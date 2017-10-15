/*
 * C Program to Count No of Lines, Blank Lines, Comments in a given Program
 * Divyansh Gaba
 * Enroll No. : 01110402715
 */
#include <stdio.h>

int main()
{
    int line_count = 0, number_of_comment_lines = 0, number_of_blank_lines = 0, lines_ending_semicolon = 0;
    FILE *fp1;
    char ch;
    char *file_name;
    printf("Enter file name to calculate LOC for: ");
    scanf("%s",file_name);
    fp1 = fopen(file_name, "r");

    while ((ch = fgetc(fp1)) != EOF)
    {
        if (ch  ==  '\n')
        {
            line_count++;
        }
        if (ch  ==  '\n')
        {
            if ((ch = fgetc(fp1))  ==  '\n')
            {
                fseek(fp1, -1, 1);
                number_of_blank_lines++;
            }
        }
        if (ch  ==  ';')
        {
            if ((ch = fgetc(fp1))  ==  '\n')
            {
                fseek(fp1, -1, 1);
                lines_ending_semicolon++;
            }
        }
    }
    fseek(fp1, 0, 0);
    while ((ch = fgetc(fp1))!= EOF)
    {
        if (ch  ==  '/')
        {
            ch = fgetc(fp1);
            if (ch  ==  '/')
            {
                number_of_comment_lines++;
                while((ch=fgetc(fp1)) != '\n');

            }
            else if(ch == '*')
            {
                while(true)
                {
                    ch = fgetc(fp1);
                    while(ch !='*' )
                    {
                        ch = fgetc(fp1);
                    }
                    if((ch=fgetc(fp1)) == '/')
                        break;
                }
                number_of_comment_lines++;
            }
        }
    }
    printf("Total no of lines: %d\n", line_count);
    printf("Total no of comment line: %d\n", number_of_comment_lines);
    printf("Total no of blank lines: %d\n", number_of_blank_lines);
    printf("Total no of non blank lines: %d\n", line_count-number_of_blank_lines);
    printf("Total no of lines end with semicolon: %d\n", lines_ending_semicolon);
    return 0;
}
