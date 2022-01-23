Homework 1
Joseph Gomes
jg3594

How To Compile & Run
====================
$ gcc -o execlp execlp.c
$ ./execlp

$ gcc -o execvp execvp.c
$ ./execvp


Description
===========

Both files create a parent process which waits for a child to do the command "ls -lh".
They both use execlp() and execvp() respectivly.
When the child completes its task it returns a return code of 0 to show that there were no errors.

