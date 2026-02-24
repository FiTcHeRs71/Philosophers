
#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# include "philo_struct.h"

# define MALLOC "Memory allocution failed, exit."
# define INVALID_ARGS "Invalid argument,only digit between INT MIN and INT MAX."
# define INVALID_NB_PHILO "Invalid number of philo"
# define TIME_SET "Unable to get and set time start"

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

/* clear.c */
void		ft_error(char *msg, t_philo *philo);
void		clean_all(t_philo *philo, t_data *data);

/*=============== Simulation ===============*/

/* simulation.c*/
void		start_simulation(t_data *data, t_philo *philo);

/* simulation_utils.c*/
void		print_status(t_philo *philo, char *status);
int			ft_usleep(int milliseconds, t_philo *philo);
long long	get_current_time(t_philo *philo);
int			check_simulation_end(t_data *data);
void		update_end_flag(t_data *data);

/* simulation_utils2.c*/
int			eat_routine(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		get_current_time_usleep(void);
#endif