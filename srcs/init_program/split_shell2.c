/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:55:14 by mcraipea          #+#    #+#             */
/*   Updated: 2020/02/10 15:08:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_new_line(char *buf, char **tab, t_data *data)
{
	int			i;
	int			j;
	int			size_line;

	i = 0;
	j = 0;
	size_line = ft_strlen(buf);
	while (tab[i])
		i++;
	if (!(tab[i] = malloc(sizeof(char) * size_line + 1)))
		exit_failure("malloc", data);
	while (buf[j])
	{
		tab[i][j] = buf[j];
		j++;
	}
	tab[i][j] = '\0';
}

void			ft_simple_quote(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		buf[256];

	ft_bzero(buf, 256);
	j = 0;
	*i += 1;
	while (str[*i] && str[*i] != '\'')
	{
		buf[j++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '\'')
	{
		*i += 1;
		ft_new_line(buf, tab, data);
	}
	else
		ft_error(0, 1, data);
}

void			ft_double_quote(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		buf[256];

	ft_bzero(buf, 256);
	j = 0;
	*i += 1;
	while (str[*i] && str[*i] != '"')
	{
		buf[j++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
	{
		*i += 1;
		ft_new_line(buf, tab, data);
	}
	else
		ft_error(1, 0, data);
}

void			ft_line_basic(int *i, char *str, char **tab, t_data *data)
{
	int			j;
	char		buf[256];

	ft_bzero(buf, 256);
	j = 0;
	while (str[*i] && (str[*i] != ' ' && str[*i] != '>'
		&& str[*i] != '<' && str[*i] != '|' && str[*i] != ';'))
	{
		buf[j++] = str[*i];
		*i += 1;
	}
	ft_new_line(buf, tab, data);
	while (str[*i] && str[*i] == ' ')
		*i += 1;
}

void			ft_chevron(int *i, char *str, char **tab, t_data *data)
{
	if (str[*i + 1] == '>')
	{
		ft_new_line(">>", tab, data);
		*i += 2;
	}
	else
	{
		ft_new_line(">", tab, data);
		*i += 1;
	}
}