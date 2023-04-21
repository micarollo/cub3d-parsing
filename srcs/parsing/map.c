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



// void free_matrix(char** matrix, int x) {
//     for (int i = 0; i < x; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);
// }

void	*fill_with_spaces(char *str, int cols)
{
	int	i;

	i = -1;
	while (++i < cols)
		str[i] = '.';
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
		fill_with_spaces(map[i], y);
		printf("*%s*\n", map[i]);
	}
	return (map);
}


// int fill_map(char *str_map, t_master *master)
// {
// 	// char	**map;
// 	char	**aux;
// 	int		i;
// 	int		j;

// 	map = (char **)ft_calloc((master->map_row + 1), sizeof(char *));
	
	
// 	// aux = ft_split(str_map, '\n');
// 	// i = 0;
// 	// printf("DESDE SPLIT:\n");
// 	// while (i < master->map_row)
// 	// {
// 	// 	printf("%s\n", aux[i]);
// 	// 	i++;
// 	// }
// 	return (0);
// }