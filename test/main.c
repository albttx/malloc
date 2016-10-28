/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:54:35 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:20:08 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void show_alloc_mem(void);
void simple_test(int *arr);
void rand_test(int len, int x_max);
void test_0(void);
void test_1(void);
void test_2(void);
void test_3(void);

int main(void)
{
	/*int arr[] = {67, 24, 352, 40, 248, 22, 0};*/
	/*int arr[] = {11, 22, 33, 44, 0};*/
	/*int arr[] = {1111, 2222,3333, 4444, 0};*/
	/*int arr[] = {1540, 3152, 3632, 2378, 2339, 778, 0};*/
	
	/*simple_test(arr);*/

	/*test_0();*/
	/*test_1();*/
	/*test_2();*/
	/*test_3();*/

	/*rand_test(3, 4000);*/
	/*rand_test(30, 3000);*/
	/*rand_test(90, 300000);*/

	show_alloc_mem();
	return (0);
}
