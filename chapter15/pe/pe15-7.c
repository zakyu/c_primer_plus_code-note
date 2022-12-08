#include <stdio.h>

unsigned font;

#define MASK_ID         0xff000
#define MASK_SIZE       0x00fe0
#define MASK_ALIGN      0x00018
#define MASK_BOLD       0x00004
#define MASK_ITALIC     0x00002
#define MASK_UNDERLINE  0x00001

void show_menu(unsigned font);
void cleanbuf();
void change_font(unsigned * font);
void change_size(unsigned * font);
void change_alignment(unsigned * font);
void toggle_bold(unsigned * font);
void toggle_italic(unsigned * font);
void toggle_underline(unsigned * font);

int main(void)
{
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
        cleanbuf();
        show_menu(font);
    }
    return 0;
}

void cleanbuf()
{
    while (getchar() != '\n')
        continue;
}

void show_menu(unsigned font)
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

void change_font(unsigned * font)
{
    printf("Enter font id (0-255): ");
    unsigned temp;
    scanf("%u", &temp);
    font->ID = (font->ID | 0xFF) & temp;
    
}

void change_size(unsigned * font)
{
    printf("Enter font id (0-127): ");
    unsigned temp;
    scanf("%u", &temp);
    font->size = (font->size | 0x7F) & temp;
}

void change_alignment(unsigned * font)
{
    printf("Enter font id (0-2): ");
    unsigned temp;
    scanf("%u", &temp);
    font->align = (font->align | 3) & temp;
}

void toggle_bold(unsigned * font)
{
    font->bold = ~font->bold;
}

void toggle_italic(unsigned * font)
{
    font->italics = ~font->italics;
}

void toggle_underline(unsigned * font)
{
    ~(font & MASK_UNDERLINE)

}