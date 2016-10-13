#include "push_swap.h"

int			check_args_before_split(char *name)
{
	int		size;
	char	prev_whitespace;

	prev_whitespace = 0;
	size = ft_strlen(name);
	if (!ft_iswhitespace(name[0]) && !ft_iswhitespace(name[size - 1]))
	{
		while (*name)
		{
			if (prev_whitespace && ft_iswhitespace(*name))
				return (0);
			prev_whitespace = ft_iswhitespace(*name);
			name++;
		}
		return (1);
	}
	return (0);
}
