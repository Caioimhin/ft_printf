/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:21:28 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_tab	ft_treat_star(t_tab inf, va_list args)
{
	if (inf.dot)
		inf.precision = va_arg(args, int);
	else if (inf.width < 1)
	{
		inf.width = va_arg(args, int);
		if (inf.width < 0)
		{
			inf.width *= -1;
			inf.minus = 1;
		}
	}
	return (inf);
}

t_tab	ft_treatment_flag(char format, t_tab inf, va_list args)
{
	if (format == '-')
		inf.minus = 1;
	else if (format == '0' && inf.width < 1 && !inf.dot)
		inf.zero = 1;
	else if (ft_isdigit(format) && !inf.dot)
		inf.width = (inf.width * 10) + (format - '0');
	else if (format == '.')
	{
		inf.dot = 1;
		inf.precision = 0;
	}
	else if (ft_isdigit(format) && inf.dot)
		inf.precision = (inf.precision * 10) + (format - '0');
	else if (format == '*')
		inf = ft_treat_star(inf, args);
	return (inf);
}

t_tab	parser_flags(const char *format, t_tab inf, va_list args)
{
	int	i;

	i = 0;
	while (format[i] && ft_flag(format[i]))
	{
		inf = ft_treatment_flag(format[i], inf, args);
		i++;
	}
	return (inf);
}
