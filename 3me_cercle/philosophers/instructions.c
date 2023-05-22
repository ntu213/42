/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:53:16 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/15 11:16:38 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_fork(int id, t_myphilo* me, t_philo *philo)
{
	pthread_mutex_lock(me->fork_l);
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
	{
		pthread_mutex_unlock(&philo->verif);
		pthread_mutex_lock(me->fork_r);
		return (0);
	}
//		return (ft_unlock(&philo->print, &philo->verif, NULL, NULL));
//		return (ft_unlock(&philo->print, me->fork_l, &philo->verif, NULL));
	pthread_mutex_lock(&philo->print);
	ft_printtime(philo);
	pthread_mutex_unlock(&philo->verif);
	printf("Philosopher %d has taken left fork\n", id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(me->fork_r);
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
	{
		pthread_mutex_unlock(&philo->verif);
		return (0);
	}
//		return (ft_unlock(&philo->print, &philo->verif, NULL, NULL));
//		return (ft_unlock(&philo->print, me->fork_l,
//			me->fork_r, &philo->verif));
	pthread_mutex_lock(&philo->print);
	ft_printtime(philo);
	pthread_mutex_unlock(&philo->verif);
	printf("Philosopher %d has taken right fork\n", id);
	pthread_mutex_unlock(&philo->print);
	return (1);
}

void	ft_drop_fork(t_myphilo *me)
{
	pthread_mutex_unlock(me->fork_l);
	pthread_mutex_unlock(me->fork_r);
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	int	eat;

	if (!ft_take_fork(me->id, me, philo))
		return (ft_unlock(NULL, me->fork_l, me->fork_r, NULL));
//	pthread_mutex_lock(&philo->verif);
//	if (philo->death || philo->end_eat >= philo->count)
//		return (ft_unlock(&philo->verif, me->fork_l, me->fork_r, NULL));
//	pthread_mutex_unlock(&philo->verif);
	pthread_mutex_lock(&philo->verif);
	eat = philo->time_to_eat;
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, me->fork_l,
			me->fork_r, &philo->verif));
	pthread_mutex_lock(&philo->print);
	ft_printtime(philo);
	pthread_mutex_unlock(&philo->verif);
	printf("Philosopher %d is eating\n", me->id);
	pthread_mutex_unlock(&philo->print);
	ft_reset_meat(me, philo);
	usleep(eat);
	ft_drop_fork(me);
	ft_add_eat(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, &philo->verif, NULL, NULL));
	pthread_mutex_lock(&philo->print);
	ft_printtime(philo);
	pthread_mutex_unlock(&philo->verif);
	printf("Philosopher %d is thinking\n", me.id);
	pthread_mutex_unlock(&philo->print);
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(&philo->verif);
	tmp = philo->time_to_sleep;
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, &philo->verif, NULL, NULL));
	pthread_mutex_lock(&philo->print);
	ft_printtime(philo);
	pthread_mutex_unlock(&philo->verif);
	printf("Philosopher %d is sleeping\n", me.id);
	pthread_mutex_unlock(&philo->print);
	usleep(tmp);
}
