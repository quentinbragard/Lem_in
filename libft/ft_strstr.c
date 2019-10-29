/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:03:27 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 09:22:19 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;
	int len;

	i = 0;
	len = ft_strlen((char*)needle);
	if (len == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		k = i;
		while ((needle[j]) && (haystack[i]) && (needle[j] == haystack[i]))
		{
			i++;
			j++;
		}
		if (j == len)
			return ((char*)(haystack + i - len));
		i = k + 1;
	}
	return (NULL);
}
