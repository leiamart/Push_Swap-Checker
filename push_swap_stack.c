/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:41:55 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/02 21:08:54 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_add_bottom(t_stack **stack, t_stack *c)
{
	t_stack	*i;

	if (!c)
		return ;
	if (!*stack)
	{
		*stack = c;
		return ;
	}
	i = ft_bottom(*stack);
	i->next = c;
}

t_stack	*ft_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_new_stack(int v)
{
	t_stack	*n;

	n = malloc(sizeof * n);
	if (!n)
		return (NULL);
	n->value = v;
	n->index = 0;
	n->pos = -1;
	n->target_pos = -1;
	n->cost_a = -1;
	n->cost_b = -1;
	n->next = NULL;
	return (n);
}
