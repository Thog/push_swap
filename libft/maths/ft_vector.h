#ifndef FT_VECTOR_H
#define FT_VECTOR_H
# include "ft_maths.h"
# include "ft_string.h"
# define ABS(x) ((x) < 0 ? (-(x)) : (x))

typedef struct			s_vec3d
{
	double				x;
	double				y;
	double				z;
}						t_vec3d;


t_vec3d			*alloc_vec3d(void);
t_vec3d			*new_vec3d(double x, double y, double z);
t_vec3d			*dup_vec3d(t_vec3d *src);
void			del_vec3d(t_vec3d *vector);

t_vec3d			*add_vec3d(t_vec3d *a, t_vec3d *b);
t_vec3d			*substract_vec3d(t_vec3d *a, t_vec3d *b);
t_vec3d			*cross_vec3d(t_vec3d *a, t_vec3d *b);

t_vec3d			*normalize_vec3d(t_vec3d *vector);

double			dot_vec3d(t_vec3d *a, t_vec3d *b);
double			vector_length(t_vec3d *vector);

t_vec3d			*spherical_to_cartesian(double theta, double phi);
double			spherical_theta(t_vec3d *vector);
double			spherical_phi(t_vec3d *vector);

double			sin_theta_square(t_vec3d *vector);
double			sin_theta(t_vec3d *vector);
double			cos_phi(t_vec3d *vector);
double			sin_phi(t_vec3d *vector);
#endif
