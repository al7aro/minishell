/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/25 16:32:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "reader.h"

void	test_reader(void)
{
	char 			**tab;
	t_error_code	err;

	err = tab_create(&tab, 9);
	CU_ASSERT(err == SUCCESS);
	err = reader_split_by_token("Alvaro Lopez <Gomez>> and|Yoav|", &tab);
	CU_ASSERT(err == SUCCESS);

	CU_ASSERT_STRING_EQUAL(tab[0], "Alvaro")
	CU_ASSERT_STRING_EQUAL(tab[1], "Lopez")
	CU_ASSERT_STRING_EQUAL(tab[2], "<")
	CU_ASSERT_STRING_EQUAL(tab[3], "Gomez")
	CU_ASSERT_STRING_EQUAL(tab[4], ">>")
	CU_ASSERT_STRING_EQUAL(tab[5], "and")
	CU_ASSERT_STRING_EQUAL(tab[6], "|")
	CU_ASSERT_STRING_EQUAL(tab[7], "Yoav")
	CU_ASSERT_STRING_EQUAL(tab[8], "|")
	tab_destroy(&tab);
}
