/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/17 18:23:06 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

/*
 * A PROMPT string should be together with global vars
 * */
int	main(int argc, char **argv)
{
	char	**input_table;

	printf("~Minishell~\n\n");
	arg_reader(argc, argv);	
	while(1)
	{
		input_table = reader(); //returns TAB
				info_log_input_table(input_table);
		if (input_table)
			free(input_table);
	}
	return (0);
}
