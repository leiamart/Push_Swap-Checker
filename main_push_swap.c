/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:05:34 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:22:25 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	ft_check_stack(t_stack *astack)
{
	while (astack->next != NULL)
	{
		if (astack->value > astack->next->value)
			return (0);
		astack = astack->next;
	}
	return (1);
}

static void	ft_push_swap_main(t_stack **astack, t_stack **bstack, int s)
{
	if (s == 2 && !ft_check_stack(*astack))
		ft_sa(astack);
	else if (s == 3)
		ft_low_sort(astack);
	else if (s > 3 && !ft_check_stack(*astack))
		ft_sort(astack, bstack);
}

t_stack	*ft_values_ps(char **argv)
{
	long int	n;
	int			i;
	t_stack		*a;

	a = NULL;
	i = 0;
	n = 0;
	while (argv[i] != NULL)
	{
		n = ft_atoi_ps(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_write_error(&a, NULL);
		if (i == 0)
			a = ft_new_stack((int) n);
		else
			ft_add_bottom(&a, ft_new_stack((int)n));
		i++;
	}
	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
	return (a);
}

static void	ft_free_finish(t_stack **astack, t_stack **bstack)
{
	ft_free_ps(astack);
	ft_free_ps(bstack);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*astack;
	t_stack	*bstack;
	char	**numbers;

	if (argc < 2)
		return (0);
	if (ft_strlen_ps(argv[1]) == 0 || !ft_imput_push_swap(argv))
		ft_write_error(NULL, NULL);
	bstack = NULL;
	if (argc > 2)
		astack = ft_values(argc, argv);
	else if (argc == 2)
	{
		numbers = ft_split_ps(argv[1], ' ');
		if (!ft_imput_push_swap(numbers))
			ft_write_error(NULL, NULL);
		astack = ft_values_ps(numbers);
	}
	if (ft_duplicated_stack(astack))
		ft_write_error(NULL, NULL);
	size = ft_stack_size(astack);
	ft_index_high_to_low(astack, size + 1);
	ft_push_swap_main(&astack, &bstack, size);
	ft_free_finish(&astack, &bstack);
}
