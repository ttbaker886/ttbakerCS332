/*
CS332 – Lab 4

Compile (from repo root):
    gcc -Wall -o Lab04/lab4 Lab04/ttbaker_lab4.c

Run (from repo root):
    ./Lab04/lab4 planet1 planet2


Compile (inside Lab04):
    gcc -Wall -o lab4 ttbaker_lab4.c

Run (inside Lab04):
    ./lab4 planet1 planet2

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // read, write, close
#include <fcntl.h>    // open flags
#include <string.h>   // strcmp
#include <errno.h>    // errno, perror

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file1 = argv[1];
    char *file2 = argv[2];

    if (strcmp(file1, file2) == 0) {
        fprintf(stderr, "Error: file1 and file2 must be different.\n");
        exit(EXIT_FAILURE);
    }

    int fd1 = open(file1, O_WRONLY | O_APPEND);
    if (fd1 < 0) {
        perror("Error opening file1");
        exit(EXIT_FAILURE);
    }

    int fd2 = open(file2, O_RDONLY);
    if (fd2 < 0) {
        perror("Error opening file2");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZE];
    ssize_t nread;
    while ((nread = read(fd2, buffer, BUFSIZE)) > 0) {
        ssize_t nwritten = write(fd1, buffer, nread);
        if (nwritten != nread) {
            perror("Error writing to file1");
            close(fd1);
            close(fd2);
            exit(EXIT_FAILURE);
        }
    }
    if (nread < 0) {
        perror("Error reading file2");
    }

    close(fd1);
    close(fd2);

    printf("Appended contents of %s to %s successfully.\n", file2, file1);
    return 0;
}
