/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:26:32 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 11:43:17 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct	s_stc
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
}				t_stc;

int				ft_printf(const char *fmt, ...);
t_stc			*ft_initialize(t_stc *inf);
int				ft_parsers(t_stc *inf);
t_stc			*ft_reinitialize(t_stc *inf);
t_stc			*ft_parse_converts(t_stc *inf);
t_stc			*ft_parse_converts2(t_stc *inf);
t_stc			*ft_parse_specifiers(t_stc *inf);
int				ft_treatment(t_stc *inf);
t_stc			*ft_send_displays(t_stc *inf);
t_stc			*ft_parse_widht(t_stc *inf);
t_stc			*ft_display_c(t_stc *inf);
t_stc			*ft_display_d(t_stc *inf);
t_stc			*ft_display_u(t_stc *inf);
int				ft_display_widht(t_stc *inf, char c, int len, int update_len);
t_stc			*ft_display_s(t_stc *inf);
t_stc			*ft_display_x(t_stc *inf);
t_stc			*ft_display_p(t_stc *inf);
t_stc			*ft_display_(t_stc *inf);
t_stc			*ft_parse_precision(t_stc *inf);
t_stc			*ft_prec_and_width(t_stc *inf, intmax_t num, char sign_place);
#endif
