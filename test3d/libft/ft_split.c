/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:46:57 by jutocche          #+#    #+#             */
/*   Updated: 2025/08/15 09:34:03 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_ptr_numb(char const *src, char c)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != c)
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ret2(char const *src, char c, int *index)
{
	int		j;
	int		start;
	char	*x;

	j = 0;
	start = 0;
	x = NULL;
	while (src[*index] == c)
		(*index)++;
	start = *index;
	while (src[*index] != '\0' && src[*index] != c)
		(*index)++;
	x = malloc(sizeof(char) * (*index - start + 1));
	if (x == NULL)
		return (NULL);
	while (start < *index)
	{
		x[j] = src[start];
		j++;
		start++;
	}
	x[j] = '\0';
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ptr;
	int		p;
	int		i;

	p = 0;
	i = 0;
	ret = NULL;
	if (s == NULL || c < 32 || c > 126)
		return (NULL);
	else
	{
		ptr = my_ptr_numb(s, c);
		ret = (char **)malloc(sizeof(char *) * (ptr + 1));
		if (ret == NULL)
			return (NULL);
		while (p < ptr)
		{
			ret[p] = ret2(s, c, &i);
			p++;
		}
		ret[ptr] = NULL;
		return (ret);
	}
}
