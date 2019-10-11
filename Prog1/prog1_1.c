/*
* Name: Cynthia Ha
* Worked with: Luke Krentz & Jenny Li
* Feb. 7, 2017
* CS 220
* Prof. Confer
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/***************** Prototypes *******************************/
void read_file_to_buffer(FILE *f);
void string_check(char *buffer);
int char_to_int(char *c);
int toDeci(char *str, int base);
int val(char c);
void convert(int deci, int base, char * converted_number_1);

/****************** Global Variable *************************/
char *buffer = NULL;

/****************** Main Function ***************************/
int main (int argc, char *argv[]) 
{
	FILE *fp = NULL;
	
	if(argc != 2)
	{
		fprintf(stderr, "Error: Too Many/Few Arguements\n");
		exit(EXIT_FAILURE);
	}

	else
	{
		fp = fopen(argv[1], "rb");

		if(fp == NULL)
		{
			fprintf(stderr, "Error: could not open %s file. \n", argv[1]);
			exit(EXIT_FAILURE);
		}

		else
		{
			read_file_to_buffer(fp);
    		string_check(buffer);
                //printf("about to close file");
    		fclose(fp);
    		free(buffer);
    		buffer = NULL;
		}
	}

	exit(EXIT_SUCCESS);
}

/************************* Declarations ***************************/

void read_file_to_buffer(FILE *file) // Code given in class
{
    long file_size = 0;

    if(buffer != NULL)
    {
        fprintf(stderr, "buffer in use\n");
        exit(EXIT_FAILURE);
    }

    rewind(file);
    if (fseek(file, 0, SEEK_END) != 0)
    {
        perror("Could not seek to end of file");
        exit(EXIT_FAILURE);
    }

    file_size = ftell(file);
    if (file_size < 0)
    {
        perror("could not tell size of file");
        exit(EXIT_FAILURE);
    }
    rewind(file);

    buffer = (char *)malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL)
    {
        fprintf(stderr, "Could not allocate memory");
        exit(EXIT_FAILURE);
    }

    if(fread(buffer, sizeof(char), (size_t)file_size, file) != file_size)
    {
        fprintf(stderr, "Could not read file\n");
        exit(EXIT_FAILURE);
    }
    buffer[file_size] = '\0';

    return;
}

void string_check(char *buffer)
{

    int i = 0, j = 0, l = 0; //counters

/************Inputs*************/
    char input_base[30];
    char input_num[1000];
    char output_base[30];

/************Output************/
    int end_number;
    int converted_base, converted_out_base;
    char converted_number_1[300];

    while( buffer[i] != '\0') //Checking if there is still another line in file
    {
        if (buffer[i] != '#' && buffer[i] != '\n') //Skipping lines with # or empty lines
        {
        	l++;

            while (buffer[i] != ' ') //getting the input base
            {
                input_base[j] = buffer[i];
                i++;
                j++;
            }
            
            j = 0; 
            i++; 

            if (input_base[1] != ' ') //converting the base (char) into an integer ; if it has more than 1 digit
                converted_base = char_to_int(input_base);
                
            else // if the base only has one digit
                converted_base = input_base[0];

            while (buffer[i] != ' ') // getting the number to convert
            {
                input_num[j] = buffer[i];
                i++;
                j++;
            }

            end_number = toDeci(input_num,converted_base); // converting the number to decimal (base 10)
            
            j = 0;
            i++;

            while (buffer[i] != '\n' && buffer[i] != '\0') // getting the output base
            {
                output_base[j] = buffer[i];
                i++;
                j++;
            }
                
            if (output_base[1] != ' ') // if it has more than 1 digit
            {   printf("%s", output_base);
                converted_out_base = char_to_int(output_base);
            }
            
            else // if it only has one digit
            { 
                //printf("%s", output_base);
                converted_out_base = output_base[0];
                
            }
            
            j = 0;
            //i++;

            
            printf("%d. %s", l, converted_number_1);
        }

        else
        {
            while (buffer[i] != '\n' && buffer[i] != '\0')
            {
                i++;
          	}
       	}

        i++;

    	}

		return;
	}

int char_to_int(char *str) // helper function
{
	int result = 0;
	int i;
	for(i = 0; i < 2; i++)	//only up to base 36 so length is 2 digits only
	{
		result = result * 10 + (str[i] - '0');
	}
	return result;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'a' + 10;
}


int toDeci(char *str, int base)
{
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}

void convert(int deci, int base, char * converted_number_1)
{
	char map [40] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'f', 'g',
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
					'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int num [100];
	int index = 0;
	int i = 0;

	while(deci != 0)
	{
		num[index] = deci % base;
		deci = deci / base;
		++index;
	}

	while(index >= 0)
	{
		converted_number_1[i] = map[num[index]];
		i++;
		index--;
	}

	return ;
}

