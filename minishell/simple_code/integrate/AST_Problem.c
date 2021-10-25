static int	set_redirect(t_AST **curr, t_list **token)
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
	redirect->file = ((t_token *)(*token)->content)->value;
	((t_token *)(*token)->content)->value = NULL;
	if (!ft_malloc((void **)&redirect->AST, sizeof(t_AST)))
		return (0);
	*curr = redirect->AST;
	return (1);
}