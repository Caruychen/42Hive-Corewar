/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caruychen <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:08:03 by caruychen         #+#    #+#             */
/*   Updated: 2022/09/23 22:41:06 by caruychen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool	source_endline(t_source source)
{
	return (source.curr == '\n' || source.curr = '\0');
}

bool	source_startline(t_source source)
{
	return (source.pos.c == 1);
}