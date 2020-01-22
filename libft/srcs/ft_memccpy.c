/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:28:07 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:15:08 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char					*ptr;
	unsigned char			*m;
	unsigned char			*l;
	unsigned int			i;

	ptr = 0;
	m = (unsigned char*)dst;
	l = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		m[i] = l[i];
		if (l[i] == ((unsigned char)c))
		{
			ptr = dst + i + 1;
			return (ptr);
		}
		i++;
	}
	return (0);
}
