/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:41:24 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:41:25 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = number_len(n);
	num = malloc(len + 1);
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_put_unsigned(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
		len += ft_put_char('0');
	else
	{
		num = ft_itoa(nb);
		len += ft_put_str(num);
		free(num);
	}
	return (len);
}
