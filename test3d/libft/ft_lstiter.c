/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:09:13 by jutocche          #+#    #+#             */
/*   Updated: 2025/04/10 16:37:42 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		next = lst->next;
		f(lst->content);
		lst = next;
	}
}
