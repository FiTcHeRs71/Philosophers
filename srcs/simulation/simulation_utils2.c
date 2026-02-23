
#include "../../includes/philo.h"

void	*handler_one_philo(t_philo *philo)
{
	ft_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->mutex_left_fork);
	return (NULL);
}