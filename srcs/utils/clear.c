
#include "../../includes/philo.h"

static void	clean_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo || !philo->data)
		return ;
	while (i < philo->data->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
		pthread_mutex_destroy(&philo[i].philo);
		i++;
	}
	if (philo->data->forks)
		free(philo->data->forks);
	if (philo)
		free(philo);
}

static void	clean_data(t_data *data)
{
	if (!data)
		return ;
	pthread_mutex_destroy(&data->mutex_global_printer);
	pthread_mutex_destroy(&data->mutex_end);
}

void	clean_all(t_philo *philo, t_data *data)
{
	if (data)
		clean_data(data);
	if (philo)
		clean_philo(philo);
}

void	ft_error(char *msg, t_philo *philo)
{
	printf("%s\n", msg);
	clean_all(philo, philo->data);
	exit(EXIT_FAILURE);
}
