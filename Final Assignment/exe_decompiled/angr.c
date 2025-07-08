extern char g_4093b8;

int sub_401000()
{
    return &g_4093b8;
}

int sub_401010(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    unsigned int v0;  // [bp-0x14]
    unsigned int v1;  // [bp-0x10]
    unsigned int v2;  // [bp-0xc]
    unsigned int v3;  // [bp-0x8]
    unsigned int v4[2];  // eax

    v3 = a3;
    v2 = a2;
    v1 = a1;
    v0 = a0;
    v4 = sub_401000();
    return (unsigned int)__stdio_common_vfprintf(v4[0], v4[1]);
}

void sub_401040(unsigned int a0)
{
    char *v0;  // [bp-0x8]
    char v1;  // [bp+0x8]

    v0 = &v1;
    sub_401010(__acrt_iob_func(1, a0, 0, v0), a0, 0, v0);
    return;
}

extern void g_405480;

void sub_401080()
{
    unsigned int v0;  // [bp-0x168]
    unsigned int v1;  // [bp-0x164]
    unsigned int v2;  // [bp-0x160]
    char *v3;  // [bp-0x15c]
    unsigned int v4;  // [bp-0x158]
    unsigned int v5;  // [bp-0x154]
    void* v6;  // [bp-0x150]
    void* v7;  // [bp-0x14c]
    char *v8;  // [bp-0x148]
    void* v9;  // [bp-0x144]
    char *v10;  // [bp-0x140]
    void* v11;  // [bp-0x13c]
    char v12;  // [bp-0x137]
    char v13;  // [bp-0x136]
    char v14;  // [bp-0x135]
    char v15;  // [bp-0x134]
    char v16;  // [bp-0x131]
    char v17;  // [bp-0x130]
    char v18[1];  // [bp-0x2c]
    char v19[19];  // [bp-0x2b]
    char v20;  // [bp-0x18]
    unsigned int v22;  // esi
    unsigned int v23;  // edi
    unsigned int v24;  // eax
    unsigned int v25;  // ecx
    unsigned int v26;  // ecx

    v1 = v22;
    v0 = v23;
    strncpy(v18, "AttackIRGC.dll", 14);
    strncpy(v19, ":\\ReversingCTF\\", 15);
    v8 = &v18[0];
    v10 = &v17;
    v3 = v10;
    do
    {
        v14 = *(v8);
        *(v10) = v14;
        v8 += 1;
        v10 += 1;
    } while (v14);
    v11 = &v20;
    v7 = v11;
    do
    {
        v13 = *((char *)v11);
        v11 += 1;
    } while (v13);
    v6 = v7;
    v5 = v11 - v7;
    v9 = &v16;
    do
    {
        v12 = (char)v9[1];
        v9 += 1;
    } while (v12);
    v24 = v5;
    for (v25 = v24 >> 2; v25; v6 += 4)
    {
        v25 -= 1;
        *((int *)v9) = *((int *)v6);
        v9 += 4;
    }
    for (v26 = v24 & 3; v26; v6 += 1)
    {
        v26 -= 1;
        *((char *)v9) = *((char *)v6);
        v9 += 1;
    }
    v4 = fopen_s(&v15, &v17, "wb");
    if (v4)
        return;
    v2 = fwrite(&g_405480, 1, 0x2c00, *((int *)&v15));
    fclose(*((int *)&v15));
    return;
}

typedef struct FILE_t {
    unsigned int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_marker *_chain;
    unsigned int _fileno;
    unsigned int _flags2;
    unsigned int _old_offset;
    unsigned short _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    struct _IO_marker *_lock;
    char padding_4c[4];
    unsigned long long _offset;
    struct _IO_codecvt *_codecvt;
    struct _IO_wide_data *_wide_data;
    void* _freeres_list;
    char __pad5;
    char padding_65[3];
    unsigned int _mode;
    char _unused2[20];
} FILE_t;

typedef struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_marker *_sbuf;
    unsigned int _pos;
} _IO_marker;

typedef struct _IO_codecvt {
    char __cd_out;
} _IO_codecvt;

typedef struct _IO_wide_data {
    unsigned short *_IO_read_ptr;
    unsigned short *_IO_read_end;
    unsigned short *_IO_read_base;
    unsigned short *_IO_write_base;
    unsigned short *_IO_write_ptr;
    unsigned short *_IO_write_end;
    unsigned short *_IO_buf_base;
    unsigned short *_IO_buf_end;
    unsigned short *_IO_save_base;
    unsigned short *_IO_backup_base;
    unsigned short *_IO_save_end;
    __mbstate_t _IO_state;
    char padding_31[3];
    char _IO_last_state;
    char padding_35[7];
    unsigned short _shortbuf[1];
    _IO_marker _wide_vtable;
} _IO_wide_data;

typedef struct __mbstate_t {
    unsigned int __count;
    char __value;
} __mbstate_t;

void sub_401290(char *a0)
{
    unsigned int v0;  // [bp-0x8]
    char v1;  // [bp+0x0]
    char *v2;  // [bp+0x4]

    while (true)
    {
        if (!*(a0))
            break;
        v0 = *(a0);
        putchar(v0);
        v2 = a0 + 1;
        fflush(__acrt_iob_func(1, *(a0), &v1, *((int *)&v1)));
        Sleep(15);
        a0 = v2;
    }
    return;
}

int sub_4012e0(unsigned int a0)
{
    unsigned int v0;  // [bp-0x8]
    unsigned int v1;  // ecx

    v0 = v1;
    v0 = ((int)((a0 >> 31 CONCAT a0) % 3) CONCAT (int)((a0 >> 31 CONCAT a0) / 3)) >> 32;
    return (!v0 ? a0 * 2 : (v0 == 1 ? a0 + 100 : (v0 == 2 ? a0 - 50 : 0)));
}

void sub_401330()
{
    unsigned int v0;  // [bp-0x10]
    unsigned int v1;  // [bp-0xc]
    void* v2;  // [bp-0x8]

    v1 = 123;
    for (v2 = 0; v2 < 5; v2 += 1)
    {
        v1 ^= v2 * 7;
    }
    v0 = sub_4012e0(v1);
    sub_401430();
    sub_401390(v1, v0);
    return;
}

void sub_401390(unsigned int a0, unsigned int a1)
{
    return;
}

void sub_4013b0(char *a0)
{
    unsigned int v0;  // [bp-0x18]
    char *v1;  // [bp-0x14]
    char *v2;  // [bp-0x10]
    char *v3;  // [bp-0xc]
    char v4;  // [bp-0x5]

    v3 = 0;
    while (true)
    {
        v2 = a0;
        v1 = v2 + 1;
        do
        {
            v4 = *(v2);
            v2 += 1;
        } while (v4);
        v0 = v2 - v1;
        if (v3 >= v0)
            break;
        *((char *)(a0 + v3)) = *((char *)(a0 + v3)) ^ 42;
        *((char *)(a0 + v3)) = *((char *)(a0 + v3)) ^ 42;
        v3 += 1;
    }
    return;
}

typedef struct struct_0 {
    char padding_0[4231196];
    char field_40901c;
} struct_0;


void sub_401430()
{
    unsigned int v0;  // [bp-0x2e8]
    unsigned int v1;  // [bp-0x2e4]
    unsigned int v2;  // [bp-0x2e0]
    char *v3;  // [bp-0x2dc]
    unsigned int v4;  // [bp-0x2d8]
    void* v5;  // [bp-0x2d4]
    char *v6;  // [bp-0x2d0]
    unsigned int *v7;  // [bp-0x2cc]
    void* v8;  // [bp-0x2c8]
    unsigned int *v9;  // [bp-0x2c4]
    char *v10;  // [bp-0x2c0]
    void* v11;  // [bp-0x2bc]
    char *v12;  // [bp-0x2b8]
    void* v13;  // [bp-0x2b4]
    struct_0 *v14;  // [bp-0x2b0]
    char v15;  // [bp-0x2aa]
    char v16;  // [bp-0x2a9]
    char *v17;  // [bp-0x2a8]
    char v18;  // [bp-0x2a1]
    char v19;  // [bp-0x2a0]
    void* v20;  // [bp-0x160]
    char v21;  // [bp-0x15d]
    char v22[260];  // [bp-0x15c]
    int v23;  // [bp-0x58]
    char v24[1];  // [bp-0x2c]
    char v25[19];  // [bp-0x2b]
    char v26;  // [bp-0x18]
    unsigned int v28;  // esi
    unsigned int v29;  // edi
    unsigned int v30;  // eax
    unsigned int v31;  // ecx
    unsigned int v32;  // ecx
    struct_0 *v33;  // ecx
    unsigned int v34;  // ecx

    v1 = v28;
    v0 = v29;
    strncpy(v24, "DroneAttack.txt", 15);
    strncpy(v25, ":\\ReversingCTF\\", 15);
    v10 = &v24[0];
    v12 = &v22[0];
    v3 = v12;
    do
    {
        v18 = *(v10);
        *(v12) = v18;
        v10 += 1;
        v12 += 1;
    } while (v18);
    v13 = &v26;
    v8 = v13;
    do
    {
        v16 = *((char *)v13);
        v13 += 1;
    } while (v16);
    v5 = v8;
    v4 = v13 - v8;
    v11 = &v21;
    do
    {
        v15 = (char)v11[1];
        v11 += 1;
    } while (v15);
    v30 = v4;
    for (v31 = v30 >> 2; v31; v5 += 4)
    {
        v31 -= 1;
        *((int *)v11) = *((int *)v5);
        v11 += 4;
    }
    for (v32 = v30 & 3; v32; v5 += 1)
    {
        v32 -= 1;
        *((char *)v11) = *((char *)v5);
        v11 += 1;
    }
    v7 = FindFirstFileA(&v22, &v19);
    if (v7 == -1)
    {
        Sleep(2000);
        sub_401290("Danger! Anti aircraft system is still operating\n");
        return;
    }
    Sleep(2000);
    sub_401290("Anti aircraft system located\nIntiating disable sequence\n\n");
    FindClose(v7);
    v9 = CreateFileA(&v22, 0x40000000, 0, NULL, 2, 128, NULL);
    if (v9 != -1)
    {
        v20 = 0;
        v17 = 0;
        for (v14 = 0; v14 < 32; v14 = &v14->padding_0[1])
        {
            *((char *)(&v23 + v17)) = *((char *)(v14 + "0123456789ABCDEF0123456789ABCDEF"));
            v17 += 1;
            v33 = &v14->padding_0[1];
            v34 = v33 & 2147483651;
            if ((v33 & 2147483651) < 0)
                v34 = (v34 - 1 | 0xfffffffc) + 1;
            if (!v34 && v14 != 31)
            {
                *((char *)(&v23 + v17)) = 32;
                v17 += 1;
            }
        }
        v6 = v17;
        if (v6 >= 41)
            sub_401bf4();
        *((char *)(&v23 + v6)) = 0;
        v2 = WriteFile(v9, &v23, v17, &(char)v20, NULL);
        CloseHandle(v9);
        Sleep(2000);
        sub_401290("Great job. Anti aircraft system is disabled\n\nStage 2: You are a jet fighter pilot. The sky is clear. Your mission: release bombs on IRGC headquarters.\nTo find them, use the cyber intelligence unit\n");
        sub_401080();
    }
    else
    {
        Sleep(2000);
        sub_401290("Danger! Anti aircraft system found but something is wrong. it is not disabled\n");
    }
    return;
}

int sub_4017b0(unsigned int a0, unsigned int a1, unsigned int a2)
{
    char v0[4];  // [bp-0x10]
    unsigned short v1;  // [bp-0xc]
    unsigned int v2;  // eax

    sub_401040("%s\n");
    Sleep(2000);
    sub_401290("Stage 1: You are a special operations expert.\nYour mission is to protect our pilots. Disable the anti aircraft system\nOh, intelligence report says the enemy spread decoys, find the real target, fast!\n\n");
    strncpy(v0, "Rada", 4);
    v1 = 114;
    sub_4013b0(&(unsigned int)v0);
    sub_401330();
    return v2;
}

void sub_401820(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
    unsigned int v0;  // [bp-0x20]
    unsigned int v1;  // [bp-0x1c]
    unsigned int v2;  // [bp-0x18]
    unsigned int v3;  // [bp-0x14]
    unsigned int v4;  // [bp-0x10]
    unsigned int v5;  // [bp-0xc]
    unsigned int v6;  // [bp-0x8]
    unsigned int v7[2];  // eax

    v4 = a4;
    v3 = a3;
    v2 = a2;
    v1 = a1;
    v0 = a0;
    v7 = sub_401000();
    v6 = __stdio_common_vsprintf(v7[0] | 1, v7[1]);
    if (v6 >= 0)
    {
        v5 = v6;
        return;
    }
    v5 = 4294967295;
    return;
}

int sub_401880(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return (unsigned int)sub_401820(a0, 4294967295, a1, a2, a3);
}

void sub_4018a0(unsigned int a0, unsigned int a1)
{
    char *v0;  // [bp-0x8]
    char v1;  // [bp+0xc]

    v0 = &v1;
    sub_401880(a0, a1, 0, v0);
    return;
}

extern unsigned int g_409040;
extern char g_4093c4;

void sub_4018e0()
{
    GetComputerNameA(&g_4093c4, &g_409040);
    return;
}

extern unsigned int g_40904c;
extern unsigned int *g_4093c0;
extern char g_4093c4;
extern char g_4093d4;

void sub_401900()
{
    unsigned int v0;  // [bp-0x1c]
    char *v1;  // [bp-0x18]
    unsigned int v2;  // [bp-0x14]
    void* v3;  // [bp-0x10]
    char *v4;  // [bp-0xc]
    char v5;  // [bp-0x5]

    v4 = &g_4093c4;
    v1 = v4 + 1;
    do
    {
        v5 = *(v4);
        v4 += 1;
    } while (v5);
    v0 = v4 - v1;
    CryptHashData(g_4093c0, &g_4093c4, v0, 0);
    CryptGetHashParam(g_4093c0, 2, &g_4093d4, &g_40904c, 0);
    for (v3 = 0; v3 < g_40904c; v3 += 1)
    {
        sub_4018a0(4231196 + 0x2 * v3, "%02X");
    }
    v2 = 32;
    if (v2 >= 33)
        sub_401bf4();
    *((char *)(4231196 + v2)) = 0;
    return;
}

extern unsigned int *g_4093c0;

void sub_4019d0(unsigned int a0, unsigned int a1)
{
    void* v1;  // [bp-0x14]
    unsigned int *v3[1];  // [bp-0xc]

    if (a1 != 1)
        return;
    CryptAcquireContextA(&v3, NULL, NULL, 1, 0xf0000000);
    CryptCreateHash(v3, 32771, NULL, 0, &g_4093c0);
    v1 = 0;
}

extern unsigned int g_403158;
extern unsigned int g_409000;
extern unsigned int g_409004;
extern unsigned int g_409050;
extern unsigned int g_409054;
extern unsigned int g_40905c;
extern unsigned int g_409060;
extern unsigned int g_409064;
extern unsigned int g_4090a0;
extern unsigned short g_40912c;
extern unsigned short g_409130;
extern unsigned short g_409134;
extern unsigned short g_409138;
extern unsigned int g_40913c;
extern unsigned int g_409140;
extern unsigned int g_409144;
extern unsigned int g_409148;
extern unsigned int g_40914c;
extern void* g_409150;
extern char g_409154;
extern unsigned int g_409158;
extern unsigned short g_40915c;
extern unsigned int g_409160;
extern struct_0 *g_409164;
extern unsigned short g_409168;

int _security_check_cookie()
{
    unsigned int v0;  // [bp-0x32c]
    unsigned int v1;  // [bp-0xc]
    unsigned int v2;  // [bp-0x8]
    unsigned int v3;  // [bp+0x0]
    unsigned int v4;  // [bp+0x4]
    unsigned int v5;  // ecx
    unsigned int v6;  // eax
    unsigned int v7;  // edx
    unsigned int v8;  // ebx
    unsigned int v9;  // esi
    unsigned int v10;  // edi
    unsigned short v11;  // ss
    unsigned short v12;  // cs
    unsigned short v13;  // ds
    unsigned short v14;  // es
    unsigned short v15;  // fs
    unsigned short v16;  // gs
    unsigned int v17;  // id
    unsigned int v18;  // ac

    if (v5 == g_409004)
        return;
    v6 = IsProcessorFeaturePresent(23);
    if (!v6)
    {
        g_409150 = 0;
        g_40914c = v5;
        g_409148 = v7;
        g_409144 = v8;
        g_409140 = v9;
        g_40913c = v10;
        g_409168 = v11;
        g_40915c = v12;
        g_409138 = v13;
        g_409134 = v14;
        g_409130 = v15;
        g_40912c = v16;
        v0 = x86g_calculate_eflags_all(15, v6, 0, 0) | 514 | v17 * 0x200000 & 0x200000 | v18 * 0x40000 & 0x40000;
        g_409160 = v0;
        *((int *)&g_409154) = vvar_9{reg 28};
        g_409158 = v3;
        g_409164 = &(char)v4;
        g_4090a0 = 65537;
        g_40905c = g_409158;
        g_409050 = 3221226505;
        g_409054 = 1;
        g_409060 = 1;
        g_409064 = 2;
        v1 = g_409004;
        v2 = g_409000;
        sub_401ad2(&g_403158);
        return;
    }
    __fastfail(2); /* do not return */
}

typedef struct EXCEPTION_POINTERS {
    struct EXCEPTION_RECORD *ExceptionRecord;
    struct CONTEXT *ContextRecord;
} EXCEPTION_POINTERS;

typedef struct EXCEPTION_RECORD {
    unsigned int ExceptionCode;
    unsigned int ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned int NumberParameters;
    unsigned int *ExceptionInformation[15];
} EXCEPTION_RECORD;

typedef struct CONTEXT {
    unsigned int ContextFlags;
    unsigned int Dr0;
    unsigned int Dr1;
    unsigned int Dr2;
    unsigned int Dr3;
    unsigned int Dr6;
    unsigned int Dr7;
    FLOATING_SAVE_AREA FloatSave;
    unsigned int SegGs;
    unsigned int SegFs;
    unsigned int SegEs;
    unsigned int SegDs;
    unsigned int Edi;
    unsigned int Esi;
    unsigned int Ebx;
    unsigned int Edx;
    unsigned int Ecx;
    unsigned int Eax;
    unsigned int Ebp;
    unsigned int Eip;
    unsigned int SegCs;
    unsigned int EFlags;
    unsigned int Esp;
    unsigned int SegSs;
    char ExtendedRegisters[512];
} CONTEXT;

typedef struct FLOATING_SAVE_AREA {
    unsigned int ControlWord;
    unsigned int StatusWord;
    unsigned int TagWord;
    unsigned int ErrorOffset;
    unsigned int ErrorSelector;
    unsigned int DataOffset;
    unsigned int DataSelector;
    char RegisterArea[80];
    unsigned int Spare0;
} FLOATING_SAVE_AREA;

void sub_401ad2(EXCEPTION_POINTERS *a0)
{
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(a0);
    TerminateProcess(GetCurrentProcess(), 3221226505);
    return;
}

void sub_401bf4()
{
    char v0;  // [bp+0x0]

    sub_401c00(8, &v0);
    return;
}

extern void g_403158;
extern unsigned int g_409050;
extern unsigned int g_409054;
extern unsigned int g_40905c;
extern unsigned int g_409060;
extern unsigned int g_409064;
extern unsigned short g_40912c;
extern unsigned short g_409130;
extern unsigned short g_409134;
extern unsigned short g_409138;
extern unsigned int g_40913c;
extern unsigned int g_409140;
extern unsigned int g_409144;
extern unsigned int g_409148;
extern unsigned int g_40914c;
extern void* g_409150;
extern unsigned int g_409154;
extern unsigned int g_409158;
extern unsigned short g_40915c;
extern unsigned int g_409160;
extern struct_0 *g_409164;
extern unsigned short g_409168;

int sub_401c00()
{
    unsigned int v0;  // [bp-0x324]
    unsigned int v1;  // [bp-0x4]
    unsigned int v2;  // [bp+0x0]
    char v3;  // [bp+0x4]
    unsigned int v4;  // eax
    unsigned int v5;  // ecx
    unsigned int v6;  // edx
    unsigned int v7;  // ebx
    unsigned int v8;  // esi
    unsigned int v9;  // edi
    unsigned short v10;  // ss
    unsigned short v11;  // cs
    unsigned short v12;  // ds
    unsigned short v13;  // es
    unsigned short v14;  // fs
    unsigned short v15;  // gs
    unsigned int v16;  // id
    unsigned int v17;  // ac

    v4 = IsProcessorFeaturePresent(23);
    if (!v4)
    {
        g_409150 = 0;
        g_40914c = v5;
        g_409148 = v6;
        g_409144 = v7;
        g_409140 = v8;
        g_40913c = v9;
        g_409168 = v10;
        g_40915c = v11;
        g_409138 = v12;
        g_409134 = v13;
        g_409130 = v14;
        g_40912c = v15;
        v0 = x86g_calculate_eflags_all(15, v4, 0, 0) | 514 | v16 * 0x200000 & 0x200000 | v17 * 0x40000 & 0x40000;
        g_409160 = v0;
        g_409154 = v1;
        g_409158 = v2;
        g_409164 = &v3;
        g_40905c = g_409158;
        g_409050 = 3221226505;
        g_409054 = 1;
        g_409060 = 1;
        g_409064 = *((int *)&v3);
        sub_401ad2(&g_403158);
        return;
    }
    __fastfail(*((int *)&v3)); /* do not return */
}

int sub_401ccf()
{
    unsigned int v1;  // esi
    unsigned int v3;  // eax

    _set_app_type(1, v1);
    _set_fmode(sub_402210());
    v3 = sub_402209();
    *((unsigned int *)__p__commode()) = v3;
    if (sub_401fcf(1))
    {
        sub_402450();
        sub_40215c(sub_40247c);
        if (!_configure_narrow_argv(sub_40220c()))
        {
            sub_402216();
            if (sub_40226c())
                __setusermatherr(sub_402209);
            sub_402246();
            sub_402246();
            sub_402225();
            _configthreadlocale(sub_402209());
            if (sub_402222())
                _initialize_narrow_environment();
            sub_402209();
            if (!sub_40239f())
                return 0;
        }
    }
    sub_402284(7);
    [D] Unsupported jumpkind Ijk_SigTRAP at address 4201849()
}

int sub_401d7a()
{
    sub_40224f();
    return 0;
}

void sub_401d82()
{
    sub_4023e6();
    _set_new_mode(sub_402209());
    return;
}

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

void sub_401ebb()
{
    unsigned int v1;  // [bp+0xfffe4]
    struct_0 **v2;  // [bp+0xffff0]
    struct_0 **v3;  // ecx
    unsigned int v4;  // eax

    v3 = v2;
    v4 = *(v3)->field_0;
    v1 = v4;
    _seh_filter_exe(v4, v3);
    return;
}

extern char g_401ed7;
extern char g_401ee6;
extern char g_401f15;

int sub_401ecf(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    char v0;  // [bp+0x0]
    unsigned int v1;  // [bp+0xfffe4]
    char v2;  // [bp+0xfffeb]
    void* v3;  // [bp+0xfffec]
    unsigned int v4;  // [bp+0xffff4]
    unsigned int v5;  // [bp+0x100000]
    unsigned int v6;  // eax
    unsigned long v7;  // ldt
    unsigned long v8;  // gdt
    unsigned short v9;  // fs

    vvar_10{reg 24} = v3 - 4;
    *((char **)&v3[4]) = &g_401ed7;
    if (sub_4023a4())
    {
        if (!v2)
        {
            *((char **)(vvar_10{reg 24} - 4)) = &g_401ee6;
            _c_exit();
        }
        v5 = 4294967294;
        v6 = v1;
        *((unsigned int *)x86g_use_seg_selector(v7, v8, (unsigned int)v9, 0)) = v4;
        return v6;
    }
    *((unsigned int *)(vvar_10{reg 24} - 4)) = v1;
    *((char **)(vvar_10{reg 24} - 8)) = &g_401f15;
    _exit(*((int *)&v0));
    [D] Unsupported jumpkind Ijk_SigTRAP at address 4202261()
}

typedef struct struct_0 {
    struct struct_0 *field_0;
} struct_0;

extern unsigned int g_40311c;
extern unsigned int g_403124;
extern unsigned int g_403128;
extern unsigned int g_403134;
extern unsigned int g_408598;
extern unsigned int g_409370;

int _start()
{
    char v1;  // [bp+0xfffe0]
    char v2;  // [bp+0xfffeb]
    void* v3;  // [bp+0x100000], Other Possible Types: unsigned int
    char v4;  // bl
    struct_0 **v5;  // esi
    unsigned int *v6;  // esi
    unsigned int v7;  // eax
    unsigned int *v8;  // eax
    unsigned int *v9;  // eax
    unsigned int v10;  // esi

    _security_init_cookie();
    sub_4024b0(&g_408598, 20);
    if (sub_401f96(1) && !((v4 = 0, v2 = 0, v3 = (void*)0, v1 = sub_401f64(), g_409370 == 1)))
    {
        if (!g_409370)
        {
            g_409370 = 1;
            if (_initterm_e(&g_403128, &g_403134))
                v3 = 4294967294;
            _initterm(&g_40311c, &g_403124);
            g_409370 = 2;
        }
        else
        {
            v4 = 1;
            v2 = 1;
        }
        sub_4020ea(*((int *)&v1));
        v5 = sub_402278();
        if (*(v5) && sub_402056(v5))
        {
            sub_402246();
            *(v5)(0, 2, 0);
        }
        v6 = sub_40227e();
        if (*(v6) && sub_402056(v6))
            _register_thread_local_exe_atexit_callback(*(v6));
        v7 = _get_initial_narrow_environment();
        v8 = __p___argv();
        v9 = __p___argc();
        v10 = sub_4017b0(*(v9), *(v8), v7);
        if (sub_4023a4())
        {
            if (!v4)
                _cexit();
            sub_402107(1, 0);
            v3 = 4294967294;
        }
    }
    else
    {
        sub_402284(7);
    }
    exit(v10);
}

typedef struct struct_0 {
    char padding_0[60];
    unsigned int field_3c;
} struct_0;

int sub_401f20(struct_0 *a0, unsigned int a1)
{
    unsigned short v0[11];  // ecx
    unsigned int v1[4];  // edx
    unsigned int v2;  // esi

    v0 = &a0->padding_0[a0->field_3c];
    v1 = (char *)&v0[1 + 1] + v0[10];
    v2 = 40 * v0[3] + (char *)v1;
    if (v1 != v2)
    {
        do
        {
            if (a1 >= v1[3] && a1 < v1[2] + v1[3])
                return v1;
        } while (&v1[2 + 2] != v2);
    }
    return 0;
}


char sub_401f64()
{
    unsigned long v1;  // ldt
    unsigned long v2;  // gdt
    unsigned short v3;  // fs
    unsigned int v4;  // eax

    if (!sub_4026f8())
        return 0;
    while (true)
    {
        vvar_65 = CAS(0x409374<32>, Load(addr=(Load(addr=Conv(64->32, x86g_use_seg_selector(vvar_29{reg 304}, vvar_30{reg 312}, Conv(16->32, vvar_28{reg 294}), 0x18<32>)), size=4, endness=Iend_LE) + 0x4<32>), size=4, endness=Iend_LE), 0x0<32>)
        v4 = (0 == vvar_65 ? 0 : vvar_65);
        if (!v4)
        {
            return 0;
        }
        else if (*((int *)(*((int *)x86g_use_seg_selector(v1, v2, (unsigned int)v3, 24)) + 4)) == v4)
        {
            return 1;
        }
    }
}

extern char g_409378;

char sub_401f96(unsigned int a0)
{
    void* v0;  // [bp-0x8]

    if (!a0)
        g_409378 = 1;
    sub_402524();
    if (!sub_402222())
    {
        return 0;
    }
    else if (!sub_402222())
    {
        v0 = 0;
        sub_402222();
        return 0;
    }
    else
    {
        return 1;
    }
}

extern char g_409379;
extern unsigned int g_40937c;
extern unsigned int g_409380;
extern unsigned int g_409384;
extern unsigned int g_409388;
extern unsigned int g_40938c;
extern unsigned int g_409390;

char sub_401fcf(unsigned int a0)
{
    unsigned int v0;  // [bp-0x8]
    unsigned int v1;  // esi

    if (g_409379)
        return 1;
    v0 = v1;
    if (a0 && a0 != 1)
    {
        sub_402284(5);
        [D] Unsupported jumpkind Ijk_SigTRAP at address 4202581()
    }
    if (!(sub_4026f8() && !a0))
    {
        g_40937c = 4294967295;
        g_409380 = 4294967295;
        g_409384 = 4294967295;
        g_409388 = 4294967295;
        g_40938c = 4294967295;
        g_409390 = 4294967295;
    }
    else if (_initialize_onexit_table(&g_40937c) || _initialize_onexit_table(&g_409388))
    {
        return 0;
    }
    g_409379 = 1;
    return 1;
}

typedef struct struct_0 {
    char padding_0[36];
    unsigned int field_24;
} struct_0;

extern char g_400000;
extern char g_400018;
extern struct_1 g_40003c;
extern unsigned int g_4085b8;

char sub_402056(unsigned int a0)
{
    unsigned int v0;  // [bp+0xffff4]
    void* v1;  // [bp+0x100000], Other Possible Types: unsigned int
    unsigned int v2;  // [bp+0x10000c]
    struct_0 *v3;  // eax
    char v4;  // al
    unsigned long v5;  // ldt
    unsigned long v6;  // gdt
    unsigned short v7;  // fs

    sub_4024b0(&g_4085b8, 8);
    v1 = 0;
    if (*((short *)&g_400000) == 23117 && *((int *)&(&g_400000)[*((int *)&g_40003c.padding_0[0])]) == 17744 && *((short *)&(&g_400018)[*((int *)&g_40003c.padding_0[0])]) == 267 && !((v3 = sub_401f20(&g_400000, v2 - &g_400000), !v3 || v3->field_24 < 0)))
    {
        v1 = 4294967294;
        v4 = 1;
    }
    else
    {
        v1 = 4294967294;
        v4 = 0;
    }
    *((unsigned int *)x86g_use_seg_selector(v5, v6, (unsigned int)v7, 0)) = v0;
    return v4;
}

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_4020bb()
{
    struct_0 **v1;  // [bp+0xffff0]

    return *(v1)->field_0 == 3221225477;
}

void sub_4020ce()
{
}

extern char g_409374;

void sub_4020ea(char a0)
{
    if (!sub_4026f8())
    {
        return;
    }
    else if (!a0)
    {
        InterlockedExchange(&g_409374, 0);
        return;
    }
    else
    {
        return;
    }
}

extern char g_409378;

void sub_402107(unsigned int a0, char a1)
{
    unsigned int v0;  // [bp-0xc]
    unsigned int v1;  // [bp-0x8]

    if (g_409378 && a1)
        return;
    v1 = a0;
    sub_402222();
    v0 = a0;
    sub_402222();
    return;
}

extern unsigned int g_40937c;

int sub_40212f(unsigned int a0)
{
    char v0;  // [bp+0x0]

    return ~(-(0 < (g_40937c == -1 ? _crt_atexit(a0, &v0) : (unsigned int)_register_onexit_function(&g_40937c)))) & a0;
}

void sub_40215c(unsigned int a0)
{
    sub_40212f(a0);
    return;
}

int sub_402171()
{
    unsigned long long v0;  // [bp-0x18]
    unsigned int v1;  // [bp-0x14]
    unsigned int v2[2];  // [bp-0x10]
    void* v3;  // [bp-0xc]
    unsigned int v4;  // [bp-0x8]

    *(v2) = 0;
    v3 = 0;
    GetSystemTimeAsFileTime(&v2);
    *((unsigned int [2])&v4) = 0 ^ v2;
    v4 ^= GetCurrentThreadId();
    v4 ^= GetCurrentProcessId();
    QueryPerformanceCounter(&v0);
    return v1 ^ v0 ^ v4 ^ &v4;
}

extern unsigned int g_409000;
extern unsigned int g_409004;

void _security_init_cookie()
{
    unsigned int v1;  // ecx

    v1 = g_409004;
    if (v1 == 3141592654 || !(v1 & 0xffff0000))
    {
        v1 = sub_402171();
        if (v1 == 3141592654)
        {
            v1 = 3141592655;
        }
        else if (!(v1 & 0xffff0000))
        {
            v1 |= (v1 | 18193) * 0x10000;
        }
        g_409004 = v1;
    }
    g_409000 = ~(v1);
    return;
}

int sub_402209()
{
    return 0;
}

int sub_40220c()
{
    return 1;
}

int sub_402210()
{
    return 0x4000;
}

extern void g_409398;

void sub_402216()
{
    InitializeSListHead(&g_409398);
    return;
}

char sub_402222()
{
    return 1;
}

void sub_402225()
{
    if (!_controlfp_s(0, 0x10000, 0x30000))
        return;
    sub_402284(7);
    [D] Unsupported jumpkind Ijk_SigTRAP at address 4203077()
}

void sub_402246()
{
    return;
}

extern char g_4093a0;

int sub_402249()
{
    return &g_4093a0;
}

void sub_40224f()
{
    unsigned int v1[2];  // eax
    unsigned int v2;  // ecx
    unsigned int v3[2];  // eax
    unsigned int v4;  // ecx

    v1 = sub_401000();
    v2 = v1[1];
    v1[0] = v1[0] | 36;
    v1[1] = v2;
    v3 = sub_402249();
    v4 = v3[1];
    v3[0] = v3[0] | 2;
    v3[1] = v4;
    return;
}

extern unsigned int g_40900c;

int sub_40226c()
{
    return !g_40900c;
}

extern char g_4093e8;

int sub_402278()
{
    return &g_4093e8;
}

extern char g_4093e4;

int sub_40227e()
{
    return &g_4093e4;
}

typedef struct EXCEPTION_POINTERS {
    struct EXCEPTION_RECORD *ExceptionRecord;
    struct CONTEXT *ContextRecord;
} EXCEPTION_POINTERS;

typedef struct EXCEPTION_RECORD {
    unsigned int ExceptionCode;
    unsigned int ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned int NumberParameters;
    unsigned int *ExceptionInformation[15];
} EXCEPTION_RECORD;

typedef struct CONTEXT {
    unsigned int ContextFlags;
    unsigned int Dr0;
    unsigned int Dr1;
    unsigned int Dr2;
    unsigned int Dr3;
    unsigned int Dr6;
    unsigned int Dr7;
    FLOATING_SAVE_AREA FloatSave;
    unsigned int SegGs;
    unsigned int SegFs;
    unsigned int SegEs;
    unsigned int SegDs;
    unsigned int Edi;
    unsigned int Esi;
    unsigned int Ebx;
    unsigned int Edx;
    unsigned int Ecx;
    unsigned int Eax;
    unsigned int Ebp;
    unsigned int Eip;
    unsigned int SegCs;
    unsigned int EFlags;
    unsigned int Esp;
    unsigned int SegSs;
    char ExtendedRegisters[512];
} CONTEXT;

typedef struct FLOATING_SAVE_AREA {
    unsigned int ControlWord;
    unsigned int StatusWord;
    unsigned int TagWord;
    unsigned int ErrorOffset;
    unsigned int ErrorSelector;
    unsigned int DataOffset;
    unsigned int DataSelector;
    char RegisterArea[80];
    unsigned int Spare0;
} FLOATING_SAVE_AREA;

void sub_402284(unsigned int a0)
{
    unsigned int v0;  // [bp-0x330]
    char v1;  // [bp-0x32c]
    char v2;  // [bp-0x328], Other Possible Types: unsigned int
    unsigned short v3;  // [bp-0x29c]
    unsigned short v4;  // [bp-0x298]
    unsigned short v5;  // [bp-0x294]
    unsigned short v6;  // [bp-0x290]
    unsigned int v7;  // [bp-0x28c]
    unsigned int v8;  // [bp-0x288]
    unsigned int v9;  // [bp-0x284]
    unsigned int v10;  // [bp-0x280]
    unsigned int v11;  // [bp-0x27c]
    unsigned int v12;  // [bp-0x278]
    unsigned int v13;  // [bp-0x274]
    unsigned int v14;  // [bp-0x270]
    unsigned short v15;  // [bp-0x26c]
    unsigned int v16;  // [bp-0x268]
    char *v17;  // [bp-0x264]
    unsigned short v18;  // [bp-0x260]
    char v19;  // [bp-0x5c], Other Possible Types: unsigned int
    unsigned int v20;  // [bp-0x58]
    unsigned int v21;  // [bp-0x50]
    EXCEPTION_POINTERS v22;  // [bp-0xc]
    unsigned int v24;  // [bp-0x4]
    unsigned int v25;  // [bp+0x0]
    unsigned int v26;  // ecx
    unsigned int v27;  // edx
    unsigned int v28;  // ebx
    unsigned int v29;  // esi
    unsigned int v30;  // edi
    unsigned short v31;  // ss
    unsigned short v32;  // cs
    unsigned short v33;  // ds
    unsigned short v34;  // es
    unsigned short v35;  // fs
    unsigned short v36;  // gs
    unsigned int v37;  // id
    unsigned int v38;  // ac
    unsigned int v39;  // eax

    if (IsProcessorFeaturePresent(23))
        __fastfail(a0); /* do not return */
    sub_402448(3);
    v12 = memset(&v2, 0, 716);
    v11 = v26;
    v10 = v27;
    v9 = v28;
    v8 = v29;
    v7 = v30;
    v18 = v31;
    v15 = v32;
    v6 = v33;
    v5 = v34;
    v4 = v35;
    v3 = v36;
    v0 = x86g_calculate_eflags_all(3, &v1, 12, 0) | 514 | v37 * 0x200000 & 0x200000 | v38 * 0x40000 & 0x40000;
    v16 = v0;
    v14 = v25;
    v17 = &(char)v25;
    v2 = 65537;
    v13 = v24;
    memset(&v19, 0, 80);
    v19 = 1073741845;
    v20 = 1;
    v21 = v25;
    v39 = IsDebuggerPresent();
    v22.ExceptionRecord = &v19;
    v22.ContextRecord = &v2;
    SetUnhandledExceptionFilter(NULL);
    if (UnhandledExceptionFilter(&v22))
    {
        return;
    }
    else if (!!(0 < v39 - 1) + 1)
    {
        sub_402448(3);
        return;
    }
    else
    {
        return;
    }
}

int sub_40239f()
{
    return sub_402209();
}

typedef struct struct_1 {
    unsigned short field_0;
    char padding_2[58];
    unsigned int field_3c;
} struct_1;

typedef struct struct_0 {
    unsigned int field_0;
    char padding_4[20];
    unsigned short field_18;
    char padding_1a[90];
    unsigned int field_74;
    char padding_78[112];
    unsigned int field_e8;
} struct_0;

char sub_4023a4()
{
    struct_1 *v1;  // eax
    struct_0 *v2;  // ecx

    v1 = GetModuleHandleW(NULL);
    if (!v1)
    {
        return 0;
    }
    else if (v1->field_0 == 23117)
    {
        v2 = v1->field_3c + (char *)v1;
        if (v2->field_0 != 17744)
        {
            return 0;
        }
        else if (v2->field_18 != 267)
        {
            return 0;
        }
        else if (v2->field_74 > 14)
        {
            return v2->field_e8;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void sub_4023e6()
{
    SetUnhandledExceptionFilter(sub_4023f2);
    return;
}

typedef struct struct_0 {
    struct struct_1 *field_0;
    unsigned int field_4;
} struct_0;

typedef struct struct_1 {
    unsigned int field_0;
    char padding_4[12];
    unsigned int field_10;
    unsigned int field_14;
} struct_1;

int sub_4023f2(struct_0 *a0)
{
    unsigned int v0[6];  // esi
    unsigned int v1;  // eax
    unsigned int *v2;  // eax

    v0 = a0->field_0;
    if (v0[0] != 3765269347)
    {
        return 0;
    }
    else if (v0[4] == 3)
    {
        v1 = v0[5];
        if (v1 != 429065504 && v1 != 429065505 && v1 != 429065506 && v1 != 0x1994000)
            return 0;
        *((unsigned int *[6])__current_exception()) = v0;
        v2 = __current_exception_context();
        *(v2) = a0->field_4;
        terminate();
        [D] Unsupported jumpkind Ijk_SigTRAP at address 4203591()
    }
    else
    {
        return 0;
    }
}

extern void* g_4093a8;

void sub_402448(unsigned int a0)
{
    g_4093a8 = 0;
    return;
}

typedef struct struct_0 {
    struct struct_0 *field_0;
} struct_0;

extern struct_0 *g_408588;

void sub_402450()
{
    struct_0 **v2;  // esi

    v2 = &g_408588;
    return;
}

typedef struct struct_0 {
    struct struct_0 *field_0;
} struct_0;

extern struct_0 *g_408590;

void sub_40247c()
{
    struct_0 **v2;  // esi

    v2 = &g_408590;
    return;
}

extern unsigned int g_409004;

int sub_4024b0()
{
    unsigned int v0;  // [bp-0x8]
    struct struct_0 v1[4];  // [bp+0x0]
    char *v3;  // [bp+0x8]
    unsigned int v4;  // [bp+0x8]
    unsigned long v5;  // ldt
    unsigned long v6;  // gdt
    unsigned short v7;  // fs
    unsigned int v8;  // ebx
    unsigned int v9;  // esi
    unsigned int v10;  // edi

    v0 = *((int *)x86g_use_seg_selector(v5, v6, (unsigned int)v7, 0));
    v3 = &v1[0].field_0;
    vvar_13{reg 24} = -4 + (char *)&v0 - v4;
    *((unsigned int *)(-4 + (char *)&v0 - v4)) = v8;
    vvar_15{reg 24} = vvar_13{reg 24} - 4;
    *((unsigned int *)(vvar_13{reg 24} - 4)) = v9;
    vvar_17{reg 24} = vvar_15{reg 24} - 4;
    *((unsigned int *)(vvar_15{reg 24} - 4)) = v10;
    *((unsigned long *)(vvar_17{reg 24} - 4)) = g_409004 ^ &v3;
    *((struct struct_0 [4])(vvar_17{reg 24} - 8)) = v1;
    *((unsigned int **)x86g_use_seg_selector(v5, v6, (unsigned int)v7, 0)) = &v0;
    return;
}

extern unsigned int g_409004;

void sub_4024f5(unsigned int *a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    char v0;  // [bp-0x8]
    char v1;  // [bp+0x0]

    *(a0) = 4204460(*(a0), *((int *)&v0), &v1);
    _except_handler4_common(&g_409004, _security_check_cookie, a0, a1, a2, a3);
    return;
}

extern unsigned int g_409010;
extern unsigned int g_4093ac;
extern unsigned int g_4093b0;

void sub_402524()
{
    unsigned int v1;  // [bp-0x38]
    unsigned int v2;  // [bp-0x34]
    unsigned int v3;  // [bp-0x30]
    void* v4;  // [bp-0x28], Other Possible Types: unsigned int
    char *v5;  // [bp-0x24], Other Possible Types: unsigned int
    unsigned int v6;  // [bp-0x24]
    void* v7;  // [bp-0x20]
    unsigned int v8;  // [bp-0x1c]
    void* v10;  // [bp-0x14]
    void* v11;  // [bp-0x10]
    char v12[4];  // [bp-0xc]
    void* v13;  // [bp-0x8], Other Possible Types: unsigned int
    unsigned int v15;  // esi
    unsigned int v16;  // edi
    unsigned int v17;  // ebx
    unsigned int v18;  // edx
    unsigned int v20;  // edi
    unsigned int v21;  // eax

    g_4093ac = 0;
    g_409010 = g_409010 | 1;
    if (!IsProcessorFeaturePresent(10))
        return;
    v10 = 0;
    v3 = v15;
    v2 = v16;
    v1 = v17;
    [D] x86g_dirtyhelper_CPUID_sse3([D] unsupported_<class 'pyvex.expr.GSPTR'>())
    [D] MBusEvent-Imbe_Fence()
    v4 = 0;
    v6 = v17;
    v7 = 0;
    v8 = v18;
    v11 = 0;
    v13 = v8 ^ 1231384169;
    strncpy(v12, "ntel", 4);
    [D] x86g_dirtyhelper_CPUID_sse3([D] unsupported_<class 'pyvex.expr.GSPTR'>())
    [D] MBusEvent-Imbe_Fence()
    v4 = 1;
    v5 = v1;
    v7 = 0;
    v8 = v18;
    if (!v13 && !v12 && !(v6 ^ 1970169159) && !((v4 & 268386288) != 67264 && (v4 & 268386288) != 132704 && (v4 & 268386288) != 132720 && (v4 & 268386288) != 198224 && (v4 & 268386288) != 198240 && (v4 & 268386288) != 198256))
    {
        v20 = g_4093b0 | 1;
        g_4093b0 = v20;
    }
    else
    {
        v20 = g_4093b0;
    }
    v1 = 7;
    v13 = 0;
    v5 = 0;
    v21 = g_409010 | 2;
    g_4093ac = 1;
    g_409010 = v21;
    return;
}

extern unsigned int g_409014;

int sub_4026f8()
{
    return g_409014;
}

