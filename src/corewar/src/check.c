/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:57:59 by molesen           #+#    #+#             */
/*   Updated: 2022/10/14 11:58:01 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	delete_carriage(t_info *info, int id)
{
	t_carriage	*carriage;
	t_carriage	*prev;

	carriage = info->head_carriage;
	prev = NULL;
	while (carriage)
	{
		if (carriage->id == id)
		{
			if (!carriage->next && !prev)
				info->head_carriage = NULL;
			else if (!carriage->next)
				prev->next = NULL;
			else if (!prev)
				info->head_carriage = carriage->next;
			else
				prev->next = carriage->next;
			free(carriage);
			return ;
		}
		prev = carriage;
		carriage = carriage->next;
	}
}

static void	print_process_killed(t_info *info, t_carriage *carriage)
{
	if (info->cycles_to_die < 0)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", \
		carriage->id, info->total_cycles - carriage->last_live_call - 1, \
		info->cycles_to_die);
	else
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", \
		carriage->id, info->total_cycles - carriage->last_live_call - 1, \
		info->cycles_to_die);
}

static void	check_carriage_live_call(t_info *info)
{
	t_carriage	*carriage;
	t_carriage	*next;
	int			limit;

	carriage = info->head_carriage;
	if (info->cycles_to_die < 0)
		limit = info->total_cycles - 1;
	else
		limit = info->total_cycles - info->cycles_to_die - 1;
	while (carriage)
	{
		if (carriage->last_live_call <= limit)
		{
			next = carriage->next;
			if ((info->flag[V_FLAG] >= 8 && info->flag[V_FLAG] <= 15) || info->flag[V_FLAG] == 24)
				print_process_killed(info, carriage);
			delete_carriage(info, carriage->id);
			carriage = next;
		}
		else
			carriage = carriage->next;
	}
}

void	check(t_info *info)
{
	info->cycle_count -= 1;
	info->total_cycles += 1;
	if (info->cycle_count <= 0)
	{
		check_carriage_live_call(info);
		if (info->live_statement >= NBR_LIVE)
		{
			info->cycles_to_die = info->cycles_to_die - CYCLE_DELTA;
			info->checks_count = 0;
			print_cycle_count(info);
		}
		else
		{
			info->checks_count += 1;//unsure about corellation of max_checks and checks_count....
			if (info->checks_count >= MAX_CHECKS)
			{
				info->cycles_to_die = info->cycles_to_die - CYCLE_DELTA;
				info->checks_count = 0;
				print_cycle_count(info);
			}
		}
		//info->checks_count += 1;
		info->cycle_count = info->cycles_to_die;
		info->live_statement = 0;
	}
}
