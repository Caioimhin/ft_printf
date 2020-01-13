/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:11 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 17:11:10 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_initialize(t_struct *info)
{
	info->len = 0;
	info->i = 0;
	info->j = 0;
	info->k = 0;
	info->l = 0;
	info->n = 0;
	info->o = 0;
	info->p = 0;
	info->specifiers = "scdiuxXpn%";
	info->converters = "-+ 0#.*";
	info->f_t = (char *)info->fmt;
	info->f_copy = (char *)info->fmt;
	return (info);
}
