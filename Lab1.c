#include <stdio.h>
#include <string.h>
#include <limits.h>
const int number_of_elements = 32;
const int size_element = 32;

typedef struct uint1024_t
{
    unsigned int element[32];
} uint1024_t;

void print_value(uint1024_t arr)                            //number output
{
    int const size = size_element * number_of_elements / 4;
    int index = -1;
    char answer[1024 / 4];
    for (int i = 0; i < number_of_elements; ++i)
    {
        int count;
        for (int j = 0; j < size_element; j += 4)
        {
            ++index;
            int num = (arr.element[i] & (15 << j)) >> j;
            if (num == 10)
            {
                answer[index] = 'A';
                continue;
            }
            if (num == 11)
            {
                answer[index] = 'B';
                continue;
            }
            if (num == 12)
            {
                answer[index] = 'C';
                continue;
            }
            if (num == 13)
            {
                answer[index] = 'D';
                continue;
            }
            if (num == 14)
            {
                answer[index] = 'E';
                continue;
            }
            if (num == 15)
            {
                answer[index] = 'F';
                continue;
            }
            answer[index] = num + '0';
        }
    }
    int flag = 0;
    for (int i = index; i >= 0; --i)
    {
        if (answer[i] != '0' || flag == 1)
        {
            flag = 1;
            printf("%c", answer[i]);
        }
    }
    if (flag == 0)
    {
        printf("0");
    }
    printf("\n");
}
uint1024_t from_uint(unsigned int x)        //translation of a number from uint to uint_1024
{
    uint1024_t uint1024;
    for (int i = 0; i < number_of_elements; ++i)
    {
        uint1024.element[i] = 0;
    }
    uint1024.element[0] = x;
    return uint1024;
}
uint1024_t add_op(uint1024_t num1, uint1024_t num2)           //addition function
{
    uint1024_t uint1024;
    long long sum = 0;
    long long unsigned overflow = 0;
    for (int i = 0; i < number_of_elements; ++i)
    {
        sum = overflow + num1.element[i] + num2.element[i];
        uint1024.element[i] = (sum % ((unsigned long long)1 + UINT_MAX));
        overflow = sum / ((unsigned long long)1 + UINT_MAX);
    }
    return uint1024;
}

uint1024_t subtr_op(uint1024_t num1, uint1024_t num2)               //subtraction function  
{
    uint1024_t result = from_uint(0);
    int more = 1;
    for (int i = number_of_elements - 1; i >= 0; --i)
    {
        if (num1.element[i] > num2.element[i])
        {
            more = 1;
            break;
        }
        else
        {
            if (num2.element[i] > num1.element[i])
            {
                more = 0;
                break;
            }
        }
    }
    if (more == 1)
    {
        long long buf = 0;
        int overflow = 0;
        for (int i = 0; i < number_of_elements; ++i)
        {
            buf = (long long)num1.element[i] - (long long)num2.element[i] - overflow;
            overflow = 0;
            if (buf < 0)
            {
                buf += (long long)UINT_MAX + (long long)1;
                overflow = 1;
            }
            result.element[i] = buf;
        }
    }
    else
    {
        printf("ERROR_big_second_number\n");
        return result;
    }
    return result;
}

uint1024_t mult_op(uint1024_t num1, uint1024_t num2)               //multiplication function
{
    uint1024_t result = from_uint(0);
    for (int j = 0; j < number_of_elements; ++j)
    {
        for (int i = 0; i < number_of_elements; ++i)
        {
            unsigned long long mult = (unsigned long long)num1.element[i] * (unsigned long long)num2.element[j];
            uint1024_t bufer = from_uint(0);

            if (mult > UINT_MAX)
            {
                if (i + j + 1 < number_of_elements)
                {
                    bufer.element[i + j] += (mult % ((unsigned long long)1 + UINT_MAX));
                    bufer.element[i + j + 1] += mult / ((unsigned long long)1 + UINT_MAX);
                    result = add_op(result, bufer);
                }
                else
                {
                    printf("ERROR_big_numbers\n");
                }
            }
            else
            {
                if (i + j >= number_of_elements && mult > 0)
                {
                    printf("ERROR_big_numbers\n");
                }
                else
                {
                    bufer.element[i + j] += mult % (UINT_MAX + (long long)1);
                    result = add_op(result, bufer);
                }
            }
        }
    }

    return result;
}
void scanf_value(uint1024_t *arr)             //number input
{
    char string[1024 / 4];
    scanf("%s", &string);
    int len = strlen(string);
    int string_index = len - 1;
    int exit = 0;
    for (int k = 0; k < number_of_elements; ++k)
    {
        arr->element[k] = 0;
        for (int j = 0; j < size_element; j += 4)
        {

            if (string_index < 0)
            {
                exit = 1;
                break;
            }
            int num = 0;
            if (string[string_index] == 'A')
            {
                num = 10;
            }
            if (string[string_index] == 'B')
            {
                num = 11;
            }
            if (string[string_index] == 'C')
            {
                num = 12;
            }
            if (string[string_index] == 'D')
            {
                num = 13;
            }
            if (string[string_index] == 'E')
            {
                num = 14;
            }
            if (string[string_index] == 'F')
            {
                num = 15;
            }
            if (string[string_index] >= '0' && string[string_index] <= '9')
            {
                num = string[string_index] - '0';
            }
            --string_index;
            arr->element[k] = (arr->element[k] | (num << j));
        }
        if (exit == 1)
        {
            break;
        }
    }
}
