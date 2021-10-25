
void	init(char *envp[])
{
	int		i;
	char	*cur_envp;  // 한줄
	t_list	*envps; // 한줄 -> 한줄 -> 한줄

	i = 0;
	while (envp[i])
	{
		cur_envp = ft_strdup(envp[i]);
		envps = ft_lstnew(cur_envp);
		if (g_shell.envp == NULL)
			g_shell.envp = envps;
		else
			(g_shell.envp)->next = envps;
		i++
	}
}



