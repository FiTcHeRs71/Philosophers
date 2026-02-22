
#include "../../includes/philo.h"

void monitor_routine(t_data *data, t_philo *philo)
{
	int	i;
	int	all_ate;

	while (true)
	{
		i = 0;
		all_ate = 0;
		while(i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&philo[i].philo);
			if (get_current_time(philo) - philo[i].last_meat > data->time_to_die)
			{
				pthread_mutex_lock(&data->mutex_end);
				data->end_checker = DEAD;
				pthread_mutex_unlock(&data->mutex_end);
				print_status(philo,"died");
				pthread_mutex_unlock(&philo[i].philo);
				return ;
			}
			if (data->number_of_eat != -1 && philo[i].meal_counter >= data->number_of_eat)
				all_ate++;
			pthread_mutex_unlock(&philo[i].philo);
			i++;
		}
		if (data->number_of_eat != -1 && all_ate == data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->mutex_end);
			data->end_checker = 1;
			pthread_mutex_unlock(&data->mutex_end);
			return;
		}
		usleep(1000);
	}
}
			

static void update_meat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo);
	philo->meal_counter++;
	philo->last_meat = get_current_time(philo);
	pthread_mutex_unlock(&philo->philo);
}

static void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		usleep(200);
	while (1)
	{
		if (check_simulation_end(philo->data) == 1)
		{
			break;
		}
		pthread_mutex_lock(philo->mutex_left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->mutex_right_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		update_meat_philo(philo);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->mutex_left_fork);
		pthread_mutex_unlock(philo->mutex_right_fork);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return(NULL);
}

void	start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	monitor_routine(data, philo);
	while (i < data->number_of_philosophers)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}