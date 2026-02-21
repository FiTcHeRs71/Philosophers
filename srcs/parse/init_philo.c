
#include "../../includes/philo.h"

static void	init_philosophers(t_philo **philo, t_data *data, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo[i] = ft_calloc(1, sizeof(t_philo));
		philo[i]->data = data;
		philo[i]->id_philo = i + 1;
		philo[i]->status = -1;
		pthread_mutex_init(&philo[i]->philo, NULL);
		if (i == 0)
		{
			philo[i]->mutex_left_fork = &data->forks[nb_philo];
			philo[i]->mutex_right_fork = &data->forks[i];
		}
		else
		{		
			philo[i]->mutex_left_fork = &data->forks[i - 1];
			philo[i]->mutex_right_fork = &data->forks[i];
		}
		i++;
	}
}

static void	init_data(t_data *data, char **args)
{
	struct timeval	current_time;
	int	i;

	i = 0;
	data->number_of_philosophers = ft_atoi(args[1]);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	data->number_of_eat = ft_atoi(args[5]);
	data->start_time = gettimeofday(&current_time, NULL);
	pthread_mutex_init(&data->mutex_global_printer, NULL);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	
}

static void	checker_args(char **args, t_philo **philo)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		if (!check_arg_is_digit(args[i]))
				ft_error(INVALID_ARGS, philo);
		i++;
	}
}

void	init_philo(char **args, t_philo **philo, t_data *data)
{
	checker_args(args, philo);
	init_data(data , args);
	init_philosophers(philo, data, data->number_of_philosophers);
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