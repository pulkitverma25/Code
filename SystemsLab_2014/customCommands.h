#ifndef CUSTOM_COMMANDS_H_
#define CUSTOM_COMMANDS_H_

#define BUFFER_SIZE 4096 /*standard buffer size = 4096*/

void cat(char *fileName,char *shm); /*custom implementation of cat*/
void grep(char * pattern,char *shm1,char *shm2); /*custom implementation of grep excluding regular expressions*/
void wc(char *shm); /*custom implementation of wc*/

#endif
