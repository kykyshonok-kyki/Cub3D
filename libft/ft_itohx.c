char	ft_itohx(int num, char isup)
{
	if (num >= 0 && num < 10)
		return ('0' + num);
	else if (num > 10 && num < 0)
		return ('0' - num);
	else if (num >= 10 && num < 16)
	{
		if (isup)
			return ('A' + num - 10);
		else
			return ('a' + num - 10);
	}
	else if (num > -16 && num <= -10)
	{
		if (isup)
			return ('A' - num + 10);
		else
			return ('a' - num + 10);
	}
	else
		return (0);
}
