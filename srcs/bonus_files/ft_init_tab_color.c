/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:40:16 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 15:42:37 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_init_tab_w_flag(t_color *t)
{
	t->color_flag[0] = RESET;
	t->color_flag[1] = BOLD;
	t->color_flag[2] = ITALIC;
	t->color_flag[3] = UNDERLINE;
	t->color_flag[4] = REVERSE;
	t->color_flag[5] = BLACK;
	t->color_flag[6] = RED;
	t->color_flag[7] = GREEN;
	t->color_flag[8] = YELLOW;
	t->color_flag[9] = BLUE;
	t->color_flag[10] = MAGENTA;
	t->color_flag[11] = CYAN;
	t->color_flag[12] = WHITE;
	t->color_flag[13] = BG_BLACK;
	t->color_flag[14] = BG_RED;
	t->color_flag[15] = BG_GREEN;
	t->color_flag[16] = BG_YELLOW;
	t->color_flag[17] = BG_BLUE;
	t->color_flag[18] = BG_MAGENTA;
	t->color_flag[19] = BG_CYAN;
	t->color_flag[20] = NULL;
}

static void	ft_init_tab_w_color(t_color *t)
{
	t->color[0] = "{RESET}";
	t->color[1] = "{BOLD}";
	t->color[2] = "{ITALIC}";
	t->color[3] = "{UNDERLINE}";
	t->color[4] = "{REVERSE}";
	t->color[5] = "{BLACK}";
	t->color[6] = "{RED}";
	t->color[7] = "{GREEN}";
	t->color[8] = "{YELLOW}";
	t->color[9] = "{BLUE}";
	t->color[10] = "{MAGENTA}";
	t->color[11] = "{CYAN}";
	t->color[12] = "{WHiTE}";
	t->color[13] = "{BG_BLACK}";
	t->color[14] = "{BG_RED}";
	t->color[15] = "{BG_GREEN}";
	t->color[16] = "{BG_YELLOW]";
	t->color[17] = "{BG_BLUE}";
	t->color[18] = "{BG_MAGENTA}";
	t->color[19] = "{BG_CYAN}";
	t->color[20] = NULL;
}

int			ft_init_tab_color(t_color *t)
{
	ft_init_tab_w_color(t);
	ft_init_tab_w_flag(t);
	return (1);
}
