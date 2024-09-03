////#include <graphics.h>
////#include <string>
////
////int main() {
////    int gd = DETECT, gm;
////    initgraph(&gd, &gm, "");
////
////    // Set text color
////    setcolor(BROWN);
////
////    // Draw rectangle with desired background color
////    setfillstyle(SOLID_FILL, RED);  // Set background color
////    bar(100, 100, 300, 150);         // Draw rectangle as background
////
////    // Set text background color to match rectangle background color
////    setbkcolor();
////
////    // Draw text on top of the rectangle
////    outtextxy(120, 120, "Hello, World!");
////
////    getch();
////    closegraph();
////    return 0;
////}
//
//#include <graphics.h>
//#include <conio.h>
//
//int main() {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, "");
//
//    // Define custom colors using the COLOR macro
//    int customColor1 = COLOR(192, 124, 79); // Purple
//    int customColor2 = COLOR(255, 165, 0); // Orange
//
//    // Set the background color to customColor1 and clear the screen
//    setbkcolor(customColor1);
//    cleardevice();
//
//    // Set the drawing color to customColor2
////    setcolor(customColor2);
//
//    // Draw a rectangle with the custom drawing color
//    rectangle(100, 100, 200, 200);
//
//    // Draw text with the custom drawing color
//    outtextxy(100, 250, "Hello, Custom Color!");
//
//    getch();
//    closegraph();
//    return 0;
//}
//

