/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:52:45 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/05 09:23:10 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	size_t			j;
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	if (src < dst)
	{
		i = len;
		while (--i >= 0)
			dst1[i] = src1[i];
	}
	else
	{
		j = -1;
		while (++j < len)
			dst1[j] = src1[j];
	}
	return (dst);
}
