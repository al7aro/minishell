/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:21:18 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 04:26:48 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "error_code.h"

void			info_log_input_table(char **input_table);
t_error_code	ft_split_arg(char *str, char ***ret);
void			arg_reader(int argc, char **argv);
t_error_code	reader(char ***ret);

#endif
