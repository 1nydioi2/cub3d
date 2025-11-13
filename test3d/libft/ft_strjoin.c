/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandoor <tvandoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:56 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/10 14:50:00 by tvandoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*src1;
	char	*src2;
	char	*result;

	src1 = (char *)s1;
	src2 = (char *)s2;
	if (src1 == NULL)
		src1 = "";
	if (src2 == NULL)
		src2 = "";
	if (src1 == NULL && src2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(src1) + ft_strlen(src2) + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	result[0] = '\0';
	ft_strcat(result, src1);
	ft_strcat(result, src2);
	return (result);
}
