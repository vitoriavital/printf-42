/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:57:23 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 16:39:12 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

static void	ft_add_plus(int spaces, char **result, char **string)
{
	char	*sign;

	sign = ft_strdup("+");
	if (spaces != 0)
		*result = ft_build_with_spaces(*string, sign, spaces);
	else
		*result = ft_strjoin(sign, *string);
	free(sign);
}

void	ft_add_sign(char spec, char **string)
{
	char	*result;
	int		i;
	int		spaces;

	i = 0;
	result = NULL;
	spaces = 0;
	if (spec == 'i' || spec == 'd' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		while (ft_is_space((*string)[i]))
			i++;
		if (i != 0)
			spaces = i;
		while ((*string)[i] && (*string)[i] != '+' && (*string)[i] != '-')
			i++;
		if ((*string)[i] != '+' && (*string)[i] != '-')
		{
			ft_add_plus(spaces, &result, string);
		}
	}
	if (result != NULL)
		*string = result;
}
