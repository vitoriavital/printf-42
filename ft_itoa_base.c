/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:09 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/05 13:44:24 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_num_length(int *is_negative, const char *base,
		unsigned long *nbr, long long *n)
{
	int	base_len;
	int	digits;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2)
		return (0);
	if (*n < 0)
	{
		*is_negative = 1;
		*nbr = *n * -1;
	}
	digits = ft_count_digits(*nbr, base_len);
	return (digits + *is_negative + 1);
}

char	*ft_itoa_base(long long n, const char *base)
{
	int				is_negative;
	int				length;
	char			*number;
	unsigned long	nbr;

	is_negative = 0;
	length = 0;
	nbr = n;
	length = ft_num_length(&is_negative, base, &nbr, &n);
	number = (char *)malloc(length * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[length - 1] = '\0';
	if (is_negative)
		number[0] = '-';
	ft_build_string(&number, nbr, length - 2, base);
	return (number);
}
