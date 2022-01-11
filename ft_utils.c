/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/01/12 00:17:23 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int size)
{
	write(1, &c, 1);
	size++;
	return (size);
}

int	ft_putstr(char *s, int size)
{
	if (s)
		while (*s)
			size = ft_putchar(*s++, size);
	else
		size = ft_putstr("(null)", size);
	return (size);
}

int	ft_putnbr(int n, int size)
{
	if (n == -2147483648)
		size = ft_putstr("-2147483648", size);
	else
	{
		if (n < 0)
		{
			n *= -1;
			size = ft_putchar('-', size);
		}
		if (n > 9)
		{
			size = ft_putnbr(n / 10, size);
			size = ft_putnbr(n % 10, size);
		}
		else
			size = ft_putchar(n + 48, size);
	}
	return (size);
}

int	ft_putunbr(unsigned int n, int size)
{
	if (n > 9)
	{
		size = ft_putunbr(n / 10, size);
		size = ft_putunbr(n % 10, size);
	}
	else
		size = ft_putchar(n + 48, size);
	return (size);
}

int	ft_puthexa(unsigned long n, char *base, int size)
{
	if (n >= 16)
		size = ft_puthexa(n / 16, base, size);
	size = ft_putchar(base[n % 16], size);
	return (size);
}
