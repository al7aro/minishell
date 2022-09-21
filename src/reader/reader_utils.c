/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:10 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/21 18:56:17 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

/*
 * TODO
 * 		is_quote()
 * 		is_duote()
 * 		is_special()
 * 		is_space()
 * 		skip_spaces()
 * */
int	is_special(char *str)
{
	int	i;

	i = 0;
	if (*str == RL_CHAR)
	{
		while (RL_CHAR == *(str + i))
			i++;
		return (i);
	}
	if (*str == RR_CHAR)
	{
		while (RR_CHAR == *(str + i))
			i++;
		return (i);
	}
	if (PIPE_CHAR == *str)
		return (1);
	if (*str == ';')
		return (1);
	return (0);
}

int	is_dquote(char c)
{
	return (DOUBLE_QUOTE_CHAR == c);
}

int	is_squote(char c)
{
	return (SINGLE_QUOTE_CHAR == c);
}

int	is_space(char c)
{
	return (SPACE_CHAR == c);
}
