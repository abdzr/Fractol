/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagehandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:50:32 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 15:55:25 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void			images(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	mlx_destroy_image(env->mlx_ptr, env->mlx_img);
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &(env->bpp),
			&(env->size_l), &(env->endian));
	env->row = -1;
}

double			ft_abs(double x)
{
	if (x < 0)
		return (-x);
	else if (x > 0)
		return (x);
	return (0);
}
