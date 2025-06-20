/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:54 by lde-mais          #+#    #+#             */
/*   Updated: 2023/01/09 15:35:15 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	count_dec(unsigned int n)
{
	int	comp;

	comp = 1;
	while (n >= 10)
	{
		n = n / 10;
		comp++;
	}
	return (comp);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		i++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + (nb % 10));
	return (count_dec(nb) + i);
}

int	ft_putnbrunsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + (nb % 10));
	return (count_dec(nb));
}
