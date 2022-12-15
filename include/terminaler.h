/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminaler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:11:01 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/13 11:07:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALER_H
# define TERMINALER_H

# include <unistd.h>
# include <fcntl.h>

# include "dup_wrapper.h"
# include "macro.h"

typedef struct s_terminaler
{
	int		stdout_fd;
	int		stderr_fd;
	int		term_fd;
	int		null_fd;
	t_bool	should_close_stdout;
}	t_terminaler;

t_error_code	terminaler_create(t_terminaler **ret);
void			terminaler_destroy(t_terminaler **obj);
void			terminaler_init(t_terminaler *t);
void			terminaler_close(t_terminaler *t);
void			terminaler_set_out_to_null(t_terminaler *t);
void			terminaler_set_out_to_err(t_terminaler *t);
void			terminaler_set_out_to_out(t_terminaler *t);

#endif
