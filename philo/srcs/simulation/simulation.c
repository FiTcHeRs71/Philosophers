/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:05:15 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 18:05:15 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	death_update(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&data->mutex_end);
	data->end_checker = DEAD;
	pthread_mutex_unlock(&data->mutex_end);
	print_status(&philo[i], "died");
	pthread_mutex_unlock(&philo[i].philo);
}

void	monitor_routine(t_data *data, t_philo *philo)
{
	int	i;
	int	all_ate;

	while (true)
	{
		i = 0;
		all_ate = 0;
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&philo[i].philo);
			if (get_current_time(philo)
				- philo[i].last_meat > data->time_to_die)
				return (death_update(data, philo, i));
			if (data->number_of_eat != -1 && philo[i].meal_counter
				>= data->number_of_eat)
				all_ate++;
			pthread_mutex_unlock(&philo[i].philo);
			i++;
		}
		if (data->number_of_eat != -1
			&& all_ate == data->number_of_philosophers)
			return (update_end_flag(data));
		usleep(1000);
	}
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
		ft_usleep(20, philo);
	while (1)
	{
		if (check_simulation_end(philo->data) == 1)
			break ;
		if (eat_routine(philo, first, second) == 1)
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo);
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
