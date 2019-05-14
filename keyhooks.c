/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:53:28 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/13 16:12:33 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_stroke(int key, void *test)
{
    t_env *env;

    env = (t_env *)test;
    (key == 53) ? exit(0) : 1;
    if (key == 126)
        env->max = env->max + 5;
    if (key == 124)

    mandeldraw(env);
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
	newx = ft_map(x, WIN_W, env->minre, env->maxre);
	newy = ft_map(y, WIN_H, env->minim, env->maxim);
	if (button == 4)
	{
		env->minre = (env->minre - newx) * env->scale + newx;
		env->maxre = (env->maxre - newx) * env->scale + newx;
		env->minim = (env->minim - newy) * env->scale + newy;
		env->maxim = (env->maxim - newy) * env->scale + newy;
	}
	else if (button == 5)
	{
		env->minre = (env->minre - newx) / env->scale + newx;
		env->maxre = (env->maxre - newx) / env->scale + newx;
		env->minim = (env->minim - newy) / env->scale + newy;
		env->maxim = (env->maxim - newy) / env->scale + newy;
	}
	juliadraw(env);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

	env = (t_env *)param;
	newx = ft_map(x, WIN_W, -2, 2);
	newy = ft_map(y, WIN_H, -2, 2);
	env->jul_cre = newx;
	env->jul_cim = newy;
	juliadraw(env);
	return (0);
}
