/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_basics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:32 by kparis            #+#    #+#             */
/*   Updated: 2019/11/06 13:07:00 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_basics(char c, va_list va)
{
	char *res;

	if (c == 'd' || c == 'i')
		res = ft_process_d(va_arg(va, int));
	else if (c == 'u')
		res = ft_process_u(va_arg(va, unsigned int));
	else if (c == 'c')
		res = ft_process_c((char)va_arg(va, int));
	else if (c == 'x')
		res = ft_process_x(va_arg(va, int));
	else if (c == 'X')
		res = ft_process_bigx(va_arg(va, int));
	else if (c == 's')
		res = ft_process_s(va_arg(va, char *));
	else if (c == 'p')
		res = ft_process_p(va_arg(va, void *));
	else if (c == '%')
		res = ft_process_percent();
	else
		res = 0;
	return (res);
}
