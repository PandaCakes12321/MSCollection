// ==== FUN_00401000 @ 00401000

int __cdecl FUN_00401000(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0040101f @ 0040101f

void FUN_0040101f(void)

{
  _memset(&DAT_00416f50,0,0x370);
  _memset(&DAT_00413e80,0,0x30d0);
  FID_conflict__memcpy(&DAT_00413e80,s_MD_PACK_00412068,8);
  DAT_00415b50 = 0;
  DAT_00415b51 = 0;
  DAT_00415b52 = 0;
  DAT_00413e8a = 0xc;
  _memset(&DAT_00415b24,0,0x28);
  FID_conflict__memcpy(&DAT_00415b14,s_MUDDLE_00412170,0xb);
  return;
}


// ==== FUN_004010b8 @ 004010b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004010b8(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0040101f();
  hFile = _lopen(s_MSPuzzle_dat_00412070,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00413e80,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_00415b14,s_MUDDLE_00412170,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00413e80,s_MD_PACK_00412068,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00416f78 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_00415b88 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00416f50 + local_10 * 0x2c,&DAT_00415b60 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00416f78 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00416f78 + local_10 * 0x2c) = 0;
        }
      }
      DAT_0041218c = (uint)(DAT_00415b50 == '\0');
      DAT_00412188 = (uint)(DAT_00415b51 == '\0');
      DAT_0041203c = (uint)(DAT_00415b52 == '\0');
      FID_conflict__memcpy(&DAT_00412040,&DAT_00415b24,0x28);
      _DAT_00412028 = (uint)DAT_00415b4c;
      if ((_DAT_00412028 == 0) || (0x14 < _DAT_00412028)) {
        _DAT_00412028 = 1;
      }
      _DAT_0041202c = (uint)DAT_00415b4d;
      if ((_DAT_0041202c == 0) || (5 < _DAT_0041202c)) {
        _DAT_0041202c = 1;
      }
      DAT_00412030 = (uint)(DAT_00415b4e == '\0');
      DAT_00412034 = (uint)(DAT_00415b4f == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0040101f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00401348 @ 00401348

undefined4 __cdecl FUN_00401348(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00416f78 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_004013e5 @ 004013e5

int __cdecl FUN_004013e5(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00416f78 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00416f50 + (local_1c + 1) * 0x2c,&DAT_00416f50 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00416f50 + local_1c * 0x2c,&DAT_00412040,0x28);
    *(int *)(&DAT_00416f78 + local_1c * 0x2c) = param_1;
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


// ==== FUN_00401529 @ 00401529

void FUN_00401529(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00415b60,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00415b60 + local_c * 0x30,&DAT_00416f50 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_00415b88 + local_c * 0x30) =
         *(undefined4 *)(&DAT_00416f78 + local_c * 0x2c);
  }
  DAT_00415b50 = DAT_0041218c == 0;
  DAT_00415b51 = DAT_00412188 == 0;
  DAT_00415b52 = DAT_0041203c == 0;
  DAT_00415b4c = DAT_00412028;
  DAT_00415b4d = DAT_0041202c;
  DAT_00415b4e = DAT_00412030 == 0;
  DAT_00415b4f = DAT_00412034 == 0;
  _memset(&DAT_00415b24,0,0x28);
  FID_conflict__memcpy(&DAT_00415b24,&DAT_00412040,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_00412070,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_00412070,0);
  }
  _lwrite(local_8,&DAT_00413e80,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_00401700 @ 00401700

undefined * __cdecl FUN_00401700(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0040ea60((uint *)&DAT_00417718,param_1);
  sVar1 = _strlen(&DAT_00417718);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_00417717)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_00417718)[param_3 + sVar1] = 0;
  return &DAT_00417718;
}


// ==== FUN_004017c9 @ 004017c9

void __cdecl FUN_004017c9(int param_1)

{
  if (DAT_004172c0 == (HDC)0x0) {
    if (param_1 == 0) {
      DAT_004172c0 = GetDC(DAT_00417308);
    }
    else {
      DAT_004172c0 = BeginPaint(DAT_00417308,(LPPAINTSTRUCT)&DAT_004172c8);
    }
  }
  else {
    MessageBeep(0xffffffff);
  }
  return;
}


// ==== FUN_00401829 @ 00401829

void __cdecl FUN_00401829(int param_1)

{
  if (DAT_004172c0 == (HDC)0x0) {
    MessageBeep(0xffffffff);
  }
  else {
    if (param_1 == 0) {
      ReleaseDC(DAT_00417308,DAT_004172c0);
    }
    else {
      EndPaint(DAT_00417308,(PAINTSTRUCT *)&DAT_004172c8);
    }
    DAT_004172c0 = (HDC)0x0;
  }
  return;
}


// ==== FUN_0040188f @ 0040188f

bool __cdecl FUN_0040188f(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_004018d8 @ 004018d8

bool __cdecl FUN_004018d8(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_0040196e @ 0040196e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_0040196e(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_00405778(DAT_0042a190,param_2,(LPCSTR)0x2,&local_10);
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
        DAT_00412184 = 0;
        _DAT_00417310 = 0x300;
        _DAT_00417312 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_00417314)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_00417315)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_00417316)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_00417317)[local_28 * 4] = 0;
        }
        if (DAT_00412180 == (HPALETTE)0x0) {
          DAT_00412180 = CreatePalette((LOGPALETTE *)&DAT_00417310);
        }
      }
      hPal = SelectPalette(param_1,DAT_00412180,0);
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


// ==== FUN_00401b80 @ 00401b80

HGLOBAL __cdecl FUN_00401b80(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_00405778(DAT_0042a190,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_00401c2a @ 00401c2a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00401c2a(HDC param_1,LPCSTR param_2,void *param_3,undefined1 *param_4)

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
  local_c = FUN_00405778(DAT_0042a190,param_2,(LPCSTR)0x2,&local_8);
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
      if (DAT_004123b0 < local_8) {
        local_8 = DAT_004123b0;
      }
      FID_conflict__memcpy(param_3,(void *)((int)_Src + iVar3),local_8);
      if ((DAT_00412184 != 0) && (local_42a == 8)) {
        DAT_00412184 = 0;
        _DAT_00417310 = 0x300;
        _DAT_00417312 = 0x100;
        for (local_444 = 0; puVar1 = local_10, local_444 < 0x100; local_444 = local_444 + 1) {
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 2] >> 2);
          local_10 = local_10 + 1;
          (&DAT_00417314)[local_444 * 4] = abStack_410[local_444 * 4 + 2];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 1] >> 2);
          local_10 = puVar1 + 2;
          (&DAT_00417315)[local_444 * 4] = abStack_410[local_444 * 4 + 1];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4] >> 2);
          local_10 = puVar1 + 3;
          (&DAT_00417316)[local_444 * 4] = abStack_410[local_444 * 4];
          (&DAT_00417317)[local_444 * 4] = 0;
        }
        DAT_00412180 = CreatePalette((LOGPALETTE *)&DAT_00417310);
        local_448 = SelectPalette(param_1,DAT_00412180,0);
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


// ==== FUN_00401ec0 @ 00401ec0

void FUN_00401ec0(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0041779c == 1) || (DAT_0041779c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00412320,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00412320,0x804,2,(DWORD_PTR)local_c);
    DAT_00412320 = 0;
    Sleep(1);
    DAT_0041779c = 0;
  }
  return;
}


// ==== FUN_00401f65 @ 00401f65

void FUN_00401f65(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0041218c != 0) && (DAT_0041779c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00412320,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0041779c = 3;
  }
  return;
}


// ==== FUN_00401fd8 @ 00401fd8

void __cdecl FUN_00401fd8(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041218c != 0) {
    if (DAT_0041779c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_00412320,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_00412320,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_004020b5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0041779c = 1;
    }
    else {
      FUN_004020b5(param_1);
    }
  }
  return;
}


// ==== FUN_004020b5 @ 004020b5

void __cdecl FUN_004020b5(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041218c == 0) {
    FUN_00401ec0();
  }
  else {
    if (((param_1 == DAT_00417798) && (0 < param_1)) && (DAT_0041779c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_00412320,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0041779c != 4) {
      FUN_00401ec0();
    }
    if (DAT_0041218c != 0) {
      if (0 < param_1) {
        DAT_00417798 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00417798;
      }
      if ((0 < param_1) && (param_1 < 4)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_004177a0 + param_1 * 0x100;
        local_20 = s_sequencer_00412324;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_00412320 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_00412320;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_00412320 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00412320,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0041779c = 1;
          }
          else {
            DAT_0041779c = 4;
          }
        }
        else {
          DAT_0041779c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_00402294 @ 00402294

void FUN_00402294(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0041218c != 0) {
    if (DAT_0041779c == 1) {
      if (DAT_00412320 == 0) {
        DAT_0041779c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_00412320,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00412320,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0041779c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0041779c = 4;
        }
      }
    }
    else if (DAT_0041779c == 4) {
      FUN_004020b5(-1);
    }
  }
  return;
}


// ==== FUN_004023b2 @ 004023b2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004023b2(int param_1)

{
  DWORD DVar1;
  uint local_8;
  
  if (DAT_00412188 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00412190) {
      DAT_00412190 = DVar1;
    }
    if (DVar1 - _DAT_00412194 < DAT_00412190) {
      if (DAT_00412198 <= *(int *)(&DAT_00417dac + param_1 * 0x10)) {
        return;
      }
      local_8 = DAT_00412190 - (DVar1 - _DAT_00412194);
      if (2000 < local_8) {
        local_8 = 2000;
      }
      if (7 < (int)DAT_00412024) {
        local_8 = local_8 / DAT_00412024;
      }
      Sleep(local_8 + 1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_00412190 = GetTickCount();
    _DAT_00412194 = *(int *)(&DAT_00417da8 + param_1 * 0x10);
    DAT_00412198 = *(int *)(&DAT_00417dac + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_00417da0 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_004024cf @ 004024cf

void FUN_004024cf(void)

{
  int local_c;
  int local_8;
  
  FUN_00401ec0();
  FUN_004023b2(0);
  for (local_8 = 1; local_8 < 8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00417da4 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00417da4 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00417da4 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_00417da0 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 4; local_c = local_c + 1) {
    DeleteFileA(&DAT_004177a0 + local_c * 0x100);
  }
  return;
}


// ==== FUN_004025b7 @ 004025b7

void __cdecl FUN_004025b7(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_00405700(DAT_0042a190,param_2,&DAT_00412330);
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


// ==== FUN_004026e6 @ 004026e6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004026e6(void)

{
  int local_8;
  
  _DAT_00417da0 = 0;
  _DAT_00417da4 = 0;
  FUN_004025b7((int *)&DAT_00417db0,s_CARDWONWAV_00412338);
  _DAT_00417dbc = 2;
  FUN_004025b7(&DAT_00417dc0,s_COINCHANGEWAV_00412344);
  _DAT_00417dcc = 5;
  FUN_004025b7((int *)&DAT_00417dd0,s_CARDLOSTWAV_00412354);
  _DAT_00417ddc = 2;
  FUN_004025b7((int *)&DAT_00417de0,s_MOVECARDWAV_00412360);
  _DAT_00417dec = 4;
  FUN_004025b7((int *)&DAT_00417df0,s_NOMOVECARDWAV_0041236c);
  _DAT_00417dfc = 4;
  FUN_004025b7((int *)&DAT_00417e00,s_STARTGAMEWAV_0041237c);
  _DAT_00417e0c = 1;
  FUN_004025b7((int *)&DAT_00417e10,s_CHANGEDIRWAV_0041238c);
  _DAT_00417e1c = 4;
  for (local_8 = 1; local_8 < 4; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_004177a0 + local_8 * 0x100);
    FUN_0040ea70((uint *)(&DAT_004177a0 + local_8 * 0x100),(uint *)(&DAT_004121a0 + local_8 * 0x20))
    ;
    FUN_00405923(&DAT_00412260 + local_8 * 0x20,&DAT_0041239c,&DAT_004177a0 + local_8 * 0x100);
  }
  return;
}


// ==== FUN_00402870 @ 00402870

void FUN_00402870(void)

{
  DAT_004123b0 = DAT_004123ac * DAT_004123a8;
  DAT_004123c0 = 0;
  DAT_004123c4 = 0;
  DAT_004123c8 = DAT_004123a8 + -1;
  DAT_004123cc = DAT_004123ac + -1;
  return;
}


// ==== FUN_004028bb @ 004028bb

undefined4 * __cdecl FUN_004028bb(undefined4 *param_1,int param_2,int param_3)

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


// ==== FUN_00402a6e @ 00402a6e

undefined4 FUN_00402a6e(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_00402870();
  DAT_004123e4 = _malloc(DAT_004123b0);
  if (DAT_004123e4 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    _memset(DAT_004123e4,0,DAT_004123b0);
    puVar2 = FUN_004028bb(&DAT_004123e4,DAT_004123a8,DAT_004123ac);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      DAT_004123d0 = DAT_004123c0;
      DAT_004123d4 = DAT_004123c4;
      DAT_004123d8 = DAT_004123c8;
      DAT_004123dc = DAT_004123cc;
      AfxResetMsgCache();
      FUN_00402b3b();
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== AfxResetMsgCache @ 00402b17

/* Library Function - Single Match
    void __stdcall AfxResetMsgCache(void)
   
   Library: Visual Studio 1998 Debug */

void AfxResetMsgCache(void)

{
  _memset(&DAT_004181a0,0,0x8900);
  return;
}


// ==== FUN_00402b3b @ 00402b3b

void FUN_00402b3b(void)

{
  int local_8;
  
  _memset(&DAT_00420da8,0,0x2c00);
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00420db0 + local_8 * 0x2c) = 0xffffffff;
    *(undefined4 *)(&DAT_00420db8 + local_8 * 0x2c) = 1;
    *(undefined4 *)(&DAT_00420dbc + local_8 * 0x2c) = 1;
    *(int *)(&DAT_00420dc8 + local_8 * 0x2c) = DAT_004123a8 + -1;
    *(int *)(&DAT_00420dcc + local_8 * 0x2c) = DAT_004123ac + -1;
  }
  return;
}


// ==== FUN_00402bfa @ 00402bfa

void __cdecl FUN_00402bfa(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(DAT_004269a8 + DAT_004123a8 * param_2 + param_1) = param_3;
  return;
}


// ==== FUN_00402c26 @ 00402c26

undefined8 __cdecl FUN_00402c26(int param_1,uint param_2)

{
  return CONCAT44((int)((ulonglong)DAT_004123a8 * (ulonglong)param_2 >> 0x20),
                  *(undefined4 *)
                   (DAT_004269a8 + (int)((ulonglong)DAT_004123a8 * (ulonglong)param_2) + param_1));
}


// ==== FUN_00402c4a @ 00402c4a

void __cdecl FUN_00402c4a(short *param_1)

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
    if (*(short **)(&DAT_00420dd0 + local_8 * 0x2c) == param_1) {
      *(undefined4 *)(&DAT_00420dd0 + local_8 * 0x2c) = 0;
    }
  }
  return;
}


// ==== FUN_00402d47 @ 00402d47

void __cdecl
FUN_00402d47(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
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


// ==== FUN_00402dc6 @ 00402dc6

bool __cdecl FUN_00402dc6(int *param_1,int *param_2)

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


// ==== FUN_00402e7a @ 00402e7a

void __cdecl FUN_00402e7a(LONG param_1,LONG param_2,LONG param_3,LONG param_4)

{
  int iVar1;
  BOOL BVar2;
  tagRECT local_1c;
  int local_c;
  
  BVar2 = IntersectRect(&local_1c,(RECT *)&param_1,(RECT *)&DAT_004123c0);
  if (BVar2 != 0) {
    param_1 = local_1c.left;
    param_2 = local_1c.top;
    param_3 = local_1c.right;
    param_4 = local_1c.bottom;
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if ((*(int *)(&DAT_004241b8 + local_c * 0x14) != 0) &&
         (BVar2 = IntersectRect(&local_1c,(RECT *)(&DAT_004241a8 + local_c * 0x14),(RECT *)&param_1)
         , BVar2 != 0)) {
        iVar1 = local_c * 0x14;
        FUN_00402d47(&param_1,*(int *)(&DAT_004241a8 + iVar1),*(int *)(&DAT_004241ac + iVar1),
                     *(int *)(&DAT_004241b0 + iVar1),*(int *)(&DAT_004241b4 + iVar1),param_1,param_2
                     ,param_3,param_4);
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_004241a8 + iVar1) = param_1;
        *(LONG *)(&DAT_004241ac + iVar1) = param_2;
        *(LONG *)(&DAT_004241b0 + iVar1) = param_3;
        *(LONG *)(&DAT_004241b4 + iVar1) = param_4;
        *(undefined4 *)(&DAT_004241b8 + local_c * 0x14) = 1;
        return;
      }
    }
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if (*(int *)(&DAT_004241b8 + local_c * 0x14) == 0) {
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_004241a8 + iVar1) = param_1;
        *(LONG *)(&DAT_004241ac + iVar1) = param_2;
        *(LONG *)(&DAT_004241b0 + iVar1) = param_3;
        *(LONG *)(&DAT_004241b4 + iVar1) = param_4;
        *(undefined4 *)(&DAT_004241b8 + local_c * 0x14) = 1;
        return;
      }
    }
  }
  return;
}


// ==== FUN_00403013 @ 00403013

void __cdecl
FUN_00403013(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_2 = *param_1;
  *param_3 = param_1[1];
  *param_4 = param_1[2];
  return;
}


// ==== FUN_00403043 @ 00403043

void __cdecl FUN_00403043(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_004123a8 - param_3;
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


// ==== FUN_0040307c @ 0040307c

void __cdecl FUN_0040307c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (DAT_004123a8 + -1 < param_5) {
    param_5 = DAT_004123a8 + -1;
  }
  if (DAT_004123ac + -1 < param_6) {
    param_6 = DAT_004123ac + -1;
  }
  if ((param_3 <= param_5) && (param_4 <= param_6)) {
    iVar1 = param_4 * DAT_004123a8 + param_3;
    FUN_00403043((undefined1 *)(param_1 + iVar1),(undefined1 *)(param_2 + iVar1),
                 (param_5 - param_3) + 1,(param_6 - param_4) + 1);
  }
  return;
}


// ==== FUN_0040314b @ 0040314b

void __cdecl FUN_0040314b(int param_1,int param_2,int param_3,int param_4)

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
  puVar6 = (undefined1 *)(param_2 + DAT_004123a8 * (param_4 - iVar4) + param_3);
  iVar2 = DAT_004123a8 - iVar1;
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


// ==== FUN_00403200 @ 00403200

void __cdecl
FUN_00403200(char *param_1,char *param_2,uint param_3,int param_4,short param_5,char param_6)

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
    param_2 = param_2 + (DAT_004123a8 - param_3);
    param_5 = param_5 + -1;
    uVar3 = param_3;
  } while (param_5 != 0);
  return;
}


// ==== FUN_00403255 @ 00403255

void __cdecl
FUN_00403255(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char param_7)

{
  uint uVar1;
  int local_1c;
  int local_10;
  int local_c;
  
  if ((param_1 <= DAT_004123d8) && (param_2 <= DAT_004123dc)) {
    local_10 = param_3 + param_1 + -1;
    local_c = 0;
    if (param_1 < DAT_004123d0) {
      local_c = DAT_004123d0 - param_1;
      param_1 = DAT_004123d0;
    }
    local_1c = param_4 + param_2 + -1;
    if (param_2 < DAT_004123d4) {
      local_c = local_c + (DAT_004123d4 - param_2) * param_3;
      param_2 = DAT_004123d4;
    }
    if (DAT_004123d8 < local_10) {
      local_10 = DAT_004123d8;
    }
    if (DAT_004123dc < local_1c) {
      local_1c = DAT_004123dc;
    }
    if ((((DAT_004123d0 <= local_10) && (DAT_004123d4 <= local_1c)) &&
        (uVar1 = (local_10 - param_1) + 1, 0 < (int)uVar1)) && ((int)uVar1 <= DAT_004123a8)) {
      FUN_00403200((char *)(param_5 + local_c),(char *)(param_6 + param_2 * DAT_004123a8 + param_1),
                   uVar1,param_3 - uVar1,((short)local_1c - (short)param_2) + 1,param_7);
    }
  }
  return;
}


// ==== FUN_004033b9 @ 004033b9

void __cdecl FUN_004033b9(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_004123d0 = param_1[6];
    DAT_004123d4 = param_1[7];
    DAT_004123d8 = param_1[8];
    DAT_004123dc = param_1[9];
    FUN_00403255(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_004123e0,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_004034ae @ 004034ae

void __cdecl FUN_004034ae(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_004123d0 = param_1[6];
    DAT_004123d4 = param_1[7];
    DAT_004123d8 = param_1[8];
    DAT_004123dc = param_1[9];
    FUN_00403255(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_004123e4,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_004035a3 @ 004035a3

undefined4 __cdecl FUN_004035a3(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_3[3] < 0) || ((int)*(short *)param_3[10] <= param_3[3])) || (param_3[10] == 0)) ||
     (param_3[2] < 1)) {
    uVar1 = 0;
  }
  else {
    DAT_004123d0 = param_3[6];
    DAT_004123d4 = param_3[7];
    DAT_004123d8 = param_3[8];
    DAT_004123dc = param_3[9];
    if ((param_1 < DAT_004123d0) || (DAT_004123d8 < param_1)) {
      uVar1 = 0;
    }
    else if ((param_2 < DAT_004123d4) || (DAT_004123dc < param_2)) {
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


// ==== FUN_0040370b @ 0040370b

undefined4 __cdecl FUN_0040370b(int param_1,int param_2)

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


// ==== FUN_00403755 @ 00403755

void FUN_00403755(void)

{
  int iVar1;
  int local_2c;
  int local_28;
  
  if (DAT_004123b4 == 0) {
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_004241b8 + local_2c * 0x14) != 0) {
        iVar1 = local_2c * 0x14;
        FUN_0040307c((int)DAT_004123e4,(int)DAT_004123e0,*(int *)(&DAT_004241a8 + iVar1),
                     *(int *)(&DAT_004241ac + iVar1),*(int *)(&DAT_004241b0 + iVar1),
                     *(int *)(&DAT_004241b4 + iVar1));
      }
    }
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_004239a8 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_004239ac + local_28 * 8) =
           *(undefined4 *)(&DAT_00420db0 + local_28 * 0x2c);
    }
    _qsort(&DAT_004239a8,0xff,8,FUN_0040370b);
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_004241b8 + local_2c * 0x14) != 0) {
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          if (0 < *(int *)(&DAT_004239ac + local_28 * 8)) {
            FUN_004033b9((int *)(&DAT_00420da8 + *(int *)(&DAT_004239a8 + local_28 * 8) * 0x2c));
          }
        }
      }
    }
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_004241b8 + local_2c * 0x14) != 0) {
        FUN_00405655((int *)(&DAT_004241a8 + local_2c * 0x14));
      }
    }
  }
  else {
    FID_conflict__memcpy(DAT_004123e0,DAT_004123e4,DAT_004123b0);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_004239a8 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_004239ac + local_28 * 8) =
           *(undefined4 *)(&DAT_00420db0 + local_28 * 0x2c);
    }
    _qsort(&DAT_004239a8,0xff,8,FUN_0040370b);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      if (0 < *(int *)(&DAT_004239ac + local_28 * 8)) {
        FUN_004033b9((int *)(&DAT_00420da8 + *(int *)(&DAT_004239a8 + local_28 * 8) * 0x2c));
      }
    }
    FUN_00405655(&DAT_004123c0);
    DAT_004123b4 = 0;
  }
  _memset(&DAT_004241a8,0,0x2800);
  GdiFlush();
  return;
}


// ==== FUN_00403a1c @ 00403a1c

void __cdecl FUN_00403a1c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  FID_conflict__memcpy(DAT_004123e0,DAT_004123e4,DAT_004123b0);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    *(int *)(&DAT_004239a8 + local_38 * 8) = local_38;
    *(undefined4 *)(&DAT_004239ac + local_38 * 8) = *(undefined4 *)(&DAT_00420db0 + local_38 * 0x2c)
    ;
  }
  _qsort(&DAT_004239a8,0xff,8,FUN_0040370b);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    if (0 < *(int *)(&DAT_004239ac + local_38 * 8)) {
      FUN_004033b9((int *)(&DAT_00420da8 + *(int *)(&DAT_004239a8 + local_38 * 8) * 0x2c));
    }
  }
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  FUN_00405655(&local_34);
  GdiFlush();
  return;
}


// ==== FUN_00403b2b @ 00403b2b

void __cdecl FUN_00403b2b(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
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
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00403c6c @ 00403c6c

void __cdecl FUN_00403c6c(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
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
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00403d90 @ 00403d90

void __cdecl FUN_00403d90(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[3] != param_2)) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
    if ((-1 < param_2) && (param_2 < *(short *)param_1[10])) {
      FUN_00402dc6(param_1,&local_14);
      FUN_00402e7a(local_14,local_10,local_c,local_8);
      param_1[3] = param_2;
      FUN_00402dc6(param_1,&local_14);
      FUN_00402e7a(local_14,local_10,local_c,local_8);
    }
  }
  return;
}


// ==== FUN_00403e66 @ 00403e66

void __cdecl FUN_00403e66(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  return;
}


// ==== FUN_00403e80 @ 00403e80

void __cdecl FUN_00403e80(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== FUN_00403e9a @ 00403e9a

void __cdecl FUN_00403e9a(int *param_1,int param_2,int param_3)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && ((param_2 != 0 || (param_3 != 0)))) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
    *param_1 = *param_1 + param_2;
    param_1[1] = param_1[1] + param_3;
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00403f39 @ 00403f39

void __cdecl FUN_00403f39(int *param_1,int param_2,int param_3,int param_4)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) &&
     (((*param_1 != param_2 || (param_1[1] != param_3)) || (param_1[2] != param_4)))) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4;
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00403ff9 @ 00403ff9

void __cdecl FUN_00403ff9(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (-1 < param_1[2])) {
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
    param_1[2] = -1;
  }
  return;
}


// ==== FUN_00404062 @ 00404062

void __cdecl FUN_00404062(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[2] != param_2)) {
    param_1[2] = param_2;
    FUN_00402dc6(param_1,&local_14);
    FUN_00402e7a(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_004040cc @ 004040cc

void __cdecl FUN_004040cc(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[10] = param_2;
  return;
}


// ==== FUN_0040410c @ 0040410c

void __cdecl FUN_0040410c(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5)

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


// ==== FUN_00404155 @ 00404155

undefined4 __cdecl FUN_00404155(LPCSTR param_1,short *param_2)

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
        if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
          local_34 = (undefined1 *)DAT_004123bc;
          for (local_398 = 0; (int)local_398 < 0x100; local_398 = local_398 + 1) {
            local_3c4 = 0x7fff;
            local_38 = 0;
            for (local_39c = 0; local_39c < 0x100; local_39c = local_39c + 1) {
              iVar2 = FUN_0040ee40((uint)*(byte *)(local_39c * 3 + 2 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3 + 2]);
              iVar3 = FUN_0040ee40((uint)*(byte *)(local_39c * 3 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3]);
              local_c = FUN_0040ee40((uint)*(byte *)(local_39c * 3 + 1 + (int)local_34) -
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
          if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
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
        if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
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
            FUN_0040410c(*(undefined1 **)(param_2 + local_398 * 2 + 0x92),(int)local_394,
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


// ==== FUN_0040495b @ 0040495b

undefined4 __cdecl FUN_0040495b(LPCSTR param_1,short *param_2)

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
  
  local_14 = FUN_00405778(DAT_0042a190,param_1,s_SPRITE_004123e8,&local_3d0);
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
      if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
        local_3c = (undefined1 *)DAT_004123bc;
        for (local_39c = 0; (int)local_39c < 0x100; local_39c = local_39c + 1) {
          local_3c8 = 0x7fff;
          local_40 = 0;
          for (local_3a0 = 0; local_3a0 < 0x100; local_3a0 = local_3a0 + 1) {
            iVar2 = FUN_0040ee40((uint)*(byte *)(local_3a0 * 3 + 2 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3 + 2]);
            iVar3 = FUN_0040ee40((uint)*(byte *)(local_3a0 * 3 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3]);
            local_10 = FUN_0040ee40((uint)*(byte *)(local_3a0 * 3 + 1 + (int)local_3c) -
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
        if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
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
      if ((DAT_004123b8 != 0) && (DAT_004123bc != 0)) {
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
          FUN_0040410c(*(undefined1 **)(param_2 + local_39c * 2 + 0x92),(int)local_398,
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


// ==== FUN_0040519a @ 0040519a

void __cdecl FUN_0040519a(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x28) = param_1;
  *(undefined4 *)(param_2 + 0xc) = 0;
  return;
}


// ==== FUN_004051bd @ 004051bd

void __cdecl FUN_004051bd(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (DAT_004123a8 + -1 < param_4) {
    param_4 = DAT_004123a8 + -1;
  }
  if (DAT_004123ac + -1 < param_5) {
    param_5 = DAT_004123ac + -1;
  }
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_3;
  *(int *)(param_1 + 0x20) = param_4;
  *(int *)(param_1 + 0x24) = param_5;
  return;
}


// ==== FUN_00405243 @ 00405243

void __cdecl FUN_00405243(int param_1,int param_2,int param_3,int param_4)

{
  int local_8;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (DAT_004123a8 + -1 < param_3) {
    param_3 = DAT_004123a8 + -1;
  }
  if (DAT_004123ac + -1 < param_4) {
    param_4 = DAT_004123ac + -1;
  }
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(int *)(&DAT_00420dc0 + local_8 * 0x2c) = param_1;
    *(int *)(&DAT_00420dc4 + local_8 * 0x2c) = param_2;
    *(int *)(&DAT_00420dc8 + local_8 * 0x2c) = param_3;
    *(int *)(&DAT_00420dcc + local_8 * 0x2c) = param_4;
  }
  return;
}


// ==== FUN_00405321 @ 00405321

void __cdecl
FUN_00405321(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  *param_3 = *(undefined4 *)(param_1 + 0x1c);
  *param_4 = *(undefined4 *)(param_1 + 0x20);
  *param_5 = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_0040535d @ 0040535d

void FUN_0040535d(void)

{
  if (DAT_00420da0 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00420da0);
    DAT_00420da0 = (HGDIOBJ)0x0;
  }
  if (DAT_00412180 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00412180);
  }
  DAT_00412180 = (HGDIOBJ)0x0;
  return;
}


// ==== FUN_004053b3 @ 004053b3

void FUN_004053b3(void)

{
  BITMAPINFO local_444;
  BYTE aBStack_3f4 [984];
  HDC local_1c;
  int local_10;
  undefined *local_c;
  void *local_8;
  
  local_c = &DAT_00420aa0;
  local_444.bmiHeader.biSize = 0x28;
  local_444.bmiHeader.biPlanes = 1;
  local_444.bmiHeader.biBitCount = 8;
  local_444.bmiHeader.biCompression = 0;
  local_444.bmiHeader.biSizeImage = 0;
  local_444.bmiHeader.biClrUsed = 0;
  local_444.bmiHeader.biClrImportant = 0;
  local_444.bmiHeader.biWidth = DAT_004123a8;
  local_444.bmiHeader.biHeight = DAT_004123ac;
  local_1c = GetDC((HWND)0x0);
  GetSystemPaletteEntries(local_1c,0,10,(LPPALETTEENTRY)&DAT_00417314);
  GetSystemPaletteEntries(local_1c,0xf6,10,(LPPALETTEENTRY)&DAT_004176ec);
  ReleaseDC((HWND)0x0,local_1c);
  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
    local_444.bmiColors[local_10].rgbRed = (&DAT_00417314)[local_10 * 4];
    local_444.bmiColors[local_10].rgbGreen = (&DAT_00417315)[local_10 * 4];
    local_444.bmiColors[local_10].rgbBlue = (&DAT_00417316)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_00417317)[local_10 * 4] = 0;
    aBStack_3f4[local_10 * 4 + 0x3b2] = (&DAT_004176ec)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b1] = (&DAT_004176ed)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b0] = (&DAT_004176ee)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b3] = '\0';
    (&DAT_004176ef)[local_10 * 4] = 0;
  }
  for (local_10 = 10; local_10 < 0xf6; local_10 = local_10 + 1) {
    (&DAT_00417314)[local_10 * 4] = local_c[local_10 * 3] * '\x04';
    local_444.bmiColors[local_10].rgbRed = (&DAT_00417314)[local_10 * 4];
    (&DAT_00417315)[local_10 * 4] = local_c[local_10 * 3 + 1] * '\x04';
    local_444.bmiColors[local_10].rgbGreen = (&DAT_00417315)[local_10 * 4];
    (&DAT_00417316)[local_10 * 4] = local_c[local_10 * 3 + 2] * '\x04';
    local_444.bmiColors[local_10].rgbBlue = (&DAT_00417316)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_00417317)[local_10 * 4] = 4;
  }
  DAT_00412180 = CreatePalette((LOGPALETTE *)&DAT_00417310);
  local_1c = GetDC((HWND)0x0);
  DAT_00420da0 = CreateDIBSection(local_1c,&local_444,0,&local_8,(HANDLE)0x0,0);
  ReleaseDC((HWND)0x0,local_1c);
  DAT_004123e0 = local_8;
  DAT_004269a8 = local_8;
  return;
}


// ==== FUN_00405655 @ 00405655

void __cdecl FUN_00405655(int *param_1)

{
  HDC hdc;
  HGDIOBJ h;
  int y;
  
  hdc = CreateCompatibleDC(DAT_004172c0);
  h = SelectObject(hdc,DAT_00420da0);
  y = (DAT_004123ac + -1) - param_1[3];
  BitBlt(DAT_004172c0,*param_1,y,(param_1[2] - *param_1) + 1,(param_1[3] - param_1[1]) + 1,hdc,
         *param_1,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  return;
}


// ==== FUN_00405700 @ 00405700

HGLOBAL __cdecl FUN_00405700(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_004269b0 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_004269b0 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_00405778 @ 00405778

HGLOBAL __cdecl FUN_00405778(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_004269b0 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_004269b0 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_004269b0 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_00405812 @ 00405812

undefined4 __cdecl FUN_00405812(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_004123f0; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),hResInfo);
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


// ==== FUN_00405923 @ 00405923

bool __cdecl FUN_00405923(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_004123f0 <= local_18) {
LAB_00405991:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_004269b0 + local_18 * 4),local_14);
      goto LAB_00405991;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_00405a57 @ 00405a57

HRSRC __cdecl FUN_00405a57(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_004269b0 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00405abc @ 00405abc

HGLOBAL __cdecl FUN_00405abc(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_004269b0 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_00405b1d @ 00405b1d

INT_PTR __cdecl FUN_00405b1d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_004269b0 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_00405b8b @ 00405b8b

HACCEL __cdecl FUN_00405b8b(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_004269b0 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00405bed @ 00405bed

HICON __cdecl FUN_00405bed(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_004269b0 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00405c4e @ 00405c4e

HMENU __cdecl FUN_00405c4e(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_004269b0 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_00405cb0 @ 00405cb0

int __cdecl FUN_00405cb0(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_004123f0 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_004269b0 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_00405d19 @ 00405d19

HBITMAP __cdecl FUN_00405d19(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_004123f0 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_004269b0 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_00405d7a @ 00405d7a

void FUN_00405d7a(void)

{
  DAT_004123f0 = 0;
  return;
}


// ==== FUN_00405d94 @ 00405d94

bool __cdecl FUN_00405d94(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_004123f0 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_004269b0 + DAT_004123f0 * 4) = param_1;
    DAT_004123f0 = DAT_004123f0 + 1;
  }
  return bVar1;
}


// ==== FUN_00405dd3 @ 00405dd3

undefined4 __cdecl FUN_00405dd3(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_004123f0 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_004269b0 + DAT_004123f0 * 4) = pHVar2;
      DAT_004123f0 = DAT_004123f0 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_00405e33 @ 00405e33

bool __cdecl FUN_00405e33(LPCSTR param_1,uint *param_2)

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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_0041267c,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0040ea60(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_00405f0b @ 00405f0b

bool __cdecl FUN_00405f0b(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_00405f4d @ 00405f4d

undefined4 FUN_00405f4d(void)

{
  return 1;
}


// ==== FUN_00405f65 @ 00405f65

void __cdecl FUN_00405f65(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_0040ea70(local_104,(uint *)&DAT_004126b0);
  }
  FUN_0040ea70(local_104,param_1);
  FUN_0040ea60(param_1,local_104);
  return;
}


// ==== FUN_00405fe7 @ 00405fe7

undefined4 __cdecl FUN_00405fe7(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00405e33(s_Shared_Path_004126b4,local_104);
  FUN_0040ea70(local_104,param_1);
  bVar1 = FUN_00405f0b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00405e33(s_Shared_Path_004126c0,local_104);
    FUN_0040ea70(local_104,(uint *)&DAT_004126cc);
    FUN_0040ea70(local_104,param_1);
    bVar1 = FUN_00405f0b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040ea60(local_104,(uint *)s___shared__004126d0);
      FUN_0040ea70(local_104,param_1);
      bVar1 = FUN_00405f0b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040ea60(local_104,(uint *)&DAT_004126dc);
        FUN_0040ea70(local_104,param_1);
        bVar1 = FUN_00405f0b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040ea60(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040ea60(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040ea60(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040ea60(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00406195 @ 00406195

undefined4 __cdecl FUN_00406195(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_00405e33(s_Help_Path_004126e0,local_104);
  FUN_0040ea70(local_104,param_1);
  bVar1 = FUN_00405f0b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_00405e33(s_Help_Path_004126ec,local_104);
    FUN_0040ea70(local_104,(uint *)&DAT_004126f8);
    FUN_0040ea70(local_104,param_1);
    bVar1 = FUN_00405f0b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040ea60(local_104,(uint *)&DAT_004126fc);
      FUN_0040ea70(local_104,param_1);
      bVar1 = FUN_00405f0b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040ea60(local_104,(uint *)s___shared__00412700);
        FUN_0040ea70(local_104,param_1);
        bVar1 = FUN_00405f0b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040ea60(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040ea60(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040ea60(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040ea60(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00406343 @ 00406343

undefined4 __cdecl FUN_00406343(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_00412678 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00426ab0 + DAT_00412678 * 4) = param_1;
    DAT_00412678 = DAT_00412678 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040638f @ 0040638f

void FUN_0040638f(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00412678; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00426ab0 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00426ab0 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00426ab0 + local_8 * 4) = 0;
  }
  DAT_00412678 = 0;
  return;
}


// ==== FUN_00406400 @ 00406400

void __cdecl FUN_00406400(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00412a74 = 2;
  }
  DAT_00428f38 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00406443 @ 00406443

void __cdecl FUN_00406443(HWND param_1)

{
  if (DAT_00428f38 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00428f38);
  }
  return;
}


// ==== FUN_00406474 @ 00406474

void __cdecl FUN_00406474(uint *param_1)

{
  FUN_0040ea60((uint *)&DAT_00412a78,param_1);
  return;
}


// ==== FUN_00406495 @ 00406495

void __cdecl FUN_00406495(HWND param_1)

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


// ==== FUN_004065cd @ 004065cd

INT_PTR __cdecl FUN_004065cd(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_00405b1d(DAT_0042a190,s_RESETSCORE_00412ba8,param_1,FUN_004092a1);
  return IVar1;
}


// ==== FUN_00406602 @ 00406602

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00406602(int param_1)

{
  if (((8 < param_1) && (param_1 < 0xf)) && (*(int *)(&DAT_00429840 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00429840 + param_1 * 4) = 1;
    Sleep(500);
    switch(param_1) {
    case 9:
      FUN_00406474((uint *)s_JOKERBMP_00412bb4);
      FUN_00405b1d(DAT_0042a190,s_QHJOKERDIALOG_00412bc0,DAT_00417308,FUN_0040789d);
      break;
    case 10:
      FUN_00406474((uint *)s_HOLEBMP_00412bd0);
      FUN_00405b1d(DAT_0042a190,s_QHHOLEDIALOG_00412bd8,DAT_00417308,FUN_0040789d);
      break;
    case 0xb:
      FUN_00406474((uint *)s_WALLBMP_00412be8);
      FUN_00405b1d(DAT_0042a190,s_QHWALLDIALOG_00412bf0,DAT_00417308,FUN_0040789d);
      break;
    case 0xc:
      FUN_00406474((uint *)s_TELEBMP_00412c00);
      FUN_00405b1d(DAT_0042a190,s_QHTELEDIALOG_00412c08,DAT_00417308,FUN_0040789d);
      break;
    case 0xd:
      FUN_00406474((uint *)s_QUICKHELPBMP_00412c18);
      FUN_00405b1d(DAT_0042a190,s_QHCHALLENGE_00412c28,DAT_00417308,FUN_00407b08);
      break;
    case 0xe:
      FUN_00406474((uint *)s_QUICKHELPBMP_00412c34);
      FUN_00405b1d(DAT_0042a190,s_QHTRAINING_00412c44,DAT_00417308,FUN_00407b08);
    }
    FUN_00409498();
    _DAT_00412a70 = 0;
    InvalidateRect(DAT_00417308,(RECT *)0x0,0);
    UpdateWindow(DAT_00417308);
  }
  return;
}


// ==== FUN_004067e8 @ 004067e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_004067e8(void)

{
  INT_PTR IVar1;
  
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_QUICKHELPBMP_00412c50);
  IVar1 = FUN_00405b1d(DAT_0042a190,s_EXITGAME_00412c60,DAT_00417308,FUN_00406cf1);
  _DAT_00412a70 = 0;
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  return IVar1;
}


// ==== FUN_0040685c @ 0040685c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_0040685c(void)

{
  INT_PTR IVar1;
  
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_QUICKHELPBMP_00412c6c);
  IVar1 = FUN_00405b1d(DAT_0042a190,s_NEWGAME_00412c7c,DAT_00417308,FUN_00406cf1);
  _DAT_00412a70 = 0;
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  return IVar1;
}


// ==== FUN_004068d0 @ 004068d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004068d0(void)

{
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_ABOUTBMP_00412c84);
  FUN_00405b1d(DAT_0042a190,s_ABOUT_00412c90,DAT_00417308,FUN_00406e88);
  _DAT_00412a70 = 0;
  return;
}


// ==== FUN_0040691f @ 0040691f

void __cdecl FUN_0040691f(HWND param_1)

{
  FUN_00405b1d(DAT_0042a190,s_CREDITS_00412c98,param_1,FUN_0040716e);
  return;
}


// ==== FUN_0040694b @ 0040694b

void __cdecl FUN_0040694b(HWND param_1)

{
  FUN_00405b1d(DAT_0042a190,s_SYSTEMINFODIALOG_00412ca0,param_1,FUN_004072ff);
  return;
}


// ==== FUN_00406977 @ 00406977

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406977(void)

{
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_QUICKHELPBMP_00412cb4);
  FUN_00405b1d(DAT_0042a190,s_QUICKHELPDIALOG_00412cc4,DAT_00417308,FUN_00407d2f);
  _DAT_00412a70 = 0;
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  return;
}


// ==== FUN_004069e2 @ 004069e2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004069e2(void)

{
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_CUPBMP_00412cd4);
  FUN_00405b1d(DAT_0042a190,s_YOURNAME_00412cdc,DAT_00417308,FUN_00407f9b);
  _DAT_00412a70 = 0;
  return;
}


// ==== FUN_00406a31 @ 00406a31

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406a31(void)

{
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_CUPBMP_00412ce8);
  FUN_00405b1d(DAT_0042a190,s_BALLSTOP_00412cf0,DAT_00417308,FUN_004082d9);
  _DAT_00412a70 = 0;
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  return;
}


// ==== FUN_00406a9c @ 00406a9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406a9c(void)

{
  _DAT_00412a70 = 1;
  FUN_00406474((uint *)s_OPTIONSBMP_00412cfc);
  FUN_00405b1d(DAT_0042a190,s_OPTIONS_00412d08,DAT_00417308,FUN_00408656);
  _DAT_00412a70 = 0;
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  return;
}


// ==== FUN_00406b07 @ 00406b07

void __cdecl FUN_00406b07(HWND param_1)

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
  local_8 = FUN_0040196e(pHVar1,&DAT_00412a78);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040188f(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00412180,0);
  RealizePalette(pHVar1);
  FUN_004018d8(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00406bfc @ 00406bfc

void __cdecl FUN_00406bfc(HWND param_1)

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
  ho = FUN_0040196e(pHVar1,s_QUICKHELPBMP_00412d10);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040188f(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00412180,0);
  RealizePalette(pHVar1);
  FUN_004018d8(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_00406cf1 @ 00406cf1

UINT FUN_00406cf1(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00406495(param_1);
      DAT_0042a168 = param_1;
      DAT_0042a160 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406b07(DAT_0042a160);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0042a168 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0042a168);
      SelectPalette(hdc,DAT_00412180,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0042a168,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_0042a168,(RECT *)0x0,0);
        InvalidateRect(DAT_00417308,(RECT *)0x0,0);
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


// ==== FUN_00406e88 @ 00406e88

UINT FUN_00406e88(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00406495(param_1);
      DAT_0042a19c = param_1;
      DAT_0042a198 = GetDlgItem(param_1,100);
      FUN_00405cb0(DAT_0042a190,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_00405e33(&DAT_00412d20,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_00405e33(s_Product_ID_00412d24,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406b07(DAT_0042a198);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_0042a19c) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_0042a19c);
      SelectPalette(local_10c,DAT_00412180,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_0042a19c,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0042a19c,(RECT *)0x0,0);
      InvalidateRect(DAT_00417308,(RECT *)0x0,0);
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
      FUN_0040694b(param_1);
      return 1;
    case (HWND)0x66:
      FUN_0040691f(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0040716e @ 0040716e

UINT FUN_0040716e(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00406495(param_1);
      DAT_00429890 = param_1;
      DAT_0042982c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406b07(DAT_0042982c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00429890 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00429890);
      SelectPalette(hdc,DAT_00412180,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00429890,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00429890,(RECT *)0x0,0);
        InvalidateRect(DAT_0042a19c,(RECT *)0x0,0);
        InvalidateRect(DAT_00417308,(RECT *)0x0,0);
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


// ==== FUN_004072ff @ 004072ff

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004072ff(HWND param_1,int param_2,uint param_3)

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
    FUN_00406495(param_1);
    _DAT_00428648 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d30,local_49c.dwMajorVersion,-1);
    FUN_0040ea60((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d34);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d38,local_49c.dwMinorVersion,-1);
    FUN_0040ea70((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d3c);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d40,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0040ea70((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d44);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0040ea70((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d48,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0040ea60((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d4c);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0040ea60((uint *)local_404,(uint *)&DAT_00412d50);
    FUN_0040ea70((uint *)local_404,(uint *)&local_4b4);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d54);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d58,local_4a0,-1);
    FUN_0040ea70((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d5c);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_00412d80,s_display_drv_00412d74,s_Unknown_00412d6c,local_404,0x80,
               s_system_ini_00412d60);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d94,local_4a0,-1);
    FUN_0040ea60((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412d98);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412d9c,local_4a0,-1);
    FUN_0040ea70((uint *)local_404,puVar1);
    FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412da0);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412da4,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0040ea70((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412da8,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0040ea70((uint *)local_404,puVar1);
      FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412dac);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412db4,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0040ea70((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_00401700((uint *)&DAT_00412db0,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0040ea70((uint *)local_404,puVar1);
      }
      FUN_0040ea70((uint *)local_404,(uint *)&DAT_00412db8);
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


// ==== FUN_0040789d @ 0040789d

UINT FUN_0040789d(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00406b07(DAT_00429828);
      }
      return 0;
    }
    FUN_00406495(param_1);
    DAT_00427c30 = param_1;
    DAT_00429828 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00412034 == 0);
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
      DAT_00412034 = (uint)(LVar2 == 0);
      FUN_00401529();
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
      DAT_00412034 = (uint)(LVar2 == 0);
      FUN_00401529();
      EndDialog(param_1,0);
      PostMessageA(DAT_00417308,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (param_3 == DAT_00427c30) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00427c30);
  SelectPalette(hdc,DAT_00412180,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00427c30,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00427c30,(RECT *)0x0,0);
    InvalidateRect(DAT_00417308,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00407b08 @ 00407b08

UINT FUN_00407b08(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00406495(param_1);
      DAT_0042a194 = param_1;
      DAT_00428f4c = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_00412034 == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406b07(DAT_00428f4c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0042a194 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0042a194);
      SelectPalette(hdc,DAT_00412180,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_0042a194,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_0042a194,(RECT *)0x0,0);
        InvalidateRect(DAT_00417308,(RECT *)0x0,0);
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
        DAT_00412034 = (uint)(LVar2 == 0);
        FUN_00401529();
        EndDialog(param_1,0);
        PostMessageA(DAT_00417308,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00407d2f @ 00407d2f

UINT FUN_00407d2f(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00406b07(DAT_00428620);
      }
      return 0;
    }
    FUN_00406495(param_1);
    DAT_00429838 = param_1;
    DAT_00428620 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00412030 == 0);
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
      DAT_00412030 = (uint)(LVar2 == 0);
      FUN_00401529();
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
      DAT_00412030 = (uint)(LVar2 == 0);
      FUN_00401529();
      EndDialog(param_1,0);
      PostMessageA(DAT_00417308,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00429838 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00429838);
  SelectPalette(hdc,DAT_00412180,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00429838,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00429838,(RECT *)0x0,0);
    InvalidateRect(DAT_00417308,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00407f9b @ 00407f9b

UINT FUN_00407f9b(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_00406b07(DAT_00428f2c);
      }
      return 0;
    }
    FUN_00406495(param_1);
    DAT_00429898 = param_1;
    DAT_00428f2c = GetDlgItem(param_1,100);
    SetDlgItemTextA(param_1,0x1e,&DAT_00412040);
    if (DAT_00412a74 == 1) {
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
    _Size = 0x10;
    _Src = FUN_00401700((uint *)&DAT_00412dbc,DAT_00412020,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (param_3 == DAT_00429898) {
        return 0;
      }
    }
    hdc = GetDC(DAT_00429898);
    SelectPalette(hdc,DAT_00412180,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_00429898,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_00429898,(RECT *)0x0,0);
      InvalidateRect(DAT_00417308,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00412040,DAT_00412a74 * 0x11);
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


// ==== FUN_004082d9 @ 004082d9

UINT FUN_004082d9(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00406495(param_1);
      DAT_00429824 = param_1;
      DAT_00429894 = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00412b78) && (DAT_00412b78 < 10)) {
        SetDlgItemTextA(param_1,DAT_00412b78 + 0x33,&DAT_00412dc0);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_00401700((uint *)&DAT_00412dc4,*(int *)(&DAT_00416f78 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00416f50 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406b07(DAT_00429894);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00429824) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00429824);
      SelectPalette(hdc,DAT_00412180,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00429824,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00429824,(RECT *)0x0,0);
        InvalidateRect(DAT_00417308,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_004065cd(DAT_00429824), IVar5 == 1)) {
        if ((-1 < DAT_00412b78) && (DAT_00412b78 < 10)) {
          SetDlgItemTextA(param_1,DAT_00412b78 + 0x33,&DAT_00412dc8);
        }
        DAT_00412b78 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00416f78 + local_14 * 0x2c) = 0;
          _memset(&DAT_00416f50 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_00401700((uint *)&DAT_00412dcc,*(int *)(&DAT_00416f78 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00416f50 + local_14 * 0x2c);
        }
        FUN_00401529();
      }
    }
  }
  return 0;
}


// ==== FUN_00408656 @ 00408656

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_00408656(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  HWND pHVar1;
  LPCSTR pCVar2;
  HDC hdc;
  LRESULT LVar3;
  char *pcVar4;
  int iVar5;
  UINT UVar6;
  WPARAM WVar7;
  LPARAM LVar8;
  HIMC pHVar9;
  BOOL BVar10;
  int local_28;
  int local_1c;
  CHAR local_18 [12];
  HIMC local_c;
  int local_8;
  
  if (param_2 < 0x54) {
    if (param_2 == 0x53) {
      WinHelpA(DAT_00417308,s_MUDDLE_HLP_00412748,1,0xf);
      return 0;
    }
    if (param_2 != 0xf) {
      return 0;
    }
    FUN_00406b07(DAT_00428f54);
    return 0;
  }
  if (0x30f < param_2) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00428658 == param_3) {
      return 0;
    }
LAB_00408928:
    hdc = GetDC(DAT_00428658);
    SelectPalette(hdc,DAT_00412180,0);
    UVar6 = RealizePalette(hdc);
    ReleaseDC(DAT_00428658,hdc);
    if (UVar6 != 0) {
      InvalidateRect(DAT_00428658,(RECT *)0x0,0);
      InvalidateRect(DAT_00417308,(RECT *)0x0,0);
      return UVar6;
    }
    return 0;
  }
  if (param_2 == 0x30f) goto LAB_00408928;
  if (param_2 == 0x110) {
    FUN_00406495(param_1);
    DAT_00428658 = param_1;
    DAT_00428f54 = GetDlgItem(param_1,100);
    LVar8 = 0;
    UVar6 = 0xf1;
    WVar7 = DAT_00412188;
    pHVar1 = GetDlgItem(param_1,0x33);
    SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    LVar8 = 0;
    UVar6 = 0xf1;
    WVar7 = DAT_0041218c;
    pHVar1 = GetDlgItem(param_1,0x32);
    SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    LVar8 = 0;
    UVar6 = 0xf1;
    WVar7 = DAT_0041203c;
    pHVar1 = GetDlgItem(param_1,0x28);
    SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    CheckRadioButton(param_1,0x5e,0x62,_DAT_0041202c + 0x5d);
    if (DAT_00412a74 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00412040);
    LVar8 = 0;
    WVar7 = 2;
    UVar6 = 0xc5;
    pHVar1 = GetDlgItem(param_1,0xf);
    SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    pHVar9 = (HIMC)0x0;
    pHVar1 = GetDlgItem(param_1,0xf);
    DAT_0042989c = ImmAssociateContext(pHVar1,pHVar9);
    pCVar2 = FUN_00401700((uint *)&DAT_00412dd0,_DAT_00412028,-1);
    SetDlgItemTextA(param_1,0xf,pCVar2);
    DAT_0042a164 = GetDlgItem(param_1,0x3ea);
    if (_DAT_0041202c == 1) {
      SendMessageA(DAT_0042a164,0x465,0,0x10008);
    }
    else {
      SendMessageA(DAT_0042a164,0x465,0,0x1000a);
    }
    if (_DAT_0041202c == 1) {
      FUN_00405cb0(DAT_0042a190,0xc9,&DAT_00427bb0,0x78);
    }
    else {
      FUN_00405cb0(DAT_0042a190,0xca,&DAT_00427bb0,0x78);
    }
    SetDlgItemTextA(param_1,0x10,&DAT_00427bb0);
    if ((_DAT_0041202c == 1) || (_DAT_0041202c == 5)) {
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0xf);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0x10);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0x3ea);
      EnableWindow(pHVar1,BVar10);
    }
    else {
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0xf);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0x10);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0x3ea);
      EnableWindow(pHVar1,BVar10);
    }
    return 1;
  }
  if (param_2 != 0x111) {
    return 0;
  }
  switch((uint)param_3 & 0xffff) {
  case 1:
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x33);
    DAT_00412188 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x32);
    DAT_0041218c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x28);
    DAT_0041203c = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x5e);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      _DAT_0041202c = 1;
    }
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x5f);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      _DAT_0041202c = 2;
    }
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x60);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      _DAT_0041202c = 3;
    }
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x61);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      _DAT_0041202c = 4;
    }
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x62);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      _DAT_0041202c = 5;
    }
    GetDlgItemTextA(param_1,0x1e,&DAT_00412040,DAT_00412a74 * 0x11);
    GetDlgItemTextA(param_1,0xf,local_18,5);
    for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
      pcVar4 = FUN_00401700((uint *)&DAT_00412e00,local_28,-1);
      iVar5 = _strcmp(local_18,pcVar4);
      if (iVar5 == 0) {
LAB_00409139:
        _DAT_00412028 = local_28;
        break;
      }
      pcVar4 = FUN_00401700((uint *)&DAT_00412e04,local_28,2);
      iVar5 = _strcmp(local_18,pcVar4);
      if (iVar5 == 0) goto LAB_00409139;
    }
  case 2:
    DAT_00428658 = (HWND)0x0;
    pHVar9 = DAT_0042989c;
    pHVar1 = GetDlgItem(param_1,0xf);
    ImmAssociateContext(pHVar1,pHVar9);
    EndDialog(param_1,0);
    return 1;
  case 0xf:
    if ((uint)param_3 >> 0x10 == 0x200) {
      GetDlgItemTextA(param_1,0xf,local_18,5);
      local_1c = _DAT_00412028;
      LVar8 = 0;
      WVar7 = 0;
      UVar6 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x5e);
      LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      if (LVar3 == 0) {
        for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
          pcVar4 = FUN_00401700((uint *)&DAT_00412ddc,local_28,-1);
          iVar5 = _strcmp(local_18,pcVar4);
          if (iVar5 == 0) {
LAB_00408b13:
            local_1c = local_28;
            break;
          }
          pcVar4 = FUN_00401700((uint *)&DAT_00412de0,local_28,2);
          iVar5 = _strcmp(local_18,pcVar4);
          if (iVar5 == 0) goto LAB_00408b13;
        }
      }
      else {
        for (local_28 = 1; local_28 < 9; local_28 = local_28 + 1) {
          pcVar4 = FUN_00401700((uint *)&DAT_00412dd4,local_28,-1);
          iVar5 = _strcmp(local_18,pcVar4);
          if (iVar5 == 0) {
LAB_00408a95:
            local_1c = local_28;
            break;
          }
          pcVar4 = FUN_00401700((uint *)&DAT_00412dd8,local_28,2);
          iVar5 = _strcmp(local_18,pcVar4);
          if (iVar5 == 0) goto LAB_00408a95;
        }
      }
      pCVar2 = FUN_00401700((uint *)&DAT_00412de4,local_1c,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
    }
    break;
  case 0x1e:
    if ((uint)param_3 >> 0x10 == 0x100) {
      local_c = ImmGetContext(param_4);
      if (local_c != (HIMC)0x0) {
        ImmSetOpenStatus(local_c,1);
        ImmReleaseContext(param_4,local_c);
        return 1;
      }
      return 0;
    }
    if ((uint)param_3 >> 0x10 == 0x200) {
      local_c = ImmGetContext(param_4);
      if (local_c != (HIMC)0x0) {
        ImmSetOpenStatus(local_c,0);
        ImmReleaseContext(param_4,local_c);
        return 1;
      }
      return 0;
    }
    break;
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x5e);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      FUN_00405cb0(DAT_0042a190,0xc9,&DAT_00427bb0,0x78);
      GetDlgItemTextA(param_1,0xf,local_18,5);
      local_1c = _DAT_00412028;
      for (local_28 = 1; local_28 < 9; local_28 = local_28 + 1) {
        pcVar4 = FUN_00401700((uint *)&DAT_00412de8,local_28,-1);
        iVar5 = _strcmp(local_18,pcVar4);
        if (iVar5 == 0) {
LAB_00408cc6:
          local_1c = local_28;
          break;
        }
        pcVar4 = FUN_00401700((uint *)&DAT_00412dec,local_28,2);
        iVar5 = _strcmp(local_18,pcVar4);
        if (iVar5 == 0) goto LAB_00408cc6;
      }
      if (8 < local_1c) {
        local_1c = 8;
      }
      pCVar2 = FUN_00401700((uint *)&DAT_00412df0,local_1c,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      SendMessageA(DAT_0042a164,0x465,0,0x10008);
    }
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x62);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 != 0) {
      FUN_00405cb0(DAT_0042a190,0xca,&DAT_00427bb0,0x78);
      GetDlgItemTextA(param_1,0xf,local_18,5);
      local_1c = _DAT_00412028;
      for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
        pcVar4 = FUN_00401700((uint *)&DAT_00412df4,local_28,-1);
        iVar5 = _strcmp(local_18,pcVar4);
        if (iVar5 == 0) {
LAB_00408de0:
          local_1c = local_28;
          break;
        }
        pcVar4 = FUN_00401700((uint *)&DAT_00412df8,local_28,2);
        iVar5 = _strcmp(local_18,pcVar4);
        if (iVar5 == 0) goto LAB_00408de0;
      }
      if (10 < local_1c) {
        local_1c = 10;
      }
      pCVar2 = FUN_00401700((uint *)&DAT_00412dfc,local_1c,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      SendMessageA(DAT_0042a164,0x465,0,0x1000a);
    }
    SetDlgItemTextA(param_1,0x10,&DAT_00427bb0);
    LVar8 = 0;
    WVar7 = 0;
    UVar6 = 0xf0;
    pHVar1 = GetDlgItem(param_1,0x5e);
    LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
    if (LVar3 == 0) {
      LVar8 = 0;
      WVar7 = 0;
      UVar6 = 0xf0;
      pHVar1 = GetDlgItem(param_1,0x62);
      LVar3 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      if (LVar3 != 0) goto LAB_00408e92;
      local_8 = 0;
    }
    else {
LAB_00408e92:
      local_8 = 1;
    }
    if (local_8 == 0) {
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0xf);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0x10);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 0;
      pHVar1 = GetDlgItem(param_1,0x3ea);
      EnableWindow(pHVar1,BVar10);
    }
    else {
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0xf);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0x10);
      EnableWindow(pHVar1,BVar10);
      BVar10 = 1;
      pHVar1 = GetDlgItem(param_1,0x3ea);
      EnableWindow(pHVar1,BVar10);
    }
    break;
  case 99:
    WinHelpA(DAT_00417308,s_MUDDLE_HLP_00412748,1,0xf);
  }
  return 0;
}


// ==== FUN_004092a1 @ 004092a1

UINT FUN_004092a1(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00406495(param_1);
      DAT_0042a390 = param_1;
      DAT_00428f50 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00406bfc(DAT_00428f50);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0042a390 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0042a390);
      SelectPalette(hdc,DAT_00412180,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_0042a390,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00429824,(RECT *)0x0,0);
        InvalidateRect(DAT_0042a390,(RECT *)0x0,0);
        InvalidateRect(DAT_00417308,(RECT *)0x0,0);
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


// ==== FUN_00409448 @ 00409448

void FUN_00409448(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_0040eee0(DVar1);
  return;
}


// ==== FUN_00409467 @ 00409467

int __cdecl FUN_00409467(int param_1)

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


// ==== FUN_00409498 @ 00409498

void FUN_00409498(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (DAT_00412034 == 0) {
    UVar3 = 0;
    UVar2 = 0x131;
    pHVar1 = GetMenu(DAT_00417308);
    CheckMenuItem(pHVar1,UVar2,UVar3);
  }
  else {
    UVar3 = 8;
    UVar2 = 0x131;
    pHVar1 = GetMenu(DAT_00417308);
    CheckMenuItem(pHVar1,UVar2,UVar3);
  }
  return;
}


// ==== FUN_004094ee @ 004094ee

void FUN_004094ee(void)

{
  FUN_004017c9(0);
  SelectPalette(DAT_004172c0,DAT_00412180,0);
  RealizePalette(DAT_004172c0);
  FUN_00403755();
  FUN_00401829(0);
  return;
}


// ==== FUN_00409537 @ 00409537

void __cdecl FUN_00409537(int param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < param_1 / 0x32; local_8 = local_8 + 1) {
    Sleep(0x32);
    FUN_0040d05e();
  }
  return;
}


// ==== FUN_0040957f @ 0040957f

UINT FUN_0040957f(void)

{
  UINT UVar1;
  
  FUN_004017c9(0);
  SelectPalette(DAT_004172c0,DAT_00412180,0);
  UVar1 = RealizePalette(DAT_004172c0);
  FUN_00401829(0);
  if (UVar1 != 0) {
    InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  }
  return UVar1;
}


// ==== FUN_004095e6 @ 004095e6

void FUN_004095e6(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  DAT_00412a6c = 1;
  for (local_8 = 0x28; local_8 < 0x100; local_8 = local_8 + 1) {
    FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),-0x28,-0x28,-1);
  }
  FUN_0040314b(DAT_00429820,DAT_004123e4,0xd6,DAT_004123ac + -0x62);
  InvalidateRect(DAT_00417308,(RECT *)0x0,0);
  UpdateWindow(DAT_00417308);
  if (100 < DAT_00412020) {
    iVar1 = FUN_00401348(DAT_00412020,&local_c);
    if ((iVar1 != 0) && (local_c < 10)) {
      FUN_004023b2(1);
      if (DAT_0041203c != 0) {
        FUN_004069e2();
      }
      iVar1 = FUN_004013e5(DAT_00412020);
      if (0 < iVar1) {
        DAT_00412b78 = local_c;
        FUN_00406a31();
      }
      FUN_00401529();
    }
  }
  FUN_004023b2(3);
  return;
}


// ==== FUN_00409702 @ 00409702

void FUN_00409702(void)

{
  int local_c;
  int local_8;
  
  if (DAT_00412730 == 1) {
    for (local_c = 0x16; local_c < 0x26; local_c = local_c + 1) {
      FUN_00403ff9((int *)(&DAT_00420da8 + local_c * 0x2c));
    }
  }
  else {
    local_8 = 0x16;
    for (local_c = 0; local_c < DAT_00412b7c; local_c = local_c + 1) {
      FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),0x22,
                   DAT_004123ac - (local_c * -5 + 0x14f),local_c + 1);
      FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),DAT_00412b84 + -1);
      local_8 = local_8 + 1;
    }
    for (local_c = 0; local_c < DAT_00412b80; local_c = local_c + 1) {
      FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),0x9c,
                   DAT_004123ac - (local_c * -5 + 0x14d),local_c + 1);
      FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),DAT_00412b84 + -1);
      local_8 = local_8 + 1;
    }
    for (local_c = 0; local_c < 0x10 - (DAT_00412b80 + DAT_00412b7c); local_c = local_c + 1) {
      FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),0x5f,
                   DAT_004123ac - (local_c * -5 + 0x152),local_c + 1);
      FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),DAT_00412b84 + -1);
      local_8 = local_8 + 1;
    }
  }
  return;
}


// ==== FUN_004098f2 @ 004098f2

void FUN_004098f2(void)

{
  undefined4 local_8;
  
  if (DAT_00412730 != 1) {
    for (local_8 = 1; local_8 < 5; local_8 = local_8 + 1) {
      if (*(int *)(local_8 * 4 + 0x412b88) * 8 <= DAT_00412020) {
        FUN_0040314b(*(int *)(local_8 * 4 + 0x42a170),DAT_004123e4,(local_8 * 5 + -5) * 8 + 0xe,
                     DAT_004123ac + -0xb7);
      }
    }
  }
  return;
}


// ==== FUN_00409980 @ 00409980

/* WARNING: Removing unreachable block (ram,0x004099a2) */

void FUN_00409980(void)

{
  int iStack00000004;
  int local_c;
  int local_8;
  
  local_c = DAT_00412020;
  iStack00000004 = 0;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_00403d90((int *)(&DAT_00420da8 + (0x14 - local_8) * 0x2c),local_c % 10);
    local_c = local_c / 10;
  }
  if (iStack00000004 != 0) {
    FUN_00401829(0);
  }
  return;
}


// ==== FUN_00409a42 @ 00409a42

void __cdecl FUN_00409a42(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_004123ac - param_2;
  if ((((DAT_00412b9c == 0) || (param_1 < 0xf)) || (0xa9 < param_1)) ||
     ((iVar1 < 0xb8 || (0xf6 < iVar1)))) {
    if (((param_1 < 0x153) || ((0x184 < param_1 || (iVar1 < 0)))) || (0x19 < iVar1)) {
      if ((((param_1 < 0x184) || (0x1b5 < param_1)) || (iVar1 < 0)) || (0x19 < iVar1)) {
        if (((param_1 < 0xba) || (0xd3 < param_1)) || ((iVar1 < 0x97 || (0xca < iVar1)))) {
          if (((param_1 < 0xba) || (0xd3 < param_1)) || ((iVar1 < 0xca || (0xfd < iVar1)))) {
            if ((((param_1 < 0x235) || (0x24e < param_1)) || (iVar1 < 0x97)) || (0xca < iVar1)) {
              if (((param_1 < 0x235) || (0x24e < param_1)) || ((iVar1 < 0xca || (0xfd < iVar1)))) {
                if (((param_1 < 0x153) || (0x184 < param_1)) || ((iVar1 < 0x17b || (0x194 < iVar1)))
                   ) {
                  if ((((param_1 < 0x184) || (0x1b5 < param_1)) || (iVar1 < 0x17b)) ||
                     (0x194 < iVar1)) {
                    iVar1 = (DAT_004123ac - iVar1) + -0x1b;
                    if ((-1 < param_1 + -0xd6) && (0 < iVar1)) {
                      iVar2 = (param_1 + -0xd6) / 0x19;
                      iVar1 = iVar1 / 0x23;
                      if (((-1 < iVar2) && ((iVar2 < 0xe && (-1 < iVar1)))) && (iVar1 < 10)) {
                        PostMessageA(DAT_00417308,0x100,0x20,0);
                      }
                    }
                  }
                  else {
                    DAT_00412a60 = 5;
                    DAT_00412a5c = 5;
                    FUN_0040b2b5();
                  }
                }
                else {
                  DAT_00412a60 = 6;
                  DAT_00412a5c = 6;
                  FUN_0040b2b5();
                }
              }
              else {
                DAT_00412a60 = 3;
                DAT_00412a58 = 3;
                FUN_0040b2b5();
              }
            }
            else {
              DAT_00412a60 = 4;
              DAT_00412a58 = 4;
              FUN_0040b2b5();
            }
          }
          else {
            DAT_00412a60 = 7;
            DAT_00412a54 = 7;
            FUN_0040b2b5();
          }
        }
        else {
          DAT_00412a60 = 8;
          DAT_00412a54 = 8;
          FUN_0040b2b5();
        }
      }
      else {
        DAT_00412a60 = 1;
        DAT_00412a50 = 1;
        FUN_0040b2b5();
      }
    }
    else {
      DAT_00412a60 = 2;
      DAT_00412a50 = 2;
      FUN_0040b2b5();
    }
  }
  else if (DAT_00412730 != 1) {
    FUN_004023b2(2);
    DAT_00412b84 = (param_1 + -0xe) / 0x27 + 1;
    if (DAT_00412b84 < 1) {
      DAT_00412b84 = 1;
    }
    if (4 < DAT_00412b84) {
      DAT_00412b84 = 4;
    }
    while ((1 < DAT_00412b84 && (DAT_00412020 < *(int *)(DAT_00412b84 * 4 + 0x412b88) * 8))) {
      DAT_00412b84 = DAT_00412b84 + -1;
    }
    FUN_00409702();
    FUN_004094ee();
  }
  return;
}


// ==== FUN_00409e52 @ 00409e52

void __cdecl FUN_00409e52(int param_1,int param_2)

{
  if ((((0 < param_1) && (0 < param_2)) && (param_1 < 0x15e)) && (param_2 < 0x15e)) {
    PostMessageA(DAT_00417308,0x100,9,0);
  }
  return;
}


// ==== FUN_00409ea5 @ 00409ea5

void __cdecl FUN_00409ea5(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    DAT_00412a68 = 0;
    FUN_00401529();
    FUN_004020b5(0);
  }
  else {
    DAT_00412a68 = 1;
    FUN_004010b8();
    if (DAT_00412a64 == 0) {
      iVar1 = FUN_00409467(2);
      FUN_004020b5(iVar1 + 2);
    }
    else {
      FUN_004020b5(1);
    }
  }
  return;
}


// ==== FUN_00409f1e @ 00409f1e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409f1e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0041218c;
  iVar2 = _DAT_0041202c;
  iVar1 = _DAT_00412028;
  FUN_00406a9c();
  if (iVar3 != DAT_0041218c) {
    if (DAT_00412a64 == 0) {
      iVar3 = FUN_00409467(2);
      FUN_004020b5(iVar3 + 2);
    }
    else {
      FUN_004020b5(1);
    }
  }
  if ((_DAT_0041202c != iVar2) || (_DAT_00412028 != iVar1)) {
    SendMessageA(DAT_00417308,0x111,0x65,1);
  }
  FUN_00401529();
  return;
}


// ==== FUN_00409fc6 @ 00409fc6

undefined4 FUN_00409fc6(void)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_00412a6c == 0) && (DAT_00412a64 == 0)) {
    IVar1 = FUN_004067e8();
    if (IVar1 == 1) {
      if (((100 < DAT_00412020) && (iVar2 = FUN_00401348(DAT_00412020,&local_8), iVar2 != 0)) &&
         (local_8 < 10)) {
        if (DAT_0041203c != 0) {
          FUN_004069e2();
        }
        iVar2 = FUN_004013e5(DAT_00412020);
        if (0 < iVar2) {
          DAT_00412b78 = local_8;
          FUN_00406a31();
        }
      }
      FUN_00401529();
      SendMessageA(DAT_00417308,2,0,0);
      WinHelpA(DAT_00417308,s_MUDDLE_HLP_00412748,2,0);
    }
  }
  else {
    SendMessageA(DAT_00417308,2,0,0);
    WinHelpA(DAT_00417308,s_MUDDLE_HLP_00412748,2,0);
  }
  return 0;
}


// ==== FUN_0040a0c1 @ 0040a0c1

undefined4 __cdecl FUN_0040a0c1(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int local_c;
  int local_8;
  
  local_8 = param_1;
  if ((param_3 == 1) || (param_3 == 2)) {
    do {
      local_8 = local_8 + 1;
      if (9 < local_8) goto LAB_0040a16f;
    } while (((*(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0) < 1) ||
             (8 < *(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0))) &&
            (*(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0) != 0xb));
    uVar1 = 1;
  }
  else {
LAB_0040a16f:
    local_8 = param_1;
    if ((param_3 == 5) || (param_3 == 6)) {
      do {
        local_8 = local_8 + -1;
        if (local_8 < 0) goto LAB_0040a214;
      } while (((*(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0) < 1) ||
               (8 < *(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0))) &&
              (*(int *)(&DAT_00428f60 + param_2 * 0x10 + local_8 * 0xe0) != 0xb));
      uVar1 = 1;
    }
    else {
LAB_0040a214:
      local_c = param_2;
      if ((param_3 == 7) || (param_3 == 8)) {
        do {
          local_c = local_c + -1;
          if (local_c < 0) goto LAB_0040a2b9;
        } while (((*(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0) < 1) ||
                 (8 < *(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0))) &&
                (*(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0) != 0xb));
        uVar1 = 1;
      }
      else {
LAB_0040a2b9:
        if ((param_3 == 3) || (param_3 == 4)) {
          do {
            local_c = param_2 + 1;
            if (0xd < local_c) goto LAB_0040a35e;
          } while (((*(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0) < 1) ||
                   (8 < *(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0))) &&
                  (param_2 = local_c,
                  *(int *)(&DAT_00428f60 + local_c * 0x10 + param_1 * 0xe0) != 0xb));
          uVar1 = 1;
        }
        else {
LAB_0040a35e:
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}


// ==== FUN_0040a36a @ 0040a36a

undefined4 __cdecl FUN_0040a36a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(&DAT_00428f60 + param_2 * 0x10 + param_1 * 0xe0);
  if (((0 < iVar1) && (iVar1 < 9)) && (iVar2 = FUN_0040a0c1(param_1,param_2,param_3), iVar2 == 0)) {
    if (param_3 == 1) {
      if (iVar1 == 1) {
        return 1;
      }
      if (iVar1 == 2) {
        return 1;
      }
      if (iVar1 == 3) {
        return 1;
      }
      if (iVar1 == 4) {
        return 1;
      }
    }
    if (param_3 == 2) {
      if (iVar1 == 5) {
        return 1;
      }
      if (iVar1 == 6) {
        return 1;
      }
      if (iVar1 == 7) {
        return 1;
      }
      if (iVar1 == 8) {
        return 1;
      }
    }
    if (param_3 == 7) {
      if (iVar1 == 2) {
        return 4;
      }
      if (iVar1 == 3) {
        return 4;
      }
      if (iVar1 == 5) {
        return 4;
      }
      if (iVar1 == 8) {
        return 4;
      }
    }
    if (param_3 == 8) {
      if (iVar1 == 1) {
        return 4;
      }
      if (iVar1 == 4) {
        return 4;
      }
      if (iVar1 == 6) {
        return 4;
      }
      if (iVar1 == 7) {
        return 4;
      }
    }
    if (param_3 == 3) {
      if (iVar1 == 2) {
        return 2;
      }
      if (iVar1 == 5) {
        return 2;
      }
      if (iVar1 == 1) {
        return 2;
      }
      if (iVar1 == 6) {
        return 2;
      }
    }
    if (param_3 == 4) {
      if (iVar1 == 3) {
        return 2;
      }
      if (iVar1 == 8) {
        return 2;
      }
      if (iVar1 == 4) {
        return 2;
      }
      if (iVar1 == 7) {
        return 2;
      }
    }
    if (param_3 == 5) {
      if (iVar1 == 5) {
        return 3;
      }
      if (iVar1 == 1) {
        return 3;
      }
      if (iVar1 == 3) {
        return 3;
      }
      if (iVar1 == 7) {
        return 3;
      }
    }
    if (param_3 == 6) {
      if (iVar1 == 2) {
        return 3;
      }
      if (iVar1 == 6) {
        return 3;
      }
      if (iVar1 == 8) {
        return 3;
      }
      if (iVar1 == 4) {
        return 3;
      }
    }
  }
  return 0;
}


// ==== FUN_0040a6aa @ 0040a6aa

undefined4 __cdecl FUN_0040a6aa(int param_1,int param_2,int param_3)

{
  int local_8;
  
  if (param_2 == 0xe) {
    local_8 = (&DAT_0042a2f0)[DAT_00412ba0 * 4];
  }
  else {
    local_8 = *(int *)(&DAT_00428f60 + param_1 * 0xe0 + param_2 * 0x10);
  }
  if ((local_8 < 1) || (8 < local_8)) {
    return 0;
  }
  if (param_3 == 1) {
    if (local_8 == 1) {
      return 1;
    }
    if (local_8 == 2) {
      return 1;
    }
    if (local_8 == 3) {
      return 1;
    }
    if (local_8 == 4) {
      return 1;
    }
  }
  if (param_3 == 2) {
    if (local_8 == 5) {
      return 1;
    }
    if (local_8 == 6) {
      return 1;
    }
    if (local_8 == 7) {
      return 1;
    }
    if (local_8 == 8) {
      return 1;
    }
  }
  if (param_3 == 7) {
    if (local_8 == 2) {
      return 4;
    }
    if (local_8 == 3) {
      return 4;
    }
    if (local_8 == 5) {
      return 4;
    }
    if (local_8 == 8) {
      return 4;
    }
  }
  if (param_3 == 8) {
    if (local_8 == 1) {
      return 4;
    }
    if (local_8 == 4) {
      return 4;
    }
    if (local_8 == 6) {
      return 4;
    }
    if (local_8 == 7) {
      return 4;
    }
  }
  if (param_3 == 3) {
    if (local_8 == 2) {
      return 2;
    }
    if (local_8 == 5) {
      return 2;
    }
    if (local_8 == 1) {
      return 2;
    }
    if (local_8 == 6) {
      return 2;
    }
  }
  if (param_3 == 4) {
    if (local_8 == 3) {
      return 2;
    }
    if (local_8 == 8) {
      return 2;
    }
    if (local_8 == 4) {
      return 2;
    }
    if (local_8 == 7) {
      return 2;
    }
  }
  if (param_3 == 5) {
    if (local_8 == 5) {
      return 3;
    }
    if (local_8 == 1) {
      return 3;
    }
    if (local_8 == 3) {
      return 3;
    }
    if (local_8 == 7) {
      return 3;
    }
  }
  if (param_3 == 6) {
    if (local_8 == 2) {
      return 3;
    }
    if (local_8 == 6) {
      return 3;
    }
    if (local_8 == 8) {
      return 3;
    }
    if (local_8 == 4) {
      return 3;
    }
  }
  return 0;
}


// ==== FUN_0040a9e7 @ 0040a9e7

void FUN_0040a9e7(void)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_8;
  
  if ((DAT_0042a2f0 < 1) || (8 < DAT_0042a2f0)) {
    FUN_00403ff9((int *)&DAT_00421144);
  }
  else {
    FUN_00404062((int *)&DAT_00421144,1);
    FUN_00403d90((int *)&DAT_00421144,DAT_0042a2f0 + -1);
  }
  FUN_0040314b(DAT_0042a1a4,DAT_004123e4,0x185,DAT_004123ac);
  FUN_0040314b(DAT_00428f24,DAT_004123e4,0x153,DAT_004123ac);
  FUN_0040314b(DAT_00428654,DAT_004123e4,0xba,DAT_004123ac + -0xcb);
  FUN_0040314b(DAT_0042a24c,DAT_004123e4,0xba,DAT_004123ac + -0x97);
  FUN_0040314b(DAT_00429834,DAT_004123e4,0x235,DAT_004123ac + -0xcb);
  FUN_0040314b(DAT_00428f34,DAT_004123e4,0x235,DAT_004123ac + -0x97);
  FUN_0040314b(DAT_00428f44,DAT_004123e4,0x185,DAT_004123ac + -0x17b);
  FUN_0040314b(DAT_00427c3c,DAT_004123e4,0x153,DAT_004123ac + -0x17b);
  switch(DAT_00412a60) {
  case 1:
    FUN_0040314b(DAT_0042a1a0,DAT_004123e4,0x185,DAT_004123ac);
    break;
  case 2:
    FUN_0040314b(DAT_00428f20,DAT_004123e4,0x153,DAT_004123ac);
    break;
  case 3:
    FUN_0040314b(DAT_00429830,DAT_004123e4,0x235,DAT_004123ac + -0xcb);
    break;
  case 4:
    FUN_0040314b(DAT_00428f30,DAT_004123e4,0x235,DAT_004123ac + -0x97);
    break;
  case 5:
    FUN_0040314b(DAT_00428f40,DAT_004123e4,0x185,DAT_004123ac + -0x17b);
    break;
  case 6:
    FUN_0040314b(DAT_00427c38,DAT_004123e4,0x153,DAT_004123ac + -0x17b);
    break;
  case 7:
    FUN_0040314b(DAT_00428650,DAT_004123e4,0xba,DAT_004123ac + -0xcb);
    break;
  case 8:
    FUN_0040314b(DAT_0042a248,DAT_004123e4,0xba,DAT_004123ac + -0x97);
  }
  DAT_004123b4 = 1;
  for (local_10 = 8; local_10 < 0x10; local_10 = local_10 + 1) {
    FUN_00403ff9((int *)(&DAT_00420da8 + local_10 * 0x2c));
  }
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    if ((&DAT_0042a2f0)[local_10 * 4] != 0) {
      *(int *)(&DAT_0042a2f4 + local_10 * 0x10) = local_10 + 8;
      if ((&DAT_0042a2f0)[local_10 * 4] < 5) {
        FUN_0040519a(&DAT_004181a0,(int)(&DAT_00420da8 + (local_10 + 8) * 0x2c));
        FUN_00403ff9((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c));
        FUN_00403d90((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c),
                     (&DAT_0042a2f0)[local_10 * 4] * 5 + -5);
        FUN_00403f39((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c),0x262,local_10 * 0x2d + 0x2c,1);
      }
      else if ((&DAT_0042a2f0)[local_10 * 4] < 9) {
        FUN_0040519a(&DAT_004183c4,(int)(&DAT_00420da8 + (local_10 + 8) * 0x2c));
        FUN_00403ff9((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c));
        FUN_00403d90((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c),
                     (&DAT_0042a2f0)[local_10 * 4] * 5 + -0x19);
        FUN_00403f39((int *)(&DAT_00420da8 + (local_10 + 8) * 0x2c),0x262,local_10 * 0x2d + 0x2c,1);
      }
    }
  }
  for (local_10 = 0x28; local_10 < 0x100; local_10 = local_10 + 1) {
    FUN_00403ff9((int *)(&DAT_00420da8 + local_10 * 0x2c));
  }
  local_8 = 0x28;
  local_10 = 0;
  do {
    if (9 < local_10) {
      return;
    }
    for (local_14 = 0; local_14 < 0xe; local_14 = local_14 + 1) {
      if (*(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) != 0) {
        *(int *)(&DAT_00428f64 + local_10 * 0xe0 + local_14 * 0x10) = local_8;
        if (*(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) < 5) {
          FUN_0040519a(&DAT_004181a0,(int)(&DAT_00420da8 + local_8 * 0x2c));
          FUN_00403ff9((int *)(&DAT_00420da8 + local_8 * 0x2c));
          iVar1 = FUN_0040a36a(local_10,local_14,DAT_00412a60);
          FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),
                       *(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) * 5 + -5 + iVar1)
          ;
          FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),local_14 * 0x19 + 0xe2,
                       local_10 * 0x23 + 0x2c,1);
        }
        else if (*(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) < 9) {
          FUN_0040519a(&DAT_004183c4,(int)(&DAT_00420da8 + local_8 * 0x2c));
          FUN_00403ff9((int *)(&DAT_00420da8 + local_8 * 0x2c));
          iVar1 = FUN_0040a36a(local_10,local_14,DAT_00412a60);
          FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),
                       *(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) * 5 + -0x19 +
                       iVar1);
          FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),local_14 * 0x19 + 0xe2,
                       local_10 * 0x23 + 0x2c,1);
        }
        else {
          if (0xc < *(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10)) goto LAB_0040af51;
          FUN_0040519a(&DAT_004185e8,(int)(&DAT_00420da8 + local_8 * 0x2c));
          FUN_00403ff9((int *)(&DAT_00420da8 + local_8 * 0x2c));
          FUN_00403d90((int *)(&DAT_00420da8 + local_8 * 0x2c),
                       *(int *)(&DAT_00428f60 + local_10 * 0xe0 + local_14 * 0x10) + -9);
          FUN_00403f39((int *)(&DAT_00420da8 + local_8 * 0x2c),local_14 * 0x19 + 0xe2,
                       local_10 * 0x23 + 0x2c,1);
        }
        local_8 = local_8 + 1;
        if (0xff < local_8) {
          return;
        }
      }
LAB_0040af51:
    }
    local_10 = local_10 + 1;
  } while( true );
}


// ==== FUN_0040b2b5 @ 0040b2b5

void FUN_0040b2b5(void)

{
  FUN_004023b2(7);
  FUN_0040a9e7();
  FUN_004094ee();
  return;
}


// ==== FUN_0040b2d9 @ 0040b2d9

void __cdecl FUN_0040b2d9(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  if ((param_1 == 1) || (param_1 == 2)) {
    *param_3 = 1;
  }
  else if ((param_1 == 7) || (param_1 == 8)) {
    *param_2 = 0xffffffff;
  }
  else if ((param_1 == 3) || (param_1 == 4)) {
    *param_2 = 1;
  }
  else if ((param_1 == 5) || (param_1 == 6)) {
    *param_3 = 0xffffffff;
  }
  return;
}


// ==== FUN_0040b383 @ 0040b383

void __cdecl FUN_0040b383(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 0;
  if ((param_1 == 1) || (param_1 == 2)) {
    *param_3 = 0xffffffff;
  }
  else if ((param_1 == 7) || (param_1 == 8)) {
    *param_2 = 1;
  }
  else if ((param_1 == 3) || (param_1 == 4)) {
    *param_2 = 0xffffffff;
  }
  else if ((param_1 == 5) || (param_1 == 6)) {
    *param_3 = 1;
  }
  return;
}


// ==== FUN_0040b42d @ 0040b42d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040b42d(int param_1)

{
  int iVar1;
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
  
  local_28 = 0;
  local_38 = 0;
  local_18 = -1;
  local_30 = -1;
  local_10 = 0;
  local_14 = 0;
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    for (local_24 = 0; local_24 < 0xe; local_24 = local_24 + 1) {
      if (*(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0) == 0xc) {
        if (local_18 < 0) {
          local_18 = local_24;
          local_1c = local_20;
        }
        else {
          local_30 = local_24;
          local_34 = local_20;
        }
      }
    }
  }
  FID_conflict__memcpy(&DAT_004298a0,&DAT_00428f60,0x8c0);
  FID_conflict__memcpy(&DAT_0042a1a8,&DAT_0042a2f0,0xa0);
  local_20 = 0;
  do {
    if (9 < local_20) {
      if (((((-1 < local_1c) && (-1 < local_18)) && (-1 < local_34)) && (-1 < local_30)) &&
         ((0 < local_10 || (0 < local_14)))) {
        *(int *)(&DAT_004298a0 + local_1c * 0xe0 + local_18 * 0x10) = local_14;
        *(int *)(&DAT_004298a0 + local_30 * 0x10 + local_34 * 0xe0) = local_10;
      }
      FID_conflict__memcpy(&DAT_00428f60,&DAT_004298a0,0x8c0);
      FID_conflict__memcpy(&DAT_0042a2f0,&DAT_0042a1a8,0xa0);
      if (DAT_00412b9c != 0) {
        DAT_00412b9c = 0;
        DAT_00412b7c = 0;
        DAT_00412b80 = 0;
        FUN_00409702();
        if (DAT_00412730 != 1) {
          DAT_00412020 = DAT_00412020 + *(int *)(DAT_00412b84 * 4 + 0x412b88) * -8;
        }
        FUN_00409980();
      }
      iVar1 = DAT_00412b7c;
      if ((local_28 < 1) && (local_38 < 1)) {
        FUN_004023b2(4);
      }
      else {
        if (0 < local_28) {
          local_3c = DAT_00412b7c;
          if (DAT_00412b7c < 4) {
            DAT_00412b7c = DAT_00412b7c + 1;
          }
          else if (DAT_00412b7c < 8) {
            DAT_00412b7c = DAT_00412b7c + 2;
          }
          else if (DAT_00412b7c < 0xb) {
            DAT_00412b7c = DAT_00412b7c + 3;
          }
          else {
            DAT_00412b7c = DAT_00412b7c + 5;
          }
          if (DAT_00412730 != 1) {
            DAT_00412020 = DAT_00412020 +
                           *(int *)(DAT_00412b84 * 4 + 0x412b88) * (DAT_00412b7c - iVar1);
          }
          FUN_004023b2(1);
          FUN_00409980();
        }
        if (0 < local_38) {
          FUN_004023b2(3);
          for (local_20 = 1; local_20 <= local_38; local_20 = local_20 + 1) {
            if (DAT_00412b80 == 0) {
              DAT_00412b80 = 5;
            }
            else if (DAT_00412b80 == 5) {
              DAT_00412b80 = 8;
            }
            else if (DAT_00412b80 == 8) {
              DAT_00412b80 = 10;
            }
            else if (DAT_00412b80 == 10) {
              DAT_00412b80 = 0xc;
            }
            else {
              DAT_00412b80 = DAT_00412b80 + 1;
            }
          }
        }
        if (0x10 < DAT_00412b7c) {
          DAT_00412b7c = 0x10;
        }
        if (0x10 < DAT_00412b80) {
          DAT_00412b80 = 0x10;
        }
        if (0x10 < DAT_00412b80 + DAT_00412b7c) {
          DAT_00412b80 = 0x10 - DAT_00412b7c;
        }
        FUN_00409702();
      }
      FUN_0040a9e7();
      FUN_004094ee();
      if (DAT_0042a2f0 == 0) {
        PostMessageA(DAT_00417308,0x111,0x79,0);
      }
      return;
    }
    for (local_24 = 0; local_24 < 0xe; local_24 = local_24 + 1) {
      if ((((0 < *(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0)) &&
           (*(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0) < 9)) &&
          (iVar1 = FUN_0040a0c1(local_20,local_24,DAT_00412a60), iVar1 == 0)) &&
         (local_c = FUN_0040a36a(local_20,local_24,DAT_00412a60), 0 < local_c)) {
        FUN_0040b2d9(DAT_00412a60,&local_8,&local_40);
        if ((((local_8 + local_24 == 0xe) || (local_8 + local_24 == -1)) ||
            ((local_40 + local_20 == 10 ||
             ((local_40 + local_20 == -1 ||
              (*(int *)(&DAT_00428f60 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0)
               == 9)))))) ||
           (*(int *)(&DAT_00428f60 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0) ==
            10)) {
          if ((((local_8 + local_24 == 0xe) && (local_40 + local_20 == 0)) ||
              (*(int *)(&DAT_00428f60 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0)
               == 9)) &&
             (*(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0) == DAT_0042a2f0)) {
            FID_conflict__memcpy(&DAT_0042a1a8,&DAT_0042a1b8,0x70);
            _DAT_0042a218 = 0;
            *(undefined4 *)(&DAT_004298a0 + local_24 * 0x10 + local_20 * 0xe0) = 0;
            if (*(int *)(&DAT_00428f60 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0)
                == 9) {
              *(undefined4 *)
               (&DAT_004298a0 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0) = 0;
            }
            local_28 = local_28 + 1;
          }
          else {
            if (param_1 == 0) {
              FUN_004023b2(5);
              return;
            }
            for (local_2c = 0; local_2c < 8; local_2c = local_2c + 1) {
              if (*(int *)(&DAT_004298a0 + local_24 * 0x10 + local_20 * 0xe0) ==
                  *(int *)(&DAT_0042a1a8 + local_2c * 0x10)) {
                local_38 = local_38 + 1;
                if (local_2c < 7) {
                  FID_conflict__memcpy
                            (&DAT_0042a1a8 + local_2c * 0x10,&DAT_0042a1a8 + (local_2c + 1) * 0x10,
                             (7 - local_2c) * 0x10);
                }
                _DAT_0042a218 = 0;
                break;
              }
            }
            *(undefined4 *)(&DAT_004298a0 + local_24 * 0x10 + local_20 * 0xe0) = 0;
          }
        }
        else {
          if ((local_40 + local_20 == local_1c) && (local_8 + local_24 == local_18)) {
            local_10 = *(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0);
          }
          if ((local_40 + local_20 == local_34) && (local_8 + local_24 == local_30)) {
            local_14 = *(int *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0);
          }
          *(undefined4 *)
           (&DAT_004298a0 + (local_8 + local_24) * 0x10 + (local_40 + local_20) * 0xe0) =
               *(undefined4 *)(&DAT_00428f60 + local_24 * 0x10 + local_20 * 0xe0);
          *(undefined4 *)(&DAT_004298a0 + local_24 * 0x10 + local_20 * 0xe0) = 0;
        }
      }
    }
    local_20 = local_20 + 1;
  } while( true );
}


// ==== FUN_0040bc16 @ 0040bc16

undefined4 __cdecl FUN_0040bc16(int param_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 1;
    }
    if (*(int *)(&DAT_00428f60 + local_8 * 0x10 + param_1 * 0xe0) != 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}


// ==== FUN_0040bc74 @ 0040bc74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040bc74(int param_1)

{
  int iVar1;
  int local_1c [2];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FID_conflict__memcpy(&DAT_004298a0,&DAT_00428f60,0x8c0);
  local_10 = 0;
  do {
    if (9 < local_10) {
      if (param_1 == 0) {
        if ((((-1 < DAT_00412ba0) && (0 < (int)(&DAT_0042a2f0)[DAT_00412ba0 * 4])) &&
            ((DAT_00412a60 == 3 || (DAT_00412a60 == 4)))) &&
           (((iVar1 = FUN_0040bc16(0), iVar1 != 0 &&
             (iVar1 = FUN_0040a0c1(0,0xe,DAT_00412a60), iVar1 == 0)) &&
            (local_c = FUN_0040a6aa(0,0xe,DAT_00412a60), 0 < local_c)))) {
          _DAT_00429970 = (&DAT_0042a2f0)[DAT_00412ba0 * 4];
          DAT_00412ba0 = DAT_00412ba0 + -1;
        }
      }
      else if ((((-1 < DAT_00412ba0) && (0 < (int)(&DAT_0042a2f0)[DAT_00412ba0 * 4])) &&
               (((DAT_00412a60 == 3 || (DAT_00412a60 == 4)) &&
                (((DAT_00429030 == 0 && (iVar1 = FUN_0040a0c1(0,0xe,DAT_00412a60), iVar1 == 0)) &&
                 (local_c = FUN_0040a6aa(0,0xe,DAT_00412a60), 0 < local_c)))))) &&
              (iVar1 = MessageBoxA(DAT_00417308,s_Are_you_sure_to_insert_next_card_00412e14,
                                   s_Question_00412e08,0x24), iVar1 == 6)) {
        _DAT_00429970 = (&DAT_0042a2f0)[DAT_00412ba0 * 4];
        DAT_00412ba0 = DAT_00412ba0 + -1;
      }
      FID_conflict__memcpy(&DAT_00428f60,&DAT_004298a0,0x8c0);
      if (param_1 != 0) {
        FUN_0040a9e7();
        FUN_004094ee();
      }
      return 1;
    }
    for (local_14 = 0; local_14 < 0xe; local_14 = local_14 + 1) {
      if ((((0 < *(int *)(&DAT_00428f60 + local_14 * 0x10 + local_10 * 0xe0)) &&
           (*(int *)(&DAT_00428f60 + local_14 * 0x10 + local_10 * 0xe0) < 9)) &&
          (iVar1 = FUN_0040a0c1(local_10,local_14,DAT_00412a60), iVar1 == 0)) &&
         (local_c = FUN_0040a6aa(local_10,local_14,DAT_00412a60), 0 < local_c)) {
        FUN_0040b383(DAT_00412a60,&local_8,local_1c);
        if (((local_8 + local_14 == 0xe) || (local_8 + local_14 == -1)) ||
           ((local_10 + local_1c[0] == 10 ||
            ((local_10 + local_1c[0] == -1 ||
             (*(int *)(&DAT_00428f60 + (local_8 + local_14) * 0x10 + (local_10 + local_1c[0]) * 0xe0
                      ) != 0)))))) {
          return 0;
        }
        *(undefined4 *)
         (&DAT_004298a0 + (local_8 + local_14) * 0x10 + (local_10 + local_1c[0]) * 0xe0) =
             *(undefined4 *)(&DAT_00428f60 + local_14 * 0x10 + local_10 * 0xe0);
        *(undefined4 *)(&DAT_004298a0 + local_14 * 0x10 + local_10 * 0xe0) = 0;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


// ==== FUN_0040bfd5 @ 0040bfd5

void FUN_0040bfd5(void)

{
  undefined4 uVar1;
  int iVar2;
  LPCSTR pCVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  uint uVar8;
  int local_40;
  int local_3c;
  int local_38;
  int local_2c [9];
  int local_8;
  
  iVar2 = DAT_00412a60;
  local_38 = 0;
  if (((DAT_00412730 == 1) && (0 < DAT_00412024)) && (DAT_00412024 < 9)) {
    uVar8 = 0x9e0;
    puVar7 = &DAT_00427c40;
    pcVar6 = s_GLEVEL_00412e38;
    pCVar3 = FUN_00401700((uint *)s_LEVELT_00412e40,DAT_00412024,3);
    iVar4 = FUN_00405812(pCVar3,pcVar6,puVar7,uVar8);
    if (iVar4 != 0) {
      FID_conflict__memcpy(&DAT_00428f60,&DAT_00427d60,0x8c0);
      FID_conflict__memcpy(&DAT_0042a2f0,&DAT_00427cc0,0x8c0);
      DAT_00412a60 = iVar2;
      return;
    }
  }
  else if (((DAT_00412730 == 5) && (0 < DAT_00412024)) && (DAT_00412024 < 0xb)) {
    uVar8 = 0x9e0;
    puVar7 = &DAT_00427c40;
    pcVar6 = s_GLEVEL_00412e48;
    pCVar3 = FUN_00401700((uint *)s_LEVEL_00412e50,DAT_00412024,3);
    iVar4 = FUN_00405812(pCVar3,pcVar6,puVar7,uVar8);
    if (iVar4 != 0) {
      FID_conflict__memcpy(&DAT_00428f60,&DAT_00427d60,0x8c0);
      FID_conflict__memcpy(&DAT_0042a2f0,&DAT_00427cc0,0x8c0);
      DAT_00412a60 = iVar2;
      return;
    }
  }
  do {
    _memset(&DAT_00428f60,0,0x8c0);
    _memset(&DAT_0042a2f0,0,0xa0);
    _memset(local_2c,0,0x24);
    if ((DAT_00412730 == 1) || (DAT_00412730 == 2)) {
      iVar4 = FUN_00409467(8);
      for (local_3c = 0; local_3c < 8; local_3c = local_3c + 1) {
        uVar8 = iVar4 + local_3c >> 0x1f;
        (&DAT_0042a2f0)[local_3c * 4] =
             *(undefined4 *)
              (&DAT_00412710 + (((iVar4 + local_3c ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8) * 4);
      }
    }
    else if (DAT_00412730 == 3) {
      FID_conflict__memcpy(&DAT_00428628,&DAT_00412710,0x20);
      for (local_3c = 0; local_3c < 4; local_3c = local_3c + 1) {
        iVar4 = FUN_00409467(2);
        if (iVar4 == 1) {
          uVar1 = *(undefined4 *)(&DAT_00428628 + local_3c * 8);
          *(undefined4 *)(&DAT_00428628 + local_3c * 8) =
               *(undefined4 *)(&DAT_0042862c + local_3c * 8);
          *(undefined4 *)(&DAT_0042862c + local_3c * 8) = uVar1;
        }
      }
      iVar4 = FUN_00409467(8);
      for (local_3c = 0; local_3c < 8; local_3c = local_3c + 1) {
        uVar8 = iVar4 + local_3c >> 0x1f;
        (&DAT_0042a2f0)[local_3c * 4] =
             *(undefined4 *)
              (&DAT_00428628 + (((iVar4 + local_3c ^ uVar8) - uVar8 & 7 ^ uVar8) - uVar8) * 4);
      }
    }
    else {
      for (local_3c = 0; local_3c < 8; local_3c = local_3c + 1) {
        for (local_40 = 0; local_40 < 10000; local_40 = local_40 + 1) {
          iVar4 = FUN_00409467(8);
          iVar4 = iVar4 + 1;
          if (local_2c[iVar4] == 0) {
            local_2c[iVar4] = 1;
            (&DAT_0042a2f0)[local_3c * 4] = iVar4;
            break;
          }
        }
      }
      if ((&DAT_0042a2f0)[local_3c * 4] == 0) {
        for (local_40 = 1; local_40 < 9; local_40 = local_40 + 1) {
          if (local_2c[local_40] == 0) {
            local_2c[local_40] = 1;
            (&DAT_0042a2f0)[local_3c * 4] = local_40;
            break;
          }
        }
      }
    }
    iVar4 = FUN_00409467(10);
    if (8 - DAT_00412730 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 10;
    }
    iVar4 = FUN_00409467(10);
    if (10 - DAT_00412730 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 10;
    }
    iVar4 = FUN_00409467(10);
    if (5 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 0xb;
    }
    iVar4 = FUN_00409467(10);
    if (5 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 0xb;
    }
    iVar4 = FUN_00409467(10);
    if (DAT_00412730 + 2 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 9;
    }
    iVar4 = FUN_00409467(10);
    if (DAT_00412730 * 2 + 2 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(9);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 9;
    }
    iVar4 = FUN_00409467(10);
    if (5 < iVar4) {
      iVar4 = FUN_00409467(5);
      iVar5 = FUN_00409467(2);
      *(undefined4 *)(&DAT_00428f60 + (iVar4 + 2) * 0xe0 + (iVar5 + 2) * 0x10) = 0xc;
      iVar4 = FUN_00409467(5);
      iVar4 = iVar4 + 2;
      iVar5 = FUN_00409467(2);
      iVar5 = iVar5 + 9;
      if (*(int *)(&DAT_00428f60 + iVar4 * 0xe0 + iVar5 * 0x10) == 0xc) {
        *(undefined4 *)(&DAT_00428f60 + iVar4 * 0xe0 + iVar5 * 0x10) = 0;
      }
      else {
        *(undefined4 *)(&DAT_00428f60 + iVar4 * 0xe0 + iVar5 * 0x10) = 0xc;
      }
    }
    DAT_00412ba0 = 7;
    local_8 = 0;
    for (local_3c = 0; local_3c < 2000; local_3c = local_3c + 1) {
      iVar4 = FUN_00409467(8);
      DAT_00412a60 = iVar4 + 1;
      iVar4 = FUN_0040bc74(0);
      if (iVar4 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        local_8 = 0;
      }
      if (99 < local_8) break;
    }
    if (DAT_00412730 < 4) {
      iVar4 = DAT_00429030;
      if (DAT_00412ba0 < 0) goto joined_r0x0040c774;
    }
    else if ((((DAT_00412ba0 < 0) && (DAT_00429030 != DAT_0042a2f0)) &&
             (DAT_00429020 != DAT_0042a2f0)) && (iVar4 = DAT_00429100, DAT_00429110 != DAT_0042a2f0)
            ) {
joined_r0x0040c774:
      if (iVar4 != DAT_0042a2f0) {
        DAT_00412a60 = iVar2;
        return;
      }
    }
    local_38 = local_38 + 1;
    if (100 < local_38) {
      uVar8 = 0x9e0;
      puVar7 = &DAT_00427c40;
      pcVar6 = s_GLEVEL_00412e58;
      iVar5 = 3;
      iVar4 = FUN_00409467(10);
      pCVar3 = FUN_00401700((uint *)s_LEVEL_00412e60,iVar4 + 1,iVar5);
      iVar4 = FUN_00405812(pCVar3,pcVar6,puVar7,uVar8);
      if (iVar4 != 0) {
        FID_conflict__memcpy(&DAT_00428f60,&DAT_00427d60,0x8c0);
        FID_conflict__memcpy(&DAT_0042a2f0,&DAT_00427cc0,0x8c0);
        DAT_00412a60 = iVar2;
        return;
      }
    }
  } while( true );
}


// ==== FUN_0040c834 @ 0040c834

void __cdecl FUN_0040c834(int param_1)

{
  int local_c;
  int local_8;
  
  if ((param_1 != 0) && (DAT_00412030 != 0)) {
    FUN_00406977();
  }
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0xe; local_c = local_c + 1) {
      if ((8 < *(int *)(&DAT_00428f60 + local_c * 0x10 + local_8 * 0xe0)) && (DAT_00412034 != 0)) {
        FUN_00406602(*(int *)(&DAT_00428f60 + local_c * 0x10 + local_8 * 0xe0));
      }
    }
  }
  return;
}


// ==== FUN_0040c8f0 @ 0040c8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040c8f0(int param_1,int param_2)

{
  int iVar1;
  HDC hDC;
  
  if (DAT_00412a64 != 0) {
    FUN_0040dd7f();
    iVar1 = FUN_00409467(2);
    FUN_004020b5(iVar1 + 2);
  }
  hDC = GetDC((HWND)0x0);
  FUN_00401c2a(hDC,s_TABLEBMP_00412e68,DAT_004123e4,&DAT_00420aa0);
  ReleaseDC((HWND)0x0,hDC);
  DAT_004123b4 = 1;
  FUN_004023b2(6);
  DAT_00412a64 = 0;
  DAT_00412a6c = 0;
  DAT_00412730 = _DAT_0041202c;
  DAT_00412024 = _DAT_00412028;
  DAT_00412b7c = 8;
  DAT_00412b80 = 8;
  DAT_00412020 = 100;
  if (_DAT_0041202c == 1) {
    DAT_00412020 = 0;
  }
  FUN_004098f2();
  FUN_00409980();
  DAT_00412b9c = 1;
  FUN_0040bfd5();
  FID_conflict__memcpy(&DAT_00428660,&DAT_00428f60,0x8c0);
  FID_conflict__memcpy(&DAT_0042a250,&DAT_0042a2f0,0xa0);
  FUN_00409702();
  FUN_0040a9e7();
  if (param_1 != 0) {
    FUN_004094ee();
    FUN_0040c834(param_2);
  }
  DAT_0042983c = GetTickCount();
  return;
}


// ==== FUN_0040ca4b @ 0040ca4b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ca4b(void)

{
  HDC hDC;
  
  DAT_00412a64 = 0;
  DAT_00412a6c = 0;
  DAT_00412024 = DAT_00412024 + 1;
  if ((DAT_00412730 == 1) && (8 < DAT_00412024)) {
    _DAT_0041202c = 2;
    DAT_00412730 = 2;
    FUN_00406602(0xe);
    FUN_0040c8f0(1,0);
  }
  else {
    if ((DAT_00412730 == 5) && (10 < DAT_00412024)) {
      _DAT_0041202c = 4;
      DAT_00412730 = 4;
      FUN_00406602(0xd);
    }
    hDC = GetDC((HWND)0x0);
    FUN_00401c2a(hDC,s_TABLEBMP_00412e74,DAT_004123e4,&DAT_00420aa0);
    ReleaseDC((HWND)0x0,hDC);
    DAT_004123b4 = 1;
    FUN_004098f2();
    while ((1 < DAT_00412b84 && (DAT_00412020 < *(int *)(DAT_00412b84 * 4 + 0x412b88) * 8))) {
      DAT_00412b84 = DAT_00412b84 + -1;
    }
    if ((DAT_00412730 < 2) || (DAT_00412b8c * 8 <= DAT_00412020)) {
      FUN_004023b2(6);
      FUN_00409980();
      DAT_00412b7c = 8;
      DAT_00412b80 = 8;
      DAT_00412b9c = 1;
      FUN_0040bfd5();
      FID_conflict__memcpy(&DAT_00428660,&DAT_00428f60,0x8c0);
      FID_conflict__memcpy(&DAT_0042a250,&DAT_0042a2f0,0xa0);
      Sleep(1000);
      FUN_00409702();
      FUN_0040a9e7();
      FUN_004094ee();
      FUN_0040c834(0);
      DAT_0042983c = GetTickCount();
    }
    else {
      FUN_004095e6();
    }
  }
  return;
}


// ==== FUN_0040cc37 @ 0040cc37

void FUN_0040cc37(void)

{
  HDC hDC;
  
  hDC = GetDC((HWND)0x0);
  FUN_00401c2a(hDC,s_TABLEBMP_00412e80,DAT_004123e4,&DAT_00420aa0);
  ReleaseDC((HWND)0x0,hDC);
  DAT_004123b4 = 1;
  FUN_0040a9e7();
  FUN_004098f2();
  while ((1 < DAT_00412b84 && (DAT_00412020 < *(int *)(DAT_00412b84 * 4 + 0x412b88) * 8))) {
    DAT_00412b84 = DAT_00412b84 + -1;
  }
  if ((DAT_00412730 < 2) || (DAT_00412b8c * 8 <= DAT_00412020)) {
    FUN_00409980();
    DAT_00412b7c = 8;
    DAT_00412b80 = 8;
    DAT_00412b9c = 1;
    FID_conflict__memcpy(&DAT_00428f60,&DAT_00428660,0x8c0);
    FID_conflict__memcpy(&DAT_0042a2f0,&DAT_0042a250,0xa0);
    FUN_00409702();
    FUN_0040a9e7();
    FUN_004094ee();
  }
  else {
    FUN_004095e6();
  }
  return;
}


// ==== FUN_0040cd6c @ 0040cd6c

void __cdecl FUN_0040cd6c(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  switch(param_3) {
  case 0x65:
    if ((DAT_00412a6c == 0) && (DAT_00412a64 == 0)) {
      IVar1 = FUN_0040685c();
      if (IVar1 != 1) {
        return;
      }
      if (((DAT_00412020 < 0x65) || (iVar2 = FUN_00401348(DAT_00412020,&local_8), iVar2 == 0)) ||
         (9 < local_8)) {
        FUN_004023b2(3);
      }
      else {
        FUN_004023b2(1);
        if (DAT_0041203c != 0) {
          FUN_004069e2();
        }
        iVar2 = FUN_004013e5(DAT_00412020);
        if (0 < iVar2) {
          DAT_00412b78 = local_8;
          FUN_00406a31();
        }
        FUN_00401529();
      }
    }
    _memset(&DAT_00429840,0,0x50);
    FUN_0040c8f0(1,1);
    break;
  case 0x66:
    DAT_00412b78 = -1;
    FUN_00406a31();
    break;
  case 0x67:
    SendMessageA(DAT_00417308,0x10,0,0);
    break;
  case 0x68:
    FUN_00409f1e();
    break;
  case 0x79:
    FUN_0040ca4b();
    break;
  case 0xc9:
    if ((DAT_00412a64 == 0) && (DAT_00412a6c == 0)) {
      FUN_0040cc37();
    }
    else {
      SendMessageA(DAT_00417308,0x111,0x65,0);
    }
    break;
  case 0x12e:
    FUN_004068d0();
    break;
  case 0x12f:
    WinHelpA(DAT_00417308,s_MUDDLE_HLP_00412748,0xb,0);
    break;
  case 0x130:
    FUN_00406977();
    break;
  case 0x131:
    DAT_00412034 = (uint)(DAT_00412034 == 0);
    FUN_00409498();
  }
  return;
}


// ==== FUN_0040d05e @ 0040d05e

void FUN_0040d05e(void)

{
  int iVar1;
  int local_10;
  int local_c;
  
  if (((DAT_00412a68 != 0) && (FUN_00402294(), iVar1 = DAT_0042a2f0, DAT_00412a64 == 0)) &&
     (DAT_00412a6c == 0)) {
    DAT_00412ba4 = DAT_00412ba4 + 1;
    if (0xe < DAT_00412ba4) {
      DAT_00412ba4 = 0;
    }
    if (((DAT_00412ba4 == 0) || (DAT_00412ba4 == 10)) && ((0 < DAT_0042a2f0 && (DAT_0042a2f0 < 9))))
    {
      if (DAT_00412ba4 == 0) {
        FUN_00403d90((int *)&DAT_00421430,0);
      }
      else {
        FUN_00403d90((int *)&DAT_00421430,1);
      }
      for (local_c = 0; local_c < 10; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 0xe; local_10 = local_10 + 1) {
          if (*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) == iVar1) {
            if (0xff < *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10)) {
              return;
            }
            if (*(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) < 0x28) {
              return;
            }
            if (DAT_00412ba4 == 0) {
              if (*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) < 5) {
                FUN_0040519a(&DAT_004181a0,
                             (int)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                            );
                FUN_00403ff9((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c));
                iVar1 = FUN_0040a36a(local_c,local_10,DAT_00412a60);
                FUN_00403d90((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c),
                             *(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) * 5 + -5 +
                             iVar1);
                FUN_00403f39((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c),local_10 * 0x19 + 0xe2,local_c * 0x23 + 0x2c,1);
              }
              else if (*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) < 9) {
                FUN_0040519a(&DAT_004183c4,
                             (int)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                            );
                FUN_00403ff9((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c));
                iVar1 = FUN_0040a36a(local_c,local_10,DAT_00412a60);
                FUN_00403d90((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c),
                             *(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) * 5 + -0x19
                             + iVar1);
                FUN_00403f39((int *)(&DAT_00420da8 +
                                    *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) *
                                    0x2c),local_10 * 0x19 + 0xe2,local_c * 0x23 + 0x2c,1);
              }
            }
            else if (*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) < 5) {
              FUN_0040519a(&DAT_00418a30,
                           (int)(&DAT_00420da8 +
                                *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c));
              FUN_00403ff9((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                          );
              iVar1 = FUN_0040a36a(local_c,local_10,DAT_00412a60);
              FUN_00403d90((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                           ,*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) * 5 + -5 +
                            iVar1);
              FUN_00403f39((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                           ,local_10 * 0x19 + 0xe2,local_c * 0x23 + 0x2c,1);
            }
            else if (*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) < 9) {
              FUN_0040519a(&DAT_00418c54,
                           (int)(&DAT_00420da8 +
                                *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c));
              FUN_00403ff9((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                          );
              iVar1 = FUN_0040a36a(local_c,local_10,DAT_00412a60);
              FUN_00403d90((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                           ,*(int *)(&DAT_00428f60 + local_c * 0xe0 + local_10 * 0x10) * 5 + -0x19 +
                            iVar1);
              FUN_00403f39((int *)(&DAT_00420da8 +
                                  *(int *)(&DAT_00428f64 + local_c * 0xe0 + local_10 * 0x10) * 0x2c)
                           ,local_10 * 0x19 + 0xe2,local_c * 0x23 + 0x2c,1);
            }
            FUN_004094ee();
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_0040d74d @ 0040d74d

UINT FUN_0040d74d(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  uint uVar1;
  UINT UVar2;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      FUN_004017c9(1);
      SelectPalette(DAT_004172c0,DAT_00412180,0);
      RealizePalette(DAT_004172c0);
      DAT_004123b4 = 1;
      FUN_00403755();
      FUN_00401829(1);
      return 0;
    }
    if (param_2 == 1) {
      FUN_00406400(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_0040535d();
      FUN_004024cf();
      FUN_00406443(param_1);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      FUN_00409ea5(param_1,0x1c,(int)param_3);
      return 0;
    }
    if (param_2 == 0x10) {
      UVar2 = FUN_00409fc6();
      return UVar2;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(400);
      GdiFlush();
      Sleep(400);
      GdiFlush();
      Sleep(100);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00428f48;
      *(undefined4 *)(param_4 + 0xc) = DAT_00428f58;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_00417308,6);
        return 0;
      }
      if ((DAT_00412a64 == 0) && (DAT_00412a6c == 0)) {
        uVar1 = GetMessageTime();
        if (uVar1 < DAT_0042983c) {
          DAT_0042983c = GetTickCount();
          return 0;
        }
        switch(param_3) {
        case (HWND)0x9:
          FUN_0040b42d(1);
          break;
        case (HWND)0x20:
          FUN_0040b42d(0);
          break;
        case (HWND)0x25:
          if (DAT_00412a60 == 7) {
            DAT_00412a60 = 8;
          }
          else if (DAT_00412a60 == 8) {
            DAT_00412a60 = 7;
          }
          else {
            DAT_00412a60 = DAT_00412a54;
          }
          DAT_00412a54 = DAT_00412a60;
          FUN_0040b2b5();
          break;
        case (HWND)0x26:
          if (DAT_00412a60 == 1) {
            DAT_00412a60 = 2;
          }
          else if (DAT_00412a60 == 2) {
            DAT_00412a60 = 1;
          }
          else {
            DAT_00412a60 = DAT_00412a50;
          }
          DAT_00412a50 = DAT_00412a60;
          FUN_0040b2b5();
          break;
        case (HWND)0x27:
          if (DAT_00412a60 == 3) {
            DAT_00412a60 = 4;
          }
          else if (DAT_00412a60 == 4) {
            DAT_00412a60 = 3;
          }
          else {
            DAT_00412a60 = DAT_00412a58;
          }
          DAT_00412a58 = DAT_00412a60;
          FUN_0040b2b5();
          break;
        case (HWND)0x28:
          if (DAT_00412a60 == 5) {
            DAT_00412a60 = 6;
          }
          else if (DAT_00412a60 == 6) {
            DAT_00412a60 = 5;
          }
          else {
            DAT_00412a60 = DAT_00412a5c;
          }
          DAT_00412a5c = DAT_00412a60;
          FUN_0040b2b5();
        }
        return 0;
      }
      PostMessageA(DAT_00417308,0x111,0x65,0);
      return 0;
    }
    if ((param_2 == 0x86) && (param_3 != (HWND)0x0)) {
      InvalidateRect(DAT_00417308,(RECT *)0x0,0);
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if ((DAT_00412a64 == 0) && (DAT_00412a6c == 0)) {
        uVar1 = GetMessageTime();
        if (uVar1 < DAT_0042983c) {
          DAT_0042983c = GetTickCount();
          return 0;
        }
        FUN_00409a42(param_4 & 0xffff,DAT_004123ac - (param_4 >> 0x10));
        return 0;
      }
      PostMessageA(DAT_00417308,0x111,0x65,0);
      return 0;
    }
    if (param_2 == 0x111) {
      FUN_0040cd6c(param_1,0x111,(short)param_3);
      return 0;
    }
    if (param_2 == 0x113) {
      FUN_0040d05e();
      return 0;
    }
  }
  else {
    if (param_2 == 0x204) {
      if ((DAT_00412a64 == 0) && (DAT_00412a6c == 0)) {
        uVar1 = GetMessageTime();
        if (uVar1 < DAT_0042983c) {
          DAT_0042983c = GetTickCount();
          return 0;
        }
        FUN_00409e52((param_4 & 0xffff) - 0xd6,(DAT_004123ac - (param_4 >> 0x10)) + -0x1b);
        return 0;
      }
      PostMessageA(DAT_00417308,0x111,0x65,0);
      return 0;
    }
    if ((param_2 == 0x30f) || ((param_2 == 0x311 && (param_3 != DAT_00417308)))) {
      UVar2 = FUN_0040957f();
      return UVar2;
    }
  }
  UVar2 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar2;
}


// ==== FUN_0040dd7f @ 0040dd7f

void FUN_0040dd7f(void)

{
  int local_8;
  
  FUN_0040495b(s_ROUNDCARDSPR_00412e8c,(short *)&DAT_004181a0);
  FUN_0040495b(s_SQUARECARDSPR_00412e9c,(short *)&DAT_004183c4);
  FUN_0040495b(s_FEATURESPR_00412eac,(short *)&DAT_004185e8);
  FUN_0040495b(s_SIGNSPR_00412eb8,(short *)&DAT_0041880c);
  FUN_0040495b(s_ARROWSPR_00412ec0,(short *)&DAT_004194e4);
  FUN_0040519a(&DAT_004194e4,0x421430);
  FUN_00403f39((int *)&DAT_00421430,0x23e,DAT_004123ac + -0x167,1);
  FUN_00403d90((int *)&DAT_00421430,0);
  FUN_0040495b(s_BROUNDCARDSPR_00412ecc,(short *)&DAT_00418a30);
  FUN_0040495b(s_BSQUARECARDSPR_00412edc,(short *)&DAT_00418c54);
  FUN_0040495b(s_DIGITSPR_00412eec,(short *)&DAT_00418e78);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040519a(&DAT_00418e78,(int)(&DAT_00420da8 + (local_8 + 0x10) * 0x2c));
    FUN_00403f39((int *)(&DAT_00420da8 + (local_8 + 0x10) * 0x2c),local_8 * 0x10 + 0x80,
                 DAT_004123ac + -0x17c,1);
    FUN_00403d90((int *)(&DAT_00420da8 + (local_8 + 0x10) * 0x2c),0);
  }
  FUN_0040495b(s_PORTRAITSPR_00412ef8,(short *)&DAT_0041909c);
  FUN_0040519a(&DAT_0041909c,0x421144);
  FUN_00403f39((int *)&DAT_00421144,0x60,DAT_004123ac + -0x5a,-1);
  FUN_00403d90((int *)&DAT_00421144,0);
  FUN_0040495b(s_COINSPR_00412f04,(short *)&DAT_004192c0);
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    FUN_0040519a(&DAT_004192c0,(int)(&DAT_00420da8 + (local_8 + 0x16) * 0x2c));
  }
  FUN_00409702();
  return;
}


// ==== FUN_0040e011 @ 0040e011

int __cdecl FUN_0040e011(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0040e032 @ 0040e032

int __cdecl FUN_0040e032(int param_1)

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


// ==== FUN_0040e06d @ 0040e06d

undefined4 FUN_0040e06d(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(s_MuddleWin_00412738,(LPCSTR)0x0);
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


// ==== FUN_0040e0e9 @ 0040e0e9

bool __cdecl FUN_0040e0e9(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040e13f @ 0040e13f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_0040e13f(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

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
  WNDCLASSA local_cc;
  DWORD local_a4;
  CHAR local_a0;
  undefined4 local_9f;
  tagMSG local_20;
  
  local_a0 = DAT_00412f0c;
  puVar10 = &local_9f;
  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  *(undefined1 *)((int)puVar10 + 2) = 0;
  DAT_0042a190 = param_1;
  iVar9 = FUN_0040e06d();
  if (iVar9 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_MuddleGameMtx_00412f10);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_20.wParam = 0;
    }
    else {
      bVar1 = FUN_0040e0e9(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_20.wParam = 0;
      }
      else {
        pHVar4 = GetDC((HWND)0x0);
        iVar9 = GetDeviceCaps(pHVar4,0xc);
        if (iVar9 < 8) {
          ReleaseDC((HWND)0x0,pHVar4);
          local_20.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,pHVar4);
          FUN_00405f4d();
          FUN_00405fe7((uint *)s_MUDDLE_DLL_00412848);
          FUN_00406195((uint *)s_MUDDLE1_DLL_00412948);
          FUN_00405f65((uint *)s_MSPuzzle_dat_00412070);
          FUN_00406195((uint *)s_MUDDLE_HLP_00412748);
          FUN_00405d7a();
          FUN_00405d94(DAT_0042a190);
          FUN_00405dd3(s_MUDDLE1_DLL_00412948);
          FUN_00405dd3(s_MUDDLE_DLL_00412848);
          FUN_00405cb0(DAT_0042a190,100,&local_a0,0x78);
          FUN_00409448();
          FUN_004010b8();
          FUN_004026e6();
          _DAT_00417310 = 0x300;
          _DAT_00417312 = 0x100;
          DAT_004123a8 = 0x274;
          DAT_004123ac = 0x194;
          iVar9 = FUN_00402a6e();
          if (iVar9 == 0) {
            FUN_004024cf();
            local_20.wParam = 0;
          }
          else {
            pHVar4 = GetDC((HWND)0x0);
            iVar9 = FUN_00401c2a(pHVar4,s_TITLEBMP_00412f20,DAT_004123e4,&DAT_00420aa0);
            if (iVar9 == 0) {
              FUN_004024cf();
              local_20.wParam = 0;
            }
            else {
              DAT_00429820 = FUN_00401b80(s_GAMEOVERBMP_00412f2c);
              DAT_00428f20 = FUN_00401b80(s_s_h_0000_00412f38);
              DAT_00428f24 = FUN_00401b80(s_s_h_0001_00412f44);
              DAT_0042a1a0 = FUN_00401b80(s_s_h_0002_00412f50);
              DAT_0042a1a4 = FUN_00401b80(s_s_h_0003_00412f5c);
              DAT_00427c38 = FUN_00401b80(s_s_h_0004_00412f68);
              DAT_00427c3c = FUN_00401b80(s_s_h_0005_00412f74);
              DAT_00428f40 = FUN_00401b80(s_s_h_0006_00412f80);
              DAT_00428f44 = FUN_00401b80(s_s_h_0007_00412f8c);
              DAT_0042a248 = FUN_00401b80(s_s_v_0000_00412f98);
              DAT_0042a24c = FUN_00401b80(s_s_v_0001_00412fa4);
              DAT_00428650 = FUN_00401b80(s_s_v_0002_00412fb0);
              DAT_00428654 = FUN_00401b80(s_s_v_0003_00412fbc);
              DAT_00428f30 = FUN_00401b80(s_s_v_0004_00412fc8);
              DAT_00428f34 = FUN_00401b80(s_s_v_0005_00412fd4);
              DAT_00429830 = FUN_00401b80(s_s_v_0006_00412fe0);
              DAT_00429834 = FUN_00401b80(s_s_v_0007_00412fec);
              DAT_0042a174 = FUN_00401b80(s_f_n_0000_00412ff8);
              _DAT_0042a178 = FUN_00401b80(s_f_n_0001_00413004);
              _DAT_0042a17c = FUN_00401b80(s_f_n_0002_00413010);
              _DAT_0042a180 = FUN_00401b80(s_f_n_0003_0041301c);
              ReleaseDC((HWND)0x0,pHVar4);
              DAT_004123b8 = 1;
              DAT_004123bc = &DAT_00420aa0;
              if (param_2 == 0) {
                local_cc.style = 0;
                local_cc.lpfnWndProc = FUN_0040d74d;
                local_cc.cbClsExtra = 0;
                local_cc.cbWndExtra = 0;
                local_cc.lpszMenuName = (LPCSTR)0x0;
                local_cc.lpszClassName = (LPCSTR)0x0;
                local_cc.hInstance = DAT_0042a190;
                local_cc.hIcon = FUN_00405bed(DAT_0042a190,s_MAINICON_00413028);
                local_cc.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
                local_cc.hbrBackground = GetStockObject(5);
                local_cc.lpszClassName = s_MuddleWin_00412738;
                AVar2 = RegisterClassA(&local_cc);
                if (AVar2 == 0) {
                  return 0xff;
                }
              }
              InitCommonControls();
              DAT_00428f28 = FUN_00405b8b(DAT_0042a190,s_ACCELERATORS_1_00413034);
              DAT_00428624 = FUN_00405c4e(DAT_0042a190,s_MainMenu_00413044);
              if ((DAT_00428f28 == (HACCEL)0x0) || (DAT_00429820 == (HGLOBAL)0x0)) {
                FUN_004024cf();
                local_20.wParam = 0;
              }
              else {
                local_a4 = GetVersion();
                if ((byte)local_a4 < 4) {
                  iVar9 = GetSystemMetrics(5);
                  DAT_00428f48 = iVar9 * 2 + DAT_004123a8;
                  iVar9 = GetSystemMetrics(6);
                  iVar5 = GetSystemMetrics(4);
                  iVar6 = GetSystemMetrics(0xf);
                  DAT_00428f58 = iVar9 * 2 + iVar5 + iVar6 + DAT_004123ac;
                  pvVar13 = (LPVOID)0x0;
                  pHVar11 = (HWND)0x0;
                  iVar9 = DAT_00428f48;
                  iVar5 = DAT_00428f58;
                  pHVar12 = DAT_00428624;
                  iVar6 = FUN_0040e032(DAT_00428f58);
                  iVar7 = FUN_0040e011(DAT_00428f48);
                  DAT_00417308 = CreateWindowExA(0,s_MuddleWin_00412738,&local_a0,0xca0000,iVar7,
                                                 iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,pvVar13);
                }
                else {
                  iVar9 = GetSystemMetrics(7);
                  DAT_00428f48 = iVar9 * 2 + DAT_004123a8;
                  iVar9 = GetSystemMetrics(8);
                  iVar5 = GetSystemMetrics(4);
                  iVar6 = GetSystemMetrics(0xf);
                  DAT_00428f58 = iVar9 * 2 + iVar5 + iVar6 + DAT_004123ac;
                  pvVar13 = (LPVOID)0x0;
                  pHVar11 = (HWND)0x0;
                  iVar9 = DAT_00428f48;
                  iVar5 = DAT_00428f58;
                  pHVar12 = DAT_00428624;
                  iVar6 = FUN_0040e032(DAT_00428f58);
                  iVar7 = FUN_0040e011(DAT_00428f48);
                  DAT_00417308 = CreateWindowExA(0x100,s_MuddleWin_00412738,&local_a0,0xca0000,iVar7
                                                 ,iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,pvVar13)
                  ;
                }
                ShowWindow(DAT_00417308,param_4);
                FUN_004053b3();
                UpdateWindow(DAT_00417308);
                SetTimer(DAT_00417308,1,0x32,(TIMERPROC)0x0);
                FUN_00409498();
                while (BVar8 = GetMessageA(&local_20,(HWND)0x0,0,0), BVar8 != 0) {
                  iVar9 = TranslateAcceleratorA(DAT_00417308,DAT_00428f28,&local_20);
                  if (iVar9 == 0) {
                    TranslateMessage(&local_20);
                    DispatchMessageA(&local_20);
                  }
                }
                FUN_0040535d();
                FUN_004024cf();
              }
            }
          }
        }
      }
    }
  }
  else {
    local_20.wParam = 0;
  }
  return local_20.wParam;
}


// ==== FID_conflict:_memcpy @ 0040e7f0

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
switchD_0040e8b9_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0040e8b9_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0040e8b9_caseD_3:
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
        goto switchD_0040e8b9_caseD_1;
      case 2:
        goto switchD_0040e8b9_caseD_2;
      case 3:
        goto switchD_0040e8b9_caseD_3;
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
switchD_0040e820_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0040e820_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0040e820_caseD_3:
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
      goto switchD_0040e820_caseD_1;
    case 2:
      goto switchD_0040e820_caseD_2;
    case 3:
      goto switchD_0040e820_caseD_3;
    }
  }
  return _Dst;
}


// ==== _memset @ 0040e940

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


// ==== _strncmp @ 0040e9a0

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


// ==== _strlen @ 0040e9e0

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0040ea00;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0040ea33:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0040ea00:
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
  goto LAB_0040ea33;
}


// ==== FUN_0040ea60 @ 0040ea60

uint * __cdecl FUN_0040ea60(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0040eb48;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0040eb48:
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


// ==== FUN_0040ea70 @ 0040ea70

uint * __cdecl FUN_0040ea70(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0040ea8c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0040eabf;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0040eadb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0040ea8c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0040eadb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0040eadb;
    }
  }
LAB_0040eabf:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0040eadb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0040eb48:
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
    if (bVar1 == 0) goto LAB_0040eb48;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _malloc @ 0040eb50

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00413068);
  return pvVar1;
}


// ==== __nh_malloc @ 0040eb70

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


// ==== __heap_alloc @ 0040ebc0

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_0041388c) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0042a5b0,0,dwBytes);
  return pvVar2;
}


// ==== _free @ 0040ec00

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
    HeapFree(DAT_0042a5b0,0,_Memory);
  }
  return;
}


// ==== _qsort @ 0040ec50

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
LAB_0040ec8f:
  uVar1 = (uint)((int)local_f8 - (int)_Base) / _SizeOfElements + 1;
  if (8 < uVar1) {
    swap((undefined1 *)((int)_Base + (uVar1 >> 1) * _SizeOfElements),_Base,_SizeOfElements);
    puVar3 = local_f8 + _SizeOfElements;
    puVar4 = _Base;
LAB_0040ecec:
    puVar4 = puVar4 + _SizeOfElements;
    if (puVar4 <= local_f8) goto code_r0x0040ecf4;
    goto LAB_0040ed04;
  }
  shortsort(_Base,local_f8,_SizeOfElements,_PtFuncCompare);
  goto LAB_0040ecb6;
code_r0x0040ecf4:
  iVar2 = (*_PtFuncCompare)(puVar4,_Base);
  if (iVar2 < 1) goto LAB_0040ecec;
LAB_0040ed04:
  do {
    puVar3 = puVar3 + -_SizeOfElements;
    if (puVar3 <= _Base) break;
    iVar2 = (*_PtFuncCompare)(puVar3,_Base);
  } while (-1 < iVar2);
  if (puVar4 <= puVar3) {
    swap(puVar4,puVar3,_SizeOfElements);
    goto LAB_0040ecec;
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
      goto LAB_0040ec8f;
    }
  }
  else {
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      auStack_f0[local_f4] = _Base;
      aiStack_78[local_f4] = (int)puVar3 - _SizeOfElements;
      local_f4 = local_f4 + 1;
    }
    _Base = puVar4;
    if (puVar4 < local_f8) goto LAB_0040ec8f;
  }
LAB_0040ecb6:
  local_f4 = local_f4 + -1;
  if (local_f4 < 0) {
    return;
  }
  local_f8 = (undefined1 *)aiStack_78[local_f4];
  _Base = (undefined1 *)auStack_f0[local_f4];
  goto LAB_0040ec8f;
}


// ==== shortsort @ 0040edb0

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


// ==== swap @ 0040ee10

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


// ==== FUN_0040ee40 @ 0040ee40

int __cdecl FUN_0040ee40(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== _strcmp @ 0040ee50

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
      if (bVar4 != *_Str2) goto LAB_0040ee94;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0040ee60;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0040ee94;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0040ee94;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0040ee60:
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
LAB_0040ee94:
  return (uint)bVar5 * -2 + 1;
}


// ==== FUN_0040eee0 @ 0040eee0

void __cdecl FUN_0040eee0(undefined4 param_1)

{
  DAT_00413050 = param_1;
  return;
}


// ==== _rand @ 0040eef0

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00413050 = DAT_00413050 * 0x343fd + 0x269ec3;
  return (DAT_00413050 & 0x7fff0000) >> 0x10;
}


// ==== entry @ 0040ef20

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
  puStack_c = &DAT_00411000;
  puStack_10 = &LAB_00410690;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_004138a8 = DVar2 >> 8 & 0xff;
  DAT_0041389c = DVar2 >> 0x10;
  _DAT_004138a4 = DVar2 & 0xff;
  _DAT_004138a0 = _DAT_004138a4 * 0x100 + _DAT_004138a8;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0042a5b4 = (byte *)GetCommandLineA();
  DAT_00413054 = ___crtGetEnvironmentStringsA();
  if ((DAT_00413054 == (LPVOID)0x0) || (DAT_0042a5b4 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0042a5b4;
  pbVar6 = DAT_0042a5b4;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_0042a5b4 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_0040f025;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_0040f025:
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
  _Code = FUN_0040e13f(pHVar5,iVar3,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0040f0c0

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00413060 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_0041305c)(0xff);
  return;
}


// ==== __callnewh @ 0040f0f0

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0042a394 != (code *)0x0) {
    iVar1 = (*DAT_0042a394)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __heap_init @ 0040f120

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0042a5b0 = HeapCreate(1,0x1000,0);
  if (DAT_0042a5b0 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0042a5b0);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 0040f160

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
  
  if (DAT_00413880 == 0) {
    lpMem = &PTR_LOOP_00413070;
  }
  else {
    lpMem = HeapAlloc(DAT_0042a5b0,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00413070) {
        if (PTR_LOOP_00413070 == (undefined *)0x0) {
          PTR_LOOP_00413070 = (undefined *)&PTR_LOOP_00413070;
        }
        if (PTR_LOOP_00413074 == (undefined *)0x0) {
          PTR_LOOP_00413074 = (undefined *)&PTR_LOOP_00413070;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00413070;
        lpMem[1] = PTR_LOOP_00413074;
        PTR_LOOP_00413074 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00413070) {
    HeapFree(DAT_0042a5b0,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 0040f2d0

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00413884 == param_1) {
    PTR_LOOP_00413884 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00413070) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0042a5b0,0,param_1);
    return;
  }
  DAT_00413880 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 0040f330

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
  
  ppuVar4 = (undefined **)PTR_LOOP_00413074;
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
            DAT_00413888 = DAT_00413888 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_00413074) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 0040f410

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00413070;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00413070) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 0040f470

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00413888 = DAT_00413888 + 1, DAT_00413888 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 0040f4c0

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
  
  piVar12 = (int *)PTR_LOOP_00413884;
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
              PTR_LOOP_00413884 = (undefined *)piVar12;
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
              PTR_LOOP_00413884 = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_00413884 != piVar12);
  ppuVar11 = &PTR_LOOP_00413070;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00413070) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00413884 = (undefined *)ppuVar11;
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
  PTR_LOOP_00413884 = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 0040f740

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


// ==== __cinit @ 0040f8c0

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_0042a5ac != (code *)0x0) {
    (*DAT_0042a5ac)();
  }
  __initterm((undefined4 *)&DAT_00412008,(undefined4 *)&DAT_0041200c);
  iVar1 = __initterm((undefined4 *)&DAT_00412000,(undefined4 *)&DAT_00412004);
  return iVar1;
}


// ==== _exit @ 0040f8f0

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0040f910

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0040f930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_004138d8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004138d4 = 1;
  DAT_004138d0 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0042a5a8 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0042a5a4 + -4), DAT_0042a5a8 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0042a5a8 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00412010,(undefined4 *)&DAT_00412014);
  }
  __initterm((undefined4 *)&DAT_00412018,(undefined4 *)&DAT_0041201c);
  if (param_3 == 0) {
    DAT_004138d8 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0040f9e0

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


// ==== __global_unwind2 @ 0040fa00

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x40fa18,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0040fa42

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
  puStack_18 = &LAB_0040fa20;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0040fad6();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_0040fad6 @ 0040fad6

void FUN_0040fad6(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004138e4 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004138e0 = in_EAX;
  DAT_004138e8 = unaff_EBP;
  return;
}


// ==== __ismbblead @ 0040fc80

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 0040fca0

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00413988 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00413c4a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 0040fce0

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
  cVar1 = *DAT_00413054;
  pcVar7 = DAT_00413054;
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
  _DAT_004138b8 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00413054;
  pcVar7 = DAT_00413054;
  do {
    if (cVar1 == '\0') {
      _free(DAT_00413054);
      DAT_00413054 = (char *)0x0;
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


// ==== __setargv @ 0040fdd0

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0042a398,0x104);
  _DAT_004138c8 = &DAT_0042a398;
  pbVar2 = &DAT_0042a398;
  if (*DAT_0042a5b4 != 0) {
    pbVar2 = DAT_0042a5b4;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_004138b0 = puVar1;
  _DAT_004138ac = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 0040fe70

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
      if (((*(byte *)((int)&DAT_00413988 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00413988 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_0040fee0;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_0040fee0:
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
          if ((*(byte *)((int)&DAT_00413988 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00410011;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00413988 + bVar1 + 1) & 4) != 0) {
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
LAB_00410011:
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


// ==== ___crtGetEnvironmentStringsA @ 00410050

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
  if (DAT_00413980 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00413980 = 2;
    }
    else {
      DAT_00413980 = 1;
    }
  }
  if (DAT_00413980 != 1) {
    if (DAT_00413980 != 2) {
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


// ==== __setmbcp @ 004101e0

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
  if (CodePage == DAT_00413a8c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00413ab0;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00413988;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00413ac0 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00413aa8)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00413988 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00413a8c = CodePage;
      _DAT_00413a90 = _CPtoLCID(CodePage);
      DAT_00413a98 = *(undefined4 *)(&DAT_00413ab4 + local_18 * 0x30);
      DAT_00413a9c = *(undefined4 *)(&DAT_00413ab8 + local_18 * 0x30);
      DAT_00413aa0 = *(undefined4 *)(local_18 * 0x30 + 0x413abc);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00413ba0);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00413988;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00413a90 = 0;
      DAT_00413a8c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00413988 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00413988 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00413a8c = CodePage;
      _DAT_00413a90 = _CPtoLCID(CodePage);
    }
    DAT_00413a98 = 0;
    DAT_00413a9c = 0;
    DAT_00413aa0 = 0;
    return 0;
  }
  if (DAT_00413aa4 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 004103c0

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00413aa4 = 1;
                    /* WARNING: Could not recover jumptable at 0x004103dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00413aa4 = 1;
                    /* WARNING: Could not recover jumptable at 0x004103f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00413e68;
  }
  DAT_00413aa4 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00410410

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


// ==== setSBCS @ 00410470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00413988;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00413a98 = 0;
  DAT_00413a8c = 0;
  _DAT_00413a90 = 0;
  DAT_00413a9c = 0;
  DAT_00413aa0 = 0;
  return;
}


// ==== ___initmbctable @ 004104a0

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 004104b0

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
  DAT_0042a5a0 = 0x20;
  DAT_0042a4a0 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0042a4a0 + 0x40);
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
    if ((int)DAT_0042a5a0 < (int)UVar7) {
      piVar4 = &DAT_0042a4a4;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0042a5a0;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0042a5a0 = DAT_0042a5a0 + 0x20;
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
      } while ((int)DAT_0042a5a0 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0042a4a0 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0042a4a0 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0042a5a0);
  return UVar7;
}


// ==== FUN_0041074d @ 0041074d

void FUN_0041074d(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 00410770

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00413060 == 1) || ((DAT_00413060 == 0 && (DAT_00413064 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00413c38 != (code *)0x0) {
      (*DAT_00413c38)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 004107b0

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
  piVar2 = &DAT_00413ba8;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00413c38);
  if ((&DAT_00413ba8)[iVar4 * 2] == param_1) {
    if ((DAT_00413060 == 1) || ((DAT_00413060 == 0 && (DAT_00413064 == 1)))) {
      if ((DAT_0042a4a0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0042a4a0 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x413bac);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x413bac);
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


// ==== ___crtMessageBoxA @ 004109b0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00413e6c != (FARPROC)0x0) {
LAB_004109ff:
    if (DAT_00413e70 != (FARPROC)0x0) {
      iVar1 = (*DAT_00413e70)();
    }
    if ((iVar1 != 0) && (DAT_00413e74 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00413e74)(iVar1);
    }
    iVar1 = (*DAT_00413e6c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00413e6c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00413e6c != (FARPROC)0x0) {
      DAT_00413e70 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00413e74 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_004109ff;
    }
  }
  return 0;
}


// ==== _strncpy @ 00410a50

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
        goto joined_r0x00410a8e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00410acb;
        goto LAB_00410b39;
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
joined_r0x00410b35:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00410b39:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00410acb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00410b35;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00410b35;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00410b35;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00410a8e:
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
LAB_00410acb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


