/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:14:56 by kparis            #+#    #+#             */
/*   Updated: 2019/11/06 13:32:34 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*trunc_str(char *str, va_list va, char **args)
{
	int	flag;
	int	x;
	int	i;

	x = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			flag = 1;
		if (str[i] == '*' && flag == 1)
			str = ft_process_star(i, str, va);
		if ((EQUAL_LIST) && flag == 1)
		{
			flag = 0;
			args[x] = ft_process_basics(str[i], va);
			x++;
		}
		i++;
	}
	args[x] = NULL;
	return (str);
}
