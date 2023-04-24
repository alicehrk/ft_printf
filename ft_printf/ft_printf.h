/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:46:30 by harkim            #+#    #+#             */
/*   Updated: 2023/02/27 18:36:20 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	check_specifier(char c, va_list ap, int *error);
int	ft_printf(const char *format, ...);
int	ft_put_c(char c, int *error);
int	ft_put_s(char *s, int *error);
int	ft_put_di(int n, int *error);
int	ft_put_u(int n, int *error);
int	ft_put_p(unsigned long long n, int *error);
int	ft_put_x(int n, int *error);
int	ft_put_lx(int n, int *error);

#endif
