/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:38 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 19:08:20 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*ft_add_spaces(int n, int zero)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(n + 1, sizeof(char));
	while (i < n)
	{
		if (zero == 1)
			str[i++] = '0';
		else
			str[i++] = ' ';
	}
	return (str);
}

static void	ft_signed(char **string, char **new_str, char **spaces)
{
	char	*sign;
	char	*str;

	sign = NULL;
	if ((*string)[0] == '-')
		sign = ft_strdup("-");
	else if ((*string)[0] == '+')
		sign = ft_strdup("+");
	str = ft_strjoin(sign, *spaces);
	*new_str = ft_strjoin(str, *string + 1);
	free(sign);
	free(str);
}

void	ft_printf_width(int n, char **string, int zero, int align)
{
	char	*new_str;
	char	*spaces;
	int		size;

	new_str = NULL;
	size = ft_strlen(*string);
	spaces = NULL;
	if (size < n)
	{
		spaces = ft_add_spaces(n - size, zero);
		if (((*string)[0] == '-' || (*string)[0] == '+') && align == 0)
			ft_signed(string, &new_str, &spaces);
		else if (((*string)[0] == '-' || (*string)[0] == '+') && align == 1)
			new_str = ft_strjoin(*string, spaces);
		else if (align == 1)
			new_str = ft_strjoin(*string, spaces);
		else
			new_str = ft_strjoin(spaces, *string);
		free(spaces);
		free(*string);
		*string = new_str;
	}
}

int	ft_handle_width(char *format_spec, int *i, int *align, char **result)
{
	int		zero;
	int		number;

	zero = 0;
	if (format_spec[*i] == '0')
	{
		zero = 1;
		(*i)++;
	}
	number = ft_get_number(format_spec, i);
	if (number >= 0 && format_spec[*i] != '%')
		ft_printf_width(number, result, zero, *align);
	(*i)++;
	return (1);
}
