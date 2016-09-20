#ifndef FT_MATHS_H
#define FT_MATHS_H
# include <math.h>
# define FT_MAX(x, y) (((x) > (y)) ? (x) : (y))
# define FT_MIN(x, y) (((x) < (y)) ? (x) : (y))

double		ft_clamp(double value, double low, double high);

#endif
