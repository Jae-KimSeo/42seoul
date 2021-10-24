#include "interpreter.h"

#define SET_NONE	0
#define SET_QUOTE	1
#define SET_DQUOTE	2

void remove_not_lexeme(char **line)
{
    while (**line && ft_strchr(" \n\t", **line))
        (*line)++;
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

t_list *scan_line(char **line)
{
	t_list *ret;

	while (*line)
	{
		remove_not_lexeme(&line)
		if (ft_strchr("'", *line) || ft_strchr('"', *line))
			set_quote_option(&line);
		else
		{
			t_token *token;
			if (token == NULL)
				return (MALLOC_ERROR);
			if (ft_strchr("|<>", *line))
				token = get_special_token(&line, &ret);
			else
				token = get_plain_token(&line, &ret);
			ret = ret->next;
		}
	}
}

//우선순위큐를 만드는게 맞다
// redirection의 경우 리다이렉트 기호 전에가 blank면 1을 default로 넣어주자

t_lexer *lexical_analyzer(char *line)
{
    t_list *tokens;
    t_lexer *ret;

/*
	tokens = (t_list *)malloc(sizeof(t_list));
	if tokens == NULL
		return (MALLOC_ERROR);
*/
	tokens = scan_line(&line);






    //scanning
    //lexeme 구분
    //token 포인터 배열 메모리할당
    //tokenizing
}