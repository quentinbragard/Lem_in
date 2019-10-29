/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:56:49 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 09:13:57 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	if (!s1 || !s2 || !*s1 || !*s2)
		return (-1);
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	while (s3[i] == s4[i])
	{
		if ((s3[i] == '\0') && (s4[i] == '\0'))
			return (0);
		if ((s3[i] == '\0') || (s4[i] == '\0'))
			return (s3[i] - s4[i]);
		i++;
	}
	return (s3[i] - s4[i]);
}
