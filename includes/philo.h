
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# include "philo_struct.h"

# define INSTRUCTION "Wrong number of argument | Usage : number_of_philosophers, time_to_die time_to_eat, time_to_sleep, number_of_times_each_philosopher_must_eat." 
# define MALLOC "Memory allocution failed, exit."
void	ft_error(char *msg, t_data *data);



#endif