char	*get_envp_value(char *name)
{
	char	*result;
	t_list	*env;

	env = get_envp(name, g_sh.envp); //여기서 env는 해당하는 환경변수 이름의 t_list 
	if (!env || !ft_strchr(env->content, '='))
		result = ft_strdup("");
	else
		result = ft_strdup(env->content + ft_strlen(name) + 1); // env에 컨텐트 보내는거 좋아, 뒤에 길이의 의미? 
	return (result);
}

t_list	*get_envp(char *name, t_list *envp) 
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(name, '=');
	if (ptr)
		len = ptr - name;
	else
		len = ft_strlen(name);
	while (envp)
	{
		if (!ft_strncmp(envp->content, name, len))
		{
			if (*(char *)(envp->content + len) == '=' || \
				*(char *)(envp->content + len) == '\0')
				return (envp);
		}
		envp = envp->next;
	}
	return (NULL);
}