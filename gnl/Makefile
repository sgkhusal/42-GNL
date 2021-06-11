# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:17:16 by sguilher          #+#    #+#              #
#    Updated: 2021/06/11 05:18:35 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Gnl Makefile

##### Variables #####

# Gnl folder path
#GNLSRC			= ../gnl

# Gnl Sources
#MANDATORY_SRCS	= $(GNLSRC)/main.c $(GNLSRC)/get_next_line.c $(GNLSRC)/get_next_line_utils.c #mandatory.c
MANDATORY_SRCS	= main.c get_next_line.c get_next_line_utils.c #mandatory.c
#BONUS_SRCS	=

# Objects
OBJS		= $(MANDATORY_SRCS:.c=.o)
#BONUSOBJS	= $(BONUS:.c=.o)

# Outputs
MANDATORY	= mandatory
BONUS		= bonus

# Library
#LIB			= $(GNLSRC)/get_next_line.h
LIB			= get_next_line.h

# Compiler
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=12
#CFLAGS		= -g -Wall -Wextra -Werror -D BUFFER_SIZE=12#debugger
#CFLAGS		= -Wall -Werror -g -D BUFFER_SIZE=12

# clean
RM		= rm -f

##### Rules #####

all:	m #b

m:		$(MANDATORY) #cat #$(OBJS) ###############################################

#b:		$(BONUS) cat #$(BONUSOBJS)

# compilation
$(OBJS):		$(MANDATORY_SRCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(MANDATORY):	$(OBJS) $(LIB)##################################
				$(CC) $(CFLAGS) $< -o $@

#$(BONUS):		$(BONUS_TESTS) $(BONUSOBJS) $(LIB)
#				$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
		$(RM) $(OBJS) $(BONUSOBJS)

fclean:		clean
		$(RM) $(MANDATORY)

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
