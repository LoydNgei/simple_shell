#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers*/
#define READ_BUF_SIZE   1024
#define WRITE_BUF_SIZE  1024
#define BUF_FLUSH -1

/*for command chaining */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/*1 if using system getline()*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define  HIST_FILE  ".simple_shell_history"
#define  HIST_MAX   4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct  liststr *next;
}list_t;

/**
 * struct passinfo - contains  pseudo-arguments to pass into a funtion ,allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguments 
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num
