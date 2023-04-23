/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:15:27 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/21 17:37:00 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_tmp;

void	ft_pushstr(char *str, int pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		j = 0;
		c = str[i];
		while (j < 8)
		{
			g_tmp = 1;
			if (c & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = c << 1;
			j++;
			while (g_tmp)
				usleep(1);
		}
		i++;
	}
}

void	ft_pushint(int pid, int n)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		g_tmp = 1;
		if (n & 4294967296)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n = n << 1;
		i++;
		while (g_tmp)
			usleep(1);
	}
}

void	ft_sig(int n)
{
	if (n == SIGUSR1)
		g_tmp = 0;
	else
	{
		write(1, "Message Sent!\n", 14);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc < 3)
		return (write(1, "[Error] Not enough arguments\n", 29));
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act.sa_mask);
	act.sa_handler = &ft_sig;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (ft_strlen(argv[2]))
	{
		ft_pushint(ft_atoi(argv[1]), ft_strlen(argv[2]));
		ft_pushstr(argv[2], ft_atoi(argv[1]));
	}
	return (0);
}
