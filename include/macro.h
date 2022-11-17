/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2022/11/17 15:31:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define PIPE_CHAR			'|'
# define RR_CHAR			'>'
# define RL_CHAR			'<'
# define SEMICOLON_CHAR		';'
# define NEW_LINE_CHAR		'\n'
# define NEW_LINE_STR		"\n"
# define SINGLE_QUOTE_CHAR	'\''
# define DOUBLE_QUOTE_CHAR	'\"'
# define SPACE_CHAR			' '
# define EQUAL_CHAR			'='
# define MINUS_CHAR			'-'
# define EQUAL_STR			"="
# define COLON_CHAR			':'
# define SLASH_CHAR			'/'
# define SLASH_STR			"/"
# define QUOTE_STR			"'"
# define MAIN_PROMPT		"\e[0mmsh$ "
# define DQUOTE_PROMPT		"\e[0mdquote> "
# define SQUOTE_PROMPT		"\e[0mquote> "
# define HEREDOC_PROMPT		"\e[0m> "
# define EMPTY_STRING		""
# define NEW_PROC			0
# define EXPANDER_CHAR		'$'
# define R_BRACKET			')'
# define L_BRACKET			'('
# define MINISHELL_STR		"\e[0mminishell"
# define EXEC_CMD_NOT_FOUND_STR	"command not found: "
# define EXEC_PREM_ERR_STR		"permission denied: "
# define PIPE_READ				0
# define PIPE_WRITE				1

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
