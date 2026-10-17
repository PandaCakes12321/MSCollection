// ==== FUN_00401030 @ 00401030

undefined4 FUN_00401030(HINSTANCE param_1)

{
  bool bVar1;
  ATOM AVar2;
  HWND hWnd;
  BOOL BVar3;
  undefined4 uVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  tagMSG local_41c;
  CHAR local_400 [1024];
  
  hWnd = FindWindowA(s_MockbaLauncherWindow_0040b040,(LPCSTR)0x0);
  if (hWnd == (HWND)0x0) {
    DAT_0040b030 = param_1;
    iVar5 = FUN_00401cb0();
    if (iVar5 == 0) {
      uVar4 = 5;
    }
    else {
      LoadStringA(DAT_0040b034,10000,DAT_0040ea24,0x400);
      iVar5 = FUN_00401a20();
      if ((iVar5 == 0) || (DAT_0040b058 == 0)) {
        LoadStringA(DAT_0040b034,0x2711,local_400,0x400);
        MessageBoxA((HWND)0x0,local_400,DAT_0040ea24,0x30);
        uVar4 = 4;
      }
      else {
        bVar1 = FUN_004017f0();
        if ((CONCAT31(extraout_var,bVar1) != 0) || (DAT_0040b05c = 0, DAT_0040b058 == 1)) {
          DAT_0040b05c = 1;
          DAT_0040b058 = -1;
        }
        FUN_00401830(0x40b070);
        AVar2 = FUN_004011d0(DAT_0040b030);
        if (CONCAT22(extraout_var_00,AVar2) == 0) {
          uVar4 = 2;
        }
        else {
          iVar5 = FUN_00401260(DAT_0040b030);
          if (iVar5 == 0) {
            uVar4 = 3;
          }
          else {
            iVar5 = GetMessageA(&local_41c,(HWND)0x0,0,0);
            while (iVar5 != 0) {
              TranslateMessage(&local_41c);
              DispatchMessageA(&local_41c);
              iVar5 = GetMessageA(&local_41c,(HWND)0x0,0,0);
            }
            UnregisterClassA(s_MockbaLauncherWindow_0040b040,DAT_0040b030);
            uVar4 = 0;
          }
        }
      }
    }
  }
  else {
    BVar3 = IsIconic(hWnd);
    if (BVar3 != 0) {
      ShowWindow(hWnd,9);
    }
    SetForegroundWindow(hWnd);
    uVar4 = 1;
  }
  return uVar4;
}


// ==== FUN_004011d0 @ 004011d0

ATOM __cdecl FUN_004011d0(HINSTANCE param_1)

{
  ATOM AVar1;
  HLOCAL hMem;
  WNDCLASSA *lpWndClass;
  HICON pHVar2;
  HCURSOR pHVar3;
  HBRUSH pHVar4;
  int iVar5;
  WNDCLASSA *pWVar6;
  
  hMem = LocalAlloc(0x40,0x28);
  lpWndClass = LocalLock(hMem);
  pWVar6 = lpWndClass;
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    pWVar6->style = 0;
    pWVar6 = (WNDCLASSA *)&pWVar6->lpfnWndProc;
  }
  lpWndClass->style = 3;
  lpWndClass->lpfnWndProc = (WNDPROC)&LAB_004012d0;
  lpWndClass->hInstance = param_1;
  pHVar2 = LoadIconA(param_1,(LPCSTR)0x69);
  lpWndClass->hIcon = pHVar2;
  pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  lpWndClass->hCursor = pHVar3;
  pHVar4 = GetSysColorBrush(0xf);
  lpWndClass->hbrBackground = pHVar4;
  lpWndClass->lpszMenuName = (LPCSTR)0x0;
  lpWndClass->lpszClassName = s_MockbaLauncherWindow_0040b040;
  AVar1 = RegisterClassA(lpWndClass);
  LocalUnlock(hMem);
  LocalFree(hMem);
  return AVar1;
}


// ==== FUN_00401260 @ 00401260

undefined4 __cdecl FUN_00401260(HINSTANCE param_1)

{
  DAT_0040b060 = CreateWindowExA(0,s_MockbaLauncherWindow_0040b040,DAT_0040ea24,0x2ca0000,
                                 -0x80000000,0,-0x80000000,0,(HWND)0x0,(HMENU)0x0,param_1,
                                 (LPVOID)0x0);
  if (DAT_0040b060 == (HWND)0x0) {
    return 0;
  }
  FUN_00401900();
  ShowWindow(DAT_0040b060,1);
  UpdateWindow(DAT_0040b060);
  return 1;
}


// ==== FUN_004016f0 @ 004016f0

undefined4 __cdecl FUN_004016f0(HWND param_1)

{
  int *piVar1;
  DWORD dwMessageId;
  int iVar2;
  BYTE *pBVar3;
  DWORD_PTR DVar4;
  TBBUTTON *pTVar5;
  LPCSTR local_cc;
  TBBUTTON local_c8 [10];
  
  DVar4 = 0;
  pTVar5 = local_c8;
  for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
    pTVar5->iBitmap = 0;
    pTVar5 = (TBBUTTON *)&pTVar5->idCommand;
  }
  pBVar3 = &local_c8[0].fsState;
  piVar1 = &DAT_0040b070;
  do {
    if (*piVar1 != 0) {
      *pBVar3 = '\x04';
      iVar2 = piVar1[1];
      pBVar3[1] = '\0';
      ((TBBUTTON *)(pBVar3 + -8))->iBitmap = DVar4;
      *(int *)(pBVar3 + -4) = iVar2;
      *(DWORD_PTR *)(pBVar3 + 4) = DVar4;
      pBVar3 = pBVar3 + 0x14;
    }
    piVar1 = piVar1 + 0x85;
    DVar4 = DVar4 + 1;
  } while (piVar1 < s__s__s_0040c538);
  DAT_0040b038 = CreateToolbarEx(param_1,0x50000100,0x65,10,DAT_0040b030,0x65,local_c8,DAT_0040b064,
                                 0,0,0x20,0x20,0x14);
  if (DAT_0040b038 == (HWND)0x0) {
    dwMessageId = GetLastError();
    FormatMessageA(0x1100,(LPCVOID)0x0,dwMessageId,0x400,(LPSTR)&local_cc,0,(va_list *)0x0);
    MessageBoxA(param_1,local_cc,DAT_0040ea24,0x30);
    LocalFree(local_cc);
    return 0;
  }
  SendMessageA(DAT_0040b038,0x421,0,0);
  return 1;
}


// ==== FUN_004017f0 @ 004017f0

bool FUN_004017f0(void)

{
  int iVar1;
  UINT UVar2;
  CHAR local_104 [260];
  
  iVar1 = __getdrive();
  wsprintfA(local_104,&DAT_0040c54c,iVar1 + 0x40);
  UVar2 = GetDriveTypeA(local_104);
  return (bool)('\x01' - (UVar2 == 3));
}


// ==== FUN_00401830 @ 00401830

undefined4 __cdecl FUN_00401830(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  ushort *puVar9;
  CHAR local_208 [520];
  
  puVar5 = (ushort *)(param_1 + 8);
  uVar6 = 0;
  do {
    if ((DAT_0040b058 & *puVar5) != 0) {
      puVar5[-0xffffffff00000004] = 1;
      puVar5[-0xffffffff00000003] = 0;
      DAT_0040b064 = DAT_0040b064 + 1;
      LoadStringA(DAT_0040b034,uVar6 + 40000,local_208,0x208);
      pcVar2 = _strchr(local_208,0x3b);
      uVar3 = 0xffffffff;
      pcVar7 = pcVar2 + 1;
      do {
        pcVar8 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar7 = pcVar8 + -uVar3;
      puVar9 = puVar5 + 0x83;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)puVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        puVar9 = puVar9 + 2;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(char *)puVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        puVar9 = (ushort *)((int)puVar9 + 1);
      }
      uVar3 = 0xffffffff;
      *pcVar2 = '\0';
      pcVar7 = pcVar2 + 1;
      do {
        pcVar2 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar2 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar2;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar7 = pcVar2 + -uVar3;
      puVar9 = puVar5 + 1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)puVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        puVar9 = puVar9 + 2;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(char *)puVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        puVar9 = (ushort *)((int)puVar9 + 1);
      }
    }
    puVar5 = puVar5 + 0x10a;
    uVar6 = uVar6 + 1;
    if (9 < uVar6) {
      return 1;
    }
  } while( true );
}


// ==== FUN_00401900 @ 00401900

void FUN_00401900(void)

{
  char cVar1;
  int iVar2;
  HBITMAP h;
  HDC hdc;
  uint uVar3;
  uint uVar4;
  LPCSTR pCVar5;
  longlong lVar6;
  tagSIZE local_30;
  tagRECT local_28;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  
  iVar2 = GetSystemMetrics(4);
  GetSystemMetrics(0x1e);
  h = LoadBitmapA(DAT_0040b030,(LPCSTR)0x65);
  GetObjectA(h,0x18,local_18);
  DeleteObject(h);
  uVar4 = (local_14 / 10 + 7) * DAT_0040b064 + 6;
  hdc = GetDC(DAT_0040b060);
  uVar3 = 0xffffffff;
  pCVar5 = DAT_0040ea24;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pCVar5;
    pCVar5 = pCVar5 + 1;
  } while (cVar1 != '\0');
  GetTextExtentPoint32A(hdc,DAT_0040ea24,~uVar3 - 2,&local_30);
  ReleaseDC(DAT_0040b060,hdc);
  DAT_0040b06c = local_10 + 0x10 + iVar2;
  lVar6 = __ftol();
  DAT_0040b068 = (uint)lVar6;
  if ((uint)lVar6 <= uVar4) {
    DAT_0040b068 = uVar4;
  }
  GetWindowRect(DAT_0040b060,&local_28);
  MoveWindow(DAT_0040b060,local_28.left,local_28.top,DAT_0040b068,DAT_0040b06c,1);
  return;
}


// ==== FUN_00401a20 @ 00401a20

undefined4 FUN_00401a20(void)

{
  BYTE BVar1;
  LSTATUS LVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  BYTE *pBVar6;
  undefined4 *puVar7;
  BYTE *pBVar8;
  HKEY local_308;
  DWORD local_304;
  char local_300 [4];
  char local_2fc [4];
  char local_2f8 [4];
  char local_2f4 [4];
  undefined4 local_2f0 [60];
  BYTE local_200 [4];
  char local_1fc [4];
  char local_1f8 [4];
  char local_1f4 [4];
  undefined4 local_1f0 [60];
  char local_100 [4];
  char local_fc [4];
  char local_f8 [4];
  char local_f4 [4];
  undefined4 local_f0 [60];
  
  local_200 = (BYTE  [4])s_Unloaded_String_0040c554._0_4_;
  local_1fc = (char  [4])s_Unloaded_String_0040c554._4_4_;
  local_1f8 = (char  [4])s_Unloaded_String_0040c554._8_4_;
  local_1f4 = (char  [4])s_Unloaded_String_0040c554._12_4_;
  puVar7 = local_1f0;
  for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_100 = (char  [4])s_Unloaded_String_0040c554._0_4_;
  local_fc = (char  [4])s_Unloaded_String_0040c554._4_4_;
  local_f8 = (char  [4])s_Unloaded_String_0040c554._8_4_;
  local_f4 = (char  [4])s_Unloaded_String_0040c554._12_4_;
  puVar7 = local_f0;
  for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_300 = (char  [4])s_Unloaded_String_0040c554._0_4_;
  local_2fc = (char  [4])s_Unloaded_String_0040c554._4_4_;
  local_2f8 = (char  [4])s_Unloaded_String_0040c554._8_4_;
  local_2f4 = (char  [4])s_Unloaded_String_0040c554._12_4_;
  puVar7 = local_2f0;
  for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_304 = 0x100;
  LoadStringA(DAT_0040b034,20000,local_100,0x100);
  LoadStringA(DAT_0040b034,0x4e21,local_300,0x100);
  LVar2 = RegOpenKeyExA((HKEY)0x80000002,local_100,0,1,&local_308);
  if (LVar2 == 0) {
    LVar2 = RegQueryValueExA(local_308,local_300,(LPDWORD)0x0,(LPDWORD)0x0,local_200,&local_304);
    if (LVar2 != 0) {
      RegCloseKey(local_308);
      return 0;
    }
    iVar3 = _atoi((char *)local_200);
    DAT_0040b058 = (undefined2)iVar3;
    LoadStringA(DAT_0040b034,0x4e22,local_300,0x100);
    local_304 = 0x100;
    LVar2 = RegQueryValueExA(local_308,local_300,(LPDWORD)0x0,(LPDWORD)0x0,local_200,&local_304);
    if (LVar2 != 0) {
      RegCloseKey(local_308);
      return 0;
    }
    uVar4 = 0xffffffff;
    pBVar6 = local_200;
    do {
      pBVar8 = pBVar6;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pBVar8 = pBVar6 + 1;
      BVar1 = *pBVar6;
      pBVar6 = pBVar8;
    } while (BVar1 != '\0');
    uVar4 = ~uVar4;
    pBVar6 = pBVar8 + -uVar4;
    pBVar8 = (BYTE *)&DAT_0040e818;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pBVar8 = *(undefined4 *)pBVar6;
      pBVar6 = pBVar6 + 4;
      pBVar8 = pBVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pBVar8 = *pBVar6;
      pBVar6 = pBVar6 + 1;
      pBVar8 = pBVar8 + 1;
    }
    LoadStringA(DAT_0040b034,0x4e23,local_300,0x100);
    local_304 = 0x100;
    LVar2 = RegQueryValueExA(local_308,local_300,(LPDWORD)0x0,(LPDWORD)0x0,local_200,&local_304);
    if (LVar2 != 0) {
      RegCloseKey(local_308);
      return 0;
    }
    uVar4 = 0xffffffff;
    pBVar6 = local_200;
    do {
      pBVar8 = pBVar6;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pBVar8 = pBVar6 + 1;
      BVar1 = *pBVar6;
      pBVar6 = pBVar8;
    } while (BVar1 != '\0');
    uVar4 = ~uVar4;
    pBVar6 = pBVar8 + -uVar4;
    pBVar8 = (BYTE *)&DAT_0040e920;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pBVar8 = *(undefined4 *)pBVar6;
      pBVar6 = pBVar6 + 4;
      pBVar8 = pBVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pBVar8 = *pBVar6;
      pBVar6 = pBVar6 + 1;
      pBVar8 = pBVar8 + 1;
    }
    RegCloseKey(local_308);
  }
  return 1;
}


// ==== FUN_00401cb0 @ 00401cb0

undefined4 FUN_00401cb0(void)

{
  LCID Locale;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_108;
  undefined4 local_104;
  char local_100;
  undefined4 local_ff;
  
  local_108 = DAT_0040c5c4;
  local_104 = DAT_0040c5c4;
  local_100 = DAT_0040c548;
  puVar2 = &local_ff;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  Locale = GetUserDefaultLCID();
  if ((Locale == 0x403) || (Locale == 0x42d)) {
    Locale = 0x40a;
  }
  GetLocaleInfoA(Locale,3,(LPSTR)&local_108,4);
  _sprintf(&local_100,&DAT_0040c5b4,s_Setup_0040c5bc,&local_108);
  DAT_0040b034 = LoadLibraryA(&local_100);
  if ((int)DAT_0040b034 < 0x20) {
    GetLocaleInfoA((uint)((ushort)Locale & 0x3ff | 0x400),3,(LPSTR)&local_104,4);
    _sprintf(&local_100,&DAT_0040c5b4,s_Setup_0040c5bc,&local_104);
    DAT_0040b034 = LoadLibraryA(&local_100);
    if ((int)DAT_0040b034 < 0x20) {
      DAT_0040b034 = LoadLibraryA(s_SetupENU_dll_0040c5a4);
      if ((int)DAT_0040b034 < 0x20) {
        MessageBoxA((HWND)0x0,s_Unable_to_find_the_language_spec_0040c564,s_Setup_0040c5bc,0);
        return 0;
      }
    }
  }
  return 1;
}


// ==== operator_new @ 00401dd0

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== _sprintf @ 00401de0

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


// ==== _strchr @ 00401e60

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}


// ==== __getdrive @ 00401f20

/* Library Function - Single Match
    __getdrive
   
   Library: Visual Studio 1998 Release */

int __cdecl __getdrive(void)

{
  DWORD DVar1;
  int iVar2;
  byte local_104;
  char local_103;
  
  iVar2 = 0;
  DVar1 = GetCurrentDirectoryA(0x104,(LPSTR)&local_104);
  if ((DVar1 != 0) && (local_103 == ':')) {
    iVar2 = _toupper((uint)local_104);
    iVar2 = iVar2 + -0x40;
  }
  return iVar2;
}


// ==== __ftol @ 00401f60

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== __fpmath @ 00401f90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_00401fc0();
  _DAT_0040c5dc = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


// ==== FUN_00401fc0 @ 00401fc0

void FUN_00401fc0(void)

{
  PTR_FUN_0040c834 = &LAB_00403430;
  PTR_FUN_0040c838 = &LAB_004034b0;
  PTR_FUN_0040c83c = &LAB_004033c0;
  PTR_FUN_0040c840 = &LAB_00403490;
  PTR_FUN_0040c830 = &LAB_00403850;
  PTR_FUN_0040c844 = &LAB_00403850;
  return;
}


// ==== _atol @ 00402000

/* Library Function - Single Match
    _atol
   
   Library: Visual Studio 1998 Release */

long __cdecl _atol(char *_Str)

{
  uint uVar1;
  uint uVar2;
  uint _C;
  int iVar3;
  byte *pbVar4;
  
  while( true ) {
    if (DAT_0040ca54 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_0040c848 + (uint)(byte)*_Str * 2) & 8;
    }
    else {
      uVar1 = __isctype((uint)(byte)*_Str,8);
    }
    if (uVar1 == 0) break;
    _Str = _Str + 1;
  }
  uVar1 = (uint)(byte)*_Str;
  pbVar4 = (byte *)(_Str + 1);
  if ((uVar1 == 0x2d) || (_C = uVar1, uVar1 == 0x2b)) {
    _C = (uint)*pbVar4;
    pbVar4 = (byte *)(_Str + 2);
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_0040ca54 < 2) {
      uVar2 = *(ushort *)(PTR_DAT_0040c848 + _C * 2) & 4;
    }
    else {
      uVar2 = __isctype(_C,4);
    }
    if (uVar2 == 0) break;
    iVar3 = (_C - 0x30) + iVar3 * 10;
    _C = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  }
  if (uVar1 == 0x2d) {
    return -iVar3;
  }
  return iVar3;
}


// ==== _atoi @ 004020b0

/* Library Function - Single Match
    _atoi
   
   Library: Visual Studio 1998 Release */

int __cdecl _atoi(char *_Str)

{
  long lVar1;
  
  lVar1 = _atol(_Str);
  return lVar1;
}


// ==== entry @ 004020c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE pHVar4;
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
  puStack_c = &DAT_0040a008;
  puStack_10 = &LAB_00404934;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0040ca70 = DVar2 >> 8 & 0xff;
  DAT_0040ca64 = DVar2 >> 0x10;
  _DAT_0040ca6c = DVar2 & 0xff;
  _DAT_0040ca68 = _DAT_0040ca6c * 0x100 + _DAT_0040ca70;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  iVar3 = __mtinit();
  if (iVar3 == 0) {
    __amsg_exit(0x10);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0041018c = (byte *)GetCommandLineA();
  DAT_0040c5ec = ___crtGetEnvironmentStringsA();
  if ((DAT_0040c5ec == (LPVOID)0x0) || (DAT_0041018c == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0041018c;
  pbVar5 = DAT_0041018c;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_0041018c + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar5);
        if (iVar3 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_004021d8;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_004021d8:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  iVar3 = FUN_00401030(pHVar4);
                    /* WARNING: Subroutine does not return */
  _exit(iVar3);
}


// ==== __amsg_exit @ 00402270

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0040c5f8 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_0040c5f4)(0xff);
  return;
}


// ==== _malloc @ 004022a0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0040ce24);
  return pvVar1;
}


// ==== __nh_malloc @ 004022c0

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


// ==== __heap_alloc @ 00402310

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if (dwBytes <= DAT_0040d644) {
    __lock(9);
    puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4);
    FUN_00403220(9);
    if (puVar1 != (undefined *)0x0) {
      return puVar1;
    }
  }
  pvVar2 = HeapAlloc(DAT_00410074,0,dwBytes);
  return pvVar2;
}


// ==== __flsbuf @ 00402370

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
    if ((_File == (FILE *)&DAT_0040d668) || (_File == (FILE *)&DAT_0040d688)) {
      iVar1 = __isatty(_FileHandle);
      if (iVar1 != 0) goto LAB_004023f4;
    }
    __getbuf(_File_00);
  }
LAB_004023f4:
  if ((_File_00->_flag & 0x108U) == 0) {
    uVar3 = 1;
    uVar4 = __write(_FileHandle,&_Ch,1);
  }
  else {
    uVar3 = (int)_File_00->_ptr - (int)_File_00->_base;
    _File_00->_ptr = _File_00->_base + 1;
    _File_00->_cnt = _File_00->_bufsiz + -1;
    if ((int)uVar3 < 1) {
      puVar2 = &DAT_0040cd60;
      if (_FileHandle != 0xffffffff) {
        puVar2 = (undefined *)
                 (*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7) >> 3)) +
                 (_FileHandle & 0x1f) * 0x24);
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


// ==== __output @ 004024c0

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
      uVar4 = *(byte *)((int)&PTR_LAB_0040a010 + (int)(char)bVar10) & 0xf;
    }
    local_21c = (int)((char)(&DAT_0040a030)[uVar4 * 8 + local_21c] >> 4);
    switch(local_21c) {
    case 0:
switchD_00402545_caseD_0:
      local_220 = 0;
      if ((PTR_DAT_0040c848[(uint)bVar10 * 2 + 1] & 0x80) != 0) {
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
          goto switchD_00402545_caseD_0;
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
        (*(code *)PTR_FUN_0040c830)(&local_208,&local_200,(int)(char)bVar10,puVar5,local_20c);
        if ((((uint)puVar14 & 0x80) != 0) && (puVar5 == (undefined1 *)0x0)) {
          (*(code *)PTR_FUN_0040c83c)(&local_200);
        }
        if ((bVar10 == 0x67) && (((uint)puVar14 & 0x80) == 0)) {
          (*(code *)PTR_FUN_0040c834)(&local_200);
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
            local_240 = (wchar_t *)PTR_DAT_0040c600;
            pwVar12 = (wchar_t *)PTR_DAT_0040c600;
          }
          for (; (puVar11 != (undefined1 *)0x0 && (puVar11 = puVar11 + -1, (char)*pwVar12 != '\0'));
              pwVar12 = (wchar_t *)((int)pwVar12 + 1)) {
          }
          puVar11 = (undefined1 *)((int)pwVar12 - (int)local_240);
          pwVar12 = local_240;
        }
        else {
          if (local_240 == (wchar_t *)0x0) {
            local_240 = (wchar_t *)PTR_DAT_0040c604;
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
          local_240 = (wchar_t *)PTR_DAT_0040c600;
          pcVar15 = PTR_DAT_0040c600;
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
        goto LAB_00402927;
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
        goto LAB_00402927;
      case 0x70:
        puVar5 = (undefined1 *)0x8;
      case 0x58:
        local_214 = 7;
        goto LAB_00402900;
      case 0x75:
        local_218 = 10;
        goto LAB_00402927;
      case 0x78:
        local_214 = 0x27;
LAB_00402900:
        local_218 = 0x10;
        puVar13 = puVar5;
        if (((uint)puVar14 & 0x80) != 0) {
          local_246 = '0';
          local_224 = 2;
          local_245 = (char)local_214 + 'Q';
        }
LAB_00402927:
        if (((uint)puVar14 & 0x8000) == 0) {
          if (((uint)puVar14 & 0x20) == 0) {
            if (((uint)puVar14 & 0x40) == 0) {
              uVar4 = get_int_arg((int *)&param_3);
              goto LAB_004029c6;
            }
            iVar9 = get_int_arg((int *)&param_3);
            local_23c = (ulonglong)iVar9;
          }
          else if (((uint)puVar14 & 0x40) == 0) {
            uVar4 = get_int_arg((int *)&param_3);
            uVar4 = uVar4 & 0xffff;
LAB_004029c6:
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
              if (((uint)puVar14 & 2) == 0) goto LAB_00402c39;
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
LAB_00402c39:
        iVar9 = (local_228 - local_224) - (int)puVar11;
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


// ==== write_char @ 00402e70

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


// ==== write_multi_char @ 00402ec0

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


// ==== write_string @ 00402f00

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


// ==== get_int_arg @ 00402f40

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


// ==== get_int64_arg @ 00402f50

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


// ==== get_short_arg @ 00402f70

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


// ==== _toupper @ 00402f80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _toupper
   
   Library: Visual Studio 1998 Release */

int __cdecl _toupper(int _C)

{
  bool bVar1;
  
  if (DAT_0040da48 == 0) {
    if ((0x60 < _C) && (_C < 0x7b)) {
      return _C + -0x20;
    }
  }
  else {
    bVar1 = DAT_0040f064 == 0;
    if (bVar1) {
      _DAT_0040f068 = _DAT_0040f068 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __toupper_lk(_C);
    if (!bVar1) {
      FUN_00403220(0x13);
      return _C;
    }
    _DAT_0040f068 = _DAT_0040f068 + -1;
  }
  return _C;
}


// ==== __toupper_lk @ 00402ff0

/* Library Function - Single Match
    __toupper_lk
   
   Library: Visual Studio 1998 Release */

uint __cdecl __toupper_lk(uint param_1)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_0040da48 == (_locale_t)0x0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      param_1 = param_1 - 0x20;
    }
    return param_1;
  }
  if ((int)param_1 < 0x100) {
    if (DAT_0040ca54 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_0040c848 + param_1 * 2) & 2;
    }
    else {
      uVar1 = __isctype(param_1,2);
    }
    if (uVar1 == 0) {
      return param_1;
    }
  }
  local_4 = (byte)(param_1 >> 8);
  if ((PTR_DAT_0040c848[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)param_1;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)param_1;
  }
  iVar2 = ___crtLCMapStringA(DAT_0040da48,(LPCWSTR)0x200,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return param_1;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __dosmaperr @ 004030e0

/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = FUN_00403170();
  iVar3 = 0;
  *puVar1 = param_1;
  puVar1 = &DAT_0040c608;
  do {
    if (*puVar1 == param_1) {
      piVar2 = FUN_00403160();
      *piVar2 = *(int *)(iVar3 * 8 + 0x40c60c);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + 1;
  } while (puVar1 < &DAT_0040c770);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    piVar2 = FUN_00403160();
    *piVar2 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    piVar2 = FUN_00403160();
    *piVar2 = 8;
    return;
  }
  piVar2 = FUN_00403160();
  *piVar2 = 0x16;
  return;
}


// ==== FUN_00403160 @ 00403160

int * FUN_00403160(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


// ==== FUN_00403170 @ 00403170

ulong * FUN_00403170(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


// ==== __mtinitlocks @ 00403180

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0040c7b4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0040c7a4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0040c794);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0040c774);
  return extraout_EAX;
}


// ==== __lock @ 004031b0

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 1998 Release */

void __cdecl __lock(int _File)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = (int *)(&DAT_0040c770 + _File * 4);
  if (*piVar1 == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    __lock(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      _free(lpCriticalSection);
    }
    FUN_00403220(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


// ==== FUN_00403220 @ 00403220

void __cdecl FUN_00403220(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0040c770 + param_1 * 4));
  return;
}


// ==== FID_conflict:__lock_file @ 00403240

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)((int)&DAT_0040d644 + 3U) < _File) && (_File < (FILE *)0x40d8a9)) {
    __lock(((int)&_File[-0x206b3]._bufsiz >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


// ==== FID_conflict:__lock_file2 @ 00403280

/* Library Function - Multiple Matches With Different Base Names
    __lock_file2
    __unlock_file2
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __lock(_Index + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== FID_conflict:__lock_file @ 004032b0

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)((int)&DAT_0040d644 + 3U) < _File) && (_File < (FILE *)0x40d8a9)) {
    FUN_00403220(((int)&_File[-0x206b3]._bufsiz >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


// ==== FID_conflict:__lock_file2 @ 004032f0

/* Library Function - Multiple Matches With Different Base Names
    __lock_file2
    __unlock_file2
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    FUN_00403220(_Index + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== __setdefaultprecision @ 00403320

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 00403340

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 00403390

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


// ==== __cftoe @ 00403500

/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftoe(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec,int _Caps)

{
  STRFLT unaff_EDI;
  _strflt local_28;
  char local_18 [24];
  
  __fltout2((_CRT_DOUBLE)*_Value,&local_28,local_18,(size_t)unaff_EDI);
  __fptostr(_Buf + (uint)(0 < (int)_SizeInBytes) + (uint)(local_28.sign == 0x2d),_SizeInBytes + 1,
            (int)&local_28,unaff_EDI);
  __cftoe2(_Buf,_SizeInBytes,_Dec,&local_28.sign,'\0');
  return (errno_t)_Buf;
}


// ==== __cftoe2 @ 00403580

/* Library Function - Single Match
    __cftoe2
   
   Library: Visual Studio 1998 Release */

undefined1 * __cdecl __cftoe2(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_5 != '\0') {
    __shift(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    puVar1 = param_1 + 1;
    *param_1 = 0x2d;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = *puVar2;
    *puVar2 = DAT_0040ca58;
  }
  puVar4 = (undefined4 *)(puVar2 + param_2 + (uint)(param_5 == '\0'));
  *puVar4 = DAT_0040a0d8;
  *(undefined2 *)(puVar4 + 1) = DAT_0040a0dc;
  if (param_3 != 0) {
    *(undefined1 *)puVar4 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar3 = param_4[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      *(undefined1 *)((int)puVar4 + 1) = 0x2d;
    }
    if (99 < iVar3) {
      *(char *)((int)puVar4 + 2) = *(char *)((int)puVar4 + 2) + (char)(iVar3 / 100);
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      *(char *)((int)puVar4 + 3) = *(char *)((int)puVar4 + 3) + (char)(iVar3 / 10);
      iVar3 = iVar3 % 10;
    }
    *(char *)(puVar4 + 1) = *(char *)(puVar4 + 1) + (char)iVar3;
  }
  return param_1;
}


// ==== __cftof @ 00403670

/* Library Function - Single Match
    __cftof
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftof(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec)

{
  STRFLT unaff_EDI;
  _strflt local_28;
  char local_18 [24];
  
  __fltout2((_CRT_DOUBLE)*_Value,&local_28,local_18,(size_t)unaff_EDI);
  __fptostr(_Buf + (local_28.sign == 0x2d),local_28.decpt + _SizeInBytes,(int)&local_28,unaff_EDI);
  __cftof2(_Buf,_SizeInBytes,&local_28.sign,'\0');
  return (errno_t)_Buf;
}


// ==== __cftof2 @ 004036e0

/* Library Function - Single Match
    __cftof2
   
   Library: Visual Studio 1998 Release */

char * __cdecl __cftof2(char *param_1,uint param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar2 = *param_3, param_2 == iVar1 - 1U)) {
    param_1[(iVar1 - 1U) + (uint)(iVar2 == 0x2d)] = '0';
    (param_1 + (iVar1 - 1U) + (uint)(iVar2 == 0x2d))[1] = '\0';
  }
  pcVar6 = param_1;
  if (*param_3 == 0x2d) {
    pcVar6 = param_1 + 1;
    *param_1 = '-';
  }
  if (param_3[1] < 1) {
    pcVar5 = pcVar6 + 1;
    __shift(pcVar6,1);
    *pcVar6 = '0';
  }
  else {
    pcVar5 = pcVar6 + param_3[1];
  }
  if (0 < (int)param_2) {
    __shift(pcVar5,1);
    *pcVar5 = DAT_0040ca58;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if (param_4 == '\0') {
        uVar4 = -iVar1;
        if ((int)param_2 <= -iVar1) {
          uVar4 = param_2;
        }
      }
      else {
        uVar4 = -iVar1;
      }
      __shift(pcVar5 + 1,uVar4);
      uVar3 = uVar4 >> 2;
      pcVar6 = pcVar5 + 1;
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1;
        builtin_strncpy(pcVar6,"0000",4);
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = '0';
        pcVar6 = pcVar6 + 1;
      }
    }
  }
  return param_1;
}


// ==== __cftog @ 004037a0

/* Library Function - Single Match
    __cftog
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftog(double *param_1,char *param_2,size_t param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  STRFLT unaff_EBP;
  char *pcVar3;
  _strflt local_28;
  char local_18 [24];
  
  __fltout2((_CRT_DOUBLE)*param_1,&local_28,local_18,(size_t)unaff_EBP);
  iVar2 = local_28.decpt + -1;
  __fptostr(param_2 + (local_28.sign == 0x2d),param_3,(int)&local_28,unaff_EBP);
  local_28.decpt = local_28.decpt + -1;
  if ((-5 < local_28.decpt) && (local_28.decpt < (int)param_3)) {
    pcVar1 = param_2 + (local_28.sign == 0x2d);
    if (iVar2 < local_28.decpt) {
      do {
        pcVar3 = pcVar1;
        pcVar1 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    __cftof2(param_2,param_3,&local_28.sign,'\x01');
    return;
  }
  __cftoe2(param_2,param_3,param_4,&local_28.sign,'\x01');
  return;
}


// ==== __shift @ 004038c0

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


// ==== __isctype @ 004038f0

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
    return (uint)*(ushort *)(PTR_DAT_0040c848 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_0040c848[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
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


// ==== __cinit @ 004039d0

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (PTR___fpmath_0040c5e0 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_0040c5e0)();
  }
  __initterm((undefined4 *)&DAT_0040b00c,(undefined4 *)&DAT_0040b014);
  iVar1 = __initterm((undefined4 *)&DAT_0040b000,(undefined4 *)&DAT_0040b008);
  return iVar1;
}


// ==== _exit @ 00403a00

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 00403a20

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 00403a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FID_conflict___lockexit();
  if (DAT_0040caa0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0040ca9c = 1;
  DAT_0040ca98 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00410188 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00410184 + -4), DAT_00410188 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00410188 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_0040b018,(undefined4 *)&DAT_0040b020);
  }
  __initterm((undefined4 *)&DAT_0040b024,(undefined4 *)&DAT_0040b028);
  if (param_3 != 0) {
    FID_conflict___lockexit();
    return;
  }
  DAT_0040caa0 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


// ==== FID_conflict:__lockexit @ 00403b00

/* Library Function - Multiple Matches With Different Base Names
    __lockexit
    __unlockexit
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lockexit(void)

{
  __lock(0xd);
  return;
}


// ==== FID_conflict:__lockexit @ 00403b10

/* Library Function - Multiple Matches With Different Base Names
    __lockexit
    __unlockexit
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lockexit(void)

{
  FUN_00403220(0xd);
  return;
}


// ==== __initterm @ 00403b20

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


// ==== __global_unwind2 @ 00403b40

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x403b58,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 00403b82

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
  puStack_18 = &LAB_00403b60;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00403c16();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_00403c16 @ 00403c16

void FUN_00403c16(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0040caac = *(undefined4 *)(unaff_EBP + 8);
  DAT_0040caa8 = in_EAX;
  DAT_0040cab0 = unaff_EBP;
  return;
}


// ==== __XcptFilter @ 00403c30

/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 1998 Release */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  code *pcVar1;
  void *pvVar2;
  void *pvVar3;
  _ptiddata p_Var4;
  int *piVar5;
  LONG LVar6;
  int iVar7;
  int iVar8;
  
  p_Var4 = __getptd();
  piVar5 = (int *)xcptlookup(_ExceptionNum,*(int **)(p_Var4->_con_ch_buf + 4));
  if ((piVar5 == (int *)0x0) || (pcVar1 = (code *)piVar5[2], pcVar1 == (code *)0x0)) {
    LVar6 = UnhandledExceptionFilter(_ExceptionPtr);
    return LVar6;
  }
  if (pcVar1 == (code *)0x5) {
    piVar5[2] = 0;
    return 1;
  }
  if (pcVar1 == (code *)0x1) {
    return -1;
  }
  pvVar2 = p_Var4->_initaddr;
  p_Var4->_initaddr = _ExceptionPtr;
  if (piVar5[1] == 8) {
    if (DAT_0040cb30 < DAT_0040cb34 + DAT_0040cb30) {
      iVar7 = DAT_0040cb30 * 0xc;
      iVar8 = DAT_0040cb30;
      do {
        iVar7 = iVar7 + 0xc;
        iVar8 = iVar8 + 1;
        *(undefined4 *)(*(int *)(p_Var4->_con_ch_buf + 4) + -4 + iVar7) = 0;
      } while (iVar8 < DAT_0040cb34 + DAT_0040cb30);
    }
    pvVar3 = p_Var4->_initarg;
    iVar8 = *piVar5;
    if (iVar8 == -0x3fffff72) {
      p_Var4->_initarg = (void *)0x83;
    }
    else if (iVar8 == -0x3fffff70) {
      p_Var4->_initarg = (void *)0x81;
    }
    else if (iVar8 == -0x3fffff6f) {
      p_Var4->_initarg = (void *)0x84;
    }
    else if (iVar8 == -0x3fffff6d) {
      p_Var4->_initarg = (void *)0x85;
    }
    else if (iVar8 == -0x3fffff73) {
      p_Var4->_initarg = (void *)0x82;
    }
    else if (iVar8 == -0x3fffff71) {
      p_Var4->_initarg = (void *)0x86;
    }
    else if (iVar8 == -0x3fffff6e) {
      p_Var4->_initarg = (void *)0x8a;
    }
    (*pcVar1)(8,p_Var4->_initarg);
    p_Var4->_initarg = pvVar3;
  }
  else {
    piVar5[2] = 0;
    (*pcVar1)(piVar5[1]);
  }
  p_Var4->_initaddr = pvVar2;
  return -1;
}


// ==== xcptlookup @ 00403d80

/* Library Function - Single Match
    _xcptlookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl xcptlookup(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = param_2;
  do {
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 3;
  } while (piVar1 < param_2 + DAT_0040cb3c * 3);
  return -(uint)(*piVar1 == param_1) & (uint)piVar1;
}


// ==== __ismbblead @ 00403db0

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 00403dd0

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_0040cb48 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_0040c852 + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 00403e10

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
  cVar1 = *DAT_0040c5ec;
  pcVar7 = DAT_0040c5ec;
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
  _DAT_0040ca80 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_0040c5ec;
  pcVar7 = DAT_0040c5ec;
  do {
    if (cVar1 == '\0') {
      _free(DAT_0040c5ec);
      DAT_0040c5ec = (char *)0x0;
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


// ==== __setargv @ 00403f00

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0040eea0,0x104);
  _DAT_0040ca90 = &DAT_0040eea0;
  pbVar2 = &DAT_0040eea0;
  if (*DAT_0041018c != 0) {
    pbVar2 = DAT_0041018c;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_0040ca78 = puVar1;
  _DAT_0040ca74 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 00403fa0

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
      if (((*(byte *)((int)&DAT_0040cb48 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_0040cb48 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00404010;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00404010:
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
          if ((*(byte *)((int)&DAT_0040cb48 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_0040413f;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_0040cb48 + bVar1 + 1) & 4) != 0) {
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
LAB_0040413f:
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


// ==== ___crtGetEnvironmentStringsA @ 00404170

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
  if (DAT_0040cb44 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0040cb44 = 2;
    }
    else {
      DAT_0040cb44 = 1;
    }
  }
  if (DAT_0040cb44 != 1) {
    if (DAT_0040cb44 != 2) {
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


// ==== __setmbcp @ 00404300

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
  uint uVar5;
  int iVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  __lock(0x19);
  CodePage = getSystemCP(_CodePage);
  if (DAT_0040cc4c == CodePage) {
    FUN_00403220(0x19);
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    FUN_00403220(0x19);
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_0040cc70;
  do {
    if (*pUVar3 == CodePage) {
      uVar5 = 0;
      puVar10 = &DAT_0040cb48;
      for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_0040cc80 + (local_18 * 6 + uVar5) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_0040cc68)[uVar5];
            do {
              pbVar1 = (byte *)((int)&DAT_0040cb48 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      DAT_0040cc4c = CodePage;
      _DAT_0040cc50 = _CPtoLCID(CodePage);
      DAT_0040cc5c = *(undefined4 *)(&DAT_0040cc78 + local_18 * 0x30);
      DAT_0040cc58 = *(undefined4 *)(&DAT_0040cc74 + local_18 * 0x30);
      DAT_0040cc60 = *(undefined4 *)(local_18 * 0x30 + 0x40cc7c);
      FUN_00403220(0x19);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_0040cd60);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_0040cb48;
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_0040cc50 = 0;
      DAT_0040cc4c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar5 = (uint)*pBVar8;
        if (uVar5 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_0040cb48 + uVar5 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar5 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_0040cb48 + uVar5 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0xff);
      DAT_0040cc4c = CodePage;
      _DAT_0040cc50 = _CPtoLCID(CodePage);
    }
    DAT_0040cc58 = 0;
    DAT_0040cc5c = 0;
    DAT_0040cc60 = 0;
    FUN_00403220(0x19);
    return 0;
  }
  if (DAT_0040cc64 == 0) {
    FUN_00403220(0x19);
    return -1;
  }
  setSBCS();
  FUN_00403220(0x19);
  return 0;
}


// ==== getSystemCP @ 00404530

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_0040cc64 = 1;
                    /* WARNING: Could not recover jumptable at 0x0040454d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0040cc64 = 1;
                    /* WARNING: Could not recover jumptable at 0x00404562. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0040da58;
  }
  DAT_0040cc64 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00404580

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


// ==== setSBCS @ 004045e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0040cb48;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0040cc58 = 0;
  DAT_0040cc4c = 0;
  _DAT_0040cc50 = 0;
  DAT_0040cc5c = 0;
  DAT_0040cc60 = 0;
  return;
}


// ==== ___initmbctable @ 00404610

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00404620

/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __ioinit(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hFile;
  UINT *pUVar3;
  UINT UVar4;
  UINT UVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  _STARTUPINFOA local_44;
  
  puVar1 = _malloc(0x480);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00410180 = 0x20;
  DAT_00410080 = puVar1;
  if (puVar1 < puVar1 + 0x120) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 9;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1[2] = 0;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00410080 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar4 = *(UINT *)local_44.lpReserved2;
    pUVar3 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar7 = (byte *)(UVar4 + (int)pUVar3);
    if (0x7ff < (int)UVar4) {
      UVar4 = 0x800;
    }
    UVar5 = UVar4;
    if ((int)DAT_00410180 < (int)UVar4) {
      piVar9 = &DAT_00410084;
      do {
        puVar1 = _malloc(0x480);
        UVar5 = DAT_00410180;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar9 = (int)puVar1;
        DAT_00410180 = DAT_00410180 + 0x20;
        if (puVar1 < puVar1 + 0x120) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar6 = puVar1 + 9;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1[2] = 0;
            puVar1 = puVar6;
          } while (puVar6 < (undefined4 *)(*piVar9 + 0x480));
        }
        piVar9 = piVar9 + 1;
        UVar5 = UVar4;
      } while ((int)DAT_00410180 < (int)UVar4);
    }
    uVar10 = 0;
    if (0 < (int)UVar5) {
      do {
        if (((*(HANDLE *)pbVar7 != (HANDLE)0xffffffff) && ((*pUVar3 & 1) != 0)) &&
           (((*pUVar3 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar7), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   ((uVar10 & 0x1f) * 0x24 +
                   *(int *)((int)&DAT_00410080 + ((int)(uVar10 & 0xffffffe7) >> 3)));
          *puVar1 = *(undefined4 *)pbVar7;
          *(byte *)(puVar1 + 1) = (byte)*pUVar3;
        }
        uVar10 = uVar10 + 1;
        pUVar3 = (UINT *)((int)pUVar3 + 1);
        pbVar7 = pbVar7 + 4;
      } while ((int)uVar10 < (int)UVar5);
    }
  }
  iVar8 = 0;
  iVar11 = 0;
  do {
    piVar9 = (int *)((int)DAT_00410080 + iVar8);
    if (*piVar9 == -1) {
      DVar2 = 0xfffffff6;
      *(undefined1 *)(piVar9 + 1) = 0x81;
      if (iVar8 != 0) {
        DVar2 = (iVar11 == 1) - 0xc;
      }
      hFile = GetStdHandle(DVar2);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
      }
      else {
        *piVar9 = (int)hFile;
        if ((DVar2 & 0xff) == 2) {
          *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
        }
        else if ((DVar2 & 0xff) == 3) {
          *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x80;
    }
    iVar8 = iVar8 + 0x24;
    iVar11 = iVar11 + 1;
  } while (iVar8 < 0x6c);
  UVar4 = SetHandleCount(DAT_00410180);
  return UVar4;
}


// ==== __mtinit @ 00404800

/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinit(void)

{
  _ptiddata _Ptd;
  BOOL BVar1;
  DWORD DVar2;
  pthreadlocinfo unaff_ESI;
  
  __mtinitlocks();
  DAT_0040cd84 = TlsAlloc();
  if (DAT_0040cd84 == 0xffffffff) {
    return 0;
  }
  _Ptd = _calloc(1,0x74);
  if (_Ptd != (_ptiddata)0x0) {
    BVar1 = TlsSetValue(DAT_0040cd84,_Ptd);
    if (BVar1 != 0) {
      __initptd(_Ptd,unaff_ESI);
      DVar2 = GetCurrentThreadId();
      _Ptd->_tid = DVar2;
      _Ptd->_thandle = 0xffffffff;
      return 1;
    }
  }
  return 0;
}


// ==== __initptd @ 00404860

/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 1998 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  *(undefined **)(_Ptd->_con_ch_buf + 4) = &DAT_0040cab8;
  _Ptd->_holdrand = 1;
  return;
}


// ==== __getptd @ 00404880

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 1998 Release */

_ptiddata __cdecl __getptd(void)

{
  DWORD dwErrCode;
  _ptiddata _Ptd;
  BOOL BVar1;
  DWORD DVar2;
  pthreadlocinfo unaff_EDI;
  
  dwErrCode = GetLastError();
  _Ptd = TlsGetValue(DAT_0040cd84);
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = _calloc(1,0x74);
    if (_Ptd != (_ptiddata)0x0) {
      BVar1 = TlsSetValue(DAT_0040cd84,_Ptd);
      if (BVar1 != 0) {
        __initptd(_Ptd,unaff_EDI);
        DVar2 = GetCurrentThreadId();
        _Ptd->_tid = DVar2;
        _Ptd->_thandle = 0xffffffff;
        goto LAB_004048e3;
      }
    }
    __amsg_exit(0x10);
  }
LAB_004048e3:
  SetLastError(dwErrCode);
  return _Ptd;
}


// ==== __heap_init @ 004048f0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_00410074 = HeapCreate(0,0x1000,0);
  if (DAT_00410074 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_00410074);
    return 0;
  }
  return 1;
}


// ==== FUN_004049f1 @ 004049f1

void FUN_004049f1(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 00404a10

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0040c5f8 == 1) || ((DAT_0040c5f8 == 0 && (DAT_0040c5fc == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0040ce20 != (code *)0x0) {
      (*DAT_0040ce20)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00404a50

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
  piVar2 = &DAT_0040cd90;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_0040ce20);
  if ((&DAT_0040cd90)[iVar4 * 2] == param_1) {
    if ((DAT_0040c5f8 == 1) || ((DAT_0040c5f8 == 0 && (DAT_0040c5fc == 1)))) {
      if ((DAT_00410080 == 0) ||
         (hFile = *(HANDLE *)(DAT_00410080 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x40cd94);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x40cd94);
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


// ==== __callnewh @ 00404c50

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_0040efa4 != (code *)0x0) {
    iVar1 = (*DAT_0040efa4)(_Size);
    if (iVar1 != 0) {
      FUN_00403220(9);
      return 1;
    }
  }
  FUN_00403220(9);
  return 0;
}


// ==== ___sbh_new_region @ 00404c90

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
  
  if (DAT_0040d638 == 0) {
    lpMem = &PTR_LOOP_0040ce28;
  }
  else {
    lpMem = HeapAlloc(DAT_00410074,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_0040ce28) {
        if (PTR_LOOP_0040ce28 == (undefined *)0x0) {
          PTR_LOOP_0040ce28 = (undefined *)&PTR_LOOP_0040ce28;
        }
        if (PTR_LOOP_0040ce2c == (undefined *)0x0) {
          PTR_LOOP_0040ce2c = (undefined *)&PTR_LOOP_0040ce28;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_0040ce28;
        lpMem[1] = PTR_LOOP_0040ce2c;
        PTR_LOOP_0040ce2c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_0040ce28) {
    HeapFree(DAT_00410074,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 00404e00

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0040d63c == param_1) {
    PTR_LOOP_0040d63c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_0040ce28) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00410074,0,param_1);
    return;
  }
  DAT_0040d638 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 00404e60

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
  
  ppuVar4 = (undefined **)PTR_LOOP_0040ce2c;
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
            DAT_0040d640 = DAT_0040d640 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_0040ce2c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 00404f40

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_0040ce28;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_0040ce28) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 00404fa0

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_free_block(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = param_1 + (param_2 - *(int *)(param_1 + 0x810) >> 0xc);
  *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + *param_3;
  *param_3 = '\0';
  *(undefined1 *)(iVar1 + 0x410) = 0xf1;
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_0040d640 = DAT_0040d640 + 1, DAT_0040d640 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00404ff0

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Release */

undefined * __cdecl ___sbh_alloc_block(uint param_1)

{
  undefined *puVar1;
  char *pcVar2;
  byte bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  undefined **ppuVar11;
  int iVar12;
  undefined *puVar13;
  
  piVar10 = (int *)PTR_LOOP_0040d63c;
  do {
    cVar8 = (char)param_1;
    if (piVar10[0x204] != 0) {
      iVar12 = piVar10[2];
      if (iVar12 < 0x400) {
        iVar9 = iVar12 << 0xc;
        do {
          bVar3 = *(byte *)(iVar12 + 0x10 + (int)piVar10);
          if (((param_1 <= bVar3) && (bVar3 != 0xff)) &&
             (param_1 < *(byte *)(iVar12 + 0x410 + (int)piVar10))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar10[0x204] + iVar9),(uint)bVar3,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar2 = (char *)(iVar12 + 0x10 + (int)piVar10);
              PTR_LOOP_0040d63c = (undefined *)piVar10;
              *pcVar2 = *pcVar2 - cVar8;
              piVar10[2] = iVar12;
              return puVar6;
            }
            *(char *)(iVar12 + 0x410 + (int)piVar10) = cVar8;
          }
          iVar9 = iVar9 + 0x1000;
          iVar12 = iVar12 + 1;
        } while (iVar9 < 0x400000);
      }
      iVar12 = 0;
      iVar9 = 0;
      if (0 < piVar10[2]) {
        do {
          bVar3 = *(byte *)(iVar9 + 0x10 + (int)piVar10);
          if (((param_1 <= bVar3) && (bVar3 != 0xff)) &&
             (param_1 < *(byte *)(iVar9 + 0x410 + (int)piVar10))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar10[0x204] + iVar12),(uint)bVar3,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar2 = (char *)(iVar9 + 0x10 + (int)piVar10);
              PTR_LOOP_0040d63c = (undefined *)piVar10;
              *pcVar2 = *pcVar2 - cVar8;
              piVar10[2] = iVar9;
              return puVar6;
            }
            *(char *)(iVar9 + 0x410 + (int)piVar10) = cVar8;
          }
          iVar12 = iVar12 + 0x1000;
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar10[2]);
      }
    }
    piVar10 = (int *)*piVar10;
  } while (piVar10 != (int *)PTR_LOOP_0040d63c);
  ppuVar11 = &PTR_LOOP_0040ce28;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_0040ce28) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_0040d63c = (undefined *)ppuVar11;
      *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
      puVar7[1] = 0xf0 - param_1;
      *(char *)(ppuVar11 + 4) = *(char *)(ppuVar11 + 4) - cVar8;
      return ppuVar11[0x204] + 0x100;
    }
  }
  puVar4 = ppuVar11[3];
  puVar6 = puVar4 + 0x10;
  puVar5 = puVar4;
  if (0x3ff < (int)puVar6) {
    puVar6 = (undefined *)0x400;
  }
  do {
    puVar13 = puVar5 + 1;
    if ((int)puVar6 <= (int)puVar13) break;
    puVar1 = puVar5 + 0x11;
    puVar5 = puVar13;
  } while (puVar1[(int)ppuVar11] == -1);
  puVar6 = VirtualAlloc(ppuVar11[0x204] + (int)puVar4 * 0x1000,((int)puVar13 - (int)puVar4) * 0x1000
                        ,0x1000,4);
  if (puVar6 != ppuVar11[0x204] + (int)puVar4 * 0x1000) {
    return (undefined *)0x0;
  }
  puVar6 = ppuVar11[3];
  piVar10 = (int *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  for (; (int)puVar6 < (int)puVar13; puVar6 = puVar6 + 1) {
    *piVar10 = (int)(piVar10 + 2);
    piVar10[1] = 0xf0;
    *(undefined1 *)(piVar10 + 0x3e) = 0xff;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x10)) = 0xf0;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x410)) = 0xf1;
    piVar10 = piVar10 + 0x400;
  }
  for (; ((int)puVar13 < 0x400 && ((puVar13 + 0x10)[(int)ppuVar11] != -1)); puVar13 = puVar13 + 1) {
  }
  puVar6 = ppuVar11[3];
  PTR_LOOP_0040d63c = (undefined *)ppuVar11;
  ppuVar11[3] = (undefined *)0xffffffff;
  if ((int)puVar13 < 0x400) {
    ppuVar11[3] = puVar13;
  }
  puVar7 = (undefined4 *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  *(char *)(puVar7 + 2) = cVar8;
  ppuVar11[2] = puVar6;
  (puVar6 + 0x10)[(int)ppuVar11] = (puVar6 + 0x10)[(int)ppuVar11] - cVar8;
  *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
  puVar7[1] = puVar7[1] - param_1;
  return ppuVar11[0x204] + (int)puVar6 * 0x1000 + 0x100;
}


// ==== ___sbh_alloc_block_from_page @ 00405270

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


// ==== __write @ 004053f0

/* Library Function - Single Match
    __write
   
   Library: Visual Studio 1998 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_00410180) &&
     ((*(byte *)(*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 0x24) & 1) != 0)) {
    __lock_fhandle(_FileHandle);
    iVar1 = __write_lk(_FileHandle,_Buf,_MaxCharCount);
    __unlock_fhandle(_FileHandle);
    return iVar1;
  }
  piVar2 = FUN_00403160();
  *piVar2 = 9;
  puVar3 = FUN_00403170();
  *puVar3 = 0;
  return -1;
}


// ==== __write_lk @ 00405470

/* Library Function - Single Match
    __write_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __write_lk(uint param_1,char *param_2,uint param_3)

{
  char cVar1;
  BOOL BVar2;
  int *piVar3;
  ulong *puVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  ulong local_418;
  DWORD local_414;
  int *local_410;
  int local_40c;
  DWORD local_408;
  char local_404 [1028];
  
  iVar7 = 0;
  local_408 = 0;
  if (param_3 == 0) {
    return 0;
  }
  local_410 = (int *)((int)&DAT_00410080 + ((int)(param_1 & 0xffffffe7) >> 3));
  local_40c = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)(*local_410 + 4 + local_40c) & 0x20) != 0) {
    __lseek_lk(param_1,0,2);
  }
  if ((*(byte *)((undefined4 *)(local_40c + *local_410) + 1) & 0x80) == 0) {
    BVar2 = WriteFile(*(HANDLE *)(local_40c + *local_410),param_2,param_3,&local_414,
                      (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
LAB_004055a4:
      local_418 = GetLastError();
    }
    else {
      local_418 = 0;
      local_408 = local_414;
    }
  }
  else {
    local_418 = 0;
    pcVar5 = param_2;
    do {
      if (param_3 <= (uint)((int)pcVar5 - (int)param_2)) break;
      pcVar6 = local_404;
      do {
        if (param_3 <= (uint)((int)pcVar5 - (int)param_2)) break;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        if (cVar1 == '\n') {
          *pcVar6 = '\r';
          iVar7 = iVar7 + 1;
          pcVar6 = pcVar6 + 1;
        }
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + 1;
      } while ((int)pcVar6 - (int)local_404 < 0x400);
      BVar2 = WriteFile(*(HANDLE *)(*local_410 + local_40c),local_404,(int)pcVar6 - (int)local_404,
                        &local_414,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) goto LAB_004055a4;
      local_408 = local_408 + local_414;
    } while ((int)pcVar6 - (int)local_404 <= (int)local_414);
  }
  if (local_408 != 0) {
    return local_408 - iVar7;
  }
  if (local_418 == 0) {
    if (((*(byte *)(*local_410 + 4 + local_40c) & 0x40) != 0) && (*param_2 == '\x1a')) {
      return 0;
    }
    piVar3 = FUN_00403160();
    *piVar3 = 0x1c;
    puVar4 = FUN_00403170();
    *puVar4 = 0;
    return -1;
  }
  if (local_418 != 5) {
    __dosmaperr(local_418);
    return -1;
  }
  piVar3 = FUN_00403160();
  *piVar3 = 9;
  puVar4 = FUN_00403170();
  *puVar4 = 5;
  return -1;
}


// ==== __lseek @ 00405670

/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 1998 Release */

long __cdecl __lseek(int _FileHandle,long _Offset,int _Origin)

{
  DWORD DVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_00410180) &&
     ((*(byte *)(*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 0x24) & 1) != 0)) {
    __lock_fhandle(_FileHandle);
    DVar1 = __lseek_lk(_FileHandle,_Offset,_Origin);
    __unlock_fhandle(_FileHandle);
    return DVar1;
  }
  piVar2 = FUN_00403160();
  *piVar2 = 9;
  puVar3 = FUN_00403170();
  *puVar3 = 0;
  return -1;
}


// ==== __lseek_lk @ 004056f0

/* Library Function - Single Match
    __lseek_lk
   
   Library: Visual Studio 1998 Release */

DWORD __cdecl __lseek_lk(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  int *piVar2;
  DWORD DVar3;
  ulong uVar4;
  
  hFile = (HANDLE)__get_osfhandle(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    piVar2 = FUN_00403160();
    *piVar2 = 9;
    return 0xffffffff;
  }
  DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
  uVar4 = 0;
  if (DVar3 == 0xffffffff) {
    uVar4 = GetLastError();
  }
  if (uVar4 != 0) {
    __dosmaperr(uVar4);
    return 0xffffffff;
  }
  pbVar1 = (byte *)(*(int *)((int)&DAT_00410080 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                   (param_1 & 0x1f) * 0x24);
  *pbVar1 = *pbVar1 & 0xfd;
  return DVar3;
}


// ==== __getbuf @ 00405780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_0040d8c8 = _DAT_0040d8c8 + 1;
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


// ==== __isatty @ 004057d0

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Release */

int __cdecl __isatty(int _FileHandle)

{
  if (DAT_00410180 <= (uint)_FileHandle) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                  (_FileHandle & 0x1fU) * 0x24) & 0x40;
}


// ==== _wctomb @ 004058f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = DAT_0040f064 == 0;
  if (bVar2) {
    _DAT_0040f068 = _DAT_0040f068 + 1;
  }
  else {
    __lock(0x13);
  }
  iVar1 = __wctomb_lk(_MbCh,_WCh);
  if (!bVar2) {
    FUN_00403220(0x13);
    return iVar1;
  }
  _DAT_0040f068 = _DAT_0040f068 + -1;
  return iVar1;
}


// ==== __wctomb_lk @ 00405950

/* Library Function - Single Match
    __wctomb_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __wctomb_lk(LPSTR param_1,WCHAR param_2)

{
  int *piVar1;
  int iVar2;
  BOOL local_4;
  
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_0040da48 == 0) {
    if (0xff < (ushort)param_2) {
      piVar1 = FUN_00403160();
      *piVar1 = 0x2a;
      return -1;
    }
    *param_1 = (CHAR)param_2;
    return 1;
  }
  local_4 = 0;
  iVar2 = WideCharToMultiByte(DAT_0040da58,0x220,&param_2,1,param_1,DAT_0040ca54,(LPCSTR)0x0,
                              &local_4);
  if ((iVar2 == 0) || (local_4 != 0)) {
    piVar1 = FUN_00403160();
    *piVar1 = 0x2a;
    iVar2 = -1;
  }
  return iVar2;
}


// ==== __aulldiv @ 004059f0

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


// ==== __aullrem @ 00405a60

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


// ==== ___crtLCMapStringA @ 00405af0

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
  
  if (DAT_0040da60 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0040da60 = 1;
    }
    else {
      DAT_0040da60 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_0040da60 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_0040da60 != 1) {
    return DAT_0040da60;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_0040da58;
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
                               iVar2), iVar1 == 0)) goto LAB_00405c6b;
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
      if (_LpDestStr == (LPSTR)0x0) goto LAB_00405d02;
      if ((int)_LpDestStr < iVar2) goto LAB_00405c6b;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_00405d02:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_00405c6b:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 00405d20

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
    if (*pcVar2 == '\0') goto LAB_00405d45;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_00405d45:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== _free @ 00405d50

/* Library Function - Single Match
    _free
   
   Library: Visual Studio 1998 Release */

void __cdecl _free(void *_Memory)

{
  char *pcVar1;
  uint local_8;
  int local_4;
  
  if (_Memory != (void *)0x0) {
    __lock(9);
    pcVar1 = (char *)___sbh_find_block(_Memory,&local_4,&local_8);
    if (pcVar1 != (char *)0x0) {
      ___sbh_free_block(local_4,local_8,pcVar1);
      FUN_00403220(9);
      return;
    }
    FUN_00403220(9);
    HeapFree(DAT_00410074,0,_Memory);
  }
  return;
}


// ==== __control87 @ 00405dc0

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 1998 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  uint uVar1;
  ushort in_FPUControlWord;
  
  uVar1 = __abstract_cw(in_FPUControlWord);
  __hw_cw();
  return ~_Mask & uVar1 | _Mask & _NewValue;
}


// ==== __controlfp @ 00405e00

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== __abstract_cw @ 00405e20

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


// ==== __hw_cw @ 00405ed0

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}


// ==== FUN_00405f60 @ 00405f60

void FUN_00405f60(void)

{
  __amsg_exit(2);
  return;
}


// ==== _tolower @ 00405f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl _tolower(int _C)

{
  bool bVar1;
  
  if (DAT_0040da48 == 0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      return _C + 0x20;
    }
  }
  else {
    bVar1 = DAT_0040f064 == 0;
    if (bVar1) {
      _DAT_0040f068 = _DAT_0040f068 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __tolower_lk(_C);
    if (!bVar1) {
      FUN_00403220(0x13);
      return _C;
    }
    _DAT_0040f068 = _DAT_0040f068 + -1;
  }
  return _C;
}


// ==== __tolower_lk @ 00405fe0

/* Library Function - Single Match
    __tolower_lk
   
   Library: Visual Studio 1998 Release */

uint __cdecl __tolower_lk(uint param_1)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_0040da48 == (_locale_t)0x0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      param_1 = param_1 + 0x20;
    }
    return param_1;
  }
  if ((int)param_1 < 0x100) {
    if (DAT_0040ca54 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_0040c848 + param_1 * 2) & 1;
    }
    else {
      uVar1 = __isctype(param_1,1);
    }
    if (uVar1 == 0) {
      return param_1;
    }
  }
  local_4 = (byte)(param_1 >> 8);
  if ((PTR_DAT_0040c848[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)param_1;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)param_1;
  }
  iVar2 = ___crtLCMapStringA(DAT_0040da48,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return param_1;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __ZeroTail @ 004060d0

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


// ==== __IncMan @ 00406140

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


// ==== __RoundMan @ 004061b0

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


// ==== __CopyMan @ 00406260

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


// ==== __FillZeroMan @ 00406280

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


// ==== __IsZeroMan @ 00406290

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


// ==== __ShrMan @ 004062b0

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


// ==== __ld12cvt @ 00406360

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


// ==== FID_conflict:__ld12tod @ 00406530

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0040da68);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 00406550

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_0040da80);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 00406570

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


// ==== FID_conflict:__atodbl @ 004065b0

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


// ==== __fptostr @ 004065f0

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


// ==== __fltout2 @ 00406680

/* Library Function - Single Match
    __fltout2
   
   Library: Visual Studio 1998 Release */

STRFLT __cdecl __fltout2(_CRT_DOUBLE _Dbl,STRFLT _Flt,char *_ResultStr,size_t _SizeInBytes)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint local_28;
  uint local_24;
  ushort local_20;
  short local_1c;
  char local_1a;
  char local_18 [24];
  
  ___dtold(&local_28,(uint *)&_Dbl);
  iVar2 = _I10_OUTPUT(local_28,local_24,local_20,0x11,0,&local_1c);
  _Flt->flag = iVar2;
  _Flt->sign = (int)local_1a;
  _Flt->decpt = (int)local_1c;
  uVar3 = 0xffffffff;
  pcVar5 = local_18;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = _ResultStr;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  _Flt->mantissa = _ResultStr;
  return _Flt;
}


// ==== ___dtold @ 00406710

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


// ==== FID_conflict:_memcpy @ 004067d0

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
switchD_00406899_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_00406899_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_00406899_caseD_3:
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
        goto switchD_00406899_caseD_1;
      case 2:
        goto switchD_00406899_caseD_2;
      case 3:
        goto switchD_00406899_caseD_3;
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
switchD_00406800_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_00406800_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_00406800_caseD_3:
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
      goto switchD_00406800_caseD_1;
    case 2:
      goto switchD_00406800_caseD_2;
    case 3:
      goto switchD_00406800_caseD_3;
    }
  }
  return _Dst;
}


// ==== ___crtGetStringTypeW @ 00406920

/* Library Function - Single Match
    ___crtGetStringTypeW
   
   Library: Visual Studio 1998 Release */

BOOL __cdecl
___crtGetStringTypeW
          (DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  LPWORD pWVar1;
  BOOL in_EAX;
  BOOL BVar2;
  size_t _Size;
  LPCSTR lpMultiByteStr;
  int iVar3;
  LPWORD lpCharType;
  BOOL local_4;
  
  local_4 = in_EAX;
  if (DAT_0040daa0 == 0) {
    local_4 = GetStringTypeW(1,L"",1,(LPWORD)&local_4);
    if (local_4 == 0) {
      local_4 = GetStringTypeA(0,1,"",1,(LPWORD)&local_4);
      if (local_4 == 0) {
        return 0;
      }
      DAT_0040daa0 = 2;
    }
    else {
      DAT_0040daa0 = 1;
    }
  }
  if (DAT_0040daa0 != 1) {
    if (DAT_0040daa0 == 2) {
      lpCharType = (LPWORD)0x0;
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = DAT_0040da58;
      }
      _Size = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      if (_Size == 0) {
        return 0;
      }
      lpMultiByteStr = _calloc(1,_Size);
      if (lpMultiByteStr == (LPCSTR)0x0) {
        return 0;
      }
      iVar3 = WideCharToMultiByte(param_5,0x220,param_2,param_3,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if ((iVar3 != 0) && (lpCharType = _malloc(_Size * 2 + 2), lpCharType != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_0040da48;
        }
        pWVar1 = lpCharType + param_3;
        *pWVar1 = 0xffff;
        pWVar1[-1] = 0xffff;
        local_4 = GetStringTypeA(param_6,param_1,lpMultiByteStr,_Size,lpCharType);
        if ((pWVar1[-1] == 0xffff) || (*pWVar1 != 0xffff)) {
          local_4 = 0;
        }
        else {
          FID_conflict__memcpy(param_4,lpCharType,param_3 * 2);
        }
      }
      _free(lpMultiByteStr);
      _free(lpCharType);
    }
    return local_4;
  }
  BVar2 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return BVar2;
}


// ==== ___crtGetStringTypeA @ 00406ae0

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
  
  iVar2 = DAT_0040daa4;
  if (DAT_0040daa4 == 0) {
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
  DAT_0040daa4 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_0040da58;
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
    _Code_page = DAT_0040da48;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== _calloc @ 00406c10

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
      if (DAT_0040d644 < dwBytes) {
LAB_00406c82:
        if (puVar3 != (undefined4 *)0x0) {
          return puVar3;
        }
      }
      else {
        __lock(9);
        puVar3 = (undefined4 *)___sbh_alloc_block(dwBytes >> 4);
        FUN_00403220(9);
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
          goto LAB_00406c82;
        }
      }
      puVar3 = HeapAlloc(DAT_00410074,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_0040ce24 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== ___crtMessageBoxA @ 00406cc0

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0040daa8 != (FARPROC)0x0) {
LAB_00406d0f:
    if (DAT_0040daac != (FARPROC)0x0) {
      iVar1 = (*DAT_0040daac)();
    }
    if ((iVar1 != 0) && (DAT_0040dab0 != (FARPROC)0x0)) {
      iVar1 = (*DAT_0040dab0)(iVar1);
    }
    iVar1 = (*DAT_0040daa8)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0040daa8 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0040daa8 != (FARPROC)0x0) {
      DAT_0040daac = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0040dab0 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00406d0f;
    }
  }
  return 0;
}


// ==== _strncpy @ 00406d60

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
        goto joined_r0x00406d9e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00406ddb;
        goto LAB_00406e49;
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
joined_r0x00406e45:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00406e49:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00406ddb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00406e45;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00406e45;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00406e45;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00406d9e:
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
LAB_00406ddb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== __free_osfhnd @ 00406e60

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  ulong *puVar4;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00410180) {
    piVar3 = (int *)((int)&DAT_00410080 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar1 = (param_1 & 0x1fU) * 0x24;
    piVar2 = (int *)(*piVar3 + iVar1);
    if (((*(byte *)(piVar2 + 1) & 1) != 0) && (*piVar2 != -1)) {
      if (DAT_0040c5fc == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00406ec5;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00406ec5:
      *(undefined4 *)(*piVar3 + iVar1) = 0xffffffff;
      return 0;
    }
  }
  piVar3 = FUN_00403160();
  *piVar3 = 9;
  puVar4 = FUN_00403170();
  *puVar4 = 0;
  return -1;
}


// ==== __get_osfhandle @ 00406f00

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_00410180) &&
     (piVar1 = (intptr_t *)
               (*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) +
               (_FileHandle & 0x1fU) * 0x24), (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  piVar2 = FUN_00403160();
  *piVar2 = 9;
  puVar3 = FUN_00403170();
  *puVar3 = 0;
  return -1;
}


// ==== __lock_fhandle @ 00406f50

/* Library Function - Single Match
    __lock_fhandle
   
   Library: Visual Studio 1998 Release */

int __cdecl __lock_fhandle(int _Filehandle)

{
  int *piVar1;
  int iVar2;
  int extraout_EAX;
  int iVar3;
  
  piVar1 = (int *)((int)&DAT_00410080 + ((int)(_Filehandle & 0xffffffe7U) >> 3));
  iVar2 = (_Filehandle & 0x1fU) * 0x24;
  iVar3 = *piVar1 + iVar2;
  if (*(int *)(iVar3 + 8) == 0) {
    __lock(0x11);
    if (*(int *)(iVar3 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0xc));
      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
    }
    FUN_00403220(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(*piVar1 + iVar2 + 0xc));
  return extraout_EAX;
}


// ==== __unlock_fhandle @ 00406fc0

/* Library Function - Single Match
    __unlock_fhandle
   
   Library: Visual Studio 1998 Release */

void __cdecl __unlock_fhandle(int _Filehandle)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             (*(int *)((int)&DAT_00410080 + ((int)(_Filehandle & 0xffffffe7U) >> 3)) +
              (_Filehandle & 0x1fU) * 0x24 + 0xc));
  return;
}


// ==== __fcloseall @ 00406ff0

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
  
  iVar2 = 0;
  iVar3 = 3;
  __lock(2);
  if (3 < DAT_00410070) {
    iVar4 = 0xc;
    do {
      _File = *(FILE **)(DAT_0040f06c + iVar4);
      if (_File != (FILE *)0x0) {
        if ((_File->_flag & 0x83) != 0) {
          iVar1 = _fclose(_File);
          if (iVar1 != -1) {
            iVar2 = iVar2 + 1;
          }
        }
        if (0x4f < iVar4) {
          DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_0040f06c + iVar4) + 0x20));
          _free(*(void **)(DAT_0040f06c + iVar4));
          *(undefined4 *)(DAT_0040f06c + iVar4) = 0;
        }
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00410070);
  }
  FUN_00403220(2);
  return iVar2;
}


// ==== __fflush_lk @ 00407090

/* Library Function - Single Match
    __fflush_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __fflush_lk(FILE *param_1)

{
  int iVar1;
  
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((param_1->_flag & 0x4000) != 0) {
    iVar1 = __commit(param_1->_file);
    return (iVar1 == 0) - 1;
  }
  return 0;
}


// ==== __flush @ 004070d0

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


// ==== flsall @ 00407150

/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int _Index;
  int local_4;
  
  iVar3 = 0;
  _Index = 0;
  local_4 = 0;
  __lock(2);
  if (0 < DAT_00410070) {
    iVar4 = 0;
    do {
      _File = *(void **)(DAT_0040f06c + iVar4);
      if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
        FID_conflict___lock_file2(_Index,_File);
        pFVar1 = *(FILE **)(DAT_0040f06c + iVar4);
        if ((pFVar1->_flag & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = __fflush_lk(pFVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if (((param_1 == 0) && ((pFVar1->_flag & 2U) != 0)) &&
                  (iVar2 = __fflush_lk(pFVar1), iVar2 == -1)) {
            local_4 = -1;
          }
        }
        FID_conflict___lock_file2(_Index,*(void **)(DAT_0040f06c + iVar4));
      }
      iVar4 = iVar4 + 4;
      _Index = _Index + 1;
    } while (_Index < DAT_00410070);
  }
  FUN_00403220(2);
  if (param_1 != 1) {
    iVar3 = local_4;
  }
  return iVar3;
}


// ==== __get_lc_time @ 004072d0

/* Library Function - Single Match
    __get_lc_time
   
   Library: Visual Studio 1998 Release */

uint __cdecl __get_lc_time(LCTYPE param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  void *unaff_EBP;
  
  uVar43 = (uint)DAT_0040db00;
  uVar40 = (uint)DAT_0040dafe;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x31,param_1 + 4,unaff_EBP);
  uVar2 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x32,param_1 + 8,unaff_EBP);
  uVar3 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x33,param_1 + 0xc,unaff_EBP);
  uVar4 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x34,param_1 + 0x10,unaff_EBP);
  uVar5 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x35,param_1 + 0x14,unaff_EBP);
  uVar6 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x36,param_1 + 0x18,unaff_EBP);
  uVar7 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x37,param_1,unaff_EBP);
  uVar8 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2a,param_1 + 0x20,unaff_EBP);
  uVar9 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2b,param_1 + 0x24,unaff_EBP);
  uVar10 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2c,param_1 + 0x28,unaff_EBP);
  uVar11 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2d,param_1 + 0x2c,unaff_EBP);
  uVar12 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2e,param_1 + 0x30,unaff_EBP);
  uVar13 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x2f,param_1 + 0x34,unaff_EBP);
  uVar14 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x30,param_1 + 0x1c,unaff_EBP);
  uVar15 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x44,param_1 + 0x38,unaff_EBP);
  uVar16 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x45,param_1 + 0x3c,unaff_EBP);
  uVar17 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x46,param_1 + 0x40,unaff_EBP);
  uVar18 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x47,param_1 + 0x44,unaff_EBP);
  uVar19 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x48,param_1 + 0x48,unaff_EBP);
  uVar20 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x49,param_1 + 0x4c,unaff_EBP);
  uVar21 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4a,param_1 + 0x50,unaff_EBP);
  uVar22 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4b,param_1 + 0x54,unaff_EBP);
  uVar23 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4c,param_1 + 0x58,unaff_EBP);
  uVar24 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4d,param_1 + 0x5c,unaff_EBP);
  uVar25 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4e,param_1 + 0x60,unaff_EBP);
  uVar26 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x4f,param_1 + 100,unaff_EBP);
  uVar27 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x38,param_1 + 0x68,unaff_EBP);
  uVar28 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x39,param_1 + 0x6c,unaff_EBP);
  uVar29 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3a,param_1 + 0x70,unaff_EBP);
  uVar30 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3b,param_1 + 0x74,unaff_EBP);
  uVar31 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3c,param_1 + 0x78,unaff_EBP);
  uVar32 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3d,param_1 + 0x7c,unaff_EBP);
  uVar33 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3e,param_1 + 0x80,unaff_EBP);
  uVar34 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x3f,param_1 + 0x84,unaff_EBP);
  uVar35 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x40,param_1 + 0x88,unaff_EBP);
  uVar36 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x41,param_1 + 0x8c,unaff_EBP);
  uVar37 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x42,param_1 + 0x90,unaff_EBP);
  uVar38 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x43,param_1 + 0x94,unaff_EBP);
  uVar39 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x28,param_1 + 0x98,unaff_EBP);
  uVar40 = ___getlocaleinfo((_locale_t)0x1,uVar40,(LPCWSTR)0x29,param_1 + 0x9c,unaff_EBP);
  uVar41 = ___getlocaleinfo((_locale_t)0x1,uVar43,(LPCWSTR)0x1f,param_1 + 0xa0,unaff_EBP);
  uVar42 = ___getlocaleinfo((_locale_t)0x1,uVar43,(LPCWSTR)0x20,param_1 + 0xa4,unaff_EBP);
  uVar43 = storeTimeFmt(uVar43,param_1);
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
         uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 |
         uVar32 | uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 |
         uVar42 | uVar43;
}


// ==== FUN_00407650 @ 00407650

void __cdecl FUN_00407650(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    _free((void *)param_1[1]);
    _free((void *)param_1[2]);
    _free((void *)param_1[3]);
    _free((void *)param_1[4]);
    _free((void *)param_1[5]);
    _free((void *)param_1[6]);
    _free((void *)*param_1);
    _free((void *)param_1[8]);
    _free((void *)param_1[9]);
    _free((void *)param_1[10]);
    _free((void *)param_1[0xb]);
    _free((void *)param_1[0xc]);
    _free((void *)param_1[0xd]);
    _free((void *)param_1[7]);
    _free((void *)param_1[0xe]);
    _free((void *)param_1[0xf]);
    _free((void *)param_1[0x10]);
    _free((void *)param_1[0x11]);
    _free((void *)param_1[0x12]);
    _free((void *)param_1[0x13]);
    _free((void *)param_1[0x14]);
    _free((void *)param_1[0x15]);
    _free((void *)param_1[0x16]);
    _free((void *)param_1[0x17]);
    _free((void *)param_1[0x18]);
    _free((void *)param_1[0x19]);
    _free((void *)param_1[0x1a]);
    _free((void *)param_1[0x1b]);
    _free((void *)param_1[0x1c]);
    _free((void *)param_1[0x1d]);
    _free((void *)param_1[0x1e]);
    _free((void *)param_1[0x1f]);
    _free((void *)param_1[0x20]);
    _free((void *)param_1[0x21]);
    _free((void *)param_1[0x22]);
    _free((void *)param_1[0x23]);
    _free((void *)param_1[0x24]);
    _free((void *)param_1[0x25]);
    _free((void *)param_1[0x26]);
    _free((void *)param_1[0x27]);
    _free((void *)param_1[0x28]);
    _free((void *)param_1[0x29]);
    _free((void *)param_1[0x2a]);
  }
  return;
}


// ==== storeTimeFmt @ 00407890

/* Library Function - Single Match
    _storeTimeFmt
   
   Library: Visual Studio 1998 Release */

uint __cdecl storeTimeFmt(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  void *unaff_EDI;
  char *local_c;
  int local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  uVar2 = ___getlocaleinfo((_locale_t)0x0,param_1,(LPCWSTR)0x23,(LCTYPE)&local_4,unaff_EDI);
  uVar3 = ___getlocaleinfo((_locale_t)0x0,param_1,(LPCWSTR)0x25,(LCTYPE)&local_8,unaff_EDI);
  uVar4 = ___getlocaleinfo((_locale_t)0x1,param_1,(LPCWSTR)0x1e,(LCTYPE)&local_c,unaff_EDI);
  uVar4 = uVar2 | uVar3 | uVar4;
  if (uVar4 != 0) {
    return uVar4;
  }
  puVar5 = _malloc(0xd);
  *(undefined1 **)(param_2 + 0xa8) = puVar5;
  if (local_4 == 0) {
    *puVar5 = 0x68;
    pcVar7 = puVar5 + 1;
    if (local_8 == 0) goto LAB_0040792b;
    *pcVar7 = 'h';
  }
  else {
    *puVar5 = 0x48;
    pcVar7 = puVar5 + 1;
    if (local_8 == 0) goto LAB_0040792b;
    *pcVar7 = 'H';
  }
  pcVar7 = puVar5 + 2;
LAB_0040792b:
  cVar1 = *local_c;
  pcVar6 = local_c;
  while (cVar1 != '\0') {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar6;
  }
  *pcVar7 = 'm';
  pcVar6 = pcVar7 + 1;
  if (local_8 != 0) {
    *pcVar6 = 'm';
    pcVar6 = pcVar7 + 2;
  }
  cVar1 = *local_c;
  pcVar7 = local_c;
  while (cVar1 != '\0') {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar7;
  }
  *pcVar6 = 's';
  pcVar6[1] = 's';
  pcVar6[2] = '\0';
  _free(local_c);
  return 0;
}


// ==== ___init_numeric @ 00407990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *unaff_EDI;
  uint _Lc_type;
  
  _Lc_type = (uint)DAT_0040dafa;
  if (DAT_0040da50 != 0) {
    iVar1 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,0x40dac4,unaff_EDI);
    iVar2 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,0x40dac8,unaff_EDI);
    iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,0x40dacc,unaff_EDI);
    fix_grouping(DAT_0040dacc);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      _free(DAT_0040dac4);
      _free(DAT_0040dac8);
      _free(DAT_0040dacc);
      DAT_0040dac4 = (void *)0x0;
      DAT_0040dac8 = (void *)0x0;
      DAT_0040dacc = (char *)0x0;
      return -1;
    }
    if (*(undefined **)PTR_PTR_0040e400 != &DAT_0040e3c8) {
      _free(*(undefined **)PTR_PTR_0040e400);
      _free(*(void **)(PTR_PTR_0040e400 + 4));
      _free(*(void **)(PTR_PTR_0040e400 + 8));
    }
    *(void **)PTR_PTR_0040e400 = DAT_0040dac4;
    *(void **)(PTR_PTR_0040e400 + 4) = DAT_0040dac8;
    *(char **)(PTR_PTR_0040e400 + 8) = DAT_0040dacc;
    _DAT_0040ca5c = 1;
    DAT_0040ca58 = **(undefined1 **)PTR_PTR_0040e400;
    return 0;
  }
  _free(DAT_0040dac4);
  _free(DAT_0040dac8);
  _free(DAT_0040dacc);
  DAT_0040dac4 = (void *)0x0;
  DAT_0040dac8 = (void *)0x0;
  DAT_0040dacc = (char *)0x0;
  pvVar4 = _malloc(2);
  *(void **)PTR_PTR_0040e400 = pvVar4;
  if (*(undefined2 **)PTR_PTR_0040e400 == (undefined2 *)0x0) {
    return -1;
  }
  **(undefined2 **)PTR_PTR_0040e400 = DAT_0040a410;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_0040e400 + 4) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_0040e400 + 4) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_0040e400 + 4) = 0;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_0040e400 + 8) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_0040e400 + 8) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_0040e400 + 8) = 0;
  _DAT_0040ca5c = 1;
  DAT_0040ca58 = **(undefined1 **)PTR_PTR_0040e400;
  return 0;
}


// ==== fix_grouping @ 00407bb0

/* Library Function - Single Match
    _fix_grouping
   
   Library: Visual Studio 1998 Release */

void __cdecl fix_grouping(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  cVar2 = *param_1;
  do {
    if (cVar2 == '\0') {
      return;
    }
    while( true ) {
      while ((cVar2 = *param_1, '/' < cVar2 && (cVar2 < ':'))) {
        *param_1 = cVar2 + -0x30;
        param_1 = param_1 + 1;
        if (*param_1 == '\0') {
          return;
        }
      }
      pcVar3 = param_1;
      if (cVar2 != ';') break;
      do {
        pcVar1 = pcVar3 + 1;
        *pcVar3 = *pcVar1;
        pcVar3 = pcVar1;
      } while (*pcVar1 != '\0');
      if (*param_1 == '\0') {
        return;
      }
    }
    param_1 = param_1 + 1;
    cVar2 = *param_1;
  } while( true );
}


// ==== ___init_ctype @ 00407f00

/* Library Function - Single Match
    ___init_ctype
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_ctype(threadlocinfo *_LocInfo)

{
  byte bVar1;
  int iVar2;
  undefined2 *_Memory;
  undefined2 *_Memory_00;
  BOOL BVar3;
  uint uVar4;
  undefined1 *puVar5;
  LPCWSTR pWVar6;
  undefined2 *puVar7;
  BYTE *pBVar8;
  void *unaff_EBP;
  undefined1 *_Memory_01;
  LPCWSTR local_18;
  _cpinfo local_14;
  
  _Memory_01 = (undefined1 *)0x0;
  local_18 = (LPCWSTR)0x0;
  if (DAT_0040da48 == 0) {
    PTR_DAT_0040c848 = &DAT_0040c852;
    PTR_DAT_0040c84c = &DAT_0040c852;
    _free(DAT_0040dad4);
    _free(DAT_0040dad8);
    DAT_0040dad4 = (undefined2 *)0x0;
    DAT_0040dad8 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_0040da58 != 0) ||
     (iVar2 = ___getlocaleinfo((_locale_t)0x0,(uint)DAT_0040daec,(LPCWSTR)0xb,0x40da58,unaff_EBP),
     _Memory_00 = (undefined2 *)local_14.MaxCharSize, _Memory = (undefined2 *)local_14.MaxCharSize,
     iVar2 == 0)) {
    _Memory = _malloc(0x202);
    _Memory_00 = _malloc(0x202);
    _Memory_01 = _malloc(0x101);
    local_18 = _malloc(0x202);
    if ((_Memory != (undefined2 *)0x0) &&
       (((_Memory_00 != (undefined2 *)0x0 && (_Memory_01 != (undefined1 *)0x0)) &&
        (local_18 != (LPCWSTR)0x0)))) {
      iVar2 = 0;
      puVar5 = _Memory_01;
      do {
        *puVar5 = (char)iVar2;
        puVar5 = puVar5 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x100);
      BVar3 = GetCPInfo(DAT_0040da58,&local_14);
      if ((BVar3 != 0) && (local_14.MaxCharSize < (undefined2 *)0x3)) {
        DAT_0040ca54 = local_14.MaxCharSize & 0xffff;
        if (1 < DAT_0040ca54) {
          pBVar8 = local_14.LeadByte;
          bVar1 = local_14.LeadByte[0];
          while ((bVar1 != 0 && (pBVar8[1] != 0))) {
            uVar4 = (uint)*pBVar8;
            if (uVar4 <= pBVar8[1]) {
              do {
                _Memory_01[uVar4] = 0;
                uVar4 = uVar4 + 1;
              } while ((int)uVar4 <= (int)(uint)pBVar8[1]);
            }
            pBVar8 = pBVar8 + 2;
            bVar1 = *pBVar8;
          }
        }
        BVar3 = ___crtGetStringTypeA
                          ((_locale_t)0x1,(DWORD)_Memory_01,(LPCSTR)0x100,(int)(_Memory + 1),
                           (LPWORD)0x0,0,(BOOL)unaff_EBP);
        if (BVar3 != 0) {
          *_Memory = 0;
          iVar2 = 0;
          pWVar6 = local_18;
          do {
            *pWVar6 = (WCHAR)iVar2;
            pWVar6 = pWVar6 + 1;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x100);
          BVar3 = ___crtGetStringTypeW(1,local_18,0x100,_Memory_00 + 1,0,0);
          if (BVar3 != 0) {
            *_Memory_00 = 0;
            if (1 < (int)DAT_0040ca54) {
              pBVar8 = local_14.LeadByte;
              while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
                uVar4 = (uint)*pBVar8;
                if (uVar4 <= pBVar8[1]) {
                  puVar7 = _Memory + uVar4 + 1;
                  do {
                    *puVar7 = 0x8000;
                    puVar7 = puVar7 + 1;
                    uVar4 = uVar4 + 1;
                  } while ((int)uVar4 <= (int)(uint)pBVar8[1]);
                }
                pBVar8 = pBVar8 + 2;
                local_14.LeadByte[0] = *pBVar8;
              }
            }
            PTR_DAT_0040c848 = (undefined *)(_Memory + 1);
            PTR_DAT_0040c84c = (undefined *)(_Memory_00 + 1);
            if (DAT_0040dad4 != (void *)0x0) {
              _free(DAT_0040dad4);
            }
            DAT_0040dad4 = _Memory;
            if (DAT_0040dad8 != (void *)0x0) {
              _free(DAT_0040dad8);
            }
            DAT_0040dad8 = _Memory_00;
            _free(_Memory_01);
            _free(local_18);
            return 0;
          }
        }
      }
    }
  }
  _free(_Memory);
  _free(_Memory_00);
  _free(_Memory_01);
  _free(local_18);
  return 1;
}


// ==== _strcspn @ 004081c0

/* Library Function - Single Match
    _strcspn
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}


// ==== _strncmp @ 00408200

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


// ==== _strpbrk @ 00408240

/* Library Function - Single Match
    _strpbrk
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}


// ==== ___addl @ 00408280

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


// ==== ___add_12 @ 004082b0

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


// ==== ___shl_12 @ 00408320

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


// ==== ___shr_12 @ 00408360

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


// ==== ___mtold12 @ 004083a0

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


// ==== ___strgtold12 @ 00408490

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
        if (DAT_0040ca58 == bVar8) {
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
          if (bVar8 != 0x30) goto switchD_00408740_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_00408944;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_00408944;
      }
      if (DAT_0040ca58 == bVar8) {
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
          goto switchD_00408740_caseD_2c;
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
        goto LAB_00408944;
      }
      if (DAT_0040ca58 == bVar8) {
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
        if (DAT_0040ca54 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0040c848 + (uint)bVar8 * 2) & 4;
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
      if (DAT_0040ca58 == bVar8) {
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
          goto switchD_00408740_caseD_2c;
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
        if (DAT_0040ca54 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0040c848 + (uint)bVar8 * 2) & 4;
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
        goto switchD_00408740_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_0040ca54 < 2) {
        uVar13 = *(ushort *)(PTR_DAT_0040c848 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_00408944;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = (byte *)(str + -1);
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00408944;
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
        goto LAB_00408944;
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
        goto LAB_00408944;
      }
      goto switchD_00408740_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_0040ca54 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0040c848 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_004088ca;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_004088ca:
      while( true ) {
        if (DAT_0040ca54 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_0040c848 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_00408740_caseD_2c:
      iVar7 = 10;
LAB_00408944:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (implicit_E == 0) goto switchD_00408740_caseD_2c;
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
      goto LAB_00408a42;
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
        goto LAB_00408a42;
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
LAB_00408a42:
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
  *(undefined4 *)(pld12->ld12 + 2) = local_28[0];
  *(ushort *)pld12->ld12 = local_c;
  *(undefined4 *)(pld12->ld12 + 6) = local_6;
  *(ushort *)(pld12->ld12 + 10) = local_52 | local_2;
  return local_40;
}


// ==== $I10_OUTPUT @ 00408be0

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
      *(undefined4 *)(param_6 + 2) = DAT_0040aa00;
      param_6[4] = DAT_0040aa04;
      *(undefined1 *)(param_6 + 5) = DAT_0040aa06;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0040a9f8;
      param_6[4] = DAT_0040a9fc;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0040a9f0;
      param_6[4] = DAT_0040a9f4;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_0040a9e8;
    param_6[4] = DAT_0040a9ec;
    *(undefined1 *)(param_6 + 5) = DAT_0040a9ee;
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
LAB_00408f59:
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
    if (psVar7 < psVar1) goto LAB_00408f59;
    goto LAB_00408f2b;
  }
  if (psVar7 < psVar1) {
LAB_00408f25:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_00408f25;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_00408f2b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}


// ==== _fclose @ 00408f80

/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Release */

int __cdecl _fclose(FILE *_File)

{
  int iVar1;
  
  if ((_File->_flag & 0x40) != 0) {
    _File->_flag = 0;
    return -1;
  }
  FID_conflict___lock_file(_File);
  iVar1 = __fclose_lk(_File);
  FID_conflict___lock_file(_File);
  return iVar1;
}


// ==== __fclose_lk @ 00408fc0

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if ((param_1->_flag & 0x83) != 0) {
    iVar2 = __flush(param_1);
    __freebuf(param_1);
    iVar1 = __close(param_1->_file);
    if (iVar1 < 0) {
      iVar2 = -1;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      _free(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return iVar2;
}


// ==== __commit @ 00409020

/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Release */

int __cdecl __commit(int _FileHandle)

{
  HANDLE hFile;
  BOOL BVar1;
  ulong *puVar2;
  int *piVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_00410180 <= (uint)_FileHandle) {
LAB_004090ae:
    piVar3 = FUN_00403160();
    *piVar3 = 9;
    return -1;
  }
  piVar3 = (int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar5 = (_FileHandle & 0x1fU) * 0x24;
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) == 0) goto LAB_004090ae;
  __lock_fhandle(_FileHandle);
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) != 0) {
    DVar4 = 0;
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar4 = GetLastError();
    }
    iVar5 = 0;
    if (DVar4 == 0) goto LAB_0040909f;
    puVar2 = FUN_00403170();
    *puVar2 = DVar4;
  }
  iVar5 = -1;
  piVar3 = FUN_00403160();
  *piVar3 = 9;
LAB_0040909f:
  __unlock_fhandle(_FileHandle);
  return iVar5;
}


// ==== ___getlocaleinfo @ 004090d0

/* Library Function - Single Match
    ___getlocaleinfo
   
   Library: Visual Studio 1998 Release */

int __cdecl
___getlocaleinfo(_locale_t _Locale,int _Lc_type,LPCWSTR _LocaleName,LCTYPE _FieldType,void *_Address
                )

{
  bool bVar1;
  size_t _Size;
  DWORD DVar2;
  LPSTR _LpLCData;
  byte *pbVar3;
  char *_Dest;
  int iVar4;
  uint uVar5;
  byte local_80 [128];
  
  if (_Locale != (_locale_t)0x1) {
    if (_Locale != (_locale_t)0x0) {
      return -1;
    }
    iVar4 = ___crtGetLocaleInfoW(_Lc_type,(LCTYPE)_LocaleName,(LPWSTR)&DAT_0040efa8,4,0);
    if (iVar4 != 0) {
      pbVar3 = &DAT_0040efa8;
      *(undefined1 *)_FieldType = 0;
      while( true ) {
        local_80[0] = *pbVar3;
        if (DAT_0040ca54 < 2) {
          uVar5 = *(ushort *)(PTR_DAT_0040c848 + (uint)local_80[0] * 2) & 4;
        }
        else {
          uVar5 = __isctype((uint)local_80[0],4);
        }
        if (uVar5 == 0) break;
        pbVar3 = pbVar3 + 2;
        *(byte *)_FieldType = local_80[0] + *(char *)_FieldType * '\n' + -0x30;
        if (&DAT_0040efb0 <= pbVar3) {
          return 0;
        }
      }
      return 0;
    }
    return -1;
  }
  pbVar3 = local_80;
  bVar1 = false;
  _Size = ___crtGetLocaleInfoA((_locale_t)_Lc_type,_LocaleName,(LCTYPE)local_80,(LPSTR)0x80,0);
  if (_Size == 0) {
    DVar2 = GetLastError();
    if (((DVar2 != 0x7a) ||
        (_LpLCData = (LPSTR)___crtGetLocaleInfoA((_locale_t)_Lc_type,_LocaleName,0,(LPSTR)0x0,0),
        _LpLCData == (LPSTR)0x0)) || (pbVar3 = _malloc((size_t)_LpLCData), pbVar3 == (byte *)0x0))
    goto LAB_004091a7;
    bVar1 = true;
    _Size = ___crtGetLocaleInfoA((_locale_t)_Lc_type,_LocaleName,(LCTYPE)pbVar3,_LpLCData,0);
    if (_Size == 0) goto LAB_004091a7;
  }
  _Dest = _malloc(_Size);
  *(char **)_FieldType = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,(char *)pbVar3,_Size);
    if (bVar1) {
      _free(pbVar3);
    }
    return 0;
  }
LAB_004091a7:
  if (bVar1) {
    _free(pbVar3);
  }
  return -1;
}


// ==== ___crtGetLocaleInfoW @ 00409290

/* Library Function - Single Match
    ___crtGetLocaleInfoW
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtGetLocaleInfoW(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  size_t _Size;
  LPSTR lpLCData;
  
  iVar1 = DAT_0040e404;
  if (DAT_0040e404 == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
  }
  DAT_0040e404 = iVar1;
  if (iVar1 == 1) {
    iVar1 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (iVar1 == 2) {
    if (param_5 == 0) {
      param_5 = DAT_0040da58;
    }
    _Size = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if (_Size == 0) {
      return 0;
    }
    lpLCData = _malloc(_Size);
    if (lpLCData == (LPSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,_Size);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
      }
      else {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
      }
      if (iVar1 != 0) {
        _free(lpLCData);
        return iVar1;
      }
    }
    _free(lpLCData);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== ___crtGetLocaleInfoA @ 004093c0

/* Library Function - Single Match
    ___crtGetLocaleInfoA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtGetLocaleInfoA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,LCTYPE _LCType,LPSTR _LpLCData,int _CchData)

{
  int iVar1;
  LPWSTR lpLCData;
  
  iVar1 = DAT_0040e408;
  if (DAT_0040e408 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
  }
  DAT_0040e408 = iVar1;
  if (iVar1 == 2) {
    iVar1 = GetLocaleInfoA((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPSTR)_LCType,(int)_LpLCData);
    return iVar1;
  }
  if (iVar1 == 1) {
    if (_CchData == 0) {
      _CchData = DAT_0040da58;
    }
    iVar1 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      return 0;
    }
    lpLCData = _malloc(iVar1 * 2);
    if (lpLCData == (LPWSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,lpLCData,iVar1);
    if (iVar1 != 0) {
      if (_LpLCData == (LPSTR)0x0) {
        iVar1 = WideCharToMultiByte(_CchData,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0)
        ;
      }
      else {
        iVar1 = WideCharToMultiByte(_CchData,0x220,lpLCData,-1,(LPSTR)_LCType,(int)_LpLCData,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
      }
      if (iVar1 != 0) {
        _free(lpLCData);
        return iVar1;
      }
    }
    _free(lpLCData);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== __strcmpi @ 00409500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __strcmpi
   
   Library: Visual Studio 1998 Release */

int __cdecl __strcmpi(char *_Str1,char *_Str2)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  if (DAT_0040da48 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_0040954e;
        bVar5 = *_Str2;
        _Str2 = _Str2 + 1;
        bVar4 = *_Str1;
        _Str1 = _Str1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_0040954e:
    uVar7 = (uint)cVar6;
  }
  else {
    bVar2 = 0 < DAT_0040f064;
    if (bVar2) {
      __lock(0x13);
    }
    else {
      _DAT_0040f068 = _DAT_0040f068 + 1;
    }
    uVar9 = (uint)bVar2;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_004095a7;
        cVar6 = *_Str2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),cVar6);
        _Str2 = _Str2 + 1;
        cVar1 = *_Str1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),cVar1);
        _Str1 = _Str1 + 1;
      } while (cVar6 == cVar1);
      uVar8 = __tolower_lk(uVar8);
      uVar7 = __tolower_lk(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_004095a7:
    if (uVar9 == 0) {
      _DAT_0040f068 = _DAT_0040f068 + -1;
    }
    else {
      FUN_00403220(0x13);
    }
  }
  return uVar7;
}


// ==== ___ld12mul @ 004095d0

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
    if (0 < (short)local_1a) goto LAB_004097a3;
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
LAB_004097a3:
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


// ==== ___multtenpow12 @ 00409880

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
  
  puVar4 = &DAT_0040e470;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar4 = &DAT_0040e5d0;
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


// ==== __close @ 00409900

/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Release */

int __cdecl __close(int _FileHandle)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_00410180) &&
     ((*(byte *)(*(int *)((int)&DAT_00410080 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 0x24) & 1) != 0)) {
    __lock_fhandle(_FileHandle);
    iVar1 = __close_lk(_FileHandle);
    __unlock_fhandle(_FileHandle);
    return iVar1;
  }
  piVar2 = FUN_00403160();
  *piVar2 = 9;
  puVar3 = FUN_00403170();
  *puVar3 = 0;
  return -1;
}


// ==== __close_lk @ 00409970

/* Library Function - Single Match
    __close_lk
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __close_lk(uint param_1)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  
  if ((param_1 == 1) || (param_1 == 2)) {
    iVar1 = __get_osfhandle(2);
    iVar2 = __get_osfhandle(1);
    if (iVar1 != iVar2) goto LAB_0040999a;
  }
  else {
LAB_0040999a:
    hObject = (HANDLE)__get_osfhandle(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_004099ba;
    }
  }
  DVar4 = 0;
LAB_004099ba:
  __free_osfhnd(param_1);
  if (DVar4 != 0) {
    __dosmaperr(DVar4);
    return 0xffffffff;
  }
  *(undefined1 *)
   (*(int *)((int)&DAT_00410080 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 + (param_1 & 0x1f) * 0x24)
       = 0;
  return 0;
}


// ==== __freebuf @ 00409a00

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


// ==== FUN_00409a40 @ 00409a40

void __cdecl FUN_00409a40(char *param_1)

{
  size_t sVar1;
  char *_Dest;
  
  sVar1 = _strlen(param_1);
  _Dest = _malloc(sVar1 + 1);
  if (_Dest != (char *)0x0) {
    FID_conflict___mbscpy(_Dest,param_1);
  }
  return;
}


// ==== _strlen @ 00409a70

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
    if (((uint)puVar2 & 3) == 0) goto LAB_00409a90;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00409ac3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00409a90:
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
  goto LAB_00409ac3;
}


// ==== FID_conflict:__mbscpy @ 00409af0

/* Library Function - Multiple Matches With Different Base Names
    __mbscpy
    _strcpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl FID_conflict___mbscpy(char *_Dest,char *_Source)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)_Dest;
  while (((uint)_Source & 3) != 0) {
    bVar1 = (byte)*(uint *)_Source;
    uVar3 = (uint)bVar1;
    _Source = (char *)((int)_Source + 1);
    if (bVar1 == 0) goto LAB_00409bd8;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *(uint *)_Source;
    uVar3 = *(uint *)_Source;
    _Source = (char *)((int)_Source + 4);
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00409bd8:
        *(byte *)puVar4 = (byte)uVar3;
        return _Dest;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return _Dest;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return _Dest;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return _Dest;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


