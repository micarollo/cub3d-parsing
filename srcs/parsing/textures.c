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

char	*tex_parse(char *str)
{
	char	**tab;
	char	*new;
	// int	i;

	str = tab_to_space(str);
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL); //manejar en la otra funcion
	new = ft_strdup(tab[1]);
	if (!new)
		return (NULL); //manejar en la otra funcion
	// new = '\0';
	// i = -1;
	// while (tab[++i])
	// {
	// 	new = ft_strjoin(new, tab[i]);
	// 	if (!new)
	// 		return (NULL); //QUE HAGOOOOOO
	// 	if (i == 0)
	// 	{
	// 		new = ft_strjoin(new, " ");
	// 		if (!new)
	// 			return (NULL); //QUE HAGOOOOOO
	// 	}
	// }
	free_tab(tab);
	return (new);
}