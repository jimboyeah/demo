/* file dec.cpp

by Dustin Caldwell   (dustin@gse.utah.edu)

*/


#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

void helpdoc();

void main(int iArg,char*_argv[],char*envs)
{
       FILE *fp;

       unsigned char ch, c;

       if((fp=fopen(_argv[1], "rb"))==NULL)           /* open file to read */
       {
               printf("cannot open file %s\n",_argv[1]);
               helpdoc();
               exit(-1);
       }

       c=0;
       ch=fgetc(fp);

       while(!feof(fp))
       {
               printf("%u\t", ch);           /* print every byte's decimal equiv. */
               c++;
               if(c>8) c=0 & printf("\n");
               ch=fgetc(fp);
       }

       fclose(fp);                   /* close up */
}

void helpdoc()                 /* print help message */
{
       printf("\
           \n Binary File Decoder\n\n\
           \
           Syntax: dec binary_file_name\n\n\
           by Dustin Caldwell (dustin@gse.utah.edu)\n\n\
           This is a filter program that reads a binary file\n\
           and prints the decimal equivalent of each byte\n\
           tab-separated. This is mostly useful when piped \n\
           into another file to be edited manually. eg:\n\n\
           c:\\>dec sonata3.mid > son3.txt\n\n\
           This will create a file called son3.txt which can\n\
           be edited with any ascii editor. \n\n\
           (rec.exe may also be useful, as it reencodes the \n\
           ascii text file).\n\n\
           Have Fun!!\n");
}
