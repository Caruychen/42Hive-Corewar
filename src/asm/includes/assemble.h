/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:13 by cchen             #+#    #+#             */
/*   Updated: 2022/10/06 10:55:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLE_H
# define ASSEMBLE_H

# include "Strings.h"
# include "parse.h"
# define BITS	8

/* Assembly stage, writes the binary once text parsing is complete. */
typedef struct s_assembler
{
	t_string	filename;	
	t_string	buffer;
	t_parser	*parser;
}				t_assembler;

void		assemble(t_parser *parser, const char *arg);
void		assemble_buffer(t_assembler *assembler);
void		assemble_write(t_assembler *assembler);
void		assemble_free(t_assembler *assembler);
t_string	*assemble_push_int(t_string *buffer, uint32_t num);
t_string	*assemble_push_num(t_string *buffer, t_arg arg, uint8_t size);

#endif
