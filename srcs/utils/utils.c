
#include "../../includes/philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (count > SIZE_MAX / size)
	{
		return (NULL);
	}
	temp = malloc(count * size);
	if (!temp)
	{
		return (NULL);
	}
	memset(temp, 0, count * size);
	return (temp);
}
