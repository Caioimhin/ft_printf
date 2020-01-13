/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:37 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_parse_specifiers(t_stc *inf)
{
	size_t	i;

	i = 0;
	while (inf->specifiers[i] != '\0')
	{
		if (inf->specifiers[i] == inf->f_t[inf->i])
			inf->specifiers_flags = inf->specifiers[i];
		i++;
	}
	return (inf);
}
