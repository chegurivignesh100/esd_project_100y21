#include<reg51.h>
#include<string.h>
void delay(void);
sbit rs = P2^0;
sbit rw=P2^1;
sbit en=P2^5;
code unsigned char a[3]={0x38,0x0f,0x06};
code unsigned char b[28]="Vardhan Gnanesh pavan Nerraj";
unsigned int i,j,k,l;
void cmdwrite()
  {
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
  }
void datawrite()
  {
   rs=1;
   rw=0; 
   en=1;
  delay();
  en=0;
  }
void delay(){
   for(k=1;k<4000;k++);  
}
void main()
{
for(i=0;i<=2;i++)
{
P3=a[i];
cmdwrite();
delay();
}
P3=0x80;
cmdwrite();
delay();
for(j=0;j<=27;j++)
{
P3=b[j];
datawrite();
}
while(1)
{
P3=0x18;
cmdwrite();
delay();
}
}