/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:26:30 by mlouati           #+#    #+#             */
/*   Updated: 2024/07/29 00:38:06 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else if (n >= 0)
		{
			if (n >= 0 && n <= 9)
				ft_putchar_fd(n + 48, fd);
			else
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putchar_fd(n % 10 + '0', fd);
			}
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
	}
}
