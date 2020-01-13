/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_converts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:18 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_parse_stardotstar(t_struct *info)
{
	if (info->f_t[info->i] == '.' && (!ft_isdigit(info->f_t[info->i + 1])) &&
			info->f_t[info->i - 1] == '*')
		info->p = 1;
	if (info->f_t[info->i] == '.' && info->f_t[info->i + 1] == '*' &&
			info->convert[5] != '*')
		info->n = 1;
	return (info);
}

static t_struct	*ft_parse(size_t i, t_struct *info)
{
	while (info->converters[i] != '\0')
	{
		ft_parse_stardotstar(info);
		while (info->converters[i] == info->f_t[info->i])
		{
			while (info->f_t[info->i] == '-' && info->i++)
				info->convert[0] = '-';
			while (info->f_t[info->i] == '+' && info->i++)
				info->convert[1] = '+';
			while (info->f_t[info->i] == ' ' && info->i++)
				info->convert[2] = ' ';
			while (info->f_t[info->i] == '0' && info->i++)
				info->convert[3] = '0';
			while (info->f_t[info->i] == '#' && info->i++)
				info->convert[4] = '#';
			while (info->f_t[info->i] == '.' && info->i++)
				info->convert[6] = '.';
			while ((info->f_t[info->i] == '*' && info->i++) &&
					info->convert[5] != '*')
				info->convert[5] = '*';
			i = 0;
		}
		i++;
	}
	return (info);
}

t_struct			*ft_parse_converts(t_struct *info)
{
	size_t	i;

	i = 0;
	ft_parse(i, info);
	return (info);
}
