/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:25 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_obtain_ten(uintmax_t num)
{
	int ten;

	ten = 1;
	while ((num /= 10) > 0)
		ten++;
	return (ten);
}

static t_struct	*ft_do_u(t_struct *info, uintmax_t num, int num_width)
{
	int			not_blank;
	int			left;

	not_blank = num_width;
	left = 0;
	(info->convert[0] == '-') ? left = 1 : 0;
	if (num_width <= info->precision)
		not_blank = info->precision;
	info->len += (not_blank <= info->widht) ? info->widht : not_blank;
	if (!left)
		ft_display_widht(info, ' ', info->widht - not_blank, 0);
	ft_display_widht(info, '0', info->precision - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (left)
		ft_display_widht(info, ' ', info->widht - not_blank, 0);
	return (info);
}

static t_struct	*ft_space(t_struct *info)
{
	if (info->convert[0] != '-' && info->widht == 0)
		ft_display_widht(info, ' ', info->widht, 1);
	if (info->convert[0] != '-' && info->widht != 0 && info->precision > 0)
	{
		ft_display_widht(info, ' ', info->widht - 1, 1);
		ft_putchar('0');
	}
	if (info->convert[0] == '-' && info->widht != 0 && info->precision == -1)
	{
		ft_putchar('0');
		ft_display_widht(info, ' ', info->widht - 1, 1);
		return (info);
	}
	if (info->convert[0] == '-')
	{
		info->i--;
		ft_display_widht(info, ' ', info->widht, 1);
	}
	if (info->precision == 0 && info->widht > 0 && info->convert[0] != '-')
	{
		ft_display_widht(info, ' ', info->widht, 0);
		return (info);
	}
	return (info);
}

t_struct			*ft_display_u(t_struct *info)
{
	uintmax_t	num;
	int			num_width;

	num = (unsigned int)va_arg(info->arg, unsigned int);
	if (num == 0 && info->precision == -1 && info->convert[6] != '.' &&
		info->widht <= 0)
	{
		ft_putchar('0');
		return (info);
	}
	num_width = ft_obtain_ten(num);
	if ((num == 0 && info->precision == -1 && info->widht <= 0) ||
		(num == 0 && info->precision == 0))
	{
		if (info->f_t[info->i - 1] == 'u' && info->convert[0] == '\0'
			&& info->convert[3] == '\0')
			info->i--;
		(info->f_t[info->i] == 'u' && info->convert[0] == '-') ? info->i++ : 0;
		ft_space(info);
		return (info);
	}
	if (info->convert[3] == '0' && info->precision == -1 && !info->convert[0])
		info->precision = info->widht;
	ft_do_u(info, num, num_width);
	return (info);
}
