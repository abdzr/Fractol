/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:53:28 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/14 21:23:25 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_stroke(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	(key == 53) ? exit(0) : 1;
	(key == 126) ? env->max = env->max + 5 : 1;
	(key == 83) ? env->c = 1 : 1;
	(key == 84) ? env->c = 2 : 1;
	(key == 85) ? env->c = 3 : 1;
	(key == 49 && env->k == 0) ? env->k = 1 : 1;
	(key == 49 && env->k == 1) ? env->k = 0 : 1;
	choice(env);
	return (0);
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
	env->max += 1;
	choice(env);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

	env = (t_env *)param;
	if (env->c != 2)
		return (0);
	newx = ft_map(x, WIN_W, -2, 2);
	newy = ft_map(y, WIN_H, -2, 2);
	env->jul_cre = newx;
	env->jul_cim = newy;
	juliadraw(env);
	return (0);
}
