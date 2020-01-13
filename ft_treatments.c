/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:27:03 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_stc	*ft_direct_dot(t_stc *inf)
{
	ft_parse_specifiers(inf);
	ft_send_displays(inf);
	return (inf);
}

static t_stc	*ft_sparks(t_stc *inf)
{
	if (inf->f_t[inf->i + 1] == '.' && inf->f_t[inf->i] == '*')
	{
		inf->j = 1;
		ft_parse_converts(inf);
		ft_parse_widht(inf);
		ft_parse_precision(inf);
		if ((inf->f_t[inf->i - 1] == 'd' || inf->f_t[inf->i - 1] == 'i' ||
			inf->f_t[inf->i - 1] == 'u' || inf->f_t[inf->i - 1] == 'x' ||
			inf->f_t[inf->i - 1] == 'X' || inf->f_t[inf->i - 1] == 'p' ||
			inf->f_t[inf->i - 1] == 's') && inf->precision > 0)
		{
			inf->i--;
			ft_display_widht(inf, ' ', inf->widht - inf->precision, 1);
		}
		ft_parse_specifiers(inf);
		ft_send_displays(inf);
	}
	return (inf);
}

static t_stc	*ft_jzero(t_stc *inf)
{
	ft_parse_converts(inf);
	ft_parse_widht(inf);
	ft_parse_precision(inf);
	ft_parse_specifiers(inf);
	ft_send_displays(inf);
	return (inf);
}

int				ft_treatments(t_stc *inf)
{
	inf->i++;
	if (inf->f_t[inf->i] == '.' && inf->f_t[inf->i + 1] != '*')
	{
		ft_parse_converts(inf);
		if (inf->f_t[inf->i] == 'd' || inf->f_t[inf->i] == 'i' ||
			inf->f_t[inf->i] == 'u' || inf->f_t[inf->i] == 'x' ||
			inf->f_t[inf->i] == 'X' || inf->f_t[inf->i] == 'p')
		{
			ft_direct_dot(inf);
			return (inf->len);
		}
		ft_parse_precision(inf);
		ft_parse_specifiers(inf);
		ft_send_displays(inf);
		return (inf->len);
	}
	ft_sparks(inf);
	if (inf->j == 0)
		ft_jzero(inf);
	return (inf->len);
}
