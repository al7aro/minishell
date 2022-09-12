/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/12 15:12:53 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static FILE* g_temp_file = NULL;

// Every test needs a declaration here

void test_dll_swap_value(void);
void test_dll_create_and_destroy_elem(void);
void test_dll_clear_list(void);

// and to be added to this array
static t_unit_test g_all_tests[] = {
	{
		test_dll_swap_value,
		"test_dll_swap_value"
	},
	{
		test_dll_create_and_destroy_elem,
		"test_dll_create_and_destroy_elem"
	},
	{
		test_dll_clear_list,
		"test_dll_clear_list"
	},
	{
		NULL,
		""
	},
};

int	init_suite(void)
{
	if (NULL == (g_temp_file = fopen(TEST_RES, "w+")))
		return -1;
	return 0;
}

int	clean_suite(void)
{
	if (0 != fclose(g_temp_file))
		return -1;
	g_temp_file = NULL;
	return 0;
}

CU_ErrorCode	loop_all_tests(CU_pSuite pSuite)
{
	int	i	= 0;
	
	while (NULL != g_all_tests[i].f)
	{
		if ((NULL == CU_add_test(pSuite, g_all_tests[i].name, g_all_tests[i].f)))
		{
			CU_cleanup_registry();
			return CU_get_error();
		}
		++i;
	}
	return CU_get_error();
}

int	main(void)
{
	CU_pSuite pSuite;

	pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	pSuite = CU_add_suite(DEFAULT_SUITE, init_suite, clean_suite);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	loop_all_tests(pSuite);
	CU_basic_set_mode(CU_BRM_NORMAL);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}