/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:49:18 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/24 16:10:26 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "parsing.h"

void	free_data(t_data *data)
{
	if (data->str_map)
		free (data->str_map);
	if (data->tex_ea)
		free (data->tex_ea);
	if (data->tex_no)
		free (data->tex_no);
	if (data->tex_so)
		free (data->tex_so);
	if (data->tex_we)
		free (data->tex_we);
	if (data->color_c)
		free (data->color_c);
	if (data->color_f)
		free (data->color_f);
	free_tab(data->map);
}

int	open_close(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_textures(t_data *data)
{
	if (!data->tex_ea || !data->tex_no || !data->tex_so || !data->tex_we)
		return (1);
	// if (open_close(data->tex_ea)|| open_close(data->tex_no)
	// 	|| open_close(data->tex_so) || open_close(data->tex_we))
	// {
	// 	printf("no abre el archivo\n");
	// 	return (1);
	// }
	return (0);
}

int parse(char *path, t_data *data)
{
    data->str_map = read_file(path, data);
    if (!data->str_map)
        return (1);
    if (check_textures(data))
	{
		free (data->str_map);
		return (1);
	}
	if (fill_map(data))
		return (1);
}