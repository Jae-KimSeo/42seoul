#include <signal.h> //
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h> // 얘 좀 자세히 봐야할듯
#include "util.c"

// 구조체들을 미리 생각해보자


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_history
{
	char				*cmd;
	struct s_history	*next;
	struct s_history	*prev;
}	t_history;

typedef struct s_minishell
{
    t_history		*history;
	t_list			*envp;
	int				signal;
	int				pid;
	int				eof;
	int				read_fd;
	char			*line;
	struct termios	term_current; //terminal 상태 변화시에  getter, setter
	struct termios	term_former;
}	t_minishell;


t_minishell g_shell; //global structure
//전역 구조체로 쓰자
//외부 소스파일에서 참조할 경우 extern

/*참고
struct termios{
	tcflag_t c_iflag; //입력모드
	tcflag_t c_oflag; //출력모드
	tcflag_t c_cflag; //제어모드
	tcflag_t c_lflag; //로컬모드
	cc_t c_cc[NCCS];  //제어문자
	speed_t c_ispeed; //입력속도
	speed_t c_ospeed; //출력속도
};
*/


static void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1) // 개행 문자를 통해 다음줄로 이동했음을 알려주는 알림 함수? 있을때 없을때 차이가 뭐지?
		exit(1);
	rl_replace_line("다시", 1); // rl_line_buffer에 입력받은 문자를 첫번째 파라미터 text로 대치, 두번째 파라미터는 undo를 초기화 할지 말지
    //이거 헤더 포함해야 컴파일됨
    // ctrl + C 하면 다시가 나오네 ?
    // 두번째 파라미터 0이던 1이던 일단 차이 없음 그냥 버퍼 비우는 의미인듯? 버퍼 : 임시 저장소 ?
	rl_redisplay(); // rl_line_buffer 의 값을 프롬프트와 함께 출력
}

static void init_simple_minishell(char *envp[])
{
	//여기서 init envp, init term이 전역 구조체에 저장되는 과정이 이루어져야함
	signal(SIGINT, handler);
}

static int read_line(void)
{
    int				ret;
	char			*line;

		line = readline("input> ");
		if (line)
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			g_shell.line = line;
			add_history(line);
			//free(line);
			line = NULL;
			if (!ret)
				return(1) ;
		}
		else
			return (1);

	return (0);
}


static t_list *init_list(void *content)
{
	t_list *ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (ret == NULL)
	{
		exit(1);
		return (NULL);
	}
	ret->content = content;
	ret->next = NULL;
	return ret;
}

static t_list *parse_line(char *line)
{
	//tokenize
	//bash에서 string 으로 받아서 for문 돌리면 나눠지는데? 뭔기준으로 나눠지는거지
	t_list *ret;
    t_list *ptr;
    char    **tmp;

	tmp = ft_split(g_shell.line);
    int i = 0;
    ptr = ret;
    while(*tmp)
    {
        ptr = init_list(tmp[i]);
        ptr = ptr->next;
        i++;
    }

	return ret;
}

static void simple_minishell(void)
{
	t_list *line;

	if (read_line()) // 일단 여기는 문자열 없을떄랑, 종료문구 썼을 두 경우 -> 이때 exit으로 그냥 끝내면 되나 아니면 별도의 프로세스가 필요한가 ? **
	{
		printf("read_finish");
		exit(1);
	}
	line = parse_line(g_shell.line);
	//if (line)

    while(line)
	{
		printf("check_parced : %s\n", line->content);
		line = line->next;
	}


}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_simple_minishell(envp);
	while (true)
		simple_minishell();
	return (0);
}

