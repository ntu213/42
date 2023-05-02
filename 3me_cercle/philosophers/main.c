/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:48:25 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/02 13:27:49 by vgiraudo         ###   ########.fr       */
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

int	ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *))
{
	printf("[Error] %s\n", str);
	ft(gofree);
	return (n);
}

void	ft_printtime(t_philo *philo)
{
	if (philo->tv.tv_usec / 1000 - philo->msec >= 0)
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec,
			philo->tv.tv_usec / 1000 - philo->msec);
	else
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec - 1,
			1000 + (philo->tv.tv_usec / 1000 - philo->msec));
}

void	ft_add_eat(t_myphilo *me, t_philo *philo)
{
	me->count_of_eat++;
	if (me->count_of_eat == philo->count_of_eat)
		philo->end_eat++;
//	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
}

void	ft_isdead(t_myphilo me, t_philo *philo)
{
	long long	time;

	gettimeofday(&philo->tv, NULL);
	time = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (time - me.last_meat >= philo->time_to_die)
	{
		pthread_mutex_lock(philo->print);
		gettimeofday(&philo->tv, NULL);
		ft_printtime(philo);
		printf("Philosopher %d is dead\n", me.id);
		pthread_mutex_unlock(philo->print);
		philo->death = 1;
	}
}

t_myphilo	ft_init_myphilo(int id)
{
	t_myphilo	new;

	new.id = id;
	new.count_of_eat = -1;
	new.fork_i = 0;
	new.fork_r = 0;
	return (new);
}

void	*ft_thread(t_philo *philo)
{
	t_myphilo	me;

	me = ft_init_myphilo(philo->start);
	while (philo->start)
		usleep(10);
	if (me.id % 2 == 0)
		usleep(1000);
//	printf("%d started!\n", me.id);
	ft_add_eat(&me, philo);
	while (!philo->start && !philo->death && philo->end_eat < philo->count)
	{
		ft_eat(&me, philo);
		if (!philo->start && !philo->death && philo->end_eat < philo->count)
			ft_sleep(me, philo);
		if (!philo->start && !philo->death && philo->end_eat < philo->count)
			ft_think(me, philo);
	}
//	philo->death = 1;
	return (philo);
}

pthread_t	ft_init_thread(t_philo *philo)
{
	pthread_t	new;

	pthread_create(&new, NULL, (void *) ft_thread, philo);
	return (new);
}

pthread_mutex_t	*ft_init_mutex(void)
{
	pthread_mutex_t	*new;

	new = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(new, NULL);
	return (new);
}

t_philo	*ft_init_philo(t_rules *rules)
{
	int		i;
	t_philo	*new;

	i = 0;
	new = malloc(sizeof(t_philo));
	new->count = rules->count;
	new->time_to_die = rules->time_to_die;
	new->time_to_eat = rules->time_to_eat * 1000;
	new->time_to_sleep = rules->time_to_sleep * 1000;
	new->count_of_eat = rules->count_of_eat;
	new->end_eat = 0;
	new->death = 0;
//	new->fork = malloc(sizeof(int) * new->count);
	new->thread = malloc(sizeof(pthread_t) * new->count);
	new->print = malloc(sizeof(pthread_mutex_t));
	new->mutex = malloc(sizeof(pthread_mutex_t *) * new->count);
	while (++i <= new->count)
	{
		new->start = i;
//		new->fork[i - 1] = 1;
		new->thread[i - 1] = ft_init_thread(new);
		new->mutex[i - 1] = ft_init_mutex();
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
		pthread_mutex_destroy(philo->mutex[i]);
		free(philo->mutex[i]);
		i++;
	}
//	free(philo->fork);
	free(philo->print);
	free(philo->thread);
	free(philo->mutex);
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
		return (ft_error_philo("Invalid Arguments", 0, rules, free));
	philo = ft_init_philo(rules);
	usleep(100000);
	gettimeofday(&philo->tv, NULL);
	philo->sec = philo->tv.tv_sec;
	philo->msec = philo->tv.tv_usec / 1000;
	free(rules);
	philo->start = 0;
	while (!philo->start && !philo->death && philo->end_eat < philo->count)
	ft_free_philo(philo);
	return (1);
}
