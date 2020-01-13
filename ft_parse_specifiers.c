/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:37 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_parse_specifiers(t_struct *info)
{
	size_t	i;

	i = 0;
	while (info->specifiers[i] != '\0')
	{
		if (info->specifiers[i] == info->f_t[info->i])
			info->specifiers_flags = info->specifiers[i];
		i++;
	}
	return (info);
}
