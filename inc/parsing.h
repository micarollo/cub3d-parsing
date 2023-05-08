/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:46:05 by anarebelo         #+#    #+#             */
/*   Updated: 2023/05/08 12:34:02 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdio.h>
# include "cub3D.h"

void	check_args(int argc, char **argv, t_master *master);
int		parse(char *path, t_map *map);
int		read_file(char *path, t_map *map);
char	**create_map(int x, int y);
int		fill_map(t_map *map);
int		check_map(char **mtx, t_map *map);
int		check_nb_rows(char *row, int cols);
int		check_nb_cols(char **map, int rows, int j);
int		check_round_2(char **map, int x, int y);
char	*tex_parse(char *str);
int		*parse_color_array(char *str);
int		check_color(int *arr);
void	free_tab(char **tab);
void	error_control(char *msj);
int		save_ini_pos(t_map *map);
int		ft_isspace(char *line);
int		check_path(char *path);
int		color_parse(char *line, char a, t_map *map);
char	*clean_color(char *str);
#endif