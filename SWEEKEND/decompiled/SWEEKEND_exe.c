// ==== FUN_00401000 @ 00401000

void FUN_00401000(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (DAT_00414f7c == 0) {
    UVar3 = 0;
    UVar2 = 0x131;
    pHVar1 = GetMenu(DAT_00417088);
    CheckMenuItem(pHVar1,UVar2,UVar3);
  }
  else {
    UVar3 = 8;
    UVar2 = 0x131;
    pHVar1 = GetMenu(DAT_00417088);
    CheckMenuItem(pHVar1,UVar2,UVar3);
  }
  DrawMenuBar(DAT_00417088);
  return;
}


// ==== FUN_00401062 @ 00401062

void __cdecl FUN_00401062(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_004145fc = 2;
  }
  DAT_00416494 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_004010a5 @ 004010a5

void __cdecl FUN_004010a5(HWND param_1)

{
  if (DAT_00416494 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00416494);
  }
  return;
}


// ==== FUN_004010d6 @ 004010d6

void __cdecl FUN_004010d6(uint *param_1)

{
  FUN_0040cb80((uint *)&DAT_00414600,param_1);
  return;
}


// ==== FUN_004010f7 @ 004010f7

void __cdecl FUN_004010f7(HWND param_1)

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


// ==== FUN_0040122f @ 0040122f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040122f(int param_1)

{
  if (((0 < param_1) && (param_1 < 3)) && (*(int *)(&DAT_00416518 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00416518 + param_1 * 4) = 1;
    _DAT_004145f4 = 1;
    Sleep(500);
    if (param_1 == 1) {
      FUN_004010d6((uint *)s_QUICKHELPBMP_00414720);
      FUN_0040bb8d(DAT_00416624,s_QTIPLOSEDGAME_00414730,DAT_00417088,FUN_004023a3);
    }
    else if (param_1 == 2) {
      FUN_004010d6((uint *)s_QUICKHELPBMP_00414740);
      FUN_0040bb8d(DAT_00416624,s_QGOBUYDIALOG_00414750,DAT_00417088,FUN_0040260e);
    }
    _DAT_004145f4 = 0;
    FUN_00408229(0);
    FUN_00401000();
    FUN_0040826f(0);
    FUN_0040c999();
  }
  return;
}


// ==== FUN_00401345 @ 00401345

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_00401345(void)

{
  INT_PTR IVar1;
  
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_QUICKHELPBMP_00414760);
  IVar1 = FUN_0040bb8d(DAT_00416624,s_EXITGAME_00414770,DAT_00417088,FUN_004017f7);
  _DAT_004145f0 = 0;
  return IVar1;
}


// ==== FUN_0040139d @ 0040139d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_0040139d(void)

{
  INT_PTR IVar1;
  
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_QUICKHELPBMP_0041477c);
  IVar1 = FUN_0040bb8d(DAT_00416624,s_NEWGAME_0041478c,DAT_00417088,FUN_004017f7);
  _DAT_004145f0 = 0;
  return IVar1;
}


// ==== FUN_004013f5 @ 004013f5

INT_PTR __cdecl FUN_004013f5(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040bb8d(DAT_00416624,s_RESETSCORE_00414794,param_1,FUN_0040392a);
  return IVar1;
}


// ==== FUN_0040142a @ 0040142a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040142a(void)

{
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_ABOUTBMP_004147a0);
  FUN_0040bb8d(DAT_00416624,s_ABOUT_004147ac,DAT_00417088,FUN_0040198e);
  _DAT_004145f0 = 0;
  return;
}


// ==== FUN_00401479 @ 00401479

void __cdecl FUN_00401479(HWND param_1)

{
  FUN_0040bb8d(DAT_00416624,s_CREDITS_004147b4,param_1,FUN_00401c74);
  return;
}


// ==== FUN_004014a5 @ 004014a5

void __cdecl FUN_004014a5(HWND param_1)

{
  FUN_0040bb8d(DAT_00416624,s_SYSTEMINFODIALOG_004147bc,param_1,FUN_00401e05);
  return;
}


// ==== FUN_004014d1 @ 004014d1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004014d1(void)

{
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_QUICKHELPBMP_004147d0);
  FUN_0040bb8d(DAT_00416624,s_QUICKHELPDIALOG_004147e0,DAT_00417088,FUN_00402835);
  _DAT_004145f0 = 0;
  return;
}


// ==== FUN_00401520 @ 00401520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401520(void)

{
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_CUPBMP_004147f0);
  FUN_0040bb8d(DAT_00416624,s_YOURNAME_004147f8,DAT_00417088,FUN_00402bb4);
  _DAT_004145f0 = 0;
  return;
}


// ==== FUN_0040156f @ 0040156f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040156f(void)

{
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_CUPBMP_00414804);
  FUN_0040bb8d(DAT_00416624,s_BALLSTOP_0041480c,DAT_00417088,FUN_00402ef2);
  _DAT_004145f0 = 0;
  return;
}


// ==== FUN_004015be @ 004015be

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004015be(void)

{
  _DAT_004145f0 = 1;
  FUN_004010d6((uint *)s_OPTIONSBMP_00414818);
  FUN_0040bb8d(DAT_00416624,s_OPTIONS_00414824,DAT_00417088,FUN_0040326f);
  _DAT_004145f0 = 0;
  return;
}


// ==== FUN_0040160d @ 0040160d

void __cdecl FUN_0040160d(HWND param_1)

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
  local_8 = FUN_00408390(pHVar1,&DAT_00414600);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_004082b1(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00414bf8,0);
  RealizePalette(pHVar1);
  FUN_004082fa(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00401702 @ 00401702

void __cdecl FUN_00401702(HWND param_1)

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
  ho = FUN_00408390(pHVar1,s_QUICKHELPBMP_0041482c);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_004082b1(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00414bf8,0);
  RealizePalette(pHVar1);
  FUN_004082fa(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_004017f7 @ 004017f7

UINT FUN_004017f7(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004010f7(param_1);
      DAT_00416620 = param_1;
      DAT_0041661c = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040160d(DAT_0041661c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00416620 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00416620);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00416620,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00416620,(RECT *)0x0,0);
        InvalidateRect(DAT_00417088,(RECT *)0x0,0);
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


// ==== FUN_0040198e @ 0040198e

UINT FUN_0040198e(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004010f7(param_1);
      DAT_00416630 = param_1;
      DAT_0041662c = GetDlgItem(param_1,100);
      FUN_0040bd20(DAT_00416624,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_0040bea4(&DAT_0041483c,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_0040bea4(s_Product_ID_00414840,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040160d(DAT_0041662c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00416630) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_00416630);
      SelectPalette(local_10c,DAT_00414bf8,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_00416630,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00416630,(RECT *)0x0,0);
      InvalidateRect(DAT_00417088,(RECT *)0x0,0);
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
      FUN_004014a5(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00401479(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00401c74 @ 00401c74

UINT FUN_00401c74(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004010f7(param_1);
      DAT_00416528 = param_1;
      DAT_00416508 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040160d(DAT_00416508);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00416528 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00416528);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00416528,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00416528,(RECT *)0x0,0);
        InvalidateRect(DAT_00416630,(RECT *)0x0,0);
        InvalidateRect(DAT_00417088,(RECT *)0x0,0);
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


// ==== FUN_00401e05 @ 00401e05

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00401e05(HWND param_1,int param_2,uint param_3)

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
    FUN_004010f7(param_1);
    _DAT_00416438 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_0041484c,local_49c.dwMajorVersion,-1);
    FUN_0040cb80((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414850);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_00414854,local_49c.dwMinorVersion,-1);
    FUN_0040cb90((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414858);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_0041485c,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0040cb90((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414860);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0040cb90((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_00414864,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0040cb80((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414868);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0040cb80((uint *)local_404,(uint *)&DAT_0041486c);
    FUN_0040cb90((uint *)local_404,(uint *)&local_4b4);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414870);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_00414874,local_4a0,-1);
    FUN_0040cb90((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_00414878);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_0041489c,s_display_drv_00414890,s_Unknown_00414888,local_404,0x80,
               s_system_ini_0041487c);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148b0,local_4a0,-1);
    FUN_0040cb80((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_004148b4);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148b8,local_4a0,-1);
    FUN_0040cb90((uint *)local_404,puVar1);
    FUN_0040cb90((uint *)local_404,(uint *)&DAT_004148bc);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148c0,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0040cb90((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148c4,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0040cb90((uint *)local_404,puVar1);
      FUN_0040cb90((uint *)local_404,(uint *)&DAT_004148c8);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148d0,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0040cb90((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_00408160((uint *)&DAT_004148cc,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0040cb90((uint *)local_404,puVar1);
      }
      FUN_0040cb90((uint *)local_404,(uint *)&DAT_004148d4);
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


// ==== FUN_004023a3 @ 004023a3

UINT FUN_004023a3(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040160d(DAT_00416504);
      }
      return 0;
    }
    FUN_004010f7(param_1);
    DAT_0041642c = param_1;
    DAT_00416504 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00414f7c == 0);
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
      DAT_00414f7c = (uint)(LVar2 == 0);
      FUN_0040c999();
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
      DAT_00414f7c = (uint)(LVar2 == 0);
      FUN_0040c999();
      EndDialog(param_1,0);
      PostMessageA(DAT_00417088,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (param_3 == DAT_0041642c) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0041642c);
  SelectPalette(hdc,DAT_00414bf8,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0041642c,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0041642c,(RECT *)0x0,0);
    InvalidateRect(DAT_00417088,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040260e @ 0040260e

UINT FUN_0040260e(HWND param_1,uint param_2,HWND param_3)

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
      FUN_004010f7(param_1);
      DAT_00416628 = param_1;
      DAT_0041649c = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_00414f7c == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040160d(DAT_0041649c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00416628 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00416628);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_00416628,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_00416628,(RECT *)0x0,0);
        InvalidateRect(DAT_00417088,(RECT *)0x0,0);
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
        DAT_00414f7c = (uint)(LVar2 == 0);
        FUN_0040c999();
        EndDialog(param_1,0);
        PostMessageA(DAT_00417088,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00402835 @ 00402835

UINT FUN_00402835(HWND param_1,uint param_2,HWND param_3)

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
        FUN_0040160d(DAT_00416430);
      }
      return 0;
    }
    FUN_004010f7(param_1);
    DAT_0041650c = param_1;
    DAT_00416430 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00414f78 == 0);
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
      DAT_00414f78 = (uint)(LVar2 == 0);
      FUN_0040c999();
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
      DAT_00414f78 = (uint)(LVar2 == 0);
      FUN_0040c999();
      EndDialog(param_1,0);
      PostMessageA(DAT_00417088,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_0041650c == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_0041650c);
  SelectPalette(hdc,DAT_00414bf8,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_0041650c,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_0041650c,(RECT *)0x0,0);
    InvalidateRect(DAT_00417088,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00402aa1 @ 00402aa1

void FUN_00402aa1(void)

{
  longlong lVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    lVar1 = __ftol();
    *(int *)(&DAT_00416538 + local_8 * 0xc) = (int)lVar1;
    lVar1 = __ftol();
    *(int *)(&DAT_0041653c + local_8 * 0xc) = (int)lVar1;
    *(undefined4 *)(&DAT_00416540 + local_8 * 0xc) = *(undefined4 *)(&DAT_00414078 + local_8 * 0xc);
  }
  return;
}


// ==== FUN_00402b42 @ 00402b42

void FUN_00402b42(void)

{
  int local_8;
  
  _memset(&DAT_004164b0,0,0x4c);
  _memset(&DAT_004163e0,0,0x4c);
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    *(int *)(&DAT_004164b0 + local_8 * 4) = local_8;
    *(int *)(&DAT_004163e0 + (0x12 - local_8) * 4) = local_8;
  }
  return;
}


// ==== FUN_00402bb4 @ 00402bb4

UINT FUN_00402bb4(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_0040160d(DAT_00416490);
      }
      return 0;
    }
    FUN_004010f7(param_1);
    DAT_00416530 = param_1;
    DAT_00416490 = GetDlgItem(param_1,100);
    if (DAT_004145fc == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00414f88);
    _Size = 0x10;
    _Src = FUN_00408160((uint *)&DAT_004148d8,DAT_00414f68,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (param_3 == DAT_00416530) {
        return 0;
      }
    }
    hdc = GetDC(DAT_00416530);
    SelectPalette(hdc,DAT_00414bf8,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_00416530,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_00416530,(RECT *)0x0,0);
      InvalidateRect(DAT_00417088,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00414f88,DAT_004145fc * 0x11);
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


// ==== FUN_00402ef2 @ 00402ef2

UINT FUN_00402ef2(HWND param_1,uint param_2,HWND param_3)

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
      FUN_004010f7(param_1);
      DAT_00416500 = param_1;
      DAT_0041652c = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00414700) && (DAT_00414700 < 10)) {
        SetDlgItemTextA(param_1,DAT_00414700 + 0x33,&DAT_004148dc);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_00408160((uint *)&DAT_004148e0,*(int *)(&DAT_0042a020 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00429ff8 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_0040160d(DAT_0041652c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00416500) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00416500);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00416500,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00416500,(RECT *)0x0,0);
        InvalidateRect(DAT_00417088,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_004013f5(DAT_00416500), IVar5 == 1)) {
        if ((-1 < DAT_00414700) && (DAT_00414700 < 10)) {
          SetDlgItemTextA(param_1,DAT_00414700 + 0x33,&DAT_004148e4);
        }
        DAT_00414700 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_0042a020 + local_14 * 0x2c) = 0;
          _memset(&DAT_00429ff8 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_00408160((uint *)&DAT_004148e8,*(int *)(&DAT_0042a020 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00429ff8 + local_14 * 0x2c);
        }
        FUN_0040c999();
      }
    }
  }
  return 0;
}


// ==== FUN_0040326f @ 0040326f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_0040326f(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_00417088,s_SWEEKEND_HLP_004142d8,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_0040160d(DAT_004164a4);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00403419:
      hdc = GetDC(DAT_0041643c);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_0041643c,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_0041643c,(RECT *)0x0,0);
      InvalidateRect(DAT_00417088,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_004010f7(param_1);
      DAT_0041643c = param_1;
      DAT_004164a4 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_004149c0;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_004149c4;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00414f84;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      WVar7 = 2;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x60,_DAT_00414f74 + 0x5e);
      if (DAT_004145fc == 1) {
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
      pHVar9 = (HIMC)0x0;
      pHVar1 = GetDlgItem(param_1,0xf);
      DAT_00416534 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_00414f88);
      pCVar2 = FUN_00408160((uint *)&DAT_004148ec,_DAT_00414f70,-1);
      SetDlgItemTextA(param_1,0xf,pCVar2);
      local_8 = GetDlgItem(param_1,0x3ea);
      SendMessageA(local_8,0x465,0,0x10032);
      return 1;
    }
    if (param_2 == 0x111) {
      switch((uint)param_3 & 0xffff) {
      case 1:
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x33);
        DAT_004149c0 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_004149c4 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_00414f84 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_00414f74 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          _DAT_00414f74 = 2;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_00414f88,DAT_004145fc * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0x33; local_28 = local_28 + 1) {
          pcVar3 = FUN_00408160((uint *)&DAT_004148fc,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_004037c6:
            _DAT_00414f70 = local_28;
            break;
          }
          pcVar3 = FUN_00408160((uint *)&DAT_00414900,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_004037c6;
        }
      case 2:
        DAT_0041643c = (HWND)0x0;
        pHVar9 = DAT_00416534;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = _DAT_00414f70;
          for (local_28 = 1; local_28 < 0x33; local_28 = local_28 + 1) {
            pcVar3 = FUN_00408160((uint *)&DAT_004148f0,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_00403562:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_00408160((uint *)&DAT_004148f4,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_00403562;
          }
          pCVar2 = FUN_00408160((uint *)&DAT_004148f8,local_1c,-1);
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
        WinHelpA(DAT_00417088,s_SWEEKEND_HLP_004142d8,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_0041643c == param_3) {
      return 0;
    }
    goto LAB_00403419;
  }
  return 0;
}


// ==== FUN_0040392a @ 0040392a

UINT FUN_0040392a(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_004010f7(param_1);
      DAT_00416634 = param_1;
      DAT_004164a0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00401702(DAT_004164a0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00416634) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00416634);
      SelectPalette(hdc,DAT_00414bf8,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00416634,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00416500,(RECT *)0x0,0);
        InvalidateRect(DAT_00416634,(RECT *)0x0,0);
        InvalidateRect(DAT_00417088,(RECT *)0x0,0);
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


// ==== FUN_00403ad0 @ 00403ad0

void FUN_00403ad0(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_0040cf40(DVar1);
  return;
}


// ==== FUN_00403aef @ 00403aef

int __cdecl FUN_00403aef(int param_1)

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


// ==== FUN_00403b20 @ 00403b20

void __cdecl FUN_00403b20(int param_1,int param_2)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < param_1 / 0x32; local_8 = local_8 + 1) {
    Sleep(0x14);
    FUN_00406823(param_2);
  }
  return;
}


// ==== FUN_00403b6f @ 00403b6f

UINT FUN_00403b6f(void)

{
  UINT UVar1;
  
  FUN_00408229(0);
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  UVar1 = RealizePalette(DAT_00417040);
  FUN_0040826f(0);
  if (UVar1 != 0) {
    InvalidateRect(DAT_00417088,(RECT *)0x0,0);
  }
  return UVar1;
}


// ==== FUN_00403bd6 @ 00403bd6

void FUN_00403bd6(void)

{
  int local_8;
  
  FUN_00402aa1();
  FUN_00402b42();
  FUN_0040a9cb(s_FLOWERS_00414904,(short *)&DAT_00417518);
  FUN_0040a9cb(s_FLOWERS1_0041490c,(short *)&DAT_0041773c);
  FUN_0040a9cb(s_DIGITS_SCO_00414918,(short *)&DAT_00417960);
  FUN_0040a9cb(s_DIGITS_LEV_00414924,(short *)&DAT_00417fcc);
  FUN_0040a9cb(s_DIGITS_MOV_00414930,(short *)&DAT_004181f0);
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_0040b20a(&DAT_00417518,(int)(&DAT_00420120 + local_8 * 0x2c));
    FUN_00409fa9((int *)(&DAT_00420120 + local_8 * 0x2c),
                 *(int *)(&DAT_00414070 + local_8 * 0xc) + 200,
                 *(int *)(&DAT_00414074 + local_8 * 0xc) + DAT_00414c04 + -0xbe,-1);
    FUN_00409e00((int *)(&DAT_00420120 + local_8 * 0x2c),0);
    FUN_00409e00((int *)(&DAT_00420120 + local_8 * 0x2c),*(int *)(&DAT_004164b0 + local_8 * 4));
  }
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_0040b20a(&DAT_0041773c,(int)(&DAT_00420120 + (local_8 + 0x13) * 0x2c));
    FUN_00409fa9((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),
                 *(int *)(&DAT_00416538 + local_8 * 0xc) + 0x1da,
                 *(int *)(&DAT_0041653c + local_8 * 0xc) + DAT_00414c04 + -0x62,-1);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),0);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),
                 *(int *)(&DAT_004163e0 + local_8 * 4));
  }
  FUN_0040b20a(&DAT_004181f0,0x4207a8);
  FUN_0040b20a(&DAT_004181f0,0x4207d4);
  FUN_00409e00((int *)&DAT_004207a8,0);
  FUN_00409e00((int *)&DAT_004207d4,0);
  FUN_00409fa9((int *)&DAT_004207a8,0x1ce,DAT_00414c04 + -0x102,-5);
  FUN_00409fa9((int *)&DAT_004207d4,0x1e0,DAT_00414c04 + -0x102,-5);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040b20a(&DAT_00417960,(int)(&DAT_00420120 + (local_8 + 0x28) * 0x2c));
    FUN_00409fa9((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),local_8 * -0x12 + 599,
                 DAT_00414c04 + -0x16a,-5);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),0);
  }
  FUN_0040b20a(&DAT_00417fcc,0x4208dc);
  FUN_0040b20a(&DAT_00417fcc,0x420908);
  FUN_00409e00((int *)&DAT_004208dc,0);
  FUN_00409e00((int *)&DAT_00420908,0);
  FUN_00409fa9((int *)&DAT_004208dc,0x209,DAT_00414c04 + -0xa5,-5);
  FUN_00409fa9((int *)&DAT_00420908,0x21b,DAT_00414c04 + -0xa5,-5);
  FUN_0040a9cb(s_BUTTERFLY_0041493c,(short *)&DAT_00417b84);
  FUN_0040b20a(&DAT_00417b84,0x4209b8);
  FUN_00409fa9((int *)&DAT_004209b8,-100,-100,1);
  FUN_0040a9cb(&DAT_00414948,(short *)&DAT_00417da8);
  FUN_0040b20a(&DAT_00417da8,0x4209e4);
  FUN_00409fa9((int *)&DAT_004209e4,-100,-100,1);
  return;
}


// ==== FUN_004040ae @ 004040ae

void FUN_004040ae(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00409fa9((int *)(&DAT_00420120 + local_8 * 0x2c),
                 *(int *)(&DAT_00414070 + local_8 * 0xc) + 200,
                 *(int *)(&DAT_00414074 + local_8 * 0xc) + DAT_00414c04 + -0xbe,local_8 + 2);
    FUN_00409e00((int *)(&DAT_00420120 + local_8 * 0x2c),*(int *)(&DAT_004164b0 + local_8 * 4));
  }
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_0040b20a(&DAT_0041773c,(int)(&DAT_00420120 + (local_8 + 0x13) * 0x2c));
    FUN_00409fa9((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),
                 *(int *)(&DAT_00416538 + local_8 * 0xc) + 0x1da,
                 *(int *)(&DAT_0041653c + local_8 * 0xc) + DAT_00414c04 + -0x62,local_8 + 2);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),
                 *(int *)(&DAT_004163e0 + local_8 * 4));
  }
  FUN_00409e00((int *)&DAT_004207a8,0);
  FUN_00409e00((int *)&DAT_004207d4,0);
  FUN_00409fa9((int *)&DAT_004207a8,0x1ce,DAT_00414c04 + -0x102,5);
  FUN_00409fa9((int *)&DAT_004207d4,0x1e0,DAT_00414c04 + -0x102,5);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_00409fa9((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),local_8 * -0x12 + 599,
                 DAT_00414c04 + -0x16a,5);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),0);
  }
  FUN_00409e00((int *)&DAT_004208dc,0);
  FUN_00409e00((int *)&DAT_00420908,0);
  FUN_00409fa9((int *)&DAT_004208dc,0x209,DAT_00414c04 + -0xa5,5);
  FUN_00409fa9((int *)&DAT_00420908,0x21b,DAT_00414c04 + -0xa5,5);
  return;
}


// ==== FUN_00404378 @ 00404378

void FUN_00404378(void)

{
  int local_8;
  
  DAT_004145d8 = 0;
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00409e00((int *)(&DAT_00420120 + local_8 * 0x2c),0);
    FUN_00409e00((int *)(&DAT_00420120 + local_8 * 0x2c),*(int *)(&DAT_004164b0 + local_8 * 4));
  }
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),0);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x13) * 0x2c),
                 *(int *)(&DAT_004163e0 + local_8 * 4));
  }
  return;
}


// ==== FUN_0040445d @ 0040445d

undefined4 __cdecl FUN_0040445d(void *param_1,int param_2)

{
  int iVar1;
  LPCSTR pCVar2;
  undefined4 uVar3;
  char *pcVar4;
  short *psVar5;
  uint uVar6;
  short local_114 [20];
  int local_ec;
  char local_e8 [12];
  int local_dc;
  uint local_d8 [19];
  uint local_8c;
  uint local_88;
  byte local_84 [128];
  
  param_2 = param_2 + -1;
  if ((param_2 < 0) || (0x31 < param_2)) {
    iVar1 = FUN_00403aef(0x1e);
    param_2 = iVar1 + 0x14;
  }
  uVar6 = 0x26;
  psVar5 = local_114;
  pcVar4 = s_GLEVEL_0041494c;
  pCVar2 = FUN_00408160((uint *)s_LEVEL_00414954,param_2,3);
  iVar1 = FUN_0040b882(pCVar2,pcVar4,psVar5,uVar6);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    for (local_dc = 0; local_dc < 0x13; local_dc = local_dc + 1) {
      local_d8[local_dc] = (int)local_114[*(short *)(&DAT_00414020 + local_dc * 4)];
    }
    _memset(local_84,0xff,0x80);
    _memset(local_e8,0,0xb);
    for (local_dc = 0; local_dc < 0x13; local_dc = local_dc + 1) {
      local_8c = local_d8[local_dc] & 0xff;
      if (local_84[local_8c] == 0xff) {
        for (local_ec = 0; local_ec < 0x2000; local_ec = local_ec + 1) {
          local_88 = FUN_00403aef(0xb);
          if (local_e8[local_88] == '\0') {
            local_e8[local_88] = '\x01';
            break;
          }
          local_88 = 0;
        }
        local_84[local_8c] = (byte)local_88;
        local_d8[local_dc] = local_88;
      }
      else {
        local_d8[local_dc] = (uint)local_84[local_8c];
      }
    }
    FID_conflict__memcpy(param_1,local_d8,0x4c);
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_00404662 @ 00404662

void __cdecl FUN_00404662(int param_1)

{
  int local_8;
  
  if ((-1 < param_1) && (param_1 < 0x13)) {
    local_8 = *(int *)(&DAT_004164b0 + param_1 * 4);
    if ((local_8 < 0) || (10 < local_8)) {
      local_8 = 0;
    }
    FUN_00409e00((int *)(&DAT_00420120 + param_1 * 0x2c),local_8);
    FUN_00409fa9((int *)(&DAT_00420120 + param_1 * 0x2c),
                 *(int *)(&DAT_00414070 + param_1 * 0xc) + 200,
                 *(int *)(&DAT_00414074 + param_1 * 0xc) + DAT_00414c04 + -0xbe,param_1 + 2);
  }
  return;
}


// ==== FUN_00404726 @ 00404726

void __cdecl FUN_00404726(int param_1)

{
  int local_8;
  
  if ((-1 < param_1) && (param_1 < 0x13)) {
    local_8 = *(int *)(&DAT_004163e0 + param_1 * 4);
    if ((local_8 < 0) || (10 < local_8)) {
      local_8 = 0;
    }
    FUN_00409e00((int *)(&DAT_00420120 + (param_1 + 0x13) * 0x2c),local_8);
    FUN_00409fa9((int *)(&DAT_00420120 + (param_1 + 0x13) * 0x2c),
                 *(int *)(&DAT_00416538 + param_1 * 0xc) + 0x1da,
                 *(int *)(&DAT_0041653c + param_1 * 0xc) + DAT_00414c04 + -0x62,param_1 + 1);
  }
  return;
}


// ==== FUN_004047eb @ 004047eb

void FUN_004047eb(void)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00404662(local_8);
  }
  return;
}


// ==== FUN_00404828 @ 00404828

void FUN_00404828(void)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00404726(local_8);
  }
  return;
}


// ==== FUN_00404865 @ 00404865

void __cdecl FUN_00404865(int param_1)

{
  FUN_00409e00((int *)&DAT_004207a8,(param_1 / 10) % 10);
  FUN_00409e00((int *)&DAT_004207d4,param_1 % 10);
  return;
}


// ==== FUN_004048ca @ 004048ca

void __cdecl FUN_004048ca(int param_1)

{
  FUN_00409e00((int *)&DAT_004208dc,(param_1 / 10) % 10);
  FUN_00409e00((int *)&DAT_00420908,param_1 % 10);
  return;
}


// ==== FUN_0040492f @ 0040492f

undefined4 __cdecl FUN_0040492f(int param_1,int param_2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x12 < local_8) {
      return 1;
    }
    if (*(int *)(param_2 + local_8 * 4) != *(int *)(param_1 + local_8 * 4)) break;
    local_8 = local_8 + 1;
  }
  return 0;
}


// ==== FUN_00404984 @ 00404984

void __cdecl FUN_00404984(int *param_1)

{
  int iVar1;
  int aiStack_d8 [6];
  int aiStack_c0 [6];
  int local_a8;
  undefined4 local_a4 [19];
  int local_58;
  undefined4 local_54 [19];
  undefined4 local_8;
  
  local_58 = 1;
  while( true ) {
    if (0x12 < local_58) {
      return;
    }
    if (param_1[local_58] != *param_1) break;
    local_58 = local_58 + 1;
  }
  do {
    FID_conflict__memcpy(local_54,param_1,0x4c);
    FID_conflict__memcpy(local_a4,local_54,0x4c);
    for (local_58 = 0; local_58 < 7; local_58 = local_58 + 1) {
      FID_conflict__memcpy(local_54,local_a4,0x4c);
      iVar1 = FUN_00403aef(7);
      if (iVar1 != 0) {
        local_8 = *(undefined4 *)(&DAT_00414158 + local_58 * 0x34);
        for (local_a8 = 0; local_a8 < 6; local_a8 = local_a8 + 1) {
          iVar1 = FUN_00403aef(2);
          if (iVar1 == 1) {
            aiStack_d8[local_a8] = *(int *)(&DAT_0041415c + local_58 * 0x34 + local_a8 * 8);
            aiStack_c0[local_a8] = *(int *)(&DAT_00414160 + local_58 * 0x34 + local_a8 * 8);
          }
          else {
            aiStack_d8[local_a8] = *(int *)(&DAT_0041415c + local_58 * 0x34 + local_a8 * 8);
            aiStack_c0[local_a8] = *(int *)(&DAT_00414160 + local_58 * 0x34 + local_a8 * 8);
          }
        }
        for (local_a8 = 0; local_a8 < 6; local_a8 = local_a8 + 1) {
          local_a4[aiStack_c0[local_a8]] = local_54[aiStack_d8[local_a8]];
        }
      }
    }
    if (0x20 < DAT_004145dc) {
      for (local_58 = 0; local_58 < 7; local_58 = local_58 + 1) {
        FID_conflict__memcpy(local_54,local_a4,0x4c);
        iVar1 = FUN_00403aef(7);
        if (iVar1 != 0) {
          local_8 = *(undefined4 *)(&DAT_00414158 + local_58 * 0x34);
          for (local_a8 = 0; local_a8 < 6; local_a8 = local_a8 + 1) {
            iVar1 = FUN_00403aef(2);
            if (iVar1 == 1) {
              aiStack_d8[local_a8] = *(int *)(&DAT_0041415c + local_58 * 0x34 + local_a8 * 8);
              aiStack_c0[local_a8] = *(int *)(&DAT_00414160 + local_58 * 0x34 + local_a8 * 8);
            }
            else {
              aiStack_d8[local_a8] = *(int *)(&DAT_0041415c + local_58 * 0x34 + local_a8 * 8);
              aiStack_c0[local_a8] = *(int *)(&DAT_00414160 + local_58 * 0x34 + local_a8 * 8);
            }
          }
          for (local_a8 = 0; local_a8 < 6; local_a8 = local_a8 + 1) {
            local_a4[aiStack_c0[local_a8]] = local_54[aiStack_d8[local_a8]];
          }
        }
      }
    }
    iVar1 = FUN_0040492f((int)param_1,(int)local_54);
  } while (iVar1 != 0);
  FID_conflict__memcpy(param_1,local_54,0x4c);
  return;
}


// ==== FUN_00404d57 @ 00404d57

void FUN_00404d57(void)

{
  DAT_004145d8 = DAT_004145dc + 10;
  if (0x32 < DAT_004145dc) {
    DAT_004145d8 = 0x32 - (DAT_004145dc + -0x32);
  }
  if ((DAT_004145d8 < 10) && (0x32 < DAT_004145dc)) {
    DAT_004145d8 = 10;
  }
  if ((DAT_004145d8 < 0x14) && (DAT_004145dc < 0x32)) {
    DAT_004145d8 = 0x14;
  }
  if (99 < DAT_004145d8) {
    DAT_004145d8 = 99;
  }
  return;
}


// ==== FUN_00404df5 @ 00404df5

void FUN_00404df5(void)

{
  FUN_00404d57();
  FUN_00408229(0);
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  RealizePalette(DAT_00417040);
  DAT_004145dc = DAT_004145dc + 1;
  if (DAT_004145dc < 0x32) {
    FUN_0040445d(&DAT_004164b0,DAT_004145dc);
  }
  else {
    FUN_0040445d(&DAT_004164b0,DAT_004145dc % 0x12 + 0x20);
  }
  FID_conflict__memcpy(&DAT_004163e0,&DAT_004164b0,0x4c);
  FUN_00404984((int *)&DAT_004164b0);
  FID_conflict__memcpy(&DAT_00416440,&DAT_004164b0,0x4c);
  FUN_004047eb();
  FUN_00404828();
  FUN_00404865(DAT_004145d8);
  FUN_004048ca(DAT_004145dc);
  DAT_00414c0c = 1;
  FUN_004097c5();
  FUN_0040826f(0);
  DAT_00416510 = GetTickCount();
  return;
}


// ==== FUN_00404efc @ 00404efc

void FUN_00404efc(void)

{
  int local_c;
  int local_8;
  
  local_c = DAT_00414f68;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),local_c % 10);
    local_c = local_c / 10;
  }
  return;
}


// ==== FUN_00404f6d @ 00404f6d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404f6d(int param_1)

{
  HDC hDC;
  
  if ((DAT_004145e4 != 0) || (DAT_004145ec != 0)) {
    FUN_004040ae();
    DAT_004145e4 = 0;
    hDC = GetDC((HWND)0x0);
    FUN_0040864c(hDC,s_BACKGROUND_0041495c,DAT_00414c3c,&DAT_0041fe18);
    ReleaseDC((HWND)0x0,hDC);
  }
  DAT_004145e0 = 400;
  DAT_004145ec = 0;
  DAT_00414f68 = 0;
  DAT_004145d8 = 0;
  FUN_00404efc();
  DAT_004145f8 = _DAT_00414f74;
  DAT_004145dc = _DAT_00414f70;
  FUN_00404d57();
  FUN_0040445d(&DAT_004164b0,DAT_004145dc);
  FID_conflict__memcpy(&DAT_004163e0,&DAT_004164b0,0x4c);
  FUN_00404984((int *)&DAT_004164b0);
  FID_conflict__memcpy(&DAT_00416440,&DAT_004164b0,0x4c);
  FUN_004047eb();
  FUN_00404828();
  FUN_00404865(DAT_004145d8);
  FUN_004048ca(DAT_004145dc);
  if (DAT_004145f8 == 2) {
    EnableMenuItem(DAT_00416434,0xc9,1);
  }
  else {
    EnableMenuItem(DAT_00416434,0xc9,0);
  }
  DrawMenuBar(DAT_00417088);
  if (param_1 != 0) {
    FUN_00408229(0);
    DAT_00414c0c = 1;
    SelectPalette(DAT_00417040,DAT_00414bf8,0);
    RealizePalette(DAT_00417040);
    FUN_004097c5();
    FUN_0040826f(0);
  }
  DAT_00416510 = GetTickCount();
  return;
}


// ==== FUN_0040512c @ 0040512c

void FUN_0040512c(void)

{
  FUN_00404d57();
  FUN_00408229(0);
  FID_conflict__memcpy(&DAT_004164b0,&DAT_00416440,0x4c);
  FUN_004047eb();
  FUN_00404865(DAT_004145d8);
  DAT_00414c0c = 1;
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  RealizePalette(DAT_00417040);
  FUN_004097c5();
  FUN_0040826f(0);
  return;
}


// ==== FUN_004051ab @ 004051ab

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004051ab(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  longlong lVar5;
  int aiStack_13c [6];
  float afStack_124 [6];
  int aiStack_10c [6];
  int aiStack_f4 [6];
  float afStack_dc [6];
  int aiStack_c4 [6];
  int aiStack_ac [6];
  float local_94;
  int local_90;
  int aiStack_8c [6];
  int local_74;
  int local_70;
  float local_6c;
  float local_68;
  int local_64;
  float local_60;
  float local_5c;
  undefined4 local_58 [19];
  float local_c;
  int local_8;
  
  FID_conflict__memcpy(local_58,&DAT_004164b0,0x4c);
  local_70 = 0;
  while( true ) {
    if (6 < local_70) {
      return;
    }
    if (*(int *)(&DAT_00414158 + local_70 * 0x34) == param_1) break;
    local_70 = local_70 + 1;
  }
  local_64 = *(int *)(&DAT_00414070 + param_1 * 0xc) + 200;
  local_8 = *(int *)(&DAT_00414074 + param_1 * 0xc) + DAT_00414c04 + -0xbe;
  for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
    aiStack_13c[local_74] = *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34);
    aiStack_8c[local_74] = *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34);
    aiStack_c4[local_74] =
         *(int *)(&DAT_00414070 + *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_10c[local_74] =
         *(int *)(&DAT_00414070 + *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_ac[local_74] =
         *(int *)(&DAT_00414074 + *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_f4[local_74] =
         *(int *)(&DAT_00414074 + *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34) * 0xc);
    afStack_dc[local_74] = (float)(aiStack_10c[local_74] - aiStack_c4[local_74]) / _DAT_00413008;
    afStack_124[local_74] = (float)(aiStack_f4[local_74] - aiStack_ac[local_74]) / _DAT_00413008;
  }
  for (local_90 = 1; local_90 < 5; local_90 = local_90 + 1) {
    for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
      local_60 = afStack_dc[local_74] * (float)local_90 +
                 (float)(*(int *)(&DAT_00414070 + aiStack_13c[local_74] * 0xc) + 200);
      local_6c = afStack_124[local_74] * (float)local_90 +
                 (float)(*(int *)(&DAT_00414074 + aiStack_13c[local_74] * 0xc) +
                        DAT_00414c04 + -0xbe);
      local_5c = local_60 - (float)local_64;
      local_c = local_6c - (float)local_8;
      dVar1 = (double)(local_5c * local_5c + local_c * local_c);
      fVar4 = (float10)FUN_0040cf80(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
      local_94 = (float)fVar4;
      local_68 = _DAT_0041300c / (float)fVar4;
      local_60 = local_68 * local_5c + (float)local_64;
      local_6c = local_68 * local_c + (float)local_8;
      iVar2 = aiStack_13c[local_74] + 2;
      lVar5 = __ftol();
      iVar3 = (int)lVar5;
      lVar5 = __ftol();
      FUN_00409fa9((int *)(&DAT_00420120 + aiStack_13c[local_74] * 0x2c),(int)lVar5,iVar3,iVar2);
    }
    FUN_00408229(0);
    SelectPalette(DAT_00417040,DAT_00414bf8,0);
    RealizePalette(DAT_00417040);
    FUN_004097c5();
    FUN_0040826f(0);
    FUN_00403b20(0x32,0);
  }
  for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
    local_58[aiStack_8c[local_74]] = *(undefined4 *)(&DAT_004164b0 + aiStack_13c[local_74] * 4);
  }
  FID_conflict__memcpy(&DAT_004164b0,local_58,0x4c);
  for (local_74 = 0; local_74 < 0x13; local_74 = local_74 + 1) {
    FUN_00404662(local_74);
  }
  FUN_00408229(0);
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  RealizePalette(DAT_00417040);
  FUN_004097c5();
  FUN_0040826f(0);
  return;
}


// ==== FUN_00405656 @ 00405656

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405656(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  longlong lVar5;
  int aiStack_13c [6];
  float afStack_124 [6];
  int aiStack_10c [6];
  int aiStack_f4 [6];
  float afStack_dc [6];
  int aiStack_c4 [6];
  int aiStack_ac [6];
  float local_94;
  int local_90;
  int aiStack_8c [6];
  int local_74;
  int local_70;
  float local_6c;
  float local_68;
  int local_64;
  float local_60;
  float local_5c;
  undefined4 local_58 [19];
  float local_c;
  int local_8;
  
  FID_conflict__memcpy(local_58,&DAT_004164b0,0x4c);
  local_70 = 0;
  while( true ) {
    if (6 < local_70) {
      return;
    }
    if (*(int *)(&DAT_00414158 + local_70 * 0x34) == param_1) break;
    local_70 = local_70 + 1;
  }
  local_64 = *(int *)(&DAT_00414070 + param_1 * 0xc) + 200;
  local_8 = *(int *)(&DAT_00414074 + param_1 * 0xc) + DAT_00414c04 + -0xbe;
  for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
    aiStack_13c[local_74] = *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34);
    aiStack_8c[local_74] = *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34);
    aiStack_c4[local_74] =
         *(int *)(&DAT_00414070 + *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_10c[local_74] =
         *(int *)(&DAT_00414070 + *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_ac[local_74] =
         *(int *)(&DAT_00414074 + *(int *)(&DAT_00414160 + local_74 * 8 + local_70 * 0x34) * 0xc);
    aiStack_f4[local_74] =
         *(int *)(&DAT_00414074 + *(int *)(&DAT_0041415c + local_74 * 8 + local_70 * 0x34) * 0xc);
    afStack_dc[local_74] = (float)(aiStack_10c[local_74] - aiStack_c4[local_74]) / _DAT_00413008;
    afStack_124[local_74] = (float)(aiStack_f4[local_74] - aiStack_ac[local_74]) / _DAT_00413008;
  }
  for (local_90 = 1; local_90 < 5; local_90 = local_90 + 1) {
    for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
      local_60 = afStack_dc[local_74] * (float)local_90 +
                 (float)(*(int *)(&DAT_00414070 + aiStack_13c[local_74] * 0xc) + 200);
      local_6c = afStack_124[local_74] * (float)local_90 +
                 (float)(*(int *)(&DAT_00414074 + aiStack_13c[local_74] * 0xc) +
                        DAT_00414c04 + -0xbe);
      local_5c = local_60 - (float)local_64;
      local_c = local_6c - (float)local_8;
      dVar1 = (double)(local_5c * local_5c + local_c * local_c);
      fVar4 = (float10)FUN_0040cf80(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
      local_94 = (float)fVar4;
      local_68 = _DAT_0041300c / (float)fVar4;
      local_60 = local_68 * local_5c + (float)local_64;
      local_6c = local_68 * local_c + (float)local_8;
      iVar2 = aiStack_13c[local_74] + 2;
      lVar5 = __ftol();
      iVar3 = (int)lVar5;
      lVar5 = __ftol();
      FUN_00409fa9((int *)(&DAT_00420120 + aiStack_13c[local_74] * 0x2c),(int)lVar5,iVar3,iVar2);
    }
    FUN_00408229(0);
    SelectPalette(DAT_00417040,DAT_00414bf8,0);
    RealizePalette(DAT_00417040);
    FUN_004097c5();
    FUN_0040826f(0);
    FUN_00403b20(0x32,0);
  }
  for (local_74 = 0; local_74 < 6; local_74 = local_74 + 1) {
    local_58[aiStack_8c[local_74]] = *(undefined4 *)(&DAT_004164b0 + aiStack_13c[local_74] * 4);
  }
  FID_conflict__memcpy(&DAT_004164b0,local_58,0x4c);
  for (local_74 = 0; local_74 < 0x13; local_74 = local_74 + 1) {
    FUN_00404662(local_74);
  }
  FUN_00408229(0);
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  RealizePalette(DAT_00417040);
  FUN_004097c5();
  FUN_0040826f(0);
  return;
}


// ==== FUN_00405b01 @ 00405b01

void FUN_00405b01(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  DAT_004145e0 = 100;
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_00409fa9((int *)(&DAT_00420120 + local_8 * 0x2c),
                 *(int *)(&DAT_00414070 + local_8 * 0xc) + 200,
                 *(int *)(&DAT_00414074 + local_8 * 0xc) + DAT_00414c04 + -0xbe,-1);
  }
  FUN_004091bb(DAT_004164fc,DAT_00414c3c,0x55,DAT_00414c04 + -0x73);
  InvalidateRect(DAT_00417088,(RECT *)0x0,0);
  UpdateWindow(DAT_00417088);
  iVar1 = FUN_0040c7b8(DAT_00414f68,&local_c);
  if (((iVar1 == 0) || (9 < local_c)) || (DAT_004145f8 != 2)) {
    FUN_00407c42(4);
    if (DAT_00414f7c != 0) {
      FUN_0040122f(1);
    }
  }
  else {
    FUN_00407c42(5);
    if (DAT_00414f84 != 0) {
      FUN_00401520();
      DrawMenuBar(DAT_00417088);
    }
    iVar1 = FUN_0040c855(DAT_00414f68);
    if (0 < iVar1) {
      DAT_00414700 = local_c;
      FUN_0040156f();
    }
    FUN_0040c999();
  }
  return;
}


// ==== FUN_00405c6a @ 00405c6a

void __cdecl FUN_00405c6a(int param_1,int param_2)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x12 < local_c) {
      FUN_00407c42(2);
      return;
    }
    if ((*(int *)(&DAT_00414078 + local_c * 0xc) != 0) &&
       ((*(int *)(&DAT_00414074 + local_c * 0xc) - param_2) *
        (*(int *)(&DAT_00414074 + local_c * 0xc) - param_2) +
        (*(int *)(&DAT_00414070 + local_c * 0xc) - param_1) *
        (*(int *)(&DAT_00414070 + local_c * 0xc) - param_1) < 0x2d9)) break;
    local_c = local_c + 1;
  }
  FUN_00407c42(1);
  if (0 < DAT_004145d8) {
    DAT_004145d8 = DAT_004145d8 + -1;
  }
  FUN_00404865(DAT_004145d8);
  FUN_00405656(local_c);
  return;
}


// ==== FUN_00405d3b @ 00405d3b

void __cdecl FUN_00405d3b(int param_1,int param_2)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x12 < local_c) {
      FUN_00407c42(2);
      return;
    }
    if ((*(int *)(&DAT_00414078 + local_c * 0xc) != 0) &&
       ((*(int *)(&DAT_00414074 + local_c * 0xc) - param_2) *
        (*(int *)(&DAT_00414074 + local_c * 0xc) - param_2) +
        (*(int *)(&DAT_00414070 + local_c * 0xc) - param_1) *
        (*(int *)(&DAT_00414070 + local_c * 0xc) - param_1) < 0x2d9)) break;
    local_c = local_c + 1;
  }
  FUN_00407c42(1);
  if (0 < DAT_004145d8) {
    DAT_004145d8 = DAT_004145d8 + -1;
  }
  FUN_00404865(DAT_004145d8);
  FUN_004051ab(local_c);
  return;
}


// ==== FUN_00405e0c @ 00405e0c

void FUN_00405e0c(void)

{
  int local_8;
  
  FUN_00403b20(200,1);
  FUN_00408229(0);
  for (local_8 = 0; local_8 < 0x13; local_8 = local_8 + 1) {
    FUN_0040a069((int *)(&DAT_00420120 + local_8 * 0x2c));
  }
  SelectPalette(DAT_00417040,DAT_00414bf8,0);
  RealizePalette(DAT_00417040);
  FUN_004097c5();
  FUN_0040826f(0);
  FUN_00403b20(100,1);
  return;
}


// ==== FUN_00405eac @ 00405eac

void FUN_00405eac(void)

{
  int local_c;
  int local_8;
  
  local_c = DAT_00414f68;
  FUN_00408229(0);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_00403b20(0x32,0);
    FUN_00409e00((int *)(&DAT_00420120 + (local_8 + 0x28) * 0x2c),local_c % 10);
    local_c = local_c / 10;
    DAT_00414c0c = 1;
    SelectPalette(DAT_00417040,DAT_00414bf8,0);
    RealizePalette(DAT_00417040);
    FUN_004097c5();
  }
  FUN_0040826f(0);
  return;
}


// ==== FUN_00405f6c @ 00405f6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405f6c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _DAT_00414f74;
  iVar1 = _DAT_00414f70;
  iVar3 = DAT_004149c4;
  FUN_004015be();
  if (DAT_004149c4 != iVar3) {
    iVar3 = FUN_00403aef(2);
    FUN_00407945(iVar3 + 1);
  }
  if ((_DAT_00414f74 != iVar2) || (_DAT_00414f70 != iVar1)) {
    SendMessageA(DAT_00417088,0x111,0x65,1);
  }
  FUN_0040c999();
  return;
}


// ==== FUN_00405ff7 @ 00405ff7

void __cdecl FUN_00405ff7(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    DAT_004145e8 = 0;
    FUN_0040c999();
    FUN_00407945(0);
  }
  else {
    DAT_004145e8 = 1;
    FUN_0040c528();
    iVar1 = FUN_00403aef(2);
    FUN_00407945(iVar1 + 1);
  }
  return;
}


// ==== FUN_00406052 @ 00406052

undefined4 FUN_00406052(void)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_004145ec == 0) && (DAT_004145e4 == 0)) {
    IVar1 = FUN_00401345();
    if (IVar1 == 1) {
      iVar2 = FUN_0040c7b8(DAT_00414f68,&local_8);
      if (((iVar2 != 0) && (local_8 < 10)) && (DAT_004145f8 == 2)) {
        if (DAT_00414f84 != 0) {
          FUN_00401520();
        }
        iVar2 = FUN_0040c855(DAT_00414f68);
        if (0 < iVar2) {
          DAT_00414700 = local_8;
          FUN_0040156f();
        }
        FUN_0040c999();
      }
      SendMessageA(DAT_00417088,2,0,0);
      WinHelpA(DAT_00417088,s_SWEEKEND_HLP_004142d8,2,0);
    }
  }
  else {
    SendMessageA(DAT_00417088,2,0,0);
    WinHelpA(DAT_00417088,s_SWEEKEND_HLP_004142d8,2,0);
  }
  FUN_0040c999();
  return 0;
}


// ==== FUN_00406152 @ 00406152

void __cdecl FUN_00406152(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  INT_PTR IVar1;
  int iVar2;
  int local_8;
  
  switch(param_3) {
  case 0x65:
    if ((DAT_004145ec == 0) && (DAT_004145e4 == 0)) {
      IVar1 = FUN_0040139d();
      if (IVar1 != 1) {
        return;
      }
      iVar2 = FUN_0040c7b8(DAT_00414f68,&local_8);
      if (((iVar2 != 0) && (local_8 < 10)) && (DAT_004145f8 == 2)) {
        if (DAT_00414f84 != 0) {
          FUN_00401520();
        }
        iVar2 = FUN_0040c855(DAT_00414f68);
        if (0 < iVar2) {
          DAT_00414700 = local_8;
          FUN_0040156f();
        }
        FUN_0040c999();
      }
    }
    FUN_00404f6d(1);
    _memset(&DAT_00416518,0,0x10);
    if (DAT_00414f78 != 0) {
      PostMessageA(DAT_00417088,0x111,0x130,0);
    }
    break;
  case 0x66:
    DAT_00414700 = -1;
    FUN_0040156f();
    break;
  case 0x67:
    SendMessageA(DAT_00417088,0x10,0,0);
    break;
  case 0x68:
    FUN_00405f6c();
    break;
  case 0xc9:
    if ((DAT_004145e4 == 0) && (DAT_004145ec == 0)) {
      if (DAT_004145f8 != 2) {
        FUN_0040512c();
      }
    }
    else {
      SendMessageA(DAT_00417088,0x111,0x65,0);
    }
    break;
  case 0x12e:
    FUN_0040142a();
    break;
  case 0x12f:
    WinHelpA(DAT_00417088,s_SWEEKEND_HLP_004142d8,0xb,0);
    break;
  case 0x130:
    FUN_004014d1();
    break;
  case 0x131:
    DAT_00414f7c = (uint)(DAT_00414f7c == 0);
    FUN_00401000();
  }
  return;
}


// ==== FUN_0040644d @ 0040644d

void __cdecl FUN_0040644d(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int local_8;
  
  if (param_2 == 0) {
    FUN_00409f0a(param_1,0xf,DAT_00414714 * 7);
    local_8 = param_1[3] + 1;
    if (DAT_00414714 < 1) {
      if (7 < local_8) {
        local_8 = 6;
      }
    }
    else if (5 < local_8) {
      local_8 = 4;
    }
    FUN_00409e00(param_1,local_8);
    if (700 < *param_1) {
      *param_3 = 0;
    }
    DAT_00414718 = DAT_00414718 + 1;
    if ((9 < DAT_00414718) && (iVar1 = FUN_00403aef(0x14), iVar1 == 0)) {
      DAT_00414714 = -DAT_00414714;
    }
  }
  else {
    FUN_00409f0a(param_1,-0xf,DAT_00414714 * 7);
    local_8 = param_1[3] + 1;
    if (DAT_00414714 < 1) {
      if (1 < local_8) {
        local_8 = 0;
      }
    }
    else if (3 < local_8) {
      local_8 = 2;
    }
    FUN_00409e00(param_1,local_8);
    if (*param_1 < -100) {
      *param_3 = 0;
    }
    DAT_00414718 = DAT_00414718 + 1;
    if ((9 < DAT_00414718) && (iVar1 = FUN_00403aef(0x14), iVar1 == 0)) {
      DAT_00414714 = -DAT_00414714;
    }
  }
  return;
}


// ==== FUN_004065de @ 004065de

void __cdecl FUN_004065de(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int local_8;
  
  if (param_2 == 0) {
    if (DAT_0041471c == 0) {
      FUN_00409f0a(param_1,0x14,DAT_00414714 * 10);
    }
    local_8 = param_1[3] + 1;
    if (DAT_00414714 < 1) {
      if (7 < local_8) {
        local_8 = 6;
      }
    }
    else if (5 < local_8) {
      local_8 = 4;
    }
    FUN_00409e00(param_1,local_8);
    if (700 < *param_1) {
      *param_3 = 0;
    }
    DAT_00414718 = DAT_00414718 + 1;
    if (DAT_0041471c != 0) {
      DAT_0041471c = DAT_0041471c + 1;
    }
    if (0x1e < DAT_0041471c) {
      DAT_0041471c = 0;
    }
    if (9 < DAT_00414718) {
      iVar1 = FUN_00403aef(0x14);
      if (iVar1 == 0) {
        DAT_00414714 = -DAT_00414714;
      }
      if ((DAT_0041471c == 0) && (iVar1 = FUN_00403aef(0x14), iVar1 == 0)) {
        DAT_0041471c = DAT_0041471c + 1;
      }
    }
  }
  else {
    if (DAT_0041471c == 0) {
      FUN_00409f0a(param_1,-0x14,DAT_00414714 * 10);
    }
    local_8 = param_1[3] + 1;
    if (DAT_00414714 < 1) {
      if (1 < local_8) {
        local_8 = 0;
      }
    }
    else if (3 < local_8) {
      local_8 = 2;
    }
    FUN_00409e00(param_1,local_8);
    if (*param_1 < -100) {
      *param_3 = 0;
    }
    DAT_00414718 = DAT_00414718 + 1;
    if (DAT_0041471c != 0) {
      DAT_0041471c = DAT_0041471c + 1;
    }
    if (0x1e < DAT_0041471c) {
      DAT_0041471c = 0;
    }
    if (9 < DAT_00414718) {
      iVar1 = FUN_00403aef(0x14);
      if (iVar1 == 0) {
        DAT_00414714 = -DAT_00414714;
      }
      if ((DAT_0041471c == 0) && (iVar1 = FUN_00403aef(0x14), iVar1 == 0)) {
        DAT_0041471c = DAT_0041471c + 1;
      }
    }
  }
  return;
}


// ==== FUN_00406823 @ 00406823

void __cdecl FUN_00406823(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_004145e8 != 0) {
    FUN_00407b24();
    if (DAT_00414704 == 0) {
      if (DAT_0041470c == 0) {
        iVar1 = FUN_00403aef(DAT_004145e0);
        if (iVar1 == 0) {
          DAT_00414704 = 1;
          DAT_00414708 = FUN_00403aef(2);
          iVar1 = FUN_00403aef(2);
          if (iVar1 == 0) {
            DAT_00414714 = 1;
          }
          else {
            DAT_00414714 = 0xffffffff;
          }
          DAT_00414718 = 0;
          FUN_00407c42(6);
          if (DAT_00414708 == 0) {
            iVar2 = 100;
            iVar1 = FUN_00403aef(300);
            FUN_00409fa9((int *)&DAT_004209e4,-0x50,iVar1 + 0x32,iVar2);
            FUN_00409e00((int *)&DAT_004209e4,4);
          }
          else {
            iVar2 = 100;
            iVar1 = FUN_00403aef(300);
            FUN_00409fa9((int *)&DAT_004209e4,700,iVar1 + 0x32,iVar2);
            FUN_00409e00((int *)&DAT_004209e4,0);
          }
        }
        else {
          iVar1 = FUN_00403aef(DAT_004145e0 / 2);
          if (iVar1 == 0) {
            DAT_0041470c = 1;
            DAT_00414710 = FUN_00403aef(2);
            iVar1 = FUN_00403aef(2);
            if (iVar1 == 0) {
              DAT_00414714 = 1;
            }
            else {
              DAT_00414714 = 0xffffffff;
            }
            DAT_00414718 = 0;
            iVar1 = FUN_00403aef(3);
            FUN_00407c42(iVar1 + 7);
            if (DAT_00414710 == 0) {
              iVar2 = 100;
              iVar1 = FUN_00403aef(300);
              FUN_00409fa9((int *)&DAT_004209b8,-100,iVar1 + 0x32,iVar2);
              FUN_00409e00((int *)&DAT_004209b8,4);
            }
            else {
              iVar2 = 100;
              iVar1 = FUN_00403aef(300);
              FUN_00409fa9((int *)&DAT_004209b8,700,iVar1 + 0x32,iVar2);
              FUN_00409e00((int *)&DAT_004209b8,0);
            }
          }
        }
      }
      else {
        FUN_0040644d((int *)&DAT_004209b8,DAT_00414710,&DAT_0041470c);
        if (param_1 != 0) {
          FUN_00408229(0);
          SelectPalette(DAT_00417040,DAT_00414bf8,0);
          RealizePalette(DAT_00417040);
          FUN_004097c5();
          FUN_0040826f(0);
        }
      }
    }
    else {
      FUN_004065de((int *)&DAT_004209e4,DAT_00414708,&DAT_00414704);
      if (param_1 != 0) {
        FUN_00408229(0);
        SelectPalette(DAT_00417040,DAT_00414bf8,0);
        RealizePalette(DAT_00417040);
        FUN_004097c5();
        FUN_0040826f(0);
      }
    }
  }
  return;
}


// ==== FUN_00406b46 @ 00406b46

UINT FUN_00406b46(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  HDC hDC;
  uint uVar1;
  int iVar2;
  UINT UVar3;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      FUN_00408229(1);
      SelectPalette(DAT_00417040,DAT_00414bf8,0);
      RealizePalette(DAT_00417040);
      DAT_00414c0c = 1;
      FUN_004097c5();
      FUN_0040826f(1);
      return 0;
    }
    if (param_2 == 1) {
      FUN_00401062(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_0040b3cd();
      FUN_00407d54();
      FUN_004010a5(param_1);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      FUN_00405ff7(param_1,0x1c,(int)param_3);
      return 0;
    }
    if (param_2 == 0x10) {
      UVar3 = FUN_00406052();
      return UVar3;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(400);
      GdiFlush();
      hDC = GetDC((HWND)0x0);
      ReleaseDC((HWND)0x0,hDC);
      Sleep(400);
      GdiFlush();
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00416498;
      *(undefined4 *)(param_4 + 0xc) = DAT_004164a8;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_00417088,6);
        return 0;
      }
      if ((DAT_004145e4 != 0) || (DAT_004145ec != 0)) {
        SendMessageA(DAT_00417088,0x111,0x65,0);
      }
      return 0;
    }
    if ((param_2 == 0x86) && (param_3 != (HWND)0x0)) {
      InvalidateRect(DAT_00417088,(RECT *)0x0,0);
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if ((DAT_004145e4 != 0) || (DAT_004145ec != 0)) {
        SendMessageA(DAT_00417088,0x111,0x65,0);
        return 0;
      }
      uVar1 = GetMessageTime();
      if (uVar1 < DAT_00416510) {
        DAT_00416510 = GetTickCount();
        return 0;
      }
      FUN_00405c6a((param_4 & 0xffff) - 200,0xbe - (param_4 >> 0x10));
      iVar2 = FUN_0040492f(0x4164b0,0x4163e0);
      if (iVar2 != 0) {
        DAT_00414f68 = DAT_00414f68 + (DAT_004145d8 * 5 + 10) * (DAT_004145dc / 7 + 1);
        FUN_00407c42(3);
        FUN_00405eac();
        FUN_00405e0c();
        FUN_00404df5();
        return 0;
      }
      if ((DAT_004145f8 == 2) && (DAT_004145d8 == 0)) {
        DAT_004145ec = 1;
        FUN_00405b01();
        return 0;
      }
      return 0;
    }
    if (param_2 == 0x111) {
      FUN_00406152(param_1,0x111,(short)param_3);
      return 0;
    }
    if (param_2 == 0x113) {
      FUN_00406823(1);
      return 0;
    }
  }
  else {
    if (param_2 == 0x204) {
      if ((DAT_004145e4 != 0) || (DAT_004145ec != 0)) {
        SendMessageA(DAT_00417088,0x111,0x65,0);
        return 0;
      }
      uVar1 = GetMessageTime();
      if (uVar1 < DAT_00416510) {
        DAT_00416510 = GetTickCount();
        return 0;
      }
      FUN_00405d3b((param_4 & 0xffff) - 200,0xbe - (param_4 >> 0x10));
      iVar2 = FUN_0040492f(0x4164b0,0x4163e0);
      if (iVar2 != 0) {
        DAT_00414f68 = DAT_00414f68 + (DAT_004145d8 * 5 + 10) * (DAT_004145dc / 7 + 1);
        FUN_00407c42(3);
        FUN_00405eac();
        FUN_00405e0c();
        FUN_00404df5();
      }
      if ((DAT_004145f8 == 2) && (DAT_004145d8 == 0)) {
        DAT_004145ec = 1;
        FUN_00405b01();
        return 0;
      }
      return 0;
    }
    if ((param_2 == 0x30f) || ((param_2 == 0x311 && (DAT_00417088 != param_3)))) {
      UVar3 = FUN_00403b6f();
      return UVar3;
    }
  }
  UVar3 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar3;
}


// ==== FUN_004070b1 @ 004070b1

int __cdecl FUN_004070b1(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_004070d2 @ 004070d2

int __cdecl FUN_004070d2(int param_1)

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


// ==== FUN_0040710d @ 0040710d

undefined4 FUN_0040710d(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(s_SpringWeekend_004142c8,(LPCSTR)0x0);
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


// ==== FUN_00407189 @ 00407189

bool __cdecl FUN_00407189(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_004071df @ 004071df

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_004071df(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

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
  
  local_a0 = DAT_00414968;
  puVar10 = &local_9f;
  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  *(undefined1 *)((int)puVar10 + 2) = 0;
  DAT_00416624 = param_1;
  iVar9 = FUN_0040710d();
  if (iVar9 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_SWeekendGameMtx_0041496c);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_20.wParam = 0;
    }
    else {
      bVar1 = FUN_00407189(0x600000);
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
          FUN_0040bfbe();
          FUN_0040c058((uint *)s_SWEEKEND_DLL_004143d8);
          FUN_0040c206((uint *)s_SWEEKEN1_DLL_004144d8);
          FUN_0040bfd6((uint *)s_MSPuzzle_dat_00414fb8);
          FUN_0040c206((uint *)s_SWEEKEND_HLP_004142d8);
          FUN_0040bdeb();
          FUN_0040be05(DAT_00416624);
          FUN_0040be44(s_SWEEKEN1_DLL_004144d8);
          FUN_0040be44(s_SWEEKEND_DLL_004143d8);
          FUN_0040bd20(DAT_00416624,100,&local_a0,0x78);
          FUN_00403ad0();
          FUN_0040c528();
          FUN_00407f6b();
          _DAT_00417090 = 0x300;
          _DAT_00417092 = 0x100;
          DAT_00414c00 = 0x274;
          DAT_00414c04 = 400;
          iVar9 = FUN_00408ade();
          if (iVar9 == 0) {
            FUN_00407d54();
            local_20.wParam = 0;
          }
          else {
            pHVar4 = GetDC((HWND)0x0);
            iVar9 = FUN_0040864c(pHVar4,s_TITLEBMP_0041497c,DAT_00414c3c,&DAT_0041fe18);
            if (iVar9 == 0) {
              ReleaseDC((HWND)0x0,pHVar4);
              FUN_00407d54();
              local_20.wParam = 0;
            }
            else {
              DAT_004164fc = FUN_004085a2(s_GAMEOVERBMP_00414988);
              ReleaseDC((HWND)0x0,pHVar4);
              if (DAT_00414c3c == (void *)0x0) {
                FUN_00407d54();
                local_20.wParam = 0;
              }
              else {
                DAT_00414c10 = 1;
                DAT_00414c14 = &DAT_0041fe18;
                if (param_2 == 0) {
                  local_cc.style = 0;
                  local_cc.lpfnWndProc = FUN_00406b46;
                  local_cc.cbClsExtra = 0;
                  local_cc.cbWndExtra = 0;
                  local_cc.hIcon = (HICON)0x0;
                  local_cc.hCursor = (HCURSOR)0x0;
                  local_cc.hbrBackground = (HBRUSH)0x0;
                  local_cc.lpszMenuName = (LPCSTR)0x0;
                  local_cc.lpszClassName = (LPCSTR)0x0;
                  local_cc.hInstance = DAT_00416624;
                  local_cc.hIcon = LoadIconA(DAT_00416624,s_MAINICON_00414994);
                  local_cc.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
                  local_cc.hbrBackground = GetStockObject(5);
                  local_cc.lpszClassName = s_SpringWeekend_004142c8;
                  AVar2 = RegisterClassA(&local_cc);
                  if (AVar2 == 0) {
                    return 0xff;
                  }
                }
                InitCommonControls();
                DAT_0041648c = FUN_0040bbfb(DAT_00416624,s_ACCELERATORS_1_004149a0);
                if (DAT_0041648c == (HACCEL)0x0) {
                  FUN_00407d54();
                  local_20.wParam = 0;
                }
                else {
                  DAT_00416434 = FUN_0040bcbe(DAT_00416624,s_MainMenu_004149b0);
                  local_a4 = GetVersion();
                  if ((byte)local_a4 < 4) {
                    iVar9 = GetSystemMetrics(5);
                    DAT_00416498 = iVar9 * 2 + DAT_00414c00;
                    iVar9 = GetSystemMetrics(6);
                    iVar5 = GetSystemMetrics(4);
                    iVar6 = GetSystemMetrics(0xf);
                    DAT_004164a8 = iVar9 * 2 + iVar5 + iVar6 + DAT_00414c04;
                    pvVar13 = (LPVOID)0x0;
                    pHVar11 = (HWND)0x0;
                    iVar9 = DAT_00416498;
                    iVar5 = DAT_004164a8;
                    pHVar12 = DAT_00416434;
                    iVar6 = FUN_004070d2(DAT_004164a8);
                    iVar7 = FUN_004070b1(DAT_00416498);
                    DAT_00417088 = CreateWindowExA(0,s_SpringWeekend_004142c8,&local_a0,0xca0000,
                                                   iVar7,iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,
                                                   pvVar13);
                  }
                  else {
                    iVar9 = GetSystemMetrics(7);
                    DAT_00416498 = iVar9 * 2 + DAT_00414c00;
                    iVar9 = GetSystemMetrics(8);
                    iVar5 = GetSystemMetrics(4);
                    iVar6 = GetSystemMetrics(0xf);
                    DAT_004164a8 = iVar9 * 2 + iVar5 + iVar6 + DAT_00414c04;
                    pvVar13 = (LPVOID)0x0;
                    pHVar11 = (HWND)0x0;
                    iVar9 = DAT_00416498;
                    iVar5 = DAT_004164a8;
                    pHVar12 = DAT_00416434;
                    iVar6 = FUN_004070d2(DAT_00414c04);
                    iVar7 = FUN_004070b1(DAT_00416498);
                    DAT_00417088 = CreateWindowExA(0x100,s_SpringWeekend_004142c8,&local_a0,0xca0000
                                                   ,iVar7,iVar6,iVar9,iVar5,pHVar11,pHVar12,param_1,
                                                   pvVar13);
                  }
                  FUN_00403bd6();
                  ShowWindow(DAT_00417088,param_4);
                  FUN_0040b423();
                  UpdateWindow(DAT_00417088);
                  SetTimer(DAT_00417088,1,0x32,(TIMERPROC)0x0);
                  FUN_00401000();
                  while (BVar8 = GetMessageA(&local_20,(HWND)0x0,0,0), BVar8 != 0) {
                    iVar9 = TranslateAcceleratorA(DAT_00417088,DAT_0041648c,&local_20);
                    if (iVar9 == 0) {
                      TranslateMessage(&local_20);
                      DispatchMessageA(&local_20);
                    }
                  }
                  FUN_0040b3cd();
                  FUN_0040c999();
                  FUN_00407d54();
                }
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


// ==== FUN_00407750 @ 00407750

void FUN_00407750(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0041663c == 1) || (DAT_0041663c == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00414b58,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00414b58,0x804,2,(DWORD_PTR)local_c);
    DAT_00414b58 = 0;
    Sleep(1);
    DAT_0041663c = 0;
  }
  return;
}


// ==== FUN_004077f5 @ 004077f5

void FUN_004077f5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_004149c4 != 0) && (DAT_0041663c == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_00414b58,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_0041663c = 3;
  }
  return;
}


// ==== FUN_00407868 @ 00407868

void __cdecl FUN_00407868(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_004149c4 != 0) {
    if (DAT_0041663c == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_00414b58,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_00414b58,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_00407945(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_0041663c = 1;
    }
    else {
      FUN_00407945(param_1);
    }
  }
  return;
}


// ==== FUN_00407945 @ 00407945

void __cdecl FUN_00407945(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_004149c4 == 0) {
    FUN_00407750();
  }
  else {
    if (((param_1 == DAT_00416638) && (0 < param_1)) && (DAT_0041663c == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_00414b58,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_0041663c != 4) {
      FUN_00407750();
    }
    if (DAT_004149c4 != 0) {
      if (0 < param_1) {
        DAT_00416638 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00416638;
      }
      if ((0 < param_1) && (param_1 < 3)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00416640 + param_1 * 0x100;
        local_20 = s_sequencer_00414b5c;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_00414b58 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_00414b58;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_00414b58 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00414b58,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_0041663c = 1;
          }
          else {
            DAT_0041663c = 4;
          }
        }
        else {
          DAT_0041663c = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_00407b24 @ 00407b24

void FUN_00407b24(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_004149c4 != 0) {
    if (DAT_0041663c == 1) {
      if (DAT_00414b58 == 0) {
        DAT_0041663c = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_00414b58,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_00414b58,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_0041663c = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_0041663c = 4;
        }
      }
    }
    else if (DAT_0041663c == 4) {
      FUN_00407945(-1);
    }
  }
  return;
}


// ==== FUN_00407c42 @ 00407c42

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00407c42(int param_1)

{
  DWORD DVar1;
  
  if (DAT_004149c0 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_004149c8) {
      DAT_004149c8 = DVar1;
    }
    if ((DAT_004149c8 <= DVar1 - _DAT_004149cc) ||
       (*(int *)(&DAT_00416c4c + param_1 * 0x10) < DAT_004149d0)) {
      sndPlaySoundA((LPCSTR)0x0,5);
      Sleep(1);
      DAT_004149c8 = GetTickCount();
      _DAT_004149cc = *(int *)(&DAT_00416c48 + param_1 * 0x10);
      DAT_004149d0 = *(int *)(&DAT_00416c4c + param_1 * 0x10);
      sndPlaySoundA(*(LPCSTR *)(&DAT_00416c40 + param_1 * 0x10),5);
    }
  }
  return;
}


// ==== FUN_00407d54 @ 00407d54

void FUN_00407d54(void)

{
  int local_c;
  int local_8;
  
  FUN_00407750();
  FUN_00407c42(0);
  for (local_8 = 1; local_8 < 10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00416c44 + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00416c44 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00416c44 + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_00416c40 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 3; local_c = local_c + 1) {
    DeleteFileA(&DAT_00416640 + local_c * 0x100);
  }
  return;
}


// ==== FUN_00407e3c @ 00407e3c

void __cdecl FUN_00407e3c(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_0040b770(DAT_00416624,param_2,&DAT_00414b68);
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


// ==== FUN_00407f6b @ 00407f6b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407f6b(void)

{
  int local_8;
  
  _DAT_00416c40 = 0;
  _DAT_00416c44 = 0;
  FUN_00407e3c((int *)&DAT_00416c50,s_ROTATEWAV_00414b70);
  _DAT_00416c5c = 5;
  FUN_00407e3c(&DAT_00416c60,s_NOROTATEWAV_00414b7c);
  _DAT_00416c6c = 5;
  FUN_00407e3c((int *)&DAT_00416c70,s_NEXTLEVELWAV_00414b88);
  _DAT_00416c7c = 1;
  FUN_00407e3c((int *)&DAT_00416c80,s_GAMEOVER1WAV_00414b98);
  _DAT_00416c8c = 1;
  FUN_00407e3c((int *)&DAT_00416c90,s_GAMEOVER2WAV_00414ba8);
  _DAT_00416c9c = 1;
  FUN_00407e3c((int *)&DAT_00416ca0,s_BEEWAV_00414bb8);
  _DAT_00416cac = 3;
  FUN_00407e3c((int *)&DAT_00416cb0,s_TIME1WAV_00414bc0);
  _DAT_00416cbc = 3;
  FUN_00407e3c((int *)&DAT_00416cc0,s_TIME2WAV_00414bcc);
  _DAT_00416ccc = 3;
  FUN_00407e3c((int *)&DAT_00416cc0,s_TIME2WAV_00414bd8);
  _DAT_00416ccc = 3;
  FUN_00407e3c((int *)&DAT_00416cd0,s_TIME3WAV_00414be4);
  _DAT_00416cdc = 3;
  for (local_8 = 1; local_8 < 3; local_8 = local_8 + 1) {
    GetTempPathA(200,&DAT_00416640 + local_8 * 0x100);
    FUN_0040cb90((uint *)(&DAT_00416640 + local_8 * 0x100),(uint *)(&DAT_004149d8 + local_8 * 0x20))
    ;
    FUN_0040b993(&DAT_00414a98 + local_8 * 0x20,&DAT_00414bf0,&DAT_00416640 + local_8 * 0x100);
  }
  return;
}


// ==== FUN_00408160 @ 00408160

undefined * __cdecl FUN_00408160(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0040cb80((uint *)&DAT_00417498,param_1);
  sVar1 = _strlen(&DAT_00417498);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_00417497)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_00417498)[param_3 + sVar1] = 0;
  return &DAT_00417498;
}


// ==== FUN_00408229 @ 00408229

void __cdecl FUN_00408229(int param_1)

{
  if (param_1 == 0) {
    DAT_00417040 = GetDC(DAT_00417088);
  }
  else {
    DAT_00417040 = BeginPaint(DAT_00417088,(LPPAINTSTRUCT)&DAT_00417048);
  }
  return;
}


// ==== FUN_0040826f @ 0040826f

void __cdecl FUN_0040826f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_00417088,DAT_00417040);
  }
  else {
    EndPaint(DAT_00417088,(PAINTSTRUCT *)&DAT_00417048);
  }
  return;
}


// ==== FUN_004082b1 @ 004082b1

bool __cdecl FUN_004082b1(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_004082fa @ 004082fa

bool __cdecl FUN_004082fa(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_00408390 @ 00408390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_00408390(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_0040b7e8(DAT_00416624,param_2,(LPCSTR)0x2,&local_10);
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
        DAT_00414bfc = 0;
        _DAT_00417090 = 0x300;
        _DAT_00417092 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_00417094)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_00417095)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_00417096)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_00417097)[local_28 * 4] = 0;
        }
        if (DAT_00414bf8 == (HPALETTE)0x0) {
          DAT_00414bf8 = CreatePalette((LOGPALETTE *)&DAT_00417090);
        }
      }
      hPal = SelectPalette(param_1,DAT_00414bf8,0);
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


// ==== FUN_004085a2 @ 004085a2

HGLOBAL __cdecl FUN_004085a2(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_0040b7e8(DAT_00416624,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_0040864c @ 0040864c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040864c(HDC param_1,LPCSTR param_2,void *param_3,undefined1 *param_4)

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
  local_c = FUN_0040b7e8(DAT_00416624,param_2,(LPCSTR)0x2,&local_8);
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
      if (DAT_00414c08 < local_8) {
        local_8 = DAT_00414c08;
      }
      FID_conflict__memcpy(param_3,(void *)((int)_Src + iVar3),local_8);
      if ((DAT_00414bfc != 0) && (local_42a == 8)) {
        DAT_00414bfc = 0;
        _DAT_00417090 = 0x300;
        _DAT_00417092 = 0x100;
        for (local_444 = 0; puVar1 = local_10, local_444 < 0x100; local_444 = local_444 + 1) {
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 2] >> 2);
          local_10 = local_10 + 1;
          (&DAT_00417094)[local_444 * 4] = abStack_410[local_444 * 4 + 2];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4 + 1] >> 2);
          local_10 = puVar1 + 2;
          (&DAT_00417095)[local_444 * 4] = abStack_410[local_444 * 4 + 1];
          *local_10 = (char)((int)(uint)abStack_410[local_444 * 4] >> 2);
          local_10 = puVar1 + 3;
          (&DAT_00417096)[local_444 * 4] = abStack_410[local_444 * 4];
          (&DAT_00417097)[local_444 * 4] = 0;
        }
        DAT_00414bf8 = CreatePalette((LOGPALETTE *)&DAT_00417090);
        local_448 = SelectPalette(param_1,DAT_00414bf8,0);
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


// ==== FUN_004088e0 @ 004088e0

void FUN_004088e0(void)

{
  DAT_00414c08 = DAT_00414c04 * DAT_00414c00;
  DAT_00414c18 = 0;
  DAT_00414c1c = 0;
  DAT_00414c20 = DAT_00414c00 + -1;
  DAT_00414c24 = DAT_00414c04 + -1;
  return;
}


// ==== FUN_0040892b @ 0040892b

undefined4 * __cdecl FUN_0040892b(undefined4 *param_1,int param_2,int param_3)

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


// ==== FUN_00408ade @ 00408ade

undefined4 FUN_00408ade(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_004088e0();
  DAT_00414c3c = _malloc(DAT_00414c08);
  if (DAT_00414c3c == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    _memset(DAT_00414c3c,0,DAT_00414c08);
    puVar2 = FUN_0040892b(&DAT_00414c3c,DAT_00414c00,DAT_00414c04);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      DAT_00414c28 = DAT_00414c18;
      DAT_00414c2c = DAT_00414c1c;
      DAT_00414c30 = DAT_00414c20;
      DAT_00414c34 = DAT_00414c24;
      AfxResetMsgCache();
      FUN_00408bab();
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== AfxResetMsgCache @ 00408b87

/* Library Function - Single Match
    void __stdcall AfxResetMsgCache(void)
   
   Library: Visual Studio 1998 Debug */

void AfxResetMsgCache(void)

{
  _memset(&DAT_00417518,0,0x8900);
  return;
}


// ==== FUN_00408bab @ 00408bab

void FUN_00408bab(void)

{
  int local_8;
  
  _memset(&DAT_00420120,0,0x2c00);
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00420128 + local_8 * 0x2c) = 0xffffffff;
    *(undefined4 *)(&DAT_00420130 + local_8 * 0x2c) = 1;
    *(undefined4 *)(&DAT_00420134 + local_8 * 0x2c) = 1;
    *(int *)(&DAT_00420140 + local_8 * 0x2c) = DAT_00414c00 + -1;
    *(int *)(&DAT_00420144 + local_8 * 0x2c) = DAT_00414c04 + -1;
  }
  return;
}


// ==== FUN_00408c6a @ 00408c6a

void __cdecl FUN_00408c6a(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(DAT_00425d20 + DAT_00414c00 * param_2 + param_1) = param_3;
  return;
}


// ==== FUN_00408c96 @ 00408c96

undefined8 __cdecl FUN_00408c96(int param_1,uint param_2)

{
  return CONCAT44((int)((ulonglong)DAT_00414c00 * (ulonglong)param_2 >> 0x20),
                  *(undefined4 *)
                   (DAT_00425d20 + (int)((ulonglong)DAT_00414c00 * (ulonglong)param_2) + param_1));
}


// ==== FUN_00408cba @ 00408cba

void __cdecl FUN_00408cba(short *param_1)

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
    if (*(short **)(&DAT_00420148 + local_8 * 0x2c) == param_1) {
      *(undefined4 *)(&DAT_00420148 + local_8 * 0x2c) = 0;
    }
  }
  return;
}


// ==== FUN_00408db7 @ 00408db7

void __cdecl
FUN_00408db7(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
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


// ==== FUN_00408e36 @ 00408e36

bool __cdecl FUN_00408e36(int *param_1,int *param_2)

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


// ==== FUN_00408eea @ 00408eea

void __cdecl FUN_00408eea(LONG param_1,LONG param_2,LONG param_3,LONG param_4)

{
  int iVar1;
  BOOL BVar2;
  tagRECT local_1c;
  int local_c;
  
  BVar2 = IntersectRect(&local_1c,(RECT *)&param_1,(RECT *)&DAT_00414c18);
  if (BVar2 != 0) {
    param_1 = local_1c.left;
    param_2 = local_1c.top;
    param_3 = local_1c.right;
    param_4 = local_1c.bottom;
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if ((*(int *)(&DAT_00423530 + local_c * 0x14) != 0) &&
         (BVar2 = IntersectRect(&local_1c,(RECT *)(&DAT_00423520 + local_c * 0x14),(RECT *)&param_1)
         , BVar2 != 0)) {
        iVar1 = local_c * 0x14;
        FUN_00408db7(&param_1,*(int *)(&DAT_00423520 + iVar1),*(int *)(&DAT_00423524 + iVar1),
                     *(int *)(&DAT_00423528 + iVar1),*(int *)(&DAT_0042352c + iVar1),param_1,param_2
                     ,param_3,param_4);
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_00423520 + iVar1) = param_1;
        *(LONG *)(&DAT_00423524 + iVar1) = param_2;
        *(LONG *)(&DAT_00423528 + iVar1) = param_3;
        *(LONG *)(&DAT_0042352c + iVar1) = param_4;
        *(undefined4 *)(&DAT_00423530 + local_c * 0x14) = 1;
        return;
      }
    }
    for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
      if (*(int *)(&DAT_00423530 + local_c * 0x14) == 0) {
        iVar1 = local_c * 0x14;
        *(LONG *)(&DAT_00423520 + iVar1) = param_1;
        *(LONG *)(&DAT_00423524 + iVar1) = param_2;
        *(LONG *)(&DAT_00423528 + iVar1) = param_3;
        *(LONG *)(&DAT_0042352c + iVar1) = param_4;
        *(undefined4 *)(&DAT_00423530 + local_c * 0x14) = 1;
        return;
      }
    }
  }
  return;
}


// ==== FUN_00409083 @ 00409083

void __cdecl
FUN_00409083(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_2 = *param_1;
  *param_3 = param_1[1];
  *param_4 = param_1[2];
  return;
}


// ==== FUN_004090b3 @ 004090b3

void __cdecl FUN_004090b3(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00414c00 - param_3;
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


// ==== FUN_004090ec @ 004090ec

void __cdecl FUN_004090ec(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (DAT_00414c00 + -1 < param_5) {
    param_5 = DAT_00414c00 + -1;
  }
  if (DAT_00414c04 + -1 < param_6) {
    param_6 = DAT_00414c04 + -1;
  }
  if ((param_3 <= param_5) && (param_4 <= param_6)) {
    iVar1 = param_4 * DAT_00414c00 + param_3;
    FUN_004090b3((undefined1 *)(param_1 + iVar1),(undefined1 *)(param_2 + iVar1),
                 (param_5 - param_3) + 1,(param_6 - param_4) + 1);
  }
  return;
}


// ==== FUN_004091bb @ 004091bb

void __cdecl FUN_004091bb(int param_1,int param_2,int param_3,int param_4)

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
  puVar6 = (undefined1 *)(param_2 + DAT_00414c00 * (param_4 - iVar4) + param_3);
  iVar2 = DAT_00414c00 - iVar1;
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


// ==== FUN_00409270 @ 00409270

void __cdecl
FUN_00409270(char *param_1,char *param_2,uint param_3,int param_4,short param_5,char param_6)

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
    param_2 = param_2 + (DAT_00414c00 - param_3);
    param_5 = param_5 + -1;
    uVar3 = param_3;
  } while (param_5 != 0);
  return;
}


// ==== FUN_004092c5 @ 004092c5

void __cdecl
FUN_004092c5(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char param_7)

{
  uint uVar1;
  int local_1c;
  int local_10;
  int local_c;
  
  if ((param_1 <= DAT_00414c30) && (param_2 <= DAT_00414c34)) {
    local_10 = param_3 + param_1 + -1;
    local_c = 0;
    if (param_1 < DAT_00414c28) {
      local_c = DAT_00414c28 - param_1;
      param_1 = DAT_00414c28;
    }
    local_1c = param_4 + param_2 + -1;
    if (param_2 < DAT_00414c2c) {
      local_c = local_c + (DAT_00414c2c - param_2) * param_3;
      param_2 = DAT_00414c2c;
    }
    if (DAT_00414c30 < local_10) {
      local_10 = DAT_00414c30;
    }
    if (DAT_00414c34 < local_1c) {
      local_1c = DAT_00414c34;
    }
    if ((((DAT_00414c28 <= local_10) && (DAT_00414c2c <= local_1c)) &&
        (uVar1 = (local_10 - param_1) + 1, 0 < (int)uVar1)) && ((int)uVar1 <= DAT_00414c00)) {
      FUN_00409270((char *)(param_5 + local_c),(char *)(param_6 + param_2 * DAT_00414c00 + param_1),
                   uVar1,param_3 - uVar1,((short)local_1c - (short)param_2) + 1,param_7);
    }
  }
  return;
}


// ==== FUN_00409429 @ 00409429

void __cdecl FUN_00409429(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_00414c28 = param_1[6];
    DAT_00414c2c = param_1[7];
    DAT_00414c30 = param_1[8];
    DAT_00414c34 = param_1[9];
    FUN_004092c5(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_00414c38,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_0040951e @ 0040951e

void __cdecl FUN_0040951e(int *param_1)

{
  if (((-1 < param_1[3]) && (param_1[3] < (int)*(short *)param_1[10])) && (param_1[10] != 0)) {
    DAT_00414c28 = param_1[6];
    DAT_00414c2c = param_1[7];
    DAT_00414c30 = param_1[8];
    DAT_00414c34 = param_1[9];
    FUN_004092c5(*param_1 - (int)*(short *)(param_1[10] + 0x82 + param_1[3] * 4),
                 param_1[1] - (int)*(short *)(param_1[10] + 0x84 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 2 + param_1[3] * 4),
                 (int)*(short *)(param_1[10] + 4 + param_1[3] * 4),
                 *(int *)(param_1[10] + 0x124 + param_1[3] * 4),DAT_00414c3c,
                 *(char *)(param_1[3] + 0x102 + param_1[10]));
  }
  return;
}


// ==== FUN_00409613 @ 00409613

undefined4 __cdecl FUN_00409613(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_3[3] < 0) || ((int)*(short *)param_3[10] <= param_3[3])) || (param_3[10] == 0)) ||
     (param_3[2] < 1)) {
    uVar1 = 0;
  }
  else {
    DAT_00414c28 = param_3[6];
    DAT_00414c2c = param_3[7];
    DAT_00414c30 = param_3[8];
    DAT_00414c34 = param_3[9];
    if ((param_1 < DAT_00414c28) || (DAT_00414c30 < param_1)) {
      uVar1 = 0;
    }
    else if ((param_2 < DAT_00414c2c) || (DAT_00414c34 < param_2)) {
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


// ==== FUN_0040977b @ 0040977b

undefined4 __cdecl FUN_0040977b(int param_1,int param_2)

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


// ==== FUN_004097c5 @ 004097c5

void FUN_004097c5(void)

{
  int iVar1;
  int local_2c;
  int local_28;
  
  if (DAT_00414c0c == 0) {
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_00423530 + local_2c * 0x14) != 0) {
        iVar1 = local_2c * 0x14;
        FUN_004090ec((int)DAT_00414c3c,(int)DAT_00414c38,*(int *)(&DAT_00423520 + iVar1),
                     *(int *)(&DAT_00423524 + iVar1),*(int *)(&DAT_00423528 + iVar1),
                     *(int *)(&DAT_0042352c + iVar1));
      }
    }
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_00422d20 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_00422d24 + local_28 * 8) =
           *(undefined4 *)(&DAT_00420128 + local_28 * 0x2c);
    }
    _qsort(&DAT_00422d20,0xff,8,FUN_0040977b);
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_00423530 + local_2c * 0x14) != 0) {
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          if (0 < *(int *)(&DAT_00422d24 + local_28 * 8)) {
            FUN_00409429((int *)(&DAT_00420120 + *(int *)(&DAT_00422d20 + local_28 * 8) * 0x2c));
          }
        }
      }
    }
    for (local_2c = 0; local_2c < 0x200; local_2c = local_2c + 1) {
      if (*(int *)(&DAT_00423530 + local_2c * 0x14) != 0) {
        FUN_0040b6c5((int *)(&DAT_00423520 + local_2c * 0x14));
      }
    }
  }
  else {
    FID_conflict__memcpy(DAT_00414c38,DAT_00414c3c,DAT_00414c08);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      *(int *)(&DAT_00422d20 + local_28 * 8) = local_28;
      *(undefined4 *)(&DAT_00422d24 + local_28 * 8) =
           *(undefined4 *)(&DAT_00420128 + local_28 * 0x2c);
    }
    _qsort(&DAT_00422d20,0xff,8,FUN_0040977b);
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      if (0 < *(int *)(&DAT_00422d24 + local_28 * 8)) {
        FUN_00409429((int *)(&DAT_00420120 + *(int *)(&DAT_00422d20 + local_28 * 8) * 0x2c));
      }
    }
    FUN_0040b6c5(&DAT_00414c18);
    DAT_00414c0c = 0;
  }
  _memset(&DAT_00423520,0,0x2800);
  GdiFlush();
  return;
}


// ==== FUN_00409a8c @ 00409a8c

void __cdecl FUN_00409a8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  FID_conflict__memcpy(DAT_00414c38,DAT_00414c3c,DAT_00414c08);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    *(int *)(&DAT_00422d20 + local_38 * 8) = local_38;
    *(undefined4 *)(&DAT_00422d24 + local_38 * 8) = *(undefined4 *)(&DAT_00420128 + local_38 * 0x2c)
    ;
  }
  _qsort(&DAT_00422d20,0xff,8,FUN_0040977b);
  for (local_38 = 0; local_38 < 0x100; local_38 = local_38 + 1) {
    if (0 < *(int *)(&DAT_00422d24 + local_38 * 8)) {
      FUN_00409429((int *)(&DAT_00420120 + *(int *)(&DAT_00422d20 + local_38 * 8) * 0x2c));
    }
  }
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  FUN_0040b6c5(&local_34);
  GdiFlush();
  return;
}


// ==== FUN_00409b9b @ 00409b9b

void __cdecl FUN_00409b9b(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
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
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00409cdc @ 00409cdc

void __cdecl FUN_00409cdc(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (1 < *(short *)param_1[10])) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
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
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00409e00 @ 00409e00

void __cdecl FUN_00409e00(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[3] != param_2)) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
    if ((-1 < param_2) && (param_2 < *(short *)param_1[10])) {
      FUN_00408e36(param_1,&local_14);
      FUN_00408eea(local_14,local_10,local_c,local_8);
      param_1[3] = param_2;
      FUN_00408e36(param_1,&local_14);
      FUN_00408eea(local_14,local_10,local_c,local_8);
    }
  }
  return;
}


// ==== FUN_00409ed6 @ 00409ed6

void __cdecl FUN_00409ed6(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  return;
}


// ==== FUN_00409ef0 @ 00409ef0

void __cdecl FUN_00409ef0(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== FUN_00409f0a @ 00409f0a

void __cdecl FUN_00409f0a(int *param_1,int param_2,int param_3)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && ((param_2 != 0 || (param_3 != 0)))) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
    *param_1 = *param_1 + param_2;
    param_1[1] = param_1[1] + param_3;
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_00409fa9 @ 00409fa9

void __cdecl FUN_00409fa9(int *param_1,int param_2,int param_3,int param_4)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) &&
     (((*param_1 != param_2 || (param_1[1] != param_3)) || (param_1[2] != param_4)))) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4;
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040a069 @ 0040a069

void __cdecl FUN_0040a069(int *param_1)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (-1 < param_1[2])) {
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
    param_1[2] = -1;
  }
  return;
}


// ==== FUN_0040a0d2 @ 0040a0d2

void __cdecl FUN_0040a0d2(int *param_1,int param_2)

{
  LONG local_14;
  LONG local_10;
  LONG local_c;
  LONG local_8;
  
  if ((param_1[10] != 0) && (param_1[2] != param_2)) {
    param_1[2] = param_2;
    FUN_00408e36(param_1,&local_14);
    FUN_00408eea(local_14,local_10,local_c,local_8);
  }
  return;
}


// ==== FUN_0040a13c @ 0040a13c

void __cdecl FUN_0040a13c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[10] = param_2;
  return;
}


// ==== FUN_0040a17c @ 0040a17c

void __cdecl FUN_0040a17c(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5)

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


// ==== FUN_0040a1c5 @ 0040a1c5

undefined4 __cdecl FUN_0040a1c5(LPCSTR param_1,short *param_2)

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
        if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
          local_34 = (undefined1 *)DAT_00414c14;
          for (local_398 = 0; (int)local_398 < 0x100; local_398 = local_398 + 1) {
            local_3c4 = 0x7fff;
            local_38 = 0;
            for (local_39c = 0; local_39c < 0x100; local_39c = local_39c + 1) {
              iVar2 = FUN_0040d310((uint)*(byte *)(local_39c * 3 + 2 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3 + 2]);
              iVar3 = FUN_0040d310((uint)*(byte *)(local_39c * 3 + (int)local_34) -
                                   (uint)(byte)local_10[local_398 * 3]);
              local_c = FUN_0040d310((uint)*(byte *)(local_39c * 3 + 1 + (int)local_34) -
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
          if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
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
        if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
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
            FUN_0040a17c(*(undefined1 **)(param_2 + local_398 * 2 + 0x92),(int)local_394,
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


// ==== FUN_0040a9cb @ 0040a9cb

undefined4 __cdecl FUN_0040a9cb(LPCSTR param_1,short *param_2)

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
  
  local_14 = FUN_0040b7e8(DAT_00416624,param_1,s_SPRITE_00414c40,&local_3d0);
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
      if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
        local_3c = (undefined1 *)DAT_00414c14;
        for (local_39c = 0; (int)local_39c < 0x100; local_39c = local_39c + 1) {
          local_3c8 = 0x7fff;
          local_40 = 0;
          for (local_3a0 = 0; local_3a0 < 0x100; local_3a0 = local_3a0 + 1) {
            iVar2 = FUN_0040d310((uint)*(byte *)(local_3a0 * 3 + 2 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3 + 2]);
            iVar3 = FUN_0040d310((uint)*(byte *)(local_3a0 * 3 + (int)local_3c) -
                                 (uint)(byte)local_18[local_39c * 3]);
            local_10 = FUN_0040d310((uint)*(byte *)(local_3a0 * 3 + 1 + (int)local_3c) -
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
        if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
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
      if ((DAT_00414c10 != 0) && (DAT_00414c14 != 0)) {
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
          FUN_0040a17c(*(undefined1 **)(param_2 + local_39c * 2 + 0x92),(int)local_398,
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


// ==== FUN_0040b20a @ 0040b20a

void __cdecl FUN_0040b20a(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x28) = param_1;
  *(undefined4 *)(param_2 + 0xc) = 0;
  return;
}


// ==== FUN_0040b22d @ 0040b22d

void __cdecl FUN_0040b22d(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (DAT_00414c00 + -1 < param_4) {
    param_4 = DAT_00414c00 + -1;
  }
  if (DAT_00414c04 + -1 < param_5) {
    param_5 = DAT_00414c04 + -1;
  }
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_3;
  *(int *)(param_1 + 0x20) = param_4;
  *(int *)(param_1 + 0x24) = param_5;
  return;
}


// ==== FUN_0040b2b3 @ 0040b2b3

void __cdecl FUN_0040b2b3(int param_1,int param_2,int param_3,int param_4)

{
  int local_8;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (DAT_00414c00 + -1 < param_3) {
    param_3 = DAT_00414c00 + -1;
  }
  if (DAT_00414c04 + -1 < param_4) {
    param_4 = DAT_00414c04 + -1;
  }
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(int *)(&DAT_00420138 + local_8 * 0x2c) = param_1;
    *(int *)(&DAT_0042013c + local_8 * 0x2c) = param_2;
    *(int *)(&DAT_00420140 + local_8 * 0x2c) = param_3;
    *(int *)(&DAT_00420144 + local_8 * 0x2c) = param_4;
  }
  return;
}


// ==== FUN_0040b391 @ 0040b391

void __cdecl
FUN_0040b391(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  *param_3 = *(undefined4 *)(param_1 + 0x1c);
  *param_4 = *(undefined4 *)(param_1 + 0x20);
  *param_5 = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_0040b3cd @ 0040b3cd

void FUN_0040b3cd(void)

{
  if (DAT_00420118 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00420118);
    DAT_00420118 = (HGDIOBJ)0x0;
  }
  if (DAT_00414bf8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00414bf8);
  }
  DAT_00414bf8 = (HGDIOBJ)0x0;
  return;
}


// ==== FUN_0040b423 @ 0040b423

void FUN_0040b423(void)

{
  BITMAPINFO local_444;
  BYTE aBStack_3f4 [984];
  HDC local_1c;
  int local_10;
  undefined *local_c;
  void *local_8;
  
  local_c = &DAT_0041fe18;
  local_444.bmiHeader.biSize = 0x28;
  local_444.bmiHeader.biPlanes = 1;
  local_444.bmiHeader.biBitCount = 8;
  local_444.bmiHeader.biCompression = 0;
  local_444.bmiHeader.biSizeImage = 0;
  local_444.bmiHeader.biClrUsed = 0;
  local_444.bmiHeader.biClrImportant = 0;
  local_444.bmiHeader.biWidth = DAT_00414c00;
  local_444.bmiHeader.biHeight = DAT_00414c04;
  local_1c = GetDC((HWND)0x0);
  GetSystemPaletteEntries(local_1c,0,10,(LPPALETTEENTRY)&DAT_00417094);
  GetSystemPaletteEntries(local_1c,0xf6,10,(LPPALETTEENTRY)&DAT_0041746c);
  ReleaseDC((HWND)0x0,local_1c);
  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
    local_444.bmiColors[local_10].rgbRed = (&DAT_00417094)[local_10 * 4];
    local_444.bmiColors[local_10].rgbGreen = (&DAT_00417095)[local_10 * 4];
    local_444.bmiColors[local_10].rgbBlue = (&DAT_00417096)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_00417097)[local_10 * 4] = 0;
    aBStack_3f4[local_10 * 4 + 0x3b2] = (&DAT_0041746c)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b1] = (&DAT_0041746d)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b0] = (&DAT_0041746e)[local_10 * 4];
    aBStack_3f4[local_10 * 4 + 0x3b3] = '\0';
    (&DAT_0041746f)[local_10 * 4] = 0;
  }
  for (local_10 = 10; local_10 < 0xf6; local_10 = local_10 + 1) {
    (&DAT_00417094)[local_10 * 4] = local_c[local_10 * 3] * '\x04';
    local_444.bmiColors[local_10].rgbRed = (&DAT_00417094)[local_10 * 4];
    (&DAT_00417095)[local_10 * 4] = local_c[local_10 * 3 + 1] * '\x04';
    local_444.bmiColors[local_10].rgbGreen = (&DAT_00417095)[local_10 * 4];
    (&DAT_00417096)[local_10 * 4] = local_c[local_10 * 3 + 2] * '\x04';
    local_444.bmiColors[local_10].rgbBlue = (&DAT_00417096)[local_10 * 4];
    local_444.bmiColors[local_10].rgbReserved = '\0';
    (&DAT_00417097)[local_10 * 4] = 4;
  }
  DAT_00414bf8 = CreatePalette((LOGPALETTE *)&DAT_00417090);
  local_1c = GetDC((HWND)0x0);
  DAT_00420118 = CreateDIBSection(local_1c,&local_444,0,&local_8,(HANDLE)0x0,0);
  ReleaseDC((HWND)0x0,local_1c);
  DAT_00414c38 = local_8;
  DAT_00425d20 = local_8;
  return;
}


// ==== FUN_0040b6c5 @ 0040b6c5

void __cdecl FUN_0040b6c5(int *param_1)

{
  HDC hdc;
  HGDIOBJ h;
  int y;
  
  hdc = CreateCompatibleDC(DAT_00417040);
  h = SelectObject(hdc,DAT_00420118);
  y = (DAT_00414c04 + -1) - param_1[3];
  BitBlt(DAT_00417040,*param_1,y,(param_1[2] - *param_1) + 1,(param_1[3] - param_1[1]) + 1,hdc,
         *param_1,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  return;
}


// ==== FUN_0040b770 @ 0040b770

HGLOBAL __cdecl FUN_0040b770(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00425d28 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_00425d28 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_0040b7e8 @ 0040b7e8

HGLOBAL __cdecl FUN_0040b7e8(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00425d28 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_00425d28 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_00425d28 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_0040b882 @ 0040b882

undefined4 __cdecl FUN_0040b882(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_00414c48; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),hResInfo);
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


// ==== FUN_0040b993 @ 0040b993

bool __cdecl FUN_0040b993(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_00414c48 <= local_18) {
LAB_0040ba01:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_00425d28 + local_18 * 4),local_14);
      goto LAB_0040ba01;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_0040bac7 @ 0040bac7

HRSRC __cdecl FUN_0040bac7(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_00425d28 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040bb2c @ 0040bb2c

HGLOBAL __cdecl FUN_0040bb2c(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_00425d28 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_0040bb8d @ 0040bb8d

INT_PTR __cdecl FUN_0040bb8d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_00425d28 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_0040bbfb @ 0040bbfb

HACCEL __cdecl FUN_0040bbfb(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_00425d28 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040bc5d @ 0040bc5d

HICON __cdecl FUN_0040bc5d(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_00425d28 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040bcbe @ 0040bcbe

HMENU __cdecl FUN_0040bcbe(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_00425d28 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040bd20 @ 0040bd20

int __cdecl FUN_0040bd20(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00414c48 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_00425d28 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_0040bd89 @ 0040bd89

HBITMAP __cdecl FUN_0040bd89(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_00414c48 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_00425d28 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040bdeb @ 0040bdeb

void FUN_0040bdeb(void)

{
  DAT_00414c48 = 0;
  return;
}


// ==== FUN_0040be05 @ 0040be05

bool __cdecl FUN_0040be05(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00414c48 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_00425d28 + DAT_00414c48 * 4) = param_1;
    DAT_00414c48 = DAT_00414c48 + 1;
  }
  return bVar1;
}


// ==== FUN_0040be44 @ 0040be44

undefined4 __cdecl FUN_0040be44(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00414c48 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_00425d28 + DAT_00414c48 * 4) = pHVar2;
      DAT_00414c48 = DAT_00414c48 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040bea4 @ 0040bea4

bool __cdecl FUN_0040bea4(LPCSTR param_1,uint *param_2)

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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_00414ed4,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0040cb80(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040bf7c @ 0040bf7c

bool __cdecl FUN_0040bf7c(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040bfbe @ 0040bfbe

undefined4 FUN_0040bfbe(void)

{
  return 1;
}


// ==== FUN_0040bfd6 @ 0040bfd6

void __cdecl FUN_0040bfd6(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_0040cb90(local_104,(uint *)&DAT_00414f08);
  }
  FUN_0040cb90(local_104,param_1);
  FUN_0040cb80(param_1,local_104);
  return;
}


// ==== FUN_0040c058 @ 0040c058

undefined4 __cdecl FUN_0040c058(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040bea4(s_Shared_Path_00414f0c,local_104);
  FUN_0040cb90(local_104,param_1);
  bVar1 = FUN_0040bf7c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040bea4(s_Shared_Path_00414f18,local_104);
    FUN_0040cb90(local_104,(uint *)&DAT_00414f24);
    FUN_0040cb90(local_104,param_1);
    bVar1 = FUN_0040bf7c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040cb80(local_104,(uint *)s___shared__00414f28);
      FUN_0040cb90(local_104,param_1);
      bVar1 = FUN_0040bf7c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040cb80(local_104,(uint *)&DAT_00414f34);
        FUN_0040cb90(local_104,param_1);
        bVar1 = FUN_0040bf7c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040cb80(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040cb80(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040cb80(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040cb80(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040c206 @ 0040c206

undefined4 __cdecl FUN_0040c206(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040bea4(s_Help_Path_00414f38,local_104);
  FUN_0040cb90(local_104,param_1);
  bVar1 = FUN_0040bf7c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040bea4(s_Help_Path_00414f44,local_104);
    FUN_0040cb90(local_104,(uint *)&DAT_00414f50);
    FUN_0040cb90(local_104,param_1);
    bVar1 = FUN_0040bf7c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040cb80(local_104,(uint *)&DAT_00414f54);
      FUN_0040cb90(local_104,param_1);
      bVar1 = FUN_0040bf7c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040cb80(local_104,(uint *)s___shared__00414f58);
        FUN_0040cb90(local_104,param_1);
        bVar1 = FUN_0040bf7c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040cb80(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040cb80(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040cb80(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040cb80(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040c3b4 @ 0040c3b4

undefined4 __cdecl FUN_0040c3b4(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_00414ed0 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00425e28 + DAT_00414ed0 * 4) = param_1;
    DAT_00414ed0 = DAT_00414ed0 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040c400 @ 0040c400

void FUN_0040c400(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00414ed0; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00425e28 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00425e28 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00425e28 + local_8 * 4) = 0;
  }
  DAT_00414ed0 = 0;
  return;
}


// ==== FUN_0040c470 @ 0040c470

int __cdecl FUN_0040c470(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0040c48f @ 0040c48f

void FUN_0040c48f(void)

{
  _memset(&DAT_00429ff8,0,0x370);
  _memset(&DAT_00426f28,0,0x30d0);
  FID_conflict__memcpy(&DAT_00426f28,s_MD_PACK_00414fb0,8);
  DAT_00429410 = 0;
  DAT_00429411 = 0;
  DAT_00429412 = 0;
  DAT_00426f32 = 0xc;
  _memset(&DAT_004293e4,0,0x28);
  FID_conflict__memcpy(&DAT_004293d4,s_SWEEKEND_004150b8,0xb);
  return;
}


// ==== FUN_0040c528 @ 0040c528

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040c528(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0040c48f();
  hFile = _lopen(s_MSPuzzle_dat_00414fb8,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00426f28,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_004293d4,s_SWEEKEND_004150b8,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00426f28,s_MD_PACK_00414fb0,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0042a020 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_00429448 + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00429ff8 + local_10 * 0x2c,&DAT_00429420 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_0042a020 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_0042a020 + local_10 * 0x2c) = 0;
        }
      }
      DAT_004149c4 = (uint)(DAT_00429410 == '\0');
      DAT_004149c0 = (uint)(DAT_00429411 == '\0');
      DAT_00414f84 = (uint)(DAT_00429412 == '\0');
      FID_conflict__memcpy(&DAT_00414f88,&DAT_004293e4,0x28);
      _DAT_00414f70 = (uint)DAT_0042940c;
      if ((_DAT_00414f70 == 0) || (0x32 < _DAT_00414f70)) {
        _DAT_00414f70 = 1;
      }
      _DAT_00414f74 = (uint)DAT_0042940d;
      if ((_DAT_00414f74 == 0) || (2 < _DAT_00414f74)) {
        _DAT_00414f74 = 2;
      }
      DAT_00414f78 = (uint)(DAT_0042940e == '\0');
      DAT_00414f7c = (uint)(DAT_0042940f == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0040c48f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_0040c7b8 @ 0040c7b8

undefined4 __cdecl FUN_0040c7b8(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_0042a020 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_0040c855 @ 0040c855

int __cdecl FUN_0040c855(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_0042a020 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00429ff8 + (local_1c + 1) * 0x2c,&DAT_00429ff8 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00429ff8 + local_1c * 0x2c,&DAT_00414f88,0x28);
    *(int *)(&DAT_0042a020 + local_1c * 0x2c) = param_1;
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


// ==== FUN_0040c999 @ 0040c999

void FUN_0040c999(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00429420,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00429420 + local_c * 0x30,&DAT_00429ff8 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_00429448 + local_c * 0x30) =
         *(undefined4 *)(&DAT_0042a020 + local_c * 0x2c);
  }
  DAT_00429410 = DAT_004149c4 == 0;
  DAT_00429411 = DAT_004149c0 == 0;
  DAT_00429412 = DAT_00414f84 == 0;
  DAT_0042940c = DAT_00414f70;
  DAT_0042940d = DAT_00414f74;
  DAT_0042940e = DAT_00414f78 == 0;
  DAT_0042940f = DAT_00414f7c == 0;
  _memset(&DAT_004293e4,0,0x28);
  FID_conflict__memcpy(&DAT_004293e4,&DAT_00414f88,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_00414fb8,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_00414fb8,0);
  }
  _lwrite(local_8,&DAT_00426f28,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_0040cb80 @ 0040cb80

uint * __cdecl FUN_0040cb80(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0040cc68;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0040cc68:
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


// ==== FUN_0040cb90 @ 0040cb90

uint * __cdecl FUN_0040cb90(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0040cbac;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0040cbdf;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0040cbfb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0040cbac:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0040cbfb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0040cbfb;
    }
  }
LAB_0040cbdf:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0040cbfb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0040cc68:
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
    if (bVar1 == 0) goto LAB_0040cc68;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _memset @ 0040cc70

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


// ==== __ftol @ 0040ccc8

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== __fpmath @ 0040ccf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_0040cd20();
  _DAT_004150dc = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


// ==== FUN_0040cd20 @ 0040cd20

void FUN_0040cd20(void)

{
  PTR_LAB_0041511c = &LAB_0040d640;
  PTR_LAB_00415120 = &LAB_0040d6c0;
  PTR_LAB_00415124 = &LAB_0040d5d0;
  PTR_LAB_00415128 = &LAB_0040d6a0;
  PTR_LAB_00415118 = &LAB_0040da60;
  PTR_LAB_0041512c = &LAB_0040da60;
  return;
}


// ==== FID_conflict:_memcpy @ 0040cd60

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
switchD_0040ce29_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0040ce29_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0040ce29_caseD_3:
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
        goto switchD_0040ce29_caseD_1;
      case 2:
        goto switchD_0040ce29_caseD_2;
      case 3:
        goto switchD_0040ce29_caseD_3;
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
switchD_0040cd90_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0040cd90_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0040cd90_caseD_3:
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
      goto switchD_0040cd90_caseD_1;
    case 2:
      goto switchD_0040cd90_caseD_2;
    case 3:
      goto switchD_0040cd90_caseD_3;
    }
  }
  return _Dst;
}


// ==== _strcmp @ 0040ceb0

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
      if (bVar4 != *_Str2) goto LAB_0040cef4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0040cec0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0040cef4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0040cef4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0040cec0:
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
LAB_0040cef4:
  return (uint)bVar5 * -2 + 1;
}


// ==== FUN_0040cf40 @ 0040cf40

void __cdecl FUN_0040cf40(undefined4 param_1)

{
  DAT_004150f0 = param_1;
  return;
}


// ==== _rand @ 0040cf50

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_004150f0 = DAT_004150f0 * 0x343fd + 0x269ec3;
  return (DAT_004150f0 & 0x7fff0000) >> 0x10;
}


// ==== FUN_0040cf80 @ 0040cf80

void FUN_0040cf80(uint param_1,int param_2)

{
  __ctrandisp1(param_1,param_2);
  return;
}


// ==== _free @ 0040cfa0

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
    HeapFree(DAT_0042a5cc,0,_Memory);
  }
  return;
}


// ==== _malloc @ 0040cff0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00415988);
  return pvVar1;
}


// ==== __nh_malloc @ 0040d010

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


// ==== __heap_alloc @ 0040d060

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00415984) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0042a5cc,0,dwBytes);
  return pvVar2;
}


// ==== _strlen @ 0040d0a0

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0040d0c0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0040d0f3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0040d0c0:
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
  goto LAB_0040d0f3;
}


// ==== _qsort @ 0040d120

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
LAB_0040d15f:
  uVar1 = (uint)((int)local_f8 - (int)_Base) / _SizeOfElements + 1;
  if (8 < uVar1) {
    swap((undefined1 *)((int)_Base + (uVar1 >> 1) * _SizeOfElements),_Base,_SizeOfElements);
    puVar3 = local_f8 + _SizeOfElements;
    puVar4 = _Base;
LAB_0040d1bc:
    puVar4 = puVar4 + _SizeOfElements;
    if (puVar4 <= local_f8) goto code_r0x0040d1c4;
    goto LAB_0040d1d4;
  }
  shortsort(_Base,local_f8,_SizeOfElements,_PtFuncCompare);
  goto LAB_0040d186;
code_r0x0040d1c4:
  iVar2 = (*_PtFuncCompare)(puVar4,_Base);
  if (iVar2 < 1) goto LAB_0040d1bc;
LAB_0040d1d4:
  do {
    puVar3 = puVar3 + -_SizeOfElements;
    if (puVar3 <= _Base) break;
    iVar2 = (*_PtFuncCompare)(puVar3,_Base);
  } while (-1 < iVar2);
  if (puVar4 <= puVar3) {
    swap(puVar4,puVar3,_SizeOfElements);
    goto LAB_0040d1bc;
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
      goto LAB_0040d15f;
    }
  }
  else {
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      auStack_f0[local_f4] = _Base;
      aiStack_78[local_f4] = (int)puVar3 - _SizeOfElements;
      local_f4 = local_f4 + 1;
    }
    _Base = puVar4;
    if (puVar4 < local_f8) goto LAB_0040d15f;
  }
LAB_0040d186:
  local_f4 = local_f4 + -1;
  if (local_f4 < 0) {
    return;
  }
  local_f8 = (undefined1 *)aiStack_78[local_f4];
  _Base = (undefined1 *)auStack_f0[local_f4];
  goto LAB_0040d15f;
}


// ==== shortsort @ 0040d280

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


// ==== swap @ 0040d2e0

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


// ==== FUN_0040d310 @ 0040d310

int __cdecl FUN_0040d310(uint param_1)

{
  return (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
}


// ==== _strncmp @ 0040d320

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


// ==== entry @ 0040d360

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
  puStack_c = &DAT_00413010;
  puStack_10 = &LAB_0040f310;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_004159a4 = DVar2 >> 8 & 0xff;
  DAT_00415998 = DVar2 >> 0x10;
  _DAT_004159a0 = DVar2 & 0xff;
  _DAT_0041599c = _DAT_004159a0 * 0x100 + _DAT_004159a4;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0042a5d0 = (byte *)GetCommandLineA();
  DAT_00415100 = ___crtGetEnvironmentStringsA();
  if ((DAT_00415100 == (LPVOID)0x0) || (DAT_0042a5d0 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0042a5d0;
  pbVar6 = DAT_0042a5d0;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_0042a5d0 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_0040d465;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_0040d465:
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
  _Code = FUN_004071df(pHVar5,iVar3,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0040d500

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0041510c == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_00415108)(0xff);
  return;
}


// ==== __setdefaultprecision @ 0040d530

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 0040d550

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 0040d5a0

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


// ==== __cftoe @ 0040d710

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
  
  _Digits = DAT_0042a368;
  if (DAT_00415130 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (uint)(*_Digits == 0x2d) + (uint)(0 < (int)_SizeInBytes),_SizeInBytes + 1,
              (int)_Digits,unaff_EBP);
  }
  else {
    __shift(_Buf + (*DAT_0042a368 == 0x2d),(uint)(0 < (int)_SizeInBytes));
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
    *pcVar2 = DAT_00415d38;
  }
  bVar4 = DAT_00415130 == '\0';
  *(undefined4 *)(pcVar2 + _SizeInBytes + bVar4) = DAT_00413068;
  *(undefined2 *)(pcVar2 + _SizeInBytes + bVar4 + 4) = DAT_0041306c;
  pcVar2 = pcVar2 + (DAT_00415130 == '\0') + _SizeInBytes;
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


// ==== __cftof @ 0040d850

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
  
  _Digits = DAT_0042a368;
  if (DAT_00415130 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (*_Digits == 0x2d),_Digits[1] + _SizeInBytes,(int)_Digits,unaff_EBP);
  }
  else if (DAT_00415134 == _SizeInBytes) {
    iVar1 = DAT_00415134 + (*DAT_0042a368 == 0x2d);
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
    *pcVar4 = DAT_00415d38;
    iVar1 = _Digits[1];
    if (iVar1 < 0) {
      if (DAT_00415130 == '\0') {
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


// ==== __cftog @ 0040d950

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
  
  DAT_0042a368 = (int *)__fltout();
  DAT_00415134 = DAT_0042a368[1] + -1;
  iVar1 = *DAT_0042a368;
  __fptostr(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_0042a368,unaff_EBP);
  DAT_00415138 = DAT_00415134 < DAT_0042a368[1] + -1;
  iVar3 = DAT_0042a368[1] + -1;
  if ((-5 < iVar3) && (iVar3 < (int)param_3)) {
    bVar5 = DAT_00415134 < DAT_0042a368[1] + -1;
    pcVar2 = param_2 + (iVar1 == 0x2d);
    DAT_00415134 = iVar3;
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
  DAT_00415134 = iVar3;
  __cftoe_g(param_1,param_2,param_3,param_4);
  return;
}


// ==== __cftoe_g @ 0040da00

/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftoe_g(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int unaff_retaddr;
  
  DAT_00415130 = 1;
  __cftoe(param_1,param_2,param_3,param_4,unaff_retaddr);
  DAT_00415130 = 0;
  return;
}


// ==== __cftof_g @ 0040da30

/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftof_g(double *param_1,char *param_2,size_t param_3)

{
  int unaff_retaddr;
  
  DAT_00415130 = 1;
  __cftof(param_1,param_2,param_3,unaff_retaddr);
  DAT_00415130 = 0;
  return;
}


// ==== __shift @ 0040dad0

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


// ==== __cintrindisp2 @ 0040db20

/* Library Function - Single Match
    __cintrindisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __cintrindisp2(undefined4 param_1,int param_2)

{
  __trandisp2(param_1,param_2);
  DAT_0042a378 = 1;
  FUN_0040dbd5();
  return;
}


// ==== __cintrindisp1 @ 0040db5e

/* Library Function - Single Match
    __cintrindisp1
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __cintrindisp1(undefined4 param_1,int param_2)

{
  __trandisp1(param_1,param_2);
  DAT_0042a378 = 1;
  FUN_0040dbd5();
  return;
}


// ==== __ctrandisp2 @ 0040db94

/* Library Function - Single Match
    __ctrandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __cdecl __ctrandisp2(uint param_1,int param_2,uint param_3,int param_4)

{
  undefined4 extraout_ECX;
  int extraout_EDX;
  
  __fload(param_1,param_2);
  __fload(param_3,param_4);
  __trandisp2(extraout_ECX,extraout_EDX);
  FUN_0040dbce();
  return;
}


// ==== FUN_0040dbce @ 0040dbce

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040dbce(void)

{
  char cVar1;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  DAT_0042a378 = '\0';
  if (DAT_004150d8 != 0) {
    DAT_0042a378 = 0;
    return;
  }
  _DAT_0042a370 = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        DAT_0042a378 = 0;
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_0040dca3;
    }
    if (((ulonglong)_DAT_0042a370 & 0x7ff0000000000000) == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00413088);
      if (ABS(in_ST0) < (float10)_DAT_00413078) {
        in_ST0 = in_ST0 * (float10)_DAT_00413098;
      }
      goto LAB_0040dca3;
    }
    if ((DAT_0042a376 & 0x7ff0) == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00413080);
      if ((float10)_DAT_00413070 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_00413090;
      }
      goto LAB_0040dca3;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    DAT_0042a378 = 0;
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    DAT_0042a378 = 0;
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0040dca3:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if (DAT_0042a378 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  __87except((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),(int *)(unaff_EBP + -0x8e),
             (ushort *)(unaff_EBP + -0xa4));
  return;
}


// ==== FUN_0040dbd5 @ 0040dbd5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040dbd5(void)

{
  char cVar1;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  if (DAT_004150d8 != 0) {
    return;
  }
  _DAT_0042a370 = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_0040dca3;
    }
    if (((ulonglong)_DAT_0042a370 & 0x7ff0000000000000) == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00413088);
      if (ABS(in_ST0) < (float10)_DAT_00413078) {
        in_ST0 = in_ST0 * (float10)_DAT_00413098;
      }
      goto LAB_0040dca3;
    }
    if ((DAT_0042a376 & 0x7ff0) == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00413080);
      if ((float10)_DAT_00413070 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_00413090;
      }
      goto LAB_0040dca3;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0040dca3:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if (DAT_0042a378 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  __87except((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),(int *)(unaff_EBP + -0x8e),
             (ushort *)(unaff_EBP + -0xa4));
  return;
}


// ==== __ctrandisp1 @ 0040dd05

/* Library Function - Single Match
    __ctrandisp1
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __cdecl __ctrandisp1(uint param_1,int param_2)

{
  undefined4 extraout_ECX;
  int extraout_EDX;
  
  __fload(param_1,param_2);
  __trandisp1(extraout_ECX,extraout_EDX);
  FUN_0040dbce();
  return;
}


// ==== __fload @ 0040dd31

/* Library Function - Single Match
    __fload
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

float10 __cdecl __fload(uint param_1,int param_2)

{
  float10 fVar1;
  
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    fVar1 = (float10)CONCAT28(param_2._2_2_ | 0x7fff,
                              CONCAT44(param_2 << 0xb | param_1 >> 0x15,param_1));
  }
  else {
    fVar1 = (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  }
  return fVar1;
}


// ==== __heap_init @ 0040dd70

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0042a5cc = HeapCreate(1,0x1000,0);
  if (DAT_0042a5cc == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0042a5cc);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 0040ddb0

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
  
  if (DAT_00415978 == 0) {
    lpMem = &PTR_LOOP_00415168;
  }
  else {
    lpMem = HeapAlloc(DAT_0042a5cc,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00415168) {
        if (PTR_LOOP_00415168 == (undefined *)0x0) {
          PTR_LOOP_00415168 = (undefined *)&PTR_LOOP_00415168;
        }
        if (PTR_LOOP_0041516c == (undefined *)0x0) {
          PTR_LOOP_0041516c = (undefined *)&PTR_LOOP_00415168;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00415168;
        lpMem[1] = PTR_LOOP_0041516c;
        PTR_LOOP_0041516c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00415168) {
    HeapFree(DAT_0042a5cc,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 0040df20

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0041597c == param_1) {
    PTR_LOOP_0041597c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00415168) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0042a5cc,0,param_1);
    return;
  }
  DAT_00415978 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 0040df80

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
  
  ppuVar4 = (undefined **)PTR_LOOP_0041516c;
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
            DAT_00415980 = DAT_00415980 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_0041516c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 0040e060

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00415168;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00415168) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 0040e0c0

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00415980 = DAT_00415980 + 1, DAT_00415980 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 0040e110

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
  
  piVar12 = (int *)PTR_LOOP_0041597c;
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
              PTR_LOOP_0041597c = (undefined *)piVar12;
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
              PTR_LOOP_0041597c = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_0041597c != piVar12);
  ppuVar11 = &PTR_LOOP_00415168;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00415168) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_0041597c = (undefined *)ppuVar11;
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
  PTR_LOOP_0041597c = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 0040e390

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


// ==== __callnewh @ 0040e510

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0042a37c != (code *)0x0) {
    iVar1 = (*DAT_0042a37c)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __cinit @ 0040e540

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (PTR___fpmath_004150e0 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_004150e0)();
  }
  __initterm((undefined4 *)&DAT_00414008,(undefined4 *)&DAT_0041400c);
  iVar1 = __initterm((undefined4 *)&DAT_00414000,(undefined4 *)&DAT_00414004);
  return iVar1;
}


// ==== _exit @ 0040e570

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0040e590

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0040e5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_004159d4 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004159d0 = 1;
  DAT_004159cc = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0042a5c8 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0042a5c4 + -4), DAT_0042a5c8 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0042a5c8 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00414010,(undefined4 *)&DAT_00414014);
  }
  __initterm((undefined4 *)&DAT_00414018,(undefined4 *)&DAT_0041401c);
  if (param_3 == 0) {
    DAT_004159d4 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0040e660

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


// ==== __global_unwind2 @ 0040e680

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x40e698,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0040e6c2

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
  puStack_18 = &LAB_0040e6a0;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0040e756();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_0040e756 @ 0040e756

void FUN_0040e756(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004159e0 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004159dc = in_EAX;
  DAT_004159e4 = unaff_EBP;
  return;
}


// ==== __ismbblead @ 0040e900

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 0040e920

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00415a80 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00415d4a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 0040e960

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
  cVar1 = *DAT_00415100;
  pcVar7 = DAT_00415100;
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
  _DAT_004159b4 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00415100;
  pcVar7 = DAT_00415100;
  do {
    if (cVar1 == '\0') {
      _free(DAT_00415100);
      DAT_00415100 = (char *)0x0;
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


// ==== __setargv @ 0040ea50

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0042a380,0x104);
  _DAT_004159c4 = &DAT_0042a380;
  pbVar2 = &DAT_0042a380;
  if (*DAT_0042a5d0 != 0) {
    pbVar2 = DAT_0042a5d0;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_004159ac = puVar1;
  _DAT_004159a8 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 0040eaf0

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
      if (((*(byte *)((int)&DAT_00415a80 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00415a80 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_0040eb60;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_0040eb60:
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
          if ((*(byte *)((int)&DAT_00415a80 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_0040ec91;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00415a80 + bVar1 + 1) & 4) != 0) {
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
LAB_0040ec91:
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


// ==== ___crtGetEnvironmentStringsA @ 0040ecd0

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
  if (DAT_00415a78 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00415a78 = 2;
    }
    else {
      DAT_00415a78 = 1;
    }
  }
  if (DAT_00415a78 != 1) {
    if (DAT_00415a78 != 2) {
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


// ==== __setmbcp @ 0040ee60

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
  if (CodePage == DAT_00415b84) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00415ba8;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00415a80;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00415bb8 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00415ba0)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00415a80 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00415b84 = CodePage;
      _DAT_00415b88 = _CPtoLCID(CodePage);
      DAT_00415b90 = *(undefined4 *)(&DAT_00415bac + local_18 * 0x30);
      DAT_00415b94 = *(undefined4 *)(&DAT_00415bb0 + local_18 * 0x30);
      DAT_00415b98 = *(undefined4 *)(local_18 * 0x30 + 0x415bb4);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00415c98);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00415a80;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00415b88 = 0;
      DAT_00415b84 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00415a80 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00415a80 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00415b84 = CodePage;
      _DAT_00415b88 = _CPtoLCID(CodePage);
    }
    DAT_00415b90 = 0;
    DAT_00415b94 = 0;
    DAT_00415b98 = 0;
    return 0;
  }
  if (DAT_00415b9c == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 0040f040

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00415b9c = 1;
                    /* WARNING: Could not recover jumptable at 0x0040f05d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00415b9c = 1;
                    /* WARNING: Could not recover jumptable at 0x0040f072. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00415fc8;
  }
  DAT_00415b9c = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 0040f090

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


// ==== setSBCS @ 0040f0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00415a80;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00415b90 = 0;
  DAT_00415b84 = 0;
  _DAT_00415b88 = 0;
  DAT_00415b94 = 0;
  DAT_00415b98 = 0;
  return;
}


// ==== ___initmbctable @ 0040f120

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 0040f130

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
  DAT_0042a5c0 = 0x20;
  DAT_0042a4c0 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0042a4c0 + 0x40);
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
    if ((int)DAT_0042a5c0 < (int)UVar7) {
      piVar4 = &DAT_0042a4c4;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0042a5c0;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0042a5c0 = DAT_0042a5c0 + 0x20;
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
      } while ((int)DAT_0042a5c0 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0042a4c0 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0042a4c0 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0042a5c0);
  return UVar7;
}


// ==== FUN_0040f3cd @ 0040f3cd

void FUN_0040f3cd(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 0040f3f0

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0041510c == 1) || ((DAT_0041510c == 0 && (DAT_00415110 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00415d30 != (code *)0x0) {
      (*DAT_00415d30)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 0040f430

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
  piVar2 = &DAT_00415ca0;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00415d30);
  if ((&DAT_00415ca0)[iVar4 * 2] == param_1) {
    if ((DAT_0041510c == 1) || ((DAT_0041510c == 0 && (DAT_00415110 == 1)))) {
      if ((DAT_0042a4c0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0042a4c0 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x415ca4);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x415ca4);
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


// ==== __control87 @ 0040f630

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


// ==== __controlfp @ 0040f680

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== __abstract_cw @ 0040f6a0

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


// ==== __hw_cw @ 0040f750

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}


// ==== __isctype @ 0040f7f0

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
    return (uint)*(ushort *)(PTR_DAT_00415d40 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00415d40[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
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


// ==== FID_conflict:_tolower @ 0040f890

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
  
  if (DAT_00415fb8 == (_locale_t)0x0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      _C = _C + 0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_00415d34 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_00415d40 + _C * 2) & 1;
    }
    else {
      uVar1 = __isctype(_C,1);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00415d40[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_00415fb8,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __ZeroTail @ 0040f980

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


// ==== __IncMan @ 0040f9f0

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


// ==== __RoundMan @ 0040fa60

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


// ==== __CopyMan @ 0040fb10

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


// ==== __FillZeroMan @ 0040fb30

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


// ==== __IsZeroMan @ 0040fb40

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


// ==== __ShrMan @ 0040fb60

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


// ==== __ld12cvt @ 0040fc10

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


// ==== FID_conflict:__ld12tod @ 0040fde0

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_00415f50);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 0040fe00

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_00415f68);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 0040fe20

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


// ==== FID_conflict:__atodbl @ 0040fe60

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


// ==== __fptostr @ 0040fea0

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


// ==== __fltout @ 0040ff30

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
  _DAT_0042a4b0 = _I10_OUTPUT(local_c,local_8,local_4,0x11,0,&DAT_0042a488);
  _DAT_0042a4b4 = &DAT_0042a48c;
  _DAT_0042a4a8 = (int)DAT_0042a48a;
  _DAT_0042a4ac = (int)DAT_0042a488;
  return &DAT_0042a4a8;
}


// ==== ___dtold @ 0040ffa0

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


// ==== __trandisp1 @ 00410060

/* Library Function - Single Match
    __trandisp1
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __trandisp1(undefined4 param_1,int param_2)

{
  float10 fVar1;
  byte bVar2;
  undefined2 uVar3;
  int unaff_EBP;
  float10 in_ST0;
  
  if (*(char *)(param_2 + 0xe) == '\x05') {
    uVar3 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar3 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar3;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = param_2;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  bVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x004100c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)(&DAT_00415f9d)[(byte)((bVar2 & 7) << 1 | (char)bVar2 < '\0')] + 0x10
              ))();
  return;
}


// ==== __trandisp2 @ 004100c7

/* Library Function - Single Match
    __trandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __trandisp2(undefined4 param_1,int param_2)

{
  float10 fVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  int unaff_EBP;
  float10 in_ST0;
  float10 in_ST1;
  
  if (*(char *)(param_2 + 0xe) == '\x05') {
    uVar4 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar4 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar4;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = param_2;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST1) << 8 | (ushort)(in_ST1 < fVar1) << 9 | (ushort)(in_ST1 != fVar1) << 10 |
       (ushort)(in_ST1 == fVar1) << 0xe;
  bVar3 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  cVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x00410151. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)((&DAT_00415f9d)[(byte)(cVar2 << 1 | cVar2 < '\0') & 0xf] |
                               (&DAT_00415f9d)[(byte)((bVar3 & 7) << 1 | (char)bVar3 < '\0')] << 2)
              + 0x10))();
  return;
}


// ==== __87except @ 00410230

/* Library Function - Single Match
    __87except
   
   Library: Visual Studio 1998 Release */

void __cdecl __87except(int param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_5c;
  uint local_58 [10];
  int local_30;
  int local_2c;
  uint local_20;
  
  local_5c = (uint)*param_3;
  switch(*param_2) {
  case 1:
  case 5:
    uVar3 = 8;
    break;
  case 2:
    uVar3 = 4;
    break;
  case 3:
    uVar3 = 0x11;
    break;
  case 4:
    uVar3 = 0x12;
    break;
  case 7:
    *param_2 = 1;
  default:
    uVar3 = 0;
    break;
  case 8:
    uVar3 = 0x10;
  }
  if (uVar3 != 0) {
    bVar1 = __handle_exc(uVar3,(double *)(param_2 + 6),local_5c);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
        local_2c = param_2[5];
        local_20 = local_20 & 0xffffffe3 | 3;
        local_30 = param_2[4];
      }
      else {
        local_20 = local_20 & 0xfffffffe;
      }
      __raise_exc(local_58,&local_5c,uVar3,param_1,(uint *)(param_2 + 2),(uint *)(param_2 + 6));
    }
  }
  __ctrlfp();
  iVar2 = 0;
  if ((*param_2 != 8) && (DAT_004160c8 == 0)) {
    iVar2 = FUN_00411be0();
  }
  if (iVar2 == 0) {
    __set_errno(*param_2);
  }
  return;
}


// ==== ___crtMessageBoxA @ 00410350

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00415fcc != (FARPROC)0x0) {
LAB_0041039f:
    if (DAT_00415fd0 != (FARPROC)0x0) {
      iVar1 = (*DAT_00415fd0)();
    }
    if ((iVar1 != 0) && (DAT_00415fd4 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00415fd4)(iVar1);
    }
    iVar1 = (*DAT_00415fcc)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00415fcc = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00415fcc != (FARPROC)0x0) {
      DAT_00415fd0 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00415fd4 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0041039f;
    }
  }
  return 0;
}


// ==== _strncpy @ 004103f0

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
        goto joined_r0x0041042e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0041046b;
        goto LAB_004104d9;
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
joined_r0x004104d5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_004104d9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0041046b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x004104d5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x004104d5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x004104d5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x0041042e:
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
LAB_0041046b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== ___crtGetStringTypeA @ 004104f0

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
  
  iVar2 = DAT_00415fe4;
  if (DAT_00415fe4 == 0) {
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
  DAT_00415fe4 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_00415fc8;
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
    _Code_page = DAT_00415fb8;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== ___crtLCMapStringA @ 00410620

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
  
  if (DAT_00415fec == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00415fec = 1;
    }
    else {
      DAT_00415fec = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_00415fec == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_00415fec != 1) {
    return DAT_00415fec;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_00415fc8;
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
                               iVar2), iVar1 == 0)) goto LAB_0041079b;
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
      if (_LpDestStr == (LPSTR)0x0) goto LAB_00410832;
      if ((int)_LpDestStr < iVar2) goto LAB_0041079b;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_00410832:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_0041079b:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 00410850

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
    if (*pcVar2 == '\0') goto LAB_00410875;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_00410875:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== ___addl @ 00410880

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


// ==== ___add_12 @ 004108b0

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


// ==== ___shl_12 @ 00410920

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


// ==== ___shr_12 @ 00410960

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


// ==== ___mtold12 @ 004109a0

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


// ==== ___strgtold12 @ 00410a90

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
        if (DAT_00415d38 == bVar8) {
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
          if (bVar8 != 0x30) goto switchD_00410d40_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_00410f44;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_00410f44;
      }
      if (DAT_00415d38 == bVar8) {
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
          goto switchD_00410d40_caseD_2c;
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
        goto LAB_00410f44;
      }
      if (DAT_00415d38 == bVar8) {
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
        if (DAT_00415d34 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00415d40 + (uint)bVar8 * 2) & 4;
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
      if (DAT_00415d38 == bVar8) {
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
          goto switchD_00410d40_caseD_2c;
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
        if (DAT_00415d34 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00415d40 + (uint)bVar8 * 2) & 4;
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
        goto switchD_00410d40_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_00415d34 < 2) {
        uVar13 = *(ushort *)(PTR_DAT_00415d40 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_00410f44;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = (byte *)(str + -1);
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_00410f44;
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
        goto LAB_00410f44;
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
        goto LAB_00410f44;
      }
      goto switchD_00410d40_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_00415d34 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00415d40 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_00410eca;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_00410eca:
      while( true ) {
        if (DAT_00415d34 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00415d40 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_00410d40_caseD_2c:
      iVar7 = 10;
LAB_00410f44:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (implicit_E == 0) goto switchD_00410d40_caseD_2c;
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
      goto LAB_00411042;
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
        goto LAB_00411042;
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
LAB_00411042:
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


// ==== $I10_OUTPUT @ 004111e0

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
      *(undefined4 *)(param_6 + 2) = DAT_004133ec;
      param_6[4] = DAT_004133f0;
      *(undefined1 *)(param_6 + 5) = DAT_004133f2;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_004133e4;
      param_6[4] = DAT_004133e8;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_004133dc;
      param_6[4] = DAT_004133e0;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_004133d4;
    param_6[4] = DAT_004133d8;
    *(undefined1 *)(param_6 + 5) = DAT_004133da;
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
LAB_00411559:
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
    if (psVar7 < psVar1) goto LAB_00411559;
    goto LAB_0041152b;
  }
  if (psVar7 < psVar1) {
LAB_00411525:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_00411525;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_0041152b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}


// ==== __raise_exc @ 00411580

/* Library Function - Single Match
    __raise_exc
   
   Library: Visual Studio 1998 Release */

void __cdecl
__raise_exc(uint *param_1,uint *param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  DWORD local_4;
  
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    local_4 = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((param_3 & 2) != 0) {
    local_4 = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((param_3 & 1) != 0) {
    local_4 = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((param_3 & 4) != 0) {
    local_4 = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((param_3 & 8) != 0) {
    local_4 = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  uVar3 = param_1[2];
  param_1[2] = ((~*param_2 & 1) << 4 ^ uVar3) & 0x10 ^ uVar3;
  uVar3 = param_1[2];
  param_1[2] = ((uint)((*param_2 & 4) == 0) << 3 ^ uVar3) & 8 ^ uVar3;
  uVar3 = param_1[2];
  param_1[2] = ((uint)((*param_2 & 8) == 0) << 2 ^ uVar3) & 4 ^ uVar3;
  uVar3 = param_1[2];
  param_1[2] = ((uint)((*param_2 & 0x10) == 0) * 2 ^ uVar3) & 2 ^ uVar3;
  uVar3 = param_1[2];
  param_1[2] = ((*param_2 & 0x20) == 0 ^ uVar3) & 1 ^ uVar3;
  uVar3 = __statfp();
  puVar2 = param_6;
  if ((uVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((uVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((uVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((uVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar3 = *puVar1 & 0xc00;
  if (uVar3 < 0x401) {
    if (uVar3 == 0x400) {
      *param_1 = *param_1 & 0xfffffffd | 1;
    }
    else if (uVar3 == 0) {
      *param_1 = *param_1 & 0xfffffffc;
    }
  }
  else if (uVar3 == 0x800) {
    *param_1 = *param_1 & 0xfffffffe | 2;
  }
  else if (uVar3 == 0xc00) {
    *param_1 = *param_1 | 3;
  }
  uVar3 = *puVar1 & 0x300;
  if (uVar3 == 0) {
    *param_1 = *param_1 & 0xffffffeb | 8;
  }
  else if (uVar3 == 0x200) {
    *param_1 = *param_1 & 0xffffffe7 | 4;
  }
  else if (uVar3 == 0x300) {
    *param_1 = *param_1 & 0xffffffe3;
  }
  *param_1 = (param_4 << 5 ^ *param_1) & 0x1ffe0 ^ *param_1;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  param_1[5] = param_5[1];
  param_1[4] = *param_5;
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  param_1[0x11] = param_6[1];
  param_1[0x10] = *param_6;
  __clrfp();
  RaiseException(local_4,0,1,(ULONG_PTR *)&param_1);
  puVar4 = param_1 + 2;
  if ((*puVar4 & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((*puVar4 & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((*puVar4 & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((*puVar4 & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((*puVar4 & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  switch(*param_1 & 3) {
  case 0:
    *puVar1 = *puVar1 & 0xfffff3ff;
    break;
  case 1:
    *puVar1 = *puVar1 & 0xfffff7ff | 0x400;
    break;
  case 2:
    *puVar1 = *puVar1 & 0xfffffbff | 0x800;
    break;
  case 3:
    *puVar1 = *puVar1 | 0xc00;
  }
  uVar3 = (*param_1 & 0x1c) >> 2;
  if (uVar3 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else if (uVar3 == 1) {
    *puVar1 = *puVar1 & 0xfffff3ff | 0x200;
  }
  else if (uVar3 == 2) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  puVar2[1] = param_1[0x11];
  *puVar2 = param_1[0x10];
  return;
}


// ==== __handle_exc @ 004118f0

/* Library Function - Single Match
    __handle_exc
   
   Library: Visual Studio 1998 Release */

bool __cdecl __handle_exc(uint param_1,double *param_2,uint param_3)

{
  ulonglong uVar1;
  uint uVar2;
  bool bVar3;
  float10 fVar4;
  undefined8 local_c;
  int local_4;
  
  uVar2 = param_1 & 0x1f;
  if (((param_1 & 8) == 0) || ((param_3 & 1) == 0)) {
    if (((param_1 & 4) == 0) || ((param_3 & 4) == 0)) {
      if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
        if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
          bVar3 = (param_1 & 0x10) != 0;
          if (((ulonglong)*param_2 & 0x7fffffff00000000) == 0 && *(int *)param_2 == 0) {
            bVar3 = true;
          }
          else {
            fVar4 = __decomp(*(uint *)param_2,*(uint *)((int)param_2 + 4),&local_4);
            local_4 = local_4 + -0x600;
            if (local_4 < -0x432) {
              bVar3 = true;
              local_c = 0.0;
            }
            else {
              local_c = (double)(ulonglong)
                                (SUB87((double)fVar4,0) & 0xfffffffffffff | 0x10000000000000);
              if (local_4 < -0x3fd) {
                local_4 = -0x3fd - local_4;
                do {
                  if ((((ulonglong)local_c & 1) != 0) && (!bVar3)) {
                    bVar3 = true;
                  }
                  uVar2 = (uint)local_c >> 1;
                  uVar1 = (ulonglong)local_c & 0x100000000;
                  local_c._0_4_ = uVar2;
                  if (uVar1 != 0) {
                    local_c._0_4_ = uVar2 | 0x80000000;
                  }
                  local_c = (double)CONCAT44(local_c._4_4_ >> 1,(uint)local_c);
                  local_4 = local_4 + -1;
                } while (local_4 != 0);
              }
              if ((double)fVar4 < 0.0) {
                local_c = -local_c;
              }
            }
            *(uint *)((int)param_2 + 4) = local_c._4_4_;
            *(uint *)param_2 = (uint)local_c;
          }
          if (bVar3) {
            FUN_00411c70();
          }
          uVar2 = param_1 & 0x1d;
        }
      }
      else {
        FUN_00411c70();
        uVar2 = param_3 & 0xc00;
        if (uVar2 < 0x401) {
          if (uVar2 == 0x400) {
            if (*param_2 <= 0.0) {
              uVar2 = param_1 & 0x1e;
              *param_2 = -(double)CONCAT44(DAT_004160f4,DAT_004160f0);
            }
            else {
              uVar2 = param_1 & 0x1e;
              *(undefined4 *)((int)param_2 + 4) = DAT_00416104;
              *(undefined4 *)param_2 = DAT_00416100;
            }
          }
          else if (uVar2 == 0) {
            if (*param_2 <= 0.0) {
              uVar2 = param_1 & 0x1e;
              *param_2 = -(double)CONCAT44(DAT_004160f4,DAT_004160f0);
            }
            else {
              uVar2 = param_1 & 0x1e;
              *(undefined4 *)((int)param_2 + 4) = DAT_004160f4;
              *(undefined4 *)param_2 = DAT_004160f0;
            }
          }
          else {
            uVar2 = param_1 & 0x1e;
          }
        }
        else if (uVar2 == 0x800) {
          if (*param_2 <= 0.0) {
            uVar2 = param_1 & 0x1e;
            *param_2 = -(double)CONCAT44(DAT_00416104,DAT_00416100);
          }
          else {
            uVar2 = param_1 & 0x1e;
            *(undefined4 *)((int)param_2 + 4) = DAT_004160f4;
            *(undefined4 *)param_2 = DAT_004160f0;
          }
        }
        else if (uVar2 == 0xc00) {
          if (*param_2 <= 0.0) {
            uVar2 = param_1 & 0x1e;
            *param_2 = -(double)CONCAT44(DAT_00416104,DAT_00416100);
          }
          else {
            uVar2 = param_1 & 0x1e;
            *(undefined4 *)((int)param_2 + 4) = DAT_00416104;
            *(undefined4 *)param_2 = DAT_00416100;
          }
        }
        else {
          uVar2 = param_1 & 0x1e;
        }
      }
    }
    else {
      uVar2 = param_1 & 0x1b;
      FUN_00411c70();
    }
  }
  else {
    uVar2 = param_1 & 0x17;
    FUN_00411c70();
  }
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    uVar2 = uVar2 & 0xffffffef;
    FUN_00411c70();
  }
  return uVar2 == 0;
}


// ==== __set_errno @ 00411bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __set_errno
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __set_errno(int _Value)

{
  if (_Value == 1) {
    _DAT_0041598c = 0x21;
    return _Value;
  }
  if (1 < _Value) {
    if (3 < _Value) {
      return _Value;
    }
    _DAT_0041598c = 0x22;
  }
  return _Value;
}


// ==== FUN_00411be0 @ 00411be0

undefined4 FUN_00411be0(void)

{
  return 0;
}


// ==== __statfp @ 00411bf0

/* Library Function - Single Match
    __statfp
   
   Library: Visual Studio 1998 Release */

int __statfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __clrfp @ 00411c10

/* Library Function - Single Match
    __clrfp
   
   Library: Visual Studio 1998 Release */

int __clrfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __ctrlfp @ 00411c30

/* Library Function - Single Match
    __ctrlfp
   
   Library: Visual Studio 1998 Release */

int __ctrlfp(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}


// ==== FUN_00411c70 @ 00411c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411c70(void)

{
  return;
}


// ==== _calloc @ 00411cd0

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
      if (DAT_00415984 < dwBytes) {
LAB_00411d2d:
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
          goto LAB_00411d2d;
        }
      }
      puVar3 = HeapAlloc(DAT_0042a5cc,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_00415988 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== ___ld12mul @ 00411d70

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
    if (0 < (short)local_1a) goto LAB_00411f43;
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
LAB_00411f43:
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


// ==== ___multtenpow12 @ 00412020

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
  
  puVar4 = &DAT_004160b8;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar4 = &DAT_00416218;
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


// ==== __set_exp @ 004120a0

/* Library Function - Single Match
    __set_exp
   
   Library: Visual Studio 1998 Release */

float10 __cdecl __set_exp(undefined4 param_1,undefined4 param_2,short param_3)

{
  undefined2 uStack_4;
  
  uStack_4 = (undefined2)param_2;
  return (float10)(double)CONCAT26((param_3 + 0x3fe) * 0x10 | param_2._2_2_ & 0x800f,
                                   CONCAT24(uStack_4,param_1));
}


// ==== __decomp @ 004120e0

/* Library Function - Single Match
    __decomp
   
   Library: Visual Studio 1998 Release */

float10 __cdecl __decomp(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  double dVar3;
  byte bVar4;
  int iVar5;
  float10 fVar6;
  double local_8;
  
  if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
    iVar5 = 0;
    local_8 = 0.0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    dVar3 = (double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))
                            );
    iVar5 = -0x3fd;
    if ((param_2 & 0x100000) == 0) {
      do {
        bVar4 = param_2._2_1_;
        iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;
        param_2._0_2_ = (ushort)iVar2;
        param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);
        param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);
        if ((param_1 & 0x80000000) != 0) {
          param_2._0_2_ = (ushort)param_2 | 1;
        }
        iVar5 = iVar5 + -1;
        param_1 = param_1 << 1;
      } while ((bVar4 & 8) == 0);
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (byte)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (dVar3 < 0.0) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar6 = __set_exp(param_1,CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)),0);
    local_8 = (double)fVar6;
  }
  else {
    iVar5 = (short)(((ushort)(param_2 >> 0x10) & 0x7ff0) >> 4) + -0x3fe;
    fVar6 = __set_exp(param_1,param_2,0);
    local_8 = (double)fVar6;
  }
  *param_3 = iVar5;
  return (float10)local_8;
}


