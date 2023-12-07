/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:29:36 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 18:50:37 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_build_with_spaces(char *str, char *additional, int n)
{
	char	*result;
	char	*substr;

	substr = ft_substr(str, 0, n);
	result = ft_strjoin(substr, additional);
	free(substr);
	substr = ft_substr(str, n, ft_strlen(str));
	result = ft_strjoin(result, substr);
	free(substr);
	return (result);
}

void	ft_build_string(char **number, unsigned long nbr, int digits,
		const char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
	{
		base_len++;
	}
	if (nbr == 0)
	{
		(*number)[digits] = base[0];
		return ;
	}
	while (nbr > 0)
	{
		(*number)[digits] = base[nbr % base_len];
		nbr = nbr / base_len;
		digits--;
	}
}

int	ft_count_digits(unsigned long n, int base)
{
	int	counter;

	counter = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / base;
		counter++;
	}
	return (counter);
}

int	ft_has_sign(char *string)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '-' || string[i] == '+')
			sign = 1;
		i++;
	}
	return (sign);
}

int	ft_get_number(char *format_spec, int *i)
{
	int	dec;
	int	number;

	dec = 0;
	number = -1;
	while (format_spec[*i] >= '0' & format_spec[*i] <= '9')
	{
		if (dec == 0)
			number = (format_spec[*i] - '0');
		else
			number = number * 10 + (format_spec[*i] - '0');
		(*i)++;
		dec++;
	}
	return (number);
}
