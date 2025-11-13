/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:27:10 by jutocche          #+#    #+#             */
/*   Updated: 2025/05/19 11:15:31 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_char;

	i = 0;
	print_char = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print_char += format_management(format, args, i);
		}
		else
			print_char += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_char);
}

int	format_management(const char *format, va_list args, int i)
{
	int	fm;

	fm = 0;
	if (format[i] == 'c')
		fm += ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		fm += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		fm += ft_ptr_base(va_arg(args, void *), "0123456789abcdef");
	else if (format[i] == 'd' || format[i] == 'i')
		fm += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		fm += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (format[i] == 'x')
		fm += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format[i] == 'X')
		fm += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format[i] == '%')
		fm += ft_putchar('%');
	return (fm);
}
