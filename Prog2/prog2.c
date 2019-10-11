/*
NAME : CYNTHIA HA
CS 220
PROF. CONFER
WORKED WITH LUKE KRENTZ AND JENNY LI

02/25/17
*/

//libraries//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
//prototypes//
void load_file_to_buffer(char *filename, char **buffer);
void process_data(char **line);
int str_to_us(char **str, int base);
int str_to_sm(char **str, int base);
int str_to_one(char **str, int base);
//global variables//
FILE *file = NULL;
char *buffer = NULL;

int main (int argc, char *argv[]) {
	bool done;
	char *c = NULL;

	if (argc != 2) {
		fprintf(stderr, "ERROR:to many/few arguments\n");
		exit(EXIT_FAILURE);
	}

	load_file_to_buffer(argv[1], &buffer);

	c = buffer;
	done = false;
	while(!done) {
		switch(*c) {

		case '\0':
			/*END OF FILE*/
			done = true;
			break;

		case '#':
			/*IGNORE COMMENT UNTIL END OF LINE*/
			do {
				c++;
			} while (*c != '\n' && *c != '\r' && *c != '\0');
			break;

		case '\n':
		case '\r':
			/*SKIPS LINE*/
			c++;
			break;

		default:
			/*READ IN DATA*/
			process_data(&c);
			break;
		}
	}

	fclose(file);
	free(buffer);
	buffer = NULL;

	return EXIT_SUCCESS;
}


void load_file_to_buffer(char *filename, char **buffer) {

	long tell_size;
	size_t size;
	bool done = false;

	if(buffer == NULL || *buffer != NULL) {
		fprintf(stderr, "ERROR: buffer cannot be used\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "rb");
	if (file) {
		if(fseek(file, 0, SEEK_END) == 0) {
			if((tell_size = ftell(file)) != EOF) {
				rewind(file);
				done = true;
			}
		}
	}

	if(!done) {
		fprintf(stderr, "ERROR: File input failed\n");
		perror("");
		exit(EXIT_FAILURE);
	}

	done = false;
	size = (size_t)tell_size;
	*buffer = (char *)malloc(sizeof(char) * (size + 1));
	if(*buffer != NULL)
		(*buffer)[size] = '\0';
		if(fread(*buffer, sizeof(char), size, file) == size) {
			done = true;
		}

	return;
}


void process_data(char **line) {
	int num;
	static int line_number = 0;
	char *c = *line;
	char *a = *line;
	char **temp = &c;
	char **tem1 = &a;

	line_number++;
	printf("%d	", line_number);


	if(*c == '0')
	{
		num = str_to_us(line, 2);
		printf("%3d   +%3d   +%3d   +%3d", num, num, num, num);
	}
	else
	{
		num = str_to_us(line, 2);
		printf("%3d", num);

		num = str_to_sm(temp, 2);
		printf("   -%3d", num);

		num = str_to_one(tem1, 2);
		printf("   -%3d", num);

		printf("   -%3d", num + 1);

	}


	printf("\n");

	return;
}

int str_to_us(char **str, int base) {

	int result = 0;
	char *c = *str;
	while(isalnum(*c)) {
		result *= base;
		if(isdigit(*c)) {
			result += *c - '0';
		}
		c++;
	}
	*str = c;

	return result;
}

int str_to_sm(char **str, int base) {
	int result = 0;
	char *c = *str;
	c++;

	while(isalnum(*c)) {
		result *= base;
		if(isdigit(*c)) {
			result += *c - '0';
		}
		c++;
	}
	*str = c;

	return result;
}

int str_to_one(char **str, int base){
	int result = 0;
	char *c = *str;
	int a = 0;

	while(isalnum(*c)) {
		result *= base;
		if(isdigit(*c)) {
			a = *c - '0';
			if(a == 1)
				a = 0;
			else
				a = 1;
			result = result + a;
		}
		c++;
	}
	*str = c;

	return result;

}