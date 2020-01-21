/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:25 by kevin             #+#    #+#             */
/*   Updated: 2020/01/21 14:46:20 by kparis           ###   ########.fr       */
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

static t_stc	*ft_do_u(t_stc *inf, uintmax_t num, int num_width)
{
	int			not_blank;
	int			left;

	not_blank = num_width;
	left = 0;
	(inf->convert[0] == '-') ? left = 1 : 0;
	if (num_width <= inf->precision)
		not_blank = inf->precision;
	inf->len += (not_blank <= inf->width) ? inf->width : not_blank;
	if (!left)
		ft_display_width(inf, ' ', inf->width - not_blank, 0);
	ft_display_width(inf, '0', inf->precision - num_width, 0);
	ft_putnbrumax_fd(num, 1);
	if (left)
		ft_display_width(inf, ' ', inf->width - not_blank, 0);
	return (inf);
}

static t_stc	*ft_space(t_stc *inf)
{
	if (inf->convert[0] != '-' && inf->width == 0)
		ft_display_width(inf, ' ', inf->width, 1);
	if (inf->convert[0] != '-' && inf->width != 0 && inf->precision > 0)
	{
		ft_display_width(inf, ' ', inf->width - 1, 1);
		ft_putchar('0');
	}
	if (inf->convert[0] == '-' && inf->width != 0 && inf->precision == -1)
	{
		ft_putchar('0');
		ft_display_width(inf, ' ', inf->width - 1, 1);
		return (inf);
	}
	if (inf->convert[0] == '-')
	{
		inf->i--;
		ft_display_width(inf, ' ', inf->width, 1);
	}
	if (inf->precision == 0 && inf->width > 0 && inf->convert[0] != '-')
	{
		ft_display_width(inf, ' ', inf->width, 0);
		return (inf);
	}
	return (inf);
}

t_stc			*ft_display_u(t_stc *inf)
{
	uintmax_t	num;
	int			num_width;

	num = (unsigned int)va_arg(inf->arg, unsigned int);
	if (num == 0 && inf->precision == -1 && inf->convert[6] != '.' &&
		inf->width <= 0)
	{
		ft_putchar('0');
		return (inf);
	}
	num_width = ft_obtain_ten(num);
	if ((num == 0 && inf->precision == -1 && inf->width <= 0) ||
		(num == 0 && inf->precision == 0))
	{
		if (inf->f_t[inf->i - 1] == 'u' && inf->convert[0] == '\0'
			&& inf->convert[3] == '\0')
			inf->i--;
		(inf->f_t[inf->i] == 'u' && inf->convert[0] == '-') ? inf->i++ : 0;
		ft_space(inf);
		return (inf);
	}
	if (inf->convert[3] == '0' && inf->precision == -1 && !inf->convert[0])
		inf->precision = inf->width;
	ft_do_u(inf, num, num_width);
	return (inf);
}
