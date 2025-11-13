/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:26:44 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/07 17:33:12 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	end_trim(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (!found)
			return (i + 1);
		i--;
	}
	return (0);
}

int	start_trim(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strcpy_trim(char *dest, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	result = NULL;
	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	start = start_trim(s1, set);
	end = end_trim(s1, set);
	if (start >= end)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy_trim(result, s1, start, end);
	return (result);
}
