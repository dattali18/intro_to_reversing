int32_t sub_401000() __pure
{
    return &data_4093b8;
}

int32_t sub_401010(FILE* arg1, char* arg2, _locale_t arg3, va_list arg4)
{
    int32_t var_18 = data_4093bc;
    return __stdio_common_vfprintf(data_4093b8, arg1, arg2, arg3, arg4);
}

int32_t sub_401040(char* arg1)
{
    int32_t var_8_1 = 0;
    void arg_8;
    return sub_401010(__acrt_iob_func(1), arg1, nullptr, &arg_8);
}

errno_t sub_401080()
{
    __security_cookie;
    char var_2c;
    __builtin_strncpy(&var_2c, "C:\\ReversingCTF\\", 0x11);
    char var_18;
    __builtin_strncpy(&var_18, "AttackIRGC.dll", 0xf);
    char* var_148 = &var_2c;
    char _FileName[0x104];
    char (* var_140)[0x104] = &_FileName;
    char (* var_15c)[0x104] = var_140;
    char i;
    
    do
    {
        char (* ecx)[0x104];
        ecx = *var_148;
        i = ecx;
        char* eax_2;
        eax_2 = i;
        *var_140 = eax_2;
        var_148 = &var_148[1];
        var_140 = &(*var_140)[1];
    } while (i);
    char* var_13c = &var_18;
    char* var_14c = var_13c;
    char i_1;
    
    do
    {
        i_1 = *var_13c;
        var_13c = &var_13c[1];
    } while (i_1);
    int32_t ecx_4 = var_13c - var_14c;
    FILE* _Stream;
    void* var_144 = &*_Stream[3];
    char* edx_5;
    
    do
    {
        edx_5 = *(var_144 + 1);
        var_144 += 1;
    } while (edx_5);
    int32_t esi_1;
    int32_t edi_1;
    edi_1 = __builtin_memcpy(var_144, var_14c, ecx_4 >> 2 << 2);
    __builtin_memcpy(edi_1, esi_1, ecx_4 & 3);
    errno_t result = fopen_s(&_Stream, &_FileName, "wb");
    
    if (!result)
    {
        uint32_t var_160_1 = fwrite(&data_405480, 1, 0x2c00, _Stream);
        result = fclose(_Stream);
    }
    
    CookieCheckFunction(result);
    return result;
}

char* sub_401290(char* arg1)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    
    while (*arg1)
    {
        putchar(*arg1);
        arg1 = &arg1[1];
        fflush(__acrt_iob_func(1));
        Sleep(0xf);
    }
    
    return arg1;
}

int32_t sub_4012e0(int32_t arg1) __pure
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t temp1 = arg1 % 3;
    
    if (!temp1)
        return arg1 << 1;
    
    if (temp1 == 1)
        return arg1 + 0x64;
    
    if (temp1 == 2)
        return arg1 - 0x32;
    
    return 0;
}

int32_t sub_401330()
{
    int32_t var_c = 0x7b;
    
    for (int32_t i = 0; i < 5; i += 1)
        var_c ^= i * 7;
    
    int32_t eax_3 = sub_4012e0(var_c);
    sub_401430();
    return sub_401390(var_c, eax_3);
}

int32_t sub_401390(int32_t arg1, int32_t arg2) __pure
{
    return (arg1 ^ arg2) + (arg1 & arg2) - (arg1 | arg2);
}

int32_t sub_4013b0(char* arg1)
{
    int32_t result = 0;
    
    while (true)
    {
        char* var_10_1 = arg1;
        char* ecx_1;
        
        do
        {
            ecx_1 = *var_10_1;
            var_10_1 = &var_10_1[1];
        } while (ecx_1);
        
        if (result >= var_10_1 - &var_10_1[1])
            break;
        
        arg1[result] ^= 0x2a;
        arg1[result] ^= 0x2a;
        result += 1;
    }
    
    return result;
}

errno_t sub_401430()
{
    __security_cookie;
    char var_2c;
    __builtin_strncpy(&var_2c, "C:\\ReversingCTF\\", 0x11);
    char var_18;
    __builtin_strncpy(&var_18, "DroneAttack.txt", 0x10);
    char* var_2c0 = &var_2c;
    void fileName;
    void* var_2b8 = &fileName;
    void* var_2dc = var_2b8;
    char i;
    
    do
    {
        void* ecx;
        ecx = *var_2c0;
        i = ecx;
        char* eax_2;
        eax_2 = i;
        *var_2b8 = eax_2;
        var_2c0 = &var_2c0[1];
        var_2b8 += 1;
    } while (i);
    char* var_2b4 = &var_18;
    char* var_2c8 = var_2b4;
    char i_1;
    
    do
    {
        i_1 = *var_2b4;
        var_2b4 = &var_2b4[1];
    } while (i_1);
    int32_t ecx_4 = var_2b4 - var_2c8;
    uint32_t numberOfBytesWritten;
    void* var_2bc = &*numberOfBytesWritten[3];
    char* edx_5;
    
    do
    {
        edx_5 = *(var_2bc + 1);
        var_2bc += 1;
    } while (edx_5);
    int32_t esi_1;
    int32_t edi_1;
    edi_1 = __builtin_memcpy(var_2bc, var_2c8, ecx_4 >> 2 << 2);
    __builtin_memcpy(edi_1, esi_1, ecx_4 & 3);
    WIN32_FIND_DATAA findFileData;
    HANDLE hFindFile = FindFirstFileA(&fileName, &findFileData);
    errno_t result;
    
    if (hFindFile == 0xffffffff)
    {
        Sleep(0x7d0);
        result = sub_401290("Danger! Anti aircraft system is …");
    }
    else
    {
        Sleep(0x7d0);
        sub_401290("Anti aircraft system located\nIn…");
        FindClose(hFindFile);
        HANDLE eax_5;
        int32_t edx_6;
        eax_5 = CreateFileA(&fileName, 0x40000000, FILE_SHARE_NONE, nullptr, CREATE_ALWAYS, 
            FILE_ATTRIBUTE_NORMAL, nullptr);
        
        if (eax_5 == 0xffffffff)
        {
            Sleep(0x7d0);
            result = sub_401290("Danger! Anti aircraft system fou…");
        }
        else
        {
            numberOfBytesWritten = 0;
            uint32_t nNumberOfBytesToWrite = 0;
            uint8_t buffer[0x2c];
            
            for (int32_t i_2 = 0; i_2 < 0x20; i_2 += 1)
            {
                edx_6 = data_40901c[i_2];
                buffer[nNumberOfBytesToWrite] = edx_6;
                nNumberOfBytesToWrite += 1;
                int32_t ecx_13 = (i_2 + 1) & 0x80000003;
                
                if (ecx_13 < 0)
                    ecx_13 = ((ecx_13 - 1) | 0xfffffffc) + 1;
                
                if (!ecx_13 && i_2 != 0x1f)
                {
                    buffer[nNumberOfBytesToWrite] = 0x20;
                    nNumberOfBytesToWrite += 1;
                }
            }
            
            if (nNumberOfBytesToWrite >= 0x29)
            {
                sub_401bf4();
                /* no return */
            }
            
            buffer[nNumberOfBytesToWrite] = 0;
            BOOL var_2e0_1 =
                WriteFile(eax_5, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr);
            CloseHandle(eax_5);
            Sleep(0x7d0);
            sub_401290("Great job. Anti aircraft system …");
            result = sub_401080();
        }
    }
    
    CookieCheckFunction(result);
    return result;
}

int32_t sub_4017b0()
{
    __security_cookie;
    char const (* var_14)[0x120] = data_409018;
    sub_401040("%s\n");
    Sleep(0x7d0);
    sub_401290("Stage 1: You are a special opera…");
    int32_t var_10;
    __builtin_strcpy(&var_10, "Radar");
    sub_4013b0(&var_10);
    sub_401330();
    CookieCheckFunction(0);
    return 0;
}

int32_t sub_401820(char* arg1, uint32_t arg2, char* arg3, _locale_t arg4, va_list arg5)
{
    int32_t var_24 = data_4093bc;
    int32_t result = __stdio_common_vsprintf(data_4093b8 | 1, arg1, arg2, arg3, arg4, arg5);
    
    if (result >= 0)
        return result;
    
    return 0xffffffff;
}

int32_t sub_401880(char* arg1, char* arg2, _locale_t arg3, va_list arg4)
{
    return sub_401820(arg1, 0xffffffff, arg2, arg3, arg4);
}

int32_t _fwprintf(char* arg1, char* arg2)
{
    int32_t var_8_1 = 0;
    void arg_c;
    return sub_401880(arg1, arg2, nullptr, &arg_c);
}

BOOL sub_4018e0()
{
    return GetComputerNameA(&data_4093c4, &data_409040);
}

BOOL sub_401900()
{
    void* var_c = &data_4093c4;
    char i;
    
    do
    {
        i = *var_c;
        var_c += 1;
    } while (i);
    CryptHashData(data_4093c0, &data_4093c4, var_c - &data_4093c5, 0);
    BOOL result = CryptGetHashParam(data_4093c0, 2, &data_4093d4, &data_40904c, 0);
    
    for (int32_t i_1 = 0; i_1 < data_40904c; i_1 += 1)
    {
        uint32_t var_20_1 = *(i_1 + &data_4093d4);
        result = _fwprintf(&data_40901c[i_1 << 1], "%02X");
    }
    
    data_40901c[0x20][0] = 0;
    return result;
}

BOOL __stdcall _TLS_Entry_0(int32_t arg1)
{
    int32_t __saved_ebp;
    BOOL result = __security_cookie ^ &__saved_ebp;
    BOOL result_1 = result;
    
    if (arg1 == 1)
    {
        uint32_t var_c;
        CryptAcquireContextA(&var_c, nullptr, nullptr, 1, 0xf0000000);
        CryptCreateHash(var_c, 0x8003, 0, 0, &data_4093c0);
        
        for (int32_t i = 0; i < 2; i += 1)
            (&data_409044)[i]();
        
        for (int32_t i_1 = 0; i_1 < 0x10; i_1 += 1)
        {
            uint32_t var_1c_1 = *(i_1 + &data_4093d4);
            _fwprintf(&data_40901c[i_1 << 1], "%02X");
        }
        
        data_40901c[0x20][0] = 0;
        CryptDestroyHash(data_4093c0);
        result = CryptReleaseContext(var_c, 0);
    }
    
    CookieCheckFunction(result);
    return result;
}

void __convention("regparm") CookieCheckFunction(uint32_t arg1)
{
    int32_t ecx;
    
    if (ecx != __security_cookie)
        /* tailcall */
        return ___report_gsfailure(arg1);
}

void ___raise_securityfailure(EXCEPTION_POINTERS* arg1) __noreturn
{
    SetUnhandledExceptionFilter(nullptr);
    UnhandledExceptionFilter(arg1);
    TerminateProcess(GetCurrentProcess(), 0xc0000409);
    /* no return */
}

void ___report_gsfailure(uint64_t stack_cookie) __noreturn
{
    BOOL eax;
    int32_t ecx;
    int32_t edx;
    eax = IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE);
    bool p = /* bool p = unimplemented  {test eax, eax} */;
    bool a = /* undefined */;
    bool z = !eax;
    
    if (!z)
        trap(0xd);
    
    data_409150 = eax;
    data_40914c = ecx;
    data_409148 = edx;
    int32_t ebx;
    data_409144 = ebx;
    int32_t esi;
    data_409140 = esi;
    int32_t edi;
    data_40913c = edi;
    int16_t ss;
    data_409168 = ss;
    int16_t cs;
    data_40915c = cs;
    int16_t ds;
    data_409138 = ds;
    int16_t es;
    data_409134 = es;
    int16_t fs;
    data_409130 = fs;
    int16_t gs;
    data_40912c = gs;
    bool d;
    data_409160 = (d ? 1 : 0) << 0xa | (eax < 0 ? 1 : 0) << 7 | (z ? 1 : 0) << 6 | (a ? 1 : 0) << 4
        | (p ? 1 : 0) << 2;
    int32_t ebp;
    data_409154 = ebp;
    data_409158 = __return_addr;
    data_409164 = &stack_cookie;
    data_4090a0 = 0x10001;
    data_40905c = data_409158;
    data_409050 = 0xc0000409;
    data_409054 = 1;
    data_409060 = 1;
    int32_t var_32c_1 = 4;
    data_409064 = 2;
    int32_t var_32c_2 = 4;
    uint32_t __security_cookie_1 = __security_cookie;
    (&__security_cookie_1)[1] = data_409000;
    ___raise_securityfailure(&data_403158);
    /* no return */
}

int32_t sub_401bf2(int32_t* arg1 @ ebp)
{
    *arg1;
}

void sub_401bf4() __noreturn
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t var_8 = 8;
    int32_t esi;
    int32_t edi;
    ___report_securityfailure(&var_4, esi, edi);
    /* no return */
}

void ___report_securityfailure(int32_t arg1 @ ebp, int32_t arg2 @ esi, int32_t arg3 @ edi) __noreturn
{
    BOOL eax;
    int32_t ecx;
    int32_t edx;
    eax = IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE);
    bool p = /* bool p = unimplemented  {test eax, eax} */;
    bool a = /* undefined */;
    bool z = !eax;
    
    if (!z)
        trap(0xd);
    
    data_409150 = eax;
    data_40914c = ecx;
    data_409148 = edx;
    int32_t ebx;
    data_409144 = ebx;
    data_409140 = arg2;
    data_40913c = arg3;
    int16_t ss;
    data_409168 = ss;
    int16_t cs;
    data_40915c = cs;
    int16_t ds;
    data_409138 = ds;
    int16_t es;
    data_409134 = es;
    int16_t fs;
    data_409130 = fs;
    int16_t gs;
    data_40912c = gs;
    bool d;
    data_409160 = (d ? 1 : 0) << 0xa | (eax < 0 ? 1 : 0) << 7 | (z ? 1 : 0) << 6 | (a ? 1 : 0) << 4
        | (p ? 1 : 0) << 2;
    data_409154 = arg1;
    data_409158 = __return_addr;
    int32_t arg_4;
    data_409164 = &arg_4;
    data_40905c = data_409158;
    data_409050 = 0xc0000409;
    data_409054 = 1;
    data_409060 = 1;
    int32_t var_324_1 = 4;
    data_409064 = arg_4;
    ___raise_securityfailure(&data_403158);
    /* no return */
}

int32_t sub_401ccd(int32_t* arg1 @ ebp)
{
    *arg1;
}

int32_t pre_c_initialization()
{
    _set_app_type(_crt_console_app);
    _set_fmode(0x4000);
    *__p__commode() = 0;
    
    if (___scrt_initialize_onexit_tables(1))
    {
        __fnclex();
        sub_402450();
        _atexit(sub_40247c);
        
        if (!_configure_narrow_argv(_crt_argv_unexpanded_arguments))
        {
            sub_402216();
            
            if (sub_40226c())
                __setusermatherr(sub_402209);
            
            __initialize_default_precision();
            _configthreadlocale(0);
            
            if (sub_402222())
                _initialize_narrow_environment();
            
            j_sub_402209();
            return 0;
        }
    }
    
    ___scrt_fastfail(7);
    breakpoint();
}

int32_t sub_401d94(int32_t arg1 @ esi)
{
    int32_t __saved_ebp_2 = 0x14;
    int32_t var_8 = 0x408598;
    enum _EXCEPTION_DISPOSITION (* var_10)(int32_t* arg1, 
        struct _EXCEPTION_REGISTRATION_RECORD* arg2, struct _CONTEXT* arg3, int32_t arg4) =
        __except_handler4;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp_3;
    int32_t __saved_ebp_1 = __saved_ebp_3;
    int32_t __saved_ebx_1;
    int32_t __saved_ebx = __saved_ebx_1;
    int32_t var_30 = arg1;
    int32_t __saved_edi_1;
    int32_t __saved_edi = __saved_edi_1;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_4 = 0x408598 ^ __security_cookie_1;
    int32_t __saved_ebp;
    void* var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c = &data_401da0;
    int32_t var_8_5 = 0xfffffffe;
    int32_t var_c_1 = var_8_4;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    var_3c = 1;
    char eax = ___scrt_initialize_crt(var_3c);
    char eax_1;
    int32_t eax_2;
    
    if (eax)
    {
        __saved_ebx_1 = 0;
        char var_1d_1 = 0;
        int32_t var_8_1 = 0;
        eax_1 = ___scrt_acquire_startup_lock();
        eax_2 = data_409370;
    }
    
    void* const* esp_1;
    
    if (!eax || eax_2 == 1)
    {
        var_3c = 7;
        esp_1 = &var_3c;
        ___scrt_fastfail(var_3c);
    }
    else
    {
        if (eax_2)
        {
            __saved_ebx_1 = 1;
            char var_1d_2 = 1;
        }
        else
        {
            data_409370 = 1;
            var_3c = &data_403134;
            void* const var_40_1 = &data_403128;
            
            if (_initterm_e(&data_403128, var_3c))
            {
                int32_t var_8_2 = 0xfffffffe;
                fsbase->NtTib.ExceptionList = ExceptionList;
                return 0xff;
            }
            
            var_3c = &data_403124;
            void* const var_40_2 = &data_40311c;
            _initterm(&data_40311c, var_3c);
            data_409370 = 2;
        }
        
        var_3c = eax_1;
        ___scrt_release_startup_lock(var_3c);
        
        if (data_4093e8)
        {
            var_3c = &data_4093e8;
            
            if (___scrt_is_nonwritable_in_current_image(var_3c))
            {
                int32_t esi = data_4093e8;
                var_3c = nullptr;
                int32_t var_40_3 = 2;
                int32_t var_44_1 = 0;
                esi(0, 2, var_3c);
            }
        }
        
        if (data_4093e4)
        {
            var_3c = &data_4093e4;
            
            if (___scrt_is_nonwritable_in_current_image(var_3c))
            {
                var_3c = data_4093e4;
                _register_thread_local_exe_atexit_callback(var_3c);
            }
        }
        
        void* eax_7 = _get_initial_narrow_environment();
        char** esi_1 = *__p___argv();
        int32_t* eax_9 = __p___argc();
        var_3c = eax_7;
        char** var_40_4 = esi_1;
        int32_t var_44_2 = *eax_9;
        sub_4017b0();
        esp_1 = &var_38;
        arg1 = 0;
        
        if (sub_4023a4())
        {
            if (!__saved_ebx_1)
                _cexit();
            
            var_3c = nullptr;
            int32_t var_40_5 = 1;
            ___scrt_uninitialize_crt(1, var_3c);
            int32_t var_8_3 = 0xfffffffe;
            fsbase->NtTib.ExceptionList = ExceptionList;
            return 0;
        }
    }
    
    *(esp_1 - 4) = arg1;
    exit();
    /* no return */
}

int32_t sub_401ebb(void* arg1 @ ebp)
{
    int32_t* _ExceptionPtr = *(arg1 - 0x14);
    uint32_t _ExceptionNum = **_ExceptionPtr;
    *(arg1 - 0x20) = _ExceptionNum;
    return _seh_filter_exe(_ExceptionNum, _ExceptionPtr);
}

int32_t sub_401ecf(void* arg1 @ ebp)
{
    int32_t* esp_5 = *(arg1 - 0x18);
    
    if (!sub_4023a4())
    {
        *(esp_5 - 4) = *(arg1 - 0x20);
        _exit();
        /* no return */
    }
    
    if (!*(arg1 - 0x19))
        _c_exit();
    
    *(arg1 - 4) = 0xfffffffe;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = *(arg1 - 0x10);
    *esp_5;
    esp_5[1];
    esp_5[2];
    esp_5[3];
    *arg1;
    return *(arg1 - 0x20);
}

int32_t _start()
{
    ___security_init_cookie();
    int32_t esi;
    /* tailcall */
    return sub_401d94(esi);
}

void* find_pe_section(void* arg1, int32_t arg2)
{
    void* ecx_1 = *(arg1 + 0x3c) + arg1;
    void* i = ecx_1 + 0x18 + *(ecx_1 + 0x14);
    
    for (void* esi_1 = *(ecx_1 + 6) * 0x28 + i; i != esi_1; i += 0x28)
    {
        if (arg2 >= *(i + 0xc) && arg2 < *(i + 8) + *(i + 0xc))
            return i;
    }
    
    return nullptr;
}

int32_t ___scrt_acquire_startup_lock()
{
    int32_t result;
    
    if (___asan_report_present())
    {
        TEB* fsbase;
        void* StackBase = fsbase->NtTib.Self->NtTib.StackBase;
        
        while (true)
        {
            result = 0;
            
            if (0 == data_409374)
                data_409374 = StackBase;
            else
                result = data_409374;
            
            if (!result)
                break;
            
            if (StackBase == result)
            {
                result = 1;
                return result;
            }
        }
    }
    
    result = 0;
    return result;
}

int32_t ___scrt_initialize_crt(int32_t arg1)
{
    if (!arg1)
        data_409378 = 1;
    
    int64_t xcr0;
    ___isa_available_init(xcr0);
    
    if (sub_402222() && sub_402222())
        return 1;
    
    return 0;
}

int32_t ___scrt_initialize_onexit_tables(int32_t arg1)
{
    if (data_409379)
    {
        int32_t eax;
        eax = 1;
        return eax;
    }
    
    if (arg1 && arg1 != 1)
    {
        ___scrt_fastfail(5);
        breakpoint();
    }
    
    int32_t eax_1;
    
    if (!___asan_report_present() || arg1)
    {
        __builtin_memset(&data_40937c, 0xff, 0x18);
        data_409379 = 1;
        eax_1 = 1;
    }
    else if (_initialize_onexit_table(&data_40937c))
        eax_1 = 0;
    else if (!_initialize_onexit_table(&data_409388))
    {
        data_409379 = 1;
        eax_1 = 1;
    }
    else
        eax_1 = 0;
    
    return eax_1;
}

void* ___scrt_is_nonwritable_in_current_image(int32_t arg1)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x4085b8;
    enum _EXCEPTION_DISPOSITION (* var_10)(int32_t* arg1, 
        struct _EXCEPTION_REGISTRATION_RECORD* arg2, struct _CONTEXT* arg3, int32_t arg4) =
        __except_handler4;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_4 = 0x4085b8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_402062;
    int32_t var_8_5 = 0xfffffffe;
    int32_t var_c = var_8_4;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8_1 = 0;
    void* result = find_pe_section(&__dos_header, arg1 - &__dos_header);
    
    if (!result || *(result + 0x24) < 0)
    {
        int32_t var_8_3 = 0xfffffffe;
        result = 0;
    }
    else
    {
        int32_t var_8_2 = 0xfffffffe;
        result = 1;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    return result;
}

int32_t sub_4020bb(void* arg1 @ ebp)
{
    int32_t result;
    result = ***(arg1 - 0x14) == 0xc0000005;
    return result;
}

int32_t ___scrt_release_startup_lock(char arg1)
{
    int32_t eax = ___asan_report_present();
    
    if (!eax || arg1)
        return eax;
    
    int32_t temp0_1 = data_409374;
    data_409374 = 0;
    return temp0_1;
}

int32_t ___scrt_uninitialize_crt(int32_t arg1, char arg2)
{
    if (!data_409378 || !arg2)
    {
        int32_t var_8_1 = arg1;
        int32_t var_c_1 = arg1;
    }
    
    int32_t result;
    result = 1;
    return result;
}

int32_t __onexit(_PVFV arg1)
{
    int32_t eax;
    
    if (data_40937c != 0xffffffff)
        eax = _register_onexit_function(&data_40937c, arg1);
    else
        eax = _crt_atexit(arg1);
    
    int32_t eax_1 = -(eax);
    return ~(eax_1 - eax_1) & arg1;
}

int32_t _atexit(_PVFV arg1)
{
    int32_t eax = __onexit(arg1);
    int32_t eax_1 = -(eax);
    return -((eax_1 - eax_1)) - 1;
}

int32_t ___get_entropy()
{
    FILETIME systemTimeAsFileTime;
    systemTimeAsFileTime.dwLowDateTime = 0;
    systemTimeAsFileTime.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&systemTimeAsFileTime);
    uint32_t var_8 = systemTimeAsFileTime.dwHighDateTime ^ systemTimeAsFileTime.dwLowDateTime;
    uint32_t eax_2 = GetCurrentThreadId();
    var_8 ^= eax_2;
    uint32_t eax_3 = GetCurrentProcessId();
    var_8 ^= eax_3;
    int32_t performanceCount;
    QueryPerformanceCounter(&performanceCount);
    int32_t var_14;
    return var_14 ^ performanceCount ^ var_8 ^ &var_8;
}

void ___security_init_cookie()
{
    uint32_t __security_cookie_1 = __security_cookie;
    
    if (__security_cookie_1 == 0xbb40e64e || !(0xffff0000 & __security_cookie_1))
    {
        uint32_t __security_cookie_2 = ___get_entropy();
        __security_cookie_1 = __security_cookie_2;
        
        if (__security_cookie_1 == 0xbb40e64e)
            __security_cookie_1 = 0xbb40e64f;
        else if (!(0xffff0000 & __security_cookie_1))
            __security_cookie_1 |= (__security_cookie_2 | 0x4711) << 0x10;
        
        __security_cookie = __security_cookie_1;
    }
    
    data_409000 = ~__security_cookie_1;
}

int32_t sub_402209() __pure
{
    return 0;
}

int32_t sub_40220c() __pure
{
    return 1;
}

int32_t sub_402210() __pure
{
    return 0x4000;
}

int32_t sub_402216()
{
    return InitializeSListHead(&data_409398);
}

int32_t sub_402222() __pure
{
    int32_t result;
    result = 1;
    return result;
}

errno_t __initialize_default_precision()
{
    errno_t result = _controlfp_s(nullptr, 0x10000, 0x30000);
    
    if (!result)
        return result;
    
    ___scrt_fastfail(7);
    breakpoint();
}

int32_t sub_402246() __pure
{
    return;
}

int32_t sub_402249() __pure
{
    return &data_4093a0;
}

int32_t ___scrt_initialize_default_local_stdio_options()
{
    int32_t ecx = data_4093bc;
    data_4093b8 |= 0x24;
    data_4093bc = ecx;
    int32_t ecx_1 = data_4093a4;
    data_4093a0 |= 2;
    data_4093a4 = ecx_1;
    return &data_4093a0;
}

int32_t sub_40226c()
{
    int32_t result;
    result = !data_40900c;
    return result;
}

int32_t sub_402278() __pure
{
    return &data_4093e8;
}

int32_t sub_40227e() __pure
{
    return &data_4093e4;
}

int32_t ___scrt_fastfail(int32_t arg1)
{
    int32_t ebx;
    int32_t var_32c_1 = ebx;
    
    if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
        trap(0xd);
    
    int32_t var_330 = 3;
    sub_402448();
    int32_t var_328;
    int32_t eax_1;
    int32_t ecx_1;
    int32_t edx;
    eax_1 = memset(&var_328, 0, 0x2cc);
    bool p = /* bool p = unimplemented  {add esp, 0xc} */;
    bool a = /* bool a = unimplemented  {add esp, 0xc} */;
    int32_t var_278 = eax_1;
    int32_t var_27c = ecx_1;
    int32_t var_280 = edx;
    int32_t var_284 = ebx;
    int32_t esi;
    int32_t var_288 = esi;
    int32_t edi;
    int32_t var_28c = edi;
    int16_t ss;
    int16_t var_260 = ss;
    int16_t cs;
    int16_t var_26c = cs;
    int16_t ds;
    int16_t var_290 = ds;
    int16_t es;
    int16_t var_294 = es;
    int16_t fs;
    int16_t var_298 = fs;
    int16_t gs;
    int16_t var_29c = gs;
    int32_t var_338;
    int32_t var_32c;
    bool d;
    int32_t var_330_1 = (&var_338 + 0xc ? 1 : 0) << 0xb | (d ? 1 : 0) << 0xa
        | (&var_32c < 0 ? 1 : 0) << 7 | (&var_338 == 0xfffffff4 ? 1 : 0) << 6 | (a ? 1 : 0) << 4
        | (p ? 1 : 0) << 2 | (&var_338 >= 0xfffffff4 ? 1 : 0);
    int32_t var_268 = var_330_1;
    void* const __return_addr_1 = __return_addr;
    var_328 = 0x10001;
    int32_t ebp;
    int32_t var_274 = ebp;
    int32_t var_5c;
    memset(&var_5c, 0, 0x50);
    var_5c = 0x40000015;
    int32_t var_58 = 1;
    void* const __return_addr_2 = __return_addr;
    int32_t ebx_1 = IsDebuggerPresent() - 1;
    char ebx_2 = -(ebx_1);
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = &var_5c;
    ExceptionInfo.ContextRecord = &var_328;
    SetUnhandledExceptionFilter(nullptr);
    int32_t result = UnhandledExceptionFilter(&ExceptionInfo);
    
    if (!result && ebx_2 - ebx_2 == 0xff)
        sub_402448();
    
    return result;
}

int32_t j_sub_402209()
{
    /* tailcall */
    return sub_402209();
}

HMODULE sub_4023a4()
{
    HMODULE result = GetModuleHandleW(nullptr);
    
    if (result && result->unused == 0x5a4d)
    {
        int32_t* ecx_2 = result * 2;
        
        if (*ecx_2 == 0x4550 && ecx_2[6] == 0x10b && ecx_2[0x1d] > 0xe)
        {
            result = ecx_2[0x3a];
            return result;
        }
    }
    
    result = 0;
    return result;
}

LPTOP_LEVEL_EXCEPTION_FILTER sub_4023e6()
{
    return SetUnhandledExceptionFilter(___scrt_unhandled_exception_filter@4);
}

int32_t __stdcall ___scrt_unhandled_exception_filter@4(int32_t* arg1)
{
    int32_t* esi = *arg1;
    
    if (*esi == 0xe06d7363 && esi[4] == 3)
    {
        int32_t eax_1 = esi[5];
        
        if (eax_1 == 0x19930520 || eax_1 == 0x19930521 || eax_1 == 0x19930522 || eax_1 == 0x1994000)
        {
            *__current_exception() = esi;
            *__current_exception_context() = arg1[1];
            terminate();
            /* no return */
        }
    }
    
    return 0;
}

int32_t sub_402448()
{
    data_4093a8 = 0;
}

void sub_402450()
{
    return;
}

void sub_40247c()
{
    return;
}

void __SEH_prolog4(int32_t arg1 @ esi, int32_t arg2 @ edi, void* arg3)
{
    enum _EXCEPTION_DISPOSITION (* var_4)(int32_t* arg1, 
        struct _EXCEPTION_REGISTRATION_RECORD* arg2, struct _CONTEXT* arg3, int32_t arg4) =
        __except_handler4;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t arg_8;
    int32_t eax = arg_8;
    int32_t ebp;
    arg_8 = ebp;
    void* esp = &ExceptionList - eax;
    int32_t ebx;
    *(esp - 4) = ebx;
    *(esp - 8) = arg1;
    *(esp - 0xc) = arg2;
    uint32_t __security_cookie_1 = __security_cookie;
    *(esp - 0x10) = __security_cookie_1 ^ &arg_8;
    void* var_10 = esp - 0x10;
    *(esp - 0x14) = __return_addr;
    void* __return_addr_1 = arg3 ^ __security_cookie_1;
    arg3 = 0xfffffffe;
    __return_addr = __return_addr_1;
    fsbase->NtTib.ExceptionList = &ExceptionList;
}

enum _EXCEPTION_DISPOSITION __except_handler4(int32_t* arg1, struct _EXCEPTION_REGISTRATION_RECORD* arg2, struct _CONTEXT* arg3, int32_t arg4)
{
    int32_t mxcsr;
    *arg1 = __filter_x86_sse2_floating_point_exception_default(mxcsr, *arg1);
    return _except_handler4_common(&__security_cookie, CookieCheckFunction, arg1, arg2, arg3, arg4);
}

int32_t ___isa_available_init(int64_t arg1 @ xcr0)
{
    data_4093ac = 0;
    data_409010 |= 1;
    
    if (IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE))
    {
        int32_t var_14_1 = 0;
        int32_t ebx;
        int32_t var_2c_1 = ebx;
        int32_t eax_1;
        int32_t ecx_1;
        int32_t edx_1;
        int32_t ebx_1;
        eax_1 = __cpuid(0, 0);
        int32_t var_28 = eax_1;
        int32_t eax_2 = var_28;
        int32_t var_38_2 = ebx;
        int32_t eax_7;
        int32_t ecx_2;
        int32_t edx_2;
        int32_t ebx_3;
        eax_7 = __cpuid(1, 0);
        var_28 = eax_7;
        int32_t var_24_2 = ebx_3;
        int32_t var_1c_2 = edx_2;
        int32_t eax_12;
        
        if (!((edx_1 ^ 0x49656e69) | (ecx_1 ^ 0x6c65746e) | (ebx_1 ^ 0x756e6547)))
            eax_12 = var_28 & 0xfff3ff0;
        
        int32_t edi_4;
        
        if (!((edx_1 ^ 0x49656e69) | (ecx_1 ^ 0x6c65746e) | (ebx_1 ^ 0x756e6547)) && (
            eax_12 == 0x106c0 || eax_12 == 0x20660 || eax_12 == 0x20670 || eax_12 == 0x30650
            || eax_12 == 0x30660 || eax_12 == 0x30670))
        {
            edi_4 = data_4093b0 | 1;
            data_4093b0 = edi_4;
        }
        else
            edi_4 = data_4093b0;
        
        int32_t ebx_5;
        
        if (eax_2 < 7)
            ebx_5 = var_14_1;
        else
        {
            int32_t* var_38_3 = &var_28;
            int32_t eax_13;
            int32_t ecx_4;
            int32_t edx_3;
            int32_t ebx_4;
            eax_13 = __cpuid(7, 0);
            var_28 = eax_13;
            int32_t var_20_3 = ecx_4;
            int32_t var_1c_3 = edx_3;
            ebx_5 = ebx_4;
            
            if (ebx_5 & 0x200)
                data_4093b0 = edi_4 | 2;
        }
        
        int32_t eax_15 = data_409010 | 2;
        data_4093ac = 1;
        data_409010 = eax_15;
        
        if (ecx_2 & 0x100000)
        {
            data_4093ac = 2;
            data_409010 = eax_15 | 4;
            
            if (ecx_2 & 0x8000000 && ecx_2 & 0x10000000)
            {
                int32_t eax_17;
                int32_t edx_4;
                edx_4 = _xgetbv(0, arg1);
                int32_t var_14_2 = edx_4;
                
                if ((eax_17 & 6) == 6)
                {
                    int32_t eax_21 = data_409010 | 8;
                    data_4093ac = 3;
                    data_409010 = eax_21;
                    
                    if (ebx_5 & 0x20)
                    {
                        data_4093ac = 5;
                        data_409010 = eax_21 | 0x20;
                        
                        if ((ebx_5 & 0xd0030000) == 0xd0030000 && (eax_17 & 0xe0) == 0xe0)
                        {
                            data_409010 |= 0x40;
                            data_4093ac = 6;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

int32_t ___asan_report_present()
{
    int32_t result;
    result = data_409014;
    return result;
}

int32_t __current_exception()
{
    /* tailcall */
    return __current_exception();
}

int32_t __current_exception_context()
{
    /* tailcall */
    return __current_exception_context();
}

int32_t memset(void* dest, int32_t c, uint32_t count)
{
    /* tailcall */
    return memset(dest, c, count);
}

enum _EXCEPTION_DISPOSITION _except_handler4_common(uint32_t* CookiePointer, void (* CookieCheckFunction)(uint32_t), struct _EXCEPTION_RECORD* ExceptionRecord, struct _EXCEPTION_REGISTRATION_RECORD* EstablisherFrame, struct _CONTEXT* ContextRecord, void* DispatcherContext)
{
    /* tailcall */
    return _except_handler4_common(CookiePointer, CookieCheckFunction, ExceptionRecord, 
        EstablisherFrame, ContextRecord, DispatcherContext);
}

int32_t _seh_filter_exe(uint32_t _ExceptionNum, struct _EXCEPTION_POINTERS* _ExceptionPtr)
{
    /* tailcall */
    return _seh_filter_exe(_ExceptionNum, _ExceptionPtr);
}

void _set_app_type(enum _crt_app_type _Type)
{
    /* tailcall */
    return _set_app_type(_Type);
}

void __setusermatherr(_UserMathErrorFunctionPointer _UserMathErrorFunction)
{
    /* tailcall */
    return __setusermatherr(_UserMathErrorFunction);
}

errno_t _configure_narrow_argv(enum _crt_argv_mode mode)
{
    /* tailcall */
    return _configure_narrow_argv(mode);
}

int32_t _initialize_narrow_environment()
{
    /* tailcall */
    return _initialize_narrow_environment();
}

char** _get_initial_narrow_environment()
{
    /* tailcall */
    return _get_initial_narrow_environment();
}

void _initterm(_PVFV* _First, _PVFV* _Last)
{
    /* tailcall */
    return _initterm(_First, _Last);
}

int32_t _initterm_e(_PIFV* _First, _PIFV* _Last)
{
    /* tailcall */
    return _initterm_e(_First, _Last);
}

void exit(int32_t _Except) __noreturn
{
    /* tailcall */
    return exit(_Except);
}

void _exit(int32_t _Except) __noreturn
{
    /* tailcall */
    return _exit(_Except);
}

errno_t _set_fmode(int32_t _Value)
{
    /* tailcall */
    return _set_fmode(_Value);
}

int32_t* __p___argc()
{
    /* tailcall */
    return __p___argc();
}

char*** __p___argv()
{
    /* tailcall */
    return __p___argv();
}

void _cexit()
{
    /* tailcall */
    return _cexit();
}

void _c_exit()
{
    /* tailcall */
    return _c_exit();
}

void _register_thread_local_exe_atexit_callback(_tls_callback_type _Callback)
{
    /* tailcall */
    return _register_thread_local_exe_atexit_callback(_Callback);
}

int32_t _configthreadlocale(int32_t _Flag)
{
    /* tailcall */
    return _configthreadlocale(_Flag);
}

int32_t _set_new_mode(int32_t _NewMode)
{
    /* tailcall */
    return _set_new_mode(_NewMode);
}

int32_t* __p__commode()
{
    /* tailcall */
    return __p__commode();
}

int32_t _initialize_onexit_table(struct _onexit_table_t* _Table)
{
    /* tailcall */
    return _initialize_onexit_table(_Table);
}

int32_t _register_onexit_function(struct _onexit_table_t* _Table, _onexit_t_1 _Function)
{
    /* tailcall */
    return _register_onexit_function(_Table, _Function);
}

int32_t _crt_atexit(_PVFV _Function)
{
    /* tailcall */
    return _crt_atexit(_Function);
}

errno_t _controlfp_s(uint32_t* _CurrentState, uint32_t _NewValue, uint32_t _Mask)
{
    /* tailcall */
    return _controlfp_s(_CurrentState, _NewValue, _Mask);
}

void terminate() __noreturn
{
    /* tailcall */
    return terminate();
}

int32_t __filter_x86_sse2_floating_point_exception_default(int32_t arg1 @ mxcsr, int32_t arg2)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    
    if (data_4093ac >= 1 && (arg2 == 0xc00002b4 || arg2 == 0xc00002b5))
    {
        int32_t eax_2 = arg1 ^ 0x3f;
        
        if (!(eax_2 & 0x81))
            return 0xc0000090;
        
        if (!(eax_2 & 0x204))
            return 0xc000008e;
        
        if (!(eax_2 & 0x102))
            return 0xc0000090;
        
        if (!(eax_2 & 0x408))
            return 0xc0000091;
        
        if (!(eax_2 & 0x810))
            return 0xc0000093;
        
        if (!(eax_2 & 0x1020))
            return 0xc000008f;
    }
    
    return arg2;
}

