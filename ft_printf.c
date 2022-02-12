/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:27:48 by iayni             #+#    #+#             */
/*   Updated: 2022/01/18 17:27:27 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_checker(const char s, va_list lista)
{
	int	len;

	len = 0;
	if (s == '%')
		ft_putchar ('%', &len);
	if (s == 'c')
		ft_putchar (va_arg(lista, int), &len);
	if (s == 's')
		ft_putstr (va_arg(lista, char *), &len);
	if (s == 'd' || s == 'i')
		len += ft_put_any_number (va_arg(lista, int), "0123456789", 10);
	if (s == 'u')
		len += ft_putnbr (va_arg(lista, unsigned int), "0123456789", 10);
	if (s == 'x')
		len += ft_putnbr (va_arg(lista, unsigned int), "0123456789abcdef", 16);
	if (s == 'X')
		len += ft_putnbr (va_arg(lista, unsigned int), "0123456789ABCDEF", 16);
	if (s == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putnbr (va_arg(lista, unsigned long), "0123456789abcdef", 16);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	lista;

	i = 0;
	len = 0;
	va_start(lista, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &len);
		if (str[i] == '%')
		{
			len += ft_checker (str[i + 1], lista);
			i++;
		}
		i++;
	}
	va_end(lista);
	return (len);
}
