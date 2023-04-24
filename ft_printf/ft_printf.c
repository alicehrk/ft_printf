/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:46:09 by harkim            #+#    #+#             */
/*   Updated: 2023/02/27 19:39:02 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char c, va_list ap, int *error)
{
	if (c == 'c')
		return (ft_put_c((char)va_arg(ap, int), error));
	else if (c == 's')
		return (ft_put_s(va_arg(ap, char *), error));
	else if (c == '%')
		return (ft_put_c('%', error));
	else if (c == 'd' || c == 'i')
		return (ft_put_di(va_arg(ap, int), error));
	else if (c == 'u')
		return (ft_put_u(va_arg(ap, int), error));
	else if (c == 'p')
		return (ft_put_p(va_arg(ap, unsigned long long), error));
	else if (c == 'x')
		return (ft_put_x(va_arg(ap, int), error));
	else if (c == 'X')
		return (ft_put_lx(va_arg(ap, int), error));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		error;

	va_start(ap, format);
	i = -1;
	len = 0;
	error = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			len += check_specifier(format[i], ap, &error);
		}
		else
			len += ft_put_c(format[i], &error);
		if (error == -1)
			return (-1);
	}
	va_end(ap);
	return (len);
}
