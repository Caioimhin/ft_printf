/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:19 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 12:12:23 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign_width(t_tab tab, int len)
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

int	ft_unsign_precision(int precision, int len)
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

int	ft_unsign_minus(t_tab tab, int len, char *str)
{
	int	ret;

	ret = 0;
	if (tab.minus)
	{
		ret += ft_unsign_precision(tab.precision, len);
		ret += ft_putstr_fd(str, 1);
		ret += ft_unsign_width(tab, len);
	}
	else if (!tab.minus)
	{
		ret += ft_unsign_width(tab, len);
		ret += ft_unsign_precision(tab.precision, len);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_u(t_tab tab, va_list args)
{
	char	*str;
	int		len;
	int		ret;

	str = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	ret = 0;
	if (tab.precision == 0 && *str == '0')
	{
		ret += ft_dispalay_width(tab.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_unsign_minus(tab, len, str);
	free(str);
	return (ret);
}
