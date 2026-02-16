
#include "includes/philo.h"

void	*increment(void *test)
{
	while ((long long)test < 100)
	{
		printf("%lli..", (long long)test);
		test++;
	}
	return (test);
}

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	void	*test = 0;
	int v;
	int u;

	v = pthread_create(&thread1, NULL, increment, test);
	u = pthread_create(&thread2, NULL, increment, test);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("test : %lli\n", (long long)test);
	printf("retour de create 1 %i\n", v);
	printf("retour de create 2 %i\n", u);
	return (0);
}
