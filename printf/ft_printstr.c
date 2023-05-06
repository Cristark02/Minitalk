/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:34:09 by mmita             #+#    #+#             */
/*   Updated: 2023/01/28 16:45:53 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *print, int *i)
{
	if (print == NULL)
		ft_printstr("(null)", i);
	else
	{
		while (*print != '\0')
		{
			ft_printchar(*print, i);
			print++;
		}
	}
}
