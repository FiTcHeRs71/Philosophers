
#include "../../includes/philo.h"

void	ft_error(char *msg, t_data *data)
{
	printf("%s\n", msg);
	data->id = 0;
}