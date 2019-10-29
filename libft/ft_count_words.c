/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:49:50 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/04 18:50:25 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
		if (s[i])
			i++;
	}
	return (k);
}