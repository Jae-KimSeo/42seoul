void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

int		read_line(void)
{
	int				ret;
	char			*line;

	signal(SIGINT, handler);
	while (true)
	{
		line = readline("minishell> ");
		if (line)
		{
			ret = strcmp(line, "exit");
			if (ret)
				printf("$> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return (1);
	}
	return (0);
}