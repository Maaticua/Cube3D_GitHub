/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:59:26 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/12 12:13:54 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	else
		return (0);
}
// #include <stdio.h>

// int main()
// {
// 	char testChar = '5';
// 	if (ft_isalpha(testChar))
// 		printf("%c is an alphabetic character.\n", testChar);
// 	else
// 		printf("%c is not an alphabetic character.\n", testChar);

// 	return 0;
// }
