/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:20:15 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:44:44 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *m;
	char *l;

	if ((dst == '\0') && (src == '\0'))
		return (0);
	m = (char *)dst;
	l = (char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			m[len - 1] = l[len - 1];
			len--;
		}
		return (dst);
	}
	else
		while (len > 0)
		{
			*m = *l;
			m++;
			l++;
			len--;
		}
	return (dst);
}
