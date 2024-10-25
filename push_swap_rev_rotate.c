/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:00:10 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:32:50 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bottom_to_top(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*a;
	t_stack	*b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	a = ft_bottom(*stack);
	b = ft_before_bottom(*stack);
	if (b == NULL)
		return ;
	aux = *stack;
	*stack = a;
	(*stack)->next = aux;
	b->next = NULL;
}

void	ft_rra(t_stack **astack)
{
	ft_bottom_to_top(astack);
	ft_putstr_ps("rra\n");
}

void	ft_rrb(t_stack **bstack)
{
	ft_bottom_to_top(bstack);
	ft_putstr_ps("rrb\n");
}

void	ft_rrr(t_stack **astack, t_stack **bstack)
{
	ft_bottom_to_top(astack);
	ft_bottom_to_top(bstack);
	ft_putstr_ps("rrr\n");
}
