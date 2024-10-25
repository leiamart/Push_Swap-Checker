/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:49:34 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:32:14 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	aux;

	if (stack == NULL || stack->next == NULL)
		return ;
	aux = stack->value;
	stack->value = stack->next->value;
	stack->next->value = aux;
	aux = stack->index;
	stack->index = stack->next->index;
	stack->next->index = aux;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(*stack);
	ft_putstr_ps("sa\n");
}

void	ft_sb(t_stack **stack)
{
	ft_swap(*stack);
	ft_putstr_ps("sb\n");
}

void	ft_ss(t_stack **astack, t_stack **bstack)
{
	ft_swap(*astack);
	ft_swap(*bstack);
	ft_putstr_ps("ss\n");
}
