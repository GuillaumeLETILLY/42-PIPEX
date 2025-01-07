/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:50:57 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/06 10:51:44 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_free_tbl(char **tbl)
{
	int	i;

	if (tbl == NULL)
		return ;
	i = 0;
	while (tbl[i] != NULL)
	{
		free(tbl[i]);
		i++;
	}
	free(tbl);
}
