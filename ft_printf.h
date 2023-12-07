/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:22:17 by mavitori          #+#    #+#             */
/*   Updated: 2023/12/07 13:54:13 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_modify_arg(char *format_spec, int size, va_list list_of_arguments);
char	*ft_format_specifier(char spec, va_list list, char *format);
char	*ft_build_with_spaces(char *str, char *additional, int n);
void	ft_build_string(char **number, unsigned long nbr, int digits,
			const char *base);
int		ft_count_digits(unsigned long n, int base);
int		ft_has_sign(char *string);
int		ft_get_number(char *format_spec, int *i);
char	*ft_print_pointer(unsigned long n, char *base);
int		ft_handle_precision(char *format_spec, int *i, int *align,
			char **result);
char	*ft_itoa_base(long long n, const char *base);
void	ft_align_left(char **string);
void	ft_add_zeros(char spec, char **string, int num);
int		ft_handle_width(char *format_spec, int *i, int *align, char **result);
void	ft_add_space(char spec, char **string);
void	ft_add_sign(char spec, char **string);
void	ft_add_prefix(char spec, char **string);

#endif
