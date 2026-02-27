/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:28:37 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/27 17:28:37 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	clean_all(t_philo *philo, t_data *data)
{
	if (data->sem_forks != SEM_FAILED)
		sem_close(data->sem_forks);
	if (data->sem_dead != SEM_FAILED)
		sem_close(data->sem_dead);
	if (data->sem_printer != SEM_FAILED)
		sem_close(data->sem_printer);
	if (data->sem_meal != SEM_FAILED)
		sem_close(data->sem_meal);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_dead");
	sem_unlink("/philo_printer");
	sem_unlink("/philo_meal");
	(void)philo;
	if (philo && philo != NULL)
	{
		free(philo);
		philo = NULL;
	}
}

void	ft_error(char *msg, t_philo *philo, t_data *data)
{
	ft_putstr_fd(msg, 2);
	clean_all(philo, data);
	exit(EXIT_FAILURE);
}
