# ifndef TYPE_H
#define TYPE_H

enum type{
    NONE, //defaut set
    ARG, //word
    FILE_IN, //word == '<'
    HERE_DOC, // word == '<<'
    FILE_OUT, //word == '>'
    FILE_OUT_SUR, //word == '>>'
    OPEN_FILE, // word following '<'
    LIMITOR, // word following '<<'
    EXIT_FILE, // word followinf '>'
    EXIT_FILE_RET // word following '>>'
};

#endif