/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:30:40 by relamine          #+#    #+#             */
/*   Updated: 2023/12/09 13:19:28 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long p)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(p, 'x');
	return (count);
}
