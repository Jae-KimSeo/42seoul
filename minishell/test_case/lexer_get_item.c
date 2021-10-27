#include "interpreter.h"

static char	*get_pipe_token(char **line, int *cur_option)
{
	char *ret;

	// || option 처리해야함 파이프 사이에 cmd없을때
	*cur_option = CUR_PIPE;
	ret = ft_strdup("|");
	*line += 1;
	//printf("check : %s, %s 11 \n", *line **line);

	return ret;
}

static char	*get_redirect_token(char **line)
{
	char	*ret;

	// 얘 앞에 붙는 인자 어떻게 할 것인가? -> syntax_analyzer에서 환경변수등 변환할때 해야할듯
	ret = NULL;
	if (ft_strncmp(*line, "<<", 2) == 0)
		ret = ft_strdup("<<");
	else if (ft_strncmp(*line, ">>", 2) == 0)
		ret = ft_strdup(">>");
	else if (ft_strncmp(*line, "<", 1) == 0)
		ret = ft_strdup("<");
	else if (ft_strncmp(*line, ">", 1) == 0)
		ret = ft_strdup(">");
	if (ft_strlen(ret) == 2)
		*line += 2;
	else if (ft_strlen(ret) == 1)
		*line += 1;
	return (ret);
}

static void	set_quote_option(char **line, int *cur_option)
{
	//RULLE
	// 둘중에 닫혀있는지 일단 확인
	// 안닫혀있는 경우라면 다른 종류의 쿼트 사이에 들어있어야함 -> 이걸 flag로 어떻게 확인하지?
	if (!ft_strcmp("'", *line) && !(*cur_option & CUR_DQUOTE)) // 현재 상태가 NONE인 경우
	{
		*cur_option ^= CUR_QUOTE;
	}
	else if (!ft_strcmp("\"", *line) && !(*cur_option & CUR_QUOTE))
	{
		*cur_option ^= CUR_DQUOTE;
	}
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
char	 *get_special_item(char **line, int *cur_option)
{
	char *token_value;

	token_value = NULL;
	if (ft_strchr("|", **line))
	{
		token_value = get_pipe_token(line, cur_option);
	}
	else if (ft_strchr("<>", **line))
	{
		if (*cur_option & CUR_REDIRECT)
		{
			exit(1);
			return ((char *)PARSE_ERROR);
		}
		*cur_option |= CUR_REDIRECT;
		token_value = get_redirect_token(line);
	}
	return (token_value);
}


static int check_option(char *plain, int *cur_option)
{
	if (*cur_option != CUR_NONE)
	{
		printf("%s\n", strerror(1));
		free(plain);
		return (PARSE_ERROR);
	}
	return (0);
}



char	*get_plain_item(char **line)
{
	char	*plain;
	char	null_char[2];
	int		temp_option;

	plain = ft_strdup("");
	null_char[1] = (char)NULL;
	temp_option = CUR_NONE;
	while (**line)
	// 뒷 옵션 1. flag가 none이고 특수문자 가 아닌경우 -> flag 특수, 이고 특수문자
	{
		null_char[0] = **line;
		if ((temp_option == CUR_NONE) && ft_strchr(" \n\t<>|", **line))
			break;
		set_quote_option(line, &temp_option);
		plain = ft_strjoin_free(plain, null_char, 1);
		//free(ptr);
		if (plain == NULL)
		{
			printf("%s\n", strerror(12));
			free(plain);
			return ((char *)PARSE_ERROR);
		}
		*line += 1;
	}
	if (check_option(plain, &temp_option))
		return ((char *)PARSE_ERROR);
	return (plain);
}
/*

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
*/