/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:53 by kevin             #+#    #+#             */
/*   Updated: 2020/01/13 10:04:17 by kparis           ###   ########.fr       */
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

static uintmax_t	ft_get_num(t_stc *inf)
{
	uintmax_t	num;

	num = (unsigned int)(va_arg(inf->arg, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static t_stc		*ft_do_x(t_stc *inf, uintmax_t num, char *str)
{
	int			n_b;
	int			n_w;
	int			left;

	left = 0;
	(inf->convert[0] == '-') ? left = 1 : 0;
	if ((n_w = ft_strlen(str)) && inf->convert[4] == '#' && num &&
			inf->convert[3] == '0' && inf->widht)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && inf->convert[4] == '#' && num)
	{
		inf->widht -= 2;
		inf->len += 2;
	}
	n_b = (n_w <= inf->precision && inf->precision > 0) ? inf->precision : n_w;
	inf->len += (n_b <= inf->widht) ? inf->widht : n_b;
	if (!left)
		ft_display_widht(inf, ' ', inf->widht - n_b, 0);
	ft_print_leading_zero(num, inf->convert[4], inf->specifiers_flags);
	ft_display_widht(inf, '0', inf->precision - n_w, 0);
	ft_putstr(str);
	if (left)
		ft_display_widht(inf, ' ', inf->widht - n_b, 0);
	return (inf);
}

static t_stc		*ft_numzero(t_stc *inf, int num)
{
	if (num == 0 && inf->precision == 0)
	{
		if (inf->f_t[inf->i - 1] == 'x' || inf->f_t[inf->i - 1] == 'X')
			inf->i--;
		ft_display_widht(inf, ' ', inf->widht, 1);
		inf->k = 1;
		return (inf);
	}
	else
		return (inf);
}

t_stc				*ft_display_x(t_stc *inf)
{
	char		*str;
	char		c;
	uintmax_t	num;

	num = ft_get_num(inf);
	ft_numzero(inf, num);
	if (inf->k == 1)
		return (inf);
	c = 'a';
	(inf->specifiers_flags == 'X') ? c = 'A' : 0;
	str = ft_itoa_base(num, 16, c);
	(inf->f_t[inf->i - 1] == 'x' || inf->f_t[inf->i - 1] == 'X') ? inf->i-- : 0;
	if (((inf->precision < 0 && num == 0) && ((inf->convert[3] == '0' &&
			inf->convert[6] == '.') || (inf->convert[6] == '.'))))
	{
		ft_strdup("");
		return (inf);
	}
	if (inf->convert[3] == '0' && inf->precision == -1 && !inf->convert[0])
		inf->precision = inf->widht;
	ft_do_x(inf, num, str);
	(num == 0 || num == '\0') ? inf->len++ : 0;
	free(str);
	return (inf);
}
