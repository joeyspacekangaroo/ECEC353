#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

        int inpipe[2];
        int outpipe[2];
        pid_t pid;

        char thingy;
        char write_mess;
        


        if(pipe(inpipe) == -1 ){
                fprintf(stderr, "failed to create pipe\n");
                return EXIT_FAILURE;

        }

        if(pipe(outpipe) == -1 ){

                fprintf(stderr, "failed to create pipe\n");
                return EXIT_FAILURE;

        }

        pid = fork();

        if(pid < 0){
                fprintf(stderr, "failed to fork\n");
                return EXIT_FAILURE;

        }

        if(pid > 0){

                close(outpipe[1]);
                close(inpipe[0]);



                while(read(STDIN_FILENO, &thingy, 1) > 0){



                        //*write_mess = read(STDIN_FILENO, thingy, 1);

                        write(inpipe[1], &thingy, 1);
                        read(outpipe[0], &write_mess,1);

                        printf("%c", write_mess);

                }


                close(inpipe[1]);
                close(outpipe[0]);
                wait(NULL);
                return EXIT_SUCCESS;

        }
        else{


                close(inpipe[1]);
                close(outpipe[0]);

                while(read(inpipe[0],&thingy,1) > 0){


                        //*read_mess = read(inpipe[0], write_mess,1);

                        write_mess = toupper(thingy);
                        write(outpipe[1], &write_mess , 1);
                }

                close(inpipe[0]);
                close(outpipe[1]);

                return EXIT_SUCCESS;

        }


}
