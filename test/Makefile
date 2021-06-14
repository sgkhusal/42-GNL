# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:17:16 by sguilher          #+#    #+#              #
#    Updated: 2021/06/14 03:00:42 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Gnl Makefile

##### Variables #####

# Gnl folder path
GNL_PATH	= ../gnl/

# Gnl Sources
FILES		= get_next_line.c get_next_line_utils.c
SRCS		= $(addprefix $(GNL_PATH), $(FILES))

# Output
NAME		= gnl

# Compilation
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -g -Wall -Wextra -Werror#debugger
BUF_MACRO	= -D BUFFER_SIZE=
BUF_SIZE	= 12
BUF_TESTS	= 0 1 2 3 4 7 8 11 12 13 20 25 256 257 1024 1025 9999 10000000
ALL_TESTS	= $(addprefix buf, $(BUF_TESTS))
LIMITS		= -D OPEN_MAX=1024
COMPL		= $(CC) $(CFLAGS) main.c $(SRCS) $(LIMITS) # Linux
#COMPL		= $(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME) # MacOX

# clean
RM			= rm -f

##### Rules #####

all:	$(NAME) cat

$(NAME):
		$(COMPL) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		./$@

# clean
fclean:
		$(RM) $(NAME) $(ALL_TESTS)

re:		fclean all

tests:	$(ALL_TESTS) #cat #problemmmmm

buf0:
		$(COMPL) $(BUF_MACRO)0 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)0\n \033[0m"
		./$@

buf1:
		$(COMPL) $(BUF_MACRO)1 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1\n \033[0m"
		./$@

buf2:
		$(COMPL) $(BUF_MACRO)2 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)2\n \033[0m"
		./$@

buf3:
		$(COMPL) $(BUF_MACRO)3 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)3\n \033[0m"
		./$@

buf4:
		$(COMPL) $(BUF_MACRO)4 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)4\n \033[0m"
		./$@

buf7:
		$(COMPL) $(BUF_MACRO)7 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)7\n \033[0m"
		./$@

buf8:
		$(COMPL) $(BUF_MACRO)8 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)8\n \033[0m"
		./$@

buf11:
		$(COMPL) $(BUF_MACRO)11 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)11\n \033[0m"
		./$@

buf12:
		$(COMPL) $(BUF_MACRO)12 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)12\n \033[0m"
		./$@

buf13:
		$(COMPL) $(BUF_MACRO)13 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)13\n \033[0m"
		./$@

buf20:
		$(COMPL) $(BUF_MACRO)20 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)20\n \033[0m"
		./$@

buf25:
		$(COMPL) $(BUF_MACRO)25 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)25\n \033[0m"
		./$@

buf256:
		$(COMPL) $(BUF_MACRO)256 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)256\n \033[0m"
		./$@

buf257:
		$(COMPL) $(BUF_MACRO)257 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)257\n \033[0m"
		./$@

buf1024:
		$(COMPL) $(BUF_MACRO)1024 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1024\n \033[0m"
		./$@

buf1025:
		$(COMPL) $(BUF_MACRO)1025 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1025\n \033[0m"
		./$@

buf9999:
		$(COMPL) $(BUF_MACRO)9999 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)9999\n \033[0m"
		./$@

buf10000000:
		$(COMPL) $(BUF_MACRO)10000000 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)10000000\n \033[0m"
		./$@

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
