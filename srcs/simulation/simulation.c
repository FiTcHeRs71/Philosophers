
#include "../../includes/philo.h"

static void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	printf("Philosophe %d est à table !\n", philo->id_philo);
	return(NULL);
}

void	start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}