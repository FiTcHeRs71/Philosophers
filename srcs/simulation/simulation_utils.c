
#include "../../includes/philo.h"

static long long	get_current_time(t_philo *philo)
{
	struct timeval	current_time;
	long long		time;

	if (gettimeofday(&current_time, NULL) == -1)
		ft_error(TIME_SET, philo);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time_stamp;

	time_stamp = get_current_time(philo) - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_global_printer);
	printf("%lli - Philosophe %d has taken a fork !\n",time_stamp, philo->id_philo);
	printf("%s", status);
	pthread_mutex_unlock(&philo->data->mutex_global_printer);
}