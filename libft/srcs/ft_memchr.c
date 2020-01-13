/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:10:16 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:45:36 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	char	*m;
	size_t	i;

	ptr = 0;
	m = (char*)s;
	i = 0;
	while (i < n)
	{
		if (m[i] == ((char)c))
		{
			ptr = &m[i];
			return (ptr);
		}
		i++;
	}
	return (0);
}
