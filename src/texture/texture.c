/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:41:54 by sluhtala          #+#    #+#             */
/*   Updated: 2020/07/15 18:01:53 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"


void	allocate_textures(t_scene *scene, size_t amount)
{
	if (!(scene->textures = (t_texture*)malloc(sizeof(t_texture) * amount)))
		exit_message("Error allocating textures");
	scene->num_textures = amount;
}

t_texture	new_texture(size_t id, size_t procedural, char *file, t_rgba col1, t_rgba col2, t_rgba col3)
{
	t_texture tex;

	tex.id = id;
	tex.color1 = col1;
	tex.color2 = col2;
	tex.color3 = col3;
	tex.file = file;
	if (tex.file)	
		return (tex);
	if (procedural == BRICKS)
		tex.texture_function = brick_texture;
	else if (procedural == CHECKER)
		tex.texture_function = checker_texture;
	//else if (procedural == PERLIN)
	//	tex.texture_function = &perlin_noise;
	else
	{
		tex.texture_function = NULL;
	}
	return (tex);
}

t_texture *get_texture_by_id(t_scene *scene, size_t id)
{
	size_t i;

	i = 0;
	while (i < scene->num_textures)
	{
		if (scene->textures[i].id == id)
			return (scene->textures + i);
		i++;
	}
	return (NULL);
}

t_rgba	texture_manager()
{
	t_rgba r;
	r= ft_make_rgba(1,1,1,1);
	return (r);
}
