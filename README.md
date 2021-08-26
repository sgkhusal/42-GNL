# GNL-42SP
Get Next Line 42 Project

The get_next_line function reads one line at a time from a file.

function prototype: `int	get_next_line(int fd, char **line);`

#### Return values:
- 1 if readed a line
- 0 if end of file
- -1 if error

## How to use
- add `#include <path/gnl/get_next_line.h>`
- call `get_next_line(int fd, char **line)`

OBS: The file descriptor must have be open before\
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
