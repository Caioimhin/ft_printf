/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:19:40 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

static t_struct	*ft_percent(t_struct *info)
{
	if (info->convert[3] == '0' && info->precision <= 0 && !info->convert[0])
	{
		info->precision = info->widht;
		info->widht = 0;
	}
	if (info->convert[0] != '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	if (info->convert[3] == '0')
		ft_display_widht(info, '0', info->precision - 1, 1);
	write(1, "%", 1);
	if (info->convert[0] == '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	info->len++;
	return (info);
}

t_struct			*ft_display_(t_struct *info)
{
	if (info->f_t[info->i] == '%')
	{
		ft_percent(info);
		return (info);
	}
	if (info->convert[3] == '0' && info->precision <= 0 && !info->convert[0])
	{
		info->precision = info->widht;
		info->widht = 0;
	}
	if (info->convert[0] != '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	if (info->convert[3] == '0')
		ft_display_widht(info, '0', info->precision - 1, 1);
	write(1, &info->f_copy[info->i], 1);
	if (info->convert[0] == '-')
		ft_display_widht(info, ' ', info->widht - 1, 1);
	info->len++;
	return (info);
}
