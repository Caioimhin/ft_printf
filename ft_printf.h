/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:32 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 17:12:45 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct	s_struct
{
	const char	*fmt;
	char		*f_copy;
	char		*f_t;
	va_list		arg;
	int			len;
	int			i;
	char		*specifiers;
	char		specifiers_flags;
	char		*converters;
	char		convert[7];
	long int	widht;
	long int	precision;
	int			j;
	int			k;
	int			l;
	int			m;
	int			n;
	int			o;
	int			p;
}				t_struct;

int				ft_printf(const char *fmt, ...);
t_struct			*ft_initialize(t_struct *info);
int				ft_parsers(t_struct *info);
t_struct			*ft_reinitialize(t_struct *info);
t_struct			*ft_parse_converts(t_struct *info);
t_struct			*ft_parse_converts2(t_struct *info);
t_struct			*ft_parse_specifiers(t_struct *info);
int				ft_treatments(t_struct *info);
t_struct			*ft_send_displays(t_struct *info);
t_struct			*ft_parse_widht(t_struct *info);
t_struct			*ft_display_c(t_struct *info);
t_struct			*ft_display_d(t_struct *info);
t_struct			*ft_display_u(t_struct *info);
int				ft_display_widht(t_struct *info, char c, int len, int update_len);
t_struct			*ft_display_s(t_struct *info);
t_struct			*ft_display_x(t_struct *info);
t_struct			*ft_display_p(t_struct *info);
t_struct			*ft_display_(t_struct *info);
t_struct			*ft_parse_precision(t_struct *info);
t_struct			*ft_prec_and_width(t_struct *info, intmax_t num, char sign_place);
#endif
