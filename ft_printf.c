/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:24:22 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/07 11:00:17 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_print_regular(const char *format, int *i, int *counter)
{
	while (format[*i] != '%' && format[*i])
	{
		ft_putchar_fd(format[(*i)++], 1);
		(*counter)++;
	}
}

static int	ft_print_format(int size, const char *format, int *i,
		va_list list_of_arguments)
{
	char	*format_spec;
	int		j;
	int		result;

	j = 0;
	format_spec = (char *)ft_calloc(size + 1, sizeof(char));
	result = 0;
	while (j <= size)
	{
		format_spec[j] = format[*i - size + j - 1];
		j++;
	}
	result = ft_modify_arg(format_spec, size, list_of_arguments);
	free(format_spec);
	return (result);
}

static int	ft_process_format(const char *format, int *i,
		va_list list_of_arguments, int *size)
{
	char	*set;

	set = "cspdiuxX%";
	(*i)++;
	(*size)++;
	while (format[*i] && !ft_strchr(set, format[*i]))
	{
		(*size)++;
		(*i)++;
	}
	if (ft_strchr(set, format[*i]))
		(*i)++;
	return (ft_print_format(*size, format, i, list_of_arguments));
}

int	ft_printf(const char *format, ...)
{
	va_list	list_of_arguments;
	int		i;
	int		counter;
	int		j;
	int		size;

	i = 0;
	j = 0;
	counter = 0;
	size = 0;
	if (format == NULL)
		return (-1);
	va_start(list_of_arguments, format);
	while (format[i])
	{
		ft_print_regular(format, &i, &counter);
		if (format[i] == '%' && format[i])
		{
			counter += ft_process_format(format, &i, list_of_arguments, &size);
			size = 0;
		}
	}
	va_end(list_of_arguments);
	return (counter);
}
