/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:29:10 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/05 09:29:09 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo_2(t_philo *new, t_rules *rules)
{
	new->count = rules->count;
	new->time_to_die = rules->time_to_die;
	new->time_to_eat = rules->time_to_eat * 1000;
	new->time_to_sleep = rules->time_to_sleep * 1000;
	new->count_of_eat = rules->count_of_eat;
	new->end_eat = 0;
	new->death = 0;
}

t_philo	*ft_init_philo(t_rules *rules)
{
	int				i;
	t_philo			*new;

	i = -1;
	new = malloc(sizeof(t_philo));
	ft_init_philo_2(new, rules);
	new->thread = malloc(sizeof(pthread_t) * new->count);
	pthread_mutex_init(&new->time, NULL);
	pthread_mutex_init(&new->verif, NULL);
	pthread_mutex_init(&new->print, NULL);
	new->mutex = malloc(sizeof(pthread_mutex_t) * new->count);
	while (++i < new->count)
		pthread_mutex_init(&new->mutex[i], NULL);
	i = 0;
	while (++i <= new->count)
	{
		pthread_mutex_lock(&new->verif);
		new->start = i;
		pthread_mutex_unlock(&new->verif);
		pthread_create(&new->thread[i - 1], NULL, (void *) ft_thread, new);
		usleep(10000);
	}
	return (new);
}

void	ft_free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->count)
	{
		pthread_join(philo->thread[i], NULL);
		i++;
	}
	free(philo->thread);
	free(philo->mutex);
	free(philo);
}

void	ft_infinite_loop(t_philo *philo)
{
	while (!philo->death && philo->end_eat < philo->count)
	{
		pthread_mutex_unlock(&philo->verif);
		sleep(1);
		pthread_mutex_lock(&philo->verif);
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!ft_ok_values(rules, argc, argv))
		return (ft_error_philo("Invalid Arguments", 0, rules, free));
	if (rules->count == 1)
		return (0);
	philo = ft_init_philo(rules);
	free(rules);
	usleep(100);
	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->tv, NULL);
	philo->sec = philo->tv.tv_sec;
	philo->msec = philo->tv.tv_usec / 1000;
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_lock(&philo->verif);
	philo->start = 0;
	ft_infinite_loop(philo);
	usleep(philo->time_to_eat + philo->time_to_sleep);
	pthread_mutex_unlock(&philo->verif);
	ft_free_philo(philo);
	return (1);
}
