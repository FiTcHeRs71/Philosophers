
#include "../../includes/philo.h"

static void	init_philosophers(t_philo **philo, int nb_philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * nb_philo);
	while (i < nb_philo)
	{
		memset(&(*philo)[i], 0, sizeof(t_philo));
		(*philo)[i].id_philo = i + 1;
		i++;
	}
}

static void	init_data(t_data *data, char **args)
{
	struct timeval	*current_time;

	current_time = NULL;
	data->number_of_philosophers = ft_atoi(args[1]);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	data->number_of_eat = ft_atoi(args[5]);
	data->start_time = gettimeofday(current_time, NULL);
	pthread_mutex_init(data->mutex_global_printer, NULL);

}

static void	checker_args(char **args, t_philo **philo)
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

void	init_philo(char **args, t_philo **philo, t_data *data)
{
	checker_args(args, philo);
	init_data(data , args);
	init_philosophers(philo, data->number_of_philosophers);
}

/*
	while (nb_philo > 0)
	{
		(*(philo[nb_philo])) = malloc(1 * sizeof(t_philo *));
		memset(philo[nb_philo], 0, sizeof(t_philo));
		philo[nb_philo]->id_philo = nb_philo;
		philo[nb_philo]->status = -1;
		philo[nb_philo]->data->start_time = gettimeofday(current_time, NULL);
		philo[nb_philo]->data->number_of_philosophers = argc - 1;
		philo[nb_philo]->data->time_to_die = ft_atoi(args[2]);
		philo[nb_philo]->data->time_to_eat = ft_atoi(args[3]);
		philo[nb_philo]->data->time_to_sleep = ft_atoi(args[4]);
		philo[nb_philo]->data->number_of_eat = ft_atoi(args[5]);
	}
*/