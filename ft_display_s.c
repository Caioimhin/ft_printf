/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:18 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:50 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprecision(char *str, int len, int precision, int mod)
{
	int	i;

	i = 0;
	if (precision != -1 && len <= precision)
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else if (precision != -1 && len > precision)
		while (i < precision)
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	return (i);
}

int		ft_swidth(int zero, int width)
{
	int ret;

	ret = 0;
	if (zero)
		ret += ft_display_width(width, '0');
	else
		ret += ft_display_width(width, ' ');
	return (ret);
}

char	*ft_special_case(char *str, t_tab inf, int *spec)
{
	*spec = 0;
	if (!str && inf.precision)
	{
		str = ft_strdup("(null)");
		*spec = 1;
	}
	else if (!str && !inf.precision)
	{
		str = ft_strdup("");
		*spec = 1;
	}
	return (str);
}

int		ft_display_s(t_tab inf, va_list args)
{
	char	*str;
	int		len;
	int		ret;
	int		howm;
	int		spec;

	ret = 0;
	str = va_arg(args, char *);
	str = ft_special_case(str, inf, &spec);
	len = ft_strlen(str);
	howm = ft_sprecision(str, len, inf.precision, 0);
	if (inf.minus && inf.width > howm)
	{
		ret += ft_sprecision(str, len, inf.precision, 1);
		ret += ft_swidth(inf.zero, (inf.width - howm));
	}
	else if (!inf.minus && inf.width > howm)
	{
		ret += ft_swidth(inf.zero, (inf.width - howm));
		ret += ft_sprecision(str, len, inf.precision, 1);
	}
	else
		ret += ft_sprecision(str, len, inf.precision, 1);
	(spec == 1) ? free(str) : 0;
	return (ret);
}
