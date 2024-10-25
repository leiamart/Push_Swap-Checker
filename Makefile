# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 23:47:02 by leiamart          #+#    #+#              #
#    Updated: 2024/10/15 22:12:35 by leiamart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = clang
CFLAGS = -g -Wall -Wextra -Werror

SOURCES = \
push_swap_utils.c\
push_swap_position.c\
push_swap_stack.c\
push_swap_sort.c\
push_swap_cost.c\
push_swap_move.c\
push_swap_initialization.c\
main_push_swap.c\
sa.c\
push_swap_p.c\
push_swap_rotate.c\
push_swap_rev_rotate.c\
push_swap_imput_check_utils.c\
push_swap_imput_check.c\
ft_split_pushswap.c\

SOURCES_BONUS = \
./bonus/checker_moves_bonus.c\
./bonus/checker_rotate_bonus.c\
./bonus/checker_stack_bonus.c\
./bonus/checker_utils_bonus.c\
./bonus/checker_imput_bonus.c\
./bonus/index_bonus.c\
./bonus/get_next_line_ps_bonus.c\
./bonus/get_next_line_utils_ps_bonus.c\
./bonus/main_checker_bonus.c\
./bonus/split_push_swap_bonus.c\
./bonus/more_utils_bonus.c\
./bonus/ft_printf_bonus.c\
./bonus/ft_printf_utils_bonus.c\

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	 $(CC) -g $(FLAGS) $(OBJECTS) -o $(NAME)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re 
