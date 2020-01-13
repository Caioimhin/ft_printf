/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_displays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:55 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printlen(t_stc *inf)
{
	*va_arg(inf->arg, int *) = inf->len;
}

t_stc			*ft_send_displays(t_stc *inf)
{
	char	*flag;

	flag = &inf->specifiers_flags;
	if (*flag == 'd' || *flag == 'i')
		ft_display_d(inf);
	else if (*flag == 'c')
		ft_display_c(inf);
	else if (*flag == 's')
		ft_display_s(inf);
	else if (*flag == 'u')
		ft_display_u(inf);
	else if (*flag == 'x' || *flag == 'X')
		ft_display_x(inf);
	else if (*flag == 'n')
		ft_printlen(inf);
	else if (*flag == 'p')
		ft_display_p(inf);
	else
		ft_display_(inf);
	return (inf);
}
