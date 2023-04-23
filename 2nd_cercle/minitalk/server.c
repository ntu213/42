/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:15:30 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/21 17:38:33 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_strct	*g_strct;

void	ft_addstr(char c, siginfo_t *info)
{
	static int	i = 0;
	int			exit;

	exit = 0;
	g_strct->str[i++] = c;
	if (!g_strct->str[i])
	{
		write(1, g_strct->str, i);
		write(1, "\n", 1);
		g_strct->act->sa_sigaction = &ft_getsize;
		sigaction(SIGUSR1, g_strct->act, NULL);
		sigaction(SIGUSR2, g_strct->act, NULL);
		if (ft_isexit(g_strct->str))
			exit = 1;
		free(g_strct->str);
		kill(info->si_pid, SIGUSR2);
		if (exit)
			ft_exit(g_strct);
		i = 0;
	}
}

void	ft_sig(int n, siginfo_t *info, void *ptr)
{
	static int	i = 0;
	static char	c = 0;

	c = c << 1;
	if (n == SIGUSR1)
		c += 1;
	i++;
	if (i == 8)
	{
		ft_addstr(c, info);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)ptr;
}

void	ft_setspaces(char *str, int n)
{
	int	i;

	i = 0;
	g_strct->str = malloc(n + 1);
	g_strct->str[n] = 0;
	while (i < n)
		g_strct->str[i++] = ' ';
	(void)str;
}

void	ft_getsize(int n, siginfo_t *info, void *ptr)
{
	static int	i = 0;
	static int	j = 0;

	j = j << 1;
	if (n == SIGUSR1)
		j++;
	i++;
	if (i == 32)
	{
		g_strct->act->sa_sigaction = &ft_sig;
		sigaction(SIGUSR1, g_strct->act, NULL);
		sigaction(SIGUSR2, g_strct->act, NULL);
		ft_setspaces(g_strct->str, j);
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)ptr;
}

int	main(void)
{
	struct sigaction	act;

	g_strct = malloc(sizeof(t_strct));
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &ft_getsize;
	g_strct->act = &act;
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		sleep(3);
	return (0);
}
