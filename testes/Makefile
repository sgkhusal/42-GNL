# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:17:16 by sguilher          #+#    #+#              #
#    Updated: 2021/05/18 05:18:05 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Gnl Makefile

##### Variables #####

# Gnl folder path
GNLSRC			= ../gnl

# Gnl Sources
MANDATORY_SRCS	= $(GNLSRC)/get_next_line.c $(GNLSRC)/get_next_line_utils.c
#BONUS_SRCS	=

# Tests
MANDATORY_TESTS	= mandatory.c
#BONUS_TESTS		= bonus.c

# Objects
OBJS		= $(SRCS:.c=.o)
#BONUSOBJS	= $(BONUS:.c=.o)

# Outputs
MANDATORY	= mandatory
BONUS		= bonus

# Library
LIB			= $(GNLSRC)/get_next_line.h

# Compiler
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

# clean
RM		= rm -f

##### Rules #####

all:	m #b

m:		$(MANDATORY) cat #$(OBJS) ###############################################

#b:		$(BONUS) cat #$(BONUSOBJS)

# compilation
%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(MANDATORY):	$(MANDATORY_TESTS) $(OBJS) $(LIB)##################################
				$(CC) $(CFLAGS) -c $< -o $@

#$(BONUS):		$(BONUS_TESTS) $(BONUSOBJS) $(LIB)
#				$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
		$(RM) $(OBJS) $(BONUSOBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

cat:
	@echo ""
	@echo "             /\_______/\"
	@echo "            /           \"
	@echo "           /   <0   0>   \"
	@echo "          (    =  Y  =    )"
	@echo "           \             /"
	@echo "           /    ~~~~~    \"
	@echo "          /               \    (\"
	@echo "         /        0        \    \\"
	@echo "        /  |      0      |  \    ))"
	@echo "       /   |   |  0  |   |   \  //"
	@echo "      /    |   |     |   |    \(("
	@echo "     (     |   |     |   |     )"
	@echo "      \    |   |     |   |    /"
	@echo "       \   |   |     |   |   /"
	@echo "        \_(_;_;_)___(_;_;_)_/"
	@echo ""
	@echo "           by Sheela Khusal"
	@echo ""

.PHONY: all clean fclean re
