
#include "../../includes/philo.h"

void	update_end_flag(t_data *data)
{
	pthread_mutex_lock(&data->mutex_end);
	data->end_checker = 1;
	pthread_mutex_unlock(&data->mutex_end);
}

int	check_simulation_end(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->mutex_end);
	status = data->end_checker;
	pthread_mutex_unlock(&data->mutex_end);
	return (status);
}

void	ft_usleep(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}

long long	get_current_time(t_philo *philo)
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
	printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	pthread_mutex_unlock(&philo->data->mutex_global_printer);
}
