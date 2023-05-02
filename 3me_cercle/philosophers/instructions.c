/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:42:54 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/02 13:20:11 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(int id, t_myphilo* me, t_philo *philo)
{
	pthread_mutex_lock(philo->mutex[me->id - 1]);
	ft_isdead(*me, philo);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return ;
	me->fork_i = 1;
//		printf("Philosopher %d has taken fork %i\n", id, id - 1);
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken left fork\n", id);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->mutex[me->id % philo->count]);
	ft_isdead(*me, philo);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return ;
	me->fork_r = 1;
//		printf("Philosopher %d has taken fork %i\n", id, id % philo->count);
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken right fork\n", id);
	pthread_mutex_unlock(philo->print);
}

void	ft_drop_fork(t_myphilo *me, t_philo *philo)
{
	pthread_mutex_unlock(philo->mutex[me->id - 1]);
	me->fork_i = 0;
	pthread_mutex_unlock(philo->mutex[me->id % philo->count]);
	me->fork_r = 0;
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is sleeping\n", me.id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_sleep);
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	ft_take_fork(me->id, me, philo);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return ;
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is eating\n", me->id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_eat);
	ft_drop_fork(me, philo);
	ft_add_eat(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is thinking\n", me.id);
	pthread_mutex_unlock(philo->print);
	ft_isdead(me, philo);
}
