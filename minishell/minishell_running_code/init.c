
void	init(char *envp[])
{
	int		i;
	char	*cur_envp;
	t_list	*envps;

	i = 0;
	while (envp[i])
	{
		cur_envp = ft_strdup(envp[i]);
		envps = ft_lstnew(cur_envp);
		if (g_shell.envp == NULL)
			g_shell.envp = envps;
		else
			ft_lstlast(g_sh.envp)->next = envps;
		i++
	}
}