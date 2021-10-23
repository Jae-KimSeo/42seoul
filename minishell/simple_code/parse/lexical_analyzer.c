#include "minishell.h"
#include "parse_util.h"

static t_list	*destructor(t_list *result, void *err)
{
	t_list	*prev;

	while (result)
	{
		ft_free(((t_token *)result->content)->value);
		ft_free(result->content);
		prev = result;
		result = result->next;
		free(prev);
	}
	return (err);
}

static void	token_lexer(t_token *data, char **line, int *status)
{
	if (ft_strchr("<>|;", **line) || !ft_strncmp("&&", *line, 2))
	{
		data->value = get_static_token(line, status);
		if (*status & LX_REDIRECT)
			data->type = LX_REDIRECT;
		else
			data->type = *status & ~(LX_CMD + LX_POSSIBLE);
	}
	else
	{
		data->value = get_token(line);
		if (*status & LX_REDIRECT)
		{
			data->type = LX_FILE;
			*status = (*status & LX_CMD) | LX_POSSIBLE;
		}
		else if (*status & LX_CMD)
			data->type = LX_ARG;
		else
		{
			*status = LX_CMD;
			data->type = LX_CMD;
		}
	}
}

static int	check_token_lexer(t_list *curr, char **line, int *status, char **e)
{
	if (!ft_malloc(&curr->content, sizeof(t_token)))
	{
		*e = PARSE_MALLOC;
		return (0);
	}
	token_lexer(curr->content, line, status);
	if (((t_token *)curr->content)->value <= (char *)PARSE_ERROR_COUNT)
	{
		*e = ((t_token *)curr->content)->value;
		((t_token *)curr->content)->value = NULL;
		return (0);
	}
	return (1);
}

static int	malloc_chk_tk_lx(t_list **curr, char **line, int *status, char **e)
{
	if (!ft_malloc((void **)&(*curr)->next, sizeof(t_list)))
	{
		*e = PARSE_MALLOC;
		return (0);
	}
	(*curr) = (*curr)->next;
	return (check_token_lexer(*curr, line, status, e));
}

t_list	*lexical_analyzer(char *line)
{
	t_list	*curr;
	t_list	*result;
	int		status;
	char	*err;

	status = LX_NONE;
	ft_strskip(&line, TK_IFS);
	if (*line == '\0')
		return ((t_list *)PARSE_NOTTHING);
	if (!ft_malloc((void **)&result, sizeof(t_list)))
		return (PARSE_MALLOC);
	curr = result;
	if (!check_token_lexer(curr, &line, &status, &err))
		return (destructor(result, err));
	ft_strskip(&line, TK_IFS);
	while (*line)
	{
		if (!malloc_chk_tk_lx(&curr, &line, &status, &err))
			return (destructor(result, err));
		ft_strskip(&line, TK_IFS);
	}
	if (status != LX_SEPERATOR && status & ~(LX_CMD + LX_POSSIBLE))
		return (destructor(result, (char *)PARSE_UNEXPECT));
	return (result);
}
