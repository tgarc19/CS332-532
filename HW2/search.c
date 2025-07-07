/*
Search Program
Made by Tiago Garcia

Tried to make it work without giving directory but what I did doesn't work
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fnmatch.h>


void print_usage() {
    printf("Usage: search [options] [directory]\n");
    printf("Options:\n");
    printf("  -S                    List all files with size, permissions, and last access time\n");
    printf("  -s <size>             List files with size less than or equal to specified size\n");
    printf("  -f <pattern> <depth>  List files matching pattern within specified depth\n");
    printf("If no directory is specified, the current directory is used.\n");
}

void list_files(const char *directory) {
    // This function should implement the logic to list files in the directory.
    // For now, we will just print a placeholder message.
    printf("Listing files in directory: %s\n", directory);
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void list_files_with_details(const char *directory) {
    // This function should implement the logic to list files with size, permissions, and last access time.
    // For now, we will just print a placeholder message.
    printf("Listing files in directory: %s\n", directory);
    DIR *dir = opendir(directory);
    if( (dir = opendir(directory)) == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        struct stat fileStat;
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", directory, entry->d_name);
        if (stat(fullPath, &fileStat) == 0) {
            printf("%s: Size: %ld bytes, Permissions: %o, Last Access Time: %ld\n",
                   entry->d_name, fileStat.st_size, fileStat.st_mode & 0777, fileStat.st_atime);
        } else {
            perror("stat");
        }
    }
    closedir(dir);
}

void list_files_with_size(const char *directory, long size_limit) {
    // This function should implement the logic to list files with size less than or equal to size_limit.
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        struct stat fileStat;
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", directory, entry->d_name);
        if (stat(fullPath, &fileStat) == 0) {
            if (fileStat.st_size <= size_limit) {
                printf("%s: Size: %ld bytes, Permissions: %o, Last Access Time: %ld\n",
                       entry->d_name, fileStat.st_size, fileStat.st_mode & 0777, fileStat.st_atime);
            }
        } else {
            perror("stat");
        }
    }
    closedir(dir);
}
void list_files_with_pattern(const char *directory, const char *pattern, long depth) {
    // This function should implement the logic to list files matching the pattern within the specified depth.
    // For now, we will just print a placeholder message.
    printf("Listing files in directory: %s matching pattern: %s with depth: %ld\n", directory, pattern, depth);
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        struct stat fileStat;
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", directory, entry->d_name);
        if (stat(fullPath, &fileStat) == 0) {
            if (fnmatch(pattern, entry->d_name, 0) == 0) {
                printf("%s: Size: %ld bytes, Permissions: %o, Last Access Time: %ld\n",
                       entry->d_name, fileStat.st_size, fileStat.st_mode & 0777, fileStat.st_atime);
            }
        } else {
            perror("stat");
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // No directory specified, use current directory
        argv[1] = ".";
    }

    // Process command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-S") == 0) {
            // Handle -S option
            printf("Listing all files with size, permissions, and last access time...\n");
            // TODO: Implement file listing with details
            if(argv[++i] == NULL || argv[++i][0] == '-') {
                // No directory specified, use current directory
                const char *dir = ".";
                list_files_with_details(dir);
            }else {
                list_files_with_details(argv[++i]);
            }
        } else if (strcmp(argv[i], "-s") == 0) {
            // Handle -s option
            if(argv[++i] == NULL || argv[++i][0] == '-') {
                // No size specified, print usage
                printf("No Size Specified!");
                printf("\n");
                print_usage();
                return 1;
            }
            long size_limit = strtol(argv[++i], NULL, 10);
            printf("Listing files with size less than or equal to: %ld\n", size_limit);
            list_files_with_size(argv[1], size_limit);
            i++;
        } else if (strcmp(argv[i], "-f") == 0) {
            // Handle -f option
            if(argv[++i] == NULL || argv[++i][0] == '-') {
                // No pattern specified, print usage
                printf("no Pattern Specified!\n");
                printf("\n");
                print_usage();
                return 1;
            }
            int n = i + 2;
            if(argv[n] == NULL || argv[n][0] == '-'){
                // No depth specified, print usage
                printf("No Depth Specified!\n");
                printf("\n");
                print_usage();
                return 1;
            }
            const char *pattern = argv[++i];
            long depth = strtol(argv[++i], NULL, 10);
            list_files_with_pattern(argv[1], pattern, depth);
            i += 2;
        }else{
            list_files(argv[i]);
        }
    }

    return 0;
}