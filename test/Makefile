# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:17:16 by sguilher          #+#    #+#              #
#    Updated: 2021/06/14 05:20:22 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Gnl Makefile

##### Variables #####

# Gnl folder path
GNL_PATH	= ../gnl/

# Gnl Sources
FILES		= get_next_line.c get_next_line_utils.c
SRCS		= $(addprefix $(GNL_PATH), $(FILES))

# Test files
MAIN		= main.c
# fd = standard input test
# fd from a redirection test
# multiple/single long line test
# multiple/single short line test (<4)
# multiple/single empty line
# send a new line to standard output test
# Ctrl+D test
# Test binary file
# read more than 1 fd at the same time

# Output
NAME		= gnl

# BUFFER_SIZE Tests
BUF_MACRO	= -D BUFFER_SIZE=
BUF_SIZE	= 12
BUF_TESTS	= 0 1 2 3 4 7 8 11 12 13 20 25 256 257 1024 1025 9999 10000000
ALL_BUF_TESTS	= $(addprefix buf, $(BUF_TESTS))


# Compilation
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -g -Wall -Wextra -Werror#debugger
LIMITS		= -D OPEN_MAX=1024
COMPL		= $(CC) $(CFLAGS) $(SRCS) $(LIMITS) # Linux
#COMPL		= $(CC) $(CFLAGS) $(SRCS) -o $(NAME) # MacOX

# clean
RM			= rm -f

##### Rules #####

all:	$(NAME) cat

$(NAME):
		@$(COMPL) $(MAIN) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		@./$@

# clean
fclean:
		@$(RM) $(NAME) $(ALL_BUF_TESTS)

re:		fclean all

# tests
testsbuf:	$(ALL_BUF_TESTS) cat

buf0:
		$(COMPL) $(MAIN) $(BUF_MACRO)0 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)0\n \033[0m"
		./$@

buf1:
		$(COMPL) $(MAIN) $(BUF_MACRO)1 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1\n \033[0m"
		./$@

buf2:
		$(COMPL) $(MAIN) $(BUF_MACRO)2 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)2\n \033[0m"
		./$@

buf3:
		$(COMPL) $(MAIN) $(BUF_MACRO)3 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)3\n \033[0m"
		./$@

buf4:
		$(COMPL) $(MAIN) $(BUF_MACRO)4 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)4\n \033[0m"
		./$@

buf7:
		$(COMPL) $(MAIN) $(BUF_MACRO)7 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)7\n \033[0m"
		./$@

buf8:
		$(COMPL) $(MAIN) $(BUF_MACRO)8 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)8\n \033[0m"
		./$@

buf11:
		$(COMPL) $(MAIN) $(BUF_MACRO)11 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)11\n \033[0m"
		./$@

buf12:
		$(COMPL) $(MAIN) $(BUF_MACRO)12 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)12\n \033[0m"
		./$@

buf13:
		$(COMPL) $(MAIN) $(BUF_MACRO)13 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)13\n \033[0m"
		./$@

buf20:
		$(COMPL) $(MAIN) $(BUF_MACRO)20 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)20\n \033[0m"
		./$@

buf25:
		$(COMPL) $(MAIN) $(BUF_MACRO)25 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)25\n \033[0m"
		./$@

buf256:
		$(COMPL) $(MAIN) $(BUF_MACRO)256 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)256\n \033[0m"
		./$@

buf257:
		$(COMPL) $(MAIN) $(BUF_MACRO)257 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)257\n \033[0m"
		./$@

buf1024:
		$(COMPL) $(MAIN) $(BUF_MACRO)1024 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1024\n \033[0m"
		./$@

buf1025:
		$(COMPL) $(MAIN) $(BUF_MACRO)1025 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1025\n \033[0m"
		./$@

buf9999:
		$(COMPL) $(MAIN) $(BUF_MACRO)9999 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)9999\n \033[0m"
		./$@

buf10000000:
		$(COMPL) $(MAIN) $(BUF_MACRO)10000000 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)10000000\n \033[0m"
		./$@

cat:
	@echo "\n"
	@echo "\033[1;33m             /\\_______/\\"
	@echo "            /           \\"
	@echo "           /   \033[1;36m<0   0>   \033[1;33m\\"
	@echo "          (    \033[1;37m=  \033[1;35mY  \033[1;37m=    \033[1;33m)"
	@echo "           \             /"
	@echo "           /    ~~~~~    \\"
	@echo "          /               \    (\\"
	@echo "         /        0        \    \\\\"
	@echo "        /  |      0      |  \    ))"
	@echo "       /   |   |  0  |   |   \  //"
	@echo "      /    |   |     |   |    \(("
	@echo "     (     |   |     |   |     )"
	@echo "      \\    |   |     |   |    /"
	@echo "       \\   |   |     |   |   /"
	@echo "        \\_(_;_;_)___(_;_;_)_/"
	@echo ""
	@echo "         by Sheela G. Khusal\n"
	@echo ""

.PHONY: all clean fclean re
