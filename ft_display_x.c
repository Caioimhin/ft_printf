/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:21 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 12:10:54 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xwidth(t_tab tab, int len)
{
	int	ret;

	ret = 0;
	if (tab.zero && !tab.minus && tab.precision < 0)
		ret += ft_dispalay_width(tab.width - len, '0');
	else if (tab.precision >= len)
		ret += ft_dispalay_width(tab.width - tab.precision, ' ');
	else
		ret += ft_dispalay_width(tab.width - len, ' ');
	return (ret);
}

int	ft_xprecision(int precision, int len)
{
	int	i;

	i = 0;
	if (precision)
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

int	ft_xminus(t_tab tab, int len, char *str)
{
	int	ret;

	ret = 0;
	if (tab.minus)
	{
		ret += ft_xprecision(tab.precision, len);
		ret += ft_putstr_fd(str, 1);
		ret += ft_xwidth(tab, len);
	}
	else if (!tab.minus)
	{
		ret += ft_xwidth(tab, len);
		ret += ft_xprecision(tab.precision, len);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_x(t_tab tab, va_list args, char c)
{
	char			*str;
	int				len;
	int				ret;
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	if (!nb)
		str = ft_strdup("0");
	else
	{
		ft_isupper(c) ? c = 'X' : 0;
		str = ft_itoa_base(nb, 16, c);
	}
	len = ft_strlen(str);
	ret = 0;
	if (tab.precision == 0 && *str == '0')
	{
		ret += ft_dispalay_width(tab.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_xminus(tab, len, str);
	free(str);
	return (ret);
}
