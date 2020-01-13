/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_displays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:55 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printlen(t_struct *info)
{
	*va_arg(info->arg, int *) = info->len;
}

t_struct			*ft_send_displays(t_struct *info)
{
	char	*flag;

	flag = &info->specifiers_flags;
	if (*flag == 'd' || *flag == 'i')
		ft_display_d(info);
	else if (*flag == 'c')
		ft_display_c(info);
	else if (*flag == 's')
		ft_display_s(info);
	else if (*flag == 'u')
		ft_display_u(info);
	else if (*flag == 'x' || *flag == 'X')
		ft_display_x(info);
	else if (*flag == 'n')
		ft_printlen(info);
	else if (*flag == 'p')
		ft_display_p(info);
	else
		ft_display_(info);
	return (info);
}
