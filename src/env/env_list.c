/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:57:28 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/08 20:57:49 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

t_error_code	env_list_create(t_env_list **ret)
{
	*ret = ft_calloc(1, sizeof(t_env_list));
	if (!*ret)
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}

void			env_list_destroy(t_env_list **lst)
{
	dll_clear_list((*lst)->env_lst, (t_dll_destroy_func)env_destroy);
	free(*lst);
	*lst = NULL;
}

t_error_code	env_list_add_last(t_env_list *lst, t_env *env)
{
	t_dll	*node;

	node = dll_create_elem(env);
	if (!node)
		return (ALLOCATION_ERROR);
	dll_add_last(&(lst->env_lst), node);
	return (SUCCESS);
}

t_dll	*env_list_get_node(t_env_list *lst)
{
	return (lst->env_lst);
}
