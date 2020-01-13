/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:11 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_initialize(t_stc *inf)
{
	inf->len = 0;
	inf->i = 0;
	inf->j = 0;
	inf->k = 0;
	inf->l = 0;
	inf->n = 0;
	inf->o = 0;
	inf->p = 0;
	inf->specifiers = "scdiuxXpn%";
	inf->converters = "-+ 0#.*";
	inf->f_t = (char *)inf->fmt;
	inf->f_copy = (char *)inf->fmt;
	return (inf);
}
