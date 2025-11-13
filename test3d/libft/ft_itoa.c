/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:38:16 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:41:51 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		l = 1;
	while (nb)
	{
		l++;
		nb /= 10;
	}
	return (l);
}

static char	*my_itoa(long n, char *ret, int p, int len)
{
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		ret[p] = (n % 10) + '0';
		p--;
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		p;
	int		len;
	long	nb;

	ret = NULL;
	nb = (long)n;
	len = intlen(n);
	p = len - 1;
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	my_itoa(nb, ret, p, len);
	return (ret);
}
