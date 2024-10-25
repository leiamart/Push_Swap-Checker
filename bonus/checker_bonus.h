/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:41:42 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/16 21:59:05 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../push_swap.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdint.h"

void		ft_pa_checker(t_stack **a, t_stack **b);
void		ft_pb_checker(t_stack **b, t_stack **a);
void		ft_sa_checker(t_stack **stack);
void		ft_sb_checker(t_stack **stack);
void		ft_ss_checker(t_stack **stack_a, t_stack **stack_b);
void		ft_rrr_check(t_stack **astack, t_stack **bstack);
void		ft_rr_checker(t_stack **astack, t_stack **bstack);
void		ft_top_to_bottom_bonus(t_stack**stack);
void		ft_bottom_to_top_checker(t_stack **stack);
void		ft_add_bottom_bonus(t_stack **stack, t_stack *c);
t_stack		*ft_new_astack(int v);
int			ft_sizestack(t_stack *stack);
void		ft_clear_stack(t_stack **stack);
void		*ft_free_ps_bonus(char **str, int c);
int			ft_check_stack_bonus(t_stack **astack);
int			ft_compare_checker(const char *s1, const char *s2);
size_t		ft_countwords_ps(const char *s, char a);
size_t		ft_strlen_ps(const char *s);
long int	ft_atoi_b(const char *str);
t_stack		*ft_stack_a_bonus(char *str, int l);
char		*ft_substr_ps(char const *s, unsigned int start, size_t len);
char		**ft_split_ps(char const *s, char c);
void		ft_index_bonus(t_stack *stack);
void		ft_error_bonus(void);
int			ft_check_error(char **argv);
char		*ft_strjoin(char *s1, char *s2);
int			ft_check_stack_bonus(t_stack **astack);
int			ft_count_words(const char *s, char c);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_freegnl(char **str);
ssize_t		ft_strlen_gnl(char *str);
char		*ft_strchr_gnl(char *str, int c);
char		*ft_substr_gnl(char *str, unsigned int start, ssize_t len);
char		*ft_strdup_gnl(char *str);
char		*get_next_line_ps(int fd);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putunbr(unsigned int n);
int			ft_putvoid(uintptr_t n);
int			ft_putstr(char *s);
int			ft_puthexa(unsigned long long n, char c);

#endif
