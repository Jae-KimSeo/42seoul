#include "push_swap.h"


int main(int argc, char* argv[]){
    Stack *a;
    Stack *b;
    Pushswap *p;
  
    int tmp;
    int count;
    int sorted;

    sorted = TRUE;
    if (argc <= 1)
    {
      write(1, "Error", sizeof("Error"));
      return 0;
    }

    a = init();
    b = init();

    count = parcing_input(argc, argv, a);
    if (check_sorted(a) == TRUE)
      exit(0);
    
    p = push_swap_init();

    // 출력 인자들을 파이프로 넘기고 ctrl d가지 넘거야 함 
    //파이프라인, fd를 생성하고
    // write할때 fd를 생성한 값으로 넣어줌
    //파일디스크립터는 파이프를 여기에 열고 인자로 넣어주고 함수 종료 전에 클로즈하는게 나을듯 
    
    //int fds[2];
    //close(fds[0]);
    //dup2(fds[1], 1);
    //int fds[2];
    //pipe(fds);
    //close(fds[0]);
    a_to_b(a, b, size(*a), p);
    //close(fds[1]);
    //printf("check fd %d, %d\n", fds[0], fds[1]);
    //close(fds[1]); 
    print_stack(a, b);
    printf("count %d", p->count);
    
    exit(0);
    //printf("instruction : %d\n", p->count);

    //exit(0);
    // delete_stack(a);
    // delete_stack(b);
    //system("leaks a.out");

    //메모리 leaks  
   // exit(0);
}
