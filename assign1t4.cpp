// assign1t4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
using namespace std;


void tree(char *basePath, const int root, FILE * pFile)
{
    int i;
    char path[1000];	


    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            for (i=0; i<root; i++) {
                if (i%2 == 0 || i == 0)
                    fprintf(pFile,"|");
                else
                    fprintf(pFile,"_");
			}

            fprintf(pFile,"|--%s\n", dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 2, pFile);
        }
    }

    closedir(dir);
}
int _tmain(int argc, _TCHAR* argv[])
{
    char *path, ch[150];
	FILE * pFile;

	path = "C:\\random";
	pFile = fopen ("result1.txt","w");
    tree(path, 0, pFile);
	fclose (pFile);
	pFile = fopen ("result1.txt","r");
	while(fscanf (pFile, "%s", ch) != EOF){
		cout<<ch<<"\n";
	}
	cin.get();
    return 0;
}