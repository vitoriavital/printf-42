/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:42 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/07 14:53:03 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*ft_add_precision(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(n + 1, sizeof(char));
	while (i < n)
		str[i++] = '0';
	return (str);
}

static int	ft_char_str(char **string, int n, int length)
{
	char	*new_str;
	int		i;

	i = 0;
	if (n == 0)
	{
		new_str = ft_strdup("");
		*string = new_str;
		return (-1);
	}
	if (length > n)
	{
		new_str = (char *)ft_calloc(n + 1, sizeof(char));
		while (i < n)
		{
			new_str[i] = (*string)[i];
			i++;
		}
		free(*string);
		*string = new_str;
	}
	return (0);
}

static void	ft_numbers(char **str, int n, int length, int alig)
{
	char	*new_str;
	char	*spaces;
	char	*sign;
	char	*temp;

	sign = NULL;
	spaces = ft_add_precision(n - length);
	if (((*str)[0] == '-' || (*str)[0] == '+') && alig == 0)
	{
		if ((*str)[0] == '-')
			sign = ft_strdup("-");
		else if ((*str)[0] == '+')
			sign = ft_strdup("+");
		temp = ft_strjoin(sign, spaces);
		new_str = ft_strjoin(temp, *str + 1);
		free(sign);
		free(temp);
	}
	else if ((((*str)[0] == '-' || (*str)[0] == '+') && alig == 1) || alig == 1)
		new_str = ft_strjoin(*str, spaces);
	else
		new_str = ft_strjoin(spaces, *str);
	free(spaces);
	free(*str);
	*str = new_str;
}

static void	ft_precision(char spec, char **string, int n, int align)
{
	int		length;

	length = 0;
	length = ft_strlen(*string);
	if (n == 0 && spec == 'c')
		n = length;
	if (length == 0 && n == 1)
		length = 1;
	if (spec == 's' || spec == 'c')
	{
		if (ft_char_str(string, n, length) == -1)
			return ;
	}
	else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x'
		|| spec == 'X')
	{
		if (ft_has_sign(*string) == 1)
			length--;
		if (length < n)
		{
			ft_numbers(string, n, length, align);
		}
	}
}

int	ft_handle_precision(char *format_spec, int *i, int *align, char **result)
{
	int		zero;
	int		number;

	zero = 0;
	number = -1;
	if (format_spec[*i] == '0')
	{
		zero = 1;
		(*i)++;
	}
	if (format_spec[*i] == '.')
	{
		(*i)++;
		if (format_spec[*i] > '0' && format_spec[*i] <= '9')
			number = ft_get_number(format_spec, i);
		else if (format_spec[*i] == '0')
			number = format_spec[(*i)++] - '0';
		else
			number = 0;
		ft_precision(format_spec[*i], result, number, *align);
		(*i)++;
	}
	return (number != 0);
}
