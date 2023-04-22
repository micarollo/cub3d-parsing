# include "cub3D.h"
# include "parsing.h"

int	check_map_row(char *row, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (row[i] == ' ' || row[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_map_col(char **map, int rows, int j)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][j] == ' ' || map[i][j] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_round(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ' || map[x][y - 1] == '1')
		&& (map[x][y + 1] == ' ' || map[x][y + 1] == '1')
		&& (map[x + 1][y] == ' ' || map[x + 1][y] == '1')
		&& (map[x - 1][y] == ' ' || map[x - 1][y] == '1'))
			return (0);
	return (1);
}

int	check_map(char **map, t_master *master)
{
	int	i;
	int	j;

	if (check_map_row(map[0], master->map_col))
		printf("row 1 mal\n");
	if (check_map_row(map[master->map_row - 1], master->map_col))
		printf("row ultima mal\n");
	if (check_map_col(map, master->map_row, 0))
		printf("col 1 mal\n");
	if (check_map_col(map, master->map_row, (master->map_col - 1)))
		printf("col ultima mal\n");

	i = 1;
	while (i < master->map_row - 1)
	{
		j = 1;
		while (j < master->map_col - 1)
		{
			if (map[i][j] == ' ')
			{
				if (check_round(map, i, j))
				{
					printf("not closed desde check\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}