/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_getreference.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:52:44 by cchen             #+#    #+#             */
/*   Updated: 2022/09/27 09:52:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	lexer_getreference(t_source *source, t_symbols *sym)
{
	size_t	len;
	char	*start;

	sym->type = LA_ref;
	start = source_next(source);
	if (source_at_lineend(*source) || !is_wordch(*start))
		sym->type = LA_unknown;
	len = 1;
	while (source_next(source) && is_wordch(*(source->curr)))
		++len;
	if (!string_replace_n(&sym->str, start, len))
		return (ERROR);
	if (sym->type == LA_unknown)
		return (error(errorset(source->pos, sym->str), LEXER_BAD_REF));
	return (OK);
}