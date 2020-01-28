/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:07:05 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 16:09:30 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	remake_ret_error(char **line, t_return_read_file *ret)
{
	ret->error = -1;
	return (-1);
}

int	return_error(char **line, t_return_read_file ret)
{
	if (ret.error == -1)
	{
		free(line);
		return (-1);
	}
	return (0);
}
