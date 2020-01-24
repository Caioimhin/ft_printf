/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:28 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct	s_tab
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			len;
}				t_tab;

int				ft_printf(const char *format, ...);
int				normal_char(char c);
int				ft_display_c(t_tab inf, va_list args);
t_tab			ft_initialize(t_tab inf);
int				ft_send_displays(char c, t_tab inf, va_list args);
int				ft_flag(char c);
t_tab			ft_treat_star(t_tab inf, va_list args);
t_tab			ft_treatment_flag(char format, t_tab inf, va_list args);
t_tab			parser_flags(const char *format, t_tab inf, va_list args);
int				ft_display_width(int width, char c);
t_tab			ft_parser_flag(const char *format, t_tab inf);
int				ft_display_s(t_tab inf, va_list args);
char			*ft_special_case(char *s, t_tab inf, int *spec);
int				ft_swidth(int zero, int width);
int				ft_sprecision(char *s, int len, int precision, int mod);
int				ft_display_p(t_tab inf, va_list args);
int				ft_pminus(t_tab inf, int len, char *s);
int				ft_display_d(t_tab inf, va_list args);
int				ft_dminus(t_tab inf, int len, char *s, int num);
int				ft_dprecision(t_tab inf, int len, int num);
int				ft_dwidht(t_tab inf, int len, int num);
int				ft_display_u(t_tab inf, va_list args);
int				ft_unsign_minus(t_tab inf, int len, char *s);
int				ft_unsign_precision(int precision, int len);
int				ft_unsign_width(t_tab inf, int len);
int				ft_display_x(t_tab inf, va_list args, char c);
int				ft_xminus(t_tab inf, int len, char *s);
int				ft_xprecision(int precision, int len);
int				ft_xwidth(t_tab inf, int len);
int				ft_display_others(t_tab inf);
int				put_ullnbr(unsigned long long nb, char *base, char *str, int l);
#endif
