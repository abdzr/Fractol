/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:41:47 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 17:45:32 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

double			ft_map(double n, double start, double min, double max)
{
	double percent;

	percent = n / start;
	return (min + (max - min) * percent);
}

int				mouse_zoom(int button, int x, int y, void *param)
{
	t_env		*env;
	double		newx;
	double		newy;

	env = (t_env *)param;
	newx = ft_map(x, WIN_W, env->mnre, env->mxre);
	newy = ft_map(y, WIN_H, env->mnim, env->mxim);
	if (button == 4)
	{
		env->mnre = (env->mnre - newx) * env->scale + newx;
		env->mxre = (env->mxre - newx) * env->scale + newx;
		env->mnim = (env->mnim - newy) * env->scale + newy;
		env->mxim = (env->mxim - newy) * env->scale + newy;
	}
	else if (button == 5)
	{
		env->mnre = (env->mnre - newx) / env->scale + newx;
		env->mxre = (env->mxre - newx) / env->scale + newx;
		env->mnim = (env->mnim - newy) / env->scale + newy;
		env->mxim = (env->mxim - newy) / env->scale + newy;
	}
	choice(env);
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_env		*env;
	double		newx;
	double		newy;

	env = (t_env *)param;
	if (env->c != 2 && env->c != 4 && env->c != 5)
		return (0);
	if (env->k == 0)
		return (0);
	newx = ft_map(x, WIN_W, -2, 2);
	newy = ft_map(y, WIN_H, -2, 2);
	env->jul_cre = newx;
	env->jul_cim = newy;
	if (env->c == 2)
		juliadraw(env);
	if (env->c == 4)
		juliadrawv3(env);
	if (env->c == 5)
		juliadrawv4(env);
	return (0);
}

void			mouse(t_env *env)
{
	mlx_hook(env->mlx_win, 2, 0, &key_stroke, env);
	mlx_hook(env->mlx_win, 4, 0, &mouse_zoom, env);
	mlx_hook(env->mlx_win, 6, 0, &mouse_move, env);
}
