/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:20:30 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 13:22:42 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_unsigned_rev(char *tab)
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
	free(tab);
	return (tab2);
}

static int		get_unsigned_intlen(unsigned int n)
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

static char		*unsigned_itoarev(char *tab, unsigned int len, unsigned int n)
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

char			*ft_utoa(unsigned int n)
{
	char	*tab;
	int		len;

	tab = 0;
	if (n == 0)
		return (ft_strdup("0"));
	len = get_unsigned_intlen(n);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (0);
	tab = unsigned_itoarev(tab, len, n);
	tab = ft_unsigned_rev(tab);
	return (tab);
}
