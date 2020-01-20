/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:37:04 by kparis            #+#    #+#             */
/*   Updated: 2020/01/20 15:52:39 by kparis           ###   ########.fr       */
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
		ft_display_width(inf, '0', inf->width - 1, 1);
	else if (inf->convert[0] != '-')
		ft_display_width(inf, ' ', inf->width - 1, 1);
	ft_putchar(c);
	inf->len++;
	if (inf->convert[0] == '-')
		ft_display_width(inf, ' ', inf->width - 1, 1);
	return (inf);
}
