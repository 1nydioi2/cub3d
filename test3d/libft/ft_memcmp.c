/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:28:00 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/03 11:01:01 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*n1 = (const unsigned char *)p1;
	const unsigned char	*n2 = (const unsigned char *)p2;
	size_t				u;

	u = 0;
	{
		while (u < size && n1[u] == n2[u])
			u++;
		if (u == size)
			return (0);
		return (n1[u] - n2[u]);
	}
}
