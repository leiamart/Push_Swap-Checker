/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:56:44 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:29:30 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_top_to_bottom(t_stack **stack)
{
	t_stack	*i;
	t_stack	*c;

	i = *stack;
	*stack = (*stack)->next;
	c = ft_bottom(*stack);
	i->next = NULL;
	c->next = i;
}

void	ft_ra(t_stack **astack)
{
	ft_top_to_bottom(astack);
	ft_putstr_ps("ra\n");
}

void	ft_rb(t_stack **bstack)
{
	ft_top_to_bottom(bstack);
	ft_putstr_ps("rb\n");
}

void	ft_rr(t_stack **astack, t_stack **bstack)
{
	ft_top_to_bottom (astack);
	ft_top_to_bottom (bstack);
	ft_putstr_ps("rr\n");
}
