
#include "../../includes/philo.h"

static void	death_update(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&data->mutex_end);
	data->end_checker = DEAD;
	pthread_mutex_unlock(&data->mutex_end);
	print_status(philo, "died");
	pthread_mutex_unlock(&philo[i].philo);
}

static void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	philo = (t_philo *)arg;
	first = philo->mutex_left_fork;
	second = philo->mutex_right_fork;
	if (philo->mutex_left_fork > philo->mutex_right_fork)
	{
		first = philo->mutex_right_fork;
		second = philo->mutex_left_fork;
	}
	if (philo->id_philo % 2 == 0)
		ft_usleep(20);
	while (1)
	{
		if (check_simulation_end(philo->data) == 1)
			break ;
		if (eat_routine(philo, first, second) == 1)
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	monitor_routine(data, philo);
	while (i < data->number_of_philosophers)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}
