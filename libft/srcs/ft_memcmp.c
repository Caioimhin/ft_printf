/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:54:08 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:15:08 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char			*m;
	const unsigned char			*l;
	unsigned int				i;

	m = (unsigned char*)s1;
	l = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (m[i] != l[i])
			return (m[i] - l[i]);
		i++;
	}
	return (0);
}
