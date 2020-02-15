/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 08:41:16 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:20:08 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

# define TRUE 1
# define FALSE 0

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BLACK "\x1b[30m"
# define WHITE "\x1b[37m"
# define RESET "\x1b[0m"

# define BG_BLACK "\x1b[40m"
# define BG_RED "\x1b[41m"
# define BG_GREEN "\x1b[42m"
# define BG_YELLOW "\x1b[43m"
# define BG_BLUE "\x1b[44m"
# define BG_MAGENTA "\x1b[45m"
# define BG_CYAN "\x1b[46m"
# define BG_WHITE "\x1b[47m"

# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define REVERSED "\x1b[7m"
# define ITALIC "\x1b[3m"

/*
**	flag  0-4 are 0: minus, 1: plus, 2: space, 3: zero and 4: hash
**	length 0-4 are 0: h, 1: hh, 2: l, 3: ll, 4: L, 5: z
*/

typedef struct	s_printf
{
	int			i;
	int			len;
	va_list		lst;
	char		*str;
	char		type;
	int			flag[5];
	int			precision;
	int			width;
	int			length[6];
	int			fd;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
void			ft_parse(t_printf *pf);
t_printf		*init_pf(char *str, t_printf *pf);
void			parse_flags(t_printf *pf);
void			parse_width(t_printf *pf);
void			parse_precision(t_printf *pf);
void			print_types(t_printf *pf);
int				ft_len_putchar(char c, int fd);
int				ft_len_putstr(char *str, int ignore, int fd);
char			*ft_itoa_base_us(size_t num, size_t base, char up_l);
void			put_c(t_printf *pf);
void			put_s(t_printf *pf);
void			put_p(t_printf *pf);
void			put_di(t_printf *pf);
void			put_spacing(t_printf *pf, long long i);
void			put_pros(t_printf *pf);
int				ft_nb_len_ll(long long nb, long long base);
int				ft_nb_len(size_t nb, size_t base);
void			put_o(t_printf *pf);
void			put_u(t_printf *pf);
void			put_x(t_printf *pf);
void			put_empty(t_printf *pf);
void			put_f(t_printf *pf);
void			put_b(t_printf *pf);
void			put_a(t_printf *pf);

#endif
