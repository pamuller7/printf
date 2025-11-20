/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:46:26 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/20 11:22:34 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg_int(va_list argptr, char c)
{
	int	pos;
	int	char_written;

	char_written = 0;
	pos = va_arg(argptr, int);
	if (c == 'd' || c == 'i')
		char_written = ft_putnbr_base(pos, "0123456789");
	return (char_written);
}

static int	print_arg_unsigned(va_list argptr, char c)
{
	unsigned int		u_i;
	unsigned long int	u_l_i;
	int					char_written;

	char_written = 0;
	if (c == 'u' || c == 'x' || c == 'X')
	{
		u_i = va_arg(argptr, unsigned int);
		if (c == 'u')
			char_written = ft_putnbr_base_uli(u_i, "0123456789");
		else if (c == 'x')
			char_written = ft_putnbr_base_uli(u_i, "0123456789abcdef");
		else if (c == 'X')
			char_written = ft_putnbr_base_uli(u_i, "0123456789ABCDEF");
	}
	else if (c == 'p')
	{
		u_l_i = va_arg(argptr, unsigned long int);
		if (!u_l_i)
			return (ft_putstr_fd("(nil)", 1));
		ft_putstr_fd("0x", 1);
		char_written = ft_putnbr_base_uli(u_l_i, "0123456789abcdef") + 2;
	}
	return (char_written);
}

static int	print_arg_char(va_list argptr, char c)
{
	int		pos;
	char	*str;
	int		char_written;

	char_written = 0;
	if (c == 'c')
	{
		pos = va_arg(argptr, int);
		char_written = ft_putchar_fd(pos, 1);
	}
	else if (c == 's')
	{
		str = va_arg(argptr, char *);
		char_written = ft_putstr_fd(str, 1);
	}
	else if (c == '%')
		char_written = ft_putchar_fd(c, 1);
	return (char_written);
}

static int	check_next_attribute(va_list argptr, char c)
{
	if (c == 'c' || c == 's' || c == '%')
		return (print_arg_char(argptr, c));
	else if (c == 'd' || c == 'i')
		return (print_arg_int(argptr, c));
	else if (c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (print_arg_unsigned(argptr, c));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		char_written;
	int		check;

	char_written = 0;
	va_start(argptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			check = check_next_attribute(argptr, *(s));
			char_written += check;
			if (check == -1)
				return (-1);
		}
		else
			char_written += ft_putchar_fd(*s, 1);
		s++;
	}
	va_end(argptr);
	return (char_written);
}
