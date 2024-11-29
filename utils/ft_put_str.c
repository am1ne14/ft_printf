/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:40:52 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/26 21:40:54 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (i);
}
