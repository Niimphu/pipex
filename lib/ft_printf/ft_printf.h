/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:23:51 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/27 19:23:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf_s(char *s);
int	ft_printf_base(unsigned int long long u, int len, char *set, int base);
int	ft_printf_fmt(const char fmt, va_list *args);
int	ft_printf(const char *str, ...);

#endif