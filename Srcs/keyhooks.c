/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:15 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:09:15 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

int		key_stroke(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	key_stroke2(key, test);
	(key == 53) ? exit(0) : 1;
	(key == KEY_PLUS) ? env->max += 5 : 1;
	(key == KEY_PAD_1) ? env->c = 1 : 1;
	(key == KEY_PAD_2) ? env->c = 2 : 1;
	(key == KEY_PAD_3) ? env->c = 3 : 1;
	(key == KEY_PAD_4) ? env->c = 4 : 1;
	(key == KEY_PAD_5) ? env->c = 5 : 1;
	(key == KEY_PAD_6) ? env->c = 6 : 1;
	(key == KEY_PAD_7) ? env->c = 7 : 1;
	(key == KEY_PAD_8) ? env->c = 8 : 1;
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

void	key_stroke2(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
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
	if (key == KEY_SPACE)
		env->k = (env->k == 0) ? 1 : 0;
}

void	values(t_env *env)
{
	env->mnre = ((0 - W / 2.0) * 4.0 / W) + env->yy;
	env->mxre = (W - W / 2.0) * 4.0 / W;
	env->mnim = (0 - H / 2.0) * 4.0 / W;
	env->mxim = (H - H / 2.0) * 4.0 / W;
	env->dx = env->mxre - env->mnre;
	env->dy = env->mxim - env->mnim;
	if (env->dx < 0)
		env->dx = -env->dx;
	if (env->dy < 0)
		env->dy = -env->dy;
}
