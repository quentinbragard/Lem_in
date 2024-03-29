/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:07:28 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/05 09:07:58 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	return (nb * ft_pow(nb, --p));
}
