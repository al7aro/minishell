/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/17 16:33:58 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static const char	*skip_sep(const char *s, char sep, char del)
{
	(void)del;
	if (*s == del && sep == del)
	{
		s++;
		while (*s != del || (*s == del && *(s - 1) == '\\'))
		{
			s++;
		}
		if (*s == del)
			s++;
	}
	while (*s && *s == sep)
		++s;
	return (s);
}

static int	count_word(const char *s, char sep, char del)
{
	int	i;

	(void)del;
	i = 0;
	s = skip_sep(s, sep, del);
	//s = skip_sep(s, del, del);
	while (*s)
	{
		++i;
		while (*s && *s != sep && *s != del)
			++s;
		if (*s == del)
			s = skip_sep(s, del, del);
		else
			s = skip_sep(s, sep, del);
	}
	return (i);
}

static const char	*create_str(const char *s, char sep, char **ret, char del)
{
	int		i;
	char	aux_sep;

	aux_sep = sep;
	i = 0;
	while (s[i] && (s[i] != sep || (s[i] == del && s[i-1] == '\\')))
	{
		if (s[i] == del)
			sep = del;
		i++;
	}
	if (sep == del)
	{
		*ret = ft_substr(s, 0, ++i);
		sep = aux_sep;
	}
	else
		*ret = ft_substr(s, 0, i);
	return (s + i);
}

static void	free_all(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

char	**ft_split_smart(char const *s, char c, char del)
{
	int				word_num;
	int				i;
	char			**ret;

	if (!s)
		return (NULL);
	word_num = count_word(s, c, del);
	ret = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!ret)
		return (NULL);
	ret[word_num] = NULL;
	s = skip_sep(s, c, del);
	i = 0;
	while (i < word_num)
	{
		s = create_str(s, c, ret + i, del);
		if (ret[i] == NULL)
		{
			free_all(ret, i);
			return (NULL);
		}
		s = skip_sep(s, c, del);
		++i;
	}
	return (ret);
}
