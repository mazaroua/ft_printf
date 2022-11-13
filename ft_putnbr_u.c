/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:44:22 by mazaroua          #+#    #+#             */
/*   Updated: 2022/11/09 22:44:24 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length1(unsigned int n)
{
	int	count ;

	count = 0;
	if (n == 0)
		count += 1;
	while (n)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = ft_length1(n);
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
