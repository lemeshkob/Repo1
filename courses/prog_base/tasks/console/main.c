#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


int main(void)
{
int aqua = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
int blue = BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
int green = BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;

for(pos.Y = 24 ;pos.Y>=0 ; --pos.Y )
{
if(pos.Y%2==0)
{
for (pos.X = 79 ;pos.X>=0 ; --pos.X  )
{
SetConsoleCursorPosition(hConsole, pos);
if((pos.X + pos.Y)%3 == 0 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, blue);
}
if((pos.X + pos.Y)%3 == 1 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, aqua);
}
if((pos.X + pos.Y)%3 == 2 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, green);
}
if((pos.X + pos.Y)%3 == 1 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, blue);
}
if((pos.X + pos.Y)%3 == 0 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, aqua);
}
if((pos.X + pos.Y)%3 == 2 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, green);
}

puts("*");
Sleep(10);
}
}
if(pos.Y%2==1)
{
for (pos.X = 0;pos.X < 80 ; pos.X ++)
{
SetConsoleCursorPosition(hConsole, pos);

if((pos.X + pos.Y)%3 == 0 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, blue);
}
if((pos.X + pos.Y)%3 == 1 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, aqua);
}
if((pos.X + pos.Y)%3 == 2 && (pos.X + pos.Y) <= 52){
SetConsoleTextAttribute(hConsole, green);
}
if((pos.X + pos.Y)%3 == 1 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, blue);
}
if((pos.X + pos.Y)%3 == 0 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, aqua);
}
if((pos.X + pos.Y)%3 == 2 && (pos.X + pos.Y) > 52){
SetConsoleTextAttribute(hConsole, green);
}
puts("*");
Sleep(10);
}
}
}


pos.Y=25;
pos.X=0;
SetConsoleCursorPosition(hConsole, pos);

}
