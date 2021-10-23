
int	ft_malloc(void **dst, size_t size)
{
	*dst = ft_calloc(size, 1);
	if (*dst == NULL)
		return (0);
	return (1);
}

//첫 파라미터 투포인터인 이유 명확하게 설명할 수 있어?
// 구조체의 주소값인 것 같긴한데 .
// *dst가 구조체 하나야
// 그럼 dst 자체는 구조체의 포인터란 소린데 그럼 포인터 배열?
// 그냥

//  char *dst;
// dst = malloc(sizedof (AST));
// *dst 여기에 할당하면 *dst 자체가 주소값에 메모리할당이고, dst는 *dst의 할당된 메모리(주소_)의 주소값이니까 배열이네