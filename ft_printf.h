/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:10:13 by iayni             #+#    #+#             */
/*   Updated: 2022/01/18 17:27:29 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s, int *len);
int		ft_printf(const char *str, ...);
void	ft_putchar(int c, int *len);
int		ft_putnbr(unsigned long n, char *base, unsigned long b_len);
int		ft_put_any_number(long num, char *base, unsigned long b_len);

#endif