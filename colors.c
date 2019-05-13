/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:35:12 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/12 15:41:45 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rgb(int r, int g, int b)
{
	unsigned char clr[4];
	clr[0] = b;
	clr[1] = g;
	clr[2] = r;
	clr[3] = 0;
	return (*(int *)clr);
}

int *clrs(t_env *env)
{
	env->tab[0] = rgb(238, 205, 163);
	env->tab[1] = rgb(238, 198, 162);
	env->tab[2] = rgb(238, 191, 162);
	env->tab[3] = rgb(238, 184, 162);
	env->tab[4] = rgb(238, 178, 162);
	env->tab[5] = rgb(238, 171, 161);
	env->tab[6] = rgb(238, 164, 161);
	env->tab[7] = rgb(238, 158, 161);
	env->tab[8] = rgb(238, 151, 161);
	env->tab[9] = rgb(238, 144, 160);
	env->tab[10] = rgb(238, 138, 160);
	env->tab[11] = rgb(238, 131, 160);
	env->tab[12] = rgb(238, 124, 160);
	env->tab[13] = rgb(238, 138, 160);
	env->tab[14] = rgb(238, 144, 160);
	env->tab[15] = rgb(238, 151, 161);
	env->tab[16] = rgb(238, 158, 161);
	env->tab[17] = rgb(238, 164, 161);
	env->tab[18] = rgb(238, 171, 161);
	env->tab[19] = rgb(238, 178, 162);
	env->tab[20] = rgb(238, 184, 162);
	env->tab[21] = rgb(238, 191, 162);
	env->tab[22] = rgb(238, 198, 162);
	env->tab[23] = rgb(238, 205, 163);
	return (env->tab);
}

int *fireorange(t_env *env)
{
	env->tab[0] = rgb(250, 116, 43);
	env->tab[1] = rgb(250, 123, 48);
	env->tab[2] = rgb(250, 130, 54);
	env->tab[3] = rgb(250, 137, 59);
	env->tab[4] = rgb(251, 145, 65);
	env->tab[5] = rgb(251, 152, 71);
	env->tab[6] = rgb(251, 159, 76);
	env->tab[7] = rgb(252, 167, 82);
	env->tab[8] = rgb(252, 174, 88);
	env->tab[9] = rgb(252, 181, 93);
	env->tab[10] = rgb(253, 189, 99);
	env->tab[11] = rgb(253, 196, 104);
	env->tab[12] = rgb(253, 196, 104);
	env->tab[13] = rgb(253, 189, 99);
	env->tab[14] = rgb(252, 181, 93);
	env->tab[15] = rgb(252, 174, 88);
	env->tab[16] = rgb(252, 167, 82);
	env->tab[17] = rgb(251, 159, 76);
	env->tab[18] = rgb(251, 152, 71);
	env->tab[19] = rgb(251, 145, 65);
	env->tab[20] = rgb(250, 137, 59);
	env->tab[21] = rgb(250, 130, 54);
	env->tab[22] = rgb(250, 123, 48);
	env->tab[23] = rgb(250, 116, 43);
	return (env->tab);
}

int *aqua_blue(t_env *env)
{
	env->tab[0] = rgb(233, 89, 81);
	env->tab[1] = rgb(93, 181, 199);
	env->tab[2] = rgb(247, 216, 120);
	env->tab[3] = rgb(230, 230, 234);
	env->tab[4] = rgb(244, 244, 248);
	env->tab[5] = rgb(244, 244, 248);
	env->tab[6] = rgb(230, 230, 234);
	env->tab[7] = rgb(247, 216, 120);
	env->tab[8] = rgb(93, 181, 199);
	env->tab[9] = rgb(233, 89, 81);
	env->tab[10] = rgb(233, 89, 81);
	env->tab[11] = rgb(93, 181, 199);
	env->tab[12] = rgb(247, 216, 120);
	env->tab[13] = rgb(230, 230, 234);
	env->tab[14] = rgb(244, 244, 248);
	env->tab[15] = rgb(244, 244, 248);
	env->tab[16] = rgb(230, 230, 234);
	env->tab[17] = rgb(247, 216, 120);
	env->tab[18] = rgb(93, 181, 199);
	env->tab[19] = rgb(233, 89, 81);
	env->tab[20] = rgb(233, 89, 81);
	env->tab[21] = rgb(93, 181, 199);
	env->tab[22] = rgb(247, 216, 120);
	env->tab[23] = rgb(230, 230, 234);
	return (env->tab);
}