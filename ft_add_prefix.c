/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:03 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 17:58:41 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

void	ft_add_prefix(char spec, char **string)
{
	char	*result;
	char	*prefix;
	int		i;

	result = NULL;
	i = 0;
	if ((spec == 'x' || spec == 'X') && ((*string)[0] != '0'
		|| (*string)[1] == 'x' || (*string)[1] == 'X'))
	{
		if (spec == 'x' || (*string)[1] == 'x')
			prefix = ft_strdup("0x");
		else if (spec == 'X' || (*string)[1] == 'X')
			prefix = ft_strdup("0X");
		while (ft_is_space((*string)[i]) || (*string)[i] == '+'
			|| (*string)[i] == '-')
			i++;
		if (i != 0)
			result = ft_build_with_spaces(*string, prefix, i);
		else
			result = ft_strjoin(prefix, *string);
		free(prefix);
	}
	if (result != NULL)
		*string = result;
}
