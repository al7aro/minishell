/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:52:28 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/08 18:52:28 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

#include <stdio.h>

#include "dll.h"
#include "error_code.h"
#include "libft.h"
#include "env.h"

typedef struct	s_env_list
{
	t_dll	*env_lst;
}				t_env_list;

t_error_code	env_list_create(t_env_list **ret);
void			env_list_destroy(t_env_list **lst);
t_error_code	env_list_add_last(t_env_list *lst, t_env *env);
t_dll			*env_list_get_node(t_env_list *lst);

t_error_code	env_init(t_env_list *env);
char			*env_get(t_env_list *env, char *key);
t_error_code	env_set(t_env_list *env, char *key, char *value);
void			env_unset(t_env_list *env, char *key);
void			env_remove(t_env_list *env, char *key);

void			env_list_print(t_env_list *lst);
#endif
