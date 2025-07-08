void __convention("regparm") sub_1cb(int32_t arg1, void* arg2, void* arg3, int32_t arg4 @ ebp, int32_t arg5 @ esi, void* arg6 @ edi, float arg7[0x4] @ xmm3, int32_t arg8) __noreturn
{
    arg3 += *(arg6 + 0x4d);  /* "nIt should not be possible to re…" */
    void* edi_1 = arg6 - 2;
    void* ebp_1 = arg4 - 2;
    void* edx_5 = arg2 + 7;
    int32_t eflags;
    int32_t ebx;
    void* esp;
    
    if (arg2 + 6 <= 0xffffffff)
    {
        arg1 = __salc(eflags);
        uint8_t* edi_9;
        uint8_t temp0_2;
        temp0_2 = __insb(edi_1 - 7, (edx_5 + 0xe), eflags);
        *edi_9 = temp0_2;
        *arg1;
        *arg5;
        *(ebp_1 + 0x45) = ebx;
        void arg_8;
        esp = &arg_8;
        ebx = arg8 - 1;
        edi_1 = __return_addr - 3;
        __bound_gprv_mema32(arg3, *(edi_1 + 0x4d));  /* "nIt should not be possible to re…" */
        *arg3[1] &= *(ebp_1 - 0xe + edi_1 + 0x29);
        *arg5;
        ebp_1 -= 0xf;
        edx_5 += 0x1d;  /* "OMBBOMBBOMBBOMBBOMBBOMBBOMBBOMBB…" */
    }
    
    int16_t es;
    *(edx_5 + 0x4d) = es;  /* "nIt should not be possible to re…" */
    void* edx_56;
    
    if (edx_5 + 1 > 0xffffffff)
        edx_56 = edx_5 + 3;
    else
    {
        *(esp - 4) = edi_1;
        void* ecx;
        ecx = (arg3 + 1) + *(edi_1 + 0x4a);
        *ecx[1] += *(ebx + ebp_1 - 5 + 0x2c);
        int32_t ss;
        *(ss + edi_1 + 0x4a);
        __out_dx_al((edx_5 + 0xe), arg1, eflags);
        
        if (edx_5 + 0xf >= 0xffffffff)
            arg1 = *(edx_5 + 0x52);  /* "hould not be possible to read th…" */
        
        arg3 = *(ebp_1 + 0x3a) * 0x424d4f42;
        edi_1 -= 5;
        ebp_1 -= 0xa;
        arg3 += *(edi_1 + 0x4d);  /* "nIt should not be possible to re…" */
        *(ebp_1 + edi_1 + 0x3e) -= 0x30;
        *(edi_1 + 0x4d) &= arg3;  /* "nIt should not be possible to re…" */
        edx_56 = edx_5 + 0x17;
        *0x42424d4e = arg1;
    }
    
    arg3 += *(edi_1 + 0x4a);
    *arg3[1] += *(ebp_1 - 7 + edi_1 - 3 + 0x28);
    int32_t eflags_1;
    char temp0_3;
    temp0_3 = __das((arg1 + 0x2dbdb2d4), eflags);
    int32_t eax;
    eax = temp0_3;
    arg3 += *(edi_1 + 0x47);
    *(edx_56 + 0x67);
    *(edx_56 + 0x67) += eax;
    int32_t esp_4;
    int16_t es_1;
    esp_4 = __les_gprz_memp(*(arg3 + 0x4d0ce2fa));
    *(esp_4 - 4) = edx_56 + 0xb7;
    *(arg3 - 0x7e7c7172) = es_1;
    int32_t esp_7;
    int16_t es_2;
    esp_7 = __les_gprz_memp(*(arg3 + 0x4d0cdafa));
    *(esp_7 - 4) = edx_56 + 0xb7;
    *(arg3 - 0x7e7c7172) = es_2;
    int32_t esp_10;
    int16_t es_3;
    esp_10 = __les_gprz_memp(*(arg3 + 0x1d5b07c9));
    int16_t* ebp_120 = *(ebp_1 - 0x5f);  /* "possible to read thislB@HfOMBBOM…" */
    __maxps_xmmps_memps(arg7, *(arg3 * 9));
    *(ebp_1 - 0x5b);  /* " be possible to read thislB@HfOM…" */
    ebp_120[2];
    *0x134907cd;
    *0x134907d1;
    *0x134907cf = edx_56 + 0xb7;
    breakpoint();
}

