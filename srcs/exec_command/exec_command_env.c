/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:38:11 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/18 16:46:24 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command_env(t_parsing *tmp, t_data *data)
{
	if (ft_strcmp(tmp->arg[0], "export") == 0)
	{
		ft_export(tmp, data);
		return (1);
	}
	else if (ft_strcmp(tmp->arg[0], "unset") == 0)
	{
		ft_unset(tmp, data);
		return (1);
	}
	else if (ft_strcmp(tmp->arg[0], "cd") == 0)
	{
		ft_cd(tmp, data);
		return (1);
	}
	else if (!ft_strcmp(tmp->arg[0], "exit"))
	{
		ft_exit(tmp, data);
		return (1);
	}
	return (0);
}
