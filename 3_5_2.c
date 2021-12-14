#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dirent;

    if((dir = opendir(argv[1])) < 0)
    {
        printf("open failed.\n");
        exit(1);
    }

    while((dirent = readdir(dir)) != NULL)
    {
        printf("%s %ld\n", dirent->d_name, dirent->d_ino);
    }

    closedir(dir);

    return 0;
}