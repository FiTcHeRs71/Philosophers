
#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_data
{
	int	*value;
	pthread_mutex_t *mutex;
}				t_data;




#endif