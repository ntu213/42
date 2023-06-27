/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:19:23 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 10:31:32 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_add_eat(t_myphilo *me, t_philo *philo)
{
	sem_wait(philo->verif);
	me->count_of_eat++;
	if (me->count_of_eat == philo->count_of_eat)
		philo->end_eat++;
	sem_post(philo->verif);
	sem_wait(philo->verif);
	sem_wait(philo->time);
	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	sem_post(philo->time);
	sem_post(philo->verif);
}

void	ft_reset_meat(t_myphilo *me, t_philo *philo)
{
	sem_wait(philo->verif);
	sem_wait(philo->time);
	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	sem_post(philo->verif);
	sem_post(philo->time);
}

void	ft_isdead(t_myphilo me, t_philo *philo)
{
	long long	time;

	sem_post(philo->verif);
	sem_wait(philo->time);
	gettimeofday(&philo->tv, NULL);
	time = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	sem_post(philo->time);
	sem_wait(philo->verif);
	if (time - me.last_meat >= me.time_to_die && !philo->death)
	{
		sem_post(philo->verif);
		sem_wait(philo->verif);
		if (philo->death || philo->end_eat >= philo->count)
			return (ft_unlock(philo->verif, philo->print, NULL, NULL));
		philo->death = 1;
		sem_post(philo->verif);
		sem_wait(philo->print);
		ft_printtime(philo);
		printf("Philosopher %d is dead\n", me.id);
		sem_post(philo->print);
	}
	else
	{
		sem_post(philo->verif);
	}
}

void	*ft_death_thread(t_myphilo *me)
{
	t_philo		*philo;

	philo = me->philo;
	while (1)
	{
		sem_wait(philo->verif);
		if (philo->death || philo->end_eat >= philo->count)
			break ;
		ft_isdead(*me, me->philo);
		usleep(1000);
	}
	sem_post(philo->verif);
	return (me);
}
