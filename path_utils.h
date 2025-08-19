#ifndef PATH_UTILS_H_
#define PATH_UTILS_H_

char *check_absolute_path(char *cmd);
char *build_full_path(char *dir, char *cmd);
char *find_in_path(char *cmd);

#endif /**PATH_UTILS_H_ */
