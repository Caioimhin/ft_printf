/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:54:10 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 15:20:43 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_rev(char *inf)
{
	int		len;
	int		i;
	char	*tab2;

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
	return (tab2);
}

static	int		get_intlen(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*itoarev(char *inf, int len, int n, int sign)
{
	int i;

	i = 0;
	while (i < len)
	{
		inf[i++] = (n % 10) + '0';
		n = n / 10;
		if (n == 0 && sign == 1)
			inf[i++] = '-';
	}
	inf[i] = 0;
	return (inf);
}

char			*ft_itoa(int n)
{
	char	*inf;
	char	*tab2;
	int		sign;
	int		len;

	sign = 0;
	inf = 0;
	tab2 = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	len = get_intlen(n);
	if (!(inf = malloc(sizeof(char) * (len + sign + 1))))
		return (0);
	inf = itoarev(inf, len, n, sign);
	tab2 = ft_rev(inf);
	free(inf);
	return (tab2);
}
