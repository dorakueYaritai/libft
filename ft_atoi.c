/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:51:25 by kakiba            #+#    #+#             */
/*   Updated: 2022/07/17 20:57:07 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_strtol(const char *nptr, char **endptr, int base);
int			start_check(const char *nptr, int *base, int *judge_minus);
int			index_check(char c, int base);

int	ft_atoi(const char *str)
{
	long int	a;

	a = ft_strtol (str, (char **) NULL, 10);
	return ((int)(a));
}

long int	ft_strtol(const char *nptr, char **endptr, int base)
{
	int					i;
	int					judge_minus;
	unsigned int long	sum;

	sum = 0;
	judge_minus = 1;
	i = start_check(nptr, &base, &judge_minus);
	while (index_check(nptr[i], base) != -1)
	{
	//	printf("%d\n", index_check(nptr[i], base));
		if ((sum <= (unsigned int long)(LONG_MAX - index_check(nptr[i], base)) / base))
		{
			sum = sum * base + index_check(nptr[i++], base);
//			printf("%llu\n", sum);
		}
		else if (judge_minus == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	if (endptr != NULL)
		*endptr = (char *)&nptr[i];
	return (judge_minus * sum);
}

int	start_check(const char *nptr, int *base, int *judge_minus)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
			*judge_minus = -1;
			i++;
	}
	else if (nptr[i] == '+')
		i++;
	if ((*base == 0 || *base == 16) && nptr[i] == '0'
		&& (nptr[i + 1] == ('x') || nptr[i + 1] == ('X')))
	{
		i = i + 2;
		*base = 16;
	}
	else if ((*base == 0 || *base == 8) && nptr[i] == '0')
	{
		i++;
		*base = 8;
	}
	return (i);
}

int	index_check(char c, int base)
{
	char	*str;

	str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	c = ft_toupper(c);
	if (ft_strchr(str, c) == NULL)
		return (-1);
	else if (ft_strchr(str, c) - str < base)
		return (ft_strchr(str, c) - str);
	else
		return (-1);
}
/*
int main(void)
{
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", ft_strtol("52", NULL, 10));
	printf("%ld\n", ft_strtol("18446744073709551616", NULL, 10));
	printf("%ld\n", strtol("18446744073709551616", NULL, 10));
//	printf("%d\n", atoi("52"));
//	printf("%d\n", atoi("52"));
//	printf("%d\n", atoi("18446744073709551616"));
	printf("%d\n", atoi("18446744073709551617"));
	printf("%d\n", ft_atoi("18446744073709551617"));
	printf("%d\n", atoi("446744073709551618"));

 	return 0;
 }*/
