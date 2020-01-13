/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:37:04 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:45:36 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct			*ft_display_c(t_struct *info)
{
	int		c;

	if (info->f_t[info->i - 1] == 'c')
		info->i--;
	c = (char)va_arg(info->arg, int);
	if (info->convert[3] == '0' && info->convert[0] != '-')
		ft_display_widht(info, '0', info->widht - 1, 1);
	else if (info->convert[0] != '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	ft_putchar(c);
	info->len++;
	if (info->convert[0] == '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	return (info);
}
