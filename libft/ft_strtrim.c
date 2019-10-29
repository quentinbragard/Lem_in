/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:03:58 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 09:23:15 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int len;

	if (!s)
		return (NULL);
	i = 0;
	j = (int)ft_strlen((char*)s) - 1;
	len = j;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')) && (j > 0))
		j--;
	return (ft_strsub(s, i, (j - i + 1)));
}
