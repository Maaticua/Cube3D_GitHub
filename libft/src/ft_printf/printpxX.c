/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:10:51 by awaegaer          #+#    #+#             */
/*   Updated: 2024/12/10 15:21:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpxx(unsigned long nbr, char c, int prefix)
{
	int		ret;
	char	*bhex;

	ret = 0;
	if (prefix)
	{
		if (!nbr)
			return (write(1, "(nil)", 5));
		ret += write(prefix--, "0x", 2);
		bhex = "0123456789abcdef";
	}
	else if (c == 'x' || c == 'p')
		bhex = "0123456789abcdef";
	else
		bhex = "0123456789ABCDEF";
	if (c == 'x' || c == 'X')
		nbr = (unsigned int) nbr;
	if (nbr >= 16)
		ret += printpxx(nbr / 16, c, prefix);
	ret += write(1, bhex + (nbr % 16), 1);
	return (ret);
}
