
#include "../../includes/philo_bonus.h"

static void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while (true)
	{
		sem_wait(philo->data->sem_meal);
		if (get_current_time(philo) - philo->last_meat > philo->data->time_to_die)
		{
			print_status(philo, "died");
			sem_post(philo->data->sem_dead);
			exit (1);
		}
		if (philo->meal_counter >= philo->data->number_of_eat)
		{
			sem_post(philo->data->sem_forks);
			sem_post(philo->data->sem_forks);
			sem_post(philo->data->sem_meal);
			exit (0);
		}
		sem_post(philo->data->sem_meal);
		usleep(1000);
	}
	return (NULL);
}

static void	routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, &monitor_routine, philo);
	pthread_detach(monitor_thread);
	if (philo->id_philo % 2 == 0)
		ft_usleep(20, philo);
	while (true)
	{
		sem_wait(philo->data->sem_forks);
		print_status(philo, "has taken a fork");
		sem_wait(philo->data->sem_forks);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		sem_wait(philo->data->sem_meal);
		philo->last_meat = get_current_time(philo);
		philo->meal_counter++;
		sem_post(philo->data->sem_meal);
		ft_usleep(philo->data->time_to_eat, philo);
		sem_post(philo->data->sem_forks);
		sem_post(philo->data->sem_forks);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo);
		print_status(philo, "is_thiking");
	}
	exit(0);
}

void	start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->start_time = get_current_time(philo);
	while (i < data->number_of_philosophers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			routine(&philo[i]);
		i++;
	}
}