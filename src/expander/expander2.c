/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:07:07 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/18 22:07:07 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*remove_pair_from_str(char *str, char *c1, char *c2)
{
	size_t	len;
	size_t	i;
	size_t	i_ret;
	char	*ret;
	char	*tmp;

	tmp = str;
	len = ft_strlen(str) - 2;
	ret = (char *)malloc(sizeof(char) * len);
	*(ret + len) = 0;
	i_ret = 0;
	i = 0;
	while (*(str + i))
	{
		if (str + i != c1 && str + i != c2)
		{
			*(ret + i_ret) = *(str + i);
			i_ret++;
		}
		i++;
	}
	free(tmp);
	return (ret);
}

static size_t	find_pair(char *pos)
{
	size_t	i;

	i = 1;
	while (*(pos + i))
	{
		if (*pos == *(pos + i))
			return (i);
		i++;
	}
	return (0);
}

char	*expander_remove_quotes(char *str)
{
	size_t	i;
	size_t	p2;

	if (!str)
		return (NULL);
	i = 0;
	while (*(str + i))
	{
		p2 = 0;
		if (DOUBLE_QUOTE_CHAR == *(str + i) || SINGLE_QUOTE_CHAR == *(str + i))
		{
			p2 = i + find_pair(str + i);
			if (p2)
			{
				str = remove_pair_from_str(str, str + i, str + p2);
				i = p2;
			}
		}
		if (!p2)
			i++;
	}
	return (str);
}
