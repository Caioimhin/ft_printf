/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:52 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsers(t_struct *info)
{
	if (ft_strcmp(info->f_copy, "%") == 0)
		return (0);
	while (info->f_copy[info->i] != '\0')
	{
		if (info->f_copy[info->i] == '%')
		{
			ft_reinitialize(info);
			ft_treatments(info);
		}
		else
		{
			write(1, &info->f_copy[info->i], 1);
			info->len++;
		}
		info->i++;
	}
	return (info->len);
}
