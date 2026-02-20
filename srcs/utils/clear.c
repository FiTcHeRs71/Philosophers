
#include "../../includes/philo.h"

void	ft_error(char *msg, t_philo *philo)
{
	printf("%s\n", msg);
	(void)philo;
	exit(EXIT_FAILURE);
}