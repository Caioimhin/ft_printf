/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:03:05 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:44:44 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*m;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	m = (char*)s1;
	if (m == '\0')
		return (0);
	if (!(dst = (char*)malloc(sizeof(*s1) * (len + 1))))
		return (0);
	while (i < len)
	{
		dst[i] = m[i];
		i++;
	}
	dst[i] = m[i];
	return (dst);
}
