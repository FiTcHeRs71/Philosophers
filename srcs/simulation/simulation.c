
#include "../../includes/philo.h"

static bool	check_number_of_meat(t_philo *philo)
{
	if (philo->meal_counter == philo->data->number_of_eat)
	{
		print_status(philo, "CHECKER FIN DE REPAS !");
		return (true);
	}
	return (false);
}


static bool	check_dead_philo(t_philo *philo)
{
	if (philo->last_meat == 0)
	{
		if (get_current_time(philo) > philo->data->start_time > philo->data->time_to_die)
		{
			print_status(philo, "is dead");
			return (true);
		}
		else 
		{
			return (false);
		}
	}
	if (get_current_time(philo) - philo->last_meat > philo->data->time_to_die)
	{
		print_status(philo, "is dead");
		return (true);
	}
	return (false);
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
		if (check_dead_philo(philo) || check_number_of_meat(philo))
			break;
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
	while (i < data->number_of_philosophers)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}