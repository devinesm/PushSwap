/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:43:43 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 11:12:09 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

/*
 * size_t usage - variable to count things in memory
 * malloc usage - function used for dynamic memory allocation
 */
# include <stdlib.h>
/*
 * write usage
 */
# include <unistd.h>

/**/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 * <ctype.h> functions
*/

/*
 * ft_is...
 * return: 1 if it's | 0 if it's not
 *
 * obs: in the originals functions, 
 * if the argument is validated as true,
 * it will return a number different of 0
 */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/*
 * ft_to...
 * return: all lower/upper case
*/
int		ft_toupper(int c);
int		ft_tolower(int c);

/**/

/*
 * <string.h>
 */

/*
 * ft_strlen
 * return: size of string
 */
size_t	ft_strlen(const char *s);
/*
 * ft_memset
 * return: return a generic pointer to str
 */
void	*ft_memset(void *s, int c, size_t m);
/*
 * ft_bzero
 * return: return a generic pointer to str
 *
 * obs: ft_memset usage
 */
void	ft_bzero(void *s, size_t n);
/*
 * ft_memcpy
 * return: return a generic pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/*
 * ft_memmove
 * return: return a generic pointer to dest
 *
 * obs: ft_memcpy usage
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/*
 * ft_strlcpy
 * return: return the src length. 
 *
 * obs: Why the return is the src length?
 * If the returned value is greater or equal to the size,
 * it means that the string didn't fit or has been cutted.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*
 * ft_strlcat
 * return: return the total length of the string it tried to creat.
 * */
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/*
 * ft_strchr
 * return: returns the first occurance of the character in the string,
 * also the characther can be '\0'.
 */
char	*ft_strchr(const char *s, int c);
/*
 * ft_strrchr
 * return: returns the last occurance of the character in the string.
 *
 * obs: Protection of size_t -> As size_t does not accept negative numbers,
 * if it was while (index >= 0), when index--, it would turn negative.
 */
char	*ft_strrchr(const char *s, int c);
/*
 * ft_strncmp
 * return: if s1 and s2 are equal, it returns 0.
 * otherwise it returns the ascii difference between them
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*
 * ft_memchr
 * return: returns a specific byte in a memory block, regardless of
 * what's inside (can be text, numbers, e.g.).
 */
void	*ft_memchr(const void *s, int c, size_t n);
/*
 * ft_memcmp.c
 * return: returns the difference between two pieces of memory at a specific byte
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
 * ft_strnstr
 * return: returns haystack if needle is empty or returns the pointer to the
 * beggining of the word in the haystack
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*
 * ft_strdup
 * return: it creates a space for the memory and allocates with the copy str
 */
char	*ft_strdup(const char *s);

/**/

/*
 * <stdlib.h>
*/

/*
 * ft_atoi
 * return: returns the interger of a given string(ascii)
 *
 * obs: use of long to prevent overflow
 */
int		ft_atoi(const char *nptr);
/*
 * ft_calloc
 * return: reserves a piece of memory and fill it with zeros.
 * after that, returns the memory
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**/

/*
 * additional functions
 */

/*
 * ft_substr
 * return: char pointer with a extract of the initial string
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*
 * ft_strjoin
 * return: cat of two strings with alocated memory
 */
char	*ft_strjoin(char const *s1, char const *s2);
/*
 * ft_strtrim
 * return: char pointer to the trim version of the str.
 * it removes specific characters in the start and end of
 * a string
 */
char	*ft_strtrim(char const *s1, char const *set);
/*
 * ft_split
 * returns: double pointer that splits a string in a char
 * and the keeps the substring in an array
 */
char	**ft_split(char const *s, char c);
/*
 * ft_itoa
 * return: converts an interger to a string
 */
char	*ft_itoa(int n);
/*
 * ft_strmapi
 * return: it creates a new string based on the original one,
 * applying a function to which character
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
 * ft_striteri
 * return: same as last, but in the original strin
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
 * ft_putchar_fd
 * return: non.
 */
void	ft_putchar_fd(char c, int fd);
/*
 * ft_putstr_fd
 * return: non.
 */
void	ft_putstr_fd(char *s, int fd);
/*
 * ft_putendl_fd
 * return: non
 */
void	ft_putendl_fd(char *s, int fd);
/*
 * ft_putnbr_fd
 * return: non
 * */
void	ft_putnbr_fd(int n, int fd);

/**/

/*
 * linked list
 */

/*
 * ft_lstnew
 * return: new node pointer
 */
t_list	*ft_lstnew(void *content);
/*
 * ft_lstadd_front
 * return: non
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/*
 * ft_lstsize
 * return: amount of nodes in a list
 */
int		ft_lstsize(t_list *lst);
/*
 * ft_lstlast
 * return: last node of list
 */
t_list	*ft_lstlast(t_list *lst);
/*
 * ft_lstadd_back
 * return: non
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/*
 * ft_lstdelone
 * return: non
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*
 * ft_lstclear
 * return: non
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/*
 * ft_lstiter
 * return: non
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/*
 * ft_lstmap
 * return: new list with node modified by a function
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
