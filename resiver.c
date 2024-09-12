#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough args\n");
        return EXIT_FAILURE;
    }

    const int kFullAccess = 0777;
    int resiver_fd = open(argv[1], O_RDONLY, /* S_IRWXU | S_IRWXG | S_IRWXO */ kFullAccess);
    if (resiver_fd < 0) {
        perror("Cant open file:");
        return EXIT_FAILURE;
    }

    while (true) {
        #define SINGLE_CHAR 1
        char buffer[SINGLE_CHAR] = {0};
        ssize_t readed = read(resiver_fd, buffer, SINGLE_CHAR);
        if (readed > 0) {
            write(fileno(stdout), buffer, SINGLE_CHAR);
        }
    }
}

