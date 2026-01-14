/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:12:10 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/13 16:55:58 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	nbr;
	int	i;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			signe = -signe;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + nptr[i++] - '0';
	if (signe < 0)
		return (-nbr);
	return (nbr);
}

// int main(void)
// {
// 	char *str1 = "   -1234";
// 	char *str2 = "42";
// 	char *str3 = "   +5678";
// 	char *str4 = "   2147483647";
// 	char *str5 = "   -2147483648";

// 	printf("String: '%s', Integer: %d\n", str1, ft_atoi(str1));
// 	printf("String: '%s', Integer: %d\n", str2, ft_atoi(str2));
// 	printf("String: '%s', Integer: %d\n", str3, ft_atoi(str3));
// 	printf("String: '%s', Integer: %d\n", str4, ft_atoi(str4));
// 	printf("String: '%s', Integer: %d\n", str5, ft_atoi(str5));

// 	return 0;
// }
