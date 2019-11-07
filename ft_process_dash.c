/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_dash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:30:45 by kparis            #+#    #+#             */
/*   Updated: 2019/11/07 14:53:39 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_dash(char *str, char **args, int arg_count, int dash)
{
	int		x;
	int		y;
	char	*number;
	int		count;

	x = 0;
	y = 0;
	number = 0;
	count = ft_atoi(&str[dash + 1]);
	if (args[arg_count] == 0)
		return (0);
	if (count <= (int)ft_strlen(args[arg_count]))
		return (args[arg_count]);
	if (!(number = malloc(sizeof(char) * (count + 1))))
		return (0);
	while (args[arg_count][y])
		number[x++] = args[arg_count][y++];
	while (count - (ft_strlen(args[arg_count])) > 0)
	{
		number[x++] = ' ';
		count--;
	}
	return (number);
}