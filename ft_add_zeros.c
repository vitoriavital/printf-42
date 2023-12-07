/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:01:40 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 17:59:03 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_add_zeros(char spec, char **string, int num)
{
	int		i;

	i = 0;
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'X' || spec == 'x')
	{
		while (i < num)
		{
			(*string)[i++] = '0';
		}
	}
}
