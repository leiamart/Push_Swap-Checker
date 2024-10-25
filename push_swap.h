/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:20:12 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/02 23:04:55 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "stdio.h"
# include "stddef.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void		ft_putstr_ps(char *str);
void		ft_free_ps(t_stack **stack);
int			ft_n_value(int n);
void		ft_write_error(t_stack **astack, t_stack **bstack);
int			ft_stack_size(t_stack *stack);
t_stack		*ft_new_stack(int v);
t_stack		*ft_bottom(t_stack *stack);
t_stack		*ft_before_bottom(t_stack *stack);
void		ft_add_bottom(t_stack **stack, t_stack *c);
void		ft_pa(t_stack **astack, t_stack **bstack);
void		ft_pb(t_stack **astack, t_stack **bstack);
void		ft_pb(t_stack **astack, t_stack **bstack);
void		ft_sa(t_stack **stack);
void		ft_sb(t_stack **stack);
void		ft_ss(t_stack **astack, t_stack **bstack);
void		ft_ra(t_stack **astack);
void		ft_rb(t_stack **bstack);
void		ft_rr(t_stack **astack, t_stack **bstack);
void		ft_rrr(t_stack **astack, t_stack **bstack);
void		ft_rra(t_stack **astack);
void		ft_rrb(t_stack **bstack);
void		ft_sort(t_stack **astack, t_stack **bstack);
void		ft_low_sort(t_stack **stack);
int			ft_low_position(t_stack **stack);
void		ft_cost(t_stack **astack, t_stack **bstack);
void		ft_cheap(t_stack **astack, t_stack **bstack);
void		ft_rotate_a(t_stack **a, int *cost);
void		ft_rotate_b(t_stack **b, int *cost);
void		ft_position_target(t_stack **a, t_stack **b);
void		ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
t_stack		*ft_values(int argc, char **argv);
void		ft_index_high_to_low(t_stack *astack, int size);
int			ft_imput_push_swap(char **argv);
int			ft_compare(const char *s1, const char *s2);
int			ft_is_digit_ps(char c);
int			ft_is_sign_ps(char c);
int			ft_duplicated_stack(t_stack *a);
int			ft_check_stack(t_stack *astack);
long int	ft_atoi_ps(const char *str);
size_t		ft_strlen_ps(const char *s);
char		**ft_split_ps(const char *s, char c);

#endif
