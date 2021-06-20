# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:17:16 by sguilher          #+#    #+#              #
#    Updated: 2021/06/20 06:48:53 by sguilher         ###   ########.fr        #
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
MAIN				= main.c
FD_TEST				= fd.c
REDIRECTION_TEST	= redirection.c
REDIRECTION_FILE	= file_tests/harry_potter1
BONUS_TEST			= bonus.c
# read more than 1 fd at the same time

# Output
NAME			= gnl
FD				= fd
REDIRECTION		= redirection
BONUS			= bonus

# BUFFER_SIZE Tests
BUF_SIZE	= 12
BUF_TESTS	= n1 0 1 2 3 4 7 8 11 12 13 25 100 1025 9999 10000000
ALL_BUF_TESTS	= $(addprefix buf, $(BUF_TESTS))


# Compilation
CC			= clang
#CFLAGS		= -Wall -Wextra -Werror
CFLAGS		= -g -Wall -Wextra -Werror #debugger/valgrind
LIMITS		= -D OPEN_MAX=1024 # take out in MacOX
BUF_MACRO	= -D BUFFER_SIZE=
BUF_MACRO_NEGATIVE	= -D BUFFER_SIZE=-1
COMPL		= $(CC) $(CFLAGS) $(SRCS) $(LIMITS) # Linux
#COMPL		= $(CC) $(CFLAGS) $(SRCS) -o $(NAME) # MacOX

# clean
RM			= rm -f

##### Rules #####

# simple test
all:	$(NAME) cat

# file descriptors tests
f:		$(FD) cat

# redirection test
r:		$(REDIRECTION) cat

# test different BUFFER_SIZE values
buffer:	$(ALL_BUF_TESTS) cat

# bonus - read multiple file descriptor test
b:		$(BONUS) cat

# clean
fclean:
		@$(RM) $(NAME) $(FD) $(REDIRECTION) $(ALL_BUF_TESTS) $(BONUS)

re:		fclean all

# tests
$(NAME):
		@$(COMPL) $(MAIN) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		@./$@

$(FD):
		@$(COMPL) $(FD_TEST) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		@./$@

$(REDIRECTION):
		@$(COMPL) $(REDIRECTION_TEST) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(REDIRECTION) - $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		@./$@ < $(REDIRECTION_FILE)

$(BONUS):
		@$(COMPL) $(BONUS_TEST) $(BUF_MACRO)$(BUF_SIZE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BONUS) - $(BUF_MACRO)$(BUF_SIZE)\n \033[0m"
		@./$@

bufn1:
		@$(COMPL) $(MAIN) $(BUF_MACRO_NEGATIVE) -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO_NEGATIVE)\n \033[0m"
		@./$@

buf0:
		@$(COMPL) $(MAIN) $(BUF_MACRO)0 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)0\n \033[0m"
		@./$@

buf1:
		@$(COMPL) $(MAIN) $(BUF_MACRO)1 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1\n \033[0m"
		@./$@

buf2:
		@$(COMPL) $(MAIN) $(BUF_MACRO)2 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)2\n \033[0m"
		@./$@

buf3:
		@$(COMPL) $(MAIN) $(BUF_MACRO)3 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)3\n \033[0m"
		@./$@

buf4:
		@$(COMPL) $(MAIN) $(BUF_MACRO)4 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)4\n \033[0m"
		@./$@

buf7:
		@$(COMPL) $(MAIN) $(BUF_MACRO)7 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)7\n \033[0m"
		@./$@

buf8:
		@$(COMPL) $(MAIN) $(BUF_MACRO)8 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)8\n \033[0m"
		@./$@

buf11:
		@$(COMPL) $(MAIN) $(BUF_MACRO)11 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)11\n \033[0m"
		@./$@

buf12:
		@$(COMPL) $(MAIN) $(BUF_MACRO)12 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)12\n \033[0m"
		@./$@

buf13:
		@$(COMPL) $(MAIN) $(BUF_MACRO)13 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)13\n \033[0m"
		@./$@

buf25:
		@$(COMPL) $(MAIN) $(BUF_MACRO)25 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)25\n \033[0m"
		@./$@

buf100:
		@$(COMPL) $(MAIN) $(BUF_MACRO)100 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)100\n \033[0m"
		@./$@

buf1025:
		@$(COMPL) $(MAIN) $(BUF_MACRO)1025 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)1025\n \033[0m"
		@./$@

buf9999:
		@$(COMPL) $(MAIN) $(BUF_MACRO)9999 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)9999\n \033[0m"
		@./$@

buf10000000:
		@$(COMPL) $(MAIN) $(BUF_MACRO)10000000 -o $@
		@echo "\033[1m\033[38;5;11m \nTest: $(BUF_MACRO)10000000\n \033[0m"
		@./$@

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
