/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:42:52 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/17 12:42:47 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s);

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write (fd, s, ft_strlen(s)));
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	fd;

// 	fd = open(NULL, O_WRONLY);
// 	ft_putstr_fd("Bonjour a tous", fd);
// }