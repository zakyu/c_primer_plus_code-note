#include <stdio.h>

struct font
{
    unsigned ID         : 8;
    unsigned size       : 7;
    unsigned align      : 2;
    unsigned bold       : 1;
    unsigned italics    : 1;
    unsigned underline  : 1;
};

typedef struct font Font;
void show_menu(Font font);
void clean_buf();
void change_font(Font * font);
void change_size(Font * font);
void change_alignment(Font * font);
void toggle_bold(Font * font);
void toggle_italic(Font * font);
void toggle_underline(Font * font);

int main(void)
{
    Font font = {1, 12, 0, 0, 0, 0};
    show_menu(font);
    char ch;
    while ((ch = getchar()) != 'q')
    {
        switch (ch)
        {
        case 'f':  change_font(&font);break;
        case 's':  change_size(&font);break;
        case 'a':  change_alignment(&font);break;
        case 'b':  toggle_bold(&font);break;
        case 'i':  toggle_italic(&font);break;
        case 'u':  toggle_underline(&font);break;
        default:
            printf("Invalid input, try again.\n");
            continue;
            break;
        }
        clean_buf();
        show_menu(font);
    }
    return 0;
}


void clean_buf()
{
    while (getchar() != '\n')
        continue;
}

void show_menu(Font font)
{
    printf("%5s%10s%15s%5s%5s%5s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%5u", font.ID);
    printf("%10u", font.size);
    switch (font.align)
    {
    case 0: printf("%15s", "left");break;
    case 1: printf("%15s", "center");break;
    case 2: printf("%15s", "right");break;
    default: printf("%15s", "unknown");
    }
    printf("%5s", font.bold?"on":"off");
    printf("%5s", font.italics?"on":"off");
    printf("%5s", font.underline?"on":"off");
    puts("\n");

    printf("f)change font\ts)change size\ta)change alignment\n"
           "b)toggle bold\ti)toggle italic\tu)toggle underline\n"
           "q)quit\n");
}

void change_font(Font * font)
{
    printf("Enter font id (0-255): ");
    unsigned temp;
    scanf("%u", &temp);
    font->ID = (font->ID | 0xFF) & temp;
}

void change_size(Font * font)
{
    printf("Enter font id (0-127): ");
    unsigned temp;
    scanf("%u", &temp);
    font->size = (font->size | 0x7F) & temp;
}

void change_alignment(Font * font)
{
    printf("Enter font id (0-2): ");
    unsigned temp;
    scanf("%u", &temp);
    font->align = (font->align | 3) & temp;
}

void toggle_bold(Font * font)
{
    font->bold = ~font->bold;
}

void toggle_italic(Font * font)
{
    font->italics = ~font->italics;
}

void toggle_underline(Font * font)
{
    font->underline = ~font->underline;
}