#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>



#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: path1 [path2 ...]\n");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (access(argv[k], F_OK) == -1) {
            printf("%s: path error\n", argv[k]);
        }
        else {
            struct stat tempStat;
            stat(argv[k], &tempStat);
            printf("%s: ", argv[k]);
            switch (tempStat.st_mode & S_IFMT) {
                case S_IFBLK:  printf("block device\n");            break;
                case S_IFCHR:  printf("character special file\n");        break;
                case S_IFDIR:  printf("directory\n");               break;
                case S_IFIFO:  printf("FIFO/pipe\n");               break;
                case S_IFLNK:  printf("symlink\n");                 break;
                case S_IFREG:  printf("regular file\n");            break;
                case S_IFSOCK: printf("socket\n");                  break;
                default:       printf("unknown?\n");                break;
            }
        }
    }
    
}