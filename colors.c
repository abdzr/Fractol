/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:35:12 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/18 07:52:33 by azarzor          ###   ########.fr       */
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

int *color1(t_env *env)
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

int *color2(t_env *env)
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

int *color3(t_env *env)
{
	env->tab[0] = 0x00141414;
	env->tab[1] = 0x00241924;
	env->tab[2] = 0x00341E34;
	env->tab[3] = 0x00452345;
	env->tab[4] = 0x00552855;
	env->tab[5] = 0x00662D66;
	env->tab[6] = 0x00763276;
	env->tab[7] = 0x00873787;
	env->tab[8] = 0x0094666F;
	env->tab[9] = 0x00A24657;
	env->tab[10] = 0x00B0253F;
	env->tab[11] = 0x00BE0528;
	env->tab[12] = 0x00BA2B46;
	env->tab[13] = 0x00B15264;
	env->tab[14] = 0x00A87982;
	env->tab[15] = 0x00A0A0A0;
	env->tab[16] = 0x00ABABAB;
	env->tab[17] = 0x00B7B7B7;
	env->tab[18] = 0x00C3C3C3;
	env->tab[19] = 0x00CFCFCF;
	env->tab[20] = 0x00DBDBDB;
	env->tab[21] = 0x00E7E7E7;
	env->tab[22] = 0x00F3F3F3;
	env->tab[23] = 0x00FFFFFF;
	return (env->tab);
}

int *color4(t_env *env)
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

int *color5(t_env *env)
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

int	*color6(t_env *env)
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

int *color7(t_env *env)
{
	env->tab[0] = 0x000A3278;
	env->tab[1] = 0x000F2D79;
	env->tab[2] = 0x0015287B;
	env->tab[3] = 0x001B247D;
	env->tab[4] = 0x00211F7F;
	env->tab[5] = 0x00271B81;
	env->tab[6] = 0x002D1682;
	env->tab[7] = 0x00331284;
	env->tab[8] = 0x00390D86;
	env->tab[9] = 0x003F0988;
	env->tab[10] = 0x0045048A;
	env->tab[11] = 0x004B008C;
	env->tab[12] = 0x00500091;
	env->tab[13] = 0x0067239B;
	env->tab[14] = 0x007F46A6;
	env->tab[15] = 0x009669B1;
	env->tab[16] = 0x00AE8CBB;
	env->tab[17] = 0x00C5AFC6;
	env->tab[18] = 0x00DDD2D1;
	env->tab[19] = 0x00F5F5DC;
	env->tab[20] = 0x00F0F0D7;
	env->tab[21] = 0x00EBCDA0;
	env->tab[22] = 0x00E6AA69;
	env->tab[23] = 0x00E18732;
	return(env->tab);
}

int *color8(t_env *env)
{
	env->tab[0] = 0x001E0500;
	env->tab[1] = 0x00270502;
	env->tab[2] = 0x00300505;
	env->tab[3] = 0x00390508;
	env->tab[4] = 0x0043050B;
	env->tab[5] = 0x004C050E;
	env->tab[6] = 0x00550511;
	env->tab[7] = 0x005F0514;
	env->tab[8] = 0x00640A14;
	env->tab[9] = 0x00781A14;
	env->tab[10] = 0x008C2B14;
	env->tab[11] = 0x00A03C14;
	env->tab[12] = 0x009B0A14;
	env->tab[13] = 0x00910914;
	env->tab[14] = 0x00870814;
	env->tab[15] = 0x007D0714;
	env->tab[16] = 0x00730714;
	env->tab[17] = 0x00690614;
	env->tab[18] = 0x005F0514;
	env->tab[19] = 0x00550514;
	env->tab[20] = 0x005A0A14;
	env->tab[21] = 0x00853214;
	env->tab[22] = 0x00B05A14;
	env->tab[23] = 0x00DC8214;
	return(env->tab);
}