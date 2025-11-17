/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:41:32 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/17 12:57:03 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	base_chng(long nb, char *base, int len, int *count)
{
	if (nb >= len && *count != -1)
	{
		*count = *count + 1;
		base_chng(nb / len, base, len, count);
	}
	if (*count == -1 || ft_putchar_fd(base[nb % len], 1) == -1)
		*count = -1;
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		count;
	int		lenbase;
	long	nb;

	count = 1;
	nb = nbr;
	lenbase = ft_strlen(base);
	if (nb < 0)
	{
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	base_chng(nb, base, lenbase, &count);
	return (count);
}

static void	base_chng_uli(unsigned long nb, char *base, int *count)
{
	unsigned long int	len;

	len = ft_strlen(base);
	if (nb >= len && *count != -1)
	{
		*count = *count + 1;
		base_chng(nb / len, base, len, count);
	}
	if (*count == -1 || ft_putchar_fd(base[nb % len], 1) == -1)
		*count = -1;
}

int	ft_putnbr_base_uli(unsigned long int nbr, char *base)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
		nbr = -nbr;
		count++;
	}
	base_chng_uli(nbr, base, &count);
	return (count);
}
