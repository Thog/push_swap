#include "ft_vector.h"

t_vec3d			*spherical_to_cartesian(double theta, double phi)
{
	return (new_vec3d(cos(phi) * sin(theta), sin(phi) * sin(theta), cos(theta)));
}

double			spherical_theta(t_vec3d *vector)
{
	return (acos(ft_clamp(vector->z, -1, 1)));
}

double			spherical_phi(t_vec3d *vector)
{
	double		phi;

	phi = atan2(vector->y, vector->x);
	return (phi < 0 ? phi + 2 * M_PI : phi);
}

double			sin_theta_square(t_vec3d *vector)
{
	return (FT_MAX(0, 1 - vector->z * vector->z));
}

double			sin_theta(t_vec3d *vector)
{
	return (sqrt(sin_theta_square(vector)));
}
