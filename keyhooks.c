/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:15 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/24 04:35:22 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int key_stroke(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	(key == 53) ? exit(0) : 1;
	(key == KEY_PLUS) ? env->max = env->max + 5 : 1;
	(key == KEY_PAD_1) ? env->c = 1 : 1;
	(key == KEY_PAD_2) ? env->c = 2 : 1;
	(key == KEY_PAD_3) ? env->c = 3 : 1;
	(key == KEY_PAD_4) ? env->c = 4 : 1;
	(key == KEY_PAD_5) ? env->c = 5 : 1;
	(key == KEY_PAD_6) ? env->c = 6 : 1;
	(key == KEY_PAD_7) ? env->c = 7 : 1;
	(key == KEY_PAD_8) ? env->c = 8 : 1;
	if (key == KEY_SPACE)
		env->k = (env->k == 0) ? 1 : 0;
	if (key == KEY_Z) 
		env->colors = color1(env);
	if (key == KEY_X)
		env->colors = color2(env);
	if (key == KEY_C)
		env->colors = color3(env);
	if (key == KEY_V)
		env->colors = color4(env);
	if (key == KEY_B)
		env->colors = color5(env);
	if (key == KEY_N)
		env->colors = color6(env);	
	if (key == KEY_A)
		env->colors = color7(env);
	if (key == KEY_S)
		env->colors = color8(env);
	if (key == KEY_R)
		{
		env->z = 0;
		env->k = 1;
		env->max = 30;
		env->scale = 1.1;
		env->colors = color1(env);
		}
	if (key == KEY_UP)
		env->yy += env->dy * 0.0009;
	if (key == KEY_DOWN)
		env->yy -= env->dy * 0.0009;
	if (key == KEY_LEFT)
		env->xx += env->dx * 0.0009;
	if (key == KEY_RIGHT)
		env->xx -= env->dx * 0.0009;
	choice(env);
	return (0);
}

void			values(t_env *env)
{
	env->mnre = ((0 - WIN_W / 2.0) * 4.0 / WIN_W) + env->yy;
	env->mxre = (WIN_W - WIN_W / 2.0) * 4.0 / WIN_W;
	env->mnim = (0 - WIN_H / 2.0) * 4.0 / WIN_W;
	env->mxim = (WIN_H - WIN_H / 2.0) * 4.0 / WIN_W;
	env->dx = env->mxre - env->mnre;
	env->dy = env->mxim - env->mnim;
}


double ft_map(double n, double start, double min, double max)
{
	double percent;

	percent = n / start;
	return (min + (max - min) * percent);
}

int mouse_zoom(int button, int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

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

int mouse_move(int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

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
