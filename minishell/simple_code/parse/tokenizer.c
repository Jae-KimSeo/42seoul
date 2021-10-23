#include "minishell.h"
#include "parse_util.h"

static int	check_flag(int flag, char **line)
{
	if (!(flag & ~(TK_QOUTES)) && **line == '"')
		flag ^= TK_QOUTES;
	else if (!(flag & ~(TK_QOUTE)) && **line == '\'')
		flag ^= TK_QOUTE;
	else if (!(flag & ~(TK_QOUTES)) && **line == '\\')
		flag |= TK_ESCAPE;
	else if ((flag & TK_ESCAPE) && *(*line - 1) == '\\')
		flag &= ~TK_ESCAPE;
	return (flag);
}

static char	*get_redirect_token(char **line)
{
	char	*token;

	token = 0;
	if (!ft_strncmp(*line, "<<", 2))
		token = ft_strndup_move("<<", 2, line);
	else if (!ft_strncmp(*line, ">>", 2))
		token = ft_strndup_move(">>", 2, line);
	else if (!ft_strncmp(*line, "<", 1))
		token = ft_strndup_move("<", 1, line);
	else if (!ft_strncmp(*line, ">", 1))
		token = ft_strndup_move(">", 1, line);
	return (token);
}

static char	*get_pipe_ctr_op_token(char **line, int *status)
{
	char	*token;

	token = 0;
	if (*status == LX_NONE || *status & ~(LX_CMD | LX_POSSIBLE))
		return ((char *)PARSE_UNEXPECT);
	if (!ft_strncmp(*line, "&&", 2))
	{
		*status = LX_CTR_OP;
		token = ft_strndup_move("&&", 2, line);
	}
	else if (!ft_strncmp(*line, "||", 2))
	{
		*status = LX_CTR_OP;
		token = ft_strndup_move("||", 2, line);
	}
	else if (!ft_strncmp(*line, "|", 1))
	{
		*status = LX_PIPE;
		token = ft_strndup_move("|", 1, line);
	}
	return (token);
}

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

char	*get_token(char **line)
{
	int		flag;
	char	*token;
	char	temp[2];

	flag = TK_NONE;
	temp[1] = 0;
	token = ft_strdup("");
	if (token == NULL)
		return (PARSE_MALLOC);
	while (**line && !(flag == TK_NONE && \
		(ft_strchr(" \n\t<>|;", **line) || !ft_strncmp("&&", *line, 2))))
	{
		flag = check_flag(flag, line);
		temp[0] = **line;
		token = ft_strjoin_free(token, temp, 1);
		if (token == NULL)
			return ((char *)ft_free_ret(token, (char *)PARSE_MALLOC));
		++(*line);
	}
	if (flag != TK_NONE)
		return ((char *)ft_free_ret(token, (char *)PARSE_INVAILD));
	return (token);
}
