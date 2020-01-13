/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:10 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	t_stc *inf;

	if (!(inf = (t_stc*)malloc(sizeof(t_stc))))
		return (-1);
	inf->fmt = fmt;
	inf = ft_initialize(inf);
	if (fmt)
	{
		va_start(inf->arg, fmt);
		inf->len = ft_parsers(inf);
		va_end(inf->arg);
	}
	free(inf);
	return (inf->len);
}
