/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:15 by kevin             #+#    #+#             */
/*   Updated: 2020/01/13 10:02:00 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_stc	*ft_dos(t_stc *inf, char *s, int len)
{
	if (inf->convert[3] == '0' && inf->convert[0] != '-')
		ft_display_widht(inf, '0', inf->widht - len, 1);
	else if (inf->convert[6] == '.' && inf->precision < inf->widht)
	{
		ft_putstr(s);
		if (inf->convert[0] == '-')
			ft_display_widht(inf, ' ', inf->widht - len, 1);
		if (inf->precision > -1 || inf->precision == -1)
			free(s);
		return (inf);
	}
	else if (inf->convert[0] != '-')
		ft_display_widht(inf, ' ', inf->widht - len, 1);
	ft_putstr(s);
	if (inf->convert[0] == '-')
		ft_display_widht(inf, ' ', inf->widht - len, 1);
	if (inf->precision > -1 || inf->precision == -1)
		free(s);
	return (inf);
}

t_stc			*ft_display_s(t_stc *inf)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	if (inf->f_t[inf->i - 1] == 's')
		inf->i--;
	s = va_arg(inf->arg, char *);
	if (inf->precision > -1 && s)
		s = ft_strndup(s, inf->precision);
	else if (inf->precision == -1 && s)
		s = ft_strdup(s);
	else if (inf->precision > -1 && !s)
		s = ft_strndup("(null)", inf->precision);
	else if (inf->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	inf->len += len;
	ft_dos(inf, s, len);
	return (inf);
}
