/*
 * C Program to Count No of Lines, Blank Lines, Comments in a given Program
 * Divyansh Gaba
 * Enroll No. : 01110402715
 */
#include <stdio.h>

int main()
{
    int line_count = 0, n_o_c_l = 0, n_o_n_b_l = 0, n_o_b_l = 0, n_e_c = 0;
    FILE *fp1;
    char ch;
    fp1 = fopen("main.cpp", "r");

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
                n_o_b_l++;
            }
        }
        if (ch  ==  ';')
        {
            if ((ch = fgetc(fp1))  ==  '\n')
            {
                fseek(fp1, -1, 1);
                n_e_c++;
            }
        }
    }
    // single line comment

    /* Comment but not a comment line */ int a;

    /* */ // this is counted as single like comment
    /*
    // this is 3 line comment
    */

    fseek(fp1, 0, 0);
    while ((ch = fgetc(fp1))!= EOF)
    {
        if (ch  ==  '/')
        {
            ch = fgetc(fp1);
            if (ch  ==  '/')
            {
                n_o_c_l++;
                while((ch=fgetc(fp1)) != '\n');

            }
            else if(ch == '*')
            {
                while(true)
                {
                    ch = fgetc(fp1);
                    if(ch=='\n')
                            n_o_c_l++;
                    else
                    {
                        while(ch !='*' )
                        {
                            if(ch=='\n')
                                n_o_c_l++;
                            ch = fgetc(fp1);
                        }
                        if((ch=fgetc(fp1)) == '/')
                            break;
                        else if(ch == '\n')
                            n_o_c_l++;
                    }
                }
                bool blank = true;
                while((ch=fgetc(fp1)) != '\n')
                {
                    if(ch != ' ')
                    {
                        blank = false;
                        if(ch == '/')
                         fseek(fp1,-1,1);
                        break;
                    }
                }
                if(blank)
                    n_o_c_l++;
            }
        }
    }
    printf("Total no of lines: %d\n", line_count);
    printf("Total no of comment line: %d\n", n_o_c_l);
    printf("Total no of blank lines: %d\n", n_o_b_l);
    printf("Total no of non blank lines: %d\n", line_count-n_o_b_l);
    printf("Total no of lines end with semicolon: %d\n", n_e_c);
    return 0;
}
