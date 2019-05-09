/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:21:45 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/09 14:22:04 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		calc(double start, double end, double zoom)
{
	return((start) + (end - start) * zoom);
}

void		zoom(t_env *env, double mouseRe, double mouseIm, double zoomFactor)
{
	double interpolation;

	interpolation = 1.0 / zoomFactor;
	env->minre = calc(mouseRe, env->minre, interpolation);
	env->minim = calc(mouseIm, env->minim, interpolation);
	env->maxre = calc(mouseRe, env->maxre, interpolation);
	env->maxim = calc(mouseIm, env->maxim, interpolation);
}
