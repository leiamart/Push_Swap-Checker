/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:06:30 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/10 21:59:59 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_pa_checker(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	t_stack	*i;

	if (ft_sizestack(*b) >= 1)
	{
		aux = *b;
		i = aux->next;
		aux->next = *a;
		*a = aux;
		*b = i;
	}
}

void	ft_pb_checker(t_stack **b, t_stack **a)
{
	t_stack	*aux;
	t_stack	*i;

	if (ft_sizestack(*a) >= 1)
	{
		aux = *a;
		i = aux->next;
		aux->next = *b;
		*b = aux;
		*a = i;
	}
}

void	ft_sa_checker(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*i;

	if (ft_sizestack(*stack) > 1)
	{
		aux = *stack;
		i = aux->next;
		aux->next = i->next;
		i->next = aux;
		*stack = i;
	}
}

void	ft_sb_checker(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*i;

	if (ft_sizestack(*stack) > 1)
	{
		aux = *stack;
		i = aux->next;
		aux->next = i->next;
		i->next = aux;
		*stack = i;
	}
}

void	ft_ss_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sizestack(*stack_a) > 1 && ft_sizestack(*stack_b) > 1)
	{
		ft_sb_checker(stack_b);
		ft_sa_checker(stack_a);
	}
}
