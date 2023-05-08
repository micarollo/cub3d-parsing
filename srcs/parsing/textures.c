/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/08 15:29:36 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

char	*tab_to_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	tex_check_name(char *str)
{
	if (ft_strcmp(str, "NO") != 0 && ft_strcmp(str, "SO") != 0
		&& ft_strcmp(str, "EA") != 0 && ft_strcmp(str, "WE") != 0)
	{
		error_control("Texture name not correct\n");
		return (1);
	}
	return (0);
}

int	tex_len_check(char **tab)
{
	int	len;

	len = tab_len(tab);
	if (len > 2)
	{
		if ((ft_strcmp(tab[2], "\n") == 0) && (len == 3))
			return (0);
		error_control("Texture usage: <NO/SO/EA/WE ./path>\n");
		return (1);
	}
	return (0);
}

char	*tex_parse(char *str)
{
	char	**tab;
	char	*new;

	str = tab_to_space(str);
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	if (tex_len_check(tab) || tex_check_name(tab[0]))
		return (NULL);
	new = ft_strtrim(tab[1], "\n");
	if (!new)
	{
		free_tab(tab);
		error_control("Texture error\n");
		return (NULL);
	}
	free_tab(tab);
	return (new);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*fill_color_array(char **tab)
{
	int	*color;
	int	len;
	int	i;

	len = len_tab(tab);
	if (len != 3)
		return (NULL);
	color = (int *)ft_calloc(len + 1, sizeof(int));
	if (!color)
	{
		free_tab(tab);
		return (NULL);
	}
	i = -1;
	while (tab[++i])
		color[i] = ft_atoi(tab[i]);
	return (color);
}

int	*parse_color_array(char *line)
{
	char	**tab;
	int		*color;
	char	*clean;

	line = tab_to_space(line);
	clean = clean_color(line);
	if (!clean)
		return (NULL);
	tab = ft_split(clean, ',');
	if (!tab)
	{
		free (clean);
		return (NULL);
	}
	free(clean);
	color = fill_color_array(tab);
	if (!color)
		return (NULL);
	free_tab(tab);
	return (color);
}
