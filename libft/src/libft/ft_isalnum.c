/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:12:06 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:47:12 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (c);
	else
		return (0);
}

// int	main(void)
// {
// 	int c;

// 	c = 'A';
// 	if (ft_isalnum(c))
// 		printf("%c is alphanumeric\n", c);
// 	else
// 		printf("%c is not alphanumeric\n", c);

// 	c = '5';
// 	if (ft_isalnum(c))
// 		printf("%c is alphanumeric\n", c);
// 	else
// 		printf("%c is not alphanumeric\n", c);

// 	c = '$';
// 	if (ft_isalnum(c))
// 		printf("%c is alphanumeric\n", c);
// 	else
// 		printf("%c is not alphanumeric\n", c);

// 	return (0);
// }
