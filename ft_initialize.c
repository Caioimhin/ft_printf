/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:23 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 17:30:09 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	ft_initialize(t_tab tab)
{
	tab.minus = 0;
	tab.zero = 0;
	tab.width = 0;
	tab.dot = 0;
	tab.precision = -1;
	return (tab);
}
