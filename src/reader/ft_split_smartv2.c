/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/17 21:04:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

int	is_special(char *str, int *aux)
{
	int	i;

	i = 0;
	(void)aux;
	if (*str == '<')
	{
		while (*(str + i) == '<')
			i++;
		return (i + 1);
	}
	if (*str == '>')
	{
		while (*(str + i) == '>')
			i++;
		return (i + 1);
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

	(void)aux;
	i = 0;
	if (is_special(str, aux))
		return (is_special(str, aux));
	if (ft_isalpha(*str))
		del = ' ';
	if (*str == '\'' || *str == '\"' || *str == ' ')
	{
		del = *str;
		i++;
	}
	printf("|%c|", del);
	while (*(str + i) && *(str + i) != del)
		i++;
	if (del != ' ')
		i++;
	if ((del == '\'' || del == '\"') && i == 2)
		*aux = 0;
	return (i);
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
		printf("WORD: %s\n", str + i);
		i += is_word(str + i, &aux);
		if (aux)
			words++;
		while (*(str + i) == ' ')
			i++;
	}
	return (words);
}

char	**ft_split_smart(char *str, char c, char del)
{
	int	words;
	
	(void)str;
	(void)c;
	(void)del;
	printf("Line: |%s|\n", str);
	words = cnt_words(str);
	printf("WORDS: %d\n", words);
	return (NULL);
}
