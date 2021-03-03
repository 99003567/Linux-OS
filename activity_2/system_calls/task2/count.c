#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1;

    char ch;
    int chars, words, lines;

    /* Open source files in 'r' mode */
    fp1 = fopen("file1.txt", "r");
    /* Check if file opened successfully */
    if (fp1 == NULL)
    {
        printf("Cannot open file \n"); 
        exit(0); 
    }

    /*
     * Logic to count characters, words and lines.
     */
    chars = words = lines = 0;
    while ((ch = fgetc(fp1)) != EOF)
    {
        chars++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    /* Increment words and lines for last word */
    if (chars > 0)
    {
        words++;
        lines++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total no. of characters = %d\n", chars);
    printf("Total no. of words      = %d\n", words);
    printf("Total no. of lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(fp1);

    return 0;
}