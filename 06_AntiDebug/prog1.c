void start_func()
{
    DialogBoxParamA(tls_callback_func(), 0x25, NULL, check_user_input, NULL);
    ExitProcess(0); /* do not return */
}

void sub_40201f()
{
    sub_402567();
    sub_40266a(); /* do not return */
}

typedef struct struct_0 {
    char padding_0[4198466];
    char field_401042;
} struct_0;

extern unsigned int *g_401000;
extern char Password;
extern char g_401040;
extern char String;
extern char g_401055;
extern unsigned short g_401067;
extern unsigned short g_40106a;
extern unsigned short g_40106e;
extern char g_4010b9;
extern char g_401119;
extern char g_401140;
extern char g_401169;
extern char g_40119d;
extern char g_4011c4;
extern char g_4011e7;
extern char g_40121d;

int check_user_input(unsigned int *a0, unsigned int a1, unsigned int a2)
{
    unsigned int v0;  // [bp-0x10]
    unsigned int v1;  // [bp-0xc]
    unsigned int v2;  // [bp-0x8]
    unsigned int v3;  // ebx
    unsigned int v4;  // esi
    unsigned int v5;  // edi
    unsigned int v7;  // eax
    unsigned int v8;  // eax
    struct_0 *v9;  // ecx
    unsigned int v10;  // eax
    char *v11;  // edi
    unsigned int v12;  // esi
    unsigned int v13;  // eax
    char v14[4198942];  // ecx

    v2 = v3;
    v1 = v4;
    v0 = v5;
    if (a1 != 272)
    {
        if (a1 != 273)
        {
            if (a1 != 16)
                return 0;
            return EndDialog(a0, NULL);
        }
        else
        {
            if (a2 == 201)
            {
                v7 = GetDlgItemTextA(a0, 301, &String, 21);
                if (v7 >= 4 && v7 <= 15)
                {
                    g_401040 = v7;
                    if (String == 32)
                    {
                        xor_encrypt_func(&g_401140);
                        SetDlgItemTextA(a0, 302, &g_401140);
                        return (unsigned int)xor_encrypt_func(&g_401140);
                    }
                    
                    if (GetDlgItemTextA(a0, 302, &Password, 21) <= 16)
                    {
                        v9 = 0;
                        v10 = 0;
                        v11 = &g_401055;
                        v12 = 1;
                        do
                        {
                            v13 = (v12 * (v10 & 0xffffff00 | *((char *)(v9 + &String))) + v12) * 0x40000000 >> 13 ^ v12;
                            v10 = v13 & 0xffffff00 | (char)v13 + 53;
                            *(v11) = (char)v13 + 53;
                            v11 += 1;
                            v9 = &v9->padding_0[1];
                            v12 += 1;
                        } while ((char)v9 != g_401040);
                        wsprintfA(&g_40121d, "%i");
                        xor_encrypt_func(&g_40121d);
                        
                        v14 = 0;
                        while (*((char *)(v14 + &Password)) == (*((char *)(v14 + &g_40121d)) ^ 190))
                        {
                            v14 = &v14[1];
                            if (!*((char *)(v14 + &Password)) && !*((char *)(v14 + &g_40121d)) && v14 > 5)
                            {
                                wsprintfA(&g_40121d, "%i");
                                xor_encrypt_func(&g_40119d);
                                
                                MessageBoxA(NULL, &g_40119d, &g_401067, 4160);
                                return (unsigned int)xor_encrypt_func(&g_40119d);
                            }
                        }
                    }
                    xor_encrypt_func(&g_4011c4);
                    SetDlgItemTextA(a0, 302, &g_4011c4);
                    return (unsigned int)xor_encrypt_func(&g_4011c4);
                }
                if (!v7)
                {
                    xor_encrypt_func(&g_401119);
                    SetDlgItemTextA(a0, 302, &g_401119);
                    return (unsigned int)xor_encrypt_func(&g_401119);
                }
                if (v7 >= 6)
                    return SetDlgItemTextA(a0, 302, "Username cannot exceed 15 letters");
                return SetDlgItemTextA(a0, 302, "Username must have 4 letters minimum");
            }
            else if (a2 != 202)
            {
                if (a2 != 203)
                    return v8;
                g_401000 = GetModuleHandleA(NULL);
                return DialogBoxParamA(g_401000, 0x7, NULL, sub_402378, NULL);
            }
        }
    }
    else
    {
        if (g_4011e7 != 1)
        {
            GetComputerNameA(&g_401067, "P");
            if (g_401067 == 18766 && g_40106e == 17746 && g_40106a == 21576)
            {
                xor_encrypt_func(&g_4010b9);
                MessageBoxA(NULL, &g_4010b9, "Info", 4160);
                xor_encrypt_func(&g_4010b9);
                return 
            }
            xor_encrypt_func(&g_401169);
            MessageBoxA(NULL, &g_401169, &g_401067, 4160);
            xor_encrypt_func(&g_401169);
        }
        else
        {
            return v8;
        }
    }
    return EndDialog(a0, NULL);
}

int sub_402378(unsigned int *a0, unsigned int a1, unsigned int a2)
{
    unsigned int v1;  // eax

    if (a1 == 272)
        return v1;
    if (a1 != 273)
    {
        if (a1 != 16)
            return 0;
    }
    else
    {
        if (a2 != 300)
            return v1;
    }
    return EndDialog(a0, NULL);
}

void xor_encrypt_func(char *a0)
{
    char *v0;  // ecx
    unsigned int v1;  // eax

    for (v0 = 0; *((char *)(a0 + v0)); v0 += 1)
    {
        *((char *)(a0 + v0)) = (v1 & 0xffffff00 | *((char *)(a0 + v0))) ^ 3735927486;
    }
    return;
}

void sub_4023da(unsigned int a0)
{
    return;
}

typedef struct struct_0 {
    char field_0;
    char padding_1[4198940];
    char field_40121d;
    char padding_40121e[1];
    unsigned short field_40121f;
    unsigned short field_401221;
} struct_0;

extern char g_40121d;
extern char g_40121f;

char sub_4023db(unsigned int a0, struct_0 *a1)
{
    struct_0 *v0;  // ecx
    char v1;  // al
    unsigned int v2;  // ecx

    v0 = 0;
    while (true)
    {
        v1 = *((char *)(a1 + v0));
        if (!*((char *)(a1 + v0)))
            break;
        if (!(!(v1 <= 142) && v1 != 143))
        {
            v0 = &v0->padding_1;
        }
        else if (v1 != 147)
        {
            *((char *)(v0 + &g_40121d)) = *((char *)(v0 + &g_40121d)) - 1;
            v0 = &v0->padding_1;
        }
        else
        {
            *((char *)(v0 + &g_40121d)) = 141;
            v0 = &v0->padding_1;
        }
    }
    *((unsigned short *)(v0 + &g_40121d)) = 62099;
    v2 = &v0->padding_1[1];
    *((unsigned short *)&(&g_40121d)[v2]) = 64507;
    *((unsigned short *)&(&g_40121f)[v2]) = 234;
    return v1;
}

int tls_callback_func()
{
    return 0;
}

typedef struct struct_0 {
    char padding_0[8211];
    unsigned int field_2013;
    char padding_2017[33];
    unsigned short field_2038;
} struct_0;

extern unsigned int g_4011e3;

void sub_40243f(unsigned int a0, unsigned int a1)
{
    char v0;  // [bp-0xfef5e3c]
    struct_0 *v1;  // eax
    unsigned int v2;  // eax
    unsigned int v3;  // eax

    v2 = &v1->padding_0[1];
    v0 += (char)v2;
    v3 = v2 + 1;
    *((unsigned int *)(v3 + 8209)) = g_4011e3;
    *((unsigned short *)(v3 + 8246)) = 6635;
    sub_402498();
    return;
}

typedef struct struct_0 {
    char padding_0[8283];
    unsigned int field_205b;
    char padding_205f[3];
    unsigned int field_2062;
    char padding_2066[641];
    unsigned int field_22e7;
} struct_0;

void sub_402469(unsigned int a0, unsigned int a1)
{
    struct_0 *v0;  // eax

    if (!(*((int *)&v0->padding_205f[2]) == 10454031))
        goto LABEL_0x40244a;
    if (!(*((int *)&(&v0->padding_0)[1]) == 300367232))
        goto LABEL_0x40244a;
    if (!(*((int *)&v0->padding_2066[639]) == 1618333752))
        goto LABEL_0x40244a;
    sub_402498();
    return;
}

void sub_402498()
{
    return;
}

extern struct_0 *g_401000;
extern unsigned int g_4011e3;

int sub_402499(unsigned int a0)
{
    char v0;  // [bp+0x0]
    unsigned int v1;  // eax
    unsigned int v2;  // eax

    v1 = &g_401000->padding_203b[211];
    while (*((char *)v1) != 204 || (unsigned short)v1 == 8759 || (unsigned short)v1 == 9381 || (unsigned short)v1 == 9403)
    {
        if (!((v1 + 1 & 65535) <= 9435))
        {
            v2 = &g_401000->padding_2112[3819];
            while (*((char *)v2) != 204)
            {
                if (!((v2 + 1 & 65535) <= 12635))
                    return *((int *)&v0);
            }
        }
    }
    *((unsigned int *)&(&g_401000->padding_0)[1]) = g_4011e3;
    *((unsigned short *)&g_401000->padding_2022[21]) = 6635;
    *((unsigned int *)&g_401000->padding_3001[232]) = 2088880770;
    *((unsigned int *)&g_401000->padding_30f0[4]) = 2088880770;
    return *((int *)&v0);
}

void sub_4024db()
{
    return;
}

extern struct_0 *g_401000;
extern char g_40121c;
extern unsigned short g_40122d;

int sub_402510()
{
    unsigned int v1;  // eax
    unsigned short v2;  // ax

    g_401000 = &GetModuleHandleA(NULL);
    if (g_40121c != 1)
    {
        g_40121c = g_40121c + 1;
        if (g_401000->field_a8 != 12287)
            ExitProcess(0); /* do not return */
        goto g_401000 & 0xffff0000 | (unsigned short)g_401000 + g_40122d;
    }
    else
    {
        v1 = &g_401000->field_1000;
        while (true)
        {
            *((unsigned int *)v1) = 1145128260;
            if (!(v2 < 4648))
                break;
            v2 += 4;
            v1 = v1 & 0xffff0000 | v2;
        }
        return v1;
    }
}

void sub_402566()
{
    return;
}

typedef struct struct_1 {
    char padding_0[4198945];
    char field_401221;
} struct_1;

typedef struct struct_0 {
    char padding_0[4198941];
    char field_40121d;
} struct_0;

extern char g_401005;
extern char g_401006;
extern char g_401040;
extern char g_401055;
extern char g_401067;
extern char g_40119d;
extern char g_40121d;
extern char g_401221;

void sub_402567()
{
    struct_1 *v1;  // edx
    struct_0 *v2;  // ecx

    g_401055 = (char)sub_402510() + 2;
    wsprintfA(&g_40121d, "%i");
    xor_encrypt_func(&g_40121d);
    
    if (!(*(&(&g_401006)[g_401040]) == (*((char *)(v1 + &g_401221)) ^ 190)))
        goto LABEL_0x40234b;
    if (!(!g_401005))
        goto LABEL_0x4022d8;
    if (1)
        goto LABEL_0x4022d8;
    wsprintfA(&g_40121d, "%i");
    xor_encrypt_func(&g_40119d);
    
    *((char *)(v2 + &g_40121d)) = 0;
    [D] syscall()();
    MessageBoxA(NULL, &g_40119d, &g_401067, 4160);
    xor_encrypt_func(&g_40119d);
    return;
}

extern char g_4011c4;

void sub_402655()
{
    xor_encrypt_func(&g_4011c4);
    xor_encrypt_func(&g_4011c4);
    return;
}

extern char g_401040;

void sub_40266a()
{
    g_401040 = 127;
    
}

