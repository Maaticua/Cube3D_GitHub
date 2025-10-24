/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:39:23 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/20 14:31:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 1 && c <= 127)
		return (c);
	else if (c == 0)
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	int c = 0;

// 	if (ft_isascii(c))
// 		printf("%c is an ASCII character.\n", c);
// 	else
// 		printf("%c is not an ASCII character.\n", c);

// 	return 0;
// }
