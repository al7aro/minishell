/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 04:40:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * A PROMPT string should be together with global vars
 * */
int	main(int argc, char **argv)
{
	t_shell_op		op;
	t_error_code	err;

	printf("~Minishell~\n\n");
	arg_reader(argc, argv);
	while (1)
	{
		err = reader(&op.input);
		info_log_input_table(op.input);
	}
	return (0);
}
