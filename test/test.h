/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:00 by sguilher          #+#    #+#             */
/*   Updated: 2021/07/01 21:37:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

//# define BUFFER_SIZE 12
//# define OPEN_MAX 256

# define TITLE1(string)		"\033[1;33m" string "\033[0m"
# define TITLE2(string)		"\033[0;32m" string "\033[0m"
# define LINE(string)		"\033[38;5;75m" string "\033[0m"
# define GNL_RET(string)		"\033[38;5;43m" string "\033[0m"
# define LINE_RET(string)	"\033[0;33m" string "\033[0m"
# define LINE_NOT_OK(string)	"\033[1;31m" string "\033[0m"
# define LINE_OK(string)		"\033[1;32m" string "\033[0m"

# define NOT_OK	0
# define OK		1

#endif