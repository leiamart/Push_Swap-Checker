/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:58:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/16 21:54:29 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error_bonus(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_operations_checker(t_stack **astack, t_stack **bstack, char *str)
{
	if (ft_compare_checker(str, "pa\n") == 0)
		ft_pa_checker(astack, bstack);
	else if (ft_compare_checker(str, "pb\n") == 0)
		ft_pb_checker(bstack, astack);
	else if (ft_compare_checker(str, "sa\n") == 0)
		ft_sa_checker(astack);
	else if (ft_compare_checker(str, "sb\n") == 0)
		ft_sb_checker(bstack);
	else if (ft_compare_checker(str, "ss\n") == 0)
		ft_ss_checker(astack, bstack);
	else if (ft_compare_checker(str, "ra\n") == 0)
		ft_top_to_bottom_bonus(astack);
	else if (ft_compare_checker(str, "rb\n") == 0)
		ft_top_to_bottom_bonus(bstack);
	else if (ft_compare_checker(str, "rr\n") == 0)
		ft_rr_checker(astack, bstack);
	else if (ft_compare_checker(str, "rra\n") == 0)
		ft_bottom_to_top_checker(astack);
	else if (ft_compare_checker(str, "rrb\n") == 0)
		ft_bottom_to_top_checker(bstack);
	else if (ft_compare_checker(str, "rrr\n") == 0)
		ft_rrr_check(astack, bstack);
	else
		ft_error_bonus();
	free(str);
}

t_stack	*ft_stack_checker(int argc, char **argv, t_stack *astack)
{
	char	*str;
	char	*temp;
	int		i;

	str = "";
	i = 1;
	if (argc == 2)
	{
		astack = ft_stack_a_bonus(argv[1], ft_count_words(argv[1], ' '));
	}
	else if (argc > 2)
	{
		while (i <= argc)
		{
			str = ft_strjoin(str, argv[i]);
			i++;
		}
		astack = ft_stack_a_bonus(str, ft_count_words(str, ' '));
		free(str);
	}
	return (astack);
}

t_stack	*ft_checker_ps(t_stack **astack, t_stack **bstack, char *c)
{
	while (c)
	{
		ft_operations_checker(astack, bstack, c);
		c = get_next_line_ps(STDIN_FILENO);
	}
	free(c);
	if (ft_check_stack_bonus(astack) == 1 && ft_sizestack(*bstack) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clear_stack(bstack);
	ft_clear_stack(astack);
	return (*astack);
}

int	main(int argc, char **argv)
{
	t_stack	*astack;
	t_stack	*bstack;
	char	*c;

	astack = NULL;
	bstack = NULL;
	c = "";
	if (argc >= 2)
	{
		astack = ft_stack_checker(argc, argv, astack);
		if (astack == NULL)
		{
			write(2, "Error\n", 6);
			ft_clear_stack(&astack);
			return (0);
		}
		c = get_next_line_ps(STDIN_FILENO);
		astack = ft_checker_ps(&astack, &bstack, c);
	}
	ft_clear_stack(&astack);
	return (0);
}
