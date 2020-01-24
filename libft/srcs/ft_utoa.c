/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:20:30 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_unsigned_rev(char *inf)
{
	unsigned int		len;
	unsigned int		i;
	char				*tab2;

	len = ft_strlen(inf);
	if (!(tab2 = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (len)
	{
		tab2[i++] = inf[len - 1];
		len--;
	}
	tab2[i] = 0;
	free(inf);
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

static char		*unsigned_itoarev(char *inf, unsigned int len, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		inf[i++] = (n % 10) + '0';
		n = n / 10;
	}
	inf[i] = 0;
	return (inf);
}

char			*ft_utoa(unsigned int n)
{
	char	*inf;
	int		len;

	inf = 0;
	if (n == 0)
		return (ft_strdup("0"));
	len = get_unsigned_intlen(n);
	if (!(inf = malloc(sizeof(char) * (len + 1))))
		return (0);
	inf = unsigned_itoarev(inf, len, n);
	inf = ft_unsigned_rev(inf);
	return (inf);
}
