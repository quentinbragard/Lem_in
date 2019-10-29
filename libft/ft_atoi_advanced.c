/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:20:44 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 18:03:52 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_advanced(char **str)
{
	int					u;
	long long			result;
	int					i;

	u = 1;
	result = 0;
	i = -1;
	while (**str == ' ' || **str == '\f' || **str == '\n' || **str
			== '\r' || **str == '\t' || **str == '\v')
		(*str)++;
	if ((**str == '+') || (**str == '-'))
	{
		if (**str == '-')
			u = -1;
		(*str)++;
	}
	while (**str > 47 && **str < 58)
	{
		result = result * 10 + (**str - 48);
		(*str)++;
	}
	return (u * result);
}
