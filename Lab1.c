#include <stdio.h>
#include <string.h>
#include <gtest/gtest.h>
int fun(int a, int b)
{
    return a+b -1 ;
}

int work_with_file(int argc, char *argv[])
{
    char name[10000];
    char command[10];
    if (argc != 3)               //checking the number of arguments
    {
        printf("error: few arguments\n");
        return -1001;
    }
    if (strlen(argv[1]) > 10)     //checking size of arguments
    {
        printf("error: comand to large\n");
        return -1002;
    }
    if (strlen(argv[2]) > 100)
    {
        printf("error: adress file to large\n");
        return -1003;
    }
    strcpy(command, argv[1]);
    FILE *file;
    file = fopen(argv[2], "r");

    if (file == NULL)
    {
        printf("error: wrong name file\n");
        return -1004;
    }
    char buf = 0;
    int count_words = 0;
    int count_strings = 0;
    int count_bytes = 0;
    int word_been = 0;
    fscanf(file, "%c", &buf);
    while (!feof(file))                          //work with file
    {
        if (buf == ' ' && word_been != 0)
        {
            word_been = 0;
            ++count_words;
        }
        else
        {
            if (buf == '\n')
            {
                ++count_strings;
                if (word_been != 0)
                {
                    word_been = 0;
                    ++count_words;
                }
                ++count_bytes;
            }
            else
            {
                word_been = 1;
            }
        }
        ++count_bytes;
        fscanf(file, "%c", &buf);
    }
    fclose(file);
    if (word_been != 0)
    {
        word_been = 0;
        ++count_words;
        ++count_strings;
    }
    if (strcmp(command, "-l") == 0 || strcmp(command, "--lines") == 0)        //command check
    {
        printf("%d strings\n", count_strings);
        return count_strings;
    }
    if (strcmp(command, "-c") == 0 || strcmp(command, "--bytes") == 0)
    {
        printf("%d bytes\n", count_bytes);
        return count_bytes;
    }
    if (strcmp(command, "-w") == 0 || strcmp(command, "--words") == 0)
    {
        printf("%d words\n", count_words);
        return count_words;
    }
    printf("error: comand don't exist\n");
    return -1005;
}
