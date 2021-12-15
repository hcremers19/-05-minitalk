/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:46:14 by hcremers          #+#    #+#             */
/*   Updated: 2021/12/15 11:46:16 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <signal.h>

int		ft_printf(const char *str, ...);
int		ft_printf_putchar(char c, int count);
int		ft_printf_putstr(char *str, int count);
int		ft_printf_putnbr(int i, int count);
int		ft_printf_putunbr(unsigned int i, int count);
int		ft_printf_putnbr_base(unsigned int i, int count, char c);
int		ft_printf_putaddress(unsigned long i, int count);
int		ft_intlen(int n);
size_t	ft_strlen(const char *s);
int		ft_uintlen(unsigned int n);
int		ft_uintlen_base(unsigned long n, int base);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putlong_base(unsigned long nbr, char *base);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
