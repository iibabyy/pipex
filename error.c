/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:57:54 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/15 17:48:13 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_failed(char *err, char *input, char *input_join, t_data *data)
{
	ft_free((void **)&input);
	ft_free((void **)&input_join);
	free_and_exit(err, EXIT_FAILURE, data, false);
}

void	print_err_and_exit(const char *err, int code, bool fail)
{
	if (fail == true)
	{
		perror(err);
		exit(code);
	}
	if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}

void	free_and_exit(const char *err, int code, t_data *data, bool fail)
{
	if (data->limiter != NULL)
	{
		unlink(data->input_file);
	}
	ft_free((void **)&data->pid);
	ft_free((void **) &data->command_path);
	free_2d_array((void ***) &data->command);
	print_err_and_exit(err, code, fail);
}