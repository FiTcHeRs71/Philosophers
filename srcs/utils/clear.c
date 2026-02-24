/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:11:28 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 18:12:16 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_putstr_fd(char *s, int fd)
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
	ft_putstr_fd(msg, 2);
	clean_all(philo, philo->data);
	exit(EXIT_FAILURE);
}
