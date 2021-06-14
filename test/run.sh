## basic test
make

## BUFFER_SIZE tests
#make tests

# fd = standard input test
clang -Wall -Wextra -Werror main.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# fd from a redirection test
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# multiple/single long line test
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# multiple/single short line test (<4)
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# multiple/single empty line
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# send a new line to standard output test
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# Ctrl+D test
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# Test binary file
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
# read more than 1 fd at the same time
clang -Wall -Wextra -Werror file.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c -D OPEN_MAX=1024 -D BUFFER_SIZE=12 -o stdinput
