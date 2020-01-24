/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:15 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pminus(t_tab inf, int len, char *str)
{
	int	ret;

	ret = 0;
	if (inf.minus)
	{
		ret += ft_putstr_fd("0x", 1);
		ret += ft_putstr_fd(str, 1);
		ret += ft_display_width(inf.width - (len + 2), ' ');
	}
	else if (!inf.minus)
	{
		ret += ft_display_width(inf.width - (len + 2), ' ');
		ret += ft_putstr_fd("0x", 1);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_p(t_tab inf, va_list args)
{
	char				*str;
	int					len;
	int					ret;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_itoa_base(nb, 16, 'a');
	len = ft_strlen(str);
	ret = 0;
	ret += ft_pminus(inf, len, str);
	free(str);
	return (ret);
}
