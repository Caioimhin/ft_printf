/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:17:39 by kparis            #+#    #+#             */
/*   Updated: 2019/11/07 14:58:51 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_process_dash_b4_dot(char *number, int count)
{
	char	*str;
	int		i;

	i = 0;
	if (count - ft_strlen(number) > 0)
	{
		if (!(str = malloc(sizeof(char) * (count + 1))))
			return (0);
		while (number[i])
		{
			str[i] = number[i];
			i++;
			count--;
		}
		while (count > 0)
		{
			str[i++] = ' ';
			count--;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (number);

}

char		*ft_replace_flags(char *str, char **args)
{
	int		i;
	int		flag;
	int		dash;
	int		argcount;
	char	*start;
	char	*number;

	i = 0;
	flag = 0;
	dash = -1;
	argcount = 0;
	while (str[i])
	{
		// gere les flags basiques
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'u' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'p'
				|| str[i + 1] == 'c' || str[i + 1] == 's')
			{
				if (args[argcount] == 0)
					return (0);
				start = str;
				start[i] = '\0';
				start = ft_strjoin(start, args[argcount++]);
				str = ft_strjoin(start, &str[i + 2]);
				continue;
			}
			else
				flag = 1;
		}
		// save l'emplacement du -
		if (str[i] == '-' && flag == 1)
			dash = i;
		// si il y a une precision
		if (str[i] == '.' && flag == 1)
		{
			start = str;
			number = ft_process_dots(str, i, args, argcount);
			// si pas de moins avant la precision
			if (dash == -1)
			{
				start[i] = '\0';
				start = ft_strjoin(start, number);
			}
			// si moins avant la precision
			else
			{
				start[dash] = '\0';
				start = ft_strjoin(start,
					ft_process_dash_b4_dot(number, ft_atoi(&start[dash + 1])));
			}
			// reset tout et renvoie str /!\ a remplir tout les cas et pas juste pour le flag d
			i++;
			while (ft_isdigit(str[i]))
				i++;
			argcount++;
			flag = 0;
			dash = -1;
			str = ft_strjoin(start, &str[i + 1]);
		}
		if (str[i] == '0' && str[i - 1] == '%')
		{
			start = str;
			start[i] = '\0';
			start = ft_strjoin(start, ft_process_dots(str, i, args, argcount));
			i++;
			while (ft_isdigit(str[i]))
				i++;
			argcount++;
			flag = 0;
			dash = -1;
			str = ft_strjoin(start, &str[i + 1]);
		}
		if ((EQUAL_LIST) && flag == 1 && dash != -1)
		{
			start = str;
			start[dash] = '\0';
			start = ft_strjoin(start, ft_process_dash(str, args, argcount, dash));
			argcount++;
			flag = 0;
			dash = -1;
			str = ft_strjoin(start, &str[i + 1]);
		}
		i++;
	}
	return (str);
}
