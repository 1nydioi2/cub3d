/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:04:48 by jutocche          #+#    #+#             */
/*   Updated: 2025/05/19 11:15:21 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_base(void *ptr, char *base)
{
	uintptr_t	num_adress;
	int			count;

	num_adress = (uintptr_t)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base_ptr(num_adress, base);
	return (count);
}

int	ft_putnbr_base_ptr(long unsigned int nbr, char *base)
{
	int					count;
	long unsigned int	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		count += ft_putnbr_base_ptr(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}
