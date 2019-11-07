/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_doubledash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:05:25 by kparis            #+#    #+#             */
/*   Updated: 2019/11/04 13:50:26 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*remove_doubledash(char *str)
{
	int		i;
	int		flag;
	char	*start;

	start = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '%')
			flag = 1;
		if (flag == 1 && (str[i] == '-' && str[i + 1] == '-'))
		{
			start = str;
			start[i] = '\0';
			str = ft_strjoin(start, &str[i + 1]);
		}
		if ((str[i] == 'd' || str[i] == 'i' || str[i] == 'u'
			|| str[i] == 'x' || str[i] == 'X' || str[i] == 'p'
			|| str[i] == 'c' || str[i] == 's') && flag == 1)
			flag = 0;
		i++;
	}
	return (str);
}
