// ==== FUN_00401000 @ 00401000

undefined4 FUN_00401000(void)

{
  return 1;
}


// ==== FUN_00401018 @ 00401018

void FUN_00401018(void)

{
  return;
}


// ==== FUN_00401030 @ 00401030

uint FUN_00401030(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = (uint)((longlong)param_1 * (longlong)param_2);
  uVar2 = (ushort)(uVar1 + 0x8000 >> 0x10);
  return (uint)uVar2 |
         CONCAT22(uVar2,(short)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) +
                        (ushort)(0xffff7fff < uVar1)) << 0x10;
}


// ==== FUN_00401054 @ 00401054

undefined4 FUN_00401054(int param_1,int param_2)

{
  return (int)(CONCAT44(param_1 >> 0x10,param_1 << 0x10) / (longlong)param_2);
}


// ==== FUN_00401074 @ 00401074

void FUN_00401074(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  
  DAT_00427e64 = param_2;
  for (; (int)param_1 < 0; param_1 = param_1 + 0xe10) {
  }
  for (; 0xe10 < (int)param_1; param_1 = param_1 - 0xe10) {
  }
  if (param_1 < 0x709) {
    if (param_1 < 0x385) {
      iVar1 = *(int *)(&DAT_00427050 + param_1 * 4);
      iVar2 = *(int *)(&DAT_00427e60 + param_1 * -4);
    }
    else {
      iVar1 = -*(int *)(&DAT_00427050 + (0x708 - param_1) * 4);
      iVar2 = *(int *)(&DAT_00427e60 + (0x708 - param_1) * -4);
    }
  }
  else {
    param_1 = 0xe10 - param_1;
    if (param_1 < 0x385) {
      iVar1 = *(int *)(&DAT_00427050 + param_1 * 4);
      iVar2 = -*(int *)(&DAT_00427e60 + param_1 * -4);
    }
    else {
      iVar1 = -*(int *)(&DAT_00427050 + (0x708 - param_1) * 4);
      iVar2 = -*(int *)(&DAT_00427e60 + (0x708 - param_1) * -4);
    }
  }
  *param_2 = iVar1;
  *unaff_EBX = iVar2;
  return;
}


// ==== FUN_00401140 @ 00401140

void FUN_00401140(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0042e4fc == 1) || (DAT_0042e4fc == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00428000,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00428000,0x804,2,(DWORD_PTR)local_c);
    DAT_00428000 = 0;
    Sleep(1);
    DAT_0042e4fc = 0;
  }
  return;
}


// ==== FUN_004011e5 @ 004011e5

void FUN_004011e5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00427e6c != 0) && (DAT_0042e4fc == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00428000,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0042e4fc = 3;
  }
  return;
}


// ==== FUN_00401258 @ 00401258

void FUN_00401258(undefined4 param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00427e6c != 0) {
    if (DAT_0042e4fc == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_00428000,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_00428000,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_00401335(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0042e4fc = 1;
    }
    else {
      FUN_00401335(param_1);
    }
  }
  return;
}


// ==== FUN_00401335 @ 00401335

void FUN_00401335(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00427e6c == 0) {
    FUN_00401140();
  }
  else {
    if (((DAT_0042e4f8 == param_1) && (0 < param_1)) && (DAT_0042e4fc == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_00428000,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0042e4fc != 4) {
      FUN_00401140();
    }
    if (DAT_00427e6c != 0) {
      if (0 < param_1) {
        DAT_0042e4f8 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_0042e4f8;
      }
      if ((0 < param_1) && (param_1 < 6)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_0042e500 + param_1 * 0x100;
        local_20 = s_sequencer_00428004;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_00428000 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_00428000;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_00428000 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00428000,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0042e4fc = 1;
          }
          else {
            DAT_0042e4fc = 4;
          }
        }
        else {
          DAT_0042e4fc = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_00401515 @ 00401515

void FUN_00401515(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00427e6c != 0) {
    if (DAT_0042e4fc == 1) {
      if (DAT_00428000 == 0) {
        DAT_0042e4fc = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_00428000,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00428000,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0042e4fc = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0042e4fc = 4;
        }
      }
    }
    else if (DAT_0042e4fc == 4) {
      FUN_00401335(0xffffffff);
    }
  }
  return;
}


// ==== FUN_00401633 @ 00401633

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401633(int param_1)

{
  DWORD DVar1;
  
  if (DAT_00427e68 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00427e70) {
      DAT_00427e70 = DVar1;
    }
    if (DVar1 - _DAT_00427e74 < DAT_00427e70) {
      if (DAT_00427e78 <= *(int *)(&DAT_0042eb0c + param_1 * 0x10)) {
        return;
      }
      Sleep(1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00427e70 = GetTickCount();
    _DAT_00427e74 = *(int *)(&DAT_0042eb08 + param_1 * 0x10);
    DAT_00427e78 = *(int *)(&DAT_0042eb0c + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_0042eb00 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_0040174d @ 0040174d

void FUN_0040174d(void)

{
  int local_c;
  int local_8;
  
  FUN_00401140();
  FUN_00401633(0);
  for (local_8 = 0xb; local_8 < 0x1a; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042eb04 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042eb04 + local_8 * 0x10));
      *(undefined4 *)(&DAT_0042eb04 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_0042eb00 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    DeleteFileA(&DAT_0042e500 + local_c * 0x100);
  }
  return;
}


// ==== FUN_00401835 @ 00401835

void FUN_00401835(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  iVar2 = FUN_0040a2f0(DAT_0067ff20,param_2,&DAT_00428010);
  param_1[1] = iVar2;
  if (param_1[1] != 0) {
    pvVar3 = LockResource((HGLOBAL)param_1[1]);
    *param_1 = (int)pvVar3;
  }
  param_1[2] = 0;
  if (*param_1 != 0) {
    local_10 = (int *)*param_1;
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      piVar1 = (int *)((int)local_10 + 1);
      if ((char)*local_10 == 'd') {
        piVar1 = (int *)((int)local_10 + 2);
        if (*(char *)((int)local_10 + 1) == 'a') {
          piVar1 = (int *)((int)local_10 + 3);
          if (*(char *)((int)local_10 + 2) == 't') {
            piVar1 = local_10 + 1;
            if (*(char *)((int)local_10 + 3) == 'a') {
              param_1[2] = (uint)(*piVar1 * 1000) / 0x2b11 + 1;
              if (2000 < (uint)param_1[2]) {
                param_1[2] = 2000;
              }
            }
          }
        }
      }
      local_10 = piVar1;
    }
  }
  return;
}


// ==== FUN_00401964 @ 00401964

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401964(void)

{
  int local_8;
  
  _DAT_0042eb00 = 0;
  _DAT_0042eb04 = 0;
  for (local_8 = 0xb; local_8 < 0x1a; local_8 = local_8 + 1) {
    FUN_00401835(&DAT_0042eb00 + local_8 * 0x10,local_8);
    *(undefined4 *)(&DAT_0042eb0c + local_8 * 0x10) = 10;
  }
  _DAT_0042ebcc = 5;
  _DAT_0042ebfc = 2;
  _DAT_0042ebdc = 2;
  _DAT_0042ec6c = 1;
  _DAT_0042ec7c = 1;
  _DAT_0042ec8c = 1;
  _DAT_0042ec9c = 1;
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_0042e500 + local_8 * 0x100);
    FUN_00421bf0(&DAT_0042e500 + local_8 * 0x100,&DAT_00427e80 + local_8 * 0x20);
    FUN_0040a513(&DAT_00427f40 + local_8 * 0x20,&DAT_00428018,&DAT_0042e500 + local_8 * 0x100);
  }
  return;
}


// ==== FUN_00401aa0 @ 00401aa0

int __fastcall FUN_00401aa0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00401b5e;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0x10),0x3350,0xb7,FUN_00407af0,FUN_00407280);
  *(undefined4 *)(param_1 + 0xc) = 0;
  for (local_14 = 0; local_14 < 0x37; local_14 = local_14 + 1) {
    *(int *)(local_14 * 0x3350 + 0x10 + param_1) = local_14;
  }
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_00401b77 @ 00401b77

void __fastcall FUN_00401b77(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00401bdb;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  local_8 = 0xffffffff;
  FUN_00401bbf();
  FUN_00401be5();
  return;
}


// ==== FUN_00401bbf @ 00401bbf

void FUN_00401bbf(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_
            ((void *)(*(int *)(unaff_EBP + -0x10) + 0x10),0x3350,0xb7,FUN_00407280);
  return;
}


// ==== FUN_00401be5 @ 00401be5

void FUN_00401be5(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00401bf3 @ 00401bf3

void __fastcall FUN_00401bf3(int param_1)

{
  int iVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < 0x33; local_c = local_c + 1) {
    *(undefined4 *)(param_1 + 0x24ae40 + local_c * 4) = 0xffffffff;
    iVar1 = local_c * 0x3350 + param_1;
    if (*(int *)(iVar1 + 0x14) == 1) {
      FUN_00405ca3(local_c);
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== FUN_00401c91 @ 00401c91

int * FUN_00401c91(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_c;
  int local_8;
  
  if (param_2 == 0) {
    local_8 = param_3 % 10;
    local_c = param_3 / 10;
  }
  else {
    local_c = 0;
    if (param_2 == 7) {
      local_8 = param_3 + -0x32;
    }
    else {
      local_8 = (param_3 + -0x14) % 5;
    }
  }
  if (param_2 == 7) {
    local_18 = 4;
  }
  else {
    local_18 = 1;
  }
  iVar2 = local_18 * 5;
  if (param_2 == 7) {
    local_18 = 3;
  }
  else {
    local_18 = 1;
  }
  iVar1 = *(int *)(&DAT_0042b41c + param_2 * 0x10);
  *param_1 = *(int *)(&DAT_0042b418 + param_2 * 0x10) + iVar2 + local_8 * 0x37;
  param_1[1] = iVar1 + local_18 * 5 + local_c * 0x39;
  return param_1;
}


// ==== FUN_00401d9c @ 00401d9c

int __thiscall FUN_00401d9c(int param_1,int param_2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x32 < local_8) {
      return -1;
    }
    if (*(int *)(param_1 + 0x24ae40 + local_8 * 4) == param_2) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// ==== FUN_00401df5 @ 00401df5

int __fastcall FUN_00401df5(int param_1)

{
  bool bVar1;
  int local_40;
  int local_34;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  param_1 = *(int *)(param_1 + 4) * 0x3350 + param_1;
  if (*(int *)(param_1 + 0x1c) == 0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    goto LAB_00402030;
  }
  local_24 = *(int *)(param_1 + 0x32ec);
  local_20 = *(int *)(param_1 + 0x32f0);
  if (*(int *)(param_1 + 0x32c4) == 0) {
LAB_00401f13:
    local_34 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x32c4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(param_1 + 0x32c4) == 0x400) {
      if ((int)*(short *)(*(int *)(param_1 + 0x32c4) + 6) *
          (int)*(short *)(*(int *)(param_1 + 0x32c4) + 8) - *(int *)(*(int *)(param_1 + 0x32c4) + 2)
          == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00401f13;
    local_34 = (int)**(short **)(param_1 + 0x32c4);
  }
  local_1c = local_24 + local_34 + -1;
  if (*(int *)(param_1 + 0x32c4) == 0) {
LAB_00401fee:
    local_40 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x32c4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(param_1 + 0x32c4) == 0x400) {
      if ((int)*(short *)(*(int *)(param_1 + 0x32c4) + 6) *
          (int)*(short *)(*(int *)(param_1 + 0x32c4) + 8) - *(int *)(*(int *)(param_1 + 0x32c4) + 2)
          == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00401fee;
    local_40 = (int)*(short *)(*(int *)(param_1 + 0x32c4) + 2);
  }
  local_18 = local_20 + local_40 + -1;
LAB_00402030:
  local_20 = (local_20 + local_18) / 2;
  local_24 = (local_1c + local_24) / 2;
  local_28 = 0;
  local_1c = local_24;
  local_18 = local_20;
  while( true ) {
    if (7 < local_28) {
      return -1;
    }
    FUN_004184b8(&local_14,&DAT_0042b418 + local_28 * 0x10,&local_24);
    if ((((local_1c == local_c) && (local_24 == local_14)) && (local_20 == local_10)) &&
       (local_18 == local_8)) break;
    local_28 = local_28 + 1;
  }
  return local_28;
}


// ==== FUN_004020e0 @ 004020e0

int __thiscall FUN_004020e0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 local_1c [16];
  int local_c;
  int local_8;
  
  if (param_2 == 7) {
    param_1 = *(int *)(param_1 + 4) * 0x3350 + param_1;
    local_8 = param_1 + 0x10;
    for (local_c = 1; local_c < 6; local_c = local_c + 1) {
      if (*(int *)(param_1 + 0x3320 + local_c * 4) != *(int *)(param_1 + 0x3320)) {
        return -1;
      }
    }
  }
  piVar1 = (int *)FUN_004026a9(local_1c,param_2);
  if (*piVar1 < 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *piVar1 * 10 + piVar1[1];
  }
  return iVar2;
}


// ==== FUN_004021a0 @ 004021a0

void __thiscall FUN_004021a0(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x24ae40 + param_2 * 4) = 0xffffffff;
  return;
}


// ==== FUN_004021c9 @ 004021c9

void __thiscall FUN_004021c9(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x24ae40 + param_2 * 4) = param_3;
  return;
}


// ==== FUN_004021f1 @ 004021f1

void __thiscall FUN_004021f1(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_2 == 0) {
    for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
      if ((*(int *)(param_1 + 0x24ae68 + local_18 * 4) == -1) &&
         (*(int *)(param_1 + 0x24ae40 + local_18 * 4) != -1)) {
        iVar1 = *(int *)(param_1 + 0x24ae40 + local_18 * 4) * 0x3350 + param_1;
        local_14 = iVar1 + 0x10;
        FUN_00404add(*(int *)(iVar1 + 0x333c) + 200,
                     *(undefined4 *)(param_1 + 0x24ae40 + local_18 * 4));
        FUN_004021c9(local_18 + 10,*(undefined4 *)(param_1 + 0x24ae40 + local_18 * 4));
        FUN_004021a0(local_18);
        puVar2 = (undefined4 *)FUN_00401c91(local_20,0,local_18 + 10);
        local_10 = *puVar2;
        local_c = puVar2[1];
        FUN_0040db6d(local_10,local_c);
      }
    }
  }
  else if (param_2 != 7) {
    if ((param_2 & 1) == 0) {
      local_8 = param_2 * 5 + 0xf;
      for (local_18 = 4; 0 < local_18; local_18 = local_18 + -1) {
        if ((*(int *)(param_1 + 0x24ae40 + (local_8 + local_18) * 4) == -1) &&
           (*(int *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4) != -1)) {
          iVar1 = *(int *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4) * 0x3350 + param_1;
          local_14 = iVar1 + 0x10;
          FUN_00404add(*(int *)(iVar1 + 0x333c) + 200,
                       *(undefined4 *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4));
          FUN_004021c9(local_8 + local_18,
                       *(undefined4 *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4));
          FUN_004021a0(local_8 + local_18 + -1);
          puVar2 = (undefined4 *)FUN_00401c91(local_30,param_2,local_8 + local_18);
          local_10 = *puVar2;
          local_c = puVar2[1];
          FUN_0040db6d(local_10,local_c);
        }
        if ((*(int *)(param_1 + 0x24ae40 + (local_8 + local_18) * 4) == -1) &&
           (*(int *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4) != -1)) {
          iVar1 = *(int *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4) * 0x3350 + param_1;
          local_14 = iVar1 + 0x10;
          FUN_00404add(*(int *)(iVar1 + 0x333c) + 200,
                       *(undefined4 *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4));
          FUN_004021c9(local_8 + local_18,
                       *(undefined4 *)(param_1 + 0x24ae3c + (local_8 + local_18) * 4));
          FUN_004021a0(local_8 + local_18 + -1);
          puVar2 = (undefined4 *)FUN_00401c91(local_38,param_2,local_8 + local_18);
          local_10 = *puVar2;
          local_c = puVar2[1];
          FUN_0040db6d(local_10,local_c);
        }
      }
    }
    else {
      local_8 = param_2 * 5 + 0xf;
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        if ((*(int *)(param_1 + 0x24ae40 + (local_8 + local_18) * 4) == -1) &&
           (*(int *)(param_1 + 0x24ae44 + (local_8 + local_18) * 4) != -1)) {
          iVar1 = *(int *)(param_1 + 0x24ae44 + (local_8 + local_18) * 4) * 0x3350 + param_1;
          local_14 = iVar1 + 0x10;
          FUN_00404add(*(int *)(iVar1 + 0x333c) + 200,
                       *(undefined4 *)(param_1 + 0x24ae44 + (local_8 + local_18) * 4));
          FUN_004021c9(local_8 + local_18,
                       *(undefined4 *)(param_1 + 0x24ae44 + (local_8 + local_18) * 4));
          FUN_004021a0(local_8 + local_18 + 1);
          puVar2 = (undefined4 *)FUN_00401c91(local_28,param_2,local_8 + local_18);
          local_10 = *puVar2;
          local_c = puVar2[1];
          FUN_0040db6d(local_10,local_c);
        }
      }
    }
  }
  return;
}


// ==== FUN_00402622 @ 00402622

void __fastcall FUN_00402622(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  
  for (local_14 = 1; -1 < local_14; local_14 = local_14 + -1) {
    for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
      if (*(int *)(param_1 + 0x24ae40 + (local_14 * 10 + local_18) * 4) == -1) {
        *(undefined4 *)(param_1 + 0x24ae40 + (local_14 * 10 + local_18) * 4) = 1;
      }
    }
  }
  return;
}


// ==== FUN_004026a9 @ 004026a9

int * __thiscall FUN_004026a9(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 local_44 [8];
  undefined1 local_3c [8];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_34 = 1000000;
  local_2c = -1;
  local_28 = -1;
  if (param_3 == 0) {
    if ((DAT_0067ff48 == -1) && (DAT_0067ff4c == -1)) {
      for (local_24 = 1; -1 < local_24; local_24 = local_24 + -1) {
        for (local_30 = 0; local_30 < 10; local_30 = local_30 + 1) {
          if (*(int *)(param_1 + 0x24ae40 + (local_24 * 10 + local_30) * 4) == -1) {
            *param_2 = local_24;
            param_2[1] = local_30;
            return param_2;
          }
        }
      }
    }
    else {
      for (local_24 = 1; -1 < local_24; local_24 = local_24 + -1) {
        for (local_30 = 0; local_30 < 10; local_30 = local_30 + 1) {
          if (*(int *)(param_1 + 0x24ae40 + (local_24 * 10 + local_30) * 4) == -1) {
            local_1c = local_30;
            local_20 = local_24;
            piVar2 = (int *)FUN_00401c91(local_3c,0,local_30);
            local_10 = *piVar2;
            local_c = piVar2[1];
            iVar1 = FUN_00422280(local_c - DAT_0067ff4c);
            local_8 = FUN_00422280(local_10 - DAT_0067ff48);
            local_8 = iVar1 + local_8;
            if (local_8 < local_34) {
              local_2c = local_20;
              local_28 = local_1c;
              local_34 = local_8;
            }
          }
        }
      }
    }
  }
  if (param_3 == 7) {
    *param_2 = 0;
    param_2[1] = 0x32;
  }
  else {
    local_18 = param_3 * 5 + 0xf;
    for (local_30 = 0; local_30 < 5; local_30 = local_30 + 1) {
      if (*(int *)(param_1 + 0x24ae40 + (local_18 + local_30) * 4) == -1) {
        local_1c = local_18 + local_30;
        local_20 = 0;
        piVar2 = (int *)FUN_00401c91(local_44,param_3,local_1c);
        local_10 = *piVar2;
        local_c = piVar2[1];
        local_8 = FUN_00422280(local_10 - DAT_0067ff48);
        if (local_8 < local_34) {
          local_2c = local_20;
          local_28 = local_1c;
          local_34 = local_8;
        }
      }
    }
    *param_2 = local_2c;
    param_2[1] = local_28;
  }
  return param_2;
}


// ==== FUN_0040293a @ 0040293a

int __fastcall FUN_0040293a(int param_1)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x32 < local_c) {
      return -1;
    }
    if (*(int *)(local_c * 0x3350 + param_1 + 0x14) == 0) break;
    local_c = local_c + 1;
  }
  return local_c;
}


// ==== FUN_004029a5 @ 004029a5

/* WARNING: Removing unreachable block (ram,0x00402ca8) */

undefined4 __thiscall FUN_004029a5(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int local_5c;
  int local_58;
  int local_54;
  int local_48;
  int local_34;
  int local_30 [4];
  int local_20;
  int local_1c;
  int local_10 [3];
  
  local_1c = FUN_0040293a();
  if (local_1c == -1) {
    return 0;
  }
  local_10[0] = *(int *)(param_1 + 0x24ae3c + param_4 * 4) * 0x3350 + param_1 + 0x10;
  local_10[1] = *(int *)(param_1 + 0x24ae40 + param_4 * 4) * 0x3350 + param_1 + 0x10;
  local_10[2] = *(int *)(param_1 + 0x24ae44 + param_4 * 4) * 0x3350 + param_1 + 0x10;
  for (local_34 = 0; local_34 < 3; local_34 = local_34 + 1) {
    *(undefined4 *)(param_1 + 0x24b120 + local_34 * 4) =
         *(undefined4 *)(local_10[local_34] + 0x3304);
  }
  local_30[3] = local_1c * 0x3350 + param_1 + 0x10;
  for (local_34 = 0; local_34 < 6; local_34 = local_34 + 1) {
    local_30[0] = *(int *)(local_10[0] + 0x3310 + local_34 * 4);
    local_30[1] = *(int *)(local_10[1] + 0x3310 + local_34 * 4);
    local_30[2] = *(int *)(local_10[2] + 0x3310 + local_34 * 4);
    iVar2 = local_30[0];
    if (((local_30[0] != local_30[1]) && (iVar2 = local_30[0], local_30[2] != local_30[0])) &&
       (iVar2 = local_30[1], local_30[2] != local_30[1])) {
      iVar2 = FUN_00411187(3);
      iVar2 = local_30[iVar2];
    }
    local_20 = iVar2;
    *(int *)(local_30[3] + 0x3310 + local_34 * 4) = local_20;
    if ((local_34 <= *(int *)(local_30[3] + 0xc)) &&
       (local_20 * 0x798 + local_34 * 0x144 != -0x428680)) {
      FUN_004077e0(&DAT_00428680 + local_20 * 0x798 + local_34 * 0x144);
      if (*(int *)(local_30[3] + 0xc) == local_34) {
        *(int *)(local_30[3] + 0xc) = *(int *)(local_30[3] + 0xc) + 1;
      }
      FUN_00408cd0();
      if ((*(int *)(local_30[3] + 0x32b4) != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
        FUN_00407310(*(undefined4 *)(local_30[3] + 0x32b4),0);
      }
      for (local_58 = 0; local_58 < *(int *)(local_30[3] + 0xc); local_58 = local_58 + 1) {
        FUN_00407a80(local_30[3] + 0x32b4);
      }
    }
  }
  if (5 < *(int *)(local_30[3] + 0xc)) {
    FUN_004077e0(&DAT_004282b0);
    if (*(int *)(local_30[3] + 0xc) == 6) {
      *(int *)(local_30[3] + 0xc) = *(int *)(local_30[3] + 0xc) + 1;
    }
    FUN_00408cd0();
    if ((*(int *)(local_30[3] + 0x32b4) != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
      FUN_00407310(*(undefined4 *)(local_30[3] + 0x32b4),0);
    }
    for (local_5c = 0; local_5c < *(int *)(local_30[3] + 0xc); local_5c = local_5c + 1) {
      FUN_00407a80(local_30[3] + 0x32b4);
    }
  }
  *(undefined4 *)(local_30[3] + 0x3304) = 0;
  if (*(int *)(local_30[3] + 0x32b4) == 0) {
LAB_00402e44:
    local_48 = 0;
  }
  else {
    if (*(int *)(local_30[3] + 0x32b4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(local_30[3] + 0x32b4) == 0x400) {
      if ((int)*(short *)(*(int *)(local_30[3] + 0x32b4) + 6) *
          (int)*(short *)(*(int *)(local_30[3] + 0x32b4) + 8) -
          *(int *)(*(int *)(local_30[3] + 0x32b4) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00402e44;
    local_48 = (int)**(short **)(local_30[3] + 0x32b4);
  }
  *(int *)(local_30[3] + 0x32dc) = param_2 - local_48 / 2;
  *(int *)(local_30[3] + 0x3308) = param_2 - local_48 / 2;
  if (*(int *)(local_30[3] + 0x32b4) != 0) {
    if (*(int *)(local_30[3] + 0x32b4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(local_30[3] + 0x32b4) == 0x400) {
      if ((int)*(short *)(*(int *)(local_30[3] + 0x32b4) + 6) *
          (int)*(short *)(*(int *)(local_30[3] + 0x32b4) + 8) -
          *(int *)(*(int *)(local_30[3] + 0x32b4) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_54 = (int)*(short *)(*(int *)(local_30[3] + 0x32b4) + 2);
      goto LAB_00402f5f;
    }
  }
  local_54 = 0;
LAB_00402f5f:
  *(int *)(local_30[3] + 0x32e0) = param_3 - local_54 / 2;
  *(int *)(local_30[3] + 0x330c) = param_3 - local_54 / 2;
  *(undefined4 *)(local_30[3] + 4) = 1;
  *(int *)(local_30[3] + 0x332c) = local_1c + 1;
  *(int *)(param_1 + 4) = local_1c;
  return 1;
}


// ==== FUN_00402fd7 @ 00402fd7

undefined4 __fastcall FUN_00402fd7(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)FUN_004026a9(local_24,0);
  local_1c = *piVar1;
  local_18 = piVar1[1];
  if (local_1c < 0) {
    uVar2 = 0;
  }
  else {
    local_10 = local_1c * 10 + local_18;
    uVar2 = FUN_0040293a();
    *(undefined4 *)(param_1 + 0x24ae40 + local_10 * 4) = uVar2;
    if (*(int *)(param_1 + 0x24ae40 + local_10 * 4) == -1) {
      uVar2 = 0;
    }
    else {
      local_14 = *(int *)(param_1 + 0x24ae40 + local_10 * 4) * 0x3350 + param_1 + 0x10;
      FUN_0040ce1e(DAT_0042bd94);
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      *(undefined4 *)(local_14 + 0x3304) = 0;
      *(undefined4 *)(local_14 + 0x32dc) = 0x122;
      *(undefined4 *)(local_14 + 0x3308) = 0x122;
      *(undefined4 *)(local_14 + 0x32e0) = 0xc3;
      *(undefined4 *)(local_14 + 0x330c) = 0xc3;
      *(undefined4 *)(local_14 + 4) = 1;
      *(int *)(local_14 + 0x332c) = *(int *)(param_1 + 0x24ae40 + local_10 * 4) + 1;
      FUN_00404add(*(int *)(param_1 + 0x24ae40 + local_10 * 4) + 0xc9,
                   *(undefined4 *)(param_1 + 0x24ae40 + local_10 * 4));
      puVar3 = (undefined4 *)FUN_00401c91(local_2c,0,local_10);
      local_c = *puVar3;
      local_8 = puVar3[1];
      FUN_0040db6d(local_c,local_8);
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00403177 @ 00403177

int __thiscall FUN_00403177(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_104;
  int local_f8;
  int aiStack_e8 [51];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_18 = 0; local_18 < 0x33; local_18 = local_18 + 1) {
    if (*(int *)(local_18 * 0x3350 + 0x14 + param_1) != 0) {
      aiStack_e8[local_c] = local_18;
      local_c = local_c + 1;
    }
  }
  for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
    for (local_1c = local_18 + 1; local_1c < local_c; local_1c = local_1c + 1) {
      iVar3 = aiStack_e8[local_18] * 0x3350 + param_1;
      local_14 = iVar3 + 0x10;
      iVar4 = aiStack_e8[local_1c] * 0x3350 + param_1;
      local_10 = iVar4 + 0x10;
      if (*(int *)(iVar3 + 0x18) < *(int *)(iVar4 + 0x18)) {
        local_8 = aiStack_e8[local_18];
        aiStack_e8[local_18] = aiStack_e8[local_1c];
        aiStack_e8[local_1c] = local_8;
      }
    }
  }
  local_18 = 0;
  do {
    if (local_c <= local_18) {
      return -1;
    }
    if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x1c + param_1) == 0) {
      bVar1 = false;
    }
    else {
      iVar3 = param_2 - *(int *)(aiStack_e8[local_18] * 0x3350 + 0x32ec + param_1);
      iVar4 = param_3 - *(int *)(aiStack_e8[local_18] * 0x3350 + 0x32f0 + param_1);
      if (iVar3 < 0) {
LAB_00403771:
        bVar1 = false;
      }
      else {
        if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_0040354c:
          local_f8 = 0;
        }
        else {
          if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 6) *
                (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 8) -
                *(int *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_0040354c;
          local_f8 = (int)**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1);
        }
        if ((local_f8 <= iVar3) || (iVar4 < 0)) goto LAB_00403771;
        if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_00403730:
          local_104 = 0;
        }
        else {
          if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 6) *
                (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 8) -
                *(int *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_00403730;
          local_104 = (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2
                                     );
        }
        if (local_104 <= iVar4) goto LAB_00403771;
        bVar1 = true;
      }
      if (bVar1) {
        cVar2 = FUN_00418f1f(iVar3,iVar4);
        if (cVar2 == '\0') {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) {
      return aiStack_e8[local_18];
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_0040382d @ 0040382d

int __thiscall FUN_0040382d(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_104;
  int local_f8;
  int aiStack_e8 [51];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_18 = 0; local_18 < 0x33; local_18 = local_18 + 1) {
    if (*(int *)(local_18 * 0x3350 + 0x14 + param_1) != 0) {
      aiStack_e8[local_c] = local_18;
      local_c = local_c + 1;
    }
  }
  for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
    for (local_1c = local_18 + 1; local_1c < local_c; local_1c = local_1c + 1) {
      iVar3 = aiStack_e8[local_18] * 0x3350 + param_1;
      local_14 = iVar3 + 0x10;
      iVar4 = aiStack_e8[local_1c] * 0x3350 + param_1;
      local_10 = iVar4 + 0x10;
      if (*(int *)(iVar3 + 0x18) < *(int *)(iVar4 + 0x18)) {
        local_8 = aiStack_e8[local_18];
        aiStack_e8[local_18] = aiStack_e8[local_1c];
        aiStack_e8[local_1c] = local_8;
      }
    }
  }
  local_18 = local_c + -1;
  do {
    if (local_18 < 0) {
      return -1;
    }
    if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x1c + param_1) == 0) {
      bVar1 = false;
    }
    else {
      iVar3 = param_2 - *(int *)(aiStack_e8[local_18] * 0x3350 + 0x32ec + param_1);
      iVar4 = param_3 - *(int *)(aiStack_e8[local_18] * 0x3350 + 0x32f0 + param_1);
      if (iVar3 < 0) {
LAB_00403e25:
        bVar1 = false;
      }
      else {
        if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_00403c00:
          local_f8 = 0;
        }
        else {
          if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 6) *
                (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 8) -
                *(int *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_00403c00;
          local_f8 = (int)**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1);
        }
        if ((local_f8 <= iVar3) || (iVar4 < 0)) goto LAB_00403e25;
        if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_00403de4:
          local_104 = 0;
        }
        else {
          if (*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 6) *
                (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 8) -
                *(int *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_00403de4;
          local_104 = (int)*(short *)(*(int *)(aiStack_e8[local_18] * 0x3350 + 0x32c4 + param_1) + 2
                                     );
        }
        if (local_104 <= iVar4) goto LAB_00403e25;
        bVar1 = true;
      }
      if (bVar1) {
        cVar2 = FUN_00418f1f(iVar3,iVar4);
        if (cVar2 == '\0') {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) {
      return aiStack_e8[local_18];
    }
    local_18 = local_18 + -1;
  } while( true );
}


// ==== FUN_00403ee1 @ 00403ee1

int __thiscall FUN_00403ee1(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_40;
  int local_3c;
  uint local_2c [10];
  
  uVar1 = FUN_0040382d(param_2,param_3);
  *(undefined4 *)(param_1 + 4) = uVar1;
  if (((*(int *)(param_1 + 4) != -1) && (iVar2 = FUN_00401df5(), 0 < iVar2)) && (iVar2 < 7)) {
    iVar3 = FUN_00401d9c(*(undefined4 *)(param_1 + 4));
    if ((iVar2 * 5 + 0xf != iVar3) && (iVar2 * 5 + 0x13 != iVar3)) {
      for (local_3c = -1; local_3c < 2; local_3c = local_3c + 1) {
        if (local_3c + iVar3 < 0) {
          return 0;
        }
        iVar2 = *(int *)(param_1 + 0x24ae40 + (local_3c + iVar3) * 4);
        local_2c[local_3c + 1] = 0;
        for (local_40 = 0; local_40 < 6; local_40 = local_40 + 1) {
          local_2c[local_3c + 1] =
               local_2c[local_3c + 1] |
               *(int *)(iVar2 * 0x3350 + param_1 + 0x3320 + local_40 * 4) <<
               ((char)local_40 * '\x03' & 0x1fU);
        }
      }
      if (((local_2c[1] != local_2c[0]) && (local_2c[2] != local_2c[0])) &&
         (local_2c[1] != local_2c[2])) {
        return iVar3;
      }
      if (((((0x13 < iVar3) && (local_2c[0] != 0xffffffff)) && (local_2c[1] != 0xffffffff)) &&
          ((local_2c[2] != 0xffffffff && (local_2c[0] != 0)))) &&
         ((local_2c[1] != 0 && (local_2c[2] != 0)))) {
        PostMessageA(DAT_0067ffa8,0x111,0x24e,0);
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_004040ad @ 004040ad

void __fastcall FUN_004040ad(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  FUN_00405ca3(0x36);
  switch(DAT_0042bd94) {
  case 1:
    local_10 = 2;
    break;
  case 2:
    local_10 = 3;
    break;
  case 3:
    local_10 = 4;
    break;
  case 4:
    local_10 = 5;
    break;
  case 5:
    local_10 = 6;
    break;
  default:
    local_10 = 6;
    break;
  case 7:
  case 9:
    local_10 = 5;
  }
  iVar1 = param_1 + 0xad2f0;
  *(int *)(param_1 + 0x24b11c) = *(int *)(param_1 + 0x24b11c) + 1;
  if (local_10 <= *(int *)(param_1 + 0x24b11c)) {
    *(undefined4 *)(param_1 + 0x24b11c) = 0;
  }
  FUN_004111c3((&DAT_0043385c)[*(int *)(param_1 + 0x24b11c)],0x51,0x154);
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    if (*(int *)(param_1 + 0xad2fc) != 0) {
      *(int *)(param_1 + 0xad2fc) = *(int *)(param_1 + 0xad2fc) + -1;
      FUN_00408cd0();
      if ((*(int *)(param_1 + 0xb05a4) != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
        FUN_00407310(*(undefined4 *)(param_1 + 0xb05a4),0);
      }
      for (local_14 = 0; local_14 < *(int *)(param_1 + 0xad2fc); local_14 = local_14 + 1) {
        FUN_004189ff(*(undefined4 *)
                      (local_14 * 0x73c + *(int *)(param_1 + 0xad3f8 + local_14 * 0x73c) * 4 + 0x10
                      + iVar1),
                     *(undefined4 *)
                      (local_14 * 0x73c + *(int *)(param_1 + 0xad3f8 + local_14 * 0x73c) * 4 + 0x60
                      + iVar1),
                     *(undefined4 *)
                      (*(int *)(param_1 + 0xad3f8 + local_14 * 0x73c) * 0x50 + local_14 * 0x73c +
                       0x10c + iVar1),*(undefined4 *)(param_1 + 0xb05a4));
      }
    }
  }
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    *(undefined4 *)(param_1 + 0xb0600 + local_c * 4) = *(undefined4 *)(param_1 + 0x24b11c);
    puVar3 = (undefined4 *)(&DAT_00428680 + *(int *)(param_1 + 0x24b11c) * 0x798 + local_c * 0x144);
    if ((local_c <= *(int *)(param_1 + 0xad2fc)) && (puVar3 != (undefined4 *)0x0)) {
      *(undefined4 *)(param_1 + 0xad3f4 + local_c * 0x73c) = *puVar3;
      uVar4 = FUN_00411187(*(undefined4 *)(param_1 + 0xad3f4 + local_c * 0x73c));
      *(undefined4 *)(param_1 + 0xad3f8 + local_c * 0x73c) = uVar4;
      for (local_20 = 0; local_20 < *(int *)(param_1 + 0xad3f4 + local_c * 0x73c);
          local_20 = local_20 + 1) {
        *(undefined4 *)(local_20 * 4 + local_c * 0x73c + 0x10 + iVar1) = puVar3[local_20 * 4 + 1];
        *(undefined4 *)(local_20 * 4 + local_c * 0x73c + 0x60 + iVar1) = puVar3[local_20 * 4 + 2];
        *(undefined4 *)(local_20 * 4 + local_c * 0x73c + 0xb0 + iVar1) = puVar3[local_20 * 4 + 3];
        FUN_00407450();
        *(undefined1 *)(local_20 * 0x50 + local_c * 0x73c + 0x114 + iVar1) = 0;
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x128 + iVar1) = 0;
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 300 + iVar1) = 0;
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x130 + iVar1) = 1;
        FUN_004073f0();
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x134 + iVar1) = 0;
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x138 + iVar1) = 0;
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x10c + iVar1) =
             puVar3[local_20 * 4 + 4];
        *(undefined4 *)(local_20 * 0x50 + local_c * 0x73c + 0x110 + iVar1) = 1;
      }
      *(undefined4 *)(param_1 + 0xad3f0 + local_c * 0x73c) =
           *(undefined4 *)
            (local_c * 0x73c + *(int *)(param_1 + 0xad3f8 + local_c * 0x73c) * 4 + 0xb0 + iVar1);
      if (*(int *)(param_1 + 0xad2fc) == local_c) {
        *(int *)(param_1 + 0xad2fc) = *(int *)(param_1 + 0xad2fc) + 1;
      }
      FUN_00408cd0();
      if ((*(int *)(param_1 + 0xb05a4) != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
        FUN_00407310(*(undefined4 *)(param_1 + 0xb05a4),0);
      }
      for (local_18 = 0; local_18 < *(int *)(param_1 + 0xad2fc); local_18 = local_18 + 1) {
        FUN_004189ff(*(undefined4 *)
                      (local_18 * 0x73c + *(int *)(param_1 + 0xad3f8 + local_18 * 0x73c) * 4 + 0x10
                      + iVar1),
                     *(undefined4 *)
                      (local_18 * 0x73c + *(int *)(param_1 + 0xad3f8 + local_18 * 0x73c) * 4 + 0x60
                      + iVar1),
                     *(undefined4 *)
                      (*(int *)(param_1 + 0xad3f8 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                       0x10c + iVar1),*(undefined4 *)(param_1 + 0xb05a4));
      }
    }
  }
  *(undefined4 *)(param_1 + 0xb05cc) = 0x20;
  *(undefined4 *)(param_1 + 0xb05f8) = 0x20;
  *(undefined4 *)(param_1 + 0xb05d0) = 0x154;
  *(undefined4 *)(param_1 + 0xb05fc) = 0x154;
  *(undefined4 *)(param_1 + 0xad2f4) = 1;
  *(undefined4 *)(param_1 + 0xb061c) = 0;
  *(undefined4 *)(param_1 + 0xad2f8) = 0;
  return;
}


// ==== FUN_00404930 @ 00404930

undefined4 __thiscall FUN_00404930(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  iVar2 = FUN_00403ee1(param_2,param_3);
  if (iVar2 != 0) {
    if (iVar2 < 0x14) {
      *(undefined4 *)(param_1 + 4) = uVar1;
      return 0;
    }
    FUN_00401df5();
    if ((*(int *)(param_1 + 0x24ae3c + iVar2 * 4) != -1) &&
       (*(int *)(param_1 + 0x24ae44 + iVar2 * 4) != -1)) {
      iVar3 = FUN_004029a5(param_2,param_3,iVar2);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 4) = uVar1;
        return 0x22b;
      }
      local_10 = 0;
      for (local_c = -1; local_c < 2; local_c = local_c + 1) {
        if (*(int *)(*(int *)(param_1 + 0x24ae40 + (local_c + iVar2) * 4) * 0x3350 + 0x3314 +
                    param_1) == 2) {
          FUN_00405ca3(*(undefined4 *)(param_1 + 0x24ae40 + (local_c + iVar2) * 4));
          *(undefined4 *)(param_1 + 0x24ae40 + (local_c + iVar2) * 4) = 0xffffffff;
          local_10 = local_10 + 1;
        }
        else {
          FUN_00404f10(*(undefined4 *)(param_1 + 0x24ae40 + (local_c + iVar2) * 4));
        }
      }
      for (local_c = 0; local_c < local_10; local_c = local_c + 1) {
      }
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar1;
  return 0;
}


// ==== FUN_00404add @ 00404add

void __thiscall FUN_00404add(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_f8;
  int aiStack_f4 [55];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _memset(&DAT_0042efe0,0,0xd0);
  *(undefined4 *)(&DAT_0042efe0 + param_3 * 4) = 4;
  DAT_0042f0bc = 0;
  for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
    iVar1 = local_18 * 0x3350 + param_1;
    local_10 = iVar1 + 0x10;
    if ((*(int *)(iVar1 + 0x14) != 0) && (199 < *(int *)(iVar1 + 0x18))) {
      (&DAT_0042ef00)[DAT_0042f0bc] = local_18;
      DAT_0042f0bc = DAT_0042f0bc + 1;
    }
  }
  if (DAT_0042f0bc != 0) {
    for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
      FUN_004055d9(local_18);
    }
  }
  local_c = 0;
  for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
    if (*(int *)(&DAT_0042efe0 + local_18 * 4) != 0) {
      aiStack_f4[local_c] = local_18;
      local_c = local_c + 1;
    }
  }
  for (local_18 = 0; local_f8 = local_18, local_18 < local_c; local_18 = local_18 + 1) {
    while (local_f8 = local_f8 + 1, local_f8 < local_c) {
      iVar1 = aiStack_f4[local_18] * 0x3350 + param_1;
      local_14 = iVar1 + 0x10;
      iVar2 = aiStack_f4[local_f8] * 0x3350 + param_1;
      local_10 = iVar2 + 0x10;
      if (*(int *)(iVar1 + 0x18) < *(int *)(iVar2 + 0x18)) {
        local_8 = aiStack_f4[local_18];
        aiStack_f4[local_18] = aiStack_f4[local_f8];
        aiStack_f4[local_f8] = local_8;
      }
    }
  }
  for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
    FUN_0041b3b9(*(undefined4 *)(aiStack_f4[local_18] * 0x3350 + 0x32c4 + param_1),0,0,0,0);
  }
  *(undefined4 *)(param_3 * 0x3350 + 0x18 + param_1) = param_2;
  for (local_18 = 0; local_f8 = local_18, local_18 < local_c; local_18 = local_18 + 1) {
    while (local_f8 = local_f8 + 1, local_f8 < local_c) {
      iVar1 = aiStack_f4[local_18] * 0x3350 + param_1;
      local_14 = iVar1 + 0x10;
      iVar2 = aiStack_f4[local_f8] * 0x3350 + param_1;
      local_10 = iVar2 + 0x10;
      if (*(int *)(iVar1 + 0x18) < *(int *)(iVar2 + 0x18)) {
        local_8 = aiStack_f4[local_18];
        aiStack_f4[local_18] = aiStack_f4[local_f8];
        aiStack_f4[local_f8] = local_8;
      }
    }
  }
  for (local_18 = local_c + -1; -1 < local_18; local_18 = local_18 + -1) {
    iVar1 = aiStack_f4[local_18] * 0x3350 + param_1;
    local_10 = iVar1 + 0x10;
    if (*(int *)(iVar1 + 0x1c) != 0) {
      FUN_0041993e(1);
    }
  }
  return;
}


// ==== FUN_00404f10 @ 00404f10

void __thiscall FUN_00404f10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_f8;
  int aiStack_f4 [55];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_2 * 0x3350 + 0x3314 + param_1) != 2) {
    _memset(&DAT_0042efe0,0,0xd0);
    *(undefined4 *)(&DAT_0042efe0 + param_2 * 4) = 4;
    DAT_0042f0bc = 0;
    for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
      iVar1 = local_18 * 0x3350 + param_1;
      local_10 = iVar1 + 0x10;
      if ((*(int *)(iVar1 + 0x14) != 0) && (199 < *(int *)(iVar1 + 0x18))) {
        (&DAT_0042ef00)[DAT_0042f0bc] = local_18;
        DAT_0042f0bc = DAT_0042f0bc + 1;
      }
    }
    if (DAT_0042f0bc != 0) {
      for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
        FUN_004055d9(local_18);
      }
    }
    local_c = 0;
    for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_0042efe0 + local_18 * 4) != 0) {
        aiStack_f4[local_c] = local_18;
        local_c = local_c + 1;
      }
    }
    for (local_18 = 0; local_f8 = local_18, local_18 < local_c; local_18 = local_18 + 1) {
      while (local_f8 = local_f8 + 1, local_f8 < local_c) {
        iVar1 = aiStack_f4[local_18] * 0x3350 + param_1;
        local_14 = iVar1 + 0x10;
        iVar2 = aiStack_f4[local_f8] * 0x3350 + param_1;
        local_10 = iVar2 + 0x10;
        if (*(int *)(iVar1 + 0x18) < *(int *)(iVar2 + 0x18)) {
          local_8 = aiStack_f4[local_18];
          aiStack_f4[local_18] = aiStack_f4[local_f8];
          aiStack_f4[local_f8] = local_8;
        }
      }
    }
    for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
      FUN_0041b3b9(*(undefined4 *)(aiStack_f4[local_18] * 0x3350 + 0x32c4 + param_1),0,0,0,0);
    }
    for (local_18 = local_c + -1; -1 < local_18; local_18 = local_18 + -1) {
      iVar1 = aiStack_f4[local_18] * 0x3350 + param_1;
      local_10 = iVar1 + 0x10;
      if (aiStack_f4[local_18] == param_2) {
        if (*(int *)(iVar1 + 0x3314) != 2) {
          *(int *)(iVar1 + 0x3314) = *(int *)(iVar1 + 0x3314) + 1;
        }
        FUN_0040d6e3();
      }
      if (*(int *)(local_10 + 0xc) != 0) {
        FUN_0041993e(1);
      }
    }
  }
  return;
}


// ==== FUN_004052e0 @ 004052e0

char FUN_004052e0(int param_1)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int local_24;
  int local_14;
  
  if (*(int *)(param_1 + 4) == 0) {
    cVar3 = '\0';
  }
  else if (*(int *)(param_1 + 8) < 400) {
    *(int *)(param_1 + 0x334c) = *(int *)(param_1 + 0x334c) + -1;
    if (*(int *)(param_1 + 4) == 0) {
      cVar3 = false;
    }
    else if (*(int *)(param_1 + 0xc) == 0) {
      cVar3 = false;
    }
    else {
      cVar3 = false;
      for (local_24 = 0; local_24 < *(int *)(param_1 + 0xc); local_24 = local_24 + 1) {
        if ((bool)cVar3) {
LAB_0040554b:
          cVar3 = true;
        }
        else {
          if (*(int *)(param_1 + 0x104 + local_24 * 0x73c) < 2) {
            bVar2 = false;
          }
          else {
            piVar1 = (int *)(param_1 + 0x100 + local_24 * 0x73c);
            *piVar1 = *piVar1 + -1;
            if (*(int *)(param_1 + 0x100 + local_24 * 0x73c) == 0) {
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
          }
          if (bVar2) goto LAB_0040554b;
          cVar3 = false;
        }
      }
    }
    if (*(int *)(param_1 + 4) == 0) {
      bVar2 = false;
    }
    else if (*(int *)(param_1 + 0x334c) < 1) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cVar3 = cVar3 + '\x02';
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      bVar2 = false;
    }
    else if (*(int *)(param_1 + 0xc) == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = false;
      for (local_14 = 0; local_14 < *(int *)(param_1 + 0xc); local_14 = local_14 + 1) {
        if (bVar2) {
LAB_00405410:
          bVar2 = true;
        }
        else {
          if (*(int *)(param_1 + 0x104 + local_14 * 0x73c) < 2) {
            bVar2 = false;
          }
          else {
            piVar1 = (int *)(param_1 + 0x100 + local_14 * 0x73c);
            *piVar1 = *piVar1 + -1;
            if (*(int *)(param_1 + 0x100 + local_14 * 0x73c) == 0) {
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
          }
          if (bVar2) goto LAB_00405410;
          bVar2 = false;
        }
      }
    }
    if (bVar2) {
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\0';
    }
  }
  return cVar3;
}


// ==== FUN_004055d9 @ 004055d9

void __thiscall FUN_004055d9(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_84;
  int local_78;
  int local_70;
  int local_64;
  undefined1 local_58 [16];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(&DAT_0042efe0 + param_2 * 4) != 0) {
    for (local_8 = 0; local_8 < DAT_0042f0bc; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_0042efe0 + (&DAT_0042ef00)[local_8] * 4) == 0) {
        if (*(int *)(param_2 * 0x3350 + 0x1c + param_1) == 0) {
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
        }
        else {
          local_18 = *(int *)(param_2 * 0x3350 + 0x32ec + param_1);
          local_14 = *(int *)(param_2 * 0x3350 + 0x32f0 + param_1);
          if (*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_0040581e:
            local_64 = 0;
          }
          else {
            if (*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) == 0) {
              bVar1 = false;
            }
            else if (**(short **)(param_2 * 0x3350 + 0x32c4 + param_1) == 0x400) {
              if ((int)*(short *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 6) *
                  (int)*(short *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 8) -
                  *(int *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
            if (bVar1) goto LAB_0040581e;
            local_64 = (int)**(short **)(param_2 * 0x3350 + 0x32c4 + param_1);
          }
          local_10 = local_18 + local_64 + -1;
          if (*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) == 0) {
LAB_004059a1:
            local_70 = 0;
          }
          else {
            if (*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) == 0) {
              bVar1 = false;
            }
            else if (**(short **)(param_2 * 0x3350 + 0x32c4 + param_1) == 0x400) {
              if ((int)*(short *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 6) *
                  (int)*(short *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 8) -
                  *(int *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 2) == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
            if (bVar1) goto LAB_004059a1;
            local_70 = (int)*(short *)(*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) + 2);
          }
          local_c = local_14 + local_70 + -1;
        }
        if (((&DAT_0042efe0)[param_2 * 4] & 2) != 0) {
          puVar2 = (undefined4 *)FUN_00409a60(local_58);
          local_38 = *puVar2;
          local_34 = puVar2[1];
          local_30 = puVar2[2];
          local_2c = puVar2[3];
          FUN_0041863c(&local_48,&local_18,&local_38);
          local_18 = local_48;
          local_14 = local_44;
          local_10 = local_40;
          local_c = local_3c;
        }
        iVar3 = (&DAT_0042ef00)[local_8] * 0x3350 + param_1;
        if (*(int *)(iVar3 + 0x1c) == 0) {
          local_28 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
        }
        else {
          local_28 = *(int *)(iVar3 + 0x32ec);
          local_24 = *(int *)(iVar3 + 0x32f0);
          if ((*(int *)(iVar3 + 0x32c4) == 0) || (iVar4 = FUN_00407370(), iVar4 != 0)) {
            local_78 = 0;
          }
          else {
            local_78 = (int)**(short **)(iVar3 + 0x32c4);
          }
          local_20 = local_28 + local_78 + -1;
          if (*(int *)(iVar3 + 0x32c4) == 0) {
LAB_00405c08:
            local_84 = 0;
          }
          else {
            if (*(int *)(iVar3 + 0x32c4) == 0) {
              bVar1 = false;
            }
            else if (**(short **)(iVar3 + 0x32c4) == 0x400) {
              if ((int)*(short *)(*(int *)(iVar3 + 0x32c4) + 6) *
                  (int)*(short *)(*(int *)(iVar3 + 0x32c4) + 8) -
                  *(int *)(*(int *)(iVar3 + 0x32c4) + 2) == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
            if (bVar1) goto LAB_00405c08;
            local_84 = (int)*(short *)(*(int *)(iVar3 + 0x32c4) + 2);
          }
          local_1c = local_24 + local_84 + -1;
        }
        iVar3 = FUN_004185a3(&local_18,&local_28);
        if (iVar3 != 0) {
          *(undefined4 *)(&DAT_0042efe0 + (&DAT_0042ef00)[local_8] * 4) = 4;
          FUN_004055d9((&DAT_0042ef00)[local_8]);
        }
      }
    }
  }
  return;
}


// ==== FUN_00405ca3 @ 00405ca3

undefined4 __thiscall FUN_00405ca3(int param_1,int param_2)

{
  int *piVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int local_fc;
  int local_f8;
  int aiStack_f4 [55];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _memset(&DAT_0042efe0,0,0xd0);
  *(undefined4 *)(&DAT_0042efe0 + param_2 * 4) = 4;
  DAT_0042f0bc = 0;
  for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
    iVar3 = local_18 * 0x3350 + param_1;
    local_10 = iVar3 + 0x10;
    if ((*(int *)(iVar3 + 0x14) != 0) && (199 < *(int *)(iVar3 + 0x18))) {
      (&DAT_0042ef00)[DAT_0042f0bc] = local_18;
      DAT_0042f0bc = DAT_0042f0bc + 1;
    }
  }
  if (DAT_0042f0bc != 0) {
    for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
      FUN_004055d9(local_18);
    }
  }
  local_c = 0;
  for (local_18 = 0; local_18 < 0x37; local_18 = local_18 + 1) {
    if (*(int *)(&DAT_0042efe0 + local_18 * 4) != 0) {
      aiStack_f4[local_c] = local_18;
      local_c = local_c + 1;
    }
  }
  for (local_18 = 0; local_f8 = local_18, local_18 < local_c; local_18 = local_18 + 1) {
    while (local_f8 = local_f8 + 1, local_f8 < local_c) {
      iVar3 = aiStack_f4[local_18] * 0x3350 + param_1;
      local_14 = iVar3 + 0x10;
      iVar4 = aiStack_f4[local_f8] * 0x3350 + param_1;
      local_10 = iVar4 + 0x10;
      if (*(int *)(iVar3 + 0x18) < *(int *)(iVar4 + 0x18)) {
        local_8 = aiStack_f4[local_18];
        aiStack_f4[local_18] = aiStack_f4[local_f8];
        aiStack_f4[local_f8] = local_8;
      }
    }
  }
  for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
    FUN_0041b3b9(*(undefined4 *)(aiStack_f4[local_18] * 0x3350 + 0x32c4 + param_1),0,0,0,0);
  }
  for (local_18 = local_c + -1; -1 < local_18; local_18 = local_18 + -1) {
    if (aiStack_f4[local_18] == param_2) {
      *(undefined4 *)(param_2 * 0x3350 + 0x14 + param_1) = 0;
      while (*(int *)(param_2 * 0x3350 + 0x1c + param_1) != 0) {
        if (*(int *)(param_2 * 0x3350 + 0x1c + param_1) != 0) {
          piVar1 = (int *)(param_2 * 0x3350 + 0x1c + param_1);
          *piVar1 = *piVar1 + -1;
          FUN_00408cd0();
          if (((*(int *)(param_2 * 0x3350 + 0x32c4 + param_1) != 0) &&
              (iVar3 = FUN_00407370(), iVar3 == 0)) &&
             (psVar2 = *(short **)(param_2 * 0x3350 + 0x32c4 + param_1), psVar2 != (short *)0x0)) {
            _memset(psVar2 + 2,0,(int)psVar2[1] * (int)*psVar2);
          }
          for (local_fc = 0; local_fc < *(int *)(param_2 * 0x3350 + 0x1c + param_1);
              local_fc = local_fc + 1) {
            FUN_004189ff(*(undefined4 *)
                          (param_2 * 0x3350 +
                           *(int *)(param_2 * 0x3350 + local_fc * 0x73c + 0x118 + param_1) * 4 +
                           local_fc * 0x73c + 0x20 + param_1),
                         *(undefined4 *)
                          (param_2 * 0x3350 +
                           *(int *)(param_2 * 0x3350 + local_fc * 0x73c + 0x118 + param_1) * 4 +
                           local_fc * 0x73c + 0x70 + param_1),
                         *(undefined4 *)
                          (*(int *)(param_2 * 0x3350 + local_fc * 0x73c + 0x118 + param_1) * 0x50 +
                           param_2 * 0x3350 + local_fc * 0x73c + 0x11c + param_1),
                         *(undefined4 *)(param_2 * 0x3350 + 0x32c4 + param_1));
          }
        }
      }
    }
    else {
      iVar3 = aiStack_f4[local_18] * 0x3350 + param_1;
      local_10 = iVar3 + 0x10;
      if (*(int *)(iVar3 + 0x1c) != 0) {
        FUN_0041993e(1);
      }
    }
  }
  return 1;
}


// ==== FUN_0040637b @ 0040637b

void __thiscall FUN_0040637b(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  FUN_0041b3b9(*(undefined4 *)(*(int *)(param_1 + 4) * 0x3350 + param_1 + 0x32c4),0,0,0,0);
  iVar1 = *(int *)(param_1 + 4) * 0x3350 + param_1;
  *(undefined4 *)(iVar1 + 0x32ec) = param_2;
  *(undefined4 *)(iVar1 + 0x3318) = param_2;
  iVar1 = *(int *)(param_1 + 4) * 0x3350 + param_1;
  *(undefined4 *)(iVar1 + 0x32f0) = param_3;
  *(undefined4 *)(iVar1 + 0x331c) = param_3;
  if (*(int *)(*(int *)(param_1 + 4) * 0x3350 + param_1 + 0x1c) != 0) {
    FUN_0041993e(1);
  }
  return;
}


// ==== FUN_004064ad @ 004064ad

undefined4 __fastcall FUN_004064ad(int param_1)

{
  int *piVar1;
  int iVar2;
  CPropertySheet *pCVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  CPropertySheet *pCVar7;
  uint local_158;
  undefined1 local_140 [4];
  undefined1 *local_13c;
  undefined1 local_138 [4];
  undefined1 *local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int aiStack_fc [55];
  uint local_20;
  CPropertySheet *local_1c;
  int local_18;
  CPropertySheet *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_20 = 0;
  local_8 = 0;
  pCVar7 = (CPropertySheet *)0xd0;
  _memset(&DAT_0042efe0,0,0xd0);
  DAT_0042f0bc = 0;
  for (local_1c = (CPropertySheet *)0x0; (int)local_1c < 0x37;
      local_1c = (CPropertySheet *)((int)local_1c + 1)) {
    iVar2 = (int)local_1c * 0x3350 + param_1;
    pCVar3 = (CPropertySheet *)(iVar2 + 0x10);
    local_14 = pCVar3;
    if (*(int *)(iVar2 + 0x14) != 0) {
      if (199 < *(int *)(iVar2 + 0x18)) {
        (&DAT_0042ef00)[DAT_0042f0bc] = local_1c;
        DAT_0042f0bc = DAT_0042f0bc + 1;
      }
      local_c = FUN_004052e0();
      pCVar7 = pCVar3;
      if (local_c != 0) {
        *(int *)(&DAT_0042efe0 + (int)local_1c * 4) = local_c;
        local_8 = 1;
      }
    }
  }
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    if (DAT_0042f0bc != 0) {
      for (local_1c = (CPropertySheet *)0x0; (int)local_1c < 0x37; local_1c = local_1c + 1) {
        pCVar7 = local_1c;
        FUN_004055d9();
      }
    }
    local_10 = 0;
    for (local_1c = (CPropertySheet *)0x0; (int)local_1c < 0x37;
        local_1c = (CPropertySheet *)((int)local_1c + 1)) {
      if (*(int *)(&DAT_0042efe0 + (int)local_1c * 4) != 0) {
        aiStack_fc[local_10] = (int)local_1c;
        local_10 = local_10 + 1;
      }
    }
    for (local_1c = (CPropertySheet *)0x0; pCVar3 = local_1c, (int)local_1c < local_10;
        local_1c = (CPropertySheet *)((int)local_1c + 1)) {
      while (local_100 = (int)pCVar3 + 1, local_100 < local_10) {
        iVar2 = aiStack_fc[(int)local_1c] * 0x3350 + param_1;
        local_18 = iVar2 + 0x10;
        iVar5 = aiStack_fc[local_100] * 0x3350 + param_1;
        local_14 = (CPropertySheet *)(iVar5 + 0x10);
        pCVar3 = (CPropertySheet *)local_100;
        if (*(int *)(iVar2 + 0x18) < *(int *)(iVar5 + 0x18)) {
          local_c = aiStack_fc[(int)local_1c];
          aiStack_fc[(int)local_1c] = aiStack_fc[local_100];
          aiStack_fc[local_100] = local_c;
        }
      }
    }
    for (local_1c = (CPropertySheet *)0x0; (int)local_1c < local_10;
        local_1c = (CPropertySheet *)((int)local_1c + 1)) {
      pCVar7 = (CPropertySheet *)0x0;
      FUN_0041b3b9(*(undefined4 *)(aiStack_fc[(int)local_1c] * 0x3350 + 0x32c4 + param_1),0,0,0);
    }
    for (local_1c = (CPropertySheet *)0x0; (int)local_1c < local_10;
        local_1c = (CPropertySheet *)((int)local_1c + 1)) {
      iVar2 = aiStack_fc[(int)local_1c] * 0x3350 + param_1;
      local_14 = (CPropertySheet *)(iVar2 + 0x10);
      local_c = *(int *)(&DAT_0042efe0 + aiStack_fc[(int)local_1c] * 4);
      if (local_c == 1) {
        if ((*(int *)(iVar2 + 0x14) != 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
          local_104 = 0;
          for (local_108 = 0; local_108 < *(int *)(iVar2 + 0x1c); local_108 = local_108 + 1) {
            if (local_104 == 0) {
              if (*(int *)(iVar2 + 0x114 + local_108 * 0x73c) < 2) {
                local_110 = 0;
              }
              else if (*(int *)(iVar2 + 0x110 + local_108 * 0x73c) == 0) {
                piVar1 = (int *)(iVar2 + 0x118 + local_108 * 0x73c);
                *piVar1 = *piVar1 + 1;
                if (*(int *)(iVar2 + 0x114 + local_108 * 0x73c) <=
                    *(int *)(iVar2 + 0x118 + local_108 * 0x73c)) {
                  *(undefined4 *)(iVar2 + 0x118 + local_108 * 0x73c) = 0;
                }
                *(undefined4 *)(iVar2 + 0x110 + local_108 * 0x73c) =
                     *(undefined4 *)
                      (local_14 +
                      local_108 * 0x73c + *(int *)(iVar2 + 0x118 + local_108 * 0x73c) * 4 + 0xb0);
                local_110 = 1;
              }
              else {
                local_110 = 0;
              }
              if (local_110 != 0) goto LAB_004069d6;
              local_104 = 0;
            }
            else {
LAB_004069d6:
              local_104 = 1;
            }
          }
          if (local_104 != 0) {
            pCVar7 = (CPropertySheet *)0x406a09;
            FUN_00408cd0();
            if (*(int *)(local_14 + 0x32b4) != 0) {
              pCVar7 = (CPropertySheet *)0x406a27;
              iVar2 = FUN_00407370();
              if (iVar2 == 0) {
                pCVar7 = (CPropertySheet *)0x0;
                FUN_00407310(*(int *)(local_14 + 0x32b4));
              }
            }
            for (local_10c = 0; local_10c < *(int *)(local_14 + 0xc); local_10c = local_10c + 1) {
              pCVar7 = local_14 + 0x32b4;
              FUN_00407a80();
            }
          }
        }
      }
      else if (local_c == 2) {
        if (*(int *)(iVar2 + 0x14) == 0) {
          local_158 = 0;
        }
        else if (*(int *)(iVar2 + 0x18) < 400) {
          if (*(int *)(iVar2 + 0x18) < 200) {
            if (*(int *)local_14 < 0x33) {
              if (*(int *)(iVar2 + 0x335c) < 1) {
                *(undefined4 *)(iVar2 + 0x335c) = 10;
                local_124 = *(int *)(iVar2 + 0x32ec);
                local_128 = *(int *)(iVar2 + 0x32f0);
                local_12c = FUN_00411187();
                local_12c = local_12c + -1;
                pCVar7 = (CPropertySheet *)0x3;
                local_130 = FUN_00411187();
                local_130 = local_130 + -1;
                if (((local_12c + local_124) - *(int *)(local_14 + 0x3308) < 4) &&
                   (local_12c + local_124 != *(int *)(local_14 + 0x3308) &&
                    -1 < (local_12c + local_124) - *(int *)(local_14 + 0x3308))) {
                  pCVar7 = (CPropertySheet *)0x0;
                  FUN_00408c50(local_12c + local_124);
                }
                if (((local_130 + local_128) - *(int *)(local_14 + 0x330c) < 4) &&
                   (local_130 + local_128 != *(int *)(local_14 + 0x330c) &&
                    -1 < (local_130 + local_128) - *(int *)(local_14 + 0x330c))) {
                  pCVar7 = (CPropertySheet *)0x0;
                  FUN_00408c90(local_130 + local_128);
                }
              }
              local_158 = 0;
            }
            else {
              local_158 = 0;
            }
          }
          else {
            if (*(int *)(iVar2 + 0x335c) < 1) {
              *(undefined4 *)(iVar2 + 0x335c) = 1;
              if (*(int *)(iVar2 + 0x3358) < 1) {
                *(undefined4 *)(iVar2 + 0x32ec) = *(undefined4 *)(iVar2 + 0x3340);
                *(undefined4 *)(iVar2 + 0x3318) = *(undefined4 *)(iVar2 + 0x3340);
                *(undefined4 *)(iVar2 + 0x32f0) = *(undefined4 *)(iVar2 + 0x3344);
                *(undefined4 *)(iVar2 + 0x331c) = *(undefined4 *)(iVar2 + 0x3344);
                *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + 0x333c);
                local_158 = 1;
                goto LAB_00406e09;
              }
              *(int *)(iVar2 + 0x3358) = *(int *)(iVar2 + 0x3358) + -1;
              local_134 = &stack0xfffffe90;
              iVar2 = iVar2 + 0x3348;
              uVar4 = FUN_00408bf0(local_138);
              FUN_004077a0(local_134,uVar4,iVar2);
              CPropertySheet::EnableStackedTabs(local_14,(int)pCVar7);
              local_13c = &stack0xfffffe90;
              pCVar3 = local_14 + 0x333c;
              uVar4 = FUN_00408c20(local_140);
              FUN_004077a0(local_13c,uVar4,pCVar3);
              CPropertySheet::EnableStackedTabs(local_14,(int)pCVar7);
              FUN_00408c50(*(int *)(local_14 + 0x3340) >> 0x10);
              pCVar7 = (CPropertySheet *)0x1;
              FUN_00408c90(*(int *)(local_14 + 0x3344) >> 0x10);
            }
            local_158 = 0;
          }
        }
        else {
          local_158 = 0;
        }
LAB_00406e09:
        local_20 = local_20 | local_158;
      }
      else if (local_c == 3) {
        if ((*(int *)(iVar2 + 0x14) != 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
          local_114 = 0;
          for (local_118 = 0; local_118 < *(int *)(iVar2 + 0x1c); local_118 = local_118 + 1) {
            if (local_114 == 0) {
              if (*(int *)(iVar2 + 0x114 + local_118 * 0x73c) < 2) {
                local_120 = 0;
              }
              else if (*(int *)(iVar2 + 0x110 + local_118 * 0x73c) == 0) {
                piVar1 = (int *)(iVar2 + 0x118 + local_118 * 0x73c);
                *piVar1 = *piVar1 + 1;
                if (*(int *)(iVar2 + 0x114 + local_118 * 0x73c) <=
                    *(int *)(iVar2 + 0x118 + local_118 * 0x73c)) {
                  *(undefined4 *)(iVar2 + 0x118 + local_118 * 0x73c) = 0;
                }
                *(undefined4 *)(iVar2 + 0x110 + local_118 * 0x73c) =
                     *(undefined4 *)
                      (local_14 +
                      local_118 * 0x73c + *(int *)(iVar2 + 0x118 + local_118 * 0x73c) * 4 + 0xb0);
                local_120 = 1;
              }
              else {
                local_120 = 0;
              }
              if (local_120 != 0) goto LAB_00406ff0;
              local_114 = 0;
            }
            else {
LAB_00406ff0:
              local_114 = 1;
            }
          }
          if (local_114 != 0) {
            FUN_00408cd0();
            if ((*(int *)(local_14 + 0x32b4) != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
              FUN_00407310(*(int *)(local_14 + 0x32b4));
            }
            for (local_11c = 0; local_11c < *(int *)(local_14 + 0xc); local_11c = local_11c + 1) {
              FUN_00407a80();
            }
          }
        }
        pCVar7 = (CPropertySheet *)0x4070d0;
        uVar6 = FUN_00409f40();
        local_20 = local_20 | uVar6;
      }
    }
    if (local_20 != 0) {
      for (local_1c = (CPropertySheet *)0x0; pCVar7 = local_1c, (int)local_1c < local_10;
          local_1c = (CPropertySheet *)((int)local_1c + 1)) {
        while (local_100 = (int)pCVar7 + 1, local_100 < local_10) {
          iVar2 = aiStack_fc[(int)local_1c] * 0x3350 + param_1;
          local_18 = iVar2 + 0x10;
          iVar5 = aiStack_fc[local_100] * 0x3350 + param_1;
          local_14 = (CPropertySheet *)(iVar5 + 0x10);
          pCVar7 = (CPropertySheet *)local_100;
          if (*(int *)(iVar2 + 0x18) < *(int *)(iVar5 + 0x18)) {
            local_c = aiStack_fc[(int)local_1c];
            aiStack_fc[(int)local_1c] = aiStack_fc[local_100];
            aiStack_fc[local_100] = local_c;
          }
        }
      }
    }
    for (local_1c = (CPropertySheet *)(local_10 + -1); -1 < (int)local_1c;
        local_1c = (CPropertySheet *)((int)local_1c + -1)) {
      iVar2 = aiStack_fc[(int)local_1c] * 0x3350 + param_1;
      local_14 = (CPropertySheet *)(iVar2 + 0x10);
      if (*(int *)(iVar2 + 0x1c) != 0) {
        FUN_0041993e();
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_00407280 @ 00407280

void FUN_00407280(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004072f3;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  FUN_004072cb();
  local_8 = 0xffffffff;
  FUN_004072da();
  FUN_004072fd();
  return;
}


// ==== FUN_004072cb @ 004072cb

void FUN_004072cb(void)

{
  FUN_004074b0();
  return;
}


// ==== FUN_004072da @ 004072da

void FUN_004072da(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x10) + 0x10),0x73c,7,FUN_0040a280)
  ;
  return;
}


// ==== FUN_004072fd @ 004072fd

void FUN_004072fd(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00407310 @ 00407310

void FUN_00407310(short *param_1,char param_2)

{
  if (param_1 != (short *)0x0) {
    _memset(param_1 + 2,(int)param_2,(int)param_1[1] * (int)*param_1);
  }
  return;
}


// ==== FUN_00407370 @ 00407370

undefined4 __fastcall FUN_00407370(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else if (*(short *)*param_1 == 0x400) {
    if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) == 0)
    {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_004073f0 @ 004073f0

void __fastcall FUN_004073f0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00407450 @ 00407450

void __fastcall FUN_00407450(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  return;
}


// ==== FUN_004074b0 @ 004074b0

void __fastcall FUN_004074b0(int *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_004075df;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 1;
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  if (param_1[0x10] != 0) {
    FUN_00422290(param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_004075ca();
  local_8 = 0xffffffff;
  FUN_004075d6();
  FUN_004075e9();
  return;
}


// ==== FUN_004075ca @ 004075ca

void FUN_004075ca(void)

{
  FUN_00407600();
  return;
}


// ==== FUN_004075d6 @ 004075d6

void FUN_004075d6(void)

{
  FUN_00407670();
  return;
}


// ==== FUN_004075e9 @ 004075e9

void FUN_004075e9(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00407600 @ 00407600

void __fastcall FUN_00407600(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00407670 @ 00407670

void __fastcall FUN_00407670(int *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00407722;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  local_8 = 0xffffffff;
  FUN_00407719();
  FUN_0040772c();
  return;
}


// ==== FUN_00407719 @ 00407719

void FUN_00407719(void)

{
  FUN_00407740();
  return;
}


// ==== FUN_0040772c @ 0040772c

void FUN_0040772c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00407740 @ 00407740

void __fastcall FUN_00407740(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  return;
}


// ==== FUN_004077a0 @ 004077a0

int * FUN_004077a0(int *param_1,int *param_2,int *param_3)

{
  *param_1 = *param_3 + *param_2;
  return param_1;
}


// ==== FUN_004077e0 @ 004077e0

void __thiscall FUN_004077e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int local_c;
  
  *(undefined4 *)(param_1 + 0xf4) = *param_2;
  uVar1 = FUN_00411187(*(undefined4 *)(param_1 + 0xf4));
  *(undefined4 *)(param_1 + 0xf8) = uVar1;
  for (local_c = 0; local_c < *(int *)(param_1 + 0xf4); local_c = local_c + 1) {
    *(undefined4 *)(param_1 + local_c * 4) = param_2[local_c * 4 + 1];
    *(undefined4 *)(param_1 + 0x50 + local_c * 4) = param_2[local_c * 4 + 2];
    *(undefined4 *)(param_1 + 0xa0 + local_c * 4) = param_2[local_c * 4 + 3];
    if ((*(int *)(local_c * 0x50 + 0xfc + param_1) != 0) &&
       (*(int *)(local_c * 0x50 + 0x100 + param_1) == 0)) {
      FUN_00422290(*(undefined4 *)(local_c * 0x50 + 0xfc + param_1));
    }
    *(undefined4 *)(local_c * 0x50 + 0xfc + param_1) = 0;
    *(undefined1 *)(local_c * 0x50 + 0x104 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x118 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x11c + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x120 + param_1) = 1;
    if (*(int *)(local_c * 0x50 + 0x13c + param_1) != 0) {
      FUN_00422290(*(undefined4 *)(local_c * 0x50 + 0x13c + param_1));
    }
    *(undefined4 *)(local_c * 0x50 + 0x13c + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x144 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x148 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x124 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0x128 + param_1) = 0;
    *(undefined4 *)(local_c * 0x50 + 0xfc + param_1) = param_2[local_c * 4 + 4];
    *(undefined4 *)(local_c * 0x50 + 0x100 + param_1) = 1;
  }
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xa0 + *(int *)(param_1 + 0xf8) * 4);
  return;
}


// ==== FUN_00407a80 @ 00407a80

void __thiscall FUN_00407a80(int param_1,undefined4 *param_2)

{
  FUN_004189ff(*(undefined4 *)(param_1 + *(int *)(param_1 + 0xf8) * 4),
               *(undefined4 *)(param_1 + 0x50 + *(int *)(param_1 + 0xf8) * 4),
               *(undefined4 *)(*(int *)(param_1 + 0xf8) * 0x50 + 0xfc + param_1),*param_2);
  return;
}


// ==== FUN_00407af0 @ 00407af0

int __fastcall FUN_00407af0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00408246;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0x10),0x73c,7,FUN_004088e0,FUN_0040a280);
  *(undefined4 *)(param_1 + 0x32b4) = 0;
  *(undefined4 *)(param_1 + 0x32b8) = 0;
  *(undefined1 *)(param_1 + 0x32bc) = 0;
  *(undefined4 *)(param_1 + 0x32d0) = 0;
  *(undefined4 *)(param_1 + 0x32d4) = 0;
  *(undefined4 *)(param_1 + 0x32d8) = 1;
  local_24 = param_1 + 0x32b4;
  local_8._1_3_ = 0;
  *(undefined4 *)(param_1 + 0x32f4) = 0;
  *(undefined4 *)(param_1 + 0x32f8) = 0;
  *(undefined4 *)(param_1 + 0x32fc) = 0;
  *(undefined4 *)(param_1 + 0x3300) = 0;
  local_8._0_1_ = 3;
  FUN_00407450();
  *(undefined1 *)(param_1 + 0x32bc) = 0;
  *(undefined4 *)(param_1 + 0x32d0) = 0;
  *(undefined4 *)(param_1 + 0x32d4) = 0;
  *(undefined4 *)(param_1 + 0x32d8) = 1;
  FUN_004073f0();
  *(undefined4 *)(param_1 + 0x32dc) = 0;
  *(undefined4 *)(param_1 + 0x32e0) = 0;
  *(undefined4 *)(param_1 + 0x32dc) = 0;
  *(undefined4 *)(param_1 + 0x32e0) = 0;
  *(undefined4 *)(param_1 + 0x32f0) = 0;
  *(undefined4 *)(param_1 + 0x32ec) = *(undefined4 *)(param_1 + 0x32f0);
  *(undefined4 *)(param_1 + 0x32e8) = *(undefined4 *)(param_1 + 0x32ec);
  *(undefined4 *)(param_1 + 0x32e4) = *(undefined4 *)(param_1 + 0x32e8);
  local_28 = param_1 + 0x32b4;
  local_8 = CONCAT31(local_8._1_3_,4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_00408800();
  }
  else {
    for (local_3c = 0; local_3c < *(int *)(param_1 + 0xc); local_3c = local_3c + 1) {
      if (local_3c == 0) {
        local_38 = *(int *)(param_1 + 0x32dc);
        iVar1 = FUN_00408680();
        local_30 = *(int *)(param_1 + 0x10 + *(int *)(param_1 + 0x108) * 4) + iVar1 + local_38 + -1;
        local_34 = *(int *)(param_1 + 0x32e0);
        iVar1 = FUN_00408740();
        local_2c = *(int *)(param_1 + 0x60 + *(int *)(param_1 + 0x108) * 4) + iVar1 + local_34 + -1;
      }
      else {
        iVar1 = FUN_00408680();
        if (local_30 <=
            *(int *)(local_3c * 0x73c + *(int *)(param_1 + 0x108 + local_3c * 0x73c) * 4 + 0x10 +
                    param_1) + iVar1 + *(int *)(param_1 + 0x32dc) + -1) {
          iVar1 = FUN_00408680();
          local_30 = *(int *)(local_3c * 0x73c + *(int *)(param_1 + 0x108 + local_3c * 0x73c) * 4 +
                              0x10 + param_1) + iVar1 + *(int *)(param_1 + 0x32dc) + -1;
        }
        iVar1 = FUN_00408740();
        if (local_2c <=
            *(int *)(local_3c * 0x73c + *(int *)(param_1 + 0x108 + local_3c * 0x73c) * 4 + 0x60 +
                    param_1) + iVar1 + *(int *)(param_1 + 0x32e0) + -1) {
          iVar1 = FUN_00408740();
          local_2c = *(int *)(local_3c * 0x73c + *(int *)(param_1 + 0x108 + local_3c * 0x73c) * 4 +
                              0x60 + param_1) + iVar1 + *(int *)(param_1 + 0x32e0) + -1;
        }
      }
    }
    uVar2 = FUN_0041877b(&local_38);
    uVar3 = FUN_0041876b(&local_38,uVar2);
    FUN_00408260(uVar3,uVar2);
  }
  if ((*(int *)(param_1 + 0x32b4) != 0) && (*(int *)(param_1 + 0x32b8) == 0)) {
    local_18 = *(undefined4 *)(param_1 + 0x32b4);
    local_14 = local_18;
    FUN_00422290(local_18);
  }
  *(undefined4 *)(param_1 + 0x32b4) = 0;
  *(undefined1 *)(param_1 + 0x32bc) = 0;
  *(undefined4 *)(param_1 + 0x32d0) = 0;
  *(undefined4 *)(param_1 + 0x32d4) = 0;
  *(undefined4 *)(param_1 + 0x32d8) = 1;
  if (*(int *)(param_1 + 0x32f4) != 0) {
    local_20 = *(undefined4 *)(param_1 + 0x32f4);
    local_1c = local_20;
    FUN_00422290(local_20);
  }
  *(undefined4 *)(param_1 + 0x32f4) = 0;
  *(undefined4 *)(param_1 + 0x32fc) = 0;
  *(undefined4 *)(param_1 + 0x3300) = 0;
  *(undefined4 *)(param_1 + 0x32dc) = 0;
  *(undefined4 *)(param_1 + 0x32e0) = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_00408260 @ 00408260

undefined4 __thiscall FUN_00408260(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined2 uVar2;
  void *pvVar4;
  int local_2c;
  int local_1c;
  int local_14;
  undefined2 uVar3;
  
  param_1[1] = 0;
  uVar2 = (undefined2)param_2;
  uVar3 = (undefined2)param_3;
  if (*param_1 == 0) {
    pvVar4 = operator_new(param_3 * param_2 + 4);
    *param_1 = (int)pvVar4;
    if (*param_1 == 0) {
      return 0;
    }
    *(undefined2 *)*param_1 = uVar2;
    *(undefined2 *)(*param_1 + 2) = uVar3;
    _memset((void *)(*param_1 + 4),0,param_3 * param_2);
    return 1;
  }
  if (*param_1 == 0) {
LAB_0040831f:
    local_14 = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040831f;
    local_14 = (int)*(short *)*param_1;
  }
  if (*param_1 == 0) {
LAB_004083d9:
    if (0 < param_3 * param_2) {
LAB_00408403:
      FUN_00422290(*param_1);
      pvVar4 = operator_new(param_3 * param_2 + 4);
      *param_1 = (int)pvVar4;
      if (*param_1 == 0) {
        return 0;
      }
      *(undefined2 *)*param_1 = uVar2;
      *(undefined2 *)(*param_1 + 2) = uVar3;
    }
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_004083d9;
    if (*(short *)(*param_1 + 2) * local_14 < param_3 * param_2) goto LAB_00408403;
  }
  if (*param_1 == 0) {
LAB_00408506:
    local_1c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00408506;
    local_1c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_2c = (int)*(short *)(*param_1 + 2);
      goto LAB_004085bc;
    }
  }
  local_2c = 0;
LAB_004085bc:
  _memset((void *)(*param_1 + 4),0,local_1c * local_2c);
  *(undefined2 *)*param_1 = uVar2;
  *(undefined2 *)(*param_1 + 2) = uVar3;
  return 1;
}


// ==== FUN_00408680 @ 00408680

int __fastcall FUN_00408680(int *param_1)

{
  bool bVar1;
  
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      return (int)*(short *)*param_1;
    }
  }
  return 0;
}


// ==== FUN_00408740 @ 00408740

int __fastcall FUN_00408740(int *param_1)

{
  bool bVar1;
  
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      return (int)*(short *)(*param_1 + 2);
    }
  }
  return 0;
}


// ==== FUN_00408800 @ 00408800

void __fastcall FUN_00408800(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  if (param_1[0x10] != 0) {
    FUN_00422290(param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


// ==== FUN_004088e0 @ 004088e0

int __fastcall FUN_004088e0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040895d;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0xfc),0x50,0x14,FUN_00408980,FUN_004074b0);
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_00408980 @ 00408980

int * __fastcall FUN_00408980(int *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00408b77;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  local_8 = 2;
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  if (param_1[0x10] != 0) {
    FUN_00422290(param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xf] = 0;
  param_1[0xe] = param_1[0xf];
  param_1[0xd] = param_1[0xe];
  param_1[0xc] = param_1[0xd];
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== EnableStackedTabs @ 00408b90

/* Library Function - Single Match
    public: void __thiscall CPropertySheet::EnableStackedTabs(int)
   
   Library: Visual Studio 1998 Debug */

void __thiscall CPropertySheet::EnableStackedTabs(CPropertySheet *this,int param_1)

{
  *(int *)(this + 0x3340) = param_1;
  return;
}


// ==== EnableStackedTabs @ 00408bc0

/* Library Function - Single Match
    public: void __thiscall CPropertySheet::EnableStackedTabs(int)
   
   Library: Visual Studio 1998 Debug */

void __thiscall CPropertySheet::EnableStackedTabs(CPropertySheet *this,int param_1)

{
  *(int *)(this + 0x3344) = param_1;
  return;
}


// ==== FUN_00408bf0 @ 00408bf0

undefined4 * __thiscall FUN_00408bf0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x3340);
  return param_2;
}


// ==== FUN_00408c20 @ 00408c20

undefined4 * __thiscall FUN_00408c20(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x3344);
  return param_2;
}


// ==== FUN_00408c50 @ 00408c50

void __thiscall FUN_00408c50(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x32dc) = param_2;
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x3308) = param_2;
  }
  return;
}


// ==== FUN_00408c90 @ 00408c90

void __thiscall FUN_00408c90(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x32e0) = param_2;
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x330c) = param_2;
  }
  return;
}


// ==== FUN_00408cd0 @ 00408cd0

void __fastcall FUN_00408cd0(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_60;
  int local_54;
  int local_48;
  int local_3c;
  int local_30;
  int local_24;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_00407450();
    *(undefined1 *)(param_1 + 0x32bc) = 0;
    *(undefined4 *)(param_1 + 0x32d0) = 0;
    *(undefined4 *)(param_1 + 0x32d4) = 0;
    *(undefined4 *)(param_1 + 0x32d8) = 1;
    if (*(int *)(param_1 + 0x32f4) != 0) {
      FUN_00422290(*(undefined4 *)(param_1 + 0x32f4));
    }
    *(undefined4 *)(param_1 + 0x32f4) = 0;
    *(undefined4 *)(param_1 + 0x32fc) = 0;
    *(undefined4 *)(param_1 + 0x3300) = 0;
    *(undefined4 *)(param_1 + 0x32dc) = 0;
    *(undefined4 *)(param_1 + 0x32e0) = 0;
  }
  else {
    for (local_18 = 0; local_18 < *(int *)(param_1 + 0xc); local_18 = local_18 + 1) {
      if (local_18 == 0) {
        local_14 = *(int *)(param_1 + 0x32dc);
        piVar2 = (int *)(*(int *)(param_1 + 0x108) * 0x50 + param_1 + 0x10c);
        if ((*piVar2 == 0) || (iVar3 = FUN_00407370(), iVar3 != 0)) {
          local_24 = 0;
        }
        else {
          local_24 = (int)*(short *)*piVar2;
        }
        local_c = *(int *)(param_1 + 0x10 + *(int *)(param_1 + 0x108) * 4) + local_14 + local_24 +
                  -1;
        local_10 = *(int *)(param_1 + 0x32e0);
        piVar2 = (int *)(*(int *)(param_1 + 0x108) * 0x50 + param_1 + 0x10c);
        if ((*piVar2 == 0) || (iVar3 = FUN_00407370(), iVar3 != 0)) {
          local_30 = 0;
        }
        else {
          local_30 = (int)*(short *)(*piVar2 + 2);
        }
        local_8 = *(int *)(param_1 + 0x60 + *(int *)(param_1 + 0x108) * 4) + local_10 + local_30 +
                  -1;
      }
      else {
        if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c + 0x10c
                    + param_1) == 0) {
LAB_00409160:
          local_3c = 0;
        }
        else {
          if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                       0x10c + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)
                     (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c + 0x10c
                     + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                         local_18 * 0x73c + 0x10c + param_1) + 6) *
                (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                         local_18 * 0x73c + 0x10c + param_1) + 8) -
                *(int *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                  local_18 * 0x73c + 0x10c + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_00409160;
          local_3c = (int)**(short **)
                            (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c
                             + 0x10c + param_1);
        }
        if (local_c <=
            *(int *)(local_18 * 0x73c + *(int *)(param_1 + 0x108 + local_18 * 0x73c) * 4 + 0x10 +
                    param_1) + *(int *)(param_1 + 0x32dc) + local_3c + -1) {
          if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                       0x10c + param_1) == 0) {
LAB_0040942c:
            local_48 = 0;
          }
          else {
            if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                         0x10c + param_1) == 0) {
              bVar1 = false;
            }
            else if (**(short **)
                       (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                        0x10c + param_1) == 0x400) {
              if ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                           local_18 * 0x73c + 0x10c + param_1) + 6) *
                  (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                           local_18 * 0x73c + 0x10c + param_1) + 8) -
                  *(int *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                    local_18 * 0x73c + 0x10c + param_1) + 2) == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
            if (bVar1) goto LAB_0040942c;
            local_48 = (int)**(short **)
                              (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                               local_18 * 0x73c + 0x10c + param_1);
          }
          local_c = *(int *)(local_18 * 0x73c + *(int *)(param_1 + 0x108 + local_18 * 0x73c) * 4 +
                             0x10 + param_1) + *(int *)(param_1 + 0x32dc) + local_48 + -1;
        }
        if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c + 0x10c
                    + param_1) == 0) {
LAB_004096ee:
          local_54 = 0;
        }
        else {
          if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                       0x10c + param_1) == 0) {
            bVar1 = false;
          }
          else if (**(short **)
                     (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c + 0x10c
                     + param_1) == 0x400) {
            if ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                         local_18 * 0x73c + 0x10c + param_1) + 6) *
                (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                         local_18 * 0x73c + 0x10c + param_1) + 8) -
                *(int *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                  local_18 * 0x73c + 0x10c + param_1) + 2) == 0) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_004096ee;
          local_54 = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                              local_18 * 0x73c + 0x10c + param_1) + 2);
        }
        if (local_8 <=
            *(int *)(local_18 * 0x73c + *(int *)(param_1 + 0x108 + local_18 * 0x73c) * 4 + 0x60 +
                    param_1) + *(int *)(param_1 + 0x32e0) + local_54 + -1) {
          if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                       0x10c + param_1) == 0) {
LAB_004099bb:
            local_60 = 0;
          }
          else {
            if (*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                         0x10c + param_1) == 0) {
              bVar1 = false;
            }
            else if (**(short **)
                       (*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 + local_18 * 0x73c +
                        0x10c + param_1) == 0x400) {
              if ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                           local_18 * 0x73c + 0x10c + param_1) + 6) *
                  (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                           local_18 * 0x73c + 0x10c + param_1) + 8) -
                  *(int *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50 +
                                    local_18 * 0x73c + 0x10c + param_1) + 2) == 0) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
            if (bVar1) goto LAB_004099bb;
            local_60 = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x108 + local_18 * 0x73c) * 0x50
                                                + local_18 * 0x73c + 0x10c + param_1) + 2);
          }
          local_8 = *(int *)(local_18 * 0x73c + *(int *)(param_1 + 0x108 + local_18 * 0x73c) * 4 +
                             0x60 + param_1) + *(int *)(param_1 + 0x32e0) + local_60 + -1;
        }
      }
    }
    uVar4 = FUN_0041877b(&local_14);
    uVar5 = FUN_0041876b(&local_14,uVar4);
    FUN_00408260(uVar5,uVar4);
  }
  return;
}


// ==== FUN_00409a60 @ 00409a60

int * __thiscall FUN_00409a60(CPropertySheet *param_1,int *param_2)

{
  bool bVar1;
  CPropertySheet *pCVar2;
  undefined4 uVar3;
  int in_stack_ffffff78;
  int local_74;
  int local_68;
  undefined1 local_3c [4];
  undefined1 *local_38;
  undefined1 local_34 [4];
  undefined1 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_20 = *(undefined4 *)(param_1 + 0x32dc);
  local_24 = *(undefined4 *)(param_1 + 0x32e0);
  local_28 = *(undefined4 *)(param_1 + 0x3340);
  local_2c = *(undefined4 *)(param_1 + 0x3344);
  local_1c = local_28;
  local_8 = local_2c;
  if (*(int *)(param_1 + 0x3348) < 1) {
    *(undefined4 *)(param_1 + 0x32dc) = *(undefined4 *)(param_1 + 0x3330);
    *(undefined4 *)(param_1 + 0x3308) = *(undefined4 *)(param_1 + 0x3330);
    *(undefined4 *)(param_1 + 0x32e0) = *(undefined4 *)(param_1 + 0x3334);
    *(undefined4 *)(param_1 + 0x330c) = *(undefined4 *)(param_1 + 0x3334);
  }
  else {
    local_30 = &stack0xffffff78;
    pCVar2 = param_1 + 0x3338;
    uVar3 = FUN_00408bf0(local_34);
    FUN_004077a0(local_30,uVar3,pCVar2);
    CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffff78);
    local_38 = &stack0xffffff78;
    pCVar2 = param_1 + 0x333c;
    uVar3 = FUN_00408c20(local_3c);
    FUN_004077a0(local_38,uVar3,pCVar2);
    CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffff78);
    *(int *)(param_1 + 0x32dc) = *(int *)(param_1 + 0x3340) >> 0x10;
    *(int *)(param_1 + 0x3308) = *(int *)(param_1 + 0x3340) >> 0x10;
    *(int *)(param_1 + 0x32e0) = *(int *)(param_1 + 0x3344) >> 0x10;
    *(int *)(param_1 + 0x330c) = *(int *)(param_1 + 0x3344) >> 0x10;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    goto LAB_00409e52;
  }
  local_18 = *(int *)(param_1 + 0x32dc);
  local_14 = *(int *)(param_1 + 0x32e0);
  if (*(int *)(param_1 + 0x32b4) == 0) {
LAB_00409d33:
    local_68 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x32b4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(param_1 + 0x32b4) == 0x400) {
      if ((int)*(short *)(*(int *)(param_1 + 0x32b4) + 6) *
          (int)*(short *)(*(int *)(param_1 + 0x32b4) + 8) - *(int *)(*(int *)(param_1 + 0x32b4) + 2)
          == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00409d33;
    local_68 = (int)**(short **)(param_1 + 0x32b4);
  }
  local_10 = local_18 + local_68 + -1;
  if (*(int *)(param_1 + 0x32b4) == 0) {
LAB_00409e0e:
    local_74 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x32b4) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(param_1 + 0x32b4) == 0x400) {
      if ((int)*(short *)(*(int *)(param_1 + 0x32b4) + 6) *
          (int)*(short *)(*(int *)(param_1 + 0x32b4) + 8) - *(int *)(*(int *)(param_1 + 0x32b4) + 2)
          == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00409e0e;
    local_74 = (int)*(short *)(*(int *)(param_1 + 0x32b4) + 2);
  }
  local_c = local_14 + local_74 + -1;
LAB_00409e52:
  *(undefined4 *)(param_1 + 0x32dc) = local_20;
  *(undefined4 *)(param_1 + 0x32e0) = local_24;
  FUN_00409f10(&local_1c);
  CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffff78);
  FUN_00409f10(&local_8);
  CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffff78);
  *param_2 = local_18;
  param_2[1] = local_14;
  param_2[2] = local_10;
  param_2[3] = local_c;
  return param_2;
}


// ==== FUN_00409f10 @ 00409f10

undefined4 * __thiscall FUN_00409f10(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


// ==== FUN_00409f40 @ 00409f40

undefined4 __fastcall FUN_00409f40(CPropertySheet *param_1)

{
  CPropertySheet *pCVar1;
  undefined4 uVar2;
  int iVar3;
  int in_stack_ffffffac;
  undefined1 local_24 [4];
  undefined1 *local_20;
  undefined1 local_1c [4];
  undefined1 *local_18;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) < 400)) {
    if (*(int *)(param_1 + 8) < 200) {
      if ((*(int *)param_1 < 0x33) && (*(int *)(param_1 + 0x334c) < 1)) {
        *(undefined4 *)(param_1 + 0x334c) = 10;
        local_8 = *(int *)(param_1 + 0x32dc);
        local_c = *(int *)(param_1 + 0x32e0);
        local_10 = FUN_00411187();
        local_10 = local_10 + -1;
        iVar3 = FUN_00411187();
        iVar3 = iVar3 + -1;
        if (((local_10 + local_8) - *(int *)(param_1 + 0x3308) < 4) &&
           (local_10 + local_8 != *(int *)(param_1 + 0x3308) &&
            -1 < (local_10 + local_8) - *(int *)(param_1 + 0x3308))) {
          *(int *)(param_1 + 0x32dc) = local_10 + local_8;
        }
        if (((iVar3 + local_c) - *(int *)(param_1 + 0x330c) < 4) &&
           (iVar3 + local_c != *(int *)(param_1 + 0x330c) &&
            -1 < (iVar3 + local_c) - *(int *)(param_1 + 0x330c))) {
          *(int *)(param_1 + 0x32e0) = iVar3 + local_c;
        }
      }
    }
    else if (*(int *)(param_1 + 0x334c) < 1) {
      *(undefined4 *)(param_1 + 0x334c) = 1;
      if (*(int *)(param_1 + 0x3348) < 1) {
        *(undefined4 *)(param_1 + 0x32dc) = *(undefined4 *)(param_1 + 0x3330);
        *(undefined4 *)(param_1 + 0x3308) = *(undefined4 *)(param_1 + 0x3330);
        *(undefined4 *)(param_1 + 0x32e0) = *(undefined4 *)(param_1 + 0x3334);
        *(undefined4 *)(param_1 + 0x330c) = *(undefined4 *)(param_1 + 0x3334);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x332c);
        return 1;
      }
      *(int *)(param_1 + 0x3348) = *(int *)(param_1 + 0x3348) + -1;
      local_18 = &stack0xffffffac;
      pCVar1 = param_1 + 0x3338;
      uVar2 = FUN_00408bf0(local_1c);
      FUN_004077a0(local_18,uVar2,pCVar1);
      CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffffac);
      local_20 = &stack0xffffffac;
      pCVar1 = param_1 + 0x333c;
      uVar2 = FUN_00408c20(local_24);
      FUN_004077a0(local_20,uVar2,pCVar1);
      CPropertySheet::EnableStackedTabs(param_1,in_stack_ffffffac);
      *(int *)(param_1 + 0x32dc) = *(int *)(param_1 + 0x3340) >> 0x10;
      *(int *)(param_1 + 0x3308) = *(int *)(param_1 + 0x3340) >> 0x10;
      *(int *)(param_1 + 0x32e0) = *(int *)(param_1 + 0x3344) >> 0x10;
      *(int *)(param_1 + 0x330c) = *(int *)(param_1 + 0x3344) >> 0x10;
    }
  }
  return 0;
}


// ==== FUN_0040a280 @ 0040a280

void FUN_0040a280(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040a2d6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_0040a2be();
  FUN_0040a2e0();
  return;
}


// ==== FUN_0040a2be @ 0040a2be

void FUN_0040a2be(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_
            ((void *)(*(int *)(unaff_EBP + -0x10) + 0xfc),0x50,0x14,FUN_004074b0);
  return;
}


// ==== FUN_0040a2e0 @ 0040a2e0

void FUN_0040a2e0(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040a2f0 @ 0040a2f0

HGLOBAL FUN_0040a2f0(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042f128 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042f128 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_0040a368 @ 0040a368

HGLOBAL FUN_0040a368(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042f128 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_0042f128 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_0042f128 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_0040a402 @ 0040a402

undefined4 FUN_0040a402(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_0042b498; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),hResInfo);
        if (param_4 < local_8) {
          local_8 = param_4;
        }
        _Src = LockResource(hResData);
        if (_Src != (LPVOID)0x0) {
          FID_conflict__memcpy(param_3,_Src,local_8);
          FreeResource(hResData);
          return 1;
        }
        FreeResource(hResData);
        return 0;
      }
    }
  }
  return 0;
}


// ==== FUN_0040a513 @ 0040a513

bool FUN_0040a513(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

{
  LPCCH lpBuffer;
  DWORD lBytes;
  HFILE hFile;
  DWORD DVar1;
  bool bVar2;
  HGLOBAL local_20;
  int local_18;
  HRSRC local_14;
  
  local_18 = 0;
  do {
    if (DAT_0042b498 <= local_18) {
LAB_0040a581:
      if (local_14 == (HRSRC)0x0) {
        bVar2 = false;
      }
      else {
        lpBuffer = LockResource(local_20);
        if (lpBuffer == (LPCCH)0x0) {
          FreeResource(local_14);
          bVar2 = false;
        }
        else {
          lBytes = SizeofResource(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),local_14);
          hFile = _lcreat(param_3,0);
          if (hFile == -1) {
            FreeResource(local_14);
            bVar2 = false;
          }
          else {
            DVar1 = _hwrite(hFile,lpBuffer,lBytes);
            _lclose(hFile);
            FreeResource(local_14);
            bVar2 = DVar1 == lBytes;
          }
        }
      }
      return bVar2;
    }
    local_14 = FindResourceA(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_0042f128 + local_18 * 4),local_14);
      goto LAB_0040a581;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_0040a647 @ 0040a647

HRSRC FUN_0040a647(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_0042f128 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040a6ac @ 0040a6ac

HGLOBAL FUN_0040a6ac(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042f128 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_0040a70d @ 0040a70d

INT_PTR FUN_0040a70d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_0042f128 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_0040a77b @ 0040a77b

HACCEL FUN_0040a77b(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_0042f128 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040a7dd @ 0040a7dd

HICON FUN_0040a7dd(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_0042f128 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040a83e @ 0040a83e

HMENU FUN_0040a83e(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_0042f128 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040a8a0 @ 0040a8a0

int FUN_0040a8a0(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0042b498 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_0042f128 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_0040a909 @ 0040a909

HBITMAP FUN_0040a909(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0042b498 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_0042f128 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040a96a @ 0040a96a

void FUN_0040a96a(void)

{
  DAT_0042b498 = 0;
  return;
}


// ==== FUN_0040a984 @ 0040a984

bool FUN_0040a984(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_0042b498 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_0042f128 + DAT_0042b498 * 4) = param_1;
    DAT_0042b498 = DAT_0042b498 + 1;
  }
  return bVar1;
}


// ==== FUN_0040a9c3 @ 0040a9c3

undefined4 FUN_0040a9c3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_0042b498 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_0042f128 + DAT_0042b498 * 4) = pHVar2;
      DAT_0042b498 = DAT_0042b498 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040aa23 @ 0040aa23

bool FUN_0040aa23(LPCSTR param_1,void *param_2)

{
  bool bVar1;
  HKEY local_414;
  BYTE local_410 [1024];
  DWORD local_10;
  LSTATUS local_c;
  DWORD local_8;
  
  _memset(param_2,0,0x100);
  local_8 = 1;
  local_414 = (HKEY)0x0;
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_0042b724,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_00421be0(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040aafb @ 0040aafb

bool FUN_0040aafb(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040ab3d @ 0040ab3d

undefined4 FUN_0040ab3d(void)

{
  return 1;
}


// ==== FUN_0040ab55 @ 0040ab55

void FUN_0040ab55(undefined4 param_1)

{
  size_t sVar1;
  CHAR local_104 [256];
  
  GetWindowsDirectoryA(local_104,0x100);
  sVar1 = _strlen(local_104);
  if (local_104[sVar1] != '\\') {
    FUN_00421bf0(local_104,&DAT_0042b758);
  }
  FUN_00421bf0(local_104,param_1);
  FUN_00421be0(param_1,local_104);
  return;
}


// ==== FUN_0040abd7 @ 0040abd7

undefined4 FUN_0040abd7(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_104 [256];
  
  _memset(local_104,0,0x100);
  FUN_0040aa23(s_Shared_Path_0042b75c,local_104);
  FUN_00421bf0(local_104,param_1);
  iVar1 = FUN_0040aafb(local_104);
  if (iVar1 == 0) {
    FUN_0040aa23(s_Shared_Path_0042b768,local_104);
    FUN_00421bf0(local_104,&DAT_0042b774);
    FUN_00421bf0(local_104,param_1);
    iVar1 = FUN_0040aafb(local_104);
    if (iVar1 == 0) {
      FUN_00421be0(local_104,s___shared__0042b778);
      FUN_00421bf0(local_104,param_1);
      iVar1 = FUN_0040aafb(local_104);
      if (iVar1 == 0) {
        FUN_00421be0(local_104,&DAT_0042b784);
        FUN_00421bf0(local_104,param_1);
        iVar1 = FUN_0040aafb(local_104);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00421be0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00421be0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00421be0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00421be0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040ad85 @ 0040ad85

undefined4 FUN_0040ad85(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_104 [256];
  
  _memset(local_104,0,0x100);
  FUN_0040aa23(s_Help_Path_0042b788,local_104);
  FUN_00421bf0(local_104,param_1);
  iVar1 = FUN_0040aafb(local_104);
  if (iVar1 == 0) {
    FUN_0040aa23(s_Help_Path_0042b794,local_104);
    FUN_00421bf0(local_104,&DAT_0042b7a0);
    FUN_00421bf0(local_104,param_1);
    iVar1 = FUN_0040aafb(local_104);
    if (iVar1 == 0) {
      FUN_00421be0(local_104,&DAT_0042b7a4);
      FUN_00421bf0(local_104,param_1);
      iVar1 = FUN_0040aafb(local_104);
      if (iVar1 == 0) {
        FUN_00421be0(local_104,s___shared__0042b7a8);
        FUN_00421bf0(local_104,param_1);
        iVar1 = FUN_0040aafb(local_104);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00421be0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00421be0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00421be0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00421be0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040af33 @ 0040af33

undefined4 FUN_0040af33(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_0042b720 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_0042f228 + DAT_0042b720 * 4) = param_1;
    DAT_0042b720 = DAT_0042b720 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040af7f @ 0040af7f

void FUN_0040af7f(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0042b720; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042f228 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042f228 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_0042f228 + local_8 * 4) = 0;
  }
  DAT_0042b720 = 0;
  return;
}


// ==== FUN_0040aff0 @ 0040aff0

int FUN_0040aff0(void *param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  _memset(param_1,0,0x94);
  iVar1 = FUN_0040c0fd((int)param_1 + 0x80,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  local_8 = FUN_0040c1cf(*(undefined4 *)((int)param_1 + 0x80),param_1,0x80);
  if (-1 < local_8) {
    *(undefined4 *)((int)param_1 + 0x88) = param_2;
    if (*(short *)((int)param_1 + 4) == -0x50ee) {
      DAT_0042b7b8 = *(int *)((int)param_1 + 0x50);
      DAT_00430328 = *(int *)((int)param_1 + 0x50) + DAT_0043032c;
      return 0;
    }
    if (*(short *)((int)param_1 + 4) == -0x50ef) {
      *(undefined4 *)((int)param_1 + 0x50) = 0x80;
      *(int *)((int)param_1 + 0x10) = (*(int *)((int)param_1 + 0x10) * 1000) / 0x46;
      return 0;
    }
    local_8 = -3;
  }
  FUN_0040b104(param_1);
  return local_8;
}


// ==== FUN_0040b104 @ 0040b104

void FUN_0040b104(void *param_1)

{
  FreeResource(DAT_00430334);
  DAT_0043032c = 0;
  DAT_00430328 = 0;
  DAT_0042b7b8 = 0;
  _memset(param_1,0,0x94);
  return;
}


// ==== FUN_0040b151 @ 0040b151

int FUN_0040b151(int param_1,undefined4 param_2)

{
  int local_24;
  uint local_20;
  int local_14;
  int local_10;
  undefined4 local_c [2];
  
  local_14 = FUN_0040c1cf(*(undefined4 *)(param_1 + 0x80),&local_24,0x10);
  if (-1 < local_14) {
    if ((local_20 & 0xffff) == 0xf1fa) {
      local_10 = local_24 + -0x10;
      if ((0 < local_10) && (local_14 = FUN_0040c076(local_c,local_10), -1 < local_14)) {
        local_14 = FUN_0040c25b(*(undefined4 *)(param_1 + 0x80),local_c,local_10);
        if (-1 < local_14) {
          local_14 = FUN_0040b229(param_1,&local_24,local_c[0],param_2);
        }
        FUN_0040c0c1(local_c);
      }
    }
    else {
      local_14 = -4;
    }
  }
  return local_14;
}


// ==== FUN_0040b229 @ 0040b229

undefined4 FUN_0040b229(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < *(short *)(param_2 + 6); local_8 = local_8 + 1) {
    iVar1 = *param_3;
    switch((short)param_3[1]) {
    case 4:
      FUN_0040b39c((int)param_3 + 6,param_1,param_4);
      break;
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 0xe:
      break;
    case 7:
      FUN_0040b6ad((int)param_3 + 6,param_1,param_4);
      break;
    case 0xb:
      FUN_0040b45e((int)param_3 + 6,param_1,param_4);
      break;
    case 0xc:
      FUN_0040b580((int)param_3 + 6,param_1,param_4);
      break;
    case 0xd:
      FUN_0040b8a3((int)param_3 + 6,param_1,param_4);
      break;
    case 0xf:
      FUN_0040b487((int)param_3 + 6,param_1,param_4);
      break;
    case 0x10:
      FUN_0040b95c((int)param_3 + 6,param_1,param_4);
    }
    param_3 = (int *)((int)param_3 + iVar1);
  }
  return 0;
}


// ==== FUN_0040b39c @ 0040b39c

void FUN_0040b39c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0040b3c5(param_1,param_2,param_3,FUN_0040bf88);
  return;
}


// ==== FUN_0040b3c5 @ 0040b3c5

void FUN_0040b3c5(short *param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  short local_18;
  int local_14;
  byte *local_10;
  uint local_c;
  
  local_14 = 0;
  local_18 = *param_1;
  local_10 = (byte *)(param_1 + 1);
  while (local_18 = local_18 + -1, -1 < local_18) {
    bVar1 = *local_10;
    local_c = (uint)local_10[1];
    if (local_c == 0) {
      local_c = 0x100;
    }
    (*param_4)(param_3,local_14 + (uint)bVar1,local_10 + 2,local_c);
    local_10 = local_10 + 2 + local_c * 3;
    local_14 = local_14 + (uint)bVar1 + local_c;
  }
  return;
}


// ==== FUN_0040b45e @ 0040b45e

void FUN_0040b45e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0040b3c5(param_1,param_2,param_3,FUN_0040bfff);
  return;
}


// ==== FUN_0040b487 @ 0040b487

void FUN_0040b487(char *param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  uint local_20;
  char *local_1c;
  int local_18;
  int local_14;
  char local_10;
  
  uVar2 = *(ushort *)(param_2 + 8);
  local_20 = (uint)*(ushort *)(param_2 + 10);
  local_1c = param_1;
  local_18 = *(int *)(param_2 + 0x90);
  iVar3 = *(int *)(param_2 + 0x8c);
  while (local_20 = local_20 - 1, -1 < (int)local_20) {
    local_14 = *(int *)(param_2 + 0x8c);
    local_1c = local_1c + 1;
    local_10 = '\0';
    while (local_14 = local_14 + local_10, local_14 < (int)(iVar3 + (uint)uVar2)) {
      local_10 = *local_1c;
      pcVar1 = local_1c + 1;
      if (local_10 < '\0') {
        local_10 = -local_10;
        FUN_0040bd46(param_3,local_14,local_18,pcVar1,(int)local_10);
        local_1c = pcVar1 + local_10;
      }
      else {
        local_1c = local_1c + 2;
        FUN_0040be93(param_3,local_14,local_18,CONCAT31((int3)((uint)pcVar1 >> 8),*pcVar1),
                     (int)local_10);
      }
    }
    local_18 = local_18 + 1;
  }
  return;
}


// ==== FUN_0040b580 @ 0040b580

void FUN_0040b580(short *param_1,int param_2,undefined4 param_3)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  byte *local_28;
  int local_24;
  short local_20;
  int local_1c;
  byte local_10;
  
  iVar2 = *(int *)(param_2 + 0x8c);
  local_28 = (byte *)(param_1 + 2);
  local_24 = (int)*param_1 + *(int *)(param_2 + 0x90);
  local_20 = param_1[1];
  while (local_20 = local_20 + -1, -1 < local_20) {
    local_10 = *local_28;
    local_28 = local_28 + 1;
    local_1c = iVar2;
    for (; local_10 != 0; local_10 = local_10 - 1) {
      local_1c = local_1c + (uint)*local_28;
      bVar3 = local_28[1];
      pbVar1 = local_28 + 2;
      if ((char)bVar3 < '\0') {
        bVar3 = -bVar3;
        local_28 = local_28 + 3;
        FUN_0040be93(param_3,local_1c,local_24,CONCAT31((int3)((uint)pbVar1 >> 8),*pbVar1),
                     (int)(char)bVar3);
      }
      else {
        FUN_0040bd46(param_3,local_1c,local_24,pbVar1,(int)(char)bVar3);
        local_28 = pbVar1 + (char)bVar3;
      }
      local_1c = local_1c + (char)bVar3;
    }
    local_24 = local_24 + 1;
  }
  return;
}


// ==== FUN_0040b6ad @ 0040b6ad

void FUN_0040b6ad(short *param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int local_2c;
  int local_28;
  short local_24;
  ushort local_1c;
  ushort *local_18;
  
  iVar2 = *(int *)(param_2 + 0x8c);
  local_2c = *(int *)(param_2 + 0x90);
  uVar1 = *(ushort *)(param_2 + 8);
  local_24 = *param_1;
  local_18 = (ushort *)(param_1 + 1);
  do {
    while( true ) {
      local_1c = *local_18;
      puVar4 = local_18 + 1;
      local_28 = iVar2;
      if (-1 < (short)local_1c) goto LAB_0040b7a4;
      if ((local_1c & 0x4000) == 0) break;
      local_2c = local_2c - (short)local_1c;
      local_18 = puVar4;
    }
    FUN_0040bce7(param_3,(undefined1)local_1c,iVar2 + (uint)uVar1 + -1,local_2c);
    for (local_1c = *puVar4; local_18 = local_18 + 2, puVar4 = local_18, local_1c != 0;
        local_1c = local_1c - 1) {
LAB_0040b7a4:
      while( true ) {
        local_18 = puVar4;
        local_28 = local_28 + (uint)(byte)*local_18;
        iVar5 = (int)(char)*(byte *)((int)local_18 + 1);
        puVar4 = local_18 + 1;
        iVar3 = iVar5 * 2;
        if (iVar3 < 0) break;
        FUN_0040bd46(param_3,local_28,local_2c,puVar4,iVar3);
        local_28 = local_28 + iVar3;
        local_18 = puVar4 + iVar5;
        local_1c = local_1c - 1;
        puVar4 = local_18;
        if (local_1c == 0) goto joined_r0x0040b813;
      }
      FUN_0040bef6(param_3,local_28,local_2c,CONCAT22((short)((uint)puVar4 >> 0x10),*puVar4),
                   iVar5 * -2 >> 1);
      local_28 = local_28 + iVar5 * -2;
    }
joined_r0x0040b813:
    local_24 = local_24 + -1;
    local_2c = local_2c + 1;
    if (local_24 < 1) {
      return;
    }
  } while( true );
}


// ==== FUN_0040b8a3 @ 0040b8a3

void FUN_0040b8a3(undefined4 param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_18;
  undefined4 local_c;
  
  uVar1 = *(ushort *)(param_2 + 10);
  uVar2 = *(ushort *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0x8c);
  iVar4 = *(int *)(param_2 + 0x90);
  local_c = local_c & 0xffff0000;
  for (local_18 = 0; local_18 < (int)(uint)uVar1; local_18 = local_18 + 1) {
    FUN_0040bef6(param_3,iVar3,iVar4 + local_18,local_c,uVar2 / 2);
    if ((uVar2 & 1) != 0) {
      FUN_0040bce7(param_3,iVar3 + (uint)uVar2 + -1,iVar4 + local_18,0);
    }
  }
  return;
}


// ==== FUN_0040b95c @ 0040b95c

void FUN_0040b95c(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_14;
  
  uVar1 = *(ushort *)(param_2 + 10);
  uVar2 = *(ushort *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0x8c);
  iVar4 = *(int *)(param_2 + 0x90);
  for (local_14 = 0; local_14 < (int)(uint)uVar1; local_14 = local_14 + 1) {
    FUN_0040bd46(param_3,uVar3,iVar4 + local_14,param_1,(uint)uVar2);
    param_1 = param_1 + (uint)uVar2;
  }
  return;
}


// ==== FUN_0040b9e4 @ 0040b9e4

int FUN_0040b9e4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 6) <= local_c) {
      return local_8;
    }
    uVar1 = FUN_0040ba7f(*(undefined4 *)(param_1 + 0x10),param_2 + 0x314);
    iVar2 = FUN_0040b151(param_1,param_2);
    if (iVar2 < 0) break;
    local_8 = FUN_0040baab(uVar1,param_2);
    if (local_8 < 0) {
      return local_8;
    }
    local_c = local_c + 1;
  }
  return iVar2;
}


// ==== FUN_0040ba7f @ 0040ba7f

int FUN_0040ba7f(int param_1,int *param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = *param_2;
  DVar2 = GetTickCount();
  return DVar2 + (uint)(iVar1 * param_1) / 1000;
}


// ==== FUN_0040baab @ 0040baab

undefined4 FUN_0040baab(void)

{
  return 0;
}


// ==== FUN_0040babd @ 0040babd

int FUN_0040babd(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0x54) == 0) {
    FUN_0040bbe4(param_1);
  }
  DAT_0042b7b8 = *(int *)(param_1 + 0x50);
  DAT_00430328 = DAT_0042b7b8 + DAT_0043032c;
  local_10 = FUN_0040ba7f(*(undefined4 *)(param_1 + 0x10),param_2 + 0x314);
  iVar1 = FUN_0040b151(param_1,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  do {
    DAT_0042b7b8 = *(int *)(param_1 + 0x54);
    DAT_00430328 = DAT_0042b7b8 + DAT_0043032c;
    for (local_c = 0; local_c < (int)(uint)*(ushort *)(param_1 + 6); local_c = local_c + 1) {
      iVar1 = FUN_0040baab(local_10,param_2);
      if (iVar1 < 0) {
        return 0;
      }
      iVar1 = FUN_0040b151(param_1,param_2);
      if (iVar1 < 0) {
        return iVar1;
      }
      local_10 = FUN_0040ba7f(*(undefined4 *)(param_1 + 0x10),param_2 + 0x314);
    }
  } while( true );
}


// ==== FUN_0040bbe4 @ 0040bbe4

int FUN_0040bbe4(int param_1)

{
  int iVar1;
  int local_18 [5];
  
  DAT_0042b7b8 = *(int *)(param_1 + 0x50);
  DAT_00430328 = DAT_0042b7b8 + DAT_0043032c;
  iVar1 = FUN_0040c1cf(*(undefined4 *)(param_1 + 0x80),local_18,0x10);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x50) + local_18[0];
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0040bc50 @ 0040bc50

char * FUN_0040bc50(int param_1)

{
  char *pcVar1;
  
  if (param_1 < 0) {
    if ((param_1 == -5) || (param_1 == -6)) {
      pcVar1 = s_File_IO_error_0042b884;
    }
    else if (0xffffffffU - param_1 < 10) {
      pcVar1 = (&PTR_s_Unspecified_error_0042b7c0)[0xffffffffU - param_1];
    }
    else {
      pcVar1 = s_Unknown_error_0042b894;
    }
  }
  else {
    pcVar1 = s_Success_0042b87c;
  }
  return pcVar1;
}


// ==== FUN_0040bcbb @ 0040bcbb

undefined4 FUN_0040bcbb(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ==== FUN_0040bcd1 @ 0040bcd1

undefined4 FUN_0040bcd1(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== FUN_0040bce7 @ 0040bce7

void FUN_0040bce7(int *param_1,int param_2,int param_3,undefined1 param_4)

{
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < param_1[1])) && (param_3 < param_1[2])) {
    *(undefined1 *)(param_1[1] * param_3 + param_2 + *param_1) = param_4;
  }
  return;
}


// ==== FUN_0040bd46 @ 0040bd46

void FUN_0040bd46(int *param_1,int param_2,int param_3,void *param_4,size_t param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  iVar2 = FUN_0040bdc6(param_1,&param_2,&param_3,&param_5);
  if (iVar2 != 0) {
    if (param_2 - iVar1 != 0) {
      param_4 = (void *)((int)param_4 + (param_2 - iVar1));
    }
    FID_conflict__memcpy((void *)(param_1[1] * param_3 + *param_1 + param_2),param_4,param_5);
  }
  return;
}


// ==== FUN_0040bdc6 @ 0040bdc6

undefined4 FUN_0040bdc6(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar1 = *param_2;
  local_8 = *param_4;
  iVar2 = local_8 + iVar1;
  if ((((*param_3 < 0) || (*(int *)(param_1 + 8) <= *param_3)) || (iVar2 < 0)) ||
     (*(int *)(param_1 + 4) <= iVar1)) {
    uVar3 = 0;
  }
  else {
    if (iVar1 < 0) {
      local_8 = local_8 + iVar1;
      *param_4 = local_8;
      *param_2 = 0;
    }
    if (*(int *)(param_1 + 4) < iVar2) {
      local_8 = local_8 - (iVar2 - *(int *)(param_1 + 4));
      *param_4 = local_8;
    }
    if (local_8 < 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_0040be93 @ 0040be93

void FUN_0040be93(int *param_1,int param_2,int param_3,byte param_4,size_t param_5)

{
  int iVar1;
  
  iVar1 = FUN_0040bdc6(param_1,&param_2,&param_3,&param_5);
  if (iVar1 != 0) {
    _memset((void *)(param_1[1] * param_3 + *param_1 + param_2),(uint)param_4,param_5);
  }
  return;
}


// ==== FUN_0040bef6 @ 0040bef6

void FUN_0040bef6(int *param_1,int param_2,int param_3,undefined2 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 *local_14;
  
  param_5 = param_5 << 1;
  iVar1 = FUN_0040bdc6(param_1,&param_2,&param_3,&param_5);
  if (iVar1 != 0) {
    uVar2 = param_5 & 1;
    param_5 = (int)param_5 >> 1;
    local_14 = (undefined2 *)(param_1[1] * param_3 + *param_1 + param_2);
    while (param_5 = param_5 + -1, -1 < (int)param_5) {
      *local_14 = param_4;
      local_14 = local_14 + 1;
    }
    if (uVar2 != 0) {
      *(undefined1 *)local_14 = (undefined1)param_4;
    }
  }
  return;
}


// ==== FUN_0040bf88 @ 0040bf88

void FUN_0040bf88(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int local_8;
  
  for (local_8 = param_2; local_8 < param_2 + param_4; local_8 = local_8 + 1) {
    *(undefined1 *)(local_8 * 3 + 0x14 + param_1) = *param_3;
    *(undefined1 *)(local_8 * 3 + 0x15 + param_1) = param_3[1];
    *(undefined1 *)(local_8 * 3 + 0x16 + param_1) = param_3[2];
    param_3 = param_3 + 3;
  }
  return;
}


// ==== FUN_0040bfff @ 0040bfff

void FUN_0040bfff(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int local_8;
  
  for (local_8 = param_2; local_8 < param_4 + param_2; local_8 = local_8 + 1) {
    *(undefined1 *)(local_8 * 3 + 0x14 + param_1) = *param_3;
    *(undefined1 *)(local_8 * 3 + 0x15 + param_1) = param_3[1];
    *(undefined1 *)(local_8 * 3 + 0x16 + param_1) = param_3[2];
    param_3 = param_3 + 3;
  }
  return;
}


// ==== FUN_0040c076 @ 0040c076

undefined4 FUN_0040c076(undefined4 *param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _malloc(param_2);
  param_1[1] = pvVar1;
  *param_1 = param_1[1];
  if (param_1[1] == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0040c0c1 @ 0040c0c1

void FUN_0040c0c1(void *param_1)

{
  if (*(int *)((int)param_1 + 4) != 0) {
    _free(*(void **)((int)param_1 + 4));
    _memset(param_1,0,8);
  }
  return;
}


// ==== FUN_0040c0fd @ 0040c0fd

undefined4 FUN_0040c0fd(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint local_8;
  
  DAT_00430334 = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_2,&DAT_0042b8a4,&DAT_0042b7bc);
  if (DAT_00430334 == (HGLOBAL)0x0) {
    uVar1 = 0xfffffffb;
  }
  else {
    DAT_0043032c = LockResource(DAT_00430334);
    if (DAT_0043032c == (LPVOID)0x0) {
      uVar1 = 0xfffffffb;
    }
    else {
      DAT_0042b7b8 = 0;
      for (local_8 = 0; local_8 < DAT_0042b7bc; local_8 = local_8 + 1) {
      }
      uVar1 = 0;
      DAT_00430328 = DAT_0043032c;
    }
  }
  return uVar1;
}


// ==== FUN_0040c1cf @ 0040c1cf

undefined4 FUN_0040c1cf(undefined4 param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  
  if (DAT_00430328 == (void *)0x0) {
    uVar1 = 0xfffffffa;
  }
  else if (DAT_0043032c == 0) {
    uVar1 = 0xfffffffa;
  }
  else if (DAT_0042b7bc < (int)DAT_00430328 + (param_3 - DAT_0043032c)) {
    uVar1 = 0xfffffffa;
  }
  else {
    FID_conflict__memcpy(param_2,DAT_00430328,param_3);
    DAT_00430328 = (void *)((int)DAT_00430328 + param_3);
    DAT_0042b7b8 = DAT_0042b7b8 + param_3;
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040c25b @ 0040c25b

int FUN_0040c25b(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_0040c1cf(param_1,*(undefined4 *)(param_2 + 4),param_3);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_0040c29c @ 0040c29c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040c29c(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  BOOL BVar2;
  undefined1 *local_3e0;
  tagMSG local_3dc;
  int local_3c0;
  uint local_3bc;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined1 auStack_3a4 [776];
  undefined1 local_9c [6];
  ushort local_96;
  int local_8;
  
  local_3b8 = param_2;
  local_3b4 = 0x278;
  local_3b0 = 400;
  local_3bc = 0;
  iVar1 = FUN_0040aff0(local_9c,param_1);
  if (-1 < iVar1) goto LAB_0040c310;
  local_3bc = 9999;
  DAT_0067ece4 = (HGLOBAL)FUN_0041671c(s_TITLEBMP_0042b8ac);
  do {
    DAT_0042bd34 = 1;
    DAT_0042bd38 = 0;
    local_3e0 = param_3;
    for (local_3c0 = 0; local_3c0 < 0xf6; local_3c0 = local_3c0 + 1) {
      *local_3e0 = auStack_3a4[local_3c0 * 3 + 2];
      local_3e0[1] = auStack_3a4[local_3c0 * 3 + 1];
      local_3e0[2] = auStack_3a4[local_3c0 * 3];
      local_3e0[3] = 0;
      local_3e0 = local_3e0 + 4;
    }
    _DAT_0067ffb0 = 0x300;
    _DAT_0067ffb2 = 0x100;
    for (local_3c0 = 0; local_3c0 < 0x100; local_3c0 = local_3c0 + 1) {
      (&DAT_0067ffb4)[local_3c0 * 4] = auStack_3a4[local_3c0 * 3];
      (&DAT_0067ffb5)[local_3c0 * 4] = auStack_3a4[local_3c0 * 3 + 1];
      (&DAT_0067ffb6)[local_3c0 * 4] = auStack_3a4[local_3c0 * 3 + 2];
      (&DAT_0067ffb7)[local_3c0 * 4] = 0;
    }
    DAT_00430330 = CreatePalette((LOGPALETTE *)&DAT_0067ffb0);
    do {
      if (local_3bc == 5) {
        FUN_00401633(0x14);
      }
      if (local_3bc == 0x3d) {
        FUN_00401633(0x11);
      }
      if (local_3bc == 0x6d) {
        FUN_00401633(0x12);
      }
      if (local_3bc == 0x82) {
        FUN_00401633(0x13);
      }
      if (local_3bc == 0x96) {
        FUN_00401633(0x14);
      }
      if (local_3bc == 0xb4) {
        FUN_00401633(0x10);
      }
      local_3bc = local_3bc + 1;
      if (local_96 == local_3bc) {
        GlobalFree(DAT_0067ece4);
        DAT_0067ece4 = (HGLOBAL)FUN_0041671c(s_TITLEBMP_0042b8b8);
      }
      do {
        InvalidateRect(DAT_00433894,(RECT *)0x0,0);
        Sleep(0x32);
        while( true ) {
          while( true ) {
            if (DAT_0042b7e4 != 0) goto LAB_0040c649;
LAB_0040c310:
            BVar2 = PeekMessageA(&local_3dc,(HWND)0x0,0,0,1);
            if (BVar2 == 0) break;
            if (local_3dc.message == 0x12) goto LAB_0040c649;
            if ((DAT_00433894 == (HWND)0x0) ||
               (iVar1 = TranslateAcceleratorA(DAT_00433894,DAT_0067ec80,&local_3dc), iVar1 == 0)) {
              TranslateMessage(&local_3dc);
              DispatchMessageA(&local_3dc);
            }
          }
          if ((DAT_0067ec8c != 0) || (local_3bc == 0)) break;
          WaitMessage();
        }
      } while ((int)(uint)local_96 <= (int)local_3bc);
      local_8 = FUN_0040b151(local_9c,&local_3b8);
      if (local_8 < 0) {
LAB_0040c649:
        FUN_0040b104(local_9c);
        return;
      }
    } while (local_3bc != 0);
  } while( true );
}


// ==== FUN_0040c670 @ 0040c670

int FUN_0040c670(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0040c68f @ 0040c68f

void FUN_0040c68f(void)

{
  _memset(&DAT_00433408,0,0x370);
  _memset(&DAT_00430338,0,0x30d0);
  FID_conflict__memcpy(&DAT_00430338,s_MD_PACK_0042b910,8);
  DAT_004317f0 = 0;
  DAT_004317f1 = 0;
  DAT_004317f2 = 0;
  DAT_00430342 = 0xc;
  _memset(&DAT_004317c4,0,0x28);
  FID_conflict__memcpy(&DAT_004317b4,s_MIXGEN_0042ba18,0xb);
  return;
}


// ==== FUN_0040c728 @ 0040c728

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040c728(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0040c68f();
  hFile = _lopen(s_MSPuzzle_dat_0042b918,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00430338,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_004317b4,s_MIXGEN_0042ba18,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00430338,s_MD_PACK_0042b910,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00433430 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_00431828 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00433408 + local_10 * 0x2c,&DAT_00431800 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00433430 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00433430 + local_10 * 0x2c) = 0;
        }
      }
      DAT_00427e6c = (uint)(DAT_004317f0 == '\0');
      DAT_00427e68 = (uint)(DAT_004317f1 == '\0');
      DAT_0042b8e4 = (uint)(DAT_004317f2 == '\0');
      FID_conflict__memcpy(&DAT_0042b8e8,&DAT_004317c4,0x28);
      _DAT_0042b8d0 = (uint)DAT_004317ec;
      if ((_DAT_0042b8d0 == 0) || (0x10 < _DAT_0042b8d0)) {
        _DAT_0042b8d0 = 1;
      }
      _DAT_0042b8d4 = (uint)DAT_004317ed;
      if ((_DAT_0042b8d4 == 0) || (1 < _DAT_0042b8d4)) {
        _DAT_0042b8d4 = 1;
      }
      DAT_0042b8d8 = (uint)(DAT_004317ee == '\0');
      DAT_0042b8dc = (uint)(DAT_004317ef == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0040c68f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_0040c9b1 @ 0040c9b1

undefined4 FUN_0040c9b1(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00433430 + local_8 * 0x2c) < param_1) {
      local_14 = local_8;
    }
    local_8 = local_8 + 1;
  }
  if ((local_14 < 0x14) && (-1 < local_14)) {
    local_c = 1;
    *param_2 = local_14;
  }
  return local_c;
}


// ==== FUN_0040ca4e @ 0040ca4e

int FUN_0040ca4e(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00433430 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00433408 + (local_1c + 1) * 0x2c,&DAT_00433408 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00433408 + local_1c * 0x2c,&DAT_0042b8e8,0x28);
    *(int *)(&DAT_00433430 + local_1c * 0x2c) = param_1;
    if (local_1c < 10) {
      local_8 = 4;
    }
    if (local_1c == 0) {
      local_8 = 2;
    }
  }
  if (local_8 == 0) {
    local_8 = 0;
  }
  return local_8;
}


// ==== FUN_0040cb92 @ 0040cb92

void FUN_0040cb92(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00431800,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00431800 + local_c * 0x30,&DAT_00433408 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_00431828 + local_c * 0x30) =
         *(undefined4 *)(&DAT_00433430 + local_c * 0x2c);
  }
  DAT_004317f0 = DAT_00427e6c == 0;
  DAT_004317f1 = DAT_00427e68 == 0;
  DAT_004317f2 = DAT_0042b8e4 == 0;
  DAT_004317ec = DAT_0042b8d0;
  DAT_004317ed = DAT_0042b8d4;
  DAT_004317ee = DAT_0042b8d8 == 0;
  DAT_004317ef = DAT_0042b8dc == 0;
  _memset(&DAT_004317c4,0,0x28);
  FID_conflict__memcpy(&DAT_004317c4,&DAT_0042b8e8,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_0042b918,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_0042b918,0);
  }
  _lwrite(local_8,&DAT_00430338,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_0040cd60 @ 0040cd60

void FUN_0040cd60(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  
  for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
    *(int *)(param_1 + local_14 * 4) = local_14;
  }
  FUN_0041116c();
  for (local_14 = 0; local_14 < 1000; local_14 = local_14 + 1) {
    iVar2 = FUN_00411187(param_2);
    iVar3 = FUN_00411187(param_2);
    if (iVar3 != iVar2) {
      uVar1 = *(undefined4 *)(param_1 + iVar2 * 4);
      *(undefined4 *)(param_1 + iVar2 * 4) = *(undefined4 *)(param_1 + iVar3 * 4);
      *(undefined4 *)(param_1 + iVar3 * 4) = uVar1;
    }
  }
  return;
}


// ==== FUN_0040ce1e @ 0040ce1e

/* WARNING: Removing unreachable block (ram,0x0040d456) */

void __thiscall FUN_0040ce1e(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_60;
  int local_58;
  int local_4c;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_0040cd60(&local_3c,6);
  switch(param_2) {
  case 1:
    local_40 = 2;
    break;
  case 2:
    local_40 = 3;
    break;
  case 3:
    local_40 = 4;
    break;
  case 4:
    local_40 = 5;
    break;
  case 5:
    local_40 = 6;
    break;
  default:
    local_40 = 6;
    break;
  case 7:
  case 9:
    local_40 = 5;
  }
  FUN_0040cd60(&local_1c,local_40);
  for (local_20 = 0; local_20 < 6; local_20 = local_20 + 1) {
    *(undefined4 *)(param_1 + 0x3310 + local_20 * 4) = local_1c;
  }
  *(undefined4 *)(param_1 + 0x3310 + local_3c * 4) = local_18;
  if (5 < param_2) {
    if (param_2 < 0xe) {
      uVar1 = FUN_00411187(local_40);
      *(undefined4 *)(param_1 + 0x3310 + local_38 * 4) = uVar1;
    }
    else {
      *(undefined4 *)(param_1 + 0x3310 + local_38 * 4) = local_14;
    }
  }
  if (8 < param_2) {
    if (param_2 < 0xf) {
      uVar1 = FUN_00411187(local_40);
      *(undefined4 *)(param_1 + 0x3310 + local_34 * 4) = uVar1;
    }
    else {
      *(undefined4 *)(param_1 + 0x3310 + local_34 * 4) = local_10;
    }
  }
  if (10 < param_2) {
    if (param_2 < 0x10) {
      uVar1 = FUN_00411187(local_40);
      *(undefined4 *)(param_1 + 0x3310 + local_30 * 4) = uVar1;
    }
    else {
      *(undefined4 *)(param_1 + 0x3310 + local_30 * 4) = local_c;
    }
  }
  if (0xc < param_2) {
    if (param_2 < 0x11) {
      uVar1 = FUN_00411187(local_40);
      *(undefined4 *)(param_1 + 0x3310 + local_2c * 4) = uVar1;
    }
    else {
      *(undefined4 *)(param_1 + 0x3310 + local_2c * 4) = local_8;
    }
  }
  for (local_20 = 0; local_20 < 6; local_20 = local_20 + 1) {
    puVar2 = (undefined4 *)
             (&DAT_00428680 + *(int *)(param_1 + 0x3310 + local_20 * 4) * 0x798 + local_20 * 0x144);
    if ((local_20 <= *(int *)(param_1 + 0xc)) && (puVar2 != (undefined4 *)0x0)) {
      *(undefined4 *)(param_1 + 0x104 + local_20 * 0x73c) = *puVar2;
      uVar1 = FUN_00411187(*(undefined4 *)(param_1 + 0x104 + local_20 * 0x73c));
      *(undefined4 *)(param_1 + 0x108 + local_20 * 0x73c) = uVar1;
      for (local_4c = 0; local_4c < *(int *)(param_1 + 0x104 + local_20 * 0x73c);
          local_4c = local_4c + 1) {
        *(undefined4 *)(local_4c * 4 + local_20 * 0x73c + 0x10 + param_1) = puVar2[local_4c * 4 + 1]
        ;
        *(undefined4 *)(local_4c * 4 + local_20 * 0x73c + 0x60 + param_1) = puVar2[local_4c * 4 + 2]
        ;
        *(undefined4 *)(local_4c * 4 + local_20 * 0x73c + 0xb0 + param_1) = puVar2[local_4c * 4 + 3]
        ;
        FUN_00408800();
        *(undefined4 *)(local_4c * 0x50 + local_20 * 0x73c + 0x10c + param_1) =
             puVar2[local_4c * 4 + 4];
        *(undefined4 *)(local_4c * 0x50 + local_20 * 0x73c + 0x110 + param_1) = 1;
      }
      *(undefined4 *)(param_1 + 0x100 + local_20 * 0x73c) =
           *(undefined4 *)
            (local_20 * 0x73c + *(int *)(param_1 + 0x108 + local_20 * 0x73c) * 4 + 0xb0 + param_1);
      if (*(int *)(param_1 + 0xc) == local_20) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      }
      FUN_00408cd0();
      if ((*(int *)(param_1 + 0x32b4) != 0) && (iVar3 = FUN_00407370(), iVar3 == 0)) {
        FUN_00407310(*(undefined4 *)(param_1 + 0x32b4),0);
      }
      for (local_44 = 0; local_44 < *(int *)(param_1 + 0xc); local_44 = local_44 + 1) {
        FUN_004189ff(*(undefined4 *)
                      (local_44 * 0x73c + *(int *)(param_1 + 0x108 + local_44 * 0x73c) * 4 + 0x10 +
                      param_1),
                     *(undefined4 *)
                      (local_44 * 0x73c + *(int *)(param_1 + 0x108 + local_44 * 0x73c) * 4 + 0x60 +
                      param_1),
                     *(undefined4 *)
                      (*(int *)(param_1 + 0x108 + local_44 * 0x73c) * 0x50 + local_44 * 0x73c +
                       0x10c + param_1),*(undefined4 *)(param_1 + 0x32b4));
      }
    }
  }
  if (5 < *(int *)(param_1 + 0xc)) {
    *(undefined4 *)(param_1 + 0x2c6c) = DAT_004282b0;
    uVar1 = FUN_00411187(*(undefined4 *)(param_1 + 0x2c6c));
    *(undefined4 *)(param_1 + 0x2c70) = uVar1;
    for (local_60 = 0; local_60 < *(int *)(param_1 + 0x2c6c); local_60 = local_60 + 1) {
      iVar3 = local_60 * 0x10;
      *(undefined4 *)(param_1 + 0x2b78 + local_60 * 4) = *(undefined4 *)(&DAT_004282b4 + iVar3);
      *(undefined4 *)(param_1 + 0x2bc8 + local_60 * 4) = *(undefined4 *)(&DAT_004282b8 + iVar3);
      *(undefined4 *)(param_1 + 0x2c18 + local_60 * 4) = *(undefined4 *)(&DAT_004282bc + iVar3);
      FUN_00408800();
      *(undefined4 *)(local_60 * 0x50 + 0x2c74 + param_1) = *(undefined4 *)(&DAT_004282c0 + iVar3);
      *(undefined4 *)(local_60 * 0x50 + 0x2c78 + param_1) = 1;
    }
    *(undefined4 *)(param_1 + 0x2c68) =
         *(undefined4 *)(param_1 + 0x2c18 + *(int *)(param_1 + 0x2c70) * 4);
    if (*(int *)(param_1 + 0xc) == 6) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
    FUN_00408cd0();
    if ((*(int *)(param_1 + 0x32b4) != 0) && (iVar3 = FUN_00407370(), iVar3 == 0)) {
      FUN_00407310(*(undefined4 *)(param_1 + 0x32b4),0);
    }
    for (local_58 = 0; local_58 < *(int *)(param_1 + 0xc); local_58 = local_58 + 1) {
      FUN_004189ff(*(undefined4 *)
                    (local_58 * 0x73c + *(int *)(param_1 + 0x108 + local_58 * 0x73c) * 4 + 0x10 +
                    param_1),
                   *(undefined4 *)
                    (local_58 * 0x73c + *(int *)(param_1 + 0x108 + local_58 * 0x73c) * 4 + 0x60 +
                    param_1),
                   *(undefined4 *)
                    (*(int *)(param_1 + 0x108 + local_58 * 0x73c) * 0x50 + local_58 * 0x73c + 0x10c
                    + param_1),*(undefined4 *)(param_1 + 0x32b4));
    }
  }
  return;
}


// ==== FUN_0040d6e3 @ 0040d6e3

void __fastcall FUN_0040d6e3(int param_1)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int local_1c;
  int local_8;
  
  puVar2 = &DAT_004282b0 + *(int *)(param_1 + 0x3304) * 0x51;
  if ((5 < *(int *)(param_1 + 0xc)) && (puVar2 != (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 0x2c6c) = *puVar2;
    uVar3 = FUN_00411187(*(undefined4 *)(param_1 + 0x2c6c));
    *(undefined4 *)(param_1 + 0x2c70) = uVar3;
    for (local_1c = 0; local_1c < *(int *)(param_1 + 0x2c6c); local_1c = local_1c + 1) {
      *(undefined4 *)(param_1 + 0x2b78 + local_1c * 4) = puVar2[local_1c * 4 + 1];
      *(undefined4 *)(param_1 + 0x2bc8 + local_1c * 4) = puVar2[local_1c * 4 + 2];
      *(undefined4 *)(param_1 + 0x2c18 + local_1c * 4) = puVar2[local_1c * 4 + 3];
      if ((*(int *)(local_1c * 0x50 + 0x2c74 + param_1) != 0) &&
         (*(int *)(local_1c * 0x50 + 0x2c78 + param_1) == 0)) {
        FUN_00422290(*(undefined4 *)(local_1c * 0x50 + 0x2c74 + param_1));
      }
      *(undefined4 *)(local_1c * 0x50 + 0x2c74 + param_1) = 0;
      *(undefined1 *)(local_1c * 0x50 + 0x2c7c + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2c90 + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2c94 + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2c98 + param_1) = 1;
      if (*(int *)(local_1c * 0x50 + 0x2cb4 + param_1) != 0) {
        FUN_00422290(*(undefined4 *)(local_1c * 0x50 + 0x2cb4 + param_1));
      }
      *(undefined4 *)(local_1c * 0x50 + 0x2cb4 + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2cbc + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2cc0 + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2c9c + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2ca0 + param_1) = 0;
      *(undefined4 *)(local_1c * 0x50 + 0x2c74 + param_1) = puVar2[local_1c * 4 + 4];
      *(undefined4 *)(local_1c * 0x50 + 0x2c78 + param_1) = 1;
    }
    *(undefined4 *)(param_1 + 0x2c68) =
         *(undefined4 *)(param_1 + 0x2c18 + *(int *)(param_1 + 0x2c70) * 4);
    if (*(int *)(param_1 + 0xc) == 6) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
    FUN_00408cd0();
    if (((*(int *)(param_1 + 0x32b4) != 0) && (iVar4 = FUN_00407370(), iVar4 == 0)) &&
       (psVar1 = *(short **)(param_1 + 0x32b4), psVar1 != (short *)0x0)) {
      _memset(psVar1 + 2,0,(int)psVar1[1] * (int)*psVar1);
    }
    for (local_8 = 0; local_8 < *(int *)(param_1 + 0xc); local_8 = local_8 + 1) {
      FUN_004189ff(*(undefined4 *)
                    (local_8 * 0x73c + *(int *)(param_1 + 0x108 + local_8 * 0x73c) * 4 + 0x10 +
                    param_1),
                   *(undefined4 *)
                    (local_8 * 0x73c + *(int *)(param_1 + 0x108 + local_8 * 0x73c) * 4 + 0x60 +
                    param_1),
                   *(undefined4 *)
                    (*(int *)(param_1 + 0x108 + local_8 * 0x73c) * 0x50 + local_8 * 0x73c + 0x10c +
                    param_1),*(undefined4 *)(param_1 + 0x32b4));
    }
  }
  return;
}


// ==== FUN_0040db6d @ 0040db6d

void __thiscall FUN_0040db6d(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_30;
  
  *(undefined4 *)(param_1 + 0x334c) = 1;
  *(int *)(param_1 + 0x3330) = param_2;
  *(int *)(param_1 + 0x3334) = param_3;
  *(int *)(param_1 + 0x3340) = *(int *)(param_1 + 0x32dc) << 0x10;
  *(int *)(param_1 + 0x3344) = *(int *)(param_1 + 0x32e0) << 0x10;
  iVar1 = FUN_00401054(*(int *)(param_1 + 0x3330) * 0x10000 - *(int *)(param_1 + 0x3340),0x30000);
  iVar2 = FUN_00401054(*(int *)(param_1 + 0x3334) * 0x10000 - *(int *)(param_1 + 0x3344),0x30000);
  iVar3 = FUN_00422280(iVar2 >> 0x10);
  iVar4 = FUN_00422280(iVar1 >> 0x10);
  if (iVar3 < iVar4) {
    local_30 = FUN_00422280(iVar1 >> 0x10);
  }
  else {
    local_30 = FUN_00422280(iVar2 >> 0x10);
  }
  uVar5 = FUN_00422280(local_30);
  *(undefined4 *)(param_1 + 0x3348) = uVar5;
  if (*(int *)(param_1 + 0x3348) == 0) {
    *(undefined4 *)(param_1 + 0x3338) = 0;
    *(undefined4 *)(param_1 + 0x333c) = 0;
  }
  else {
    uVar5 = FUN_00401054(param_2 * 0x10000 - *(int *)(param_1 + 0x3340),
                         *(int *)(param_1 + 0x3348) << 0x10);
    *(undefined4 *)(param_1 + 0x3338) = uVar5;
    uVar5 = FUN_00401054(param_3 * 0x10000 - *(int *)(param_1 + 0x3344),
                         *(int *)(param_1 + 0x3348) << 0x10);
    *(undefined4 *)(param_1 + 0x333c) = uVar5;
  }
  return;
}


// ==== FID_conflict:_$E31 @ 0040deb0

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_0040deca();
  FUN_0040dee4();
  return;
}


// ==== FUN_0040deca @ 0040deca

void FUN_0040deca(void)

{
  FUN_00401aa0();
  return;
}


// ==== FUN_0040dee4 @ 0040dee4

void FUN_0040dee4(void)

{
  _atexit(FUN_0040df01);
  return;
}


// ==== FUN_0040df01 @ 0040df01

void FUN_0040df01(void)

{
  FUN_00401b77();
  return;
}


// ==== FUN_0040df1b @ 0040df1b

void FUN_0040df1b(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_0042bda0 = 2;
  }
  DAT_0067ec90 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_0040df5e @ 0040df5e

void FUN_0040df5e(HWND param_1)

{
  if (DAT_0067ec90 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_0067ec90);
  }
  return;
}


// ==== FUN_0040df8f @ 0040df8f

void FUN_0040df8f(undefined4 param_1)

{
  FUN_00421be0(&DAT_0042bda8,param_1);
  return;
}


// ==== FUN_0040dfb0 @ 0040dfb0

void FUN_0040dfb0(HWND param_1)

{
  int iVar1;
  int iVar2;
  tagRECT local_38;
  tagRECT local_28;
  HWND local_18;
  tagRECT local_14;
  
  local_18 = GetParent(param_1);
  if (local_18 == (HWND)0x0) {
    local_18 = GetDesktopWindow();
  }
  GetWindowRect(local_18,&local_28);
  GetWindowRect(param_1,&local_38);
  CopyRect(&local_14,&local_28);
  OffsetRect(&local_38,-local_38.left,-local_38.top);
  OffsetRect(&local_14,-local_14.left,-local_14.top);
  OffsetRect(&local_14,-local_38.right,-local_38.bottom);
  if ((((-1 < local_28.left + local_14.right / 2) && (-1 < local_28.top + local_14.bottom / 2)) &&
      (iVar1 = local_14.right / 2, iVar2 = GetSystemMetrics(0), local_28.right - iVar1 <= iVar2)) &&
     (iVar1 = local_14.bottom / 2, iVar2 = GetSystemMetrics(1), local_28.bottom - iVar1 <= iVar2)) {
    SetWindowPos(param_1,(HWND)0x0,local_28.left + local_14.right / 2,
                 local_28.top + local_14.bottom / 2,0,0,1);
  }
  return;
}


// ==== FUN_0040e0e8 @ 0040e0e8

void FUN_0040e0e8(int param_1)

{
  if (((0 < param_1) && (param_1 < 6)) && (*(int *)(&DAT_0067fbf0 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_0067fbf0 + param_1 * 4) = 1;
    Sleep(100);
    DAT_004337a0 = 1;
    switch(param_1) {
    case 1:
      FUN_0040df8f(s_QUICKHELPBMP_0042bf64);
      FUN_0040a70d(DAT_0067ff20,s_QTIPNEWANIMAL_0042bf74,DAT_0067ffa8,FUN_0040f479);
      break;
    case 2:
      FUN_0040df8f(s_QUICKHELPBMP_0042bfc0);
      FUN_0040a70d(DAT_0067ff20,s_QHIDENTICALDIALOG_0042bfd0,DAT_0067ffa8,FUN_0040f479);
      break;
    case 3:
      FUN_0040df8f(s_QUICKHELPBMP_0042bfe4);
      FUN_0040a70d(DAT_0067ff20,s_QHBOOKDIALOG_0042bff4,DAT_0067ffa8,FUN_0040f479);
      break;
    case 4:
      FUN_0040df8f(s_QUICKHELPBMP_0042bfa0);
      FUN_0040a70d(DAT_0067ff20,s_QHCONGRATULATE_0042bfb0,DAT_0067ffa8,FUN_0040f6ef);
      break;
    case 5:
      FUN_0040df8f(s_QUICKHELPBMP_0042bf84);
      FUN_0040a70d(DAT_0067ff20,s_QTIPRESCUED_0042bf94,DAT_0067ffa8,FUN_0040f479);
    }
    DAT_004337a0 = 0;
    FUN_00411b20();
  }
  return;
}


// ==== FUN_0040e284 @ 0040e284

undefined4 FUN_0040e284(void)

{
  undefined4 uVar1;
  
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_QUICKHELPBMP_0042c004);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  uVar1 = FUN_0040a70d(DAT_0067ff20,s_EXITGAME_0042c014,DAT_0067ffa8,FUN_0040e8af);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return uVar1;
}


// ==== FUN_0040e2fc @ 0040e2fc

undefined4 FUN_0040e2fc(void)

{
  undefined4 uVar1;
  
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_QUICKHELPBMP_0042c020);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  uVar1 = FUN_0040a70d(DAT_0067ff20,s_NEWGAME_0042c030,DAT_0067ffa8,FUN_0040e8af);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return uVar1;
}


// ==== FUN_0040e374 @ 0040e374

undefined4 FUN_0040e374(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0040a70d(DAT_0067ff20,s_RESETSCORE_0042c038,param_1,FUN_00410986);
  return uVar1;
}


// ==== FUN_0040e3a9 @ 0040e3a9

void FUN_0040e3a9(void)

{
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_ABOUTBMP_0042c044);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_ABOUT_0042c050,DAT_0067ffa8,FUN_0040ea50);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e418 @ 0040e418

void FUN_0040e418(undefined4 param_1)

{
  FUN_0040a70d(DAT_0067ff20,s_CREDITS_0042c058,param_1,FUN_0040ed40);
  return;
}


// ==== FUN_0040e444 @ 0040e444

void FUN_0040e444(undefined4 param_1)

{
  FUN_0040a70d(DAT_0067ff20,s_SYSTEMINFODIALOG_0042c060,param_1,FUN_0040eedb);
  return;
}


// ==== FUN_0040e470 @ 0040e470

void FUN_0040e470(void)

{
  DAT_004337a0 = 1;
  FUN_0040df8f(s_QUICKHELPBMP_0042c074);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_QUICKHELPDIALOG_0042c084,DAT_0067ffa8,FUN_0040f91f);
  DAT_004337a0 = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e4df @ 0040e4df

void FUN_0040e4df(void)

{
  DAT_004337a0 = 1;
  FUN_0040df8f(s_QUICKHELPBMP_0042c094);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_QUICKHELPDIALOG_0042c0a4,DAT_0067ffa8,FUN_0040f91f);
  DAT_004337a0 = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e54e @ 0040e54e

void FUN_0040e54e(void)

{
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_CUPBMP_0042c0b4);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_YOURNAME_0042c0bc,DAT_0067ffa8,FUN_0040fb95);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e5bd @ 0040e5bd

void FUN_0040e5bd(void)

{
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_CUPBMP_0042c0c8);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_BALLSTOP_0042c0d0,DAT_0067ffa8,FUN_0040fede);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e62c @ 0040e62c

void FUN_0040e62c(void)

{
  DAT_0067ec9c = 1;
  FUN_0040df8f(s_OPTIONSBMP_0042c0dc);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  FUN_0040a70d(DAT_0067ff20,s_OPTIONS_0042c0e8,DAT_0067ffa8,FUN_00410265);
  DAT_0067ec9c = 0;
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e69b @ 0040e69b

void FUN_0040e69b(HWND param_1)

{
  HDC pHVar1;
  int local_20;
  int local_1c;
  tagRECT local_18;
  HGDIOBJ local_8;
  
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  GetClientRect(param_1,&local_18);
  pHVar1 = GetDC((HWND)0x0);
  local_8 = (HGDIOBJ)FUN_00416500(pHVar1,&DAT_0042bda8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00416421(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0068045c,0);
  RealizePalette(pHVar1);
  FUN_0041646a(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e7aa @ 0040e7aa

void FUN_0040e7aa(HWND param_1)

{
  HDC pHVar1;
  undefined4 uVar2;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  GetClientRect(param_1,&local_14);
  pHVar1 = GetDC((HWND)0x0);
  uVar2 = FUN_00416500(pHVar1,s_QUICKHELPBMP_0042c0f0);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00416421(uVar2,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0068045c,0);
  RealizePalette(pHVar1);
  FUN_0041646a(pHVar1,uVar2,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  InvalidateRect(DAT_00433894,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040e8af @ 0040e8af

UINT FUN_0040e8af(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ff1c = param_1;
      DAT_0067ff18 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067ff18);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0067ff1c == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0067ff1c);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0067ff1c,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0067ff1c,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
        return UVar1;
      }
      return 0;
    }
    if (param_3 == (HWND)0x1) {
      EndDialog(param_1,1);
      return 1;
    }
    if (param_3 == (HWND)0x2) {
      EndDialog(param_1,2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040ea50 @ 0040ea50

UINT FUN_0040ea50(HWND param_1,uint param_2,HWND param_3)

{
  int iVar1;
  CHAR local_20c [256];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ff30 = param_1;
      DAT_0067ff2c = GetDlgItem(param_1,100);
      FUN_0040a8a0(DAT_0067ff20,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      iVar1 = FUN_0040aa23(&DAT_0042c100,local_20c);
      if (iVar1 == 0) {
        FUN_0040aa23(s_Product_ID_0042c104,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067ff2c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0067ff30) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_0067ff30);
      SelectPalette(local_10c,DAT_0068045c,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_0067ff30,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0067ff30,(RECT *)0x0,0);
      InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
      return local_108;
    }
    switch(param_3) {
    case (HWND)0x1:
    case (HWND)0x2:
      EndDialog(param_1,0);
      return 1;
    default:
      break;
    case (HWND)0x65:
      FUN_0040e444(param_1);
      return 1;
    case (HWND)0x66:
      FUN_0040e418(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040ed40 @ 0040ed40

UINT FUN_0040ed40(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067fc08 = param_1;
      DAT_0067ece0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067ece0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0067fc08 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0067fc08);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0067fc08,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0067fc08,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ff30,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
        return UVar1;
      }
      return 0;
    }
    if ((param_3 != (HWND)0x0) && (param_3 < (HWND)0x3)) {
      EndDialog(param_1,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040eedb @ 0040eedb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040eedb(HWND param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  _MEMORYSTATUS local_4dc;
  DWORD local_4bc;
  DWORD local_4b8;
  CHAR local_4b4 [12];
  HDC local_4a8;
  DWORD local_4a4;
  uint local_4a0;
  _OSVERSIONINFOA local_49c;
  DWORD local_408;
  CHAR local_404 [1024];
  
  if (param_2 == 0x110) {
    FUN_0040dfb0(param_1);
    _DAT_00433ad0 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    uVar2 = FUN_004162d0(&DAT_0042c110,local_49c.dwMajorVersion,0xffffffff);
    FUN_00421be0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c114);
    uVar2 = FUN_004162d0(&DAT_0042c118,local_49c.dwMinorVersion,0xffffffff);
    FUN_00421bf0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c11c);
    uVar2 = FUN_004162d0(&DAT_0042c120,local_49c.dwBuildNumber & 0xffff,0xffffffff);
    FUN_00421bf0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c124);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_00421bf0(local_404,local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    uVar2 = FUN_004162d0(&DAT_0042c128,local_4dc.dwTotalPhys >> 10,0xffffffff);
    FUN_00421be0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c12c);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4[0] = local_404[0];
    local_4b4[1] = 0;
    local_4b4[2] = 0;
    local_4b4[3] = 0;
    FUN_00421be0(local_404,&DAT_0042c130);
    FUN_00421bf0(local_404,local_4b4);
    FUN_00421bf0(local_404,&DAT_0042c134);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    uVar2 = FUN_004162d0(&DAT_0042c138,local_4a0,0xffffffff);
    FUN_00421bf0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c13c);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_0042c160,s_display_drv_0042c154,s_Unknown_0042c14c,local_404,0x80,
               s_system_ini_0042c140);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    uVar2 = FUN_004162d0(&DAT_0042c174,local_4a0,0xffffffff);
    FUN_00421be0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c178);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    uVar2 = FUN_004162d0(&DAT_0042c17c,local_4a0,0xffffffff);
    FUN_00421bf0(local_404,uVar2);
    FUN_00421bf0(local_404,&DAT_0042c180);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      uVar2 = FUN_004162d0(&DAT_0042c184,1 << ((byte)local_4a0 & 0x1f),0xffffffff);
      FUN_00421bf0(local_404,uVar2);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar1 = 1 << ((byte)local_4a0 & 0x1f);
      uVar2 = FUN_004162d0(&DAT_0042c188,(int)(iVar1 + (iVar1 >> 0x1f & 0x3ffU)) >> 10,0xffffffff);
      FUN_00421bf0(local_404,uVar2);
      FUN_00421bf0(local_404,&DAT_0042c18c);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar1 = 1 << ((byte)local_4a0 & 0x1f);
        iVar1 = iVar1 + (iVar1 >> 0x1f & 0x3ffU);
        uVar2 = FUN_004162d0(&DAT_0042c194,(int)((iVar1 >> 10) + (iVar1 >> 0x1f & 0x3ffU)) >> 10,
                             0xffffffff);
        FUN_00421bf0(local_404,uVar2);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar1 = 1 << ((byte)local_4a0 & 0x1f);
        iVar1 = iVar1 + (iVar1 >> 0x1f & 3U);
        uVar2 = FUN_004162d0(&DAT_0042c190,(int)((iVar1 >> 2) + (iVar1 >> 0x1f & 3U)) >> 2,
                             0xffffffff);
        FUN_00421bf0(local_404,uVar2);
      }
      FUN_00421bf0(local_404,&DAT_0042c198);
    }
    SetDlgItemTextA(param_1,0xb6,local_404);
    ReleaseDC((HWND)0x0,local_4a8);
    uVar2 = 1;
  }
  else if (((param_2 == 0x111) && (param_3 != 0)) && (param_3 < 3)) {
    EndDialog(param_1,0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0040f479 @ 0040f479

UINT FUN_0040f479(HWND param_1,uint param_2,HWND param_3)

{
  HWND pHVar1;
  HDC hdc;
  LRESULT LVar2;
  UINT UVar3;
  uint wParam;
  WPARAM WVar4;
  LPARAM LVar5;
  
  if (param_2 < 0x111) {
    if (param_2 != 0x110) {
      if (param_2 == 0xf) {
        FUN_0040e69b(DAT_0067ecdc);
      }
      return 0;
    }
    FUN_0040dfb0(param_1);
    DAT_004337a8 = param_1;
    DAT_0067ecdc = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0042b8dc == 0);
    UVar3 = 0xf1;
    pHVar1 = GetDlgItem(param_1,0x12d);
    SendMessageA(pHVar1,UVar3,wParam,LVar5);
    return 1;
  }
  if (param_2 == 0x111) {
    if (param_3 == (HWND)0x1) {
      LVar5 = 0;
      WVar4 = 0;
      UVar3 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x12d);
      LVar2 = SendMessageA(pHVar1,UVar3,WVar4,LVar5);
      DAT_0042b8dc = (uint)(LVar2 == 0);
      FUN_0040cb92();
    }
    else if (param_3 != (HWND)0x2) {
      if (param_3 != (HWND)0x63) {
        return 0;
      }
      LVar5 = 0;
      WVar4 = 0;
      UVar3 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x12d);
      LVar2 = SendMessageA(pHVar1,UVar3,WVar4,LVar5);
      DAT_0042b8dc = (uint)(LVar2 == 0);
      FUN_0040cb92();
      EndDialog(param_1,0);
      PostMessageA(DAT_0067ffa8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_004337a8 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_004337a8);
  SelectPalette(hdc,DAT_0068045c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_004337a8,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_004337a8,(RECT *)0x0,0);
    InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040f6ef @ 0040f6ef

UINT FUN_0040f6ef(HWND param_1,uint param_2,HWND param_3)

{
  HWND pHVar1;
  HDC hdc;
  LRESULT LVar2;
  UINT UVar3;
  uint wParam;
  WPARAM wParam_00;
  LPARAM LVar4;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ff24 = param_1;
      DAT_0067ec98 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_0042b8dc == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067ec98);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0067ff24) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0067ff24);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_0067ff24,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_0067ff24,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
        return UVar3;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if (param_3 == (HWND)0x63) {
        LVar4 = 0;
        wParam_00 = 0;
        UVar3 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x12d);
        LVar2 = SendMessageA(pHVar1,UVar3,wParam_00,LVar4);
        DAT_0042b8dc = (uint)(LVar2 == 0);
        FUN_0040cb92();
        EndDialog(param_1,0);
        PostMessageA(DAT_0067ffa8,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0040f91f @ 0040f91f

UINT FUN_0040f91f(HWND param_1,uint param_2,HWND param_3)

{
  HWND pHVar1;
  HDC hdc;
  LRESULT LVar2;
  UINT UVar3;
  uint wParam;
  WPARAM WVar4;
  LPARAM LVar5;
  
  if (param_2 < 0x111) {
    if (param_2 != 0x110) {
      if (param_2 == 0xf) {
        FUN_0040e69b(DAT_00433890);
      }
      return 0;
    }
    FUN_0040dfb0(param_1);
    DAT_0067ece8 = param_1;
    DAT_00433890 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0042b8d8 == 0);
    UVar3 = 0xf1;
    pHVar1 = GetDlgItem(param_1,0x12d);
    SendMessageA(pHVar1,UVar3,wParam,LVar5);
    return 1;
  }
  if (param_2 == 0x111) {
    if (param_3 == (HWND)0x1) {
      LVar5 = 0;
      WVar4 = 0;
      UVar3 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x12d);
      LVar2 = SendMessageA(pHVar1,UVar3,WVar4,LVar5);
      DAT_0042b8d8 = (uint)(LVar2 == 0);
      FUN_0040cb92();
    }
    else if (param_3 != (HWND)0x2) {
      if (param_3 != (HWND)0x63) {
        return 0;
      }
      LVar5 = 0;
      WVar4 = 0;
      UVar3 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x12d);
      LVar2 = SendMessageA(pHVar1,UVar3,WVar4,LVar5);
      DAT_0042b8d8 = (uint)(LVar2 == 0);
      FUN_0040cb92();
      EndDialog(param_1,0);
      PostMessageA(DAT_0067ffa8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0067ece8 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0067ece8);
  SelectPalette(hdc,DAT_0068045c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0067ece8,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0067ece8,(RECT *)0x0,0);
    InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040fb95 @ 0040fb95

UINT FUN_0040fb95(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  HWND pHVar1;
  void *_Src;
  HDC hdc;
  uint uVar2;
  UINT UVar3;
  WPARAM WVar4;
  LPARAM LVar5;
  size_t _Size;
  CHAR local_108 [256];
  HIMC local_8;
  
  if (param_2 < 0x111) {
    if (param_2 != 0x110) {
      if (param_2 == 0xf) {
        FUN_0040e69b(DAT_0067ec88);
      }
      return 0;
    }
    FUN_0040dfb0(param_1);
    DAT_0067fc40 = param_1;
    DAT_0067ec88 = GetDlgItem(param_1,100);
    if (DAT_0042bda0 == 1) {
      LVar5 = 0;
      WVar4 = 0xf;
      UVar3 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0x1e);
      SendMessageA(pHVar1,UVar3,WVar4,LVar5);
    }
    else {
      LVar5 = 0;
      WVar4 = 0x14;
      UVar3 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0x1e);
      SendMessageA(pHVar1,UVar3,WVar4,LVar5);
    }
    SetDlgItemTextA(param_1,0x1e,&DAT_0042b8e8);
    _Size = 0x10;
    _Src = (void *)FUN_004162d0(&DAT_0042c19c,DAT_0042bd9c,0xffffffff);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_0067fc40 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_0067fc40);
    SelectPalette(hdc,DAT_0068045c,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_0067fc40,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_0067fc40,(RECT *)0x0,0);
      InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_0042b8e8,DAT_0042bda0 * 0x11);
  }
  else if (uVar2 != 2) {
    if (uVar2 != 0x1e) {
      return 0;
    }
    if ((uint)param_3 >> 0x10 == 0x100) {
      local_8 = ImmGetContext(param_4);
      if (local_8 == (HIMC)0x0) {
        return 0;
      }
      ImmSetOpenStatus(local_8,1);
      ImmReleaseContext(param_4,local_8);
      return 1;
    }
    if ((uint)param_3 >> 0x10 != 0x200) {
      return 0;
    }
    local_8 = ImmGetContext(param_4);
    if (local_8 == (HIMC)0x0) {
      return 0;
    }
    ImmSetOpenStatus(local_8,0);
    ImmReleaseContext(param_4,local_8);
    return 1;
  }
  EndDialog(param_1,0);
  return 1;
}


// ==== FUN_0040fede @ 0040fede

UINT FUN_0040fede(HWND param_1,uint param_2,HWND param_3)

{
  HWND pHVar1;
  uint uVar2;
  LPCSTR pCVar3;
  HDC hdc;
  UINT UVar4;
  int iVar5;
  int local_14;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ecd8 = param_1;
      DAT_0067fc3c = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_0042bea8) && (DAT_0042bea8 < 10)) {
        SetDlgItemTextA(param_1,DAT_0042bea8 + 0x33,&DAT_0042c1a0);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar5 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar5);
        uVar2 = uVar2 | 0x80;
        iVar5 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar5,uVar2);
        pCVar3 = (LPCSTR)FUN_004162d0(&DAT_0042c1a4,*(undefined4 *)(&DAT_00433430 + local_14 * 0x2c)
                                      ,0xffffffff);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00433408 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067fc3c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0067ecd8) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0067ecd8);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_0067ecd8,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_0067ecd8,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (iVar5 = FUN_0040e374(DAT_0067ecd8), iVar5 == 1)) {
        if ((-1 < DAT_0042bea8) && (DAT_0042bea8 < 10)) {
          SetDlgItemTextA(param_1,DAT_0042bea8 + 0x33,&DAT_0042c1a8);
        }
        DAT_0042bea8 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00433430 + local_14 * 0x2c) = 0;
          _memset(&DAT_00433408 + local_14 * 0x2c,0,0x28);
          pCVar3 = (LPCSTR)FUN_004162d0(&DAT_0042c1ac,
                                        *(undefined4 *)(&DAT_00433430 + local_14 * 0x2c),0xffffffff)
          ;
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00433408 + local_14 * 0x2c);
        }
        FUN_0040cb92();
      }
    }
  }
  return 0;
}


// ==== FUN_00410265 @ 00410265

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_00410265(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  HWND pHVar1;
  LPCSTR pCVar2;
  HDC hdc;
  char *pcVar3;
  int iVar4;
  LRESULT LVar5;
  UINT UVar6;
  WPARAM WVar7;
  LPARAM LVar8;
  HIMC pHVar9;
  int local_28;
  int local_1c;
  CHAR local_18 [12];
  HIMC local_c;
  HWND local_8;
  
  if (param_2 < 0x54) {
    if (param_2 == 0x53) {
      WinHelpA(DAT_0067ffa8,s_mixgen_hlp_0042ba28,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_0040e69b(DAT_0067eca4);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_0041040f:
      hdc = GetDC(DAT_0067ec70);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_0067ec70,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0067ec70,(RECT *)0x0,0);
      InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ec70 = param_1;
      DAT_0067eca4 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00427e68;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00427e6c;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0042b8e4;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      WVar7 = 2;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x61,_DAT_0042b8d4 + 0x5e);
      if (DAT_0042bda0 == 1) {
        LVar8 = 0;
        WVar7 = 0xf;
        UVar6 = 0xc5;
        pHVar1 = GetDlgItem(param_1,0x1e);
        SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      }
      else {
        LVar8 = 0;
        WVar7 = 0x14;
        UVar6 = 0xc5;
        pHVar1 = GetDlgItem(param_1,0x1e);
        SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      }
      SetDlgItemTextA(param_1,0x1e,&DAT_0042b8e8);
      pHVar9 = (HIMC)0x0;
      pHVar1 = GetDlgItem(param_1,0xf);
      DAT_0067fc44 = ImmAssociateContext(pHVar1,pHVar9);
      pCVar2 = (LPCSTR)FUN_004162d0(&DAT_0042c1b0,_DAT_0042b8d0,0xffffffff);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x10010);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_00427e68 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_00427e6c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_0042b8e4 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042b8d4 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042b8d4 = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042b8d4 = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042b8d4 = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_0042b8e8,DAT_0042bda0 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0x11; local_28 = local_28 + 1) {
          pcVar3 = (char *)FUN_004162d0(&DAT_0042c1c0,local_28,0xffffffff);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00410822:
            _DAT_0042b8d0 = local_28;
            break;
          }
          pcVar3 = (char *)FUN_004162d0(&DAT_0042c1c4,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00410822;
        }
      case 2:
        DAT_0067ec70 = (HWND)0x0;
        pHVar9 = DAT_0067fc44;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = _DAT_0042b8d0;
          for (local_28 = 1; local_28 < 0x11; local_28 = local_28 + 1) {
            pcVar3 = (char *)FUN_004162d0(&DAT_0042c1b4,local_28,0xffffffff);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_00410562:
              local_1c = local_28;
              break;
            }
            pcVar3 = (char *)FUN_004162d0(&DAT_0042c1b8,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_00410562;
          }
          pCVar2 = (LPCSTR)FUN_004162d0(&DAT_0042c1bc,local_1c,0xffffffff);
          SetDlgItemTextA(param_1,0xf,pCVar2);
        }
        break;
      case 0x1e:
        if ((uint)param_3 >> 0x10 == 0x100) {
          local_c = ImmGetContext(param_4);
          if (local_c == (HIMC)0x0) {
            return 0;
          }
          ImmSetOpenStatus(local_c,1);
          ImmReleaseContext(param_4,local_c);
          return 1;
        }
        if ((uint)param_3 >> 0x10 == 0x200) {
          local_c = ImmGetContext(param_4);
          if (local_c == (HIMC)0x0) {
            return 0;
          }
          ImmSetOpenStatus(local_c,0);
          ImmReleaseContext(param_4,local_c);
          return 1;
        }
        break;
      case 99:
        WinHelpA(DAT_0067ffa8,s_mixgen_hlp_0042ba28,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_0067ec70 == param_3) {
      return 0;
    }
    goto LAB_0041040f;
  }
  return 0;
}


// ==== FUN_00410986 @ 00410986

UINT FUN_00410986(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_0040dfb0(param_1);
      DAT_0067ff54 = param_1;
      DAT_0067eca0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040e7aa(DAT_0067eca0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0067ff54 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0067ff54);
      SelectPalette(hdc,DAT_0068045c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0067ff54,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0067ecd8,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ff54,(RECT *)0x0,0);
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
        return UVar1;
      }
      return 0;
    }
    if (param_3 == (HWND)0x1) {
      EndDialog(param_1,1);
      return 1;
    }
    if (param_3 == (HWND)0x2) {
      EndDialog(param_1,2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00410b37 @ 00410b37

void FUN_00410b37(void)

{
  FUN_00410b51();
  FUN_00410b79();
  return;
}


// ==== FUN_00410b51 @ 00410b51

void FUN_00410b51(void)

{
  _eh_vector_constructor_iterator_(&DAT_0067ecf0,0x28,0x60,FUN_004160d0,FUN_00407670);
  return;
}


// ==== FUN_00410b79 @ 00410b79

void FUN_00410b79(void)

{
  _atexit(FUN_00410b96);
  return;
}


// ==== FUN_00410b96 @ 00410b96

void FUN_00410b96(void)

{
  _eh_vector_destructor_iterator_(&DAT_0067ecf0,0x28,0x60,FUN_00407670);
  return;
}


// ==== FUN_00410bb9 @ 00410bb9

void FUN_00410bb9(void)

{
  FUN_00410bd3();
  FUN_00410bfb();
  return;
}


// ==== FUN_00410bd3 @ 00410bd3

void FUN_00410bd3(void)

{
  _eh_vector_constructor_iterator_(&DAT_0067fc48,0x28,0x12,FUN_004160d0,FUN_00407670);
  return;
}


// ==== FUN_00410bfb @ 00410bfb

void FUN_00410bfb(void)

{
  _atexit(FUN_00410c18);
  return;
}


// ==== FUN_00410c18 @ 00410c18

void FUN_00410c18(void)

{
  _eh_vector_destructor_iterator_(&DAT_0067fc48,0x28,0x12,FUN_00407670);
  return;
}


// ==== FUN_00410c3b @ 00410c3b

void FUN_00410c3b(void)

{
  FUN_00410c55();
  FUN_00410c7d();
  return;
}


// ==== FUN_00410c55 @ 00410c55

void FUN_00410c55(void)

{
  _eh_vector_constructor_iterator_(&DAT_004338a0,0x28,0xe,FUN_004160d0,FUN_00407670);
  return;
}


// ==== FUN_00410c7d @ 00410c7d

void FUN_00410c7d(void)

{
  _atexit(FUN_00410c9a);
  return;
}


// ==== FUN_00410c9a @ 00410c9a

void FUN_00410c9a(void)

{
  _eh_vector_destructor_iterator_(&DAT_004338a0,0x28,0xe,FUN_00407670);
  return;
}


// ==== FUN_00410cbd @ 00410cbd

void FUN_00410cbd(void)

{
  FUN_00410cd7();
  FUN_00410cff();
  return;
}


// ==== FUN_00410cd7 @ 00410cd7

void FUN_00410cd7(void)

{
  _eh_vector_constructor_iterator_(&DAT_004337b8,0x28,4,FUN_004160d0,FUN_00407670);
  return;
}


// ==== FUN_00410cff @ 00410cff

void FUN_00410cff(void)

{
  _atexit(FUN_00410d1c);
  return;
}


// ==== FUN_00410d1c @ 00410d1c

void FUN_00410d1c(void)

{
  _eh_vector_destructor_iterator_(&DAT_004337b8,0x28,4,FUN_00407670);
  return;
}


// ==== FUN_00410d3f @ 00410d3f

void FUN_00410d3f(HWND param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  HDC hdc;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int y;
  int x;
  int local_10;
  
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_0068045c,0);
  RealizePalette(hdc);
  if (DAT_006809cc != 0) {
    bVar7 = false;
    if ((DAT_006809e4 == 0) && (DAT_006809e8 == 0)) {
      for (local_10 = 0; local_10 < DAT_006809cc; local_10 = local_10 + 1) {
        iVar1 = *(int *)(&DAT_00680898 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_00680890 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_00680894 + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_0068088c + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_00680890 + local_10 * 0x10);
        iVar6 = *(int *)(&DAT_0068088c + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_006809f0);
        BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_006809cc = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_006809cc; local_10 = local_10 + 1) {
        if ((DAT_006809e4 <= *(int *)(&DAT_0068088c + local_10 * 0x10)) &&
           (DAT_006809e8 <= *(int *)(&DAT_00680890 + local_10 * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_10 = 0; local_10 < DAT_006809cc; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_00680890 + local_10 * 0x10) - DAT_006809e8;
          x = *(int *)(&DAT_0068088c + local_10 * 0x10) - DAT_006809e4;
          iVar1 = *(int *)(&DAT_00680898 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00680890 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00680894 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0068088c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00680890 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0068088c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_006809f0);
          BitBlt(hdc,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_006809cc; local_10 = local_10 + 1) {
          iVar1 = *(int *)(&DAT_00680898 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00680890 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00680894 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0068088c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00680890 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0068088c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_006809f0);
          BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_006809cc = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_0041116c @ 0041116c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041116c(void)

{
  _DAT_0067ec84 = GetTickCount();
  return;
}


// ==== FUN_00411187 @ 00411187

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00411187(int param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  param_1 = param_1 * ((iVar1 + _DAT_0067ec84) % 0x7fff);
  return (int)(param_1 + (param_1 >> 0x1f & 0x7fffU)) >> 0xf;
}


// ==== FUN_004111c3 @ 004111c3

void FUN_004111c3(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int local_2c;
  int local_28;
  
  if (param_1 != (int *)0x0) {
    if (param_1[4] == 3) {
      local_28 = *param_1 + 0xc;
    }
    else {
      if ((param_1[8] == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
        local_2c = 1 << (*(byte *)((int)param_1 + 0xe) & 0x1f);
      }
      else {
        local_2c = param_1[8];
      }
      local_28 = local_2c * 4 + *param_1;
    }
    local_28 = (int)param_1 + local_28;
    uVar1 = ((uint)DAT_0068046e * DAT_00680464 + 0x1f & 0xffffffe0) >> 3;
    FUN_00416a90(DAT_00680448 + (DAT_00680468 - (param_1[2] + param_3)) * uVar1 + param_2,local_28,
                 param_1[1],param_1[2],uVar1,
                 ((uint)*(ushort *)((int)param_1 + 0xe) * param_1[1] + 0x1f & 0xffffffe0) >> 3,0);
  }
  return;
}


// ==== FUN_004112f9 @ 004112f9

void FUN_004112f9(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_30;
  int local_2c;
  int local_28;
  
  if (param_1 != (int *)0x0) {
    if (param_1[4] == 3) {
      local_28 = *param_1 + 0xc;
    }
    else {
      if ((param_1[8] == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
        local_2c = 1 << (*(byte *)((int)param_1 + 0xe) & 0x1f);
      }
      else {
        local_2c = param_1[8];
      }
      local_28 = local_2c * 4 + *param_1;
    }
    local_28 = (int)param_1 + local_28;
    uVar2 = ((uint)*(ushort *)((int)DAT_0067ece4 + 0xe) * DAT_0067ece4[1] + 0x1f & 0xffffffe0) >> 3;
    if (DAT_0067ece4[4] == 3) {
      iVar1 = *DAT_0067ece4 + 0xc;
    }
    else {
      if ((DAT_0067ece4[8] == 0) && (*(ushort *)((int)DAT_0067ece4 + 0xe) < 9)) {
        local_30 = 1 << (*(byte *)((int)DAT_0067ece4 + 0xe) & 0x1f);
      }
      else {
        local_30 = DAT_0067ece4[8];
      }
      iVar1 = local_30 * 4 + *DAT_0067ece4;
    }
    FUN_00416a90((int)DAT_0067ece4 +
                 (DAT_0067ece4[2] - (param_3 + param_1[2])) * uVar2 + param_2 + iVar1,local_28,
                 param_1[1],param_1[2],uVar2,
                 ((uint)*(ushort *)((int)param_1 + 0xe) * param_1[1] + 0x1f & 0xffffffe0) >> 3,0);
  }
  return;
}


// ==== FUN_004114a7 @ 004114a7

void FUN_004114a7(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int local_2c;
  
  if (((param_1 != (int *)0x0) && (param_2[1] <= param_2[3])) && (*param_2 <= param_2[2])) {
    if (param_1[4] == 3) {
      iVar1 = *param_1 + 0xc;
    }
    else {
      if ((param_1[8] == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
        local_2c = 1 << (*(byte *)((int)param_1 + 0xe) & 0x1f);
      }
      else {
        local_2c = param_1[8];
      }
      iVar1 = local_2c * 4 + *param_1;
    }
    uVar2 = ((uint)DAT_0068046e * DAT_00680464 + 0x1f & 0xffffffe0) >> 3;
    FUN_00416a90(DAT_00680448 + (DAT_00680468 - param_2[3]) * uVar2 + *param_2,
                 (int)param_1 + (DAT_00680468 - param_2[3]) * uVar2 + *param_2 + iVar1,
                 (param_2[2] - *param_2) + 1,(param_2[3] - param_2[1]) + 1,uVar2,
                 ((uint)*(ushort *)((int)param_1 + 0xe) * param_1[1] + 0x1f & 0xffffffe0) >> 3,
                 0xffffffff);
  }
  return;
}


// ==== FUN_00411632 @ 00411632

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411632(void)

{
  int local_c;
  int local_8;
  
  FUN_004114a7(DAT_0067ece4,&DAT_0042bef0);
  FUN_004111c3(*(undefined4 *)(&DAT_0067ecb0 + (DAT_0043388c % 10) * 4),DAT_0042bef0 + 0xb,
               DAT_0042bef4);
  FUN_004111c3(*(undefined4 *)(&DAT_0067ecb0 + ((DAT_0043388c / 10) % 10) * 4),DAT_0042bef0,
               DAT_0042bef4);
  InvalidateRect(DAT_00433894,(RECT *)&DAT_0042bef0,0);
  FUN_004114a7(DAT_0067ece4,&DAT_0042bf00);
  FUN_004111c3(*(undefined4 *)(&DAT_00433778 + (DAT_0042bd94 % 10) * 4),DAT_0042bf00 + 10,
               DAT_0042bf04);
  FUN_004111c3(*(undefined4 *)(&DAT_00433778 + ((DAT_0042bd94 / 10) % 10) * 4),DAT_0042bf00,
               DAT_0042bf04);
  InvalidateRect(DAT_00433894,(RECT *)&DAT_0042bf00,0);
  FUN_004114a7(DAT_0067ece4,&DAT_0042bf10);
  local_8 = DAT_0042bd9c;
  for (local_c = 4; -1 < local_c; local_c = local_c + -1) {
    FUN_004111c3(*(undefined4 *)(&DAT_00433778 + (local_8 % 10) * 4),local_c * 10 + _DAT_0042bf10,
                 DAT_0042bf14);
    local_8 = local_8 / 10;
  }
  InvalidateRect(DAT_00433894,(RECT *)&DAT_0042bf10,0);
  return;
}


// ==== FUN_004117ed @ 004117ed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004117ed(void)

{
  int local_c;
  int local_8;
  
  FUN_004112f9(*(undefined4 *)(&DAT_0067ecb0 + (DAT_0043388c % 10) * 4),DAT_0042bef0 + 0xb,
               DAT_0042bef4);
  FUN_004112f9(*(undefined4 *)(&DAT_0067ecb0 + ((DAT_0043388c / 10) % 10) * 4),DAT_0042bef0,
               DAT_0042bef4);
  FUN_004112f9(*(undefined4 *)(&DAT_00433778 + (DAT_0042bd94 % 10) * 4),DAT_0042bf00 + 10,
               DAT_0042bf04);
  FUN_004112f9(*(undefined4 *)(&DAT_00433778 + ((DAT_0042bd94 / 10) % 10) * 4),DAT_0042bf00,
               DAT_0042bf04);
  local_8 = DAT_0042bd9c;
  for (local_c = 4; -1 < local_c; local_c = local_c + -1) {
    FUN_004112f9(*(undefined4 *)(&DAT_00433778 + (local_8 % 10) * 4),local_c * 10 + _DAT_0042bf10,
                 DAT_0042bf14);
    local_8 = local_8 / 10;
  }
  return;
}


// ==== FUN_00411936 @ 00411936

void FUN_00411936(void)

{
  undefined4 local_8;
  
  FUN_00401bf3();
  DAT_0043388c = *(undefined4 *)(DAT_0042bd94 * 4 + 0x42beac);
  FUN_004111c3(DAT_00433878,0x108,0x147);
  DAT_0042bd4c = 0;
  FUN_00411632();
  DAT_0067ff48 = 0xffffffff;
  DAT_0067ff4c = 0xffffffff;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    FUN_00402fd7();
  }
  DAT_0042bd8c = ((0x10 - DAT_0042bd94) * (0x10 - DAT_0042bd94) * -7 + 3000) / 2;
  DAT_0067fc38 = DAT_0042bd8c;
  if (DAT_0042bd48 != 0) {
    if (DAT_0067ebf4 == 1) {
      DAT_004e0dcc = 1;
    }
    else {
      FUN_00405ca3(0x36);
      FUN_004111c3(DAT_0067ff38,0x14,0x14b);
      InvalidateRect(DAT_00433894,(RECT *)0x0,0);
      DAT_0067ebf4 = 0;
      FUN_004040ad();
    }
  }
  return;
}


// ==== FUN_00411a76 @ 00411a76

void FUN_00411a76(void)

{
  if (DAT_0042bd94 == 0x10) {
    DAT_0042bd9c = DAT_0042bd9c + 50000;
  }
  if (DAT_0042bd94 < 0x10) {
    DAT_0042bd94 = DAT_0042bd94 + 1;
    DAT_0042bd9c = DAT_0042bd9c + DAT_0042bd94 * 100;
    FUN_00411936();
  }
  else {
    FUN_00411632();
    FUN_0040e0e8(4);
    SendMessageA(DAT_0067ffa8,0x465,0,0);
  }
  return;
}


// ==== FUN_00411af7 @ 00411af7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411af7(void)

{
  DAT_0042bd98 = _DAT_0042b8d0;
  DAT_0042bd94 = _DAT_0042b8d0;
  FUN_00411936();
  return;
}


// ==== FUN_00411b20 @ 00411b20

void FUN_00411b20(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_0042bd40 == 0) && (DAT_0042bd30 == 0)) && (DAT_0042bd44 == 0)) {
    SetMenu(DAT_00433894,DAT_00433898);
    if (DAT_0042b8dc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00433894);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00433894);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00433894);
  }
  else {
    SetMenu(DAT_00433894,DAT_0067ff58);
    if (DAT_0042b8dc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00433894);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00433894);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00433894);
  }
  return;
}


// ==== FUN_00411c24 @ 00411c24

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411c24(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_0042b8d0;
  iVar2 = DAT_00427e6c;
  FUN_0040e62c();
  FUN_0040cb92();
  if (DAT_00427e6c == 0) {
    FUN_00401335(0);
  }
  else if ((iVar2 == 0) && (DAT_0042bd40 == 0)) {
    if ((DAT_0042bd30 == 0) || (iVar1 != _DAT_0042b8d0)) {
      iVar2 = FUN_00411187(4);
      FUN_00401335(iVar2 + 2);
    }
    else {
      FUN_00401335(1);
    }
  }
  if (iVar1 != _DAT_0042b8d0) {
    PostMessageA(DAT_0067ffa8,0x111,0x65,0);
  }
  return;
}


// ==== FUN_00411ce7 @ 00411ce7

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_00411ce7(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  bool bVar1;
  BITMAPINFO *lpbmi;
  int cy;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  HDC pHVar6;
  HGDIOBJ pvVar7;
  UINT UVar8;
  DWORD local_12c;
  BYTE *local_128;
  DWORD local_124;
  BYTE *local_120;
  DWORD local_11c;
  BYTE *local_118;
  DWORD local_114;
  BYTE *local_110;
  undefined1 local_10c [8];
  undefined1 local_104 [8];
  undefined1 local_fc [8];
  undefined2 local_f4;
  undefined2 uStack_f2;
  int local_e4;
  int local_e0;
  HDC local_bc;
  int local_a8;
  int local_a4;
  tagPAINTSTRUCT local_a0;
  undefined *local_54;
  UINT local_4c;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_24 [5];
  BITMAPINFO *local_10;
  int local_c;
  
  local_4c = 0;
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      if (DAT_0042bd38 != 0) {
        local_bc = BeginPaint(param_1,&local_a0);
        EndPaint(param_1,&local_a0);
        return 0;
      }
      local_bc = BeginPaint(param_1,&local_a0);
      if (DAT_0042bd34 == 0) {
        SelectPalette(local_bc,DAT_0068045c,0);
        RealizePalette(local_bc);
        cy = DAT_00680450;
        iVar3 = DAT_0068044c;
        if (DAT_0042bd44 == 0) {
          if (((DAT_0042bd40 == 0) && ((DAT_0042bd2c == 0 || (DAT_0042bd30 != 0)))) &&
             (((DAT_0067ec8c != (HWND)0x0 || (DAT_0042bd30 != 0)) &&
              (((DAT_0067ec9c == 0 || (DAT_004337a0 != 0)) || (DAT_0042bd30 != 0)))))) {
            DAT_006809cc = 0;
            pHVar6 = CreateCompatibleDC(local_bc);
            pvVar7 = SelectObject(pHVar6,DAT_006809f0);
            BitBlt(local_bc,0,0,iVar3,cy,pHVar6,0,0,0xcc0020);
            SelectObject(pHVar6,pvVar7);
            DeleteDC(pHVar6);
            GdiFlush();
          }
          else {
            FUN_0041646a(local_bc,DAT_0067ec7c,0x2e,0);
            FUN_004117ed();
            lpbmi = DAT_0067ece4;
            local_10 = DAT_0067ece4;
            if ((DAT_0067ece4->bmiHeader).biClrUsed == 0) {
              (DAT_0067ece4->bmiHeader).biClrUsed = 0x100;
            }
            if ((lpbmi->bmiHeader).biCompression == 3) {
              local_118 = (BYTE *)((int)(lpbmi->bmiColors + -7) + (lpbmi->bmiHeader).biSize);
            }
            else {
              if (((lpbmi->bmiHeader).biClrUsed == 0) && ((lpbmi->bmiHeader).biBitCount < 9)) {
                local_11c = 1 << ((byte)(lpbmi->bmiHeader).biBitCount & 0x1f);
              }
              else {
                local_11c = (lpbmi->bmiHeader).biClrUsed;
              }
              local_118 = &lpbmi->bmiColors[local_11c - 10].rgbBlue + (lpbmi->bmiHeader).biSize;
            }
            StretchDIBits(local_bc,0,0x68,0x276,0x128,0,0,0x276,0x128,local_118,lpbmi,0,0xcc0020);
            if ((local_10->bmiHeader).biCompression == 3) {
              local_120 = (BYTE *)((int)(local_10->bmiColors + -7) + (local_10->bmiHeader).biSize);
            }
            else {
              if (((local_10->bmiHeader).biClrUsed == 0) && ((local_10->bmiHeader).biBitCount < 9))
              {
                local_124 = 1 << ((byte)(local_10->bmiHeader).biBitCount & 0x1f);
              }
              else {
                local_124 = (local_10->bmiHeader).biClrUsed;
              }
              local_120 = &local_10->bmiColors[local_124 - 10].rgbBlue +
                          (local_10->bmiHeader).biSize;
            }
            StretchDIBits(local_bc,0,0,0x2e,0x14a,0,0x46,0x2e,0x14a,local_120,local_10,0,0xcc0020);
            if ((local_10->bmiHeader).biCompression == 3) {
              local_128 = (BYTE *)((int)(local_10->bmiColors + -7) + (local_10->bmiHeader).biSize);
            }
            else {
              if (((local_10->bmiHeader).biClrUsed == 0) && ((local_10->bmiHeader).biBitCount < 9))
              {
                local_12c = 1 << ((byte)(local_10->bmiHeader).biBitCount & 0x1f);
              }
              else {
                local_12c = (local_10->bmiHeader).biClrUsed;
              }
              local_128 = &local_10->bmiColors[local_12c - 10].rgbBlue +
                          (local_10->bmiHeader).biSize;
            }
            StretchDIBits(local_bc,0x249,0,0x2d,0x14a,0x249,0x46,0x2d,0x14a,local_128,local_10,0,
                          0xcc0020);
            GdiFlush();
            GlobalFree(DAT_0067ece4);
            DAT_0067ece4 = (BITMAPINFO *)0x0;
            DAT_0067ece4 = (BITMAPINFO *)FUN_0041671c(s_GAMEBOX_0042c1e0);
          }
        }
        else {
          FUN_0041646a(local_bc,DAT_0067ff28,0x2e,0);
          local_24[1] = 0;
          local_24[3] = 0x276;
          local_24[2] = 0x68;
          local_24[4] = 400;
          pHVar6 = CreateCompatibleDC(local_bc);
          pvVar7 = SelectObject(pHVar6,DAT_006809f0);
          BitBlt(local_bc,0,0x68,0x277,0x129,pHVar6,0,0x68,0xcc0020);
          SelectObject(pHVar6,pvVar7);
          DeleteDC(pHVar6);
          GdiFlush();
          local_24[1] = 0;
          local_24[3] = 0x2e;
          local_24[2] = 0;
          local_24[4] = 400;
          pHVar6 = CreateCompatibleDC(local_bc);
          pvVar7 = SelectObject(pHVar6,DAT_006809f0);
          BitBlt(local_bc,0,0,0x2f,0x191,pHVar6,0,0,0xcc0020);
          SelectObject(pHVar6,pvVar7);
          DeleteDC(pHVar6);
          GdiFlush();
          local_24[1] = 0x249;
          local_24[3] = 0x276;
          local_24[2] = 0;
          local_24[4] = 400;
          pHVar6 = CreateCompatibleDC(local_bc);
          pvVar7 = SelectObject(pHVar6,DAT_006809f0);
          BitBlt(local_bc,0x249,0,0x2e,0x191,pHVar6,0x249,0,0xcc0020);
          SelectObject(pHVar6,pvVar7);
          DeleteDC(pHVar6);
          GdiFlush();
        }
      }
      else {
        SelectPalette(local_bc,DAT_00430330,0);
        RealizePalette(local_bc);
        if ((DAT_0067ece4->bmiHeader).biCompression == 3) {
          local_110 = (BYTE *)((int)(DAT_0067ece4->bmiColors + -7) +
                              (DAT_0067ece4->bmiHeader).biSize);
        }
        else {
          if (((DAT_0067ece4->bmiHeader).biClrUsed == 0) &&
             ((DAT_0067ece4->bmiHeader).biBitCount < 9)) {
            local_114 = 1 << ((byte)(DAT_0067ece4->bmiHeader).biBitCount & 0x1f);
          }
          else {
            local_114 = (DAT_0067ece4->bmiHeader).biClrUsed;
          }
          local_110 = &DAT_0067ece4->bmiColors[local_114 - 10].rgbBlue +
                      (DAT_0067ece4->bmiHeader).biSize;
        }
        StretchDIBits(local_bc,0,0,0x276,400,0,0,0x276,400,local_110,DAT_0067ece4,0,0xcc0020);
      }
      EndPaint(param_1,&local_a0);
      return 0;
    }
    switch(param_2) {
    case 1:
      FUN_00401bf3();
      FUN_0040df1b(param_1);
      break;
    case 2:
      if (DAT_0067ec6c != (HGLOBAL)0x0) {
        GlobalFree(DAT_0067ec6c);
      }
      DAT_0067ec6c = (HGLOBAL)0x0;
      if (DAT_0067ece4 != (BITMAPINFO *)0x0) {
        GlobalFree(DAT_0067ece4);
      }
      DAT_0067ece4 = (BITMAPINFO *)0x0;
      FUN_0040df5e(param_1);
      PostQuitMessage(0);
      return 0;
    case 5:
      if ((param_3 == (HWND)0x0) || (param_3 == (HWND)0x2)) {
        SendMessageA(param_1,0x46f,1,0);
      }
      break;
    case 7:
      if (DAT_0042bd70 == 0) {
        UVar8 = FUN_004211e0(param_1,param_2,param_3,param_4);
        return UVar8;
      }
      SetActiveWindow(DAT_0067ec78);
      return 0;
    }
switchD_00414648_caseD_3:
    UVar8 = FUN_004211e0(param_1,param_2,param_3,param_4);
    return UVar8;
  }
  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_0067ec8c = param_3;
      DAT_0042bd28 = 0;
      if (param_3 == (HWND)0x0) {
        FUN_0040cb92();
        if ((DAT_0042bd30 == 0) && (DAT_0042bd44 == 0)) {
          DAT_0042bd40 = 1;
        }
        FUN_00411b20();
      }
      else {
        FUN_0040c728();
      }
      DAT_0042bd2c = 0;
      if ((param_3 == (HWND)0x0) || (DAT_0042bd40 != 0)) {
        FUN_00401335(0);
      }
      else if (DAT_0042bd30 == 0) {
        iVar3 = FUN_00411187(4);
        FUN_00401335(iVar3 + 2);
      }
      else {
        FUN_00401335(1);
      }
      InvalidateRect(DAT_00433894,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x10) {
      if (DAT_0042bd38 != 0) {
        return 0;
      }
      if (DAT_0042bd34 == 0) {
        if ((DAT_0042bd30 == 0) && (DAT_0042bd44 == 0)) {
          iVar3 = FUN_0040e284();
          if (iVar3 != 1) {
            return 0;
          }
          iVar3 = FUN_0040c9b1(DAT_0042bd9c,local_24);
          if ((iVar3 != 0) && (local_24[0] < 10)) {
            if (DAT_0042b8e4 != 0) {
              FUN_0040e54e();
            }
            FUN_0040ca4e(DAT_0042bd9c);
            DAT_0042bea8 = local_24[0];
            FUN_0040e5bd();
            FUN_0040cb92();
          }
        }
        WinHelpA(param_1,s_mixgen_hlp_0042ba28,2,0);
        FUN_00421198();
        FUN_0040174d();
        DestroyWindow(param_1);
        return 0;
      }
      DAT_0042b7e4 = 1;
      DAT_0042bd3c = 1;
      FUN_00421198();
      FUN_0040174d();
      DestroyWindow(param_1);
      return 0;
    }
    goto switchD_00414648_caseD_3;
  }
  if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(400);
      GdiFlush();
      Sleep(400);
      GdiFlush();
      DeleteObject(DAT_0067ec7c);
      DeleteObject(DAT_0067ff28);
      local_bc = GetDC(DAT_00433894);
      DAT_0067ec7c = (HGDIOBJ)FUN_00416500(local_bc,s_PAUSEBMP_0042c1c8);
      DAT_0067ff28 = (HGDIOBJ)FUN_00416500(local_bc,s_GAMEOVERBMP_0042c1d4);
      ReleaseDC(DAT_00433894,local_bc);
      Sleep(100);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_0067ec94;
      *(undefined4 *)(param_4 + 0xc) = DAT_0067eca8;
      return 0;
    }
    goto switchD_00414648_caseD_3;
  }
  if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (DAT_0042bd38 != 0) {
        return 0;
      }
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_0067ffa8,6);
        return 0;
      }
      if (DAT_0042bd34 != 0) {
        DAT_0042b7e4 = 1;
        return 0;
      }
      if ((DAT_0042bd30 != 0) || (DAT_0042bd44 != 0)) {
        PostMessageA(DAT_00433894,0x111,0x65,0);
        return 0;
      }
      if (DAT_0042bd40 != 0) {
        SendMessageA(DAT_0067ffa8,0x111,0xc9,0);
        return 0;
      }
      if (param_3 == (HWND)0x2d) {
        DAT_0067ff48 = 0xffffffff;
        DAT_0067ff4c = 0xffffffff;
        iVar3 = FUN_00402fd7();
        if (iVar3 != 0) {
          FUN_00401633(0x15);
          DAT_0042bd8c = DAT_0067fc38;
          piVar4 = (int *)FUN_004026a9(local_104,0);
          local_e4 = *piVar4;
          local_e0 = piVar4[1];
          if (local_e4 < 0) {
            FUN_00401633(0x16);
          }
        }
      }
    }
    else if (param_2 == 0x86) {
      if ((param_3 != (HWND)0x0) || (DAT_0042bd34 != 0)) {
        InvalidateRect(DAT_0067ffa8,(RECT *)0x0,0);
      }
      UVar8 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
      return UVar8;
    }
    goto switchD_00414648_caseD_3;
  }
  if (0x200 < param_2) {
    if (param_2 < 0x212) {
      if (param_2 == 0x211) {
        DAT_0042bd28 = 0;
        DAT_0042bd2c = 1;
        InvalidateRect(param_1,(RECT *)0x0,1);
        return 0;
      }
      if (param_2 == 0x201) {
        if (DAT_0042bd38 != 0) {
          return 0;
        }
        if (DAT_0042bd34 != 0) {
          DAT_0042b7e4 = 1;
          return 0;
        }
        if ((DAT_0042bd30 != 0) || (DAT_0042bd44 != 0)) {
          PostMessageA(DAT_00433894,0x111,0x65,0);
          return 0;
        }
        if (DAT_0042bd40 != 0) {
          SendMessageA(DAT_0067ffa8,0x111,0xc9,0);
          return 0;
        }
        if (DAT_00433adc == -1) {
          if ((((0xc < (param_4 & 0xffff)) && ((param_4 & 0xffff) < 0x20)) &&
              (0x154 < param_4 >> 0x10)) && (param_4 >> 0x10 < 0x18b)) {
            FUN_00405ca3(0x36);
            DAT_0042bd48 = 0;
            FUN_004114a7(DAT_0067ece4,&DAT_0042bd50);
            InvalidateRect(DAT_00433894,(RECT *)&DAT_0042bd50,0);
          }
          if (((0x20 < (param_4 & 0xffff)) && ((param_4 & 0xffff) < 0x53)) &&
             ((0x154 < param_4 >> 0x10 && (param_4 >> 0x10 < 0x18b)))) {
            if (DAT_0042bd48 == 0) {
              DAT_0042bd48 = 1;
              DAT_0067ebf4 = 0;
              FUN_004111c3(DAT_0067ff38,0x14,0x14b);
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
              FUN_004040ad();
            }
            else {
              FUN_004040ad();
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
            }
            if (DAT_0042b8dc != 0) {
              FUN_0040e0e8(3);
            }
            return 0;
          }
          if (((0x53 < (param_4 & 0xffff)) && ((param_4 & 0xffff) < 0x62)) &&
             ((0x154 < param_4 >> 0x10 && (param_4 >> 0x10 < 0x18a)))) {
            if (DAT_0042bd48 == 0) {
              DAT_0042bd48 = 1;
              DAT_0067ebf4 = 0;
              FUN_004111c3(DAT_0067ff38,0x14,0x14b);
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
              DAT_0067ebf4 = (int)((param_4 >> 0x10) - 0x154) / 9;
              if (DAT_0067ebf4 < 0) {
                DAT_0067ebf4 = 0;
              }
              if (5 < DAT_0067ebf4) {
                DAT_0067ebf4 = 6;
              }
              FUN_004040ad();
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
            }
            else {
              local_3c = (int)((param_4 >> 0x10) - 0x154) / 9 + -1;
              if (local_3c < 0) {
                local_3c = 6;
              }
              if (4 < local_3c) {
                local_3c = 5;
              }
              if ((local_3c + 1) % 6 == DAT_0067ebf4) {
                return 0;
              }
              DAT_0067ebf4 = local_3c;
              FUN_004040ad();
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
            }
            if (DAT_0042b8dc != 0) {
              FUN_0040e0e8(3);
            }
            return 0;
          }
        }
        if ((((0x12f < (param_4 & 0xffff)) && ((param_4 & 0xffff) < 0x14a)) &&
            (0x91 < param_4 >> 0x10)) && (param_4 >> 0x10 < 300)) {
          if (DAT_00433adc == -1) {
            PostMessageA(DAT_00433894,0x100,0x2d,0);
          }
          return 0;
        }
        DAT_0067ff48 = (param_4 & 0xffff) - 0x1c;
        DAT_0067ff4c = param_4 >> 0x10;
        if (DAT_00433adc == -1) {
          local_38 = FUN_00403177(param_4 & 0xffff,param_4 >> 0x10);
          if (local_38 != -1) {
            DAT_00433adc = local_38;
            iVar3 = FUN_00401df5();
            if (iVar3 < 7) {
              iVar3 = DAT_00433adc * 0x3350;
              local_54 = (undefined *)(iVar3 + 0x433ae8);
              _DAT_004337ac = (param_4 & 0xffff) - *(int *)(&DAT_00436dc4 + iVar3);
              _DAT_004337b0 = (param_4 >> 0x10) - *(int *)(&DAT_00436dc8 + iVar3);
              FUN_00404add(DAT_00433adc + 0x191,DAT_00433adc);
              uVar5 = FUN_00401d9c(DAT_00433adc);
              FUN_004021a0(uVar5);
              FUN_00410d3f(param_1);
              iVar3 = FUN_00401df5();
              if (iVar3 != -1) {
                uVar5 = FUN_00401df5();
                FUN_004021f1(uVar5);
              }
              if ((DAT_0042bd4c == 0) && (local_38 = FUN_004020e0(7), local_38 != -1)) {
                FUN_00401633(0x17);
                FUN_004111c3(DAT_0043387c,0x108,0x147);
                InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                UpdateWindow(DAT_00433894);
                Sleep(0x32);
                FUN_004111c3(DAT_00433880,0x108,0x147);
                InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                UpdateWindow(DAT_00433894);
                Sleep(0x32);
                FUN_004111c3(DAT_00433884,0x108,0x147);
                InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                UpdateWindow(DAT_00433894);
                DAT_0042bd4c = 1;
              }
            }
            else {
              DAT_00433adc = -1;
            }
          }
        }
        else {
          local_a8 = FUN_00401df5();
          if (local_a8 == -1) {
            FUN_00401633(0xb);
            DAT_0042bd28 = 0;
            return 0;
          }
          local_38 = FUN_004020e0(local_a8);
          if (local_38 == -1) {
            DAT_0042bd28 = 0;
            if (local_a8 == 7) {
              FUN_00401633(0x18);
            }
            else {
              FUN_00401633(0xb);
            }
          }
          else {
            if (local_a8 == 7) {
              FUN_00401633(0xc);
              local_a4 = 0x32;
              if (DAT_0067e9e0 == -1) {
                if (DAT_004dda7c == 0) {
                  DAT_004dda7c = 1;
                }
              }
              else {
                FUN_00405ca3(DAT_0067e9e0);
                *(undefined4 *)(local_a4 * 4 + 0x67e918) = 0xffffffff;
              }
              local_54 = &DAT_004dda78;
              DAT_004ddb78 = 1;
              DAT_0042bf20 = 1;
              DAT_0043388c = DAT_0043388c + -1;
              switch(DAT_0042bd94) {
              case 1:
                DAT_0042bd9c = DAT_0042bd9c + 5;
                break;
              case 2:
                DAT_0042bd9c = DAT_0042bd9c + 10;
                break;
              case 3:
                DAT_0042bd9c = DAT_0042bd9c + 0xf;
                break;
              case 4:
                DAT_0042bd9c = DAT_0042bd9c + 0x14;
                break;
              case 5:
                DAT_0042bd9c = DAT_0042bd9c + 0x19;
                break;
              case 6:
                DAT_0042bd9c = DAT_0042bd9c + 0x1e;
                break;
              case 7:
                DAT_0042bd9c = DAT_0042bd9c + 0x28;
                break;
              case 8:
                DAT_0042bd9c = DAT_0042bd9c + 0x32;
                break;
              case 9:
                DAT_0042bd9c = DAT_0042bd9c + 0x3c;
                break;
              case 10:
                DAT_0042bd9c = DAT_0042bd9c + 100;
                break;
              case 0xb:
                DAT_0042bd9c = DAT_0042bd9c + 0x78;
                break;
              case 0xc:
                DAT_0042bd9c = DAT_0042bd9c + 200;
                break;
              case 0xd:
                DAT_0042bd9c = DAT_0042bd9c + 0xfa;
                break;
              case 0xe:
                DAT_0042bd9c = DAT_0042bd9c + 400;
                break;
              case 0xf:
                DAT_0042bd9c = DAT_0042bd9c + 0x1c2;
                break;
              default:
                DAT_0042bd9c = DAT_0042bd9c + 500;
              }
              FUN_00411632();
              if (DAT_0042b8dc != 0) {
                FUN_0040e0e8(5);
              }
            }
            FUN_004021c9(local_38,DAT_00433adc);
            local_54 = (undefined *)(DAT_00433adc * 0x3350 + 0x433ae8);
            piVar4 = (int *)FUN_00401c91(local_10c,local_a8,local_38);
            local_30 = *piVar4;
            local_2c = piVar4[1];
            if ((*(int *)((int)local_54 + 0x32dc) == local_30) &&
               (*(int *)((int)local_54 + 0x32e0) == local_2c)) {
              FUN_00404add(*(undefined4 *)((int)local_54 + 0x332c),DAT_00433adc);
            }
            else {
              FUN_00404add(DAT_00433adc + 0xc9,DAT_00433adc);
              FUN_0040db6d(local_30,local_2c);
            }
            if (local_a8 == 7) {
              local_a4 = 0x32;
              Sleep(100);
              FUN_00405ca3(*(undefined4 *)(local_a4 * 4 + 0x67e918));
              *(undefined4 *)(local_a4 * 4 + 0x67e918) = 0xffffffff;
            }
            if (DAT_0042bd4c != 0) {
              Sleep(0x32);
              if (DAT_00433adc != -1) {
                FUN_0041b3b9(*(undefined4 *)(&DAT_00436d9c + DAT_00433adc * 0x3350),0,0,0,0);
              }
              FUN_004111c3(DAT_00433880,0x108,0x147);
              if ((DAT_00433adc != -1) && (*(int *)(&DAT_00433af4 + DAT_00433adc * 0x3350) != 0)) {
                FUN_0041993e(1);
              }
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
              UpdateWindow(DAT_00433894);
              Sleep(0x32);
              if (DAT_00433adc != -1) {
                FUN_0041b3b9(*(undefined4 *)(&DAT_00436d9c + DAT_00433adc * 0x3350),0,0,0,0);
              }
              FUN_004111c3(DAT_0043387c,0x108,0x147);
              if ((DAT_00433adc != -1) && (*(int *)(&DAT_00433af4 + DAT_00433adc * 0x3350) != 0)) {
                FUN_0041993e(1);
              }
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
              UpdateWindow(DAT_00433894);
              Sleep(0x32);
              if (DAT_00433adc != -1) {
                FUN_0041b3b9(*(undefined4 *)(&DAT_00436d9c + DAT_00433adc * 0x3350),0,0,0,0);
              }
              FUN_004111c3(DAT_00433878,0x108,0x147);
              if ((DAT_00433adc != -1) && (*(int *)(&DAT_00433af4 + DAT_00433adc * 0x3350) != 0)) {
                FUN_0041993e(1);
              }
              InvalidateRect(DAT_00433894,(RECT *)0x0,0);
              UpdateWindow(DAT_00433894);
              DAT_0042bd4c = 0;
            }
            if (DAT_0043388c == 0) {
              FUN_00401633(0xd);
              FUN_00411a76();
            }
            FUN_00410d3f(param_1);
            DAT_00433adc = -1;
            if (DAT_0042bd28 != 0) {
              PostMessageA(DAT_0067ffa8,0x204,(WPARAM)param_3,param_4);
            }
            DAT_0042bd28 = 0;
          }
        }
        return 0;
      }
      if (param_2 == 0x203) {
        if (DAT_00433adc != -1) {
          DAT_0042bd28 = 1;
          PostMessageA(DAT_0067ffa8,0x201,(WPARAM)param_3,param_4);
          return 0;
        }
        DAT_0042bd28 = 0;
        return 0;
      }
      if (param_2 == 0x204) {
        DAT_0042bd28 = 0;
        if (DAT_0042bd38 != 0) {
          DAT_0042bd28 = 0;
          return 0;
        }
        if (DAT_0042bd34 == 0) {
          if ((DAT_0042bd30 == 0) && (DAT_0042bd44 == 0)) {
            if (DAT_0042bd40 == 0) {
              if (DAT_00433adc == -1) {
                local_38 = FUN_00404930(param_4 & 0xffff,param_4 >> 0x10);
                if (local_38 == 1) {
                  FUN_00401633(0xe);
                  iVar3 = DAT_00433adc * 0x3350;
                  local_54 = (undefined *)(iVar3 + 0x433ae8);
                  _DAT_004337ac = (param_4 & 0xffff) - *(int *)(&DAT_00436dc4 + iVar3);
                  _DAT_004337b0 = (param_4 >> 0x10) - *(int *)(&DAT_00436dc8 + iVar3);
                  FUN_00404add(DAT_00433adc + 0x191,DAT_00433adc);
                  FUN_00410d3f(param_1);
                  if ((DAT_0042bd4c == 0) && (local_38 = FUN_004020e0(7), local_38 != -1)) {
                    FUN_00401633(0x17);
                    FUN_004111c3(DAT_0043387c,0x108,0x147);
                    InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                    UpdateWindow(DAT_00433894);
                    Sleep(0x32);
                    FUN_004111c3(DAT_00433880,0x108,0x147);
                    InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                    UpdateWindow(DAT_00433894);
                    Sleep(0x32);
                    FUN_004111c3(DAT_00433884,0x108,0x147);
                    InvalidateRect(DAT_00433894,(RECT *)0x0,0);
                    UpdateWindow(DAT_00433894);
                    DAT_0042bd4c = 1;
                  }
                  if (DAT_0042b8dc != 0) {
                    FUN_0040e0e8(1);
                  }
                }
                else {
                  FUN_00401633(0xb);
                }
                if (local_38 == 0x22b) {
                  SendMessageA(param_1,0x465,0,0);
                }
              }
              return 0;
            }
            DAT_0042bd28 = 0;
            return 0;
          }
          PostMessageA(DAT_00433894,0x111,0x65,0);
          return 0;
        }
        DAT_0042b7e4 = 1;
        DAT_0042bd28 = 0;
        return 0;
      }
    }
    else if (param_2 < 0x310) {
      if (param_2 == 0x30f) {
LAB_00413a56:
        if (DAT_0042bd38 != 0) {
          return 0;
        }
        local_bc = GetDC(param_1);
        if (DAT_0042bd34 == 0) {
          if (DAT_0068045c != (HPALETTE)0x0) {
            SelectPalette(local_bc,DAT_0068045c,0);
            local_4c = RealizePalette(local_bc);
          }
          ReleaseDC(param_1,local_bc);
          if (local_4c != 0) {
            InvalidateRect(param_1,(RECT *)0x0,1);
            return local_4c;
          }
          return 0;
        }
        SelectPalette(local_bc,DAT_00430330,0);
        RealizePalette(local_bc);
        ReleaseDC(param_1,local_bc);
        if (local_4c != 0) {
          InvalidateRect(param_1,(RECT *)0x0,1);
        }
        InvalidateRect(param_1,(RECT *)0x0,0);
        return local_4c;
      }
      if (param_2 == 0x212) {
        DAT_0042bd28 = 0;
        DAT_0042bd2c = 0;
        InvalidateRect(param_1,(RECT *)0x0,1);
        return 0;
      }
    }
    else if (param_2 < 0x42c) {
      if (param_2 == 0x42b) {
        if (((DAT_0042bd44 == 0) && (DAT_0067ec9c == 0)) &&
           ((DAT_0042bd40 == 0 && (DAT_004337a0 == 0)))) {
          iVar3 = FUN_004064ad();
          if (iVar3 != 0) {
            FUN_00410d3f(param_1);
          }
          if ((DAT_0042bf20 != 0) && (local_54 = &DAT_004dda78, 20000 < DAT_004ddb78)) {
            DAT_0042bf20 = 0;
            FUN_00411632();
          }
          return 0;
        }
        return 0;
      }
      if (param_2 == 0x311) {
        if (DAT_0042bd34 != 0) {
          InvalidateRect(param_1,(RECT *)0x0,0);
        }
        if (param_3 != param_1) goto LAB_00413a56;
      }
    }
    else {
      if (param_2 == 0x42c) {
        if ((((DAT_0042bd44 == 0) && (DAT_0067ec9c == 0)) && (DAT_0042bd40 == 0)) &&
           (DAT_004337a0 == 0)) {
          DAT_0067ff48 = 0xffffffff;
          DAT_0067ff4c = 0xffffffff;
          FUN_00401633(0x15);
          iVar3 = FUN_00402fd7();
          if (iVar3 == 0) {
            SendMessageA(param_1,0x465,0,0);
          }
          else {
            piVar4 = (int *)FUN_004026a9(local_fc,0);
            local_e4 = *piVar4;
            local_e0 = piVar4[1];
            if (local_e4 < 0) {
              FUN_00401633(0x16);
            }
          }
          return 0;
        }
        return 0;
      }
      if (param_2 == 0x465) {
        DAT_0042bd28 = 0;
        FUN_00401633(0xf);
        DAT_0042bd44 = 1;
        FUN_00401bf3();
        FUN_00411b20();
        InvalidateRect(DAT_00433894,(RECT *)0x0,0);
        iVar3 = FUN_0040c9b1(DAT_0042bd9c,local_24);
        if ((iVar3 != 0) && (local_24[0] < 10)) {
          if (DAT_0042b8e4 != 0) {
            FUN_0040e54e();
          }
          FUN_0040ca4e(DAT_0042bd9c);
          DAT_0042bea8 = local_24[0];
          FUN_0040e5bd();
          FUN_0040cb92();
        }
      }
    }
    goto switchD_00414648_caseD_3;
  }
  if (param_2 != 0x200) {
    if (param_2 == 0x111) {
      if (DAT_0042bd38 != 0) {
        return 0;
      }
      _local_f4 = CONCAT22(uStack_f2,(short)param_3);
      uVar2 = (uint)param_3 & 0xffff;
      if (uVar2 < 0xca) {
        if (uVar2 == 0xc9) {
          if (DAT_0042bd34 != 0) {
            DAT_0042b7e4 = 1;
            return 0;
          }
          if ((DAT_0042bd30 == 0) && (DAT_0042bd44 == 0)) {
            DAT_0042bd40 = (uint)(DAT_0042bd40 == 0);
            FUN_00411b20();
            InvalidateRect(DAT_00433894,(RECT *)0x0,0);
            if (DAT_0042bd40 == 0) {
              iVar3 = FUN_00411187(4);
              FUN_00401258(iVar3 + 2);
            }
            else {
              UpdateWindow(DAT_00433894);
              FUN_004011e5();
            }
            return 0;
          }
          SendMessageA(DAT_00433894,0x111,0x65,0);
          return 0;
        }
        switch(uVar2) {
        case 0x65:
          DAT_0042bd28 = 0;
          if (DAT_0042bd34 != 0) {
            DAT_0042b7e4 = 1;
            DAT_0042bd28 = 0;
            return 0;
          }
          if ((DAT_0042bd30 == 0) && (DAT_0042bd44 == 0)) {
            iVar3 = FUN_0040e2fc();
            if (iVar3 != 1) {
              return 0;
            }
            iVar3 = FUN_0040c9b1(DAT_0042bd9c,local_24);
            if ((iVar3 != 0) && (local_24[0] < 10)) {
              if (DAT_0042b8e4 != 0) {
                FUN_0040e54e();
              }
              FUN_0040ca4e(DAT_0042bd9c);
              DAT_0042bea8 = local_24[0];
              FUN_0040e5bd();
              FUN_0040cb92();
            }
          }
          InvalidateRect(DAT_00433894,(RECT *)0x0,0);
          DAT_0042bd44 = 0;
          DAT_0042bd40 = 0;
          DAT_0042bd30 = 0;
          FUN_00411b20();
          iVar3 = FUN_00411187(4);
          FUN_00401335(iVar3 + 2);
          DAT_0042bd9c = 0;
          FUN_00411af7();
          FUN_00410d3f(param_1);
          _memset(&DAT_0067fbf0,0,0x18);
          if (DAT_0042b8d8 != 0) {
            PostMessageA(DAT_00433894,0x111,0x130,0);
          }
          return 0;
        case 0x66:
          DAT_0042bea8 = 0xffffffff;
          FUN_0040e5bd();
          return 0;
        case 0x67:
          PostMessageA(param_1,0x10,0,0);
          return 0;
        case 0x68:
          FUN_00411c24();
          return 0;
        }
      }
      else if (uVar2 < 0x13c) {
        if (uVar2 == 0x13b) {
          FUN_0040e4df();
          return 0;
        }
        switch(uVar2) {
        case 300:
          FUN_00402622();
          SendMessageA(param_1,0x465,0,0);
          return 0;
        case 0x12e:
          FUN_0040e3a9();
          return 0;
        case 0x12f:
          WinHelpA(param_1,s_mixgen_hlp_0042ba28,0xb,0);
          return 0;
        case 0x130:
          FUN_0040e470();
          return 0;
        case 0x131:
          DAT_0042b8dc = (uint)(DAT_0042b8dc == 0);
          FUN_00411b20();
          return 0;
        }
      }
      else if ((uVar2 == 0x24e) && (FUN_00401633(0x19), DAT_0042b8dc != 0)) {
        FUN_0040e0e8(2);
      }
    }
    else if (param_2 == 0x113) {
      if (param_3 != (HWND)0xa) {
        if ((DAT_0042bd40 == 0) && (DAT_0067ec8c != (HWND)0x0)) {
          FUN_00401515();
        }
        return 0;
      }
      KillTimer(DAT_00433894,10);
      if (DAT_0067ec9c == 0) {
        FUN_0040e4df();
      }
      return 0;
    }
    goto switchD_00414648_caseD_3;
  }
  if (DAT_0042bd34 != 0) {
    return 0;
  }
  if (DAT_0042bd40 != 0) {
    return 0;
  }
  if (DAT_00433adc == -1) {
    return 0;
  }
  iVar3 = DAT_00433adc * 0x3350;
  local_54 = (undefined *)(iVar3 + 0x433ae8);
  local_34 = (param_4 & 0xffff) - _DAT_004337ac;
  if (local_34 < 0) {
    local_34 = 0;
  }
  if (*(int *)(&DAT_00436d9c + iVar3) == 0) {
LAB_0041356e:
    local_c = 0;
  }
  else {
    if (*(int *)(&DAT_00436d9c + iVar3) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00436d9c + iVar3) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00436d9c + iVar3) + 6) *
          (int)*(short *)(*(int *)(&DAT_00436d9c + iVar3) + 8) -
          *(int *)(*(int *)(&DAT_00436d9c + iVar3) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041356e;
    local_c = (int)**(short **)(&DAT_00436d9c + iVar3);
  }
  if (0x275 - local_c < local_34) {
    local_34 = 0x275 - local_c;
  }
  local_40 = (param_4 >> 0x10) - _DAT_004337b0;
  if (local_40 < 0) {
    local_40 = 0;
  }
  if (*(int *)(&DAT_00436d9c + iVar3) != 0) {
    if (*(int *)(&DAT_00436d9c + iVar3) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00436d9c + iVar3) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00436d9c + iVar3) + 6) *
          (int)*(short *)(*(int *)(&DAT_00436d9c + iVar3) + 8) -
          *(int *)(*(int *)(&DAT_00436d9c + iVar3) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_c = (int)*(short *)(*(int *)(&DAT_00436d9c + iVar3) + 2);
      goto LAB_004136ac;
    }
  }
  local_c = 0;
LAB_004136ac:
  if (399 - local_c < local_40) {
    local_40 = 399 - local_c;
  }
  FUN_0040637b(local_34,local_40);
  FUN_00410d3f(param_1);
  return 0;
}


// ==== FUN_00414805 @ 00414805

int FUN_00414805(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_00414826 @ 00414826

int FUN_00414826(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(1);
  if (iVar1 < 0x1e1) {
    iVar1 = 0;
  }
  else {
    iVar1 = GetSystemMetrics(1);
    iVar1 = (iVar1 - param_1) / 2;
  }
  return iVar1;
}


// ==== FUN_00414861 @ 00414861

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ATOM FUN_00414861(undefined4 param_1)

{
  ATOM AVar1;
  
  _DAT_0067fc10 = 8;
  _DAT_0067fc14 = FUN_00411ce7;
  _DAT_0067fc18 = 0;
  _DAT_0067fc1c = 0;
  _DAT_0067fc20 = param_1;
  _DAT_0067fc28 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_0067fc2c = GetStockObject(5);
  _DAT_0067fc24 = DAT_0067ff34;
  _DAT_0067fc30 = 0;
  _DAT_0067fc34 = PTR_s_MixGenWindow_0042bd74;
  AVar1 = RegisterClassA((WNDCLASSA *)&DAT_0067fc10);
  return AVar1;
}


// ==== FUN_004148f9 @ 004148f9

undefined4 FUN_004148f9(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_MixGenWindow_0042bd74,(LPCSTR)0x0);
  if (hWnd == (HWND)0x0) {
    uVar2 = 0;
  }
  else {
    hWnd_00 = GetLastActivePopup(hWnd);
    BVar1 = IsIconic(hWnd);
    if (BVar1 != 0) {
      ShowWindow(hWnd,9);
    }
    SetForegroundWindow(hWnd_00);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00414976 @ 00414976

bool FUN_00414976(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_004149cc @ 004149cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_004149cc(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  HCURSOR hCursor;
  HDC pHVar4;
  HGDIOBJ pvVar5;
  BOOL BVar6;
  int local_64;
  int local_60;
  tagMSG local_5c;
  HDC local_3c;
  uint local_30;
  HCURSOR local_28;
  HDC local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_20 = 0;
  local_1c = 0;
  DAT_0067ff20 = param_1;
  iVar2 = FUN_004148f9();
  if (iVar2 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_MixGenGameMtx_0042c1e8);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_5c.wParam = 0;
    }
    else {
      iVar2 = FUN_00414976(0x600000);
      if (iVar2 == 0) {
        local_5c.wParam = 0;
      }
      else {
        local_24 = GetDC((HWND)0x0);
        iVar2 = GetDeviceCaps(local_24,0xc);
        if (iVar2 < 8) {
          ReleaseDC((HWND)0x0,local_24);
          local_5c.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_24);
          DAT_0067ff34 = LoadIconA(param_1,s_mainicon_0042c1f8);
          hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
          local_28 = SetCursor(hCursor);
          FUN_0040ab3d();
          FUN_0040abd7(s_MIXGEN_DLL_0042bb28);
          FUN_0040ad85(s_MIXGEN1_DLL_0042bc28);
          FUN_0040ab55(s_MSPuzzle_dat_0042b918);
          FUN_0040ad85(s_mixgen_hlp_0042ba28);
          FUN_0040a96a();
          FUN_0040a984(DAT_0067ff20);
          FUN_0040a9c3(s_MIXGEN1_DLL_0042bc28);
          FUN_0040a9c3(s_MIXGEN_DLL_0042bb28);
          iVar2 = FUN_00414861(param_1);
          if (iVar2 == 0) {
            SetCursor(local_28);
            local_5c.wParam = 0;
          }
          else {
            FUN_0040c728();
            FUN_00401964();
            InitCommonControls();
            iVar2 = FUN_004152e6(param_1);
            if (iVar2 == 0) {
              FUN_0040174d();
              SetCursor(local_28);
              local_5c.wParam = 0;
            }
            else {
              iVar2 = FUN_004150d8(param_1,param_4);
              if (iVar2 == 0) {
                SetCursor(local_28);
                FUN_00421198();
                FUN_0040174d();
                local_5c.wParam = 0;
              }
              else {
                DAT_0042bd98 = _DAT_0042b8d0;
                DAT_0042bd94 = _DAT_0042b8d0;
                SetCursor(local_28);
                SetTimer(DAT_00433894,1,100,(TIMERPROC)0x0);
                DAT_0067ece4 = (int *)FUN_0041671c(s_TITLEBMP_0042c204);
                if (DAT_0067ece4 == (int *)0x0) {
                  FUN_0040174d();
                  local_5c.wParam = 0;
                }
                else {
                  FUN_00411b20();
                  if (DAT_0067ece4[4] == 3) {
                    local_60 = *DAT_0067ece4 + 0xc;
                  }
                  else {
                    if ((DAT_0067ece4[8] == 0) && (*(ushort *)((int)DAT_0067ece4 + 0xe) < 9)) {
                      local_64 = 1 << (*(byte *)((int)DAT_0067ece4 + 0xe) & 0x1f);
                    }
                    else {
                      local_64 = DAT_0067ece4[8];
                    }
                    local_60 = local_64 * 4 + *DAT_0067ece4;
                  }
                  local_60 = (int)DAT_0067ece4 + local_60;
                  FUN_0040c29c(s_PROMPT_0042c210,local_60,DAT_0067ece4 + 10);
                  DAT_0042bd34 = 0;
                  if (DAT_0042bd3c == 0) {
                    local_3c = GetDC(DAT_00433894);
                    iVar2 = GetDeviceCaps(local_3c,0x18);
                    local_30 = (uint)(0x100 < iVar2);
                    if (local_30 == 0) {
                      if (DAT_006809d4 == 64000) {
                        local_18 = 0;
                        local_10 = DAT_0068044c;
                        local_14 = 0;
                        local_c = DAT_00680450;
                      }
                      else {
                        local_18 = DAT_006809d4;
                        local_14 = DAT_006809d8;
                        local_10 = DAT_006809dc;
                        local_c = DAT_006809e0;
                      }
                      FUN_0041f155(&local_18,0);
                      iVar1 = DAT_00680450;
                      iVar2 = DAT_0068044c;
                      DAT_006809cc = 0;
                      pHVar4 = CreateCompatibleDC(local_3c);
                      pvVar5 = SelectObject(pHVar4,DAT_006809f0);
                      BitBlt(local_3c,0,0,iVar2,iVar1,pHVar4,0,0,0xcc0020);
                      SelectObject(pHVar4,pvVar5);
                      DeleteDC(pHVar4);
                      GdiFlush();
                    }
                    FUN_0041bf92(DAT_0067ec6c);
                    SelectPalette(local_3c,DAT_0068045c,0);
                    RealizePalette(local_3c);
                    FUN_0041c39f(0,0,DAT_0067ec6c,0xffff);
                    iVar1 = DAT_00680450;
                    iVar2 = DAT_0068044c;
                    DAT_006809cc = 0;
                    pHVar4 = CreateCompatibleDC(local_3c);
                    pvVar5 = SelectObject(pHVar4,DAT_006809f0);
                    BitBlt(local_3c,0,0,iVar2,iVar1,pHVar4,0,0,0xcc0020);
                    SelectObject(pHVar4,pvVar5);
                    DeleteDC(pHVar4);
                    GdiFlush();
                    ReleaseDC(DAT_00433894,local_3c);
                  }
                  if (DAT_0042bd3c == 0) {
                    GlobalFree(DAT_0067ece4);
                    DAT_0067ece4 = (int *)0x0;
                    DAT_0067ece4 = (int *)FUN_0041671c(s_GAMEBOX_0042c218);
                    PostMessageA(DAT_00433894,0x464,0,0);
                    PostMessageA(DAT_00433894,0x111,0x65,0);
                    local_3c = GetDC(DAT_00433894);
                    DAT_0067ec7c = FUN_00416500(local_3c,s_PAUSEBMP_0042c220);
                    DAT_0067ff28 = FUN_00416500(local_3c,s_GAMEOVERBMP_0042c22c);
                    ReleaseDC(DAT_00433894,local_3c);
                    while( true ) {
                      while (BVar6 = PeekMessageA(&local_5c,(HWND)0x0,0,0,1), BVar6 == 0) {
                        if (DAT_0067ec8c == 0) {
                          WaitMessage();
                        }
                        else {
                          DAT_0042bd8c = DAT_0042bd8c + -1;
                          if (DAT_0042bd8c < 1) {
                            DAT_0042bd8c = DAT_0067fc38;
                            SendMessageA(DAT_00433894,0x42c,0,0);
                          }
                          SendMessageA(DAT_00433894,0x42b,0,0);
                          Sleep(5);
                        }
                      }
                      if (local_5c.message == 0x12) break;
                      if ((DAT_00433894 == (HWND)0x0) ||
                         (iVar2 = TranslateAcceleratorA(DAT_00433894,DAT_0067ec80,&local_5c),
                         iVar2 == 0)) {
                        TranslateMessage(&local_5c);
                        DispatchMessageA(&local_5c);
                      }
                    }
                  }
                  else {
                    DAT_0042bd38 = 1;
                    local_5c.wParam = 0;
                  }
                  FUN_0040174d();
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_5c.wParam = 0;
  }
  return local_5c.wParam;
}


// ==== FUN_004150d8 @ 004150d8

undefined4 FUN_004150d8(undefined4 param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HWND pHVar7;
  HMENU pHVar8;
  HINSTANCE pHVar9;
  LPVOID pvVar10;
  byte local_88;
  CHAR local_84 [128];
  
  DAT_00433898 = FUN_0040a83e(DAT_0067ff20,s_MainMenuPlayed_0042c238);
  DAT_0067ff58 = (HMENU)FUN_0040a83e(DAT_0067ff20,s_MainMenu_0042c248);
  DAT_0067ec80 = FUN_0040a77b(param_1,s_ACCELERATORS_1_0042c254);
  if (DAT_0067ec80 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_0040a8a0(DAT_0067ff20,100,local_84,0x78);
    DVar2 = GetVersion();
    local_88 = (byte)DVar2;
    if (local_88 < 4) {
      iVar3 = GetSystemMetrics(5);
      DAT_0067ec94 = iVar3 * 2 + 0x276;
      iVar3 = GetSystemMetrics(6);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_0067eca8 = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_0067ec94;
      iVar4 = DAT_0067eca8;
      pHVar8 = DAT_0067ff58;
      pHVar9 = DAT_0067ff20;
      iVar5 = FUN_00414826(DAT_0067eca8);
      iVar6 = FUN_00414805(DAT_0067ec94);
      DAT_00433894 = CreateWindowExA(0,PTR_s_MixGenWindow_0042bd74,local_84,0xca0000,iVar6,iVar5,
                                     iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    else {
      iVar3 = GetSystemMetrics(7);
      DAT_0067ec94 = iVar3 * 2 + 0x276;
      iVar3 = GetSystemMetrics(8);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_0067eca8 = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_0067ec94;
      iVar4 = DAT_0067eca8;
      pHVar8 = DAT_0067ff58;
      pHVar9 = DAT_0067ff20;
      iVar5 = FUN_00414826(DAT_0067eca8);
      iVar6 = FUN_00414805(DAT_0067ec94);
      DAT_00433894 = CreateWindowExA(0x100,PTR_s_MixGenWindow_0042bd74,local_84,0xca0000,iVar6,iVar5
                                     ,iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    DAT_0067ffa8 = DAT_00433894;
    if (DAT_00433894 == (HWND)0x0) {
      uVar1 = 0;
    }
    else {
      ShowWindow(DAT_00433894,5);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_004152e6 @ 004152e6

/* WARNING: Removing unreachable block (ram,0x0041587d) */
/* WARNING: Removing unreachable block (ram,0x00415da6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004152e6(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_34;
  int local_2c;
  int local_24;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  
  DAT_0067ec6c = FUN_0041671c(s_GAMEBOX_0042c264);
  if (DAT_0067ec6c == 0) {
    uVar1 = 0;
  }
  else {
    FUN_00421020(DAT_0067ec6c,param_1,1);
    DAT_006809e4 = 0x276;
    DAT_0067ff38 = FUN_0041671c(s_BOOKOPENBMP_0042c26c);
    DAT_00433878 = FUN_0041671c(s_DOOR00_0042c278);
    DAT_0043387c = FUN_0041671c(s_DOOR01_0042c280);
    DAT_00433880 = FUN_0041671c(s_DOOR02_0042c288);
    DAT_00433884 = FUN_0041671c(s_DOOR03_0042c290);
    for (local_c = 1; local_c < 7; local_c = local_c + 1) {
      uVar1 = FUN_004162d0(s_BOOKMARK_0042c298,local_c,1);
      uVar1 = FUN_0041671c(uVar1);
      *(undefined4 *)(local_c * 4 + 0x433858) = uVar1;
    }
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      uVar1 = FUN_004162d0(s_DIGITBMP_0042c2a4,local_c,1);
      uVar1 = FUN_0041671c(uVar1);
      *(undefined4 *)(&DAT_00433778 + local_c * 4) = uVar1;
    }
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      uVar1 = FUN_004162d0(s_BDIGITBMP_0042c2b0,local_c,1);
      uVar1 = FUN_0041671c(uVar1);
      *(undefined4 *)(&DAT_0067ecb0 + local_c * 4) = uVar1;
    }
    for (local_c = 0; local_c < 6; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(int *)(&DAT_0067ed0c + local_10 * 0x28 + local_c * 0x280) =
             local_c * 100 + local_10 + 0x834;
        *(undefined4 *)(&DAT_0067ed10 + local_10 * 0x28 + local_c * 0x280) = 2;
        *(undefined4 *)(&DAT_0067ed14 + local_10 * 0x28 + local_c * 0x280) = 0;
        FUN_004161f0();
        *(undefined4 *)(&DAT_00428690 + local_10 * 0x144 + local_c * 0x798) =
             *(undefined4 *)(&DAT_0067ecf0 + local_10 * 0x28 + local_c * 0x280);
        if (local_10 == 5) {
          for (local_14 = 1; local_14 < *(int *)(local_c * 0x798 + 0x428cd4);
              local_14 = local_14 + 1) {
            *(int *)(&DAT_0067ed0c + (local_14 + 5) * 0x28 + local_c * 0x280) =
                 local_c * 100 + local_14 + 0x839;
            *(undefined4 *)(&DAT_0067ed10 + (local_14 + 5) * 0x28 + local_c * 0x280) = 2;
            *(undefined4 *)(&DAT_0067ed14 + (local_14 + 5) * 0x28 + local_c * 0x280) = 0;
            FUN_004161f0();
            *(undefined4 *)(local_c * 0x798 + 0x428ce4 + local_14 * 0x10) =
                 *(undefined4 *)(&DAT_0067ecf0 + (local_14 + 5) * 0x28 + local_c * 0x280);
          }
        }
      }
    }
    for (local_c = 1; local_c < 3; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(int *)(&DAT_0067fc64 + local_10 * 0x28 + local_c * 0xf0) =
             (local_c * 3 + -3) * 2 + local_10 + 3000;
        *(undefined4 *)(&DAT_0067fc68 + local_10 * 0x28 + local_c * 0xf0) = 2;
        *(undefined4 *)(&DAT_0067fc6c + local_10 * 0x28 + local_c * 0xf0) = 0;
        FUN_004161f0();
        *(undefined4 *)(&DAT_004282c0 + local_10 * 0x10 + local_c * 0x144) =
             (&DAT_0067fc48)[local_c * 0x3c + local_10 * 10];
      }
    }
    _DAT_0067fc64 = 0xbc4;
    _DAT_0067fc68 = 2;
    _DAT_0067fc6c = 0;
    FUN_004161f0();
    _DAT_004282c0 = DAT_0067fc48;
    for (local_c = 0; local_c < 0xe; local_c = local_c + 1) {
      *(int *)(&DAT_004338bc + local_c * 0x28) = local_c + 0xc1c;
      *(undefined4 *)(&DAT_004338c0 + local_c * 0x28) = 2;
      *(undefined4 *)(&DAT_004338c4 + local_c * 0x28) = 0;
      FUN_004161f0();
      *(undefined4 *)(&DAT_00428178 + local_c * 0x10) =
           *(undefined4 *)(&DAT_004338a0 + local_c * 0x28);
    }
    if (-1 < DAT_004d73e4) {
      DAT_004d74dc = DAT_00428168;
      DAT_004d74e0 = FUN_00411187(DAT_00428168);
      for (local_24 = 0; local_24 < DAT_004d74dc; local_24 = local_24 + 1) {
        iVar2 = local_24 * 0x10;
        *(undefined4 *)(&DAT_004d73e8 + local_24 * 4) = *(undefined4 *)(&DAT_0042816c + iVar2);
        *(undefined4 *)(&DAT_004d7438 + local_24 * 4) = *(undefined4 *)(&DAT_00428170 + iVar2);
        *(undefined4 *)(&DAT_004d7488 + local_24 * 4) = *(undefined4 *)(&DAT_00428174 + iVar2);
        FUN_00416170();
        FUN_004073f0();
        *(undefined4 *)(&DAT_004d750c + local_24 * 0x50) = 0;
        *(undefined4 *)(&DAT_004d7510 + local_24 * 0x50) = 0;
        *(undefined4 *)(&DAT_004d74e4 + local_24 * 0x50) = *(undefined4 *)(&DAT_00428178 + iVar2);
        *(undefined4 *)(&DAT_004d74e8 + local_24 * 0x50) = 1;
      }
      DAT_004d74d8 = *(undefined4 *)(&DAT_004d7488 + DAT_004d74e0 * 4);
      if (DAT_004d73e4 == 0) {
        DAT_004d73e4 = 1;
      }
      FUN_00408cd0();
      if ((DAT_004da68c != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
        FUN_00407310(DAT_004da68c,0);
      }
      for (local_1c = 0; local_1c < DAT_004d73e4; local_1c = local_1c + 1) {
        FUN_004189ff(*(undefined4 *)
                      (&DAT_004d73e8 + local_1c * 0x73c + (&DAT_004d74e0)[local_1c * 0x1cf] * 4),
                     *(undefined4 *)
                      (&DAT_004d7438 + local_1c * 0x73c + (&DAT_004d74e0)[local_1c * 0x1cf] * 4),
                     *(undefined4 *)
                      (&DAT_004d74e4 + (&DAT_004d74e0)[local_1c * 0x1cf] * 0x50 + local_1c * 0x73c),
                     DAT_004da68c);
      }
    }
    DAT_004da6b4 = 300;
    DAT_004da6e0 = 300;
    DAT_004da6b8 = 0xb5;
    DAT_004da6e4 = 0xb5;
    DAT_004d73dc = 1;
    DAT_004da704 = 0;
    DAT_004d73e0 = 0;
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      *(int *)(&DAT_004337d4 + local_c * 0x28) = local_c + 0xce4;
      *(undefined4 *)(&DAT_004337d8 + local_c * 0x28) = 2;
      *(undefined4 *)(&DAT_004337dc + local_c * 0x28) = 0;
      if ((*(int *)(&DAT_004337d8 + local_c * 0x28) != 0) &&
         (*(int *)(&DAT_004337b8 + local_c * 0x28) == 0)) {
        if (*(int *)(&DAT_004337dc + local_c * 0x28) == 0) {
          if (*(int *)(&DAT_004337d8 + local_c * 0x28) == 1) {
            uVar1 = FUN_004167dd(local_c * 0x28 + 0x4337c0);
            *(undefined4 *)(&DAT_004337b8 + local_c * 0x28) = uVar1;
          }
          else {
            uVar1 = FUN_004167dd(*(undefined4 *)(&DAT_004337d4 + local_c * 0x28));
            *(undefined4 *)(&DAT_004337b8 + local_c * 0x28) = uVar1;
          }
          if (*(int *)(&DAT_004337b8 + local_c * 0x28) != 0) {
            *(undefined4 *)(&DAT_004337bc + local_c * 0x28) = 1;
          }
        }
        else if (*(int *)(&DAT_004337b8 + local_c * 0x28) != 0) {
          *(undefined4 *)(&DAT_004337bc + local_c * 0x28) = 0;
        }
      }
      *(undefined4 *)(&DAT_00428030 + local_c * 0x10) =
           *(undefined4 *)(&DAT_004337b8 + local_c * 0x28);
    }
    if (-1 < DAT_004dda84) {
      DAT_004ddb7c = DAT_00428020;
      DAT_004ddb80 = FUN_00411187(DAT_00428020);
      for (local_34 = 0; local_34 < DAT_004ddb7c; local_34 = local_34 + 1) {
        iVar2 = local_34 * 0x10;
        *(undefined4 *)(&DAT_004dda88 + local_34 * 4) = *(undefined4 *)(&DAT_00428024 + iVar2);
        *(undefined4 *)(&DAT_004ddad8 + local_34 * 4) = *(undefined4 *)(&DAT_00428028 + iVar2);
        *(undefined4 *)(&DAT_004ddb28 + local_34 * 4) = *(undefined4 *)(&DAT_0042802c + iVar2);
        FUN_00408800();
        *(undefined4 *)(&DAT_004ddb84 + local_34 * 0x50) = *(undefined4 *)(&DAT_00428030 + iVar2);
        *(undefined4 *)(&DAT_004ddb88 + local_34 * 0x50) = 1;
      }
      DAT_004ddb78 = *(undefined4 *)(&DAT_004ddb28 + DAT_004ddb80 * 4);
      if (DAT_004dda84 == 0) {
        DAT_004dda84 = 1;
      }
      FUN_00408cd0();
      if ((DAT_004e0d2c != 0) && (iVar2 = FUN_00407370(), iVar2 == 0)) {
        FUN_00407310(DAT_004e0d2c,0);
      }
      for (local_2c = 0; local_2c < DAT_004dda84; local_2c = local_2c + 1) {
        FUN_004189ff(*(undefined4 *)
                      (&DAT_004dda88 + local_2c * 0x73c + (&DAT_004ddb80)[local_2c * 0x1cf] * 4),
                     *(undefined4 *)
                      (&DAT_004ddad8 + local_2c * 0x73c + (&DAT_004ddb80)[local_2c * 0x1cf] * 4),
                     *(undefined4 *)
                      (&DAT_004ddb84 + (&DAT_004ddb80)[local_2c * 0x1cf] * 0x50 + local_2c * 0x73c),
                     DAT_004e0d2c);
      }
    }
    DAT_004e0d54 = 0x6b;
    DAT_004e0d80 = 0x6b;
    DAT_004e0d58 = 0x155;
    DAT_004e0d84 = 0x155;
    DAT_004dda7c = 0;
    DAT_004e0da4 = 0;
    DAT_004dda80 = 0;
    DAT_0067ebf4 = 0;
    DAT_004e0dcc = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_004160d0 @ 004160d0

undefined4 * __fastcall FUN_004160d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  *unaff_FS_OFFSET = uVar1;
  return param_1;
}


// ==== FUN_00416170 @ 00416170

void __fastcall FUN_00416170(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_00422290(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  return;
}


// ==== FUN_004161f0 @ 004161f0

undefined4 __fastcall FUN_004161f0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[8] == 0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    if (param_1[9] == 0) {
      if (param_1[8] == 1) {
        iVar2 = FUN_004167dd(param_1 + 2);
        *param_1 = iVar2;
      }
      else {
        iVar2 = FUN_004167dd(param_1[7]);
        *param_1 = iVar2;
      }
      if (*param_1 == 0) {
        return 0;
      }
      param_1[1] = 1;
    }
    else {
      if (*param_1 == 0) {
        return 0;
      }
      param_1[1] = 0;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_004162d0 @ 004162d0

undefined * FUN_004162d0(undefined4 param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_00421be0(&DAT_006803b8,param_1);
  sVar1 = _strlen(&DAT_006803b8);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_006803b7)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_006803b8)[param_3 + sVar1] = 0;
  return &DAT_006803b8;
}


// ==== FUN_00416399 @ 00416399

void FUN_00416399(int param_1)

{
  if (param_1 == 0) {
    DAT_0067ff60 = GetDC(DAT_0067ffa8);
  }
  else {
    DAT_0067ff60 = BeginPaint(DAT_0067ffa8,(LPPAINTSTRUCT)&DAT_0067ff68);
  }
  return;
}


// ==== FUN_004163df @ 004163df

void FUN_004163df(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_0067ffa8,DAT_0067ff60);
  }
  else {
    EndPaint(DAT_0067ffa8,(PAINTSTRUCT *)&DAT_0067ff68);
  }
  return;
}


// ==== FUN_00416421 @ 00416421

bool FUN_00416421(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_1 != (HANDLE)0x0) {
    GetObjectA(param_1,0x18,local_1c);
    *param_2 = local_18;
    *param_3 = local_14;
  }
  return param_1 != (HANDLE)0x0;
}


// ==== FUN_0041646a @ 0041646a

bool FUN_0041646a(HDC param_1,HANDLE param_2,int param_3,int param_4)

{
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  HDC local_c;
  HGDIOBJ local_8;
  
  if (param_2 != (HANDLE)0x0) {
    GetObjectA(param_2,0x18,local_24);
    local_c = CreateCompatibleDC(param_1);
    local_8 = SelectObject(local_c,param_2);
    BitBlt(param_1,param_3,param_4,local_20,local_1c,local_c,0,0,0xcc0020);
    SelectObject(local_c,local_8);
    DeleteDC(local_c);
  }
  return param_2 != (HANDLE)0x0;
}


// ==== FUN_00416500 @ 00416500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP FUN_00416500(HDC param_1,undefined4 param_2)

{
  DWORD DVar1;
  HGLOBAL hResData;
  LPVOID _Src;
  HGLOBAL hMem;
  HPALETTE hPal;
  int local_28;
  SIZE_T local_10;
  BITMAPINFOHEADER *local_c;
  HBITMAP local_8;
  
  hResData = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_2,2,&local_10);
  if (hResData == (HGLOBAL)0x0) {
    local_8 = (HBITMAP)0x0;
  }
  else {
    _Src = LockResource(hResData);
    hMem = GlobalAlloc(2,local_10);
    if (hMem == (HGLOBAL)0x0) {
      FreeResource(hResData);
      local_8 = (HBITMAP)0x0;
    }
    else {
      local_c = GlobalLock(hMem);
      FID_conflict__memcpy(local_c,_Src,0x2c);
      if (local_c->biClrUsed == 0) {
        local_c->biClrUsed = 0x100;
      }
      DVar1 = local_c->biClrUsed;
      FID_conflict__memcpy(local_c,_Src,local_10);
      if (local_c->biBitCount == 8) {
        _DAT_0042c2c0 = 0;
        _DAT_0067ffb0 = 0x300;
        _DAT_0067ffb2 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_0067ffb4)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_0067ffb5)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_0067ffb6)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_0067ffb7)[local_28 * 4] = 0;
        }
        if (DAT_0042c2bc == (HPALETTE)0x0) {
          DAT_0042c2bc = CreatePalette((LOGPALETTE *)&DAT_0067ffb0);
        }
      }
      hPal = SelectPalette(param_1,DAT_0068045c,0);
      RealizePalette(param_1);
      local_8 = CreateDIBitmap(param_1,local_c,4,&local_c[1].biSize + DVar1,(BITMAPINFO *)local_c,0)
      ;
      if (hPal != (HPALETTE)0x0) {
        SelectPalette(param_1,hPal,0);
      }
      GlobalUnlock(hMem);
      GlobalFree(hMem);
      FreeResource(hResData);
    }
  }
  return local_8;
}


// ==== FUN_0041671c @ 0041671c

HGLOBAL FUN_0041671c(undefined4 param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_1,2,&local_c);
  if (hResData == (HGLOBAL)0x0) {
    hMem = (HGLOBAL)0x0;
  }
  else {
    _Src = LockResource(hResData);
    hMem = GlobalAlloc(0x40,local_c);
    if (hMem == (HGLOBAL)0x0) {
      FreeResource(hResData);
      hMem = (HGLOBAL)0x0;
    }
    else {
      local_8 = GlobalLock(hMem);
      FID_conflict__memcpy(local_8,_Src,local_c);
      if (*(int *)((int)local_8 + 0x20) == 0) {
        *(undefined4 *)((int)local_8 + 0x20) = 0x100;
      }
      FreeResource(hResData);
    }
  }
  return hMem;
}


// ==== FUN_004167dd @ 004167dd

LPVOID FUN_004167dd(undefined4 param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  undefined1 local_8 [4];
  
  hResData = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_1,s_SPRITE_0042c2c4,local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_0041682f @ 0041682f

LPVOID FUN_0041682f(undefined4 param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  undefined1 local_8 [4];
  
  hResData = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_1,s_SPRFONT_0042c2cc,local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_00416881 @ 00416881

undefined2 * FUN_00416881(undefined4 param_1)

{
  HGLOBAL hResData;
  undefined2 *puVar1;
  LPVOID _Src;
  HGLOBAL hMem;
  undefined1 *local_38;
  int local_34;
  undefined1 *local_30;
  int local_2c;
  SIZE_T local_10;
  LPVOID local_c;
  int local_8;
  
  hResData = (HGLOBAL)FUN_0040a368(DAT_0067ff20,param_1,2,&local_10);
  if (hResData == (HGLOBAL)0x0) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    _Src = LockResource(hResData);
    hMem = GlobalAlloc(0x40,local_10);
    if (hMem == (HGLOBAL)0x0) {
      FreeResource(hResData);
      puVar1 = (undefined2 *)0x0;
    }
    else {
      local_c = GlobalLock(hMem);
      FID_conflict__memcpy(local_c,_Src,local_10);
      FreeResource(hResData);
      local_10 = *(int *)((int)local_c + 4) * *(int *)((int)local_c + 8) + 4;
      puVar1 = GlobalAlloc(0x40,local_10);
      if (hMem == (HGLOBAL)0x0) {
        GlobalFree((HGLOBAL)0x0);
        puVar1 = (undefined2 *)0x0;
      }
      else {
        *puVar1 = (short)*(undefined4 *)((int)local_c + 4);
        puVar1[1] = (short)*(undefined4 *)((int)local_c + 8);
        local_30 = (undefined1 *)
                   ((int)puVar1 + (*(int *)((int)local_c + 8) + -1) * *(int *)((int)local_c + 4) + 4
                   );
        if (*(int *)((int)local_c + 0x20) == 0) {
          *(undefined4 *)((int)local_c + 0x20) = 0x100;
        }
        local_38 = (undefined1 *)((int)local_c + *(int *)((int)local_c + 0x20) * 4 + 0x28);
        local_8 = (*(int *)((int)local_c + 4) + 3U & 0xfffffffc) - *(int *)((int)local_c + 4);
        for (local_2c = 0; local_2c < *(int *)((int)local_c + 8); local_2c = local_2c + 1) {
          for (local_34 = 0; local_34 < *(int *)((int)local_c + 4); local_34 = local_34 + 1) {
            *local_30 = *local_38;
            local_38 = local_38 + 1;
            local_30 = local_30 + 1;
          }
          local_38 = local_38 + local_8;
          local_30 = local_30 + *(int *)((int)local_c + 4) * -2;
        }
        GlobalFree(hMem);
      }
    }
  }
  return puVar1;
}


// ==== FUN_00416a90 @ 00416a90

/* WARNING: Removing unreachable block (ram,0x00416aee) */
/* WARNING: Removing unreachable block (ram,0x00416b21) */

void FUN_00416a90(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
                 byte param_7)

{
  char *pcVar1;
  char cVar2;
  undefined3 uVar5;
  int iVar3;
  int iVar4;
  uint uVar6;
  int iVar7;
  
  if (param_3 != 0) {
    iVar3 = (uint)param_7 << 8;
    do {
      for (uVar6 = param_3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        cVar2 = *param_2;
        uVar5 = (undefined3)((uint)iVar3 >> 8);
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_00416af6;
LAB_00416ace:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_00416aff;
LAB_00416ad5:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_00416b09;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_00416b24;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_00416ace;
LAB_00416af6:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_00416ad5;
LAB_00416aff:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_00416b09:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_00416ae3;
          }
        }
LAB_00416ae3:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_00416b24:
      if ((param_3 & 3) != 0) {
        iVar7 = (param_3 & 3) + 1;
        pcVar1 = param_1;
        while (param_1 = pcVar1, iVar7 = iVar7 + -1, iVar7 != 0) {
          cVar2 = *param_2;
          iVar4 = CONCAT31((int3)((uint)iVar3 >> 8),cVar2);
          param_2 = param_2 + 1;
          uVar6 = (uint)iVar3 >> 8;
          iVar3 = iVar4;
          pcVar1 = param_1 + 1;
          if (cVar2 != (char)uVar6) {
            *param_1 = cVar2;
          }
        }
      }
      param_2 = param_2 + (param_6 - param_3);
      param_1 = param_1 + (param_5 - param_3);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== FUN_00416b4c @ 00416b4c

void FUN_00416b4c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
                 int param_6)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uVar1 = param_3 >> 2;
    do {
      for (; uVar2 = param_3 & 3, uVar1 != 0; uVar1 = uVar1 - 1) {
        *param_1 = *param_2;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      param_2 = (undefined4 *)((int)param_2 + (param_6 - param_3));
      param_1 = (undefined4 *)((int)param_1 + (param_5 - param_3));
      param_4 = param_4 + -1;
      uVar1 = param_3 >> 2;
    } while (param_4 != 0);
  }
  return;
}


// ==== FUN_00416b96 @ 00416b96

void FUN_00416b96(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
                 int param_6,int param_7,int param_8)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042d256 = param_4;
    do {
      for (uVar4 = DAT_0042d256 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *param_2;
        if (*param_3 != '\0') goto LAB_00416c10;
LAB_00416bdc:
        uVar3 = param_2[1];
        if (param_3[1] != '\0') goto LAB_00416c1c;
LAB_00416be6:
        uVar3 = param_2[2];
        if (param_3[2] != '\0') goto LAB_00416c29;
        while (uVar3 = param_2[3], param_3[3] != '\0') {
          while( true ) {
            param_1[3] = uVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_00416c48;
            uVar3 = *param_2;
            if (*param_3 == '\0') goto LAB_00416bdc;
LAB_00416c10:
            *param_1 = uVar3;
            uVar3 = param_2[1];
            if (param_3[1] == '\0') goto LAB_00416be6;
LAB_00416c1c:
            param_1[1] = uVar3;
            uVar3 = param_2[2];
            if (param_3[2] == '\0') break;
LAB_00416c29:
            param_1[2] = uVar3;
            uVar3 = param_2[3];
            if (param_3[3] == '\0') goto LAB_00416bfa;
          }
        }
LAB_00416bfa:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00416c48:
      if ((DAT_0042d256 & 3) != 0) {
        iVar5 = (DAT_0042d256 & 3) + 1;
        puVar2 = param_1;
        while (param_1 = puVar2, iVar5 = iVar5 + -1, iVar5 != 0) {
          uVar3 = *param_2;
          cVar1 = *param_3;
          param_2 = param_2 + 1;
          param_3 = param_3 + 1;
          puVar2 = param_1 + 1;
          if (cVar1 != '\0') {
            *param_1 = uVar3;
          }
        }
      }
      param_2 = param_2 + (param_7 - param_4);
      param_1 = param_1 + (param_6 - param_4);
      param_3 = param_3 + (param_8 - param_4);
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_00416c7d @ 00416c7d

void FUN_00416c7d(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
                 int param_6,int param_7,int param_8,char param_9)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042d256 = param_4;
    do {
      for (uVar4 = DAT_0042d256 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar1 = *param_2;
        if (*param_3 == param_9) goto LAB_00416cfd;
LAB_00416cc5:
        uVar1 = param_2[1];
        if (param_3[1] == param_9) goto LAB_00416d0a;
LAB_00416cd0:
        uVar1 = param_2[2];
        if (param_3[2] == param_9) goto LAB_00416d18;
        while (uVar1 = param_2[3], param_3[3] == param_9) {
          while( true ) {
            param_1[3] = uVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_00416d38;
            uVar1 = *param_2;
            if (*param_3 != param_9) goto LAB_00416cc5;
LAB_00416cfd:
            *param_1 = uVar1;
            uVar1 = param_2[1];
            if (param_3[1] != param_9) goto LAB_00416cd0;
LAB_00416d0a:
            param_1[1] = uVar1;
            uVar1 = param_2[2];
            if (param_3[2] != param_9) break;
LAB_00416d18:
            param_1[2] = uVar1;
            uVar1 = param_2[3];
            if (param_3[3] != param_9) goto LAB_00416ce6;
          }
        }
LAB_00416ce6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00416d38:
      if ((DAT_0042d256 & 3) != 0) {
        iVar5 = (DAT_0042d256 & 3) + 1;
        puVar3 = param_1;
        while (param_1 = puVar3, iVar5 = iVar5 + -1, iVar5 != 0) {
          uVar1 = *param_2;
          cVar2 = *param_3;
          param_2 = param_2 + 1;
          param_3 = param_3 + 1;
          puVar3 = param_1 + 1;
          if (cVar2 == param_9) {
            *param_1 = uVar1;
          }
        }
      }
      param_2 = param_2 + (param_7 - param_4);
      param_1 = param_1 + (param_6 - param_4);
      param_3 = param_3 + (param_8 - param_4);
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_00416d6e @ 00416d6e

void FUN_00416d6e(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    DAT_0042d256 = param_2 & 3;
    uVar1 = param_2 >> 2;
    do {
      for (; uVar2 = DAT_0042d256, uVar1 != 0; uVar1 = uVar1 - 1) {
        *param_1 = CONCAT22(CONCAT11(param_5,param_5),CONCAT11(param_5,param_5));
        param_1 = param_1 + 1;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)param_1 = param_5;
        param_1 = (undefined4 *)((int)param_1 + 1);
      }
      param_1 = (undefined4 *)((int)param_1 + (param_4 - param_2));
      param_3 = param_3 + -1;
      uVar1 = param_2 >> 2;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_00416dc6 @ 00416dc6

/* WARNING: Removing unreachable block (ram,0x00416e22) */
/* WARNING: Removing unreachable block (ram,0x00416e55) */

void FUN_00416dc6(undefined1 *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6
                 ,undefined1 param_7)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    do {
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_00416e2a;
LAB_00416e02:
        if (param_2[1] != '\0') goto LAB_00416e33;
LAB_00416e09:
        if (param_2[2] != '\0') goto LAB_00416e3d;
        while (param_2[3] != '\0') {
          while( true ) {
            param_1[3] = param_7;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar3 = uVar3 - 1;
            if (uVar3 == 0) goto LAB_00416e58;
            if (*param_2 == '\0') goto LAB_00416e02;
LAB_00416e2a:
            *param_1 = param_7;
            if (param_2[1] == '\0') goto LAB_00416e09;
LAB_00416e33:
            param_1[1] = param_7;
            if (param_2[2] == '\0') break;
LAB_00416e3d:
            param_1[2] = param_7;
            if (param_2[3] == '\0') goto LAB_00416e17;
          }
        }
LAB_00416e17:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_00416e58:
      if ((param_3 & 3) != 0) {
        iVar4 = (param_3 & 3) + 1;
        puVar2 = param_1;
        while (param_1 = puVar2, iVar4 = iVar4 + -1, iVar4 != 0) {
          cVar1 = *param_2;
          param_2 = param_2 + 1;
          puVar2 = param_1 + 1;
          if (cVar1 != '\0') {
            *param_1 = param_7;
          }
        }
      }
      param_2 = param_2 + (param_6 - param_3);
      param_1 = param_1 + (param_5 - param_3);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== FUN_00416e80 @ 00416e80

void FUN_00416e80(void)

{
  byte in_AH;
  undefined4 unaff_ESI;
  
  if (in_AH < DAT_0042d263) {
    if (DAT_0042d262 == '\0') {
      return;
    }
    DAT_0042d25e = unaff_ESI;
    DAT_0042d262 = 0;
    return;
  }
  if (DAT_0042d262 == '\x01') {
    return;
  }
  DAT_0042d25a = unaff_ESI;
  DAT_0042d262 = 1;
  return;
}


// ==== FUN_00416ec4 @ 00416ec4

/* WARNING: Removing unreachable block (ram,0x00416fcd) */

void FUN_00416ec4(char *param_1,char *param_2,char *param_3,int param_4,uint param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  char cVar1;
  uint uVar2;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  int extraout_ECX_02;
  int iVar3;
  int extraout_ECX_03;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  char *pcVar4;
  char *pcVar5;
  
  if (param_5 != 0) {
    DAT_0042d262 = 0;
    DAT_0042d25a = param_3;
    DAT_0042d25e = param_4;
    param_9 = param_9 - param_5;
    DAT_0042d256 = param_5;
    do {
      for (uVar2 = DAT_0042d256 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        if (*param_2 != '\0') goto LAB_00416f62;
LAB_00416f2a:
        if (param_2[1] != '\0') goto LAB_00416f76;
LAB_00416f31:
        if (param_2[2] != '\0') goto LAB_00416f8c;
        while (param_2[3] != '\0') {
          while( true ) {
            FUN_00416e80();
            if (param_3[3] != '\0') {
              param_1[3] = param_3[3];
            }
            param_1 = param_1 + 4;
            param_3 = param_3 + 4;
            param_2 = param_2 + 4;
            DAT_0042d25a = DAT_0042d25a + 4;
            DAT_0042d25e = DAT_0042d25e + 4;
            uVar2 = extraout_ECX_02 - 1;
            param_6 = extraout_EDX_02;
            if (uVar2 == 0) goto LAB_00416fd0;
            if (*param_2 == '\0') goto LAB_00416f2a;
LAB_00416f62:
            FUN_00416e80();
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
            uVar2 = extraout_ECX;
            param_6 = extraout_EDX;
            if (param_2[1] == '\0') goto LAB_00416f31;
LAB_00416f76:
            FUN_00416e80();
            if (param_3[1] != '\0') {
              param_1[1] = param_3[1];
            }
            uVar2 = extraout_ECX_00;
            param_6 = extraout_EDX_00;
            if (param_2[2] == '\0') break;
LAB_00416f8c:
            FUN_00416e80();
            if (param_3[2] != '\0') {
              param_1[2] = param_3[2];
            }
            uVar2 = extraout_ECX_01;
            param_6 = extraout_EDX_01;
            if (param_2[3] == '\0') goto LAB_00416f3f;
          }
        }
LAB_00416f3f:
        param_1 = param_1 + 4;
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        DAT_0042d25a = DAT_0042d25a + 4;
        DAT_0042d25e = DAT_0042d25e + 4;
      }
LAB_00416fd0:
      if ((DAT_0042d256 & 3) != 0) {
        iVar3 = (DAT_0042d256 & 3) + 1;
        pcVar4 = param_3;
        pcVar5 = param_1;
        while (param_1 = pcVar5, param_3 = pcVar4, iVar3 = iVar3 + -1, iVar3 != 0) {
          cVar1 = *param_2;
          pcVar4 = param_3 + 1;
          pcVar5 = param_1 + 1;
          param_2 = param_2 + 1;
          DAT_0042d25a = DAT_0042d25a + 1;
          DAT_0042d25e = DAT_0042d25e + 1;
          if (cVar1 != '\0') {
            FUN_00416e80();
            iVar3 = extraout_ECX_03;
            param_6 = extraout_EDX_03;
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
          }
        }
      }
      param_3 = param_3 + param_9;
      param_1 = param_1 + (param_7 - param_5);
      param_2 = param_2 + (param_8 - param_5);
      DAT_0042d25a = DAT_0042d25a + param_9;
      DAT_0042d25e = DAT_0042d25e + param_9;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}


// ==== FUN_00417029 @ 00417029

void FUN_00417029(char *param_1,char *param_2,byte *param_3,uint param_4,int param_5,int param_6,
                 int param_7,int param_8,byte param_9,char param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_4 != 0) {
    DAT_0042d256 = param_4;
    do {
      for (uVar2 = DAT_0042d256 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        cVar1 = *param_2;
        if ((cVar1 != param_10) && (param_9 <= *param_3)) goto LAB_004170c0;
LAB_0041707c:
        cVar1 = param_2[1];
        if ((cVar1 != param_10) && (param_9 <= param_3[1])) goto LAB_004170d0;
LAB_0041708a:
        cVar1 = param_2[2];
        if ((cVar1 != param_10) && (param_9 <= param_3[2])) goto LAB_004170e1;
        while ((cVar1 = param_2[3], cVar1 != param_10 && (param_9 <= param_3[3]))) {
          while( true ) {
            param_1[3] = cVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_00417104;
            cVar1 = *param_2;
            if ((cVar1 == param_10) || (*param_3 < param_9)) goto LAB_0041707c;
LAB_004170c0:
            *param_1 = cVar1;
            cVar1 = param_2[1];
            if ((cVar1 == param_10) || (param_3[1] < param_9)) goto LAB_0041708a;
LAB_004170d0:
            param_1[1] = cVar1;
            cVar1 = param_2[2];
            if ((cVar1 == param_10) || (param_3[2] < param_9)) break;
LAB_004170e1:
            param_1[2] = cVar1;
            cVar1 = param_2[3];
            if ((cVar1 == param_10) || (param_3[3] < param_9)) goto LAB_004170a6;
          }
        }
LAB_004170a6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00417104:
      if ((DAT_0042d256 & 3) != 0) {
        iVar3 = (DAT_0042d256 & 3) + 1;
        pbVar4 = param_3;
        pcVar5 = param_1;
        while (param_1 = pcVar5, param_3 = pbVar4, iVar3 = iVar3 + -1, iVar3 != 0) {
          cVar1 = *param_2;
          param_2 = param_2 + 1;
          pcVar5 = param_1 + 1;
          pbVar4 = param_3 + 1;
          if ((cVar1 != param_10) && (param_9 <= *param_3)) {
            *param_1 = cVar1;
          }
        }
      }
      param_2 = param_2 + (param_7 - param_4);
      param_1 = param_1 + (param_6 - param_4);
      param_3 = param_3 + (param_8 - param_4);
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}


// ==== FUN_00417140 @ 00417140

undefined * FUN_00417140(void)

{
  return &DAT_0042c2d4;
}


// ==== FUN_00417146 @ 00417146

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417146(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 uStack_14;
  
  param_1 = param_1 + _DAT_0042c2d8;
  param_3 = param_3 + _DAT_0042c2d8;
  iVar4 = param_3;
  iVar2 = param_2 + _DAT_0042c2dc;
  iVar3 = param_4 + _DAT_0042c2dc;
  if (param_3 < param_1) {
    iVar4 = param_1;
    param_1 = param_3;
    iVar2 = param_4 + _DAT_0042c2dc;
    iVar3 = param_2 + _DAT_0042c2dc;
  }
  if ((DAT_0042c2e0 <= iVar4) && (param_1 <= DAT_0042c2e4)) {
    if (iVar2 < iVar3) {
      if (iVar3 < DAT_0042c2e8) {
        return;
      }
      if (DAT_0042c2ec < iVar2) {
        return;
      }
      if ((param_1 < DAT_0042c2e0) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_0042c2e0) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - param_1)) + iVar3, param_1 = DAT_0042c2e0,
         DAT_0042c2ec < iVar2)) {
        return;
      }
      if ((DAT_0042c2e4 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0042c2e4 - param_1) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - param_1)) + iVar2, iVar4 = DAT_0042c2e4,
         iVar3 < DAT_0042c2e8)) {
        return;
      }
      if ((iVar2 < DAT_0042c2e8) &&
         (param_1 = (int)(((longlong)(iVar3 - DAT_0042c2e8) * (longlong)(param_1 - iVar4)) /
                         (longlong)-(iVar2 - iVar3)) + iVar4, iVar2 = DAT_0042c2e8,
         DAT_0042c2e4 < param_1)) {
        return;
      }
      if ((DAT_0042c2ec < iVar3) &&
         (iVar4 = (int)(((longlong)(DAT_0042c2ec - iVar2) * (longlong)(iVar4 - param_1)) /
                       (longlong)(iVar3 - iVar2)) + param_1, iVar3 = DAT_0042c2ec,
         iVar4 < DAT_0042c2e0)) {
        return;
      }
    }
    else {
      if (DAT_0042c2ec < iVar3) {
        return;
      }
      if (iVar2 < DAT_0042c2e8) {
        return;
      }
      if ((param_1 < DAT_0042c2e0) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_0042c2e0) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - param_1)) + iVar3, param_1 = DAT_0042c2e0,
         iVar2 < DAT_0042c2e8)) {
        return;
      }
      if ((DAT_0042c2e4 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0042c2e4 - param_1) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - param_1)) + iVar2, iVar4 = DAT_0042c2e4,
         DAT_0042c2ec < iVar3)) {
        return;
      }
      if ((iVar3 < DAT_0042c2e8) &&
         (iVar4 = (int)(((longlong)(iVar2 - DAT_0042c2e8) * (longlong)(iVar4 - param_1)) /
                       (longlong)(iVar2 - iVar3)) + param_1, iVar3 = DAT_0042c2e8,
         iVar4 < DAT_0042c2e0)) {
        return;
      }
      if ((DAT_0042c2ec < iVar2) &&
         (param_1 = (int)(((longlong)(DAT_0042c2ec - iVar3) * (longlong)(param_1 - iVar4)) /
                         (longlong)(iVar2 - iVar3)) + iVar4, iVar2 = DAT_0042c2ec,
         DAT_0042c2e4 < param_1)) {
        return;
      }
    }
    if (param_1 == iVar4) {
      iVar4 = iVar2;
      if (iVar3 <= iVar2) {
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      puVar9 = (undefined1 *)(DAT_0042c2f0 * iVar4 + param_1 + _DAT_0042c2d4);
      for (iVar4 = (iVar3 - iVar4) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *puVar9 = param_5;
        puVar9 = puVar9 + DAT_0042c2f0;
      }
    }
    else if (iVar2 == iVar3) {
      uVar6 = (iVar4 - param_1) + 1;
      puVar10 = (undefined4 *)(DAT_0042c2f0 * iVar2 + param_1 + _DAT_0042c2d4);
      uVar1 = CONCAT11(param_5,param_5);
      uStack_14 = CONCAT22(uVar1,uVar1);
      uVar5 = (ushort)uVar6;
      if (uVar5 != 0) {
        puVar11 = puVar10;
        if ((uVar6 & 1) != 0) {
          puVar11 = (undefined4 *)((int)puVar10 + 1);
          *(undefined1 *)puVar10 = param_5;
        }
        iVar4 = CONCAT22((short)(uVar6 >> 0x10),uVar5 >> 2);
        if (uVar5 >> 2 != 0) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar11 = uStack_14;
            puVar11 = puVar11 + 1;
          }
        }
        if ((uVar5 >> 1 & 1) != 0) {
          *(undefined2 *)puVar11 = uVar1;
        }
      }
    }
    else {
      DAT_0042c2f4 = DAT_0042c2f0;
      uVar6 = iVar4 - param_1;
      uVar8 = iVar3 - iVar2;
      if (iVar3 < iVar2) {
        DAT_0042c2f4 = -DAT_0042c2f0;
        uVar8 = -uVar8;
      }
      iVar4 = DAT_0042c2f4;
      if ((short)uVar6 < (short)uVar8) {
        puVar9 = (undefined1 *)(DAT_0042c2f0 * iVar2 + param_1 + _DAT_0042c2d4);
        uVar6 = (uint)(((ulonglong)uVar6 << 0x20) / (ulonglong)uVar8);
        iVar2 = uVar8 + 1;
        uVar8 = 0x80000000;
        do {
          *puVar9 = param_5;
          bVar12 = CARRY4(uVar8,uVar6);
          uVar8 = uVar8 + uVar6;
          puVar9 = puVar9 + (uint)bVar12 + iVar4;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else {
        iVar3 = (int)(CONCAT44(uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) / (ulonglong)uVar6);
        iVar7 = uVar6 + 1;
        uVar6 = iVar3 * 2 - (uint)(iVar3 < 0);
        uVar8 = 0x80000000;
        puVar9 = (undefined1 *)(DAT_0042c2f0 * iVar2 + param_1 + _DAT_0042c2d4);
        do {
          while( true ) {
            *puVar9 = param_5;
            bVar12 = CARRY4(uVar8,uVar6);
            uVar8 = uVar8 + uVar6;
            if (bVar12) break;
            iVar7 = iVar7 + -1;
            puVar9 = puVar9 + 1;
            if (iVar7 == 0) {
              return;
            }
          }
          puVar9 = puVar9 + 1 + iVar4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
  }
  return;
}


// ==== FUN_0041744e @ 0041744e

void FUN_0041744e(int param_1,byte *param_2,int param_3)

{
  do {
    *param_2 = *(byte *)(param_1 + (uint)*param_2);
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


// ==== FUN_0041746f @ 0041746f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041746f(ushort *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  ushort *puVar12;
  ushort *puVar13;
  undefined4 *puVar14;
  ushort *puVar15;
  ushort *puVar16;
  bool bVar17;
  
  DAT_0042d200 = 0x7fffffff;
  DAT_0042d204 = 0;
  DAT_0042d1f8 = 0x7fffffff;
  DAT_0042d1fc = 0;
  if (param_3 != 0) {
    piVar10 = param_2;
    do {
      piVar1 = piVar10 + 1;
      DAT_0042d1fc = *piVar10 + _DAT_0042c2d8;
      if (DAT_0042d1fc <= DAT_0042d1f8) {
        DAT_0042d1f8 = DAT_0042d1fc;
      }
      piVar10 = piVar10 + 2;
      iVar2 = *piVar1 + _DAT_0042c2dc;
      if (iVar2 <= DAT_0042d200) {
        DAT_0042d200 = iVar2;
      }
      if (iVar2 <= DAT_0042d204) {
        DAT_0042d204 = iVar2;
      }
    } while ((int)piVar10 <= (int)(param_2 + (param_3 + -1) * 2));
    if ((((DAT_0042d1f8 <= DAT_0042c2e4) && (DAT_0042c2e0 <= DAT_0042d1fc)) &&
        (DAT_0042d200 <= DAT_0042c2ec)) && (DAT_0042c2e8 <= DAT_0042d204)) {
      if (DAT_0042d200 <= DAT_0042c2e8) {
        DAT_0042d200 = DAT_0042c2e8;
      }
      if (DAT_0042c2ec <= DAT_0042d204) {
        DAT_0042d204 = DAT_0042c2ec;
      }
      iVar2 = DAT_0042c2e4 + 1;
      piVar10 = &DAT_0042c2f8;
      for (iVar4 = ((DAT_0042d204 - DAT_0042d200) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar2;
        piVar10 = piVar10 + 1;
      }
      puVar14 = &DAT_0042c2fc;
      for (iVar2 = (DAT_0042d204 - DAT_0042d200) + 1; iVar4 = DAT_0042d200, uVar3 = _DAT_0042d210,
          0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 2;
      }
      for (; DAT_0042d200 = iVar4, _DAT_0042d210 = uVar3, 1 < DAT_0042d208;
          DAT_0042d208 = DAT_0042d208 + -1) {
        iVar5 = param_2[1] + _DAT_0042c2dc;
        iVar7 = param_2[3] + _DAT_0042c2dc;
        iVar2 = *param_2 + _DAT_0042c2d8;
        iVar11 = iVar5;
        iVar8 = param_2[2] + _DAT_0042c2d8;
        if (iVar7 < iVar5) {
          iVar2 = param_2[2] + _DAT_0042c2d8;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_2 + _DAT_0042c2d8;
        }
        if ((iVar11 <= DAT_0042d204) && (iVar4 <= iVar7)) {
          if (iVar11 <= iVar4) {
            iVar2 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar2 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042d204 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042d204 - iVar11) * (longlong)(iVar8 - iVar2)) /
                         (longlong)(iVar7 - iVar11)) + iVar2;
            iVar7 = DAT_0042d204;
          }
          _DAT_0042d20c = &DAT_0042c2f8 + (iVar7 - iVar4) * 2;
          piVar10 = &DAT_0042c2f8 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar2;
          if (iVar8 < iVar2) {
            _DAT_0042d210 = -uVar9;
            if ((int)_DAT_0042d210 < iVar4) goto LAB_00417711;
            iVar7 = -(_DAT_0042d210 + 1 >> 1);
            uVar3 = _DAT_0042d210 + 1;
            iVar11 = iVar2;
LAB_004176e8:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_004176e8;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              if (iVar8 <= *piVar10) {
                *piVar10 = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar2 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_0042d210;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_00417711:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar6 = 0x80000000;
            _DAT_0042d210 = uVar3;
            do {
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              piVar10 = piVar10 + 2;
              bVar17 = CARRY4(uVar6,uVar9);
              uVar6 = uVar6 + uVar9;
              iVar2 = iVar2 + (iVar11 >> 0x1f) + (uint)bVar17;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          else {
            iVar7 = -(uVar9 + 1 >> 1);
            uVar3 = uVar9 + 1;
            iVar11 = iVar2;
            _DAT_0042d210 = uVar9;
LAB_004176a6:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              iVar11 = iVar8 + 1;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_004176a6;
              }
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar8) {
                piVar10[1] = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar7 = iVar7 - _DAT_0042d210;
              iVar2 = iVar11;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_2 = param_2 + 2;
        iVar4 = DAT_0042d200;
        uVar3 = _DAT_0042d210;
      }
      if (DAT_0042d1f8 <= DAT_0042c2e0) {
        DAT_0042d1f8 = DAT_0042c2e0;
      }
      DAT_0042d21c = (uint)*param_1;
      DAT_0042d218 = (ushort *)((int)param_1 + DAT_0042d21c * param_1[1] + 4);
      param_1 = param_1 + 2;
      DAT_0042d220 = DAT_0042c2f0 * iVar4 + _DAT_0042c2d4;
      piVar10 = &DAT_0042c2f8;
      DAT_0042d214 = param_1;
      if (iVar4 <= DAT_0042d204) {
        do {
          iVar2 = *piVar10;
          if (*piVar10 <= DAT_0042c2e0) {
            iVar2 = DAT_0042c2e0;
          }
          iVar11 = piVar10[1];
          if (piVar10[1] <= DAT_0042c2e4) {
            iVar11 = DAT_0042c2e4;
          }
          if (iVar2 <= iVar11) {
            uVar9 = (iVar11 - iVar2) + 1;
            puVar15 = (ushort *)(DAT_0042d220 + iVar2);
            iVar2 = CONCAT22((short)((uint)(iVar2 - DAT_0042d1f8) >> 0x10),
                             (ushort)(iVar2 - DAT_0042d1f8) % (ushort)(byte)DAT_0042d21c);
            puVar12 = (ushort *)((int)param_1 + iVar2);
            iVar2 = iVar2 - DAT_0042d21c;
            uVar3 = -iVar2;
            if ((int)uVar3 < (int)uVar9) {
              uVar9 = uVar9 + iVar2;
              if ((short)uVar3 != 0) {
                puVar13 = puVar12;
                puVar16 = puVar15;
                if ((uVar3 & 1) != 0) {
                  puVar16 = (ushort *)((int)puVar15 + 1);
                  puVar13 = (ushort *)((int)puVar12 + 1);
                  *(char *)puVar15 = (char)*puVar12;
                }
                uVar6 = uVar3 >> 2;
                if ((short)uVar6 != 0) {
                  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *(undefined4 *)puVar16 = *(undefined4 *)puVar13;
                    puVar13 = puVar13 + 2;
                    puVar16 = puVar16 + 2;
                  }
                }
                puVar15 = puVar16;
                if ((uVar3 >> 1 & 1) != 0) {
                  puVar15 = puVar16 + 1;
                  *puVar16 = *puVar13;
                }
              }
              if ((int)DAT_0042d21c < (int)uVar9) {
                do {
                  uVar3 = DAT_0042d21c;
                  uVar9 = uVar9 - DAT_0042d21c;
                  if ((short)DAT_0042d21c != 0) {
                    uVar6 = DAT_0042d21c >> 1;
                    puVar12 = param_1;
                    puVar13 = puVar15;
                    if ((DAT_0042d21c & 1) != 0) {
                      puVar13 = (ushort *)((int)puVar15 + 1);
                      puVar12 = (ushort *)((int)param_1 + 1);
                      *(char *)puVar15 = (char)*param_1;
                    }
                    uVar3 = uVar3 >> 2;
                    if ((short)uVar3 != 0) {
                      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *(undefined4 *)puVar13 = *(undefined4 *)puVar12;
                        puVar12 = puVar12 + 2;
                        puVar13 = puVar13 + 2;
                      }
                    }
                    puVar15 = puVar13;
                    if ((uVar6 & 1) != 0) {
                      puVar15 = puVar13 + 1;
                      *puVar13 = *puVar12;
                    }
                  }
                } while ((int)DAT_0042d21c < (int)uVar9);
              }
              if ((short)uVar9 != 0) {
                puVar12 = param_1;
                puVar13 = puVar15;
                if ((uVar9 & 1) != 0) {
                  puVar13 = (ushort *)((int)puVar15 + 1);
                  puVar12 = (ushort *)((int)param_1 + 1);
                  *(char *)puVar15 = (char)*param_1;
                }
                uVar3 = uVar9 >> 2;
                if ((short)uVar3 != 0) {
                  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *(undefined4 *)puVar13 = *(undefined4 *)puVar12;
                    puVar12 = puVar12 + 2;
                    puVar13 = puVar13 + 2;
                  }
                }
                if ((uVar9 >> 1 & 1) != 0) {
                  *puVar13 = *puVar12;
                }
              }
            }
            else if ((short)uVar9 != 0) {
              puVar13 = puVar12;
              puVar16 = puVar15;
              if ((uVar9 & 1) != 0) {
                puVar16 = (ushort *)((int)puVar15 + 1);
                puVar13 = (ushort *)((int)puVar12 + 1);
                *(char *)puVar15 = (char)*puVar12;
              }
              uVar3 = uVar9 >> 2;
              if ((short)uVar3 != 0) {
                for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                  *(undefined4 *)puVar16 = *(undefined4 *)puVar13;
                  puVar13 = puVar13 + 2;
                  puVar16 = puVar16 + 2;
                }
              }
              if ((uVar9 >> 1 & 1) != 0) {
                *puVar16 = *puVar13;
              }
            }
          }
          DAT_0042d220 = DAT_0042d220 + DAT_0042c2f0;
          piVar10 = piVar10 + 2;
          param_1 = (ushort *)((int)param_1 + DAT_0042d21c);
          if (DAT_0042d218 <= param_1) {
            param_1 = DAT_0042d214;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042d204);
      }
    }
  }
  return;
}


// ==== FUN_004178b6 @ 004178b6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004178b6(int *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  bool bVar15;
  undefined4 uStack_14;
  
  DAT_0042d200 = 0x7fffffff;
  DAT_0042d204 = 0;
  DAT_0042d1f8 = 0x7fffffff;
  DAT_0042d1fc = 0;
  if (param_2 != 0) {
    piVar12 = param_1;
    do {
      piVar1 = piVar12 + 1;
      iVar3 = *piVar12 + _DAT_0042c2d8;
      if (iVar3 <= DAT_0042d1f8) {
        DAT_0042d1f8 = iVar3;
      }
      if (DAT_0042d1fc <= iVar3) {
        DAT_0042d1fc = iVar3;
      }
      piVar12 = piVar12 + 2;
      iVar3 = *piVar1 + _DAT_0042c2dc;
      if (iVar3 <= DAT_0042d200) {
        DAT_0042d200 = iVar3;
      }
      if (DAT_0042d204 <= iVar3) {
        DAT_0042d204 = iVar3;
      }
    } while ((int)piVar12 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042d1f8 <= DAT_0042c2e4) && (DAT_0042c2e0 <= DAT_0042d1fc)) &&
        (DAT_0042d200 <= DAT_0042c2ec)) && (DAT_0042c2e8 <= DAT_0042d204)) {
      if (DAT_0042d200 <= DAT_0042c2e8) {
        DAT_0042d200 = DAT_0042c2e8;
      }
      if (DAT_0042c2ec <= DAT_0042d204) {
        DAT_0042d204 = DAT_0042c2ec;
      }
      iVar3 = DAT_0042c2e4 + 1;
      piVar12 = &DAT_0042c2f8;
      for (iVar4 = ((DAT_0042d204 - DAT_0042d200) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = iVar3;
        piVar12 = piVar12 + 1;
      }
      puVar13 = &DAT_0042c2fc;
      for (iVar3 = (DAT_0042d204 - DAT_0042d200) + 1; DAT_0042d208 = param_2, iVar4 = DAT_0042d200,
          uVar6 = _DAT_0042d210, 0 < iVar3; iVar3 = iVar3 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 2;
      }
      for (; DAT_0042d200 = iVar4, _DAT_0042d210 = uVar6, 1 < DAT_0042d208;
          DAT_0042d208 = DAT_0042d208 + -1) {
        iVar5 = param_1[1] + _DAT_0042c2dc;
        iVar7 = param_1[3] + _DAT_0042c2dc;
        iVar3 = *param_1 + _DAT_0042c2d8;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_0042c2d8;
        if (iVar7 < iVar5) {
          iVar3 = param_1[2] + _DAT_0042c2d8;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_0042c2d8;
        }
        if ((iVar11 <= DAT_0042d204) && (iVar4 <= iVar7)) {
          if (iVar11 < iVar4) {
            iVar3 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar3 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042d204 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042d204 - iVar11) * (longlong)(iVar8 - iVar3)) /
                         (longlong)(iVar7 - iVar11)) + iVar3;
            iVar7 = DAT_0042d204;
          }
          _DAT_0042d20c = &DAT_0042c2f8 + (iVar7 - iVar4) * 2;
          piVar12 = &DAT_0042c2f8 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            _DAT_0042d210 = -uVar9;
            if ((int)_DAT_0042d210 < iVar4) goto LAB_00417b5d;
            iVar7 = -(_DAT_0042d210 + 1 >> 1);
            uVar6 = _DAT_0042d210 + 1;
            iVar11 = iVar3;
LAB_00417b34:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00417b34;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              if (iVar8 <= *piVar12) {
                *piVar12 = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar3 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_0042d210;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_00417b5d:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar10 = 0x80000000;
            _DAT_0042d210 = uVar6;
            do {
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              piVar12 = piVar12 + 2;
              bVar15 = CARRY4(uVar10,uVar9);
              uVar10 = uVar10 + uVar9;
              iVar3 = iVar3 + (iVar11 >> 0x1f) + (uint)bVar15;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          else {
            iVar7 = -(uVar9 + 1 >> 1);
            uVar6 = uVar9 + 1;
            iVar11 = iVar3;
            _DAT_0042d210 = uVar9;
LAB_00417af2:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              iVar11 = iVar8 + 1;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00417af2;
              }
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar8) {
                piVar12[1] = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar7 = iVar7 - _DAT_0042d210;
              iVar3 = iVar11;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_0042d200;
        uVar6 = _DAT_0042d210;
      }
      iVar3 = DAT_0042c2f0 * iVar4 + _DAT_0042c2d4;
      piVar12 = &DAT_0042c2f8;
      uVar2 = CONCAT11(param_3,param_3);
      uStack_14 = CONCAT22(uVar2,uVar2);
      if (iVar4 <= DAT_0042d204) {
        do {
          iVar11 = *piVar12;
          if (*piVar12 <= DAT_0042c2e0) {
            iVar11 = DAT_0042c2e0;
          }
          iVar7 = piVar12[1];
          if (piVar12[1] <= DAT_0042c2e4) {
            iVar7 = DAT_0042c2e4;
          }
          if (iVar11 <= iVar7) {
            uVar6 = (iVar7 - iVar11) + 1;
            puVar13 = (undefined4 *)(iVar3 + iVar11);
            if ((short)uVar6 != 0) {
              puVar14 = puVar13;
              if ((uVar6 & 1) != 0) {
                puVar14 = (undefined4 *)((int)puVar13 + 1);
                *(undefined1 *)puVar13 = param_3;
              }
              uVar9 = uVar6 >> 2;
              if ((short)uVar9 != 0) {
                for (; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *puVar14 = uStack_14;
                  puVar14 = puVar14 + 1;
                }
              }
              if ((uVar6 >> 1 & 1) != 0) {
                *(undefined2 *)puVar14 = uVar2;
              }
            }
          }
          iVar3 = iVar3 + DAT_0042c2f0;
          piVar12 = piVar12 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042d204);
      }
    }
  }
  return;
}


// ==== FUN_00417c28 @ 00417c28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417c28(int *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  bool bVar14;
  
  DAT_0042d200 = 0x7fffffff;
  DAT_0042d204 = 0;
  DAT_0042d1f8 = 0x7fffffff;
  DAT_0042d1fc = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      iVar3 = *piVar10 + _DAT_0042c2d8;
      if (iVar3 <= DAT_0042d1f8) {
        DAT_0042d1f8 = iVar3;
      }
      if (DAT_0042d1fc <= iVar3) {
        DAT_0042d1fc = iVar3;
      }
      piVar10 = piVar10 + 2;
      iVar3 = *piVar1 + _DAT_0042c2dc;
      if (iVar3 <= DAT_0042d200) {
        DAT_0042d200 = iVar3;
      }
      if (DAT_0042d204 <= iVar3) {
        DAT_0042d204 = iVar3;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042d1f8 <= DAT_0042c2e4) && (DAT_0042c2e0 <= DAT_0042d1fc)) &&
        (DAT_0042d200 <= DAT_0042c2ec)) && (DAT_0042c2e8 <= DAT_0042d204)) {
      if (DAT_0042d200 <= DAT_0042c2e8) {
        DAT_0042d200 = DAT_0042c2e8;
      }
      if (DAT_0042c2ec <= DAT_0042d204) {
        DAT_0042d204 = DAT_0042c2ec;
      }
      iVar3 = DAT_0042c2e4 + 1;
      piVar10 = &DAT_0042c2f8;
      for (iVar4 = ((DAT_0042d204 - DAT_0042d200) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar3;
        piVar10 = piVar10 + 1;
      }
      iVar3 = (DAT_0042d204 - DAT_0042d200) + 1;
      puVar12 = &DAT_0042c2fc;
      iVar4 = iVar3;
      while (iVar11 = iVar3, DAT_0042d208 = param_2, iVar3 = DAT_0042d200, uVar2 = _DAT_0042d210,
            0 < iVar4) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 2;
        iVar3 = iVar11 + -1;
        iVar4 = iVar11;
      }
      for (; DAT_0042d200 = iVar3, _DAT_0042d210 = uVar2, 1 < DAT_0042d208;
          DAT_0042d208 = DAT_0042d208 + -1) {
        iVar5 = param_1[1] + _DAT_0042c2dc;
        iVar6 = param_1[3] + _DAT_0042c2dc;
        iVar4 = *param_1 + _DAT_0042c2d8;
        iVar11 = iVar5;
        iVar7 = param_1[2] + _DAT_0042c2d8;
        if (iVar6 < iVar5) {
          iVar4 = param_1[2] + _DAT_0042c2d8;
          iVar11 = iVar6;
          iVar6 = iVar5;
          iVar7 = *param_1 + _DAT_0042c2d8;
        }
        if ((iVar11 <= DAT_0042d204) && (iVar3 <= iVar6)) {
          if (iVar11 < iVar3) {
            iVar4 = (int)(((longlong)(iVar6 - iVar3) * (longlong)(iVar4 - iVar7)) /
                         (longlong)(iVar6 - iVar11)) + iVar7;
            iVar11 = iVar3;
          }
          if (DAT_0042d204 < iVar6) {
            iVar7 = (int)(((longlong)(DAT_0042d204 - iVar11) * (longlong)(iVar7 - iVar4)) /
                         (longlong)(iVar6 - iVar11)) + iVar4;
            iVar6 = DAT_0042d204;
          }
          _DAT_0042d20c = &DAT_0042c2f8 + (iVar6 - iVar3) * 2;
          piVar10 = &DAT_0042c2f8 + (iVar11 - iVar3) * 2;
          iVar3 = (iVar6 - iVar3) - (iVar11 - iVar3);
          uVar8 = iVar7 - iVar4;
          if (iVar7 < iVar4) {
            _DAT_0042d210 = -uVar8;
            if ((int)_DAT_0042d210 < iVar3) goto LAB_00417ecc;
            iVar6 = -(_DAT_0042d210 + 1 >> 1);
            uVar2 = _DAT_0042d210 + 1;
            iVar11 = iVar4;
LAB_00417ea3:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              iVar11 = iVar7 + -1;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_00417ea3;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              if (iVar7 <= *piVar10) {
                *piVar10 = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar4 = iVar7 + -1;
              iVar6 = iVar6 - _DAT_0042d210;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
          else if ((int)uVar8 < iVar3) {
LAB_00417ecc:
            iVar11 = (int)(CONCAT44((int)uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) /
                          (longlong)iVar3);
            uVar8 = iVar11 * 2;
            iVar3 = iVar3 + 1;
            uVar9 = 0x80000000;
            _DAT_0042d210 = uVar2;
            do {
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              piVar10 = piVar10 + 2;
              bVar14 = CARRY4(uVar9,uVar8);
              uVar9 = uVar9 + uVar8;
              iVar4 = iVar4 + (iVar11 >> 0x1f) + (uint)bVar14;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          else {
            iVar6 = -(uVar8 + 1 >> 1);
            uVar2 = uVar8 + 1;
            iVar11 = iVar4;
            _DAT_0042d210 = uVar8;
LAB_00417e61:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              iVar11 = iVar7 + 1;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_00417e61;
              }
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar7) {
                piVar10[1] = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar6 = iVar6 - _DAT_0042d210;
              iVar4 = iVar11;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
        }
        param_1 = param_1 + 2;
        iVar3 = DAT_0042d200;
        uVar2 = _DAT_0042d210;
      }
      if (DAT_0042d1f8 <= DAT_0042c2e0) {
        DAT_0042d1f8 = DAT_0042c2e0;
      }
      DAT_0042d220 = DAT_0042c2f0 * iVar3 + _DAT_0042c2d4;
      piVar10 = &DAT_0042c2f8;
      if (iVar3 <= DAT_0042d204) {
        do {
          iVar4 = *piVar10;
          if (*piVar10 <= DAT_0042c2e0) {
            iVar4 = DAT_0042c2e0;
          }
          iVar11 = piVar10[1];
          if (DAT_0042c2e4 <= piVar10[1]) {
            iVar11 = DAT_0042c2e4;
          }
          if (iVar4 <= iVar11) {
            puVar13 = (undefined1 *)(DAT_0042d220 + iVar4);
            for (iVar11 = (iVar11 - iVar4) + 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar13 = param_3;
              puVar13 = puVar13 + 1;
            }
          }
          DAT_0042d220 = DAT_0042d220 + DAT_0042c2f0;
          piVar10 = piVar10 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= DAT_0042d204);
      }
    }
  }
  return;
}


// ==== FUN_00417f9e @ 00417f9e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417f9e(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  bool bVar10;
  
  DAT_0042d234 = '\0';
  if ((int)param_3 < 0) {
    DAT_0042d234 = '\x01';
    param_3 = -param_3;
  }
  else if (param_3 == 0) {
    param_3 = 1;
  }
  DAT_0042d235 = '\0';
  if ((int)param_4 < 0) {
    DAT_0042d235 = '\x01';
    param_4 = -param_4;
  }
  else if (param_4 == 0) {
    param_4 = 1;
  }
  uVar5 = *param_5 / param_3;
  uVar1 = ((ulonglong)(uint)*param_5 % (ulonglong)param_3 << 0x20) / (ulonglong)param_3;
  uVar6 = (uint)uVar1;
  DAT_0042d242 = param_5[1] / param_4;
  uVar2 = ((ulonglong)(uint)param_5[1] % (ulonglong)param_4 << 0x20) / (ulonglong)param_4;
  DAT_0042d23e = (uint)uVar2;
  DAT_0042d24e = (uint)*param_5;
  param_1 = param_1 + _DAT_0042c2d8;
  iVar7 = param_3 + param_1 + -1;
  param_2 = param_2 + _DAT_0042c2dc;
  DAT_0042d230 = param_4 + param_2 + -1;
  DAT_0042d22c = param_2;
  DAT_0042d236 = uVar6;
  DAT_0042d23a = uVar5;
  if ((((param_1 <= DAT_0042c2e4) && (DAT_0042c2e0 <= iVar7)) && (param_2 <= DAT_0042c2ec)) &&
     (DAT_0042c2e8 <= DAT_0042d230)) {
    DAT_0042d246 = 0;
    _DAT_0042d24a = 0;
    param_5 = param_5 + 2;
    DAT_0042d224 = param_1;
    if ((param_1 < DAT_0042c2e0) && (DAT_0042d224 = DAT_0042c2e0, DAT_0042d234 == '\0')) {
      lVar3 = (ulonglong)(uint)-(param_1 - DAT_0042c2e0) * (uVar1 & 0xffffffff);
      DAT_0042d246 = (uint)lVar3;
      param_5 = (ushort *)
                ((int)param_5 + -(param_1 - DAT_0042c2e0) * uVar5 + (int)((ulonglong)lVar3 >> 0x20))
      ;
    }
    DAT_0042d228 = iVar7;
    if ((DAT_0042c2e4 < iVar7) && (DAT_0042d228 = DAT_0042c2e4, DAT_0042d234 != '\0')) {
      lVar3 = (ulonglong)(uint)(iVar7 - DAT_0042c2e4) * (uVar1 & 0xffffffff);
      DAT_0042d246 = DAT_0042d246 + (int)lVar3;
      param_5 = (ushort *)
                ((int)param_5 + (iVar7 - DAT_0042c2e4) * uVar5 + (int)((ulonglong)lVar3 >> 0x20));
    }
    if ((param_2 < DAT_0042c2e8) && (DAT_0042d22c = DAT_0042c2e8, DAT_0042d235 == '\0')) {
      lVar3 = (ulonglong)(uint)-(param_2 - DAT_0042c2e8) * (uVar2 & 0xffffffff);
      _DAT_0042d24a = (uint)lVar3;
      param_5 = (ushort *)
                ((int)param_5 +
                (-(param_2 - DAT_0042c2e8) * DAT_0042d242 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0042d24e);
    }
    iVar7 = DAT_0042d230;
    if ((DAT_0042c2ec < DAT_0042d230) && (iVar7 = DAT_0042c2ec, DAT_0042d235 == '\0')) {
      lVar3 = (ulonglong)(uint)(DAT_0042d230 - DAT_0042c2ec) * (uVar2 & 0xffffffff);
      _DAT_0042d24a = _DAT_0042d24a + (int)lVar3;
      param_5 = (ushort *)
                ((int)param_5 +
                ((DAT_0042d230 - DAT_0042c2ec) * DAT_0042d242 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0042d24e);
    }
    DAT_0042d242 = DAT_0042d242 * DAT_0042d24e;
    DAT_0042d230 = iVar7;
    if (DAT_0042d234 != '\0') {
      DAT_0042d252 = param_5;
      if (DAT_0042d235 == '\0') {
        DAT_0042d220 = (char *)(DAT_0042c2f0 * DAT_0042d22c + DAT_0042d228 + _DAT_0042c2d4);
        DAT_0042d228 = DAT_0042d228 - (DAT_0042d224 + -1);
        DAT_0042d230 = iVar7 - (DAT_0042d22c + -1);
        iVar7 = DAT_0042d228;
        uVar8 = DAT_0042d246;
        pcVar9 = DAT_0042d220;
        do {
          do {
            if ((char)*param_5 != '\0') {
              *pcVar9 = (char)*param_5;
            }
            iVar4 = DAT_0042d230;
            param_5 = (ushort *)((int)param_5 + CARRY4(uVar8,uVar6) + uVar5);
            iVar7 = iVar7 + -1;
            uVar8 = uVar8 + uVar6;
            pcVar9 = pcVar9 + -1;
          } while (iVar7 != 0);
          bVar10 = CARRY4(_DAT_0042d24a,DAT_0042d23e);
          _DAT_0042d24a = _DAT_0042d24a + DAT_0042d23e;
          if (bVar10) {
            DAT_0042d252 = (ushort *)((int)DAT_0042d252 + DAT_0042d24e);
          }
          param_5 = (ushort *)((int)DAT_0042d252 + DAT_0042d242);
          DAT_0042d220 = DAT_0042d220 + DAT_0042c2f0;
          DAT_0042d230 = DAT_0042d230 + -1;
          iVar7 = DAT_0042d228;
          uVar8 = DAT_0042d246;
          pcVar9 = DAT_0042d220;
          DAT_0042d252 = param_5;
        } while (DAT_0042d230 != 0 && 0 < iVar4);
      }
      else {
        DAT_0042d220 = (char *)(DAT_0042c2f0 * iVar7 + DAT_0042d228 + _DAT_0042c2d4);
        DAT_0042d228 = DAT_0042d228 - (DAT_0042d224 + -1);
        DAT_0042d230 = iVar7 - (DAT_0042d22c + -1);
        iVar7 = DAT_0042d228;
        uVar8 = DAT_0042d246;
        pcVar9 = DAT_0042d220;
        do {
          do {
            if ((char)*param_5 != '\0') {
              *pcVar9 = (char)*param_5;
            }
            iVar4 = DAT_0042d230;
            param_5 = (ushort *)((int)param_5 + CARRY4(uVar8,uVar6) + uVar5);
            iVar7 = iVar7 + -1;
            uVar8 = uVar8 + uVar6;
            pcVar9 = pcVar9 + -1;
          } while (iVar7 != 0);
          bVar10 = CARRY4(_DAT_0042d24a,DAT_0042d23e);
          _DAT_0042d24a = _DAT_0042d24a + DAT_0042d23e;
          if (bVar10) {
            DAT_0042d252 = (ushort *)((int)DAT_0042d252 + DAT_0042d24e);
          }
          param_5 = (ushort *)((int)DAT_0042d252 + DAT_0042d242);
          DAT_0042d220 = DAT_0042d220 + -DAT_0042c2f0;
          DAT_0042d230 = DAT_0042d230 + -1;
          iVar7 = DAT_0042d228;
          uVar8 = DAT_0042d246;
          pcVar9 = DAT_0042d220;
          DAT_0042d252 = param_5;
        } while (DAT_0042d230 != 0 && 0 < iVar4);
      }
    }
    uVar6 = DAT_0042d23a;
    uVar5 = DAT_0042d236;
    if (DAT_0042d235 != '\0') {
      DAT_0042d220 = (char *)(DAT_0042c2f0 * DAT_0042d230 + DAT_0042d224 + _DAT_0042c2d4);
      DAT_0042d228 = DAT_0042d228 - (DAT_0042d224 + -1);
      DAT_0042d230 = DAT_0042d230 - (DAT_0042d22c + -1);
      iVar7 = DAT_0042d228;
      uVar8 = DAT_0042d246;
      pcVar9 = DAT_0042d220;
      DAT_0042d252 = param_5;
      do {
        do {
          if ((char)*param_5 != '\0') {
            *pcVar9 = (char)*param_5;
          }
          iVar4 = DAT_0042d230;
          param_5 = (ushort *)((int)param_5 + CARRY4(uVar8,uVar5) + uVar6);
          iVar7 = iVar7 + -1;
          uVar8 = uVar8 + uVar5;
          pcVar9 = pcVar9 + 1;
        } while (iVar7 != 0);
        bVar10 = CARRY4(_DAT_0042d24a,DAT_0042d23e);
        _DAT_0042d24a = _DAT_0042d24a + DAT_0042d23e;
        if (bVar10) {
          DAT_0042d252 = (ushort *)((int)DAT_0042d252 + DAT_0042d24e);
        }
        param_5 = (ushort *)((int)DAT_0042d252 + DAT_0042d242);
        DAT_0042d220 = DAT_0042d220 + -DAT_0042c2f0;
        DAT_0042d230 = DAT_0042d230 + -1;
        iVar7 = DAT_0042d228;
        uVar8 = DAT_0042d246;
        pcVar9 = DAT_0042d220;
        DAT_0042d252 = param_5;
      } while (DAT_0042d230 != 0 && 0 < iVar4);
    }
    uVar6 = DAT_0042d23a;
    uVar5 = DAT_0042d236;
    DAT_0042d220 = (char *)(DAT_0042c2f0 * DAT_0042d22c + DAT_0042d224 + _DAT_0042c2d4);
    DAT_0042d228 = DAT_0042d228 - (DAT_0042d224 + -1);
    DAT_0042d230 = DAT_0042d230 - (DAT_0042d22c + -1);
    iVar7 = DAT_0042d228;
    uVar8 = DAT_0042d246;
    pcVar9 = DAT_0042d220;
    DAT_0042d252 = param_5;
    do {
      do {
        if ((char)*param_5 != '\0') {
          *pcVar9 = (char)*param_5;
        }
        iVar4 = DAT_0042d230;
        param_5 = (ushort *)((int)param_5 + CARRY4(uVar8,uVar5) + uVar6);
        iVar7 = iVar7 + -1;
        uVar8 = uVar8 + uVar5;
        pcVar9 = pcVar9 + 1;
      } while (iVar7 != 0);
      bVar10 = CARRY4(_DAT_0042d24a,DAT_0042d23e);
      _DAT_0042d24a = _DAT_0042d24a + DAT_0042d23e;
      if (bVar10) {
        DAT_0042d252 = (ushort *)((int)DAT_0042d252 + DAT_0042d24e);
      }
      param_5 = (ushort *)((int)DAT_0042d252 + DAT_0042d242);
      DAT_0042d220 = DAT_0042d220 + DAT_0042c2f0;
      DAT_0042d230 = DAT_0042d230 + -1;
      iVar7 = DAT_0042d228;
      uVar8 = DAT_0042d246;
      pcVar9 = DAT_0042d220;
      DAT_0042d252 = param_5;
    } while (DAT_0042d230 != 0 && 0 < iVar4);
  }
  return;
}


// ==== FUN_0041848b @ 0041848b

void FUN_0041848b(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  if (0xf < param_3) {
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    param_3 = param_3 & 3;
    if (param_3 == 0) {
      return;
    }
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_004184b8 @ 004184b8

undefined8 FUN_004184b8(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  
  if ((((*param_2 == *param_3) && (param_2[2] == param_3[2])) && (param_2[1] == param_3[1])) &&
     (param_2[3] == param_3[3])) {
    *param_1 = *param_2;
    param_1[2] = param_2[2];
    param_1[1] = param_2[1];
    param_1[3] = param_2[3];
    uVar1 = 1;
  }
  else {
    iVar3 = *param_2;
    iVar6 = param_2[2];
    piVar5 = param_2;
    if (((param_3[2] < iVar3) || (iVar6 < *param_3)) ||
       ((piVar5 = (int *)param_2[3], param_3[3] < param_2[1] || ((int)piVar5 < param_3[1])))) {
      param_2 = piVar5;
      uVar1 = 0;
    }
    else {
      iVar8 = *param_3;
      iVar2 = iVar3;
      if (iVar8 <= iVar3) {
        iVar2 = iVar8;
        iVar8 = iVar3;
      }
      iVar3 = iVar2;
      if (iVar6 <= iVar2) {
        iVar3 = iVar6;
        iVar6 = iVar2;
      }
      iVar2 = param_3[2];
      if (param_3[2] <= iVar3) {
        iVar2 = iVar3;
      }
      iVar3 = iVar6;
      if (iVar6 <= iVar8) {
        iVar3 = iVar8;
        iVar8 = iVar6;
      }
      iVar6 = iVar2;
      if (iVar2 <= iVar8) {
        iVar6 = iVar8;
        iVar8 = iVar2;
      }
      if (iVar6 <= iVar3) {
        iVar3 = iVar6;
      }
      *param_1 = iVar8;
      param_1[2] = iVar3;
      piVar5 = (int *)param_2[1];
      piVar9 = (int *)param_2[3];
      piVar7 = (int *)param_3[1];
      piVar4 = piVar5;
      if ((int)piVar9 <= (int)piVar5) {
        piVar4 = piVar9;
        piVar9 = piVar5;
      }
      piVar5 = piVar4;
      if ((int)piVar7 <= (int)piVar4) {
        piVar5 = piVar7;
        piVar7 = piVar4;
      }
      piVar4 = (int *)param_3[3];
      if (param_3[3] <= (int)piVar5) {
        piVar4 = piVar5;
      }
      piVar5 = piVar7;
      if ((int)piVar7 <= (int)piVar9) {
        piVar5 = piVar9;
        piVar9 = piVar7;
      }
      param_2 = piVar4;
      if ((int)piVar4 <= (int)piVar9) {
        param_2 = piVar9;
        piVar9 = piVar4;
      }
      piVar7 = piVar5;
      if ((int)param_2 <= (int)piVar5) {
        piVar7 = param_2;
        param_2 = piVar5;
      }
      param_1[1] = (int)piVar9;
      param_1[3] = (int)piVar7;
      uVar1 = 1;
    }
  }
  return CONCAT44(param_2,uVar1);
}


// ==== FUN_004185a3 @ 004185a3

undefined4 FUN_004185a3(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((((param_2[2] < *param_1) || (param_1[2] < *param_2)) || (param_2[3] < param_1[1])) ||
     (param_1[3] < param_2[1])) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_004185df @ 004185df

void FUN_004185df(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    param_2[3] = param_1[3];
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    iVar2 = *param_1;
    *param_2 = iVar2;
    if (param_2[2] <= iVar2) {
      LOCK();
      iVar1 = param_2[2];
      param_2[2] = iVar2;
      UNLOCK();
      *param_2 = iVar1;
    }
    if (param_2[1] < param_2[3]) {
      return;
    }
    LOCK();
    iVar2 = param_2[3];
    param_2[3] = param_2[1];
    UNLOCK();
    param_2[1] = iVar2;
  }
  if (param_1[2] <= *param_1) {
    LOCK();
    iVar2 = param_1[2];
    param_1[2] = *param_1;
    UNLOCK();
    *param_1 = iVar2;
  }
  if (param_1[3] <= param_1[1]) {
    LOCK();
    iVar2 = param_1[3];
    param_1[3] = param_1[1];
    UNLOCK();
    param_1[1] = iVar2;
  }
  return;
}


// ==== FUN_0041863c @ 0041863c

void FUN_0041863c(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (*param_3 < *param_2) {
    iVar1 = *param_3;
  }
  *param_1 = iVar1;
  iVar1 = param_2[2];
  if (param_2[2] < param_3[2]) {
    iVar1 = param_3[2];
  }
  param_1[2] = iVar1;
  iVar1 = param_2[1];
  if (param_3[1] < param_2[1]) {
    iVar1 = param_3[1];
  }
  param_1[1] = iVar1;
  iVar1 = param_2[3];
  if (param_2[3] < param_3[3]) {
    iVar1 = param_3[3];
  }
  param_1[3] = iVar1;
  return;
}


// ==== FUN_00418692 @ 00418692

undefined4 FUN_00418692(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004185a3(param_3,param_2);
  if (iVar1 != 0) {
    FUN_0041863c(&DAT_0042d264,param_2,param_3);
    DAT_0042d274 = ((param_2[2] - *param_2) + 1U & 0xffff) *
                   ((param_2[3] - param_2[1]) + 1U & 0xffff);
    if (((DAT_0042d26c - DAT_0042d264) + 1U & 0xffff) *
        ((DAT_0042d270 - DAT_0042d268) + 1U & 0xffff) <=
        ((param_3[2] - *param_3) + 1U & 0xffff) * ((param_3[3] - param_3[1]) + 1U & 0xffff) +
        DAT_0042d274) {
      *param_1 = DAT_0042d264;
      param_1[1] = DAT_0042d268;
      param_1[2] = DAT_0042d26c;
      param_1[3] = DAT_0042d270;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0041876b @ 0041876b

int FUN_0041876b(int *param_1)

{
  return (param_1[2] - *param_1) + 1;
}


// ==== FUN_0041877b @ 0041877b

int FUN_0041877b(int param_1)

{
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) + 1;
}


// ==== FUN_0041878c @ 0041878c

void FUN_0041878c(char *param_1,uint param_2,char param_3)

{
  uint uVar1;
  char *pcVar2;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (*param_1 == param_3) goto LAB_004187d2;
LAB_004187ae:
    if (param_1[1] == param_3) goto LAB_004187db;
LAB_004187b5:
    if (param_1[2] == param_3) goto LAB_004187e5;
    while (param_1[3] == param_3) {
      while( true ) {
        param_1[3] = '\0';
        param_1 = param_1 + 4;
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) goto LAB_004187fc;
        if (*param_1 != param_3) goto LAB_004187ae;
LAB_004187d2:
        *param_1 = '\0';
        if (param_1[1] != param_3) goto LAB_004187b5;
LAB_004187db:
        param_1[1] = '\0';
        if (param_1[2] != param_3) break;
LAB_004187e5:
        param_1[2] = '\0';
        if (param_1[3] != param_3) goto LAB_004187c3;
      }
    }
LAB_004187c3:
    param_1 = param_1 + 4;
  }
LAB_004187fc:
  param_2 = param_2 & 3;
  do {
    if (param_2 == 0) {
      return;
    }
    do {
      pcVar2 = param_1;
      param_1 = pcVar2 + 1;
      if (*pcVar2 == param_3) break;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
    *pcVar2 = '\0';
    param_2 = param_2 - 1;
  } while( true );
}


// ==== FUN_00418818 @ 00418818

bool FUN_00418818(char *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  *param_4 = param_2;
  param_4[2] = 0xffffffff;
  param_4[1] = param_3;
  param_4[3] = 0xffffffff;
  uVar2 = 0;
LAB_00418843:
  do {
    uVar1 = 0;
    pcVar3 = param_1;
    do {
      while (param_1 = pcVar3 + 1, *pcVar3 == '\0') {
        uVar1 = uVar1 + 1;
        pcVar3 = param_1;
        if (param_2 <= uVar1) {
          uVar2 = uVar2 + 1;
          param_3 = param_3 - 1;
          if (param_3 != 0) goto LAB_00418843;
          goto LAB_0041887c;
        }
      }
      if ((int)uVar1 < (int)*param_4) {
        *param_4 = uVar1;
      }
      if ((int)param_4[2] < (int)uVar1) {
        param_4[2] = uVar1;
      }
      if ((int)uVar2 < (int)param_4[1]) {
        param_4[1] = uVar2;
      }
      if ((int)param_4[3] < (int)uVar2) {
        param_4[3] = uVar2;
      }
      uVar1 = uVar1 + 1;
      pcVar3 = param_1;
    } while (uVar1 < param_2);
    uVar2 = uVar2 + 1;
    param_3 = param_3 - 1;
    if (param_3 == 0) {
LAB_0041887c:
      return *param_4 != param_2;
    }
  } while( true );
}


// ==== FUN_00418890 @ 00418890

void FUN_00418890(int param_1,int param_2,short *param_3,short *param_4)

{
  int iVar1;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    local_1c = (int)*param_3;
    local_24 = (int)param_3[1];
    local_5c = (int)*param_4;
    local_58 = (int)param_4[1];
    if ((local_1c != 0) && (((local_24 != 0 && (local_5c != 0)) && (local_58 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = local_1c + param_1;
      local_34 = param_2 + local_24;
      local_64 = 0;
      local_60 = 0;
      local_30 = local_58;
      local_2c = local_5c;
      iVar1 = FUN_004184b8(&local_14,&local_40,&local_64);
      if (iVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (int)param_3 + local_1c * local_4c + local_20 + 4;
        local_44 = (int)param_4 + local_10 * local_2c + local_14 + 4;
        FUN_00416a90(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_004189ff @ 004189ff

void FUN_004189ff(int param_1,int param_2,short *param_3,short *param_4)

{
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    FUN_00416a90((int)param_4 + param_1 + *param_4 * param_2 + 4,param_3 + 2,(int)*param_3,
                 (int)param_3[1],(int)*param_4,(int)*param_3,0);
  }
  return;
}


// ==== FUN_00418a9a @ 00418a9a

void FUN_00418a9a(int param_1,int param_2,int param_3,short *param_4,short *param_5)

{
  int iVar1;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_4 != (short *)0x0) && (param_5 != (short *)0x0)) && (param_3 != 0)) {
    local_1c = (int)*param_4;
    local_24 = (int)param_4[1];
    local_2c = (int)*param_5;
    local_30 = (int)param_5[1];
    if (((local_1c != 0) && (local_24 != 0)) && ((local_2c != 0 && (local_30 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = FUN_0041876b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0041877b(param_3);
      local_34 = param_2 + local_34;
      local_64 = 0;
      local_60 = 0;
      local_5c = local_2c;
      local_58 = local_30;
      iVar1 = FUN_004184b8(&local_14,&local_40,&local_64);
      if (iVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (int)param_4 + local_4c * local_1c + local_20 + 4;
        local_44 = (int)param_5 + local_10 * local_2c + local_14 + 4;
        FUN_00416a90(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_00418c29 @ 00418c29

void FUN_00418c29(int param_1,int param_2,undefined4 param_3,short *param_4,short *param_5)

{
  int iVar1;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_4 != (short *)0x0) && (param_5 != (short *)0x0)) {
    local_1c = (int)*param_4;
    local_24 = (int)*param_4;
    local_2c = (int)*param_5;
    local_30 = (int)*param_5;
    if ((local_1c != 0) && (((local_24 != 0 && (local_2c != 0)) && (local_30 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = FUN_0041876b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0041877b(param_3);
      local_34 = param_2 + local_34;
      local_64 = 0;
      local_60 = 0;
      local_5c = local_2c;
      local_58 = local_30;
      iVar1 = FUN_004184b8(&local_14,&local_40,&local_64);
      if (iVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (int)param_4 + local_4c * local_1c + local_20 + 4;
        local_44 = (int)param_5 + local_10 * local_2c + local_14 + 4;
        FUN_00416b4c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_00418daa @ 00418daa

void FUN_00418daa(int param_1,int param_2,int param_3,short *param_4,short *param_5)

{
  int iVar1;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_4 != (short *)0x0) && (param_5 != (short *)0x0)) && (param_3 != 0)) {
    local_1c = (int)*param_4;
    local_24 = (int)*param_4;
    local_5c = (int)*param_5;
    local_58 = (int)*param_5;
    if (((local_1c != 0) && (local_24 != 0)) && ((local_5c != 0 && (local_58 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = local_1c + param_1;
      local_34 = param_2 + local_24;
      local_64 = 0;
      local_60 = 0;
      local_30 = local_58;
      local_2c = local_5c;
      iVar1 = FUN_004184b8(&local_14,&local_40,&local_64);
      if (iVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (int)param_4 + local_1c * local_4c + local_20 + 4;
        local_44 = (int)param_5 + local_10 * local_2c + local_14 + 4;
        FUN_00416b4c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_00418f1f @ 00418f1f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00418f1f(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      _DAT_0042d27c = 0;
      uVar2 = 0;
    }
    else {
      if (*param_1 != 0) {
        if (*param_1 == 0) {
          bVar1 = false;
        }
        else if (*(short *)*param_1 == 0x400) {
          if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2)
              == 0) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          return *(undefined1 *)(*(short *)*param_1 * param_3 + *param_1 + 4 + param_2);
        }
      }
      uVar2 = *(undefined1 *)(*param_1 + 4 + param_2);
    }
  }
  return uVar2;
}


// ==== FUN_004190b6 @ 004190b6

bool __fastcall FUN_004190b6(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_004190f0 @ 004190f0

bool __fastcall FUN_004190f0(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_0041912a @ 0041912a

void __thiscall FUN_0041912a(int *param_1,int param_2)

{
  bool bVar1;
  
  if (*param_1 != 0) {
    if (param_2 == 0) {
      if (*param_1 == 0) {
        bVar1 = false;
      }
      else if (*(short *)*param_1 == 0x400) {
        if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2)
            == 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_00420df8(param_1[10],param_1[0xb],*param_1,0);
      }
      else {
        FUN_0041e81f(param_1[10],param_1[0xb],*param_1,0);
      }
    }
    else {
      if (*param_1 == 0) {
        bVar1 = false;
      }
      else if (*(short *)*param_1 == 0x400) {
        if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2)
            == 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_00420c41(param_1[10],param_1[0xb],*param_1,0);
      }
      else {
        FUN_0041d370(param_1[10],param_1[0xb],*param_1,0);
      }
    }
  }
  return;
}


// ==== FUN_0041934a @ 0041934a

void __thiscall FUN_0041934a(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  
  if (*param_1 != 0) {
    if (param_4 == 0) {
      if (*param_1 == 0) {
        bVar1 = false;
      }
      else if (*(short *)*param_1 == 0x400) {
        if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2)
            == 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_00420df8(param_2,param_3,*param_1,0);
      }
      else {
        FUN_0041e81f(param_2,param_3,*param_1,0);
      }
    }
    else {
      if (*param_1 == 0) {
        bVar1 = false;
      }
      else if (*(short *)*param_1 == 0x400) {
        if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2)
            == 0) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_00420c41(param_2,param_3,*param_1,0);
      }
      else {
        FUN_0041d370(param_2,param_3,*param_1,0);
      }
    }
  }
  return;
}


// ==== FUN_00419522 @ 00419522

void __thiscall FUN_00419522(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*param_1 == 0) {
    return;
  }
  if (param_3 != 0) {
    FUN_0041ce13(param_1[10],param_1[0xb],param_1[10],param_1[0xb],param_2,*param_1);
    return;
  }
  if (*param_1 == 0) {
LAB_0041963e:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041963e;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_14 = (int)*(short *)(*param_1 + 2);
      goto LAB_004196f4;
    }
  }
  local_14 = 0;
LAB_004196f4:
  FUN_0041c6f5(param_1[10],param_1[0xb],param_1[10],param_1[0xb],local_c,local_14,param_2,0xffff);
  return;
}


// ==== FUN_00419754 @ 00419754

void __thiscall
FUN_00419754(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*param_1 == 0) {
    return;
  }
  if (param_5 != 0) {
    FUN_0041ce13(param_2,param_3,param_2,param_3,param_4,*param_1);
    return;
  }
  if (*param_1 == 0) {
LAB_0041984c:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041984c;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_14 = (int)*(short *)(*param_1 + 2);
      goto LAB_00419902;
    }
  }
  local_14 = 0;
LAB_00419902:
  FUN_0041c6f5(param_2,param_3,param_2,param_3,local_c,local_14,param_4,0xffff);
  return;
}


// ==== FUN_0041993e @ 0041993e

void __thiscall FUN_0041993e(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*param_1 == 0) {
    return;
  }
  if (*param_1 == 0) {
LAB_004199f8:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_004199f8;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_14 = (int)*(short *)(*param_1 + 2);
      goto LAB_00419aae;
    }
  }
  local_14 = 0;
LAB_00419aae:
  FUN_0041add8(param_1[10],param_1[0xb],param_1[10] + local_c + -1,param_1[0xb] + local_14 + -1,0);
  FUN_0041912a(param_2);
  return;
}


// ==== FUN_00419afc @ 00419afc

void __thiscall FUN_00419afc(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*param_1 == 0) {
    return;
  }
  if (*param_1 == 0) {
LAB_00419bb6:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00419bb6;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_14 = (int)*(short *)(*param_1 + 2);
      goto LAB_00419c6c;
    }
  }
  local_14 = 0;
LAB_00419c6c:
  FUN_0041add8(param_2,param_3,param_2 + local_c + -1,param_3 + local_14 + -1,0);
  FUN_0041934a(param_2,param_3,param_4);
  return;
}


// ==== FUN_00419cb1 @ 00419cb1

void __thiscall FUN_00419cb1(int *param_1,int param_2)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (*param_1 == 0) {
    return;
  }
  if (*param_1 == 0) {
    bVar1 = false;
  }
  else if (*(short *)*param_1 == 0x400) {
    if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) == 0)
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (param_2 == 0) {
      FUN_0041dd0e(param_1[10],param_1[0xb],param_1[0xc],param_1[0xd],
                   (param_1[0xe] - param_1[0xc]) + 1,(param_1[0xf] - param_1[0xd]) + 1,*param_1,0);
      return;
    }
    FUN_0041d84c(param_1[10],param_1[0xb],param_1[0xc],param_1[0xd],
                 (param_1[0xe] - param_1[0xc]) + 1,(param_1[0xf] - param_1[0xd]) + 1,*param_1,0);
    return;
  }
  if (*param_1 == 0) {
LAB_00419f78:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00419f78;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_8 = (int)*(short *)(*param_1 + 2);
      goto LAB_0041a043;
    }
  }
  local_8 = 0;
LAB_0041a043:
  DAT_00680438 = operator_new(local_8 * local_c + 4);
  if (DAT_00680438 != (undefined2 *)0x0) {
    *DAT_00680438 = (short)local_c;
    DAT_00680438[1] = (short)local_8;
    _memset(DAT_00680438 + 2,0,local_8 * local_c);
    if (param_2 == 0) {
      FUN_0041dd0e(param_1[10],param_1[0xb],param_1[0xc],param_1[0xd],
                   (param_1[0xe] - param_1[0xc]) + 1,(param_1[0xf] - param_1[0xd]) + 1,DAT_00680438,
                   0);
    }
    else {
      FUN_0041d84c(param_1[10],param_1[0xb],param_1[0xc],param_1[0xd],
                   (param_1[0xe] - param_1[0xc]) + 1,(param_1[0xf] - param_1[0xd]) + 1,DAT_00680438,
                   0);
    }
    FUN_00422290(DAT_00680438);
  }
  DAT_00680438 = (undefined2 *)0x0;
  return;
}


// ==== FUN_0041a242 @ 0041a242

void __thiscall
FUN_0041a242(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (*param_1 == 0) {
    return;
  }
  if (*param_1 == 0) {
    bVar1 = false;
  }
  else if (*(short *)*param_1 == 0x400) {
    if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) == 0)
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (param_5 == 0) {
      FUN_0041dd0e(param_2,param_3,*param_4,param_4[1],(param_4[2] - *param_4) + 1,
                   (param_4[3] - param_4[1]) + 1,*param_1,0);
      return;
    }
    FUN_0041d84c(param_2,param_3,*param_4,param_4[1],(param_4[2] - *param_4) + 1,
                 (param_4[3] - param_4[1]) + 1,*param_1,0);
    return;
  }
  if (*param_1 == 0) {
LAB_0041a45b:
    local_c = 0;
  }
  else {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041a45b;
    local_c = (int)*(short *)*param_1;
  }
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_8 = (int)*(short *)(*param_1 + 2);
      goto LAB_0041a511;
    }
  }
  local_8 = 0;
LAB_0041a511:
  DAT_00680438 = operator_new(local_8 * local_c + 4);
  if (DAT_00680438 != (undefined2 *)0x0) {
    *DAT_00680438 = (short)local_c;
    DAT_00680438[1] = (short)local_8;
    _memset(DAT_00680438 + 2,0,local_8 * local_c);
    if (param_5 == 0) {
      FUN_0041dd0e(param_2,param_3,*param_4,param_4[1],(param_4[2] - *param_4) + 1,
                   (param_4[3] - param_4[1]) + 1,DAT_00680438,0);
    }
    else {
      FUN_0041d84c(param_2,param_3,*param_4,param_4[1],(param_4[2] - *param_4) + 1,
                   (param_4[3] - param_4[1]) + 1,DAT_00680438,0);
    }
    FUN_00422290(DAT_00680438);
  }
  DAT_00680438 = (undefined2 *)0x0;
  return;
}


// ==== FUN_0041a68c @ 0041a68c

void __thiscall FUN_0041a68c(int param_1,undefined4 param_2)

{
  FUN_0041add8(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
               (*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x28)) - *(int *)(param_1 + 0x30),
               (*(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x2c)) - *(int *)(param_1 + 0x34),0);
  FUN_00419cb1(param_2);
  return;
}


// ==== FUN_0041a6f1 @ 0041a6f1

void FUN_0041a6f1(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  FUN_0041add8(param_1,param_2,(param_3[2] + param_1) - *param_3,(param_3[3] + param_2) - param_3[1]
               ,0);
  FUN_0041a242(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0041a760 @ 0041a760

undefined4 __thiscall FUN_0041a760(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  void *pvVar10;
  
  iVar7 = param_5;
  iVar6 = param_4;
  iVar4 = DAT_00680454;
  iVar3 = DAT_00680450;
  iVar2 = DAT_00680448;
  if (DAT_00680448 == 0) {
    uVar5 = 0;
  }
  else if (*(short *)(param_1 + 0x80) < 0x1f) {
    if (param_4 < param_2) {
      param_4 = param_2;
      param_2 = iVar6;
    }
    if (param_5 < param_3) {
      param_5 = param_3;
      param_3 = iVar7;
    }
    if (param_2 < 1) {
      param_2 = 0;
    }
    if (param_3 < 1) {
      param_3 = 0;
    }
    iVar6 = DAT_0068044c + -1;
    if (param_4 <= DAT_0068044c + -1) {
      iVar6 = param_4;
    }
    iVar7 = DAT_00680450 + -1;
    if (param_5 <= DAT_00680450 + -1) {
      iVar7 = param_5;
    }
    iVar8 = (iVar6 - param_2) + 1;
    iVar9 = (iVar7 - param_3) + 1;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + 1;
    pvVar10 = operator_new(iVar9 * iVar8 + 8);
    *(void **)(param_1 + *(short *)(param_1 + 0x80) * 4) = pvVar10;
    if (*(int *)(param_1 + *(short *)(param_1 + 0x80) * 4) == 0) {
      uVar5 = 0;
    }
    else {
      puVar1 = *(undefined2 **)(param_1 + *(short *)(param_1 + 0x80) * 4);
      *puVar1 = (short)param_2;
      puVar1[1] = (short)param_3;
      puVar1[2] = (short)iVar6;
      puVar1[3] = (short)iVar7;
      if (DAT_00680458 == -1) {
        FUN_00416b4c(puVar1 + 4,iVar2 + param_3 * iVar4 + param_2,iVar8,iVar9,iVar8,iVar4);
      }
      else {
        FUN_00416b4c(puVar1 + 4,iVar2 + ((iVar3 - param_3) + -1) * iVar4 + param_2,iVar8,iVar9,iVar8
                     ,-iVar4);
      }
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


// ==== FUN_0041a98d @ 0041a98d

undefined4 __thiscall FUN_0041a98d(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  short *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(short *)(param_1 + 0x80) == -1) {
    uVar1 = 2;
  }
  else {
    local_34 = *(short **)(param_1 + *(short *)(param_1 + 0x80) * 4);
    if (local_34 == (short *)0x0) {
      uVar1 = 0;
    }
    else {
      local_14 = (int)*local_34;
      local_20 = (int)local_34[1];
      local_18 = (int)local_34[2];
      local_24 = (int)local_34[3];
      local_30 = (local_18 - local_14) + 1;
      if ((param_2 != -0x8000) && (param_3 != -0x8000)) {
        local_18 = local_18 + (param_2 - local_14);
        local_24 = local_24 + (param_3 - local_20);
        local_14 = param_2;
        local_20 = param_3;
      }
      iVar3 = local_18;
      iVar2 = local_24;
      if (local_18 < local_14) {
        local_1c = local_18;
        local_18 = local_14;
        local_14 = iVar3;
      }
      if (local_24 < local_20) {
        local_1c = local_24;
        local_24 = local_20;
        local_20 = iVar2;
      }
      if (local_14 < 1) {
        local_14 = 0;
      }
      if (local_20 < 1) {
        local_20 = 0;
      }
      local_2c = DAT_0068044c;
      local_38 = DAT_00680450;
      local_28 = DAT_00680454;
      iVar2 = DAT_0068044c + -1;
      if (local_18 <= DAT_0068044c + -1) {
        iVar2 = local_18;
      }
      iVar3 = DAT_00680450 + -1;
      if (local_24 <= DAT_00680450 + -1) {
        iVar3 = local_24;
      }
      local_34 = local_34 + 4;
      local_10 = DAT_00680448;
      local_8 = (iVar2 - local_14) + 1;
      local_c = (iVar3 - local_20) + 1;
      local_48 = local_14 + local_8 + -1;
      local_44 = local_20 + local_c + -1;
      local_50 = local_14;
      local_4c = local_20;
      local_24 = iVar3;
      local_18 = iVar2;
      FUN_0041fcb3(&local_50);
      if (DAT_00680458 == -1) {
        local_10 = local_10 + local_20 * local_28 + local_14;
        FUN_00416b4c(local_10,local_34,local_8,local_c,local_28,local_30);
      }
      else {
        local_10 = local_10 + ((local_38 - local_20) + -1) * local_28 + local_14;
        FUN_00416b4c(local_10,local_34,local_8,local_c,-local_28,local_30);
      }
      local_40 = *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4);
      local_3c = local_40;
      FUN_00422290(local_40);
      *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
      *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0041ac32 @ 0041ac32

undefined4 __thiscall FUN_0041ac32(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  short *psVar1;
  undefined4 uVar2;
  
  if (*(short *)(param_1 + 0x80) == -1) {
    uVar2 = 0;
  }
  else {
    psVar1 = *(short **)(param_1 + *(short *)(param_1 + 0x80) * 4);
    if (psVar1 == (short *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_2 = (int)*psVar1;
      *param_3 = (int)psVar1[1];
      *param_4 = (int)psVar1[2];
      *param_5 = (int)psVar1[3];
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041acbc @ 0041acbc

undefined4 __thiscall FUN_0041acbc(int param_1,int *param_2)

{
  short *psVar1;
  undefined4 uVar2;
  
  if (*(short *)(param_1 + 0x80) == -1) {
    uVar2 = 0;
  }
  else {
    psVar1 = *(short **)(param_1 + *(short *)(param_1 + 0x80) * 4);
    if (psVar1 == (short *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_2 = (int)*psVar1;
      param_2[1] = (int)psVar1[1];
      param_2[2] = (int)psVar1[2];
      param_2[3] = (int)psVar1[3];
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041ad49 @ 0041ad49

void __fastcall FUN_0041ad49(int param_1)

{
  while (*(short *)(param_1 + 0x80) != -1) {
    FUN_00422290(*(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4));
    *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
  }
  return;
}


// ==== FUN_0041adba @ 0041adba

void FUN_0041adba(void)

{
  FUN_0041ad49();
  return;
}


// ==== FUN_0041add8 @ 0041add8

undefined4 __thiscall
FUN_0041add8(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  
  iVar7 = param_5;
  iVar6 = param_4;
  iVar4 = DAT_00680454;
  iVar3 = DAT_00680450;
  iVar2 = DAT_00680448;
  if (DAT_00680448 == 0) {
    uVar5 = 0;
  }
  else {
    if (param_4 < param_2) {
      param_4 = param_2;
      param_2 = iVar6;
    }
    if (param_5 < param_3) {
      param_5 = param_3;
      param_3 = iVar7;
    }
    iVar6 = param_2;
    if (param_2 < 1) {
      iVar6 = 0;
    }
    iVar7 = param_3;
    if (param_3 < 1) {
      iVar7 = 0;
    }
    iVar8 = DAT_0068044c + -1;
    if (param_4 <= DAT_0068044c + -1) {
      iVar8 = param_4;
    }
    iVar9 = DAT_00680450 + -1;
    if (param_5 <= DAT_00680450 + -1) {
      iVar9 = param_5;
    }
    iVar8 = (iVar8 - iVar6) + 1;
    iVar9 = (iVar9 - iVar7) + 1;
    if (*param_1 == 0) {
      param_1[1] = 0;
      uVar10 = iVar9 * iVar8 + 0xc;
      pvVar11 = operator_new(uVar10);
      *param_1 = (int)pvVar11;
      if (*param_1 == 0) {
        return 0;
      }
      param_1[1] = uVar10;
    }
    else {
      uVar10 = iVar9 * iVar8 + 0xc;
      if (param_6 == 0) {
        if (param_1[1] < (int)uVar10) {
          FUN_00422290(*param_1);
          pvVar11 = operator_new(uVar10);
          *param_1 = (int)pvVar11;
          if (*param_1 == 0) {
            return 0;
          }
          param_1[1] = uVar10;
        }
      }
      else {
        FUN_00422290(*param_1);
        pvVar11 = operator_new(uVar10);
        *param_1 = (int)pvVar11;
        if (*param_1 == 0) {
          return 0;
        }
        param_1[1] = uVar10;
      }
    }
    psVar1 = (short *)*param_1;
    *psVar1 = (short)iVar6;
    psVar1[1] = (short)iVar7;
    psVar1[2] = (short)iVar6 - (short)param_2;
    psVar1[3] = (short)iVar7 - (short)param_3;
    psVar1[4] = (short)iVar8;
    psVar1[5] = (short)iVar9;
    if (DAT_00680458 == -1) {
      FUN_00416b4c(psVar1 + 6,iVar2 + iVar7 * iVar4 + iVar6,iVar8,iVar9,iVar8,iVar4);
    }
    else {
      FUN_00416b4c(psVar1 + 6,iVar2 + ((iVar3 - iVar7) + -1) * iVar4 + iVar6,iVar8,iVar9,iVar8,
                   -iVar4);
    }
    param_1[2] = 1;
    param_1[3] = 1;
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0041b0e9 @ 0041b0e9

undefined4 __thiscall FUN_0041b0e9(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  short *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_1 == 0) || (param_1[3] == 0)) {
    uVar1 = 2;
  }
  else if ((param_2 == 0) && (param_1[2] == 0)) {
    uVar1 = 2;
  }
  else {
    local_34 = (short *)*param_1;
    param_1[2] = 0;
    local_14 = (int)*local_34;
    local_20 = (int)local_34[1];
    local_18 = local_34[4] + local_14 + -1;
    iVar2 = local_34[5] + local_20 + -1;
    local_30 = (local_18 - local_14) + 1;
    local_2c = DAT_0068044c;
    local_38 = DAT_00680450;
    local_28 = DAT_00680454;
    if ((param_4 != -0x8000) && (param_5 != -0x8000)) {
      iVar3 = local_18 + (param_4 - local_14);
      iVar2 = iVar2 + (param_5 - local_20);
      local_14 = param_4;
      local_20 = param_5;
      local_18 = iVar3;
      if (iVar3 < param_4) {
        local_18 = param_4;
        local_1c = iVar3;
        local_14 = iVar3;
      }
      local_24 = iVar2;
      if (iVar2 < param_5) {
        local_24 = param_5;
        local_20 = iVar2;
        local_1c = iVar2;
      }
      if (local_14 < 1) {
        local_14 = 0;
      }
      if (local_20 < 1) {
        local_20 = 0;
      }
      iVar3 = DAT_0068044c + -1;
      if (local_18 <= DAT_0068044c + -1) {
        iVar3 = local_18;
      }
      iVar2 = DAT_00680450 + -1;
      local_18 = iVar3;
      if (local_24 <= DAT_00680450 + -1) {
        iVar2 = local_24;
      }
    }
    local_24 = iVar2;
    local_34 = local_34 + 6;
    local_10 = DAT_00680448;
    local_8 = (local_18 - local_14) + 1;
    local_c = (local_24 - local_20) + 1;
    local_48 = local_14;
    local_44 = local_20;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    FUN_0041fcb3(&local_48);
    if (DAT_00680458 == -1) {
      local_10 = local_10 + local_20 * local_28 + local_14;
      FUN_00416b4c(local_10,local_34,local_8,local_c,local_28,local_30);
    }
    else {
      local_10 = local_10 + ((local_38 - local_20) + -1) * local_28 + local_14;
      FUN_00416b4c(local_10,local_34,local_8,local_c,-local_28,local_30);
    }
    if (param_3 != 0) {
      if (*param_1 != 0) {
        FUN_00422290(*param_1);
      }
      *param_1 = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041b3b9 @ 0041b3b9

undefined4 __thiscall
FUN_0041b3b9(int *param_1,short *param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  short *local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_1 == 0) || (param_1[3] == 0)) {
    uVar1 = 2;
  }
  else if ((param_5 == 0) && (param_1[2] == 0)) {
    uVar1 = 2;
  }
  else if (param_2 == (short *)0x0) {
    uVar1 = 0;
  }
  else {
    local_3c = (short *)*param_1;
    param_1[2] = 0;
    local_58 = (int)*local_3c;
    local_54 = (int)local_3c[1];
    local_44 = (int)local_3c[2];
    local_8 = (int)local_3c[3];
    local_24 = local_3c[4] + local_58 + -1;
    local_30 = local_3c[5] + local_54 + -1;
    local_38 = DAT_0068044c;
    local_40 = DAT_00680450;
    local_34 = DAT_00680454;
    local_3c = local_3c + 6;
    local_18 = DAT_00680448;
    local_c = (local_24 - local_58) + 1;
    local_14 = (local_30 - local_54) + 1;
    local_10 = (int)*param_2;
    local_1c = local_10 - (param_3 + local_44);
    local_28 = (int)param_2[1] - (param_4 + local_8);
    if ((local_1c < local_c) || (local_28 < local_14)) {
      uVar1 = 0;
    }
    else {
      if (param_2 == (short *)0x0) {
        local_48 = 0;
      }
      else {
        local_48 = (int)param_2 + (param_4 + local_8) * (int)*param_2 + param_3 + local_44 + 4;
      }
      local_50 = local_c + local_58 + -1;
      local_4c = local_54 + local_14 + -1;
      local_2c = local_54;
      local_20 = local_58;
      FUN_0041fcb3(&local_58);
      if (DAT_00680458 == -1) {
        local_18 = local_18 + local_2c * local_34 + local_20;
        FUN_00416b96(local_18,local_3c,local_48,local_c,local_14,local_34,local_c,local_10);
      }
      else {
        local_18 = local_18 + ((local_40 - local_2c) + -1) * local_34 + local_20;
        FUN_00416b96(local_18,local_3c,local_48,local_c,local_14,-local_34,local_c,local_10);
      }
      if (param_6 != 0) {
        if (*param_1 != 0) {
          FUN_00422290(*param_1);
        }
        *param_1 = 0;
        param_1[2] = 0;
        param_1[3] = 0;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0041b690 @ 0041b690

undefined4 __thiscall
FUN_0041b690(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  short *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_1 == 0) || (param_1[3] == 0)) {
    uVar1 = 2;
  }
  else if ((param_2 == 0) && (param_1[2] == 0)) {
    uVar1 = 2;
  }
  else {
    local_34 = (short *)*param_1;
    param_1[2] = 0;
    local_14 = (int)*local_34;
    local_20 = (int)local_34[1];
    local_18 = local_34[4] + local_14 + -1;
    local_24 = local_34[5] + local_20 + -1;
    local_30 = (local_18 - local_14) + 1;
    if ((param_5 != -0x8000) && (param_6 != -0x8000)) {
      local_18 = local_18 + (param_5 - local_14);
      local_24 = local_24 + (param_6 - local_20);
      local_14 = param_5;
      local_20 = param_6;
    }
    iVar3 = local_18;
    iVar2 = local_24;
    if (local_18 < local_14) {
      local_1c = local_18;
      local_18 = local_14;
      local_14 = iVar3;
    }
    if (local_24 < local_20) {
      local_1c = local_24;
      local_24 = local_20;
      local_20 = iVar2;
    }
    if (local_14 < 1) {
      local_14 = 0;
    }
    if (local_20 < 1) {
      local_20 = 0;
    }
    local_2c = DAT_0068044c;
    local_38 = DAT_00680450;
    local_28 = DAT_00680454;
    iVar2 = DAT_0068044c + -1;
    if (local_18 <= DAT_0068044c + -1) {
      iVar2 = local_18;
    }
    iVar3 = DAT_00680450 + -1;
    if (local_24 <= DAT_00680450 + -1) {
      iVar3 = local_24;
    }
    local_34 = local_34 + 6;
    local_10 = DAT_00680448;
    local_8 = (iVar2 - local_14) + 1;
    local_c = (iVar3 - local_20) + 1;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    local_48 = local_14;
    local_44 = local_20;
    local_24 = iVar3;
    local_18 = iVar2;
    FUN_0041fcb3(&local_48);
    if (DAT_00680458 == -1) {
      local_10 = local_10 + local_28 * local_20 + local_14;
      FUN_00416a90(local_10,local_34,local_8,local_c,local_28,local_30,param_3);
    }
    else {
      local_10 = local_10 + ((local_38 - local_20) + -1) * local_28 + local_14;
      FUN_00416a90(local_10,local_34,local_8,local_c,-local_28,local_30,param_3);
    }
    if (param_4 != 0) {
      if (*param_1 != 0) {
        FUN_00422290(*param_1);
      }
      *param_1 = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041b969 @ 0041b969

undefined4 __thiscall
FUN_0041b969(int *param_1,HDC param_2,int param_3,int param_4,int param_5,int param_6)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HDC hdc;
  HGDIOBJ h;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  
  if ((*param_1 == 0) || (param_1[3] == 0)) {
    uVar2 = 2;
  }
  else if ((param_3 == 0) && (param_1[2] == 0)) {
    uVar2 = 2;
  }
  else {
    psVar1 = (short *)*param_1;
    param_1[2] = 0;
    local_14 = (int)*psVar1;
    local_20 = (int)psVar1[1];
    local_18 = psVar1[4] + local_14 + -1;
    local_24 = psVar1[5] + local_20 + -1;
    iVar3 = (local_18 - local_14) + 1;
    if ((param_5 != -0x8000) && (param_6 != -0x8000)) {
      local_18 = local_18 + (param_5 - local_14);
      local_24 = local_24 + (param_6 - local_20);
      local_14 = param_5;
      local_20 = param_6;
    }
    iVar5 = local_18;
    iVar4 = local_24;
    if (local_18 < local_14) {
      local_18 = local_14;
      local_14 = iVar5;
    }
    if (local_24 < local_20) {
      local_24 = local_20;
      local_20 = iVar4;
    }
    if (local_14 < 1) {
      local_14 = 0;
    }
    if (local_20 < 1) {
      local_20 = 0;
    }
    iVar4 = DAT_0068044c + -1;
    if (local_18 <= DAT_0068044c + -1) {
      iVar4 = local_18;
    }
    iVar5 = DAT_00680450 + -1;
    if (local_24 <= DAT_00680450 + -1) {
      iVar5 = local_24;
    }
    iVar4 = (iVar4 - local_14) + 1;
    iVar5 = (iVar5 - local_20) + 1;
    if (DAT_00680458 == -1) {
      FUN_00416b4c(DAT_00680448 + DAT_00680454 * local_20 + local_14,psVar1 + 6,iVar4,iVar5,
                   DAT_00680454,iVar3);
    }
    else {
      FUN_00416b4c(DAT_00680448 + ((DAT_00680450 - local_20) + -1) * DAT_00680454 + local_14,
                   psVar1 + 6,iVar4,iVar5,-DAT_00680454,iVar3);
    }
    if (param_4 != 0) {
      if (*param_1 != 0) {
        FUN_00422290(*param_1);
      }
      *param_1 = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    DAT_006809cc = 0;
    hdc = CreateCompatibleDC(param_2);
    h = SelectObject(hdc,DAT_006809f0);
    BitBlt(param_2,local_14,local_20,iVar4,iVar5,hdc,local_14,local_20,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    GdiFlush();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0041bc96 @ 0041bc96

bool __thiscall FUN_0041bc96(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *param_2 = (int)*(short *)*param_1;
    *param_3 = (int)*(short *)(*param_1 + 2);
    *param_4 = (int)*(short *)(*param_1 + 8) + *param_2 + -1;
    *param_5 = (int)*(short *)(*param_1 + 10) + *param_3 + -1;
  }
  return iVar1 != 0;
}


// ==== FUN_0041bd09 @ 0041bd09

bool __thiscall FUN_0041bd09(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *param_2 = (int)*(short *)*param_1;
    param_2[1] = (int)*(short *)(*param_1 + 2);
    param_2[2] = (int)*(short *)(*param_1 + 8) + *param_2 + -1;
    param_2[3] = (int)*(short *)(*param_1 + 10) + param_2[1] + -1;
  }
  return iVar1 != 0;
}


// ==== FUN_0041bd80 @ 0041bd80

uint __thiscall FUN_0041bd80(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 local_8;
  
  if (*param_1 == 0) {
    uVar1 = (uint)param_1 & 0xffffff00;
  }
  else {
    if (*param_1 == 0) {
      local_8 = (int *)0x0;
    }
    else {
      param_1 = (int *)(*param_1 + 8);
      local_8 = param_1;
    }
    if (local_8 == (int *)0x0) {
      uVar1 = (uint)param_1 & 0xffffff00;
    }
    else {
      param_2 = (short)*local_8 * param_3 + param_2;
      uVar1 = CONCAT31((int3)((uint)param_2 >> 8),*(undefined1 *)(param_2 + 4 + (int)local_8));
    }
  }
  return uVar1;
}


// ==== FUN_0041be0a @ 0041be0a

void __thiscall FUN_0041be0a(int *param_1,int param_2,int param_3,undefined1 param_4)

{
  undefined4 local_8;
  
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      local_8 = (short *)0x0;
    }
    else {
      local_8 = (short *)(*param_1 + 8);
    }
    if (local_8 != (short *)0x0) {
      *(undefined1 *)(param_3 * *local_8 + param_2 + 4 + (int)local_8) = param_4;
    }
  }
  return;
}


// ==== FUN_0041bea0 @ 0041bea0

void FUN_0041bea0(void)

{
  FUN_0041beba();
  FUN_0041bf5b();
  return;
}


// ==== FUN_0041beba @ 0041beba

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041beba(void)

{
  DAT_00680440 = 0;
  _DAT_00680444 = 0;
  DAT_00680448 = 0;
  DAT_0068044c = 0;
  DAT_00680450 = 0;
  DAT_0068045c = 0;
  DAT_00680458 = 1;
  _DAT_00680888 = 0;
  DAT_006809cc = 0;
  DAT_006809d4 = 64000;
  _DAT_006809d0 = 1;
  DAT_006809e4 = 0;
  DAT_006809e8 = 0;
  return;
}


// ==== FUN_0041bf5b @ 0041bf5b

void FUN_0041bf5b(void)

{
  _atexit(FUN_0041bf78);
  return;
}


// ==== FUN_0041bf78 @ 0041bf78

void FUN_0041bf78(void)

{
  FUN_0041c207();
  return;
}


// ==== FUN_0041bf92 @ 0041bf92

undefined4 __thiscall FUN_0041bf92(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  HDC pHVar3;
  HBITMAP pHVar4;
  HGDIOBJ pvVar5;
  undefined4 uVar6;
  void *local_8;
  
  if (*param_1 != 0) {
    FUN_0041c2e0();
  }
  if (*param_2 == 0x5452494d) {
    if ((short)param_2[1] == 0x5247) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (*(short *)((int)param_2 + 6) != 2) {
      return 0;
    }
    param_2 = param_2 + 2;
  }
  FUN_004214d0();
  iVar2 = FUN_004215a4(param_1 + 0x12,param_2);
  param_1[7] = iVar2;
  param_1[8] = 0x28;
  *(undefined2 *)(param_1 + 0xb) = 1;
  *(undefined2 *)((int)param_1 + 0x2e) = 8;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[9] = param_2[1];
  param_1[6] = 1;
  param_1[10] = param_2[2] * param_1[6];
  pHVar3 = GetDC((HWND)0x0);
  *param_1 = (int)pHVar3;
  pHVar4 = CreateDIBSection((HDC)*param_1,(BITMAPINFO *)(param_1 + 8),0,&local_8,(HANDLE)0x0,0);
  param_1[1] = (int)pHVar4;
  DAT_006809f0 = param_1[1];
  param_1[2] = (int)local_8;
  pvVar5 = SelectObject((HDC)*param_1,(HGDIOBJ)param_1[1]);
  param_1[0x112] = (int)pvVar5;
  param_1[3] = param_1[9];
  param_1[4] = param_1[10];
  param_1[5] = ((uint)*(ushort *)((int)param_1 + 0x2e) * param_1[9] + 0x1f & 0xffffffe0) >> 3;
  if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
     (((param_1[3] == 0 || (param_1[4] == 0)) || (param_1[7] == 0)))) {
    uVar6 = 0;
  }
  else {
    FUN_0041c39f(0,0,param_2,0xffff);
    uVar6 = 1;
  }
  return uVar6;
}


// ==== FUN_0041c207 @ 0041c207

void __fastcall FUN_0041c207(int *param_1)

{
  HGDIOBJ ho;
  
  if (*param_1 != 0) {
    ho = SelectObject((HDC)*param_1,(HGDIOBJ)param_1[0x112]);
    DeleteObject(ho);
    ReleaseDC((HWND)0x0,(HDC)*param_1);
  }
  if (param_1[7] != 0) {
    DeleteObject((HGDIOBJ)param_1[7]);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[0x112] = 0;
  param_1[6] = 1;
  param_1[0x169] = 0;
  param_1[0x16a] = 0;
  return;
}


// ==== FUN_0041c2e0 @ 0041c2e0

void __fastcall FUN_0041c2e0(int *param_1)

{
  HGDIOBJ ho;
  
  if (*param_1 != 0) {
    ho = SelectObject((HDC)*param_1,(HGDIOBJ)param_1[0x112]);
    DeleteObject(ho);
    ReleaseDC((HWND)0x0,(HDC)*param_1);
  }
  if (param_1[7] != 0) {
    DeleteObject((HGDIOBJ)param_1[7]);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[0x112] = 0;
  param_1[6] = 1;
  return;
}


// ==== FUN_0041c39f @ 0041c39f

undefined4 __thiscall FUN_0041c39f(int *param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  int iVar1;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_c = 0;
  }
  else if (param_4 == (int *)0x0) {
    local_c = 0;
  }
  else {
    if (param_4[4] == 3) {
      local_8 = *param_4 + 0xc;
    }
    else {
      if ((param_4[8] == 0) && (*(ushort *)((int)param_4 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_4 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_4[8];
      }
      local_8 = local_70 * 4 + *param_4;
    }
    local_8 = (int)param_4 + local_8;
    local_58 = param_4;
    local_4c = param_4;
    local_68 = param_2;
    local_64 = param_3;
    local_60 = param_4[1] + param_2;
    local_5c = param_4[2] + param_3;
    if (param_1[0x165] == 64000) {
      local_48 = 0;
      local_40 = param_1[3];
      local_44 = 0;
      local_3c = param_1[4];
    }
    else {
      local_48 = param_1[0x165];
      local_44 = param_1[0x166];
      local_40 = param_1[0x167];
      local_3c = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_28,&local_68,&local_48);
    if (iVar1 != 0) {
      local_30 = ((uint)*(ushort *)((int)local_4c + 0xe) * local_4c[1] + 0x1f & 0xffffffe0) >> 3;
      local_34 = param_1[5];
      local_54 = local_28;
      local_10 = local_24;
      local_2c = local_20 - local_28;
      local_18 = local_1c - local_24;
      local_14 = local_28 - param_2;
      local_38 = local_24 - param_3;
      local_50 = local_8 + (local_4c[2] - (local_38 + local_18)) * local_30 + local_14;
      if (param_1[6] == -1) {
        local_34 = -local_34;
        local_6c = (local_18 + local_24 + -1) * param_1[5] + local_28 + param_1[2];
      }
      else {
        local_6c = (param_1[4] - (local_18 + local_24)) * param_1[5] + local_28 + param_1[2];
      }
      if ((param_5 & 0xffff) == 0xffff) {
        FUN_00416b4c(local_6c,local_50,local_2c,local_18,local_34,local_30);
      }
      else {
        FUN_00416a90(local_6c,local_50,local_2c,local_18,local_34,local_30,param_5);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_2c + local_54 + -1;
      local_78 = local_18 + local_10 + -1;
      FUN_0041fcb3(&local_84);
    }
  }
  return local_c;
}


// ==== FUN_0041c6f5 @ 0041c6f5

undefined4 __thiscall
FUN_0041c6f5(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8,uint param_9)

{
  int iVar1;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_c = 0;
  }
  else if (param_8 == (int *)0x0) {
    local_c = 0;
  }
  else {
    if (param_8[4] == 3) {
      local_8 = *param_8 + 0xc;
    }
    else {
      if ((param_8[8] == 0) && (*(ushort *)((int)param_8 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_8 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_8[8];
      }
      local_8 = local_70 * 4 + *param_8;
    }
    local_8 = (int)param_8 + local_8;
    local_58 = param_8;
    local_4c = param_8;
    if ((param_6 == 0) || (param_7 == 0)) {
      param_6 = param_8[1];
      param_7 = param_8[2];
      param_4 = 0;
      param_5 = 0;
    }
    local_68 = param_2;
    local_64 = param_3;
    local_60 = param_6 + param_2;
    local_5c = param_7 + param_3;
    if (param_1[0x165] == 64000) {
      local_48 = 0;
      local_40 = param_1[3];
      local_44 = 0;
      local_3c = param_1[4];
    }
    else {
      local_48 = param_1[0x165];
      local_44 = param_1[0x166];
      local_40 = param_1[0x167];
      local_3c = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_28,&local_68,&local_48);
    if (iVar1 != 0) {
      local_30 = ((uint)*(ushort *)((int)local_4c + 0xe) * local_4c[1] + 0x1f & 0xffffffe0) >> 3;
      local_34 = param_1[5];
      local_54 = local_28;
      local_10 = local_24;
      local_2c = local_20 - local_28;
      local_18 = local_1c - local_24;
      local_14 = (local_28 + param_4) - param_2;
      local_38 = (local_24 + param_5) - param_3;
      local_50 = local_8 + (local_4c[2] - (local_38 + local_18)) * local_30 + local_14;
      if (param_1[6] == -1) {
        local_34 = -local_34;
        local_6c = (local_24 + local_18 + -1) * param_1[5] + local_28 + param_1[2];
      }
      else {
        local_6c = (param_1[4] - (local_24 + local_18)) * param_1[5] + local_28 + param_1[2];
      }
      if ((param_9 & 0xffff) == 0xffff) {
        FUN_00416b4c(local_6c,local_50,local_2c,local_18,local_34,local_30);
      }
      else {
        FUN_00416a90(local_6c,local_50,local_2c,local_18,local_34,local_30,param_9);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_54 + local_2c + -1;
      local_78 = local_10 + local_18 + -1;
      FUN_0041fcb3(&local_84);
    }
  }
  return local_c;
}


// ==== FUN_0041ca7f @ 0041ca7f

void FUN_0041ca7f(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0041c6f5(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041cad7 @ 0041cad7

undefined4 __thiscall
FUN_0041cad7(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6,
            int param_7,undefined4 param_8,HDC param_9,undefined4 param_10)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041c6f5(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_10);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar2 = param_6 + param_2 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_7 + param_3 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_9);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_9,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_0041cc40 @ 0041cc40

void FUN_0041cc40(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_0041cad7(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5,param_6);
  return;
}


// ==== FUN_0041cc9c @ 0041cc9c

undefined4 __thiscall
FUN_0041cc9c(int param_1,int param_2,int param_3,int param_4,HDC param_5,undefined4 param_6)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041c39f(param_2,param_3,param_4,param_6);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar2 = *(int *)(param_4 + 4) + param_2 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = *(int *)(param_4 + 8) + param_3 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_5);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_5,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_0041ce13 @ 0041ce13

undefined4 __thiscall
FUN_0041ce13(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,
            short *param_7)

{
  int iVar1;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int *local_68;
  int local_64;
  int local_60;
  int *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_10 = 0;
  }
  else if ((param_6 == (int *)0x0) || (param_7 == (short *)0x0)) {
    local_10 = 0;
  }
  else {
    if (param_6[4] == 3) {
      local_8 = *param_6 + 0xc;
    }
    else {
      if ((param_6[8] == 0) && (*(ushort *)((int)param_6 + 0xe) < 9)) {
        local_84 = 1 << (*(byte *)((int)param_6 + 0xe) & 0x1f);
      }
      else {
        local_84 = param_6[8];
      }
      local_8 = local_84 * 4 + *param_6;
    }
    local_8 = (int)param_6 + local_8;
    local_68 = param_6;
    local_5c = param_6;
    local_28 = (int)*param_7;
    local_18 = (int)param_7[1];
    local_78 = param_2;
    local_74 = param_3;
    local_70 = param_2 + local_28;
    local_6c = param_3 + local_18;
    if (param_1[0x165] == 64000) {
      local_58 = 0;
      local_50 = param_1[3];
      local_54 = 0;
      local_4c = param_1[4];
    }
    else {
      local_58 = param_1[0x165];
      local_54 = param_1[0x166];
      local_50 = param_1[0x167];
      local_4c = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_38,&local_78,&local_58);
    if (iVar1 != 0) {
      local_40 = ((uint)*(ushort *)((int)local_5c + 0xe) * local_5c[1] + 0x1f & 0xffffffe0) >> 3;
      local_44 = param_1[5];
      local_64 = local_38;
      local_14 = local_34;
      local_3c = local_30 - local_38;
      local_20 = local_2c - local_34;
      local_1c = (param_4 + local_38) - param_2;
      local_48 = (param_5 + local_34) - param_3;
      local_c = local_38 - param_2;
      local_24 = (local_34 - param_3) + local_20 + -1;
      local_60 = local_8 + (local_5c[2] - (local_48 + local_20)) * local_40 + local_1c;
      if (param_7 == (short *)0x0) {
        local_80 = 0;
      }
      else {
        local_80 = (int)param_7 + *param_7 * local_24 + local_c + 4;
      }
      if (param_1[6] == -1) {
        local_44 = -local_44;
        local_7c = (local_20 + local_34 + -1) * param_1[5] + local_38 + param_1[2];
      }
      else {
        local_7c = (param_1[4] - (local_20 + local_34)) * param_1[5] + local_38 + param_1[2];
      }
      FUN_00416b96(local_7c,local_60,local_80,local_3c,local_20,local_44,local_40,-local_28);
      local_10 = 1;
      local_9c = local_64;
      local_98 = local_14;
      local_94 = local_3c + local_64 + -1;
      local_90 = local_20 + local_14 + -1;
      FUN_0041fcb3(&local_9c);
    }
  }
  return local_10;
}


// ==== FUN_0041d1c5 @ 0041d1c5

undefined4 __thiscall
FUN_0041d1c5(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,short *param_7,HDC param_8)

{
  int iVar1;
  int y;
  undefined4 uVar2;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_0041ce13(param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    if (*param_7 + param_2 + -1 < *(int *)(param_1 + 0xc) + -1) {
      param_2 = *param_7 + param_2;
    }
    else {
      param_2 = *(int *)(param_1 + 0xc);
    }
    if (param_7[1] + param_3 + -1 < *(int *)(param_1 + 0x10) + -1) {
      param_3 = param_7[1] + param_3;
    }
    else {
      param_3 = *(int *)(param_1 + 0x10);
    }
    if ((param_2 - iVar1 == 0) || (param_3 - y == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_8,iVar1,y,param_2 - iVar1,param_3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041d370 @ 0041d370

undefined4 __thiscall FUN_0041d370(int *param_1,int param_2,int param_3,short *param_4,int param_5)

{
  int iVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_4 == (short *)0x0))))
  {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_4;
    local_18 = (int)param_4[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_2;
      local_5c = param_3;
      local_58 = local_10 + param_2;
      local_54 = local_18 + param_3;
      if (param_1[0x165] == 64000) {
        local_48 = 0;
        local_40 = param_1[3];
        local_44 = 0;
        local_3c = param_1[4];
      }
      else {
        local_48 = param_1[0x165];
        local_44 = param_1[0x166];
        local_40 = param_1[0x167];
        local_3c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_2c,&local_60,&local_48);
      if (iVar1 != 0) {
        if (param_5 == 0) {
          local_34 = param_1[5];
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = local_2c - param_2;
          local_38 = local_28 - param_3;
          local_4c = (int)param_4 + local_10 * local_38 + local_14 + 4;
          if (param_1[6] == -1) {
            local_64 = param_1[5] * local_28 + local_2c + param_1[2];
          }
          else {
            local_34 = -local_34;
            local_64 = (param_1[4] - (local_28 + 1)) * param_1[5] + local_2c + param_1[2];
          }
          FUN_00416a90(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0041fcb3(&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_0041d5e7 @ 0041d5e7

undefined4 __thiscall
FUN_0041d5e7(int *param_1,int param_2,int param_3,short *param_4,undefined4 param_5)

{
  int iVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_4 == (short *)0x0))))
  {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_4;
    local_18 = (int)param_4[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_2;
      local_5c = param_3;
      local_58 = param_2 + local_10;
      local_54 = param_3 + local_18;
      if (param_1[0x165] == 64000) {
        local_48 = 0;
        local_40 = param_1[3];
        local_44 = 0;
        local_3c = param_1[4];
      }
      else {
        local_48 = param_1[0x165];
        local_44 = param_1[0x166];
        local_40 = param_1[0x167];
        local_3c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_2c,&local_60,&local_48);
      if (iVar1 != 0) {
        local_34 = param_1[5];
        local_50 = local_2c;
        local_c = local_28;
        local_30 = local_24 - local_2c;
        local_1c = local_20 - local_28;
        local_14 = local_2c - param_2;
        local_38 = local_28 - param_3;
        local_4c = (int)param_4 + local_38 * local_10 + local_14 + 4;
        if (param_1[6] == -1) {
          local_64 = param_1[5] * local_28 + local_2c + param_1[2];
        }
        else {
          local_34 = -local_34;
          local_64 = (param_1[4] - (local_28 + 1)) * param_1[5] + local_2c + param_1[2];
        }
        FUN_00416dc6(local_64,local_4c,local_30,local_1c,local_34,local_10,param_5);
        local_8 = 1;
        local_78 = local_50;
        local_74 = local_c;
        local_70 = local_30 + local_50 + -1;
        local_6c = local_1c + local_c + -1;
        FUN_0041fcb3(&local_78);
      }
    }
  }
  return local_8;
}


// ==== FUN_0041d84c @ 0041d84c

undefined4 __thiscall
FUN_0041d84c(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            short *param_8,int param_9)

{
  int iVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_8 == (short *)0x0))))
  {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_8;
    local_18 = (int)param_8[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      if ((param_6 == 0) || (param_7 == 0)) {
        param_4 = 0;
        param_5 = 0;
        param_6 = local_10;
        param_7 = local_18;
      }
      local_60 = param_2;
      local_5c = param_3;
      local_58 = param_2 + param_6;
      local_54 = param_3 + param_7;
      if (param_1[0x165] == 64000) {
        local_48 = 0;
        local_40 = param_1[3];
        local_44 = 0;
        local_3c = param_1[4];
      }
      else {
        local_48 = param_1[0x165];
        local_44 = param_1[0x166];
        local_40 = param_1[0x167];
        local_3c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_2c,&local_60,&local_48);
      if (iVar1 != 0) {
        if (param_9 == 0) {
          local_34 = param_1[5];
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = (param_4 + local_2c) - param_2;
          local_38 = (local_28 + param_5) - param_3;
          local_4c = (int)param_8 + local_38 * local_10 + local_14 + 4;
          if (param_1[6] == -1) {
            local_64 = param_1[5] * local_28 + local_2c + param_1[2];
          }
          else {
            local_34 = -local_34;
            local_64 = (param_1[4] - (local_28 + 1)) * param_1[5] + local_2c + param_1[2];
          }
          FUN_00416a90(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0041fcb3(&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_0041daf7 @ 0041daf7

void FUN_0041daf7(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0041d84c(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041db4f @ 0041db4f

undefined4 __thiscall
FUN_0041db4f(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6,
            int param_7,undefined4 param_8,HDC param_9)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041d84c(param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar2 = param_2 + param_6 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_3 + param_7 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_9);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_9,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_0041dcb6 @ 0041dcb6

void FUN_0041dcb6(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0041db4f(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041dd0e @ 0041dd0e

undefined4 __thiscall
FUN_0041dd0e(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            short *param_8,int param_9)

{
  int iVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_8 == (short *)0x0))))
  {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_8;
    local_18 = (int)param_8[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      if ((param_6 == 0) || (param_7 == 0)) {
        param_4 = 0;
        param_5 = 0;
        param_6 = local_10;
        param_7 = local_18;
      }
      local_60 = param_2;
      local_5c = param_3;
      local_58 = param_6 + param_2;
      local_54 = param_7 + param_3;
      if (param_1[0x165] == 64000) {
        local_48 = 0;
        local_40 = param_1[3];
        local_44 = 0;
        local_3c = param_1[4];
      }
      else {
        local_48 = param_1[0x165];
        local_44 = param_1[0x166];
        local_40 = param_1[0x167];
        local_3c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_2c,&local_60,&local_48);
      if (iVar1 != 0) {
        if (param_9 == 0) {
          local_34 = param_1[5];
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = (param_4 + local_2c) - param_2;
          local_38 = (param_5 + local_28) - param_3;
          local_4c = (int)param_8 + local_38 * local_10 + local_14 + 4;
          if (param_1[6] == -1) {
            local_64 = param_1[5] * local_28 + local_2c + param_1[2];
          }
          else {
            local_34 = -local_34;
            local_64 = (param_1[4] - (local_28 + 1)) * param_1[5] + local_2c + param_1[2];
          }
          FUN_00416b4c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0041fcb3(&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_0041dfb7 @ 0041dfb7

void FUN_0041dfb7(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0041dd0e(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041e00f @ 0041e00f

undefined4 __thiscall
FUN_0041e00f(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6,
            int param_7,undefined4 param_8,HDC param_9)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041dd0e(param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar2 = param_6 + param_2 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_7 + param_3 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_9);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_9,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_0041e176 @ 0041e176

void FUN_0041e176(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0041e00f(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041e1ce @ 0041e1ce

undefined4 __thiscall FUN_0041e1ce(int param_1,int param_2,int param_3,short *param_4,HDC param_5)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041d370(param_2,param_3,param_4,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar3 = *param_4 + param_2 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar3) {
      iVar3 = iVar4;
    }
    iVar4 = param_4[1] + param_3 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar3 = (iVar3 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar3 == 0) || (iVar4 == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_5);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_5,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041e33c @ 0041e33c

undefined4 __thiscall
FUN_0041e33c(int *param_1,int param_2,int param_3,int param_4,int param_5,short *param_6,
            short *param_7,int param_8)

{
  int iVar1;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_6 == (short *)0x0))))
  {
    local_c = 0;
  }
  else {
    local_18 = (int)*param_6;
    local_20 = (int)param_6[1];
    if ((local_18 == 0) || (local_20 == 0)) {
      local_c = 0;
    }
    else {
      local_2c = (int)*param_7;
      local_14 = (int)param_7[1];
      local_70 = param_2;
      local_6c = param_3;
      local_68 = param_2 + local_2c;
      local_64 = local_14 + param_3;
      if (param_1[0x165] == 64000) {
        local_58 = 0;
        local_50 = param_1[3];
        local_54 = 0;
        local_4c = param_1[4];
      }
      else {
        local_58 = param_1[0x165];
        local_54 = param_1[0x166];
        local_50 = param_1[0x167];
        local_4c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_3c,&local_70,&local_58);
      if (iVar1 != 0) {
        if (param_8 == 0) {
          local_44 = param_1[5];
          local_60 = local_3c;
          local_10 = local_38;
          local_40 = local_34 - local_3c;
          local_24 = local_30 - local_38;
          local_1c = (local_3c + param_4) - param_2;
          local_48 = (local_38 + param_5) - param_3;
          local_8 = local_3c - param_2;
          local_28 = local_38 - param_3;
          local_5c = (int)param_6 + local_18 * local_48 + local_1c + 4;
          if (param_7 == (short *)0x0) {
            local_78 = 0;
          }
          else {
            local_78 = (int)param_7 + *param_7 * local_28 + local_8 + 4;
          }
          if (param_1[6] == -1) {
            local_74 = param_1[5] * local_38 + local_3c + param_1[2];
          }
          else {
            local_44 = -local_44;
            local_74 = (param_1[4] - (local_38 + 1)) * param_1[5] + local_3c + param_1[2];
          }
          FUN_00416b96(local_74,local_5c,local_78,local_40,local_24,local_44,local_18,local_2c);
          local_c = 1;
          local_90 = local_60;
          local_8c = local_10;
          local_88 = local_60 + local_40 + -1;
          local_84 = local_10 + local_24 + -1;
          FUN_0041fcb3(&local_90);
        }
        else {
          local_c = 1;
        }
      }
    }
  }
  return local_c;
}


// ==== FUN_0041e672 @ 0041e672

undefined4 __thiscall
FUN_0041e672(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,short *param_7,HDC param_8)

{
  int iVar1;
  int y;
  undefined4 uVar2;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_0041e33c(param_2,param_3,param_4,param_5,param_6,param_7,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    if (*param_7 + param_2 + -1 < *(int *)(param_1 + 0xc) + -1) {
      param_2 = *param_7 + param_2;
    }
    else {
      param_2 = *(int *)(param_1 + 0xc);
    }
    if (param_7[1] + param_3 + -1 < *(int *)(param_1 + 0x10) + -1) {
      param_3 = param_7[1] + param_3;
    }
    else {
      param_3 = *(int *)(param_1 + 0x10);
    }
    if ((param_2 - iVar1 == 0) || (param_3 - y == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_8,iVar1,y,param_2 - iVar1,param_3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041e81f @ 0041e81f

undefined4 __thiscall FUN_0041e81f(int *param_1,int param_2,int param_3,short *param_4,int param_5)

{
  int iVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_4 == (short *)0x0))))
  {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_4;
    local_18 = (int)param_4[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_2;
      local_5c = param_3;
      local_58 = param_2 + local_10;
      local_54 = param_3 + local_18;
      if (param_1[0x165] == 64000) {
        local_48 = 0;
        local_40 = param_1[3];
        local_44 = 0;
        local_3c = param_1[4];
      }
      else {
        local_48 = param_1[0x165];
        local_44 = param_1[0x166];
        local_40 = param_1[0x167];
        local_3c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_2c,&local_60,&local_48);
      if (iVar1 != 0) {
        if (param_5 == 0) {
          local_34 = param_1[5];
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = local_2c - param_2;
          local_38 = local_28 - param_3;
          local_4c = (int)param_4 + local_38 * local_10 + local_14 + 4;
          if (param_1[6] == -1) {
            local_64 = param_1[5] * local_28 + local_2c + param_1[2];
          }
          else {
            local_34 = -local_34;
            local_64 = (param_1[4] - (local_28 + 1)) * param_1[5] + local_2c + param_1[2];
          }
          FUN_00416b4c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0041fcb3(&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_0041ea94 @ 0041ea94

undefined4 __thiscall FUN_0041ea94(int param_1,int param_2,int param_3,short *param_4,HDC param_5)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041e81f(param_2,param_3,param_4,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 < 1) {
      iVar1 = 0;
    }
    y = param_3;
    if (param_3 < 1) {
      y = 0;
    }
    iVar3 = *param_4 + param_2 + -1;
    iVar4 = *(int *)(param_1 + 0xc) + -1;
    if (iVar4 <= iVar3) {
      iVar3 = iVar4;
    }
    iVar4 = param_4[1] + param_3 + -1;
    iVar5 = *(int *)(param_1 + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar3 = (iVar3 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar3 == 0) || (iVar4 == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_006809cc = 0;
      hdc = CreateCompatibleDC(param_5);
      h = SelectObject(hdc,DAT_006809f0);
      BitBlt(param_5,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041ec02 @ 0041ec02

undefined4 __thiscall
FUN_0041ec02(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8,uint param_9)

{
  int iVar1;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_20 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_20 = 0;
  }
  else if (param_8 == (int *)0x0) {
    local_20 = 0;
  }
  else {
    if (param_8[4] == 3) {
      local_1c = *param_8 + 0xc;
    }
    else {
      if ((param_8[8] == 0) && (*(ushort *)((int)param_8 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_8 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_8[8];
      }
      local_1c = local_70 * 4 + *param_8;
    }
    local_1c = (int)param_8 + local_1c;
    local_18 = param_8;
    local_48 = param_8;
    if ((param_6 == 0) || (param_7 == 0)) {
      param_6 = param_1[3];
      param_7 = param_1[4];
      param_2 = 0;
      param_3 = 0;
    }
    local_58 = param_2;
    local_54 = param_3;
    local_50 = param_2 + param_6;
    local_4c = param_7 + param_3;
    local_10 = 0;
    local_14 = 0;
    local_c = param_8[1];
    local_8 = param_8[2];
    iVar1 = FUN_004184b8(&local_6c,&local_58,&local_14);
    if (iVar1 != 0) {
      local_34 = ((uint)*(ushort *)((int)local_48 + 0xe) * local_48[1] + 0x1f & 0xffffffe0) >> 3;
      local_44 = local_6c;
      local_24 = local_68;
      local_30 = local_64 - local_6c;
      local_2c = local_60 - local_68;
      local_28 = (local_6c + param_4) - param_2;
      local_3c = (param_5 + local_68) - param_3;
      if (param_1[6] == -1) {
        local_40 = param_1[5] * local_3c + local_28 + param_1[2];
        iVar1 = local_48[2] - (local_68 + 1);
        local_38 = -local_34;
      }
      else {
        local_40 = (param_1[4] - (local_2c + local_3c)) * param_1[5] + local_28 + param_1[2];
        iVar1 = local_48[2] - (local_2c + local_68);
        local_38 = local_34;
      }
      local_5c = local_1c + iVar1 * local_34 + local_6c;
      if ((param_9 & 0xffff) == 0xffff) {
        FUN_00416b4c(local_5c,local_40,local_30,local_2c,local_38,param_1[5]);
      }
      else {
        FUN_00416a90(local_5c,local_40,local_30,local_2c,local_38,param_1[5],param_9);
      }
      local_20 = 1;
    }
  }
  return local_20;
}


// ==== FUN_0041eef6 @ 0041eef6

undefined4 __thiscall
FUN_0041eef6(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            short *param_8,uint param_9)

{
  int iVar1;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  short *local_8;
  
  local_10 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_10 = 0;
  }
  else if (param_8 == (short *)0x0) {
    local_10 = 0;
  }
  else {
    local_1c = (int)*param_8;
    local_58 = (int)param_8[1];
    local_8 = param_8 + 2;
    if ((param_6 == 0) || (param_7 == 0)) {
      param_2 = 0;
      param_3 = 0;
      param_6 = local_1c;
      param_7 = local_58;
    }
    local_44 = param_2;
    local_40 = param_3;
    local_3c = param_6 + param_2;
    local_38 = param_7 + param_3;
    local_20 = 0;
    local_24 = 0;
    local_18 = local_58;
    local_c = local_1c;
    iVar1 = FUN_004184b8(&local_68,&local_44,&local_24);
    if (iVar1 != 0) {
      local_50 = local_68;
      local_14 = local_64;
      local_34 = local_60 - local_68;
      local_2c = local_5c - local_64;
      local_28 = (local_68 + param_4) - param_2;
      local_48 = (local_64 + param_5) - param_3;
      if (param_1[6] == -1) {
        local_30 = param_1[5];
        local_4c = param_1[5] * local_48 + local_28 + param_1[2];
      }
      else {
        local_30 = -param_1[5];
        local_4c = ((param_1[4] - local_48) + -1) * param_1[5] + local_28 + param_1[2];
      }
      local_54 = local_c * local_64 + local_68 + (int)local_8;
      if ((param_9 & 0xffff) == 0xffff) {
        FUN_00416b4c(local_54,local_4c,local_34,local_2c,local_c,local_30);
      }
      else {
        FUN_00416a90(local_54,local_4c,local_34,local_2c,local_c,local_30,param_9);
      }
      local_10 = 1;
    }
  }
  return local_10;
}


// ==== FUN_0041f155 @ 0041f155

undefined4 __thiscall FUN_0041f155(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    local_8 = 0;
  }
  else {
    if (param_2 == (int *)0x0) {
      if (param_1[0x165] == 64000) {
        local_18 = 0;
        local_10 = param_1[3];
        local_14 = 0;
        local_c = param_1[4];
      }
      else {
        local_18 = param_1[0x165];
        local_14 = param_1[0x166];
        local_10 = param_1[0x167];
        local_c = param_1[0x168];
      }
    }
    else {
      local_18 = *param_2;
      local_14 = param_2[1];
      local_10 = param_2[2];
      local_c = param_2[3];
    }
    iVar1 = local_10;
    iVar2 = local_14;
    local_20 = local_10 - local_18;
    local_24 = local_c - local_14;
    if (local_20 < 0) {
      local_20 = 1 - local_20;
      local_5c = local_10;
      local_10 = local_18;
      local_18 = iVar1;
    }
    if (local_24 < 0) {
      local_24 = 1 - local_24;
      local_5c = local_14;
      local_14 = local_c;
      local_c = iVar2;
    }
    if ((local_20 == 0) || (local_24 == 0)) {
      local_8 = 0;
    }
    else {
      if (param_1[0x165] == 64000) {
        local_50 = 0;
        local_48 = param_1[3];
        local_4c = 0;
        local_44 = param_1[4];
      }
      else {
        local_50 = param_1[0x165];
        local_4c = param_1[0x166];
        local_48 = param_1[0x167];
        local_44 = param_1[0x168];
      }
      iVar2 = FUN_004184b8(&local_38,&local_18,&local_50);
      if (iVar2 != 0) {
        local_40 = param_1[5];
        local_54 = local_38;
        local_1c = local_34;
        local_3c = local_30 - local_38;
        local_28 = local_2c - local_34;
        if (param_1[6] == -1) {
          local_58 = param_1[5] * local_34 + local_38 + param_1[2];
        }
        else {
          local_40 = -local_40;
          local_58 = (param_1[4] - (local_34 + 1)) * param_1[5] + local_38 + param_1[2];
        }
        FUN_00416d6e(local_58,local_3c,local_28,local_40,param_3);
        local_8 = 1;
        local_70 = local_54;
        local_6c = local_1c;
        local_68 = local_3c + local_54 + -1;
        local_64 = local_28 + local_1c + -1;
        FUN_0041fcb3(&local_70);
      }
    }
  }
  return local_8;
}


// ==== FUN_0041f433 @ 0041f433

void __thiscall
FUN_0041f433(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            short param_8)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041f6c4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    FUN_0041f6ce(unaff_ESI,unaff_EBX,param_1);
    return;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  if ((param_6 == 0) || (param_7 == 0)) {
    local_8 = 0xffffffff;
    FUN_0041f6bb();
    FUN_0041f6ce(unaff_ESI,unaff_EBX,param_1);
    return;
  }
  local_50 = param_4;
  local_4c = param_5;
  local_48 = param_6 + param_4;
  local_44 = param_7 + param_5;
  if (param_1[0x165] == 64000) {
    local_40 = 0;
    local_38 = param_1[3];
    local_3c = 0;
    local_34 = param_1[4];
  }
  else {
    local_40 = param_1[0x165];
    local_3c = param_1[0x166];
    local_38 = param_1[0x167];
    local_34 = param_1[0x168];
  }
  iVar1 = FUN_004184b8(&local_30,&local_50,&local_40);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0041f6bb();
    FUN_0041f6ce(unaff_ESI,unaff_EBX,param_1);
    return;
  }
  local_50 = param_2;
  local_4c = param_3;
  local_48 = (local_28 - local_30) + param_2;
  local_44 = (local_24 - local_2c) + param_3;
  iVar1 = FUN_004184b8(&local_30,&local_50,&local_40);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0041f6bb();
    FUN_0041f6ce(unaff_ESI,unaff_EBX,param_1);
    return;
  }
  FUN_0041add8(local_30,local_2c,local_28,local_24,1);
  if (param_8 == -1) {
    FUN_0041b0e9(1,param_2,param_3,0xffff8000);
  }
  else {
    FUN_0041b690((int)(char)param_8,1,param_2,param_3,0xffff8000);
  }
  local_8 = 0xffffffff;
  FUN_0041f6bb();
  FUN_0041f6ce(unaff_ESI,unaff_EBX,param_1);
  return;
}


// ==== FUN_0041f6bb @ 0041f6bb

void FUN_0041f6bb(void)

{
  FUN_00407600();
  return;
}


// ==== FUN_0041f6ce @ 0041f6ce

void FUN_0041f6ce(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0041f6df @ 0041f6df

void FUN_0041f6df(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  FUN_0041f433(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_0041f733 @ 0041f733

undefined4 __thiscall
FUN_0041f733(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            uint param_8)

{
  undefined4 uVar1;
  int iVar2;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || (param_1[7] == 0)) {
    uVar1 = 0;
  }
  else if ((param_6 == 0) || (param_7 == 0)) {
    uVar1 = 0;
  }
  else {
    local_54 = param_4;
    local_50 = param_5;
    local_4c = param_6 + param_4;
    local_48 = param_7 + param_5;
    if (param_1[0x165] == 64000) {
      local_3c = 0;
      local_34 = param_1[3];
      local_38 = 0;
      local_30 = param_1[4];
    }
    else {
      local_3c = param_1[0x165];
      local_38 = param_1[0x166];
      local_34 = param_1[0x167];
      local_30 = param_1[0x168];
    }
    iVar2 = FUN_004184b8(&local_20,&local_54,&local_3c);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_54 = param_2;
      local_50 = param_3;
      local_4c = (local_18 - local_20) + param_2;
      local_48 = (local_14 - local_1c) + param_3;
      iVar2 = FUN_004184b8(&local_20,&local_54,&local_3c);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        local_28 = param_1[5];
        local_44 = local_20;
        local_8 = local_1c;
        local_24 = local_18 - local_20;
        local_10 = local_14 - local_1c;
        local_c = (local_20 + param_4) - param_2;
        local_2c = (local_1c + param_5) - param_3;
        if (param_1[6] == -1) {
          local_58 = param_1[5] * local_1c + param_1[2] + local_20;
          local_40 = param_1[5] * local_2c + param_1[2] + local_c;
        }
        else {
          local_28 = -local_28;
          local_58 = (param_1[4] - (local_1c + 1)) * param_1[5] + local_20 + param_1[2];
          local_40 = (param_1[4] - (local_2c + 1)) * param_1[5] + local_c + param_1[2];
        }
        if ((param_8 & 0xffff) == 0xffff) {
          FUN_00416b4c(local_58,local_40,local_24,local_10,local_28,local_28);
        }
        else {
          FUN_00416a90(local_58,local_40,local_24,local_10,local_28,local_28,param_8);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// ==== FUN_0041f9ed @ 0041f9ed

void FUN_0041f9ed(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  FUN_0041f733(param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_0041fa41 @ 0041fa41

undefined4 FUN_0041fa41(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041d370(param_1,param_2,param_3 + 8,0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041c39f(param_1,param_2,param_3 + 8,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0041fad9 @ 0041fad9

undefined4 FUN_0041fad9(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041e81f(param_1,param_2,param_3 + 8,0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041c39f(param_1,param_2,param_3 + 8,0xffff);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0041fb74 @ 0041fb74

undefined4 FUN_0041fb74(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041e1ce(param_1,param_2,param_3 + 8,param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041cc9c(param_1,param_2,param_3 + 8,param_4,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0041fc12 @ 0041fc12

undefined4 FUN_0041fc12(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041ea94(param_1,param_2,param_3 + 8,param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041cc9c(param_1,param_2,param_3 + 8,param_4,0xffff);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0041fcb3 @ 0041fcb3

void __thiscall FUN_0041fcb3(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x590) != 0) {
    if (*(int *)(param_1 + 0x58c) == 0) {
      iVar1 = *(int *)(param_1 + 0x58c) * 0x10 + param_1;
      *(undefined4 *)(iVar1 + 0x44c) = *param_2;
      *(undefined4 *)(iVar1 + 0x450) = param_2[1];
      *(undefined4 *)(iVar1 + 0x454) = param_2[2];
      *(undefined4 *)(iVar1 + 0x458) = param_2[3];
      *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + 1;
    }
    else if (*(int *)(param_1 + 0x58c) < 0x14) {
      iVar1 = *(int *)(param_1 + 0x58c) * 0x10 + param_1;
      *(undefined4 *)(iVar1 + 0x44c) = *param_2;
      *(undefined4 *)(iVar1 + 0x450) = param_2[1];
      *(undefined4 *)(iVar1 + 0x454) = param_2[2];
      *(undefined4 *)(iVar1 + 0x458) = param_2[3];
      *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + 1;
      for (local_18 = 0; local_18 < *(int *)(param_1 + 0x58c) + -1; local_18 = local_18 + 1) {
        iVar1 = FUN_00418692(&local_14,(*(int *)(param_1 + 0x58c) + -1) * 0x10 + param_1 + 0x44c,
                             local_18 * 0x10 + param_1 + 0x44c);
        if (iVar1 != 0) {
          iVar1 = local_18 * 0x10 + param_1;
          *(undefined4 *)(iVar1 + 0x44c) = local_14;
          *(undefined4 *)(iVar1 + 0x450) = local_10;
          *(undefined4 *)(iVar1 + 0x454) = local_c;
          *(undefined4 *)(iVar1 + 0x458) = local_8;
          *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + -1;
LAB_0041fe66:
          if (*(int *)(param_1 + 0x58c) == 1) {
            return;
          }
          local_18 = 0;
          do {
            local_1c = local_18;
            if (*(int *)(param_1 + 0x58c) + -1 <= local_18) {
              return;
            }
            while (local_1c = local_1c + 1, local_1c < *(int *)(param_1 + 0x58c)) {
              iVar1 = FUN_00418692(&local_14,local_1c * 0x10 + param_1 + 0x44c,
                                   local_18 * 0x10 + param_1 + 0x44c);
              if (iVar1 != 0) {
                iVar1 = local_18 * 0x10 + param_1;
                *(undefined4 *)(iVar1 + 0x44c) = local_14;
                *(undefined4 *)(iVar1 + 0x450) = local_10;
                *(undefined4 *)(iVar1 + 0x454) = local_c;
                *(undefined4 *)(iVar1 + 0x458) = local_8;
                *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + -1;
                iVar1 = *(int *)(param_1 + 0x58c) * 0x10 + param_1;
                iVar2 = local_1c * 0x10 + param_1;
                *(undefined4 *)(iVar2 + 0x44c) = *(undefined4 *)(iVar1 + 0x44c);
                *(undefined4 *)(iVar2 + 0x450) = *(undefined4 *)(iVar1 + 0x450);
                *(undefined4 *)(iVar2 + 0x454) = *(undefined4 *)(iVar1 + 0x454);
                *(undefined4 *)(iVar2 + 0x458) = *(undefined4 *)(iVar1 + 0x458);
                goto LAB_0041fe66;
              }
            }
            local_18 = local_18 + 1;
          } while( true );
        }
      }
    }
    else {
      FUN_0041863c(&local_14,(*(int *)(param_1 + 0x58c) + -1) * 0x10 + param_1 + 0x44c,param_2);
      param_1 = (*(int *)(param_1 + 0x58c) + -1) * 0x10 + param_1;
      *(undefined4 *)(param_1 + 0x44c) = local_14;
      *(undefined4 *)(param_1 + 0x450) = local_10;
      *(undefined4 *)(param_1 + 0x454) = local_c;
      *(undefined4 *)(param_1 + 0x458) = local_8;
    }
  }
  return;
}


// ==== FUN_0041ff7f @ 0041ff7f

void __thiscall FUN_0041ff7f(int param_1,int *param_2,int *param_3,HDC param_4)

{
  int iVar1;
  int iVar2;
  HDC pHVar3;
  HGDIOBJ pvVar4;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = FUN_004185a3(param_2,param_3);
  if (iVar1 == 0) {
    FUN_0041876b(param_2);
    FUN_0041877b(param_2);
    if (*param_2 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = *param_2;
    }
    if (param_2[1] < 0) {
      local_24 = 0;
    }
    else {
      local_24 = param_2[1];
    }
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    if (param_2[2] <= iVar1) {
      iVar1 = param_2[2];
    }
    iVar2 = *(int *)(param_1 + 0x10) + -1;
    if (param_2[3] <= iVar2) {
      iVar2 = param_2[3];
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_006809cc = 0;
      pHVar3 = CreateCompatibleDC(param_4);
      pvVar4 = SelectObject(pHVar3,DAT_006809f0);
      BitBlt(param_4,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
    FUN_0041876b(param_3);
    FUN_0041877b(param_3);
    if (*param_3 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = *param_3;
    }
    if (param_3[1] < 0) {
      local_24 = 0;
    }
    else {
      local_24 = param_3[1];
    }
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    if (param_3[2] <= iVar1) {
      iVar1 = param_3[2];
    }
    iVar2 = *(int *)(param_1 + 0x10) + -1;
    if (param_3[3] <= iVar2) {
      iVar2 = param_3[3];
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_006809cc = 0;
      pHVar3 = CreateCompatibleDC(param_4);
      pvVar4 = SelectObject(pHVar3,DAT_006809f0);
      BitBlt(param_4,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  else {
    FUN_0041863c(&local_18,param_2,param_3);
    FUN_0041876b(&local_18);
    FUN_0041877b(&local_18);
    if (local_18 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_18;
    }
    if (local_14 < 0) {
      local_24 = 0;
    }
    else {
      local_24 = local_14;
    }
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    if (local_10 <= iVar1) {
      iVar1 = local_10;
    }
    iVar2 = *(int *)(param_1 + 0x10) + -1;
    if (local_c <= iVar2) {
      iVar2 = local_c;
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_006809cc = 0;
      pHVar3 = CreateCompatibleDC(param_4);
      pvVar4 = SelectObject(pHVar3,DAT_006809f0);
      BitBlt(param_4,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  return;
}


// ==== FUN_0042038a @ 0042038a

undefined4 __thiscall
FUN_0042038a(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,short *param_10,short *param_11,int param_12)

{
  int iVar1;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  if ((((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
       ((param_1[3] == 0 || (param_1[4] == 0)))) ||
      ((param_1[7] == 0 || ((param_10 == (short *)0x0 || (param_11 == (short *)0x0)))))) ||
     (param_12 == 0)) {
    local_10 = 0;
  }
  else {
    local_1c = (int)*param_10;
    local_24 = (int)param_10[1];
    if ((local_1c == 0) || (local_24 == 0)) {
      local_10 = 0;
    }
    else {
      if ((param_6 == 0) || (param_7 == 0)) {
        param_4 = 0;
        param_5 = 0;
        param_6 = local_1c;
        param_7 = local_24;
      }
      local_70 = param_2;
      local_6c = param_3;
      local_68 = param_6 + param_2;
      local_64 = param_7 + param_3;
      if (param_1[0x165] == 64000) {
        local_58 = 0;
        local_50 = param_1[3];
        local_54 = 0;
        local_4c = param_1[4];
      }
      else {
        local_58 = param_1[0x165];
        local_54 = param_1[0x166];
        local_50 = param_1[0x167];
        local_4c = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_38,&local_70,&local_58);
      if (iVar1 != 0) {
        local_18 = (int)*param_11;
        local_40 = param_1[5];
        local_60 = local_38;
        local_14 = local_34;
        local_3c = local_30 - local_38;
        local_28 = local_2c - local_34;
        local_20 = (param_4 + local_38) - param_2;
        local_48 = (param_5 + local_34) - param_3;
        local_5c = (int)param_10 + local_1c * local_48 + local_20 + 4;
        local_44 = (local_48 + param_9) * local_18 + local_20 + param_8;
        local_8 = (int)param_11 + local_44 + 4;
        local_c = param_12 + 4 + local_44;
        if (param_1[6] == -1) {
          local_74 = param_1[5] * local_34 + local_38 + param_1[2];
        }
        else {
          local_40 = -local_40;
          local_74 = (param_1[4] - (local_34 + 1)) * param_1[5] + local_38 + param_1[2];
        }
        FUN_00416ec4(local_74,local_5c,local_8,local_c,local_3c,local_28,local_40,local_1c,local_18)
        ;
        local_10 = 1;
      }
    }
  }
  return local_10;
}


// ==== FUN_00420652 @ 00420652

undefined4 __thiscall FUN_00420652(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
     (((param_1[3] == 0 || (param_1[4] == 0)) || (param_1[7] == 0)))) {
    local_8 = 0;
  }
  else {
    local_c = (param_4 - param_2) + 1;
    local_10 = (param_5 - param_3) + 1;
    local_4c = param_2;
    local_48 = param_3;
    local_44 = param_2 + local_c;
    local_40 = param_3 + local_10;
    if (param_1[0x165] == 64000) {
      local_3c = 0;
      local_34 = param_1[3];
      local_38 = 0;
      local_30 = param_1[4];
    }
    else {
      local_3c = param_1[0x165];
      local_38 = param_1[0x166];
      local_34 = param_1[0x167];
      local_30 = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_24,&local_4c,&local_3c);
    if (iVar1 != 0) {
      local_28 = local_1c - local_24;
      local_14 = local_18 - local_20;
      iVar1 = local_20 + local_14 + -1;
      if (param_1[6] == -1) {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_004219bc(param_1[5] * local_2c + param_1[2] + local_24,local_28);
        }
      }
      else {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_004219bc(((param_1[4] - local_2c) + -1) * param_1[5] + param_1[2] + local_24,local_28)
          ;
        }
      }
      local_8 = 1;
      local_60 = local_24;
      local_5c = local_20;
      local_58 = local_24 + local_28 + -1;
      local_54 = local_20 + local_14 + -1;
      FUN_0041fcb3(&local_60);
    }
  }
  return local_8;
}


// ==== FUN_00420885 @ 00420885

void __fastcall FUN_00420885(int param_1)

{
  int local_8;
  
  if (((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (*(int *)(param_1 + 0x10) != 0)) {
    if (*(int *)(param_1 + 0xc) < 0) {
      *(int *)(param_1 + 0xc) = -*(int *)(param_1 + 0xc);
    }
    for (local_8 = 0; local_8 < *(int *)(param_1 + 0x10); local_8 = local_8 + 1) {
    }
  }
  return;
}


// ==== FUN_00420907 @ 00420907

undefined4 __thiscall
FUN_00420907(int *param_1,int param_2,int param_3,int param_4,int param_5,short *param_6,
            short *param_7,undefined4 param_8)

{
  int iVar1;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) ||
     ((param_1[7] == 0 || ((param_6 == (short *)0x0 || (param_7 == (short *)0x0)))))) {
    local_c = 0;
  }
  else {
    local_14 = (int)*param_6;
    local_1c = (int)param_6[1];
    local_6c = (int)*param_7;
    if ((local_14 == 0) || (local_1c == 0)) {
      local_c = 0;
    }
    else {
      local_64 = param_2;
      local_60 = param_3;
      local_5c = local_14 + param_2;
      local_58 = local_1c + param_3;
      if (param_1[0x165] == 64000) {
        local_4c = 0;
        local_44 = param_1[3];
        local_48 = 0;
        local_40 = param_1[4];
      }
      else {
        local_4c = param_1[0x165];
        local_48 = param_1[0x166];
        local_44 = param_1[0x167];
        local_40 = param_1[0x168];
      }
      iVar1 = FUN_004184b8(&local_30,&local_64,&local_4c);
      if (iVar1 != 0) {
        local_38 = param_1[5];
        local_54 = local_30;
        local_10 = local_2c;
        local_34 = local_28 - local_30;
        local_20 = local_24 - local_2c;
        local_18 = local_30 - param_2;
        local_3c = local_2c - param_3;
        if (param_6 == (short *)0x0) {
          local_50 = 0;
        }
        else {
          local_50 = (int)param_6 + *param_6 * local_3c + local_18 + 4;
        }
        if (param_7 == (short *)0x0) {
          local_8 = 0;
        }
        else {
          local_8 = (int)param_7 + (local_2c + param_5) * (int)*param_7 + local_30 + param_4 + 4;
        }
        if (param_1[6] == -1) {
          local_68 = param_1[5] * local_2c + local_30 + param_1[2];
        }
        else {
          local_38 = -local_38;
          local_68 = (param_1[4] - (local_2c + 1)) * param_1[5] + local_30 + param_1[2];
        }
        FUN_00417029(local_68,local_50,local_8,local_34,local_20,local_38,local_14,local_6c,param_8,
                     0);
        local_c = 1;
        local_88 = local_54;
        local_84 = local_10;
        local_80 = local_34 + local_54 + -1;
        local_7c = local_10 + local_20 + -1;
        FUN_0041fcb3(&local_88);
      }
    }
  }
  return local_c;
}


// ==== FUN_00420c41 @ 00420c41

undefined4 __thiscall FUN_00420c41(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_4 == 0)))) {
    local_8 = 0;
  }
  else if ((local_10 == 0) || (local_14 == 0)) {
    local_8 = 0;
  }
  else {
    local_50 = param_2;
    local_4c = param_3;
    local_48 = local_10 + param_2;
    local_44 = local_14 + param_3;
    if (param_1[0x165] == 64000) {
      local_3c = 0;
      local_34 = param_1[3];
      local_38 = 0;
      local_30 = param_1[4];
    }
    else {
      local_3c = param_1[0x165];
      local_38 = param_1[0x166];
      local_34 = param_1[0x167];
      local_30 = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_28,&local_50,&local_3c);
    if (iVar1 != 0) {
      if (param_5 == 0) {
        local_40 = local_28;
        local_c = local_24;
        local_2c = local_20 - local_28;
        local_18 = local_1c - local_24;
        local_8 = 1;
        local_64 = local_28;
        local_60 = local_24;
        local_5c = local_28 + local_2c + -1;
        local_58 = local_24 + local_18 + -1;
        FUN_0041fcb3(&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00420df8 @ 00420df8

undefined4 __thiscall FUN_00420df8(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) ||
      ((param_1[3] == 0 || (param_1[4] == 0)))) || ((param_1[7] == 0 || (param_4 == 0)))) {
    local_8 = 0;
  }
  else if ((local_10 == 0) || (local_14 == 0)) {
    local_8 = 0;
  }
  else {
    local_50 = param_2;
    local_4c = param_3;
    local_48 = param_2 + local_10;
    local_44 = param_3 + local_14;
    if (param_1[0x165] == 64000) {
      local_3c = 0;
      local_34 = param_1[3];
      local_38 = 0;
      local_30 = param_1[4];
    }
    else {
      local_3c = param_1[0x165];
      local_38 = param_1[0x166];
      local_34 = param_1[0x167];
      local_30 = param_1[0x168];
    }
    iVar1 = FUN_004184b8(&local_28,&local_50,&local_3c);
    if (iVar1 != 0) {
      if (param_5 == 0) {
        local_40 = local_28;
        local_c = local_24;
        local_2c = local_20 - local_28;
        local_18 = local_1c - local_24;
        local_8 = 1;
        local_64 = local_28;
        local_60 = local_24;
        local_5c = local_2c + local_28 + -1;
        local_58 = local_18 + local_24 + -1;
        FUN_0041fcb3(&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00420fb0 @ 00420fb0

void FUN_00420fb0(void)

{
  FUN_00420fca();
  FUN_00420fe9();
  return;
}


// ==== FUN_00420fca @ 00420fca

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420fca(void)

{
  _DAT_006809f4 = 0x5452494d;
  return;
}


// ==== FUN_00420fe9 @ 00420fe9

void FUN_00420fe9(void)

{
  _atexit(FUN_00421006);
  return;
}


// ==== FUN_00421006 @ 00421006

void FUN_00421006(void)

{
  FUN_00421198();
  return;
}


// ==== FUN_00421020 @ 00421020

bool FUN_00421020(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0041bf92(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_004219f0();
    *puVar2 = DAT_00680448;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = DAT_0068044c + -1;
    puVar2[5] = 0;
    puVar2[6] = DAT_00680450 + -1;
    puVar2[7] = DAT_00680454;
  }
  return iVar1 != 0;
}


// ==== FUN_004210df @ 004210df

undefined4 * FUN_004210df(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_004219f0();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004219f0();
  *puVar1 = DAT_00680448;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = DAT_0068044c + -1;
  puVar1[5] = 0;
  puVar1[6] = DAT_00680450 + -1;
  puVar1[7] = DAT_00680454;
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_00421198 @ 00421198

void FUN_00421198(void)

{
  FUN_0041c2e0();
  return;
}


// ==== FUN_004211b7 @ 004211b7

void FUN_004211b7(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_004211e0 @ 004211e0

void FUN_004211e0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00421209 @ 00421209

uint FUN_00421209(int param_1)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 6) == 0) {
    uVar1 = (uint)*(ushort *)(param_1 + 8);
  }
  else if (*(short *)(param_1 + 6) == 2) {
    uVar1 = *(uint *)(param_1 + 0xc);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== FUN_00421283 @ 00421283

uint FUN_00421283(int param_1)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 6) == 0) {
    uVar1 = (uint)*(ushort *)(param_1 + 10);
  }
  else if (*(short *)(param_1 + 6) == 2) {
    uVar1 = *(uint *)(param_1 + 0x10);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== FUN_004212fe @ 004212fe

uint FUN_004212fe(int param_1)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 6) == 0) {
    uVar1 = (uint)*(ushort *)(param_1 + 8);
  }
  else if (*(short *)(param_1 + 6) == 2) {
    uVar1 = ((uint)*(ushort *)(param_1 + 0x16) * *(int *)(param_1 + 0xc) + 0x1f & 0xffffffe0) >> 3;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== FUN_0042138d @ 0042138d

int FUN_0042138d(int param_1)

{
  int *piVar1;
  int local_10;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(short *)(param_1 + 6) == 0) {
    param_1 = param_1 + 0xc;
  }
  else if (*(short *)(param_1 + 6) == 2) {
    if (*(int *)(param_1 + 0x18) == 3) {
      param_1 = *piVar1 + 0xc + (int)piVar1;
    }
    else {
      if ((*(int *)(param_1 + 0x28) == 0) && (*(ushort *)(param_1 + 0x16) < 9)) {
        local_10 = 1 << (*(byte *)(param_1 + 0x16) & 0x1f);
      }
      else {
        local_10 = *(int *)(param_1 + 0x28);
      }
      param_1 = (int)piVar1 + local_10 * 4 + *piVar1;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}


// ==== FUN_00421463 @ 00421463

int FUN_00421463(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  if (*(short *)(param_1 + 6) == 0) {
    iVar1 = 0;
  }
  else if (*(short *)(param_1 + 6) != 2) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_004214d0 @ 004214d0

void FUN_004214d0(void)

{
  HDC hdc;
  HPALETTE pHVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_0042d282; local_8 = local_8 + 1) {
    (&DAT_0042d284)[local_8 * 4] = 0;
    (&DAT_0042d285)[local_8 * 4] = 0;
    (&DAT_0042d286)[local_8 * 4] = 0;
    (&DAT_0042d287)[local_8 * 4] = 4;
  }
  hdc = GetDC((HWND)0x0);
  pHVar1 = CreatePalette((LOGPALETTE *)&DAT_0042d280);
  if (pHVar1 != (HPALETTE)0x0) {
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    RealizePalette(hdc);
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    DeleteObject(pHVar1);
  }
  ReleaseDC((HWND)0x0,hdc);
  return;
}


// ==== FUN_004215a4 @ 004215a4

void FUN_004215a4(int param_1,int *param_2)

{
  int iVar1;
  HDC hdc;
  int local_8;
  
  hdc = GetDC((HWND)0x0);
  GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)&DAT_0042d284);
  GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)&DAT_0042d65c);
  ReleaseDC((HWND)0x0,hdc);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_0042d284)[local_8 * 4];
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_0042d285)[local_8 * 4];
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_0042d286)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_0042d287)[local_8 * 4] = 0;
    *(undefined *)(param_1 + 0x3da + local_8 * 4) = (&DAT_0042d65c)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d9 + local_8 * 4) = (&DAT_0042d65d)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d8 + local_8 * 4) = (&DAT_0042d65e)[local_8 * 4];
    *(undefined1 *)(param_1 + 0x3db + local_8 * 4) = 0;
    (&DAT_0042d65f)[local_8 * 4] = 0;
  }
  iVar1 = *param_2;
  for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
    (&DAT_0042d284)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 2);
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_0042d284)[local_8 * 4];
    (&DAT_0042d285)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 1);
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_0042d285)[local_8 * 4];
    (&DAT_0042d286)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1);
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_0042d286)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_0042d287)[local_8 * 4] = 4;
  }
  CreatePalette((LOGPALETTE *)&DAT_0042d280);
  return;
}


// ==== FUN_004217a0 @ 004217a0

void FUN_004217a0(char param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_34;
  int local_30;
  uint local_20;
  int local_1c;
  
  iVar4 = 100 - param_2;
  DAT_006809f8 = param_1;
  bVar1 = (&DAT_00680488)[param_1 * 4];
  bVar2 = (&DAT_00680489)[param_1 * 4];
  bVar3 = (&DAT_0068048a)[param_1 * 4];
  for (local_30 = 0; local_30 < 0x100; local_30 = local_30 + 1) {
    uVar5 = ((uint)bVar1 * param_2 + (uint)(byte)(&DAT_00680488)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar5) {
      uVar5 = 0xff;
    }
    uVar6 = (param_2 * (uint)bVar2 + (uint)(byte)(&DAT_00680489)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar6) {
      uVar6 = 0xff;
    }
    uVar7 = (param_2 * (uint)bVar3 + (uint)(byte)(&DAT_0068048a)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    local_1c = 0;
    local_20 = 0xffffffff;
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      uVar8 = (uVar7 - (byte)(&DAT_0068048a)[local_34 * 4]) *
              (uVar7 - (byte)(&DAT_0068048a)[local_34 * 4]) +
              (uVar6 - (byte)(&DAT_00680489)[local_34 * 4]) *
              (uVar6 - (byte)(&DAT_00680489)[local_34 * 4]) +
              (uVar5 - (byte)(&DAT_00680488)[local_34 * 4]) *
              (uVar5 - (byte)(&DAT_00680488)[local_34 * 4]);
      if (uVar8 < local_20) {
        local_1c = local_34;
        local_20 = uVar8;
      }
    }
    (&DAT_00680a00)[local_30] = (undefined1)local_1c;
  }
  return;
}


// ==== FUN_004219bc @ 004219bc

void FUN_004219bc(undefined4 param_1,undefined4 param_2)

{
  FUN_0041744e(&DAT_00680a00,param_1,param_2);
  return;
}


// ==== FUN_004219f0 @ 004219f0

void FUN_004219f0(void)

{
  FUN_00417140();
  return;
}


// ==== FUN_00421a05 @ 00421a05

undefined4 * FUN_00421a05(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_004219f0();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004219f0();
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_00421a4e @ 00421a4e

undefined4 FUN_00421a4e(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004219f0();
  return *puVar1;
}


// ==== FUN_00421a65 @ 00421a65

undefined4 FUN_00421a65(void)

{
  int iVar1;
  
  iVar1 = FUN_004219f0();
  return *(undefined4 *)(iVar1 + 0x1c);
}


// ==== FUN_00421a7d @ 00421a7d

void FUN_00421a7d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00417146(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_00421aa9 @ 00421aa9

void FUN_00421aa9(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004178b6(param_1,param_2,param_3);
  return;
}


// ==== FUN_00421acd @ 00421acd

void FUN_00421acd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0041746f(param_1,param_2,param_3);
  return;
}


// ==== FUN_00421af1 @ 00421af1

void FUN_00421af1(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00417c28(param_1,param_2,param_3);
  return;
}


// ==== FUN_00421b15 @ 00421b15

void FUN_00421b15(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00417f9e(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_00421b41 @ 00421b41

void FUN_00421b41(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_004185df(param_1,param_1);
  }
  else {
    FUN_004185df(param_1,param_2);
  }
  return;
}


// ==== _memset @ 00421b80

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}


// ==== FUN_00421be0 @ 00421be0

uint * FUN_00421be0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00421cc8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00421cc8:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


// ==== FUN_00421bf0 @ 00421bf0

uint * FUN_00421bf0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_00421c0c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_00421c3f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x00421c5b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_00421c0c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x00421c5b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x00421c5b;
    }
  }
LAB_00421c3f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x00421c5b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00421cc8:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00421cc8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== __global_unwind2 @ 00421cd0

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x421ce8,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 00421d12

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_00421cf0;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00421da6(0x101);
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== __abnormal_termination @ 00421d7a

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio 1998 Release */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  
  iVar2 = 0;
  iVar1 = *unaff_FS_OFFSET;
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_00421cf0) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_00421d9d @ 00421d9d

void __fastcall FUN_00421d9d(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0042d698 = param_1;
  DAT_0042d694 = in_EAX;
  DAT_0042d69c = unaff_EBP;
  return;
}


// ==== FUN_00421da6 @ 00421da6

void FUN_00421da6(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0042d698 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0042d694 = in_EAX;
  DAT_0042d69c = unaff_EBP;
  return;
}


// ==== _JumpToContinuation @ 00421dc0

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x00421dec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== _CallMemberFunction0 @ 00421e00

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421e05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00421e10

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421e15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00421e20

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421e25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== _UnwindNestedFrames @ 00421e30

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x421e5c,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}


// ==== ___CxxFrameHandler @ 00421e90

/* Library Function - Single Match
    ___CxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4
___CxxFrameHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ==== _CallCatchBlock2 @ 00421ed0

/* Library Function - Single Match
    void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
   *,int,unsigned long)
   
   Library: Visual Studio 1998 Release */

void * __cdecl
_CallCatchBlock2(EHRegistrationNode *param_1,_s_FuncInfo *param_2,void *param_3,int param_4,
                ulong param_5)

{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *local_10;
  _s_FuncInfo *local_c;
  EHRegistrationNode *local_8;
  int local_4;
  
  local_c = param_2;
  local_8 = param_1;
  local_10 = &LAB_00421f40;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== _CallSETranslator @ 00421f70

/* Library Function - Single Match
    int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)

{
  int *unaff_FS_OFFSET;
  EHExceptionRecord *local_34;
  void *local_30;
  undefined4 *local_2c;
  code *local_28;
  _s_FuncInfo *local_24;
  EHRegistrationNode *local_20;
  int local_1c;
  EHRegistrationNode *local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = TranslatorGuardHandler;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x422007;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_0042d6d0)(*(undefined4 *)param_1,&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}


// ==== TranslatorGuardHandler @ 00422050

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
   
   Library: Visual Studio 1998 Release */

_EXCEPTION_DISPOSITION __cdecl
TranslatorGuardHandler
          (EHExceptionRecord *param_1,TranslatorGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  
  if (((byte)param_1[4] & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x004220af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// ==== `eh_vector_destructor_iterator' @ 004220c0

/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 1998 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426000;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_00422130();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00422130 @ 00422130

void FUN_00422130(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== __ArrayUnwind @ 00422150

/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 1998 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426010;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== `eh_vector_constructor_iterator' @ 004221f0

/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Library: Visual Studio 1998 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int local_20;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426020;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  local_20 = 0;
  if (0 < param_3) {
    do {
      (*param_4)(unaff_EDI);
      local_20 = local_20 + 1;
    } while (local_20 < param_3);
  }
  local_8 = 0xffffffff;
  FUN_00422260();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00422260 @ 00422260

void FUN_00422260(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== FUN_00422280 @ 00422280

int FUN_00422280(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== FUN_00422290 @ 00422290

void FUN_00422290(void *param_1)

{
  _free(param_1);
  return;
}


// ==== operator_new @ 004222a0

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== FID_conflict:_memcpy @ 004222b0

/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl FID_conflict__memcpy(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  int in_EDX;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if ((_Src < _Dst) && (_Dst < (void *)((int)_Src + _Size))) {
    puVar3 = (undefined4 *)((int)_Src + _Size);
    puVar5 = (undefined4 *)((int)_Dst + _Size);
    if (((uint)puVar5 & 3) == 0) {
      uVar1 = _Size >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        puVar3 = puVar3 + -1;
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *puVar5 = *puVar3;
      }
      switch(_Size & 3) {
      case 1:
switchD_00422379_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_00422379_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_00422379_caseD_3:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar3 + 1);
        return _Dst;
      }
    }
    else {
      puVar4 = (undefined1 *)((int)puVar3 + -1);
      puVar6 = (undefined1 *)((int)puVar5 + -1);
      if (_Size < 0xd) {
        for (; _Size != 0; _Size = _Size - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return _Dst;
      }
      uVar2 = -in_EDX & 3;
      uVar1 = _Size - uVar2;
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      puVar3 = (undefined4 *)(puVar4 + -3);
      puVar5 = (undefined4 *)(puVar6 + -3);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uVar1 & 3) {
      case 1:
        goto switchD_00422379_caseD_1;
      case 2:
        goto switchD_00422379_caseD_2;
      case 3:
        goto switchD_00422379_caseD_3;
      }
    }
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    for (uVar1 = _Size >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(_Size & 3) {
    case 1:
switchD_004222e0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_004222e0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_004222e0_caseD_3:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
      return _Dst;
    }
  }
  else {
    puVar4 = _Dst;
    if (_Size < 0xd) {
      for (; _Size != 0; _Size = _Size - 1) {
        *puVar4 = *(undefined1 *)_Src;
        _Src = (undefined1 *)((int)_Src + 1);
        puVar4 = puVar4 + 1;
      }
      return _Dst;
    }
    uVar2 = -(int)_Dst & 3;
    uVar1 = _Size - uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      _Src = (undefined4 *)((int)_Src + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(uVar1 & 3) {
    case 1:
      goto switchD_004222e0_caseD_1;
    case 2:
      goto switchD_004222e0_caseD_2;
    case 3:
      goto switchD_004222e0_caseD_3;
    }
  }
  return _Dst;
}


// ==== _strlen @ 00422400

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_00422420;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00422453:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00422420:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_00422453;
}


// ==== _malloc @ 00422480

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0042d6e0);
  return pvVar1;
}


// ==== __nh_malloc @ 004224a0

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (0xffffffe0 < _Size) {
    return (void *)0x0;
  }
  if (_Size == 0) {
    _Size = 1;
  }
  do {
    pvVar1 = (void *)0x0;
    if (_Size < 0xffffffe1) {
      pvVar1 = __heap_alloc(_Size);
    }
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (_NhFlag == 0) {
      return (void *)0x0;
    }
    iVar2 = __callnewh(_Size);
  } while (iVar2 != 0);
  return (void *)0x0;
}


// ==== __heap_alloc @ 004224f0

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  void *pvVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_0042df04) &&
     (pvVar1 = (void *)___sbh_alloc_block(_Size + 0xf >> 4), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  pvVar2 = HeapAlloc(DAT_00680d20,0,dwBytes);
  return pvVar2;
}


// ==== _free @ 00422530

/* Library Function - Single Match
    _free
   
   Library: Visual Studio 1998 Release */

void __cdecl _free(void *_Memory)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  if (_Memory != (void *)0x0) {
    iVar1 = ___sbh_find_block(_Memory,&local_4,&local_8);
    if (iVar1 != 0) {
      ___sbh_free_block(local_4,local_8,iVar1);
      return;
    }
    HeapFree(DAT_00680d20,0,_Memory);
  }
  return;
}


// ==== _strncmp @ 00422580

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


// ==== __onexit @ 004225c0

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = __msize(DAT_00680d18);
  if (sVar1 < (uint)((int)DAT_00680d14 + (4 - (int)DAT_00680d18))) {
    sVar1 = __msize(DAT_00680d18);
    pvVar2 = _realloc(DAT_00680d18,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      return (_onexit_t)0x0;
    }
    DAT_00680d14 = (undefined4 *)
                   (((int)DAT_00680d14 - (int)DAT_00680d18 & 0xfffffffcU) + (int)pvVar2);
    DAT_00680d18 = pvVar2;
  }
  *DAT_00680d14 = _Func;
  DAT_00680d14 = DAT_00680d14 + 1;
  return _Func;
}


// ==== _atexit @ 00422640

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}


// ==== _strcmp @ 004226a0

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_004226e4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_004226b0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_004226e4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_004226e4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_004226b0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_004226e4:
  return (uint)bVar5 * -2 + 1;
}


// ==== _rand @ 00422730

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_0042d6a0 = DAT_0042d6a0 * 0x343fd + 0x269ec3;
  return (DAT_0042d6a0 & 0x7fff0000) >> 0x10;
}


// ==== entry @ 00422760

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  HMODULE pHVar5;
  byte *pbVar6;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_00426030;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0042df20 = DVar2 >> 8 & 0xff;
  DAT_0042df14 = DVar2 >> 0x10;
  _DAT_0042df1c = DVar2 & 0xff;
  _DAT_0042df18 = _DAT_0042df1c * 0x100 + _DAT_0042df20;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00680d24 = (byte *)GetCommandLineA();
  DAT_0042d6a4 = ___crtGetEnvironmentStringsA();
  if ((DAT_0042d6a4 == (LPVOID)0x0) || (DAT_00680d24 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_00680d24;
  pbVar6 = DAT_00680d24;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_00680d24 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_00422865;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_00422865:
  bVar1 = *pbVar6;
  while ((bVar1 != 0 && (*pbVar6 < 0x21))) {
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar6;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  uVar4 = 10;
  if ((local_74.dwFlags & 1) != 0) {
    uVar4 = local_74._48_4_ & 0xffff;
  }
  uVar7 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  iVar3 = FUN_004149cc(pHVar5,uVar7,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(iVar3);
}


// ==== __amsg_exit @ 00422900

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0042d6b0 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_0042d6ac)(0xff);
  return;
}


// ==== ___InternalCxxFrameHandler @ 00422930

/* Library Function - Single Match
    ___InternalCxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4
___InternalCxxFrameHandler
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  if (*(int *)param_5 != 0x19930520) {
    _inconsistency();
  }
  if (((byte)param_1[4] & 0x66) != 0) {
    if ((*(int *)(param_5 + 4) != 0) && (param_6 == 0)) {
      ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
    }
    return 1;
  }
  if (*(int *)(param_5 + 0xc) != 0) {
    if (((*(int *)param_1 == -0x1f928c9d) && (0x19930520 < *(uint *)(param_1 + 0x14))) &&
       (*(code **)(*(int *)(param_1 + 0x1c) + 8) != (code *)0x0)) {
      uVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 8))
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar1;
    }
    FindHandler(param_1,param_2,param_3,param_4,param_5,(uchar)param_8,param_6,param_7);
  }
  return 1;
}


// ==== FindHandler @ 004229f0

/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  EHExceptionRecord *pEVar4;
  int iVar5;
  int iVar6;
  _s_HandlerType *p_Var7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  _s_TryBlockMapEntry *local_18;
  uint local_c;
  uint local_8;
  uint *local_4;
  
  iVar2 = *(int *)(param_2 + 8);
  if ((iVar2 < -1) || (*(int *)(param_5 + 4) <= iVar2)) {
    _inconsistency();
  }
  pEVar4 = DAT_0042d6bc;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_0042d6bc == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_0042d6bc;
    param_3 = DAT_0042d6c0;
    iVar5 = _ValidateRead(DAT_0042d6bc,1);
    if (iVar5 == 0) {
      _inconsistency();
    }
    if (((*(int *)pEVar4 == -0x1f928c9d) && (*(int *)(pEVar4 + 0x10) == 3)) &&
       ((*(int *)(pEVar4 + 0x14) == 0x19930520 && (*(int *)(pEVar4 + 0x1c) == 0)))) {
      _inconsistency();
    }
  }
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     (*(int *)(param_1 + 0x14) == 0x19930520)) {
    local_18 = GetRangeOfTrysToCheck(param_5,param_7,iVar2,&local_c,&local_8);
    if (local_c < local_8) {
      do {
        if ((*(int *)local_18 <= iVar2) && (iVar2 <= *(int *)(local_18 + 4))) {
          p_Var7 = *(_s_HandlerType **)(local_18 + 0x10);
          for (iVar5 = *(int *)(local_18 + 0xc); iVar5 != 0; iVar5 = iVar5 + -1) {
            piVar8 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
            for (iVar6 = *piVar8; iVar6 != 0; iVar6 = iVar6 + -1) {
              piVar8 = piVar8 + 1;
              iVar10 = *(int *)(p_Var7 + 4);
              local_4 = *(uint **)(param_1 + 0x1c);
              pbVar3 = (byte *)*piVar8;
              if ((iVar10 == 0) || (*(char *)(iVar10 + 8) == '\0')) {
LAB_00422ba6:
                bVar12 = true;
              }
              else {
                if (*(int *)(pbVar3 + 4) == iVar10) {
LAB_00422b7e:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_00422ba6;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00422b75:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_00422b7a;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00422b75;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_00422b7a:
                  if (iVar10 == 0) goto LAB_00422b7e;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_00422c04;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_00422c04:
        local_18 = local_18 + 0x14;
        local_c = local_c + 1;
      } while (local_c < local_8);
    }
    if (param_6 != '\0') {
      DestructExceptionObject(param_1,'\x01');
      return;
    }
  }
  else {
    if (param_6 == '\0') {
      FindHandlerForForeignException(param_1,param_2,param_3,param_4,param_5,iVar2,param_7,param_8);
      return;
    }
    terminate();
  }
  return;
}


// ==== FindHandlerForForeignException @ 00422c90

/* Library Function - Single Match
    void __cdecl FindHandlerForForeignException(struct EHExceptionRecord *,struct EHRegistrationNode
   *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,int,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
FindHandlerForForeignException
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  int iVar1;
  _s_TryBlockMapEntry *p_Var2;
  int iVar3;
  uint local_8;
  uint local_4;
  
  if (((DAT_0042d6d0 == 0) ||
      (iVar1 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,param_7,param_8),
      iVar1 == 0)) &&
     (p_Var2 = GetRangeOfTrysToCheck(param_5,param_7,param_6,&local_8,&local_4), local_8 < local_4))
  {
    do {
      if ((*(int *)p_Var2 <= param_6) && (param_6 <= *(int *)(p_Var2 + 4))) {
        iVar3 = *(int *)(p_Var2 + 0xc) * 0x10 + *(int *)(p_Var2 + 0x10);
        iVar1 = *(int *)(iVar3 + -0xc);
        if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
          CatchIt(param_1,param_2,param_3,param_4,param_5,(_s_HandlerType *)(iVar3 + -0x10),
                  (_s_CatchableType *)0x0,p_Var2,param_7,param_8);
        }
      }
      p_Var2 = p_Var2 + 0x14;
      local_8 = local_8 + 1;
    } while (local_8 < local_4);
  }
  return;
}


// ==== GetRangeOfTrysToCheck @ 00422d70

/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 1998 Release */

_s_TryBlockMapEntry * __cdecl
GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 0xc);
  local_c = uVar3;
  if (-1 < param_2) {
    piVar2 = (int *)(uVar3 * 0x14 + 4 + iVar1);
    local_8 = uVar3;
    do {
      if (uVar3 == 0xffffffff) {
        _inconsistency();
      }
      uVar3 = uVar3 - 1;
      if (((piVar2[-5] < param_3) && (param_3 <= piVar2[-4])) || (uVar3 == 0xffffffff)) {
        param_2 = param_2 + -1;
        local_c = local_8;
        local_8 = uVar3;
      }
      piVar2 = piVar2 + -5;
    } while (-1 < param_2);
  }
  uVar3 = uVar3 + 1;
  *param_4 = uVar3;
  *param_5 = local_c;
  if ((*(uint *)(param_1 + 0xc) < local_c) || (local_c < uVar3)) {
    _inconsistency();
  }
  return (_s_TryBlockMapEntry *)(iVar1 + uVar3 * 0x14);
}


// ==== ___FrameUnwindToState @ 00422e10

/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 1998 Release */

void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426040;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != param_4;
      iVar1 = *(int *)(*(int *)(param_3 + 8) + iVar1 * 8)) {
    local_8 = 0xffffffff;
    if ((iVar1 < 0) || (*(int *)(param_3 + 4) <= iVar1)) {
      _inconsistency();
    }
    local_8 = 0;
    iVar2 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar1 * 8);
    if (iVar2 != 0) {
      __CallSettingFrame_12(iVar2,param_1,0x103);
    }
  }
  local_8 = 0xffffffff;
  if (iVar1 != param_4) {
    _inconsistency();
  }
  *(int *)(param_1 + 8) = iVar1;
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== CatchIt @ 00422f00

/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10)

{
  void *pvVar1;
  
  if (param_7 != (_s_CatchableType *)0x0) {
    BuildCatchObject(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  ___FrameUnwindToState(param_2,param_4,param_5,*(undefined4 *)param_8);
  *(int *)(param_2 + 8) = *(int *)(param_8 + 4) + 1;
  pvVar1 = CallCatchBlock(param_1,param_2,param_3,param_5,*(void **)(param_6 + 0xc),param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}


// ==== CallCatchBlock @ 00422fa0

/* Library Function - Single Match
    void * __cdecl CallCatchBlock(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _CONTEXT *,struct _s_FuncInfo const *,void *,int,unsigned long)
   
   Library: Visual Studio 1998 Release */

void * __cdecl
CallCatchBlock(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
              _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426050;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  DAT_0042d6bc = param_1;
  DAT_0042d6c0 = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00423065();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== FUN_00423065 @ 00423065

void FUN_00423065(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  **(undefined4 **)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
  DAT_0042d6bc = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_0042d6c0 = *(undefined4 *)(unaff_EBP + -0x24);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (*(int *)(unaff_EBP + -0x1c) != 0)) {
    iVar2 = __abnormal_termination();
    DestructExceptionObject(*(EHExceptionRecord **)(unaff_EBP + 8),(uchar)iVar2);
  }
  return;
}


// ==== BuildCatchObject @ 004230e0

/* Library Function - Single Match
    void __cdecl BuildCatchObject(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _s_HandlerType const *,struct _s_CatchableType const *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
BuildCatchObject(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_s_HandlerType *param_3,
                _s_CatchableType *param_4)

{
  EHRegistrationNode *_Dst;
  int iVar1;
  void *pvVar2;
  undefined4 *unaff_FS_OFFSET;
  size_t _Size;
  undefined4 uVar3;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426068;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    _Dst = param_2 + *(int *)(param_3 + 8) + 0xc;
    local_8 = 0;
    if (((byte)*param_3 & 8) == 0) {
      if (((byte)*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
            _Size = *(size_t *)(param_4 + 0x14);
            pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
            FID_conflict__memcpy(_Dst,pvVar2,_Size);
            goto LAB_004232ce;
          }
        }
        else {
          iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) &&
             (iVar1 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar1 != 0)) {
            if (((byte)*param_4 & 4) == 0) {
              pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined4 *)(param_4 + 0x18),pvVar2);
            }
            else {
              uVar3 = 1;
              pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined4 *)(param_4 + 0x18),pvVar2,uVar3);
            }
            goto LAB_004232ce;
          }
        }
      }
      else {
        iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
        if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
          FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x18),*(size_t *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*(void **)_Dst != (void *)0x0)) {
            pvVar2 = AdjustPointer(*(void **)_Dst,(PMD *)(param_4 + 8));
            *(void **)_Dst = pvVar2;
          }
          goto LAB_004232ce;
        }
      }
    }
    else {
      iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
      if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
        pvVar2 = *(void **)(param_1 + 0x18);
        *(void **)_Dst = pvVar2;
        pvVar2 = AdjustPointer(pvVar2,(PMD *)(param_4 + 8));
        *(void **)_Dst = pvVar2;
        goto LAB_004232ce;
      }
    }
    _inconsistency();
  }
LAB_004232ce:
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== DestructExceptionObject @ 004232e0

/* Library Function - Single Match
    void __cdecl DestructExceptionObject(struct EHExceptionRecord *,unsigned char)
   
   Library: Visual Studio 1998 Release */

void __cdecl DestructExceptionObject(EHExceptionRecord *param_1,uchar param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426078;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== AdjustPointer @ 00423360

/* Library Function - Single Match
    void * __cdecl AdjustPointer(void *,struct PMD const &)
   
   Library: Visual Studio 1998 Release */

void * __cdecl AdjustPointer(void *param_1,PMD *param_2)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = (void *)(*(int *)param_2 + (int)param_1);
  iVar1 = *(int *)(param_2 + 4);
  if (-1 < iVar1) {
    pvVar2 = (void *)((int)pvVar2 +
                     iVar1 + *(int *)(*(int *)(iVar1 + (int)param_1) + *(int *)(param_2 + 8)));
  }
  return pvVar2;
}


// ==== __CallSettingFrame@12 @ 00423390

/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 extraout_var;
  
  puVar3 = &stack0xfffffffc;
  pcVar1 = (code *)FUN_00421d9d(param_3);
  (*pcVar1)(puVar3,extraout_var);
  iVar2 = *(int *)(puVar3 + 0x10);
  if (iVar2 == 0x100) {
    iVar2 = 2;
  }
  FUN_00421d9d(iVar2);
  return;
}


// ==== terminate @ 004233e0

/* Library Function - Single Match
    void __cdecl terminate(void)
   
   Library: Visual Studio 1998 Release */

void __cdecl terminate(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00426088;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_0042d6d4 != (code *)0x0) {
    local_8 = 1;
    (*DAT_0042d6d4)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 00423460

/* Library Function - Single Match
    void __cdecl _inconsistency(void)
   
   Library: Visual Studio 1998 Release */

void __cdecl _inconsistency(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004260a0;
  puStack_10 = &LAB_004234dc;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_terminate_0042d6dc != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_terminate_0042d6dc)();
  }
  local_8 = 0xffffffff;
  terminate();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00423599 @ 00423599

void FUN_00423599(int param_1)

{
  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}


// ==== __callnewh @ 004235c0

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_00680b00 != (code *)0x0) {
    iVar1 = (*DAT_00680b00)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __heap_init @ 004235f0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  int iVar1;
  
  DAT_00680d20 = HeapCreate(1,0x1000,0);
  if (DAT_00680d20 == (HANDLE)0x0) {
    return 0;
  }
  iVar1 = ___sbh_new_region();
  if (iVar1 == 0) {
    HeapDestroy(DAT_00680d20);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 00423630

/* Library Function - Single Match
    ___sbh_new_region
   
   Library: Visual Studio 1998 Release */

undefined ** ___sbh_new_region(void)

{
  undefined4 *lpAddress;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  undefined **lpMem;
  undefined4 *puVar4;
  
  if (DAT_0042def8 == 0) {
    lpMem = &PTR_LOOP_0042d6e8;
  }
  else {
    lpMem = HeapAlloc(DAT_00680d20,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_0042d6e8) {
        if (PTR_LOOP_0042d6e8 == (undefined *)0x0) {
          PTR_LOOP_0042d6e8 = (undefined *)&PTR_LOOP_0042d6e8;
        }
        if (PTR_LOOP_0042d6ec == (undefined *)0x0) {
          PTR_LOOP_0042d6ec = (undefined *)&PTR_LOOP_0042d6e8;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_0042d6e8;
        lpMem[1] = PTR_LOOP_0042d6ec;
        PTR_LOOP_0042d6ec = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[0x204] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)0x0;
      lpMem[3] = (undefined *)0x10;
      iVar2 = 0;
      do {
        if (iVar2 < 0x10) {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xf0;
        }
        else {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xff;
        }
        iVar3 = iVar2 + 1;
        *(undefined1 *)((int)lpMem + iVar2 + 0x410) = 0xf1;
        iVar2 = iVar3;
      } while (iVar3 < 0x400);
      puVar4 = lpAddress;
      for (iVar2 = 0x4000; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      if (lpAddress < lpMem[0x204] + 0x10000) {
        do {
          *lpAddress = lpAddress + 2;
          lpAddress[1] = 0xf0;
          *(undefined1 *)(lpAddress + 0x3e) = 0xff;
          lpAddress = lpAddress + 0x400;
        } while (lpAddress < lpMem[0x204] + 0x10000);
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_0042d6e8) {
    HeapFree(DAT_00680d20,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 004237a0

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0042defc == param_1) {
    PTR_LOOP_0042defc = param_1[1];
  }
  if (param_1 != &PTR_LOOP_0042d6e8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00680d20,0,param_1);
    return;
  }
  DAT_0042def8 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 00423800

/* Library Function - Single Match
    ___sbh_decommit_pages
   
   Library: Visual Studio 1998 Release */

void ___sbh_decommit_pages(int param_1)

{
  BOOL BVar1;
  char *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int local_4;
  
  puVar4 = PTR_LOOP_0042d6ec;
  do {
    puVar5 = puVar4;
    if (*(int *)(puVar4 + 0x810) != 0) {
      iVar3 = 0x3ff;
      pcVar2 = puVar4 + 0x40f;
      local_4 = 0;
      iVar6 = 0x3ff000;
      do {
        if (*pcVar2 == -0x10) {
          BVar1 = VirtualFree((LPVOID)(*(int *)(puVar4 + 0x810) + iVar6),0x1000,0x4000);
          if (BVar1 != 0) {
            *pcVar2 = -1;
            DAT_0042df00 = DAT_0042df00 + -1;
            if ((*(int *)(puVar4 + 0xc) == -1) || (iVar3 < *(int *)(puVar4 + 0xc))) {
              *(int *)(puVar4 + 0xc) = iVar3;
            }
            local_4 = local_4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar6 = iVar6 + -0x1000;
        iVar3 = iVar3 + -1;
        pcVar2 = pcVar2 + -1;
      } while (-1 < iVar6);
      puVar5 = *(undefined **)(puVar4 + 4);
      if ((local_4 != 0) && (puVar4[0x10] == -1)) {
        iVar3 = 1;
        pcVar2 = puVar4 + 0x11;
        do {
          if (*pcVar2 != -1) break;
          iVar3 = iVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          ___sbh_release_region(puVar4);
        }
      }
    }
    if ((puVar5 == PTR_LOOP_0042d6ec) || (puVar4 = puVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 004238e0

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_0042d6e8;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_0042d6e8) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 00423940

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Release */

void ___sbh_free_block(int param_1,int param_2,char *param_3)

{
  param_1 = (param_2 - *(int *)(param_1 + 0x810) >> 0xc) + param_1;
  *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + *param_3;
  *param_3 = '\0';
  *(undefined1 *)(param_1 + 0x410) = 0xf1;
  if ((*(char *)(param_1 + 0x10) == -0x10) &&
     (DAT_0042df00 = DAT_0042df00 + 1, DAT_0042df00 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00423990

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Release */

undefined * ___sbh_alloc_block(uint param_1)

{
  char *pcVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined **ppuVar11;
  int *piVar12;
  undefined *puVar13;
  
  piVar12 = (int *)PTR_LOOP_0042defc;
  do {
    cVar8 = (char)param_1;
    if (piVar12[0x204] != 0) {
      iVar10 = piVar12[2];
      if (iVar10 < 0x400) {
        iVar9 = iVar10 << 0xc;
        do {
          bVar2 = *(byte *)((int)piVar12 + iVar10 + 0x10);
          if (((param_1 <= bVar2) && (bVar2 != 0xff)) &&
             (param_1 < *(byte *)((int)piVar12 + iVar10 + 0x410))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page(piVar12[0x204] + iVar9,(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar10 + 0x10);
              PTR_LOOP_0042defc = (undefined *)piVar12;
              *pcVar1 = *pcVar1 - cVar8;
              piVar12[2] = iVar10;
              return puVar6;
            }
            *(char *)((int)piVar12 + iVar10 + 0x410) = cVar8;
          }
          iVar9 = iVar9 + 0x1000;
          iVar10 = iVar10 + 1;
        } while (iVar9 < 0x400000);
      }
      iVar10 = 0;
      iVar9 = 0;
      if (0 < piVar12[2]) {
        do {
          bVar2 = *(byte *)((int)piVar12 + iVar9 + 0x10);
          if (((param_1 <= bVar2) && (bVar2 != 0xff)) &&
             (param_1 < *(byte *)((int)piVar12 + iVar9 + 0x410))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page(piVar12[0x204] + iVar10,(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar9 + 0x10);
              PTR_LOOP_0042defc = (undefined *)piVar12;
              *pcVar1 = *pcVar1 - cVar8;
              piVar12[2] = iVar9;
              return puVar6;
            }
            *(char *)((int)piVar12 + iVar9 + 0x410) = cVar8;
          }
          iVar10 = iVar10 + 0x1000;
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar12[2]);
      }
    }
    piVar12 = (int *)*piVar12;
  } while ((int *)PTR_LOOP_0042defc != piVar12);
  ppuVar11 = &PTR_LOOP_0042d6e8;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_0042d6e8) {
      puVar6 = (undefined *)___sbh_new_region();
      if (puVar6 == (undefined *)0x0) {
        return (undefined *)0x0;
      }
      piVar12 = *(int **)(puVar6 + 0x810);
      *(char *)(piVar12 + 2) = cVar8;
      PTR_LOOP_0042defc = puVar6;
      *piVar12 = (int)piVar12 + param_1 + 8;
      piVar12[1] = 0xf0 - param_1;
      puVar6[0x10] = puVar6[0x10] - cVar8;
      return (undefined *)(*(int *)(puVar6 + 0x810) + 0x100);
    }
  }
  puVar3 = ppuVar11[3];
  puVar6 = puVar3 + 0x10;
  puVar5 = puVar3;
  if (0x3ff < (int)puVar6) {
    puVar6 = (undefined *)0x400;
  }
  do {
    puVar13 = puVar5 + 1;
    if ((int)puVar6 <= (int)puVar13) break;
    puVar4 = puVar5 + 0x11;
    puVar5 = puVar13;
  } while (*(char *)((int)ppuVar11 + (int)puVar4) == -1);
  puVar6 = VirtualAlloc(ppuVar11[0x204] + (int)puVar3 * 0x1000,((int)puVar13 - (int)puVar3) * 0x1000
                        ,0x1000,4);
  if (puVar6 != ppuVar11[0x204] + (int)puVar3 * 0x1000) {
    return (undefined *)0x0;
  }
  puVar6 = ppuVar11[3];
  piVar12 = (int *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  for (; (int)puVar6 < (int)puVar13; puVar6 = puVar6 + 1) {
    *piVar12 = (int)(piVar12 + 2);
    piVar12[1] = 0xf0;
    *(undefined1 *)(piVar12 + 0x3e) = 0xff;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x10)) = 0xf0;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x410)) = 0xf1;
    piVar12 = piVar12 + 0x400;
  }
  for (; ((int)puVar13 < 0x400 && (*(char *)((int)ppuVar11 + (int)(puVar13 + 0x10)) != -1));
      puVar13 = puVar13 + 1) {
  }
  puVar6 = ppuVar11[3];
  PTR_LOOP_0042defc = (undefined *)ppuVar11;
  ppuVar11[3] = (undefined *)0xffffffff;
  if ((int)puVar13 < 0x400) {
    ppuVar11[3] = puVar13;
  }
  puVar7 = (undefined4 *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  *(char *)(puVar7 + 2) = cVar8;
  ppuVar11[2] = puVar6;
  *(char *)((int)ppuVar11 + (int)(puVar6 + 0x10)) =
       *(char *)((int)ppuVar11 + (int)(puVar6 + 0x10)) - cVar8;
  *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
  puVar7[1] = puVar7[1] - param_1;
  return ppuVar11[0x204] + (int)puVar6 * 0x1000 + 0x100;
}


// ==== ___sbh_alloc_block_from_page @ 00423c10

/* Library Function - Single Match
    ___sbh_alloc_block_from_page
   
   Library: Visual Studio 1998 Release */

int ___sbh_alloc_block_from_page(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  bVar4 = (byte)param_3;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = bVar4;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)pbVar2 * 0x10 + (int)param_1 * -0xf + 0x80;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = *pbVar3;
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            param_1[1] = 0;
            *param_1 = (int)(param_1 + 2);
          }
          *pbVar6 = bVar4;
          return (int)pbVar6 * 0x10 + (int)param_1 * -0xf + 0x80;
        }
        if (pbVar2 == pbVar6) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar6 = (byte *)(param_1 + 2);
  while( true ) {
    while( true ) {
      if ((pbVar2 <= pbVar6) || ((byte *)((int)param_1 + 0xf7U) < pbVar6 + param_3)) {
        return 0;
      }
      if (*pbVar6 == 0) break;
      pbVar6 = pbVar6 + *pbVar6;
    }
    pbVar3 = pbVar6 + 1;
    uVar5 = 1;
    bVar1 = *pbVar3;
    while (bVar1 == 0) {
      pbVar3 = pbVar3 + 1;
      uVar5 = uVar5 + 1;
      bVar1 = *pbVar3;
    }
    if (param_3 <= uVar5) break;
    param_2 = param_2 - uVar5;
    pbVar6 = pbVar3;
    if (param_2 < param_3) {
      return 0;
    }
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    *param_1 = (int)(pbVar6 + param_3);
    param_1[1] = uVar5 - param_3;
  }
  else {
    param_1[1] = 0;
    *param_1 = (int)(param_1 + 2);
  }
  *pbVar6 = bVar4;
  return (int)pbVar6 * 0x10 + (int)param_1 * -0xf + 0x80;
}


// ==== ___sbh_resize_block @ 00423d90

/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 1998 Release */

undefined4 ___sbh_resize_block(int param_1,int *param_2,byte *param_3,uint param_4)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  uVar4 = 0;
  bVar2 = *param_3;
  uVar7 = (uint)bVar2;
  bVar6 = (byte)param_4;
  if (uVar7 <= param_4) {
    if ((uVar7 < param_4) && (pbVar9 = param_3 + param_4, pbVar9 <= param_2 + 0x3e)) {
      for (pbVar8 = param_3 + uVar7; (pbVar8 < pbVar9 && (*pbVar8 == 0)); pbVar8 = pbVar8 + 1) {
      }
      if (pbVar8 == pbVar9) {
        *param_3 = bVar6;
        if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar9)) {
          if (pbVar9 < param_2 + 0x3e) {
            iVar5 = 0;
            *param_2 = (int)pbVar9;
            bVar3 = *pbVar9;
            while (bVar3 == 0) {
              iVar5 = iVar5 + 1;
              pbVar9 = pbVar9 + 1;
              bVar3 = *pbVar9;
            }
            param_2[1] = iVar5;
          }
          else {
            param_2[1] = 0;
            *param_2 = (int)(param_2 + 2);
          }
        }
        pcVar1 = (char *)(((int)param_2 - *(int *)(param_1 + 0x810) >> 0xc) + 0x10 + param_1);
        *pcVar1 = *pcVar1 + (bVar2 - bVar6);
        uVar4 = 1;
      }
    }
    return uVar4;
  }
  *param_3 = bVar6;
  pcVar1 = (char *)(((int)param_2 - *(int *)(param_1 + 0x810) >> 0xc) + 0x10 + param_1);
  *pcVar1 = *pcVar1 + (bVar2 - bVar6);
  *(undefined1 *)(((int)param_2 - *(int *)(param_1 + 0x810) >> 0xc) + 0x410 + param_1) = 0xf1;
  return 1;
}


// ==== __cinit @ 00423e60

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_00680d1c != (code *)0x0) {
    (*DAT_00680d1c)();
  }
  __initterm(&DAT_00427028,&DAT_00427030);
  iVar1 = __initterm(&DAT_00427000,&DAT_00427024);
  return iVar1;
}


// ==== _exit @ 00423e90

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 00423eb0

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __exit(undefined4 param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 00423ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0042df50 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0042df4c = 1;
  DAT_0042df48 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00680d18 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00680d14 + -4), DAT_00680d18 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00680d18 <= puVar1);
    }
    __initterm(&DAT_00427034,&DAT_00427038);
  }
  __initterm(&DAT_0042703c,&DAT_00427040);
  if (param_3 == 0) {
    DAT_0042df50 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 00423f80

/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 1998 Release */

void __initterm(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ==== _realloc @ 00423fa0

/* Library Function - Single Match
    _realloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
    return pvVar1;
  }
  if (_NewSize != 0) {
    if (_NewSize < 0xffffffe1) {
      if (_NewSize == 0) {
        _NewSize = 0x10;
      }
      else {
        _NewSize = _NewSize + 0xf & 0xfffffff0;
      }
    }
    do {
      local_c = (undefined4 *)0x0;
      if (_NewSize < 0xffffffe1) {
        pbVar2 = (byte *)___sbh_find_block(_Memory,&local_4,&local_8);
        if (pbVar2 == (byte *)0x0) {
          local_c = HeapReAlloc(DAT_00680d20,0,_Memory,_NewSize);
        }
        else {
          if (_NewSize < DAT_0042df04) {
            iVar3 = ___sbh_resize_block(local_4,local_8,pbVar2,_NewSize >> 4);
            if (iVar3 == 0) {
              local_c = (undefined4 *)___sbh_alloc_block(_NewSize >> 4);
              if (local_c != (undefined4 *)0x0) {
                uVar5 = (uint)*pbVar2 << 4;
                if (_NewSize <= (uint)*pbVar2 << 4) {
                  uVar5 = _NewSize;
                }
                puVar6 = _Memory;
                puVar7 = local_c;
                for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *puVar7 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar7 = puVar7 + 1;
                }
                for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                  *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
                  puVar6 = (undefined4 *)((int)puVar6 + 1);
                  puVar7 = (undefined4 *)((int)puVar7 + 1);
                }
                ___sbh_free_block(local_4,local_8,pbVar2);
              }
            }
            else {
              local_c = _Memory;
            }
          }
          if (local_c != (undefined4 *)0x0) {
            return local_c;
          }
          local_c = HeapAlloc(DAT_00680d20,0,_NewSize);
          if (local_c != (undefined4 *)0x0) {
            uVar5 = (uint)*pbVar2 << 4;
            if (_NewSize <= (uint)*pbVar2 << 4) {
              uVar5 = _NewSize;
            }
            puVar6 = _Memory;
            puVar7 = local_c;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              puVar7 = (undefined4 *)((int)puVar7 + 1);
            }
            ___sbh_free_block(local_4,local_8,pbVar2);
          }
        }
      }
      if ((local_c != (undefined4 *)0x0) || (DAT_0042d6e0 == 0)) {
        return local_c;
      }
      iVar3 = __callnewh(_NewSize);
      if (iVar3 == 0) {
        return (void *)0x0;
      }
    } while( true );
  }
  _free(_Memory);
  return (void *)0x0;
}


// ==== __msize @ 00424150

/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 1998 Release */

size_t __cdecl __msize(void *_Memory)

{
  byte *pbVar1;
  SIZE_T SVar2;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  pbVar1 = (byte *)___sbh_find_block(_Memory,local_8,local_4);
  if (pbVar1 != (byte *)0x0) {
    return (uint)*pbVar1 << 4;
  }
  SVar2 = HeapSize(DAT_00680d20,0,_Memory);
  return SVar2;
}


// ==== __ismbblead @ 00424330

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype(_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 00424350

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_0042dff0 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_0042e2b2 + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 00424390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setenvp
   
   Library: Visual Studio 1998 Release */

int __cdecl __setenvp(void)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int extraout_EAX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  
  iVar8 = 0;
  cVar1 = *DAT_0042d6a4;
  pcVar7 = DAT_0042d6a4;
  while (cVar1 != '\0') {
    if (*pcVar7 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar10 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar7 = pcVar7 + ~uVar4;
    cVar1 = *pcVar7;
  }
  puVar2 = _malloc(iVar8 * 4 + 4);
  _DAT_0042df30 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_0042d6a4;
  pcVar7 = DAT_0042d6a4;
  do {
    if (cVar1 == '\0') {
      _free(DAT_0042d6a4);
      DAT_0042d6a4 = (char *)0x0;
      *puVar2 = 0;
      return extraout_EAX;
    }
    uVar4 = 0xffffffff;
    pcVar10 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if (*pcVar7 != '=') {
      pvVar3 = _malloc(~uVar4);
      *puVar2 = pvVar3;
      if (pvVar3 == (void *)0x0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar10 = pcVar7;
      do {
        pcVar9 = pcVar10;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar10 = (char *)*puVar2;
      puVar2 = puVar2 + 1;
      pcVar9 = pcVar9 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    pcVar7 = pcVar7 + ~uVar4;
    cVar1 = *pcVar7;
  } while( true );
}


// ==== __setargv @ 00424480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Release */

int __cdecl __setargv(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00680b08,0x104);
  _DAT_0042df40 = &DAT_00680b08;
  pcVar2 = &DAT_00680b08;
  if (*DAT_00680d24 != '\0') {
    pcVar2 = DAT_00680d24;
  }
  parse_cmdline(pcVar2,0,0,&local_8,&local_4);
  pvVar1 = _malloc(local_8 * 4 + local_4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_4);
  _DAT_0042df28 = pvVar1;
  _DAT_0042df24 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 00424520

/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 1998 Release */

void __cdecl
parse_cmdline(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    pbVar6 = param_1 + 1;
    bVar1 = *pbVar6;
    while ((bVar1 != 0x22 && (*pbVar6 != 0))) {
      if (((*(byte *)((int)&DAT_0042dff0 + *pbVar6 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        *param_3 = bVar1;
        param_3 = param_3 + 1;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar6;
        param_3 = param_3 + 1;
      }
      pbVar6 = pbVar6 + 1;
      bVar1 = *pbVar6;
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar6 == 0x22) {
      pbVar6 = pbVar6 + 1;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar6 = param_1 + 1;
      if ((*(byte *)((int)&DAT_0042dff0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00424590;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00424590:
      pbVar6 = pbVar6 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar3 = false;
  while (*pbVar6 != 0) {
    for (; (*pbVar6 == 0x20 || (*pbVar6 == 9)); pbVar6 = pbVar6 + 1) {
    }
    if (*pbVar6 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar2 = true;
      uVar5 = 0;
      bVar1 = *pbVar6;
      while (bVar1 == 0x5c) {
        pbVar6 = pbVar6 + 1;
        uVar5 = uVar5 + 1;
        bVar1 = *pbVar6;
      }
      if (*pbVar6 == 0x22) {
        pbVar4 = pbVar6;
        if ((uVar5 & 1) == 0) {
          if ((!bVar3) || (pbVar4 = pbVar6 + 1, *pbVar4 != 0x22)) {
            bVar2 = false;
            pbVar4 = pbVar6;
          }
          bVar3 = !bVar3;
        }
        uVar5 = uVar5 >> 1;
        pbVar6 = pbVar4;
      }
      while (uVar5 != 0) {
        uVar5 = uVar5 - 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar6;
      if ((bVar1 == 0) || ((!bVar3 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar2) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_0042dff0 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_004246c1;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_0042dff0 + bVar1 + 1) & 4) != 0) {
          *param_3 = bVar1;
          pbVar6 = pbVar6 + 1;
          pbVar4 = param_3 + 1;
          *param_5 = *param_5 + 1;
        }
        bVar1 = *pbVar6;
        param_3 = pbVar4 + 1;
        pbVar6 = pbVar6 + 1;
        *pbVar4 = bVar1;
        *param_5 = *param_5 + 1;
      }
      else {
LAB_004246c1:
        pbVar6 = pbVar6 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}


// ==== ___crtGetEnvironmentStringsA @ 00424700

/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 1998 Release */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char cVar1;
  WCHAR WVar2;
  size_t _Size;
  LPSTR lpMultiByteStr;
  CHAR *pCVar3;
  uint uVar4;
  LPCH pCVar5;
  char *pcVar6;
  WCHAR *pWVar8;
  int iVar10;
  LPCH pCVar11;
  LPWCH lpWideCharStr;
  CHAR *pCVar12;
  char *pcVar7;
  WCHAR *pWVar9;
  
  pCVar5 = (LPCH)0x0;
  lpWideCharStr = (LPWCH)0x0;
  if (DAT_0042dfe8 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0042dfe8 = 2;
    }
    else {
      DAT_0042dfe8 = 1;
    }
  }
  if (DAT_0042dfe8 != 1) {
    if (DAT_0042dfe8 != 2) {
      return (LPVOID)0x0;
    }
    if ((pCVar5 == (LPCH)0x0) && (pCVar5 = GetEnvironmentStrings(), pCVar5 == (LPCH)0x0)) {
      return (LPVOID)0x0;
    }
    cVar1 = *pCVar5;
    pcVar6 = pCVar5;
    while (cVar1 != '\0') {
      do {
        pcVar7 = pcVar6;
        pcVar6 = pcVar7 + 1;
      } while (*pcVar6 != '\0');
      pcVar6 = pcVar7 + 2;
      cVar1 = *pcVar6;
    }
    pcVar6 = pcVar6 + (1 - (int)pCVar5);
    pCVar3 = _malloc((size_t)pcVar6);
    if (pCVar3 != (CHAR *)0x0) {
      pCVar11 = pCVar5;
      pCVar12 = pCVar3;
      for (uVar4 = (uint)pcVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pCVar12 = *(undefined4 *)pCVar11;
        pCVar11 = pCVar11 + 4;
        pCVar12 = pCVar12 + 4;
      }
      for (uVar4 = (uint)pcVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pCVar12 = *pCVar11;
        pCVar11 = pCVar11 + 1;
        pCVar12 = pCVar12 + 1;
      }
      FreeEnvironmentStringsA(pCVar5);
      return pCVar3;
    }
    FreeEnvironmentStringsA(pCVar5);
    return (LPVOID)0x0;
  }
  if ((lpWideCharStr == (LPWCH)0x0) &&
     (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
    return (LPVOID)0x0;
  }
  WVar2 = *lpWideCharStr;
  pWVar8 = lpWideCharStr;
  while (WVar2 != L'\0') {
    do {
      pWVar9 = pWVar8;
      pWVar8 = pWVar9 + 1;
    } while (*pWVar8 != L'\0');
    pWVar8 = pWVar9 + 2;
    WVar2 = *pWVar8;
  }
  iVar10 = ((int)pWVar8 - (int)lpWideCharStr >> 1) + 1;
  _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar10,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if ((_Size != 0) && (lpMultiByteStr = _malloc(_Size), lpMultiByteStr != (LPSTR)0x0)) {
    iVar10 = WideCharToMultiByte(0,0,lpWideCharStr,iVar10,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                 (LPBOOL)0x0);
    if (iVar10 == 0) {
      _free(lpMultiByteStr);
      lpMultiByteStr = (LPSTR)0x0;
    }
    FreeEnvironmentStringsW(lpWideCharStr);
    return lpMultiByteStr;
  }
  FreeEnvironmentStringsW(lpWideCharStr);
  return (LPVOID)0x0;
}


// ==== __setmbcp @ 00424890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 1998 Release */

int __cdecl __setmbcp(int _CodePage)

{
  byte *pbVar1;
  byte bVar2;
  UINT CodePage;
  UINT *pUVar3;
  BOOL BVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  CodePage = getSystemCP(_CodePage);
  if (CodePage == DAT_0042e0f4) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_0042e118;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_0042dff0;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_0042e128 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_0042e110)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_0042dff0 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_0042e0f4 = CodePage;
      _DAT_0042e0f8 = _CPtoLCID(CodePage);
      DAT_0042e100 = *(undefined4 *)(&DAT_0042e11c + local_18 * 0x30);
      DAT_0042e104 = *(undefined4 *)(&DAT_0042e120 + local_18 * 0x30);
      DAT_0042e108 = *(undefined4 *)(local_18 * 0x30 + 0x42e124);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_0042e208);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_0042dff0;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_0042e0f8 = 0;
      DAT_0042e0f4 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_0042dff0 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_0042dff0 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_0042e0f4 = CodePage;
      _DAT_0042e0f8 = _CPtoLCID(CodePage);
    }
    DAT_0042e100 = 0;
    DAT_0042e104 = 0;
    DAT_0042e108 = 0;
    return 0;
  }
  if (DAT_0042e10c == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00424a70

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0042e10c = 1;
                    /* WARNING: Could not recover jumptable at 0x00424a8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0042e10c = 1;
                    /* WARNING: Could not recover jumptable at 0x00424aa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0042e4d0;
  }
  DAT_0042e10c = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00424ac0

/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Release */

undefined4 _CPtoLCID(undefined4 param_1)

{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}


// ==== setSBCS @ 00424b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0042dff0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0042e100 = 0;
  DAT_0042e0f4 = 0;
  _DAT_0042e0f8 = 0;
  DAT_0042e104 = 0;
  DAT_0042e108 = 0;
  return;
}


// ==== ___initmbctable @ 00424b50

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00424b60

/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __ioinit(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hFile;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  UINT UVar7;
  UINT UVar8;
  int iVar9;
  UINT *pUVar10;
  _STARTUPINFOA local_44;
  
  puVar1 = _malloc(0x100);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00680d10 = 0x20;
  DAT_00680c10 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00680c10 + 0x40);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar7 = *(UINT *)local_44.lpReserved2;
    pUVar10 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar3 = (byte *)(UVar7 + (int)pUVar10);
    if (0x7ff < (int)UVar7) {
      UVar7 = 0x800;
    }
    UVar8 = UVar7;
    if ((int)DAT_00680d10 < (int)UVar7) {
      piVar4 = &DAT_00680c14;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_00680d10;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00680d10 = DAT_00680d10 + 0x20;
        if (puVar1 < puVar1 + 0x40) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar6 = puVar1 + 2;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1 = puVar6;
          } while (puVar6 < (undefined4 *)(*piVar4 + 0x100));
        }
        piVar4 = piVar4 + 1;
        UVar8 = UVar7;
      } while ((int)DAT_00680d10 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00680c10 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
                   (uVar5 & 0x1f) * 8);
          *puVar1 = *(undefined4 *)pbVar3;
          *(byte *)(puVar1 + 1) = (byte)*pUVar10;
        }
        uVar5 = uVar5 + 1;
        pUVar10 = (UINT *)((int)pUVar10 + 1);
        pbVar3 = pbVar3 + 4;
      } while ((int)uVar5 < (int)UVar8);
    }
  }
  iVar9 = 0;
  do {
    piVar4 = DAT_00680c10 + iVar9 * 2;
    if (*piVar4 == -1) {
      DVar2 = 0xfffffff6;
      *(undefined1 *)(piVar4 + 1) = 0x81;
      if (iVar9 != 0) {
        DVar2 = (iVar9 == 1) - 0xc;
      }
      hFile = GetStdHandle(DVar2);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
      }
      else {
        *piVar4 = (int)hFile;
        if ((DVar2 & 0xff) == 2) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
        }
        else if ((DVar2 & 0xff) == 3) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x80;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 3);
  UVar7 = SetHandleCount(DAT_00680d10);
  return UVar7;
}


// ==== __FF_MSGBANNER @ 00424d40

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0042d6b0 == 1) || ((DAT_0042d6b0 == 0 && (DAT_0042d6b4 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0042e2a0 != (code *)0x0) {
      (*DAT_0042e2a0)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00424d80

/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 1998 Release */

void __cdecl __NMSG_WRITE(int param_1)

{
  char cVar1;
  int *piVar2;
  DWORD DVar3;
  HANDLE hFile;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];
  
  iVar4 = 0;
  piVar2 = &DAT_0042e210;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_0042e2a0);
  if ((&DAT_0042e210)[iVar4 * 2] == param_1) {
    if ((DAT_0042d6b0 == 1) || ((DAT_0042d6b0 == 0 && (DAT_0042d6b4 == 1)))) {
      if ((DAT_00680c10 == 0) ||
         (hFile = *(HANDLE *)(DAT_00680c10 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x42e214);
      uVar6 = 0xffffffff;
      pcVar9 = pcVar8;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar8,~uVar6 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar8 = "<program name unknown>";
        pCVar10 = local_104;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar8;
        pCVar10[2] = pcVar8[2];
      }
      pcVar8 = local_104;
      uVar6 = 0xffffffff;
      pcVar9 = local_104;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar6) {
        uVar6 = 0xffffffff;
        pcVar8 = local_104;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        pcVar8 = acStack_140 + ~uVar6;
        _strncpy(pcVar8,"...",3);
      }
      pcVar9 = "Runtime Error!\n\nProgram: ";
      pcVar11 = local_1a4;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar6 = 0xffffffff;
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = "\n\n";
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = *(char **)(iVar4 * 8 + 0x42e214);
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar4 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      ___crtMessageBoxA(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}


// ==== FUN_00424fb0 @ 00424fb0

int FUN_00424fb0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_00680c0c != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_00680c0c);
    if (iVar2 != 0) {
      iVar2 = (*DAT_00680c0c)(param_1);
      return iVar2;
    }
  }
  return 0;
}


// ==== FUN_00425010 @ 00425010

void FUN_00425010(void)

{
  SetUnhandledExceptionFilter(DAT_00680c0c);
  return;
}


// ==== _ValidateRead @ 00425020

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 00425040

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateWrite(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateExecute @ 00425060

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== _abort @ 00425080

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 1998 Release */

void __cdecl _abort(void)

{
  __NMSG_WRITE(10);
  _raise(0x16);
  __exit(3);
  return;
}


// ==== ___crtMessageBoxA @ 004250a0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0042e4d4 != (FARPROC)0x0) {
LAB_004250ef:
    if (DAT_0042e4d8 != (FARPROC)0x0) {
      iVar1 = (*DAT_0042e4d8)();
    }
    if ((iVar1 != 0) && (DAT_0042e4dc != (FARPROC)0x0)) {
      iVar1 = (*DAT_0042e4dc)(iVar1);
    }
    iVar1 = (*DAT_0042e4d4)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0042e4d4 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0042e4d4 != (FARPROC)0x0) {
      DAT_0042e4d8 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0042e4dc = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_004250ef;
    }
  }
  return 0;
}


// ==== _strncpy @ 00425140

/* Library Function - Single Match
    _strncpy
   
   Library: Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x0042517e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_004251bb;
        goto LAB_00425229;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00425225:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00425229:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_004251bb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00425225;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00425225;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00425225;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0042517e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_004251bb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _raise @ 00425240

/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Release */

int __cdecl _raise(int _SigNum)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 local_4;
  
  switch(_SigNum) {
  case 2:
    puVar5 = &DAT_0042e4e0;
    pcVar6 = DAT_0042e4e0;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    iVar3 = siglookup(_SigNum);
    puVar5 = (undefined4 *)(iVar3 + 8);
    pcVar6 = (code *)*puVar5;
    break;
  case 0xf:
    puVar5 = &DAT_0042e4ec;
    pcVar6 = DAT_0042e4ec;
    break;
  case 0x15:
    puVar5 = &DAT_0042e4e4;
    pcVar6 = DAT_0042e4e4;
    break;
  case 0x16:
    puVar5 = &DAT_0042e4e8;
    pcVar6 = DAT_0042e4e8;
  }
  if (pcVar6 == (code *)0x1) {
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    __exit(3);
  }
  uVar2 = DAT_0042dfe0;
  uVar1 = DAT_0042dfdc;
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar4 = local_4, _SigNum == 4)) {
    DAT_0042dfe0 = 0;
    uVar4 = uVar2;
    if (_SigNum == 8) {
      DAT_0042dfdc = 0x8c;
      local_4 = uVar1;
      goto LAB_0042530c;
    }
  }
  else {
LAB_0042530c:
    if (_SigNum == 8) {
      if (DAT_0042dfd0 < DAT_0042dfd4 + DAT_0042dfd0) {
        puVar5 = (undefined4 *)(DAT_0042dfd0 * 0xc + 0x42df60);
        iVar3 = DAT_0042dfd4;
        do {
          *puVar5 = 0;
          puVar5 = puVar5 + 3;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      goto LAB_0042534d;
    }
  }
  *puVar5 = 0;
LAB_0042534d:
  if (_SigNum == 8) {
    (*pcVar6)(8,DAT_0042dfdc);
  }
  else {
    (*pcVar6)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_0042dfdc = local_4;
  }
  DAT_0042dfe0 = uVar4;
  return 0;
}


// ==== siglookup @ 004253d0

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_0042df58;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_0042df58 + DAT_0042dfd8 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


