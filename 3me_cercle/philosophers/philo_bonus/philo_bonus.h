/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:23:19 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/06 10:32:46 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_eat;
	int				end_eat;
	int				death;
	int				start;
	int				go;
	int				sec;
	int				msec;
	pthread_t		*thread;
	struct timeval	tv;
	sem_t			*time;
	sem_t			*print;
	sem_t			*verif;
	sem_t			*fork;
}			t_philo;

typedef struct s_rules
{
	int	count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	count_of_eat;
}			t_rules;

typedef struct s_myphilo
{
	int				id;
	int				count_of_eat;
	int				time_to_die;
	long long		last_meat;
	t_philo			*philo;
}			t_myphilo;

int		ft_take_fork(int id, t_myphilo *me, t_philo *philo);
int		ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *));
void	ft_scenario(t_rules *rules);
void	ft_drop_fork(t_philo *philo);
void	ft_printtime(t_philo *philo);
void	ft_free_philo(t_philo *philo);
void	ft_infinite_loop(t_philo *philo);
void	ft_eat(t_myphilo *me, t_philo *philo);
void	ft_think(t_myphilo me, t_philo *philo);
void	ft_sleep(t_myphilo me, t_philo *philo);
void	ft_add_eat(t_myphilo *me, t_philo *philo);
void	ft_reset_meat(t_myphilo *me, t_philo *philo);
void	ft_unlock(sem_t *m1, sem_t *m2, sem_t *m3, sem_t *m4);
void	*ft_thread(t_philo *philo);
void	*ft_death_thread(t_myphilo *me);

#endif