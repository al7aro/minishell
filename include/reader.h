/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:21:18 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/17 21:33:11 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

void	info_log_input_table(char **input_table);
char	**ft_split_arg(char *str);
void	arg_reader(int argc, char **argv);
char	**reader();

#endif
