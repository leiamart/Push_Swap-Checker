/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:41:10 by leiamart          #+#    #+#             */
/*   Updated: 2024/09/30 20:22:49 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack **astack, t_stack **bstack)
{
	t_stack	*a_aux;
	t_stack	*b_aux;
	int		a;
	int		b;

	a_aux = *astack;
	b_aux = *bstack;
	a = ft_stack_size(a_aux);
	b = ft_stack_size(b_aux);
	while (b_aux)
	{
		b_aux->cost_b = b_aux->pos;
		if (b_aux->pos > b / 2)
			b_aux->cost_b = (b - b_aux->pos) * -1;
		b_aux->cost_a = b_aux->target_pos;
		if (b_aux->target_pos > a / 2)
			b_aux->cost_a = (a - b_aux->target_pos) * -1;
		b_aux = b_aux->next;
	}
}

void	ft_cheap(t_stack **astack, t_stack **bstack)
{
	t_stack	*aux;
	int		i;
	int		a;
	int		b;

	aux = *bstack;
	i = INT_MAX;
	while (aux)
	{
		if (ft_n_value(aux->cost_a) + ft_n_value(aux->cost_b) < ft_n_value(i))
		{
			i = ft_n_value(aux->cost_b) + ft_n_value(aux->cost_a);
			a = aux->cost_a;
			b = aux->cost_b;
		}
		aux = aux->next;
	}
	ft_move(astack, bstack, a, b);
}
