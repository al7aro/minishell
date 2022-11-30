/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:20:42 by yoav              #+#    #+#             */
/*   Updated: 2022/09/17 12:33:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "laxer.h"
#include "expander.h"

static t_error_code	laxer_create_token(t_shell_op *sp, char **s)
{
	t_token_list	*tok_lst;
	t_error_code	err;
	t_token_type	type;
	t_token			*tok;
	char			*tmp;

	tok_lst = sp->token_list;
	type = laxer_get_token_type(*s);
	tmp = *s;
	*s = expander_expand_var(sp, *s);
	free(tmp);
	err = token_create(&tok, *s, type);
	if (SUCCESS != err)
		return (err);
	err = token_list_add_last(tok_lst, tok);
	if (SUCCESS != err)
	{
		token_destroy(&tok);
		return (err);
	}
	return (err);
}

t_error_code	laxer_create_token_list(t_shell_op *sp)
{
	t_error_code	err;
	int				i;

	err = token_list_create(&(sp->token_list));
	if (SUCCESS != err)
		return (err);
	i = 0;
	while (sp->input[i])
	{
		err = laxer_create_token(sp, &sp->input[i]);
		if (SUCCESS != err)
		{
			token_list_destroy(&(sp->token_list));
			return (err);
		}
		++i;
	}
	return (SUCCESS);
}
