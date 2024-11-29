/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:39:34 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:39:41 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	print_hex(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		print_hex(ptr / 16);
		print_hex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_put_char(ptr + '0');
		else
			ft_put_char(ptr - 10 + 'a');
	}
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
	{
		ft_put_str("(nil)");
		return (5);
	}
	len = 2;
	ft_put_str("0x");
	print_hex(ptr);
	len += ptr_len(ptr);
	return (len);
}
