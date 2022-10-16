/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:45:28 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 12:06:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//-----TO DELETE
t_error_code	b_echo(char *str){(void)str; return (SUCCESS);}
t_error_code	b_cd(char *str){(void)str; return (SUCCESS);}
t_error_code	b_export(char *str){(void)str; return (SUCCESS);}
t_error_code	b_unset(char *str){(void)str; return (SUCCESS);}
t_error_code	b_pwd(){return (SUCCESS);}
t_error_code	b_env(){return (SUCCESS);}
t_error_code	b_exit(){return (SUCCESS);}
//--------------------------

t_builtin_list	builtin_init(void)
{
	t_builtin_list	b;

	b = (t_builtin_list){{"echo", b_echo},
	{"cd", (t_error_code (*)(char *))b_cd},
	{"export", (t_error_code (*)(char *))b_export},
	{"unset", (t_error_code (*)(char *))b_unset},
	{"pwd", (t_error_code (*)(void))b_pwd},
	{"env", (t_error_code (*)(void))b_env},
	{"exit", (t_error_code (*)(void))b_exit}};
	return (b);
}
