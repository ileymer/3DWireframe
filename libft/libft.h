/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:34:03 by dyoung            #+#    #+#             */
/*   Updated: 2020/01/12 19:14:33 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 2

size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
void				ft_bzero(void *b, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int ch, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *arr, int ch, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *str, char c);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memdup(void const *content, size_t size);
t_list				*ft_lstnew (void const *content, size_t content_size);
void				ft_swap(char *a, char *b);
void				ft_swapi(int *a, int *b);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_list);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_top
{
	char			*m;
	int				fd;
	struct s_top	*next;
}					t_meand;

typedef struct		s_topi
{
	char			*m;
	struct s_topi	*next;
}					t_oie;

t_meand				*listik(int fd);
t_oie				*listik2(void);
int					stroka(t_oie *k[3], char **line, int irg[3], t_meand *l2);
int					get_next_line(const int fd, char **line);
int					perevod(int fd, char **line, t_meand *l2);

#endif
