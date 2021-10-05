#include "push_swap.h"

    int parcing_input(int argc, char **argv, Stack *a){
        int input_count;
        char *input;

        int i = 1;

        if (argc == 1){
            exit (0);
        }
        while (argv[i]){
            char **ptr;
            ptr = ft_split(argv[i], ' ');
            if (ft_strlen(ptr[0]) == ft_strlen(argv[i])){
                input = argv[i];
                if (check_valid_input(input, a) == TRUE){
                    push_tail(a,input);
                    input_count++;
                }else{
                    printf("Error");
                    exit (1);
                }
            }
            else {
                int j;
                j = 0;
                while (ptr[j]){
                    input = ptr[j];
                    if (check_valid_input(input, a) == TRUE){
                        push_tail(a,input);
                        input_count++;
                    }else{
                        printf("Error");
                        exit (1);
                    }
                    j++;
                }
            }
            i++;
        }
        return (input_count);
    }

    int check_valid_input(char *input, Stack *a){
        ListNode *ptr;
        int i;

        i = 0;
        ptr = a->head;
        // 중복 체킄 
        while (ptr){
            if (ptr->data == input)
                return FALSE;
            ptr = ptr->prev;
        }
        // 숫자가 아닌지
        while (input[i]){	
            if (ft_isdigit(input[i]) == 0)
                return (FALSE);
            i++;
        }
        // MAX_INT 이상인지
        if (atoi(input) > INT_MAX){
            return (FALSE);
        }
       return (TRUE); 
    }

    int check_sorted(Stack *a, int cnt){
        ListNode *ptr;
        int num;

        if (size(*a) < 2)
            return (TRUE);
        ptr = a->head;
        num = cnt;
        while (ptr->prev && num != 0){
            if (ft_atoi(ptr->data) > ft_atoi(ptr->prev->data))
                return (FALSE);
            ptr = ptr->prev;
            num--;
        }
        return (TRUE);
    }

    int check_reverse_sorted(Stack *b, int cnt){
        ListNode *ptr;
        int num;

        if (size(*b) < 2)
            return (TRUE);
        ptr = b->head;
        num = cnt;
        while (ptr->prev && num != 0)
        {
            if (ft_atoi(ptr->data) < ft_atoi(ptr->prev->data))
                return (FALSE);
            ptr = ptr->prev;
            num--;
        }
        return (TRUE);
    }
