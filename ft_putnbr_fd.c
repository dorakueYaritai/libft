/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:27:03 by kakiba            #+#    #+#             */
/*   Updated: 2022/07/06 12:57:44 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c;

	i = 1;
	while (n / i < 10)
		i = i * 10;
	while (i > 1)
	{
		c = n / i + '0';
		write(fd, &c, 1);
		n = n % i;
		i = i / 10;
	}
}
