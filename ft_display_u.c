/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:19 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign_width(t_tab inf, int len)
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

int	ft_unsign_minus(t_tab inf, int len, char *str)
{
	int	ret;

	ret = 0;
	if (inf.minus)
	{
		ret += ft_unsign_precision(inf.precision, len);
		ret += ft_putstr_fd(str, 1);
		ret += ft_unsign_width(inf, len);
	}
	else if (!inf.minus)
	{
		ret += ft_unsign_width(inf, len);
		ret += ft_unsign_precision(inf.precision, len);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_u(t_tab inf, va_list args)
{
	char	*str;
	int		len;
	int		ret;

	str = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	ret = 0;
	if (inf.precision == 0 && *str == '0')
	{
		ret += ft_display_width(inf.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_unsign_minus(inf, len, str);
	free(str);
	return (ret);
}
