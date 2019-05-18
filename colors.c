/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:35:12 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/18 06:44:14 by azarzor          ###   ########.fr       */
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

int *colorpall1(t_env *env)
{
	env->tab[0] = 0xE500C4;
	env->tab[1] = 0XDB00C3;
	env->tab[2] = 0xD100C3;
	env->tab[3] = 0xC700C3;
	env->tab[4] = 0xBD00C3;
	env->tab[5] = 0xB300C2;
	env->tab[6] = 0xA900C2;
	env->tab[7] = 0x9F00C2;
	env->tab[8] = 0x9500C2;
	env->tab[9] = 0x8B00C2;
	env->tab[10] = 0x8100C1;
	env->tab[11] = 0x7700C1;
	env->tab[12] = 0x6D00C1;
	env->tab[13] = 0x6300C1;
	env->tab[14] = 0x5900C0;
	env->tab[15] = 0x4F00C0;
	env->tab[16] = 0x4500C0;
	env->tab[17] = 0x3B00C0;
	env->tab[18] = 0x3100C0;
	env->tab[19] = 0x2700BF;
	env->tab[20] = 0x1D00BF;
	env->tab[21] = 0x1300BF;
	env->tab[22] = 0x0900BF;
	env->tab[23] = 0x0000BF;
	return (env->tab);
}

int *colorpall(t_env *env)
{
    env->tab[0] = 0x001E5A1E;
	env->tab[1] = 0x001C5628;
	env->tab[2] = 0x001A5232;
	env->tab[3] = 0x00184E3C;
	env->tab[4] = 0x00164A46;
	env->tab[5] = 0x00144650;
	env->tab[6] = 0x000F4650;
	env->tab[7] = 0x000D3F52;
	env->tab[8] = 0x000C3854;
	env->tab[9] = 0x000B3256;
	env->tab[10] = 0x000A2B58;
	env->tab[11] = 0x0009245B;
	env->tab[12] = 0x00081E5D;
	env->tab[13] = 0x0007175F;
	env->tab[14] = 0x00061061;
	env->tab[15] = 0x00050A64;
	env->tab[16] = 0x000A0F5F;
	env->tab[17] = 0x003A3254;
	env->tab[18] = 0x006A5549;
	env->tab[19] = 0x009A783E;
	env->tab[20] = 0x00CA9B33;
	env->tab[21] = 0x00FABE28;
	env->tab[22] = 0x00FFB428;
	env->tab[23] = 0x00FFA528;
	return (env->tab);
}

int	*colorpafll(t_env *env)
{
	env->tab[0] = 0x00A00A1E;
	env->tab[1] = 0x00930A28;
	env->tab[2] = 0x00860A32;
	env->tab[3] = 0x00790A3C;
	env->tab[4] = 0x006C0A46;
	env->tab[5] = 0x005F0A50;
	env->tab[6] = 0x00520A5A;
	env->tab[7] = 0x00460A64;
	env->tab[8] = 0x004B0A69;
	env->tab[9] = 0x00450B6C;
	env->tab[10] = 0x003F0C70;
	env->tab[11] = 0x003A0D74;
	env->tab[12] = 0x00340E78;
	env->tab[13] = 0x002F0F7C;
	env->tab[14] = 0x00291080;
	env->tab[15] = 0x00241184;
	env->tab[16] = 0x001E1288;
	env->tab[17] = 0x0019148C;
	env->tab[18] = 0x001E1987;
	env->tab[19] = 0x00652E5A;
	env->tab[20] = 0x00AD442D;
	env->tab[21] = 0x00F55A00;
	env->tab[22] = 0x00FA5F00;
	env->tab[23] = 0x00FF6400;
	return(env->tab);
}
