#ifndef CORE_H
#define CORE_H


typedef unsigned int   u32int;
typedef	         int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

void writeByte(u16int port, u8int value);
u8int readByte(u16int port);
u16int readWord(u16int port);

#endif