/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:40:59 by mazaroua          #+#    #+#             */
/*   Updated: 2022/11/09 23:41:02 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned long i)
{
	int	count;

	count = 0;
	while (i)
	{
		i = i / 16;
		count += 1;
	}
	return (count);
}

int	ft_putadress(unsigned long i)
{
	int		len;
	int		j;
	char	*adress;

	len = ft_len(i);
	j = 0;
	if (i == 0)
		return (ft_putstr("0x0"));
	adress = malloc(sizeof(char) * (len + 1));
	if (!adress)
		return (0);
	adress[len--] = '\0';
	while (i > 0)
	{
		adress[len--] = "0123456789abcdef"[i % 16];
		i = i / 16;
	}
	ft_putstr("0x");
	while (adress[j])
		write(1, &adress[j++], 1);
	free(adress);
	return (j + 2);
}
