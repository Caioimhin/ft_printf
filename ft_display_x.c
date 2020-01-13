/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:53 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:58:52 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void			ft_print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	ft_get_num(t_struct *info)
{
	uintmax_t	num;

	num = (unsigned int)(va_arg(info->arg, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static t_struct		*ft_do_x(t_struct *info, uintmax_t num, char *str)
{
	int			n_b;
	int			n_w;
	int			left;

	left = 0;
	(info->convert[0] == '-') ? left = 1 : 0;
	if ((n_w = ft_strlen(str)) && info->convert[4] == '#' && num &&
			info->convert[3] == '0' && info->widht)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && info->convert[4] == '#' && num)
	{
		info->widht -= 2;
		info->len += 2;
	}
	n_b = (n_w <= info->precision && info->precision > 0) ? info->precision : n_w;
	info->len += (n_b <= info->widht) ? info->widht : n_b;
	if (!left)
		ft_display_widht(info, ' ', info->widht - n_b, 0);
	ft_print_leading_zero(num, info->convert[4], info->specifiers_flags);
	ft_display_widht(info, '0', info->precision - n_w, 0);
	ft_putstr(str);
	if (left)
		ft_display_widht(info, ' ', info->widht - n_b, 0);
	return (info);
}

static t_struct		*ft_numzero(t_struct *info, int num)
{
	if (num == 0 && info->precision == 0)
	{
		if (info->f_t[info->i - 1] == 'x' || info->f_t[info->i - 1] == 'X')
			info->i--;
		ft_display_widht(info, ' ', info->widht, 1);
		info->k = 1;
		return (info);
	}
	else
		return (info);
}

t_struct			*ft_display_x(t_struct *info)
{
	char		*str;
	char		c;
	uintmax_t	num;

	num = ft_get_num(info);
	ft_numzero(info, num);
	if (info->k == 1)
		return (info);
	c = 'a';
	(info->specifiers_flags == 'X') ? c = 'A' : 0;
	str = ft_itoa_base(num, 16, c);
	(info->f_t[info->i - 1] == 'x' || info->f_t[info->i - 1] == 'X') ? info->i-- : 0;
	if (((info->precision < 0 && num == 0) && ((info->convert[3] == '0' &&
			info->convert[6] == '.') || (info->convert[6] == '.'))))
	{
		ft_strdup("");
		return (info);
	}
	if (info->convert[3] == '0' && info->precision == -1 && !info->convert[0])
		info->precision = info->widht;
	ft_do_x(info, num, str);
	(num == 0 || num == '\0') ? info->len++ : 0;
	free(str);
	return (info);
}
