/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:48:49 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/05 09:30:04 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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
	pthread_mutex_t	time;
	pthread_mutex_t	print;
	pthread_mutex_t	verif;
	pthread_mutex_t	*mutex;
}			t_philo;

typedef struct s_myphilo
{
	int				id;
	int				count_of_eat;
	int				time_to_die;
	long long		last_meat;
	t_philo			*philo;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
}			t_myphilo;

typedef struct s_rules
{
	int	count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	count_of_eat;
}			t_rules;

int		ft_atoi(const char *str);
int		ft_take_fork(int id, t_myphilo *me, t_philo *philo);
int		ft_ok_values(t_rules *rules, int argc, char **argv);
int		ft_error_philo(char *str, int n, void *gofree, void (*ft)(void *));
void	ft_drop_fork(t_myphilo *me);
void	ft_printtime(t_philo *philo);
void	ft_eat(t_myphilo *me, t_philo *philo);
void	ft_think(t_myphilo me, t_philo *philo);
void	ft_sleep(t_myphilo me, t_philo *philo);
void	ft_isdead(t_myphilo me, t_philo *philo);
void	ft_add_eat(t_myphilo *me, t_philo *philo);
void	ft_reset_meat(t_myphilo *me, t_philo *philo);
void	ft_unlock(pthread_mutex_t *m1, pthread_mutex_t *m2,
			pthread_mutex_t *m3, pthread_mutex_t *m4);
void	*ft_thread(t_philo *philo);
void	*ft_death_thread(t_myphilo *me);

#endif