/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:45:01 by mmita             #+#    #+#             */
/*   Updated: 2023/01/28 18:24:36 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned long long n, int *i, char *base)
{
	if (n > 15)
	{
		ft_printhex((n / 16), i, base);
		ft_printhex((n % 16), i, base);
	}
	else
		ft_printchar(base[n], i);
}
