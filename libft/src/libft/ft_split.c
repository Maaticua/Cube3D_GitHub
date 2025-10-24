/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:04:59 by awaegaer          #+#    #+#             */
/*   Updated: 2025/06/20 14:29:45 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static char	*allocate_word(char const *s, size_t j, size_t i)
{
	char	*word;

	word = malloc(i - j + 1);
	if (word)
		ft_strlcpy(word, &s[j], i - j + 1);
	return (word);
}

static void	*ft_free_split(char **res, size_t k)
{
	while (k--)
		free(res[k]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	utils[4];

	utils[2] = ((utils[0] = 0));
	utils[3] = ft_countwords(s, c);
	res = malloc(sizeof(char *) * (utils[3] + 1));
	if (!res)
		return (NULL);
	while (s[utils[0]])
	{
		while (s[utils[0]] && s[utils[0]] == c)
			utils[0]++;
		utils[1] = utils[0];
		while (s[utils[0]] && s[utils[0]] != c)
			utils[0]++;
		if (utils[0] > utils[1])
		{
			res[utils[2]] = allocate_word(s, utils[1], utils[0]);
			if (!res[utils[2]++])
				return (ft_free_split(res, utils[2] - 1));
		}
	}
	res[utils[2]] = NULL;
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	size_t	i;

	result = ft_split("Hello world this is a test", ' ');
	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("result[%zu]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
