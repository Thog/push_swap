#include "ft_vector.h"

t_vec3d			*add_vec3d(t_vec3d *a, t_vec3d *b)
{
	if (a && b)
	{
		a->x += b->x;
		a->y += b->y;
		a->z += b->z;
	}
	return (a);
}

t_vec3d			*substract_vec3d(t_vec3d *a, t_vec3d *b)
{
	if (a && b)
	{
		a->x -= b->x;
		a->y -= b->y;
		a->z -= b->z;
	}
	return (a);
}

t_vec3d			*cross_vec3d(t_vec3d *a, t_vec3d *b)
{
	if (a && b)
	{
		a->x *= b->x;
		a->y *= b->y;
		a->z *= b->z;
	}
	return (a);
}

double			dot_vec3d(t_vec3d *a, t_vec3d *b)
{
	double	res;

	res = 0;
	if (a && b)
		res = a->x * b->x + a->y * b->y + a->z * b->z;
	return (res);
}

double			vector_length(t_vec3d *vector)
{
	return (sqrt(dot_vec3d(vector, vector)));
}
