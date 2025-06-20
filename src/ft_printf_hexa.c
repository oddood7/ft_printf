/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:34:45 by lde-mais          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:13 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_hex(unsigned long long n)
{
	int	comp;

	comp = 1;
	while (n >= 16)
	{
		n /= 16;
		comp++;
	}
	return (comp);
}

int	ft_printadress(unsigned long long adr)
{
	char	*base;

	base = "0123456789abcdef";
	if (adr >= 16)
	{
		ft_printadress(adr / 16);
		ft_printadress(adr % 16);
	}
	else
		write(1, &base[adr], 1);
	return (count_hex(adr));
}

int	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;

	nb = nbr;
	if (nb < 0)
		nb = (unsigned int)nb;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
		write(1, &base[nb], 1);
	return (count_hex(nb));
}
