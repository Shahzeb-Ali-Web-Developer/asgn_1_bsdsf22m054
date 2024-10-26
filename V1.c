#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

// Function to display the shell prompt
void display_prompt() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("zebshell@%s:- ", cwd);
    } else {
        perror("getcwd() error");
    }
}

// Function to parse user input into command and arguments
void parse_input(char *input, char **args) {
    char *token = strtok(input, " \n");
    int index = 0;
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL;  // Null-terminate the argument list
}

int main() {
    char input[1024];
    char *args[64];

    while (1) {
        display_prompt();  // Display the prompt

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting zebshell...\n");
            break;  // Exit if CTRL+D (EOF) is pressed
        }

        // Parse the input into command and arguments
        parse_input(input, args);

        // Fork a new process
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {  // Child process
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
            }
            exit(EXIT_FAILURE);  // Exit if execvp fails
        } else {  // Parent process
            wait(NULL);  // Wait for the child process to finish
        }
    }

    return 0;
}
