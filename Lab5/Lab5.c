#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

//unnecessary for current iteration
#include <sys/types.h>

int main (int argc, char **argv) { 
  struct dirent *dirent; 
  DIR *parentDir; 

  if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
  } 
  parentDir = opendir(argv[1]); 
  if (parentDir == NULL) { 
    printf ("Error opening directory '%s'\n", argv[1]); 
    exit (-1);
  } 
  int count = 1; 

  while((dirent = readdir(parentDir)) != NULL){ 
    printf ("[%d] %s\n", count, (*dirent).d_name); 
    if (dirent->d_type == DT_DIR) {
      //construct path
      char path[1024];
      snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
      //uses recursion on main, very strange I want to do it on another function but I don't wanna make a void function, this will work anyway
      //however my instance of codespaces isn't working with opendir() for somereason.
      main(2, (char *[]){argv[0], path});
    } else {
      printf ("[%d] %s is a file\n", count, dirent->d_name);
    }
    count++; 
  } 
  closedir (parentDir); 
  return 0; 
} 
