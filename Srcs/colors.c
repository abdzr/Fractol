/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:35:12 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 18:28:46 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

int		rgb(int r, int g, int b)
{
	unsigned char clr[4];

	clr[0] = b;
	clr[1] = g;
	clr[2] = r;
	clr[3] = 0;
	return (*(int *)clr);
}

int		*color1(t_env *env)
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

int		*color2(t_env *env)
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

int		*color3(t_env *env)
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

int		*color4(t_env *env)
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
