int	ft_abs(int value)
{
	if (value < 0)
		return (value *= -1);
	return (value);
}

float	ft_fabs(float value)
{
	if (value < 0)
		return (value *= -1);
	return value;
}
