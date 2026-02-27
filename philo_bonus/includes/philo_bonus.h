/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:42:18 by fducrot           #+#    #+#             */
/*   Updated: 2026/02/27 17:42:27 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <semaphore.h>

# include "philo_struct_bonus.h"

# define MALLOC "Memory allocution failed, exit."
# define INVALID_ARGS "Invalid argument,only digit between INT MIN and INT MAX."
# define INVALID_NB_PHILO "Invalid number of philo"
# define TIME_SET "Unable to get and set time start"
# define SEM_EROR "Unable to set semaphore"

/*=============== Parse ===============*/

/* init_utils.c */
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
bool		check_arg_is_digit(char *str);

/* init_philo.c */
void		init_philo(char **args, t_philo *philo, t_data *data);

/*=============== Utils ===============*/

/* utils.c */
void		*ft_calloc(size_t count, size_t size);
void		ft_putstr_fd(char *s, int fd);
long long	get_current_time(t_philo *philo);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		unlink_sem(void);

/* clear.c */
void		ft_error(char *msg, t_philo *philo, t_data *data);
void		clean_all(t_philo *philo, t_data *data);

/*=============== Simulation ===============*/

/* simulation.c*/
void		start_simulation(t_data *data, t_philo *philo);

/* simulation_utils.c*/
void		print_status(t_philo *philo, char *status);
int			ft_usleep(int milliseconds, t_philo *philo);
int			check_simulation_end(t_data *data);
void		printer_death(t_philo *philo);
void		put_fork_on_table(t_philo *philo);

#endif