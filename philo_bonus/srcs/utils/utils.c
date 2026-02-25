
#include "../../includes/philo_bonus.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long long	get_current_time(t_philo *philo)
{
	struct timeval	current_time;
	long long		time;

	if (gettimeofday(&current_time, NULL) == -1)
		ft_error(TIME_SET, philo, philo->data);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}