//
// Created by 郑楚彬 on 2020/7/24.
//

/* 符号表的条目（CSAPP 7-4） */
typedef struct {
    int   name;       /* String table offset */
    char  type:4,     /* Function or data (4 bits) */
        binding:4;  /* Local or global (4 bits) */
    char  reserved;   /* Unused */
    short section;    /* Section header index */
    long  value;      /* Section offset or absolute address */
    long  size;       /* Object size in bytes */
} Elf64_Symbol;

/* ELF 重定位条目（CSAPP 7-9） */
typedef struct {
    long offset;    /* 需要被修改的引用的节偏移 */
    long type:32,   /* 重定位的类型: 告知链接器如何修改新的引用 */
        symbol:32;  /* 符号表的索引值: 标识被修改引用应该指向的符号 */
    long addend;    /* 有符号常数: 有些重定位需要使用它来修改引用位置 */
} Elf64_Rela;

