/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:14:00 by awaegaer          #+#    #+#             */
/*   Updated: 2025/02/27 13:34:53 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *s, ...);
int		printc(char c);
int		prints(char *s);
int		printpxx(unsigned long nbr, char c, int prefix);
int		printdiu(long long nbr, char c);
size_t	pf_strlen(const char *s);

#endif
