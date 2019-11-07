/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:10:22 by kparis            #+#    #+#             */
/*   Updated: 2019/11/07 12:50:04 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define EQUAL_LIST str[i] == 'd' || str[i] == 'i' || str[i] == 'u'\
	|| str[i] == 'x' || str[i] == 'X' || str[i] == 'p'\
	|| str[i] == 'c' || str[i] == 's'

char	*ft_process_percent(void);
char	*ft_process_bigx(int nbr);
char	*ft_process_c(char c);
char	*ft_process_d(int nbr);
char	*ft_process_p(void *p);
char	*ft_process_s(char *str);
char	*ft_process_x(int nbr);
char	*ft_process_u(unsigned int nbr);
char	*ft_process_star(size_t i, char *str, va_list va);
char	*ft_process_basics(char c, va_list va);
char	*trunc_str(char *str, va_list va, char **args);
char	*check_useless_0(char *str);
char	*remove_doubledash(char *str);
char	*ft_process_dots(char *str, int i, char **args, int arg_count);
void	ft_display_str(char *str);
char	*ft_replace_flags(char *str2, char **args);
char	*ft_process_dash(char *str, char **args, int arg_count, int dash);
char	*ft_process_num(char *str, int i, char **args, int arg_count);
#endif
