// ==== FUN_00401000 @ 00401000

void FUN_00401000(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00413e64 == 1) || (DAT_00413e64 == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004121b8,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004121b8,0x804,2,(DWORD_PTR)local_c);
    DAT_004121b8 = 0;
    Sleep(1);
    DAT_00413e64 = 0;
  }
  return;
}


// ==== FUN_004010a5 @ 004010a5

void FUN_004010a5(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00412024 != 0) && (DAT_00413e64 == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_004121b8,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_00413e64 = 3;
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
  
  if (DAT_00412024 != 0) {
    if (DAT_00413e64 == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_004121b8,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_004121b8,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_004011f5(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_00413e64 = 1;
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
  
  if (DAT_00412024 == 0) {
    FUN_00401000();
  }
  else {
    if (((DAT_00413e60 == param_1) && (0 < param_1)) && (DAT_00413e64 == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_004121b8,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_00413e64 != 4) {
      FUN_00401000();
    }
    if (DAT_00412024 != 0) {
      if (0 < param_1) {
        DAT_00413e60 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00413e60;
      }
      if ((0 < param_1) && (param_1 < 4)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00413e68 + param_1 * 0x100;
        local_20 = s_sequencer_004121bc;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_004121b8 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_004121b8;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_004121b8 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004121b8,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_00413e64 = 1;
          }
          else {
            DAT_00413e64 = 4;
          }
        }
        else {
          DAT_00413e64 = 4;
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
  
  if (DAT_00412024 != 0) {
    if (DAT_00413e64 == 1) {
      if (DAT_004121b8 == 0) {
        DAT_00413e64 = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_004121b8,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_004121b8,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_00413e64 = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_00413e64 = 4;
        }
      }
    }
    else if (DAT_00413e64 == 4) {
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
  
  if (DAT_00412020 != 0) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_00412028) {
      DAT_00412028 = DVar1;
    }
    if ((DAT_00412028 <= DVar1 - _DAT_0041202c) ||
       (*(int *)(&DAT_00414474 + param_1 * 0x10) < DAT_00412030)) {
      sndPlaySoundA((LPCSTR)0x0,5);
      Sleep(1);
      DAT_00412028 = GetTickCount();
      _DAT_0041202c = *(int *)(&DAT_00414470 + param_1 * 0x10);
      DAT_00412030 = *(int *)(&DAT_00414474 + param_1 * 0x10);
      sndPlaySoundA(*(LPCSTR *)(&DAT_00414468 + param_1 * 0x10),5);
    }
  }
  return;
}


// ==== FUN_00401605 @ 00401605

void FUN_00401605(void)

{
  int local_c;
  int local_8;
  
  FUN_00401000();
  FUN_004014f3(0);
  for (local_8 = 1; local_8 < 9; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0041446c + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_0041446c + local_8 * 0x10));
      *(undefined4 *)(&DAT_0041446c + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_00414468 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 4; local_c = local_c + 1) {
    DeleteFileA(&DAT_00413e68 + local_c * 0x100);
  }
  return;
}


// ==== FUN_004016ed @ 004016ed

void __cdecl FUN_004016ed(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_0040df30(DAT_0041800c,param_2,&DAT_004121c8);
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
              param_1[2] = (uint)(*piVar1 * 1000) / 0x2b11 + 5;
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


// ==== FUN_0040181e @ 0040181e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040181e(void)

{
  int local_c;
  
  _DAT_00414468 = 0;
  _DAT_0041446c = 0;
  FUN_004016ed((int *)&DAT_00414478,s_BALLWAVE_004121d0);
  _DAT_00414484 = 6;
  FUN_004016ed(&DAT_00414488,s_FINALWAVE_004121dc);
  _DAT_00414494 = 0;
  FUN_004016ed((int *)&DAT_00414498,s_HOMEWAVE_004121e8);
  _DAT_004144a4 = 3;
  FUN_004016ed((int *)&DAT_004144a8,s_LOSTWAVE_004121f4);
  _DAT_004144b4 = 2;
  FUN_004016ed((int *)&DAT_004144b8,s_ROTATEWAVE_00412200);
  _DAT_004144c4 = 6;
  FUN_004016ed((int *)&DAT_004144c8,s_CLICKWAVE_0041220c);
  _DAT_004144d4 = 6;
  FUN_004016ed((int *)&DAT_004144e8,s_TICKWAVE_00412218);
  _DAT_004144f4 = 6;
  FUN_004016ed((int *)&DAT_004144d8,s_ALARMWAVE_00412224);
  _DAT_004144e4 = 1;
  for (local_c = 1; local_c < 4; local_c = local_c + 1) {
    GetTempPathA(200,&DAT_00413e68 + local_c * 0x100);
    FUN_0040ecc0((uint *)(&DAT_00413e68 + local_c * 0x100),(uint *)(&DAT_00412038 + local_c * 0x20))
    ;
    FUN_0040e153(&DAT_004120f8 + local_c * 0x20,&DAT_00412230,&DAT_00413e68 + local_c * 0x100);
  }
  return;
}


// ==== FUN_004019d0 @ 004019d0

undefined4 FUN_004019d0(void)

{
  return 1;
}


// ==== FUN_004019e8 @ 004019e8

void FUN_004019e8(void)

{
  return;
}


// ==== FUN_00401a00 @ 00401a00

int __cdecl FUN_00401a00(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_00401a1f @ 00401a1f

void FUN_00401a1f(void)

{
  _memset(&DAT_00417968,0,0x370);
  _memset(&DAT_00414890,0,0x30d0);
  FID_conflict__memcpy(&DAT_00414890,s_MD_PACK_00412280,8);
  DAT_00417184 = 0;
  DAT_00417185 = 0;
  DAT_00417186 = 0;
  DAT_0041489a = 0xc;
  _memset(&DAT_00417158,0,0x28);
  FID_conflict__memcpy(&DAT_00417148,s_FINTYFLUSH_00412388,0xb);
  return;
}


// ==== FUN_00401ab8 @ 00401ab8

undefined4 FUN_00401ab8(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_00401a1f();
  hFile = _lopen(s_MSPuzzle_dat_00412288,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_00414890,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_00417148,s_FINTYFLUSH_00412394,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_00414890,s_MD_PACK_00412280,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00417990 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_004171bc + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_00417968 + local_10 * 0x2c,&DAT_00417194 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_00417990 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_00417990 + local_10 * 0x2c) = 0;
        }
      }
      DAT_00412024 = (uint)(DAT_00417184 == '\0');
      DAT_00412020 = (uint)(DAT_00417185 == '\0');
      DAT_00412254 = (uint)(DAT_00417186 == '\0');
      FID_conflict__memcpy(&DAT_00412258,&DAT_00417158,0x28);
      DAT_00412240 = (uint)DAT_00417180;
      if ((DAT_00412240 == 0) || (10 < DAT_00412240)) {
        DAT_00412240 = 1;
      }
      DAT_00412244 = (uint)DAT_00417181;
      if ((DAT_00412244 == 0) || (4 < DAT_00412244)) {
        DAT_00412244 = 1;
      }
      DAT_00412248 = (uint)(DAT_00417182 == '\0');
      DAT_0041224c = (uint)(DAT_00417183 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_00401a1f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_00401d48 @ 00401d48

undefined4 __cdecl FUN_00401d48(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_00417990 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_00401de5 @ 00401de5

int __cdecl FUN_00401de5(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_00417990 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_00417968 + (local_1c + 1) * 0x2c,&DAT_00417968 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_00417968 + local_1c * 0x2c,&DAT_00412258,0x28);
    *(int *)(&DAT_00417990 + local_1c * 0x2c) = param_1;
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


// ==== FUN_00401f29 @ 00401f29

void FUN_00401f29(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_00417194,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_00417194 + local_c * 0x30,&DAT_00417968 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_004171bc + local_c * 0x30) =
         *(undefined4 *)(&DAT_00417990 + local_c * 0x2c);
  }
  DAT_00417184 = DAT_00412024 == 0;
  DAT_00417185 = DAT_00412020 == 0;
  DAT_00417186 = DAT_00412254 == 0;
  DAT_00417180 = (undefined1)DAT_00412240;
  DAT_00417181 = (undefined1)DAT_00412244;
  DAT_00417182 = DAT_00412248 == 0;
  DAT_00417183 = DAT_0041224c == 0;
  _memset(&DAT_00417158,0,0x28);
  FID_conflict__memcpy(&DAT_00417158,&DAT_00412258,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_00412288,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_00412288,0);
  }
  _lwrite(local_8,&DAT_00414890,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_004020f2 @ 004020f2

void FUN_004020f2(void)

{
  undefined4 local_8;
  
  for (local_8 = 1; local_8 < 0xb; local_8 = local_8 + 1) {
    if (local_8 == 1) {
      DAT_0041486c = 1000;
    }
    else {
      *(int *)(local_8 * 4 + 0x414868) = *(int *)(local_8 * 4 + 0x414864) + local_8 * 1000;
    }
  }
  return;
}


// ==== FUN_00402170 @ 00402170

/* WARNING: Removing unreachable block (ram,0x004021ce) */
/* WARNING: Removing unreachable block (ram,0x00402201) */

void __cdecl
FUN_00402170(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
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
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_004021d6;
LAB_004021ae:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_004021df;
LAB_004021b5:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_004021e9;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_00402204;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_004021ae;
LAB_004021d6:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_004021b5;
LAB_004021df:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_004021e9:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_004021c3;
          }
        }
LAB_004021c3:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_00402204:
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


// ==== FUN_0040222c @ 0040222c

void __cdecl
FUN_0040222c(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
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


// ==== FUN_00402280 @ 00402280

void FUN_00402280(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_0040ef30(DVar1);
  return;
}


// ==== FUN_0040229f @ 0040229f

int __cdecl FUN_0040229f(int param_1)

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


// ==== FUN_004022d0 @ 004022d0

void FUN_004022d0(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_004123b8 == 0) && (DAT_004127a0 == 0)) && (DAT_004123b0 == 0)) {
    SetMenu(DAT_004181b8,DAT_00417d04);
    if (DAT_0041224c == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00417cfc);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00417cfc);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004181b8);
  }
  else {
    SetMenu(DAT_004181b8,DAT_00418168);
    if (DAT_0041224c == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00417cfc);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00417cfc);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_004181b8);
  }
  return;
}


// ==== FUN_004023d4 @ 004023d4

bool __cdecl FUN_004023d4(int *param_1)

{
  return *param_1 == 0x28;
}


// ==== FUN_004023fc @ 004023fc

undefined2 __cdecl FUN_004023fc(int *param_1)

{
  short sVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    bVar2 = FUN_004023d4(param_1);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      sVar1 = *(short *)((int)param_1 + 10);
    }
    else {
      sVar1 = *(short *)((int)param_1 + 0xe);
    }
    if (sVar1 == 1) {
      local_c = 2;
    }
    else if (sVar1 == 4) {
      local_c = 0x10;
    }
    else if (sVar1 == 8) {
      local_c = 0x100;
    }
    else {
      local_c = 0;
    }
    bVar2 = FUN_004023d4(param_1);
    if ((CONCAT31(extraout_var_00,bVar2) != 0) && (param_1[8] != 0)) {
      local_c = (undefined2)param_1[8];
    }
  }
  return local_c;
}


// ==== FUN_004024ef @ 004024ef

HPALETTE __cdecl FUN_004024ef(ushort *param_1)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  undefined3 extraout_var;
  HPALETTE pHVar4;
  uint uVar5;
  HLOCAL hMem;
  LOGPALETTE *plpal;
  int local_18;
  
  bVar2 = FUN_004023d4((int *)param_1);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    pHVar4 = (HPALETTE)0x0;
  }
  else {
    uVar1 = *param_1;
    uVar3 = FUN_004023fc((int *)param_1);
    uVar5 = (uint)uVar3;
    if (uVar5 == 0) {
      pHVar4 = (HPALETTE)0x0;
    }
    else {
      hMem = LocalAlloc(2,uVar5 * 4 + 8);
      if (hMem == (HLOCAL)0x0) {
        pHVar4 = (HPALETTE)0x0;
      }
      else {
        plpal = LocalLock(hMem);
        plpal->palVersion = 0x300;
        plpal->palNumEntries = uVar3;
        _memset(plpal->palPalEntry,0,uVar5 << 2);
        for (local_18 = 0; local_18 < (int)uVar5; local_18 = local_18 + 1) {
          if ((9 < local_18) && (local_18 < 0xf7)) {
            plpal->palPalEntry[local_18].peRed = *(BYTE *)((int)param_1 + local_18 * 4 + uVar1 + 2);
            plpal->palPalEntry[local_18].peGreen =
                 *(BYTE *)((int)param_1 + local_18 * 4 + uVar1 + 1);
            plpal->palPalEntry[local_18].peBlue =
                 *(BYTE *)((int)param_1 + local_18 * 4 + (uint)uVar1);
            plpal->palPalEntry[local_18].peFlags = '\0';
          }
        }
        pHVar4 = CreatePalette(plpal);
        LocalUnlock(hMem);
        LocalFree(hMem);
      }
    }
  }
  return pHVar4;
}


// ==== FUN_00402657 @ 00402657

HGLOBAL __cdecl FUN_00402657(int *param_1)

{
  ushort uVar1;
  SIZE_T dwBytes;
  HGLOBAL _Dst;
  
  GlobalSize(param_1);
  FUN_004023fc(param_1);
  dwBytes = GlobalSize(param_1);
  _Dst = GlobalAlloc(0x40,dwBytes);
  if (_Dst == (HGLOBAL)0x0) {
    _Dst = (HGLOBAL)0x0;
  }
  else {
    uVar1 = FUN_004023fc(param_1);
    FID_conflict__memcpy(_Dst,param_1,(uint)uVar1 * 4 + 0x28);
  }
  return _Dst;
}


// ==== FUN_004026df @ 004026df

void __cdecl FUN_004026df(HDC param_1)

{
  int DestWidth;
  int DestHeight;
  ushort uVar1;
  BITMAPINFO *pBVar2;
  UINT UVar3;
  DWORD DVar4;
  HPALETTE local_10;
  
  DestWidth = DAT_00417f60[1];
  DestHeight = DAT_00417f60[2];
  if (DAT_00417f18 != (HPALETTE)0x0) {
    local_10 = SelectPalette(param_1,DAT_00417f18,0);
    RealizePalette(param_1);
  }
  if ((DAT_004127a0 == 0) || (DAT_004123b0 != 0)) {
    if ((((DAT_004123b8 == 0) &&
         (((DAT_004123bc == 0 || (DAT_004123b0 != 0)) || (DAT_004127a0 != 0)))) &&
        (((DAT_004123b4 != 0 || (DAT_004123b0 != 0)) || (DAT_004127a0 != 0)))) &&
       (((DAT_004123c0 == 0 || (DAT_004123b0 != 0)) || (DAT_004127a0 != 0)))) {
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0,DestWidth,DestHeight,0,0,DestWidth,DestHeight,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    }
    else {
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0,0x10,DestHeight,0,0,0x10,DestHeight,DAT_00417f60 + uVar1 + 10,pBVar2
                    ,UVar3,DVar4);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,DestWidth + -0x11,0,0x11,DestHeight,DestWidth + -0x11,0,0x11,DestHeight,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0,DestWidth,0x10,0,DestHeight + -0x10,DestWidth,0x10,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0x89,DestWidth,0x14,0,DestHeight + -0x9d,DestWidth,0x14,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
      FUN_0040dbda(param_1,DAT_0041285c,0x129,0x89);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0x9d,0xd8,DestHeight + -0x9d,0,0,0xd8,DestHeight + -0x9d,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0x18e,0x9d,DestWidth + -0x18e,DestHeight + -0x9d,0x18e,0,
                    DestWidth + -0x18e,DestHeight + -0x9d,DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,
                    DVar4);
      DVar4 = 0xcc0020;
      UVar3 = 1;
      pBVar2 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,0,0x116,DestWidth,DestHeight + -0x116,0,0,DestWidth,DestHeight + -0x116,
                    DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
      FUN_0040dbda(param_1,DAT_00412858,0xd8,0x9d);
      FUN_0040dbda(param_1,DAT_00412854,0x10,0x10);
    }
  }
  else {
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0,0,0x10,DestHeight,0,0,0x10,DestHeight,DAT_00417f60 + uVar1 + 10,pBVar2,
                  UVar3,DVar4);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,DestWidth + -0x11,0,0x11,DestHeight,DestWidth + -0x11,0,0x11,DestHeight,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0,0,DestWidth,0x10,0,DestHeight + -0x10,DestWidth,0x10,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0,0x89,DestWidth,0x14,0,DestHeight + -0x9d,DestWidth,0x14,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    FUN_0040dbda(param_1,DAT_0041285c,0x129,0x89);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0,0x9d,0xd8,DestHeight + -0x9d,0,0,0xd8,DestHeight + -0x9d,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0x18e,0x9d,DestWidth + -0x18e,DestHeight + -0x9d,0x18e,0,
                  DestWidth + -0x18e,DestHeight + -0x9d,DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4
                 );
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,0,0x116,DestWidth,DestHeight + -0x116,0,0,DestWidth,DestHeight + -0x116,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    FUN_0040dbda(param_1,DAT_00412858,0xd8,0x9d);
    FUN_0040dbda(param_1,DAT_00412850,0x10,0x10);
  }
  if (local_10 != (HPALETTE)0x0) {
    SelectPalette(param_1,local_10,0);
  }
  return;
}


// ==== FUN_00402d97 @ 00402d97

void __cdecl FUN_00402d97(HPALETTE param_1)

{
  HDC hdc;
  UINT local_10;
  HLOCAL local_c;
  undefined2 *local_8;
  
  local_c = LocalAlloc(2,0x408);
  if (local_c != (HLOCAL)0x0) {
    local_8 = LocalLock(local_c);
    *local_8 = 0x300;
    GetObjectA(param_1,4,&local_10);
    local_8[1] = (short)local_10;
    GetPaletteEntries(param_1,0,local_10,(LPPALETTEENTRY)(local_8 + 2));
    if (DAT_00418024 == 8) {
      hdc = GetDC((HWND)0x0);
      GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)(local_8 + 2));
      GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)(local_8 + 0x1ee));
      ReleaseDC((HWND)0x0,hdc);
    }
    SetPaletteEntries(param_1,0,0x100,(PALETTEENTRY *)(local_8 + 2));
    LocalUnlock(local_c);
    LocalFree(local_c);
  }
  return;
}


// ==== FUN_00402e8e @ 00402e8e

int __cdecl FUN_00402e8e(int *param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  
  if ((((param_2 < 0) || (param_3 < 0)) || (param_1[1] <= param_2)) || (param_1[2] <= param_3)) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
    uVar1 = FUN_004023fc(param_1);
    iVar2 = (int)param_1 +
            ((param_1[2] - param_3) + -1) * (iVar2 + 3U & 0xfffffffc) + param_2 +
            (uint)uVar1 * 4 + 0x28;
  }
  return iVar2;
}


// ==== FUN_00402f1b @ 00402f1b

void __cdecl
FUN_00402f1b(int *param_1,int param_2,int param_3,uint param_4,int param_5,int *param_6,int param_7,
            int param_8)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00402e8e(param_1,param_2,param_5 + param_3 + -1);
  puVar2 = (undefined4 *)FUN_00402e8e(param_6,param_7,param_8 + param_5 + -1);
  FUN_0040222c(puVar2,puVar1,param_4,param_5,param_6[1] + 3U & 0xfffffffc,
               param_1[1] + 3U & 0xfffffffc);
  return;
}


// ==== FUN_00402fa2 @ 00402fa2

void __cdecl
FUN_00402fa2(int *param_1,int param_2,int param_3,uint param_4,int param_5,int *param_6,int param_7,
            int param_8,byte param_9)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)FUN_00402e8e(param_1,param_2,param_5 + param_3 + -1);
  pcVar2 = (char *)FUN_00402e8e(param_6,param_7,param_5 + param_8 + -1);
  FUN_00402170(pcVar2,pcVar1,param_4,param_5,param_6[1] + 3U & 0xfffffffc,
               param_1[1] + 3U & 0xfffffffc,param_9);
  return;
}


// ==== FUN_0040302d @ 0040302d

void FUN_0040302d(void)

{
  FUN_00402f1b(DAT_00417f68,0,0,DAT_00417f60[1] - 1,DAT_00417f60[2] + -1,DAT_00417f60,0,0);
  return;
}


// ==== FUN_0040306d @ 0040306d

void FUN_0040306d(void)

{
  GlobalFree(DAT_00417f68);
  GlobalFree(DAT_00418030);
  GlobalFree(DAT_00417cd8);
  GlobalFree(DAT_00417ce4);
  GlobalFree(DAT_00418018);
  DeleteObject(DAT_00417f18);
  GlobalFree(DAT_00417f6c);
  GlobalFree(DAT_00417f60);
  DeleteObject(DAT_00412850);
  DeleteObject(DAT_00412854);
  DeleteObject(DAT_00412858);
  DeleteObject(DAT_0041285c);
  return;
}


// ==== FUN_0040310d @ 0040310d

undefined4 FUN_0040310d(void)

{
  FUN_0040306d();
  DestroyWindow(DAT_00417cfc);
  return 0;
}


// ==== FUN_00403130 @ 00403130

int __cdecl FUN_00403130(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_00403151 @ 00403151

int __cdecl FUN_00403151(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(1);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_00403172 @ 00403172

undefined4 FUN_00403172(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_MainFlushWnd_00412830,(LPCSTR)0x0);
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


// ==== FUN_004031ef @ 004031ef

void __cdecl FUN_004031ef(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_00412860 = 2;
  }
  DAT_00417e20 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_00403232 @ 00403232

void __cdecl FUN_00403232(HWND param_1)

{
  if (DAT_00417e20 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00417e20);
  }
  return;
}


// ==== FUN_00403263 @ 00403263

void __cdecl FUN_00403263(uint *param_1)

{
  FUN_0040ecb0((uint *)&DAT_00412868,param_1);
  return;
}


// ==== FUN_00403284 @ 00403284

void __cdecl FUN_00403284(HWND param_1)

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


// ==== FUN_004033bc @ 004033bc

INT_PTR FUN_004033bc(void)

{
  INT_PTR IVar1;
  
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_QUICKHELPBMP_00412990);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  IVar1 = FUN_0040e34d(DAT_0041800c,s_EXITGAME_004129a0,DAT_004181b8,FUN_00403b42);
  DAT_004123c0 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  return IVar1;
}


// ==== FUN_00403440 @ 00403440

INT_PTR FUN_00403440(void)

{
  INT_PTR IVar1;
  
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_QUICKHELPBMP_004129ac);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  IVar1 = FUN_0040e34d(DAT_0041800c,s_NEWGAME_004129bc,DAT_004181b8,FUN_00403b42);
  DAT_004123c0 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  return IVar1;
}


// ==== FUN_004034c4 @ 004034c4

INT_PTR __cdecl FUN_004034c4(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040e34d(DAT_0041800c,s_RESETSCORE_004129c4,param_1,FUN_00405bc0);
  return IVar1;
}


// ==== FUN_004034f9 @ 004034f9

void FUN_004034f9(void)

{
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_ABOUTBMP_004129d0);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  FUN_0040e34d(DAT_0041800c,s_ABOUT_004129dc,DAT_004181b8,FUN_00403cd9);
  DAT_004123c0 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  return;
}


// ==== FUN_00403574 @ 00403574

void __cdecl FUN_00403574(HWND param_1)

{
  FUN_0040e34d(DAT_0041800c,s_CREDITS_004129e4,param_1,FUN_00403fbf);
  return;
}


// ==== FUN_004035a0 @ 004035a0

void __cdecl FUN_004035a0(HWND param_1)

{
  FUN_0040e34d(DAT_0041800c,s_SYSTEMINFODIALOG_004129ec,param_1,FUN_00404150);
  return;
}


// ==== FUN_004035cc @ 004035cc

void FUN_004035cc(void)

{
  DAT_004123c4 = 1;
  FUN_00403263((uint *)s_QUICKHELPBMP_00412a00);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  FUN_0040e34d(DAT_0041800c,s_QUICKHELPDIALOG_00412a10,DAT_004181b8,FUN_00404b81);
  DAT_004123c4 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  return;
}


// ==== FUN_00403647 @ 00403647

void __cdecl FUN_00403647(int param_1)

{
  if (((4 < param_1) && (param_1 < 9)) && (*(int *)(&DAT_00417ef0 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_00417ef0 + param_1 * 4) = 1;
    Sleep(200);
    DAT_004123c4 = 1;
    switch(param_1) {
    case 5:
      FUN_00403263((uint *)s_PBRUSHBMP_00412a20);
      FUN_0040e34d(DAT_0041800c,s_QHELPPBRUSHDIALOG_00412a2c,DAT_004181b8,FUN_004046ee);
      break;
    case 6:
      FUN_00403263((uint *)s_BOMBBMP_00412a40);
      FUN_0040e34d(DAT_0041800c,s_QHELPBOMBDIALOG_00412a48,DAT_004181b8,FUN_004046ee);
      break;
    case 7:
      FUN_00403263((uint *)s_QHELPNOBONUSBMP_00412a58);
      FUN_0040e34d(DAT_0041800c,s_QHELPNOBONUSDIALOG_00412a68,DAT_004181b8,FUN_004046ee);
      break;
    case 8:
      FUN_00403263((uint *)s_QUICKHELPBMP_00412a7c);
      FUN_0040e34d(DAT_0041800c,s_QGOBUYDIALOG_00412a8c,DAT_004181b8,FUN_0040495a);
    }
    DAT_004123c4 = 0;
    FUN_004022d0();
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
    UpdateWindow(DAT_004181b8);
  }
  return;
}


// ==== FUN_004037cf @ 004037cf

void FUN_004037cf(void)

{
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_CUPBMP_00412a9c);
  FUN_0040e34d(DAT_0041800c,s_YOURNAME_00412aa4,DAT_004181b8,FUN_00404ded);
  DAT_004123c0 = 0;
  return;
}


// ==== FUN_0040381e @ 0040381e

void FUN_0040381e(void)

{
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_CUPBMP_00412ab0);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  FUN_0040e34d(DAT_0041800c,s_BALLSTOP_00412ab8,DAT_004181b8,FUN_0040512c);
  DAT_004123c0 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  return;
}


// ==== FUN_00403899 @ 00403899

void FUN_00403899(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00412244;
  iVar1 = DAT_00412240;
  DAT_004123c0 = 1;
  FUN_00403263((uint *)s_OPTIONSBMP_00412ac4);
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  FUN_0040e34d(DAT_0041800c,s_OPTIONS_00412ad0,DAT_004181b8,FUN_004054a9);
  DAT_004123c0 = 0;
  InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  UpdateWindow(DAT_004181b8);
  if ((iVar1 != DAT_00412240) || (iVar2 != DAT_00412244)) {
    SendMessageA(DAT_004181b8,0x111,0x65,0);
  }
  return;
}


// ==== FUN_00403958 @ 00403958

void __cdecl FUN_00403958(HWND param_1)

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
  local_8 = FUN_0040dc70(pHVar1,&DAT_00412868);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040db91(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00417f18,0);
  RealizePalette(pHVar1);
  FUN_0040dbda(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00403a4d @ 00403a4d

void __cdecl FUN_00403a4d(HWND param_1)

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
  ho = FUN_0040dc70(pHVar1,s_QUICKHELPBMP_00412ad8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_0040db91(ho,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_00417f18,0);
  RealizePalette(pHVar1);
  FUN_0040dbda(pHVar1,ho,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(ho);
  return;
}


// ==== FUN_00403b42 @ 00403b42

UINT FUN_00403b42(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403284(param_1);
      DAT_00418004 = param_1;
      DAT_00417f78 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403958(DAT_00417f78);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00418004 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00418004);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00418004,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00418004,(RECT *)0x0,0);
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
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


// ==== FUN_00403cd9 @ 00403cd9

UINT FUN_00403cd9(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403284(param_1);
      DAT_00418034 = param_1;
      DAT_0041802c = GetDlgItem(param_1,100);
      FUN_0040e4e0(DAT_0041800c,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_0040e664(&DAT_00412ae8,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_0040e664(s_Product_ID_00412aec,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403958(DAT_0041802c);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00418034) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_00418034);
      SelectPalette(local_10c,DAT_00417f18,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_00418034,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00418034,(RECT *)0x0,0);
      InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
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
      FUN_004035a0(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00403574(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00403fbf @ 00403fbf

UINT FUN_00403fbf(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403284(param_1);
      DAT_00417f1c = param_1;
      DAT_00417ed4 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403958(DAT_00417ed4);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00417f1c == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00417f1c);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00417f1c,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00417f1c,(RECT *)0x0,0);
        InvalidateRect(DAT_00418034,(RECT *)0x0,0);
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
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


// ==== FUN_00404150 @ 00404150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00404150(HWND param_1,int param_2,uint param_3)

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
    FUN_00403284(param_1);
    _DAT_00417da8 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412af8,local_49c.dwMajorVersion,-1);
    FUN_0040ecb0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412afc);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b00,local_49c.dwMinorVersion,-1);
    FUN_0040ecc0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b04);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b08,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_0040ecc0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b0c);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_0040ecc0((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b10,local_4dc.dwTotalPhys >> 10,-1);
    FUN_0040ecb0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b14);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_0040ecb0((uint *)local_404,(uint *)&DAT_00412b18);
    FUN_0040ecc0((uint *)local_404,(uint *)&local_4b4);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b1c);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_408 * local_4b8 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b20,local_4a0,-1);
    FUN_0040ecc0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b24);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_00412b48,s_display_drv_00412b3c,s_Unknown_00412b34,local_404,0x80,
               s_system_ini_00412b28);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b5c,local_4a0,-1);
    FUN_0040ecb0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b60);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b64,local_4a0,-1);
    FUN_0040ecc0((uint *)local_404,puVar1);
    FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b68);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b6c,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_0040ecc0((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b70,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_0040ecc0((uint *)local_404,puVar1);
      FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b74);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b7c,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_0040ecc0((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_0040da40((uint *)&DAT_00412b78,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_0040ecc0((uint *)local_404,puVar1);
      }
      FUN_0040ecc0((uint *)local_404,(uint *)&DAT_00412b80);
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


// ==== FUN_004046ee @ 004046ee

UINT FUN_004046ee(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00403958(DAT_00417ed0);
      }
      return 0;
    }
    FUN_00403284(param_1);
    DAT_00417cdc = param_1;
    DAT_00417ed0 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0041224c == 0);
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
      DAT_0041224c = (uint)(LVar2 == 0);
      FUN_00401f29();
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
      DAT_0041224c = (uint)(LVar2 == 0);
      FUN_00401f29();
      EndDialog(param_1,0);
      PostMessageA(DAT_004181b8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00417cdc == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00417cdc);
  SelectPalette(hdc,DAT_00417f18,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00417cdc,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00417cdc,(RECT *)0x0,0);
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_0040495a @ 0040495a

UINT FUN_0040495a(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00403284(param_1);
      DAT_00418010 = param_1;
      DAT_00417e28 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_0041224c == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403958(DAT_00417e28);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00418010 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00418010);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_00418010,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_00418010,(RECT *)0x0,0);
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
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
        DAT_0041224c = (uint)(LVar2 == 0);
        FUN_00401f29();
        EndDialog(param_1,0);
        PostMessageA(DAT_004181b8,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00404b81 @ 00404b81

UINT FUN_00404b81(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00403958(DAT_00417cec);
      }
      return 0;
    }
    FUN_00403284(param_1);
    DAT_00417ee8 = param_1;
    DAT_00417cec = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_00412248 == 0);
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
      DAT_00412248 = (uint)(LVar2 == 0);
      FUN_00401f29();
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
      DAT_00412248 = (uint)(LVar2 == 0);
      FUN_00401f29();
      EndDialog(param_1,0);
      PostMessageA(DAT_004181b8,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00417ee8 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00417ee8);
  SelectPalette(hdc,DAT_00417f18,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00417ee8,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00417ee8,(RECT *)0x0,0);
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00404ded @ 00404ded

UINT FUN_00404ded(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_00403958(DAT_00417e14);
      }
      return 0;
    }
    FUN_00403284(param_1);
    DAT_00417f50 = param_1;
    DAT_00417e14 = GetDlgItem(param_1,100);
    if (DAT_00412860 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_00412258);
    _Size = 0x10;
    _Src = FUN_0040da40((uint *)&DAT_00412b84,DAT_004180b0,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (DAT_00417f50 == param_3) {
        return 0;
      }
    }
    hdc = GetDC(DAT_00417f50);
    SelectPalette(hdc,DAT_00417f18,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_00417f50,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_00417f50,(RECT *)0x0,0);
      InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_00412258,DAT_00412860 * 0x11);
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


// ==== FUN_0040512c @ 0040512c

UINT FUN_0040512c(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00403284(param_1);
      DAT_00417ec4 = param_1;
      DAT_00417f20 = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_00412968) && (DAT_00412968 < 10)) {
        SetDlgItemTextA(param_1,DAT_00412968 + 0x33,&DAT_00412b88);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_0040da40((uint *)&DAT_00412b8c,*(int *)(&DAT_00417990 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00417968 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403958(DAT_00417f20);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_00417ec4) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00417ec4);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_00417ec4,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_00417ec4,(RECT *)0x0,0);
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_004034c4(DAT_00417ec4), IVar5 == 1)) {
        if ((-1 < DAT_00412968) && (DAT_00412968 < 10)) {
          SetDlgItemTextA(param_1,DAT_00412968 + 0x33,&DAT_00412b90);
        }
        DAT_00412968 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00417990 + local_14 * 0x2c) = 0;
          _memset(&DAT_00417968 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_0040da40((uint *)&DAT_00412b94,*(int *)(&DAT_00417990 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_00417968 + local_14 * 0x2c);
        }
        FUN_00401f29();
      }
    }
  }
  return 0;
}


// ==== FUN_004054a9 @ 004054a9

UINT FUN_004054a9(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_004181b8,s_FFLUSH_HLP_004123c8,1,0x1e);
    }
    else if (param_2 == 0xf) {
      FUN_00403958(DAT_00417ebc);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00405653:
      hdc = GetDC(DAT_00417e0c);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_00417e0c,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00417e0c,(RECT *)0x0,0);
      InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00403284(param_1);
      DAT_00417e0c = param_1;
      DAT_00417ebc = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00412020;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00412024;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_00412254;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      WVar7 = 2;
      UVar6 = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xf);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x62,DAT_00412244 + 0x5e);
      if (DAT_00412860 == 1) {
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
      DAT_00417f58 = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_00412258);
      pCVar2 = FUN_0040da40((uint *)&DAT_00412b98,DAT_00412240,-1);
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
        DAT_00412020 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_00412024 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_00412254 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00412244 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00412244 = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00412244 = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_00412244 = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_00412258,DAT_00412860 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
          pcVar3 = FUN_0040da40((uint *)&DAT_00412ba8,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00405a5c:
            DAT_00412240 = local_28;
            break;
          }
          pcVar3 = FUN_0040da40((uint *)&DAT_00412bac,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00405a5c;
        }
      case 2:
        DAT_00417e0c = (HWND)0x0;
        pHVar9 = DAT_00417f58;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_00412240;
          for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
            pcVar3 = FUN_0040da40((uint *)&DAT_00412b9c,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_0040579c:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_0040da40((uint *)&DAT_00412ba0,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_0040579c;
          }
          pCVar2 = FUN_0040da40((uint *)&DAT_00412ba4,local_1c,-1);
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
        WinHelpA(DAT_004181b8,s_FFLUSH_HLP_004123c8,1,0x1e);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_00417e0c == param_3) {
      return 0;
    }
    goto LAB_00405653;
  }
  return 0;
}


// ==== FUN_00405bc0 @ 00405bc0

UINT FUN_00405bc0(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00403284(param_1);
      DAT_00418164 = param_1;
      DAT_00417eb8 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00403a4d(DAT_00417eb8);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00418164 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00418164);
      SelectPalette(hdc,DAT_00417f18,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00418164,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00417ec4,(RECT *)0x0,0);
        InvalidateRect(DAT_00418164,(RECT *)0x0,0);
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
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


// ==== FUN_00405d67 @ 00405d67

UINT FUN_00405d67(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  HDC pHVar1;
  HPALETTE hPal;
  INT_PTR IVar2;
  int iVar3;
  UINT UVar4;
  tagRECT local_18;
  
  if (param_2 < 0x11) {
    if (param_2 == 0x10) {
      if (DAT_004127a0 == 0) {
        IVar2 = FUN_004033bc();
        if (IVar2 != 1) {
          return 0;
        }
        iVar3 = FUN_00401d48(DAT_004180b0,&DAT_00417e1c);
        if ((iVar3 != 0) && (DAT_00417e1c < 10)) {
          if (DAT_00412254 != 0) {
            FUN_004037cf();
          }
          FUN_00401de5(DAT_004180b0);
          FUN_00401f29();
          DAT_00412968 = DAT_00417e1c;
          FUN_0040381e();
        }
      }
      FUN_00401f29();
      SendMessageA(param_1,2,0,0);
      return 0;
    }
    if (param_2 == 1) {
      GetClientRect(param_1,&local_18);
      DAT_0041801c = CreateWindowExA(0,PTR_s_GameFlushWnd_00412834,(LPCSTR)0x0,0x50000000,0,0,
                                     (local_18.right - local_18.left) + DAT_004180b8 * 2,0x127,
                                     param_1,(HMENU)0x0,DAT_0041800c,(LPVOID)0x0);
      FUN_004031ef(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_0040306d();
      FUN_00401f29();
      FUN_004011f5(0);
      FUN_00401605();
      FUN_00403232(param_1);
      KillTimer(DAT_0041801c,1);
      KillTimer(DAT_0041801c,2);
      KillTimer(DAT_0041801c,3);
      FUN_00401f29();
      WinHelpA(param_1,s_FFLUSH_HLP_004123c8,2,0);
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      if (DAT_00412848 == 2) {
        DAT_00412848 = 1;
        UVar4 = DefWindowProcA(param_1,0x20,(WPARAM)param_3,param_4);
        return UVar4;
      }
      if (DAT_00412848 != 1) {
        UVar4 = DefWindowProcA(param_1,0x20,(WPARAM)param_3,param_4);
        return UVar4;
      }
      DAT_00412848 = 0;
      SetFocus(DAT_0041801c);
      UVar4 = DefWindowProcA(param_1,0x20,(WPARAM)param_3,param_4);
      return UVar4;
    }
    if (param_2 == 0x1c) {
      DAT_004123b4 = param_3;
      DAT_004123a0 = 0;
      DAT_004123a8 = 0;
      if (param_3 == (HWND)0x0) {
        FUN_00401f29();
        FUN_004011f5(0);
        SendMessageA(param_1,0x464,0,param_4);
        if ((DAT_004123b0 == 0) && (DAT_004127a0 == 0)) {
          DAT_004123b8 = 1;
        }
        FUN_004022d0();
      }
      else {
        FUN_00401ab8();
        if (DAT_004123b8 == 0) {
          if (DAT_004123b0 == 0) {
            FUN_004011f5(DAT_004126e0 + 2);
          }
          else {
            FUN_004011f5(1);
          }
        }
        SendMessageA(param_1,0x464,(WPARAM)param_3,param_4);
        if (((DAT_004123b8 == 0) && (DAT_004123b0 == 0)) && (DAT_004127a0 == 0)) {
          InvalidateRect(DAT_0041801c,(RECT *)0x0,1);
        }
      }
      DAT_004123bc = 0;
      InvalidateRect(DAT_0041801c,(RECT *)0x0,0);
      return 0;
    }
  }
  else if (param_2 < 0x25) {
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00417e24;
      *(undefined4 *)(param_4 + 0xc) = DAT_00417ec0;
      return 0;
    }
    if (param_2 == 0x21) {
      DAT_00412848 = 2;
      UVar4 = DefWindowProcA(param_1,0x21,(WPARAM)param_3,param_4);
      return UVar4;
    }
  }
  else {
    if (0x86 < param_2) {
      if (param_2 < 0x112) {
        if (param_2 == 0x111) {
          PostMessageA(DAT_0041801c,0x111,(WPARAM)param_3,param_4);
        }
        else {
          if (param_2 != 0x100) goto LAB_00406356;
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          if (param_3 == (HWND)0x1b) {
            ShowWindow(DAT_004181b8,6);
            return 0;
          }
          if ((DAT_004127a0 == 0) && (DAT_004123b0 == 0)) {
            PostMessageA(DAT_0041801c,0x100,(WPARAM)param_3,param_4);
          }
          else {
            PostMessageA(DAT_004181b8,0x111,0x65,0);
          }
        }
      }
      else {
        if (param_2 < 0x310) {
          if (param_2 == 0x30f) {
LAB_00405e64:
            pHVar1 = GetDC((HWND)0x0);
            hPal = SelectPalette(pHVar1,DAT_00417f18,(uint)(param_2 != 0x30f));
            UVar4 = RealizePalette(pHVar1);
            SelectPalette(pHVar1,hPal,1);
            RealizePalette(pHVar1);
            ReleaseDC((HWND)0x0,pHVar1);
            InvalidateRect(DAT_0041801c,(RECT *)0x0,1);
            return UVar4;
          }
          if (param_2 == 0x211) {
            DAT_004123bc = 1;
            InvalidateRect(param_1,(RECT *)0x0,0);
            return 0;
          }
          if (param_2 == 0x212) {
            DAT_004123bc = 0;
            InvalidateRect(param_1,(RECT *)0x0,0);
            return 0;
          }
          goto LAB_00406356;
        }
        if (param_2 == 0x311) {
          if (param_3 != param_1) goto LAB_00405e64;
        }
        else if (param_2 != 0x464) goto LAB_00406356;
      }
      return 0;
    }
    if (param_2 == 0x86) {
      if (param_3 != (HWND)0x0) {
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
      }
      UVar4 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
      return UVar4;
    }
    if (param_2 == 0x7e) {
      Sleep(300);
      GdiFlush();
      Sleep(300);
      DeleteObject(DAT_00412850);
      DeleteObject(DAT_00412854);
      DeleteObject(DAT_00412858);
      DeleteObject(DAT_0041285c);
      Sleep(100);
      pHVar1 = GetDC((HWND)0x0);
      DAT_00412850 = FUN_0040dc70(pHVar1,s_GAMEOVERBMP_00412bb0);
      DAT_00412854 = FUN_0040dc70(pHVar1,s_BREAKBMP_00412bbc);
      DAT_00412858 = FUN_0040dc70(pHVar1,s_BREAKBMP1_00412bc8);
      DAT_0041285c = FUN_0040dc70(pHVar1,s_BREAKBMP2_00412bd4);
      ReleaseDC((HWND)0x0,pHVar1);
      GdiFlush();
      Sleep(100);
      return 0;
    }
  }
LAB_00406356:
  UVar4 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar4;
}


// ==== FUN_00406483 @ 00406483

void FUN_00406483(void)

{
  DAT_0041296c = GetTickCount();
  return;
}


// ==== FUN_0040649e @ 0040649e

void __cdecl FUN_0040649e(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  uint local_10;
  
  DVar2 = GetTickCount();
  if (DAT_0041296c < DVar2) {
    if (DVar2 < param_1 + DAT_0041296c) {
      uVar1 = param_1 - (DVar2 - DAT_0041296c);
      if (uVar1 == 0) {
        Sleep(1);
      }
      else if (uVar1 < 10) {
        for (local_10 = 0; local_10 < uVar1; local_10 = local_10 + 1) {
          Sleep(1);
          DVar2 = GetTickCount();
          if (uVar1 + DAT_0041296c <= DVar2) {
            return;
          }
        }
      }
      else {
        Sleep(1);
      }
    }
    else {
      Sleep(1);
    }
  }
  else {
    Sleep(1);
  }
  return;
}


// ==== FUN_0040657c @ 0040657c

void __cdecl
FUN_0040657c(undefined4 param_1,HDC param_2,undefined4 param_3,char param_4,int param_5)

{
  ushort uVar1;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  char local_10;
  char local_c;
  
  for (local_c = '\0'; local_c < '\x04'; local_c = local_c + '\x01') {
    for (local_10 = '\0'; local_10 < '\x04'; local_10 = local_10 + '\x01') {
      if ((param_4 == '\0') || (param_4 == '\x01')) {
        local_14 = 0;
      }
      else {
        local_14 = 1;
      }
      if ((param_4 == '\0') || (param_4 == '\x03')) {
        local_18 = 0;
      }
      else {
        local_18 = 1;
      }
      FUN_00402f1b(DAT_00418030,
                   (char)(&DAT_00417db8)[(int)local_10 + param_4 * 0x14 + local_c * 5] * 0xd + 0x1e1
                   ,param_5 * -0xd + 0xe4,0xd,0xd,DAT_00417f60,
                   local_c * 0xd + local_18 * 0x100 + 0x99,local_10 * 0xd + local_14 * 0x43 + 0x9e);
    }
  }
  if ((param_4 == '\0') || (param_4 == '\x01')) {
    local_1c = 0;
  }
  else {
    local_1c = 1;
  }
  if ((param_4 == '\0') || (param_4 == '\x03')) {
    local_20 = 0;
  }
  else {
    local_20 = 1;
  }
  if ((param_4 == '\0') || (param_4 == '\x01')) {
    local_24 = 0;
  }
  else {
    local_24 = 1;
  }
  if ((param_4 == '\0') || (param_4 == '\x03')) {
    local_28 = 0;
  }
  else {
    local_28 = 1;
  }
  rop = 0xcc0020;
  iUsage = 1;
  lpbmi = DAT_00417f6c;
  uVar1 = FUN_004023fc(DAT_00417f60);
  StretchDIBits(param_2,local_28 * 0x100 + 0x99,local_24 * 0x43 + 0x9e,0x34,0x34,
                local_20 * 0x100 + 0x99,DAT_00417f60[2] + local_1c * -0x43 + -0xd2,0x34,0x34,
                DAT_00417f60 + uVar1 + 10,lpbmi,iUsage,rop);
  return;
}


// ==== FUN_004067ef @ 004067ef

undefined4 FUN_004067ef(void)

{
  undefined4 uVar1;
  int iVar2;
  char local_10;
  
  DAT_004127a0 = 1;
  FUN_004022d0();
  for (local_10 = '\0'; local_10 < '\x04'; local_10 = local_10 + '\x01') {
    if ((local_10 != DAT_0041281c) && ((&DAT_00417db8)[local_10 * 0x14] != -1)) {
      (&DAT_00417dbc)[DAT_0041281c * 0x14] =
           (&DAT_00417dbc)[local_10 * 0x14] + (&DAT_00417dbc)[DAT_0041281c * 0x14];
    }
  }
  DAT_00418028 = FUN_0040de82((LPCSTR)0xca);
  if (DAT_00418028 != (int *)0x0) {
    DAT_00417f54 = DAT_00418028;
    FUN_00402f1b(DAT_00418028,0,0,0x87,0x87,DAT_00417f68,8,0x95);
    GlobalFree(DAT_00417f54);
  }
  FUN_0040b1db();
  InvalidateRect(DAT_0041801c,(RECT *)0x0,0);
  if (DAT_004180b0 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00401d48(DAT_004180b0,&DAT_00417e1c);
    if ((iVar2 == 0) || (9 < DAT_00417e1c)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00406959 @ 00406959

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406959(void)

{
  int iVar1;
  ushort uVar2;
  BITMAPINFO *pBVar3;
  UINT UVar4;
  DWORD DVar5;
  int local_68;
  int local_5c [5];
  int local_48;
  int local_44;
  int local_40;
  CHAR local_3c [16];
  int local_2c;
  int local_24;
  HDC local_20;
  int local_1c;
  HGDIOBJ local_18;
  int local_c;
  HDC local_8;
  
  local_40 = 0;
  if (((_DAT_00412828 != 0) && (DAT_0041280c < _DAT_00412828)) && (-1 < DAT_0041280c)) {
    FUN_004014f3(1);
    local_c = 0;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      if ((&DAT_00418038)[DAT_0041280c * 4 + local_1c] != '\0') {
        local_c = local_c + 1;
      }
    }
    if (DAT_004180c4 == 0) {
      for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
        if ((('\0' < (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5]) &&
            ((char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] < '\x05')) &&
           (('\0' < (char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] &&
            ((char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] < '\x05')))) {
          FUN_0040b0d4();
          (&DAT_004126c8)[DAT_0041281c] = 0;
          FUN_004014f3(4);
          local_20 = GetDC(DAT_0041801c);
          local_8 = CreateCompatibleDC(local_20);
          local_18 = SelectObject(local_8,DAT_004180d8);
          SelectPalette(local_20,DAT_00417f18,0);
          RealizePalette(local_20);
          wsprintfA(local_3c,&DAT_00412be0,(&DAT_004126c8)[DAT_0041281c]);
          FUN_00407bb3(local_20,local_8,(int)local_3c,5,500,0xbd);
          DeleteDC(local_8);
          ReleaseDC(DAT_0041801c,local_20);
          return;
        }
      }
    }
    local_68 = 0;
    for (local_2c = 0; local_2c < 5; local_2c = local_2c + 1) {
      local_5c[local_2c] = 0;
    }
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      for (local_24 = 0; local_24 < 4; local_24 = local_24 + 1) {
        switch((&DAT_00417db8)[local_1c + local_24 * 5 + DAT_0041281c * 0x14]) {
        case 1:
          local_5c[1] = local_5c[1] + 1;
          break;
        case 2:
          local_5c[2] = local_5c[2] + 1;
          break;
        case 3:
          local_5c[3] = local_5c[3] + 1;
          break;
        case 4:
          local_5c[4] = local_5c[4] + 1;
        }
      }
    }
    local_24 = 1;
    local_5c[0] = local_5c[1];
    for (local_1c = 2; local_1c < 5; local_1c = local_1c + 1) {
      if (local_5c[0] < local_5c[local_1c]) {
        local_5c[0] = local_5c[local_1c];
        local_24 = local_1c;
      }
    }
    local_5c[0] = local_24;
    iVar1 = local_5c[0];
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      if (((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\0') ||
         ((&DAT_00418038)[DAT_0041280c * 4 + local_1c] == '\0')) {
        (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] =
             (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] +
             (&DAT_00418038)[DAT_0041280c * 4 + local_1c];
      }
      else if ((((((char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] < '\x01'
                  ) || ('\x04' < (char)(&DAT_00417db8)
                                       [local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5])) ||
                ((char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] < '\x01')) ||
               ('\x04' < (char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c])) &&
              ((((char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] < '\x05'
                || ('\a' < (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5])
                ) || (((char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] < '\x05' ||
                      ('\a' < (char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c])))))) {
        if (((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\x06') ||
           ((&DAT_00418038)[DAT_0041280c * 4 + local_1c] == '\x06')) {
          (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] = 0;
        }
        else if (((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\a') ||
                ((&DAT_00418038)[DAT_0041280c * 4 + local_1c] == '\a')) {
          if ((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\a') {
            (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] =
                 (&DAT_00418038)[DAT_0041280c * 4 + local_1c];
          }
          if ((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\x04') {
            (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] = 1;
          }
          else {
            (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] =
                 (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] + '\x01';
          }
        }
        else if (((&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] == '\x05') ||
                ((&DAT_00418038)[DAT_0041280c * 4 + local_1c] == '\x05')) {
          local_5c[0]._0_1_ = (undefined1)local_24;
          (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] =
               (undefined1)local_5c[0];
        }
      }
      else {
        if ((('\0' < (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5]) &&
            ((char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] < '\x05')) &&
           (('\0' < (char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] &&
            ((char)(&DAT_00418038)[DAT_0041280c * 4 + local_1c] < '\x05')))) {
          local_68 = local_68 + 1;
          (&DAT_00417dbc)[DAT_0041281c * 0x14] = (&DAT_00417dbc)[DAT_0041281c * 0x14] + '\x01';
          if (local_40 == 0) {
            DAT_004180c4 = DAT_004180c4 + -1;
          }
          local_40 = local_40 + 1;
        }
        (&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + DAT_00412824 * 5] = 0;
      }
    }
    for (local_1c = DAT_0041280c; local_1c < _DAT_00412828; local_1c = local_1c + 1) {
      for (local_24 = 0; local_24 < 4; local_24 = local_24 + 1) {
        (&DAT_00418038)[local_1c * 4 + local_24] = (&DAT_0041803c)[local_1c * 4 + local_24];
      }
    }
    local_5c[0] = iVar1;
    local_20 = GetDC(DAT_0041801c);
    DAT_00417d00 = 0x25;
    local_8 = CreateCompatibleDC(local_20);
    SelectPalette(local_20,DAT_00417f18,0);
    RealizePalette(local_20);
    if (0 < local_c) {
      local_44 = 10 - _DAT_00412828;
      if (local_44 < 1) {
        local_44 = 1;
      }
      DAT_004180b0 = DAT_004180b0 + DAT_00412800 * DAT_004126e4 * local_44 * local_c;
      (&DAT_004126c8)[DAT_0041281c] =
           (&DAT_004126c8)[DAT_0041281c] + DAT_00412800 * DAT_004126e4 * local_44 * local_c;
      wsprintfA(local_3c,&DAT_00412be8,DAT_004180b0);
      FUN_00407bb3(local_20,local_8,(int)local_3c,5,500,0xfc);
      wsprintfA(local_3c,&DAT_00412bf0,(&DAT_004126c8)[DAT_0041281c]);
      FUN_00407bb3(local_20,local_8,(int)local_3c,5,500,0xbd);
    }
    FUN_00402f1b(DAT_00417f60,0x129,DAT_00417d00,0x14,0x50,DAT_00418018,0,1);
    for (local_1c = 0; local_1c < 0x8c; local_1c = local_1c + 10) {
      FUN_00406483();
      FUN_00402f1b(DAT_00417f68,0x129,DAT_00417d00,0x14,10,DAT_00418018,0,0);
      FUN_00402f1b(DAT_00418018,0,0,0x14,0x5a,DAT_00417f60,0x129,DAT_00417d00);
      DVar5 = 0xcc0020;
      UVar4 = 1;
      pBVar3 = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(local_20,0x129,DAT_00417d00,0x14,0x5a,0x129,
                    (DAT_00417f60[2] - DAT_00417d00) + -0x5a,0x14,0x5a,DAT_00417f60 + uVar2 + 10,
                    pBVar3,UVar4,DVar5);
      DAT_00417d00 = DAT_00417d00 + 10;
      FUN_0040649e(10);
    }
    FUN_00402f1b(DAT_00417f60,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,
                 ((_DAT_00412828 - DAT_0041280c) * 4 + -4) * 5,0x50,DAT_00418018,0x14,0);
    if (0 < local_68) {
      FUN_004014f3(4);
    }
    for (local_1c = 0; local_1c < 0x14; local_1c = local_1c + 0x14) {
      FUN_00402f1b(DAT_00417f68,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,0x14,0x50,
                   DAT_00418018,0,0);
      iVar1 = DAT_0041282c;
      DAT_0041282c = DAT_0041282c + 0x14;
      FUN_00402f1b(DAT_00418018,0,0,((_DAT_00412828 - DAT_0041280c) * 4 + -4) * 5 + 0x14,0x50,
                   DAT_00417f60,iVar1 + (_DAT_00412828 * 4 + -4) * -5,0x25);
      DVar5 = 0xcc0020;
      UVar4 = 1;
      pBVar3 = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(local_20,DAT_0041282c + -0x14 + (_DAT_00412828 * 4 + -4) * -5,0x25,
                    ((_DAT_00412828 - DAT_0041280c) * 4 + -4) * 5 + 0x14,0x50,
                    DAT_0041282c + -0x14 + (_DAT_00412828 * 4 + -4) * -5,DAT_00417f60[2] + -0x75,
                    ((_DAT_00412828 - DAT_0041280c) * 4 + -4) * 5 + 0x14,0x50,
                    DAT_00417f60 + uVar2 + 10,pBVar3,UVar4,DVar5);
    }
    SelectObject(local_8,DAT_004180d8);
    FUN_0040657c(local_20,local_20,local_8,(char)DAT_0041281c,1);
    FUN_0040776e(local_20);
    _DAT_00412828 = _DAT_00412828 + -1;
    DAT_0041282c = DAT_0041282c + -0x14;
    local_48 = 0;
    if (local_68 != 0) {
      if (DAT_004180c4 < 0) {
        DAT_004127a0 = 1;
        FUN_004022d0();
        wsprintfA(local_3c,&DAT_00412bf8,0);
        FUN_00407bb3(local_20,local_8,(int)local_3c,2,0x65,0xfb);
        wsprintfA(local_3c,&DAT_00412bfc,DAT_004180b0);
        FUN_00407bb3(local_20,local_8,(int)local_3c,5,500,0xfc);
        FUN_004014f3(2);
        local_48 = FUN_004067ef();
      }
      else {
        wsprintfA(local_3c,&DAT_00412c04,DAT_004180c4);
        FUN_00407bb3(local_20,local_8,(int)local_3c,2,0x65,0xfb);
        if (DAT_004180b0 < 0) {
          DAT_004180b0 = 0;
        }
        wsprintfA(local_3c,&DAT_00412c08,DAT_004180b0);
        FUN_00407bb3(local_20,local_8,(int)local_3c,5,500,0xfc);
      }
    }
    DeleteDC(local_8);
    ReleaseDC(DAT_0041801c,local_20);
    if (_DAT_00412828 <= DAT_0041280c) {
      FUN_0040a135();
    }
    FUN_0040796d();
    if (local_48 == 0) {
      if (_DAT_00412828 == 0) {
        FUN_0040b0d4();
      }
      FUN_004080ae();
    }
    if (local_48 == 1) {
      if (DAT_00412254 != 0) {
        FUN_004037cf();
      }
      FUN_00401de5(DAT_004180b0);
      FUN_00401f29();
      DAT_00412968 = DAT_00417e1c;
      FUN_0040381e();
    }
  }
  return;
}


// ==== FUN_0040776e @ 0040776e

void __cdecl FUN_0040776e(HDC param_1)

{
  ushort uVar1;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_10;
  uint local_c;
  int local_8;
  
  local_c = (uint)(DAT_00412790 == 1);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      if (DAT_00412824 == local_8) {
        FUN_00402f1b(DAT_00417cd8,local_c * 0x14,
                     (char)(&DAT_00417db8)[local_10 + local_8 * 5 + DAT_0041281c * 0x14] * 0x14,0x14
                     ,0x14,DAT_00417f60,(local_8 * 4 + 4) * 5 + DAT_00412818,
                     (local_10 * 4 + 4) * 5 + 0x9d);
      }
      else {
        FUN_00402f1b(DAT_00418030,local_c * 0x14 + 0x1e1,
                     (char)(&DAT_00417db8)[local_10 + local_8 * 5 + DAT_0041281c * 0x14] * 0x14,0x14
                     ,0x14,DAT_00417f60,(local_8 * 4 + 4) * 5 + DAT_00412818,
                     (local_10 * 4 + 4) * 5 + 0x9d);
      }
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,(local_8 * 4 + 4) * 5 + DAT_00412818,(local_10 * 4 + 4) * 5 + 0x9d,0x14,
                    0x14,(local_8 * 4 + 4) * 5 + DAT_00412818,
                    (DAT_00417f60[2] - ((local_10 * 4 + 4) * 5 + 0x9d)) + -0x14,0x14,0x14,
                    DAT_00417f60 + uVar1 + 10,lpbmi,iUsage,rop);
    }
  }
  return;
}


// ==== FUN_0040796d @ 0040796d

void FUN_0040796d(void)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ h;
  
  hdc = GetDC(DAT_0041801c);
  hdc_00 = CreateCompatibleDC(hdc);
  h = SelectObject(hdc_00,DAT_004180d8);
  SelectPalette(hdc,DAT_00417f18,0);
  RealizePalette(hdc);
  FUN_00407a13(hdc);
  FUN_0040776e(hdc);
  SelectObject(hdc_00,h);
  DeleteDC(hdc_00);
  ReleaseDC(DAT_0041801c,hdc);
  return;
}


// ==== FUN_00407a13 @ 00407a13

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00407a13(HDC param_1)

{
  ushort uVar1;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_10 = (uint)(DAT_00412790 != 1);
  if (_DAT_00412828 != 0) {
    local_8 = DAT_0041282c;
    for (local_14 = 0; local_14 < _DAT_00412828; local_14 = local_14 + 1) {
      for (local_c = 0; local_c < 4; local_c = local_c + 1) {
        if (local_14 == DAT_0041280c) {
          FUN_00402f1b(DAT_00417cd8,local_10 * 0x14,
                       (char)(&DAT_00418038)[local_14 * 4 + local_c] * 0x14,0x14,0x14,DAT_00417f60,
                       local_8,local_c * 0x14 + 0x25);
        }
        else {
          FUN_00402f1b(DAT_00418030,local_10 * 0x14 + 0x1e1,
                       (char)(&DAT_00418038)[local_14 * 4 + local_c] * 0x14,0x14,0x14,DAT_00417f60,
                       local_8,local_c * 0x14 + 0x25);
        }
        rop = 0xcc0020;
        iUsage = 1;
        lpbmi = DAT_00417f6c;
        uVar1 = FUN_004023fc(DAT_00417f60);
        StretchDIBits(param_1,local_8,local_c * 0x14 + 0x25,0x14,0x14,local_8,
                      (DAT_00417f60[2] - (local_c * 0x14 + 0x25)) + -0x14,0x14,0x14,
                      DAT_00417f60 + uVar1 + 10,lpbmi,iUsage,rop);
      }
      local_8 = local_8 + -0x14;
    }
  }
  return;
}


// ==== FUN_00407bb3 @ 00407bb3

void __cdecl
FUN_00407bb3(HDC param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_8;
  
  for (local_8 = 0; local_8 < param_4; local_8 = local_8 + 1) {
    if ((*(char *)(local_8 + param_3) == ' ') || (*(char *)(local_8 + param_3) == '-')) {
      *(undefined1 *)(local_8 + param_3) = 0x30;
    }
    FUN_00402f1b(DAT_00417ce4,((int)*(char *)(local_8 + param_3) & 0xfU) * 0x12,0,0x12,0x19,
                 DAT_00417f60,param_5,param_6 + -1);
    rop = 0xcc0020;
    iUsage = 1;
    lpbmi = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(param_1,param_5,param_6 + -1,0x12,0x19,param_5,
                  (DAT_00417f60[2] - (param_6 + -1)) + -0x19,0x12,0x19,DAT_00417f60 + uVar1 + 10,
                  lpbmi,iUsage,rop);
    param_5 = param_5 + 0x12;
  }
  return;
}


// ==== FUN_00407cac @ 00407cac

void FUN_00407cac(void)

{
  int iVar1;
  CHAR local_20 [16];
  HDC local_10;
  HGDIOBJ local_c;
  HDC local_8;
  
  FUN_004014f3(6);
  local_10 = GetDC(DAT_0041801c);
  local_8 = CreateCompatibleDC(local_10);
  local_c = SelectObject(local_8,DAT_004180d8);
  SelectPalette(local_10,DAT_00417f18,0);
  RealizePalette(local_10);
  iVar1 = DAT_0041281c;
  DAT_00412820 = DAT_0041281c;
  if (DAT_0041281c == 3) {
    DAT_0041281c = 0;
  }
  else {
    DAT_0041281c = DAT_0041281c + 1;
  }
  while ((&DAT_00417db8)[DAT_0041281c * 0x14] == -1) {
    if (DAT_0041281c == 3) {
      DAT_0041281c = 0;
    }
    else {
      DAT_0041281c = DAT_0041281c + 1;
    }
  }
  FUN_0040657c(local_10,local_10,local_8,(char)iVar1,0);
  FUN_0040657c(local_10,local_10,local_8,(char)DAT_0041281c,1);
  wsprintfA(local_20,&DAT_00412c10,(&DAT_004126c8)[DAT_0041281c]);
  FUN_00407bb3(local_10,local_8,(int)local_20,5,500,0xbd);
  if (DAT_004127a0 != 1) {
    FUN_0040776e(local_10);
  }
  DeleteDC(local_8);
  ReleaseDC(DAT_0041801c,local_10);
  return;
}


// ==== FUN_00407e2e @ 00407e2e

void __cdecl FUN_00407e2e(char param_1)

{
  CHAR local_1c [16];
  HDC local_c;
  HDC local_8;
  
  if (((&DAT_00417db8)[param_1 * 0x14] != -1) && (param_1 != DAT_0041281c)) {
    FUN_004014f3(6);
    local_c = GetDC(DAT_0041801c);
    local_8 = CreateCompatibleDC(local_c);
    SelectObject(local_8,DAT_004180d8);
    SelectPalette(local_c,DAT_00417f18,0);
    RealizePalette(local_c);
    FUN_0040657c(local_c,local_c,local_8,(char)DAT_0041281c,0);
    DAT_00412820 = DAT_0041281c;
    FUN_0040657c(local_c,local_c,local_8,param_1,1);
    DAT_0041281c = (int)param_1;
    wsprintfA(local_1c,&DAT_00412c18,(&DAT_004126c8)[DAT_0041281c]);
    FUN_00407bb3(local_c,local_8,(int)local_1c,5,500,0xbd);
    FUN_0040776e(local_c);
    DeleteDC(local_8);
    ReleaseDC(DAT_0041801c,local_c);
  }
  return;
}


// ==== FUN_00407f77 @ 00407f77

void __cdecl FUN_00407f77(LPCSTR param_1)

{
  int *hMem;
  
  hMem = FUN_0040de82(param_1);
  if (hMem != (int *)0x0) {
    FUN_00402f1b(hMem,0,0,0x245,0x79,DAT_00417f68,0x10,0x10);
    FUN_00402f1b(hMem,0x2fb,0,0x14,0x16,DAT_00417f68,0x129,0x89);
    FUN_00402f1b(hMem,0x245,0,DAT_00412810 + 0x3e,DAT_00412810 + 1,DAT_00417f68,0xd8,0x9d);
    FUN_00402f1b(hMem,0,0,0x245,0x79,DAT_00417f60,0x10,0x10);
    FUN_00402f1b(hMem,0x2fb,0,0x14,0x16,DAT_00417f60,0x129,0x89);
    FUN_00402f1b(hMem,0x245,0,DAT_00412810 + 0x3e,DAT_00412810 + 1,DAT_00417f60,0xd8,0x9d);
    GlobalFree(hMem);
  }
  return;
}


// ==== FUN_004080ae @ 004080ae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004080ae(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  BITMAPINFO *pBVar4;
  UINT UVar5;
  DWORD DVar6;
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
  int local_44 [5];
  CHAR local_30 [16];
  int local_20;
  int local_1c;
  HDC local_18;
  int local_14;
  HDC local_10;
  HDC local_8;
  
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    local_44[local_14] = 0;
  }
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      switch((&DAT_00417db8)[local_14 + DAT_0041281c * 0x14 + local_1c * 5]) {
      case 1:
        local_44[1] = local_44[1] + 1;
        break;
      case 2:
        local_44[2] = local_44[2] + 1;
        break;
      case 3:
        local_44[3] = local_44[3] + 1;
        break;
      case 4:
        local_44[4] = local_44[4] + 1;
      }
    }
  }
  for (local_14 = 1; (local_14 < 5 && (local_44[local_14] != 0x10)); local_14 = local_14 + 1) {
  }
  if (local_14 != 5) {
    FUN_004014f3(3);
    local_18 = GetDC(DAT_0041801c);
    SelectPalette(local_18,DAT_00417f18,0);
    RealizePalette(local_18);
    local_8 = CreateCompatibleDC(local_18);
    SelectObject(local_8,DAT_004180d8);
    local_10 = CreateCompatibleDC(local_18);
    SelectObject(local_10,DAT_00418020);
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      local_44[local_14] = 0;
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
        switch((&DAT_00417db8)[local_14 + DAT_0041281c * 0x14 + local_1c * 5]) {
        case 1:
          local_44[0] = local_44[0] + 1;
          break;
        case 2:
          local_44[1] = local_44[1] + 1;
          break;
        case 3:
          local_44[2] = local_44[2] + 1;
          break;
        case 4:
          local_44[3] = local_44[3] + 1;
        }
      }
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    }
    DAT_004180b0 = DAT_004180b0 + (&DAT_004126c8)[DAT_0041281c];
    wsprintfA(local_30,&DAT_00412c20,DAT_004180b0);
    FUN_00407bb3(local_18,local_8,(int)local_30,5,500,0xfc);
    (&DAT_004126c8)[DAT_0041281c] = 0;
    wsprintfA(local_30,&DAT_00412c28,(&DAT_004126c8)[DAT_0041281c]);
    FUN_00407bb3(local_18,local_8,(int)local_30,5,500,0xbd);
    _DAT_004127a8 = _DAT_004127a8 + 1;
    wsprintfA(local_30,&DAT_00412c30,DAT_004127a4 + -1);
    FUN_00407bb3(local_18,local_8,(int)local_30,2,0x65,0xcd);
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
        FUN_00402f1b(DAT_00418030,(-(uint)(DAT_00412790 == 0) & 0xffffffec) + 0x1f5,
                     (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + local_14 * 5] * 0x14,
                     0x14,0x14,DAT_00418018,(local_14 * 4 + 4) * 5,(local_1c * 4 + 4) * 5 + 0x78);
      }
    }
    if (DAT_004127a4 == '\x01') {
      FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,0x78,0x78,DAT_00418018,0x78,0x78);
      for (local_14 = 1; local_14 < 100; local_14 = local_14 + 1) {
        FUN_00406483();
        FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
        DVar6 = 0xcc0020;
        UVar5 = 1;
        pBVar4 = DAT_00417f6c;
        uVar1 = FUN_004023fc(DAT_00417f60);
        StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                      (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10,
                      pBVar4,UVar5,DVar6);
        if (local_14 < 0x15) {
          local_4c = 0x50;
        }
        else {
          local_4c = 100 - local_14;
        }
        FUN_00402f1b(DAT_00418018,0x14,0x8c,0x50,local_4c,DAT_00417f60,DAT_00412818 + 0x14,
                     local_14 + 0xb1);
        if (local_14 < 0x15) {
          local_50 = 0x50;
          local_54 = 0x50;
          local_58 = 0x50;
        }
        else {
          local_50 = 100 - local_14;
          local_54 = 100 - local_14;
          local_58 = 100 - local_14;
        }
        DVar6 = 0xcc0020;
        UVar5 = 1;
        pBVar4 = DAT_00417f6c;
        uVar1 = FUN_004023fc(DAT_00417f60);
        StretchDIBits(local_18,DAT_00412818 + 0x14,local_14 + 0xb1,0x50,local_58,DAT_00412818 + 0x14
                      ,(DAT_00417f60[2] - (local_14 + 0xb1)) - local_54,0x50,local_50,
                      DAT_00417f60 + uVar1 + 10,pBVar4,UVar5,DVar6);
        if (local_14 < 0x50) {
          local_14 = local_14 + 9;
          FUN_0040649e(10);
        }
      }
      FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
      DVar6 = 0xcc0020;
      UVar5 = 1;
      pBVar4 = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                    (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10,
                    pBVar4,UVar5,DVar6);
      SelectObject(local_8,DAT_004180d8);
      DAT_004180c4 = DAT_004180c4 + 1;
      wsprintfA(local_30,&DAT_00412c34,DAT_004180c4);
      FUN_00407bb3(local_18,local_8,(int)local_30,2,0x65,0xfb);
      for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
        for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
          (&DAT_00417db8)[local_20 + DAT_0041281c * 0x14 + local_1c * 5] = 0;
        }
      }
      FUN_0040657c(local_18,local_18,local_8,(char)DAT_0041281c,1);
      DAT_0041281c = DAT_00412820;
      if (DAT_00412820 == 0) {
        DAT_00412820 = 3;
      }
      else {
        DAT_00412820 = DAT_00412820 + -1;
      }
      while ((&DAT_00417db8)[DAT_00412820 * 0x14] == -1) {
        if (DAT_00412820 == 0) {
          DAT_00412820 = 3;
        }
        else {
          DAT_00412820 = DAT_00412820 + -1;
        }
      }
      DAT_00412800 = DAT_00412800 + 1;
      uVar3 = (int)DAT_00412800 >> 0x1f;
      FUN_00407f77((LPCSTR)((((DAT_00412800 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3) + 0x65));
      iVar2 = FUN_00409238(DAT_00412800);
      DAT_004127a4 = (char)iVar2;
      SelectObject(local_8,DAT_00417dac);
      FUN_00409a80(local_18,local_8);
      SelectObject(local_8,DAT_004180d8);
      FUN_00409275(local_18,local_8);
      DAT_004127a4 = DAT_004127a4 + '\x01';
    }
    else {
      FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,0x78,0x78,DAT_00418018,0x78,0x78);
      for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          FUN_00402f1b(DAT_00418030,(-(uint)(DAT_00412790 == 0) & 0xffffffec) + 0x1f5,
                       (char)(&DAT_00417db8)[local_1c + DAT_00412820 * 0x14 + local_14 * 5] * 0x14,
                       0x14,0x14,DAT_00418018,(local_14 * 4 + 4) * 5 + 0x78,
                       (local_1c * 4 + 4) * 5 + 0x78);
        }
      }
      if (DAT_004127a4 < '\x04') {
        for (local_14 = 1; local_14 < 100; local_14 = local_14 + 1) {
          FUN_00406483();
          FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
          DVar6 = 0xcc0020;
          UVar5 = 1;
          pBVar4 = DAT_00417f6c;
          uVar1 = FUN_004023fc(DAT_00417f60);
          StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                        (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10
                        ,pBVar4,UVar5,DVar6);
          if (local_14 < 0x15) {
            local_5c = 0x50;
          }
          else {
            local_5c = 100 - local_14;
          }
          FUN_00402f1b(DAT_00418018,0x14,0x8c,0x50,local_5c,DAT_00417f60,DAT_00412818 + 0x14,
                       local_14 + 0xb1);
          if (local_14 < 0x15) {
            local_60 = 0x50;
            local_64 = 0x50;
            local_68 = 0x50;
          }
          else {
            local_60 = 100 - local_14;
            local_64 = 100 - local_14;
            local_68 = 100 - local_14;
          }
          DVar6 = 0xcc0020;
          UVar5 = 1;
          pBVar4 = DAT_00417f6c;
          uVar1 = FUN_004023fc(DAT_00417f60);
          StretchDIBits(local_18,DAT_00412818 + 0x14,local_14 + 0xb1,0x50,local_68,
                        DAT_00412818 + 0x14,(DAT_00417f60[2] - (local_14 + 0xb1)) - local_64,0x50,
                        local_60,DAT_00417f60 + uVar1 + 10,pBVar4,UVar5,DVar6);
          if (local_14 < 0x50) {
            local_14 = local_14 + 9;
            FUN_0040649e(10);
          }
        }
        FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
        DVar6 = 0xcc0020;
        UVar5 = 1;
        pBVar4 = DAT_00417f6c;
        uVar1 = FUN_004023fc(DAT_00417f60);
        StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                      (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10,
                      pBVar4,UVar5,DVar6);
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
            (&DAT_00417db8)[local_20 + DAT_0041281c * 0x14 + local_1c * 5] = 0;
          }
        }
        SelectObject(local_8,DAT_004180d8);
        FUN_0040657c(local_18,local_18,local_8,(char)DAT_0041281c,0);
        DAT_0041281c = DAT_00412820;
        FUN_0040657c(local_18,local_18,local_8,(char)DAT_00412820,1);
        if (DAT_00412820 == 0) {
          DAT_00412820 = 3;
        }
        else {
          DAT_00412820 = DAT_00412820 + -1;
        }
        while ((&DAT_00417db8)[DAT_00412820 * 0x14] == -1) {
          if (DAT_00412820 == 0) {
            DAT_00412820 = 3;
          }
          else {
            DAT_00412820 = DAT_00412820 + -1;
          }
        }
      }
      else {
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
            (&DAT_00417db8)[local_20 + DAT_0041281c * 0x14 + local_1c * 5] = 0;
          }
        }
        for (local_14 = 1; local_14 < 100; local_14 = local_14 + 1) {
          FUN_00406483();
          FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
          DVar6 = 0xcc0020;
          UVar5 = 1;
          pBVar4 = DAT_00417f6c;
          uVar1 = FUN_004023fc(DAT_00417f60);
          StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                        (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10
                        ,pBVar4,UVar5,DVar6);
          if (local_14 < 0x15) {
            local_6c = 0x50;
          }
          else {
            local_6c = 100 - local_14;
          }
          FUN_00402f1b(DAT_00418018,0x14,0x8c,0x50,local_6c,DAT_00417f60,DAT_00412818 + 0x14,
                       local_14 + 0xb1);
          if (local_14 < 0x15) {
            local_70 = 0x50;
            local_74 = 0x50;
            local_78 = 0x50;
          }
          else {
            local_70 = 100 - local_14;
            local_74 = 100 - local_14;
            local_78 = 100 - local_14;
          }
          DVar6 = 0xcc0020;
          UVar5 = 1;
          pBVar4 = DAT_00417f6c;
          uVar1 = FUN_004023fc(DAT_00417f60);
          StretchDIBits(local_18,DAT_00412818 + 0x14,local_14 + 0xb1,0x50,local_78,
                        DAT_00412818 + 0x14,(DAT_00417f60[2] - (local_14 + 0xb1)) - local_74,0x50,
                        local_70,DAT_00417f60 + uVar1 + 10,pBVar4,UVar5,DVar6);
          if (local_14 < 0x50) {
            local_14 = local_14 + 9;
            FUN_0040649e(10);
          }
        }
        FUN_00402f1b(DAT_00418018,0x8c,0x8c,0x50,local_14,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
        DVar6 = 0xcc0020;
        UVar5 = 1;
        pBVar4 = DAT_00417f6c;
        uVar1 = FUN_004023fc(DAT_00417f60);
        StretchDIBits(local_18,DAT_00412818 + 0x14,0xb1,0x50,local_14,DAT_00412818 + 0x14,
                      (DAT_00417f60[2] + -0xb1) - local_14,0x50,local_14,DAT_00417f60 + uVar1 + 10,
                      pBVar4,UVar5,DVar6);
        SelectObject(local_8,DAT_004180d8);
        FUN_0040657c(local_18,local_18,local_8,(char)DAT_0041281c,0);
        iVar2 = DAT_00412820;
        DAT_0041281c = DAT_00412820;
        if (DAT_00412820 == 0) {
          DAT_00412820 = 3;
        }
        else {
          DAT_00412820 = DAT_00412820 + -1;
        }
        while ((&DAT_00417db8)[DAT_00412820 * 0x14] == -1) {
          if (DAT_00412820 == 0) {
            DAT_00412820 = 3;
          }
          else {
            DAT_00412820 = DAT_00412820 + -1;
          }
        }
        FUN_0040657c(local_18,local_18,local_8,(char)iVar2,1);
      }
    }
    wsprintfA(local_30,&DAT_00412c38,(&DAT_004126c8)[DAT_0041281c]);
    FUN_00407bb3(local_18,local_8,(int)local_30,5,500,0xbd);
    DeleteDC(local_10);
    DeleteDC(local_8);
    ReleaseDC(DAT_0041801c,local_18);
    DAT_004127a4 = DAT_004127a4 + -1;
    if (DAT_00412790 == 0) {
      PostMessageA(DAT_0041801c,0x100,0x28,0);
    }
    else {
      PostMessageA(DAT_0041801c,0x100,0x26,0);
    }
  }
  return;
}


// ==== FUN_00409238 @ 00409238

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00409238(int param_1)

{
  int iVar1;
  
  if (param_1 < 2) {
    _DAT_00412804 = FUN_0040229f(4);
    _DAT_00412804 = _DAT_00412804 + 1;
  }
  iVar1 = param_1 + -10;
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  return iVar1 + 3;
}


// ==== FUN_00409275 @ 00409275

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00409275(HDC param_1,HDC param_2)

{
  int iVar1;
  CHAR local_10 [4];
  int local_c;
  HGDIOBJ local_8;
  
  iVar1 = FUN_00409238(DAT_00412800);
  DAT_004127a4 = (char)iVar1;
  _DAT_004127a8 = 0;
  wsprintfA(local_10,&DAT_00412c40,(int)DAT_004127a4);
  local_8 = SelectObject(param_2,DAT_004180d8);
  FUN_00407bb3(param_1,param_2,(int)local_10,2,0x65,0xcd);
  DAT_004127a0 = 0;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    iVar1 = FUN_00409344(DAT_00412800);
    FUN_004098ab(param_1,param_2,iVar1);
  }
  SelectObject(param_2,local_8);
  return;
}


// ==== FUN_00409344 @ 00409344

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00409344(int param_1)

{
  int iVar1;
  int iVar2;
  char local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (_DAT_00412828 == 0) {
    DAT_0041282c = 0x129;
    DAT_0041280c = 0;
  }
  if (_DAT_00412828 == 0x1b) {
    local_10 = 1;
  }
  else {
    if (DAT_0041280c < _DAT_00412828 / 2) {
      local_10 = 0;
      for (local_18 = _DAT_00412828; 0 < local_18; local_18 = local_18 + -1) {
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          (&DAT_00418038)[local_18 * 4 + local_14] =
               *(undefined1 *)((int)&DAT_00418034 + local_18 * 4 + local_14);
        }
      }
      local_20 = '\0';
    }
    else {
      local_10 = 1;
      local_20 = DAT_00412828;
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      iVar1 = FUN_0040229f(2);
      (&DAT_00418038)[local_20 * 4 + local_14] = (char)iVar1;
    }
    while (((((&DAT_00418038)[local_20 * 4] == '\0' && ((&DAT_00418039)[local_20 * 4] == '\0')) &&
            ((&DAT_0041803a)[local_20 * 4] == '\0')) && ((&DAT_0041803b)[local_20 * 4] == '\0'))) {
      for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
        iVar1 = FUN_0040229f(2);
        (&DAT_00418038)[local_20 * 4 + local_14] = (char)iVar1;
      }
    }
    if (param_1 < 4) {
      local_8 = FUN_0040229f(param_1);
    }
    else {
      local_8 = FUN_0040229f(4);
    }
    local_8 = local_8 + 1;
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      if ((&DAT_00418038)[local_20 * 4 + local_14] == '\0') {
        (&DAT_00418038)[local_20 * 4 + local_14] = 0;
      }
      else {
        (&DAT_00418038)[local_20 * 4 + local_14] = (undefined1)local_8;
      }
    }
    if (4 < param_1) {
      if (6 < param_1) {
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          if (((&DAT_00418038)[local_20 * 4 + local_14] != '\0') &&
             (iVar1 = FUN_0040229f(0x10), iVar1 == 4)) {
            while ((char)(&DAT_00418038)[local_20 * 4 + local_14] == local_8) {
              iVar1 = FUN_0040229f(4);
              (&DAT_00418038)[local_20 * 4 + local_14] = (char)iVar1 + '\x01';
            }
          }
        }
      }
      if (param_1 == 5) {
        iVar1 = FUN_0040229f(8);
        if (iVar1 == 4) {
          for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
            (&DAT_00418038)[local_20 * 4 + local_14] = 0;
          }
          iVar1 = FUN_0040229f(4);
          iVar2 = FUN_0040229f(2);
          (&DAT_00418038)[local_20 * 4 + iVar1] = (char)iVar2 + '\x04';
        }
      }
      else if (5 < param_1) {
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          if (((&DAT_00418038)[local_20 * 4 + local_14] != '\0') &&
             (iVar1 = FUN_0040229f(0x10), iVar1 == 6)) {
            while ((char)(&DAT_00418038)[local_20 * 4 + local_14] == local_8) {
              (&DAT_00418038)[local_20 * 4 + local_14] = 5;
            }
          }
        }
        if (param_1 == 6) {
          iVar1 = FUN_0040229f(8);
          if (iVar1 == 4) {
            for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
              (&DAT_00418038)[local_20 * 4 + local_14] = 0;
            }
            iVar1 = FUN_0040229f(4);
            (&DAT_00418038)[local_20 * 4 + iVar1] = 6;
          }
        }
        else if (6 < param_1) {
          for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
            if (((&DAT_00418038)[local_20 * 4 + local_14] != '\0') &&
               (iVar1 = FUN_0040229f(0x10), iVar1 == 6)) {
              while ((char)(&DAT_00418038)[local_20 * 4 + local_14] == local_8) {
                (&DAT_00418038)[local_20 * 4 + local_14] = 6;
              }
            }
          }
        }
      }
    }
    if (local_10 == 1) {
      DAT_00417cf8 = DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5 + -0x14;
    }
    else {
      DAT_0041282c = DAT_0041282c + 0x14;
      DAT_00417cf8 = DAT_0041282c;
    }
    _DAT_00417ce0 = 0;
    _DAT_004180d0 = 1;
    if (DAT_0041224c != 0) {
      for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
        if (((&DAT_00418038)[local_20 * 4 + local_14] == '\x05') ||
           ((&DAT_00418038)[local_20 * 4 + local_14] == '\x06')) {
          FUN_00403647((int)(char)(&DAT_00418038)[local_20 * 4 + local_14]);
        }
      }
    }
  }
  return local_10;
}


// ==== FUN_004098ab @ 004098ab

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004098ab(HDC param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  char local_18;
  int local_14;
  
  if (_DAT_00412828 != 0x1b) {
    if (param_3 == 1) {
      local_18 = DAT_00412828;
    }
    else {
      local_18 = '\0';
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      FUN_00402f1b(DAT_00418030,0x1e1,(char)(&DAT_00418038)[local_18 * 4 + local_14] * 0x14,0x14,
                   0x14,DAT_00418018,0,local_14 * 0x14 + 0x14);
    }
    for (local_14 = 1; local_14 < 0x65; local_14 = local_14 + 1) {
      FUN_00406483();
      if (0x50 < local_14) {
        FUN_00402f1b(DAT_00417f68,DAT_00417cf8,0x11,0x14,local_14 + -0x50,DAT_00418018,0,
                     0x14 - (local_14 + -0x50));
      }
      FUN_00402f1b(DAT_00418018,0,100 - local_14,0x14,local_14,DAT_00417f60,DAT_00417cf8,0x11);
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar1 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(param_1,DAT_00417cf8,0x11,0x14,local_14,DAT_00417cf8,
                    (DAT_00417f60[2] + -0x11) - local_14,0x14,local_14,DAT_00417f60 + uVar1 + 10,
                    lpbmi,iUsage,rop);
      if (local_14 < 0x50) {
        local_14 = local_14 + 0x13;
        FUN_0040649e(10);
      }
    }
    _DAT_00412828 = _DAT_00412828 + 1;
    if (param_3 == 0) {
      DAT_0041280c = DAT_0041280c + 1;
    }
    _DAT_004180d0 = 0;
    FUN_00407a13(param_1);
  }
  return;
}


// ==== FUN_00409a80 @ 00409a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00409a80(HDC param_1,HDC param_2)

{
  ushort uVar1;
  BITMAPINFO *pBVar2;
  UINT UVar3;
  DWORD DVar4;
  CHAR local_28 [24];
  int local_10;
  
  FUN_00402f1b(DAT_00417f68,0x11,0x11,0x244,0x78,DAT_00417f60,0x11,0x11);
  DVar4 = 0xcc0020;
  UVar3 = 1;
  pBVar2 = DAT_00417f6c;
  uVar1 = FUN_004023fc(DAT_00417f60);
  StretchDIBits(param_1,0x10,0x10,0x245,0x79,0x10,DAT_00417f60[2] + -0x89,0x245,0x79,
                DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
  DVar4 = 0xcc0020;
  UVar3 = 1;
  pBVar2 = DAT_00417f6c;
  uVar1 = FUN_004023fc(DAT_00417f60);
  StretchDIBits(param_1,0x129,0x89,0x14,0x16,0x129,DAT_00417f60[2] + -0x9f,0x14,0x16,
                DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
  _DAT_00412828 = 0;
  DAT_00412814 = 0;
  DAT_00412818 = 0x115;
  DAT_0041282c = 0x129;
  DAT_0041281c = 0;
  DAT_00412820 = 3;
  DAT_0041280c = 0;
  DAT_00412824 = 0;
  FUN_00402f1b(DAT_00417f68,0xed,0x9d,DAT_00412810 + 0x28,DAT_00412810,DAT_00417f60,0xed,0x9d);
  FUN_00402fa2(DAT_00418030,0,((uint)(DAT_00412790 == 0) * -8 + 8) * 0xf,DAT_00412810,DAT_00412810,
               DAT_00417f60,DAT_00412818,0x9d,0);
  DVar4 = 0xcc0020;
  UVar3 = 1;
  pBVar2 = DAT_00417f6c;
  uVar1 = FUN_004023fc(DAT_00417f60);
  StretchDIBits(param_1,DAT_00412818 + -0x3d,0x9d,DAT_00412810 + 0x3e,DAT_00412810 + 1,
                DAT_00412818 + -0x3d,(DAT_00417f60[2] + -0x9d) - (DAT_00412810 + 1),
                DAT_00412810 + 0x3e,DAT_00412810 + 1,DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
  SelectObject(param_2,DAT_004180d8);
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    FUN_0040657c(param_1,param_1,param_2,(char)local_10,(uint)(DAT_0041281c == local_10));
  }
  FUN_0040776e(param_1);
  wsprintfA(local_28,&DAT_00412c44,DAT_00412800);
  FUN_00407bb3(param_1,param_2,(int)local_28,2,0x65,0x9f);
  wsprintfA(local_28,&DAT_00412c48,DAT_004180c4);
  FUN_00407bb3(param_1,param_2,(int)local_28,2,0x65,0xfb);
  wsprintfA(local_28,&DAT_00412c4c,(int)DAT_004127a4);
  FUN_00407bb3(param_1,param_2,(int)local_28,2,0x65,0xcd);
  wsprintfA(local_28,&DAT_00412c50,DAT_004180b0);
  FUN_00407bb3(param_1,param_2,(int)local_28,5,500,0xfc);
  wsprintfA(local_28,&DAT_00412c58,(&DAT_004126c8)[DAT_0041281c]);
  FUN_00407bb3(param_1,param_2,(int)local_28,5,500,0xbd);
  return;
}


// ==== FUN_00409e3d @ 00409e3d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409e3d(void)

{
  int iVar1;
  ushort uVar2;
  HDC hdc;
  int iVar3;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_18;
  
  if ((DAT_0041282c < 0x22e) && (DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5 < 0x116)) {
    FUN_004014f3(6);
    hdc = GetDC(DAT_0041801c);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    iVar1 = DAT_0041280c;
    iVar3 = DAT_0041282c + DAT_0041280c * -0x14;
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00418030,0x1e1,(char)(&DAT_00418038)[iVar1 * 4 + local_18] * 0x14,0x14,0x14,
                   DAT_00417f60,iVar3,local_18 * 0x14 + 0x25);
    }
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00417cd8,0,(char)(&DAT_00418038)[(iVar1 + 1) * 4 + local_18] * 0x14,0x14,0x14
                   ,DAT_00417f60,iVar3 + -0x14,local_18 * 0x14 + 0x25);
    }
    FUN_00402f1b(DAT_00417f60,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,_DAT_00412828 * 0x14
                 ,0x50,DAT_00418018,0x14,0);
    FUN_00402f1b(DAT_00417f68,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,0x14,0x50,
                 DAT_00418018,0,0);
    for (local_18 = 0; iVar1 = DAT_0041282c, local_18 < 0x14; local_18 = local_18 + 0x14) {
      DAT_0041282c = DAT_0041282c + 0x14;
      FUN_00402f1b(DAT_00418018,0,0,_DAT_00412828 * 0x14 + 0x14,0x50,DAT_00417f60,
                   iVar1 + (_DAT_00412828 * 4 + -4) * -5,0x25);
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(hdc,DAT_0041282c + -0x14 + (_DAT_00412828 * 4 + -4) * -5,0x25,
                    _DAT_00412828 * 0x14 + 0x14,0x50,
                    DAT_0041282c + -0x14 + (_DAT_00412828 * 4 + -4) * -5,DAT_00417f60[2] + -0x75,
                    _DAT_00412828 * 0x14 + 0x14,0x50,DAT_00417f60 + uVar2 + 10,lpbmi,iUsage,rop);
    }
    ReleaseDC(DAT_0041801c,hdc);
    DAT_0041280c = DAT_0041280c + 1;
  }
  return;
}


// ==== FUN_0040a135 @ 0040a135

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040a135(void)

{
  int iVar1;
  ushort uVar2;
  HDC hdc;
  int iVar3;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_18;
  
  if ((0x11 < DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5) && (0x13c < DAT_0041282c)) {
    FUN_004014f3(6);
    hdc = GetDC(DAT_0041801c);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    iVar1 = DAT_0041280c;
    iVar3 = DAT_0041282c + DAT_0041280c * -0x14;
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00418030,0x1e1,(char)(&DAT_00418038)[iVar1 * 4 + local_18] * 0x14,0x14,0x14,
                   DAT_00417f60,iVar3,local_18 * 0x14 + 0x25);
    }
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00417cd8,0,(char)(&DAT_00418038)[(iVar1 + -1) * 4 + local_18] * 0x14,0x14,
                   0x14,DAT_00417f60,iVar3 + 0x14,local_18 * 0x14 + 0x25);
    }
    FUN_00402f1b(DAT_00417f60,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,_DAT_00412828 * 0x14
                 ,0x50,DAT_00418018,0,0);
    FUN_00402f1b(DAT_00417f68,DAT_0041282c,0x25,0x14,0x50,DAT_00418018,_DAT_00412828 * 0x14,0);
    for (local_18 = 0; local_18 < 0x14; local_18 = local_18 + 0x14) {
      DAT_0041282c = DAT_0041282c + -0x14;
      FUN_00402f1b(DAT_00418018,0,0,_DAT_00412828 * 0x14 + 0x14,0x50,DAT_00417f60,
                   DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25);
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(hdc,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,0x25,
                    _DAT_00412828 * 0x14 + 0x14,0x50,DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5,
                    DAT_00417f60[2] + -0x75,_DAT_00412828 * 0x14 + 0x14,0x50,
                    DAT_00417f60 + uVar2 + 10,lpbmi,iUsage,rop);
    }
    ReleaseDC(DAT_0041801c,hdc);
    DAT_0041280c = DAT_0041280c + -1;
  }
  return;
}


// ==== FUN_0040a415 @ 0040a415

void FUN_0040a415(void)

{
  int iVar1;
  ushort uVar2;
  HDC hdc;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_1c;
  int local_14;
  
  hdc = GetDC(DAT_0041801c);
  if (DAT_00412818 != 0x115) {
    FUN_004014f3(6);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    iVar1 = DAT_00412824;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      FUN_00402f1b(DAT_00418030,0x1e1,
                   (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + iVar1 * 5] * 0x14,0x14,
                   0x14,DAT_00417f60,(iVar1 * 4 + 4) * 5 + DAT_00412818,
                   (local_1c * 4 + 4) * 5 + 0x9d);
    }
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      FUN_00402f1b(DAT_00417cd8,0,
                   (char)(&DAT_00417db8)[local_1c + DAT_0041281c * 0x14 + (iVar1 + -1) * 5] * 0x14,
                   0x14,0x14,DAT_00417f60,((iVar1 + -1) * 4 + 4) * 5 + DAT_00412818,
                   (local_1c * 4 + 4) * 5 + 0x9d);
    }
    FUN_00402f1b(DAT_00417f60,DAT_00412818 + 0x14,0xb1,0x50,0x50,DAT_00418018,2,0);
    for (local_14 = 0; local_14 < 0x14; local_14 = local_14 + 2) {
      FUN_00402f1b(DAT_00417f68,DAT_00412818 + 0x14,0xb1,2,0x50,DAT_00418018,0,0);
      FUN_00402f1b(DAT_00418018,0,0,0x52,0x50,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(hdc,DAT_00412818 + 0x14,0xb1,0x52,0x50,DAT_00412818 + 0x14,
                    DAT_00417f60[2] + -0x101,0x52,0x50,DAT_00417f60 + uVar2 + 10,lpbmi,iUsage,rop);
      DAT_00412818 = DAT_00412818 + 2;
    }
    DAT_00412824 = DAT_00412824 + -1;
  }
  ReleaseDC(DAT_0041801c,hdc);
  return;
}


// ==== FUN_0040a6a0 @ 0040a6a0

void FUN_0040a6a0(void)

{
  int iVar1;
  ushort uVar2;
  HDC hdc;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD rop;
  int local_18;
  int local_10;
  
  hdc = GetDC(DAT_0041801c);
  if (DAT_00412818 != 0xd9) {
    FUN_004014f3(6);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    iVar1 = DAT_00412824;
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00418030,0x1e1,
                   (char)(&DAT_00417db8)[local_18 + iVar1 * 5 + DAT_0041281c * 0x14] * 0x14,0x14,
                   0x14,DAT_00417f60,(iVar1 * 4 + 4) * 5 + DAT_00412818,
                   (local_18 * 4 + 4) * 5 + 0x9d);
    }
    iVar1 = DAT_00412824 + 1;
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      FUN_00402f1b(DAT_00417cd8,0,
                   (char)(&DAT_00417db8)[local_18 + iVar1 * 5 + DAT_0041281c * 0x14] * 0x14,0x14,
                   0x14,DAT_00417f60,(iVar1 * 4 + 4) * 5 + DAT_00412818,
                   (local_18 * 4 + 4) * 5 + 0x9d);
    }
    FUN_00402f1b(DAT_00417f60,DAT_00412818 + 0x14,0xb1,0x50,0x50,DAT_00418018,0,0);
    for (local_10 = 0; iVar1 = DAT_00412818, local_10 < 0x14; local_10 = local_10 + 2) {
      DAT_00412818 = DAT_00412818 + -2;
      FUN_00402f1b(DAT_00417f68,iVar1 + 0x62,0xb1,2,0x50,DAT_00418018,0x50,0);
      FUN_00402f1b(DAT_00418018,0,0,0x52,0x50,DAT_00417f60,DAT_00412818 + 0x14,0xb1);
      rop = 0xcc0020;
      iUsage = 1;
      lpbmi = DAT_00417f6c;
      uVar2 = FUN_004023fc(DAT_00417f60);
      StretchDIBits(hdc,DAT_00412818 + 0x14,0xb1,0x52,0x50,DAT_00412818 + 0x14,
                    DAT_00417f60[2] + -0x101,0x52,0x50,DAT_00417f60 + uVar2 + 10,lpbmi,iUsage,rop);
    }
    DAT_00412824 = DAT_00412824 + 1;
  }
  ReleaseDC(DAT_0041801c,hdc);
  return;
}


// ==== FUN_0040a938 @ 0040a938

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040a938(HWND param_1)

{
  if (DAT_00412814 == 0) {
    FUN_004014f3(5);
    DAT_00412814 = 0;
    _DAT_00418014 = SetTimer(param_1,1,0x32,DAT_00417cf4);
  }
  return;
}


// ==== FUN_0040a987 @ 0040a987

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040a987(HWND param_1)

{
  if (DAT_00412814 == 0) {
    FUN_004014f3(5);
    DAT_00412814 = 0;
    _DAT_00418014 = SetTimer(param_1,5,0x32,DAT_00417ce8);
  }
  return;
}


// ==== FUN_0040a9d6 @ 0040a9d6

void FUN_0040a9d6(void)

{
  tagPOINT local_20;
  int local_18;
  int local_14;
  
  if (DAT_004123b8 != 1) {
    if (DAT_004123b4 != 0) {
      FUN_004013d5();
    }
    if ((((DAT_004123c0 == 0) && (DAT_004123c4 == 0)) && (DAT_004123bc == 0)) &&
       (((DAT_004123b4 != 0 && (DAT_004123a0 != 0)) &&
        ((DAT_004123a4 = DAT_004123a4 + 1, 3 < DAT_004123a4 || (0 < DAT_004123a8)))))) {
      DAT_004123a4 = 0;
      DAT_004123a8 = 1;
      GetCursorPos(&local_20);
      ScreenToClient(DAT_004181b8,&local_20);
      local_14 = local_20.x;
      local_18 = local_20.y;
      switch(DAT_004123a0) {
      case 1:
        if (((0x10 < local_20.y) && (local_20.y < 0x8a)) && (local_20.x < 0x129)) {
          FUN_0040a135();
        }
        break;
      case 2:
        if (((0x10 < local_20.y) && (local_20.y < 0x8a)) && (0x13d < local_20.x)) {
          FUN_00409e3d();
        }
        break;
      case 3:
        if ((((0x9c < local_20.y) && (local_20.y < 0x116)) && (0xd8 < local_20.x)) &&
           ((local_20.x < 0x129 && (DAT_00412814 == 0)))) {
          FUN_0040a6a0();
        }
        break;
      case 4:
        if (((0x9c < local_20.y) && (local_20.y < 0x116)) &&
           ((local_20.x < 0x18e && ((0x13d < local_20.x && (DAT_00412814 == 0)))))) {
          FUN_0040a415();
        }
        break;
      case 5:
        if ((((0xb0 < local_20.y) && (local_20.y < 0x102)) && (DAT_00412818 + 0x14 <= local_20.x))
           && ((local_20.x <= DAT_00412818 + 100 && (DAT_00412814 == 0)))) {
          FUN_0040a938(DAT_0041801c);
        }
        break;
      case 6:
        if (((0xb0 < local_20.y) && (local_20.y < 0x102)) &&
           ((DAT_00412818 + 0x14 <= local_20.x &&
            ((local_20.x <= DAT_00412818 + 100 && (DAT_00412814 == 0)))))) {
          FUN_0040a987(DAT_0041801c);
        }
      }
    }
  }
  return;
}


// ==== FUN_0040b0d4 @ 0040b0d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b0d4(void)

{
  HDC hdc;
  HDC hdc_00;
  int iVar1;
  
  if (_DAT_00412828 < 0x19) {
    if ((_DAT_00412828 < 0x1b) && (0x18 < _DAT_00412828)) {
      FUN_004014f3(7);
    }
    else {
      FUN_004014f3(8);
    }
    hdc = GetDC(DAT_0041801c);
    hdc_00 = CreateCompatibleDC(hdc);
    SelectObject(hdc_00,DAT_004180d8);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    iVar1 = FUN_00409344(DAT_00412800);
    FUN_004098ab(hdc,hdc_00,iVar1);
    FUN_00407a13(hdc);
    DeleteDC(hdc_00);
    ReleaseDC(DAT_0041801c,hdc);
    DAT_00417cf8 = 0xfffffffd;
    _DAT_00417ce0 = 0;
    _DAT_004180d0 = 1;
  }
  return;
}


// ==== FUN_0040b1db @ 0040b1db

void FUN_0040b1db(void)

{
  return;
}


// ==== FUN_0040b1eb @ 0040b1eb

void __cdecl FUN_0040b1eb(HDC param_1,HDC param_2,int param_3)

{
  HGDIOBJ h;
  
  if (param_3 == 1) {
    h = SelectObject(param_2,DAT_004180d8);
    BitBlt(param_1,8,0x95,0x87,0x87,param_2,0x28,0,0xcc0020);
    SelectObject(param_2,h);
  }
  else {
    BitBlt(param_1,8,0x95,0x87,0x87,param_2,8,0x95,0xcc0020);
  }
  return;
}


// ==== FUN_0040b281 @ 0040b281

/* WARNING: Removing unreachable block (ram,0x0040c5f6) */
/* WARNING: Removing unreachable block (ram,0x0040c4fd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0040b281(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  HGLOBAL pvVar1;
  int iVar2;
  INT_PTR IVar3;
  LRESULT LVar4;
  uint uVar5;
  int local_80;
  tagPAINTSTRUCT local_7c;
  uint local_3c;
  int local_38;
  HDC local_34;
  int local_30;
  RECT local_2c;
  int local_1c;
  HGDIOBJ local_18;
  HDC local_c;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_34 = BeginPaint(param_1,&local_7c);
      FUN_004026df(local_34);
      if (DAT_004126e8 == 1) {
        EndPaint(param_1,&local_7c);
        DAT_004126e8 = 0;
        PostMessageA(param_1,0x301,0,0);
        return 0;
      }
      if (DAT_004126d8 != 0) {
        if (DAT_004123ac == 1) {
          DAT_004123ac = 0;
          _DAT_00417e08 = 0;
          DAT_00417ec8 = 0;
          _DAT_00417ecc = 0;
          DAT_00418008 = 0;
          DAT_00417f70 = 0;
          DAT_004180cc = 0;
          DAT_00417ed8 = 0;
          DAT_00417f5c = 5;
          DAT_00417f74 = 6;
          DAT_00417ee4 = 1;
          DAT_00417edc = 1;
          _DAT_00417f64 = SetTimer(param_1,3,100,DAT_004180c0);
        }
        EndPaint(param_1,&local_7c);
        return 0;
      }
      EndPaint(param_1,&local_7c);
      return 0;
    }
    if (param_2 == 2) {
LAB_0040c623:
      FUN_00401f29();
      FUN_004011f5(0);
      FUN_00401605();
      KillTimer(param_1,1);
      KillTimer(param_1,2);
      KillTimer(param_1,3);
      return 0;
    }
switchD_0040c72d_caseD_203:
    LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
    return LVar4;
  }
  if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      DAT_004123a0 = 0;
      DAT_004123a8 = 0;
      if (param_3 == 0x1b) {
        ShowWindow(DAT_004181b8,6);
        return 0;
      }
      if (DAT_004127a0 == 1) {
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        return 0;
      }
      if (DAT_004123b8 == 1) {
        PostMessageA(DAT_004181b8,0x111,0xc9,0);
        return 0;
      }
      if (param_3 == 0x2d) {
        FUN_0040b0d4();
        return 0;
      }
      if (DAT_004127b4 == param_3) {
        if (DAT_00412790 == 1) {
          FUN_00409e3d();
          return 0;
        }
        if (DAT_00412814 != 0) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        FUN_0040a415();
        return 0;
      }
      if (DAT_004127b0 == param_3) {
        if (DAT_00412814 != 0) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (DAT_00412790 == 1) {
          FUN_0040a135();
          return 0;
        }
        FUN_0040a6a0();
        return 0;
      }
      if (DAT_00412814 != 0) {
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        return 0;
      }
      if (DAT_004127d0 == param_3) {
        DAT_00412790 = 1;
        FUN_0040796d();
        return 0;
      }
      if (DAT_004127d4 == param_3) {
        DAT_00412790 = 0;
        FUN_0040796d();
        return 0;
      }
      if ((DAT_004127c4 != param_3) && (param_3 != 0xc)) {
        if (param_3 == 8) {
          _DAT_004126dc = 0;
          FUN_0040a987(DAT_0041801c);
          return 0;
        }
        if (DAT_004127c8 == param_3) {
          FUN_004080ae();
          return 0;
        }
        if (DAT_004127b8 == param_3) {
          FUN_00406959();
          return 0;
        }
        if (DAT_004127cc != param_3) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        FUN_00407cac();
        return 0;
      }
      _DAT_004126dc = 0;
      FUN_0040a938(DAT_0041801c);
      return 0;
    }
    if (param_2 == 0x10) goto LAB_0040c623;
    goto switchD_0040c72d_caseD_203;
  }
  if (0x111 < param_2) {
    if (param_2 < 0x302) {
      if (param_2 == 0x301) {
        pvVar1 = DAT_00417ce4;
        if (DAT_00418030 == (int *)0x0) {
          DAT_00418028 = FUN_0040de82((LPCSTR)0xcb);
          if (DAT_00418028 == (int *)0x0) {
            FUN_0040306d();
            SendMessageA(DAT_00417cfc,2,0,0);
            return 0;
          }
          DAT_00418030 = DAT_00418028;
          DAT_00418028 = FUN_0040de82(s_LIGHTED_00412c60);
          if (DAT_00418028 == (HGLOBAL)0x0) {
            FUN_0040306d();
            SendMessageA(DAT_00417cfc,2,0,0);
            return 0;
          }
          DAT_00417cd8 = DAT_00418028;
          DAT_00418028 = FUN_0040de82(s_DIGITS_00412c68);
          pvVar1 = DAT_00418028;
          if (DAT_00418028 == (HGLOBAL)0x0) {
            FUN_0040306d();
            SendMessageA(DAT_00417cfc,2,0,0);
            return 0;
          }
        }
        DAT_00417ce4 = pvVar1;
        DAT_00418018 = FUN_00402657(DAT_00418030);
        if (DAT_00418018 == (HGLOBAL)0x0) {
          FUN_0040306d();
          SendMessageA(DAT_00417cfc,2,0,0);
          return 0;
        }
        DAT_004126d8 = 1;
        local_2c.top = 0;
        local_2c.left = 0;
        local_2c.bottom = 100;
        local_2c.right = 100;
        InvalidateRect(DAT_0041801c,&local_2c,0);
        UpdateWindow(DAT_0041801c);
        return 0;
      }
      switch(param_2) {
      case 0x201:
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        if ((DAT_004127a0 != 0) || (DAT_004123b0 != 0)) {
          PostMessageA(DAT_004181b8,0x111,0x65,0);
          return 0;
        }
        if (DAT_004123b8 == 1) {
          PostMessageA(DAT_004181b8,0x111,0xc9,0);
          return 0;
        }
        local_3c = param_4 & 0xffff;
        uVar5 = param_4 >> 0x10;
        if ((((0xb0 < uVar5) && (uVar5 < 0x102)) && (DAT_00412818 + 0x14 <= (int)local_3c)) &&
           ((int)local_3c <= DAT_00412818 + 100)) {
          if (DAT_00412790 != 0) {
            DAT_00412790 = 0;
            FUN_0040796d();
          }
          if (DAT_00412814 != 0) {
            return 0;
          }
          FUN_0040a987(DAT_0041801c);
          DAT_004123a0 = 6;
          DAT_004123a4 = 0;
          return 0;
        }
        if (((0x9c < uVar5) && (uVar5 < 0x116)) && ((0xd8 < local_3c && (local_3c < 0x129)))) {
          if (DAT_00412790 != 0) {
            DAT_00412790 = 0;
            FUN_0040796d();
          }
          if (DAT_00412814 != 0) {
            return 0;
          }
          FUN_0040a6a0();
          DAT_004123a0 = 3;
          DAT_004123a4 = 0;
          return 0;
        }
        if (((0x9c < uVar5) && (uVar5 < 0x116)) && ((local_3c < 0x18e && (0x13d < local_3c)))) {
          if (DAT_00412790 != 0) {
            DAT_00412790 = 0;
            FUN_0040796d();
          }
          if (DAT_00412814 != 0) {
            return 0;
          }
          FUN_0040a415();
          DAT_004123a0 = 4;
          DAT_004123a4 = 0;
          return 0;
        }
        if ((((0x11 < uVar5) && (uVar5 < 0x89)) && (0x128 < local_3c)) && (local_3c < 0x13d)) {
          if ((0x128 < local_3c) && (local_3c < 0x13d)) {
            if (DAT_00412814 != 0) {
              DAT_004123a0 = 0;
              DAT_004123a8 = 0;
              return 0;
            }
            FUN_00406959();
          }
          if (DAT_00412790 == 1) {
            return 0;
          }
          DAT_00412790 = 1;
          FUN_0040796d();
          return 0;
        }
        if (((0x10 < uVar5) && (uVar5 < 0x8a)) && (local_3c < 0x129)) {
          if (DAT_00412790 != 1) {
            DAT_00412790 = 1;
            FUN_0040796d();
          }
          FUN_0040a135();
          DAT_004123a0 = 1;
          DAT_004123a4 = 0;
          return 0;
        }
        if (((0x10 < uVar5) && (uVar5 < 0x8a)) && (0x13d < local_3c)) {
          if (DAT_00412790 != 1) {
            DAT_00412790 = 1;
            FUN_0040796d();
          }
          FUN_00409e3d();
          DAT_004123a0 = 2;
          DAT_004123a4 = 0;
          return 0;
        }
        if ((((0x8b < uVar5) && (uVar5 < 0xd4)) && (0x98 < local_3c)) && (local_3c < 0xcd)) {
          FUN_00407e2e('\0');
          return 0;
        }
        if (((0x8b < uVar5) && (uVar5 < 0xd4)) && ((0x198 < local_3c && (local_3c < 0x1cd)))) {
          FUN_00407e2e('\x01');
          return 0;
        }
        if ((((0xe1 < uVar5) && (uVar5 < 0x129)) && (0x98 < local_3c)) && (local_3c < 0xcd)) {
          FUN_00407e2e('\x03');
          return 0;
        }
        if (uVar5 < 0xe2) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (0x128 < uVar5) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (local_3c < 0x199) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (0x1cc < local_3c) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        FUN_00407e2e('\x02');
        return 0;
      case 0x202:
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        return 0;
      default:
        break;
      case 0x204:
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        if (DAT_004127a0 == 1) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (DAT_004123b8 == 1) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (DAT_00412814 != 0) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        local_3c = param_4 & 0xffff;
        uVar5 = param_4 >> 0x10;
        if ((((0xb0 < uVar5) && (uVar5 < 0x102)) && (DAT_00412818 + 0x14 <= (int)local_3c)) &&
           ((int)local_3c <= DAT_00412818 + 100)) {
          if (DAT_00412790 != 0) {
            DAT_00412790 = 0;
            FUN_0040796d();
          }
          if (DAT_00412814 != 0) {
            return 0;
          }
          FUN_0040a938(DAT_0041801c);
          DAT_004123a0 = 5;
          DAT_004123a4 = 0;
          return 0;
        }
        if (((0xb0 < uVar5) && (uVar5 < 0x102)) &&
           ((DAT_00412818 + 0x14 <= (int)local_3c && ((int)local_3c <= DAT_00412818 + 100)))) {
          if (DAT_00412790 == 1) {
            DAT_00412790 = 0;
            FUN_0040796d();
          }
          FUN_004080ae();
          return 0;
        }
        if (uVar5 < 0x25) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (0x75 < uVar5) {
          DAT_004123a0 = 0;
          DAT_004123a8 = 0;
          return 0;
        }
        if (DAT_00412790 != 1) {
          DAT_00412790 = 1;
          FUN_0040796d();
        }
        FUN_0040b0d4();
        return 0;
      case 0x205:
        goto switchD_0040bc78_caseD_69;
      }
    }
    goto switchD_0040c72d_caseD_203;
  }
  if (param_2 != 0x111) {
    if (param_2 == 0x101) {
      if ((DAT_004127c4 != param_3) && (param_3 != 0xc)) {
        DAT_004123a0 = 0;
        DAT_004123a8 = 0;
        return 0;
      }
      DAT_004123a0 = 0;
      DAT_004123a8 = 0;
      _DAT_004126dc = 1;
      return 0;
    }
    goto switchD_0040c72d_caseD_203;
  }
  switch(param_3 & 0xffff) {
  case 0x65:
    DAT_004123b0 = 0;
    if (DAT_004127a0 != 1) {
      IVar3 = FUN_00403440();
      if (IVar3 != 1) goto switchD_0040bc78_caseD_69;
      iVar2 = FUN_00401d48(DAT_004180b0,&DAT_00417e1c);
      if ((iVar2 != 0) && (DAT_00417e1c < 10)) {
        if (DAT_00412254 != 0) {
          FUN_004037cf();
        }
        FUN_00401de5(DAT_004180b0);
        FUN_00401f29();
        DAT_00412968 = DAT_00417e1c;
        FUN_0040381e();
      }
      KillTimer(DAT_0041801c,2);
      DAT_004123b8 = 0;
    }
    local_34 = GetDC(DAT_0041801c);
    local_c = CreateCompatibleDC(local_34);
    if (DAT_004123ac == 1) {
      DAT_004123ac = 0;
    }
    DAT_004126ec = DAT_004126ec + 1 & 1;
    DAT_00412800 = DAT_00412240;
    DAT_004126e4 = DAT_00412244;
    DAT_004180b0 = 0;
    DAT_004123b8 = 0;
    DAT_004127a0 = 0;
    FUN_004022d0();
    uVar5 = (int)(DAT_004126e0 + 1U) >> 0x1f;
    DAT_004126e0 = ((DAT_004126e0 + 1U ^ uVar5) - uVar5 & 1 ^ uVar5) - uVar5;
    FUN_004011f5(DAT_004126e0 + 2);
    SelectPalette(local_34,DAT_00417f18,0);
    RealizePalette(local_34);
    uVar5 = (int)DAT_00412800 >> 0x1f;
    FUN_00407f77((LPCSTR)((((DAT_00412800 ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5) + 0x65));
    for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1) {
      (&DAT_004126c8)[local_30] = 0;
    }
    FUN_00407bb3(local_34,local_c,0x412c70,5,500,0xbd);
    FUN_0040b1db();
    DAT_004180c4 = 0;
    iVar2 = FUN_00409238(DAT_00412800);
    DAT_004127a4 = (undefined1)iVar2;
    _DAT_004127a8 = 0;
    for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1) {
      for (local_38 = 0; local_38 < 4; local_38 = local_38 + 1) {
        for (local_80 = 0; local_80 < 5; local_80 = local_80 + 1) {
          (&DAT_00417db8)[local_80 + local_30 * 0x14 + local_38 * 5] = 0;
        }
      }
    }
    FUN_00409a80(local_34,local_c);
    _memset(&DAT_00417ef0,0,0x28);
    if (DAT_00412248 != 0) {
      FUN_004035cc();
      UpdateWindow(DAT_004181b8);
    }
    if (DAT_004123b8 != 0) {
      DAT_004123b8 = 0;
      InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
      UpdateWindow(DAT_004181b8);
      FUN_004011f5(DAT_004126e0 + 2);
    }
    FUN_00409275(local_34,local_c);
    if (DAT_004126e4 == 1) {
      _DAT_00417ee0 = SetTimer(param_1,2,10000,DAT_004180c8);
    }
    else {
      _DAT_00417ee0 = SetTimer(param_1,2,DAT_004126e4 * -0x5dc + 9000,DAT_004180c8);
    }
    DeleteDC(local_c);
    ReleaseDC(DAT_0041801c,local_34);
    SetFocus(param_1);
    break;
  case 0x66:
    DAT_00412968 = -1;
    FUN_0040381e();
    break;
  case 0x67:
    PostMessageA(DAT_004181b8,0x10,0,0);
  default:
switchD_0040bc78_caseD_69:
    DAT_004123a0 = 0;
    DAT_004123a8 = 0;
    break;
  case 0x68:
    local_1c = DAT_00412024;
    FUN_00403899();
    if (DAT_00412024 != local_1c) {
      if ((DAT_00412024 == 0) || (DAT_004123b8 != 0)) {
        FUN_004011f5(0);
      }
      else if (DAT_004123b0 == 0) {
        FUN_004011f5(DAT_004126e0 + 2);
      }
      else {
        FUN_004011f5(1);
      }
    }
    FUN_00401f29();
    break;
  case 0xc9:
    if (DAT_004127a0 == 0) {
      DAT_004123b8 = (uint)(DAT_004123b8 == 0);
      FUN_004022d0();
      if (DAT_004123b8 == 0) {
        FUN_00401118(DAT_004126e4 + 1);
      }
      else {
        InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
        UpdateWindow(DAT_004181b8);
        FUN_004010a5();
      }
      InvalidateRect(param_1,(RECT *)0x0,0);
    }
    else {
      SendMessageA(param_1,0x111,0x65,0);
    }
    break;
  case 0xea:
    if (DAT_004127a0 != 1) {
      KillTimer(DAT_0041801c,2);
    }
    local_34 = GetDC(DAT_0041801c);
    local_c = CreateCompatibleDC(local_34);
    if (DAT_004123ac == 1) {
      DAT_004123ac = 0;
    }
    DAT_004126ec = DAT_004126ec + 1 & 1;
    DAT_004123b8 = 0;
    SelectPalette(local_34,DAT_00417f18,0);
    RealizePalette(local_34);
    FUN_0040b1db();
    iVar2 = FUN_00409238(DAT_00412800);
    DAT_004127a4 = (undefined1)iVar2;
    FUN_00409a80(local_34,local_c);
    FUN_0040c75b(local_34,local_c);
    if (DAT_004126e4 == 1) {
      _DAT_00417ee0 = SetTimer(param_1,2,10000,DAT_004180c8);
    }
    else {
      _DAT_00417ee0 = SetTimer(param_1,2,DAT_004126e4 * -0x5dc + 9000,DAT_004180c8);
    }
    SelectObject(local_c,local_18);
    DeleteDC(local_c);
    ReleaseDC(DAT_0041801c,local_34);
    break;
  case 0x12e:
    FUN_004034f9();
    break;
  case 0x12f:
    WinHelpA(param_1,s_FFLUSH_HLP_004123c8,0xb,0);
    break;
  case 0x130:
    FUN_004035cc();
    break;
  case 0x131:
    DAT_0041224c = (uint)(DAT_0041224c == 0);
    FUN_004022d0();
  }
  return 0;
}


// ==== FUN_0040c75b @ 0040c75b

void __cdecl FUN_0040c75b(HDC param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  iVar1 = FUN_00409238(DAT_00412800);
  DAT_004127a4 = (undefined1)iVar1;
  DAT_004127a0 = 0;
  local_14 = DAT_00417e18 - (DAT_00417e18 / 2 + 1);
  for (local_10 = 0; (int)local_10 < DAT_00417e18; local_10 = local_10 + 1) {
    iVar1 = FUN_0040c81c(local_14);
    FUN_004098ab(param_1,param_2,iVar1);
    uVar2 = (int)local_10 >> 0x1f;
    if (((local_10 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
      local_8 = local_10 + 1;
    }
    else {
      local_8 = -(local_10 + 1);
    }
    local_14 = local_14 + local_8;
  }
  return;
}


// ==== FUN_0040c81c @ 0040c81c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0040c81c(int param_1)

{
  char local_20;
  int local_18;
  int local_14;
  int local_10;
  
  if (_DAT_00412828 == 0) {
    DAT_0041282c = 0x129;
    DAT_0041280c = 0;
  }
  if (_DAT_00412828 == 0x1b) {
    local_10 = 1;
  }
  else {
    if (DAT_0041280c < _DAT_00412828 / 2) {
      local_10 = 0;
      for (local_18 = _DAT_00412828; 0 < local_18; local_18 = local_18 + -1) {
        for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
          (&DAT_00418038)[local_18 * 4 + local_14] =
               *(undefined1 *)((int)&DAT_00418034 + local_18 * 4 + local_14);
        }
      }
      local_20 = '\0';
    }
    else {
      local_10 = 1;
      local_20 = DAT_00412828;
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      (&DAT_00418038)[local_20 * 4 + local_14] = (&DAT_00417d08)[param_1 * 4 + local_14];
    }
    if (local_10 == 1) {
      DAT_00417cf8 = DAT_0041282c + (_DAT_00412828 * 4 + -4) * -5 + -0x14;
    }
    else {
      DAT_0041282c = DAT_0041282c + 0x14;
      DAT_00417cf8 = DAT_0041282c;
    }
    _DAT_00417ce0 = 0;
    _DAT_004180d0 = 1;
  }
  return local_10;
}


// ==== FUN_0040c988 @ 0040c988

void FUN_0040c988(HWND param_1)

{
  ushort uVar1;
  BITMAPINFO *pBVar2;
  UINT UVar3;
  DWORD DVar4;
  undefined1 auStack_28 [16];
  int local_18;
  HDC local_14;
  int local_10;
  HDC local_c;
  HDC local_8;
  
  local_14 = GetDC(DAT_0041801c);
  SelectPalette(local_14,DAT_00417f18,0);
  RealizePalette(local_14);
  local_8 = CreateCompatibleDC(local_14);
  SelectObject(local_8,DAT_00417dac);
  local_c = CreateCompatibleDC(local_14);
  SelectObject(local_c,DAT_00418020);
  if (DAT_00412814 == 3) {
    KillTimer(param_1,1);
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        auStack_28[local_18 + local_10 * 4] =
             (&DAT_00417db8)[local_10 * 5 + DAT_0041281c * 0x14 + local_18];
      }
    }
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        (&DAT_00417db8)[local_10 * 5 + DAT_0041281c * 0x14 + local_18] =
             auStack_28[(local_18 * 4 - local_10) + 3];
      }
    }
    FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00417f60,DAT_00412818,
                 0x9d);
    FUN_00402fa2(DAT_00418030,0,((uint)(DAT_00412790 == 0) * -8 + 8) * 0xf,DAT_00412810,DAT_00412810
                 ,DAT_00417f60,DAT_00412818,0x9d,0);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(local_14,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00412818,
                  (DAT_00417f60[2] + -0x9d) - DAT_00412810,DAT_00412810,DAT_00412810,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    SelectObject(local_8,DAT_004180d8);
    FUN_0040657c(local_14,local_14,local_8,(char)DAT_0041281c,1);
    FUN_0040776e(local_14);
    DAT_00412814 = 0;
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  }
  else {
    FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00417f60,DAT_00412818,
                 0x9d);
    FUN_00402fa2(DAT_00418030,DAT_00412814 * DAT_00412810,((uint)(DAT_00412790 == 0) * -8 + 8) * 0xf
                 ,DAT_00412810,DAT_00412810,DAT_00417f60,DAT_00412818,0x9d,0);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(local_14,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00412818,
                  (DAT_00417f60[2] + -0x9d) - DAT_00412810,DAT_00412810,DAT_00412810,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    DAT_00412814 = DAT_00412814 + 1;
  }
  DeleteDC(local_c);
  DeleteDC(local_8);
  ReleaseDC(DAT_0041801c,local_14);
  return;
}


// ==== FUN_0040cd55 @ 0040cd55

void FUN_0040cd55(HWND param_1)

{
  ushort uVar1;
  BITMAPINFO *pBVar2;
  UINT UVar3;
  DWORD DVar4;
  undefined1 auStack_28 [16];
  int local_18;
  HDC local_14;
  int local_10;
  HDC local_c;
  HDC local_8;
  
  local_14 = GetDC(DAT_0041801c);
  SelectPalette(local_14,DAT_00417f18,0);
  RealizePalette(local_14);
  local_8 = CreateCompatibleDC(local_14);
  SelectObject(local_8,DAT_00417dac);
  local_c = CreateCompatibleDC(local_14);
  SelectObject(local_c,DAT_00418020);
  if (DAT_00412814 == 3) {
    KillTimer(param_1,5);
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        auStack_28[local_10 * 4 + local_18] =
             (&DAT_00417db8)[local_18 + local_10 * 5 + DAT_0041281c * 0x14];
      }
    }
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        (&DAT_00417db8)[local_18 + local_10 * 5 + DAT_0041281c * 0x14] =
             auStack_28[(3 - local_18) * 4 + local_10];
      }
    }
    FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00417f60,DAT_00412818,
                 0x9d);
    FUN_00402fa2(DAT_00418030,0,((uint)(DAT_00412790 == 0) * -8 + 8) * 0xf,DAT_00412810,DAT_00412810
                 ,DAT_00417f60,DAT_00412818,0x9d,0);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(local_14,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00412818,
                  (DAT_00417f60[2] + -0x9d) - DAT_00412810,DAT_00412810,DAT_00412810,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    SelectObject(local_8,DAT_004180d8);
    FUN_0040657c(local_14,local_14,local_8,(char)DAT_0041281c,1);
    FUN_0040776e(local_14);
    DAT_00412814 = 0;
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  }
  else {
    FUN_00402f1b(DAT_00417f68,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00417f60,DAT_00412818,
                 0x9d);
    FUN_00402fa2(DAT_00418030,(2 - DAT_00412814) * DAT_00412810,
                 ((uint)(DAT_00412790 == 0) * -8 + 8) * 0xf,DAT_00412810,DAT_00412810,DAT_00417f60,
                 DAT_00412818,0x9d,0);
    DVar4 = 0xcc0020;
    UVar3 = 1;
    pBVar2 = DAT_00417f6c;
    uVar1 = FUN_004023fc(DAT_00417f60);
    StretchDIBits(local_14,DAT_00412818,0x9d,DAT_00412810,DAT_00412810,DAT_00412818,
                  (DAT_00417f60[2] + -0x9d) - DAT_00412810,DAT_00412810,DAT_00412810,
                  DAT_00417f60 + uVar1 + 10,pBVar2,UVar3,DVar4);
    DAT_00412814 = DAT_00412814 + 1;
  }
  DeleteDC(local_c);
  DeleteDC(local_8);
  ReleaseDC(DAT_0041801c,local_14);
  return;
}


// ==== FUN_0040d12d @ 0040d12d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040d12d(void)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ h;
  int iVar1;
  int local_34;
  
  if (DAT_004127a0 == 1) {
    KillTimer(DAT_0041801c,2);
    InvalidateRect(DAT_004181b8,(RECT *)0x0,0);
  }
  else if ((((DAT_004123b8 != 1) && (DAT_004123c0 == 0)) && (DAT_004123c4 == 0)) &&
          ((DAT_004123bc == 0 && (DAT_004123b4 != 0)))) {
    hdc = GetDC(DAT_0041801c);
    hdc_00 = CreateCompatibleDC(hdc);
    h = SelectObject(hdc_00,DAT_004180d8);
    SelectPalette(hdc,DAT_00417f18,0);
    RealizePalette(hdc);
    if (_DAT_00412828 < 0x19) {
      FUN_004014f3(8);
    }
    else if (_DAT_00412828 < 0x1a) {
      FUN_004014f3(7);
    }
    iVar1 = FUN_00409344(DAT_00412800);
    FUN_004098ab(hdc,hdc_00,iVar1);
    FUN_00407a13(hdc);
    DAT_00417cf8 = 0xfffffffd;
    _DAT_00417ce0 = 0;
    _DAT_004180d0 = 1;
    if (_DAT_00412828 == 0x1b) {
      FUN_004014f3(2);
      local_34 = FUN_004067ef();
    }
    if ((_DAT_00412828 < 0x1b) && (0x18 < _DAT_00412828)) {
      FUN_004014f3(7);
    }
    SelectObject(hdc_00,h);
    DeleteDC(hdc_00);
    ReleaseDC(DAT_0041801c,hdc);
    if (local_34 == 1) {
      if (DAT_00412254 != 0) {
        FUN_004037cf();
      }
      FUN_00401de5(DAT_004180b0);
      FUN_00401f29();
      DAT_00412968 = DAT_00417e1c;
      FUN_0040381e();
    }
  }
  return;
}


// ==== FUN_0040d347 @ 0040d347

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0040d347(HINSTANCE param_1)

{
  _DAT_00417d80 = 0;
  _DAT_00417d84 = FUN_00405d67;
  _DAT_00417d90 = param_1;
  _DAT_00417d94 = LoadIconA(param_1,s_MAINICON_00412c78);
  _DAT_00417d98 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_00417d9c = GetStockObject(5);
  _DAT_00417da0 = 0;
  _DAT_00417da4 = PTR_s_MainFlushWnd_00412830;
  RegisterClassA((WNDCLASSA *)&DAT_00417d80);
  _DAT_00417f28 = 0;
  _DAT_00417f2c = FUN_0040b281;
  _DAT_00417f38 = param_1;
  _DAT_00417f3c = LoadIconA(param_1,s_MAINICON_00412c84);
  _DAT_00417f40 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_00417f44 = GetStockObject(5);
  _DAT_00417f48 = 0;
  _DAT_00417f4c = PTR_s_GameFlushWnd_00412834;
  RegisterClassA((WNDCLASSA *)&DAT_00417f28);
  return 1;
}


// ==== FUN_0040d43b @ 0040d43b

bool __cdecl FUN_0040d43b(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040d491 @ 0040d491

WPARAM FUN_0040d491(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  tagMSG local_128 [4];
  undefined2 *local_a4;
  int local_a0;
  HDC local_9c;
  HDC local_98;
  DWORD local_90;
  CHAR local_8c [132];
  HACCEL local_8;
  
  DAT_0041800c = param_1;
  iVar2 = FUN_00403172();
  if (iVar2 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_FFlushGameMtx_00412c90);
    DVar3 = GetLastError();
    if (DVar3 == 0xb7) {
      local_128[0].wParam = 0;
    }
    else {
      bVar1 = FUN_0040d43b(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_128[0].wParam = 0;
      }
      else {
        local_98 = GetDC((HWND)0x0);
        iVar2 = GetDeviceCaps(local_98,0xc);
        if (iVar2 < 8) {
          ReleaseDC((HWND)0x0,local_98);
          local_128[0].wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_98);
          FUN_0040e77e();
          FUN_0040e818((uint *)s_FFLUSH_DLL_004124c8);
          FUN_0040e9c6((uint *)s_FFLUSH1_DLL_004125c8);
          FUN_0040e796((uint *)s_MSPuzzle_dat_00412288);
          FUN_0040e9c6((uint *)s_FFLUSH_HLP_004123c8);
          FUN_0040e5ab();
          FUN_0040e5c5(DAT_0041800c);
          FUN_0040e604(s_FFLUSH1_DLL_004125c8);
          FUN_0040e604(s_FFLUSH_DLL_004124c8);
          InitCommonControls();
          FUN_0040d347(param_1);
          FUN_0040e4e0(DAT_0041800c,100,local_8c,0x78);
          local_8 = FUN_0040e3bb(param_1,s_ACCELERATORS_1_00412ca0);
          DAT_00417d04 = FUN_0040e47e(DAT_0041800c,s_MainMenuPlayed_00412cb0);
          DAT_00418168 = FUN_0040e47e(DAT_0041800c,s_MainMenu_00412cc0);
          if (local_8 == (HACCEL)0x0) {
            local_128[0].wParam = 0;
          }
          else {
            local_90 = GetVersion();
            if ((byte)local_90 < 4) {
              iVar2 = GetSystemMetrics(5);
              DAT_00417e24 = iVar2 * 2 + 0x266;
              iVar2 = GetSystemMetrics(6);
              iVar4 = GetSystemMetrics(4);
              iVar5 = GetSystemMetrics(0xf);
              DAT_00417ec0 = iVar2 * 2 + iVar4 + iVar5 + 0x127;
              pvVar10 = (LPVOID)0x0;
              pHVar8 = (HWND)0x0;
              iVar2 = DAT_00417e24;
              iVar4 = DAT_00417ec0;
              pHVar9 = DAT_00418168;
              iVar5 = FUN_00403151(DAT_00417ec0);
              iVar6 = FUN_00403130(DAT_00417e24);
              DAT_00417cfc = CreateWindowExA(0,PTR_s_MainFlushWnd_00412830,local_8c,0xca0000,iVar6,
                                             iVar5,iVar2,iVar4,pHVar8,pHVar9,param_1,pvVar10);
            }
            else {
              iVar2 = GetSystemMetrics(7);
              DAT_00417e24 = iVar2 * 2 + 0x266;
              iVar2 = GetSystemMetrics(8);
              iVar4 = GetSystemMetrics(4);
              iVar5 = GetSystemMetrics(0xf);
              DAT_00417ec0 = iVar2 * 2 + iVar4 + iVar5 + 0x127;
              pvVar10 = (LPVOID)0x0;
              pHVar8 = (HWND)0x0;
              iVar2 = DAT_00417e24;
              iVar4 = DAT_00417ec0;
              pHVar9 = DAT_00418168;
              iVar5 = FUN_00403151(DAT_00417ec0);
              iVar6 = FUN_00403130(DAT_00417e24);
              DAT_00417cfc = CreateWindowExA(0x100,PTR_s_MainFlushWnd_00412830,local_8c,0xca0000,
                                             iVar6,iVar5,iVar2,iVar4,pHVar8,pHVar9,param_1,pvVar10);
            }
            if (DAT_00417cfc == (HWND)0x0) {
              local_128[0].wParam = 0;
            }
            else {
              DAT_004181b8 = DAT_00417cfc;
              FUN_0040181e();
              DAT_00418028 = FUN_0040de82((LPCSTR)0xc8);
              if (DAT_00418028 == (ushort *)0x0) {
                local_128[0].wParam = FUN_0040310d();
              }
              else {
                DAT_00417f68 = DAT_00418028;
                DAT_00417f18 = FUN_004024ef(DAT_00418028);
                if (DAT_00417f18 == (HPALETTE)0x0) {
                  local_128[0].wParam = FUN_0040310d();
                }
                else {
                  FUN_00402d97(DAT_00417f18);
                  local_9c = GetDC((HWND)0x0);
                  DAT_00412850 = FUN_0040dc70(local_9c,s_GAMEOVERBMP_00412ccc);
                  DAT_00412854 = FUN_0040dc70(local_9c,s_BREAKBMP_00412cd8);
                  DAT_00412858 = FUN_0040dc70(local_9c,s_BREAKBMP1_00412ce4);
                  DAT_0041285c = FUN_0040dc70(local_9c,s_BREAKBMP2_00412cf0);
                  ReleaseDC((HWND)0x0,local_9c);
                  DAT_00417f60 = FUN_00402657((int *)DAT_00417f68);
                  if (DAT_00417f60 == (HGLOBAL)0x0) {
                    local_128[0].wParam = FUN_0040310d();
                  }
                  else {
                    FUN_0040302d();
                    if ((DAT_00417f6c == (void *)0x0) &&
                       (DAT_00417f6c = GlobalAlloc(0x40,0x228), DAT_00417f6c == (HGLOBAL)0x0)) {
                      local_128[0].wParam = FUN_0040310d();
                    }
                    else {
                      FID_conflict__memcpy(DAT_00417f6c,DAT_00417f60,0x28);
                      local_a4 = (undefined2 *)((int)DAT_00417f6c + 0x28);
                      for (local_a0 = 0; local_a0 < 0x100; local_a0 = local_a0 + 1) {
                        *local_a4 = (short)local_a0;
                        local_a4 = local_a4 + 1;
                      }
                      DAT_00417cf4 = FUN_0040c988;
                      DAT_00417ce8 = FUN_0040cd55;
                      DAT_004180c8 = FUN_0040d12d;
                      DAT_004180c0 = FUN_0040a9d6;
                      FUN_00402280();
                      FUN_00401a1f();
                      FUN_00401ab8();
                      ShowWindow(DAT_00417cfc,param_4);
                      UpdateWindow(DAT_00417cfc);
                      FUN_004022d0();
                      while (BVar7 = GetMessageA(local_128,(HWND)0x0,0,0), BVar7 != 0) {
                        iVar2 = TranslateAcceleratorA(DAT_00417cfc,local_8,local_128);
                        if (iVar2 == 0) {
                          TranslateMessage(local_128);
                          DispatchMessageA(local_128);
                        }
                      }
                      FUN_00401f29();
                      FUN_004011f5(0);
                      FUN_00401605();
                    }
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
    local_128[0].wParam = 0;
  }
  return local_128[0].wParam;
}


// ==== FUN_0040da40 @ 0040da40

undefined * __cdecl FUN_0040da40(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_0040ecb0((uint *)&DAT_004185c8,param_1);
  sVar1 = _strlen(&DAT_004185c8);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_004185c7)[sVar1 + local_8] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_004185c8)[param_3 + sVar1] = 0;
  return &DAT_004185c8;
}


// ==== FUN_0040db09 @ 0040db09

void __cdecl FUN_0040db09(int param_1)

{
  if (param_1 == 0) {
    DAT_00418170 = GetDC(DAT_004181b8);
  }
  else {
    DAT_00418170 = BeginPaint(DAT_004181b8,(LPPAINTSTRUCT)&DAT_00418178);
  }
  return;
}


// ==== FUN_0040db4f @ 0040db4f

void __cdecl FUN_0040db4f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_004181b8,DAT_00418170);
  }
  else {
    EndPaint(DAT_004181b8,(PAINTSTRUCT *)&DAT_00418178);
  }
  return;
}


// ==== FUN_0040db91 @ 0040db91

bool __cdecl FUN_0040db91(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_0040dbda @ 0040dbda

bool __cdecl FUN_0040dbda(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_0040dc70 @ 0040dc70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_0040dc70(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_0040dfa8(DAT_0041800c,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_00412d00 = 0;
        _DAT_004181c0 = 0x300;
        _DAT_004181c2 = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_004181c4)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_004181c5)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_004181c6)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_004181c7)[local_28 * 4] = 0;
        }
        if (DAT_00412cfc == (HPALETTE)0x0) {
          DAT_00412cfc = CreatePalette((LOGPALETTE *)&DAT_004181c0);
        }
      }
      hPal = SelectPalette(param_1,DAT_00417f18,0);
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


// ==== FUN_0040de82 @ 0040de82

HGLOBAL __cdecl FUN_0040de82(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_0040dfa8(DAT_0041800c,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_0040df30 @ 0040df30

HGLOBAL __cdecl FUN_0040df30(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418648 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_00418648 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_0040dfa8 @ 0040dfa8

HGLOBAL __cdecl FUN_0040dfa8(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418648 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_00418648 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_00418648 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_0040e042 @ 0040e042

undefined4 __cdecl FUN_0040e042(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_00412d08; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_00418648 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_00418648 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_00418648 + local_18 * 4),hResInfo);
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


// ==== FUN_0040e153 @ 0040e153

bool __cdecl FUN_0040e153(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_00412d08 <= local_18) {
LAB_0040e1c1:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_00418648 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_00418648 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_00418648 + local_18 * 4),local_14);
      goto LAB_0040e1c1;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_0040e287 @ 0040e287

HRSRC __cdecl FUN_0040e287(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_00418648 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e2ec @ 0040e2ec

HGLOBAL __cdecl FUN_0040e2ec(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_00418648 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_0040e34d @ 0040e34d

INT_PTR __cdecl FUN_0040e34d(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_00418648 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_0040e3bb @ 0040e3bb

HACCEL __cdecl FUN_0040e3bb(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_00418648 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e41d @ 0040e41d

HICON __cdecl FUN_0040e41d(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_00418648 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e47e @ 0040e47e

HMENU __cdecl FUN_0040e47e(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_00418648 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e4e0 @ 0040e4e0

int __cdecl FUN_0040e4e0(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_00412d08 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_00418648 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_0040e549 @ 0040e549

HBITMAP __cdecl FUN_0040e549(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_00412d08 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_00418648 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e5ab @ 0040e5ab

void FUN_0040e5ab(void)

{
  DAT_00412d08 = 0;
  return;
}


// ==== FUN_0040e5c5 @ 0040e5c5

bool __cdecl FUN_0040e5c5(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_00412d08 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_00418648 + DAT_00412d08 * 4) = param_1;
    DAT_00412d08 = DAT_00412d08 + 1;
  }
  return bVar1;
}


// ==== FUN_0040e604 @ 0040e604

undefined4 __cdecl FUN_0040e604(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_00412d08 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_00418648 + DAT_00412d08 * 4) = pHVar2;
      DAT_00412d08 = DAT_00412d08 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040e664 @ 0040e664

bool __cdecl FUN_0040e664(LPCSTR param_1,uint *param_2)

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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_00412f94,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_0040ecb0(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040e73c @ 0040e73c

bool __cdecl FUN_0040e73c(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040e77e @ 0040e77e

undefined4 FUN_0040e77e(void)

{
  return 1;
}


// ==== FUN_0040e796 @ 0040e796

void __cdecl FUN_0040e796(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_0040ecc0(local_104,(uint *)&DAT_00412fc8);
  }
  FUN_0040ecc0(local_104,param_1);
  FUN_0040ecb0(param_1,local_104);
  return;
}


// ==== FUN_0040e818 @ 0040e818

undefined4 __cdecl FUN_0040e818(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040e664(s_Shared_Path_00412fcc,local_104);
  FUN_0040ecc0(local_104,param_1);
  bVar1 = FUN_0040e73c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040e664(s_Shared_Path_00412fd8,local_104);
    FUN_0040ecc0(local_104,(uint *)&DAT_00412fe4);
    FUN_0040ecc0(local_104,param_1);
    bVar1 = FUN_0040e73c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040ecb0(local_104,(uint *)s___shared__00412fe8);
      FUN_0040ecc0(local_104,param_1);
      bVar1 = FUN_0040e73c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040ecb0(local_104,(uint *)&DAT_00412ff4);
        FUN_0040ecc0(local_104,param_1);
        bVar1 = FUN_0040e73c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040ecb0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040ecb0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040ecb0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040ecb0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040e9c6 @ 0040e9c6

undefined4 __cdecl FUN_0040e9c6(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040e664(s_Help_Path_00412ff8,local_104);
  FUN_0040ecc0(local_104,param_1);
  bVar1 = FUN_0040e73c((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040e664(s_Help_Path_00413004,local_104);
    FUN_0040ecc0(local_104,(uint *)&DAT_00413010);
    FUN_0040ecc0(local_104,param_1);
    bVar1 = FUN_0040e73c((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_0040ecb0(local_104,(uint *)&DAT_00413014);
      FUN_0040ecc0(local_104,param_1);
      bVar1 = FUN_0040e73c((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_0040ecb0(local_104,(uint *)s___shared__00413018);
        FUN_0040ecc0(local_104,param_1);
        bVar1 = FUN_0040e73c((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_0040ecb0(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_0040ecb0(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_0040ecb0(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_0040ecb0(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040eb74 @ 0040eb74

undefined4 __cdecl FUN_0040eb74(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_00412f90 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_00418748 + DAT_00412f90 * 4) = param_1;
    DAT_00412f90 = DAT_00412f90 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040ebc0 @ 0040ebc0

void FUN_0040ebc0(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_00412f90; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00418748 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_00418748 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00418748 + local_8 * 4) = 0;
  }
  DAT_00412f90 = 0;
  return;
}


// ==== _memset @ 0040ec50

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


// ==== FUN_0040ecb0 @ 0040ecb0

uint * __cdecl FUN_0040ecb0(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_0040ed98;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_0040ed98:
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


// ==== FUN_0040ecc0 @ 0040ecc0

uint * __cdecl FUN_0040ecc0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_0040ecdc;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_0040ed0f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x0040ed2b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_0040ecdc:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x0040ed2b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x0040ed2b;
    }
  }
LAB_0040ed0f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x0040ed2b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_0040ed98:
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
    if (bVar1 == 0) goto LAB_0040ed98;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== FID_conflict:_memcpy @ 0040eda0

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
switchD_0040ee69_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0040ee69_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0040ee69_caseD_3:
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
        goto switchD_0040ee69_caseD_1;
      case 2:
        goto switchD_0040ee69_caseD_2;
      case 3:
        goto switchD_0040ee69_caseD_3;
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
switchD_0040edd0_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0040edd0_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0040edd0_caseD_3:
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
      goto switchD_0040edd0_caseD_1;
    case 2:
      goto switchD_0040edd0_caseD_2;
    case 3:
      goto switchD_0040edd0_caseD_3;
    }
  }
  return _Dst;
}


// ==== _strncmp @ 0040eef0

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


// ==== FUN_0040ef30 @ 0040ef30

void __cdecl FUN_0040ef30(undefined4 param_1)

{
  DAT_00413030 = param_1;
  return;
}


// ==== _rand @ 0040ef40

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00413030 = DAT_00413030 * 0x343fd + 0x269ec3;
  return (DAT_00413030 & 0x7fff0000) >> 0x10;
}


// ==== _strcmp @ 0040ef70

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
      if (bVar4 != *_Str2) goto LAB_0040efb4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0040ef80;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_0040efb4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_0040efb4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0040ef80:
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
LAB_0040efb4:
  return (uint)bVar5 * -2 + 1;
}


// ==== _free @ 0040f000

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
    HeapFree(DAT_00419a70,0,_Memory);
  }
  return;
}


// ==== _malloc @ 0040f050

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00413878);
  return pvVar1;
}


// ==== __nh_malloc @ 0040f070

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


// ==== __heap_alloc @ 0040f0c0

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00413874) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_00419a70,0,dwBytes);
  return pvVar2;
}


// ==== _strlen @ 0040f100

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
    if (((uint)puVar2 & 3) == 0) goto LAB_0040f120;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_0040f153:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_0040f120:
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
  goto LAB_0040f153;
}


// ==== entry @ 0040f180

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
  puStack_c = &DAT_00411000;
  puStack_10 = &LAB_004108f0;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_00413894 = DVar2 >> 8 & 0xff;
  DAT_00413888 = DVar2 >> 0x10;
  _DAT_00413890 = DVar2 & 0xff;
  _DAT_0041388c = _DAT_00413890 * 0x100 + _DAT_00413894;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00419a74 = (byte *)GetCommandLineA();
  DAT_00413040 = ___crtGetEnvironmentStringsA();
  if ((DAT_00413040 == (LPVOID)0x0) || (DAT_00419a74 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_00419a74;
  pbVar6 = DAT_00419a74;
  if (bVar1 == 0x22) {
    pbVar6 = DAT_00419a74 + 1;
    if (*pbVar6 != 0x22) {
      do {
        if (*pbVar6 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar6);
        if (iVar3 != 0) {
          pbVar6 = pbVar6 + 1;
        }
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x22);
      if (*pbVar6 != 0x22) goto LAB_0040f285;
    }
    pbVar6 = pbVar6 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    }
  }
LAB_0040f285:
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
  _Code = FUN_0040d491(pHVar5,uVar7,pbVar6,uVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 0040f320

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0041304c == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_00413048)(0xff);
  return;
}


// ==== __heap_init @ 0040f350

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_00419a70 = HeapCreate(1,0x1000,0);
  if (DAT_00419a70 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_00419a70);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 0040f390

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
  
  if (DAT_00413868 == 0) {
    lpMem = &PTR_LOOP_00413058;
  }
  else {
    lpMem = HeapAlloc(DAT_00419a70,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00413058) {
        if (PTR_LOOP_00413058 == (undefined *)0x0) {
          PTR_LOOP_00413058 = (undefined *)&PTR_LOOP_00413058;
        }
        if (PTR_LOOP_0041305c == (undefined *)0x0) {
          PTR_LOOP_0041305c = (undefined *)&PTR_LOOP_00413058;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00413058;
        lpMem[1] = PTR_LOOP_0041305c;
        PTR_LOOP_0041305c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00413058) {
    HeapFree(DAT_00419a70,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 0040f500

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_0041386c == param_1) {
    PTR_LOOP_0041386c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00413058) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00419a70,0,param_1);
    return;
  }
  DAT_00413868 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 0040f560

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
  
  ppuVar4 = (undefined **)PTR_LOOP_0041305c;
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
            DAT_00413870 = DAT_00413870 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_0041305c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 0040f640

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00413058;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00413058) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 0040f6a0

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00413870 = DAT_00413870 + 1, DAT_00413870 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 0040f6f0

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
  
  piVar12 = (int *)PTR_LOOP_0041386c;
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
              PTR_LOOP_0041386c = (undefined *)piVar12;
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
              PTR_LOOP_0041386c = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_0041386c != piVar12);
  ppuVar11 = &PTR_LOOP_00413058;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00413058) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_0041386c = (undefined *)ppuVar11;
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
  PTR_LOOP_0041386c = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 0040f970

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


// ==== __callnewh @ 0040faf0

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_00419848 != (code *)0x0) {
    iVar1 = (*DAT_00419848)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __cinit @ 0040fb20

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_00419a6c != (code *)0x0) {
    (*DAT_00419a6c)();
  }
  __initterm((undefined4 *)&DAT_00412008,(undefined4 *)&DAT_0041200c);
  iVar1 = __initterm((undefined4 *)&DAT_00412000,(undefined4 *)&DAT_00412004);
  return iVar1;
}


// ==== _exit @ 0040fb50

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0040fb70

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 0040fb90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_004138c4 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004138c0 = 1;
  DAT_004138bc = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00419a68 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00419a64 + -4), DAT_00419a68 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00419a68 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00412010,(undefined4 *)&DAT_00412014);
  }
  __initterm((undefined4 *)&DAT_00412018,(undefined4 *)&DAT_0041201c);
  if (param_3 == 0) {
    DAT_004138c4 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 0040fc40

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


// ==== __global_unwind2 @ 0040fc60

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x40fc78,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0040fca2

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
  puStack_18 = &LAB_0040fc80;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0040fd36();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== FUN_0040fd36 @ 0040fd36

void FUN_0040fd36(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004138d0 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004138cc = in_EAX;
  DAT_004138d4 = unaff_EBP;
  return;
}


// ==== FUN_0040fd50 @ 0040fd50

LONG __cdecl FUN_0040fd50(int param_1,_EXCEPTION_POINTERS *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = (int *)FUN_0040feb0(param_1);
  uVar3 = DAT_00413960;
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
  DAT_00413960 = param_2;
  if (piVar4[1] == 8) {
    if (DAT_00413950 < DAT_00413954 + DAT_00413950) {
      puVar7 = (undefined4 *)(DAT_00413950 * 0xc + 0x4138e0);
      iVar6 = DAT_00413954;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 3;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar2 = DAT_0041395c;
    iVar6 = *piVar4;
    if (iVar6 == -0x3fffff72) {
      DAT_0041395c = 0x83;
    }
    else if (iVar6 == -0x3fffff70) {
      DAT_0041395c = 0x81;
    }
    else if (iVar6 == -0x3fffff6f) {
      DAT_0041395c = 0x84;
    }
    else if (iVar6 == -0x3fffff6d) {
      DAT_0041395c = 0x85;
    }
    else if (iVar6 == -0x3fffff73) {
      DAT_0041395c = 0x82;
    }
    else if (iVar6 == -0x3fffff71) {
      DAT_0041395c = 0x86;
    }
    else if (iVar6 == -0x3fffff6e) {
      DAT_0041395c = 0x8a;
    }
    (*pcVar1)(8,DAT_0041395c);
    DAT_0041395c = uVar2;
  }
  else {
    piVar4[2] = 0;
    (*pcVar1)(piVar4[1]);
  }
  DAT_00413960 = (_EXCEPTION_POINTERS *)uVar3;
  return -1;
}


// ==== FUN_0040feb0 @ 0040feb0

uint __cdecl FUN_0040feb0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_004138d8;
  do {
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 3;
  } while (piVar1 < &DAT_004138d8 + DAT_00413958 * 3);
  return -(uint)(*piVar1 == param_1) & (uint)piVar1;
}


// ==== __ismbblead @ 0040fee0

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 0040ff00

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00413970 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00413c32 + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 0040ff40

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
  cVar1 = *DAT_00413040;
  pcVar7 = DAT_00413040;
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
  _DAT_004138a4 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00413040;
  pcVar7 = DAT_00413040;
  do {
    if (cVar1 == '\0') {
      _free(DAT_00413040);
      DAT_00413040 = (char *)0x0;
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


// ==== __setargv @ 00410030

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00419850,0x104);
  _DAT_004138b4 = &DAT_00419850;
  pbVar2 = &DAT_00419850;
  if (*DAT_00419a74 != 0) {
    pbVar2 = DAT_00419a74;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_0041389c = puVar1;
  _DAT_00413898 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 004100d0

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
      if (((*(byte *)((int)&DAT_00413970 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_00413970 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_00410140;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_00410140:
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
          if ((*(byte *)((int)&DAT_00413970 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00410271;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00413970 + bVar1 + 1) & 4) != 0) {
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
LAB_00410271:
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


// ==== ___crtGetEnvironmentStringsA @ 004102b0

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
  if (DAT_00413968 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00413968 = 2;
    }
    else {
      DAT_00413968 = 1;
    }
  }
  if (DAT_00413968 != 1) {
    if (DAT_00413968 != 2) {
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


// ==== __setmbcp @ 00410440

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
  if (CodePage == DAT_00413a74) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00413a98;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00413970;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00413aa8 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00413a90)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00413970 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00413a74 = CodePage;
      _DAT_00413a78 = _CPtoLCID(CodePage);
      DAT_00413a80 = *(undefined4 *)(&DAT_00413a9c + local_18 * 0x30);
      DAT_00413a84 = *(undefined4 *)(&DAT_00413aa0 + local_18 * 0x30);
      DAT_00413a88 = *(undefined4 *)(local_18 * 0x30 + 0x413aa4);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00413b88);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00413970;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00413a78 = 0;
      DAT_00413a74 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00413970 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00413970 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00413a74 = CodePage;
      _DAT_00413a78 = _CPtoLCID(CodePage);
    }
    DAT_00413a80 = 0;
    DAT_00413a84 = 0;
    DAT_00413a88 = 0;
    return 0;
  }
  if (DAT_00413a8c == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00410620

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00413a8c = 1;
                    /* WARNING: Could not recover jumptable at 0x0041063d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00413a8c = 1;
                    /* WARNING: Could not recover jumptable at 0x00410652. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00413e50;
  }
  DAT_00413a8c = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00410670

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


// ==== setSBCS @ 004106d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00413970;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00413a80 = 0;
  DAT_00413a74 = 0;
  _DAT_00413a78 = 0;
  DAT_00413a84 = 0;
  DAT_00413a88 = 0;
  return;
}


// ==== ___initmbctable @ 00410700

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00410710

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
  DAT_00419a60 = 0x20;
  DAT_00419960 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00419960 + 0x40);
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
    if ((int)DAT_00419a60 < (int)UVar7) {
      piVar4 = &DAT_00419964;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_00419a60;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00419a60 = DAT_00419a60 + 0x20;
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
      } while ((int)DAT_00419a60 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00419960 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_00419960 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_00419a60);
  return UVar7;
}


// ==== FUN_004109ad @ 004109ad

void FUN_004109ad(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __FF_MSGBANNER @ 004109d0

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0041304c == 1) || ((DAT_0041304c == 0 && (DAT_00413050 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00413c20 != (code *)0x0) {
      (*DAT_00413c20)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00410a10

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
  piVar2 = &DAT_00413b90;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00413c20);
  if ((&DAT_00413b90)[iVar4 * 2] == param_1) {
    if ((DAT_0041304c == 1) || ((DAT_0041304c == 0 && (DAT_00413050 == 1)))) {
      if ((DAT_00419960 == 0) ||
         (hFile = *(HANDLE *)(DAT_00419960 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x413b94);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x413b94);
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


// ==== ___crtMessageBoxA @ 00410c10

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00413e54 != (FARPROC)0x0) {
LAB_00410c5f:
    if (DAT_00413e58 != (FARPROC)0x0) {
      iVar1 = (*DAT_00413e58)();
    }
    if ((iVar1 != 0) && (DAT_00413e5c != (FARPROC)0x0)) {
      iVar1 = (*DAT_00413e5c)(iVar1);
    }
    iVar1 = (*DAT_00413e54)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00413e54 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00413e54 != (FARPROC)0x0) {
      DAT_00413e58 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00413e5c = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00410c5f;
    }
  }
  return 0;
}


// ==== _strncpy @ 00410cb0

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
        goto joined_r0x00410cee;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00410d2b;
        goto LAB_00410d99;
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
joined_r0x00410d95:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00410d99:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00410d2b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00410d95;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00410d95;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00410d95;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00410cee:
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
LAB_00410d2b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


