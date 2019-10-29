/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:02:27 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/05 11:25:53 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			c = 0;
			while (haystack[i + c] == needle[c] && i + c < len)
			{
				if (needle[c + 1] == '\0')
					return ((char*)haystack + i);
				c++;
			}
		}
		i++;
	}
	return (NULL);
}
