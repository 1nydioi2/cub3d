/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:43:53 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 15:47:01 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;
	int				len;

	dst = NULL;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i])
	{
		dst[j] = f(i, s[i]);
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
