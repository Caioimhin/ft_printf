/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_widht.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:46 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_parse_widht(t_struct *info)
{
	if (info->convert[5] == '*')
	{
		info->widht = va_arg(info->arg, int);
		if (info->widht < 0 && info->convert[6] != '.')
		{
			info->widht *= (-1);
			info->convert[0] = '-';
		}
		ft_parse_specifiers(info);
		(info->convert[0] == '-') ? info->i = info->i + 1 : 0;
	}
	else if (info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9')
	{
		if (info->f_t[info->i - 1] == '0' && info->f_t[info->i - 2] == '.')
			return (info);
		while (info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9')
		{
			info->widht *= 10;
			info->widht += (info->f_t[info->i] - 48);
			info->i++;
		}
	}
	if (info->widht < 0 && info->p == 1)
		info->widht *= (-1);
	return (info);
}
