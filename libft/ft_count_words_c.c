/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:41:04 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/04 18:51:56 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words_c(char const *str, char c)
{
	if (!*str)
		return (0);
	while (*str == c)
		str++;
	while (*str && *str != c)
		str++;
	if (*str)
		return (1 + ft_count_words_c(str, c));
	return (*(str - 1) != c ? 1 : 0);
}
