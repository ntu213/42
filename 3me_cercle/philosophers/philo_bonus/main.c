/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:53:44 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 14:52:49 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
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

	new = malloc(sizeof(t_philo));
	ft_init_philo_2(new, rules);
	new->thread = malloc(sizeof(pthread_t) * new->count);
	sem_unlink("time");
	sem_unlink("verif");
	sem_unlink("print");
	sem_unlink("fork");
	new->time = sem_open("time", O_CREAT, 0644, 1);
	new->verif = sem_open("verif", O_CREAT, 0644, 1);
	new->print = sem_open("print", O_CREAT, 0644, 1);
	new->fork = sem_open("fork", O_CREAT, 0644, rules->count);
	i = 0;
	while (++i <= new->count)
	{
		sem_wait(new->verif);
		new->start = i;
		sem_post(new->verif);
		pthread_create(&new->thread[i - 1], NULL, (void *) ft_thread, new);
		usleep(10000);
	}
	return (new);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!ft_ok_values(rules, argc, argv))
		return (ft_error_philo("Invalid Arguments", 0, rules, free));
	if (rules->count == 1)
		return (ft_scenario(rules), 0);
	philo = ft_init_philo(rules);
	free(rules);
	usleep(100);
	sem_wait(philo->time);
	gettimeofday(&philo->tv, NULL);
	philo->sec = philo->tv.tv_sec;
	philo->msec = philo->tv.tv_usec / 1000;
	sem_post(philo->time);
	sem_wait(philo->verif);
	philo->start = 0;
	ft_infinite_loop(philo);
	usleep(philo->time_to_eat + philo->time_to_sleep);
	sem_post(philo->verif);
	ft_free_philo(philo);
	return (1);
}
