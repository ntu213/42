/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:29:10 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/08 16:52:04 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *))
{
	printf("[Error] %s\n", str);
	ft(gofree);
	return (n);
}

void	ft_unlock(pthread_mutex_t *m1, pthread_mutex_t *m2, pthread_mutex_t *m3, pthread_mutex_t *m4)
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

t_myphilo	ft_init_myphilo(int id, pthread_mutex_t *m1, pthread_mutex_t *m2)
{
	t_myphilo	new;

	new.id = id;
	new.count_of_eat = -1;
	new.fork_l = m1;
	new.fork_r = m2;
	return (new);
}

void	ft_add_eat(t_myphilo *me, t_philo *philo)
{
	me->count_of_eat++;
	if (me->count_of_eat == philo->count_of_eat)
		philo->end_eat++;
	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
}

t_tmp	*ft_get_tmp(t_myphilo *me, t_philo *philo)
{
	t_tmp	new;

	new.me = me;
	new.philo = philo;
	return (&new);
}

void	ft_isdead(t_myphilo me, t_philo *philo)
{
	long long	time;

	gettimeofday(&philo->tv, NULL);
	time = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (time - me.last_meat >= philo->time_to_die && !philo->death)
	{
		if (philo->death || philo->end_eat >= philo->count)
			return ;
		philo->death = 1;
		pthread_mutex_lock(philo->print);
		if (philo->death || philo->end_eat >= philo->count)
			return (ft_unlock(philo->print, NULL, NULL, NULL));
		gettimeofday(&philo->tv, NULL);
		ft_printtime(philo);
		printf("Philosopher %d is dead\n", me.id);
		pthread_mutex_unlock(philo->print);
	}
}

void	*ft_death_thread(t_tmp *tmp)
{
	t_myphilo	*me;
	t_philo		*philo;

	me = tmp->me;
	philo = tmp->philo;
	while (!philo->death && philo->end_eat < philo->count)
	{
		ft_isdead(*me, philo);
		usleep(1000);
	}
}

void	ft_take_fork(int id, t_myphilo* me, t_philo *philo)
{
	pthread_mutex_lock(me->fork_l);
	pthread_mutex_lock(philo->print);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, me->fork_l, NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken left fork\n", id);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(me->fork_r);
	pthread_mutex_lock(philo->print);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, me->fork_l,
			me->fork_r, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken right fork\n", id);
	pthread_mutex_unlock(philo->print);
}

void	ft_drop_fork(t_myphilo *me)
{
	pthread_mutex_unlock(me->fork_l);
	pthread_mutex_unlock(me->fork_r);
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	ft_take_fork(me->id, me, philo);
	pthread_mutex_lock(philo->print);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, philo->mutex[me->id - 1],
			philo->mutex[me->id % philo->count], NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is eating\n", me->id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_eat);
	ft_drop_fork(me);
	ft_add_eat(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, NULL, NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is thinking\n", me.id);
	pthread_mutex_unlock(philo->print);
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, NULL, NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is sleeping\n", me.id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_sleep);
}

void	*ft_thread(t_philo *philo)
{
	t_myphilo	me;
	pthread_t	thread;

	pthread_create(&thread, NULL, (void *) ft_death_thread,
		ft_get_tmp(&me, philo));
	while (philo->start)
		usleep(10);
	me = ft_init_myphilo(philo->start, philo->mutex[me.id - 1],
		philo->mutex[me.id % philo->count]);
printf("%d started!\n", me.id);
	ft_add_eat(&me, philo);
	while (!philo->death && philo->end_eat < philo->count)
	{
		ft_eat(&me, philo);
		ft_sleep(me, philo);
		ft_think(me, philo);
	}
	pthread_mutex_lock(philo->print);
	printf("thread exit: %d\n", me.id);
	pthread_mutex_unlock(philo->print);
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
	new->thread = malloc(sizeof(pthread_t) * new->count);
	new->print = ft_init_mutex();
	new->mutex = malloc(sizeof(pthread_mutex_t *) * new->count);
	while (++i <= new->count)
	{
		new->start = i;
		new->thread[i - 1] = ft_init_thread(new);
		new->mutex[i - 1] = ft_init_mutex();
		usleep(100);
	}
	return (new);
}

void	ft_free_philo(t_philo *philo)
{
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!ft_ok_values(rules, argc, argv))
		return (ft_error_philo("Invalid Arguments", 0, rules, free));
	philo = ft_init_philo(rules);
	free(rules);
	usleep(100);
	gettimeofday(&philo->tv, NULL);
	philo->sec = philo->tv.tv_sec;
	philo->msec = philo->tv.tv_usec / 1000;
	philo->start = 0;
	while (!philo->death && philo->end_eat < philo->count)
		usleep(10);
	ft_free_philo(philo);
	return (1);
}