//Alejo Ponce
//Daniel Martinez
//Ben Jimenez
//Juhn Baek

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME_SZ 256 //prompt change limit
#define MAX_CMD_LEN  128 //command line limit
#define HISTORY_COUNT 20 //history counter limit
#define CHUNK 1024 // read 1024 bytes at a time
#define MAX_STRING_LENGTH 100
#define QUIT false

char string[50];

// history function to store the commands entered by user
int history(char *hist[], int current)
{
    int i = current;
    int hist_num = 1;
    
    do {
        if (hist[i]) {
            printf("%s\n", hist[i]);
            hist_num++;
        }
        
        i = (i + 1) % HISTORY_COUNT;
        
    } while (i != current);
    
    return 0;
}

//function to clean histroy after being called
int clear_history(char *hist[])
{
    int i;
    
    for (i = 0; i < HISTORY_COUNT; i++) {
        free(hist[i]);
        hist[i] = NULL;
    }
    
    return 0;
}

int main(int argc, char *argv[])
{
    //variables for file open
    char   *input_arg[4];
    char   *input_str = NULL;
    size_t  input_len = 0;
    char  **args;
    ssize_t len;
    size_t  n;
    pid_t child, p;
    int status;
    char *hist[HISTORY_COUNT];
    int i, current = 0;
    /*  batch mode file reader */
    if (argc>1) {
        char   str[1024];
        FILE *f = fopen(argv[1], "r"); // "r" for read
        printf("*Batch Mode*\n");
        while(fgets(str, sizeof str, f)!=NULL){
            
        }
        system(str);
        fclose(f);
        return 0;
    }
    
    for (i = 0; i < HISTORY_COUNT; i++)
        hist[i] = NULL;
    for(i = 0; i<50; i++) {
        string[i] = '\0';
    }
    
    strncpy(string, "prompt", 50);
    
    printf("*** interactive mode ***\n");
    printf("type \"prompt\" at any time to change prompt\n");
    printf("type \"history\" at any time to display history\n");
    
    while (1)
    {
        for(i = 0; i < 50; i++) {
            printf("%c",string[i]);
        }
        
        printf("> ");
        
        if(argc<4)
        {
            /* No command line parameters. Read command from stdin. */
            
            len = getline(&input_str, &input_len, stdin);
            
            // for loop to invoke prompt change when user enters prompt
            if(strcmp(input_str, "prompt\n") ==0)
            {
                //for loop to clean out the trash
                for(i = 0; i<50; i++) {
                    string[i] = '\0';
                    
                }
                
                printf("enter new prompt: \n");
                fgets (string, MAX_NAME_SZ, stdin);
                printf("prompt set ...\n");
                
            }
            /* Find length excluding the newline at end. */
            if (len > (ssize_t)0){
                n = strcspn(input_str, "\r\n");
            }
            
            else{
                n = 0;
            }
            
            if (n > (size_t)0)
            {
                
                /* Terminate input command before the newline. */
                input_str[n] = '\0';
            }
            
            
            free(hist[current]);
            hist[current] = strdup(input_str);
            current = (current + 1) % HISTORY_COUNT;
            input_arg[0] = "/bin/sh";
            input_arg[1] = "-c";
            input_arg[2] = input_str;
            input_arg[3] = NULL;
            args = input_arg;
            
            //if else statments to invoke commands like history and quit
            if (strcmp(input_str, "history") == 0)
            {
                history(hist, current);
            }
            else if (strcmp(input_str, "hc") == 0)
            {
                clear_history(hist);
            }
            else if (strcmp(input_str, "quit") == 0)
            {
                exit(0);
            }
        }
        else
        {
            /* Use command line parameters */
            argv[argc] = NULL;
            args = argv + 1;
        }
        //ERROR MESSAGES-----------------------------------------------------------------------------------------------
        child = fork();
        if (child == (pid_t)-1) {
            fprintf(stderr, "Cannot fork: %s.\n", strerror(errno));
            return 1;
        }
        
        if (!child) {
            /* This is the child process. */
            
            errno = ENOENT;
            execvp(args[0], args);
            fprintf(stderr, "%s: %s.\n", args[0], strerror(errno));
            exit(127);
        }
        
        do {
            p = waitpid(child, &status, 0);
        } while (p == (pid_t)-1 && errno == EINTR);
        if (p == (pid_t)-1) {
            fprintf(stderr, "Lost child process: %s.\n", strerror(errno));
            return 127;
            
        }
        if (p != child) {
            fprintf(stderr, "waitpid() library bug occurred.\n");
            return 127;
            
        }
        
    }
    clear_history(hist);

}


