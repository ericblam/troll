#ifndef PATH_H

#define PATH_H

#define TROLL_DIR ".troll"

char *init_troll_dir(const char *base);
char *get_repo_troll_dir();
void die_if_not_troll_repo();

#endif /* end of include guard: PATH_H */
