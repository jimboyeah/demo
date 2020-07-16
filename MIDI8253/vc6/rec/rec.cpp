
/* File rec.cpp
    by Dustin Caldwell (dustin@gse.utah.edu)
*/

#include <dos.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void helpdoc();

void main(int iArg,char*_argv[],char*envs[])
{
    FILE *rfp, *wfp;

    unsigned char ch, c;
    char s[20];

    if((rfp=fopen(_argv[1], "r"))==NULL)          /* open the read file */
    {
        printf("cannot open file %s \n",_argv[1]);
        helpdoc();
        exit(-1);
    }

    if((wfp=fopen(_argv[2], "wb"))==NULL)         /* open the write file */
    {
        printf("cannot open file %s \n",_argv[1]);
        helpdoc();
        exit(-1);
    }

    c=0;

    ch=fgetc(rfp);

    while(!feof(rfp))           /* loop for whole file */
    {

        if(isalnum(ch))        /* only 'see' valid ascii chars */
        {
            c=0;
            while(isdigit(ch))   /* only use decimal digits (0-9) */
            {
                s[c]=ch;    /* build a string containing the number */
                c++;
                ch=fgetc(rfp);
            }
            s[c]=NULL;           /* must have NULL terminator */

            fputc(atoi(s), wfp);/* write the binary equivalent to file */

        }

        ch=fgetc(rfp);         /* loop until next number starts */


    }

    fclose(rfp);          /* close up */
    fclose(wfp);
}


void helpdoc()     /* print help message */
{
    printf("\n Text File Encoder\n\n");

    printf("\n Syntax: rec text_file_name binary_file_name\n\n");

    printf("by Dustin Caldwell (dustin@gse.utah.edu)\n\n");
    printf("This is a program that reads an ascii tab-\n");
    printf("delimited file and builds a binary file where\n");
    printf("each byte of the binary file is one of the decimal\n");
    printf("digits in the text file.\n");
    printf(" eg:\n\n");
    printf("c:\\>rec son3.txt son3.mid\n\n");
    printf("(This will create a file called son3.mid which is\n");
    printf("a valid binary file)\n\n");
    printf("(dec.exe may also be useful, as it decodes binary files)\n\n");
    printf("Have Fun!!\n");
}