// ==== FUN_00401000 @ 00401000

HGLOBAL __cdecl FUN_00401000(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00411020 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00413180 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_00413180 + local_c * 4),hResInfo);
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
    if (DAT_00411020 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00413180 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_00413180 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_00413180 + local_c * 4),hResInfo);
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
    for (local_18 = 0; local_18 < DAT_00411020; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_00413180 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_00413180 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_00413180 + local_18 * 4),hResInfo);
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
    if (DAT_00411020 <= local_18) {
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_00413180 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_00413180 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_00413180 + local_18 * 4),local_14);
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
    if (DAT_00411020 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_00413180 + local_c * 4),param_2,param_3);
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
    if (DAT_00411020 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_00413180 + local_c * 4),param_2);
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
    if (DAT_00411020 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_00413180 + local_c * 4),param_2,param_3,param_4,0);
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
    if (DAT_00411020 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_00413180 + local_c * 4),param_2);
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
    if (DAT_00411020 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_00413180 + local_c * 4),param_2);
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
    if (DAT_00411020 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_00413180 + local_c * 4),param_2);
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
    if (DAT_00411020 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_00413180 + local_c * 4),param_2,param_3,param_4);
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
    if (DAT_00411020 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_00413180 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040167a @ 0040167a

void FUN_0040167a(void)

{
  DAT_00411020 = 0;
  return;
}


// ==== FUN_00401694 @ 00401694

bool __cdecl FUN_00401694(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00411020 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_00413180 + DAT_00411020 * 4) = param_1;
    DAT_00411020 = DAT_00411020 + 1;
  }
  return bVar1;
}


// ==== FUN_004016d3 @ 004016d3

undefined4 __cdecl FUN_004016d3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00411020 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_00413180 + DAT_00411020 * 4) = pHVar2;
      DAT_00411020 = DAT_00411020 + 1;
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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_004112ac,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0040d140(param_2,local_410);
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
    FUN_0040d150(local_104,(uint *)&DAT_004112e0);
  }
  FUN_0040d150(local_104,param_1);
  FUN_0040d140(param_1,local_104);
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
  FUN_00401733(s_Shared_Path_004112e4,local_104);
  FUN_0040d150(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Shared_Path_004112f0,local_104);
    FUN_0040d150(local_104,(uint *)&DAT_004112fc);
    FUN_0040d150(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040d140(local_104,(uint *)s___shared__00411300);
      FUN_0040d150(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040d140(local_104,(uint *)&DAT_0041130c);
        FUN_0040d150(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040d140(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040d140(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040d140(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040d140(param_1,local_104);
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
  FUN_00401733(s_Help_Path_00411310,local_104);
  FUN_0040d150(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Help_Path_0041131c,local_104);
    FUN_0040d150(local_104,(uint *)&DAT_00411328);
    FUN_0040d150(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040d140(local_104,(uint *)&DAT_0041132c);
      FUN_0040d150(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040d140(local_104,(uint *)s___shared__00411330);
        FUN_0040d150(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040d140(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040d140(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040d140(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040d140(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00401c43 @ 00401c43

undefined4 __cdecl FUN_00401c43(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_004112a8 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00413280 + DAT_004112a8 * 4) = param_1;
    DAT_004112a8 = DAT_004112a8 + 1;
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
  
  for (local_8 = 0; local_8 < DAT_004112a8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00413280 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00413280 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00413280 + local_8 * 4) = 0;
  }
  DAT_004112a8 = 0;
  return;
}


// ==== FUN_00401d00 @ 00401d00

undefined4 __cdecl FUN_00401d00(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_2 < *param_1) || (param_3 < param_1[1])) || (param_1[2] < param_2)) ||
     (param_1[3] < param_3)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_00401d57 @ 00401d57

void FUN_00401d57(void)

{
  _memset(&DAT_00414380,0,0x480);
  DAT_0041133c = 0;
  DAT_00411340 = 0xffffffff;
  return;
}


// ==== FUN_00401d8f @ 00401d8f

bool __cdecl FUN_00401d8f(void *param_1)

{
  bool bVar1;
  
  bVar1 = DAT_0041133c < 0x1f;
  if (bVar1) {
    FID_conflict__memcpy(&DAT_00414380 + DAT_0041133c * 0x24,param_1,0x24);
    DAT_0041133c = DAT_0041133c + 1;
  }
  return bVar1;
}


// ==== FUN_00401ddd @ 00401ddd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00401ddd(HWND param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == 0x200) {
    if (-1 < DAT_00411340) {
      local_8 = param_4 & 0xffff;
      local_c = param_4 >> 0x10;
      local_10 = DAT_00411340;
      local_20 = *(int *)(&DAT_00414384 + DAT_00411340 * 0x24);
      local_1c = *(undefined4 *)(&DAT_00414388 + DAT_00411340 * 0x24);
      local_18 = *(undefined4 *)(&DAT_0041438c + DAT_00411340 * 0x24);
      local_14 = *(undefined4 *)(&DAT_00414390 + DAT_00411340 * 0x24);
      if ((-1 < DAT_00411344) && (iVar1 = FUN_00401d00(&local_20,local_8,local_c), iVar1 == 0)) {
        FUN_004039b9(0);
        SelectPalette(DAT_00419160,DAT_00411888,0);
        RealizePalette(DAT_00419160);
        FUN_0040233c(DAT_00419160,(int)(&DAT_00414380 + local_10 * 0x24),0);
        FUN_004039ff(0);
        DAT_00411344 = -1;
      }
      if ((DAT_00411344 < 0) && (iVar1 = FUN_00401d00(&local_20,local_8,local_c), iVar1 != 0)) {
        DAT_00411344 = DAT_00411340;
        FUN_004039b9(0);
        SelectPalette(DAT_00419160,DAT_00411888,0);
        RealizePalette(DAT_00419160);
        FUN_0040233c(DAT_00419160,(int)(&DAT_00414380 + local_10 * 0x24),1);
        FUN_004039ff(0);
      }
      return 0;
    }
  }
  else if (param_2 == 0x201) {
    if (DAT_00411344 < 0) {
      _DAT_00411348 = param_4 & 0xffff;
      _DAT_0041134c = param_4 >> 0x10;
      local_10 = 0;
      local_c = _DAT_0041134c;
      local_8 = _DAT_00411348;
      do {
        if (DAT_0041133c <= local_10) {
          return 0;
        }
        local_20 = *(int *)(&DAT_00414384 + local_10 * 0x24);
        local_1c = *(undefined4 *)(&DAT_00414388 + local_10 * 0x24);
        local_18 = *(undefined4 *)(&DAT_0041438c + local_10 * 0x24);
        local_14 = *(undefined4 *)(&DAT_00414390 + local_10 * 0x24);
        iVar1 = FUN_00401d00(&local_20,local_8,local_c);
        if (iVar1 != 0) {
          SetCapture(param_1);
          DAT_00411340 = local_10;
          DAT_00411344 = local_10;
          if (*(int *)(&DAT_004143a0 + local_10 * 0x24) != 0) {
            FUN_004039b9(0);
            SelectPalette(DAT_00419160,DAT_00411888,0);
            RealizePalette(DAT_00419160);
            FUN_0040233c(DAT_00419160,(int)(&DAT_00414380 + local_10 * 0x24),2);
            FUN_004039ff(0);
            Sleep(100);
            SendMessageA(param_1,0x402,*(WPARAM *)(&DAT_00414380 + local_10 * 0x24),2);
            return 1;
          }
          if (*(int *)(&DAT_0041439c + local_10 * 0x24) != 0) {
            FUN_004039b9(0);
            SelectPalette(DAT_00419160,DAT_00411888,0);
            RealizePalette(DAT_00419160);
            FUN_0040233c(DAT_00419160,(int)(&DAT_00414380 + local_10 * 0x24),1);
            FUN_004039ff(0);
            SendMessageA(param_1,0x402,*(WPARAM *)(&DAT_00414380 + local_10 * 0x24),1);
            return 1;
          }
        }
        local_10 = local_10 + 1;
      } while( true );
    }
  }
  else if (param_2 == 0x202) {
    if (-1 < DAT_00411340) {
      ReleaseCapture();
      DAT_00411340 = -1;
    }
    if (((-1 < DAT_00411344) && (DAT_00411344 < DAT_0041133c)) &&
       (local_10 = DAT_00411344, *(int *)(&DAT_00414398 + DAT_00411344 * 0x24) != 0)) {
      FUN_004039b9(0);
      SelectPalette(DAT_00419160,DAT_00411888,0);
      RealizePalette(DAT_00419160);
      FUN_0040233c(DAT_00419160,(int)(&DAT_00414380 + local_10 * 0x24),0);
      FUN_004039ff(0);
      SendMessageA(param_1,0x402,*(WPARAM *)(&DAT_00414380 + local_10 * 0x24),0);
      local_8 = param_4 & 0xffff;
      local_c = param_4 >> 0x10;
      local_20 = *(int *)(&DAT_00414384 + local_10 * 0x24);
      local_1c = *(undefined4 *)(&DAT_00414388 + local_10 * 0x24);
      local_18 = *(undefined4 *)(&DAT_0041438c + local_10 * 0x24);
      local_14 = *(undefined4 *)(&DAT_00414390 + local_10 * 0x24);
      iVar1 = FUN_00401d00(&local_20,local_8,local_c);
      if (iVar1 != 0) {
        SendMessageA(param_1,0x402,*(WPARAM *)(&DAT_00414380 + local_10 * 0x24),3);
        DAT_00411344 = 0xffffffff;
        return 1;
      }
    }
    DAT_00411344 = 0xffffffff;
    return 0;
  }
  return 0;
}


// ==== FUN_0040233c @ 0040233c

void __cdecl FUN_0040233c(HDC param_1,int param_2,int param_3)

{
  if ((((param_3 == 0) || (param_3 == 1)) || (param_3 == 2)) &&
     (*(int *)(param_2 + 0x18 + param_3 * 4) != 0)) {
    FUN_00403a8a(param_1,*(HANDLE *)(param_2 + 0x18 + param_3 * 4),*(int *)(param_2 + 4),
                 *(int *)(param_2 + 8));
  }
  return;
}


// ==== FUN_004023a0 @ 004023a0

void __cdecl FUN_004023a0(HDC param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0041133c; local_8 = local_8 + 1) {
    if (((*(int *)(&DAT_00414394 + local_8 * 0x24) == 0) ||
        (*(int *)(&DAT_00414394 + local_8 * 0x24) == 1)) &&
       (*(int *)(&DAT_00414398 + *(int *)(&DAT_00414394 + local_8 * 0x24) * 4 + local_8 * 0x24) != 0
       )) {
      FUN_00403a8a(param_1,*(HANDLE *)
                            (&DAT_00414398 +
                            *(int *)(&DAT_00414394 + local_8 * 0x24) * 4 + local_8 * 0x24),
                   *(int *)(&DAT_00414384 + local_8 * 0x24),*(int *)(&DAT_00414388 + local_8 * 0x24)
                  );
    }
  }
  return;
}


// ==== FUN_00402468 @ 00402468

undefined4 __cdecl
FUN_00402468(HDC param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0041133c <= local_8) {
      return 0;
    }
    if (*(int *)(&DAT_00414380 + local_8 * 0x24) == param_2) break;
    local_8 = local_8 + 1;
  }
  *(undefined4 *)(&DAT_00414398 + local_8 * 0x24) = param_3;
  *(undefined4 *)(&DAT_0041439c + local_8 * 0x24) = param_4;
  *(undefined4 *)(&DAT_004143a0 + local_8 * 0x24) = param_5;
  if (param_1 != (HDC)0x0) {
    FUN_0040233c(param_1,(int)(&DAT_00414380 + local_8 * 0x24),0);
  }
  return 1;
}


// ==== FUN_00402520 @ 00402520

int __cdecl FUN_00402520(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0040253f @ 0040253f

void FUN_0040253f(void)

{
  _memset(&DAT_00417900,0,0x370);
  _memset(&DAT_00414828,0,0x30d0);
  FID_conflict__memcpy(&DAT_00414828,s_MD_PACK_00411398,8);
  DAT_00417528 = 0;
  DAT_00417529 = 0;
  DAT_0041752a = 0;
  DAT_00414832 = 0xc;
  _memset(&DAT_004174fc,0,0x28);
  FID_conflict__memcpy(&DAT_004174ec,s_LINEUP_004114a0,0xb);
  return;
}


// ==== FUN_004025d8 @ 004025d8

undefined4 FUN_004025d8(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0040253f();
  hFile = _lopen(s_MSPuzzle_dat_004113a0,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00414828,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_004174ec,s_LINEUP_004114a0,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00414828,s_MD_PACK_00411398,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00417928 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_00417560 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00417900 + local_10 * 0x2c,&DAT_00417538 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00417928 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00417928 + local_10 * 0x2c) = 0;
        }
      }
      DAT_0041214c = (uint)(DAT_00417528 == '\0');
      DAT_00412148 = (uint)(DAT_00417529 == '\0');
      DAT_0041136c = (uint)(DAT_0041752a == '\0');
      FID_conflict__memcpy(&DAT_00411370,&DAT_004174fc,0x28);
      DAT_00411358 = (uint)DAT_00417524;
      if ((DAT_00411358 == 0) || (10 < DAT_00411358)) {
        DAT_00411358 = 1;
      }
      DAT_0041135c = (uint)DAT_00417525;
      if ((DAT_0041135c == 0) || (4 < DAT_0041135c)) {
        DAT_0041135c = 1;
      }
      DAT_00411360 = (uint)(DAT_00417526 == '\0');
      DAT_00411364 = (uint)(DAT_00417527 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0040253f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00402868 @ 00402868

undefined4 __cdecl FUN_00402868(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00417928 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_00402905 @ 00402905

int __cdecl FUN_00402905(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00417928 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00417900 + (local_1c + 1) * 0x2c,&DAT_00417900 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00417900 + local_1c * 0x2c,&DAT_00411370,0x28);
    *(int *)(&DAT_00417928 + local_1c * 0x2c) = param_1;
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


// ==== FUN_00402a49 @ 00402a49

void FUN_00402a49(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00417538,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00417538 + local_c * 0x30,&DAT_00417900 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_00417560 + local_c * 0x30) =
         *(undefined4 *)(&DAT_00417928 + local_c * 0x2c);
  }
  DAT_00417528 = DAT_0041214c == 0;
  DAT_00417529 = DAT_00412148 == 0;
  DAT_0041752a = DAT_0041136c == 0;
  DAT_00417524 = (undefined1)DAT_00411358;
  DAT_00417525 = (undefined1)DAT_0041135c;
  DAT_00417526 = DAT_00411360 == 0;
  DAT_00417527 = DAT_00411364 == 0;
  _memset(&DAT_004174fc,0,0x28);
  FID_conflict__memcpy(&DAT_004174fc,&DAT_00411370,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_004113a0,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_004113a0,0);
  }
  _lwrite(local_8,&DAT_00414828,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_00402c12 @ 00402c12

void FUN_00402c12(void)

{
  undefined4 local_8;
  
  for (local_8 = 1; local_8 < 0xb; local_8 = local_8 + 1) {
    if (local_8 == 1) {
      DAT_00414804 = 1000;
    }
    else {
      *(int *)(local_8 * 4 + 0x414800) = *(int *)(local_8 * 4 + 0x4147fc) + local_8 * 1000;
    }
  }
  return;
}


// ==== FUN_00402c90 @ 00402c90

void FUN_00402c90(void)

{
  int local_dc;
  int local_d8;
  undefined1 local_d4 [52];
  undefined1 local_a0 [52];
  undefined1 local_6c [52];
  undefined1 local_38 [52];
  
  for (local_dc = 0; local_dc < 0xc; local_dc = local_dc + 1) {
    FID_conflict__memcpy(local_6c,&DAT_004114b0 + local_dc * 0x31,0x31);
    FUN_00402fad((int)local_6c,(int)local_38);
    for (local_d8 = 0; local_d8 < 4; local_d8 = local_d8 + 1) {
      FUN_00402dc6((int)local_6c,(int)local_a0,local_d8);
      FUN_00402dc6((int)local_38,(int)local_d4,local_d8);
      FID_conflict__memcpy(&DAT_00417c70 + (local_dc * 8 + local_d8 * 2) * 0x31,local_a0,0x31);
      FID_conflict__memcpy(&DAT_00417c70 + (local_dc * 8 + local_d8 * 2 + 1) * 0x31,local_d4,0x31);
    }
  }
  return;
}


// ==== FUN_00402dc6 @ 00402dc6

void __cdecl FUN_00402dc6(int param_1,int param_2,undefined4 param_3)

{
  int local_c;
  int local_8;
  
  switch(param_3) {
  case 0:
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        *(undefined1 *)(local_c + local_8 * 7 + param_2) =
             *(undefined1 *)(local_c + local_8 * 7 + param_1);
      }
    }
    break;
  case 1:
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        *(undefined1 *)(local_c + local_8 * 7 + param_2) =
             *(undefined1 *)((6 - local_c) * 7 + local_8 + param_1);
      }
    }
    break;
  case 2:
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        *(undefined1 *)(local_c + local_8 * 7 + param_2) =
             *(undefined1 *)(((6 - local_8) * 7 - local_c) + 6 + param_1);
      }
    }
    break;
  case 3:
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        *(undefined1 *)(local_c + local_8 * 7 + param_2) =
             *(undefined1 *)((6 - local_8) + local_c * 7 + param_1);
      }
    }
  }
  return;
}


// ==== FUN_00402fad @ 00402fad

void __cdecl FUN_00402fad(int param_1,int param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 7; local_c = local_c + 1) {
      *(undefined1 *)(local_8 * 7 + local_c + param_2) =
           *(undefined1 *)((6 - local_c) + local_8 * 7 + param_1);
    }
  }
  return;
}


// ==== FUN_00403030 @ 00403030

undefined4 __cdecl FUN_00403030(HDC param_1)

{
  LPCSTR pCVar1;
  HBITMAP pHVar2;
  int local_8;
  
  DAT_00419138 = FUN_00403b20(param_1,s_TITLE_00411720);
  DAT_00418f4c = FUN_00403b20(param_1,s_GAMEOVER_00411728);
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_SQUARE__00411734,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00418f60 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_SMALLSQUARE__0041173c,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00418ee0 + local_8 * 4) = pHVar2;
  }
  DAT_00418edc = FUN_00403b20(param_1,s_SQUARE_E_0041174c);
  DAT_00418f50 = FUN_00403b20(param_1,s_SMALLSQUARE_E_00411758);
  DAT_0041915c = FUN_00403b20(param_1,s_BORDER_H_00411768);
  DAT_00419158 = FUN_00403b20(param_1,s_BORDER_V_00411774);
  DAT_00418f78 = FUN_00403b20(param_1,s_ARROW_D_00411780);
  DAT_00418f54 = FUN_00403b20(param_1,s_ARROW_L_00411788);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_BREAK_E_00411790,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00419140 + local_8 * 4) = pHVar2;
  }
  DAT_00419150 = FUN_00403b20(param_1,s_BONUS_00411798);
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)&DAT_004117a0,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00418f10 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)&DAT_004117a8,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00418f20 + local_8 * 4) = pHVar2;
  }
  DAT_00418f00 = FUN_00403b20(param_1,s_B_U_0_004117b0);
  DAT_00418f08 = FUN_00403b20(param_1,s_B_U_2_004117b8);
  DAT_00418f0c = FUN_00403b20(param_1,s_B_U_3_004117c0);
  DAT_00418f34 = FUN_00403b20(param_1,s_NEW_0_004117c8);
  DAT_00418f38 = FUN_00403b20(param_1,s_NEW_1_004117d0);
  DAT_00418f3c = FUN_00403b20(param_1,s_NEW_2_004117d8);
  DAT_00419104 = FUN_00403b20(param_1,s_PAUSE_0_004117e0);
  DAT_00418f7c = FUN_00403b20(param_1,s_PAUSE_1_004117e8);
  DAT_00419100 = FUN_00403b20(param_1,s_PAUSE_2_004117f0);
  DAT_0041910c = FUN_00403b20(param_1,s_BREAK_004117f8);
  DAT_00418ed4 = FUN_00403b20(param_1,s_PLAY_0_00411800);
  DAT_00418ed0 = FUN_00403b20(param_1,s_PLAY_1_00411808);
  DAT_00418ed8 = FUN_00403b20(param_1,s_PLAY_2_00411810);
  DAT_00418f40 = FUN_00403b20(param_1,s_STEP_0_00411818);
  DAT_00418f48 = FUN_00403b20(param_1,s_STEP_1_00411820);
  DAT_00418f44 = FUN_00403b20(param_1,s_STEP_2_00411828);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_DIGIT__00411830,local_8,1);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00419110 + local_8 * 4) = pHVar2;
  }
  DAT_00419108 = FUN_00403b20(param_1,s_DIGIT_E_00411838);
  DAT_00418f58 = FUN_00403b20(param_1,s_SCORE_00411840);
  DAT_00419154 = FUN_00403b20(param_1,s_LEVEL_00411848);
  for (local_8 = 0; local_8 < DAT_0041170c; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_TimeBonus_00411850,local_8,2);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00419010 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < DAT_00411710; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_ClearBonus_0041185c,local_8,2);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00419040 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < DAT_00411714; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_ScoreBonus_00411868,local_8,2);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_00419070 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < DAT_00411718; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_GARBAGE_00411874,local_8,2);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_004190a0 + local_8 * 4) = pHVar2;
  }
  for (local_8 = 0; local_8 < DAT_0041171c; local_8 = local_8 + 1) {
    pCVar1 = FUN_004038f0((uint *)s_BonusAdd_0041187c,local_8,2);
    pHVar2 = FUN_00403b20(param_1,pCVar1);
    *(HBITMAP *)(&DAT_004190d0 + local_8 * 4) = pHVar2;
  }
  return 1;
}


// ==== FUN_004035e1 @ 004035e1

void FUN_004035e1(void)

{
  int local_c;
  int local_8;
  
  if (DAT_00419138 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00419138);
  }
  DAT_00419138 = (HGDIOBJ)0x0;
  if (DAT_00418f4c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00418f4c);
  }
  DAT_00418f4c = (HGDIOBJ)0x0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00418f60 + local_8 * 4));
  }
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00418ee0 + local_8 * 4));
  }
  DeleteObject(DAT_00418edc);
  DeleteObject(DAT_00418f50);
  DeleteObject(DAT_0041915c);
  DeleteObject(DAT_00419158);
  DeleteObject(DAT_00418f78);
  DeleteObject(DAT_00418f54);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00419140 + local_8 * 4));
  }
  DeleteObject(DAT_00419150);
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00418f10 + local_8 * 4));
  }
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00418f20 + local_8 * 4));
  }
  DeleteObject(DAT_00418f00);
  DeleteObject(DAT_00418f08);
  DeleteObject(DAT_00418f0c);
  DeleteObject(DAT_00418f34);
  DeleteObject(DAT_00418f38);
  DeleteObject(DAT_00418f3c);
  DeleteObject(DAT_00419104);
  DeleteObject(DAT_00418f7c);
  DeleteObject(DAT_00419100);
  DeleteObject(DAT_0041910c);
  DeleteObject(DAT_00418ed4);
  DeleteObject(DAT_00418ed0);
  DeleteObject(DAT_00418ed8);
  DeleteObject(DAT_00418f40);
  DeleteObject(DAT_00418f48);
  DeleteObject(DAT_00418f44);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00419110 + local_8 * 4));
  }
  DeleteObject(DAT_00419108);
  DeleteObject(DAT_00418f58);
  DeleteObject(DAT_00419154);
  for (local_c = 3; local_c < 8; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < *(int *)(&DAT_00411700 + local_c * 4); local_8 = local_8 + 1) {
      DeleteObject(*(HGDIOBJ *)(&DAT_00418f80 + local_8 * 4 + local_c * 0x30));
    }
  }
  return;
}


// ==== FUN_004038f0 @ 004038f0

undefined * __cdecl FUN_004038f0(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0040d140((uint *)&DAT_004195b8,param_1);
  sVar1 = _strlen(&DAT_004195b8);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_004195b7)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_004195b8)[param_3 + sVar1] = 0;
  return &DAT_004195b8;
}


// ==== FUN_004039b9 @ 004039b9

void __cdecl FUN_004039b9(int param_1)

{
  if (param_1 == 0) {
    DAT_00419160 = GetDC(DAT_004191a8);
  }
  else {
    DAT_00419160 = BeginPaint(DAT_004191a8,(LPPAINTSTRUCT)&DAT_00419168);
  }
  return;
}


// ==== FUN_004039ff @ 004039ff

void __cdecl FUN_004039ff(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_004191a8,DAT_00419160);
  }
  else {
    EndPaint(DAT_004191a8,(PAINTSTRUCT *)&DAT_00419168);
  }
  return;
}


// ==== FUN_00403a41 @ 00403a41

bool __cdecl FUN_00403a41(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_00403a8a @ 00403a8a

bool __cdecl FUN_00403a8a(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_00403b20 @ 00403b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_00403b20(HDC param_1,LPCSTR param_2)

{
  DWORD DVar1;
  HGLOBAL hResData;
  LPVOID _Src;
  HGLOBAL hMem;
  HPALETTE local_2c;
  int local_28;
  SIZE_T local_10;
  BITMAPINFOHEADER *local_c;
  HBITMAP local_8;
  
  local_2c = (HPALETTE)0x0;
  hResData = FUN_00401078(DAT_0041b754,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_0041188c = 0;
        _DAT_004191b0 = 0x300;
        _DAT_004191b2 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_004191b4)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_004191b5)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_004191b6)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_004191b7)[local_28 * 4] = 0;
        }
        if (DAT_00411888 == (HPALETTE)0x0) {
          DAT_00411888 = CreatePalette((LOGPALETTE *)&DAT_004191b0);
        }
        local_2c = SelectPalette(param_1,DAT_00411888,0);
        RealizePalette(param_1);
      }
      local_8 = CreateDIBitmap(param_1,local_c,4,&local_c[1].biSize + DVar1,(BITMAPINFO *)local_c,0)
      ;
      if ((local_c->biBitCount == 8) && (local_2c != (HPALETTE)0x0)) {
        SelectPalette(param_1,local_2c,0);
      }
      GlobalUnlock(hMem);
      GlobalFree(hMem);
      FreeResource(hResData);
    }
  }
  return local_8;
}


// ==== FUN_00403d44 @ 00403d44

HGLOBAL __cdecl FUN_00403d44(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_00401078(DAT_0041b754,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_00403df0 @ 00403df0

void __cdecl FUN_00403df0(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00411d58 = 2;
  }
  DAT_00419a54 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00403e33 @ 00403e33

void __cdecl FUN_00403e33(HWND param_1)

{
  if (DAT_00419a54 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00419a54);
  }
  return;
}


// ==== FUN_00403e64 @ 00403e64

void __cdecl FUN_00403e64(uint *param_1)

{
  FUN_0040d140((uint *)&DAT_00411d60,param_1);
  return;
}


// ==== FUN_00403e85 @ 00403e85

void __cdecl FUN_00403e85(HWND param_1)

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


// ==== FUN_00403fbd @ 00403fbd

INT_PTR __cdecl FUN_00403fbd(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040141d(DAT_0041b754,s_RESETSCORE_00411e90,param_1,FUN_0040656f);
  return IVar1;
}


// ==== FUN_00403ff2 @ 00403ff2

INT_PTR FUN_00403ff2(void)

{
  INT_PTR IVar1;
  
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_QUICKHELPBMP_00411e9c);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_0041b754,s_EXITGAME_00411eac,DAT_004191a8,FUN_00404718);
  DAT_00411ba0 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_0040406a @ 0040406a

INT_PTR FUN_0040406a(void)

{
  INT_PTR IVar1;
  
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_QUICKHELPBMP_00411eb8);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_0041b754,s_NEWGAME_00411ec8,DAT_004191a8,FUN_00404718);
  DAT_00411ba0 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_004040e2 @ 004040e2

void FUN_004040e2(void)

{
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_ABOUTBMP_00411ed0);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  FUN_0040141d(DAT_0041b754,s_ABOUT_00411edc,DAT_004191a8,FUN_004048af);
  DAT_00411ba0 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404151 @ 00404151

void __cdecl FUN_00404151(HWND param_1)

{
  FUN_0040141d(DAT_0041b754,s_CREDITS_00411ee4,param_1,FUN_00404b95);
  return;
}


// ==== FUN_0040417d @ 0040417d

void __cdecl FUN_0040417d(HWND param_1)

{
  FUN_0040141d(DAT_0041b754,s_SYSTEMINFODIALOG_00411eec,param_1,FUN_00404d26);
  return;
}


// ==== FUN_004041a9 @ 004041a9

void FUN_004041a9(void)

{
  DAT_00411ba4 = 1;
  FUN_00403e64((uint *)s_QUICKHELPBMP_00411f00);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  FUN_0040141d(DAT_0041b754,s_QUICKHELPDIALOG_00411f10,DAT_004191a8,FUN_00405530);
  DAT_00411ba4 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return;
}


// ==== FUN_00404218 @ 00404218

void __cdecl FUN_00404218(int param_1)

{
  if (((2 < param_1) && (param_1 < 9)) && (*(int *)(&DAT_0041b6f8 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_0041b6f8 + param_1 * 4) = 1;
    DAT_00411ba4 = 1;
    Sleep(500);
    switch(param_1) {
    case 3:
      FUN_00403e64((uint *)s_TIMEBONUS00_00411f20);
      FUN_0040141d(DAT_0041b754,s_TIMEPOINTDIALOG_00411f2c,DAT_004191a8,FUN_004052c4);
      break;
    case 4:
      FUN_00403e64((uint *)s_CLEARBONUS00_00411f3c);
      FUN_0040141d(DAT_0041b754,s_CLEARPOINTDIALOG_00411f4c,DAT_004191a8,FUN_004052c4);
      break;
    case 5:
      FUN_00403e64((uint *)s_SCOREBONUS00_00411f60);
      FUN_0040141d(DAT_0041b754,s_SCOREPOINTDIALOG_00411f70,DAT_004191a8,FUN_004052c4);
      break;
    case 6:
      FUN_00403e64((uint *)s_GARBAGE00_00411f84);
      FUN_0040141d(DAT_0041b754,s_GARBAGEPOINTDIALOG_00411f90,DAT_004191a8,FUN_004052c4);
      break;
    case 7:
      FUN_00403e64((uint *)s_BONUSADD00_00411fa4);
      FUN_0040141d(DAT_0041b754,s_BONUSPOINTDIALOG_00411fb0,DAT_004191a8,FUN_004052c4);
      break;
    case 8:
      FUN_00403e64((uint *)s_BONUSADD00_00411fc4);
      FUN_0040141d(DAT_0041b754,s_NEWBONUSDIALOG_00411fd0,DAT_004191a8,FUN_004052c4);
    }
    DAT_00411ba4 = 0;
    FUN_00409eb8();
    FUN_00402a49();
    InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  }
  return;
}


// ==== FUN_00404401 @ 00404401

void FUN_00404401(void)

{
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_CUPBMP_00411fe0);
  FUN_0040141d(DAT_0041b754,s_YOURNAME_00411fe8,DAT_004191a8,FUN_0040579c);
  DAT_00411ba0 = 0;
  return;
}


// ==== FUN_00404450 @ 00404450

void FUN_00404450(void)

{
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_CUPBMP_00411ff4);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  FUN_0040141d(DAT_0041b754,s_BALLSTOP_00411ffc,DAT_004191a8,FUN_00405adb);
  DAT_00411ba0 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return;
}


// ==== FUN_004044bf @ 004044bf

void FUN_004044bf(void)

{
  DAT_00411ba0 = 1;
  FUN_00403e64((uint *)s_OPTIONSBMP_00412008);
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  FUN_0040141d(DAT_0041b754,s_OPTIONS_00412014,DAT_004191a8,FUN_00405e58);
  DAT_00411ba0 = 0;
  InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040452e @ 0040452e

void __cdecl FUN_0040452e(HWND param_1)

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
  local_8 = FUN_00403b20(pHVar1,&DAT_00411d60);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00403a41(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00411888,0);
  RealizePalette(pHVar1);
  FUN_00403a8a(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00404623 @ 00404623

void __cdecl FUN_00404623(HWND param_1)

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
  ho = FUN_00403b20(pHVar1,s_QUICKHELPBMP_0041201c);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00403a41(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00411888,0);
  RealizePalette(pHVar1);
  FUN_00403a8a(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_00404718 @ 00404718

UINT FUN_00404718(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403e85(param_1);
      DAT_0041b730 = param_1;
      DAT_0041b72c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040452e(DAT_0041b72c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041b730 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041b730);
      SelectPalette(hdc,DAT_00411888,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041b730,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041b730,(RECT *)0x0,0);
        InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
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


// ==== FUN_004048af @ 004048af

UINT FUN_004048af(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403e85(param_1);
      DAT_0041b75c = param_1;
      DAT_0041b758 = GetDlgItem(param_1,100);
      FUN_004015b0(DAT_0041b754,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00401733(&DAT_0041202c,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00401733(s_Product_ID_00412030,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040452e(DAT_0041b758);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0041b75c) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_0041b75c);
      SelectPalette(local_10c,DAT_00411888,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_0041b75c,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0041b75c,(RECT *)0x0,0);
      InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
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
      FUN_0040417d(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00404151(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00404b95 @ 00404b95

UINT FUN_00404b95(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403e85(param_1);
      DAT_0041b71c = param_1;
      DAT_0041b6ec = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040452e(DAT_0041b6ec);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0041b71c == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041b71c);
      SelectPalette(hdc,DAT_00411888,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041b71c,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041b71c,(RECT *)0x0,0);
        InvalidateRect(DAT_0041b75c,(RECT *)0x0,0);
        InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
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


// ==== FUN_00404d26 @ 00404d26

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00404d26(HWND param_1,int param_2,uint param_3)

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
    FUN_00403e85(param_1);
    _DAT_00419a44 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_0041203c,local_49c.dwMajorVersion,-1);
    FUN_0040d140((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412040);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_00412044,local_49c.dwMinorVersion,-1);
    FUN_0040d150((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412048);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_0041204c,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0040d150((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412050);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0040d150((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_00412054,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0040d140((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412058);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0040d140((uint *)local_404,(uint *)&DAT_0041205c);
    FUN_0040d150((uint *)local_404,(uint *)&local_4b4);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412060);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_00412064,local_4a0,-1);
    FUN_0040d150((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_00412068);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_0041208c,s_display_drv_00412080,s_Unknown_00412078,local_404,0x80,
               s_system_ini_0041206c);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120a0,local_4a0,-1);
    FUN_0040d140((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_004120a4);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120a8,local_4a0,-1);
    FUN_0040d150((uint *)local_404,puVar1);
    FUN_0040d150((uint *)local_404,(uint *)&DAT_004120ac);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120b0,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0040d150((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120b4,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0040d150((uint *)local_404,puVar1);
      FUN_0040d150((uint *)local_404,(uint *)&DAT_004120b8);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120c0,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0040d150((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_004038f0((uint *)&DAT_004120bc,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0040d150((uint *)local_404,puVar1);
      }
      FUN_0040d150((uint *)local_404,(uint *)&DAT_004120c4);
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


// ==== FUN_004052c4 @ 004052c4

UINT FUN_004052c4(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040452e(DAT_0041b6e8);
      }
      return 0;
    }
    FUN_00403e85(param_1);
    DAT_00419a38 = param_1;
    DAT_0041b6e8 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00411364 == 0);
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
      DAT_00411364 = (uint)(LVar2 == 0);
      FUN_00402a49();
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
      DAT_00411364 = (uint)(LVar2 == 0);
      FUN_00402a49();
      EndDialog(param_1,0);
      PostMessageA(DAT_004191a8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00419a38 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00419a38);
  SelectPalette(hdc,DAT_00411888,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00419a38,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00419a38,(RECT *)0x0,0);
    InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00405530 @ 00405530

UINT FUN_00405530(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040452e(DAT_00419a3c);
      }
      return 0;
    }
    FUN_00403e85(param_1);
    DAT_0041b6f0 = param_1;
    DAT_00419a3c = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00411360 == 0);
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
      DAT_00411360 = (uint)(LVar2 == 0);
      FUN_00402a49();
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
      DAT_00411360 = (uint)(LVar2 == 0);
      FUN_00402a49();
      EndDialog(param_1,0);
      PostMessageA(DAT_004191a8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0041b6f0 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0041b6f0);
  SelectPalette(hdc,DAT_00411888,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0041b6f0,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0041b6f0,(RECT *)0x0,0);
    InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040579c @ 0040579c

UINT FUN_0040579c(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_0040452e(DAT_00419a50);
      }
      return 0;
    }
    FUN_00403e85(param_1);
    DAT_0041b724 = param_1;
    DAT_00419a50 = GetDlgItem(param_1,100);
    if (DAT_00411d58 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00411370);
    _Size = 0x10;
    _Src = FUN_004038f0((uint *)&DAT_004120c8,DAT_00411350,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_0041b724 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_0041b724);
    SelectPalette(hdc,DAT_00411888,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_0041b724,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_0041b724,(RECT *)0x0,0);
      InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00411370,DAT_00411d58 * 0x11);
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


// ==== FUN_00405adb @ 00405adb

UINT FUN_00405adb(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00403e85(param_1);
      DAT_0041b668 = param_1;
      DAT_0041b720 = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00411e60) && (DAT_00411e60 < 10)) {
        SetDlgItemTextA(param_1,DAT_00411e60 + 0x33,&DAT_004120cc);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_004038f0((uint *)&DAT_004120d0,*(int *)(&DAT_00417928 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00417900 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040452e(DAT_0041b720);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0041b668) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041b668);
      SelectPalette(hdc,DAT_00411888,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_0041b668,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_0041b668,(RECT *)0x0,0);
        InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_00403fbd(DAT_0041b668), IVar5 == 1)) {
        if ((-1 < DAT_00411e60) && (DAT_00411e60 < 10)) {
          SetDlgItemTextA(param_1,DAT_00411e60 + 0x33,&DAT_004120d4);
        }
        DAT_00411e60 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00417928 + local_14 * 0x2c) = 0;
          _memset(&DAT_00417900 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_004038f0((uint *)&DAT_004120d8,*(int *)(&DAT_00417928 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00417900 + local_14 * 0x2c);
        }
        FUN_00402a49();
      }
    }
  }
  return 0;
}


// ==== FUN_00405e58 @ 00405e58

UINT FUN_00405e58(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_004191a8,s_LINEUP_HLP_00411890,1,0x32);
    }
    else if (param_2 == 0xf) {
      FUN_0040452e(DAT_00419a60);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00406002:
      hdc = GetDC(DAT_00419a48);
      SelectPalette(hdc,DAT_00411888,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_00419a48,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00419a48,(RECT *)0x0,0);
      InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00403e85(param_1);
      DAT_00419a48 = param_1;
      DAT_00419a60 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00412148;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0041214c;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0041136c;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x62,DAT_0041135c + 0x5e);
      if (DAT_00411d58 == 1) {
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
      DAT_0041b728 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_00411370);
      pCVar2 = FUN_004038f0((uint *)&DAT_004120dc,DAT_00411358,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x1000a);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_00412148 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_0041214c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_0041136c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0041135c = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0041135c = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0041135c = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0041135c = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_00411370,DAT_00411d58 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
          pcVar3 = FUN_004038f0((uint *)&DAT_004120ec,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_0040640b:
            DAT_00411358 = local_28;
            break;
          }
          pcVar3 = FUN_004038f0((uint *)&DAT_004120f0,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_0040640b;
        }
      case 2:
        DAT_00419a48 = (HWND)0x0;
        pHVar9 = DAT_0041b728;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_00411358;
          for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
            pcVar3 = FUN_004038f0((uint *)&DAT_004120e0,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_0040614b:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_004038f0((uint *)&DAT_004120e4,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_0040614b;
          }
          pCVar2 = FUN_004038f0((uint *)&DAT_004120e8,local_1c,-1);
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
        WinHelpA(DAT_004191a8,s_LINEUP_HLP_00411890,1,0x32);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_00419a48 == param_3) {
      return 0;
    }
    goto LAB_00406002;
  }
  return 0;
}


// ==== FUN_0040656f @ 0040656f

UINT FUN_0040656f(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403e85(param_1);
      DAT_0041b760 = param_1;
      DAT_00419a5c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00404623(DAT_00419a5c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0041b760) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0041b760);
      SelectPalette(hdc,DAT_00411888,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0041b760,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0041b668,(RECT *)0x0,0);
        InvalidateRect(DAT_0041b760,(RECT *)0x0,0);
        InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
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


// ==== FUN_00406715 @ 00406715

void __cdecl FUN_00406715(int param_1)

{
  FUN_004039b9(param_1);
  SelectPalette(DAT_00419160,DAT_00411888,0);
  RealizePalette(DAT_00419160);
  return;
}


// ==== FUN_00406751 @ 00406751

void FUN_00406751(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_0040d3e0(DVar1);
  return;
}


// ==== FUN_00406770 @ 00406770

int FUN_00406770(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_4c;
  int local_48;
  int local_44;
  int local_3c;
  int aiStack_38 [13];
  
  local_4c = DAT_00411bb8;
  if ((2 < DAT_00411354) && (DAT_00411bb8 < 2)) {
    local_4c = 2;
  }
  if ((5 < DAT_00411354) && (local_4c < 3)) {
    local_4c = 3;
  }
  if (7 < DAT_00411354) {
    local_4c = 4;
  }
  if (9 < DAT_00411354) {
    local_4c = 5;
  }
  local_44 = 0;
  for (local_48 = 0; local_48 < 0xc; local_48 = local_48 + 1) {
    local_44 = local_44 + *(int *)(local_4c * 0x34 + 0x411c20 + local_48 * 4);
    aiStack_38[local_48] = local_44;
  }
  iVar1 = _rand();
  local_48 = 0;
  while( true ) {
    if (0xb < local_48) {
      iVar1 = _rand();
      local_3c = iVar1 % 0x60 + 1;
      if (local_3c < 1) {
        local_3c = 1;
      }
      if (0x60 < local_3c) {
        local_3c = 0x60;
      }
      return local_3c;
    }
    if (iVar1 % local_44 + 1 < aiStack_38[local_48]) break;
    local_48 = local_48 + 1;
  }
  uVar2 = _rand();
  uVar3 = (int)uVar2 >> 0x1f;
  local_3c = (((uVar2 ^ uVar3) - uVar3 & 7 ^ uVar3) - uVar3) + local_48 * 8 + 1;
  if (local_3c < 1) {
    local_3c = 1;
  }
  if (local_3c < 0x61) {
    return local_3c;
  }
  return 0x60;
}


// ==== FUN_004068f3 @ 004068f3

int __cdecl FUN_004068f3(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 - 1;
  uVar2 = (int)uVar1 >> 0x1f;
  return (int)((((uVar1 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2) +
              ((int)(uVar1 + (uVar2 & 7)) >> 3) * 2) % 6;
}


// ==== FUN_00406934 @ 00406934

void __cdecl FUN_00406934(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((DAT_00411b98 == 0) && (DAT_00411b94 != 0)) && (DAT_00411ba8 == 0)) && (DAT_00411ba0 == 0))
  {
    switch(*(undefined4 *)(param_3 + 8)) {
    case 0:
      FUN_00403a8a(DAT_00419160,DAT_00418edc,param_1,param_2);
      break;
    case 1:
      iVar1 = FUN_004068f3(*(int *)(param_3 + 4));
      FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00418f60 + iVar1 * 4),param_1,param_2);
      break;
    case 2:
      FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00419140 + *(int *)(param_3 + 4) * 4),param_1,
                   param_2);
      break;
    case 3:
    case 5:
      if (*(int *)(&DAT_00411700 + *(int *)(param_3 + 8) * 4) + -1 < *(int *)(param_3 + 4)) {
        FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00418f80 + *(int *)(param_3 + 8) * 0x30),param_1,
                     param_2);
      }
      else {
        FUN_00403a8a(DAT_00419160,
                     *(HANDLE *)
                      (&DAT_00418f80 +
                      ((*(int *)(&DAT_00411700 + *(int *)(param_3 + 8) * 4) + -1) -
                      *(int *)(param_3 + 4)) * 4 + *(int *)(param_3 + 8) * 0x30),param_1,param_2);
      }
      break;
    case 4:
      FUN_00403a8a(DAT_00419160,
                   *(HANDLE *)
                    (&DAT_00418f80 +
                    (*(int *)(param_3 + 4) % DAT_00411710) * 4 + *(int *)(param_3 + 8) * 0x30),
                   param_1,param_2);
      break;
    case 6:
    case 7:
      if (*(int *)(&DAT_00411700 + *(int *)(param_3 + 8) * 4) + -1 < *(int *)(param_3 + 4)) {
        FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00418f80 + *(int *)(param_3 + 8) * 0x30),param_1,
                     param_2);
      }
      else {
        FUN_00403a8a(DAT_00419160,
                     *(HANDLE *)
                      (&DAT_00418f80 + *(int *)(param_3 + 4) * 4 + *(int *)(param_3 + 8) * 0x30),
                     param_1,param_2);
      }
    }
  }
  else {
    FUN_00403a8a(DAT_00419160,DAT_00418edc,param_1,param_2);
  }
  return;
}


// ==== FUN_00406ba5 @ 00406ba5

void __cdecl FUN_00406ba5(int param_1,int param_2)

{
  FUN_00406934((param_2 * 3 + -3) * 9 + DAT_00411bc0,(param_1 * 3 + -3) * 9 + DAT_00411bc4,
               (int)(&DAT_00419a68 + param_1 * 0x1c0 + param_2 * 0x1c));
  return;
}


// ==== FUN_00406c0e @ 00406c0e

void FUN_00406c0e(void)

{
  undefined4 local_14;
  undefined4 local_10;
  
  if (DAT_00411b90 == 0) {
    if (DAT_00411b9c == 0) {
      if ((((DAT_00411b98 == 0) && (DAT_00411ba8 == 0)) && (DAT_00411ba0 == 0)) &&
         (DAT_00411b94 != 0)) {
        for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
          for (local_14 = 1; local_14 < 0xf; local_14 = local_14 + 1) {
            FUN_00406ba5(local_10,local_14);
          }
        }
      }
      else {
        FUN_00403a8a(DAT_00419160,DAT_0041910c,DAT_00411bc0,DAT_00411bc4 + 0x51);
        for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
          for (local_14 = 1; local_14 < 0xf; local_14 = local_14 + 1) {
            if ((local_10 < 4) || (0xb < local_10)) {
              FUN_00406ba5(local_10,local_14);
            }
          }
        }
      }
    }
    else {
      FUN_00403a8a(DAT_00419160,DAT_00418f4c,DAT_00411bc0,DAT_00411bc4 + 0x51);
      for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
        for (local_14 = 1; local_14 < 0xf; local_14 = local_14 + 1) {
          if ((local_10 < 4) || (0xb < local_10)) {
            FUN_00406ba5(local_10,local_14);
          }
        }
      }
    }
  }
  else {
    FUN_00403a8a(DAT_00419160,DAT_00419138,DAT_00411bc0,DAT_00411bc4 + 0x51);
    for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
      for (local_14 = 1; local_14 < 0xf; local_14 = local_14 + 1) {
        if ((local_10 < 4) || (0xb < local_10)) {
          FUN_00406ba5(local_10,local_14);
        }
      }
    }
  }
  return;
}


// ==== FUN_00406e77 @ 00406e77

undefined4 __cdecl FUN_00406e77(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((((param_1 == 1) || (param_2 == 1)) || (param_1 == 0xe)) || (param_2 == 0xe)) {
    uVar1 = 0;
  }
  else if ((((((&DAT_00419a70)[param_1 * 0x70 + param_2 * 7] == 0) &&
             ((&DAT_00419a70)[(param_1 + -1) * 0x70 + (param_2 + -1) * 7] == 0)) &&
            (((&DAT_00419a70)[(param_1 + -1) * 0x70 + param_2 * 7] == 0 &&
             (((&DAT_00419a70)[(param_1 + -1) * 0x70 + (param_2 + 1) * 7] == 0 &&
              ((&DAT_00419a70)[param_1 * 0x70 + (param_2 + -1) * 7] == 0)))))) &&
           ((&DAT_00419a70)[param_1 * 0x70 + (param_2 + 1) * 7] == 0)) &&
          ((((&DAT_00419a70)[(param_1 + 1) * 0x70 + (param_2 + -1) * 7] == 0 &&
            ((&DAT_00419a70)[(param_1 + 1) * 0x70 + param_2 * 7] == 0)) &&
           ((&DAT_00419a70)[(param_1 + 1) * 0x70 + (param_2 + 1) * 7] == 0)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040701b @ 0040701b

void __cdecl FUN_0040701b(int param_1,byte param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_10;
  
  if (((DAT_00411b90 == 0) && (DAT_00411b9c == 0)) &&
     ((param_3 != 0 || ((DAT_00411bbc != 0 && ((param_2 & 1) == 0)))))) {
    for (local_10 = 1; local_10 < 0x1f5; local_10 = local_10 + 1) {
      iVar1 = _rand();
      iVar1 = iVar1 % 0xe + 1;
      iVar2 = _rand();
      iVar2 = iVar2 % 0xe + 1;
      iVar3 = FUN_00406e77(iVar1,iVar2);
      if (iVar3 != 0) {
        (&DAT_00419a70)[iVar1 * 0x70 + iVar2 * 7] = 2;
        uVar4 = _rand();
        uVar5 = (int)uVar4 >> 0x1f;
        *(uint *)(&DAT_00419a6c + iVar2 * 0x1c + iVar1 * 0x1c0) =
             ((uVar4 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5;
        if (param_1 == 0) {
          return;
        }
        FUN_00406ba5(iVar1,iVar2);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00407147 @ 00407147

int __cdecl FUN_00407147(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0040d420(param_2 - param_4);
  iVar2 = FUN_0040d420(param_1 - param_3);
  return iVar2 + iVar1;
}


// ==== FUN_00407179 @ 00407179

void FUN_00407179(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(1,1,local_8,local_c);
      if (iVar1 < 4) {
LAB_00407228:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(1,0xe,local_8,local_c);
        if (iVar1 < 4) goto LAB_00407228;
        iVar1 = FUN_00407147(0xe,1,local_8,local_c);
        if (iVar1 < 4) goto LAB_00407228;
        iVar1 = FUN_00407147(0xe,0xe,local_8,local_c);
        if (iVar1 < 4) goto LAB_00407228;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_0040728d @ 0040728d

void FUN_0040728d(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(1,1,local_8,local_c);
      if (iVar1 < 3) {
LAB_00407364:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(1,0xe,local_8,local_c);
        if (iVar1 < 3) goto LAB_00407364;
        iVar1 = FUN_00407147(0xe,1,local_8,local_c);
        if (iVar1 < 3) goto LAB_00407364;
        iVar1 = FUN_00407147(0xe,0xe,local_8,local_c);
        if ((iVar1 < 3) ||
           (((local_8 == 7 || (local_8 == 8)) && ((local_c == 7 || (local_c == 8))))))
        goto LAB_00407364;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_004073c9 @ 004073c9

void FUN_004073c9(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(1,1,local_8,local_c);
      if (iVar1 < 2) {
LAB_004074ec:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(1,0xe,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(0xe,1,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(0xe,0xe,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(7,7,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(8,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(8,7,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
        iVar1 = FUN_00407147(7,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_004074ec;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_00407551 @ 00407551

void FUN_00407551(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(7,7,local_8,local_c);
      if (iVar1 < 2) {
LAB_00407600:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(8,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407600;
        iVar1 = FUN_00407147(8,7,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407600;
        iVar1 = FUN_00407147(7,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407600;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_00407665 @ 00407665

void FUN_00407665(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(4,7,local_8,local_c);
      if (iVar1 < 2) {
LAB_00407714:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(4,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407714;
        iVar1 = FUN_00407147(0xb,7,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407714;
        iVar1 = FUN_00407147(0xb,8,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407714;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_00407779 @ 00407779

void FUN_00407779(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (0xe < local_8) {
      return;
    }
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      iVar1 = FUN_00407147(7,4,local_8,local_c);
      if (iVar1 < 2) {
LAB_00407828:
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar2 = _rand();
        uVar3 = (int)uVar2 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar2 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3;
      }
      else {
        iVar1 = FUN_00407147(8,4,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407828;
        iVar1 = FUN_00407147(7,0xb,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407828;
        iVar1 = FUN_00407147(8,0xb,local_8,local_c);
        if (iVar1 < 2) goto LAB_00407828;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_0040788d @ 0040788d

void FUN_0040788d(void)

{
  uint uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 1; local_8 < 0xf; local_8 = local_8 + 1) {
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      if (((local_8 == 7) || (local_8 == 8)) && ((local_c < 5 || (10 < local_c)))) {
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar1 = _rand();
        uVar2 = (int)uVar1 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2;
      }
    }
  }
  return;
}


// ==== FUN_00407955 @ 00407955

void FUN_00407955(void)

{
  uint uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 1; local_8 < 0xf; local_8 = local_8 + 1) {
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      if (((local_c == 7) || (local_c == 8)) && ((local_8 < 5 || (10 < local_8)))) {
        (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 2;
        uVar1 = _rand();
        uVar2 = (int)uVar1 >> 0x1f;
        *(uint *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
             ((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2;
      }
    }
  }
  return;
}


// ==== FUN_00407a1d @ 00407a1d

void FUN_00407a1d(void)

{
  uint uVar1;
  uint uVar2;
  int local_8;
  
  _memset(&DAT_00419a68,0,0x1c00);
  if (2 < DAT_00411bb8) {
    uVar1 = _rand();
    uVar2 = (int)uVar1 >> 0x1f;
    switch(((uVar1 ^ uVar2) - uVar2 & 7 ^ uVar2) - uVar2) {
    case 0:
      FUN_00407179();
      break;
    case 1:
      FUN_0040728d();
      break;
    case 2:
      FUN_004073c9();
      break;
    case 3:
      FUN_00407551();
      break;
    case 4:
      FUN_00407665();
      break;
    case 5:
      FUN_00407779();
      break;
    case 6:
      FUN_0040788d();
      break;
    case 7:
      FUN_00407955();
    }
  }
  if (DAT_00411bbc != 0) {
    for (local_8 = 1; local_8 <= DAT_00411354; local_8 = local_8 + 1) {
      FUN_0040701b(0,(byte)local_8,0);
    }
  }
  return;
}


// ==== FUN_00407b33 @ 00407b33

void __cdecl FUN_00407b33(int param_1,int param_2)

{
  undefined4 local_20 [5];
  int local_c;
  int local_8;
  
  if ((0 < param_1) && (param_1 < 0xd)) {
    local_8 = DAT_00411be0;
    local_c = (0xe - param_1) * 0x1b + DAT_00411be4;
    if (param_1 == 1) {
      FID_conflict__memcpy(local_20,&DAT_00418f10,0x14);
    }
    else if (param_1 == 0xc) {
      FID_conflict__memcpy(local_20,&DAT_00418f00,0x14);
    }
    else {
      FID_conflict__memcpy(local_20,&DAT_00418f20,0x14);
    }
    FUN_00403a8a(DAT_00419160,(HANDLE)local_20[param_2],local_8,local_c);
  }
  return;
}


// ==== FUN_00407bf3 @ 00407bf3

void FUN_00407bf3(void)

{
  uint local_8;
  
  if ((int)DAT_00411bb4 < 0xc) {
    FUN_0040caf3(3);
    DAT_00411bb4 = DAT_00411bb4 + 1;
    for (local_8 = 0xc; (int)DAT_00411bb4 <= (int)local_8; local_8 = local_8 - 1) {
      FUN_00407b33(local_8,2);
      if (DAT_00411bb4 == local_8) {
        if (DAT_00411364 == 0) {
          return;
        }
        PostMessageA(DAT_004191a8,0x111,0x137,8);
        return;
      }
      Sleep(10);
      FUN_00407b33(local_8,3);
      FUN_00407b33(local_8 - 1,1);
      Sleep(10);
      FUN_00407b33(local_8,0);
      FUN_00407b33(local_8 - 1,2);
      if ((local_8 & 3) == 0) {
        FUN_0040a323();
      }
    }
    if (DAT_00411364 != 0) {
      PostMessageA(DAT_004191a8,0x111,0x137,8);
    }
  }
  return;
}


// ==== FUN_00407d10 @ 00407d10

void FUN_00407d10(void)

{
  undefined4 local_8;
  
  if (0 < DAT_00411bb4) {
    FUN_0040caf3(5);
    DAT_00411bb4 = DAT_00411bb4 + -1;
    FUN_00407b33(1,0);
    if (DAT_00411bb4 != 0) {
      Sleep(0x19);
      for (local_8 = DAT_00411bb4 + 1; 0 < local_8; local_8 = local_8 + -1) {
        if (DAT_00411bb4 < local_8) {
          FUN_00407b33(local_8,3);
        }
        else {
          FUN_00407b33(local_8,4);
        }
        if (local_8 == 1) {
          FUN_00407b33(1,1);
        }
      }
      Sleep(0x32);
      for (local_8 = 1; local_8 <= DAT_00411bb4 + 1; local_8 = local_8 + 1) {
        if (DAT_00411bb4 < local_8) {
          FUN_00407b33(local_8,0);
        }
        else {
          FUN_00407b33(local_8,2);
        }
      }
    }
  }
  return;
}


// ==== FUN_00407e2a @ 00407e2a

void __cdecl FUN_00407e2a(int param_1)

{
  int local_c;
  int local_8;
  
  if (param_1 <= DAT_00411bb4) {
    FUN_0040caf3(5);
    for (local_c = 0; local_c < param_1; local_c = local_c + 1) {
      DAT_00411bb4 = DAT_00411bb4 + -1;
      FUN_00407b33(1,0);
      if (DAT_00411bb4 == 0) {
        return;
      }
      Sleep(0x19);
      for (local_8 = DAT_00411bb4 + 1; 0 < local_8; local_8 = local_8 + -1) {
        if (DAT_00411bb4 < local_8) {
          FUN_00407b33(local_8,3);
        }
        else {
          FUN_00407b33(local_8,4);
        }
        if (local_8 == 1) {
          FUN_00407b33(1,1);
        }
      }
      Sleep(0x32);
      for (local_8 = 1; local_8 <= DAT_00411bb4 + 1; local_8 = local_8 + 1) {
        if (DAT_00411bb4 < local_8) {
          FUN_00407b33(local_8,0);
        }
        else {
          FUN_00407b33(local_8,2);
        }
      }
    }
  }
  return;
}


// ==== FUN_00407f65 @ 00407f65

void __cdecl FUN_00407f65(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_14;
  uint local_10;
  uint local_8;
  
  iVar1 = DAT_00411bd0;
  iVar2 = (5 - param_1) * 0x4d + DAT_00411bd4;
  if (param_1 < 5) {
    FUN_00403a8a(DAT_00419160,DAT_00418f78,DAT_00411bd0,iVar2 + -7);
  }
  iVar1 = iVar1 + 0x1c;
  iVar2 = iVar2 + 0x1c;
  local_10 = 0;
  local_8 = 0;
  if (*(int *)(&DAT_0041b738 + param_1 * 4) != 0) {
    local_8 = (uint)(*(char *)(*(int *)(&DAT_0041b738 + param_1 * 4) * 0x31 + 0x417c42) != '\0');
    local_10 = (uint)(*(char *)(*(int *)(&DAT_0041b738 + param_1 * 4) * 0x31 + 0x417c54) != '\0');
    if (*(char *)(*(int *)(&DAT_0041b738 + param_1 * 4) * 0x31 + 0x417c6c) != '\0') {
      local_8 = 0xffffffff;
    }
    if (*(char *)(*(int *)(&DAT_0041b738 + param_1 * 4) * 0x31 + 0x417c5a) != '\0') {
      local_10 = 0xffffffff;
    }
  }
  for (local_14 = -3; local_14 < 4; local_14 = local_14 + 1) {
    for (local_1c = -3; local_1c < 4; local_1c = local_1c + 1) {
      if (((*(int *)(&DAT_0041b738 + param_1 * 4) == 0) ||
          ((&DAT_00417c73)
           [(*(int *)(&DAT_0041b738 + param_1 * 4) + -1) * 0x31 + local_1c + (local_14 + 3) * 7] ==
           '\0')) || ((param_1 == 5 && (4 < DAT_00411e64)))) {
        iVar3 = FUN_0040d420(local_8 + local_14);
        if ((iVar3 < 3) && (iVar3 = FUN_0040d420(local_10 + local_1c), iVar3 < 3)) {
          FUN_00403a8a(DAT_00419160,DAT_00418f50,(local_10 + local_1c) * 0xe + iVar1,
                       (local_8 + local_14) * 0xe + iVar2);
        }
      }
      else if ((local_14 == 0) && (local_1c == 0)) {
        FUN_00403a8a(DAT_00419160,DAT_00418ef8,local_10 * 0xe + iVar1,local_8 * 0xe + iVar2);
      }
      else {
        iVar3 = (local_8 + local_14) * 0xe + iVar2;
        iVar4 = (local_10 + local_1c) * 0xe + iVar1;
        iVar5 = FUN_004068f3(*(int *)(&DAT_0041b738 + param_1 * 4));
        FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00418ee0 + iVar5 * 4),iVar4,iVar3);
      }
    }
  }
  return;
}


// ==== FUN_00408244 @ 00408244

void FUN_00408244(void)

{
  undefined4 local_8;
  
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    FUN_00407f65(local_8);
  }
  return;
}


// ==== FUN_00408281 @ 00408281

void FUN_00408281(void)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 1;
  while( true ) {
    if (500 < local_10) {
      local_8 = 1;
      do {
        if (0xe < local_8) {
          return;
        }
        for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
          if ((&DAT_00419a70)[local_8 * 0x70 + local_c * 7] == 2) {
            (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 0;
            FUN_00406ba5(local_8,local_c);
            return;
          }
        }
        local_8 = local_8 + 1;
      } while( true );
    }
    iVar1 = _rand();
    iVar1 = iVar1 % 0xe + 1;
    iVar2 = _rand();
    iVar2 = iVar2 % 0xe + 1;
    if ((&DAT_00419a70)[iVar1 * 0x70 + iVar2 * 7] == 2) break;
    local_10 = local_10 + 1;
  }
  (&DAT_00419a70)[iVar1 * 0x70 + iVar2 * 7] = 0;
  FUN_00406ba5(iVar1,iVar2);
  return;
}


// ==== FUN_004083cf @ 004083cf

void FUN_004083cf(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  
  iVar4 = DAT_00411bd0;
  iVar3 = DAT_00411bd4 + -7;
  FUN_00403a8a(DAT_00419160,DAT_00418f54,DAT_00411bd0 + -7,DAT_00411bd4);
  for (local_10 = 0; iVar2 = DAT_00411be4, iVar1 = DAT_00411be0, local_10 < 7;
      local_10 = local_10 + 1) {
    FUN_00403a8a(DAT_00419160,DAT_00419158,iVar4 + 0x46,local_10 * 0x38 + iVar3);
  }
  iVar4 = DAT_00411be4 + -7;
  for (local_10 = 0; local_10 < 9; local_10 = local_10 + 1) {
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar1,iVar4);
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar1,iVar2 + 0x17a);
  }
  for (local_10 = 0; iVar3 = DAT_00411c00, local_10 < 7; local_10 = local_10 + 1) {
    FUN_00403a8a(DAT_00419160,DAT_00419158,iVar1 + -7,local_10 * 0x38 + iVar4);
    FUN_00403a8a(DAT_00419160,DAT_00419158,iVar1 + 0x36,local_10 * 0x38 + iVar4);
    FUN_00403a8a(DAT_00419160,DAT_00419158,DAT_00411c08,local_10 * 0x38 + iVar4);
  }
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar3,0x3d);
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar3,0x7a);
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar3,DAT_00411c04 + -7);
    FUN_00403a8a(DAT_00419160,DAT_0041915c,local_10 * 0x46 + iVar3,DAT_00411bf4 + -7);
  }
  return;
}


// ==== FUN_00408666 @ 00408666

void FUN_00408666(void)

{
  undefined *_Src;
  size_t _Size;
  int local_1c;
  undefined4 local_18;
  undefined1 local_14 [16];
  
  FUN_00403a8a(DAT_00419160,DAT_00418f58,DAT_00411bf0,DAT_00411bf4);
  _Size = 0x10;
  _Src = FUN_004038f0((uint *)&DAT_004120f4,DAT_00411350,5);
  FID_conflict__memcpy(local_14,_Src,_Size);
  local_18 = 0;
  for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
    if (((local_18 == 0) && (local_14[local_1c + -1] == '0')) && (local_1c != 5)) {
      FUN_00403a8a(DAT_00419160,DAT_00419108,(local_1c + -1) * 0x11 + DAT_00411bf0 + 9,
                   DAT_00411bf4 + 0x2f);
    }
    else {
      local_18 = 1;
      FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00419050 + (char)local_14[local_1c + -1] * 4),
                   (local_1c + -1) * 0x11 + DAT_00411bf0 + 9,DAT_00411bf4 + 0x2f);
    }
  }
  return;
}


// ==== FUN_00408781 @ 00408781

void FUN_00408781(void)

{
  undefined *_Src;
  size_t _Size;
  int local_1c;
  undefined4 local_18;
  undefined1 local_14 [16];
  
  FUN_00403a8a(DAT_00419160,DAT_00419154,DAT_00411c00,DAT_00411c04);
  _Size = 0x10;
  _Src = FUN_004038f0((uint *)&DAT_004120f8,DAT_00411354,5);
  FID_conflict__memcpy(local_14,_Src,_Size);
  local_18 = 0;
  for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
    if ((local_18 == 0) && (local_14[local_1c + -1] == '0')) {
      FUN_00403a8a(DAT_00419160,DAT_00419108,(local_1c + -1) * 0x11 + DAT_00411c00 + 9,
                   DAT_00411c04 + 0x2f);
    }
    else {
      local_18 = 1;
      FUN_00403a8a(DAT_00419160,*(HANDLE *)(&DAT_00419050 + (char)local_14[local_1c + -1] * 4),
                   (local_1c + -1) * 0x11 + DAT_00411c00 + 9,DAT_00411c04 + 0x2f);
    }
  }
  return;
}


// ==== FUN_00408892 @ 00408892

void FUN_00408892(void)

{
  DAT_004178f8 = 0;
  DAT_00411b9c = 0;
  DAT_00411b98 = 0;
  DAT_00411ba0 = 0;
  DAT_00411350 = 0;
  DAT_00411354 = DAT_00411358;
  DAT_00411bb0 = FUN_00402520(DAT_00411358);
  _memset(&DAT_00419a68,0,0x1c00);
  if ((DAT_00411bb8 == 2) || (DAT_00411bb8 == 4)) {
    DAT_00411bbc = 1;
  }
  else {
    DAT_00411bbc = 0;
  }
  if (DAT_00411b90 == 0) {
    FUN_00407a1d();
  }
  _memset(&DAT_0041b738,0,0x1c);
  DAT_0041b73c = FUN_00406770();
  DAT_00411bb4 = DAT_00411bb8 + -1;
  DAT_00411368 = 0;
  DAT_00411b90 = 0;
  return;
}


// ==== FUN_00408984 @ 00408984

undefined4 __cdecl FUN_00408984(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_18;
  
  if ((((param_1 < 1) || (0xe < param_1)) || (param_2 < 1)) || (0xe < param_2)) {
    uVar4 = 0;
  }
  else if ((param_3 < 1) || (0x60 < param_3)) {
    uVar4 = 0;
  }
  else if (((&DAT_00419a70)[param_1 * 0x70 + param_2 * 7] == 2) && (2 < DAT_00411bb4)) {
    FUN_00407e2a(3);
    (&DAT_00419a70)[param_1 * 0x70 + param_2 * 7] = 0;
    FUN_00406ba5(param_1,param_2);
    uVar4 = 0;
  }
  else {
    for (local_38 = -3; local_38 < 4; local_38 = local_38 + 1) {
      for (local_3c = -3; local_3c < 4; local_3c = local_3c + 1) {
        if ((&DAT_00417c73)[local_3c + (local_38 + 3) * 7 + (param_3 + -1) * 0x31] != '\0') {
          if ((((param_1 + local_38 < 1) || (0xe < param_1 + local_38)) || (param_2 + local_3c < 1))
             || (0xe < param_2 + local_3c)) {
            return 0;
          }
          if ((&DAT_00419a70)[(param_1 + local_38) * 0x70 + (param_2 + local_3c) * 7] != 0) {
            return 0;
          }
        }
      }
    }
    FUN_0040caf3(2);
    DAT_00411e68 = 0;
    *(int *)(&DAT_00419a68 + param_2 * 0x1c + param_1 * 0x1c0) = param_3;
    for (local_38 = -3; local_38 < 4; local_38 = local_38 + 1) {
      for (local_3c = -3; local_3c < 4; local_3c = local_3c + 1) {
        if ((&DAT_00417c73)[local_3c + (local_38 + 3) * 7 + (param_3 + -1) * 0x31] != '\0') {
          *(int *)(&DAT_00419a6c + (param_2 + local_3c) * 0x1c + (param_1 + local_38) * 0x1c0) =
               param_3;
          *(int *)(&DAT_00419a74 + (param_2 + local_3c) * 0x1c + (param_1 + local_38) * 0x1c0) =
               param_2;
          *(int *)(&DAT_00419a78 + (param_2 + local_3c) * 0x1c + (param_1 + local_38) * 0x1c0) =
               param_1;
          *(int *)(&DAT_00419a7c + (param_2 + local_3c) * 0x1c + (param_1 + local_38) * 0x1c0) =
               local_3c;
          *(int *)(&DAT_00419a80 + (param_2 + local_3c) * 0x1c + (param_1 + local_38) * 0x1c0) =
               local_38;
          (&DAT_00419a70)[(param_1 + local_38) * 0x70 + (param_2 + local_3c) * 7] = 1;
          FUN_00406ba5(param_1 + local_38,param_2 + local_3c);
        }
      }
    }
    DAT_00411350 = DAT_00411350 + DAT_00411354;
    FUN_00408666();
    for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
      for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
        if (((((2 < (int)(&DAT_00419a70)[local_38 * 0x70 + local_3c * 7]) &&
              ((&DAT_00419a70)[(local_38 + -1) * 0x70 + (local_3c + -1) * 7] == 1)) &&
             (((&DAT_00419a70)[(local_38 + -1) * 0x70 + local_3c * 7] == 1 &&
              (((&DAT_00419a70)[(local_38 + -1) * 0x70 + (local_3c + 1) * 7] == 1 &&
               ((&DAT_00419a70)[local_38 * 0x70 + (local_3c + -1) * 7] == 1)))))) &&
            ((&DAT_00419a70)[local_38 * 0x70 + (local_3c + 1) * 7] == 1)) &&
           ((((&DAT_00419a70)[(local_38 + 1) * 0x70 + (local_3c + -1) * 7] == 1 &&
             ((&DAT_00419a70)[(local_38 + 1) * 0x70 + local_3c * 7] == 1)) &&
            ((&DAT_00419a70)[(local_38 + 1) * 0x70 + (local_3c + 1) * 7] == 1)))) {
          switch((&DAT_00419a70)[local_38 * 0x70 + local_3c * 7]) {
          case 3:
            DAT_00411368 = DAT_00411368 + 10;
            break;
          case 4:
            Sleep(500);
            FUN_00407a1d();
            FUN_00406c0e();
            return 1;
          case 5:
            DAT_00411350 = DAT_00411350 + DAT_00411354 * 100;
            FUN_00408666();
            break;
          case 6:
            FUN_00408281();
            break;
          case 7:
            FUN_00407bf3();
          }
          (&DAT_00419a70)[local_38 * 0x70 + local_3c * 7] = 0;
          FUN_00406ba5(local_38,local_3c);
        }
      }
    }
    _memset(&DAT_00419638,0,0x400);
    bVar3 = false;
    bVar1 = false;
    local_30 = 0;
    local_18 = 0;
    for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
      bVar2 = true;
      iVar5 = FUN_004068f3(*(int *)(local_38 * 0x1c0 + 0x419a88));
      bVar7 = (&DAT_00419a8c)[local_38 * 0x70] == 1;
      for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
        if ((&DAT_00419a70)[local_38 * 0x70 + local_3c * 7] != 1) {
          bVar2 = false;
          break;
        }
        iVar6 = FUN_004068f3(*(int *)(&DAT_00419a6c + local_3c * 0x1c + local_38 * 0x1c0));
        if (iVar6 != iVar5) {
          bVar7 = false;
        }
      }
      if ((bVar2) && (bVar7)) {
        bVar1 = true;
      }
      if (bVar2) {
        local_30 = local_30 + 1;
        for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
          *(undefined4 *)
           (&DAT_00419638 +
           *(int *)(&DAT_00419a74 + local_3c * 0x1c + local_38 * 0x1c0) * 4 +
           *(int *)(&DAT_00419a78 + local_3c * 0x1c + local_38 * 0x1c0) * 0x40) =
               *(undefined4 *)
                (&DAT_00419a68 +
                *(int *)(&DAT_00419a74 + local_3c * 0x1c + local_38 * 0x1c0) * 0x1c +
                *(int *)(&DAT_00419a78 + local_3c * 0x1c + local_38 * 0x1c0) * 0x1c0);
        }
        bVar3 = true;
      }
    }
    for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
      bVar2 = true;
      iVar5 = FUN_004068f3(*(int *)(local_3c * 0x1c + 0x419c2c));
      bVar7 = (&DAT_00419c30)[local_3c * 7] == 1;
      for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
        if ((&DAT_00419a70)[local_38 * 0x70 + local_3c * 7] != 1) {
          bVar2 = false;
          break;
        }
        iVar6 = FUN_004068f3(*(int *)(&DAT_00419a6c + local_3c * 0x1c + local_38 * 0x1c0));
        if (iVar6 != iVar5) {
          bVar7 = false;
        }
      }
      if ((bVar2) && (bVar7)) {
        bVar1 = true;
      }
      if (bVar2) {
        local_18 = local_18 + 1;
        for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
          *(undefined4 *)
           (&DAT_00419638 +
           *(int *)(&DAT_00419a74 + local_3c * 0x1c + local_38 * 0x1c0) * 4 +
           *(int *)(&DAT_00419a78 + local_3c * 0x1c + local_38 * 0x1c0) * 0x40) =
               *(undefined4 *)
                (&DAT_00419a68 +
                *(int *)(&DAT_00419a74 + local_3c * 0x1c + local_38 * 0x1c0) * 0x1c +
                *(int *)(&DAT_00419a78 + local_3c * 0x1c + local_38 * 0x1c0) * 0x1c0);
        }
        bVar3 = true;
      }
    }
    if (bVar1) {
      FUN_00407bf3();
    }
    if ((0 < local_30) && (0 < local_18)) {
      local_30 = local_30 + 1;
    }
    local_30 = local_30 + local_18;
    if (1 < local_30) {
      for (; 0 < local_30; local_30 = local_30 + -1) {
        FUN_00407bf3();
      }
    }
    if (bVar3) {
      bVar1 = true;
      local_34 = 0;
      for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
        for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
          if ((&DAT_00419a70)[local_38 * 0x70 + local_3c * 7] == 7) {
            bVar1 = false;
          }
          if ((&DAT_00419a70)[local_38 * 0x70 + local_3c * 7] == 6) {
            local_34 = local_34 + 1;
          }
        }
      }
      for (local_38 = 1; local_38 <= local_34; local_38 = local_38 + 1) {
        FUN_0040701b(1,(byte)DAT_00411354,1);
      }
      DAT_0041b73c = 0;
      FUN_00407f65(1);
      Sleep(0x14);
      for (local_38 = 1; local_38 < 0xf; local_38 = local_38 + 1) {
        for (local_3c = 1; local_3c < 0xf; local_3c = local_3c + 1) {
          if (*(int *)(&DAT_00419638 + local_3c * 4 + local_38 * 0x40) != 0) {
            for (param_1 = -3; param_1 < 4; param_1 = param_1 + 1) {
              for (param_2 = -3; param_2 < 4; param_2 = param_2 + 1) {
                if (((&DAT_00417c73)
                     [param_2 + (*(int *)(&DAT_00419638 + local_3c * 4 + local_38 * 0x40) + -1) *
                                0x31 + (param_1 + 3) * 7] != '\0') &&
                   ((&DAT_00419a70)[(param_1 + local_38) * 0x70 + (param_2 + local_3c) * 7] != 2)) {
                  _memset(&DAT_00419a68 + (param_1 + local_38) * 0x1c0 + (param_2 + local_3c) * 0x1c
                          ,0,0x1c);
                  FUN_00406ba5(param_1 + local_38,param_2 + local_3c);
                }
              }
            }
            DAT_00411350 = DAT_00411350 + (DAT_00411bb8 + 2) * DAT_00411354;
            FUN_00408666();
            FUN_0040a323();
            Sleep(100);
          }
        }
      }
      DAT_004178f8 = DAT_004178f8 + 1;
      if (DAT_00411354 * 10 < DAT_004178f8) {
        DAT_00411354 = DAT_00411354 + 1;
        DAT_00411bb0 = FUN_00402520(DAT_00411354);
        FUN_00408781();
        FUN_0040701b(1,(byte)DAT_00411354,0);
        FUN_0040caf3(7);
      }
      if (bVar1) {
        for (param_1 = 1; param_1 < 0xf; param_1 = param_1 + 1) {
          for (param_2 = 1; param_2 < 0xf; param_2 = param_2 + 1) {
            if (*(int *)(&DAT_00419a68 + param_2 * 0x1c + param_1 * 0x1c0) != 0) {
              FUN_0040caf3(6);
              return 1;
            }
          }
        }
        if (DAT_00411bb4 < 0xc) {
          FUN_00407bf3();
        }
        else {
          FUN_0040caf3(6);
        }
        DAT_00411350 = DAT_00411350 + (DAT_00411bb8 + 2) * DAT_00411354 * 10;
        FUN_00408666();
        uVar4 = 1;
      }
      else {
        FUN_0040caf3(6);
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_004097d3 @ 004097d3

void __cdecl FUN_004097d3(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_14;
  int local_10;
  
  if ((0 < DAT_00411bb4) && ((&DAT_00419a70)[param_1 * 0x70 + param_2 * 7] == 1)) {
    FUN_00407d10();
    iVar1 = *(int *)(&DAT_00419a74 + param_2 * 0x1c + param_1 * 0x1c0);
    iVar2 = *(int *)(&DAT_00419a78 + param_2 * 0x1c + param_1 * 0x1c0);
    for (local_10 = -3; local_10 < 4; local_10 = local_10 + 1) {
      for (local_14 = -3; local_14 < 4; local_14 = local_14 + 1) {
        if ((*(int *)(&DAT_00419a74 + (iVar1 + local_14) * 0x1c + (iVar2 + local_10) * 0x1c0) ==
             iVar1) &&
           (*(int *)(&DAT_00419a78 + (iVar1 + local_14) * 0x1c + (iVar2 + local_10) * 0x1c0) ==
            iVar2)) {
          _memset(&DAT_00419a68 + (iVar2 + local_10) * 0x1c0 + (iVar1 + local_14) * 0x1c,0,0x1c);
          FUN_00406ba5(iVar2 + local_10,iVar1 + local_14);
        }
      }
    }
  }
  return;
}


// ==== FUN_00409942 @ 00409942

void FUN_00409942(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (1 < DAT_00411354) {
    local_8 = 0;
    for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
      for (local_14 = 1; local_14 < 0xf; local_14 = local_14 + 1) {
        if (2 < (int)(&DAT_00419a70)[local_10 * 0x70 + local_14 * 7]) {
          local_8 = local_8 + 1;
        }
      }
    }
    if (local_8 < 1) {
      iVar1 = _rand();
      iVar1 = iVar1 % (DAT_00411354 + 1);
    }
    else {
      iVar1 = _rand();
      iVar1 = iVar1 % (local_8 * 10);
    }
    if (iVar1 == 0) {
      for (local_18 = 1; local_18 < 0x65; local_18 = local_18 + 1) {
        iVar1 = _rand();
        local_c = iVar1 % 7 + 1;
        if (2 < local_c) break;
      }
      if ((((2 < local_c) && ((local_8 < 5 - DAT_00411bb8 || (local_c == 4)))) &&
          ((2 < DAT_00411354 || (local_c != 7)))) &&
         ((((3 < DAT_00411354 || (local_c != 5)) && ((4 < DAT_00411354 || (local_c != 3)))) &&
          ((5 < DAT_00411354 || (local_c != 6)))))) {
        for (local_18 = 1; local_18 < 0x1f5; local_18 = local_18 + 1) {
          iVar1 = _rand();
          iVar1 = iVar1 % 0xc + 2;
          iVar2 = _rand();
          iVar2 = iVar2 % 0xc + 2;
          iVar3 = FUN_00406e77(iVar1,iVar2);
          if (iVar3 != 0) {
            (&DAT_00419a70)[iVar1 * 0x70 + iVar2 * 7] = local_c;
            if (local_c == 4) {
              *(undefined4 *)(&DAT_00419a6c + iVar2 * 0x1c + iVar1 * 0x1c0) = 0;
              *(undefined4 *)(&DAT_00419a74 + iVar2 * 0x1c + iVar1 * 0x1c0) = 1;
            }
            else if ((local_c < 3) || (5 < local_c)) {
              *(undefined4 *)(&DAT_00419a6c + iVar2 * 0x1c + iVar1 * 0x1c0) = 0;
            }
            else {
              *(undefined4 *)(&DAT_00419a6c + iVar2 * 0x1c + iVar1 * 0x1c0) = 0xc;
            }
            FUN_00406715(0);
            FUN_00406ba5(iVar1,iVar2);
            FUN_004039ff(0);
            if (DAT_00411364 == 0) {
              return;
            }
            PostMessageA(DAT_004191a8,0x111,0x137,local_c);
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_00409c7c @ 00409c7c

void FUN_00409c7c(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 1; local_8 < 0xf; local_8 = local_8 + 1) {
    for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
      if (((&DAT_00419a70)[local_8 * 0x70 + local_c * 7] == 3) ||
         ((&DAT_00419a70)[local_8 * 0x70 + local_c * 7] == 5)) {
        if (*(int *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) < 1) {
          (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 0;
          FUN_00406ba5(local_8,local_c);
        }
        else {
          *(int *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) =
               *(int *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) + -1;
          FUN_00406ba5(local_8,local_c);
        }
      }
      if ((&DAT_00419a70)[local_8 * 0x70 + local_c * 7] == 4) {
        if (*(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) < 0xc) {
          *(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) =
               *(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) + 1;
        }
        else if (*(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) == 0xc) {
          *(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) =
               *(int *)(&DAT_00419a74 + local_c * 0x1c + local_8 * 0x1c0) + 1;
          *(undefined4 *)(&DAT_00419a6c + local_c * 0x1c + local_8 * 0x1c0) = 0;
          FUN_00406ba5(local_8,local_c);
        }
        else {
          (&DAT_00419a70)[local_8 * 0x70 + local_c * 7] = 0;
          FUN_00406ba5(local_8,local_c);
        }
      }
    }
  }
  return;
}


// ==== FUN_00409eb8 @ 00409eb8

void FUN_00409eb8(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_00411b98 == 0) && (DAT_00411b9c == 0)) && (DAT_00411b90 == 0)) {
    SetMenu(DAT_004191a8,DAT_00419a40);
    if (DAT_00411364 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004191a8);
  }
  else {
    SetMenu(DAT_004191a8,DAT_0041b764);
    if (DAT_00411364 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004191a8);
  }
  return;
}


// ==== FUN_00409fbc @ 00409fbc

void FUN_00409fbc(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_00411b98 == 0) && (DAT_00411b9c == 0)) && (DAT_00411b90 == 0)) {
    SetMenu(DAT_004191a8,DAT_00419a40);
    if (DAT_00411364 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004191a8);
    FUN_00402468(DAT_00419160,0xc9,DAT_00419104,DAT_00419100,DAT_00418f7c);
    FUN_00406c0e();
  }
  else {
    SetMenu(DAT_004191a8,DAT_0041b764);
    if (DAT_00411364 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_004191a8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004191a8);
    FUN_00402468(DAT_00419160,0xc9,DAT_00418ed4,DAT_00418ed8,DAT_00418ed0);
    FUN_00406c0e();
  }
  return;
}


// ==== FUN_0040a114 @ 0040a114

void FUN_0040a114(void)

{
  int iVar1;
  int local_10 [2];
  int local_8;
  
  FUN_00409942();
  FUN_00406715(0);
  FUN_00409c7c();
  FUN_004039ff(0);
  local_8 = 1;
  while( true ) {
    if (5 < local_8) {
      if (DAT_00411bb4 < 1) {
        DAT_00411b9c = 1;
        DAT_00411b98 = 1;
        FUN_00406715(0);
        _memset(&DAT_00419a68,0,0x1c00);
        DAT_00411e64 = 0;
        FUN_00407f65(5);
        FUN_004083cf();
        FUN_00409fbc();
        FUN_004039ff(0);
        FUN_0040c7f5(1);
        if (DAT_00412148 != 0) {
          FUN_0040caf3(7);
          Sleep(200);
          FUN_0040caf3(7);
        }
        iVar1 = FUN_00402868(DAT_00411350,local_10);
        if ((iVar1 != 0) && (local_10[0] < 10)) {
          if (DAT_0041136c != 0) {
            FUN_00404401();
            DrawMenuBar(DAT_004191a8);
          }
          iVar1 = FUN_00402905(DAT_00411350);
          if (0 < iVar1) {
            DAT_00411e60 = local_10[0];
            FUN_00404450();
          }
          FUN_00402a49();
        }
        FUN_00406715(0);
        DAT_00411354 = DAT_00411358;
        FUN_00408781();
        FUN_004039ff(0);
      }
      else {
        FUN_00406715(0);
        FUN_00407d10();
        FUN_004039ff(0);
      }
      return;
    }
    if (*(int *)(&DAT_0041b738 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  DAT_00411e6c = 0;
  iVar1 = FUN_00406770();
  *(int *)(&DAT_0041b738 + local_8 * 4) = iVar1;
  FUN_00406715(0);
  FUN_00407f65(local_8);
  FUN_004039ff(0);
  FUN_0040caf3(8);
  if (local_8 != 5) {
    return;
  }
  Sleep(200);
  FUN_0040caf3(8);
  return;
}


// ==== FUN_0040a323 @ 0040a323

void FUN_0040a323(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  
  if (DAT_0041b74c != 0) {
    DAT_00411e64 = DAT_00411e64 + 1;
    if (5 < DAT_00411e64) {
      DAT_00411e64 = 0;
    }
    FUN_00407f65(5);
  }
  bVar1 = false;
  for (local_c = 1; local_c < 0xf; local_c = local_c + 1) {
    for (local_10 = 1; local_10 < 0xf; local_10 = local_10 + 1) {
      if ((5 < (int)(&DAT_00419a70)[local_c * 0x70 + local_10 * 7]) &&
         (*(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) == 0)) {
        bVar1 = true;
      }
      if ((5 < (int)(&DAT_00419a70)[local_c * 0x70 + local_10 * 7]) &&
         (0 < *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0))) {
        if (*(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) <
            *(int *)(&DAT_00411700 + (&DAT_00419a70)[local_c * 0x70 + local_10 * 7] * 4) + -1) {
          *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) =
               *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) + 1;
          FUN_00406ba5(local_c,local_10);
        }
        else {
          *(undefined4 *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) = 0;
          FUN_00406ba5(local_c,local_10);
        }
      }
      if ((&DAT_00419a70)[local_c * 0x70 + local_10 * 7] == 4) {
        if (*(int *)(&DAT_00419a74 + local_10 * 0x1c + local_c * 0x1c0) < 0xc) {
          *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) =
               *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) + 1;
          if (DAT_00411710 < *(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0)) {
            *(undefined4 *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) = 1;
          }
          FUN_00406ba5(local_c,local_10);
        }
        else if (*(int *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) != 0) {
          *(undefined4 *)(&DAT_00419a6c + local_10 * 0x1c + local_c * 0x1c0) = 0;
          FUN_00406ba5(local_c,local_10);
        }
      }
    }
  }
  if ((bVar1) && (iVar2 = _rand(), iVar2 % 10 == 1)) {
    for (local_14 = 1; local_14 < 0xc9; local_14 = local_14 + 1) {
      iVar2 = _rand();
      iVar2 = iVar2 % 0xe + 1;
      iVar3 = _rand();
      iVar3 = iVar3 % 0xe + 1;
      if ((5 < (int)(&DAT_00419a70)[iVar2 * 0x70 + iVar3 * 7]) &&
         (*(int *)(&DAT_00419a6c + iVar3 * 0x1c + iVar2 * 0x1c0) == 0)) {
        *(undefined4 *)(&DAT_00419a6c + iVar3 * 0x1c + iVar2 * 0x1c0) = 1;
        FUN_00406ba5(iVar2,iVar3);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0040a709 @ 0040a709

void FUN_0040a709(void)

{
  undefined4 local_14;
  undefined4 local_8;
  
  FUN_00403a8a(DAT_00419160,DAT_00419150,DAT_00411be0,DAT_00411be4);
  for (local_14 = 1; local_14 < 0xd; local_14 = local_14 + 1) {
    if (DAT_00411bb4 < local_14) {
      local_8 = 0;
    }
    else {
      local_8 = 2;
    }
    FUN_00407b33(local_14,local_8);
  }
  return;
}


// ==== FUN_0040a797 @ 0040a797

void FUN_0040a797(void)

{
  FUN_00408244();
  FUN_0040a709();
  FUN_00408781();
  FUN_00408666();
  FUN_004023a0(DAT_00419160);
  FUN_00406c0e();
  FUN_004083cf();
  return;
}


// ==== FUN_0040a7d3 @ 0040a7d3

void FUN_0040a7d3(void)

{
  if ((DAT_00411b9c != 0) || (DAT_00411bac != 0)) {
    FUN_0040c7f5(DAT_0041135c + 1);
  }
  DAT_00411bac = 0;
  DAT_00411b90 = 0;
  DAT_00411bb8 = DAT_0041135c;
  FUN_00408892();
  FUN_0040caf3(1);
  FUN_00406715(0);
  FUN_00406c0e();
  FUN_00408244();
  FUN_0040a709();
  FUN_00408666();
  FUN_00408781();
  FUN_00409fbc();
  FUN_004039ff(0);
  _memset(&DAT_0041b6f8,0,0x24);
  if (DAT_00411360 != 0) {
    PostMessageA(DAT_004191a8,0x111,0x130,0);
  }
  return;
}


// ==== FUN_0040a8a1 @ 0040a8a1

void FUN_0040a8a1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0041214c;
  iVar2 = DAT_0041135c;
  iVar1 = DAT_00411358;
  FUN_004044bf();
  if ((iVar3 != DAT_0041214c) && (DAT_00411b98 == 0)) {
    if (DAT_00411b9c == 0) {
      FUN_0040c7f5(DAT_0041135c + 1);
    }
    else {
      FUN_0040c7f5(1);
    }
  }
  if ((DAT_0041135c != iVar2) || (DAT_00411358 != iVar1)) {
    DAT_00411bac = (uint)(DAT_0041135c != iVar2);
    SendMessageA(DAT_004191a8,0x111,0x65,1);
  }
  if ((DAT_00411b90 != 0) || (DAT_00411b9c != 0)) {
    FUN_00406715(0);
    DAT_00411354 = DAT_00411358;
    FUN_00408781();
    FUN_004039ff(0);
  }
  FUN_00402a49();
  return;
}


// ==== FUN_0040a9b4 @ 0040a9b4

void FUN_0040a9b4(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  iVar1 = DAT_00411bf0;
  if (((DAT_00411b98 == 0) && (DAT_00411b90 == 0)) && (DAT_00411b9c == 0)) {
    local_8 = DAT_00418f7c;
    local_10 = DAT_00419100;
  }
  else {
    local_8 = DAT_00418ed0;
    local_10 = DAT_00418ed8;
  }
  FUN_00406715(0);
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    FUN_00403a8a(DAT_00419160,local_8,iVar1,0x44);
    Sleep(0xf);
    FUN_00403a8a(DAT_00419160,local_10,iVar1,0x44);
    if (local_14 != 2) {
      Sleep(0xf);
    }
  }
  FUN_004039ff(0);
  return;
}


// ==== FUN_0040aaa2 @ 0040aaa2

void __cdecl FUN_0040aaa2(undefined4 param_1,undefined4 param_2,undefined2 param_3,int param_4)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  switch(param_3) {
  case 0x65:
    FUN_0040caf3(5);
    if ((DAT_00411b9c == 0) && (DAT_00411b90 == 0)) {
      IVar1 = FUN_0040406a();
      if (IVar1 != 1) {
        DAT_00411bac = 0;
        return;
      }
      iVar2 = FUN_00402868(DAT_00411350,&local_8);
      if ((iVar2 != 0) && (local_8 < 10)) {
        if (DAT_0041136c != 0) {
          FUN_00404401();
          DrawMenuBar(DAT_004191a8);
        }
        iVar2 = FUN_00402905(DAT_00411350);
        if (0 < iVar2) {
          DAT_00411e60 = local_8;
          FUN_00404450();
        }
        FUN_00402a49();
      }
    }
    if (DAT_00411b98 != 0) {
      FUN_0040c718(DAT_00411bb8 + 1);
    }
    FUN_0040a7d3();
    break;
  case 0x66:
    DAT_00411e60 = -1;
    FUN_00404450();
    break;
  case 0x67:
    SendMessageA(DAT_004191a8,0x10,0,0);
    break;
  case 0x68:
    FUN_0040a8a1();
    break;
  case 0x69:
    FUN_0040caf3(4);
    if (DAT_00411b90 != 0) {
      FUN_0040a7d3();
      return;
    }
    if (DAT_00411b9c != 0) {
      FUN_0040a7d3();
      return;
    }
    if (DAT_00411b98 != 0) {
      FUN_0040c718(DAT_00411bb8 + 1);
      DAT_00411b98 = 0;
      FUN_00406715(0);
      FUN_00409fbc();
      FUN_004039ff(0);
      return;
    }
    if (DAT_0041b74c == 0) {
      FUN_0040a114();
    }
    break;
  case 0xc9:
    FUN_0040caf3(7);
    if (DAT_00411b90 != 0) {
      FUN_0040a7d3();
      return;
    }
    if (DAT_00411b9c != 0) {
      FUN_0040a7d3();
      return;
    }
    DAT_00411b98 = (uint)(DAT_00411b98 == 0);
    FUN_00406715(0);
    FUN_00409fbc();
    FUN_004039ff(0);
    if (DAT_00411b98 == 0) {
      if (DAT_00411b9c == 0) {
        FUN_0040c718(DAT_00411bb8 + 1);
      }
      else {
        FUN_0040c718(1);
      }
    }
    else {
      InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
      UpdateWindow(DAT_004191a8);
      FUN_0040c6a5();
    }
    break;
  case 0x12e:
    FUN_004040e2();
    break;
  case 0x12f:
    WinHelpA(DAT_004191a8,s_LINEUP_HLP_00411890,0xb,0);
    break;
  case 0x130:
    FUN_004041a9();
    break;
  case 0x131:
    DAT_00411364 = (uint)(DAT_00411364 == 0);
    FUN_00406715(0);
    FUN_00409fbc();
    FUN_004039ff(0);
    break;
  case 0x137:
    if (DAT_00411364 != 0) {
      FUN_00404218(param_4);
    }
  }
  return;
}


// ==== FUN_0040af1a @ 0040af1a

undefined4 FUN_0040af1a(void)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_00411b9c == 0) && (DAT_00411b90 == 0)) {
    IVar1 = FUN_00403ff2();
    if (IVar1 == 1) {
      iVar2 = FUN_00402868(DAT_00411350,&local_8);
      if ((iVar2 != 0) && (local_8 < 10)) {
        if (DAT_0041136c != 0) {
          FUN_00404401();
          DrawMenuBar(DAT_004191a8);
        }
        iVar2 = FUN_00402905(DAT_00411350);
        if (0 < iVar2) {
          DAT_00411e60 = local_8;
          FUN_00404450();
        }
        FUN_00402a49();
      }
      SendMessageA(DAT_004191a8,2,0,0);
      WinHelpA(DAT_004191a8,s_LINEUP_HLP_00411890,2,0);
    }
  }
  else {
    SendMessageA(DAT_004191a8,2,0,0);
    WinHelpA(DAT_004191a8,s_LINEUP_HLP_00411890,2,0);
  }
  FUN_00402a49();
  return 0;
}


// ==== FUN_0040b019 @ 0040b019

void FUN_0040b019(void)

{
  FUN_004039b9(1);
  SelectPalette(DAT_00419160,DAT_00411888,0);
  RealizePalette(DAT_00419160);
  FUN_0040a797();
  FUN_004039ff(1);
  return;
}


// ==== FUN_0040b062 @ 0040b062

void FUN_0040b062(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint in_stack_00000010;
  
  if ((DAT_00411b90 == 0) && (DAT_00411b9c == 0)) {
    if (DAT_00411b98 == 0) {
      uVar1 = in_stack_00000010 & 0xffff;
      uVar2 = in_stack_00000010 >> 0x10;
      DAT_00411e70 = 0;
      iVar3 = FUN_00401d00(&DAT_00411bc0,uVar1,uVar2);
      if (iVar3 == 0) {
        iVar3 = FUN_00401d00(&DAT_00411bd0,uVar1,uVar2);
        if (iVar3 == 0) {
          iVar3 = FUN_00401d00(&DAT_00411c00,uVar1,uVar2);
          if (iVar3 == 0) {
            iVar3 = FUN_00401d00(&DAT_00411c00,uVar1,uVar2);
            if (iVar3 != 0) {
              DAT_00411e70 = 8;
            }
          }
          else {
            DAT_00411e70 = 8;
          }
        }
        else {
          DAT_00411e70 = 3;
        }
      }
      else {
        DAT_00411e70 = 2;
      }
    }
    else {
      PostMessageA(DAT_004191a8,0x111,0xc9,0);
      DAT_00411e70 = 0;
    }
  }
  else {
    PostMessageA(DAT_004191a8,0x111,0x65,0);
    DAT_00411e70 = 0;
  }
  return;
}


// ==== FUN_0040b1bd @ 0040b1bd

void FUN_0040b1bd(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_stack_00000010;
  
  uVar1 = in_stack_00000010 & 0xffff;
  uVar2 = in_stack_00000010 >> 0x10;
  if (DAT_00411e70 != 0) {
    iVar3 = FUN_00401d00(&DAT_00411bc0,uVar1,uVar2);
    if ((iVar3 == 0) || (DAT_00411e70 != 2)) {
      iVar3 = FUN_00401d00(&DAT_00411bd0,uVar1,uVar2);
      if ((iVar3 != 0) && (((DAT_00411e70 == 3 && (DAT_00411b9c == 0)) && (DAT_00411b98 == 0)))) {
        iVar3 = 5 - (int)((uVar2 - DAT_00411bd4) + -1) / 0x4d;
        if ((iVar3 == 1) && ((0 < DAT_00411bb4 || (DAT_0041b73c == DAT_00411e68)))) {
          FUN_00406715(0);
          if (DAT_0041b73c != DAT_00411e68) {
            FUN_00407d10();
          }
          uVar1 = DAT_0041b73c - 1;
          uVar6 = (int)uVar1 >> 0x1f;
          uVar2 = (((uVar1 ^ uVar6) - uVar6 & 7 ^ uVar6) - uVar6) + 6;
          uVar7 = (int)uVar2 >> 0x1f;
          DAT_00411e68 = (((uVar2 ^ uVar7) - uVar7 & 7 ^ uVar7) - uVar7) +
                         ((int)(uVar1 + (uVar6 & 7)) >> 3) * 8 + 1;
          DAT_0041b73c = DAT_00411e68;
          FUN_00407f65(1);
          FUN_004039ff(0);
        }
        else if (((0 < DAT_00411bb4) && (1 < iVar3)) &&
                ((iVar3 < 6 && (*(int *)(&DAT_0041b738 + iVar3 * 4) != 0)))) {
          iVar4 = *(int *)(&DAT_0041b738 + iVar3 * 4);
          *(int *)(&DAT_0041b738 + iVar3 * 4) = DAT_0041b73c;
          DAT_0041b73c = iVar4;
          FUN_00406715(0);
          FUN_00407d10();
          FUN_00407f65(1);
          FUN_00407f65(iVar3);
          FUN_004039ff(0);
        }
      }
    }
    else if (((DAT_00411b98 == 0) && (DAT_00411b90 == 0)) && (DAT_00411b9c == 0)) {
      iVar3 = (int)((uVar1 - DAT_00411bc0) + -1) / 0x1b + 1;
      iVar4 = (int)((uVar2 - DAT_00411bc4) + -1) / 0x1b + 1;
      if (((0 < iVar4) && (iVar4 < 0xf)) && ((0 < iVar3 && (iVar3 < 0xf)))) {
        FUN_00406715(0);
        iVar5 = FUN_00408984(iVar4,iVar3,DAT_0041b73c);
        if (iVar5 == 0) {
          FUN_004097d3(iVar4,iVar3);
        }
        else {
          FID_conflict__memcpy(&DAT_0041b73c,&DAT_0041b740,0x10);
          DAT_0041b74c = 0;
          if (DAT_0041b73c == 0) {
            DAT_0041b73c = FUN_00406770();
          }
          FUN_00408244();
        }
        FUN_004039ff(0);
      }
    }
  }
  return;
}


// ==== FUN_0040b4c5 @ 0040b4c5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b4c5(void)

{
  uint in_stack_00000010;
  
  _DAT_00411e74 = FUN_00401d00(&DAT_00411c00,in_stack_00000010 & 0xffff,in_stack_00000010 >> 0x10);
  DAT_00411e78 = FUN_00401d00(&DAT_00411bd0,in_stack_00000010 & 0xffff,in_stack_00000010 >> 0x10);
  return;
}


// ==== FUN_0040b528 @ 0040b528

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b528(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint in_stack_00000010;
  
  iVar1 = FUN_00401d00(&DAT_00411bd0,in_stack_00000010 & 0xffff,in_stack_00000010 >> 0x10);
  if ((((iVar1 == 0) || (DAT_00411e78 == 0)) || (DAT_00411b9c != 0)) ||
     (((DAT_00411b98 != 0 || ((int)(((in_stack_00000010 >> 0x10) - DAT_00411bd4) + -1) / 0x4d != 4))
      || ((DAT_00411bb4 < 1 && (DAT_0041b73c != DAT_00411e68)))))) {
    _DAT_00411e74 = 0;
  }
  else {
    FUN_00406715(0);
    if (DAT_0041b73c != DAT_00411e68) {
      FUN_00407d10();
    }
    uVar2 = DAT_0041b73c - 1;
    uVar4 = (int)uVar2 >> 0x1f;
    uVar3 = (((uVar2 ^ uVar4) - uVar4 & 7 ^ uVar4) - uVar4) + 2;
    uVar5 = (int)uVar3 >> 0x1f;
    DAT_00411e68 = (((uVar3 ^ uVar5) - uVar5 & 7 ^ uVar5) - uVar5) +
                   ((int)(uVar2 + (uVar4 & 7)) >> 3) * 8 + 1;
    DAT_0041b73c = DAT_00411e68;
    FUN_00407f65(1);
    FUN_004039ff(0);
  }
  return;
}


// ==== FUN_0040b66b @ 0040b66b

void __cdecl FUN_0040b66b(HWND param_1,undefined4 param_2,WPARAM param_3,int param_4)

{
  if (param_4 == 3) {
    SendMessageA(param_1,0x111,param_3,0);
  }
  else if (param_4 == 2) {
    if (param_3 == 0x65) {
      FUN_0040caf3(5);
    }
    else if (param_3 == 0x69) {
      FUN_0040caf3(4);
    }
    else if (param_3 == 0xc9) {
      FUN_0040caf3(7);
      FUN_0040a9b4();
    }
  }
  return;
}


// ==== FUN_0040b714 @ 0040b714

void __cdecl FUN_0040b714(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    DAT_00411b94 = 0;
    FUN_00402a49();
    if ((DAT_00411b90 == 0) && (DAT_00411b9c == 0)) {
      DAT_00411b98 = 1;
    }
    FUN_00406715(0);
    FUN_00409fbc();
    FUN_004039ff(0);
    FUN_0040c7f5(0);
    if (((DAT_00411b98 == 0) && (DAT_00411b9c == 0)) && (DAT_00411b90 == 0)) {
      FUN_00406715(0);
      FUN_00406c0e();
      FUN_004039ff(0);
    }
  }
  else {
    DAT_00411b94 = 1;
    FUN_004025d8();
    if (DAT_00411e7c == 0) {
      if (DAT_00411b98 == 0) {
        if (DAT_00411b9c == 0) {
          FUN_0040c7f5(DAT_00411bb8 + 1);
        }
        else {
          FUN_0040c7f5(1);
        }
      }
      if (((DAT_00411b98 == 0) && (DAT_00411b9c == 0)) && (DAT_00411b90 == 0)) {
        FUN_00406715(0);
        FUN_00406c0e();
        FUN_004039ff(0);
      }
    }
    else {
      DAT_00411e7c = 0;
    }
  }
  return;
}


// ==== FUN_0040b86c @ 0040b86c

void FUN_0040b86c(void)

{
  if ((DAT_00411b98 == 0) && (DAT_00411b94 != 0)) {
    FUN_0040c9d5();
  }
  if (((((DAT_00411b94 != 0) && (DAT_00411b90 == 0)) && (DAT_00411b98 == 0)) &&
      ((DAT_00411b9c == 0 && (DAT_00411ba0 == 0)))) && ((DAT_00411ba8 == 0 && (DAT_00411ba4 == 0))))
  {
    if (DAT_0041b73c == 0) {
      FUN_0040a114();
    }
    FUN_00406715(0);
    FUN_0040a323();
    FUN_004039ff(0);
    if ((DAT_00411344 < 0) && (DAT_00411e6c = DAT_00411e6c + 1, DAT_00411bb0 < DAT_00411e6c)) {
      DAT_00411e6c = 0;
      if (DAT_00411368 < 1) {
        FUN_0040a114();
      }
      else if (DAT_00411368 < 2) {
        DAT_00411368 = 0;
      }
      else {
        DAT_00411368 = DAT_00411368 + -1;
      }
    }
  }
  return;
}


// ==== FUN_0040b992 @ 0040b992

UINT FUN_0040b992(void)

{
  UINT UVar1;
  
  FUN_004039b9(0);
  SelectPalette(DAT_00419160,DAT_00411888,0);
  UVar1 = RealizePalette(DAT_00419160);
  FUN_004039ff(0);
  if (UVar1 != 0) {
    InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
  }
  return UVar1;
}


// ==== FUN_0040b9f9 @ 0040b9f9

UINT FUN_0040b9f9(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  int iVar1;
  HDC hDC;
  UINT UVar2;
  
  if (((DAT_00411ba0 == 0) && (DAT_00411ba4 == 0)) &&
     (iVar1 = FUN_00401ddd(param_1,param_2,param_3,param_4), iVar1 != 0)) {
    return 0;
  }
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      FUN_0040b019();
      return 0;
    }
    if (param_2 == 1) {
      FUN_00403df0(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_0040cc10();
      FUN_00403e33(param_1);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      FUN_0040b714(param_1,0x1c,(int)param_3);
      return 0;
    }
    if (param_2 == 0x10) {
      UVar2 = FUN_0040af1a();
      return UVar2;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      if (DAT_00411888 != (HGDIOBJ)0x0) {
        DeleteObject(DAT_00411888);
        DAT_00411888 = (HGDIOBJ)0x0;
      }
      Sleep(400);
      GdiFlush();
      Sleep(400);
      GdiFlush();
      FUN_004035e1();
      Sleep(100);
      hDC = GetDC((HWND)0x0);
      FUN_00403030(hDC);
      ReleaseDC((HWND)0x0,hDC);
      FUN_0040bed3();
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00419a58;
      *(undefined4 *)(param_4 + 0xc) = DAT_00419a64;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_004191a8,6);
        return 0;
      }
      if ((DAT_00411b90 == 0) && (DAT_00411b9c == 0)) {
        if ((DAT_00411b98 != 0) && (param_3 != (HWND)0x20)) {
          PostMessageA(DAT_004191a8,0x111,0xc9,0);
        }
        return 0;
      }
      if (param_3 != (HWND)0x20) {
        PostMessageA(DAT_004191a8,0x111,0x65,0);
      }
      return 0;
    }
    if ((param_2 == 0x86) && (param_3 != (HWND)0x0)) {
      InvalidateRect(DAT_004191a8,(RECT *)0x0,0);
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      FUN_0040b062();
      return 0;
    }
    if (param_2 == 0x111) {
      FUN_0040aaa2(param_1,0x111,(short)param_3,param_4);
      return 0;
    }
    if (param_2 == 0x113) {
      FUN_0040b86c();
      return 0;
    }
  }
  else if (param_2 < 0x212) {
    if (param_2 == 0x211) {
      DAT_00411ba8 = 1;
      InvalidateRect(param_1,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x202) {
      FUN_0040b1bd();
      return 0;
    }
    if (param_2 == 0x204) {
      FUN_0040b4c5();
      return 0;
    }
    if (param_2 == 0x205) {
      FUN_0040b528();
      return 0;
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_0040bc66:
      UVar2 = FUN_0040b992();
      return UVar2;
    }
    if (param_2 == 0x212) {
      DAT_00411ba8 = 0;
      InvalidateRect(param_1,(RECT *)0x0,0);
      return 0;
    }
  }
  else {
    if (param_2 == 0x311) {
      if (DAT_004191a8 == param_3) {
        return 0;
      }
      goto LAB_0040bc66;
    }
    if (param_2 == 0x402) {
      FUN_0040b66b(param_1,0x402,(WPARAM)param_3,param_4);
      return 0;
    }
  }
  UVar2 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar2;
}


// ==== FUN_0040bed3 @ 0040bed3

void FUN_0040bed3(void)

{
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_00401d57();
  local_14 = 0;
  local_28 = 0x65;
  local_24 = DAT_00411bf0;
  local_20 = 7;
  local_1c = DAT_00411bf0 + 0x65;
  local_18 = 0x3e;
  local_10 = DAT_00418f34;
  local_c = DAT_00418f3c;
  local_8 = DAT_00418f38;
  FUN_00401d8f(&local_28);
  local_28 = 0xc9;
  local_24 = DAT_00411bf0;
  local_20 = 0x44;
  local_1c = DAT_00411bf0 + 0x65;
  local_18 = 0x7b;
  local_10 = DAT_00418ed4;
  local_c = DAT_00418ed8;
  local_8 = DAT_00418ed0;
  FUN_00401d8f(&local_28);
  local_28 = 0x69;
  local_24 = DAT_00411bf0;
  local_20 = 0x81;
  local_1c = DAT_00411bf0 + 0x65;
  local_18 = 0xb8;
  local_10 = DAT_00418f40;
  local_c = DAT_00418f44;
  local_8 = DAT_00418f48;
  FUN_00401d8f(&local_28);
  return;
}


// ==== FUN_0040bfd6 @ 0040bfd6

int __cdecl FUN_0040bfd6(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0040bff7 @ 0040bff7

int __cdecl FUN_0040bff7(int param_1)

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


// ==== FUN_0040c032 @ 0040c032

undefined4 FUN_0040c032(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(s_PentomaniaWnd_00411e80,(LPCSTR)0x0);
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


// ==== FUN_0040c0ae @ 0040c0ae

bool __cdecl FUN_0040c0ae(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040c104 @ 0040c104

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_0040c104(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int iVar6;
  BOOL BVar7;
  HWND pHVar8;
  HMENU pHVar9;
  LPVOID pvVar10;
  tagMSG local_dc;
  WNDCLASSA local_c0;
  HDC local_94;
  HDC local_90;
  DWORD local_8c;
  CHAR local_88 [128];
  HWND local_8;
  
  DAT_0041b754 = param_1;
  iVar2 = FUN_0040c032();
  if (iVar2 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_LineupGameMtx_004120fc);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_dc.wParam = 0;
    }
    else {
      bVar1 = FUN_0040c0ae(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_dc.wParam = 0;
      }
      else {
        local_94 = GetDC((HWND)0x0);
        iVar2 = GetDeviceCaps(local_94,0xc);
        if (iVar2 < 8) {
          ReleaseDC((HWND)0x0,local_94);
          local_dc.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_94);
          FUN_0040184d();
          FUN_004018e7((uint *)s_LINEUP_DLL_00411990);
          FUN_00401a95((uint *)s_LINEUP1_DLL_00411a90);
          FUN_00401865((uint *)s_MSPuzzle_dat_004113a0);
          FUN_00401a95((uint *)s_LINEUP_HLP_00411890);
          FUN_0040167a();
          FUN_00401694(DAT_0041b754);
          FUN_004016d3(s_LINEUP1_DLL_00411a90);
          FUN_004016d3(s_LINEUP_DLL_00411990);
          FUN_004015b0(DAT_0041b754,100,local_88,0x78);
          if (param_2 == 0) {
            local_c0.style = 0;
            local_c0.lpfnWndProc = FUN_0040b9f9;
            local_c0.cbClsExtra = 0;
            local_c0.cbWndExtra = 0;
            local_c0.hInstance = param_1;
            local_c0.hIcon = FUN_004014ed(DAT_0041b754,s_MAINICON_0041210c);
            local_c0.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
            local_c0.hbrBackground = GetStockObject(5);
            local_c0.lpszMenuName = (LPCSTR)0x0;
            local_c0.lpszClassName = s_PentomaniaWnd_00411e80;
            RegisterClassA(&local_c0);
          }
          InitCommonControls();
          FUN_00406751();
          FUN_00402c90();
          FUN_00402c12();
          FUN_0040253f();
          FUN_0040ce27();
          FUN_004025d8();
          local_90 = GetDC((HWND)0x0);
          FUN_00403030(local_90);
          ReleaseDC((HWND)0x0,local_90);
          FUN_0040bed3();
          FUN_00408892();
          DAT_00411b90 = 1;
          DAT_00411b9c = 1;
          DAT_00419a4c = FUN_0040148b(DAT_0041b754,s_ACCELERATORS_1_00412118);
          DAT_00419a40 = FUN_0040154e(DAT_0041b754,s_MainMenuPlayed_00412128);
          DAT_0041b764 = FUN_0040154e(DAT_0041b754,s_MainMenu_00412138);
          if (((DAT_0041b764 == (HMENU)0x0) || (DAT_00419a4c == (HACCEL)0x0)) || (DAT_00419138 == 0)
             ) {
            FUN_0040cc10();
            local_dc.wParam = 0;
          }
          else {
            local_8c = GetVersion();
            if ((byte)local_8c < 4) {
              iVar2 = GetSystemMetrics(5);
              DAT_00419a58 = iVar2 * 2 + _DAT_00411c18;
              iVar2 = GetSystemMetrics(6);
              iVar4 = GetSystemMetrics(0xf);
              iVar5 = GetSystemMetrics(4);
              DAT_00419a64 = iVar2 * 2 + iVar4 + iVar5 + _DAT_00411c1c;
              pvVar10 = (LPVOID)0x0;
              pHVar8 = (HWND)0x0;
              iVar2 = DAT_00419a58;
              iVar4 = DAT_00419a64;
              pHVar9 = DAT_0041b764;
              iVar5 = FUN_0040bff7(DAT_00419a64);
              iVar6 = FUN_0040bfd6(DAT_00419a58);
              local_8 = CreateWindowExA(0,s_PentomaniaWnd_00411e80,local_88,0xca0000,iVar6,iVar5,
                                        iVar2,iVar4,pHVar8,pHVar9,param_1,pvVar10);
            }
            else {
              iVar2 = GetSystemMetrics(7);
              DAT_00419a58 = iVar2 * 2 + _DAT_00411c18;
              iVar2 = GetSystemMetrics(8);
              iVar4 = GetSystemMetrics(0xf);
              iVar5 = GetSystemMetrics(4);
              DAT_00419a64 = iVar2 * 2 + iVar4 + iVar5 + _DAT_00411c1c;
              pvVar10 = (LPVOID)0x0;
              pHVar8 = (HWND)0x0;
              iVar2 = DAT_00419a58;
              iVar4 = DAT_00419a64;
              pHVar9 = DAT_0041b764;
              iVar5 = FUN_0040bff7(DAT_00419a64);
              iVar6 = FUN_0040bfd6(DAT_00419a58);
              local_8 = CreateWindowExA(0x100,s_PentomaniaWnd_00411e80,local_88,0xca0000,iVar6,iVar5
                                        ,iVar2,iVar4,pHVar8,pHVar9,param_1,pvVar10);
            }
            DAT_004191a8 = local_8;
            ShowWindow(local_8,param_4);
            UpdateWindow(local_8);
            FUN_00406715(0);
            FUN_00409fbc();
            FUN_004039ff(0);
            FUN_0040c7f5(1);
            SetTimer(DAT_004191a8,1,100,(TIMERPROC)0x0);
            while (BVar7 = GetMessageA(&local_dc,(HWND)0x0,0,0), BVar7 != 0) {
              iVar2 = TranslateAcceleratorA(DAT_004191a8,DAT_00419a4c,&local_dc);
              if (iVar2 == 0) {
                TranslateMessage(&local_dc);
                DispatchMessageA(&local_dc);
              }
            }
            KillTimer(DAT_004191a8,1);
            if (DAT_00411888 != (HGDIOBJ)0x0) {
              DeleteObject(DAT_00411888);
            }
            FUN_004035e1();
            FUN_0040cc10();
          }
        }
      }
    }
  }
  else {
    local_dc.wParam = 0;
  }
  return local_dc.wParam;
}


// ==== FUN_0040c600 @ 0040c600

void FUN_0040c600(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0041b76c == 1) || (DAT_0041b76c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004122e0,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004122e0,0x804,2,(DWORD_PTR)local_c);
    DAT_004122e0 = 0;
    Sleep(1);
    DAT_0041b76c = 0;
  }
  return;
}


// ==== FUN_0040c6a5 @ 0040c6a5

void FUN_0040c6a5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0041214c != 0) && (DAT_0041b76c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004122e0,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0041b76c = 3;
  }
  return;
}


// ==== FUN_0040c718 @ 0040c718

void __cdecl FUN_0040c718(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041214c != 0) {
    if (DAT_0041b76c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_004122e0,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_004122e0,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_0040c7f5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0041b76c = 1;
    }
    else {
      FUN_0040c7f5(param_1);
    }
  }
  return;
}


// ==== FUN_0040c7f5 @ 0040c7f5

void __cdecl FUN_0040c7f5(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041214c == 0) {
    FUN_0040c600();
  }
  else {
    if (((DAT_0041b768 == param_1) && (0 < param_1)) && (DAT_0041b76c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_004122e0,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0041b76c != 4) {
      FUN_0040c600();
    }
    if (DAT_0041214c != 0) {
      if (0 < param_1) {
        DAT_0041b768 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_0041b768;
      }
      if ((0 < param_1) && (param_1 < 6)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_0041b770 + param_1 * 0x100;
        local_20 = s_sequencer_004122e4;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_004122e0 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_004122e0;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_004122e0 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004122e0,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0041b76c = 1;
          }
          else {
            DAT_0041b76c = 4;
          }
        }
        else {
          DAT_0041b76c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_0040c9d5 @ 0040c9d5

void FUN_0040c9d5(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041214c != 0) {
    if (DAT_0041b76c == 1) {
      if (DAT_004122e0 == 0) {
        DAT_0041b76c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_004122e0,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004122e0,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0041b76c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0041b76c = 4;
        }
      }
    }
    else if (DAT_0041b76c == 4) {
      FUN_0040c7f5(-1);
    }
  }
  return;
}


// ==== FUN_0040caf3 @ 0040caf3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040caf3(int param_1)

{
  DWORD DVar1;
  uint local_8;
  
  if (DAT_00412148 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00412150) {
      DAT_00412150 = DVar1;
    }
    if (DVar1 - _DAT_00412154 < DAT_00412150) {
      if (DAT_00412158 <= *(int *)(&DAT_0041bd7c + param_1 * 0x10)) {
        return;
      }
      local_8 = DAT_00412150 - (DVar1 - _DAT_00412154);
      if (2000 < local_8) {
        local_8 = 2000;
      }
      if (7 < (int)DAT_00411354) {
        local_8 = local_8 / DAT_00411354;
      }
      Sleep(local_8 + 1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00412150 = GetTickCount();
    _DAT_00412154 = *(int *)(&DAT_0041bd78 + param_1 * 0x10);
    DAT_00412158 = *(int *)(&DAT_0041bd7c + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_0041bd70 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_0040cc10 @ 0040cc10

void FUN_0040cc10(void)

{
  int local_c;
  int local_8;
  
  FUN_0040c600();
  FUN_0040caf3(0);
  for (local_8 = 1; local_8 < 9; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0041bd74 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0041bd74 + local_8 * 0x10));
      *(undefined4 *)(&DAT_0041bd74 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_0041bd70 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    DeleteFileA(&DAT_0041b770 + local_c * 0x100);
  }
  return;
}


// ==== FUN_0040ccf8 @ 0040ccf8

void __cdecl FUN_0040ccf8(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00401000(DAT_0041b754,param_2,&DAT_004122f0);
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


// ==== FUN_0040ce27 @ 0040ce27

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ce27(void)

{
  int local_8;
  
  _DAT_0041bd70 = 0;
  _DAT_0041bd74 = 0;
  FUN_0040ccf8((int *)&DAT_0041bd80,s_APPLAUSE_004122f8);
  _DAT_0041bd8c = 1;
  FUN_0040ccf8(&DAT_0041bd90,s_BALLS_00412304);
  _DAT_0041bd9c = 3;
  FUN_0040ccf8((int *)&DAT_0041bda0,s_NOISE_0041230c);
  _DAT_0041bdac = 1;
  FUN_0040ccf8((int *)&DAT_0041bdd0,s_LINECOMPLETE_00412314);
  _DAT_0041bddc = 2;
  FUN_0040ccf8((int *)&DAT_0041bdb0,&DAT_00412324);
  _DAT_0041bdbc = 4;
  FUN_0040ccf8((int *)&DAT_0041bdc0,s_NOBONUS_0041232c);
  _DAT_0041bdcc = 1;
  FUN_0040ccf8((int *)&DAT_0041bde0,s_WHIST1_00412334);
  _DAT_0041bdec = 1;
  FUN_0040ccf8((int *)&DAT_0041bdf0,s_WHIST2_0041233c);
  _DAT_0041bdfc = 1;
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_0041b770 + local_8 * 0x100);
    FUN_0040d150((uint *)(&DAT_0041b770 + local_8 * 0x100),(uint *)(&DAT_00412160 + local_8 * 0x20))
    ;
    FUN_00401223(&DAT_00412220 + local_8 * 0x20,&DAT_00412344,&DAT_0041b770 + local_8 * 0x100);
  }
  return;
}


// ==== FID_conflict:_memcpy @ 0040cff0

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
switchD_0040d0b9_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0040d0b9_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0040d0b9_caseD_3:
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
        goto switchD_0040d0b9_caseD_1;
      case 2:
        goto switchD_0040d0b9_caseD_2;
      case 3:
        goto switchD_0040d0b9_caseD_3;
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
switchD_0040d020_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0040d020_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0040d020_caseD_3:
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
      goto switchD_0040d020_caseD_1;
    case 2:
      goto switchD_0040d020_caseD_2;
    case 3:
      goto switchD_0040d020_caseD_3;
    }
  }
  return _Dst;
}


// ==== FUN_0040d140 @ 0040d140

uint * __cdecl FUN_0040d140(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0040d228;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0040d228:
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


// ==== FUN_0040d150 @ 0040d150

uint * __cdecl FUN_0040d150(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0040d16c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0040d19f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0040d1bb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0040d16c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0040d1bb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0040d1bb;
    }
  }
LAB_0040d19f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0040d1bb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0040d228:
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
    if (bVar1 == 0) goto LAB_0040d228;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _memset @ 0040d230

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


// ==== _strlen @ 0040d290

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0040d2b0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0040d2e3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0040d2b0:
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
  goto LAB_0040d2e3;
}


// ==== _strncmp @ 0040d310

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


// ==== _strcmp @ 0040d350

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
      if (bVar4 != *_Str2) goto LAB_0040d394;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0040d360;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0040d394;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0040d394;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0040d360:
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
LAB_0040d394:
  return (uint)bVar5 * -2 + 1;
}


// ==== FUN_0040d3e0 @ 0040d3e0

void __cdecl FUN_0040d3e0(undefined4 param_1)

{
  DAT_00412350 = param_1;
  return;
}


// ==== _rand @ 0040d3f0

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00412350 = DAT_00412350 * 0x343fd + 0x269ec3;
  return (DAT_00412350 & 0x7fff0000) >> 0x10;
}


// ==== FUN_0040d420 @ 0040d420

int __cdecl FUN_0040d420(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== _free @ 0040d430

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
    HeapFree(DAT_0041c390,0,_Memory);
  }
  return;
}


// ==== _malloc @ 0040d480

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00412b90);
  return pvVar1;
}


// ==== __nh_malloc @ 0040d4a0

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


// ==== __heap_alloc @ 0040d4f0

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00412b8c) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0041c390,0,dwBytes);
  return pvVar2;
}


// ==== entry @ 0040d530

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
  puStack_c = &DAT_00410000;
  puStack_10 = &LAB_0040eca0;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_00412bac = DVar2 >> 8 & 0xff;
  DAT_00412ba0 = DVar2 >> 0x10;
  _DAT_00412ba8 = DVar2 & 0xff;
  _DAT_00412ba4 = _DAT_00412ba8 * 0x100 + _DAT_00412bac;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0041c394 = (byte *)GetCommandLineA();
  DAT_00412354 = ___crtGetEnvironmentStringsA();
  if ((DAT_00412354 == (LPVOID)0x0) || (DAT_0041c394 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0041c394;
  pbVar6 = DAT_0041c394;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_0041c394 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_0040d635;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_0040d635:
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
  _Code = FUN_0040c104(pHVar5,iVar3,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0040d6d0

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00412360 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_0041235c)(0xff);
  return;
}


// ==== __heap_init @ 0040d700

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0041c390 = HeapCreate(1,0x1000,0);
  if (DAT_0041c390 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0041c390);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 0040d740

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
  
  if (DAT_00412b80 == 0) {
    lpMem = &PTR_LOOP_00412370;
  }
  else {
    lpMem = HeapAlloc(DAT_0041c390,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00412370) {
        if (PTR_LOOP_00412370 == (undefined *)0x0) {
          PTR_LOOP_00412370 = (undefined *)&PTR_LOOP_00412370;
        }
        if (PTR_LOOP_00412374 == (undefined *)0x0) {
          PTR_LOOP_00412374 = (undefined *)&PTR_LOOP_00412370;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00412370;
        lpMem[1] = PTR_LOOP_00412374;
        PTR_LOOP_00412374 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00412370) {
    HeapFree(DAT_0041c390,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 0040d8b0

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00412b84 == param_1) {
    PTR_LOOP_00412b84 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00412370) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0041c390,0,param_1);
    return;
  }
  DAT_00412b80 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 0040d910

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
  
  ppuVar4 = (undefined **)PTR_LOOP_00412374;
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
            DAT_00412b88 = DAT_00412b88 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_00412374) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 0040d9f0

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00412370;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00412370) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 0040da50

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00412b88 = DAT_00412b88 + 1, DAT_00412b88 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 0040daa0

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
  
  piVar12 = (int *)PTR_LOOP_00412b84;
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
              PTR_LOOP_00412b84 = (undefined *)piVar12;
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
              PTR_LOOP_00412b84 = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_00412b84 != piVar12);
  ppuVar11 = &PTR_LOOP_00412370;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00412370) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00412b84 = (undefined *)ppuVar11;
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
  PTR_LOOP_00412b84 = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 0040dd20

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


// ==== __callnewh @ 0040dea0

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0041c170 != (code *)0x0) {
    iVar1 = (*DAT_0041c170)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __cinit @ 0040ded0

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_0041c38c != (code *)0x0) {
    (*DAT_0041c38c)();
  }
  __initterm((undefined4 *)&DAT_00411008,(undefined4 *)&DAT_0041100c);
  iVar1 = __initterm((undefined4 *)&DAT_00411000,(undefined4 *)&DAT_00411004);
  return iVar1;
}


// ==== _exit @ 0040df00

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0040df20

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0040df40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_00412bdc == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00412bd8 = 1;
  DAT_00412bd4 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0041c388 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0041c384 + -4), DAT_0041c388 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0041c388 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00411010,(undefined4 *)&DAT_00411014);
  }
  __initterm((undefined4 *)&DAT_00411018,(undefined4 *)&DAT_0041101c);
  if (param_3 == 0) {
    DAT_00412bdc = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0040dff0

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


// ==== __global_unwind2 @ 0040e010

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x40e028,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0040e052

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
  puStack_18 = &LAB_0040e030;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0040e0e6();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_0040e0e6 @ 0040e0e6

void FUN_0040e0e6(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_00412be8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00412be4 = in_EAX;
  DAT_00412bec = unaff_EBP;
  return;
}


// ==== FUN_0040e100 @ 0040e100

LONG __cdecl FUN_0040e100(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = (int *)FUN_0040e260(param_1);
  uVar3 = DAT_00412c78;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(param_2);
    return LVar5;
  }
  if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    return 1;
  }
  if (pcVar1 == (code *)0x1) {
    return -1;
  }
  DAT_00412c78 = param_2;
  if (piVar4[1] == 8) {
    if (DAT_00412c68 < DAT_00412c6c + DAT_00412c68) {
      puVar7 = (undefined4 *)(DAT_00412c68 * 0xc + 0x412bf8);
      iVar6 = DAT_00412c6c;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 3;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar2 = DAT_00412c74;
    iVar6 = *piVar4;
    if (iVar6 == -0x3fffff72) {
      DAT_00412c74 = 0x83;
    }
    else if (iVar6 == -0x3fffff70) {
      DAT_00412c74 = 0x81;
    }
    else if (iVar6 == -0x3fffff6f) {
      DAT_00412c74 = 0x84;
    }
    else if (iVar6 == -0x3fffff6d) {
      DAT_00412c74 = 0x85;
    }
    else if (iVar6 == -0x3fffff73) {
      DAT_00412c74 = 0x82;
    }
    else if (iVar6 == -0x3fffff71) {
      DAT_00412c74 = 0x86;
    }
    else if (iVar6 == -0x3fffff6e) {
      DAT_00412c74 = 0x8a;
    }
    (*pcVar1)(8,DAT_00412c74);
    DAT_00412c74 = uVar2;
  }
  else {
    piVar4[2] = 0;
    (*pcVar1)(piVar4[1]);
  }
  DAT_00412c78 = (_EXCEPTION_POINTERS *)uVar3;
  return -1;
}


// ==== FUN_0040e260 @ 0040e260

uint __cdecl FUN_0040e260(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00412bf0;
  do {
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 3;
  } while (piVar1 < &DAT_00412bf0 + DAT_00412c70 * 3);
  return -(uint)(*piVar1 == param_1) & (uint)piVar1;
}


// ==== __ismbblead @ 0040e290

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 0040e2b0

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00412c88 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00412f4a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 0040e2f0

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
  cVar1 = *DAT_00412354;
  pcVar7 = DAT_00412354;
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
  _DAT_00412bbc = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00412354;
  pcVar7 = DAT_00412354;
  do {
    if (cVar1 == '\0') {
      _free(DAT_00412354);
      DAT_00412354 = (char *)0x0;
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


// ==== __setargv @ 0040e3e0

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0041c178,0x104);
  _DAT_00412bcc = &DAT_0041c178;
  pbVar2 = &DAT_0041c178;
  if (*DAT_0041c394 != 0) {
    pbVar2 = DAT_0041c394;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_00412bb4 = puVar1;
  _DAT_00412bb0 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 0040e480

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
      if (((*(byte *)((int)&DAT_00412c88 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00412c88 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_0040e4f0;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_0040e4f0:
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
          if ((*(byte *)((int)&DAT_00412c88 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_0040e621;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00412c88 + bVar1 + 1) & 4) != 0) {
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
LAB_0040e621:
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


// ==== ___crtGetEnvironmentStringsA @ 0040e660

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
  if (DAT_00412c80 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00412c80 = 2;
    }
    else {
      DAT_00412c80 = 1;
    }
  }
  if (DAT_00412c80 != 1) {
    if (DAT_00412c80 != 2) {
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


// ==== __setmbcp @ 0040e7f0

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
  if (CodePage == DAT_00412d8c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00412db0;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00412c88;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00412dc0 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00412da8)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00412c88 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00412d8c = CodePage;
      _DAT_00412d90 = _CPtoLCID(CodePage);
      DAT_00412d98 = *(undefined4 *)(&DAT_00412db4 + local_18 * 0x30);
      DAT_00412d9c = *(undefined4 *)(&DAT_00412db8 + local_18 * 0x30);
      DAT_00412da0 = *(undefined4 *)(local_18 * 0x30 + 0x412dbc);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00412ea0);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00412c88;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00412d90 = 0;
      DAT_00412d8c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00412c88 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00412c88 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00412d8c = CodePage;
      _DAT_00412d90 = _CPtoLCID(CodePage);
    }
    DAT_00412d98 = 0;
    DAT_00412d9c = 0;
    DAT_00412da0 = 0;
    return 0;
  }
  if (DAT_00412da4 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 0040e9d0

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00412da4 = 1;
                    /* WARNING: Could not recover jumptable at 0x0040e9ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00412da4 = 1;
                    /* WARNING: Could not recover jumptable at 0x0040ea02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00413168;
  }
  DAT_00412da4 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 0040ea20

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


// ==== setSBCS @ 0040ea80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00412c88;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00412d98 = 0;
  DAT_00412d8c = 0;
  _DAT_00412d90 = 0;
  DAT_00412d9c = 0;
  DAT_00412da0 = 0;
  return;
}


// ==== ___initmbctable @ 0040eab0

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 0040eac0

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
  DAT_0041c380 = 0x20;
  DAT_0041c280 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0041c280 + 0x40);
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
    if ((int)DAT_0041c380 < (int)UVar7) {
      piVar4 = &DAT_0041c284;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0041c380;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0041c380 = DAT_0041c380 + 0x20;
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
      } while ((int)DAT_0041c380 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0041c280 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0041c280 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0041c380);
  return UVar7;
}


// ==== FUN_0040ed5d @ 0040ed5d

void FUN_0040ed5d(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 0040ed80

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00412360 == 1) || ((DAT_00412360 == 0 && (DAT_00412364 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00412f38 != (code *)0x0) {
      (*DAT_00412f38)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 0040edc0

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
  piVar2 = &DAT_00412ea8;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00412f38);
  if ((&DAT_00412ea8)[iVar4 * 2] == param_1) {
    if ((DAT_00412360 == 1) || ((DAT_00412360 == 0 && (DAT_00412364 == 1)))) {
      if ((DAT_0041c280 == 0) ||
         (hFile = *(HANDLE *)(DAT_0041c280 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x412eac);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x412eac);
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


// ==== ___crtMessageBoxA @ 0040efc0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0041316c != (FARPROC)0x0) {
LAB_0040f00f:
    if (DAT_00413170 != (FARPROC)0x0) {
      iVar1 = (*DAT_00413170)();
    }
    if ((iVar1 != 0) && (DAT_00413174 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00413174)(iVar1);
    }
    iVar1 = (*DAT_0041316c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0041316c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0041316c != (FARPROC)0x0) {
      DAT_00413170 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00413174 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0040f00f;
    }
  }
  return 0;
}


// ==== _strncpy @ 0040f060

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
        goto joined_r0x0040f09e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0040f0db;
        goto LAB_0040f149;
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
joined_r0x0040f145:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_0040f149:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0040f0db;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x0040f145;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x0040f145;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x0040f145;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0040f09e:
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
LAB_0040f0db:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


