/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:40:48 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			ft_sign(uintmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static t_tab_itoa	*ft_get_str(t_tab_itoa *inf, uintmax_t value,
								int base, char c)
{
	if (c >= 'a' && c <= 'z')
		inf->str_bases = "0123456789abcdef";
	if (c >= 'A' && c <= 'Z')
		inf->str_bases = "0123456789ABCDEF";
	while (inf->size > inf->flag)
	{
		inf->str[inf->size - 1] = inf->str_bases[ft_sign(value % base)];
		inf->size--;
		value /= base;
	}
	return (inf);
}

char				*ft_itoa_base(uintmax_t value, int base, char c)
{
	t_tab_itoa	*inf;
	char		*res;

	if (!(inf = (t_tab_itoa*)malloc(sizeof(t_tab_itoa))))
		return (0);
	inf->flag = 0;
	inf->size = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		inf->flag = 1;
	inf->tmp = value;
	while (inf->tmp /= base)
		inf->size++;
	inf->size = inf->size + inf->flag + 1;
	inf->str = (char *)malloc(sizeof(char) * inf->size + 1);
	inf->str[inf->size] = '\0';
	if (inf->flag == 1)
		inf->str[0] = '-';
	ft_get_str(inf, value, base, c);
	res = ft_strdup(inf->str);
	free(inf->str);
	free(inf);
	return (res);
}
