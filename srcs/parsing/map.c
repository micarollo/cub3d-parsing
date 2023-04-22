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

void free_map(char** map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
    free(map);
}

void	*fill_with_spaces(char *str, int cols)
{
	int	i;

	i = -1;
	while (++i < cols)
		str[i] = ' ';
	str[i] = '\0';
}

char **create_map(int x, int y)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc((x + 1), sizeof(char *));
	if (!map)
		return (NULL); //clean_free
	i = -1;
	while (++i < x)
	{
		map[i] = (char*)calloc(y + 1, sizeof(char));
		if (!map[i])
			return (NULL); //clean_free
		fill_with_spaces(map[i], y);
		printf("*%s*\n", map[i]);
	}
	return (map);
}

void	fill_row(char *str, char *map_row)
{
	int	i;

	i = 0;
	while (str[i])
	{
		map_row[i] = str[i];
		i++;
	}
}

int fill_map(char *str_map, t_master *master)
{
	char	**aux;
	char	**map;
	int		i;

	map = create_map(master->map_row, master->map_col);
	aux = ft_split(str_map, '\n'); //proteger
	i = 0;
	printf("\n\nFILLINGGG:\n");
	while (i < master->map_row)
	{
		fill_row(aux[i], map[i]);
		printf("*%s*\n", map[i]);
		i++;
	}
	check_map(map, master);
	free_map(map);
	return (0);
}