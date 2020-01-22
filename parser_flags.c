/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:21:28 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:21:29 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_tab	ft_treat_star(t_tab tab, va_list args)
{
	if (tab.dot)
		tab.precision = va_arg(args, int);
	else if (tab.width < 1)
	{
		tab.width = va_arg(args, int);
		if (tab.width < 0)
		{
			tab.width *= -1;
			tab.minus = 1;
		}
	}
	return (tab);
}

t_tab	ft_treatment_flag(char format, t_tab tab, va_list args)
{
	if (format == '-')
		tab.minus = 1;
	else if (format == '0' && tab.width < 1 && !tab.dot)
		tab.zero = 1;
	else if (ft_isdigit(format) && !tab.dot)
		tab.width = (tab.width * 10) + (format - '0');
	else if (format == '.')
	{
		tab.dot = 1;
		tab.precision = 0;
	}
	else if (ft_isdigit(format) && tab.dot)
		tab.precision = (tab.precision * 10) + (format - '0');
	else if (format == '*')
		tab = ft_treat_star(tab, args);
	return (tab);
}

t_tab	parser_flags(const char *format, t_tab tab, va_list args)
{
	int	i;

	i = 0;
	while (format[i] && ft_flag(format[i]))
	{
		tab = ft_treatment_flag(format[i], tab, args);
		i++;
	}
	return (tab);
}
