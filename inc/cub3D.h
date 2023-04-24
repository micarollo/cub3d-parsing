/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:20 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/24 13:28:57 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "stdio.h"

typedef struct s_data
{
	char 		**map;
	char		*tex_no;
	char		*tex_so;
	char		*tex_ea;
	char		*tex_we;
	char		*color_c;
	char		*color_f;
	int			map_col;
	int			map_row;
}	t_data;

typedef struct s_player
{
	float	px;
	float	py;
}	t_player;

typedef struct s_master
{
	t_data		data;
	t_player 	player;
}	t_master;


#endif