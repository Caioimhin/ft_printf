/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:37:04 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc			*ft_display_c(t_stc *inf)
{
	int		c;

	if (inf->f_t[inf->i - 1] == 'c')
		inf->i--;
	c = (char)va_arg(inf->arg, int);
	if (inf->convert[3] == '0' && inf->convert[0] != '-')
		ft_display_widht(inf, '0', inf->widht - 1, 1);
	else if (inf->convert[0] != '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	ft_putchar(c);
	inf->len++;
	if (inf->convert[0] == '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	return (inf);
}
