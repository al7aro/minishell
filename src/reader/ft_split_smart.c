/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 02:35:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "tab.h"

int	is_special(char *str, int *aux)
{
	int	i;

	i = 0;
	(void)aux;
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

int	is_word(char *str, int *aux)
{
	char	del;
	int		i;

	i = -1;
	if (is_special(str, aux))
		return (is_special(str, aux));
	del = ' ';
	if (*str == '\'' || *str == '\"' || *str == ' ')
		del = *(str + ++i);
	while (*(str + ++i) && *(str + i) != del)
	{
		if (del == ' ' && is_special(str + i, aux))
			return (i);
		if ((*(str + i) == '\"' && *(str + i) != del && del != '\'')
			|| (*(str + i) == '\'' && *(str + i) != del && del != '\"'))
			del = *(str + i++);
		if (del != ' ' && *(str + i + 1) == del && *(str + i + 2) != ' ')
		{
			del = ' ';
			i++;
		}
	}
	if ((del == '\'' || del == '\"') && i == 1)
		*aux = 0;
	return (i + 1);
}

int	cnt_words(char *str)
{
	int	i;
	int	aux;
	int	words;

	i = 0;
	words = 0;
	while (*(str + i))
	{
		aux = 1;
		while (*(str + i) == ' ')
			i++;
		i += is_word(str + i, &aux);
		if (aux)
			words++;
		while (*(str + i) == ' ')
			i++;
	}
	return (words);
}

char	allocate_words(char *src, char ***ret, int size)
{
	int		words;
	int		i;
	int		aux;
	int		len;

	len = 0;
	i = 0;
	words = -1;
	(void)ret;
	while (++words < size)
	{
		while (*(src + i) == ' ')
			i++;
		len = is_word(src + i, &aux) - 1;
		if (len == 0)
			len++;
		if (aux)
			*((*ret + words)) = ft_substr(src, i, len);
		i += is_word(src + i, &aux);
		while (*(src + i) == ' ')
			i++;
	}
	return (0);
}

char	**ft_split_arg(char *str)
{
	int		words;
	char	**tab;

	words = cnt_words(str);
	tab_create(&tab, words);
	allocate_words(str, &tab, words);
	return (tab);
}
