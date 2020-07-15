/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:09:34 by sluhtala          #+#    #+#             */
/*   Updated: 2020/07/15 18:11:29 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# include "rt.h"
# define BRICKS 1
# define PERLIN 2
# define CHECKER 3

typedef struct		s_texture
{
	size_t		id;
	char		*file;
	t_rgba		(*texture_function)(double, double);
	t_rgba		color1;
	t_rgba		color2;
	t_rgba		color3;
}					t_texture;

typedef struct		s_material
{
	size_t			id;
	t_rgba			diffuse;
	double			shininess;
	double			specular;
	t_texture		*texture;	
}					t_material;

typedef struct s_scene t_scene;

t_texture	new_texture(size_t id, size_t procedural, char *file, t_rgba col1, t_rgba col2, t_rgba col3);
t_material new_material(size_t id, t_rgba diffuse, t_texture *texture);

void	allocate_textures(t_scene *scene, size_t amount);
void	allocate_materials(t_scene *scene, size_t amount);

t_rgba		brick_texture(double u, double v);
double		perlin_noise(double x, double y, unsigned char ***g);
t_rgba		checker_texture(double x, double y);

void	material_temp_function(t_scene *scene);
#endif
