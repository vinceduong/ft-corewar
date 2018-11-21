/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:48:46 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:25:56 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

# define BUFF_SIZE 42
# define HEX "0123456789ABCDEF"
# define HEXM "0123456789abcdef"
# define OCTAL "012345678"
# define DEC "0123456789"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char			*str;
	size_t			fd;
	struct s_gnl	*next;
}				t_gnl;

typedef struct	s_arg
{
	int		width;
	int		indextmp;
	int		index;
	int		wipr;
	int		ret;
	char	arg;
	char	flag[13];
	char	buf[4096];
}				t_arg;

char			*ft_itoa_base(int n, char *b);
int				ft_intlen_base(long nb, int base);
char			*ft_strnrev(const char *src, size_t n);
char			*ft_strrev(const char *src);
void			ft_swap(void *a);
int				ft_intlen(long nb);
int				ft_charlen(wchar_t c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t size);
char			*ft_strcdup(const char *s1, int c);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t t);
char			*ft_strnstr(const char *haystack, const char *needle,
																size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				get_next_line(const int fd, char **line);
char			*ft_read_data(int fd);
int				ft_chrstr(const char *find, char c);
int				ft_intlen_unsigned(uintmax_t n, int base);
char			*ft_pf_itoa_base(uintmax_t n, char *b, int base);
char			*ft_pf_itoa(intmax_t n);
char			*ft_putwchar(wchar_t c, int i);
int				ft_strwlen(wchar_t *str, t_arg *pf);
void			ft_print_o(va_list ag, t_arg *pf);
void			ft_flag_sc(t_arg *pf);
int				ft_display(t_arg *pf);
void			ft_print(va_list ag, t_arg *pf);
void			ft_pf_copy(char c, t_arg *pf);
t_arg			*ft_init(t_arg *pf);
void			ft_reset_flag(t_arg *pf);
void			ft_handle_flag(int n, t_arg *pf, int i, int nb);
uintmax_t		ft_cast_unsigned(va_list ag, t_arg *pf);
intmax_t		ft_cast_d(va_list ag, t_arg *pf);
int				ft_get_arg(va_list ag, t_arg *pf, const char *format);
void			ft_print_percent(t_arg *pf);
void			ft_print_bigx(va_list ag, t_arg *pf);
void			ft_print_s(va_list ag, t_arg *pf);
void			ft_print_c(va_list ag, t_arg *pf);
void			ft_print_unsigned(va_list ag, t_arg *pf);
void			ft_print_x(va_list ag, t_arg *pf);
void			ft_print_d(va_list ag, t_arg *pf);
#endif
