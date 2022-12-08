#include <stdio.h>

unsigned font;

#define MASK_SIZE       0x00fe0
#define MASK_ALIGN      0x00018
#define MASK_BOLD       0x00004
#define MASK_ITALIC     0x00002
#define MASK_UNDERLINE  0x00001

#define CLEAN_ID        0x00fff
#define CLEAN_SIZE      0xff01f
#define CLEAN_ALIGN     0xfffe7

void show_menu();
void clean_buf();
void change_font();
void change_size();
void change_alignment();
void toggle_bold();
void toggle_italic();
void toggle_underline();

int main(void)
{
    font = 0x01020;
    show_menu(font);
    char ch;
    while ((ch = getchar()) != 'q')
    {
        switch (ch)
        {
        case 'f':  change_font();break;
        case 's':  change_size();break;
        case 'a':  change_alignment();break;
        case 'b':  toggle_bold();break;
        case 'i':  toggle_italic();break;
        case 'u':  toggle_underline();break;
        default:
            printf("Invalid input, try again.\n");
            continue;
            break;
        }
        clean_buf();
        show_menu();
    }
    return 0;
}

void clean_buf()
{
    while (getchar() != '\n')
        continue;
}

void show_menu()
{
    printf("%5s%10s%15s%5s%5s%5s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%5u", font>>12);
    printf("%10u", (font&MASK_SIZE)>>5);
    switch ((font&MASK_ALIGN)>>3)
    {
    case 0: printf("%15s", "left");break;
    case 1: printf("%15s", "center");break;
    case 2: printf("%15s", "right");break;
    default: printf("%15s", "unknown");
    }
    printf("%5s", (font&MASK_BOLD)>>2?"on":"off");
    printf("%5s", (font&MASK_ITALIC)>>1?"on":"off");
    printf("%5s", (font&MASK_UNDERLINE)?"on":"off");
    puts("\n");

    printf("f)change font\ts)change size\ta)change alignment\n"
           "b)toggle bold\ti)toggle italic\tu)toggle underline\n"
           "q)quit\n");
}

void change_font()
{
    printf("Enter font id (0-255): ");
    unsigned temp;
    scanf("%u", &temp);
    font = (font & CLEAN_ID) | (temp<<12);
}

void change_size()
{
    printf("Enter font id (0-127): ");
    unsigned temp;
    scanf("%u", &temp);
    font = font & CLEAN_SIZE | (temp<<5);
}

void change_alignment()
{
    printf("Enter font id (0-2): ");
    unsigned temp;
    scanf("%u", &temp);
    font = font & CLEAN_ALIGN | (temp<<3);
}

void toggle_bold()
{
    font ^= MASK_BOLD;
}

void toggle_italic()
{
    font ^= MASK_ITALIC;
}

void toggle_underline()
{
    font ^= MASK_UNDERLINE;
}