/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:37:59 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/12 12:40:55 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (c);
	else
		return (0);
}
// #include <stdio.h>

// int main()
// {
// 	char testChar = '5';
// 	if (ft_isdigit(testChar))
// 		printf("%c is a digit.\n", testChar);
// 	else
// 		printf("%c is not a digit.\n", testChar);

// 	return 0;
// }
