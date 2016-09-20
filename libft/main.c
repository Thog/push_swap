#include "libft.h"
#include <stdio.h>

double	  	test_one[4][6] = {{2, 2, 2, 2, 2, 2},
							  {3, 3, 3, 3, 3, 3},
							  {4, 4, 4, 4, 4, 4},
							  {5, 5, 5, 5, 5, 5}};

double 		test_two[4][4] = {{1, 1, 1, 1},
							  {1, 2, 2, 1},
							  {1, 3, 3, 1},
							  {1, 1, 1, 1}};

void 		apply_matrix(t_matrix *matrix, void (*f)(t_matrix*, int, int))
{
	if (matrix == NULL)
		return;
	printf("Matrix [%lu, %lu]\n", matrix->row_length, matrix->colum_length);
	for (int i = 0; i < matrix->colum_length; i++)
	{
		for (int j = 0; j < matrix->row_length; j++)
		{
			f(matrix, i, j);
		}
	}
}

void 		print_matrix(t_matrix *matrix, int i, int j)
{
	printf("%g ", get_matrix_entry(matrix, i, j));
	if ((j + 1) == matrix->row_length)
		printf("\n");
}

void 		fill_one(t_matrix *matrix, int i, int j)
{
	matrix->mem[i][j] = test_one[i][j];
}

void 		fill_two(t_matrix *matrix, int i, int j)
{
	matrix->mem[i][j] = test_two[i][j];
}

int			main(void)
{
	t_matrix *mone = alloc_matrix(6, 4);
	apply_matrix(mone, fill_one);
	apply_matrix(mone, print_matrix);
	printf("\n");
	t_matrix *mtwo = alloc_matrix(4, 4);
	apply_matrix(mtwo, fill_two);
	apply_matrix(mtwo, print_matrix);
	t_matrix *mthree = cross_matrix(mtwo, mone);
	printf("\n\n");
	apply_matrix(mthree, print_matrix);
	t_matrix *transposed = transpose_matrix(mthree);
	apply_matrix(transposed, print_matrix);
	del_matrix(mone);
	del_matrix(mtwo);
	del_matrix(mthree);
	//del_matrix(transposed);
}
