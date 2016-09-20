#include "ft_maths.h"

double		ft_clamp(double value, double low, double high)
{
	return value < low ? low : (value > high ? high : value);
}
