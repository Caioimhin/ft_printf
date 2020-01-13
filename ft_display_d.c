/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:19:58 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int		ft_obtain_ten(intmax_t num)
{
	int ten;

	if (num < 0)
		num *= -1;
	ten = 1;
	while ((num /= 10) > 0)
		ten++;
	return (ten);
}

static char		ft_placesign(int is_negative)
{
	if (is_negative)
		return ('-');
	return ('\0');
}

static t_struct	*ft_displayzero(t_struct *info, int sign_place, int num_width)
{
	if (info->convert[3] == '0' && sign_place && (info->precision < info->widht))
	{
		ft_display_widht(info, '0', info->precision - num_width, 0);
		return (info);
	}
	if (info->convert[3] == '0' && sign_place && (info->precision > info->widht))
	{
		ft_display_widht(info, '0', info->precision - num_width, 0);
		return (info);
	}
	if (info->convert[3] == '0' && sign_place && info->precision == info->widht)
	{
		ft_display_widht(info, '0', info->precision - num_width - 1, 0);
		return (info);
	}
	if (info->convert[3] == '0' && !sign_place)
	{
		ft_display_widht(info, '0', info->precision - num_width, 0);
		return (info);
	}
	else
		ft_display_widht(info, '0', info->precision - num_width, 0);
	return (info);
}

static t_struct	*ft_do_d(t_struct *info, intmax_t num, int num_width, int left)
{
	int			not_blank;
	char		sign_place;
	int			negative;

	negative = (num < 0) ? 1 : 0;
	num *= (negative && num != (-2147483648 - 1)) ? -1 : 1;
	sign_place = ft_placesign(negative);
	not_blank = num_width;
	if (num_width <= info->precision && info->precision >= 0)
		not_blank = info->precision;
	sign_place ? not_blank++ : 0;
	info->len += (not_blank <= info->widht) ? info->widht : not_blank;
	if (info->convert[5] == '*' && info->convert[6] == '.' && info->precision == 0)
		ft_prec_and_width(info, num, sign_place);
	if (info->m == 1)
		return (info);
	(!left) ? ft_display_widht(info, ' ', info->widht - not_blank, 0) : 0;
	(sign_place) ? write(1, &sign_place, 1) : 0;
	ft_displayzero(info, sign_place, num_width);
	if (num != (-2147483648 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((info->len += 9) > 0)
		write(1, "2147483648", 10);
	(left) ? ft_display_widht(info, ' ', info->widht - not_blank, 0) : 0;
	return (info);
}

t_struct			*ft_display_d(t_struct *info)
{
	intmax_t	num;
	int			num_width;
	int			left;

	num = (int)(va_arg(info->arg, int));
	if (num == 0 && info->precision == 0)
	{
		if (info->f_t[info->i - 1] == 'i' || info->f_t[info->i - 1] == 'd')
			info->i--;
		ft_display_widht(info, ' ', info->widht, 1);
		return (info);
	}
	(info->f_t[info->i - 1] == 'i' || info->f_t[info->i - 1] == 'd') ? info->i-- : 0;
	if (((info->precision < 0 && num == 0) && ((info->convert[3] == '0' &&
			info->convert[6] == '.') || (info->convert[6] == '.'))))
	{
		ft_strdup("");
		return (info);
	}
	num_width = ft_obtain_ten(num);
	left = (info->convert[0] == '-') ? 1 : 0;
	if (info->convert[3] == '0' && info->precision == -1 && !info->convert[0])
		info->precision = info->widht;
	ft_do_d(info, num, num_width, left);
	return (info);
}
