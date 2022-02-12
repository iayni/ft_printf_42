/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:43:59 by iayni             #+#    #+#             */
/*   Updated: 2022/01/18 02:19:30 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(unsigned long n, char *base, unsigned long b_len)
{
	int	len;

	len = 0;
	if (n < b_len)
		len += write(1, &base[n], 1);
	else
	{
		len += ft_putnbr(n / b_len, base, b_len);
		len += write(1, &base[n % b_len], 1);
	}
	return (len);
}

int	ft_put_any_number(long num, char *base, unsigned long b_len)
{
	int	len;

	len = 0;
	if (num < 0L)
	{
		len += write(1, "-", 1);
		num = num * -1;
	}
	return (len + ft_putnbr(num, base, b_len));
}
