#include "ft_vector.h"

double		cos_phi(t_vec3d *vector)
{
	double		sinus_theta;

	sinus_theta = sin_theta(vector);
	if (!sinus_theta)
		return (0);
	return (ft_clamp(vector->x / sinus_theta, -1, 1));
}

double			sin_phi(t_vec3d *vector)
{
	double		sinus_theta;

	sinus_theta = sin_theta(vector);
	if (!sinus_theta)
		return (0);
	return (ft_clamp(vector->y / sinus_theta, -1, 1));
}
