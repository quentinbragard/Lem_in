/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:03:05 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/04 18:52:49 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letters(char const *s, char c, int w)
{
	int i;
	int k;
	int l;

	k = 0;
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && (s[i] != '\0'))
			{
				if (k == w)
					l++;
				i++;
			}
			k++;
		}
		if (s[i])
			i++;
	}
	return (l);
}

static char	*ft_take_letters(char const *s, char c, int w, char *ret)
{
	int i;
	int k;
	int l;

	k = 0;
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && (s[i] != '\0'))
			{
				if (k == w)
					ret[l++] = s[i];
				i++;
			}
			k++;
		}
		if (s[i])
			i++;
		ret[l] = '\0';
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(ret = (char**)(malloc((sizeof(ret) * (ft_count_words(s, c) + 1))))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		if (!(ret[i] = (char*)malloc((ft_count_letters(s, c, i) + 1))))
			return (NULL);
		ret[i] = ft_take_letters(s, c, i, ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
