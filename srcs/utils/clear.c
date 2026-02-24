/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:01:57 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 19:02:01 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static void	clean_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	if (philo && data && data->forks)
	{
		while (i < data->number_of_philosophers)
		{
			if (i < data->flag_mutex_fork)
				pthread_mutex_destroy(&data->forks[i]);
			if (i < data->flag_mutex_philo)
				pthread_mutex_destroy(&philo[i].philo);
			i++;
		}
		free(data->forks);
	}
	if (philo)
		free(philo);
}

static void	clean_data(t_data *data)
{
	if (!data)
		return ;
	if (data->flag_global_mutex == 1)
	{
		pthread_mutex_destroy(&data->mutex_global_printer);
		pthread_mutex_destroy(&data->mutex_end);
	}
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
