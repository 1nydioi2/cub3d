/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:28 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/12 12:01:19 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	tot;

	tab = NULL;
	if (nmemb == 0 || size == 0)
	{
		tab = malloc(0);
		return (tab);
	}
	tot = nmemb * size;
	if (tot / nmemb != size || tot > SIZE_MAX / size)
		return (NULL);
	tab = malloc(tot);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, tot);
	return (tab);
}
