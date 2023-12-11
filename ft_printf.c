/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:18:05 by relamine          #+#    #+#             */
/*   Updated: 2023/12/10 23:34:58 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_spcifier(int chars, va_list args)
{
	if (chars == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (chars == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (chars == 'p')
		return (ft_pointer(va_arg(args, unsigned long)));
	if (chars == 'd' || chars == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (chars == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (chars == 'x' || chars == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), chars));
	else if (chars == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += format_spcifier(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
