/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:29:10 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/22 10:21:54 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
//printf("%d|%d\n", id - 1, id % philo->count);
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
//	t_tmp		tmp;
	pthread_t	thread;

//	tmp = ft_get_tmp(&me, philo);
	pthread_mutex_lock(&philo->verif);
	me = ft_init_myphilo(philo->start, philo);
	pthread_mutex_lock(&philo->print);
//printf("started thread %d\n", me.id);
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
	{
		if (!ft_exec(&me, philo))
			break ;
	}
	pthread_mutex_unlock(&philo->verif);
	pthread_mutex_lock(&philo->print);
//printf("join thread %d\n", me.id);
	pthread_mutex_unlock(&philo->print);
	pthread_join(thread, NULL);
	pthread_mutex_lock(&philo->print);
//printf("joined thread %d\n", me.id);
	pthread_mutex_unlock(&philo->print);
	return (philo);
}

pthread_t	ft_init_thread(t_philo *philo)
{
	pthread_t	new;

	pthread_create(&new, NULL, (void *) ft_thread, philo);
	return (new);
}

t_philo	*ft_init_philo(t_rules *rules)
{
	int				i;
	t_philo			*new;

	i = -1;
	new = malloc(sizeof(t_philo));
	new->count = rules->count;
	new->time_to_die = rules->time_to_die;
	new->time_to_eat = rules->time_to_eat * 1000;
	new->time_to_sleep = rules->time_to_sleep * 1000;
	new->count_of_eat = rules->count_of_eat;
	new->end_eat = 0;
	new->death = 0;
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
//	printf("%p\n", &new->start);
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
	while (!philo->death && philo->end_eat < philo->count)
	{
//fflush(stdout);
		pthread_mutex_unlock(&philo->verif);
		sleep(1);
		pthread_mutex_lock(&philo->verif);
	}
	usleep(philo->time_to_eat + philo->time_to_sleep);
	pthread_mutex_unlock(&philo->verif);
	ft_free_philo(philo);
	return (1);
}