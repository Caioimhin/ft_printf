/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:06 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:55:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	ft_get_num(t_struct *info)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(info->arg, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_struct		*ft_do_p(t_struct *info, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	info->len += (not_blank <= info->widht) ? info->widht : not_blank;
	if (!left)
		ft_display_widht(info, ' ', info->widht - not_blank, 0);
	write(1, "0x", 2);
	ft_display_widht(info, '0', (info->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (left)
		ft_display_widht(info, ' ', info->widht - not_blank, 0);
	free(str);
	return (info);
}

static t_struct		*ft_numzero(t_struct *info, uintmax_t num, char *str)
{
	int			num_width;

	num_width = ft_strlen(str) + 2;
	if (num == 0)
	{
		if (info->precision == -1 && info->convert[3] != '0')
			ft_display_widht(info, ' ', (info->widht - num_width), 0);
		if (info->precision >= 0 || (info->precision == -1 &&
			((info->convert[3] == '0') || (info->convert[6] == '.'))))
		{
			if (info->precision == 0)
				ft_display_widht(info, ' ', (info->widht - 2), 0);
			write(1, "0x", 2);
			if (info->precision > 0)
				ft_display_widht(info, '0', info->precision, 0);
			info->l = 1;
			return (info);
		}
		write(1, "0x0", 3);
		info->l = 1;
		return (info);
	}
	return (info);
}

t_struct				*ft_display_p(t_struct *info)
{
	char		*str;
	uintmax_t	num;
	int			left;

	left = 0;
	num = ft_get_num(info);
	str = ft_calloc(ft_strlen(ft_itoa_base(num, 16, 'a')), sizeof(char));
	str = ft_itoa_base(num, 16, 'a');
	if (info->f_t[info->i - 1] == 'p' && info->convert[0] == '\0'
		&& info->convert[3] == '\0')
		info->i--;
	ft_numzero(info, num, str);
	if (info->l == 1)
		return (info);
	if (info->convert[0] == '-')
		left = 1;
	if (info->convert[3] == '0' && info->precision == -1 && !info->convert[0])
	{
		info->precision = info->widht - 2;
		info->widht = 0;
	}
	ft_do_p(info, str, left);
	return (info);
}
