
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include "philo_struct.h"

# define INSTRUCTION "Wrong number of argument | Usage : number_of_philosophers, time_to_die time_to_eat, time_to_sleep, number_of_times_each_philosopher_must_eat." 
# define MALLOC "Memory allocution failed, exit."
# define INVALID_ARGS "Invalid argument, argument must contains only digit."

/*=============== Parse ===============*/

/* init_utils.c */
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

/* init_philo.c */
void	init_philo(char **args, t_philo **philo, t_data *data);


/*=============== Utils ===============*/

/* utils.c */
void	*ft_calloc(size_t count, size_t size);

/* clear.c */
void	ft_error(char *msg, t_philo **philo);



#endif