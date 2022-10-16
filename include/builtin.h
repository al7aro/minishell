/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:34:20 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 12:06:50 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "error_code.h"

typedef struct	s_builtin
{
	const char	*name;
	const void	*func;
}				t_builtin;

typedef struct	s_builtin_list
{
	t_builtin	echo;
	t_builtin	cd;
	t_builtin	export;
	t_builtin	unset;
	t_builtin	pwd;
	t_builtin	env;
	t_builtin	exit;
}				t_builtin_list;

t_error_code	b_echo(char *str);
t_error_code	b_cd(char *str);
t_error_code	b_export(char *str);
t_error_code	b_unset(char *str);
t_error_code	b_pwd();
t_error_code	b_env();
t_error_code	b_exit();

t_builtin_list	builtin_init(void);
t_builtin		builtin_get_func(t_builtin_list b, char *str);

#endif
