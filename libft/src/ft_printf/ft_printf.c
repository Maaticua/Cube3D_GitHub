/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:36 by awaegaer          #+#    #+#             */
/*   Updated: 2025/03/27 17:56:22 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_if(const char c, va_list args)
{
	int	cpt;

	cpt = 0;
	if (c == 'c')
		cpt += printc(va_arg(args, int));
	else if (c == 's')
		cpt += prints(va_arg(args, char *));
	else if (c == 'p')
		cpt += printpxx(va_arg(args, unsigned long), 'p', 1);
	else if (c == 'd')
		cpt += printdiu(va_arg(args, int), 'd');
	else if (c == 'i')
		cpt += printdiu(va_arg(args, int), 'i');
	else if (c == 'u')
		cpt += printdiu(va_arg(args, int), 'u');
	else if (c == 'x')
		cpt += printpxx(va_arg(args, unsigned long), 'x', 0);
	else if (c == 'X')
		cpt += printpxx(va_arg(args, unsigned long), 'X', 0);
	else if (c == '%')
		cpt += printc(c);
	else
		return (-1);
	return (cpt);
}

int	ft_printf(const char *s, ...)
{
	int		ret;
	size_t	i;
	va_list	args;

	ret = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ret += ft_printf_if(s[++i], args);
			i++;
		}
		else
			ret += write(1, s + i++, 1);
	}
	va_end(args);
	return (ret);
}

// #include <limits.h>

// int	main(void)
// {
// 	int moi = ft_printf("%%%");
// 	printf("\n");
// 	int vrai = printf("%%%");
// 	printf("\n");
// 	 printf("moi: %d, vrai: %d", moi, vrai);
// }
