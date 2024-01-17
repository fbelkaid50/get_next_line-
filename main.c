// #include <unistd.h>
// #include<stdio.h>
// #define BUFFER_SIZE 10

//  int main ()
//  {
//     int fd = open ("test.txt",O_CREAT | O_RDWR ,0777);
//     char str[BUFFER_SIZE +1];
//     ssize_t bytesread = read (fd,str,BUFFER_SIZE);
//     str[bytesread]='\0';
//     printf("%s",str);
//     close (fd);
//  }
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

// int main() {
//     char buffer[BUFFER_SIZE + 1];
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1) {
//         printf("Failed to open file\n");
//         return 1;
//     }

//     ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
//     if (bytesRead == -1) {
//         printf("Failed to read file\n");
//         return 1;
//     }

//     buffer[bytesRead] = '\0'; // Null-terminate the read content
//     printf("%s", buffer);

//     close(fd);
//     return 0;
// }