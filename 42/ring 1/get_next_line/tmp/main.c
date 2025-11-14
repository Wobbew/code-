#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
		printf("%s", line);
		free(line);

    // line = get_next_line(fd);
    // printf("%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("%s", line);
    // free(line);

    // fd = open(, O_RDONLY);
		// /* 4 */ test_gnl(fd, "aaaaaaaaaa\n");
		// /* 5 */ test_gnl(fd, "bbbbbbbbbb\n");
		// /* 6 */ test_gnl(fd, "cccccccccc\n");
		// /* 7 */ test_gnl(fd, "dddddddddd\n");
		// /* 8 */ test_gnl(fd, NULL);
    close(fd);
    return (0);

}