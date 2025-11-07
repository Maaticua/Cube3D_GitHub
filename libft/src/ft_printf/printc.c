/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:56:34 by awaegaer          #+#    #+#             */
/*   Updated: 2024/12/10 12:38:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printc(char c)
{
	return (write(1, &c, 1));
}

// int	main(int argc, char **argv)
// {
// 	int	ret;

// 	if (argc > 1)
// 	{
// 		ret = printc(argv[1][0]);
// 		printf("Return value: %d\n", ret);
// 	}
// 	else
// 	{
// 		printf("Usage: %s <character>\n", argv[0]);
// 	}
// 	return (0);
// }
