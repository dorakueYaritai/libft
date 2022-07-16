/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:27:03 by kakiba            #+#    #+#             */
/*   Updated: 2022/07/12 00:06:55 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		buf;
	int		i;
	char	c;

	buf = n;
	i = 1;
	if (n == -2147483648)
		write (fd, "-2147483648", 12);
	else if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	while (n >= 10)
	{
		n /= 10;
		i *= 10;
	}
	while (i >= 1)
	{
		c = buf / i + '0';
		write (fd, &c, 1);
		buf %= i;
		i /= 10;
	}
}
