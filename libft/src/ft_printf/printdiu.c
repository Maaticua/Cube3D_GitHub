/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdiu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:11:12 by awaegaer          #+#    #+#             */
/*   Updated: 2024/12/10 15:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printdiu(long long nbr, char c)
{
	int	ret;

	ret = 0;
	if (c == 'u')
		nbr = (unsigned int) nbr;
	if (nbr < 0)
	{
		nbr = -nbr;
		ret += write(1, "-", 1);
	}
	if (nbr >= 10)
		ret += printdiu(nbr / 10, c);
	ret += printc(nbr % 10 + '0');
	return (ret);
}
