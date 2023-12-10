/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 06:48:21 by relamine          #+#    #+#             */
/*   Updated: 2023/12/09 13:24:09 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int sp)
{
	int		count;
	char	*hex;

	count = 0;
	if (sp == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_putnbr_hex(n / 16, sp);
		count += ft_putnbr_hex(n % 16, sp);
	}
	else
		return (ft_putchar(hex[n]));
	return (count);
}
