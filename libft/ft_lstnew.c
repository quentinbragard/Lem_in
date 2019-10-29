/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:50:09 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 11:18:57 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void const	*c1;
	size_t		s1;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		c1 = NULL;
		s1 = 0;
	}
	else
	{
		c1 = ft_strdup(content);
		s1 = content_size;
	}
	list->content = (void*)c1;
	list->content_size = s1;
	list->next = NULL;
	return (list);
}
