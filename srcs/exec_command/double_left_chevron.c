/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_left_chevron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:24:33 by pganglof          #+#    #+#             */
/*   Updated: 2020/02/07 13:14:57 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		double_left_chevron(t_list **tmp, t_data *data)
{
	while (((t_parsing*)((*tmp)->content))->ld_chevron)
	{
		*tmp = (*tmp)->next;
		data->mypipefd[1] = open(((t_parsing*)((*tmp)->content))->arg[0],
		O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		if (((t_parsing*)((*tmp)->content))->arg[1] != NULL)
			((t_parsing*)(data->lst_parsing->content))->arg =
			add_arg2(((t_parsing*)(data->lst_parsing->content))->arg,
			((t_parsing*)((*tmp)->content))->arg, data);
	}
	data->savestdout = dup(STDOUT_FILENO);
	dup2(data->mypipefd[1], STDOUT_FILENO);
}
