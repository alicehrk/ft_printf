/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:45:52 by harkim            #+#    #+#             */
/*   Updated: 2023/02/27 19:39:56 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getlen(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_hex(unsigned long long n, char *base, int *error)
{
	if (n >= 16)
		ft_putnbr_hex((n / 16), base, error);
	if (*error == -1)
		return ;
	ft_put_c(base[n % 16], error);
}

int	ft_put_p(unsigned long long n, int *error)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n == 0)
	{
		ft_put_s("0x0", error);
		return (3);
	}
	ft_put_s("0x", error);
	if (*error == -1)
		return (-1);
	ft_putnbr_hex(n, base, error);
	len = ft_getlen(n) + 2;
	return (len);
}

int	ft_put_x(int n, int *error)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	ft_putnbr_hex((unsigned int)n, base, error);
	len = ft_getlen((unsigned int)n);
	return (len);
}

int	ft_put_lx(int n, int *error)
{
	char	*base;
	int		len;

	base = "0123456789ABCDEF";
	len = 0;
	ft_putnbr_hex((unsigned int)n, base, error);
	len = ft_getlen((unsigned int)n);
	return (len);
}
