/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:24:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:31:12 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d2;
	unsigned char	*src2;
	size_t			p;

	d2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	p = 0;
	while (p < n)
	{
		d2[p] = src2[p];
		p++;
	}
	return ((void *)dest);
}
