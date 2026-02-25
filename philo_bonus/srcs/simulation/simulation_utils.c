
#include "../../includes/philo_bonus.h"

int	check_simulation_end(t_data *data)
{
	int	status;

	status = data->end_checker;
	return (status);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time_stamp;

	time_stamp = get_current_time(philo) - philo->data->start_time;
	sem_wait(philo->data->sem_printer);
	if (ft_strncmp(status, "died", 5) == 0)
		printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	else if (philo->data->end_checker == ALIVE)
		printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	sem_post(philo->data->sem_printer);
}

int	ft_usleep(int milliseconds, t_philo *philo)
{
	long long	start;

	start = get_current_time(philo);
	while ((get_current_time(philo) - start) < milliseconds)
	{
		if (check_simulation_end(philo->data) == DEAD)
			break ;
		usleep(10);
	}
	return (0);
}
