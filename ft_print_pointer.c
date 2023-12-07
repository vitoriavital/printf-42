/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:10:33 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 18:57:50 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*ft_itoa_base_ptr(unsigned long n, const char *base)
{
	int				base_len;
	int				digits;
	int				length;
	char			*number;
	unsigned long	nbr;

	base_len = 0;
	length = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2)
		return (NULL);
	nbr = n;
	digits = ft_count_digits(nbr, base_len);
	length = digits + 1;
	number = (char *) malloc(length * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[length - 1] = '\0';
	ft_build_string(&number, nbr, length - 2, base);
	return (number);
}

char	*ft_print_pointer(unsigned long n, char *base)
{
	char	*result;
	char	*prefix;
	char	*number;

	if (n == 0)
		return (ft_strdup("(nil)"));
	prefix = ft_strdup("0x");
	number = ft_itoa_base_ptr(n, base);
	result = ft_strjoin(prefix, number);
	free (number);
	free(prefix);
	return (result);
}
