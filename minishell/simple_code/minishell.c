#include <signal.h> //
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

typedef struct s_history
{
	char				*cmd;
	char				*edit_cmd;
	struct s_history	*next;
	struct s_history	*prev;
}	t_history;

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

t_minishell g_shell; //global structure
//전역 구조체로 쓰자
//define 할 필요 없다
//외부 소스파일에서 참조할 경우 extern
//포인터가 아니므로 동적할당 할필요 역시 없다.
//그럼 안쓰는애들은 초기화 안해도 되나?



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
}//  어떻게 끝나야되지 ?

static void init_simple_minishell(char *envp[])
{
	//여기서 init envp, init term이 전역 구조체에 저장되는 과정이 이루어져야함
	signal(SIGINT, handler); // signal SIGINT, hanler 3개 다 모르네 **** // read_line->simple_minishell 로 signall 변경
}

static int read_line(void)
{
    int				ret;
	char			*line;
//	while (true)
//	{
		line = readline("input> ");
		if (line) //입력 없어도 개행 있어서 그런지 조건문 돌고, ctrl + D, bye(종료텍스트) 만 작동하네
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			g_shell.line = line;
			add_history(line); // 사용자가 입력했던 문자열 불러오기->이건어디 저장되는거지 ?
			//free(line);
			line = NULL;
			if (!ret)
				return(1) ;
		}
		else
			return (1);
//	}
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

	ret = init_list("pre_");
	ret->next = init_list(g_shell.line);
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

/*
static void	init_term(void)
{
	if (tcgetattr(STDIN_FILENO, &g_sh.term_ori) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit_minishell(1);
	}
	g_sh.term_sh = g_sh.term_ori;
	g_sh.term_sh.c_lflag &= ~(ICANON | ECHO); // 비트연산후 할당 AND 연산후 할당
	g_sh.term_sh.c_lflag |= VEOF; // OR 연산후 할당 
	g_sh.term_sh.c_cc[VMIN] = 1;
	g_sh.term_sh.c_cc[VTIME] = 0;
}

static void	init_envp(char *envp[])
{
	int		i;
	char	*tmp_s;
	t_list	*tmp_l;

	i = 0;
	while (envp[i])
	{
		tmp_s = ft_strdup(envp[i]);
		tmp_l = ft_lstnew(tmp_s);
		if (tmp_s == NULL || tmp_l == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit_minishell(1);
		}
		if (g_sh.envp == NULL)
			g_sh.envp = tmp_l;
		else
			ft_lstlast(g_sh.envp)->next = tmp_l;
		++i;
	}
}
//term관련 함수들
//envp
//g.shell의 초기화


*/



/*
static void	minishell(void)
{
	t_list	*ASTs;

	get_line(); // 여기서 전역 구조체에 라인 담고 구조체 세팅
	ASTs = parse_line(g_sh.line); // 리스트에 파싱된 애들 담고
	exec_cmd(ASTs); // 명령어 실행
}
*/

/*개념적으로 정리해야되는걸 생각해보자
envp, term 등 initlize
termios 구조체
tcgetsetter tcset~ 함수들
readline 관련된 정확한 입출력
t_minishell 전체 구조체 의미
signal 자체의 깊은 의미, 파라미터들의 의미
*/