# asgn_1_bsdsf22m054
The purpose of this assignment is to give you practice in the use of UNIX system calls and writing a command interpreter on top
of UNIX. The Shell as described by Richard Stevens in his book Advanced Programming in the UNIX environment is a
command-line interpreter that reads user input and execute commands. For some it is a user interface between user and the
internals of operating system whose job is to intercept user’s command and then trigger system calls to ask OS to accomplish the
user’s tasks. For me it is a program executing another program.
A shell mainly consists of two parts: parsing user requests and accomplishing user request with system call’s help. In this
assignment you will write your own command shell to gain experience with some advanced programming techniques like process
creation and control, file descriptors, signals, I/O redirection and pipes.
