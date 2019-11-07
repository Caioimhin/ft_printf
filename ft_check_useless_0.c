/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_useless_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:03:28 by kparis            #+#    #+#             */
/*   Updated: 2019/11/06 17:09:26 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_new_str(char *str, int zero)
{
	char	*start;

	start = str;
	start[zero] = '\0';
	str = &str[zero + 1];
	str = ft_strjoin(start, str);
	return (str);
}

char		*check_useless_0(char *str)
{
	int		i;
	int		flag;
	int		zero;

	i = 0;
	flag = 0;
	zero = -1;
	while (str[i])
	{
		if (str[i] == '%')
			flag = 1;
		if (flag == 1 && str[i] == '0')
			zero = i;
		if ((zero != -1 && flag == 1) && (str[i] == '-' || str[i] == '.'))
		{
			str = get_new_str(str, zero);
			zero = -1;
		}
		if ((EQUAL_LIST) && flag == 1)
		{
			flag = 0;
			zero = -1;
		}
		i++;
	}
	return (str);
}
