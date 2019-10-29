/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:52:33 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/04 20:10:36 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *lst)
{
	int		i;
	t_list	*begin;

	i = 0;
	if (!lst)
		return (0);
	begin = lst;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}
