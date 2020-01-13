/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:27:03 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_direct_dot(t_struct *info)
{
	ft_parse_specifiers(info);
	ft_send_displays(info);
	return (info);
}

static t_struct	*ft_sparks(t_struct *info)
{
	if (info->f_t[info->i + 1] == '.' && info->f_t[info->i] == '*')
	{
		info->j = 1;
		ft_parse_converts(info);
		ft_parse_widht(info);
		ft_parse_precision(info);
		if ((info->f_t[info->i - 1] == 'd' || info->f_t[info->i - 1] == 'i' ||
			info->f_t[info->i - 1] == 'u' || info->f_t[info->i - 1] == 'x' ||
			info->f_t[info->i - 1] == 'X' || info->f_t[info->i - 1] == 'p' ||
			info->f_t[info->i - 1] == 's') && info->precision > 0)
		{
			info->i--;
			ft_display_widht(info, ' ', info->widht - info->precision, 1);
		}
		ft_parse_specifiers(info);
		ft_send_displays(info);
	}
	return (info);
}

static t_struct	*ft_jzero(t_struct *info)
{
	ft_parse_converts(info);
	ft_parse_widht(info);
	ft_parse_precision(info);
	ft_parse_specifiers(info);
	ft_send_displays(info);
	return (info);
}

int				ft_treatments(t_struct *info)
{
	info->i++;
	if (info->f_t[info->i] == '.' && info->f_t[info->i + 1] != '*')
	{
		ft_parse_converts(info);
		if (info->f_t[info->i] == 'd' || info->f_t[info->i] == 'i' ||
			info->f_t[info->i] == 'u' || info->f_t[info->i] == 'x' ||
			info->f_t[info->i] == 'X' || info->f_t[info->i] == 'p')
		{
			ft_direct_dot(info);
			return (info->len);
		}
		ft_parse_precision(info);
		ft_parse_specifiers(info);
		ft_send_displays(info);
		return (info->len);
	}
	ft_sparks(info);
	if (info->j == 0)
		ft_jzero(info);
	return (info->len);
}
