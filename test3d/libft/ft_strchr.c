/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:27:02 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/11 11:05:30 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	u;

	u = 0;
	c = (unsigned char)c;
	while (s[u] != '\0')
	{
		if (s[u] == c)
			return ((char *)&s[u]);
		u++;
	}
	if (s[u] == c)
		return ((char *)&s[u]);
	return (NULL);
}
