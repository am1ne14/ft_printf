/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:34:19 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/29 05:40:27 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start (args, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		if (str[i] == '%' && ft_strchr(str[i + 1]))
		{
			len += check_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
