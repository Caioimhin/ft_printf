/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:20:37 by kevin             #+#    #+#             */
/*   Updated: 2020/01/20 15:52:39 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_width(t_stc *inf, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			inf->len += len;
		if (!(str = malloc(sizeof(char *) * len + 1)))
			return (-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
	return (inf->len);
}
