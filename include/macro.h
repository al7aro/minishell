/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2022/11/14 13:21:32 by al7aro           ###   ########.fr       */
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
# define MAIN_PROMPT		"\e[0mprompt> "
# define DQUOTE_PROMPT		"\e[0mdquote> "
# define SQUOTE_PROMPT		"\e[0mquote> "
# define HEREDOC_PROMPT		"\e[0mheredoc> "
# define EMPTY_STRING		""
# define NEW_PROC			0
# define EXPANDER_CHAR		'$'
# define R_BRACKET			')'
# define L_BRACKET			'('
# define MINISHELL_STR		"\e[0mminishell"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
