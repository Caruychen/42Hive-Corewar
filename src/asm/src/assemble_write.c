/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:35 by cchen             #+#    #+#             */
/*   Updated: 2022/10/06 10:47:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "errors.h"
#include "definitions.h"
#include "assemble.h"

static void	open_file(int *fd, t_assembler *assembler)
{
	const char	*filename;

	filename = assembler->filename.memory;
	*fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (*fd > ERROR)
		return ;
	assemble_free(assembler);
	exit_error();
}

static void	write_file(int fd, t_assembler *assembler)
{
	ssize_t		res;
	t_string	buffer;
	size_t		written;

	buffer = assembler->buffer;
	written = 0;
	while (written < buffer.length)
	{
		res = write(fd, buffer.memory + written, buffer.length - written);
		if (res == ERROR)
		{
			assemble_free(assembler);
			exit_error();
		}
		if (!res)
			break ;
		written += (size_t) res;
	}
}

/* Writes bytecode to file */
void	assemble_write(t_assembler *assembler)
{
	int	fd;

	ft_printf("Writing output program to %s\n", assembler->filename.memory);
	open_file(&fd, assembler);
	write_file(fd, assembler);
	close(fd);
}
