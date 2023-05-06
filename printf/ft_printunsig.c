/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:56:20 by mmita             #+#    #+#             */
/*   Updated: 2023/01/28 19:18:10 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunsig(unsigned int n, int *i)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_printunsig(n / 10, i);
		n = n % 10;
	}
	if (n < 10)
		ft_printchar(n + 48, i);
}
