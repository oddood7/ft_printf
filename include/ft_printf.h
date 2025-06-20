/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:22:35 by lde-mais          #+#    #+#             */
/*   Updated: 2023/01/09 15:32:47 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

void					ft_putchar(char c);
int						ft_printchar(char c);
int						ft_printstr(char *str);
int						count_dec(unsigned int n);
int						ft_putnbr(int nb);
int						ft_putnbrunsigned(unsigned int nb);
int						count_hex(unsigned long long n);
int						ft_printadress(unsigned long long adr);
int						ft_putnbr_base(int nbr, char *base);
int						ft_printf(const char *format, ...);
int						ft_print_p(va_list arg);
int						ft_format(va_list arg, const char format);

#endif
