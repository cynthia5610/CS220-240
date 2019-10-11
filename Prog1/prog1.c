/*
* Name: Cynthia Ha
* Worked with: Luke Krentz
* Feb. 7, 2017
* CS 220
* Prof. Confer
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/***************** Prototypes *******************************/
void read_file_to_buffer(FILE *f);
void string_check(char *buffer);
int char_to_int(char c);
int toDeci(char *str, int base, int counter);
int val(char c);
int convert(int deci, int base, char * converted_number_1);

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

    int i = 0, j = 0, l = 0, k=0; //counters

/************Inputs*************/
    char input_base[2];
    char input_num[1000];
    char output_base[2];

/************Output************/
    int end_number;
    int converted_base = 0, converted_out_base = 0;
    char converted_number_1[300];

    while( buffer[i] != '\0') //Checking if there is still another line in file
    {
        if (buffer[i] != '\r' && buffer[i] != '\n' && buffer[i] != '#') //Skipping lines with # or empty lines
        {
        	l++;

            while (buffer[i] != ' ') //getting the input base
            {
                input_base[j] = buffer[i];
                i++;
                j++;
            }

            i++;

            if(j == 2)
            	converted_base = atoi(input_base);
            else
            	converted_base = char_to_int(input_base[0]);

            j = 0; 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            while (buffer[i] != ' ') // getting the number to convert
            {
                input_num[j] = buffer[i];
                i++;
                j++;
            }

            end_number = toDeci(input_num,converted_base,j); // converting the number to decimal (base 10
            
            j = 0;
            i++;

            while (buffer[i] != '\n' && buffer[i] != '\0') // getting the output base
            {
                output_base[j] = buffer[i];
                i++;
                j++;
            }
                
            if(j == 2)
            	converted_out_base = atoi(output_base);
            else
            	converted_out_base = char_to_int(output_base[0]);      
            j = 0;
            i++;

            int t = convert(end_number,converted_out_base,converted_number_1);

            printf("%d. ", l);
            for(k = 0; k < t; k++){
            printf("%c", converted_number_1[k]);
        	}
        	printf("\n");
        }

        else
        {
        	while(buffer[i] != '\n')
        	{
        		i++;
        	}
            i++;
       	}

    }

		return;
}

int char_to_int(char str) // helper function
{
	int result = 0;
	result = result * 10 + (str - '0');
	return result;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'a' + 10;
}


int toDeci(char *str, int base, int length)
{
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    for (i = length - 1; i >= 0; i--)
    {
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}

int convert(int deci, int base, char * converted_number_1)
{
	char map [40] = {'0' ,'1', '2', '3', '4', '5', '6', '7', '8', '9',
					 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'f', 'g', 
					 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 
					 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int num [100];
	int index = 0;
	int i = 0;

	if(deci != 0)
	{
		while(deci != 0)
		{
		num[index] = deci % base;
		deci = deci / base;
		++index;
		}

		for(i = 0; i < index; i++)
		{
		converted_number_1[i] = map[num[index-i-1]];
		}
	}
	else
	{
		converted_number_1[0] = '0';
		index = 1;
	}

	return index;
}
