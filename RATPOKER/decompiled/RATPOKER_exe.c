// ==== FUN_00401000 @ 00401000

void FUN_00401000(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00417c3c == 1) || (DAT_00417c3c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004141b8,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004141b8,0x804,2,(DWORD_PTR)local_c);
    DAT_004141b8 = 0;
    Sleep(1);
    DAT_00417c3c = 0;
  }
  return;
}


// ==== FUN_004010a5 @ 004010a5

void FUN_004010a5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00414024 != 0) && (DAT_00417c3c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004141b8,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_00417c3c = 3;
  }
  return;
}


// ==== FUN_00401118 @ 00401118

void __cdecl FUN_00401118(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00414024 != 0) {
    if (DAT_00417c3c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_004141b8,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_004141b8,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_004011f5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_00417c3c = 1;
    }
    else {
      FUN_004011f5(param_1);
    }
  }
  return;
}


// ==== FUN_004011f5 @ 004011f5

void __cdecl FUN_004011f5(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00414024 == 0) {
    FUN_00401000();
  }
  else {
    if (((DAT_00417c38 == param_1) && (0 < param_1)) && (DAT_00417c3c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_004141b8,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_00417c3c != 4) {
      FUN_00401000();
    }
    if (DAT_00414024 != 0) {
      if (0 < param_1) {
        DAT_00417c38 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00417c38;
      }
      if ((0 < param_1) && (param_1 < 5)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00417c40 + param_1 * 0x100;
        local_20 = s_sequencer_004141bc;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_004141b8 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_004141b8;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_004141b8 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004141b8,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_00417c3c = 1;
          }
          else {
            DAT_00417c3c = 4;
          }
        }
        else {
          DAT_00417c3c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_004013d5 @ 004013d5

void FUN_004013d5(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00414024 != 0) {
    if (DAT_00417c3c == 1) {
      if (DAT_004141b8 == 0) {
        DAT_00417c3c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_004141b8,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004141b8,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_00417c3c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_00417c3c = 4;
        }
      }
    }
    else if (DAT_00417c3c == 4) {
      FUN_004011f5(-1);
    }
  }
  return;
}


// ==== FUN_004014f3 @ 004014f3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004014f3(int param_1)

{
  DWORD DVar1;
  
  if (DAT_00414020 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00414028) {
      DAT_00414028 = DVar1;
    }
    if (DVar1 - _DAT_0041402c < DAT_00414028) {
      if (DAT_00414030 <= *(int *)(&DAT_0041824c + param_1 * 0x10)) {
        return;
      }
      Sleep(1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00414028 = GetTickCount();
    _DAT_0041402c = *(int *)(&DAT_00418248 + param_1 * 0x10);
    DAT_00414030 = *(int *)(&DAT_0041824c + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_00418240 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_0040160d @ 0040160d

void FUN_0040160d(void)

{
  int local_c;
  int local_8;
  
  FUN_00401000();
  FUN_004014f3(0);
  for (local_8 = 10; local_8 < 0x18; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00418244 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00418244 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00418244 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_00418240 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 5; local_c = local_c + 1) {
    DeleteFileA(&DAT_00417c40 + local_c * 0x100);
  }
  return;
}


// ==== FUN_004016f5 @ 004016f5

void __cdecl FUN_004016f5(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00401940(DAT_0041ecac,param_2,&DAT_004141c8);
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
              if (5000 < (uint)param_1[2]) {
                param_1[2] = 5000;
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


// ==== FUN_00401824 @ 00401824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401824(void)

{
  LPCSTR local_8;
  
  _DAT_00418240 = 0;
  _DAT_00418244 = 0;
  for (local_8 = (LPCSTR)0xa; (int)local_8 < 0x18; local_8 = local_8 + 1) {
    FUN_004016f5((int *)(&DAT_00418240 + (int)local_8 * 0x10),local_8);
    *(undefined4 *)(&DAT_0041824c + (int)local_8 * 0x10) = 10;
  }
  _DAT_0041835c = 1;
  _DAT_0041833c = 1;
  _DAT_0041834c = 1;
  _DAT_0041832c = 3;
  _DAT_004183bc = 2;
  for (local_8 = (LPCSTR)0x1; (int)local_8 < 5; local_8 = (LPCSTR)((int)local_8 + 1)) {
    GetTempPathA(200,&DAT_00417c40 + (int)local_8 * 0x100);
    FUN_004106e0((uint *)(&DAT_00417c40 + (int)local_8 * 0x100),
                 (uint *)(&DAT_00414038 + (int)local_8 * 0x20));
    FUN_00401b63(&DAT_004140f8 + (int)local_8 * 0x20,&DAT_004141d0,
                 &DAT_00417c40 + (int)local_8 * 0x100);
  }
  return;
}


// ==== FUN_00401940 @ 00401940

HGLOBAL __cdecl FUN_00401940(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418640 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_00418640 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_004019b8 @ 004019b8

HGLOBAL __cdecl FUN_004019b8(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418640 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_00418640 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_00418640 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_00401a52 @ 00401a52

undefined4 __cdecl FUN_00401a52(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_004141d8; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418640 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_00418640 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_00418640 + local_18 * 4),hResInfo);
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


// ==== FUN_00401b63 @ 00401b63

bool __cdecl FUN_00401b63(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_004141d8 <= local_18) {
LAB_00401bd1:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_00418640 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_00418640 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_00418640 + local_18 * 4),local_14);
      goto LAB_00401bd1;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_00401c97 @ 00401c97

HRSRC __cdecl FUN_00401c97(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_00418640 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00401cfc @ 00401cfc

HGLOBAL __cdecl FUN_00401cfc(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_00418640 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_00401d5d @ 00401d5d

INT_PTR __cdecl FUN_00401d5d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_00418640 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_00401dcb @ 00401dcb

HACCEL __cdecl FUN_00401dcb(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_00418640 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00401e2d @ 00401e2d

HICON __cdecl FUN_00401e2d(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_00418640 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00401e8e @ 00401e8e

HMENU __cdecl FUN_00401e8e(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_00418640 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00401ef0 @ 00401ef0

int __cdecl FUN_00401ef0(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004141d8 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_00418640 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_00401f59 @ 00401f59

HBITMAP __cdecl FUN_00401f59(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_004141d8 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_00418640 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_00401fbb @ 00401fbb

void FUN_00401fbb(void)

{
  DAT_004141d8 = 0;
  return;
}


// ==== FUN_00401fd5 @ 00401fd5

bool __cdecl FUN_00401fd5(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_004141d8 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_00418640 + DAT_004141d8 * 4) = param_1;
    DAT_004141d8 = DAT_004141d8 + 1;
  }
  return bVar1;
}


// ==== FUN_00402014 @ 00402014

undefined4 __cdecl FUN_00402014(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_004141d8 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_00418640 + DAT_004141d8 * 4) = pHVar2;
      DAT_004141d8 = DAT_004141d8 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00402074 @ 00402074

bool __cdecl FUN_00402074(LPCSTR param_1,uint *param_2)

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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_00414464,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_004106d0(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040214c @ 0040214c

bool __cdecl FUN_0040214c(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040218e @ 0040218e

undefined4 FUN_0040218e(void)

{
  return 1;
}


// ==== FUN_004021a6 @ 004021a6

void __cdecl FUN_004021a6(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_004106e0(local_104,(uint *)&DAT_00414498);
  }
  FUN_004106e0(local_104,param_1);
  FUN_004106d0(param_1,local_104);
  return;
}


// ==== FUN_00402228 @ 00402228

undefined4 __cdecl FUN_00402228(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00402074(s_Shared_Path_0041449c,local_104);
  FUN_004106e0(local_104,param_1);
  bVar1 = FUN_0040214c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00402074(s_Shared_Path_004144a8,local_104);
    FUN_004106e0(local_104,(uint *)&DAT_004144b4);
    FUN_004106e0(local_104,param_1);
    bVar1 = FUN_0040214c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_004106d0(local_104,(uint *)s___shared__004144b8);
      FUN_004106e0(local_104,param_1);
      bVar1 = FUN_0040214c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_004106d0(local_104,(uint *)&DAT_004144c4);
        FUN_004106e0(local_104,param_1);
        bVar1 = FUN_0040214c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_004106d0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_004106d0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_004106d0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_004106d0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_004023d6 @ 004023d6

undefined4 __cdecl FUN_004023d6(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00402074(s_Help_Path_004144c8,local_104);
  FUN_004106e0(local_104,param_1);
  bVar1 = FUN_0040214c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00402074(s_Help_Path_004144d4,local_104);
    FUN_004106e0(local_104,(uint *)&DAT_004144e0);
    FUN_004106e0(local_104,param_1);
    bVar1 = FUN_0040214c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_004106d0(local_104,(uint *)&DAT_004144e4);
      FUN_004106e0(local_104,param_1);
      bVar1 = FUN_0040214c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_004106d0(local_104,(uint *)s___shared__004144e8);
        FUN_004106e0(local_104,param_1);
        bVar1 = FUN_0040214c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_004106d0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_004106d0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_004106d0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_004106d0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00402584 @ 00402584

undefined4 __cdecl FUN_00402584(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_00414460 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00418740 + DAT_00414460 * 4) = param_1;
    DAT_00414460 = DAT_00414460 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_004025d0 @ 004025d0

void FUN_004025d0(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00414460; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00418740 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00418740 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00418740 + local_8 * 4) = 0;
  }
  DAT_00414460 = 0;
  return;
}


// ==== FUN_00402640 @ 00402640

int __cdecl FUN_00402640(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0040265f @ 0040265f

void FUN_0040265f(void)

{
  _memset(&DAT_0041c910,0,0x370);
  _memset(&DAT_00419840,0,0x30d0);
  FID_conflict__memcpy(&DAT_00419840,s_MD_PACK_00414540,8);
  DAT_0041a0d4 = 0;
  DAT_0041a0d5 = 0;
  DAT_0041a0d6 = 0;
  DAT_0041984a = 0xc;
  _memset(&DAT_0041a0a8,0,0x28);
  FID_conflict__memcpy(&DAT_0041a098,s_RATPOKER_00414648,0xb);
  return;
}


// ==== FUN_004026f8 @ 004026f8

undefined4 FUN_004026f8(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0040265f();
  hFile = _lopen(s_MSPuzzle_dat_00414548,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00419840,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_0041a098,s_RATPOKER_00414654,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00419840,s_MD_PACK_00414540,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0041c938 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_0041a10c + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_0041c910 + local_10 * 0x2c,&DAT_0041a0e4 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_0041c938 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_0041c938 + local_10 * 0x2c) = 0;
        }
      }
      DAT_00414024 = (uint)(DAT_0041a0d4 == '\0');
      DAT_00414020 = (uint)(DAT_0041a0d5 == '\0');
      DAT_00414514 = (uint)(DAT_0041a0d6 == '\0');
      FID_conflict__memcpy(&DAT_00414518,&DAT_0041a0a8,0x28);
      DAT_00414500 = (uint)DAT_0041a0d0;
      if ((DAT_00414500 == 0) || (0x14 < DAT_00414500)) {
        DAT_00414500 = 1;
      }
      DAT_00414504 = (uint)DAT_0041a0d1;
      if ((DAT_00414504 == 0) || (3 < DAT_00414504)) {
        DAT_00414504 = 1;
      }
      DAT_00414508 = (uint)(DAT_0041a0d2 == '\0');
      DAT_0041450c = (uint)(DAT_0041a0d3 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0040265f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00402988 @ 00402988

undefined4 __cdecl FUN_00402988(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_0041c938 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_00402a25 @ 00402a25

int __cdecl FUN_00402a25(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_0041c938 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_0041c910 + (local_1c + 1) * 0x2c,&DAT_0041c910 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_0041c910 + local_1c * 0x2c,&DAT_00414518,0x28);
    *(int *)(&DAT_0041c938 + local_1c * 0x2c) = param_1;
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


// ==== FUN_00402b69 @ 00402b69

void FUN_00402b69(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_0041a0e4,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_0041a0e4 + local_c * 0x30,&DAT_0041c910 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_0041a10c + local_c * 0x30) =
         *(undefined4 *)(&DAT_0041c938 + local_c * 0x2c);
  }
  DAT_0041a0d4 = DAT_00414024 == 0;
  DAT_0041a0d5 = DAT_00414020 == 0;
  DAT_0041a0d6 = DAT_00414514 == 0;
  DAT_0041a0d0 = (undefined1)DAT_00414500;
  DAT_0041a0d1 = (undefined1)DAT_00414504;
  DAT_0041a0d2 = DAT_00414508 == 0;
  DAT_0041a0d3 = DAT_0041450c == 0;
  _memset(&DAT_0041a0a8,0,0x28);
  FID_conflict__memcpy(&DAT_0041a0a8,&DAT_00414518,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_00414548,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_00414548,0);
  }
  _lwrite(local_8,&DAT_00419840,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_00402d40 @ 00402d40

void __cdecl FUN_00402d40(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_004168a4 = 2;
  }
  DAT_0041cd08 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00402d83 @ 00402d83

void __cdecl FUN_00402d83(HWND param_1)

{
  if (DAT_0041cd08 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_0041cd08);
  }
  return;
}


// ==== FUN_00402db4 @ 00402db4

void __cdecl FUN_00402db4(uint *param_1)

{
  FUN_004106d0((uint *)&DAT_004168a8,param_1);
  return;
}


// ==== FUN_00402dd5 @ 00402dd5

void __cdecl FUN_00402dd5(HWND param_1)

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


// ==== FUN_00402f0d @ 00402f0d

void __cdecl FUN_00402f0d(int param_1)

{
  LPCSTR pCVar1;
  HWND pHVar2;
  code *pcVar3;
  
  if ((0 < param_1) && (param_1 < 0x17)) {
    DAT_00416890 = 1;
    InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    FUN_00402db4((uint *)s_QUICKHELPBMP_004169cc);
    if (param_1 == 0x16) {
      FUN_00401d5d(DAT_0041ecac,s_QGOBUYDIALOG_004169dc,DAT_0041ef48,FUN_004037e1);
    }
    else if (param_1 == 0x15) {
      FUN_00401d5d(DAT_0041ecac,s_QHCONGRATULAT_004169ec,DAT_0041ef48,FUN_004037e1);
    }
    else {
      pcVar3 = FUN_00403575;
      pHVar2 = DAT_0041ef48;
      pCVar1 = FUN_0040d050((uint *)s_QHLEVELDIALOG_004169fc,param_1,2);
      FUN_00401d5d(DAT_0041ecac,pCVar1,pHVar2,pcVar3);
    }
    DAT_00416890 = 0;
    InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    FUN_00406fd2();
  }
  return;
}


// ==== FUN_00403003 @ 00403003

INT_PTR FUN_00403003(void)

{
  INT_PTR IVar1;
  
  DAT_00416888 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_QUICKHELPBMP_00416a0c);
  IVar1 = FUN_00401d5d(DAT_0041ecac,s_EXITGAME_00416a1c,DAT_0041ef48,FUN_00403a08);
  DAT_00416888 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_0040307b @ 0040307b

INT_PTR FUN_0040307b(void)

{
  INT_PTR IVar1;
  
  DAT_00416888 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_QUICKHELPBMP_00416a28);
  IVar1 = FUN_00401d5d(DAT_0041ecac,s_NEWGAME_00416a38,DAT_0041ef48,FUN_00403a08);
  DAT_00416888 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_004030f3 @ 004030f3

INT_PTR __cdecl FUN_004030f3(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_00401d5d(DAT_0041ecac,s_RESETSCORE_00416a40,param_1,FUN_004065b8);
  return IVar1;
}


// ==== FUN_00403128 @ 00403128

void FUN_00403128(void)

{
  DAT_00416888 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_ABOUTBMP_00416a4c);
  FUN_00401d5d(DAT_0041ecac,s_ABOUT_00416a58,DAT_0041ef48,FUN_00403b9f);
  DAT_00416888 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403197 @ 00403197

void __cdecl FUN_00403197(HWND param_1)

{
  FUN_00401d5d(DAT_0041ecac,s_CREDITS_00416a60,param_1,FUN_00403e85);
  return;
}


// ==== FUN_004031c3 @ 004031c3

void __cdecl FUN_004031c3(HWND param_1)

{
  FUN_00401d5d(DAT_0041ecac,s_SYSTEMINFODIALOG_00416a68,param_1,FUN_00404016);
  return;
}


// ==== FUN_004031ef @ 004031ef

void FUN_004031ef(void)

{
  DAT_00416890 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_QUICKHELPBMP_00416a7c);
  FUN_00401d5d(DAT_0041ecac,s_QUICKHELPDIALOG_00416a8c,DAT_0041ef48,FUN_004045b4);
  DAT_00416890 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040325e @ 0040325e

void FUN_0040325e(void)

{
  DAT_00416888 = 1;
  FUN_00402db4((uint *)s_CUPBMP_00416a9c);
  FUN_00401d5d(DAT_0041ecac,s_YOURNAME_00416aa4,DAT_0041ef48,FUN_00404a8f);
  DAT_00416888 = 0;
  return;
}


// ==== FUN_004032ad @ 004032ad

void FUN_004032ad(void)

{
  DAT_00416888 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_CUPBMP_00416ab0);
  FUN_00401d5d(DAT_0041ecac,s_BALLSTOP_00416ab8,DAT_0041ef48,FUN_00405b81);
  DAT_00416888 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040331c @ 0040331c

void FUN_0040331c(void)

{
  DAT_00416888 = 1;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  FUN_00402db4((uint *)s_OPTIONSBMP_00416ac4);
  FUN_00401d5d(DAT_0041ecac,s_OPTIONS_00416ad0,DAT_0041ef48,FUN_00405efe);
  DAT_00416888 = 0;
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040338b @ 0040338b

void __cdecl FUN_0040338b(HWND param_1)

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
  local_8 = FUN_0040d280(pHVar1,&DAT_004168a8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040d1a1(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00416da0,0);
  RealizePalette(pHVar1);
  FUN_0040d1ea(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00403480 @ 00403480

void __cdecl FUN_00403480(HWND param_1)

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
  ho = FUN_0040d280(pHVar1,s_QUICKHELPBMP_00416ad8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040d1a1(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00416da0,0);
  RealizePalette(pHVar1);
  FUN_0040d1ea(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_00403575 @ 00403575

UINT FUN_00403575(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040338b(DAT_0041dccc);
      }
      return 0;
    }
    FUN_00402dd5(param_1);
    DAT_0041cc80 = param_1;
    DAT_0041dccc = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0041450c == 0);
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
      DAT_0041450c = (uint)(LVar2 == 0);
      FUN_00402b69();
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
      DAT_0041450c = (uint)(LVar2 == 0);
      FUN_00402b69();
      EndDialog(param_1,0);
      PostMessageA(DAT_0041ef48,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0041cc80 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0041cc80);
  SelectPalette(hdc,DAT_00416da0,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0041cc80,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0041cc80,(RECT *)0x0,0);
    InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_004037e1 @ 004037e1

UINT FUN_004037e1(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00402dd5(param_1);
      DAT_0041ecb0 = param_1;
      DAT_0041cd18 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_0041450c == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041cd18);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041ecb0 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041ecb0);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_0041ecb0,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_0041ecb0,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
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
        DAT_0041450c = (uint)(LVar2 == 0);
        FUN_00402b69();
        EndDialog(param_1,0);
        PostMessageA(DAT_0041ef48,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00403a08 @ 00403a08

UINT FUN_00403a08(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402dd5(param_1);
      DAT_0041eca8 = param_1;
      DAT_0041eca0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041eca0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041eca8 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041eca8);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041eca8,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041eca8,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
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


// ==== FUN_00403b9f @ 00403b9f

UINT FUN_00403b9f(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402dd5(param_1);
      DAT_0041ecf8 = param_1;
      DAT_0041ecf4 = GetDlgItem(param_1,100);
      FUN_00401ef0(DAT_0041ecac,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00402074(&DAT_00416ae8,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00402074(s_Product_ID_00416aec,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041ecf4);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0041ecf8) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_0041ecf8);
      SelectPalette(local_10c,DAT_00416da0,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_0041ecf8,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0041ecf8,(RECT *)0x0,0);
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
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
      FUN_004031c3(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00403197(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00403e85 @ 00403e85

UINT FUN_00403e85(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402dd5(param_1);
      DAT_0041dcd8 = param_1;
      DAT_0041dcd0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041dcd0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041dcd8 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041dcd8);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041dcd8,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041dcd8,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ecf8,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
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


// ==== FUN_00404016 @ 00404016

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00404016(HWND param_1,int param_2,uint param_3)

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
    FUN_00402dd5(param_1);
    _DAT_0041cc98 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416af8,local_49c.dwMajorVersion,-1);
    FUN_004106d0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416afc);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b00,local_49c.dwMinorVersion,-1);
    FUN_004106e0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b04);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b08,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_004106e0((uint *)local_404,puVar1);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b0c);
      FUN_004106e0((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b10,local_4dc.dwTotalPhys >> 10,-1);
    FUN_004106d0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b14);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_004106d0((uint *)local_404,(uint *)&DAT_00416b18);
    FUN_004106e0((uint *)local_404,(uint *)&local_4b4);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b1c);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b20,local_4a0,-1);
    FUN_004106e0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b24);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_00416b48,s_display_drv_00416b3c,s_Unknown_00416b34,local_404,0x80,
               s_system_ini_00416b28);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b5c,local_4a0,-1);
    FUN_004106d0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b60);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b64,local_4a0,-1);
    FUN_004106e0((uint *)local_404,puVar1);
    FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b68);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b6c,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_004106e0((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b70,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_004106e0((uint *)local_404,puVar1);
      FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b74);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b7c,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_004106e0((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_0040d050((uint *)&DAT_00416b78,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_004106e0((uint *)local_404,puVar1);
      }
      FUN_004106e0((uint *)local_404,(uint *)&DAT_00416b80);
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


// ==== FUN_004045b4 @ 004045b4

UINT FUN_004045b4(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040338b(DAT_0041cc84);
      }
      return 0;
    }
    FUN_00402dd5(param_1);
    DAT_0041dcd4 = param_1;
    DAT_0041cc84 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00414508 == 0);
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
      DAT_00414508 = (uint)(LVar2 == 0);
      FUN_00402b69();
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
      DAT_00414508 = (uint)(LVar2 == 0);
      FUN_00402b69();
      EndDialog(param_1,0);
      PostMessageA(DAT_0041ef48,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (param_3 == DAT_0041dcd4) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0041dcd4);
  SelectPalette(hdc,DAT_00416da0,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0041dcd4,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0041dcd4,(RECT *)0x0,0);
    InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040481f @ 0040481f

int __cdecl FUN_0040481f(int param_1,int *param_2)

{
  bool bVar1;
  int local_44;
  int local_40;
  int local_3c;
  int aiStack_34 [10];
  int local_c;
  int local_8;
  
  local_c = 0;
  bVar1 = true;
  local_8 = 0;
  local_44 = 10;
  if ((param_1 == 1) || (param_1 == 5)) {
    local_44 = DAT_00416560;
    for (local_40 = 0; local_40 < *param_2; local_40 = local_40 + 1) {
      if (param_2[local_40 + 1] == 8) {
        return 0;
      }
    }
  }
  for (local_40 = 0; local_40 < *param_2; local_40 = local_40 + 1) {
    if (param_2[local_40 + 1] == 7) {
      aiStack_34[local_40] = param_2[local_40 + 1];
      if (*(int *)(&DAT_00416388 + local_40 * 4 + param_1 * 0x30) == 2) {
        bVar1 = true;
        local_c = 0;
      }
      else {
        local_c = local_c + *(int *)(&DAT_00416388 + local_40 * 4 + param_1 * 0x30);
      }
    }
    else if (bVar1) {
      aiStack_34[local_40] = param_2[local_40 + 1];
      local_8 = param_2[local_40 + 1];
      local_c = 0;
      bVar1 = false;
    }
    else if (*(int *)(&DAT_00416388 + local_40 * 4 + param_1 * 0x30) == 2) {
      local_8 = param_2[local_40 + 1];
      aiStack_34[local_40] = param_2[local_40 + 1];
      local_c = 0;
    }
    else {
      local_8 = (local_c + *(int *)(&DAT_00416388 + local_40 * 4 + param_1 * 0x30) + local_8) %
                local_44;
      aiStack_34[local_40] = local_8;
      local_c = 0;
    }
  }
  local_3c = 0;
  local_40 = 0;
  while( true ) {
    if (*param_2 <= local_40) {
      return local_3c;
    }
    if ((aiStack_34[local_40] != 7) && (param_2[local_40 + 1] != aiStack_34[local_40])) break;
    local_3c = local_3c + 1;
    if (*(int *)(&DAT_00416380 + param_1 * 0x30) <= local_3c) {
      return *(int *)(&DAT_00416380 + param_1 * 0x30);
    }
    local_40 = local_40 + 1;
  }
  if (*(int *)(&DAT_00416380 + param_1 * 0x30) <= local_3c) {
    return local_3c;
  }
  return 0;
}


// ==== FUN_00404a8f @ 00404a8f

UINT FUN_00404a8f(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_0040338b(DAT_0041ccb0);
      }
      return 0;
    }
    FUN_00402dd5(param_1);
    DAT_0041dce0 = param_1;
    DAT_0041ccb0 = GetDlgItem(param_1,100);
    if (DAT_004168a4 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00414518);
    _Size = 0x10;
    _Src = FUN_0040d050((uint *)&DAT_00416b84,DAT_004144f8,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_0041dce0 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_0041dce0);
    SelectPalette(hdc,DAT_00416da0,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_0041dce0,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_0041dce0,(RECT *)0x0,0);
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00414518,DAT_004168a4 * 0x11);
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


// ==== FUN_00404dce @ 00404dce

undefined4 __cdecl FUN_00404dce(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = *param_3;
  local_10 = *param_4;
  switch(*(undefined4 *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2)) {
  case 1:
    local_10 = local_10 + -1;
    break;
  case 2:
    local_10 = local_10 + 1;
    break;
  case 3:
    local_c = local_c + -1;
    break;
  case 4:
    local_c = local_c + 1;
    break;
  default:
    return 0;
  }
  if ((((-1 < local_c) && (-1 < local_10)) && (local_c < 10)) && (local_10 < 10)) {
    iVar1 = FID_conflict___toupper_lk((int)*(char *)(local_c * 0x14 + local_10 + param_1));
    if (((*(int *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) != 0) ||
        (*(int *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) != 0)) && ((char)iVar1 != 'V')) {
      return 0;
    }
    switch((char)iVar1) {
    case '#':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 1) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 7;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 7;
      }
      break;
    case '$':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 1) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 3;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 3;
      }
      break;
    default:
      return 0;
    case '-':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 1) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 6;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 6;
      }
      break;
    case '/':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 1) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 0xc;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 0xc;
      }
      break;
    case '<':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 4) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      break;
    case '>':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 4) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      break;
    case 'J':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 2) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 9;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 9;
      }
      break;
    case 'L':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 4) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 0xb;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 0xb;
      }
      break;
    case 'V':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) != 4) {
        *param_3 = local_c;
        *param_4 = local_10;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 4;
        return 1;
      }
      *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
      *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
      DAT_0041ecf0 = 1;
      break;
    case 'X':
      *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) =
           *(undefined4 *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2);
      *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 0;
      *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 2;
      *param_3 = local_c;
      *param_4 = local_10;
      return 1;
    case 'Y':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 2) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 10;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 10;
      }
      break;
    case '^':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 1) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 5;
      }
      break;
    case '|':
      if (*(int *)(*param_3 * 400 + *param_4 * 0x28 + 8 + param_2) == 4) {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 4;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 8;
      }
      else {
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + param_2) = 3;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + param_2) = 8;
      }
    }
    *param_3 = local_c;
    *param_4 = local_10;
    return 1;
  }
  return 0;
}


// ==== FUN_00405b81 @ 00405b81

UINT FUN_00405b81(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00402dd5(param_1);
      DAT_0041dcc8 = param_1;
      DAT_0041dcdc = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_004169a8) && (DAT_004169a8 < 10)) {
        SetDlgItemTextA(param_1,DAT_004169a8 + 0x33,&DAT_00416b88);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_0040d050((uint *)&DAT_00416b8c,*(int *)(&DAT_0041c938 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0041c910 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041dcdc);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0041dcc8) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041dcc8);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_0041dcc8,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_0041dcc8,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_004030f3(DAT_0041dcc8), IVar5 == 1)) {
        if ((-1 < DAT_004169a8) && (DAT_004169a8 < 10)) {
          SetDlgItemTextA(param_1,DAT_004169a8 + 0x33,&DAT_00416b90);
        }
        DAT_004169a8 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_0041c938 + local_14 * 0x2c) = 0;
          _memset(&DAT_0041c910 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_0040d050((uint *)&DAT_00416b94,*(int *)(&DAT_0041c938 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0041c910 + local_14 * 0x2c);
        }
        FUN_00402b69();
      }
    }
  }
  return 0;
}


// ==== FUN_00405efe @ 00405efe

UINT FUN_00405efe(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_0041ef48,s_ratpoker_hlp_00416578,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_0040338b(DAT_0041cd20);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_004060a7:
      hdc = GetDC(DAT_0041cc9c);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_0041cc9c,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0041cc9c,(RECT *)0x0,0);
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00402dd5(param_1);
      DAT_0041cc9c = param_1;
      DAT_0041cd20 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00414020;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00414024;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00414514;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      WVar7 = 2;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x60,DAT_00414504 + 0x5e);
      if (DAT_004168a4 == 1) {
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
      SetDlgItemTextA(param_1,0x1e,&DAT_00414518);
      pHVar9 = (HIMC)0x0;
      pHVar1 = GetDlgItem(param_1,0xf);
      DAT_0041dcf0 = ImmAssociateContext(pHVar1,pHVar9);
      pCVar2 = FUN_0040d050((uint *)&DAT_00416b98,DAT_00414500,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x10014);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_00414020 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_00414024 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_00414514 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00414504 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00414504 = 2;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_00414518,DAT_004168a4 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0x15; local_28 = local_28 + 1) {
          pcVar3 = FUN_0040d050((uint *)&DAT_00416ba8,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00406454:
            DAT_00414500 = local_28;
            break;
          }
          pcVar3 = FUN_0040d050((uint *)&DAT_00416bac,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00406454;
        }
      case 2:
        DAT_0041cc9c = (HWND)0x0;
        pHVar9 = DAT_0041dcf0;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_00414500;
          for (local_28 = 1; local_28 < 0x15; local_28 = local_28 + 1) {
            pcVar3 = FUN_0040d050((uint *)&DAT_00416b9c,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_004061f0:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_0040d050((uint *)&DAT_00416ba0,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_004061f0;
          }
          pCVar2 = FUN_0040d050((uint *)&DAT_00416ba4,local_1c,-1);
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
        WinHelpA(DAT_0041ef48,s_ratpoker_hlp_00416578,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (param_3 == DAT_0041cc9c) {
      return 0;
    }
    goto LAB_004060a7;
  }
  return 0;
}


// ==== FUN_004065b8 @ 004065b8

UINT FUN_004065b8(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402dd5(param_1);
      DAT_0041eef0 = param_1;
      DAT_0041cd1c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403480(DAT_0041cd1c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041eef0 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041eef0);
      SelectPalette(hdc,DAT_00416da0,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041eef0,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041dcc8,(RECT *)0x0,0);
        InvalidateRect(DAT_0041eef0,(RECT *)0x0,0);
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
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


// ==== FUN_0040675f @ 0040675f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040675f(int param_1,void *param_2)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_1c = 0;
  local_8 = 0;
  DAT_0041ecf0 = 0;
  _DAT_0041ccac = 0;
  _memset(param_2,0,4000);
  _memset(&DAT_0041ed58,0,400);
  local_c = 0;
  do {
    if (9 < local_c) {
      return 0;
    }
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      if ((*(char *)(local_10 + local_c * 0x14 + param_1) == 'O') ||
         (*(char *)(local_10 + local_c * 0x14 + param_1) == 'o')) {
        DAT_0041cd10 = local_10;
        DAT_0041cd14 = local_c;
        _DAT_0041ecc0 = local_10 + 1;
        _DAT_0041ecc4 = local_c;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + (int)param_2) = 0;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 8 + (int)param_2) = 2;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + (int)param_2) = 1;
        *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 0x18 + (int)param_2) = 2;
        while( true ) {
          if (DAT_0041ecf0 == 0) {
            *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 0x18 + (int)param_2) = 2;
          }
          else {
            *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 0x18 + (int)param_2) = 4;
          }
          local_20 = local_10;
          local_18 = local_c;
          iVar1 = FUN_00404dce(param_1,(int)param_2,&local_18,&local_20);
          if (iVar1 == 0) {
            return 0;
          }
          if ((local_18 == local_c) && (local_20 == local_10)) {
            return 0;
          }
          if (*(int *)(local_c * 400 + local_10 * 0x28 + (int)param_2) == 3) {
            DAT_0041cc90 = local_10;
            DAT_0041cc94 = local_c;
          }
          local_c = local_18;
          local_10 = local_20;
          if (local_1c == 0) {
            local_1c = 1;
          }
          else if (local_8 == 0) {
            local_8 = 1;
            DAT_0041ecb8 = local_20;
            DAT_0041ecbc = local_18;
          }
          if (*(int *)(local_18 * 400 + local_20 * 0x28 + (int)param_2) == 2) break;
          if (*(int *)(local_18 * 400 + local_20 * 0x28 + (int)param_2) == 4) {
            DAT_0041dce8 = local_20;
            DAT_0041dcec = local_18;
            DAT_0041ec98 = local_20 + -1;
            DAT_0041ec9c = local_18;
            local_10 = DAT_0041cc90;
            local_c = DAT_0041cc94;
            *(undefined4 *)(DAT_0041cc94 * 400 + DAT_0041cc90 * 0x28 + 8 + (int)param_2) = 4;
            while( true ) {
              local_20 = local_10;
              local_18 = local_c;
              iVar1 = FUN_00404dce(param_1,(int)param_2,&local_18,&local_20);
              if (iVar1 == 0) {
                return 0;
              }
              if ((local_18 == local_c) && (local_20 == local_10)) break;
              local_c = local_18;
              local_10 = local_20;
              *(undefined4 *)(local_18 * 400 + local_20 * 0x28 + 0x18 + (int)param_2) = 1;
              if (*(int *)(local_18 * 400 + local_20 * 0x28 + (int)param_2) == 2) {
                *(undefined4 *)(DAT_0041cc94 * 400 + DAT_0041cc90 * 0x28 + 8 + (int)param_2) = 1;
                DAT_0041cca0 = local_20;
                DAT_0041cca4 = local_18;
                local_10 = DAT_0041cc90;
                local_c = DAT_0041cc94;
                local_14 = 0;
                while ((local_14 < 8 &&
                       (*(int *)(local_c * 400 + local_10 * 0x28 + 0x18 + (int)param_2) == 4))) {
                  (&DAT_0041ed08)[local_14 * 2] = local_10;
                  (&DAT_0041ed0c)[local_14 * 2] = local_c;
                  *(undefined4 *)(local_c * 400 + local_10 * 0x28 + 0x18 + (int)param_2) = 3;
                  *(int *)(local_c * 400 + local_10 * 0x28 + 0x20 + (int)param_2) = local_14;
                  switch(*(undefined4 *)(local_c * 400 + local_10 * 0x28 + 4 + (int)param_2)) {
                  case 1:
                    local_10 = local_10 + 1;
                    break;
                  case 2:
                    local_10 = local_10 + -1;
                    break;
                  case 3:
                    local_c = local_c + 1;
                    break;
                  case 4:
                    local_c = local_c + -1;
                  }
                  local_14 = local_14 + 1;
                }
                for (local_c = 0; local_c < 4; local_c = local_c + 1) {
                  *(undefined4 *)(&DAT_0041ccb8 + local_c * 8) = 0xfffffff6;
                  *(undefined4 *)(&DAT_0041ccbc + local_c * 8) = 0xfffffff6;
                }
                _DAT_0041ccac = 0;
                for (local_c = 0; local_c < 10; local_c = local_c + 1) {
                  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
                    if (*(char *)(local_10 + local_c * 0x14 + param_1) == '*') {
                      DAT_0041ed00 = local_10;
                      DAT_0041ed04 = local_c;
                    }
                    if (*(char *)(local_10 + local_c * 0x14 + param_1) == '<') {
                      _DAT_0041ccb8 = local_10;
                      _DAT_0041ccbc = local_c;
                      _DAT_0041ccac = _DAT_0041ccac + 1;
                    }
                    if (*(char *)(local_10 + local_c * 0x14 + param_1) == '^') {
                      _DAT_0041ccc0 = local_10;
                      _DAT_0041ccc4 = local_c;
                      _DAT_0041ccac = _DAT_0041ccac + 1;
                    }
                    if (*(char *)(local_10 + local_c * 0x14 + param_1) == '>') {
                      _DAT_0041ccc8 = local_10;
                      _DAT_0041cccc = local_c;
                      _DAT_0041ccac = _DAT_0041ccac + 1;
                    }
                  }
                }
                return 1;
              }
            }
            return 0;
          }
        }
        return 0;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== FUN_00406ddc @ 00406ddc

void FUN_00406ddc(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_00410b50(DVar1);
  return;
}


// ==== FUN_00406dfb @ 00406dfb

int __cdecl FUN_00406dfb(int param_1)

{
  int iVar1;
  
  if (param_1 < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = _rand();
    iVar1 = iVar1 % param_1;
  }
  return iVar1;
}


// ==== FUN_00406e2c @ 00406e2c

UINT FUN_00406e2c(void)

{
  UINT UVar1;
  
  FUN_0040d119(0);
  SelectPalette(DAT_0041ef00,DAT_00416da0,0);
  UVar1 = RealizePalette(DAT_0041ef00);
  FUN_0040d15f(0);
  if (UVar1 != 0) {
    InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  }
  return UVar1;
}


// ==== FUN_00406e93 @ 00406e93

void FUN_00406e93(void)

{
  int local_c;
  int local_8;
  
  local_c = DAT_004144f8;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040ecf0((int *)(&DAT_00427fe0 + (0x18 - local_8) * 0x2c),local_c % 10);
    local_c = local_c / 10;
  }
  return;
}


// ==== FUN_00406f06 @ 00406f06

void FUN_00406f06(void)

{
  return;
}


// ==== FUN_00406f16 @ 00406f16

void FUN_00406f16(void)

{
  FUN_0040ecf0((int *)&DAT_004282a0,DAT_004144fc / 10);
  FUN_0040ecf0((int *)&DAT_004282cc,DAT_004144fc % 10);
  return;
}


// ==== FUN_00406f68 @ 00406f68

void FUN_00406f68(void)

{
  DAT_00416898 = DAT_00416898 + -1;
  return;
}


// ==== FUN_00406f7e @ 00406f7e

void FUN_00406f7e(void)

{
  FUN_0040ecf0((int *)&DAT_0042800c,(DAT_00416898 / 10) * 3);
  FUN_0040ecf0((int *)&DAT_00428038,(DAT_00416898 % 10) * 3);
  return;
}


// ==== FUN_00406fd2 @ 00406fd2

void FUN_00406fd2(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_0041688c == 0) && (DAT_00416884 == 0)) && (DAT_0041687c == 0)) {
    SetMenu(DAT_0041ef48,DAT_0041cc88);
    if (DAT_0041450c == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_0041ef48);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_0041ef48);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_0041ef48);
  }
  else {
    SetMenu(DAT_0041ef48,DAT_0041eefc);
    if (DAT_0041450c == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_0041ef48);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_0041ef48);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_0041ef48);
  }
  return;
}


// ==== FUN_004070d6 @ 004070d6

void FUN_004070d6(void)

{
  LPCSTR pCVar1;
  short *psVar2;
  
  psVar2 = (short *)&DAT_0041f3d8;
  pCVar1 = FUN_0040d050((uint *)s_WAYS__00416bb0,*(int *)(DAT_004144fc * 0x60 + 0x41467c),1);
  FUN_0040f8bb(pCVar1,psVar2);
  psVar2 = (short *)&DAT_0041f820;
  pCVar1 = FUN_0040d050((uint *)s_ROTARY__00416bb8,*(int *)(DAT_004144fc * 0x60 + 0x414684),1);
  FUN_0040f8bb(pCVar1,psVar2);
  psVar2 = (short *)&DAT_00420d88;
  pCVar1 = FUN_0040d050((uint *)s_DOOR__00416bc0,*(int *)(DAT_004144fc * 0x60 + 0x41467c),1);
  FUN_0040f8bb(pCVar1,psVar2);
  FUN_004100fa(&DAT_0041f3d8,0x427fe0);
  FUN_004100fa(&DAT_0041f3d8,0x428064);
  FUN_004100fa(&DAT_00420d88,0x4282f8);
  FUN_004100fa(&DAT_00420d88,0x428324);
  return;
}


// ==== FUN_004071e2 @ 004071e2

void FUN_004071e2(void)

{
  int local_8;
  
  FUN_0040f8bb(s_WAYS_1_00416bc8,(short *)&DAT_0041f3d8);
  FUN_0040f8bb(s_ROTARY_1_00416bd0,(short *)&DAT_0041f820);
  FUN_0040f8bb(s_DOOR_1_00416bdc,(short *)&DAT_00420d88);
  FUN_0040f8bb(s_BUBBLESPR_00416be4,(short *)&DAT_0041f5fc);
  FUN_004100fa(&DAT_0041f3d8,0x427fe0);
  FUN_0040ee99((int *)&DAT_00427fe0,-100,-100,-1);
  FUN_004100fa(&DAT_0041f3d8,0x428064);
  FUN_0040ef59((int *)&DAT_00428064);
  FUN_0040f8bb(s_RESCDIGITS_00416bf0,(short *)&DAT_00420940);
  FUN_004100fa(&DAT_00420940,0x42800c);
  FUN_004100fa(&DAT_00420940,0x428038);
  FUN_0040f8bb(s_DIGITS_00416bfc,(short *)&DAT_00420b64);
  FUN_004100fa(&DAT_00420b64,0x4282a0);
  FUN_004100fa(&DAT_00420b64,0x4282cc);
  FUN_004100fa(&DAT_00420d88,0x4282f8);
  FUN_004100fa(&DAT_00420d88,0x428324);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_004100fa(&DAT_00420b64,(int)(&DAT_00427fe0 + (local_8 + 0x14) * 0x2c));
  }
  FUN_0040f8bb(s_RAT_R_00416c04,(short *)&DAT_004220cc);
  FUN_0040f8bb(s_RAT_O_00416c0c,(short *)&DAT_004222f0);
  FUN_0040f8bb(s_RAT_Y_00416c14,(short *)&DAT_00422514);
  FUN_0040f8bb(s_RAT_G_00416c1c,(short *)&DAT_00422738);
  FUN_0040f8bb(s_RAT_C_00416c24,(short *)&DAT_0042295c);
  FUN_0040f8bb(s_RAT_B_00416c2c,(short *)&DAT_00422b80);
  FUN_0040f8bb(s_RAT_M_00416c34,(short *)&DAT_00422da4);
  FUN_0040f8bb(s_RAT_W_00416c3c,(short *)&DAT_00422fc8);
  FUN_0040f8bb(s_RAT_D_00416c44,(short *)&DAT_004231ec);
  FUN_0040f8bb(s_RAT_R_P_00416c4c,(short *)&DAT_00423634);
  FUN_0040f8bb(s_RAT_O_P_00416c54,(short *)&DAT_00423858);
  FUN_0040f8bb(s_RAT_Y_P_00416c5c,(short *)&DAT_00423a7c);
  FUN_0040f8bb(s_RAT_G_P_00416c64,(short *)&DAT_00423ca0);
  FUN_0040f8bb(s_RAT_C_P_00416c6c,(short *)&DAT_00423ec4);
  FUN_0040f8bb(s_RAT_B_P_00416c74,(short *)&DAT_004240e8);
  FUN_0040f8bb(s_RAT_M_P_00416c7c,(short *)&DAT_0042430c);
  FUN_0040f8bb(s_RAT_W_P_00416c84,(short *)&DAT_00424530);
  FUN_0040f8bb(s_RAT_D_P_00416c8c,(short *)&DAT_00424754);
  FUN_0040f8bb(s_RAT_R_M_00416c94,(short *)&DAT_00424b9c);
  FUN_0040f8bb(s_RAT_O_M_00416c9c,(short *)&DAT_00424dc0);
  FUN_0040f8bb(s_RAT_Y_M_00416ca4,(short *)&DAT_00424fe4);
  FUN_0040f8bb(s_RAT_G_M_00416cac,(short *)&DAT_00425208);
  FUN_0040f8bb(s_RAT_C_M_00416cb4,(short *)&DAT_0042542c);
  FUN_0040f8bb(s_RAT_B_M_00416cbc,(short *)&DAT_00425650);
  FUN_0040f8bb(s_RAT_M_M_00416cc4,(short *)&DAT_00425874);
  FUN_0040f8bb(s_RAT_W_M_00416ccc,(short *)&DAT_00425a98);
  FUN_0040f8bb(s_RAT_D_M_00416cd4,(short *)&DAT_00425cbc);
  FUN_0040f8bb(s_A_CENTER_00416cdc,(short *)&DAT_004211d0);
  FUN_004100fa(&DAT_004211d0,0x42842c);
  FUN_0040ef59((int *)&DAT_0042842c);
  return;
}


// ==== FUN_00407697 @ 00407697

void __cdecl FUN_00407697(undefined4 param_1)

{
  DAT_004169b0 = param_1;
  if (2 < DAT_004169ac) {
    DAT_004169ac = 2;
  }
  return;
}


// ==== FUN_004076c6 @ 004076c6

void FUN_004076c6(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_0041cd14;
  iVar1 = DAT_0041cd10;
  DAT_004169ac = *(int *)(DAT_004144fc * 0x60 + 0x414674);
  if (DAT_004169ac < 2) {
    DAT_004169ac = 2;
  }
  if (*(int *)(&DAT_0041cd28 + DAT_0041cd10 * 0x28 + DAT_0041cd14 * 400) == 1) {
    if ((*(int *)(&DAT_0041cd34 + DAT_0041cd10 * 0x28 + DAT_0041cd14 * 400) == 0) &&
       (*(int *)(&DAT_0041cd34 + (DAT_0041cd10 * 5 + 5) * 8 + DAT_0041cd14 * 400) == 0)) {
      if (*(int *)(&DAT_0041cd34 + DAT_0041ecb8 * 0x28 + DAT_0041ecbc * 400) == 0) {
        FUN_004014f3(0xe);
      }
      else {
        FUN_004014f3(0x17);
      }
      iVar3 = FUN_00406dfb(*(int *)(DAT_004144fc * 0x60 + 0x414664));
      *(int *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) = iVar3 + 1;
      *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 0;
      if (*(int *)(DAT_004144fc * 0x60 + 0x414670) != 0) {
        iVar3 = *(int *)(DAT_004144fc * 0x60 + 0x414688);
        iVar4 = FUN_00406dfb(100);
        if (iVar4 < iVar3 + -1) {
          *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 1;
        }
        iVar3 = *(int *)(DAT_004144fc * 0x60 + 0x41468c);
        iVar4 = FUN_00406dfb(100);
        if (iVar4 < iVar3 + -1) {
          *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 2;
        }
      }
      if (0xc < DAT_004144fc) {
        iVar3 = *(int *)(DAT_004144fc * 0x60 + 0x414694);
        iVar4 = FUN_00406dfb(100);
        if (iVar4 < iVar3 + -1) {
          *(undefined4 *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) = 9;
          *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 0;
        }
      }
      if (7 < DAT_004144fc) {
        iVar3 = *(int *)(DAT_004144fc * 0x60 + 0x414690);
        iVar4 = FUN_00406dfb(100);
        if (iVar4 < iVar3 + -1) {
          *(undefined4 *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) = 8;
          *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 0;
        }
      }
      if (DAT_004169b0 != 0) {
        *(int *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) = DAT_004169b0;
      }
      DAT_004169b0 = 0;
      DAT_0041689c = 1;
      FUN_0040ecf0((int *)&DAT_004282f8,1);
    }
    else {
      PostMessageA(DAT_0041ef48,0x111,0x22c,0);
    }
  }
  else {
    PostMessageA(DAT_0041ef48,0x111,0x22c,0);
  }
  return;
}


// ==== FUN_004079ff @ 004079ff

void __cdecl FUN_004079ff(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_1c;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = param_1 * 10 + param_2 + 0x1c;
  if (*(int *)(&DAT_0041cd34 + param_2 * 0x28 + param_1 * 400) == 0) {
    FUN_0040ef59((int *)(&DAT_00427fe0 + iVar1 * 0x2c));
  }
  else {
    if (param_3 != 0) {
      FUN_0040ef59((int *)(&DAT_00427fe0 + iVar1 * 0x2c));
      if (*(int *)(&DAT_0041cd38 + param_2 * 0x28 + param_1 * 400) == 1) {
        FUN_004100fa(&DAT_0041f3d8 +
                     (*(int *)(&DAT_0041cd34 + param_2 * 0x28 + param_1 * 400) + 0x1e) * 0x224,
                     (int)(&DAT_00427fe0 + iVar1 * 0x2c));
      }
      else if (*(int *)(&DAT_0041cd38 + param_2 * 0x28 + param_1 * 400) == 2) {
        FUN_004100fa(&DAT_0041f3d8 +
                     (*(int *)(&DAT_0041cd34 + param_2 * 0x28 + param_1 * 400) + 0x28) * 0x224,
                     (int)(&DAT_00427fe0 + iVar1 * 0x2c));
      }
      else {
        FUN_004100fa(&DAT_0041f3d8 +
                     (*(int *)(&DAT_0041cd34 + param_2 * 0x28 + param_1 * 400) + 0x14) * 0x224,
                     (int)(&DAT_00427fe0 + iVar1 * 0x2c));
      }
    }
    local_c = param_2 * 0x27 + 0x19;
    local_10 = (DAT_00416dac - (param_1 * 0x27 + 0x19)) + 4;
    local_1c = 0;
    if (DAT_0041eef8 < 0) {
      if ((DAT_0041cc90 == param_2) && (DAT_0041cc94 + 1 == param_1)) {
        *(undefined4 *)(&DAT_0041cd3c + param_2 * 0x28 + param_1 * 400) = 4;
      }
      switch(*(undefined4 *)(&DAT_0041cd3c + param_2 * 0x28 + param_1 * 400)) {
      case 1:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_c = local_c + DAT_0041eef8 * -7;
        }
        if (DAT_0041eef8 == -3) {
          local_8 = 8;
        }
        else if (DAT_0041eef8 == -2) {
          local_8 = 9;
          local_1c = 1;
        }
        else {
          local_8 = 10;
          local_1c = 1;
        }
        break;
      case 2:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_c = local_c + DAT_0041eef8 * 7;
        }
        if (DAT_0041eef8 == -3) {
          local_8 = 0;
        }
        else if (DAT_0041eef8 == -2) {
          local_8 = 1;
          local_1c = 1;
        }
        else {
          local_8 = 2;
          local_1c = 1;
        }
        break;
      case 3:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_10 = local_10 + DAT_0041eef8 * 7;
        }
        if (DAT_0041eef8 == -3) {
          local_8 = 0xc;
          local_1c = 1;
        }
        else if (DAT_0041eef8 == -2) {
          local_8 = 0xd;
          local_1c = -6;
        }
        else {
          local_8 = 0xe;
          local_1c = -2;
        }
        break;
      case 4:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_10 = local_10 + DAT_0041eef8 * -7;
        }
        if (DAT_0041eef8 == -3) {
          local_8 = 4;
          local_1c = -1;
        }
        else if (DAT_0041eef8 == -2) {
          local_8 = 5;
          local_1c = 8;
        }
        else {
          local_8 = 6;
        }
      }
    }
    else {
      switch(*(undefined4 *)(&DAT_0041cd30 + param_2 * 0x28 + param_1 * 400)) {
      case 1:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_c = local_c + DAT_0041eef8 * -7;
        }
        if (DAT_0041eef8 == 0) {
          local_8 = 0xb;
        }
        else if (DAT_0041eef8 == 1) {
          local_8 = 9;
          local_1c = 1;
        }
        else {
          local_8 = 10;
          local_1c = 1;
        }
        break;
      case 2:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_c = local_c + DAT_0041eef8 * 7;
        }
        if (DAT_0041eef8 == 0) {
          local_8 = 3;
        }
        else if (DAT_0041eef8 == 1) {
          local_8 = 1;
          local_1c = 1;
        }
        else {
          local_8 = 2;
          local_1c = 1;
        }
        break;
      case 3:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_10 = local_10 + DAT_0041eef8 * 7;
        }
        if (DAT_0041eef8 == 0) {
          local_8 = 0xf;
        }
        else if (DAT_0041eef8 == 1) {
          local_8 = 0xd;
          local_1c = -6;
        }
        else {
          local_8 = 0xe;
          local_1c = -2;
        }
        break;
      case 4:
        if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) == 0) &&
           (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) != 3)) {
          local_10 = local_10 + DAT_0041eef8 * -7;
        }
        if (DAT_0041eef8 == 0) {
          local_8 = 7;
        }
        else if (DAT_0041eef8 == 1) {
          local_8 = 5;
          local_1c = 8;
        }
        else {
          local_8 = 6;
        }
      }
    }
    if ((*(int *)(&DAT_0041cd44 + param_2 * 0x28 + param_1 * 400) != 0) ||
       (*(int *)(&DAT_0041cd4c + param_2 * 0x28 + param_1 * 400) == 3)) {
      if (1 < local_1c) {
        local_1c = 1;
      }
      if (local_1c < -1) {
        local_1c = -1;
      }
    }
    FUN_0040ee99((int *)(&DAT_00427fe0 + iVar1 * 0x2c),local_c,local_1c + local_10,10);
    FUN_0040ecf0((int *)(&DAT_00427fe0 + iVar1 * 0x2c),local_8);
  }
  return;
}


// ==== FUN_00408281 @ 00408281

void FUN_00408281(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0041cca4;
  iVar1 = DAT_0041cca0;
  if (*(int *)(&DAT_0041cd28 + DAT_0041cca0 * 0x28 + DAT_0041cca4 * 400) == 2) {
    if (*(int *)(&DAT_0041cd34 + DAT_0041cca0 * 0x28 + DAT_0041cca4 * 400) != 0) {
      FUN_00406f68();
      if (DAT_00416898 < 1) {
        PostMessageA(DAT_0041ef48,0x111,0x22b,0);
        DAT_00416898 = 0;
      }
      FUN_00406f7e();
    }
    *(undefined4 *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) = 0;
    *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) = 0;
  }
  return;
}


// ==== FUN_0040835c @ 0040835c

void FUN_0040835c(void)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      *(undefined4 *)(&DAT_0041cd44 + local_10 * 0x28 + local_c * 400) = 0;
      if (((*(int *)(&DAT_0041cd34 + local_10 * 0x28 + local_c * 400) != 0) &&
          (*(int *)(&DAT_0041cd40 + local_10 * 0x28 + local_c * 400) == 2)) &&
         (*(int *)(&DAT_0041cd34 + DAT_0041ec98 * 0x28 + DAT_0041ec9c * 400) != 0)) {
        local_8 = local_c;
        local_14 = local_10;
        switch(*(undefined4 *)(&DAT_0041cd30 + local_10 * 0x28 + local_c * 400)) {
        case 1:
          local_14 = local_10 + -1;
          break;
        case 2:
          local_14 = local_10 + 1;
          break;
        case 3:
          local_8 = local_c + -1;
          break;
        case 4:
          local_8 = local_c + 1;
        }
        if ((*(int *)(&DAT_0041cd34 + local_14 * 0x28 + local_8 * 400) != 0) ||
           ((DAT_0041dce8 == local_14 && (DAT_0041dcec == local_8)))) {
          *(undefined4 *)(&DAT_0041cd44 + local_10 * 0x28 + local_c * 400) = 1;
        }
      }
    }
  }
  return;
}


// ==== FUN_00408521 @ 00408521

void FUN_00408521(void)

{
  int local_c;
  int local_8;
  
  _memset(&DAT_0041dcf8,0,4000);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      if (*(int *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400) != 0) {
        if (*(int *)(&DAT_0041cd28 + local_c * 0x28 + local_8 * 400) == 2) {
          *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + local_8 * 400) = 0;
        }
        else if ((*(int *)(&DAT_0041cd44 + local_c * 0x28 + local_8 * 400) == 0) &&
                (*(int *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400) != 3)) {
          switch(*(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400)) {
          case 1:
            if (((DAT_0041cc90 == local_c) && (DAT_0041cc94 == local_8)) &&
               (*(int *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400) == 1)) {
              *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                   *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd08 + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                   *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd0c + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                   *(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd1c + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                   *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
            }
            else {
              *(undefined4 *)(&DAT_0041dd04 + (local_c * 5 + -5) * 8 + local_8 * 400) =
                   *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd08 + (local_c * 5 + -5) * 8 + local_8 * 400) =
                   *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd0c + (local_c * 5 + -5) * 8 + local_8 * 400) =
                   *(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400);
              *(undefined4 *)(&DAT_0041dd1c + (local_c * 5 + -5) * 8 + local_8 * 400) =
                   *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
            }
            break;
          case 2:
            *(undefined4 *)(&DAT_0041dd04 + (local_c * 5 + 5) * 8 + local_8 * 400) =
                 *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd08 + (local_c * 5 + 5) * 8 + local_8 * 400) =
                 *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd0c + (local_c * 5 + 5) * 8 + local_8 * 400) =
                 *(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd1c + (local_c * 5 + 5) * 8 + local_8 * 400) =
                 *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
            break;
          case 3:
            *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + (local_8 * 5 + -5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd08 + local_c * 0x28 + (local_8 * 5 + -5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd0c + local_c * 0x28 + (local_8 * 5 + -5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd1c + local_c * 0x28 + (local_8 * 5 + -5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
            break;
          case 4:
            *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd08 + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd0c + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd30 + local_c * 0x28 + local_8 * 400);
            *(undefined4 *)(&DAT_0041dd1c + local_c * 0x28 + (local_8 * 5 + 5) * 0x50) =
                 *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
          }
        }
        else {
          *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + local_8 * 400) =
               *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400);
          *(undefined4 *)(&DAT_0041dd08 + local_c * 0x28 + local_8 * 400) =
               *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400);
          *(undefined4 *)(&DAT_0041dd0c + local_c * 0x28 + local_8 * 400) =
               *(undefined4 *)(&DAT_0041cd3c + local_c * 0x28 + local_8 * 400);
          *(undefined4 *)(&DAT_0041dd1c + local_c * 0x28 + local_8 * 400) =
               *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400);
        }
      }
    }
  }
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0041cd34 + local_c * 0x28 + local_8 * 400) =
           *(undefined4 *)(&DAT_0041dd04 + local_c * 0x28 + local_8 * 400);
      *(undefined4 *)(&DAT_0041cd38 + local_c * 0x28 + local_8 * 400) =
           *(undefined4 *)(&DAT_0041dd08 + local_c * 0x28 + local_8 * 400);
      *(undefined4 *)(&DAT_0041cd3c + local_c * 0x28 + local_8 * 400) =
           *(undefined4 *)(&DAT_0041dd0c + local_c * 0x28 + local_8 * 400);
      *(undefined4 *)(&DAT_0041cd4c + local_c * 0x28 + local_8 * 400) =
           *(undefined4 *)(&DAT_0041dd1c + local_c * 0x28 + local_8 * 400);
    }
  }
  return;
}


// ==== FUN_00408c97 @ 00408c97

void FUN_00408c97(void)

{
  if (*(int *)(&DAT_0041cd34 + (DAT_0041cc90 + -1) * 0x28 + DAT_0041cc94 * 400) == 9) {
    DAT_004169b4 = 3;
  }
  return;
}


// ==== FUN_00408ce5 @ 00408ce5

void FUN_00408ce5(void)

{
  int iVar1;
  LPCSTR pCVar2;
  int local_60;
  int local_58;
  int aiStack_54 [10];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  HGLOBAL local_14;
  int local_10;
  int local_c;
  
  if (*(int *)(&DAT_0041cd4c + DAT_0041cc90 * 0x28 + DAT_0041cc94 * 400) == 1) {
    *(undefined4 *)(&DAT_0041cd30 + DAT_0041cc90 * 0x28 + DAT_0041cc94 * 400) = 4;
  }
  else {
    *(undefined4 *)(&DAT_0041cd30 + DAT_0041cc90 * 0x28 + DAT_0041cc94 * 400) = 1;
  }
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    for (local_24 = 0; local_24 < 10; local_24 = local_24 + 1) {
      if (*(int *)(&DAT_0041cd4c + local_24 * 0x28 + local_20 * 400) != 1) {
        *(undefined4 *)(&DAT_0041cd4c + local_24 * 0x28 + local_20 * 400) = 0;
      }
    }
  }
  local_24 = DAT_0041ed08;
  local_20 = DAT_0041ed0c;
  if ((*(int *)(&DAT_0041cd4c + DAT_0041ed08 * 0x28 + DAT_0041ed0c * 400) != 1) &&
     (*(int *)(&DAT_0041cd34 + DAT_0041ed08 * 0x28 + DAT_0041ed0c * 400) != 0)) {
    if (DAT_004169b4 < 1) {
      local_58 = 0;
      for (local_2c = 0; local_2c < 8; local_2c = local_2c + 1) {
        local_24 = (&DAT_0041ed08)[local_2c * 2];
        local_20 = (&DAT_0041ed0c)[local_2c * 2];
        if (*(int *)(&DAT_0041cd34 + local_24 * 0x28 + local_20 * 400) == 0) break;
        local_58 = local_58 + 1;
        aiStack_54[local_2c] = *(int *)(&DAT_0041cd34 + local_24 * 0x28 + local_20 * 400) + -1;
      }
      for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
        if (*(int *)(DAT_004144fc * 0x60 + 0x414698 + local_2c * 4) != 0) {
          local_18 = FUN_0040481f(local_2c,&local_58);
          if (local_18 != 0) {
            if ((2 < local_18) && (*(int *)(&DAT_00416380 + local_2c * 0x30) == local_18)) {
              local_10 = *(int *)(&DAT_00416384 + local_2c * 0x30) << 7;
              for (local_60 = 0; local_60 < local_18; local_60 = local_60 + 1) {
                local_24 = (&DAT_0041ed08)[local_60 * 2];
                local_20 = (&DAT_0041ed0c)[local_60 * 2];
                if (*(int *)(&DAT_0041cd38 + local_24 * 0x28 + local_20 * 400) == 1) {
                  local_10 = local_10 << 1;
                }
                if (*(int *)(&DAT_0041cd38 + local_24 * 0x28 + local_20 * 400) == 2) {
                  local_10 = local_10 / 2;
                }
                *(undefined4 *)(&DAT_0041cd4c + local_24 * 0x28 + local_20 * 400) = 1;
              }
              DAT_004144f8 = DAT_004144f8 + ((int)(local_10 + (local_10 >> 0x1f & 0x7fU)) >> 7);
              if (local_2c < 2) {
                FUN_004014f3(0x16);
              }
              else if (local_2c < 6) {
                FUN_004014f3(0x15);
              }
              else if (local_2c < 8) {
                FUN_004014f3(0x14);
              }
              else {
                FUN_004014f3(0x13);
              }
              FUN_00406e93();
              local_28 = 10;
              local_1c = 0x38;
              for (local_20 = 9; iVar1 = local_28, -1 < local_20; local_20 = local_20 + -1) {
                local_c = local_28;
                if (local_20 != 3) {
                  local_28 = local_28 + 1;
                  local_1c = local_1c + 0x22;
                }
                if ((*(int *)(DAT_004144fc * 0x60 + 0x414698 + local_20 * 4) != 0) &&
                   (local_2c == local_20)) {
                  if (local_20 == 3) {
                    local_14 = FUN_0040d492(s_COMB15_00416ce8);
                  }
                  else {
                    pCVar2 = FUN_0040d050((uint *)&DAT_00416cf0,iVar1,2);
                    local_14 = FUN_0040d492(pCVar2);
                  }
                  if (local_14 != (HGLOBAL)0x0) {
                    FUN_0040e0ab((int)local_14,DAT_00416de4,400,DAT_00416dac - local_1c);
                    GlobalFree(local_14);
                  }
                }
              }
              DAT_004169b8 = local_2c;
              return;
            }
            if (7 < local_58) {
              return;
            }
            for (local_60 = 0; local_60 < local_58; local_60 = local_60 + 1) {
              *(undefined4 *)
               (&DAT_0041cd4c +
               (&DAT_0041ed08)[local_60 * 2] * 0x28 + (&DAT_0041ed0c)[local_60 * 2] * 400) = 3;
            }
            return;
          }
          local_18 = 0;
        }
      }
    }
    else {
      DAT_004169b4 = DAT_004169b4 + -1;
    }
  }
  return;
}


// ==== FUN_004091dd @ 004091dd

void FUN_004091dd(void)

{
  int iVar1;
  LPCSTR pCVar2;
  HGLOBAL hMem;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = 0;
  local_10 = 0x38;
  for (local_14 = 9; -1 < local_14; local_14 = local_14 + -1) {
    iVar1 = local_18;
    if (local_14 != 3) {
      iVar1 = local_18 + 1;
      local_10 = local_10 + 0x22;
      if (*(int *)(DAT_004144fc * 0x60 + 0x414698 + local_14 * 4) != 0) {
        pCVar2 = FUN_0040d050((uint *)&DAT_00416cf8,local_18,2);
        hMem = FUN_0040d492(pCVar2);
        if (hMem != (HGLOBAL)0x0) {
          FUN_0040e0ab((int)hMem,DAT_00416de4,400,DAT_00416dac - local_10);
          GlobalFree(hMem);
        }
      }
    }
    local_18 = iVar1;
  }
  return;
}


// ==== FUN_004092b1 @ 004092b1

void FUN_004092b1(void)

{
  bool bVar1;
  int local_10;
  int local_c;
  uint local_8;
  
  if (DAT_0041eef8 == 2) {
    FUN_00408281();
  }
  DAT_0041eef8 = DAT_0041eef8 + 1;
  bVar1 = 2 < DAT_0041eef8;
  if (bVar1) {
    DAT_0041eef8 = -3;
    FUN_00408521();
  }
  local_8 = (uint)bVar1;
  if ((DAT_0041eef8 == -3) && (DAT_004169ac = DAT_004169ac + -1, DAT_004169ac < 1)) {
    FUN_004076c6();
  }
  if (DAT_0041eef8 == 0) {
    FUN_00408c97();
    if (-1 < DAT_004169b8) {
      DAT_004169b8 = -1;
      FUN_004091dd();
    }
    FUN_00408ce5();
    FUN_0040835c();
  }
  if (*(int *)(&DAT_0041cd4c + DAT_0041cc90 * 0x28 + DAT_0041cc94 * 400) == 1) {
    FUN_0040efc2((int *)&DAT_00428064,1);
    FUN_0040ecf0((int *)&DAT_00428064,1);
  }
  else {
    FUN_0040ef59((int *)&DAT_00428064);
  }
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      FUN_004079ff(local_c,local_10,local_8);
    }
  }
  return;
}


// ==== FUN_00409425 @ 00409425

void FUN_00409425(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_18;
  int local_14;
  
  iVar1 = DAT_0041ed00 * 0x27 + 0x19;
  iVar2 = DAT_00416dac - (DAT_0041ed04 * 0x27 + 0x19);
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    if (*(int *)(&DAT_0041ed64 + local_14 * 0x28) != 0) {
      local_18 = DAT_0041ecdc + local_14;
      if ((int)local_18 < 0) {
        local_18 = local_18 + 4;
      }
      if (3 < (int)local_18) {
        uVar5 = (int)local_18 >> 0x1f;
        local_18 = ((local_18 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5;
      }
      iVar3 = FUN_00406dfb(3);
      iVar3 = iVar3 + -1;
      iVar4 = FUN_00406dfb(3);
      iVar4 = iVar4 + -1;
      switch(local_18) {
      case 0:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar3 + iVar1 + -0x4d,
                     iVar4 + iVar2,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar3 + iVar1 + -0x4d,
                     iVar4 + iVar2,2);
        break;
      case 1:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar3 + iVar1,
                     iVar4 + iVar2 + 0x4d,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar3 + iVar1,
                     iVar4 + iVar2 + 0x4d,2);
        break;
      case 2:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar3 + iVar1 + 0x4d,
                     iVar4 + iVar2,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar3 + iVar1 + 0x4d,
                     iVar4 + iVar2,2);
        break;
      case 3:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar3 + iVar1,
                     iVar4 + iVar2 + -0x4d,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar3 + iVar1,
                     iVar4 + iVar2 + -0x4d,2);
      }
    }
  }
  return;
}


// ==== FUN_004096cd @ 004096cd

void FUN_004096cd(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_8;
  
  for (local_14 = 0; (int)local_14 < 4; local_14 = local_14 + 1) {
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_14 + 8) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
  }
  iVar1 = DAT_0041ed00 * 0x27;
  iVar2 = DAT_00416dac - (DAT_0041ed04 * 0x27 + 0x19);
  for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
    local_14 = DAT_0041ecdc + local_18;
    if ((int)local_14 < 0) {
      local_14 = local_14 + 4;
    }
    if (3 < (int)local_14) {
      uVar3 = (int)local_14 >> 0x1f;
      local_14 = ((local_14 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
    }
    if (*(int *)(&DAT_0041ecc8 + local_18 * 4) != 0) {
      FUN_004100fa(&DAT_0041f820,(int)(&DAT_00427fe0 + (local_18 + 8) * 0x2c));
      FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 8) * 0x2c),iVar1 + 0x19,iVar2,1);
      local_8 = local_14 * 2 + -1;
      if (local_8 < 0) {
        local_8 = 7;
      }
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_18 + 8) * 0x2c),local_8);
    }
    if (*(int *)(&DAT_0041ed64 + local_18 * 0x28) != 0) {
      local_1c = DAT_0041ecdc + local_18;
      if ((int)local_1c < 0) {
        local_1c = local_1c + 4;
      }
      if (3 < (int)local_1c) {
        uVar3 = (int)local_1c >> 0x1f;
        local_1c = ((local_1c ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      FUN_004100fa(&DAT_0041f5fc,(int)(&DAT_00427fe0 + (local_18 + 4) * 0x2c));
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_18 + 4) * 0x2c),0);
      if (*(int *)(&DAT_0041ed68 + local_18 * 0x28) == 1) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_18 * 0x28) + 0x1e) * 0x224,
                     (int)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c));
      }
      else if (*(int *)(&DAT_0041ed68 + local_18 * 0x28) == 2) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_18 * 0x28) + 0x28) * 0x224,
                     (int)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c));
      }
      else {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_18 * 0x28) + 0x14) * 0x224,
                     (int)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c));
      }
      switch(local_1c) {
      case 0:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 4) * 0x2c),iVar1 + -0x1e,iVar2 + -0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c),iVar1 + -0x1e,iVar2 + -0x37,2)
        ;
        break;
      case 1:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 4) * 0x2c),iVar1 + -0x1e,iVar2 + 0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c),iVar1 + -0x1e,iVar2 + 0x37,2);
        break;
      case 2:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 4) * 0x2c),iVar1 + 0x50,iVar2 + 0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c),iVar1 + 0x50,iVar2 + 0x37,2);
        break;
      case 3:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 4) * 0x2c),iVar1 + 0x50,iVar2 + -0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_18 + 0xc) * 0x2c),iVar1 + 0x50,iVar2 + -0x37,2);
      }
    }
  }
  return;
}


// ==== FUN_00409bc7 @ 00409bc7

void FUN_00409bc7(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_18;
  int local_14;
  uint local_10;
  
  for (local_10 = 0; (int)local_10 < 4; local_10 = local_10 + 1) {
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 8) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 4) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 0xc) * 0x2c));
  }
  iVar1 = DAT_0041ed00 * 0x27;
  iVar2 = DAT_00416dac - (DAT_0041ed04 * 0x27 + 0x19);
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    local_10 = DAT_0041ecdc + local_14;
    if ((int)local_10 < 0) {
      local_10 = local_10 + 4;
    }
    if (3 < (int)local_10) {
      uVar3 = (int)local_10 >> 0x1f;
      local_10 = ((local_10 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
    }
    if (*(int *)(&DAT_0041ecc8 + local_14 * 4) != 0) {
      FUN_004100fa(&DAT_0041f820,(int)(&DAT_00427fe0 + (local_14 + 8) * 0x2c));
      FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 8) * 0x2c),iVar1 + 0x19,iVar2,1);
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_14 + 8) * 0x2c),local_10 * 2 + 1);
    }
    if (*(int *)(&DAT_0041ed64 + local_14 * 0x28) != 0) {
      local_18 = DAT_0041ecdc + local_14;
      if ((int)local_18 < 0) {
        local_18 = local_18 + 4;
      }
      if (3 < (int)local_18) {
        uVar3 = (int)local_18 >> 0x1f;
        local_18 = ((local_18 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      FUN_004100fa(&DAT_0041f5fc,(int)(&DAT_00427fe0 + (local_14 + 4) * 0x2c));
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),0);
      if (*(int *)(&DAT_0041ed68 + local_14 * 0x28) == 1) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x1e) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      else if (*(int *)(&DAT_0041ed68 + local_14 * 0x28) == 2) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x28) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      else {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x14) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      switch(local_18) {
      case 0:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + -0x1e,iVar2 + 0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + -0x1e,iVar2 + 0x37,2);
        break;
      case 1:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + 0x50,iVar2 + 0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + 0x50,iVar2 + 0x37,2);
        break;
      case 2:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + 0x50,iVar2 + -0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + 0x50,iVar2 + -0x37,2);
        break;
      case 3:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + -0x1e,iVar2 + -0x37,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + -0x1e,iVar2 + -0x37,2)
        ;
      }
    }
  }
  return;
}


// ==== FUN_0040a0aa @ 0040a0aa

void FUN_0040a0aa(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_18;
  int local_14;
  uint local_10;
  
  for (local_10 = 0; (int)local_10 < 4; local_10 = local_10 + 1) {
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 8) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 4) * 0x2c));
    FUN_0040ef59((int *)(&DAT_00427fe0 + (local_10 + 0xc) * 0x2c));
  }
  iVar1 = DAT_0041ed00 * 0x27;
  iVar2 = iVar1 + 0x19;
  iVar3 = DAT_00416dac - (DAT_0041ed04 * 0x27 + 0x19);
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    local_10 = DAT_0041ecdc + local_14;
    if ((int)local_10 < 0) {
      local_10 = local_10 + 4;
    }
    if (3 < (int)local_10) {
      uVar4 = (int)local_10 >> 0x1f;
      local_10 = ((local_10 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4;
    }
    if (*(int *)(&DAT_0041ecc8 + local_14 * 4) != 0) {
      FUN_004100fa(&DAT_0041f820,(int)(&DAT_00427fe0 + (local_14 + 8) * 0x2c));
      FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 8) * 0x2c),iVar2,iVar3,1);
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_14 + 8) * 0x2c),local_10 * 2);
    }
    if (*(int *)(&DAT_0041ed64 + local_14 * 0x28) != 0) {
      local_18 = DAT_0041ecdc + local_14;
      if ((int)local_18 < 0) {
        local_18 = local_18 + 4;
      }
      if (3 < (int)local_18) {
        uVar4 = (int)local_18 >> 0x1f;
        local_18 = ((local_18 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4;
      }
      FUN_004100fa(&DAT_0041f5fc,(int)(&DAT_00427fe0 + (local_14 + 4) * 0x2c));
      FUN_0040ecf0((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),0);
      if (*(int *)(&DAT_0041ed68 + local_14 * 0x28) == 1) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x1e) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      else if (*(int *)(&DAT_0041ed68 + local_14 * 0x28) == 2) {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x28) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      else {
        FUN_004100fa(&DAT_0041f3d8 + (*(int *)(&DAT_0041ed64 + local_14 * 0x28) + 0x14) * 0x224,
                     (int)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c));
      }
      switch(local_18) {
      case 0:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + -0x34,iVar3,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + -0x34,iVar3,2);
        break;
      case 1:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar2,iVar3 + 0x4d,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar2,iVar3 + 0x4d,2);
        break;
      case 2:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar1 + 0x66,iVar3,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar1 + 0x66,iVar3,2);
        break;
      case 3:
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 4) * 0x2c),iVar2,iVar3 + -0x4d,5);
        FUN_0040ee99((int *)(&DAT_00427fe0 + (local_14 + 0xc) * 0x2c),iVar2,iVar3 + -0x4d,2);
      }
    }
  }
  return;
}


// ==== FUN_0040a574 @ 0040a574

void FUN_0040a574(void)

{
  FUN_0040ee99((int *)&DAT_00427fe0,*(int *)(&DAT_0041ccb8 + DAT_0041eef4 * 8) * 0x27 + 0x19,
               DAT_00416dac - (*(int *)(&DAT_0041ccbc + DAT_0041eef4 * 8) * 0x27 + 0x19),1);
  FUN_0040ecf0((int *)&DAT_00427fe0,0x10);
  return;
}


// ==== FUN_0040a5e8 @ 0040a5e8

void FUN_0040a5e8(void)

{
  DAT_004169bc = DAT_004169bc + 1;
  FUN_0040ecf0((int *)&DAT_00427fe0,0x10);
  if (4 < DAT_004169bc) {
    DAT_004169bc = 0;
    FUN_0040ecf0((int *)&DAT_00427fe0,0xe);
  }
  return;
}


// ==== FUN_0040a633 @ 0040a633

void FUN_0040a633(void)

{
  if (DAT_0041689c != 0) {
    DAT_0041689c = DAT_0041689c + 1;
    if (DAT_0041689c < 3) {
      FUN_0040ecf0((int *)&DAT_004282f8,DAT_0041689c);
    }
    else if (DAT_0041689c < 0xb) {
      FUN_0040ecf0((int *)&DAT_004282f8,2);
    }
    else if (DAT_0041689c < 0xd) {
      FUN_0040ecf0((int *)&DAT_004282f8,1);
    }
    else if (0xd < DAT_0041689c) {
      FUN_0040ecf0((int *)&DAT_004282f8,0);
      DAT_0041689c = 0;
    }
  }
  return;
}


// ==== FUN_0040a700 @ 0040a700

void FUN_0040a700(void)

{
  if (DAT_004168a0 == 0) {
    if (*(int *)(&DAT_0041cd34 + (DAT_0041cca0 + 1) * 0x28 + DAT_0041cca4 * 400) != 0) {
      DAT_004168a0 = 6;
      FUN_004014f3(0x12);
      FUN_0040ecf0((int *)&DAT_00428324,1);
    }
  }
  else if (*(int *)(&DAT_0041cd34 + (DAT_0041cca0 + 1) * 0x28 + DAT_0041cca4 * 400) == 0) {
    DAT_004168a0 = DAT_004168a0 + -1;
    if (DAT_004168a0 < 3) {
      FUN_0040ecf0((int *)&DAT_00428324,1);
    }
    if (DAT_004168a0 < 1) {
      FUN_0040ecf0((int *)&DAT_00428324,0);
      DAT_004168a0 = 0;
    }
  }
  else {
    FUN_0040ecf0((int *)&DAT_00428324,2);
  }
  return;
}


// ==== FUN_0040a80d @ 0040a80d

void FUN_0040a80d(void)

{
  int iVar1;
  int local_14;
  int local_10;
  
  iVar1 = FUN_0040675f((int)(s_____________________00415318 + DAT_004144fc * 200),&DAT_0041cd28);
  if (iVar1 != 0) {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        if (*(int *)(&DAT_0041cd28 + local_14 * 0x28 + local_10 * 400) != 0) {
          switch(*(undefined4 *)(&DAT_0041cd28 + local_14 * 0x28 + local_10 * 400)) {
          case 1:
            FUN_0040ecf0((int *)&DAT_00427fe0,0xc);
            FUN_0040ecf0((int *)&DAT_004282f8,0);
            FUN_0040ee99((int *)&DAT_004282f8,local_14 * 0x27 + 0x19,
                         (DAT_00416dac - (local_10 * 0x27 + 0x19)) + 3,0x14);
            break;
          case 2:
            FUN_0040ecf0((int *)&DAT_00427fe0,0xf);
            FUN_0040ee99((int *)&DAT_00427fe0,local_14 * 0x27 + 0x19,
                         DAT_00416dac - ((local_10 + -1) * 0x27 + 0x19),1);
            FUN_0040e40e((int *)&DAT_00427fe0);
            FUN_0040ecf0((int *)&DAT_00427fe0,0xc);
            FUN_0040ee99((int *)&DAT_0042800c,local_14 * 0x27 + 0x11,
                         DAT_00416dac - ((local_10 + -1) * 0x27 + 0x19),1);
            FUN_0040ee99((int *)&DAT_00428038,local_14 * 0x27 + 0x20,
                         DAT_00416dac - ((local_10 + -1) * 0x27 + 0x19),1);
            FUN_0040ee99((int *)&DAT_00428324,local_14 * 0x27 + 0x18,
                         (DAT_00416dac - (local_10 * 0x27 + 0x19)) + 3,0x14);
            FUN_0040ecf0((int *)&DAT_00428324,0);
            break;
          case 3:
            FUN_0040ecf0((int *)&DAT_00427fe0,0xb);
            FUN_0040ee99((int *)&DAT_00427fe0,local_14 * 0x27 + 0x19,
                         DAT_00416dac - (local_10 * 0x27 + 0x19),1);
            FUN_0040e40e((int *)&DAT_00427fe0);
            FUN_0040ecf0((int *)&DAT_00427fe0,10);
            FUN_0040ee99((int *)&DAT_00428064,local_14 * 0x27 + 0x19,
                         DAT_00416dac - (local_10 * 0x27 + 0x19),1);
            FUN_0040ef59((int *)&DAT_00428064);
            break;
          case 4:
            FUN_0040ecf0((int *)&DAT_00427fe0,4);
            break;
          case 5:
            FUN_0040ecf0((int *)&DAT_00427fe0,0xd);
            break;
          case 6:
            FUN_0040ecf0((int *)&DAT_00427fe0,7);
            break;
          case 7:
            FUN_0040ecf0((int *)&DAT_00427fe0,10);
            break;
          case 8:
            FUN_0040ecf0((int *)&DAT_00427fe0,9);
            break;
          case 9:
            FUN_0040ecf0((int *)&DAT_00427fe0,5);
            break;
          case 10:
            FUN_0040ecf0((int *)&DAT_00427fe0,2);
            break;
          case 0xb:
            FUN_0040ecf0((int *)&DAT_00427fe0,3);
            break;
          case 0xc:
            FUN_0040ecf0((int *)&DAT_00427fe0,0);
            break;
          default:
            goto switchD_0040ac2b_default;
          }
          FUN_0040ee99((int *)&DAT_00427fe0,local_14 * 0x27 + 0x19,
                       DAT_00416dac - (local_10 * 0x27 + 0x19),1);
          FUN_0040e40e((int *)&DAT_00427fe0);
        }
switchD_0040ac2b_default:
      }
    }
    FUN_0040ee99((int *)&DAT_00427fe0,-100,-100,-1);
    FID_conflict__memcpy(&DAT_0041ecc8,(void *)(DAT_004144fc * 0x28 + 0x414e40),0x28);
    DAT_0041ecdc = 0;
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      if (-1 < *(int *)(&DAT_0041ccb8 + local_10 * 8)) {
        DAT_0041eef4 = local_10;
        break;
      }
    }
    FUN_0040a574();
    FUN_0040a0aa();
    FUN_0040ef59((int *)&DAT_0042842c);
    if (*(int *)(DAT_004144fc * 0x28 + 0x414e50) != 0) {
      FUN_0040ee99((int *)&DAT_0042842c,DAT_0041ed00 * 0x27 + 0x19,
                   DAT_00416dac - (DAT_0041ed04 * 0x27 + 0x19),2);
    }
  }
  return;
}


// ==== FUN_0040adbd @ 0040adbd

undefined4 __cdecl FUN_0040adbd(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_8;
  
  if (*(int *)(&DAT_0041ccb8 + (param_1 % 3) * 8) < 0) {
    uVar1 = 0;
  }
  else {
    local_8 = param_1 % 3 - DAT_0041ecdc;
    if ((int)local_8 < 0) {
      local_8 = local_8 + 4;
    }
    if (3 < (int)local_8) {
      uVar2 = (int)local_8 >> 0x1f;
      local_8 = ((local_8 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2;
    }
    uVar1 = *(undefined4 *)(&DAT_0041ecc8 + local_8 * 4);
  }
  return uVar1;
}


// ==== FUN_0040ae36 @ 0040ae36

void FUN_0040ae36(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  
  DAT_004169c0 = 0;
  iVar1 = *(int *)(&DAT_0041ccb8 + DAT_0041eef4 * 8);
  iVar2 = *(int *)(&DAT_0041ccbc + DAT_0041eef4 * 8);
  local_38 = DAT_0041eef4 - DAT_0041ecdc;
  if (local_38 < 0) {
    local_38 = local_38 + 4;
  }
  if ((*(int *)(&DAT_0041ed64 + local_38 * 0x28) != 0) ||
     (*(int *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) != 0)) {
    local_3c = 0;
    local_44 = 0;
    if (*(int *)(&DAT_0041cd2c + iVar1 * 0x28 + iVar2 * 400) == 2) {
      local_3c = -((DAT_0041eef8 * 7) / 2);
      local_44 = -0x13;
    }
    else if (*(int *)(&DAT_0041cd2c + iVar1 * 0x28 + iVar2 * 400) == 3) {
      local_3c = 0x13;
      local_44 = -((DAT_0041eef8 * 7) / 2);
    }
    else if (*(int *)(&DAT_0041cd2c + iVar1 * 0x28 + iVar2 * 400) == 4) {
      local_3c = -0x13;
      local_44 = (DAT_0041eef8 * 7) / 2;
    }
    if (*(int *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) == 0) {
      local_40 = local_38 + 0xc;
      local_3c = -local_3c;
      local_44 = -local_44;
    }
    else {
      local_40 = iVar2 * 10 + iVar1 + 0x1c;
    }
    FUN_0040edfa((int *)(&DAT_00427fe0 + local_40 * 0x2c),local_3c,local_44);
    FUN_0040d119(0);
    DAT_00416db4 = 1;
    SelectPalette(DAT_0041ef00,DAT_00416da0,0);
    RealizePalette(DAT_0041ef00);
    FUN_0040e6b5();
    FUN_0040d15f(0);
    Sleep(10);
    uVar3 = *(undefined4 *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400);
    uVar4 = *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400);
    *(undefined4 *)(&DAT_0041cd34 + iVar1 * 0x28 + iVar2 * 400) =
         *(undefined4 *)(&DAT_0041ed64 + local_38 * 0x28);
    *(undefined4 *)(&DAT_0041cd38 + iVar1 * 0x28 + iVar2 * 400) =
         *(undefined4 *)(&DAT_0041ed68 + local_38 * 0x28);
    *(undefined4 *)(&DAT_0041ed64 + local_38 * 0x28) = uVar3;
    *(undefined4 *)(&DAT_0041ed68 + local_38 * 0x28) = uVar4;
    FUN_004079ff(iVar2,iVar1,1);
    FUN_004014f3(0xd);
    FUN_0040a0aa();
  }
  return;
}


// ==== FUN_0040b129 @ 0040b129

void FUN_0040b129(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar1 = DAT_0041eef4;
  local_c = 1;
  do {
    if (2 < local_c) {
LAB_0040b196:
      if (iVar1 != DAT_0041eef4) {
        FUN_004014f3(0xb);
        FUN_0040a574();
      }
      return;
    }
    iVar2 = FUN_0040adbd((local_c + DAT_0041eef4) % 3);
    if (iVar2 != 0) {
      DAT_0041eef4 = (local_c + DAT_0041eef4) % 3;
      goto LAB_0040b196;
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== FUN_0040b1bd @ 0040b1bd

void FUN_0040b1bd(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar1 = DAT_0041eef4;
  local_c = 2;
  do {
    if (local_c < 0) {
LAB_0040b22a:
      if (iVar1 != DAT_0041eef4) {
        FUN_004014f3(0xb);
        FUN_0040a574();
      }
      return;
    }
    iVar2 = FUN_0040adbd((local_c + DAT_0041eef4) % 3);
    if (iVar2 != 0) {
      DAT_0041eef4 = (local_c + DAT_0041eef4) % 3;
      goto LAB_0040b22a;
    }
    local_c = local_c + -1;
  } while( true );
}


// ==== FUN_0040b251 @ 0040b251

void __cdecl FUN_0040b251(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (((param_2 != 0) || (DAT_004169c8 < DAT_004169c4)) &&
     ((DAT_004169c8 = DAT_004169c4, 3 < DAT_0041ecd8 ||
      ((-1 < (int)(DAT_0041ecdc + param_1) && ((int)(DAT_0041ecdc + param_1) <= DAT_0041ecd8)))))) {
    DAT_0041ecdc = DAT_0041ecdc + param_1;
    if ((int)DAT_0041ecdc < 0) {
      DAT_0041ecdc = DAT_0041ecdc + 4;
    }
    if (0 < (int)DAT_0041ecdc) {
      uVar2 = (int)DAT_0041ecdc >> 0x1f;
      DAT_0041ecdc = ((DAT_0041ecdc ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2;
    }
    iVar1 = FUN_0040adbd(DAT_0041eef4);
    if (iVar1 == 0) {
      DAT_0041eef4 = DAT_0041eef4 + param_1;
      if (DAT_0041eef4 < 0) {
        DAT_0041eef4 = 2;
      }
      else if (2 < DAT_0041eef4) {
        DAT_0041eef4 = 0;
      }
      iVar1 = FUN_0040adbd(DAT_0041eef4);
      if (iVar1 == 0) {
        DAT_0041eef4 = DAT_0041eef4 + param_1;
        if (DAT_0041eef4 < 0) {
          DAT_0041eef4 = 2;
        }
        else if (2 < DAT_0041eef4) {
          DAT_0041eef4 = 0;
        }
      }
      FUN_0040a574();
    }
    FUN_004014f3(10);
    if (param_1 < 1) {
      FUN_00409bc7();
      FUN_0040d119(0);
      SelectPalette(DAT_0041ef00,DAT_00416da0,0);
      RealizePalette(DAT_0041ef00);
      FUN_0040e6b5();
      FUN_0040d15f(0);
      if (DAT_004144fc == 8) {
        Sleep(10);
      }
      else {
        Sleep(0x14);
      }
    }
    else {
      FUN_004096cd();
      FUN_0040d119(0);
      SelectPalette(DAT_0041ef00,DAT_00416da0,0);
      RealizePalette(DAT_0041ef00);
      FUN_0040e6b5();
      FUN_0040d15f(0);
      if (DAT_004144fc == 8) {
        Sleep(10);
      }
      else {
        Sleep(0x14);
      }
    }
    FUN_0040a0aa();
  }
  return;
}


// ==== FUN_0040b471 @ 0040b471

void __cdecl FUN_0040b471(int param_1)

{
  HDC hDC;
  LPCSTR pCVar1;
  void *pvVar2;
  undefined1 *puVar3;
  
  if (((((DAT_004144fc == 1) || (DAT_004144fc == 5)) || (DAT_004144fc == 8)) ||
      ((DAT_004144fc == 0xb || (DAT_004144fc == 0xe)))) ||
     ((DAT_004144fc == 0x11 || (DAT_004144fc == 0x13)))) {
    FUN_004011f5(*(int *)(DAT_004144fc * 0x60 + 0x414680));
  }
  FUN_004070d6();
  hDC = GetDC((HWND)0x0);
  puVar3 = &DAT_00427cd8;
  pvVar2 = DAT_00416de4;
  pCVar1 = FUN_0040d050((uint *)s_BACKGROUND_00416d00,*(int *)(DAT_004144fc * 0x60 + 0x414678),2);
  FUN_0040d53c(hDC,pCVar1,pvVar2,puVar3);
  ReleaseDC((HWND)0x0,hDC);
  FUN_0040e0ab(DAT_0041eca4,(int)DAT_00416de4,0x18b,DAT_00416dac);
  FUN_004091dd();
  DAT_00416560 = *(int *)(DAT_004144fc * 0x60 + 0x414664);
  if (DAT_00416560 < 6) {
    DAT_00416560 = 6;
  }
  DAT_00416878 = *(int *)(DAT_004144fc * 0x60 + 0x414660);
  if (DAT_00416878 < 0x32) {
    DAT_00416878 = 0x32;
  }
  if (200 < DAT_00416878) {
    DAT_00416878 = 200;
  }
  DAT_0041eef8 = 0xffffffff;
  DAT_004169ac = 0;
  DAT_004169b4 = 0;
  FUN_00406e93();
  FUN_00406f06();
  FUN_00406f16();
  FUN_0040a80d();
  DAT_00416898 = *(undefined4 *)(DAT_004144fc * 0x60 + 0x414668);
  FUN_00406f7e();
  FUN_00406fd2();
  FUN_004092b1();
  DAT_00416db4 = 1;
  if (param_1 != 0) {
    FUN_0040d119(0);
    DAT_00416db4 = 1;
    SelectPalette(DAT_0041ef00,DAT_00416da0,0);
    RealizePalette(DAT_0041ef00);
    FUN_0040e6b5();
    FUN_0040d15f(0);
  }
  if ((DAT_00414508 != 0) && (DAT_00414500 == DAT_004144fc)) {
    FUN_004031ef();
  }
  if (DAT_0041450c != 0) {
    FUN_00402f0d(DAT_004144fc);
  }
  return;
}


// ==== FUN_0040b6c8 @ 0040b6c8

void __cdecl FUN_0040b6c8(int param_1)

{
  int local_8;
  
  DAT_0041687c = 0;
  DAT_00416884 = 0;
  DAT_0041688c = 0;
  DAT_004144f8 = 0;
  DAT_004169ac = 0;
  DAT_004144fc = DAT_00414500;
  if ((DAT_00414500 < 1) || (0x14 < DAT_00414500)) {
    DAT_004144fc = 1;
  }
  FUN_0040ee99((int *)&DAT_004282a0,0x205,DAT_00416dac + -0x19,1);
  FUN_0040ee99((int *)&DAT_004282cc,0x213,DAT_00416dac + -0x19,1);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040ee99((int *)(&DAT_00427fe0 + (local_8 + 0x14) * 0x2c),local_8 * 0xe + 0x1ee,
                 DAT_00416dac + -0x3b,1);
  }
  FUN_0040b471(param_1);
  return;
}


// ==== FUN_0040b7e6 @ 0040b7e6

void FUN_0040b7e6(void)

{
  return;
}


// ==== FUN_0040b7f6 @ 0040b7f6

void FUN_0040b7f6(void)

{
  INT_PTR IVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = DAT_00414024;
  local_10 = DAT_00414504;
  local_c = DAT_00414500;
  FUN_0040331c();
  if ((local_8 != DAT_00414024) && (DAT_0041688c == 0)) {
    FUN_004011f5(*(int *)(DAT_004144fc * 0x60 + 0x414680));
  }
  if ((DAT_00414504 != local_10) || (DAT_00414500 != local_c)) {
    if ((DAT_0041687c == 0) && (DAT_00416884 == 0)) {
      IVar1 = FUN_0040307b();
      if (IVar1 != 1) {
        return;
      }
      iVar2 = FUN_00402988(DAT_004144f8,&local_14);
      if ((iVar2 != 0) && (local_14 < 10)) {
        if (DAT_00414514 != 0) {
          FUN_0040325e();
        }
        iVar2 = FUN_00402a25(DAT_004144f8);
        if (0 < iVar2) {
          DAT_004169a8 = local_14;
          FUN_004032ad();
        }
        FUN_00402b69();
      }
      DAT_00416884 = 1;
    }
    SendMessageA(DAT_0041ef48,0x111,0x65,1);
  }
  FUN_00402b69();
  return;
}


// ==== FUN_0040b92b @ 0040b92b

void __cdecl FUN_0040b92b(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    if ((DAT_00416884 == 0) && (DAT_0041687c == 0)) {
      DAT_0041688c = 1;
    }
    FUN_00406fd2();
    DAT_00416880 = 0;
    FUN_00402b69();
    FUN_004011f5(0);
  }
  else {
    DAT_00416880 = 1;
    FUN_004026f8();
    if (DAT_0041688c == 0) {
      FUN_004011f5(*(int *)(DAT_004144fc * 0x60 + 0x414680));
    }
  }
  InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
  DAT_00416894 = 0;
  return;
}


// ==== FUN_0040b9da @ 0040b9da

undefined4 FUN_0040b9da(void)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_00416884 == 0) && (DAT_0041687c == 0)) {
    IVar1 = FUN_00403003();
    if (IVar1 == 1) {
      iVar2 = FUN_00402988(DAT_004144f8,&local_8);
      if ((iVar2 != 0) && (local_8 < 10)) {
        if (DAT_00414514 != 0) {
          FUN_0040325e();
        }
        iVar2 = FUN_00402a25(DAT_004144f8);
        if (0 < iVar2) {
          DAT_004169a8 = local_8;
          FUN_004032ad();
        }
        FUN_00402b69();
      }
      SendMessageA(DAT_0041ef48,2,0,0);
      WinHelpA(DAT_0041ef48,s_ratpoker_hlp_00416578,2,0);
    }
  }
  else {
    SendMessageA(DAT_0041ef48,2,0,0);
    WinHelpA(DAT_0041ef48,s_ratpoker_hlp_00416578,2,0);
  }
  FUN_00402b69();
  return 0;
}


// ==== FUN_0040bacd @ 0040bacd

void __cdecl FUN_0040bacd(undefined4 param_1,undefined4 param_2,ushort param_3)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  if (param_3 < 0xca) {
    if (param_3 == 0xc9) {
      if ((DAT_0041687c != 0) || (DAT_00416884 != 0)) {
        SendMessageA(DAT_0041ef48,0x111,0x65,0);
        return;
      }
      DAT_0041688c = (uint)(DAT_0041688c == 0);
      if (DAT_0041688c == 0) {
        FUN_00401118(*(int *)(DAT_004144fc * 0x60 + 0x414680));
      }
      else {
        InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
        UpdateWindow(DAT_0041ef48);
        FUN_004010a5();
      }
      FUN_00406fd2();
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    }
    else {
      switch(param_3) {
      case 0x65:
        if ((DAT_00416884 == 0) && (DAT_0041687c == 0)) {
          IVar1 = FUN_0040307b();
          if (IVar1 != 1) {
            return;
          }
          iVar2 = FUN_00402988(DAT_004144f8,&local_8);
          if ((iVar2 != 0) && (local_8 < 10)) {
            if (DAT_00414514 != 0) {
              FUN_0040325e();
            }
            iVar2 = FUN_00402a25(DAT_004144f8);
            if (0 < iVar2) {
              DAT_004169a8 = local_8;
              FUN_004032ad();
            }
            FUN_00402b69();
          }
        }
        FUN_004011f5(*(int *)(DAT_004144fc * 0x60 + 0x414680));
        FUN_0040b6c8(1);
        break;
      case 0x66:
        DAT_004169a8 = -1;
        FUN_004032ad();
        break;
      case 0x67:
        SendMessageA(DAT_0041ef48,0x10,0,0);
        break;
      case 0x68:
        FUN_0040b7f6();
      }
    }
  }
  else {
    switch(param_3) {
    case 0x12e:
      FUN_00403128();
      break;
    case 0x12f:
      WinHelpA(DAT_0041ef48,s_ratpoker_hlp_00416578,0xb,0);
      break;
    case 0x130:
      FUN_004031ef();
      break;
    case 0x131:
      DAT_0041450c = (uint)(DAT_0041450c == 0);
      FUN_00406fd2();
      break;
    case 0x22b:
      DAT_004144fc = DAT_004144fc + 1;
      Sleep(0xfa);
      if (DAT_004144fc < 0x15) {
        FUN_004014f3(0x10);
        FUN_0040b471(1);
      }
      else {
        DAT_004144fc = 0x14;
        PostMessageA(DAT_0041ef48,0x111,0x22c,0);
      }
      break;
    case 0x22c:
      DAT_00416884 = 1;
      FUN_00406fd2();
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
      if ((DAT_004144fc == 0x14) && (DAT_00416898 == 0)) {
        FUN_00402f0d(0x15);
      }
      iVar2 = FUN_00402988(DAT_004144f8,&local_8);
      if ((iVar2 == 0) || (9 < local_8)) {
        FUN_004014f3(0xf);
      }
      else {
        FUN_004014f3(0x11);
        if (DAT_00414514 != 0) {
          FUN_0040325e();
        }
        iVar2 = FUN_00402a25(DAT_004144f8);
        if (0 < iVar2) {
          DAT_004169a8 = local_8;
          FUN_004032ad();
        }
        FUN_00402b69();
      }
    }
  }
  return;
}


// ==== FUN_0040bf92 @ 0040bf92

void FUN_0040bf92(void)

{
  if ((DAT_00416880 != 0) && (DAT_0041688c == 0)) {
    FUN_004013d5();
  }
  return;
}


// ==== FUN_0040bfc6 @ 0040bfc6

void FUN_0040bfc6(void)

{
  if ((((DAT_00416880 != 0) && (DAT_004169c4 = DAT_004169c4 + 1, DAT_0041688c == 0)) &&
      (DAT_0041687c == 0)) &&
     (((DAT_00416884 == 0 && (DAT_00416888 == 0)) && ((DAT_00416894 == 0 && (DAT_00416890 == 0))))))
  {
    FUN_004092b1();
    FUN_0040a5e8();
    FUN_0040a633();
    FUN_0040a700();
    FUN_00409425();
    if (DAT_004169c0 != 0) {
      FUN_0040ae36();
    }
    FUN_0040d119(0);
    DAT_00416db4 = 1;
    SelectPalette(DAT_0041ef00,DAT_00416da0,0);
    RealizePalette(DAT_0041ef00);
    FUN_0040e6b5();
    FUN_0040d15f(0);
  }
  return;
}


// ==== FUN_0040c0af @ 0040c0af

UINT FUN_0040c0af(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  SHORT SVar1;
  HDC hDC;
  UINT UVar2;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      FUN_0040d119(1);
      SelectPalette(DAT_0041ef00,DAT_00416da0,0);
      RealizePalette(DAT_0041ef00);
      DAT_00416db4 = 1;
      if (DAT_0041687c != 0) {
        FUN_0040e6b5();
        FUN_0040d15f(1);
        return 0;
      }
      if (DAT_00416884 != 0) {
        FUN_0040e97c(0x18b,0,DAT_00416da8,DAT_00416dac);
        FUN_0040d1ea(DAT_0041ef00,DAT_0041eee8,0,0);
        FUN_0040d15f(1);
        return 0;
      }
      if (((DAT_0041688c == 0) && (DAT_00416888 == 0)) && (DAT_00416894 == 0)) {
        FUN_0040e6b5();
        FUN_0040d15f(1);
        return 0;
      }
      FUN_0040e97c(0x18b,0,DAT_00416da8,DAT_00416dac);
      FUN_0040d1ea(DAT_0041ef00,DAT_0041dce4,0,0);
      FUN_0040d15f(1);
      return 0;
    }
    if (param_2 == 1) {
      FUN_00402d40(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_004102bd();
      FUN_0040160d();
      FUN_00402b69();
      FUN_00402d83(param_1);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_004169c0 = 0;
      FUN_0040b92b(param_1,0x1c,(int)param_3);
      return 0;
    }
    if (param_2 == 0x10) {
      UVar2 = FUN_0040b9da();
      return UVar2;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(400);
      GdiFlush();
      Sleep(400);
      GdiFlush();
      DeleteObject(DAT_0041eee8);
      DeleteObject(DAT_0041dce4);
      hDC = GetDC((HWND)0x0);
      DAT_0041eee8 = FUN_0040d280(hDC,s_GAMEOVERBMP_00416d0c);
      DAT_0041dce4 = FUN_0040d280(hDC,s_PAUSEBMP_00416d18);
      ReleaseDC((HWND)0x0,hDC);
      Sleep(100);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_0041cd0c;
      *(undefined4 *)(param_4 + 0xc) = DAT_0041cd24;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_0041ef48,6);
        return 0;
      }
      if ((DAT_0041687c != 0) || (DAT_00416884 != 0)) {
        SendMessageA(DAT_0041ef48,0x111,0x65,0);
        return 0;
      }
      if (DAT_0041688c != 0) {
        SendMessageA(DAT_0041ef48,0x111,0xc9,0);
        return 0;
      }
      if ((param_3 == (HWND)0x20) || (param_3 == (HWND)0x26)) {
        DAT_004169c0 = 1;
      }
      if ((param_3 != (HWND)0x9) && (param_3 != (HWND)0x28)) {
        if (param_3 == (HWND)0x25) {
          FUN_0040b251(-1,0);
          if (DAT_004144fc == 8) {
            FUN_0040d119(0);
            SelectPalette(DAT_0041ef00,DAT_00416da0,0);
            RealizePalette(DAT_0041ef00);
            FUN_0040e6b5();
            FUN_0040d15f(0);
            Sleep(5);
            FUN_0040b251(-1,1);
          }
          FUN_0040d119(0);
          SelectPalette(DAT_0041ef00,DAT_00416da0,0);
          RealizePalette(DAT_0041ef00);
          FUN_0040e6b5();
          FUN_0040d15f(0);
          SVar1 = GetAsyncKeyState(0x11);
          if (((int)SVar1 & 0x80000000U) != 0) {
            DAT_0041eeec = 1;
            PostMessageA(DAT_0041ef48,0x100,9,0);
          }
          return 0;
        }
        if (param_3 == (HWND)0x27) {
          FUN_0040b251(1,0);
          if (DAT_004144fc == 8) {
            FUN_0040d119(0);
            SelectPalette(DAT_0041ef00,DAT_00416da0,0);
            RealizePalette(DAT_0041ef00);
            FUN_0040e6b5();
            FUN_0040d15f(0);
            Sleep(5);
            FUN_0040b251(1,1);
          }
          FUN_0040d119(0);
          SelectPalette(DAT_0041ef00,DAT_00416da0,0);
          RealizePalette(DAT_0041ef00);
          FUN_0040e6b5();
          FUN_0040d15f(0);
          SVar1 = GetAsyncKeyState(0x11);
          if (((int)SVar1 & 0x80000000U) != 0) {
            PostMessageA(DAT_0041ef48,0x100,9,0);
          }
          return 0;
        }
        return 0;
      }
      if ((DAT_0041eeec == 0) && (SVar1 = GetAsyncKeyState(0x10), ((int)SVar1 & 0x80000000U) == 0))
      {
        FUN_0040b129();
      }
      else {
        FUN_0040b1bd();
      }
      DAT_0041eeec = 0;
      FUN_0040d119(0);
      SelectPalette(DAT_0041ef00,DAT_00416da0,0);
      RealizePalette(DAT_0041ef00);
      FUN_0040e6b5();
      FUN_0040d15f(0);
      return 0;
    }
    if ((param_2 == 0x86) && (param_3 != (HWND)0x0)) {
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if ((DAT_0041687c == 0) && (DAT_00416884 == 0)) {
        if (DAT_0041688c != 0) {
          SendMessageA(DAT_0041ef48,0x111,0xc9,0);
          return 0;
        }
        FUN_0040b7e6();
        return 0;
      }
      SendMessageA(DAT_0041ef48,0x111,0x65,0);
      return 0;
    }
    if (param_2 == 0x111) {
      FUN_0040bacd(param_1,0x111,(ushort)param_3);
      return 0;
    }
    if (param_2 == 0x113) {
      FUN_0040bf92();
      return 0;
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_0040c6e2:
      UVar2 = FUN_00406e2c();
      return UVar2;
    }
    if (param_2 == 0x211) {
      DAT_004169c0 = 0;
      DAT_00416894 = 1;
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x212) {
      DAT_004169c0 = 0;
      DAT_00416894 = 0;
      InvalidateRect(DAT_0041ef48,(RECT *)0x0,0);
      return 0;
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_0041ef48 != param_3) goto LAB_0040c6e2;
  }
  else if (param_2 == 0x401) {
    FUN_0040bfc6();
    return 0;
  }
  UVar2 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar2;
}


// ==== FUN_0040c8b1 @ 0040c8b1

int __cdecl FUN_0040c8b1(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0040c8d2 @ 0040c8d2

int __cdecl FUN_0040c8d2(int param_1)

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


// ==== FUN_0040c90d @ 0040c90d

undefined4 FUN_0040c90d(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(s_RatPokerWnd_00416568,(LPCSTR)0x0);
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


// ==== FUN_0040c989 @ 0040c989

bool __cdecl FUN_0040c989(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040c9df @ 0040c9df

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_0040c9df(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  ATOM AVar2;
  DWORD DVar3;
  undefined3 extraout_var;
  HDC pHVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  BOOL BVar8;
  int iVar9;
  undefined4 *puVar10;
  HWND pHVar11;
  HMENU pHVar12;
  LPVOID pvVar13;
  DWORD local_dc;
  WNDCLASSA local_d8;
  DWORD local_b0;
  CHAR local_ac;
  undefined4 local_ab;
  undefined4 local_2c;
  DWORD local_28;
  tagMSG local_24;
  DWORD local_8;
  
  local_ac = DAT_00416d24;
  puVar10 = &local_ab;
  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  *(undefined1 *)((int)puVar10 + 2) = 0;
  local_2c = 0;
  DAT_0041ecac = param_1;
  iVar9 = FUN_0040c90d();
  if (iVar9 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_RatPokerGameMtx_00416d28);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_24.wParam = 0;
    }
    else {
      bVar1 = FUN_0040c989(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_24.wParam = 0;
      }
      else {
        pHVar4 = GetDC((HWND)0x0);
        iVar9 = GetDeviceCaps(pHVar4,0xc);
        if (iVar9 < 8) {
          ReleaseDC((HWND)0x0,pHVar4);
          local_24.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,pHVar4);
          FUN_0040218e();
          FUN_00402228((uint *)s_RATPOKER_DLL_00416678);
          FUN_004023d6((uint *)s_RATPOKE1_DLL_00416778);
          FUN_004021a6((uint *)s_MSPuzzle_dat_00414548);
          FUN_004023d6((uint *)s_ratpoker_hlp_00416578);
          FUN_00401fbb();
          FUN_00401fd5(DAT_0041ecac);
          FUN_00402014(s_RATPOKE1_DLL_00416778);
          FUN_00402014(s_RATPOKER_DLL_00416678);
          FUN_00406ddc();
          FUN_004026f8();
          DAT_004144fc = DAT_00414500;
          FUN_00401824();
          _DAT_0041ef50 = 0x300;
          _DAT_0041ef52 = 0x100;
          DAT_00416da8 = 0x26c;
          DAT_00416dac = 400;
          iVar9 = FUN_0040d9ce();
          if (iVar9 == 0) {
            FUN_0040160d();
            local_24.wParam = 0;
          }
          else {
            FUN_004071e2();
            pHVar4 = GetDC((HWND)0x0);
            iVar9 = FUN_0040d53c(pHVar4,s_TITLEBMP_00416d38,DAT_00416de4,&DAT_00427cd8);
            if (iVar9 == 0) {
              FUN_0040160d();
              local_24.wParam = 0;
            }
            else {
              FUN_00401ef0(DAT_0041ecac,100,&local_ac,0x78);
              DAT_0041eca4 = FUN_0040d492(s_LEVSCORE_00416d44);
              ReleaseDC((HWND)0x0,pHVar4);
              DAT_00416db8 = 0;
              DAT_00416dbc = &DAT_00427cd8;
              if (param_2 == 0) {
                local_d8.style = 0;
                local_d8.lpfnWndProc = FUN_0040c0af;
                local_d8.cbClsExtra = 0;
                local_d8.cbWndExtra = 0;
                local_d8.hIcon = (HICON)0x0;
                local_d8.hCursor = (HCURSOR)0x0;
                local_d8.hbrBackground = (HBRUSH)0x0;
                local_d8.lpszMenuName = (LPCSTR)0x0;
                local_d8.lpszClassName = (LPCSTR)0x0;
                local_d8.hInstance = DAT_0041ecac;
                local_d8.hIcon = LoadIconA(DAT_0041ecac,s_MAINICON_00416d50);
                local_d8.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
                local_d8.hbrBackground = GetStockObject(5);
                local_d8.lpszClassName = s_RatPokerWnd_00416568;
                AVar2 = RegisterClassA(&local_d8);
                if (AVar2 == 0) {
                  return 0xff;
                }
              }
              InitCommonControls();
              DAT_0041cca8 = FUN_00401dcb(DAT_0041ecac,s_ACCELERATORS_1_00416d5c);
              DAT_0041cc88 = FUN_00401e8e(DAT_0041ecac,s_MainMenuPlayed_00416d6c);
              DAT_0041eefc = FUN_00401e8e(DAT_0041ecac,s_MainMenu_00416d7c);
              if (DAT_0041cca8 == (HACCEL)0x0) {
                FUN_0040160d();
                local_24.wParam = 0;
              }
              else {
                local_b0 = GetVersion();
                if ((byte)local_b0 < 4) {
                  iVar9 = GetSystemMetrics(5);
                  DAT_0041cd0c = iVar9 * 2 + DAT_00416da8;
                  iVar9 = GetSystemMetrics(6);
                  iVar5 = GetSystemMetrics(4);
                  iVar6 = GetSystemMetrics(0xf);
                  DAT_0041cd24 = iVar9 * 2 + iVar5 + iVar6 + DAT_00416dac;
                  pvVar13 = (LPVOID)0x0;
                  pHVar11 = (HWND)0x0;
                  iVar9 = DAT_0041cd0c;
                  iVar5 = DAT_0041cd24;
                  pHVar12 = DAT_0041cc88;
                  iVar6 = FUN_0040c8d2(DAT_0041cd24);
                  iVar7 = FUN_0040c8b1(DAT_0041cd0c);
                  DAT_0041ef48 = CreateWindowExA(0,s_RatPokerWnd_00416568,&local_ac,0xca0000,iVar7,
                                                 iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,pvVar13);
                }
                else {
                  iVar9 = GetSystemMetrics(7);
                  DAT_0041cd0c = iVar9 * 2 + DAT_00416da8;
                  iVar9 = GetSystemMetrics(8);
                  iVar5 = GetSystemMetrics(4);
                  iVar6 = GetSystemMetrics(0xf);
                  DAT_0041cd24 = iVar9 * 2 + iVar5 + iVar6 + DAT_00416dac;
                  pvVar13 = (LPVOID)0x0;
                  pHVar11 = (HWND)0x0;
                  iVar9 = DAT_0041cd0c;
                  iVar5 = DAT_0041cd24;
                  pHVar12 = DAT_0041cc88;
                  iVar6 = FUN_0040c8d2(DAT_00416dac);
                  iVar7 = FUN_0040c8b1(DAT_0041cd0c);
                  DAT_0041ef48 = CreateWindowExA(0x100,s_RatPokerWnd_00416568,&local_ac,0xca0000,
                                                 iVar7,iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,
                                                 pvVar13);
                }
                ShowWindow(DAT_0041ef48,param_4);
                FUN_00410313();
                UpdateWindow(DAT_0041ef48);
                pHVar4 = GetDC((HWND)0x0);
                DAT_0041eee8 = FUN_0040d280(pHVar4,s_GAMEOVERBMP_00416d88);
                DAT_0041dce4 = FUN_0040d280(pHVar4,s_PAUSEBMP_00416d94);
                ReleaseDC((HWND)0x0,pHVar4);
                SetTimer(DAT_0041ef48,1,100,(TIMERPROC)0x0);
                FUN_00406fd2();
                local_28 = GetTickCount();
                local_dc = local_28;
                while( true ) {
                  while (BVar8 = PeekMessageA(&local_24,(HWND)0x0,0,0,1), BVar8 == 0) {
                    if (DAT_00416880 == 0) {
                      WaitMessage();
                    }
                    else {
                      SendMessageA(DAT_0041ef48,0x401,0,0);
                      DVar3 = GetTickCount();
                      local_8 = DAT_00416878 - (DVar3 - local_dc);
                      if (((int)local_8 < 4) || (DAT_00416878 < (int)local_8)) {
                        local_8 = 4;
                      }
                      local_28 = DVar3;
                      Sleep(local_8);
                      local_dc = DVar3;
                    }
                  }
                  if (local_24.message == 0x12) break;
                  if ((DAT_0041ef48 == (HWND)0x0) ||
                     (iVar9 = TranslateAcceleratorA(DAT_0041ef48,DAT_0041cca8,&local_24), iVar9 == 0
                     )) {
                    TranslateMessage(&local_24);
                    DispatchMessageA(&local_24);
                  }
                }
                FUN_004102bd();
                FUN_00402b69();
                FUN_0040160d();
              }
            }
          }
        }
      }
    }
  }
  else {
    local_24.wParam = 0;
  }
  return local_24.wParam;
}


// ==== FUN_0040d050 @ 0040d050

undefined * __cdecl FUN_0040d050(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_004106d0((uint *)&DAT_0041f358,param_1);
  sVar1 = _strlen(&DAT_0041f358);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_0041f357)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_0041f358)[param_3 + sVar1] = 0;
  return &DAT_0041f358;
}


// ==== FUN_0040d119 @ 0040d119

void __cdecl FUN_0040d119(int param_1)

{
  if (param_1 == 0) {
    DAT_0041ef00 = GetDC(DAT_0041ef48);
  }
  else {
    DAT_0041ef00 = BeginPaint(DAT_0041ef48,(LPPAINTSTRUCT)&DAT_0041ef08);
  }
  return;
}


// ==== FUN_0040d15f @ 0040d15f

void __cdecl FUN_0040d15f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_0041ef48,DAT_0041ef00);
  }
  else {
    EndPaint(DAT_0041ef48,(PAINTSTRUCT *)&DAT_0041ef08);
  }
  return;
}


// ==== FUN_0040d1a1 @ 0040d1a1

bool __cdecl FUN_0040d1a1(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_0040d1ea @ 0040d1ea

bool __cdecl FUN_0040d1ea(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_0040d280 @ 0040d280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_0040d280(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_004019b8(DAT_0041ecac,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_00416da4 = 0;
        _DAT_0041ef50 = 0x300;
        _DAT_0041ef52 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_0041ef54)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_0041ef55)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_0041ef56)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_0041ef57)[local_28 * 4] = 0;
        }
        if (DAT_00416da0 == (HPALETTE)0x0) {
          DAT_00416da0 = CreatePalette((LOGPALETTE *)&DAT_0041ef50);
        }
      }
      hPal = SelectPalette(param_1,DAT_00416da0,0);
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


// ==== FUN_0040d492 @ 0040d492

HGLOBAL __cdecl FUN_0040d492(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_004019b8(DAT_0041ecac,param_1,(LPCSTR)0x2,&local_c);
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
      FreeResource(hResData);
    }
  }
  return hMem;
}


// ==== FUN_0040d53c @ 0040d53c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040d53c(HDC param_1,LPCSTR param_2,void *param_3,undefined1 *param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  LPVOID _Src;
  int iVar3;
  HPALETTE local_448;
  int local_444;
  undefined1 local_438 [14];
  short local_42a;
  int local_418;
  byte abStack_410 [1024];
  undefined1 *local_10;
  HGLOBAL local_c;
  DWORD local_8;
  
  local_10 = param_4;
  local_448 = (HPALETTE)0x0;
  local_c = FUN_004019b8(DAT_0041ecac,param_2,(LPCSTR)0x2,&local_8);
  if (local_c == (HGLOBAL)0x0) {
    uVar2 = 0;
  }
  else {
    _Src = LockResource(local_c);
    FID_conflict__memcpy(local_438,_Src,0x428);
    if (local_418 == 0) {
      local_418 = 0x100;
    }
    iVar3 = local_418 * 4 + 0x28;
    local_8 = local_8 - iVar3;
    if (local_8 == 0) {
      uVar2 = 0;
    }
    else {
      if (DAT_00416db0 < local_8) {
        local_8 = DAT_00416db0;
      }
      FID_conflict__memcpy(param_3,(void *)((int)_Src + iVar3),local_8);
      if (local_42a == 8) {
        _DAT_00416da4 = 0;
        _DAT_0041ef50 = 0x300;
        _DAT_0041ef52 = 0x100;
        for (local_444 = 0; puVar1 = local_10, local_444 < 0x100; local_444 = local_444 + 1) {
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 2] >> 2);
          local_10 = local_10 + 1;
          (&DAT_0041ef54)[local_444 * 4] = abStack_410[local_444 * 4 + 2];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 1] >> 2);
          local_10 = puVar1 + 2;
          (&DAT_0041ef55)[local_444 * 4] = abStack_410[local_444 * 4 + 1];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4] >> 2);
          local_10 = puVar1 + 3;
          (&DAT_0041ef56)[local_444 * 4] = abStack_410[local_444 * 4];
          (&DAT_0041ef57)[local_444 * 4] = 0;
        }
        if (DAT_00416da0 == (HPALETTE)0x0) {
          DAT_00416da0 = CreatePalette((LOGPALETTE *)&DAT_0041ef50);
        }
        local_448 = SelectPalette(param_1,DAT_00416da0,0);
        RealizePalette(param_1);
      }
      if ((local_42a == 8) && (local_448 != (HPALETTE)0x0)) {
        SelectPalette(param_1,local_448,0);
      }
      FreeResource(local_c);
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0040d7d0 @ 0040d7d0

void FUN_0040d7d0(void)

{
  DAT_00416db0 = DAT_00416dac * DAT_00416da8;
  DAT_00416dc0 = 0;
  DAT_00416dc4 = 0;
  DAT_00416dc8 = DAT_00416da8 + -1;
  DAT_00416dcc = DAT_00416dac + -1;
  return;
}


// ==== FUN_0040d81b @ 0040d81b

undefined4 * __cdecl FUN_0040d81b(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int local_c;
  undefined4 *local_8;
  
  iVar1 = (param_2 + 3U & 0xfffffffc) * param_3;
  puVar2 = _malloc(iVar1 + 0x428);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0x28;
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    *(undefined2 *)(puVar2 + 3) = 1;
    *(undefined2 *)((int)puVar2 + 0xe) = 8;
    puVar2[4] = 0;
    puVar2[5] = iVar1;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0x100;
    puVar2[9] = 0;
    local_8 = puVar2 + 10;
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      *local_8 = 0;
      local_8[1] = 0x800000;
      local_8[2] = 0x8000;
      local_8[3] = 0x808000;
      local_8[4] = 0x80;
      local_8[5] = 0x800080;
      local_8[6] = 0x8080;
      local_8[7] = 0xc0c0c0;
      local_8[8] = 0x808080;
      local_8[9] = 0xff0000;
      local_8[10] = 0xff00;
      local_8[0xb] = 0xffff00;
      local_8[0xc] = 0xff;
      local_8[0xd] = 0xff00ff;
      local_8[0xe] = 0xffff;
      local_8[0xf] = 0xffffff;
      local_8 = local_8 + 0x10;
    }
    *param_1 = local_8;
  }
  return puVar2;
}


// ==== FUN_0040d9ce @ 0040d9ce

undefined4 FUN_0040d9ce(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_0040d7d0();
  DAT_00416de4 = _malloc(DAT_00416db0);
  if (DAT_00416de4 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    _memset(DAT_00416de4,0,DAT_00416db0);
    puVar2 = FUN_0040d81b(&DAT_00416de4,DAT_00416da8,DAT_00416dac);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      DAT_00416dd0 = DAT_00416dc0;
      DAT_00416dd4 = DAT_00416dc4;
      DAT_00416dd8 = DAT_00416dc8;
      DAT_00416ddc = DAT_00416dcc;
      AfxResetMsgCache();
      FUN_0040da9b();
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== AfxResetMsgCache @ 0040da77

/* Library Function - Single Match
    void __stdcall AfxResetMsgCache(void)
   
   Library: Visual Studio 1998 Debug */

void AfxResetMsgCache(void)

{
  _memset(&DAT_0041f3d8,0,0x8900);
  return;
}


// ==== FUN_0040da9b @ 0040da9b

void FUN_0040da9b(void)

{
  int local_8;
  
  _memset(&DAT_00427fe0,0,0x2c00);
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00427fe8 + local_8 * 0x2c) = 0xffffffff;
    *(undefined4 *)(&DAT_00427ff0 + local_8 * 0x2c) = 1;
    *(undefined4 *)(&DAT_00427ff4 + local_8 * 0x2c) = 1;
    *(int *)(&DAT_00428000 + local_8 * 0x2c) = DAT_00416da8 + -1;
    *(int *)(&DAT_00428004 + local_8 * 0x2c) = DAT_00416dac + -1;
  }
  return;
}


// ==== FUN_0040db5a @ 0040db5a

void __cdecl FUN_0040db5a(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(DAT_0042dbe0 + DAT_00416da8 * param_2 + param_1) = param_3;
  return;
}


// ==== FUN_0040db86 @ 0040db86

undefined8 __cdecl FUN_0040db86(int param_1,uint param_2)

{
  return CONCAT44((int)((ulonglong)DAT_00416da8 * (ulonglong)param_2 >> 0x20),
                  *(undefined4 *)
                   (DAT_0042dbe0 + (int)((ulonglong)DAT_00416da8 * (ulonglong)param_2) + param_1));
}


// ==== FUN_0040dbaa @ 0040dbaa

void __cdecl FUN_0040dbaa(short *param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < *param_1; local_8 = local_8 + 1) {
    if ((*(int *)(param_1 + local_8 * 2 + 0x92) != 0) &&
       (*(int *)(param_1 + local_8 * 2 + 0xd2) != 0)) {
      _free(*(void **)(param_1 + local_8 * 2 + 0x92));
      (param_1 + local_8 * 2 + 0x92)[0] = 0;
      (param_1 + local_8 * 2 + 0x92)[1] = 0;
      (param_1 + local_8 * 2 + 0xd2)[0] = 0;
      (param_1 + local_8 * 2 + 0xd2)[1] = 0;
    }
  }
  _memset(param_1,0,0x224);
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    if (*(short **)(&DAT_00428008 + local_8 * 0x2c) == param_1) {
      *(undefined4 *)(&DAT_00428008 + local_8 * 0x2c) = 0;
    }
  }
  return;
}


// ==== FUN_0040dca7 @ 0040dca7

void __cdecl
FUN_0040dca7(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_6 < param_2) {
    *param_1 = param_6;
  }
  if (param_7 < param_3) {
    param_1[1] = param_7;
  }
  if (param_4 < param_8) {
    param_1[2] = param_8;
  }
  if (param_5 < param_9) {
    param_1[3] = param_9;
  }
  return;
}


// ==== FUN_0040dd26 @ 0040dd26

bool __cdecl FUN_0040dd26(int *param_1,int *param_2)

{
  int iVar1;
  
  _memset(param_2,0,0x10);
  iVar1 = param_1[10];
  if (iVar1 != 0) {
    *param_2 = *param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4);
    param_2[1] = param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4);
    param_2[2] = (int)*(short *)(param_1[10] + 2 + param_1[3] * 4) + *param_2;
    param_2[3] = (int)*(short *)(param_1[10] + 4 + param_1[3] * 4) + param_2[1];
  }
  return iVar1 != 0;
}


// ==== FUN_0040ddda @ 0040ddda

void __cdecl FUN_0040ddda(LONG param_1,LONG param_2,LONG param_3,LONG param_4)

{
  int iVar1;
  BOOL BVar2;
  tagRECT local_1c;
  int local_c;
  
  BVar2 = IntersectRect(&local_1c,(RECT *)&param_1,(RECT *)&DAT_00416dc0);
  if (BVar2 != 0) {
    param_1 = local_1c.left;
    param_2 = local_1c.top;
    param_3 = local_1c.right;
    param_4 = local_1c.bottom;
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if ((*(int *)(&DAT_0042b3f0 + local_c * 0x14) != 0) &&
         (BVar2 = IntersectRect(&local_1c,(RECT *)(&DAT_0042b3e0 + local_c * 0x14),(RECT *)&param_1)
         , BVar2 != 0)) {
        iVar1 = local_c * 0x14;
        FUN_0040dca7(&param_1,*(int *)(&DAT_0042b3e0 + iVar1),*(int *)(&DAT_0042b3e4 + iVar1),
                     *(int *)(&DAT_0042b3e8 + iVar1),*(int *)(&DAT_0042b3ec + iVar1),param_1,param_2
                     ,param_3,param_4);
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_0042b3e0 + iVar1) = param_1;
        *(LONG *)(&DAT_0042b3e4 + iVar1) = param_2;
        *(LONG *)(&DAT_0042b3e8 + iVar1) = param_3;
        *(LONG *)(&DAT_0042b3ec + iVar1) = param_4;
        *(undefined4 *)(&DAT_0042b3f0 + local_c * 0x14) = 1;
        return;
      }
    }
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if (*(int *)(&DAT_0042b3f0 + local_c * 0x14) == 0) {
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_0042b3e0 + iVar1) = param_1;
        *(LONG *)(&DAT_0042b3e4 + iVar1) = param_2;
        *(LONG *)(&DAT_0042b3e8 + iVar1) = param_3;
        *(LONG *)(&DAT_0042b3ec + iVar1) = param_4;
        *(undefined4 *)(&DAT_0042b3f0 + local_c * 0x14) = 1;
        return;
      }
    }
  }
  return;
}


// ==== FUN_0040df73 @ 0040df73

void __cdecl
FUN_0040df73(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_2 = *param_1;
  *param_3 = param_1[1];
  *param_4 = param_1[2];
  return;
}


// ==== FUN_0040dfa3 @ 0040dfa3

void __cdecl FUN_0040dfa3(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00416da8 - param_3;
  iVar2 = param_3;
  do {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    param_1 = param_1 + iVar1;
    param_2 = param_2 + iVar1;
    param_4 = param_4 + -1;
    iVar2 = param_3;
  } while (param_4 != 0);
  return;
}


// ==== FUN_0040dfdc @ 0040dfdc

void __cdecl FUN_0040dfdc(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (DAT_00416da8 + -1 < param_5) {
    param_5 = DAT_00416da8 + -1;
  }
  if (DAT_00416dac + -1 < param_6) {
    param_6 = DAT_00416dac + -1;
  }
  if ((param_3 <= param_5) && (param_4 <= param_6)) {
    iVar1 = param_4 * DAT_00416da8 + param_3;
    FUN_0040dfa3((undefined1 *)(param_1 + iVar1),(undefined1 *)(param_2 + iVar1),
                 (param_5 - param_3) + 1,(param_6 - param_4) + 1);
  }
  return;
}


// ==== FUN_0040e0ab @ 0040e0ab

void __cdecl FUN_0040e0ab(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(param_1 + 8);
  local_c = *(int *)(param_1 + 0x20);
  if (local_c < 1) {
    local_c = 0x100;
  }
  puVar5 = (undefined1 *)(param_1 + local_c * 4 + 0x28);
  puVar6 = (undefined1 *)(param_2 + DAT_00416da8 * (param_4 - iVar4) + param_3);
  iVar2 = DAT_00416da8 - iVar1;
  iVar3 = iVar1;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar6 = puVar6 + iVar2;
    puVar5 = puVar5 + ((iVar1 + 3U & 0xfffffffc) - iVar1);
    iVar4 = iVar4 + -1;
    iVar3 = iVar1;
  } while (iVar4 != 0);
  return;
}


// ==== FUN_0040e160 @ 0040e160

void __cdecl
FUN_0040e160(char *param_1,char *param_2,uint param_3,int param_4,short param_5,char param_6)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar3 = param_3;
  do {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      if (cVar1 != param_6) {
        *param_2 = cVar1;
      }
      param_2 = param_2 + 1;
      uVar2 = (short)uVar3 - 1;
      uVar3 = (uint)uVar2;
    } while (uVar2 != 0);
    param_1 = param_1 + param_4;
    param_2 = param_2 + (DAT_00416da8 - param_3);
    param_5 = param_5 + -1;
    uVar3 = param_3;
  } while (param_5 != 0);
  return;
}


// ==== FUN_0040e1b5 @ 0040e1b5

void __cdecl
FUN_0040e1b5(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char param_7)

{
  uint uVar1;
  int local_1c;
  int local_10;
  int local_c;
  
  if ((param_1 <= DAT_00416dd8) && (param_2 <= DAT_00416ddc)) {
    local_10 = param_3 + param_1 + -1;
    local_c = 0;
    if (param_1 < DAT_00416dd0) {
      local_c = DAT_00416dd0 - param_1;
      param_1 = DAT_00416dd0;
    }
    local_1c = param_4 + param_2 + -1;
    if (param_2 < DAT_00416dd4) {
      local_c = local_c + (DAT_00416dd4 - param_2) * param_3;
      param_2 = DAT_00416dd4;
    }
    if (DAT_00416dd8 < local_10) {
      local_10 = DAT_00416dd8;
    }
    if (DAT_00416ddc < local_1c) {
      local_1c = DAT_00416ddc;
    }
    if ((((DAT_00416dd0 <= local_10) && (DAT_00416dd4 <= local_1c)) &&
        (uVar1 = (local_10 - param_1) + 1, 0 < (int)uVar1)) && ((int)uVar1 <= DAT_00416da8)) {
      FUN_0040e160((char *)(param_5 + local_c),(char *)(param_6 + param_2 * DAT_00416da8 + param_1),
                   uVar1,param_3 - uVar1,((short)local_1c - (short)param_2) + 1,param_7);
    }
  }
  return;
}


// ==== FUN_0040e319 @ 0040e319

void __cdecl FUN_0040e319(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_00416dd0 = param_1[6];
    DAT_00416dd4 = param_1[7];
    DAT_00416dd8 = param_1[8];
    DAT_00416ddc = param_1[9];
    FUN_0040e1b5(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_00416de0,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_0040e40e @ 0040e40e

void __cdecl FUN_0040e40e(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_00416dd0 = param_1[6];
    DAT_00416dd4 = param_1[7];
    DAT_00416dd8 = param_1[8];
    DAT_00416ddc = param_1[9];
    FUN_0040e1b5(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_00416de4,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_0040e503 @ 0040e503

undefined4 __cdecl FUN_0040e503(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_3[3] < 0) || ((int)*(short *)param_3[10] <= param_3[3])) || (param_3[10] == 0)) ||
     (param_3[2] < 1)) {
    uVar1 = 0;
  }
  else {
    DAT_00416dd0 = param_3[6];
    DAT_00416dd4 = param_3[7];
    DAT_00416dd8 = param_3[8];
    DAT_00416ddc = param_3[9];
    if ((param_1 < DAT_00416dd0) || (DAT_00416dd8 < param_1)) {
      uVar1 = 0;
    }
    else if ((param_2 < DAT_00416dd4) || (DAT_00416ddc < param_2)) {
      uVar1 = 0;
    }
    else {
      iVar2 = *param_3 - (int)*(short *)(param_3[10] + 0x82 + param_3[3] * 4);
      iVar3 = param_3[1] - (int)*(short *)(param_3[10] + 0x84 + param_3[3] * 4);
      if ((((iVar2 < param_1) && (param_1 < *(short *)(param_3[10] + 2 + param_3[3] * 4) + iVar2))
          && (iVar3 < param_2)) && (param_2 < *(short *)(param_3[10] + 4 + param_3[3] * 4) + iVar3))
      {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


// ==== FUN_0040e66b @ 0040e66b

undefined4 __cdecl FUN_0040e66b(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 4) == *(int *)(param_1 + 4)) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) < *(int *)(param_2 + 4)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0040e6b5 @ 0040e6b5

void FUN_0040e6b5(void)

{
  int iVar1;
  int local_2c;
  int local_28;
  
  if (DAT_00416db4 == 0) {
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_0042b3f0 + local_2c * 0x14) != 0) {
        iVar1 = local_2c * 0x14;
        FUN_0040dfdc((int)DAT_00416de4,(int)DAT_00416de0,*(int *)(&DAT_0042b3e0 + iVar1),
                     *(int *)(&DAT_0042b3e4 + iVar1),*(int *)(&DAT_0042b3e8 + iVar1),
                     *(int *)(&DAT_0042b3ec + iVar1));
      }
    }
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_0042abe0 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_0042abe4 + local_28 * 8) =
           *(undefined4 *)(&DAT_00427fe8 + local_28 * 0x2c);
    }
    _qsort(&DAT_0042abe0,0xff,8,FUN_0040e66b);
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_0042b3f0 + local_2c * 0x14) != 0) {
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          if (0 < *(int *)(&DAT_0042abe4 + local_28 * 8)) {
            FUN_0040e319((int *)(&DAT_00427fe0 + *(int *)(&DAT_0042abe0 + local_28 * 8) * 0x2c));
          }
        }
      }
    }
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_0042b3f0 + local_2c * 0x14) != 0) {
        FUN_004105b5((int *)(&DAT_0042b3e0 + local_2c * 0x14));
      }
    }
  }
  else {
    FID_conflict__memcpy(DAT_00416de0,DAT_00416de4,DAT_00416db0);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_0042abe0 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_0042abe4 + local_28 * 8) =
           *(undefined4 *)(&DAT_00427fe8 + local_28 * 0x2c);
    }
    _qsort(&DAT_0042abe0,0xff,8,FUN_0040e66b);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      if (0 < *(int *)(&DAT_0042abe4 + local_28 * 8)) {
        FUN_0040e319((int *)(&DAT_00427fe0 + *(int *)(&DAT_0042abe0 + local_28 * 8) * 0x2c));
      }
    }
    FUN_004105b5(&DAT_00416dc0);
    DAT_00416db4 = 0;
  }
  _memset(&DAT_0042b3e0,0,0x2800);
  GdiFlush();
  return;
}


// ==== FUN_0040e97c @ 0040e97c

void __cdecl FUN_0040e97c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  FID_conflict__memcpy(DAT_00416de0,DAT_00416de4,DAT_00416db0);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    *(int *)(&DAT_0042abe0 + local_38 * 8) = local_38;
    *(undefined4 *)(&DAT_0042abe4 + local_38 * 8) = *(undefined4 *)(&DAT_00427fe8 + local_38 * 0x2c)
    ;
  }
  _qsort(&DAT_0042abe0,0xff,8,FUN_0040e66b);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    if (0 < *(int *)(&DAT_0042abe4 + local_38 * 8)) {
      FUN_0040e319((int *)(&DAT_00427fe0 + *(int *)(&DAT_0042abe0 + local_38 * 8) * 0x2c));
    }
  }
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  FUN_004105b5(&local_34);
  GdiFlush();
  return;
}


// ==== FUN_0040ea8b @ 0040ea8b

void __cdecl FUN_0040ea8b(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    if (param_1[4] == 0) {
      if (param_1[5] == 0) {
        if (param_1[3] < 1) {
          param_1[5] = 1;
          param_1[3] = param_1[3] + 1;
        }
        else {
          param_1[3] = param_1[3] + -1;
        }
      }
      else if (param_1[3] < *(short *)param_1[10] + -1) {
        param_1[3] = param_1[3] + 1;
      }
      else {
        param_1[5] = 0;
        if (0 < param_1[3]) {
          param_1[3] = param_1[3] + -1;
        }
      }
    }
    else if (param_1[3] < *(short *)param_1[10] + -1) {
      param_1[3] = param_1[3] + 1;
    }
    else {
      param_1[3] = 0;
    }
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040ebcc @ 0040ebcc

void __cdecl FUN_0040ebcc(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    if (param_1[4] == 0) {
      if (param_1[5] == 0) {
        if (param_1[3] < (int)*(short *)param_1[10]) {
          param_1[3] = param_1[3] + 1;
        }
        else {
          param_1[5] = 1;
        }
      }
      else if (param_1[3] < 1) {
        param_1[5] = 0;
      }
      else {
        param_1[3] = param_1[3] + -1;
      }
    }
    else if (param_1[3] < 1) {
      param_1[3] = *(short *)param_1[10] + -1;
    }
    else {
      param_1[3] = param_1[3] + -1;
    }
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040ecf0 @ 0040ecf0

void __cdecl FUN_0040ecf0(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[3] != param_2)) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    if ((-1 < param_2) && (param_2 < *(short *)param_1[10])) {
      FUN_0040dd26(param_1,&local_14);
      FUN_0040ddda(local_14,local_10,local_c,local_8);
      param_1[3] = param_2;
      FUN_0040dd26(param_1,&local_14);
      FUN_0040ddda(local_14,local_10,local_c,local_8);
    }
  }
  return;
}


// ==== FUN_0040edc6 @ 0040edc6

void __cdecl FUN_0040edc6(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  return;
}


// ==== FUN_0040ede0 @ 0040ede0

void __cdecl FUN_0040ede0(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== FUN_0040edfa @ 0040edfa

void __cdecl FUN_0040edfa(int *param_1,int param_2,int param_3)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && ((param_2 != 0 || (param_3 != 0)))) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    *param_1 = *param_1 + param_2;
    param_1[1] = param_1[1] + param_3;
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040ee99 @ 0040ee99

void __cdecl FUN_0040ee99(int *param_1,int param_2,int param_3,int param_4)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) &&
     (((*param_1 != param_2 || (param_1[1] != param_3)) || (param_1[2] != param_4)))) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4;
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040ef59 @ 0040ef59

void __cdecl FUN_0040ef59(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (-1 < param_1[2])) {
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
    param_1[2] = -1;
  }
  return;
}


// ==== FUN_0040efc2 @ 0040efc2

void __cdecl FUN_0040efc2(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[2] != param_2)) {
    param_1[2] = param_2;
    FUN_0040dd26(param_1,&local_14);
    FUN_0040ddda(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040f02c @ 0040f02c

void __cdecl FUN_0040f02c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[10] = param_2;
  return;
}


// ==== FUN_0040f06c @ 0040f06c

void __cdecl FUN_0040f06c(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)((param_2 + param_5) - param_3);
  iVar2 = param_3;
  do {
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar3 + param_3 * -2;
    param_4 = param_4 + -1;
    iVar2 = param_3;
  } while (param_4 != 0);
  return;
}


// ==== FUN_0040f0b5 @ 0040f0b5

undefined4 __cdecl FUN_0040f0b5(LPCSTR param_1,short *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  short sVar5;
  short *psVar6;
  byte *pbVar7;
  short *psVar8;
  undefined1 local_7c4 [256];
  undefined1 local_6c4 [768];
  int local_3c4;
  int local_3c0;
  byte local_3bc [32];
  int local_39c;
  uint local_398;
  void *local_394;
  short local_390;
  HFILE local_38c;
  size_t local_388;
  undefined4 local_384;
  undefined4 uStack_380;
  undefined4 uStack_300;
  byte abStack_280 [32];
  uint local_260;
  short local_25c;
  short asStack_25a [64];
  undefined4 uStack_1da;
  byte abStack_15a [34];
  int aiStack_138 [32];
  size_t asStack_b8 [32];
  int local_38;
  undefined1 *local_34;
  undefined1 local_30 [32];
  undefined1 *local_10;
  int local_c;
  byte *local_8;
  
  local_10 = local_6c4;
  for (local_398 = 0; (int)local_398 <= *param_2 + -1; local_398 = local_398 + 1) {
    if ((*(int *)(param_2 + local_398 * 2 + 0x92) != 0) &&
       (*(int *)(param_2 + local_398 * 2 + 0xd2) != 0)) {
      _free(*(void **)(param_2 + local_398 * 2 + 0x92));
    }
  }
  _memset(param_2,0,0x224);
  _memset(&local_25c,0,0x224);
  *param_2 = 0;
  local_38c = _lopen(param_1,0);
  if (local_38c == -1) {
    uVar1 = 0;
  }
  else {
    local_388 = _hread(local_38c,&local_384,0x126);
    if (local_388 == 0x126) {
      if ((local_384 & 0xffff) == 1) {
        for (local_398 = 1; (int)local_398 <= (int)(local_260 & 0xffff); local_398 = local_398 + 1)
        {
          local_388 = _hread(local_38c,local_6c4,0x300);
          if (local_388 != 0x300) {
            _lclose(local_38c);
            return 0;
          }
        }
        local_25c = local_384._2_2_;
        for (local_398 = 0; (int)local_398 < (int)local_384._2_2_; local_398 = local_398 + 1) {
          *(undefined4 *)(asStack_25a + local_398 * 2) = (&uStack_380)[local_398];
          abStack_15a[local_398] = abStack_280[local_398];
          local_3bc[local_398] = abStack_280[local_398];
          (&uStack_1da)[local_398] = (&uStack_300)[local_398];
          *(short *)((int)&uStack_1da + local_398 * 4 + 2) =
               *(short *)((int)&uStack_380 + local_398 * 4 + 2) -
               *(short *)((int)&uStack_300 + local_398 * 4 + 2);
        }
        FID_conflict__memcpy(local_30,local_3bc,0x1f);
        if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
          local_34 = (undefined1 *)DAT_00416dbc;
          for (local_398 = 0; (int)local_398 < 0x100; local_398 = local_398 + 1) {
            local_3c4 = 0x7fff;
            local_38 = 0;
            for (local_39c = 0; local_39c < 0x100; local_39c = local_39c + 1) {
              iVar2 = FUN_00410e80((uint)*(byte *)(local_39c * 3 + 2 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3 + 2]);
              iVar3 = FUN_00410e80((uint)*(byte *)(local_39c * 3 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3]);
              local_c = FUN_00410e80((uint)*(byte *)(local_39c * 3 + 1 + (int)local_34) -
                                     (uint)(byte)local_10[local_398 * 3 + 1]);
              local_c = iVar2 + iVar3 + local_c;
              if (local_c < local_3c4) {
                local_3c4 = local_c;
                local_38 = local_39c;
              }
            }
            for (local_3c0 = 0; local_3c0 < 0x20; local_3c0 = local_3c0 + 1) {
              if (local_3bc[local_3c0] == local_398) {
                local_30[local_3c0] = (undefined1)local_38;
              }
            }
            local_7c4[local_398] = (undefined1)local_38;
          }
          local_34 = local_7c4;
        }
        for (local_398 = 0; (int)local_398 < (int)local_25c; local_398 = local_398 + 1) {
          asStack_b8[local_398] =
               (int)asStack_25a[local_398 * 2 + 1] * (int)asStack_25a[local_398 * 2];
          pvVar4 = _malloc(asStack_b8[local_398]);
          aiStack_138[local_398] = (int)pvVar4;
          if (aiStack_138[local_398] == 0) {
            for (local_3c0 = 0; local_3c0 < 0x20; local_3c0 = local_3c0 + 1) {
              if ((aiStack_138[local_3c0] != 0) && (asStack_b8[local_3c0] != 0)) {
                _free((void *)aiStack_138[local_3c0]);
              }
            }
            _lclose(local_38c);
            return 0;
          }
          local_388 = _hread(local_38c,(LPVOID)aiStack_138[local_398],asStack_b8[local_398]);
          if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
            pbVar7 = (byte *)aiStack_138[local_398];
            local_8 = pbVar7;
            sVar5 = (short)asStack_b8[local_398];
            local_390 = sVar5;
            for (; sVar5 != 0; sVar5 = sVar5 + -1) {
              *pbVar7 = local_34[*pbVar7];
              pbVar7 = pbVar7 + 1;
            }
          }
          if (asStack_b8[local_398] != local_388) {
            for (local_3c0 = 0; local_3c0 < 0x20; local_3c0 = local_3c0 + 1) {
              if ((aiStack_138[local_3c0] != 0) && (asStack_b8[local_3c0] != 0)) {
                _free((void *)aiStack_138[local_3c0]);
              }
            }
            _lclose(local_38c);
            return 0;
          }
        }
        _lclose(local_38c);
        psVar6 = &local_25c;
        psVar8 = param_2;
        for (iVar2 = 0x89; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined4 *)psVar8 = *(undefined4 *)psVar6;
          psVar6 = psVar6 + 2;
          psVar8 = psVar8 + 2;
        }
        if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
          for (local_398 = 0; (int)local_398 < (int)*param_2; local_398 = local_398 + 1) {
            *(undefined1 *)(local_398 + 0x102 + (int)param_2) = local_30[local_398];
          }
        }
        local_394 = _malloc(0x10000);
        if (local_394 == (void *)0x0) {
          uVar1 = 0;
        }
        else {
          for (local_398 = 0; (int)local_398 < (int)*param_2; local_398 = local_398 + 1) {
            FUN_0040f06c(*(undefined1 **)(param_2 + local_398 * 2 + 0x92),(int)local_394,
                         (int)param_2[local_398 * 2 + 1],(int)param_2[local_398 * 2 + 2],
                         (int)param_2[local_398 * 2 + 2] * (int)param_2[local_398 * 2 + 1]);
            FID_conflict__memcpy
                      (*(void **)(param_2 + local_398 * 2 + 0x92),local_394,
                       *(size_t *)(param_2 + local_398 * 2 + 0xd2));
          }
          _free(local_394);
          uVar1 = 1;
        }
      }
      else {
        _lclose(local_38c);
        uVar1 = 0;
      }
    }
    else {
      _lclose(local_38c);
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_0040f8bb @ 0040f8bb

undefined4 __cdecl FUN_0040f8bb(LPCSTR param_1,short *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  short sVar5;
  short *psVar6;
  byte *pbVar7;
  short *psVar8;
  undefined1 local_7d0 [256];
  undefined1 local_6d0 [768];
  DWORD local_3d0;
  LPVOID local_3cc;
  int local_3c8;
  int local_3c4;
  byte local_3c0 [32];
  int local_3a0;
  uint local_39c;
  void *local_398;
  short local_394;
  LPVOID local_390;
  undefined4 local_38c;
  undefined4 uStack_388;
  undefined4 uStack_308;
  byte abStack_288 [32];
  uint local_268;
  short local_264;
  short asStack_262 [64];
  undefined4 uStack_1e2;
  byte abStack_162 [34];
  int aiStack_140 [32];
  size_t asStack_c0 [32];
  int local_40;
  undefined1 *local_3c;
  undefined1 local_38 [32];
  undefined1 *local_18;
  HGLOBAL local_14;
  int local_10;
  byte *local_c;
  DWORD local_8;
  
  local_14 = FUN_004019b8(DAT_0041ecac,param_1,s_SPRITE_00416de8,&local_3d0);
  local_8 = local_3d0;
  if (local_14 == (HGLOBAL)0x0) {
    uVar1 = 0;
  }
  else {
    local_3cc = LockResource(local_14);
    local_18 = local_6d0;
    local_390 = local_3cc;
    for (local_39c = 0; (int)local_39c <= *param_2 + -1; local_39c = local_39c + 1) {
      if ((*(int *)(param_2 + local_39c * 2 + 0x92) != 0) &&
         (*(int *)(param_2 + local_39c * 2 + 0xd2) != 0)) {
        _free(*(void **)(param_2 + local_39c * 2 + 0x92));
      }
    }
    _memset(param_2,0,0x224);
    _memset(&local_264,0,0x224);
    *param_2 = 0;
    FID_conflict__memcpy(&local_38c,local_3cc,0x126);
    local_3cc = (void *)((int)local_3cc + 0x126);
    local_8 = local_8 - 0x126;
    if ((int)local_8 < 0) {
      FreeResource(local_14);
      uVar1 = 0;
    }
    else if ((local_38c & 0xffff) == 1) {
      for (local_39c = 1; (int)local_39c <= (int)(local_268 & 0xffff); local_39c = local_39c + 1) {
        FID_conflict__memcpy(local_6d0,local_3cc,0x300);
        local_3cc = (void *)((int)local_3cc + 0x300);
        local_8 = local_8 + -0x300;
        if ((int)local_8 < 0) {
          FreeResource(local_14);
          return 0;
        }
      }
      local_264 = local_38c._2_2_;
      for (local_39c = 0; (int)local_39c < (int)local_38c._2_2_; local_39c = local_39c + 1) {
        *(undefined4 *)(asStack_262 + local_39c * 2) = (&uStack_388)[local_39c];
        abStack_162[local_39c] = abStack_288[local_39c];
        local_3c0[local_39c] = abStack_288[local_39c];
        (&uStack_1e2)[local_39c] = (&uStack_308)[local_39c];
        *(short *)((int)&uStack_1e2 + local_39c * 4 + 2) =
             *(short *)((int)&uStack_388 + local_39c * 4 + 2) -
             *(short *)((int)&uStack_308 + local_39c * 4 + 2);
      }
      FID_conflict__memcpy(local_38,local_3c0,0x1f);
      if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
        local_3c = (undefined1 *)DAT_00416dbc;
        for (local_39c = 0; (int)local_39c < 0x100; local_39c = local_39c + 1) {
          local_3c8 = 0x7fff;
          local_40 = 0;
          for (local_3a0 = 0; local_3a0 < 0x100; local_3a0 = local_3a0 + 1) {
            iVar2 = FUN_00410e80((uint)*(byte *)(local_3a0 * 3 + 2 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3 + 2]);
            iVar3 = FUN_00410e80((uint)*(byte *)(local_3a0 * 3 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3]);
            local_10 = FUN_00410e80((uint)*(byte *)(local_3a0 * 3 + 1 + (int)local_3c) -
                                    (uint)(byte)local_18[local_39c * 3 + 1]);
            local_10 = iVar2 + iVar3 + local_10;
            if (local_10 < local_3c8) {
              local_3c8 = local_10;
              local_40 = local_3a0;
            }
          }
          for (local_3c4 = 0; local_3c4 < 0x20; local_3c4 = local_3c4 + 1) {
            if (local_3c0[local_3c4] == local_39c) {
              local_38[local_3c4] = (undefined1)local_40;
            }
          }
          local_7d0[local_39c] = (undefined1)local_40;
        }
        local_3c = local_7d0;
      }
      for (local_39c = 0; (int)local_39c < (int)local_264; local_39c = local_39c + 1) {
        asStack_c0[local_39c] =
             (int)asStack_262[local_39c * 2 + 1] * (int)asStack_262[local_39c * 2];
        pvVar4 = _malloc(asStack_c0[local_39c]);
        aiStack_140[local_39c] = (int)pvVar4;
        if (aiStack_140[local_39c] == 0) {
          for (local_3c4 = 0; local_3c4 < 0x20; local_3c4 = local_3c4 + 1) {
            if ((aiStack_140[local_3c4] != 0) && (asStack_c0[local_3c4] != 0)) {
              _free((void *)aiStack_140[local_3c4]);
            }
          }
          FreeResource(local_14);
          return 0;
        }
        FID_conflict__memcpy((void *)aiStack_140[local_39c],local_3cc,asStack_c0[local_39c]);
        local_3cc = (void *)((int)local_3cc + asStack_c0[local_39c]);
        local_8 = local_8 - asStack_c0[local_39c];
        if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
          pbVar7 = (byte *)aiStack_140[local_39c];
          local_c = pbVar7;
          sVar5 = (short)asStack_c0[local_39c];
          local_394 = sVar5;
          for (; sVar5 != 0; sVar5 = sVar5 + -1) {
            *pbVar7 = local_3c[*pbVar7];
            pbVar7 = pbVar7 + 1;
          }
        }
        if ((int)local_8 < 0) {
          for (local_3c4 = 0; local_3c4 < 0x20; local_3c4 = local_3c4 + 1) {
            if ((aiStack_140[local_3c4] != 0) && (asStack_c0[local_3c4] != 0)) {
              _free((void *)aiStack_140[local_3c4]);
            }
          }
          FreeResource(local_14);
          return 0;
        }
      }
      FreeResource(local_14);
      psVar6 = &local_264;
      psVar8 = param_2;
      for (iVar2 = 0x89; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)psVar8 = *(undefined4 *)psVar6;
        psVar6 = psVar6 + 2;
        psVar8 = psVar8 + 2;
      }
      if ((DAT_00416db8 != 0) && (DAT_00416dbc != 0)) {
        for (local_39c = 0; (int)local_39c < (int)*param_2; local_39c = local_39c + 1) {
          *(undefined1 *)(local_39c + 0x102 + (int)param_2) = local_38[local_39c];
        }
      }
      local_398 = _malloc(0x10000);
      if (local_398 == (void *)0x0) {
        uVar1 = 0;
      }
      else {
        for (local_39c = 0; (int)local_39c < (int)*param_2; local_39c = local_39c + 1) {
          FUN_0040f06c(*(undefined1 **)(param_2 + local_39c * 2 + 0x92),(int)local_398,
                       (int)param_2[local_39c * 2 + 1],(int)param_2[local_39c * 2 + 2],
                       (int)param_2[local_39c * 2 + 2] * (int)param_2[local_39c * 2 + 1]);
          FID_conflict__memcpy
                    (*(void **)(param_2 + local_39c * 2 + 0x92),local_398,
                     *(size_t *)(param_2 + local_39c * 2 + 0xd2));
        }
        _free(local_398);
        uVar1 = 1;
      }
    }
    else {
      FreeResource(local_14);
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_004100fa @ 004100fa

void __cdecl FUN_004100fa(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x28) = param_1;
  *(undefined4 *)(param_2 + 0xc) = 0;
  return;
}


// ==== FUN_0041011d @ 0041011d

void __cdecl FUN_0041011d(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (DAT_00416da8 + -1 < param_4) {
    param_4 = DAT_00416da8 + -1;
  }
  if (DAT_00416dac + -1 < param_5) {
    param_5 = DAT_00416dac + -1;
  }
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_3;
  *(int *)(param_1 + 0x20) = param_4;
  *(int *)(param_1 + 0x24) = param_5;
  return;
}


// ==== FUN_004101a3 @ 004101a3

void __cdecl FUN_004101a3(int param_1,int param_2,int param_3,int param_4)

{
  int local_8;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (DAT_00416da8 + -1 < param_3) {
    param_3 = DAT_00416da8 + -1;
  }
  if (DAT_00416dac + -1 < param_4) {
    param_4 = DAT_00416dac + -1;
  }
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(int *)(&DAT_00427ff8 + local_8 * 0x2c) = param_1;
    *(int *)(&DAT_00427ffc + local_8 * 0x2c) = param_2;
    *(int *)(&DAT_00428000 + local_8 * 0x2c) = param_3;
    *(int *)(&DAT_00428004 + local_8 * 0x2c) = param_4;
  }
  return;
}


// ==== FUN_00410281 @ 00410281

void __cdecl
FUN_00410281(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  *param_3 = *(undefined4 *)(param_1 + 0x1c);
  *param_4 = *(undefined4 *)(param_1 + 0x20);
  *param_5 = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_004102bd @ 004102bd

void FUN_004102bd(void)

{
  if (DAT_00427fd8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00427fd8);
    DAT_00427fd8 = (HGDIOBJ)0x0;
  }
  if (DAT_00416da0 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00416da0);
  }
  DAT_00416da0 = (HGDIOBJ)0x0;
  return;
}


// ==== FUN_00410313 @ 00410313

void FUN_00410313(void)

{
  BITMAPINFO local_444;
  BYTE aBStack_3f4 [984];
  HDC local_1c;
  int local_10;
  undefined *local_c;
  void *local_8;
  
  local_c = &DAT_00427cd8;
  local_444.bmiHeader.biSize = 0x28;
  local_444.bmiHeader.biPlanes = 1;
  local_444.bmiHeader.biBitCount = 8;
  local_444.bmiHeader.biCompression = 0;
  local_444.bmiHeader.biSizeImage = 0;
  local_444.bmiHeader.biClrUsed = 0;
  local_444.bmiHeader.biClrImportant = 0;
  local_444.bmiHeader.biWidth = DAT_00416da8;
  local_444.bmiHeader.biHeight = DAT_00416dac;
  local_1c = GetDC((HWND)0x0);
  GetSystemPaletteEntries(local_1c,0,10,(LPPALETTEENTRY)&DAT_0041ef54);
  GetSystemPaletteEntries(local_1c,0xf6,10,(LPPALETTEENTRY)&DAT_0041f32c);
  ReleaseDC((HWND)0x0,local_1c);
  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
    local_444.bmiColors[local_10].rgbRed = (&DAT_0041ef54)[local_10 * 4];
    local_444.bmiColors[local_10].rgbGreen = (&DAT_0041ef55)[local_10 * 4];
    local_444.bmiColors[local_10].rgbBlue = (&DAT_0041ef56)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_0041ef57)[local_10 * 4] = 0;
    aBStack_3f4[local_10 * 4 + 0x3b2] = (&DAT_0041f32c)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b1] = (&DAT_0041f32d)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b0] = (&DAT_0041f32e)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b3] = '\0';
    (&DAT_0041f32f)[local_10 * 4] = 0;
  }
  for (local_10 = 10; local_10 < 0xf6; local_10 = local_10 + 1) {
    (&DAT_0041ef54)[local_10 * 4] = local_c[local_10 * 3] * '\x04';
    local_444.bmiColors[local_10].rgbRed = (&DAT_0041ef54)[local_10 * 4];
    (&DAT_0041ef55)[local_10 * 4] = local_c[local_10 * 3 + 1] * '\x04';
    local_444.bmiColors[local_10].rgbGreen = (&DAT_0041ef55)[local_10 * 4];
    (&DAT_0041ef56)[local_10 * 4] = local_c[local_10 * 3 + 2] * '\x04';
    local_444.bmiColors[local_10].rgbBlue = (&DAT_0041ef56)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_0041ef57)[local_10 * 4] = 4;
  }
  DAT_00416da0 = CreatePalette((LOGPALETTE *)&DAT_0041ef50);
  local_1c = GetDC((HWND)0x0);
  DAT_00427fd8 = CreateDIBSection(local_1c,&local_444,0,&local_8,(HANDLE)0x0,0);
  ReleaseDC((HWND)0x0,local_1c);
  DAT_00416de0 = local_8;
  DAT_0042dbe0 = local_8;
  return;
}


// ==== FUN_004105b5 @ 004105b5

void __cdecl FUN_004105b5(int *param_1)

{
  HDC hdc;
  HGDIOBJ h;
  int y;
  
  hdc = CreateCompatibleDC(DAT_0041ef00);
  h = SelectObject(hdc,DAT_00427fd8);
  y = (DAT_00416dac + -1) - param_1[3];
  BitBlt(DAT_0041ef00,*param_1,y,(param_1[2] - *param_1) + 1,(param_1[3] - param_1[1]) + 1,hdc,
         *param_1,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  return;
}


// ==== _memset @ 00410670

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


// ==== FUN_004106d0 @ 004106d0

uint * __cdecl FUN_004106d0(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_004107b8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_004107b8:
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


// ==== FUN_004106e0 @ 004106e0

uint * __cdecl FUN_004106e0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_004106fc;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0041072f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0041074b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_004106fc:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0041074b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0041074b;
    }
  }
LAB_0041072f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0041074b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_004107b8:
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
    if (bVar1 == 0) goto LAB_004107b8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== FID_conflict:_memcpy @ 004107c0

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
switchD_00410889_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_00410889_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_00410889_caseD_3:
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
        goto switchD_00410889_caseD_1;
      case 2:
        goto switchD_00410889_caseD_2;
      case 3:
        goto switchD_00410889_caseD_3;
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
switchD_004107f0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_004107f0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_004107f0_caseD_3:
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
      goto switchD_004107f0_caseD_1;
    case 2:
      goto switchD_004107f0_caseD_2;
    case 3:
      goto switchD_004107f0_caseD_3;
    }
  }
  return _Dst;
}


// ==== _strlen @ 00410910

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
    if (((uint)puVar2 & 3) == 0) goto LAB_00410930;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00410963:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00410930:
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
  goto LAB_00410963;
}


// ==== _strncmp @ 00410990

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


// ==== FID_conflict:__toupper_lk @ 004109d0

/* Library Function - Multiple Matches With Different Base Names
    __toupper_lk
    _toupper
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict___toupper_lk(int _C)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_00416e18 == (_locale_t)0x0) {
    if ((0x60 < _C) && (_C < 0x7b)) {
      _C = _C + -0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_0041703c < 2) {
      uVar1 = *(ushort *)(PTR_DAT_00416e30 + _C * 2) & 2;
    }
    else {
      uVar1 = __isctype(_C,2);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00416e30[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_00416e18,(LPCWSTR)0x200,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== _strcmp @ 00410ac0

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
      if (bVar4 != *_Str2) goto LAB_00410b04;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00410ad0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00410b04;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_00410b04;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00410ad0:
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
LAB_00410b04:
  return (uint)bVar5 * -2 + 1;
}


// ==== FUN_00410b50 @ 00410b50

void __cdecl FUN_00410b50(undefined4 param_1)

{
  DAT_00416df0 = param_1;
  return;
}


// ==== _rand @ 00410b60

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00416df0 = DAT_00416df0 * 0x343fd + 0x269ec3;
  return (DAT_00416df0 & 0x7fff0000) >> 0x10;
}


// ==== _free @ 00410b90

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
    HeapFree(DAT_0042de00,0,_Memory);
  }
  return;
}


// ==== _malloc @ 00410be0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00417870);
  return pvVar1;
}


// ==== __nh_malloc @ 00410c00

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


// ==== __heap_alloc @ 00410c50

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_0041786c) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0042de00,0,dwBytes);
  return pvVar2;
}


// ==== _qsort @ 00410c90

/* Library Function - Single Match
    _qsort
   
   Library: Visual Studio 1998 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *local_f8;
  int local_f4;
  undefined4 auStack_f0 [30];
  int aiStack_78 [30];
  
  if ((_NumOfElements < 2) || (_SizeOfElements == 0)) {
    return;
  }
  local_f4 = 0;
  local_f8 = (undefined1 *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_00410ccf:
  uVar1 = (uint)((int)local_f8 - (int)_Base) / _SizeOfElements + 1;
  if (8 < uVar1) {
    swap((undefined1 *)((int)_Base + (uVar1 >> 1) * _SizeOfElements),_Base,_SizeOfElements);
    puVar3 = local_f8 + _SizeOfElements;
    puVar4 = _Base;
LAB_00410d2c:
    puVar4 = puVar4 + _SizeOfElements;
    if (puVar4 <= local_f8) goto code_r0x00410d34;
    goto LAB_00410d44;
  }
  shortsort(_Base,local_f8,_SizeOfElements,_PtFuncCompare);
  goto LAB_00410cf6;
code_r0x00410d34:
  iVar2 = (*_PtFuncCompare)(puVar4,_Base);
  if (iVar2 < 1) goto LAB_00410d2c;
LAB_00410d44:
  do {
    puVar3 = puVar3 + -_SizeOfElements;
    if (puVar3 <= _Base) break;
    iVar2 = (*_PtFuncCompare)(puVar3,_Base);
  } while (-1 < iVar2);
  if (puVar4 <= puVar3) {
    swap(puVar4,puVar3,_SizeOfElements);
    goto LAB_00410d2c;
  }
  swap(_Base,puVar3,_SizeOfElements);
  if ((int)(puVar3 + (-1 - (int)_Base)) < (int)local_f8 - (int)puVar4) {
    if (puVar4 < local_f8) {
      auStack_f0[local_f4] = puVar4;
      aiStack_78[local_f4] = (int)local_f8;
      local_f4 = local_f4 + 1;
    }
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      local_f8 = puVar3 + -_SizeOfElements;
      goto LAB_00410ccf;
    }
  }
  else {
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      auStack_f0[local_f4] = _Base;
      aiStack_78[local_f4] = (int)puVar3 - _SizeOfElements;
      local_f4 = local_f4 + 1;
    }
    _Base = puVar4;
    if (puVar4 < local_f8) goto LAB_00410ccf;
  }
LAB_00410cf6:
  local_f4 = local_f4 + -1;
  if (local_f4 < 0) {
    return;
  }
  local_f8 = (undefined1 *)aiStack_78[local_f4];
  _Base = (undefined1 *)auStack_f0[local_f4];
  goto LAB_00410ccf;
}


// ==== shortsort @ 00410df0

/* Library Function - Single Match
    _shortsort
   
   Library: Visual Studio 1998 Release */

void __cdecl shortsort(undefined1 *param_1,undefined1 *param_2,int param_3,undefined *param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  for (; puVar2 = param_1, puVar1 = param_1, param_1 < param_2; param_2 = param_2 + -param_3) {
    while (puVar1 = puVar1 + param_3, puVar1 <= param_2) {
      iVar3 = (*(code *)param_4)(puVar1,puVar2);
      if (0 < iVar3) {
        puVar2 = puVar1;
      }
    }
    swap(puVar2,param_2,param_3);
  }
  return;
}


// ==== swap @ 00410e50

/* Library Function - Single Match
    _swap
   
   Library: Visual Studio 1998 Release */

void __cdecl swap(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_1 != param_2) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


// ==== FUN_00410e80 @ 00410e80

int __cdecl FUN_00410e80(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== entry @ 00410e90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  HMODULE pHVar5;
  WPARAM _Code;
  byte *pbVar6;
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
  puStack_c = &DAT_00413000;
  puStack_10 = &LAB_00412900;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0041788c = DVar2 >> 8 & 0xff;
  DAT_00417880 = DVar2 >> 0x10;
  _DAT_00417888 = DVar2 & 0xff;
  _DAT_00417884 = _DAT_00417888 * 0x100 + _DAT_0041788c;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0042de04 = (byte *)GetCommandLineA();
  DAT_00416df4 = ___crtGetEnvironmentStringsA();
  if ((DAT_00416df4 == (LPVOID)0x0) || (DAT_0042de04 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0042de04;
  pbVar6 = DAT_0042de04;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_0042de04 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_00410f95;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_00410f95:
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
  iVar3 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  _Code = FUN_0040c9df(pHVar5,iVar3,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 00411030

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00416e00 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_00416dfc)(0xff);
  return;
}


// ==== ___crtLCMapStringA @ 00411060

/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  int iVar1;
  LPCWSTR lpWideCharStr;
  int iVar2;
  LPCWSTR lpDestStr;
  
  if (DAT_00416e0c == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00416e0c = 1;
    }
    else {
      DAT_00416e0c = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_00416e0c == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_00416e0c != 1) {
    return DAT_00416e0c;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_00416e28;
  }
  iVar1 = MultiByteToWideChar(_CchDest,9,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = _malloc(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(_CchDest,1,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)0x0,0),
     iVar2 != 0)) {
    if (((uint)_LocaleName & 0x400) == 0) {
      lpDestStr = _malloc(iVar2 * 2);
      if ((lpDestStr == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,lpDestStr,
                               iVar2), iVar1 == 0)) goto LAB_004111db;
      if (_LpDestStr == (LPSTR)0x0) {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        iVar1 = iVar2;
      }
      else {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)_CchSrc,(int)_LpDestStr,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        iVar1 = iVar2;
      }
    }
    else {
      if (_LpDestStr == (LPSTR)0x0) goto LAB_00411272;
      if ((int)_LpDestStr < iVar2) goto LAB_004111db;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_00411272:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_004111db:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 00411290

/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Release */

size_t __cdecl _strncnt(char *_String,size_t _Cnt)

{
  size_t sVar1;
  char *pcVar2;
  
  pcVar2 = _String;
  sVar1 = _Cnt;
  while (sVar1 != 0) {
    sVar1 = sVar1 - 1;
    if (*pcVar2 == '\0') goto LAB_004112b5;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_004112b5:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== __isctype @ 004112c0

/* Library Function - Single Match
    __isctype
   
   Library: Visual Studio 1998 Release */

int __cdecl __isctype(int _C,int _Type)

{
  LPCSTR _LpSrcStr;
  BOOL BVar1;
  byte bVar2;
  BOOL unaff_EBX;
  undefined4 local_6;
  undefined1 local_2;
  
  if (_C + 1U < 0x101) {
    return (uint)*(ushort *)(PTR_DAT_00416e30 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00416e30[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_6._0_3_ = CONCAT12((char)_C,(undefined2)local_6);
    local_6 = (uint)(uint3)local_6;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_6._0_3_ = CONCAT12(bVar2,(undefined2)local_6);
    local_2 = 0;
    local_6 = CONCAT13((char)_C,(uint3)local_6);
  }
  BVar1 = ___crtGetStringTypeA
                    ((_locale_t)0x1,(int)&local_6 + 2,_LpSrcStr,(int)&local_6,(LPWORD)0x0,0,
                     unaff_EBX);
  if (BVar1 == 0) {
    return 0;
  }
  return local_6 & 0xffff & _Type;
}


// ==== __heap_init @ 00411360

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0042de00 = HeapCreate(1,0x1000,0);
  if (DAT_0042de00 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0042de00);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 004113a0

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
  
  if (DAT_00417860 == 0) {
    lpMem = &PTR_LOOP_00417050;
  }
  else {
    lpMem = HeapAlloc(DAT_0042de00,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00417050) {
        if (PTR_LOOP_00417050 == (undefined *)0x0) {
          PTR_LOOP_00417050 = (undefined *)&PTR_LOOP_00417050;
        }
        if (PTR_LOOP_00417054 == (undefined *)0x0) {
          PTR_LOOP_00417054 = (undefined *)&PTR_LOOP_00417050;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00417050;
        lpMem[1] = PTR_LOOP_00417054;
        PTR_LOOP_00417054 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00417050) {
    HeapFree(DAT_0042de00,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 00411510

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00417864 == param_1) {
    PTR_LOOP_00417864 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00417050) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0042de00,0,param_1);
    return;
  }
  DAT_00417860 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 00411570

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
  
  ppuVar4 = (undefined **)PTR_LOOP_00417054;
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
            DAT_00417868 = DAT_00417868 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_00417054) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 00411650

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00417050;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00417050) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 004116b0

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00417868 = DAT_00417868 + 1, DAT_00417868 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00411700

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
  
  piVar12 = (int *)PTR_LOOP_00417864;
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
              PTR_LOOP_00417864 = (undefined *)piVar12;
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
              PTR_LOOP_00417864 = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_00417864 != piVar12);
  ppuVar11 = &PTR_LOOP_00417050;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00417050) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00417864 = (undefined *)ppuVar11;
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
  PTR_LOOP_00417864 = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 00411980

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


// ==== __callnewh @ 00411b00

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0042dbe4 != (code *)0x0) {
    iVar1 = (*DAT_0042dbe4)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __cinit @ 00411b30

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_0042ddfc != (code *)0x0) {
    (*DAT_0042ddfc)();
  }
  __initterm((undefined4 *)&DAT_00414008,(undefined4 *)&DAT_0041400c);
  iVar1 = __initterm((undefined4 *)&DAT_00414000,(undefined4 *)&DAT_00414004);
  return iVar1;
}


// ==== _exit @ 00411b60

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 00411b80

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 00411ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_004178bc == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004178b8 = 1;
  DAT_004178b4 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0042ddf8 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0042ddf4 + -4), DAT_0042ddf8 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0042ddf8 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00414010,(undefined4 *)&DAT_00414014);
  }
  __initterm((undefined4 *)&DAT_00414018,(undefined4 *)&DAT_0041401c);
  if (param_3 == 0) {
    DAT_004178bc = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 00411c50

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


// ==== __global_unwind2 @ 00411c70

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x411c88,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 00411cb2

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
  puStack_18 = &LAB_00411c90;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00411d46();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_00411d46 @ 00411d46

void FUN_00411d46(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004178c8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004178c4 = in_EAX;
  DAT_004178cc = unaff_EBP;
  return;
}


// ==== __ismbblead @ 00411ef0

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 00411f10

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00417968 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00416e3a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 00411f50

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
  cVar1 = *DAT_00416df4;
  pcVar7 = DAT_00416df4;
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
  _DAT_0041789c = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00416df4;
  pcVar7 = DAT_00416df4;
  do {
    if (cVar1 == '\0') {
      _free(DAT_00416df4);
      DAT_00416df4 = (char *)0x0;
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


// ==== __setargv @ 00412040

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0042dbe8,0x104);
  _DAT_004178ac = &DAT_0042dbe8;
  pbVar2 = &DAT_0042dbe8;
  if (*DAT_0042de04 != 0) {
    pbVar2 = DAT_0042de04;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_00417894 = puVar1;
  _DAT_00417890 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 004120e0

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
      if (((*(byte *)((int)&DAT_00417968 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00417968 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00412150;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00412150:
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
          if ((*(byte *)((int)&DAT_00417968 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00412281;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00417968 + bVar1 + 1) & 4) != 0) {
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
LAB_00412281:
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


// ==== ___crtGetEnvironmentStringsA @ 004122c0

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
  if (DAT_00417960 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00417960 = 2;
    }
    else {
      DAT_00417960 = 1;
    }
  }
  if (DAT_00417960 != 1) {
    if (DAT_00417960 != 2) {
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


// ==== __setmbcp @ 00412450

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
  if (CodePage == DAT_00417a6c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00417a90;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00417968;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00417aa0 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00417a88)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00417968 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00417a6c = CodePage;
      _DAT_00417a70 = _CPtoLCID(CodePage);
      DAT_00417a78 = *(undefined4 *)(&DAT_00417a94 + local_18 * 0x30);
      DAT_00417a7c = *(undefined4 *)(&DAT_00417a98 + local_18 * 0x30);
      DAT_00417a80 = *(undefined4 *)(local_18 * 0x30 + 0x417a9c);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00417b80);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00417968;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00417a70 = 0;
      DAT_00417a6c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00417968 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00417968 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00417a6c = CodePage;
      _DAT_00417a70 = _CPtoLCID(CodePage);
    }
    DAT_00417a78 = 0;
    DAT_00417a7c = 0;
    DAT_00417a80 = 0;
    return 0;
  }
  if (DAT_00417a84 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00412630

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00417a84 = 1;
                    /* WARNING: Could not recover jumptable at 0x0041264d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00417a84 = 1;
                    /* WARNING: Could not recover jumptable at 0x00412662. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00416e28;
  }
  DAT_00417a84 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00412680

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


// ==== setSBCS @ 004126e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00417968;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00417a78 = 0;
  DAT_00417a6c = 0;
  _DAT_00417a70 = 0;
  DAT_00417a7c = 0;
  DAT_00417a80 = 0;
  return;
}


// ==== ___initmbctable @ 00412710

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00412720

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
  DAT_0042ddf0 = 0x20;
  DAT_0042dcf0 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0042dcf0 + 0x40);
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
    if ((int)DAT_0042ddf0 < (int)UVar7) {
      piVar4 = &DAT_0042dcf4;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0042ddf0;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0042ddf0 = DAT_0042ddf0 + 0x20;
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
      } while ((int)DAT_0042ddf0 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0042dcf0 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0042dcf0 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0042ddf0);
  return UVar7;
}


// ==== FUN_004129bd @ 004129bd

void FUN_004129bd(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 004129e0

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00416e00 == 1) || ((DAT_00416e00 == 0 && (DAT_00416e04 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00417c18 != (code *)0x0) {
      (*DAT_00417c18)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00412a20

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
  piVar2 = &DAT_00417b88;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00417c18);
  if ((&DAT_00417b88)[iVar4 * 2] == param_1) {
    if ((DAT_00416e00 == 1) || ((DAT_00416e00 == 0 && (DAT_00416e04 == 1)))) {
      if ((DAT_0042dcf0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0042dcf0 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x417b8c);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x417b8c);
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


// ==== _strncpy @ 00412c20

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
        goto joined_r0x00412c5e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00412c9b;
        goto LAB_00412d09;
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
joined_r0x00412d05:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00412d09:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00412c9b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00412d05;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00412d05;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00412d05;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00412c5e:
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
LAB_00412c9b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== ___crtGetStringTypeA @ 00412d20

/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 1998 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  BOOL BVar1;
  size_t _Size;
  int cchSrc;
  int iVar2;
  LPCWSTR lpWideCharStr;
  WORD local_2;
  
  iVar2 = DAT_00417c24;
  if (DAT_00417c24 == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = 2;
    }
  }
  DAT_00417c24 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_00416e28;
      }
      _Size = MultiByteToWideChar((UINT)_LpCharType,9,(LPCSTR)_DWInfoType,(int)_LpSrcStr,(LPWSTR)0x0
                                  ,0);
      iVar2 = BVar1;
      if (((_Size != 0) && (lpWideCharStr = _calloc(2,_Size), lpWideCharStr != (LPCWSTR)0x0)) &&
         (cchSrc = MultiByteToWideChar((UINT)_LpCharType,1,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                                       lpWideCharStr,_Size), cchSrc != 0)) {
        iVar2 = GetStringTypeW((DWORD)_Plocinfo,lpWideCharStr,cchSrc,(LPWORD)_CchSrc);
      }
      _free(lpWideCharStr);
    }
    return iVar2;
  }
  if (_Code_page == 0) {
    _Code_page = DAT_00416e18;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== ___crtMessageBoxA @ 00412e50

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00417c28 != (FARPROC)0x0) {
LAB_00412e9f:
    if (DAT_00417c2c != (FARPROC)0x0) {
      iVar1 = (*DAT_00417c2c)();
    }
    if ((iVar1 != 0) && (DAT_00417c30 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00417c30)(iVar1);
    }
    iVar1 = (*DAT_00417c28)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00417c28 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00417c28 != (FARPROC)0x0) {
      DAT_00417c2c = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00417c30 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00412e9f;
    }
  }
  return 0;
}


// ==== _calloc @ 00412ef0

/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _calloc(size_t _Count,size_t _Size)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint dwBytes;
  undefined4 *puVar4;
  
  dwBytes = _Size * _Count;
  if (dwBytes < 0xffffffe1) {
    if (dwBytes == 0) {
      dwBytes = 0x10;
    }
    else {
      dwBytes = dwBytes + 0xf & 0xfffffff0;
    }
  }
  do {
    puVar3 = (undefined4 *)0x0;
    if (dwBytes < 0xffffffe1) {
      if (DAT_0041786c < dwBytes) {
LAB_00412f4d:
        if (puVar3 != (undefined4 *)0x0) {
          return puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)___sbh_alloc_block(dwBytes >> 4);
        if (puVar3 != (undefined4 *)0x0) {
          puVar4 = puVar3;
          for (uVar2 = dwBytes >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          }
          for (uVar2 = dwBytes & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)puVar4 = 0;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
          }
          goto LAB_00412f4d;
        }
      }
      puVar3 = HeapAlloc(DAT_0042de00,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_00417870 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


