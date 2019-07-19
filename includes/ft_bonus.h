/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:04:08 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/02 19:04:10 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define REVERSE	"\033[7m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"

/*
** 			----	BONUS	---
**
** 1 - Types : n, b, ib, k :
**
** n : the number of char write before %n and entered in the variable in params;
** b : unsigned int, binary code;
** ib : 2 args, on it's a number, one it's base;
** uz : size_t;
** k : transform the number in date or date and hour for ISO8601;
**
** 2 - Buffer of 512, when the buffer of 2048 is full it prints;
**
** 3 - When the buffer match \n, it writes or it writes at the end of process;
**
** 4 - The most static for speed;
**
** 5 - Color, if you put {color} just before % the answer is in color
**if you put {color} somewhere the all of answer is in this color or put {reset};
**
*/


#endif