/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_csdiu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:30:36 by harkim            #+#    #+#             */
/*   Updated: 2023/02/27 19:39:40 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(char c, int *error)
{
	if (write(1, &c, 1) < 0)
		*error = -1;
	return (1);
}

int	ft_put_s(char *s, int *error)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			*error = -1;
		return (6);
	}
	while (s[i])
	{
		ft_put_c(s[i], error);
		if (*error == -1)
			return (-1);
		i++;
	}
	return (i);
}

static void	ft_putnbr(long n, int *error)
{
	if (n > 9)
		ft_putnbr(n / 10, error);
	if (*error == -1)
		return ;
	ft_put_c(n % 10 + '0', error);
}

int	ft_put_di(int n, int *error)
{
	long long	value;
	long long	temp_value;
	int			len;

	value = (long long)n;
	temp_value = value;
	len = 0;
	if (temp_value == 0)
		len = 1;
	while (temp_value != 0)
	{
		temp_value /= 10;
		len++;
	}
	if (value < 0)
	{
		ft_put_c('-', error);
		if (*error == -1)
			return (-1);
		len += 1;
		value *= -1;
	}
	ft_putnbr(value, error);
	return (len);
}

int	ft_put_u(int n, int *error)
{
	unsigned int	num;
	unsigned int	temp_num;
	int				len;

	num = (unsigned int)n;
	temp_num = num;
	len = 0;
	if (temp_num == 0)
		len = 1;
	while (temp_num != 0)
	{
		temp_num /= 10;
		len++;
	}
	ft_putnbr(num, error);
	return (len);
}
