
#ifndef PHILO_STRUCT_H

# define PHILO_STRUCT_H

typedef enum s_status
{
	EATING,
	SLEAPING,
	THINKING,
}					t_status;

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