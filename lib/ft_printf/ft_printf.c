/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:30:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/28 17:14:45 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf_s(char *s)
{
	int	r;

	r = 0;
	if (!s)
		return (ft_printf_s("(null)"));
	while (*s)
		r += write(1, s++, 1);
	return (r);
}

int	ft_printf_int(int n, int len)
{
	if (n == -2147483648)
		return (ft_printf_s("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		len += write(1, "-", 1);
	}
	if (n)
		len = ft_printf_int(n / 10, ++len);
	else
	{
		if (len == 0)
		{
			ft_putchar_fd('0', 1);
			return (1);
		}
		return (len);
	}
	ft_putchar_fd(n % 10 + '0', 1);
	return (len);
}

int	ft_printf_base(unsigned long long u, int len, char *set, int base)
{
	if (u)
		len = ft_printf_base(u / base, ++len, set, base);
	else
	{
		if (len == 0)
		{
			ft_putchar_fd('0', 1);
			return (1);
		}
		return (len);
	}
	ft_putchar_fd(set[(u % base)], 1);
	return (len);
}

int	ft_printf_fmt(const char fmt, va_list *args)
{
	if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), 1);
		return (1);
	}
	if (fmt == 's')
		return (ft_printf_s(va_arg(*args, char *)));
	if (fmt == 'p')
		return (ft_printf_s("0x") + ft_printf_base(va_arg(*args, \
			unsigned long long), 0, "0123456789abcdef", 16));
	if (fmt == 'd' || fmt == 'i')
		return (ft_printf_int(va_arg(*args, int), 0));
	if (fmt == 'u')
		return (ft_printf_base(va_arg(*args, unsigned int), \
			0, "0123456789", 10));
	if (fmt == 'x')
		return (ft_printf_base(va_arg(*args, unsigned int), \
			0, "0123456789abcdef", 16));
	if (fmt == 'X')
		return (ft_printf_base(va_arg(*args, unsigned int), \
			0, "0123456789ABCDEF", 16));
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += ft_printf_fmt(*(++str), &args);
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	int 			n;
// 	char 			c;
// 	char			*s;
// 	unsigned int	u;
// 	unsigned int	x;
// 	int				r1;
// 	int				r2;

// 	c = 'c';
// 	n = -2147483648;
// 	s = "Hello World. )OIWEFRUWISUHR\nKLBSKhgq3p894tgjrpur3pw84ugf. Yes.";
// 	u = 4294967295;
// 	x = 4294967295;
// 	r1 = ft_printf("My print:\nc:%c\ns:%s\np:%p\nu:%u\n", c, s, NULL, u);
// 	r1 += ft_printf("i:%i\nd:%d\nx:%x\nX:%X\n%%:%%\n\n", n, n, x, x);
// 	r2 = printf("Standard:\nc:%c\ns:%s\np:%p\nu:%u\n", c, s, NULL, u);
// 	r2 += printf("i:%i\nd:%d\nx:%x\nX:%X\n%%:%%\n\n", n, n, x, x);
// 	printf("ft_printf returns: %i\nprintf returns: %i\n", r1, r2);
// 	return (0);
// }
