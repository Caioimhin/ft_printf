/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:20:30 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:20:31 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_utoa(unsigned int n)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	if (n < 0)
		return (ft_strdup(""));
	else if (n >= 10)
		str = ft_strjoin(ft_utoa(n / 10), ft_utoa(n % 10));
	else if (n >= 0 && n < 10)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
