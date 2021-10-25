#include "interpreter.h"

static char	*get_pipe_token(char **line, int *cur_option)
{
	char *ret;

	*cur_option = CUR_PIPE;
	ret = ft_strdup("|")
	(*line)++;

	return ret;
}

static char	*get_redirect_token(char **line, int *cur_option)
{
	char	*ret;

	// 얘 앞에 붙는 인자 어떻게 할 것인가? -> syntax_analyzer에서 환경변수등 변환할때 해야할듯
	if (*cur_option & CUR_REDIRECT)
	{
		printf("Redirect Syntax ERROR")
		return (PARSE_ERROR);
	}
	*cur_option |= CUR_REDIRECT;
	if (ft_strncmp(*line, "<<", 2) == 0)
		ret = ft_strdup("<<");
	else if (ft_strncmp(*line, ">>", 2) == 0)
		ret = ft_strdup(">>");
	else if (ft_strcmp(*line, "<", 1) == 0)
		ret = ft_strdup("<");
	else if (ft_strcmp(*line, ">", 1) == 0)
		ret = ft_strdup(">");
	if (sizeof(ret) == 2)
		*(line) += 2;
	else if (sizeof(ret) == 1)
		*(line) += 1;
	return (ret);
}

static char	*set_quote_option(char **line, int *cur_option)
{
	//RULLE
	// 둘중에 닫혀있는지 일단 확인
	// 안닫혀있는 경우라면 다른 종류의 쿼트 사이에 들어있어야함 -> 이걸 flag로 어떻게 확인하지?
	if (!ft_strcmp("'", **line) && !(*cur_option != CUR_DQUOTE)) // 현재 상태가 NONE인 경우
	{
		cur_option ^= CUR_QUOTE;
	}
	else if (!ft_strcmp("\"", **line) && !(*cur_option != CUR_QUOTE))
	{
		cur_option ^= CUR_DQUOTE;
	}
}

char	 *get_special_token(char **line, int *cur_option)
{
	char *token_value;

	token_value = NULL;
	if (ft_strchr("|"), **line)
	{
		token_value = get_pipe_token(line, cur_option);
	}
	else if (ft_strchr("<>"), **line)
	{
		token_value = get_redirect_token(line, cur_option);
	}
	else if (ft_strchr("'\""), **line)
	{
		set_quote_option(line, cur_option);
	}
	return (token_value);
}

char	*get_plain_token(char **line, int *cur_option)
{
	char	*token;
	char	*plain;
	char	*ptr;

	ptr = ft_strdup("");
	while (**line)
	// 뒷 옵션 1. flag가 none이고 특수문자 가 아닌경우 -> flag 특수, 이고 특수문자
	{
		if ((*cur_option == CUR_NONE) && ft_strchr(" \n\t<>|", **line))
			break;
		set_quote_option(line, cur_option);
		plain = ft_strjoin(ptr, **line);
		free(ptr);
		if (plain == NULL)
		{
			print("%s\n", strerror(12))
			free(plain);
			return (PARSE_ERROR);
		}
		(*line)++;
	}
	if (cur_option != CUR_NONE)
	{
		printf("%s\n", strerror(1));
		free(token);
		return (PARSE_ERROR);
	}
	return (token);
}
