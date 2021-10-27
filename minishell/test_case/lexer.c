#include "interpreter.h"

static char **remove_not_lexeme(char **line)
{
	if (**line == (char)NULL)
		return (NULL);
    while (**line && ft_strchr(" \n\t", **line))
        (*line)++;
	//printf("REMOVE :%s\n", *line);
	return line;
}
/*
void	ft_strskip(char **str, char *charset)
{
	while (**str && ft_strchr(charset, **str))
		++(*str);
}
*/
static t_token *get_special_token(t_token *token, char **line, int *cur_option)
{
	token->value = get_special_item(line, cur_option);
	if (*cur_option & CUR_REDIRECT)
		token->type = CUR_REDIRECT;
	else if (*cur_option & CUR_PIPE)
		token->type = CUR_PIPE;
	return (token);
}
/*
char	*get_static_token(char **line, int *status)
{
	char	*token;

	token = 0;
	if (ft_strchr("<>", **line))
	{
		if (*status & LX_REDIRECT)
			return ((char *)PARSE_UNEXPECT);
		*status |= (LX_REDIRECT | LX_POSSIBLE);
		return (get_redirect_token(line));
	}
	if (ft_strchr("&|", **line))
		return (get_pipe_ctr_op_token(line, status));
	if (*status & ~(LX_CMD | LX_POSSIBLE) || \
		!(*status & (LX_CMD | LX_POSSIBLE)))
		return ((char *)PARSE_UNEXPECT);
	if (!ft_strncmp(*line, ";", 1))
	{
		*status = LX_SEPERATOR;
		token = ft_strndup_move(";", 1, line);
	}
	return (token);
}
*/
static t_token *get_plain_token(t_token *token, char **line, int *cur_option)
{
	if (*cur_option & CUR_REDIRECT) // 리다이렉트인 경우
	{
		token->type = CUR_AFTER_FD;
		*cur_option ^= CUR_REDIRECT;
	}
	else if (*cur_option & CUR_CMD) // 이미 CMD가 있는경우
		token->type = CUR_ARG;
	else
	{
		*cur_option = CUR_CMD;
		token->type = CUR_CMD;
	}
	token->value = get_plain_item(line);
	return (token);
}
/*
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
*/

static t_list	*scan_line(char **line, int *cur_option)
{
	t_list *ret;
	t_list *head;
	t_token *token;

	line = remove_not_lexeme(line);
	// init
		if (line == NULL)
			return NULL;
		token = (t_token *)malloc(sizeof(t_token));
		malloc_error_check(token);
		if (ft_strchr("|<>", **line))
			token = get_special_token(token, line, cur_option);
		else
			token = get_plain_token(token, line, cur_option);
	ret = ft_lstnew(token);
	head = ret;
	while (*line)
	{
		line = remove_not_lexeme(line);
		if (line == NULL)
			break;
		token = (t_token *)malloc(sizeof(t_token));
		malloc_error_check(token);
		if (ft_strchr("|<>", **line))
			token = get_special_token(token, line, cur_option);
		else
			token = get_plain_token(token, line, cur_option);
		ret->next = ft_lstnew(token);
		ret = ret->next;
	}
	return (head); // 이거 어느위치인지 체크 구조체 원포인터일때 링크는 넘어갈까 안넘어갈까
}
/*
static t_lexer *init_lexer(char *line, t_list *tokens)
{
	t_lexer *ret;

	ret = (t_lexer *)malloc(sizeof(t_lexer));
	malloc_error_check(ret);
	ret->line = line;
	ret->tokens = tokens;
	ret->start = -1;
	ret->end = -1;

	return (ret);
}
*/
t_list *lexical_analyzer(char *line)
{
	t_list		*tokens;
	int			cur_option;

	cur_option = CUR_NONE;
	tokens = scan_line(&line, &cur_option);
	return (tokens);
}

    //scanning
    //lexeme 구분
    //token 포인터 배열 메모리할당
    //tokenizing


/*
int 	set_quote_option(char *line)
{
	int quote_opt;

	quote_opt = SET_NONE;
	while (*line)
	{
		if (*line == "'")
			quote_opt ^= SET_QUOTE;
		else if (*line == '"')
			quote_opt ^= SET_DQUOTE;

		line++;
	}

}이거 나중에 체크하는게 나을듯
*/