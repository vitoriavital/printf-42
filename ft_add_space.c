/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:28:08 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/04 15:20:17 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_add_space(char spec, char **string)
{
	char	*result;
	int		i;
	char	*space;

	i = 0;
	result = NULL;
	if (spec == 'i' || spec == 'd' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		while ((*string)[i] && (*string)[i] != '+' && (*string)[i] != '-')
			i++;
		if ((*string)[i] != '+' && (*string)[i] != '-')
		{
			space = ft_strdup(" ");
			result = ft_strjoin(space, *string);
			free(space);
		}
	}
	if (result != NULL)
		*string = result;
}
