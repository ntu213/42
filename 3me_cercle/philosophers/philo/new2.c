/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:27:30 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/05 09:29:08 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_ok_values(t_rules *rules, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	rules->count = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->count_of_eat = ft_atoi(argv[5]);
	else
		rules->count_of_eat = -1;
	if (rules->count < 1 || rules->time_to_die < 1 || rules->time_to_eat < 1
		|| rules->time_to_sleep < 1 || rules->count_of_eat < -1)
		return (0);
	return (1);
}

t_myphilo	ft_init_myphilo(int id, t_philo *philo)
{
	t_myphilo	new;

	new.id = id;
	new.count_of_eat = -1;
	new.time_to_die = philo->time_to_die;
	new.philo = philo;
	usleep(10);
	if (id % 2 == 0)
	{
		new.fork_l = &philo->mutex[id - 1];
		new.fork_r = &philo->mutex[id % philo->count];
	}
	else
	{
		new.fork_l = &philo->mutex[id % philo->count];
		new.fork_r = &philo->mutex[id - 1];
	}
	return (new);
}

int	ft_exec(t_myphilo *me, t_philo *philo)
{
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	pthread_mutex_unlock(&philo->verif);
	ft_eat(me, philo);
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	pthread_mutex_unlock(&philo->verif);
	ft_sleep(*me, philo);
	pthread_mutex_lock(&philo->verif);
	if (philo->death || philo->end_eat >= philo->count)
		return (0);
	pthread_mutex_unlock(&philo->verif);
	ft_think(*me, philo);
	return (1);
}

void	*ft_thread(t_philo *philo)
{
	t_myphilo	me;
	pthread_t	thread;

	pthread_mutex_lock(&philo->verif);
	me = ft_init_myphilo(philo->start, philo);
	pthread_mutex_lock(&philo->print);
	pthread_mutex_unlock(&philo->print);
	while (philo->start)
	{
		pthread_mutex_unlock(&philo->verif);
		usleep(10);
		pthread_mutex_lock(&philo->verif);
	}
	pthread_mutex_unlock(&philo->verif);
	ft_add_eat(&me, philo);
	pthread_create(&thread, NULL, (void *) ft_death_thread, &me);
	while (1)
		if (!ft_exec(&me, philo))
			break ;
	pthread_mutex_unlock(&philo->verif);
	pthread_join(thread, NULL);
	return (philo);
}

pthread_t	ft_init_thread(t_philo *philo)
{
	pthread_t	new;

	pthread_create(&new, NULL, (void *) ft_thread, philo);
	return (new);
}
