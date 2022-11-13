/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:43:12 by mazaroua          #+#    #+#             */
/*   Updated: 2022/11/13 16:42:01 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list p, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(p, int));
	else if (c == 's')
		len = ft_putstr(va_arg(p, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(p, int));
	else if (c == 'p')
		len = ft_putadress(va_arg(p, unsigned long));
	else if (c == 'u')
		len = ft_putnbr_u(va_arg(p, unsigned int));
	else if (c == 'x')
		len = ft_puthex(va_arg(p, unsigned int), 'x');
	else if (c == 'X')
		len = ft_puthex(va_arg(p, unsigned int), 'X');
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	p;

	i = 0;
	len = 0;
	va_start(p, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check_format(p, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(p);
	return (len);
}
