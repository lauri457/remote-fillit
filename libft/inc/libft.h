/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:19 by lharkala          #+#    #+#             */
/*   Updated: 2022/04/07 11:07:56 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 120
# define MAX_FD 1024
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

int		is_lower(int c);
int		is_upper(int c);
int		is_alpha(int c);
int		is_digit(int c);
int		is_alnum(int c);
int		is_ascii(int c);
int		is_print(int c);
int		is_space(int c);

void	*v_set(void *s, int c, size_t n);
void	v_bzero(void *s, size_t n);
void	*v_cpy(void *dest, const void *src, size_t n);
void	*v_chr(const void *s, int c, size_t n);
void	*v_ccpy(void *dest, const void *src, int c, size_t n);
void	*v_move(void *dest, const void *src, size_t n);
int		v_cmp(const void *s1, const void *s2, size_t n);
void	*v_alloc(size_t size);
void	v_del(void **ap);

int		c_toupper(int c);
int		c_tolower(int c);
int		c_atoi(const char *str);
char	*c_itoa(int n);

void	fd_putchar(char c, int fd);
void	fd_putstr(char const *s, int fd);
void	fd_putendl(char const *s, int fd);
void	fd_putnbr(int nb, int fd);
int		fd_getline(const int fd, char **line);

t_list	*l_new(void const *content, size_t content_size);
void	l_delone(t_list **alst, void (*del)(void*, size_t));
void	l_del(t_list **alst, void (*del)(void*, size_t));
void	l_add(t_list **alst, t_list *new);
void	l_iter(t_list *lst, void (*f)(t_list *elem));
t_list	*l_map(t_list *lst, t_list *(*f)(t_list *elem));

size_t	s_len(const char *s);
char	*s_dup(const char *s);
char	*s_cpy(char *dest, const char *src);
char	*s_ncpy(char *dest, const char *src, size_t n);
char	*s_cat(char *dest, const char *src);
char	*s_ncat(char *dest, const char *src, size_t n);
size_t	s_lcat(char *dest, const char *src, size_t size);
char	*s_chr(const char *s, int c);
char	*s_rchr(const char *s, int c);
int		s_cmp(const char *s1, const char *s2);
int		s_ncmp(const char *s1, const char *s2, size_t n);
char	*s_str(const char *haystack, const char *needle);
char	*s_nstr(const char *haystack, const char *needle, size_t len);
char	*s_new(size_t size);
void	*v_calloc(size_t count, size_t size);
char	*s_new(size_t size);
void	s_del(char **as);
void	s_clr(char *s);
void	s_iter(char *s, void (*f)(char *));
void	s_iteri(char *s, void (*f)(unsigned int, char *));
char	*s_map(char const *s, char (*f)(char));
char	*s_mapi(char const *s, char (*f)(unsigned int, char));
int		s_equ(char const *s1, char const *s2);
int		s_nequ(char const *s1, char const *s2, size_t n);
char	*s_sub(char const *s, unsigned int start, size_t len);
char	*s_join(char const *s1, char const *s2);
char	*s_trim(char const *s);
char	**s_split(char const *s, char c);
size_t	s_lcpy(char *dst, const char *src, size_t size);

#endif
