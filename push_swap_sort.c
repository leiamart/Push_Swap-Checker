/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:34:12 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:28:20 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_high_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	ft_low_sort(t_stack **stack)
{
	int	h;

	if (ft_check_stack(*stack))
		return ;
	h = ft_high_index(*stack);
	if ((*stack)->index == h)
		ft_ra(stack);
	else if ((*stack)->next->index == h)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

static void	ft_less_three_a_to_b(t_stack **astack, t_stack **bstack)
{
	int	size;
	int	push;
	int	i;

	size = ft_stack_size(*astack);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*astack)->index <= size / 2)
		{
			ft_pb(astack, bstack);
			push++;
		}
		else
			ft_ra(astack);
		i++;
	}
	while (size - push > 3)
	{
		ft_pb(astack, bstack);
		push++;
	}
}

static void	ft_move_stack(t_stack **astack)
{
	int	size;
	int	low_pos;

	size = ft_stack_size(*astack);
	low_pos = ft_low_position(astack);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			ft_rra(astack);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ft_ra(astack);
			low_pos--;
		}
	}
}

void	ft_sort(t_stack **astack, t_stack **bstack)
{
	ft_less_three_a_to_b(astack, bstack);
	ft_low_sort(astack);
	while (*bstack)
	{
		ft_position_target(astack, bstack);
		ft_cost(astack, bstack);
		ft_cheap(astack, bstack);
	}
	if (!ft_check_stack(*astack))
		ft_move_stack(astack);
}
