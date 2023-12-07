/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:31:55 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 18:04:35 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_align_left(char **string)
{
	size_t	size;
	char	*trimmed;
	size_t	i;
	int		diff;

	size = ft_strlen(*string);
	trimmed = ft_strtrim(*string, " ");
	diff = ft_strlen(trimmed) < size;
	i = 0;
	if (diff > 0)
	{
		while (i < ft_strlen(trimmed))
		{
			(*string)[i] = trimmed[i];
			i++;
		}
		while ((*string)[i])
		{
			(*string)[i++] = ' ';
		}
	}
	free (trimmed);
}
