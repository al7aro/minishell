/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/19 12:08:09 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	is_special(char *str)
{
	int	i;

	i = 0;
	if (*str == '<')
	{
		while (*(str + i) == '<')
			i++;
		return (i);
	}
	if (*str == '>')
	{
		while (*(str + i) == '>')
			i++;
		return (i);
	}
	if (*str == '|')
		return (1);
	if (*str == ';')
		return (1);
	return (0);
}

int	is_word(char *str)
{
	char	del;
	int		i;

	i = -1;
	if (is_special(str))
		return (is_special(str));
	del = ' ';
	while (*(str + ++i) && *(str + i) != del)
	{
		if (del == ' ' && is_special(str + i))
			return (i);
		if ((*(str + i) == '\"' && *(str + i) != del && del != '\'')
			|| (*(str + i) == '\'' && *(str + i) != del && del != '\"'))
			del = *(str + i);
		if (del != ' ' && *(str + i + 1) == del)
		{
			del = ' ';
			i += 1;
		}
	}
	return (i + 1 + (del == '\"' || del == '\'') - (*(str + i) == ' '));
}

int	cnt_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (*(str + i))
	{
		while (*(str + i) == ' ')
			i++;
		i += is_word(str + i);
		words++;
		while (*(str + i) == ' ')
			i++;
	}
	return (words);
}

void	allocate_words(char *src, char ***ret, int size)
{
	int		words;
	int		i;
	int		len;

	len = 0;
	i = 0;
	words = -1;
	while (++words < size)
	{
		while (*(src + i) == ' ')
			i++;
		len = is_word(src + i);
		if (len == 0)
			len++;
		*((*ret + words)) = ft_substr(src, i, len);
		i += is_word(src + i);
		while (*(src + i) == ' ')
			i++;
	}
}

t_error_code	ft_split_arg(char *str, char ***ret)
{
	t_error_code	err;
	int				words;

	words = cnt_words(str);
	err = tab_create(ret, words);
	allocate_words(str, ret, words);
	return (err);
}
