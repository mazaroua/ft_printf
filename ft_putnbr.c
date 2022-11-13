/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:43:57 by mazaroua          #+#    #+#             */
/*   Updated: 2022/11/09 22:43:59 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length(int n)
{
	int	count ;

	count = 0;
	if (n < 0 || n == 0)
		count = 1;
	while (n)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_length(n);
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
