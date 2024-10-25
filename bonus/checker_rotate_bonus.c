/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:40:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/10 21:58:27 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_top_to_bottom_bonus(t_stack**stack)
{
	t_stack	*aux;
	t_stack	*a;

	if (ft_sizestack(*stack) > 1)
	{
		aux = *stack;
		a = aux;
		while (a->next != NULL)
			a = a->next;
		a->next = aux;
		*stack = (*stack)->next;
		aux->next = NULL;
	}
}

void	ft_bottom_to_top_checker(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*i;

	aux = *stack;
	if (ft_sizestack(*stack) > 1)
	{
		while (aux->next->next != NULL)
			aux = aux->next;
		i = aux->next;
		i->next = *stack;
		aux->next = NULL;
		*stack = i;
		i = NULL;
		aux = NULL;
	}
}

void	ft_rrr_check(t_stack **astack, t_stack **bstack)
{
	if (ft_sizestack(*astack) > 1 && ft_sizestack(*bstack) > 1)
	{
		ft_bottom_to_top_checker(astack);
		ft_bottom_to_top_checker(bstack);
	}
}

void	ft_rr_checker(t_stack **astack, t_stack **bstack)
{
	if (ft_sizestack(*astack) > 1 && ft_sizestack(*bstack) > 1)
		ft_top_to_bottom_bonus(astack);
	ft_top_to_bottom_bonus(bstack);
}
