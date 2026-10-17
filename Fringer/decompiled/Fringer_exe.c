// ==== FUN_00401000 @ 00401000

HGLOBAL __cdecl FUN_00401000(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00427070 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),hResInfo);
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
    if (DAT_00427070 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),hResInfo);
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
    for (local_18 = 0; local_18 < DAT_00427070; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),hResInfo);
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
    if (DAT_00427070 <= local_18) {
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_0042ad70 + local_18 * 4),local_14);
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
    if (DAT_00427070 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),param_2,param_3);
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
    if (DAT_00427070 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042ad70 + local_c * 4),param_2);
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
    if (DAT_00427070 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_0042ad70 + local_c * 4),param_2,param_3,param_4,0);
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
    if (DAT_00427070 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_0042ad70 + local_c * 4),param_2);
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
    if (DAT_00427070 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_0042ad70 + local_c * 4),param_2);
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
    if (DAT_00427070 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_0042ad70 + local_c * 4),param_2);
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
    if (DAT_00427070 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_0042ad70 + local_c * 4),param_2,param_3,param_4);
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
    if (DAT_00427070 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_0042ad70 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040167a @ 0040167a

void FUN_0040167a(void)

{
  DAT_00427070 = 0;
  return;
}


// ==== FUN_00401694 @ 00401694

bool __cdecl FUN_00401694(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00427070 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_0042ad70 + DAT_00427070 * 4) = param_1;
    DAT_00427070 = DAT_00427070 + 1;
  }
  return bVar1;
}


// ==== FUN_004016d3 @ 004016d3

undefined4 __cdecl FUN_004016d3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00427070 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_0042ad70 + DAT_00427070 * 4) = pHVar2;
      DAT_00427070 = DAT_00427070 + 1;
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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_004272fc,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0041e6e0(param_2,local_410);
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
    FUN_0041e6f0(local_104,(uint *)&DAT_00427330);
  }
  FUN_0041e6f0(local_104,param_1);
  FUN_0041e6e0(param_1,local_104);
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
  FUN_00401733(s_Shared_Path_00427334,local_104);
  FUN_0041e6f0(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Shared_Path_00427340,local_104);
    FUN_0041e6f0(local_104,(uint *)&DAT_0042734c);
    FUN_0041e6f0(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0041e6e0(local_104,(uint *)s___shared__00427350);
      FUN_0041e6f0(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0041e6e0(local_104,(uint *)&DAT_0042735c);
        FUN_0041e6f0(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0041e6e0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0041e6e0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0041e6e0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0041e6e0(param_1,local_104);
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
  FUN_00401733(s_Help_Path_00427360,local_104);
  FUN_0041e6f0(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Help_Path_0042736c,local_104);
    FUN_0041e6f0(local_104,(uint *)&DAT_00427378);
    FUN_0041e6f0(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0041e6e0(local_104,(uint *)&DAT_0042737c);
      FUN_0041e6f0(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0041e6e0(local_104,(uint *)s___shared__00427380);
        FUN_0041e6f0(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0041e6e0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0041e6e0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0041e6e0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0041e6e0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00401c43 @ 00401c43

undefined4 __cdecl FUN_00401c43(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_004272f8 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_0042ae70 + DAT_004272f8 * 4) = param_1;
    DAT_004272f8 = DAT_004272f8 + 1;
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
  
  for (local_8 = 0; local_8 < DAT_004272f8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042ae70 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042ae70 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_0042ae70 + local_8 * 4) = 0;
  }
  DAT_004272f8 = 0;
  return;
}


// ==== FUN_00401d00 @ 00401d00

undefined4 FUN_00401d00(void)

{
  return 1;
}


// ==== FUN_00401d18 @ 00401d18

void FUN_00401d18(void)

{
  return;
}


// ==== FUN_00401d30 @ 00401d30

undefined * __cdecl FUN_00401d30(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0041e6e0((uint *)&DAT_0042c3c8,param_1);
  sVar1 = _strlen(&DAT_0042c3c8);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_0042c3c7)[local_8 + sVar1] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_0042c3c8)[param_3 + sVar1] = 0;
  return &DAT_0042c3c8;
}


// ==== FUN_00401df9 @ 00401df9

void __cdecl FUN_00401df9(int param_1)

{
  if (param_1 == 0) {
    DAT_0042bf70 = GetDC(DAT_0042bfb8);
  }
  else {
    DAT_0042bf70 = BeginPaint(DAT_0042bfb8,(LPPAINTSTRUCT)&DAT_0042bf78);
  }
  return;
}


// ==== FUN_00401e3f @ 00401e3f

void __cdecl FUN_00401e3f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_0042bfb8,DAT_0042bf70);
  }
  else {
    EndPaint(DAT_0042bfb8,(PAINTSTRUCT *)&DAT_0042bf78);
  }
  return;
}


// ==== FUN_00401e81 @ 00401e81

bool __cdecl FUN_00401e81(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_00401eca @ 00401eca

bool __cdecl FUN_00401eca(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_00401f60 @ 00401f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_00401f60(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_00401078(DAT_004318c0,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_00427390 = 0;
        _DAT_0042bfc0 = 0x300;
        _DAT_0042bfc2 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_0042bfc4)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_0042bfc5)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_0042bfc6)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_0042bfc7)[local_28 * 4] = 0;
        }
        if (DAT_0042738c == (HPALETTE)0x0) {
          DAT_0042738c = CreatePalette((LOGPALETTE *)&DAT_0042bfc0);
        }
      }
      hPal = SelectPalette(param_1,DAT_00431ae4,0);
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


// ==== FUN_0040217c @ 0040217c

HGLOBAL __cdecl FUN_0040217c(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_00401078(DAT_004318c0,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_00402226 @ 00402226

LPVOID __cdecl FUN_00402226(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_004318c0,param_1,s_SPRITE_00427394,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_00402278 @ 00402278

LPVOID __cdecl FUN_00402278(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_004318c0,param_1,s_SPRFONT_0042739c,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_004022ca @ 004022ca

undefined2 * __cdecl FUN_004022ca(LPCSTR param_1)

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
  
  hResData = FUN_00401078(DAT_004318c0,param_1,(LPCSTR)0x2,&local_10);
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


// ==== FUN_004024c0 @ 004024c0

int __cdecl FUN_004024c0(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_004024df @ 004024df

void FUN_004024df(void)

{
  _memset(&DAT_0042f518,0,0x370);
  _memset(&DAT_0042c448,0,0x30d0);
  FID_conflict__memcpy(&DAT_0042c448,s_MD_PACK_004273f0,8);
  DAT_0042dd0c = 0;
  DAT_0042dd0d = 0;
  DAT_0042dd0e = 0;
  DAT_0042c452 = 0xc;
  _memset(&DAT_0042dce0,0,0x28);
  FID_conflict__memcpy(&DAT_0042dcd0,s_FRINGER_004274f8,0xb);
  return;
}


// ==== FUN_00402578 @ 00402578

undefined4 FUN_00402578(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_004024df();
  hFile = _lopen(s_MSPuzzle_dat_004273f8,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_0042c448,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_0042dcd0,s_FRINGER_004274f8,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_0042c448,s_MD_PACK_004273f0,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0042f540 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_0042dd44 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_0042f518 + local_10 * 0x2c,&DAT_0042dd1c + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_0042f540 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_0042f540 + local_10 * 0x2c) = 0;
        }
      }
      DAT_0042750c = (uint)(DAT_0042dd0c == '\0');
      DAT_00427508 = (uint)(DAT_0042dd0d == '\0');
      DAT_004273c4 = (uint)(DAT_0042dd0e == '\0');
      FID_conflict__memcpy(&DAT_004273c8,&DAT_0042dce0,0x28);
      DAT_004273b0 = (uint)DAT_0042dd08;
      if ((DAT_004273b0 == 0) || (9 < DAT_004273b0)) {
        DAT_004273b0 = 1;
      }
      DAT_004273b4 = (uint)DAT_0042dd09;
      if ((DAT_004273b4 == 0) || (1 < DAT_004273b4)) {
        DAT_004273b4 = 1;
      }
      DAT_004273b8 = (uint)(DAT_0042dd0a == '\0');
      DAT_004273bc = (uint)(DAT_0042dd0b == '\0');
      uVar1 = 1;
    }
    else {
      FUN_004024df();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00402801 @ 00402801

undefined4 __cdecl FUN_00402801(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_0042f540 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_0040289e @ 0040289e

int __cdecl FUN_0040289e(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_0042f540 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_0042f518 + (local_1c + 1) * 0x2c,&DAT_0042f518 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_0042f518 + local_1c * 0x2c,&DAT_004273c8,0x28);
    *(int *)(&DAT_0042f540 + local_1c * 0x2c) = param_1;
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


// ==== FUN_004029e2 @ 004029e2

void FUN_004029e2(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_0042dd1c,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_0042dd1c + local_c * 0x30,&DAT_0042f518 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_0042dd44 + local_c * 0x30) =
         *(undefined4 *)(&DAT_0042f540 + local_c * 0x2c);
  }
  DAT_0042dd0c = DAT_0042750c == 0;
  DAT_0042dd0d = DAT_00427508 == 0;
  DAT_0042dd0e = DAT_004273c4 == 0;
  DAT_0042dd08 = (undefined1)DAT_004273b0;
  DAT_0042dd09 = (undefined1)DAT_004273b4;
  DAT_0042dd0a = DAT_004273b8 == 0;
  DAT_0042dd0b = DAT_004273bc == 0;
  _memset(&DAT_0042dce0,0,0x28);
  FID_conflict__memcpy(&DAT_0042dce0,&DAT_004273c8,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_004273f8,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_004273f8,0);
  }
  _lwrite(local_8,&DAT_0042c448,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_00402bb0 @ 00402bb0

void FUN_00402bb0(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0042f88c == 1) || (DAT_0042f88c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004276a0,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004276a0,0x804,2,(DWORD_PTR)local_c);
    DAT_004276a0 = 0;
    Sleep(1);
    DAT_0042f88c = 0;
  }
  return;
}


// ==== FUN_00402c55 @ 00402c55

void FUN_00402c55(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0042750c != 0) && (DAT_0042f88c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004276a0,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0042f88c = 3;
  }
  return;
}


// ==== FUN_00402cc8 @ 00402cc8

void __cdecl FUN_00402cc8(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0042750c != 0) {
    if (DAT_0042f88c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_004276a0,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_004276a0,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_00402da5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0042f88c = 1;
    }
    else {
      FUN_00402da5(param_1);
    }
  }
  return;
}


// ==== FUN_00402da5 @ 00402da5

void __cdecl FUN_00402da5(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0042750c == 0) {
    FUN_00402bb0();
  }
  else {
    if (((DAT_0042f888 == param_1) && (0 < param_1)) && (DAT_0042f88c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_004276a0,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0042f88c != 4) {
      FUN_00402bb0();
    }
    if (DAT_0042750c != 0) {
      if (0 < param_1) {
        DAT_0042f888 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_0042f888;
      }
      if ((0 < param_1) && (param_1 < 5)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_0042f890 + param_1 * 0x100;
        local_20 = s_sequencer_004276a4;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_004276a0 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_004276a0;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_004276a0 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004276a0,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0042f88c = 1;
          }
          else {
            DAT_0042f88c = 4;
          }
        }
        else {
          DAT_0042f88c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_00402f85 @ 00402f85

void FUN_00402f85(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0042750c != 0) {
    if (DAT_0042f88c == 1) {
      if (DAT_004276a0 == 0) {
        DAT_0042f88c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_004276a0,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004276a0,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0042f88c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0042f88c = 4;
        }
      }
    }
    else if (DAT_0042f88c == 4) {
      FUN_00402da5(-1);
    }
  }
  return;
}


// ==== FUN_004030a3 @ 004030a3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004030a3(int param_1)

{
  DWORD DVar1;
  
  if (DAT_00427508 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00427510) {
      DAT_00427510 = DVar1;
    }
    if (DVar1 - _DAT_00427514 < DAT_00427510) {
      if (DAT_00427518 <= *(int *)(&DAT_0042fe9c + param_1 * 0x10)) {
        return;
      }
      Sleep(1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00427510 = GetTickCount();
    _DAT_00427514 = *(int *)(&DAT_0042fe98 + param_1 * 0x10);
    DAT_00427518 = *(int *)(&DAT_0042fe9c + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_0042fe90 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_004031bd @ 004031bd

void FUN_004031bd(void)

{
  int local_c;
  int local_8;
  
  FUN_00402bb0();
  FUN_004030a3(0);
  for (local_8 = 1; local_8 < 0xf; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042fe94 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042fe94 + local_8 * 0x10));
      *(undefined4 *)(&DAT_0042fe94 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_0042fe90 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 5; local_c = local_c + 1) {
    DeleteFileA(&DAT_0042f890 + local_c * 0x100);
  }
  return;
}


// ==== FUN_004032a5 @ 004032a5

void __cdecl FUN_004032a5(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00401000(DAT_004318c0,param_2,&DAT_004276b0);
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


// ==== FUN_004033d4 @ 004033d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004033d4(void)

{
  int local_8;
  
  _DAT_0042fe90 = 0;
  _DAT_0042fe94 = 0;
  FUN_004032a5((int *)&DAT_0042fea0,s_DelLineWAV_004276b8);
  _DAT_0042feac = 3;
  FUN_004032a5(&DAT_0042feb0,s_ENDBESTWAV_004276c4);
  _DAT_0042febc = 1;
  FUN_004032a5((int *)&DAT_0042fec0,s_ENDCURRWAV_004276d0);
  _DAT_0042fecc = 1;
  FUN_004032a5((int *)&DAT_0042fed0,s_GetStarWAV_004276dc);
  _DAT_0042fedc = 3;
  FUN_004032a5((int *)&DAT_0042fee0,s_LeftWAV_004276e8);
  _DAT_0042feec = 0xb;
  FUN_004032a5((int *)&DAT_0042fef0,s_RightWAV_004276f0);
  _DAT_0042fefc = 0xb;
  FUN_004032a5((int *)&DAT_0042ff00,s_MoveLineWAV_004276fc);
  _DAT_0042ff0c = 10;
  FUN_004032a5((int *)&DAT_0042ff10,s_NewBrushWAV_00427708);
  _DAT_0042ff1c = 4;
  FUN_004032a5((int *)&DAT_0042ff20,s_NewCandleWAV_00427714);
  _DAT_0042ff2c = 4;
  FUN_004032a5((int *)&DAT_0042ff30,s_NewLevelWAV_00427724);
  _DAT_0042ff3c = 3;
  FUN_004032a5((int *)&DAT_0042ff40,s_UseBrushWAV_00427730);
  _DAT_0042ff4c = 5;
  FUN_004032a5((int *)&DAT_0042ff50,s_LastLineWAV_0042773c);
  _DAT_0042ff5c = 2;
  FUN_004032a5((int *)&DAT_0042ff60,s_CandleBurnWAV_00427748);
  _DAT_0042ff6c = 3;
  FUN_004032a5((int *)&DAT_0042ff70,s_UseStarWAV_00427758);
  _DAT_0042ff7c = 5;
  for (local_8 = 1; local_8 < 5; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_0042f890 + local_8 * 0x100);
    FUN_0041e6f0((uint *)(&DAT_0042f890 + local_8 * 0x100),(uint *)(&DAT_00427520 + local_8 * 0x20))
    ;
    FUN_00401223(&DAT_004275e0 + local_8 * 0x20,&DAT_00427764,&DAT_0042f890 + local_8 * 0x100);
  }
  return;
}


// ==== FUN_00403650 @ 00403650

undefined4 __cdecl FUN_00403650(int param_1,int param_2)

{
  if (5 < param_1) {
    param_1 = 5;
  }
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (10 < param_2) {
    param_2 = 10;
  }
  if (param_2 < 1) {
    param_2 = 1;
  }
  return *(undefined4 *)(param_1 * 0x2c + 0x427aa0 + param_2 * 4);
}


// ==== FUN_004036bb @ 004036bb

void __cdecl FUN_004036bb(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00427ba8 = 2;
  }
  DAT_00430b04 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_004036fe @ 004036fe

void __cdecl FUN_004036fe(HWND param_1)

{
  if (DAT_00430b04 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00430b04);
  }
  return;
}


// ==== FUN_0040372f @ 0040372f

void __cdecl FUN_0040372f(uint *param_1)

{
  FUN_0041e6e0((uint *)&DAT_00427bb0,param_1);
  return;
}


// ==== FUN_00403750 @ 00403750

void __cdecl FUN_00403750(HWND param_1)

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


// ==== FUN_00403888 @ 00403888

INT_PTR __cdecl FUN_00403888(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040141d(DAT_004318c0,s_RESETSCORE_004280c4,param_1,FUN_00406079);
  return IVar1;
}


// ==== FUN_004038bd @ 004038bd

void __cdecl FUN_004038bd(int param_1)

{
  if (((0 < param_1) && (param_1 < 6)) && (*(int *)(&DAT_00430b98 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00430b98 + param_1 * 4) = 1;
    Sleep(100);
    DAT_00427a94 = 1;
    switch(param_1) {
    case 1:
      FUN_0040372f((uint *)s_QUICKHELPBMP_004280d0);
      FUN_0040141d(DAT_004318c0,s_QHBONUSDIALOG_004280e0,DAT_0042bfb8,FUN_00404bbb);
      break;
    case 2:
      FUN_0040372f((uint *)s_QUICKHELPBMP_004280f0);
      FUN_0040141d(DAT_004318c0,s_QHENDDIALOG_00428100,DAT_0042bfb8,FUN_00404bbb);
      break;
    case 3:
      FUN_0040372f((uint *)s_QHBRUSHBMP_0042810c);
      FUN_0040141d(DAT_004318c0,s_QHBRUSHDIALOG_00428118,DAT_0042bfb8,FUN_00404bbb);
      break;
    case 4:
      FUN_0040372f((uint *)s_QHCANDLEBMP_00428128);
      FUN_0040141d(DAT_004318c0,s_QHCANDLEDIALOG_00428134,DAT_0042bfb8,FUN_00404bbb);
      break;
    case 5:
      FUN_0040372f((uint *)s_QUICKHELPBMP_00428144);
      FUN_0040141d(DAT_004318c0,s_QHCONGRATULATE_00428154,DAT_0042bfb8,FUN_00404e31);
    }
    DAT_00427a94 = 0;
    FUN_0040f027();
    DAT_00427a74 = 1;
  }
  return;
}


// ==== FUN_00403a63 @ 00403a63

INT_PTR FUN_00403a63(void)

{
  INT_PTR IVar1;
  
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_QUICKHELPBMP_00428164);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_004318c0,s_EXITGAME_00428174,DAT_0042bfb8,FUN_00403ff2);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_00403adb @ 00403adb

INT_PTR FUN_00403adb(void)

{
  INT_PTR IVar1;
  
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_QUICKHELPBMP_00428180);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_004318c0,s_NEWGAME_00428190,DAT_0042bfb8,FUN_00403ff2);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_00403b53 @ 00403b53

void FUN_00403b53(void)

{
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_ABOUTBMP_00428198);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  FUN_0040141d(DAT_004318c0,s_ABOUT_004281a4,DAT_0042bfb8,FUN_00404193);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403bc2 @ 00403bc2

void __cdecl FUN_00403bc2(HWND param_1)

{
  FUN_0040141d(DAT_004318c0,s_CREDITS_004281ac,param_1,FUN_00404483);
  return;
}


// ==== FUN_00403bee @ 00403bee

void __cdecl FUN_00403bee(HWND param_1)

{
  FUN_0040141d(DAT_004318c0,s_SYSTEMINFODIALOG_004281b4,param_1,FUN_0040461d);
  return;
}


// ==== FUN_00403c1a @ 00403c1a

void FUN_00403c1a(void)

{
  DAT_00427a94 = 1;
  FUN_0040372f((uint *)s_QUICKHELPBMP_004281c8);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  FUN_0040141d(DAT_004318c0,s_QUICKHELPDIALOG_004281d8,DAT_0042bfb8,FUN_00405061);
  DAT_00427a94 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403c89 @ 00403c89

void FUN_00403c89(void)

{
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_CUPBMP_004281e8);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  FUN_0040141d(DAT_004318c0,s_YOURNAME_004281f0,DAT_0042bfb8,FUN_004052d7);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403cf8 @ 00403cf8

void FUN_00403cf8(void)

{
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_CUPBMP_004281fc);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  FUN_0040141d(DAT_004318c0,s_BALLSTOP_00428204,DAT_0042bfb8,FUN_00405620);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403d67 @ 00403d67

void FUN_00403d67(void)

{
  DAT_00427a90 = 1;
  FUN_0040372f((uint *)s_OPTIONSBMP_00428210);
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  FUN_0040141d(DAT_004318c0,s_OPTIONS_0042821c,DAT_0042bfb8,FUN_004059a8);
  DAT_00427a90 = 0;
  InvalidateRect(DAT_00431704,(RECT *)0x0,0);
  return;
}


// ==== FUN_00403dd6 @ 00403dd6

void __cdecl FUN_00403dd6(HWND param_1)

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
  local_8 = FUN_00401f60(pHVar1,&DAT_00427bb0);
  ReleaseDC((HWND)0x0,pHVar1);
  if (local_8 != (HBITMAP)0x0) {
    FUN_00401e81(local_8,&local_1c,&local_20);
    pHVar1 = GetDC(param_1);
    SelectPalette(pHVar1,DAT_00431ae4,0);
    RealizePalette(pHVar1);
    FUN_00401eca(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
                 ((local_18.bottom - local_18.top) - local_20) / 2);
    ReleaseDC(param_1,pHVar1);
    DeleteObject(local_8);
  }
  return;
}


// ==== FUN_00403ee4 @ 00403ee4

void __cdecl FUN_00403ee4(HWND param_1)

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
  ho = FUN_00401f60(pHVar1,s_QUICKHELPBMP_00428224);
  ReleaseDC((HWND)0x0,pHVar1);
  if (ho != (HBITMAP)0x0) {
    FUN_00401e81(ho,&local_18,&local_1c);
    pHVar1 = GetDC(param_1);
    SelectPalette(pHVar1,DAT_00431ae4,0);
    RealizePalette(pHVar1);
    FUN_00401eca(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
                 ((local_14.bottom - local_14.top) - local_1c) / 2);
    ReleaseDC(param_1,pHVar1);
    DeleteObject(ho);
  }
  return;
}


// ==== FUN_00403ff2 @ 00403ff2

UINT FUN_00403ff2(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403750(param_1);
      DAT_004318bc = param_1;
      DAT_00431764 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403dd6(DAT_00431764);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_004318bc == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004318bc);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_004318bc,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_004318bc,(RECT *)0x0,0);
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
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


// ==== FUN_00404193 @ 00404193

UINT FUN_00404193(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403750(param_1);
      DAT_004318f8 = param_1;
      DAT_004318c8 = GetDlgItem(param_1,100);
      FUN_004015b0(DAT_004318c0,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00401733(&DAT_00428234,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00401733(s_Product_ID_00428238,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403dd6(DAT_004318c8);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_004318f8) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_004318f8);
      SelectPalette(local_10c,DAT_00431ae4,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_004318f8,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_004318f8,(RECT *)0x0,0);
      InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
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
      FUN_00403bee(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00403bc2(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00404483 @ 00404483

UINT FUN_00404483(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403750(param_1);
      DAT_00430bb0 = param_1;
      DAT_00430b8c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403dd6(DAT_00430b8c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00430bb0) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00430bb0);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00430bb0,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00430bb0,(RECT *)0x0,0);
        InvalidateRect(DAT_004318f8,(RECT *)0x0,0);
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
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


// ==== FUN_0040461d @ 0040461d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040461d(HWND param_1,int param_2,uint param_3)

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
    FUN_00403750(param_1);
    _DAT_00430788 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_00428244,local_49c.dwMajorVersion,-1);
    FUN_0041e6e0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428248);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_0042824c,local_49c.dwMinorVersion,-1);
    FUN_0041e6f0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428250);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_00428254,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0041e6f0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428258);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0041e6f0((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_0042825c,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0041e6e0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428260);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0041e6e0((uint *)local_404,(uint *)&DAT_00428264);
    FUN_0041e6f0((uint *)local_404,(uint *)&local_4b4);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428268);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_0042826c,local_4a0,-1);
    FUN_0041e6f0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_00428270);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_00428294,s_display_drv_00428288,s_Unknown_00428280,local_404,0x80,
               s_system_ini_00428274);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282a8,local_4a0,-1);
    FUN_0041e6e0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_004282ac);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282b0,local_4a0,-1);
    FUN_0041e6f0((uint *)local_404,puVar1);
    FUN_0041e6f0((uint *)local_404,(uint *)&DAT_004282b4);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282b8,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0041e6f0((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282bc,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0041e6f0((uint *)local_404,puVar1);
      FUN_0041e6f0((uint *)local_404,(uint *)&DAT_004282c0);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282c8,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0041e6f0((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_00401d30((uint *)&DAT_004282c4,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0041e6f0((uint *)local_404,puVar1);
      }
      FUN_0041e6f0((uint *)local_404,(uint *)&DAT_004282cc);
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


// ==== FUN_00404bbb @ 00404bbb

UINT FUN_00404bbb(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00403dd6(DAT_00430b88);
      }
      return 0;
    }
    FUN_00403750(param_1);
    DAT_004302ac = param_1;
    DAT_00430b88 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_004273bc == 0);
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
      DAT_004273bc = (uint)(LVar2 == 0);
      FUN_0040ef41();
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
      DAT_004273bc = (uint)(LVar2 == 0);
      FUN_0040ef41();
      EndDialog(param_1,0);
      PostMessageA(DAT_0042bfb8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_004302ac == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_004302ac);
  SelectPalette(hdc,DAT_00431ae4,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_004302ac,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_004302ac,(RECT *)0x0,0);
    InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00404e31 @ 00404e31

UINT FUN_00404e31(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00403750(param_1);
      DAT_004318c4 = param_1;
      DAT_00430b0c = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_004273bc == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403dd6(DAT_00430b0c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_004318c4) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004318c4);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_004318c4,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_004318c4,(RECT *)0x0,0);
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
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
        DAT_004273bc = (uint)(LVar2 == 0);
        FUN_0040ef41();
        EndDialog(param_1,0);
        PostMessageA(DAT_0042bfb8,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00405061 @ 00405061

UINT FUN_00405061(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00403dd6(DAT_0043077c);
      }
      return 0;
    }
    FUN_00403750(param_1);
    DAT_00430b90 = param_1;
    DAT_0043077c = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_004273b8 == 0);
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
      DAT_004273b8 = (uint)(LVar2 == 0);
      FUN_0040ef41();
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
      DAT_004273b8 = (uint)(LVar2 == 0);
      FUN_0040ef41();
      EndDialog(param_1,0);
      PostMessageA(DAT_0042bfb8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00430b90 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00430b90);
  SelectPalette(hdc,DAT_00431ae4,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00430b90,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00430b90,(RECT *)0x0,0);
    InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_004052d7 @ 004052d7

UINT FUN_004052d7(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_00403dd6(DAT_00430afc);
      }
      return 0;
    }
    FUN_00403750(param_1);
    DAT_00430bb8 = param_1;
    DAT_00430afc = GetDlgItem(param_1,100);
    if (DAT_00427ba8 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_004273c8);
    _Size = 0x10;
    _Src = FUN_00401d30((uint *)&DAT_004282d0,DAT_004273a8,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_00430bb8 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_00430bb8);
    SelectPalette(hdc,DAT_00431ae4,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_00430bb8,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_00430bb8,(RECT *)0x0,0);
      InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_004273c8,DAT_00427ba8 * 0x11);
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


// ==== FUN_00405620 @ 00405620

UINT FUN_00405620(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00403750(param_1);
      DAT_00430b80 = param_1;
      DAT_00430bb4 = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00427cb0) && (DAT_00427cb0 < 10)) {
        SetDlgItemTextA(param_1,DAT_00427cb0 + 0x33,&DAT_004282d4);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_00401d30((uint *)&DAT_004282d8,*(int *)(&DAT_0042f540 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0042f518 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403dd6(DAT_00430bb4);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00430b80 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00430b80);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00430b80,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00430b80,(RECT *)0x0,0);
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_00403888(DAT_00430b80), IVar5 == 1)) {
        if ((-1 < DAT_00427cb0) && (DAT_00427cb0 < 10)) {
          SetDlgItemTextA(param_1,DAT_00427cb0 + 0x33,&DAT_004282dc);
        }
        DAT_00427cb0 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_0042f540 + local_14 * 0x2c) = 0;
          _memset(&DAT_0042f518 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_00401d30((uint *)&DAT_004282e0,*(int *)(&DAT_0042f540 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0042f518 + local_14 * 0x2c);
        }
        FUN_0040ef41();
      }
    }
  }
  return 0;
}


// ==== FUN_004059a8 @ 004059a8

UINT FUN_004059a8(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_0042bfb8,s_FRINGER_HLP_00427770,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_00403dd6(DAT_00430b14);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00405b52:
      hdc = GetDC(DAT_00430a90);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_00430a90,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00430a90,(RECT *)0x0,0);
      InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00403750(param_1);
      DAT_00430a90 = param_1;
      DAT_00430b14 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00427508;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0042750c;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_004273c4;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x61,DAT_004273b4 + 0x5e);
      if (DAT_00427ba8 == 1) {
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
      WVar7 = 1;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      pHVar9 = (HIMC)0x0;
      pHVar1 = GetDlgItem(param_1,0xf);
      DAT_00431708 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_004273c8);
      pCVar2 = FUN_00401d30((uint *)&DAT_004282e4,DAT_004273b0,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x10009);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_00427508 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_0042750c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_004273c4 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004273b4 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004273b4 = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004273b4 = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004273b4 = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_004273c8,DAT_00427ba8 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 10; local_28 = local_28 + 1) {
          pcVar3 = FUN_00401d30((uint *)&DAT_004282f0,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
            DAT_004273b0 = local_28;
            break;
          }
        }
      case 2:
        DAT_00430a90 = (HWND)0x0;
        pHVar9 = DAT_00431708;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_004273b0;
          for (local_28 = 1; local_28 < 10; local_28 = local_28 + 1) {
            pcVar3 = FUN_00401d30((uint *)&DAT_004282e8,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
              local_1c = local_28;
              break;
            }
          }
          pCVar2 = FUN_00401d30((uint *)&DAT_004282ec,local_1c,-1);
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
        WinHelpA(DAT_0042bfb8,s_FRINGER_HLP_00427770,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_00430a90 == param_3) {
      return 0;
    }
    goto LAB_00405b52;
  }
  return 0;
}


// ==== FUN_00406079 @ 00406079

UINT FUN_00406079(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403750(param_1);
      DAT_00431abc = param_1;
      DAT_00430b10 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403ee4(DAT_00430b10);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00431abc == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00431abc);
      SelectPalette(hdc,DAT_00431ae4,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00431abc,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00430b80,(RECT *)0x0,0);
        InvalidateRect(DAT_00431abc,(RECT *)0x0,0);
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
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


// ==== FUN_0040622a @ 0040622a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040622a(void)

{
  _DAT_00430af8 = GetTickCount();
  return;
}


// ==== FUN_00406245 @ 00406245

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00406245(int param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  iVar1 = ((iVar1 + _DAT_00430af8) % 0x7fff) * param_1;
  return (int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf;
}


// ==== FUN_00406281 @ 00406281

void FUN_00406281(void)

{
  return;
}


// ==== FUN_004062b4 @ 004062b4

void FUN_004062b4(void)

{
  return;
}


// ==== FID_conflict:_$E31 @ 004062d3

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_004062ed();
  FUN_00406307();
  return;
}


// ==== FUN_004062ed @ 004062ed

void FUN_004062ed(void)

{
  FUN_00409af5(&DAT_004318d0);
  return;
}


// ==== FUN_00406307 @ 00406307

void FUN_00406307(void)

{
  _atexit(FUN_00406324);
  return;
}


// ==== FUN_00406324 @ 00406324

void FUN_00406324(void)

{
  FUN_00409b6f();
  return;
}


// ==== FUN_0040633e @ 0040633e

void FUN_0040633e(void)

{
  FUN_00406358();
  FUN_004063e1();
  return;
}


// ==== FUN_00406358 @ 00406358

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406358(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430a80 = 0;
  _DAT_00430a84 = 0;
  _DAT_00430a88 = 0;
  _DAT_00430a8c = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004063e1 @ 004063e1

void FUN_004063e1(void)

{
  _atexit(FUN_004063fe);
  return;
}


// ==== FUN_004063fe @ 004063fe

void FUN_004063fe(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00406447;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00406436();
  thunk_FUN_00406451();
  return;
}


// ==== FUN_00406436 @ 00406436

void FUN_00406436(void)

{
  FUN_00411e30((int *)&DAT_00430a80);
  return;
}


// ==== FUN_00406451 @ 00406451

void FUN_00406451(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040645f @ 0040645f

void FUN_0040645f(void)

{
  FUN_00406479();
  FUN_004066a3();
  return;
}


// ==== FUN_00406479 @ 00406479

/* WARNING: Removing unreachable block (ram,0x00406549) */
/* WARNING: Removing unreachable block (ram,0x0040659c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406479(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430b6c = 0;
  _DAT_00430b4c = 1;
  _DAT_00430b48 = 0;
  _DAT_00430b44 = 0;
  DAT_00430b30 = 0;
  DAT_00430b2c = 0;
  DAT_00430b28 = 0;
  DAT_00430b68 = 0;
  _DAT_00430b70 = 0;
  _DAT_00430b74 = 0;
  _DAT_00430b50 = 0;
  _DAT_00430b54 = 0;
  DAT_00430b64 = 0;
  DAT_00430b60 = 0;
  DAT_00430b5c = 0;
  _DAT_00430b58 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004066a3 @ 004066a3

void FUN_004066a3(void)

{
  _atexit(FUN_004066c0);
  return;
}


// ==== FUN_004066c0 @ 004066c0

void FUN_004066c0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00406709;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_004066f8();
  thunk_FUN_00406713();
  return;
}


// ==== FUN_004066f8 @ 004066f8

void FUN_004066f8(void)

{
  FUN_00411f90(&DAT_00430b28);
  return;
}


// ==== FUN_00406713 @ 00406713

void FUN_00406713(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00406721 @ 00406721

void FUN_00406721(void)

{
  FUN_0040673b();
  FUN_004069b0();
  return;
}


// ==== FUN_0040673b @ 0040673b

/* WARNING: Removing unreachable block (ram,0x00406806) */
/* WARNING: Removing unreachable block (ram,0x00406859) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040673b(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  puStack_c = &LAB_00406998;
  _DAT_00431944 = 0;
  DAT_00431924 = 1;
  DAT_00431920 = 0;
  DAT_0043191c = 0;
  DAT_00431908 = 0;
  DAT_00431904 = 0;
  DAT_00431900 = 0;
  DAT_00431940 = 0;
  _DAT_00431948 = 0;
  _DAT_0043194c = 0;
  _DAT_00431928 = 0;
  _DAT_0043192c = 0;
  DAT_0043193c = 0;
  DAT_00431938 = 0;
  DAT_00431934 = 0;
  _DAT_00431930 = 0;
  local_8 = 3;
  _eh_vector_constructor_iterator_(&DAT_0043195c,0x10,0x14,CReObject::CReObject,FUN_00411e30);
  DAT_00431954 = 0x32;
  DAT_00431958 = 10;
  _DAT_00431950 = 3;
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_004069b0 @ 004069b0

void FUN_004069b0(void)

{
  _atexit(FUN_004069cd);
  return;
}


// ==== FUN_004069cd @ 004069cd

void FUN_004069cd(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00406a3a;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  FUN_00406a12();
  local_8 = 0xffffffff;
  FUN_00406a2a();
  thunk_FUN_00406a44();
  return;
}


// ==== FUN_00406a12 @ 00406a12

void FUN_00406a12(void)

{
  _eh_vector_destructor_iterator_(&DAT_0043195c,0x10,0x14,FUN_00411e30);
  return;
}


// ==== FUN_00406a2a @ 00406a2a

void FUN_00406a2a(void)

{
  FUN_00411f90(&DAT_00431900);
  return;
}


// ==== FUN_00406a44 @ 00406a44

void FUN_00406a44(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FID_conflict:_$E31 @ 00406a52

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_00406a6c();
  FUN_00406a86();
  return;
}


// ==== FUN_00406a6c @ 00406a6c

void FUN_00406a6c(void)

{
  FUN_0040e58e((undefined4 *)&DAT_004302b8);
  return;
}


// ==== FUN_00406a86 @ 00406a86

void FUN_00406a86(void)

{
  _atexit(FUN_00406aa3);
  return;
}


// ==== FUN_00406aa3 @ 00406aa3

void FUN_00406aa3(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00406b2a;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._1_3_ = 0;
  local_8._0_1_ = 1;
  FUN_00406af5();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00406b0d();
  local_8 = 0xffffffff;
  FUN_00406b19();
  thunk_FUN_00406b34();
  return;
}


// ==== FUN_00406af5 @ 00406af5

void FUN_00406af5(void)

{
  _eh_vector_destructor_iterator_(&DAT_004302ec,0x50,5,FUN_00411f90);
  return;
}


// ==== FUN_00406b0d @ 00406b0d

void FUN_00406b0d(void)

{
  FUN_00411e30((int *)&DAT_004302dc);
  return;
}


// ==== FUN_00406b19 @ 00406b19

void FUN_00406b19(void)

{
  FUN_00411e30((int *)&DAT_004302cc);
  return;
}


// ==== FUN_00406b34 @ 00406b34

void FUN_00406b34(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FID_conflict:_$E31 @ 00406b42

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_00406b5c();
  FUN_00406b76();
  return;
}


// ==== FUN_00406b5c @ 00406b5c

void FUN_00406b5c(void)

{
  FUN_0040d9b4(&DAT_00431768);
  return;
}


// ==== FUN_00406b76 @ 00406b76

void FUN_00406b76(void)

{
  _atexit(FUN_00406b93);
  return;
}


// ==== FUN_00406b93 @ 00406b93

void FUN_00406b93(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00406be8;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00406bcb();
  thunk_FUN_00406bf2();
  return;
}


// ==== FUN_00406bcb @ 00406bcb

void FUN_00406bcb(void)

{
  _eh_vector_destructor_iterator_(&DAT_0043176c,0x50,4,FUN_00411f90);
  return;
}


// ==== FUN_00406bf2 @ 00406bf2

void FUN_00406bf2(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00406c00 @ 00406c00

void FUN_00406c00(void)

{
  FUN_00406c1a();
  FUN_00406e0f();
  return;
}


// ==== FUN_00406c1a @ 00406c1a

/* WARNING: Removing unreachable block (ram,0x00406ce5) */
/* WARNING: Removing unreachable block (ram,0x00406d38) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406c1a(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430adc = 0;
  _DAT_00430abc = 1;
  _DAT_00430ab8 = 0;
  _DAT_00430ab4 = 0;
  DAT_00430aa0 = 0;
  DAT_00430a9c = 0;
  DAT_00430a98 = 0;
  DAT_00430ad8 = 0;
  _DAT_00430ae0 = 0;
  _DAT_00430ae4 = 0;
  _DAT_00430ac0 = 0;
  _DAT_00430ac4 = 0;
  DAT_00430ad4 = 0;
  DAT_00430ad0 = 0;
  DAT_00430acc = 0;
  _DAT_00430ac8 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00406e0f @ 00406e0f

void FUN_00406e0f(void)

{
  _atexit(FUN_00406e2c);
  return;
}


// ==== FUN_00406e2c @ 00406e2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406e2c(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00406f46;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430a98 = 0;
  DAT_00430aa0 = 0;
  _DAT_00430ab4 = 0;
  _DAT_00430ab8 = 0;
  _DAT_00430abc = 1;
  if (DAT_00430ad8 != (void *)0x0) {
    FUN_0041ee80(DAT_00430ad8);
  }
  DAT_00430ad8 = (void *)0x0;
  _DAT_00430ae0 = 0;
  _DAT_00430ae4 = 0;
  _DAT_00430ac0 = 0;
  _DAT_00430ac4 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00406f2a();
  local_8 = 0xffffffff;
  FUN_00406f36();
  thunk_FUN_00406f50();
  return;
}


// ==== FUN_00406f2a @ 00406f2a

void FUN_00406f2a(void)

{
  FUN_00411e30(&DAT_00430ad8);
  return;
}


// ==== FUN_00406f36 @ 00406f36

void FUN_00406f36(void)

{
  FUN_00411ee0(&DAT_00430a98);
  return;
}


// ==== FUN_00406f50 @ 00406f50

void FUN_00406f50(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00406f5e @ 00406f5e

void FUN_00406f5e(void)

{
  FUN_00406f78();
  FUN_0040716d();
  return;
}


// ==== FUN_00406f78 @ 00406f78

/* WARNING: Removing unreachable block (ram,0x00407043) */
/* WARNING: Removing unreachable block (ram,0x00407096) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406f78(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431754 = 0;
  _DAT_00431734 = 1;
  _DAT_00431730 = 0;
  _DAT_0043172c = 0;
  DAT_00431718 = 0;
  DAT_00431714 = 0;
  DAT_00431710 = 0;
  DAT_00431750 = 0;
  _DAT_00431758 = 0;
  _DAT_0043175c = 0;
  _DAT_00431738 = 0;
  _DAT_0043173c = 0;
  DAT_0043174c = 0;
  DAT_00431748 = 0;
  DAT_00431744 = 0;
  _DAT_00431740 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_0040716d @ 0040716d

void FUN_0040716d(void)

{
  _atexit(FUN_0040718a);
  return;
}


// ==== FUN_0040718a @ 0040718a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040718a(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_004072a4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00431710 = 0;
  DAT_00431718 = 0;
  _DAT_0043172c = 0;
  _DAT_00431730 = 0;
  _DAT_00431734 = 1;
  if (DAT_00431750 != (void *)0x0) {
    FUN_0041ee80(DAT_00431750);
  }
  DAT_00431750 = (void *)0x0;
  _DAT_00431758 = 0;
  _DAT_0043175c = 0;
  _DAT_00431738 = 0;
  _DAT_0043173c = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00407288();
  local_8 = 0xffffffff;
  FUN_00407294();
  thunk_FUN_004072ae();
  return;
}


// ==== FUN_00407288 @ 00407288

void FUN_00407288(void)

{
  FUN_00411e30(&DAT_00431750);
  return;
}


// ==== FUN_00407294 @ 00407294

void FUN_00407294(void)

{
  FUN_00411ee0(&DAT_00431710);
  return;
}


// ==== FUN_004072ae @ 004072ae

void FUN_004072ae(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004072bc @ 004072bc

void FUN_004072bc(void)

{
  FUN_004072d6();
  FUN_00407313();
  return;
}


// ==== FUN_004072d6 @ 004072d6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004072d6(void)

{
  DAT_00430290 = 0;
  _DAT_00430294 = 0;
  _DAT_00430298 = 0;
  _DAT_0043029c = 1;
  return;
}


// ==== FUN_00407313 @ 00407313

void FUN_00407313(void)

{
  _atexit(FUN_00407330);
  return;
}


// ==== FUN_00407330 @ 00407330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407330(void)

{
  if (DAT_00430290 != 0) {
    DAT_00430290 = 0;
  }
  _DAT_00430294 = 0;
  _DAT_00430298 = 0;
  _DAT_0043029c = 1;
  return;
}


// ==== FUN_0040737a @ 0040737a

void FUN_0040737a(void)

{
  FUN_00407394();
  FUN_0040743b();
  return;
}


// ==== FUN_00407394 @ 00407394

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407394(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_00431aac = 0;
  _DAT_00431ab0 = 0;
  _DAT_00431ab4 = 0;
  _DAT_00431ab8 = 0;
  DAT_00431aa0 = 0;
  DAT_00431aa4 = 0;
  DAT_00431aa8 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_0040743b @ 0040743b

void FUN_0040743b(void)

{
  _atexit(FUN_00407458);
  return;
}


// ==== FUN_00407458 @ 00407458

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407458(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040750c;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  DAT_00431aa0 = 0;
  if (DAT_00431aac != (void *)0x0) {
    FUN_0041ee80(DAT_00431aac);
  }
  DAT_00431aac = (void *)0x0;
  _DAT_00431ab4 = 0;
  _DAT_00431ab8 = 0;
  DAT_00431aa4 = 0;
  DAT_00431aa8 = 0;
  local_8 = 0xffffffff;
  FUN_004074fb();
  thunk_FUN_00407516();
  return;
}


// ==== FUN_004074fb @ 004074fb

void FUN_004074fb(void)

{
  FUN_00411e30(&DAT_00431aac);
  return;
}


// ==== FUN_00407516 @ 00407516

void FUN_00407516(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00407524 @ 00407524

void FUN_00407524(void)

{
  FUN_0040753e();
  FUN_004075e5();
  return;
}


// ==== FUN_0040753e @ 0040753e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040753e(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_0043076c = 0;
  _DAT_00430770 = 0;
  _DAT_00430774 = 0;
  _DAT_00430778 = 0;
  DAT_00430760 = 0;
  DAT_00430764 = 0;
  DAT_00430768 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004075e5 @ 004075e5

void FUN_004075e5(void)

{
  _atexit(FUN_00407602);
  return;
}


// ==== FUN_00407602 @ 00407602

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407602(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004076b6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  DAT_00430760 = 0;
  if (DAT_0043076c != (void *)0x0) {
    FUN_0041ee80(DAT_0043076c);
  }
  DAT_0043076c = (void *)0x0;
  _DAT_00430774 = 0;
  _DAT_00430778 = 0;
  DAT_00430764 = 0;
  DAT_00430768 = 0;
  local_8 = 0xffffffff;
  FUN_004076a5();
  thunk_FUN_004076c0();
  return;
}


// ==== FUN_004076a5 @ 004076a5

void FUN_004076a5(void)

{
  FUN_00411e30(&DAT_0043076c);
  return;
}


// ==== FUN_004076c0 @ 004076c0

void FUN_004076c0(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004076ce @ 004076ce

void FUN_004076ce(void)

{
  FUN_004076e3();
  return;
}


// ==== FUN_004076e3 @ 004076e3

void FUN_004076e3(void)

{
  undefined4 *local_c;
  int local_8;
  
  local_8 = 0xb4;
  local_c = (undefined4 *)&DAT_00430bc0;
  while( true ) {
    local_8 = local_8 + -1;
    if (local_8 < 0) break;
    FUN_00412100(local_c);
    local_c = local_c + 4;
  }
  return;
}


// ==== FUN_00407723 @ 00407723

int __cdecl FUN_00407723(int param_1)

{
  undefined4 local_8;
  
  if (DAT_00428078 + param_1 < (int)(uint)DAT_00428068) {
    local_8 = DAT_00428078 + param_1;
  }
  else {
    local_8 = (DAT_00428078 + param_1) - (uint)DAT_00428068;
  }
  return (uint)DAT_00428064 * local_8 * 4 + DAT_00430488;
}


// ==== FUN_00407787 @ 00407787

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00407787(int param_1,int param_2,int param_3)

{
  _DAT_00428080 =
       (uint)(((*(uint *)(param_2 + param_1 * 4) ^ *(uint *)(param_3 + param_1 * 4) & 0x78) & 0x78)
             != 0);
  switch(*(uint *)(param_2 + param_1 * 4) & 7) {
  case 0:
    break;
  case 1:
    *(uint *)(param_3 + 4 + param_1 * 4) =
         *(uint *)(param_3 + 4 + param_1 * 4) & 0x87 | *(uint *)(param_2 + param_1 * 4) & 0x78;
    break;
  case 2:
  case 3:
  case 6:
    *(uint *)(param_3 + param_1 * 4) =
         *(uint *)(param_3 + param_1 * 4) & 0x87 | *(uint *)(param_2 + param_1 * 4) & 0x78;
    break;
  case 4:
    *(uint *)(param_3 + -4 + param_1 * 4) =
         *(uint *)(param_3 + -4 + param_1 * 4) & 0x87 | *(uint *)(param_2 + param_1 * 4) & 0x78;
  }
  return;
}


// ==== FUN_004078a7 @ 004078a7

void __cdecl FUN_004078a7(int param_1,int param_2,uint *param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int local_2c;
  uint local_24;
  uint local_10;
  int local_c;
  int local_8;
  
  local_24 = *param_3;
  if (local_24 != 0) {
    local_8 = param_1 * 0x10 + DAT_00428070;
    iVar1 = param_2 * 0x18 + DAT_00428074;
    FUN_00413eac(&DAT_00431ac8,local_8 + -4,iVar1 + param_4,param_1 << 4,param_2 * 0x18 + param_4,
                 0x10,param_5,(short *)*DAT_004318fc,0);
    switch(local_24 & 7) {
    case 0:
      break;
    case 1:
    case 4:
      if ((local_24 & 0x80) == 0) {
        if (((byte)local_24 & 7) == 1) {
          local_10 = param_3[1];
          local_c = 0x18;
          local_2c = 0;
        }
        else {
          local_10 = param_3[-1];
          local_c = 0xc;
          local_2c = 0x24;
          local_8 = local_8 + -4;
        }
      }
      else {
        local_10 = local_24;
        if (((byte)local_24 & 7) == 1) {
          local_c = 0;
          local_2c = 0x18;
          local_24 = param_3[1];
        }
        else {
          local_c = 0x24;
          local_2c = 0xc;
          local_8 = local_8 + -4;
          local_24 = param_3[-1];
        }
      }
      FUN_00412d55(&DAT_00431ac8,local_8,iVar1 + param_4,local_2c,(local_10 & 0x78) * 3 + param_4,
                   0xc,param_5,DAT_00431760,0);
      FUN_00412d55(&DAT_00431ac8,local_8,iVar1 + param_4,local_c,(local_24 & 0x78) * 3 + param_4,0xc
                   ,param_5,DAT_00431760,0);
      break;
    case 2:
    case 3:
    case 6:
      uVar2 = (local_24 & 4) >> 2;
      FUN_00412d55(&DAT_00431ac8,local_8 + uVar2 * -4,iVar1 + param_4,
                   (local_24 & 1) * -0x18 + 0x48 + uVar2 * -0xc,(local_24 & 0x78) * 3 + param_4,
                   (uVar2 + (local_24 & 1)) * 4 + 8,param_5,DAT_00431760,0);
    }
  }
  return;
}


// ==== FUN_00407b66 @ 00407b66

void __cdecl FUN_00407b66(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_00428064; local_8 = local_8 + 1) {
    FUN_004078a7(local_8,param_1,(uint *)(local_8 * 4 + param_2),param_3,param_4);
  }
  return;
}


// ==== FUN_00407bbf @ 00407bbf

void FUN_00407bbf(void)

{
  int iVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < (int)(uint)DAT_00428068; local_c = local_c + 1) {
    iVar1 = FUN_00407723(local_c);
    FUN_00407b66(local_c,iVar1,0,0x18);
  }
  return;
}


// ==== FUN_00407c19 @ 00407c19

void __cdecl FUN_00407c19(HWND param_1,int param_2,int param_3,int param_4,int param_5)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ h;
  
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00431ae4,0);
  RealizePalette(hdc);
  hdc_00 = CreateCompatibleDC(hdc);
  h = SelectObject(hdc_00,DAT_00432078);
  BitBlt(hdc,param_2,param_3,param_4,param_5,hdc_00,param_2,param_3,0xcc0020);
  SelectObject(hdc_00,h);
  DeleteDC(hdc_00);
  GdiFlush();
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_00407ced @ 00407ced

void __cdecl FUN_00407ced(int param_1,int param_2,HWND param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = param_1 * 0x10 + DAT_00428070;
  iVar2 = param_2 * 0x18 + DAT_00428074;
  iVar3 = FUN_00407723(param_2);
  FUN_004078a7(param_1,param_2,(uint *)(param_1 * 4 + iVar3),0,0x18);
  FUN_004078a7(param_1 + 1,param_2,(uint *)(param_1 * 4 + iVar3 + 4),0,0x18);
  if (param_2 < (int)(DAT_00428068 - 1)) {
    local_10 = 0;
    local_1c = param_2;
    for (local_c = param_2; local_c < (int)(DAT_00428068 - 1); local_c = local_c + 1) {
      iVar3 = FUN_00407723(local_c);
      iVar4 = FUN_00407723(local_c + 1);
      FUN_00407787(param_1,iVar3,iVar4);
      FUN_00407787(param_1 + 1,iVar3,iVar4);
      local_1c = local_1c + 1;
      FUN_004078a7(param_1,local_1c,(uint *)(param_1 * 4 + iVar4),0,0x18);
      FUN_004078a7(param_1 + 1,local_1c,(uint *)(param_1 * 4 + iVar4 + 4),0,0x18);
      local_10 = local_10 + 1;
    }
    if (param_3 != (HWND)0x0) {
      FUN_00407c19(param_3,iVar1,iVar2,0x18,(local_10 * 3 + 3) * 8);
    }
  }
  else if (param_3 != (HWND)0x0) {
    FUN_00407c19(param_3,iVar1,iVar2,0x18,0x18);
  }
  return;
}


// ==== FUN_00407e92 @ 00407e92

undefined4 __cdecl FUN_00407e92(uint param_1,HWND param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar4 = param_1 & 0x7f;
  if (DAT_00428068 == DAT_00430b18) {
    local_14 = 0xffffffff;
  }
  else {
    local_14 = DAT_00430b18;
  }
  local_18 = (uint)DAT_00428068;
  while (uVar3 = local_18, local_18 = uVar3 - 1, (int)local_14 < (int)local_18) {
    iVar5 = FUN_00407723(local_18);
    uVar6 = *(uint *)(iVar5 + uVar4 * 4) & 7;
    uVar7 = *(uint *)(iVar5 + 4 + uVar4 * 4) & 7;
    if ((param_1 & 0x80) == 0) {
      local_10 = 0x80;
    }
    else {
      local_10 = 0;
    }
    if ((uVar6 != 2) || (uVar7 != 2)) goto LAB_00407f63;
    if (local_14 + 1 == local_18) goto LAB_00407f60;
  }
LAB_004080c2:
  FUN_00407ced(uVar4,local_18,param_2);
  return 1;
LAB_00407f60:
  local_18 = uVar3 - 2;
LAB_00407f63:
  if ((uVar6 == 3) && (uVar7 == 6)) {
    puVar1 = (uint *)(iVar5 + uVar4 * 4);
    *puVar1 = *puVar1 & 0x7a;
    puVar1 = (uint *)(iVar5 + 4 + uVar4 * 4);
    *puVar1 = *puVar1 & 0x7a;
  }
  else if ((uVar6 == 1) && ((uVar7 == 4 && ((*(uint *)(iVar5 + uVar4 * 4) & 0x80) == local_10)))) {
    *(uint *)(iVar5 + uVar4 * 4) = (*(uint *)(iVar5 + uVar4 * 4) & 0x78) + 2;
    *(uint *)(iVar5 + 4 + uVar4 * 4) = (*(uint *)(iVar5 + 4 + uVar4 * 4) & 0x78) + 2;
  }
  else {
    if (DAT_00428068 - 2 == local_18) {
      return 0;
    }
    local_18 = local_18 + 1;
    iVar5 = FUN_00407723(local_18);
    *(uint *)(iVar5 + uVar4 * 4) = (*(uint *)(iVar5 + uVar4 * 4) & 0x78) + 1;
    *(uint *)(iVar5 + 4 + uVar4 * 4) = (*(uint *)(iVar5 + 4 + uVar4 * 4) & 0x78) + 4;
    if (((*(uint *)(iVar5 + 4 + uVar4 * 4) ^ *(uint *)(iVar5 + uVar4 * 4) & 0x78) & 0x78) == 0) {
      piVar2 = (int *)(iVar5 + uVar4 * 4);
      *piVar2 = *piVar2 + 2;
      piVar2 = (int *)(iVar5 + 4 + uVar4 * 4);
      *piVar2 = *piVar2 + 2;
    }
    else if (local_10 == 0) {
      piVar2 = (int *)(iVar5 + uVar4 * 4);
      *piVar2 = *piVar2 + 0x80;
    }
    else {
      piVar2 = (int *)(iVar5 + 4 + uVar4 * 4);
      *piVar2 = *piVar2 + 0x80;
    }
  }
  goto LAB_004080c2;
}


// ==== FUN_004080e5 @ 004080e5

void __cdecl FUN_004080e5(int param_1,int param_2,HWND param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x10 + DAT_00428070;
  iVar2 = param_2 * 0x18 + DAT_00428074;
  iVar3 = FUN_00407723(param_2);
  FUN_004078a7(param_1,param_2,(uint *)(param_1 * 4 + iVar3),0,0x18);
  FUN_004078a7(param_1 + 1,param_2,(uint *)(param_1 * 4 + iVar3 + 4),0,0x18);
  if (param_3 != (HWND)0x0) {
    FUN_00407c19(param_3,iVar1,iVar2,0x18,0x18);
  }
  return;
}


// ==== FUN_0040818a @ 0040818a

undefined4 __cdecl FUN_0040818a(uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar2 = param_1 & 0x7f;
  if (DAT_00428068 == DAT_00430b18) {
    local_14 = 0xffffffff;
  }
  else {
    local_14 = DAT_00430b18;
  }
  local_18 = (uint)DAT_00428068;
  while (uVar1 = local_18, local_18 = uVar1 - 1, (int)local_14 < (int)local_18) {
    iVar3 = FUN_00407723(local_18);
    uVar4 = *(uint *)(iVar3 + uVar2 * 4) & 7;
    uVar5 = *(uint *)(iVar3 + 4 + uVar2 * 4) & 7;
    if ((param_1 & 0x80) == 0) {
      local_10 = 0x80;
    }
    else {
      local_10 = 0;
    }
    if ((uVar4 != 2) || (uVar5 != 2)) goto LAB_0040825b;
    if (local_14 + 1 == local_18) goto LAB_00408258;
  }
LAB_004082c9:
  *param_2 = uVar2;
  *param_3 = local_18;
  return 1;
LAB_00408258:
  local_18 = uVar1 - 2;
LAB_0040825b:
  if (((uVar4 != 3) || (uVar5 != 6)) &&
     ((uVar4 != 1 || ((uVar5 != 4 || ((*(uint *)(iVar3 + uVar2 * 4) & 0x80) != local_10)))))) {
    if (DAT_00428068 - 1 == local_18) {
      return 0;
    }
    local_18 = local_18 + 1;
  }
  goto LAB_004082c9;
}


// ==== FUN_004082e8 @ 004082e8

void __thiscall FUN_004082e8(void *this,HDC param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HDC pHVar4;
  HGDIOBJ pvVar5;
  int iVar6;
  uint uVar7;
  int x1;
  int iVar8;
  longlong lVar9;
  undefined4 local_10;
  
  pHVar4 = CreateCompatibleDC(DAT_00431ac8);
  pvVar5 = SelectObject(pHVar4,DAT_00432078);
  for (local_10 = 0xe; -1 < local_10; local_10 = local_10 + -1) {
    lVar9 = __ftol();
    BitBlt(param_1,*(int *)((int)this + 8) + DAT_00428070 + -4,local_10 + DAT_00428074 + param_2 + 4
           ,((uint)DAT_00428064 * 0x10 - *(int *)((int)this + 8)) - *(int *)((int)this + 0xc),1,
           pHVar4,*(int *)((int)this + 8) + DAT_00428070 + -4,
           (int)lVar9 + DAT_00428074 + param_2 + 5,0xcc0020);
  }
  SelectObject(pHVar4,pvVar5);
  DeleteDC(pHVar4);
  iVar6 = DAT_00428074 + param_2;
  iVar1 = *(int *)((int)this + 8);
  iVar8 = DAT_00428070 + -4;
  uVar7 = (uint)DAT_00428064;
  iVar2 = *(int *)((int)this + 8);
  iVar3 = *(int *)((int)this + 0xc);
  x1 = *(int *)((int)this + 8) + DAT_00428070;
  pHVar4 = CreateCompatibleDC(param_1);
  pvVar5 = SelectObject(pHVar4,DAT_00432078);
  BitBlt(param_1,iVar1 + iVar8,iVar6 + 0x13,(uVar7 * 0x10 - iVar2) - iVar3,5,pHVar4,x1,9,0xcc0020);
  SelectObject(pHVar4,pvVar5);
  DeleteDC(pHVar4);
  GdiFlush();
  return;
}


// ==== FUN_004084cb @ 004084cb

void FUN_004084cb(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_14;
  
  iVar2 = (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488;
  iVar3 = (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488;
  for (local_14 = 0; local_14 < (int)(uint)DAT_00428064; local_14 = local_14 + 1) {
    if (*(int *)(iVar2 + local_14 * 4) == 0) {
      *(undefined4 *)(iVar3 + local_14 * 4) = 0;
    }
    else {
      if ((local_14 < (int)(DAT_00428064 - 1)) && (*(int *)(iVar2 + 4 + local_14 * 4) != 0)) {
        uVar4 = _rand();
        *(uint *)(iVar3 + local_14 * 4) = (uVar4 & 1) + 1;
      }
      else {
        *(undefined4 *)(iVar3 + local_14 * 4) = 2;
      }
      if (*(int *)(iVar3 + local_14 * 4) != 2) {
        if (DAT_00428064 - 1 == local_14) {
          *(undefined4 *)(iVar3 + local_14 * 4) = 2;
        }
        else {
          uVar4 = _rand();
          iVar5 = (uVar4 & 1) * 0x80;
          piVar1 = (int *)(iVar3 + local_14 * 4);
          *piVar1 = *piVar1 + iVar5;
          *(int *)(iVar3 + 4 + local_14 * 4) = iVar5 + 0x84;
          local_14 = local_14 + 1;
        }
      }
    }
  }
  for (local_14 = 0; local_14 < (int)(uint)DAT_00428064; local_14 = local_14 + 1) {
    if (*(int *)(iVar2 + local_14 * 4) == 0) {
      *(undefined4 *)(iVar3 + local_14 * 4) = 0;
    }
    else if (*(int *)(iVar3 + local_14 * 4) == 2) {
      piVar1 = (int *)(iVar3 + local_14 * 4);
      *piVar1 = *piVar1 + (*(uint *)(iVar2 + local_14 * 4) & 0x78);
    }
    else {
      piVar1 = (int *)(iVar3 + local_14 * 4);
      *piVar1 = *piVar1 + (*(uint *)(iVar2 + 4 + local_14 * 4) & 0x78);
      piVar1 = (int *)(iVar3 + 4 + local_14 * 4);
      *piVar1 = *piVar1 + (*(uint *)(iVar2 + local_14 * 4) & 0x78);
      if (((*(uint *)(iVar2 + 4 + local_14 * 4) ^ *(uint *)(iVar2 + local_14 * 4) & 0x78) & 0x78) ==
          0) {
        *(uint *)(iVar3 + local_14 * 4) = (*(uint *)(iVar3 + local_14 * 4) & 0x7f) + 2;
        *(uint *)(iVar3 + 4 + local_14 * 4) = (*(uint *)(iVar3 + 4 + local_14 * 4) & 0x7f) + 2;
      }
      local_14 = local_14 + 1;
    }
  }
  for (local_14 = 0; local_14 < (int)(DAT_00428064 - 1); local_14 = local_14 + 1) {
    *(undefined4 *)(local_14 * 4 + (DAT_00428064 - 1) * (uint)DAT_00428068 * 4 + DAT_00430aec) = 0;
    if ((*(byte *)(iVar3 + local_14 * 4) & 1) != 0) {
      FUN_0040d07c(&DAT_00431900,local_14);
    }
  }
  return;
}


// ==== FUN_00408775 @ 00408775

bool __cdecl FUN_00408775(uint param_1)

{
  bool bVar1;
  int iVar2;
  int local_14;
  uint local_c;
  
  local_c = (uint)DAT_00428068;
  do {
    local_c = local_c - 1;
    if ((int)local_c <= (int)param_1) break;
    iVar2 = FUN_00407723(local_c);
    bVar1 = false;
    for (local_14 = 0; local_14 < (int)(uint)DAT_00428064; local_14 = local_14 + 1) {
      if ((*(int *)(iVar2 + local_14 * 4) != 0) &&
         (((byte)*(undefined4 *)(iVar2 + local_14 * 4) & 7) != 2)) {
        bVar1 = true;
        break;
      }
    }
  } while (!bVar1);
  return local_c == param_1;
}


// ==== FUN_00408846 @ 00408846

void __cdecl FUN_00408846(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0xc0 + param_2 * 0x10;
  iVar3 = FUN_00407723(param_1);
  uVar1 = *(uint *)(iVar3 + param_2 * 4);
  if ((uVar1 & 2) != 0) {
    *(int *)(&DAT_00430bc0 + iVar2) = param_2;
  }
  if ((uVar1 & 1) != 0) {
    *(int *)(&DAT_00430bc4 + iVar2) = param_2 + 1;
  }
  if ((uVar1 & 4) != 0) {
    *(int *)(&DAT_00430bc4 + iVar2) = param_2 + -1;
  }
  return;
}


// ==== FUN_004088c4 @ 004088c4

undefined4 __cdecl FUN_004088c4(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0xc0 + param_2 * 0x10;
  if ((param_3 == param_2) && (*(int *)(&DAT_00430bc0 + iVar1) == param_3)) {
    uVar2 = 1;
  }
  else if (*(int *)(&DAT_00430bc4 + iVar1) == param_3) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_0040892f @ 0040892f

void __cdecl FUN_0040892f(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  int local_10;
  uint *local_8;
  
  for (local_10 = 0; local_10 < (int)(uint)DAT_00428068; local_10 = local_10 + 1) {
    iVar1 = FUN_00407723(local_10);
    local_8 = (uint *)(iVar1 + param_1 * 4);
    iVar1 = local_10 * 0xc0 + param_1 * 0x10;
    piVar2 = (int *)(&DAT_00430bc0 + iVar1);
    uVar3 = _rand();
    uVar3 = uVar3 & 1;
    iVar4 = uVar3 * 0x80;
    if ((((*(int *)(&DAT_00430bc4 + iVar1) == *(int *)(&DAT_00430bcc + iVar1)) &&
         (*(int *)(&DAT_00430bc8 + iVar1) == *piVar2)) && (*(int *)(&DAT_00430bc4 + iVar1) != 0xff))
       && (*piVar2 != 0xff)) {
      if (param_3 != 0) {
        uVar5 = _rand();
        param_3 = uVar5 & 1;
      }
      if (param_3 == 0) {
        iVar4 = FUN_00407723(local_10);
        local_8 = (uint *)(iVar4 + param_1 * 4);
        if (((byte)*local_8 & 5) == 1) {
          local_8[1] = (local_8[1] & 0xf8) + 2;
        }
        else {
          local_8[-1] = (local_8[-1] & 0xf8) + 2;
        }
        *local_8 = (*local_8 & 0xf8) + 2;
        *local_8 = (*local_8 & 0x87) + param_2 * 8 + 0x80;
        local_14 = *(int *)(&DAT_00430bc8 + iVar1);
      }
      else {
        if ((*local_8 & 1) == 0) {
          local_8[-1] = (local_8[-1] & 0x7d) + iVar4;
        }
        else {
          local_8[1] = (local_8[1] & 0x7d) + iVar4;
        }
        *local_8 = (-(uint)(uVar3 == 0) & 0x80) + (*local_8 & 0x7d);
        *local_8 = (*local_8 & 0x87) + param_2 * 8;
        local_14 = *(int *)(&DAT_00430bcc + iVar1);
      }
    }
    else if ((*(int *)(&DAT_00430bc4 + iVar1) == *(int *)(&DAT_00430bcc + iVar1)) &&
            (*(int *)(&DAT_00430bc4 + iVar1) != 0xff)) {
      if ((*local_8 & 2) != 0) {
        if ((*local_8 & 1) == 0) {
          local_8[-1] = (local_8[-1] & 0x7d) + iVar4;
        }
        else {
          local_8[1] = (local_8[1] & 0x7d) + iVar4;
        }
        *local_8 = (-(uint)(uVar3 == 0) & 0x80) + (*local_8 & 0x7d);
      }
      local_14 = *(int *)(&DAT_00430bc4 + iVar1);
    }
    else {
      if ((*local_8 & 5) != 0) {
        if ((*local_8 & 1) == 0) {
          local_8[-1] = local_8[-1] & 0xfa;
        }
        else {
          local_8[1] = local_8[1] & 0xfa;
        }
        *local_8 = *local_8 & 0xfa;
      }
      local_14 = *piVar2;
    }
    *local_8 = (*local_8 & 0x87) + param_2 * 8;
    param_1 = local_14;
  }
  return;
}


// ==== FUN_00408be8 @ 00408be8

undefined4 __cdecl FUN_00408be8(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(uint)DAT_00428068 <= local_8) {
      return 1;
    }
    iVar1 = FUN_00407723(local_8);
    if ((*(uint *)(iVar1 + param_1 * 4) & 7) != 2) break;
    iVar1 = local_8 * 0xc0 + param_1 * 0x10;
    *(int *)(&DAT_00430bc0 + iVar1) = param_1;
    *(int *)(&DAT_00430bc8 + iVar1) = param_1;
    local_8 = local_8 + 1;
  }
  return 0;
}


// ==== FUN_00408c77 @ 00408c77

undefined4 __cdecl FUN_00408c77(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  uint local_8;
  
  FUN_00408846(0,param_1);
  for (local_8 = 0; (int)local_8 < (int)(DAT_00428068 - 1); local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(uint)DAT_00428064; local_10 = local_10 + 1) {
      iVar1 = local_8 * 0xc0 + local_10 * 0x10;
      if (*(int *)(&DAT_00430bc0 + iVar1) != 0xff) {
        FUN_00408846(local_8 + 1,*(int *)(&DAT_00430bc0 + iVar1));
      }
      if (*(int *)(&DAT_00430bc4 + iVar1) != 0xff) {
        FUN_00408846(local_8 + 1,*(int *)(&DAT_00430bc4 + iVar1));
      }
    }
  }
  for (local_10 = 0; local_10 < (int)(uint)DAT_00428064; local_10 = local_10 + 1) {
    iVar1 = (DAT_00428068 - 1) * 0xc0 + local_10 * 0x10;
    if (*(int *)(&DAT_00430bc0 + iVar1) != 0xff) {
      iVar2 = (uint)DAT_00428068 * 0xc0 + *(int *)(&DAT_00430bc0 + iVar1) * 0x10;
      *(int *)(&DAT_00430bc8 + iVar2) = local_10;
      *(int *)(&DAT_00430bc0 + iVar2) = local_10;
    }
    if (*(int *)(&DAT_00430bc4 + iVar1) != 0xff) {
      iVar2 = (uint)DAT_00428068 * 0xc0 + *(int *)(&DAT_00430bc4 + iVar1) * 0x10;
      *(int *)(&DAT_00430bcc + iVar2) = local_10;
      *(undefined4 *)(&DAT_00430bc0 + iVar2) = *(undefined4 *)(&DAT_00430bc4 + iVar1);
    }
  }
  for (local_10 = 0; local_10 < (int)(uint)DAT_00428064; local_10 = local_10 + 1) {
    if (local_10 != param_2) {
      iVar1 = (uint)DAT_00428068 * 0xc0 + local_10 * 0x10;
      *(undefined4 *)(&DAT_00430bcc + iVar1) = 0xff;
      *(undefined4 *)(&DAT_00430bc8 + iVar1) = *(undefined4 *)(&DAT_00430bcc + iVar1);
      *(undefined4 *)(&DAT_00430bc4 + iVar1) = *(undefined4 *)(&DAT_00430bc8 + iVar1);
      *(undefined4 *)(&DAT_00430bc0 + iVar1) = *(undefined4 *)(&DAT_00430bc4 + iVar1);
    }
  }
  iVar1 = (uint)DAT_00428068 * 0xc0 + param_2 * 0x10;
  if ((*(int *)(&DAT_00430bc8 + iVar1) == 0xff) && (*(int *)(&DAT_00430bcc + iVar1) == 0xff)) {
    uVar3 = 0;
  }
  else {
    for (local_8 = (uint)DAT_00428068; 0 < (int)local_8; local_8 = local_8 - 1) {
      for (local_10 = 0; local_10 < (int)(uint)DAT_00428064; local_10 = local_10 + 1) {
        iVar1 = local_8 * 0xc0 + local_10 * 0x10;
        if ((*(int *)(&DAT_00430bc8 + iVar1) != 0xff) || (*(int *)(&DAT_00430bcc + iVar1) != 0xff))
        {
          iVar1 = FUN_004088c4(local_8 - 1,local_10,local_10);
          if (iVar1 != 0) {
            iVar1 = (local_8 - 1) * 0xc0 + local_10 * 0x10;
            *(undefined4 *)(&DAT_00430bc8 + iVar1) = *(undefined4 *)(&DAT_00430bc0 + iVar1);
          }
          if ((0 < local_10) &&
             (iVar1 = FUN_004088c4(local_8 - 1,local_10 + -1,local_10), iVar1 != 0)) {
            iVar1 = (local_8 - 1) * 0xc0 + (local_10 + -1) * 0x10;
            *(undefined4 *)(&DAT_00430bcc + iVar1) = *(undefined4 *)(&DAT_00430bc4 + iVar1);
          }
          if ((local_10 < (int)(DAT_00428064 - 1)) &&
             (iVar1 = FUN_004088c4(local_8 - 1,local_10 + 1,local_10), iVar1 != 0)) {
            iVar1 = (local_8 - 1) * 0xc0 + (local_10 + 1) * 0x10;
            *(undefined4 *)(&DAT_00430bcc + iVar1) = *(undefined4 *)(&DAT_00430bc4 + iVar1);
          }
        }
      }
    }
    iVar1 = param_1 * 0x10;
    if ((*(int *)(&DAT_00430bc4 + iVar1) == *(int *)(&DAT_00430bcc + iVar1)) ||
       (*(int *)(&DAT_00430bc8 + iVar1) == *(int *)(&DAT_00430bc0 + iVar1))) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ==== FUN_0040906f @ 0040906f

int __cdecl FUN_0040906f(int param_1,uint param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while ((local_8 < (int)(uint)DAT_00428064 &&
         (iVar1 = FUN_00407723(param_1), (*(uint *)(iVar1 + local_8 * 4) & 0x78) >> 3 != param_2)))
  {
    local_8 = local_8 + 1;
  }
  return local_8;
}


// ==== FUN_004090cf @ 004090cf

void __cdecl FUN_004090cf(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_3 == param_1) {
    iVar3 = FUN_00407723(param_2);
    puVar1 = (uint *)(iVar3 + param_4 * 4 + param_3 * 4);
    iVar3 = FUN_0040d00f(param_2);
    iVar3 = iVar3 + param_4 * 4 + param_3 * 4;
    switch(*puVar1 & 7) {
    case 1:
    case 3:
      puVar1[1] = (puVar1[1] & 0x78) + 2;
      *(undefined4 *)(iVar3 + 4) = 0;
      break;
    case 2:
      break;
    case 4:
    case 6:
      puVar1[-1] = (puVar1[-1] & 0x78) + 2;
      *(undefined4 *)(iVar3 + -4) = 0;
    }
  }
  iVar3 = FUN_00407723(param_2);
  puVar2 = (undefined4 *)(iVar3 + param_3 * 4);
  puVar2[param_4] = *puVar2;
  iVar3 = FUN_0040d00f(param_2);
  puVar2 = (undefined4 *)(iVar3 + param_3 * 4);
  puVar2[param_4] = *puVar2;
  return;
}


// ==== FUN_004091ff @ 004091ff

void __cdecl FUN_004091ff(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_00428068; local_8 = local_8 + 1) {
    iVar1 = FUN_0040906f(local_8,param_1);
    local_10 = iVar1;
    if (param_2 == 0) {
      while (local_10 = local_10 + -1, -1 < local_10) {
        FUN_004090cf(iVar1 + -1,local_8,local_10,1);
      }
      if (iVar1 == 0) {
        FUN_004090cf(0,local_8,0,0);
      }
      puVar2 = (undefined4 *)FUN_00407723(local_8);
      *puVar2 = 0;
      puVar2 = (undefined4 *)FUN_0040d00f(local_8);
      *puVar2 = 0;
    }
    else {
      while (local_10 = local_10 + 1, local_10 <= (int)(DAT_00428064 - 1)) {
        FUN_004090cf(iVar1 + 1,local_8,local_10,-1);
      }
      if (DAT_00428064 - 1 == iVar1) {
        FUN_004090cf(iVar1,local_8,iVar1,0);
      }
      iVar1 = FUN_00407723(local_8);
      *(undefined4 *)(iVar1 + -4 + (uint)DAT_00428064 * 4) = 0;
      iVar1 = FUN_0040d00f(local_8);
      *(undefined4 *)(iVar1 + -8 + (uint)DAT_00428064 * 4) = 0;
    }
  }
  FUN_0040d2f3();
  return;
}


// ==== FUN_00409390 @ 00409390

bool FUN_00409390(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0;
      (local_c < (int)(uint)DAT_00428064 &&
      (iVar1 = FUN_00407723(0), *(int *)(iVar1 + local_c * 4) == 0)); local_c = local_c + 1) {
    local_8 = local_8 + 1;
  }
  for (; local_c < (int)(uint)DAT_00428064; local_c = local_c + 1) {
    iVar1 = FUN_00407723(0);
    if (*(int *)(iVar1 + local_c * 4) == 0) {
      local_8 = local_8 + -1;
    }
  }
  return local_8 == 0;
}


// ==== FUN_0040943f @ 0040943f

void __cdecl FUN_0040943f(int param_1,int param_2,HWND param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 0x10 + DAT_00428070;
  iVar2 = param_2 * 0x18 + DAT_00428074;
  FUN_00412d55(&DAT_00431ac8,iVar1,iVar2,-(uint)((DAT_00430b20 & 0x80) == 0) & 0x18,0,0x18,0x18,
               DAT_00430af4,0);
  if (param_3 != (HWND)0x0) {
    FUN_00407c19(param_3,iVar1,iVar2,0x18,0x18);
  }
  return;
}


// ==== FUN_004094d9 @ 004094d9

void __cdecl FUN_004094d9(HDC param_1,int param_2,int param_3)

{
  int x;
  int y;
  HDC hdc;
  HGDIOBJ h;
  
  x = param_2 * 0x10 + DAT_00428070;
  y = param_3 * 0x18 + DAT_00428074;
  FUN_00412d55(&DAT_00431ac8,x,y,-(uint)((DAT_00430b20 & 0x80) == 0) & 0x18,0,0x18,0x18,DAT_00430af4
               ,0);
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_00432078);
  BitBlt(param_1,x,y,0x18,0x18,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_004095cd @ 004095cd

void FUN_004095cd(void)

{
  int iVar1;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_10;
  
  for (local_10 = 0; local_10 < DAT_00428068; local_10 = local_10 + 1) {
    iVar1 = FUN_00407723((uint)local_10);
    FUN_00407b66((uint)local_10,iVar1,0,0x18);
    if (DAT_00428068 - 1 != (uint)local_10) {
      if (DAT_00428068 == 0x100) {
        local_18 = DAT_00430488;
      }
      else {
        local_18 = (uint)DAT_00428064 * 4 + iVar1;
      }
      for (local_14 = 0; local_14 < DAT_00428064; local_14 = local_14 + 1) {
        FUN_00407787((uint)local_14,iVar1,local_18);
      }
    }
  }
  return;
}


// ==== FUN_004096c8 @ 004096c8

void __cdecl FUN_004096c8(HWND param_1)

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
  SelectPalette(hdc,DAT_00431ae4,0);
  RealizePalette(hdc);
  if (DAT_00432054 != 0) {
    bVar7 = false;
    if ((DAT_0043206c == 0) && (DAT_00432070 == 0)) {
      for (local_10 = 0; local_10 < DAT_00432054; local_10 = local_10 + 1) {
        iVar1 = *(int *)(&DAT_00431f20 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_00431f1c + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
        iVar6 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_00432078);
        BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_00432054 = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_00432054; local_10 = local_10 + 1) {
        if ((DAT_0043206c <= *(int *)(&DAT_00431f14 + local_10 * 0x10)) &&
           (DAT_00432070 <= *(int *)(&DAT_00431f18 + local_10 * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_10 = 0; local_10 < DAT_00432054; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_00431f18 + local_10 * 0x10) - DAT_00432070;
          x = *(int *)(&DAT_00431f14 + local_10 * 0x10) - DAT_0043206c;
          iVar1 = *(int *)(&DAT_00431f20 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00431f1c + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_00432078);
          BitBlt(hdc,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_00432054; local_10 = local_10 + 1) {
          iVar1 = *(int *)(&DAT_00431f20 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00431f1c + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00431f18 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_00431f14 + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_00432078);
          BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_00432054 = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_00409af5 @ 00409af5

undefined4 * __fastcall FUN_00409af5(undefined4 *param_1)

{
  param_1[7] = 0x309;
  param_1[5] = 0;
  param_1[6] = 1;
  param_1[4] = 0;
  *param_1 = 0;
  param_1[1] = 0xc;
  param_1[2] = 1;
  DAT_00430488 = &DAT_00430490;
  DAT_00430aec = &DAT_00430790;
  FUN_0040a99a();
  return param_1;
}


// ==== FUN_00409b6f @ 00409b6f

void FUN_00409b6f(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_004318fc;
  if ((DAT_004318fc != (undefined4 *)0x0) && (DAT_004318fc != (undefined4 *)0x0)) {
    *DAT_004318fc = 0;
    FUN_0041ee80(puVar1);
  }
  return;
}


// ==== FUN_00409bec @ 00409bec

int FUN_00409bec(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < (int)(uint)DAT_00428064; local_8 = local_8 + 1) {
    if (*(int *)(local_8 * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// ==== FUN_00409c5c @ 00409c5c

int FUN_00409c5c(void)

{
  int local_4c [16];
  int local_c;
  uint local_8;
  
  _memset(local_4c,0,0x40);
  for (local_c = 0; local_c < (int)(uint)DAT_00428064; local_c = local_c + 1) {
    if (*(int *)(local_c * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) != 0) {
      local_8 = (*(uint *)(local_c * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) &
                0x78) >> 3;
      local_4c[local_8] = local_4c[local_8] + 1;
    }
  }
  local_8 = 0;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (0 < local_4c[local_c]) {
      local_8 = local_8 + 1;
    }
  }
  if ((int)local_8 < 1) {
    local_8 = 1;
  }
  return local_8;
}


// ==== FUN_00409d4c @ 00409d4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00409d4c(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  LPCSTR pCVar4;
  HGLOBAL pvVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  uint *puVar9;
  undefined4 *unaff_FS_OFFSET;
  int local_b4;
  int local_ac;
  int local_a4;
  int local_9c;
  int *local_94;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040a981;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  iVar7 = *(int *)(param_1 + 0x1c);
  if ((*(int *)(param_1 + 0x1c) != 0x309) && (DAT_004318e8 * 3 + -3 != DAT_004318e4)) {
    if (DAT_004318e4 < 0x1d) {
      iVar3 = (((*(int *)(param_1 + 0x14) + -2) % 3) * 0x32 + 100) *
              ((*(int *)(param_1 + 0x14) + -2) / 3 + 1);
    }
    else {
      iVar3 = (DAT_004318e4 * 5 + -0x8c) * 200 + 1000;
    }
    DAT_004318dc = DAT_004318dc + iVar3;
    DAT_00428088 = FUN_00409c5c();
  }
  *(int *)(param_1 + 0x1c) = ((*(int *)(param_1 + 0x14) + -1) / 3) % 9;
  *(int *)(param_1 + 0x20) = (*(int *)(param_1 + 0x14) + -1) % 3;
  if ((DAT_004318e4 + -1) / 0x1b < 1) {
    DAT_004302a4 = *(undefined4 *)
                    (&DAT_00427ce8 +
                    (*(int *)(&DAT_00427d40 + *(int *)(param_1 + 0x1c) * 0x2c) +
                    *(int *)(param_1 + 0x20)) * 8);
    *(undefined4 *)(param_1 + 0x24) =
         *(undefined4 *)
          (&DAT_00427cec +
          (*(int *)(&DAT_00427d40 + *(int *)(param_1 + 0x1c) * 0x2c) + *(int *)(param_1 + 0x20)) * 8
          );
  }
  else if (*(int *)(param_1 + 0x1c) == 0) {
    DAT_004302a4 = 3;
    *(undefined4 *)(param_1 + 0x24) = 1;
  }
  else {
    DAT_004302a4 = 4;
    *(undefined4 *)(param_1 + 0x24) = 1;
  }
  DAT_00428070 = *(int *)(&DAT_00427d18 + *(int *)(param_1 + 0x1c) * 0x2c);
  FUN_0041a0b9((void *)(DAT_0043047c * 0x50 + 0x43032c),0,0,-0x8000,-0x8000);
  FUN_0041a0b9((void *)(DAT_004318ac * 0x50 + 0x4317ac),0,0,-0x8000,-0x8000);
  if (*(int *)(param_1 + 0x20) == 0) {
    if (*(int *)(param_1 + 0x1c) != iVar7) {
      DAT_00427cb8 = DAT_00427cb8 + 1 & 3;
      FUN_00402da5(DAT_00427cb8 + 1);
      if (*(int *)(param_1 + 0x10) != 0) {
        GlobalFree(*(HGLOBAL *)(param_1 + 0x10));
      }
      pCVar4 = FUN_00401d30((uint *)&DAT_004282f4,*(int *)(param_1 + 0x1c),1);
      pvVar5 = FUN_0040217c(pCVar4);
      *(HGLOBAL *)(param_1 + 0x10) = pvVar5;
      if (*(int *)(param_1 + 0x10) == 0) {
        PostMessageA(DAT_00431704,0x10,0,0);
        uVar6 = 0;
        goto LAB_0040a98b;
      }
    }
  }
  else {
    FUN_004030a3(10);
  }
  FUN_00412d55(&DAT_00431ac8,0,0,0,0,600,400,*(int **)(param_1 + 0x10),-1);
  FUN_0041831a(&DAT_00430a98,*(int *)(&DAT_00427d38 + *(int *)(param_1 + 0x1c) * 0x2c),
               *(int *)(&DAT_00427d3c + *(int *)(param_1 + 0x1c) * 0x2c),1);
  DAT_00431aa4 = *(int *)(&DAT_00427d38 + *(int *)(param_1 + 0x1c) * 0x2c) + 0x28;
  DAT_00431aa8 = *(int *)(&DAT_00427d3c + *(int *)(param_1 + 0x1c) * 0x2c) + 0x26;
  if ((DAT_004318e4 + -1) / 0x1b < 1) {
    DAT_00430764 = *(int *)(&DAT_00427d38 + *(int *)(param_1 + 0x1c) * 0x2c) + 0x43;
    iVar7 = *(int *)(&DAT_00427d3c + *(int *)(param_1 + 0x1c) * 0x2c);
  }
  else {
    DAT_00430764 = *(int *)(&DAT_00427d38 + *(int *)(param_1 + 0x1c) * 0x2c) + 0x57;
    iVar7 = *(int *)(&DAT_00427d3c + *(int *)(param_1 + 0x1c) * 0x2c);
  }
  DAT_00430768 = iVar7 + 0x4f;
  FUN_0040e84e(0x4302b8);
  FUN_0040da42(0x431768);
  if (DAT_00431760 != (HGLOBAL)0x0) {
    GlobalFree(DAT_00431760);
  }
  pCVar4 = FUN_00401d30((uint *)s_THREAD_004282fc,*(int *)(param_1 + 0x1c),1);
  DAT_00431760 = FUN_0040217c(pCVar4);
  piVar2 = DAT_004318fc;
  if (DAT_00431760 == (HGLOBAL)0x0) {
    PostMessageA(DAT_00431704,0x10,0,0);
    uVar6 = 0;
    goto LAB_0040a98b;
  }
  if (DAT_004318fc != (int *)0x0) {
    if (DAT_004318fc != (int *)0x0) {
      *DAT_004318fc = 0;
      FUN_0041ee80(piVar2);
    }
    DAT_004318fc = (int *)0x0;
  }
  local_94 = operator_new(8);
  local_8 = 0;
  if (local_94 == (int *)0x0) {
    local_94 = (int *)0x0;
  }
  else {
    iVar7 = ((uint)DAT_00428068 * 3 + 3) * 8;
    iVar3 = (uint)DAT_00428064 * 0x10;
    local_94[1] = 0;
    pvVar8 = operator_new(iVar7 * iVar3 + 4);
    *local_94 = (int)pvVar8;
    if (*local_94 != 0) {
      *(short *)*local_94 = (short)iVar3;
      *(short *)(*local_94 + 2) = (short)iVar7;
      _memset((void *)(*local_94 + 4),0,iVar7 * iVar3);
    }
  }
  local_8 = 0xffffffff;
  DAT_004318fc = local_94;
  if (local_94 == (int *)0x0) {
    uVar6 = 0;
    goto LAB_0040a98b;
  }
  FUN_00417610((char)*(undefined4 *)(&DAT_00427d20 + *(int *)(param_1 + 0x1c) * 0x2c),0x32);
  FUN_00416cb2(&DAT_00431ac8,DAT_00428070 + -4,DAT_00428074,
               (uint)DAT_00428064 * 0x10 + DAT_00428070 + -5,
               ((uint)DAT_00428068 * 3 + 3) * 8 + DAT_00428074 + 8);
  if (*DAT_004318fc == 0) {
LAB_0040a5e1:
    local_9c = 0;
  }
  else {
    if (*DAT_004318fc == 0) {
      bVar1 = false;
    }
    else if (*(short *)*DAT_004318fc == 0x400) {
      if ((int)*(short *)(*DAT_004318fc + 6) * (int)*(short *)(*DAT_004318fc + 8) -
          *(int *)(*DAT_004318fc + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040a5e1;
    local_9c = (int)*(short *)*DAT_004318fc;
  }
  if (*DAT_004318fc == 0) {
LAB_0040a6b0:
    local_ac = 0;
  }
  else {
    if (*DAT_004318fc == 0) {
      bVar1 = false;
    }
    else if (*(short *)*DAT_004318fc == 0x400) {
      if ((int)*(short *)(*DAT_004318fc + 6) * (int)*(short *)(*DAT_004318fc + 8) -
          *(int *)(*DAT_004318fc + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040a6b0;
    local_ac = (int)*(short *)(*DAT_004318fc + 2);
  }
  FUN_00415556(&DAT_00431ac8,0,0,DAT_00428070 + -4,DAT_00428074,local_9c,local_ac,
               (short *)*DAT_004318fc,-1);
  if (*DAT_004318fc == 0) {
LAB_0040a7e4:
    local_a4 = 0;
  }
  else {
    if (*DAT_004318fc == 0) {
      bVar1 = false;
    }
    else if (*(short *)*DAT_004318fc == 0x400) {
      if ((int)*(short *)(*DAT_004318fc + 6) * (int)*(short *)(*DAT_004318fc + 8) -
          *(int *)(*DAT_004318fc + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040a7e4;
    local_a4 = (int)*(short *)*DAT_004318fc;
  }
  if (*DAT_004318fc == 0) {
LAB_0040a8b3:
    local_b4 = 0;
  }
  else {
    if (*DAT_004318fc == 0) {
      bVar1 = false;
    }
    else if (*(short *)*DAT_004318fc == 0x400) {
      if ((int)*(short *)(*DAT_004318fc + 6) * (int)*(short *)(*DAT_004318fc + 8) -
          *(int *)(*DAT_004318fc + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040a8b3;
    local_b4 = (int)*(short *)(*DAT_004318fc + 2);
  }
  FUN_00413eac(&DAT_00431ac8,DAT_00428070 + -4,DAT_00428074,0,0,local_a4,local_b4,
               (short *)*DAT_004318fc,0);
  puVar9 = (uint *)FUN_00401d30((uint *)s_ARROW_CURSOR_00428304,*(int *)(param_1 + 0x1c),1);
  FUN_0040cb08(&DAT_00430b20,puVar9);
  DAT_00430b20 = 5;
  _DAT_00430b24 = 0;
  FUN_0040c8f2(&DAT_00430b20);
  uVar6 = 1;
LAB_0040a98b:
  *unaff_FS_OFFSET = local_10;
  return uVar6;
}


// ==== FUN_0040a99a @ 0040a99a

void FUN_0040a99a(void)

{
  int iVar1;
  int local_c;
  undefined4 *local_8;
  
  local_8 = DAT_00430aec;
  for (local_c = 0; iVar1 = (DAT_00428068 + 1) * (DAT_00428064 - 1),
      iVar1 - local_c != 0 && local_c <= iVar1; local_c = local_c + 1) {
    *local_8 = 0;
    local_8 = local_8 + 1;
  }
  return;
}


// ==== FUN_0040a9f6 @ 0040a9f6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040a9f6(undefined4 *param_1)

{
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  char local_d8 [104];
  int local_70;
  int local_6c;
  char local_68 [100];
  
  DAT_004302bc = 0;
  _DAT_004302b8 = 0;
  DAT_004318b8 = 0;
  DAT_00430a70 = 0;
  _DAT_00430a74 = DAT_00428064 - 1;
  FUN_0040a99a();
  *param_1 = 2;
  DAT_00430a68 = 0;
  DAT_00430a6c = 200;
  if (DAT_004318e4 < 2) {
    DAT_00430a6c = 400;
  }
  else if (DAT_004318e4 < 4) {
    DAT_00430a6c = 300;
  }
  if (DAT_004318e4 < 0x1c) {
    if ((DAT_004318e4 + -1) / 0x1b < 1) {
      local_70 = ((DAT_004318e4 + -1) / 3) % 9;
    }
    else {
      local_70 = 8;
    }
    local_6c = param_1[8];
    _sprintf(local_d8,s__d__d_00428318,local_70 + 1,local_6c + 1);
    goto LAB_0040acf0;
  }
  if (DAT_00430a98 == (short *)0x0) {
LAB_0040ab53:
    local_e0 = 0;
  }
  else {
    if (*DAT_00430a98 == 0x400) {
      if ((int)DAT_00430a98[3] * (int)DAT_00430a98[4] - *(int *)(DAT_00430a98 + 1) == 0) {
        local_dc = 1;
      }
      else {
        local_dc = 0;
      }
    }
    else {
      local_dc = 0;
    }
    if (local_dc != 0) goto LAB_0040ab53;
    local_e0 = (int)DAT_00430a98[1];
  }
  if (DAT_00431710 == (short *)0x0) {
LAB_0040ac0e:
    local_e8 = 0;
  }
  else {
    if (*DAT_00431710 == 0x400) {
      if ((int)DAT_00431710[3] * (int)DAT_00431710[4] - *(int *)(DAT_00431710 + 1) == 0) {
        local_e4 = 1;
      }
      else {
        local_e4 = 0;
      }
    }
    else {
      local_e4 = 0;
    }
    if (local_e4 != 0) goto LAB_0040ac0e;
    local_e8 = (int)DAT_00431710[1];
  }
  FUN_0041831a(&DAT_00431710,*(int *)(&DAT_00427d38 + param_1[7] * 0x2c),
               (*(int *)(&DAT_00427d3c + param_1[7] * 0x2c) + local_e0) - local_e8,1);
  _sprintf(local_d8,&DAT_00428314,DAT_004318e4 + -0x1b);
LAB_0040acf0:
  _DAT_00431ab8 = 0;
  _sprintf(local_68,&DAT_00428320,param_1[3]);
  if (DAT_00431aa0 != (void *)0x0) {
    FUN_0041a0b9(&DAT_00431aac,0,0,-0x8000,-0x8000);
    FUN_0041ba43(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_68,&local_f8);
    FUN_00419da8(&DAT_00431aac,local_f8,local_f4,local_f0,local_ec,0);
    FUN_0041aeb1(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_68,0);
  }
  _DAT_00430778 = 0;
  if (DAT_00430760 != (void *)0x0) {
    FUN_0041a0b9(&DAT_0043076c,0,0,-0x8000,-0x8000);
    FUN_0041ba43(DAT_00430760,DAT_00430764,DAT_00430768,(int)local_d8,&local_108);
    FUN_00419da8(&DAT_0043076c,local_108,local_104,local_100,local_fc,0);
    FUN_0041aeb1(DAT_00430760,DAT_00430764,DAT_00430768,(int)local_d8,0);
  }
  return;
}


// ==== FUN_0040ae73 @ 0040ae73

undefined4 __cdecl FUN_0040ae73(undefined4 param_1,undefined4 param_2)

{
  DAT_00430b18 = param_1;
  return param_2;
}


// ==== FUN_0040ae8e @ 0040ae8e

void FUN_0040ae8e(void)

{
  int iVar1;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  uint *local_10;
  uint local_c;
  uint local_8;
  
  local_14 = DAT_00430b18;
  DAT_00430b18 = (uint)DAT_00428068;
  local_1c = 0;
  local_28 = 0;
  do {
    if ((int)(DAT_00428064 - 1) <= local_1c) {
      if (*(int *)(local_1c * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) != 0) {
        local_28 = local_28 + 1;
      }
      local_2c = 0;
      if (local_28 == 0) {
        FUN_0040ae73(local_14,1);
      }
      else if (local_28 < 4) {
        FUN_0040ae73(local_14,0);
      }
      else {
        if ((DAT_00430b20 & 0x80) == 0) {
          local_18 = 0x80;
        }
        else {
          local_18 = 0;
        }
        for (local_1c = 0; local_1c < (int)(DAT_00428064 - 1); local_1c = local_1c + 1) {
          if ((*(int *)(local_1c * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) != 0)
             && (iVar1 = FUN_0040818a(local_18 + local_1c,&local_8,&local_24), iVar1 != 0)) {
            iVar1 = FUN_00407723(local_24);
            local_10 = (uint *)(iVar1 + local_8 * 4);
            if (((byte)*local_10 & 7) != 2) {
              local_2c = local_2c + 1;
              local_c = local_24;
              local_20 = local_8;
            }
          }
        }
        if (local_28 == 4) {
          if (local_2c == 1) {
            if (((int)(uint)DAT_00428064 >> 1) - 1U == local_20) {
              FUN_0040ae73(local_14,0);
            }
            else {
              if ((int)(uint)DAT_00428064 >> 1 == local_20) {
                local_20 = ((int)(uint)DAT_00428064 >> 1) + -2;
              }
              else {
                local_20 = (int)(uint)DAT_00428064 >> 1;
              }
              iVar1 = FUN_00407723(local_c);
              local_10 = (uint *)(iVar1 + local_20 * 4);
              if (((local_10[1] ^ *local_10 & 0x78) & 0x78) == 0) {
                FUN_0040ae73(local_14,1);
              }
              else {
                FUN_0040ae73(local_14,0);
              }
            }
          }
          else {
            FUN_0040ae73(local_14,0);
          }
        }
        else {
          FUN_0040ae73(local_14,1);
        }
      }
      return;
    }
    if (*(int *)(local_1c * 4 + (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) != 0) {
      local_28 = local_28 + 1;
      iVar1 = FUN_0040818a((DAT_00430b20 & 0x80) + local_1c,&local_8,&local_24);
      if (iVar1 != 0) {
        iVar1 = FUN_00407723(local_24);
        local_10 = (uint *)(iVar1 + local_8 * 4);
        if (((byte)*local_10 & 7) != 2) {
          FUN_0040ae73(local_14,1);
          return;
        }
      }
    }
    local_1c = local_1c + 1;
  } while( true );
}


// ==== FUN_0040b1a0 @ 0040b1a0

void __thiscall FUN_0040b1a0(void *this,HWND param_1)

{
  bool bVar1;
  HDC hdc;
  int iVar2;
  uint uVar3;
  int x1;
  HDC pHVar4;
  HGDIOBJ pvVar5;
  int iVar6;
  undefined3 extraout_var;
  int iVar7;
  int iVar8;
  undefined3 extraout_var_00;
  int iVar9;
  int local_24;
  int local_14;
  int local_10;
  int local_8;
  
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00431ae4,0);
  RealizePalette(hdc);
  FUN_00419da8((void *)((int)this + 0x18),*(int *)((int)this + 8) + DAT_00428070 + -4,
               DAT_00428074 + DAT_00430484,
               ((uint)DAT_00428064 * 0x10 + DAT_00428070 + -5) - *(int *)((int)this + 0xc),
               DAT_00428074 + DAT_00430484 + 4,0);
  FUN_004082e8(this,hdc,DAT_00430484);
  local_14 = 0;
  local_8 = 0;
  if (*(int *)this == 1) {
    *(undefined4 *)this = 3;
    iVar2 = DAT_00428074 + DAT_00430484;
    iVar6 = *(int *)((int)this + 8);
    iVar9 = DAT_00428070 + -4;
    uVar3 = (uint)DAT_00428064;
    iVar7 = *(int *)((int)this + 8);
    iVar8 = *(int *)((int)this + 0xc);
    x1 = *(int *)((int)this + 8) + DAT_00428070;
    pHVar4 = CreateCompatibleDC(hdc);
    pvVar5 = SelectObject(pHVar4,DAT_00432078);
    BitBlt(hdc,iVar6 + iVar9,iVar2,(uVar3 * 0x10 - iVar7) - iVar8,5,pHVar4,x1,9,0xcc0020);
    SelectObject(pHVar4,pvVar5);
    DeleteDC(pHVar4);
    GdiFlush();
  }
  else {
    local_8 = DAT_00430b18 * 0x18 + DAT_00428074 + DAT_004302a0;
    iVar6 = 0x18 - DAT_004302a0;
    if (0 < iVar6) {
      if (DAT_00431700 < iVar6) {
        FUN_00407b66(DAT_00430b18,DAT_00430a60,DAT_004302a0,DAT_00431700);
        DAT_004302a0 = DAT_004302a0 + DAT_00431700;
        local_14 = DAT_00431700;
      }
      else {
        if (DAT_004302b0 != 0) {
          DAT_00431700 = 0x18;
        }
        FUN_00407b66(DAT_00430b18,DAT_00430a60,DAT_004302a0,iVar6);
        DAT_00430b18 = DAT_00430b18 + 1;
        local_14 = iVar6;
        if ((int)DAT_00430b18 < (int)(uint)DAT_00428068) {
          if (DAT_00428068 - 1 != DAT_00430b18) {
            iVar7 = FUN_0040818a(DAT_00430b20,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
            if (iVar7 == 0) {
              DAT_00428058 = -1;
            }
            else {
              FUN_004094d9(hdc,DAT_00428058,DAT_0042805c);
              FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
            }
          }
          DAT_004302a0 = 0;
          iVar7 = DAT_00431700 - iVar6;
          DAT_00430a60 = FUN_00407723(DAT_00430b18 - 1);
          if (iVar7 != 0) {
            FUN_00407b66(DAT_00430b18,DAT_00430a60,DAT_004302a0,iVar7);
            DAT_004302a0 = DAT_004302a0 + iVar7;
            local_14 = iVar6 + iVar7;
          }
        }
        else {
          *(undefined4 *)this = 0;
          FUN_00407b66(DAT_00430b18 - 1,DAT_00430a60,0,0x18);
          if (DAT_00432054 != 0) {
            bVar1 = false;
            if ((DAT_0043206c == 0) && (DAT_00432070 == 0)) {
              for (local_24 = 0; local_24 < DAT_00432054; local_24 = local_24 + 1) {
                FUN_00412150(hdc,(int *)(&DAT_00431f14 + local_24 * 0x10));
              }
              DAT_00432054 = 0;
            }
            else {
              for (local_24 = 0; local_24 < DAT_00432054; local_24 = local_24 + 1) {
                if ((DAT_0043206c <= *(int *)(&DAT_00431f14 + local_24 * 0x10)) &&
                   (DAT_00432070 <= *(int *)(&DAT_00431f18 + local_24 * 0x10))) {
                  bVar1 = true;
                  break;
                }
              }
              if (bVar1) {
                for (local_24 = 0; local_24 < DAT_00432054; local_24 = local_24 + 1) {
                  FUN_00412220(hdc,(int *)(&DAT_00431f14 + local_24 * 0x10),
                               *(int *)(&DAT_00431f14 + local_24 * 0x10) - DAT_0043206c,
                               *(int *)(&DAT_00431f18 + local_24 * 0x10) - DAT_00432070);
                }
              }
              else {
                for (local_24 = 0; local_24 < DAT_00432054; local_24 = local_24 + 1) {
                  FUN_00412150(hdc,(int *)(&DAT_00431f14 + local_24 * 0x10));
                }
              }
              DAT_00432054 = 0;
            }
          }
          bVar1 = FUN_00408775(DAT_00428068 - 3);
          if (CONCAT31(extraout_var,bVar1) == 0) {
            DAT_00427a80 = 1;
          }
          if (DAT_00428078 == 0) {
            DAT_00428078 = (uint)DAT_00428068;
          }
          DAT_00428078 = DAT_00428078 - 1;
          for (local_10 = 0; local_10 < (int)(uint)DAT_00428064; local_10 = local_10 + 1) {
            *(undefined4 *)(local_10 * 4 + DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) =
                 *(undefined4 *)
                  (local_10 * 4 + (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488);
          }
          for (local_10 = 0; local_10 < (int)(DAT_00428064 - 1); local_10 = local_10 + 1) {
            *(undefined4 *)(local_10 * 4 + (DAT_00428064 - 1) * DAT_00428078 * 4 + DAT_00430aec) =
                 *(undefined4 *)
                  (local_10 * 4 + (DAT_00428064 - 1) * (uint)DAT_00428068 * 4 + DAT_00430aec);
          }
        }
      }
    }
  }
  FUN_00412d55(&DAT_00431ac8,*(int *)((int)this + 8) + DAT_00428070 + -4,DAT_00428074 + DAT_00430484
               ,*(int *)((int)this + 8) + DAT_00428070,9,
               ((uint)DAT_00428064 * 0x10 - *(int *)((int)this + 8)) - *(int *)((int)this + 0xc),5,
               DAT_004318e0,-1);
  uVar3 = (uint)DAT_00428064;
  iVar6 = *(int *)((int)this + 8);
  iVar7 = *(int *)((int)this + 0xc);
  iVar8 = *(int *)((int)this + 8) + DAT_00428070 + -4;
  pHVar4 = CreateCompatibleDC(hdc);
  pvVar5 = SelectObject(pHVar4,DAT_00432078);
  BitBlt(hdc,iVar8,local_8,((uVar3 * 0x10 + 8) - iVar6) - iVar7,local_14 + 5,pHVar4,iVar8,local_8,
         0xcc0020);
  SelectObject(pHVar4,pvVar5);
  DeleteDC(pHVar4);
  GdiFlush();
  bVar1 = FUN_00408775(DAT_00430b18);
  if (CONCAT31(extraout_var_00,bVar1) != 0) {
    *(undefined4 *)((int)this + 0x14) = 1;
    if (DAT_004302a0 < 0x15) {
      DAT_00431700 = 4;
    }
    else {
      DAT_00431700 = 0x18 - DAT_004302a0;
    }
  }
  DAT_00430484 = DAT_00430484 + DAT_00431700;
  FUN_0041a0b9((void *)((int)this + 0x18),0,0,-0x8000,-0x8000);
  if (DAT_004318d0 == 1) {
    uVar3 = (uint)DAT_00428064;
    iVar6 = *(int *)((int)this + 8);
    iVar7 = *(int *)((int)this + 0xc);
    iVar8 = (DAT_00428074 + DAT_00430484) - DAT_00431700;
    iVar2 = *(int *)((int)this + 8) + DAT_00428070 + -4;
    pHVar4 = CreateCompatibleDC(hdc);
    pvVar5 = SelectObject(pHVar4,DAT_00432078);
    BitBlt(hdc,iVar2,iVar8,((uVar3 * 0x10 + 8) - iVar6) - iVar7,0x18,pHVar4,iVar2,iVar8,0xcc0020);
    SelectObject(pHVar4,pvVar5);
    DeleteDC(pHVar4);
    GdiFlush();
  }
  if (*(int *)((int)this + 0x14) == 0) {
    *(undefined4 *)((int)this + 4) = DAT_004318f4;
  }
  else {
    *(undefined4 *)((int)this + 4) = 1;
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_0040ba7e @ 0040ba7e

undefined4 __fastcall FUN_0040ba7e(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((int)param_1[1] < 1) {
    FUN_004030a3(7);
    FUN_004084cb();
    if (DAT_004302bc != 0) {
      FUN_0040e6a0();
    }
    DAT_00431700 = DAT_004302a4;
    DAT_00430484 = 0;
    DAT_00430b18 = 0;
    DAT_004302a0 = 0;
    DAT_004302b0 = 0;
    DAT_00430a60 = (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488;
    param_1[4] = 0x18;
    *param_1 = 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040bb38 @ 0040bb38

void __fastcall FUN_0040bb38(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  FUN_00407bbf();
  FUN_0040cf5a(&DAT_00430b20);
  FUN_0040c8f2(&DAT_00430b20);
  iVar3 = FUN_0040c388();
  if (iVar3 == 0) {
    FUN_0040d606(0x431900);
    iVar3 = FUN_0040c812();
    piVar2 = DAT_004318e0;
    if (iVar3 != 0) {
      uVar4 = (uint)DAT_00428068;
      iVar3 = FUN_0040c812();
      FUN_00412d55(&DAT_00431ac8,DAT_00428070 + -4,DAT_00428074,DAT_00428070 + -4,DAT_00428074,
                   iVar3 << 4,(uVar4 * 3 + 3) * 8 + 0xb,piVar2,-1);
    }
    uVar4 = FUN_0040c880();
    piVar2 = DAT_004318e0;
    if (uVar4 != DAT_00428064 - 1) {
      uVar4 = (uint)DAT_00428068;
      uVar9 = (uint)DAT_00428064;
      uVar5 = FUN_0040c880();
      iVar3 = DAT_00428074;
      uVar6 = FUN_0040c880();
      iVar1 = DAT_00428074;
      iVar8 = DAT_00428070 + -4;
      uVar7 = FUN_0040c880();
      FUN_00412d55(&DAT_00431ac8,(uVar7 + 1) * 0x10 + DAT_00428070 + -4,iVar1,
                   (uVar6 + 1) * 0x10 + iVar8,iVar3,((uVar9 - 1) - uVar5) * 0x10,
                   (uVar4 * 3 + 3) * 8 + 0xb,piVar2,-1);
    }
    FUN_0040d5a5(&DAT_00431900);
  }
  iVar3 = FUN_0040c812();
  *(int *)(param_1 + 8) = iVar3 << 4;
  uVar5 = (uint)DAT_00428064;
  uVar4 = FUN_0040c880();
  *(uint *)(param_1 + 0xc) = ((uVar5 - 1) - uVar4) * 0x10;
  return;
}


// ==== FUN_0040bd0a @ 0040bd0a

int __fastcall FUN_0040bd0a(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int *local_a8;
  int *local_a4;
  undefined *local_a0;
  undefined *local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_84;
  int local_80;
  int local_7c;
  char local_78 [100];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  local_10 = FUN_0040c812();
  local_10 = -local_10;
  local_84 = 0;
  for (local_80 = 0; local_80 < (int)(uint)DAT_00428064; local_80 = local_80 + 1) {
    for (local_7c = 0; local_7c < (int)(DAT_00428068 + 1); local_7c = local_7c + 1) {
      *(undefined4 *)(&DAT_00430bcc + local_80 * 0x10 + local_7c * 0xc0) = 0xff;
      *(undefined4 *)(&DAT_00430bc8 + local_80 * 0x10 + local_7c * 0xc0) =
           *(undefined4 *)(&DAT_00430bcc + local_80 * 0x10 + local_7c * 0xc0);
      *(undefined4 *)(&DAT_00430bc4 + local_80 * 0x10 + local_7c * 0xc0) =
           *(undefined4 *)(&DAT_00430bc8 + local_80 * 0x10 + local_7c * 0xc0);
      *(undefined4 *)(&DAT_00430bc0 + local_80 * 0x10 + local_7c * 0xc0) =
           *(undefined4 *)(&DAT_00430bc4 + local_80 * 0x10 + local_7c * 0xc0);
    }
    iVar2 = FUN_00408be8(local_80);
    if (iVar2 != 0) {
      FUN_0040892f(local_80,0xf,0);
      bVar1 = FUN_00409390();
      FUN_004091ff(0xf,CONCAT31(extraout_var,bVar1));
      if (DAT_004302bc != 0) {
        local_14 = (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488;
        if ((DAT_004302c0 == local_80) || (DAT_004302c4 == local_80)) {
          DAT_004302bc = 0;
          local_9c = &DAT_004302ec + DAT_0043047c * 0x50;
          FUN_0041a0b9((void *)(DAT_0043047c * 0x50 + 0x43032c),0,0,-0x8000,-0x8000);
          FUN_0041a0b9(&DAT_004302cc,0,0,-0x8000,-0x8000);
          FUN_0041a0b9(&DAT_004302dc,0,0,-0x8000,-0x8000);
        }
        else {
          if (local_80 < DAT_004302c0) {
            local_c = local_c + -1;
          }
          if (local_80 < DAT_004302c4) {
            local_8 = local_8 + -1;
          }
        }
      }
      local_80 = -1;
      local_84 = local_84 + 1;
    }
  }
  if (local_84 != 0) {
    FUN_004030a3(1);
    iVar3 = FUN_00403650(DAT_00428088,(DAT_004318e4 + -1) / 3 + 1);
    iVar2 = DAT_00428084;
    iVar4 = FUN_00409bec();
    DAT_004318dc = DAT_004318dc + iVar3 * (iVar2 - iVar4);
    _sprintf(local_78,&DAT_00428328,DAT_004318dc);
    if (DAT_00431aa0 != (void *)0x0) {
      FUN_0041a0b9(&DAT_00431aac,0,0,-0x8000,-0x8000);
      FUN_0041ba43(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_78,&local_b8);
      FUN_00419da8(&DAT_00431aac,local_b8,local_b4,local_b0,local_ac,0);
      FUN_0041aeb1(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_78,0);
    }
    DAT_00428084 = FUN_00409bec();
    DAT_00428088 = FUN_00409c5c();
    FUN_0040bb38(param_1);
  }
  iVar2 = FUN_0040ae8e();
  if ((iVar2 == 0) && (DAT_00427a84 == 0)) {
    DAT_00427a84 = 400;
  }
  iVar2 = FUN_0040c812();
  *(int *)(param_1 + 8) = iVar2 << 4;
  uVar6 = (uint)DAT_00428064;
  uVar5 = FUN_0040c880();
  *(uint *)(param_1 + 0xc) = ((uVar6 - 1) - uVar5) * 0x10;
  iVar2 = FUN_0040c812();
  local_10 = local_10 + iVar2;
  local_c = local_c + local_10;
  local_8 = local_8 + local_10;
  if ((DAT_004302bc != 0) &&
     ((local_14 = (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488,
      *(int *)(local_14 + DAT_004302c0 * 4) == 0 || (*(int *)(local_14 + DAT_004302c4 * 4) == 0))))
  {
    DAT_004302bc = 0;
    local_a0 = &DAT_004302ec + DAT_0043047c * 0x50;
    FUN_0041a0b9((void *)(DAT_0043047c * 0x50 + 0x43032c),0,0,-0x8000,-0x8000);
    FUN_0041a0b9(&DAT_004302cc,0,0,-0x8000,-0x8000);
    FUN_0041a0b9(&DAT_004302dc,0,0,-0x8000,-0x8000);
  }
  if (((local_84 != 0) && (DAT_004302bc != 0)) && ((local_c != 0 || (local_8 != 0)))) {
    if (local_c != 0) {
      DAT_004302c0 = DAT_004302c0 + local_c;
      FUN_0041a0b9(&DAT_004302cc,0,0,-0x8000,-0x8000);
      local_8c = DAT_004302c0 * 0x10 + DAT_00428070;
      local_94 = DAT_00428074 + -8;
      local_90 = local_8c + 8;
      local_98 = DAT_00428074;
      FUN_00419da8(&DAT_004302cc,local_8c,local_94,local_90,DAT_00428074,0);
      local_a4 = DAT_00430af4;
      FUN_00412d55(&DAT_00431ac8,local_8c,local_94,0x30,0,9,9,DAT_00430af4,0);
    }
    if (local_8 != 0) {
      DAT_004302c4 = DAT_004302c4 + local_8;
      FUN_0041a0b9(&DAT_004302dc,0,0,-0x8000,-0x8000);
      local_8c = DAT_004302c4 * 0x10 + DAT_00428070;
      local_98 = (uint)DAT_00428068 * 0x18 + DAT_00428074;
      local_94 = local_98 + -1;
      local_90 = local_8c + 8;
      local_98 = local_98 + 7;
      FUN_00419da8(&DAT_004302dc,local_8c,local_94,local_90,local_98,0);
      local_a8 = DAT_00430af4;
      FUN_00412d55(&DAT_00431ac8,local_8c,local_94,0x30,0,9,9,DAT_00430af4,0);
    }
  }
  return local_84;
}


// ==== FUN_0040c388 @ 0040c388

undefined4 FUN_0040c388(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if ((int)(uint)DAT_00428064 <= local_c) {
      DAT_004318d0 = 1;
      PostMessageA(DAT_00431704,0x111,100,0);
      return 1;
    }
    if (*(int *)((uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488 + local_c * 4) != 0) break;
    local_c = local_c + 1;
  }
  return 0;
}


// ==== FUN_0040c417 @ 0040c417

void __thiscall FUN_0040c417(void *this,HWND param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  HGDIOBJ local_78;
  HDC local_74;
  HDC local_70;
  char local_6c [100];
  int local_8;
  
  if (*(int *)((int)this + 4) < 1) {
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined4 *)this = 2;
    *(undefined4 *)((int)this + 4) = 200;
    if (DAT_004318e4 < 2) {
      DAT_00430a6c = 400;
    }
    else if (DAT_004318e4 < 4) {
      DAT_00430a6c = 300;
    }
    if ((0x1b < DAT_004318e4) &&
       (*(int *)((int)this + 4) = (DAT_004318e4 * 5 + -0x87) * -2 + 200,
       *(int *)((int)this + 4) < 0x32)) {
      *(undefined4 *)((int)this + 4) = 0x32;
    }
    local_70 = GetDC(param_1);
    SelectPalette(local_70,DAT_00431ae4,0);
    RealizePalette(local_70);
    local_80 = (((uint)DAT_00428064 * 0x10 + 8) - *(int *)((int)this + 8)) -
               *(int *)((int)this + 0xc);
    local_84 = (DAT_00428074 + DAT_00430484) - DAT_00431700;
    local_88 = *(int *)((int)this + 8) + DAT_00428070 + -4;
    local_7c = DAT_00431ac8;
    local_74 = CreateCompatibleDC(local_70);
    local_78 = SelectObject(local_74,DAT_00432078);
    BitBlt(local_70,local_88,local_84,local_80,0x18,local_74,local_88,local_84,0xcc0020);
    SelectObject(local_74,local_78);
    DeleteDC(local_74);
    GdiFlush();
    ReleaseDC(param_1,local_70);
    local_8 = FUN_0040eccd(0x4302b8);
    FUN_004096c8(param_1);
    if (local_8 != 0) {
      bVar1 = FUN_00409390();
      FUN_004091ff(9,CONCAT31(extraout_var,bVar1));
      FUN_004030a3(1);
      iVar2 = FUN_00403650(DAT_00428088,(DAT_004318e4 + -1) / 3 + 1);
      iVar4 = DAT_00428084;
      iVar3 = FUN_00409bec();
      DAT_004318dc = DAT_004318dc + iVar2 * (iVar4 - iVar3);
      _sprintf(local_6c,&DAT_00428330,DAT_004318dc);
      if (DAT_00431aa0 != (void *)0x0) {
        FUN_0041a0b9(&DAT_00431aac,0,0,-0x8000,-0x8000);
        FUN_0041ba43(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_6c,&local_98);
        FUN_00419da8(&DAT_00431aac,local_98,local_94,local_90,local_8c,0);
        FUN_0041aeb1(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_6c,0);
      }
      DAT_00428084 = FUN_00409bec();
      DAT_00428088 = FUN_00409c5c();
      FUN_0040bb38((int)this);
      FUN_004096c8(param_1);
    }
    iVar4 = FUN_0040bd0a((int)this);
    if (iVar4 != 0) {
      FUN_004096c8(param_1);
    }
    if ((DAT_004318d0 != 1) && (iVar4 = FUN_0040e984(&DAT_004302b8,0), iVar4 != 0)) {
      FUN_004096c8(param_1);
    }
    FUN_0040cf5a(&DAT_00430b20);
    iVar4 = FUN_0040818a(DAT_00430b20,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
    if (iVar4 == 0) {
      DAT_00428058 = -1;
    }
    else {
      FUN_004094d9(local_70,DAT_00428058,DAT_0042805c);
      FUN_004096c8(param_1);
      FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
    }
  }
  return;
}


// ==== FUN_0040c812 @ 0040c812

int FUN_0040c812(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if ((int)(uint)DAT_00428064 <= local_c) {
      return 0;
    }
    if (*(int *)((uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488 + local_c * 4) != 0) break;
    local_c = local_c + 1;
  }
  return local_c;
}


// ==== FUN_0040c880 @ 0040c880

uint FUN_0040c880(void)

{
  uint local_c;
  
  local_c = (uint)DAT_00428064;
  do {
    local_c = local_c - 1;
    if ((int)local_c < 0) {
      return DAT_00428064 - 1;
    }
  } while (*(int *)((uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488 + local_c * 4) == 0);
  return local_c;
}


// ==== FUN_0040c8f2 @ 0040c8f2

void __fastcall FUN_0040c8f2(uint *param_1)

{
  int local_14 [3];
  undefined4 local_8;
  
  if (param_1[1] == 0) {
    param_1[1] = 1;
  }
  else {
    FUN_0041a0b9(param_1 + 0x12,0,0,-0x8000,-0x8000);
  }
  local_14[1] = 0;
  local_8 = 0x17;
  if ((*param_1 & 0x80) == 0) {
    local_14[0] = 0;
  }
  else {
    local_14[0] = 0x18;
  }
  local_14[2] = local_14[0] + 0x17;
  FUN_004196c1(param_1 + 2,(*param_1 & 0x7f) * 0x10 + DAT_00428070,
               (uint)DAT_00428068 * 0x18 + DAT_00428074 + 9,local_14,1);
  return;
}


// ==== FUN_0040c9b2 @ 0040c9b2

undefined4 __thiscall FUN_0040c9b2(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)this & 0x7f;
  if (param_1 == 0x27) {
    if ((int)uVar1 <= DAT_004318d4 + -3) {
      iVar2 = FUN_00407723(0);
      if (*(int *)(iVar2 + 8 + uVar1 * 4) == 0) {
        return 0;
      }
      *(uint *)this = (*(uint *)this & 0x80) + uVar1 + 1;
      FUN_0040c8f2(this);
    }
  }
  else if (uVar1 != 0) {
    iVar2 = FUN_00407723(0);
    if (*(int *)(iVar2 + -4 + uVar1 * 4) == 0) {
      return 0;
    }
    *(uint *)this = (*(uint *)this & 0x80) + (uVar1 - 1);
    FUN_0040c8f2(this);
  }
  if ((-1 < DAT_00428058) && (((int)DAT_00430b18 < DAT_0042805c || (DAT_00428068 == DAT_00430b18))))
  {
    FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
  }
  iVar2 = FUN_0040818a(*(uint *)this,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
  if (iVar2 == 0) {
    DAT_00428058 = -1;
  }
  else {
    FUN_0040943f(DAT_00428058,DAT_0042805c,(HWND)0x0);
  }
  return 1;
}


// ==== FUN_0040cb08 @ 0040cb08

void __thiscall FUN_0040cb08(void *this,uint *param_1)

{
  LPVOID pvVar1;
  
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 1;
  if (*(int *)((int)this + 0x48) != 0) {
    FUN_0041ee80(*(void **)((int)this + 0x48));
  }
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  FUN_0041e6e0((uint *)((int)this + 0x10),param_1);
  *(undefined4 *)((int)this + 0x28) = 1;
  *(undefined4 *)((int)this + 0x2c) = 0;
  if ((*(int *)((int)this + 0x28) != 0) && (*(int *)((int)this + 8) == 0)) {
    if (*(int *)((int)this + 0x2c) == 0) {
      if (*(int *)((int)this + 0x28) == 1) {
        pvVar1 = FUN_00402226((LPCSTR)((int)this + 0x10));
        *(LPVOID *)((int)this + 8) = pvVar1;
      }
      else {
        pvVar1 = FUN_00402226(*(LPCSTR *)((int)this + 0x24));
        *(LPVOID *)((int)this + 8) = pvVar1;
      }
      if (*(int *)((int)this + 8) != 0) {
        *(undefined4 *)((int)this + 0xc) = 1;
      }
    }
    else if (*(int *)((int)this + 8) != 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}


// ==== FUN_0040ccff @ 0040ccff

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040ccff(uint *param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  DAT_00431a9c = 0;
  if ((((DAT_00428068 - 1 != DAT_00430b18) && (DAT_00428068 - 2 != DAT_00430b18)) &&
      ((DAT_00428068 - 3 != DAT_00430b18 || (DAT_00430a7c == 0)))) &&
     ((iVar2 = FUN_0040818a(*param_1,&local_18,&local_1c), iVar2 != 0 &&
      ((int)local_1c < (int)(DAT_00428068 - 1))))) {
    iVar2 = FUN_00407723(local_1c);
    local_8 = (undefined4 *)(iVar2 + local_18 * 4);
    local_14 = (uint)(((byte)*local_8 & 7) != 2);
    FUN_00407e92(*param_1,(HWND)0x0);
    bVar1 = FUN_0040d7ed(&DAT_00431900,local_18,local_1c);
    DAT_00431a9c = CONCAT31(extraout_var,bVar1);
    if ((*param_1 & 0x80) == 0) {
      *param_1 = *param_1 & 0x7f | 0x80;
    }
    else {
      *param_1 = *param_1 & 0x7f;
    }
    if ((*param_1 & 0x80) == 0) {
      FUN_004030a3(5);
    }
    else {
      FUN_004030a3(6);
    }
    if ((int)(uint)DAT_00428068 <= DAT_00430b18) {
      FUN_0040bd0a(0x430a68);
    }
    FUN_0040c8f2(param_1);
    iVar2 = FUN_0040818a(*param_1,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
    if (iVar2 == 0) {
      DAT_00428058 = -1;
    }
    else {
      FUN_0040943f(DAT_00428058,DAT_0042805c,(HWND)0x0);
    }
    if (local_14 != 0) {
      local_10 = ((DAT_004318e4 / 3) * 5 + 5) * 200;
      local_c = DAT_004318dc / local_10;
      if (((local_10 + _DAT_0042808c <= DAT_004318dc) && (6 < DAT_004318e4)) &&
         (_DAT_0042808c = DAT_004318dc, DAT_004318b4 < 1)) {
        FUN_0040db7e(&DAT_00431768);
        DAT_004318b4 = DAT_004318b4 + 1;
        FUN_004030a3(8);
      }
    }
  }
  return;
}


// ==== FUN_0040cf5a @ 0040cf5a

void __fastcall FUN_0040cf5a(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_c;
  
  uVar1 = *param_1 & 0x7f;
  uVar2 = FUN_0040c812();
  local_c = uVar1;
  if ((int)uVar1 <= (int)uVar2) {
    local_c = uVar2;
  }
  uVar3 = FUN_0040c880();
  uVar2 = uVar3 - 1;
  if ((int)uVar1 <= (int)(uVar3 - 1)) {
    uVar2 = uVar1;
  }
  if (((int)local_c <= (int)uVar1) && (local_c = uVar1, (int)uVar2 < (int)uVar1)) {
    local_c = uVar2;
  }
  *param_1 = *param_1 & 0x80 | local_c;
  return;
}


// ==== FUN_0040cff7 @ 0040cff7

void FUN_0040cff7(void)

{
  return;
}


// ==== FUN_0040d00f @ 0040d00f

int FUN_0040d00f(int param_1)

{
  undefined4 local_8;
  
  if (param_1 + DAT_00428078 < (int)(uint)DAT_00428068) {
    local_8 = param_1 + DAT_00428078;
  }
  else {
    local_8 = (param_1 + DAT_00428078) - (uint)DAT_00428068;
  }
  return (DAT_00428064 - 1) * local_8 * 4 + DAT_00430aec;
}


// ==== FUN_0040d07c @ 0040d07c

void __thiscall FUN_0040d07c(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_004318e4 < 4) {
    iVar1 = FUN_00406245(2);
  }
  else {
    iVar1 = FUN_00406245(5);
  }
  if ((iVar1 == 0) &&
     (((DAT_004318e4 < 0x1c || (iVar1 = FUN_00406245(2), iVar1 == 0)) &&
      (DAT_00427a88 < DAT_00427a8c)))) {
    iVar1 = (DAT_00428064 - 1) * (uint)DAT_00428068 * 4 + DAT_00430aec;
    iVar2 = FUN_00406245(5);
    *(int *)(iVar1 + param_1 * 4) = iVar2 * 8 + *(int *)((int)this + 0x50) + 8;
  }
  return;
}


// ==== FUN_0040d14c @ 0040d14c

void __thiscall FUN_0040d14c(void *this,HWND param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  int local_24;
  uint local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = FUN_0040d00f(param_3);
  puVar1 = (uint *)(iVar2 + param_2 * 4);
  local_1c = *puVar1 >> 4 & 0xf;
  switch(*puVar1 & 7) {
  case 1:
    local_24 = 3;
    break;
  case 2:
    local_24 = 2;
    break;
  case 3:
    local_24 = 1;
    break;
  case 4:
    local_24 = 0;
    break;
  default:
    local_24 = 0;
  }
  if (local_1c < 8) {
    local_10 = local_24 * 0x18;
    local_8 = local_10 + 0x17;
    local_14 = local_1c * 0x18;
    local_c = local_14 + 0x17;
    FUN_004196c1(this,param_2 * 0x10 + DAT_00428070,(param_4 + param_3) * 0x18 + DAT_00428074,
                 &local_14,1);
    if ((param_2 == DAT_00428058) && (DAT_0042805c == param_3)) {
      FUN_0040943f(param_2,param_3,(HWND)0x0);
    }
    FUN_004096c8(param_1);
    FUN_0041a0b9((void *)((int)this + 0x40),0,0,-0x8000,-0x8000);
  }
  if (local_1c < 7) {
    local_1c = local_1c + 1;
  }
  else {
    local_1c = 0;
  }
  *puVar1 = (local_1c & 0xf) << 4 | *puVar1 & 0xf;
  return;
}


// ==== FUN_0040d2f3 @ 0040d2f3

void FUN_0040d2f3(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < (int)(uint)DAT_00428068; local_10 = local_10 + 1) {
    iVar1 = FUN_0040d00f(local_10);
    local_14 = FUN_0040c812();
    while( true ) {
      uVar2 = FUN_0040c880();
      if ((int)uVar2 <= local_14) break;
      if (*(int *)(iVar1 + local_14 * 4) != 0) {
        iVar3 = FUN_00407723(local_10);
        if ((*(byte *)(iVar3 + local_14 * 4) & 1) == 0) {
          *(undefined4 *)(iVar1 + local_14 * 4) = 0;
        }
      }
      local_14 = local_14 + 1;
    }
  }
  return;
}


// ==== FUN_0040d3a7 @ 0040d3a7

void __thiscall FUN_0040d3a7(void *this,HWND param_1)

{
  int iVar1;
  uint uVar2;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < (int)(uint)DAT_00428068; local_c = local_c + 1) {
    iVar1 = FUN_0040d00f(local_c);
    if ((local_c <= DAT_00430b18 + -2) || (DAT_00430b18 + 2 <= local_c)) {
      for (local_10 = FUN_0040c812(); uVar2 = FUN_0040c880(), local_10 < (int)uVar2;
          local_10 = local_10 + 1) {
        if (*(int *)(iVar1 + local_10 * 4) != 0) {
          if (local_c < DAT_00430b18) {
            if (DAT_00430b18 < (int)(uint)DAT_00428068) {
              DAT_00432054 = 0;
              FUN_0040d14c(this,param_1,local_10,local_c,1);
            }
            else {
              DAT_00432054 = 0;
              FUN_0040d14c(this,param_1,local_10,local_c,0);
            }
          }
          else {
            DAT_00432054 = 0;
            FUN_0040d14c(this,param_1,local_10,local_c,0);
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_0040d4ff @ 0040d4ff

void FUN_0040d4ff(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 local_c;
  
  if ((-1 < DAT_00430b18) && (DAT_00430b18 < (int)(uint)DAT_00428068)) {
    for (local_c = 0; local_c < (int)(DAT_00428064 - 1); local_c = local_c + 1) {
      iVar2 = FUN_0040d00f(DAT_00430b18);
      pbVar1 = (byte *)(iVar2 + local_c * 4);
      if (*(int *)pbVar1 != 0) {
        if ((*pbVar1 & 7) != 0) {
          *(int *)pbVar1 = *(int *)pbVar1 + -1;
        }
        if ((*pbVar1 & 7) == 0) {
          pbVar1[0] = 0;
          pbVar1[1] = 0;
          pbVar1[2] = 0;
          pbVar1[3] = 0;
        }
      }
    }
  }
  return;
}


// ==== FUN_0040d5a5 @ 0040d5a5

void __fastcall FUN_0040d5a5(void *param_1)

{
  uint local_8;
  
  if (*(int *)((int)param_1 + 0x58) != 0) {
    for (local_8 = 1; ((int)local_8 < 0x15 && ((int)local_8 <= *(int *)((int)param_1 + 0x58)));
        local_8 = local_8 + 1) {
      FUN_0040d860(param_1,local_8);
    }
  }
  return;
}


// ==== FUN_0040d606 @ 0040d606

void __fastcall FUN_0040d606(int param_1)

{
  int local_8;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    for (local_8 = 1; (local_8 < 0x15 && (local_8 <= *(int *)(param_1 + 0x58)));
        local_8 = local_8 + 1) {
      FUN_0041a0b9((void *)((local_8 + -1) * 0x10 + 0x5c + param_1),0,0,-0x8000,-0x8000);
    }
  }
  return;
}


// ==== FUN_0040d67c @ 0040d67c

void __thiscall FUN_0040d67c(void *this,HWND param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040818a(*(uint *)this,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
  if (iVar1 != 0) {
    FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
  }
  if ((*(byte *)this & 0x80) == 0) {
    *(uint *)this = (*(uint *)this & 0x7f) + 0x80;
  }
  else {
    *(uint *)this = *(uint *)this & 0x7f;
  }
  FUN_0040c8f2(this);
  iVar1 = FUN_0040818a(*(uint *)this,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
  if (iVar1 == 0) {
    DAT_00428058 = -1;
  }
  else {
    FUN_0040943f(DAT_00428058,DAT_0042805c,(HWND)0x0);
  }
  FUN_004096c8(param_1);
  if (-1 < DAT_00428058) {
    FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
  }
  return;
}


// ==== FUN_0040d76f @ 0040d76f

void __thiscall FUN_0040d76f(void *this,HWND param_1)

{
  if (0 < *(int *)((int)this + 0x58)) {
    if (*(int *)((int)this + 0x58) < 0x15) {
      FUN_0041a0b9((void *)((*(int *)((int)this + 0x58) + -1) * 0x10 + 0x5c + (int)this),0,0,-0x8000
                   ,-0x8000);
    }
    FUN_004030a3(0xe);
    *(int *)((int)this + 0x58) = *(int *)((int)this + 0x58) + -1;
    FUN_0040d67c(&DAT_00430b20,param_1);
  }
  return;
}


// ==== FUN_0040d7ed @ 0040d7ed

bool __thiscall FUN_0040d7ed(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = FUN_0040d00f(param_2);
  piVar1 = (int *)(iVar2 + param_1 * 4);
  bVar3 = *piVar1 != 0;
  if (bVar3) {
    *piVar1 = 0;
    *(int *)((int)this + 0x58) = *(int *)((int)this + 0x58) + 1;
    DAT_00427a88 = DAT_00427a88 + 1;
    FUN_004030a3(4);
    FUN_0040d860(this,*(uint *)((int)this + 0x58));
  }
  return bVar3;
}


// ==== FUN_0040d860 @ 0040d860

void __thiscall FUN_0040d860(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  int local_20;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  
  if ((0 < (int)param_1) && ((int)param_1 < 0x15)) {
    local_14[1] = 0;
    local_8 = 0x17;
    uVar2 = (int)param_1 >> 0x1f;
    if (((param_1 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
      local_14[0] = 0x18;
      uVar2 = FUN_0040c880();
      local_18 = (uVar2 + 1) * 0x10 + DAT_00428070 + -4;
      local_20 = DAT_00428074 + (((int)(param_1 - 2) % 0x14) * 0x18) / 2;
    }
    else {
      local_14[0] = 0;
      iVar1 = FUN_0040c812();
      local_18 = iVar1 * 0x10 + DAT_00428070 + -0x1c;
      local_20 = DAT_00428074 + (((int)(param_1 - 1) % 0x14) * 0x18) / 2;
    }
    FUN_00419da8((void *)((param_1 - 1) * 0x10 + 0x5c + (int)this),local_18,local_20,local_18 + 0x17
                 ,local_20 + 0x17,0);
    local_14[2] = local_14[0] + 0x17;
    local_14[1] = 0;
    local_8 = 0x17;
    FUN_00419212(&DAT_00430b28,local_18,local_20,local_14,1);
  }
  return;
}


// ==== FUN_0040d9b4 @ 0040d9b4

undefined4 * __fastcall FUN_0040d9b4(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040da29;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_(param_1 + 1,0x50,4,FUN_004122f0,FUN_00411f90);
  *param_1 = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040da42 @ 0040da42

void __fastcall FUN_0040da42(int param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(int *)(local_8 * 0x50 + 0x2c + param_1) =
         *(int *)(&DAT_00427d28 + DAT_004318ec * 0x2c) + *(int *)(&DAT_00427cc8 + local_8 * 8);
    *(int *)(local_8 * 0x50 + 0x30 + param_1) =
         *(int *)(&DAT_00427d2c + DAT_004318ec * 0x2c) + *(int *)(&DAT_00427ccc + local_8 * 8);
  }
  return;
}


// ==== FUN_0040daea @ 0040daea

void __fastcall FUN_0040daea(int param_1)

{
  FUN_0041a0b9((void *)(*(int *)(param_1 + 0x144) * 0x50 + param_1 + 0x44),0,0,-0x8000,-0x8000);
  if (*(int *)(param_1 + 0x144) < 3) {
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  FUN_0041890e((void *)(*(int *)(param_1 + 0x144) * 0x50 + 4 + param_1),1);
  return;
}


// ==== FUN_0040db7e @ 0040db7e

void __fastcall FUN_0040db7e(int *param_1)

{
  if (*param_1 == 0) {
    *param_1 = 1;
    param_1[0x51] = 0;
    param_1[0x52] = -1;
  }
  return;
}


// ==== FUN_0040dbc8 @ 0040dbc8

void __cdecl FUN_0040dbc8(int param_1,int param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(uint)DAT_00428064 <= local_8) {
      return;
    }
    iVar1 = FUN_00408c77(param_1,local_8);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  FUN_0040892f(param_1,param_2,1);
  return;
}


// ==== FUN_0040dc2e @ 0040dc2e

void FUN_0040dc2e(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  for (local_c = 0; local_c < (int)(uint)DAT_00428068; local_c = local_c + 1) {
    iVar2 = FUN_00407723(local_c);
    for (local_10 = 0; local_10 < (int)(DAT_00428064 - 1); local_10 = local_10 + 1) {
      if (((*(byte *)(iVar2 + local_10 * 4) & 1) != 0) &&
         (((*(uint *)(iVar2 + 4 + local_10 * 4) ^ *(uint *)(iVar2 + local_10 * 4) & 0x78) & 0x78) ==
          0)) {
        puVar1 = (uint *)(iVar2 + local_10 * 4);
        *puVar1 = *puVar1 | 2;
        puVar1 = (uint *)(iVar2 + 4 + local_10 * 4);
        *puVar1 = *puVar1 | 2;
      }
    }
  }
  return;
}


// ==== FUN_0040dce3 @ 0040dce3

undefined4 __fastcall FUN_0040dce3(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x54] == 0) {
    if ((int)param_1[0x53] < 1) {
      uVar1 = 0;
    }
    else {
      param_1[0x53] = param_1[0x53] + -1;
      FUN_004030a3(0xb);
      param_1[0x54] = 1;
      if (param_1[0x53] == 0) {
        *param_1 = 0;
        FUN_0041a0b9(param_1 + param_1[0x51] * 0x14 + 0x11,0,0,-0x8000,-0x8000);
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040dda2 @ 0040dda2

undefined4 __fastcall FUN_0040dda2(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34 [12];
  
  if (*(int *)(param_1 + 0x150) == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x150) = 0;
    FUN_0040a99a();
    iVar3 = (uint)DAT_00428064 * DAT_00428078 * 4 + DAT_00430488;
    FUN_0040622a();
    for (local_38 = 0; local_38 < 1000; local_38 = local_38 + 1) {
      local_34[0] = FUN_00406245(9);
      local_34[1] = FUN_00406245(9);
      if (local_34[1] != local_34[0]) {
        local_34[2] = *(int *)(&DAT_00428090 + local_34[0] * 4);
        *(undefined4 *)(&DAT_00428090 + local_34[0] * 4) =
             *(undefined4 *)(&DAT_00428090 + local_34[1] * 4);
        *(int *)(&DAT_00428090 + local_34[1] * 4) = local_34[2];
      }
    }
    for (local_38 = 0; local_38 < (int)(uint)DAT_00428064; local_38 = local_38 + 1) {
      local_34[local_38] = 0;
    }
    for (local_38 = 0; local_38 < (int)(uint)DAT_00428064; local_38 = local_38 + 1) {
      if (*(int *)(iVar3 + local_38 * 4) != 0) {
        piVar1 = (int *)((int)local_34 + ((*(uint *)(iVar3 + local_38 * 4) & 0x78) >> 1));
        *piVar1 = *piVar1 + 1;
      }
    }
    local_3c = 0;
    for (local_38 = 0; local_38 < (int)(uint)DAT_00428064; local_38 = local_38 + 1) {
      if (local_34[local_38] != 0) {
        local_3c = local_3c + 1;
      }
    }
    local_40 = 0;
    for (local_38 = 0; local_38 < (int)(uint)DAT_00428064; local_38 = local_38 + 1) {
      if (*(int *)(iVar3 + local_38 * 4) != 0) {
        for (local_48 = 0; local_48 < (int)(uint)DAT_00428064; local_48 = local_48 + 1) {
          for (local_4c = 0; local_4c < (int)(DAT_00428068 + 1); local_4c = local_4c + 1) {
            *(undefined4 *)(&DAT_00430bcc + local_4c * 0xc0 + local_48 * 0x10) = 0xff;
            *(undefined4 *)(&DAT_00430bc8 + local_4c * 0xc0 + local_48 * 0x10) =
                 *(undefined4 *)(&DAT_00430bcc + local_4c * 0xc0 + local_48 * 0x10);
            *(undefined4 *)(&DAT_00430bc4 + local_4c * 0xc0 + local_48 * 0x10) =
                 *(undefined4 *)(&DAT_00430bc8 + local_4c * 0xc0 + local_48 * 0x10);
            *(undefined4 *)(&DAT_00430bc0 + local_4c * 0xc0 + local_48 * 0x10) =
                 *(undefined4 *)(&DAT_00430bc4 + local_4c * 0xc0 + local_48 * 0x10);
          }
        }
        if (local_40 < 2) {
          local_40 = local_40 + 1;
          FUN_0040dbc8(local_38,0);
        }
        else {
          iVar4 = FUN_00406245(local_3c);
          FUN_0040dbc8(local_38,iVar4);
        }
      }
    }
    FUN_0040dc2e();
    FUN_00407bbf();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040e0aa @ 0040e0aa

/* WARNING: Removing unreachable block (ram,0x0040e53d) */
/* WARNING: Removing unreachable block (ram,0x0040e4db) */
/* WARNING: Removing unreachable block (ram,0x0040e4e8) */
/* WARNING: Removing unreachable block (ram,0x0040e4ed) */
/* WARNING: Removing unreachable block (ram,0x0040e4fa) */
/* WARNING: Removing unreachable block (ram,0x0040e506) */
/* WARNING: Removing unreachable block (ram,0x0040e4a9) */

void FUN_0040e0aa(void)

{
  uint *puVar1;
  LPVOID pvVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    puVar1 = (uint *)FUN_00401d30((uint *)s_CANDLE_00428338,local_8,1);
    FUN_0041e6e0((uint *)(local_8 * 0x50 + 0x4302f4),puVar1);
    *(undefined4 *)(&DAT_0043030c + local_8 * 0x50) = 1;
    *(undefined4 *)(&DAT_00430310 + local_8 * 0x50) = 0;
    if ((*(int *)(&DAT_0043030c + local_8 * 0x50) != 0) &&
       (*(int *)(&DAT_004302ec + local_8 * 0x50) == 0)) {
      if (*(int *)(&DAT_00430310 + local_8 * 0x50) == 0) {
        if (*(int *)(&DAT_0043030c + local_8 * 0x50) == 1) {
          pvVar2 = FUN_00402226((LPCSTR)(local_8 * 0x50 + 0x4302f4));
          *(LPVOID *)(&DAT_004302ec + local_8 * 0x50) = pvVar2;
        }
        else {
          pvVar2 = FUN_00402226(*(LPCSTR *)(&DAT_00430308 + local_8 * 0x50));
          *(LPVOID *)(&DAT_004302ec + local_8 * 0x50) = pvVar2;
        }
        if (*(int *)(&DAT_004302ec + local_8 * 0x50) != 0) {
          *(undefined4 *)(&DAT_004302f0 + local_8 * 0x50) = 1;
        }
      }
      else if (*(int *)(&DAT_004302ec + local_8 * 0x50) != 0) {
        *(undefined4 *)(&DAT_004302f0 + local_8 * 0x50) = 0;
      }
    }
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    puVar1 = (uint *)FUN_00401d30((uint *)s_MOV_BRUSH_00428340,local_8,1);
    FUN_0041e6e0((uint *)(local_8 * 0x50 + 0x431774),puVar1);
    *(undefined4 *)(&DAT_0043178c + local_8 * 0x50) = 1;
    *(undefined4 *)(&DAT_00431790 + local_8 * 0x50) = 0;
    if ((*(int *)(&DAT_0043178c + local_8 * 0x50) != 0) &&
       (*(int *)(&DAT_0043176c + local_8 * 0x50) == 0)) {
      if (*(int *)(&DAT_00431790 + local_8 * 0x50) == 0) {
        if (*(int *)(&DAT_0043178c + local_8 * 0x50) == 1) {
          pvVar2 = FUN_00402226((LPCSTR)(local_8 * 0x50 + 0x431774));
          *(LPVOID *)(&DAT_0043176c + local_8 * 0x50) = pvVar2;
        }
        else {
          pvVar2 = FUN_00402226(*(LPCSTR *)(&DAT_00431788 + local_8 * 0x50));
          *(LPVOID *)(&DAT_0043176c + local_8 * 0x50) = pvVar2;
        }
        if (*(int *)(&DAT_0043176c + local_8 * 0x50) != 0) {
          *(undefined4 *)(&DAT_00431770 + local_8 * 0x50) = 1;
        }
      }
      else if (*(int *)(&DAT_0043176c + local_8 * 0x50) != 0) {
        *(undefined4 *)(&DAT_00431770 + local_8 * 0x50) = 0;
      }
    }
  }
  FUN_0041e6e0((uint *)&DAT_00431908,(uint *)s_STARS_0042834c);
  DAT_00431920 = 1;
  DAT_00431924 = 0;
  if ((DAT_00431900 == (LPVOID)0x0) &&
     (DAT_00431900 = FUN_00402226(&DAT_00431908), DAT_00431900 != (LPVOID)0x0)) {
    DAT_00431904 = 1;
  }
  return;
}


// ==== FUN_0040e58e @ 0040e58e

undefined4 * __fastcall FUN_0040e58e(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040e687;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  local_8 = 1;
  _eh_vector_constructor_iterator_(param_1 + 0xd,0x50,5,FUN_004122f0,FUN_00411f90);
  param_1[1] = 0;
  *param_1 = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040e6a0 @ 0040e6a0

void FUN_0040e6a0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488;
  if (((byte)*(undefined4 *)(iVar1 + DAT_004302c0 * 4) & 7) != 2) {
    iVar2 = FUN_0040c812();
    if ((iVar2 < DAT_004302c0) && ((*(byte *)(iVar1 + -4 + DAT_004302c0 * 4) & 1) != 0)) {
      FUN_0040e77e(&DAT_004302b8,-1);
      FUN_004096c8(DAT_00431704);
    }
    else {
      uVar3 = FUN_0040c880();
      if ((DAT_004302c0 < (int)uVar3) && ((*(byte *)(iVar1 + 4 + DAT_004302c0 * 4) & 4) != 0)) {
        FUN_0040e77e(&DAT_004302b8,1);
        FUN_004096c8(DAT_00431704);
      }
    }
  }
  return;
}


// ==== FUN_0040e77e @ 0040e77e

void __thiscall FUN_0040e77e(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + param_1;
  FUN_0041a0b9((void *)((int)this + 0x14),0,0,-0x8000,-0x8000);
  iVar1 = *(int *)((int)this + 8) * 0x10 + DAT_00428070;
  iVar2 = DAT_00428074 + -8;
  FUN_00419da8((void *)((int)this + 0x14),iVar1,iVar2,iVar1 + 8,DAT_00428074,0);
  FUN_00412d55(&DAT_00431ac8,iVar1,iVar2,0x30,0,9,9,DAT_00430af4,0);
  return;
}


// ==== FUN_0040e84e @ 0040e84e

void __fastcall FUN_0040e84e(int param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined4 *)(local_8 * 0x50 + 0x5c + param_1) =
         *(undefined4 *)(&DAT_00427d30 + DAT_004318ec * 0x2c);
    *(undefined4 *)(local_8 * 0x50 + 0x60 + param_1) =
         *(undefined4 *)(&DAT_00427d34 + DAT_004318ec * 0x2c);
  }
  return;
}


// ==== FUN_0040e8e2 @ 0040e8e2

void __thiscall FUN_0040e8e2(void *this,HWND param_1)

{
  FUN_0041a0b9((void *)((int)this + *(int *)((int)this + 0x1c4) * 0x50 + 0x74),0,0,-0x8000,-0x8000);
  if (*(int *)((int)this + 0x1c4) < 4) {
    *(int *)((int)this + 0x1c4) = *(int *)((int)this + 0x1c4) + 1;
  }
  else {
    *(undefined4 *)((int)this + 0x1c4) = 0;
  }
  FUN_0041890e((void *)(*(int *)((int)this + 0x1c4) * 0x50 + 0x34 + (int)this),1);
  FUN_004096c8(param_1);
  return;
}


// ==== FUN_0040e984 @ 0040e984

undefined4 __thiscall FUN_0040e984(void *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)((int)this + 4) == 0) && (3 < DAT_004318e4)) {
    if (DAT_004280b4 == 0) {
      DAT_004280b4 = 0;
      if ((param_1 == 0) && (iVar2 = FUN_00406245(8), iVar2 != 0)) {
        return 0;
      }
      FUN_004030a3(9);
      *(undefined4 *)((int)this + 4) = 1;
      *(undefined4 *)((int)this + 0x1c4) = 0;
      *(undefined4 *)((int)this + 0x1c8) = 0xffffffff;
      *(undefined4 *)((int)this + 0x10) = 2;
      uVar3 = FUN_0040c880();
      iVar2 = FUN_0040c812();
      iVar4 = FUN_0040c812();
      iVar5 = FUN_00406245((uVar3 - iVar2) + 1);
      *(int *)((int)this + 8) = iVar4 + iVar5;
      iVar4 = *(int *)((int)this + 8) * 0x10 + DAT_00428070;
      iVar5 = DAT_00428074 + -8;
      FUN_00419da8((void *)((int)this + 0x14),iVar4,iVar5,iVar4 + 8,DAT_00428074,0);
      FUN_00412d55(&DAT_00431ac8,iVar4,iVar5,0x30,0,9,9,DAT_00430af4,0);
      iVar4 = FUN_0040c812();
      iVar2 = FUN_00406245((uVar3 - iVar2) + 1);
      *(int *)((int)this + 0xc) = iVar4 + iVar2;
      iVar2 = *(int *)((int)this + 0xc) * 0x10 + DAT_00428070;
      iVar4 = (uint)DAT_00428068 * 0x18 + DAT_00428074;
      iVar5 = iVar4 + -1;
      FUN_00419da8((void *)((int)this + 0x24),iVar2,iVar5,iVar2 + 8,iVar4 + 7,0);
      FUN_00412d55(&DAT_00431ac8,iVar2,iVar5,0x30,0,9,9,DAT_00430af4,0);
      *(undefined4 *)this = 0;
      uVar1 = 1;
    }
    else {
      DAT_004280b4 = 0;
      uVar1 = 0;
    }
  }
  else {
    DAT_004280b4 = 1;
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040ebb3 @ 0040ebb3

bool __cdecl FUN_0040ebb3(uint param_1,uint param_2)

{
  int iVar1;
  byte local_10;
  byte local_c;
  
  local_c = 0;
  do {
    if (DAT_00428068 <= local_c) {
      return param_2 == param_1;
    }
    iVar1 = FUN_00407723((uint)local_c);
    if (local_c != DAT_00428068) {
      for (local_10 = 0; local_10 < DAT_00428064; local_10 = local_10 + 1) {
        if (local_10 == param_1) {
          switch(*(uint *)(iVar1 + (uint)local_10 * 4) & 7) {
          case 0:
            break;
          case 1:
          case 3:
            param_1 = param_1 + 1;
            break;
          case 2:
            break;
          case 4:
          case 6:
            param_1 = param_1 - 1;
          }
          break;
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// ==== FUN_0040eccd @ 0040eccd

undefined4 __fastcall FUN_0040eccd(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 4) != 0) {
    for (local_8 = 0; local_8 <= (int)(uint)DAT_00428068; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < (int)(uint)DAT_00428064; local_c = local_c + 1) {
        *(undefined4 *)(&DAT_00430bcc + local_c * 0x10 + local_8 * 0xc0) = 0xff;
        *(undefined4 *)(&DAT_00430bc8 + local_c * 0x10 + local_8 * 0xc0) =
             *(undefined4 *)(&DAT_00430bcc + local_c * 0x10 + local_8 * 0xc0);
        *(undefined4 *)(&DAT_00430bc4 + local_c * 0x10 + local_8 * 0xc0) =
             *(undefined4 *)(&DAT_00430bc8 + local_c * 0x10 + local_8 * 0xc0);
        *(undefined4 *)(&DAT_00430bc0 + local_c * 0x10 + local_8 * 0xc0) =
             *(undefined4 *)(&DAT_00430bc4 + local_c * 0x10 + local_8 * 0xc0);
      }
    }
    iVar2 = FUN_00408c77(*(int *)(param_1 + 8),*(int *)(param_1 + 0xc));
    if ((iVar2 != 0) &&
       (bVar1 = FUN_0040ebb3(*(uint *)(param_1 + 8),*(uint *)(param_1 + 0xc)),
       CONCAT31(extraout_var,bVar1) != 0)) {
      FUN_004030a3(0xd);
      FUN_0041a0b9((void *)(param_1 + 0x14),0,0,-0x8000,-0x8000);
      FUN_0041a0b9((void *)(param_1 + 0x24),0,0,-0x8000,-0x8000);
      *(undefined4 *)(param_1 + 4) = 0;
      FUN_0041a0b9((void *)(*(int *)(param_1 + 0x1c4) * 0x50 + param_1 + 0x74),0,0,-0x8000,-0x8000);
      FUN_0040892f(*(int *)(param_1 + 8),9,1);
      FUN_00407bbf();
      return 1;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      FUN_0041a0b9((void *)(param_1 + 0x14),0,0,-0x8000,-0x8000);
      FUN_0041a0b9((void *)(param_1 + 0x24),0,0,-0x8000,-0x8000);
      *(undefined4 *)(param_1 + 4) = 0;
      FUN_0041a0b9((void *)(*(int *)(param_1 + 0x1c4) * 0x50 + param_1 + 0x74),0,0,-0x8000,-0x8000);
    }
    else {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
  }
  return 0;
}


// ==== FUN_0040ef41 @ 0040ef41

void FUN_0040ef41(void)

{
  DAT_004273b0 = DAT_004318e8;
  FUN_004029e2();
  return;
}


// ==== FUN_0040ef60 @ 0040ef60

void FUN_0040ef60(void)

{
  FUN_00402578();
  DAT_004318e8 = DAT_004273b0;
  return;
}


// ==== FUN_0040ef7f @ 0040ef7f

bool FUN_0040ef7f(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_004318e8;
  iVar2 = DAT_0042750c;
  DAT_004273b0 = DAT_004318e8;
  FUN_00403d67();
  DAT_004318e8 = DAT_004273b0;
  FUN_0040ef41();
  if (DAT_0042750c == 0) {
    FUN_00402da5(0);
  }
  else if ((iVar2 == 0) && (DAT_00427a78 == 0)) {
    iVar2 = FUN_00406245(3);
    FUN_00402da5(iVar2 + 1);
  }
  return DAT_004318e8 != iVar1;
}


// ==== FUN_0040f027 @ 0040f027

void FUN_0040f027(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_00427a78 == 0) && (DAT_00427a7c == 0)) && (DAT_004318d0 != 1)) {
    SetMenu(DAT_00431704,DAT_00430780);
    if (DAT_004273bc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00431704);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00431704);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00431704);
  }
  else {
    SetMenu(DAT_00431704,DAT_00431ac0);
    if (DAT_004273bc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00431704);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00431704);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00431704);
  }
  return;
}


// ==== FUN_0040f12b @ 0040f12b

void __cdecl FUN_0040f12b(HDC param_1,int *param_2,BITMAPINFO *param_3,int param_4,int param_5)

{
  uint DestWidth;
  int DestHeight;
  int iVar1;
  uint uVar2;
  DWORD local_34;
  int local_30;
  DWORD local_2c;
  char *local_28;
  BYTE *local_18;
  
  if ((param_2 != (int *)0x0) && (param_3 != (BITMAPINFO *)0x0)) {
    if ((param_3->bmiHeader).biCompression == 3) {
      local_18 = (BYTE *)((int)(param_3->bmiColors + -7) + (param_3->bmiHeader).biSize);
    }
    else {
      if (((param_3->bmiHeader).biClrUsed == 0) && ((param_3->bmiHeader).biBitCount < 9)) {
        local_2c = 1 << ((byte)(param_3->bmiHeader).biBitCount & 0x1f);
      }
      else {
        local_2c = (param_3->bmiHeader).biClrUsed;
      }
      local_18 = &param_3->bmiColors[local_2c - 10].rgbBlue + (param_3->bmiHeader).biSize;
    }
    uVar2 = ((uint)(param_3->bmiHeader).biBitCount * (param_3->bmiHeader).biWidth + 0x1f &
            0xffffffe0) >> 3;
    DestWidth = (param_3->bmiHeader).biWidth;
    DestHeight = (param_3->bmiHeader).biHeight;
    FUN_0041bba0((char *)local_18,DAT_00431ad0,DestWidth,DestHeight,uVar2,
                 ((uint)DAT_00431af6 * DAT_00431aec + 0x1f & 0xffffffe0) >> 3,0xff);
    if (param_2[4] == 3) {
      iVar1 = *param_2 + 0xc;
    }
    else {
      if ((param_2[8] == 0) && (*(ushort *)((int)param_2 + 0xe) < 9)) {
        local_30 = 1 << (*(byte *)((int)param_2 + 0xe) & 0x1f);
      }
      else {
        local_30 = param_2[8];
      }
      iVar1 = local_30 * 4 + *param_2;
    }
    local_28 = (char *)((int)param_2 + iVar1);
    FUN_0041bba0((char *)(local_18 + (DestHeight - (param_5 + param_2[2])) * uVar2 + param_4),
                 local_28,param_2[1],param_2[2],uVar2,
                 ((uint)*(ushort *)((int)param_2 + 0xe) * param_2[1] + 0x1f & 0xffffffe0) >> 3,0);
    if ((param_3->bmiHeader).biCompression == 3) {
      local_18 = (BYTE *)((int)(param_3->bmiColors + -7) + (param_3->bmiHeader).biSize);
    }
    else {
      if (((param_3->bmiHeader).biClrUsed == 0) && ((param_3->bmiHeader).biBitCount < 9)) {
        local_34 = 1 << ((byte)(param_3->bmiHeader).biBitCount & 0x1f);
      }
      else {
        local_34 = (param_3->bmiHeader).biClrUsed;
      }
      local_18 = &param_3->bmiColors[local_34 - 10].rgbBlue + (param_3->bmiHeader).biSize;
    }
    StretchDIBits(param_1,0,0,DestWidth,DestHeight,0,0,DestWidth,DestHeight,local_18,param_3,0,
                  0xcc0020);
  }
  return;
}


// ==== FUN_0040f3c8 @ 0040f3c8

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_0040f3c8(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  INT_PTR IVar4;
  int iVar5;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  BOOL BVar6;
  UINT UVar7;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  int *local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  undefined4 local_184;
  HGDIOBJ local_180;
  HDC local_17c;
  int local_178;
  int local_174;
  undefined4 local_170;
  HGDIOBJ local_16c;
  HDC local_168;
  int local_164;
  int local_160;
  undefined4 local_15c;
  HGDIOBJ local_158;
  HDC local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c [17];
  undefined2 local_e8;
  undefined2 uStack_e6;
  int local_dc;
  HDC local_d8;
  tagPAINTSTRUCT local_d4;
  int local_94;
  char local_90 [100];
  HDC local_2c;
  UINT local_28;
  int local_24;
  int local_20;
  int local_1c [6];
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_d8 = BeginPaint(param_1,&local_d4);
      SelectPalette(local_d8,DAT_00431ae4,0);
      RealizePalette(local_d8);
      if (DAT_004318d0 != 3) {
        if ((((DAT_00427a78 != 0) || ((DAT_00427a98 != 0 && (DAT_004318d0 != 1)))) ||
            ((DAT_00430b00 == (HWND)0x0 && (DAT_004318d0 != 1)))) ||
           ((DAT_00427a90 != 0 && (DAT_004318d0 != 1)))) {
          FUN_0040f12b(local_d8,DAT_00430b84,DAT_00430af0,DAT_00428070 + -0x1c,DAT_00428074 + -8);
          EndPaint(param_1,&local_d4);
          return 0;
        }
        if (DAT_00427a7c != 0) {
          FUN_0040f12b(local_d8,DAT_00430b78,DAT_00430af0,DAT_00428070 + -0x1c,DAT_00428074 + -8);
          EndPaint(param_1,&local_d4);
          return 0;
        }
      }
      if ((DAT_004318d0 != 1) && (DAT_004318d0 != 3)) {
        DAT_00432054 = 0;
        local_15c = DAT_00431ac8;
        local_160 = DAT_00431ad8;
        local_164 = DAT_00431ad4;
        local_154 = CreateCompatibleDC(local_d8);
        local_158 = SelectObject(local_154,DAT_00432078);
        BitBlt(local_d8,0,0,local_164,local_160,local_154,0,0,0xcc0020);
        SelectObject(local_154,local_158);
        DeleteDC(local_154);
        GdiFlush();
        iVar5 = FUN_0040818a(DAT_00430b20,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
        if (iVar5 != 0) {
          FUN_004094d9(local_d8,DAT_00428058,DAT_0042805c);
        }
        if ((DAT_004318d0 == 2) && ((DAT_00430a68 == 1 || (DAT_00430a68 == 3)))) {
          FUN_004082e8(&DAT_00430a68,local_d8,DAT_00430484 - DAT_00431700);
          local_188 = (DAT_00428074 + DAT_00430484) - DAT_00431700;
          local_18c = DAT_00430a70 + DAT_00428070 + -4;
          local_190 = ((uint)DAT_00428064 * 0x10 - DAT_00430a70) - _DAT_00430a74;
          local_194 = DAT_00430a70 + DAT_00428070;
          local_184 = DAT_00431ac8;
          local_17c = CreateCompatibleDC(local_d8);
          local_180 = SelectObject(local_17c,DAT_00432078);
          BitBlt(local_d8,local_18c,local_188,local_190,5,local_17c,local_194,9,0xcc0020);
          SelectObject(local_17c,local_180);
          DeleteDC(local_17c);
          GdiFlush();
        }
        EndPaint(param_1,&local_d4);
        return 0;
      }
      DAT_00432054 = 0;
      local_170 = DAT_00431ac8;
      local_174 = DAT_00431ad8;
      local_178 = DAT_00431ad4;
      local_168 = CreateCompatibleDC(local_d8);
      local_16c = SelectObject(local_168,DAT_00432078);
      BitBlt(local_d8,0,0,local_178,local_174,local_168,0,0,0xcc0020);
      SelectObject(local_168,local_16c);
      DeleteDC(local_168);
      GdiFlush();
      EndPaint(param_1,&local_d4);
      return 0;
    }
    switch(param_2) {
    case 1:
      FUN_004036bb(param_1);
      return 0;
    case 2:
      WinHelpA(DAT_00431704,s_FRINGER_HLP_00427770,2,0);
      if (DAT_004318e0 != (HGLOBAL)0x0) {
        GlobalFree(DAT_004318e0);
      }
      FUN_004036fe(param_1);
      PostQuitMessage(0);
      return 0;
    case 5:
      if (param_3 != (HWND)0x0) {
        if (param_3 == (HWND)0x1) {
          PostMessageA(param_1,0x464,0,param_4);
          return 0;
        }
        if (param_3 != (HWND)0x2) {
          return 0;
        }
      }
      PostMessageA(param_1,0x464,1,param_4);
      return 0;
    case 7:
      if (DAT_00427cc0 != 0) {
        SetActiveWindow(DAT_00430a94);
        return 0;
      }
      UVar7 = FUN_0041dbd0(param_1,param_2,(WPARAM)param_3,param_4);
      return UVar7;
    }
switchD_00411424_caseD_3:
    UVar7 = FUN_0041dbd0(param_1,param_2,(WPARAM)param_3,param_4);
    return UVar7;
  }
  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_00427a74 = 1;
      DAT_00430b00 = param_3;
      if (param_3 == (HWND)0x0) {
        FUN_0040ef41();
        if (DAT_004318d0 != 1) {
          DAT_00427a78 = 1;
        }
        FUN_0040f027();
      }
      else {
        FUN_0040ef60();
      }
      PostMessageA(param_1,0x464,(WPARAM)param_3,param_4);
      if ((param_3 == (HWND)0x0) || (DAT_00427a78 != 0)) {
        FUN_00402da5(0);
      }
      else {
        FUN_00402da5(DAT_00427cb8 + 1);
      }
      DAT_00427a98 = 0;
      InvalidateRect(DAT_00431704,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x10) {
      if ((DAT_00427a7c == 0) && (DAT_004318d0 != 1)) {
        IVar4 = FUN_00403a63();
        if (IVar4 != 1) {
          return 0;
        }
        DAT_004273a8 = DAT_004318dc;
        iVar5 = FUN_00402801(DAT_004318dc,local_1c);
        if ((iVar5 != 0) && (local_1c[0] < 10)) {
          if (DAT_004273c4 != 0) {
            FUN_00403c89();
          }
          FUN_0040289e(DAT_004318dc);
          DAT_00427cb0 = local_1c[0];
          FUN_00403cf8();
          FUN_0040ef41();
        }
      }
      local_20 = DAT_004318d0;
      DAT_004318d0 = 4;
      FUN_004062b4();
      FUN_004062b4();
      DAT_004318d0 = 3;
      if (DAT_004318e0 != (HGLOBAL)0x0) {
        GlobalFree(DAT_004318e0);
      }
      DAT_004318e0 = FUN_0040217c(s_TITLEBMP_0042835c);
      if (DAT_004318e0 != (int *)0x0) {
        local_198 = DAT_004318e0;
        FUN_00412d55(&DAT_00431ac8,0,0,0,0,600,400,DAT_004318e0,-1);
        FUN_004096c8(param_1);
      }
      FUN_00406281();
      SetTimer(DAT_00431704,10,300,(TIMERPROC)0x0);
      return 0;
    }
    goto switchD_00411424_caseD_3;
  }
  if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      GdiFlush();
      Sleep(200);
      if (DAT_0042738c != (HGDIOBJ)0x0) {
        DeleteObject(DAT_0042738c);
        DAT_0042738c = (HGDIOBJ)0x0;
      }
      local_2c = GetDC((HWND)0x0);
      Sleep(100);
      ReleaseDC((HWND)0x0,local_2c);
      GdiFlush();
      Sleep(200);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00430b08;
      *(undefined4 *)(param_4 + 0xc) = DAT_00430b1c;
      return 0;
    }
    goto switchD_00411424_caseD_3;
  }
  if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_0042bfb8,6);
        return 0;
      }
      if (DAT_004318d0 == 0) {
        return 0;
      }
      if (DAT_00430b7c != 0) {
        SendMessageA(DAT_00431704,0x111,0x65,0);
        return 0;
      }
      if (DAT_004318d0 == 1) {
        SendMessageA(DAT_00431704,0x111,0x65,0);
        return 0;
      }
      if (DAT_00427a78 != 0) {
        SendMessageA(DAT_00431704,0x111,0xc9,0);
        return 0;
      }
      if (param_3 != (HWND)0xd) {
        if (DAT_004318d0 != 4) {
          DAT_00432054 = 0;
          switch(param_3) {
          case (HWND)0x20:
          case (HWND)0x26:
            if (DAT_00427a74 != 0) {
              DAT_00427a74 = 0;
              FUN_0040ccff(&DAT_00430b20);
              FUN_004096c8(param_1);
              _sprintf(local_90,&DAT_00428354,DAT_004318dc);
              if (DAT_00431aa0 != (void *)0x0) {
                FUN_0041a0b9(&DAT_00431aac,0,0,-0x8000,-0x8000);
                FUN_0041ba43(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_90,&local_1a8);
                FUN_00419da8(&DAT_00431aac,local_1a8,local_1a4,local_1a0,local_19c,0);
                FUN_0041aeb1(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_90,0);
              }
              FUN_004096c8(param_1);
              if (-1 < DAT_00428058) {
                FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
              }
            }
            break;
          case (HWND)0x25:
          case (HWND)0x27:
            iVar5 = FUN_0040c9b2(&DAT_00430b20,(int)param_3);
            if ((iVar5 != 0) && (FUN_004096c8(param_1), -1 < DAT_00428058)) {
              FUN_004080e5(DAT_00428058,DAT_0042805c,(HWND)0x0);
            }
            break;
          case (HWND)0x28:
            SendMessageA(DAT_0042bfb8,0x111,0x22b,0);
          }
          return 0;
        }
        return 0;
      }
      iVar5 = FUN_0040dce3(&DAT_00431768);
      if (iVar5 == 0) {
        return 0;
      }
      FUN_004096c8(param_1);
      if (DAT_004318d0 == 1) {
        return 0;
      }
      PostMessageA(param_1,0x42b,0,0);
      PostMessageA(param_1,0x100,0x25,0);
      PostMessageA(param_1,0x100,0x27,0);
      iVar5 = FUN_00409bec();
      if (2 < iVar5) {
        return 0;
      }
      PostMessageA(param_1,0x100,0x20,0);
      PostMessageA(param_1,0x101,0x20,0);
      return 0;
    }
    if (param_2 == 0x86) {
      if (param_3 != (HWND)0x0) {
        InvalidateRect(DAT_0042bfb8,(RECT *)0x0,0);
      }
      UVar7 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
      return UVar7;
    }
    goto switchD_00411424_caseD_3;
  }
  if (0x111 < param_2) {
    if (param_2 < 0x202) {
      if (param_2 == 0x201) {
        if (DAT_004318d0 == 0) {
          return 0;
        }
        if (DAT_00430b7c != 0) {
          PostMessageA(DAT_00431704,0x111,0x65,0);
          return 0;
        }
        if (DAT_004318d0 == 1) {
          SendMessageA(DAT_00431704,0x111,0x65,0);
          return 0;
        }
        if (DAT_00427a78 == 0) {
          return 0;
        }
        SendMessageA(DAT_00431704,0x111,0xc9,0);
        return 0;
      }
      if (param_2 == 0x113) {
        if (param_3 == (HWND)0x1) {
          if ((DAT_00427a78 == 0) && (DAT_00430b00 != (HWND)0x0)) {
            FUN_00402f85();
          }
          if (((DAT_004273bc != 0) && (DAT_004302bc != 0)) && (1 < DAT_0043047c)) {
            FUN_004038bd(4);
          }
          if (((DAT_004273bc != 0) && (DAT_00431768 != 0)) && (1 < DAT_004318ac)) {
            FUN_004038bd(3);
          }
          if ((DAT_004273bc != 0) && (DAT_00431a9c != 0)) {
            DAT_00427a74 = 1;
            FUN_004038bd(1);
            DAT_00431a9c = 0;
          }
          return 0;
        }
        if (param_3 != (HWND)0xa) {
          return 0;
        }
        KillTimer(param_1,10);
        FUN_0041db88();
        DestroyWindow(param_1);
        return 0;
      }
    }
    else if (param_2 < 0x301) {
      if (param_2 == 0x300) {
        DAT_004318dc = DAT_004318dc + DAT_00431958 * 0x1e;
        _sprintf(local_90,&DAT_00428368,DAT_004318dc);
        if (DAT_00431aa0 != (void *)0x0) {
          FUN_0041a0b9(&DAT_00431aac,0,0,-0x8000,-0x8000);
          FUN_0041ba43(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_90,&local_1b8);
          FUN_00419da8(&DAT_00431aac,local_1b8,local_1b4,local_1b0,local_1ac,0);
          FUN_0041aeb1(DAT_00431aa0,DAT_00431aa4,DAT_00431aa8,(int)local_90,0);
        }
        FUN_004096c8(param_1);
        DAT_00427a7c = 1;
        FUN_0040f027();
        InvalidateRect(DAT_00431704,(RECT *)0x0,0);
        DAT_004273a8 = DAT_004318dc;
        iVar5 = FUN_00402801(DAT_004318dc,local_1c);
        if ((iVar5 != 0) && (local_1c[0] < 10)) {
          FUN_004030a3(2);
          if (DAT_004273c4 != 0) {
            FUN_00403c89();
          }
          FUN_0040289e(DAT_004318dc);
          DAT_00427cb0 = local_1c[0];
          FUN_00403cf8();
          FUN_0040ef41();
          return 0;
        }
        FUN_004030a3(3);
        return 0;
      }
      if (param_2 == 0x211) {
        DAT_00427a98 = 1;
        InvalidateRect(param_1,(RECT *)0x0,1);
        return 0;
      }
      if (param_2 == 0x212) {
        DAT_00427a98 = 0;
        InvalidateRect(param_1,(RECT *)0x0,1);
        return 0;
      }
    }
    else {
      if (param_2 < 0x42c) {
        if (param_2 == 0x42b) {
          if (DAT_00430b00 == (HWND)0x0) {
            return 0;
          }
          if (DAT_00427a78 != 0) {
            return 0;
          }
          if (((DAT_00427a90 != 0) || (DAT_00427a94 != 0)) || (DAT_00427a98 != 0)) {
            return 0;
          }
          if (DAT_004318d0 == 1) {
            return 0;
          }
          if (DAT_004318d0 != 3) {
            if (DAT_004318d8 != 0) {
              DAT_004318d8 = 0;
            }
            if (DAT_004318d0 == 0) {
              return 0;
            }
            if (((0 < DAT_00427a84) && (DAT_00427a84 = DAT_00427a84 + -1, DAT_00427a84 == 1)) &&
               ((iVar5 = FUN_0040ae8e(), iVar5 == 0 && (DAT_00427a84 = 0, DAT_004273bc != 0)))) {
              FUN_004038bd(2);
            }
            if (DAT_004318d0 != 1) {
              DAT_00431954 = DAT_00431954 + -1;
              if (DAT_00431954 < 1) {
                DAT_00431954 = 0x14;
                FUN_0040d3a7(&DAT_00431900,param_1);
              }
              if (((DAT_004318b8 != 0) && (DAT_00430a68 != 1)) &&
                 ((DAT_00430a68 != 3 && (iVar5 = FUN_0040dda2(0x431768), iVar5 != 0)))) {
                FUN_004096c8(param_1);
              }
              if ((DAT_004302bc != 0) && (DAT_00430480 = DAT_00430480 + -1, DAT_00430480 < 1)) {
                DAT_00432054 = 0;
                FUN_0040e8e2(&DAT_004302b8,param_1);
                DAT_00430480 = 10;
              }
              if ((DAT_00431768 != 0) && (DAT_004318b0 = DAT_004318b0 + -1, DAT_004318b0 < 1)) {
                DAT_00432054 = 0;
                FUN_0040daea(0x431768);
                DAT_004318b0 = 0x14;
                FUN_004096c8(param_1);
              }
              if (DAT_004318d0 == 2) {
                DAT_00430a6c = DAT_00430a6c + -1;
                if (DAT_00430a68 == 0) {
                  FUN_0040c417(&DAT_00430a68,param_1);
                  bVar2 = FUN_00408775(DAT_00428068 - 3);
                  if (CONCAT31(extraout_var_00,bVar2) == 0) {
                    FUN_004030a3(0xc);
                  }
                  if (DAT_00427a80 != 0) {
                    DAT_00427a80 = 0;
                    bVar2 = FUN_00408775(DAT_00428068 - 2);
                    if (CONCAT31(extraout_var_01,bVar2) == 0) {
                      DAT_004318d0 = 1;
                      PostMessageA(param_1,0x300,0,0);
                    }
                  }
                  return 0;
                }
                if ((DAT_00430a68 == 2) && (iVar5 = FUN_0040ba7e(&DAT_00430a68), iVar5 == 0)) {
                  return 0;
                }
                local_dc = DAT_00430b18;
                if (DAT_00430a6c < 1) {
                  FUN_0040b1a0(&DAT_00430a68,param_1);
                }
                local_24 = DAT_00430b18;
                if (DAT_00430b18 != local_dc) {
                  FUN_0040d4ff();
                }
                return 0;
              }
            }
            return 0;
          }
          return 0;
        }
        if (param_2 != 0x30f) {
          if (param_2 != 0x311) goto switchD_00411424_caseD_3;
          if (param_3 == param_1) {
            return 0;
          }
        }
        local_d8 = GetDC(param_1);
        if (DAT_00431ae4 != (HPALETTE)0x0) {
          SelectPalette(local_d8,DAT_00431ae4,0);
          local_28 = RealizePalette(local_d8);
        }
        ReleaseDC(param_1,local_d8);
        if (local_28 != 0) {
          InvalidateRect(param_1,(RECT *)0x0,1);
          return local_28;
        }
        return 0;
      }
      if (param_2 == 0x464) {
        if (param_3 == (HWND)0x0) {
          FUN_00406281();
        }
        else if (DAT_00427cb4 == 0) {
          BVar6 = IsIconic(param_1);
          if (BVar6 == 0) {
            FUN_00406281();
          }
          else {
            FUN_00406281();
          }
          if (DAT_00427cc0 != 0) {
            SetActiveWindow(DAT_00430a94);
          }
        }
        else {
          DAT_00427cb4 = 0;
          FUN_00406281();
        }
        FUN_0041e0ab((int)DAT_00430b00);
        return 0;
      }
    }
    goto switchD_00411424_caseD_3;
  }
  if (param_2 != 0x111) {
    if (param_2 == 0x101) {
      if (DAT_004318d0 == 0) {
        return 0;
      }
      if ((param_3 != (HWND)0x20) && (param_3 != (HWND)0x26)) {
        return 0;
      }
      DAT_00427a74 = 1;
      return 0;
    }
    goto switchD_00411424_caseD_3;
  }
  if (DAT_004318d0 == 0) {
    return 0;
  }
  if (DAT_004318d0 == 3) {
    return 0;
  }
  _local_e8 = CONCAT22(uStack_e6,(short)param_3);
  uVar3 = (uint)param_3 & 0xffff;
  if (uVar3 < 0xca) {
    if (uVar3 == 0xc9) {
      if ((DAT_004318d0 != 1) && (DAT_00427a7c == 0)) {
        DAT_00427a78 = (uint)(DAT_00427a78 == 0);
        FUN_0040f027();
        if (DAT_00427a78 == 0) {
          FUN_00402cc8(DAT_00427cb8 + 1);
        }
        else {
          InvalidateRect(DAT_00431704,(RECT *)0x0,0);
          UpdateWindow(DAT_00431704);
          FUN_00402c55();
        }
        InvalidateRect(DAT_00431704,(RECT *)0x0,0);
        return 0;
      }
      SendMessageA(DAT_00431704,0x111,0x65,0);
      return 0;
    }
    switch(uVar3) {
    case 0x65:
      if ((DAT_004318d0 != 1) && (DAT_00427a7c == 0)) {
        IVar4 = FUN_00403adb();
        if (IVar4 != 1) {
          return 0;
        }
        DAT_004273a8 = DAT_004318dc;
        iVar5 = FUN_00402801(DAT_004318dc,local_1c);
        if ((iVar5 != 0) && (local_1c[0] < 10)) {
          FUN_004030a3(2);
          if (DAT_004273c4 != 0) {
            FUN_00403c89();
          }
          FUN_0040289e(DAT_004318dc);
          DAT_00427cb0 = local_1c[0];
          FUN_00403cf8();
          FUN_0040ef41();
        }
      }
      DAT_00427a80 = 0;
      DAT_00427a84 = 0;
      DAT_00427a7c = 0;
      DAT_00427a78 = 0;
      DAT_004318e4 = DAT_004318e8 * 3 + -3;
      DAT_00431958 = 0;
      DAT_004318dc = 0;
      DAT_00431768 = 0;
      DAT_004318b4 = 0;
      DAT_004318ec = 0x309;
      DAT_00427a88 = 0;
      _DAT_0042808c = 0;
      _memset(&DAT_00430b98,0,0x18);
    case 100:
      DAT_00427a74 = 1;
      if (DAT_004318e4 < 0x1b) {
        DAT_00427a8c = DAT_004318e4 * 2 + 2;
      }
      else {
        DAT_00427a8c = DAT_00427a8c + 1;
      }
      DAT_00427a80 = 0;
      DAT_00427a84 = 0;
      DAT_00430b7c = 0;
      FUN_00409d4c(0x4318d0);
      DAT_00428084 = 0xc;
      if (DAT_004318f0 == 0) {
        DAT_00431768 = 0;
        DAT_004318b4 = 0;
      }
      FUN_0040a9f6(&DAT_004318d0);
      FUN_0040f027();
      DAT_00430b18 = (uint)DAT_00428068;
      DAT_00431700 = DAT_004302a4;
      DAT_004302a0 = 0;
      DAT_00430a60 = (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488;
      DAT_00430484 = DAT_004302a4;
      _DAT_00430a78 = 0x18;
      local_12c[4] = 0;
      FUN_0040622a();
      for (local_94 = 0;
          (uint)DAT_00428064 * (uint)DAT_00428068 - local_94 != 0 &&
          local_94 <= (int)((uint)DAT_00428064 * (uint)DAT_00428068); local_94 = local_94 + 1) {
        *(undefined4 *)(DAT_00430488 + local_94 * 4) = 2;
      }
      local_14c = FUN_00406245(2);
      local_14c = local_14c << 2;
      local_12c[0] = 0;
      local_12c[1] = 1;
      local_12c[2] = 2;
      local_12c[3] = 3;
      local_12c[4] = 4;
      for (local_94 = 0; local_94 < 0xc; local_94 = local_94 + 1) {
        local_12c[local_94 + 5] = local_94;
      }
      for (local_94 = 0; local_94 < 1000; local_94 = local_94 + 1) {
        local_140 = FUN_00406245(0xc);
        local_144 = FUN_00406245(0xc);
        if (local_140 != local_144) {
          local_148 = local_12c[local_140 + 5];
          local_12c[local_140 + 5] = local_12c[local_144 + 5];
          local_12c[local_144 + 5] = local_148;
        }
      }
      if (DAT_004318e4 < 0x1c) {
        local_14c = DAT_004318e4 + -1;
      }
      else {
        local_14c = DAT_004318f0 + 0x18;
      }
      local_130 = (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488;
      local_13c = 0;
      local_150 = 0;
      local_134 = *(int *)(&DAT_00427ea8 + local_14c * 0x10);
      for (; local_13c < 4; local_13c = local_13c + 1) {
        for (local_94 = 0; local_94 < 0xc; local_94 = local_94 + 1) {
          if ((local_150 <= local_12c[local_94 + 5]) && (local_12c[local_94 + 5] < local_134)) {
            *(int *)(local_130 + local_94 * 4) = local_12c[local_13c];
          }
        }
        local_150 = local_150 + *(int *)(&DAT_00427ea8 + local_13c * 4 + local_14c * 0x10);
        local_134 = local_134 + *(int *)(&DAT_00427eac + local_13c * 4 + local_14c * 0x10);
      }
      if (DAT_004318e4 < 0x16) {
LAB_0040ffba:
        for (local_94 = 0; local_94 < (int)(uint)DAT_00428064; local_94 = local_94 + 1) {
          if (0x15 < DAT_004318e4) {
            if (local_94 == 4) {
              *(int *)(local_130 + 0x10) = local_12c[4];
            }
            if ((local_94 == 8) && (0x19 < DAT_004318e4)) {
              *(int *)(local_130 + 0x20) = local_12c[4];
            }
            if ((local_94 == 6) && (0x1b < DAT_004318e4)) {
              *(int *)(local_130 + 0x18) = local_12c[4];
            }
          }
          *(uint *)(local_130 + local_94 * 4) = (*(uint *)(local_130 + local_94 * 4) & 0xf) << 3;
          piVar1 = (int *)(DAT_00430488 + local_94 * 4);
          *piVar1 = *piVar1 + *(int *)(local_130 + local_94 * 4);
        }
        DAT_00428078 = 0;
        iVar5 = -((DAT_004318e4 + -1) % 3);
        local_138 = iVar5 + 8;
        if (DAT_004318e4 < 3) {
          local_138 = iVar5 + 7;
        }
        if (DAT_004318e4 < 2) {
          local_138 = local_138 + -1;
        }
        if ((0x1b < DAT_004318e4) && (local_138 = local_138 + DAT_004318e4 + -0x1b, 0xb < local_138)
           ) {
          local_138 = 0xb;
        }
        for (local_13c = 0; local_13c < local_138; local_13c = local_13c + 1) {
          FUN_004084cb();
          if (DAT_00428078 == 0) {
            DAT_00428078 = (uint)DAT_00428068;
          }
          DAT_00428078 = DAT_00428078 - 1;
          for (local_94 = 0; local_94 < (int)(uint)DAT_00428064; local_94 = local_94 + 1) {
            *(undefined4 *)(local_94 * 4 + DAT_00428064 * DAT_00428078 * 4 + DAT_00430488) =
                 *(undefined4 *)
                  (local_94 * 4 + (uint)DAT_00428064 * (uint)DAT_00428068 * 4 + DAT_00430488);
          }
        }
        FUN_004095cd();
        iVar5 = FUN_0040818a(DAT_00430b20,(uint *)&DAT_00428058,(uint *)&DAT_0042805c);
        if (iVar5 != 0) {
          FUN_0040943f(DAT_00428058,DAT_0042805c,(HWND)0x0);
        }
        FUN_0040d5a5(&DAT_00431900);
        FUN_004096c8(param_1);
        DAT_00428088 = FUN_00409c5c();
        if ((((uint)param_3 & 0xffff) == 0x65) && (DAT_004273b8 != 0)) {
          PostMessageA(DAT_00431704,0x111,0x130,0);
        }
        if (0x1b < DAT_004318e4) {
          FUN_004038bd(5);
        }
        return 0;
      }
      do {
        local_12c[4] = FUN_00406245(9);
        local_13c = 0;
        while( true ) {
          if (3 < local_13c) {
            local_12c[4] = 5;
            goto LAB_0040ffba;
          }
          if (local_12c[local_13c] == local_12c[4]) break;
          local_13c = local_13c + 1;
        }
      } while( true );
    case 0x66:
      DAT_00427cb0 = 0xffffffff;
      FUN_00403cf8();
      return 0;
    case 0x67:
      PostMessageA(DAT_00431704,0x10,0,0);
      return 0;
    case 0x68:
      bVar2 = FUN_0040ef7f();
      if (CONCAT31(extraout_var,bVar2) != 0) {
        PostMessageA(DAT_00431704,0x111,0x65,0);
      }
      return 0;
    }
    goto switchD_004102e8_default;
  }
  switch(uVar3) {
  case 0x12e:
    FUN_00403b53();
    break;
  case 0x12f:
    FUN_004062b4();
    WinHelpA(DAT_00431704,s_FRINGER_HLP_00427770,0xb,0);
    FUN_004062b4();
    break;
  case 0x130:
    FUN_00403c1a();
    break;
  case 0x131:
    DAT_004273bc = (uint)(DAT_004273bc == 0);
    FUN_0040f027();
    break;
  case 0x22b:
    FUN_0040d76f(&DAT_00431900,param_1);
  default:
switchD_004102e8_default:
  }
  return 0;
}


// ==== FUN_004115ab @ 004115ab

int __cdecl FUN_004115ab(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_004115cc @ 004115cc

int __cdecl FUN_004115cc(int param_1)

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


// ==== FUN_00411607 @ 00411607

ATOM __cdecl FUN_00411607(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_0040f3c8;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = param_1;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(5);
  local_2c.hIcon = LoadIconA(param_1,&DAT_00428370);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = PTR_s_FringerWnd_00427a70;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1;
}


// ==== FUN_00411685 @ 00411685

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00411685(void)

{
  short *psVar1;
  undefined4 uVar2;
  
  psVar1 = FUN_004022ca(s_SCORELEVBMP_00428378);
  if (psVar1 == (short *)0x0) {
    uVar2 = 0;
  }
  else {
    DAT_00430a9c = 1;
    _DAT_00430ac0 = (int)*psVar1;
    _DAT_00430ac4 = (int)psVar1[1];
    DAT_00430a98 = psVar1;
    psVar1 = FUN_004022ca(s_BONUSBMP_00428384);
    if (psVar1 == (short *)0x0) {
      uVar2 = 0;
    }
    else {
      DAT_00431714 = 1;
      _DAT_00431738 = (int)*psVar1;
      _DAT_0043173c = (int)psVar1[1];
      uVar2 = 1;
      DAT_00431710 = psVar1;
    }
  }
  return uVar2;
}


// ==== FUN_00411781 @ 00411781

undefined4 FUN_00411781(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_FringerWnd_00427a70,(LPCSTR)0x0);
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


// ==== FUN_004117fe @ 004117fe

bool __cdecl FUN_004117fe(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_00411854 @ 00411854

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_00411854(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  ATOM AVar2;
  int iVar3;
  DWORD DVar4;
  undefined3 extraout_var;
  HCURSOR hCursor;
  undefined2 extraout_var_01;
  undefined3 extraout_var_00;
  BOOL BVar5;
  tagMSG local_98;
  HCURSOR local_78;
  HDC local_74;
  undefined4 local_70;
  undefined4 local_8;
  
  local_70 = 0;
  local_8 = 0;
  DAT_004318c0 = param_1;
  iVar3 = FUN_00411781();
  if (iVar3 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_FringerGameMtx_00428390);
    DVar4 = GetLastError();
    if (DVar4 == 0xb7) {
      local_98.wParam = 0;
    }
    else {
      bVar1 = FUN_004117fe(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_98.wParam = 0;
      }
      else {
        local_74 = GetDC((HWND)0x0);
        iVar3 = GetDeviceCaps(local_74,0xc);
        if (iVar3 < 8) {
          ReleaseDC((HWND)0x0,local_74);
          local_98.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_74);
          FUN_00406281();
          hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
          local_78 = SetCursor(hCursor);
          AVar2 = FUN_00411607(param_1);
          if (CONCAT22(extraout_var_01,AVar2) == 0) {
            SetCursor(local_78);
            local_98.wParam = 0;
          }
          else {
            FUN_0040184d();
            FUN_004018e7((uint *)s_FRINGER_DLL_00427870);
            FUN_00401a95((uint *)s_FRINGER1_DLL_00427970);
            FUN_00401865((uint *)s_MSPuzzle_dat_004273f8);
            FUN_00401a95((uint *)s_FRINGER_HLP_00427770);
            FUN_0040167a();
            FUN_00401694(DAT_004318c0);
            FUN_004016d3(s_FRINGER1_DLL_00427970);
            FUN_004016d3(s_FRINGER_DLL_00427870);
            FUN_0040e0aa();
            FUN_0040ef60();
            FUN_004033d4();
            InitCommonControls();
            DAT_00430b7c = 1;
            DAT_004318e0 = FUN_0040217c(s_TITLEBMP_004283a0);
            if (DAT_004318e0 == (int *)0x0) {
              SetCursor(local_78);
              FUN_004031bd();
              local_98.wParam = 0;
            }
            else {
              FUN_0041da10(DAT_004318e0);
              iVar3 = FUN_00411c1f(param_1,param_4);
              if (iVar3 == 0) {
                FUN_0041db88();
                if (DAT_004318e0 != (int *)0x0) {
                  GlobalFree(DAT_004318e0);
                }
                FUN_004031bd();
                SetCursor(local_78);
                local_98.wParam = 0;
              }
              else {
                bVar1 = FUN_0041ae70(&DAT_00430290,(LPCSTR)0x3e9);
                if (CONCAT31(extraout_var_00,bVar1) == 0) {
                  FUN_0041db88();
                  SetCursor(local_78);
                  local_98.wParam = 0;
                }
                else {
                  _DAT_00430294 = 1;
                  DAT_00431aa0 = &DAT_00430290;
                  DAT_00430760 = &DAT_00430290;
                  DAT_0043206c = 600;
                  DAT_00430af4 = FUN_0040217c(s_Arrow0_004283ac);
                  DAT_00430b84 = FUN_0040217c(s_PAUSEBMP_004283b4);
                  DAT_00430b78 = FUN_0040217c(s_GAMEOVERBMP_004283c0);
                  DAT_00430af0 = FUN_0040217c(s_TITLEBMP_004283cc);
                  FUN_00411685();
                  SetCursor(local_78);
                  DAT_004318d0 = 1;
                  FUN_0040f027();
                  SetTimer(DAT_00431704,1,100,(TIMERPROC)0x0);
                  while( true ) {
                    while (BVar5 = PeekMessageA(&local_98,(HWND)0x0,0,0,1), BVar5 == 0) {
                      if (DAT_00430b00 == 0) {
                        WaitMessage();
                      }
                      else {
                        SendMessageA(DAT_00431704,0x42b,0,0);
                        Sleep(10);
                      }
                    }
                    if (local_98.message == 0x12) break;
                    if ((DAT_00431704 == (HWND)0x0) ||
                       (iVar3 = TranslateAcceleratorA(DAT_00431704,DAT_00430ae8,&local_98),
                       iVar3 == 0)) {
                      TranslateMessage(&local_98);
                      DispatchMessageA(&local_98);
                    }
                  }
                  FUN_004031bd();
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_98.wParam = 0;
  }
  return local_98.wParam;
}


// ==== FUN_00411c1f @ 00411c1f

undefined4 __cdecl FUN_00411c1f(undefined4 param_1,int param_2)

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
  
  DAT_00430780 = FUN_0040154e(DAT_004318c0,s_MainMenuPlayed_004283d8);
  DAT_00431ac0 = FUN_0040154e(DAT_004318c0,s_MainMenu_004283e8);
  DAT_00430ae8 = FUN_0040148b(param_1,s_ACCELERATORS_1_004283f4);
  if (DAT_00430ae8 == (HACCEL)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_004015b0(DAT_004318c0,100,local_84,0x78);
    DVar2 = GetVersion();
    local_88 = (byte)DVar2;
    if (local_88 < 4) {
      iVar3 = GetSystemMetrics(5);
      DAT_00430b08 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(6);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_00430b1c = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00430b08;
      iVar4 = DAT_00430b1c;
      pHVar8 = DAT_00431ac0;
      pHVar9 = DAT_004318c0;
      iVar5 = FUN_004115cc(DAT_00430b1c);
      iVar6 = FUN_004115ab(DAT_00430b08);
      DAT_00431704 = CreateWindowExA(0,PTR_s_FringerWnd_00427a70,local_84,0xca0000,iVar6,iVar5,iVar3
                                     ,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    else {
      iVar3 = GetSystemMetrics(7);
      DAT_00430b08 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(8);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_00430b1c = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00430b08;
      iVar4 = DAT_00430b1c;
      pHVar8 = DAT_00431ac0;
      pHVar9 = DAT_004318c0;
      iVar5 = FUN_004115cc(DAT_00430b1c);
      iVar6 = FUN_004115ab(DAT_00430b08);
      DAT_00431704 = CreateWindowExA(0x100,PTR_s_FringerWnd_00427a70,local_84,0xca0000,iVar6,iVar5,
                                     iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    DAT_0042bfb8 = DAT_00431704;
    if (DAT_00431704 == (HWND)0x0) {
      uVar1 = 0;
    }
    else {
      ShowWindow(DAT_00431704,param_2);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00411e30 @ 00411e30

void __fastcall FUN_00411e30(int *param_1)

{
  if (*param_1 != 0) {
    FUN_0041ee80((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00411ea0 @ 00411ea0

void __fastcall FUN_00411ea0(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== FUN_00411ee0 @ 00411ee0

void __fastcall FUN_00411ee0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00411f78;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  local_8 = 0xffffffff;
  FUN_00411f6f();
  FUN_00411f82();
  return;
}


// ==== FUN_00411f6f @ 00411f6f

void FUN_00411f6f(void)

{
  int unaff_EBP;
  
  FUN_00411ea0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00411f82 @ 00411f82

void FUN_00411f82(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00411f90 @ 00411f90

void __fastcall FUN_00411f90(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_004120a5;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  if (param_1[0x10] != 0) {
    FUN_0041ee80((void *)param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00412090();
  local_8 = 0xffffffff;
  FUN_0041209c();
  FUN_004120af();
  return;
}


// ==== FUN_00412090 @ 00412090

void FUN_00412090(void)

{
  int unaff_EBP;
  
  FUN_00411e30((int *)(*(int *)(unaff_EBP + -0x18) + 0x40));
  return;
}


// ==== FUN_0041209c @ 0041209c

void FUN_0041209c(void)

{
  int unaff_EBP;
  
  FUN_00411ee0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004120af @ 004120af

void FUN_004120af(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== CReObject @ 004120c0

/* Library Function - Single Match
    public: __thiscall CReObject::CReObject(void)
   
   Library: Visual Studio 1998 Debug */

CReObject * __thiscall CReObject::CReObject(CReObject *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}


// ==== FUN_00412100 @ 00412100

undefined4 * __fastcall FUN_00412100(undefined4 *param_1)

{
  param_1[3] = 0xff;
  param_1[2] = param_1[3];
  param_1[1] = param_1[2];
  *param_1 = param_1[1];
  return param_1;
}


// ==== FUN_00412150 @ 00412150

void FUN_00412150(HDC param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int y;
  int x;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = param_2[3];
  iVar2 = param_2[1];
  iVar3 = param_2[2];
  iVar4 = *param_2;
  y = param_2[1];
  x = *param_2;
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_00432078);
  BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00412220 @ 00412220

void FUN_00412220(HDC param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int y1;
  int x1;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = param_2[3];
  iVar2 = param_2[1];
  iVar3 = param_2[2];
  iVar4 = *param_2;
  y1 = param_2[1];
  x1 = *param_2;
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_00432078);
  BitBlt(param_1,param_3,param_4,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x1,y1,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_004122f0 @ 004122f0

undefined4 * __fastcall FUN_004122f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004124cd;
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
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  if (param_1[0x10] != 0) {
    FUN_0041ee80((void *)param_1[0x10]);
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


// ==== FUN_00412500 @ 00412500

void FUN_00412500(void)

{
  FUN_0041251a();
  FUN_004125bb();
  return;
}


// ==== FUN_0041251a @ 0041251a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041251a(void)

{
  DAT_00431ac8 = 0;
  _DAT_00431acc = 0;
  DAT_00431ad0 = 0;
  DAT_00431ad4 = 0;
  DAT_00431ad8 = 0;
  DAT_00431ae4 = 0;
  DAT_00431ae0 = 1;
  _DAT_00431f10 = 0;
  DAT_00432054 = 0;
  _DAT_0043205c = 64000;
  _DAT_00432058 = 1;
  DAT_0043206c = 0;
  DAT_00432070 = 0;
  return;
}


// ==== FUN_004125bb @ 004125bb

void FUN_004125bb(void)

{
  _atexit(FUN_004125d8);
  return;
}


// ==== FUN_004125d8 @ 004125d8

void FUN_004125d8(void)

{
  FUN_00412867(&DAT_00431ac8);
  return;
}


// ==== FUN_004125f2 @ 004125f2

undefined4 __thiscall FUN_004125f2(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  HDC pHVar3;
  HBITMAP pHVar4;
  HGDIOBJ pvVar5;
  void *local_8;
  
  if (*(int *)this != 0) {
    FUN_00412940(this);
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
  FUN_0041e130();
  uVar2 = FUN_0041e204((int)this + 0x48,param_1);
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
  DAT_00432078 = *(undefined4 *)((int)this + 4);
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
    FUN_004129ff(this,0,0,param_1,-1);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00412867 @ 00412867

void __fastcall FUN_00412867(int *param_1)

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


// ==== FUN_00412940 @ 00412940

void __fastcall FUN_00412940(int *param_1)

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


// ==== FUN_004129ff @ 004129ff

undefined4 __thiscall FUN_004129ff(void *this,int param_1,int param_2,int *param_3,short param_4)

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
    uVar1 = FUN_0041d5c8(&local_28,&local_68,&local_48);
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
        FUN_0041bc5c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0041bba0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_4);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_2c + local_54 + -1;
      local_78 = local_18 + local_10 + -1;
      FUN_00416313(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_00412d55 @ 00412d55

undefined4 __thiscall
FUN_00412d55(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0041d5c8(&local_28,&local_68,&local_48);
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
        FUN_0041bc5c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0041bba0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_8);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_54 + local_2c + -1;
      local_78 = local_10 + local_18 + -1;
      FUN_00416313(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_004130df @ 004130df

void __thiscall
FUN_004130df(void *this,int param_1,int param_2,int *param_3,int *param_4,short param_5)

{
  FUN_00412d55(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00413137 @ 00413137

undefined4 __thiscall
FUN_00413137(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_00412d55(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_004132a0 @ 004132a0

void __thiscall
FUN_004132a0(void *this,int param_1,int param_2,int *param_3,int *param_4,HDC param_5,short param_6)

{
  FUN_00413137(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5,param_6);
  return;
}


// ==== FUN_004132fc @ 004132fc

undefined4 __thiscall
FUN_004132fc(void *this,int param_1,int param_2,int *param_3,HDC param_4,short param_5)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_004129ff(this,param_1,param_2,param_3,param_5);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_4,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00413473 @ 00413473

undefined4 __thiscall
FUN_00413473(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6)

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
    uVar1 = FUN_0041d5c8(&local_38,&local_78,&local_58);
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
      FUN_0041bca6(local_7c,local_60,local_80,local_3c,local_20,local_44,local_40,-local_28);
      local_10 = 1;
      local_9c = local_64;
      local_98 = local_14;
      local_94 = local_3c + local_64 + -1;
      local_90 = local_20 + local_14 + -1;
      FUN_00416313(this,&local_9c);
    }
  }
  return local_10;
}


// ==== FUN_00413825 @ 00413825

undefined4 __thiscall
FUN_00413825(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6,
            HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_00413473(this,param_1,param_2,param_3,param_4,param_5,param_6);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_004139d0 @ 004139d0

undefined4 __thiscall FUN_004139d0(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0041d5c8(&local_2c,&local_60,&local_48);
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
          FUN_0041bba0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00416313(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00413c47 @ 00413c47

undefined4 __thiscall
FUN_00413c47(void *this,int param_1,int param_2,short *param_3,undefined1 param_4)

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
      uVar1 = FUN_0041d5c8(&local_2c,&local_60,&local_48);
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
        FUN_0041bed6(local_64,local_4c,local_30,local_1c,local_34,local_10,param_4);
        local_8 = 1;
        local_78 = local_50;
        local_74 = local_c;
        local_70 = local_30 + local_50 + -1;
        local_6c = local_1c + local_c + -1;
        FUN_00416313(this,&local_78);
      }
    }
  }
  return local_8;
}


// ==== FUN_00413eac @ 00413eac

undefined4 __thiscall
FUN_00413eac(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041d5c8(&local_2c,&local_60,&local_48);
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
          FUN_0041bba0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00416313(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00414157 @ 00414157

void __thiscall
FUN_00414157(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_00413eac(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004141af @ 004141af

undefined4 __thiscall
FUN_004141af(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_00413eac(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00414316 @ 00414316

void __thiscall
FUN_00414316(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_004141af(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041436e @ 0041436e

undefined4 __thiscall
FUN_0041436e(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041d5c8(&local_2c,&local_60,&local_48);
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
          FUN_0041bc5c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00416313(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00414617 @ 00414617

void __thiscall
FUN_00414617(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_0041436e(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041466f @ 0041466f

undefined4 __thiscall
FUN_0041466f(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_0041436e(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_004147d6 @ 004147d6

void __thiscall
FUN_004147d6(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_0041466f(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0041482e @ 0041482e

undefined4 __thiscall FUN_0041482e(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_004139d0(this,param_1,param_2,param_3,0);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041499c @ 0041499c

undefined4 __thiscall
FUN_0041499c(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0041d5c8(&local_3c,&local_70,&local_58);
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
          FUN_0041bca6(local_74,local_5c,local_78,local_40,local_24,local_44,local_18,local_2c);
          local_c = 1;
          local_90 = local_60;
          local_8c = local_10;
          local_88 = local_60 + local_40 + -1;
          local_84 = local_10 + local_24 + -1;
          FUN_00416313(this,&local_90);
        }
        else {
          local_c = 1;
        }
      }
    }
  }
  return local_c;
}


// ==== FUN_00414cd2 @ 00414cd2

undefined4 __thiscall
FUN_00414cd2(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_0041499c(this,param_1,param_2,param_3,param_4,param_5,param_6,0);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_00414e7f @ 00414e7f

undefined4 __thiscall FUN_00414e7f(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0041d5c8(&local_2c,&local_60,&local_48);
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
          FUN_0041bc5c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00416313(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_004150f4 @ 004150f4

undefined4 __thiscall FUN_004150f4(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00414e7f(this,param_1,param_2,param_3,0);
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
      DAT_00432054 = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_00432078);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00415262 @ 00415262

undefined4 __thiscall
FUN_00415262(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0041d5c8(&local_6c,&local_58,local_14);
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
        FUN_0041bc5c((undefined4 *)local_5c,(undefined4 *)local_40,local_30,local_2c,local_38,
                     *(int *)((int)this + 0x14));
      }
      else {
        FUN_0041bba0(local_5c,local_40,local_30,local_2c,local_38,*(int *)((int)this + 0x14),
                     (byte)param_8);
      }
      local_20 = 1;
    }
  }
  return local_20;
}


// ==== FUN_00415556 @ 00415556

undefined4 __thiscall
FUN_00415556(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0041d5c8(&local_68,&local_44,local_24);
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
        FUN_0041bc5c((undefined4 *)local_54,(undefined4 *)local_4c,local_34,local_2c,local_c,
                     local_30);
      }
      else {
        FUN_0041bba0(local_54,local_4c,local_34,local_2c,local_c,local_30,(byte)param_8);
      }
      local_10 = 1;
    }
  }
  return local_10;
}


// ==== FUN_004157b5 @ 004157b5

undefined4 __thiscall FUN_004157b5(void *this,int *param_1,undefined1 param_2)

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
      uVar3 = FUN_0041d5c8(&local_38,&local_18,&local_50);
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
        FUN_0041be7e(local_58,local_3c,local_28,local_40,param_2);
        local_8 = 1;
        local_70 = local_54;
        local_6c = local_1c;
        local_68 = local_3c + local_54 + -1;
        local_64 = local_28 + local_1c + -1;
        FUN_00416313(this,&local_70);
      }
    }
  }
  return local_8;
}


// ==== FUN_00415a93 @ 00415a93

void __thiscall
FUN_00415a93(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  puStack_c = &LAB_00415d24;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    FUN_00415d2e();
    return;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  if ((param_5 == 0) || (param_6 == 0)) {
    local_8 = 0xffffffff;
    FUN_00415d1b();
    FUN_00415d2e();
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
  uVar1 = FUN_0041d5c8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_00415d1b();
    FUN_00415d2e();
    return;
  }
  local_50 = param_1;
  local_4c = param_2;
  local_48 = (local_28 - local_30) + param_1;
  local_44 = (local_24 - local_2c) + param_2;
  uVar1 = FUN_0041d5c8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_00415d1b();
    FUN_00415d2e();
    return;
  }
  FUN_00419da8(&local_20,local_30,local_2c,local_28,local_24,1);
  if (param_7 == -1) {
    FUN_0041a0b9(&local_20,1,param_1,param_2,-0x8000);
  }
  else {
    FUN_0041a660(&local_20,(int)(char)param_7,1,param_1,param_2,-0x8000);
  }
  local_8 = 0xffffffff;
  FUN_00415d1b();
  FUN_00415d2e();
  return;
}


// ==== FUN_00415d1b @ 00415d1b

void FUN_00415d1b(void)

{
  int unaff_EBP;
  
  FUN_00411e30((int *)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_00415d2e @ 00415d2e

void FUN_00415d2e(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00415d3f @ 00415d3f

void __thiscall FUN_00415d3f(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00415a93(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_00415d93 @ 00415d93

undefined4 __thiscall
FUN_00415d93(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0041d5c8(&local_20,&local_54,&local_3c);
    if ((int)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_54 = param_1;
      local_50 = param_2;
      local_4c = (local_18 - local_20) + param_1;
      local_48 = (local_14 - local_1c) + param_2;
      uVar2 = FUN_0041d5c8(&local_20,&local_54,&local_3c);
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
          FUN_0041bc5c((undefined4 *)local_58,(undefined4 *)local_40,local_24,local_10,local_28,
                       local_28);
        }
        else {
          FUN_0041bba0(local_58,local_40,local_24,local_10,local_28,local_28,(byte)param_7);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// ==== FUN_0041604d @ 0041604d

void __thiscall FUN_0041604d(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00415d93(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_004160a1 @ 004160a1

undefined4 __thiscall FUN_004160a1(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_004139d0(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_004129ff(this,param_1,param_2,(int *)(param_3 + 8),0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00416139 @ 00416139

undefined4 __thiscall FUN_00416139(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00414e7f(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_004129ff(this,param_1,param_2,(int *)(param_3 + 8),-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_004161d4 @ 004161d4

undefined4 __thiscall FUN_004161d4(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0041482e(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_004132fc(this,param_1,param_2,(int *)(param_3 + 8),param_4,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00416272 @ 00416272

undefined4 __thiscall FUN_00416272(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_004150f4(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_004132fc(this,param_1,param_2,(int *)(param_3 + 8),param_4,-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00416313 @ 00416313

void __thiscall FUN_00416313(void *this,int *param_1)

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
        iVar1 = FUN_0041d7a2(&local_14,
                             (int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
                             (int *)((int)this + local_18 * 0x10 + 0x44c));
        if (iVar1 != 0) {
          *(int *)((int)this + local_18 * 0x10 + 0x44c) = local_14;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x450) = local_10;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x454) = local_c;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x458) = local_8;
          *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + -1;
LAB_004164c6:
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
              iVar1 = FUN_0041d7a2(&local_14,(int *)((int)this + local_1c * 0x10 + 0x44c),
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
                goto LAB_004164c6;
              }
            }
            local_18 = local_18 + 1;
          } while( true );
        }
      }
    }
    else {
      FUN_0041d74c(&local_14,(int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
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


// ==== FUN_004165df @ 004165df

void __thiscall FUN_004165df(void *this,int *param_1,int *param_2,HDC param_3)

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
  
  iVar1 = FUN_0041d6b3(param_1,param_2);
  if (iVar1 == 0) {
    FUN_0041d87b(param_1);
    FUN_0041d88b((int)param_1);
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
      DAT_00432054 = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_00432078);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
    FUN_0041d87b(param_2);
    FUN_0041d88b((int)param_2);
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
      DAT_00432054 = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_00432078);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  else {
    FUN_0041d74c(&local_18,param_1,param_2);
    FUN_0041d87b(&local_18);
    FUN_0041d88b((int)&local_18);
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
      DAT_00432054 = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_00432078);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  return;
}


// ==== FUN_004169ea @ 004169ea

undefined4 __thiscall
FUN_004169ea(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041d5c8(&local_38,&local_70,&local_58);
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
        FUN_0041bfd4(local_74,local_5c,local_8,local_c,local_3c,local_28,local_40,local_1c,local_18)
        ;
        local_10 = 1;
      }
    }
  }
  return local_10;
}


// ==== FUN_00416cb2 @ 00416cb2

undefined4 __thiscall FUN_00416cb2(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar2 = FUN_0041d5c8(&local_24,&local_4c,&local_3c);
    if ((int)uVar2 != 0) {
      local_28 = local_1c - local_24;
      local_14 = local_18 - local_20;
      iVar1 = local_20 + local_14 + -1;
      if (*(int *)((int)this + 0x18) == -1) {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0041782c((byte *)(*(int *)((int)this + 0x14) * local_2c + *(int *)((int)this + 8) +
                               local_24),local_28);
        }
      }
      else {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0041782c((byte *)(((*(int *)((int)this + 0x10) - local_2c) + -1) *
                                *(int *)((int)this + 0x14) + *(int *)((int)this + 8) + local_24),
                       local_28);
        }
      }
      local_8 = 1;
      local_60 = local_24;
      local_5c = local_20;
      local_58 = local_24 + local_28 + -1;
      local_54 = local_20 + local_14 + -1;
      FUN_00416313(this,&local_60);
    }
  }
  return local_8;
}


// ==== FUN_00416ee5 @ 00416ee5

void __fastcall FUN_00416ee5(int param_1)

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


// ==== FUN_00416f67 @ 00416f67

undefined4 __thiscall
FUN_00416f67(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0041d5c8(&local_30,&local_64,&local_4c);
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
        FUN_0041c139(local_68,local_50,local_8,local_34,local_20,local_38,local_14,local_6c,param_7,
                     '\0');
        local_c = 1;
        local_88 = local_54;
        local_84 = local_10;
        local_80 = local_34 + local_54 + -1;
        local_7c = local_10 + local_20 + -1;
        FUN_00416313(this,&local_88);
      }
    }
  }
  return local_c;
}


// ==== FUN_004172a1 @ 004172a1

undefined4 __thiscall FUN_004172a1(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0041d5c8(&local_28,&local_50,&local_3c);
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
        FUN_00416313(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00417458 @ 00417458

undefined4 __thiscall FUN_00417458(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0041d5c8(&local_28,&local_50,&local_3c);
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
        FUN_00416313(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_00417610 @ 00417610

void __cdecl FUN_00417610(char param_1,int param_2)

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
  DAT_00432080 = param_1;
  bVar1 = (&DAT_00431b10)[param_1 * 4];
  bVar2 = (&DAT_00431b11)[param_1 * 4];
  bVar3 = (&DAT_00431b12)[param_1 * 4];
  for (local_30 = 0; local_30 < 0x100; local_30 = local_30 + 1) {
    uVar5 = ((uint)bVar1 * param_2 + (uint)(byte)(&DAT_00431b10)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar5) {
      uVar5 = 0xff;
    }
    uVar6 = (param_2 * (uint)bVar2 + (uint)(byte)(&DAT_00431b11)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar6) {
      uVar6 = 0xff;
    }
    uVar7 = (param_2 * (uint)bVar3 + (uint)(byte)(&DAT_00431b12)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    local_1c = 0;
    local_20 = 0xffffffff;
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      uVar8 = (uVar7 - (byte)(&DAT_00431b12)[local_34 * 4]) *
              (uVar7 - (byte)(&DAT_00431b12)[local_34 * 4]) +
              (uVar6 - (byte)(&DAT_00431b11)[local_34 * 4]) *
              (uVar6 - (byte)(&DAT_00431b11)[local_34 * 4]) +
              (uVar5 - (byte)(&DAT_00431b10)[local_34 * 4]) *
              (uVar5 - (byte)(&DAT_00431b10)[local_34 * 4]);
      if (uVar8 < local_20) {
        local_1c = local_34;
        local_20 = uVar8;
      }
    }
    (&DAT_00432088)[local_30] = (undefined1)local_1c;
  }
  return;
}


// ==== FUN_0041782c @ 0041782c

void __cdecl FUN_0041782c(byte *param_1,int param_2)

{
  FUN_0041c55e(0x432088,param_1,param_2);
  return;
}


// ==== FUN_00417860 @ 00417860

void __cdecl FUN_00417860(int param_1,int param_2,short *param_3,short *param_4)

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
      uVar1 = FUN_0041d5c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_3 + local_1c * local_4c + local_20 + 4);
        local_44 = (char *)((int)param_4 + local_10 * local_2c + local_14 + 4);
        FUN_0041bba0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_004179cf @ 004179cf

void __cdecl FUN_004179cf(int param_1,int param_2,short *param_3,short *param_4)

{
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    FUN_0041bba0((char *)((int)param_4 + param_1 + *param_4 * param_2 + 4),(char *)(param_3 + 2),
                 (int)*param_3,(int)param_3[1],(int)*param_4,(int)*param_3,0);
  }
  return;
}


// ==== FUN_00417a6a @ 00417a6a

void __cdecl FUN_00417a6a(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_0041d87b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0041d88b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0041d5c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (char *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041bba0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_00417bf9 @ 00417bf9

void __cdecl FUN_00417bf9(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_0041d87b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0041d88b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0041d5c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041bc5c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_00417d7a @ 00417d7a

void __cdecl FUN_00417d7a(int param_1,int param_2,int param_3,short *param_4,short *param_5)

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
      uVar1 = FUN_0041d5c8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_1c * local_4c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041bc5c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_00417eef @ 00417eef

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00417eef(void *this,int param_1,int param_2)

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
      _DAT_00428408 = 0;
      DAT_00428408 = 0;
      uVar2 = DAT_00428408;
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


// ==== FUN_00418086 @ 00418086

bool __fastcall FUN_00418086(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_004180c0 @ 004180c0

bool __fastcall FUN_004180c0(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_004180fa @ 004180fa

void __thiscall FUN_004180fa(void *this,int param_1)

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
        FUN_00417458(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_00414e7f(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
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
        FUN_004172a1(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_004139d0(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_0041831a @ 0041831a

void __thiscall FUN_0041831a(void *this,int param_1,int param_2,int param_3)

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
        FUN_00417458(&DAT_00431ac8,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_00414e7f(&DAT_00431ac8,param_1,param_2,*(short **)this,0);
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
        FUN_004172a1(&DAT_00431ac8,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_004139d0(&DAT_00431ac8,param_1,param_2,*(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_004184f2 @ 004184f2

void __thiscall FUN_004184f2(void *this,int *param_1,int param_2)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_2 != 0) {
    FUN_00413473(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),param_1,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041860e:
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
    if (bVar1) goto LAB_0041860e;
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
      goto LAB_004186c4;
    }
  }
  local_14 = 0;
LAB_004186c4:
  FUN_00412d55(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),local_c,local_14,param_1,-1);
  return;
}


// ==== FUN_00418724 @ 00418724

void __thiscall FUN_00418724(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_4 != 0) {
    FUN_00413473(&DAT_00431ac8,param_1,param_2,param_1,param_2,param_3,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041881c:
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
    if (bVar1) goto LAB_0041881c;
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
      goto LAB_004188d2;
    }
  }
  local_14 = 0;
LAB_004188d2:
  FUN_00412d55(&DAT_00431ac8,param_1,param_2,param_1,param_2,local_c,local_14,param_3,-1);
  return;
}


// ==== FUN_0041890e @ 0041890e

void __thiscall FUN_0041890e(void *this,int param_1)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_004189c8:
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
    if (bVar1) goto LAB_004189c8;
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
      goto LAB_00418a7e;
    }
  }
  local_14 = 0;
LAB_00418a7e:
  FUN_00419da8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28) + local_c + -1,*(int *)((int)this + 0x2c) + local_14 + -1,
               0);
  FUN_004180fa(this,param_1);
  return;
}


// ==== FUN_00418acc @ 00418acc

void __thiscall FUN_00418acc(void *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_00418b86:
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
    if (bVar1) goto LAB_00418b86;
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
      goto LAB_00418c3c;
    }
  }
  local_14 = 0;
LAB_00418c3c:
  FUN_00419da8((void *)((int)this + 0x40),param_1,param_2,param_1 + local_c + -1,
               param_2 + local_14 + -1,0);
  FUN_0041831a(this,param_1,param_2,param_3);
  return;
}


// ==== FUN_00418c81 @ 00418c81

void __thiscall FUN_00418c81(void *this,int param_1)

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
      FUN_0041436e(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
      return;
    }
    FUN_00413eac(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                 (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                 (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_00418f48:
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
    if (bVar1) goto LAB_00418f48;
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
      goto LAB_00419013;
    }
  }
  local_8 = 0;
LAB_00419013:
  DAT_00432188 = operator_new(local_8 * local_c + 4);
  if (DAT_00432188 != (short *)0x0) {
    *DAT_00432188 = (short)local_c;
    DAT_00432188[1] = (short)local_8;
    _memset(DAT_00432188 + 2,0,local_8 * local_c);
    if (param_1 == 0) {
      FUN_0041436e(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_00432188,0);
    }
    else {
      FUN_00413eac(&DAT_00431ac8,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_00432188,0);
    }
    FUN_0041ee80(DAT_00432188);
  }
  DAT_00432188 = (short *)0x0;
  return;
}


// ==== FUN_00419212 @ 00419212

void __thiscall FUN_00419212(void *this,int param_1,int param_2,int *param_3,int param_4)

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
      FUN_0041436e(&DAT_00431ac8,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,*(short **)this,0);
      return;
    }
    FUN_00413eac(&DAT_00431ac8,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                 (param_3[3] - param_3[1]) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041942b:
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
    if (bVar1) goto LAB_0041942b;
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
      goto LAB_004194e1;
    }
  }
  local_8 = 0;
LAB_004194e1:
  DAT_00432188 = operator_new(local_8 * local_c + 4);
  if (DAT_00432188 != (short *)0x0) {
    *DAT_00432188 = (short)local_c;
    DAT_00432188[1] = (short)local_8;
    _memset(DAT_00432188 + 2,0,local_8 * local_c);
    if (param_4 == 0) {
      FUN_0041436e(&DAT_00431ac8,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_00432188,0);
    }
    else {
      FUN_00413eac(&DAT_00431ac8,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_00432188,0);
    }
    FUN_0041ee80(DAT_00432188);
  }
  DAT_00432188 = (short *)0x0;
  return;
}


// ==== FUN_0041965c @ 0041965c

void __thiscall FUN_0041965c(void *this,int param_1)

{
  FUN_00419da8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               (*(int *)((int)this + 0x38) + *(int *)((int)this + 0x28)) -
               *(int *)((int)this + 0x30),
               (*(int *)((int)this + 0x3c) + *(int *)((int)this + 0x2c)) -
               *(int *)((int)this + 0x34),0);
  FUN_00418c81(this,param_1);
  return;
}


// ==== FUN_004196c1 @ 004196c1

void __thiscall FUN_004196c1(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  FUN_00419da8((void *)((int)this + 0x40),param_1,param_2,(param_3[2] + param_1) - *param_3,
               (param_3[3] + param_2) - param_3[1],0);
  FUN_00419212(this,param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00419730 @ 00419730

undefined4 __thiscall FUN_00419730(void *this,int param_1,int param_2,int param_3,int param_4)

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
  iVar4 = DAT_00431adc;
  iVar3 = DAT_00431ad8;
  iVar2 = DAT_00431ad0;
  if (DAT_00431ad0 == 0) {
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
    iVar6 = DAT_00431ad4 + -1;
    if (param_3 <= DAT_00431ad4 + -1) {
      iVar6 = param_3;
    }
    iVar7 = DAT_00431ad8 + -1;
    if (param_4 <= DAT_00431ad8 + -1) {
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
      if (DAT_00431ae0 == -1) {
        FUN_0041bc5c((undefined4 *)(puVar1 + 4),(undefined4 *)(iVar2 + param_2 * iVar4 + param_1),
                     uVar8,iVar9,uVar8,iVar4);
      }
      else {
        FUN_0041bc5c((undefined4 *)(puVar1 + 4),
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


// ==== FUN_0041995d @ 0041995d

undefined4 __thiscall FUN_0041995d(void *this,int param_1,int param_2)

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
      local_2c = DAT_00431ad4;
      local_38 = DAT_00431ad8;
      local_28 = DAT_00431adc;
      iVar2 = DAT_00431ad4 + -1;
      if (local_18 <= DAT_00431ad4 + -1) {
        iVar2 = local_18;
      }
      iVar3 = DAT_00431ad8 + -1;
      if (local_24 <= DAT_00431ad8 + -1) {
        iVar3 = local_24;
      }
      local_34 = local_34 + 4;
      local_10 = (undefined4 *)DAT_00431ad0;
      local_8 = (iVar2 - local_14) + 1;
      local_c = (iVar3 - local_20) + 1;
      local_48 = local_14 + local_8 + -1;
      local_44 = local_20 + local_c + -1;
      local_50 = local_14;
      local_4c = local_20;
      local_24 = iVar3;
      local_18 = iVar2;
      FUN_00416313(&DAT_00431ac8,&local_50);
      if (DAT_00431ae0 == -1) {
        local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
        FUN_0041bc5c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
      }
      else {
        local_10 = (undefined4 *)
                   ((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
        FUN_0041bc5c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
      }
      local_40 = *(void **)((int)this + *(short *)((int)this + 0x80) * 4);
      local_3c = local_40;
      FUN_0041ee80(local_40);
      *(undefined4 *)((int)this + *(short *)((int)this + 0x80) * 4) = 0;
      *(short *)((int)this + 0x80) = *(short *)((int)this + 0x80) + -1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00419c02 @ 00419c02

undefined4 __thiscall FUN_00419c02(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_00419c8c @ 00419c8c

undefined4 __thiscall FUN_00419c8c(void *this,int *param_1)

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


// ==== FUN_00419d19 @ 00419d19

void __fastcall FUN_00419d19(int param_1)

{
  while (*(short *)(param_1 + 0x80) != -1) {
    FUN_0041ee80(*(void **)(param_1 + *(short *)(param_1 + 0x80) * 4));
    *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
  }
  return;
}


// ==== FUN_00419d8a @ 00419d8a

void __fastcall FUN_00419d8a(int param_1)

{
  FUN_00419d19(param_1);
  return;
}


// ==== FUN_00419da8 @ 00419da8

undefined4 __thiscall
FUN_00419da8(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

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
  iVar4 = DAT_00431adc;
  iVar3 = DAT_00431ad8;
  iVar2 = DAT_00431ad0;
  if (DAT_00431ad0 == 0) {
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
    iVar10 = DAT_00431ad4 + -1;
    if (param_3 <= DAT_00431ad4 + -1) {
      iVar10 = param_3;
    }
    iVar8 = DAT_00431ad8 + -1;
    if (param_4 <= DAT_00431ad8 + -1) {
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
          FUN_0041ee80(*(void **)this);
          pvVar12 = operator_new(uVar11);
          *(void **)this = pvVar12;
          if (*(int *)this == 0) {
            return 0;
          }
          *(uint *)((int)this + 4) = uVar11;
        }
      }
      else {
        FUN_0041ee80(*(void **)this);
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
    if (DAT_00431ae0 == -1) {
      FUN_0041bc5c((undefined4 *)(psVar1 + 6),(undefined4 *)(iVar2 + iVar7 * iVar4 + iVar6),uVar9,
                   iVar10,uVar9,iVar4);
    }
    else {
      FUN_0041bc5c((undefined4 *)(psVar1 + 6),
                   (undefined4 *)(iVar2 + ((iVar3 - iVar7) + -1) * iVar4 + iVar6),uVar9,iVar10,uVar9
                   ,-iVar4);
    }
    *(undefined4 *)((int)this + 8) = 1;
    *(undefined4 *)((int)this + 0xc) = 1;
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0041a0b9 @ 0041a0b9

undefined4 __thiscall FUN_0041a0b9(void *this,int param_1,int param_2,int param_3,int param_4)

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
    local_2c = DAT_00431ad4;
    local_38 = DAT_00431ad8;
    local_28 = DAT_00431adc;
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
      iVar3 = DAT_00431ad4 + -1;
      if (local_18 <= DAT_00431ad4 + -1) {
        iVar3 = local_18;
      }
      iVar2 = DAT_00431ad8 + -1;
      local_18 = iVar3;
      if (local_24 <= DAT_00431ad8 + -1) {
        iVar2 = local_24;
      }
    }
    local_24 = iVar2;
    local_34 = local_34 + 6;
    local_10 = (undefined4 *)DAT_00431ad0;
    local_8 = (local_18 - local_14) + 1;
    local_c = (local_24 - local_20) + 1;
    local_48 = local_14;
    local_44 = local_20;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    FUN_00416313(&DAT_00431ac8,&local_48);
    if (DAT_00431ae0 == -1) {
      local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
      FUN_0041bc5c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
    }
    else {
      local_10 = (undefined4 *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0041bc5c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
    }
    if (param_2 != 0) {
      if (*(int *)this != 0) {
        FUN_0041ee80(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041a389 @ 0041a389

undefined4 __thiscall
FUN_0041a389(void *this,short *param_1,int param_2,int param_3,int param_4,int param_5)

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
    local_38 = DAT_00431ad4;
    local_40 = DAT_00431ad8;
    local_34 = DAT_00431adc;
    local_3c = local_3c + 6;
    local_18 = (undefined1 *)DAT_00431ad0;
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
      FUN_00416313(&DAT_00431ac8,&local_58);
      if (DAT_00431ae0 == -1) {
        local_18 = (undefined1 *)((int)local_18 + local_2c * local_34 + local_20);
        FUN_0041bca6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,local_34,local_c,
                     local_10);
      }
      else {
        local_18 = (undefined1 *)
                   ((int)local_18 + ((local_40 - local_2c) + -1) * local_34 + local_20);
        FUN_0041bca6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,-local_34,local_c,
                     local_10);
      }
      if (param_5 != 0) {
        if (*(int *)this != 0) {
          FUN_0041ee80(*(void **)this);
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


// ==== FUN_0041a660 @ 0041a660

undefined4 __thiscall
FUN_0041a660(void *this,int param_1,byte param_2,int param_3,int param_4,int param_5)

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
    local_2c = DAT_00431ad4;
    local_38 = DAT_00431ad8;
    local_28 = DAT_00431adc;
    iVar2 = DAT_00431ad4 + -1;
    if (local_18 <= DAT_00431ad4 + -1) {
      iVar2 = local_18;
    }
    iVar3 = DAT_00431ad8 + -1;
    if (local_24 <= DAT_00431ad8 + -1) {
      iVar3 = local_24;
    }
    local_34 = local_34 + 6;
    local_10 = (char *)DAT_00431ad0;
    local_8 = (iVar2 - local_14) + 1;
    local_c = (iVar3 - local_20) + 1;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    local_48 = local_14;
    local_44 = local_20;
    local_24 = iVar3;
    local_18 = iVar2;
    FUN_00416313(&DAT_00431ac8,&local_48);
    if (DAT_00431ae0 == -1) {
      local_10 = (char *)((int)local_10 + local_28 * local_20 + local_14);
      FUN_0041bba0(local_10,(char *)local_34,local_8,local_c,local_28,local_30,param_2);
    }
    else {
      local_10 = (char *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0041bba0(local_10,(char *)local_34,local_8,local_c,-local_28,local_30,param_2);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_0041ee80(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041a939 @ 0041a939

undefined4 __thiscall
FUN_0041a939(void *this,HDC param_1,int param_2,int param_3,int param_4,int param_5)

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
    iVar5 = DAT_00431ad4 + -1;
    if (local_18 <= DAT_00431ad4 + -1) {
      iVar5 = local_18;
    }
    iVar4 = DAT_00431ad8 + -1;
    if (local_24 <= DAT_00431ad8 + -1) {
      iVar4 = local_24;
    }
    cx = (iVar5 - local_14) + 1;
    iVar5 = (iVar4 - local_20) + 1;
    if (DAT_00431ae0 == -1) {
      FUN_0041bc5c((undefined4 *)(DAT_00431ad0 + DAT_00431adc * local_20 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,DAT_00431adc,iVar3);
    }
    else {
      FUN_0041bc5c((undefined4 *)
                   (DAT_00431ad0 + ((DAT_00431ad8 - local_20) + -1) * DAT_00431adc + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,-DAT_00431adc,iVar3);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_0041ee80(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    DAT_00432054 = 0;
    hdc = CreateCompatibleDC(param_1);
    h = SelectObject(hdc,DAT_00432078);
    BitBlt(param_1,local_14,local_20,cx,iVar5,hdc,local_14,local_20,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    GdiFlush();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0041ac66 @ 0041ac66

bool __thiscall FUN_0041ac66(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_0041acd9 @ 0041acd9

bool __thiscall FUN_0041acd9(void *this,int *param_1)

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


// ==== FUN_0041ad50 @ 0041ad50

uint __thiscall FUN_0041ad50(void *this,int param_1,int param_2)

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


// ==== FUN_0041adda @ 0041adda

void __thiscall FUN_0041adda(void *this,int param_1,int param_2,undefined1 param_3)

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


// ==== FUN_0041ae70 @ 0041ae70

bool __thiscall FUN_0041ae70(void *this,LPCSTR param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = FUN_00402278(param_1);
  *(LPVOID *)this = pvVar1;
  return *(int *)this != 0;
}


// ==== FUN_0041aeb1 @ 0041aeb1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041aeb1(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int local_30;
  int local_28;
  int local_24;
  int local_20 [4];
  int local_10;
  short *local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    _DAT_00432058 = 0;
    FUN_0041ba43(this,param_1,param_2,param_3,local_20);
    if (*(int *)this == 0) {
      local_30 = 0;
    }
    else {
      local_30 = (int)**(short **)this;
    }
    if (*(int *)this == 0) {
      local_10 = 4;
    }
    else {
      local_10 = *(short *)(*(int *)this + 2) * local_30 + 4;
    }
    local_28 = param_1;
    for (local_24 = 0; *(char *)(local_24 + param_3) != '\0'; local_24 = local_24 + 1) {
      local_c = (short *)(*(char *)(local_24 + param_3) * local_10 + *(int *)this);
      local_8 = (int)*local_c;
      if (param_4 == 0) {
        FUN_004139d0(&DAT_00431ac8,local_28,param_2,local_c,0);
      }
      else {
        FUN_00413c47(&DAT_00431ac8,local_28,param_2,local_c,*(undefined1 *)((int)this + 0xc));
      }
      local_28 = local_28 + *(int *)((int)this + 4) + local_8;
    }
    _DAT_00432058 = 1;
    FUN_00416313(&DAT_00431ac8,local_20);
  }
  return;
}


// ==== FUN_0041b04c @ 0041b04c

void __thiscall FUN_0041b04c(void *this,int param_1,int param_2,int param_3,HDC param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int y;
  int x;
  int local_c;
  
  if (*(int *)this != 0) {
    DAT_00432054 = 0;
    FUN_0041aeb1(this,param_1,param_2,param_3,param_5);
    if (DAT_00432054 != 0) {
      bVar7 = false;
      if ((DAT_0043206c == 0) && (DAT_00432070 == 0)) {
        for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
          iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
          iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_00432078);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_00432054 = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
          if ((DAT_0043206c <= *(int *)(&DAT_00431f14 + local_c * 0x10)) &&
             (DAT_00432070 <= *(int *)(&DAT_00431f18 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
            y = *(int *)(&DAT_00431f18 + local_c * 0x10) - DAT_00432070;
            x = *(int *)(&DAT_00431f14 + local_c * 0x10) - DAT_0043206c;
            iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
            iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_00432078);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
            iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_00432078);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_00432054 = 0;
      }
    }
  }
  return;
}


// ==== FUN_0041b47a @ 0041b47a

void __thiscall
FUN_0041b47a(void *this,int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,
            int param_7)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    FUN_0041ba43(this,param_1,param_2,param_3,&local_14);
    local_14 = local_14 + param_6;
    local_10 = local_10 + param_7;
    local_c = local_c + param_6;
    local_8 = local_8 + param_7;
    FUN_004130df(&DAT_00431ac8,param_1,param_2,&local_14,param_4,-1);
    FUN_0041aeb1(this,param_1,param_2,param_3,param_5);
  }
  return;
}


// ==== FUN_0041b50f @ 0041b50f

void __thiscall
FUN_0041b50f(void *this,int param_1,int param_2,int param_3,HDC param_4,int *param_5,int param_6,
            int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int y;
  int x;
  int local_c;
  
  if (*(int *)this != 0) {
    DAT_00432054 = 0;
    FUN_0041b47a(this,param_1,param_2,param_3,param_5,param_6,param_7,param_8);
    if (DAT_00432054 != 0) {
      bVar7 = false;
      if ((DAT_0043206c == 0) && (DAT_00432070 == 0)) {
        for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
          iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
          iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_00432078);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_00432054 = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
          if ((DAT_0043206c <= *(int *)(&DAT_00431f14 + local_c * 0x10)) &&
             (DAT_00432070 <= *(int *)(&DAT_00431f18 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
            y = *(int *)(&DAT_00431f18 + local_c * 0x10) - DAT_00432070;
            x = *(int *)(&DAT_00431f14 + local_c * 0x10) - DAT_0043206c;
            iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
            iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_00432078);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_00432054; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_00431f20 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00431f1c + local_c * 0x10);
            iVar4 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00431f18 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_00431f14 + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_00432078);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_00432054 = 0;
      }
    }
  }
  return;
}


// ==== FUN_0041b949 @ 0041b949

int __thiscall FUN_0041b949(void *this,int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)this == 0) {
    local_18 = 0;
  }
  else {
    if (*(int *)this == 0) {
      local_1c = 0;
    }
    else {
      local_1c = (int)**(short **)this;
    }
    if (*(int *)this == 0) {
      local_10 = 4;
    }
    else {
      local_10 = *(short *)(*(int *)this + 2) * local_1c + 4;
    }
    local_18 = 0;
    for (local_14 = 0; *(char *)(local_14 + param_1) != '\0'; local_14 = local_14 + 1) {
      local_18 = local_18 +
                 *(int *)((int)this + 4) +
                 (int)*(short *)(*(char *)(local_14 + param_1) * local_10 + *(int *)this);
    }
  }
  return local_18;
}


// ==== FUN_0041ba43 @ 0041ba43

undefined4 __thiscall FUN_0041ba43(void *this,int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)this == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0041b949(this,param_3);
    *param_4 = param_1;
    param_4[1] = param_2;
    param_4[2] = iVar2 + param_1 + -1;
    if (*(int *)this == 0) {
      param_4[3] = param_2 + -1;
    }
    else {
      param_4[3] = *(short *)(*(int *)this + 2) + param_2 + -1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041bae5 @ 0041bae5

int __thiscall FUN_0041bae5(void *this,char param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)this == 0) {
    iVar1 = 0;
  }
  else {
    if (*(int *)this == 0) {
      local_c = 0;
    }
    else {
      local_c = (int)**(short **)this;
    }
    if (*(int *)this == 0) {
      local_8 = 4;
    }
    else {
      local_8 = *(short *)(*(int *)this + 2) * local_c + 4;
    }
    iVar1 = (int)*(short *)(param_1 * local_8 + *(int *)this);
  }
  return iVar1;
}


// ==== FUN_0041bba0 @ 0041bba0

/* WARNING: Removing unreachable block (ram,0x0041bbfe) */
/* WARNING: Removing unreachable block (ram,0x0041bc31) */

void __cdecl
FUN_0041bba0(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
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
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_0041bc06;
LAB_0041bbde:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_0041bc0f;
LAB_0041bbe5:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_0041bc19;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_0041bc34;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_0041bbde;
LAB_0041bc06:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_0041bbe5;
LAB_0041bc0f:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_0041bc19:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_0041bbf3;
          }
        }
LAB_0041bbf3:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0041bc34:
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


// ==== FUN_0041bc5c @ 0041bc5c

void __cdecl
FUN_0041bc5c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
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


// ==== FUN_0041bca6 @ 0041bca6

void __cdecl
FUN_0041bca6(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042938e = param_4;
    do {
      for (uVar4 = DAT_0042938e >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *param_2;
        if (*param_3 != '\0') goto LAB_0041bd20;
LAB_0041bcec:
        uVar3 = param_2[1];
        if (param_3[1] != '\0') goto LAB_0041bd2c;
LAB_0041bcf6:
        uVar3 = param_2[2];
        if (param_3[2] != '\0') goto LAB_0041bd39;
        while (uVar3 = param_2[3], param_3[3] != '\0') {
          while( true ) {
            param_1[3] = uVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0041bd58;
            uVar3 = *param_2;
            if (*param_3 == '\0') goto LAB_0041bcec;
LAB_0041bd20:
            *param_1 = uVar3;
            uVar3 = param_2[1];
            if (param_3[1] == '\0') goto LAB_0041bcf6;
LAB_0041bd2c:
            param_1[1] = uVar3;
            uVar3 = param_2[2];
            if (param_3[2] == '\0') break;
LAB_0041bd39:
            param_1[2] = uVar3;
            uVar3 = param_2[3];
            if (param_3[3] == '\0') goto LAB_0041bd0a;
          }
        }
LAB_0041bd0a:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041bd58:
      if ((DAT_0042938e & 3) != 0) {
        iVar5 = (DAT_0042938e & 3) + 1;
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


// ==== FUN_0041bd8d @ 0041bd8d

void __cdecl
FUN_0041bd8d(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8,char param_9)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042938e = param_4;
    do {
      for (uVar4 = DAT_0042938e >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar1 = *param_2;
        if (*param_3 == param_9) goto LAB_0041be0d;
LAB_0041bdd5:
        uVar1 = param_2[1];
        if (param_3[1] == param_9) goto LAB_0041be1a;
LAB_0041bde0:
        uVar1 = param_2[2];
        if (param_3[2] == param_9) goto LAB_0041be28;
        while (uVar1 = param_2[3], param_3[3] == param_9) {
          while( true ) {
            param_1[3] = uVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0041be48;
            uVar1 = *param_2;
            if (*param_3 != param_9) goto LAB_0041bdd5;
LAB_0041be0d:
            *param_1 = uVar1;
            uVar1 = param_2[1];
            if (param_3[1] != param_9) goto LAB_0041bde0;
LAB_0041be1a:
            param_1[1] = uVar1;
            uVar1 = param_2[2];
            if (param_3[2] != param_9) break;
LAB_0041be28:
            param_1[2] = uVar1;
            uVar1 = param_2[3];
            if (param_3[3] != param_9) goto LAB_0041bdf6;
          }
        }
LAB_0041bdf6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041be48:
      if ((DAT_0042938e & 3) != 0) {
        iVar5 = (DAT_0042938e & 3) + 1;
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


// ==== FUN_0041be7e @ 0041be7e

void __cdecl
FUN_0041be7e(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    DAT_0042938e = param_2 & 3;
    uVar1 = param_2 >> 2;
    do {
      for (; uVar2 = DAT_0042938e, uVar1 != 0; uVar1 = uVar1 - 1) {
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


// ==== FUN_0041bed6 @ 0041bed6

/* WARNING: Removing unreachable block (ram,0x0041bf32) */
/* WARNING: Removing unreachable block (ram,0x0041bf65) */

void __cdecl
FUN_0041bed6(undefined1 *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
            undefined1 param_7)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    do {
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0041bf3a;
LAB_0041bf12:
        if (param_2[1] != '\0') goto LAB_0041bf43;
LAB_0041bf19:
        if (param_2[2] != '\0') goto LAB_0041bf4d;
        while (param_2[3] != '\0') {
          while( true ) {
            param_1[3] = param_7;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar3 = uVar3 - 1;
            if (uVar3 == 0) goto LAB_0041bf68;
            if (*param_2 == '\0') goto LAB_0041bf12;
LAB_0041bf3a:
            *param_1 = param_7;
            if (param_2[1] == '\0') goto LAB_0041bf19;
LAB_0041bf43:
            param_1[1] = param_7;
            if (param_2[2] == '\0') break;
LAB_0041bf4d:
            param_1[2] = param_7;
            if (param_2[3] == '\0') goto LAB_0041bf27;
          }
        }
LAB_0041bf27:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0041bf68:
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


// ==== FUN_0041bf90 @ 0041bf90

void FUN_0041bf90(void)

{
  byte in_AH;
  undefined4 unaff_ESI;
  
  if (in_AH < DAT_0042939b) {
    if (DAT_0042939a == '\0') {
      return;
    }
    DAT_00429396 = unaff_ESI;
    DAT_0042939a = 0;
    return;
  }
  if (DAT_0042939a == '\x01') {
    return;
  }
  DAT_00429392 = unaff_ESI;
  DAT_0042939a = 1;
  return;
}


// ==== FUN_0041bfd4 @ 0041bfd4

/* WARNING: Removing unreachable block (ram,0x0041c0dd) */

void __cdecl
FUN_0041bfd4(char *param_1,char *param_2,char *param_3,int param_4,uint param_5,int param_6,
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
    DAT_0042939a = 0;
    DAT_00429392 = param_3;
    DAT_00429396 = param_4;
    iVar1 = param_9 - param_5;
    DAT_0042938e = param_5;
    do {
      for (uVar3 = DAT_0042938e >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0041c072;
LAB_0041c03a:
        if (param_2[1] != '\0') goto LAB_0041c086;
LAB_0041c041:
        if (param_2[2] != '\0') goto LAB_0041c09c;
        while (param_2[3] != '\0') {
          while( true ) {
            FUN_0041bf90();
            if (param_3[3] != '\0') {
              param_1[3] = param_3[3];
            }
            param_1 = param_1 + 4;
            param_3 = param_3 + 4;
            param_2 = param_2 + 4;
            DAT_00429392 = DAT_00429392 + 4;
            DAT_00429396 = DAT_00429396 + 4;
            uVar3 = extraout_ECX_02 - 1;
            param_6 = extraout_EDX_02;
            if (uVar3 == 0) goto LAB_0041c0e0;
            if (*param_2 == '\0') goto LAB_0041c03a;
LAB_0041c072:
            FUN_0041bf90();
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
            uVar3 = extraout_ECX;
            param_6 = extraout_EDX;
            if (param_2[1] == '\0') goto LAB_0041c041;
LAB_0041c086:
            FUN_0041bf90();
            if (param_3[1] != '\0') {
              param_1[1] = param_3[1];
            }
            uVar3 = extraout_ECX_00;
            param_6 = extraout_EDX_00;
            if (param_2[2] == '\0') break;
LAB_0041c09c:
            FUN_0041bf90();
            if (param_3[2] != '\0') {
              param_1[2] = param_3[2];
            }
            uVar3 = extraout_ECX_01;
            param_6 = extraout_EDX_01;
            if (param_2[3] == '\0') goto LAB_0041c04f;
          }
        }
LAB_0041c04f:
        param_1 = param_1 + 4;
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        DAT_00429392 = DAT_00429392 + 4;
        DAT_00429396 = DAT_00429396 + 4;
      }
LAB_0041c0e0:
      if ((DAT_0042938e & 3) != 0) {
        iVar4 = (DAT_0042938e & 3) + 1;
        pcVar5 = param_3;
        pcVar6 = param_1;
        while (param_1 = pcVar6, param_3 = pcVar5, iVar4 = iVar4 + -1, iVar4 != 0) {
          cVar2 = *param_2;
          pcVar5 = param_3 + 1;
          pcVar6 = param_1 + 1;
          param_2 = param_2 + 1;
          DAT_00429392 = DAT_00429392 + 1;
          DAT_00429396 = DAT_00429396 + 1;
          if (cVar2 != '\0') {
            FUN_0041bf90();
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
      DAT_00429392 = DAT_00429392 + iVar1;
      DAT_00429396 = DAT_00429396 + iVar1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}


// ==== FUN_0041c139 @ 0041c139

void __cdecl
FUN_0041c139(char *param_1,char *param_2,byte *param_3,uint param_4,int param_5,int param_6,
            int param_7,int param_8,byte param_9,char param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_4 != 0) {
    DAT_0042938e = param_4;
    do {
      for (uVar2 = DAT_0042938e >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        cVar1 = *param_2;
        if ((cVar1 != param_10) && (param_9 <= *param_3)) goto LAB_0041c1d0;
LAB_0041c18c:
        cVar1 = param_2[1];
        if ((cVar1 != param_10) && (param_9 <= param_3[1])) goto LAB_0041c1e0;
LAB_0041c19a:
        cVar1 = param_2[2];
        if ((cVar1 != param_10) && (param_9 <= param_3[2])) goto LAB_0041c1f1;
        while ((cVar1 = param_2[3], cVar1 != param_10 && (param_9 <= param_3[3]))) {
          while( true ) {
            param_1[3] = cVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_0041c214;
            cVar1 = *param_2;
            if ((cVar1 == param_10) || (*param_3 < param_9)) goto LAB_0041c18c;
LAB_0041c1d0:
            *param_1 = cVar1;
            cVar1 = param_2[1];
            if ((cVar1 == param_10) || (param_3[1] < param_9)) goto LAB_0041c19a;
LAB_0041c1e0:
            param_1[1] = cVar1;
            cVar1 = param_2[2];
            if ((cVar1 == param_10) || (param_3[2] < param_9)) break;
LAB_0041c1f1:
            param_1[2] = cVar1;
            cVar1 = param_2[3];
            if ((cVar1 == param_10) || (param_3[3] < param_9)) goto LAB_0041c1b6;
          }
        }
LAB_0041c1b6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041c214:
      if ((DAT_0042938e & 3) != 0) {
        iVar3 = (DAT_0042938e & 3) + 1;
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


// ==== FUN_0041c250 @ 0041c250

undefined * FUN_0041c250(void)

{
  return &DAT_0042840c;
}


// ==== FUN_0041c256 @ 0041c256

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041c256(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

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
  
  iVar9 = param_1 + _DAT_00428410;
  iVar6 = param_3 + _DAT_00428410;
  iVar4 = iVar6;
  iVar2 = param_2 + _DAT_00428414;
  iVar3 = param_4 + _DAT_00428414;
  if (iVar6 < iVar9) {
    iVar4 = iVar9;
    iVar9 = iVar6;
    iVar2 = param_4 + _DAT_00428414;
    iVar3 = param_2 + _DAT_00428414;
  }
  if ((DAT_00428418 <= iVar4) && (iVar9 <= DAT_0042841c)) {
    if (iVar2 < iVar3) {
      if (iVar3 < DAT_00428420) {
        return;
      }
      if (DAT_00428424 < iVar2) {
        return;
      }
      if ((iVar9 < DAT_00428418) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00428418) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00428418,
         DAT_00428424 < iVar2)) {
        return;
      }
      if ((DAT_0042841c < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0042841c - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_0042841c,
         iVar3 < DAT_00428420)) {
        return;
      }
      if ((iVar2 < DAT_00428420) &&
         (iVar9 = (int)(((longlong)(iVar3 - DAT_00428420) * (longlong)(iVar9 - iVar4)) /
                       (longlong)-(iVar2 - iVar3)) + iVar4, iVar2 = DAT_00428420,
         DAT_0042841c < iVar9)) {
        return;
      }
      if ((DAT_00428424 < iVar3) &&
         (iVar4 = (int)(((longlong)(DAT_00428424 - iVar2) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar3 - iVar2)) + iVar9, iVar3 = DAT_00428424,
         iVar4 < DAT_00428418)) {
        return;
      }
    }
    else {
      if (DAT_00428424 < iVar3) {
        return;
      }
      if (iVar2 < DAT_00428420) {
        return;
      }
      if ((iVar9 < DAT_00428418) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00428418) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00428418,
         iVar2 < DAT_00428420)) {
        return;
      }
      if ((DAT_0042841c < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0042841c - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_0042841c,
         DAT_00428424 < iVar3)) {
        return;
      }
      if ((iVar3 < DAT_00428420) &&
         (iVar4 = (int)(((longlong)(iVar2 - DAT_00428420) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar2 - iVar3)) + iVar9, iVar3 = DAT_00428420,
         iVar4 < DAT_00428418)) {
        return;
      }
      if ((DAT_00428424 < iVar2) &&
         (iVar9 = (int)(((longlong)(DAT_00428424 - iVar3) * (longlong)(iVar9 - iVar4)) /
                       (longlong)(iVar2 - iVar3)) + iVar4, iVar2 = DAT_00428424,
         DAT_0042841c < iVar9)) {
        return;
      }
    }
    if (iVar9 == iVar4) {
      iVar4 = iVar2;
      if (iVar3 <= iVar2) {
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      puVar10 = (undefined1 *)(DAT_00428428 * iVar4 + iVar9 + _DAT_0042840c);
      for (iVar4 = (iVar3 - iVar4) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + DAT_00428428;
      }
    }
    else if (iVar2 == iVar3) {
      uVar7 = (iVar4 - iVar9) + 1;
      puVar11 = (undefined4 *)(DAT_00428428 * iVar2 + iVar9 + _DAT_0042840c);
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
      DAT_0042842c = DAT_00428428;
      uVar7 = iVar4 - iVar9;
      uVar8 = iVar3 - iVar2;
      if (iVar3 < iVar2) {
        DAT_0042842c = -DAT_00428428;
        uVar8 = -uVar8;
      }
      iVar4 = DAT_0042842c;
      if ((short)uVar7 < (short)uVar8) {
        puVar10 = (undefined1 *)(DAT_00428428 * iVar2 + iVar9 + _DAT_0042840c);
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
        puVar10 = (undefined1 *)(DAT_00428428 * iVar2 + iVar9 + _DAT_0042840c);
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


// ==== FUN_0041c55e @ 0041c55e

void __cdecl FUN_0041c55e(int param_1,byte *param_2,int param_3)

{
  do {
    *param_2 = *(byte *)(param_1 + (uint)*param_2);
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


// ==== FUN_0041c57f @ 0041c57f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041c57f(void *this,int *param_1,int param_2)

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
  
  DAT_00429338 = 0x7fffffff;
  DAT_0042933c = 0;
  DAT_00429330 = 0x7fffffff;
  DAT_00429334 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      DAT_00429334 = *piVar10 + _DAT_00428410;
      if (DAT_00429334 <= DAT_00429330) {
        DAT_00429330 = DAT_00429334;
      }
      piVar10 = piVar10 + 2;
      iVar2 = *piVar1 + _DAT_00428414;
      if (iVar2 <= DAT_00429338) {
        DAT_00429338 = iVar2;
      }
      if (iVar2 <= DAT_0042933c) {
        DAT_0042933c = iVar2;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_00429330 <= DAT_0042841c) && (DAT_00428418 <= DAT_00429334)) &&
        (DAT_00429338 <= DAT_00428424)) && (DAT_00428420 <= DAT_0042933c)) {
      if (DAT_00429338 <= DAT_00428420) {
        DAT_00429338 = DAT_00428420;
      }
      if (DAT_00428424 <= DAT_0042933c) {
        DAT_0042933c = DAT_00428424;
      }
      iVar2 = DAT_0042841c + 1;
      piVar10 = &DAT_00428430;
      for (iVar4 = ((DAT_0042933c - DAT_00429338) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar2;
        piVar10 = piVar10 + 1;
      }
      puVar14 = &DAT_00428434;
      for (iVar2 = (DAT_0042933c - DAT_00429338) + 1; iVar4 = DAT_00429338, uVar3 = _DAT_00429348,
          0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 2;
      }
      for (; DAT_00429338 = iVar4, _DAT_00429348 = uVar3, 1 < DAT_00429340;
          DAT_00429340 = DAT_00429340 + -1) {
        iVar5 = param_1[1] + _DAT_00428414;
        iVar7 = param_1[3] + _DAT_00428414;
        iVar2 = *param_1 + _DAT_00428410;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_00428410;
        if (iVar7 < iVar5) {
          iVar2 = param_1[2] + _DAT_00428410;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_00428410;
        }
        if ((iVar11 <= DAT_0042933c) && (iVar4 <= iVar7)) {
          if (iVar11 <= iVar4) {
            iVar2 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar2 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042933c < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042933c - iVar11) * (longlong)(iVar8 - iVar2)) /
                         (longlong)(iVar7 - iVar11)) + iVar2;
            iVar7 = DAT_0042933c;
          }
          _DAT_00429344 = &DAT_00428430 + (iVar7 - iVar4) * 2;
          piVar10 = &DAT_00428430 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar2;
          if (iVar8 < iVar2) {
            _DAT_00429348 = -uVar9;
            if ((int)_DAT_00429348 < iVar4) goto LAB_0041c821;
            iVar7 = -(_DAT_00429348 + 1 >> 1);
            uVar3 = _DAT_00429348 + 1;
            iVar11 = iVar2;
LAB_0041c7f8:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041c7f8;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              if (iVar8 <= *piVar10) {
                *piVar10 = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar2 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_00429348;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0041c821:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar6 = 0x80000000;
            _DAT_00429348 = uVar3;
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
            _DAT_00429348 = uVar9;
LAB_0041c7b6:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              iVar11 = iVar8 + 1;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041c7b6;
              }
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar8) {
                piVar10[1] = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar7 = iVar7 - _DAT_00429348;
              iVar2 = iVar11;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_00429338;
        uVar3 = _DAT_00429348;
      }
      if (DAT_00429330 <= DAT_00428418) {
        DAT_00429330 = DAT_00428418;
      }
      DAT_00429354 = (uint)*(ushort *)this;
      DAT_00429350 = (undefined4 *)((int)this + DAT_00429354 * *(ushort *)((int)this + 2) + 4);
      puVar14 = (undefined4 *)((int)this + 4);
      DAT_00429358 = DAT_00428428 * iVar4 + _DAT_0042840c;
      piVar10 = &DAT_00428430;
      DAT_0042934c = puVar14;
      if (iVar4 <= DAT_0042933c) {
        do {
          iVar2 = *piVar10;
          if (*piVar10 <= DAT_00428418) {
            iVar2 = DAT_00428418;
          }
          iVar11 = piVar10[1];
          if (piVar10[1] <= DAT_0042841c) {
            iVar11 = DAT_0042841c;
          }
          if (iVar2 <= iVar11) {
            uVar9 = (iVar11 - iVar2) + 1;
            puVar15 = (undefined4 *)(DAT_00429358 + iVar2);
            iVar2 = CONCAT22((short)((uint)(iVar2 - DAT_00429330) >> 0x10),
                             (ushort)(iVar2 - DAT_00429330) % (ushort)(byte)DAT_00429354);
            puVar12 = (undefined4 *)((int)puVar14 + iVar2);
            iVar2 = iVar2 - DAT_00429354;
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
              if ((int)DAT_00429354 < (int)uVar9) {
                do {
                  uVar3 = DAT_00429354;
                  uVar9 = uVar9 - DAT_00429354;
                  if ((short)DAT_00429354 != 0) {
                    uVar6 = DAT_00429354 >> 1;
                    puVar12 = puVar14;
                    puVar13 = puVar15;
                    if ((DAT_00429354 & 1) != 0) {
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
                } while ((int)DAT_00429354 < (int)uVar9);
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
          DAT_00429358 = DAT_00429358 + DAT_00428428;
          piVar10 = piVar10 + 2;
          puVar14 = (undefined4 *)((int)puVar14 + DAT_00429354);
          if (DAT_00429350 <= puVar14) {
            puVar14 = DAT_0042934c;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042933c);
      }
    }
  }
  return;
}


// ==== FUN_0041c9c6 @ 0041c9c6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041c9c6(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_00429338 = 0x7fffffff;
  DAT_0042933c = 0;
  DAT_00429330 = 0x7fffffff;
  DAT_00429334 = 0;
  if (param_2 != 0) {
    piVar12 = param_1;
    do {
      piVar1 = piVar12 + 1;
      iVar3 = *piVar12 + _DAT_00428410;
      if (iVar3 <= DAT_00429330) {
        DAT_00429330 = iVar3;
      }
      if (DAT_00429334 <= iVar3) {
        DAT_00429334 = iVar3;
      }
      piVar12 = piVar12 + 2;
      iVar3 = *piVar1 + _DAT_00428414;
      if (iVar3 <= DAT_00429338) {
        DAT_00429338 = iVar3;
      }
      if (DAT_0042933c <= iVar3) {
        DAT_0042933c = iVar3;
      }
    } while ((int)piVar12 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_00429330 <= DAT_0042841c) && (DAT_00428418 <= DAT_00429334)) &&
        (DAT_00429338 <= DAT_00428424)) && (DAT_00428420 <= DAT_0042933c)) {
      if (DAT_00429338 <= DAT_00428420) {
        DAT_00429338 = DAT_00428420;
      }
      if (DAT_00428424 <= DAT_0042933c) {
        DAT_0042933c = DAT_00428424;
      }
      iVar3 = DAT_0042841c + 1;
      piVar12 = &DAT_00428430;
      for (iVar4 = ((DAT_0042933c - DAT_00429338) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = iVar3;
        piVar12 = piVar12 + 1;
      }
      puVar13 = &DAT_00428434;
      for (iVar3 = (DAT_0042933c - DAT_00429338) + 1; DAT_00429340 = param_2, iVar4 = DAT_00429338,
          uVar6 = _DAT_00429348, 0 < iVar3; iVar3 = iVar3 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 2;
      }
      for (; DAT_00429338 = iVar4, _DAT_00429348 = uVar6, 1 < DAT_00429340;
          DAT_00429340 = DAT_00429340 + -1) {
        iVar5 = param_1[1] + _DAT_00428414;
        iVar7 = param_1[3] + _DAT_00428414;
        iVar3 = *param_1 + _DAT_00428410;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_00428410;
        if (iVar7 < iVar5) {
          iVar3 = param_1[2] + _DAT_00428410;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_00428410;
        }
        if ((iVar11 <= DAT_0042933c) && (iVar4 <= iVar7)) {
          if (iVar11 < iVar4) {
            iVar3 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar3 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042933c < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042933c - iVar11) * (longlong)(iVar8 - iVar3)) /
                         (longlong)(iVar7 - iVar11)) + iVar3;
            iVar7 = DAT_0042933c;
          }
          _DAT_00429344 = &DAT_00428430 + (iVar7 - iVar4) * 2;
          piVar12 = &DAT_00428430 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            _DAT_00429348 = -uVar9;
            if ((int)_DAT_00429348 < iVar4) goto LAB_0041cc6d;
            iVar7 = -(_DAT_00429348 + 1 >> 1);
            uVar6 = _DAT_00429348 + 1;
            iVar11 = iVar3;
LAB_0041cc44:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041cc44;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              if (iVar8 <= *piVar12) {
                *piVar12 = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar3 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_00429348;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0041cc6d:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar10 = 0x80000000;
            _DAT_00429348 = uVar6;
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
            _DAT_00429348 = uVar9;
LAB_0041cc02:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              iVar11 = iVar8 + 1;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041cc02;
              }
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar8) {
                piVar12[1] = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar7 = iVar7 - _DAT_00429348;
              iVar3 = iVar11;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_00429338;
        uVar6 = _DAT_00429348;
      }
      iVar3 = DAT_00428428 * iVar4 + _DAT_0042840c;
      piVar12 = &DAT_00428430;
      uVar2 = CONCAT11(param_3,param_3);
      uStack_14 = CONCAT22(uVar2,uVar2);
      if (iVar4 <= DAT_0042933c) {
        do {
          iVar11 = *piVar12;
          if (*piVar12 <= DAT_00428418) {
            iVar11 = DAT_00428418;
          }
          iVar7 = piVar12[1];
          if (piVar12[1] <= DAT_0042841c) {
            iVar7 = DAT_0042841c;
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
          iVar3 = iVar3 + DAT_00428428;
          piVar12 = piVar12 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042933c);
      }
    }
  }
  return;
}


// ==== FUN_0041cd38 @ 0041cd38

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041cd38(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_00429338 = 0x7fffffff;
  DAT_0042933c = 0;
  DAT_00429330 = 0x7fffffff;
  DAT_00429334 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      iVar3 = *piVar10 + _DAT_00428410;
      if (iVar3 <= DAT_00429330) {
        DAT_00429330 = iVar3;
      }
      if (DAT_00429334 <= iVar3) {
        DAT_00429334 = iVar3;
      }
      piVar10 = piVar10 + 2;
      iVar3 = *piVar1 + _DAT_00428414;
      if (iVar3 <= DAT_00429338) {
        DAT_00429338 = iVar3;
      }
      if (DAT_0042933c <= iVar3) {
        DAT_0042933c = iVar3;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_00429330 <= DAT_0042841c) && (DAT_00428418 <= DAT_00429334)) &&
        (DAT_00429338 <= DAT_00428424)) && (DAT_00428420 <= DAT_0042933c)) {
      if (DAT_00429338 <= DAT_00428420) {
        DAT_00429338 = DAT_00428420;
      }
      if (DAT_00428424 <= DAT_0042933c) {
        DAT_0042933c = DAT_00428424;
      }
      iVar3 = DAT_0042841c + 1;
      piVar10 = &DAT_00428430;
      for (iVar4 = ((DAT_0042933c - DAT_00429338) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar3;
        piVar10 = piVar10 + 1;
      }
      iVar3 = (DAT_0042933c - DAT_00429338) + 1;
      puVar12 = &DAT_00428434;
      iVar4 = iVar3;
      while (iVar11 = iVar3, DAT_00429340 = param_2, iVar3 = DAT_00429338, uVar2 = _DAT_00429348,
            0 < iVar4) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 2;
        iVar3 = iVar11 + -1;
        iVar4 = iVar11;
      }
      for (; DAT_00429338 = iVar3, _DAT_00429348 = uVar2, 1 < DAT_00429340;
          DAT_00429340 = DAT_00429340 + -1) {
        iVar5 = param_1[1] + _DAT_00428414;
        iVar6 = param_1[3] + _DAT_00428414;
        iVar4 = *param_1 + _DAT_00428410;
        iVar11 = iVar5;
        iVar7 = param_1[2] + _DAT_00428410;
        if (iVar6 < iVar5) {
          iVar4 = param_1[2] + _DAT_00428410;
          iVar11 = iVar6;
          iVar6 = iVar5;
          iVar7 = *param_1 + _DAT_00428410;
        }
        if ((iVar11 <= DAT_0042933c) && (iVar3 <= iVar6)) {
          if (iVar11 < iVar3) {
            iVar4 = (int)(((longlong)(iVar6 - iVar3) * (longlong)(iVar4 - iVar7)) /
                         (longlong)(iVar6 - iVar11)) + iVar7;
            iVar11 = iVar3;
          }
          if (DAT_0042933c < iVar6) {
            iVar7 = (int)(((longlong)(DAT_0042933c - iVar11) * (longlong)(iVar7 - iVar4)) /
                         (longlong)(iVar6 - iVar11)) + iVar4;
            iVar6 = DAT_0042933c;
          }
          _DAT_00429344 = &DAT_00428430 + (iVar6 - iVar3) * 2;
          piVar10 = &DAT_00428430 + (iVar11 - iVar3) * 2;
          iVar3 = (iVar6 - iVar3) - (iVar11 - iVar3);
          uVar8 = iVar7 - iVar4;
          if (iVar7 < iVar4) {
            _DAT_00429348 = -uVar8;
            if ((int)_DAT_00429348 < iVar3) goto LAB_0041cfdc;
            iVar6 = -(_DAT_00429348 + 1 >> 1);
            uVar2 = _DAT_00429348 + 1;
            iVar11 = iVar4;
LAB_0041cfb3:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              iVar11 = iVar7 + -1;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0041cfb3;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              if (iVar7 <= *piVar10) {
                *piVar10 = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar4 = iVar7 + -1;
              iVar6 = iVar6 - _DAT_00429348;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
          else if ((int)uVar8 < iVar3) {
LAB_0041cfdc:
            iVar11 = (int)(CONCAT44((int)uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) /
                          (longlong)iVar3);
            uVar8 = iVar11 * 2;
            iVar3 = iVar3 + 1;
            uVar9 = 0x80000000;
            _DAT_00429348 = uVar2;
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
            _DAT_00429348 = uVar8;
LAB_0041cf71:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              iVar11 = iVar7 + 1;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0041cf71;
              }
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar7) {
                piVar10[1] = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar6 = iVar6 - _DAT_00429348;
              iVar4 = iVar11;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
        }
        param_1 = param_1 + 2;
        iVar3 = DAT_00429338;
        uVar2 = _DAT_00429348;
      }
      if (DAT_00429330 <= DAT_00428418) {
        DAT_00429330 = DAT_00428418;
      }
      DAT_00429358 = DAT_00428428 * iVar3 + _DAT_0042840c;
      piVar10 = &DAT_00428430;
      if (iVar3 <= DAT_0042933c) {
        do {
          iVar4 = *piVar10;
          if (*piVar10 <= DAT_00428418) {
            iVar4 = DAT_00428418;
          }
          iVar11 = piVar10[1];
          if (DAT_0042841c <= piVar10[1]) {
            iVar11 = DAT_0042841c;
          }
          if (iVar4 <= iVar11) {
            puVar13 = (undefined1 *)(DAT_00429358 + iVar4);
            for (iVar11 = (iVar11 - iVar4) + 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar13 = param_3;
              puVar13 = puVar13 + 1;
            }
          }
          DAT_00429358 = DAT_00429358 + DAT_00428428;
          piVar10 = piVar10 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= DAT_0042933c);
      }
    }
  }
  return;
}


// ==== FUN_0041d0ae @ 0041d0ae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041d0ae(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

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
  
  DAT_0042936c = '\0';
  if ((int)param_3 < 0) {
    DAT_0042936c = '\x01';
    param_3 = -param_3;
  }
  else if (param_3 == 0) {
    param_3 = 1;
  }
  DAT_0042936d = '\0';
  if ((int)param_4 < 0) {
    DAT_0042936d = '\x01';
    param_4 = -param_4;
  }
  else if (param_4 == 0) {
    param_4 = 1;
  }
  uVar4 = *param_5 / param_3;
  uVar1 = ((ulonglong)(uint)*param_5 % (ulonglong)param_3 << 0x20) / (ulonglong)param_3;
  uVar5 = (uint)uVar1;
  DAT_0042937a = param_5[1] / param_4;
  uVar2 = ((ulonglong)(uint)param_5[1] % (ulonglong)param_4 << 0x20) / (ulonglong)param_4;
  DAT_00429376 = (uint)uVar2;
  DAT_00429386 = (uint)*param_5;
  iVar6 = param_1 + _DAT_00428410;
  iVar8 = param_3 + iVar6 + -1;
  iVar7 = param_2 + _DAT_00428414;
  DAT_00429368 = param_4 + iVar7 + -1;
  DAT_00429364 = iVar7;
  DAT_0042936e = uVar5;
  DAT_00429372 = uVar4;
  if ((((iVar6 <= DAT_0042841c) && (DAT_00428418 <= iVar8)) && (iVar7 <= DAT_00428424)) &&
     (DAT_00428420 <= DAT_00429368)) {
    DAT_0042937e = 0;
    _DAT_00429382 = 0;
    puVar10 = param_5 + 2;
    DAT_0042935c = iVar6;
    if ((iVar6 < DAT_00428418) && (DAT_0042935c = DAT_00428418, DAT_0042936c == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar6 - DAT_00428418) * (uVar1 & 0xffffffff);
      DAT_0042937e = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + -(iVar6 - DAT_00428418) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    DAT_00429360 = iVar8;
    if ((DAT_0042841c < iVar8) && (DAT_00429360 = DAT_0042841c, DAT_0042936c != '\0')) {
      lVar3 = (ulonglong)(uint)(iVar8 - DAT_0042841c) * (uVar1 & 0xffffffff);
      DAT_0042937e = DAT_0042937e + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + (iVar8 - DAT_0042841c) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    if ((iVar7 < DAT_00428420) && (DAT_00429364 = DAT_00428420, DAT_0042936d == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar7 - DAT_00428420) * (uVar2 & 0xffffffff);
      _DAT_00429382 = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                (-(iVar7 - DAT_00428420) * DAT_0042937a + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_00429386);
    }
    iVar6 = DAT_00429368;
    if ((DAT_00428424 < DAT_00429368) && (iVar6 = DAT_00428424, DAT_0042936d == '\0')) {
      lVar3 = (ulonglong)(uint)(DAT_00429368 - DAT_00428424) * (uVar2 & 0xffffffff);
      _DAT_00429382 = _DAT_00429382 + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                ((DAT_00429368 - DAT_00428424) * DAT_0042937a + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_00429386);
    }
    DAT_0042937a = DAT_0042937a * DAT_00429386;
    DAT_00429368 = iVar6;
    if (DAT_0042936c != '\0') {
      DAT_0042938a = puVar10;
      if (DAT_0042936d == '\0') {
        DAT_00429358 = (char *)(DAT_00428428 * DAT_00429364 + DAT_00429360 + _DAT_0042840c);
        DAT_00429360 = DAT_00429360 - (DAT_0042935c + -1);
        DAT_00429368 = iVar6 - (DAT_00429364 + -1);
        iVar6 = DAT_00429360;
        uVar9 = DAT_0042937e;
        pcVar11 = DAT_00429358;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_00429368;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_00429382,DAT_00429376);
          _DAT_00429382 = _DAT_00429382 + DAT_00429376;
          if (bVar12) {
            DAT_0042938a = (ushort *)((int)DAT_0042938a + DAT_00429386);
          }
          puVar10 = (ushort *)((int)DAT_0042938a + DAT_0042937a);
          DAT_00429358 = DAT_00429358 + DAT_00428428;
          DAT_00429368 = DAT_00429368 + -1;
          iVar6 = DAT_00429360;
          uVar9 = DAT_0042937e;
          pcVar11 = DAT_00429358;
          DAT_0042938a = puVar10;
        } while (DAT_00429368 != 0 && 0 < iVar7);
      }
      else {
        DAT_00429358 = (char *)(DAT_00428428 * iVar6 + DAT_00429360 + _DAT_0042840c);
        DAT_00429360 = DAT_00429360 - (DAT_0042935c + -1);
        DAT_00429368 = iVar6 - (DAT_00429364 + -1);
        iVar6 = DAT_00429360;
        uVar9 = DAT_0042937e;
        pcVar11 = DAT_00429358;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_00429368;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_00429382,DAT_00429376);
          _DAT_00429382 = _DAT_00429382 + DAT_00429376;
          if (bVar12) {
            DAT_0042938a = (ushort *)((int)DAT_0042938a + DAT_00429386);
          }
          puVar10 = (ushort *)((int)DAT_0042938a + DAT_0042937a);
          DAT_00429358 = DAT_00429358 + -DAT_00428428;
          DAT_00429368 = DAT_00429368 + -1;
          iVar6 = DAT_00429360;
          uVar9 = DAT_0042937e;
          pcVar11 = DAT_00429358;
          DAT_0042938a = puVar10;
        } while (DAT_00429368 != 0 && 0 < iVar7);
      }
    }
    uVar5 = DAT_00429372;
    uVar4 = DAT_0042936e;
    if (DAT_0042936d != '\0') {
      DAT_00429358 = (char *)(DAT_00428428 * DAT_00429368 + DAT_0042935c + _DAT_0042840c);
      DAT_00429360 = DAT_00429360 - (DAT_0042935c + -1);
      DAT_00429368 = DAT_00429368 - (DAT_00429364 + -1);
      iVar6 = DAT_00429360;
      uVar9 = DAT_0042937e;
      pcVar11 = DAT_00429358;
      DAT_0042938a = puVar10;
      do {
        do {
          if ((char)*puVar10 != '\0') {
            *pcVar11 = (char)*puVar10;
          }
          iVar7 = DAT_00429368;
          puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
          iVar6 = iVar6 + -1;
          uVar9 = uVar9 + uVar4;
          pcVar11 = pcVar11 + 1;
        } while (iVar6 != 0);
        bVar12 = CARRY4(_DAT_00429382,DAT_00429376);
        _DAT_00429382 = _DAT_00429382 + DAT_00429376;
        if (bVar12) {
          DAT_0042938a = (ushort *)((int)DAT_0042938a + DAT_00429386);
        }
        puVar10 = (ushort *)((int)DAT_0042938a + DAT_0042937a);
        DAT_00429358 = DAT_00429358 + -DAT_00428428;
        DAT_00429368 = DAT_00429368 + -1;
        iVar6 = DAT_00429360;
        uVar9 = DAT_0042937e;
        pcVar11 = DAT_00429358;
        DAT_0042938a = puVar10;
      } while (DAT_00429368 != 0 && 0 < iVar7);
    }
    uVar5 = DAT_00429372;
    uVar4 = DAT_0042936e;
    DAT_00429358 = (char *)(DAT_00428428 * DAT_00429364 + DAT_0042935c + _DAT_0042840c);
    DAT_00429360 = DAT_00429360 - (DAT_0042935c + -1);
    DAT_00429368 = DAT_00429368 - (DAT_00429364 + -1);
    iVar6 = DAT_00429360;
    uVar9 = DAT_0042937e;
    pcVar11 = DAT_00429358;
    DAT_0042938a = puVar10;
    do {
      do {
        if ((char)*puVar10 != '\0') {
          *pcVar11 = (char)*puVar10;
        }
        iVar7 = DAT_00429368;
        puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
        iVar6 = iVar6 + -1;
        uVar9 = uVar9 + uVar4;
        pcVar11 = pcVar11 + 1;
      } while (iVar6 != 0);
      bVar12 = CARRY4(_DAT_00429382,DAT_00429376);
      _DAT_00429382 = _DAT_00429382 + DAT_00429376;
      if (bVar12) {
        DAT_0042938a = (ushort *)((int)DAT_0042938a + DAT_00429386);
      }
      puVar10 = (ushort *)((int)DAT_0042938a + DAT_0042937a);
      DAT_00429358 = DAT_00429358 + DAT_00428428;
      DAT_00429368 = DAT_00429368 + -1;
      iVar6 = DAT_00429360;
      uVar9 = DAT_0042937e;
      pcVar11 = DAT_00429358;
      DAT_0042938a = puVar10;
    } while (DAT_00429368 != 0 && 0 < iVar7);
  }
  return;
}


// ==== FUN_0041d59b @ 0041d59b

void __cdecl FUN_0041d59b(undefined4 *param_1,undefined4 *param_2,uint param_3)

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


// ==== FUN_0041d5c8 @ 0041d5c8

undefined8 __cdecl FUN_0041d5c8(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_0041d6b3 @ 0041d6b3

undefined4 __cdecl FUN_0041d6b3(int *param_1,int *param_2)

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


// ==== FUN_0041d6ef @ 0041d6ef

void __cdecl FUN_0041d6ef(int *param_1,int *param_2)

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


// ==== FUN_0041d74c @ 0041d74c

void __cdecl FUN_0041d74c(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_0041d7a2 @ 0041d7a2

undefined4 __cdecl FUN_0041d7a2(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_0041d6b3(param_3,param_2);
  if (iVar1 != 0) {
    FUN_0041d74c(&DAT_0042939c,param_2,param_3);
    DAT_004293ac = ((param_2[2] - *param_2) + 1U & 0xffff) *
                   ((param_2[3] - param_2[1]) + 1U & 0xffff);
    if (((DAT_004293a4 - DAT_0042939c) + 1U & 0xffff) *
        ((DAT_004293a8 - DAT_004293a0) + 1U & 0xffff) <=
        ((param_3[2] - *param_3) + 1U & 0xffff) * ((param_3[3] - param_3[1]) + 1U & 0xffff) +
        DAT_004293ac) {
      *param_1 = DAT_0042939c;
      param_1[1] = DAT_004293a0;
      param_1[2] = DAT_004293a4;
      param_1[3] = DAT_004293a8;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0041d87b @ 0041d87b

int __cdecl FUN_0041d87b(int *param_1)

{
  return (param_1[2] - *param_1) + 1;
}


// ==== FUN_0041d88b @ 0041d88b

int __cdecl FUN_0041d88b(int param_1)

{
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) + 1;
}


// ==== FUN_0041d89c @ 0041d89c

void __cdecl FUN_0041d89c(char *param_1,uint param_2,char param_3)

{
  uint uVar1;
  char *pcVar2;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (*param_1 == param_3) goto LAB_0041d8e2;
LAB_0041d8be:
    if (param_1[1] == param_3) goto LAB_0041d8eb;
LAB_0041d8c5:
    if (param_1[2] == param_3) goto LAB_0041d8f5;
    while (param_1[3] == param_3) {
      while( true ) {
        param_1[3] = '\0';
        param_1 = param_1 + 4;
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) goto LAB_0041d90c;
        if (*param_1 != param_3) goto LAB_0041d8be;
LAB_0041d8e2:
        *param_1 = '\0';
        if (param_1[1] != param_3) goto LAB_0041d8c5;
LAB_0041d8eb:
        param_1[1] = '\0';
        if (param_1[2] != param_3) break;
LAB_0041d8f5:
        param_1[2] = '\0';
        if (param_1[3] != param_3) goto LAB_0041d8d3;
      }
    }
LAB_0041d8d3:
    param_1 = param_1 + 4;
  }
LAB_0041d90c:
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


// ==== FUN_0041d928 @ 0041d928

bool __cdecl FUN_0041d928(char *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  *param_4 = param_2;
  param_4[2] = 0xffffffff;
  param_4[1] = param_3;
  param_4[3] = 0xffffffff;
  uVar2 = 0;
LAB_0041d953:
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
          if (param_3 != 0) goto LAB_0041d953;
          goto LAB_0041d98c;
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
LAB_0041d98c:
      return *param_4 != param_2;
    }
  } while( true );
}


// ==== FUN_0041d9a0 @ 0041d9a0

void FUN_0041d9a0(void)

{
  FUN_0041d9ba();
  FUN_0041d9d9();
  return;
}


// ==== FUN_0041d9ba @ 0041d9ba

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d9ba(void)

{
  _DAT_0043218c = 0x5452494d;
  return;
}


// ==== FUN_0041d9d9 @ 0041d9d9

void FUN_0041d9d9(void)

{
  _atexit(FUN_0041d9f6);
  return;
}


// ==== FUN_0041d9f6 @ 0041d9f6

void FUN_0041d9f6(void)

{
  FUN_0041db88();
  return;
}


// ==== FUN_0041da10 @ 0041da10

bool __cdecl FUN_0041da10(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_004125f2(&DAT_00431ac8,param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_0041e400();
    *puVar2 = DAT_00431ad0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = DAT_00431ad4 + -1;
    puVar2[5] = 0;
    puVar2[6] = DAT_00431ad8 + -1;
    puVar2[7] = DAT_00431adc;
  }
  return iVar1 != 0;
}


// ==== FUN_0041dacf @ 0041dacf

undefined4 * __cdecl FUN_0041dacf(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0041e400();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0041e400();
  *puVar1 = DAT_00431ad0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = DAT_00431ad4 + -1;
  puVar1[5] = 0;
  puVar1[6] = DAT_00431ad8 + -1;
  puVar1[7] = DAT_00431adc;
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_0041db88 @ 0041db88

void FUN_0041db88(void)

{
  FUN_00412940(&DAT_00431ac8);
  return;
}


// ==== FUN_0041dba7 @ 0041dba7

void __cdecl FUN_0041dba7(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0041dbd0 @ 0041dbd0

void __cdecl FUN_0041dbd0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0041dbf9 @ 0041dbf9

uint __cdecl FUN_0041dbf9(int param_1)

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


// ==== FUN_0041dc73 @ 0041dc73

uint __cdecl FUN_0041dc73(int param_1)

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


// ==== FUN_0041dcee @ 0041dcee

uint __cdecl FUN_0041dcee(int param_1)

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


// ==== FUN_0041dd7d @ 0041dd7d

int __cdecl FUN_0041dd7d(int param_1)

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


// ==== FUN_0041de53 @ 0041de53

int __cdecl FUN_0041de53(int param_1)

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


// ==== FUN_0041dec0 @ 0041dec0

void FUN_0041dec0(void)

{
  if (DAT_004321a8 == 0) {
    DAT_004321a8 = 1;
    if (DAT_00432198 != (HWND)0x0) {
      if (DAT_004321ac == (int *)0x0) {
        PostMessageA(DAT_00432198,0x42b,DAT_004321a0,DAT_004321a4);
      }
      else if (*DAT_004321ac != 0) {
        PostMessageA(DAT_00432198,0x42b,DAT_004321a0,DAT_004321a4);
      }
    }
    DAT_004321a8 = 0;
  }
  return;
}


// ==== FUN_0041df5f @ 0041df5f

void FUN_0041df5f(void)

{
  DAT_004321ac = 0;
  DAT_00432198 = 0;
  FUN_0041df88();
  return;
}


// ==== FUN_0041df88 @ 0041df88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041df88(void)

{
  undefined4 uVar1;
  timecaps_tag local_10;
  MMRESULT local_8;
  
  if (DAT_0043219c == 0) {
    local_8 = timeGetDevCaps(&local_10,8);
    if (local_8 == 0x61) {
      uVar1 = 0;
    }
    else {
      DAT_00432194 = local_10.wPeriodMin;
      _DAT_00432190 = local_10.wPeriodMax;
      if (local_10.wPeriodMin <= DAT_004293b0) {
        local_10.wPeriodMin = DAT_004293b0;
      }
      DAT_004321a4 = DAT_004293b4;
      DAT_004321a0 = local_10.wPeriodMin;
      DAT_0043219c = timeSetEvent(local_10.wPeriodMin,DAT_004293b4,FUN_0041dec0,1,1);
      if (DAT_0043219c == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041e03f @ 0041e03f

void __cdecl FUN_0041e03f(undefined4 param_1,undefined4 param_2)

{
  DAT_004321ac = param_2;
  DAT_00432198 = param_1;
  return;
}


// ==== FUN_0041e05f @ 0041e05f

void FUN_0041e05f(void)

{
  DAT_00432198 = 0;
  DAT_004321ac = 0;
  if (DAT_0043219c != 0) {
    timeKillEvent(DAT_0043219c);
    DAT_0043219c = 0;
  }
  return;
}


// ==== FUN_0041e0ab @ 0041e0ab

void __cdecl FUN_0041e0ab(int param_1)

{
  if (param_1 == 0) {
    if (DAT_0043219c != 0) {
      timeKillEvent(DAT_0043219c);
      DAT_0043219c = 0;
    }
  }
  else if ((DAT_0043219c == 0) && (DAT_00432198 != 0)) {
    FUN_0041df88();
  }
  return;
}


// ==== FUN_0041e130 @ 0041e130

void FUN_0041e130(void)

{
  HDC hdc;
  HPALETTE pHVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_004293ba; local_8 = local_8 + 1) {
    (&DAT_004293bc)[local_8 * 4] = 0;
    (&DAT_004293bd)[local_8 * 4] = 0;
    (&DAT_004293be)[local_8 * 4] = 0;
    (&DAT_004293bf)[local_8 * 4] = 4;
  }
  hdc = GetDC((HWND)0x0);
  pHVar1 = CreatePalette((LOGPALETTE *)&DAT_004293b8);
  if (pHVar1 != (HPALETTE)0x0) {
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    RealizePalette(hdc);
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    DeleteObject(pHVar1);
  }
  ReleaseDC((HWND)0x0,hdc);
  return;
}


// ==== FUN_0041e204 @ 0041e204

void __cdecl FUN_0041e204(int param_1,int *param_2)

{
  int iVar1;
  HDC hdc;
  int local_8;
  
  hdc = GetDC((HWND)0x0);
  GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)&DAT_004293bc);
  GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)&DAT_00429794);
  ReleaseDC((HWND)0x0,hdc);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_004293bc)[local_8 * 4];
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_004293bd)[local_8 * 4];
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_004293be)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_004293bf)[local_8 * 4] = 0;
    *(undefined *)(param_1 + 0x3da + local_8 * 4) = (&DAT_00429794)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d9 + local_8 * 4) = (&DAT_00429795)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d8 + local_8 * 4) = (&DAT_00429796)[local_8 * 4];
    *(undefined1 *)(param_1 + 0x3db + local_8 * 4) = 0;
    (&DAT_00429797)[local_8 * 4] = 0;
  }
  iVar1 = *param_2;
  for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
    (&DAT_004293bc)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 2);
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_004293bc)[local_8 * 4];
    (&DAT_004293bd)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 1);
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_004293bd)[local_8 * 4];
    (&DAT_004293be)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1);
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_004293be)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_004293bf)[local_8 * 4] = 4;
  }
  CreatePalette((LOGPALETTE *)&DAT_004293b8);
  return;
}


// ==== FUN_0041e400 @ 0041e400

void FUN_0041e400(void)

{
  FUN_0041c250();
  return;
}


// ==== FUN_0041e415 @ 0041e415

undefined4 * __cdecl FUN_0041e415(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0041e400();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0041e400();
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


// ==== FUN_0041e45e @ 0041e45e

undefined4 FUN_0041e45e(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0041e400();
  return *puVar1;
}


// ==== FUN_0041e475 @ 0041e475

undefined4 FUN_0041e475(void)

{
  int iVar1;
  
  iVar1 = FUN_0041e400();
  return *(undefined4 *)(iVar1 + 0x1c);
}


// ==== FUN_0041e48d @ 0041e48d

void __cdecl FUN_0041e48d(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  FUN_0041c256(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0041e4b9 @ 0041e4b9

void __cdecl FUN_0041e4b9(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0041c9c6(param_1,param_2,param_3);
  return;
}


// ==== FUN_0041e4dd @ 0041e4dd

void __thiscall FUN_0041e4dd(void *this,int *param_1,int param_2)

{
  FUN_0041c57f(this,param_1,param_2);
  return;
}


// ==== FUN_0041e501 @ 0041e501

void __cdecl FUN_0041e501(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0041cd38(param_1,param_2,param_3);
  return;
}


// ==== FUN_0041e525 @ 0041e525

void __cdecl FUN_0041e525(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  FUN_0041d0ae(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0041e551 @ 0041e551

void __cdecl FUN_0041e551(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    FUN_0041d6ef(param_1,param_1);
  }
  else {
    FUN_0041d6ef(param_1,param_2);
  }
  return;
}


// ==== FID_conflict:_memcpy @ 0041e590

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
switchD_0041e659_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0041e659_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0041e659_caseD_3:
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
        goto switchD_0041e659_caseD_1;
      case 2:
        goto switchD_0041e659_caseD_2;
      case 3:
        goto switchD_0041e659_caseD_3;
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
switchD_0041e5c0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0041e5c0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0041e5c0_caseD_3:
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
      goto switchD_0041e5c0_caseD_1;
    case 2:
      goto switchD_0041e5c0_caseD_2;
    case 3:
      goto switchD_0041e5c0_caseD_3;
    }
  }
  return _Dst;
}


// ==== FUN_0041e6e0 @ 0041e6e0

uint * __cdecl FUN_0041e6e0(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0041e7c8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0041e7c8:
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


// ==== FUN_0041e6f0 @ 0041e6f0

uint * __cdecl FUN_0041e6f0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0041e70c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0041e73f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0041e75b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0041e70c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0041e75b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0041e75b;
    }
  }
LAB_0041e73f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0041e75b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0041e7c8:
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
    if (bVar1 == 0) goto LAB_0041e7c8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _memset @ 0041e7d0

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


// ==== _strlen @ 0041e830

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0041e850;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0041e883:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0041e850:
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
  goto LAB_0041e883;
}


// ==== _strncmp @ 0041e8b0

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


// ==== _strcmp @ 0041e8f0

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
      if (bVar4 != *_Str2) goto LAB_0041e934;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0041e900;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0041e934;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0041e934;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0041e900:
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
LAB_0041e934:
  return (uint)bVar5 * -2 + 1;
}


// ==== _rand @ 0041e980

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_004297c0 = DAT_004297c0 * 0x343fd + 0x269ec3;
  return (DAT_004297c0 & 0x7fff0000) >> 0x10;
}


// ==== __onexit @ 0041e9b0

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = __msize(DAT_0043341c);
  if (sVar1 < (uint)((int)DAT_00433418 + (4 - (int)DAT_0043341c))) {
    sVar1 = __msize(DAT_0043341c);
    pvVar2 = _realloc(DAT_0043341c,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      return (_onexit_t)0x0;
    }
    DAT_00433418 = (undefined4 *)
                   (((int)DAT_00433418 - (int)DAT_0043341c & 0xfffffffcU) + (int)pvVar2);
    DAT_0043341c = pvVar2;
  }
  *DAT_00433418 = _Func;
  DAT_00433418 = DAT_00433418 + 1;
  return _Func;
}


// ==== _atexit @ 0041ea30

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}


// ==== __global_unwind2 @ 0041ea88

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x41eaa0,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0041eaca

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
  puStack_18 = &LAB_0041eaa8;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0041eb5e();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== __abnormal_termination @ 0041eb32

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
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_0041eaa8) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_0041eb55 @ 0041eb55

void __fastcall FUN_0041eb55(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_004297cc = param_1;
  DAT_004297c8 = in_EAX;
  DAT_004297d0 = unaff_EBP;
  return;
}


// ==== FUN_0041eb5e @ 0041eb5e

void FUN_0041eb5e(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004297cc = *(undefined4 *)(unaff_EBP + 8);
  DAT_004297c8 = in_EAX;
  DAT_004297d0 = unaff_EBP;
  return;
}


// ==== _JumpToContinuation @ 0041eb80

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0041ebac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== _CallMemberFunction0 @ 0041ebc0

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ebc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 0041ebd0

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ebd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 0041ebe0

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0041ebe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== _UnwindNestedFrames @ 0041ebf0

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x41ec1c,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}


// ==== ___CxxFrameHandler @ 0041ec50

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


// ==== _CallCatchBlock2 @ 0041ec90

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
  local_10 = &LAB_0041ed00;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== _CallSETranslator @ 0041ed30

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
  local_14 = 0x41edc7;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_00429860)(*(undefined4 *)param_1,&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}


// ==== TranslatorGuardHandler @ 0041ee10

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
                    /* WARNING: Could not recover jumptable at 0x0041ee6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// ==== FUN_0041ee80 @ 0041ee80

void __cdecl FUN_0041ee80(void *param_1)

{
  _free(param_1);
  return;
}


// ==== `eh_vector_destructor_iterator' @ 0041ee90

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
  puStack_c = &DAT_00426008;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_0041ef00();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_0041ef00 @ 0041ef00

void FUN_0041ef00(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== __ArrayUnwind @ 0041ef20

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
  puStack_c = &DAT_00426018;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== `eh_vector_constructor_iterator' @ 0041efc0

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
  puStack_c = &DAT_00426028;
  puStack_10 = &LAB_0042032c;
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
  FUN_0041f030();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_0041f030 @ 0041f030

void FUN_0041f030(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== __ftol @ 0041f04c

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== __fpmath @ 0041f080

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_0041f0b0();
  _DAT_004297e0 = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


// ==== FUN_0041f0b0 @ 0041f0b0

void FUN_0041f0b0(void)

{
  PTR_FUN_00429874 = &LAB_00420520;
  PTR_FUN_00429878 = &LAB_004205a0;
  PTR_FUN_0042987c = &LAB_004204b0;
  PTR_FUN_00429880 = &LAB_00420580;
  PTR_FUN_00429870 = &LAB_00420940;
  PTR_FUN_00429884 = &LAB_00420940;
  return;
}


// ==== operator_new @ 0041f0f0

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== _sprintf @ 0041f100

/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 1998 Release */

int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  FILE local_20;
  
  local_20._flag = 0x42;
  local_20._base = _Dest;
  local_20._ptr = _Dest;
  local_20._cnt = 0x7fffffff;
  iVar1 = __output(&local_20,(byte *)_Format,(undefined4 *)&stack0x0000000c);
  local_20._cnt = local_20._cnt + -1;
  if (-1 < local_20._cnt) {
    *local_20._ptr = '\0';
    return iVar1;
  }
  __flsbuf(0,&local_20);
  return iVar1;
}


// ==== _free @ 0041f170

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
    HeapFree(DAT_00433414,0,_Memory);
  }
  return;
}


// ==== _malloc @ 0041f1c0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0042a0c0);
  return pvVar1;
}


// ==== __nh_malloc @ 0041f1e0

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


// ==== __heap_alloc @ 0041f230

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_0042a0bc) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_00433414,0,dwBytes);
  return pvVar2;
}


// ==== entry @ 0041f270

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
  undefined4 uVar7;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_00426038;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0042981c = DVar2 >> 8 & 0xff;
  DAT_00429810 = DVar2 >> 0x10;
  _DAT_00429818 = DVar2 & 0xff;
  _DAT_00429814 = _DAT_00429818 * 0x100 + _DAT_0042981c;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00433420 = (byte *)GetCommandLineA();
  DAT_004297f0 = ___crtGetEnvironmentStringsA();
  if ((DAT_004297f0 == (LPVOID)0x0) || (DAT_00433420 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_00433420;
  pbVar6 = DAT_00433420;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_00433420 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_0041f375;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_0041f375:
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
  _Code = FUN_00411854(pHVar5,uVar7,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0041f410

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_004297fc == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_004297f8)(0xff);
  return;
}


// ==== __cinit @ 0041f440

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (PTR___fpmath_004297e4 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_004297e4)();
  }
  __initterm((undefined4 *)&DAT_00427044,(undefined4 *)&DAT_00427050);
  iVar1 = __initterm((undefined4 *)&DAT_00427000,(undefined4 *)&DAT_00427040);
  return iVar1;
}


// ==== _exit @ 0041f470

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0041f490

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0041f4b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0042984c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00429848 = 1;
  DAT_00429844 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0043341c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00433418 + -4), DAT_0043341c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0043341c <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00427054,(undefined4 *)&DAT_0042705c);
  }
  __initterm((undefined4 *)&DAT_00427060,(undefined4 *)&DAT_00427064);
  if (param_3 == 0) {
    DAT_0042984c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0041f560

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


// ==== _realloc @ 0041f580

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
          local_c = HeapReAlloc(DAT_00433414,0,_Memory,_NewSize);
        }
        else {
          if (_NewSize < DAT_0042a0bc) {
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
          local_c = HeapAlloc(DAT_00433414,0,_NewSize);
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
      if ((local_c != (undefined4 *)0x0) || (DAT_0042a0c0 == 0)) {
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


// ==== __msize @ 0041f730

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
  SVar2 = HeapSize(DAT_00433414,0,_Memory);
  return SVar2;
}


// ==== ___InternalCxxFrameHandler @ 0041f780

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


// ==== FindHandler @ 0041f840

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
  pEVar4 = DAT_00429854;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_00429854 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_00429854;
    param_3 = DAT_00429858;
    iVar5 = _ValidateRead(DAT_00429854,1);
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
LAB_0041f9f6:
                bVar12 = true;
              }
              else {
                if (*(int *)(pbVar3 + 4) == iVar10) {
LAB_0041f9ce:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_0041f9f6;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_0041f9c5:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_0041f9ca;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_0041f9c5;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_0041f9ca:
                  if (iVar10 == 0) goto LAB_0041f9ce;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_0041fa54;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_0041fa54:
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


// ==== FindHandlerForForeignException @ 0041fae0

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
  
  if (((DAT_00429860 == 0) ||
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


// ==== GetRangeOfTrysToCheck @ 0041fbc0

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


// ==== ___FrameUnwindToState @ 0041fc60

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
  puStack_c = &DAT_00426048;
  puStack_10 = &LAB_0042032c;
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


// ==== CatchIt @ 0041fd50

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


// ==== CallCatchBlock @ 0041fdf0

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
  puStack_c = &DAT_00426058;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &local_14;
  DAT_00429854 = param_1;
  DAT_00429858 = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0041feb5();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== FUN_0041feb5 @ 0041feb5

void FUN_0041feb5(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  **(undefined4 **)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
  DAT_00429854 = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_00429858 = *(undefined4 *)(unaff_EBP + -0x24);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (*(int *)(unaff_EBP + -0x1c) != 0)) {
    iVar2 = __abnormal_termination();
    DestructExceptionObject(*(EHExceptionRecord **)(unaff_EBP + 8),(uchar)iVar2);
  }
  return;
}


// ==== BuildCatchObject @ 0041ff30

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
  puStack_c = &DAT_00426070;
  puStack_10 = &LAB_0042032c;
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
            goto LAB_0042011e;
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
            goto LAB_0042011e;
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
          goto LAB_0042011e;
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
        goto LAB_0042011e;
      }
    }
    _inconsistency();
  }
LAB_0042011e:
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== DestructExceptionObject @ 00420130

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
  puStack_c = &DAT_00426080;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== AdjustPointer @ 004201b0

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


// ==== __CallSettingFrame@12 @ 004201e0

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_0041eb55(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_0041eb55(param_3);
  return;
}


// ==== terminate @ 00420230

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
  puStack_c = &DAT_00426090;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_00429864 != (code *)0x0) {
    local_8 = 1;
    (*DAT_00429864)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 004202b0

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
  puStack_c = &DAT_004260a8;
  puStack_10 = &LAB_0042032c;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_terminate_0042986c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_terminate_0042986c)();
  }
  local_8 = 0xffffffff;
  terminate();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_004203e9 @ 004203e9

void FUN_004203e9(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __setdefaultprecision @ 00420410

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 00420430

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 00420480

/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 1998 Release */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  __ms_p5_test_fdiv();
  return;
}


// ==== __cftoe @ 004205f0

/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftoe(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec,int _Caps)

{
  int *_Digits;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  STRFLT unaff_EBP;
  bool bVar4;
  
  _Digits = DAT_004321b0;
  if (DAT_00429888 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (uint)(*_Digits == 0x2d) + (uint)(0 < (int)_SizeInBytes),_SizeInBytes + 1,
              (int)_Digits,unaff_EBP);
  }
  else {
    __shift(_Buf + (*DAT_004321b0 == 0x2d),(uint)(0 < (int)_SizeInBytes));
  }
  pcVar1 = _Buf;
  if (*_Digits == 0x2d) {
    pcVar1 = _Buf + 1;
    *_Buf = '-';
  }
  pcVar2 = pcVar1;
  if (0 < (int)_SizeInBytes) {
    pcVar2 = pcVar1 + 1;
    *pcVar1 = *pcVar2;
    *pcVar2 = DAT_0042a418;
  }
  bVar4 = DAT_00429888 == '\0';
  *(undefined4 *)(pcVar2 + _SizeInBytes + bVar4) = DAT_00426108;
  *(undefined2 *)(pcVar2 + _SizeInBytes + bVar4 + 4) = DAT_0042610c;
  pcVar2 = pcVar2 + (DAT_00429888 == '\0') + _SizeInBytes;
  if (_Dec != 0) {
    *pcVar2 = 'E';
  }
  if (*(char *)_Digits[3] != '0') {
    iVar3 = _Digits[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      pcVar2[1] = '-';
    }
    if (99 < iVar3) {
      pcVar2[2] = pcVar2[2] + (char)(iVar3 / 100);
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      pcVar2[3] = pcVar2[3] + (char)(iVar3 / 10);
      iVar3 = iVar3 % 10;
    }
    pcVar2[4] = pcVar2[4] + (char)iVar3;
  }
  return (errno_t)_Buf;
}


// ==== __cftof @ 00420730

/* Library Function - Single Match
    __cftof
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftof(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec)

{
  int iVar1;
  int *_Digits;
  uint uVar2;
  uint uVar3;
  STRFLT unaff_EBP;
  char *pcVar4;
  char *pcVar5;
  
  _Digits = DAT_004321b0;
  if (DAT_00429888 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (*_Digits == 0x2d),_Digits[1] + _SizeInBytes,(int)_Digits,unaff_EBP);
  }
  else if (DAT_0042988c == _SizeInBytes) {
    iVar1 = DAT_0042988c + (*DAT_004321b0 == 0x2d);
    _Buf[iVar1] = '0';
    (_Buf + iVar1)[1] = '\0';
  }
  pcVar5 = _Buf;
  if (*_Digits == 0x2d) {
    pcVar5 = _Buf + 1;
    *_Buf = '-';
  }
  if (_Digits[1] < 1) {
    pcVar4 = pcVar5 + 1;
    __shift(pcVar5,1);
    *pcVar5 = '0';
  }
  else {
    pcVar4 = pcVar5 + _Digits[1];
  }
  if (0 < (int)_SizeInBytes) {
    __shift(pcVar4,1);
    *pcVar4 = DAT_0042a418;
    iVar1 = _Digits[1];
    if (iVar1 < 0) {
      if (DAT_00429888 == '\0') {
        uVar3 = -iVar1;
        if ((int)_SizeInBytes <= -iVar1) {
          uVar3 = _SizeInBytes;
        }
      }
      else {
        uVar3 = -iVar1;
      }
      __shift(pcVar4 + 1,uVar3);
      uVar2 = uVar3 >> 2;
      pcVar5 = pcVar4 + 1;
      while (uVar2 != 0) {
        uVar2 = uVar2 - 1;
        builtin_strncpy(pcVar5,"0000",4);
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar5 = '0';
        pcVar5 = pcVar5 + 1;
      }
    }
  }
  return (errno_t)_Buf;
}


// ==== __cftog @ 00420830

/* Library Function - Single Match
    __cftog
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftog(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  STRFLT unaff_EBP;
  bool bVar5;
  
  DAT_004321b0 = (int *)__fltout();
  DAT_0042988c = DAT_004321b0[1] + -1;
  iVar1 = *DAT_004321b0;
  __fptostr(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_004321b0,unaff_EBP);
  DAT_00429890 = DAT_0042988c < DAT_004321b0[1] + -1;
  iVar3 = DAT_004321b0[1] + -1;
  if ((-5 < iVar3) && (iVar3 < (int)param_3)) {
    bVar5 = DAT_0042988c < DAT_004321b0[1] + -1;
    pcVar2 = param_2 + (iVar1 == 0x2d);
    DAT_0042988c = iVar3;
    if (bVar5) {
      do {
        pcVar4 = pcVar2;
        pcVar2 = pcVar4 + 1;
      } while (*pcVar4 != '\0');
      pcVar4[-1] = '\0';
    }
    __cftof_g(param_1,param_2,param_3);
    return;
  }
  DAT_0042988c = iVar3;
  __cftoe_g(param_1,param_2,param_3,param_4);
  return;
}


// ==== __cftoe_g @ 004208e0

/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftoe_g(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int unaff_retaddr;
  
  DAT_00429888 = 1;
  __cftoe(param_1,param_2,param_3,param_4,unaff_retaddr);
  DAT_00429888 = 0;
  return;
}


// ==== __cftof_g @ 00420910

/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftof_g(double *param_1,char *param_2,size_t param_3)

{
  int unaff_retaddr;
  
  DAT_00429888 = 1;
  __cftof(param_1,param_2,param_3,unaff_retaddr);
  DAT_00429888 = 0;
  return;
}


// ==== __shift @ 004209b0

/* Library Function - Single Match
    __shift
   
   Library: Visual Studio 1998 Release */

void __cdecl __shift(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 != 0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FID_conflict__memcpy(param_1 + param_2,param_1,~uVar2);
  }
  return;
}


// ==== __flsbuf @ 004209e0

/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 1998 Release */

int __cdecl __flsbuf(int _Ch,FILE *_File)

{
  uint _FileHandle;
  FILE *_File_00;
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  _File_00 = _File;
  _FileHandle = _File->_file;
  uVar3 = _File->_flag;
  if (((uVar3 & 0x82) == 0) || ((uVar3 & 0x40) != 0)) {
    _File->_flag = uVar3 | 0x20;
    return -1;
  }
  if ((uVar3 & 1) != 0) {
    _File->_cnt = 0;
    if ((_File->_flag & 0x10U) == 0) {
      _File->_flag = _File->_flag | 0x20;
      return -1;
    }
    _File->_ptr = _File->_base;
    _File->_flag = _File->_flag & 0xfffffffe;
  }
  uVar3 = _File->_flag;
  uVar4 = 0;
  _File->_flag = uVar3 | 2;
  _File->_flag = uVar3 & 0xffffffef | 2;
  _File->_cnt = 0;
  if ((_File->_flag & 0x10cU) == 0) {
    if ((_File == (FILE *)&DAT_0042a680) || (_File == (FILE *)&DAT_0042a6a0)) {
      iVar1 = __isatty(_FileHandle);
      if (iVar1 != 0) goto LAB_00420a64;
    }
    __getbuf(_File_00);
  }
LAB_00420a64:
  if ((_File_00->_flag & 0x108U) == 0) {
    uVar3 = 1;
    uVar4 = __write(_FileHandle,&_Ch,1);
  }
  else {
    uVar3 = (int)_File_00->_ptr - (int)_File_00->_base;
    _File_00->_ptr = _File_00->_base + 1;
    _File_00->_cnt = _File_00->_bufsiz + -1;
    if ((int)uVar3 < 1) {
      puVar2 = &DAT_0042a378;
      if (_FileHandle != 0xffffffff) {
        puVar2 = (undefined *)
                 (*(int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7) >> 3)) +
                 (_FileHandle & 0x1f) * 8);
      }
      if ((puVar2[4] & 0x20) != 0) {
        __lseek(_FileHandle,0,2);
      }
    }
    else {
      uVar4 = __write(_FileHandle,_File_00->_base,uVar3);
    }
    *_File_00->_base = (char)_Ch;
  }
  if (uVar4 != uVar3) {
    _File_00->_flag = _File_00->_flag | 0x20;
    return -1;
  }
  return _Ch & 0xff;
}


// ==== __output @ 00420b30

/* Library Function - Single Match
    __output
   
   Library: Visual Studio 1998 Release */

int __cdecl __output(FILE *param_1,byte *param_2,undefined4 *param_3)

{
  char cVar1;
  byte *pbVar2;
  wchar_t wVar3;
  uint uVar4;
  undefined1 *puVar5;
  short *psVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  byte bVar10;
  undefined1 *puVar11;
  wchar_t *pwVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  char *pcVar15;
  undefined8 uVar16;
  char local_246;
  char local_245;
  char local_244 [4];
  wchar_t *local_240;
  undefined8 local_23c;
  int local_234;
  undefined8 local_230;
  int local_228;
  int local_224;
  int local_220;
  int local_21c;
  uint local_218;
  int local_214;
  int local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined1 uStack_1;
  
  local_234 = 0;
  bVar10 = *param_2;
  local_21c = 0;
  pbVar2 = param_2;
  puVar5 = local_200;
  puVar14 = local_200;
  puVar11 = local_200;
  do {
    if ((bVar10 == 0) || (param_2 = pbVar2 + 1, local_234 < 0)) {
      return local_234;
    }
    if (((char)bVar10 < ' ') || ('x' < (char)bVar10)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(byte *)((int)&DAT_00426108 + (int)(char)bVar10) & 0xf;
    }
    local_21c = (int)((char)(&DAT_00426128)[uVar4 * 8 + local_21c] >> 4);
    switch(local_21c) {
    case 0:
switchD_00420bb5_caseD_0:
      local_220 = 0;
      if ((PTR_DAT_0042a420[(uint)bVar10 * 2 + 1] & 0x80) != 0) {
        write_char((int)(char)bVar10,param_1,&local_234);
        bVar10 = *param_2;
        param_2 = pbVar2 + 2;
      }
      write_char((int)(char)bVar10,param_1,&local_234);
      break;
    case 1:
      local_20c = 0;
      puVar14 = (undefined1 *)0x0;
      puVar5 = (undefined1 *)0xffffffff;
      local_210 = 0;
      local_228 = 0;
      local_224 = 0;
      local_220 = 0;
      break;
    case 2:
      switch(bVar10) {
      case 0x20:
        puVar14 = (undefined1 *)((uint)puVar14 | 2);
        break;
      case 0x23:
        puVar14 = (undefined1 *)((uint)puVar14 | 0x80);
        break;
      case 0x2b:
        puVar14 = (undefined1 *)((uint)puVar14 | 1);
        break;
      case 0x2d:
        puVar14 = (undefined1 *)((uint)puVar14 | 4);
        break;
      case 0x30:
        puVar14 = (undefined1 *)((uint)puVar14 | 8);
      }
      break;
    case 3:
      if (bVar10 == 0x2a) {
        local_228 = get_int_arg((int *)&param_3);
        if (local_228 < 0) {
          local_228 = -local_228;
          puVar14 = (undefined1 *)((uint)puVar14 | 4);
        }
      }
      else {
        local_228 = (char)bVar10 + -0x30 + local_228 * 10;
      }
      break;
    case 4:
      puVar5 = (undefined1 *)0x0;
      break;
    case 5:
      if (bVar10 == 0x2a) {
        puVar5 = (undefined1 *)get_int_arg((int *)&param_3);
        if ((int)puVar5 < 0) {
          puVar5 = (undefined1 *)0xffffffff;
        }
      }
      else {
        puVar5 = (undefined1 *)((char)bVar10 + -0x30 + (int)puVar5 * 10);
      }
      break;
    case 6:
      switch(bVar10) {
      case 0x49:
        if ((*param_2 != 0x36) || (pbVar2[2] != 0x34)) {
          local_21c = 0;
          goto switchD_00420bb5_caseD_0;
        }
        param_2 = pbVar2 + 3;
        puVar14 = (undefined1 *)((uint)puVar14 | 0x8000);
        break;
      case 0x68:
        puVar14 = (undefined1 *)((uint)puVar14 | 0x20);
        break;
      case 0x6c:
        puVar14 = (undefined1 *)((uint)puVar14 | 0x10);
        break;
      case 0x77:
        puVar14 = (undefined1 *)((uint)puVar14 | 0x800);
      }
      break;
    case 7:
      pwVar12 = local_240;
      puVar13 = puVar5;
      switch(bVar10) {
      case 0x43:
        if (((uint)puVar14 & 0x830) == 0) {
          puVar14 = (undefined1 *)((uint)puVar14 | 0x800);
        }
      case 99:
        if (((uint)puVar14 & 0x810) == 0) {
          puVar11 = (undefined1 *)0x1;
          uVar8 = get_int_arg((int *)&param_3);
          local_200 = (undefined1 *)CONCAT31(local_200._1_3_,(char)uVar8);
        }
        else {
          wVar3 = get_short_arg(&param_3);
          puVar11 = (undefined1 *)_wctomb((char *)&local_200,wVar3);
          if ((int)puVar11 < 0) {
            local_210 = 1;
          }
        }
        pwVar12 = (wchar_t *)&local_200;
        break;
      case 0x45:
      case 0x47:
        local_20c = 1;
        bVar10 = bVar10 + 0x20;
      case 0x65:
      case 0x66:
      case 0x67:
        puVar13 = (undefined1 *)((uint)puVar14 | 0x40);
        local_240 = (wchar_t *)&local_200;
        if ((int)puVar5 < 0) {
          puVar5 = (undefined1 *)0x6;
        }
        else if ((puVar5 == (undefined1 *)0x0) && (bVar10 == 0x67)) {
          puVar5 = (undefined1 *)0x1;
        }
        local_208 = *param_3;
        local_204 = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)PTR_FUN_00429870)(&local_208,&local_200,(int)(char)bVar10,puVar5,local_20c);
        if ((((uint)puVar14 & 0x80) != 0) && (puVar5 == (undefined1 *)0x0)) {
          (*(code *)PTR_FUN_0042987c)(&local_200);
        }
        if ((bVar10 == 0x67) && (((uint)puVar14 & 0x80) == 0)) {
          (*(code *)PTR_FUN_00429874)(&local_200);
        }
        if ((char)local_200 == '-') {
          puVar13 = (undefined1 *)((uint)puVar14 | 0x140);
          local_240 = (wchar_t *)((int)&local_200 + 1);
        }
        uVar4 = 0xffffffff;
        pwVar12 = local_240;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          wVar3 = *pwVar12;
          pwVar12 = (wchar_t *)((int)pwVar12 + 1);
        } while ((char)wVar3 != '\0');
        puVar11 = (undefined1 *)(~uVar4 - 1);
        puVar14 = puVar13;
        pwVar12 = local_240;
        break;
      case 0x53:
        if (((uint)puVar14 & 0x830) == 0) {
          puVar14 = (undefined1 *)((uint)puVar14 | 0x800);
        }
      case 0x73:
        puVar11 = (undefined1 *)0x7fffffff;
        if (puVar5 != (undefined1 *)0xffffffff) {
          puVar11 = puVar5;
        }
        local_240 = (wchar_t *)get_int_arg((int *)&param_3);
        if (((uint)puVar14 & 0x810) == 0) {
          pwVar12 = local_240;
          if (local_240 == (wchar_t *)0x0) {
            local_240 = (wchar_t *)PTR_DAT_00429894;
            pwVar12 = (wchar_t *)PTR_DAT_00429894;
          }
          for (; (puVar11 != (undefined1 *)0x0 && (puVar11 = puVar11 + -1, (char)*pwVar12 != '\0'));
              pwVar12 = (wchar_t *)((int)pwVar12 + 1)) {
          }
          puVar11 = (undefined1 *)((int)pwVar12 - (int)local_240);
          pwVar12 = local_240;
        }
        else {
          if (local_240 == (wchar_t *)0x0) {
            local_240 = (wchar_t *)PTR_DAT_00429898;
          }
          local_220 = 1;
          for (pwVar12 = local_240;
              (puVar11 != (undefined1 *)0x0 && (puVar11 = puVar11 + -1, *pwVar12 != L'\0'));
              pwVar12 = pwVar12 + 1) {
          }
          puVar11 = (undefined1 *)((int)pwVar12 - (int)local_240 >> 1);
          pwVar12 = local_240;
        }
        break;
      case 0x5a:
        psVar6 = (short *)get_int_arg((int *)&param_3);
        if ((psVar6 == (short *)0x0) ||
           (pwVar12 = *(wchar_t **)(psVar6 + 2), pwVar12 == (wchar_t *)0x0)) {
          uVar4 = 0xffffffff;
          local_240 = (wchar_t *)PTR_DAT_00429894;
          pcVar15 = PTR_DAT_00429894;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar15;
            pcVar15 = pcVar15 + 1;
          } while (cVar1 != '\0');
          puVar11 = (undefined1 *)(~uVar4 - 1);
          pwVar12 = local_240;
        }
        else if (((uint)puVar14 & 0x800) == 0) {
          local_220 = 0;
          puVar11 = (undefined1 *)(int)*psVar6;
        }
        else {
          local_220 = 1;
          puVar11 = (undefined1 *)((uint)(int)*psVar6 >> 1);
        }
        break;
      case 100:
      case 0x69:
        local_218 = 10;
        puVar14 = (undefined1 *)((uint)puVar14 | 0x40);
        goto LAB_00420f97;
      case 0x6e:
        piVar7 = (int *)get_int_arg((int *)&param_3);
        if (((uint)puVar14 & 0x20) == 0) {
          *piVar7 = local_234;
        }
        else {
          *(short *)piVar7 = (short)local_234;
        }
        local_210 = 1;
        pwVar12 = local_240;
        break;
      case 0x6f:
        local_218 = 8;
        if (((uint)puVar14 & 0x80) != 0) {
          puVar14 = (undefined1 *)((uint)puVar14 | 0x200);
        }
        goto LAB_00420f97;
      case 0x70:
        puVar5 = (undefined1 *)0x8;
      case 0x58:
        local_214 = 7;
        goto LAB_00420f70;
      case 0x75:
        local_218 = 10;
        goto LAB_00420f97;
      case 0x78:
        local_214 = 0x27;
LAB_00420f70:
        local_218 = 0x10;
        puVar13 = puVar5;
        if (((uint)puVar14 & 0x80) != 0) {
          local_246 = '0';
          local_224 = 2;
          local_245 = (char)local_214 + 'Q';
        }
LAB_00420f97:
        if (((uint)puVar14 & 0x8000) == 0) {
          if (((uint)puVar14 & 0x20) == 0) {
            if (((uint)puVar14 & 0x40) == 0) {
              uVar4 = get_int_arg((int *)&param_3);
              goto LAB_00421036;
            }
            iVar9 = get_int_arg((int *)&param_3);
            local_23c = (ulonglong)iVar9;
          }
          else if (((uint)puVar14 & 0x40) == 0) {
            uVar4 = get_int_arg((int *)&param_3);
            uVar4 = uVar4 & 0xffff;
LAB_00421036:
            local_23c = (ulonglong)uVar4;
          }
          else {
            uVar8 = get_int_arg((int *)&param_3);
            local_23c = (ulonglong)(int)(short)uVar8;
          }
        }
        else {
          local_23c = get_int64_arg((int *)&param_3);
        }
        if (((((uint)puVar14 & 0x40) == 0) || (0 < local_23c._4_4_)) || (-1 < (longlong)local_23c))
        {
          local_230 = local_23c;
        }
        else {
          puVar14 = (undefined1 *)((uint)puVar14 | 0x100);
          local_230 = CONCAT44(-(local_23c._4_4_ + (uint)((uint)local_23c != 0)),-(uint)local_23c);
        }
        if (((uint)puVar14 & 0x8000) == 0) {
          local_230 = local_230 & 0xffffffff;
        }
        if ((int)puVar13 < 0) {
          puVar13 = (undefined1 *)0x1;
        }
        else {
          puVar14 = (undefined1 *)((uint)puVar14 & 0xfffffff7);
        }
        pwVar12 = (wchar_t *)register0x00000010;
        if ((local_230._4_4_ == 0) && ((uint)local_230 == 0)) {
          local_224 = 0;
        }
        while( true ) {
          local_240 = (wchar_t *)((int)pwVar12 + -1);
          puVar5 = puVar13 + -1;
          if ((((int)puVar13 < 1) && (local_230._4_4_ == 0)) && ((uint)local_230 == 0)) break;
          uVar4 = (int)local_218 >> 0x1f;
          local_23c = (ulonglong)(int)local_218;
          uVar16 = __aullrem((uint)local_230,local_230._4_4_,local_218,uVar4);
          iVar9 = (int)uVar16 + 0x30;
          local_230 = __aulldiv((uint)local_230,local_230._4_4_,(uint)local_23c,uVar4);
          if (0x39 < iVar9) {
            iVar9 = iVar9 + local_214;
          }
          *(char *)local_240 = (char)iVar9;
          puVar13 = puVar5;
          pwVar12 = local_240;
        }
        puVar11 = &uStack_1 + -(int)local_240;
        if ((((uint)puVar14 & 0x200) != 0) &&
           (((char)*pwVar12 != '0' || (puVar11 == (undefined1 *)0x0)))) {
          puVar11 = &stack0x00000000 + -(int)local_240;
          *(char *)local_240 = '0';
          pwVar12 = local_240;
        }
      }
      local_240 = pwVar12;
      if (local_210 == 0) {
        if (((uint)puVar14 & 0x40) != 0) {
          if (((uint)puVar14 & 0x100) == 0) {
            if (((uint)puVar14 & 1) == 0) {
              if (((uint)puVar14 & 2) == 0) goto LAB_004212a9;
              local_246 = ' ';
            }
            else {
              local_246 = '+';
            }
          }
          else {
            local_246 = '-';
          }
          local_224 = 1;
        }
LAB_004212a9:
        iVar9 = (local_228 - (int)puVar11) - local_224;
        local_230 = CONCAT44(local_230._4_4_,iVar9);
        if (((uint)puVar14 & 0xc) == 0) {
          write_multi_char(0x20,iVar9,param_1,&local_234);
        }
        write_string(&local_246,local_224,param_1,&local_234);
        if ((((uint)puVar14 & 8) != 0) && (((uint)puVar14 & 4) == 0)) {
          write_multi_char(0x30,(uint)local_230,param_1,&local_234);
        }
        if ((local_220 == 0) || ((int)puVar11 < 1)) {
          write_string((char *)local_240,(int)puVar11,param_1,&local_234);
        }
        else {
          local_23c = CONCAT44(local_23c._4_4_,puVar11 + -1);
          pwVar12 = local_240;
          do {
            wVar3 = *pwVar12;
            pwVar12 = pwVar12 + 1;
            iVar9 = _wctomb(local_244,wVar3);
            if (iVar9 < 1) break;
            write_string(local_244,iVar9,param_1,&local_234);
            iVar9 = (uint)local_23c;
            local_23c = CONCAT44(local_23c._4_4_,(uint)local_23c + -1);
          } while (iVar9 != 0);
        }
        if (((uint)puVar14 & 4) != 0) {
          write_multi_char(0x20,(uint)local_230,param_1,&local_234);
        }
      }
    }
    bVar10 = *param_2;
    pbVar2 = param_2;
  } while( true );
}


// ==== write_char @ 004214e0

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 1998 Release */

void __cdecl write_char(int param_1,FILE *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_2->_cnt + -1;
  param_2->_cnt = iVar1;
  if (iVar1 < 0) {
    uVar2 = __flsbuf(param_1,param_2);
  }
  else {
    *param_2->_ptr = (char)param_1;
    uVar2 = (uint)(byte)*param_2->_ptr;
    param_2->_ptr = param_2->_ptr + 1;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}


// ==== write_multi_char @ 00421530

/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 1998 Release */

void __cdecl write_multi_char(int param_1,int param_2,FILE *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    write_char(param_1,param_3,param_4);
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}


// ==== write_string @ 00421570

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 1998 Release */

void __cdecl write_string(char *param_1,int param_2,FILE *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    write_char((int)*param_1,param_3,param_4);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}


// ==== get_int_arg @ 004215b0

/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl get_int_arg(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}


// ==== get_int64_arg @ 004215c0

/* Library Function - Single Match
    _get_int64_arg
   
   Library: Visual Studio 1998 Release */

undefined8 __cdecl get_int64_arg(int *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}


// ==== get_short_arg @ 004215e0

/* Library Function - Single Match
    _get_short_arg
   
   Library: Visual Studio 1998 Release */

undefined2 __cdecl get_short_arg(undefined4 *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)*param_1;
  *param_1 = puVar1 + 2;
  return *puVar1;
}


// ==== __heap_init @ 004215f0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_00433414 = HeapCreate(1,0x1000,0);
  if (DAT_00433414 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_00433414);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 00421630

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
  
  if (DAT_0042a0b0 == 0) {
    lpMem = &PTR_LOOP_004298a0;
  }
  else {
    lpMem = HeapAlloc(DAT_00433414,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_004298a0) {
        if (PTR_LOOP_004298a0 == (undefined *)0x0) {
          PTR_LOOP_004298a0 = (undefined *)&PTR_LOOP_004298a0;
        }
        if (PTR_LOOP_004298a4 == (undefined *)0x0) {
          PTR_LOOP_004298a4 = (undefined *)&PTR_LOOP_004298a0;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_004298a0;
        lpMem[1] = PTR_LOOP_004298a4;
        PTR_LOOP_004298a4 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_004298a0) {
    HeapFree(DAT_00433414,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 004217a0

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0042a0b4 == param_1) {
    PTR_LOOP_0042a0b4 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_004298a0) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00433414,0,param_1);
    return;
  }
  DAT_0042a0b0 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 00421800

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
  
  ppuVar4 = (undefined **)PTR_LOOP_004298a4;
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
            DAT_0042a0b8 = DAT_0042a0b8 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_004298a4) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 004218e0

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_004298a0;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_004298a0) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 00421940

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_0042a0b8 = DAT_0042a0b8 + 1, DAT_0042a0b8 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00421990

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
  
  piVar12 = (int *)PTR_LOOP_0042a0b4;
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
              PTR_LOOP_0042a0b4 = (undefined *)piVar12;
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
              PTR_LOOP_0042a0b4 = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_0042a0b4 != piVar12);
  ppuVar11 = &PTR_LOOP_004298a0;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_004298a0) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_0042a0b4 = (undefined *)ppuVar11;
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
  PTR_LOOP_0042a0b4 = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 00421c10

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


// ==== ___sbh_resize_block @ 00421d90

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


// ==== __callnewh @ 00421e60

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_004321b4 != (code *)0x0) {
    iVar1 = (*DAT_004321b4)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __ismbblead @ 00422020

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 00422040

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_0042a160 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_0042a42a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 00422080

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
  cVar1 = *DAT_004297f0;
  pcVar7 = DAT_004297f0;
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
  _DAT_0042982c = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_004297f0;
  pcVar7 = DAT_004297f0;
  do {
    if (cVar1 == '\0') {
      _free(DAT_004297f0);
      DAT_004297f0 = (char *)0x0;
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


// ==== __setargv @ 00422170

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_004321b8,0x104);
  _DAT_0042983c = &DAT_004321b8;
  pbVar2 = &DAT_004321b8;
  if (*DAT_00433420 != 0) {
    pbVar2 = DAT_00433420;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_00429824 = puVar1;
  _DAT_00429820 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 00422210

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
      if (((*(byte *)((int)&DAT_0042a160 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_0042a160 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00422280;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00422280:
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
          if ((*(byte *)((int)&DAT_0042a160 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_004223b1;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_0042a160 + bVar1 + 1) & 4) != 0) {
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
LAB_004223b1:
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


// ==== ___crtGetEnvironmentStringsA @ 004223f0

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
  if (DAT_0042a158 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0042a158 = 2;
    }
    else {
      DAT_0042a158 = 1;
    }
  }
  if (DAT_0042a158 != 1) {
    if (DAT_0042a158 != 2) {
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


// ==== __setmbcp @ 00422580

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
  if (CodePage == DAT_0042a264) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_0042a288;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_0042a160;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_0042a298 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_0042a280)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_0042a160 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_0042a264 = CodePage;
      _DAT_0042a268 = _CPtoLCID(CodePage);
      DAT_0042a270 = *(undefined4 *)(&DAT_0042a28c + local_18 * 0x30);
      DAT_0042a274 = *(undefined4 *)(&DAT_0042a290 + local_18 * 0x30);
      DAT_0042a278 = *(undefined4 *)(local_18 * 0x30 + 0x42a294);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_0042a378);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_0042a160;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_0042a268 = 0;
      DAT_0042a264 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_0042a160 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_0042a160 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_0042a264 = CodePage;
      _DAT_0042a268 = _CPtoLCID(CodePage);
    }
    DAT_0042a270 = 0;
    DAT_0042a274 = 0;
    DAT_0042a278 = 0;
    return 0;
  }
  if (DAT_0042a27c == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00422760

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0042a27c = 1;
                    /* WARNING: Could not recover jumptable at 0x0042277d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0042a27c = 1;
                    /* WARNING: Could not recover jumptable at 0x00422792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0042a908;
  }
  DAT_0042a27c = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 004227b0

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


// ==== setSBCS @ 00422810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0042a160;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0042a270 = 0;
  DAT_0042a264 = 0;
  _DAT_0042a268 = 0;
  DAT_0042a274 = 0;
  DAT_0042a278 = 0;
  return;
}


// ==== ___initmbctable @ 00422840

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00422850

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
  DAT_00433410 = 0x20;
  DAT_00433310 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00433310 + 0x40);
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
    if ((int)DAT_00433410 < (int)UVar7) {
      piVar4 = &DAT_00433314;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_00433410;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00433410 = DAT_00433410 + 0x20;
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
      } while ((int)DAT_00433410 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00433310 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_00433310 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_00433410);
  return UVar7;
}


// ==== __FF_MSGBANNER @ 00422a30

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_004297fc == 1) || ((DAT_004297fc == 0 && (DAT_00429800 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0042a410 != (code *)0x0) {
      (*DAT_0042a410)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00422a70

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
  piVar2 = &DAT_0042a380;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_0042a410);
  if ((&DAT_0042a380)[iVar4 * 2] == param_1) {
    if ((DAT_004297fc == 1) || ((DAT_004297fc == 0 && (DAT_00429800 == 1)))) {
      if ((DAT_00433310 == 0) ||
         (hFile = *(HANDLE *)(DAT_00433310 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x42a384);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x42a384);
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


// ==== FUN_00422ca0 @ 00422ca0

int FUN_00422ca0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_004322bc != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_004322bc);
    if (iVar2 != 0) {
      iVar2 = (*DAT_004322bc)(param_1);
      return iVar2;
    }
  }
  return 0;
}


// ==== FUN_00422d00 @ 00422d00

void FUN_00422d00(void)

{
  SetUnhandledExceptionFilter(DAT_004322bc);
  return;
}


// ==== _ValidateRead @ 00422d10

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 00422d30

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


// ==== _ValidateExecute @ 00422d50

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== _abort @ 00422d70

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


// ==== __control87 @ 00422d90

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 1998 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  uint uVar1;
  ushort in_FPUControlWord;
  
  uVar1 = __abstract_cw(in_FPUControlWord);
  __hw_cw();
  return ~_Mask & uVar1 | _NewValue & _Mask;
}


// ==== __controlfp @ 00422de0

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== __abstract_cw @ 00422e00

/* Library Function - Single Match
    __abstract_cw
   
   Library: Visual Studio 1998 Release */

uint __cdecl __abstract_cw(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 == 0x400) {
    uVar1 = uVar1 | 0x100;
  }
  else if (uVar2 == 0x800) {
    uVar1 = uVar1 | 0x200;
  }
  else if (uVar2 == 0xc00) {
    uVar1 = uVar1 | 0x300;
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}


// ==== __hw_cw @ 00422eb0

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}


// ==== FUN_00422f40 @ 00422f40

void FUN_00422f40(void)

{
  __amsg_exit(2);
  return;
}


// ==== __isctype @ 00422f50

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
    return (uint)*(ushort *)(PTR_DAT_0042a420 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_0042a420[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
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


// ==== FID_conflict:_tolower @ 00422ff0

/* Library Function - Multiple Matches With Different Base Names
    __tolower_lk
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict__tolower(int _C)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_0042a8f8 == (_locale_t)0x0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      _C = _C + 0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_0042a414 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_0042a420 + _C * 2) & 1;
    }
    else {
      uVar1 = __isctype(_C,1);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_0042a420[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_0042a8f8,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __ZeroTail @ 004230e0

/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __ZeroTail(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar1 = (byte)(param_2 >> 0x1f);
  if ((*(uint *)(param_1 + iVar2 * 4) &
      ~(-1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f))) != 0) {
    return 0;
  }
  iVar2 = iVar2 + 1;
  if (iVar2 < 3) {
    piVar3 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar3 != 0) {
        return 0;
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}


// ==== __IncMan @ 00423150

/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __IncMan(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar1 = (byte)(param_2 >> 0x1f);
  puVar4 = (uint *)(param_1 + iVar2 * 4);
  iVar3 = ___addl(*puVar4,1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) &
                               0x1f),puVar4);
  iVar2 = iVar2 + -1;
  if (-1 < iVar2) {
    puVar4 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar3 == 0) {
        return;
      }
      iVar3 = ___addl(*puVar4,1,puVar4);
      iVar2 = iVar2 + -1;
      puVar4 = puVar4 + -1;
    } while (-1 < iVar2);
  }
  return;
}


// ==== __RoundMan @ 004231c0

/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __RoundMan(int param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  local_4 = 0;
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  bVar2 = 0x1f - ((((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  puVar1 = (uint *)(param_1 + iVar3 * 4);
  if ((*puVar1 & 1 << (bVar2 & 0x1f)) != 0) {
    iVar4 = __ZeroTail(param_1,param_2 + 1);
    if (iVar4 == 0) {
      local_4 = __IncMan(param_1,param_2 + -1);
    }
  }
  iVar3 = iVar3 + 1;
  *puVar1 = *puVar1 & -1 << (bVar2 & 0x1f);
  if (iVar3 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar3 * 4);
    for (iVar4 = 3 - iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_4;
}


// ==== __CopyMan @ 00423270

/* Library Function - Single Match
    __CopyMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __CopyMan(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 3;
  do {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== __FillZeroMan @ 00423290

/* Library Function - Single Match
    __FillZeroMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __FillZeroMan(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== __IsZeroMan @ 004232a0

/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __IsZeroMan(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return 1;
}


// ==== __ShrMan @ 004232c0

/* Library Function - Single Match
    __ShrMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __ShrMan(uint *param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  bVar2 = (((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2;
  iVar6 = 3;
  uVar4 = 0;
  puVar5 = param_1;
  do {
    uVar1 = *puVar5;
    uVar8 = uVar1 >> (bVar2 & 0x1f);
    *puVar5 = uVar8;
    uVar8 = uVar8 | uVar4;
    uVar4 = (uVar1 & ~(-1 << (bVar2 & 0x1f))) << (0x20 - bVar2 & 0x1f);
    iVar6 = iVar6 + -1;
    *puVar5 = uVar8;
    puVar5 = puVar5 + 1;
  } while (iVar6 != 0);
  iVar6 = 2;
  puVar7 = param_1 + 2;
  puVar5 = param_1 + (2 - iVar3);
  do {
    if (iVar6 < iVar3) {
      *puVar7 = 0;
    }
    else {
      *puVar7 = *puVar5;
    }
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
    iVar6 = iVar6 + -1;
  } while (-1 < iVar6);
  return;
}


// ==== __ld12cvt @ 00423370

/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __ld12cvt(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  int local_10;
  undefined4 local_c [3];
  
  uVar1 = param_1[5];
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  local_14 = *(uint *)(param_1 + 1);
  local_18 = *(uint *)(param_1 + 3);
  local_10 = (uint)*param_1 << 0x10;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan((int *)&local_18);
    if (iVar2 == 0) {
      __FillZeroMan(&local_18);
      uVar3 = 2;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    __CopyMan(local_c,&local_18);
    iVar2 = __RoundMan((int)&local_18,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      iVar5 = 0;
      __FillZeroMan(&local_18);
      uVar3 = 2;
    }
    else if (iVar2 < iVar5) {
      if (iVar5 < *param_3) {
        iVar5 = iVar5 + param_3[5];
        local_18 = local_18 & 0x7fffffff;
        __ShrMan(&local_18,param_3[3]);
        uVar3 = 0;
      }
      else {
        __FillZeroMan(&local_18);
        local_18 = local_18 | 0x80000000;
        __ShrMan(&local_18,param_3[3]);
        iVar5 = param_3[5] + *param_3;
        uVar3 = 1;
      }
    }
    else {
      __CopyMan(&local_18,local_c);
      __ShrMan(&local_18,iVar2 - iVar5);
      __RoundMan((int)&local_18,param_3[2]);
      iVar5 = 0;
      __ShrMan(&local_18,param_3[3] + 1);
      uVar3 = 2;
    }
  }
  local_18 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) | ((uVar1 & 0x8000) == 0) - 1 & 0x80000000 |
             local_18;
  if (param_3[4] == 0x40) {
    param_2[1] = local_18;
    *param_2 = local_14;
    return uVar3;
  }
  if (param_3[4] == 0x20) {
    *param_2 = local_18;
  }
  return uVar3;
}


// ==== FID_conflict:__ld12tod @ 00423540

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0042a630);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 00423560

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0042a648);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 00423580

/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *_Result,char *_Str)

{
  INTRNCVT_STATUS IVar1;
  char *local_10;
  _LDBL12 local_c;
  
  ___strgtold12(&local_c,&local_10,_Str,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&local_c,(_CRT_DOUBLE *)_Result);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 004235c0

/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *_Result,char *_Str)

{
  INTRNCVT_STATUS IVar1;
  char *local_10;
  _LDBL12 local_c;
  
  ___strgtold12(&local_c,&local_10,_Str,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&local_c,(_CRT_DOUBLE *)_Result);
  return IVar1;
}


// ==== __fptostr @ 00423600

/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __fptostr(char *_Buf,size_t _SizeInBytes,int _Digits,STRFLT _PtFlt)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar7 = _Buf + 1;
  pcVar5 = *(char **)(_Digits + 0xc);
  *_Buf = '0';
  sVar2 = _SizeInBytes;
  pcVar6 = pcVar7;
  if (0 < (int)_SizeInBytes) {
    do {
      cVar1 = *pcVar5;
      if (cVar1 == '\0') {
        *pcVar6 = '0';
      }
      else {
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar1;
      }
      pcVar6 = pcVar6 + 1;
      _SizeInBytes = _SizeInBytes - 1;
      sVar2 = 0;
    } while (_SizeInBytes != 0);
  }
  *pcVar6 = '\0';
  if ((-1 < (int)sVar2) && ('4' < *pcVar5)) {
    pcVar6 = pcVar6 + -1;
    cVar1 = *pcVar6;
    while (cVar1 == '9') {
      *pcVar6 = '0';
      pcVar6 = pcVar6 + -1;
      cVar1 = *pcVar6;
    }
    *pcVar6 = *pcVar6 + '\x01';
  }
  if (*_Buf == '1') {
    *(int *)(_Digits + 4) = *(int *)(_Digits + 4) + 1;
    return sVar2;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)_Buf = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    _Buf = _Buf + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *_Buf = *pcVar7;
    pcVar7 = pcVar7 + 1;
    _Buf = _Buf + 1;
  }
  return uVar3;
}


// ==== __fltout @ 00423690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fltout
   
   Library: Visual Studio 1998 Release */

undefined * __fltout(void)

{
  uint local_c;
  uint local_8;
  ushort local_4;
  
  ___dtold(&local_c,(uint *)&stack0x00000004);
  _DAT_004322e8 = _I10_OUTPUT(local_c,local_8,local_4,0x11,0,&DAT_004322c0);
  _DAT_004322ec = &DAT_004322c4;
  _DAT_004322e0 = (int)DAT_004322c2;
  _DAT_004322e4 = (int)DAT_004322c0;
  return &DAT_004322e0;
}


// ==== ___dtold @ 00423700

/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 1998 Release */

void __cdecl ___dtold(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar5 = (uVar1 & 0x7ff0) >> 4;
  uVar4 = 0x80000000;
  uVar2 = param_2[1];
  uVar3 = *param_2;
  if (uVar5 == 0) {
    if (((uVar2 & 0xfffff) == 0) && (uVar3 == 0)) {
      *(undefined2 *)(param_1 + 2) = 0;
      param_1[1] = 0;
      *param_1 = 0;
      return;
    }
    uVar5 = 0x3c01;
    uVar4 = 0;
  }
  else if (uVar5 == 0x7ff) {
    uVar5 = 0x7fff;
  }
  else {
    uVar5 = uVar5 + 0x3c00;
  }
  *param_1 = uVar3 << 0xb;
  param_1[1] = (uVar2 & 0xfffff) << 0xb | uVar3 >> 0x15 | uVar4;
  while (uVar4 == 0) {
    uVar5 = uVar5 - 1;
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *param_1 = uVar2 * 2;
    param_1[1] = uVar2 >> 0x1f | uVar3 * 2;
    uVar4 = uVar3 * 2 & 0x80000000;
  }
  *(ushort *)(param_1 + 2) = uVar5 | uVar1 & 0x8000;
  return;
}


// ==== __write @ 004237c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 1998 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  byte bVar1;
  char cVar2;
  BOOL BVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  ulong local_418;
  DWORD local_414;
  int *local_410;
  int local_40c;
  DWORD local_408;
  char local_404 [1028];
  
  if ((uint)_FileHandle < DAT_00433410) {
    local_410 = (int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
    local_40c = (_FileHandle & 0x1fU) * 8;
    bVar1 = *(byte *)(*local_410 + 4 + local_40c);
    if ((bVar1 & 1) != 0) {
      iVar5 = 0;
      local_408 = 0;
      if (_MaxCharCount == 0) {
        return 0;
      }
      if ((bVar1 & 0x20) != 0) {
        __lseek(_FileHandle,0,2);
      }
      if ((*(byte *)((undefined4 *)(local_40c + *local_410) + 1) & 0x80) == 0) {
        BVar3 = WriteFile(*(HANDLE *)(local_40c + *local_410),_Buf,_MaxCharCount,&local_414,
                          (LPOVERLAPPED)0x0);
        if (BVar3 == 0) {
LAB_00423905:
          local_418 = GetLastError();
        }
        else {
          local_418 = 0;
          local_408 = local_414;
        }
      }
      else {
        local_418 = 0;
        pcVar4 = _Buf;
        do {
          if (_MaxCharCount <= (uint)((int)pcVar4 - (int)_Buf)) break;
          pcVar6 = local_404;
          do {
            if (_MaxCharCount <= (uint)((int)pcVar4 - (int)_Buf)) break;
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            if (cVar2 == '\n') {
              *pcVar6 = '\r';
              iVar5 = iVar5 + 1;
              pcVar6 = pcVar6 + 1;
            }
            *pcVar6 = cVar2;
            pcVar6 = pcVar6 + 1;
          } while ((int)pcVar6 - (int)local_404 < 0x400);
          BVar3 = WriteFile(*(HANDLE *)(*local_410 + local_40c),local_404,
                            (int)pcVar6 - (int)local_404,&local_414,(LPOVERLAPPED)0x0);
          if (BVar3 == 0) goto LAB_00423905;
          local_408 = local_408 + local_414;
        } while ((int)pcVar6 - (int)local_404 <= (int)local_414);
      }
      if (local_408 != 0) {
        return local_408 - iVar5;
      }
      if (local_418 == 0) {
        if (((*(byte *)(*local_410 + 4 + local_40c) & 0x40) != 0) && (*(char *)_Buf == '\x1a')) {
          return 0;
        }
        _DAT_00429804 = 0x1c;
        _DAT_00429808 = 0;
        return -1;
      }
      if (local_418 != 5) {
        __dosmaperr(local_418);
        return -1;
      }
      _DAT_00429804 = 9;
      _DAT_00429808 = local_418;
      return -1;
    }
  }
  _DAT_00429804 = 9;
  _DAT_00429808 = 0;
  return -1;
}


// ==== __lseek @ 004239f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 1998 Release */

long __cdecl __lseek(int _FileHandle,long _Offset,int _Origin)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  HANDLE hFile;
  DWORD DVar4;
  ulong uVar5;
  
  if ((uint)_FileHandle < DAT_00433410) {
    piVar1 = (int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
    iVar2 = (_FileHandle & 0x1fU) * 8;
    if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) != 0) {
      hFile = (HANDLE)__get_osfhandle(_FileHandle);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_00429804 = 9;
        return -1;
      }
      DVar4 = SetFilePointer(hFile,_Offset,(PLONG)0x0,_Origin);
      uVar5 = 0;
      if (DVar4 == 0xffffffff) {
        uVar5 = GetLastError();
      }
      if (uVar5 != 0) {
        __dosmaperr(uVar5);
        return -1;
      }
      pbVar3 = (byte *)(*piVar1 + 4 + iVar2);
      *pbVar3 = *pbVar3 & 0xfd;
      return DVar4;
    }
  }
  _DAT_00429804 = 9;
  _DAT_00429808 = 0;
  return -1;
}


// ==== __getbuf @ 00423ab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_0042a8e0 = _DAT_0042a8e0 + 1;
  pcVar1 = _malloc(0x1000);
  _File->_base = pcVar1;
  if (pcVar1 == (char *)0x0) {
    _File->_flag = _File->_flag | 4;
    _File->_base = (char *)&_File->_charbuf;
    _File->_bufsiz = 2;
  }
  else {
    _File->_flag = _File->_flag | 8;
    _File->_bufsiz = 0x1000;
  }
  _File->_ptr = _File->_base;
  _File->_cnt = 0;
  return;
}


// ==== __isatty @ 00423b00

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Release */

int __cdecl __isatty(int _FileHandle)

{
  if (DAT_00433410 <= (uint)_FileHandle) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                  (_FileHandle & 0x1fU) * 8) & 0x40;
}


// ==== _wctomb @ 00423c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  int iVar1;
  BOOL local_4;
  
  if (_MbCh == (char *)0x0) {
    return 0;
  }
  if (DAT_0042a8f8 == 0) {
    if (0xff < (ushort)_WCh) {
      _DAT_00429804 = 0x2a;
      return -1;
    }
    *_MbCh = (char)_WCh;
    return 1;
  }
  local_4 = 0;
  iVar1 = WideCharToMultiByte(DAT_0042a908,0x220,&_WCh,1,_MbCh,DAT_0042a414,(LPCSTR)0x0,&local_4);
  if ((iVar1 == 0) || (local_4 != 0)) {
    _DAT_00429804 = 0x2a;
    iVar1 = -1;
  }
  return iVar1;
}


// ==== __aulldiv @ 00423cc0

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio 1998 Release */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}


// ==== __aullrem @ 00423d30

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio 1998 Release */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}


// ==== ___crtMessageBoxA @ 00423db0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0042a90c != (FARPROC)0x0) {
LAB_00423dff:
    if (DAT_0042a910 != (FARPROC)0x0) {
      iVar1 = (*DAT_0042a910)();
    }
    if ((iVar1 != 0) && (DAT_0042a914 != (FARPROC)0x0)) {
      iVar1 = (*DAT_0042a914)(iVar1);
    }
    iVar1 = (*DAT_0042a90c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0042a90c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0042a90c != (FARPROC)0x0) {
      DAT_0042a910 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0042a914 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00423dff;
    }
  }
  return 0;
}


// ==== _strncpy @ 00423e50

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
        goto joined_r0x00423e8e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00423ecb;
        goto LAB_00423f39;
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
joined_r0x00423f35:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00423f39:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00423ecb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00423f35;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00423f35;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00423f35;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00423e8e:
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
LAB_00423ecb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _raise @ 00423f50

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
    puVar6 = &DAT_0042a920;
    pcVar7 = DAT_0042a920;
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
    puVar6 = &DAT_0042a92c;
    pcVar7 = DAT_0042a92c;
    break;
  case 0x15:
    puVar6 = &DAT_0042a924;
    pcVar7 = DAT_0042a924;
    break;
  case 0x16:
    puVar6 = &DAT_0042a928;
    pcVar7 = DAT_0042a928;
  }
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
    __exit(3);
  }
  uVar2 = DAT_0042a150;
  uVar1 = DAT_0042a14c;
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_0042a150 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_0042a14c = 0x8c;
      local_4 = uVar1;
      goto LAB_0042401c;
    }
  }
  else {
LAB_0042401c:
    if (_SigNum == 8) {
      if (DAT_0042a140 < DAT_0042a144 + DAT_0042a140) {
        puVar6 = (undefined4 *)(DAT_0042a140 * 0xc + 0x42a0d0);
        iVar4 = DAT_0042a144;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_0042405d;
    }
  }
  *puVar6 = 0;
LAB_0042405d:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_0042a14c);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_0042a14c = local_4;
  }
  DAT_0042a150 = uVar5;
  return 0;
}


// ==== siglookup @ 004240e0

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_0042a0c8;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_0042a0c8 + DAT_0042a148 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


// ==== ___crtGetStringTypeA @ 00424120

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
  
  iVar2 = DAT_0042a938;
  if (DAT_0042a938 == 0) {
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
  DAT_0042a938 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_0042a908;
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
    _Code_page = DAT_0042a8f8;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== ___crtLCMapStringA @ 00424250

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
  
  if (DAT_0042a940 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042a940 = 1;
    }
    else {
      DAT_0042a940 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_0042a940 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_0042a940 != 1) {
    return DAT_0042a940;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_0042a908;
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
                               iVar2), iVar1 == 0)) goto LAB_004243cb;
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
      if (_LpDestStr == (LPSTR)0x0) goto LAB_00424462;
      if ((int)_LpDestStr < iVar2) goto LAB_004243cb;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_00424462:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_004243cb:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 00424480

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
    if (*pcVar2 == '\0') goto LAB_004244a5;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_004244a5:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== ___addl @ 004244b0

/* Library Function - Single Match
    ___addl
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl ___addl(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}


// ==== ___add_12 @ 004244e0

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = ___addl(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = ___addl(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = ___addl(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  ___addl(param_1[2],param_2[2],param_1 + 2);
  return;
}


// ==== ___shl_12 @ 00424550

/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___shl_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] * 2 | uVar2 >> 0x1f;
  return;
}


// ==== ___shr_12 @ 00424590

/* Library Function - Single Match
    ___shr_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___shr_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[2];
  uVar2 = param_1[1];
  param_1[2] = uVar1 >> 1;
  param_1[1] = uVar2 >> 1 | uVar1 << 0x1f;
  *param_1 = *param_1 >> 1 | uVar2 << 0x1f;
  return;
}


// ==== ___mtold12 @ 004245d0

/* Library Function - Single Match
    ___mtold12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___mtold12(char *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  sVar3 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_c = *param_3;
    local_8 = param_3[1];
    local_4 = param_3[2];
    ___shl_12(param_3);
    ___shl_12(param_3);
    ___add_12(param_3,&local_c);
    ___shl_12(param_3);
    local_c = (uint)*param_1;
    local_8 = 0;
    local_4 = 0;
    ___add_12(param_3,&local_c);
    param_1 = param_1 + 1;
  }
  uVar2 = param_3[2];
  while (uVar2 == 0) {
    sVar3 = sVar3 + -0x10;
    uVar2 = param_3[1] >> 0x10;
    param_3[2] = uVar2;
    param_3[1] = param_3[1] << 0x10 | *param_3 >> 0x10;
    *param_3 = *param_3 << 0x10;
  }
  bVar1 = *(byte *)((int)param_3 + 9);
  while ((bVar1 & 0x80) == 0) {
    sVar3 = sVar3 + -1;
    ___shl_12(param_3);
    bVar1 = *(byte *)((int)param_3 + 9);
  }
  *(short *)((int)param_3 + 10) = sVar3;
  return;
}


// ==== ___strgtold12 @ 004246c0

/* Library Function - Single Match
    ___strgtold12
   
   Library: Visual Studio 1998 Release */

uint __cdecl
___strgtold12(_LDBL12 *pld12,char **p_end_ptr,char *str,int mult12,int scale,int decpt,
             int implicit_E)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  byte bVar8;
  char *pcVar9;
  char *pcVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  ushort local_52;
  uint local_50;
  byte *local_4c;
  int local_48;
  uint local_40;
  int local_3c;
  undefined4 local_28 [5];
  char local_11;
  ushort local_c;
  undefined4 local_a;
  undefined4 local_6;
  ushort local_2;
  
  local_3c = 1;
  pcVar10 = (char *)local_28;
  iVar12 = 0;
  local_52 = 0;
  local_50 = 0;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  bVar5 = false;
  iVar7 = 0;
  bVar6 = false;
  local_48 = 0;
  local_40 = 0;
  local_4c = (byte *)str;
  for (; (((bVar8 = *str, bVar8 == 0x20 || (bVar8 == 9)) || (bVar8 == 10)) || (bVar8 == 0xd));
      str = str + 1) {
  }
  do {
    bVar8 = *str;
    pbVar11 = (byte *)(str + 1);
    switch(iVar7) {
    case 0:
      if (((char)bVar8 < '1') || ('9' < (char)bVar8)) {
        if (DAT_0042a418 == bVar8) {
          iVar7 = 5;
        }
        else if (bVar8 == 0x2b) {
          local_52 = 0;
          iVar7 = 2;
        }
        else if (bVar8 == 0x2d) {
          local_52 = 0x8000;
          iVar7 = 2;
        }
        else {
          if (bVar8 != 0x30) goto switchD_00424970_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_00424b74;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_00424b74;
      }
      if (DAT_0042a418 == bVar8) {
        iVar7 = 4;
      }
      else {
        switch(bVar8) {
        case 0x2b:
        case 0x2d:
          iVar7 = 0xb;
          pbVar11 = (byte *)str;
          break;
        default:
          goto switchD_00424970_caseD_2c;
        case 0x30:
          iVar7 = 1;
          break;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          iVar7 = 6;
        }
      }
      break;
    case 2:
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_00424b74;
      }
      if (DAT_0042a418 == bVar8) {
        iVar7 = 5;
      }
      else if (bVar8 == 0x30) {
        iVar7 = 1;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 3:
      bVar2 = true;
      while( true ) {
        if (DAT_0042a414 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042a420 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar10 = bVar8 - 0x30;
          bVar8 = *pbVar11;
          pcVar10 = pcVar10 + 1;
          pbVar11 = pbVar11 + 1;
        }
        else {
          bVar8 = *pbVar11;
          pbVar11 = pbVar11 + 1;
          local_48 = local_48 + 1;
        }
      }
      if (DAT_0042a418 == bVar8) {
        iVar7 = 4;
      }
      else {
        switch(bVar8) {
        case 0x2b:
        case 0x2d:
          iVar7 = 0xb;
          pbVar11 = pbVar11 + -1;
          break;
        default:
          goto switchD_00424970_caseD_2c;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          iVar7 = 6;
        }
      }
      break;
    case 4:
      bVar2 = true;
      bVar4 = true;
      if (local_50 == 0) {
        while (bVar8 == 0x30) {
          local_48 = local_48 + -1;
          bVar8 = *pbVar11;
          pbVar11 = pbVar11 + 1;
        }
      }
      while( true ) {
        if (DAT_0042a414 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042a420 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        pcVar9 = pcVar10;
        if (local_50 < 0x19) {
          pcVar9 = pcVar10 + 1;
          local_50 = local_50 + 1;
          local_48 = local_48 + -1;
          *pcVar10 = bVar8 - 0x30;
        }
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
        pcVar10 = pcVar9;
      }
      switch(bVar8) {
      case 0x2b:
      case 0x2d:
        iVar7 = 0xb;
        pbVar11 = pbVar11 + -1;
        break;
      default:
        goto switchD_00424970_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_0042a414 < 2) {
        uVar13 = *(ushort *)(PTR_DAT_0042a420 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_00424b74;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = (byte *)(str + -1);
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00424b74;
      }
      if (bVar8 == 0x2b) {
        iVar7 = 7;
      }
      else if (bVar8 == 0x2d) {
        local_3c = -1;
        iVar7 = 7;
      }
      else if (bVar8 == 0x30) {
        iVar7 = 8;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 7:
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00424b74;
      }
      if (bVar8 == 0x30) {
        iVar7 = 8;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 8:
      bVar3 = true;
      while (bVar8 == 0x30) {
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00424b74;
      }
      goto switchD_00424970_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_0042a414 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042a420 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_00424afa;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_00424afa:
      while( true ) {
        if (DAT_0042a414 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042a420 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_00424970_caseD_2c:
      iVar7 = 10;
LAB_00424b74:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (implicit_E == 0) goto switchD_00424970_caseD_2c;
      local_4c = (byte *)str;
      if (bVar8 == 0x2b) {
        iVar7 = 7;
      }
      else if (bVar8 == 0x2d) {
        local_3c = -1;
        iVar7 = 7;
      }
      else {
        iVar7 = 10;
        pbVar11 = (byte *)str;
      }
    }
    str = (char *)pbVar11;
  } while (iVar7 != 10);
  *p_end_ptr = (char *)pbVar11;
  if (bVar2) {
    if (0x18 < local_50) {
      if ('\x04' < local_11) {
        local_11 = local_11 + '\x01';
      }
      pcVar10 = pcVar10 + -1;
      local_48 = local_48 + 1;
      local_50 = 0x18;
    }
    if (local_50 == 0) {
      local_c = 0;
      local_6 = 0;
      local_2 = 0;
      local_28[0] = 0;
      goto LAB_00424c72;
    }
    pcVar10 = pcVar10 + -1;
    cVar1 = *pcVar10;
    while (cVar1 == '\0') {
      pcVar10 = pcVar10 + -1;
      local_50 = local_50 - 1;
      local_48 = local_48 + 1;
      cVar1 = *pcVar10;
    }
    ___mtold12((char *)local_28,local_50,(uint *)&local_c);
    if (local_3c < 0) {
      iVar12 = -iVar12;
    }
    uVar13 = iVar12 + local_48;
    if (!bVar3) {
      uVar13 = uVar13 + scale;
    }
    if (!bVar4) {
      uVar13 = uVar13 - decpt;
    }
    if ((int)uVar13 < 0x1451) {
      if (-0x1451 < (int)uVar13) {
        ___multtenpow12((int *)&local_c,uVar13,mult12);
        local_28[0] = local_a;
        goto LAB_00424c72;
      }
      bVar6 = true;
    }
    else {
      bVar5 = true;
    }
  }
  local_6 = local_28[0];
  local_c = (ushort)local_28[0];
  local_2 = (ushort)local_28[0];
LAB_00424c72:
  if (bVar2) {
    if (bVar5) {
      local_2 = 0x7fff;
      local_6 = 0x80000000;
      local_c = 0;
      local_28[0] = 0;
      local_40 = 2;
    }
    else if (bVar6) {
      local_c = 0;
      local_6 = 0;
      local_2 = 0;
      local_28[0] = 0;
      local_40 = 1;
    }
  }
  else {
    local_c = 0;
    local_6 = 0;
    local_2 = 0;
    local_28[0] = 0;
    local_40 = 4;
  }
  *(ushort *)pld12->ld12 = local_c;
  *(undefined4 *)(pld12->ld12 + 2) = local_28[0];
  *(ushort *)(pld12->ld12 + 10) = local_2 | local_52;
  *(undefined4 *)(pld12->ld12 + 6) = local_6;
  return local_40;
}


// ==== $I10_OUTPUT @ 00424e10

/* Library Function - Single Match
    _$I10_OUTPUT
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl
_I10_OUTPUT(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  short sVar9;
  undefined2 local_28;
  undefined4 uStack_26;
  undefined4 uStack_22;
  undefined1 local_1e;
  char cStack_1d;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xcc;
  local_15 = 0xcc;
  local_14 = 0xcc;
  local_13 = 0xcc;
  local_12 = 0xcc;
  local_11 = 0xcc;
  local_10 = 0xcc;
  local_f = 0xcc;
  local_e = 0xfb;
  local_d = 0x3f;
  local_1c = 1;
  uVar2 = param_3 & 0x7fff;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if (((uVar2 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *(undefined1 *)(param_6 + 1) = 0x20;
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (uVar2 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 != 0x80000000) || (param_1 != 0)) && ((param_2 & 0x40000000) == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_004264d0;
      param_6[4] = DAT_004264d4;
      *(undefined1 *)(param_6 + 5) = DAT_004264d6;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_004264c8;
      param_6[4] = DAT_004264cc;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_004264c0;
      param_6[4] = DAT_004264c4;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_004264b8;
    param_6[4] = DAT_004264bc;
    *(undefined1 *)(param_6 + 5) = DAT_004264be;
    *(undefined1 *)((int)param_6 + 3) = 6;
    return 0;
  }
  local_1e = (undefined1)uVar2;
  cStack_1d = (char)(uVar2 >> 8);
  sVar9 = (short)(((uint)(uVar2 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + (uint)uVar2 * 0x4d10 +
                  -0x134312f4 >> 0x10);
  local_28 = 0;
  uStack_22 = param_2;
  uStack_26 = param_1;
  ___multtenpow12((int *)&local_28,-(int)sVar9,1);
  if (0x3ffe < CONCAT11(cStack_1d,local_1e)) {
    sVar9 = sVar9 + 1;
    ___ld12mul((int *)&local_28,(int *)&local_18);
  }
  *param_6 = sVar9;
  if (((param_5 & 1) != 0) && (param_4 = param_4 + sVar9, param_4 < 1)) {
    *(undefined1 *)(param_6 + 1) = 0x20;
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (0x15 < param_4) {
    param_4 = 0x15;
  }
  iVar8 = 8;
  uVar2 = CONCAT11(cStack_1d,local_1e);
  local_1e = 0;
  cStack_1d = '\0';
  iVar4 = uVar2 - 0x3ffe;
  do {
    ___shl_12((uint *)&local_28);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (iVar4 < 0) {
    for (uVar5 = -iVar4 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
      ___shr_12((uint *)&local_28);
    }
  }
  psVar1 = param_6 + 2;
  iVar8 = param_4 + 1;
  psVar7 = psVar1;
  psVar6 = psVar1;
  iVar4 = uStack_26;
  uVar5 = uStack_22;
  if (0 < iVar8) {
    do {
      uStack_22._2_2_ = (undefined2)(uVar5 >> 0x10);
      uStack_22._0_2_ = (undefined2)uVar5;
      uStack_26._2_2_ = (undefined2)((uint)iVar4 >> 0x10);
      uStack_26._0_2_ = (undefined2)iVar4;
      psVar6 = (short *)((int)psVar7 + 1);
      local_c = CONCAT22((undefined2)uStack_26,local_28);
      local_8 = CONCAT22((undefined2)uStack_22,uStack_26._2_2_);
      local_4 = CONCAT13(cStack_1d,CONCAT12(local_1e,uStack_22._2_2_));
      uStack_26 = iVar4;
      uStack_22 = uVar5;
      ___shl_12((uint *)&local_28);
      ___shl_12((uint *)&local_28);
      ___add_12((uint *)&local_28,&local_c);
      ___shl_12((uint *)&local_28);
      iVar8 = iVar8 + -1;
      *(char *)psVar7 = cStack_1d + '0';
      cStack_1d = '\0';
      psVar7 = psVar6;
      iVar4 = uStack_26;
      uVar5 = uStack_22;
    } while (iVar8 != 0);
  }
  psVar7 = psVar6 + -1;
  if (*(char *)((int)psVar6 + -1) < '5') {
    if (psVar7 < psVar1) {
LAB_00425189:
      *param_6 = 0;
      *(char *)psVar1 = '0';
      *(undefined1 *)(param_6 + 1) = 0x20;
      *(undefined1 *)((int)param_6 + 3) = 1;
      *(undefined1 *)((int)param_6 + 5) = 0;
      return 1;
    }
    do {
      if ((char)*psVar7 != '0') break;
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_00425189;
    goto LAB_0042515b;
  }
  if (psVar7 < psVar1) {
LAB_00425155:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_00425155;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_0042515b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}


// ==== __dosmaperr @ 004251b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  int iVar1;
  ulong *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_0042a948;
  _DAT_00429808 = param_1;
  do {
    if (*puVar2 == param_1) {
      _DAT_00429804 = *(undefined4 *)(iVar1 * 8 + 0x42a94c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (puVar2 < &DAT_0042aab0);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_00429804 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    _DAT_00429804 = 8;
    return;
  }
  _DAT_00429804 = 0x16;
  return;
}


// ==== __free_osfhnd @ 00425220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00433410) {
    piVar1 = (int *)((int)&DAT_00433310 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar2 = (param_1 & 0x1fU) * 8;
    piVar3 = (int *)(*piVar1 + iVar2);
    if (((*(byte *)(piVar3 + 1) & 1) != 0) && (*piVar3 != -1)) {
      if (DAT_00429800 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00425286;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00425286:
      *(undefined4 *)(*piVar1 + iVar2) = 0xffffffff;
      return 0;
    }
  }
  _DAT_00429804 = 9;
  _DAT_00429808 = 0;
  return -1;
}


// ==== __get_osfhandle @ 004252b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  
  if (((uint)_FileHandle < DAT_00433410) &&
     (piVar1 = (intptr_t *)
               (*(int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) +
               (_FileHandle & 0x1fU) * 8), (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  _DAT_00429804 = 9;
  _DAT_00429808 = 0;
  return -1;
}


// ==== _calloc @ 00425300

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
      if (DAT_0042a0bc < dwBytes) {
LAB_0042535d:
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
          goto LAB_0042535d;
        }
      }
      puVar3 = HeapAlloc(DAT_00433414,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_0042a0c0 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== __fcloseall @ 004253a0

/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 1998 Release */

int __cdecl __fcloseall(void)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 3;
  if (3 < DAT_00433300) {
    iVar2 = 0xc;
    do {
      _File = *(FILE **)(DAT_004322f0 + iVar2);
      if (_File != (FILE *)0x0) {
        if ((_File->_flag & 0x83U) != 0) {
          iVar1 = _fclose(_File);
          if (iVar1 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        if (0x4f < iVar2) {
          _free(*(void **)(DAT_004322f0 + iVar2));
          *(undefined4 *)(DAT_004322f0 + iVar2) = 0;
        }
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00433300);
  }
  return iVar3;
}


// ==== _fflush @ 00425420

/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Release */

int __cdecl _fflush(FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = __flush(_File);
  if (iVar1 != 0) {
    return -1;
  }
  if ((_File->_flag & 0x4000) != 0) {
    iVar1 = __commit(_File->_file);
    return (iVar1 == 0) - 1;
  }
  return 0;
}


// ==== __flush @ 00425470

/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 1998 Release */

int __cdecl __flush(FILE *_File)

{
  uint uVar1;
  uint _MaxCharCount;
  int iVar2;
  
  iVar2 = 0;
  if ((((byte)_File->_flag & 3) == 2) && ((_File->_flag & 0x108U) != 0)) {
    _MaxCharCount = (int)_File->_ptr - (int)_File->_base;
    if (0 < (int)_MaxCharCount) {
      uVar1 = __write(_File->_file,_File->_base,_MaxCharCount);
      if (uVar1 == _MaxCharCount) {
        if ((_File->_flag & 0x80U) != 0) {
          _File->_flag = _File->_flag & 0xfffffffd;
        }
      }
      else {
        _File->_flag = _File->_flag | 0x20;
        iVar2 = -1;
      }
    }
  }
  _File->_ptr = _File->_base;
  _File->_cnt = 0;
  return iVar2;
}


// ==== flsall @ 004254f0

/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Release */

int __cdecl flsall(int param_1)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = 0;
  iVar4 = 0;
  local_4 = 0;
  if (0 < DAT_00433300) {
    iVar3 = 0;
    do {
      _File = *(FILE **)(DAT_004322f0 + iVar3);
      if ((_File != (FILE *)0x0) && ((_File->_flag & 0x83U) != 0)) {
        if (param_1 == 1) {
          iVar1 = _fflush(_File);
          if (iVar1 != -1) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (((param_1 == 0) && ((_File->_flag & 2U) != 0)) &&
                (iVar1 = _fflush(_File), iVar1 == -1)) {
          local_4 = -1;
        }
      }
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00433300);
  }
  if (param_1 != 1) {
    iVar2 = local_4;
  }
  return iVar2;
}


// ==== ___ld12mul @ 00425580

/* Library Function - Single Match
    ___ld12mul
   
   Library: Visual Studio 1998 Release */

void __cdecl ___ld12mul(int *param_1,int *param_2)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  ushort local_1a;
  undefined4 local_18;
  short local_14 [4];
  int local_c;
  int local_8;
  int local_4;
  
  local_18._0_1_ = 0;
  local_18._1_1_ = 0;
  local_18._2_2_ = 0;
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  uVar2 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar4 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar5 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  local_1a = uVar4 + uVar5;
  if (((0x7ffe < uVar4) || (0x7ffe < uVar5)) || (0xbffd < local_1a)) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar2 == 0) & 0x80000000) - 0x8000;
    return;
  }
  if (local_1a < 0x3fc0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  if (((uVar4 == 0) && (local_1a = local_1a + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
     ((param_1[1] == 0 && (*param_1 == 0)))) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    return;
  }
  if (((uVar5 == 0) && (local_1a = local_1a + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
     ((param_2[1] == 0 && (*param_2 == 0)))) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  local_8 = 0;
  local_c = 0;
  do {
    iVar6 = 8;
    iVar8 = local_c * 2;
    local_4 = 5 - local_c;
    if (0 < 5 - local_c) {
      puVar1 = (uint *)((int)&local_18 + local_8);
      do {
        iVar3 = ___addl(*puVar1,(uint)*(ushort *)(iVar6 + (int)param_2) *
                                (uint)*(ushort *)(iVar8 + (int)param_1),puVar1);
        if (iVar3 != 0) {
          *(short *)((int)local_14 + local_8) = *(short *)((int)local_14 + local_8) + 1;
        }
        iVar8 = iVar8 + 2;
        iVar6 = iVar6 + -2;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    local_8 = local_8 + 2;
    local_c = local_c + 1;
  } while (local_c < 5);
  local_1a = local_1a + 0xc002;
  if (0 < (short)local_1a) {
    do {
      if ((local_14[3] & 0x8000U) != 0) break;
      ___shl_12(&local_18);
      local_1a = local_1a - 1;
    } while (0 < (short)local_1a);
    if (0 < (short)local_1a) goto LAB_00425753;
  }
  local_1a = local_1a - 1;
  if ((short)local_1a < 0) {
    iVar8 = CONCAT22(local_18._2_2_,CONCAT11(local_18._1_1_,(byte)local_18));
    sVar7 = -local_1a;
    local_1a = 0;
    do {
      if (((byte)local_18 & 1) != 0) {
        iVar8 = iVar8 + 1;
      }
      ___shr_12(&local_18);
      sVar7 = sVar7 + -1;
    } while (sVar7 != 0);
  }
  else {
    iVar8 = CONCAT22(local_18._2_2_,CONCAT11(local_18._1_1_,(byte)local_18));
  }
  if (iVar8 != 0) {
    local_18._0_1_ = (byte)local_18 | 1;
  }
LAB_00425753:
  iVar6 = CONCAT22(local_14[2],local_14[1]);
  iVar8 = CONCAT22(local_14[0],local_18._2_2_);
  if (0x8000 < CONCAT11(local_18._1_1_,(byte)local_18)) {
    if (CONCAT22(local_14[0],local_18._2_2_) == -1) {
      iVar8 = 0;
      if (CONCAT22(local_14[2],local_14[1]) == -1) {
        if (local_14[3] == 0xffff) {
          local_14[3] = 0x8000;
          local_1a = local_1a + 1;
          iVar6 = 0;
          iVar8 = 0;
        }
        else {
          local_14[3] = local_14[3] + 1;
          iVar6 = 0;
          iVar8 = 0;
        }
      }
      else {
        iVar6 = CONCAT22(local_14[2],local_14[1]) + 1;
      }
    }
    else {
      iVar8 = CONCAT22(local_14[0],local_18._2_2_) + 1;
      iVar6 = CONCAT22(local_14[2],local_14[1]);
    }
  }
  local_14[0] = (short)((uint)iVar8 >> 0x10);
  local_18._2_2_ = (undefined2)iVar8;
  local_14[2] = (short)((uint)iVar6 >> 0x10);
  local_14[1] = (short)iVar6;
  if (local_1a < 0x7fff) {
    *(undefined2 *)param_1 = local_18._2_2_;
    *(uint *)((int)param_1 + 2) = CONCAT22(local_14[1],local_14[0]);
    *(ushort *)((int)param_1 + 10) = local_1a | uVar2;
    *(uint *)((int)param_1 + 6) = CONCAT22(local_14[3],local_14[2]);
    return;
  }
  param_1[1] = 0;
  *param_1 = 0;
  param_1[2] = (-(uint)(uVar2 == 0) & 0x80000000) - 0x8000;
  return;
}


// ==== ___multtenpow12 @ 00425830

/* Library Function - Single Match
    ___multtenpow12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___multtenpow12(int *param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  undefined *puVar4;
  uint uVar5;
  ushort local_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined4 local_4;
  
  puVar4 = &DAT_0042aa50;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar4 = &DAT_0042abb0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      puVar4 = puVar4 + 0x54;
      uVar5 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar5;
      if (uVar2 != 0) {
        puVar1 = (ushort *)(puVar4 + uVar2 * 0xc);
        puVar3 = puVar1;
        if (0x7fff < *puVar1) {
          puVar3 = &local_c;
          local_c = (ushort)*(undefined4 *)puVar1;
          uStack_a._0_2_ = (undefined2)((uint)*(undefined4 *)puVar1 >> 0x10);
          uStack_a._2_2_ = (undefined2)*(undefined4 *)(puVar1 + 2);
          uStack_6 = (undefined2)((uint)*(undefined4 *)(puVar1 + 2) >> 0x10);
          local_4 = *(undefined4 *)(puVar1 + 4);
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
        }
        ___ld12mul(param_1,(int *)puVar3);
      }
    }
  }
  return;
}


// ==== _fclose @ 004258b0

/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Release */

int __cdecl _fclose(FILE *_File)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if ((_File->_flag & 0x40U) != 0) {
    _File->_flag = 0;
    return -1;
  }
  if ((_File->_flag & 0x83U) != 0) {
    iVar2 = __flush(_File);
    __freebuf(_File);
    iVar1 = __close(_File->_file);
    if (iVar1 < 0) {
      iVar2 = -1;
    }
    else if (_File->_tmpfname != (char *)0x0) {
      _free(_File->_tmpfname);
      _File->_tmpfname = (char *)0x0;
    }
  }
  _File->_flag = 0;
  return iVar2;
}


// ==== __commit @ 00425920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Release */

int __cdecl __commit(int _FileHandle)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  
  if (((uint)_FileHandle < DAT_00433410) &&
     ((*(byte *)(*(int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    DVar2 = 0;
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    iVar3 = 0;
    if (DVar2 != 0) {
      _DAT_00429804 = 9;
      _DAT_00429808 = DVar2;
      return -1;
    }
  }
  else {
    _DAT_00429804 = 9;
    iVar3 = -1;
  }
  return iVar3;
}


// ==== __close @ 00425990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Release */

int __cdecl __close(int _FileHandle)

{
  int *piVar1;
  int iVar2;
  intptr_t iVar3;
  intptr_t iVar4;
  HANDLE hObject;
  BOOL BVar5;
  DWORD DVar6;
  
  if (DAT_00433410 <= (uint)_FileHandle) {
    _DAT_00429804 = 9;
    _DAT_00429808 = 0;
    return -1;
  }
  piVar1 = (int *)((int)&DAT_00433310 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar2 = (_FileHandle & 0x1fU) * 8;
  if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) == 0) {
    _DAT_00429804 = 9;
    _DAT_00429808 = 0;
    return -1;
  }
  if ((_FileHandle == 1) || (_FileHandle == 2)) {
    iVar3 = __get_osfhandle(2);
    iVar4 = __get_osfhandle(1);
    if (iVar3 != iVar4) goto LAB_004259eb;
  }
  else {
LAB_004259eb:
    hObject = (HANDLE)__get_osfhandle(_FileHandle);
    BVar5 = CloseHandle(hObject);
    if (BVar5 == 0) {
      DVar6 = GetLastError();
      goto LAB_00425a0b;
    }
  }
  DVar6 = 0;
LAB_00425a0b:
  __free_osfhnd(_FileHandle);
  if (DVar6 == 0) {
    *(undefined1 *)(*piVar1 + 4 + iVar2) = 0;
    return 0;
  }
  __dosmaperr(DVar6);
  return -1;
}


// ==== __freebuf @ 00425a60

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    _free(_File->_base);
    _File->_ptr = (char *)0x0;
    _File->_flag = _File->_flag & 0xfffffbf7;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}


