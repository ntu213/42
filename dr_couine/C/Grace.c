#include <stdio.h>
#define FILE "Grace_kid.c"
#define PRINT "#include <stdio.h>%c#define FILE %cGrace_kid.c%c%c#define PRINT %c%s%c%c#define FT(x)int main(){fprintf(fopen(FILE, x), PRINT, 10, 34, 34, 10, 34, PRINT, 34, 10, 10, 34, 34, 10, 10); return (0);}%cFT(%cw%c)%c/*hop la le p'tit commentaire :)*/%c"
#define FT(x)int main(){fprintf(fopen(FILE, x), PRINT, 10, 34, 34, 10, 34, PRINT, 34, 10, 10, 34, 34, 10, 10); return (0);}
FT("w")
/*hop la le p'tit commentaire :)*/
