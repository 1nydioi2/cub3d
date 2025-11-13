/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:28:08 by jutocche          #+#    #+#             */
/*   Updated: 2025/10/11 11:16:32 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long				ft_atoi_long(const char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int character);
int					ft_isalpha(int character);
int					ft_isascii(int character);
int					ft_isdigit(int character);
int					ft_isprint(int character);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *p1, const void *p2, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t l);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int character);
int					ft_toupper(int character);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// get_next_line
char				*get_next_line(int fd);
char				*process_remainder(char **remainder_ptr);
char				*process_buffer(char *line, char *buffer,
						char **remainder_ptr);
char				*read_and_process(int fd, char *line, char **remainder_ptr);

// ft_printf
int					ft_printf(const char *format, ...);
int					format_management(const char *format, va_list args, int i);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putnbr(int n);
int					ft_putnbr_base(unsigned int nbr, char *base);
int					ft_ptr_base(void *ptr, char *base);
int					ft_putnbr_base_ptr(long unsigned int nbr, char *base);

// minishell
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *s2, char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strndup(const char *s, size_t n);

#endif
