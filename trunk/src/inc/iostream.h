/* 
 * File:   iostream.h
 * Author: brandon
 *
 * Created on October 28, 2010, 10:50 PM
 */

#ifndef IOSTREAM_H
#define	IOSTREAM_H

#include "core.h"

void writeByte(u16int port, u8int value);
u8int readByte(u16int port);
u16int readWord(u16int port);

#endif	/* IOSTREAM_H */

