/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinitialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:41 by kparis            #+#    #+#             */
/*   Updated: 2020/01/20 15:07:44 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_reinitialize(t_stc *inf)
{
	inf->specifiers_flags = '\0';
	inf->convert[0] = '\0';
	inf->convert[1] = '\0';
	inf->convert[2] = '\0';
	inf->convert[3] = '\0';
	inf->convert[4] = '\0';
	inf->convert[5] = '\0';
	inf->convert[6] = '\0';
	inf->precision = -1;
	inf->width = 0;
	return (inf);
}
