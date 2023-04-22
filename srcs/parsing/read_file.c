/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:55:52 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/19 17:48:34 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "get_next_line.h"
# include "parsing.h"

int	count_row(char *str_map)
{
	int	count;
	int	map_row;

	count = 0;
	map_row = 0;
	while (str_map[count])
	{
		if (str_map[count] != '\n')
			count++;
		else
		{
			map_row++;
			count++;
		}
	}
	map_row++;
	return (map_row);
}

int	ft_isspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

void	tex_parse_aux(char a, char b, char *line, t_master *master)
{
	if (a == 'N' && b == 'O')
		master->tex_no = tex_parse(line);
	if (a == 'S' && b == 'O')
		master->tex_so = tex_parse(line);
	if (a == 'E' && b == 'A')
		master->tex_ea = tex_parse(line);
	if (a == 'W' && b == 'E')
		master->tex_we = tex_parse(line);
	// if (!master->tex_so || !master->tex_no || ...)
	//		clean_free();
}

int	check_line(char *line, t_master *master)
{
	int	i;

	i = 0;
	if (!ft_isspace(line))
		return (1);
	while (line)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if ((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'E' && line[i + 1] == 'A')
			|| (line[i] == 'W' && line[i + 1] == 'E'))
		{
			tex_parse_aux(line[i], line[i + 1], line, master);
			return (1);
		}
		// if (line[i] == 'N' && line[i + 1] == 'O')
		// {
		// 	master->tex_no = tex_parse(line);
		// 	return (1);
		// }
		// if (line[i] == 'S' && line[i + 1] == 'O')
		// {
		// 	master->tex_so = tex_parse(line);
		// 	return (1);
		// }
		// if (line[i] == 'E' && line[i + 1] == 'A')
		// {
		// 	master->tex_ea = tex_parse(line);
		// 	return (1);
		// }
		// if (line[i] == 'W' && line[i + 1] == 'E')
		// {
		// 	master->tex_we = tex_parse(line);
		// 	return (1);
		// }
		if (line[i] == 'C')
		{
			master->color_c = ft_strdup(line);
			return (1);
		}
		if (line[i] == 'F')
		{
			master->color_f = ft_strdup(line);
			return (1);
		}
		if (line[i] == '1')
		{
			// printf("es mapa\n");
			return (0);
		}
		else
		{
			printf("Algo que no es, mapa mal?\n");
			return (1);
		}
	}
	return (0);
}

char	*read_file(char *path, t_master *master)
{
    int		fd;
	char	*line;
	int		exit;
	char	*str_map;
	int	len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Cannot read the map\n");
	line = NULL;
	exit = 0;
	master->map_col = 0;
	str_map = NULL;
	while (!exit)
	{
		line = get_next_line(fd);
		if (!line)
			exit = 1;
		else
		{
            // printf("%s", line);
			if (check_line(line, master))
				free (line);
			else
			{
				len = ft_strlen(line) - 1;
				if (len > master->map_col)
					master->map_col = len;
				str_map = ft_strjoin(str_map, line); //join_free
				free (line);
			}
		}
	}
	master->map_row = count_row(str_map);
	fill_map(str_map, master);
	return (str_map);
}