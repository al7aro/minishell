/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/15 13:20:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_error_code	file_logic(char **argv, char **envp)
{
	t_error_code	err;
	int				fd;

	fd = open(*(argv + 1), O_RDONLY);
	if (fd < 0)
		return (fd);
	err = dup_wrapper(fd, STDIN_FILENO);
	if (SUCCESS != err)
		return (err);
	err = internal_flow(NULL, envp, reader_get_tab_from_file);
	close(fd);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;

	err = mini_signal_disable();
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	if (mode_mngr_is_cli(argc, argv))
		return (internal_flow(argv[2], envp, reader_get_tab_from_cli));
	if (mode_mngr_is_file(argc))
		return (file_logic(argv, envp));
	if (!mode_mngr_is_interactive())
		return (internal_flow(NULL, envp, reader_get_tab_from_file));
	err = mini_signal_interactive_mode();
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	return (internal_flow(NULL, envp, reader_get_tab));
}
