#include "push_swap.h"

static int		check_args_validity(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (ac > i)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || (!j && av[i][j] == '-' && \
						ft_isdigit(av[i][j + 1])))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int				ft_prgm_base(int ac, char **av, void (*op)(t_nlist*, t_nlist*))
{
	t_nlist		*a;
	t_nlist		*b;
	int			code;

	code = 0;
	if (ac >= 3 && check_args_validity(ac, av))
	{
		a = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		b = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		if ((!a || !b) && (code = 1))
			ft_putstr_fd("Error alloc\n", 2);
		else if (fill_stack(a, ac, av))
			op(a, b);
		else
			ft_putstr_fd("Error fill\n", 2);
		destroy_nlist(&a);
		destroy_nlist(&b);
	}
	else
		ft_putstr_fd("Error args\n", 2);
	return (code);
}
