/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:07:07 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/01 22:20:43 by r3dc4t-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stddef.h>

static char	*remove_pair_from_str(char *str, char *c1, char *c2)
{
	size_t	len;
	size_t	i;
	size_t	i_ret;
	char	*ret;

	len = ft_strlen(str) - 2;
	ret = (char *)malloc(sizeof(char) * len + 1);
	*(ret + len) = 0;
	i_ret = 0;
	i = 0;
	while (*(str + i))
	{
		if (str + i != c1 && str + i != c2 && i_ret < len)
		{
			*(ret + i_ret) = *(str + i);
			i_ret++;
		}
		i++;
	}
	free(str);
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

char	*expander_remove_line_quotes(char *str)
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
		if (!(*(str + i - 1)))
			break ;
	}
	return (str);
}

static void	modify_token_list(t_shell_op *sp)
{
	char	**input;
	t_dll	*token_list;
	size_t	i;
	t_token	*t;
	char	*tmp;

	input = sp->input;
	token_list = token_list_get_node(sp->token_list);
	i = 0;
	while (token_list)
	{
		t = token_list_get_token(token_list);
		tmp = t->value;
		t->value = *(input + i++);
		free(tmp);
		token_list = token_list->next;
	}
}

t_error_code	expander_remove_all_quotes(t_shell_op *sp)
{
	char	**input;
	size_t	i;
	char	*tmp;

	input = sp->input;
	i = 0;
	while (*(input + i))
	{
		tmp = *(input + i);
		*(input + i) = expander_remove_line_quotes(*(input + i));
		free(tmp);
		i++;
	}
	modify_token_list(sp);
	return (SUCCESS);
}
