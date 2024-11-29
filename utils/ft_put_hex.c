/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:39:19 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:39:26 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_convert_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_convert_hex(num / 16, format);
		ft_convert_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_put_char(num + '0');
		else
		{
			if (format == 'x')
				ft_put_char(num - 10 + 'a');
			if (format == 'X')
				ft_put_char(num - 10 + 'A');
		}
	}
}

int	ft_put_hex(unsigned int num, const char format)
{
	int	len;

	len = 0;
	if (num == 0)
		len += ft_put_char('0');
	else
	{
		ft_convert_hex(num, format);
		len += num_len(num);
	}
	return (len);
}
