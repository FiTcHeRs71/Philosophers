
#include "includes/philo.h"

void	*increment(void *arg)
{
	t_data *data = (t_data *)arg;

	while (1)
	{
		pthread_mutex_lock(data->mutex);
		if (*(data->value) >= 1000000)
		{
			pthread_mutex_unlock(data->mutex);
			break;
		}
		(*(data->value))++;
		pthread_mutex_unlock(data->mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	locker;
	int				test;
	t_data			data;

	test = 0;
	pthread_mutex_init(&locker, NULL);

	data.value = &test;
	data.mutex = &locker;

	pthread_create(&thread1, NULL, &increment, &data);
	pthread_create(&thread2, NULL, &increment, &data);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&locker);

	printf("test : %d\n", test);

	return (0);
}
