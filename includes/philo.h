
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include "philo_struct.h"

# define MALLOC "Memory allocution failed, exit."
# define INVALID_ARGS "Invalid argument, argument must contains only digit between INT MIN and INT MAX."
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

/*=============== Simulation ===============*/

/* simulation.c*/
void		start_simulation(t_data *data, t_philo *philo);

/* simulation_utils.c*/
void		print_status(t_philo *philo, char *status);
void		ft_usleep(int time_in_ms);
long long	get_current_time(t_philo *philo);


#endif