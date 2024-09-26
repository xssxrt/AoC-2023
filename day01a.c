#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

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
            if (*p >= '1' && *p <= '9')
            {
                if (!first)
                {
                    first = *p;
                }
                last = *p;
            }
        }
        total_calibration_value += 10 * (first - '0') + (last - '0');
    }
    printf("%d\n", total_calibration_value);
    fclose(file);
    return 0;
}
