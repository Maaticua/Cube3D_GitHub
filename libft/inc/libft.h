/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:08:04 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/09 15:57:18 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "pipex.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
// Checks if the character is alphabetic
int					ft_isdigit(int c);
// Checks if the character is a digit
int					ft_isalnum(int c);
// Checks if the character is alphanumeric
int					ft_isascii(int c);
// Checks if the character is an ASCII character
int					ft_isprint(int c);
// Checks if the character is printable
int					ft_toupper(int c);
// Converts a character to uppercase
int					ft_tolower(int c);
// Converts a character to lowercase
int					ft_strncmp(const char *s1, const char *s2, size_t n);
// Compares two strings up to n characters
int					ft_strcmp(const char *s1, const char *s2);
// compares two strings
int					ft_memcmp(const void *s1, const void *s2, size_t n);
// Compares two memory areas
int					ft_atoi(const char *nptr);
// Converts a string to an integer
int					ft_abs(int n);
// Calcul de la valeur absolue d'un entier.
size_t				ft_strlen(const char *s);
// Returns the length of a string
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
// Copies a string to a buffer with size limit
size_t				ft_strlcat(char *dst, const char *src, size_t size);
// Concatenates a string to a buffer with size limit

void				*ft_memset(void *s, int c, size_t n);
// Fills memory with a constant byte
void				ft_bzero(void *s, size_t n);
// Sets memory to zero
void				*ft_memcpy(void *dest, const void *src, size_t n);
// Copies memory area
void				*ft_memmove(void *dest, const void *src, size_t n);
// Moves memory area
void				*ft_memchr(const void *s, int c, size_t n);
// Scans memory for a character
void				*ft_calloc(size_t nmemb, size_t size);
// Allocates memory and sets it to zero

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
// Applies a function to each character of a string
void				ft_putchar_fd(char c, int fd);
// Outputs a character to a file descriptor
void				ft_putstr_fd(char *s, int fd);
// Outputs a string to a file descriptor
void				ft_putnbr_fd(int n, int fd);
// Outputs an integer to a file descriptor
void				ft_putendl_fd(char *s, int fd);
// Outputs a string to a file descriptor, followed by a newline

char				*ft_strchr(const char *s, int c);
// Finds the first occurrence of a character in a string
char				*ft_strrchr(const char *s, int c);
// Finds the last occurrence of a character in a string
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
// Locates a substring in a string with length limit
char				*ft_strdup(const char *s);
// Duplicates a string
char				*ft_substr(char const *s, unsigned int start, size_t len);
// Extracts a substring from a string
char				*ft_strjoin(char const *s1, char const *s2);
// Joins two strings into a new string
char				*ft_strtrim(char const *s1, char const *set);
// Trims characters from the beginning and end of a string
char				**ft_split(char const *s, char c);
// Splits a string into an array of strings using a delimiter
char				*ft_itoa(int n);
// Converts an integer to a string
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Applies a function to each character of a string to create a new string

#endif
