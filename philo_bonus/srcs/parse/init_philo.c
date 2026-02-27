/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:14:45 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/27 13:16:26 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

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
		i++;
	}
}

static void	init_data(t_data *data, t_philo *philo, char **args)
{
	struct timeval	cur_time;

	data->number_of_philosophers = ft_atoi(args[1]);
	if (data->number_of_philosophers <= 0)
		ft_error(INVALID_NB_PHILO, philo, data);
	update_args(data, args);
	if (gettimeofday(&cur_time, NULL) == -1)
		ft_error(TIME_SET, philo, data);
	data->start_time = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_dead");
	sem_unlink("/philo_printer");
	sem_unlink("/philo_meal");
	data->sem_forks = sem_open("/philo_forks", O_CREAT, 0644, data->number_of_philosophers);
	if (data->sem_forks == SEM_FAILED)
		ft_error(SEM_EROR, philo, data);
	data->sem_dead = sem_open("/philo_dead", O_CREAT, 0644, 0);
	if (data->sem_dead == SEM_FAILED)
		ft_error(SEM_EROR, philo, data);
	data->sem_printer = sem_open("/philo_printer", O_CREAT, 0644, 1);
	if (data->sem_printer == SEM_FAILED)
		ft_error(SEM_EROR, philo, data);
	data->sem_meal = sem_open("/philo_meal", O_CREAT, 0644, 1);
	if (data->sem_meal == SEM_FAILED)
		ft_error(SEM_EROR, philo, data);
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
