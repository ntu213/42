/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:30:06 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 10:30:57 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->count)
	{
		pthread_join(philo->thread[i], NULL);
		i++;
	}
	sem_close(philo->time);
	sem_close(philo->verif);
	sem_close(philo->print);
	sem_close(philo->fork);
	free(philo->thread);
	free(philo);
}

void	ft_infinite_loop(t_philo *philo)
{
	while (!philo->death && philo->end_eat < philo->count)
	{
		sem_post(philo->verif);
		sleep(1);
		sem_wait(philo->verif);
	}
}

int	ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *))
{
	printf("[Error] %s\n", str);
	ft(gofree);
	return (n);
}

void	ft_scenario(t_rules *rules)
{
	printf("[%.7d] Philosopher 1 has taken left fork\n", 0);
	usleep(rules->time_to_die);
	printf("[%.7d] Philosopher 1 is dead\n", rules->time_to_die);
}
