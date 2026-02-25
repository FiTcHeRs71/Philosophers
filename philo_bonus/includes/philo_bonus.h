
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <semaphore.h>

# include "philo_struct_bonus.h"

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
void		ft_putstr_fd(char *s, int fd);
long long	get_current_time(t_philo *philo);

/* clear.c */
void		ft_error(char *msg, t_philo *philo, t_data *data);


/*=============== Simulation ===============*/

/* simulation.c*/

/* simulation_utils.c*/


/* simulation_utils2.c*/


#endif