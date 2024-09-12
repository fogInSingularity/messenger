#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough args\n");
        return EXIT_FAILURE;
    }

    const int kFullAccess = 0777;
    int sender_fd = open(argv[1], O_WRONLY | O_CREAT, /* S_IRWXU | S_IRWXG | S_IRWXO */ kFullAccess);
    if (sender_fd < 0) {
        perror("Cant open file:");
        return EXIT_FAILURE;
    }

    int hold_char = 0;
    while ((hold_char = getchar()) != EOF) {
        #define SINGLE_CHAR 1
        char mini_buf[SINGLE_CHAR] = {hold_char};    
    
        write(sender_fd, mini_buf, SINGLE_CHAR);
    }
}
