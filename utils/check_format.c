/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:38:17 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:38:29 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (len += ft_put_char(va_arg(args, int)));
	else if (format == 's')
		return (len += ft_put_str(va_arg(args, char *)));
	else if (format == 'p')
		return (len += ft_put_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (len += ft_put_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (len += ft_put_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (len += ft_put_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (len += ft_put_char('%'));
	else
		return (0);
}
