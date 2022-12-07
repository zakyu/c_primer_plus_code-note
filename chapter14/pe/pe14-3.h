#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

typedef struct book BOOK;
typedef void (*SORT_FUNC)(BOOK *[], int);

void print_book(BOOK * const library, int count, SORT_FUNC print);
void by_default(BOOK * order[], int count);
void by_title(BOOK * order[], int count);
void by_price(BOOK * order[], int count);
char * s_gets(char * st, int size);