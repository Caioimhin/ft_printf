/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrumax_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:46:27 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:15:08 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbrumax_fd(uintmax_t n, int fd)
{
	if (n > 9)
		ft_putnbrumax_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
