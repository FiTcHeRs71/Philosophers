
#include "../../includes/philo.h"

static void	update_meat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo);
	philo->meal_counter++;
	philo->last_meat = get_current_time(philo);
	pthread_mutex_unlock(&philo->philo);
}

int	eat_routine(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	if (philo->data->number_of_philosophers == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	update_meat_philo(philo);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	return (0);
}