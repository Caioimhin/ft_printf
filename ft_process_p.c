/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:27:43 by kparis            #+#    #+#             */
/*   Updated: 2019/10/24 17:39:07 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_p(void *p)
{
	unsigned int	*adress;
	char			*str;
	char			*str2;

	str = 0;
	str2 = 0;
	adress = (unsigned int *)&p;
	if (p != 0)
		str = ft_strdup("0x10");
	else
		str = ft_strdup("0x0");
	str2 = ft_putnbr_base(*adress, "0123456789abcdef");
	return (ft_strjoin(str, str2));
}
