#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void	handler(int signum)
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

int		main(void)
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
			add_history(line); // 사용자가 입력했던 문자열 불러오기
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return (1);
	}
    //system("./a.out leaks");
	return (0);
}