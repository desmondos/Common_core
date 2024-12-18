/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:40:36 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 12:17:09 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_list
{
	struct s_list	*back;
	bool			pre_mid;
	bool			is_cheapest;
	int				data;
	int				cur_pos;
	int				fin_pos;
	int				move;
	struct s_list	*target;
	struct s_list	*next;
}				t_list;

bool	is_sorted(t_list *stack);

long	str_to_long(const char *nptr);

t_list	*get_cheapest_node(t_list *list);
t_list	*find_highest_node(t_list *stack);
t_list	*find_min_node(t_list *stack);
t_list	*get_last_node(t_list *stack);

int		initialize_stack(t_list **stack, char *argv[]);
void	check_argument(int ac, char **av);
void	append_to_stack(t_list **stack, int input);
void	initialize_nodes(t_list *a, t_list *b);
void	free_stack(t_list **stack);
void	free_puterror_exit(t_list **stack, char **argv);
void	puterror_exit(void);
void	ft_push(t_list **source, t_list **target);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **b, t_list **a);
void	push_swap(t_list **a, t_list **b);
void	setup_pos(t_list *stack);
void	setup_target(t_list *a, t_list *b);
void	id_cheapest_node(t_list *b);
void	set_move_costs(t_list *a, t_list *b);
void	ft_reverse_rotate(t_list **stack);
void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
void	ft_rotate(t_list **stack);
void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);
void	rot_all(t_list **a, t_list **b, t_list *cheap);
void	easy_sort(t_list **stack);
void	mid_sort(t_list **a, t_list **b);
void	ft_swap(t_list **stack);
void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);
void	ft_rot_a(t_list **a, t_list *top);
void	ft_rot_b(t_list **b, t_list *top);
void	perform_moves(t_list **a, t_list **b);
void	free_arg(char **av);
void	main_sort(t_list *a);

char	*arg_merge(int ac, char **av);
char	*ft_strcat(char *dest, const char *src);

int		has_dup(t_list *stack, int input);
int		is_valid_input(char *input);
int		min(int a, int b);
int		main(int argc, char **argv);
int		calculate_len(int ac, char **av);
int		get_stack_length(t_list *a);
int		is_lowest_value(t_list *stack);

#endif
