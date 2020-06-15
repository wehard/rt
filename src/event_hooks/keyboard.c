/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:06:46 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/06/15 19:49:06 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keys.h"

int	key_press_hook(int key, t_rt *rt)
{
	ft_printf("scene %d, press key %d\n", rt->cur_scene, key);
	return (0);
}

int	key_release_hook(int key, t_rt *rt)
{
	ft_printf("scene %d, release key %d\n", rt->cur_scene, key);
	if (key == KEY_SPACE)
	{
		mlx_clear_window(rt->mlx->mlx_ptr, rt->mlx->win_ptr);
		render_scene(rt, rt->scenes[rt->cur_scene]);
	}
	else if (key == KEY_ESC)
	{
		close_hook(rt);
	}
	return (0);
}
