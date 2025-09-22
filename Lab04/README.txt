CS332 – Lab 4


Description:
    This program takes two filenames as command-line arguments.
    - If the two filenames are the same, the program prints an error and exits.
    - Opens the first file in append mode (O_WRONLY | O_APPEND).
    - Opens the second file in read-only mode (O_RDONLY).
    - Appends the contents of the second file to the first file.
    - The second file is left unchanged.

Compile (inside Lab04):
    gcc -Wall -o lab4 ttbaker_lab4.c

Compile (from repo root):
    gcc -Wall -o Lab04/lab4 Lab04/ttbaker_lab4.c

Run (inside Lab04):
    ./lab4 planet1 planet2

Run (from repo root):
    ./Lab04/lab4 planet1 planet2

Example Test:
    $ echo "Hello, this is planet one!" > planet1
    $ echo "Greetings from planet two!" > planet2
    $ ./lab4 planet1 planet2
    Appended contents of planet2 to planet1 successfully.

    $ cat planet1
    Hello, this is planet one!
    Greetings from planet two!

    $ cat planet2
    Greetings from planet two!

Notes:
    - The program uses low-level UNIX system calls: open, read, write, close.
    - Buffer size = 1024 bytes.
    - Errors are handled using perror() for clear messages.
    - Do not use the same filename for both arguments.
