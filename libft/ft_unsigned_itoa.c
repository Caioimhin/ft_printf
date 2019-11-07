/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:54:10 by kparis            #+#    #+#             */
/*   Updated: 2019/10/25 10:57:23 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_rev(char *tab)
{
	unsigned int		len;
	unsigned int		i;
	char				*tab2;

	len = ft_strlen(tab);
	if (!(tab2 = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (len)
	{
		tab2[i++] = tab[len - 1];
		len--;
	}
	tab2[i] = 0;
	return (tab2);
}

char	*unsigned_iszero(char *tab)
{
	if (!(tab = malloc(sizeof(char) * 2)))
		return (0);
	tab[0] = '0';
	tab[1] = 0;
	return (tab);
}

int		get_unsigned_intlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*unsigned_itoarev(char *tab, unsigned int len, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		tab[i++] = (n % 10) + '0';
		n = n / 10;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*tab;
	int		len;

	tab = 0;
	if (n == 0)
		return (unsigned_iszero(tab));
	len = get_unsigned_intlen(n);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (0);
	tab = unsigned_itoarev(tab, len, n);
	tab = ft_unsigned_rev(tab);
	return (tab);
}
