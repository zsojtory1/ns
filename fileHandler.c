#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	FILE *readFile;
	FILE *writeFile;
	char * line = NULL;
	char * prevLine;
	char * readSplit;
	char * prevSplit;
	char:
	size_t len = 0;
	ssize_t read;
	readFile = fopen(argv[1], "r");

	while((read = getline(&line, &len, readFile)) != -1){
		split = strtok(line, " ");
		if (prevLine != NULL)
		prevLine = line;
	}
}
