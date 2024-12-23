// 第一段代码#if和#endif
#define HAVE_FILE 
// #if不仅要判断 HAVE_FILE这个宏是否被定义了还要判断这个宏是不是非0
#if HAVE_FILE
#include <stdio.h>
int main()
{
    printf("This is a file operation\n");
    return 0;
}
#endif


// //第二段
// #define HAVE_FILE 
 
// #ifdef HAVE_FILE
// #include <stdio.h>
// int main()
// {
//     printf("This is a file operation\n");
//     return 0;
// }
// #endif


// // // 第三段

// #define HAVE_FILE //这个宏被定义了 但是没有值
// //  #ifndef表示如果 HAVE_FILE 这个宏没被定义就走下面的代码，如果已经被定义了那么就不能走下面的代码（代码变灰了）
// #ifndef HAVE_FILE
// #include <stdio.h>
// int main()
// {
//     printf("This is a file operation\n");
//     return 0;
// }
// #endif