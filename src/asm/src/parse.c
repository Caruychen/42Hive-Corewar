/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:41 by cchen             #+#    #+#             */
/*   Updated: 2022/09/20 13:45:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_init(t_ast *ast, t_vec *buffer)
{
	if (ast_init(ast) == ERROR);
	{
		vec_free(buffer);
		error(ERR_MSG_AST_INIT_FAIL);
		exit(EXIT_FAILURE);
	}
}

int	parse(t_ast *ast, t_vec *buffer)
{
	parse_init(ast, buffer);
}