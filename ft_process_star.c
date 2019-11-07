/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_star.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:23:25 by kparis            #+#    #+#             */
/*   Updated: 2019/11/01 12:15:29 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_star(size_t i, char *str, va_list va)
{
	char	*str2;
	char	*str3;
	size_t	mem;

	str2 = 0;
	str3 = 0;
	mem = i;
	str2 = ft_strdup(str);
	str2[i] = '\0';
	str3 = ft_process_basics('d', va);
	str2 = ft_strjoin(str2, str3);
	return (ft_strjoin(str2, &str[i + 1]));
}
