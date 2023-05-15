#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/*---------------------------------------------------------------*/

/* for tokenization of strings */

typedef struct {
    char *cur_tok_st;
    char *nxt_tok_st;
} Tokenizer, o_tok;

/* call the f_tokenizer function before using s_tok function passing in the parameters */
void f_tokenizer(Tokenizer *tokenizer, char *input_string);
char *s_tok(Tokenizer *tokenizer, const char *delimiters);
char **prs(char *command, size_t k);
void reallocate(char **args, char **av, int argc);
/*--------------------------------------------------------------*/
int open_file(const char* filename);
char* read_lines(int fd);
char* read_file(const char* filename);
void file_process(char **argv, char **av, char *cmd, char *Name, int argc);
/*--------------------------------------------------------------*/
extern char** environ;

void execute_command(char** args, char** envp, size_t n, char *Name, int argc);
void exec_command(char** args, char** envp, char *arg, char *Name, int argc);
char* find_executable(char *argv);
int is_executable(char *argv);
/*---------------------------------------------------------------*/
void cd_command(char** args, char *NAME, int argc);
void exit_command(char** args, char *NAME, int argc);
void setenv_command(char** args, char *NAME, int argc);
void unsetenv_command(char** args, char *NAME, int argc);
void help_command(char** args, char *NAME, int argc);
int execute_builtin_command(char** args, char *NAME, int argc);

struct built_in
{
    char *name;
    void (*function)(char **args, char *NAME, int argc);
};

/*--------------------------------------------------------------------------*/

#endif /* MAIN_H */
