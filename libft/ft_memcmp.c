/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:51:37 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 09:01:44 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	if (n == 0)
		return (0);
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	i = 0;
	while ((s3[i] == s4[i]) && (i < n - 1))
		i++;
	return (s3[i] - s4[i]);
}
