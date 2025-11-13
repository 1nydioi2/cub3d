/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:28:16 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 16:38:43 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	o;
	size_t			u;

	p = (unsigned char *) s;
	o = (unsigned char) c;
	u = 0;
	while (u < n)
	{
		if (p[u] == o)
			return ((void *)&p[u]);
		u++;
	}
	return (NULL);
}
