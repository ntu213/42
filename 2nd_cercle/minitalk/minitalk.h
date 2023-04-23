/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:47:06 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/21 17:38:52 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_strct
{
	char				*str;
	struct sigaction	*act;
}			t_strct;

int		ft_strlen(char *str);
int		ft_isexit(char *str);
int		ft_atoi(const char *str);
void	ft_exit(t_strct *strct);
void	ft_putnbr_fd(int nb, int fd);
void	ft_getsize(int n, siginfo_t *info, void *ptr);

#endif