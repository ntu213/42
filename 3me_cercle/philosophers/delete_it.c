#include "philo.h"

void ft_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
		printf("%s\n", str);
	pthread_mutex_unlock(&philo->print);
}