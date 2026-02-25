/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:07:06 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 18:07:06 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((*tmp1 || *tmp2) && (n > 0))
	{
		if (*tmp1 != *tmp2)
		{
			return (*tmp1 - *tmp2);
		}
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

static void	update_meat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo);
	philo->meal_counter++;
	philo->last_meat = get_current_time(philo);
	pthread_mutex_unlock(&philo->philo);
}

int	eat_routine(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	if (philo->data->number_of_philosophers == 1)
	{
		ft_usleep(philo->data->time_to_die, philo);
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	update_meat_philo(philo);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	return (0);
}
