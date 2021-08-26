# GNL-42SP
Get Next Line 42 Project

The get_next_line function reads one line at a time from a text file\

Calling get_next_line function in a loop will then allow you to read the text file one line at a time until the end of it.

Bonus: To be able to manage multiple file descriptors with your get_next_line. For
example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can
call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc.
without losing the reading thread on each of the descriptors.

## Index

- [gnl:](https://github.com/sgkhusal/GNL/tree/main/gnl) code developed for the project
- [test:](https://github.com/sgkhusal/GNL/tree/main/test) my own test program
- [gnl-testers:](https://github.com/sgkhusal/GNL/tree/main/gnl-testers) other external tests

## Get_next_line function - <[gnl:](https://github.com/sgkhusal/GNL/tree/main/gnl)> folder

function prototype: `int	get_next_line(int fd, char **line);`

#### Return values:
- 1 if readed a line
- 0 if reached end of file
- -1 if error

Note: Files in suffixed with _bonus_ in <gnl> folder are copies of corresponding files.

## How to use
- git clone https://github.com/sgkhusal/GNL.git
- add get_next_line header in your file: `#include 'path/gnl/get_next_line.h'`
- call `get_next_line(int fd, char **line)`
- in compilation, call `path/gnl/get_next_line.c path/gnl/get_next_line_utils.c -D BUFFER_SIZE=<size>`

Note: The file descriptor must be open before get_next_line function\
Eg: `fd = open(file_name, O_RDONLY);`

# GNL-Tester
This tester was made for the old version of 42 school get_next_line project

## How to use the tester
### In test folder:
- Change your GNL_PATH in the makefile
- make - mandatory tests
- make buffer - mandatory tests for BUFFER_SIZE=-1, 0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 25, 100, 1025, 9999 and 10000000
- make bufn1 - mandatory tests for BUFFER_SIZE=-1
- make bufnumber - mandatory tests for `BUFFER_SIZE=number` (number = 0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 25, 100, 1025, 9999 or 10000000)\
For the tests below you can change BUFFER_SIZE value in the makefile:
- make
- make r: redirection test (bonus)
- make f: fd tests (bonus)
- make b: other bonus tests
