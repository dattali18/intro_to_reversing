#include "out.h"



undefined * FUN_00401000(void)

{
  return &DAT_004093b8;
}



void __cdecl
FUN_00401010(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00401000();
  __stdio_common_vfprintf(*puVar1,puVar1[1],param_1,param_2,param_3,param_4);
  return;
}



undefined4 __cdecl FUN_00401040(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0x00000008;
  uVar2 = 0;
  uVar1 = __acrt_iob_func(1);
  uVar1 = FUN_00401010(uVar1,param_1,uVar2,puVar3);
  return uVar1;
}



void FUN_00401080(void)

{
  char cVar1;
  errno_t eVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *local_148;
  char *local_144;
  char *local_140;
  char *local_13c;
  undefined4 local_134;
  char local_130 [260];
  char local_2c [20];
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00409004 ^ (uint)&stack0xfffffffc;
  builtin_strncpy(local_2c,"C:\\ReversingCTF\\",0x11);
  builtin_strncpy(local_18,"AttackIRGC.dll",0xf);
  local_148 = local_2c;
  local_140 = local_130;
  do {
    cVar1 = *local_148;
    *local_140 = cVar1;
    local_148 = local_148 + 1;
    local_140 = local_140 + 1;
  } while (cVar1 != '\0');
  local_13c = local_18;
  do {
    cVar1 = *local_13c;
    local_13c = local_13c + 1;
  } while (cVar1 != '\0');
  uVar3 = (int)local_13c - (int)local_18;
  local_144 = (char *)((int)&local_134 + 3);
  do {
    pcVar5 = local_144 + 1;
    local_144 = local_144 + 1;
  } while (*pcVar5 != '\0');
  pcVar5 = local_18;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)local_144 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    local_144 = local_144 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *local_144 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    local_144 = local_144 + 1;
  }
  eVar2 = fopen_s((FILE **)&local_134,local_130,"wb");
  if (eVar2 == 0) {
    fwrite(&DAT_00405480,1,0x2c00,local_134);
    fclose(local_134);
  }
  FUN_00401ac4(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



void __cdecl print_str_typewriter(char *param_1)

{
  FILE *_File;
  
  while (*param_1 != '\0') {
    putchar((int)*param_1);
    param_1 = param_1 + 1;
    _File = (FILE *)__acrt_iob_func(1);
    fflush(_File);
    Sleep(0xf);
  }
  return;
}



int __cdecl FUN_004012e0(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 % 3;
  if (iVar1 == 0) {
    iVar1 = param_1 << 1;
  }
  else if (iVar1 == 1) {
    iVar1 = param_1 + 100;
  }
  else if (iVar1 == 2) {
    iVar1 = param_1 + -0x32;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



void FUN_00401330(void)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x7b;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    local_c = local_8 * 7 ^ local_c;
  }
  uVar1 = FUN_004012e0(local_c);
  FUN_00401430();
  FUN_00401390(local_c,uVar1);
  return;
}



int __cdecl FUN_00401390(uint param_1,uint param_2)

{
  return ((param_1 ^ param_2) + (param_1 & param_2)) - (param_1 | param_2);
}



void __cdecl FUN_004013b0(char *param_1)

{
  char cVar1;
  char *local_10;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    local_10 = param_1;
    do {
      cVar1 = *local_10;
      local_10 = local_10 + 1;
    } while (cVar1 != '\0');
    if ((uint)((int)local_10 - (int)(param_1 + 1)) <= local_c) break;
    param_1[local_c] = param_1[local_c] ^ 0x2a;
    param_1[local_c] = param_1[local_c] ^ 0x2a;
    local_c = local_c + 1;
  }
  return;
}



void FUN_00401430(void)

{
  char cVar1;
  HANDLE pvVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *local_2c0;
  char *local_2bc;
  char *local_2b8;
  char *local_2b4;
  int local_2b0;
  uint local_2a8;
  _WIN32_FIND_DATAA local_2a0;
  undefined4 local_160;
  char local_15c [260];
  char local_58 [44];
  char local_2c [20];
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00409004 ^ (uint)&stack0xfffffffc;
  builtin_strncpy(local_2c,"C:\\ReversingCTF\\",0x11);
  builtin_strncpy(local_18,"DroneAttack.txt",0x10);
  local_2c0 = local_2c;
  local_2b8 = local_15c;
  do {
    cVar1 = *local_2c0;
    *local_2b8 = cVar1;
    local_2c0 = local_2c0 + 1;
    local_2b8 = local_2b8 + 1;
  } while (cVar1 != '\0');
  local_2b4 = local_18;
  do {
    cVar1 = *local_2b4;
    local_2b4 = local_2b4 + 1;
  } while (cVar1 != '\0');
  uVar3 = (int)local_2b4 - (int)local_18;
  local_2bc = (char *)((int)&local_160 + 3);
  do {
    pcVar5 = local_2bc + 1;
    local_2bc = local_2bc + 1;
  } while (*pcVar5 != '\0');
  pcVar5 = local_18;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)local_2bc = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    local_2bc = local_2bc + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *local_2bc = *pcVar5;
    pcVar5 = pcVar5 + 1;
    local_2bc = local_2bc + 1;
  }
  pvVar2 = FindFirstFileA(local_15c,&local_2a0);
  if (pvVar2 == (HANDLE)0xffffffff) {
    Sleep(2000);
    print_str_typewriter("Danger! Anti aircraft system is still operating\n");
  }
  else {
    Sleep(2000);
    print_str_typewriter("Anti aircraft system located\nIntiating disable sequence\n\n");
    FindClose(pvVar2);
    pvVar2 = CreateFileA(local_15c,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
    if (pvVar2 == (HANDLE)0xffffffff) {
      Sleep(2000);
      print_str_typewriter("Danger! Anti aircraft system found but something is wrong. it is not disabled\n"
                  );
    }
    else {
      local_160 = 0;
      local_2a8 = 0;
      for (local_2b0 = 0; local_2b0 < 0x20; local_2b0 = local_2b0 + 1) {
        local_58[local_2a8] = s_0123456789ABCDEF0123456789ABCDEF_0040901c[local_2b0];
        uVar3 = local_2b0 + 1U & 0x80000003;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
        }
        uVar4 = local_2a8 + 1;
        if ((uVar3 == 0) && (local_2b0 != 0x1f)) {
          local_58[local_2a8 + 1] = ' ';
          uVar4 = local_2a8 + 2;
        }
        local_2a8 = uVar4;
      }
      if (0x28 < local_2a8) {
        FUN_00401bf4();
      }
      local_58[local_2a8] = '\0';
      WriteFile(pvVar2,local_58,local_2a8,&local_160,(LPOVERLAPPED)0x0);
      CloseHandle(pvVar2);
      Sleep(2000);
      print_str_typewriter(
                  "Great job. Anti aircraft system is disabled\n\nStage 2: You are a jet fighter pilot. The sky is clear. Your mission: release bombs on IRGC headquarters.\nTo find them, use the cyber intelligence unit\n"
                  );
      FUN_00401080();
    }
  }
  FUN_00401ac4(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_004017b0(void)

{
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00409004 ^ (uint)&stack0xfffffffc;
  FUN_00401040(&DAT_004053a4);
  Sleep(2000);
  print_str_typewriter(
              "Stage 1: You are a special operations expert.\nYour mission is to protect our pilots. Disable the anti aircraft system\nOh, intelligence report says the enemy spread decoys, find the real target, fast!\n\n"
              );
  builtin_strncpy(local_10,"Radar",6);
  FUN_004013b0(local_10);
  FUN_00401330();
  FUN_00401ac4(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



int __cdecl
FUN_00401820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint *puVar1;
  int local_c;
  
  puVar1 = (uint *)FUN_00401000();
  local_c = __stdio_common_vsprintf(*puVar1 | 1,puVar1[1],param_1,param_2,param_3,param_4,param_5);
  if (local_c < 0) {
    local_c = -1;
  }
  return local_c;
}



void __cdecl
FUN_00401880(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00401820(param_1,0xffffffff,param_2,param_3,param_4);
  return;
}



undefined4 __cdecl FUN_004018a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00401880(param_1,param_2,0,&stack0x0000000c);
  return uVar1;
}



void FUN_004018e0(void)

{
  GetComputerNameA(&DAT_004093c4,(LPDWORD)&DAT_00409040);
  return;
}



// WARNING: Removing unreachable block (ram,0x004019b8)

void FUN_00401900(void)

{
  char *pcVar1;
  uint local_10;
  char *local_c;
  
  local_c = &DAT_004093c4;
  pcVar1 = local_c;
  do {
    local_c = pcVar1;
    pcVar1 = local_c + 1;
  } while (*local_c != '\0');
  CryptHashData(DAT_004093c0,&DAT_004093c4,(DWORD)(local_c + -0x4093c4),0);
  CryptGetHashParam(DAT_004093c0,2,&DAT_004093d4,&DAT_0040904c,0);
  for (local_10 = 0; local_10 < DAT_0040904c; local_10 = local_10 + 1) {
    FUN_004018a0(s_0123456789ABCDEF0123456789ABCDEF_0040901c + local_10 * 2,"%02X");
  }
  s_0123456789ABCDEF0123456789ABCDEF_0040901c[0x20] = '\0';
  return;
}



// WARNING: Removing unreachable block (ram,0x00401a8d)

void tls_callback_0(undefined4 param_1,int param_2)

{
  uint local_14;
  int local_10;
  HCRYPTPROV local_c;
  uint local_8;
  
  local_8 = DAT_00409004 ^ (uint)&stack0xfffffffc;
  if (param_2 == 1) {
    CryptAcquireContextA(&local_c,(LPCSTR)0x0,(LPCSTR)0x0,1,0xf0000000);
    CryptCreateHash(local_c,0x8003,0,0,&DAT_004093c0);
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      (*(code *)(&PTR_FUN_00409044)[local_14])();
    }
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      FUN_004018a0(s_0123456789ABCDEF0123456789ABCDEF_0040901c + local_10 * 2,&DAT_00408088);
    }
    s_0123456789ABCDEF0123456789ABCDEF_0040901c[0x20] = '\0';
    CryptDestroyHash(DAT_004093c0);
    CryptReleaseContext(local_c,0);
  }
  FUN_00401ac4(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



void __fastcall FUN_00401ac4(int param_1)

{
  if (param_1 == DAT_00409004) {
    return;
  }
  FUN_00401afa();
  return;
}



void __cdecl FUN_00401ad2(_EXCEPTION_POINTERS *param_1)

{
  HANDLE hProcess;
  UINT uExitCode;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00401afa(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_00409148 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_00409150 = (undefined4)uVar9;
  _DAT_00409160 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_00409164 = &stack0x00000004;
  _DAT_004090a0 = 0x10001;
  _DAT_00409050 = 0xc0000409;
  _DAT_00409054 = 1;
  _DAT_00409060 = 1;
  DAT_00409064 = 2;
  _DAT_0040905c = unaff_retaddr;
  _DAT_0040912c = in_GS;
  _DAT_00409130 = in_FS;
  _DAT_00409134 = in_ES;
  _DAT_00409138 = in_DS;
  _DAT_0040913c = unaff_EDI;
  _DAT_00409140 = unaff_ESI;
  _DAT_00409144 = unaff_EBX;
  _DAT_0040914c = uVar3;
  _DAT_00409154 = unaff_EBP;
  DAT_00409158 = unaff_retaddr;
  _DAT_0040915c = in_CS;
  _DAT_00409168 = in_SS;
  FUN_00401ad2((_EXCEPTION_POINTERS *)&PTR_DAT_00403158);
  return;
}



void FUN_00401bf4(void)

{
  FUN_00401c00(8);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __cdecl FUN_00401c00(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_00409148 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_00409150 = (undefined4)uVar9;
  _DAT_00409160 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_00409164 = &param_1;
  _DAT_00409050 = 0xc0000409;
  _DAT_00409054 = 1;
  _DAT_00409060 = 1;
  DAT_00409064 = param_1;
  _DAT_0040905c = unaff_retaddr;
  _DAT_0040912c = in_GS;
  _DAT_00409130 = in_FS;
  _DAT_00409134 = in_ES;
  _DAT_00409138 = in_DS;
  _DAT_0040913c = unaff_EDI;
  _DAT_00409140 = unaff_ESI;
  _DAT_00409144 = unaff_EBX;
  _DAT_0040914c = uVar3;
  _DAT_00409154 = unaff_EBP;
  DAT_00409158 = unaff_retaddr;
  _DAT_0040915c = in_CS;
  _DAT_00409168 = in_SS;
  FUN_00401ad2((_EXCEPTION_POINTERS *)&PTR_DAT_00403158);
  return;
}



// WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4

int FUN_00401d94(void)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int unaff_ESI;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_14;
  
  uVar3 = ___scrt_initialize_crt(1);
  if ((char)uVar3 != '\0') {
    bVar2 = false;
    uVar3 = ___scrt_acquire_startup_lock();
    if (DAT_00409370 != 1) {
      if (DAT_00409370 == 0) {
        DAT_00409370 = 1;
        iVar4 = initterm_e(&DAT_00403128,&DAT_00403134);
        if (iVar4 != 0) {
          ExceptionList = local_14;
          return 0xff;
        }
        initterm(&DAT_0040311c,&DAT_00403124);
        DAT_00409370 = 2;
      }
      else {
        bVar2 = true;
      }
      ___scrt_release_startup_lock((char)uVar3);
      piVar5 = (int *)FUN_00402278();
      if ((*piVar5 != 0) &&
         (uVar3 = ___scrt_is_nonwritable_in_current_image((int)piVar5), (char)uVar3 != '\0')) {
        pcVar1 = (code *)*piVar5;
        uVar8 = 0;
        uVar7 = 2;
        uVar3 = 0;
        guard_check_icall();
        (*pcVar1)(uVar3,uVar7,uVar8);
      }
      piVar5 = (int *)FUN_0040227e();
      if ((*piVar5 != 0) &&
         (uVar3 = ___scrt_is_nonwritable_in_current_image((int)piVar5), (char)uVar3 != '\0')) {
        register_thread_local_exe_atexit_callback(*piVar5);
      }
      get_initial_narrow_environment();
      __p___argv();
      __p___argc();
      unaff_ESI = FUN_004017b0();
      uVar6 = FUN_004023a4();
      if ((char)uVar6 != '\0') {
        if (!bVar2) {
          _cexit();
        }
        ___scrt_uninitialize_crt(1,'\0');
        ExceptionList = local_14;
        return unaff_ESI;
      }
      goto LAB_00401f07;
    }
  }
  FUN_00402284();
LAB_00401f07:
                    // WARNING: Subroutine does not return
  exit(unaff_ESI);
}



void entry(void)

{
  ___security_init_cookie();
  FUN_00401d94();
  return;
}



// Library Function - Single Match
//  struct _IMAGE_SECTION_HEADER * __cdecl find_pe_section(unsigned char * const,unsigned int)
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

_IMAGE_SECTION_HEADER * __cdecl find_pe_section(uchar *param_1,uint param_2)

{
  int iVar1;
  _IMAGE_SECTION_HEADER *p_Var2;
  _IMAGE_SECTION_HEADER *p_Var3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  p_Var2 = (_IMAGE_SECTION_HEADER *)
           (param_1 + (uint)*(ushort *)(param_1 + iVar1 + 0x14) + iVar1 + 0x18);
  p_Var3 = p_Var2 + (uint)*(ushort *)(param_1 + iVar1 + 6) * 0x28;
  while( true ) {
    if (p_Var2 == p_Var3) {
      return (_IMAGE_SECTION_HEADER *)0x0;
    }
    if ((*(uint *)(p_Var2 + 0xc) <= param_2) &&
       (param_2 < (uint)(*(int *)(p_Var2 + 8) + *(int *)(p_Var2 + 0xc)))) break;
    p_Var2 = p_Var2 + 0x28;
  }
  return p_Var2;
}



// Library Function - Single Match
//  ___scrt_acquire_startup_lock
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

uint ___scrt_acquire_startup_lock(void)

{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  void *pvVar3;
  
  bVar2 = ___scrt_is_ucrt_dll_in_use();
  pvVar3 = (void *)CONCAT31(extraout_var,bVar2);
  if (pvVar3 != (void *)0x0) {
    while( true ) {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar1 = StackBase;
      if (DAT_00409374 != (void *)0x0) {
        pvVar3 = DAT_00409374;
        pvVar1 = DAT_00409374;
      }
      DAT_00409374 = pvVar1;
      UNLOCK();
      if (pvVar3 == (void *)0x0) break;
      if (StackBase == pvVar3) {
        return CONCAT31((int3)((uint)pvVar3 >> 8),1);
      }
    }
  }
  return (uint)pvVar3 & 0xffffff00;
}



// Library Function - Single Match
//  ___scrt_initialize_crt
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

int __cdecl ___scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint3 extraout_var;
  uint3 uVar2;
  undefined3 extraout_var_00;
  uint3 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_00409378 = 1;
  }
  FUN_00402524();
  cVar1 = FUN_00402222();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_00402222();
    if (cVar1 != '\0') {
      return CONCAT31(extraout_var_00,1);
    }
    FUN_00402222();
    uVar2 = extraout_var_01;
  }
  return (uint)uVar2 << 8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  ___scrt_initialize_onexit_tables
// 
// Library: Visual Studio 2019 Release

undefined4 __cdecl ___scrt_initialize_onexit_tables(int param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined4 in_EAX;
  undefined3 extraout_var;
  uint uVar3;
  undefined4 uVar4;
  
  if (DAT_00409379 != '\0') {
    return CONCAT31((int3)((uint)in_EAX >> 8),1);
  }
  if ((param_1 != 0) && (param_1 != 1)) {
    FUN_00402284();
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  bVar2 = ___scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT31(extraout_var,bVar2);
  if ((uVar3 == 0) || (param_1 != 0)) {
    DAT_0040937c = 0xffffffff;
    _DAT_00409380 = 0xffffffff;
    _DAT_00409384 = 0xffffffff;
    _DAT_00409388 = 0xffffffff;
    _DAT_0040938c = 0xffffffff;
    _DAT_00409390 = 0xffffffff;
LAB_00402042:
    DAT_00409379 = '\x01';
    uVar3 = CONCAT31((int3)(uVar3 >> 8),1);
  }
  else {
    uVar3 = initialize_onexit_table(&DAT_0040937c);
    if (uVar3 == 0) {
      uVar3 = initialize_onexit_table(&DAT_00409388);
      if (uVar3 == 0) goto LAB_00402042;
    }
    uVar3 = uVar3 & 0xffffff00;
  }
  return uVar3;
}



// WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4
// Library Function - Single Match
//  ___scrt_is_nonwritable_in_current_image
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

uint __cdecl ___scrt_is_nonwritable_in_current_image(int param_1)

{
  _IMAGE_SECTION_HEADER *p_Var1;
  uint uVar2;
  void *local_14;
  
  p_Var1 = find_pe_section((uchar *)&IMAGE_DOS_HEADER_00400000,param_1 - 0x400000);
  if ((p_Var1 == (_IMAGE_SECTION_HEADER *)0x0) || (*(int *)(p_Var1 + 0x24) < 0)) {
    uVar2 = (uint)p_Var1 & 0xffffff00;
  }
  else {
    uVar2 = CONCAT31((int3)((uint)p_Var1 >> 8),1);
  }
  ExceptionList = local_14;
  return uVar2;
}



// Library Function - Single Match
//  ___scrt_release_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

int __cdecl ___scrt_release_startup_lock(char param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  
  bVar2 = ___scrt_is_ucrt_dll_in_use();
  iVar1 = DAT_00409374;
  iVar3 = CONCAT31(extraout_var,bVar2);
  if ((iVar3 != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_00409374 = 0;
    UNLOCK();
    iVar3 = iVar1;
  }
  return iVar3;
}



// Library Function - Single Match
//  ___scrt_uninitialize_crt
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

undefined1 __cdecl ___scrt_uninitialize_crt(undefined4 param_1,char param_2)

{
  if ((DAT_00409378 == '\0') || (param_2 == '\0')) {
    FUN_00402222();
    FUN_00402222();
  }
  return 1;
}



// Library Function - Single Match
//  __onexit
// 
// Library: Visual Studio 2019 Release

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  int iVar1;
  
  if (DAT_0040937c == -1) {
    iVar1 = crt_atexit();
  }
  else {
    iVar1 = register_onexit_function(&DAT_0040937c,_Func);
  }
  return (_onexit_t)(~-(uint)(iVar1 != 0) & (uint)_Func);
}



// Library Function - Single Match
//  _atexit
// 
// Library: Visual Studio 2019 Release

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Library Function - Single Match
//  ___get_entropy
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

uint ___get_entropy(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;
  
  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_10);
  local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
  DVar1 = GetCurrentThreadId();
  local_8 = local_8 ^ DVar1;
  DVar1 = GetCurrentProcessId();
  local_8 = local_8 ^ DVar1;
  QueryPerformanceCounter(&local_18);
  return local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
}



// Library Function - Single Match
//  ___security_init_cookie
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __cdecl ___security_init_cookie(void)

{
  if ((DAT_00409004 == 0xbb40e64e) || ((DAT_00409004 & 0xffff0000) == 0)) {
    DAT_00409004 = ___get_entropy();
    if (DAT_00409004 == 0xbb40e64e) {
      DAT_00409004 = 0xbb40e64f;
    }
    else if ((DAT_00409004 & 0xffff0000) == 0) {
      DAT_00409004 = DAT_00409004 | (DAT_00409004 | 0x4711) << 0x10;
    }
  }
  DAT_00409000 = ~DAT_00409004;
  return;
}



undefined4 FUN_00402209(void)

{
  return 0;
}



undefined4 FUN_0040220c(void)

{
  return 1;
}



undefined4 FUN_00402210(void)

{
  return 0x4000;
}



void FUN_00402216(void)

{
  InitializeSListHead((PSLIST_HEADER)&DAT_00409398);
  return;
}



undefined1 FUN_00402222(void)

{
  return 1;
}



void FUN_00402225(void)

{
  code *pcVar1;
  errno_t eVar2;
  
  eVar2 = _controlfp_s((uint *)0x0,0x10000,0x30000);
  if (eVar2 == 0) {
    return;
  }
  FUN_00402284();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// guard_check_icall

void __cdecl guard_check_icall(void)

{
  return;
}



undefined * FUN_00402249(void)

{
  return &DAT_004093a0;
}



void FUN_0040224f(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)FUN_00401000();
  *puVar1 = *puVar1 | 0x24;
  puVar1[1] = puVar1[1];
  puVar1 = (uint *)FUN_00402249();
  *puVar1 = *puVar1 | 2;
  puVar1[1] = puVar1[1];
  return;
}



bool FUN_0040226c(void)

{
  return DAT_0040900c == 0;
}



undefined * FUN_00402278(void)

{
  return &DAT_004093e8;
}



undefined * FUN_0040227e(void)

{
  return &DAT_004093e4;
}



void FUN_00402284(void)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  undefined4 local_328 [39];
  EXCEPTION_RECORD local_5c;
  _EXCEPTION_POINTERS local_c;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  FUN_00402448();
  memset(local_328,0,0x2cc);
  local_328[0] = 0x10001;
  memset(&local_5c,0,0x50);
  local_5c.ExceptionCode = 0x40000015;
  local_5c.ExceptionFlags = 1;
  BVar2 = IsDebuggerPresent();
  local_c.ExceptionRecord = &local_5c;
  local_c.ContextRecord = (PCONTEXT)local_328;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar3 = UnhandledExceptionFilter(&local_c);
  if ((LVar3 == 0) && (BVar2 != 1)) {
    FUN_00402448();
  }
  return;
}



undefined4 thunk_FUN_00402209(void)

{
  return 0;
}



uint FUN_004023a4(void)

{
  HMODULE pHVar1;
  int *piVar2;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 != (HMODULE)0x0) && ((short)pHVar1->unused == 0x5a4d)) &&
      (piVar2 = (int *)((int)&pHVar1->unused + pHVar1[0xf].unused), *piVar2 == 0x4550)) &&
     ((pHVar1 = (HMODULE)0x10b, (short)piVar2[6] == 0x10b && (0xe < (uint)piVar2[0x1d])))) {
    return CONCAT31(1,piVar2[0x3a] != 0);
  }
  return (uint)pHVar1 & 0xffffff00;
}



undefined4 FUN_004023f2(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (((*piVar3 == -0x1f928c9d) && (piVar3[4] == 3)) &&
     ((iVar1 = piVar3[5], iVar1 == 0x19930520 ||
      (((iVar1 == 0x19930521 || (iVar1 == 0x19930522)) || (iVar1 == 0x1994000)))))) {
    piVar2 = (int *)__current_exception();
    *piVar2 = (int)piVar3;
    iVar1 = param_1[1];
    piVar3 = (int *)__current_exception_context();
    *piVar3 = iVar1;
                    // WARNING: Subroutine does not return
    terminate();
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00402448(void)

{
  _DAT_004093a8 = 0;
  return;
}



// WARNING: Removing unreachable block (ram,0x00402460)
// WARNING: Removing unreachable block (ram,0x00402461)
// WARNING: Removing unreachable block (ram,0x00402467)
// WARNING: Removing unreachable block (ram,0x00402471)
// WARNING: Removing unreachable block (ram,0x00402478)

void FUN_00402450(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x0040248c)
// WARNING: Removing unreachable block (ram,0x0040248d)
// WARNING: Removing unreachable block (ram,0x00402493)
// WARNING: Removing unreachable block (ram,0x0040249d)
// WARNING: Removing unreachable block (ram,0x004024a4)

void FUN_0040247c(void)

{
  return;
}



// WARNING: This is an inlined function
// WARNING: Unable to track spacebase fully for stack
// WARNING: Variable defined which should be unmapped: param_2
// Library Function - Single Match
//  __SEH_prolog4
// 
// Library: Visual Studio

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  iVar1 = -param_2;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_00409004 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Library Function - Single Match
//  __except_handler4
// 
// Library: Visual Studio 2019 Release

void __cdecl
__except_handler4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __filter_x86_sse2_floating_point_exception_default(*param_1);
  *param_1 = iVar1;
  except_handler4_common(&DAT_00409004,FUN_00401ac4,param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Removing unreachable block (ram,0x00402593)
// WARNING: Removing unreachable block (ram,0x00402557)
// WARNING: Removing unreachable block (ram,0x0040260b)

undefined4 FUN_00402524(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint in_XCR0;
  
  DAT_004093ac = 0;
  DAT_00409010 = DAT_00409010 | 1;
  BVar4 = IsProcessorFeaturePresent(10);
  uVar5 = DAT_00409010;
  if (BVar4 != 0) {
    piVar1 = (int *)cpuid_basic_info(0);
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar6 = puVar2[3];
    if (((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) &&
       (((((uVar5 = *puVar2 & 0xfff3ff0, uVar5 == 0x106c0 || (uVar5 == 0x20660)) ||
          (uVar5 == 0x20670)) || ((uVar5 == 0x30650 || (uVar5 == 0x30660)))) || (uVar5 == 0x30670)))
       ) {
      DAT_004093b0 = DAT_004093b0 | 1;
    }
    if (*piVar1 < 7) {
      uVar7 = 0;
    }
    else {
      iVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar7 = *(uint *)(iVar3 + 4);
      if ((uVar7 & 0x200) != 0) {
        DAT_004093b0 = DAT_004093b0 | 2;
      }
    }
    DAT_004093ac = 1;
    uVar5 = DAT_00409010 | 2;
    if ((uVar6 & 0x100000) != 0) {
      uVar5 = DAT_00409010 | 6;
      DAT_004093ac = 2;
      if ((((uVar6 & 0x8000000) != 0) && ((uVar6 & 0x10000000) != 0)) && ((in_XCR0 & 6) == 6)) {
        DAT_004093ac = 3;
        uVar5 = DAT_00409010 | 0xe;
        if ((uVar7 & 0x20) != 0) {
          DAT_004093ac = 5;
          uVar5 = DAT_00409010 | 0x2e;
          if (((uVar7 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
            DAT_00409010 = DAT_00409010 | 0x6e;
            DAT_004093ac = 6;
            uVar5 = DAT_00409010;
          }
        }
      }
    }
  }
  DAT_00409010 = uVar5;
  return 0;
}



// Library Function - Single Match
//  ___scrt_is_ucrt_dll_in_use
// 
// Library: Visual Studio 2019 Release

bool ___scrt_is_ucrt_dll_in_use(void)

{
  return DAT_00409014 != 0;
}



void __current_exception(void)

{
                    // WARNING: Could not recover jumptable at 0x00402704. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception();
  return;
}



void __current_exception_context(void)

{
                    // WARNING: Could not recover jumptable at 0x0040270a. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception_context();
  return;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00402710. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __cdecl except_handler4_common(void)

{
                    // WARNING: Could not recover jumptable at 0x00402716. Too many branches
                    // WARNING: Treating indirect jump as call
  except_handler4_common();
  return;
}



void _seh_filter_exe(void)

{
                    // WARNING: Could not recover jumptable at 0x0040271c. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_exe();
  return;
}



void _set_app_type(void)

{
                    // WARNING: Could not recover jumptable at 0x00402722. Too many branches
                    // WARNING: Treating indirect jump as call
  _set_app_type();
  return;
}



void __setusermatherr(void)

{
                    // WARNING: Could not recover jumptable at 0x00402728. Too many branches
                    // WARNING: Treating indirect jump as call
  __setusermatherr();
  return;
}



void _configure_narrow_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x0040272e. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_narrow_argv();
  return;
}



void _initialize_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x00402734. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_narrow_environment();
  return;
}



void __cdecl get_initial_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x0040273a. Too many branches
                    // WARNING: Treating indirect jump as call
  get_initial_narrow_environment();
  return;
}



void __cdecl initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x00402740. Too many branches
                    // WARNING: Treating indirect jump as call
  initterm();
  return;
}



void __cdecl initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x00402746. Too many branches
                    // WARNING: Treating indirect jump as call
  initterm_e();
  return;
}



void __cdecl exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x0040274c. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  exit(_Code);
  return;
}



void __cdecl _exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x00402752. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _exit(_Code);
  return;
}



errno_t __cdecl _set_fmode(int _Mode)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x00402758. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = _set_fmode(_Mode);
  return eVar1;
}



void __p___argc(void)

{
                    // WARNING: Could not recover jumptable at 0x0040275e. Too many branches
                    // WARNING: Treating indirect jump as call
  __p___argc();
  return;
}



void __p___argv(void)

{
                    // WARNING: Could not recover jumptable at 0x00402764. Too many branches
                    // WARNING: Treating indirect jump as call
  __p___argv();
  return;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x0040276a. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



void __cdecl _c_exit(void)

{
                    // WARNING: Could not recover jumptable at 0x00402770. Too many branches
                    // WARNING: Treating indirect jump as call
  _c_exit();
  return;
}



void __cdecl register_thread_local_exe_atexit_callback(void)

{
                    // WARNING: Could not recover jumptable at 0x00402776. Too many branches
                    // WARNING: Treating indirect jump as call
  register_thread_local_exe_atexit_callback();
  return;
}



int __cdecl _configthreadlocale(int _Flag)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0040277c. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _configthreadlocale(_Flag);
  return iVar1;
}



void __p__commode(void)

{
                    // WARNING: Could not recover jumptable at 0x00402788. Too many branches
                    // WARNING: Treating indirect jump as call
  __p__commode();
  return;
}



void __cdecl initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x0040278e. Too many branches
                    // WARNING: Treating indirect jump as call
  initialize_onexit_table();
  return;
}



void __cdecl register_onexit_function(void)

{
                    // WARNING: Could not recover jumptable at 0x00402794. Too many branches
                    // WARNING: Treating indirect jump as call
  register_onexit_function();
  return;
}



void __cdecl crt_atexit(void)

{
                    // WARNING: Could not recover jumptable at 0x0040279a. Too many branches
                    // WARNING: Treating indirect jump as call
  crt_atexit();
  return;
}



errno_t __cdecl _controlfp_s(uint *_CurrentState,uint _NewValue,uint _Mask)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x004027a0. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = _controlfp_s(_CurrentState,_NewValue,_Mask);
  return eVar1;
}



void terminate(void)

{
                    // WARNING: Could not recover jumptable at 0x004027a6. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  terminate();
  return;
}



// Library Function - Single Match
//  __filter_x86_sse2_floating_point_exception_default
// 
// Library: Visual Studio 2019 Release

int __cdecl __filter_x86_sse2_floating_point_exception_default(int param_1)

{
  uint uVar1;
  
  if ((DAT_004093ac < 1) || ((param_1 != -0x3ffffd4c && (param_1 != -0x3ffffd4b)))) {
    return param_1;
  }
  uVar1 = MXCSR ^ 0x3f;
  if ((uVar1 & 0x81) != 0) {
    if ((uVar1 & 0x204) == 0) {
      return -0x3fffff72;
    }
    if ((uVar1 & 0x102) != 0) {
      if ((uVar1 & 0x408) == 0) {
        return -0x3fffff6f;
      }
      if ((uVar1 & 0x810) != 0) {
        if ((uVar1 & 0x1020) != 0) {
          return param_1;
        }
        return -0x3fffff71;
      }
      return -0x3fffff6d;
    }
  }
  return -0x3fffff70;
}



