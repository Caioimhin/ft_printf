/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:06 by kevin             #+#    #+#             */
/*   Updated: 2020/01/13 10:02:38 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	ft_get_num(t_stc *inf)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(inf->arg, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_stc		*ft_do_p(t_stc *inf, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	inf->len += (not_blank <= inf->widht) ? inf->widht : not_blank;
	if (!left)
		ft_display_widht(inf, ' ', inf->widht - not_blank, 0);
	write(1, "0x", 2);
	ft_display_widht(inf, '0', (inf->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (left)
		ft_display_widht(inf, ' ', inf->widht - not_blank, 0);
	free(str);
	return (inf);
}

static t_stc		*ft_numzero(t_stc *inf, uintmax_t num, char *str)
{
	int			num_width;

	num_width = ft_strlen(str) + 2;
	if (num == 0)
	{
		if (inf->precision == -1 && inf->convert[3] != '0')
			ft_display_widht(inf, ' ', (inf->widht - num_width), 0);
		if (inf->precision >= 0 || (inf->precision == -1 &&
			((inf->convert[3] == '0') || (inf->convert[6] == '.'))))
		{
			if (inf->precision == 0)
				ft_display_widht(inf, ' ', (inf->widht - 2), 0);
			write(1, "0x", 2);
			if (inf->precision > 0)
				ft_display_widht(inf, '0', inf->precision, 0);
			inf->l = 1;
			return (inf);
		}
		write(1, "0x0", 3);
		inf->l = 1;
		return (inf);
	}
	return (inf);
}

t_stc				*ft_display_p(t_stc *inf)
{
	char		*str;
	uintmax_t	num;
	int			left;

	left = 0;
	num = ft_get_num(inf);
	str = ft_calloc(ft_strlen(ft_itoa_base(num, 16, 'a')), sizeof(char));
	str = ft_itoa_base(num, 16, 'a');
	if (inf->f_t[inf->i - 1] == 'p' && inf->convert[0] == '\0'
		&& inf->convert[3] == '\0')
		inf->i--;
	ft_numzero(inf, num, str);
	if (inf->l == 1)
		return (inf);
	if (inf->convert[0] == '-')
		left = 1;
	if (inf->convert[3] == '0' && inf->precision == -1 && !inf->convert[0])
	{
		inf->precision = inf->widht - 2;
		inf->widht = 0;
	}
	ft_do_p(inf, str, left);
	return (inf);
}
