//일단 디렉토리를 파악할 수 있어야함
//execvp함수는 파일이름을 받고 그걸 실행시킴
// 그럼 리다이렉션은 여기서 일어나는게 아닌가?

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *str[3];
	str[0] = "/bin/ls";
	str[1] = "-l";
	str[2] = NULL;
	execve(str[0], str, NULL);

	printf("exec 함수를 실행한 뒤는 메모리에서 사라짐\n");
	return (0);
}


//execve_manual

/*
#include <unistd.h>

     int
     execve(const char *path, char *const argv[], char *const envp[]);

불러온 프로세스를 새로운 프로세스로 변화시킴?
이 새로운 프로세슨믄 ordinary file으로부터 생성됨
new_process_file : 일단 새로운 파일이 생기는거네


*/
