#include "ft_matrix.h"

double			get_matrix_entry(t_matrix *matrix, size_t y, size_t x)
{
	if (matrix && matrix->row_length > x && matrix->colum_length > y)
		return (matrix->mem[y][x]);
	return (0.0D);
}

t_matrix		*cross_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		i;
	size_t		j;
	size_t		k;
	double		sum;

	c = NULL;
	// c = (n x p)
	if (b->colum_length == a->row_length &&
		(c = alloc_matrix(b->row_length, b->colum_length)))
	{
		i = 0;
		// n
		while (i < b->row_length)
		{
			j = 0;
			// p
			while (j < a->colum_length)
			{
				sum = 0;
				k = 0;

				// m
				while (k < b->colum_length)
				{
					sum += get_matrix_entry(b, k, i) *
						get_matrix_entry(a, j, k);
					k++;
				}
				c->mem[j][i] = sum;
				j++;
			}
			i++;
		}
	}
	return (c);
}

t_matrix		*transpose_matrix(t_matrix *source)
{
	t_matrix	*res;
	size_t		i;
	size_t		j;

	res = NULL;
	j = 0;
	if (source && (res = alloc_matrix(source->colum_length, source->row_length)))
	{
		while ((++j) <= source->colum_length)
		{
			i = 0;
			while ((++i) <= source->row_length)
			{
				res->mem[i - 1][j - 1] = source->mem[j - 1][i - 1];
			}
		}
	}
	return (res);
}
