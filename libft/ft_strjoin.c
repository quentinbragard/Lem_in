/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:58:39 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 10:52:59 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		s3;
	int		s4;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_strlen(s1);
	s4 = ft_strlen(s2);
	if (!(ret = ft_strnew(s3 + s4)))
		return (NULL);
	i = 0;
	while (i < s3)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < s3 + s4)
	{
		ret[i] = s2[i - s3];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
