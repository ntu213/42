/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:48:25 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/01 18:17:36 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	pthread_mutex_t tmp;
	int ismutex = 0;

void	ft_tmp(int n)
{
	int i;
	int	hasmutex;

	i = 0;
	hasmutex = 0;
	while (i < 5)
	{
		printf("%d\n", n);
		if (hasmutex)
		{
			pthread_mutex_unlock(&tmp);
			printf("%d throws mutex\n", n);
			ismutex = 0;
			hasmutex = 0;
		}
		usleep(n * 50000);
		if (!ismutex)
		{
			pthread_mutex_lock(&tmp);
			printf("%d has mutex\n", n);
			ismutex = 1;
			hasmutex = 1;
			usleep(50000);
		}
		i++;
	}
	if (hasmutex)
	{
		pthread_mutex_unlock(&tmp);
		printf("%d throws mutex\n", n);
		ismutex = 0;
		hasmutex = 0;
	}
}
*/

int	ft_error(char *str, int n, void *gofree, void (*ft)(void *))
{
	printf("[Error] %s\n", str);
	ft(gofree);
	return (n);
}

t_myphilo	ft_init_myphilo(int id)
{
	t_myphilo	new;

	new.id = id;
	new.count_of_eat = 0;
	new.fork_i = 0;
	new.fork_r = 0;
	return (new);
}

void	ft_take_fork(int id, t_myphilo* me, t_philo *philo)
{
	if (philo->fork[id - 1])
	{
		philo->fork[id - 1] = 0;
		me->fork_i = 1;
//		printf("Philosopher %d has taken fork %i\n", id, id - 1);
	gettimeofday(&philo->tv, NULL);
		printf("[%ld%.3ld] Philosopher %d has taken left fork\n",
			philo->tv.tv_sec, philo->tv.tv_usec / 1000, id);
	}
	if (philo->fork[id % philo->count])
	{
		philo->fork[id % philo->count] = 0;
		me->fork_r = 1;
//		printf("Philosopher %d has taken fork %i\n", id, id % philo->count);
	gettimeofday(&philo->tv, NULL);
		printf("[%ld%.3ld] Philosopher %d has taken right fork\n",
			philo->tv.tv_sec, philo->tv.tv_usec / 1000, id);
	}
}

void	ft_drop_fork(t_myphilo *me, t_philo *philo)
{
	philo->fork[me->id - 1] = 1;
	me->fork_i = 0;
	philo->fork[me->id % philo->count] = 1;
	me->fork_r = 0;
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	gettimeofday(&philo->tv, NULL);
	printf("[%ld%.3ld] Philosopher %d is sleeping\n", philo->tv.tv_sec,
		philo->tv.tv_usec / 1000, me.id);
	usleep(philo->time_to_sleep);
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	while ((!me->fork_i || !me->fork_r) && !philo->death)
		ft_take_fork(me->id, me, philo);
	gettimeofday(&philo->tv, NULL);
	printf("[%ld%.3ld] Philosopher %d is eating\n", philo->tv.tv_sec,
		philo->tv.tv_usec / 1000, me->id);
	usleep(philo->time_to_eat);
	ft_drop_fork(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	gettimeofday(&philo->tv, NULL);
	printf("[%ld%.3ld] Philosopher %d is thinking\n", philo->tv.tv_sec,
		philo->tv.tv_usec / 1000, me.id);
}

void	*ft_thread(t_philo *philo)
{
	t_myphilo	me;

	me = ft_init_myphilo(philo->start);
	while (philo->start)
		usleep(10);
	if (me.id % 2 == 0)
		ft_take_fork(me.id, &me, philo);
	else
		usleep(1000);
	printf("%d started!\n", me.id);
	while (!philo->start && !philo->death)
	{
		ft_eat(&me, philo);
		ft_sleep(me, philo);
		ft_think(me, philo);
	}
	philo->death = 1;
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
	int		i;
	t_philo	*new;

	i = 0;
	new = malloc(sizeof(t_philo));
	new->count = rules->count;
	new->time_to_die = rules->time_to_die * 1000;
	new->time_to_eat = rules->time_to_eat * 1000;
	new->time_to_sleep = rules->time_to_sleep * 1000;
	new->count_of_eat = rules->count_of_eat;
	new->death = 0;
	new->fork = malloc(sizeof(int) * new->count);
	new->thread = malloc(sizeof(pthread_t) * new->count);
//	new->mutex = malloc(sizeof(pthread_mutex_t *) * new->count);
	while (++i <= new->count)
	{
		new->start = i;
		new->fork[i - 1] = 1;
		new->thread[i - 1] = ft_init_thread(new);
		usleep(100);
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
//		pthread_mutex_destroy(philo->mutex[i]);
		i++;
	}
	free(philo->fork);
	free(philo->thread);
//	free(philo->mutex);
	free(philo);
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

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!ft_ok_values(rules, argc, argv))
		return (ft_error("Invalid Arguments", 0, rules, free));
//	pthread_mutex_init(&tmp, NULL);
	philo = ft_init_philo(rules);
	int i = 0;
	while (i < 1)
	{
	gettimeofday(&philo->tv, NULL);
		printf("%d%d\n", philo->tv.tv_sec, philo->tv.tv_usec / 1000);
		sleep(1);
		i++;
	}
	sleep(1);
	free(rules);
	philo->start = 0;
	while (!philo->start && !philo->death)
		usleep(1);
//	pthread_mutex_destroy(&tmp);
	ft_free_philo(philo);
	return (1);
}
