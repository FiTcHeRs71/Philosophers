/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:00:27 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/24 19:00:31 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H

# define PHILO_STRUCT_H

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
	int				flag_mutex_philo;
	int				flag_mutex_fork;
	int				flag_global_mutex;
	long long		start_time;
	pthread_mutex_t	mutex_end;
	pthread_mutex_t	mutex_global_printer;
	pthread_mutex_t	*forks;
}					t_data;

typedef struct s_philo
{
	int				id_philo;
	int				status;
	int				meal_counter;
	long long		last_meat;
	pthread_t		thread_id;
	pthread_mutex_t	*mutex_left_fork;
	pthread_mutex_t	*mutex_right_fork;
	pthread_mutex_t	philo;
	t_data			*data;
}					t_philo;

#endif