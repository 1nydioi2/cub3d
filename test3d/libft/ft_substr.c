/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:40:33 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:46:32 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_sub(char *dest, char *src, unsigned int start,
		size_t len)
{
	unsigned int	j;

	j = 0;
	while (j < len && src[start + j])
	{
		dest[j] = src[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	dst = NULL;
	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	else if (len == 0 || start >= i)
	{
		dst = malloc(1);
		if (dst == NULL)
			return (0);
		dst[0] = '\0';
		return (dst);
	}
	else if (start + len > i)
		len = i - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy_sub(dst, (char *)s, start, len);
	return (dst);
}
