/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:26:21 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/22 13:27:41 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_links_errors(char *input)
{
	int i;
	int w;

	i = 0;
	if ((!(w = ft_count_words_line_c(input, ' ')) || w > 3))
		return (-3);
	if (!(i = ft_pos('-', input)) || i > ft_pos('\n', input))
		return (-3);
	if (ft_pos('-', input + i) < ft_pos('\n', input + i)
			&& ft_pos('-', input + i))
		return (-3);
	if (w == 3 && ft_count_words_line_c(input + i, ' ') != 1)
		return (-3);
	else if (w == 2 && ft_count_words_line_c(input + i, ' ') != 1)
		return (-3);
	else if (w == 1 && (ft_pos(input[i], " \n") || ft_pos(input[i - 2], " \n")))
		return (-3);
	return (0);
}

int		check_links(char *input)
{
	int len;

	g_info.hash_size = ft_find_next_prime(g_info.nb_rooms * 10);
	if (!(len = ft_pos('-', input)))
		return (-4);
	while (input[len] != '\n')
		len--;
	input += len + 1;
	while (*input)
	{
		if (*input == '#')
			input += ft_pos('\n', input);
		else if (check_links_errors(input))
			return (-3);
		input += ft_pos('\n', input);
	}
	return (0);
}

long	atoi_checker(char *str)
{
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
		return (-1);
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str
			== '\r' || *str == '\t' || *str == '\v')
		str++;
	if ((*str == '+') || (*str == '-'))
		str++;
	if (!ft_isdigit(*str++))
		return (-1);
	while (*str && *str != ' ')
		if (!ft_isdigit(*str++))
			return (-1);
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
		return (-1);
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str
			== '\r' || *str == '\t' || *str == '\v')
		str++;
	if ((*str == '+') || (*str == '-'))
		str++;
	if (!ft_isdigit(*str++))
		return (-1);
	while (*str && *str != '\n')
		if (!ft_isdigit(*str++))
			return (-1);
	return (0);
}

int		check_rooms(char *input)
{
	int i;
	int len;

	i = 0;
	len = ft_pos('-', input);
	while (input[len] != '\n')
		len--;
	while (*input && i < len + 1 && (i += ft_pos('\n', input)))
		if (*input == '#')
			input += ft_pos('\n', input);
		else
		{
			if (ft_count_words_line_c(input, ' ') != 3)
				return (-2);
			while (*input == ' ')
				input++;
			while (*input != ' ')
				input++;
			if (atoi_checker(input))
				return (-2);
			input += ft_pos('\n', input);
			g_info.nb_rooms++;
		}
	return (0);
}
