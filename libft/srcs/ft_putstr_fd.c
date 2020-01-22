/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:31:20 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:15:08 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
