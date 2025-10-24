/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:52:10 by awaegaer          #+#    #+#             */
/*   Updated: 2024/11/28 14:52:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*mapi;

	len = ft_strlen(s);
	i = 0;
	mapi = malloc (len + 1);
	if (!mapi)
		return (NULL);
	while (i < len)
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
/*
#include <stdio.h>

char my_func(unsigned int i, char c)
{
	return (c + i);
}

int main()
{
	char str[] = "Hello";
	char *result = ft_strmapi(str, my_func);
	if (result)
	{
		printf("Original: %s\n", str);
		printf("Modified: %s\n", result);
		free(result);
	}
	return 0;
}
*/
