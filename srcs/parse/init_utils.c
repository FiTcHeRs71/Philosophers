
#include "../../includes/philo.h"

int	ft_isdigit(int c)
{
	if (!c)
	{
		return (0);
	}
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool	check_arg_is_digit(char *str)
{
	size_t		i;
	long long	number;
	int			s;

	i = 0;
	number = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		number = (number * 10) + (str[i] - '0');
		if ((s == 1 && number > INT_MAX) || (s == -1 && number > 2147483648))
			return (false);
		i++;
	}
	return (true);
}
// chekcer les calloc avec ft_error
int	ft_atoi(const char *str)
{
	int	ngps;
	int	result;

	ngps = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			ngps *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = ((result * 10) + (*str - 48));
		str++;
	}
	return (result * ngps);
}