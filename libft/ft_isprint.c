int	ft_isprint(int c)
{
	if ((c >= '\100' && c <= '\176') || (c >= '\40' && c <= '\77'))
		return (c);
	else
		return (0);
}
