
#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H


typedef struct s_fork
{
	int	id_fork;
	pthread_mutex_t *mutex;

}			t_fork;



typedef struct	s_philo
{
	int	id_philo;
	int	status;
	int	meal_counter;
	int	is_alive;
	pthread_mutex_t *mutex;

}				t_philo;


typedef struct	s_data
{
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	long long	start_time;
	t_philo	*philo;
	t_fork	*fork;
	pthread_mutex_t *mutex;
}				t_data;



#endif