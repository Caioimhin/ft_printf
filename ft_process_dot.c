/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:15:31 by kparis            #+#    #+#             */
/*   Updated: 2019/11/06 18:09:04 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_dots(char *str, int i, char **args, int arg_count)
{
	int		x;
	int		y;
	char	*number;
	int		count;

	x = 0;
	y = 0;
	number = 0;
	count = ft_atoi(&str[i + 1]);
	if (args[arg_count] == 0)
		return (0);
	if (count <= (int)ft_strlen(args[arg_count]))
		return (args[arg_count]);
	if (!(number = malloc(sizeof(char) * (count + 1))))
		return (0);
	while (count - (ft_strlen(args[arg_count])) > 0)
	{
		number[x++] = '0';
		count--;
	}
	while (args[arg_count][y])
		number[x++] = args[arg_count][y++];
	return (number);
}
