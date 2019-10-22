#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void showMenu();
void createFile(char* fileName);
void writeFile(char* fileName);
void readFile(char* fileName);
void changeRight(char* fileName);
void readRight(char* fileName);
