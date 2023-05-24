int	g_black_pid = 0;
int	g_white_pid = 0;
int	g_game_end = 0;
struct sigaction	act;

void	ft_getpid(int n, siginfo_t *info, void *ptr)
{
	if (!g_black_pid)
	{
		g_black_pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
	}
	else if (info->si_pid != g_black_pid)
	{
		g_white_pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
act.sa_sigaction = &ft_getpid;
sigaction(SIGUSR1, &act, NULL);
sigaction(SIGUSR2, &act, NULL);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

void	main()
{
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &ft_getpid;
	printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (!g_game_end)
		sleep(1);
}