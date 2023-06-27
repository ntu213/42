/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:29:46 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/05 13:16:02 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *))
{
	printf("[Error] %s\n", str);
	ft(gofree);
	return (n);
}

void	ft_reset_meat(t_myphilo *me, t_philo *philo)
{
	pthread_mutex_lock(&philo->verif);
	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	pthread_mutex_unlock(&philo->verif);
	pthread_mutex_unlock(&philo->time);
}

void	ft_unlock(pthread_mutex_t *m1, pthread_mutex_t *m2,
	pthread_mutex_t *m3, pthread_mutex_t *m4)
{
	if (m1)
		pthread_mutex_unlock(m1);
	if (m2)
		pthread_mutex_unlock(m2);
	if (m3)
		pthread_mutex_unlock(m3);
	if (m4)
		pthread_mutex_unlock(m4);
	return ;
}

void	ft_scenario(t_rules *rules)
{
	printf("[%.7d] Philosopher 1 has taken left fork\n", 0);
	usleep(rules->time_to_die);
	printf("[%.7d] Philosopher 1 is dead\n", rules->time_to_die);
}
