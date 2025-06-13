void __convention("regparm") sub_402000(HINSTANCE arg1) __noreturn
{
    sub_402439(arg1);
    DialogBoxParamA(arg1, 0x25, nullptr, 0x402029, 0);
    ExitProcess(0);
    /* no return */
}

void __stdcall sub_402378(HWND arg1, int32_t arg2, int32_t arg3)
{
    if (arg2 != 0x110)
    {
        if (arg2 == 0x111)
        {
            if (arg3 == 0x12c)
                EndDialog(arg1, 0);
        }
        else if (arg2 == 0x10)
            EndDialog(arg1, 0);
    }
}

int32_t __stdcall sub_4023b9(char* arg1)
{
    int32_t ecx = 0;
    int32_t result;
    
    while (true)
    {
        result = arg1[ecx];
        
        if (!result)
            break;
        
        arg1[ecx] = (result ^ 0xdeadbabe);
        ecx += 1;
    }
    
    return result;
}

int32_t __stdcall sub_4023da(char* arg1)
{
    void* ecx = nullptr;
    char result;
    
    while (true)
    {
        result = *(arg1 + ecx);
        
        if (!result)
            break;
        
        if (result > 0x8e && result != 0x8f)
        {
            if (result == 0x93)
            {
                *(ecx + 0x40121d) = 0x8d;
                ecx += 1;
                continue;
            }
            else
            {
                *(ecx + 0x40121d) -= 1;
                ecx += 1;
                continue;
            }
        }
        
        ecx += 1;
    }
    
    *(ecx + 0x40121d) = 0xf293;
    *(ecx + 0x40121f) = 0xfbfb;
    *(ecx + 0x401221) = 0xea;
    return result;
}

int32_t __convention("regparm") sub_402439(int32_t arg1)
{
    bool cond:0 = !IsDebuggerPresent();
    void* eax_1 = data_401000;
    
    if (cond:0 && *(eax_1 + 0x2062) == 0x9f840f && *(eax_1 + 0x205b) == 0x11e73d80
        && *(eax_1 + 0x22e7) == 0x6075d038)
    {
        sub_402498(arg1);
        return arg1;
    }
    
    *(eax_1 + 0x2011) = data_4011e3;
    *(eax_1 + 0x2036) = 0x19eb;
    sub_402498(arg1);
    return arg1;
}

int32_t __convention("regparm") sub_402498(int32_t arg1)
{
    char* eax_1 = data_401000 + 0x2111;
    
    while (*eax_1 != 0xcc || eax_1 == 0x2237 || eax_1 == 0x24a5 || eax_1 == 0x24bb)
    {
        eax_1 = &eax_1[1];
        
        if (eax_1 > 0x24db)
        {
            char* eax_3 = data_401000 + 0x3000;
            
            while (*eax_3 != 0xcc)
            {
                eax_3 = &eax_3[1];
                
                if (eax_3 > 0x315b)
                    return arg1;
            }
            
            break;
        }
    }
    
    void* eax_5 = data_401000;
    *(eax_5 + 0x201e) = data_4011e3;
    *(eax_5 + 0x2039) = 0x19eb;
    *(eax_5 + 0x30ec) = 0x7c81ca82;
    *(eax_5 + 0x30f8) = 0x7c81ca82;
    return arg1;
}

int32_t sub_4024db() __pure
{
    return;
}

int32_t _TLS_Entry_0()
{
    HMODULE eax = GetModuleHandleA(nullptr);
    data_401000 = eax;
    
    if (data_40121c != 1)
    {
        data_40121c += 1;
        
        if (*(eax + 0xa8) != 0x2fff)
        {
            ExitProcess(0);
            /* no return */
        }
        
        HMODULE ebx;
        ebx = eax + data_40122d;
        /* jump -> ebx */
    }
    
    int32_t result = data_401000 + 0x1000;
    
    while (true)
    {
        __builtin_strncpy(result, "DEAD", 4);
        
        if (result >= 0x1228)
            break;
        
        result += 4;
    }
    
    return result;
}

int32_t sub_402655()
{
    sub_4023b9(&data_4011c4);
    return sub_4023b9(&data_4011c4);
}

