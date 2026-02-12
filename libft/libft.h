/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:33:19 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:28:46 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
// # define INT_MIN -2147483648

# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_putnbr_unsigned_fd(unsigned int nb, size_t h);
size_t	ft_puthexx_fd(unsigned int nb, size_t	h);
size_t	ft_puthex_fd(unsigned int nb, size_t	h);
size_t	ft_strlen(const char *str);
size_t	ft_putchar(char c);
size_t	ft_putnbr(int nb, size_t h);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_bzero(void *s, size_t n);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(char c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_printf(const char *s, ...);
int		ft_lstsize(t_list *lst);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

#endif