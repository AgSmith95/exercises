#ifndef STATIC_VFS_A_H
#define STATIC_VFS_A_H

// int y = 1; // causes "multiple definition of `y'"
extern int y;
// generates "D y" in a file where it's defined as 'int y = <something>;'
// 'D'/'d' - The symbol is in the initialized data section
// generates "U y" in other files where y is not defined
// 'U' - The symbol is undefined.

static int x = 10;
// symbol "d x" is generated in all of the files, which include this
// 'D'/'d' - The symbol is in the initialized data section
static int f(int a) {
// static forces this function to be generated
// as 't' - the symbol in code section
// in every file, which includes this one
// instead of the 'U' for looking for this symbol later
// 'U' - The symbol is undefined.
    return a + x;
}

#endif //STATIC_VFS_A_H
