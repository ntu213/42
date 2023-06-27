/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:53:16 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 10:26:59 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_take_fork(int id, t_myphilo *me, t_philo *philo)
{
	sem_wait(philo->fork);
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
	{
		sem_post(philo->verif);
		sem_post(philo->fork);
		return (0);
	}
	sem_wait(philo->print);
	ft_printtime(philo);
	sem_post(philo->verif);
	printf("Philosopher %d has taken a fork\n", id);
	sem_post(philo->print);
	sem_wait(philo->fork);
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (sem_post(philo->verif), 0);
	sem_wait(philo->print);
	ft_printtime(philo);
	sem_post(philo->verif);
	printf("Philosopher %d has taken a fork\n", id);
	sem_post(philo->print);
	(void)me;
	return (1);
}

void	ft_drop_fork(t_philo *philo)
{
	sem_post(philo->fork);
	sem_post(philo->fork);
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	int	eat;

	if (!ft_take_fork(me->id, me, philo))
		return (ft_unlock(philo->fork, philo->fork, NULL, NULL));
	sem_wait(philo->verif);
	eat = philo->time_to_eat;
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, philo->fork,
				philo->fork, philo->verif));
	sem_wait(philo->print);
	ft_printtime(philo);
	sem_post(philo->verif);
	printf("Philosopher %d is eating\n", me->id);
	sem_post(philo->print);
	ft_reset_meat(me, philo);
	usleep(eat);
	ft_drop_fork(philo);
	ft_add_eat(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	sem_wait(philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, philo->verif, NULL, NULL));
	sem_wait(philo->print);
	ft_printtime(philo);
	sem_post(philo->verif);
	printf("Philosopher %d is thinking\n", me.id);
	sem_post(philo->print);
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	int	tmp;

	sem_wait(philo->verif);
	tmp = philo->time_to_sleep;
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(NULL, philo->verif, NULL, NULL));
	sem_wait(philo->print);
	ft_printtime(philo);
	sem_post(philo->verif);
	printf("Philosopher %d is sleeping\n", me.id);
	sem_post(philo->print);
	usleep(tmp);
}
