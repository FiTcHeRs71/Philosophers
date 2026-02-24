/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:01:12 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 19:01:21 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	update_args(t_data *data, char **args)
{
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
	{
		data->number_of_eat = ft_atoi(args[5]);
	}
	else
	{
		data->number_of_eat = -1;
	}
}

static void	init_philosophers(t_philo *philo, t_data *data, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo[i].data = data;
		philo[i].id_philo = i + 1;
		philo[i].status = -1;
		philo[i].last_meat = get_current_time(philo);
		pthread_mutex_init(&philo[i].philo, NULL);
		data->flag_mutex_philo++;
		philo[i].mutex_left_fork = &data->forks[i];
		philo[i].mutex_right_fork = &data->forks[(i + 1)
			% data->number_of_philosophers];
		i++;
	}
}

static void	init_data(t_data *data, t_philo *philo, char **args)
{
	struct timeval	current_time;
	int				i;

	i = 0;
	data->number_of_philosophers = ft_atoi(args[1]);
	if (data->number_of_philosophers <= 0)
		ft_error(INVALID_NB_PHILO, philo, data);
	update_args(data, args);
	if (gettimeofday(&current_time, NULL) == -1)
		ft_error(TIME_SET, philo, data);
	data->start_time = (current_time.tv_sec * 1000) + (current_time.tv_usec
			/ 1000);
	pthread_mutex_init(&data->mutex_global_printer, NULL);
	pthread_mutex_init(&data->mutex_end, NULL);
	data->flag_global_mutex = 1;
	data->forks = ft_calloc(data->number_of_philosophers,
			sizeof(pthread_mutex_t));
	if (!data->forks)
		ft_error(MALLOC, philo, data);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->flag_mutex_fork++;
		i++;
	}
}

static void	checker_args(char **args, t_philo *philo, t_data *data)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		if (!check_arg_is_digit(args[i]))
			ft_error(INVALID_ARGS, philo, data);
		i++;
	}
}

void	init_philo(char **args, t_philo *philo, t_data *data)
{
	checker_args(args, philo, data);
	init_data(data, philo, args);
	init_philosophers(philo, data, data->number_of_philosophers);
}
