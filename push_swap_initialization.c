/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initialization.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:04:23 by leiamart          #+#    #+#             */
/*   Updated: 2024/09/30 20:24:00 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_values(int argc, char **argv)
{
	long int	n;
	int			i;
	t_stack		*a;

	a = NULL;
	i = 1;
	n = 0;
	while (i < argc)
	{
		n = ft_atoi_ps(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_write_error(&a, NULL);
		if (i == 1)
			a = ft_new_stack((int) n);
		else
			ft_add_bottom(&a, ft_new_stack((int)n));
		i++;
	}
	return (a);
}

void	ft_index_high_to_low(t_stack *astack, int size)
{
	t_stack	*h;
	t_stack	*p;
	int		i;

	while (--size > 0)
	{
		p = astack;
		i = INT_MIN;
		h = NULL;
		while (p)
		{
			if (p->value == INT_MIN && p->index == 0)
				p->index = 1;
			if (p->value > i && p-> index == 0)
			{
				i = p->value;
				h = p;
				p = astack;
			}
			else
				p = p->next;
		}
		if (h != NULL)
			h->index = size;
	}
}
