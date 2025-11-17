/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamuller <pamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:34:38 by pamuller          #+#    #+#             */
/*   Updated: 2025/11/17 12:03:01 by pamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("txt", O_WRONLY);
	ft_putchar_fd('c', fd);
}*/