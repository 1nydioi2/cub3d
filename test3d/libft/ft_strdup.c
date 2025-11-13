/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:39 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/11 11:15:00 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*src1;
	char	*tab;

	if (!src)
		return (NULL);
	src1 = (char *)src;
	tab = NULL;
	if (src != NULL)
		tab = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tab == NULL)
		return (NULL);
	ft_strcpy(tab, src1);
	return (tab);
}
