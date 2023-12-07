/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:07:03 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/07 14:25:55 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putstr_printf(char *s, int fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar_fd(s[i++], fd);
}

static int	ft_simple_flags(char *format_spec, int *i, char **result, char spec)
{
	int	output;

	output = 0;
	if (format_spec[*i] == '#')
	{
		ft_add_prefix(spec, result);
		(*i)++;
	}
	else if (format_spec[*i] == '+')
	{
		output = 1;
		(*i)++;
	}
	else if (format_spec[*i] == ' ')
	{
		ft_add_space(spec, result);
		(*i)++;
	}
	else if (format_spec[*i] == '-')
	{
		output = 1;
		(*i)++;
	}
	return (output);
}

static void	ft_process_arg(char *format_spec, int size, char **result,
		char **basic_output)
{
	int	dec;
	int	align;
	int	i;
	int	spec;

	dec = 0;
	align = 0;
	i = 1;
	spec = format_spec[size];
	while (i < size)
	{
		if (format_spec[i] >= '0' && format_spec[i] <= '9')
			dec = ft_handle_width(format_spec, &i, &align, result);
		else if (format_spec[i] == '#' || format_spec[i] == '+'
			|| format_spec[i] == ' ' || format_spec[i] == '-')
			align = ft_simple_flags(format_spec, &i, result, spec);
		else if (format_spec[i] == '.')
			dec = ft_handle_precision(format_spec, &i, &align, result);
		else
			i++;
	}
	if (align == 1 && format_spec[size - 1] == '+')
		ft_add_sign(spec, result);
	if (*basic_output != *result && dec == 0)
		free(*basic_output);
}

static int	ft_null_cases(char spec, char *format_spec)
{
	if (spec == 'c')
		return ((format_spec[2] - '0'));
	else if (spec == 's' && format_spec[1] == '.')
	{
		if ((format_spec[2] - '0') >= 0 && (format_spec[2] - '0') <= 9)
			return ((format_spec[2] - '0'));
		else
			return (0);
	}
	else if (spec == 's')
		return ((format_spec[1] - '0'));
	else
		return (0);
}

int	ft_modify_arg(char *format_spec, int size, va_list list_of_arguments)
{
	char	spec;
	char	*result;
	char	*basic_output;
	int		length;

	length = 0;
	spec = format_spec[size];
	basic_output = ft_format_specifier(spec, list_of_arguments, format_spec);
	if (basic_output == NULL)
		return (ft_null_cases(spec, format_spec));
	if ((basic_output[0] == '\0' && spec == 'c') || (ft_strncmp(basic_output,
				"", 1) == 0 && spec == 's' && size == 2 && format_spec[1] != '.'
			&& format_spec[1] != ' '))
		length = 1;
	result = basic_output;
	ft_process_arg(format_spec, size, &result, &basic_output);
	length += ft_strlen(result);
	ft_putstr_printf(result, 1, length);
	if (length == 0 && spec == 'c' && result != NULL)
	{
		ft_putchar_fd(0, 1);
		length = 1;
	}
	free(result);
	return (length);
}
