/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinitialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:41 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_struct	*ft_reinitialize(t_struct *info)
{
	info->specifiers_flags = '\0';
	info->convert[0] = '\0';
	info->convert[1] = '\0';
	info->convert[2] = '\0';
	info->convert[3] = '\0';
	info->convert[4] = '\0';
	info->convert[5] = '\0';
	info->convert[6] = '\0';
	info->precision = -1;
	info->widht = 0;
	return (info);
}
