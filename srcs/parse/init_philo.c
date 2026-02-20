
#include "../../includes/philo.h"

void	checker_args(char **args, t_philo **philo)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				ft_error(INVALID_ARGS, philo);
			j++;
		}
		i++;
	}
}

void	init_philo(int argc, char **args, t_philo **philo)
{
	int nb_philo;
	int i = 0;
	struct timeval *current_time;

	nb_philo = argc - 1;
	current_time = NULL;
	checker_args(args, philo);
	while (i < nb_philo)
	{
		philo[i] = malloc(1 * sizeof(t_philo));
		memset(philo[i], 0, sizeof(t_philo));
		philo[i]->id_philo = nb_philo;
		philo[i]->status = -1;
		philo[i]->data->start_time = gettimeofday(current_time, NULL);
		philo[i]->data->number_of_philosophers = argc - 1;
		philo[i]->data->time_to_die = ft_atoi(args[2]);
		philo[i]->data->time_to_eat = ft_atoi(args[3]);
		philo[i]->data->time_to_sleep = ft_atoi(args[4]);
		philo[i]->data->number_of_eat = ft_atoi(args[5]);
		i++;
	}
}