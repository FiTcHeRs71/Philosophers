/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:23:03 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 18:29:18 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;

	if (argc == 6 || argc == 5)
	{
		memset(&data, 0, sizeof(t_data));
		philo = ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
		if (!philo)
			ft_error(MALLOC, philo, &data);
		init_philo(argv, philo, &data);
		start_simulation(&data, philo);
		clean_all(philo, &data);
	}
	else
	{
		ft_putstr_fd("Wrong number of argument | Usage : "
			"number_of_philosophers, time_to_die time_to_eat, "
			"time_to_sleep, [number_of_times_each_philosopher_must_eat].\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
