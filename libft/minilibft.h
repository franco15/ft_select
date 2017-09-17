/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:53:45 by lfranco-          #+#    #+#             */
/*   Updated: 2017/07/27 19:53:46 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <term.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*
** array.c
*/
void	ft_arrdel(void **arr);
size_t	ft_arrlen(void **s);
char	**ft_arrdup(char **s);

/*
** conv.c
*/
char	*ft_itoa_base(long long int n, int b);

/*
** fd.c
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putcharn_fd(int c, int n, int fd);

/*
** ft_printf.c
*/
void	ft_printf(const char *format, ...);
void	ft_printfcolor(const char *format, ...);

/*
** mem.c
*/
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_realloc(void **ptr, size_t size, size_t newsize);

/*
** mem2.c
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** put.c
*/
void	ft_putnbr(int nb);
size_t	ft_putchar(char c);
size_t	ft_putstr(char const *s);

/*
** strings.c
*/
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const	char *src);
size_t	ft_strlen(const char *s);

/*
** string2.c
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strdel(char **as);

/*
** strings3.c
*/
char	*ft_strndup(const char *s1, size_t l);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	**ft_strsplit(char const *s, char c);

/*
** term.c
*/
void	ft_termcmd(char *s);
void	ft_clearscreen(int rows);
void	ft_cursor_goto(int x, int y);
size_t	ft_max_len(char **s);

/*
** xtra.c
*/
int		ft_isallupper(char *s);
int		ft_countwords(char const *s, char c);
int		ft_wordlen(char const *s, char c);
void	ft_error(char *s);

#endif
