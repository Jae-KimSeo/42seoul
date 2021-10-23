// 리다이렉트 파싱 시에  단순히 a > b 이면 3개의 토큰이 아니라 
// 앞에 fd가 오는지, txt.file이 오는지 -> 이경우 fd 1 이 생략 // 뒤에 fd가 올경우 레퍼런스 + 숫자, file이 올경우 띄어쓰기 상관없음
// 세덩어리가 아니라 두덩어리라고 생각해야함 -> fd가 리다이렉트 기호 앞에 붙어있을 경우
// 그냥 세덩어리일 경우 리다이렉트 기호 앞이 파일 이름일 경우 

typedef struct s_AST
{
	int		type;
	void	*data;
}	t_AST;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

typedef struct s_pipe
{
	t_AST	*left;
	t_AST	*right;
}	t_pipe;

typedef struct s_redirect
{
	int		type;
	t_AST	*AST;
	char	*file;
}	t_redirect;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;


#define FT_REDIRECT 1;
#define FT_FD_IN 2;
#define FT_FD_OUT 4;
#define FT_FD_HEREDOC 8;
#define FT_FD_APPEND 16;



static int	redirect_divide(t_AST **curr, t_list **token) //set_redirect 
{
	t_redirect	*redirect;

	if (!ft_malloc((void **)&(*curr)->data, sizeof(t_redirect)))
		return (0);
	redirect = (*curr)->data;
	(*curr)->type = FT_REDIRECT;
	if (!ft_strcmp(((t_token *)(*token)->content)->value, "<"))
		redirect->type = FT_FD_IN;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">"))
		redirect->type = FT_FD_OUT;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, "<<"))
		redirect->type = FT_FD_HEREDOC;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">>"))
		redirect->type = FT_FD_APPEND;
	*token = (*token)->next;
	redirect->file = ((t_token *)(*token)->content)->value; //여기서 리스트의 void *인 content를 토큰 구조체로 할당하고 
	((t_token *)(*token)->content)->value = NULL;
	if (!ft_malloc((void **)&redirect->AST, sizeof(t_AST)))
		return (0);
	*curr = redirect->AST;
	return (1);
}

//회의
//다음주 할일
//기능별 정의 () 
//칸반
//회고 