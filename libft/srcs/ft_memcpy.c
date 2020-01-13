/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:42:19 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:45:36 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*m;
	char	*l;

	if ((dst == '\0') && (src == '\0'))
		return (0);
	m = (char*)dst;
	l = (char*)src;
	while (n--)
		*m++ = *l++;
	return (dst);
}
