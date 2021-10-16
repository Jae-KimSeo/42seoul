#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <termios.h> // 얘 좀 자세히 봐야할듯


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_minishell
{
	int				signal;
	int				status;
	int				isps2;
	int				pid;
	int				eof;
	int				read_fd;
	char			*line;
	t_history		*cmd;
	t_history		*history;
	int				cmd_i;
	int				cmd_s;
	t_list			*envp;
	struct termios	term_sh;
	struct termios	term_ori;
}	t_minishell;

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

#define t_minishell g_shell

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

static void parce_line()
{
	//tokenize
	//bash에서 string 으로 받아서 for문 돌리면 나눠지는데? 뭔기준으로 나눠지는거지
	t_list *ret;

	ret->content = "pre_"
	ret = ret->next;
	ret->content = g_shell.line;

static int read_line(void)
{
    int				ret;
	char			*line;

	signal(SIGINT, handler); // signal SIGINT, hanler 3개 다 모르네
	while (true)
	{
		line = readline("input> ");
		if (line)
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			g_shell.line = line;
			add_history(line); // 사용자가 입력했던 문자열 불러오기->이건어디 저장되는거지 ?
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return (1);
	}
	return (0);
}


static void	minishell(void)
{
	t_list	*ASTs;

	get_line(); // 여기서 전역 구조체에 라인 담고 구조체 세팅
	ASTs = parse_line(g_sh.line); // 리스트에 파싱된 애들 담고
	exec_cmd(ASTs); // 명령어 실행
}


static void simple_minishell(void)
{
    t_list *line;

    read_line();
	line = parse_line(g_shell.line);
	while(line)
	{
		printf("check_parced : %s\n", line);
		line = line->next;
	}


}



//init_minishell : 환경변수, term setting
//minishell 프로그램 while문을 통해 minishell함수가 계속 실행되고 라인을  읽어와서 파싱한뒤 명령을 수행해야함

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_minishell(envp);
	while (1)
		minishell();
	return (0);
}



/*개념적으로 정리해야되는걸 생각해보자
envp, term 등 initlize
termios 구조체
tcgetsetter tcset~ 함수들
readline 관련된 정확한 입출력
t_minishell 전체 구조체 의미
signal 자체의 깊은 의미, 파라미터들의 의미
*/