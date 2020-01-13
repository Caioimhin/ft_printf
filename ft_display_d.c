/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:19:58 by kevin             #+#    #+#             */
/*   Updated: 2020/01/13 10:03:45 by kparis           ###   ########.fr       */
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

static t_stc	*ft_displayzero(t_stc *inf, int sign_place, int num_width)
{
	if (inf->convert[3] == '0' && sign_place && (inf->precision < inf->widht))
	{
		ft_display_widht(inf, '0', inf->precision - num_width, 0);
		return (inf);
	}
	if (inf->convert[3] == '0' && sign_place && (inf->precision > inf->widht))
	{
		ft_display_widht(inf, '0', inf->precision - num_width, 0);
		return (inf);
	}
	if (inf->convert[3] == '0' && sign_place && inf->precision == inf->widht)
	{
		ft_display_widht(inf, '0', inf->precision - num_width - 1, 0);
		return (inf);
	}
	if (inf->convert[3] == '0' && !sign_place)
	{
		ft_display_widht(inf, '0', inf->precision - num_width, 0);
		return (inf);
	}
	else
		ft_display_widht(inf, '0', inf->precision - num_width, 0);
	return (inf);
}

static t_stc	*ft_do_d(t_stc *inf, intmax_t num, int num_width, int left)
{
	int			not_blank;
	char		sign_place;
	int			negative;

	negative = (num < 0) ? 1 : 0;
	num *= (negative && num != (-2147483648 - 1)) ? -1 : 1;
	sign_place = ft_placesign(negative);
	not_blank = num_width;
	if (num_width <= inf->precision && inf->precision >= 0)
		not_blank = inf->precision;
	sign_place ? not_blank++ : 0;
	inf->len += (not_blank <= inf->widht) ? inf->widht : not_blank;
	if (inf->convert[5] == '*' && inf->convert[6] == '.' && inf->precision == 0)
		ft_prec_and_width(inf, num, sign_place);
	if (inf->m == 1)
		return (inf);
	(!left) ? ft_display_widht(inf, ' ', inf->widht - not_blank, 0) : 0;
	(sign_place) ? write(1, &sign_place, 1) : 0;
	ft_displayzero(inf, sign_place, num_width);
	if (num != (-2147483648 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((inf->len += 9) > 0)
		write(1, "2147483648", 10);
	(left) ? ft_display_widht(inf, ' ', inf->widht - not_blank, 0) : 0;
	return (inf);
}

t_stc			*ft_display_d(t_stc *inf)
{
	intmax_t	num;
	int			num_width;
	int			left;

	num = (int)(va_arg(inf->arg, int));
	if (num == 0 && inf->precision == 0)
	{
		if (inf->f_t[inf->i - 1] == 'i' || inf->f_t[inf->i - 1] == 'd')
			inf->i--;
		ft_display_widht(inf, ' ', inf->widht, 1);
		return (inf);
	}
	(inf->f_t[inf->i - 1] == 'i' || inf->f_t[inf->i - 1] == 'd') ? inf->i-- : 0;
	if (((inf->precision < 0 && num == 0) && ((inf->convert[3] == '0' &&
			inf->convert[6] == '.') || (inf->convert[6] == '.'))))
	{
		ft_strdup("");
		return (inf);
	}
	num_width = ft_obtain_ten(num);
	left = (inf->convert[0] == '-') ? 1 : 0;
	if (inf->convert[3] == '0' && inf->precision == -1 && !inf->convert[0])
		inf->precision = inf->widht;
	ft_do_d(inf, num, num_width, left);
	return (inf);
}
