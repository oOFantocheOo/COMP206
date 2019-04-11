#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>



int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("ERROR: Wrong number of arguments. One required.\n");
        return -1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!(fp))
    {
        printf("ERROR: Can't find file!\n");
        return -1;
    }
    size_t sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    char f[sz + 1];
    fread(f, 1, sz + 1, fp);
    f[sz] = '\0';
    fclose(fp);
    char t[8];
    char *start=f;
    char *stop;
    char *pageNameStart;
    char *pageNameEnd;
    int foundTitle=0;
    while(strstr(start,"<a href=\"/wiki/"))
    {
        start=strstr(start,"<a href=\"/wiki/");
        stop=strstr(start,">");
        foundTitle=0;
        for (char *i=start; i+7<stop; i++)
        {
            memcpy(t,i,7);
            t[7]='\0';
            if(strcmp("title=\"",t)==0)
                foundTitle=1;
        }
        if(foundTitle==1)
        {
            pageNameStart=strstr(start,"/wiki/");
            pageNameStart+=6;
            pageNameEnd=strstr(pageNameStart,"\"");
            for (char *j=pageNameStart;j!=pageNameEnd;j++)
                printf("%c",*j);

            printf("\n");
            start=strstr(stop,">");
        }
        else tart=strstr(stop,">");
    }
    return 0；
}

