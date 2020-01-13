/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:52 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsers(t_stc *inf)
{
	if (ft_strcmp(inf->f_copy, "%") == 0)
		return (0);
	while (inf->f_copy[inf->i] != '\0')
	{
		if (inf->f_copy[inf->i] == '%')
		{
			ft_reinitialize(inf);
			ft_treatments(inf);
		}
		else
		{
			write(1, &inf->f_copy[inf->i], 1);
			inf->len++;
		}
		inf->i++;
	}
	return (inf->len);
}
