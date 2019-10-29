/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:05:14 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/25 14:27:58 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

char	*room_name(char **line)
{
	char	*ret;
	char	*tmp;
	int		count;
	int		k;

	count = 0;
	tmp = NULL;
	while (**line != 'L')
		(*line)++;
	tmp = *line;
	while (*(++*line) != '-')
		count++;
	*line = tmp;
	if (!(ret = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	k = 0;
	while (*(++*line) != '-')
		ret[k++] = **line;
	ret[k] = '\0';
	return (ret);
}
