// ==== FUN_00401000 @ 00401000

HGLOBAL __cdecl FUN_00401000(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00423348 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_00423348 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_00401078 @ 00401078

HGLOBAL __cdecl FUN_00401078(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00423348 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_00423348 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_00423348 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_00401112 @ 00401112

undefined4 __cdecl FUN_00401112(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_00420040; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_00423348 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_00423348 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_00423348 + local_18 * 4),hResInfo);
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


// ==== FUN_00401223 @ 00401223

bool __cdecl FUN_00401223(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_00420040 <= local_18) {
LAB_00401291:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_00423348 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_00423348 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_00423348 + local_18 * 4),local_14);
      goto LAB_00401291;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_00401357 @ 00401357

HRSRC __cdecl FUN_00401357(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_00423348 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_004013bc @ 004013bc

HGLOBAL __cdecl FUN_004013bc(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_00423348 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_0040141d @ 0040141d

INT_PTR __cdecl FUN_0040141d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_00423348 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_0040148b @ 0040148b

HACCEL __cdecl FUN_0040148b(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_00423348 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_004014ed @ 004014ed

HICON __cdecl FUN_004014ed(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_00423348 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040154e @ 0040154e

HMENU __cdecl FUN_0040154e(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_00423348 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_004015b0 @ 004015b0

int __cdecl FUN_004015b0(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00420040 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_00423348 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_00401619 @ 00401619

HBITMAP __cdecl FUN_00401619(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_00420040 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_00423348 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040167a @ 0040167a

void FUN_0040167a(void)

{
  DAT_00420040 = 0;
  return;
}


// ==== FUN_00401694 @ 00401694

bool __cdecl FUN_00401694(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00420040 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_00423348 + DAT_00420040 * 4) = param_1;
    DAT_00420040 = DAT_00420040 + 1;
  }
  return bVar1;
}


// ==== FUN_004016d3 @ 004016d3

undefined4 __cdecl FUN_004016d3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00420040 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_00423348 + DAT_00420040 * 4) = pHVar2;
      DAT_00420040 = DAT_00420040 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00401733 @ 00401733

bool __cdecl FUN_00401733(LPCSTR param_1,uint *param_2)

{
  bool bVar1;
  HKEY local_414;
  uint local_410 [256];
  DWORD local_10;
  LSTATUS local_c;
  DWORD local_8;
  
  _memset(param_2,0,0x100);
  local_8 = 1;
  local_414 = (HKEY)0x0;
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_004202cc,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0041afd0(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040180b @ 0040180b

bool __cdecl FUN_0040180b(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040184d @ 0040184d

undefined4 FUN_0040184d(void)

{
  return 1;
}


// ==== FUN_00401865 @ 00401865

void __cdecl FUN_00401865(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_0041afe0(local_104,(uint *)&DAT_00420300);
  }
  FUN_0041afe0(local_104,param_1);
  FUN_0041afd0(param_1,local_104);
  return;
}


// ==== FUN_004018e7 @ 004018e7

undefined4 __cdecl FUN_004018e7(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00401733(s_Shared_Path_00420304,local_104);
  FUN_0041afe0(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Shared_Path_00420310,local_104);
    FUN_0041afe0(local_104,(uint *)&DAT_0042031c);
    FUN_0041afe0(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0041afd0(local_104,(uint *)s___shared__00420320);
      FUN_0041afe0(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0041afd0(local_104,(uint *)&DAT_0042032c);
        FUN_0041afe0(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0041afd0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0041afd0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0041afd0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0041afd0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00401a95 @ 00401a95

undefined4 __cdecl FUN_00401a95(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00401733(s_Help_Path_00420330,local_104);
  FUN_0041afe0(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Help_Path_0042033c,local_104);
    FUN_0041afe0(local_104,(uint *)&DAT_00420348);
    FUN_0041afe0(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0041afd0(local_104,(uint *)&DAT_0042034c);
      FUN_0041afe0(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0041afd0(local_104,(uint *)s___shared__00420350);
        FUN_0041afe0(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0041afd0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0041afd0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0041afd0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0041afd0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00401c43 @ 00401c43

undefined4 __cdecl FUN_00401c43(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_004202c8 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00423448 + DAT_004202c8 * 4) = param_1;
    DAT_004202c8 = DAT_004202c8 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00401c8f @ 00401c8f

void FUN_00401c8f(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_004202c8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00423448 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00423448 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00423448 + local_8 * 4) = 0;
  }
  DAT_004202c8 = 0;
  return;
}


// ==== FUN_00401d00 @ 00401d00

int __cdecl FUN_00401d00(void *param_1,LPCSTR param_2)

{
  int iVar1;
  int local_8;
  
  _memset(param_1,0,0x94);
  iVar1 = FUN_00402e0d((int)param_1 + 0x80,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  local_8 = FUN_00402edf(*(undefined4 *)((int)param_1 + 0x80),param_1,0x80);
  if (-1 < local_8) {
    *(LPCSTR *)((int)param_1 + 0x88) = param_2;
    if (*(short *)((int)param_1 + 4) == -0x50ee) {
      DAT_00420360 = *(int *)((int)param_1 + 0x50);
      DAT_00424548 = *(int *)((int)param_1 + 0x50) + DAT_0042454c;
      return 0;
    }
    if (*(short *)((int)param_1 + 4) == -0x50ef) {
      *(undefined4 *)((int)param_1 + 0x50) = 0x80;
      *(int *)((int)param_1 + 0x10) = (*(int *)((int)param_1 + 0x10) * 1000) / 0x46;
      return 0;
    }
    local_8 = -3;
  }
  FUN_00401e14(param_1);
  return local_8;
}


// ==== FUN_00401e14 @ 00401e14

void __cdecl FUN_00401e14(void *param_1)

{
  FreeResource(DAT_00424550);
  DAT_0042454c = 0;
  DAT_00424548 = 0;
  DAT_00420360 = 0;
  _memset(param_1,0,0x94);
  return;
}


// ==== FUN_00401e61 @ 00401e61

int __cdecl FUN_00401e61(int param_1,int *param_2)

{
  int local_24;
  uint local_20;
  int local_14;
  size_t local_10;
  int *local_c [2];
  
  local_14 = FUN_00402edf(*(undefined4 *)(param_1 + 0x80),&local_24,0x10);
  if (-1 < local_14) {
    if ((local_20 & 0xffff) == 0xf1fa) {
      local_10 = local_24 - 0x10;
      if ((0 < (int)local_10) && (local_14 = FUN_00402d86(local_c,local_10), -1 < local_14)) {
        local_14 = FUN_00402f6b(*(undefined4 *)(param_1 + 0x80),(int)local_c,local_10);
        if (-1 < local_14) {
          local_14 = FUN_00401f39(param_1,(int)&local_24,local_c[0],param_2);
        }
        FUN_00402dd1(local_c);
      }
    }
    else {
      local_14 = -4;
    }
  }
  return local_14;
}


// ==== FUN_00401f39 @ 00401f39

undefined4 __cdecl FUN_00401f39(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < *(short *)(param_2 + 6); local_8 = local_8 + 1) {
    iVar1 = *param_3;
    switch((short)param_3[1]) {
    case 4:
      FUN_004020ac((short *)((int)param_3 + 6),param_1,param_4);
      break;
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 0xe:
      break;
    case 7:
      FUN_004023bd((short *)((int)param_3 + 6),param_1,param_4);
      break;
    case 0xb:
      FUN_0040216e((short *)((int)param_3 + 6),param_1,param_4);
      break;
    case 0xc:
      FUN_00402290((short *)((int)param_3 + 6),param_1,param_4);
      break;
    case 0xd:
      FUN_004025b3((int)param_3 + 6,param_1,param_4);
      break;
    case 0xf:
      FUN_00402197((byte *)((int)param_3 + 6),param_1,param_4);
      break;
    case 0x10:
      FUN_0040266c((void *)((int)param_3 + 6),param_1,param_4);
    }
    param_3 = (int *)((int)param_3 + iVar1);
  }
  return 0;
}


// ==== FUN_004020ac @ 004020ac

void __cdecl FUN_004020ac(short *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004020d5(param_1,param_2,param_3,FUN_00402c98);
  return;
}


// ==== FUN_004020d5 @ 004020d5

void __cdecl FUN_004020d5(short *param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

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
    (*(code *)param_4)(param_3,local_14 + (uint)bVar1,local_10 + 2,local_c);
    local_10 = local_10 + 2 + local_c * 3;
    local_14 = local_14 + (uint)bVar1 + local_c;
  }
  return;
}


// ==== FUN_0040216e @ 0040216e

void __cdecl FUN_0040216e(short *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004020d5(param_1,param_2,param_3,FUN_00402d0f);
  return;
}


// ==== FUN_00402197 @ 00402197

void __cdecl FUN_00402197(byte *param_1,int param_2,int *param_3)

{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  uint local_20;
  byte *local_1c;
  int local_18;
  int local_14;
  byte local_10;
  
  uVar2 = *(ushort *)(param_2 + 8);
  local_20 = (uint)*(ushort *)(param_2 + 10);
  local_1c = param_1;
  local_18 = *(int *)(param_2 + 0x90);
  iVar3 = *(int *)(param_2 + 0x8c);
  while (local_20 = local_20 - 1, -1 < (int)local_20) {
    local_14 = *(int *)(param_2 + 0x8c);
    local_1c = local_1c + 1;
    local_10 = 0;
    while (local_14 = local_14 + (char)local_10, local_14 < (int)(iVar3 + (uint)uVar2)) {
      local_10 = *local_1c;
      pbVar1 = local_1c + 1;
      if ((char)local_10 < '\0') {
        local_10 = -local_10;
        FUN_00402a56(param_3,local_14,local_18,pbVar1,(int)(char)local_10);
        local_1c = pbVar1 + (char)local_10;
      }
      else {
        local_1c = local_1c + 2;
        FUN_00402ba3(param_3,local_14,local_18,*pbVar1,(int)(char)local_10);
      }
    }
    local_18 = local_18 + 1;
  }
  return;
}


// ==== FUN_00402290 @ 00402290

void __cdecl FUN_00402290(short *param_1,int param_2,int *param_3)

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
        FUN_00402ba3(param_3,local_1c,local_24,*pbVar1,(int)(char)bVar3);
      }
      else {
        FUN_00402a56(param_3,local_1c,local_24,pbVar1,(int)(char)bVar3);
        local_28 = pbVar1 + (char)bVar3;
      }
      local_1c = local_1c + (char)bVar3;
    }
    local_24 = local_24 + 1;
  }
  return;
}


// ==== FUN_004023bd @ 004023bd

void __cdecl FUN_004023bd(short *param_1,int param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  size_t sVar3;
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
      if (-1 < (short)local_1c) goto LAB_004024b4;
      if ((local_1c & 0x4000) == 0) break;
      local_2c = local_2c - (short)local_1c;
      local_18 = puVar4;
    }
    FUN_004029f7(param_3,(uint)(byte)local_1c,iVar2 + (uint)uVar1 + -1,(char)local_2c);
    for (local_1c = *puVar4; local_18 = local_18 + 2, puVar4 = local_18, local_1c != 0;
        local_1c = local_1c - 1) {
LAB_004024b4:
      while( true ) {
        local_18 = puVar4;
        local_28 = local_28 + (uint)(byte)*local_18;
        iVar5 = (int)(char)*(byte *)((int)local_18 + 1);
        puVar4 = local_18 + 1;
        sVar3 = iVar5 * 2;
        if ((int)sVar3 < 0) break;
        FUN_00402a56(param_3,local_28,local_2c,puVar4,sVar3);
        local_28 = local_28 + sVar3;
        local_18 = puVar4 + iVar5;
        local_1c = local_1c - 1;
        puVar4 = local_18;
        if (local_1c == 0) goto joined_r0x00402523;
      }
      FUN_00402c06(param_3,local_28,local_2c,*puVar4,iVar5 * -2 >> 1);
      local_28 = local_28 + iVar5 * -2;
    }
joined_r0x00402523:
    local_24 = local_24 + -1;
    local_2c = local_2c + 1;
    if (local_24 < 1) {
      return;
    }
  } while( true );
}


// ==== FUN_004025b3 @ 004025b3

void __cdecl FUN_004025b3(undefined4 param_1,int param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_18;
  
  uVar1 = *(ushort *)(param_2 + 10);
  uVar2 = *(ushort *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0x8c);
  iVar4 = *(int *)(param_2 + 0x90);
  for (local_18 = 0; local_18 < (int)(uint)uVar1; local_18 = local_18 + 1) {
    FUN_00402c06(param_3,iVar3,iVar4 + local_18,0,uVar2 / 2);
    if ((uVar2 & 1) != 0) {
      FUN_004029f7(param_3,iVar3 + (uint)uVar2 + -1,iVar4 + local_18,0);
    }
  }
  return;
}


// ==== FUN_0040266c @ 0040266c

void __cdecl FUN_0040266c(void *param_1,int param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_14;
  
  uVar1 = *(ushort *)(param_2 + 10);
  uVar2 = *(ushort *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0x8c);
  iVar4 = *(int *)(param_2 + 0x90);
  for (local_14 = 0; local_14 < (int)(uint)uVar1; local_14 = local_14 + 1) {
    FUN_00402a56(param_3,iVar3,iVar4 + local_14,param_1,(uint)uVar2);
    param_1 = (void *)((int)param_1 + (uint)uVar2);
  }
  return;
}


// ==== FUN_004026f4 @ 004026f4

int __cdecl FUN_004026f4(int param_1,int *param_2)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_c = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 6) <= local_c) {
      return local_8;
    }
    FUN_0040278f(*(int *)(param_1 + 0x10),param_2 + 0xc5);
    iVar1 = FUN_00401e61(param_1,param_2);
    if (iVar1 < 0) break;
    local_8 = FUN_004027bb();
    if (local_8 < 0) {
      return local_8;
    }
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_0040278f @ 0040278f

int __cdecl FUN_0040278f(int param_1,int *param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = *param_2;
  DVar2 = GetTickCount();
  return DVar2 + (uint)(iVar1 * param_1) / 1000;
}


// ==== FUN_004027bb @ 004027bb

undefined4 FUN_004027bb(void)

{
  return 0;
}


// ==== FUN_004027cd @ 004027cd

int __cdecl FUN_004027cd(int param_1,int *param_2)

{
  int iVar1;
  int local_c;
  
  if (*(int *)(param_1 + 0x54) == 0) {
    FUN_004028f4(param_1);
  }
  DAT_00420360 = *(int *)(param_1 + 0x50);
  DAT_00424548 = DAT_00420360 + DAT_0042454c;
  FUN_0040278f(*(int *)(param_1 + 0x10),param_2 + 0xc5);
  iVar1 = FUN_00401e61(param_1,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  do {
    DAT_00420360 = *(int *)(param_1 + 0x54);
    DAT_00424548 = DAT_00420360 + DAT_0042454c;
    for (local_c = 0; local_c < (int)(uint)*(ushort *)(param_1 + 6); local_c = local_c + 1) {
      iVar1 = FUN_004027bb();
      if (iVar1 < 0) {
        return 0;
      }
      iVar1 = FUN_00401e61(param_1,param_2);
      if (iVar1 < 0) {
        return iVar1;
      }
      FUN_0040278f(*(int *)(param_1 + 0x10),param_2 + 0xc5);
    }
  } while( true );
}


// ==== FUN_004028f4 @ 004028f4

int __cdecl FUN_004028f4(int param_1)

{
  int iVar1;
  int local_18 [5];
  
  DAT_00420360 = *(int *)(param_1 + 0x50);
  DAT_00424548 = DAT_00420360 + DAT_0042454c;
  iVar1 = FUN_00402edf(*(undefined4 *)(param_1 + 0x80),local_18,0x10);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x50) + local_18[0];
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00402960 @ 00402960

char * __cdecl FUN_00402960(int param_1)

{
  char *pcVar1;
  
  if (param_1 < 0) {
    if ((param_1 == -5) || (param_1 == -6)) {
      pcVar1 = s_File_IO_error_0042042c;
    }
    else if (0xffffffffU - param_1 < 10) {
      pcVar1 = (&PTR_s_Unspecified_error_00420368)[0xffffffffU - param_1];
    }
    else {
      pcVar1 = s_Unknown_error_0042043c;
    }
  }
  else {
    pcVar1 = s_Success_00420424;
  }
  return pcVar1;
}


// ==== FUN_004029cb @ 004029cb

undefined4 __cdecl FUN_004029cb(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


// ==== FUN_004029e1 @ 004029e1

undefined4 __cdecl FUN_004029e1(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== FUN_004029f7 @ 004029f7

void __cdecl FUN_004029f7(int *param_1,int param_2,int param_3,undefined1 param_4)

{
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < param_1[1])) && (param_3 < param_1[2])) {
    *(undefined1 *)(param_1[1] * param_3 + param_2 + *param_1) = param_4;
  }
  return;
}


// ==== FUN_00402a56 @ 00402a56

void __cdecl FUN_00402a56(int *param_1,int param_2,int param_3,void *param_4,size_t param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  iVar2 = FUN_00402ad6((int)param_1,&param_2,&param_3,(int *)&param_5);
  if (iVar2 != 0) {
    if (param_2 - iVar1 != 0) {
      param_4 = (void *)((int)param_4 + (param_2 - iVar1));
    }
    FID_conflict__memcpy((void *)(param_1[1] * param_3 + *param_1 + param_2),param_4,param_5);
  }
  return;
}


// ==== FUN_00402ad6 @ 00402ad6

undefined4 __cdecl FUN_00402ad6(int param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_00402ba3 @ 00402ba3

void __cdecl FUN_00402ba3(int *param_1,int param_2,int param_3,byte param_4,size_t param_5)

{
  int iVar1;
  
  iVar1 = FUN_00402ad6((int)param_1,&param_2,&param_3,(int *)&param_5);
  if (iVar1 != 0) {
    _memset((void *)(param_1[1] * param_3 + *param_1 + param_2),(uint)param_4,param_5);
  }
  return;
}


// ==== FUN_00402c06 @ 00402c06

void __cdecl FUN_00402c06(int *param_1,int param_2,int param_3,undefined2 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 *local_14;
  
  param_5 = param_5 << 1;
  iVar1 = FUN_00402ad6((int)param_1,&param_2,&param_3,(int *)&param_5);
  if (iVar1 != 0) {
    uVar2 = param_5 & 1;
    param_5 = (int)param_5 >> 1;
    local_14 = (undefined2 *)(param_1[1] * param_3 + *param_1 + param_2);
    while (param_5 = param_5 - 1, -1 < (int)param_5) {
      *local_14 = param_4;
      local_14 = local_14 + 1;
    }
    if (uVar2 != 0) {
      *(undefined1 *)local_14 = (undefined1)param_4;
    }
  }
  return;
}


// ==== FUN_00402c98 @ 00402c98

void __cdecl FUN_00402c98(int param_1,int param_2,undefined1 *param_3,int param_4)

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


// ==== FUN_00402d0f @ 00402d0f

void __cdecl FUN_00402d0f(int param_1,int param_2,undefined1 *param_3,int param_4)

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


// ==== FUN_00402d86 @ 00402d86

undefined4 __cdecl FUN_00402d86(undefined4 *param_1,size_t param_2)

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


// ==== FUN_00402dd1 @ 00402dd1

void __cdecl FUN_00402dd1(void *param_1)

{
  if (*(int *)((int)param_1 + 4) != 0) {
    _free(*(void **)((int)param_1 + 4));
    _memset(param_1,0,8);
  }
  return;
}


// ==== FUN_00402e0d @ 00402e0d

undefined4 __cdecl FUN_00402e0d(undefined4 param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  uint local_8;
  
  DAT_00424550 = FUN_00401078(DAT_004293b0,param_2,&DAT_0042044c,&DAT_00420364);
  if (DAT_00424550 == (HGLOBAL)0x0) {
    uVar1 = 0xfffffffb;
  }
  else {
    DAT_0042454c = LockResource(DAT_00424550);
    if (DAT_0042454c == (LPVOID)0x0) {
      uVar1 = 0xfffffffb;
    }
    else {
      DAT_00420360 = 0;
      for (local_8 = 0; local_8 < DAT_00420364; local_8 = local_8 + 1) {
      }
      uVar1 = 0;
      DAT_00424548 = DAT_0042454c;
    }
  }
  return uVar1;
}


// ==== FUN_00402edf @ 00402edf

undefined4 __cdecl FUN_00402edf(undefined4 param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  
  if (DAT_00424548 == (void *)0x0) {
    uVar1 = 0xfffffffa;
  }
  else if (DAT_0042454c == 0) {
    uVar1 = 0xfffffffa;
  }
  else if (DAT_00420364 < (int)DAT_00424548 + (param_3 - DAT_0042454c)) {
    uVar1 = 0xfffffffa;
  }
  else {
    FID_conflict__memcpy(param_2,DAT_00424548,param_3);
    DAT_00424548 = (void *)((int)DAT_00424548 + param_3);
    DAT_00420360 = DAT_00420360 + param_3;
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00402f6b @ 00402f6b

int __cdecl FUN_00402f6b(undefined4 param_1,int param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = FUN_00402edf(param_1,*(void **)(param_2 + 4),param_3);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_00402fac @ 00402fac

void __cdecl FUN_00402fac(LPCSTR param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  tagMSG local_3dc;
  uint local_3bc;
  int local_3b8 [199];
  undefined1 local_9c [6];
  ushort local_96;
  int local_8;
  
  local_3b8[0] = param_2;
  local_3b8[1] = 0x21c;
  local_3b8[2] = 400;
  local_3bc = 0;
  iVar1 = FUN_00401d00(local_9c,param_1);
  if (-1 < iVar1) goto LAB_00403020;
  local_3bc = 9999;
  DAT_004292fc = FUN_0040f0ac(s_TITLEBMP_00420454);
  do {
    DAT_00420ab0 = 1;
    DAT_00420ab4 = 0;
    do {
      if (local_3bc == 0x32) {
        FUN_0040f923(0x16);
      }
      local_3bc = local_3bc + 1;
      if (local_96 == local_3bc) {
        GlobalFree(DAT_004292fc);
        DAT_004292fc = FUN_0040f0ac(s_TITLEBMP_00420460);
      }
      do {
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
        Sleep(0x32);
        while( true ) {
          while( true ) {
            if (DAT_0042038c != 0) goto LAB_0040319e;
LAB_00403020:
            BVar2 = PeekMessageA(&local_3dc,(HWND)0x0,0,0,1);
            if (BVar2 == 0) break;
            if (local_3dc.message == 0x12) goto LAB_0040319e;
            if ((DAT_00429778 == (HWND)0x0) ||
               (iVar1 = TranslateAcceleratorA(DAT_00429778,DAT_00428bd4,&local_3dc), iVar1 == 0)) {
              TranslateMessage(&local_3dc);
              DispatchMessageA(&local_3dc);
            }
          }
          if ((DAT_00428be4 != 0) || (local_3bc == 0)) break;
          WaitMessage();
        }
      } while ((int)(uint)local_96 <= (int)local_3bc);
      local_8 = FUN_00401e61((int)local_9c,local_3b8);
      if (local_8 < 0) {
LAB_0040319e:
        FUN_00401e14(local_9c);
        return;
      }
    } while (local_3bc != 0);
  } while( true );
}


// ==== FUN_004031c0 @ 004031c0

int __cdecl FUN_004031c0(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_004031df @ 004031df

void FUN_004031df(void)

{
  _memset(&DAT_00427628,0,0x370);
  _memset(&DAT_00424558,0,0x30d0);
  FID_conflict__memcpy(&DAT_00424558,s_MD_PACK_004204b8,8);
  DAT_004251f8 = 0;
  DAT_004251f9 = 0;
  DAT_004251fa = 0;
  DAT_00424562 = 0xc;
  _memset(&DAT_004251cc,0,0x28);
  FID_conflict__memcpy(&DAT_004251bc,s_JEWELCH_004205c0,0xb);
  return;
}


// ==== FUN_00403278 @ 00403278

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00403278(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_004031df();
  hFile = _lopen(s_MSPuzzle_dat_004204c0,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00424558,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_004251bc,s_JEWELCH_004205c0,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00424558,s_MD_PACK_004204b8,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00427650 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_00425230 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00427628 + local_10 * 0x2c,&DAT_00425208 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00427650 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00427650 + local_10 * 0x2c) = 0;
        }
      }
      DAT_00420f74 = (uint)(DAT_004251f8 == '\0');
      DAT_00420f70 = (uint)(DAT_004251f9 == '\0');
      DAT_0042048c = (uint)(DAT_004251fa == '\0');
      FID_conflict__memcpy(&DAT_00420490,&DAT_004251cc,0x28);
      _DAT_00420478 = (uint)DAT_004251f4;
      if ((_DAT_00420478 == 0) || (99 < _DAT_00420478)) {
        _DAT_00420478 = 1;
      }
      _DAT_0042047c = (uint)DAT_004251f5;
      if ((_DAT_0042047c == 0) || (4 < _DAT_0042047c)) {
        _DAT_0042047c = 2;
      }
      DAT_00420480 = (uint)(DAT_004251f6 == '\0');
      DAT_00420484 = (uint)(DAT_004251f7 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_004031df();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00403508 @ 00403508

undefined4 __cdecl FUN_00403508(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00427650 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_004035a5 @ 004035a5

int __cdecl FUN_004035a5(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00427650 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00427628 + (local_1c + 1) * 0x2c,&DAT_00427628 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00427628 + local_1c * 0x2c,&DAT_00420490,0x28);
    *(int *)(&DAT_00427650 + local_1c * 0x2c) = param_1;
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


// ==== FUN_004036e9 @ 004036e9

void FUN_004036e9(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00425208,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00425208 + local_c * 0x30,&DAT_00427628 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_00425230 + local_c * 0x30) =
         *(undefined4 *)(&DAT_00427650 + local_c * 0x2c);
  }
  DAT_004251f8 = DAT_00420f74 == 0;
  DAT_004251f9 = DAT_00420f70 == 0;
  DAT_004251fa = DAT_0042048c == 0;
  DAT_004251f4 = DAT_00420478;
  DAT_004251f5 = DAT_0042047c;
  DAT_004251f6 = DAT_00420480 == 0;
  DAT_004251f7 = DAT_00420484 == 0;
  _memset(&DAT_004251cc,0,0x28);
  FID_conflict__memcpy(&DAT_004251cc,&DAT_00420490,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_004204c0,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_004204c0,0);
  }
  _lwrite(local_8,&DAT_00424558,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_004038c0 @ 004038c0

void FUN_004038c0(void)

{
  FUN_004038da();
  FUN_00403ae9();
  return;
}


// ==== FUN_004038da @ 004038da

/* WARNING: Removing unreachable block (ram,0x004039a5) */
/* WARNING: Removing unreachable block (ram,0x004039b2) */
/* WARNING: Removing unreachable block (ram,0x00403a12) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004038da(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_004293fc = 0;
  DAT_004293dc = 1;
  DAT_004293d8 = 0;
  DAT_004293d4 = 0;
  DAT_004293c0 = 0;
  DAT_004293bc = 0;
  DAT_004293b8 = 0;
  DAT_004293f8 = 0;
  _DAT_00429400 = 0;
  _DAT_00429404 = 0;
  _DAT_004293e0 = 0;
  _DAT_004293e4 = 0;
  DAT_004293f4 = 0;
  DAT_004293f0 = 0;
  DAT_004293ec = 0;
  _DAT_004293e8 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403ae9 @ 00403ae9

void FUN_00403ae9(void)

{
  _atexit(FUN_00403b06);
  return;
}


// ==== FUN_00403b06 @ 00403b06

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403b06(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00403c3a;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 1;
  if ((DAT_004293b8 != (void *)0x0) && (DAT_004293bc == 0)) {
    FUN_0041b6d0(DAT_004293b8);
  }
  DAT_004293b8 = (void *)0x0;
  DAT_004293c0 = 0;
  DAT_004293d4 = 0;
  DAT_004293d8 = 0;
  DAT_004293dc = 1;
  if (DAT_004293f8 != (void *)0x0) {
    FUN_0041b6d0(DAT_004293f8);
  }
  DAT_004293f8 = (void *)0x0;
  _DAT_00429400 = 0;
  _DAT_00429404 = 0;
  _DAT_004293e0 = 0;
  _DAT_004293e4 = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_00403c1e();
  local_8 = 0xffffffff;
  FUN_00403c2a();
  thunk_FUN_00403c44();
  return;
}


// ==== FUN_00403c1e @ 00403c1e

void FUN_00403c1e(void)

{
  FUN_0040eac0(&DAT_004293f8);
  return;
}


// ==== FUN_00403c2a @ 00403c2a

void FUN_00403c2a(void)

{
  FUN_0040eb90(&DAT_004293b8);
  return;
}


// ==== FUN_00403c44 @ 00403c44

void FUN_00403c44(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403c52 @ 00403c52

void FUN_00403c52(void)

{
  FUN_00403c6c();
  FUN_00403e7b();
  return;
}


// ==== FUN_00403c6c @ 00403c6c

/* WARNING: Removing unreachable block (ram,0x00403d37) */
/* WARNING: Removing unreachable block (ram,0x00403d44) */
/* WARNING: Removing unreachable block (ram,0x00403da4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403c6c(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0042934c = 0;
  DAT_0042932c = 1;
  DAT_00429328 = 0;
  DAT_00429324 = 0;
  DAT_00429310 = 0;
  DAT_0042930c = 0;
  DAT_00429308 = 0;
  DAT_00429348 = 0;
  _DAT_00429350 = 0;
  _DAT_00429354 = 0;
  _DAT_00429330 = 0;
  _DAT_00429334 = 0;
  DAT_00429344 = 0;
  DAT_00429340 = 0;
  DAT_0042933c = 0;
  _DAT_00429338 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403e7b @ 00403e7b

void FUN_00403e7b(void)

{
  _atexit(FUN_00403e98);
  return;
}


// ==== FUN_00403e98 @ 00403e98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403e98(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00403fcc;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 1;
  if ((DAT_00429308 != (void *)0x0) && (DAT_0042930c == 0)) {
    FUN_0041b6d0(DAT_00429308);
  }
  DAT_00429308 = (void *)0x0;
  DAT_00429310 = 0;
  DAT_00429324 = 0;
  DAT_00429328 = 0;
  DAT_0042932c = 1;
  if (DAT_00429348 != (void *)0x0) {
    FUN_0041b6d0(DAT_00429348);
  }
  DAT_00429348 = (void *)0x0;
  _DAT_00429350 = 0;
  _DAT_00429354 = 0;
  _DAT_00429330 = 0;
  _DAT_00429334 = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_00403fb0();
  local_8 = 0xffffffff;
  FUN_00403fbc();
  thunk_FUN_00403fd6();
  return;
}


// ==== FUN_00403fb0 @ 00403fb0

void FUN_00403fb0(void)

{
  FUN_0040eac0(&DAT_00429348);
  return;
}


// ==== FUN_00403fbc @ 00403fbc

void FUN_00403fbc(void)

{
  FUN_0040eb90(&DAT_00429308);
  return;
}


// ==== FUN_00403fd6 @ 00403fd6

void FUN_00403fd6(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403fe4 @ 00403fe4

void __cdecl FUN_00403fe4(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00420b20 = 2;
  }
  DAT_004291c4 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00404027 @ 00404027

void __cdecl FUN_00404027(HWND param_1)

{
  if (DAT_004291c4 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_004291c4);
  }
  return;
}


// ==== FUN_00404058 @ 00404058

void __cdecl FUN_00404058(uint *param_1)

{
  FUN_0041afd0((uint *)&DAT_00420b28,param_1);
  return;
}


// ==== FUN_00404079 @ 00404079

void __cdecl FUN_00404079(HWND param_1)

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


// ==== FUN_004041b1 @ 004041b1

void __cdecl FUN_004041b1(int param_1)

{
  if (((0 < param_1) && (param_1 < 4)) && (*(int *)(&DAT_00429378 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00429378 + param_1 * 4) = 1;
    Sleep(100);
    DAT_00420a9c = 1;
    if (param_1 == 1) {
      FUN_00404058((uint *)s_QUICKHELPBMP_00420c8c);
      FUN_0040141d(DAT_004293b0,s_QHBRUSHDIALOG_00420c9c,DAT_00429778,FUN_004054aa);
    }
    else if (param_1 == 2) {
      FUN_00404058((uint *)s_QUICKHELPBMP_00420c6c);
      FUN_0040141d(DAT_004293b0,s_QHCONGRATULAT_00420c7c,DAT_00429778,FUN_00405720);
    }
    else if (param_1 == 3) {
      FUN_00404058((uint *)s_QUICKHELPBMP_00420cac);
      FUN_0040141d(DAT_004293b0,s_QHCANDLEDIALOG_00420cbc,DAT_00429778,FUN_004054aa);
    }
    DAT_00420a9c = 0;
  }
  return;
}


// ==== FUN_004042e0 @ 004042e0

INT_PTR FUN_004042e0(void)

{
  INT_PTR IVar1;
  
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_QUICKHELPBMP_00420ccc);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_004293b0,s_EXITGAME_00420cdc,DAT_00429778,FUN_004048e1);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_00404358 @ 00404358

INT_PTR FUN_00404358(void)

{
  INT_PTR IVar1;
  
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_QUICKHELPBMP_00420ce8);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_004293b0,s_NEWGAME_00420cf8,DAT_00429778,FUN_004048e1);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_004043d0 @ 004043d0

INT_PTR __cdecl FUN_004043d0(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040141d(DAT_004293b0,s_RESETSCORE_00420d00,param_1,FUN_00406743);
  return IVar1;
}


// ==== FUN_00404405 @ 00404405

void FUN_00404405(void)

{
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_ABOUTBMP_00420d0c);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_ABOUT_00420d18,DAT_00429778,FUN_00404a82);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404474 @ 00404474

void __cdecl FUN_00404474(HWND param_1)

{
  FUN_0040141d(DAT_004293b0,s_CREDITS_00420d20,param_1,FUN_00404d72);
  return;
}


// ==== FUN_004044a0 @ 004044a0

void __cdecl FUN_004044a0(HWND param_1)

{
  FUN_0040141d(DAT_004293b0,s_SYSTEMINFODIALOG_00420d28,param_1,FUN_00404f0c);
  return;
}


// ==== FUN_004044cc @ 004044cc

void FUN_004044cc(void)

{
  DAT_00420a9c = 1;
  FUN_00404058((uint *)s_QUICKHELPBMP_00420d3c);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_QUICKHELPDIALOG_00420d4c,DAT_00429778,FUN_004054aa);
  DAT_00420a9c = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040453b @ 0040453b

void FUN_0040453b(void)

{
  FUN_00404058((uint *)s_QUICKHELPBMP_00420d5c);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_QUICKHELPDIALOG_00420d6c,DAT_00429778,FUN_004054aa);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404596 @ 00404596

void FUN_00404596(void)

{
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_CUPBMP_00420d7c);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_YOURNAME_00420d84,DAT_00429778,FUN_00405951);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404605 @ 00404605

void FUN_00404605(void)

{
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_CUPBMP_00420d90);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_BALLSTOP_00420d98,DAT_00429778,FUN_004063bb);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404674 @ 00404674

void FUN_00404674(void)

{
  DAT_00420a98 = 1;
  FUN_00404058((uint *)s_OPTIONSBMP_00420da4);
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  FUN_0040141d(DAT_004293b0,s_OPTIONS_00420db0,DAT_00429778,FUN_00405c9a);
  DAT_00420a98 = 0;
  InvalidateRect(DAT_00429398,(RECT *)0x0,0);
  return;
}


// ==== FUN_004046e3 @ 004046e3

void __cdecl FUN_004046e3(HWND param_1)

{
  HDC pHVar1;
  int local_20;
  int local_1c;
  tagRECT local_18;
  HBITMAP local_8;
  
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  GetClientRect(param_1,&local_18);
  pHVar1 = GetDC((HWND)0x0);
  local_8 = FUN_0040ee90(pHVar1,&DAT_00420b28);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040edb1(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0042a62c,0);
  RealizePalette(pHVar1);
  FUN_0040edfa(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_004047e2 @ 004047e2

void __cdecl FUN_004047e2(HWND param_1)

{
  HDC pHVar1;
  HBITMAP ho;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  GetClientRect(param_1,&local_14);
  pHVar1 = GetDC((HWND)0x0);
  ho = FUN_0040ee90(pHVar1,s_QUICKHELPBMP_00420db8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040edb1(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0042a62c,0);
  RealizePalette(pHVar1);
  FUN_0040edfa(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_004048e1 @ 004048e1

UINT FUN_004048e1(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_004293ac = param_1;
      DAT_004293a4 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004046e3(DAT_004293a4);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_004293ac == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004293ac);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_004293ac,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_004293ac,(RECT *)0x0,0);
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
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


// ==== FUN_00404a82 @ 00404a82

UINT FUN_00404a82(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_004294ac = param_1;
      DAT_004294a8 = GetDlgItem(param_1,100);
      FUN_004015b0(DAT_004293b0,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00401733(&DAT_00420dc8,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00401733(s_Product_ID_00420dcc,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004046e3(DAT_004294a8);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_004294ac) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_004294ac);
      SelectPalette(local_10c,DAT_0042a62c,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_004294ac,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_004294ac,(RECT *)0x0,0);
      InvalidateRect(DAT_00429778,(RECT *)0x0,0);
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
      FUN_004044a0(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00404474(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00404d72 @ 00404d72

UINT FUN_00404d72(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_00429388 = param_1;
      DAT_0042936c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004046e3(DAT_0042936c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00429388) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00429388);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00429388,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00429388,(RECT *)0x0,0);
        InvalidateRect(DAT_004294ac,(RECT *)0x0,0);
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
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


// ==== FUN_00404f0c @ 00404f0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00404f0c(HWND param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  _MEMORYSTATUS local_4dc;
  DWORD local_4bc;
  DWORD local_4b8;
  undefined1 local_4b4;
  undefined1 local_4b3;
  undefined1 local_4b2;
  undefined1 local_4b1;
  HDC local_4a8;
  DWORD local_4a4;
  uint local_4a0;
  _OSVERSIONINFOA local_49c;
  DWORD local_408;
  undefined1 local_404 [1024];
  
  if (param_2 == 0x110) {
    FUN_00404079(param_1);
    _DAT_004285dc = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420dd8,local_49c.dwMajorVersion,-1);
    FUN_0041afd0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420ddc);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420de0,local_49c.dwMinorVersion,-1);
    FUN_0041afe0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420de4);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420de8,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0041afe0((uint *)local_404,puVar1);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420dec);
      FUN_0041afe0((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420df0,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0041afd0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420df4);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0041afd0((uint *)local_404,(uint *)&DAT_00420df8);
    FUN_0041afe0((uint *)local_404,(uint *)&local_4b4);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420dfc);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_408 * local_4b8 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e00,local_4a0,-1);
    FUN_0041afe0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420e04);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_00420e28,s_display_drv_00420e1c,s_Unknown_00420e14,local_404,0x80,
               s_system_ini_00420e08);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e3c,local_4a0,-1);
    FUN_0041afd0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420e40);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e44,local_4a0,-1);
    FUN_0041afe0((uint *)local_404,puVar1);
    FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420e48);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e4c,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0041afe0((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e50,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0041afe0((uint *)local_404,puVar1);
      FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420e54);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e5c,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0041afe0((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_0040ec60((uint *)&DAT_00420e58,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0041afe0((uint *)local_404,puVar1);
      }
      FUN_0041afe0((uint *)local_404,(uint *)&DAT_00420e60);
    }
    SetDlgItemTextA(param_1,0xb6,local_404);
    ReleaseDC((HWND)0x0,local_4a8);
    uVar3 = 1;
  }
  else if (((param_2 == 0x111) && (param_3 != 0)) && (param_3 < 3)) {
    EndDialog(param_1,0);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_004054aa @ 004054aa

UINT FUN_004054aa(HWND param_1,uint param_2,HWND param_3)

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
        FUN_004046e3(DAT_004285d0);
      }
      return 0;
    }
    FUN_00404079(param_1);
    DAT_00429370 = param_1;
    DAT_004285d0 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00420480 == 0);
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
      DAT_00420480 = (uint)(LVar2 == 0);
      FUN_004036e9();
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
      DAT_00420480 = (uint)(LVar2 == 0);
      FUN_004036e9();
      EndDialog(param_1,0);
      PostMessageA(DAT_00429778,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00429370 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00429370);
  SelectPalette(hdc,DAT_0042a62c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00429370,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00429370,(RECT *)0x0,0);
    InvalidateRect(DAT_00429778,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00405720 @ 00405720

UINT FUN_00405720(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00404079(param_1);
      DAT_004285d4 = param_1;
      DAT_00429728 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_00420480 == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004046e3(DAT_00429728);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_004285d4 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004285d4);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_004285d4,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_004285d4,(RECT *)0x0,0);
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
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
        DAT_00420480 = (uint)(LVar2 == 0);
        FUN_004036e9();
        EndDialog(param_1,0);
        PostMessageA(DAT_00429778,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00405951 @ 00405951

UINT FUN_00405951(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  HWND pHVar1;
  undefined *_Src;
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
        FUN_004046e3(DAT_00428be0);
      }
      return 0;
    }
    FUN_00404079(param_1);
    DAT_00429390 = param_1;
    DAT_00428be0 = GetDlgItem(param_1,100);
    if (DAT_00420b20 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00420490);
    _Size = 0x10;
    _Src = FUN_0040ec60((uint *)&DAT_00420e64,DAT_00420abc,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_00429390 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_00429390);
    SelectPalette(hdc,DAT_0042a62c,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_00429390,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_00429390,(RECT *)0x0,0);
      InvalidateRect(DAT_00429778,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00420490,DAT_00420b20 * 0x11);
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


// ==== FUN_00405c9a @ 00405c9a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_00405c9a(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_00429778,s_jewelch_hlp_00420798,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_004046e3(DAT_0042935c);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00405e44:
      hdc = GetDC(DAT_00428bcc);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_00428bcc,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00428bcc,(RECT *)0x0,0);
      InvalidateRect(DAT_00429778,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_00428bcc = param_1;
      DAT_0042935c = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00420f70;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00420f74;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0042048c;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x62,_DAT_0042047c + 0x5e);
      if (DAT_00420b20 == 1) {
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
      LVar8 = 0;
      WVar7 = 2;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      pHVar9 = (HIMC)0x0;
      pHVar1 = GetDlgItem(param_1,0xf);
      DAT_004293a0 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_00420490);
      pCVar2 = FUN_0040ec60((uint *)&DAT_00420e68,_DAT_00420478,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x10063);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_00420f70 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_00420f74 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_0042048c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042047c = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042047c = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042047c = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_0042047c = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_00420490,DAT_00420b20 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 100; local_28 = local_28 + 1) {
          pcVar3 = FUN_0040ec60((uint *)&DAT_00420e78,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00406257:
            _DAT_00420478 = local_28;
            break;
          }
          pcVar3 = FUN_0040ec60((uint *)&DAT_00420e7c,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00406257;
        }
      case 2:
        DAT_00428bcc = (HWND)0x0;
        pHVar9 = DAT_004293a0;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = _DAT_00420478;
          for (local_28 = 1; local_28 < 100; local_28 = local_28 + 1) {
            pcVar3 = FUN_0040ec60((uint *)&DAT_00420e6c,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_00405f97:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_0040ec60((uint *)&DAT_00420e70,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_00405f97;
          }
          pCVar2 = FUN_0040ec60((uint *)&DAT_00420e74,local_1c,-1);
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
        WinHelpA(DAT_00429778,s_jewelch_hlp_00420798,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_00428bcc == param_3) {
      return 0;
    }
    goto LAB_00405e44;
  }
  return 0;
}


// ==== FUN_004063bb @ 004063bb

UINT FUN_004063bb(HWND param_1,uint param_2,HWND param_3)

{
  HWND pHVar1;
  uint uVar2;
  LPCSTR pCVar3;
  HDC hdc;
  UINT UVar4;
  INT_PTR IVar5;
  int iVar6;
  int local_14;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_00429364 = param_1;
      DAT_0042938c = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00420c28) && (DAT_00420c28 < 10)) {
        SetDlgItemTextA(param_1,DAT_00420c28 + 0x33,&DAT_00420e80);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_0040ec60((uint *)&DAT_00420e84,*(int *)(&DAT_00427650 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00427628 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004046e3(DAT_0042938c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00429364 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00429364);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00429364,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00429364,(RECT *)0x0,0);
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_004043d0(DAT_00429364), IVar5 == 1)) {
        if ((-1 < DAT_00420c28) && (DAT_00420c28 < 10)) {
          SetDlgItemTextA(param_1,DAT_00420c28 + 0x33,&DAT_00420e88);
        }
        DAT_00420c28 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00427650 + local_14 * 0x2c) = 0;
          _memset(&DAT_00427628 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_0040ec60((uint *)&DAT_00420e8c,*(int *)(&DAT_00427650 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00427628 + local_14 * 0x2c);
        }
        FUN_004036e9();
      }
    }
  }
  return 0;
}


// ==== FUN_00406743 @ 00406743

UINT FUN_00406743(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00404079(param_1);
      DAT_00429724 = param_1;
      DAT_00429358 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004047e2(DAT_00429358);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00429724 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00429724);
      SelectPalette(hdc,DAT_0042a62c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00429724,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00429364,(RECT *)0x0,0);
        InvalidateRect(DAT_00429724,(RECT *)0x0,0);
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
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


// ==== FUN_004068f4 @ 004068f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004068f4(void)

{
  _DAT_00428bdc = GetTickCount();
  return;
}


// ==== FUN_0040690f @ 0040690f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0040690f(int param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  iVar1 = ((iVar1 + _DAT_00428bdc) % 0x7fff) * param_1;
  return (int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf;
}


// ==== FUN_0040694b @ 0040694b

void FUN_0040694b(void)

{
  if (((DAT_00420aa0 == 0) && (DAT_00420aa8 == 0)) && (DAT_00420aac == 0)) {
    SetMenu(DAT_00429778,DAT_004285d8);
    DrawMenuBar(DAT_00429778);
  }
  else {
    SetMenu(DAT_00429778,DAT_0042972c);
    DrawMenuBar(DAT_00429778);
  }
  return;
}


// ==== FUN_004069c3 @ 004069c3

void FUN_004069c3(void)

{
  int iVar1;
  uint uVar2;
  int local_2c;
  char *local_28;
  
  if (DAT_00428bd8 != (int *)0x0) {
    uVar2 = ((uint)DAT_0042a63e * DAT_0042a634 + 0x1f & 0xffffffe0) >> 3;
    if (DAT_00428bd8[4] == 3) {
      iVar1 = *DAT_00428bd8 + 0xc;
    }
    else {
      if ((DAT_00428bd8[8] == 0) && (*(ushort *)((int)DAT_00428bd8 + 0xe) < 9)) {
        local_2c = 1 << (*(byte *)((int)DAT_00428bd8 + 0xe) & 0x1f);
      }
      else {
        local_2c = DAT_00428bd8[8];
      }
      iVar1 = local_2c * 4 + *DAT_00428bd8;
    }
    local_28 = (char *)((int)DAT_00428bd8 + iVar1);
    FUN_00414ea0((char *)(DAT_0042a618 + (DAT_0042a638 - DAT_00428bd8[2]) * uVar2),local_28,
                 DAT_00428bd8[1],DAT_00428bd8[2],uVar2,
                 ((uint)*(ushort *)((int)DAT_00428bd8 + 0xe) * DAT_00428bd8[1] + 0x1f & 0xffffffe0)
                 >> 3,0);
  }
  return;
}


// ==== FUN_00406b0c @ 00406b0c

void __cdecl FUN_00406b0c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_2c;
  char *local_28;
  
  if (param_1 != (int *)0x0) {
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
    local_28 = (char *)((int)param_1 + iVar1);
    uVar2 = ((uint)DAT_0042a63e * DAT_0042a634 + 0x1f & 0xffffffe0) >> 3;
    FUN_00414ea0((char *)(DAT_0042a618 + (DAT_0042a638 - (param_3 + param_1[2])) * uVar2 + param_2),
                 local_28,param_1[1],param_1[2],uVar2,
                 ((uint)*(ushort *)((int)param_1 + 0xe) * param_1[1] + 0x1f & 0xffffffe0) >> 3,0);
  }
  return;
}


// ==== FUN_00406c42 @ 00406c42

void FUN_00406c42(void)

{
  int local_c;
  int local_8;
  
  FUN_004069c3();
  FUN_00406b0c(*(int **)(&DAT_00427998 + (DAT_00420474 / 10) * 4),DAT_00420c38 + 0xf,DAT_00420c3c);
  FUN_00406b0c(*(int **)(&DAT_00427998 + (DAT_00420474 % 10) * 4),DAT_00420c38 + 0x21,DAT_00420c3c);
  local_8 = DAT_00420abc;
  for (local_c = 4; -1 < local_c; local_c = local_c + -1) {
    FUN_00406b0c(*(int **)(&DAT_00427998 + (local_8 % 10) * 4),DAT_00420c48 + local_c * 0x11 + 3,
                 DAT_00420c4c);
    local_8 = local_8 / 10;
  }
  InvalidateRect(DAT_00429778,(RECT *)&DAT_00420c38,0);
  InvalidateRect(DAT_00429778,(RECT *)&DAT_00420c48,0);
  return;
}


// ==== FUN_00406d4e @ 00406d4e

void FUN_00406d4e(void)

{
  return;
}


// ==== FUN_00406d5e @ 00406d5e

void FUN_00406d5e(void)

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
  
  hdc = GetDC(DAT_00429398);
  SelectPalette(hdc,DAT_0042a62c,0);
  RealizePalette(hdc);
  if (DAT_0042ab9c != 0) {
    bVar7 = false;
    if ((DAT_0042abb4 == 0) && (DAT_0042abb8 == 0)) {
      for (local_10 = 0; local_10 < DAT_0042ab9c; local_10 = local_10 + 1) {
        iVar1 = *(int *)(&DAT_0042aa68 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_0042aa64 + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
        iVar6 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_0042abc0);
        BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0042ab9c = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_0042ab9c; local_10 = local_10 + 1) {
        if ((DAT_0042abb4 <= *(int *)(&DAT_0042aa5c + local_10 * 0x10)) &&
           (DAT_0042abb8 <= *(int *)(&DAT_0042aa60 + local_10 * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_10 = 0; local_10 < DAT_0042ab9c; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_0042aa60 + local_10 * 0x10) - DAT_0042abb8;
          x = *(int *)(&DAT_0042aa5c + local_10 * 0x10) - DAT_0042abb4;
          iVar1 = *(int *)(&DAT_0042aa68 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_0042aa64 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_0042abc0);
          BitBlt(hdc,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_0042ab9c; local_10 = local_10 + 1) {
          iVar1 = *(int *)(&DAT_0042aa68 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_0042aa64 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_0042aa60 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0042aa5c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_0042abc0);
          BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0042ab9c = 0;
    }
  }
  ReleaseDC(DAT_00429398,hdc);
  return;
}


// ==== FUN_0040718f @ 0040718f

undefined1 __cdecl FUN_0040718f(byte param_1,byte param_2,int param_3)

{
  undefined1 uVar1;
  
  switch(*(undefined2 *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96)) {
  case 1:
    uVar1 = 0;
    break;
  case 2:
    if (param_3 != 0) {
      FUN_0040f923(0xb);
    }
    uVar1 = 0x19;
    break;
  case 3:
    if (param_3 != 0) {
      FUN_0040f923(0xb);
    }
    uVar1 = 0x14;
    break;
  case 4:
    if (param_3 != 0) {
      FUN_0040f923(0xb);
    }
    uVar1 = 0x1e;
    break;
  case 5:
    if (param_3 != 0) {
      FUN_0040f923(0xc);
    }
    uVar1 = 10;
    break;
  case 6:
    if (param_3 != 0) {
      FUN_0040f923(0xf);
    }
    uVar1 = 2;
    break;
  case 7:
    if (param_3 != 0) {
      FUN_0040f923(0xf);
    }
    uVar1 = 1;
    break;
  case 8:
    if (param_3 != 0) {
      FUN_0040f923(0xd);
    }
    uVar1 = 5;
    break;
  case 9:
    FUN_0040f923(0x10);
    uVar1 = 0;
    break;
  case 10:
    FUN_0040f923(0x11);
    uVar1 = 0;
    break;
  case 0xb:
    if (param_3 != 0) {
      FUN_0040f923(0xe);
    }
    uVar1 = 3;
    break;
  case 0xc:
    FUN_0040f923(0x12);
    uVar1 = 0;
    break;
  default:
    uVar1 = (&DAT_004285f2)[(uint)param_2 * 10 + (uint)param_1 * 0x96];
  }
  return uVar1;
}


// ==== FUN_00407347 @ 00407347

void __cdecl FUN_00407347(int param_1,int param_2)

{
  ushort uVar1;
  
  (&DAT_004285f0)[param_2 * 10 + param_1 * 0x96] = 0;
  uVar1 = *(ushort *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e);
  if ((uVar1 & 3) == 0) {
    (&DAT_004285f0)[param_2 * 10 + param_1 * 0x96] =
         (char)(1 << (((byte)(*(ushort *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e) >> 2) & 7) -
                      1 & 0x1f));
  }
  else if (((uVar1 & 3) != 0) && ((uVar1 & 3) < 4)) {
    (&DAT_004285f0)[param_2 * 10 + param_1 * 0x96] =
         (byte)(1 << (((byte)(*(ushort *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e) >> 2) & 7) -
                      1 & 0x1f)) |
         (byte)(1 << (((byte)((ushort)*(undefined2 *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e)
                             >> 0xb) & 7) - 1 & 0x1f)) |
         (byte)(1 << (((byte)(*(ushort *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e) >> 5) & 7) -
                      1 & 0x1f)) |
         (byte)(1 << (((byte)((ushort)*(undefined2 *)(&DAT_004291d0 + param_2 * 2 + param_1 * 0x1e)
                             >> 8) & 7) - 1 & 0x1f));
  }
  return;
}


// ==== FUN_004074d4 @ 004074d4

bool __cdecl FUN_004074d4(LPCSTR param_1,uint param_2,LPVOID param_3,LONG param_4)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0x20);
  if (hFile != -1) {
    _llseek(hFile,param_4,0);
    _lread(hFile,param_3,param_2 & 0xffff);
    _lclose(hFile);
  }
  return hFile != -1;
}


// ==== FUN_0040753d @ 0040753d

bool __cdecl FUN_0040753d(LPCSTR param_1,UINT param_2,LPCCH param_3,LONG param_4)

{
  UINT UVar1;
  HFILE local_8;
  
  local_8 = _lopen(param_1,0x11);
  if ((local_8 == -1) && (local_8 = _lcreat(param_1,0), local_8 == -1)) {
    return false;
  }
  _llseek(local_8,param_4,0);
  UVar1 = _lwrite(local_8,param_3,param_2);
  if (UVar1 == param_2) {
    _lclose(local_8);
  }
  else {
    _lclose(local_8);
  }
  return UVar1 == param_2;
}


// ==== FUN_004075d4 @ 004075d4

uint __cdecl FUN_004075d4(int param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 99999;
  local_8 = 0;
  for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
    iVar1 = FUN_0041b880(*(int *)(&DAT_004279cc + local_c * 0xc) - param_2);
    iVar2 = FUN_0041b880(*(int *)(&DAT_004279d0 + local_c * 0xc) - param_3);
    iVar3 = FUN_0041b880(*(int *)(&DAT_004279c8 + local_c * 0xc) - param_1);
    iVar3 = iVar1 + iVar2 + iVar3;
    in_EAX = local_10;
    if (iVar3 < local_10) {
      local_8 = local_c;
      in_EAX = local_c;
      local_10 = iVar3;
    }
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),(undefined1)local_8);
}


// ==== FUN_00407685 @ 00407685

void __cdecl FUN_00407685(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  short *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_30 = &DAT_0042a630;
  if (DAT_004291c8 == (int *)0x0) {
    return;
  }
  if (DAT_004291c8[1] != DAT_0042a634) {
    return;
  }
  if (DAT_004291c8[2] != DAT_0042a638) {
    return;
  }
  local_18 = DAT_004291c8[1];
  local_10 = ((uint)*(ushort *)((int)DAT_004291c8 + 0xe) * DAT_004291c8[1] + 0x1f & 0xffffffe0) >> 3
  ;
  local_20 = DAT_004291c8[2];
  if (DAT_004291c8[4] == 3) {
    iVar1 = *DAT_004291c8 + 0xc;
  }
  else {
    if ((DAT_004291c8[8] == 0) && (*(ushort *)((int)DAT_004291c8 + 0xe) < 9)) {
      local_34 = 1 << (*(byte *)((int)DAT_004291c8 + 0xe) & 0x1f);
    }
    else {
      local_34 = DAT_004291c8[8];
    }
    iVar1 = local_34 * 4 + *DAT_004291c8;
  }
  if (DAT_004293b8 == (short *)0x0) {
LAB_00407837:
    local_14 = 0;
  }
  else {
    if (*DAT_004293b8 == 0x400) {
      if ((int)DAT_004293b8[3] * (int)DAT_004293b8[4] - *(int *)(DAT_004293b8 + 1) == 0) {
        local_38 = 1;
      }
      else {
        local_38 = 0;
      }
    }
    else {
      local_38 = 0;
    }
    if (local_38 != 0) goto LAB_00407837;
    local_14 = (int)*DAT_004293b8;
  }
  if (DAT_004293b8 != (short *)0x0) {
    if (*DAT_004293b8 == 0x400) {
      if ((int)DAT_004293b8[3] * (int)DAT_004293b8[4] - *(int *)(DAT_004293b8 + 1) == 0) {
        local_3c = 1;
      }
      else {
        local_3c = 0;
      }
    }
    else {
      local_3c = 0;
    }
    if (local_3c == 0) {
      local_1c = (int)DAT_004293b8[1];
      goto LAB_004078e9;
    }
  }
  local_1c = 0;
LAB_004078e9:
  uVar2 = (param_3[2] - *param_3) + 1;
  iVar3 = (param_3[3] - param_3[1]) + 1;
  local_24 = (char *)(DAT_0042a618 + (local_20 - (iVar3 + param_2)) * local_10 + param_1);
  local_2c = (char *)((int)DAT_004291c8 +
                     (local_20 - (iVar3 + param_2)) * local_10 + param_1 + iVar1);
  if (DAT_004293b8 == (short *)0x0) {
    local_44 = (short *)0x0;
  }
  else {
    if (DAT_004293b8 == (short *)0x0) {
      local_40 = 0;
    }
    else if (*DAT_004293b8 == 0x400) {
      if ((int)DAT_004293b8[3] * (int)DAT_004293b8[4] - *(int *)(DAT_004293b8 + 1) == 0) {
        local_40 = 1;
      }
      else {
        local_40 = 0;
      }
    }
    else {
      local_40 = 0;
    }
    if (local_40 == 0) {
      local_44 = DAT_004293b8 + 2;
    }
    else {
      local_44 = (short *)0x0;
    }
  }
  local_28 = (char *)((int)local_44 + param_3[3] * local_14 + *param_3);
  uVar5 = uVar2;
  pcVar6 = local_2c;
  pcVar7 = local_28;
  pcVar8 = local_24;
  do {
    do {
      if (*pcVar7 != '\0') {
        *pcVar8 = *pcVar7 + *pcVar6 + -0x17;
      }
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
      pcVar6 = pcVar6 + 1;
      uVar4 = (short)uVar5 - 1;
      uVar5 = (uint)uVar4;
    } while (uVar4 != 0);
    pcVar7 = pcVar7 + (-uVar2 - local_14);
    pcVar8 = pcVar8 + (local_10 - uVar2);
    pcVar6 = pcVar6 + (local_10 - uVar2);
    iVar3 = iVar3 + -1;
    uVar5 = uVar2;
  } while (iVar3 != 0);
  local_8 = (param_3[2] - *param_3) + 1;
  local_c = (param_3[3] - param_3[1]) + 1;
  local_54 = param_1;
  local_50 = param_2;
  local_4c = param_1 + local_8 + -1;
  local_48 = local_c + param_2 + -1;
  FUN_00413ba3(&DAT_0042a610,&local_54);
  return;
}


// ==== FUN_00407ab0 @ 00407ab0

void __cdecl FUN_00407ab0(int param_1,int param_2,ushort param_3)

{
  int local_20;
  char local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_3 >> 2 & 7) == 0) {
    local_18 = '\x05';
  }
  else {
    local_18 = ((byte)(param_3 >> 2) & 7) - 1;
  }
  for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
    local_10 = local_18 * 0x24;
    local_8 = local_10 + 0x23;
    local_14 = local_20 * 0x24;
    local_c = local_14 + 0x23;
    FUN_00407685(param_2 * 0x24,param_1 * 0x24 + 0x28,&local_14);
  }
  return;
}


// ==== FUN_00407b6e @ 00407b6e

void __cdecl FUN_00407b6e(int param_1,int param_2,ushort param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char local_1c;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = param_2 * 0x24;
  iVar3 = param_1 * 0x24 + 0x28;
  if ((param_3 >> 2 & 7) == 0) {
    local_1c = '\x05';
  }
  else {
    local_1c = ((byte)(param_3 >> 2) & 7) - 1;
  }
  local_10 = local_1c * 0x24;
  local_8 = local_10 + 0x23;
  local_14 = 0;
  local_c = 0x23;
  FUN_00407685(iVar1,iVar3,&local_14);
  if ((param_3 >> 5 & 7) == 0) {
    local_1c = '\x05';
  }
  else {
    local_1c = ((byte)(param_3 >> 5) & 7) - 1;
  }
  local_10 = local_1c * 0x24;
  local_8 = local_10 + 0x23;
  local_14 = 0x24;
  local_c = 0x47;
  FUN_00407685(iVar1,iVar3,&local_14);
  bVar2 = (byte)(param_3 >> 8);
  if ((param_3 >> 8 & 7) == 0) {
    local_1c = '\x05';
  }
  else {
    local_1c = (bVar2 & 7) - 1;
  }
  local_10 = local_1c * 0x24;
  local_8 = local_10 + 0x23;
  local_14 = 0x48;
  local_c = 0x6b;
  FUN_00407685(iVar1,iVar3,&local_14);
  if ((param_3 >> 0xb & 7) == 0) {
    local_1c = '\x05';
  }
  else {
    local_1c = (bVar2 >> 3 & 7) - 1;
  }
  local_10 = local_1c * 0x24;
  local_8 = local_10 + 0x23;
  local_14 = 0x6c;
  local_c = 0x8f;
  FUN_00407685(iVar1,iVar3,&local_14);
  return;
}


// ==== FUN_00407d75 @ 00407d75

void __cdecl FUN_00407d75(char param_1,char param_2,ushort param_3)

{
  if ((param_3 & 3) == 0) {
    FUN_00407ab0((int)param_1,(int)param_2,param_3);
  }
  else if (((param_3 & 3) != 0) && ((param_3 & 3) < 4)) {
    FUN_00407b6e((int)param_1,(int)param_2,param_3);
  }
  return;
}


// ==== FUN_00407df7 @ 00407df7

void __cdecl FUN_00407df7(int param_1,int param_2,char param_3)

{
  char cVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = param_3 + -1;
  local_10 = (int)*(short *)(&DAT_004205d2 + cVar1 * 0x10);
  local_8 = *(short *)(&DAT_004205d6 + cVar1 * 0x10) + local_10 + -1;
  local_14 = (int)*(short *)(&DAT_004205d0 + cVar1 * 0x10);
  local_c = *(short *)(&DAT_004205d4 + cVar1 * 0x10) + local_14 + -1;
  FUN_00418652(&DAT_00429308,(int)*(short *)(&DAT_004205d8 + cVar1 * 0x10) + param_1 * 0x24,
               (int)*(short *)(&DAT_004205da + cVar1 * 0x10) + param_2 * 0x24 + 0x28,&local_14,1);
  return;
}


// ==== FUN_00407eb1 @ 00407eb1

void __cdecl FUN_00407eb1(int param_1,int param_2,char param_3)

{
  char cVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = param_3 + -1;
  (&DAT_004285f6)[param_1 * 10 + param_2 * 0x96] =
       (&DAT_004285f6)[param_1 * 10 + param_2 * 0x96] + '\x01';
  if (*(short *)(&DAT_004205dc + cVar1 * 0x10) <=
      (short)(ushort)(byte)(&DAT_004285f6)[param_1 * 10 + param_2 * 0x96]) {
    (&DAT_004285f6)[param_1 * 10 + param_2 * 0x96] = 0;
  }
  local_10 = (int)*(short *)(&DAT_004205d2 + cVar1 * 0x10);
  local_8 = *(short *)(&DAT_004205d6 + cVar1 * 0x10) + local_10 + -1;
  local_14 = (uint)(byte)(&DAT_004285f6)[param_1 * 10 + param_2 * 0x96] *
             (int)*(short *)(&DAT_004205d4 + cVar1 * 0x10) +
             (int)*(short *)(&DAT_004205d0 + cVar1 * 0x10);
  local_c = *(short *)(&DAT_004205d4 + cVar1 * 0x10) + local_14 + -1;
  FUN_00418652(&DAT_00429308,(int)*(short *)(&DAT_004205d8 + cVar1 * 0x10) + param_1 * 0x24,
               (int)*(short *)(&DAT_004205da + cVar1 * 0x10) + param_2 * 0x24 + 0x28,&local_14,1);
  return;
}


// ==== FUN_00408005 @ 00408005

void __cdecl FUN_00408005(int param_1,int param_2,char param_3)

{
  char cVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = param_3 + -1;
  (&DAT_004285f5)[param_1 * 10 + param_2 * 0x96] =
       (&DAT_004285f5)[param_1 * 10 + param_2 * 0x96] + '\x01';
  if (*(short *)(&DAT_004205dc + cVar1 * 0x10) <=
      (short)(ushort)(byte)(&DAT_004285f5)[param_1 * 10 + param_2 * 0x96]) {
    (&DAT_004285f5)[param_1 * 10 + param_2 * 0x96] = 0;
  }
  local_10 = (int)*(short *)(&DAT_004205d2 + cVar1 * 0x10);
  local_8 = *(short *)(&DAT_004205d6 + cVar1 * 0x10) + local_10 + -1;
  local_14 = (uint)(byte)(&DAT_004285f5)[param_1 * 10 + param_2 * 0x96] *
             (int)*(short *)(&DAT_004205d4 + cVar1 * 0x10) +
             (int)*(short *)(&DAT_004205d0 + cVar1 * 0x10);
  local_c = *(short *)(&DAT_004205d4 + cVar1 * 0x10) + local_14 + -1;
  FUN_00418652(&DAT_00429308,(int)*(short *)(&DAT_004205d8 + cVar1 * 0x10) + param_1 * 0x24,
               (int)*(short *)(&DAT_004205da + cVar1 * 0x10) + param_2 * 0x24 + 0x28,&local_14,1);
  return;
}


// ==== FUN_00408159 @ 00408159

void __cdecl FUN_00408159(int param_1,int param_2,char param_3)

{
  char cVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (&DAT_00420aec)[param_3 * 0x18] * '\x03' + param_3 + '\x10';
  (&DAT_00420ada)[param_3 * 0x18] = (&DAT_00420ada)[param_3 * 0x18] + '\x01';
  if (*(short *)(&DAT_004205dc + cVar1 * 0x10) <=
      (short)(ushort)(byte)(&DAT_00420ada)[param_3 * 0x18]) {
    (&DAT_00420ada)[param_3 * 0x18] = 0;
  }
  local_10 = (int)*(short *)(&DAT_004205d2 + cVar1 * 0x10);
  local_8 = *(short *)(&DAT_004205d6 + cVar1 * 0x10) + local_10 + -1;
  local_14 = (uint)(byte)(&DAT_00420ada)[param_3 * 0x18] *
             (int)*(short *)(&DAT_004205d4 + cVar1 * 0x10) +
             (int)*(short *)(&DAT_004205d0 + cVar1 * 0x10);
  local_c = *(short *)(&DAT_004205d4 + cVar1 * 0x10) + local_14 + -1;
  FUN_00418652(&DAT_00429308,(int)*(short *)(&DAT_004205d8 + cVar1 * 0x10) + param_1 * 0x24,
               (int)*(short *)(&DAT_004205da + cVar1 * 0x10) + param_2 * 0x24 + 0x28,&local_14,1);
  return;
}


// ==== FUN_004082a4 @ 004082a4

void __cdecl FUN_004082a4(byte param_1,byte param_2)

{
  if (*(short *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96) != 0) {
    FUN_00407df7((uint)param_2,(uint)param_1,
                 (char)*(undefined2 *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96));
  }
  return;
}


// ==== FUN_00408311 @ 00408311

void __cdecl FUN_00408311(byte param_1,byte param_2)

{
  if (((((&DAT_004285f4)[(uint)param_2 * 10 + (uint)param_1 * 0x96] == '\0') &&
       ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] == -1)) &&
      (*(short *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96) != 0)) &&
     (*(short *)(&DAT_004205dc +
                ((char)(&DAT_004285f2)[(uint)param_2 * 10 + (uint)param_1 * 0x96] + -1) * 0x10) != 0
     )) {
    FUN_00407d75(param_1,param_2,
                 *(ushort *)(&DAT_004291d0 + (uint)param_2 * 2 + (uint)param_1 * 0x1e));
    FUN_00407eb1((uint)param_2,(uint)param_1,
                 (char)*(undefined2 *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96));
  }
  return;
}


// ==== FUN_00408432 @ 00408432

void __cdecl FUN_00408432(byte param_1,byte param_2)

{
  if (((&DAT_004285f4)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != '\0') &&
     ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] == -1)) {
    FUN_00407d75(param_1,param_2,
                 *(ushort *)(&DAT_004291d0 + (uint)param_2 * 2 + (uint)param_1 * 0x1e));
    FUN_00408005((uint)param_2,(uint)param_1,
                 (&DAT_004285f4)[(uint)param_2 * 10 + (uint)param_1 * 0x96]);
  }
  return;
}


// ==== FUN_004084f7 @ 004084f7

void __cdecl FUN_004084f7(byte param_1,byte param_2)

{
  if ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != -1) {
    FUN_00407d75(param_1,param_2,
                 *(ushort *)(&DAT_004291d0 + (uint)param_2 * 2 + (uint)param_1 * 0x1e));
    FUN_00408159((uint)param_2,(uint)param_1,
                 (&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96]);
  }
  return;
}


// ==== FUN_00408593 @ 00408593

void __cdecl FUN_00408593(byte param_1,byte param_2)

{
  if (((&DAT_004285f4)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != '\0') &&
     ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] == -1)) {
    FUN_00407df7((uint)param_2,(uint)param_1,
                 (&DAT_004285f4)[(uint)param_2 * 10 + (uint)param_1 * 0x96]);
  }
  return;
}


// ==== FUN_0040862d @ 0040862d

void __cdecl FUN_0040862d(byte param_1,byte param_2)

{
  if ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != -1) {
    FUN_00407df7((uint)param_2,(uint)param_1,
                 (&DAT_00420aec)
                 [(uint)(byte)(&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] * 0x18] *
                 '\x03' + (&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] + '\x11');
  }
  return;
}


// ==== FUN_004086d4 @ 004086d4

void __cdecl FUN_004086d4(byte param_1,byte param_2)

{
  byte bVar1;
  
  if ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != -1) {
    bVar1 = (&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96];
    (&DAT_00420ad9)[(uint)bVar1 * 0x18] = param_2;
    (&DAT_00420ad8)[(uint)bVar1 * 0x18] = param_1;
    FUN_00407df7((uint)param_2,(uint)param_1,
                 (&DAT_00420aec)[(uint)bVar1 * 0x18] * '\x03' + bVar1 + '\x11');
  }
  return;
}


// ==== FUN_0040878c @ 0040878c

void FUN_0040878c(void)

{
  byte bVar1;
  byte bVar2;
  
  for (bVar1 = 0; (char)bVar1 < '\n'; bVar1 = bVar1 + 1) {
    for (bVar2 = 0; (char)bVar2 < '\x0f'; bVar2 = bVar2 + 1) {
      FUN_00407d75(bVar1,bVar2,*(ushort *)(&DAT_004291d0 + (char)bVar2 * 2 + (char)bVar1 * 0x1e));
      FUN_004082a4(bVar1,bVar2);
      FUN_00408593(bVar1,bVar2);
      FUN_004086d4(bVar1,bVar2);
    }
  }
  return;
}


// ==== FUN_00408834 @ 00408834

int FUN_00408834(void)

{
  char *pcVar1;
  char *pcVar2;
  char local_1c;
  char *local_18;
  char local_14;
  char local_c;
  
  *DAT_00428bd0 = DAT_00420ad8 * '\x10' + DAT_00420ad9;
  DAT_00428bd0[1] = DAT_00420af0 * '\x10' + DAT_00420af1;
  DAT_00428bd0[2] = DAT_00420ad8 * '\x10' + DAT_00420ad9;
  pcVar2 = DAT_00428bd0 + 3;
  local_18 = DAT_00428bd0 + 4;
  local_1c = '\0';
  for (local_c = '\0'; pcVar1 = local_18, local_c < '\n'; local_c = local_c + '\x01') {
    for (local_14 = '\0'; local_14 < '\x0f'; local_14 = local_14 + '\x01') {
      if (*(short *)(&DAT_004285f2 + local_14 * 10 + local_c * 0x96) != 0) {
        local_1c = local_1c + '\x01';
        *local_18 = local_c * '\x10' + local_14;
        *(undefined2 *)(local_18 + 1) =
             *(undefined2 *)(&DAT_004285f2 + local_14 * 10 + local_c * 0x96);
        local_18 = local_18 + 4;
      }
    }
  }
  *pcVar2 = local_1c;
  local_18 = local_18 + 1;
  local_1c = '\0';
  for (local_c = '\0'; local_c < '\n'; local_c = local_c + '\x01') {
    for (local_14 = '\0'; local_14 < '\x0f'; local_14 = local_14 + '\x01') {
      if ((&DAT_004285f4)[local_14 * 10 + local_c * 0x96] != '\0') {
        local_1c = local_1c + '\x01';
        *local_18 = local_c * '\x10' + local_14;
        local_18[1] = (&DAT_004285f4)[local_14 * 10 + local_c * 0x96];
        local_18 = local_18 + 2;
      }
    }
  }
  *pcVar1 = local_1c;
  return (int)local_18 - (int)DAT_00428bd0;
}


// ==== FUN_00408a27 @ 00408a27

void FUN_00408a27(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte local_1c;
  byte *local_18;
  
  pbVar5 = DAT_00428bd0 + 3;
  pbVar3 = DAT_00428bd0;
  for (local_1c = 0; local_18 = pbVar3 + 4, pbVar4 = local_18, local_1c < *pbVar5;
      local_1c = local_1c + 1) {
    *(undefined2 *)(&DAT_004285f2 + (uint)(*local_18 & 0xf) * 10 + (uint)(*local_18 >> 4) * 0x96) =
         *(undefined2 *)(pbVar3 + 5);
    pbVar3 = local_18;
  }
  local_18 = pbVar3 + 5;
  for (local_1c = 0; local_1c < *pbVar4; local_1c = local_1c + 1) {
    bVar1 = *local_18;
    bVar2 = *local_18;
    (&DAT_004285f4)[(uint)(bVar2 & 0xf) * 10 + (uint)(bVar1 >> 4) * 0x96] = local_18[1];
    (&DAT_004285f5)[(uint)(bVar2 & 0xf) * 10 + (uint)(bVar1 >> 4) * 0x96] = 0;
    local_18 = local_18 + 2;
  }
  return;
}


// ==== FUN_00408b5c @ 00408b5c

void __cdecl FUN_00408b5c(char param_1,char param_2,char param_3)

{
  FUN_00407df7((int)param_3,(int)param_2,param_1);
  return;
}


// ==== FUN_00408b85 @ 00408b85

void __cdecl FUN_00408b85(char param_1,byte param_2,byte param_3)

{
  FUN_00407df7((uint)param_3,(uint)param_2,param_1);
  return;
}


// ==== FUN_00408bad @ 00408bad

void __cdecl FUN_00408bad(char param_1,byte param_2,byte param_3)

{
  FUN_00407df7((uint)param_3,(uint)param_2,
               (&DAT_00420aec)[param_1 * 0x18] * '\x03' + param_1 + '\x11');
  return;
}


// ==== FUN_00408bed @ 00408bed

void __cdecl FUN_00408bed(char param_1,byte param_2,byte param_3)

{
  switch(param_1) {
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
  case '\v':
  case '\f':
    FUN_00408b5c(param_1,param_2,param_3);
    break;
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x10':
    FUN_00408b85(param_1,param_2,param_3);
    break;
  case '\x11':
    FUN_00408bad('\0',param_2,param_3);
    break;
  case '\x12':
    FUN_00408bad('\x01',param_2,param_3);
    break;
  case '\x13':
    FUN_00408bad('\x02',param_2,param_3);
  }
  return;
}


// ==== FUN_00408cd2 @ 00408cd2

void __cdecl FUN_00408cd2(char param_1)

{
  FUN_00408bed(param_1,0,0xf);
  return;
}


// ==== FUN_00408cf2 @ 00408cf2

undefined1 __cdecl FUN_00408cf2(byte param_1,byte param_2)

{
  undefined1 uVar1;
  
  if ((0 < *(short *)(&DAT_004285f2 + (char)param_2 * 10 + (char)param_1 * 0x96)) &&
     (*(short *)(&DAT_004285f2 + (char)param_2 * 10 + (char)param_1 * 0x96) < 0xd)) {
    FUN_004082a4(param_1,param_2);
    return (&DAT_004285f2)[(char)param_2 * 10 + (char)param_1 * 0x96];
  }
  if ((&DAT_004285f7)[(char)param_2 * 10 + (char)param_1 * 0x96] != -1) {
    FUN_0040862d(param_1,param_2);
    if ((&DAT_004285f7)[(char)param_2 * 10 + (char)param_1 * 0x96] == '\0') {
      return 0x11;
    }
    if ((&DAT_004285f7)[(char)param_2 * 10 + (char)param_1 * 0x96] == '\x01') {
      return 0x12;
    }
    if ((&DAT_004285f7)[(char)param_2 * 10 + (char)param_1 * 0x96] == '\x02') {
      return 0x13;
    }
  }
  if ((&DAT_004285f4)[(char)param_2 * 10 + (char)param_1 * 0x96] == '\0') {
    uVar1 = 0;
  }
  else {
    FUN_00408593(param_1,param_2);
    uVar1 = (&DAT_004285f4)[(char)param_2 * 10 + (char)param_1 * 0x96];
  }
  return uVar1;
}


// ==== FUN_00408e9d @ 00408e9d

void __cdecl FUN_00408e9d(byte param_1,byte param_2)

{
  FUN_00407d75(param_1,param_2,*(ushort *)(&DAT_004291d0 + (char)param_2 * 2 + (char)param_1 * 0x1e)
              );
  FUN_00408cf2(param_1,param_2);
  return;
}


// ==== FUN_00408ee9 @ 00408ee9

undefined4 __cdecl FUN_00408ee9(byte param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_1 & (&DAT_004285f0)[param_3 * 10 + param_2 * 0x96]) == 0) {
    uVar1 = 0;
  }
  else if ((&DAT_004285f4)[param_3 * 10 + param_2 * 0x96] == '\0') {
    if (param_4 == 0) {
      if ((&DAT_004294ba)[param_3 * 4 + param_2 * 0x3c] == '\0') {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


// ==== FUN_00408fab @ 00408fab

bool __cdecl FUN_00408fab(byte param_1,byte param_2,undefined1 param_3,int param_4)

{
  uint local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  switch(param_3) {
  case 0:
    if (param_1 == 0) {
      return false;
    }
    local_10 = (uint)param_2;
    local_c = (uint)param_1;
    do {
      local_c = local_c - 1;
      if ((int)local_c < 0) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 1:
    if (param_2 == 0xe) {
      return false;
    }
    local_c = (uint)param_1;
    local_10 = (uint)param_2;
    do {
      local_10 = local_10 + 1;
      if (0xe < (int)local_10) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 2:
    if (param_1 == 9) {
      return false;
    }
    local_10 = (uint)param_2;
    local_c = (uint)param_1;
    do {
      local_c = local_c + 1;
      if (9 < (int)local_c) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 3:
    if (param_2 == 0) {
      return false;
    }
    local_c = (uint)param_1;
    local_10 = (uint)param_2;
    do {
      local_10 = local_10 - 1;
      if ((int)local_10 < 0) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
  }
  if (local_8 != 0) {
    DAT_00429718 = (char)local_c;
    (&DAT_004294b9)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] = (char)(local_10 << 4) + DAT_00429718
    ;
    (&DAT_004294b8)[local_10 * 4 + local_c * 0x3c] = param_2 * '\x10' + param_1;
    DAT_0042971c = (undefined1)local_10;
  }
  return local_8 != 0;
}


// ==== FUN_004092cb @ 004092cb

void __cdecl FUN_004092cb(char param_1)

{
  FUN_00407d75((&DAT_00420ad8)[param_1 * 0x18],(&DAT_00420ad9)[param_1 * 0x18],
               *(ushort *)
                (&DAT_004291d0 +
                (uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 2 +
                (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x1e));
  FUN_0040862d((&DAT_00420ad8)[param_1 * 0x18],(&DAT_00420ad9)[param_1 * 0x18]);
  return;
}


// ==== FUN_0040935d @ 0040935d

void __cdecl FUN_0040935d(char param_1)

{
  (&DAT_004285f7)
  [(uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 10 +
   (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x96] = 0xff;
  (&DAT_004294ba)
  [(uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 4 +
   (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x3c] = 0;
  FUN_004092cb(param_1);
  return;
}


// ==== FUN_004093e4 @ 004093e4

bool FUN_004093e4(void)

{
  bool bVar1;
  byte local_c;
  byte local_8;
  
  local_8 = 0;
  do {
    if (9 < local_8) {
      bVar1 = DAT_00420c58 != 0;
      if (bVar1) {
        DAT_00420c58 = 0;
      }
      return bVar1;
    }
    for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
      if (((1 < *(short *)(&DAT_004285f2 + (uint)local_c * 10 + (uint)local_8 * 0x96)) &&
          (*(short *)(&DAT_004285f2 + (uint)local_c * 10 + (uint)local_8 * 0x96) < 9)) ||
         (*(short *)(&DAT_004285f2 + (uint)local_c * 10 + (uint)local_8 * 0x96) == 0xb)) {
        return false;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_004094da @ 004094da

bool FUN_004094da(void)

{
  byte local_10;
  byte local_c;
  char local_8;
  
  local_8 = '\0';
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
      if (((0 < *(short *)(&DAT_004285f2 + (uint)local_10 * 10 + (uint)local_c * 0x96)) &&
          (*(short *)(&DAT_004285f2 + (uint)local_10 * 10 + (uint)local_c * 0x96) < 9)) ||
         (*(short *)(&DAT_004285f2 + (uint)local_10 * 10 + (uint)local_c * 0x96) == 0xb)) {
        local_8 = local_8 + '\x01';
      }
    }
  }
  return local_8 != '\0';
}


// ==== FUN_004095c5 @ 004095c5

void __cdecl FUN_004095c5(char param_1,undefined1 param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  bool bVar5;
  char cVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar7;
  int local_24;
  int local_20;
  short local_18;
  
  if (((DAT_00420c2c != 3) || (param_1 != '\x01')) && ((DAT_00420c2c == 1 || (param_1 != '\x02'))))
  {
    (&DAT_00420aec)[param_1 * 0x18] = param_2;
    bVar1 = (&DAT_00420ad8)[param_1 * 0x18];
    bVar2 = (&DAT_00420ad9)[param_1 * 0x18];
    bVar5 = FUN_00408fab(bVar1,bVar2,param_2,1);
    if (CONCAT31(extraout_var,bVar5) == 1) {
      bVar3 = (&DAT_004285f0)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96];
      switch(param_2) {
      case 0:
        do {
          bVar1 = bVar1 - 1;
        } while ((bVar3 & (&DAT_004285f0)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96]) == 0);
        break;
      case 1:
        do {
          bVar2 = bVar2 + 1;
        } while ((bVar3 & (&DAT_004285f0)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96]) == 0);
        break;
      case 2:
        do {
          bVar1 = bVar1 + 1;
        } while ((bVar3 & (&DAT_004285f0)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96]) == 0);
        break;
      case 3:
        do {
          bVar2 = bVar2 - 1;
        } while ((bVar3 & (&DAT_004285f0)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96]) == 0);
      }
      if ((&DAT_004285f7)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96] == -1) {
        FUN_0040935d(param_1);
        if (*(short *)(&DAT_004285f2 + (uint)bVar2 * 10 + (uint)bVar1 * 0x96) != 0) {
          local_18 = 0;
          for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
            for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
              sVar4 = *(short *)(&DAT_004285f2 + local_24 * 10 + local_20 * 0x96);
              if ((8 < sVar4) && (sVar4 != 0xb)) {
                sVar4 = 0;
              }
              if (local_18 <= sVar4) {
                local_18 = sVar4;
              }
            }
          }
          if ((1 < *(short *)(&DAT_004285f2 + (uint)bVar2 * 10 + (uint)bVar1 * 0x96)) ||
             (*(short *)(&DAT_004285f2 + (uint)bVar2 * 10 + (uint)bVar1 * 0x96) == local_18)) {
            if (param_1 == '\x01') {
              cVar6 = FUN_0040718f(bVar1,bVar2,1);
              iVar7 = DAT_00420ac0 + -1;
              if (iVar7 < 2) {
                iVar7 = 1;
              }
              DAT_00420abc = DAT_00420abc + cVar6 * iVar7;
              FUN_00406c42();
            }
            sVar4 = *(short *)(&DAT_004285f2 + (uint)bVar2 * 10 + (uint)bVar1 * 0x96);
            if (sVar4 == 9) {
              bVar5 = false;
              for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
                for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
                  if ((&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] == '\x10') {
                    (&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] = 0;
                    FUN_00407d75((char)local_20,(char)local_24,
                                 *(ushort *)(&DAT_004291d0 + local_24 * 2 + local_20 * 0x1e));
                    bVar5 = true;
                    break;
                  }
                  if (bVar5) break;
                }
              }
            }
            else if (sVar4 == 10) {
              bVar5 = false;
              for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
                for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
                  if ((&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] == '\x0f') {
                    (&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] = 0;
                    FUN_00407d75((char)local_20,(char)local_24,
                                 *(ushort *)(&DAT_004291d0 + local_24 * 2 + local_20 * 0x1e));
                    bVar5 = true;
                    break;
                  }
                  if (bVar5) break;
                }
              }
            }
            else if (sVar4 == 0xc) {
              bVar5 = false;
              for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
                for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
                  if ((&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] == '\x0e') {
                    (&DAT_004285f4)[local_24 * 10 + local_20 * 0x96] = 0;
                    FUN_00407d75((char)local_20,(char)local_24,
                                 *(ushort *)(&DAT_004291d0 + local_24 * 2 + local_20 * 0x1e));
                    bVar5 = true;
                    break;
                  }
                  if (bVar5) break;
                }
              }
            }
            *(undefined2 *)(&DAT_004285f2 + (uint)bVar2 * 10 + (uint)bVar1 * 0x96) = 0;
            bVar5 = FUN_004094da();
            if (CONCAT31(extraout_var_00,bVar5) == 0) {
              if (param_1 != '\x01') {
                PostMessageA(DAT_00429778,0x111,0x22c,0);
                return;
              }
              FUN_0040f923(0x14);
              PostMessageA(DAT_00429778,0x111,0x22b,0);
            }
          }
        }
        FUN_00408e9d((&DAT_00420ad8)[param_1 * 0x18],(&DAT_00420ad9)[param_1 * 0x18]);
        (&DAT_00420ad8)[param_1 * 0x18] = bVar1;
        (&DAT_00420ad9)[param_1 * 0x18] = bVar2;
        (&DAT_004285f7)[(uint)bVar2 * 10 + (uint)bVar1 * 0x96] = param_1;
        FUN_004092cb(param_1);
      }
    }
    else {
      FUN_0040f923(0x13);
    }
  }
  return;
}


// ==== FUN_00409d13 @ 00409d13

void __cdecl FUN_00409d13(byte param_1,byte param_2)

{
  char cVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint local_10;
  byte local_c;
  
  local_c = (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] & 7;
  do {
    if ('\x03' < (char)local_c) {
      return;
    }
    (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] =
         (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] + '\x01';
    local_10 = FUN_0040690f(4);
    local_10 = local_10 & 0xff;
    while ((char)local_10 < '\x04') {
      if (((int)(uint)(byte)(&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] >>
           ((char)local_10 + 4U & 0x1f) & 1U) == 0) {
        (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] =
             (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] +
             (char)(1 << ((char)local_10 + 4U & 0x1f));
        bVar2 = FUN_00408fab(param_1,param_2,(char)local_10,0);
        if (CONCAT31(extraout_var,bVar2) == 1) {
          return;
        }
      }
      local_10 = (uint)(byte)((char)local_10 + 1);
    }
    if ((char)local_10 == '\x04') {
      for (cVar1 = '\0'; cVar1 < '\x04'; cVar1 = cVar1 + '\x01') {
        if (((int)(uint)(byte)(&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] >>
             (cVar1 + 4U & 0x1f) & 1U) == 0) {
          (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] =
               (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] +
               (char)(1 << (cVar1 + 4U & 0x1f));
          bVar2 = FUN_00408fab(param_1,param_2,cVar1,0);
          if (CONCAT31(extraout_var_00,bVar2) == 1) {
            return;
          }
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== FUN_00409f1c @ 00409f1c

void __cdecl FUN_00409f1c(byte param_1,byte param_2)

{
  DAT_0042971c = (byte)(&DAT_004294b8)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] >> 4;
  DAT_00429718 = (&DAT_004294b8)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] & 0xf;
  return;
}


// ==== FUN_00409f79 @ 00409f79

undefined4 FUN_00409f79(void)

{
  DAT_0042971c = DAT_00420ad9;
  DAT_00429718 = DAT_00420ad8;
  FUN_00409d13(DAT_00420ad8,DAT_00420ad9);
  while( true ) {
    while( true ) {
      if (*(short *)(&DAT_004285f2 + (uint)DAT_0042971c * 10 + (uint)DAT_00429718 * 0x96) != 0) {
        return 1;
      }
      if (((&DAT_004294ba)[(uint)DAT_0042971c * 4 + (uint)DAT_00429718 * 0x3c] & 7) == 4) break;
      FUN_00409d13(DAT_00429718,DAT_0042971c);
    }
    if ((DAT_00420ad9 == DAT_0042971c) && (DAT_00420ad8 == DAT_00429718)) break;
    FUN_00409f1c(DAT_00429718,DAT_0042971c);
  }
  return 0;
}


// ==== FUN_0040a07f @ 0040a07f

undefined4 FUN_0040a07f(void)

{
  LPCSTR pCVar1;
  HGLOBAL hResData;
  LPVOID pvVar2;
  char *pcVar3;
  uint *puVar4;
  int local_18;
  int local_14;
  uint local_c;
  void *local_8;
  
  puVar4 = &local_c;
  pcVar3 = s_GLEVEL_00420e90;
  pCVar1 = FUN_0040ec60((uint *)s_LEVEL_00420e98,DAT_00420474,3);
  hResData = FUN_00401078(DAT_004293b0,pCVar1,pcVar3,puVar4);
  if ((hResData == (HGLOBAL)0x0) || (local_c < 0x12e)) {
    return 0;
  }
  pvVar2 = LockResource(hResData);
  local_8 = (void *)((int)pvVar2 + 2);
  FID_conflict__memcpy(&DAT_004291d0,local_8,300);
  local_8 = (void *)((int)local_8 + 300);
  FID_conflict__memcpy(DAT_00428bd0,local_8,local_c - 0x12e);
  FreeResource(hResData);
  for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < 0xf; local_18 = local_18 + 1) {
      (&DAT_004285f0)[local_18 * 10 + local_14 * 0x96] = 0;
      (&DAT_00428be8)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f0)[local_18 * 10 + local_14 * 0x96];
      *(undefined2 *)(&DAT_004285f2 + local_18 * 10 + local_14 * 0x96) = 0;
      *(undefined2 *)(&DAT_00428bea + local_18 * 10 + local_14 * 0x96) =
           *(undefined2 *)(&DAT_004285f2 + local_18 * 10 + local_14 * 0x96);
      (&DAT_004285f4)[local_18 * 10 + local_14 * 0x96] = 0;
      (&DAT_00428bec)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f4)[local_18 * 10 + local_14 * 0x96];
      (&DAT_004285f5)[local_18 * 10 + local_14 * 0x96] = 0;
      (&DAT_00428bed)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f5)[local_18 * 10 + local_14 * 0x96];
      (&DAT_004285f6)[local_18 * 10 + local_14 * 0x96] = 0;
      (&DAT_00428bee)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f6)[local_18 * 10 + local_14 * 0x96];
      (&DAT_004285f7)[local_18 * 10 + local_14 * 0x96] = 0xff;
      (&DAT_00428bef)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f7)[local_18 * 10 + local_14 * 0x96];
      (&DAT_004285f8)[local_18 * 10 + local_14 * 0x96] = 0;
      (&DAT_00428bf0)[local_18 * 10 + local_14 * 0x96] =
           (&DAT_004285f8)[local_18 * 10 + local_14 * 0x96];
      (&DAT_00429408)[local_18 + local_14 * 0xf] = 0;
      (&DAT_004294b8)[local_18 * 4 + local_14 * 0x3c] = 0;
      (&DAT_004294b9)[local_18 * 4 + local_14 * 0x3c] = 0;
      (&DAT_004294ba)[local_18 * 4 + local_14 * 0x3c] = 0;
      (&DAT_004294bb)[local_18 * 4 + local_14 * 0x3c] = 0;
    }
  }
  for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < 0xf; local_18 = local_18 + 1) {
      FUN_00407347(local_14,local_18);
    }
  }
  FUN_00408a27();
  if (DAT_00420c2c != 0) {
    if (DAT_00420c2c == 1) {
      (&DAT_004285f7)
      [((int)DAT_00428bd0[2] & 0xfU) * 10 + ((uint)(int)DAT_00428bd0[2] >> 4 & 0xf) * 0x96] = 2;
    }
    else if (DAT_00420c2c != 2) goto LAB_0040a506;
  }
  (&DAT_004285f7)
  [((int)DAT_00428bd0[1] & 0xfU) * 10 + ((uint)(int)DAT_00428bd0[1] >> 4 & 0xf) * 0x96] = 1;
LAB_0040a506:
  if (1 < DAT_00420c2c) {
    (&DAT_004285f7)[((int)*DAT_00428bd0 & 0xfU) * 10 + ((uint)(int)*DAT_00428bd0 >> 4 & 0xf) * 0x96]
         = 0;
  }
  FUN_0040878c();
  if (1 < DAT_00420c2c) {
    DAT_004293b4 = DAT_00420ac4;
  }
  DAT_004294b0 = 10;
  DAT_00429374 = 100;
  DAT_004285ec = 0xe;
  DAT_004285e8 = 0xd;
  return 1;
}


// ==== FUN_0040a596 @ 0040a596

undefined4 __cdecl FUN_0040a596(byte param_1,byte param_2,undefined1 param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined3 extraout_var;
  
  if ((byte)(&DAT_004285f4)[(char)param_2 * 10 + (char)param_1 * 0x96] < 0xe) {
    bVar5 = FUN_00408fab(param_1,param_2,param_3,1);
    if (CONCAT31(extraout_var,bVar5) == 1) {
      bVar1 = (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96];
      bVar3 = param_1;
      bVar4 = param_2;
      switch(param_3) {
      case 0:
        do {
          bVar3 = bVar3 - 1;
        } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)bVar3 * 0x96]) == 0);
        break;
      case 1:
        do {
          bVar4 = bVar4 + 1;
        } while ((bVar1 & (&DAT_004285f0)[(uint)bVar4 * 10 + (uint)param_1 * 0x96]) == 0);
        break;
      case 2:
        do {
          bVar3 = bVar3 + 1;
        } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)bVar3 * 0x96]) == 0);
        break;
      case 3:
        do {
          bVar4 = bVar4 - 1;
        } while ((bVar1 & (&DAT_004285f0)[(uint)bVar4 * 10 + (uint)param_1 * 0x96]) == 0);
      }
      if ((&DAT_004285f7)[(uint)bVar4 * 10 + (uint)bVar3 * 0x96] == -1) {
        cVar2 = (&DAT_004285f4)[(char)param_2 * 10 + (char)param_1 * 0x96];
        (&DAT_004285f4)[(char)param_2 * 10 + (char)param_1 * 0x96] = 0;
        (&DAT_004285f4)[(uint)bVar4 * 10 + (uint)bVar3 * 0x96] = cVar2 + '(';
        FUN_00408e9d(param_1,param_2);
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 1;
  }
  return uVar6;
}


// ==== FUN_0040a80e @ 0040a80e

void FUN_0040a80e(void)

{
  byte local_8;
  
  DAT_004285ec = DAT_004285ec + -1;
  if (DAT_004285ec < 1) {
    DAT_004285ec = 0xe;
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      FUN_004084f7((&DAT_00420ad8)[(uint)local_8 * 0x18],(&DAT_00420ad9)[(uint)local_8 * 0x18]);
    }
  }
  return;
}


// ==== FUN_0040a88a @ 0040a88a

void FUN_0040a88a(void)

{
  byte bVar1;
  byte bVar2;
  
  DAT_004294b0 = DAT_004294b0 + -1;
  if (DAT_004294b0 < 1) {
    DAT_004294b0 = 10;
    for (bVar1 = 0; bVar1 < 10; bVar1 = bVar1 + 1) {
      for (bVar2 = 0; bVar2 < 0xf; bVar2 = bVar2 + 1) {
        FUN_00408311(bVar1,bVar2);
      }
    }
  }
  return;
}


// ==== FUN_0040a90d @ 0040a90d

void FUN_0040a90d(void)

{
  int iVar1;
  char local_18 [4];
  byte local_14;
  undefined3 uStack_13;
  uint local_10;
  uint local_c;
  char local_8;
  
  DAT_004285e8 = DAT_004285e8 + -1;
  DAT_00429374 = DAT_00429374 + -1;
  if (DAT_00429374 < 1) {
    DAT_00429374 = 100;
    local_c = (uint)local_c._1_3_ << 8;
    while ((byte)local_c < 4) {
      local_18[local_c & 0xff] = '\0';
      local_c = CONCAT31(local_c._1_3_,(byte)local_c + '\x01');
    }
    iVar1 = FUN_0040690f(4);
    local_14 = (byte)iVar1;
    do {
      if ((int)local_18[2] + (int)local_18[3] + (int)local_18[0] + (int)local_18[1] == 4) break;
      local_8 = '\0';
      for (; local_14 < 4; local_14 = local_14 + 1) {
        if (local_18[local_14] == '\0') {
          local_18[local_14] = '\x01';
          break;
        }
      }
      if (local_14 == 4) {
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          if (local_18[local_14] == '\0') {
            local_18[local_14] = '\x01';
            break;
          }
        }
      }
      local_c = local_c & 0xffffff00;
      while ((byte)local_c < 10) {
        local_10 = local_10 & 0xffffff00;
        while( true ) {
          if (0xe < (byte)local_10) break;
          if ((((&DAT_004285f4)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96] != '\0') &&
              ((byte)(&DAT_004285f4)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96] < 0x28)) &&
             (iVar1 = FUN_0040a596((byte)local_c,(byte)local_10,local_14), iVar1 == 1)) {
            local_8 = local_8 + '\x01';
          }
          local_10 = CONCAT31(local_10._1_3_,(byte)local_10 + '\x01');
        }
        local_c = CONCAT31(local_c._1_3_,(byte)local_c + 1);
      }
    } while (local_8 == '\0');
    local_c = local_c & 0xffffff00;
    while ((byte)local_c < 10) {
      local_10 = local_10 & 0xffffff00;
      while( true ) {
        if (0xe < (byte)local_10) break;
        if (0x27 < (byte)(&DAT_004285f4)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96]) {
          (&DAT_004285f4)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96] =
               (&DAT_004285f4)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96] + -0x28;
          iVar1 = FUN_0040690f((int)DAT_0042060c);
          (&DAT_004285f5)[(local_10 & 0xff) * 10 + (local_c & 0xff) * 0x96] = (char)iVar1;
        }
        local_10 = CONCAT31(local_10._1_3_,(byte)local_10 + '\x01');
      }
      local_c = CONCAT31(local_c._1_3_,(byte)local_c + '\x01');
    }
    FUN_00406d5e();
  }
  else if (DAT_004285e8 < 1) {
    DAT_004285e8 = 0xd;
    local_c = (uint)local_c._1_3_ << 8;
    while ((byte)local_c < 10) {
      local_10 = local_10 & 0xffffff00;
      while( true ) {
        if (0xe < (byte)local_10) break;
        FUN_00408432((byte)local_c,(byte)local_10);
        local_10 = CONCAT31(local_10._1_3_,(byte)local_10 + '\x01');
      }
      local_c = CONCAT31(local_c._1_3_,(byte)local_c + 1);
    }
  }
  return;
}


// ==== FUN_0040ac40 @ 0040ac40

undefined4 __cdecl
FUN_0040ac40(byte param_1,byte param_2,byte param_3,byte param_4,byte param_5,byte param_6,
            byte param_7)

{
  undefined4 uVar1;
  
  if (((uint)(byte)(&DAT_004294b8)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] ==
       (uint)param_5 * 0x10 + (uint)param_4) ||
     ((uint)(byte)(&DAT_004294b9)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] ==
      (uint)param_5 * 0x10 + (uint)param_4)) {
    uVar1 = 0;
  }
  else if ((&DAT_004285f4)[(uint)param_3 * 10 + (uint)param_2 * 0x96] == '\0') {
    if ((&DAT_004294ba)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] == '\0') {
      if ((param_1 & (&DAT_004285f0)[(uint)param_3 * 10 + (uint)param_2 * 0x96]) == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 1;
      }
    }
    else if ((param_1 & (&DAT_004285f0)[(uint)param_3 * 10 + (uint)param_2 * 0x96]) == 0) {
      uVar1 = 3;
    }
    else if ((byte)(&DAT_004294bb)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] <
             (byte)(&DAT_004294bb)[(uint)param_7 * 4 + (uint)param_6 * 0x3c]) {
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040ade6 @ 0040ade6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040ade6(byte param_1,byte param_2,undefined1 param_3)

{
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  int local_8;
  
  DAT_004294a0 = param_1;
  DAT_004294a4 = param_2;
  local_8 = 0;
  _DAT_004293a8 = 0;
  switch(param_3) {
  case 0:
    if (param_1 == 0) {
      uVar1 = 0;
    }
    else {
      local_c = (uint)param_1;
      do {
        local_c = local_c - 1;
        if ((int)local_c < 0) goto switchD_0040b12d_default;
        local_8 = FUN_0040ac40((&DAT_004285f0)[(uint)DAT_004294a4 * 10 + (uint)DAT_004294a0 * 0x96],
                               (byte)local_c,param_2,DAT_004294a0,DAT_004294a4,param_1,param_2);
        if (local_8 == 1) {
          DAT_004294a0 = (byte)local_c;
        }
        if (local_8 == 2) goto switchD_0040b12d_default;
      } while (local_8 != 0);
      uVar1 = 0;
    }
    break;
  case 1:
    if (param_2 == 0xe) {
      uVar1 = 0;
    }
    else {
      local_10 = (uint)param_2;
      do {
        local_10 = local_10 + 1;
        if (0xe < (int)local_10) goto switchD_0040b12d_default;
        local_8 = FUN_0040ac40((&DAT_004285f0)[(uint)DAT_004294a4 * 10 + (uint)DAT_004294a0 * 0x96],
                               param_1,(byte)local_10,DAT_004294a0,DAT_004294a4,param_1,param_2);
        if (local_8 == 1) {
          DAT_004294a4 = (byte)local_10;
        }
        if (local_8 == 2) goto switchD_0040b12d_default;
      } while (local_8 != 0);
      uVar1 = 0;
    }
    break;
  case 2:
    if (param_1 == 9) {
      uVar1 = 0;
    }
    else {
      local_c = (uint)param_1;
      do {
        local_c = local_c + 1;
        if (9 < (int)local_c) goto switchD_0040b12d_default;
        local_8 = FUN_0040ac40((&DAT_004285f0)[(uint)DAT_004294a4 * 10 + (uint)DAT_004294a0 * 0x96],
                               (byte)local_c,param_2,DAT_004294a0,DAT_004294a4,param_1,param_2);
        if (local_8 == 1) {
          DAT_004294a0 = (byte)local_c;
        }
        if (local_8 == 2) goto switchD_0040b12d_default;
      } while (local_8 != 0);
      uVar1 = 0;
    }
    break;
  case 3:
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      local_10 = (uint)param_2;
      do {
        local_10 = local_10 - 1;
        if ((int)local_10 < 0) goto switchD_0040b12d_default;
        local_8 = FUN_0040ac40((&DAT_004285f0)[(uint)DAT_004294a4 * 10 + (uint)DAT_004294a0 * 0x96],
                               param_1,(byte)local_10,DAT_004294a0,DAT_004294a4,param_1,param_2);
        if (local_8 == 1) {
          DAT_004294a4 = (byte)local_10;
        }
        if (local_8 == 2) goto switchD_0040b12d_default;
      } while (local_8 != 0);
      uVar1 = 0;
    }
    break;
  default:
switchD_0040b12d_default:
    if (local_8 == 2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_0040b164 @ 0040b164

undefined4 __cdecl FUN_0040b164(byte param_1,byte param_2,byte param_3,byte param_4,byte param_5)

{
  undefined4 uVar1;
  
  if ((param_1 & (&DAT_004285f0)[(uint)param_3 * 10 + (uint)param_2 * 0x96]) == 0) {
    uVar1 = 3;
  }
  else {
    (&DAT_004294b9)[(uint)param_5 * 4 + (uint)param_4 * 0x3c] = param_3 * '\x10' + param_2;
    (&DAT_004294b8)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] = param_5 * '\x10' + param_4;
    if ((&DAT_004294ba)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] == '\0') {
      (&DAT_004294ba)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] = 1;
      (&DAT_004294bb)[(uint)param_3 * 4 + (uint)param_2 * 0x3c] =
           (&DAT_004294bb)[(uint)param_5 * 4 + (uint)param_4 * 0x3c] + '\x01';
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
  }
  return uVar1;
}


// ==== FUN_0040b288 @ 0040b288

undefined4 __cdecl FUN_0040b288(byte param_1,byte param_2,undefined1 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint local_20;
  uint local_1c;
  byte local_14;
  byte local_c;
  int local_8;
  
  bVar1 = (&DAT_004294b9)[(uint)param_2 * 4 + (uint)param_1 * 0x3c];
  local_8 = 0;
  switch(param_3) {
  case 0:
    local_20 = (uint)param_2;
    if (param_1 == 0) {
      return 0;
    }
    local_1c = (uint)param_1;
    do {
      local_1c = local_1c - 1;
      if ((int)local_1c < 0) break;
      local_8 = FUN_0040b164((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],
                             (byte)local_1c,param_2,param_1,param_2);
      if (local_8 == 1) {
        param_1 = (byte)local_1c;
      }
    } while (local_8 != 2);
    break;
  case 1:
    local_1c = (uint)param_1;
    if (param_2 == 0xe) {
      return 0;
    }
    local_20 = (uint)param_2;
    do {
      local_20 = local_20 + 1;
      if (0xe < (int)local_20) break;
      local_8 = FUN_0040b164((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],param_1,
                             (byte)local_20,param_1,param_2);
      if (local_8 == 1) {
        param_2 = (byte)local_20;
      }
    } while (local_8 != 2);
    break;
  case 2:
    local_20 = (uint)param_2;
    if (param_1 == 9) {
      return 0;
    }
    local_1c = (uint)param_1;
    do {
      local_1c = local_1c + 1;
      if (9 < (int)local_1c) break;
      local_8 = FUN_0040b164((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],
                             (byte)local_1c,param_2,param_1,param_2);
      if (local_8 == 1) {
        param_1 = (byte)local_1c;
      }
    } while (local_8 != 2);
    break;
  case 3:
    local_1c = (uint)param_1;
    if (param_2 == 0) {
      return 0;
    }
    local_20 = (uint)param_2;
    do {
      local_20 = local_20 - 1;
      if ((int)local_20 < 0) break;
      local_8 = FUN_0040b164((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],param_1,
                             (byte)local_20,param_1,param_2);
      if (local_8 == 1) {
        param_2 = (byte)local_20;
      }
    } while (local_8 != 2);
  }
  if (local_8 == 2) {
    for (local_14 = (byte)((uint)(int)(char)bVar1 >> 4) & 0xf;
        (local_c = bVar1 & 0xf, (int)(char)local_c != local_1c || ((int)(char)local_14 != local_20))
        ; local_14 = (byte)(&DAT_004294b9)[(char)local_14 * 4 + (char)local_c * 0x3c] >> 4) {
      (&DAT_004294ba)[(char)local_14 * 4 + (char)local_c * 0x3c] = 0;
      bVar1 = (&DAT_004294b9)[(char)local_14 * 4 + (char)local_c * 0x3c];
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0040b615 @ 0040b615

undefined4 __cdecl FUN_0040b615(byte param_1,byte param_2)

{
  int iVar1;
  char local_64;
  int local_60;
  int local_c;
  
  local_64 = '\0';
  local_c = 0;
  do {
    if (3 < local_c) {
      return 1;
    }
    iVar1 = FUN_0040690f(4);
    for (local_60 = (int)(char)iVar1; local_60 < 4; local_60 = local_60 + 1) {
      if (((int)local_64 >> ((char)local_60 + 4U & 0x1f) & 1U) == 0) {
        local_64 = (char)(1 << ((char)local_60 + 4U & 0x1f)) + local_64;
        break;
      }
    }
    if (local_60 == 4) {
      for (local_60 = 0; local_60 < 4; local_60 = local_60 + 1) {
        if (((int)local_64 >> ((char)local_60 + 4U & 0x1f) & 1U) == 0) {
          local_64 = (char)(1 << ((char)local_60 + 4U & 0x1f)) + local_64;
          break;
        }
      }
    }
    iVar1 = FUN_0040ade6(param_1,param_2,(char)local_60);
    if (iVar1 != 0) {
      FUN_0040b288(param_1,param_2,(char)local_60);
      return 1;
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== FUN_0040b758 @ 0040b758

void __cdecl FUN_0040b758(byte param_1,byte param_2,byte param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  
  while (((param_3 != param_1 || (param_4 != param_2)) &&
         (iVar1 = FUN_0040b615(param_1,param_2), iVar1 != 0))) {
    uVar2 = (uint)param_2;
    param_2 = (byte)(&DAT_004294b9)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] >> 4;
    param_1 = (&DAT_004294b9)[uVar2 * 4 + (uint)param_1 * 0x3c] & 0xf;
  }
  return;
}


// ==== FUN_0040b804 @ 0040b804

void __cdecl FUN_0040b804(byte param_1,byte param_2,byte param_3,byte param_4)

{
  uint uVar1;
  char local_c;
  
  local_c = '\0';
  while ((param_3 != param_1 || (param_4 != param_2))) {
    (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] = 1;
    (&DAT_004294bb)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] = local_c;
    local_c = local_c + '\x01';
    uVar1 = (uint)param_2;
    param_2 = (byte)(&DAT_004294b9)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] >> 4;
    param_1 = (&DAT_004294b9)[uVar1 * 4 + (uint)param_1 * 0x3c] & 0xf;
  }
  (&DAT_004285f7)[(uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96] = 0;
  (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] = 0;
  (&DAT_004294bb)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] = local_c;
  return;
}


// ==== FUN_0040b932 @ 0040b932

bool __cdecl FUN_0040b932(byte param_1,byte param_2,undefined1 param_3,int param_4)

{
  uint local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  switch(param_3) {
  case 0:
    if (param_1 == 0) {
      return false;
    }
    local_c = (uint)param_1;
    do {
      local_c = local_c - 1;
      if ((int)local_c < 0) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             (uint)param_2,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 1:
    if (param_2 == 0xe) {
      return false;
    }
    local_10 = (uint)param_2;
    do {
      local_10 = local_10 + 1;
      if (0xe < (int)local_10) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],
                             (uint)param_1,local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 2:
    if (param_1 == 9) {
      return false;
    }
    local_c = (uint)param_1;
    do {
      local_c = local_c + 1;
      if (9 < (int)local_c) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],local_c,
                             (uint)param_2,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
    break;
  case 3:
    if (param_2 == 0) {
      return false;
    }
    local_10 = (uint)param_2;
    do {
      local_10 = local_10 - 1;
      if ((int)local_10 < 0) break;
      local_8 = FUN_00408ee9((&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96],
                             (uint)param_1,local_10,param_4);
      if (local_8 == 2) {
        return false;
      }
    } while (local_8 == 0);
  }
  return local_8 != 0;
}


// ==== FUN_0040bbfa @ 0040bbfa

char __cdecl FUN_0040bbfa(byte param_1,byte param_2,undefined1 param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  undefined3 extraout_var;
  int local_20;
  int local_1c;
  char local_8;
  
  local_8 = '\0';
  while( true ) {
    bVar3 = FUN_0040b932(param_1,param_2,param_3,1);
    if (CONCAT31(extraout_var,bVar3) != 1) {
      return '\0';
    }
    bVar1 = (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96];
    switch(param_3) {
    case 0:
      local_8 = local_8 + '\x01';
      do {
        param_1 = param_1 - 1;
      } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96]) == 0);
      break;
    case 1:
      local_8 = local_8 + '\x01';
      do {
        param_2 = param_2 + 1;
      } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96]) == 0);
      break;
    case 2:
      local_8 = local_8 + '\x01';
      do {
        param_1 = param_1 + 1;
      } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96]) == 0);
      break;
    case 3:
      local_8 = local_8 + '\x01';
      do {
        param_2 = param_2 - 1;
      } while ((bVar1 & (&DAT_004285f0)[(uint)param_2 * 10 + (uint)param_1 * 0x96]) == 0);
    }
    if ((&DAT_004285f7)[(uint)param_2 * 10 + (uint)param_1 * 0x96] != -1) break;
    if (*(short *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96) != 0) {
      sVar2 = 0;
      for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < 0xf; local_20 = local_20 + 1) {
          sVar4 = *(short *)(&DAT_004285f2 + local_20 * 10 + local_1c * 0x96);
          if (*(short *)(&DAT_004285f2 + local_20 * 10 + local_1c * 0x96) <= sVar2) {
            sVar4 = sVar2;
          }
          sVar2 = sVar4;
        }
      }
      if (1 < *(short *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96)) {
        return local_8;
      }
      if (*(short *)(&DAT_004285f2 + (uint)param_2 * 10 + (uint)param_1 * 0x96) == sVar2) {
        return local_8;
      }
    }
  }
  return '\0';
}


// ==== FUN_0040bec3 @ 0040bec3

int __cdecl FUN_0040bec3(byte param_1,byte param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte local_14;
  char local_10;
  byte abStack_8 [4];
  
  for (cVar1 = '\0'; cVar1 < '\x04'; cVar1 = cVar1 + '\x01') {
    bVar2 = FUN_0040bbfa(param_1,param_2,cVar1);
    abStack_8[cVar1] = bVar2;
  }
  local_10 = '\0';
  local_14 = 100;
  for (cVar1 = '\0'; cVar1 < '\x04'; cVar1 = cVar1 + '\x01') {
    if ((abStack_8[cVar1] != 0) && ((int)(uint)abStack_8[cVar1] < (int)(char)local_14)) {
      local_14 = abStack_8[cVar1];
      local_10 = cVar1;
    }
  }
  if (local_14 == 100) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_10 + 1;
  }
  return iVar3;
}


// ==== FUN_0040bf8f @ 0040bf8f

void __cdecl FUN_0040bf8f(byte param_1,byte param_2,char param_3)

{
  (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] =
       (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] + '\x01';
  (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] =
       (&DAT_004294ba)[(uint)param_2 * 4 + (uint)param_1 * 0x3c] +
       (char)(1 << (param_3 + 4U & 0x1f));
  FUN_00408fab(param_1,param_2,param_3,0);
  return;
}


// ==== FUN_0040c014 @ 0040c014

void __cdecl FUN_0040c014(byte param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040bec3(param_1,param_2);
  if ((char)iVar1 == '\0') {
    FUN_00409d13(param_1,param_2);
  }
  else {
    FUN_0040bf8f(param_1,param_2,(char)iVar1 + -1);
  }
  return;
}


// ==== FUN_0040c071 @ 0040c071

undefined4 FUN_0040c071(void)

{
  short sVar1;
  char local_14;
  char local_10;
  short local_c;
  
  DAT_0042971c = DAT_00420ad9;
  DAT_00429718 = DAT_00420ad8;
  FUN_0040c014(DAT_00420ad8,DAT_00420ad9);
  do {
    if (*(short *)(&DAT_004285f2 + (uint)DAT_0042971c * 10 + (uint)DAT_00429718 * 0x96) != 0) {
      local_c = 0;
      for (local_10 = '\0'; local_10 < '\n'; local_10 = local_10 + '\x01') {
        for (local_14 = '\0'; local_14 < '\x0f'; local_14 = local_14 + '\x01') {
          sVar1 = *(short *)(&DAT_004285f2 + local_14 * 10 + local_10 * 0x96);
          if (*(short *)(&DAT_004285f2 + local_14 * 10 + local_10 * 0x96) <= local_c) {
            sVar1 = local_c;
          }
          local_c = sVar1;
        }
      }
      if ((1 < *(short *)(&DAT_004285f2 + (uint)DAT_0042971c * 10 + (uint)DAT_00429718 * 0x96)) ||
         (*(short *)(&DAT_004285f2 + (uint)DAT_0042971c * 10 + (uint)DAT_00429718 * 0x96) == local_c
         )) {
        for (local_10 = '\0'; local_10 < '\n'; local_10 = local_10 + '\x01') {
          for (local_14 = '\0'; local_14 < '\x0f'; local_14 = local_14 + '\x01') {
            (&DAT_004294ba)[local_14 * 4 + local_10 * 0x3c] = 0;
          }
        }
        FUN_0040b804(DAT_00420ad8,DAT_00420ad9,DAT_00429718,DAT_0042971c);
        return 1;
      }
    }
    if (((&DAT_004294ba)[(uint)DAT_0042971c * 4 + (uint)DAT_00429718 * 0x3c] & 7) == 4) {
      if ((DAT_00420ad9 == DAT_0042971c) && (DAT_00420ad8 == DAT_00429718)) {
        return 0;
      }
      FUN_00409f1c(DAT_00429718,DAT_0042971c);
    }
    else {
      FUN_0040c014(DAT_00429718,DAT_0042971c);
    }
  } while( true );
}


// ==== FUN_0040c2bd @ 0040c2bd

void __cdecl FUN_0040c2bd(char param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (&DAT_004294b9)
          [(uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 4 +
           (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x3c] & 0xf;
  bVar1 = (byte)(&DAT_004294b9)
                [(uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 4 +
                 (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x3c] >> 4;
  if ((int)((uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] - (uint)bVar2) < 0) {
    (&DAT_00420aec)[param_1 * 0x18] = 2;
  }
  if ((int)((uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] - (uint)bVar1) < 0) {
    (&DAT_00420aec)[param_1 * 0x18] = 1;
  }
  if ((uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] != (uint)bVar2 &&
      -1 < (int)((uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] - (uint)bVar2)) {
    (&DAT_00420aec)[param_1 * 0x18] = 0;
  }
  if ((uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] != (uint)bVar1 &&
      -1 < (int)((uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] - (uint)bVar1)) {
    (&DAT_00420aec)[param_1 * 0x18] = 3;
  }
  (&DAT_00420ad8)[param_1 * 0x18] = bVar2;
  (&DAT_00420ad9)[param_1 * 0x18] = bVar1;
  (&DAT_004285f7)
  [(uint)(byte)(&DAT_00420ad9)[param_1 * 0x18] * 10 +
   (uint)(byte)(&DAT_00420ad8)[param_1 * 0x18] * 0x96] = param_1;
  return;
}


// ==== FUN_0040c459 @ 0040c459

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040c459(void)

{
  short sVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  undefined4 uVar7;
  byte bVar8;
  int local_1c;
  int local_14;
  short local_c;
  
  bVar5 = DAT_00420ad9;
  bVar4 = DAT_00420ad8;
  bVar8 = (&DAT_004294b9)[(uint)DAT_00420ad9 * 4 + (uint)DAT_00420ad8 * 0x3c] & 0xf;
  bVar2 = (byte)(&DAT_004294b9)[(uint)DAT_00420ad9 * 4 + (uint)DAT_00420ad8 * 0x3c] >> 4;
  if ((&DAT_004285f7)[(uint)bVar2 * 10 + (uint)bVar8 * 0x96] == -1) {
    if (((&DAT_004285f4)[(uint)bVar2 * 10 + (uint)bVar8 * 0x96] == '\0') ||
       (0x27 < (byte)(&DAT_004285f4)[(uint)bVar2 * 10 + (uint)bVar8 * 0x96])) {
      FUN_0040935d('\0');
      FUN_0040c2bd('\0');
      if (*(short *)(&DAT_004285f2 + (uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96) != 0) {
        local_c = 0;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          for (local_1c = 0; local_1c < 0xf; local_1c = local_1c + 1) {
            sVar1 = *(short *)(&DAT_004285f2 + local_1c * 10 + local_14 * 0x96);
            if (*(short *)(&DAT_004285f2 + local_1c * 10 + local_14 * 0x96) <= local_c) {
              sVar1 = local_c;
            }
            local_c = sVar1;
          }
        }
        if ((1 < *(short *)(&DAT_004285f2 + (uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96)) ||
           (*(short *)(&DAT_004285f2 + (uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96) ==
            local_c)) {
          cVar6 = FUN_0040718f(DAT_00420ad8,DAT_00420ad9,0);
          _DAT_00420ae8 = _DAT_00420ae8 + cVar6;
          sVar1 = *(short *)(&DAT_004285f2 + (uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96);
          if (sVar1 == 9) {
            bVar3 = false;
            for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
              for (local_1c = 0; local_1c < 0xf; local_1c = local_1c + 1) {
                if ((&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] == '\x10') {
                  (&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] = 0;
                  FUN_00407d75((char)local_14,(char)local_1c,
                               *(ushort *)(&DAT_004291d0 + local_1c * 2 + local_14 * 0x1e));
                  bVar3 = true;
                  break;
                }
                if (bVar3) break;
              }
            }
          }
          else if (sVar1 == 10) {
            bVar3 = false;
            for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
              for (local_1c = 0; local_1c < 0xf; local_1c = local_1c + 1) {
                if ((&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] == '\x0f') {
                  (&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] = 0;
                  FUN_00407d75((char)local_14,(char)local_1c,
                               *(ushort *)(&DAT_004291d0 + local_1c * 2 + local_14 * 0x1e));
                  bVar3 = true;
                  break;
                }
                if (bVar3) break;
              }
            }
          }
          else if (sVar1 == 0xc) {
            bVar3 = false;
            for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
              for (local_1c = 0; local_1c < 0xf; local_1c = local_1c + 1) {
                if ((&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] == '\x0e') {
                  (&DAT_004285f4)[local_1c * 10 + local_14 * 0x96] = 0;
                  FUN_00407d75((char)local_14,(char)local_1c,
                               *(ushort *)(&DAT_004291d0 + local_1c * 2 + local_14 * 0x1e));
                  bVar3 = true;
                  break;
                }
                if (bVar3) break;
              }
            }
          }
          *(undefined2 *)(&DAT_004285f2 + (uint)DAT_00420ad9 * 10 + (uint)DAT_00420ad8 * 0x96) = 0;
        }
      }
      FUN_00408e9d(bVar4,bVar5);
      FUN_004092cb('\0');
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


// ==== FUN_0040c99b @ 0040c99b

void FUN_0040c99b(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined3 extraout_var_01;
  byte local_10;
  byte local_c;
  char local_8 [4];
  
  bVar1 = FUN_004093e4();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_0040f923(0x17);
  }
  DAT_004293b4 = DAT_004293b4 + -1;
  if (DAT_004293b4 < 1) {
    DAT_004293b4 = DAT_00420ac4;
    bVar1 = FUN_004094da();
    if (CONCAT31(extraout_var_00,bVar1) == 1) {
      if ((&DAT_004294ba)[(uint)DAT_00420ad9 * 4 + (uint)DAT_00420ad8 * 0x3c] == '\0') {
        iVar2 = FUN_0040c071();
        if (iVar2 == 1) {
          FUN_0040b758(DAT_00420ad8,DAT_00420ad9,DAT_00429718,DAT_0042971c);
          FUN_0040b804(DAT_00420ad8,DAT_00420ad9,DAT_00429718,DAT_0042971c);
          iVar2 = FUN_0040c459();
          if (iVar2 == 0) {
            (&DAT_004294ba)[(uint)DAT_00420ad9 * 4 + (uint)DAT_00420ad8 * 0x3c] = 0;
          }
        }
        else {
          for (local_c = 0; local_c < 10; local_c = local_c + 1) {
            for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
              (&DAT_004294ba)[(uint)local_10 * 4 + (uint)local_c * 0x3c] = 0;
            }
          }
          iVar2 = FUN_0040690f(4);
          local_8[0] = (char)iVar2;
          iVar2 = FUN_0040690f(4);
          local_8[1] = (char)iVar2;
          while (local_8[1] == local_8[0]) {
            iVar2 = FUN_0040690f(4);
            local_8[1] = (char)iVar2;
          }
          iVar2 = FUN_0040690f(4);
          local_8[2] = (char)iVar2;
          while ((local_8[2] == local_8[0] || (local_8[2] == local_8[1]))) {
            iVar2 = FUN_0040690f(4);
            local_8[2] = (char)iVar2;
          }
          iVar2 = FUN_0040690f(4);
          local_8[3] = (char)iVar2;
          while (((local_8[3] == local_8[0] || (local_8[3] == local_8[1])) ||
                 (local_8[3] == local_8[2]))) {
            iVar2 = FUN_0040690f(4);
            local_8[3] = (char)iVar2;
          }
          for (local_c = 0; local_c < 4; local_c = local_c + 1) {
            bVar1 = FUN_0040b932(DAT_00420ad8,DAT_00420ad9,(char)*(undefined4 *)(local_8 + local_c),
                                 1);
            if (CONCAT31(extraout_var_01,bVar1) == 1) {
              FUN_004095c5('\0',(char)*(undefined4 *)(local_8 + local_c));
              break;
            }
          }
        }
      }
      else {
        iVar2 = FUN_0040c459();
        if (iVar2 == 0) {
          (&DAT_004294ba)[(uint)DAT_00420ad9 * 4 + (uint)DAT_00420ad8 * 0x3c] = 0;
        }
      }
      FUN_00406d5e();
    }
    else {
      PostMessageA(DAT_00429778,0x111,0x22c,0);
    }
  }
  return;
}


// ==== FUN_0040cc76 @ 0040cc76

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040cc76(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00420f74;
  iVar2 = _DAT_0042047c;
  iVar1 = _DAT_00420478;
  FUN_00404674();
  if ((iVar3 != DAT_00420f74) && (DAT_00420aa0 == 0)) {
    if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
      iVar3 = FUN_0040690f(4);
      FUN_0040f625(iVar3 + 2);
    }
    else {
      FUN_0040f625(1);
    }
  }
  if ((iVar2 != _DAT_0042047c) || (iVar1 != _DAT_00420478)) {
    SendMessageA(DAT_00429778,0x111,0x65,1);
  }
  FUN_004036e9();
  return;
}


// ==== FUN_0040cd36 @ 0040cd36

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_0040cd36(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  int cy;
  uint uVar1;
  LPCSTR pCVar2;
  INT_PTR IVar3;
  int iVar4;
  HDC pHVar5;
  HDC pHVar6;
  HGDIOBJ pvVar7;
  UINT UVar8;
  DWORD local_84;
  BYTE *local_80;
  tagPAINTSTRUCT local_68;
  UINT local_20;
  int local_18 [5];
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      if (DAT_00420ab4 != 0) {
        BeginPaint(param_1,&local_68);
        EndPaint(param_1,&local_68);
        return 0;
      }
      pHVar5 = BeginPaint(param_1,&local_68);
      SelectPalette(pHVar5,DAT_0042a62c,0);
      RealizePalette(pHVar5);
      cy = DAT_0042a620;
      iVar4 = DAT_0042a61c;
      if (DAT_00420ab0 == 0) {
        if (DAT_00420aa8 == 0) {
          if ((((DAT_00420aa0 == 0) && ((DAT_00420aa4 == 0 || (DAT_00420aac != 0)))) &&
              ((DAT_00428be4 != (HWND)0x0 || (DAT_00420aac != 0)))) &&
             ((DAT_00420a98 == 0 || (DAT_00420aac != 0)))) {
            DAT_0042ab9c = 0;
            pHVar6 = CreateCompatibleDC(pHVar5);
            pvVar7 = SelectObject(pHVar6,DAT_0042abc0);
            BitBlt(pHVar5,0,0,iVar4,cy,pHVar6,0,0,0xcc0020);
            SelectObject(pHVar6,pvVar7);
            DeleteDC(pHVar6);
            GdiFlush();
          }
          else {
            local_18[1] = 0;
            local_18[3] = 0x21c;
            local_18[2] = 0;
            local_18[4] = 0x27;
            pHVar6 = CreateCompatibleDC(pHVar5);
            pvVar7 = SelectObject(pHVar6,DAT_0042abc0);
            BitBlt(pHVar5,0,0,0x21d,0x28,pHVar6,0,0,0xcc0020);
            SelectObject(pHVar6,pvVar7);
            DeleteDC(pHVar6);
            GdiFlush();
            FUN_0040edfa(pHVar5,DAT_00429394,0,0x28);
          }
        }
        else {
          local_18[1] = 0;
          local_18[3] = 0x21c;
          local_18[2] = 0;
          local_18[4] = 0x27;
          pHVar6 = CreateCompatibleDC(pHVar5);
          pvVar7 = SelectObject(pHVar6,DAT_0042abc0);
          BitBlt(pHVar5,0,0,0x21d,0x28,pHVar6,0,0,0xcc0020);
          SelectObject(pHVar6,pvVar7);
          DeleteDC(pHVar6);
          GdiFlush();
          FUN_0040edfa(pHVar5,DAT_00429720,0,0x28);
        }
      }
      else {
        if ((DAT_004292fc->bmiHeader).biCompression == 3) {
          local_80 = (BYTE *)((int)(DAT_004292fc->bmiColors + -7) + (DAT_004292fc->bmiHeader).biSize
                             );
        }
        else {
          if (((DAT_004292fc->bmiHeader).biClrUsed == 0) &&
             ((DAT_004292fc->bmiHeader).biBitCount < 9)) {
            local_84 = 1 << ((byte)(DAT_004292fc->bmiHeader).biBitCount & 0x1f);
          }
          else {
            local_84 = (DAT_004292fc->bmiHeader).biClrUsed;
          }
          local_80 = &DAT_004292fc->bmiColors[local_84 - 10].rgbBlue +
                     (DAT_004292fc->bmiHeader).biSize;
        }
        StretchDIBits(pHVar5,0,0,0x21c,400,0,0,0x21c,400,local_80,DAT_004292fc,0,0xcc0020);
      }
      EndPaint(param_1,&local_68);
      return 0;
    }
    if (param_2 == 1) {
      FUN_00403fe4(param_1);
      return 0;
    }
    if (param_2 == 2) {
      if (DAT_004292fc != (BITMAPINFO *)0x0) {
        GlobalFree(DAT_004292fc);
      }
      if (DAT_00428bd8 != (HGLOBAL)0x0) {
        GlobalFree(DAT_00428bd8);
      }
      WinHelpA(DAT_00429398,s_jewelch_hlp_00420798,2,0);
      FUN_00404027(param_1);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_00428be4 = param_3;
      if (param_3 == (HWND)0x0) {
        FUN_004036e9();
        if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
          DAT_00420aa0 = 1;
        }
        FUN_0040694b();
      }
      else {
        FUN_00403278();
      }
      if ((param_3 == (HWND)0x0) || (DAT_00420aa0 != 0)) {
        FUN_0040f625(0);
      }
      else if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
        iVar4 = FUN_0040690f(4);
        FUN_0040f625(iVar4 + 2);
      }
      else {
        FUN_0040f625(1);
      }
      DAT_00420aa4 = 0;
      InvalidateRect(DAT_00429398,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x10) {
      if (DAT_00420ab4 != 0) {
        return 0;
      }
      if (DAT_00420ab0 == 0) {
        if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
          IVar3 = FUN_004042e0();
          if (IVar3 != 1) {
            return 0;
          }
          iVar4 = FUN_00403508(DAT_00420abc,local_18);
          if (((iVar4 != 0) && (local_18[0] < 10)) && (1 < DAT_00420ac0)) {
            if (DAT_0042048c != 0) {
              FUN_00404596();
            }
            FUN_004035a5(DAT_00420abc);
            DAT_00420c28 = local_18[0];
            FUN_00404605();
            FUN_004036e9();
          }
        }
        FUN_00406d4e();
        FUN_004036e9();
        FUN_0040fa3d();
        FUN_00418d58();
        DestroyWindow(param_1);
        return 0;
      }
      DAT_0042038c = 1;
      DAT_00420ab8 = 1;
      FUN_00418d58();
      FUN_0040fa3d();
      DestroyWindow(param_1);
      return 0;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(400);
      GdiFlush();
      Sleep(400);
      GdiFlush();
      DeleteObject(DAT_00429394);
      DeleteObject(DAT_00429720);
      pHVar5 = GetDC((HWND)0x0);
      DAT_00429394 = FUN_0040ee90(pHVar5,s_PAUSEBMP_00420ea0);
      DAT_00429720 = FUN_0040ee90(pHVar5,s_GAMEOVERBMP_00420eac);
      ReleaseDC((HWND)0x0,pHVar5);
      Sleep(100);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00429300;
      *(undefined4 *)(param_4 + 0xc) = DAT_00429360;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_00429778,6);
        return 0;
      }
      if (DAT_00420ab4 != 0) {
        return 0;
      }
      if (DAT_00420ab0 != 0) {
        DAT_0042038c = 1;
        return 0;
      }
      if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
        if (DAT_00420aa0 == 0) {
          if (param_3 == (HWND)0x25) {
            FUN_004095c5('\x01',3);
          }
          else if (param_3 == (HWND)0x26) {
            FUN_004095c5('\x01',0);
          }
          else if (param_3 == (HWND)0x27) {
            FUN_004095c5('\x01',1);
          }
          else if (param_3 == (HWND)0x28) {
            FUN_004095c5('\x01',2);
          }
          FUN_00406d5e();
          return 0;
        }
        PostMessageA(DAT_00429778,0x111,0xc9,0);
        return 0;
      }
      PostMessageA(DAT_00429778,0x111,0x65,0);
      return 0;
    }
    if (param_2 == 0x86) {
      if (param_3 != (HWND)0x0) {
        InvalidateRect(DAT_00429778,(RECT *)0x0,0);
      }
      UVar8 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
      return UVar8;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if (DAT_00420ab4 != 0) {
        return 0;
      }
      if (DAT_00420ab0 == 0) {
        if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
          if (DAT_00420aa0 == 0) {
            return 0;
          }
          PostMessageA(DAT_00429778,0x111,0xc9,0);
          return 0;
        }
        PostMessageA(DAT_00429778,0x111,0x65,0);
        return 0;
      }
      DAT_0042038c = 1;
      return 0;
    }
    if (param_2 == 0x111) {
      if (DAT_00420ab4 != 0) {
        return 0;
      }
      uVar1 = (uint)param_3 & 0xffff;
      if (uVar1 < 0xca) {
        if (uVar1 == 0xc9) {
          if (DAT_00420ab0 != 0) {
            DAT_0042038c = 1;
            return 0;
          }
          if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
            DAT_00420aa0 = (uint)(DAT_00420aa0 == 0);
            FUN_0040694b();
            if (DAT_00420aa0 == 0) {
              iVar4 = FUN_0040690f(4);
              FUN_0040f548(iVar4 + 2);
            }
            else {
              InvalidateRect(DAT_00429398,(RECT *)0x0,0);
              UpdateWindow(DAT_00429398);
              FUN_0040f4d5();
            }
            InvalidateRect(DAT_00429398,(RECT *)0x0,0);
            return 0;
          }
          SendMessageA(DAT_00429778,0x111,0x65,0);
          return 0;
        }
        switch(uVar1) {
        case 0x65:
          if (DAT_00420ab0 != 0) {
            DAT_0042038c = 1;
            return 0;
          }
          if ((DAT_00420aac == 0) && (DAT_00420aa8 == 0)) {
            IVar3 = FUN_00404358();
            if (IVar3 != 1) {
              return 0;
            }
            iVar4 = FUN_00403508(DAT_00420abc,local_18);
            if (((iVar4 != 0) && (local_18[0] < 10)) && (1 < DAT_00420ac0)) {
              if (DAT_0042048c != 0) {
                FUN_00404596();
              }
              FUN_004035a5(DAT_00420abc);
              DAT_00420c28 = local_18[0];
              FUN_00404605();
              FUN_004036e9();
            }
          }
          iVar4 = FUN_0040690f(4);
          FUN_0040f625(iVar4 + 2);
          DAT_00420aac = 0;
          DAT_00420aa8 = 0;
          DAT_00420aa0 = 0;
          FUN_0040694b();
          DAT_00420474 = _DAT_00420478 + -1;
          if (((int)DAT_00420474 < 0) || (0x62 < (int)DAT_00420474)) {
            DAT_00420474 = 0;
          }
          DAT_00420b18 = 0;
          DAT_00420b00 = 0;
          _DAT_00420ae8 = 0;
          DAT_00420abc = 0;
          FUN_00406c42();
          DAT_00420ac0 = _DAT_0042047c;
          if (_DAT_0042047c == 1) {
            DAT_00420c2c = 0;
          }
          else {
            DAT_00420c2c = 2;
            DAT_00420ac4 = (undefined4)(100 / (longlong)(_DAT_0042047c + -1));
          }
          InvalidateRect(DAT_00429778,(RECT *)0x0,0);
          PostMessageA(DAT_00429778,0x111,0x22b,0);
          _memset(&DAT_00429378,0,0x10);
          if (DAT_00420480 != 0) {
            PostMessageA(DAT_00429778,0x111,0x130,0);
          }
          return 0;
        case 0x66:
          DAT_00420c28 = 0xffffffff;
          FUN_00404605();
          return 0;
        case 0x67:
          FUN_004036e9();
          PostMessageA(param_1,0x10,0,0);
          return 0;
        case 0x68:
          FUN_0040cc76();
          return 0;
        }
      }
      else if (uVar1 < 0x22c) {
        if (uVar1 == 0x22b) {
          DAT_00420c58 = 1;
          DAT_00420474 = DAT_00420474 + 1;
          if (DAT_004291c8 != (HGLOBAL)0x0) {
            GlobalFree(DAT_004291c8);
          }
          uVar1 = (int)DAT_00420474 >> 0x1f;
          pCVar2 = FUN_0040ec60((uint *)s_PATTERN_00420eb8,
                                ((DAT_00420474 ^ uVar1) - uVar1 & 1 ^ uVar1) - uVar1,3);
          DAT_004291c8 = FUN_0040f0ac(pCVar2);
          if ((int)DAT_00420474 < 100) {
            if (DAT_00420c2c == 0) {
              DAT_00420abc = 0;
            }
            FUN_00406c42();
            iVar4 = FUN_0040a07f();
            if (iVar4 != 0) {
              FUN_00406d5e();
              return 0;
            }
            MessageBeep(0);
            DAT_00420aa8 = 1;
            FUN_0040694b();
            InvalidateRect(DAT_00429778,(RECT *)0x0,0);
            return 0;
          }
          DAT_00420aa8 = 1;
          FUN_0040694b();
          InvalidateRect(DAT_00429778,(RECT *)0x0,0);
          FUN_004041b1(2);
          iVar4 = FUN_00403508(DAT_00420abc,local_18);
          if (((iVar4 != 0) && (local_18[0] < 10)) && (1 < DAT_00420ac0)) {
            if (DAT_0042048c != 0) {
              FUN_00404596();
            }
            FUN_004035a5(DAT_00420abc);
            DAT_00420c28 = local_18[0];
            FUN_00404605();
            FUN_004036e9();
          }
          return 0;
        }
        if (uVar1 == 0x12e) {
          FUN_00404405();
          return 0;
        }
        if (uVar1 == 0x12f) {
          WinHelpA(param_1,s_jewelch_hlp_00420798,0xb,0);
          return 0;
        }
        if (uVar1 == 0x130) {
          FUN_004044cc();
          return 0;
        }
      }
      else {
        if (uVar1 == 0x22c) {
          FUN_0040f923(0x15);
          DAT_00420aa8 = 1;
          FUN_0040f625(1);
          FUN_0040694b();
          InvalidateRect(DAT_00429778,(RECT *)0x0,0);
          iVar4 = FUN_00403508(DAT_00420abc,local_18);
          if (((iVar4 != 0) && (local_18[0] < 10)) && (1 < DAT_00420ac0)) {
            if (DAT_0042048c != 0) {
              FUN_00404596();
            }
            FUN_004035a5(DAT_00420abc);
            DAT_00420c28 = local_18[0];
            FUN_00404605();
            FUN_004036e9();
          }
          return 0;
        }
        if (uVar1 == 0x22d) {
          FUN_0040453b();
          return 0;
        }
      }
      return 0;
    }
    if (param_2 == 0x113) {
      if ((DAT_00420aa0 == 0) && (DAT_00428be4 != (HWND)0x0)) {
        FUN_0040f805();
      }
      return 0;
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_0040d5de:
      if (DAT_00420ab4 != 0) {
        return 0;
      }
      pHVar5 = GetDC(param_1);
      if (DAT_0042a62c != (HPALETTE)0x0) {
        SelectPalette(pHVar5,DAT_0042a62c,0);
        local_20 = RealizePalette(pHVar5);
      }
      ReleaseDC(param_1,pHVar5);
      if (local_20 != 0) {
        InvalidateRect(param_1,(RECT *)0x0,1);
        return local_20;
      }
      return 0;
    }
    if (param_2 == 0x211) {
      DAT_00420aa4 = 1;
      InvalidateRect(param_1,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x212) {
      DAT_00420aa4 = 0;
      InvalidateRect(param_1,(RECT *)0x0,0);
      return 0;
    }
  }
  else {
    if (param_2 == 0x311) {
      if (param_3 == param_1) {
        return 0;
      }
      goto LAB_0040d5de;
    }
    if (param_2 == 0x42b) {
      if ((((DAT_00420aa0 == 0) && (DAT_00420aac == 0)) && (DAT_00420aa8 == 0)) &&
         ((DAT_00420a98 == 0 && (DAT_00420a9c == 0)))) {
        FUN_0040a90d();
        FUN_0040a80e();
        FUN_0040a88a();
        FUN_00406d5e();
        if (1 < DAT_00420c2c) {
          FUN_0040c99b();
        }
        return 0;
      }
      return 0;
    }
  }
  UVar8 = FUN_00418da0(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar8;
}


// ==== FUN_0040e058 @ 0040e058

int __cdecl FUN_0040e058(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0040e079 @ 0040e079

int __cdecl FUN_0040e079(int param_1)

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


// ==== FUN_0040e0b4 @ 0040e0b4

ATOM __cdecl FUN_0040e0b4(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 8;
  local_2c.lpfnWndProc = FUN_0040cd36;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = param_1;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(5);
  local_2c.hIcon = LoadIconA(param_1,s_MAINICON_00420ec0);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = PTR_s_JewelChaseWnd_00420790;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1;
}


// ==== FUN_0040e132 @ 0040e132

/* WARNING: Removing unreachable block (ram,0x0040e2b5) */
/* WARNING: Removing unreachable block (ram,0x0040e2a8) */
/* WARNING: Removing unreachable block (ram,0x0040e2ba) */
/* WARNING: Removing unreachable block (ram,0x0040e2c7) */
/* WARNING: Removing unreachable block (ram,0x0040e2d3) */
/* WARNING: Removing unreachable block (ram,0x0040e1e4) */
/* WARNING: Removing unreachable block (ram,0x0040e1aa) */
/* WARNING: Removing unreachable block (ram,0x0040e19d) */
/* WARNING: Removing unreachable block (ram,0x0040e1af) */
/* WARNING: Removing unreachable block (ram,0x0040e1c8) */
/* WARNING: Removing unreachable block (ram,0x0040e1bc) */
/* WARNING: Removing unreachable block (ram,0x0040e16b) */
/* WARNING: Removing unreachable block (ram,0x0040e2ef) */
/* WARNING: Removing unreachable block (ram,0x0040e276) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040e132(void)

{
  DAT_004293d4 = 1000;
  DAT_004293d8 = 2;
  DAT_004293dc = 0;
  if ((DAT_004293b8 == (LPVOID)0x0) &&
     (DAT_004293b8 = FUN_0040f16d((LPCSTR)0x3e8), DAT_004293b8 != (LPVOID)0x0)) {
    DAT_004293bc = 1;
  }
  DAT_00429324 = 0x3e9;
  DAT_00429328 = 2;
  DAT_0042932c = 0;
  if ((DAT_00429308 == (LPVOID)0x0) &&
     (DAT_00429308 = FUN_0040f16d((LPCSTR)0x3e9), DAT_00429308 != (LPVOID)0x0)) {
    DAT_0042930c = 1;
  }
  DAT_00428bd0 = operator_new(0x883);
  _DAT_00429368 = 8;
  return;
}


// ==== FUN_0040e376 @ 0040e376

undefined4 FUN_0040e376(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_JewelChaseWnd_00420790,(LPCSTR)0x0);
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


// ==== FUN_0040e3f3 @ 0040e3f3

bool __cdecl FUN_0040e3f3(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040e449 @ 0040e449

WPARAM FUN_0040e449(HINSTANCE param_1)

{
  bool bVar1;
  ATOM AVar2;
  int iVar3;
  DWORD DVar4;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  LPCSTR pCVar5;
  HGLOBAL pvVar6;
  BOOL BVar7;
  int local_40;
  int local_3c;
  tagMSG local_38;
  HDC local_1c;
  int local_14;
  HDC local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  DAT_004293b0 = param_1;
  iVar3 = FUN_0040e376();
  if (iVar3 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_JewelChGameMtx_00420ecc);
    DVar4 = GetLastError();
    if (DVar4 == 0xb7) {
      local_38.wParam = 0;
    }
    else {
      bVar1 = FUN_0040e3f3(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_38.wParam = 0;
      }
      else {
        local_10 = GetDC((HWND)0x0);
        iVar3 = GetDeviceCaps(local_10,0xc);
        if (iVar3 < 8) {
          ReleaseDC((HWND)0x0,local_10);
          local_38.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_10);
          FUN_0040184d();
          FUN_004018e7((uint *)s_jewelch_dll_00420898);
          FUN_00401a95((uint *)s_jewelch1_dll_00420998);
          FUN_00401865((uint *)s_MSPuzzle_dat_004204c0);
          FUN_00401a95((uint *)s_jewelch_hlp_00420798);
          FUN_0040167a();
          FUN_00401694(DAT_004293b0);
          FUN_004016d3(s_jewelch1_dll_00420998);
          FUN_004016d3(s_jewelch_dll_00420898);
          FUN_00403278();
          FUN_0040fc54();
          AVar2 = FUN_0040e0b4(param_1);
          if (CONCAT22(extraout_var_00,AVar2) == 0) {
            local_38.wParam = 0;
          }
          else {
            DAT_004292fc = FUN_0040f0ac(s_TITLEBMP_00420edc);
            if (DAT_004292fc == (int *)0x0) {
              local_38.wParam = 0;
            }
            else {
              DAT_00428bd8 = FUN_0040f0ac(s_LEVSCORE_00420ee8);
              for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
                pCVar5 = FUN_0040ec60((uint *)s_DIGIT_00420ef4,local_14,1);
                pvVar6 = FUN_0040f0ac(pCVar5);
                *(HGLOBAL *)(&DAT_00427998 + local_14 * 4) = pvVar6;
              }
              DAT_004291c8 = FUN_0040f0ac(s_PATTERN001_00420efc);
              if (DAT_004292fc == (int *)0x0) {
                FUN_00406d4e();
                local_38.wParam = 0;
              }
              else {
                FUN_00418be0(DAT_004292fc);
                iVar3 = FUN_0040e8b0(param_1);
                if (iVar3 == 0) {
                  FUN_00406d4e();
                  FUN_00418d58();
                  local_38.wParam = 0;
                }
                else {
                  local_1c = GetDC((HWND)0x0);
                  DAT_00429394 = FUN_0040ee90(local_1c,s_PAUSEBMP_00420f08);
                  DAT_00429720 = FUN_0040ee90(local_1c,s_GAMEOVERBMP_00420f14);
                  ReleaseDC((HWND)0x0,local_1c);
                  if ((DAT_00428bd4 == (HACCEL)0x0) || (DAT_00429394 == (HBITMAP)0x0)) {
                    FUN_0040fa3d();
                    local_38.wParam = 0;
                  }
                  else {
                    FUN_0040e132();
                    DAT_0042abb4 = 0x21c;
                    InitCommonControls();
                    FUN_0040694b();
                    SetTimer(DAT_00429778,1,100,(TIMERPROC)0x0);
                    if (DAT_004292fc[4] == 3) {
                      local_3c = *DAT_004292fc + 0xc;
                    }
                    else {
                      if ((DAT_004292fc[8] == 0) && (*(ushort *)((int)DAT_004292fc + 0xe) < 9)) {
                        local_40 = 1 << (*(byte *)((int)DAT_004292fc + 0xe) & 0x1f);
                      }
                      else {
                        local_40 = DAT_004292fc[8];
                      }
                      local_3c = local_40 * 4 + *DAT_004292fc;
                    }
                    local_3c = (int)DAT_004292fc + local_3c;
                    FUN_00402fac(s_PROMPT_00420f20,local_3c);
                    DAT_00420ab0 = 0;
                    if (DAT_00420ab8 == 0) {
                      PostMessageA(DAT_00429778,0x111,0x65,0);
                      while( true ) {
                        while (BVar7 = PeekMessageA(&local_38,(HWND)0x0,0,0,1), BVar7 == 0) {
                          if (DAT_00428be4 == 0) {
                            WaitMessage();
                          }
                          else {
                            SendMessageA(DAT_00429398,0x42b,0,0);
                            Sleep(10);
                          }
                        }
                        if (local_38.message == 0x12) break;
                        if ((DAT_00429398 == (HWND)0x0) ||
                           (iVar3 = TranslateAcceleratorA(DAT_00429398,DAT_00428bd4,&local_38),
                           iVar3 == 0)) {
                          TranslateMessage(&local_38);
                          DispatchMessageA(&local_38);
                        }
                      }
                    }
                    else {
                      DAT_00420ab4 = 1;
                      local_38.wParam = 0;
                    }
                    FUN_0040fa3d();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_38.wParam = 0;
  }
  return local_38.wParam;
}


// ==== FUN_0040e8b0 @ 0040e8b0

undefined4 __cdecl FUN_0040e8b0(undefined4 param_1)

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
  
  DAT_004285d8 = FUN_0040154e(DAT_004293b0,s_MainMenuPlayed_00420f28);
  DAT_0042972c = FUN_0040154e(DAT_004293b0,s_MainMenu_00420f38);
  DAT_00428bd4 = FUN_0040148b(param_1,s_ACCELERATORS_1_00420f44);
  if (DAT_00428bd4 == (HACCEL)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_004015b0(DAT_004293b0,100,local_84,0x78);
    DVar2 = GetVersion();
    local_88 = (byte)DVar2;
    if (local_88 < 4) {
      iVar3 = GetSystemMetrics(5);
      DAT_00429300 = iVar3 * 2 + 0x21c;
      iVar3 = GetSystemMetrics(6);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_00429360 = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00429300;
      iVar4 = DAT_00429360;
      pHVar8 = DAT_0042972c;
      pHVar9 = DAT_004293b0;
      iVar5 = FUN_0040e079(DAT_00429360);
      iVar6 = FUN_0040e058(DAT_00429300);
      DAT_00429398 = CreateWindowExA(0,PTR_s_JewelChaseWnd_00420790,local_84,0xca0000,iVar6,iVar5,
                                     iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    else {
      iVar3 = GetSystemMetrics(7);
      DAT_00429300 = iVar3 * 2 + 0x21c;
      iVar3 = GetSystemMetrics(8);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_00429360 = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00429300;
      iVar4 = DAT_00429360;
      pHVar8 = DAT_0042972c;
      pHVar9 = DAT_004293b0;
      iVar5 = FUN_0040e079(DAT_00429360);
      iVar6 = FUN_0040e058(DAT_00429300);
      DAT_00429398 = CreateWindowExA(0x100,PTR_s_JewelChaseWnd_00420790,local_84,0xca0000,iVar6,
                                     iVar5,iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    DAT_00429778 = DAT_00429398;
    if (DAT_00429398 == (HWND)0x0) {
      uVar1 = 0;
    }
    else {
      ShowWindow(DAT_00429398,5);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0040eac0 @ 0040eac0

void __fastcall FUN_0040eac0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_0041b6d0((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_0040eb30 @ 0040eb30

void __fastcall FUN_0040eb30(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_0041b6d0((void *)*param_1);
  }
  *param_1 = 0;
  return;
}


// ==== FUN_0040eb90 @ 0040eb90

void __fastcall FUN_0040eb90(int *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040ec42;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  if ((*param_1 != 0) && (param_1[1] == 0)) {
    FUN_0041b6d0((void *)*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  local_8 = 0xffffffff;
  FUN_0040ec39();
  FUN_0040ec4c();
  return;
}


// ==== FUN_0040ec39 @ 0040ec39

void FUN_0040ec39(void)

{
  int unaff_EBP;
  
  FUN_0040eb30(*(int **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0040ec4c @ 0040ec4c

void FUN_0040ec4c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040ec60 @ 0040ec60

undefined * __cdecl FUN_0040ec60(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0041afd0((uint *)&DAT_00429b88,param_1);
  sVar1 = _strlen(&DAT_00429b88);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_00429b87)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_00429b88)[param_3 + sVar1] = 0;
  return &DAT_00429b88;
}


// ==== FUN_0040ed29 @ 0040ed29

void __cdecl FUN_0040ed29(int param_1)

{
  if (param_1 == 0) {
    DAT_00429730 = GetDC(DAT_00429778);
  }
  else {
    DAT_00429730 = BeginPaint(DAT_00429778,(LPPAINTSTRUCT)&DAT_00429738);
  }
  return;
}


// ==== FUN_0040ed6f @ 0040ed6f

void __cdecl FUN_0040ed6f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_00429778,DAT_00429730);
  }
  else {
    EndPaint(DAT_00429778,(PAINTSTRUCT *)&DAT_00429738);
  }
  return;
}


// ==== FUN_0040edb1 @ 0040edb1

bool __cdecl FUN_0040edb1(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_0040edfa @ 0040edfa

bool __cdecl FUN_0040edfa(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_0040ee90 @ 0040ee90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_0040ee90(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_00401078(DAT_004293b0,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_00420f58 = 0;
        _DAT_00429780 = 0x300;
        _DAT_00429782 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_00429784)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_00429785)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_00429786)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_00429787)[local_28 * 4] = 0;
        }
        if (DAT_00420f54 == (HPALETTE)0x0) {
          DAT_00420f54 = CreatePalette((LOGPALETTE *)&DAT_00429780);
        }
      }
      hPal = SelectPalette(param_1,DAT_0042a62c,0);
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


// ==== FUN_0040f0ac @ 0040f0ac

HGLOBAL __cdecl FUN_0040f0ac(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_00401078(DAT_004293b0,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_0040f16d @ 0040f16d

LPVOID __cdecl FUN_0040f16d(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_004293b0,param_1,s_SPRITE_00420f5c,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_0040f1bf @ 0040f1bf

LPVOID __cdecl FUN_0040f1bf(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_004293b0,param_1,s_SPRFONT_00420f64,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_0040f211 @ 0040f211

undefined2 * __cdecl FUN_0040f211(LPCSTR param_1)

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
  
  hResData = FUN_00401078(DAT_004293b0,param_1,(LPCSTR)0x2,&local_10);
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


// ==== FUN_0040f400 @ 0040f400

undefined4 FUN_0040f400(void)

{
  return 1;
}


// ==== FUN_0040f418 @ 0040f418

void FUN_0040f418(void)

{
  return;
}


// ==== FUN_0040f430 @ 0040f430

void FUN_0040f430(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00429c0c == 1) || (DAT_00429c0c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00421108,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00421108,0x804,2,(DWORD_PTR)local_c);
    DAT_00421108 = 0;
    Sleep(1);
    DAT_00429c0c = 0;
  }
  return;
}


// ==== FUN_0040f4d5 @ 0040f4d5

void FUN_0040f4d5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00420f74 != 0) && (DAT_00429c0c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00421108,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_00429c0c = 3;
  }
  return;
}


// ==== FUN_0040f548 @ 0040f548

void __cdecl FUN_0040f548(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00420f74 != 0) {
    if (DAT_00429c0c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_00421108,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_00421108,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_0040f625(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_00429c0c = 1;
    }
    else {
      FUN_0040f625(param_1);
    }
  }
  return;
}


// ==== FUN_0040f625 @ 0040f625

void __cdecl FUN_0040f625(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00420f74 == 0) {
    FUN_0040f430();
  }
  else {
    if (((DAT_00429c08 == param_1) && (0 < param_1)) && (DAT_00429c0c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_00421108,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_00429c0c != 4) {
      FUN_0040f430();
    }
    if (DAT_00420f74 != 0) {
      if (0 < param_1) {
        DAT_00429c08 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00429c08;
      }
      if ((0 < param_1) && (param_1 < 6)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00429c10 + param_1 * 0x100;
        local_20 = s_sequencer_0042110c;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_00421108 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_00421108;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_00421108 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00421108,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_00429c0c = 1;
          }
          else {
            DAT_00429c0c = 4;
          }
        }
        else {
          DAT_00429c0c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_0040f805 @ 0040f805

void FUN_0040f805(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00420f74 != 0) {
    if (DAT_00429c0c == 1) {
      if (DAT_00421108 == 0) {
        DAT_00429c0c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_00421108,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00421108,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_00429c0c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_00429c0c = 4;
        }
      }
    }
    else if (DAT_00429c0c == 4) {
      FUN_0040f625(-1);
    }
  }
  return;
}


// ==== FUN_0040f923 @ 0040f923

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f923(int param_1)

{
  DWORD DVar1;
  
  if (DAT_00420f70 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00420f78) {
      DAT_00420f78 = DVar1;
    }
    if (DVar1 - _DAT_00420f7c < DAT_00420f78) {
      if (DAT_00420f80 <= *(int *)(&DAT_0042a21c + param_1 * 0x10)) {
        return;
      }
      Sleep(1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00420f78 = GetTickCount();
    _DAT_00420f7c = *(int *)(&DAT_0042a218 + param_1 * 0x10);
    DAT_00420f80 = *(int *)(&DAT_0042a21c + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_0042a210 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_0040fa3d @ 0040fa3d

void FUN_0040fa3d(void)

{
  int local_c;
  int local_8;
  
  FUN_0040f430();
  FUN_0040f923(0);
  for (local_8 = 0xb; local_8 < 0x18; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042a214 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042a214 + local_8 * 0x10));
      *(undefined4 *)(&DAT_0042a214 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_0042a210 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    DeleteFileA(&DAT_00429c10 + local_c * 0x100);
  }
  return;
}


// ==== FUN_0040fb25 @ 0040fb25

void __cdecl FUN_0040fb25(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00401000(DAT_004293b0,param_2,&DAT_00421118);
  param_1[1] = (int)pvVar2;
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


// ==== FUN_0040fc54 @ 0040fc54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040fc54(void)

{
  LPCSTR local_8;
  
  _DAT_0042a210 = 0;
  _DAT_0042a214 = 0;
  for (local_8 = (LPCSTR)0xb; (int)local_8 < 0x18; local_8 = local_8 + 1) {
    FUN_0040fb25((int *)(&DAT_0042a210 + (int)local_8 * 0x10),local_8);
    *(undefined4 *)(&DAT_0042a21c + (int)local_8 * 0x10) = 10;
  }
  _DAT_0042a36c = 1;
  _DAT_0042a35c = 2;
  _DAT_0042a33c = 4;
  _DAT_0042a32c = 5;
  _DAT_0042a31c = 6;
  _DAT_0042a38c = 3;
  for (local_8 = (LPCSTR)0x1; (int)local_8 < 6; local_8 = (LPCSTR)((int)local_8 + 1)) {
    GetTempPathA(200,&DAT_00429c10 + (int)local_8 * 0x100);
    FUN_0041afe0((uint *)(&DAT_00429c10 + (int)local_8 * 0x100),
                 (uint *)(&DAT_00420f88 + (int)local_8 * 0x20));
    FUN_00401223(&DAT_00421048 + (int)local_8 * 0x20,&DAT_00421120,
                 &DAT_00429c10 + (int)local_8 * 0x100);
  }
  return;
}


// ==== FUN_0040fdaa @ 0040fdaa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040fdaa(void)

{
  DAT_0042a610 = 0;
  _DAT_0042a614 = 0;
  DAT_0042a618 = 0;
  DAT_0042a61c = 0;
  DAT_0042a620 = 0;
  DAT_0042a62c = 0;
  DAT_0042a628 = 1;
  _DAT_0042aa58 = 0;
  DAT_0042ab9c = 0;
  _DAT_0042aba4 = 64000;
  _DAT_0042aba0 = 1;
  DAT_0042abb4 = 0;
  DAT_0042abb8 = 0;
  return;
}


// ==== FUN_0040fe4b @ 0040fe4b

void FUN_0040fe4b(void)

{
  _atexit(FUN_0040fe68);
  return;
}


// ==== FUN_0040fe68 @ 0040fe68

void FUN_0040fe68(void)

{
  FUN_004100f7(&DAT_0042a610);
  return;
}


// ==== FUN_0040fe82 @ 0040fe82

undefined4 __thiscall FUN_0040fe82(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  HDC pHVar3;
  HBITMAP pHVar4;
  HGDIOBJ pvVar5;
  void *local_8;
  
  if (*(int *)this != 0) {
    FUN_004101d0(this);
  }
  if (*param_1 == 0x5452494d) {
    if ((short)param_1[1] == 0x5247) {
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
    if (*(short *)((int)param_1 + 6) != 2) {
      return 0;
    }
    param_1 = param_1 + 2;
  }
  FUN_00419090();
  uVar2 = FUN_00419164((int)this + 0x48,param_1);
  *(undefined4 *)((int)this + 0x1c) = uVar2;
  *(undefined4 *)((int)this + 0x20) = 0x28;
  *(undefined2 *)((int)this + 0x2c) = 1;
  *(undefined2 *)((int)this + 0x2e) = 8;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(int *)((int)this + 0x24) = param_1[1];
  *(undefined4 *)((int)this + 0x18) = 1;
  *(int *)((int)this + 0x28) = param_1[2] * *(int *)((int)this + 0x18);
  pHVar3 = GetDC((HWND)0x0);
  *(HDC *)this = pHVar3;
  pHVar4 = CreateDIBSection(*(HDC *)this,(BITMAPINFO *)((int)this + 0x20),0,&local_8,(HANDLE)0x0,0);
  *(HBITMAP *)((int)this + 4) = pHVar4;
  DAT_0042abc0 = *(undefined4 *)((int)this + 4);
  *(void **)((int)this + 8) = local_8;
  pvVar5 = SelectObject(*(HDC *)this,*(HGDIOBJ *)((int)this + 4));
  *(HGDIOBJ *)((int)this + 0x448) = pvVar5;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 0x24);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 0x28);
  *(uint *)((int)this + 0x14) =
       ((uint)*(ushort *)((int)this + 0x2e) * *(int *)((int)this + 0x24) + 0x1f & 0xffffffe0) >> 3;
  if ((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0)) ||
     (((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)) ||
      (*(int *)((int)this + 0x1c) == 0)))) {
    uVar2 = 0;
  }
  else {
    FUN_0041028f(this,0,0,param_1,-1);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_004100f7 @ 004100f7

void __fastcall FUN_004100f7(int *param_1)

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


// ==== FUN_004101d0 @ 004101d0

void __fastcall FUN_004101d0(int *param_1)

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


// ==== FUN_0041028f @ 0041028f

undefined4 __thiscall FUN_0041028f(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  undefined8 uVar1;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  char *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  char *local_50;
  int *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_c = 0;
  }
  else if (param_3 == (int *)0x0) {
    local_c = 0;
  }
  else {
    if (param_3[4] == 3) {
      local_8 = *param_3 + 0xc;
    }
    else {
      if ((param_3[8] == 0) && (*(ushort *)((int)param_3 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_3 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_3[8];
      }
      local_8 = local_70 * 4 + *param_3;
    }
    local_8 = (int)param_3 + local_8;
    local_58 = param_3;
    local_4c = param_3;
    local_68 = param_1;
    local_64 = param_2;
    local_60 = param_3[1] + param_1;
    local_5c = param_3[2] + param_2;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_48 = 0;
      local_40 = *(undefined4 *)((int)this + 0xc);
      local_44 = 0;
      local_3c = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_48 = *(int *)((int)this + 0x594);
      local_44 = *(undefined4 *)((int)this + 0x598);
      local_40 = *(undefined4 *)((int)this + 0x59c);
      local_3c = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar1 = FUN_004168c8(&local_28,&local_68,&local_48);
    if ((int)uVar1 != 0) {
      local_30 = ((uint)*(ushort *)((int)local_4c + 0xe) * local_4c[1] + 0x1f & 0xffffffe0) >> 3;
      local_34 = *(int *)((int)this + 0x14);
      local_54 = local_28;
      local_10 = local_24;
      local_2c = local_20 - local_28;
      local_18 = local_1c - local_24;
      local_14 = local_28 - param_1;
      local_38 = local_24 - param_2;
      local_50 = (char *)(local_8 + (local_4c[2] - (local_38 + local_18)) * local_30 + local_14);
      if (*(int *)((int)this + 0x18) == -1) {
        local_34 = -local_34;
        local_6c = (char *)((local_18 + local_24 + -1) * *(int *)((int)this + 0x14) + local_28 +
                           *(int *)((int)this + 8));
      }
      else {
        local_6c = (char *)((*(int *)((int)this + 0x10) - (local_18 + local_24)) *
                            *(int *)((int)this + 0x14) + local_28 + *(int *)((int)this + 8));
      }
      if (param_4 == -1) {
        FUN_00414f5c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_00414ea0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_4);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_2c + local_54 + -1;
      local_78 = local_18 + local_10 + -1;
      FUN_00413ba3(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_004105e5 @ 004105e5

undefined4 __thiscall
FUN_004105e5(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int *param_7,short param_8)

{
  undefined8 uVar1;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  char *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  char *local_50;
  int *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_c = 0;
  }
  else if (param_7 == (int *)0x0) {
    local_c = 0;
  }
  else {
    if (param_7[4] == 3) {
      local_8 = *param_7 + 0xc;
    }
    else {
      if ((param_7[8] == 0) && (*(ushort *)((int)param_7 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_7 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_7[8];
      }
      local_8 = local_70 * 4 + *param_7;
    }
    local_8 = (int)param_7 + local_8;
    local_58 = param_7;
    local_4c = param_7;
    if ((param_5 == 0) || (param_6 == 0)) {
      param_5 = param_7[1];
      param_6 = param_7[2];
      param_3 = 0;
      param_4 = 0;
    }
    local_68 = param_1;
    local_64 = param_2;
    local_60 = param_5 + param_1;
    local_5c = param_6 + param_2;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_48 = 0;
      local_40 = *(undefined4 *)((int)this + 0xc);
      local_44 = 0;
      local_3c = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_48 = *(int *)((int)this + 0x594);
      local_44 = *(undefined4 *)((int)this + 0x598);
      local_40 = *(undefined4 *)((int)this + 0x59c);
      local_3c = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar1 = FUN_004168c8(&local_28,&local_68,&local_48);
    if ((int)uVar1 != 0) {
      local_30 = ((uint)*(ushort *)((int)local_4c + 0xe) * local_4c[1] + 0x1f & 0xffffffe0) >> 3;
      local_34 = *(int *)((int)this + 0x14);
      local_54 = local_28;
      local_10 = local_24;
      local_2c = local_20 - local_28;
      local_18 = local_1c - local_24;
      local_14 = (local_28 + param_3) - param_1;
      local_38 = (local_24 + param_4) - param_2;
      local_50 = (char *)(local_8 + (local_4c[2] - (local_38 + local_18)) * local_30 + local_14);
      if (*(int *)((int)this + 0x18) == -1) {
        local_34 = -local_34;
        local_6c = (char *)((local_24 + local_18 + -1) * *(int *)((int)this + 0x14) + local_28 +
                           *(int *)((int)this + 8));
      }
      else {
        local_6c = (char *)((*(int *)((int)this + 0x10) - (local_24 + local_18)) *
                            *(int *)((int)this + 0x14) + local_28 + *(int *)((int)this + 8));
      }
      if (param_8 == -1) {
        FUN_00414f5c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_00414ea0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_8);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_54 + local_2c + -1;
      local_78 = local_10 + local_18 + -1;
      FUN_00413ba3(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_0041096f @ 0041096f

void __thiscall
FUN_0041096f(void *this,int param_1,int param_2,int *param_3,int *param_4,short param_5)

{
  FUN_004105e5(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004109c7 @ 004109c7

undefined4 __thiscall
FUN_004109c7(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int *param_7,HDC param_8,short param_9)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_004105e5(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar2 = param_5 + param_1 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_6 + param_2 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00410b30 @ 00410b30

void __thiscall
FUN_00410b30(void *this,int param_1,int param_2,int *param_3,int *param_4,HDC param_5,short param_6)

{
  FUN_004109c7(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5,param_6);
  return;
}


// ==== FUN_00410b8c @ 00410b8c

undefined4 __thiscall
FUN_00410b8c(void *this,int param_1,int param_2,int *param_3,HDC param_4,short param_5)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041028f(this,param_1,param_2,param_3,param_5);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar2 = param_3[1] + param_1 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_3[2] + param_2 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_4,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00410d03 @ 00410d03

undefined4 __thiscall
FUN_00410d03(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6)

{
  undefined8 uVar1;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_84;
  char *local_80;
  undefined1 *local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int *local_68;
  int local_64;
  undefined1 *local_60;
  int *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_10 = 0;
  }
  else if ((param_5 == (int *)0x0) || (param_6 == (short *)0x0)) {
    local_10 = 0;
  }
  else {
    if (param_5[4] == 3) {
      local_8 = *param_5 + 0xc;
    }
    else {
      if ((param_5[8] == 0) && (*(ushort *)((int)param_5 + 0xe) < 9)) {
        local_84 = 1 << (*(byte *)((int)param_5 + 0xe) & 0x1f);
      }
      else {
        local_84 = param_5[8];
      }
      local_8 = local_84 * 4 + *param_5;
    }
    local_8 = (int)param_5 + local_8;
    local_68 = param_5;
    local_5c = param_5;
    local_28 = (int)*param_6;
    local_18 = (int)param_6[1];
    local_78 = param_1;
    local_74 = param_2;
    local_70 = param_1 + local_28;
    local_6c = param_2 + local_18;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_58 = 0;
      local_50 = *(undefined4 *)((int)this + 0xc);
      local_54 = 0;
      local_4c = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_58 = *(int *)((int)this + 0x594);
      local_54 = *(undefined4 *)((int)this + 0x598);
      local_50 = *(undefined4 *)((int)this + 0x59c);
      local_4c = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar1 = FUN_004168c8(&local_38,&local_78,&local_58);
    if ((int)uVar1 != 0) {
      local_40 = ((uint)*(ushort *)((int)local_5c + 0xe) * local_5c[1] + 0x1f & 0xffffffe0) >> 3;
      local_44 = *(int *)((int)this + 0x14);
      local_64 = local_38;
      local_14 = local_34;
      local_3c = local_30 - local_38;
      local_20 = local_2c - local_34;
      local_1c = (param_3 + local_38) - param_1;
      local_48 = (param_4 + local_34) - param_2;
      local_c = local_38 - param_1;
      local_24 = (local_34 - param_2) + local_20 + -1;
      local_60 = (undefined1 *)
                 (local_8 + (local_5c[2] - (local_48 + local_20)) * local_40 + local_1c);
      if (param_6 == (short *)0x0) {
        local_80 = (char *)0x0;
      }
      else {
        local_80 = (char *)((int)param_6 + *param_6 * local_24 + local_c + 4);
      }
      if (*(int *)((int)this + 0x18) == -1) {
        local_44 = -local_44;
        local_7c = (undefined1 *)
                   ((local_20 + local_34 + -1) * *(int *)((int)this + 0x14) + local_38 +
                   *(int *)((int)this + 8));
      }
      else {
        local_7c = (undefined1 *)
                   ((*(int *)((int)this + 0x10) - (local_20 + local_34)) *
                    *(int *)((int)this + 0x14) + local_38 + *(int *)((int)this + 8));
      }
      FUN_00414fa6(local_7c,local_60,local_80,local_3c,local_20,local_44,local_40,-local_28);
      local_10 = 1;
      local_9c = local_64;
      local_98 = local_14;
      local_94 = local_3c + local_64 + -1;
      local_90 = local_20 + local_14 + -1;
      FUN_00413ba3(this,&local_9c);
    }
  }
  return local_10;
}


// ==== FUN_004110b5 @ 004110b5

undefined4 __thiscall
FUN_004110b5(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6,
            HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_00410d03(this,param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    if (*param_6 + param_1 + -1 < *(int *)((int)this + 0xc) + -1) {
      iVar2 = *param_6 + param_1;
    }
    else {
      iVar2 = *(int *)((int)this + 0xc);
    }
    if (param_6[1] + param_2 + -1 < *(int *)((int)this + 0x10) + -1) {
      iVar3 = param_6[1] + param_2;
    }
    else {
      iVar3 = *(int *)((int)this + 0x10);
    }
    if ((iVar2 - iVar1 == 0) || (iVar3 - y == 0)) {
      uVar4 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_00411260 @ 00411260

undefined4 __thiscall FUN_00411260(void *this,int param_1,int param_2,short *param_3,int param_4)

{
  undefined8 uVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  char *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_3 == (short *)0x0)))) {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_3;
    local_18 = (int)param_3[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_1;
      local_5c = param_2;
      local_58 = local_10 + param_1;
      local_54 = local_18 + param_2;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0xc);
        local_44 = 0;
        local_3c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_48 = *(int *)((int)this + 0x594);
        local_44 = *(undefined4 *)((int)this + 0x598);
        local_40 = *(undefined4 *)((int)this + 0x59c);
        local_3c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_2c,&local_60,&local_48);
      if ((int)uVar1 != 0) {
        if (param_4 == 0) {
          local_34 = *(int *)((int)this + 0x14);
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = local_2c - param_1;
          local_38 = local_28 - param_2;
          local_4c = (char *)((int)param_3 + local_10 * local_38 + local_14 + 4);
          if (*(int *)((int)this + 0x18) == -1) {
            local_64 = (char *)(*(int *)((int)this + 0x14) * local_28 + local_2c +
                               *(int *)((int)this + 8));
          }
          else {
            local_34 = -local_34;
            local_64 = (char *)((*(int *)((int)this + 0x10) - (local_28 + 1)) *
                                *(int *)((int)this + 0x14) + local_2c + *(int *)((int)this + 8));
          }
          FUN_00414ea0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00413ba3(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_004114d7 @ 004114d7

undefined4 __thiscall
FUN_004114d7(void *this,int param_1,int param_2,short *param_3,undefined1 param_4)

{
  undefined8 uVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined1 *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_3 == (short *)0x0)))) {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_3;
    local_18 = (int)param_3[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_1;
      local_5c = param_2;
      local_58 = param_1 + local_10;
      local_54 = param_2 + local_18;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0xc);
        local_44 = 0;
        local_3c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_48 = *(int *)((int)this + 0x594);
        local_44 = *(undefined4 *)((int)this + 0x598);
        local_40 = *(undefined4 *)((int)this + 0x59c);
        local_3c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_2c,&local_60,&local_48);
      if ((int)uVar1 != 0) {
        local_34 = *(int *)((int)this + 0x14);
        local_50 = local_2c;
        local_c = local_28;
        local_30 = local_24 - local_2c;
        local_1c = local_20 - local_28;
        local_14 = local_2c - param_1;
        local_38 = local_28 - param_2;
        local_4c = (char *)((int)param_3 + local_38 * local_10 + local_14 + 4);
        if (*(int *)((int)this + 0x18) == -1) {
          local_64 = (undefined1 *)
                     (*(int *)((int)this + 0x14) * local_28 + local_2c + *(int *)((int)this + 8));
        }
        else {
          local_34 = -local_34;
          local_64 = (undefined1 *)
                     ((*(int *)((int)this + 0x10) - (local_28 + 1)) * *(int *)((int)this + 0x14) +
                      local_2c + *(int *)((int)this + 8));
        }
        FUN_004151d6(local_64,local_4c,local_30,local_1c,local_34,local_10,param_4);
        local_8 = 1;
        local_78 = local_50;
        local_74 = local_c;
        local_70 = local_30 + local_50 + -1;
        local_6c = local_1c + local_c + -1;
        FUN_00413ba3(this,&local_78);
      }
    }
  }
  return local_8;
}


// ==== FUN_0041173c @ 0041173c

undefined4 __thiscall
FUN_0041173c(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short *param_7,int param_8)

{
  undefined8 uVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  char *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_7 == (short *)0x0)))) {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_7;
    local_18 = (int)param_7[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      if ((param_5 == 0) || (param_6 == 0)) {
        param_3 = 0;
        param_4 = 0;
        param_5 = local_10;
        param_6 = local_18;
      }
      local_60 = param_1;
      local_5c = param_2;
      local_58 = param_1 + param_5;
      local_54 = param_2 + param_6;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0xc);
        local_44 = 0;
        local_3c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_48 = *(int *)((int)this + 0x594);
        local_44 = *(undefined4 *)((int)this + 0x598);
        local_40 = *(undefined4 *)((int)this + 0x59c);
        local_3c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_2c,&local_60,&local_48);
      if ((int)uVar1 != 0) {
        if (param_8 == 0) {
          local_34 = *(int *)((int)this + 0x14);
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = (param_3 + local_2c) - param_1;
          local_38 = (local_28 + param_4) - param_2;
          local_4c = (char *)((int)param_7 + local_38 * local_10 + local_14 + 4);
          if (*(int *)((int)this + 0x18) == -1) {
            local_64 = (char *)(*(int *)((int)this + 0x14) * local_28 + local_2c +
                               *(int *)((int)this + 8));
          }
          else {
            local_34 = -local_34;
            local_64 = (char *)((*(int *)((int)this + 0x10) - (local_28 + 1)) *
                                *(int *)((int)this + 0x14) + local_2c + *(int *)((int)this + 8));
          }
          FUN_00414ea0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00413ba3(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_004119e7 @ 004119e7

void __thiscall
FUN_004119e7(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_0041173c(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00411a3f @ 00411a3f

undefined4 __thiscall
FUN_00411a3f(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short *param_7,HDC param_8)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041173c(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar2 = param_1 + param_5 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_2 + param_6 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00411ba6 @ 00411ba6

void __thiscall
FUN_00411ba6(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_00411a3f(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00411bfe @ 00411bfe

undefined4 __thiscall
FUN_00411bfe(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short *param_7,int param_8)

{
  undefined8 uVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined4 *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_7 == (short *)0x0)))) {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_7;
    local_18 = (int)param_7[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      if ((param_5 == 0) || (param_6 == 0)) {
        param_3 = 0;
        param_4 = 0;
        param_5 = local_10;
        param_6 = local_18;
      }
      local_60 = param_1;
      local_5c = param_2;
      local_58 = param_5 + param_1;
      local_54 = param_6 + param_2;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0xc);
        local_44 = 0;
        local_3c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_48 = *(int *)((int)this + 0x594);
        local_44 = *(undefined4 *)((int)this + 0x598);
        local_40 = *(undefined4 *)((int)this + 0x59c);
        local_3c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_2c,&local_60,&local_48);
      if ((int)uVar1 != 0) {
        if (param_8 == 0) {
          local_34 = *(int *)((int)this + 0x14);
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = (param_3 + local_2c) - param_1;
          local_38 = (param_4 + local_28) - param_2;
          local_4c = (undefined4 *)((int)param_7 + local_38 * local_10 + local_14 + 4);
          if (*(int *)((int)this + 0x18) == -1) {
            local_64 = (undefined4 *)
                       (*(int *)((int)this + 0x14) * local_28 + local_2c + *(int *)((int)this + 8));
          }
          else {
            local_34 = -local_34;
            local_64 = (undefined4 *)
                       ((*(int *)((int)this + 0x10) - (local_28 + 1)) * *(int *)((int)this + 0x14) +
                        local_2c + *(int *)((int)this + 8));
          }
          FUN_00414f5c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00413ba3(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00411ea7 @ 00411ea7

void __thiscall
FUN_00411ea7(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_00411bfe(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00411eff @ 00411eff

undefined4 __thiscall
FUN_00411eff(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short *param_7,HDC param_8)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00411bfe(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar2 = param_5 + param_1 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar2) {
      iVar2 = iVar4;
    }
    iVar4 = param_6 + param_2 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar2 = (iVar2 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar2 == 0) || (iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00412066 @ 00412066

void __thiscall
FUN_00412066(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_00411eff(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004120be @ 004120be

undefined4 __thiscall FUN_004120be(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00411260(this,param_1,param_2,param_3,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar3 = *param_3 + param_1 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar3) {
      iVar3 = iVar4;
    }
    iVar4 = param_3[1] + param_2 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar3 = (iVar3 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar3 == 0) || (iVar4 == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041222c @ 0041222c

undefined4 __thiscall
FUN_0041222c(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,int param_7)

{
  undefined8 uVar1;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char *local_78;
  undefined1 *local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined1 *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
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
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_5 == (short *)0x0)))) {
    local_c = 0;
  }
  else {
    local_18 = (int)*param_5;
    local_20 = (int)param_5[1];
    if ((local_18 == 0) || (local_20 == 0)) {
      local_c = 0;
    }
    else {
      local_2c = (int)*param_6;
      local_14 = (int)param_6[1];
      local_70 = param_1;
      local_6c = param_2;
      local_68 = param_1 + local_2c;
      local_64 = local_14 + param_2;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_58 = 0;
        local_50 = *(undefined4 *)((int)this + 0xc);
        local_54 = 0;
        local_4c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_58 = *(int *)((int)this + 0x594);
        local_54 = *(undefined4 *)((int)this + 0x598);
        local_50 = *(undefined4 *)((int)this + 0x59c);
        local_4c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_3c,&local_70,&local_58);
      if ((int)uVar1 != 0) {
        if (param_7 == 0) {
          local_44 = *(int *)((int)this + 0x14);
          local_60 = local_3c;
          local_10 = local_38;
          local_40 = local_34 - local_3c;
          local_24 = local_30 - local_38;
          local_1c = (local_3c + param_3) - param_1;
          local_48 = (local_38 + param_4) - param_2;
          local_8 = local_3c - param_1;
          local_28 = local_38 - param_2;
          local_5c = (undefined1 *)((int)param_5 + local_18 * local_48 + local_1c + 4);
          if (param_6 == (short *)0x0) {
            local_78 = (char *)0x0;
          }
          else {
            local_78 = (char *)((int)param_6 + *param_6 * local_28 + local_8 + 4);
          }
          if (*(int *)((int)this + 0x18) == -1) {
            local_74 = (undefined1 *)
                       (*(int *)((int)this + 0x14) * local_38 + local_3c + *(int *)((int)this + 8));
          }
          else {
            local_44 = -local_44;
            local_74 = (undefined1 *)
                       ((*(int *)((int)this + 0x10) - (local_38 + 1)) * *(int *)((int)this + 0x14) +
                        local_3c + *(int *)((int)this + 8));
          }
          FUN_00414fa6(local_74,local_5c,local_78,local_40,local_24,local_44,local_18,local_2c);
          local_c = 1;
          local_90 = local_60;
          local_8c = local_10;
          local_88 = local_60 + local_40 + -1;
          local_84 = local_10 + local_24 + -1;
          FUN_00413ba3(this,&local_90);
        }
        else {
          local_c = 1;
        }
      }
    }
  }
  return local_c;
}


// ==== FUN_00412562 @ 00412562

undefined4 __thiscall
FUN_00412562(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_0041222c(this,param_1,param_2,param_3,param_4,param_5,param_6,0);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    if (*param_6 + param_1 + -1 < *(int *)((int)this + 0xc) + -1) {
      iVar2 = *param_6 + param_1;
    }
    else {
      iVar2 = *(int *)((int)this + 0xc);
    }
    if (param_6[1] + param_2 + -1 < *(int *)((int)this + 0x10) + -1) {
      iVar3 = param_6[1] + param_2;
    }
    else {
      iVar3 = *(int *)((int)this + 0x10);
    }
    if ((iVar2 - iVar1 == 0) || (iVar3 - y == 0)) {
      uVar4 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_0041270f @ 0041270f

undefined4 __thiscall FUN_0041270f(void *this,int param_1,int param_2,short *param_3,int param_4)

{
  undefined8 uVar1;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined4 *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_3 == (short *)0x0)))) {
    local_8 = 0;
  }
  else {
    local_10 = (int)*param_3;
    local_18 = (int)param_3[1];
    if ((local_10 == 0) || (local_18 == 0)) {
      local_8 = 0;
    }
    else {
      local_60 = param_1;
      local_5c = param_2;
      local_58 = param_1 + local_10;
      local_54 = param_2 + local_18;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0xc);
        local_44 = 0;
        local_3c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_48 = *(int *)((int)this + 0x594);
        local_44 = *(undefined4 *)((int)this + 0x598);
        local_40 = *(undefined4 *)((int)this + 0x59c);
        local_3c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_2c,&local_60,&local_48);
      if ((int)uVar1 != 0) {
        if (param_4 == 0) {
          local_34 = *(int *)((int)this + 0x14);
          local_50 = local_2c;
          local_c = local_28;
          local_30 = local_24 - local_2c;
          local_1c = local_20 - local_28;
          local_14 = local_2c - param_1;
          local_38 = local_28 - param_2;
          local_4c = (undefined4 *)((int)param_3 + local_38 * local_10 + local_14 + 4);
          if (*(int *)((int)this + 0x18) == -1) {
            local_64 = (undefined4 *)
                       (*(int *)((int)this + 0x14) * local_28 + local_2c + *(int *)((int)this + 8));
          }
          else {
            local_34 = -local_34;
            local_64 = (undefined4 *)
                       ((*(int *)((int)this + 0x10) - (local_28 + 1)) * *(int *)((int)this + 0x14) +
                        local_2c + *(int *)((int)this + 8));
          }
          FUN_00414f5c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00413ba3(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00412984 @ 00412984

undefined4 __thiscall FUN_00412984(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041270f(this,param_1,param_2,param_3,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = param_1;
    if (param_1 < 1) {
      iVar1 = 0;
    }
    y = param_2;
    if (param_2 < 1) {
      y = 0;
    }
    iVar3 = *param_3 + param_1 + -1;
    iVar4 = *(int *)((int)this + 0xc) + -1;
    if (iVar4 <= iVar3) {
      iVar3 = iVar4;
    }
    iVar4 = param_3[1] + param_2 + -1;
    iVar5 = *(int *)((int)this + 0x10) + -1;
    if (iVar5 <= iVar4) {
      iVar4 = iVar5;
    }
    iVar3 = (iVar3 - iVar1) + 1;
    iVar4 = (iVar4 - y) + 1;
    if ((iVar3 == 0) || (iVar4 == 0)) {
      uVar2 = 0;
    }
    else {
      DAT_0042ab9c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0042abc0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00412af2 @ 00412af2

undefined4 __thiscall
FUN_00412af2(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int *param_7,short param_8)

{
  int iVar1;
  undefined8 uVar2;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  char *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  char *local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  int local_14 [3];
  int local_8;
  
  local_20 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_20 = 0;
  }
  else if (param_7 == (int *)0x0) {
    local_20 = 0;
  }
  else {
    if (param_7[4] == 3) {
      local_1c = *param_7 + 0xc;
    }
    else {
      if ((param_7[8] == 0) && (*(ushort *)((int)param_7 + 0xe) < 9)) {
        local_70 = 1 << (*(byte *)((int)param_7 + 0xe) & 0x1f);
      }
      else {
        local_70 = param_7[8];
      }
      local_1c = local_70 * 4 + *param_7;
    }
    local_1c = (int)param_7 + local_1c;
    local_18 = param_7;
    local_48 = param_7;
    if ((param_5 == 0) || (param_6 == 0)) {
      param_5 = *(int *)((int)this + 0xc);
      param_6 = *(int *)((int)this + 0x10);
      param_1 = 0;
      param_2 = 0;
    }
    local_58 = param_1;
    local_54 = param_2;
    local_50 = param_1 + param_5;
    local_4c = param_6 + param_2;
    local_14[1] = 0;
    local_14[0] = 0;
    local_14[2] = param_7[1];
    local_8 = param_7[2];
    uVar2 = FUN_004168c8(&local_6c,&local_58,local_14);
    if ((int)uVar2 != 0) {
      local_34 = ((uint)*(ushort *)((int)local_48 + 0xe) * local_48[1] + 0x1f & 0xffffffe0) >> 3;
      local_44 = local_6c;
      local_24 = local_68;
      local_30 = local_64 - local_6c;
      local_2c = local_60 - local_68;
      local_28 = (local_6c + param_3) - param_1;
      local_3c = (param_4 + local_68) - param_2;
      if (*(int *)((int)this + 0x18) == -1) {
        local_40 = (char *)(*(int *)((int)this + 0x14) * local_3c + local_28 +
                           *(int *)((int)this + 8));
        iVar1 = local_48[2] - (local_68 + 1);
        local_38 = -local_34;
      }
      else {
        local_40 = (char *)((*(int *)((int)this + 0x10) - (local_2c + local_3c)) *
                            *(int *)((int)this + 0x14) + local_28 + *(int *)((int)this + 8));
        iVar1 = local_48[2] - (local_2c + local_68);
        local_38 = local_34;
      }
      local_5c = (char *)(local_1c + iVar1 * local_34 + local_6c);
      if (param_8 == -1) {
        FUN_00414f5c((undefined4 *)local_5c,(undefined4 *)local_40,local_30,local_2c,local_38,
                     *(int *)((int)this + 0x14));
      }
      else {
        FUN_00414ea0(local_5c,local_40,local_30,local_2c,local_38,*(int *)((int)this + 0x14),
                     (byte)param_8);
      }
      local_20 = 1;
    }
  }
  return local_20;
}


// ==== FUN_00412de6 @ 00412de6

undefined4 __thiscall
FUN_00412de6(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short *param_7,short param_8)

{
  undefined8 uVar1;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  char *local_54;
  int local_50;
  char *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [3];
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  short *local_8;
  
  local_10 = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_10 = 0;
  }
  else if (param_7 == (short *)0x0) {
    local_10 = 0;
  }
  else {
    local_24[2] = (int)*param_7;
    local_58 = (int)param_7[1];
    local_8 = param_7 + 2;
    if ((param_5 == 0) || (param_6 == 0)) {
      param_1 = 0;
      param_2 = 0;
      param_5 = local_24[2];
      param_6 = local_58;
    }
    local_44 = param_1;
    local_40 = param_2;
    local_3c = param_5 + param_1;
    local_38 = param_6 + param_2;
    local_24[1] = 0;
    local_24[0] = 0;
    local_18 = local_58;
    local_c = local_24[2];
    uVar1 = FUN_004168c8(&local_68,&local_44,local_24);
    if ((int)uVar1 != 0) {
      local_50 = local_68;
      local_14 = local_64;
      local_34 = local_60 - local_68;
      local_2c = local_5c - local_64;
      local_28 = (local_68 + param_3) - param_1;
      local_48 = (local_64 + param_4) - param_2;
      if (*(int *)((int)this + 0x18) == -1) {
        local_30 = *(int *)((int)this + 0x14);
        local_4c = (char *)(*(int *)((int)this + 0x14) * local_48 + local_28 +
                           *(int *)((int)this + 8));
      }
      else {
        local_30 = -*(int *)((int)this + 0x14);
        local_4c = (char *)(((*(int *)((int)this + 0x10) - local_48) + -1) *
                            *(int *)((int)this + 0x14) + local_28 + *(int *)((int)this + 8));
      }
      local_54 = (char *)(local_c * local_64 + local_68 + (int)local_8);
      if (param_8 == -1) {
        FUN_00414f5c((undefined4 *)local_54,(undefined4 *)local_4c,local_34,local_2c,local_c,
                     local_30);
      }
      else {
        FUN_00414ea0(local_54,local_4c,local_34,local_2c,local_c,local_30,(byte)param_8);
      }
      local_10 = 1;
    }
  }
  return local_10;
}


// ==== FUN_00413045 @ 00413045

undefined4 __thiscall FUN_00413045(void *this,int *param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  uint local_3c;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    local_8 = 0;
  }
  else {
    if (param_1 == (int *)0x0) {
      if (*(int *)((int)this + 0x594) == 64000) {
        local_18 = 0;
        local_10 = *(int *)((int)this + 0xc);
        local_14 = 0;
        local_c = *(int *)((int)this + 0x10);
      }
      else {
        local_18 = *(int *)((int)this + 0x594);
        local_14 = *(int *)((int)this + 0x598);
        local_10 = *(int *)((int)this + 0x59c);
        local_c = *(int *)((int)this + 0x5a0);
      }
    }
    else {
      local_18 = *param_1;
      local_14 = param_1[1];
      local_10 = param_1[2];
      local_c = param_1[3];
    }
    iVar2 = local_10;
    iVar1 = local_14;
    local_20 = local_10 - local_18;
    local_24 = local_c - local_14;
    if (local_20 < 0) {
      local_20 = 1 - local_20;
      local_5c = local_10;
      local_10 = local_18;
      local_18 = iVar2;
    }
    if (local_24 < 0) {
      local_24 = 1 - local_24;
      local_5c = local_14;
      local_14 = local_c;
      local_c = iVar1;
    }
    if ((local_20 == 0) || (local_24 == 0)) {
      local_8 = 0;
    }
    else {
      if (*(int *)((int)this + 0x594) == 64000) {
        local_50 = 0;
        local_48 = *(undefined4 *)((int)this + 0xc);
        local_4c = 0;
        local_44 = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_50 = *(int *)((int)this + 0x594);
        local_4c = *(undefined4 *)((int)this + 0x598);
        local_48 = *(undefined4 *)((int)this + 0x59c);
        local_44 = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar3 = FUN_004168c8(&local_38,&local_18,&local_50);
      if ((int)uVar3 != 0) {
        local_40 = *(int *)((int)this + 0x14);
        local_54 = local_38;
        local_1c = local_34;
        local_3c = local_30 - local_38;
        local_28 = local_2c - local_34;
        if (*(int *)((int)this + 0x18) == -1) {
          local_58 = (undefined4 *)
                     (*(int *)((int)this + 0x14) * local_34 + local_38 + *(int *)((int)this + 8));
        }
        else {
          local_40 = -local_40;
          local_58 = (undefined4 *)
                     ((*(int *)((int)this + 0x10) - (local_34 + 1)) * *(int *)((int)this + 0x14) +
                      local_38 + *(int *)((int)this + 8));
        }
        FUN_0041517e(local_58,local_3c,local_28,local_40,param_2);
        local_8 = 1;
        local_70 = local_54;
        local_6c = local_1c;
        local_68 = local_3c + local_54 + -1;
        local_64 = local_28 + local_1c + -1;
        FUN_00413ba3(this,&local_70);
      }
    }
  }
  return local_8;
}


// ==== FUN_00413323 @ 00413323

void __thiscall
FUN_00413323(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short param_7)

{
  undefined4 *unaff_FS_OFFSET;
  undefined8 uVar1;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  puStack_c = &LAB_004135b4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    FUN_004135be();
    return;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  if ((param_5 == 0) || (param_6 == 0)) {
    local_8 = 0xffffffff;
    FUN_004135ab();
    FUN_004135be();
    return;
  }
  local_50 = param_3;
  local_4c = param_4;
  local_48 = param_5 + param_3;
  local_44 = param_6 + param_4;
  if (*(int *)((int)this + 0x594) == 64000) {
    local_40 = 0;
    local_38 = *(undefined4 *)((int)this + 0xc);
    local_3c = 0;
    local_34 = *(undefined4 *)((int)this + 0x10);
  }
  else {
    local_40 = *(int *)((int)this + 0x594);
    local_3c = *(undefined4 *)((int)this + 0x598);
    local_38 = *(undefined4 *)((int)this + 0x59c);
    local_34 = *(undefined4 *)((int)this + 0x5a0);
  }
  uVar1 = FUN_004168c8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_004135ab();
    FUN_004135be();
    return;
  }
  local_50 = param_1;
  local_4c = param_2;
  local_48 = (local_28 - local_30) + param_1;
  local_44 = (local_24 - local_2c) + param_2;
  uVar1 = FUN_004168c8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_004135ab();
    FUN_004135be();
    return;
  }
  FUN_004199d8(&local_20,local_30,local_2c,local_28,local_24,1);
  if (param_7 == -1) {
    FUN_00419ce9(&local_20,1,param_1,param_2,-0x8000);
  }
  else {
    FUN_0041a290(&local_20,(int)(char)param_7,1,param_1,param_2,-0x8000);
  }
  local_8 = 0xffffffff;
  FUN_004135ab();
  FUN_004135be();
  return;
}


// ==== FUN_004135ab @ 004135ab

void FUN_004135ab(void)

{
  int unaff_EBP;
  
  FUN_0040eac0((int *)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_004135be @ 004135be

void FUN_004135be(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004135cf @ 004135cf

void __thiscall FUN_004135cf(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00413323(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_00413623 @ 00413623

undefined4 __thiscall
FUN_00413623(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            short param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  char *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  char *local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    uVar1 = 0;
  }
  else if ((param_5 == 0) || (param_6 == 0)) {
    uVar1 = 0;
  }
  else {
    local_54 = param_3;
    local_50 = param_4;
    local_4c = param_5 + param_3;
    local_48 = param_6 + param_4;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_3c = 0;
      local_34 = *(undefined4 *)((int)this + 0xc);
      local_38 = 0;
      local_30 = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_3c = *(int *)((int)this + 0x594);
      local_38 = *(undefined4 *)((int)this + 0x598);
      local_34 = *(undefined4 *)((int)this + 0x59c);
      local_30 = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar2 = FUN_004168c8(&local_20,&local_54,&local_3c);
    if ((int)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_54 = param_1;
      local_50 = param_2;
      local_4c = (local_18 - local_20) + param_1;
      local_48 = (local_14 - local_1c) + param_2;
      uVar2 = FUN_004168c8(&local_20,&local_54,&local_3c);
      if ((int)uVar2 == 0) {
        uVar1 = 0;
      }
      else {
        local_28 = *(int *)((int)this + 0x14);
        local_44 = local_20;
        local_8 = local_1c;
        local_24 = local_18 - local_20;
        local_10 = local_14 - local_1c;
        local_c = (local_20 + param_3) - param_1;
        local_2c = (local_1c + param_4) - param_2;
        if (*(int *)((int)this + 0x18) == -1) {
          local_58 = (char *)(*(int *)((int)this + 0x14) * local_1c + *(int *)((int)this + 8) +
                             local_20);
          local_40 = (char *)(*(int *)((int)this + 0x14) * local_2c + *(int *)((int)this + 8) +
                             local_c);
        }
        else {
          local_28 = -local_28;
          local_58 = (char *)((*(int *)((int)this + 0x10) - (local_1c + 1)) *
                              *(int *)((int)this + 0x14) + local_20 + *(int *)((int)this + 8));
          local_40 = (char *)((*(int *)((int)this + 0x10) - (local_2c + 1)) *
                              *(int *)((int)this + 0x14) + local_c + *(int *)((int)this + 8));
        }
        if (param_7 == -1) {
          FUN_00414f5c((undefined4 *)local_58,(undefined4 *)local_40,local_24,local_10,local_28,
                       local_28);
        }
        else {
          FUN_00414ea0(local_58,local_40,local_24,local_10,local_28,local_28,(byte)param_7);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// ==== FUN_004138dd @ 004138dd

void __thiscall FUN_004138dd(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00413623(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_00413931 @ 00413931

undefined4 __thiscall FUN_00413931(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00411260(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041028f(this,param_1,param_2,(int *)(param_3 + 8),0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_004139c9 @ 004139c9

undefined4 __thiscall FUN_004139c9(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041270f(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041028f(this,param_1,param_2,(int *)(param_3 + 8),-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00413a64 @ 00413a64

undefined4 __thiscall FUN_00413a64(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_004120be(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00410b8c(this,param_1,param_2,(int *)(param_3 + 8),param_4,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00413b02 @ 00413b02

undefined4 __thiscall FUN_00413b02(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00412984(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00410b8c(this,param_1,param_2,(int *)(param_3 + 8),param_4,-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00413ba3 @ 00413ba3

void __thiscall FUN_00413ba3(void *this,int *param_1)

{
  int iVar1;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)((int)this + 0x590) != 0) {
    if (*(int *)((int)this + 0x58c) == 0) {
      iVar1 = *(int *)((int)this + 0x58c);
      *(int *)((int)this + iVar1 * 0x10 + 0x44c) = *param_1;
      *(int *)((int)this + iVar1 * 0x10 + 0x450) = param_1[1];
      *(int *)((int)this + iVar1 * 0x10 + 0x454) = param_1[2];
      *(int *)((int)this + iVar1 * 0x10 + 0x458) = param_1[3];
      *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + 1;
    }
    else if (*(int *)((int)this + 0x58c) < 0x14) {
      iVar1 = *(int *)((int)this + 0x58c);
      *(int *)((int)this + iVar1 * 0x10 + 0x44c) = *param_1;
      *(int *)((int)this + iVar1 * 0x10 + 0x450) = param_1[1];
      *(int *)((int)this + iVar1 * 0x10 + 0x454) = param_1[2];
      *(int *)((int)this + iVar1 * 0x10 + 0x458) = param_1[3];
      *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + 1;
      for (local_18 = 0; local_18 < *(int *)((int)this + 0x58c) + -1; local_18 = local_18 + 1) {
        iVar1 = FUN_00416aa2(&local_14,
                             (int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
                             (int *)((int)this + local_18 * 0x10 + 0x44c));
        if (iVar1 != 0) {
          *(int *)((int)this + local_18 * 0x10 + 0x44c) = local_14;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x450) = local_10;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x454) = local_c;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x458) = local_8;
          *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + -1;
LAB_00413d56:
          if (*(int *)((int)this + 0x58c) == 1) {
            return;
          }
          local_18 = 0;
          do {
            local_1c = local_18;
            if (*(int *)((int)this + 0x58c) + -1 <= local_18) {
              return;
            }
            while (local_1c = local_1c + 1, local_1c < *(int *)((int)this + 0x58c)) {
              iVar1 = FUN_00416aa2(&local_14,(int *)((int)this + local_1c * 0x10 + 0x44c),
                                   (int *)((int)this + local_18 * 0x10 + 0x44c));
              if (iVar1 != 0) {
                *(int *)((int)this + local_18 * 0x10 + 0x44c) = local_14;
                *(undefined4 *)((int)this + local_18 * 0x10 + 0x450) = local_10;
                *(undefined4 *)((int)this + local_18 * 0x10 + 0x454) = local_c;
                *(undefined4 *)((int)this + local_18 * 0x10 + 0x458) = local_8;
                *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + -1;
                iVar1 = *(int *)((int)this + 0x58c);
                *(undefined4 *)((int)this + local_1c * 0x10 + 0x44c) =
                     *(undefined4 *)((int)this + iVar1 * 0x10 + 0x44c);
                *(undefined4 *)((int)this + local_1c * 0x10 + 0x450) =
                     *(undefined4 *)((int)this + iVar1 * 0x10 + 0x450);
                *(undefined4 *)((int)this + local_1c * 0x10 + 0x454) =
                     *(undefined4 *)((int)this + iVar1 * 0x10 + 0x454);
                *(undefined4 *)((int)this + local_1c * 0x10 + 0x458) =
                     *(undefined4 *)((int)this + iVar1 * 0x10 + 0x458);
                goto LAB_00413d56;
              }
            }
            local_18 = local_18 + 1;
          } while( true );
        }
      }
    }
    else {
      FUN_00416a4c(&local_14,(int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
                   param_1);
      iVar1 = *(int *)((int)this + 0x58c) + -1;
      *(int *)((int)this + iVar1 * 0x10 + 0x44c) = local_14;
      *(undefined4 *)((int)this + iVar1 * 0x10 + 0x450) = local_10;
      *(undefined4 *)((int)this + iVar1 * 0x10 + 0x454) = local_c;
      *(undefined4 *)((int)this + iVar1 * 0x10 + 0x458) = local_8;
    }
  }
  return;
}


// ==== FUN_00413e6f @ 00413e6f

void __thiscall FUN_00413e6f(void *this,int *param_1,int *param_2,HDC param_3)

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
  
  iVar1 = FUN_004169b3(param_1,param_2);
  if (iVar1 == 0) {
    FUN_00416b7b(param_1);
    FUN_00416b8b((int)param_1);
    if (*param_1 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = *param_1;
    }
    if (param_1[1] < 0) {
      local_24 = 0;
    }
    else {
      local_24 = param_1[1];
    }
    iVar1 = *(int *)((int)this + 0xc) + -1;
    if (param_1[2] <= iVar1) {
      iVar1 = param_1[2];
    }
    iVar2 = *(int *)((int)this + 0x10) + -1;
    if (param_1[3] <= iVar2) {
      iVar2 = param_1[3];
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_0042ab9c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0042abc0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
    FUN_00416b7b(param_2);
    FUN_00416b8b((int)param_2);
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
    iVar1 = *(int *)((int)this + 0xc) + -1;
    if (param_2[2] <= iVar1) {
      iVar1 = param_2[2];
    }
    iVar2 = *(int *)((int)this + 0x10) + -1;
    if (param_2[3] <= iVar2) {
      iVar2 = param_2[3];
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_0042ab9c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0042abc0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  else {
    FUN_00416a4c(&local_18,param_1,param_2);
    FUN_00416b7b(&local_18);
    FUN_00416b8b((int)&local_18);
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
    iVar1 = *(int *)((int)this + 0xc) + -1;
    if (local_10 <= iVar1) {
      iVar1 = local_10;
    }
    iVar2 = *(int *)((int)this + 0x10) + -1;
    if (local_c <= iVar2) {
      iVar2 = local_c;
    }
    iVar1 = (iVar1 - local_1c) + 1;
    local_8 = (iVar2 - local_24) + 1;
    if ((iVar1 != 0) && (local_8 != 0)) {
      DAT_0042ab9c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0042abc0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  return;
}


// ==== FUN_0041427a @ 0041427a

undefined4 __thiscall
FUN_0041427a(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,short *param_9,short *param_10,int param_11)

{
  undefined8 uVar1;
  char *local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  char *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
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
  char *local_8;
  
  local_10 = 0;
  if ((((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
       || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
      ((*(int *)((int)this + 0x1c) == 0 || ((param_9 == (short *)0x0 || (param_10 == (short *)0x0)))
       ))) || (param_11 == 0)) {
    local_10 = 0;
  }
  else {
    local_1c = (int)*param_9;
    local_24 = (int)param_9[1];
    if ((local_1c == 0) || (local_24 == 0)) {
      local_10 = 0;
    }
    else {
      if ((param_5 == 0) || (param_6 == 0)) {
        param_3 = 0;
        param_4 = 0;
        param_5 = local_1c;
        param_6 = local_24;
      }
      local_70 = param_1;
      local_6c = param_2;
      local_68 = param_5 + param_1;
      local_64 = param_6 + param_2;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_58 = 0;
        local_50 = *(undefined4 *)((int)this + 0xc);
        local_54 = 0;
        local_4c = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_58 = *(int *)((int)this + 0x594);
        local_54 = *(undefined4 *)((int)this + 0x598);
        local_50 = *(undefined4 *)((int)this + 0x59c);
        local_4c = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_38,&local_70,&local_58);
      if ((int)uVar1 != 0) {
        local_18 = (int)*param_10;
        local_40 = *(int *)((int)this + 0x14);
        local_60 = local_38;
        local_14 = local_34;
        local_3c = local_30 - local_38;
        local_28 = local_2c - local_34;
        local_20 = (param_3 + local_38) - param_1;
        local_48 = (param_4 + local_34) - param_2;
        local_5c = (char *)((int)param_9 + local_1c * local_48 + local_20 + 4);
        local_44 = (local_48 + param_8) * local_18 + local_20 + param_7;
        local_8 = (char *)((int)param_10 + local_44 + 4);
        local_c = param_11 + 4 + local_44;
        if (*(int *)((int)this + 0x18) == -1) {
          local_74 = (char *)(*(int *)((int)this + 0x14) * local_34 + local_38 +
                             *(int *)((int)this + 8));
        }
        else {
          local_40 = -local_40;
          local_74 = (char *)((*(int *)((int)this + 0x10) - (local_34 + 1)) *
                              *(int *)((int)this + 0x14) + local_38 + *(int *)((int)this + 8));
        }
        FUN_004152d4(local_74,local_5c,local_8,local_c,local_3c,local_28,local_40,local_1c,local_18)
        ;
        local_10 = 1;
      }
    }
  }
  return local_10;
}


// ==== FUN_00414542 @ 00414542

undefined4 __thiscall FUN_00414542(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  if ((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0)) ||
     (((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)) ||
      (*(int *)((int)this + 0x1c) == 0)))) {
    local_8 = 0;
  }
  else {
    local_c = (param_3 - param_1) + 1;
    local_10 = (param_4 - param_2) + 1;
    local_4c = param_1;
    local_48 = param_2;
    local_44 = param_1 + local_c;
    local_40 = param_2 + local_10;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_3c = 0;
      local_34 = *(undefined4 *)((int)this + 0xc);
      local_38 = 0;
      local_30 = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_3c = *(int *)((int)this + 0x594);
      local_38 = *(undefined4 *)((int)this + 0x598);
      local_34 = *(undefined4 *)((int)this + 0x59c);
      local_30 = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar2 = FUN_004168c8(&local_24,&local_4c,&local_3c);
    if ((int)uVar2 != 0) {
      local_28 = local_1c - local_24;
      local_14 = local_18 - local_20;
      iVar1 = local_20 + local_14 + -1;
      if (*(int *)((int)this + 0x18) == -1) {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0041acbc((byte *)(*(int *)((int)this + 0x14) * local_2c + *(int *)((int)this + 8) +
                               local_24),local_28);
        }
      }
      else {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0041acbc((byte *)(((*(int *)((int)this + 0x10) - local_2c) + -1) *
                                *(int *)((int)this + 0x14) + *(int *)((int)this + 8) + local_24),
                       local_28);
        }
      }
      local_8 = 1;
      local_60 = local_24;
      local_5c = local_20;
      local_58 = local_24 + local_28 + -1;
      local_54 = local_20 + local_14 + -1;
      FUN_00413ba3(this,&local_60);
    }
  }
  return local_8;
}


// ==== FUN_00414775 @ 00414775

void __fastcall FUN_00414775(int param_1)

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


// ==== FUN_004147f7 @ 004147f7

undefined4 __thiscall
FUN_004147f7(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,byte param_7)

{
  undefined8 uVar1;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_6c;
  char *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  char *local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  uint local_34;
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
  byte *local_8;
  
  local_c = 0;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || ((param_5 == (short *)0x0 || (param_6 == (short *)0x0)))))
     ) {
    local_c = 0;
  }
  else {
    local_14 = (int)*param_5;
    local_1c = (int)param_5[1];
    local_6c = (int)*param_6;
    if ((local_14 == 0) || (local_1c == 0)) {
      local_c = 0;
    }
    else {
      local_64 = param_1;
      local_60 = param_2;
      local_5c = local_14 + param_1;
      local_58 = local_1c + param_2;
      if (*(int *)((int)this + 0x594) == 64000) {
        local_4c = 0;
        local_44 = *(undefined4 *)((int)this + 0xc);
        local_48 = 0;
        local_40 = *(undefined4 *)((int)this + 0x10);
      }
      else {
        local_4c = *(int *)((int)this + 0x594);
        local_48 = *(undefined4 *)((int)this + 0x598);
        local_44 = *(undefined4 *)((int)this + 0x59c);
        local_40 = *(undefined4 *)((int)this + 0x5a0);
      }
      uVar1 = FUN_004168c8(&local_30,&local_64,&local_4c);
      if ((int)uVar1 != 0) {
        local_38 = *(int *)((int)this + 0x14);
        local_54 = local_30;
        local_10 = local_2c;
        local_34 = local_28 - local_30;
        local_20 = local_24 - local_2c;
        local_18 = local_30 - param_1;
        local_3c = local_2c - param_2;
        if (param_5 == (short *)0x0) {
          local_50 = (char *)0x0;
        }
        else {
          local_50 = (char *)((int)param_5 + *param_5 * local_3c + local_18 + 4);
        }
        if (param_6 == (short *)0x0) {
          local_8 = (byte *)0x0;
        }
        else {
          local_8 = (byte *)((int)param_6 +
                            (local_2c + param_4) * (int)*param_6 + local_30 + param_3 + 4);
        }
        if (*(int *)((int)this + 0x18) == -1) {
          local_68 = (char *)(*(int *)((int)this + 0x14) * local_2c + local_30 +
                             *(int *)((int)this + 8));
        }
        else {
          local_38 = -local_38;
          local_68 = (char *)((*(int *)((int)this + 0x10) - (local_2c + 1)) *
                              *(int *)((int)this + 0x14) + local_30 + *(int *)((int)this + 8));
        }
        FUN_00415439(local_68,local_50,local_8,local_34,local_20,local_38,local_14,local_6c,param_7,
                     '\0');
        local_c = 1;
        local_88 = local_54;
        local_84 = local_10;
        local_80 = local_34 + local_54 + -1;
        local_7c = local_10 + local_20 + -1;
        FUN_00413ba3(this,&local_88);
      }
    }
  }
  return local_c;
}


// ==== FUN_00414b31 @ 00414b31

undefined4 __thiscall FUN_00414b31(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
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
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_3 == 0)))) {
    local_8 = 0;
  }
  else if ((local_10 == 0) || (local_14 == 0)) {
    local_8 = 0;
  }
  else {
    local_50 = param_1;
    local_4c = param_2;
    local_48 = local_10 + param_1;
    local_44 = local_14 + param_2;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_3c = 0;
      local_34 = *(undefined4 *)((int)this + 0xc);
      local_38 = 0;
      local_30 = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_3c = *(int *)((int)this + 0x594);
      local_38 = *(undefined4 *)((int)this + 0x598);
      local_34 = *(undefined4 *)((int)this + 0x59c);
      local_30 = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar1 = FUN_004168c8(&local_28,&local_50,&local_3c);
    if ((int)uVar1 != 0) {
      if (param_4 == 0) {
        local_40 = local_28;
        local_c = local_24;
        local_2c = local_20 - local_28;
        local_18 = local_1c - local_24;
        local_8 = 1;
        local_64 = local_28;
        local_60 = local_24;
        local_5c = local_28 + local_2c + -1;
        local_58 = local_24 + local_18 + -1;
        FUN_00413ba3(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00414ce8 @ 00414ce8

undefined4 __thiscall FUN_00414ce8(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
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
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     ((*(int *)((int)this + 0x1c) == 0 || (param_3 == 0)))) {
    local_8 = 0;
  }
  else if ((local_10 == 0) || (local_14 == 0)) {
    local_8 = 0;
  }
  else {
    local_50 = param_1;
    local_4c = param_2;
    local_48 = param_1 + local_10;
    local_44 = param_2 + local_14;
    if (*(int *)((int)this + 0x594) == 64000) {
      local_3c = 0;
      local_34 = *(undefined4 *)((int)this + 0xc);
      local_38 = 0;
      local_30 = *(undefined4 *)((int)this + 0x10);
    }
    else {
      local_3c = *(int *)((int)this + 0x594);
      local_38 = *(undefined4 *)((int)this + 0x598);
      local_34 = *(undefined4 *)((int)this + 0x59c);
      local_30 = *(undefined4 *)((int)this + 0x5a0);
    }
    uVar1 = FUN_004168c8(&local_28,&local_50,&local_3c);
    if ((int)uVar1 != 0) {
      if (param_4 == 0) {
        local_40 = local_28;
        local_c = local_24;
        local_2c = local_20 - local_28;
        local_18 = local_1c - local_24;
        local_8 = 1;
        local_64 = local_28;
        local_60 = local_24;
        local_5c = local_2c + local_28 + -1;
        local_58 = local_18 + local_24 + -1;
        FUN_00413ba3(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00414ea0 @ 00414ea0

/* WARNING: Removing unreachable block (ram,0x00414efe) */
/* WARNING: Removing unreachable block (ram,0x00414f31) */

void __cdecl
FUN_00414ea0(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
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
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_00414f06;
LAB_00414ede:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_00414f0f;
LAB_00414ee5:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_00414f19;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_00414f34;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_00414ede;
LAB_00414f06:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_00414ee5;
LAB_00414f0f:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_00414f19:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_00414ef3;
          }
        }
LAB_00414ef3:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_00414f34:
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


// ==== FUN_00414f5c @ 00414f5c

void __cdecl
FUN_00414f5c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
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


// ==== FUN_00414fa6 @ 00414fa6

void __cdecl
FUN_00414fa6(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_004220aa = param_4;
    do {
      for (uVar4 = DAT_004220aa >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *param_2;
        if (*param_3 != '\0') goto LAB_00415020;
LAB_00414fec:
        uVar3 = param_2[1];
        if (param_3[1] != '\0') goto LAB_0041502c;
LAB_00414ff6:
        uVar3 = param_2[2];
        if (param_3[2] != '\0') goto LAB_00415039;
        while (uVar3 = param_2[3], param_3[3] != '\0') {
          while( true ) {
            param_1[3] = uVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_00415058;
            uVar3 = *param_2;
            if (*param_3 == '\0') goto LAB_00414fec;
LAB_00415020:
            *param_1 = uVar3;
            uVar3 = param_2[1];
            if (param_3[1] == '\0') goto LAB_00414ff6;
LAB_0041502c:
            param_1[1] = uVar3;
            uVar3 = param_2[2];
            if (param_3[2] == '\0') break;
LAB_00415039:
            param_1[2] = uVar3;
            uVar3 = param_2[3];
            if (param_3[3] == '\0') goto LAB_0041500a;
          }
        }
LAB_0041500a:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00415058:
      if ((DAT_004220aa & 3) != 0) {
        iVar5 = (DAT_004220aa & 3) + 1;
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


// ==== FUN_0041508d @ 0041508d

void __cdecl
FUN_0041508d(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8,char param_9)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_004220aa = param_4;
    do {
      for (uVar4 = DAT_004220aa >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar1 = *param_2;
        if (*param_3 == param_9) goto LAB_0041510d;
LAB_004150d5:
        uVar1 = param_2[1];
        if (param_3[1] == param_9) goto LAB_0041511a;
LAB_004150e0:
        uVar1 = param_2[2];
        if (param_3[2] == param_9) goto LAB_00415128;
        while (uVar1 = param_2[3], param_3[3] == param_9) {
          while( true ) {
            param_1[3] = uVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_00415148;
            uVar1 = *param_2;
            if (*param_3 != param_9) goto LAB_004150d5;
LAB_0041510d:
            *param_1 = uVar1;
            uVar1 = param_2[1];
            if (param_3[1] != param_9) goto LAB_004150e0;
LAB_0041511a:
            param_1[1] = uVar1;
            uVar1 = param_2[2];
            if (param_3[2] != param_9) break;
LAB_00415128:
            param_1[2] = uVar1;
            uVar1 = param_2[3];
            if (param_3[3] != param_9) goto LAB_004150f6;
          }
        }
LAB_004150f6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00415148:
      if ((DAT_004220aa & 3) != 0) {
        iVar5 = (DAT_004220aa & 3) + 1;
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


// ==== FUN_0041517e @ 0041517e

void __cdecl
FUN_0041517e(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    DAT_004220aa = param_2 & 3;
    uVar1 = param_2 >> 2;
    do {
      for (; uVar2 = DAT_004220aa, uVar1 != 0; uVar1 = uVar1 - 1) {
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


// ==== FUN_004151d6 @ 004151d6

/* WARNING: Removing unreachable block (ram,0x00415232) */
/* WARNING: Removing unreachable block (ram,0x00415265) */

void __cdecl
FUN_004151d6(undefined1 *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
            undefined1 param_7)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    do {
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0041523a;
LAB_00415212:
        if (param_2[1] != '\0') goto LAB_00415243;
LAB_00415219:
        if (param_2[2] != '\0') goto LAB_0041524d;
        while (param_2[3] != '\0') {
          while( true ) {
            param_1[3] = param_7;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar3 = uVar3 - 1;
            if (uVar3 == 0) goto LAB_00415268;
            if (*param_2 == '\0') goto LAB_00415212;
LAB_0041523a:
            *param_1 = param_7;
            if (param_2[1] == '\0') goto LAB_00415219;
LAB_00415243:
            param_1[1] = param_7;
            if (param_2[2] == '\0') break;
LAB_0041524d:
            param_1[2] = param_7;
            if (param_2[3] == '\0') goto LAB_00415227;
          }
        }
LAB_00415227:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_00415268:
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


// ==== FUN_00415290 @ 00415290

void FUN_00415290(void)

{
  byte in_AH;
  undefined4 unaff_ESI;
  
  if (in_AH < DAT_004220b7) {
    if (DAT_004220b6 == '\0') {
      return;
    }
    DAT_004220b2 = unaff_ESI;
    DAT_004220b6 = 0;
    return;
  }
  if (DAT_004220b6 == '\x01') {
    return;
  }
  DAT_004220ae = unaff_ESI;
  DAT_004220b6 = 1;
  return;
}


// ==== FUN_004152d4 @ 004152d4

/* WARNING: Removing unreachable block (ram,0x004153dd) */

void __cdecl
FUN_004152d4(char *param_1,char *param_2,char *param_3,int param_4,uint param_5,int param_6,
            int param_7,int param_8,int param_9)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  int extraout_ECX_02;
  int iVar4;
  int extraout_ECX_03;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  char *pcVar5;
  char *pcVar6;
  
  if (param_5 != 0) {
    DAT_004220b6 = 0;
    DAT_004220ae = param_3;
    DAT_004220b2 = param_4;
    iVar1 = param_9 - param_5;
    DAT_004220aa = param_5;
    do {
      for (uVar3 = DAT_004220aa >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_00415372;
LAB_0041533a:
        if (param_2[1] != '\0') goto LAB_00415386;
LAB_00415341:
        if (param_2[2] != '\0') goto LAB_0041539c;
        while (param_2[3] != '\0') {
          while( true ) {
            FUN_00415290();
            if (param_3[3] != '\0') {
              param_1[3] = param_3[3];
            }
            param_1 = param_1 + 4;
            param_3 = param_3 + 4;
            param_2 = param_2 + 4;
            DAT_004220ae = DAT_004220ae + 4;
            DAT_004220b2 = DAT_004220b2 + 4;
            uVar3 = extraout_ECX_02 - 1;
            param_6 = extraout_EDX_02;
            if (uVar3 == 0) goto LAB_004153e0;
            if (*param_2 == '\0') goto LAB_0041533a;
LAB_00415372:
            FUN_00415290();
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
            uVar3 = extraout_ECX;
            param_6 = extraout_EDX;
            if (param_2[1] == '\0') goto LAB_00415341;
LAB_00415386:
            FUN_00415290();
            if (param_3[1] != '\0') {
              param_1[1] = param_3[1];
            }
            uVar3 = extraout_ECX_00;
            param_6 = extraout_EDX_00;
            if (param_2[2] == '\0') break;
LAB_0041539c:
            FUN_00415290();
            if (param_3[2] != '\0') {
              param_1[2] = param_3[2];
            }
            uVar3 = extraout_ECX_01;
            param_6 = extraout_EDX_01;
            if (param_2[3] == '\0') goto LAB_0041534f;
          }
        }
LAB_0041534f:
        param_1 = param_1 + 4;
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        DAT_004220ae = DAT_004220ae + 4;
        DAT_004220b2 = DAT_004220b2 + 4;
      }
LAB_004153e0:
      if ((DAT_004220aa & 3) != 0) {
        iVar4 = (DAT_004220aa & 3) + 1;
        pcVar5 = param_3;
        pcVar6 = param_1;
        while (param_1 = pcVar6, param_3 = pcVar5, iVar4 = iVar4 + -1, iVar4 != 0) {
          cVar2 = *param_2;
          pcVar5 = param_3 + 1;
          pcVar6 = param_1 + 1;
          param_2 = param_2 + 1;
          DAT_004220ae = DAT_004220ae + 1;
          DAT_004220b2 = DAT_004220b2 + 1;
          if (cVar2 != '\0') {
            FUN_00415290();
            iVar4 = extraout_ECX_03;
            param_6 = extraout_EDX_03;
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
          }
        }
      }
      param_3 = param_3 + iVar1;
      param_1 = param_1 + (param_7 - param_5);
      param_2 = param_2 + (param_8 - param_5);
      DAT_004220ae = DAT_004220ae + iVar1;
      DAT_004220b2 = DAT_004220b2 + iVar1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}


// ==== FUN_00415439 @ 00415439

void __cdecl
FUN_00415439(char *param_1,char *param_2,byte *param_3,uint param_4,int param_5,int param_6,
            int param_7,int param_8,byte param_9,char param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_4 != 0) {
    DAT_004220aa = param_4;
    do {
      for (uVar2 = DAT_004220aa >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        cVar1 = *param_2;
        if ((cVar1 != param_10) && (param_9 <= *param_3)) goto LAB_004154d0;
LAB_0041548c:
        cVar1 = param_2[1];
        if ((cVar1 != param_10) && (param_9 <= param_3[1])) goto LAB_004154e0;
LAB_0041549a:
        cVar1 = param_2[2];
        if ((cVar1 != param_10) && (param_9 <= param_3[2])) goto LAB_004154f1;
        while ((cVar1 = param_2[3], cVar1 != param_10 && (param_9 <= param_3[3]))) {
          while( true ) {
            param_1[3] = cVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_00415514;
            cVar1 = *param_2;
            if ((cVar1 == param_10) || (*param_3 < param_9)) goto LAB_0041548c;
LAB_004154d0:
            *param_1 = cVar1;
            cVar1 = param_2[1];
            if ((cVar1 == param_10) || (param_3[1] < param_9)) goto LAB_0041549a;
LAB_004154e0:
            param_1[1] = cVar1;
            cVar1 = param_2[2];
            if ((cVar1 == param_10) || (param_3[2] < param_9)) break;
LAB_004154f1:
            param_1[2] = cVar1;
            cVar1 = param_2[3];
            if ((cVar1 == param_10) || (param_3[3] < param_9)) goto LAB_004154b6;
          }
        }
LAB_004154b6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_00415514:
      if ((DAT_004220aa & 3) != 0) {
        iVar3 = (DAT_004220aa & 3) + 1;
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


// ==== FUN_00415550 @ 00415550

undefined * FUN_00415550(void)

{
  return &DAT_00421128;
}


// ==== FUN_00415556 @ 00415556

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415556(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  bool bVar13;
  undefined4 uStack_14;
  
  iVar9 = param_1 + _DAT_0042112c;
  iVar6 = param_3 + _DAT_0042112c;
  iVar4 = iVar6;
  iVar2 = param_2 + _DAT_00421130;
  iVar3 = param_4 + _DAT_00421130;
  if (iVar6 < iVar9) {
    iVar4 = iVar9;
    iVar9 = iVar6;
    iVar2 = param_4 + _DAT_00421130;
    iVar3 = param_2 + _DAT_00421130;
  }
  if ((DAT_00421134 <= iVar4) && (iVar9 <= DAT_00421138)) {
    if (iVar2 < iVar3) {
      if (iVar3 < DAT_0042113c) {
        return;
      }
      if (DAT_00421140 < iVar2) {
        return;
      }
      if ((iVar9 < DAT_00421134) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00421134) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00421134,
         DAT_00421140 < iVar2)) {
        return;
      }
      if ((DAT_00421138 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_00421138 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_00421138,
         iVar3 < DAT_0042113c)) {
        return;
      }
      if ((iVar2 < DAT_0042113c) &&
         (iVar9 = (int)(((longlong)(iVar3 - DAT_0042113c) * (longlong)(iVar9 - iVar4)) /
                       (longlong)-(iVar2 - iVar3)) + iVar4, iVar2 = DAT_0042113c,
         DAT_00421138 < iVar9)) {
        return;
      }
      if ((DAT_00421140 < iVar3) &&
         (iVar4 = (int)(((longlong)(DAT_00421140 - iVar2) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar3 - iVar2)) + iVar9, iVar3 = DAT_00421140,
         iVar4 < DAT_00421134)) {
        return;
      }
    }
    else {
      if (DAT_00421140 < iVar3) {
        return;
      }
      if (iVar2 < DAT_0042113c) {
        return;
      }
      if ((iVar9 < DAT_00421134) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00421134) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00421134,
         iVar2 < DAT_0042113c)) {
        return;
      }
      if ((DAT_00421138 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_00421138 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_00421138,
         DAT_00421140 < iVar3)) {
        return;
      }
      if ((iVar3 < DAT_0042113c) &&
         (iVar4 = (int)(((longlong)(iVar2 - DAT_0042113c) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar2 - iVar3)) + iVar9, iVar3 = DAT_0042113c,
         iVar4 < DAT_00421134)) {
        return;
      }
      if ((DAT_00421140 < iVar2) &&
         (iVar9 = (int)(((longlong)(DAT_00421140 - iVar3) * (longlong)(iVar9 - iVar4)) /
                       (longlong)(iVar2 - iVar3)) + iVar4, iVar2 = DAT_00421140,
         DAT_00421138 < iVar9)) {
        return;
      }
    }
    if (iVar9 == iVar4) {
      iVar4 = iVar2;
      if (iVar3 <= iVar2) {
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      puVar10 = (undefined1 *)(DAT_00421144 * iVar4 + iVar9 + _DAT_00421128);
      for (iVar4 = (iVar3 - iVar4) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + DAT_00421144;
      }
    }
    else if (iVar2 == iVar3) {
      uVar7 = (iVar4 - iVar9) + 1;
      puVar11 = (undefined4 *)(DAT_00421144 * iVar2 + iVar9 + _DAT_00421128);
      uVar1 = CONCAT11(param_5,param_5);
      uStack_14 = CONCAT22(uVar1,uVar1);
      uVar5 = (ushort)uVar7;
      if (uVar5 != 0) {
        puVar12 = puVar11;
        if ((uVar7 & 1) != 0) {
          puVar12 = (undefined4 *)((int)puVar11 + 1);
          *(undefined1 *)puVar11 = param_5;
        }
        iVar4 = CONCAT22((short)(uVar7 >> 0x10),uVar5 >> 2);
        if (uVar5 >> 2 != 0) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar12 = uStack_14;
            puVar12 = puVar12 + 1;
          }
        }
        if ((uVar5 >> 1 & 1) != 0) {
          *(undefined2 *)puVar12 = uVar1;
        }
      }
    }
    else {
      DAT_00421148 = DAT_00421144;
      uVar7 = iVar4 - iVar9;
      uVar8 = iVar3 - iVar2;
      if (iVar3 < iVar2) {
        DAT_00421148 = -DAT_00421144;
        uVar8 = -uVar8;
      }
      iVar4 = DAT_00421148;
      if ((short)uVar7 < (short)uVar8) {
        puVar10 = (undefined1 *)(DAT_00421144 * iVar2 + iVar9 + _DAT_00421128);
        uVar7 = (uint)(((ulonglong)uVar7 << 0x20) / (ulonglong)uVar8);
        iVar9 = uVar8 + 1;
        uVar8 = 0x80000000;
        do {
          *puVar10 = param_5;
          bVar13 = CARRY4(uVar8,uVar7);
          uVar8 = uVar8 + uVar7;
          puVar10 = puVar10 + (uint)bVar13 + iVar4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      else {
        iVar3 = (int)(CONCAT44(uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) / (ulonglong)uVar7);
        iVar6 = uVar7 + 1;
        uVar7 = iVar3 * 2 - (uint)(iVar3 < 0);
        uVar8 = 0x80000000;
        puVar10 = (undefined1 *)(DAT_00421144 * iVar2 + iVar9 + _DAT_00421128);
        do {
          while( true ) {
            *puVar10 = param_5;
            bVar13 = CARRY4(uVar8,uVar7);
            uVar8 = uVar8 + uVar7;
            if (bVar13) break;
            iVar6 = iVar6 + -1;
            puVar10 = puVar10 + 1;
            if (iVar6 == 0) {
              return;
            }
          }
          puVar10 = puVar10 + 1 + iVar4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}


// ==== FUN_0041585e @ 0041585e

void __cdecl FUN_0041585e(int param_1,byte *param_2,int param_3)

{
  do {
    *param_2 = *(byte *)(param_1 + (uint)*param_2);
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


// ==== FUN_0041587f @ 0041587f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041587f(void *this,int *param_1,int param_2)

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
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  bool bVar17;
  
  DAT_00422054 = 0x7fffffff;
  DAT_00422058 = 0;
  DAT_0042204c = 0x7fffffff;
  DAT_00422050 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      DAT_00422050 = *piVar10 + _DAT_0042112c;
      if (DAT_00422050 <= DAT_0042204c) {
        DAT_0042204c = DAT_00422050;
      }
      piVar10 = piVar10 + 2;
      iVar2 = *piVar1 + _DAT_00421130;
      if (iVar2 <= DAT_00422054) {
        DAT_00422054 = iVar2;
      }
      if (iVar2 <= DAT_00422058) {
        DAT_00422058 = iVar2;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042204c <= DAT_00421138) && (DAT_00421134 <= DAT_00422050)) &&
        (DAT_00422054 <= DAT_00421140)) && (DAT_0042113c <= DAT_00422058)) {
      if (DAT_00422054 <= DAT_0042113c) {
        DAT_00422054 = DAT_0042113c;
      }
      if (DAT_00421140 <= DAT_00422058) {
        DAT_00422058 = DAT_00421140;
      }
      iVar2 = DAT_00421138 + 1;
      piVar10 = &DAT_0042114c;
      for (iVar4 = ((DAT_00422058 - DAT_00422054) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar2;
        piVar10 = piVar10 + 1;
      }
      puVar14 = &DAT_00421150;
      for (iVar2 = (DAT_00422058 - DAT_00422054) + 1; iVar4 = DAT_00422054, uVar3 = _DAT_00422064,
          0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 2;
      }
      for (; DAT_00422054 = iVar4, _DAT_00422064 = uVar3, 1 < DAT_0042205c;
          DAT_0042205c = DAT_0042205c + -1) {
        iVar5 = param_1[1] + _DAT_00421130;
        iVar7 = param_1[3] + _DAT_00421130;
        iVar2 = *param_1 + _DAT_0042112c;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_0042112c;
        if (iVar7 < iVar5) {
          iVar2 = param_1[2] + _DAT_0042112c;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_0042112c;
        }
        if ((iVar11 <= DAT_00422058) && (iVar4 <= iVar7)) {
          if (iVar11 <= iVar4) {
            iVar2 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar2 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_00422058 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_00422058 - iVar11) * (longlong)(iVar8 - iVar2)) /
                         (longlong)(iVar7 - iVar11)) + iVar2;
            iVar7 = DAT_00422058;
          }
          _DAT_00422060 = &DAT_0042114c + (iVar7 - iVar4) * 2;
          piVar10 = &DAT_0042114c + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar2;
          if (iVar8 < iVar2) {
            _DAT_00422064 = -uVar9;
            if ((int)_DAT_00422064 < iVar4) goto LAB_00415b21;
            iVar7 = -(_DAT_00422064 + 1 >> 1);
            uVar3 = _DAT_00422064 + 1;
            iVar11 = iVar2;
LAB_00415af8:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00415af8;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              if (iVar8 <= *piVar10) {
                *piVar10 = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar2 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_00422064;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_00415b21:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar6 = 0x80000000;
            _DAT_00422064 = uVar3;
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
            _DAT_00422064 = uVar9;
LAB_00415ab6:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              iVar11 = iVar8 + 1;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00415ab6;
              }
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar8) {
                piVar10[1] = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar7 = iVar7 - _DAT_00422064;
              iVar2 = iVar11;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_00422054;
        uVar3 = _DAT_00422064;
      }
      if (DAT_0042204c <= DAT_00421134) {
        DAT_0042204c = DAT_00421134;
      }
      DAT_00422070 = (uint)*(ushort *)this;
      DAT_0042206c = (undefined4 *)((int)this + DAT_00422070 * *(ushort *)((int)this + 2) + 4);
      puVar14 = (undefined4 *)((int)this + 4);
      DAT_00422074 = DAT_00421144 * iVar4 + _DAT_00421128;
      piVar10 = &DAT_0042114c;
      DAT_00422068 = puVar14;
      if (iVar4 <= DAT_00422058) {
        do {
          iVar2 = *piVar10;
          if (*piVar10 <= DAT_00421134) {
            iVar2 = DAT_00421134;
          }
          iVar11 = piVar10[1];
          if (piVar10[1] <= DAT_00421138) {
            iVar11 = DAT_00421138;
          }
          if (iVar2 <= iVar11) {
            uVar9 = (iVar11 - iVar2) + 1;
            puVar15 = (undefined4 *)(DAT_00422074 + iVar2);
            iVar2 = CONCAT22((short)((uint)(iVar2 - DAT_0042204c) >> 0x10),
                             (ushort)(iVar2 - DAT_0042204c) % (ushort)(byte)DAT_00422070);
            puVar12 = (undefined4 *)((int)puVar14 + iVar2);
            iVar2 = iVar2 - DAT_00422070;
            uVar3 = -iVar2;
            if ((int)uVar3 < (int)uVar9) {
              uVar9 = uVar9 + iVar2;
              if ((short)uVar3 != 0) {
                puVar13 = puVar12;
                puVar16 = puVar15;
                if ((uVar3 & 1) != 0) {
                  puVar16 = (undefined4 *)((int)puVar15 + 1);
                  puVar13 = (undefined4 *)((int)puVar12 + 1);
                  *(undefined1 *)puVar15 = *(undefined1 *)puVar12;
                }
                uVar6 = uVar3 >> 2;
                if ((short)uVar6 != 0) {
                  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar16 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar16 = puVar16 + 1;
                  }
                }
                puVar15 = puVar16;
                if ((uVar3 >> 1 & 1) != 0) {
                  puVar15 = (undefined4 *)((int)puVar16 + 2);
                  *(undefined2 *)puVar16 = *(undefined2 *)puVar13;
                }
              }
              if ((int)DAT_00422070 < (int)uVar9) {
                do {
                  uVar3 = DAT_00422070;
                  uVar9 = uVar9 - DAT_00422070;
                  if ((short)DAT_00422070 != 0) {
                    uVar6 = DAT_00422070 >> 1;
                    puVar12 = puVar14;
                    puVar13 = puVar15;
                    if ((DAT_00422070 & 1) != 0) {
                      puVar13 = (undefined4 *)((int)puVar15 + 1);
                      puVar12 = (undefined4 *)((int)puVar14 + 1);
                      *(undefined1 *)puVar15 = *(undefined1 *)puVar14;
                    }
                    uVar3 = uVar3 >> 2;
                    if ((short)uVar3 != 0) {
                      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *puVar13 = *puVar12;
                        puVar12 = puVar12 + 1;
                        puVar13 = puVar13 + 1;
                      }
                    }
                    puVar15 = puVar13;
                    if ((uVar6 & 1) != 0) {
                      puVar15 = (undefined4 *)((int)puVar13 + 2);
                      *(undefined2 *)puVar13 = *(undefined2 *)puVar12;
                    }
                  }
                } while ((int)DAT_00422070 < (int)uVar9);
              }
              if ((short)uVar9 != 0) {
                puVar12 = puVar14;
                puVar13 = puVar15;
                if ((uVar9 & 1) != 0) {
                  puVar13 = (undefined4 *)((int)puVar15 + 1);
                  puVar12 = (undefined4 *)((int)puVar14 + 1);
                  *(undefined1 *)puVar15 = *(undefined1 *)puVar14;
                }
                uVar3 = uVar9 >> 2;
                if ((short)uVar3 != 0) {
                  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *puVar13 = *puVar12;
                    puVar12 = puVar12 + 1;
                    puVar13 = puVar13 + 1;
                  }
                }
                if ((uVar9 >> 1 & 1) != 0) {
                  *(undefined2 *)puVar13 = *(undefined2 *)puVar12;
                }
              }
            }
            else if ((short)uVar9 != 0) {
              puVar13 = puVar12;
              puVar16 = puVar15;
              if ((uVar9 & 1) != 0) {
                puVar16 = (undefined4 *)((int)puVar15 + 1);
                puVar13 = (undefined4 *)((int)puVar12 + 1);
                *(undefined1 *)puVar15 = *(undefined1 *)puVar12;
              }
              uVar3 = uVar9 >> 2;
              if ((short)uVar3 != 0) {
                for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                  *puVar16 = *puVar13;
                  puVar13 = puVar13 + 1;
                  puVar16 = puVar16 + 1;
                }
              }
              if ((uVar9 >> 1 & 1) != 0) {
                *(undefined2 *)puVar16 = *(undefined2 *)puVar13;
              }
            }
          }
          DAT_00422074 = DAT_00422074 + DAT_00421144;
          piVar10 = piVar10 + 2;
          puVar14 = (undefined4 *)((int)puVar14 + DAT_00422070);
          if (DAT_0042206c <= puVar14) {
            puVar14 = DAT_00422068;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_00422058);
      }
    }
  }
  return;
}


// ==== FUN_00415cc6 @ 00415cc6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415cc6(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_00422054 = 0x7fffffff;
  DAT_00422058 = 0;
  DAT_0042204c = 0x7fffffff;
  DAT_00422050 = 0;
  if (param_2 != 0) {
    piVar12 = param_1;
    do {
      piVar1 = piVar12 + 1;
      iVar3 = *piVar12 + _DAT_0042112c;
      if (iVar3 <= DAT_0042204c) {
        DAT_0042204c = iVar3;
      }
      if (DAT_00422050 <= iVar3) {
        DAT_00422050 = iVar3;
      }
      piVar12 = piVar12 + 2;
      iVar3 = *piVar1 + _DAT_00421130;
      if (iVar3 <= DAT_00422054) {
        DAT_00422054 = iVar3;
      }
      if (DAT_00422058 <= iVar3) {
        DAT_00422058 = iVar3;
      }
    } while ((int)piVar12 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042204c <= DAT_00421138) && (DAT_00421134 <= DAT_00422050)) &&
        (DAT_00422054 <= DAT_00421140)) && (DAT_0042113c <= DAT_00422058)) {
      if (DAT_00422054 <= DAT_0042113c) {
        DAT_00422054 = DAT_0042113c;
      }
      if (DAT_00421140 <= DAT_00422058) {
        DAT_00422058 = DAT_00421140;
      }
      iVar3 = DAT_00421138 + 1;
      piVar12 = &DAT_0042114c;
      for (iVar4 = ((DAT_00422058 - DAT_00422054) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = iVar3;
        piVar12 = piVar12 + 1;
      }
      puVar13 = &DAT_00421150;
      for (iVar3 = (DAT_00422058 - DAT_00422054) + 1; DAT_0042205c = param_2, iVar4 = DAT_00422054,
          uVar6 = _DAT_00422064, 0 < iVar3; iVar3 = iVar3 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 2;
      }
      for (; DAT_00422054 = iVar4, _DAT_00422064 = uVar6, 1 < DAT_0042205c;
          DAT_0042205c = DAT_0042205c + -1) {
        iVar5 = param_1[1] + _DAT_00421130;
        iVar7 = param_1[3] + _DAT_00421130;
        iVar3 = *param_1 + _DAT_0042112c;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_0042112c;
        if (iVar7 < iVar5) {
          iVar3 = param_1[2] + _DAT_0042112c;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_0042112c;
        }
        if ((iVar11 <= DAT_00422058) && (iVar4 <= iVar7)) {
          if (iVar11 < iVar4) {
            iVar3 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar3 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_00422058 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_00422058 - iVar11) * (longlong)(iVar8 - iVar3)) /
                         (longlong)(iVar7 - iVar11)) + iVar3;
            iVar7 = DAT_00422058;
          }
          _DAT_00422060 = &DAT_0042114c + (iVar7 - iVar4) * 2;
          piVar12 = &DAT_0042114c + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            _DAT_00422064 = -uVar9;
            if ((int)_DAT_00422064 < iVar4) goto LAB_00415f6d;
            iVar7 = -(_DAT_00422064 + 1 >> 1);
            uVar6 = _DAT_00422064 + 1;
            iVar11 = iVar3;
LAB_00415f44:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00415f44;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              if (iVar8 <= *piVar12) {
                *piVar12 = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar3 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_00422064;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_00415f6d:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar10 = 0x80000000;
            _DAT_00422064 = uVar6;
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
            _DAT_00422064 = uVar9;
LAB_00415f02:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              iVar11 = iVar8 + 1;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_00415f02;
              }
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar8) {
                piVar12[1] = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar7 = iVar7 - _DAT_00422064;
              iVar3 = iVar11;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_00422054;
        uVar6 = _DAT_00422064;
      }
      iVar3 = DAT_00421144 * iVar4 + _DAT_00421128;
      piVar12 = &DAT_0042114c;
      uVar2 = CONCAT11(param_3,param_3);
      uStack_14 = CONCAT22(uVar2,uVar2);
      if (iVar4 <= DAT_00422058) {
        do {
          iVar11 = *piVar12;
          if (*piVar12 <= DAT_00421134) {
            iVar11 = DAT_00421134;
          }
          iVar7 = piVar12[1];
          if (piVar12[1] <= DAT_00421138) {
            iVar7 = DAT_00421138;
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
          iVar3 = iVar3 + DAT_00421144;
          piVar12 = piVar12 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_00422058);
      }
    }
  }
  return;
}


// ==== FUN_00416038 @ 00416038

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00416038(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_00422054 = 0x7fffffff;
  DAT_00422058 = 0;
  DAT_0042204c = 0x7fffffff;
  DAT_00422050 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      iVar3 = *piVar10 + _DAT_0042112c;
      if (iVar3 <= DAT_0042204c) {
        DAT_0042204c = iVar3;
      }
      if (DAT_00422050 <= iVar3) {
        DAT_00422050 = iVar3;
      }
      piVar10 = piVar10 + 2;
      iVar3 = *piVar1 + _DAT_00421130;
      if (iVar3 <= DAT_00422054) {
        DAT_00422054 = iVar3;
      }
      if (DAT_00422058 <= iVar3) {
        DAT_00422058 = iVar3;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042204c <= DAT_00421138) && (DAT_00421134 <= DAT_00422050)) &&
        (DAT_00422054 <= DAT_00421140)) && (DAT_0042113c <= DAT_00422058)) {
      if (DAT_00422054 <= DAT_0042113c) {
        DAT_00422054 = DAT_0042113c;
      }
      if (DAT_00421140 <= DAT_00422058) {
        DAT_00422058 = DAT_00421140;
      }
      iVar3 = DAT_00421138 + 1;
      piVar10 = &DAT_0042114c;
      for (iVar4 = ((DAT_00422058 - DAT_00422054) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar3;
        piVar10 = piVar10 + 1;
      }
      iVar3 = (DAT_00422058 - DAT_00422054) + 1;
      puVar12 = &DAT_00421150;
      iVar4 = iVar3;
      while (iVar11 = iVar3, DAT_0042205c = param_2, iVar3 = DAT_00422054, uVar2 = _DAT_00422064,
            0 < iVar4) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 2;
        iVar3 = iVar11 + -1;
        iVar4 = iVar11;
      }
      for (; DAT_00422054 = iVar3, _DAT_00422064 = uVar2, 1 < DAT_0042205c;
          DAT_0042205c = DAT_0042205c + -1) {
        iVar5 = param_1[1] + _DAT_00421130;
        iVar6 = param_1[3] + _DAT_00421130;
        iVar4 = *param_1 + _DAT_0042112c;
        iVar11 = iVar5;
        iVar7 = param_1[2] + _DAT_0042112c;
        if (iVar6 < iVar5) {
          iVar4 = param_1[2] + _DAT_0042112c;
          iVar11 = iVar6;
          iVar6 = iVar5;
          iVar7 = *param_1 + _DAT_0042112c;
        }
        if ((iVar11 <= DAT_00422058) && (iVar3 <= iVar6)) {
          if (iVar11 < iVar3) {
            iVar4 = (int)(((longlong)(iVar6 - iVar3) * (longlong)(iVar4 - iVar7)) /
                         (longlong)(iVar6 - iVar11)) + iVar7;
            iVar11 = iVar3;
          }
          if (DAT_00422058 < iVar6) {
            iVar7 = (int)(((longlong)(DAT_00422058 - iVar11) * (longlong)(iVar7 - iVar4)) /
                         (longlong)(iVar6 - iVar11)) + iVar4;
            iVar6 = DAT_00422058;
          }
          _DAT_00422060 = &DAT_0042114c + (iVar6 - iVar3) * 2;
          piVar10 = &DAT_0042114c + (iVar11 - iVar3) * 2;
          iVar3 = (iVar6 - iVar3) - (iVar11 - iVar3);
          uVar8 = iVar7 - iVar4;
          if (iVar7 < iVar4) {
            _DAT_00422064 = -uVar8;
            if ((int)_DAT_00422064 < iVar3) goto LAB_004162dc;
            iVar6 = -(_DAT_00422064 + 1 >> 1);
            uVar2 = _DAT_00422064 + 1;
            iVar11 = iVar4;
LAB_004162b3:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              iVar11 = iVar7 + -1;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_004162b3;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              if (iVar7 <= *piVar10) {
                *piVar10 = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar4 = iVar7 + -1;
              iVar6 = iVar6 - _DAT_00422064;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
          else if ((int)uVar8 < iVar3) {
LAB_004162dc:
            iVar11 = (int)(CONCAT44((int)uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) /
                          (longlong)iVar3);
            uVar8 = iVar11 * 2;
            iVar3 = iVar3 + 1;
            uVar9 = 0x80000000;
            _DAT_00422064 = uVar2;
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
            _DAT_00422064 = uVar8;
LAB_00416271:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              iVar11 = iVar7 + 1;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_00416271;
              }
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar7) {
                piVar10[1] = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar6 = iVar6 - _DAT_00422064;
              iVar4 = iVar11;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
        }
        param_1 = param_1 + 2;
        iVar3 = DAT_00422054;
        uVar2 = _DAT_00422064;
      }
      if (DAT_0042204c <= DAT_00421134) {
        DAT_0042204c = DAT_00421134;
      }
      DAT_00422074 = DAT_00421144 * iVar3 + _DAT_00421128;
      piVar10 = &DAT_0042114c;
      if (iVar3 <= DAT_00422058) {
        do {
          iVar4 = *piVar10;
          if (*piVar10 <= DAT_00421134) {
            iVar4 = DAT_00421134;
          }
          iVar11 = piVar10[1];
          if (DAT_00421138 <= piVar10[1]) {
            iVar11 = DAT_00421138;
          }
          if (iVar4 <= iVar11) {
            puVar13 = (undefined1 *)(DAT_00422074 + iVar4);
            for (iVar11 = (iVar11 - iVar4) + 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar13 = param_3;
              puVar13 = puVar13 + 1;
            }
          }
          DAT_00422074 = DAT_00422074 + DAT_00421144;
          piVar10 = piVar10 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= DAT_00422058);
      }
    }
  }
  return;
}


// ==== FUN_004163ae @ 004163ae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004163ae(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  char *pcVar11;
  bool bVar12;
  
  DAT_00422088 = '\0';
  if ((int)param_3 < 0) {
    DAT_00422088 = '\x01';
    param_3 = -param_3;
  }
  else if (param_3 == 0) {
    param_3 = 1;
  }
  DAT_00422089 = '\0';
  if ((int)param_4 < 0) {
    DAT_00422089 = '\x01';
    param_4 = -param_4;
  }
  else if (param_4 == 0) {
    param_4 = 1;
  }
  uVar4 = *param_5 / param_3;
  uVar1 = ((ulonglong)(uint)*param_5 % (ulonglong)param_3 << 0x20) / (ulonglong)param_3;
  uVar5 = (uint)uVar1;
  DAT_00422096 = param_5[1] / param_4;
  uVar2 = ((ulonglong)(uint)param_5[1] % (ulonglong)param_4 << 0x20) / (ulonglong)param_4;
  DAT_00422092 = (uint)uVar2;
  DAT_004220a2 = (uint)*param_5;
  iVar6 = param_1 + _DAT_0042112c;
  iVar8 = param_3 + iVar6 + -1;
  iVar7 = param_2 + _DAT_00421130;
  DAT_00422084 = param_4 + iVar7 + -1;
  DAT_00422080 = iVar7;
  DAT_0042208a = uVar5;
  DAT_0042208e = uVar4;
  if ((((iVar6 <= DAT_00421138) && (DAT_00421134 <= iVar8)) && (iVar7 <= DAT_00421140)) &&
     (DAT_0042113c <= DAT_00422084)) {
    DAT_0042209a = 0;
    _DAT_0042209e = 0;
    puVar10 = param_5 + 2;
    DAT_00422078 = iVar6;
    if ((iVar6 < DAT_00421134) && (DAT_00422078 = DAT_00421134, DAT_00422088 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar6 - DAT_00421134) * (uVar1 & 0xffffffff);
      DAT_0042209a = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + -(iVar6 - DAT_00421134) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    DAT_0042207c = iVar8;
    if ((DAT_00421138 < iVar8) && (DAT_0042207c = DAT_00421138, DAT_00422088 != '\0')) {
      lVar3 = (ulonglong)(uint)(iVar8 - DAT_00421138) * (uVar1 & 0xffffffff);
      DAT_0042209a = DAT_0042209a + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + (iVar8 - DAT_00421138) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    if ((iVar7 < DAT_0042113c) && (DAT_00422080 = DAT_0042113c, DAT_00422089 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar7 - DAT_0042113c) * (uVar2 & 0xffffffff);
      _DAT_0042209e = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                (-(iVar7 - DAT_0042113c) * DAT_00422096 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_004220a2);
    }
    iVar6 = DAT_00422084;
    if ((DAT_00421140 < DAT_00422084) && (iVar6 = DAT_00421140, DAT_00422089 == '\0')) {
      lVar3 = (ulonglong)(uint)(DAT_00422084 - DAT_00421140) * (uVar2 & 0xffffffff);
      _DAT_0042209e = _DAT_0042209e + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                ((DAT_00422084 - DAT_00421140) * DAT_00422096 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_004220a2);
    }
    DAT_00422096 = DAT_00422096 * DAT_004220a2;
    DAT_00422084 = iVar6;
    if (DAT_00422088 != '\0') {
      DAT_004220a6 = puVar10;
      if (DAT_00422089 == '\0') {
        DAT_00422074 = (char *)(DAT_00421144 * DAT_00422080 + DAT_0042207c + _DAT_00421128);
        DAT_0042207c = DAT_0042207c - (DAT_00422078 + -1);
        DAT_00422084 = iVar6 - (DAT_00422080 + -1);
        iVar6 = DAT_0042207c;
        uVar9 = DAT_0042209a;
        pcVar11 = DAT_00422074;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_00422084;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_0042209e,DAT_00422092);
          _DAT_0042209e = _DAT_0042209e + DAT_00422092;
          if (bVar12) {
            DAT_004220a6 = (ushort *)((int)DAT_004220a6 + DAT_004220a2);
          }
          puVar10 = (ushort *)((int)DAT_004220a6 + DAT_00422096);
          DAT_00422074 = DAT_00422074 + DAT_00421144;
          DAT_00422084 = DAT_00422084 + -1;
          iVar6 = DAT_0042207c;
          uVar9 = DAT_0042209a;
          pcVar11 = DAT_00422074;
          DAT_004220a6 = puVar10;
        } while (DAT_00422084 != 0 && 0 < iVar7);
      }
      else {
        DAT_00422074 = (char *)(DAT_00421144 * iVar6 + DAT_0042207c + _DAT_00421128);
        DAT_0042207c = DAT_0042207c - (DAT_00422078 + -1);
        DAT_00422084 = iVar6 - (DAT_00422080 + -1);
        iVar6 = DAT_0042207c;
        uVar9 = DAT_0042209a;
        pcVar11 = DAT_00422074;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_00422084;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_0042209e,DAT_00422092);
          _DAT_0042209e = _DAT_0042209e + DAT_00422092;
          if (bVar12) {
            DAT_004220a6 = (ushort *)((int)DAT_004220a6 + DAT_004220a2);
          }
          puVar10 = (ushort *)((int)DAT_004220a6 + DAT_00422096);
          DAT_00422074 = DAT_00422074 + -DAT_00421144;
          DAT_00422084 = DAT_00422084 + -1;
          iVar6 = DAT_0042207c;
          uVar9 = DAT_0042209a;
          pcVar11 = DAT_00422074;
          DAT_004220a6 = puVar10;
        } while (DAT_00422084 != 0 && 0 < iVar7);
      }
    }
    uVar5 = DAT_0042208e;
    uVar4 = DAT_0042208a;
    if (DAT_00422089 != '\0') {
      DAT_00422074 = (char *)(DAT_00421144 * DAT_00422084 + DAT_00422078 + _DAT_00421128);
      DAT_0042207c = DAT_0042207c - (DAT_00422078 + -1);
      DAT_00422084 = DAT_00422084 - (DAT_00422080 + -1);
      iVar6 = DAT_0042207c;
      uVar9 = DAT_0042209a;
      pcVar11 = DAT_00422074;
      DAT_004220a6 = puVar10;
      do {
        do {
          if ((char)*puVar10 != '\0') {
            *pcVar11 = (char)*puVar10;
          }
          iVar7 = DAT_00422084;
          puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
          iVar6 = iVar6 + -1;
          uVar9 = uVar9 + uVar4;
          pcVar11 = pcVar11 + 1;
        } while (iVar6 != 0);
        bVar12 = CARRY4(_DAT_0042209e,DAT_00422092);
        _DAT_0042209e = _DAT_0042209e + DAT_00422092;
        if (bVar12) {
          DAT_004220a6 = (ushort *)((int)DAT_004220a6 + DAT_004220a2);
        }
        puVar10 = (ushort *)((int)DAT_004220a6 + DAT_00422096);
        DAT_00422074 = DAT_00422074 + -DAT_00421144;
        DAT_00422084 = DAT_00422084 + -1;
        iVar6 = DAT_0042207c;
        uVar9 = DAT_0042209a;
        pcVar11 = DAT_00422074;
        DAT_004220a6 = puVar10;
      } while (DAT_00422084 != 0 && 0 < iVar7);
    }
    uVar5 = DAT_0042208e;
    uVar4 = DAT_0042208a;
    DAT_00422074 = (char *)(DAT_00421144 * DAT_00422080 + DAT_00422078 + _DAT_00421128);
    DAT_0042207c = DAT_0042207c - (DAT_00422078 + -1);
    DAT_00422084 = DAT_00422084 - (DAT_00422080 + -1);
    iVar6 = DAT_0042207c;
    uVar9 = DAT_0042209a;
    pcVar11 = DAT_00422074;
    DAT_004220a6 = puVar10;
    do {
      do {
        if ((char)*puVar10 != '\0') {
          *pcVar11 = (char)*puVar10;
        }
        iVar7 = DAT_00422084;
        puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
        iVar6 = iVar6 + -1;
        uVar9 = uVar9 + uVar4;
        pcVar11 = pcVar11 + 1;
      } while (iVar6 != 0);
      bVar12 = CARRY4(_DAT_0042209e,DAT_00422092);
      _DAT_0042209e = _DAT_0042209e + DAT_00422092;
      if (bVar12) {
        DAT_004220a6 = (ushort *)((int)DAT_004220a6 + DAT_004220a2);
      }
      puVar10 = (ushort *)((int)DAT_004220a6 + DAT_00422096);
      DAT_00422074 = DAT_00422074 + DAT_00421144;
      DAT_00422084 = DAT_00422084 + -1;
      iVar6 = DAT_0042207c;
      uVar9 = DAT_0042209a;
      pcVar11 = DAT_00422074;
      DAT_004220a6 = puVar10;
    } while (DAT_00422084 != 0 && 0 < iVar7);
  }
  return;
}


// ==== FUN_0041689b @ 0041689b

void __cdecl FUN_0041689b(undefined4 *param_1,undefined4 *param_2,uint param_3)

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


// ==== FUN_004168c8 @ 004168c8

undefined8 __cdecl FUN_004168c8(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_004169b3 @ 004169b3

undefined4 __cdecl FUN_004169b3(int *param_1,int *param_2)

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


// ==== FUN_004169ef @ 004169ef

void __cdecl FUN_004169ef(int *param_1,int *param_2)

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


// ==== FUN_00416a4c @ 00416a4c

void __cdecl FUN_00416a4c(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_00416aa2 @ 00416aa2

undefined4 __cdecl FUN_00416aa2(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004169b3(param_3,param_2);
  if (iVar1 != 0) {
    FUN_00416a4c(&DAT_004220b8,param_2,param_3);
    DAT_004220c8 = ((param_2[2] - *param_2) + 1U & 0xffff) *
                   ((param_2[3] - param_2[1]) + 1U & 0xffff);
    if (((DAT_004220c0 - DAT_004220b8) + 1U & 0xffff) *
        ((DAT_004220c4 - DAT_004220bc) + 1U & 0xffff) <=
        ((param_3[2] - *param_3) + 1U & 0xffff) * ((param_3[3] - param_3[1]) + 1U & 0xffff) +
        DAT_004220c8) {
      *param_1 = DAT_004220b8;
      param_1[1] = DAT_004220bc;
      param_1[2] = DAT_004220c0;
      param_1[3] = DAT_004220c4;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00416b7b @ 00416b7b

int __cdecl FUN_00416b7b(int *param_1)

{
  return (param_1[2] - *param_1) + 1;
}


// ==== FUN_00416b8b @ 00416b8b

int __cdecl FUN_00416b8b(int param_1)

{
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) + 1;
}


// ==== FUN_00416b9c @ 00416b9c

void __cdecl FUN_00416b9c(char *param_1,uint param_2,char param_3)

{
  uint uVar1;
  char *pcVar2;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (*param_1 == param_3) goto LAB_00416be2;
LAB_00416bbe:
    if (param_1[1] == param_3) goto LAB_00416beb;
LAB_00416bc5:
    if (param_1[2] == param_3) goto LAB_00416bf5;
    while (param_1[3] == param_3) {
      while( true ) {
        param_1[3] = '\0';
        param_1 = param_1 + 4;
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) goto LAB_00416c0c;
        if (*param_1 != param_3) goto LAB_00416bbe;
LAB_00416be2:
        *param_1 = '\0';
        if (param_1[1] != param_3) goto LAB_00416bc5;
LAB_00416beb:
        param_1[1] = '\0';
        if (param_1[2] != param_3) break;
LAB_00416bf5:
        param_1[2] = '\0';
        if (param_1[3] != param_3) goto LAB_00416bd3;
      }
    }
LAB_00416bd3:
    param_1 = param_1 + 4;
  }
LAB_00416c0c:
  uVar1 = param_2 & 3;
  do {
    if (uVar1 == 0) {
      return;
    }
    do {
      pcVar2 = param_1;
      param_1 = pcVar2 + 1;
      if (*pcVar2 == param_3) break;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
    *pcVar2 = '\0';
    uVar1 = uVar1 - 1;
  } while( true );
}


// ==== FUN_00416c28 @ 00416c28

bool __cdecl FUN_00416c28(char *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  *param_4 = param_2;
  param_4[2] = 0xffffffff;
  param_4[1] = param_3;
  param_4[3] = 0xffffffff;
  uVar2 = 0;
LAB_00416c53:
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
          if (param_3 != 0) goto LAB_00416c53;
          goto LAB_00416c8c;
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
LAB_00416c8c:
      return *param_4 != param_2;
    }
  } while( true );
}


// ==== FUN_00416ca0 @ 00416ca0

void __cdecl FUN_00416ca0(int param_1,int param_2,short *param_3,short *param_4)

{
  undefined8 uVar1;
  int local_64 [3];
  int local_58;
  int local_54;
  char *local_50;
  int local_4c;
  uint local_48;
  char *local_44;
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
    local_64[2] = (int)*param_4;
    local_58 = (int)param_4[1];
    if ((local_1c != 0) && (((local_24 != 0 && (local_64[2] != 0)) && (local_58 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = local_1c + param_1;
      local_34 = param_2 + local_24;
      local_64[0] = 0;
      local_64[1] = 0;
      local_30 = local_58;
      local_2c = local_64[2];
      uVar1 = FUN_004168c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_3 + local_1c * local_4c + local_20 + 4);
        local_44 = (char *)((int)param_4 + local_10 * local_2c + local_14 + 4);
        FUN_00414ea0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_00416e0f @ 00416e0f

void __cdecl FUN_00416e0f(int param_1,int param_2,short *param_3,short *param_4)

{
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    FUN_00414ea0((char *)((int)param_4 + param_1 + *param_4 * param_2 + 4),(char *)(param_3 + 2),
                 (int)*param_3,(int)param_3[1],(int)*param_4,(int)*param_3,0);
  }
  return;
}


// ==== FUN_00416eaa @ 00416eaa

void __cdecl FUN_00416eaa(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

{
  undefined8 uVar1;
  int local_64 [3];
  int local_58;
  int local_54;
  char *local_50;
  int local_4c;
  uint local_48;
  char *local_44;
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
  
  if (((param_4 != (short *)0x0) && (param_5 != (short *)0x0)) && (param_3 != (int *)0x0)) {
    local_1c = (int)*param_4;
    local_24 = (int)param_4[1];
    local_2c = (int)*param_5;
    local_30 = (int)param_5[1];
    if (((local_1c != 0) && (local_24 != 0)) && ((local_2c != 0 && (local_30 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = FUN_00416b7b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_00416b8b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_004168c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (char *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_00414ea0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_00417039 @ 00417039

void __cdecl FUN_00417039(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

{
  undefined8 uVar1;
  int local_64 [3];
  int local_58;
  int local_54;
  undefined4 *local_50;
  int local_4c;
  uint local_48;
  undefined4 *local_44;
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
      local_38 = FUN_00416b7b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_00416b8b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_004168c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_00414f5c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_004171ba @ 004171ba

void __cdecl FUN_004171ba(int param_1,int param_2,int param_3,short *param_4,short *param_5)

{
  undefined8 uVar1;
  int local_64 [3];
  int local_58;
  int local_54;
  undefined4 *local_50;
  int local_4c;
  uint local_48;
  undefined4 *local_44;
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
    local_64[2] = (int)*param_5;
    local_58 = (int)*param_5;
    if (((local_1c != 0) && (local_24 != 0)) && ((local_64[2] != 0 && (local_58 != 0)))) {
      local_40 = param_1;
      local_3c = param_2;
      local_38 = local_1c + param_1;
      local_34 = param_2 + local_24;
      local_64[0] = 0;
      local_64[1] = 0;
      local_30 = local_58;
      local_2c = local_64[2];
      uVar1 = FUN_004168c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_1c * local_4c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_00414f5c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_0041732f @ 0041732f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0041732f(void *this,int param_1,int param_2)

{
  bool bVar1;
  undefined1 uVar2;
  
  if (*(int *)this == 0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      _DAT_004220d0 = 0;
      DAT_004220d0 = 0;
      uVar2 = DAT_004220d0;
    }
    else {
      if (*(int *)this != 0) {
        if (*(int *)this == 0) {
          bVar1 = false;
        }
        else if (**(short **)this == 0x400) {
          if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
              *(int *)(*(int *)this + 2) == 0) {
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
          return *(undefined1 *)(**(short **)this * param_2 + *(int *)this + 4 + param_1);
        }
      }
      uVar2 = *(undefined1 *)(*(int *)this + 4 + param_1);
    }
  }
  return uVar2;
}


// ==== FUN_004174c6 @ 004174c6

bool __fastcall FUN_004174c6(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_00417500 @ 00417500

bool __fastcall FUN_00417500(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_0041753a @ 0041753a

void __thiscall FUN_0041753a(void *this,int param_1)

{
  bool bVar1;
  
  if (*(int *)this != 0) {
    if (param_1 == 0) {
      if (*(int *)this == 0) {
        bVar1 = false;
      }
      else if (**(short **)this == 0x400) {
        if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
            *(int *)(*(int *)this + 2) == 0) {
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
        FUN_00414ce8(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_0041270f(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(short **)this,0);
      }
    }
    else {
      if (*(int *)this == 0) {
        bVar1 = false;
      }
      else if (**(short **)this == 0x400) {
        if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
            *(int *)(*(int *)this + 2) == 0) {
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
        FUN_00414b31(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_00411260(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_0041775a @ 0041775a

void __thiscall FUN_0041775a(void *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (*(int *)this != 0) {
    if (param_3 == 0) {
      if (*(int *)this == 0) {
        bVar1 = false;
      }
      else if (**(short **)this == 0x400) {
        if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
            *(int *)(*(int *)this + 2) == 0) {
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
        FUN_00414ce8(&DAT_0042a610,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_0041270f(&DAT_0042a610,param_1,param_2,*(short **)this,0);
      }
    }
    else {
      if (*(int *)this == 0) {
        bVar1 = false;
      }
      else if (**(short **)this == 0x400) {
        if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
            *(int *)(*(int *)this + 2) == 0) {
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
        FUN_00414b31(&DAT_0042a610,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_00411260(&DAT_0042a610,param_1,param_2,*(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_00417932 @ 00417932

void __thiscall FUN_00417932(void *this,int *param_1,int param_2)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_2 != 0) {
    FUN_00410d03(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),param_1,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_00417a4e:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00417a4e;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_14 = (int)*(short *)(*(int *)this + 2);
      goto LAB_00417b04;
    }
  }
  local_14 = 0;
LAB_00417b04:
  FUN_004105e5(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),local_c,local_14,param_1,-1);
  return;
}


// ==== FUN_00417b64 @ 00417b64

void __thiscall FUN_00417b64(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_4 != 0) {
    FUN_00410d03(&DAT_0042a610,param_1,param_2,param_1,param_2,param_3,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_00417c5c:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00417c5c;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_14 = (int)*(short *)(*(int *)this + 2);
      goto LAB_00417d12;
    }
  }
  local_14 = 0;
LAB_00417d12:
  FUN_004105e5(&DAT_0042a610,param_1,param_2,param_1,param_2,local_c,local_14,param_3,-1);
  return;
}


// ==== FUN_00417d4e @ 00417d4e

void __thiscall FUN_00417d4e(void *this,int param_1)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_00417e08:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00417e08;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_14 = (int)*(short *)(*(int *)this + 2);
      goto LAB_00417ebe;
    }
  }
  local_14 = 0;
LAB_00417ebe:
  FUN_004199d8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28) + local_c + -1,*(int *)((int)this + 0x2c) + local_14 + -1,
               0);
  FUN_0041753a(this,param_1);
  return;
}


// ==== FUN_00417f0c @ 00417f0c

void __thiscall FUN_00417f0c(void *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_00417fc6:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00417fc6;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_14 = (int)*(short *)(*(int *)this + 2);
      goto LAB_0041807c;
    }
  }
  local_14 = 0;
LAB_0041807c:
  FUN_004199d8((void *)((int)this + 0x40),param_1,param_2,param_1 + local_c + -1,
               param_2 + local_14 + -1,0);
  FUN_0041775a(this,param_1,param_2,param_3);
  return;
}


// ==== FUN_004180c1 @ 004180c1

void __thiscall FUN_004180c1(void *this,int param_1)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
    bVar1 = false;
  }
  else if (**(short **)this == 0x400) {
    if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
        *(int *)(*(int *)this + 2) == 0) {
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
    if (param_1 == 0) {
      FUN_00411bfe(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
      return;
    }
    FUN_0041173c(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                 (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                 (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_00418388:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00418388;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_8 = (int)*(short *)(*(int *)this + 2);
      goto LAB_00418453;
    }
  }
  local_8 = 0;
LAB_00418453:
  DAT_0042abc4 = operator_new(local_8 * local_c + 4);
  if (DAT_0042abc4 != (short *)0x0) {
    *DAT_0042abc4 = (short)local_c;
    DAT_0042abc4[1] = (short)local_8;
    _memset(DAT_0042abc4 + 2,0,local_8 * local_c);
    if (param_1 == 0) {
      FUN_00411bfe(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_0042abc4,0);
    }
    else {
      FUN_0041173c(&DAT_0042a610,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_0042abc4,0);
    }
    FUN_0041b6d0(DAT_0042abc4);
  }
  DAT_0042abc4 = (short *)0x0;
  return;
}


// ==== FUN_00418652 @ 00418652

void __thiscall FUN_00418652(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
    bVar1 = false;
  }
  else if (**(short **)this == 0x400) {
    if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
        *(int *)(*(int *)this + 2) == 0) {
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
    if (param_4 == 0) {
      FUN_00411bfe(&DAT_0042a610,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,*(short **)this,0);
      return;
    }
    FUN_0041173c(&DAT_0042a610,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                 (param_3[3] - param_3[1]) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041886b:
    local_c = 0;
  }
  else {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041886b;
    local_c = (int)**(short **)this;
  }
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      bVar1 = false;
    }
    else if (**(short **)this == 0x400) {
      if ((int)*(short *)(*(int *)this + 6) * (int)*(short *)(*(int *)this + 8) -
          *(int *)(*(int *)this + 2) == 0) {
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
      local_8 = (int)*(short *)(*(int *)this + 2);
      goto LAB_00418921;
    }
  }
  local_8 = 0;
LAB_00418921:
  DAT_0042abc4 = operator_new(local_8 * local_c + 4);
  if (DAT_0042abc4 != (short *)0x0) {
    *DAT_0042abc4 = (short)local_c;
    DAT_0042abc4[1] = (short)local_8;
    _memset(DAT_0042abc4 + 2,0,local_8 * local_c);
    if (param_4 == 0) {
      FUN_00411bfe(&DAT_0042a610,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_0042abc4,0);
    }
    else {
      FUN_0041173c(&DAT_0042a610,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_0042abc4,0);
    }
    FUN_0041b6d0(DAT_0042abc4);
  }
  DAT_0042abc4 = (short *)0x0;
  return;
}


// ==== FUN_00418a9c @ 00418a9c

void __thiscall FUN_00418a9c(void *this,int param_1)

{
  FUN_004199d8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               (*(int *)((int)this + 0x38) + *(int *)((int)this + 0x28)) -
               *(int *)((int)this + 0x30),
               (*(int *)((int)this + 0x3c) + *(int *)((int)this + 0x2c)) -
               *(int *)((int)this + 0x34),0);
  FUN_004180c1(this,param_1);
  return;
}


// ==== FUN_00418b01 @ 00418b01

void __thiscall FUN_00418b01(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  FUN_004199d8((void *)((int)this + 0x40),param_1,param_2,(param_3[2] + param_1) - *param_3,
               (param_3[3] + param_2) - param_3[1],0);
  FUN_00418652(this,param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00418b70 @ 00418b70

void FUN_00418b70(void)

{
  FUN_00418b8a();
  FUN_00418ba9();
  return;
}


// ==== FUN_00418b8a @ 00418b8a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00418b8a(void)

{
  _DAT_0042abc8 = 0x5452494d;
  return;
}


// ==== FUN_00418ba9 @ 00418ba9

void FUN_00418ba9(void)

{
  _atexit(FUN_00418bc6);
  return;
}


// ==== FUN_00418bc6 @ 00418bc6

void FUN_00418bc6(void)

{
  FUN_00418d58();
  return;
}


// ==== FUN_00418be0 @ 00418be0

bool __cdecl FUN_00418be0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0040fe82(&DAT_0042a610,param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_0041acf0();
    *puVar2 = DAT_0042a618;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = DAT_0042a61c + -1;
    puVar2[5] = 0;
    puVar2[6] = DAT_0042a620 + -1;
    puVar2[7] = DAT_0042a624;
  }
  return iVar1 != 0;
}


// ==== FUN_00418c9f @ 00418c9f

undefined4 * __cdecl FUN_00418c9f(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0041acf0();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0041acf0();
  *puVar1 = DAT_0042a618;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = DAT_0042a61c + -1;
  puVar1[5] = 0;
  puVar1[6] = DAT_0042a620 + -1;
  puVar1[7] = DAT_0042a624;
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_00418d58 @ 00418d58

void FUN_00418d58(void)

{
  FUN_004101d0(&DAT_0042a610);
  return;
}


// ==== FUN_00418d77 @ 00418d77

void __cdecl FUN_00418d77(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00418da0 @ 00418da0

void __cdecl FUN_00418da0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00418dc9 @ 00418dc9

uint __cdecl FUN_00418dc9(int param_1)

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


// ==== FUN_00418e43 @ 00418e43

uint __cdecl FUN_00418e43(int param_1)

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


// ==== FUN_00418ebe @ 00418ebe

uint __cdecl FUN_00418ebe(int param_1)

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


// ==== FUN_00418f4d @ 00418f4d

int __cdecl FUN_00418f4d(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_10;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(short *)(param_1 + 6) == 0) {
    iVar2 = param_1 + 0xc;
  }
  else if (*(short *)(param_1 + 6) == 2) {
    if (*(int *)(param_1 + 0x18) == 3) {
      iVar2 = *piVar1 + 0xc + (int)piVar1;
    }
    else {
      if ((*(int *)(param_1 + 0x28) == 0) && (*(ushort *)(param_1 + 0x16) < 9)) {
        local_10 = 1 << (*(byte *)(param_1 + 0x16) & 0x1f);
      }
      else {
        local_10 = *(int *)(param_1 + 0x28);
      }
      iVar2 = (int)piVar1 + local_10 * 4 + *piVar1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_00419023 @ 00419023

int __cdecl FUN_00419023(int param_1)

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


// ==== FUN_00419090 @ 00419090

void FUN_00419090(void)

{
  HDC hdc;
  HPALETTE pHVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_004220da; local_8 = local_8 + 1) {
    (&DAT_004220dc)[local_8 * 4] = 0;
    (&DAT_004220dd)[local_8 * 4] = 0;
    (&DAT_004220de)[local_8 * 4] = 0;
    (&DAT_004220df)[local_8 * 4] = 4;
  }
  hdc = GetDC((HWND)0x0);
  pHVar1 = CreatePalette((LOGPALETTE *)&DAT_004220d8);
  if (pHVar1 != (HPALETTE)0x0) {
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    RealizePalette(hdc);
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    DeleteObject(pHVar1);
  }
  ReleaseDC((HWND)0x0,hdc);
  return;
}


// ==== FUN_00419164 @ 00419164

void __cdecl FUN_00419164(int param_1,int *param_2)

{
  int iVar1;
  HDC hdc;
  int local_8;
  
  hdc = GetDC((HWND)0x0);
  GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)&DAT_004220dc);
  GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)&DAT_004224b4);
  ReleaseDC((HWND)0x0,hdc);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_004220dc)[local_8 * 4];
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_004220dd)[local_8 * 4];
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_004220de)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_004220df)[local_8 * 4] = 0;
    *(undefined *)(param_1 + 0x3da + local_8 * 4) = (&DAT_004224b4)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d9 + local_8 * 4) = (&DAT_004224b5)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d8 + local_8 * 4) = (&DAT_004224b6)[local_8 * 4];
    *(undefined1 *)(param_1 + 0x3db + local_8 * 4) = 0;
    (&DAT_004224b7)[local_8 * 4] = 0;
  }
  iVar1 = *param_2;
  for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
    (&DAT_004220dc)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 2);
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_004220dc)[local_8 * 4];
    (&DAT_004220dd)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 1);
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_004220dd)[local_8 * 4];
    (&DAT_004220de)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1);
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_004220de)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_004220df)[local_8 * 4] = 4;
  }
  CreatePalette((LOGPALETTE *)&DAT_004220d8);
  return;
}


// ==== FUN_00419360 @ 00419360

undefined4 __thiscall FUN_00419360(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  void *pvVar10;
  
  iVar7 = param_4;
  iVar6 = param_3;
  iVar4 = DAT_0042a624;
  iVar3 = DAT_0042a620;
  iVar2 = DAT_0042a618;
  if (DAT_0042a618 == 0) {
    uVar5 = 0;
  }
  else if (*(short *)((int)this + 0x80) < 0x1f) {
    if (param_3 < param_1) {
      param_3 = param_1;
      param_1 = iVar6;
    }
    if (param_4 < param_2) {
      param_4 = param_2;
      param_2 = iVar7;
    }
    if (param_1 < 1) {
      param_1 = 0;
    }
    if (param_2 < 1) {
      param_2 = 0;
    }
    iVar6 = DAT_0042a61c + -1;
    if (param_3 <= DAT_0042a61c + -1) {
      iVar6 = param_3;
    }
    iVar7 = DAT_0042a620 + -1;
    if (param_4 <= DAT_0042a620 + -1) {
      iVar7 = param_4;
    }
    uVar8 = (iVar6 - param_1) + 1;
    iVar9 = (iVar7 - param_2) + 1;
    *(short *)((int)this + 0x80) = *(short *)((int)this + 0x80) + 1;
    pvVar10 = operator_new(iVar9 * uVar8 + 8);
    *(void **)((int)this + *(short *)((int)this + 0x80) * 4) = pvVar10;
    if (*(int *)((int)this + *(short *)((int)this + 0x80) * 4) == 0) {
      uVar5 = 0;
    }
    else {
      puVar1 = *(undefined2 **)((int)this + *(short *)((int)this + 0x80) * 4);
      *puVar1 = (short)param_1;
      puVar1[1] = (short)param_2;
      puVar1[2] = (short)iVar6;
      puVar1[3] = (short)iVar7;
      if (DAT_0042a628 == -1) {
        FUN_00414f5c((undefined4 *)(puVar1 + 4),(undefined4 *)(iVar2 + param_2 * iVar4 + param_1),
                     uVar8,iVar9,uVar8,iVar4);
      }
      else {
        FUN_00414f5c((undefined4 *)(puVar1 + 4),
                     (undefined4 *)(iVar2 + ((iVar3 - param_2) + -1) * iVar4 + param_1),uVar8,iVar9,
                     uVar8,-iVar4);
      }
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


// ==== FUN_0041958d @ 0041958d

undefined4 __thiscall FUN_0041958d(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  void *local_40;
  void *local_3c;
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
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  if (*(short *)((int)this + 0x80) == -1) {
    uVar1 = 2;
  }
  else {
    local_34 = *(short **)((int)this + *(short *)((int)this + 0x80) * 4);
    if (local_34 == (short *)0x0) {
      uVar1 = 0;
    }
    else {
      local_14 = (int)*local_34;
      local_20 = (int)local_34[1];
      local_18 = (int)local_34[2];
      local_24 = (int)local_34[3];
      local_30 = (local_18 - local_14) + 1;
      if ((param_1 != -0x8000) && (param_2 != -0x8000)) {
        local_18 = local_18 + (param_1 - local_14);
        local_24 = local_24 + (param_2 - local_20);
        local_14 = param_1;
        local_20 = param_2;
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
      local_2c = DAT_0042a61c;
      local_38 = DAT_0042a620;
      local_28 = DAT_0042a624;
      iVar2 = DAT_0042a61c + -1;
      if (local_18 <= DAT_0042a61c + -1) {
        iVar2 = local_18;
      }
      iVar3 = DAT_0042a620 + -1;
      if (local_24 <= DAT_0042a620 + -1) {
        iVar3 = local_24;
      }
      local_34 = local_34 + 4;
      local_10 = (undefined4 *)DAT_0042a618;
      local_8 = (iVar2 - local_14) + 1;
      local_c = (iVar3 - local_20) + 1;
      local_48 = local_14 + local_8 + -1;
      local_44 = local_20 + local_c + -1;
      local_50 = local_14;
      local_4c = local_20;
      local_24 = iVar3;
      local_18 = iVar2;
      FUN_00413ba3(&DAT_0042a610,&local_50);
      if (DAT_0042a628 == -1) {
        local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
        FUN_00414f5c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
      }
      else {
        local_10 = (undefined4 *)
                   ((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
        FUN_00414f5c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
      }
      local_40 = *(void **)((int)this + *(short *)((int)this + 0x80) * 4);
      local_3c = local_40;
      FUN_0041b6d0(local_40);
      *(undefined4 *)((int)this + *(short *)((int)this + 0x80) * 4) = 0;
      *(short *)((int)this + 0x80) = *(short *)((int)this + 0x80) + -1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00419832 @ 00419832

undefined4 __thiscall FUN_00419832(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

{
  short *psVar1;
  undefined4 uVar2;
  
  if (*(short *)((int)this + 0x80) == -1) {
    uVar2 = 0;
  }
  else {
    psVar1 = *(short **)((int)this + *(short *)((int)this + 0x80) * 4);
    if (psVar1 == (short *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_1 = (int)*psVar1;
      *param_2 = (int)psVar1[1];
      *param_3 = (int)psVar1[2];
      *param_4 = (int)psVar1[3];
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_004198bc @ 004198bc

undefined4 __thiscall FUN_004198bc(void *this,int *param_1)

{
  short *psVar1;
  undefined4 uVar2;
  
  if (*(short *)((int)this + 0x80) == -1) {
    uVar2 = 0;
  }
  else {
    psVar1 = *(short **)((int)this + *(short *)((int)this + 0x80) * 4);
    if (psVar1 == (short *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_1 = (int)*psVar1;
      param_1[1] = (int)psVar1[1];
      param_1[2] = (int)psVar1[2];
      param_1[3] = (int)psVar1[3];
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00419949 @ 00419949

void __fastcall FUN_00419949(int param_1)

{
  while (*(short *)(param_1 + 0x80) != -1) {
    FUN_0041b6d0(*(void **)(param_1 + *(short *)(param_1 + 0x80) * 4));
    *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
  }
  return;
}


// ==== FUN_004199ba @ 004199ba

void __fastcall FUN_004199ba(int param_1)

{
  FUN_00419949(param_1);
  return;
}


// ==== FUN_004199d8 @ 004199d8

undefined4 __thiscall
FUN_004199d8(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  void *pvVar12;
  
  iVar7 = param_4;
  iVar6 = param_3;
  iVar4 = DAT_0042a624;
  iVar3 = DAT_0042a620;
  iVar2 = DAT_0042a618;
  if (DAT_0042a618 == 0) {
    uVar5 = 0;
  }
  else {
    if (param_3 < param_1) {
      param_3 = param_1;
      param_1 = iVar6;
    }
    if (param_4 < param_2) {
      param_4 = param_2;
      param_2 = iVar7;
    }
    iVar6 = param_1;
    if (param_1 < 1) {
      iVar6 = 0;
    }
    iVar7 = param_2;
    if (param_2 < 1) {
      iVar7 = 0;
    }
    iVar10 = DAT_0042a61c + -1;
    if (param_3 <= DAT_0042a61c + -1) {
      iVar10 = param_3;
    }
    iVar8 = DAT_0042a620 + -1;
    if (param_4 <= DAT_0042a620 + -1) {
      iVar8 = param_4;
    }
    uVar9 = (iVar10 - iVar6) + 1;
    iVar10 = (iVar8 - iVar7) + 1;
    if (*(int *)this == 0) {
      *(undefined4 *)((int)this + 4) = 0;
      uVar11 = iVar10 * uVar9 + 0xc;
      pvVar12 = operator_new(uVar11);
      *(void **)this = pvVar12;
      if (*(int *)this == 0) {
        return 0;
      }
      *(uint *)((int)this + 4) = uVar11;
    }
    else {
      uVar11 = iVar10 * uVar9 + 0xc;
      if (param_5 == 0) {
        if (*(int *)((int)this + 4) < (int)uVar11) {
          FUN_0041b6d0(*(void **)this);
          pvVar12 = operator_new(uVar11);
          *(void **)this = pvVar12;
          if (*(int *)this == 0) {
            return 0;
          }
          *(uint *)((int)this + 4) = uVar11;
        }
      }
      else {
        FUN_0041b6d0(*(void **)this);
        pvVar12 = operator_new(uVar11);
        *(void **)this = pvVar12;
        if (*(int *)this == 0) {
          return 0;
        }
        *(uint *)((int)this + 4) = uVar11;
      }
    }
    psVar1 = *(short **)this;
    *psVar1 = (short)iVar6;
    psVar1[1] = (short)iVar7;
    psVar1[2] = (short)iVar6 - (short)param_1;
    psVar1[3] = (short)iVar7 - (short)param_2;
    psVar1[4] = (short)uVar9;
    psVar1[5] = (short)iVar10;
    if (DAT_0042a628 == -1) {
      FUN_00414f5c((undefined4 *)(psVar1 + 6),(undefined4 *)(iVar2 + iVar7 * iVar4 + iVar6),uVar9,
                   iVar10,uVar9,iVar4);
    }
    else {
      FUN_00414f5c((undefined4 *)(psVar1 + 6),
                   (undefined4 *)(iVar2 + ((iVar3 - iVar7) + -1) * iVar4 + iVar6),uVar9,iVar10,uVar9
                   ,-iVar4);
    }
    *(undefined4 *)((int)this + 8) = 1;
    *(undefined4 *)((int)this + 0xc) = 1;
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_00419ce9 @ 00419ce9

undefined4 __thiscall FUN_00419ce9(void *this,int param_1,int param_2,int param_3,int param_4)

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
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  if ((*(int *)this == 0) || (*(int *)((int)this + 0xc) == 0)) {
    uVar1 = 2;
  }
  else if ((param_1 == 0) && (*(int *)((int)this + 8) == 0)) {
    uVar1 = 2;
  }
  else {
    local_34 = *(short **)this;
    *(undefined4 *)((int)this + 8) = 0;
    local_14 = (int)*local_34;
    local_20 = (int)local_34[1];
    local_18 = local_34[4] + local_14 + -1;
    iVar2 = local_34[5] + local_20 + -1;
    local_30 = (local_18 - local_14) + 1;
    local_2c = DAT_0042a61c;
    local_38 = DAT_0042a620;
    local_28 = DAT_0042a624;
    if ((param_3 != -0x8000) && (param_4 != -0x8000)) {
      iVar3 = local_18 + (param_3 - local_14);
      iVar2 = iVar2 + (param_4 - local_20);
      local_14 = param_3;
      local_20 = param_4;
      local_18 = iVar3;
      if (iVar3 < param_3) {
        local_18 = param_3;
        local_1c = iVar3;
        local_14 = iVar3;
      }
      local_24 = iVar2;
      if (iVar2 < param_4) {
        local_24 = param_4;
        local_20 = iVar2;
        local_1c = iVar2;
      }
      if (local_14 < 1) {
        local_14 = 0;
      }
      if (local_20 < 1) {
        local_20 = 0;
      }
      iVar3 = DAT_0042a61c + -1;
      if (local_18 <= DAT_0042a61c + -1) {
        iVar3 = local_18;
      }
      iVar2 = DAT_0042a620 + -1;
      local_18 = iVar3;
      if (local_24 <= DAT_0042a620 + -1) {
        iVar2 = local_24;
      }
    }
    local_24 = iVar2;
    local_34 = local_34 + 6;
    local_10 = (undefined4 *)DAT_0042a618;
    local_8 = (local_18 - local_14) + 1;
    local_c = (local_24 - local_20) + 1;
    local_48 = local_14;
    local_44 = local_20;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    FUN_00413ba3(&DAT_0042a610,&local_48);
    if (DAT_0042a628 == -1) {
      local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
      FUN_00414f5c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
    }
    else {
      local_10 = (undefined4 *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_00414f5c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
    }
    if (param_2 != 0) {
      if (*(int *)this != 0) {
        FUN_0041b6d0(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_00419fb9 @ 00419fb9

undefined4 __thiscall
FUN_00419fb9(void *this,short *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  char *local_48;
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
  undefined1 *local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if ((*(int *)this == 0) || (*(int *)((int)this + 0xc) == 0)) {
    uVar1 = 2;
  }
  else if ((param_4 == 0) && (*(int *)((int)this + 8) == 0)) {
    uVar1 = 2;
  }
  else if (param_1 == (short *)0x0) {
    uVar1 = 0;
  }
  else {
    local_3c = *(short **)this;
    *(undefined4 *)((int)this + 8) = 0;
    local_58 = (int)*local_3c;
    local_54 = (int)local_3c[1];
    local_44 = (int)local_3c[2];
    local_8 = (int)local_3c[3];
    local_24 = local_3c[4] + local_58 + -1;
    local_30 = local_3c[5] + local_54 + -1;
    local_38 = DAT_0042a61c;
    local_40 = DAT_0042a620;
    local_34 = DAT_0042a624;
    local_3c = local_3c + 6;
    local_18 = (undefined1 *)DAT_0042a618;
    local_c = (local_24 - local_58) + 1;
    local_14 = (local_30 - local_54) + 1;
    local_10 = (int)*param_1;
    local_1c = local_10 - (param_2 + local_44);
    local_28 = (int)param_1[1] - (param_3 + local_8);
    if ((local_1c < (int)local_c) || (local_28 < local_14)) {
      uVar1 = 0;
    }
    else {
      if (param_1 == (short *)0x0) {
        local_48 = (char *)0x0;
      }
      else {
        local_48 = (char *)((int)param_1 +
                           (param_3 + local_8) * (int)*param_1 + param_2 + local_44 + 4);
      }
      local_50 = local_c + local_58 + -1;
      local_4c = local_54 + local_14 + -1;
      local_2c = local_54;
      local_20 = local_58;
      FUN_00413ba3(&DAT_0042a610,&local_58);
      if (DAT_0042a628 == -1) {
        local_18 = (undefined1 *)((int)local_18 + local_2c * local_34 + local_20);
        FUN_00414fa6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,local_34,local_c,
                     local_10);
      }
      else {
        local_18 = (undefined1 *)
                   ((int)local_18 + ((local_40 - local_2c) + -1) * local_34 + local_20);
        FUN_00414fa6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,-local_34,local_c,
                     local_10);
      }
      if (param_5 != 0) {
        if (*(int *)this != 0) {
          FUN_0041b6d0(*(void **)this);
        }
        *(undefined4 *)this = 0;
        *(undefined4 *)((int)this + 8) = 0;
        *(undefined4 *)((int)this + 0xc) = 0;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0041a290 @ 0041a290

undefined4 __thiscall
FUN_0041a290(void *this,int param_1,byte param_2,int param_3,int param_4,int param_5)

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
  char *local_10;
  int local_c;
  uint local_8;
  
  if ((*(int *)this == 0) || (*(int *)((int)this + 0xc) == 0)) {
    uVar1 = 2;
  }
  else if ((param_1 == 0) && (*(int *)((int)this + 8) == 0)) {
    uVar1 = 2;
  }
  else {
    local_34 = *(short **)this;
    *(undefined4 *)((int)this + 8) = 0;
    local_14 = (int)*local_34;
    local_20 = (int)local_34[1];
    local_18 = local_34[4] + local_14 + -1;
    local_24 = local_34[5] + local_20 + -1;
    local_30 = (local_18 - local_14) + 1;
    if ((param_4 != -0x8000) && (param_5 != -0x8000)) {
      local_18 = local_18 + (param_4 - local_14);
      local_24 = local_24 + (param_5 - local_20);
      local_14 = param_4;
      local_20 = param_5;
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
    local_2c = DAT_0042a61c;
    local_38 = DAT_0042a620;
    local_28 = DAT_0042a624;
    iVar2 = DAT_0042a61c + -1;
    if (local_18 <= DAT_0042a61c + -1) {
      iVar2 = local_18;
    }
    iVar3 = DAT_0042a620 + -1;
    if (local_24 <= DAT_0042a620 + -1) {
      iVar3 = local_24;
    }
    local_34 = local_34 + 6;
    local_10 = (char *)DAT_0042a618;
    local_8 = (iVar2 - local_14) + 1;
    local_c = (iVar3 - local_20) + 1;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    local_48 = local_14;
    local_44 = local_20;
    local_24 = iVar3;
    local_18 = iVar2;
    FUN_00413ba3(&DAT_0042a610,&local_48);
    if (DAT_0042a628 == -1) {
      local_10 = (char *)((int)local_10 + local_28 * local_20 + local_14);
      FUN_00414ea0(local_10,(char *)local_34,local_8,local_c,local_28,local_30,param_2);
    }
    else {
      local_10 = (char *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_00414ea0(local_10,(char *)local_34,local_8,local_c,-local_28,local_30,param_2);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_0041b6d0(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041a569 @ 0041a569

undefined4 __thiscall
FUN_0041a569(void *this,HDC param_1,int param_2,int param_3,int param_4,int param_5)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint cx;
  int iVar5;
  HDC hdc;
  HGDIOBJ h;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  
  if ((*(int *)this == 0) || (*(int *)((int)this + 0xc) == 0)) {
    uVar2 = 2;
  }
  else if ((param_2 == 0) && (*(int *)((int)this + 8) == 0)) {
    uVar2 = 2;
  }
  else {
    psVar1 = *(short **)this;
    *(undefined4 *)((int)this + 8) = 0;
    local_14 = (int)*psVar1;
    local_20 = (int)psVar1[1];
    local_18 = psVar1[4] + local_14 + -1;
    local_24 = psVar1[5] + local_20 + -1;
    iVar3 = (local_18 - local_14) + 1;
    if ((param_4 != -0x8000) && (param_5 != -0x8000)) {
      local_18 = local_18 + (param_4 - local_14);
      local_24 = local_24 + (param_5 - local_20);
      local_14 = param_4;
      local_20 = param_5;
    }
    iVar4 = local_18;
    iVar5 = local_24;
    if (local_18 < local_14) {
      local_18 = local_14;
      local_14 = iVar4;
    }
    if (local_24 < local_20) {
      local_24 = local_20;
      local_20 = iVar5;
    }
    if (local_14 < 1) {
      local_14 = 0;
    }
    if (local_20 < 1) {
      local_20 = 0;
    }
    iVar5 = DAT_0042a61c + -1;
    if (local_18 <= DAT_0042a61c + -1) {
      iVar5 = local_18;
    }
    iVar4 = DAT_0042a620 + -1;
    if (local_24 <= DAT_0042a620 + -1) {
      iVar4 = local_24;
    }
    cx = (iVar5 - local_14) + 1;
    iVar5 = (iVar4 - local_20) + 1;
    if (DAT_0042a628 == -1) {
      FUN_00414f5c((undefined4 *)(DAT_0042a618 + DAT_0042a624 * local_20 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,DAT_0042a624,iVar3);
    }
    else {
      FUN_00414f5c((undefined4 *)
                   (DAT_0042a618 + ((DAT_0042a620 - local_20) + -1) * DAT_0042a624 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,-DAT_0042a624,iVar3);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_0041b6d0(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    DAT_0042ab9c = 0;
    hdc = CreateCompatibleDC(param_1);
    h = SelectObject(hdc,DAT_0042abc0);
    BitBlt(param_1,local_14,local_20,cx,iVar5,hdc,local_14,local_20,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    GdiFlush();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0041a896 @ 0041a896

bool __thiscall FUN_0041a896(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (iVar1 != 0) {
    *param_1 = (int)**(short **)this;
    *param_2 = (int)*(short *)(*(int *)this + 2);
    *param_3 = (int)*(short *)(*(int *)this + 8) + *param_1 + -1;
    *param_4 = (int)*(short *)(*(int *)this + 10) + *param_2 + -1;
  }
  return iVar1 != 0;
}


// ==== FUN_0041a909 @ 0041a909

bool __thiscall FUN_0041a909(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (iVar1 != 0) {
    *param_1 = (int)**(short **)this;
    param_1[1] = (int)*(short *)(*(int *)this + 2);
    param_1[2] = (int)*(short *)(*(int *)this + 8) + *param_1 + -1;
    param_1[3] = (int)*(short *)(*(int *)this + 10) + param_1[1] + -1;
  }
  return iVar1 != 0;
}


// ==== FUN_0041a980 @ 0041a980

uint __thiscall FUN_0041a980(void *this,int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_8;
  
  if (*(int *)this == 0) {
    uVar1 = (uint)this & 0xffffff00;
  }
  else {
    if (*(int *)this == 0) {
      local_8 = (short *)0x0;
    }
    else {
      this = (void *)(*(int *)this + 8);
      local_8 = this;
    }
    if (local_8 == (short *)0x0) {
      uVar1 = (uint)this & 0xffffff00;
    }
    else {
      iVar2 = *local_8 * param_2 + param_1;
      uVar1 = CONCAT31((int3)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 4 + (int)local_8));
    }
  }
  return uVar1;
}


// ==== FUN_0041aa0a @ 0041aa0a

void __thiscall FUN_0041aa0a(void *this,int param_1,int param_2,undefined1 param_3)

{
  undefined4 local_8;
  
  if (*(int *)this != 0) {
    if (*(int *)this == 0) {
      local_8 = (short *)0x0;
    }
    else {
      local_8 = (short *)(*(int *)this + 8);
    }
    if (local_8 != (short *)0x0) {
      *(undefined1 *)(param_2 * *local_8 + param_1 + 4 + (int)local_8) = param_3;
    }
  }
  return;
}


// ==== FUN_0041aaa0 @ 0041aaa0

void __cdecl FUN_0041aaa0(char param_1,int param_2)

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
  DAT_0042abd0 = param_1;
  bVar1 = (&DAT_0042a658)[param_1 * 4];
  bVar2 = (&DAT_0042a659)[param_1 * 4];
  bVar3 = (&DAT_0042a65a)[param_1 * 4];
  for (local_30 = 0; local_30 < 0x100; local_30 = local_30 + 1) {
    uVar5 = ((uint)bVar1 * param_2 + (uint)(byte)(&DAT_0042a658)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar5) {
      uVar5 = 0xff;
    }
    uVar6 = (param_2 * (uint)bVar2 + (uint)(byte)(&DAT_0042a659)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar6) {
      uVar6 = 0xff;
    }
    uVar7 = (param_2 * (uint)bVar3 + (uint)(byte)(&DAT_0042a65a)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    local_1c = 0;
    local_20 = 0xffffffff;
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      uVar8 = (uVar7 - (byte)(&DAT_0042a65a)[local_34 * 4]) *
              (uVar7 - (byte)(&DAT_0042a65a)[local_34 * 4]) +
              (uVar6 - (byte)(&DAT_0042a659)[local_34 * 4]) *
              (uVar6 - (byte)(&DAT_0042a659)[local_34 * 4]) +
              (uVar5 - (byte)(&DAT_0042a658)[local_34 * 4]) *
              (uVar5 - (byte)(&DAT_0042a658)[local_34 * 4]);
      if (uVar8 < local_20) {
        local_1c = local_34;
        local_20 = uVar8;
      }
    }
    (&DAT_0042abd8)[local_30] = (undefined1)local_1c;
  }
  return;
}


// ==== FUN_0041acbc @ 0041acbc

void __cdecl FUN_0041acbc(byte *param_1,int param_2)

{
  FUN_0041585e(0x42abd8,param_1,param_2);
  return;
}


// ==== FUN_0041acf0 @ 0041acf0

void FUN_0041acf0(void)

{
  FUN_00415550();
  return;
}


// ==== FUN_0041ad05 @ 0041ad05

undefined4 * __cdecl FUN_0041ad05(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0041acf0();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0041acf0();
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


// ==== FUN_0041ad4e @ 0041ad4e

undefined4 FUN_0041ad4e(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0041acf0();
  return *puVar1;
}


// ==== FUN_0041ad65 @ 0041ad65

undefined4 FUN_0041ad65(void)

{
  int iVar1;
  
  iVar1 = FUN_0041acf0();
  return *(undefined4 *)(iVar1 + 0x1c);
}


// ==== FUN_0041ad7d @ 0041ad7d

void __cdecl FUN_0041ad7d(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  FUN_00415556(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0041ada9 @ 0041ada9

void __cdecl FUN_0041ada9(int *param_1,int param_2,undefined1 param_3)

{
  FUN_00415cc6(param_1,param_2,param_3);
  return;
}


// ==== FUN_0041adcd @ 0041adcd

void __thiscall FUN_0041adcd(void *this,int *param_1,int param_2)

{
  FUN_0041587f(this,param_1,param_2);
  return;
}


// ==== FUN_0041adf1 @ 0041adf1

void __cdecl FUN_0041adf1(int *param_1,int param_2,undefined1 param_3)

{
  FUN_00416038(param_1,param_2,param_3);
  return;
}


// ==== FUN_0041ae15 @ 0041ae15

void __cdecl FUN_0041ae15(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  FUN_004163ae(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0041ae41 @ 0041ae41

void __cdecl FUN_0041ae41(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    FUN_004169ef(param_1,param_1);
  }
  else {
    FUN_004169ef(param_1,param_2);
  }
  return;
}


// ==== FID_conflict:_memcpy @ 0041ae80

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
switchD_0041af49_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0041af49_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0041af49_caseD_3:
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
        goto switchD_0041af49_caseD_1;
      case 2:
        goto switchD_0041af49_caseD_2;
      case 3:
        goto switchD_0041af49_caseD_3;
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
switchD_0041aeb0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0041aeb0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0041aeb0_caseD_3:
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
      goto switchD_0041aeb0_caseD_1;
    case 2:
      goto switchD_0041aeb0_caseD_2;
    case 3:
      goto switchD_0041aeb0_caseD_3;
    }
  }
  return _Dst;
}


// ==== FUN_0041afd0 @ 0041afd0

uint * __cdecl FUN_0041afd0(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0041b0b8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0041b0b8:
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


// ==== FUN_0041afe0 @ 0041afe0

uint * __cdecl FUN_0041afe0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0041affc;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0041b02f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0041b04b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0041affc:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0041b04b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0041b04b;
    }
  }
LAB_0041b02f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0041b04b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0041b0b8:
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
    if (bVar1 == 0) goto LAB_0041b0b8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _memset @ 0041b0c0

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


// ==== _strlen @ 0041b120

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0041b140;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0041b173:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0041b140:
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
  goto LAB_0041b173;
}


// ==== _malloc @ 0041b1a0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00422508);
  return pvVar1;
}


// ==== __nh_malloc @ 0041b1c0

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


// ==== __heap_alloc @ 0041b210

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00422d2c) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0042af00,0,dwBytes);
  return pvVar2;
}


// ==== _free @ 0041b250

/* Library Function - Single Match
    _free
   
   Library: Visual Studio 1998 Release */

void __cdecl _free(void *_Memory)

{
  char *pcVar1;
  uint local_8;
  int local_4;
  
  if (_Memory != (void *)0x0) {
    pcVar1 = (char *)___sbh_find_block(_Memory,&local_4,&local_8);
    if (pcVar1 != (char *)0x0) {
      ___sbh_free_block(local_4,local_8,pcVar1);
      return;
    }
    HeapFree(DAT_0042af00,0,_Memory);
  }
  return;
}


// ==== _strncmp @ 0041b2a0

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


// ==== __global_unwind2 @ 0041b2d8

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x41b2f0,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0041b31a

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_0041b2f8;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0041b3ae();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== __abnormal_termination @ 0041b382

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
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_0041b2f8) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_0041b3a5 @ 0041b3a5

void __fastcall FUN_0041b3a5(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_004224e8 = param_1;
  DAT_004224e4 = in_EAX;
  DAT_004224ec = unaff_EBP;
  return;
}


// ==== FUN_0041b3ae @ 0041b3ae

void FUN_0041b3ae(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004224e8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004224e4 = in_EAX;
  DAT_004224ec = unaff_EBP;
  return;
}


// ==== _JumpToContinuation @ 0041b3d0

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0041b3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== _CallMemberFunction0 @ 0041b410

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041b415. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 0041b420

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041b425. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 0041b430

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041b435. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== _UnwindNestedFrames @ 0041b440

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x41b46c,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}


// ==== ___CxxFrameHandler @ 0041b4a0

/* Library Function - Single Match
    ___CxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl
___CxxFrameHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
                  void *param_4)

{
  _s_FuncInfo *in_EAX;
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler
                    (param_1,param_2,param_3,param_4,in_EAX,0,(EHRegistrationNode *)0x0,0);
  return uVar1;
}


// ==== _CallCatchBlock2 @ 0041b4e0

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
  local_10 = &LAB_0041b550;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== _CallSETranslator @ 0041b580

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
  local_14 = 0x41b617;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_00422d40)(*(undefined4 *)param_1,&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}


// ==== TranslatorGuardHandler @ 0041b660

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
            (param_1,*(EHRegistrationNode **)(param_2 + 0xc),param_3,(void *)0x0,
             *(_s_FuncInfo **)(param_2 + 8),*(int *)(param_2 + 0x10),
             *(EHRegistrationNode **)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x0041b6bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// ==== FUN_0041b6d0 @ 0041b6d0

void __cdecl FUN_0041b6d0(void *param_1)

{
  _free(param_1);
  return;
}


// ==== __onexit @ 0041b6e0

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = __msize(DAT_0042aef8);
  if (sVar1 < (uint)((int)DAT_0042aef4 + (4 - (int)DAT_0042aef8))) {
    sVar1 = __msize(DAT_0042aef8);
    pvVar2 = _realloc(DAT_0042aef8,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      return (_onexit_t)0x0;
    }
    DAT_0042aef4 = (undefined4 *)
                   (((int)DAT_0042aef4 - (int)DAT_0042aef8 & 0xfffffffcU) + (int)pvVar2);
    DAT_0042aef8 = pvVar2;
  }
  *DAT_0042aef4 = _Func;
  DAT_0042aef4 = DAT_0042aef4 + 1;
  return _Func;
}


// ==== _atexit @ 0041b760

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}


// ==== _strcmp @ 0041b7c0

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
      if (bVar4 != *_Str2) goto LAB_0041b804;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0041b7d0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0041b804;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0041b804;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0041b7d0:
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
LAB_0041b804:
  return (uint)bVar5 * -2 + 1;
}


// ==== _rand @ 0041b850

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_004224f0 = DAT_004224f0 * 0x343fd + 0x269ec3;
  return (DAT_004224f0 & 0x7fff0000) >> 0x10;
}


// ==== FUN_0041b880 @ 0041b880

int __cdecl FUN_0041b880(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== operator_new @ 0041b890

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== entry @ 0041b8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE pHVar4;
  WPARAM _Code;
  byte *pbVar5;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_0041f000;
  puStack_10 = &LAB_0041dda0;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_00422d68 = DVar2 >> 8 & 0xff;
  DAT_00422d5c = DVar2 >> 0x10;
  _DAT_00422d64 = DVar2 & 0xff;
  _DAT_00422d60 = _DAT_00422d64 * 0x100 + _DAT_00422d68;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0042af04 = (byte *)GetCommandLineA();
  DAT_004224f4 = ___crtGetEnvironmentStringsA();
  if ((DAT_004224f4 == (LPVOID)0x0) || (DAT_0042af04 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0042af04;
  pbVar5 = DAT_0042af04;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_0042af04 + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar5);
        if (iVar3 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_0041b9a5;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_0041b9a5:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  _Code = FUN_0040e449(pHVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0041ba40

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00422500 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_004224fc)(0xff);
  return;
}


// ==== __callnewh @ 0041ba70

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0042acd8 != (code *)0x0) {
    iVar1 = (*DAT_0042acd8)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __heap_init @ 0041baa0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0042af00 = HeapCreate(1,0x1000,0);
  if (DAT_0042af00 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0042af00);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 0041bae0

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
  
  if (DAT_00422d20 == 0) {
    lpMem = &PTR_LOOP_00422510;
  }
  else {
    lpMem = HeapAlloc(DAT_0042af00,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00422510) {
        if (PTR_LOOP_00422510 == (undefined *)0x0) {
          PTR_LOOP_00422510 = (undefined *)&PTR_LOOP_00422510;
        }
        if (PTR_LOOP_00422514 == (undefined *)0x0) {
          PTR_LOOP_00422514 = (undefined *)&PTR_LOOP_00422510;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00422510;
        lpMem[1] = PTR_LOOP_00422514;
        PTR_LOOP_00422514 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00422510) {
    HeapFree(DAT_0042af00,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 0041bc50

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00422d24 == param_1) {
    PTR_LOOP_00422d24 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00422510) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0042af00,0,param_1);
    return;
  }
  DAT_00422d20 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 0041bcb0

/* Library Function - Single Match
    ___sbh_decommit_pages
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_decommit_pages(int param_1)

{
  BOOL BVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int iVar6;
  int local_4;
  
  ppuVar4 = (undefined **)PTR_LOOP_00422514;
  do {
    ppuVar5 = ppuVar4;
    if (ppuVar4[0x204] != (undefined *)0x0) {
      puVar3 = (undefined *)0x3ff;
      pcVar2 = (char *)((int)ppuVar4 + 0x40f);
      local_4 = 0;
      iVar6 = 0x3ff000;
      do {
        if (*pcVar2 == -0x10) {
          BVar1 = VirtualFree(ppuVar4[0x204] + iVar6,0x1000,0x4000);
          if (BVar1 != 0) {
            *pcVar2 = -1;
            DAT_00422d28 = DAT_00422d28 + -1;
            if ((ppuVar4[3] == (undefined *)0xffffffff) || ((int)puVar3 < (int)ppuVar4[3])) {
              ppuVar4[3] = puVar3;
            }
            local_4 = local_4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar6 = iVar6 + -0x1000;
        puVar3 = puVar3 + -1;
        pcVar2 = pcVar2 + -1;
      } while (-1 < iVar6);
      ppuVar5 = (undefined **)ppuVar4[1];
      if ((local_4 != 0) && (*(char *)(ppuVar4 + 4) == -1)) {
        iVar6 = 1;
        pcVar2 = (char *)((int)ppuVar4 + 0x11);
        do {
          if (*pcVar2 != -1) break;
          iVar6 = iVar6 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar6 < 0x400);
        if (iVar6 == 0x400) {
          ___sbh_release_region(ppuVar4);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_00422514) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 0041bd90

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00422510;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00422510) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 0041bdf0

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_free_block(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - *(int *)(param_1 + 0x810) >> 0xc) + param_1;
  *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + *param_3;
  *param_3 = '\0';
  *(undefined1 *)(iVar1 + 0x410) = 0xf1;
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00422d28 = DAT_00422d28 + 1, DAT_00422d28 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 0041be40

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Release */

undefined * __cdecl ___sbh_alloc_block(uint param_1)

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
  
  piVar12 = (int *)PTR_LOOP_00422d24;
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
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar12[0x204] + iVar9),(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar10 + 0x10);
              PTR_LOOP_00422d24 = (undefined *)piVar12;
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
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar12[0x204] + iVar10),(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar9 + 0x10);
              PTR_LOOP_00422d24 = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_00422d24 != piVar12);
  ppuVar11 = &PTR_LOOP_00422510;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00422510) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00422d24 = (undefined *)ppuVar11;
      *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
      puVar7[1] = 0xf0 - param_1;
      *(char *)(ppuVar11 + 4) = *(char *)(ppuVar11 + 4) - cVar8;
      return ppuVar11[0x204] + 0x100;
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
  PTR_LOOP_00422d24 = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 0041c0c0

/* Library Function - Single Match
    ___sbh_alloc_block_from_page
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_alloc_block_from_page(int *param_1,uint param_2,uint param_3)

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


// ==== ___sbh_resize_block @ 0041c240

/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl ___sbh_resize_block(int param_1,int *param_2,byte *param_3,uint param_4)

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


// ==== ___InternalCxxFrameHandler @ 0041c310

/* Library Function - Single Match
    ___InternalCxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl
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
      ___FrameUnwindToState((int)param_2,param_4,(int)param_5,-1);
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


// ==== FindHandler @ 0041c3d0

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
  pEVar4 = DAT_00422d34;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_00422d34 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_00422d34;
    param_3 = DAT_00422d38;
    iVar5 = _ValidateRead(DAT_00422d34,1);
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
LAB_0041c586:
                bVar12 = true;
              }
              else {
                if (*(int *)(pbVar3 + 4) == iVar10) {
LAB_0041c55e:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_0041c586;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_0041c555:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_0041c55a;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_0041c555;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_0041c55a:
                  if (iVar10 == 0) goto LAB_0041c55e;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_0041c5e4;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_0041c5e4:
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


// ==== FindHandlerForForeignException @ 0041c670

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
  
  if (((DAT_00422d40 == 0) ||
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


// ==== GetRangeOfTrysToCheck @ 0041c750

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


// ==== ___FrameUnwindToState @ 0041c7f0

/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 1998 Release */

void __cdecl ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_0041f010;
  puStack_10 = &LAB_0041dda0;
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


// ==== CatchIt @ 0041c8e0

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
  ___FrameUnwindToState((int)param_2,param_4,(int)param_5,*(int *)param_8);
  *(int *)(param_2 + 8) = *(int *)(param_8 + 4) + 1;
  pvVar1 = CallCatchBlock(param_1,param_2,param_3,param_5,*(void **)(param_6 + 0xc),param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}


// ==== CallCatchBlock @ 0041c980

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
  puStack_c = &DAT_0041f020;
  puStack_10 = &LAB_0041dda0;
  *unaff_FS_OFFSET = &local_14;
  DAT_00422d34 = param_1;
  DAT_00422d38 = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0041ca45();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== FUN_0041ca45 @ 0041ca45

void FUN_0041ca45(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  **(undefined4 **)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
  DAT_00422d34 = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_00422d38 = *(undefined4 *)(unaff_EBP + -0x24);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (*(int *)(unaff_EBP + -0x1c) != 0)) {
    iVar2 = __abnormal_termination();
    DestructExceptionObject(*(EHExceptionRecord **)(unaff_EBP + 8),(uchar)iVar2);
  }
  return;
}


// ==== BuildCatchObject @ 0041cac0

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
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_0041f038;
  puStack_10 = &LAB_0041dda0;
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
            goto LAB_0041ccae;
          }
        }
        else {
          iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) &&
             (iVar1 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar1 != 0)) {
            if (((byte)*param_4 & 4) == 0) {
              AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined **)(param_4 + 0x18));
            }
            else {
              AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined **)(param_4 + 0x18));
            }
            goto LAB_0041ccae;
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
          goto LAB_0041ccae;
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
        goto LAB_0041ccae;
      }
    }
    _inconsistency();
  }
LAB_0041ccae:
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== DestructExceptionObject @ 0041ccc0

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
  puStack_c = &DAT_0041f048;
  puStack_10 = &LAB_0041dda0;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== AdjustPointer @ 0041cd40

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


// ==== __CallSettingFrame@12 @ 0041cd70

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_0041b3a5(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_0041b3a5(param_3);
  return;
}


// ==== terminate @ 0041cdc0

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
  puStack_c = &DAT_0041f058;
  puStack_10 = &LAB_0041dda0;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_00422d44 != (code *)0x0) {
    local_8 = 1;
    (*DAT_00422d44)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 0041ce40

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
  puStack_c = &DAT_0041f070;
  puStack_10 = &LAB_0041dda0;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_terminate_00422d4c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_terminate_00422d4c)();
  }
  local_8 = 0xffffffff;
  terminate();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== __cinit @ 0041cec0

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_0042aefc != (code *)0x0) {
    (*DAT_0042aefc)();
  }
  __initterm((undefined4 *)&DAT_0042001c,(undefined4 *)&DAT_00420024);
  iVar1 = __initterm((undefined4 *)&DAT_00420000,(undefined4 *)&DAT_00420018);
  return iVar1;
}


// ==== _exit @ 0041cef0

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0041cf10

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0041cf30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_00422d98 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00422d94 = 1;
  DAT_00422d90 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0042aef8 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0042aef4 + -4), DAT_0042aef8 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0042aef8 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00420028,(undefined4 *)&DAT_0042002c);
  }
  __initterm((undefined4 *)&DAT_00420030,(undefined4 *)&DAT_00420034);
  if (param_3 == 0) {
    DAT_00422d98 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0041cfe0

/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __initterm(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}


// ==== _realloc @ 0041d000

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
  int *local_8;
  int local_4;
  
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
        pbVar2 = (byte *)___sbh_find_block(_Memory,&local_4,(uint *)&local_8);
        if (pbVar2 == (byte *)0x0) {
          local_c = HeapReAlloc(DAT_0042af00,0,_Memory,_NewSize);
        }
        else {
          if (_NewSize < DAT_00422d2c) {
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
                ___sbh_free_block(local_4,(int)local_8,(char *)pbVar2);
              }
            }
            else {
              local_c = _Memory;
            }
          }
          if (local_c != (undefined4 *)0x0) {
            return local_c;
          }
          local_c = HeapAlloc(DAT_0042af00,0,_NewSize);
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
            ___sbh_free_block(local_4,(int)local_8,(char *)pbVar2);
          }
        }
      }
      if ((local_c != (undefined4 *)0x0) || (DAT_00422508 == 0)) {
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


// ==== __msize @ 0041d1b0

/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 1998 Release */

size_t __cdecl __msize(void *_Memory)

{
  byte *pbVar1;
  SIZE_T SVar2;
  undefined4 local_8;
  uint local_4;
  
  pbVar1 = (byte *)___sbh_find_block(_Memory,&local_8,&local_4);
  if (pbVar1 != (byte *)0x0) {
    return (uint)*pbVar1 << 4;
  }
  SVar2 = HeapSize(DAT_0042af00,0,_Memory);
  return SVar2;
}


// ==== __ismbblead @ 0041d390

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 0041d3b0

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00422e38 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_004230fa + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 0041d3f0

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
  cVar1 = *DAT_004224f4;
  pcVar7 = DAT_004224f4;
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
  _DAT_00422d78 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_004224f4;
  pcVar7 = DAT_004224f4;
  do {
    if (cVar1 == '\0') {
      _free(DAT_004224f4);
      DAT_004224f4 = (char *)0x0;
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


// ==== __setargv @ 0041d4e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Release */

int __cdecl __setargv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0042ace0,0x104);
  _DAT_00422d88 = &DAT_0042ace0;
  pbVar2 = &DAT_0042ace0;
  if (*DAT_0042af04 != 0) {
    pbVar2 = DAT_0042af04;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_00422d70 = puVar1;
  _DAT_00422d6c = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 0041d580

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
      if (((*(byte *)((int)&DAT_00422e38 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00422e38 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_0041d5f0;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_0041d5f0:
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
          if ((*(byte *)((int)&DAT_00422e38 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_0041d721;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00422e38 + bVar1 + 1) & 4) != 0) {
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
LAB_0041d721:
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


// ==== ___crtGetEnvironmentStringsA @ 0041d760

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
  if (DAT_00422e30 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00422e30 = 2;
    }
    else {
      DAT_00422e30 = 1;
    }
  }
  if (DAT_00422e30 != 1) {
    if (DAT_00422e30 != 2) {
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


// ==== __setmbcp @ 0041d8f0

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
  if (CodePage == DAT_00422f3c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00422f60;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00422e38;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00422f70 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00422f58)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00422e38 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00422f3c = CodePage;
      _DAT_00422f40 = _CPtoLCID(CodePage);
      DAT_00422f48 = *(undefined4 *)(&DAT_00422f64 + local_18 * 0x30);
      DAT_00422f4c = *(undefined4 *)(&DAT_00422f68 + local_18 * 0x30);
      DAT_00422f50 = *(undefined4 *)(local_18 * 0x30 + 0x422f6c);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00423050);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00422e38;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00422f40 = 0;
      DAT_00422f3c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00422e38 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00422e38 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00422f3c = CodePage;
      _DAT_00422f40 = _CPtoLCID(CodePage);
    }
    DAT_00422f48 = 0;
    DAT_00422f4c = 0;
    DAT_00422f50 = 0;
    return 0;
  }
  if (DAT_00422f54 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 0041dad0

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00422f54 = 1;
                    /* WARNING: Could not recover jumptable at 0x0041daed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00422f54 = 1;
                    /* WARNING: Could not recover jumptable at 0x0041db02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00423318;
  }
  DAT_00422f54 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 0041db20

/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl _CPtoLCID(undefined4 param_1)

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


// ==== setSBCS @ 0041db80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00422e38;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00422f48 = 0;
  DAT_00422f3c = 0;
  _DAT_00422f40 = 0;
  DAT_00422f4c = 0;
  DAT_00422f50 = 0;
  return;
}


// ==== ___initmbctable @ 0041dbb0

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 0041dbc0

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
  DAT_0042aef0 = 0x20;
  DAT_0042adf0 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0042adf0 + 0x40);
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
    if ((int)DAT_0042aef0 < (int)UVar7) {
      piVar4 = &DAT_0042adf4;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0042aef0;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0042aef0 = DAT_0042aef0 + 0x20;
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
      } while ((int)DAT_0042aef0 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0042adf0 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0042adf0 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0042aef0);
  return UVar7;
}


// ==== FUN_0041de5d @ 0041de5d

void FUN_0041de5d(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 0041de80

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00422500 == 1) || ((DAT_00422500 == 0 && (DAT_00422504 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_004230e8 != (code *)0x0) {
      (*DAT_004230e8)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 0041dec0

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
  piVar2 = &DAT_00423058;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_004230e8);
  if ((&DAT_00423058)[iVar4 * 2] == param_1) {
    if ((DAT_00422500 == 1) || ((DAT_00422500 == 0 && (DAT_00422504 == 1)))) {
      if ((DAT_0042adf0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0042adf0 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x42305c);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x42305c);
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


// ==== FUN_0041e0f0 @ 0041e0f0

int FUN_0041e0f0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_0042ade4 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_0042ade4);
    if (iVar2 != 0) {
      iVar2 = (*DAT_0042ade4)(param_1);
      return iVar2;
    }
  }
  return 0;
}


// ==== FUN_0041e150 @ 0041e150

void FUN_0041e150(void)

{
  SetUnhandledExceptionFilter(DAT_0042ade4);
  return;
}


// ==== _ValidateRead @ 0041e160

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 0041e180

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


// ==== _ValidateExecute @ 0041e1a0

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== _abort @ 0041e1c0

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


// ==== ___crtMessageBoxA @ 0041e1e0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0042331c != (FARPROC)0x0) {
LAB_0041e22f:
    if (DAT_00423320 != (FARPROC)0x0) {
      iVar1 = (*DAT_00423320)();
    }
    if ((iVar1 != 0) && (DAT_00423324 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00423324)(iVar1);
    }
    iVar1 = (*DAT_0042331c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0042331c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0042331c != (FARPROC)0x0) {
      DAT_00423320 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00423324 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0041e22f;
    }
  }
  return 0;
}


// ==== _strncpy @ 0041e280

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
        goto joined_r0x0041e2be;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0041e2fb;
        goto LAB_0041e369;
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
joined_r0x0041e365:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_0041e369:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0041e2fb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x0041e365;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x0041e365;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x0041e365;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0041e2be:
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
LAB_0041e2fb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _raise @ 0041e380

/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Release */

int __cdecl _raise(int _SigNum)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 local_4;
  
  switch(_SigNum) {
  case 2:
    puVar6 = &DAT_00423330;
    pcVar7 = DAT_00423330;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    uVar3 = siglookup(_SigNum);
    puVar6 = (undefined4 *)(uVar3 + 8);
    pcVar7 = (code *)*puVar6;
    break;
  case 0xf:
    puVar6 = &DAT_0042333c;
    pcVar7 = DAT_0042333c;
    break;
  case 0x15:
    puVar6 = &DAT_00423334;
    pcVar7 = DAT_00423334;
    break;
  case 0x16:
    puVar6 = &DAT_00423338;
    pcVar7 = DAT_00423338;
  }
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
    __exit(3);
  }
  uVar2 = DAT_00422e28;
  uVar1 = DAT_00422e24;
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_00422e28 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_00422e24 = 0x8c;
      local_4 = uVar1;
      goto LAB_0041e44c;
    }
  }
  else {
LAB_0041e44c:
    if (_SigNum == 8) {
      if (DAT_00422e18 < DAT_00422e1c + DAT_00422e18) {
        puVar6 = (undefined4 *)(DAT_00422e18 * 0xc + 0x422da8);
        iVar4 = DAT_00422e1c;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_0041e48d;
    }
  }
  *puVar6 = 0;
LAB_0041e48d:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_00422e24);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_00422e24 = local_4;
  }
  DAT_00422e28 = uVar5;
  return 0;
}


// ==== siglookup @ 0041e510

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_00422da0;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_00422da0 + DAT_00422e20 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


