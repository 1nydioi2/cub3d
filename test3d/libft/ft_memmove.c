/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:24:52 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:32:05 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			p;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	p = 0;
	if (!dest && !src)
		return (NULL);
	if (d < s || d >= s + n)
	{
		while (p < n)
		{
			d[p] = s[p];
			p++;
		}
		return (dest);
	}
	p = n;
	while (p > 0)
	{
		p--;
		d[p] = s[p];
	}
	return (dest);
}
