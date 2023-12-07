/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:38 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/07 14:23:06 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*ft_str_spec(char *arg, char *format)
{
	if (arg == NULL && format[1] == '.')
	{
		return (NULL);
	}
	else if (arg == NULL)
		return (ft_strdup("(null)"));
	else if (arg[0] == '\0' && format[1] >= '1' && format[1] <= '9')
	{
		ft_putchar_fd(' ', 1);
		return (NULL);
	}
	else
		return (ft_strdup(arg));
}

static char	*ft_format_spec_c(va_list list_of_arguments, char *format)
{
	char	*result;
	int		i;

	result = (char *)ft_calloc(2, sizeof(char));
	result[0] = va_arg(list_of_arguments, int);
	i = 0;
	if (result[0] == 0 && format[1] == '-')
	{
		free(result);
		ft_putchar_fd(0, 1);
		while (i++ < ((format[2] - '0') - 1))
			ft_putchar_fd(' ', 1);
		return (NULL);
	}
	return (result);
}

char	*ft_format_specifier(char spec, va_list list, char *format)
{
	char	*result;

	result = NULL;
	if (spec == 'c')
		result = ft_format_spec_c(list, format);
	else if (spec == 's')
		result = ft_str_spec(va_arg(list, char *), format);
	else if (spec == 'p')
		result = ft_print_pointer(va_arg(list, unsigned long),
				"0123456789abcdef");
	else if (spec == 'd')
		result = ft_itoa_base(va_arg(list, int), "0123456789");
	else if (spec == 'i')
		result = ft_itoa_base(va_arg(list, int), "0123456789");
	else if (spec == 'u')
		result = ft_itoa_base(va_arg(list, unsigned int), "0123456789");
	else if (spec == 'x')
		result = ft_itoa_base(va_arg(list, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		result = ft_itoa_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (spec == '%')
		result = ft_strdup("%");
	return (result);
}
