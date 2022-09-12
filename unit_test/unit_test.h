/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:56:02 by yoav              #+#    #+#             */
/*   Updated: 2022/09/12 15:21:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>
# include <string.h>
# include "CUnit/Basic.h"
# include "CUnit/MyMem.h"

# define TEST_RES "unit_test_result.txt"
# define DEFAULT_SUITE	"SUITE"

typedef void (*t_unit_test_func)(void);

typedef struct s_unit_test
{
	t_unit_test_func	f;
	const char *		name;
}	t_unit_test;

#endif
