/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:40:48 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 11:54:33 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			ft_sign(uintmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static t_tab_itoa	*ft_get_str(t_tab_itoa *tab, uintmax_t value,
								int base, char c)
{
	if (c >= 'a' && c <= 'z')
		tab->str_bases = "0123456789abcdef";
	if (c >= 'A' && c <= 'Z')
		tab->str_bases = "0123456789ABCDEF";
	while (tab->size > tab->flag)
	{
		tab->str[tab->size - 1] = tab->str_bases[ft_sign(value % base)];
		tab->size--;
		value /= base;
	}
	return (tab);
}

char				*ft_itoa_base(uintmax_t value, int base, char c)
{
	t_tab_itoa	tab;

	tab.flag = 0;
	tab.size = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		tab.flag = 1;
	tab.tmp = value;
	while (tab.tmp /= base)
		tab.size++;
	tab.size = tab.size + tab.flag + 1;
	tab.str = (char *)malloc(sizeof(char) * tab.size + 1);
	tab.str[tab.size] = '\0';
	if (tab.flag == 1)
		tab.str[0] = '-';
	ft_get_str(&tab, value, base, c);
	return (tab.str);
}
