int	ft_atoi(const char *str)
{
	int		res;
	char	sign;

	res = 0;
	sign = 1;
	while (*str == '\r' || *str == '\v' || *str == '\f'
		|| *str == ' ' || *str == '	' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		res = res * 10 + sign * (*str - '0');
		str++;
	}
	return (res);
}
