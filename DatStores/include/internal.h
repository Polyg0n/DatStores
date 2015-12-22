//
//  internal.h
//  DatStores
//
//  Created by Corbin Matschull on 11/21/15.
//  Copyright © 2015 Corbin Matschull. All rights reserved.
//

#ifndef INTERNAL_H
#define INTERNAL_H

#ifndef __XRC_NULL
#   define  __XRC_NULL 0
#elif !defined(_XRC_FALSE)
#   define _FALSE 0
#elif !defined(_XRC_TRUE)
#   define _TRUE 1
#endif


typedef char      BYTE, *PBYTE, *PCSTR, *LPBYTE;
typedef short     WORD, *PWORD, *LPWORD;
typedef int       DWORD32, *PDWORD32, *LPDWORD32;
typedef int       BOOLEAN;
typedef long      DWORD, *PDWORD, *LPDWORD;
typedef long long DWORD64, *PDWORD64, *LPDWORD64;
typedef long long _QWORD;
typedef void*     HANDLE;

#endif /* INTERNAL_H */
