/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:15 by kevin             #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_dos(t_struct *info, char *s, int len)
{
	if (info->convert[3] == '0' && info->convert[0] != '-')
		ft_display_widht(info, '0', info->widht - len, 1);
	else if (info->convert[6] == '.' && info->precision < info->widht)
	{
		ft_putstr(s);
		if (info->convert[0] == '-')
			ft_display_widht(info, ' ', info->widht - len, 1);
		if (info->precision > -1 || info->precision == -1)
			free(s);
		return (info);
	}
	else if (info->convert[0] != '-')
		ft_display_widht(info, ' ', info->widht - len, 1);
	ft_putstr(s);
	if (info->convert[0] == '-')
		ft_display_widht(info, ' ', info->widht - len, 1);
	if (info->precision > -1 || info->precision == -1)
		free(s);
	return (info);
}

t_struct			*ft_display_s(t_struct *info)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	if (info->f_t[info->i - 1] == 's')
		info->i--;
	s = va_arg(info->arg, char *);
	if (info->precision > -1 && s)
		s = ft_strndup(s, info->precision);
	else if (info->precision == -1 && s)
		s = ft_strdup(s);
	else if (info->precision > -1 && !s)
		s = ft_strndup("(null)", info->precision);
	else if (info->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	info->len += len;
	ft_dos(info, s, len);
	return (info);
}
