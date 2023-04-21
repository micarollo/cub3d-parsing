/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:46:05 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/19 16:44:18 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdio.h>
# include "cub3D.h"

void	check_args(int argc, char **argv);
char	*read_file(char *path, t_master *master);
char    **create_map(int x, int y);

#endif