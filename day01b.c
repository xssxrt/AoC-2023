#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int get_calibration_value(char *p)
{
    switch (*p)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return *p - '0';
        case 'o':
            if (strncmp(p, "one", 3) == 0)
            {
                return 1;
            }
            return 0;
        case 't':
            if (strncmp(p, "two", 3) == 0)
            {
                return 2;
            }
            else if (strncmp(p, "three", 5) == 0)
            {
                return 3;
            }
            return 0;
        case 'f':
            if (strncmp(p, "four", 4) == 0)
            {
                return 4;
            }
            else if (strncmp(p, "five", 4) == 0)
            {
                return 5;
            }
            return 0;
        case 's':
            if (strncmp(p, "six", 3) == 0)
            {
                return 6;
            }
            else if (strncmp(p, "seven", 5) == 0)
            {
                return 7;
            }
            return 0;
        case 'e':
            if (strncmp(p, "eight", 5) == 0)
            {
                return 8;
            }
            return 0;
        case 'n':
            if (strncmp(p, "nine", 4) == 0)
            {
                return 9;
            }
            return 0;
        default:
            return 0;
    }
}

int main(void)
{
    FILE *file = fopen("./1.txt", "r");
    char line[MAX_LINE_LENGTH];
    int total_calibration_value = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        int first = 0;
        int last = 0;
        for (char *p = line; *p != '\0'; p++)
        {
            int v = get_calibration_value(p);
            if (v)
            {
                last = v;
                if (!first)
                {
                    first = last;
                }
            }
        }
        total_calibration_value += 10 * first + last;
    }
    printf("%d\n", total_calibration_value);
    fclose(file);
    return 0;
}
