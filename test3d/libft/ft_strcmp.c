/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandoor <tvandoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:30:00 by tvandoor          #+#    #+#             */
/*   Updated: 2025/10/10 14:34:19 by tvandoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0')
	{
		c++;
	}
	if (s1[c] == '\0' && s2[c] == '\0')
		return (0);
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
