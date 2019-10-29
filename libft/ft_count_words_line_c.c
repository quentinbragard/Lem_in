/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_line_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:04:07 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 18:04:08 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words_line_c(char const *str, char c)
{
	if (!*str || *str == '\n')
		return (0);
	while (*str == c)
		str++;
	while (*str && *str != '\n' && *str != c)
		str++;
	if (*str && *str != '\n')
		return (1 + ft_count_words_line_c(str, c));
	return (*(str - 1) != c ? 1 : 0);
}
