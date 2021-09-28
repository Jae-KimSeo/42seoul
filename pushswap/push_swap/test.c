// 1. 매개변수가 숫자인지 아닌지 확인하는 함수.
// 2. 매개변수가 숫자인데 "1 2" 3 4 의 경우 자르기
// check_input_number(argv)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_input_number(char *input)
{
  int i;
  int count_space;

  i = 0;
  count_space = 0;
  if(strchr(input, ' ') != NULL)
  {
    while(input[i] != '\0')
    {
      printf("%c\n", input[i]);
      if (input[i] == ' ')
        count_space++;
      i++;
    }
    printf("count: %d\n", count_space + 1);
  }
  else
    printf("%s\n", input);
}

int main(int argc, char *argv[])
{
  int i;

  i = 1;
  while (i < argc)
  {
    check_input_number(argv[i]);
    i++;
  }
  return (0);
}
