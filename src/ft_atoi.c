#include "main.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	long long			sign;

	while (*str && (*str == ' ' || *str == '\n'
			|| *str == '\t' || *str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str && (*str >= '0' && *str <= '9') && result <= __INT64_MAX__)
		result = result * 10 + (*str++ - '0');
	if (result > __INT64_MAX__ && sign == 1)
		return (-1);
	if (result > __INT64_MAX__ && sign == -1)
		return (0);
	return (result * sign);
}
