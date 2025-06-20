/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:18:30 by lde-mais          #+#    #+#             */
/*   Updated: 2023/01/09 15:54:07 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_p(va_list arg)
{
	unsigned long long	tmp;

	tmp = va_arg(arg, unsigned long long);
	if (tmp)
	{
		write(1, "0x", 2);
		return (ft_printadress(tmp) + 2);
	}
	else
		return (write(1, "(nil)", 5));
}

int	ft_format(va_list arg, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(arg, char *)));
	else if (format == 'c')
		return (ft_printchar(va_arg(arg, int)));
	else if (format == '%')
		return (ft_printchar('%'));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF"));
	else if (format == 'u')
		return (ft_putnbrunsigned(va_arg(arg, unsigned int)));
	else if (format == 'p')
		return (ft_print_p(arg));
	else
		return (-1);
}

int	while_str(const char *format, va_list arg)
{
	int			len;
	int			i;
	int			j;
	int			end;

	i = 0;
	len = 0;
	j = 0;
	end = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_format(arg, format[i + 1]);
			i++;
			j += 2;
			end += len;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (i - j + end);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			len;

	va_start(arg, format);
	len = while_str(format, arg);
	if (len == -1)
		return (-1);
	va_end(arg);
	return (len);
}
