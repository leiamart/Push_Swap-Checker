/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:59:05 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/02 20:59:22 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_position(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	ft_low_position(t_stack **stack)
{
	t_stack	*aux;
	int		i;
	int		c;

	aux = *stack;
	i = INT_MAX;
	ft_position(stack);
	c = aux->pos;
	while (aux)
	{
		if (aux->index < i)
		{
			i = aux->index;
			c = aux->pos;
		}
		aux = aux->next;
	}
	return (c);
}

static int	ft_best_target(t_stack **a, int i, int c, int p)
{
	t_stack	*a_aux;

	a_aux = *a;
	while (a_aux)
	{
		if (a_aux->index > i && a_aux->index < c)
		{
			c = a_aux->index;
			p = a_aux->pos;
		}
		a_aux = a_aux->next;
	}
	if (c != INT_MAX)
		return (p);
	a_aux = *a;
	while (a_aux)
	{
		if (a_aux->index < c)
		{
			c = a_aux->index;
			p = a_aux->pos;
		}
		a_aux = a_aux->next;
	}
	return (p);
}

void	ft_position_target(t_stack **a, t_stack **b)
{
	t_stack	*b_aux;
	int		i;

	b_aux = *b;
	ft_position(a);
	ft_position(b);
	i = 0;
	while (b_aux)
	{
		i = ft_best_target(a, b_aux->index, INT_MAX, i);
		b_aux->target_pos = i;
		b_aux = b_aux->next;
	}
}
