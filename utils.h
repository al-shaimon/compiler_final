#ifndef UTILS_H
#define UTILS_H

extern int inMultiLineComment;

// Function declarations
int isKeyword(char *word);
void stripCommentsAndStrings(char *line);

#endif
