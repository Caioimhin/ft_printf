/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:12:46 by kparis            #+#    #+#             */
/*   Updated: 2019/10/24 18:28:23 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_percent(void)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '%';
	str[1] = 0;
	return (str);
}
