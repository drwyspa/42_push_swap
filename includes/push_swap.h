/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:14:51 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/27 16:55:35 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
///////////////////
# include <stdbool.h>

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

//Sorting Algorithms
int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

//Operations
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

//Stack operations
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);

//Position
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **a, t_stack **b);

//Costs
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//Calculate move
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

//Input check
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
int			is_correct_input(char **argv);

//Utils
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		**arraydup(char **array);
char		*ft_strdup(const char *s);
int			freearray(char **array);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);

//Init
t_stack		*fill_stack_values(t_stack *stack_a, char **array);
void		assign_index(t_stack *stack_a, int stack_size);

//Error handling
void		exit_error(t_stack **stack_a, t_stack **stack_b, char **array);

#endif