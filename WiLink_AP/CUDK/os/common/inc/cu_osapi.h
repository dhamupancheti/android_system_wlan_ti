/*
 * cu_osapi.h
 *
 * Copyright 2001-2010 Texas Instruments, Inc. - http://www.ti.com/
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and  
 * limitations under the License.
 */

/****************************************************************************/
/*                                                                          */
/*    MODULE:   cu_osapi.h                                                     */
/*    PURPOSE:                                                              */
/*                                                                          */
/****************************************************************************/
#ifndef _CUOSAPI_H_
#define _CUOSAPI_H_

/* defines */
/***********/
#define OK                      0
#define FALSE                   0
#define TRUE                    1
#define OSAL_ERROR					-1
#define OSAL_SUCCESS				0
#define OSAL_FAILURE				1
#define OS_GETINPUTSTRING_CONTINUE  TRUE+1

#if !defined(max)
#define max(a,b) ((a>b)?a:b)
#endif
/* replaces IFNAMSIZ in Linux */
#define IF_NAME_SIZE    16

/* types */
/*********/
#if !defined(VOID)
typedef void                    VOID,*PVOID;
#endif
typedef unsigned char           U8,*PU8;
typedef /*signed*/ char         S8,*PS8,**PPS8;
typedef unsigned short          U16,*PU16;
typedef signed short            S16,*PS16;
typedef unsigned long           U32,*PU32;
typedef signed long             S32,*PS32;
typedef float                   F32,*PF32;
typedef PVOID                   THandle;
typedef int                     TI_SIZE_T;

/* 
 * supp declares its OS abstarction with primitive types, so these must
 * be specifically declared here, and only if they weren't defined before by someone
 * including common.h
 */
#if !defined(COMMON_H)
typedef unsigned char   u8;
typedef unsigned short 	u16;
typedef unsigned long   u32;
typedef unsigned long long u64;
#endif


#ifndef NULL
#define NULL    (0)
#endif

typedef enum
{
    OS_FOPEN_READ = 0,
	OS_FOPEN_READ_BINARY, 
	OS_FOPEN_WRITE,
	OS_FOPEN_WRITE_BINARY
} os_fopen_mode_e;

enum { CU_MSG_DEBUG, CU_MSG_INFO1, CU_MSG_WARNING, CU_MSG_ERROR, CU_MSG_INFO2};

/****************************************************************************************
 *                      OS Memory API                                                   *
 ****************************************************************************************/
PVOID os_MemoryCAlloc(U32 Number, U32 Size);
PVOID os_MemoryAlloc(U32 Size);
VOID os_MemoryFree(PVOID pMemPtr);
PVOID os_memset(PVOID s, U8 c, U32 n);
PVOID os_memcpy(PVOID dest, const PVOID src, U32 n);
S32 os_memcmp(const PVOID s1, const PVOID s2, S32 n);

/****************************************************************************************
 *                      OS File API                                                    *
 ****************************************************************************************/
PVOID os_fopen (const PS8 path, os_fopen_mode_e mode);
S32 os_fclose (PVOID stream);
S32 os_getFileSize (PVOID file);
PS8 os_fgets (PS8 s, S32 size, PVOID stream);
S32 os_fread (PVOID ptr, S32 size, S32 nmemb, PVOID stream);
S32 os_fwrite (PVOID ptr, S32 size, S32 nmemb, PVOID stream);

/****************************************************************************************
 *                      OS String API                                                   *
 ****************************************************************************************/
PS8 os_strcpy(PS8 dest, const PS8 src);
PS8 os_strncpy(PS8 dest, const PS8 src, S32 n);
S32 os_strcmp(const PS8 s1, const PS8 s2);
S32 os_strncmp(const PS8 s1, const PS8 s2, U32 n);
S32 os_sscanf(const PS8 str, const PS8 format, ...);
S32 os_sprintf(PS8 str, const PS8 format, ...);
PS8 os_strcat(PS8 dest, const PS8 src);
U32 os_strlen(const PS8 s);
PS8 os_strchr(const PS8 s, S32 c);
S32 os_strtol(const PS8 nptr, PPS8 endptr, S32 base);
U32 os_strtoul(const PS8 nptr, PPS8 endptr, S32 base);
S32 os_tolower(S32 c);
S32 os_isupper(S32 c);
S32 os_toupper(S32 c);
S32 os_atoi(const PS8 str);

/****************************************************************************************
 *                      OS Output API                                                   *
 ****************************************************************************************/
S32 os_Printf(const PS8 buffer);
VOID os_error_printf(S32 debug_level, const PS8 arg_list ,...);

/****************************************************************************************
 *                      Miscelanous OS API                                              *
 ****************************************************************************************/
S32 os_getInputString(PS8 inbuf, S32 len);
VOID os_Catch_CtrlC_Signal(PVOID SignalCB);

VOID os_OsSpecificCmdParams(S32 argc, PS8* argv);
VOID os_InitOsSpecificModules(VOID);
VOID os_DeInitOsSpecificModules(VOID);
TI_SIZE_T os_get_last_error(VOID);

#endif  /* _CUOSAPI_H_ */

