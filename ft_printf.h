/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:13:35 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/29 05:38:57 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strchr(int c);
int		ft_printf(const char *str, ...);
int		check_format(va_list args, const char format);
int		ft_put_unsigned(unsigned int nb);
int		number_len(unsigned int num);
int		ft_put_str(char *str);
int		ft_put_ptr(unsigned long long ptr);
int		ptr_len(unsigned long long ptr);
int		ft_put_nbr(int nbr);
int		ft_put_hex(unsigned int num, const char format);
int		num_len(unsigned int num);
int		ft_put_char(char c);
char	*ft_itoa(unsigned int n);
void	print_hex(unsigned long long ptr);
void	ft_convert_hex(unsigned int num, const char format);

#endif
