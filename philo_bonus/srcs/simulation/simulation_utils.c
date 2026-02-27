/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:43:23 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/27 17:43:23 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	check_simulation_end(t_data *data)
{
	int	status;

	status = data->end_checker;
	return (status);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time_stamp;

	time_stamp = get_current_time(philo) - philo->data->start_time;
	sem_wait(philo->data->sem_printer);
	printf("%lli %d %s\n", time_stamp, philo->id_philo, status);
	sem_post(philo->data->sem_printer);
}

int	ft_usleep(int milliseconds, t_philo *philo)
{
	long long	start;

	start = get_current_time(philo);
	while ((get_current_time(philo) - start) < milliseconds)
	{
		if (check_simulation_end(philo->data) == DEAD)
			break ;
		usleep(500);
	}
	return (0);
}

void	printer_death(t_philo *philo)
{
	sem_wait(philo->data->sem_printer);
	printf("%lli %d died\n", get_current_time(philo) - philo->data->start_time,
		philo->id_philo);
}

void	put_fork_on_table(t_philo *philo)
{
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}
