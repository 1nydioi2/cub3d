/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:27:14 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/11 11:05:46 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	u;

	u = 0;
	c = (unsigned char)c;
	while (s[u] != '\0')
		u++;
	if (c == '\0')
		return ((char *)&s[u]);
	while (u >= 0)
	{
		if (s[u] == c)
			return ((char *)&s[u]);
		u--;
	}
	return (NULL);
}
