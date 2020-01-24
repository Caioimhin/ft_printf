/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:11 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dwidht(t_tab inf, int len, int nb)
{
	int	ret;

	ret = 0;
	if (inf.zero)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			ret++;
		}
		ret += ft_display_width(inf.width - len, '0');
	}
	else if (inf.precision >= len)
	{
		if (nb < 0)
			ret += ft_display_width(inf.width - inf.precision - 1, ' ');
		else
			ret += ft_display_width(inf.width - inf.precision, ' ');
	}
	else
		ret += ft_display_width(inf.width - len, ' ');
	return (ret);
}

int	ft_dprecision(t_tab inf, int len, int nb)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (nb < 0 && inf.precision < len && !inf.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (inf.precision > 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			ret++;
			i--;
		}
		while (i++ < inf.precision - len)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_dminus(t_tab inf, int len, char *str, int nb)
{
	int	ret;

	ret = 0;
	if (nb < 0)
		str++;
	if (inf.minus)
	{
		ret += ft_dprecision(inf, len, nb);
		ret += ft_putstr_fd(str, 1);
		ret += ft_dwidht(inf, len, nb);
	}
	else if (!inf.minus)
	{
		ret += ft_dwidht(inf, len, nb);
		ret += ft_dprecision(inf, len, nb);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_d(t_tab inf, va_list args)
{
	int		nb;
	char	*str;
	int		len;
	int		ret;

	nb = va_arg(args, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	ret = 0;
	if (inf.zero && (inf.minus || inf.precision >= 0))
		inf.zero = 0;
	if (inf.precision == 0 && *str == '0')
	{
		ret += ft_display_width(inf.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_dminus(inf, len, str, nb);
	free(str);
	return (ret);
}
