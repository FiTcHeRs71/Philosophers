
#include "includes/philo.h"


int main(int argc, char **argv)
{
	t_philo	**philo;
	t_data	data;

	philo = ft_calloc(1, sizeof(t_philo **));
	if(argc == 6)
	{
		init_philo(argv, philo, &data);
		printf("check OK");
	}
	else
	{
		ft_error(INSTRUCTION, philo);
	}
	return (0);
}







/*void	*increment(void *arg)
{
	t_data *data = (t_data *)arg;
	int		i = 0;

	while(i < 1000000)
	{
		pthread_mutex_lock(data->mutex);
		i++;
		(*(data->value))++;
		pthread_mutex_unlock(data->mutex);
	}
	printf("%d\n", (*(data->value)));
	return (NULL);
}

int	main(void)
{
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	locker;
	int				i;
	t_data			*data[2];

	i = 0;
	pthread_mutex_init(&locker, NULL);
	
	data[0] = calloc(1 , sizeof(t_data));
	data[1] = calloc(1 , sizeof(t_data));
	data[0]->value = &i;
	data[0]->mutex = &locker;
	data[0]->id = 1;
	data[1]->id = 2;
	data[1]->value = &i;
	data[1]->mutex = &locker;
	
	pthread_create(&thread1, NULL, &increment, data[0]);
	pthread_create(&thread2, NULL, &increment, data[1]);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&locker);

	printf("i : %d\n", i);

	free(data[0]);
	free(data[1]);
	return (0);
}*/
