/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:46:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 10:31:33 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_myphilo	ft_init_myphilo(int id, t_philo *philo)
{
	t_myphilo	new;

	new.id = id;
	new.count_of_eat = -1;
	new.time_to_die = philo->time_to_die;
	new.philo = philo;
	usleep(10);
	return (new);
}

void	ft_unlock(sem_t *m1, sem_t *m2, sem_t *m3, sem_t *m4)
{
	if (m1)
		sem_post(m1);
	if (m2)
		sem_post(m2);
	if (m3)
		sem_post(m3);
	if (m4)
		sem_post(m4);
	return ;
}

void	ft_printtime(t_philo *philo)
{
	sem_wait(philo->time);
	gettimeofday(&philo->tv, NULL);
	if (philo->tv.tv_usec / 1000 - philo->msec >= 0)
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec,
			philo->tv.tv_usec / 1000 - philo->msec);
	else
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec - 1,
			1000 + (philo->tv.tv_usec / 1000 - philo->msec));
	sem_post(philo->time);
}

int	ft_exec(t_myphilo *me, t_philo *philo)
{
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	sem_post(philo->verif);
	ft_eat(me, philo);
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	sem_post(philo->verif);
	ft_sleep(*me, philo);
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	sem_post(philo->verif);
	ft_think(*me, philo);
	return (1);
}

void	*ft_thread(t_philo *philo)
{
	t_myphilo	me;
	pthread_t	thread;

	sem_wait(philo->verif);
	me = ft_init_myphilo(philo->start, philo);
	sem_wait(philo->print);
	sem_post(philo->print);
	while (philo->start)
	{
		sem_post(philo->verif);
		usleep(10);
		sem_wait(philo->verif);
	}
	sem_post(philo->verif);
	ft_add_eat(&me, philo);
	pthread_create(&thread, NULL, (void *) ft_death_thread, &me);
	while (1)
		if (!ft_exec(&me, philo))
			break ;
	sem_post(philo->verif);
	pthread_join(thread, NULL);
	return (philo);
}
