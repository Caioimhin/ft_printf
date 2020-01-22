/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:11 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 17:30:23 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dwidht(t_tab tab, int len, int nb)
{
	int	ret;

	ret = 0;
	if (tab.zero)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			ret++;
		}
		ret += ft_dispalay_width(tab.width - len, '0');
	}
	else if (tab.precision >= len)
	{
		if (nb < 0)
			ret += ft_dispalay_width(tab.width - tab.precision - 1, ' ');
		else
			ret += ft_dispalay_width(tab.width - tab.precision, ' ');
	}
	else
		ret += ft_dispalay_width(tab.width - len, ' ');
	return (ret);
}

int	ft_dprecision(t_tab tab, int len, int nb)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (nb < 0 && tab.precision < len && !tab.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (tab.precision > 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			ret++;
			i--;
		}
		while (i++ < tab.precision - len)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_dminus(t_tab tab, int len, char *str, int nb)
{
	int	ret;

	ret = 0;
	if (nb < 0)
		str++;
	if (tab.minus)
	{
		ret += ft_dprecision(tab, len, nb);
		ret += ft_putstr_fd(str, 1);
		ret += ft_dwidht(tab, len, nb);
	}
	else if (!tab.minus)
	{
		ret += ft_dwidht(tab, len, nb);
		ret += ft_dprecision(tab, len, nb);
		ret += ft_putstr_fd(str, 1);
	}
	return (ret);
}

int	ft_display_d(t_tab tab, va_list args)
{
	int		nb;
	char	*str;
	int		len;
	int		ret;

	nb = va_arg(args, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	ret = 0;
	if (tab.zero && (tab.minus || tab.precision >= 0))
		tab.zero = 0;
	if (tab.precision == 0 && *str == '0')
	{
		ret += ft_dispalay_width(tab.width, ' ');
		free(str);
		return (ret);
	}
	ret += ft_dminus(tab, len, str, nb);
	free(str);
	return (ret);
}
