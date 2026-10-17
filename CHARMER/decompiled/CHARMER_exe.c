// ==== FUN_00401000 @ 00401000

HGLOBAL __cdecl FUN_00401000(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00428080 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042c138 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042c138 + local_c * 4),hResInfo);
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
    if (DAT_00428080 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042c138 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_0042c138 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_0042c138 + local_c * 4),hResInfo);
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
    for (local_18 = 0; local_18 < DAT_00428080; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),hResInfo);
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
    if (DAT_00428080 <= local_18) {
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_0042c138 + local_18 * 4),local_14);
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
    if (DAT_00428080 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_0042c138 + local_c * 4),param_2,param_3);
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
    if (DAT_00428080 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_0042c138 + local_c * 4),param_2);
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
    if (DAT_00428080 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_0042c138 + local_c * 4),param_2,param_3,param_4,0);
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
    if (DAT_00428080 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_0042c138 + local_c * 4),param_2);
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
    if (DAT_00428080 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_0042c138 + local_c * 4),param_2);
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
    if (DAT_00428080 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_0042c138 + local_c * 4),param_2);
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
    if (DAT_00428080 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_0042c138 + local_c * 4),param_2,param_3,param_4);
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
    if (DAT_00428080 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_0042c138 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040167a @ 0040167a

void FUN_0040167a(void)

{
  DAT_00428080 = 0;
  return;
}


// ==== FUN_00401694 @ 00401694

bool __cdecl FUN_00401694(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00428080 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_0042c138 + DAT_00428080 * 4) = param_1;
    DAT_00428080 = DAT_00428080 + 1;
  }
  return bVar1;
}


// ==== FUN_004016d3 @ 004016d3

undefined4 __cdecl FUN_004016d3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00428080 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_0042c138 + DAT_00428080 * 4) = pHVar2;
      DAT_00428080 = DAT_00428080 + 1;
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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_0042830c,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_00421360(param_2,local_410);
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
    FUN_00421370(local_104,(uint *)&DAT_00428340);
  }
  FUN_00421370(local_104,param_1);
  FUN_00421360(param_1,local_104);
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
  FUN_00401733(s_Shared_Path_00428344,local_104);
  FUN_00421370(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Shared_Path_00428350,local_104);
    FUN_00421370(local_104,(uint *)&DAT_0042835c);
    FUN_00421370(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_00421360(local_104,(uint *)s___shared__00428360);
      FUN_00421370(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_00421360(local_104,(uint *)&DAT_0042836c);
        FUN_00421370(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00421360(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00421360(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00421360(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00421360(param_1,local_104);
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
  FUN_00401733(s_Help_Path_00428370,local_104);
  FUN_00421370(local_104,param_1);
  bVar1 = FUN_0040180b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00401733(s_Help_Path_0042837c,local_104);
    FUN_00421370(local_104,(uint *)&DAT_00428388);
    FUN_00421370(local_104,param_1);
    bVar1 = FUN_0040180b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_00421360(local_104,(uint *)&DAT_0042838c);
      FUN_00421370(local_104,param_1);
      bVar1 = FUN_0040180b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_00421360(local_104,(uint *)s___shared__00428390);
        FUN_00421370(local_104,param_1);
        bVar1 = FUN_0040180b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00421360(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00421360(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00421360(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00421360(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00401c43 @ 00401c43

undefined4 __cdecl FUN_00401c43(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_00428308 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_0042c238 + DAT_00428308 * 4) = param_1;
    DAT_00428308 = DAT_00428308 + 1;
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
  
  for (local_8 = 0; local_8 < DAT_00428308; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0042c238 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0042c238 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_0042c238 + local_8 * 4) = 0;
  }
  DAT_00428308 = 0;
  return;
}


// ==== FUN_00401d00 @ 00401d00

int __cdecl FUN_00401d00(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_00401d1f @ 00401d1f

void FUN_00401d1f(void)

{
  _memset(&DAT_00430408,0,0x370);
  _memset(&DAT_0042d338,0,0x30d0);
  FID_conflict__memcpy(&DAT_0042d338,s_MD_PACK_004283e8,8);
  DAT_0042f414 = 0;
  DAT_0042f415 = 0;
  DAT_0042f416 = 0;
  DAT_0042d342 = 0xc;
  _memset(&DAT_0042f3e8,0,0x28);
  FID_conflict__memcpy(&DAT_0042f3d8,s_CHARMER_004284f0,0xb);
  return;
}


// ==== FUN_00401db8 @ 00401db8

undefined4 FUN_00401db8(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_00401d1f();
  hFile = _lopen(s_MSPuzzle_dat_004283f0,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_0042d338,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_0042f3d8,s_CHARMER_004284f0,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_0042d338,s_MD_PACK_004283e8,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00430430 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_0042f44c + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00430408 + local_10 * 0x2c,&DAT_0042f424 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00430430 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00430430 + local_10 * 0x2c) = 0;
        }
      }
      DAT_00429964 = (uint)(DAT_0042f414 == '\0');
      DAT_00429960 = (uint)(DAT_0042f415 == '\0');
      DAT_004283bc = (uint)(DAT_0042f416 == '\0');
      FID_conflict__memcpy(&DAT_004283c0,&DAT_0042f3e8,0x28);
      DAT_004283a8 = (uint)DAT_0042f410;
      if ((DAT_004283a8 == 0) || (10 < DAT_004283a8)) {
        DAT_004283a8 = 1;
      }
      DAT_004283ac = (uint)DAT_0042f411;
      if ((DAT_004283ac == 0) || (3 < DAT_004283ac)) {
        DAT_004283ac = 1;
      }
      DAT_004283b0 = (uint)(DAT_0042f412 == '\0');
      DAT_004283b4 = (uint)(DAT_0042f413 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_00401d1f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00402048 @ 00402048

undefined4 __cdecl FUN_00402048(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00430430 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_004020e5 @ 004020e5

int __cdecl FUN_004020e5(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00430430 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00430408 + (local_1c + 1) * 0x2c,&DAT_00430408 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00430408 + local_1c * 0x2c,&DAT_004283c0,0x28);
    *(int *)(&DAT_00430430 + local_1c * 0x2c) = param_1;
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


// ==== FUN_00402229 @ 00402229

void FUN_00402229(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_0042f424,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_0042f424 + local_c * 0x30,&DAT_00430408 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_0042f44c + local_c * 0x30) =
         *(undefined4 *)(&DAT_00430430 + local_c * 0x2c);
  }
  DAT_0042f414 = DAT_00429964 == 0;
  DAT_0042f415 = DAT_00429960 == 0;
  DAT_0042f416 = DAT_004283bc == 0;
  DAT_0042f410 = (undefined1)DAT_004283a8;
  DAT_0042f411 = (undefined1)DAT_004283ac;
  DAT_0042f412 = DAT_004283b0 == 0;
  DAT_0042f413 = DAT_004283b4 == 0;
  _memset(&DAT_0042f3e8,0,0x28);
  FID_conflict__memcpy(&DAT_0042f3e8,&DAT_004283c0,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_004283f0,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_004283f0,0);
  }
  _lwrite(local_8,&DAT_0042d338,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_00402400 @ 00402400

void FUN_00402400(void)

{
  FUN_0040241a();
  FUN_00402442();
  return;
}


// ==== FUN_0040241a @ 0040241a

void FUN_0040241a(void)

{
  _eh_vector_constructor_iterator_(&DAT_00431d08,0xc,0x10,FUN_004137c0,FUN_00413800);
  return;
}


// ==== FUN_00402442 @ 00402442

void FUN_00402442(void)

{
  _atexit(FUN_0040245f);
  return;
}


// ==== FUN_0040245f @ 0040245f

void FUN_0040245f(void)

{
  _eh_vector_destructor_iterator_(&DAT_00431d08,0xc,0x10,FUN_00413800);
  return;
}


// ==== FUN_00402482 @ 00402482

void FUN_00402482(void)

{
  FUN_0040249c();
  FUN_004024c7();
  return;
}


// ==== FUN_0040249c @ 0040249c

void FUN_0040249c(void)

{
  _eh_vector_constructor_iterator_(&DAT_00430c38,0x1a8,7,FUN_00413490,FUN_004135e0);
  return;
}


// ==== FUN_004024c7 @ 004024c7

void FUN_004024c7(void)

{
  _atexit(FUN_004024e4);
  return;
}


// ==== FUN_004024e4 @ 004024e4

void FUN_004024e4(void)

{
  _eh_vector_destructor_iterator_(&DAT_00430c38,0x1a8,7,FUN_004135e0);
  return;
}


// ==== FUN_0040250a @ 0040250a

void FUN_0040250a(void)

{
  FUN_00402524();
  FUN_004027e3();
  return;
}


// ==== FUN_00402524 @ 00402524

/* WARNING: Removing unreachable block (ram,0x00402647) */
/* WARNING: Removing unreachable block (ram,0x004025f4) */
/* WARNING: Removing unreachable block (ram,0x00402767) */
/* WARNING: Switch with 1 destination removed at 0x0040278d */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402524(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00432008 = 0;
  _DAT_00431fe8 = 1;
  _DAT_00431fe4 = 0;
  _DAT_00431fe0 = 0;
  DAT_00431fcc = 0;
  DAT_00431fc8 = 0;
  DAT_00431fc4 = 0;
  DAT_00432004 = 0;
  _DAT_0043200c = 0;
  _DAT_00432010 = 0;
  _DAT_00431fec = 0;
  _DAT_00431ff0 = 0;
  DAT_00432000 = 0;
  DAT_00431ffc = 0;
  DAT_00431ff8 = 0;
  _DAT_00431ff4 = 0;
  DAT_00431fc0 = 9;
  DAT_00431fbc = 2;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004027e3 @ 004027e3

void FUN_004027e3(void)

{
  _atexit(FUN_00402800);
  return;
}


// ==== FUN_00402800 @ 00402800

void FUN_00402800(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00402849;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00402838();
  thunk_FUN_00402853();
  return;
}


// ==== FUN_00402838 @ 00402838

void FUN_00402838(void)

{
  FUN_00413140(&DAT_00431fc4);
  return;
}


// ==== FUN_00402853 @ 00402853

void FUN_00402853(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00402861 @ 00402861

void FUN_00402861(void)

{
  FUN_0040287b();
  FUN_00402aea();
  return;
}


// ==== FUN_0040287b @ 0040287b

/* WARNING: Removing unreachable block (ram,0x00402976) */
/* WARNING: Removing unreachable block (ram,0x004029c9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040287b(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431ab4 = 0;
  _DAT_00431a94 = 1;
  _DAT_00431a90 = 0;
  _DAT_00431a8c = 0;
  DAT_00431a78 = 0;
  DAT_00431a74 = 0;
  DAT_00431a70 = 0;
  _DAT_00431a6c = 0;
  _DAT_00431a68 = 0;
  _DAT_00431a64 = 0;
  _DAT_00431a60 = 0;
  DAT_00431ab0 = 0;
  _DAT_00431ab8 = 0;
  _DAT_00431abc = 0;
  _DAT_00431a98 = 0;
  _DAT_00431a9c = 0;
  DAT_00431aac = 0;
  DAT_00431aa8 = 0;
  DAT_00431aa4 = 0;
  _DAT_00431aa0 = 0;
  DAT_00431a58 = 0;
  DAT_00431a5c = 3;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00402aea @ 00402aea

void FUN_00402aea(void)

{
  _atexit(FUN_00402b07);
  return;
}


// ==== FUN_00402b07 @ 00402b07

void FUN_00402b07(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00402b69;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  FUN_00402b4c();
  local_8 = 0xffffffff;
  FUN_00402b58();
  thunk_FUN_00402b73();
  return;
}


// ==== FUN_00402b4c @ 00402b4c

void FUN_00402b4c(void)

{
  FUN_00413140(&DAT_00431a70);
  return;
}


// ==== FUN_00402b58 @ 00402b58

void FUN_00402b58(void)

{
  FUN_00412fe0((int *)&DAT_00431a60);
  return;
}


// ==== FUN_00402b73 @ 00402b73

void FUN_00402b73(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00402b81 @ 00402b81

void FUN_00402b81(void)

{
  FUN_00402b9b();
  FUN_00402c74();
  return;
}


// ==== FUN_00402b9b @ 00402b9b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402b9b(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431f60 = 0;
  _DAT_00431f64 = 0;
  _DAT_00431f68 = 0;
  _DAT_00431f6c = 0;
  DAT_00431f48 = 1;
  DAT_00431f4c = 0;
  DAT_00431f5c = 0;
  DAT_00431f70 = 1;
  DAT_00431f74 = 4;
  DAT_00431f78 = 2;
  DAT_00431f7c = 1;
  DAT_00431fa8 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00402c74 @ 00402c74

void FUN_00402c74(void)

{
  _atexit(FUN_00402c91);
  return;
}


// ==== FUN_00402c91 @ 00402c91

void FUN_00402c91(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00402cda;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00402cc9();
  thunk_FUN_00402ce4();
  return;
}


// ==== FUN_00402cc9 @ 00402cc9

void FUN_00402cc9(void)

{
  FUN_00412fe0((int *)&DAT_00431f60);
  return;
}


// ==== FUN_00402ce4 @ 00402ce4

void FUN_00402ce4(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00402cf2 @ 00402cf2

void FUN_00402cf2(void)

{
  FUN_00402d0c();
  FUN_00402d49();
  return;
}


// ==== FUN_00402d0c @ 00402d0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402d0c(void)

{
  DAT_00430778 = 0;
  _DAT_0043077c = 0;
  _DAT_00430780 = 0;
  _DAT_00430784 = 1;
  return;
}


// ==== FUN_00402d49 @ 00402d49

void FUN_00402d49(void)

{
  _atexit(FUN_00402d66);
  return;
}


// ==== FUN_00402d66 @ 00402d66

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402d66(void)

{
  if (DAT_00430778 != 0) {
    DAT_00430778 = 0;
  }
  _DAT_0043077c = 0;
  _DAT_00430780 = 0;
  _DAT_00430784 = 1;
  return;
}


// ==== FUN_00402db0 @ 00402db0

void FUN_00402db0(void)

{
  FUN_00402dca();
  FUN_00402e71();
  return;
}


// ==== FUN_00402dca @ 00402dca

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402dca(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_00432024 = 0;
  _DAT_00432028 = 0;
  _DAT_0043202c = 0;
  _DAT_00432030 = 0;
  DAT_00432018 = 0;
  DAT_0043201c = 0;
  DAT_00432020 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00402e71 @ 00402e71

void FUN_00402e71(void)

{
  _atexit(FUN_00402e8e);
  return;
}


// ==== FUN_00402e8e @ 00402e8e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402e8e(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00402f42;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  DAT_00432018 = 0;
  if (DAT_00432024 != (void *)0x0) {
    FUN_00421c00(DAT_00432024);
  }
  DAT_00432024 = (void *)0x0;
  _DAT_0043202c = 0;
  _DAT_00432030 = 0;
  DAT_0043201c = 0;
  DAT_00432020 = 0;
  local_8 = 0xffffffff;
  FUN_00402f31();
  thunk_FUN_00402f4c();
  return;
}


// ==== FUN_00402f31 @ 00402f31

void FUN_00402f31(void)

{
  FUN_00412fe0(&DAT_00432024);
  return;
}


// ==== FUN_00402f4c @ 00402f4c

void FUN_00402f4c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FID_conflict:_$E31 @ 00402f5a

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_00402f74();
  FUN_00402f8e();
  return;
}


// ==== FUN_00402f74 @ 00402f74

void FUN_00402f74(void)

{
  FUN_0040df12(0x431868);
  return;
}


// ==== FUN_00402f8e @ 00402f8e

void FUN_00402f8e(void)

{
  _atexit(FUN_00402fab);
  return;
}


// ==== FUN_00402fab @ 00402fab

void FUN_00402fab(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00403000;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00402fe3();
  thunk_FUN_0040300a();
  return;
}


// ==== FUN_00402fe3 @ 00402fe3

void FUN_00402fe3(void)

{
  _eh_vector_destructor_iterator_(&DAT_00431870,0x50,6,FUN_00413140);
  return;
}


// ==== FUN_0040300a @ 0040300a

void FUN_0040300a(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FID_conflict:_$E31 @ 00403018

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_00403032();
  FUN_0040304c();
  return;
}


// ==== FUN_00403032 @ 00403032

void FUN_00403032(void)

{
  FUN_0040e37e(&DAT_004307f8);
  return;
}


// ==== FUN_0040304c @ 0040304c

void FUN_0040304c(void)

{
  _atexit(FUN_00403069);
  return;
}


// ==== FUN_00403069 @ 00403069

void FUN_00403069(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004030be;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_004030a1();
  thunk_FUN_004030c8();
  return;
}


// ==== FUN_004030a1 @ 004030a1

void FUN_004030a1(void)

{
  _eh_vector_destructor_iterator_(&DAT_00430804,0x50,7,FUN_00413140);
  return;
}


// ==== FUN_004030c8 @ 004030c8

void FUN_004030c8(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FID_conflict:_$E31 @ 004030d6

/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_004030f0();
  FUN_0040310a();
  return;
}


// ==== FUN_004030f0 @ 004030f0

void FUN_004030f0(void)

{
  FUN_0040e885(&DAT_00431b10);
  return;
}


// ==== FUN_0040310a @ 0040310a

void FUN_0040310a(void)

{
  _atexit(FUN_00403127);
  return;
}


// ==== FUN_00403127 @ 00403127

void FUN_00403127(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040317c;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_0040315f();
  thunk_FUN_00403186();
  return;
}


// ==== FUN_0040315f @ 0040315f

void FUN_0040315f(void)

{
  _eh_vector_destructor_iterator_(&DAT_00431b1c,0x50,6,FUN_00413140);
  return;
}


// ==== FUN_00403186 @ 00403186

void FUN_00403186(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403194 @ 00403194

void FUN_00403194(void)

{
  FUN_004031ae();
  FUN_004033a3();
  return;
}


// ==== FUN_004031ae @ 004031ae

/* WARNING: Removing unreachable block (ram,0x00403279) */
/* WARNING: Removing unreachable block (ram,0x004032cc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004031ae(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_004307e4 = 0;
  _DAT_004307c4 = 1;
  _DAT_004307c0 = 0;
  _DAT_004307bc = 0;
  DAT_004307a8 = 0;
  DAT_004307a4 = 0;
  DAT_004307a0 = 0;
  DAT_004307e0 = 0;
  _DAT_004307e8 = 0;
  _DAT_004307ec = 0;
  _DAT_004307c8 = 0;
  _DAT_004307cc = 0;
  DAT_004307dc = 0;
  DAT_004307d8 = 0;
  DAT_004307d4 = 0;
  _DAT_004307d0 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004033a3 @ 004033a3

void FUN_004033a3(void)

{
  _atexit(FUN_004033c0);
  return;
}


// ==== FUN_004033c0 @ 004033c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004033c0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_004034da;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_004307a0 = 0;
  DAT_004307a8 = 0;
  _DAT_004307bc = 0;
  _DAT_004307c0 = 0;
  _DAT_004307c4 = 1;
  if (DAT_004307e0 != (void *)0x0) {
    FUN_00421c00(DAT_004307e0);
  }
  DAT_004307e0 = (void *)0x0;
  _DAT_004307e8 = 0;
  _DAT_004307ec = 0;
  _DAT_004307c8 = 0;
  _DAT_004307cc = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004034be();
  local_8 = 0xffffffff;
  FUN_004034ca();
  thunk_FUN_004034e4();
  return;
}


// ==== FUN_004034be @ 004034be

void FUN_004034be(void)

{
  FUN_00412fe0(&DAT_004307e0);
  return;
}


// ==== FUN_004034ca @ 004034ca

void FUN_004034ca(void)

{
  FUN_00413090(&DAT_004307a0);
  return;
}


// ==== FUN_004034e4 @ 004034e4

void FUN_004034e4(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004034f2 @ 004034f2

void FUN_004034f2(void)

{
  FUN_0040350c();
  FUN_00403701();
  return;
}


// ==== FUN_0040350c @ 0040350c

/* WARNING: Removing unreachable block (ram,0x004035d7) */
/* WARNING: Removing unreachable block (ram,0x0040362a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040350c(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431824 = 0;
  _DAT_00431804 = 1;
  _DAT_00431800 = 0;
  _DAT_004317fc = 0;
  DAT_004317e8 = 0;
  DAT_004317e4 = 0;
  DAT_004317e0 = 0;
  DAT_00431820 = 0;
  _DAT_00431828 = 0;
  _DAT_0043182c = 0;
  _DAT_00431808 = 0;
  _DAT_0043180c = 0;
  DAT_0043181c = 0;
  DAT_00431818 = 0;
  DAT_00431814 = 0;
  _DAT_00431810 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403701 @ 00403701

void FUN_00403701(void)

{
  _atexit(FUN_0040371e);
  return;
}


// ==== FUN_0040371e @ 0040371e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040371e(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00403838;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_004317e0 = 0;
  DAT_004317e8 = 0;
  _DAT_004317fc = 0;
  _DAT_00431800 = 0;
  _DAT_00431804 = 1;
  if (DAT_00431820 != (void *)0x0) {
    FUN_00421c00(DAT_00431820);
  }
  DAT_00431820 = (void *)0x0;
  _DAT_00431828 = 0;
  _DAT_0043182c = 0;
  _DAT_00431808 = 0;
  _DAT_0043180c = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0040381c();
  local_8 = 0xffffffff;
  FUN_00403828();
  thunk_FUN_00403842();
  return;
}


// ==== FUN_0040381c @ 0040381c

void FUN_0040381c(void)

{
  FUN_00412fe0(&DAT_00431820);
  return;
}


// ==== FUN_00403828 @ 00403828

void FUN_00403828(void)

{
  FUN_00413090(&DAT_004317e0);
  return;
}


// ==== FUN_00403842 @ 00403842

void FUN_00403842(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403850 @ 00403850

void FUN_00403850(void)

{
  FUN_0040386a();
  FUN_00403a5f();
  return;
}


// ==== FUN_0040386a @ 0040386a

/* WARNING: Removing unreachable block (ram,0x00403935) */
/* WARNING: Removing unreachable block (ram,0x00403988) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040386a(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431e6c = 0;
  _DAT_00431e4c = 1;
  _DAT_00431e48 = 0;
  _DAT_00431e44 = 0;
  DAT_00431e30 = 0;
  DAT_00431e2c = 0;
  DAT_00431e28 = 0;
  DAT_00431e68 = 0;
  _DAT_00431e70 = 0;
  _DAT_00431e74 = 0;
  _DAT_00431e50 = 0;
  _DAT_00431e54 = 0;
  DAT_00431e64 = 0;
  DAT_00431e60 = 0;
  DAT_00431e5c = 0;
  _DAT_00431e58 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403a5f @ 00403a5f

void FUN_00403a5f(void)

{
  _atexit(FUN_00403a7c);
  return;
}


// ==== FUN_00403a7c @ 00403a7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403a7c(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00403b96;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00431e28 = 0;
  DAT_00431e30 = 0;
  _DAT_00431e44 = 0;
  _DAT_00431e48 = 0;
  _DAT_00431e4c = 1;
  if (DAT_00431e68 != (void *)0x0) {
    FUN_00421c00(DAT_00431e68);
  }
  DAT_00431e68 = (void *)0x0;
  _DAT_00431e70 = 0;
  _DAT_00431e74 = 0;
  _DAT_00431e50 = 0;
  _DAT_00431e54 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00403b7a();
  local_8 = 0xffffffff;
  FUN_00403b86();
  thunk_FUN_00403ba0();
  return;
}


// ==== FUN_00403b7a @ 00403b7a

void FUN_00403b7a(void)

{
  FUN_00412fe0(&DAT_00431e68);
  return;
}


// ==== FUN_00403b86 @ 00403b86

void FUN_00403b86(void)

{
  FUN_00413090(&DAT_00431e28);
  return;
}


// ==== FUN_00403ba0 @ 00403ba0

void FUN_00403ba0(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403bae @ 00403bae

void FUN_00403bae(void)

{
  FUN_00403bc8();
  FUN_00403dbd();
  return;
}


// ==== FUN_00403bc8 @ 00403bc8

/* WARNING: Removing unreachable block (ram,0x00403c93) */
/* WARNING: Removing unreachable block (ram,0x00403ce6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403bc8(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00431e0c = 0;
  _DAT_00431dec = 1;
  _DAT_00431de8 = 0;
  _DAT_00431de4 = 0;
  DAT_00431dd0 = 0;
  DAT_00431dcc = 0;
  DAT_00431dc8 = 0;
  DAT_00431e08 = 0;
  _DAT_00431e10 = 0;
  _DAT_00431e14 = 0;
  _DAT_00431df0 = 0;
  _DAT_00431df4 = 0;
  DAT_00431e04 = 0;
  DAT_00431e00 = 0;
  DAT_00431dfc = 0;
  _DAT_00431df8 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403dbd @ 00403dbd

void FUN_00403dbd(void)

{
  _atexit(FUN_00403dda);
  return;
}


// ==== FUN_00403dda @ 00403dda

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403dda(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00403ef4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00431dc8 = 0;
  DAT_00431dd0 = 0;
  _DAT_00431de4 = 0;
  _DAT_00431de8 = 0;
  _DAT_00431dec = 1;
  if (DAT_00431e08 != (void *)0x0) {
    FUN_00421c00(DAT_00431e08);
  }
  DAT_00431e08 = (void *)0x0;
  _DAT_00431e10 = 0;
  _DAT_00431e14 = 0;
  _DAT_00431df0 = 0;
  _DAT_00431df4 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00403ed8();
  local_8 = 0xffffffff;
  FUN_00403ee4();
  thunk_FUN_00403efe();
  return;
}


// ==== FUN_00403ed8 @ 00403ed8

void FUN_00403ed8(void)

{
  FUN_00412fe0(&DAT_00431e08);
  return;
}


// ==== FUN_00403ee4 @ 00403ee4

void FUN_00403ee4(void)

{
  FUN_00413090(&DAT_00431dc8);
  return;
}


// ==== FUN_00403efe @ 00403efe

void FUN_00403efe(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00403f0c @ 00403f0c

void FUN_00403f0c(void)

{
  FUN_00403f26();
  FUN_0040411b();
  return;
}


// ==== FUN_00403f26 @ 00403f26

/* WARNING: Removing unreachable block (ram,0x00403ff1) */
/* WARNING: Removing unreachable block (ram,0x00404044) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403f26(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430b2c = 0;
  _DAT_00430b0c = 1;
  _DAT_00430b08 = 0;
  _DAT_00430b04 = 0;
  DAT_00430af0 = 0;
  DAT_00430aec = 0;
  DAT_00430ae8 = 0;
  DAT_00430b28 = 0;
  _DAT_00430b30 = 0;
  _DAT_00430b34 = 0;
  _DAT_00430b10 = 0;
  _DAT_00430b14 = 0;
  DAT_00430b24 = 0;
  DAT_00430b20 = 0;
  DAT_00430b1c = 0;
  _DAT_00430b18 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_0040411b @ 0040411b

void FUN_0040411b(void)

{
  _atexit(FUN_00404138);
  return;
}


// ==== FUN_00404138 @ 00404138

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404138(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00404252;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430ae8 = 0;
  DAT_00430af0 = 0;
  _DAT_00430b04 = 0;
  _DAT_00430b08 = 0;
  _DAT_00430b0c = 1;
  if (DAT_00430b28 != (void *)0x0) {
    FUN_00421c00(DAT_00430b28);
  }
  DAT_00430b28 = (void *)0x0;
  _DAT_00430b30 = 0;
  _DAT_00430b34 = 0;
  _DAT_00430b10 = 0;
  _DAT_00430b14 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404236();
  local_8 = 0xffffffff;
  FUN_00404242();
  thunk_FUN_0040425c();
  return;
}


// ==== FUN_00404236 @ 00404236

void FUN_00404236(void)

{
  FUN_00412fe0(&DAT_00430b28);
  return;
}


// ==== FUN_00404242 @ 00404242

void FUN_00404242(void)

{
  FUN_00413090(&DAT_00430ae8);
  return;
}


// ==== FUN_0040425c @ 0040425c

void FUN_0040425c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040426a @ 0040426a

void FUN_0040426a(void)

{
  FUN_00404284();
  FUN_00404479();
  return;
}


// ==== FUN_00404284 @ 00404284

/* WARNING: Removing unreachable block (ram,0x0040434f) */
/* WARNING: Removing unreachable block (ram,0x004043a2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404284(void)

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


// ==== FUN_00404479 @ 00404479

void FUN_00404479(void)

{
  _atexit(FUN_00404496);
  return;
}


// ==== FUN_00404496 @ 00404496

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404496(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_004045b0;
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
    FUN_00421c00(DAT_00430ad8);
  }
  DAT_00430ad8 = (void *)0x0;
  _DAT_00430ae0 = 0;
  _DAT_00430ae4 = 0;
  _DAT_00430ac0 = 0;
  _DAT_00430ac4 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404594();
  local_8 = 0xffffffff;
  FUN_004045a0();
  thunk_FUN_004045ba();
  return;
}


// ==== FUN_00404594 @ 00404594

void FUN_00404594(void)

{
  FUN_00412fe0(&DAT_00430ad8);
  return;
}


// ==== FUN_004045a0 @ 004045a0

void FUN_004045a0(void)

{
  FUN_00413090(&DAT_00430a98);
  return;
}


// ==== FUN_004045ba @ 004045ba

void FUN_004045ba(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004045c8 @ 004045c8

void FUN_004045c8(void)

{
  FUN_004045e2();
  FUN_004047d7();
  return;
}


// ==== FUN_004045e2 @ 004045e2

/* WARNING: Removing unreachable block (ram,0x004046ad) */
/* WARNING: Removing unreachable block (ram,0x00404700) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004045e2(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430a8c = 0;
  DAT_00430a6c = 1;
  DAT_00430a68 = 0;
  DAT_00430a64 = 0;
  DAT_00430a50 = 0;
  DAT_00430a4c = 0;
  DAT_00430a48 = 0;
  DAT_00430a88 = 0;
  _DAT_00430a90 = 0;
  _DAT_00430a94 = 0;
  _DAT_00430a70 = 0;
  _DAT_00430a74 = 0;
  DAT_00430a84 = 0;
  DAT_00430a80 = 0;
  DAT_00430a7c = 0;
  _DAT_00430a78 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004047d7 @ 004047d7

void FUN_004047d7(void)

{
  _atexit(FUN_004047f4);
  return;
}


// ==== FUN_004047f4 @ 004047f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004047f4(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0040490e;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430a48 = 0;
  DAT_00430a50 = 0;
  DAT_00430a64 = 0;
  DAT_00430a68 = 0;
  DAT_00430a6c = 1;
  if (DAT_00430a88 != (void *)0x0) {
    FUN_00421c00(DAT_00430a88);
  }
  DAT_00430a88 = (void *)0x0;
  _DAT_00430a90 = 0;
  _DAT_00430a94 = 0;
  _DAT_00430a70 = 0;
  _DAT_00430a74 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004048f2();
  local_8 = 0xffffffff;
  FUN_004048fe();
  thunk_FUN_00404918();
  return;
}


// ==== FUN_004048f2 @ 004048f2

void FUN_004048f2(void)

{
  FUN_00412fe0(&DAT_00430a88);
  return;
}


// ==== FUN_004048fe @ 004048fe

void FUN_004048fe(void)

{
  FUN_00413090(&DAT_00430a48);
  return;
}


// ==== FUN_00404918 @ 00404918

void FUN_00404918(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00404926 @ 00404926

void FUN_00404926(void)

{
  FUN_00404940();
  FUN_00404b35();
  return;
}


// ==== FUN_00404940 @ 00404940

/* WARNING: Removing unreachable block (ram,0x00404a0b) */
/* WARNING: Removing unreachable block (ram,0x00404a5e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404940(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430c24 = 0;
  DAT_00430c04 = 1;
  DAT_00430c00 = 0;
  DAT_00430bfc = 0;
  DAT_00430be8 = 0;
  DAT_00430be4 = 0;
  DAT_00430be0 = 0;
  DAT_00430c20 = 0;
  _DAT_00430c28 = 0;
  _DAT_00430c2c = 0;
  _DAT_00430c08 = 0;
  _DAT_00430c0c = 0;
  DAT_00430c1c = 0;
  DAT_00430c18 = 0;
  DAT_00430c14 = 0;
  _DAT_00430c10 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00404b35 @ 00404b35

void FUN_00404b35(void)

{
  _atexit(FUN_00404b52);
  return;
}


// ==== FUN_00404b52 @ 00404b52

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404b52(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00404c6c;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430be0 = 0;
  DAT_00430be8 = 0;
  DAT_00430bfc = 0;
  DAT_00430c00 = 0;
  DAT_00430c04 = 1;
  if (DAT_00430c20 != (void *)0x0) {
    FUN_00421c00(DAT_00430c20);
  }
  DAT_00430c20 = (void *)0x0;
  _DAT_00430c28 = 0;
  _DAT_00430c2c = 0;
  _DAT_00430c08 = 0;
  _DAT_00430c0c = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404c50();
  local_8 = 0xffffffff;
  FUN_00404c5c();
  thunk_FUN_00404c76();
  return;
}


// ==== FUN_00404c50 @ 00404c50

void FUN_00404c50(void)

{
  FUN_00412fe0(&DAT_00430c20);
  return;
}


// ==== FUN_00404c5c @ 00404c5c

void FUN_00404c5c(void)

{
  FUN_00413090(&DAT_00430be0);
  return;
}


// ==== FUN_00404c76 @ 00404c76

void FUN_00404c76(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00404c84 @ 00404c84

void FUN_00404c84(void)

{
  FUN_00404c9e();
  FUN_00404e93();
  return;
}


// ==== FUN_00404c9e @ 00404c9e

/* WARNING: Removing unreachable block (ram,0x00404d69) */
/* WARNING: Removing unreachable block (ram,0x00404dbc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404c9e(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430b84 = 0;
  DAT_00430b64 = 1;
  DAT_00430b60 = 0;
  DAT_00430b5c = 0;
  DAT_00430b48 = 0;
  DAT_00430b44 = 0;
  DAT_00430b40 = 0;
  DAT_00430b80 = 0;
  _DAT_00430b88 = 0;
  _DAT_00430b8c = 0;
  _DAT_00430b68 = 0;
  _DAT_00430b6c = 0;
  DAT_00430b7c = 0;
  DAT_00430b78 = 0;
  DAT_00430b74 = 0;
  _DAT_00430b70 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00404e93 @ 00404e93

void FUN_00404e93(void)

{
  _atexit(FUN_00404eb0);
  return;
}


// ==== FUN_00404eb0 @ 00404eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404eb0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00404fca;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430b40 = 0;
  DAT_00430b48 = 0;
  DAT_00430b5c = 0;
  DAT_00430b60 = 0;
  DAT_00430b64 = 1;
  if (DAT_00430b80 != (void *)0x0) {
    FUN_00421c00(DAT_00430b80);
  }
  DAT_00430b80 = (void *)0x0;
  _DAT_00430b88 = 0;
  _DAT_00430b8c = 0;
  _DAT_00430b68 = 0;
  _DAT_00430b6c = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404fae();
  local_8 = 0xffffffff;
  FUN_00404fba();
  thunk_FUN_00404fd4();
  return;
}


// ==== FUN_00404fae @ 00404fae

void FUN_00404fae(void)

{
  FUN_00412fe0(&DAT_00430b80);
  return;
}


// ==== FUN_00404fba @ 00404fba

void FUN_00404fba(void)

{
  FUN_00413090(&DAT_00430b40);
  return;
}


// ==== FUN_00404fd4 @ 00404fd4

void FUN_00404fd4(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00404fe2 @ 00404fe2

void FUN_00404fe2(void)

{
  FUN_00404ffc();
  FUN_004051f1();
  return;
}


// ==== FUN_00404ffc @ 00404ffc

/* WARNING: Removing unreachable block (ram,0x004050c7) */
/* WARNING: Removing unreachable block (ram,0x0040511a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404ffc(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_00430bd4 = 0;
  _DAT_00430bb4 = 1;
  _DAT_00430bb0 = 0;
  _DAT_00430bac = 0;
  DAT_00430b98 = 0;
  DAT_00430b94 = 0;
  DAT_00430b90 = 0;
  DAT_00430bd0 = 0;
  _DAT_00430bd8 = 0;
  _DAT_00430bdc = 0;
  _DAT_00430bb8 = 0;
  _DAT_00430bbc = 0;
  DAT_00430bcc = 0;
  DAT_00430bc8 = 0;
  DAT_00430bc4 = 0;
  _DAT_00430bc0 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004051f1 @ 004051f1

void FUN_004051f1(void)

{
  _atexit(FUN_0040520e);
  return;
}


// ==== FUN_0040520e @ 0040520e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040520e(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00405328;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  DAT_00430b90 = 0;
  DAT_00430b98 = 0;
  _DAT_00430bac = 0;
  _DAT_00430bb0 = 0;
  _DAT_00430bb4 = 1;
  if (DAT_00430bd0 != (void *)0x0) {
    FUN_00421c00(DAT_00430bd0);
  }
  DAT_00430bd0 = (void *)0x0;
  _DAT_00430bd8 = 0;
  _DAT_00430bdc = 0;
  _DAT_00430bb8 = 0;
  _DAT_00430bbc = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0040530c();
  local_8 = 0xffffffff;
  FUN_00405318();
  thunk_FUN_00405332();
  return;
}


// ==== FUN_0040530c @ 0040530c

void FUN_0040530c(void)

{
  FUN_00412fe0(&DAT_00430bd0);
  return;
}


// ==== FUN_00405318 @ 00405318

void FUN_00405318(void)

{
  FUN_00413090(&DAT_00430b90);
  return;
}


// ==== FUN_00405332 @ 00405332

void FUN_00405332(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00405340 @ 00405340

void __cdecl FUN_00405340(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00429110 = 2;
  }
  DAT_00430b38 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00405383 @ 00405383

void __cdecl FUN_00405383(HWND param_1)

{
  if (DAT_00430b38 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00430b38);
  }
  return;
}


// ==== FUN_004053b4 @ 004053b4

void __cdecl FUN_004053b4(uint *param_1)

{
  FUN_00421360((uint *)&DAT_00429118,param_1);
  return;
}


// ==== FUN_004053d5 @ 004053d5

void __cdecl FUN_004053d5(HWND param_1)

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


// ==== FUN_0040550d @ 0040550d

void __cdecl FUN_0040550d(int param_1)

{
  if (((0 < param_1) && (param_1 < 4)) && (*(int *)(&DAT_00431840 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00431840 + param_1 * 4) = 1;
    DAT_00430788 = 1;
    Sleep(100);
    if (param_1 == 1) {
      FUN_004053b4((uint *)s_QUICKHELPBMP_00429610);
      FUN_0040141d(DAT_00431e20,s_QTIPPARROT_00429620,DAT_00432088,FUN_004067b5);
    }
    else if (param_1 == 2) {
      FUN_004053b4((uint *)s_QUICKHELPBMP_0042964c);
      FUN_0040141d(DAT_00431e20,s_QTIPPARTNER_0042965c,DAT_00432088,FUN_004067b5);
    }
    else if (param_1 == 3) {
      FUN_004053b4((uint *)s_QUICKHELPBMP_0042962c);
      FUN_0040141d(DAT_00431e20,s_QHCONGRATULATE_0042963c,DAT_00432088,FUN_00406a2b);
    }
    DAT_00430788 = 0;
    FUN_0040f43e();
    FUN_0040f14c();
  }
  return;
}


// ==== FUN_00405646 @ 00405646

INT_PTR __cdecl FUN_00405646(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040141d(DAT_00431e20,s_RESETSCORE_00429668,param_1,FUN_00407c7d);
  return IVar1;
}


// ==== FUN_0040567b @ 0040567b

INT_PTR FUN_0040567b(void)

{
  INT_PTR IVar1;
  
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_QUICKHELPBMP_00429674);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_00431e20,s_EXITGAME_00429684,DAT_00432088,FUN_00405bec);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_004056f3 @ 004056f3

INT_PTR FUN_004056f3(void)

{
  INT_PTR IVar1;
  
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_QUICKHELPBMP_00429690);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  IVar1 = FUN_0040141d(DAT_00431e20,s_NEWGAME_004296a0,DAT_00432088,FUN_00405bec);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return IVar1;
}


// ==== FUN_0040576b @ 0040576b

void FUN_0040576b(void)

{
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_ABOUTBMP_004296a8);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  FUN_0040141d(DAT_00431e20,s_ABOUT_004296b4,DAT_00432088,FUN_00405d8c);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return;
}


// ==== FUN_004057da @ 004057da

void __cdecl FUN_004057da(HWND param_1)

{
  FUN_0040141d(DAT_00431e20,s_CREDITS_004296bc,param_1,FUN_0040607c);
  return;
}


// ==== FUN_00405806 @ 00405806

void __cdecl FUN_00405806(HWND param_1)

{
  FUN_0040141d(DAT_00431e20,s_SYSTEMINFODIALOG_004296c4,param_1,FUN_00406217);
  return;
}


// ==== FUN_00405832 @ 00405832

void FUN_00405832(void)

{
  DAT_00430788 = 1;
  FUN_004053b4((uint *)s_QUICKHELPBMP_004296d8);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  FUN_0040141d(DAT_00431e20,s_QUICKHELPDIALOG_004296e8,DAT_00432088,FUN_00406c5c);
  DAT_00430788 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return;
}


// ==== FUN_004058a1 @ 004058a1

void FUN_004058a1(void)

{
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_CUPBMP_004296f8);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  FUN_0040141d(DAT_00431e20,s_YOURNAME_00429700,DAT_00432088,FUN_00406ed2);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return;
}


// ==== FUN_00405910 @ 00405910

void FUN_00405910(void)

{
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_CUPBMP_0042970c);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  FUN_0040141d(DAT_00431e20,s_BALLSTOP_00429714,DAT_00432088,FUN_0040721b);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return;
}


// ==== FUN_0040597f @ 0040597f

void FUN_0040597f(void)

{
  DAT_004317d0 = 1;
  FUN_004053b4((uint *)s_OPTIONSBMP_00429720);
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  FUN_0040141d(DAT_00431e20,s_OPTIONS_0042972c,DAT_00432088,FUN_004075a2);
  DAT_004317d0 = 0;
  InvalidateRect(DAT_00432088,(RECT *)0x0,0);
  return;
}


// ==== FUN_004059ee @ 004059ee

void __cdecl FUN_004059ee(HWND param_1)

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
  ho = FUN_00414310(pHVar1,s_QUICKHELPBMP_00429734);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00414231(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00432f3c,0);
  RealizePalette(pHVar1);
  FUN_0041427a(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_00405aed @ 00405aed

void __cdecl FUN_00405aed(HWND param_1)

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
  local_8 = FUN_00414310(pHVar1,&DAT_00429118);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_00414231(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00432f3c,0);
  RealizePalette(pHVar1);
  FUN_0041427a(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00405bec @ 00405bec

UINT FUN_00405bec(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004053d5(param_1);
      DAT_00431e1c = param_1;
      DAT_00431e18 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00405aed(DAT_00431e18);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00431e1c) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00431e1c);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00431e1c,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00431e1c,(RECT *)0x0,0);
        InvalidateRect(DAT_00432088,(RECT *)0x0,0);
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


// ==== FUN_00405d8c @ 00405d8c

UINT FUN_00405d8c(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004053d5(param_1);
      DAT_00431fac = param_1;
      DAT_00431e78 = GetDlgItem(param_1,100);
      FUN_004015b0(DAT_00431e20,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00401733(&DAT_00429744,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00401733(s_Product_ID_00429748,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00405aed(DAT_00431e78);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00431fac) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_00431fac);
      SelectPalette(local_10c,DAT_00432f3c,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_00431fac,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00431fac,(RECT *)0x0,0);
      InvalidateRect(DAT_00432088,(RECT *)0x0,0);
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
      FUN_00405806(param_1);
      return 1;
    case (HWND)0x66:
      FUN_004057da(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040607c @ 0040607c

UINT FUN_0040607c(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004053d5(param_1);
      DAT_00431854 = param_1;
      DAT_00431838 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00405aed(DAT_00431838);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00431854 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00431854);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00431854,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00431854,(RECT *)0x0,0);
        InvalidateRect(DAT_00431fac,(RECT *)0x0,0);
        InvalidateRect(DAT_00432088,(RECT *)0x0,0);
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


// ==== FUN_00406217 @ 00406217

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00406217(HWND param_1,int param_2,uint param_3)

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
    FUN_004053d5(param_1);
    _DAT_004307f0 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_00429754,local_49c.dwMajorVersion,-1);
    FUN_00421360((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429758);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_0042975c,local_49c.dwMinorVersion,-1);
    FUN_00421370((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429760);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_00429764,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_00421370((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429768);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_00421370((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_0042976c,local_4dc.dwTotalPhys >> 10,-1);
    FUN_00421360((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429770);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_00421360((uint *)local_404,(uint *)&DAT_00429774);
    FUN_00421370((uint *)local_404,(uint *)&local_4b4);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429778);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_0042977c,local_4a0,-1);
    FUN_00421370((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_00429780);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_004297a4,s_display_drv_00429798,s_Unknown_00429790,local_404,0x80,
               s_system_ini_00429784);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297b8,local_4a0,-1);
    FUN_00421360((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_004297bc);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297c0,local_4a0,-1);
    FUN_00421370((uint *)local_404,puVar1);
    FUN_00421370((uint *)local_404,(uint *)&DAT_004297c4);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297c8,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_00421370((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297cc,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_00421370((uint *)local_404,puVar1);
      FUN_00421370((uint *)local_404,(uint *)&DAT_004297d0);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297d8,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_00421370((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_004140e0((uint *)&DAT_004297d4,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_00421370((uint *)local_404,puVar1);
      }
      FUN_00421370((uint *)local_404,(uint *)&DAT_004297dc);
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


// ==== FUN_004067b5 @ 004067b5

UINT FUN_004067b5(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00405aed(DAT_00431834);
      }
      return 0;
    }
    FUN_004053d5(param_1);
    DAT_0043078c = param_1;
    DAT_00431834 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_004283b4 == 0);
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
      DAT_004283b4 = (uint)(LVar2 == 0);
      FUN_0040f14c();
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
      DAT_004283b4 = (uint)(LVar2 == 0);
      FUN_00402229();
      EndDialog(param_1,0);
      PostMessageA(DAT_00432088,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0043078c == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0043078c);
  SelectPalette(hdc,DAT_00432f3c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0043078c,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0043078c,(RECT *)0x0,0);
    InvalidateRect(DAT_00432088,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00406a2b @ 00406a2b

UINT FUN_00406a2b(HWND param_1,uint param_2,HWND param_3)

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
      FUN_004053d5(param_1);
      DAT_00431e24 = param_1;
      DAT_00430c34 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_004283b4 == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00405aed(DAT_00430c34);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00431e24 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00431e24);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_00431e24,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_00431e24,(RECT *)0x0,0);
        InvalidateRect(DAT_00432088,(RECT *)0x0,0);
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
        DAT_004283b4 = (uint)(LVar2 == 0);
        FUN_00402229();
        EndDialog(param_1,0);
        PostMessageA(DAT_00432088,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00406c5c @ 00406c5c

UINT FUN_00406c5c(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00405aed(DAT_00430794);
      }
      return 0;
    }
    FUN_004053d5(param_1);
    DAT_0043183c = param_1;
    DAT_00430794 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_004283b0 == 0);
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
      DAT_004283b0 = (uint)(LVar2 == 0);
      FUN_0040f14c();
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
      DAT_004283b0 = (uint)(LVar2 == 0);
      FUN_00402229();
      EndDialog(param_1,0);
      PostMessageA(DAT_00432088,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0043183c == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0043183c);
  SelectPalette(hdc,DAT_00432f3c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0043183c,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0043183c,(RECT *)0x0,0);
    InvalidateRect(DAT_00432088,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00406ed2 @ 00406ed2

UINT FUN_00406ed2(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_00405aed(DAT_00430a40);
      }
      return 0;
    }
    FUN_004053d5(param_1);
    DAT_0043185c = param_1;
    DAT_00430a40 = GetDlgItem(param_1,100);
    if (DAT_00429110 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_004283c0);
    _Size = 0x10;
    _Src = FUN_004140e0((uint *)&DAT_004297e0,DAT_0042882c,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_0043185c == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_0043185c);
    SelectPalette(hdc,DAT_00432f3c,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_0043185c,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_0043185c,(RECT *)0x0,0);
      InvalidateRect(DAT_00432088,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_004283c0,DAT_00429110 * 0x11);
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


// ==== FUN_0040721b @ 0040721b

UINT FUN_0040721b(HWND param_1,uint param_2,HWND param_3)

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
      FUN_004053d5(param_1);
      DAT_00431830 = param_1;
      DAT_00431858 = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00429218) && (DAT_00429218 < 10)) {
        SetDlgItemTextA(param_1,DAT_00429218 + 0x33,&DAT_004297e4);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_004140e0((uint *)&DAT_004297e8,*(int *)(&DAT_00430430 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00430408 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00405aed(DAT_00431858);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00431830) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00431830);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00431830,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00431830,(RECT *)0x0,0);
        InvalidateRect(DAT_00432088,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_00405646(DAT_00431830), IVar5 == 1)) {
        if ((-1 < DAT_00429218) && (DAT_00429218 < 10)) {
          SetDlgItemTextA(param_1,DAT_00429218 + 0x33,&DAT_004297ec);
        }
        DAT_00429218 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00430430 + local_14 * 0x2c) = 0;
          _memset(&DAT_00430408 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_004140e0((uint *)&DAT_004297f0,*(int *)(&DAT_00430430 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00430408 + local_14 * 0x2c);
        }
        FUN_0040f14c();
      }
    }
  }
  return 0;
}


// ==== FUN_004075a2 @ 004075a2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_004075a2(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_00432088,s_CHARMER_HLP_00428518,1,0x28);
    }
    else if (param_2 == 0xf) {
      FUN_00405aed(DAT_004317d8);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_0040774c:
      hdc = GetDC(DAT_004307f4);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_004307f4,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_004307f4,(RECT *)0x0,0);
      InvalidateRect(DAT_00432088,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_004053d5(param_1);
      DAT_004307f4 = param_1;
      DAT_004317d8 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00429960;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00429964;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_004283bc;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5e,0x60,DAT_004283ac + 0x5d);
      if (DAT_00429110 == 1) {
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
      _DAT_00431a54 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_004283c0);
      pCVar2 = FUN_004140e0((uint *)&DAT_004297f4,DAT_004283a8,-1);
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
        DAT_00429960 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_00429964 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_004283bc = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5e);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004283ac = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004283ac = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_004283ac = 3;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_004283c0,DAT_00429110 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
          pcVar3 = FUN_004140e0((uint *)&DAT_00429804,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00407b31:
            DAT_004283a8 = local_28;
            break;
          }
          pcVar3 = FUN_004140e0((uint *)&DAT_00429808,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00407b31;
        }
      case 2:
        DAT_004307f4 = (HWND)0x0;
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_004283a8;
          for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
            pcVar3 = FUN_004140e0((uint *)&DAT_004297f8,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_0040789f:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_004140e0((uint *)&DAT_004297fc,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_0040789f;
          }
          pCVar2 = FUN_004140e0((uint *)&DAT_00429800,local_1c,-1);
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
        WinHelpA(DAT_00432088,s_CHARMER_HLP_00428518,1,0x28);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_004307f4 == param_3) {
      return 0;
    }
    goto LAB_0040774c;
  }
  return 0;
}


// ==== FUN_00407c7d @ 00407c7d

UINT FUN_00407c7d(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004053d5(param_1);
      DAT_00432034 = param_1;
      DAT_004317d4 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_004059ee(DAT_004317d4);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00432034) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00432034);
      SelectPalette(hdc,DAT_00432f3c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00432034,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00431830,(RECT *)0x0,0);
        InvalidateRect(DAT_00432034,(RECT *)0x0,0);
        InvalidateRect(DAT_00432088,(RECT *)0x0,0);
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


// ==== FUN_00407e2d @ 00407e2d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407e2d(void)

{
  _DAT_00430a3c = GetTickCount();
  return;
}


// ==== FUN_00407e48 @ 00407e48

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00407e48(int param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  iVar1 = ((iVar1 + _DAT_00430a3c) % 0x7fff) * param_1;
  return (int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf;
}


// ==== FUN_00407e84 @ 00407e84

void FUN_00407e84(void)

{
  return;
}


// ==== FUN_00407e94 @ 00407e94

void FUN_00407e94(void)

{
  return;
}


// ==== FUN_00407ec7 @ 00407ec7

void FUN_00407ec7(void)

{
  return;
}


// ==== FUN_00407ee6 @ 00407ee6

void __cdecl FUN_00407ee6(int param_1)

{
  LPVOID pvVar1;
  int local_c;
  int local_8;
  
  if (param_1 == 1) {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 4; local_c = local_c + 1) {
        *(undefined **)(&DAT_00431d10 + local_c * 0xc + local_8 * 0x30) =
             (&PTR_s_snake00_00428830)[local_8 * 4 + local_c];
        if (*(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) == 0) {
          if ((*(int *)(&DAT_00431d10 + local_c * 0xc + local_8 * 0x30) != 0) &&
             ((*(int *)(&DAT_00431d08 + local_c * 0xc + local_8 * 0x30) == 0 ||
              (*(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) == 0)))) {
            pvVar1 = FUN_004145d6(*(LPCSTR *)(&DAT_00431d10 + local_c * 0xc + local_8 * 0x30));
            *(LPVOID *)(&DAT_00431d08 + local_c * 0xc + local_8 * 0x30) = pvVar1;
            if (*(int *)(&DAT_00431d08 + local_c * 0xc + local_8 * 0x30) != 0) {
              *(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) =
                   *(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) + 1;
            }
          }
        }
        else {
          *(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) =
               *(int *)(&DAT_00431d0c + local_c * 0xc + local_8 * 0x30) + 1;
        }
      }
    }
  }
  else {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      }
    }
  }
  return;
}


// ==== FUN_004080e2 @ 004080e2

void __cdecl FUN_004080e2(int *param_1)

{
  FUN_004159d5(&DAT_00432f20,0,1,0,1,600,400,param_1,-1);
  return;
}


// ==== FUN_0040811c @ 0040811c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040811c(void *this,int param_1,undefined4 param_2)

{
  if (param_1 == 4) {
    *(undefined4 *)((int)this + 4) = 4;
    *(undefined4 *)((int)this + 8) = param_2;
    *(undefined4 *)((int)this + 0xc) = 1;
    *(int *)((int)this + 0x10) =
         (*(int *)(&DAT_00430c88 + *(int *)((int)this + 8) * 0x1a8) * 5 + 5) * -5 + 0x16e;
  }
  else if (param_1 == 5) {
    DAT_00431f4c = 5;
    _DAT_00431f50 = param_2;
  }
  return;
}


// ==== FUN_004081c2 @ 004081c2

void FUN_004081c2(HWND param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  HDC hdc;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int y;
  int x;
  int local_10;
  
  iVar7 = FUN_00407e48(2);
  if (iVar7 == 0) {
    FUN_0041ad4a(&DAT_00430be0,0x20b,0x1e,1);
  }
  else if (((DAT_00431f80 == 0) && (DAT_00431f84 == 0)) && (DAT_00431f88 == 0)) {
    FUN_0041ad4a(&DAT_00430b40,0x20b,0x1e,1);
  }
  else {
    FUN_0041ad4a(&DAT_00430b90,0x20b,0x1e,1);
  }
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00432f3c,0);
  RealizePalette(hdc);
  if (DAT_004334ac != 0) {
    bVar6 = false;
    if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        iVar7 = *(int *)(&DAT_00433378 + local_10 * 0x10);
        iVar1 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_00433374 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_004334d0);
        BitBlt(hdc,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_004334ac = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_10 * 0x10)) &&
           (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_10 * 0x10))) {
          bVar6 = true;
          break;
        }
      }
      if (bVar6) {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_00433370 + local_10 * 0x10) - DAT_004334c8;
          x = *(int *)(&DAT_0043336c + local_10 * 0x10) - DAT_004334c4;
          iVar7 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar1 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,x,y,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          iVar7 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar1 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_004334ac = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_00408670 @ 00408670

void FUN_00408670(HWND param_1,int param_2)

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
  
  if (param_2 == 1) {
    FUN_0041ad4a(&DAT_00430a48,0x225,0x12d,1);
  }
  else {
    FUN_0041ad4a(&DAT_00430a98,0x225,0x12d,1);
  }
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00432f3c,0);
  RealizePalette(hdc);
  if (DAT_004334ac != 0) {
    bVar7 = false;
    if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_004334d0);
        BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_004334ac = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_10 * 0x10)) &&
           (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_10 * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_00433370 + local_10 * 0x10) - DAT_004334c8;
          x = *(int *)(&DAT_0043336c + local_10 * 0x10) - DAT_004334c4;
          iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_004334ac = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_00408add @ 00408add

void __thiscall FUN_00408add(void *this,int param_1)

{
  int iVar1;
  int local_20;
  int local_18 [3];
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  do {
    if (2 < local_8) {
      return;
    }
    iVar1 = *(int *)((int)this + 0x14) / 3;
    if (iVar1 < local_8) {
      local_20 = 3;
LAB_00408ba7:
      local_18[0] = local_20 * 0x30;
      local_18[2] = local_18[0] + 0x2f;
      local_18[1] = 0;
      local_c = 0x31;
      FUN_0041bc42(&DAT_00431dc8,0xf,local_8 * 0x50 + 0x22,local_18,1);
    }
    else {
      if (iVar1 <= local_8) {
        local_20 = 3 - *(int *)((int)this + 0x14) % 3;
        goto LAB_00408ba7;
      }
      if (param_1 != 0) {
        local_18[0] = 0;
        local_18[2] = 0x2f;
        local_18[1] = 0;
        local_c = 0x31;
        FUN_0041bc42(&DAT_00431dc8,0xf,local_8 * 0x50 + 0x22,local_18,1);
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_00408bfa @ 00408bfa

void __thiscall FUN_00408bfa(void *this,HWND param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  HDC hdc;
  HDC pHVar9;
  HGDIOBJ pvVar10;
  int y;
  int x;
  int local_28;
  int local_1c;
  int local_14 [3];
  undefined4 local_8;
  
  local_1c = 0;
  while( true ) {
    if (2 < local_1c) {
      return;
    }
    if (*(int *)((int)this + local_1c * 4 + 0x38) != 0) break;
    local_1c = local_1c + 1;
  }
  if (*(int *)((int)this + local_1c * 4 + 0x44) == 0) {
    local_14[0] = 0x30;
    local_14[2] = 0x5f;
    local_14[1] = 0;
    local_8 = 0x31;
    FUN_0041bc42(&DAT_00431dc8,0xf,local_1c * 0x50 + 0x22,local_14,1);
    if (*(int *)((int)this + local_1c * 4 + 0x50) != -1) {
      local_14[0] = *(int *)((int)this + local_1c * 4 + 0x50) * 0x30;
      local_14[2] = local_14[0] + 0x2f;
      local_14[1] = 0x32;
      local_8 = 99;
      FUN_0041bc42(&DAT_00431dc8,0xf,local_1c * 0x50 + 0x22,local_14,1);
    }
    piVar1 = (int *)((int)this + local_1c * 4 + 0x50);
    *piVar1 = *piVar1 + -1;
    if (*(int *)((int)this + local_1c * 4 + 0x50) == -2) {
      *(undefined4 *)((int)this + local_1c * 4 + 0x38) = 0;
    }
  }
  else {
    if (*(int *)((int)this + local_1c * 4 + 0x50) == 0) {
      FUN_00414ba3(0xf,0);
    }
    local_14[0] = *(int *)((int)this + local_1c * 4 + 0x50) * 0x30;
    local_14[2] = local_14[0] + 0x2f;
    local_14[1] = 0x32;
    local_8 = 99;
    FUN_0041bc42(&DAT_00431dc8,0xf,local_1c * 0x50 + 0x22,local_14,1);
    piVar1 = (int *)((int)this + local_1c * 4 + 0x50);
    *piVar1 = *piVar1 + 1;
    if (*(int *)((int)this + local_1c * 4 + 0x50) == 3) {
      *(undefined4 *)((int)this + local_1c * 4 + 0x38) = 0;
    }
  }
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00432f3c,0);
  RealizePalette(hdc);
  if (DAT_004334ac != 0) {
    bVar8 = false;
    if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
      for (local_28 = 0; local_28 < DAT_004334ac; local_28 = local_28 + 1) {
        iVar2 = *(int *)(&DAT_00433378 + local_28 * 0x10);
        iVar3 = *(int *)(&DAT_00433370 + local_28 * 0x10);
        iVar4 = *(int *)(&DAT_00433374 + local_28 * 0x10);
        iVar5 = *(int *)(&DAT_0043336c + local_28 * 0x10);
        iVar6 = *(int *)(&DAT_00433370 + local_28 * 0x10);
        iVar7 = *(int *)(&DAT_0043336c + local_28 * 0x10);
        pHVar9 = CreateCompatibleDC(hdc);
        pvVar10 = SelectObject(pHVar9,DAT_004334d0);
        BitBlt(hdc,iVar7,iVar6,(iVar4 - iVar5) + 1,(iVar2 - iVar3) + 1,pHVar9,iVar7,iVar6,0xcc0020);
        SelectObject(pHVar9,pvVar10);
        DeleteDC(pHVar9);
        GdiFlush();
      }
      DAT_004334ac = 0;
    }
    else {
      for (local_28 = 0; local_28 < DAT_004334ac; local_28 = local_28 + 1) {
        if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_28 * 0x10)) &&
           (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_28 * 0x10))) {
          bVar8 = true;
          break;
        }
      }
      if (bVar8) {
        for (local_28 = 0; local_28 < DAT_004334ac; local_28 = local_28 + 1) {
          y = *(int *)(&DAT_00433370 + local_28 * 0x10) - DAT_004334c8;
          x = *(int *)(&DAT_0043336c + local_28 * 0x10) - DAT_004334c4;
          iVar2 = *(int *)(&DAT_00433378 + local_28 * 0x10);
          iVar3 = *(int *)(&DAT_00433370 + local_28 * 0x10);
          iVar4 = *(int *)(&DAT_00433374 + local_28 * 0x10);
          iVar5 = *(int *)(&DAT_0043336c + local_28 * 0x10);
          iVar6 = *(int *)(&DAT_00433370 + local_28 * 0x10);
          iVar7 = *(int *)(&DAT_0043336c + local_28 * 0x10);
          pHVar9 = CreateCompatibleDC(hdc);
          pvVar10 = SelectObject(pHVar9,DAT_004334d0);
          BitBlt(hdc,x,y,(iVar4 - iVar5) + 1,(iVar2 - iVar3) + 1,pHVar9,iVar7,iVar6,0xcc0020);
          SelectObject(pHVar9,pvVar10);
          DeleteDC(pHVar9);
          GdiFlush();
        }
      }
      else {
        for (local_28 = 0; local_28 < DAT_004334ac; local_28 = local_28 + 1) {
          iVar2 = *(int *)(&DAT_00433378 + local_28 * 0x10);
          iVar3 = *(int *)(&DAT_00433370 + local_28 * 0x10);
          iVar4 = *(int *)(&DAT_00433374 + local_28 * 0x10);
          iVar5 = *(int *)(&DAT_0043336c + local_28 * 0x10);
          iVar6 = *(int *)(&DAT_00433370 + local_28 * 0x10);
          iVar7 = *(int *)(&DAT_0043336c + local_28 * 0x10);
          pHVar9 = CreateCompatibleDC(hdc);
          pvVar10 = SelectObject(pHVar9,DAT_004334d0);
          BitBlt(hdc,iVar7,iVar6,(iVar4 - iVar5) + 1,(iVar2 - iVar3) + 1,pHVar9,iVar7,iVar6,0xcc0020
                );
          SelectObject(pHVar9,pvVar10);
          DeleteDC(pHVar9);
          GdiFlush();
        }
      }
      DAT_004334ac = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  if ((*(int *)((int)this + 4) == 6) && (*(int *)((int)this + 0x40) == 0)) {
    SendMessageA(param_1,0x300,0,0);
  }
  return;
}


// ==== FUN_00409226 @ 00409226

void __thiscall FUN_00409226(void *this,HWND param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  HDC hdc;
  int iVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  int y;
  int x;
  int local_24;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  if (*(int *)((int)this + 0xc) < 1) {
    hdc = GetDC(param_1);
    SelectPalette(hdc,DAT_00432f3c,0);
    RealizePalette(hdc);
    *(undefined4 *)((int)this + 0xc) = 1;
    FUN_0041cae9((void *)((int)this + 0x18),1,0,-0x8000,-0x8000);
    if ((DAT_00431fc0 * 5 + 5) * -5 + 0x16e < *(int *)((int)this + 0x10)) {
      local_14[1] = 0;
      local_8 = 0x18;
      local_14[0] = 200;
      local_14[2] = 0xf9;
      FUN_0041c7d8((void *)((int)this + 0x18),
                   *(int *)(&DAT_00430c40 + *(int *)((int)this + 8) * 0x1a8),
                   *(int *)((int)this + 0x10),
                   *(int *)(&DAT_00430c40 + *(int *)((int)this + 8) * 0x1a8) + 0x31,
                   *(int *)((int)this + 0x10) + 0x18,0);
      FUN_0041bc42(&DAT_004307a0,*(int *)(&DAT_00430c40 + *(int *)((int)this + 8) * 0x1a8),
                   *(int *)((int)this + 0x10),local_14,1);
    }
    else {
      *(undefined4 *)((int)this + 0x24) = 0;
      if (*(int *)this == 0) {
        FUN_0040ce75((int)(&DAT_00430c38 + *(int *)((int)this + 8) * 0x1a8));
      }
      else {
        FUN_0041cae9(&DAT_00430dc8 + *(int *)((int)this + 8) * 0x1a8,1,0,-0x8000,-0x8000);
        FUN_0040cd06(&DAT_00430c38 + *(int *)((int)this + 8) * 0x1a8);
        FUN_0040cf6d((int)(&DAT_00430c38 + *(int *)((int)this + 8) * 0x1a8));
      }
      *(int *)(&DAT_00430ddc + *(int *)((int)this + 8) * 0x1a8) = DAT_00431fb8 + -9;
      FUN_0040c74e((int)(&DAT_00430c38 + *(int *)((int)this + 8) * 0x1a8));
      *(undefined4 *)(&DAT_00430dc4 + *(int *)((int)this + 8) * 0x1a8) = 1;
      *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
      FUN_00414ba3(6,0);
      if (*(int *)((int)this + 0x14) % 3 == 0) {
        iVar7 = (*(int *)((int)this + 0x14) + -1) / 3;
        if (*(int *)((int)this + iVar7 * 4 + 0x38) == 0) {
          *(undefined4 *)((int)this + iVar7 * 4 + 0x50) = 0;
        }
        *(undefined4 *)((int)this + iVar7 * 4 + 0x44) = 1;
        *(undefined4 *)((int)this + iVar7 * 4 + 0x38) = 1;
      }
      if ((*(int *)((int)this + 0x14) == 9) ||
         (*(int *)(&DAT_00430c88 + *(int *)((int)this + 8) * 0x1a8) == DAT_00431fc0)) {
        *(undefined4 *)((int)this + 0x5c) = 0;
        if (*(int *)((int)this + 0x14) != 9) {
          for (local_18 = (*(int *)((int)this + 0x14) + -1) / 3; local_18 < 3;
              local_18 = local_18 + 1) {
            *(undefined4 *)((int)this + local_18 * 4 + 0x38) = 1;
            *(undefined4 *)((int)this + local_18 * 4 + 0x50) = 0;
            *(undefined4 *)((int)this + local_18 * 4 + 0x44) = 1;
          }
        }
        *(undefined4 *)((int)this + 4) = 6;
      }
      else {
        FUN_00408add(this,0);
        *(undefined4 *)((int)this + 4) = 3;
      }
    }
    if (DAT_004334ac != 0) {
      bVar6 = false;
      if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
        for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
          iVar7 = *(int *)(&DAT_00433378 + local_24 * 0x10);
          iVar1 = *(int *)(&DAT_00433370 + local_24 * 0x10);
          iVar2 = *(int *)(&DAT_00433374 + local_24 * 0x10);
          iVar3 = *(int *)(&DAT_0043336c + local_24 * 0x10);
          iVar4 = *(int *)(&DAT_00433370 + local_24 * 0x10);
          iVar5 = *(int *)(&DAT_0043336c + local_24 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_004334ac = 0;
      }
      else {
        for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
          if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_24 * 0x10)) &&
             (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_24 * 0x10))) {
            bVar6 = true;
            break;
          }
        }
        if (bVar6) {
          for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
            y = *(int *)(&DAT_00433370 + local_24 * 0x10) - DAT_004334c8;
            x = *(int *)(&DAT_0043336c + local_24 * 0x10) - DAT_004334c4;
            iVar7 = *(int *)(&DAT_00433378 + local_24 * 0x10);
            iVar1 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar2 = *(int *)(&DAT_00433374 + local_24 * 0x10);
            iVar3 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            iVar4 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar5 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            pHVar8 = CreateCompatibleDC(hdc);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(hdc,x,y,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
            iVar7 = *(int *)(&DAT_00433378 + local_24 * 0x10);
            iVar1 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar2 = *(int *)(&DAT_00433374 + local_24 * 0x10);
            iVar3 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            iVar4 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar5 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            pHVar8 = CreateCompatibleDC(hdc);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(hdc,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar7 - iVar1) + 1,pHVar8,iVar5,iVar4,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_004334ac = 0;
      }
    }
    ReleaseDC(param_1,hdc);
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -2;
  }
  return;
}


// ==== FUN_0040998e @ 0040998e

void FUN_0040998e(void)

{
  SendMessageA(DAT_00431864,0x111,0x77,0);
  return;
}


// ==== FUN_0040ae15 @ 0040ae15

void FUN_0040ae15(void)

{
  undefined4 uVar1;
  uint *puVar2;
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
  HDC local_14;
  int local_10;
  int local_c;
  int local_8;
  
  DAT_00431f4c = 3;
  FUN_00407ee6(0);
  local_14 = GetDC(DAT_00431864);
  SelectPalette(local_14,DAT_00432f3c,0);
  RealizePalette(local_14);
  FUN_004080e2(DAT_00431fb0);
  FUN_0040d0a5(&DAT_00431fb8);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    FUN_00408add(&DAT_00431f48,1);
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00430c3c + local_c * 0x1a8) = 0;
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00430c74 + local_c * 0x1a8) = 0;
    *(undefined4 *)(&DAT_00430c84 + local_c * 0x1a8) = 0;
    for (local_10 = 0; local_10 < *(int *)(&DAT_00430c88 + local_c * 0x1a8); local_10 = local_10 + 1
        ) {
      *(undefined4 *)(&DAT_00430ca0 + local_10 * 0x18 + local_c * 0x1a8) = 0;
    }
    *(undefined4 *)(&DAT_00430dd4 + local_c * 0x1a8) = 0;
    if (((DAT_00431f78 + 1) / 2 <= local_c) && (local_c < 7 - (DAT_00431f78 + 1) / 2)) {
      *(undefined4 *)(&DAT_00430c88 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430c58 + local_c * 0x1a8) = 5;
      *(undefined4 *)(&DAT_00430c5c + local_c * 0x1a8) = 0x14f;
      *(undefined4 *)(&DAT_00430c60 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430c88 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430dc4 + local_c * 0x1a8) = 1;
    }
    if (((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) && (7 - (DAT_00431f78 + 1) / 2 == local_c)) {
      *(undefined4 *)(&DAT_00430c88 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430c58 + local_c * 0x1a8) = 5;
      *(undefined4 *)(&DAT_00430c5c + local_c * 0x1a8) = 0x14f;
      *(undefined4 *)(&DAT_00430c60 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430c88 + local_c * 0x1a8) = 0;
      *(undefined4 *)(&DAT_00430dc4 + local_c * 0x1a8) = 1;
    }
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    *(undefined4 *)(&DAT_00430c88 + local_c * 0x1a8) = 0;
  }
  if (DAT_00431f48 == 0) {
    local_8 = 1;
  }
  else {
    local_8 = DAT_00431fc0 + -3;
  }
  while( true ) {
    local_18 = local_8;
    if (local_8 == 0) break;
    local_8 = local_8 + -1;
    for (local_c = (DAT_00431f78 + 1) / 2; local_c < 7 - (DAT_00431f78 + 1) / 2;
        local_c = local_c + 1) {
      FUN_0040cd06(&DAT_00430c38 + local_c * 0x1a8);
      FUN_0040cf6d((int)(&DAT_00430c38 + local_c * 0x1a8));
    }
    if ((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) {
      local_c = 7 - (DAT_00431f78 + 1) / 2;
      FUN_0040cd06(&DAT_00430c38 + local_c * 0x1a8);
      FUN_0040cf6d((int)(&DAT_00430c38 + local_c * 0x1a8));
    }
  }
  local_8 = local_8 + -1;
  uVar1 = FUN_0040ddf2(*(int *)(&DAT_00430c50 + DAT_00431a5c * 0x1a8));
  *(undefined4 *)(&DAT_00430c48 + DAT_00431a5c * 0x1a8) = uVar1;
  *(undefined4 *)(&DAT_00430c58 + DAT_00431a5c * 0x1a8) = 0;
  puVar2 = (uint *)FUN_004140e0((uint *)&DAT_0042980c,DAT_0042882c,5);
  FUN_00421360((uint *)&DAT_00431e80,puVar2);
  if (DAT_00432018 != (void *)0x0) {
    FUN_0041cae9(&DAT_00432024,0,0,-0x8000,-0x8000);
    FUN_0041e473(DAT_00432018,DAT_0043201c,DAT_00432020,0x431e80,&local_68);
    FUN_0041c7d8(&DAT_00432024,local_68,local_64,local_60,local_5c,0);
    FUN_0041d8e1(DAT_00432018,DAT_0043201c,DAT_00432020,0x431e80,1);
  }
  FUN_0040d265(&DAT_00431a58,(HWND)0x0);
  if (DAT_004334ac != 0) {
    local_1c = 0;
    if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
      for (local_20 = 0; local_20 < DAT_004334ac; local_20 = local_20 + 1) {
        local_24 = (*(int *)(&DAT_00433378 + local_20 * 0x10) -
                   *(int *)(&DAT_00433370 + local_20 * 0x10)) + 1;
        local_28 = (*(int *)(&DAT_00433374 + local_20 * 0x10) -
                   *(int *)(&DAT_0043336c + local_20 * 0x10)) + 1;
        local_2c = *(int *)(&DAT_00433370 + local_20 * 0x10);
        local_30 = *(int *)(&DAT_0043336c + local_20 * 0x10);
        FUN_00413410(local_14,local_30,local_2c,local_28,local_24,DAT_00432f20,local_30,local_2c);
      }
      DAT_004334ac = 0;
    }
    else {
      for (local_20 = 0; local_20 < DAT_004334ac; local_20 = local_20 + 1) {
        if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_20 * 0x10)) &&
           (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_20 * 0x10))) {
          local_1c = 1;
          break;
        }
      }
      if (local_1c == 0) {
        for (local_20 = 0; local_20 < DAT_004334ac; local_20 = local_20 + 1) {
          local_34 = (*(int *)(&DAT_00433378 + local_20 * 0x10) -
                     *(int *)(&DAT_00433370 + local_20 * 0x10)) + 1;
          local_38 = (*(int *)(&DAT_00433374 + local_20 * 0x10) -
                     *(int *)(&DAT_0043336c + local_20 * 0x10)) + 1;
          local_3c = *(int *)(&DAT_00433370 + local_20 * 0x10);
          local_40 = *(int *)(&DAT_0043336c + local_20 * 0x10);
          FUN_00413410(local_14,local_40,local_3c,local_38,local_34,DAT_00432f20,local_40,local_3c);
        }
      }
      else {
        for (local_20 = 0; local_20 < DAT_004334ac; local_20 = local_20 + 1) {
          local_54 = *(int *)(&DAT_00433370 + local_20 * 0x10) - DAT_004334c8;
          local_58 = *(int *)(&DAT_0043336c + local_20 * 0x10) - DAT_004334c4;
          local_44 = (*(int *)(&DAT_00433378 + local_20 * 0x10) -
                     *(int *)(&DAT_00433370 + local_20 * 0x10)) + 1;
          local_48 = (*(int *)(&DAT_00433374 + local_20 * 0x10) -
                     *(int *)(&DAT_0043336c + local_20 * 0x10)) + 1;
          local_4c = *(int *)(&DAT_00433370 + local_20 * 0x10);
          local_50 = *(int *)(&DAT_0043336c + local_20 * 0x10);
          FUN_00413410(local_14,local_58,local_54,local_48,local_44,DAT_00432f20,local_50,local_4c);
        }
      }
      DAT_004334ac = 0;
    }
  }
  ReleaseDC(DAT_00431864,local_14);
  DAT_00431b10 = 0;
  return;
}


// ==== FUN_0040b6b8 @ 0040b6b8

void __fastcall FUN_0040b6b8(void *param_1)

{
  int local_78;
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
  
  FUN_0041cae9((void *)((int)param_1 + 0x30),1,0,-0x8000,-0x8000);
  FUN_0041cae9((void *)((int)param_1 + 0x40),1,0,-0x8000,-0x8000);
  local_34 = (*(int *)((int)param_1 + 0x50) * -0x19 + 0x16e) - *(int *)((int)param_1 + 0x24);
  if (0 < local_34) {
    FUN_0040ba50(param_1,&local_20,&local_1c,&local_54,&local_3c,&local_24);
    FUN_0040ba14(param_1,&local_28,&local_8);
    local_30 = local_34 / local_3c;
    local_2c = local_34 % local_3c;
    if (local_30 < 1) {
      *(undefined4 *)((int)param_1 + 0x28) = 1;
      *(undefined4 *)((int)param_1 + 0x2c) = 1;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x2c) = 0;
    }
    local_38 = *(int *)((int)param_1 + 8);
    local_40 = *(int *)((int)param_1 + 0x24);
    FUN_0040ba50(param_1,&local_20,&local_1c,&local_54,&local_3c,&local_24);
    local_50 = FUN_0040bbeb(param_1,1,0);
    local_18 = FUN_0040bbeb(param_1,0,0);
    local_48 = local_50 + local_20 + -1;
    local_10 = local_18 + local_54 + -1;
    local_4c = FUN_0040bbeb(param_1,1,1);
    local_14 = FUN_0040bbeb(param_1,0,1);
    if (local_30 < 1) {
      local_78 = local_2c;
    }
    else {
      local_78 = local_3c;
    }
    local_c = local_14 + local_78 + -1;
    if (local_c < local_14) {
      *(undefined4 *)((int)param_1 + 0x3c) = 0;
    }
    else {
      if (local_28 < local_c - local_14) {
        local_8 = 0;
      }
      FUN_0041c7d8((void *)((int)param_1 + 0x30),local_8 + local_24 + local_38,local_40,
                   local_8 + local_24 + local_54 + local_38 + -1,(local_c + local_40) - local_14,0);
      FUN_00416dd7(&DAT_00432f20,local_8 + local_24 + local_38,local_40,&local_18,
                   *(short **)
                    (&DAT_00431d08 +
                    *(int *)((int)param_1 + 0x1c) * 0xc + *(int *)((int)param_1 + 0x18) * 0x30),0);
    }
    if (0 < local_30) {
      local_44 = (local_30 + -1) * local_3c + local_4c + local_2c + -1;
      if (local_44 < local_4c) {
        *(undefined4 *)((int)param_1 + 0x4c) = 0;
      }
      else {
        FUN_0041c7d8((void *)((int)param_1 + 0x40),local_1c + local_38,local_3c + local_40,
                     local_1c + local_20 + local_38 + -1,(local_44 + local_3c + local_40) - local_4c
                     ,0);
        FUN_00416dd7(&DAT_00432f20,local_1c + local_38,local_3c + local_40,&local_50,
                     *(short **)
                      (&DAT_00431d08 +
                      *(int *)((int)param_1 + 0x1c) * 0xc + *(int *)((int)param_1 + 0x18) * 0x30),0)
        ;
      }
    }
  }
  return;
}


// ==== FUN_0040ba14 @ 0040ba14

void __thiscall FUN_0040ba14(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *(undefined4 *)(&DAT_00428870 + *(int *)((int)this + 0x18) * 8);
  *param_2 = *(undefined4 *)(&DAT_00428874 + *(int *)((int)this + 0x18) * 8);
  return;
}


// ==== FUN_0040ba50 @ 0040ba50

void __thiscall
FUN_0040ba50(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
            undefined4 *param_4,undefined4 *param_5)

{
  if (*(int *)((int)this + 0x20) == 2) {
    *param_1 = *(undefined4 *)
                (&DAT_004288b8 +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_3 = *(undefined4 *)
                (&DAT_004288c8 +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_2 = *(undefined4 *)
                (&DAT_004288bc +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_5 = *(undefined4 *)
                (&DAT_004288cc +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
  }
  else {
    *param_1 = *(undefined4 *)
                (&DAT_00428898 +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_3 = *(undefined4 *)
                (&DAT_004288a8 +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_2 = *(undefined4 *)
                (&DAT_0042889c +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    *param_5 = *(undefined4 *)
                (&DAT_004288ac +
                *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
  }
  *param_4 = *(undefined4 *)
              (&DAT_004288d0 +
              *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
  return;
}


// ==== FUN_0040bbeb @ 0040bbeb

undefined4 __thiscall FUN_0040bbeb(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)((int)this + 0x20) == 2) {
    if (param_1 == 0) {
      if (param_2 == 0) {
        uVar1 = *(undefined4 *)
                 (&DAT_004288c0 +
                 *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
      }
      else {
        uVar1 = *(undefined4 *)
                 (&DAT_004288c4 +
                 *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
      }
    }
    else if (param_2 == 0) {
      uVar1 = *(undefined4 *)
               (&DAT_004288b0 +
               *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    }
    else {
      uVar1 = *(undefined4 *)
               (&DAT_004288b4 +
               *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    }
  }
  else if (param_1 == 0) {
    if (param_2 == 0) {
      uVar1 = *(undefined4 *)
               (&DAT_004288a0 +
               *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    }
    else {
      uVar1 = *(undefined4 *)
               (&DAT_004288a4 +
               *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220);
    }
  }
  else if (param_2 == 0) {
    uVar1 = *(undefined4 *)
             (&DAT_00428890 + *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220
             );
  }
  else {
    uVar1 = *(undefined4 *)
             (&DAT_00428894 + *(int *)((int)this + 0x28) * 0x44 + *(int *)((int)this + 0x18) * 0x220
             );
  }
  return uVar1;
}


// ==== FUN_0040bdb2 @ 0040bdb2

undefined4 FUN_0040bdb2(void)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (6 < local_8) {
      return 1;
    }
    if ((*(int *)(&DAT_00430c3c + local_8 * 0x1a8) != 0) &&
       (*(int *)(&DAT_00430c88 + local_8 * 0x1a8) != 1)) break;
    local_8 = local_8 + 1;
  }
  return 0;
}


// ==== FUN_0040be2c @ 0040be2c

int FUN_0040be2c(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_c = 100;
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    iVar1 = local_c;
    if ((*(int *)(&DAT_00430c3c + local_8 * 0x1a8) != 0) &&
       (iVar1 = *(int *)(&DAT_00430c88 + local_8 * 0x1a8),
       local_c <= *(int *)(&DAT_00430c88 + local_8 * 0x1a8))) {
      iVar1 = local_c;
    }
    local_c = iVar1;
  }
  return local_c + -1;
}


// ==== FUN_0040beae @ 0040beae

void __thiscall FUN_0040beae(void *this,int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  
  if ((*(int *)((int)this + 0x20) == 1) && (*(int *)((int)this + 0x24) <= DAT_00431fb8)) {
    DAT_0042882c = DAT_0042882c + (5 - DAT_00431f78) * DAT_00428508 * 10;
    if ((DAT_00431b10 != 0) && (0 < DAT_00431f5c)) {
      DAT_00431f5c = DAT_00431f5c + -1;
      FUN_00414ba3(7,0);
      if ((DAT_00431f80 == 0) && ((DAT_00431f84 == 0 && (DAT_00431f88 == 0)))) {
        local_24 = 3 - DAT_00431f5c % 3;
        local_1c = DAT_00431f5c / 3;
        if (local_24 == 1) {
          (&DAT_00431f80)[local_1c] = 1;
          (&DAT_00431f8c)[local_1c] = 0;
          *(undefined4 *)(&DAT_00431f98 + local_1c * 4) = 2;
        }
        else {
          local_14[0] = local_24 * 0x30;
          local_14[2] = local_14[0] + 0x2f;
          local_14[1] = 0;
          local_8 = 0x31;
          FUN_0041bc42(&DAT_00431dc8,0xf,local_1c * 0x50 + 0x22,local_14,1);
        }
      }
      else {
        for (local_20 = 0; local_20 < 3; local_20 = local_20 + 1) {
          if ((&DAT_00431f80)[local_20] != 0) {
            (&DAT_00431f8c)[local_20] = 0;
            break;
          }
        }
      }
    }
    puVar1 = (uint *)FUN_004140e0((uint *)&DAT_00429810,DAT_0042882c,5);
    FUN_00421360((uint *)&DAT_00431e80,puVar1);
    if (DAT_00432018 != (void *)0x0) {
      FUN_0041cae9(&DAT_00432024,0,0,-0x8000,-0x8000);
      FUN_0041e473(DAT_00432018,DAT_0043201c,DAT_00432020,0x431e80,&local_34);
      FUN_0041c7d8(&DAT_00432024,local_34,local_30,local_2c,local_28,0);
      FUN_0041d8e1(DAT_00432018,DAT_0043201c,DAT_00432020,0x431e80,1);
    }
    FUN_00414ba3(0xb,0);
    *(undefined4 *)((int)this + 0x20) = 4;
    uVar2 = FUN_0040deb2(*(int *)((int)this + 0x18));
    *(undefined4 *)((int)this + 0x10) = uVar2;
  }
  else {
    local_18 = 0;
    if ((*(int *)((int)this + 0x20) == 4) &&
       (*(int *)((int)this + 0x50) * -0x19 + 0x16e <= *(int *)((int)this + 0x24))) {
      if (DAT_00431f48 == 0) {
        FUN_0040cd06(this);
        FUN_0040cf6d((int)this);
      }
      else {
        FUN_0040ce75((int)this);
        local_18 = FUN_0040bdb2();
        FUN_0040c74e((int)this);
      }
      *(undefined4 *)((int)this + 0x3c) = 0;
      *(undefined4 *)((int)this + 0x4c) = 0;
      if ((*(int *)((int)this + 0x50) == DAT_00431fc0) || (local_18 == 1)) {
        FUN_0040811c(&DAT_00431f48,5,param_1);
      }
      if (DAT_00431a5c == param_1) {
        *(int *)((int)this + 0x24) = *(int *)((int)this + 0x50) * -0x19 + 0x16f;
        *(undefined4 *)((int)this + 0x20) = 0;
        uVar2 = FUN_0040ddf2(*(int *)((int)this + 0x18));
        *(undefined4 *)((int)this + 0x10) = uVar2;
      }
      else {
        *(int *)((int)this + 0x24) = *(int *)((int)this + 0x50) * -0x19 + 0x16f;
        *(undefined4 *)((int)this + 0x20) = 5;
      }
    }
    else if ((*(int *)((int)this + 0x20) == 3) &&
            (*(int *)((int)this + 0x50) * -0x19 + 0x16e <= *(int *)((int)this + 0x24))) {
      if (DAT_00431a5c == param_1) {
        *(int *)((int)this + 0x24) = *(int *)((int)this + 0x50) * -0x19 + 0x16f;
        *(undefined4 *)((int)this + 0x20) = 0;
        uVar2 = FUN_0040ddf2(*(int *)((int)this + 0x18));
        *(undefined4 *)((int)this + 0x10) = uVar2;
      }
      else {
        *(int *)((int)this + 0x24) = *(int *)((int)this + 0x50) * -0x19 + 0x16f;
        *(undefined4 *)((int)this + 0x20) = 5;
      }
    }
  }
  return;
}


// ==== FUN_0040c2fc @ 0040c2fc

void __fastcall FUN_0040c2fc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == 1) {
    uVar2 = *(int *)(param_1 + 0x24) - DAT_00431fb8;
    if (uVar2 < *(uint *)(param_1 + 0x14)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - uVar2;
    }
    else {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x14);
    }
    if (*(int *)(param_1 + 0x24) <= *(int *)(param_1 + 0x1a4) + 9) {
      *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x24) + -9;
    }
  }
  else if (iVar1 == 3) {
    uVar2 = (*(int *)(param_1 + 0x50) * -0x19 + 0x16e) - *(int *)(param_1 + 0x24);
    if (uVar2 < *(uint *)(param_1 + 0x14)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + uVar2;
    }
    else {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x14);
    }
  }
  else if (iVar1 == 4) {
    uVar2 = (*(int *)(param_1 + 0x50) * -0x19 + 0x16e) - *(int *)(param_1 + 0x24);
    if (uVar2 < (uint)(*(int *)(param_1 + 0x14) * 10)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + uVar2;
    }
    else {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x14) * 10 + *(int *)(param_1 + 0x24);
    }
  }
  return;
}


// ==== FUN_0040c463 @ 0040c463

void __fastcall FUN_0040c463(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[99];
  if (iVar1 == 0) {
    if (DAT_00431fb8 + -9 == param_1[0x69]) {
      param_1[99] = 1;
    }
    else if (param_1[8] != 1) {
      param_1[99] = 3;
    }
  }
  else if (iVar1 == 2) {
    if (param_1[0x14] * -0x19 + 0x165 == param_1[0x69]) {
      param_1[0xf] = 0;
      param_1[0x13] = 0;
      param_1[99] = 4;
      if ((DAT_00431f5c + 1) % 3 == 0) {
        FUN_00414ba3(0xf,0);
      }
      else {
        FUN_00414ba3(1,0);
      }
      FUN_0040811c(&DAT_00431f48,4,*param_1);
    }
    else {
      iVar1 = (param_1[0x14] * -0x19 + 0x165) - param_1[0x69];
      if (iVar1 < DAT_00431f70) {
        param_1[0x69] = param_1[0x69] + iVar1;
      }
      else {
        param_1[0x69] = param_1[0x69] + DAT_00431f70;
      }
      if (param_1[9] + -9 <= (int)param_1[0x69]) {
        param_1[0x69] = param_1[9] + -9;
        iVar1 = FUN_0040de22(param_1[6]);
        if ((float10)(uint)param_1[5] / (float10)iVar1 <
            (float10)DAT_00431f70 / (float10)DAT_00431f74) {
          param_1[99] = 3;
        }
        else if (param_1[8] == 1) {
          param_1[99] = 0;
        }
        else {
          param_1[99] = 3;
        }
      }
    }
  }
  else if (iVar1 == 3) {
    iVar1 = param_1[0x69] - (DAT_00431fb8 + -9);
    if (iVar1 < DAT_00431f70) {
      param_1[0x69] = param_1[0x69] - iVar1;
    }
    else {
      param_1[0x69] = param_1[0x69] - DAT_00431f70;
    }
    if (param_1[9] + -9 <= (int)param_1[0x69]) {
      param_1[0x69] = param_1[9] + -9;
    }
    if (DAT_00431fb8 + -9 == param_1[0x69]) {
      param_1[99] = 1;
    }
  }
  return;
}


// ==== FUN_0040c74e @ 0040c74e

void __fastcall FUN_0040c74e(int param_1)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = *(int *)(param_1 + 0x54 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8) * 0x32;
  local_c = local_14 + 0x31;
  local_10 = (*(uint *)(param_1 + 0x58 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8) & 1) * 0x22;
  local_8 = local_10 + 8;
  FUN_0041cae9((void *)(param_1 + 400),1,0,-0x8000,-0x8000);
  FUN_0041c7d8((void *)(param_1 + 400),*(int *)(param_1 + 8),*(int *)(param_1 + 0x1a4),
               *(int *)(param_1 + 8) + 0x31,*(int *)(param_1 + 0x1a4) + 8,0);
  FUN_0041bc42(&DAT_004307a0,*(int *)(param_1 + 8),*(int *)(param_1 + 0x1a4),&local_14,1);
  return;
}


// ==== FUN_0040c827 @ 0040c827

void __thiscall FUN_0040c827(void *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)((int)this + 4) != 0) {
    *(int *)((int)this + 0x1a0) = *(int *)((int)this + 0x1a0) + -1;
    if ((*(int *)((int)this + 0x1a0) == 0) &&
       (((*(undefined4 *)((int)this + 0x1a0) = DAT_00431f74, *(int *)((int)this + 0x18c) == 3 ||
         (*(int *)((int)this + 0x18c) == 2)) || (*(int *)((int)this + 0x18c) == 0)))) {
      FUN_0040c463(this);
      FUN_0040c74e((int)this);
      FUN_0040b6b8(this);
    }
    if (*(int *)((int)this + 0x20) != 5) {
      if ((*(int *)((int)this + 0x2c) == 0) &&
         (*(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1, *(int *)((int)this + 0xc) == 0
         )) {
        if (*(int *)((int)this + 0x28) < 7) {
          *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + 1;
        }
        else {
          *(undefined4 *)((int)this + 0x28) = 0;
        }
        uVar1 = FUN_0040ddc2(*(int *)((int)this + 0x18));
        *(undefined4 *)((int)this + 0xc) = uVar1;
        if (*(int *)((int)this + 0x20) == 2) {
          FUN_0040b6b8(this);
        }
      }
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -1;
      if (((*(int *)((int)this + 0x20) == 2) && (DAT_004307f8 != 0)) && (DAT_00431a5c != param_1)) {
        *(undefined4 *)((int)this + 0x20) = 3;
        iVar2 = FUN_0040de82(*(int *)((int)this + 0x18));
        *(int *)((int)this + 0x10) = iVar2 / 2;
      }
      else if (*(int *)((int)this + 0x10) == 0) {
        if (*(int *)((int)this + 0x20) == 0) {
          if ((DAT_004307f8 == 0) || (DAT_00431a5c == param_1)) {
            *(undefined4 *)((int)this + 0x20) = 1;
            uVar1 = FUN_0040de22(*(int *)((int)this + 0x18));
            *(undefined4 *)((int)this + 0x10) = uVar1;
            uVar1 = FUN_0040ddc2(*(int *)((int)this + 0x18));
            *(undefined4 *)((int)this + 0xc) = uVar1;
          }
          else {
            *(undefined4 *)((int)this + 0x20) = 5;
          }
        }
        else {
          if (*(int *)((int)this + 0x20) == 1) {
            if ((DAT_004307f8 == 0) || (DAT_00431a5c == param_1)) {
              uVar1 = FUN_0040de22(*(int *)((int)this + 0x18));
              *(undefined4 *)((int)this + 0x10) = uVar1;
            }
            else {
              *(undefined4 *)((int)this + 0x20) = 3;
              iVar2 = FUN_0040de82(*(int *)((int)this + 0x18));
              *(int *)((int)this + 0x10) = iVar2 / 2;
            }
          }
          else if (*(int *)((int)this + 0x20) == 3) {
            if ((DAT_004307f8 == 0) || (DAT_00431a5c == param_1)) {
              uVar1 = FUN_0040de82(*(int *)((int)this + 0x18));
              *(undefined4 *)((int)this + 0x10) = uVar1;
            }
            else {
              iVar2 = FUN_0040de82(*(int *)((int)this + 0x18));
              *(int *)((int)this + 0x10) = iVar2 / 2;
            }
          }
          else if (*(int *)((int)this + 0x20) == 2) {
            if ((DAT_004307f8 == 0) || (DAT_00431a5c == param_1)) {
              *(undefined4 *)((int)this + 0x20) = 3;
              uVar1 = FUN_0040de82(*(int *)((int)this + 0x18));
              *(undefined4 *)((int)this + 0x10) = uVar1;
            }
            else {
              *(undefined4 *)((int)this + 0x20) = 3;
              iVar2 = FUN_0040de82(*(int *)((int)this + 0x18));
              *(int *)((int)this + 0x10) = iVar2 / 2;
            }
          }
          else if (*(int *)((int)this + 0x20) == 4) {
            uVar1 = FUN_0040deb2(*(int *)((int)this + 0x18));
            *(undefined4 *)((int)this + 0x10) = uVar1;
          }
          FUN_0040c2fc((int)this);
          FUN_0040c74e((int)this);
          FUN_0040b6b8(this);
          FUN_0040beae(this,param_1);
        }
      }
    }
  }
  return;
}


// ==== FUN_0040cbd3 @ 0040cbd3

void __thiscall FUN_0040cbd3(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  LPVOID pvVar4;
  
  *(undefined4 *)((int)this + 0x18) = param_1;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  uVar2 = FUN_0040dee2(*(int *)((int)this + 0x18));
  *(undefined4 *)((int)this + 0x14) = uVar2;
  iVar1 = *(int *)((int)this + 0x18) * 0x30 + *(int *)((int)this + 0x1c) * 0xc;
  piVar3 = (int *)(&DAT_00431d08 + iVar1);
  if (*(int *)(&DAT_00431d0c + iVar1) == 0) {
    if ((*(int *)(&DAT_00431d10 + iVar1) != 0) &&
       ((*piVar3 == 0 || (*(int *)(&DAT_00431d0c + iVar1) == 0)))) {
      pvVar4 = FUN_004145d6(*(LPCSTR *)(&DAT_00431d10 + iVar1));
      *piVar3 = (int)pvVar4;
      if (*piVar3 != 0) {
        *(int *)(&DAT_00431d0c + iVar1) = *(int *)(&DAT_00431d0c + iVar1) + 1;
      }
    }
  }
  else {
    *(int *)(&DAT_00431d0c + iVar1) = *(int *)(&DAT_00431d0c + iVar1) + 1;
  }
  *(undefined4 *)((int)this + 4) = 1;
  return;
}


// ==== FUN_0040cd06 @ 0040cd06

void __fastcall FUN_0040cd06(void *param_1)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + 0x50) < DAT_00431fc0) {
    *(int *)((int)param_1 + 0x50) = *(int *)((int)param_1 + 0x50) + 1;
    iVar1 = FUN_00407e48(4);
    *(int *)((int)param_1 + 0x18) = iVar1;
    iVar1 = FUN_00407e48(4);
    *(int *)((int)param_1 + 0x1c) = iVar1;
    *(int *)((int)param_1 + 0x24) = *(int *)((int)param_1 + 0x50) * -0x19 + 0x16f;
    FUN_0040cbd3(param_1,*(undefined4 *)((int)param_1 + 0x18),*(undefined4 *)((int)param_1 + 0x1c));
    *(undefined4 *)((int)param_1 + (*(int *)((int)param_1 + 0x50) * 3 + -3) * 8 + 0x54) =
         *(undefined4 *)((int)param_1 + 0x18);
    *(undefined4 *)((int)param_1 + (*(int *)((int)param_1 + 0x50) * 3 + -3) * 8 + 0x58) =
         *(undefined4 *)((int)param_1 + 0x1c);
    FUN_0041c7d8((void *)((int)param_1 + (*(int *)((int)param_1 + 0x50) * 3 + -3) * 8 + 0x5c),
                 *(int *)((int)param_1 + 8),*(int *)((int)param_1 + 0x50) * -0x19 + 0x16e,
                 *(int *)((int)param_1 + 8) + 0x31,
                 (*(int *)((int)param_1 + 0x50) * 5 + -5) * -5 + 0x16d,0);
    FUN_0041cae9((void *)((int)param_1 + 400),1,0,-0x8000,-0x8000);
    *(int *)((int)param_1 + 0x1a4) = DAT_00431fb8 + -9;
    FUN_0041c7d8((void *)((int)param_1 + 400),*(int *)((int)param_1 + 8),DAT_00431fb8 + -9,
                 *(int *)((int)param_1 + 8) + 0x31,DAT_00431fb8 + -1,0);
    *(undefined4 *)((int)param_1 + 0x18c) = 1;
  }
  return;
}


// ==== FUN_0040ce75 @ 0040ce75

void __fastcall FUN_0040ce75(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 1) {
    FUN_0041cae9((void *)(param_1 + 0x5c + (*(int *)(param_1 + 0x50) * 3 + -3) * 8),1,0,-0x8000,
                 -0x8000);
    FUN_0041cae9((void *)(param_1 + 400),1,0,-0x8000,-0x8000);
    FUN_0041c7d8((void *)(param_1 + 400),*(int *)(param_1 + 8),DAT_00431fb8 + -9,
                 *(int *)(param_1 + 8) + 0x31,DAT_00431fb8 + -1,0);
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
    *(int *)(param_1 + 0x1a4) = DAT_00431fb8 + -9;
    *(undefined4 *)(param_1 + 0x18) =
         *(undefined4 *)(param_1 + 0x54 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8);
    *(undefined4 *)(param_1 + 0x1c) =
         *(undefined4 *)(param_1 + 0x58 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x50) * -0x19 + 0x16f;
  }
  return;
}


// ==== FUN_0040cf6d @ 0040cf6d

void __fastcall FUN_0040cf6d(int param_1)

{
  int local_24 [3];
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = *(int *)(param_1 + 0x54 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8) * 0x32;
  local_c = local_14 + 0x31;
  local_8 = (*(uint *)(param_1 + 0x58 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8) & 1) * 0x22;
  local_10 = local_8 + 9;
  local_8 = local_8 + 0x21;
  if (*(int *)(param_1 + 0x50) == 1) {
    local_24[0] = 0;
    local_24[2] = 0x31;
    local_24[1] = 0;
    local_18 = 0x18;
    FUN_0041bc42(&DAT_004317e0,*(int *)(param_1 + 8),*(int *)(param_1 + 0x50) * -0x19 + 0x16e,
                 local_24,1);
  }
  else {
    FUN_0041bc42(&DAT_004307a0,*(int *)(param_1 + 8),*(int *)(param_1 + 0x50) * -0x19 + 0x16e,
                 &local_14,1);
  }
  local_10 = (*(uint *)(param_1 + 0x58 + (*(int *)(param_1 + 0x50) * 3 + -3) * 8) & 1) * 0x22;
  local_8 = local_10 + 8;
  FUN_0041bc42(&DAT_004307a0,*(int *)(param_1 + 8),DAT_00431fb8 + -9,&local_14,1);
  return;
}


// ==== FUN_0040d0a5 @ 0040d0a5

void __fastcall FUN_0040d0a5(int *param_1)

{
  int local_8;
  
  FUN_0041cae9(param_1 + 0x13,0,0,-0x8000,-0x8000);
  if (param_1[2] < 0xe) {
    *param_1 = param_1[2] * -0x19 + 0x16e;
    local_8 = (param_1[2] * 5 + 5) * -5 + 0x16e;
  }
  else {
    local_8 = 0;
  }
  FUN_0041b4fc(param_1 + 3,0x5a,local_8,1);
  return;
}


// ==== FUN_0040d139 @ 0040d139

void __fastcall FUN_0040d139(int param_1)

{
  LPVOID pvVar1;
  
  FUN_00421360((uint *)(param_1 + 0x14),(uint *)s_margin_00429814);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(int *)(param_1 + 0x2c) == 1) {
        pvVar1 = FUN_004145d6((LPCSTR)(param_1 + 0x14));
        *(LPVOID *)(param_1 + 0xc) = pvVar1;
      }
      else {
        pvVar1 = FUN_004145d6(*(LPCSTR *)(param_1 + 0x28));
        *(LPVOID *)(param_1 + 0xc) = pvVar1;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
    }
    else if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  return;
}


// ==== FUN_0040d265 @ 0040d265

void __thiscall FUN_0040d265(void *this,HWND param_1)

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
  int local_24;
  HDC local_1c;
  int local_18 [3];
  undefined4 local_c;
  int local_8;
  
  if (param_1 != (HWND)0x0) {
    local_1c = GetDC(param_1);
    SelectPalette(local_1c,DAT_00432f3c,0);
    RealizePalette(local_1c);
  }
  FUN_0041cae9((void *)((int)this + 8),1,0,-0x8000,-0x8000);
  local_8 = *(int *)(&DAT_00430c40 + *(int *)((int)this + 4) * 0x1a8) + 7;
  local_18[1] = 0;
  local_c = 0x1d;
  local_18[0] = *(int *)this * 0x23;
  local_18[2] = local_18[0] + 0x22;
  FUN_0041c7d8((void *)((int)this + 8),local_8,0x172,
               *(int *)(&DAT_00430c40 + *(int *)((int)this + 4) * 0x1a8) + 0x29,399,0);
  FUN_0041bc42(&DAT_00431e28,local_8,0x172,local_18,1);
  if (param_1 != (HWND)0x0) {
    if (DAT_004334ac != 0) {
      bVar7 = false;
      if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
        for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
          iVar1 = *(int *)(&DAT_00433378 + local_24 * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_24 * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_24 * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_24 * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_24 * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_24 * 0x10);
          pHVar8 = CreateCompatibleDC(local_1c);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(local_1c,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_004334ac = 0;
      }
      else {
        for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
          if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_24 * 0x10)) &&
             (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_24 * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
            y = *(int *)(&DAT_00433370 + local_24 * 0x10) - DAT_004334c8;
            x = *(int *)(&DAT_0043336c + local_24 * 0x10) - DAT_004334c4;
            iVar1 = *(int *)(&DAT_00433378 + local_24 * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_24 * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            pHVar8 = CreateCompatibleDC(local_1c);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(local_1c,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020)
            ;
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_24 = 0; local_24 < DAT_004334ac; local_24 = local_24 + 1) {
            iVar1 = *(int *)(&DAT_00433378 + local_24 * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_24 * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_24 * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_24 * 0x10);
            pHVar8 = CreateCompatibleDC(local_1c);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(local_1c,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_004334ac = 0;
      }
    }
    ReleaseDC(param_1,local_1c);
  }
  return;
}


// ==== FUN_0040d749 @ 0040d749

void __thiscall FUN_0040d749(void *this,HWND param_1)

{
  if (*(int *)this == 0) {
    *(undefined4 *)this = 1;
    FUN_00414ba3(0xd,1);
  }
  else if (*(int *)this == 1) {
    *(undefined4 *)this = 2;
    FUN_00414ba3(0xe,1);
  }
  else if (*(int *)this == 2) {
    *(undefined4 *)this = 0;
    FUN_00414ba3(0xc,1);
  }
  FUN_0040d265(this,param_1);
  return;
}


// ==== FUN_0040d7da @ 0040d7da

void __thiscall FUN_0040d7da(void *this,HWND param_1)

{
  *(undefined4 *)this = 2;
  FUN_0040d749(this,param_1);
  return;
}


// ==== PreCreateWindow @ 0040d807

/* Library Function - Single Match
    protected: virtual int __thiscall CEditView::PreCreateWindow(struct tagCREATESTRUCTA &)
   
   Library: Visual Studio 1998 Debug */

int __thiscall CEditView::PreCreateWindow(CEditView *this,tagCREATESTRUCTA *param_1)

{
  int iVar1;
  
  *(undefined4 *)(this + 4) = 3;
  iVar1 = FUN_0040d7da(this,(HWND)param_1);
  return iVar1;
}


// ==== FUN_0040d835 @ 0040d835

void __thiscall FUN_0040d835(void *this,HWND param_1,int param_2)

{
  if (param_2 == 0x27) {
    if ((*(int *)((int)this + 4) != 6) &&
       (*(int *)(&DAT_00430c3c + (*(int *)((int)this + 4) + 1) * 0x1a8) != 0)) {
      FUN_0040da14((int)this);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      if (*(int *)this == 0) {
        FUN_0040d265(this,param_1);
      }
      else {
        FUN_0040d7da(this,param_1);
      }
      FUN_0040dae5((int)this);
    }
  }
  else if (param_2 == 0x25) {
    if ((*(int *)((int)this + 4) != 0) &&
       (*(int *)(&DAT_00430c3c + (*(int *)((int)this + 4) + -1) * 0x1a8) != 0)) {
      FUN_0040da14((int)this);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
      if (*(int *)this == 0) {
        FUN_0040d265(this,param_1);
      }
      else {
        FUN_0040d7da(this,param_1);
      }
      FUN_0040dae5((int)this);
    }
  }
  else if (param_2 == 0xc9) {
    if ((*(int *)((int)this + 4) != 6) &&
       (*(int *)(&DAT_00430c3c + (*(int *)((int)this + 4) + 1) * 0x1a8) != 0)) {
      FUN_0040da14((int)this);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      FUN_0040d265(this,param_1);
      FUN_0040dae5((int)this);
    }
  }
  else if (((param_2 == 0xcc) && (*(int *)((int)this + 4) != 0)) &&
          (*(int *)(&DAT_00430c3c + (*(int *)((int)this + 4) + -1) * 0x1a8) != 0)) {
    FUN_0040da14((int)this);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
    FUN_0040d265(this,param_1);
    FUN_0040dae5((int)this);
  }
  return;
}


// ==== FUN_0040da14 @ 0040da14

void __fastcall FUN_0040da14(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) == 1) {
    *(undefined4 *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) = 2;
    uVar1 = FUN_0040de52(*(int *)(&DAT_00430c50 + *(int *)(param_1 + 4) * 0x1a8));
    *(undefined4 *)(&DAT_00430c48 + *(int *)(param_1 + 4) * 0x1a8) = uVar1;
  }
  else if (*(int *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) == 0) {
    *(undefined4 *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) = 5;
  }
  return;
}


// ==== FUN_0040dae5 @ 0040dae5

void __fastcall FUN_0040dae5(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) == 2) {
    *(undefined4 *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) = 1;
    uVar1 = FUN_0040de22(*(int *)(&DAT_00430c50 + *(int *)(param_1 + 4) * 0x1a8));
    *(undefined4 *)(&DAT_00430c48 + *(int *)(param_1 + 4) * 0x1a8) = uVar1;
  }
  else if (*(int *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) == 5) {
    *(undefined4 *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) = 0;
    uVar1 = FUN_0040ddf2(*(int *)(&DAT_00430c50 + *(int *)(param_1 + 4) * 0x1a8));
    *(undefined4 *)(&DAT_00430c48 + *(int *)(param_1 + 4) * 0x1a8) = uVar1;
  }
  else if (*(int *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) == 3) {
    *(undefined4 *)(&DAT_00430c58 + *(int *)(param_1 + 4) * 0x1a8) = 1;
    uVar1 = FUN_0040de22(*(int *)(&DAT_00430c50 + *(int *)(param_1 + 4) * 0x1a8));
    *(undefined4 *)(&DAT_00430c48 + *(int *)(param_1 + 4) * 0x1a8) = uVar1;
  }
  return;
}


// ==== FUN_0040dc76 @ 0040dc76

void FUN_0040dc76(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if (DAT_00431a58 == 0) {
    local_c = DAT_00429370;
  }
  else if (DAT_00431a58 == 1) {
    local_c = DAT_00429374;
  }
  else if (DAT_00431a58 == 2) {
    local_c = DAT_00429378;
  }
  local_8 = 0;
  while( true ) {
    if (6 < local_8) {
      return;
    }
    if ((((*(int *)(&DAT_00430c3c + local_8 * 0x1a8) != 0) &&
         (*(int *)(&DAT_00430c58 + local_8 * 0x1a8) != 4)) &&
        (*(int *)(&DAT_00430dc4 + local_8 * 0x1a8) == 1)) &&
       (iVar1 = FUN_00407e48(local_c), iVar1 == 7)) break;
    local_8 = local_8 + 1;
  }
  *(undefined4 *)(&DAT_00430dd8 + local_8 * 0x1a8) = DAT_00431f74;
  *(undefined4 *)(&DAT_00430dc4 + local_8 * 0x1a8) = 2;
  FUN_00414ba3(1,0);
  return;
}


// ==== FUN_0040ddc2 @ 0040ddc2

undefined4 __cdecl FUN_0040ddc2(int param_1)

{
  return *(undefined4 *)(&DAT_00429234 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040ddf2 @ 0040ddf2

undefined4 __cdecl FUN_0040ddf2(int param_1)

{
  return *(undefined4 *)(&DAT_00429220 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040de22 @ 0040de22

undefined4 __cdecl FUN_0040de22(int param_1)

{
  return *(undefined4 *)(&DAT_00429224 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040de52 @ 0040de52

undefined4 __cdecl FUN_0040de52(int param_1)

{
  return *(undefined4 *)(&DAT_00429228 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040de82 @ 0040de82

undefined4 __cdecl FUN_0040de82(int param_1)

{
  return *(undefined4 *)(&DAT_0042922c + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040deb2 @ 0040deb2

undefined4 __cdecl FUN_0040deb2(int param_1)

{
  return *(undefined4 *)(&DAT_00429230 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040dee2 @ 0040dee2

undefined4 __cdecl FUN_0040dee2(int param_1)

{
  return *(undefined4 *)(&DAT_00429238 + param_1 * 0x1c + DAT_00431a58 * 0x70);
}


// ==== FUN_0040df12 @ 0040df12

int __fastcall FUN_0040df12(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040df95;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_((void *)(param_1 + 8),0x50,6,FUN_00413820,FUN_00413140);
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0x1e8) = 1;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040dfae @ 0040dfae

void __fastcall FUN_0040dfae(int param_1)

{
  uint *puVar1;
  LPVOID pvVar2;
  int local_8;
  
  FUN_00421360((uint *)(param_1 + 0x10),(uint *)s_ZAS_SNAKE_0042981c);
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 8) == 0)) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (*(int *)(param_1 + 0x28) == 1) {
        pvVar2 = FUN_004145d6((LPCSTR)(param_1 + 0x10));
        *(LPVOID *)(param_1 + 8) = pvVar2;
      }
      else {
        pvVar2 = FUN_004145d6(*(LPCSTR *)(param_1 + 0x24));
        *(LPVOID *)(param_1 + 8) = pvVar2;
      }
      if (*(int *)(param_1 + 8) != 0) {
        *(undefined4 *)(param_1 + 0xc) = 1;
      }
    }
    else if (*(int *)(param_1 + 8) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    puVar1 = (uint *)FUN_004140e0((uint *)s_ZAS_SNAKE_00429828,local_8,1);
    FUN_00421360((uint *)(local_8 * 0x50 + param_1 + 0x10),puVar1);
    *(undefined4 *)(local_8 * 0x50 + 0x28 + param_1) = 1;
    *(undefined4 *)(local_8 * 0x50 + 0x2c + param_1) = 0;
    if ((*(int *)(local_8 * 0x50 + 0x28 + param_1) != 0) &&
       (*(int *)(local_8 * 0x50 + 8 + param_1) == 0)) {
      if (*(int *)(local_8 * 0x50 + 0x2c + param_1) == 0) {
        if (*(int *)(local_8 * 0x50 + 0x28 + param_1) == 1) {
          pvVar2 = FUN_004145d6((LPCSTR)(local_8 * 0x50 + param_1 + 0x10));
          *(LPVOID *)(local_8 * 0x50 + 8 + param_1) = pvVar2;
        }
        else {
          pvVar2 = FUN_004145d6(*(LPCSTR *)(local_8 * 0x50 + 0x24 + param_1));
          *(LPVOID *)(local_8 * 0x50 + 8 + param_1) = pvVar2;
        }
        if (*(int *)(local_8 * 0x50 + 8 + param_1) != 0) {
          *(undefined4 *)(local_8 * 0x50 + 0xc + param_1) = 1;
        }
      }
      else if (*(int *)(local_8 * 0x50 + 8 + param_1) != 0) {
        *(undefined4 *)(local_8 * 0x50 + 0xc + param_1) = 0;
      }
    }
  }
  return;
}


// ==== FUN_0040e2c1 @ 0040e2c1

void __fastcall FUN_0040e2c1(int param_1)

{
  FUN_0041cae9((void *)(*(int *)(&DAT_00429380 + *(int *)(param_1 + 4) * 4) * 0x50 + param_1 + 0x48)
               ,0,0,-0x8000,-0x8000);
  if (*(int *)(param_1 + 4) == 0x21) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  FUN_0041b4fc((void *)(*(int *)(&DAT_00429380 + *(int *)(param_1 + 4) * 4) * 0x50 + 8 + param_1),
               *(int *)(&DAT_00429408 + *(int *)(&DAT_00429380 + *(int *)(param_1 + 4) * 4) * 8),
               *(int *)(&DAT_0042940c + *(int *)(&DAT_00429380 + *(int *)(param_1 + 4) * 4) * 8),1);
  return;
}


// ==== FUN_0040e37e @ 0040e37e

undefined4 * __fastcall FUN_0040e37e(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040e3fd;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_(param_1 + 3,0x50,7,FUN_00413820,FUN_00413140);
  param_1[2] = 6;
  *param_1 = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040e416 @ 0040e416

void __fastcall FUN_0040e416(int param_1)

{
  uint *puVar1;
  LPVOID pvVar2;
  int local_8;
  
  FUN_00421360((uint *)(param_1 + 0x14),(uint *)s_OLD_MAN_00429834);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(int *)(param_1 + 0x2c) == 1) {
        pvVar2 = FUN_004145d6((LPCSTR)(param_1 + 0x14));
        *(LPVOID *)(param_1 + 0xc) = pvVar2;
      }
      else {
        pvVar2 = FUN_004145d6(*(LPCSTR *)(param_1 + 0x28));
        *(LPVOID *)(param_1 + 0xc) = pvVar2;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
    }
    else if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  for (local_8 = 1; local_8 < 7; local_8 = local_8 + 1) {
    puVar1 = (uint *)FUN_004140e0((uint *)s_OLD_MAN_0042983c,local_8,1);
    FUN_00421360((uint *)(local_8 * 0x50 + param_1 + 0x14),puVar1);
    *(undefined4 *)(local_8 * 0x50 + 0x2c + param_1) = 1;
    *(undefined4 *)(local_8 * 0x50 + 0x30 + param_1) = 0;
    if ((*(int *)(local_8 * 0x50 + 0x2c + param_1) != 0) &&
       (*(int *)(local_8 * 0x50 + 0xc + param_1) == 0)) {
      if (*(int *)(local_8 * 0x50 + 0x30 + param_1) == 0) {
        if (*(int *)(local_8 * 0x50 + 0x2c + param_1) == 1) {
          pvVar2 = FUN_004145d6((LPCSTR)(local_8 * 0x50 + param_1 + 0x14));
          *(LPVOID *)(local_8 * 0x50 + 0xc + param_1) = pvVar2;
        }
        else {
          pvVar2 = FUN_004145d6(*(LPCSTR *)(local_8 * 0x50 + 0x28 + param_1));
          *(LPVOID *)(local_8 * 0x50 + 0xc + param_1) = pvVar2;
        }
        if (*(int *)(local_8 * 0x50 + 0xc + param_1) != 0) {
          *(undefined4 *)(local_8 * 0x50 + 0x10 + param_1) = 1;
        }
      }
      else if (*(int *)(local_8 * 0x50 + 0xc + param_1) != 0) {
        *(undefined4 *)(local_8 * 0x50 + 0x10 + param_1) = 0;
      }
    }
  }
  return;
}


// ==== FUN_0040e729 @ 0040e729

void __fastcall FUN_0040e729(undefined4 *param_1)

{
  if (param_1[2] == -1) {
    param_1[2] = 0;
  }
  else {
    FUN_0041cae9(param_1 + *(int *)(&DAT_00429438 + param_1[2] * 4) * 0x14 + 0x13,0,0,-0x8000,
                 -0x8000);
    if (param_1[2] == 0x14) {
      FUN_0041ad4a(&DAT_00430a98,0x225,0x12d,1);
      *param_1 = 0;
      FUN_00414ba3(2,0);
      return;
    }
    param_1[2] = param_1[2] + 1;
  }
  FUN_0041b4fc(param_1 + *(int *)(&DAT_00429438 + param_1[2] * 4) * 0x14 + 3,
               *(int *)(&DAT_00429490 + *(int *)(&DAT_00429438 + param_1[2] * 4) * 8),
               *(int *)(&DAT_00429494 + *(int *)(&DAT_00429438 + param_1[2] * 4) * 8),1);
  return;
}


// ==== FUN_0040e835 @ 0040e835

void __fastcall FUN_0040e835(int param_1)

{
  FUN_0041cae9((void *)(*(int *)(&DAT_00429438 + *(int *)(param_1 + 8) * 4) * 0x50 + param_1 + 0x4c)
               ,0,0,-0x8000,-0x8000);
  return;
}


// ==== FUN_0040e885 @ 0040e885

undefined4 * __fastcall FUN_0040e885(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040e90e;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_(param_1 + 3,0x50,6,FUN_00413820,FUN_00413140);
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040e927 @ 0040e927

void __fastcall FUN_0040e927(int param_1)

{
  uint *puVar1;
  LPVOID pvVar2;
  int local_8;
  
  FUN_00421360((uint *)(param_1 + 0x14),(uint *)s_PARROT_00429844);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(int *)(param_1 + 0x2c) == 1) {
        pvVar2 = FUN_004145d6((LPCSTR)(param_1 + 0x14));
        *(LPVOID *)(param_1 + 0xc) = pvVar2;
      }
      else {
        pvVar2 = FUN_004145d6(*(LPCSTR *)(param_1 + 0x28));
        *(LPVOID *)(param_1 + 0xc) = pvVar2;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
    }
    else if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    puVar1 = (uint *)FUN_004140e0((uint *)s_PARROT_0042984c,local_8,1);
    FUN_00421360((uint *)(local_8 * 0x50 + param_1 + 0x14),puVar1);
    *(undefined4 *)(local_8 * 0x50 + 0x2c + param_1) = 1;
    *(undefined4 *)(local_8 * 0x50 + 0x30 + param_1) = 0;
    if ((*(int *)(local_8 * 0x50 + 0x2c + param_1) != 0) &&
       (*(int *)(local_8 * 0x50 + 0xc + param_1) == 0)) {
      if (*(int *)(local_8 * 0x50 + 0x30 + param_1) == 0) {
        if (*(int *)(local_8 * 0x50 + 0x2c + param_1) == 1) {
          pvVar2 = FUN_004145d6((LPCSTR)(local_8 * 0x50 + param_1 + 0x14));
          *(LPVOID *)(local_8 * 0x50 + 0xc + param_1) = pvVar2;
        }
        else {
          pvVar2 = FUN_004145d6(*(LPCSTR *)(local_8 * 0x50 + 0x28 + param_1));
          *(LPVOID *)(local_8 * 0x50 + 0xc + param_1) = pvVar2;
        }
        if (*(int *)(local_8 * 0x50 + 0xc + param_1) != 0) {
          *(undefined4 *)(local_8 * 0x50 + 0x10 + param_1) = 1;
        }
      }
      else if (*(int *)(local_8 * 0x50 + 0xc + param_1) != 0) {
        *(undefined4 *)(local_8 * 0x50 + 0x10 + param_1) = 0;
      }
    }
  }
  return;
}


// ==== FUN_0040ec3a @ 0040ec3a

void __fastcall FUN_0040ec3a(int param_1)

{
  if (*(int *)(param_1 + 8) == 0x26) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    if ((*(int *)(param_1 + 8) + 1) % 9 == 0) {
      FUN_00414ba3(10,0);
    }
  }
  FUN_0041ad4a((void *)(*(int *)(&DAT_004294c8 + *(int *)(param_1 + 8) * 4) * 0x50 + 0xc + param_1),
               DAT_00429568,DAT_0042956c,1);
  return;
}


// ==== FUN_0040ecc2 @ 0040ecc2

void __thiscall FUN_0040ecc2(void *this,HWND param_1,int param_2)

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
  
  if (param_2 == 1) {
    *(undefined4 *)((int)this + 4) = 0x14;
    FUN_0041ad4a((void *)((int)this + 0xfc),DAT_00429568,DAT_0042956c,1);
  }
  else {
    *(undefined4 *)((int)this + 4) = 0xfffffff6;
    FUN_0041ad4a((void *)((int)this + 0xc),DAT_00429568,DAT_0042956c,1);
  }
  hdc = GetDC(param_1);
  SelectPalette(hdc,DAT_00432f3c,0);
  RealizePalette(hdc);
  if (DAT_004334ac != 0) {
    bVar7 = false;
    if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
        iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
        iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
        iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
        pHVar8 = CreateCompatibleDC(hdc);
        pvVar9 = SelectObject(pHVar8,DAT_004334d0);
        BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_004334ac = 0;
    }
    else {
      for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
        if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_10 * 0x10)) &&
           (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_10 * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          y = *(int *)(&DAT_00433370 + local_10 * 0x10) - DAT_004334c8;
          x = *(int *)(&DAT_0043336c + local_10 * 0x10) - DAT_004334c4;
          iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_10 = 0; local_10 < DAT_004334ac; local_10 = local_10 + 1) {
          iVar1 = *(int *)(&DAT_00433378 + local_10 * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_10 * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_10 * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_10 * 0x10);
          pHVar8 = CreateCompatibleDC(hdc);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(hdc,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020
                );
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_004334ac = 0;
    }
  }
  ReleaseDC(param_1,hdc);
  return;
}


// ==== FUN_0040f14c @ 0040f14c

void FUN_0040f14c(void)

{
  FUN_00402229();
  return;
}


// ==== FUN_0040f161 @ 0040f161

void __cdecl FUN_0040f161(undefined4 param_1)

{
  if (DAT_00428508 == 2) {
    DAT_00429370 = 1000;
    DAT_00429374 = 0x4b0;
    DAT_00429378 = 600;
  }
  else if (DAT_00428508 == 3) {
    DAT_00429370 = 700;
    DAT_00429374 = 0x28a;
    DAT_00429378 = 0x2ee;
  }
  else {
    DAT_00429370 = 0x5dc;
    DAT_00429374 = 0x578;
    DAT_00429378 = 0x640;
  }
  switch(param_1) {
  case 1:
    DAT_00431f78 = 4;
    DAT_00431f7c = 1;
    break;
  case 2:
    DAT_00431f78 = 4;
    DAT_00431f7c = 5;
    break;
  case 3:
    DAT_00431f78 = 3;
    DAT_00431f7c = 2;
    break;
  case 4:
    DAT_00431f78 = 3;
    DAT_00431f7c = 6;
    break;
  case 5:
    DAT_00431f78 = 2;
    DAT_00431f7c = 3;
    break;
  case 6:
    DAT_00431f78 = 2;
    DAT_00431f7c = 7;
    break;
  case 7:
    DAT_00431f78 = 1;
    DAT_00431f7c = 4;
    break;
  case 8:
    DAT_00431f78 = 1;
    DAT_00431f7c = 8;
    break;
  case 9:
    DAT_00431f78 = 0;
    DAT_00431f7c = 5;
    break;
  default:
    DAT_00431f78 = 0;
    DAT_00431f7c = 9;
  }
  return;
}


// ==== FUN_0040f34d @ 0040f34d

void FUN_0040f34d(void)

{
  FUN_00401db8();
  DAT_00431f7c = DAT_004283a8;
  DAT_004283a4 = DAT_004283a8;
  DAT_00428508 = DAT_004283ac;
  FUN_0040f161(DAT_004283a8);
  return;
}


// ==== FUN_0040f38e @ 0040f38e

undefined4 FUN_0040f38e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = DAT_00429964;
  iVar2 = DAT_004283ac;
  iVar1 = DAT_004283a8;
  FUN_0040597f();
  FUN_0040f14c();
  if (DAT_00429964 == 0) {
    FUN_004148a5(0);
  }
  else if ((iVar3 == 0) && (DAT_00428818 == 0)) {
    iVar3 = _rand();
    FUN_004148a5(iVar3 % 3 + 1);
  }
  if ((DAT_004283ac == iVar2) && (DAT_004283a8 == iVar1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_0040f43e @ 0040f43e

void FUN_0040f43e(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_00431f4c == 2) || (DAT_00428818 != 0)) || (DAT_0042881c != 0)) {
    SetMenu(DAT_00431864,DAT_00432038);
    if (DAT_004283b4 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00432088);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00432088);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00431864);
  }
  else {
    SetMenu(DAT_00431864,DAT_00430798);
    if (DAT_004283b4 == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00432088);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00432088);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00431864);
  }
  return;
}


// ==== FUN_0040f542 @ 0040f542

void __cdecl FUN_0040f542(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_30;
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
    uVar2 = ((uint)*(ushort *)((int)DAT_00431fb0 + 0xe) * DAT_00431fb0[1] + 0x1f & 0xffffffe0) >> 3;
    if (DAT_00431fb0[4] == 3) {
      iVar1 = *DAT_00431fb0 + 0xc;
    }
    else {
      if ((DAT_00431fb0[8] == 0) && (*(ushort *)((int)DAT_00431fb0 + 0xe) < 9)) {
        local_30 = 1 << (*(byte *)((int)DAT_00431fb0 + 0xe) & 0x1f);
      }
      else {
        local_30 = DAT_00431fb0[8];
      }
      iVar1 = local_30 * 4 + *DAT_00431fb0;
    }
    FUN_0041e5d0((char *)((int)DAT_00431fb0 +
                         (DAT_00431fb0[2] - (param_1[2] + param_3)) * uVar2 + param_2 + iVar1),
                 local_28,param_1[1],param_1[2],uVar2,
                 ((uint)*(ushort *)((int)param_1 + 0xe) * param_1[1] + 0x1f & 0xffffffe0) >> 3,0);
  }
  return;
}


// ==== FUN_0040f6f0 @ 0040f6f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_0040f6f0(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  bool bVar1;
  int cy;
  DWORD DVar2;
  INT_PTR IVar3;
  int iVar4;
  HDC pHVar5;
  HDC pHVar6;
  HGDIOBJ pvVar7;
  HWND pHVar8;
  BOOL BVar9;
  UINT UVar10;
  int local_94;
  int local_8c;
  int local_84;
  tagPAINTSTRUCT local_70;
  int local_2c;
  UINT local_20;
  int local_18 [5];
  
  if (0xf < param_2) {
    if (param_2 < 0x1d) {
      if (param_2 == 0x1c) {
        DAT_00430a44 = param_3;
        PostMessageA(param_1,0x464,(WPARAM)param_3,param_4);
        if (param_3 == (HWND)0x0) {
          FUN_0040f14c();
          if ((DAT_00431f4c != 2) && (DAT_0042881c == 0)) {
            DAT_00428818 = 1;
          }
          FUN_0040f43e();
        }
        else {
          FUN_00401db8();
        }
        if ((param_3 == (HWND)0x0) || (DAT_00428818 != 0)) {
          FUN_004148a5(0);
        }
        else {
          iVar4 = _rand();
          FUN_004148a5(iVar4 % 3 + 1);
        }
        DAT_00428820 = 0;
        InvalidateRect(DAT_00431864,(RECT *)0x0,0);
        return 0;
      }
      if (param_2 == 0x10) {
        if ((DAT_0042881c != 0) || (DAT_00431f4c == 2)) {
          FUN_00407e94();
          DAT_00428824 = 1;
          SetTimer(DAT_00431864,0x14,500,(TIMERPROC)0x0);
          return 0;
        }
        if ((DAT_00431f4c != 2) && (DAT_004307f8 == 0)) {
          FUN_00414ba3(2,0);
          FUN_00408670(DAT_00431864,1);
        }
        FUN_00407ec7();
        IVar3 = FUN_0040567b();
        if (IVar3 != 1) {
          if ((DAT_00431f4c != 2) && (DAT_004307f8 == 0)) {
            FUN_00414ba3(3,0);
            FUN_00408670(DAT_00431864,0);
          }
          FUN_00407ec7();
          return 0;
        }
        iVar4 = FUN_00402048(DAT_0042882c,local_18);
        if ((iVar4 != 0) && (local_18[0] < 10)) {
          if (DAT_004283bc != 0) {
            FUN_004058a1();
          }
          FUN_004020e5(DAT_0042882c);
          DAT_00429218 = local_18[0];
          FUN_00405910();
          FUN_0040f14c();
        }
        FUN_00407ec7();
        FUN_00407e94();
        DAT_00428824 = 1;
        SetTimer(DAT_00431864,0x14,500,(TIMERPROC)0x0);
        return 0;
      }
switchD_00411ecf_caseD_3:
      UVar10 = FUN_00420600(param_1,param_2,(WPARAM)param_3,param_4);
      return UVar10;
    }
    if (param_2 < 0x7f) {
      if (param_2 == 0x7e) {
        Sleep(400);
        GdiFlush();
        Sleep(400);
        GdiFlush();
        DeleteObject(DAT_00431860);
        DeleteObject(DAT_00432014);
        Sleep(100);
        pHVar5 = GetDC((HWND)0x0);
        DAT_00431860 = FUN_00414310(pHVar5,s_PAUSEBMP_00429854);
        DAT_00432014 = FUN_00414310(pHVar5,s_GAMEOVERBMP_00429860);
        ReleaseDC((HWND)0x0,pHVar5);
        return 0;
      }
      if (param_2 == 0x24) {
        *(undefined4 *)(param_4 + 8) = DAT_00430c30;
        *(undefined4 *)(param_4 + 0xc) = DAT_004317dc;
        return 0;
      }
      goto switchD_00411ecf_caseD_3;
    }
    if (param_2 < 0x101) {
      if (param_2 != 0x100) {
        if (param_2 == 0x86) {
          if (param_3 != (HWND)0x0) {
            InvalidateRect(DAT_00432088,(RECT *)0x0,0);
          }
          UVar10 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
          return UVar10;
        }
        goto switchD_00411ecf_caseD_3;
      }
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_00432088,6);
        return 0;
      }
      if ((DAT_00431a50 == 1) || (DAT_0042881c != 0)) {
        SendMessageA(DAT_00431864,0x111,0x65,0);
      }
      else {
        if (DAT_00428818 != 0) {
          SendMessageA(DAT_00432088,0x111,0xc9,0);
          return 0;
        }
        switch(param_3) {
        case (HWND)0x20:
        case (HWND)0x28:
          FUN_0040d749(&DAT_00431a58,param_1);
          break;
        case (HWND)0x25:
          FUN_0040d835(&DAT_00431a58,param_1,0xcc);
          break;
        case (HWND)0x27:
          FUN_0040d835(&DAT_00431a58,param_1,0xc9);
        }
      }
    }
    else if (param_2 < 0x202) {
      if (param_2 == 0x201) {
        if ((DAT_00431f4c != 2) && (DAT_0042881c == 0)) {
          if (DAT_00428818 != 0) {
            SendMessageA(DAT_00432088,0x111,0xc9,0);
            return 0;
          }
          return 0;
        }
        SendMessageA(DAT_00431864,0x111,0x65,0);
        return 0;
      }
      if (param_2 != 0x111) {
        if (param_2 == 0x113) {
          if (param_3 == (HWND)0x1) {
            if (DAT_00428504 < 2) {
              if (DAT_00428504 == 1) {
                DAT_00428504 = 0;
                if (DAT_00431a58 == 0) {
                  FUN_004148a5(1);
                }
                if (DAT_00431a58 == 1) {
                  FUN_004148a5(2);
                }
                else if (DAT_00431a58 == 2) {
                  FUN_004148a5(3);
                }
              }
              else if ((DAT_00428818 == 0) && (DAT_00430a44 != (HWND)0x0)) {
                FUN_00414a85();
              }
            }
            else {
              DAT_00428504 = DAT_00428504 + -1;
            }
            return 0;
          }
          if (param_3 == (HWND)0x14) {
            DAT_00428824 = 1;
            KillTimer(param_1,1);
            KillTimer(param_1,0x14);
            FUN_004205b8();
            DestroyWindow(param_1);
            return 0;
          }
          return 0;
        }
        goto switchD_00411ecf_caseD_3;
      }
      if (DAT_00428824 != 0) {
        return 0;
      }
      switch((uint)param_3 & 0xffff) {
      case 0x65:
        if ((DAT_00431f4c != 2) && (DAT_0042881c == 0)) {
          IVar3 = FUN_004056f3();
          if (IVar3 != 1) {
            return 0;
          }
          iVar4 = FUN_00402048(DAT_0042882c,local_18);
          if ((iVar4 != 0) && (local_18[0] < 10)) {
            if (DAT_004283bc != 0) {
              FUN_004058a1();
            }
            FUN_004020e5(DAT_0042882c);
            DAT_00429218 = local_18[0];
            FUN_00405910();
            FUN_0040f14c();
          }
        }
        DAT_0042881c = 0;
        DAT_00428818 = 0;
        DAT_00428508 = DAT_004283ac;
        DAT_004283a4 = DAT_004283a8;
        DAT_004307f8 = 0;
        DAT_00431b10 = 0;
        FUN_0040f161(DAT_004283a8);
        for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
          *(int *)(&DAT_00430c38 + local_2c * 0x1a8) = local_2c;
          *(int *)(&DAT_00430c40 + local_2c * 0x1a8) = local_2c * 0x38 + 0x60;
          if ((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) {
            *(int *)(&DAT_00430c40 + local_2c * 0x1a8) =
                 *(int *)(&DAT_00430c40 + local_2c * 0x1a8) + -0x1c;
          }
        }
        if (DAT_00431a50 == 1) {
          DAT_00431a50 = 0;
          GlobalFree(DAT_00431fb0);
          DAT_00431fb0 = FUN_0041452c(s_playbox_0042986c);
          FUN_004159d5(&DAT_00432f20,0,1,0,1,600,400,DAT_00431fb0,-1);
        }
        DAT_00431f8c = 0;
        DAT_00431f84 = 0;
        DAT_00431f80 = 0;
        DAT_00431fc0 = DAT_00431f7c + 4;
        DAT_00431a5c = 3;
        DAT_00431a58 = 0;
        DAT_0042882c = 0;
        DAT_00431f5c = 0;
        iVar4 = _rand();
        FUN_004148a5(iVar4 % 3 + 1);
        FUN_0040f542(*(int **)(DAT_004283a4 * 4 + 0x431ac0),0x18,0x11a);
        FUN_0040ae15();
        FUN_0040f43e();
        _memset(&DAT_00431840,0,0x14);
        if (DAT_004283b0 != 0) {
          PostMessageA(DAT_00431864,0x111,0x130,0);
        }
        return 0;
      case 0x66:
        if (DAT_00431f4c != 2) {
          FUN_0040ecc2(&DAT_00431b10,param_1,1);
        }
        FUN_00407ec7();
        DAT_00429218 = 0xffffffff;
        FUN_00405910();
        if (DAT_00431f4c != 2) {
          FUN_0040ecc2(&DAT_00431b10,DAT_00431864,0);
        }
        FUN_00407ec7();
        return 0;
      case 0x67:
        SetFocus(param_1);
        PostMessageA(DAT_00431864,0x10,0,0);
        return 0;
      case 0x68:
        if (DAT_00431f4c != 2) {
          FUN_00414ba3(10,0);
          FUN_0040ecc2(&DAT_00431b10,param_1,1);
        }
        FUN_00407ec7();
        iVar4 = FUN_0040f38e();
        if (iVar4 != 0) {
          SendMessageA(DAT_00431864,0x111,0x65,0);
        }
        if (DAT_00431f4c != 2) {
          FUN_0040ecc2(&DAT_00431b10,DAT_00431864,0);
        }
        FUN_00407ec7();
        return 0;
      case 0x6b:
        SetFocus(param_1);
        if (DAT_00431a50 == 1) {
          return 0;
        }
        PostMessageA(param_1,0x300,0,0);
        DAT_00431f4c = 6;
        return 0;
      case 0x77:
        DAT_004283a4 = DAT_004283a4 + 1;
        if (DAT_004283a4 < 0xb) {
          FUN_0040f161(DAT_004283a4);
          for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
            *(int *)(&DAT_00430c38 + local_2c * 0x1a8) = local_2c;
            *(int *)(&DAT_00430c40 + local_2c * 0x1a8) = local_2c * 0x38 + 0x60;
            if ((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) {
              *(int *)(&DAT_00430c40 + local_2c * 0x1a8) =
                   *(int *)(&DAT_00430c40 + local_2c * 0x1a8) + -0x1c;
            }
          }
          FUN_0040f542(*(int **)(DAT_004283a4 * 4 + 0x431ac0),0x18,0x11a);
          for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
            *(int *)(&DAT_00430c38 + local_2c * 0x1a8) = local_2c;
            *(int *)(&DAT_00430c40 + local_2c * 0x1a8) = local_2c * 0x38 + 0x60;
            if ((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) {
              *(int *)(&DAT_00430c40 + local_2c * 0x1a8) =
                   *(int *)(&DAT_00430c40 + local_2c * 0x1a8) + -0x1c;
            }
          }
          DAT_00431fc0 = DAT_00431f7c + 4;
          FUN_0040ae15();
        }
        else {
          FUN_0040550d(3);
          SendMessageA(DAT_00432088,0x111,0x6b,0);
        }
      default:
        break;
      case 0xc9:
        if ((DAT_00431f4c != 2) && (DAT_0042881c == 0)) {
          DAT_00428818 = (uint)(DAT_00428818 == 0);
          FUN_0040f43e();
          if (DAT_00428818 == 0) {
            iVar4 = _rand();
            FUN_004147c8(iVar4 % 3 + 1);
          }
          else {
            InvalidateRect(DAT_00431864,(RECT *)0x0,0);
            UpdateWindow(DAT_00431864);
            FUN_00414755();
          }
          InvalidateRect(DAT_00431864,(RECT *)0x0,0);
          return 0;
        }
        SendMessageA(DAT_00431864,0x111,0x65,0);
        return 0;
      case 0x12e:
        FUN_00407ec7();
        FUN_0040576b();
        FUN_00407ec7();
        return 0;
      case 0x12f:
        SetFocus(param_1);
        WinHelpA(DAT_00431864,s_CHARMER_HLP_00428518,0xb,0);
        return 0;
      case 0x130:
        FUN_00405832();
        return 0;
      case 0x131:
        DAT_004283b4 = (uint)(DAT_004283b4 == 0);
        FUN_0040f43e();
        return 0;
      }
    }
    else {
      if (param_2 < 0x301) {
        if (param_2 == 0x300) {
          DAT_0042881c = 1;
          FUN_0040f43e();
          InvalidateRect(DAT_00431864,(RECT *)0x0,0);
          iVar4 = FUN_00402048(DAT_0042882c,local_18);
          if ((iVar4 == 0) || (9 < local_18[0])) {
            FUN_00414ba3(5,0);
            InvalidateRect(DAT_00431864,(RECT *)0x0,0);
          }
          else {
            FUN_0040ecc2(&DAT_00431b10,param_1,1);
            if (DAT_004283bc != 0) {
              FUN_004058a1();
            }
            FUN_004020e5(DAT_0042882c);
            DAT_00429218 = local_18[0];
            FUN_00405910();
            FUN_0040f14c();
          }
          return 0;
        }
        if (param_2 == 0x211) {
          DAT_00428820 = 1;
          InvalidateRect(param_1,(RECT *)0x0,0);
          return 0;
        }
        if (param_2 == 0x212) {
          DAT_00428820 = 0;
          InvalidateRect(param_1,(RECT *)0x0,0);
          return 0;
        }
        goto switchD_00411ecf_caseD_3;
      }
      if (param_2 < 0x310) {
        if (param_2 == 0x30f) {
LAB_00410f45:
          pHVar5 = GetDC(param_1);
          if (DAT_00432f3c != (HPALETTE)0x0) {
            SelectPalette(pHVar5,DAT_00432f3c,0);
            local_20 = RealizePalette(pHVar5);
          }
          ReleaseDC(param_1,pHVar5);
          if (local_20 == 0) {
            return 0;
          }
          InvalidateRect(param_1,(RECT *)0x0,1);
          return local_20;
        }
        if (param_2 != 0x301) goto switchD_00411ecf_caseD_3;
        DAT_00431f4c = 2;
        pHVar8 = GetActiveWindow();
        if (pHVar8 == param_1) {
          FUN_00407e94();
        }
      }
      else if (param_2 == 0x311) {
        if (param_3 != param_1) goto LAB_00410f45;
      }
      else {
        if (param_2 != 0x42b) {
          if (param_2 == 0x464) {
            if (param_3 == (HWND)0x0) {
              FUN_00407e94();
            }
            else if (DAT_00428500 == 0) {
              BVar9 = IsIconic(param_1);
              if (BVar9 == 0) {
                FUN_00407e94();
              }
              else {
                FUN_00407e94();
              }
              if (DAT_00428828 != 0) {
                SetActiveWindow(DAT_00430a34);
              }
            }
            else {
              DAT_00428500 = 0;
              FUN_00407e94();
            }
            FUN_00420adb((int)DAT_00430a44);
            return 0;
          }
          goto switchD_00411ecf_caseD_3;
        }
        if (DAT_00430a44 == (HWND)0x0) {
          return 0;
        }
        if (DAT_00428818 != 0) {
          return 0;
        }
        if ((DAT_004317d0 != 0) || (DAT_00430788 != 0)) {
          return 0;
        }
        if (DAT_00431f4c == 1) {
          return 0;
        }
        if (DAT_00431f4c == 2) {
          DAT_00431868 = DAT_00431868 + -1;
          if (DAT_00431868 < 1) {
            DAT_00431868 = 0x1e;
            FUN_0040e2c1(0x431868);
            pHVar5 = GetDC(param_1);
            SelectPalette(pHVar5,DAT_00432f3c,0);
            RealizePalette(pHVar5);
            FUN_00413a20(&DAT_00432f20,pHVar5);
            ReleaseDC(param_1,pHVar5);
          }
          return 0;
        }
        if (DAT_004307f8 != 0) {
          if (DAT_00431f4c == 6) {
            DAT_004307f8 = 0;
            FUN_0040e835(0x4307f8);
            FUN_00408670(param_1,0);
            return 0;
          }
          DAT_004307fc = DAT_004307fc + -1;
          if (DAT_004307fc < 1) {
            DAT_004307fc = 0x14;
            FUN_0040e729(&DAT_004307f8);
            pHVar5 = GetDC(param_1);
            SelectPalette(pHVar5,DAT_00432f3c,0);
            RealizePalette(pHVar5);
            if (DAT_004334ac != 0) {
              bVar1 = false;
              if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
                for (local_84 = 0; local_84 < DAT_004334ac; local_84 = local_84 + 1) {
                  FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_84 * 0x10));
                }
                DAT_004334ac = 0;
              }
              else {
                for (local_84 = 0; local_84 < DAT_004334ac; local_84 = local_84 + 1) {
                  if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_84 * 0x10)) &&
                     (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_84 * 0x10))) {
                    bVar1 = true;
                    break;
                  }
                }
                if (bVar1) {
                  for (local_84 = 0; local_84 < DAT_004334ac; local_84 = local_84 + 1) {
                    FUN_00413340(pHVar5,(int *)(&DAT_0043336c + local_84 * 0x10),
                                 *(int *)(&DAT_0043336c + local_84 * 0x10) - DAT_004334c4,
                                 *(int *)(&DAT_00433370 + local_84 * 0x10) - DAT_004334c8);
                  }
                }
                else {
                  for (local_84 = 0; local_84 < DAT_004334ac; local_84 = local_84 + 1) {
                    FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_84 * 0x10));
                  }
                }
                DAT_004334ac = 0;
              }
            }
            ReleaseDC(param_1,pHVar5);
          }
        }
        if (DAT_00431b10 != 0) {
          if (DAT_00431f4c == 6) {
            DAT_00431b10 = 0;
          }
          else {
            DAT_00431b14 = DAT_00431b14 + -1;
            if (DAT_00431b14 < 1) {
              DAT_00431b14 = 0x1e;
              DVar2 = GetTickCount();
              DAT_00431cfc = DVar2 / 0x37;
              if (DAT_00431d00 < DAT_00431cfc) {
                FUN_0040ecc2(&DAT_00431b10,param_1,0);
                DAT_00431b10 = 0;
              }
              else {
                FUN_0040ec3a(0x431b10);
                pHVar5 = GetDC(param_1);
                SelectPalette(pHVar5,DAT_00432f3c,0);
                RealizePalette(pHVar5);
                if (DAT_004334ac != 0) {
                  bVar1 = false;
                  if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
                    for (local_8c = 0; local_8c < DAT_004334ac; local_8c = local_8c + 1) {
                      FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_8c * 0x10));
                    }
                    DAT_004334ac = 0;
                  }
                  else {
                    for (local_8c = 0; local_8c < DAT_004334ac; local_8c = local_8c + 1) {
                      if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_8c * 0x10)) &&
                         (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_8c * 0x10))) {
                        bVar1 = true;
                        break;
                      }
                    }
                    if (bVar1) {
                      for (local_8c = 0; local_8c < DAT_004334ac; local_8c = local_8c + 1) {
                        FUN_00413340(pHVar5,(int *)(&DAT_0043336c + local_8c * 0x10),
                                     *(int *)(&DAT_0043336c + local_8c * 0x10) - DAT_004334c4,
                                     *(int *)(&DAT_00433370 + local_8c * 0x10) - DAT_004334c8);
                      }
                    }
                    else {
                      for (local_8c = 0; local_8c < DAT_004334ac; local_8c = local_8c + 1) {
                        FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_8c * 0x10));
                      }
                    }
                    DAT_004334ac = 0;
                  }
                }
                ReleaseDC(param_1,pHVar5);
              }
            }
          }
        }
        if ((((DAT_00431f80 != 0) || (DAT_00431f84 != 0)) || (DAT_00431f88 != 0)) &&
           (DAT_00431fa4 = DAT_00431fa4 + -1, DAT_00431fa4 < 1)) {
          DAT_00431fa4 = 0x19;
          FUN_00408bfa(&DAT_00431f48,param_1);
        }
        DAT_00431fa8 = DAT_00431fa8 + -1;
        if (DAT_00431fa8 < 1) {
          DAT_00431fa8 = 10;
          FUN_004081c2(param_1);
        }
        if (DAT_00431f4c != 3) {
          if (DAT_00431f4c == 4) {
            FUN_00409226(&DAT_00431f48,param_1);
            return 0;
          }
          if (DAT_00431f4c == 5) {
            FUN_00414ba3(8,0);
            FUN_0040998e();
            return 0;
          }
          if (DAT_00431f4c == 6) {
            return 0;
          }
        }
        if (DAT_00429574 != 0) {
          DAT_00429574 = 0;
          FUN_00414ba3(8,0);
          FUN_0040998e();
          return 0;
        }
        iVar4 = FUN_00407e48(6000);
        if (((iVar4 == 0x309) || (DAT_00429578 != 0)) && (DAT_00429578 = 0, DAT_004307f8 == 0)) {
          FUN_00414ba3(3,0);
          DAT_004307f8 = 1;
          FUN_0041ad4a(&DAT_00430ae8,0x225,0x12d,1);
          _DAT_00430800 = 0xffffffff;
          if (DAT_004283b4 != 0) {
            FUN_0040550d(2);
          }
        }
        if (((DAT_00429570 != 0) ||
            ((iVar4 = FUN_00407e48((9 - DAT_00431f5c) * 200 + 4000), iVar4 == 0x4d &&
             (0 < DAT_00431f5c)))) && (DAT_00429570 = 0, DAT_00431b10 == 0)) {
          FUN_00414ba3(9,0);
          DAT_00431b10 = 1;
          _DAT_00431b18 = 0x26;
          DVar2 = GetTickCount();
          DAT_00431cfc = DVar2 / 0x37;
          DAT_00431d00 = DAT_00431cfc + 0x10e;
          if (DAT_004283b4 != 0) {
            FUN_0040550d(1);
          }
        }
        local_2c = 0;
        while ((local_2c < 7 &&
               (FUN_0040c827(&DAT_00430c38 + local_2c * 0x1a8,local_2c), DAT_00431f4c == 3))) {
          local_2c = local_2c + 1;
        }
        FUN_0040dc76();
        pHVar5 = GetDC(param_1);
        SelectPalette(pHVar5,DAT_00432f3c,0);
        RealizePalette(pHVar5);
        if (DAT_004334ac != 0) {
          bVar1 = false;
          if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
            for (local_94 = 0; local_94 < DAT_004334ac; local_94 = local_94 + 1) {
              FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_94 * 0x10));
            }
            DAT_004334ac = 0;
          }
          else {
            for (local_94 = 0; local_94 < DAT_004334ac; local_94 = local_94 + 1) {
              if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_94 * 0x10)) &&
                 (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_94 * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_94 = 0; local_94 < DAT_004334ac; local_94 = local_94 + 1) {
                FUN_00413340(pHVar5,(int *)(&DAT_0043336c + local_94 * 0x10),
                             *(int *)(&DAT_0043336c + local_94 * 0x10) - DAT_004334c4,
                             *(int *)(&DAT_00433370 + local_94 * 0x10) - DAT_004334c8);
              }
            }
            else {
              for (local_94 = 0; local_94 < DAT_004334ac; local_94 = local_94 + 1) {
                FUN_00413270(pHVar5,(int *)(&DAT_0043336c + local_94 * 0x10));
              }
            }
            DAT_004334ac = 0;
          }
        }
        ReleaseDC(param_1,pHVar5);
      }
    }
    goto LAB_0041203d;
  }
  if (param_2 == 0xf) {
    pHVar5 = BeginPaint(param_1,&local_70);
    if ((((DAT_00428818 == 0) &&
         (((DAT_00428820 == 0 || (DAT_00431f4c == 2)) || (DAT_0042881c != 0)))) &&
        (((DAT_00430a44 != (HWND)0x0 || (DAT_00431f4c == 2)) || (DAT_0042881c != 0)))) &&
       (((DAT_004317d0 == 0 || (DAT_00431f4c == 2)) || (DAT_0042881c != 0)))) {
      if (DAT_0042881c != 0) {
        SelectPalette(pHVar5,DAT_00432f3c,0);
        RealizePalette(pHVar5);
        local_18[1] = 0;
        local_18[3] = 600;
        local_18[2] = 0;
        local_18[4] = 0x1d;
        pHVar6 = CreateCompatibleDC(pHVar5);
        pvVar7 = SelectObject(pHVar6,DAT_004334d0);
        BitBlt(pHVar5,0,0,0x259,0x1e,pHVar6,0,0,0xcc0020);
        SelectObject(pHVar6,pvVar7);
        DeleteDC(pHVar6);
        GdiFlush();
        local_18[1] = 0;
        local_18[3] = 0x4f;
        local_18[2] = 0x1e;
        local_18[4] = 400;
        pHVar6 = CreateCompatibleDC(pHVar5);
        pvVar7 = SelectObject(pHVar6,DAT_004334d0);
        BitBlt(pHVar5,0,0x1e,0x50,0x173,pHVar6,0,0x1e,0xcc0020);
        SelectObject(pHVar6,pvVar7);
        DeleteDC(pHVar6);
        GdiFlush();
        local_18[1] = 0x1f0;
        local_18[3] = 600;
        local_18[2] = 0x1e;
        local_18[4] = 400;
        pHVar6 = CreateCompatibleDC(pHVar5);
        pvVar7 = SelectObject(pHVar6,DAT_004334d0);
        BitBlt(pHVar5,0x1f0,0x1e,0x69,0x173,pHVar6,0x1f0,0x1e,0xcc0020);
        SelectObject(pHVar6,pvVar7);
        DeleteDC(pHVar6);
        GdiFlush();
        local_18[1] = 0x1e;
        local_18[3] = 0x1f0;
        local_18[2] = 0x172;
        local_18[4] = 400;
        pHVar6 = CreateCompatibleDC(pHVar5);
        pvVar7 = SelectObject(pHVar6,DAT_004334d0);
        BitBlt(pHVar5,0x1e,0x172,0x1d3,0x1f,pHVar6,0x1e,0x172,0xcc0020);
        SelectObject(pHVar6,pvVar7);
        DeleteDC(pHVar6);
        GdiFlush();
        FUN_0041427a(pHVar5,DAT_00432014,0x50,0x1e);
        EndPaint(param_1,&local_70);
        return 0;
      }
      SelectPalette(pHVar5,DAT_00432f3c,0);
      RealizePalette(pHVar5);
      cy = DAT_00432f30;
      iVar4 = DAT_00432f2c;
      DAT_004334ac = 0;
      pHVar6 = CreateCompatibleDC(pHVar5);
      pvVar7 = SelectObject(pHVar6,DAT_004334d0);
      BitBlt(pHVar5,0,0,iVar4,cy,pHVar6,0,0,0xcc0020);
      SelectObject(pHVar6,pvVar7);
      DeleteDC(pHVar6);
      GdiFlush();
      EndPaint(param_1,&local_70);
      return 0;
    }
    SelectPalette(pHVar5,DAT_00432f3c,0);
    RealizePalette(pHVar5);
    local_18[1] = 0;
    local_18[3] = 600;
    local_18[2] = 0;
    local_18[4] = 0x1d;
    pHVar6 = CreateCompatibleDC(pHVar5);
    pvVar7 = SelectObject(pHVar6,DAT_004334d0);
    BitBlt(pHVar5,0,0,0x259,0x1e,pHVar6,0,0,0xcc0020);
    SelectObject(pHVar6,pvVar7);
    DeleteDC(pHVar6);
    GdiFlush();
    local_18[1] = 0;
    local_18[3] = 0x4f;
    local_18[2] = 0x1e;
    local_18[4] = 400;
    pHVar6 = CreateCompatibleDC(pHVar5);
    pvVar7 = SelectObject(pHVar6,DAT_004334d0);
    BitBlt(pHVar5,0,0x1e,0x50,0x173,pHVar6,0,0x1e,0xcc0020);
    SelectObject(pHVar6,pvVar7);
    DeleteDC(pHVar6);
    GdiFlush();
    local_18[1] = 0x1f0;
    local_18[3] = 600;
    local_18[2] = 0x1e;
    local_18[4] = 400;
    pHVar6 = CreateCompatibleDC(pHVar5);
    pvVar7 = SelectObject(pHVar6,DAT_004334d0);
    BitBlt(pHVar5,0x1f0,0x1e,0x69,0x173,pHVar6,0x1f0,0x1e,0xcc0020);
    SelectObject(pHVar6,pvVar7);
    DeleteDC(pHVar6);
    GdiFlush();
    local_18[1] = 0x1e;
    local_18[3] = 0x1f0;
    local_18[2] = 0x172;
    local_18[4] = 400;
    pHVar6 = CreateCompatibleDC(pHVar5);
    pvVar7 = SelectObject(pHVar6,DAT_004334d0);
    BitBlt(pHVar5,0x1e,0x172,0x1d3,0x1f,pHVar6,0x1e,0x172,0xcc0020);
    SelectObject(pHVar6,pvVar7);
    DeleteDC(pHVar6);
    GdiFlush();
    FUN_0041427a(pHVar5,DAT_00431860,0x50,0x1e);
    EndPaint(param_1,&local_70);
    return 0;
  }
  switch(param_2) {
  case 1:
    FUN_00405340(param_1);
    for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
      *(int *)(&DAT_00430c38 + local_2c * 0x1a8) = local_2c;
      *(int *)(&DAT_00430c40 + local_2c * 0x1a8) = local_2c * 0x38 + 0x60;
      if ((DAT_00431f78 == 1) || (DAT_00431f78 == 3)) {
        *(int *)(&DAT_00430c40 + local_2c * 0x1a8) =
             *(int *)(&DAT_00430c40 + local_2c * 0x1a8) + -0x1c;
      }
    }
    FUN_0040d139(0x431fb8);
    UVar10 = FUN_00420600(param_1,param_2,(WPARAM)param_3,param_4);
    break;
  case 2:
    if (DAT_00431fb0 != (int *)0x0) {
      GlobalFree(DAT_00431fb0);
    }
    WinHelpA(DAT_00431864,s_CHARMER_HLP_00428518,2,0);
    FUN_00414cbe();
    FUN_00405383(param_1);
    PostQuitMessage(0);
    UVar10 = 0;
    break;
  default:
    goto switchD_00411ecf_caseD_3;
  case 5:
    if (param_3 == (HWND)0x0) {
LAB_00411ca3:
      PostMessageA(param_1,0x464,1,param_4);
    }
    else if (param_3 == (HWND)0x1) {
      PostMessageA(param_1,0x464,0,param_4);
    }
    else if (param_3 == (HWND)0x2) goto LAB_00411ca3;
LAB_0041203d:
    UVar10 = 0;
    break;
  case 7:
    if (DAT_00428828 == 0) {
      UVar10 = FUN_00420600(param_1,param_2,(WPARAM)param_3,param_4);
    }
    else {
      SetActiveWindow(DAT_00430a34);
      UVar10 = 0;
    }
  }
  return UVar10;
}


// ==== FUN_0041204b @ 0041204b

int __cdecl FUN_0041204b(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0041206c @ 0041206c

int __cdecl FUN_0041206c(int param_1)

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


// ==== FUN_004120a7 @ 004120a7

ATOM __cdecl FUN_004120a7(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_0040f6f0;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = param_1;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(5);
  local_2c.hIcon = LoadIconA(param_1,&DAT_00429874);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = PTR_s_CharmerWnd_00428510;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1;
}


// ==== FUN_00412125 @ 00412125

undefined4 FUN_00412125(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_CharmerWnd_00428510,(LPCSTR)0x0);
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


// ==== FUN_004121a2 @ 004121a2

bool __cdecl FUN_004121a2(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_004121f8 @ 004121f8

/* WARNING: Removing unreachable block (ram,0x00412b98) */
/* WARNING: Removing unreachable block (ram,0x00412ba2) */
/* WARNING: Removing unreachable block (ram,0x00412ba7) */
/* WARNING: Removing unreachable block (ram,0x00412bb4) */
/* WARNING: Removing unreachable block (ram,0x00412bc3) */
/* WARNING: Removing unreachable block (ram,0x004128f4) */
/* WARNING: Removing unreachable block (ram,0x00412901) */
/* WARNING: Removing unreachable block (ram,0x00412906) */
/* WARNING: Removing unreachable block (ram,0x00412922) */
/* WARNING: Removing unreachable block (ram,0x00412913) */
/* WARNING: Removing unreachable block (ram,0x004127ce) */
/* WARNING: Removing unreachable block (ram,0x004127db) */
/* WARNING: Removing unreachable block (ram,0x004127e0) */
/* WARNING: Removing unreachable block (ram,0x004127fc) */
/* WARNING: Removing unreachable block (ram,0x004127ed) */
/* WARNING: Removing unreachable block (ram,0x0041270d) */
/* WARNING: Removing unreachable block (ram,0x004126a8) */
/* WARNING: Removing unreachable block (ram,0x004126b5) */
/* WARNING: Removing unreachable block (ram,0x004126ba) */
/* WARNING: Removing unreachable block (ram,0x004126d6) */
/* WARNING: Removing unreachable block (ram,0x004126c7) */
/* WARNING: Removing unreachable block (ram,0x00412670) */
/* WARNING: Removing unreachable block (ram,0x00412833) */
/* WARNING: Removing unreachable block (ram,0x00412796) */
/* WARNING: Removing unreachable block (ram,0x00412959) */
/* WARNING: Removing unreachable block (ram,0x004128bc) */
/* WARNING: Removing unreachable block (ram,0x00412bf6) */
/* WARNING: Removing unreachable block (ram,0x00412b63) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004121f8(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  ATOM AVar2;
  int iVar3;
  DWORD DVar4;
  undefined3 extraout_var;
  HCURSOR hCursor;
  undefined2 extraout_var_01;
  LPCSTR pCVar5;
  HGLOBAL pvVar6;
  undefined3 extraout_var_00;
  BOOL BVar7;
  undefined4 *unaff_FS_OFFSET;
  LPVOID local_a4;
  undefined4 local_a0;
  uint local_9c [6];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64 [4];
  tagMSG local_54;
  HDC local_34;
  undefined4 local_30;
  HCURSOR local_28;
  int local_24;
  HDC local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00412dc8;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_1c = 0;
  local_18 = 0;
  DAT_00431e20 = param_1;
  iVar3 = FUN_00412125();
  if (iVar3 != 0) {
    FUN_00412dd2();
    return;
  }
  CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_CharmerGameMtx_0042987c);
  DVar4 = GetLastError();
  if (DVar4 == 0xb7) {
    FUN_00412dd2();
    return;
  }
  bVar1 = FUN_004121a2(0x600000);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00412dd2();
    return;
  }
  local_20 = GetDC((HWND)0x0);
  iVar3 = GetDeviceCaps(local_20,0xc);
  if (iVar3 < 8) {
    ReleaseDC((HWND)0x0,local_20);
    FUN_00412dd2();
    return;
  }
  ReleaseDC((HWND)0x0,local_20);
  hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  local_28 = SetCursor(hCursor);
  FUN_00407e94();
  AVar2 = FUN_004120a7(param_1);
  if (CONCAT22(extraout_var_01,AVar2) == 0) {
    SetCursor(local_28);
    FUN_00412dd2();
    return;
  }
  FUN_0040184d();
  FUN_004018e7((uint *)s_CHARMER_DLL_00428618);
  FUN_00401a95((uint *)s_CHARMER1_DLL_00428718);
  FUN_00401865((uint *)s_MSPuzzle_dat_004283f0);
  FUN_00401a95((uint *)s_CHARMER_HLP_00428518);
  FUN_0040167a();
  FUN_00401694(DAT_00431e20);
  FUN_004016d3(s_CHARMER1_DLL_00428718);
  FUN_004016d3(s_CHARMER_DLL_00428618);
  FUN_00407e2d();
  FUN_0040f34d();
  FUN_00414ed7();
  InitCommonControls();
  DAT_00431fb0 = FUN_0041452c(s_STARTBMP_0042988c);
  if (DAT_00431fb0 == (int *)0x0) {
    FUN_00414cbe();
    SetCursor(local_28);
    FUN_00412dd2();
    return;
  }
  for (local_24 = 1; local_24 < 0xb; local_24 = local_24 + 1) {
    pCVar5 = FUN_004140e0((uint *)s_LEVEL_00429898,local_24,2);
    pvVar6 = FUN_0041452c(pCVar5);
    *(HGLOBAL *)(local_24 * 4 + 0x431ac0) = pvVar6;
  }
  FUN_00420440(DAT_00431fb0);
  iVar3 = FUN_00412de3(param_1,param_4);
  if (iVar3 == 0) {
    if (DAT_00431fb0 != (int *)0x0) {
      GlobalFree(DAT_00431fb0);
    }
    FUN_004205b8();
    FUN_00414cbe();
    SetCursor(local_28);
    FUN_00412dd2();
    return;
  }
  local_34 = GetDC((HWND)0x0);
  DAT_00431860 = FUN_00414310(local_34,s_PAUSEBMP_004298a0);
  DAT_00432014 = FUN_00414310(local_34,s_GAMEOVERBMP_004298ac);
  ReleaseDC((HWND)0x0,local_34);
  FUN_0040dfae(0x431868);
  FUN_0040e416(0x4307f8);
  FUN_0040e927(0x431b10);
  FUN_00421360((uint *)&DAT_004307a8,(uint *)s_boxcover_004298b8);
  _DAT_004307c0 = 1;
  _DAT_004307c4 = 0;
  FUN_00414000(&DAT_004307a0);
  FUN_00421360((uint *)&DAT_004317e8,(uint *)s_boxcover1_004298c4);
  _DAT_00431800 = 1;
  _DAT_00431804 = 0;
  FUN_00414000(&DAT_004317e0);
  FUN_00421360((uint *)&DAT_00431e30,(uint *)s_flutes_004298d0);
  _DAT_00431e48 = 1;
  _DAT_00431e4c = 0;
  FUN_00414000(&DAT_00431e28);
  FUN_00421360((uint *)&DAT_00431dd0,(uint *)s_hearts_004298d8);
  _DAT_00431de8 = 1;
  _DAT_00431dec = 0;
  FUN_00414000(&DAT_00431dc8);
  FUN_00421360((uint *)&DAT_00430af0,(uint *)s_DOORO_004298e0);
  _DAT_00430b08 = 1;
  _DAT_00430b0c = 0;
  FUN_00414000(&DAT_00430ae8);
  FUN_00421360((uint *)&DAT_00430aa0,(uint *)s_DOORM_004298e8);
  _DAT_00430ab8 = 1;
  _DAT_00430abc = 0;
  FUN_00414000(&DAT_00430a98);
  FUN_00421360((uint *)&DAT_00430a50,(uint *)s_DOORC_004298f0);
  DAT_00430a68 = 1;
  DAT_00430a6c = 0;
  if ((DAT_00430a48 == (LPVOID)0x0) &&
     (DAT_00430a48 = FUN_004145d6(&DAT_00430a50), DAT_00430a48 != (LPVOID)0x0)) {
    DAT_00430a4c = 1;
  }
  FUN_00421360((uint *)&DAT_00430be8,(uint *)s_LIGHT_004298f8);
  DAT_00430c00 = 1;
  DAT_00430c04 = 0;
  if ((DAT_00430be0 == (LPVOID)0x0) &&
     (DAT_00430be0 = FUN_004145d6(&DAT_00430be8), DAT_00430be0 != (LPVOID)0x0)) {
    DAT_00430be4 = 1;
  }
  FUN_00421360((uint *)&DAT_00430b48,(uint *)s_LIGHT1_00429900);
  DAT_00430b60 = 1;
  DAT_00430b64 = 0;
  if ((DAT_00430b40 == (LPVOID)0x0) &&
     (DAT_00430b40 = FUN_004145d6(&DAT_00430b48), DAT_00430b40 != (LPVOID)0x0)) {
    DAT_00430b44 = 1;
  }
  FUN_00421360((uint *)&DAT_00430b98,(uint *)s_LIGHT2_00429908);
  _DAT_00430bb0 = 1;
  _DAT_00430bb4 = 0;
  FUN_00414000(&DAT_00430b90);
  bVar1 = FUN_0041d8a0(&DAT_00430778,(LPCSTR)0x3e8);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    FUN_004205b8();
    SetCursor(local_28);
    FUN_00412dd2();
    return;
  }
  _DAT_00430784 = 0x4f;
  DAT_00432018 = &DAT_00430778;
  DAT_0043201c = 9;
  DAT_00432020 = 0x166;
  FUN_00407ee6(1);
  DAT_004334c4 = 600;
  SetCursor(local_28);
  FUN_00413ef0(&local_a4);
  local_64[0] = 0;
  local_64[1] = 0;
  local_64[2] = 0;
  local_64[3] = 0;
  local_8 = 1;
  FUN_00413f90(&local_a4);
  FUN_00413e90(local_64);
  local_7c = 0;
  local_78 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  local_74 = 0;
  local_8 = 2;
  FUN_00421360(local_9c,(uint *)s_SNAKEBAS_00429910);
  local_84 = 1;
  local_80 = 0;
  if ((local_a4 == (LPVOID)0x0) &&
     (local_a4 = FUN_004145d6((LPCSTR)local_9c), local_a4 != (LPVOID)0x0)) {
    local_a0 = 1;
  }
  FUN_0041ad4a(&local_a4,0xdb,0x132,1);
  local_8 = 0xffffffff;
  FUN_00412dbc();
  UpdateWindow(DAT_00431864);
  FUN_0040e2c1(0x431868);
  local_34 = GetDC(DAT_00431864);
  SelectPalette(local_34,DAT_00432f3c,0);
  RealizePalette(local_34);
  FUN_00413a20(&DAT_00432f20,local_34);
  ReleaseDC(DAT_00431864,local_34);
  DAT_00431868 = 0x1e;
  DAT_00431f4c = 2;
  FUN_0040f43e();
  local_30 = 0;
  SetTimer(DAT_00431864,1,100,(TIMERPROC)0x0);
  while( true ) {
    while (BVar7 = PeekMessageA(&local_54,(HWND)0x0,0,0,1), BVar7 == 0) {
      if (DAT_00430a44 == 0) {
        WaitMessage();
      }
      else {
        SendMessageA(DAT_00431864,0x42b,0,0);
        Sleep(10);
      }
    }
    if (local_54.message == 0x12) break;
    if ((DAT_00431864 == (HWND)0x0) ||
       (iVar3 = TranslateAcceleratorA(DAT_00431864,DAT_00430a38,&local_54), iVar3 == 0)) {
      TranslateMessage(&local_54);
      DispatchMessageA(&local_54);
    }
  }
  FUN_00414cbe();
  FUN_00412dd2();
  return;
}


// ==== FUN_00412dbc @ 00412dbc

void FUN_00412dbc(void)

{
  int unaff_EBP;
  
  FUN_00413140((undefined4 *)(unaff_EBP + -0xa0));
  return;
}


// ==== FUN_00412dd2 @ 00412dd2

void FUN_00412dd2(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00412de3 @ 00412de3

undefined4 __cdecl FUN_00412de3(undefined4 param_1,int param_2)

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
  
  DAT_00430798 = FUN_0040154e(DAT_00431e20,s_MainMenuPlayed_0042991c);
  DAT_00432038 = FUN_0040154e(DAT_00431e20,s_MainMenu_0042992c);
  DAT_00430a38 = FUN_0040148b(param_1,s_ACCELERATORS_1_00429938);
  if (DAT_00430a38 == (HACCEL)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_004015b0(DAT_00431e20,100,local_84,0x78);
    DVar2 = GetVersion();
    local_88 = (byte)DVar2;
    if (local_88 < 4) {
      iVar3 = GetSystemMetrics(5);
      DAT_00430c30 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(6);
      iVar4 = GetSystemMetrics(0xf);
      iVar5 = GetSystemMetrics(4);
      DAT_004317dc = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00430c30;
      iVar4 = DAT_004317dc;
      pHVar8 = DAT_00432038;
      pHVar9 = DAT_00431e20;
      iVar5 = FUN_0041206c(DAT_004317dc);
      iVar6 = FUN_0041204b(DAT_00430c30);
      DAT_00431864 = CreateWindowExA(0,PTR_s_CharmerWnd_00428510,local_84,0xca0000,iVar6,iVar5,iVar3
                                     ,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    else {
      iVar3 = GetSystemMetrics(7);
      DAT_00430c30 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(8);
      iVar4 = GetSystemMetrics(0xf);
      iVar5 = GetSystemMetrics(4);
      DAT_004317dc = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00430c30;
      iVar4 = DAT_004317dc;
      pHVar8 = DAT_00432038;
      pHVar9 = DAT_00431e20;
      iVar5 = FUN_0041206c(DAT_004317dc);
      iVar6 = FUN_0041204b(DAT_00430c30);
      DAT_00431864 = CreateWindowExA(0x100,PTR_s_CharmerWnd_00428510,local_84,0xca0000,iVar6,iVar5,
                                     iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    DAT_00432088 = DAT_00431864;
    ShowWindow(DAT_00431864,param_2);
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_00412fe0 @ 00412fe0

void __fastcall FUN_00412fe0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00421c00((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00413050 @ 00413050

void __fastcall FUN_00413050(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== FUN_00413090 @ 00413090

void __fastcall FUN_00413090(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00413128;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  local_8 = 0xffffffff;
  FUN_0041311f();
  FUN_00413132();
  return;
}


// ==== FUN_0041311f @ 0041311f

void FUN_0041311f(void)

{
  int unaff_EBP;
  
  FUN_00413050(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00413132 @ 00413132

void FUN_00413132(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00413140 @ 00413140

void __fastcall FUN_00413140(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00413255;
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
    FUN_00421c00((void *)param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00413240();
  local_8 = 0xffffffff;
  FUN_0041324c();
  FUN_0041325f();
  return;
}


// ==== FUN_00413240 @ 00413240

void FUN_00413240(void)

{
  int unaff_EBP;
  
  FUN_00412fe0((int *)(*(int *)(unaff_EBP + -0x18) + 0x40));
  return;
}


// ==== FUN_0041324c @ 0041324c

void FUN_0041324c(void)

{
  int unaff_EBP;
  
  FUN_00413090(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0041325f @ 0041325f

void FUN_0041325f(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00413270 @ 00413270

void FUN_00413270(HDC param_1,int *param_2)

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
  h = SelectObject(hdc,DAT_004334d0);
  BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00413340 @ 00413340

void FUN_00413340(HDC param_1,int *param_2,int param_3,int param_4)

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
  h = SelectObject(hdc,DAT_004334d0);
  BitBlt(param_1,param_3,param_4,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x1,y1,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00413410 @ 00413410

void __cdecl
FUN_00413410(HDC param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7,int param_8)

{
  HDC hdc;
  HGDIOBJ h;
  
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_004334d0);
  BitBlt(param_1,param_2,param_3,param_4,param_5,hdc,param_7,param_8,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00413490 @ 00413490

int __fastcall FUN_00413490(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413586;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_
            ((void *)(param_1 + 0x30),0x10,2,CReObject::CReObject,FUN_00412fe0);
  local_8 = 0;
  _eh_vector_constructor_iterator_((void *)(param_1 + 0x54),0x18,0xd,FUN_004136c0,FUN_00413750);
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== CReObject @ 004135a0

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


// ==== FUN_004135e0 @ 004135e0

void __fastcall FUN_004135e0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_004136a0;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8._1_3_ = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  for (local_14 = 0; local_14 < *(int *)(param_1 + 0x50); local_14 = local_14 + 1) {
  }
  local_8._0_1_ = 1;
  FUN_00413665();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00413674();
  local_8 = 0xffffffff;
  FUN_0041368a();
  FUN_004136aa();
  return;
}


// ==== FUN_00413665 @ 00413665

void FUN_00413665(void)

{
  int unaff_EBP;
  
  FUN_00412fe0((int *)(*(int *)(unaff_EBP + -0x14) + 400));
  return;
}


// ==== FUN_00413674 @ 00413674

void FUN_00413674(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_
            ((void *)(*(int *)(unaff_EBP + -0x14) + 0x54),0x18,0xd,FUN_00413750);
  return;
}


// ==== FUN_0041368a @ 0041368a

void FUN_0041368a(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x14) + 0x30),0x10,2,FUN_00412fe0);
  return;
}


// ==== FUN_004136aa @ 004136aa

void FUN_004136aa(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004136c0 @ 004136c0

int __fastcall FUN_004136c0(int param_1)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *unaff_FS_OFFSET = uVar1;
  return param_1;
}


// ==== FUN_00413750 @ 00413750

void FUN_00413750(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041379a;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_0041378e();
  FUN_004137a4();
  return;
}


// ==== FUN_0041378e @ 0041378e

void FUN_0041378e(void)

{
  int unaff_EBP;
  
  FUN_00412fe0((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}


// ==== FUN_004137a4 @ 004137a4

void FUN_004137a4(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004137c0 @ 004137c0

undefined4 * __fastcall FUN_004137c0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


// ==== FUN_00413800 @ 00413800

void FUN_00413800(void)

{
  return;
}


// ==== FUN_00413820 @ 00413820

undefined4 * __fastcall FUN_00413820(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004139fd;
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
    FUN_00421c00((void *)param_1[0x10]);
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


// ==== FUN_00413a20 @ 00413a20

void __thiscall FUN_00413a20(void *this,HDC param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int y1;
  int x1;
  bool bVar9;
  HDC pHVar10;
  HGDIOBJ pvVar11;
  int local_c;
  
  if (*(int *)((int)this + 0x58c) != 0) {
    bVar9 = false;
    if ((*(int *)((int)this + 0x5a4) == 0) && (*(int *)((int)this + 0x5a8) == 0)) {
      for (local_c = 0; local_c < *(int *)((int)this + 0x58c); local_c = local_c + 1) {
        iVar1 = *(int *)(local_c * 0x10 + 0x458 + (int)this);
        iVar2 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
        iVar3 = *(int *)(local_c * 0x10 + 0x454 + (int)this);
        iVar4 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
        iVar5 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
        iVar6 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
        pHVar10 = CreateCompatibleDC(param_1);
        pvVar11 = SelectObject(pHVar10,DAT_004334d0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar10,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar10,pvVar11);
        DeleteDC(pHVar10);
        GdiFlush();
      }
      *(undefined4 *)((int)this + 0x58c) = 0;
    }
    else {
      for (local_c = 0; local_c < *(int *)((int)this + 0x58c); local_c = local_c + 1) {
        if ((*(int *)((int)this + 0x5a4) <= *(int *)(local_c * 0x10 + 0x44c + (int)this)) &&
           (*(int *)((int)this + 0x5a8) <= *(int *)(local_c * 0x10 + 0x450 + (int)this))) {
          bVar9 = true;
          break;
        }
      }
      if (bVar9) {
        for (local_c = 0; local_c < *(int *)((int)this + 0x58c); local_c = local_c + 1) {
          iVar1 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
          iVar2 = *(int *)((int)this + 0x5a8);
          iVar3 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
          iVar4 = *(int *)((int)this + 0x5a4);
          iVar5 = *(int *)(local_c * 0x10 + 0x458 + (int)this);
          iVar6 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
          iVar7 = *(int *)(local_c * 0x10 + 0x454 + (int)this);
          iVar8 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
          y1 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
          x1 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
          pHVar10 = CreateCompatibleDC(param_1);
          pvVar11 = SelectObject(pHVar10,DAT_004334d0);
          BitBlt(param_1,iVar3 - iVar4,iVar1 - iVar2,(iVar7 - iVar8) + 1,(iVar5 - iVar6) + 1,pHVar10
                 ,x1,y1,0xcc0020);
          SelectObject(pHVar10,pvVar11);
          DeleteDC(pHVar10);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < *(int *)((int)this + 0x58c); local_c = local_c + 1) {
          iVar1 = *(int *)(local_c * 0x10 + 0x458 + (int)this);
          iVar2 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
          iVar3 = *(int *)(local_c * 0x10 + 0x454 + (int)this);
          iVar4 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
          iVar5 = *(int *)(local_c * 0x10 + 0x450 + (int)this);
          iVar6 = *(int *)(local_c * 0x10 + 0x44c + (int)this);
          pHVar10 = CreateCompatibleDC(param_1);
          pvVar11 = SelectObject(pHVar10,DAT_004334d0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar10,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar10,pvVar11);
          DeleteDC(pHVar10);
          GdiFlush();
        }
      }
      *(undefined4 *)((int)this + 0x58c) = 0;
    }
  }
  return;
}


// ==== FUN_00413e90 @ 00413e90

void __fastcall FUN_00413e90(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00421c00((void *)*param_1);
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00413ef0 @ 00413ef0

undefined4 * __fastcall FUN_00413ef0(undefined4 *param_1)

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


// ==== FUN_00413f90 @ 00413f90

void __fastcall FUN_00413f90(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  return;
}


// ==== FUN_00414000 @ 00414000

undefined4 __fastcall FUN_00414000(int *param_1)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if (param_1[8] == 0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    if (param_1[9] == 0) {
      if (param_1[8] == 1) {
        pvVar2 = FUN_004145d6((LPCSTR)(param_1 + 2));
        *param_1 = (int)pvVar2;
      }
      else {
        pvVar2 = FUN_004145d6((LPCSTR)param_1[7]);
        *param_1 = (int)pvVar2;
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


// ==== FUN_004140e0 @ 004140e0

undefined * __cdecl FUN_004140e0(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_00421360((uint *)&DAT_00432498,param_1);
  sVar1 = _strlen(&DAT_00432498);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_00432497)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_00432498)[sVar1 + param_3] = 0;
  return &DAT_00432498;
}


// ==== FUN_004141a9 @ 004141a9

void __cdecl FUN_004141a9(int param_1)

{
  if (param_1 == 0) {
    DAT_00432040 = GetDC(DAT_00432088);
  }
  else {
    DAT_00432040 = BeginPaint(DAT_00432088,(LPPAINTSTRUCT)&DAT_00432048);
  }
  return;
}


// ==== FUN_004141ef @ 004141ef

void __cdecl FUN_004141ef(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_00432088,DAT_00432040);
  }
  else {
    EndPaint(DAT_00432088,(PAINTSTRUCT *)&DAT_00432048);
  }
  return;
}


// ==== FUN_00414231 @ 00414231

bool __cdecl FUN_00414231(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_0041427a @ 0041427a

bool __cdecl FUN_0041427a(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_00414310 @ 00414310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_00414310(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_00401078(DAT_00431e20,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_0042994c = 0;
        _DAT_00432090 = 0x300;
        _DAT_00432092 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_00432094)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_00432095)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_00432096)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_00432097)[local_28 * 4] = 0;
        }
        if (DAT_00429948 == (HPALETTE)0x0) {
          DAT_00429948 = CreatePalette((LOGPALETTE *)&DAT_00432090);
        }
      }
      hPal = SelectPalette(param_1,DAT_00432f3c,0);
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


// ==== FUN_0041452c @ 0041452c

HGLOBAL __cdecl FUN_0041452c(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_00401078(DAT_00431e20,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_004145d6 @ 004145d6

LPVOID __cdecl FUN_004145d6(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_00431e20,param_1,s_SPRITE_00429950,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_00414628 @ 00414628

LPVOID __cdecl FUN_00414628(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_00401078(DAT_00431e20,param_1,s_SPRFONT_00429958,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_00414680 @ 00414680

undefined4 FUN_00414680(void)

{
  return 1;
}


// ==== FUN_00414698 @ 00414698

void FUN_00414698(void)

{
  return;
}


// ==== FUN_004146b0 @ 004146b0

void FUN_004146b0(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0043251c == 1) || (DAT_0043251c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00429af8,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00429af8,0x804,2,(DWORD_PTR)local_c);
    DAT_00429af8 = 0;
    Sleep(1);
    DAT_0043251c = 0;
  }
  return;
}


// ==== FUN_00414755 @ 00414755

void FUN_00414755(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00429964 != 0) && (DAT_0043251c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00429af8,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0043251c = 3;
  }
  return;
}


// ==== FUN_004147c8 @ 004147c8

void __cdecl FUN_004147c8(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00429964 != 0) {
    if (DAT_0043251c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_00429af8,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_00429af8,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_004148a5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0043251c = 1;
    }
    else {
      FUN_004148a5(param_1);
    }
  }
  return;
}


// ==== FUN_004148a5 @ 004148a5

void __cdecl FUN_004148a5(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00429964 == 0) {
    FUN_004146b0();
  }
  else {
    if (((DAT_00432518 == param_1) && (0 < param_1)) && (DAT_0043251c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_00429af8,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0043251c != 4) {
      FUN_004146b0();
    }
    if (DAT_00429964 != 0) {
      if (0 < param_1) {
        DAT_00432518 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00432518;
      }
      if ((0 < param_1) && (param_1 < 4)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00432520 + param_1 * 0x100;
        local_20 = s_sequencer_00429afc;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_00429af8 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_00429af8;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_00429af8 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00429af8,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0043251c = 1;
          }
          else {
            DAT_0043251c = 4;
          }
        }
        else {
          DAT_0043251c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_00414a85 @ 00414a85

void FUN_00414a85(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_00429964 != 0) {
    if (DAT_0043251c == 1) {
      if (DAT_00429af8 == 0) {
        DAT_0043251c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_00429af8,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00429af8,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0043251c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0043251c = 4;
        }
      }
    }
    else if (DAT_0043251c == 4) {
      FUN_004148a5(-1);
    }
  }
  return;
}


// ==== FUN_00414ba3 @ 00414ba3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00414ba3(int param_1,int param_2)

{
  DWORD DVar1;
  
  if (DAT_00429960 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00429968) {
      DAT_00429968 = DVar1;
    }
    if (((param_2 != 0) || (DAT_00429968 <= DVar1 - _DAT_0042996c)) ||
       (*(int *)(&DAT_00432b2c + param_1 * 0x10) < DAT_00429970)) {
      sndPlaySoundA((LPCSTR)0x0,5);
      Sleep(1);
      DAT_00429968 = GetTickCount();
      _DAT_0042996c = *(int *)(&DAT_00432b28 + param_1 * 0x10);
      DAT_00429970 = *(int *)(&DAT_00432b2c + param_1 * 0x10);
      sndPlaySoundA(*(LPCSTR *)(&DAT_00432b20 + param_1 * 0x10),5);
    }
  }
  return;
}


// ==== FUN_00414cbe @ 00414cbe

void FUN_00414cbe(void)

{
  int local_c;
  int local_8;
  
  FUN_004146b0();
  FUN_00414ba3(0,0);
  for (local_8 = 1; local_8 < 0x10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00432b24 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00432b24 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00432b24 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_00432b20 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 4; local_c = local_c + 1) {
    DeleteFileA(&DAT_00432520 + local_c * 0x100);
  }
  return;
}


// ==== FUN_00414da8 @ 00414da8

void __cdecl FUN_00414da8(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00401000(DAT_00431e20,param_2,&DAT_00429b08);
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


// ==== FUN_00414ed7 @ 00414ed7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00414ed7(void)

{
  int local_8;
  
  _DAT_00432b20 = 0;
  _DAT_00432b24 = 0;
  FUN_00414da8((int *)&DAT_00432b30,s_COVERWAV_00429b10);
  _DAT_00432b3c = 10;
  FUN_00414da8(&DAT_00432b40,s_DOORCLOSWAV_00429b1c);
  _DAT_00432b4c = 10;
  FUN_00414da8((int *)&DAT_00432b50,s_DOOROPENWAV_00429b28);
  _DAT_00432b5c = 10;
  FUN_00414da8((int *)&DAT_00432b60,s_ENDBESTWAV_00429b34);
  _DAT_00432b6c = 10;
  FUN_00414da8((int *)&DAT_00432b70,s_ENDCURRWAV_00429b40);
  _DAT_00432b7c = 10;
  FUN_00414da8((int *)&DAT_00432b80,s_HEARTWAV_00429b4c);
  _DAT_00432b8c = 10;
  FUN_00414da8((int *)&DAT_00432b90,s_NEWHEARTWAV_00429b58);
  _DAT_00432b9c = 1;
  FUN_00414da8((int *)&DAT_00432ba0,s_NEWLEVELWAV_00429b64);
  _DAT_00432bac = 0;
  FUN_00414da8((int *)&DAT_00432bb0,s_PARHELLOWAV_00429b70);
  _DAT_00432bbc = 2;
  FUN_00414da8((int *)&DAT_00432bc0,s_PARROTWAV_00429b7c);
  _DAT_00432bcc = 3;
  FUN_00414da8((int *)&DAT_00432bd0,s_SNAKEUPWAV_00429b88);
  _DAT_00432bdc = 10;
  FUN_00414da8((int *)&DAT_00432be0,s_FLUTE0WAV_00429b94);
  _DAT_00432bec = 10;
  FUN_00414da8((int *)&DAT_00432bf0,s_FLUTE1WAV_00429ba0);
  _DAT_00432bfc = 10;
  FUN_00414da8((int *)&DAT_00432c00,s_FLUTE2WAV_00429bac);
  _DAT_00432c0c = 10;
  FUN_00414da8((int *)&DAT_00432c10,s_WINDOWWAV_00429bb8);
  _DAT_00432c1c = 10;
  for (local_8 = 1; local_8 < 4; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_00432520 + local_8 * 0x100);
    FUN_00421370((uint *)(&DAT_00432520 + local_8 * 0x100),(uint *)(&DAT_00429978 + local_8 * 0x20))
    ;
    FUN_00401223(&DAT_00429a38 + local_8 * 0x20,&DAT_00429bc4,&DAT_00432520 + local_8 * 0x100);
  }
  return;
}


// ==== FUN_0041519a @ 0041519a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041519a(void)

{
  DAT_00432f20 = 0;
  _DAT_00432f24 = 0;
  DAT_00432f28 = 0;
  DAT_00432f2c = 0;
  DAT_00432f30 = 0;
  DAT_00432f3c = 0;
  DAT_00432f38 = 1;
  _DAT_00433368 = 0;
  DAT_004334ac = 0;
  _DAT_004334b4 = 64000;
  _DAT_004334b0 = 1;
  DAT_004334c4 = 0;
  DAT_004334c8 = 0;
  return;
}


// ==== FUN_0041523b @ 0041523b

void FUN_0041523b(void)

{
  _atexit(FUN_00415258);
  return;
}


// ==== FUN_00415258 @ 00415258

void FUN_00415258(void)

{
  FUN_004154e7(&DAT_00432f20);
  return;
}


// ==== FUN_00415272 @ 00415272

undefined4 __thiscall FUN_00415272(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  HDC pHVar3;
  HBITMAP pHVar4;
  HGDIOBJ pvVar5;
  void *local_8;
  
  if (*(int *)this != 0) {
    FUN_004155c0(this);
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
  FUN_00420b60();
  uVar2 = FUN_00420c34((int)this + 0x48,param_1);
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
  DAT_004334d0 = *(undefined4 *)((int)this + 4);
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
    FUN_0041567f(this,0,0,param_1,-1);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_004154e7 @ 004154e7

void __fastcall FUN_004154e7(int *param_1)

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


// ==== FUN_004155c0 @ 004155c0

void __fastcall FUN_004155c0(int *param_1)

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


// ==== FUN_0041567f @ 0041567f

undefined4 __thiscall FUN_0041567f(void *this,int param_1,int param_2,int *param_3,short param_4)

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
    uVar1 = FUN_0041fff8(&local_28,&local_68,&local_48);
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
        FUN_0041e68c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0041e5d0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_4);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_2c + local_54 + -1;
      local_78 = local_18 + local_10 + -1;
      FUN_00418f93(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_004159d5 @ 004159d5

undefined4 __thiscall
FUN_004159d5(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0041fff8(&local_28,&local_68,&local_48);
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
        FUN_0041e68c((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0041e5d0(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_8);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_54 + local_2c + -1;
      local_78 = local_10 + local_18 + -1;
      FUN_00418f93(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_00415d5f @ 00415d5f

void __thiscall
FUN_00415d5f(void *this,int param_1,int param_2,int *param_3,int *param_4,short param_5)

{
  FUN_004159d5(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00415db7 @ 00415db7

undefined4 __thiscall
FUN_00415db7(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_004159d5(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00415f20 @ 00415f20

void __thiscall
FUN_00415f20(void *this,int param_1,int param_2,int *param_3,int *param_4,HDC param_5,short param_6)

{
  FUN_00415db7(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5,param_6);
  return;
}


// ==== FUN_00415f7c @ 00415f7c

undefined4 __thiscall
FUN_00415f7c(void *this,int param_1,int param_2,int *param_3,HDC param_4,short param_5)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041567f(this,param_1,param_2,param_3,param_5);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_4,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_004160f3 @ 004160f3

undefined4 __thiscall
FUN_004160f3(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6)

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
    uVar1 = FUN_0041fff8(&local_38,&local_78,&local_58);
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
      FUN_0041e6d6(local_7c,local_60,local_80,local_3c,local_20,local_44,local_40,-local_28);
      local_10 = 1;
      local_9c = local_64;
      local_98 = local_14;
      local_94 = local_3c + local_64 + -1;
      local_90 = local_20 + local_14 + -1;
      FUN_00418f93(this,&local_9c);
    }
  }
  return local_10;
}


// ==== FUN_004164a5 @ 004164a5

undefined4 __thiscall
FUN_004164a5(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6,
            HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_004160f3(this,param_1,param_2,param_3,param_4,param_5,param_6);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_00416650 @ 00416650

undefined4 __thiscall FUN_00416650(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0041fff8(&local_2c,&local_60,&local_48);
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
          FUN_0041e5d0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00418f93(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_004168c7 @ 004168c7

undefined4 __thiscall
FUN_004168c7(void *this,int param_1,int param_2,short *param_3,undefined1 param_4)

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
      uVar1 = FUN_0041fff8(&local_2c,&local_60,&local_48);
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
        FUN_0041e906(local_64,local_4c,local_30,local_1c,local_34,local_10,param_4);
        local_8 = 1;
        local_78 = local_50;
        local_74 = local_c;
        local_70 = local_30 + local_50 + -1;
        local_6c = local_1c + local_c + -1;
        FUN_00418f93(this,&local_78);
      }
    }
  }
  return local_8;
}


// ==== FUN_00416b2c @ 00416b2c

undefined4 __thiscall
FUN_00416b2c(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041fff8(&local_2c,&local_60,&local_48);
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
          FUN_0041e5d0(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00418f93(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00416dd7 @ 00416dd7

void __thiscall
FUN_00416dd7(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_00416b2c(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00416e2f @ 00416e2f

undefined4 __thiscall
FUN_00416e2f(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_00416b2c(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00416f96 @ 00416f96

void __thiscall
FUN_00416f96(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_00416e2f(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00416fee @ 00416fee

undefined4 __thiscall
FUN_00416fee(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041fff8(&local_2c,&local_60,&local_48);
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
          FUN_0041e68c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00418f93(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00417297 @ 00417297

void __thiscall
FUN_00417297(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_00416fee(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004172ef @ 004172ef

undefined4 __thiscall
FUN_004172ef(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_00416fee(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00417456 @ 00417456

void __thiscall
FUN_00417456(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_004172ef(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004174ae @ 004174ae

undefined4 __thiscall FUN_004174ae(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00416650(this,param_1,param_2,param_3,0);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_0041761c @ 0041761c

undefined4 __thiscall
FUN_0041761c(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0041fff8(&local_3c,&local_70,&local_58);
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
          FUN_0041e6d6(local_74,local_5c,local_78,local_40,local_24,local_44,local_18,local_2c);
          local_c = 1;
          local_90 = local_60;
          local_8c = local_10;
          local_88 = local_60 + local_40 + -1;
          local_84 = local_10 + local_24 + -1;
          FUN_00418f93(this,&local_90);
        }
        else {
          local_c = 1;
        }
      }
    }
  }
  return local_c;
}


// ==== FUN_00417952 @ 00417952

undefined4 __thiscall
FUN_00417952(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_0041761c(this,param_1,param_2,param_3,param_4,param_5,param_6,0);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_00417aff @ 00417aff

undefined4 __thiscall FUN_00417aff(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0041fff8(&local_2c,&local_60,&local_48);
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
          FUN_0041e68c(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_00418f93(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00417d74 @ 00417d74

undefined4 __thiscall FUN_00417d74(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00417aff(this,param_1,param_2,param_3,0);
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
      DAT_004334ac = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_004334d0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00417ee2 @ 00417ee2

undefined4 __thiscall
FUN_00417ee2(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0041fff8(&local_6c,&local_58,local_14);
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
        FUN_0041e68c((undefined4 *)local_5c,(undefined4 *)local_40,local_30,local_2c,local_38,
                     *(int *)((int)this + 0x14));
      }
      else {
        FUN_0041e5d0(local_5c,local_40,local_30,local_2c,local_38,*(int *)((int)this + 0x14),
                     (byte)param_8);
      }
      local_20 = 1;
    }
  }
  return local_20;
}


// ==== FUN_004181d6 @ 004181d6

undefined4 __thiscall
FUN_004181d6(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0041fff8(&local_68,&local_44,local_24);
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
        FUN_0041e68c((undefined4 *)local_54,(undefined4 *)local_4c,local_34,local_2c,local_c,
                     local_30);
      }
      else {
        FUN_0041e5d0(local_54,local_4c,local_34,local_2c,local_c,local_30,(byte)param_8);
      }
      local_10 = 1;
    }
  }
  return local_10;
}


// ==== FUN_00418435 @ 00418435

undefined4 __thiscall FUN_00418435(void *this,int *param_1,undefined1 param_2)

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
      uVar3 = FUN_0041fff8(&local_38,&local_18,&local_50);
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
        FUN_0041e8ae(local_58,local_3c,local_28,local_40,param_2);
        local_8 = 1;
        local_70 = local_54;
        local_6c = local_1c;
        local_68 = local_3c + local_54 + -1;
        local_64 = local_28 + local_1c + -1;
        FUN_00418f93(this,&local_70);
      }
    }
  }
  return local_8;
}


// ==== FUN_00418713 @ 00418713

void __thiscall
FUN_00418713(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  puStack_c = &LAB_004189a4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    FUN_004189ae();
    return;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  if ((param_5 == 0) || (param_6 == 0)) {
    local_8 = 0xffffffff;
    FUN_0041899b();
    FUN_004189ae();
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
  uVar1 = FUN_0041fff8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0041899b();
    FUN_004189ae();
    return;
  }
  local_50 = param_1;
  local_4c = param_2;
  local_48 = (local_28 - local_30) + param_1;
  local_44 = (local_24 - local_2c) + param_2;
  uVar1 = FUN_0041fff8(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0041899b();
    FUN_004189ae();
    return;
  }
  FUN_0041c7d8(&local_20,local_30,local_2c,local_28,local_24,1);
  if (param_7 == -1) {
    FUN_0041cae9(&local_20,1,param_1,param_2,-0x8000);
  }
  else {
    FUN_0041d090(&local_20,(int)(char)param_7,1,param_1,param_2,-0x8000);
  }
  local_8 = 0xffffffff;
  FUN_0041899b();
  FUN_004189ae();
  return;
}


// ==== FUN_0041899b @ 0041899b

void FUN_0041899b(void)

{
  int unaff_EBP;
  
  FUN_00412fe0((int *)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_004189ae @ 004189ae

void FUN_004189ae(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004189bf @ 004189bf

void __thiscall FUN_004189bf(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00418713(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_00418a13 @ 00418a13

undefined4 __thiscall
FUN_00418a13(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0041fff8(&local_20,&local_54,&local_3c);
    if ((int)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_54 = param_1;
      local_50 = param_2;
      local_4c = (local_18 - local_20) + param_1;
      local_48 = (local_14 - local_1c) + param_2;
      uVar2 = FUN_0041fff8(&local_20,&local_54,&local_3c);
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
          FUN_0041e68c((undefined4 *)local_58,(undefined4 *)local_40,local_24,local_10,local_28,
                       local_28);
        }
        else {
          FUN_0041e5d0(local_58,local_40,local_24,local_10,local_28,local_28,(byte)param_7);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// ==== FUN_00418ccd @ 00418ccd

void __thiscall FUN_00418ccd(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00418a13(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_00418d21 @ 00418d21

undefined4 __thiscall FUN_00418d21(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00416650(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041567f(this,param_1,param_2,(int *)(param_3 + 8),0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00418db9 @ 00418db9

undefined4 __thiscall FUN_00418db9(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00417aff(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0041567f(this,param_1,param_2,(int *)(param_3 + 8),-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00418e54 @ 00418e54

undefined4 __thiscall FUN_00418e54(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_004174ae(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00415f7c(this,param_1,param_2,(int *)(param_3 + 8),param_4,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00418ef2 @ 00418ef2

undefined4 __thiscall FUN_00418ef2(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00417d74(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00415f7c(this,param_1,param_2,(int *)(param_3 + 8),param_4,-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00418f93 @ 00418f93

void __thiscall FUN_00418f93(void *this,int *param_1)

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
        iVar1 = FUN_004201d2(&local_14,
                             (int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
                             (int *)((int)this + local_18 * 0x10 + 0x44c));
        if (iVar1 != 0) {
          *(int *)((int)this + local_18 * 0x10 + 0x44c) = local_14;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x450) = local_10;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x454) = local_c;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x458) = local_8;
          *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + -1;
LAB_00419146:
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
              iVar1 = FUN_004201d2(&local_14,(int *)((int)this + local_1c * 0x10 + 0x44c),
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
                goto LAB_00419146;
              }
            }
            local_18 = local_18 + 1;
          } while( true );
        }
      }
    }
    else {
      FUN_0042017c(&local_14,(int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
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


// ==== FUN_0041925f @ 0041925f

void __thiscall FUN_0041925f(void *this,int *param_1,int *param_2,HDC param_3)

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
  
  iVar1 = FUN_004200e3(param_1,param_2);
  if (iVar1 == 0) {
    FUN_004202ab(param_1);
    FUN_004202bb((int)param_1);
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
      DAT_004334ac = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_004334d0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
    FUN_004202ab(param_2);
    FUN_004202bb((int)param_2);
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
      DAT_004334ac = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_004334d0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  else {
    FUN_0042017c(&local_18,param_1,param_2);
    FUN_004202ab(&local_18);
    FUN_004202bb((int)&local_18);
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
      DAT_004334ac = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_004334d0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  return;
}


// ==== FUN_0041966a @ 0041966a

undefined4 __thiscall
FUN_0041966a(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0041fff8(&local_38,&local_70,&local_58);
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
        FUN_0041ea04(local_74,local_5c,local_8,local_c,local_3c,local_28,local_40,local_1c,local_18)
        ;
        local_10 = 1;
      }
    }
  }
  return local_10;
}


// ==== FUN_00419932 @ 00419932

undefined4 __thiscall FUN_00419932(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar2 = FUN_0041fff8(&local_24,&local_4c,&local_3c);
    if ((int)uVar2 != 0) {
      local_28 = local_1c - local_24;
      local_14 = local_18 - local_20;
      iVar1 = local_20 + local_14 + -1;
      if (*(int *)((int)this + 0x18) == -1) {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0042104c((byte *)(*(int *)((int)this + 0x14) * local_2c + *(int *)((int)this + 8) +
                               local_24),local_28);
        }
      }
      else {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0042104c((byte *)(((*(int *)((int)this + 0x10) - local_2c) + -1) *
                                *(int *)((int)this + 0x14) + *(int *)((int)this + 8) + local_24),
                       local_28);
        }
      }
      local_8 = 1;
      local_60 = local_24;
      local_5c = local_20;
      local_58 = local_24 + local_28 + -1;
      local_54 = local_20 + local_14 + -1;
      FUN_00418f93(this,&local_60);
    }
  }
  return local_8;
}


// ==== FUN_00419b65 @ 00419b65

void __fastcall FUN_00419b65(int param_1)

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


// ==== FUN_00419be7 @ 00419be7

undefined4 __thiscall
FUN_00419be7(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0041fff8(&local_30,&local_64,&local_4c);
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
        FUN_0041eb69(local_68,local_50,local_8,local_34,local_20,local_38,local_14,local_6c,param_7,
                     '\0');
        local_c = 1;
        local_88 = local_54;
        local_84 = local_10;
        local_80 = local_34 + local_54 + -1;
        local_7c = local_10 + local_20 + -1;
        FUN_00418f93(this,&local_88);
      }
    }
  }
  return local_c;
}


// ==== FUN_00419f21 @ 00419f21

undefined4 __thiscall FUN_00419f21(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0041fff8(&local_28,&local_50,&local_3c);
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
        FUN_00418f93(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_0041a0d8 @ 0041a0d8

undefined4 __thiscall FUN_0041a0d8(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0041fff8(&local_28,&local_50,&local_3c);
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
        FUN_00418f93(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_0041a290 @ 0041a290

void __cdecl FUN_0041a290(int param_1,int param_2,short *param_3,short *param_4)

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
      uVar1 = FUN_0041fff8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_3 + local_1c * local_4c + local_20 + 4);
        local_44 = (char *)((int)param_4 + local_10 * local_2c + local_14 + 4);
        FUN_0041e5d0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_0041a3ff @ 0041a3ff

void __cdecl FUN_0041a3ff(int param_1,int param_2,short *param_3,short *param_4)

{
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    FUN_0041e5d0((char *)((int)param_4 + param_1 + *param_4 * param_2 + 4),(char *)(param_3 + 2),
                 (int)*param_3,(int)param_3[1],(int)*param_4,(int)*param_3,0);
  }
  return;
}


// ==== FUN_0041a49a @ 0041a49a

void __cdecl FUN_0041a49a(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_004202ab(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_004202bb((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0041fff8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (char *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041e5d0(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_0041a629 @ 0041a629

void __cdecl FUN_0041a629(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_004202ab(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_004202bb((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0041fff8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041e68c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_0041a7aa @ 0041a7aa

void __cdecl FUN_0041a7aa(int param_1,int param_2,int param_3,short *param_4,short *param_5)

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
      uVar1 = FUN_0041fff8(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_1c * local_4c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0041e68c(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_0041a91f @ 0041a91f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0041a91f(void *this,int param_1,int param_2)

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
      _DAT_00429bd0 = 0;
      DAT_00429bd0 = 0;
      uVar2 = DAT_00429bd0;
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


// ==== FUN_0041aab6 @ 0041aab6

bool __fastcall FUN_0041aab6(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_0041aaf0 @ 0041aaf0

bool __fastcall FUN_0041aaf0(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_0041ab2a @ 0041ab2a

void __thiscall FUN_0041ab2a(void *this,int param_1)

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
        FUN_0041a0d8(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_00417aff(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
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
        FUN_00419f21(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_00416650(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_0041ad4a @ 0041ad4a

void __thiscall FUN_0041ad4a(void *this,int param_1,int param_2,int param_3)

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
        FUN_0041a0d8(&DAT_00432f20,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_00417aff(&DAT_00432f20,param_1,param_2,*(short **)this,0);
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
        FUN_00419f21(&DAT_00432f20,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_00416650(&DAT_00432f20,param_1,param_2,*(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_0041af22 @ 0041af22

void __thiscall FUN_0041af22(void *this,int *param_1,int param_2)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_2 != 0) {
    FUN_004160f3(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),param_1,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041b03e:
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
    if (bVar1) goto LAB_0041b03e;
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
      goto LAB_0041b0f4;
    }
  }
  local_14 = 0;
LAB_0041b0f4:
  FUN_004159d5(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),local_c,local_14,param_1,-1);
  return;
}


// ==== FUN_0041b154 @ 0041b154

void __thiscall FUN_0041b154(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_4 != 0) {
    FUN_004160f3(&DAT_00432f20,param_1,param_2,param_1,param_2,param_3,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041b24c:
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
    if (bVar1) goto LAB_0041b24c;
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
      goto LAB_0041b302;
    }
  }
  local_14 = 0;
LAB_0041b302:
  FUN_004159d5(&DAT_00432f20,param_1,param_2,param_1,param_2,local_c,local_14,param_3,-1);
  return;
}


// ==== FUN_0041b33e @ 0041b33e

void __thiscall FUN_0041b33e(void *this,int param_1)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_0041b3f8:
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
    if (bVar1) goto LAB_0041b3f8;
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
      goto LAB_0041b4ae;
    }
  }
  local_14 = 0;
LAB_0041b4ae:
  FUN_0041c7d8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28) + local_c + -1,*(int *)((int)this + 0x2c) + local_14 + -1,
               0);
  FUN_0041ab2a(this,param_1);
  return;
}


// ==== FUN_0041b4fc @ 0041b4fc

void __thiscall FUN_0041b4fc(void *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_0041b5b6:
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
    if (bVar1) goto LAB_0041b5b6;
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
      goto LAB_0041b66c;
    }
  }
  local_14 = 0;
LAB_0041b66c:
  FUN_0041c7d8((void *)((int)this + 0x40),param_1,param_2,param_1 + local_c + -1,
               param_2 + local_14 + -1,0);
  FUN_0041ad4a(this,param_1,param_2,param_3);
  return;
}


// ==== FUN_0041b6b1 @ 0041b6b1

void __thiscall FUN_0041b6b1(void *this,int param_1)

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
      FUN_00416fee(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
      return;
    }
    FUN_00416b2c(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                 (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                 (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041b978:
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
    if (bVar1) goto LAB_0041b978;
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
      goto LAB_0041ba43;
    }
  }
  local_8 = 0;
LAB_0041ba43:
  DAT_004334d4 = operator_new(local_8 * local_c + 4);
  if (DAT_004334d4 != (short *)0x0) {
    *DAT_004334d4 = (short)local_c;
    DAT_004334d4[1] = (short)local_8;
    _memset(DAT_004334d4 + 2,0,local_8 * local_c);
    if (param_1 == 0) {
      FUN_00416fee(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_004334d4,0);
    }
    else {
      FUN_00416b2c(&DAT_00432f20,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_004334d4,0);
    }
    FUN_00421c00(DAT_004334d4);
  }
  DAT_004334d4 = (short *)0x0;
  return;
}


// ==== FUN_0041bc42 @ 0041bc42

void __thiscall FUN_0041bc42(void *this,int param_1,int param_2,int *param_3,int param_4)

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
      FUN_00416fee(&DAT_00432f20,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,*(short **)this,0);
      return;
    }
    FUN_00416b2c(&DAT_00432f20,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                 (param_3[3] - param_3[1]) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_0041be5b:
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
    if (bVar1) goto LAB_0041be5b;
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
      goto LAB_0041bf11;
    }
  }
  local_8 = 0;
LAB_0041bf11:
  DAT_004334d4 = operator_new(local_8 * local_c + 4);
  if (DAT_004334d4 != (short *)0x0) {
    *DAT_004334d4 = (short)local_c;
    DAT_004334d4[1] = (short)local_8;
    _memset(DAT_004334d4 + 2,0,local_8 * local_c);
    if (param_4 == 0) {
      FUN_00416fee(&DAT_00432f20,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_004334d4,0);
    }
    else {
      FUN_00416b2c(&DAT_00432f20,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_004334d4,0);
    }
    FUN_00421c00(DAT_004334d4);
  }
  DAT_004334d4 = (short *)0x0;
  return;
}


// ==== FUN_0041c08c @ 0041c08c

void __thiscall FUN_0041c08c(void *this,int param_1)

{
  FUN_0041c7d8((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               (*(int *)((int)this + 0x38) + *(int *)((int)this + 0x28)) -
               *(int *)((int)this + 0x30),
               (*(int *)((int)this + 0x3c) + *(int *)((int)this + 0x2c)) -
               *(int *)((int)this + 0x34),0);
  FUN_0041b6b1(this,param_1);
  return;
}


// ==== FUN_0041c0f1 @ 0041c0f1

void __thiscall FUN_0041c0f1(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  FUN_0041c7d8((void *)((int)this + 0x40),param_1,param_2,(param_3[2] + param_1) - *param_3,
               (param_3[3] + param_2) - param_3[1],0);
  FUN_0041bc42(this,param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0041c160 @ 0041c160

undefined4 __thiscall FUN_0041c160(void *this,int param_1,int param_2,int param_3,int param_4)

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
  iVar4 = DAT_00432f34;
  iVar3 = DAT_00432f30;
  iVar2 = DAT_00432f28;
  if (DAT_00432f28 == 0) {
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
    iVar6 = DAT_00432f2c + -1;
    if (param_3 <= DAT_00432f2c + -1) {
      iVar6 = param_3;
    }
    iVar7 = DAT_00432f30 + -1;
    if (param_4 <= DAT_00432f30 + -1) {
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
      if (DAT_00432f38 == -1) {
        FUN_0041e68c((undefined4 *)(puVar1 + 4),(undefined4 *)(iVar2 + param_2 * iVar4 + param_1),
                     uVar8,iVar9,uVar8,iVar4);
      }
      else {
        FUN_0041e68c((undefined4 *)(puVar1 + 4),
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


// ==== FUN_0041c38d @ 0041c38d

undefined4 __thiscall FUN_0041c38d(void *this,int param_1,int param_2)

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
      local_2c = DAT_00432f2c;
      local_38 = DAT_00432f30;
      local_28 = DAT_00432f34;
      iVar2 = DAT_00432f2c + -1;
      if (local_18 <= DAT_00432f2c + -1) {
        iVar2 = local_18;
      }
      iVar3 = DAT_00432f30 + -1;
      if (local_24 <= DAT_00432f30 + -1) {
        iVar3 = local_24;
      }
      local_34 = local_34 + 4;
      local_10 = (undefined4 *)DAT_00432f28;
      local_8 = (iVar2 - local_14) + 1;
      local_c = (iVar3 - local_20) + 1;
      local_48 = local_14 + local_8 + -1;
      local_44 = local_20 + local_c + -1;
      local_50 = local_14;
      local_4c = local_20;
      local_24 = iVar3;
      local_18 = iVar2;
      FUN_00418f93(&DAT_00432f20,&local_50);
      if (DAT_00432f38 == -1) {
        local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
        FUN_0041e68c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
      }
      else {
        local_10 = (undefined4 *)
                   ((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
        FUN_0041e68c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
      }
      local_40 = *(void **)((int)this + *(short *)((int)this + 0x80) * 4);
      local_3c = local_40;
      FUN_00421c00(local_40);
      *(undefined4 *)((int)this + *(short *)((int)this + 0x80) * 4) = 0;
      *(short *)((int)this + 0x80) = *(short *)((int)this + 0x80) + -1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0041c632 @ 0041c632

undefined4 __thiscall FUN_0041c632(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_0041c6bc @ 0041c6bc

undefined4 __thiscall FUN_0041c6bc(void *this,int *param_1)

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


// ==== FUN_0041c749 @ 0041c749

void __fastcall FUN_0041c749(int param_1)

{
  while (*(short *)(param_1 + 0x80) != -1) {
    FUN_00421c00(*(void **)(param_1 + *(short *)(param_1 + 0x80) * 4));
    *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
  }
  return;
}


// ==== FUN_0041c7ba @ 0041c7ba

void __fastcall FUN_0041c7ba(int param_1)

{
  FUN_0041c749(param_1);
  return;
}


// ==== FUN_0041c7d8 @ 0041c7d8

undefined4 __thiscall
FUN_0041c7d8(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

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
  iVar4 = DAT_00432f34;
  iVar3 = DAT_00432f30;
  iVar2 = DAT_00432f28;
  if (DAT_00432f28 == 0) {
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
    iVar10 = DAT_00432f2c + -1;
    if (param_3 <= DAT_00432f2c + -1) {
      iVar10 = param_3;
    }
    iVar8 = DAT_00432f30 + -1;
    if (param_4 <= DAT_00432f30 + -1) {
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
          FUN_00421c00(*(void **)this);
          pvVar12 = operator_new(uVar11);
          *(void **)this = pvVar12;
          if (*(int *)this == 0) {
            return 0;
          }
          *(uint *)((int)this + 4) = uVar11;
        }
      }
      else {
        FUN_00421c00(*(void **)this);
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
    if (DAT_00432f38 == -1) {
      FUN_0041e68c((undefined4 *)(psVar1 + 6),(undefined4 *)(iVar2 + iVar7 * iVar4 + iVar6),uVar9,
                   iVar10,uVar9,iVar4);
    }
    else {
      FUN_0041e68c((undefined4 *)(psVar1 + 6),
                   (undefined4 *)(iVar2 + ((iVar3 - iVar7) + -1) * iVar4 + iVar6),uVar9,iVar10,uVar9
                   ,-iVar4);
    }
    *(undefined4 *)((int)this + 8) = 1;
    *(undefined4 *)((int)this + 0xc) = 1;
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0041cae9 @ 0041cae9

undefined4 __thiscall FUN_0041cae9(void *this,int param_1,int param_2,int param_3,int param_4)

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
    local_2c = DAT_00432f2c;
    local_38 = DAT_00432f30;
    local_28 = DAT_00432f34;
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
      iVar3 = DAT_00432f2c + -1;
      if (local_18 <= DAT_00432f2c + -1) {
        iVar3 = local_18;
      }
      iVar2 = DAT_00432f30 + -1;
      local_18 = iVar3;
      if (local_24 <= DAT_00432f30 + -1) {
        iVar2 = local_24;
      }
    }
    local_24 = iVar2;
    local_34 = local_34 + 6;
    local_10 = (undefined4 *)DAT_00432f28;
    local_8 = (local_18 - local_14) + 1;
    local_c = (local_24 - local_20) + 1;
    local_48 = local_14;
    local_44 = local_20;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    FUN_00418f93(&DAT_00432f20,&local_48);
    if (DAT_00432f38 == -1) {
      local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
      FUN_0041e68c(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
    }
    else {
      local_10 = (undefined4 *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0041e68c(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
    }
    if (param_2 != 0) {
      if (*(int *)this != 0) {
        FUN_00421c00(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041cdb9 @ 0041cdb9

undefined4 __thiscall
FUN_0041cdb9(void *this,short *param_1,int param_2,int param_3,int param_4,int param_5)

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
    local_38 = DAT_00432f2c;
    local_40 = DAT_00432f30;
    local_34 = DAT_00432f34;
    local_3c = local_3c + 6;
    local_18 = (undefined1 *)DAT_00432f28;
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
      FUN_00418f93(&DAT_00432f20,&local_58);
      if (DAT_00432f38 == -1) {
        local_18 = (undefined1 *)((int)local_18 + local_2c * local_34 + local_20);
        FUN_0041e6d6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,local_34,local_c,
                     local_10);
      }
      else {
        local_18 = (undefined1 *)
                   ((int)local_18 + ((local_40 - local_2c) + -1) * local_34 + local_20);
        FUN_0041e6d6(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,-local_34,local_c,
                     local_10);
      }
      if (param_5 != 0) {
        if (*(int *)this != 0) {
          FUN_00421c00(*(void **)this);
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


// ==== FUN_0041d090 @ 0041d090

undefined4 __thiscall
FUN_0041d090(void *this,int param_1,byte param_2,int param_3,int param_4,int param_5)

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
    local_2c = DAT_00432f2c;
    local_38 = DAT_00432f30;
    local_28 = DAT_00432f34;
    iVar2 = DAT_00432f2c + -1;
    if (local_18 <= DAT_00432f2c + -1) {
      iVar2 = local_18;
    }
    iVar3 = DAT_00432f30 + -1;
    if (local_24 <= DAT_00432f30 + -1) {
      iVar3 = local_24;
    }
    local_34 = local_34 + 6;
    local_10 = (char *)DAT_00432f28;
    local_8 = (iVar2 - local_14) + 1;
    local_c = (iVar3 - local_20) + 1;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    local_48 = local_14;
    local_44 = local_20;
    local_24 = iVar3;
    local_18 = iVar2;
    FUN_00418f93(&DAT_00432f20,&local_48);
    if (DAT_00432f38 == -1) {
      local_10 = (char *)((int)local_10 + local_28 * local_20 + local_14);
      FUN_0041e5d0(local_10,(char *)local_34,local_8,local_c,local_28,local_30,param_2);
    }
    else {
      local_10 = (char *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0041e5d0(local_10,(char *)local_34,local_8,local_c,-local_28,local_30,param_2);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_00421c00(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0041d369 @ 0041d369

undefined4 __thiscall
FUN_0041d369(void *this,HDC param_1,int param_2,int param_3,int param_4,int param_5)

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
    iVar5 = DAT_00432f2c + -1;
    if (local_18 <= DAT_00432f2c + -1) {
      iVar5 = local_18;
    }
    iVar4 = DAT_00432f30 + -1;
    if (local_24 <= DAT_00432f30 + -1) {
      iVar4 = local_24;
    }
    cx = (iVar5 - local_14) + 1;
    iVar5 = (iVar4 - local_20) + 1;
    if (DAT_00432f38 == -1) {
      FUN_0041e68c((undefined4 *)(DAT_00432f28 + DAT_00432f34 * local_20 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,DAT_00432f34,iVar3);
    }
    else {
      FUN_0041e68c((undefined4 *)
                   (DAT_00432f28 + ((DAT_00432f30 - local_20) + -1) * DAT_00432f34 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,-DAT_00432f34,iVar3);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_00421c00(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    DAT_004334ac = 0;
    hdc = CreateCompatibleDC(param_1);
    h = SelectObject(hdc,DAT_004334d0);
    BitBlt(param_1,local_14,local_20,cx,iVar5,hdc,local_14,local_20,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    GdiFlush();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0041d696 @ 0041d696

bool __thiscall FUN_0041d696(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_0041d709 @ 0041d709

bool __thiscall FUN_0041d709(void *this,int *param_1)

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


// ==== FUN_0041d780 @ 0041d780

uint __thiscall FUN_0041d780(void *this,int param_1,int param_2)

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


// ==== FUN_0041d80a @ 0041d80a

void __thiscall FUN_0041d80a(void *this,int param_1,int param_2,undefined1 param_3)

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


// ==== FUN_0041d8a0 @ 0041d8a0

bool __thiscall FUN_0041d8a0(void *this,LPCSTR param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = FUN_00414628(param_1);
  *(LPVOID *)this = pvVar1;
  return *(int *)this != 0;
}


// ==== FUN_0041d8e1 @ 0041d8e1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041d8e1(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int local_30;
  int local_28;
  int local_24;
  int local_20 [4];
  int local_10;
  short *local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    _DAT_004334b0 = 0;
    FUN_0041e473(this,param_1,param_2,param_3,local_20);
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
        FUN_00416650(&DAT_00432f20,local_28,param_2,local_c,0);
      }
      else {
        FUN_004168c7(&DAT_00432f20,local_28,param_2,local_c,*(undefined1 *)((int)this + 0xc));
      }
      local_28 = local_28 + *(int *)((int)this + 4) + local_8;
    }
    _DAT_004334b0 = 1;
    FUN_00418f93(&DAT_00432f20,local_20);
  }
  return;
}


// ==== FUN_0041da7c @ 0041da7c

void __thiscall FUN_0041da7c(void *this,int param_1,int param_2,int param_3,HDC param_4,int param_5)

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
    DAT_004334ac = 0;
    FUN_0041d8e1(this,param_1,param_2,param_3,param_5);
    if (DAT_004334ac != 0) {
      bVar7 = false;
      if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
        for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_004334ac = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
          if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_c * 0x10)) &&
             (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
            y = *(int *)(&DAT_00433370 + local_c * 0x10) - DAT_004334c8;
            x = *(int *)(&DAT_0043336c + local_c * 0x10) - DAT_004334c4;
            iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_004334ac = 0;
      }
    }
  }
  return;
}


// ==== FUN_0041deaa @ 0041deaa

void __thiscall
FUN_0041deaa(void *this,int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,
            int param_7)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    FUN_0041e473(this,param_1,param_2,param_3,&local_14);
    local_14 = local_14 + param_6;
    local_10 = local_10 + param_7;
    local_c = local_c + param_6;
    local_8 = local_8 + param_7;
    FUN_00415d5f(&DAT_00432f20,param_1,param_2,&local_14,param_4,-1);
    FUN_0041d8e1(this,param_1,param_2,param_3,param_5);
  }
  return;
}


// ==== FUN_0041df3f @ 0041df3f

void __thiscall
FUN_0041df3f(void *this,int param_1,int param_2,int param_3,HDC param_4,int *param_5,int param_6,
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
    DAT_004334ac = 0;
    FUN_0041deaa(this,param_1,param_2,param_3,param_5,param_6,param_7,param_8);
    if (DAT_004334ac != 0) {
      bVar7 = false;
      if ((DAT_004334c4 == 0) && (DAT_004334c8 == 0)) {
        for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_004334d0);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_004334ac = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
          if ((DAT_004334c4 <= *(int *)(&DAT_0043336c + local_c * 0x10)) &&
             (DAT_004334c8 <= *(int *)(&DAT_00433370 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
            y = *(int *)(&DAT_00433370 + local_c * 0x10) - DAT_004334c8;
            x = *(int *)(&DAT_0043336c + local_c * 0x10) - DAT_004334c4;
            iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_004334ac; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_00433378 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_00433374 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0043336c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_00433370 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0043336c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_004334d0);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_004334ac = 0;
      }
    }
  }
  return;
}


// ==== FUN_0041e379 @ 0041e379

int __thiscall FUN_0041e379(void *this,int param_1)

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


// ==== FUN_0041e473 @ 0041e473

undefined4 __thiscall FUN_0041e473(void *this,int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)this == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0041e379(this,param_3);
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


// ==== FUN_0041e515 @ 0041e515

int __thiscall FUN_0041e515(void *this,char param_1)

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


// ==== FUN_0041e5d0 @ 0041e5d0

/* WARNING: Removing unreachable block (ram,0x0041e62e) */
/* WARNING: Removing unreachable block (ram,0x0041e661) */

void __cdecl
FUN_0041e5d0(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
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
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_0041e636;
LAB_0041e60e:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_0041e63f;
LAB_0041e615:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_0041e649;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_0041e664;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_0041e60e;
LAB_0041e636:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_0041e615;
LAB_0041e63f:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_0041e649:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_0041e623;
          }
        }
LAB_0041e623:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0041e664:
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


// ==== FUN_0041e68c @ 0041e68c

void __cdecl
FUN_0041e68c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
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


// ==== FUN_0041e6d6 @ 0041e6d6

void __cdecl
FUN_0041e6d6(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042ab56 = param_4;
    do {
      for (uVar4 = DAT_0042ab56 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *param_2;
        if (*param_3 != '\0') goto LAB_0041e750;
LAB_0041e71c:
        uVar3 = param_2[1];
        if (param_3[1] != '\0') goto LAB_0041e75c;
LAB_0041e726:
        uVar3 = param_2[2];
        if (param_3[2] != '\0') goto LAB_0041e769;
        while (uVar3 = param_2[3], param_3[3] != '\0') {
          while( true ) {
            param_1[3] = uVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0041e788;
            uVar3 = *param_2;
            if (*param_3 == '\0') goto LAB_0041e71c;
LAB_0041e750:
            *param_1 = uVar3;
            uVar3 = param_2[1];
            if (param_3[1] == '\0') goto LAB_0041e726;
LAB_0041e75c:
            param_1[1] = uVar3;
            uVar3 = param_2[2];
            if (param_3[2] == '\0') break;
LAB_0041e769:
            param_1[2] = uVar3;
            uVar3 = param_2[3];
            if (param_3[3] == '\0') goto LAB_0041e73a;
          }
        }
LAB_0041e73a:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041e788:
      if ((DAT_0042ab56 & 3) != 0) {
        iVar5 = (DAT_0042ab56 & 3) + 1;
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


// ==== FUN_0041e7bd @ 0041e7bd

void __cdecl
FUN_0041e7bd(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8,char param_9)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_0042ab56 = param_4;
    do {
      for (uVar4 = DAT_0042ab56 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar1 = *param_2;
        if (*param_3 == param_9) goto LAB_0041e83d;
LAB_0041e805:
        uVar1 = param_2[1];
        if (param_3[1] == param_9) goto LAB_0041e84a;
LAB_0041e810:
        uVar1 = param_2[2];
        if (param_3[2] == param_9) goto LAB_0041e858;
        while (uVar1 = param_2[3], param_3[3] == param_9) {
          while( true ) {
            param_1[3] = uVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0041e878;
            uVar1 = *param_2;
            if (*param_3 != param_9) goto LAB_0041e805;
LAB_0041e83d:
            *param_1 = uVar1;
            uVar1 = param_2[1];
            if (param_3[1] != param_9) goto LAB_0041e810;
LAB_0041e84a:
            param_1[1] = uVar1;
            uVar1 = param_2[2];
            if (param_3[2] != param_9) break;
LAB_0041e858:
            param_1[2] = uVar1;
            uVar1 = param_2[3];
            if (param_3[3] != param_9) goto LAB_0041e826;
          }
        }
LAB_0041e826:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041e878:
      if ((DAT_0042ab56 & 3) != 0) {
        iVar5 = (DAT_0042ab56 & 3) + 1;
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


// ==== FUN_0041e8ae @ 0041e8ae

void __cdecl
FUN_0041e8ae(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    DAT_0042ab56 = param_2 & 3;
    uVar1 = param_2 >> 2;
    do {
      for (; uVar2 = DAT_0042ab56, uVar1 != 0; uVar1 = uVar1 - 1) {
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


// ==== FUN_0041e906 @ 0041e906

/* WARNING: Removing unreachable block (ram,0x0041e962) */
/* WARNING: Removing unreachable block (ram,0x0041e995) */

void __cdecl
FUN_0041e906(undefined1 *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
            undefined1 param_7)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    do {
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0041e96a;
LAB_0041e942:
        if (param_2[1] != '\0') goto LAB_0041e973;
LAB_0041e949:
        if (param_2[2] != '\0') goto LAB_0041e97d;
        while (param_2[3] != '\0') {
          while( true ) {
            param_1[3] = param_7;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar3 = uVar3 - 1;
            if (uVar3 == 0) goto LAB_0041e998;
            if (*param_2 == '\0') goto LAB_0041e942;
LAB_0041e96a:
            *param_1 = param_7;
            if (param_2[1] == '\0') goto LAB_0041e949;
LAB_0041e973:
            param_1[1] = param_7;
            if (param_2[2] == '\0') break;
LAB_0041e97d:
            param_1[2] = param_7;
            if (param_2[3] == '\0') goto LAB_0041e957;
          }
        }
LAB_0041e957:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0041e998:
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


// ==== FUN_0041e9c0 @ 0041e9c0

void FUN_0041e9c0(void)

{
  byte in_AH;
  undefined4 unaff_ESI;
  
  if (in_AH < DAT_0042ab63) {
    if (DAT_0042ab62 == '\0') {
      return;
    }
    DAT_0042ab5e = unaff_ESI;
    DAT_0042ab62 = 0;
    return;
  }
  if (DAT_0042ab62 == '\x01') {
    return;
  }
  DAT_0042ab5a = unaff_ESI;
  DAT_0042ab62 = 1;
  return;
}


// ==== FUN_0041ea04 @ 0041ea04

/* WARNING: Removing unreachable block (ram,0x0041eb0d) */

void __cdecl
FUN_0041ea04(char *param_1,char *param_2,char *param_3,int param_4,uint param_5,int param_6,
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
    DAT_0042ab62 = 0;
    DAT_0042ab5a = param_3;
    DAT_0042ab5e = param_4;
    iVar1 = param_9 - param_5;
    DAT_0042ab56 = param_5;
    do {
      for (uVar3 = DAT_0042ab56 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0041eaa2;
LAB_0041ea6a:
        if (param_2[1] != '\0') goto LAB_0041eab6;
LAB_0041ea71:
        if (param_2[2] != '\0') goto LAB_0041eacc;
        while (param_2[3] != '\0') {
          while( true ) {
            FUN_0041e9c0();
            if (param_3[3] != '\0') {
              param_1[3] = param_3[3];
            }
            param_1 = param_1 + 4;
            param_3 = param_3 + 4;
            param_2 = param_2 + 4;
            DAT_0042ab5a = DAT_0042ab5a + 4;
            DAT_0042ab5e = DAT_0042ab5e + 4;
            uVar3 = extraout_ECX_02 - 1;
            param_6 = extraout_EDX_02;
            if (uVar3 == 0) goto LAB_0041eb10;
            if (*param_2 == '\0') goto LAB_0041ea6a;
LAB_0041eaa2:
            FUN_0041e9c0();
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
            uVar3 = extraout_ECX;
            param_6 = extraout_EDX;
            if (param_2[1] == '\0') goto LAB_0041ea71;
LAB_0041eab6:
            FUN_0041e9c0();
            if (param_3[1] != '\0') {
              param_1[1] = param_3[1];
            }
            uVar3 = extraout_ECX_00;
            param_6 = extraout_EDX_00;
            if (param_2[2] == '\0') break;
LAB_0041eacc:
            FUN_0041e9c0();
            if (param_3[2] != '\0') {
              param_1[2] = param_3[2];
            }
            uVar3 = extraout_ECX_01;
            param_6 = extraout_EDX_01;
            if (param_2[3] == '\0') goto LAB_0041ea7f;
          }
        }
LAB_0041ea7f:
        param_1 = param_1 + 4;
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        DAT_0042ab5a = DAT_0042ab5a + 4;
        DAT_0042ab5e = DAT_0042ab5e + 4;
      }
LAB_0041eb10:
      if ((DAT_0042ab56 & 3) != 0) {
        iVar4 = (DAT_0042ab56 & 3) + 1;
        pcVar5 = param_3;
        pcVar6 = param_1;
        while (param_1 = pcVar6, param_3 = pcVar5, iVar4 = iVar4 + -1, iVar4 != 0) {
          cVar2 = *param_2;
          pcVar5 = param_3 + 1;
          pcVar6 = param_1 + 1;
          param_2 = param_2 + 1;
          DAT_0042ab5a = DAT_0042ab5a + 1;
          DAT_0042ab5e = DAT_0042ab5e + 1;
          if (cVar2 != '\0') {
            FUN_0041e9c0();
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
      DAT_0042ab5a = DAT_0042ab5a + iVar1;
      DAT_0042ab5e = DAT_0042ab5e + iVar1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}


// ==== FUN_0041eb69 @ 0041eb69

void __cdecl
FUN_0041eb69(char *param_1,char *param_2,byte *param_3,uint param_4,int param_5,int param_6,
            int param_7,int param_8,byte param_9,char param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_4 != 0) {
    DAT_0042ab56 = param_4;
    do {
      for (uVar2 = DAT_0042ab56 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        cVar1 = *param_2;
        if ((cVar1 != param_10) && (param_9 <= *param_3)) goto LAB_0041ec00;
LAB_0041ebbc:
        cVar1 = param_2[1];
        if ((cVar1 != param_10) && (param_9 <= param_3[1])) goto LAB_0041ec10;
LAB_0041ebca:
        cVar1 = param_2[2];
        if ((cVar1 != param_10) && (param_9 <= param_3[2])) goto LAB_0041ec21;
        while ((cVar1 = param_2[3], cVar1 != param_10 && (param_9 <= param_3[3]))) {
          while( true ) {
            param_1[3] = cVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_0041ec44;
            cVar1 = *param_2;
            if ((cVar1 == param_10) || (*param_3 < param_9)) goto LAB_0041ebbc;
LAB_0041ec00:
            *param_1 = cVar1;
            cVar1 = param_2[1];
            if ((cVar1 == param_10) || (param_3[1] < param_9)) goto LAB_0041ebca;
LAB_0041ec10:
            param_1[1] = cVar1;
            cVar1 = param_2[2];
            if ((cVar1 == param_10) || (param_3[2] < param_9)) break;
LAB_0041ec21:
            param_1[2] = cVar1;
            cVar1 = param_2[3];
            if ((cVar1 == param_10) || (param_3[3] < param_9)) goto LAB_0041ebe6;
          }
        }
LAB_0041ebe6:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0041ec44:
      if ((DAT_0042ab56 & 3) != 0) {
        iVar3 = (DAT_0042ab56 & 3) + 1;
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


// ==== FUN_0041ec80 @ 0041ec80

undefined * FUN_0041ec80(void)

{
  return &DAT_00429bd4;
}


// ==== FUN_0041ec86 @ 0041ec86

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041ec86(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

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
  
  iVar9 = param_1 + _DAT_00429bd8;
  iVar6 = param_3 + _DAT_00429bd8;
  iVar4 = iVar6;
  iVar2 = param_2 + _DAT_00429bdc;
  iVar3 = param_4 + _DAT_00429bdc;
  if (iVar6 < iVar9) {
    iVar4 = iVar9;
    iVar9 = iVar6;
    iVar2 = param_4 + _DAT_00429bdc;
    iVar3 = param_2 + _DAT_00429bdc;
  }
  if ((DAT_00429be0 <= iVar4) && (iVar9 <= DAT_00429be4)) {
    if (iVar2 < iVar3) {
      if (iVar3 < DAT_00429be8) {
        return;
      }
      if (DAT_00429bec < iVar2) {
        return;
      }
      if ((iVar9 < DAT_00429be0) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00429be0) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00429be0,
         DAT_00429bec < iVar2)) {
        return;
      }
      if ((DAT_00429be4 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_00429be4 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_00429be4,
         iVar3 < DAT_00429be8)) {
        return;
      }
      if ((iVar2 < DAT_00429be8) &&
         (iVar9 = (int)(((longlong)(iVar3 - DAT_00429be8) * (longlong)(iVar9 - iVar4)) /
                       (longlong)-(iVar2 - iVar3)) + iVar4, iVar2 = DAT_00429be8,
         DAT_00429be4 < iVar9)) {
        return;
      }
      if ((DAT_00429bec < iVar3) &&
         (iVar4 = (int)(((longlong)(DAT_00429bec - iVar2) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar3 - iVar2)) + iVar9, iVar3 = DAT_00429bec,
         iVar4 < DAT_00429be0)) {
        return;
      }
    }
    else {
      if (DAT_00429bec < iVar3) {
        return;
      }
      if (iVar2 < DAT_00429be8) {
        return;
      }
      if ((iVar9 < DAT_00429be0) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_00429be0) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_00429be0,
         iVar2 < DAT_00429be8)) {
        return;
      }
      if ((DAT_00429be4 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_00429be4 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_00429be4,
         DAT_00429bec < iVar3)) {
        return;
      }
      if ((iVar3 < DAT_00429be8) &&
         (iVar4 = (int)(((longlong)(iVar2 - DAT_00429be8) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar2 - iVar3)) + iVar9, iVar3 = DAT_00429be8,
         iVar4 < DAT_00429be0)) {
        return;
      }
      if ((DAT_00429bec < iVar2) &&
         (iVar9 = (int)(((longlong)(DAT_00429bec - iVar3) * (longlong)(iVar9 - iVar4)) /
                       (longlong)(iVar2 - iVar3)) + iVar4, iVar2 = DAT_00429bec,
         DAT_00429be4 < iVar9)) {
        return;
      }
    }
    if (iVar9 == iVar4) {
      iVar4 = iVar2;
      if (iVar3 <= iVar2) {
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      puVar10 = (undefined1 *)(DAT_00429bf0 * iVar4 + iVar9 + _DAT_00429bd4);
      for (iVar4 = (iVar3 - iVar4) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + DAT_00429bf0;
      }
    }
    else if (iVar2 == iVar3) {
      uVar7 = (iVar4 - iVar9) + 1;
      puVar11 = (undefined4 *)(DAT_00429bf0 * iVar2 + iVar9 + _DAT_00429bd4);
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
      DAT_00429bf4 = DAT_00429bf0;
      uVar7 = iVar4 - iVar9;
      uVar8 = iVar3 - iVar2;
      if (iVar3 < iVar2) {
        DAT_00429bf4 = -DAT_00429bf0;
        uVar8 = -uVar8;
      }
      iVar4 = DAT_00429bf4;
      if ((short)uVar7 < (short)uVar8) {
        puVar10 = (undefined1 *)(DAT_00429bf0 * iVar2 + iVar9 + _DAT_00429bd4);
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
        puVar10 = (undefined1 *)(DAT_00429bf0 * iVar2 + iVar9 + _DAT_00429bd4);
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


// ==== FUN_0041ef8e @ 0041ef8e

void __cdecl FUN_0041ef8e(int param_1,byte *param_2,int param_3)

{
  do {
    *param_2 = *(byte *)(param_1 + (uint)*param_2);
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


// ==== FUN_0041efaf @ 0041efaf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041efaf(void *this,int *param_1,int param_2)

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
  
  DAT_0042ab00 = 0x7fffffff;
  DAT_0042ab04 = 0;
  DAT_0042aaf8 = 0x7fffffff;
  DAT_0042aafc = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      DAT_0042aafc = *piVar10 + _DAT_00429bd8;
      if (DAT_0042aafc <= DAT_0042aaf8) {
        DAT_0042aaf8 = DAT_0042aafc;
      }
      piVar10 = piVar10 + 2;
      iVar2 = *piVar1 + _DAT_00429bdc;
      if (iVar2 <= DAT_0042ab00) {
        DAT_0042ab00 = iVar2;
      }
      if (iVar2 <= DAT_0042ab04) {
        DAT_0042ab04 = iVar2;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042aaf8 <= DAT_00429be4) && (DAT_00429be0 <= DAT_0042aafc)) &&
        (DAT_0042ab00 <= DAT_00429bec)) && (DAT_00429be8 <= DAT_0042ab04)) {
      if (DAT_0042ab00 <= DAT_00429be8) {
        DAT_0042ab00 = DAT_00429be8;
      }
      if (DAT_00429bec <= DAT_0042ab04) {
        DAT_0042ab04 = DAT_00429bec;
      }
      iVar2 = DAT_00429be4 + 1;
      piVar10 = &DAT_00429bf8;
      for (iVar4 = ((DAT_0042ab04 - DAT_0042ab00) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar2;
        piVar10 = piVar10 + 1;
      }
      puVar14 = &DAT_00429bfc;
      for (iVar2 = (DAT_0042ab04 - DAT_0042ab00) + 1; iVar4 = DAT_0042ab00, uVar3 = _DAT_0042ab10,
          0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 2;
      }
      for (; DAT_0042ab00 = iVar4, _DAT_0042ab10 = uVar3, 1 < DAT_0042ab08;
          DAT_0042ab08 = DAT_0042ab08 + -1) {
        iVar5 = param_1[1] + _DAT_00429bdc;
        iVar7 = param_1[3] + _DAT_00429bdc;
        iVar2 = *param_1 + _DAT_00429bd8;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_00429bd8;
        if (iVar7 < iVar5) {
          iVar2 = param_1[2] + _DAT_00429bd8;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_00429bd8;
        }
        if ((iVar11 <= DAT_0042ab04) && (iVar4 <= iVar7)) {
          if (iVar11 <= iVar4) {
            iVar2 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar2 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042ab04 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042ab04 - iVar11) * (longlong)(iVar8 - iVar2)) /
                         (longlong)(iVar7 - iVar11)) + iVar2;
            iVar7 = DAT_0042ab04;
          }
          _DAT_0042ab0c = &DAT_00429bf8 + (iVar7 - iVar4) * 2;
          piVar10 = &DAT_00429bf8 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar2;
          if (iVar8 < iVar2) {
            _DAT_0042ab10 = -uVar9;
            if ((int)_DAT_0042ab10 < iVar4) goto LAB_0041f251;
            iVar7 = -(_DAT_0042ab10 + 1 >> 1);
            uVar3 = _DAT_0042ab10 + 1;
            iVar11 = iVar2;
LAB_0041f228:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041f228;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              if (iVar8 <= *piVar10) {
                *piVar10 = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar2 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_0042ab10;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0041f251:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar6 = 0x80000000;
            _DAT_0042ab10 = uVar3;
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
            _DAT_0042ab10 = uVar9;
LAB_0041f1e6:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              iVar11 = iVar8 + 1;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041f1e6;
              }
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar8) {
                piVar10[1] = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar7 = iVar7 - _DAT_0042ab10;
              iVar2 = iVar11;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_0042ab00;
        uVar3 = _DAT_0042ab10;
      }
      if (DAT_0042aaf8 <= DAT_00429be0) {
        DAT_0042aaf8 = DAT_00429be0;
      }
      DAT_0042ab1c = (uint)*(ushort *)this;
      DAT_0042ab18 = (undefined4 *)((int)this + DAT_0042ab1c * *(ushort *)((int)this + 2) + 4);
      puVar14 = (undefined4 *)((int)this + 4);
      DAT_0042ab20 = DAT_00429bf0 * iVar4 + _DAT_00429bd4;
      piVar10 = &DAT_00429bf8;
      DAT_0042ab14 = puVar14;
      if (iVar4 <= DAT_0042ab04) {
        do {
          iVar2 = *piVar10;
          if (*piVar10 <= DAT_00429be0) {
            iVar2 = DAT_00429be0;
          }
          iVar11 = piVar10[1];
          if (piVar10[1] <= DAT_00429be4) {
            iVar11 = DAT_00429be4;
          }
          if (iVar2 <= iVar11) {
            uVar9 = (iVar11 - iVar2) + 1;
            puVar15 = (undefined4 *)(DAT_0042ab20 + iVar2);
            iVar2 = CONCAT22((short)((uint)(iVar2 - DAT_0042aaf8) >> 0x10),
                             (ushort)(iVar2 - DAT_0042aaf8) % (ushort)(byte)DAT_0042ab1c);
            puVar12 = (undefined4 *)((int)puVar14 + iVar2);
            iVar2 = iVar2 - DAT_0042ab1c;
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
              if ((int)DAT_0042ab1c < (int)uVar9) {
                do {
                  uVar3 = DAT_0042ab1c;
                  uVar9 = uVar9 - DAT_0042ab1c;
                  if ((short)DAT_0042ab1c != 0) {
                    uVar6 = DAT_0042ab1c >> 1;
                    puVar12 = puVar14;
                    puVar13 = puVar15;
                    if ((DAT_0042ab1c & 1) != 0) {
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
                } while ((int)DAT_0042ab1c < (int)uVar9);
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
          DAT_0042ab20 = DAT_0042ab20 + DAT_00429bf0;
          piVar10 = piVar10 + 2;
          puVar14 = (undefined4 *)((int)puVar14 + DAT_0042ab1c);
          if (DAT_0042ab18 <= puVar14) {
            puVar14 = DAT_0042ab14;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042ab04);
      }
    }
  }
  return;
}


// ==== FUN_0041f3f6 @ 0041f3f6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041f3f6(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_0042ab00 = 0x7fffffff;
  DAT_0042ab04 = 0;
  DAT_0042aaf8 = 0x7fffffff;
  DAT_0042aafc = 0;
  if (param_2 != 0) {
    piVar12 = param_1;
    do {
      piVar1 = piVar12 + 1;
      iVar3 = *piVar12 + _DAT_00429bd8;
      if (iVar3 <= DAT_0042aaf8) {
        DAT_0042aaf8 = iVar3;
      }
      if (DAT_0042aafc <= iVar3) {
        DAT_0042aafc = iVar3;
      }
      piVar12 = piVar12 + 2;
      iVar3 = *piVar1 + _DAT_00429bdc;
      if (iVar3 <= DAT_0042ab00) {
        DAT_0042ab00 = iVar3;
      }
      if (DAT_0042ab04 <= iVar3) {
        DAT_0042ab04 = iVar3;
      }
    } while ((int)piVar12 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042aaf8 <= DAT_00429be4) && (DAT_00429be0 <= DAT_0042aafc)) &&
        (DAT_0042ab00 <= DAT_00429bec)) && (DAT_00429be8 <= DAT_0042ab04)) {
      if (DAT_0042ab00 <= DAT_00429be8) {
        DAT_0042ab00 = DAT_00429be8;
      }
      if (DAT_00429bec <= DAT_0042ab04) {
        DAT_0042ab04 = DAT_00429bec;
      }
      iVar3 = DAT_00429be4 + 1;
      piVar12 = &DAT_00429bf8;
      for (iVar4 = ((DAT_0042ab04 - DAT_0042ab00) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = iVar3;
        piVar12 = piVar12 + 1;
      }
      puVar13 = &DAT_00429bfc;
      for (iVar3 = (DAT_0042ab04 - DAT_0042ab00) + 1; DAT_0042ab08 = param_2, iVar4 = DAT_0042ab00,
          uVar6 = _DAT_0042ab10, 0 < iVar3; iVar3 = iVar3 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 2;
      }
      for (; DAT_0042ab00 = iVar4, _DAT_0042ab10 = uVar6, 1 < DAT_0042ab08;
          DAT_0042ab08 = DAT_0042ab08 + -1) {
        iVar5 = param_1[1] + _DAT_00429bdc;
        iVar7 = param_1[3] + _DAT_00429bdc;
        iVar3 = *param_1 + _DAT_00429bd8;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_00429bd8;
        if (iVar7 < iVar5) {
          iVar3 = param_1[2] + _DAT_00429bd8;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_00429bd8;
        }
        if ((iVar11 <= DAT_0042ab04) && (iVar4 <= iVar7)) {
          if (iVar11 < iVar4) {
            iVar3 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar3 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_0042ab04 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_0042ab04 - iVar11) * (longlong)(iVar8 - iVar3)) /
                         (longlong)(iVar7 - iVar11)) + iVar3;
            iVar7 = DAT_0042ab04;
          }
          _DAT_0042ab0c = &DAT_00429bf8 + (iVar7 - iVar4) * 2;
          piVar12 = &DAT_00429bf8 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            _DAT_0042ab10 = -uVar9;
            if ((int)_DAT_0042ab10 < iVar4) goto LAB_0041f69d;
            iVar7 = -(_DAT_0042ab10 + 1 >> 1);
            uVar6 = _DAT_0042ab10 + 1;
            iVar11 = iVar3;
LAB_0041f674:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041f674;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              if (iVar8 <= *piVar12) {
                *piVar12 = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar3 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_0042ab10;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0041f69d:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar10 = 0x80000000;
            _DAT_0042ab10 = uVar6;
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
            _DAT_0042ab10 = uVar9;
LAB_0041f632:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              iVar11 = iVar8 + 1;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0041f632;
              }
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar8) {
                piVar12[1] = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar7 = iVar7 - _DAT_0042ab10;
              iVar3 = iVar11;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_0042ab00;
        uVar6 = _DAT_0042ab10;
      }
      iVar3 = DAT_00429bf0 * iVar4 + _DAT_00429bd4;
      piVar12 = &DAT_00429bf8;
      uVar2 = CONCAT11(param_3,param_3);
      uStack_14 = CONCAT22(uVar2,uVar2);
      if (iVar4 <= DAT_0042ab04) {
        do {
          iVar11 = *piVar12;
          if (*piVar12 <= DAT_00429be0) {
            iVar11 = DAT_00429be0;
          }
          iVar7 = piVar12[1];
          if (piVar12[1] <= DAT_00429be4) {
            iVar7 = DAT_00429be4;
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
          iVar3 = iVar3 + DAT_00429bf0;
          piVar12 = piVar12 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_0042ab04);
      }
    }
  }
  return;
}


// ==== FUN_0041f768 @ 0041f768

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041f768(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_0042ab00 = 0x7fffffff;
  DAT_0042ab04 = 0;
  DAT_0042aaf8 = 0x7fffffff;
  DAT_0042aafc = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      iVar3 = *piVar10 + _DAT_00429bd8;
      if (iVar3 <= DAT_0042aaf8) {
        DAT_0042aaf8 = iVar3;
      }
      if (DAT_0042aafc <= iVar3) {
        DAT_0042aafc = iVar3;
      }
      piVar10 = piVar10 + 2;
      iVar3 = *piVar1 + _DAT_00429bdc;
      if (iVar3 <= DAT_0042ab00) {
        DAT_0042ab00 = iVar3;
      }
      if (DAT_0042ab04 <= iVar3) {
        DAT_0042ab04 = iVar3;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_0042aaf8 <= DAT_00429be4) && (DAT_00429be0 <= DAT_0042aafc)) &&
        (DAT_0042ab00 <= DAT_00429bec)) && (DAT_00429be8 <= DAT_0042ab04)) {
      if (DAT_0042ab00 <= DAT_00429be8) {
        DAT_0042ab00 = DAT_00429be8;
      }
      if (DAT_00429bec <= DAT_0042ab04) {
        DAT_0042ab04 = DAT_00429bec;
      }
      iVar3 = DAT_00429be4 + 1;
      piVar10 = &DAT_00429bf8;
      for (iVar4 = ((DAT_0042ab04 - DAT_0042ab00) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar3;
        piVar10 = piVar10 + 1;
      }
      iVar3 = (DAT_0042ab04 - DAT_0042ab00) + 1;
      puVar12 = &DAT_00429bfc;
      iVar4 = iVar3;
      while (iVar11 = iVar3, DAT_0042ab08 = param_2, iVar3 = DAT_0042ab00, uVar2 = _DAT_0042ab10,
            0 < iVar4) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 2;
        iVar3 = iVar11 + -1;
        iVar4 = iVar11;
      }
      for (; DAT_0042ab00 = iVar3, _DAT_0042ab10 = uVar2, 1 < DAT_0042ab08;
          DAT_0042ab08 = DAT_0042ab08 + -1) {
        iVar5 = param_1[1] + _DAT_00429bdc;
        iVar6 = param_1[3] + _DAT_00429bdc;
        iVar4 = *param_1 + _DAT_00429bd8;
        iVar11 = iVar5;
        iVar7 = param_1[2] + _DAT_00429bd8;
        if (iVar6 < iVar5) {
          iVar4 = param_1[2] + _DAT_00429bd8;
          iVar11 = iVar6;
          iVar6 = iVar5;
          iVar7 = *param_1 + _DAT_00429bd8;
        }
        if ((iVar11 <= DAT_0042ab04) && (iVar3 <= iVar6)) {
          if (iVar11 < iVar3) {
            iVar4 = (int)(((longlong)(iVar6 - iVar3) * (longlong)(iVar4 - iVar7)) /
                         (longlong)(iVar6 - iVar11)) + iVar7;
            iVar11 = iVar3;
          }
          if (DAT_0042ab04 < iVar6) {
            iVar7 = (int)(((longlong)(DAT_0042ab04 - iVar11) * (longlong)(iVar7 - iVar4)) /
                         (longlong)(iVar6 - iVar11)) + iVar4;
            iVar6 = DAT_0042ab04;
          }
          _DAT_0042ab0c = &DAT_00429bf8 + (iVar6 - iVar3) * 2;
          piVar10 = &DAT_00429bf8 + (iVar11 - iVar3) * 2;
          iVar3 = (iVar6 - iVar3) - (iVar11 - iVar3);
          uVar8 = iVar7 - iVar4;
          if (iVar7 < iVar4) {
            _DAT_0042ab10 = -uVar8;
            if ((int)_DAT_0042ab10 < iVar3) goto LAB_0041fa0c;
            iVar6 = -(_DAT_0042ab10 + 1 >> 1);
            uVar2 = _DAT_0042ab10 + 1;
            iVar11 = iVar4;
LAB_0041f9e3:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              iVar11 = iVar7 + -1;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0041f9e3;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              if (iVar7 <= *piVar10) {
                *piVar10 = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar4 = iVar7 + -1;
              iVar6 = iVar6 - _DAT_0042ab10;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
          else if ((int)uVar8 < iVar3) {
LAB_0041fa0c:
            iVar11 = (int)(CONCAT44((int)uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) /
                          (longlong)iVar3);
            uVar8 = iVar11 * 2;
            iVar3 = iVar3 + 1;
            uVar9 = 0x80000000;
            _DAT_0042ab10 = uVar2;
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
            _DAT_0042ab10 = uVar8;
LAB_0041f9a1:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              iVar11 = iVar7 + 1;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0041f9a1;
              }
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar7) {
                piVar10[1] = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar6 = iVar6 - _DAT_0042ab10;
              iVar4 = iVar11;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
        }
        param_1 = param_1 + 2;
        iVar3 = DAT_0042ab00;
        uVar2 = _DAT_0042ab10;
      }
      if (DAT_0042aaf8 <= DAT_00429be0) {
        DAT_0042aaf8 = DAT_00429be0;
      }
      DAT_0042ab20 = DAT_00429bf0 * iVar3 + _DAT_00429bd4;
      piVar10 = &DAT_00429bf8;
      if (iVar3 <= DAT_0042ab04) {
        do {
          iVar4 = *piVar10;
          if (*piVar10 <= DAT_00429be0) {
            iVar4 = DAT_00429be0;
          }
          iVar11 = piVar10[1];
          if (DAT_00429be4 <= piVar10[1]) {
            iVar11 = DAT_00429be4;
          }
          if (iVar4 <= iVar11) {
            puVar13 = (undefined1 *)(DAT_0042ab20 + iVar4);
            for (iVar11 = (iVar11 - iVar4) + 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar13 = param_3;
              puVar13 = puVar13 + 1;
            }
          }
          DAT_0042ab20 = DAT_0042ab20 + DAT_00429bf0;
          piVar10 = piVar10 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= DAT_0042ab04);
      }
    }
  }
  return;
}


// ==== FUN_0041fade @ 0041fade

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041fade(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

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
  
  DAT_0042ab34 = '\0';
  if ((int)param_3 < 0) {
    DAT_0042ab34 = '\x01';
    param_3 = -param_3;
  }
  else if (param_3 == 0) {
    param_3 = 1;
  }
  DAT_0042ab35 = '\0';
  if ((int)param_4 < 0) {
    DAT_0042ab35 = '\x01';
    param_4 = -param_4;
  }
  else if (param_4 == 0) {
    param_4 = 1;
  }
  uVar4 = *param_5 / param_3;
  uVar1 = ((ulonglong)(uint)*param_5 % (ulonglong)param_3 << 0x20) / (ulonglong)param_3;
  uVar5 = (uint)uVar1;
  DAT_0042ab42 = param_5[1] / param_4;
  uVar2 = ((ulonglong)(uint)param_5[1] % (ulonglong)param_4 << 0x20) / (ulonglong)param_4;
  DAT_0042ab3e = (uint)uVar2;
  DAT_0042ab4e = (uint)*param_5;
  iVar6 = param_1 + _DAT_00429bd8;
  iVar8 = param_3 + iVar6 + -1;
  iVar7 = param_2 + _DAT_00429bdc;
  DAT_0042ab30 = param_4 + iVar7 + -1;
  DAT_0042ab2c = iVar7;
  DAT_0042ab36 = uVar5;
  DAT_0042ab3a = uVar4;
  if ((((iVar6 <= DAT_00429be4) && (DAT_00429be0 <= iVar8)) && (iVar7 <= DAT_00429bec)) &&
     (DAT_00429be8 <= DAT_0042ab30)) {
    DAT_0042ab46 = 0;
    _DAT_0042ab4a = 0;
    puVar10 = param_5 + 2;
    DAT_0042ab24 = iVar6;
    if ((iVar6 < DAT_00429be0) && (DAT_0042ab24 = DAT_00429be0, DAT_0042ab34 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar6 - DAT_00429be0) * (uVar1 & 0xffffffff);
      DAT_0042ab46 = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + -(iVar6 - DAT_00429be0) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    DAT_0042ab28 = iVar8;
    if ((DAT_00429be4 < iVar8) && (DAT_0042ab28 = DAT_00429be4, DAT_0042ab34 != '\0')) {
      lVar3 = (ulonglong)(uint)(iVar8 - DAT_00429be4) * (uVar1 & 0xffffffff);
      DAT_0042ab46 = DAT_0042ab46 + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + (iVar8 - DAT_00429be4) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    if ((iVar7 < DAT_00429be8) && (DAT_0042ab2c = DAT_00429be8, DAT_0042ab35 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar7 - DAT_00429be8) * (uVar2 & 0xffffffff);
      _DAT_0042ab4a = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                (-(iVar7 - DAT_00429be8) * DAT_0042ab42 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0042ab4e);
    }
    iVar6 = DAT_0042ab30;
    if ((DAT_00429bec < DAT_0042ab30) && (iVar6 = DAT_00429bec, DAT_0042ab35 == '\0')) {
      lVar3 = (ulonglong)(uint)(DAT_0042ab30 - DAT_00429bec) * (uVar2 & 0xffffffff);
      _DAT_0042ab4a = _DAT_0042ab4a + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                ((DAT_0042ab30 - DAT_00429bec) * DAT_0042ab42 + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0042ab4e);
    }
    DAT_0042ab42 = DAT_0042ab42 * DAT_0042ab4e;
    DAT_0042ab30 = iVar6;
    if (DAT_0042ab34 != '\0') {
      DAT_0042ab52 = puVar10;
      if (DAT_0042ab35 == '\0') {
        DAT_0042ab20 = (char *)(DAT_00429bf0 * DAT_0042ab2c + DAT_0042ab28 + _DAT_00429bd4);
        DAT_0042ab28 = DAT_0042ab28 - (DAT_0042ab24 + -1);
        DAT_0042ab30 = iVar6 - (DAT_0042ab2c + -1);
        iVar6 = DAT_0042ab28;
        uVar9 = DAT_0042ab46;
        pcVar11 = DAT_0042ab20;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_0042ab30;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_0042ab4a,DAT_0042ab3e);
          _DAT_0042ab4a = _DAT_0042ab4a + DAT_0042ab3e;
          if (bVar12) {
            DAT_0042ab52 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab4e);
          }
          puVar10 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab42);
          DAT_0042ab20 = DAT_0042ab20 + DAT_00429bf0;
          DAT_0042ab30 = DAT_0042ab30 + -1;
          iVar6 = DAT_0042ab28;
          uVar9 = DAT_0042ab46;
          pcVar11 = DAT_0042ab20;
          DAT_0042ab52 = puVar10;
        } while (DAT_0042ab30 != 0 && 0 < iVar7);
      }
      else {
        DAT_0042ab20 = (char *)(DAT_00429bf0 * iVar6 + DAT_0042ab28 + _DAT_00429bd4);
        DAT_0042ab28 = DAT_0042ab28 - (DAT_0042ab24 + -1);
        DAT_0042ab30 = iVar6 - (DAT_0042ab2c + -1);
        iVar6 = DAT_0042ab28;
        uVar9 = DAT_0042ab46;
        pcVar11 = DAT_0042ab20;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_0042ab30;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_0042ab4a,DAT_0042ab3e);
          _DAT_0042ab4a = _DAT_0042ab4a + DAT_0042ab3e;
          if (bVar12) {
            DAT_0042ab52 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab4e);
          }
          puVar10 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab42);
          DAT_0042ab20 = DAT_0042ab20 + -DAT_00429bf0;
          DAT_0042ab30 = DAT_0042ab30 + -1;
          iVar6 = DAT_0042ab28;
          uVar9 = DAT_0042ab46;
          pcVar11 = DAT_0042ab20;
          DAT_0042ab52 = puVar10;
        } while (DAT_0042ab30 != 0 && 0 < iVar7);
      }
    }
    uVar5 = DAT_0042ab3a;
    uVar4 = DAT_0042ab36;
    if (DAT_0042ab35 != '\0') {
      DAT_0042ab20 = (char *)(DAT_00429bf0 * DAT_0042ab30 + DAT_0042ab24 + _DAT_00429bd4);
      DAT_0042ab28 = DAT_0042ab28 - (DAT_0042ab24 + -1);
      DAT_0042ab30 = DAT_0042ab30 - (DAT_0042ab2c + -1);
      iVar6 = DAT_0042ab28;
      uVar9 = DAT_0042ab46;
      pcVar11 = DAT_0042ab20;
      DAT_0042ab52 = puVar10;
      do {
        do {
          if ((char)*puVar10 != '\0') {
            *pcVar11 = (char)*puVar10;
          }
          iVar7 = DAT_0042ab30;
          puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
          iVar6 = iVar6 + -1;
          uVar9 = uVar9 + uVar4;
          pcVar11 = pcVar11 + 1;
        } while (iVar6 != 0);
        bVar12 = CARRY4(_DAT_0042ab4a,DAT_0042ab3e);
        _DAT_0042ab4a = _DAT_0042ab4a + DAT_0042ab3e;
        if (bVar12) {
          DAT_0042ab52 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab4e);
        }
        puVar10 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab42);
        DAT_0042ab20 = DAT_0042ab20 + -DAT_00429bf0;
        DAT_0042ab30 = DAT_0042ab30 + -1;
        iVar6 = DAT_0042ab28;
        uVar9 = DAT_0042ab46;
        pcVar11 = DAT_0042ab20;
        DAT_0042ab52 = puVar10;
      } while (DAT_0042ab30 != 0 && 0 < iVar7);
    }
    uVar5 = DAT_0042ab3a;
    uVar4 = DAT_0042ab36;
    DAT_0042ab20 = (char *)(DAT_00429bf0 * DAT_0042ab2c + DAT_0042ab24 + _DAT_00429bd4);
    DAT_0042ab28 = DAT_0042ab28 - (DAT_0042ab24 + -1);
    DAT_0042ab30 = DAT_0042ab30 - (DAT_0042ab2c + -1);
    iVar6 = DAT_0042ab28;
    uVar9 = DAT_0042ab46;
    pcVar11 = DAT_0042ab20;
    DAT_0042ab52 = puVar10;
    do {
      do {
        if ((char)*puVar10 != '\0') {
          *pcVar11 = (char)*puVar10;
        }
        iVar7 = DAT_0042ab30;
        puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
        iVar6 = iVar6 + -1;
        uVar9 = uVar9 + uVar4;
        pcVar11 = pcVar11 + 1;
      } while (iVar6 != 0);
      bVar12 = CARRY4(_DAT_0042ab4a,DAT_0042ab3e);
      _DAT_0042ab4a = _DAT_0042ab4a + DAT_0042ab3e;
      if (bVar12) {
        DAT_0042ab52 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab4e);
      }
      puVar10 = (ushort *)((int)DAT_0042ab52 + DAT_0042ab42);
      DAT_0042ab20 = DAT_0042ab20 + DAT_00429bf0;
      DAT_0042ab30 = DAT_0042ab30 + -1;
      iVar6 = DAT_0042ab28;
      uVar9 = DAT_0042ab46;
      pcVar11 = DAT_0042ab20;
      DAT_0042ab52 = puVar10;
    } while (DAT_0042ab30 != 0 && 0 < iVar7);
  }
  return;
}


// ==== FUN_0041ffcb @ 0041ffcb

void __cdecl FUN_0041ffcb(undefined4 *param_1,undefined4 *param_2,uint param_3)

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


// ==== FUN_0041fff8 @ 0041fff8

undefined8 __cdecl FUN_0041fff8(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_004200e3 @ 004200e3

undefined4 __cdecl FUN_004200e3(int *param_1,int *param_2)

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


// ==== FUN_0042011f @ 0042011f

void __cdecl FUN_0042011f(int *param_1,int *param_2)

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


// ==== FUN_0042017c @ 0042017c

void __cdecl FUN_0042017c(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_004201d2 @ 004201d2

undefined4 __cdecl FUN_004201d2(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004200e3(param_3,param_2);
  if (iVar1 != 0) {
    FUN_0042017c(&DAT_0042ab64,param_2,param_3);
    DAT_0042ab74 = ((param_2[2] - *param_2) + 1U & 0xffff) *
                   ((param_2[3] - param_2[1]) + 1U & 0xffff);
    if (((DAT_0042ab6c - DAT_0042ab64) + 1U & 0xffff) *
        ((DAT_0042ab70 - DAT_0042ab68) + 1U & 0xffff) <=
        ((param_3[2] - *param_3) + 1U & 0xffff) * ((param_3[3] - param_3[1]) + 1U & 0xffff) +
        DAT_0042ab74) {
      *param_1 = DAT_0042ab64;
      param_1[1] = DAT_0042ab68;
      param_1[2] = DAT_0042ab6c;
      param_1[3] = DAT_0042ab70;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004202ab @ 004202ab

int __cdecl FUN_004202ab(int *param_1)

{
  return (param_1[2] - *param_1) + 1;
}


// ==== FUN_004202bb @ 004202bb

int __cdecl FUN_004202bb(int param_1)

{
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) + 1;
}


// ==== FUN_004202cc @ 004202cc

void __cdecl FUN_004202cc(char *param_1,uint param_2,char param_3)

{
  uint uVar1;
  char *pcVar2;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (*param_1 == param_3) goto LAB_00420312;
LAB_004202ee:
    if (param_1[1] == param_3) goto LAB_0042031b;
LAB_004202f5:
    if (param_1[2] == param_3) goto LAB_00420325;
    while (param_1[3] == param_3) {
      while( true ) {
        param_1[3] = '\0';
        param_1 = param_1 + 4;
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) goto LAB_0042033c;
        if (*param_1 != param_3) goto LAB_004202ee;
LAB_00420312:
        *param_1 = '\0';
        if (param_1[1] != param_3) goto LAB_004202f5;
LAB_0042031b:
        param_1[1] = '\0';
        if (param_1[2] != param_3) break;
LAB_00420325:
        param_1[2] = '\0';
        if (param_1[3] != param_3) goto LAB_00420303;
      }
    }
LAB_00420303:
    param_1 = param_1 + 4;
  }
LAB_0042033c:
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


// ==== FUN_00420358 @ 00420358

bool __cdecl FUN_00420358(char *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  *param_4 = param_2;
  param_4[2] = 0xffffffff;
  param_4[1] = param_3;
  param_4[3] = 0xffffffff;
  uVar2 = 0;
LAB_00420383:
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
          if (param_3 != 0) goto LAB_00420383;
          goto LAB_004203bc;
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
LAB_004203bc:
      return *param_4 != param_2;
    }
  } while( true );
}


// ==== FUN_004203d0 @ 004203d0

void FUN_004203d0(void)

{
  FUN_004203ea();
  FUN_00420409();
  return;
}


// ==== FUN_004203ea @ 004203ea

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004203ea(void)

{
  _DAT_004334d8 = 0x5452494d;
  return;
}


// ==== FUN_00420409 @ 00420409

void FUN_00420409(void)

{
  _atexit(FUN_00420426);
  return;
}


// ==== FUN_00420426 @ 00420426

void FUN_00420426(void)

{
  FUN_004205b8();
  return;
}


// ==== FUN_00420440 @ 00420440

bool __cdecl FUN_00420440(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00415272(&DAT_00432f20,param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_00421080();
    *puVar2 = DAT_00432f28;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = DAT_00432f2c + -1;
    puVar2[5] = 0;
    puVar2[6] = DAT_00432f30 + -1;
    puVar2[7] = DAT_00432f34;
  }
  return iVar1 != 0;
}


// ==== FUN_004204ff @ 004204ff

undefined4 * __cdecl FUN_004204ff(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_00421080();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_00421080();
  *puVar1 = DAT_00432f28;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = DAT_00432f2c + -1;
  puVar1[5] = 0;
  puVar1[6] = DAT_00432f30 + -1;
  puVar1[7] = DAT_00432f34;
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_004205b8 @ 004205b8

void FUN_004205b8(void)

{
  FUN_004155c0(&DAT_00432f20);
  return;
}


// ==== FUN_004205d7 @ 004205d7

void __cdecl FUN_004205d7(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00420600 @ 00420600

void __cdecl FUN_00420600(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00420629 @ 00420629

uint __cdecl FUN_00420629(int param_1)

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


// ==== FUN_004206a3 @ 004206a3

uint __cdecl FUN_004206a3(int param_1)

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


// ==== FUN_0042071e @ 0042071e

uint __cdecl FUN_0042071e(int param_1)

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


// ==== FUN_004207ad @ 004207ad

int __cdecl FUN_004207ad(int param_1)

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


// ==== FUN_00420883 @ 00420883

int __cdecl FUN_00420883(int param_1)

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


// ==== FUN_004208f0 @ 004208f0

void FUN_004208f0(void)

{
  if (DAT_004334f4 == 0) {
    DAT_004334f4 = 1;
    if (DAT_004334e4 != (HWND)0x0) {
      if (DAT_004334f8 == (int *)0x0) {
        PostMessageA(DAT_004334e4,0x42b,DAT_004334ec,DAT_004334f0);
      }
      else if (*DAT_004334f8 != 0) {
        PostMessageA(DAT_004334e4,0x42b,DAT_004334ec,DAT_004334f0);
      }
    }
    DAT_004334f4 = 0;
  }
  return;
}


// ==== FUN_0042098f @ 0042098f

void FUN_0042098f(void)

{
  DAT_004334f8 = 0;
  DAT_004334e4 = 0;
  FUN_004209b8();
  return;
}


// ==== FUN_004209b8 @ 004209b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004209b8(void)

{
  undefined4 uVar1;
  timecaps_tag local_10;
  MMRESULT local_8;
  
  if (DAT_004334e8 == 0) {
    local_8 = timeGetDevCaps(&local_10,8);
    if (local_8 == 0x61) {
      uVar1 = 0;
    }
    else {
      DAT_004334e0 = local_10.wPeriodMin;
      _DAT_004334dc = local_10.wPeriodMax;
      if (local_10.wPeriodMin <= DAT_0042ab78) {
        local_10.wPeriodMin = DAT_0042ab78;
      }
      DAT_004334f0 = DAT_0042ab7c;
      DAT_004334ec = local_10.wPeriodMin;
      DAT_004334e8 = timeSetEvent(local_10.wPeriodMin,DAT_0042ab7c,FUN_004208f0,1,1);
      if (DAT_004334e8 == 0) {
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


// ==== FUN_00420a6f @ 00420a6f

void __cdecl FUN_00420a6f(undefined4 param_1,undefined4 param_2)

{
  DAT_004334f8 = param_2;
  DAT_004334e4 = param_1;
  return;
}


// ==== FUN_00420a8f @ 00420a8f

void FUN_00420a8f(void)

{
  DAT_004334e4 = 0;
  DAT_004334f8 = 0;
  if (DAT_004334e8 != 0) {
    timeKillEvent(DAT_004334e8);
    DAT_004334e8 = 0;
  }
  return;
}


// ==== FUN_00420adb @ 00420adb

void __cdecl FUN_00420adb(int param_1)

{
  if (param_1 == 0) {
    if (DAT_004334e8 != 0) {
      timeKillEvent(DAT_004334e8);
      DAT_004334e8 = 0;
    }
  }
  else if ((DAT_004334e8 == 0) && (DAT_004334e4 != 0)) {
    FUN_004209b8();
  }
  return;
}


// ==== FUN_00420b60 @ 00420b60

void FUN_00420b60(void)

{
  HDC hdc;
  HPALETTE pHVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_0042ab82; local_8 = local_8 + 1) {
    (&DAT_0042ab84)[local_8 * 4] = 0;
    (&DAT_0042ab85)[local_8 * 4] = 0;
    (&DAT_0042ab86)[local_8 * 4] = 0;
    (&DAT_0042ab87)[local_8 * 4] = 4;
  }
  hdc = GetDC((HWND)0x0);
  pHVar1 = CreatePalette((LOGPALETTE *)&DAT_0042ab80);
  if (pHVar1 != (HPALETTE)0x0) {
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    RealizePalette(hdc);
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    DeleteObject(pHVar1);
  }
  ReleaseDC((HWND)0x0,hdc);
  return;
}


// ==== FUN_00420c34 @ 00420c34

void __cdecl FUN_00420c34(int param_1,int *param_2)

{
  int iVar1;
  HDC hdc;
  int local_8;
  
  hdc = GetDC((HWND)0x0);
  GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)&DAT_0042ab84);
  GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)&DAT_0042af5c);
  ReleaseDC((HWND)0x0,hdc);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_0042ab84)[local_8 * 4];
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_0042ab85)[local_8 * 4];
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_0042ab86)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_0042ab87)[local_8 * 4] = 0;
    *(undefined *)(param_1 + 0x3da + local_8 * 4) = (&DAT_0042af5c)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d9 + local_8 * 4) = (&DAT_0042af5d)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d8 + local_8 * 4) = (&DAT_0042af5e)[local_8 * 4];
    *(undefined1 *)(param_1 + 0x3db + local_8 * 4) = 0;
    (&DAT_0042af5f)[local_8 * 4] = 0;
  }
  iVar1 = *param_2;
  for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
    (&DAT_0042ab84)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 2);
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_0042ab84)[local_8 * 4];
    (&DAT_0042ab85)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 1);
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_0042ab85)[local_8 * 4];
    (&DAT_0042ab86)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1);
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_0042ab86)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_0042ab87)[local_8 * 4] = 4;
  }
  CreatePalette((LOGPALETTE *)&DAT_0042ab80);
  return;
}


// ==== FUN_00420e30 @ 00420e30

void __cdecl FUN_00420e30(char param_1,int param_2)

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
  DAT_00433500 = param_1;
  bVar1 = (&DAT_00432f68)[param_1 * 4];
  bVar2 = (&DAT_00432f69)[param_1 * 4];
  bVar3 = (&DAT_00432f6a)[param_1 * 4];
  for (local_30 = 0; local_30 < 0x100; local_30 = local_30 + 1) {
    uVar5 = ((uint)bVar1 * param_2 + (uint)(byte)(&DAT_00432f68)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar5) {
      uVar5 = 0xff;
    }
    uVar6 = (param_2 * (uint)bVar2 + (uint)(byte)(&DAT_00432f69)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar6) {
      uVar6 = 0xff;
    }
    uVar7 = (param_2 * (uint)bVar3 + (uint)(byte)(&DAT_00432f6a)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    local_1c = 0;
    local_20 = 0xffffffff;
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      uVar8 = (uVar7 - (byte)(&DAT_00432f6a)[local_34 * 4]) *
              (uVar7 - (byte)(&DAT_00432f6a)[local_34 * 4]) +
              (uVar6 - (byte)(&DAT_00432f69)[local_34 * 4]) *
              (uVar6 - (byte)(&DAT_00432f69)[local_34 * 4]) +
              (uVar5 - (byte)(&DAT_00432f68)[local_34 * 4]) *
              (uVar5 - (byte)(&DAT_00432f68)[local_34 * 4]);
      if (uVar8 < local_20) {
        local_1c = local_34;
        local_20 = uVar8;
      }
    }
    (&DAT_00433508)[local_30] = (undefined1)local_1c;
  }
  return;
}


// ==== FUN_0042104c @ 0042104c

void __cdecl FUN_0042104c(byte *param_1,int param_2)

{
  FUN_0041ef8e(0x433508,param_1,param_2);
  return;
}


// ==== FUN_00421080 @ 00421080

void FUN_00421080(void)

{
  FUN_0041ec80();
  return;
}


// ==== FUN_00421095 @ 00421095

undefined4 * __cdecl FUN_00421095(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_00421080();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_00421080();
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


// ==== FUN_004210de @ 004210de

undefined4 FUN_004210de(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00421080();
  return *puVar1;
}


// ==== FUN_004210f5 @ 004210f5

undefined4 FUN_004210f5(void)

{
  int iVar1;
  
  iVar1 = FUN_00421080();
  return *(undefined4 *)(iVar1 + 0x1c);
}


// ==== FUN_0042110d @ 0042110d

void __cdecl FUN_0042110d(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  FUN_0041ec86(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_00421139 @ 00421139

void __cdecl FUN_00421139(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0041f3f6(param_1,param_2,param_3);
  return;
}


// ==== FUN_0042115d @ 0042115d

void __thiscall FUN_0042115d(void *this,int *param_1,int param_2)

{
  FUN_0041efaf(this,param_1,param_2);
  return;
}


// ==== FUN_00421181 @ 00421181

void __cdecl FUN_00421181(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0041f768(param_1,param_2,param_3);
  return;
}


// ==== FUN_004211a5 @ 004211a5

void __cdecl FUN_004211a5(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  FUN_0041fade(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_004211d1 @ 004211d1

void __cdecl FUN_004211d1(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    FUN_0042011f(param_1,param_1);
  }
  else {
    FUN_0042011f(param_1,param_2);
  }
  return;
}


// ==== FID_conflict:_memcpy @ 00421210

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
switchD_004212d9_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_004212d9_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_004212d9_caseD_3:
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
        goto switchD_004212d9_caseD_1;
      case 2:
        goto switchD_004212d9_caseD_2;
      case 3:
        goto switchD_004212d9_caseD_3;
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
switchD_00421240_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_00421240_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_00421240_caseD_3:
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
      goto switchD_00421240_caseD_1;
    case 2:
      goto switchD_00421240_caseD_2;
    case 3:
      goto switchD_00421240_caseD_3;
    }
  }
  return _Dst;
}


// ==== FUN_00421360 @ 00421360

uint * __cdecl FUN_00421360(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_00421448;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00421448:
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


// ==== FUN_00421370 @ 00421370

uint * __cdecl FUN_00421370(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0042138c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_004213bf;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x004213db;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0042138c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x004213db;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x004213db;
    }
  }
LAB_004213bf:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x004213db:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00421448:
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
    if (bVar1 == 0) goto LAB_00421448;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _memset @ 00421450

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


// ==== _strlen @ 004214b0

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
    if (((uint)puVar2 & 3) == 0) goto LAB_004214d0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00421503:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_004214d0:
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
  goto LAB_00421503;
}


// ==== _strncmp @ 00421530

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


// ==== `eh_vector_constructor_iterator' @ 00421570

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
  puStack_c = &DAT_00427000;
  puStack_10 = &LAB_00422028;
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
  FUN_004215e0();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_004215e0 @ 004215e0

void FUN_004215e0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== __onexit @ 00421600

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = __msize(DAT_0043385c);
  if (sVar1 < (uint)((int)DAT_00433858 + (4 - (int)DAT_0043385c))) {
    sVar1 = __msize(DAT_0043385c);
    pvVar2 = _realloc(DAT_0043385c,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      return (_onexit_t)0x0;
    }
    DAT_00433858 = (undefined4 *)
                   (((int)DAT_00433858 - (int)DAT_0043385c & 0xfffffffcU) + (int)pvVar2);
    DAT_0043385c = pvVar2;
  }
  *DAT_00433858 = _Func;
  DAT_00433858 = DAT_00433858 + 1;
  return _Func;
}


// ==== _atexit @ 00421680

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}


// ==== `eh_vector_destructor_iterator' @ 004216e0

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
  puStack_c = &DAT_00427010;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_00421750();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00421750 @ 00421750

void FUN_00421750(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== __ArrayUnwind @ 00421770

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
  puStack_c = &DAT_00427020;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== __global_unwind2 @ 00421808

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x421820,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0042184a

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
  puStack_18 = &LAB_00421828;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_004218de();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== __abnormal_termination @ 004218b2

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
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_00421828) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_004218d5 @ 004218d5

void __fastcall FUN_004218d5(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0042af98 = param_1;
  DAT_0042af94 = in_EAX;
  DAT_0042af9c = unaff_EBP;
  return;
}


// ==== FUN_004218de @ 004218de

void FUN_004218de(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0042af98 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0042af94 = in_EAX;
  DAT_0042af9c = unaff_EBP;
  return;
}


// ==== _JumpToContinuation @ 00421900

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0042192c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== _CallMemberFunction0 @ 00421940

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421945. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00421950

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421955. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00421960

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00421965. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== _UnwindNestedFrames @ 00421970

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x42199c,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}


// ==== ___CxxFrameHandler @ 004219d0

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


// ==== _CallCatchBlock2 @ 00421a10

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
  local_10 = &LAB_00421a80;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== _CallSETranslator @ 00421ab0

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
  local_14 = 0x421b47;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_0042b020)(*(undefined4 *)param_1,&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}


// ==== TranslatorGuardHandler @ 00421b90

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
                    /* WARNING: Could not recover jumptable at 0x00421bef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// ==== FUN_00421c00 @ 00421c00

void __cdecl FUN_00421c00(void *param_1)

{
  _free(param_1);
  return;
}


// ==== _strcmp @ 00421c10

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
      if (bVar4 != *_Str2) goto LAB_00421c54;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00421c20;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00421c54;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_00421c54;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00421c20:
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
LAB_00421c54:
  return (uint)bVar5 * -2 + 1;
}


// ==== _rand @ 00421ca0

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_0042afa0 = DAT_0042afa0 * 0x343fd + 0x269ec3;
  return (DAT_0042afa0 & 0x7fff0000) >> 0x10;
}


// ==== __fpmath @ 00421cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_00421d00();
  _DAT_0042afb0 = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


// ==== FUN_00421d00 @ 00421d00

void FUN_00421d00(void)

{
  PTR_LAB_0042b044 = &LAB_00423100;
  PTR_LAB_0042b048 = &LAB_00423180;
  PTR_LAB_0042b04c = &LAB_00423090;
  PTR_LAB_0042b050 = &LAB_00423160;
  PTR_LAB_0042b040 = &LAB_00423520;
  PTR_LAB_0042b054 = &LAB_00423520;
  return;
}


// ==== _free @ 00421d40

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
    HeapFree(DAT_00433854,0,_Memory);
  }
  return;
}


// ==== _malloc @ 00421d90

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0042b888);
  return pvVar1;
}


// ==== __nh_malloc @ 00421db0

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


// ==== __heap_alloc @ 00421e00

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_0042b884) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_00433854,0,dwBytes);
  return pvVar2;
}


// ==== entry @ 00421e40

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
  puStack_c = &DAT_00427030;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0042afec = DVar2 >> 8 & 0xff;
  DAT_0042afe0 = DVar2 >> 0x10;
  _DAT_0042afe8 = DVar2 & 0xff;
  _DAT_0042afe4 = _DAT_0042afe8 * 0x100 + _DAT_0042afec;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00433860 = (byte *)GetCommandLineA();
  DAT_0042afc0 = ___crtGetEnvironmentStringsA();
  if ((DAT_0042afc0 == (LPVOID)0x0) || (DAT_00433860 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_00433860;
  pbVar6 = DAT_00433860;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_00433860 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_00421f45;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_00421f45:
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
  iVar3 = FUN_004121f8(pHVar5,uVar7,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(iVar3);
}


// ==== __amsg_exit @ 00421fe0

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0042afcc == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_0042afc8)(0xff);
  return;
}


// ==== operator_new @ 00422010

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== FUN_004220e5 @ 004220e5

void FUN_004220e5(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __cinit @ 00422100

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (PTR___fpmath_0042afb4 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_0042afb4)();
  }
  __initterm((undefined4 *)&DAT_00428064,(undefined4 *)&DAT_0042806c);
  iVar1 = __initterm((undefined4 *)&DAT_00428000,(undefined4 *)&DAT_00428060);
  return iVar1;
}


// ==== _exit @ 00422130

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 00422150

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 00422170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0042b01c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0042b018 = 1;
  DAT_0042b014 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0043385c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00433858 + -4), DAT_0043385c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0043385c <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00428070,(undefined4 *)&DAT_00428074);
  }
  __initterm((undefined4 *)&DAT_00428078,(undefined4 *)&DAT_0042807c);
  if (param_3 == 0) {
    DAT_0042b01c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 00422220

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


// ==== _realloc @ 00422240

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
          local_c = HeapReAlloc(DAT_00433854,0,_Memory,_NewSize);
        }
        else {
          if (_NewSize < DAT_0042b884) {
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
          local_c = HeapAlloc(DAT_00433854,0,_NewSize);
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
      if ((local_c != (undefined4 *)0x0) || (DAT_0042b888 == 0)) {
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


// ==== __msize @ 004223f0

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
  SVar2 = HeapSize(DAT_00433854,0,_Memory);
  return SVar2;
}


// ==== terminate @ 00422440

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
  puStack_c = &DAT_00427040;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_0042b024 != (code *)0x0) {
    local_8 = 1;
    (*DAT_0042b024)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 004224c0

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
  puStack_c = &DAT_00427058;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_terminate_0042b02c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_terminate_0042b02c)();
  }
  local_8 = 0xffffffff;
  terminate();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== ___InternalCxxFrameHandler @ 00422540

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


// ==== FindHandler @ 00422600

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
  pEVar4 = DAT_0042b034;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_0042b034 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_0042b034;
    param_3 = DAT_0042b038;
    iVar5 = _ValidateRead(DAT_0042b034,1);
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
LAB_004227b6:
                bVar12 = true;
              }
              else {
                if (*(int *)(pbVar3 + 4) == iVar10) {
LAB_0042278e:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_004227b6;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00422785:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_0042278a;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00422785;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_0042278a:
                  if (iVar10 == 0) goto LAB_0042278e;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_00422814;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_00422814:
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


// ==== FindHandlerForForeignException @ 004228a0

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
  
  if (((DAT_0042b020 == 0) ||
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


// ==== GetRangeOfTrysToCheck @ 00422980

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


// ==== ___FrameUnwindToState @ 00422a20

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
  puStack_c = &DAT_00427070;
  puStack_10 = &LAB_00422028;
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


// ==== CatchIt @ 00422b10

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


// ==== CallCatchBlock @ 00422bb0

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
  puStack_c = &DAT_00427080;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &local_14;
  DAT_0042b034 = param_1;
  DAT_0042b038 = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00422c75();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== FUN_00422c75 @ 00422c75

void FUN_00422c75(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  **(undefined4 **)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
  DAT_0042b034 = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_0042b038 = *(undefined4 *)(unaff_EBP + -0x24);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (*(int *)(unaff_EBP + -0x1c) != 0)) {
    iVar2 = __abnormal_termination();
    DestructExceptionObject(*(EHExceptionRecord **)(unaff_EBP + 8),(uchar)iVar2);
  }
  return;
}


// ==== BuildCatchObject @ 00422cf0

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
  puStack_c = &DAT_00427098;
  puStack_10 = &LAB_00422028;
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
            goto LAB_00422ede;
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
            goto LAB_00422ede;
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
          goto LAB_00422ede;
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
        goto LAB_00422ede;
      }
    }
    _inconsistency();
  }
LAB_00422ede:
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== DestructExceptionObject @ 00422ef0

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
  puStack_c = &DAT_004270a8;
  puStack_10 = &LAB_00422028;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== AdjustPointer @ 00422f70

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


// ==== __CallSettingFrame@12 @ 00422fa0

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_004218d5(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_004218d5(param_3);
  return;
}


// ==== __setdefaultprecision @ 00422ff0

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 00423010

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 00423060

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


// ==== __cftoe @ 004231d0

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
  
  _Digits = DAT_00433608;
  if (DAT_0042b058 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (uint)(*_Digits == 0x2d) + (uint)(0 < (int)_SizeInBytes),_SizeInBytes + 1,
              (int)_Digits,unaff_EBP);
  }
  else {
    __shift(_Buf + (*DAT_00433608 == 0x2d),(uint)(0 < (int)_SizeInBytes));
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
    *pcVar2 = DAT_0042bbe0;
  }
  bVar4 = DAT_0042b058 == '\0';
  *(undefined4 *)(pcVar2 + _SizeInBytes + bVar4) = DAT_00427100;
  *(undefined2 *)(pcVar2 + _SizeInBytes + bVar4 + 4) = DAT_00427104;
  pcVar2 = pcVar2 + (DAT_0042b058 == '\0') + _SizeInBytes;
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


// ==== __cftof @ 00423310

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
  
  _Digits = DAT_00433608;
  if (DAT_0042b058 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (*_Digits == 0x2d),_Digits[1] + _SizeInBytes,(int)_Digits,unaff_EBP);
  }
  else if (DAT_0042b05c == _SizeInBytes) {
    iVar1 = DAT_0042b05c + (*DAT_00433608 == 0x2d);
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
    *pcVar4 = DAT_0042bbe0;
    iVar1 = _Digits[1];
    if (iVar1 < 0) {
      if (DAT_0042b058 == '\0') {
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


// ==== __cftog @ 00423410

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
  
  DAT_00433608 = (int *)__fltout();
  DAT_0042b05c = DAT_00433608[1] + -1;
  iVar1 = *DAT_00433608;
  __fptostr(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_00433608,unaff_EBP);
  DAT_0042b060 = DAT_0042b05c < DAT_00433608[1] + -1;
  iVar3 = DAT_00433608[1] + -1;
  if ((-5 < iVar3) && (iVar3 < (int)param_3)) {
    bVar5 = DAT_0042b05c < DAT_00433608[1] + -1;
    pcVar2 = param_2 + (iVar1 == 0x2d);
    DAT_0042b05c = iVar3;
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
  DAT_0042b05c = iVar3;
  __cftoe_g(param_1,param_2,param_3,param_4);
  return;
}


// ==== __cftoe_g @ 004234c0

/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftoe_g(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int unaff_retaddr;
  
  DAT_0042b058 = 1;
  __cftoe(param_1,param_2,param_3,param_4,unaff_retaddr);
  DAT_0042b058 = 0;
  return;
}


// ==== __cftof_g @ 004234f0

/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftof_g(double *param_1,char *param_2,size_t param_3)

{
  int unaff_retaddr;
  
  DAT_0042b058 = 1;
  __cftof(param_1,param_2,param_3,unaff_retaddr);
  DAT_0042b058 = 0;
  return;
}


// ==== __shift @ 00423590

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


// ==== __heap_init @ 004235c0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_00433854 = HeapCreate(1,0x1000,0);
  if (DAT_00433854 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_00433854);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 00423600

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
  
  if (DAT_0042b878 == 0) {
    lpMem = &PTR_LOOP_0042b068;
  }
  else {
    lpMem = HeapAlloc(DAT_00433854,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_0042b068) {
        if (PTR_LOOP_0042b068 == (undefined *)0x0) {
          PTR_LOOP_0042b068 = (undefined *)&PTR_LOOP_0042b068;
        }
        if (PTR_LOOP_0042b06c == (undefined *)0x0) {
          PTR_LOOP_0042b06c = (undefined *)&PTR_LOOP_0042b068;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_0042b068;
        lpMem[1] = PTR_LOOP_0042b06c;
        PTR_LOOP_0042b06c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_0042b068) {
    HeapFree(DAT_00433854,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 00423770

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0042b87c == param_1) {
    PTR_LOOP_0042b87c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_0042b068) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00433854,0,param_1);
    return;
  }
  DAT_0042b878 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 004237d0

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
  
  ppuVar4 = (undefined **)PTR_LOOP_0042b06c;
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
            DAT_0042b880 = DAT_0042b880 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_0042b06c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 004238b0

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_0042b068;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_0042b068) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 00423910

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_0042b880 = DAT_0042b880 + 1, DAT_0042b880 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00423960

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
  
  piVar12 = (int *)PTR_LOOP_0042b87c;
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
              PTR_LOOP_0042b87c = (undefined *)piVar12;
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
              PTR_LOOP_0042b87c = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_0042b87c != piVar12);
  ppuVar11 = &PTR_LOOP_0042b068;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_0042b068) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_0042b87c = (undefined *)ppuVar11;
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
  PTR_LOOP_0042b87c = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 00423be0

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


// ==== ___sbh_resize_block @ 00423d60

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


// ==== __callnewh @ 00423e30

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0043360c != (code *)0x0) {
    iVar1 = (*DAT_0043360c)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __ismbblead @ 00423ff0

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 00424010

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_0042b928 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_0042bbf2 + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 00424050

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
  cVar1 = *DAT_0042afc0;
  pcVar7 = DAT_0042afc0;
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
  _DAT_0042affc = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_0042afc0;
  pcVar7 = DAT_0042afc0;
  do {
    if (cVar1 == '\0') {
      _free(DAT_0042afc0);
      DAT_0042afc0 = (char *)0x0;
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


// ==== __setargv @ 00424140

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00433610,0x104);
  _DAT_0042b00c = &DAT_00433610;
  pbVar2 = &DAT_00433610;
  if (*DAT_00433860 != 0) {
    pbVar2 = DAT_00433860;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_0042aff4 = puVar1;
  _DAT_0042aff0 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 004241e0

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
      if (((*(byte *)((int)&DAT_0042b928 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_0042b928 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00424250;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00424250:
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
          if ((*(byte *)((int)&DAT_0042b928 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00424381;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_0042b928 + bVar1 + 1) & 4) != 0) {
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
LAB_00424381:
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


// ==== ___crtGetEnvironmentStringsA @ 004243c0

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
  if (DAT_0042b920 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0042b920 = 2;
    }
    else {
      DAT_0042b920 = 1;
    }
  }
  if (DAT_0042b920 != 1) {
    if (DAT_0042b920 != 2) {
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


// ==== __setmbcp @ 00424550

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
  if (CodePage == DAT_0042ba2c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_0042ba50;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_0042b928;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_0042ba60 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_0042ba48)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_0042b928 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_0042ba2c = CodePage;
      _DAT_0042ba30 = _CPtoLCID(CodePage);
      DAT_0042ba38 = *(undefined4 *)(&DAT_0042ba54 + local_18 * 0x30);
      DAT_0042ba3c = *(undefined4 *)(&DAT_0042ba58 + local_18 * 0x30);
      DAT_0042ba40 = *(undefined4 *)(local_18 * 0x30 + 0x42ba5c);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_0042bb40);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_0042b928;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_0042ba30 = 0;
      DAT_0042ba2c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_0042b928 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_0042b928 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_0042ba2c = CodePage;
      _DAT_0042ba30 = _CPtoLCID(CodePage);
    }
    DAT_0042ba38 = 0;
    DAT_0042ba3c = 0;
    DAT_0042ba40 = 0;
    return 0;
  }
  if (DAT_0042ba44 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00424730

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0042ba44 = 1;
                    /* WARNING: Could not recover jumptable at 0x0042474d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0042ba44 = 1;
                    /* WARNING: Could not recover jumptable at 0x00424762. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0042be40;
  }
  DAT_0042ba44 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00424780

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


// ==== setSBCS @ 004247e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0042b928;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0042ba38 = 0;
  DAT_0042ba2c = 0;
  _DAT_0042ba30 = 0;
  DAT_0042ba3c = 0;
  DAT_0042ba40 = 0;
  return;
}


// ==== ___initmbctable @ 00424810

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00424820

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
  DAT_00433850 = 0x20;
  DAT_00433750 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00433750 + 0x40);
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
    if ((int)DAT_00433850 < (int)UVar7) {
      piVar4 = &DAT_00433754;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_00433850;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00433850 = DAT_00433850 + 0x20;
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
      } while ((int)DAT_00433850 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00433750 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_00433750 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_00433850);
  return UVar7;
}


// ==== __FF_MSGBANNER @ 00424a00

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0042afcc == 1) || ((DAT_0042afcc == 0 && (DAT_0042afd0 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0042bbd8 != (code *)0x0) {
      (*DAT_0042bbd8)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00424a40

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
  piVar2 = &DAT_0042bb48;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_0042bbd8);
  if ((&DAT_0042bb48)[iVar4 * 2] == param_1) {
    if ((DAT_0042afcc == 1) || ((DAT_0042afcc == 0 && (DAT_0042afd0 == 1)))) {
      if ((DAT_00433750 == 0) ||
         (hFile = *(HANDLE *)(DAT_00433750 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x42bb4c);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x42bb4c);
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


// ==== _abort @ 00424c40

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


// ==== FUN_00424c90 @ 00424c90

int FUN_00424c90(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_00433714 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_00433714);
    if (iVar2 != 0) {
      iVar2 = (*DAT_00433714)(param_1);
      return iVar2;
    }
  }
  return 0;
}


// ==== FUN_00424cf0 @ 00424cf0

void FUN_00424cf0(void)

{
  SetUnhandledExceptionFilter(DAT_00433714);
  return;
}


// ==== _ValidateRead @ 00424d00

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 00424d20

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


// ==== _ValidateExecute @ 00424d40

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== __control87 @ 00424d60

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


// ==== __controlfp @ 00424db0

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== __abstract_cw @ 00424dd0

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


// ==== __hw_cw @ 00424e80

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}


// ==== __isctype @ 00424f20

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
    return (uint)*(ushort *)(PTR_DAT_0042bbe8 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_0042bbe8[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
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


// ==== FID_conflict:_tolower @ 00424fc0

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
  
  if (DAT_0042be30 == (_locale_t)0x0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      _C = _C + 0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_0042bbdc < 2) {
      uVar1 = *(ushort *)(PTR_DAT_0042bbe8 + _C * 2) & 1;
    }
    else {
      uVar1 = __isctype(_C,1);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_0042bbe8[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_0042be30,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __ZeroTail @ 004250b0

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


// ==== __IncMan @ 00425120

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


// ==== __RoundMan @ 00425190

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


// ==== __CopyMan @ 00425240

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


// ==== __FillZeroMan @ 00425260

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


// ==== __IsZeroMan @ 00425270

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


// ==== __ShrMan @ 00425290

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


// ==== __ld12cvt @ 00425340

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


// ==== FID_conflict:__ld12tod @ 00425510

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0042bdf8);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 00425530

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0042be10);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 00425550

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


// ==== FID_conflict:__atodbl @ 00425590

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


// ==== __fptostr @ 004255d0

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


// ==== __fltout @ 00425660

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
  _DAT_00433740 = _I10_OUTPUT(local_c,local_8,local_4,0x11,0,&DAT_00433718);
  _DAT_00433744 = &DAT_0043371c;
  _DAT_00433738 = (int)DAT_0043371a;
  _DAT_0043373c = (int)DAT_00433718;
  return &DAT_00433738;
}


// ==== ___dtold @ 004256d0

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


// ==== ___crtMessageBoxA @ 00425790

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0042be44 != (FARPROC)0x0) {
LAB_004257df:
    if (DAT_0042be48 != (FARPROC)0x0) {
      iVar1 = (*DAT_0042be48)();
    }
    if ((iVar1 != 0) && (DAT_0042be4c != (FARPROC)0x0)) {
      iVar1 = (*DAT_0042be4c)(iVar1);
    }
    iVar1 = (*DAT_0042be44)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0042be44 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0042be44 != (FARPROC)0x0) {
      DAT_0042be48 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0042be4c = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_004257df;
    }
  }
  return 0;
}


// ==== _strncpy @ 00425830

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
        goto joined_r0x0042586e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_004258ab;
        goto LAB_00425919;
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
joined_r0x00425915:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00425919:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_004258ab;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00425915;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00425915;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00425915;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0042586e:
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
LAB_004258ab:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _raise @ 00425930

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
    puVar6 = &DAT_0042be50;
    pcVar7 = DAT_0042be50;
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
    puVar6 = &DAT_0042be5c;
    pcVar7 = DAT_0042be5c;
    break;
  case 0x15:
    puVar6 = &DAT_0042be54;
    pcVar7 = DAT_0042be54;
    break;
  case 0x16:
    puVar6 = &DAT_0042be58;
    pcVar7 = DAT_0042be58;
  }
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
    __exit(3);
  }
  uVar2 = DAT_0042b918;
  uVar1 = DAT_0042b914;
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_0042b918 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_0042b914 = 0x8c;
      local_4 = uVar1;
      goto LAB_004259fc;
    }
  }
  else {
LAB_004259fc:
    if (_SigNum == 8) {
      if (DAT_0042b908 < DAT_0042b90c + DAT_0042b908) {
        puVar6 = (undefined4 *)(DAT_0042b908 * 0xc + 0x42b898);
        iVar4 = DAT_0042b90c;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_00425a3d;
    }
  }
  *puVar6 = 0;
LAB_00425a3d:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_0042b914);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_0042b914 = local_4;
  }
  DAT_0042b918 = uVar5;
  return 0;
}


// ==== siglookup @ 00425ac0

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_0042b890;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_0042b890 + DAT_0042b910 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


// ==== ___crtGetStringTypeA @ 00425b00

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
  
  iVar2 = DAT_0042be68;
  if (DAT_0042be68 == 0) {
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
  DAT_0042be68 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_0042be40;
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
    _Code_page = DAT_0042be30;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== ___crtLCMapStringA @ 00425c30

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
  
  if (DAT_0042be70 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042be70 = 1;
    }
    else {
      DAT_0042be70 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_0042be70 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_0042be70 != 1) {
    return DAT_0042be70;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_0042be40;
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
                               iVar2), iVar1 == 0)) goto LAB_00425dab;
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
      if (_LpDestStr == (LPSTR)0x0) goto LAB_00425e42;
      if ((int)_LpDestStr < iVar2) goto LAB_00425dab;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_00425e42:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_00425dab:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 00425e60

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
    if (*pcVar2 == '\0') goto LAB_00425e85;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_00425e85:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== ___addl @ 00425e90

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


// ==== ___add_12 @ 00425ec0

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


// ==== ___shl_12 @ 00425f30

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


// ==== ___shr_12 @ 00425f70

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


// ==== ___mtold12 @ 00425fb0

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


// ==== ___strgtold12 @ 004260a0

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
        if (DAT_0042bbe0 == bVar8) {
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
          if (bVar8 != 0x30) goto switchD_00426350_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_00426554;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_00426554;
      }
      if (DAT_0042bbe0 == bVar8) {
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
          goto switchD_00426350_caseD_2c;
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
        goto LAB_00426554;
      }
      if (DAT_0042bbe0 == bVar8) {
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
        if (DAT_0042bbdc < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042bbe8 + (uint)bVar8 * 2) & 4;
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
      if (DAT_0042bbe0 == bVar8) {
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
          goto switchD_00426350_caseD_2c;
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
        if (DAT_0042bbdc < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042bbe8 + (uint)bVar8 * 2) & 4;
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
        goto switchD_00426350_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_0042bbdc < 2) {
        uVar13 = *(ushort *)(PTR_DAT_0042bbe8 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_00426554;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = (byte *)(str + -1);
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00426554;
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
        goto LAB_00426554;
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
        goto LAB_00426554;
      }
      goto switchD_00426350_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_0042bbdc < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042bbe8 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_004264da;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_004264da:
      while( true ) {
        if (DAT_0042bbdc < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0042bbe8 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_00426350_caseD_2c:
      iVar7 = 10;
LAB_00426554:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (implicit_E == 0) goto switchD_00426350_caseD_2c;
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
      goto LAB_00426652;
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
        goto LAB_00426652;
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
LAB_00426652:
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


// ==== $I10_OUTPUT @ 004267f0

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
      *(undefined4 *)(param_6 + 2) = DAT_00427454;
      param_6[4] = DAT_00427458;
      *(undefined1 *)(param_6 + 5) = DAT_0042745a;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0042744c;
      param_6[4] = DAT_00427450;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_00427444;
      param_6[4] = DAT_00427448;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_0042743c;
    param_6[4] = DAT_00427440;
    *(undefined1 *)(param_6 + 5) = DAT_00427442;
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
LAB_00426b69:
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
    if (psVar7 < psVar1) goto LAB_00426b69;
    goto LAB_00426b3b;
  }
  if (psVar7 < psVar1) {
LAB_00426b35:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_00426b35;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_00426b3b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}


// ==== _calloc @ 00426b90

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
      if (DAT_0042b884 < dwBytes) {
LAB_00426bed:
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
          goto LAB_00426bed;
        }
      }
      puVar3 = HeapAlloc(DAT_00433854,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_0042b888 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== ___ld12mul @ 00426c30

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
    if (0 < (short)local_1a) goto LAB_00426e03;
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
LAB_00426e03:
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


// ==== ___multtenpow12 @ 00426ee0

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
  
  puVar4 = &DAT_0042be18;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar4 = &DAT_0042bf78;
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


