# 缓冲区

无缓冲输入：回显用户输入字符后立即重复打印该字符。

缓冲输入：用户输入的字符被收集并存储在一个被称为缓存区的临时存储区，按下Enter键后，程序才可使用用户输入的字符。

## 两种缓冲方式

完全缓冲I/O、行缓冲I/O

完全缓冲输入指的是当缓冲区被填满时才刷新缓冲区（内容被发送至目的地），通常出现在文件输入中。缓冲区的大小取决于系统，常见的大小是512字节和4096字节。

行缓冲I/O指在出现换行符时刷新缓冲区。键盘输入通常是行缓冲输入，所以在按下Enter键后才刷新缓冲区。

# 重定向

把输入重定向至文件：`<`

把输出重定向至文件：`>`

组合重定向


