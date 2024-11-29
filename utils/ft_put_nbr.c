/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:40:11 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:40:12 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int nbr)
{
	long	nb;
	int		len;

	nb = nbr;
	len = 0;
	if (nb < 0)
	{
		len += ft_put_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_put_nbr(nb / 10);
	len += ft_put_char((nb % 10) + '0');
	return (len);
}
