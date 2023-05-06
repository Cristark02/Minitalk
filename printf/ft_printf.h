/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:52:10 by mmita             #+#    #+#             */
/*   Updated: 2023/01/28 19:14:47 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UPP_BASE "0123456789ABCDEF"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(char const *print, ...);
void	ft_printchar(char c, int *i);
void	ft_printstr(char *print, int *i);
void	ft_printdori(int n, int *i);
void	ft_printunsig(unsigned int n, int *i);
void	ft_printhex(unsigned long long n, int *count, char *base);

#endif