#include <stdio.h>
#include <string.h>

#define MAXLEN 1000000   // 评测的最大长度

/*
    获取下个下标
    规则：
        将字符的序号（A到F依次对应 1 到 6 ）与下标相加作为新的下标值
        如果下标大于等于len，将其对 len 求余
*/
int get_next_index(const char * string, int len, int cur_index) {
    return (string[cur_index]-'A'+1 + cur_index) % len;
}

int min_string_begin_index(const char * string, int strlen, int * isChecked)
{
    int x = 0, y = 1;  // x, y指向两个比较中的字符串的首字母下标
    int i = x, j = y;           // i, j指向字符串当前的字符位置
    int len; // 字符串的长度

    isChecked[x] = 1; // 标记进行比较的下标
    isChecked[y] = 1; // 标记进行比较的下标
    while (x < strlen && y < strlen && len < strlen)   
    // len == strlen 时，字符串本身就是最小字符串
    {
        int result = string[i] - string[j];
        if (result == 0) // 两个字符串各自的下标指向的字符相等，继续比较下一个字符
        {
            i = get_next_index(string, strlen, i); // 按照题目要求计算下一个下标
            j = get_next_index(string, strlen, j);
            len++;
        }
        else
        {
            if (result < 0)    // x, i 表示的字符串比较小 淘汰 y
            {
                int temp = y;
                while (temp != j)
                {
                    isChecked[temp] = 1;
                    temp = get_next_index(string, strlen, temp);
                }
                while (isChecked[y])
                    y++;
                    
                isChecked[y] = 1;
            }
            else    // y, j 表示的字符串比较小 淘汰 x
            {
                int temp = x;
                
                while (temp != i)   // 遍历一遍淘汰的字符串，做标记
                {
                    isChecked[temp] = 1;
                    temp = get_next_index(string, strlen, temp);
                }

                // 找一个未比较的下标，作为新字符串的开始
                while(isChecked[x])
                    x++;

                isChecked[x] = 1;   // 标记进行比较的下标
            }

            // 重新开始比较两个新的字符串
            i = x;
            j = y;
        }
    }

    return x<y?x:y; // 返回较小的下标
}

int main(void)
{
    char string[MAXLEN];
    fgets(string, MAXLEN, stdin);       // 读取一行字符串
    int len = strlen(string)-1;         // 获取字符串长度 （字符串最后一位是'\0'）

    int isChecked[len];                 // 变长数组 C99支持 不能在声明中初始化
    for (int i = 0; i < len; i++)       // 初始化为未比较
    {
        isChecked[i] = 0;
    }

    printf("%d\n", min_string_begin_index(string, len, isChecked)); // 打印最小字符串的开始下标
    return 0;
}
