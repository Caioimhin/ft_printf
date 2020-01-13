/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:40:48 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:45:36 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			ft_sign(uintmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static t_tab_itoa	*ft_get_str(t_tab_itoa *info, uintmax_t value,
								int base, char c)
{
	if (c >= 'a' && c <= 'z')
		info->str_bases = "0123456789abcdef";
	if (c >= 'A' && c <= 'Z')
		info->str_bases = "0123456789ABCDEF";
	while (info->size > info->flag)
	{
		info->str[info->size - 1] = info->str_bases[ft_sign(value % base)];
		info->size--;
		value /= base;
	}
	return (info);
}

char				*ft_itoa_base(uintmax_t value, int base, char c)
{
	t_tab_itoa	*info;
	char		*res;

	if (!(info = (t_tab_itoa*)malloc(sizeof(t_tab_itoa))))
		return (0);
	info->flag = 0;
	info->size = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		info->flag = 1;
	info->tmp = value;
	while (info->tmp /= base)
		info->size++;
	info->size = info->size + info->flag + 1;
	info->str = (char *)malloc(sizeof(char) * info->size + 1);
	info->str[info->size] = '\0';
	if (info->flag == 1)
		info->str[0] = '-';
	ft_get_str(info, value, base, c);
	res = ft_strdup(info->str);
	free(info->str);
	free(info);
	return (res);
}
