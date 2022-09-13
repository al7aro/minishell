/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/14 01:13:38 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * A PROMPT string should be together with global vars
 * */
int	main(int argc, char **argv)
{
	char	**input_table;

	printf("~Minishell~\n\n");
	first_read(argc, argv);
	while(1)
	{
		input_table = reader();
		tmp_print_input_table(input_table);
	}
	return (0);
}
