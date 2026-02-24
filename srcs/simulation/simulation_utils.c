
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


int	ft_usleep(int milliseconds, t_philo *philo)
{
	int	start;

	start = get_current_time(philo);
	while ((get_current_time(philo) - start) < milliseconds)
	{
		pthread_mutex_lock(&philo->data->mutex_end);
		if (philo->data->end_checker == ALIVE)
			ft_usleep(100, philo);
		/*else
		{
			pthread_mutex_unlock(&philo->data->mutex_end);
			break ;
		}
		pthread_mutex_unlock(&philo->data->mutex_end);*/
	}
	return (0);
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
	pthread_mutex_lock(&philo->data->mutex_end);
	if (philo->data->end_checker == ALIVE)
		printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	else if (philo->data->end_checker == DEAD && ft_strncmp(status, "died", 5) == 0)
		printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	pthread_mutex_unlock(&philo->data->mutex_end);
	pthread_mutex_unlock(&philo->data->mutex_global_printer);
}
