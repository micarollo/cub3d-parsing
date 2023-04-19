/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:28 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/19 17:48:53 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"
# include "cub3D.h"

// char	*fill_line(char *str, int len)
// {
// 	int	i;
// 	char	*line;

// 	i = ft_strlen(str);
// 	if (len > str)
// 	{
// 		line = ft_calloc()	
// 	}
// }

int fill_map(char *str_map, t_master *master)
{
	char	**map;
	char	**aux;
	int		i;
	// int		j;

	// map = (char **)ft_calloc((master->map_row + 1), sizeof(char *));
	aux = ft_split(str_map, '\n');
	i = 0;
	printf("DESDE SPLIT:\n");
	while (i < master->map_row)
	{
		printf("%s\n", aux[i]);
		i++;
	}
	// i = 0;
	// while (i < master->map_row)
	// {
	// 	map[i] = ft_calloc(master->map_col, sizeof(char));
	// 	i++;
	// }
	return (0);
}