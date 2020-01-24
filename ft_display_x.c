/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:21 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xwidth(t_tab inf, int len)
{
	int	ret;

	ret = 0;
	if (inf.zero && !inf.minus && inf.precision < 0)
		ret += ft_display_width(inf.width - len, '0');
	else if (inf.precision >= len)
		ret += ft_display_width(inf.width - inf.precision, ' ');
	else
		ret += ft_display_width(inf.width - len, ' ');
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

int	ft_xminus(t_tab inf, int len, char *str)
{
	int	ret;

	ret = 0;
	if (inf.minus)
	{
		ret += ft_xprecision(inf.precision, len);
		ret += ft_putstr_fd(str, 1);
		ret += ft_xwidth(inf, len);
	}
	else if (!inf.minus)
	{
		ret += ft_xwidth(inf, len);
		ret += ft_xprecision(inf.precision, len);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_x(t_tab inf, va_list args, char c)
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
	if (inf.precision == 0 && *str == '0')
	{
		ret += ft_display_width(inf.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_xminus(inf, len, str);
	free(str);
	return (ret);
}
