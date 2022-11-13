/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:43:24 by mazaroua          #+#    #+#             */
/*   Updated: 2022/11/09 22:43:26 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_length2(unsigned int n)
{
	int	count ;

	count = 0;
	if (n == 0)
		count += 1;
	while (n)
	{
		n = n / 16;
		count += 1;
	}
	return (count);
}

int	ft_puthex(unsigned int i, char xX)
{
	int		len;
	char	*base;

	len = ft_length2(i);
	if (xX == 'x')
		base = "0123456789abcdef";
	if (xX == 'X')
		base = "0123456789ABCDEF";
	if (i < 16)
		ft_putchar(base[i]);
	else if (i >= 16)
	{
		ft_puthex(i / 16, xX);
		ft_puthex(i % 16, xX);
	}
	return (len);
}
