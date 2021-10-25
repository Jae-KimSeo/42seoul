#include "interpreter.h"

void remove_not_lexeme(char **line)
{
    while (**line && ft_strchr(" \n\t", **line))
        (*line)++;
}

t_list	*scan_line(char **line, int *cur_option)
{
	t_list *ret;
	t_token *token;

	while (*line)
	{
		ret = ft_lstnew();
		remove_not_lexeme(&line)
		token = (t_token *)malloc(sizeof(t_token));
		if (token == NULL)
			return (MALLOC_ERROR);
		if (ft_strchr("|<>'\"", **line))
			token->value = get_special_token(line, cur_option);
		else
			token->value = get_plain_token(line, cur_option);
		token->type = *cur_option;
		ret = ft_lstnew(token);
		//(t_token *)ret->content = token;
 		ret = ret->next;
	}
	return ret; // 이거 어느위치인지 체크 구조체 원포인터일때 링크는 넘어갈까 안넘어갈까
}

//우선순위큐를 만드는게 맞다
// redirection의 경우 리다이렉트 기호 전에가 blank면 1을 default로 넣어주자


t_lexer *init_lexer(char *line, t_list *tokens)
{
	t_lexer *ret;

	ret = (t_lexer *)malloc(sizeof(t_lexer));
	if (ret == NULL)
	{
		return (MALLOC_ERROR);
	}
	ret->line = line;
	ret->tokens = tokens;
	ret->start = -1;
	ret->end = -1;

	return (ret);
}

t_lexer *lexical_analyzer(char *line)
{
	t_list		*tokens;
	char		*save_line;
	int			cur_option;

	save_line = line;
	cur_option = CUR_NONE;
	tokens = scan_line(&line, &cur_option);

	return (init_lexer(save_line, tokens));

    //scanning
    //lexeme 구분
    //token 포인터 배열 메모리할당
    //tokenizing
}



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