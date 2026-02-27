/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:23:32 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/27 17:24:11 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_BONUS_H

# define PHILO_STRUCT_BONUS_H

typedef struct s_philo	t_philo;

typedef enum s_life
{
	ALIVE,
	DEAD,
}					t_life;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				number_of_eat;
	int				number_of_philosophers;
	int				end_checker;
	long long		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_printer;
	sem_t			*sem_dead;
	sem_t			*sem_meal;
	t_philo			*philo;
}					t_data;

typedef struct s_philo
{
	int				id_philo;
	int				status;
	int				meal_counter;
	long long		last_meat;
	pid_t			pid;
	t_data			*data;
}					t_philo;

#endif