/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:26 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_prec_just_num(t_struct *info)
{
	while (info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9')
	{
		info->precision *= 10;
		info->precision += (info->f_t[info->i] - 48);
		info->i++;
	}
	return (info);
}

static t_struct	*ft_num(t_struct *info)
{
	if (info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9')
	{
		ft_prec_just_num(info);
		return (info);
	}
	if (info->f_t[info->i + 1] == '.' && (info->f_t[info->i] >= '0'
				&& info->f_t[info->i] <= '9'))
	{
		while (info->f_t[info->i + 2] >= '0' && info->f_t[info->i + 2] <= '9')
		{
			info->precision *= 10;
			info->precision += (info->f_t[info->i + 2] - 48);
			info->i++;
		}
		info->i = info->i + 2;
		return (info);
	}
	else
	{
		info->i++;
		if (info->convert[6] == '.' &&
				(info->f_t[info->i] < '0' && info->f_t[info->i] > '9'))
			info->i++;
		return (info);
	}
}

static t_struct	*ft_dot(t_struct *info)
{
	info->i++;
	info->precision = 0;
	if (info->f_t[info->i] == 's' || info->f_t[info->i] == 'c'
			|| info->f_t[info->i] == 'd' || info->f_t[info->i] == 'p'
			|| info->f_t[info->i] == 'x' || info->f_t[info->i] == 'X'
			|| info->f_t[info->i] == 'i' || info->f_t[info->i] == 'u')
		ft_parse_specifiers(info);
	(info->convert[0] == '-' && info->f_t[info->i - 1] != '.') ? info->i -= 2 : 0;
	(info->convert[0] != '-' && info->f_t[info->i - 1] != '.') ? info->i -= 1 : 0;
	(info->f_t[info->i] == '*') ? info->precision = info->widht : 0;
	(info->f_t[info->i] == '*') ? info->i++ : 0;
	(info->convert[5] == '*' && info->n == 1) ? info->precision = info->widht : 0;
	if (info->convert[0] != '-' && info->convert[5] == '*' &&
			(info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9'))
	{
		while (info->f_t[info->i - 1] >= '0' && info->f_t[info->i - 1] <= '9')
			info->i--;
		while (info->f_t[info->i] >= '0' && info->f_t[info->i] <= '9')
		{
			info->precision *= 10;
			info->precision += (info->f_t[info->i] - 48);
			info->i++;
		}
	}
	return (info);
}

t_struct			*ft_parse_precision(t_struct *info)
{
	int len;

	len = 0;
	if ((info->convert[6] == '.') || (info->f_t[info->i] == '.'))
	{
		ft_dot(info);
		ft_num(info);
	}
	if (info->precision == 0 && info->widht < 0)
		info->precision = (-1);
	if (info->p == 1)
		info->precision = va_arg(info->arg, int);
	return (info);
}
