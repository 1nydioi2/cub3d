/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:27:29 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/11 12:09:23 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n && s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0')
	{
		c++;
	}
	if (c == n || (s1[c] == '\0' && s2[c] == '\0'))
		return (0);
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	while (i < n)
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		if (s1[i] == '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }
