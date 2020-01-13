/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_converts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:18 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 11:26:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_stc	*ft_parse_stardotstar(t_stc *inf)
{
	if (inf->f_t[inf->i] == '.' && (!ft_isdigit(inf->f_t[inf->i + 1])) &&
			inf->f_t[inf->i - 1] == '*')
		inf->p = 1;
	if (inf->f_t[inf->i] == '.' && inf->f_t[inf->i + 1] == '*' &&
			inf->convert[5] != '*')
		inf->n = 1;
	return (inf);
}

static t_stc	*ft_parse(size_t i, t_stc *inf)
{
	while (inf->converters[i] != '\0')
	{
		ft_parse_stardotstar(inf);
		while (inf->converters[i] == inf->f_t[inf->i])
		{
			while (inf->f_t[inf->i] == '-' && inf->i++)
				inf->convert[0] = '-';
			while (inf->f_t[inf->i] == '+' && inf->i++)
				inf->convert[1] = '+';
			while (inf->f_t[inf->i] == ' ' && inf->i++)
				inf->convert[2] = ' ';
			while (inf->f_t[inf->i] == '0' && inf->i++)
				inf->convert[3] = '0';
			while (inf->f_t[inf->i] == '#' && inf->i++)
				inf->convert[4] = '#';
			while (inf->f_t[inf->i] == '.' && inf->i++)
				inf->convert[6] = '.';
			while ((inf->f_t[inf->i] == '*' && inf->i++) &&
					inf->convert[5] != '*')
				inf->convert[5] = '*';
			i = 0;
		}
		i++;
	}
	return (inf);
}

t_stc			*ft_parse_converts(t_stc *inf)
{
	size_t	i;

	i = 0;
	ft_parse(i, inf);
	return (inf);
}
