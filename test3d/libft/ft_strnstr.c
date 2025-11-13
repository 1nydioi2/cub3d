/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:28:34 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:33:03 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t l)
{
	char	*s;
	char	*t;
	size_t	u;
	size_t	v;

	s = (char *)str;
	t = (char *)to_find;
	u = 0;
	v = 0;
	if (t[0] == '\0')
		return (s);
	while (s[u] != '\0' && u < l)
	{
		v = 0;
		while (s[u + v] && t[v] && s[u + v] == t[v] && (u + v) < l)
			v++;
		if (t[v] == '\0')
			return (&s[u]);
		u++;
	}
	return (0);
}
