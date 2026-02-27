#include "../../includes/philo_bonus.h"

static void	clean_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	if (philo && data)
	{
		while (i < data->number_of_philosophers)
		{
			i++;
		}
	}
	if (philo)
		free(philo);
}

static void	clean_data(t_data *data)
{
	if (!data)
		return ;
	sem_post(data->sem_dead);
	sem_close(data->sem_dead);
	sem_close(data->sem_forks);
	sem_close(data->sem_meal);
	sem_close(data->sem_printer);
}

void	clean_all(t_philo *philo, t_data *data)
{
	if (data)
		clean_data(data);
	if (philo)
		clean_philo(philo, data);
}

void	ft_error(char *msg, t_philo *philo, t_data *data)
{
	ft_putstr_fd(msg, 2);
	clean_all(philo, data);
	exit(EXIT_FAILURE);
}
