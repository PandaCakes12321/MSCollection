// ==== FUN_00401000 @ 00401000

void FUN_00401000(void)

{
  FUN_0040101a();
  FUN_00401057();
  return;
}


// ==== FUN_0040101a @ 0040101a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040101a(void)

{
  DAT_00442080 = 0;
  _DAT_00442084 = 0;
  _DAT_00442088 = 0;
  _DAT_0044208c = 1;
  return;
}


// ==== FUN_00401057 @ 00401057

void FUN_00401057(void)

{
  _atexit(FUN_00401074);
  return;
}


// ==== FUN_00401074 @ 00401074

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401074(void)

{
  if (DAT_00442080 != 0) {
    DAT_00442080 = 0;
  }
  _DAT_00442084 = 0;
  _DAT_00442088 = 0;
  _DAT_0044208c = 1;
  return;
}


// ==== FUN_004010be @ 004010be

void FUN_004010be(void)

{
  FUN_004010d8();
  FUN_00401115();
  return;
}


// ==== FUN_004010d8 @ 004010d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004010d8(void)

{
  DAT_00483190 = 0;
  _DAT_00483194 = 0;
  _DAT_00483198 = 0;
  _DAT_0048319c = 1;
  return;
}


// ==== FUN_00401115 @ 00401115

void FUN_00401115(void)

{
  _atexit(FUN_00401132);
  return;
}


// ==== FUN_00401132 @ 00401132

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401132(void)

{
  if (DAT_00483190 != 0) {
    DAT_00483190 = 0;
  }
  _DAT_00483194 = 0;
  _DAT_00483198 = 0;
  _DAT_0048319c = 1;
  return;
}


// ==== FUN_0040117c @ 0040117c

void FUN_0040117c(void)

{
  FUN_00401196();
  FUN_0040123d();
  return;
}


// ==== FUN_00401196 @ 00401196

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401196(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_0044265c = 0;
  _DAT_00442660 = 0;
  _DAT_00442664 = 0;
  _DAT_00442668 = 0;
  _DAT_00442650 = 0;
  _DAT_00442654 = 0;
  _DAT_00442658 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_0040123d @ 0040123d

void FUN_0040123d(void)

{
  _atexit(FUN_0040125a);
  return;
}


// ==== FUN_0040125a @ 0040125a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040125a(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040130e;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  _DAT_00442650 = 0;
  if (DAT_0044265c != (void *)0x0) {
    FUN_00432b10(DAT_0044265c);
  }
  DAT_0044265c = (void *)0x0;
  _DAT_00442664 = 0;
  _DAT_00442668 = 0;
  _DAT_00442654 = 0;
  _DAT_00442658 = 0;
  local_8 = 0xffffffff;
  FUN_004012fd();
  thunk_FUN_00401318();
  return;
}


// ==== FUN_004012fd @ 004012fd

void FUN_004012fd(void)

{
  FUN_0040bb40(&DAT_0044265c);
  return;
}


// ==== FUN_00401318 @ 00401318

void FUN_00401318(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00401326 @ 00401326

void FUN_00401326(void)

{
  FUN_00401340();
  FUN_004013e7();
  return;
}


// ==== FUN_00401340 @ 00401340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401340(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_00487b2c = 0;
  _DAT_00487b30 = 0;
  _DAT_00487b34 = 0;
  _DAT_00487b38 = 0;
  DAT_00487b20 = 0;
  DAT_00487b24 = 0;
  DAT_00487b28 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004013e7 @ 004013e7

void FUN_004013e7(void)

{
  _atexit(FUN_00401404);
  return;
}


// ==== FUN_00401404 @ 00401404

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401404(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004014b8;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  DAT_00487b20 = 0;
  if (DAT_00487b2c != (void *)0x0) {
    FUN_00432b10(DAT_00487b2c);
  }
  DAT_00487b2c = (void *)0x0;
  _DAT_00487b34 = 0;
  _DAT_00487b38 = 0;
  DAT_00487b24 = 0;
  DAT_00487b28 = 0;
  local_8 = 0xffffffff;
  FUN_004014a7();
  thunk_FUN_004014c2();
  return;
}


// ==== FUN_004014a7 @ 004014a7

void FUN_004014a7(void)

{
  FUN_0040bb40(&DAT_00487b2c);
  return;
}


// ==== FUN_004014c2 @ 004014c2

void FUN_004014c2(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004014d0 @ 004014d0

void FUN_004014d0(void)

{
  FUN_004014ea();
  FUN_004015d9();
  return;
}


// ==== FUN_004014ea @ 004014ea

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004014ea(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0044414c = 0;
  _DAT_00444150 = 0;
  _DAT_00444154 = 0;
  _DAT_00444158 = 0;
  DAT_00444140 = 0;
  DAT_00444144 = 0;
  DAT_00444148 = 0;
  DAT_00444160 = 0xffffffff;
  DAT_00444168 = 0;
  _DAT_00444164 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_004015d9 @ 004015d9

void FUN_004015d9(void)

{
  _atexit(FUN_004015f6);
  return;
}


// ==== FUN_004015f6 @ 004015f6

void FUN_004015f6(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040163e;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_0040162e();
  thunk_FUN_00401648();
  return;
}


// ==== FUN_0040162e @ 0040162e

void FUN_0040162e(void)

{
  FUN_0040c070(&DAT_00444140);
  return;
}


// ==== FUN_00401648 @ 00401648

void FUN_00401648(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00401656 @ 00401656

void FUN_00401656(void)

{
  FUN_00401670();
  FUN_004018dd();
  return;
}


// ==== FUN_00401670 @ 00401670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401670(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004018c5;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  DAT_00480ebc = 0;
  _DAT_00480ec0 = 0;
  _DAT_00480ec4 = 0;
  _DAT_00480ec8 = 0;
  local_8 = 0;
  _eh_vector_constructor_iterator_(&DAT_00480f2c,4,0xc,FUN_0040c940,FUN_0040c970);
  local_8 = CONCAT31(local_8._1_3_,1);
  _memset(&DAT_004616ac,0,0xfc04);
  _memset(&DAT_004712b4,0,0xfc04);
  DAT_00480eb8 = 0;
  DAT_00480ed4 = 0xffffffff;
  DAT_00480ed8 = 0xffffffff;
  _DAT_00480f04 = 1;
  _DAT_00480f08 = 0;
  _DAT_00480f0c = 0;
  DAT_00480f28 = 0;
  DAT_00480f29 = 1;
  DAT_00480f1c = 0;
  _DAT_00480f18 = 0;
  DAT_00480ecc = 0xffffffff;
  DAT_00480ed0 = 0xffffffff;
  _DAT_00480edc = 0xffffffff;
  _DAT_00480ee0 = 0xffffffff;
  _DAT_00480ee4 = 0xffffffff;
  _DAT_00480ee8 = 0xffffffff;
  _DAT_00480ef4 = 0xffffffff;
  _DAT_00480ef8 = 0xffffffff;
  _DAT_00480efc = 0xffffffff;
  _DAT_00480f00 = 0xffffffff;
  _DAT_00480eec = 0xffffffff;
  _DAT_00480ef0 = 0xffffffff;
  _DAT_00480fa4 = 0;
  _DAT_00480fa8 = 0;
  DAT_00480fb4 = 0;
  DAT_00480fb8 = 1;
  DAT_00480fbc = 1;
  _DAT_00480fc0 = 0;
  _DAT_00480fc4 = 1;
  _DAT_00480fac = 0;
  _DAT_00480fb0 = 0x46;
  _DAT_00480f20 = 0xffffffff;
  DAT_00480f24 = 1;
  DAT_004712b0 = 0xfe;
  DAT_004616a8 = 0xfe;
  DAT_004712b2 = 0xfe;
  DAT_004616aa = 0xfe;
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_004018dd @ 004018dd

void FUN_004018dd(void)

{
  _atexit(FUN_004018fa);
  return;
}


// ==== FUN_004018fa @ 004018fa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004018fa(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00401b32;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 1;
  _memset(&DAT_004616ac,0,0xfc04);
  _memset(&DAT_004712b4,0,0xfc04);
  DAT_00480eb8 = 0;
  DAT_00480ed4 = 0xffffffff;
  DAT_00480ed8 = 0xffffffff;
  _DAT_00480f04 = 1;
  _DAT_00480f08 = 0;
  _DAT_00480f0c = 0;
  DAT_00480f28 = 0;
  DAT_00480f29 = 1;
  DAT_00480f1c = 0;
  _DAT_00480f18 = 0;
  DAT_00480ecc = 0xffffffff;
  DAT_00480ed0 = 0xffffffff;
  _DAT_00480edc = 0xffffffff;
  _DAT_00480ee0 = 0xffffffff;
  _DAT_00480ee4 = 0xffffffff;
  _DAT_00480ee8 = 0xffffffff;
  _DAT_00480ef4 = 0xffffffff;
  _DAT_00480ef8 = 0xffffffff;
  _DAT_00480efc = 0xffffffff;
  _DAT_00480f00 = 0xffffffff;
  _DAT_00480eec = 0xffffffff;
  _DAT_00480ef0 = 0xffffffff;
  _DAT_00480fa4 = 0;
  _DAT_00480fa8 = 0;
  DAT_00480fb4 = 0;
  DAT_00480fb8 = 1;
  DAT_00480fbc = 1;
  _DAT_00480fc0 = 0;
  _DAT_00480fc4 = 1;
  _DAT_00480fac = 0;
  _DAT_00480fb0 = 0x46;
  _DAT_00480f20 = 0xffffffff;
  DAT_00480f24 = 1;
  if (DAT_00480ebc != (void *)0x0) {
    FUN_00432b10(DAT_00480ebc);
  }
  DAT_00480ebc = (void *)0x0;
  _DAT_00480ec4 = 0;
  _DAT_00480ec8 = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_00401b07();
  local_8 = 0xffffffff;
  FUN_00401b21();
  thunk_FUN_00401b3c();
  return;
}


// ==== FUN_00401b07 @ 00401b07

void FUN_00401b07(void)

{
  _eh_vector_destructor_iterator_(&DAT_00480f2c,4,0xc,FUN_0040c970);
  return;
}


// ==== FUN_00401b21 @ 00401b21

void FUN_00401b21(void)

{
  FUN_0040bb40(&DAT_00480ebc);
  return;
}


// ==== FUN_00401b3c @ 00401b3c

void FUN_00401b3c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_00401b4a @ 00401b4a

void FUN_00401b4a(void)

{
  FUN_00401b64();
  FUN_00401c6f();
  return;
}


// ==== FUN_00401b64 @ 00401b64

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00401b64(void)

{
  int local_8;
  
  _DAT_00486c3c = 0;
  _DAT_00486c38 = 0;
  DAT_00486b70 = 0;
  DAT_00486b80 = 0;
  _DAT_00486b84 = 0;
  _DAT_00486b88 = 0;
  _DAT_00486b8c = 0xf;
  _DAT_00486c34 = 0;
  DAT_00486b74 = 0;
  DAT_00486b78 = 0;
  _DAT_00486b7c = 0xffffffff;
  _DAT_00487880 = 0;
  _DAT_0048787c = 0;
  _DAT_00486c44 = 0;
  DAT_00486c40 = 0;
  DAT_00486f90 = 1;
  _DAT_00486f94 = 0;
  _DAT_00487898 = 0;
  _DAT_0048789c = 0xffffffff;
  _DAT_004878a0 = 2;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00486bd0 + local_8 * 4) = 0;
  }
  return;
}


// ==== FUN_00401c6f @ 00401c6f

void FUN_00401c6f(void)

{
  _atexit(FUN_00401c8c);
  return;
}


// ==== FUN_00401c8c @ 00401c8c

void FUN_00401c8c(void)

{
  if (DAT_00486b78 != (HGLOBAL)0x0) {
    GlobalFree(DAT_00486b78);
    DAT_00486b78 = (HGLOBAL)0x0;
  }
  return;
}


// ==== FUN_00401cc4 @ 00401cc4

void FUN_00401cc4(void)

{
  FUN_00401cde();
  FUN_00401d09();
  return;
}


// ==== FUN_00401cde @ 00401cde

void FUN_00401cde(void)

{
  _eh_vector_constructor_iterator_(&DAT_00442670,0xd0,8,FUN_0040c5b0,FUN_0040bac0);
  return;
}


// ==== FUN_00401d09 @ 00401d09

void FUN_00401d09(void)

{
  _atexit(FUN_00401d26);
  return;
}


// ==== FUN_00401d26 @ 00401d26

void FUN_00401d26(void)

{
  _eh_vector_destructor_iterator_(&DAT_00442670,0xd0,8,FUN_0040bac0);
  return;
}


// ==== FUN_00401d4c @ 00401d4c

void FUN_00401d4c(void)

{
  FUN_00401d66();
  FUN_00401d8e();
  return;
}


// ==== FUN_00401d66 @ 00401d66

void FUN_00401d66(void)

{
  _eh_vector_constructor_iterator_(&DAT_00443000,0x28,10,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00401d8e @ 00401d8e

void FUN_00401d8e(void)

{
  _atexit(FUN_00401dab);
  return;
}


// ==== FUN_00401dab @ 00401dab

void FUN_00401dab(void)

{
  _eh_vector_destructor_iterator_(&DAT_00443000,0x28,10,FUN_0040bc90);
  return;
}


// ==== FUN_00401dce @ 00401dce

void FUN_00401dce(void)

{
  FUN_00401de8();
  FUN_00401e10();
  return;
}


// ==== FUN_00401de8 @ 00401de8

void FUN_00401de8(void)

{
  _eh_vector_constructor_iterator_(&DAT_00443648,0x28,5,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00401e10 @ 00401e10

void FUN_00401e10(void)

{
  _atexit(FUN_00401e2d);
  return;
}


// ==== FUN_00401e2d @ 00401e2d

void FUN_00401e2d(void)

{
  _eh_vector_destructor_iterator_(&DAT_00443648,0x28,5,FUN_0040bc90);
  return;
}


// ==== FUN_00401e50 @ 00401e50

void FUN_00401e50(void)

{
  FUN_00401e6a();
  FUN_00401e92();
  return;
}


// ==== FUN_00401e6a @ 00401e6a

void FUN_00401e6a(void)

{
  _eh_vector_constructor_iterator_(&DAT_004831a0,0x28,0x12,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00401e92 @ 00401e92

void FUN_00401e92(void)

{
  _atexit(FUN_00401eaf);
  return;
}


// ==== FUN_00401eaf @ 00401eaf

void FUN_00401eaf(void)

{
  _eh_vector_destructor_iterator_(&DAT_004831a0,0x28,0x12,FUN_0040bc90);
  return;
}


// ==== FUN_00401ed2 @ 00401ed2

void FUN_00401ed2(void)

{
  FUN_00401eec();
  FUN_00401f14();
  return;
}


// ==== FUN_00401eec @ 00401eec

void FUN_00401eec(void)

{
  _eh_vector_constructor_iterator_(&DAT_00442d30,0x28,0x12,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00401f14 @ 00401f14

void FUN_00401f14(void)

{
  _atexit(FUN_00401f31);
  return;
}


// ==== FUN_00401f31 @ 00401f31

void FUN_00401f31(void)

{
  _eh_vector_destructor_iterator_(&DAT_00442d30,0x28,0x12,FUN_0040bc90);
  return;
}


// ==== FUN_00401f54 @ 00401f54

void FUN_00401f54(void)

{
  FUN_00401f6e();
  FUN_00401f96();
  return;
}


// ==== FUN_00401f6e @ 00401f6e

void FUN_00401f6e(void)

{
  _eh_vector_constructor_iterator_(&DAT_00443bc8,0x28,0x23,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00401f96 @ 00401f96

void FUN_00401f96(void)

{
  _atexit(FUN_00401fb3);
  return;
}


// ==== FUN_00401fb3 @ 00401fb3

void FUN_00401fb3(void)

{
  _eh_vector_destructor_iterator_(&DAT_00443bc8,0x28,0x23,FUN_0040bc90);
  return;
}


// ==== FUN_00401fd6 @ 00401fd6

void FUN_00401fd6(void)

{
  FUN_00401ff0();
  FUN_00402018();
  return;
}


// ==== FUN_00401ff0 @ 00401ff0

void FUN_00401ff0(void)

{
  _eh_vector_constructor_iterator_(&DAT_00443190,0x28,0x1e,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00402018 @ 00402018

void FUN_00402018(void)

{
  _atexit(FUN_00402035);
  return;
}


// ==== FUN_00402035 @ 00402035

void FUN_00402035(void)

{
  _eh_vector_destructor_iterator_(&DAT_00443190,0x28,0x1e,FUN_0040bc90);
  return;
}


// ==== FUN_00402058 @ 00402058

void FUN_00402058(void)

{
  FUN_00402072();
  FUN_0040209d();
  return;
}


// ==== FUN_00402072 @ 00402072

void FUN_00402072(void)

{
  _eh_vector_constructor_iterator_(&DAT_004441d8,0x28,3000,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_0040209d @ 0040209d

void FUN_0040209d(void)

{
  _atexit(FUN_004020ba);
  return;
}


// ==== FUN_004020ba @ 004020ba

void FUN_004020ba(void)

{
  _eh_vector_destructor_iterator_(&DAT_004441d8,0x28,3000,FUN_0040bc90);
  return;
}


// ==== FUN_004020e0 @ 004020e0

void FUN_004020e0(void)

{
  FUN_004020fa();
  FUN_00402125();
  return;
}


// ==== FUN_004020fa @ 004020fa

void FUN_004020fa(void)

{
  _eh_vector_constructor_iterator_(&DAT_00480fd0,0x28,0xd2,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_00402125 @ 00402125

void FUN_00402125(void)

{
  _atexit(FUN_00402142);
  return;
}


// ==== FUN_00402142 @ 00402142

void FUN_00402142(void)

{
  _eh_vector_destructor_iterator_(&DAT_00480fd0,0x28,0xd2,FUN_0040bc90);
  return;
}


// ==== FUN_00402168 @ 00402168

void FUN_00402168(void)

{
  FUN_00402182();
  FUN_004021aa();
  return;
}


// ==== FUN_00402182 @ 00402182

void FUN_00402182(void)

{
  _eh_vector_constructor_iterator_(&DAT_00483520,0x28,5,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_004021aa @ 004021aa

void FUN_004021aa(void)

{
  _atexit(FUN_004021c7);
  return;
}


// ==== FUN_004021c7 @ 004021c7

void FUN_004021c7(void)

{
  _eh_vector_destructor_iterator_(&DAT_00483520,0x28,5,FUN_0040bc90);
  return;
}


// ==== FUN_004021ea @ 004021ea

void FUN_004021ea(void)

{
  FUN_00402204();
  FUN_0040222c();
  return;
}


// ==== FUN_00402204 @ 00402204

void FUN_00402204(void)

{
  _eh_vector_constructor_iterator_(&DAT_00483498,0x28,3,FUN_0040bbf0,FUN_0040bc90);
  return;
}


// ==== FUN_0040222c @ 0040222c

void FUN_0040222c(void)

{
  _atexit(FUN_00402249);
  return;
}


// ==== FUN_00402249 @ 00402249

void FUN_00402249(void)

{
  _eh_vector_destructor_iterator_(&DAT_00483498,0x28,3,FUN_0040bc90);
  return;
}


// ==== FUN_0040226c @ 0040226c

void FUN_0040226c(void)

{
  FUN_00402286();
  FUN_0040231f();
  return;
}


// ==== FUN_00402286 @ 00402286

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402286(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  DAT_00483470 = 0;
  DAT_00483474 = 0;
  DAT_00483478 = 0;
  _DAT_0048348c = 0;
  _DAT_00483490 = 0;
  _DAT_00483494 = 1;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_0040231f @ 0040231f

void FUN_0040231f(void)

{
  _atexit(FUN_0040233c);
  return;
}


// ==== FUN_0040233c @ 0040233c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040233c(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004023d7;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  DAT_00483470 = 0;
  DAT_00483478 = 0;
  _DAT_0048348c = 0;
  _DAT_00483490 = 0;
  _DAT_00483494 = 1;
  local_8 = 0xffffffff;
  FUN_004023c7();
  thunk_FUN_004023e1();
  return;
}


// ==== FUN_004023c7 @ 004023c7

void FUN_004023c7(void)

{
  FUN_0040bbb0(&DAT_00483470);
  return;
}


// ==== FUN_004023e1 @ 004023e1

void FUN_004023e1(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004023ef @ 004023ef

void FUN_004023ef(void)

{
  FUN_00402409();
  FUN_00402431();
  return;
}


// ==== FUN_00402409 @ 00402409

void FUN_00402409(void)

{
  _eh_vector_constructor_iterator_(&DAT_00443718,0x50,0xf,FUN_0040bd40,FUN_0040bf40);
  return;
}


// ==== FUN_00402431 @ 00402431

void FUN_00402431(void)

{
  _atexit(FUN_0040244e);
  return;
}


// ==== FUN_0040244e @ 0040244e

void FUN_0040244e(void)

{
  _eh_vector_destructor_iterator_(&DAT_00443718,0x50,0xf,FUN_0040bf40);
  return;
}


// ==== FUN_00402471 @ 00402471

void FUN_00402471(void)

{
  FUN_0040248b();
  FUN_0040251b();
  return;
}


// ==== FUN_0040248b @ 0040248b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040248b(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00402503;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  _eh_vector_constructor_iterator_(&DAT_004878d0,0x50,5,FUN_0040bd40,FUN_0040bf40);
  _DAT_00487a60 = 0;
  _DAT_00487a64 = 0;
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_0040251b @ 0040251b

void FUN_0040251b(void)

{
  _atexit(FUN_00402538);
  return;
}


// ==== FUN_00402538 @ 00402538

void FUN_00402538(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00402589;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_00402570();
  thunk_FUN_00402593();
  return;
}


// ==== FUN_00402570 @ 00402570

void FUN_00402570(void)

{
  _eh_vector_destructor_iterator_(&DAT_004878d0,0x50,5,FUN_0040bf40);
  return;
}


// ==== FUN_00402593 @ 00402593

void FUN_00402593(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_004025a1 @ 004025a1

void __cdecl FUN_004025a1(HWND param_1)

{
  _cpinfo local_18;
  
  GetCPInfo(0,&local_18);
  if (1 < local_18.MaxCharSize) {
    DAT_0043d3e0 = 2;
  }
  DAT_00442d28 = ImmAssociateContext(param_1,(HIMC)0x0);
  return;
}


// ==== FUN_004025e4 @ 004025e4

void __cdecl FUN_004025e4(HWND param_1)

{
  if (DAT_00442d28 != (HIMC)0x0) {
    ImmAssociateContext(param_1,DAT_00442d28);
  }
  return;
}


// ==== FUN_00402615 @ 00402615

void __cdecl FUN_00402615(uint *param_1)

{
  FUN_00432d40((uint *)&DAT_0043d3e8,param_1);
  return;
}


// ==== FUN_00402636 @ 00402636

void __cdecl FUN_00402636(HWND param_1)

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


// ==== FUN_0040276e @ 0040276e

INT_PTR __cdecl FUN_0040276e(HWND param_1)

{
  INT_PTR IVar1;
  
  IVar1 = FUN_0040e5ad(DAT_00483518,s_RESETSCORE_0043e9a8,param_1,FUN_00404fff);
  return IVar1;
}


// ==== FUN_004027a3 @ 004027a3

void __cdecl FUN_004027a3(int param_1)

{
  LPCSTR pCVar1;
  HWND pHVar2;
  code *pcVar3;
  
  if ((0 < param_1) && (param_1 < 0xc)) {
    *(undefined4 *)(&DAT_004830a8 + param_1 * 4) = 1;
    Sleep(100);
    DAT_0043d39c = 1;
    FUN_00402615((uint *)s_QUICKHELPBMP_0043e9b4);
    if (param_1 < 0xb) {
      pcVar3 = FUN_00403add;
      pHVar2 = DAT_0048cc60;
      pCVar1 = FUN_00426060((uint *)s_QHLEVELDIALOG_0043e9d4,param_1,2);
      FUN_0040e5ad(DAT_00483518,pCVar1,pHVar2,pcVar3);
    }
    else {
      FUN_0040e5ad(DAT_00483518,s_QHCONGRATULAT_0043e9c4,DAT_0048cc60,FUN_00403d52);
    }
    DAT_0043d39c = 0;
    FUN_00405495();
  }
  return;
}


// ==== FUN_00402862 @ 00402862

INT_PTR FUN_00402862(void)

{
  INT_PTR IVar1;
  
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_QUICKHELPBMP_0043e9e4);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  IVar1 = FUN_0040e5ad(DAT_00483518,s_EXITGAME_0043e9f4,DAT_0048cc60,FUN_00402f13);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if ((((IVar1 != 1) && (DAT_0043d3ac == 0)) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return IVar1;
}


// ==== FUN_0040291d @ 0040291d

INT_PTR FUN_0040291d(void)

{
  INT_PTR IVar1;
  
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_QUICKHELPBMP_0043ea00);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  IVar1 = FUN_0040e5ad(DAT_00483518,s_NEWGAME_0043ea10,DAT_0048cc60,FUN_00402f13);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if ((((IVar1 != 1) && (DAT_0043d3ac == 0)) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return IVar1;
}


// ==== FUN_004029d8 @ 004029d8

void FUN_004029d8(void)

{
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_ABOUTBMP_0043ea18);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  FUN_0040e5ad(DAT_00483518,s_ABOUT_0043ea24,DAT_0048cc60,FUN_004030b4);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if (((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return;
}


// ==== FUN_00402a78 @ 00402a78

void __cdecl FUN_00402a78(HWND param_1)

{
  FUN_0040e5ad(DAT_00483518,s_CREDITS_0043ea2c,param_1,FUN_004033a4);
  return;
}


// ==== FUN_00402aa4 @ 00402aa4

void __cdecl FUN_00402aa4(HWND param_1)

{
  FUN_0040e5ad(DAT_00483518,s_SYSTEMINFODIALOG_0043ea34,param_1,FUN_0040353f);
  return;
}


// ==== FUN_00402ad0 @ 00402ad0

void FUN_00402ad0(void)

{
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_QUICKHELPBMP_0043ea48);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  FUN_0040e5ad(DAT_00483518,s_QUICKHELPDIALOG_0043ea58,DAT_0048cc60,FUN_00403f83);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if (((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return;
}


// ==== FUN_00402b70 @ 00402b70

void FUN_00402b70(void)

{
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_CUPBMP_0043ea68);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  FUN_0040e5ad(DAT_00483518,s_YOURNAME_0043ea70,DAT_0048cc60,FUN_004041f9);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  return;
}


// ==== FUN_00402bdf @ 00402bdf

void FUN_00402bdf(void)

{
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_CUPBMP_0043ea7c);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  FUN_0040e5ad(DAT_00483518,s_BALLSTOP_0043ea84,DAT_0048cc60,FUN_00404557);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if (((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return;
}


// ==== FUN_00402c7f @ 00402c7f

void FUN_00402c7f(void)

{
  DAT_0043d398 = 1;
  FUN_00402615((uint *)s_OPTIONSBMP_0043ea90);
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  FUN_0040e5ad(DAT_00483518,s_OPTIONS_0043ea9c,DAT_0048cc60,FUN_004048de);
  DAT_0043d398 = 0;
  InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
  if (((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
    DAT_0043d3b4 = DAT_0043d3b8;
  }
  return;
}


// ==== FUN_00402d1f @ 00402d1f

void __cdecl FUN_00402d1f(HWND param_1)

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
  local_8 = FUN_00426290(pHVar1,&DAT_0043d3e8);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_004261b1(local_8,&local_1c,&local_20);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0048d10c,0);
  RealizePalette(pHVar1);
  FUN_004261fa(pHVar1,local_8,((local_18.right - local_18.left) - local_1c) / 2,
               ((local_18.bottom - local_18.top) - local_20) / 2);
  ReleaseDC(param_1,pHVar1);
  DeleteObject(local_8);
  return;
}


// ==== FUN_00402e1e @ 00402e1e

void __cdecl FUN_00402e1e(HWND param_1)

{
  HDC pHVar1;
  HBITMAP pHVar2;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  GetClientRect(param_1,&local_14);
  pHVar1 = GetDC((HWND)0x0);
  pHVar2 = FUN_00426290(pHVar1,s_QUICKHELPBMP_0043eaa4);
  ReleaseDC((HWND)0x0,pHVar1);
  FUN_004261b1(pHVar2,&local_18,&local_1c);
  pHVar1 = GetDC(param_1);
  SelectPalette(pHVar1,DAT_0048d10c,0);
  RealizePalette(pHVar1);
  FUN_004261fa(pHVar1,pHVar2,((local_14.right - local_14.left) - local_18) / 2,
               ((local_14.bottom - local_14.top) - local_1c) / 2);
  ReleaseDC(param_1,pHVar1);
  return;
}


// ==== FUN_00402f13 @ 00402f13

UINT FUN_00402f13(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402636(param_1);
      DAT_00483514 = param_1;
      DAT_00483510 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402d1f(DAT_00483510);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00483514 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00483514);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00483514,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_00483514,(RECT *)0x0,0);
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
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


// ==== FUN_004030b4 @ 004030b4

UINT FUN_004030b4(HWND param_1,uint param_2,HWND param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_20c [64];
  HDC local_10c;
  UINT local_108;
  CHAR local_104 [256];
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402636(param_1);
      DAT_004878a4 = param_1;
      DAT_00486b68 = GetDlgItem(param_1,100);
      FUN_0040e740(DAT_00483518,1,local_104,0x80);
      SetDlgItemTextA(param_1,0x67,local_104);
      _memset(local_20c,0,0x100);
      bVar1 = FUN_0040e8c3(&DAT_0043eab4,local_20c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_0040e8c3(s_Product_ID_0043eab8,local_20c);
      }
      SetDlgItemTextA(param_1,0x68,(LPCSTR)local_20c);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402d1f(DAT_00486b68);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_004878a4) {
          return 0;
        }
      }
      local_10c = GetDC(DAT_004878a4);
      SelectPalette(local_10c,DAT_0048d10c,0);
      local_108 = RealizePalette(local_10c);
      ReleaseDC(DAT_004878a4,local_10c);
      if (local_108 == 0) {
        return 0;
      }
      InvalidateRect(DAT_004878a4,(RECT *)0x0,0);
      InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
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
      FUN_00402aa4(param_1);
      return 1;
    case (HWND)0x66:
      FUN_00402a78(param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004033a4 @ 004033a4

UINT FUN_004033a4(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402636(param_1);
      DAT_004830e8 = param_1;
      DAT_004616a0 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402d1f(DAT_004616a0);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_004830e8 == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004830e8);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_004830e8,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_004830e8,(RECT *)0x0,0);
        InvalidateRect(DAT_004878a4,(RECT *)0x0,0);
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
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


// ==== FUN_0040353f @ 0040353f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040353f(HWND param_1,int param_2,uint param_3)

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
    FUN_00402636(param_1);
    _DAT_00442d00 = param_1;
    local_49c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_49c);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eac4,local_49c.dwMajorVersion,-1);
    FUN_00432d40((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eac8);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eacc,local_49c.dwMinorVersion,-1);
    FUN_00432d50((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043ead0);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043ead4,local_49c.dwBuildNumber & 0xffff,-1);
    FUN_00432d50((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043ead8);
    if (&stack0x00000000 != (undefined1 *)0x488) {
      FUN_00432d50((uint *)local_404,(uint *)local_49c.szCSDVersion);
    }
    SetDlgItemTextA(param_1,0x66,local_404);
    local_4dc.dwLength = 0x20;
    GlobalMemoryStatus(&local_4dc);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eadc,local_4dc.dwTotalPhys >> 10,-1);
    FUN_00432d40((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eae0);
    SetDlgItemTextA(param_1,0x84,local_404);
    GetCurrentDirectoryA(0x80,local_404);
    local_4b4 = local_404[0];
    local_4b3 = 0;
    local_4b2 = 0;
    local_4b1 = 0;
    FUN_00432d40((uint *)local_404,(uint *)&DAT_0043eae4);
    FUN_00432d50((uint *)local_404,(uint *)&local_4b4);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eae8);
    GetDiskFreeSpaceA((LPCSTR)0x0,&local_408,&local_4b8,&local_4a4,&local_4bc);
    local_4a0 = (local_4b8 * local_408 >> 4) * local_4a4 >> 6;
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eaec,local_4a0,-1);
    FUN_00432d50((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eaf0);
    SetDlgItemTextA(param_1,0x8e,local_404);
    GetPrivateProfileStringA
              (s_boot_description_0043eb14,s_display_drv_0043eb08,s_Unknown_0043eb00,local_404,0x80,
               s_system_ini_0043eaf4);
    SetDlgItemTextA(param_1,0xac,local_404);
    local_4a8 = GetDC((HWND)0x0);
    local_4a0 = GetDeviceCaps(local_4a8,8);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb28,local_4a0,-1);
    FUN_00432d40((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eb2c);
    local_4a0 = GetDeviceCaps(local_4a8,10);
    puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb30,local_4a0,-1);
    FUN_00432d50((uint *)local_404,puVar1);
    FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eb34);
    local_4a0 = GetDeviceCaps(local_4a8,0xc);
    if ((int)local_4a0 < 9) {
      puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb38,1 << ((byte)local_4a0 & 0x1f),-1);
      FUN_00432d50((uint *)local_404,puVar1);
    }
    else if ((int)local_4a0 < 0x11) {
      iVar2 = 1 << ((byte)local_4a0 & 0x1f);
      puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb3c,
                                    (int)(iVar2 + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
      FUN_00432d50((uint *)local_404,puVar1);
      FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eb40);
    }
    else {
      if ((int)local_4a0 < 0x19) {
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 0x3ffU);
        puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb48,
                                      (int)((iVar2 >> 10) + (iVar2 >> 0x1f & 0x3ffU)) >> 10,-1);
        FUN_00432d50((uint *)local_404,puVar1);
      }
      else {
        local_4a0 = local_4a0 + -0x10;
        iVar2 = 1 << ((byte)local_4a0 & 0x1f);
        iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
        puVar1 = (uint *)FUN_00426060((uint *)&DAT_0043eb44,
                                      (int)((iVar2 >> 2) + (iVar2 >> 0x1f & 3U)) >> 2,-1);
        FUN_00432d50((uint *)local_404,puVar1);
      }
      FUN_00432d50((uint *)local_404,(uint *)&DAT_0043eb4c);
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


// ==== FUN_00403add @ 00403add

UINT FUN_00403add(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00402d1f(DAT_00461698);
      }
      return 0;
    }
    FUN_00402636(param_1);
    DAT_004420a0 = param_1;
    DAT_00461698 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0043f0cc == 0);
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
      DAT_0043f0cc = (uint)(LVar2 == 0);
      FUN_0041b879();
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
      DAT_0043f0cc = (uint)(LVar2 == 0);
      FUN_0041b879();
      EndDialog(param_1,0);
      PostMessageA(DAT_0048cc60,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (param_3 == DAT_004420a0) {
      return 0;
    }
  }
  hdc = GetDC(DAT_004420a0);
  SelectPalette(hdc,DAT_0048d10c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_004420a0,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_004420a0,(RECT *)0x0,0);
    InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_00403d52 @ 00403d52

UINT FUN_00403d52(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00402636(param_1);
      DAT_0048351c = param_1;
      DAT_00443644 = GetDlgItem(param_1,100);
      LVar4 = 0;
      wParam = (uint)(DAT_0043f0cc == 0);
      UVar3 = 0xf1;
      pHVar1 = GetDlgItem(param_1,0x12d);
      SendMessageA(pHVar1,UVar3,wParam,LVar4);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402d1f(DAT_00443644);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_0048351c == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_0048351c);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar3 = RealizePalette(hdc);
      ReleaseDC(DAT_0048351c,hdc);
      if (UVar3 != 0) {
        InvalidateRect(DAT_0048351c,(RECT *)0x0,0);
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
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
        DAT_0043f0cc = (uint)(LVar2 == 0);
        FUN_0041b879();
        EndDialog(param_1,0);
        PostMessageA(DAT_0048cc60,0x111,0x12f,0);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00403f83 @ 00403f83

UINT FUN_00403f83(HWND param_1,uint param_2,HWND param_3)

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
        FUN_00402d1f(DAT_00442cf0);
      }
      return 0;
    }
    FUN_00402636(param_1);
    DAT_00480fc8 = param_1;
    DAT_00442cf0 = GetDlgItem(param_1,100);
    LVar5 = 0;
    wParam = (uint)(DAT_0043f0c8 == 0);
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
      DAT_0043f0c8 = (uint)(LVar2 == 0);
      FUN_0041b879();
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
      DAT_0043f0c8 = (uint)(LVar2 == 0);
      FUN_0041b879();
      EndDialog(param_1,0);
      PostMessageA(DAT_0048cc60,0x111,0x12f,0);
      return 1;
    }
    EndDialog(param_1,0);
    return 1;
  }
  if (param_2 != 0x30f) {
    if (param_2 != 0x311) {
      return 0;
    }
    if (DAT_00480fc8 == param_3) {
      return 0;
    }
  }
  hdc = GetDC(DAT_00480fc8);
  SelectPalette(hdc,DAT_0048d10c,0);
  UVar3 = RealizePalette(hdc);
  ReleaseDC(DAT_00480fc8,hdc);
  if (UVar3 != 0) {
    InvalidateRect(DAT_00480fc8,(RECT *)0x0,0);
    InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
    return UVar3;
  }
  return 0;
}


// ==== FUN_004041f9 @ 004041f9

UINT FUN_004041f9(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
        FUN_00402d1f(DAT_00442d24);
      }
      return 0;
    }
    FUN_00402636(param_1);
    DAT_004830f0 = param_1;
    DAT_00442d24 = GetDlgItem(param_1,100);
    if (DAT_0043d3e0 == 1) {
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
    SetDlgItemTextA(param_1,0x1e,&DAT_0043f0d8);
    _memset(local_108,0,0x100);
    _Size = 0x10;
    _Src = FUN_00426060((uint *)&DAT_0043eb50,DAT_00486b80,-1);
    FID_conflict__memcpy(local_108,_Src,_Size);
    SetDlgItemTextA(param_1,0x28,local_108);
    return 1;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x30f) {
      if (param_2 != 0x311) {
        return 0;
      }
      if (param_3 == DAT_004830f0) {
        return 0;
      }
    }
    hdc = GetDC(DAT_004830f0);
    SelectPalette(hdc,DAT_0048d10c,0);
    UVar3 = RealizePalette(hdc);
    ReleaseDC(DAT_004830f0,hdc);
    if (UVar3 != 0) {
      InvalidateRect(DAT_004830f0,(RECT *)0x0,0);
      InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
      return UVar3;
    }
    return 0;
  }
  uVar2 = (uint)param_3 & 0xffff;
  if (uVar2 == 1) {
    GetDlgItemTextA(param_1,0x1e,&DAT_0043f0d8,DAT_0043d3e0 * 0x11);
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


// ==== FUN_00404557 @ 00404557

UINT FUN_00404557(HWND param_1,uint param_2,HWND param_3)

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
      FUN_00402636(param_1);
      DAT_004441d0 = param_1;
      DAT_004830ec = GetDlgItem(param_1,0x65);
      if ((-1 < DAT_0043d4e8) && (DAT_0043d4e8 < 10)) {
        SetDlgItemTextA(param_1,DAT_0043d4e8 + 0x33,&DAT_0043eb54);
      }
      for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        uVar2 = GetWindowLongA(pHVar1,iVar6);
        uVar2 = uVar2 | 0x80;
        iVar6 = -0x10;
        pHVar1 = GetDlgItem(param_1,local_14 + 0x1f);
        SetWindowLongA(pHVar1,iVar6,uVar2);
        pCVar3 = FUN_00426060((uint *)&DAT_0043eb58,*(int *)(&DAT_0048c8d0 + local_14 * 0x2c),-1);
        SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
        SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0048c8a8 + local_14 * 0x2c);
      }
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402d1f(DAT_004830ec);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (param_3 == DAT_004441d0) {
          return 0;
        }
      }
      hdc = GetDC(DAT_004441d0);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar4 = RealizePalette(hdc);
      ReleaseDC(DAT_004441d0,hdc);
      if (UVar4 != 0) {
        InvalidateRect(DAT_004441d0,(RECT *)0x0,0);
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
        return UVar4;
      }
      return 0;
    }
    if (param_3 != (HWND)0x0) {
      if (param_3 < (HWND)0x3) {
        EndDialog(param_1,0);
        return 1;
      }
      if ((param_3 == (HWND)0xa) && (IVar5 = FUN_0040276e(DAT_004441d0), IVar5 == 1)) {
        if ((-1 < DAT_0043d4e8) && (DAT_0043d4e8 < 10)) {
          SetDlgItemTextA(param_1,DAT_0043d4e8 + 0x33,&DAT_0043eb5c);
        }
        DAT_0043d4e8 = -1;
        for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_0048c8d0 + local_14 * 0x2c) = 0;
          _memset(&DAT_0048c8a8 + local_14 * 0x2c,0,0x28);
          pCVar3 = FUN_00426060((uint *)&DAT_0043eb60,*(int *)(&DAT_0048c8d0 + local_14 * 0x2c),-1);
          SetDlgItemTextA(param_1,local_14 + 0xb,pCVar3);
          SetDlgItemTextA(param_1,local_14 + 0x1f,&DAT_0048c8a8 + local_14 * 0x2c);
        }
        FUN_0041b879();
      }
    }
  }
  return 0;
}


// ==== FUN_004048de @ 004048de

UINT FUN_004048de(HWND param_1,uint param_2,HWND param_3,HWND param_4)

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
      WinHelpA(DAT_0048cc60,s_COLC_HLP_0043d098,1,0xf);
    }
    else if (param_2 == 0xf) {
      FUN_00402d1f(DAT_00443714);
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00404a88:
      hdc = GetDC(DAT_00442d08);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar6 = RealizePalette(hdc);
      ReleaseDC(DAT_00442d08,hdc);
      if (UVar6 == 0) {
        return 0;
      }
      InvalidateRect(DAT_00442d08,(RECT *)0x0,0);
      InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
      return UVar6;
    }
    if (param_2 == 0x110) {
      FUN_00402636(param_1);
      DAT_00442d08 = param_1;
      DAT_00443714 = GetDlgItem(param_1,100);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0043ebe0;
      pHVar1 = GetDlgItem(param_1,0x33);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0043ebe4;
      pHVar1 = GetDlgItem(param_1,0x32);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      LVar8 = 0;
      UVar6 = 0xf1;
      WVar7 = DAT_0043f0d4;
      pHVar1 = GetDlgItem(param_1,0x28);
      SendMessageA(pHVar1,UVar6,WVar7,LVar8);
      CheckRadioButton(param_1,0x5f,0x62,DAT_0043f0c4 + 0x5e);
      if (DAT_0043d3e0 == 1) {
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
      DAT_0048318c = ImmAssociateContext(pHVar1,pHVar9);
      SetDlgItemTextA(param_1,0x1e,&DAT_0043f0d8);
      pCVar2 = FUN_00426060((uint *)&DAT_0043eb64,DAT_0043f0c0,-1);
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
        DAT_0043ebe0 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x32);
        DAT_0043ebe4 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x28);
        DAT_0043f0d4 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x5f);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0043f0c4 = 1;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x60);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0043f0c4 = 2;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x61);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0043f0c4 = 3;
        }
        LVar8 = 0;
        WVar7 = 0;
        UVar6 = 0xf0;
        pHVar1 = GetDlgItem(param_1,0x62);
        LVar5 = SendMessageA(pHVar1,UVar6,WVar7,LVar8);
        if (LVar5 != 0) {
          DAT_0043f0c4 = 4;
        }
        GetDlgItemTextA(param_1,0x1e,&DAT_0043f0d8,DAT_0043d3e0 * 0x11);
        GetDlgItemTextA(param_1,0xf,local_18,5);
        for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
          pcVar3 = FUN_00426060((uint *)&DAT_0043eb74,local_28,-1);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) {
LAB_00404e9b:
            DAT_0043f0c0 = local_28;
            break;
          }
          pcVar3 = FUN_00426060((uint *)&DAT_0043eb78,local_28,2);
          iVar4 = _strcmp(local_18,pcVar3);
          if (iVar4 == 0) goto LAB_00404e9b;
        }
      case 2:
        DAT_00442d08 = (HWND)0x0;
        pHVar9 = DAT_0048318c;
        pHVar1 = GetDlgItem(param_1,0xf);
        ImmAssociateContext(pHVar1,pHVar9);
        EndDialog(param_1,0);
        return 1;
      case 0xf:
        if ((uint)param_3 >> 0x10 == 0x200) {
          GetDlgItemTextA(param_1,0xf,local_18,5);
          local_1c = DAT_0043f0c0;
          for (local_28 = 1; local_28 < 0xb; local_28 = local_28 + 1) {
            pcVar3 = FUN_00426060((uint *)&DAT_0043eb68,local_28,-1);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) {
LAB_00404bdb:
              local_1c = local_28;
              break;
            }
            pcVar3 = FUN_00426060((uint *)&DAT_0043eb6c,local_28,2);
            iVar4 = _strcmp(local_18,pcVar3);
            if (iVar4 == 0) goto LAB_00404bdb;
          }
          pCVar2 = FUN_00426060((uint *)&DAT_0043eb70,local_1c,-1);
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
        WinHelpA(DAT_0048cc60,s_COLC_HLP_0043d098,1,0xf);
      }
    }
  }
  else if (param_2 == 0x311) {
    if (DAT_00442d08 == param_3) {
      return 0;
    }
    goto LAB_00404a88;
  }
  return 0;
}


// ==== FUN_00404fff @ 00404fff

UINT FUN_00404fff(HWND param_1,uint param_2,HWND param_3)

{
  HDC hdc;
  UINT UVar1;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00402636(param_1);
      DAT_00487b3c = param_1;
      DAT_00443710 = GetDlgItem(param_1,100);
      return 1;
    }
    if (param_2 == 0xf) {
      FUN_00402e1e(DAT_00443710);
    }
  }
  else {
    if (param_2 != 0x111) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          return 0;
        }
        if (DAT_00487b3c == param_3) {
          return 0;
        }
      }
      hdc = GetDC(DAT_00487b3c);
      SelectPalette(hdc,DAT_0048d10c,0);
      UVar1 = RealizePalette(hdc);
      ReleaseDC(DAT_00487b3c,hdc);
      if (UVar1 != 0) {
        InvalidateRect(DAT_004441d0,(RECT *)0x0,0);
        InvalidateRect(DAT_00487b3c,(RECT *)0x0,0);
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
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


// ==== FUN_004051b0 @ 004051b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004051b0(void)

{
  switch(DAT_0043f0c4) {
  case 1:
    _DAT_00480f08 = 0;
    _DAT_00480fc4 = 1;
    if (DAT_00480fb8 < 0) {
      DAT_00480fb8 = -2;
    }
    else {
      DAT_00480fb8 = 2;
    }
    if (DAT_00480fbc < 0) {
      DAT_00480fbc = -2;
    }
    else {
      DAT_00480fbc = 2;
    }
    _DAT_00480fb0 = 0x23;
    break;
  case 2:
    _DAT_00480f08 = 0;
    _DAT_00480fc4 = 2;
    if (DAT_00480fb8 < 0) {
      DAT_00480fb8 = -3;
    }
    else {
      DAT_00480fb8 = 3;
    }
    if (DAT_00480fbc < 0) {
      DAT_00480fbc = -3;
    }
    else {
      DAT_00480fbc = 3;
    }
    _DAT_00480fb0 = 0x17;
    break;
  case 3:
    _DAT_00480f08 = 0;
    _DAT_00480fc4 = 3;
    if (DAT_00480fb8 < 0) {
      DAT_00480fb8 = -4;
    }
    else {
      DAT_00480fb8 = 4;
    }
    if (DAT_00480fbc < 0) {
      DAT_00480fbc = -4;
    }
    else {
      DAT_00480fbc = 4;
    }
    _DAT_00480fb0 = 0x11;
    break;
  case 4:
    _DAT_00480f08 = 0;
    _DAT_00480fc4 = 4;
    if (DAT_00480fb8 < 0) {
      DAT_00480fb8 = -5;
    }
    else {
      DAT_00480fb8 = 5;
    }
    if (DAT_00480fbc < 0) {
      DAT_00480fbc = -5;
    }
    else {
      DAT_00480fbc = 5;
    }
    _DAT_00480fb0 = 0xe;
  }
  if (DAT_00486b70 != DAT_0043f0c0 + -1) {
    DAT_00486b70 = DAT_0043f0c0 + -1;
  }
  return;
}


// ==== FUN_0040547b @ 0040547b

void FUN_0040547b(void)

{
  FUN_0041b408();
  FUN_004051b0();
  return;
}


// ==== FUN_00405495 @ 00405495

void FUN_00405495(void)

{
  HMENU pHVar1;
  UINT UVar2;
  UINT UVar3;
  
  if (((DAT_0043d3a0 == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3ac == 0)) {
    SetMenu(DAT_00442cf8,DAT_00442cfc);
    if (DAT_0043f0cc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00442cf8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00442cf8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00442cf8);
  }
  else {
    SetMenu(DAT_00442cf8,DAT_00487b40);
    if (DAT_0043f0cc == 0) {
      UVar3 = 0;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00442cf8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    else {
      UVar3 = 8;
      UVar2 = 0x131;
      pHVar1 = GetMenu(DAT_00442cf8);
      CheckMenuItem(pHVar1,UVar2,UVar3);
    }
    DrawMenuBar(DAT_00442cf8);
  }
  return;
}


// ==== FUN_00405599 @ 00405599

undefined4 FUN_00405599(void)

{
  int iVar1;
  INT_PTR IVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = DAT_0043f0c4;
  local_c = DAT_0043ebe4;
  local_8 = DAT_0043f0c0;
  FUN_00402c7f();
  FUN_0041b879();
  if (DAT_0043ebe4 == 0) {
    FUN_0040cc75(0);
  }
  else if ((local_c == 0) && (DAT_0043d3a0 == 0)) {
    if (DAT_0043d3ac == 0) {
      FUN_0040cc75(DAT_0043f0c4 + 1);
    }
    else {
      FUN_0040cc75(1);
    }
  }
  if ((DAT_0043f0c0 != local_8) || (DAT_0043f0c4 != iVar1)) {
    if ((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) {
      IVar2 = FUN_0040291d();
      if (IVar2 != 1) {
        return 0;
      }
      iVar3 = FUN_0041b698(DAT_00486b80,&local_10);
      if ((iVar3 != 0) && (local_10 < 10)) {
        if (DAT_0043f0d4 != 0) {
          FUN_00402b70();
        }
        FUN_0041b735(DAT_00486b80);
        DAT_0043d4e8 = local_10;
        FUN_00402bdf();
        FUN_0041b879();
      }
    }
    SendMessageA(DAT_0048cc60,0x111,0x132,0);
    FUN_004051b0();
    DAT_00486b70 = DAT_0043f0c0 + -1;
    DAT_0043d3b0 = DAT_0043f0c4;
    DAT_0043d3a0 = 0;
    DAT_0043d3ac = 0;
    FUN_00405495();
    if ((DAT_0043f0c4 != iVar1) && (local_c != 0)) {
      FUN_0040cc75(DAT_0043f0c4 + 1);
    }
    SendMessageA(DAT_0048cc60,0x111,0x79,0);
  }
  return 0;
}


// ==== FUN_00405770 @ 00405770

undefined4 FUN_00405770(void)

{
  return DAT_0043e8d0;
}


// ==== FUN_00405785 @ 00405785

undefined4 FUN_00405785(void)

{
  return 1;
}


// ==== FUN_0040579a @ 0040579a

void __cdecl FUN_0040579a(undefined4 param_1)

{
  DAT_00442d10 = param_1;
  return;
}


// ==== FUN_004057b2 @ 004057b2

undefined4 FUN_004057b2(void)

{
  return DAT_00442d10;
}


// ==== FUN_004057c7 @ 004057c7

void __thiscall FUN_004057c7(void *this,int param_1)

{
  *(int *)this = param_1;
  *(undefined4 *)((int)this + 8) = 5;
  if ((param_1 != 0) && (*(int *)((int)this + 4) = param_1 / 5, *(int *)((int)this + 4) == 0)) {
    *(undefined4 *)((int)this + 4) = 1;
  }
  return;
}


// ==== FUN_00405828 @ 00405828

undefined4 __thiscall FUN_00405828(void *this,HDC param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 uVar7;
  int iVar8;
  HDC pHVar9;
  HGDIOBJ pvVar10;
  int y;
  int x;
  int local_c;
  
  if (*(int *)this == 0) {
    uVar7 = 0;
  }
  else {
    FUN_0040cf73(0x2c);
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    if (*(int *)((int)this + 8) == 0) {
      *(undefined4 *)((int)this + 8) = 5;
      FUN_0041c2b4(&DAT_00486b70,*(int *)((int)this + 4));
      *(int *)this = *(int *)this - *(int *)((int)this + 4);
      iVar8 = *(int *)this;
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      *(int *)this = iVar8;
      FUN_00425ece(0x486b70);
      if (DAT_0048d67c != 0) {
        bVar6 = false;
        if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            iVar8 = *(int *)(&DAT_0048d548 + local_c * 0x10);
            iVar1 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_0048d544 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar5 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            pHVar9 = CreateCompatibleDC(param_1);
            pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
            BitBlt(param_1,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar8 - iVar1) + 1,pHVar9,iVar5,iVar4,
                   0xcc0020);
            SelectObject(pHVar9,pvVar10);
            DeleteDC(pHVar9);
            GdiFlush();
          }
          DAT_0048d67c = 0;
        }
        else {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
               (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
              bVar6 = true;
              break;
            }
          }
          if (bVar6) {
            for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
              y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
              x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
              iVar8 = *(int *)(&DAT_0048d548 + local_c * 0x10);
              iVar1 = *(int *)(&DAT_0048d540 + local_c * 0x10);
              iVar2 = *(int *)(&DAT_0048d544 + local_c * 0x10);
              iVar3 = *(int *)(&DAT_0048d53c + local_c * 0x10);
              iVar4 = *(int *)(&DAT_0048d540 + local_c * 0x10);
              iVar5 = *(int *)(&DAT_0048d53c + local_c * 0x10);
              pHVar9 = CreateCompatibleDC(param_1);
              pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
              BitBlt(param_1,x,y,(iVar2 - iVar3) + 1,(iVar8 - iVar1) + 1,pHVar9,iVar5,iVar4,0xcc0020
                    );
              SelectObject(pHVar9,pvVar10);
              DeleteDC(pHVar9);
              GdiFlush();
            }
          }
          else {
            for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
              iVar8 = *(int *)(&DAT_0048d548 + local_c * 0x10);
              iVar1 = *(int *)(&DAT_0048d540 + local_c * 0x10);
              iVar2 = *(int *)(&DAT_0048d544 + local_c * 0x10);
              iVar3 = *(int *)(&DAT_0048d53c + local_c * 0x10);
              iVar4 = *(int *)(&DAT_0048d540 + local_c * 0x10);
              iVar5 = *(int *)(&DAT_0048d53c + local_c * 0x10);
              pHVar9 = CreateCompatibleDC(param_1);
              pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
              BitBlt(param_1,iVar5,iVar4,(iVar2 - iVar3) + 1,(iVar8 - iVar1) + 1,pHVar9,iVar5,iVar4,
                     0xcc0020);
              SelectObject(pHVar9,pvVar10);
              DeleteDC(pHVar9);
              GdiFlush();
            }
          }
          DAT_0048d67c = 0;
        }
      }
      uVar7 = 1;
    }
    else {
      uVar7 = 1;
    }
  }
  return uVar7;
}


// ==== FUN_00405ca2 @ 00405ca2

void FUN_00405ca2(void)

{
  return;
}


// ==== FUN_00405cb2 @ 00405cb2

undefined * __cdecl FUN_00405cb2(int param_1)

{
  return (&PTR_DAT_0043d3d0)[param_1];
}


// ==== FUN_00405ccc @ 00405ccc

undefined * __cdecl FUN_00405ccc(int param_1)

{
  return (&PTR_s_Rainbow_0043e74c)[param_1 * 10];
}


// ==== FUN_00405ce9 @ 00405ce9

int FUN_00405ce9(void)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0044268c + local_8 * 0xd0) == 1) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// ==== FUN_00405d47 @ 00405d47

undefined4 FUN_00405d47(void)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = FUN_00405ce9();
  switch(iVar1) {
  case 1:
    local_8 = 1;
    break;
  case 2:
    local_8 = 2;
    break;
  case 3:
    local_8 = 6;
    break;
  case 4:
    local_8 = 0xc;
    break;
  case 5:
    local_8 = 0x14;
    break;
  case 6:
    local_8 = 0x1e;
  }
  return local_8;
}


// ==== FUN_00405df3 @ 00405df3

undefined4 FUN_00405df3(void)

{
  return 100;
}


// ==== FUN_00405e19 @ 00405e19

undefined4 FUN_00405e19(void)

{
  return 300;
}


// ==== FUN_00405e3f @ 00405e3f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405e3f(void)

{
  DWORD DVar1;
  
  _DAT_00442d20 = GetTickCount();
  DVar1 = GetTickCount();
  FUN_00433010(DVar1);
  return;
}


// ==== FUN_00405e69 @ 00405e69

int __cdecl FUN_00405e69(int param_1)

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


// ==== FUN_00405e9a @ 00405e9a

bool __fastcall FUN_00405e9a(int param_1)

{
  bool bVar1;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x1f810) == 0) {
    local_c = (char *)(param_1 + 4);
  }
  else {
    local_c = (char *)(param_1 + 0xfc0c);
  }
  bVar1 = FUN_0042d6b8(local_c,0xfe,0xfe,(uint *)(param_1 + 0x1f84c));
  return bVar1;
}


// ==== FUN_00405f26 @ 00405f26

bool __thiscall FUN_00405f26(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_00405e9a((int)this);
  bVar1 = CONCAT31(extraout_var,bVar1) != 0;
  if (bVar1) {
    FUN_0042d32b(param_1,(undefined4 *)((int)this + 0x1f84c),0x10);
  }
  return bVar1;
}


// ==== FUN_00405f76 @ 00405f76

undefined4 __thiscall FUN_00405f76(void *this,int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_48;
  int local_3c;
  int local_34;
  undefined4 *local_2c;
  uint local_28;
  uint local_20;
  
  if ((((*(int *)((int)this + 0x1f84c) == -1) || (*(int *)((int)this + 0x1f850) == -1)) ||
      (*(int *)((int)this + 0x1f854) == -1)) || (*(int *)((int)this + 0x1f858) == -1)) {
    *param_1 = 0;
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    local_20 = (uint)(*(int *)((int)this + 0x1f810) == 0);
    if (local_20 == 0) {
      _memset((void *)((int)this + 4),0,0xfc04);
    }
    else {
      _memset((void *)((int)this + 0xfc0c),0,0xfc04);
    }
    iVar2 = (0xfe - ((*(int *)((int)this + 0x1f854) - *(int *)((int)this + 0x1f84c)) + 1)) / 2;
    iVar3 = (0xfe - ((*(int *)((int)this + 0x1f858) - *(int *)((int)this + 0x1f850)) + 1)) / 2;
    iVar2 = iVar2 + (*(int *)((int)this + 0x1f84c) % 10 - iVar2 % 10);
    iVar3 = iVar3 + (*(int *)((int)this + 0x1f850) % 0xf - iVar3 % 0xf);
    iVar4 = iVar2 - *(int *)((int)this + 0x1f84c);
    iVar5 = iVar3 - *(int *)((int)this + 0x1f850);
    if (((*(int *)((int)this + 0x1f84c) == -1) || (*(int *)((int)this + 0x1f850) == -1)) ||
       ((*(int *)((int)this + 0x1f854) == -1 || (*(int *)((int)this + 0x1f858) == -1)))) {
      local_2c = (undefined4 *)0x0;
    }
    else {
      if (*(int *)((int)this + 0x1f810) == 0) {
        local_3c = (int)this + 4;
      }
      else {
        local_3c = (int)this + 0xfc0c;
      }
      local_2c = (undefined4 *)
                 (*(int *)((int)this + 0x1f850) * 0xfe + *(int *)((int)this + 0x1f84c) + local_3c);
    }
    if (((*(int *)((int)this + 0x1f84c) == -1) || (*(int *)((int)this + 0x1f850) == -1)) ||
       ((*(int *)((int)this + 0x1f854) == -1 || (*(int *)((int)this + 0x1f858) == -1)))) {
      local_28 = 0;
    }
    else {
      local_28 = ((*(int *)((int)this + 0x1f858) * 0xfe + *(int *)((int)this + 0x1f854)) -
                 (*(int *)((int)this + 0x1f850) * 0xfe + *(int *)((int)this + 0x1f84c))) + 1;
    }
    if (local_20 == 0xffffffff) {
      if (*(int *)((int)this + 0x1f810) == 0) {
        local_34 = (int)this + 4;
      }
      else {
        local_34 = (int)this + 0xfc0c;
      }
    }
    else if (local_20 == 0) {
      local_34 = (int)this + 4;
    }
    else {
      local_34 = (int)this + 0xfc0c;
    }
    FUN_0042d32b((undefined4 *)(iVar3 * 0xfe + iVar2 + local_34),local_2c,local_28);
    *(int *)((int)this + 0x1f824) = *(int *)((int)this + 0x1f824) + iVar4;
    *(int *)((int)this + 0x1f828) = *(int *)((int)this + 0x1f828) + iVar5;
    *(int *)((int)this + 0x1f834) = *(int *)((int)this + 0x1f834) + iVar4;
    *(int *)((int)this + 0x1f838) = *(int *)((int)this + 0x1f838) + iVar5;
    *(int *)((int)this + 0x1f83c) = *(int *)((int)this + 0x1f83c) + iVar4;
    *(int *)((int)this + 0x1f840) = *(int *)((int)this + 0x1f840) + iVar5;
    *(int *)((int)this + 0x1f84c) = iVar2;
    *(int *)((int)this + 0x1f854) = *(int *)((int)this + 0x1f854) + iVar4;
    *(int *)((int)this + 0x1f850) = iVar3;
    *(int *)((int)this + 0x1f858) = *(int *)((int)this + 0x1f858) + iVar5;
    *(uint *)((int)this + 0x1f810) = local_20;
    piVar6 = (int *)FUN_0042d730();
    if (*(int *)((int)this + 0x1f810) == 0) {
      local_48 = (int)this + 4;
    }
    else {
      local_48 = (int)this + 0xfc0c;
    }
    *piVar6 = local_48;
    *param_1 = iVar4;
    *param_2 = iVar5;
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0040643a @ 0040643a

undefined4 __thiscall FUN_0040643a(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)((int)this + 0x1f910) * *(int *)((int)this + 0x1f914) < 0) {
    if (((param_1 < 0x88) && (0x86 < param_2)) || ((param_1 < 0x13c && (0x13a < param_2)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (((param_1 < 0x2e) && (0x2c < param_2)) || ((param_1 < 0xe2 && (0xe0 < param_2)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_004064fb @ 004064fb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004064fb(void *this,HDC param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  short *local_c0;
  char *local_98;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30 [4];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  if (DAT_0043e8bc != 0) {
    if (*(int *)((int)this + 0x1f85c) == 0) {
      local_30[0] = -1;
      bVar1 = FUN_0042ee69((void *)((int)this + 0x1f814),local_30);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        local_c0 = this;
        if (*(int *)((int)this + 0x1f810) != 0) {
          local_c0 = (short *)((int)this + 0xfc08);
        }
        FUN_0042e519((void *)((int)this + 0x1f814),local_c0,*(int *)((int)this + 0x1f868),
                     *(int *)((int)this + 0x1f86c),0,0);
      }
      if (*(int *)((int)this + 0x1f908) <= *(int *)((int)this + 0x1f904)) {
        if (*(int *)((int)this + 0x1f810) == 0) {
          local_98 = (char *)((int)this + 4);
        }
        else {
          local_98 = (char *)((int)this + 0xfc0c);
        }
        FUN_0042d62c(local_98,0xfc04,*(char *)(*(int *)((int)this + 0x1f900) + 0x1f8b4 + (int)this))
        ;
        *(int *)((int)this + 0x1f900) = *(int *)((int)this + 0x1f900) + 1;
        if (*(int *)((int)this + 0x1f908) <= *(int *)((int)this + 0x1f900)) {
          *(undefined4 *)((int)this + 0x1f900) = 0;
        }
        *(int *)((int)this + 0x1f904) = *(int *)((int)this + 0x1f904) + -1;
      }
      local_70 = *(int *)((int)this + 0x1f910);
      local_34 = *(int *)((int)this + 0x1f914);
      local_1c = *(int *)((int)this + 0x1f82c) + *(int *)((int)this + 0x1f910);
      local_20 = *(int *)((int)this + 0x1f830) + *(int *)((int)this + 0x1f914);
      *(int *)((int)this + 0x1f82c) = local_1c;
      *(int *)((int)this + 0x1f830) = local_20;
      if (((((local_1c <= DAT_004830f8) || (DAT_00483100 <= local_1c)) || (local_20 <= DAT_004830fc)
           ) || (DAT_00483104 <= local_20)) && (_DAT_0048789c = 0xffffffff, DAT_00486c40 != 0)) {
        iVar2 = FUN_00405e69(6);
        *(char *)(*(int *)((int)this + 0x1f90c) + 0x1f880 + (int)this) = (char)iVar2;
      }
      if ((local_1c <= DAT_004830f8) ||
         ((*(int *)((int)this + 0x1f878) == 2 && (*(int *)((int)this + 0x1f910) < 0)))) {
        if (((*(int *)((int)this + 0x1f910) < 0) && (0 < *(int *)((int)this + 0x1f914))) &&
           (((0x2d < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x87)) ||
            ((0xe1 < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x13b)))))) {
          if (*(int *)((int)this + 0x1f90c) == 0) {
            *(undefined4 *)((int)this + 0x1f90c) = 1;
          }
          else {
            *(undefined4 *)((int)this + 0x1f90c) = 0;
          }
        }
        *(int *)((int)this + 0x1f910) = -*(int *)((int)this + 0x1f910);
        *(undefined4 *)((int)this + 0x1f878) = 0xffffffff;
      }
      if ((DAT_00483100 <= local_1c) ||
         ((*(int *)((int)this + 0x1f878) == 0 && (0 < *(int *)((int)this + 0x1f910))))) {
        if (((0 < *(int *)((int)this + 0x1f910)) && (*(int *)((int)this + 0x1f914) < 0)) &&
           (((0x2d < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x87)) ||
            ((0xe1 < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x13b)))))) {
          if (*(int *)((int)this + 0x1f90c) == 0) {
            *(undefined4 *)((int)this + 0x1f90c) = 1;
          }
          else {
            *(undefined4 *)((int)this + 0x1f90c) = 0;
          }
        }
        *(int *)((int)this + 0x1f910) = -*(int *)((int)this + 0x1f910);
        *(undefined4 *)((int)this + 0x1f878) = 0xffffffff;
      }
      if ((local_20 <= DAT_004830fc) ||
         ((*(int *)((int)this + 0x1f878) == 3 && (*(int *)((int)this + 0x1f914) < 0)))) {
        if (((*(int *)((int)this + 0x1f910) < 0) && (*(int *)((int)this + 0x1f914) < 0)) &&
           (((0x13b < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x2d)) ||
            ((0x87 < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0xe1)))))) {
          if (*(int *)((int)this + 0x1f90c) == 0) {
            *(undefined4 *)((int)this + 0x1f90c) = 1;
          }
          else {
            *(undefined4 *)((int)this + 0x1f90c) = 0;
          }
        }
        *(int *)((int)this + 0x1f914) = -*(int *)((int)this + 0x1f914);
        *(undefined4 *)((int)this + 0x1f878) = 0xffffffff;
      }
      if ((DAT_00483104 <= local_20) ||
         ((*(int *)((int)this + 0x1f878) == 1 && (0 < *(int *)((int)this + 0x1f914))))) {
        if (((0 < *(int *)((int)this + 0x1f910)) && (0 < *(int *)((int)this + 0x1f914))) &&
           (((0x13b < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0x2d)) ||
            ((0x87 < *(int *)((int)this + 0x1f918) && (*(int *)((int)this + 0x1f918) < 0xe1)))))) {
          if (*(int *)((int)this + 0x1f90c) == 0) {
            *(undefined4 *)((int)this + 0x1f90c) = 1;
          }
          else {
            *(undefined4 *)((int)this + 0x1f90c) = 0;
          }
        }
        *(int *)((int)this + 0x1f914) = -*(int *)((int)this + 0x1f914);
        *(undefined4 *)((int)this + 0x1f878) = 0xffffffff;
      }
      if ((((*(int *)((int)this + 0x1f84c) != -1) && (*(int *)((int)this + 0x1f850) != -1)) &&
          (*(int *)((int)this + 0x1f854) != -1)) && (*(int *)((int)this + 0x1f858) != -1)) {
        *(undefined4 *)((int)this + 0x1f844) = *(undefined4 *)((int)this + 0x1f84c);
        *(undefined4 *)((int)this + 0x1f848) = *(undefined4 *)((int)this + 0x1f850);
      }
      local_1c = *(int *)((int)this + 0x1f824) + local_70;
      local_20 = *(int *)((int)this + 0x1f828) + local_34;
      *(int *)((int)this + 0x1f824) = local_1c;
      *(int *)((int)this + 0x1f828) = local_20;
      local_18 = (*(int *)((int)this + 0x1f918) + *(int *)((int)this + 0x1f91c)) % 0x168;
      iVar2 = FUN_0040643a(this,*(int *)((int)this + 0x1f918),local_18);
      if (iVar2 == 0) {
        DAT_00483188 = 0;
      }
      else if (DAT_00483188 == 0) {
        if (*(int *)((int)this + 0x1f90c) == 0) {
          *(undefined4 *)((int)this + 0x1f90c) = 1;
        }
        else {
          *(undefined4 *)((int)this + 0x1f90c) = 0;
        }
        DAT_00483188 = 1;
      }
      *(int *)((int)this + 0x1f918) = local_18;
      local_14 = (local_18 + 0xb4) % 0x168;
      local_90 = *(int *)(&DAT_004420a8 + local_18 * 4) + local_1c;
      local_8c = *(int *)(&DAT_004864d8 + local_18 * 4) + local_20;
      local_88 = *(int *)(&DAT_004420a8 + local_14 * 4) + local_1c;
      local_84 = *(int *)(&DAT_004864d8 + local_14 * 4) + local_20;
      iVar2 = FUN_00407448((char)*(undefined4 *)((int)this + 0x1f8fc),*(int *)((int)this + 0x1f90c))
      ;
      _local_8 = CONCAT31(uStack_7,(char)iVar2);
      *(char *)(*(int *)((int)this + 0x1f8fc) + 0x1f8b4 + (int)this) = (char)iVar2;
      *(int *)((int)this + 0x1f8fc) = *(int *)((int)this + 0x1f8fc) + 1;
      if (*(int *)((int)this + 0x1f908) <= *(int *)((int)this + 0x1f8fc)) {
        *(undefined4 *)((int)this + 0x1f8fc) = 0;
      }
      *(int *)((int)this + 0x1f904) = *(int *)((int)this + 0x1f904) + 1;
      if (((((local_90 < 0) || (0xfd < local_90)) ||
           ((local_8c < 0 || ((0xfd < local_8c || (local_88 < 0)))))) || (0xfd < local_88)) ||
         ((local_84 < 0 || (0xfd < local_84)))) {
        FUN_00405f76(this,&local_c,&local_10);
        local_90 = local_90 + local_c;
        local_8c = local_8c + local_10;
        local_88 = local_88 + local_c;
        local_84 = local_84 + local_10;
        *(int *)((int)this + 0x1f844) = *(int *)((int)this + 0x1f844) + local_c;
        *(int *)((int)this + 0x1f848) = *(int *)((int)this + 0x1f848) + local_10;
      }
      local_5c = *(int *)((int)this + 0x1f834);
      local_58 = *(undefined4 *)((int)this + 0x1f838);
      local_54 = *(undefined4 *)((int)this + 0x1f83c);
      local_50 = *(undefined4 *)((int)this + 0x1f840);
      local_4c = local_88;
      local_48 = local_84;
      local_44 = local_90;
      local_40 = local_8c;
      local_3c = *(undefined4 *)((int)this + 0x1f834);
      local_38 = *(undefined4 *)((int)this + 0x1f838);
      FUN_0042d831(&local_5c,5,(char)_local_8);
      FUN_00405e9a((int)this);
      *(int *)((int)this + 0x1f834) = local_90;
      *(int *)((int)this + 0x1f838) = local_8c;
      *(int *)((int)this + 0x1f83c) = local_88;
      *(int *)((int)this + 0x1f840) = local_84;
      iVar2 = (*(int *)((int)this + 0x1f82c) - *(int *)((int)this + 0x1f824)) +
              *(int *)((int)this + 0x1f84c);
      iVar3 = (*(int *)((int)this + 0x1f830) - *(int *)((int)this + 0x1f828)) +
              *(int *)((int)this + 0x1f850);
      local_64 = (*(int *)((int)this + 0x1f854) + iVar2) - *(int *)((int)this + 0x1f84c);
      local_60 = (*(int *)((int)this + 0x1f858) + iVar3) - *(int *)((int)this + 0x1f850);
      local_6c = iVar2;
      local_68 = iVar3;
      FUN_0042d358(&local_80,&DAT_004830f8,&local_6c);
      FUN_0042df38((void *)((int)this + 0x1f814),local_80,local_7c,local_78,local_74,0);
      *(int *)((int)this + 0x1f868) = (*(int *)((int)this + 0x1f84c) + local_80) - local_6c;
      *(int *)((int)this + 0x1f86c) = (*(int *)((int)this + 0x1f850) + local_7c) - local_68;
      FUN_00408263(this,iVar2,iVar3);
      if (local_30[0] == -1) {
        iVar2 = FUN_0042d61b((int)&local_80);
        iVar3 = FUN_0042d60b(&local_80);
        hdc = CreateCompatibleDC(param_1);
        h = SelectObject(hdc,DAT_0048d6a0);
        BitBlt(param_1,local_80,local_7c,iVar3,iVar2,hdc,local_80,local_7c,0xcc0020);
        SelectObject(hdc,h);
        DeleteDC(hdc);
        GdiFlush();
      }
      else {
        FUN_0042a8ff(&DAT_0048d0f0,local_30,&local_80,param_1);
      }
    }
    else {
      _memset((void *)((int)this + 4),0,0xfc04);
      _memset((void *)((int)this + 0xfc0c),0,0xfc04);
      *(undefined4 *)((int)this + 0x1f824) = 0x7f;
      *(undefined4 *)((int)this + 0x1f828) = 0x7f;
      *(undefined4 *)((int)this + 0x1f918) = 0;
      *(int *)((int)this + 0x1f834) = *(int *)((int)this + 0x1f824) + 0x17;
      *(int *)((int)this + 0x1f83c) = *(int *)((int)this + 0x1f824) + -0x17;
      *(undefined4 *)((int)this + 0x1f838) = *(undefined4 *)((int)this + 0x1f828);
      *(undefined4 *)((int)this + 0x1f840) = *(undefined4 *)((int)this + 0x1f828);
      *(undefined4 *)((int)this + 0x1f864) = 0;
      *(undefined4 *)((int)this + 0x1f84c) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f850) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f854) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f858) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f844) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f848) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f8fc) = 0;
      *(undefined4 *)((int)this + 0x1f900) = 0;
      *(undefined4 *)((int)this + 0x1f904) = 0;
      *(undefined4 *)((int)this + 0x1f878) = 0xffffffff;
      *(undefined4 *)((int)this + 0x1f85c) = 0;
    }
  }
  return 1;
}


// ==== FUN_00407448 @ 00407448

int __cdecl FUN_00407448(char param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = param_1 + 1;
  }
  else {
    iVar1 = param_1 + 0x65;
  }
  return iVar1;
}


// ==== FUN_00407473 @ 00407473

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00407473(short *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  short *local_a4;
  short *local_98;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30 [4];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 local_8;
  
  if (DAT_0043e8bc != 0) {
    if (*(int *)(param_1 + 0xfc2e) == 0) {
      local_30[0] = -1;
      bVar1 = FUN_0042ee69(param_1 + 0xfc0a,local_30);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        local_a4 = param_1;
        if (*(int *)(param_1 + 0xfc08) != 0) {
          local_a4 = param_1 + 0x7e04;
        }
        FUN_0042e519(param_1 + 0xfc0a,local_a4,*(int *)(param_1 + 0xfc34),*(int *)(param_1 + 0xfc36)
                     ,0,0);
      }
      if (*(int *)(param_1 + 0xfc84) <= *(int *)(param_1 + 0xfc82)) {
        if (*(int *)(param_1 + 0xfc08) == 0) {
          local_98 = param_1 + 2;
        }
        else {
          local_98 = param_1 + 0x7e06;
        }
        FUN_0042d62c((char *)local_98,0xfc04,
                     *(char *)(*(int *)(param_1 + 0xfc80) + 0x1f8b4 + (int)param_1));
        *(int *)(param_1 + 0xfc80) = *(int *)(param_1 + 0xfc80) + 1;
        if (*(int *)(param_1 + 0xfc84) <= *(int *)(param_1 + 0xfc80)) {
          param_1[0xfc80] = 0;
          param_1[0xfc81] = 0;
        }
        *(int *)(param_1 + 0xfc82) = *(int *)(param_1 + 0xfc82) + -1;
      }
      local_70 = *(int *)(param_1 + 0xfc88);
      local_34 = *(int *)(param_1 + 0xfc8a);
      local_1c = *(int *)(param_1 + 0xfc16) + *(int *)(param_1 + 0xfc88);
      local_20 = *(int *)(param_1 + 0xfc18) + *(int *)(param_1 + 0xfc8a);
      *(int *)(param_1 + 0xfc16) = local_1c;
      *(int *)(param_1 + 0xfc18) = local_20;
      if (((((local_1c <= DAT_004830f8) || (DAT_00483100 <= local_1c)) || (local_20 <= DAT_004830fc)
           ) || (DAT_00483104 <= local_20)) && (_DAT_0048789c = 0xffffffff, DAT_00486c40 != 0)) {
        iVar2 = FUN_00405e69(6);
        *(char *)(*(int *)(param_1 + 0xfc86) + 0x1f880 + (int)param_1) = (char)iVar2;
      }
      if ((local_1c <= DAT_004830f8) ||
         ((*(int *)(param_1 + 0xfc3c) == 2 && (*(int *)(param_1 + 0xfc88) < 0)))) {
        if (((*(int *)(param_1 + 0xfc88) < 0) && (0 < *(int *)(param_1 + 0xfc8a))) &&
           (((0x2d < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x87)) ||
            ((0xe1 < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x13b)))))) {
          if (*(int *)(param_1 + 0xfc86) == 0) {
            param_1[0xfc86] = 1;
            param_1[0xfc87] = 0;
          }
          else {
            param_1[0xfc86] = 0;
            param_1[0xfc87] = 0;
          }
        }
        *(int *)(param_1 + 0xfc88) = -*(int *)(param_1 + 0xfc88);
        param_1[0xfc3c] = -1;
        param_1[0xfc3d] = -1;
      }
      if ((DAT_00483100 <= local_1c) ||
         ((*(int *)(param_1 + 0xfc3c) == 0 && (0 < *(int *)(param_1 + 0xfc88))))) {
        if (((0 < *(int *)(param_1 + 0xfc88)) && (*(int *)(param_1 + 0xfc8a) < 0)) &&
           (((0x2d < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x87)) ||
            ((0xe1 < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x13b)))))) {
          if (*(int *)(param_1 + 0xfc86) == 0) {
            param_1[0xfc86] = 1;
            param_1[0xfc87] = 0;
          }
          else {
            param_1[0xfc86] = 0;
            param_1[0xfc87] = 0;
          }
        }
        *(int *)(param_1 + 0xfc88) = -*(int *)(param_1 + 0xfc88);
        param_1[0xfc3c] = -1;
        param_1[0xfc3d] = -1;
      }
      if ((local_20 <= DAT_004830fc) ||
         ((*(int *)(param_1 + 0xfc3c) == 3 && (*(int *)(param_1 + 0xfc8a) < 0)))) {
        if (((*(int *)(param_1 + 0xfc88) < 0) && (*(int *)(param_1 + 0xfc8a) < 0)) &&
           (((0x13b < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x2d)) ||
            ((0x87 < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0xe1)))))) {
          if (*(int *)(param_1 + 0xfc86) == 0) {
            param_1[0xfc86] = 1;
            param_1[0xfc87] = 0;
          }
          else {
            param_1[0xfc86] = 0;
            param_1[0xfc87] = 0;
          }
        }
        *(int *)(param_1 + 0xfc8a) = -*(int *)(param_1 + 0xfc8a);
        param_1[0xfc3c] = -1;
        param_1[0xfc3d] = -1;
      }
      if ((DAT_00483104 <= local_20) ||
         ((*(int *)(param_1 + 0xfc3c) == 1 && (0 < *(int *)(param_1 + 0xfc8a))))) {
        if (((0 < *(int *)(param_1 + 0xfc88)) && (0 < *(int *)(param_1 + 0xfc8a))) &&
           (((0x13b < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0x2d)) ||
            ((0x87 < *(int *)(param_1 + 0xfc8c) && (*(int *)(param_1 + 0xfc8c) < 0xe1)))))) {
          if (*(int *)(param_1 + 0xfc86) == 0) {
            param_1[0xfc86] = 1;
            param_1[0xfc87] = 0;
          }
          else {
            param_1[0xfc86] = 0;
            param_1[0xfc87] = 0;
          }
        }
        *(int *)(param_1 + 0xfc8a) = -*(int *)(param_1 + 0xfc8a);
        param_1[0xfc3c] = -1;
        param_1[0xfc3d] = -1;
      }
      if ((((*(int *)(param_1 + 0xfc26) != -1) && (*(int *)(param_1 + 0xfc28) != -1)) &&
          (*(int *)(param_1 + 0xfc2a) != -1)) && (*(int *)(param_1 + 0xfc2c) != -1)) {
        *(undefined4 *)(param_1 + 0xfc22) = *(undefined4 *)(param_1 + 0xfc26);
        *(undefined4 *)(param_1 + 0xfc24) = *(undefined4 *)(param_1 + 0xfc28);
      }
      local_1c = *(int *)(param_1 + 0xfc12) + local_70;
      local_20 = *(int *)(param_1 + 0xfc14) + local_34;
      *(int *)(param_1 + 0xfc12) = local_1c;
      *(int *)(param_1 + 0xfc14) = local_20;
      local_18 = (*(int *)(param_1 + 0xfc8c) + *(int *)(param_1 + 0xfc8e)) % 0x168;
      iVar2 = FUN_0040643a(param_1,*(int *)(param_1 + 0xfc8c),local_18);
      if (iVar2 == 0) {
        DAT_00483188 = 0;
      }
      else if (DAT_00483188 == 0) {
        if (*(int *)(param_1 + 0xfc86) == 0) {
          param_1[0xfc86] = 1;
          param_1[0xfc87] = 0;
        }
        else {
          param_1[0xfc86] = 0;
          param_1[0xfc87] = 0;
        }
        DAT_00483188 = 1;
      }
      *(int *)(param_1 + 0xfc8c) = local_18;
      local_14 = (local_18 + 0xb4) % 0x168;
      local_90 = *(int *)(&DAT_004420a8 + local_18 * 4) + local_1c;
      local_8c = *(int *)(&DAT_004864d8 + local_18 * 4) + local_20;
      local_88 = *(int *)(&DAT_004420a8 + local_14 * 4) + local_1c;
      local_84 = *(int *)(&DAT_004864d8 + local_14 * 4) + local_20;
      iVar2 = FUN_00407448((char)*(undefined4 *)(param_1 + 0xfc7e),*(int *)(param_1 + 0xfc86));
      local_8 = (undefined1)iVar2;
      *(undefined1 *)(*(int *)(param_1 + 0xfc7e) + 0x1f8b4 + (int)param_1) = local_8;
      *(int *)(param_1 + 0xfc7e) = *(int *)(param_1 + 0xfc7e) + 1;
      if (*(int *)(param_1 + 0xfc84) <= *(int *)(param_1 + 0xfc7e)) {
        param_1[0xfc7e] = 0;
        param_1[0xfc7f] = 0;
      }
      *(int *)(param_1 + 0xfc82) = *(int *)(param_1 + 0xfc82) + 1;
      if (((((local_90 < 0) || (0xfd < local_90)) ||
           ((local_8c < 0 || ((0xfd < local_8c || (local_88 < 0)))))) || (0xfd < local_88)) ||
         ((local_84 < 0 || (0xfd < local_84)))) {
        FUN_00405f76(param_1,&local_c,&local_10);
        local_90 = local_90 + local_c;
        local_8c = local_8c + local_10;
        local_88 = local_88 + local_c;
        local_84 = local_84 + local_10;
        *(int *)(param_1 + 0xfc22) = *(int *)(param_1 + 0xfc22) + local_c;
        *(int *)(param_1 + 0xfc24) = *(int *)(param_1 + 0xfc24) + local_10;
      }
      local_5c = *(undefined4 *)(param_1 + 0xfc1a);
      local_58 = *(undefined4 *)(param_1 + 0xfc1c);
      local_54 = *(undefined4 *)(param_1 + 0xfc1e);
      local_50 = *(undefined4 *)(param_1 + 0xfc20);
      local_4c = local_88;
      local_48 = local_84;
      local_44 = local_90;
      local_40 = local_8c;
      local_3c = *(undefined4 *)(param_1 + 0xfc1a);
      local_38 = *(undefined4 *)(param_1 + 0xfc1c);
      FUN_00405e9a((int)param_1);
      *(int *)(param_1 + 0xfc1a) = local_90;
      *(int *)(param_1 + 0xfc1c) = local_8c;
      *(int *)(param_1 + 0xfc1e) = local_88;
      *(int *)(param_1 + 0xfc20) = local_84;
      local_6c = (*(int *)(param_1 + 0xfc16) - *(int *)(param_1 + 0xfc12)) +
                 *(int *)(param_1 + 0xfc26);
      local_68 = (*(int *)(param_1 + 0xfc18) - *(int *)(param_1 + 0xfc14)) +
                 *(int *)(param_1 + 0xfc28);
      local_64 = (*(int *)(param_1 + 0xfc2a) + local_6c) - *(int *)(param_1 + 0xfc26);
      local_60 = (*(int *)(param_1 + 0xfc2c) + local_68) - *(int *)(param_1 + 0xfc28);
      FUN_0042d358(&local_80,&DAT_004830f8,&local_6c);
      *(int *)(param_1 + 0xfc34) = (*(int *)(param_1 + 0xfc26) + local_80) - local_6c;
      *(int *)(param_1 + 0xfc36) = (*(int *)(param_1 + 0xfc28) + local_7c) - local_68;
    }
    else {
      _memset(param_1 + 2,0,0xfc04);
      _memset(param_1 + 0x7e06,0,0xfc04);
      param_1[0xfc12] = 0x7f;
      param_1[0xfc13] = 0;
      param_1[0xfc14] = 0x7f;
      param_1[0xfc15] = 0;
      param_1[0xfc8c] = 0;
      param_1[0xfc8d] = 0;
      *(int *)(param_1 + 0xfc1a) = *(int *)(param_1 + 0xfc12) + 0x17;
      *(int *)(param_1 + 0xfc1e) = *(int *)(param_1 + 0xfc12) + -0x17;
      *(undefined4 *)(param_1 + 0xfc1c) = *(undefined4 *)(param_1 + 0xfc14);
      *(undefined4 *)(param_1 + 0xfc20) = *(undefined4 *)(param_1 + 0xfc14);
      param_1[0xfc32] = 0;
      param_1[0xfc33] = 0;
      param_1[0xfc26] = -1;
      param_1[0xfc27] = -1;
      param_1[0xfc28] = -1;
      param_1[0xfc29] = -1;
      param_1[0xfc2a] = -1;
      param_1[0xfc2b] = -1;
      param_1[0xfc2c] = -1;
      param_1[0xfc2d] = -1;
      param_1[0xfc22] = -1;
      param_1[0xfc23] = -1;
      param_1[0xfc24] = -1;
      param_1[0xfc25] = -1;
      param_1[0xfc7e] = 0;
      param_1[0xfc7f] = 0;
      param_1[0xfc80] = 0;
      param_1[0xfc81] = 0;
      param_1[0xfc82] = 0;
      param_1[0xfc83] = 0;
      param_1[0xfc3c] = -1;
      param_1[0xfc3d] = -1;
      param_1[0xfc2e] = 0;
      param_1[0xfc2f] = 0;
    }
  }
  return 1;
}


// ==== FUN_00408263 @ 00408263

void __thiscall FUN_00408263(void *this,int param_1,int param_2)

{
  int iVar1;
  short *local_30;
  short *local_c;
  
  DAT_0048d684 = DAT_004830f8;
  DAT_0048d688 = DAT_004830fc;
  DAT_0048d68c = DAT_00483100;
  DAT_0048d690 = DAT_00483104;
  *(int *)((int)this + 0x1f870) =
       (((*(int *)((int)this + 0x1f84c) + *(int *)((int)this + 0x1f870)) -
        *(int *)((int)this + 0x1f844)) + 0x14) % 10;
  iVar1 = FUN_00405e69(3);
  *(int *)((int)this + 0x1f870) = (*(int *)((int)this + 0x1f870) + iVar1 + 9) % 10;
  *(int *)((int)this + 0x1f874) =
       (((*(int *)((int)this + 0x1f850) + *(int *)((int)this + 0x1f874)) -
        *(int *)((int)this + 0x1f848)) + 0x1e) % 0xf;
  iVar1 = FUN_00405e69(3);
  *(int *)((int)this + 0x1f874) = (*(int *)((int)this + 0x1f874) + iVar1 + 0xe) % 0xf;
  if (*(int *)((int)this + 0x1f87c) == 2) {
    local_30 = this;
    if (*(int *)((int)this + 0x1f810) != 0) {
      local_30 = (short *)((int)this + 0xfc08);
    }
    FUN_0042ad0a(&DAT_0048d0f0,param_1,param_2,*(int *)((int)this + 0x1f84c),
                 *(int *)((int)this + 0x1f850),
                 (*(int *)((int)this + 0x1f854) - *(int *)((int)this + 0x1f84c)) + 1,
                 (*(int *)((int)this + 0x1f858) - *(int *)((int)this + 0x1f850)) + 1,
                 *(int *)((int)this + 0x1f870),*(int *)((int)this + 0x1f874),local_30,
                 *(short **)((int)this + *(char *)((int)this + 0x1f880) * 8 + 0x1f884),
                 *(int *)((int)this + *(char *)((int)this + 0x1f881) * 8 + 0x1f884));
  }
  else {
    local_c = this;
    if (*(int *)((int)this + 0x1f810) != 0) {
      local_c = (short *)((int)this + 0xfc08);
    }
    FUN_0042ad0a(&DAT_0048d0f0,param_1,param_2,*(int *)((int)this + 0x1f84c),
                 *(int *)((int)this + 0x1f850),
                 (*(int *)((int)this + 0x1f854) - *(int *)((int)this + 0x1f84c)) + 1,
                 (*(int *)((int)this + 0x1f858) - *(int *)((int)this + 0x1f850)) + 1,
                 *(int *)((int)this + 0x1f870),*(int *)((int)this + 0x1f874),local_c,
                 *(short **)((int)this + *(char *)((int)this + 0x1f880) * 8 + 0x1f884),
                 *(int *)((int)this + *(char *)((int)this + 0x1f880) * 8 + 0x1f888));
  }
  DAT_0048d684 = 64000;
  return;
}


// ==== FUN_004085c4 @ 004085c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004085c4(void)

{
  HDC hdc;
  
  FUN_00405e3f();
  DAT_00486c40 = 1;
  _DAT_00486b6c = 1;
  DAT_004830f8 = 0;
  DAT_004830fc = 0x74;
  DAT_00483100 = 599;
  DAT_00483104 = 399;
  DAT_00486b80 = 0;
  _DAT_00486b84 = 0;
  _DAT_00486b88 = 0;
  _DAT_004878a0 = 2;
  DAT_00442cf4 = DAT_00480f24;
  DAT_00480f24 = 2;
  _DAT_00480f08 = 0;
  _DAT_00480fc4 = 3;
  if (DAT_00480fb8 < 0) {
    DAT_00480fb8 = 0xfffffffd;
  }
  else {
    DAT_00480fb8 = 3;
  }
  if (DAT_00480fbc < 0) {
    DAT_00480fbc = 0xfffffffd;
  }
  else {
    DAT_00480fbc = 3;
  }
  _DAT_00480fb0 = 0x17;
  FUN_00424a09(&DAT_00486b70);
  hdc = GetDC(DAT_00442cf8);
  SelectPalette(hdc,DAT_0048d10c,0);
  RealizePalette(hdc);
  DAT_0044209c = 1;
  ReleaseDC(DAT_00442cf8,hdc);
  return;
}


// ==== FUN_00408747 @ 00408747

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UINT FUN_00408747(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  int iVar1;
  INT_PTR IVar2;
  UINT UVar3;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  undefined4 local_180;
  HGDIOBJ local_17c;
  HDC local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
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
  undefined4 local_138;
  HGDIOBJ local_134;
  HDC local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  HGDIOBJ local_110;
  HDC local_10c;
  int *local_108;
  int local_104;
  int local_100;
  undefined4 local_fc;
  HGDIOBJ local_f8;
  HDC local_f4;
  int local_f0;
  int local_ec;
  undefined4 local_e8;
  HGDIOBJ local_e4;
  HDC local_e0;
  int *local_dc;
  int local_d8;
  int local_d4;
  undefined4 local_d0;
  HGDIOBJ local_cc;
  HDC local_c8;
  int local_c4;
  undefined2 local_c0;
  undefined2 uStack_be;
  HDC local_8c;
  tagPAINTSTRUCT local_78;
  int local_34;
  UINT local_24;
  int local_1c;
  tagRECT local_18;
  
  local_24 = 0;
  if (param_2 == 0x42b) {
    if ((((DAT_0043d3ac == 0) && (DAT_0043d398 == 0)) && (DAT_0043d3a0 == 0)) &&
       ((DAT_0043d3a8 == 0 && (DAT_0043d39c == 0)))) {
      local_8c = GetDC(param_1);
      SelectPalette(local_8c,DAT_0048d10c,0);
      RealizePalette(local_8c);
      if (DAT_00486c40 == 0) {
        iVar1 = FUN_004057b2();
        if (iVar1 == 0) {
          FUN_00425941(&DAT_00486b70,local_8c);
          if (DAT_0043d3a8 != 0) {
            return 0;
          }
          FUN_00414020(&DAT_00486b70,local_8c);
        }
        else {
          iVar1 = FUN_004057b2();
          if (iVar1 == 1) {
            if (DAT_00444160 == -1) {
              _DAT_00444164 = 0;
              if (DAT_00444140 != (void *)0x0) {
                FUN_004300f3(DAT_00444140,DAT_00444144,DAT_00444148,0x444168,&local_1ac);
                FUN_0042df38(&DAT_0044414c,local_1ac,local_1a8,local_1a4,local_1a0,0);
                FUN_0042f6fc(DAT_00444140,DAT_00444144,DAT_00444148,0x444168,local_8c,0);
              }
              DAT_00444160 = 1;
              _DAT_0044415c = 0x28;
            }
            else if (DAT_00444160 == 0) {
              _DAT_0044415c = _DAT_0044415c + -1;
              if (_DAT_0044415c == 0) {
                _DAT_00444164 = 1;
                if (DAT_00444140 != (void *)0x0) {
                  FUN_004300f3(DAT_00444140,DAT_00444144,DAT_00444148,0x444168,&local_1bc);
                  FUN_0042df38(&DAT_0044414c,local_1bc,local_1b8,local_1b4,local_1b0,0);
                  FUN_0042f6fc(DAT_00444140,DAT_00444144,DAT_00444148,0x444168,local_8c,0);
                }
                DAT_00444160 = 1;
                _DAT_0044415c = 0x28;
              }
            }
            else if ((DAT_00444160 == 1) && (_DAT_0044415c = _DAT_0044415c + -1, _DAT_0044415c == 0)
                    ) {
              FUN_0042eac9(&DAT_0044414c,local_8c,0,0,-0x8000,-0x8000);
              DAT_00444160 = 0;
              _DAT_0044415c = 0x28;
            }
          }
          else {
            iVar1 = FUN_00405828(&DAT_00442090,local_8c);
            if (iVar1 == 0) {
              Sleep(300);
              FUN_0040579a(0);
              DAT_0043d3b4 = DAT_0043d3b8;
            }
          }
        }
      }
      else {
        FUN_0040c140(&DAT_0048d0f0,local_8c);
        PostMessageA(param_1,0x4f7,0,0);
      }
      ReleaseDC(param_1,local_8c);
      if (DAT_0043d3b4 < 2) {
        DAT_0043d3b4 = 0;
      }
      else {
        DAT_0043d3b4 = DAT_0043d3b4 + -1;
      }
      return 0;
    }
    return 0;
  }
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8c = BeginPaint(param_1,&local_78);
      SelectPalette(local_8c,DAT_0048d10c,0);
      RealizePalette(local_8c);
      if ((DAT_0043d3a0 == 0) &&
         (((DAT_0043e8bc != (HWND)0x0 || (DAT_0043d3ac != 0)) || (DAT_0043d3a8 != 0)))) {
        DAT_0048d67c = 0;
        local_fc = DAT_0048d0f0;
        local_100 = DAT_0048d100;
        local_104 = DAT_0048d0fc;
        local_f4 = CreateCompatibleDC(local_8c);
        local_f8 = SelectObject(local_f4,DAT_0048d6a0);
        BitBlt(local_8c,0,0,local_104,local_100,local_f4,0,0,0xcc0020);
        SelectObject(local_f4,local_f8);
        DeleteDC(local_f4);
        GdiFlush();
      }
      else {
        local_18.left = 0;
        local_18.right = 600;
        local_18.top = 0;
        local_18.bottom = 0x8b;
        local_128 = 0;
        local_12c = 0;
        local_118 = 0x8c;
        local_11c = 0x259;
        local_120 = 0;
        local_124 = 0;
        local_114 = DAT_0048d0f0;
        local_10c = CreateCompatibleDC(local_8c);
        local_110 = SelectObject(local_10c,DAT_0048d6a0);
        BitBlt(local_8c,local_12c,local_128,local_11c,local_118,local_10c,local_124,local_120,
               0xcc0020);
        SelectObject(local_10c,local_110);
        DeleteDC(local_10c);
        GdiFlush();
        local_18.left = 0;
        local_18.right = 0x89;
        local_18.top = 0;
        local_18.bottom = 400;
        local_14c = 0;
        local_150 = 0;
        local_13c = 0x191;
        local_140 = 0x8a;
        local_144 = 0;
        local_148 = 0;
        local_138 = DAT_0048d0f0;
        local_130 = CreateCompatibleDC(local_8c);
        local_134 = SelectObject(local_130,DAT_0048d6a0);
        BitBlt(local_8c,local_150,local_14c,local_140,local_13c,local_130,local_148,local_144,
               0xcc0020);
        SelectObject(local_130,local_134);
        DeleteDC(local_130);
        GdiFlush();
        local_18.left = 0x1ce;
        local_18.right = 600;
        local_18.top = 0;
        local_18.bottom = 400;
        local_170 = 0;
        local_174 = 0x1ce;
        local_160 = 0x191;
        local_164 = 0x8b;
        local_168 = 0;
        local_16c = 0x1ce;
        local_15c = DAT_0048d0f0;
        local_154 = CreateCompatibleDC(local_8c);
        local_158 = SelectObject(local_154,DAT_0048d6a0);
        BitBlt(local_8c,local_174,local_170,local_164,local_160,local_154,local_16c,local_168,
               0xcc0020);
        SelectObject(local_154,local_158);
        DeleteDC(local_154);
        GdiFlush();
        local_18.left = 0;
        local_18.right = 600;
        local_18.top = 0x104;
        local_18.bottom = 400;
        local_194 = 0x104;
        local_198 = 0;
        local_184 = 0x8d;
        local_188 = 0x259;
        local_18c = 0x104;
        local_190 = 0;
        local_180 = DAT_0048d0f0;
        local_178 = CreateCompatibleDC(local_8c);
        local_17c = SelectObject(local_178,DAT_0048d6a0);
        BitBlt(local_8c,local_198,local_194,local_188,local_184,local_178,local_190,local_18c,
               0xcc0020);
        SelectObject(local_178,local_17c);
        DeleteDC(local_178);
        GdiFlush();
        FUN_004261fa(local_8c,DAT_004830f4,0x8a,0x8c);
      }
      EndPaint(param_1,&local_78);
      return 0;
    }
    if (param_2 == 1) {
      FUN_004025a1(param_1);
      return 0;
    }
    if (param_2 == 2) {
      FUN_0042f1e8();
      WinHelpA(param_1,s_COLC_HLP_0043d098,2,0);
      FUN_004025e4(param_1);
      PostQuitMessage(0);
      return 0;
    }
    if ((param_2 == 5) && ((param_3 == (HWND)0x0 || (param_3 == (HWND)0x2)))) {
      SendMessageA(param_1,0x464,1,0);
    }
  }
  else if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_0043e8bc = param_3;
      if (param_3 == (HWND)0x0) {
        FUN_0041b879();
        if ((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) {
          DAT_0043d3a0 = 1;
        }
        FUN_00405495();
      }
      else {
        FUN_0041b408();
      }
      if ((param_3 == (HWND)0x0) || (DAT_0043d3a0 != 0)) {
        FUN_0040cc75(0);
      }
      else if (DAT_0043d3ac == 0) {
        FUN_0040cc75(DAT_0043f0c4 + 1);
      }
      else {
        FUN_0040cc75(1);
      }
      _DAT_0043d3a4 = 0;
      InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
      return 0;
    }
    if (param_2 == 0x10) {
      if ((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) {
        IVar2 = FUN_00402862();
        if (IVar2 != 1) {
          return 0;
        }
        iVar1 = FUN_0041b698(DAT_00486b80,&local_1c);
        if ((iVar1 != 0) && (local_1c < 10)) {
          if (DAT_0043f0d4 != 0) {
            FUN_00402b70();
          }
          FUN_0041b735(DAT_00486b80);
          DAT_0043d4e8 = local_1c;
          FUN_00402bdf();
          FUN_0041b879();
        }
      }
      FUN_0041b879();
      FUN_0040d0a5();
      FUN_0040ee1f();
      PostQuitMessage(0);
      return 0;
    }
  }
  else if (param_2 < 0x7f) {
    if (param_2 == 0x7e) {
      Sleep(300);
      GdiFlush();
      DeleteObject(DAT_004830f4);
      local_8c = GetDC((HWND)0x0);
      DAT_004830f4 = FUN_00426290(local_8c,s_PAUSEBMP_0043eb7c);
      ReleaseDC((HWND)0x0,local_8c);
      Sleep(300);
      GdiFlush();
      Sleep(100);
      return 0;
    }
    if (param_2 == 0x24) {
      *(undefined4 *)(param_4 + 8) = DAT_00443640;
      *(undefined4 *)(param_4 + 0xc) = DAT_004441cc;
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_3 == (HWND)0x1b) {
        ShowWindow(DAT_0048cc60,6);
        return 0;
      }
      if ((DAT_0043d3ac != 0) || (DAT_0043d3a8 != 0)) {
        SendMessageA(DAT_00442cf8,0x111,0x65,0);
        return 0;
      }
      if (DAT_0043d3a0 != 0) {
        SendMessageA(DAT_00442cf8,0x111,0xc9,0);
        return 0;
      }
      switch(param_3) {
      case (HWND)0xd:
        if (DAT_00442648 != 0) {
          SendMessageA(param_1,0x111,0xc9,0);
          return 0;
        }
        if (DAT_00486c40 != 0) {
          DAT_00486c40 = 0;
          DAT_0044209c = 0;
          PostMessageA(param_1,0x4f7,0,0);
          return 0;
        }
        if (DAT_0044209c == 0) {
          SendMessageA(param_1,0x111,0x79,0);
          return 0;
        }
        break;
      case (HWND)0x20:
        if (DAT_00442648 != 0) {
          SendMessageA(param_1,0x111,0xc9,0);
          return 0;
        }
        if (DAT_00486c40 != 0) {
          DAT_00486c40 = 0;
          DAT_0044209c = 0;
          PostMessageA(param_1,0x4f7,0,0);
        }
        break;
      case (HWND)0x25:
        if (DAT_00486c40 == 0) {
          _DAT_0048789c = 0xffffffff;
          _DAT_00480f20 = 0;
        }
        break;
      case (HWND)0x26:
        if (DAT_00486c40 == 0) {
          _DAT_0048789c = 0xffffffff;
          _DAT_00480f20 = 1;
        }
        break;
      case (HWND)0x27:
        if (DAT_00486c40 == 0) {
          _DAT_0048789c = 0xffffffff;
          _DAT_00480f20 = 2;
        }
        break;
      case (HWND)0x28:
        if (DAT_00486c40 == 0) {
          _DAT_0048789c = 0xffffffff;
          _DAT_00480f20 = 3;
        }
      }
    }
    else if (param_2 == 0x86) {
      if (param_3 != (HWND)0x0) {
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
      }
      UVar3 = DefWindowProcA(param_1,0x86,(WPARAM)param_3,param_4);
      return UVar3;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if ((DAT_0043d3ac != 0) || (DAT_0043d3a8 != 0)) {
        SendMessageA(DAT_00442cf8,0x111,0x65,0);
      }
      if (DAT_0043d3a0 == 0) {
        return 0;
      }
      SendMessageA(DAT_00442cf8,0x111,0xc9,0);
      return 0;
    }
    if (param_2 == 0x111) {
      _local_c0 = CONCAT22(uStack_be,(short)param_3);
      switch((uint)param_3 & 0xffff) {
      case 0x65:
        if (DAT_00486b74 == 1) {
          DAT_00486b74 = 0;
        }
        if ((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) {
          IVar2 = FUN_0040291d();
          if (IVar2 != 1) {
            return 0;
          }
          iVar1 = FUN_0041b698(DAT_00486b80,&local_1c);
          if ((iVar1 != 0) && (local_1c < 10)) {
            if (DAT_0043f0d4 != 0) {
              FUN_00402b70();
            }
            FUN_0041b735(DAT_00486b80);
            DAT_0043d4e8 = local_1c;
            FUN_00402bdf();
            FUN_0041b879();
          }
        }
        SendMessageA(DAT_0048cc60,0x111,0x132,0);
        FUN_004051b0();
        local_c4 = DAT_0043f0c0 + -1;
        DAT_0043d3b0 = DAT_0043f0c4;
        DAT_0043d3a0 = 0;
        DAT_0043d3ac = 0;
        DAT_0043d3a8 = 0;
        _DAT_00487898 = 0;
        DAT_00486b70 = local_c4;
        for (local_34 = 0; local_34 < 8; local_34 = local_34 + 1) {
          *(undefined4 *)(&DAT_004426fc + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_00442718 + local_34 * 0xd0) = 0;
        }
        FUN_00405495();
        FUN_0040cb98(DAT_0043f0c4 + 1);
      case 0x79:
        _DAT_00487898 = 0;
        for (local_34 = 0; local_34 < 8; local_34 = local_34 + 1) {
          *(undefined4 *)(&DAT_004426fc + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_00442718 + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_00442738 + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_0044273c + local_34 * 0xd0) = 0;
        }
        DAT_0043d3a8 = 0;
        _DAT_00486c34 = 0;
        DAT_00486b80 = 0;
        _DAT_00486b84 = 0;
        _DAT_00486b88 = 0;
        _DAT_004878a0 = 2;
        for (local_19c = 0; local_19c < 10; local_19c = local_19c + 1) {
          *(undefined4 *)(&DAT_00486bd0 + local_19c * 4) = 0;
        }
        FUN_00424a09(&DAT_00486b70);
        local_8c = GetDC(param_1);
        SelectPalette(local_8c,DAT_0048d10c,0);
        RealizePalette(local_8c);
        DAT_0044209c = 1;
        FUN_0042549a(local_8c);
        ReleaseDC(param_1,local_8c);
        if ((((uint)param_3 & 0xffff) == 0x65) && (DAT_0043f0c8 != 0)) {
          FUN_00402ad0();
        }
        if (DAT_0043f0cc != 0) {
          FUN_004027a3(DAT_00486b70 + 1);
        }
        DAT_0043d3b4 = DAT_0043d3b8;
        return 0;
      case 0x66:
        DAT_0043d4e8 = 0xffffffff;
        FUN_00402bdf();
        return 0;
      case 0x67:
        PostMessageA(param_1,0x10,0,0);
        return 0;
      case 0x68:
        FUN_00405599();
        return 0;
      default:
        break;
      case 0xc9:
        if ((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) {
          DAT_0043d3a0 = (uint)(DAT_0043d3a0 == 0);
          FUN_00405495();
          if (DAT_0043d3a0 == 0) {
            FUN_0040cb98(DAT_0043f0c4 + 1);
          }
          else {
            InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
            UpdateWindow(DAT_00442cf8);
            FUN_0040cb25();
          }
          InvalidateRect(DAT_00442cf8,(RECT *)0x0,0);
          if (DAT_0043d3a0 == 0) {
            DAT_0043d3b4 = DAT_0043d3b8;
          }
          return 0;
        }
        SendMessageA(DAT_00442cf8,0x111,0x65,0);
        return 0;
      case 300:
        _DAT_00487898 = 0;
        for (local_34 = 0; local_34 < 8; local_34 = local_34 + 1) {
          *(undefined4 *)(&DAT_004426fc + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_00442718 + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_00442738 + local_34 * 0xd0) = 0;
          *(undefined4 *)(&DAT_0044273c + local_34 * 0xd0) = 0;
        }
        FUN_004057c7(&DAT_00442090,1000);
        FUN_0040579a(2);
        FUN_00424a09(&DAT_00486b70);
        DAT_0044209c = 1;
        FUN_00405ca2();
        local_8c = GetDC(param_1);
        SelectPalette(local_8c,DAT_0048d10c,0);
        RealizePalette(local_8c);
        FUN_0042549a(local_8c);
        ReleaseDC(param_1,local_8c);
        FUN_0040cf73(0x2c);
        if (DAT_0043f0cc != 0) {
          FUN_004027a3(DAT_00486b70 + 1);
        }
        return 0;
      case 0x12e:
        FUN_004029d8();
        return 0;
      case 0x12f:
        WinHelpA(param_1,s_COLC_HLP_0043d098,0xb,0);
        return 0;
      case 0x130:
        FUN_00402ad0();
        return 0;
      case 0x131:
        DAT_0043f0cc = (uint)(DAT_0043f0cc == 0);
        FUN_00405495();
        return 0;
      case 0x132:
        iVar1 = FUN_004057b2();
        if (iVar1 == 1) {
          return 0;
        }
        return 0;
      case 0x136:
        if (DAT_0043f0cc != 0) {
          FUN_004027a3(DAT_00486b70 + 1);
        }
        return 0;
      case 0x137:
        FUN_00405495();
        if (param_4 != 0) {
          FUN_004027a3(0xb);
        }
        iVar1 = FUN_0041b698(DAT_00486b80,&local_1c);
        if ((iVar1 == 0) || (9 < local_1c)) {
          FUN_0040cf73(0x21);
        }
        else {
          FUN_0040cf73(0x22);
          if (DAT_0043f0d4 != 0) {
            FUN_00402b70();
          }
          FUN_0041b735(DAT_00486b80);
          DAT_0043d4e8 = local_1c;
          FUN_00402bdf();
          FUN_0041b879();
        }
        return 0;
      }
    }
    else if (param_2 == 0x113) {
      if ((DAT_0043d3a0 == 0) && (DAT_0043e8bc != (HWND)0x0)) {
        FUN_0040ce55();
      }
      return 0;
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
LAB_00409cdf:
      local_8c = GetDC(param_1);
      if (DAT_0048d10c != (HPALETTE)0x0) {
        SelectPalette(local_8c,DAT_0048d10c,0);
        local_24 = RealizePalette(local_8c);
      }
      ReleaseDC(param_1,local_8c);
      if (local_24 != 0) {
        InvalidateRect(param_1,(RECT *)0x0,1);
        return local_24;
      }
      return 0;
    }
    if (param_2 == 0x211) {
      _DAT_0043d3a4 = 1;
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 == 0x212) {
      _DAT_0043d3a4 = 0;
      InvalidateRect(param_1,(RECT *)0x0,1);
      if (((DAT_0043d3ac == 0) && (DAT_0043d3a8 == 0)) && (DAT_0043d3a0 == 0)) {
        DAT_0043d3b4 = DAT_0043d3b8;
      }
      return 0;
    }
  }
  else if (param_2 < 0x465) {
    if (param_2 == 0x464) {
      return 0;
    }
    if ((param_2 == 0x311) && (param_3 != param_1)) goto LAB_00409cdf;
  }
  else if (param_2 == 0x4f6) {
    if (DAT_0043e8c8 == 0) {
      _DAT_0043e8c4 = 1;
      DAT_00486c40 = 0;
      DAT_0044209c = 0;
      SendMessageA(param_1,0x4f7,0,0);
    }
    else {
      GetWindowRect(param_1,&local_18);
      _DAT_0043e8c4 = 1;
      FUN_004085c4();
    }
  }
  else if (param_2 == 0x4f7) {
    if (DAT_00487a6c != (HGLOBAL)0x0) {
      GlobalFree(DAT_00487a6c);
      DAT_00487a6c = (HGLOBAL)0x0;
    }
    DAT_004830f8 = 0x1d;
    DAT_004830fc = 0x1e;
    DAT_00483100 = 0x245;
    DAT_00483104 = 0x171;
    DAT_00480f24 = DAT_00442cf4;
    _DAT_00486b6c = 0;
    local_8c = GetDC(param_1);
    SelectPalette(local_8c,DAT_0048d10c,0);
    RealizePalette(local_8c);
    if (DAT_0048d684 == 64000) {
      local_18.left = 0;
      local_18.right = DAT_0048d0fc;
      local_18.top = 0;
      local_18.bottom = DAT_0048d100;
    }
    else {
      local_18.left = DAT_0048d684;
      local_18.top = DAT_0048d688;
      local_18.right = DAT_0048d68c;
      local_18.bottom = DAT_0048d690;
    }
    FUN_00429ad5(&DAT_0048d0f0,&local_18.left,0);
    DAT_0048d67c = 0;
    local_d0 = DAT_0048d0f0;
    local_d4 = DAT_0048d100;
    local_d8 = DAT_0048d0fc;
    local_c8 = CreateCompatibleDC(local_8c);
    local_cc = SelectObject(local_c8,DAT_0048d6a0);
    BitBlt(local_8c,0,0,local_d8,local_d4,local_c8,0,0,0xcc0020);
    SelectObject(local_c8,local_cc);
    DeleteDC(local_c8);
    GdiFlush();
    local_dc = DAT_00486b78;
    FUN_00426912(&DAT_0048d0f0,DAT_00486b78);
    SelectPalette(local_8c,DAT_0048d10c,0);
    RealizePalette(local_8c);
    local_108 = DAT_00486b78;
    FUN_00426d1f(&DAT_0048d0f0,0,0,DAT_00486b78,-1);
    DAT_0048d67c = 0;
    local_e8 = DAT_0048d0f0;
    local_ec = DAT_0048d100;
    local_f0 = DAT_0048d0fc;
    local_e0 = CreateCompatibleDC(local_8c);
    local_e4 = SelectObject(local_e0,DAT_0048d6a0);
    BitBlt(local_8c,0,0,local_f0,local_ec,local_e0,0,0,0xcc0020);
    SelectObject(local_e0,local_e4);
    DeleteDC(local_e0);
    GdiFlush();
    ReleaseDC(param_1,local_8c);
  }
  UVar3 = FUN_0042f230(param_1,param_2,(WPARAM)param_3,param_4);
  return UVar3;
}


// ==== FUN_0040a522 @ 0040a522

int __cdecl FUN_0040a522(int param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(0);
  return (iVar1 - param_1) / 2;
}


// ==== FUN_0040a543 @ 0040a543

int __cdecl FUN_0040a543(int param_1)

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


// ==== FUN_0040a57e @ 0040a57e

ATOM __cdecl FUN_0040a57e(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = FUN_00408747;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = param_1;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(5);
  local_2c.hIcon = LoadIconA(param_1,&DAT_0043eb88);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = PTR_s_ShawlGameWnd_0043d090;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1;
}


// ==== FUN_0040a5fc @ 0040a5fc

undefined4 FUN_0040a5fc(void)

{
  HWND hWnd;
  HWND hWnd_00;
  BOOL BVar1;
  undefined4 uVar2;
  
  hWnd = FindWindowA(PTR_s_ShawlGameWnd_0043d090,(LPCSTR)0x0);
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


// ==== FUN_0040a679 @ 0040a679

bool __cdecl FUN_0040a679(size_t param_1)

{
  void *_Dst;
  
  _Dst = _malloc(param_1);
  if (_Dst != (void *)0x0) {
    _memset(_Dst,0,param_1);
    _free(_Dst);
  }
  return _Dst != (void *)0x0;
}


// ==== FUN_0040a6cf @ 0040a6cf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_0040a6cf(HINSTANCE param_1)

{
  bool bVar1;
  ATOM AVar2;
  int iVar3;
  DWORD DVar4;
  undefined3 extraout_var;
  HCURSOR hCursor;
  undefined2 extraout_var_00;
  BOOL BVar5;
  tagMSG local_54;
  HDC local_34;
  undefined4 local_30;
  HCURSOR local_24;
  DWORD local_20;
  HDC local_1c;
  undefined4 local_18;
  undefined4 local_14;
  DWORD local_10;
  DWORD local_8;
  
  local_18 = 0;
  local_14 = 0;
  DAT_00483518 = param_1;
  iVar3 = FUN_0040a5fc();
  if (iVar3 == 0) {
    CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s_ColcGameMtx_0043eb90);
    DVar4 = GetLastError();
    if (DVar4 == 0xb7) {
      local_54.wParam = 0;
    }
    else {
      bVar1 = FUN_0040a679(0x600000);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        local_54.wParam = 0;
      }
      else {
        local_1c = GetDC((HWND)0x0);
        iVar3 = GetDeviceCaps(local_1c,0xc);
        if (iVar3 < 8) {
          ReleaseDC((HWND)0x0,local_1c);
          local_54.wParam = 0;
        }
        else {
          ReleaseDC((HWND)0x0,local_1c);
          hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
          local_24 = SetCursor(hCursor);
          FUN_0040e9dd();
          FUN_0040ea77((uint *)s_COLC_DLL_0043d198);
          FUN_0040ec25((uint *)s_COLC1_DLL_0043d298);
          FUN_0040e9f5((uint *)s_MSPuzzle_dat_0043f108);
          FUN_0040ec25((uint *)s_COLC_HLP_0043d098);
          FUN_0040e80a();
          FUN_0040e824(DAT_00483518);
          FUN_0040e863(s_COLC1_DLL_0043d298);
          FUN_0040e863(s_COLC_DLL_0043d198);
          FUN_0040547b();
          FUN_0040d2c6();
          InitCommonControls();
          AVar2 = FUN_0040a57e(param_1);
          if (CONCAT22(extraout_var_00,AVar2) == 0) {
            FUN_0040d0a5();
            SetCursor(local_24);
            local_54.wParam = 0;
          }
          else {
            iVar3 = FUN_0040ac51();
            if (iVar3 == 0) {
              FUN_0040d0a5();
              SetCursor(local_24);
              local_54.wParam = 0;
            }
            else {
              iVar3 = FUN_0040aa43(param_1);
              if (iVar3 == 0) {
                SetCursor(local_24);
                FUN_0042f1e8();
                FUN_0040d0a5();
                local_54.wParam = 0;
              }
              else {
                _DAT_00442d04 = 1;
                local_34 = GetDC((HWND)0x0);
                DAT_004830f4 = FUN_00426290(local_34,s_PAUSEBMP_0043eb9c);
                ReleaseDC((HWND)0x0,local_34);
                SetCursor(local_24);
                PostMessageA(DAT_00442cf8,0x4f6,0,0);
                DAT_00486c40 = 1;
                local_30 = 0;
                SetTimer(DAT_00442cf8,1,100,(TIMERPROC)0x0);
                FUN_00405495();
                local_20 = GetTickCount();
                local_10 = local_20;
                while( true ) {
                  while (BVar5 = PeekMessageA(&local_54,(HWND)0x0,0,0,1), BVar5 == 0) {
                    if (DAT_0043e8bc == 0) {
                      WaitMessage();
                    }
                    else {
                      SendMessageA(DAT_00442cf8,0x42b,0,0);
                      local_10 = GetTickCount();
                      local_8 = (DAT_0043d3b4 * 0x10 + 0x21) - (local_10 - local_20);
                      if ((int)local_8 < 4) {
                        local_8 = 4;
                      }
                      if (100 < (int)local_8) {
                        local_8 = 100;
                      }
                      local_20 = local_10;
                      Sleep(local_8);
                    }
                  }
                  if (local_54.message == 0x12) break;
                  if ((DAT_00442cf8 == (HWND)0x0) ||
                     (iVar3 = TranslateAcceleratorA(DAT_00442cf8,DAT_00442d18,&local_54), iVar3 == 0
                     )) {
                    TranslateMessage(&local_54);
                    DispatchMessageA(&local_54);
                  }
                }
                FUN_0040d0a5();
                FUN_0040ee1f();
                WinHelpA(DAT_0048cc60,s_COLC_HLP_0043d098,2,0);
              }
            }
          }
        }
      }
    }
  }
  else {
    local_54.wParam = 0;
  }
  return local_54.wParam;
}


// ==== FUN_0040aa43 @ 0040aa43

undefined4 __cdecl FUN_0040aa43(undefined4 param_1)

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
  
  DAT_00442cfc = FUN_0040e6de(DAT_00483518,s_MainMenuPlayed_0043eba8);
  DAT_00487b40 = FUN_0040e6de(DAT_00483518,s_MainMenu_0043ebb8);
  DAT_00442d18 = FUN_0040e61b(param_1,s_ACCELERATORS_1_0043ebc4);
  if (DAT_00442d18 == (HACCEL)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_0040e740(DAT_00483518,100,local_84,0x78);
    DVar2 = GetVersion();
    local_88 = (byte)DVar2;
    if (local_88 < 4) {
      iVar3 = GetSystemMetrics(5);
      DAT_00443640 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(6);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_004441cc = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00443640;
      iVar4 = DAT_004441cc;
      pHVar8 = DAT_00487b40;
      pHVar9 = DAT_00483518;
      iVar5 = FUN_0040a543(DAT_004441cc);
      iVar6 = FUN_0040a522(DAT_00443640);
      DAT_00442cf8 = CreateWindowExA(0,PTR_s_ShawlGameWnd_0043d090,local_84,0xca0000,iVar6,iVar5,
                                     iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    else {
      iVar3 = GetSystemMetrics(7);
      DAT_00443640 = iVar3 * 2 + 600;
      iVar3 = GetSystemMetrics(8);
      iVar4 = GetSystemMetrics(4);
      iVar5 = GetSystemMetrics(0xf);
      DAT_004441cc = iVar3 * 2 + iVar4 + iVar5 + 400;
      pvVar10 = (LPVOID)0x0;
      pHVar7 = (HWND)0x0;
      iVar3 = DAT_00443640;
      iVar4 = DAT_004441cc;
      pHVar8 = DAT_00487b40;
      pHVar9 = DAT_00483518;
      iVar5 = FUN_0040a543(DAT_004441cc);
      iVar6 = FUN_0040a522(DAT_00443640);
      DAT_00442cf8 = CreateWindowExA(0x100,PTR_s_ShawlGameWnd_0043d090,local_84,0xca0000,iVar6,iVar5
                                     ,iVar3,iVar4,pHVar7,pHVar8,pHVar9,pvVar10);
    }
    DAT_0048cc60 = DAT_00442cf8;
    if (DAT_00442cf8 == (HWND)0x0) {
      uVar1 = 0;
    }
    else {
      ShowWindow(DAT_00442cf8,5);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0040ac51 @ 0040ac51

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040ac51(void)

{
  double dVar1;
  bool bVar2;
  LPVOID pvVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined3 extraout_var_00;
  int iVar7;
  longlong lVar8;
  undefined *local_44;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  FUN_00405ca2();
  DAT_0044209c = 0;
  for (local_18 = 0; local_18 < 6; local_18 = local_18 + 1) {
    if (*(int *)(&DAT_00480f2c + local_18 * 8) != 0) {
      *(undefined4 *)(&DAT_00480f2c + local_18 * 8) = 0;
    }
    pvVar3 = FUN_00426556((LPCSTR)(local_18 + 1000));
    *(LPVOID *)(&DAT_00480f2c + local_18 * 8) = pvVar3;
    if (*(int *)(&DAT_00480f30 + local_18 * 8) != 0) {
      *(undefined4 *)(&DAT_00480f30 + local_18 * 8) = 0;
    }
    pvVar3 = FUN_00426556((LPCSTR)(local_18 + 0x46a));
    *(LPVOID *)(&DAT_00480f30 + local_18 * 8) = pvVar3;
  }
  DAT_004830f8 = 0x1d;
  DAT_004830fc = 0x1e;
  DAT_00483100 = 0x245;
  DAT_00483104 = 0x171;
  DAT_004864c8 = 0;
  DAT_004864cc = 0;
  DAT_004864d0 = 599;
  DAT_004864d4 = 399;
  bVar2 = FUN_004258e3(0x486b70);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    uVar4 = 0;
  }
  else {
    DAT_00487a6c = FUN_004264ac(s_TITLEBMP_0043ebd4);
    FUN_00426912(&DAT_0048d0f0,DAT_00487a6c);
    FUN_00426d1f(&DAT_0048d0f0,0,0,DAT_00487a6c,-1);
    DAT_0048d694 = 600;
    for (local_18 = 0; local_18 < 0x168; local_18 = local_18 + 1) {
      dVar1 = ((double)local_18 * _DAT_0043c000) / _DAT_0043c008;
      FUN_00433170(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
      lVar8 = __ftol();
      *(int *)(&DAT_004864d8 + local_18 * 4) = (int)lVar8;
      FUN_0043317a();
      lVar8 = __ftol();
      *(int *)(&DAT_004420a8 + local_18 * 4) = (int)lVar8;
    }
    puVar5 = (undefined4 *)FUN_0042d730();
    if (DAT_00480eb8 == 0) {
      local_44 = &DAT_004616ac;
    }
    else {
      local_44 = &DAT_004712b4;
    }
    *puVar5 = local_44;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = DAT_004616a8 + -1;
    puVar5[5] = 0;
    puVar5[6] = DAT_004616aa + -1;
    puVar5[7] = (int)DAT_004616a8;
    for (local_18 = 0; local_18 < 6; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < 5; local_1c = local_1c + 1) {
        *(int *)(&DAT_00443be4 + local_1c * 0x28 + local_18 * 200) = local_18 * 5 + local_1c + 0x3ef
        ;
        *(undefined4 *)(&DAT_00443be8 + local_1c * 0x28 + local_18 * 200) = 2;
        *(undefined4 *)(&DAT_00443bec + local_1c * 0x28 + local_18 * 200) = 0;
        iVar6 = FUN_0040c9a0((int *)(&DAT_00443bc8 + local_1c * 0x28 + local_18 * 200));
        if (iVar6 == 0) {
          return 0;
        }
        *(int *)(&DAT_004431ac + local_1c * 0x28 + local_18 * 200) = local_18 * 5 + local_1c + 0x412
        ;
        *(undefined4 *)(&DAT_004431b0 + local_1c * 0x28 + local_18 * 200) = 2;
        *(undefined4 *)(&DAT_004431b4 + local_1c * 0x28 + local_18 * 200) = 0;
        iVar6 = FUN_0040c9a0((int *)(&DAT_00443190 + local_1c * 0x28 + local_18 * 200));
        if (iVar6 == 0) {
          return 0;
        }
      }
      for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
        *(int *)(&DAT_004831bc + local_1c * 0x28 + local_18 * 0x78) =
             local_18 * 3 + local_1c + 0x435;
        *(undefined4 *)(&DAT_004831c0 + local_1c * 0x28 + local_18 * 0x78) = 2;
        *(undefined4 *)(&DAT_004831c4 + local_1c * 0x28 + local_18 * 0x78) = 0;
        iVar6 = FUN_0040c9a0((int *)(&DAT_004831a0 + local_1c * 0x28 + local_18 * 0x78));
        if (iVar6 == 0) {
          return 0;
        }
        *(int *)(&DAT_00442d4c + local_1c * 0x28 + local_18 * 0x78) =
             local_18 * 3 + local_1c + 0x44a;
        *(undefined4 *)(&DAT_00442d50 + local_1c * 0x28 + local_18 * 0x78) = 2;
        *(undefined4 *)(&DAT_00442d54 + local_1c * 0x28 + local_18 * 0x78) = 0;
        iVar6 = FUN_0040c9a0((int *)(&DAT_00442d30 + local_1c * 0x28 + local_18 * 0x78));
        if (iVar6 == 0) {
          return 0;
        }
      }
    }
    for (local_1c = 0; local_1c < 5; local_1c = local_1c + 1) {
      *(int *)(&DAT_00444094 + local_1c * 0x28) = local_1c + 0x616;
      *(undefined4 *)(&DAT_00444098 + local_1c * 0x28) = 2;
      *(undefined4 *)(&DAT_0044409c + local_1c * 0x28) = 0;
      iVar6 = FUN_0040c9a0((int *)(&DAT_00444078 + local_1c * 0x28));
      if (iVar6 == 0) {
        return 0;
      }
    }
    _DAT_0044301c = 0x645;
    _DAT_00443020 = 2;
    _DAT_00443024 = 0;
    iVar6 = FUN_0040c9a0((int *)&DAT_00443000);
    if (iVar6 == 0) {
      uVar4 = 0;
    }
    else {
      for (local_18 = 1; local_18 < 9; local_18 = local_18 + 1) {
        *(int *)(&DAT_0044301c + local_18 * 0x28) = local_18 + 0x45f;
        *(undefined4 *)(&DAT_00443020 + local_18 * 0x28) = 2;
        *(undefined4 *)(&DAT_00443024 + local_18 * 0x28) = 0;
        if (*(int *)(&DAT_00443020 + local_18 * 0x28) == 0) {
          bVar2 = false;
        }
        else if (*(int *)(&DAT_00443000 + local_18 * 0x28) == 0) {
          if (*(int *)(&DAT_00443024 + local_18 * 0x28) == 0) {
            if (*(int *)(&DAT_00443020 + local_18 * 0x28) == 1) {
              pvVar3 = FUN_00426556((LPCSTR)(local_18 * 0x28 + 0x443008));
              *(LPVOID *)(&DAT_00443000 + local_18 * 0x28) = pvVar3;
            }
            else {
              pvVar3 = FUN_00426556(*(LPCSTR *)(&DAT_0044301c + local_18 * 0x28));
              *(LPVOID *)(&DAT_00443000 + local_18 * 0x28) = pvVar3;
            }
            if (*(int *)(&DAT_00443000 + local_18 * 0x28) != 0) {
              *(undefined4 *)(local_18 * 0x28 + 0x443004) = 1;
              goto LAB_0040b439;
            }
            bVar2 = false;
          }
          else if (*(int *)(&DAT_00443000 + local_18 * 0x28) == 0) {
            bVar2 = false;
          }
          else {
            *(undefined4 *)(local_18 * 0x28 + 0x443004) = 0;
LAB_0040b439:
            bVar2 = true;
          }
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          return 0;
        }
      }
      _DAT_00443184 = 0x541;
      _DAT_00443188 = 2;
      _DAT_0044318c = 0;
      FUN_0040c9a0((int *)&DAT_00443168);
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        *(int *)(&DAT_00443664 + local_18 * 0x28) = local_18 + 0x641;
        *(undefined4 *)(&DAT_00443668 + local_18 * 0x28) = 2;
        *(undefined4 *)(&DAT_0044366c + local_18 * 0x28) = 0;
        if (*(int *)(&DAT_00443668 + local_18 * 0x28) == 0) {
          bVar2 = false;
        }
        else if (*(int *)(&DAT_00443648 + local_18 * 0x28) == 0) {
          if (*(int *)(&DAT_0044366c + local_18 * 0x28) == 0) {
            if (*(int *)(&DAT_00443668 + local_18 * 0x28) == 1) {
              pvVar3 = FUN_00426556((LPCSTR)(local_18 * 0x28 + 0x443650));
              *(LPVOID *)(&DAT_00443648 + local_18 * 0x28) = pvVar3;
            }
            else {
              pvVar3 = FUN_00426556(*(LPCSTR *)(&DAT_00443664 + local_18 * 0x28));
              *(LPVOID *)(&DAT_00443648 + local_18 * 0x28) = pvVar3;
            }
            if (*(int *)(&DAT_00443648 + local_18 * 0x28) != 0) {
              *(undefined4 *)(&DAT_0044364c + local_18 * 0x28) = 1;
              goto LAB_0040b61e;
            }
            bVar2 = false;
          }
          else if (*(int *)(&DAT_00443648 + local_18 * 0x28) == 0) {
            bVar2 = false;
          }
          else {
            *(undefined4 *)(&DAT_0044364c + local_18 * 0x28) = 0;
LAB_0040b61e:
            bVar2 = true;
          }
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          return 0;
        }
      }
      bVar2 = FUN_0042f520(&DAT_00442080,(LPCSTR)0x3e8);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        uVar4 = 0;
      }
      else {
        _DAT_00442650 = &DAT_00442080;
        _DAT_00442654 = 0x6f;
        _DAT_00442658 = 9;
        DAT_00487b20 = &DAT_00442080;
        DAT_00487b24 = 0x16c;
        DAT_00487b28 = 9;
        _DAT_00444164 = 0;
        _DAT_0044415c = 0;
        DAT_00444140 = &DAT_00442080;
        DAT_00444144 = 0xaf;
        DAT_00444148 = 0xb8;
        for (local_18 = 0; local_18 < 0xf; local_18 = local_18 + 1) {
          *(int *)(&DAT_00443734 + local_18 * 0x50) = local_18 + 0x607;
          *(undefined4 *)(&DAT_00443738 + local_18 * 0x50) = 2;
          *(undefined4 *)(&DAT_0044373c + local_18 * 0x50) = 0;
          if ((*(int *)(&DAT_00443738 + local_18 * 0x50) != 0) &&
             (*(int *)(&DAT_00443718 + local_18 * 0x50) == 0)) {
            if (*(int *)(&DAT_0044373c + local_18 * 0x50) == 0) {
              if (*(int *)(&DAT_00443738 + local_18 * 0x50) == 1) {
                pvVar3 = FUN_00426556((LPCSTR)(local_18 * 0x50 + 0x443720));
                *(LPVOID *)(&DAT_00443718 + local_18 * 0x50) = pvVar3;
              }
              else {
                pvVar3 = FUN_00426556(*(LPCSTR *)(&DAT_00443734 + local_18 * 0x50));
                *(LPVOID *)(&DAT_00443718 + local_18 * 0x50) = pvVar3;
              }
              if (*(int *)(&DAT_00443718 + local_18 * 0x50) != 0) {
                *(undefined4 *)(&DAT_0044371c + local_18 * 0x50) = 1;
              }
            }
            else if (*(int *)(&DAT_00443718 + local_18 * 0x50) != 0) {
              *(undefined4 *)(&DAT_0044371c + local_18 * 0x50) = 0;
            }
          }
          *(undefined4 *)(&DAT_00443744 + local_18 * 0x50) = 5;
        }
        iVar6 = FUN_0042d60b(&DAT_004830f8);
        iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
        iVar7 = FUN_0042d61b(0x4830f8);
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
            *(int *)(&DAT_0044267c + (local_18 * 4 + local_1c) * 0xd0) = iVar6 * local_1c + 2;
            *(int *)(&DAT_00442680 + (local_18 * 4 + local_1c) * 0xd0) = local_18 * (iVar7 / 2) + 2;
            *(int *)(&DAT_00442684 + (local_18 * 4 + local_1c) * 0xd0) = (local_1c + 1) * iVar6 + -2
            ;
            *(int *)(&DAT_00442688 + (local_18 * 4 + local_1c) * 0xd0) =
                 (local_18 + 1) * (iVar7 / 2) + -2;
          }
        }
        for (local_24 = 0; local_24 < 10; local_24 = local_24 + 1) {
          for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
            for (local_1c = 0; local_1c < 6; local_1c = local_1c + 1) {
              for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
                *(undefined4 *)
                 (&DAT_004835e8 +
                 local_1c * 0x28 + local_24 * 0x4b0 + local_18 * 0xf0 + local_20 * 4) =
                     *(undefined4 *)(&DAT_0043d4f0 + local_18 * 4);
              }
            }
          }
        }
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ==== FUN_0040bac0 @ 0040bac0

void FUN_0040bac0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040bb23;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  FUN_0040bb0b();
  local_8 = 0xffffffff;
  FUN_0040bb17();
  FUN_0040bb2d();
  return;
}


// ==== FUN_0040bb0b @ 0040bb0b

void FUN_0040bb0b(void)

{
  FUN_0040c8e0();
  return;
}


// ==== FUN_0040bb17 @ 0040bb17

void FUN_0040bb17(void)

{
  int unaff_EBP;
  
  FUN_0040bb40((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}


// ==== FUN_0040bb2d @ 0040bb2d

void FUN_0040bb2d(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040bb40 @ 0040bb40

void __fastcall FUN_0040bb40(int *param_1)

{
  if (*param_1 != 0) {
    FUN_00432b10((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_0040bbb0 @ 0040bbb0

void __fastcall FUN_0040bbb0(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== FUN_0040bbf0 @ 0040bbf0

undefined4 * __fastcall FUN_0040bbf0(undefined4 *param_1)

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


// ==== FUN_0040bc90 @ 0040bc90

void __fastcall FUN_0040bc90(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040bd28;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  local_8 = 0xffffffff;
  FUN_0040bd1f();
  FUN_0040bd32();
  return;
}


// ==== FUN_0040bd1f @ 0040bd1f

void FUN_0040bd1f(void)

{
  int unaff_EBP;
  
  FUN_0040bbb0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_0040bd32 @ 0040bd32

void FUN_0040bd32(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040bd40 @ 0040bd40

undefined4 * __fastcall FUN_0040bd40(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040bf1d;
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
    FUN_00432b10((void *)param_1[0x10]);
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


// ==== FUN_0040bf40 @ 0040bf40

void __fastcall FUN_0040bf40(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0040c055;
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
    FUN_00432b10((void *)param_1[0x10]);
  }
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0040c040();
  local_8 = 0xffffffff;
  FUN_0040c04c();
  FUN_0040c05f();
  return;
}


// ==== FUN_0040c040 @ 0040c040

void FUN_0040c040(void)

{
  int unaff_EBP;
  
  FUN_0040bb40((int *)(*(int *)(unaff_EBP + -0x18) + 0x40));
  return;
}


// ==== FUN_0040c04c @ 0040c04c

void FUN_0040c04c(void)

{
  int unaff_EBP;
  
  FUN_0040bc90(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0040c05f @ 0040c05f

void FUN_0040c05f(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040c070 @ 0040c070

void __fastcall FUN_0040c070(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040c122;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0;
  *param_1 = 0;
  if (param_1[3] != 0) {
    FUN_00432b10((void *)param_1[3]);
  }
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0xffffffff;
  FUN_0040c116();
  FUN_0040c12c();
  return;
}


// ==== FUN_0040c116 @ 0040c116

void FUN_0040c116(void)

{
  int unaff_EBP;
  
  FUN_0040bb40((int *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  return;
}


// ==== FUN_0040c12c @ 0040c12c

void FUN_0040c12c(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040c140 @ 0040c140

void __thiscall FUN_0040c140(void *this,HDC param_1)

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
        pvVar11 = SelectObject(pHVar10,DAT_0048d6a0);
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
          pvVar11 = SelectObject(pHVar10,DAT_0048d6a0);
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
          pvVar11 = SelectObject(pHVar10,DAT_0048d6a0);
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


// ==== FUN_0040c5b0 @ 0040c5b0

int __fastcall FUN_0040c5b0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040c8ba;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  local_8 = 3;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 1;
  if (*(int *)(param_1 + 0x74) != 0) {
    FUN_00432b10(*(void **)(param_1 + 0x74));
  }
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_0040c8e0 @ 0040c8e0

void FUN_0040c8e0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0040c927;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  local_8 = 0xffffffff;
  FUN_0040c91e();
  FUN_0040c931();
  return;
}


// ==== FUN_0040c91e @ 0040c91e

void FUN_0040c91e(void)

{
  int unaff_EBP;
  
  FUN_0040bf40(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_0040c931 @ 0040c931

void FUN_0040c931(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0040c940 @ 0040c940

undefined4 * __fastcall FUN_0040c940(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}


// ==== FUN_0040c970 @ 0040c970

void __fastcall FUN_0040c970(int *param_1)

{
  if (*param_1 != 0) {
    *param_1 = 0;
  }
  return;
}


// ==== FUN_0040c9a0 @ 0040c9a0

undefined4 __fastcall FUN_0040c9a0(int *param_1)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if (param_1[8] == 0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    if (param_1[9] == 0) {
      if (param_1[8] == 1) {
        pvVar2 = FUN_00426556((LPCSTR)(param_1 + 2));
        *param_1 = (int)pvVar2;
      }
      else {
        pvVar2 = FUN_00426556((LPCSTR)param_1[7]);
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


// ==== FUN_0040ca80 @ 0040ca80

void FUN_0040ca80(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_00487bd4 == 1) || (DAT_00487bd4 == 3)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_0043ed78,0x808,2,(DWORD_PTR)local_c);
    Sleep(1);
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_0043ed78,0x804,2,(DWORD_PTR)local_c);
    DAT_0043ed78 = 0;
    Sleep(1);
    DAT_00487bd4 = 0;
  }
  return;
}


// ==== FUN_0040cb25 @ 0040cb25

void FUN_0040cb25(void)

{
  undefined1 local_c [4];
  MCIERROR local_8;
  
  if ((DAT_0043ebe4 != 0) && (DAT_00487bd4 == 1)) {
    _memset(local_c,0,4);
    local_8 = mciSendCommandA(DAT_0043ed78,0x809,2,(DWORD_PTR)local_c);
    Sleep(1);
    DAT_00487bd4 = 3;
  }
  return;
}


// ==== FUN_0040cb98 @ 0040cb98

void __cdecl FUN_0040cb98(int param_1)

{
  undefined1 local_18 [4];
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0043ebe4 != 0) {
    if (DAT_00487bd4 == 3) {
      _memset(local_18,0,4);
      local_14 = mciSendCommandA(DAT_0043ed78,0x855,2,(DWORD_PTR)local_18);
      if (local_14 != 0) {
        _memset(local_10,0,0xc);
        local_c = 0;
        local_14 = mciSendCommandA(DAT_0043ed78,0x806,4,(DWORD_PTR)local_10);
        Sleep(1);
        if (local_14 != 0) {
          FUN_0040cc75(param_1);
          return;
        }
      }
      Sleep(1);
      DAT_00487bd4 = 1;
    }
    else {
      FUN_0040cc75(param_1);
    }
  }
  return;
}


// ==== FUN_0040cc75 @ 0040cc75

void __cdecl FUN_0040cc75(int param_1)

{
  undefined1 local_28 [4];
  MCIDEVICEID local_24;
  char *local_20;
  undefined *local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0043ebe4 == 0) {
    FUN_0040ca80();
  }
  else {
    if (((DAT_00487bd0 == param_1) && (0 < param_1)) && (DAT_00487bd4 == 1)) {
      _memset(local_10,0,0xc);
      local_c = 0;
      local_14 = mciSendCommandA(DAT_0043ed78,0x806,4,(DWORD_PTR)local_10);
      Sleep(1);
      if (local_14 == 0) {
        return;
      }
    }
    if (DAT_00487bd4 != 4) {
      FUN_0040ca80();
    }
    if (DAT_0043ebe4 != 0) {
      if (0 < param_1) {
        DAT_00487bd0 = param_1;
      }
      if (param_1 == -1) {
        param_1 = DAT_00487bd0;
      }
      if ((0 < param_1) && (param_1 < 6)) {
        _memset(local_28,0,0x14);
        local_1c = &DAT_00487bd8 + param_1 * 0x100;
        local_20 = s_sequencer_0043ed7c;
        local_14 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)local_28);
        Sleep(1);
        if ((DAT_0043ed78 != 0) && (local_14 == 0x109)) {
          local_24 = DAT_0043ed78;
          local_14 = 0;
        }
        if (local_14 == 0) {
          DAT_0043ed78 = local_24;
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_0043ed78,0x806,4,(DWORD_PTR)local_10);
          Sleep(1);
          if (local_14 == 0) {
            DAT_00487bd4 = 1;
          }
          else {
            DAT_00487bd4 = 4;
          }
        }
        else {
          DAT_00487bd4 = 4;
        }
      }
    }
  }
  return;
}


// ==== FUN_0040ce55 @ 0040ce55

void FUN_0040ce55(void)

{
  undefined1 local_24 [4];
  int local_20;
  undefined4 local_1c;
  MCIERROR local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  if (DAT_0043ebe4 != 0) {
    if (DAT_00487bd4 == 1) {
      if (DAT_0043ed78 == 0) {
        DAT_00487bd4 = 4;
      }
      else {
        _memset(local_24,0,0x10);
        local_1c = 4;
        local_14 = mciSendCommandA(DAT_0043ed78,0x814,0x102,(DWORD_PTR)local_24);
        Sleep(1);
        if ((local_14 == 0) && (local_20 == 0x20d)) {
          _memset(local_10,0,0xc);
          local_c = 0;
          local_14 = mciSendCommandA(DAT_0043ed78,0x806,4,(DWORD_PTR)local_10);
          if (local_14 != 0) {
            DAT_00487bd4 = 4;
          }
          Sleep(1);
        }
        if (local_14 != 0) {
          DAT_00487bd4 = 4;
        }
      }
    }
    else if (DAT_00487bd4 == 4) {
      FUN_0040cc75(-1);
    }
  }
  return;
}


// ==== FUN_0040cf73 @ 0040cf73

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040cf73(int param_1)

{
  DWORD DVar1;
  
  if ((DAT_0043ebe0 != 0) && (*(int *)(&DAT_004881d8 + param_1 * 0x10) != 0)) {
    DVar1 = GetTickCount();
    if (DVar1 < DAT_0043ebe8) {
      DAT_0043ebe8 = DVar1;
    }
    if (DVar1 - _DAT_0043ebec < DAT_0043ebe8) {
      if (DAT_0043ebf0 <= *(int *)(&DAT_004881e4 + param_1 * 0x10)) {
        return;
      }
      Sleep(1);
    }
    sndPlaySoundA((LPCSTR)0x0,5);
    Sleep(1);
    DAT_0043ebe8 = GetTickCount();
    _DAT_0043ebec = *(int *)(&DAT_004881e0 + param_1 * 0x10);
    DAT_0043ebf0 = *(int *)(&DAT_004881e4 + param_1 * 0x10);
    sndPlaySoundA(*(LPCSTR *)(&DAT_004881d8 + param_1 * 0x10),5);
  }
  return;
}


// ==== FUN_0040d0a5 @ 0040d0a5

void FUN_0040d0a5(void)

{
  int local_c;
  int local_8;
  
  FUN_0040ca80();
  FUN_0040cf73(0);
  for (local_8 = 0xb; local_8 < 0x2e; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_004881dc + local_8 * 0x10) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_004881dc + local_8 * 0x10));
      *(undefined4 *)(&DAT_004881dc + local_8 * 0x10) = 0;
      *(undefined4 *)(&DAT_004881d8 + local_8 * 0x10) = 0;
    }
  }
  mciSendCommandA(0xffffffff,0x804,2,0);
  Sleep(1000);
  mciSendCommandA(0xffffffff,0x804,2,0);
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    DeleteFileA(&DAT_00487bd8 + local_c * 0x100);
  }
  return;
}


// ==== FUN_0040d18d @ 0040d18d

void __cdecl FUN_0040d18d(int *param_1,LPCSTR param_2)

{
  int *piVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  int *local_10;
  int local_c;
  
  pvVar2 = FUN_0040e190(DAT_00483518,param_2,&DAT_0043ed88);
  param_1[1] = (int)pvVar2;
  if (param_1[1] != 0) {
    pvVar3 = LockResource((HGLOBAL)param_1[1]);
    *param_1 = (int)pvVar3;
    param_1[2] = 0;
    if (*param_1 != 0) {
      local_10 = (int *)*param_1;
      for (local_c = 0; local_c < 0x200; local_c = local_c + 1) {
        piVar1 = (int *)((int)local_10 + 1);
        if (((((char)*local_10 == 'd') &&
             (piVar1 = (int *)((int)local_10 + 2), *(char *)((int)local_10 + 1) == 'a')) &&
            (piVar1 = (int *)((int)local_10 + 3), *(char *)((int)local_10 + 2) == 't')) &&
           ((piVar1 = local_10 + 1, *(char *)((int)local_10 + 3) == 'a' &&
            (param_1[2] = (uint)(*piVar1 * 1000) / 0x2b11 + 1, 2000 < (uint)param_1[2])))) {
          param_1[2] = 2000;
        }
        local_10 = piVar1;
      }
    }
  }
  return;
}


// ==== FUN_0040d2c6 @ 0040d2c6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040d2c6(void)

{
  LPCSTR local_8;
  
  _DAT_004881d8 = 0;
  _DAT_004881dc = 0;
  for (local_8 = (LPCSTR)0xb; (int)local_8 < 0x2e; local_8 = local_8 + 1) {
    FUN_0040d18d((int *)(&DAT_004881d8 + (int)local_8 * 0x10),local_8);
    *(undefined4 *)(&DAT_004881e4 + (int)local_8 * 0x10) = 10;
  }
  _DAT_004883f4 = 1;
  _DAT_00488404 = 1;
  _DAT_004884b4 = 1;
  _DAT_00488304 = 2;
  _DAT_00488314 = 2;
  for (local_8 = (LPCSTR)0x1; (int)local_8 < 6; local_8 = (LPCSTR)((int)local_8 + 1)) {
    GetTempPathA(200,&DAT_00487bd8 + (int)local_8 * 0x100);
    FUN_00432d50((uint *)(&DAT_00487bd8 + (int)local_8 * 0x100),
                 (uint *)(&DAT_0043ebf8 + (int)local_8 * 0x20));
    FUN_0040e3b3(&DAT_0043ecb8 + (int)local_8 * 0x20,&DAT_0043ed90,
                 &DAT_00487bd8 + (int)local_8 * 0x100);
  }
  return;
}


// ==== FUN_0040d3e0 @ 0040d3e0

void __thiscall FUN_0040d3e0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar4;
  void *pvVar5;
  int local_34;
  int local_28;
  int local_24;
  int local_c;
  int local_8;
  undefined2 uVar3;
  
  *(int *)((int)this + 0x50) = param_3;
  *(int *)((int)this + 0x54) = param_4;
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0) {
LAB_0040d4e8:
    local_8 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040d4e8;
    local_8 = (int)**(short **)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28);
  }
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0) {
LAB_0040d5df:
    local_c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040d5df;
    local_c = (int)*(short *)(*(int *)(&DAT_00443190 + *(int *)((int)this + 0x50) * 0x28) + 2);
  }
  *(undefined4 *)((int)this + 4) = 0;
  uVar2 = (undefined2)local_8;
  uVar3 = (undefined2)local_c;
  if (*(int *)this == 0) {
    pvVar5 = operator_new(local_8 * local_c + 4);
    *(void **)this = pvVar5;
    if (*(int *)this != 0) {
      **(undefined2 **)this = uVar2;
      *(undefined2 *)(*(int *)this + 2) = uVar3;
      _memset((void *)(*(int *)this + 4),0,local_8 * local_c);
    }
    goto LAB_0040d8e8;
  }
  if (*(int *)this == 0) {
LAB_0040d69e:
    local_24 = 0;
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
    if (bVar1) goto LAB_0040d69e;
    local_24 = (int)**(short **)this;
  }
  if ((*(int *)this == 0) || (iVar4 = FUN_0040e110(this), iVar4 != 0)) {
    if (0 < local_8 * local_c) goto LAB_0040d711;
  }
  else if (*(short *)(*(int *)this + 2) * local_24 < local_8 * local_c) {
LAB_0040d711:
    pvVar5 = operator_new(local_8 * local_c + 4);
    *(void **)this = pvVar5;
    if (*(int *)this == 0) goto LAB_0040d8e8;
    **(undefined2 **)this = uVar2;
    *(undefined2 *)(*(int *)this + 2) = uVar3;
  }
  if ((*(int *)this == 0) || (iVar4 = FUN_0040e110(this), iVar4 != 0)) {
    local_28 = 0;
  }
  else {
    local_28 = (int)**(short **)this;
  }
  if (*(int *)this == 0) {
LAB_0040d831:
    local_34 = 0;
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
    if (bVar1) goto LAB_0040d831;
    local_34 = (int)*(short *)(*(int *)this + 2);
  }
  _memset((void *)(*(int *)this + 4),0,local_34 * local_28);
  **(undefined2 **)this = uVar2;
  *(undefined2 *)(*(int *)this + 2) = uVar3;
LAB_0040d8e8:
  *(int *)((int)this + 0x28) = param_1 - local_8 / 2;
  *(int *)((int)this + 0x2c) = param_2 - local_c / 2;
  *(undefined4 *)((int)this + 100) =
       *(undefined4 *)
        (&DAT_0043d508 + *(int *)((int)this + 0x54) * 4 + *(int *)((int)this + 0x50) * 0x10);
  *(undefined4 *)((int)this + 0x68) =
       *(undefined4 *)
        (&DAT_0043d558 + *(int *)((int)this + 0x54) * 4 + *(int *)((int)this + 0x50) * 0x10);
  iVar4 = FUN_00405e69(3);
  *(int *)((int)this + 0x6c) = iVar4;
  iVar4 = FUN_00405e69(4);
  *(int *)((int)this + 0x70) = iVar4 + 1;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  if (*(int *)((int)this + 0x40) != 0) {
    FUN_00432b10(*(void **)((int)this + 0x40));
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  return;
}


// ==== FUN_0040d9f2 @ 0040d9f2

void __fastcall FUN_0040d9f2(int *param_1)

{
  short *psVar1;
  bool bVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_8;
  
  if (*param_1 == 0) {
    return;
  }
  FUN_0042e519(param_1 + 0x10,(short *)*param_1,0,0,0,0);
  if (*param_1 != 0) {
    if (*param_1 == 0) {
      bVar2 = false;
    }
    else if (*(short *)*param_1 == 0x400) {
      if ((int)*(short *)(*param_1 + 6) * (int)*(short *)(*param_1 + 8) - *(int *)(*param_1 + 2) ==
          0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if ((!bVar2) && (psVar1 = (short *)*param_1, psVar1 != (short *)0x0)) {
      _memset(psVar1 + 2,0,(int)psVar1[1] * (int)*psVar1);
    }
  }
  if (DAT_00483470 == (short *)0x0) {
LAB_0040dbbf:
    local_10 = 0;
  }
  else {
    if (*DAT_00483470 == 0x400) {
      if ((int)DAT_00483470[3] * (int)DAT_00483470[4] - *(int *)(DAT_00483470 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0040dbbf;
    local_10 = (int)*DAT_00483470 / 2;
  }
  if (DAT_00483470 == (short *)0x0) {
LAB_0040dc77:
    local_14 = 0;
  }
  else {
    if (*DAT_00483470 == 0x400) {
      if ((int)DAT_00483470[3] * (int)DAT_00483470[4] - *(int *)(DAT_00483470 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0040dc77;
    local_14 = (int)DAT_00483470[1] / 2;
  }
  iVar3 = param_1[0x14] * 0x380 + param_1[0x15] * 0xe0;
  for (local_8 = 0; local_8 < param_1[0x19]; local_8 = local_8 + 1) {
    FUN_004303bf(*(int *)(&DAT_0043d5a8 + local_8 * 8 + iVar3) - local_10,
                 *(int *)(&DAT_0043d5ac + local_8 * 8 + iVar3) - local_14,DAT_00483470,
                 (short *)*param_1);
  }
  if (param_1[0x17] == 0) goto LAB_0040dfa3;
  iVar3 = param_1[0x14] * 0x380 + param_1[0x19] * 8 + param_1[0x15] * 0xe0;
  if (*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0) {
LAB_0040de46:
    local_10 = 0;
  }
  else {
    if (*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 2) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0040de46;
    local_10 = (int)**(short **)(&DAT_00483498 + param_1[0x1b] * 0x28) / 2;
  }
  if (*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0) {
LAB_0040df4f:
    local_14 = 0;
  }
  else {
    if (*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)(&DAT_00483498 + param_1[0x1b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 2) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0040df4f;
    local_14 = (int)*(short *)(*(int *)(&DAT_00483498 + param_1[0x1b] * 0x28) + 2) / 2;
  }
  FUN_004303bf(*(int *)(iVar3 + 0x43d5a0) - local_10,*(int *)(iVar3 + 0x43d5a4) - local_14,
               *(short **)(&DAT_00483498 + param_1[0x1b] * 0x28),(short *)*param_1);
LAB_0040dfa3:
  FUN_004312fe(param_1,1);
  return;
}


// ==== FUN_0040dfb7 @ 0040dfb7

undefined4 __fastcall FUN_0040dfb7(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x17] == 0) {
    uVar1 = 0;
  }
  else {
    param_1[0x1a] = param_1[0x1a] + -1;
    if (param_1[0x1a] == 0) {
      param_1[0x19] = param_1[0x19] + -1;
      if (param_1[0x19] == 0) {
        FUN_0042e519(param_1 + 0x10,(short *)*param_1,0,0,0,0);
        param_1[0x17] = 0;
        uVar1 = 2;
      }
      else {
        param_1[0x1a] = *(int *)(&DAT_0043d558 + param_1[0x15] * 4 + param_1[0x14] * 0x10);
        param_1[0x1c] = param_1[0x1c] + -1;
        if (param_1[0x1c] == 0) {
          param_1[0x1c] = 4;
          param_1[0x1b] = param_1[0x1b] + 1;
          if (2 < param_1[0x1b]) {
            param_1[0x1b] = 0;
          }
        }
        FUN_0040d9f2(param_1);
        uVar1 = 1;
      }
    }
    else {
      param_1[0x1c] = param_1[0x1c] + -1;
      if (param_1[0x1c] == 0) {
        param_1[0x1c] = 4;
        param_1[0x1b] = param_1[0x1b] + 1;
        if (2 < param_1[0x1b]) {
          param_1[0x1b] = 0;
        }
        FUN_0040d9f2(param_1);
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


// ==== FUN_0040e110 @ 0040e110

undefined4 __fastcall FUN_0040e110(int *param_1)

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


// ==== FUN_0040e190 @ 0040e190

HGLOBAL __cdecl FUN_0040e190(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_004885d8 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  pvVar1 = LoadResource(*(HMODULE *)(&DAT_004885d8 + local_c * 4),hResInfo);
  return pvVar1;
}


// ==== FUN_0040e208 @ 0040e208

HGLOBAL __cdecl FUN_0040e208(undefined4 param_1,LPCSTR param_2,LPCSTR param_3,DWORD *param_4)

{
  HRSRC hResInfo;
  DWORD DVar1;
  HGLOBAL pvVar2;
  int local_c;
  
  *param_4 = 0;
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HGLOBAL)0x0;
    }
    hResInfo = FindResourceA(*(HMODULE *)(&DAT_004885d8 + local_c * 4),param_2,param_3);
    if (hResInfo != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  DVar1 = SizeofResource(*(HMODULE *)(&DAT_004885d8 + local_c * 4),hResInfo);
  *param_4 = DVar1;
  pvVar2 = LoadResource(*(HMODULE *)(&DAT_004885d8 + local_c * 4),hResInfo);
  return pvVar2;
}


// ==== FUN_0040e2a2 @ 0040e2a2

undefined4 __cdecl FUN_0040e2a2(LPCSTR param_1,LPCSTR param_2,void *param_3,uint param_4)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID _Src;
  int local_18;
  uint local_8;
  
  if (param_4 != 0) {
    for (local_18 = 0; local_18 < DAT_0043ed98; local_18 = local_18 + 1) {
      hResInfo = FindResourceA(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),param_1,param_2);
      if (hResInfo != (HRSRC)0x0) {
        hResData = LoadResource(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),hResInfo);
        if (hResData == (HGLOBAL)0x0) {
          return 0;
        }
        local_8 = SizeofResource(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),hResInfo);
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


// ==== FUN_0040e3b3 @ 0040e3b3

bool __cdecl FUN_0040e3b3(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

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
    if (DAT_0043ed98 <= local_18) {
LAB_0040e421:
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
          lBytes = SizeofResource(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),local_14);
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
    local_14 = FindResourceA(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),param_1,param_2);
    if (local_14 != (HRSRC)0x0) {
      local_20 = LoadResource(*(HMODULE *)(&DAT_004885d8 + local_18 * 4),local_14);
      goto LAB_0040e421;
    }
    local_18 = local_18 + 1;
  } while( true );
}


// ==== FUN_0040e4e7 @ 0040e4e7

HRSRC __cdecl FUN_0040e4e7(undefined4 param_1,LPCSTR param_2,LPCSTR param_3)

{
  HRSRC pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HRSRC)0x0;
    }
    pHVar1 = FindResourceA(*(HMODULE *)(&DAT_004885d8 + local_c * 4),param_2,param_3);
    if (pHVar1 != (HRSRC)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e54c @ 0040e54c

HGLOBAL __cdecl FUN_0040e54c(undefined4 param_1,HRSRC param_2)

{
  HGLOBAL pvVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HGLOBAL)0x0;
    }
    pvVar1 = LoadResource(*(HMODULE *)(&DAT_004885d8 + local_c * 4),param_2);
    if (pvVar1 != (HGLOBAL)0x0) break;
    local_c = local_c + 1;
  }
  return pvVar1;
}


// ==== FUN_0040e5ad @ 0040e5ad

INT_PTR __cdecl FUN_0040e5ad(undefined4 param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4)

{
  INT_PTR IVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return -1;
    }
    IVar1 = DialogBoxParamA(*(HINSTANCE *)(&DAT_004885d8 + local_c * 4),param_2,param_3,param_4,0);
    if (IVar1 != -1) break;
    local_c = local_c + 1;
  }
  return IVar1;
}


// ==== FUN_0040e61b @ 0040e61b

HACCEL __cdecl FUN_0040e61b(undefined4 param_1,LPCSTR param_2)

{
  HACCEL pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HACCEL)0x0;
    }
    pHVar1 = LoadAcceleratorsA(*(HINSTANCE *)(&DAT_004885d8 + local_c * 4),param_2);
    if (pHVar1 != (HACCEL)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e67d @ 0040e67d

HICON __cdecl FUN_0040e67d(undefined4 param_1,LPCSTR param_2)

{
  HICON pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HICON)0x0;
    }
    pHVar1 = LoadIconA(*(HINSTANCE *)(&DAT_004885d8 + local_c * 4),param_2);
    if (pHVar1 != (HICON)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e6de @ 0040e6de

HMENU __cdecl FUN_0040e6de(undefined4 param_1,LPCSTR param_2)

{
  HMENU pHVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return (HMENU)0x0;
    }
    pHVar1 = LoadMenuA(*(HINSTANCE *)(&DAT_004885d8 + local_c * 4),param_2);
    if (pHVar1 != (HMENU)0x0) break;
    local_c = local_c + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e740 @ 0040e740

int __cdecl FUN_0040e740(undefined4 param_1,UINT param_2,LPSTR param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_c) {
      return 0;
    }
    iVar1 = LoadStringA(*(HINSTANCE *)(&DAT_004885d8 + local_c * 4),param_2,param_3,param_4);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}


// ==== FUN_0040e7a9 @ 0040e7a9

HBITMAP __cdecl FUN_0040e7a9(undefined4 param_1,LPCSTR param_2)

{
  HBITMAP pHVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_0043ed98 <= local_8) {
      return (HBITMAP)0x0;
    }
    pHVar1 = LoadBitmapA(*(HINSTANCE *)(&DAT_004885d8 + local_8 * 4),param_2);
    if (pHVar1 != (HBITMAP)0x0) break;
    local_8 = local_8 + 1;
  }
  return pHVar1;
}


// ==== FUN_0040e80a @ 0040e80a

void FUN_0040e80a(void)

{
  DAT_0043ed98 = 0;
  return;
}


// ==== FUN_0040e824 @ 0040e824

bool __cdecl FUN_0040e824(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = DAT_0043ed98 < 0x40;
  if (bVar1) {
    *(undefined4 *)(&DAT_004885d8 + DAT_0043ed98 * 4) = param_1;
    DAT_0043ed98 = DAT_0043ed98 + 1;
  }
  return bVar1;
}


// ==== FUN_0040e863 @ 0040e863

undefined4 __cdecl FUN_0040e863(LPCSTR param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  
  if (DAT_0043ed98 < 0x40) {
    pHVar2 = LoadLibraryA(param_1);
    if (pHVar2 < (HMODULE)0x20) {
      uVar1 = 0;
    }
    else {
      *(HMODULE *)(&DAT_004885d8 + DAT_0043ed98 * 4) = pHVar2;
      DAT_0043ed98 = DAT_0043ed98 + 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040e8c3 @ 0040e8c3

bool __cdecl FUN_0040e8c3(LPCSTR param_1,uint *param_2)

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
  local_c = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_Microsoft_Microsoft_Gam_0043f024,0,0x20019,
                          &local_414);
  if (local_c == 0) {
    local_10 = 0x400;
    local_c = RegQueryValueExA(local_414,param_1,(LPDWORD)0x0,&local_8,(LPBYTE)local_410,&local_10);
    if ((local_c == 0) && (local_10 < 0x100)) {
      FUN_00432d40(param_2,local_410);
    }
    bVar1 = local_c == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ==== FUN_0040e99b @ 0040e99b

bool __cdecl FUN_0040e99b(LPCSTR param_1)

{
  HFILE hFile;
  
  hFile = _lopen(param_1,0);
  _lclose(hFile);
  return hFile != -1;
}


// ==== FUN_0040e9dd @ 0040e9dd

undefined4 FUN_0040e9dd(void)

{
  return 1;
}


// ==== FUN_0040e9f5 @ 0040e9f5

void __cdecl FUN_0040e9f5(uint *param_1)

{
  size_t sVar1;
  uint local_104 [64];
  
  GetWindowsDirectoryA((LPSTR)local_104,0x100);
  sVar1 = _strlen((char *)local_104);
  if (*(char *)((int)local_104 + sVar1) != '\\') {
    FUN_00432d50(local_104,(uint *)&DAT_0043f058);
  }
  FUN_00432d50(local_104,param_1);
  FUN_00432d40(param_1,local_104);
  return;
}


// ==== FUN_0040ea77 @ 0040ea77

undefined4 __cdecl FUN_0040ea77(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040e8c3(s_Shared_Path_0043f05c,local_104);
  FUN_00432d50(local_104,param_1);
  bVar1 = FUN_0040e99b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040e8c3(s_Shared_Path_0043f068,local_104);
    FUN_00432d50(local_104,(uint *)&DAT_0043f074);
    FUN_00432d50(local_104,param_1);
    bVar1 = FUN_0040e99b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_00432d40(local_104,(uint *)s___shared__0043f078);
      FUN_00432d50(local_104,param_1);
      bVar1 = FUN_0040e99b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_00432d40(local_104,(uint *)&DAT_0043f084);
        FUN_00432d50(local_104,param_1);
        bVar1 = FUN_0040e99b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00432d40(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00432d40(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00432d40(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00432d40(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040ec25 @ 0040ec25

undefined4 __cdecl FUN_0040ec25(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint local_104 [64];
  
  _memset(local_104,0,0x100);
  FUN_0040e8c3(s_Help_Path_0043f088,local_104);
  FUN_00432d50(local_104,param_1);
  bVar1 = FUN_0040e99b((LPCSTR)local_104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_0040e8c3(s_Help_Path_0043f094,local_104);
    FUN_00432d50(local_104,(uint *)&DAT_0043f0a0);
    FUN_00432d50(local_104,param_1);
    bVar1 = FUN_0040e99b((LPCSTR)local_104);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_00432d40(local_104,(uint *)&DAT_0043f0a4);
      FUN_00432d50(local_104,param_1);
      bVar1 = FUN_0040e99b((LPCSTR)local_104);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        FUN_00432d40(local_104,(uint *)s___shared__0043f0a8);
        FUN_00432d50(local_104,param_1);
        bVar1 = FUN_0040e99b((LPCSTR)local_104);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          uVar2 = 0;
        }
        else {
          FUN_00432d40(param_1,local_104);
          uVar2 = 1;
        }
      }
      else {
        FUN_00432d40(param_1,local_104);
        uVar2 = 1;
      }
    }
    else {
      FUN_00432d40(param_1,local_104);
      uVar2 = 1;
    }
  }
  else {
    FUN_00432d40(param_1,local_104);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0040edd3 @ 0040edd3

undefined4 __cdecl FUN_0040edd3(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_0043f020 < 0x400) && (param_1 != 0)) {
    *(int *)(&DAT_004886d8 + DAT_0043f020 * 4) = param_1;
    DAT_0043f020 = DAT_0043f020 + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0040ee1f @ 0040ee1f

void FUN_0040ee1f(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0043f020; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_004886d8 + local_8 * 4) != 0) {
      FreeResource(*(HGLOBAL *)(&DAT_004886d8 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_004886d8 + local_8 * 4) = 0;
  }
  DAT_0043f020 = 0;
  return;
}


// ==== FUN_0040ee90 @ 0040ee90

int __fastcall FUN_0040ee90(int param_1)

{
  bool bVar1;
  
  if ((*(int *)(param_1 + 0x1c) != 0) &&
     (*(int *)(&DAT_00443bc8 + *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200) !=
      0)) {
    if (*(int *)(&DAT_00443bc8 + *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200)
        == 0) {
      bVar1 = false;
    }
    else if (**(short **)
               (&DAT_00443bc8 + *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200) ==
             0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200)
                         + 6) *
          (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200)
                         + 8) -
          *(int *)(*(int *)(&DAT_00443bc8 +
                           *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200) + 2) ==
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
      return (int)**(short **)
                    (&DAT_00443bc8 +
                    *(int *)(param_1 + 0xac) * 0x28 + *(int *)(param_1 + 0xb0) * 200) / 2;
    }
  }
  return 0;
}


// ==== FUN_0040f04a @ 0040f04a

void __thiscall
FUN_0040f04a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined4 *)((int)this + 0xb0) = param_1;
  *(undefined4 *)((int)this + 0xb4) = param_2;
  *(undefined4 *)((int)this + 0xac) = param_3;
  *(undefined4 *)((int)this + 0xb8) = param_4;
  iVar1 = FUN_0040ee90((int)this);
  *(int *)((int)this + 8) = iVar1;
  return;
}


// ==== FUN_0040f0a0 @ 0040f0a0

void __fastcall FUN_0040f0a0(int *param_1)

{
  bool bVar1;
  int iVar2;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_1[7];
  if (iVar2 == 0) {
    return;
  }
  if (iVar2 != 1) {
    if (iVar2 != 2) {
      return;
    }
    if (param_1[0x31] == 0) {
      local_2c = 6;
      local_28 = (param_1[0x2b] + 2) * 0x16;
    }
    else if (param_1[0x31] == 1) {
      local_28 = 6;
      local_2c = (param_1[0x2b] + 2) * 0x16;
    }
    iVar2 = (*param_1 + DAT_004830f8) - local_28 / 2;
    local_c = iVar2 + local_28 + -1;
    local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
    local_8 = local_10 + local_2c + -1;
    FUN_0042df38(param_1 + 9,iVar2,local_10,local_c,local_8,0);
    if (param_1[0x31] != 0) {
      if (param_1[0x31] != 1) {
        return;
      }
      FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,*(short **)(&DAT_00442d30 + param_1[0x2c] * 0x78),0)
      ;
      if (param_1[0x2b] != 0) {
        for (local_20 = 0; local_20 < param_1[0x2b]; local_20 = local_20 + 1) {
          FUN_00427cf0(&DAT_0048d0f0,iVar2,(local_20 + 1) * 0x16 + local_10,
                       *(short **)(&DAT_00442d58 + param_1[0x2c] * 0x78),0);
        }
      }
      FUN_00427cf0(&DAT_0048d0f0,iVar2,(param_1[0x2b] + 1) * 0x16 + local_10,
                   *(short **)(&DAT_00442d80 + param_1[0x2c] * 0x78),0);
      return;
    }
    FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,*(short **)(&DAT_004831a0 + param_1[0x2c] * 0x78),0);
    if (param_1[0x2b] != 0) {
      for (local_20 = 0; local_20 < param_1[0x2b]; local_20 = local_20 + 1) {
        FUN_00427cf0(&DAT_0048d0f0,(local_20 + 1) * 0x16 + iVar2,local_10,
                     *(short **)(&DAT_004831c8 + param_1[0x2c] * 0x78),0);
      }
    }
    FUN_00427cf0(&DAT_0048d0f0,(param_1[0x2b] + 1) * 0x16 + iVar2,local_10,
                 *(short **)(&DAT_004831f0 + param_1[0x2c] * 0x78),0);
    return;
  }
  if (*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
LAB_0040f23c:
    local_28 = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040f23c;
    local_28 = (int)**(short **)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28);
  }
  if (*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
LAB_0040f3c6:
    local_2c = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040f3c6;
    local_2c = (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28)
                              + 2);
  }
  iVar2 = (*param_1 + DAT_004830f8) - local_28 / 2;
  local_c = iVar2 + local_28 + -1;
  local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
  local_8 = local_10 + local_2c + -1;
  FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,
               *(short **)(&DAT_00443bc8 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28),0);
  FUN_0040fd7a(param_1[0x2b],&local_18,&local_1c);
  if (*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
LAB_0040f5fa:
    local_28 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040f5fa;
    local_28 = (int)**(short **)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28);
  }
  if (*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
LAB_0040f784:
    local_2c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040f784;
    local_2c = (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2c] * 200 + param_1[0x2b] * 0x28)
                              + 2);
  }
  local_10 = ((param_1[1] + DAT_004830fc) - local_2c / 2) + local_1c;
  FUN_00427cf0(&DAT_0048d0f0,((*param_1 + DAT_004830f8) - local_28 / 2) + local_18,local_10,
               *(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2d] * 200),0);
  if (param_1[0x2e] == -1) {
    return;
  }
  local_14 = (int *)FUN_00413cbe((int)param_1);
  if (local_14 == (int *)0x0) {
    return;
  }
  if (*local_14 == 0) {
LAB_0040f8da:
    local_28 = 0;
  }
  else {
    if (*local_14 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_14 == 0x400) {
      if ((int)*(short *)(*local_14 + 6) * (int)*(short *)(*local_14 + 8) - *(int *)(*local_14 + 2)
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
    if (bVar1) goto LAB_0040f8da;
    local_28 = (int)*(short *)*local_14;
  }
  if (*local_14 != 0) {
    if (*local_14 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_14 == 0x400) {
      if ((int)*(short *)(*local_14 + 6) * (int)*(short *)(*local_14 + 8) - *(int *)(*local_14 + 2)
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
      local_2c = (int)*(short *)(*local_14 + 2);
      goto LAB_0040f990;
    }
  }
  local_2c = 0;
LAB_0040f990:
  local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*param_1 + DAT_004830f8) - local_28 / 2,local_10,(short *)*local_14,0)
  ;
  if (*(int *)(&DAT_00486f94 + param_1[0x30] * 4) == 3) {
    FUN_0040d9f2(param_1 + 0xd);
  }
  return;
}


// ==== FUN_0040fd7a @ 0040fd7a

void __cdecl FUN_0040fd7a(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  switch(param_1) {
  case 0:
    *param_2 = 0;
    *param_3 = 0;
    break;
  case 1:
    *param_2 = 0;
    *param_3 = 0xffffffff;
    break;
  case 2:
    *param_2 = 0;
    *param_3 = 0;
    break;
  case 3:
    *param_2 = 0xffffffff;
    *param_3 = 0;
    break;
  case 4:
    *param_2 = 0xffffffff;
    *param_3 = 0xffffffff;
  }
  return;
}


// ==== FUN_0040fe33 @ 0040fe33

void __fastcall FUN_0040fe33(int *param_1)

{
  bool bVar1;
  int iVar2;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_1[7];
  if (iVar2 == 0) {
    return;
  }
  if (iVar2 != 1) {
    if (iVar2 != 2) {
      return;
    }
    if (param_1[0x31] == 0) {
      local_2c = 6;
      local_28 = (param_1[0x2b] + 2) * 0x16;
    }
    else if (param_1[0x31] == 1) {
      local_28 = 6;
      local_2c = (param_1[0x2b] + 2) * 0x16;
    }
    iVar2 = (*param_1 + DAT_004830f8) - local_28 / 2;
    local_c = iVar2 + local_28 + -1;
    local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
    local_8 = local_2c + local_10 + -1;
    FUN_0042df38(param_1 + 9,iVar2,local_10,local_c,local_8,0);
    if (param_1[0x31] != 0) {
      if (param_1[0x31] != 1) {
        return;
      }
      FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,*(short **)(&DAT_00442d30 + param_1[0x2c] * 0x78),0)
      ;
      if (param_1[0x2b] != 0) {
        for (local_20 = 0; local_20 < param_1[0x2b]; local_20 = local_20 + 1) {
          FUN_00427cf0(&DAT_0048d0f0,iVar2,(local_20 + 1) * 0x16 + local_10,
                       *(short **)(&DAT_00442d58 + param_1[0x2c] * 0x78),0);
        }
      }
      FUN_00427cf0(&DAT_0048d0f0,iVar2,(param_1[0x2b] + 1) * 0x16 + local_10,
                   *(short **)(&DAT_00442d80 + param_1[0x2c] * 0x78),0);
      return;
    }
    FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,*(short **)(&DAT_004831a0 + param_1[0x2c] * 0x78),0);
    if (param_1[0x2b] != 0) {
      for (local_20 = 0; local_20 < param_1[0x2b]; local_20 = local_20 + 1) {
        FUN_00427cf0(&DAT_0048d0f0,(local_20 + 1) * 0x16 + iVar2,local_10,
                     *(short **)(&DAT_004831c8 + param_1[0x2c] * 0x78),0);
      }
    }
    FUN_00427cf0(&DAT_0048d0f0,(param_1[0x2b] + 1) * 0x16 + iVar2,local_10,
                 *(short **)(&DAT_004831f0 + param_1[0x2c] * 0x78),0);
    return;
  }
  if (*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_0040ffcf:
    local_28 = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0040ffcf;
    local_28 = (int)**(short **)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200);
  }
  if (*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_00410159:
    local_2c = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00410159;
    local_2c = (int)*(short *)(*(int *)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200)
                              + 2);
  }
  iVar2 = (*param_1 + DAT_004830f8) - local_28 / 2;
  local_c = iVar2 + local_28 + -1;
  local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
  local_8 = local_2c + local_10 + -1;
  FUN_0042df38(param_1 + 9,iVar2,local_10,local_c,local_8,0);
  FUN_00427cf0(&DAT_0048d0f0,iVar2,local_10,
               *(short **)(&DAT_00443bc8 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200),0);
  FUN_0040fd7a(param_1[0x2b],&local_18,&local_1c);
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_004103aa:
    local_28 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_004103aa;
    local_28 = (int)**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200);
  }
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_00410534:
    local_2c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00410534;
    local_2c = (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200)
                              + 2);
  }
  local_10 = ((param_1[1] + DAT_004830fc) - local_2c / 2) + local_1c;
  FUN_00427cf0(&DAT_0048d0f0,((*param_1 + DAT_004830f8) - local_28 / 2) + local_18,local_10,
               *(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2d] * 200),0);
  if (param_1[0x2e] == -1) {
    return;
  }
  local_14 = (int *)FUN_00413cbe((int)param_1);
  if (local_14 == (int *)0x0) {
    return;
  }
  if (*local_14 == 0) {
LAB_0041068a:
    local_28 = 0;
  }
  else {
    if (*local_14 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_14 == 0x400) {
      if ((int)*(short *)(*local_14 + 6) * (int)*(short *)(*local_14 + 8) - *(int *)(*local_14 + 2)
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
    if (bVar1) goto LAB_0041068a;
    local_28 = (int)*(short *)*local_14;
  }
  if (*local_14 != 0) {
    if (*local_14 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_14 == 0x400) {
      if ((int)*(short *)(*local_14 + 6) * (int)*(short *)(*local_14 + 8) - *(int *)(*local_14 + 2)
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
      local_2c = (int)*(short *)(*local_14 + 2);
      goto LAB_00410740;
    }
  }
  local_2c = 0;
LAB_00410740:
  local_10 = (param_1[1] + DAT_004830fc) - local_2c / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*param_1 + DAT_004830f8) - local_28 / 2,local_10,(short *)*local_14,0)
  ;
  if (*(int *)(&DAT_00486f94 + param_1[0x30] * 4) == 3) {
    FUN_0040d9f2(param_1 + 0xd);
  }
  return;
}


// ==== FUN_00410b2a @ 00410b2a

void __thiscall FUN_00410b2a(void *this,HDC param_1)

{
  int iVar1;
  bool bVar2;
  HDC hdc;
  HGDIOBJ h;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)((int)this + 0x1c);
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      if (*(int *)((int)this + 0xc4) == 0) {
        local_3c = 6;
        local_34 = (*(int *)((int)this + 0xac) + 2) * 0x16;
      }
      else if (*(int *)((int)this + 0xc4) == 1) {
        local_34 = 6;
        local_3c = (*(int *)((int)this + 0xac) + 2) * 0x16;
      }
      local_38 = (*(int *)this + DAT_004830f8) - local_34 / 2;
      local_10 = local_38 + local_34 + -1;
      local_18 = (*(int *)((int)this + 4) + DAT_004830fc) - local_3c / 2;
      local_c = local_18 + local_3c + -1;
      FUN_0042df38((void *)((int)this + 0x24),local_38,local_18,local_10,local_c,0);
      local_14 = local_18;
      local_8 = local_34;
      local_1c = local_3c;
      if (*(int *)((int)this + 0xc4) == 0) {
        FUN_00427cf0(&DAT_0048d0f0,local_38,local_18,
                     *(short **)(&DAT_004831a0 + *(int *)((int)this + 0xb0) * 0x78),0);
        if (*(int *)((int)this + 0xac) != 0) {
          for (local_2c = 0; local_2c < *(int *)((int)this + 0xac); local_2c = local_2c + 1) {
            FUN_00427cf0(&DAT_0048d0f0,(local_2c + 1) * 0x16 + local_38,local_18,
                         *(short **)(&DAT_004831c8 + *(int *)((int)this + 0xb0) * 0x78),0);
          }
        }
        FUN_00427cf0(&DAT_0048d0f0,(*(int *)((int)this + 0xac) + 1) * 0x16 + local_38,local_18,
                     *(short **)(&DAT_004831f0 + *(int *)((int)this + 0xb0) * 0x78),0);
      }
      else if (*(int *)((int)this + 0xc4) == 1) {
        FUN_00427cf0(&DAT_0048d0f0,local_38,local_18,
                     *(short **)(&DAT_00442d30 + *(int *)((int)this + 0xb0) * 0x78),0);
        if (*(int *)((int)this + 0xac) != 0) {
          for (local_2c = 0; local_2c < *(int *)((int)this + 0xac); local_2c = local_2c + 1) {
            FUN_00427cf0(&DAT_0048d0f0,local_38,(local_2c + 1) * 0x16 + local_18,
                         *(short **)(&DAT_00442d58 + *(int *)((int)this + 0xb0) * 0x78),0);
          }
        }
        FUN_00427cf0(&DAT_0048d0f0,local_38,(*(int *)((int)this + 0xac) + 1) * 0x16 + local_18,
                     *(short **)(&DAT_00442d80 + *(int *)((int)this + 0xb0) * 0x78),0);
      }
    }
    goto LAB_0041199d;
  }
  if (*(int *)(&DAT_00443bc8 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28)
      == 0) {
LAB_00410cfc:
    local_34 = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 +
                *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)
               (&DAT_00443bc8 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443bc8 +
                           *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) + 2
                  ) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00410cfc;
    local_34 = (int)**(short **)
                      (&DAT_00443bc8 +
                      *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28);
  }
  if (*(int *)(&DAT_00443bc8 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28)
      == 0) {
LAB_00410eb0:
    local_3c = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 +
                *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)
               (&DAT_00443bc8 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443bc8 +
                           *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) + 2
                  ) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00410eb0;
    local_3c = (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                       *(int *)((int)this + 0xb0) * 200 +
                                       *(int *)((int)this + 0xac) * 0x28) + 2);
  }
  local_38 = (*(int *)this + DAT_004830f8) - local_34 / 2;
  local_10 = local_38 + local_34 + -1;
  local_18 = (*(int *)((int)this + 4) + DAT_004830fc) - local_3c / 2;
  local_c = local_18 + local_3c + -1;
  FUN_0042df38((void *)((int)this + 0x24),local_38,local_18,local_10,local_c,0);
  FUN_00427cf0(&DAT_0048d0f0,local_38,local_18,
               *(short **)
                (&DAT_00443bc8 +
                *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28),0);
  FUN_0040fd7a(*(undefined4 *)((int)this + 0xac),&local_24,&local_28);
  local_14 = local_18;
  local_8 = local_34;
  local_1c = local_3c;
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28)
      == 0) {
LAB_00411155:
    local_34 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 +
                *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)
               (&DAT_00443190 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443190 +
                           *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) + 2
                  ) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00411155;
    local_34 = (int)**(short **)
                      (&DAT_00443190 +
                      *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28);
  }
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28)
      == 0) {
LAB_00411318:
    local_3c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 +
                *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) == 0) {
      bVar2 = false;
    }
    else if (**(short **)
               (&DAT_00443190 + *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xb0) * 200 +
                                  *(int *)((int)this + 0xac) * 0x28) + 8) -
          *(int *)(*(int *)(&DAT_00443190 +
                           *(int *)((int)this + 0xb0) * 200 + *(int *)((int)this + 0xac) * 0x28) + 2
                  ) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00411318;
    local_3c = (int)*(short *)(*(int *)(&DAT_00443190 +
                                       *(int *)((int)this + 0xb0) * 200 +
                                       *(int *)((int)this + 0xac) * 0x28) + 2);
  }
  local_18 = ((*(int *)((int)this + 4) + DAT_004830fc) - local_3c / 2) + local_28;
  FUN_00427cf0(&DAT_0048d0f0,((*(int *)this + DAT_004830f8) - local_34 / 2) + local_24,local_18,
               *(short **)
                (&DAT_00443190 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb4) * 200),0);
  if (*(int *)((int)this + 0xb8) == -1) goto LAB_0041199d;
  local_20 = (int *)FUN_00413cbe((int)this);
  if (local_20 == (int *)0x0) {
    return;
  }
  if (*local_20 == 0) {
LAB_00411480:
    local_34 = 0;
  }
  else {
    if (*local_20 == 0) {
      bVar2 = false;
    }
    else if (*(short *)*local_20 == 0x400) {
      if ((int)*(short *)(*local_20 + 6) * (int)*(short *)(*local_20 + 8) - *(int *)(*local_20 + 2)
          == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00411480;
    local_34 = (int)*(short *)*local_20;
  }
  if (*local_20 == 0) {
LAB_00411539:
    local_3c = 0;
  }
  else {
    if (*local_20 == 0) {
      bVar2 = false;
    }
    else if (*(short *)*local_20 == 0x400) {
      if ((int)*(short *)(*local_20 + 6) * (int)*(short *)(*local_20 + 8) - *(int *)(*local_20 + 2)
          == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_00411539;
    local_3c = (int)*(short *)(*local_20 + 2);
  }
  local_18 = (*(int *)((int)this + 4) + DAT_004830fc) - local_3c / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*(int *)this + DAT_004830f8) - local_34 / 2,local_18,
               (short *)*local_20,0);
  if (*(int *)(&DAT_00486f94 + *(int *)((int)this + 0xc0) * 4) == 3) {
    FUN_0040d9f2((int *)((int)this + 0x34));
  }
LAB_0041199d:
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,local_38,local_14,local_8,local_1c,hdc,local_38,local_14,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00411a29 @ 00411a29

void __fastcall FUN_00411a29(int *param_1)

{
  bool bVar1;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  if (param_1[7] != 1) {
    return;
  }
  if (param_1[0x2e] == -1) {
    return;
  }
  param_1[0x2a] = 0;
  if ((*(int *)(&DAT_00486f94 + param_1[0x30] * 4) == 3) && (param_1[0x23] != 0)) {
    param_1[0x24] = param_1[0x25];
    param_1[0x23] = 0;
  }
  FUN_0040fd7a(param_1[0x2b],&local_10,&local_14);
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_00411c50:
    local_1c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00411c50;
    local_1c = (int)**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200);
  }
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_00411dda:
    local_20 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00411dda;
    local_20 = (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200)
                              + 2);
  }
  local_8 = ((param_1[1] + DAT_004830fc) - local_20 / 2) + local_14;
  FUN_00427cf0(&DAT_0048d0f0,((*param_1 + DAT_004830f8) - local_1c / 2) + local_10,local_8,
               *(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2d] * 200),0);
  local_c = (int *)FUN_00413cbe((int)param_1);
  if (local_c == (int *)0x0) {
    return;
  }
  if (*local_c == 0) {
LAB_00411f1b:
    local_1c = 0;
  }
  else {
    if (*local_c == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_c == 0x400) {
      if ((int)*(short *)(*local_c + 6) * (int)*(short *)(*local_c + 8) - *(int *)(*local_c + 2) ==
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
    if (bVar1) goto LAB_00411f1b;
    local_1c = (int)*(short *)*local_c;
  }
  if (*local_c != 0) {
    if (*local_c == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_c == 0x400) {
      if ((int)*(short *)(*local_c + 6) * (int)*(short *)(*local_c + 8) - *(int *)(*local_c + 2) ==
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
      local_20 = (int)*(short *)(*local_c + 2);
      goto LAB_00411fd1;
    }
  }
  local_20 = 0;
LAB_00411fd1:
  local_8 = (param_1[1] + DAT_004830fc) - local_20 / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*param_1 + DAT_004830f8) - local_1c / 2,local_8,(short *)*local_c,0);
  if (*(int *)(&DAT_00486f94 + param_1[0x30] * 4) == 3) {
    FUN_0040d9f2(param_1 + 0xd);
  }
  return;
}


// ==== FUN_0041205f @ 0041205f

void __fastcall FUN_0041205f(int *param_1)

{
  bool bVar1;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1[7] != 1) {
    return;
  }
  param_1[0x2a] = 1;
  if ((*(int *)(&DAT_00486f94 + param_1[0x30] * 4) == 3) && (param_1[0x23] = 1, param_1[0x24] != 0))
  {
    param_1[0x25] = param_1[0x24];
    param_1[0x24] = 0;
  }
  FUN_0040fd7a(param_1[0x2b],&local_c,&local_10);
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_0041227e:
    local_18 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041227e;
    local_18 = (int)**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200);
  }
  if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
LAB_00412408:
    local_1c = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 6)
          * (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 8
                           ) -
          *(int *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200) + 2) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00412408;
    local_1c = (int)*(short *)(*(int *)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2c] * 200)
                              + 2);
  }
  local_8 = ((param_1[1] + DAT_004830fc) - local_1c / 2) + local_10;
  FUN_00427cf0(&DAT_0048d0f0,((*param_1 + DAT_004830f8) - local_18 / 2) + local_c,local_8,
               *(short **)(&DAT_00443190 + param_1[0x2b] * 0x28 + param_1[0x2d] * 200),0);
  if (DAT_00443118 == (short *)0x0) {
LAB_00412530:
    local_18 = 0;
  }
  else {
    if (*DAT_00443118 == 0x400) {
      if ((int)DAT_00443118[3] * (int)DAT_00443118[4] - *(int *)(DAT_00443118 + 1) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00412530;
    local_18 = (int)*DAT_00443118;
  }
  if (DAT_00443118 != (short *)0x0) {
    if (*DAT_00443118 == 0x400) {
      if ((int)DAT_00443118[3] * (int)DAT_00443118[4] - *(int *)(DAT_00443118 + 1) == 0) {
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
      local_1c = (int)DAT_00443118[1];
      goto LAB_004125e2;
    }
  }
  local_1c = 0;
LAB_004125e2:
  local_8 = (param_1[1] + DAT_004830fc) - local_1c / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*param_1 + DAT_004830f8) - local_18 / 2,local_8,DAT_00443118,0);
  return;
}


// ==== FUN_00412649 @ 00412649

void __thiscall FUN_00412649(void *this,HDC param_1)

{
  bool bVar1;
  HDC hdc;
  HGDIOBJ h;
  int x;
  int local_30;
  int local_28;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)((int)this + 0x1c) != 1) {
    return;
  }
  if (*(int *)((int)this + 0xb8) == -1) {
    return;
  }
  FUN_0040fd7a(*(undefined4 *)((int)this + 0xac),&local_1c,&local_20);
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200)
      == 0) {
LAB_00412813:
    local_28 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)
               (&DAT_00443190 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 8) -
          *(int *)(*(int *)(&DAT_00443190 +
                           *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) + 2
                  ) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00412813;
    local_28 = (int)**(short **)
                      (&DAT_00443190 +
                      *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200);
  }
  if (*(int *)(&DAT_00443190 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200)
      == 0) {
LAB_0041299d:
    local_30 = 0;
  }
  else {
    if (*(int *)(&DAT_00443190 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)
               (&DAT_00443190 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443190 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 8) -
          *(int *)(*(int *)(&DAT_00443190 +
                           *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) + 2
                  ) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_0041299d;
    local_30 = (int)*(short *)(*(int *)(&DAT_00443190 +
                                       *(int *)((int)this + 0xac) * 0x28 +
                                       *(int *)((int)this + 0xb0) * 200) + 2);
  }
  x = ((*(int *)this + DAT_004830f8) - local_28 / 2) + local_1c;
  local_10 = ((*(int *)((int)this + 4) + DAT_004830fc) - local_30 / 2) + local_20;
  FUN_00427cf0(&DAT_0048d0f0,x,local_10,
               *(short **)
                (&DAT_00443190 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb4) * 200),0);
  local_c = local_10;
  local_8 = local_28;
  local_14 = local_30;
  local_18 = (int *)FUN_00413cbe((int)this);
  if (local_18 == (int *)0x0) goto LAB_00412c30;
  if (*local_18 == 0) {
LAB_00412af6:
    local_28 = 0;
  }
  else {
    if (*local_18 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_18 == 0x400) {
      if ((int)*(short *)(*local_18 + 6) * (int)*(short *)(*local_18 + 8) - *(int *)(*local_18 + 2)
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
    if (bVar1) goto LAB_00412af6;
    local_28 = (int)*(short *)*local_18;
  }
  if (*local_18 == 0) {
LAB_00412ba0:
    local_30 = 0;
  }
  else {
    if (*local_18 == 0) {
      bVar1 = false;
    }
    else if (*(short *)*local_18 == 0x400) {
      if ((int)*(short *)(*local_18 + 6) * (int)*(short *)(*local_18 + 8) - *(int *)(*local_18 + 2)
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
    if (bVar1) goto LAB_00412ba0;
    local_30 = (int)*(short *)(*local_18 + 2);
  }
  local_10 = (*(int *)((int)this + 4) + DAT_004830fc) - local_30 / 2;
  FUN_00427cf0(&DAT_0048d0f0,(*(int *)this + DAT_004830f8) - local_28 / 2,local_10,
               (short *)*local_18,0);
  if (*(int *)(&DAT_00486f94 + *(int *)((int)this + 0xc0) * 4) == 3) {
    FUN_0040d9f2((int *)((int)this + 0x34));
  }
LAB_00412c30:
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,x,local_c,local_8,local_14,hdc,x,local_c,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_00412cbc @ 00412cbc

void __thiscall FUN_00412cbc(void *this,HDC param_1)

{
  bool bVar1;
  HDC hdc;
  HGDIOBJ h;
  int x;
  int y;
  uint uVar2;
  int local_14;
  int local_10;
  
  if (*(int *)((int)this + 0x1c) != 1) {
    return;
  }
  if (*(int *)(&DAT_00443bc8 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200)
      == 0) {
LAB_00412e57:
    local_10 = 0;
  }
  else {
    if (*(int *)(&DAT_00443bc8 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)
               (&DAT_00443bc8 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 8) -
          *(int *)(*(int *)(&DAT_00443bc8 +
                           *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) + 2
                  ) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) goto LAB_00412e57;
    local_10 = (int)**(short **)
                      (&DAT_00443bc8 +
                      *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200);
  }
  if (*(int *)(&DAT_00443bc8 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200)
      != 0) {
    if (*(int *)(&DAT_00443bc8 +
                *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) == 0) {
      bVar1 = false;
    }
    else if (**(short **)
               (&DAT_00443bc8 + *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200
               ) == 0x400) {
      if ((int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 6) *
          (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                  *(int *)((int)this + 0xac) * 0x28 +
                                  *(int *)((int)this + 0xb0) * 200) + 8) -
          *(int *)(*(int *)(&DAT_00443bc8 +
                           *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200) + 2
                  ) == 0) {
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
      local_14 = (int)*(short *)(*(int *)(&DAT_00443bc8 +
                                         *(int *)((int)this + 0xac) * 0x28 +
                                         *(int *)((int)this + 0xb0) * 200) + 2);
      goto LAB_00412fed;
    }
  }
  local_14 = 0;
LAB_00412fed:
  x = (*(int *)this + DAT_004830f8) - local_10 / 2;
  y = (*(int *)((int)this + 4) + DAT_004830fc) - local_14 / 2;
  uVar2 = (int)*(uint *)((int)this + 200) >> 0x1f;
  if (((*(uint *)((int)this + 200) ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
    FUN_00427cf0(&DAT_0048d0f0,x,y,
                 *(short **)
                  (&DAT_00443bc8 +
                  *(int *)((int)this + 0xac) * 0x28 + *(int *)((int)this + 0xb0) * 200),0);
  }
  else {
    FUN_00427cf0(&DAT_0048d0f0,x,y,*(short **)(&DAT_00444078 + *(int *)((int)this + 0xac) * 0x28),0)
    ;
  }
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,x,y,local_10,local_14,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041314e @ 0041314e

void __fastcall FUN_0041314e(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_14;
  int local_8;
  
  iVar1 = FUN_00405e69(5);
  param_1[0x2b] = iVar1;
  param_1[0x2e] = -1;
  if (param_1[7] == 1) {
    iVar1 = FUN_00405e69(6);
    param_1[0x2d] = iVar1;
    iVar1 = FUN_0040ee90((int)param_1);
    param_1[2] = iVar1;
    iVar1 = FUN_0042d60b(param_1 + 3);
    iVar4 = FUN_0042d61b((int)(param_1 + 3));
    iVar5 = iVar1 + param_1[2] * -2;
    iVar6 = iVar4 + param_1[2] * -2;
    iVar2 = FUN_00405e69(iVar5);
    iVar3 = FUN_00405e69(iVar6);
    *param_1 = param_1[3] + iVar1 / 2 + (iVar2 - iVar5 / 2);
    param_1[1] = param_1[4] + iVar4 / 2 + (iVar3 - iVar6 / 2);
    param_1[0x2f] = 0;
    iVar1 = FUN_00405e69(DAT_00486f90);
    param_1[0x30] = iVar1;
    iVar1 = *(int *)(&DAT_00486f94 + param_1[0x30] * 4);
    if (*(int *)(&DAT_00487af0 + iVar1 * 4) != 0) {
      iVar4 = FUN_00405e69(*(int *)(&DAT_00487af0 + iVar1 * 4));
      param_1[0x2e] = iVar4;
      switch(iVar1) {
      case 0:
      case 1:
      case 2:
      case 5:
      case 6:
      case 7:
        iVar4 = FUN_00405e69(*(int *)(&DAT_00486a78 + param_1[0x2e] * 4 + iVar1 * 0x18));
        param_1[0x2f] = iVar4;
        iVar1 = FUN_00405e69(*(int *)(&DAT_004835e8 +
                                     iVar1 * 0x4b0 +
                                     param_1[0x2b] * 0xf0 + param_1[0x2e] * 0x28 + param_1[0x2f] * 4
                                     ));
        param_1[8] = iVar1 + 1;
        break;
      case 3:
        FUN_0040d3e0(param_1 + 0xd,*param_1 + DAT_004830f8,param_1[1] + DAT_004830fc,param_1[0x2b],
                     param_1[0x2e]);
        iVar1 = FUN_00405e69(*(int *)(&DAT_004835e8 +
                                     iVar1 * 0x4b0 +
                                     param_1[0x2b] * 0xf0 + param_1[0x2e] * 0x28 + param_1[0x2f] * 4
                                     ));
        param_1[8] = iVar1 + 1;
        break;
      case 4:
        iVar4 = FUN_00405e69(2);
        param_1[0x2f] = iVar4;
        iVar1 = FUN_00405e69(*(int *)(&DAT_004835e8 +
                                     iVar1 * 0x4b0 +
                                     param_1[0x2b] * 0xf0 + param_1[0x2e] * 0x28 + param_1[0x2f] * 4
                                     ));
        param_1[8] = iVar1 + 1;
        break;
      case 8:
        iVar4 = FUN_00405e69(*(int *)(&DAT_00486a78 + param_1[0x2e] * 4 + iVar1 * 0x18));
        param_1[0x2f] = iVar4;
        iVar1 = FUN_00405e69(*(int *)(&DAT_004835e8 +
                                     iVar1 * 0x4b0 +
                                     param_1[0x2b] * 0xf0 + param_1[0x2e] * 0x28 + param_1[0x2f] * 4
                                     ));
        param_1[8] = iVar1 + 1;
      }
    }
  }
  else if (param_1[7] == 2) {
    iVar1 = FUN_00405e69(2);
    param_1[0x31] = iVar1;
    if (param_1[0x31] == 0) {
      local_14 = 6;
      local_8 = (param_1[0x2b] + 2) * 0x16;
    }
    else if (param_1[0x31] == 1) {
      local_8 = 6;
      local_14 = (param_1[0x2b] + 2) * 0x16;
    }
    iVar1 = FUN_0042d60b(param_1 + 3);
    iVar4 = FUN_0042d61b((int)(param_1 + 3));
    iVar5 = FUN_00405e69(iVar1 - local_8);
    iVar6 = FUN_00405e69(iVar4 - local_14);
    *param_1 = param_1[3] + iVar1 / 2 + (iVar5 - (iVar1 - local_8) / 2);
    param_1[1] = param_1[4] + iVar4 / 2 + (iVar6 - (iVar4 - local_14) / 2);
  }
  return;
}


// ==== FUN_00413669 @ 00413669

void __thiscall FUN_00413669(void *this,int param_1)

{
  int iVar1;
  
  if (*(int *)((int)this + 0x1c) != 0) {
    if (param_1 == -1) {
      iVar1 = FUN_00405e69(6);
      *(int *)((int)this + 0xb0) = iVar1;
    }
    else {
      *(int *)((int)this + 0xb0) = param_1;
    }
    FUN_0041314e(this);
  }
  return;
}


// ==== FUN_004136c9 @ 004136c9

void __thiscall FUN_004136c9(void *this,int param_1)

{
  int iVar1;
  int aiStack_24 [6];
  int local_c;
  int local_8;
  
  if (*(int *)((int)this + 0x1c) != 0) {
    local_8 = 0;
    for (local_c = 0; local_c < 6; local_c = local_c + 1) {
      if (*(int *)(param_1 + local_c * 4) < 2) {
        aiStack_24[local_8] = local_c;
        local_8 = local_8 + 1;
      }
    }
    iVar1 = FUN_00405e69(local_8);
    *(int *)((int)this + 0xb0) = aiStack_24[iVar1];
    if ((*(int *)((int)this + 0xb0) < 0) || (5 < *(int *)((int)this + 0xb0))) {
      *(undefined4 *)((int)this + 0xb0) = 0;
    }
    if (*(int *)(param_1 + *(int *)((int)this + 0xb0) * 4) == 0) {
      local_8 = 0;
      for (local_c = 0; local_c < 6; local_c = local_c + 1) {
        if (0 < *(int *)(param_1 + local_c * 4)) {
          aiStack_24[local_8] = local_c;
          local_8 = local_8 + 1;
        }
      }
      iVar1 = FUN_00405e69(local_8);
      *(int *)((int)this + 0xb0) = aiStack_24[iVar1];
      if (*(int *)(param_1 + *(int *)((int)this + 0xb0) * 4) == 0) {
        for (local_c = 0; local_c < 6; local_c = local_c + 1) {
          if (0 < *(int *)(param_1 + local_c * 4)) {
            *(int *)((int)this + 0xb0) = local_c;
            break;
          }
        }
      }
    }
    FUN_0041314e(this);
  }
  return;
}


// ==== FUN_00413849 @ 00413849

undefined4 __thiscall FUN_00413849(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_8;
  
  if (*(int *)((int)this + 0x1c) == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = *param_1 - DAT_004830f8;
    iVar3 = param_1[1] - DAT_004830fc;
    if (*(int *)((int)this + 0x1c) == 1) {
      iVar3 = iVar3 - *(int *)((int)this + 4);
      if (*(int *)((int)this + 8) * *(int *)((int)this + 8) <
          iVar3 * iVar3 + (iVar2 - *(int *)this) * (iVar2 - *(int *)this)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else if (*(int *)((int)this + 0x1c) == 2) {
      if (*(int *)((int)this + 0xc4) == 0) {
        local_1c = 6;
        local_8 = (*(int *)((int)this + 0xac) + 2) * 0x16;
      }
      else if (*(int *)((int)this + 0xc4) == 1) {
        local_8 = 6;
        local_1c = (*(int *)((int)this + 0xac) + 2) * 0x16;
      }
      iVar4 = *(int *)this - local_8 / 2;
      iVar5 = *(int *)((int)this + 4) - local_1c / 2;
      if ((((iVar2 < iVar4) || (iVar4 + local_8 + -1 < iVar2)) || (iVar3 < iVar5)) ||
         (local_1c + iVar5 + -1 < iVar3)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00413a04 @ 00413a04

undefined4 __thiscall
FUN_00413a04(void *this,int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (*(int *)((int)this + 0x1c) == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00413849(this,param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_00413849(this,param_2);
      if (iVar2 == 0) {
        iVar2 = FUN_00413849(this,param_3);
        if (iVar2 == 0) {
          local_c = (*param_2 + *param_1) / 2;
          local_8 = (param_1[1] + param_2[1]) / 2;
          iVar2 = FUN_00413849(this,&local_c);
          if (iVar2 == 0) {
            local_c = (*param_3 + *param_1) / 2;
            local_8 = (param_3[1] + param_1[1]) / 2;
            iVar2 = FUN_00413849(this,&local_c);
            if (iVar2 == 0) {
              uVar1 = 0;
            }
            else {
              *param_4 = 2;
              uVar1 = 1;
            }
          }
          else {
            *param_4 = 1;
            uVar1 = 1;
          }
        }
        else {
          *param_4 = 2;
          uVar1 = 1;
        }
      }
      else {
        *param_4 = 1;
        uVar1 = 1;
      }
    }
    else {
      *param_4 = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_00413b45 @ 00413b45

void __fastcall FUN_00413b45(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_00486f94 + *(int *)(param_1 + 0xc0) * 4);
  switch(iVar1) {
  case 0:
  case 1:
  case 2:
  case 5:
  case 6:
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
    if (*(int *)(&DAT_00486a78 + *(int *)(param_1 + 0xb8) * 4 + iVar1 * 0x18) <=
        *(int *)(param_1 + 0xbc)) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
    break;
  case 3:
    if (*(int *)(param_1 + 0xbc) < 3) {
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0xbc) = 3;
    }
    break;
  case 4:
    if (*(int *)(param_1 + 0xbc) < 9) {
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0xbc) = 9;
    }
    break;
  case 7:
    iVar1 = FUN_00405e69(*(int *)(&DAT_00486a78 + *(int *)(param_1 + 0xb8) * 4 + iVar1 * 0x18));
    *(int *)(param_1 + 0xbc) = iVar1;
    break;
  case 8:
    iVar1 = FUN_00405e69(*(int *)(&DAT_00486a78 + *(int *)(param_1 + 0xb8) * 4 + iVar1 * 0x18));
    *(int *)(param_1 + 0xbc) = iVar1;
  }
  return;
}


// ==== FUN_00413cbe @ 00413cbe

undefined * __fastcall FUN_00413cbe(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(&DAT_00486f94 + *(int *)(param_1 + 0xc0) * 4);
  if (*(int *)(param_1 + 0xb8) == -1) {
    return (undefined *)0x0;
  }
  switch(iVar1) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 5:
  case 7:
  case 8:
    return &DAT_004441d8 +
           iVar1 * 12000 +
           *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400 +
           *(int *)(param_1 + 0xbc) * 0x28;
  case 3:
    switch(*(undefined4 *)(param_1 + 0xbc)) {
    case 0:
    case 1:
      return &DAT_004441d8 +
             iVar1 * 12000 + *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400;
    case 2:
      return &DAT_00483520 + *(int *)(param_1 + 0xac) * 0x28;
    case 3:
      return (undefined *)0x0;
    }
switchD_00413f6a_caseD_6:
    switch(*(undefined4 *)(param_1 + 0xbc)) {
    case 0:
      puVar2 = &DAT_004441d8 +
               iVar1 * 12000 + *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400;
      break;
    case 1:
    case 3:
    case 5:
      puVar2 = &DAT_00444250 +
               iVar1 * 12000 + *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400;
      break;
    case 2:
      puVar2 = &DAT_00444200 +
               iVar1 * 12000 + *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400;
      break;
    case 4:
      puVar2 = &DAT_00444228 +
               iVar1 * 12000 + *(int *)(param_1 + 0xac) * 0x960 + *(int *)(param_1 + 0xb8) * 400;
      break;
    default:
switchD_00413f6a_default:
      puVar2 = (undefined *)0x0;
    }
    return puVar2;
  case 6:
    goto switchD_00413f6a_caseD_6;
  default:
    goto switchD_00413f6a_default;
  }
}


// ==== FUN_00413fa1 @ 00413fa1

void __fastcall FUN_00413fa1(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) =
       *(undefined4 *)
        (&DAT_004835e8 +
        *(int *)(&DAT_00486f94 + *(int *)(param_1 + 0xc0) * 4) * 0x4b0 +
        *(int *)(param_1 + 0xac) * 0xf0 + *(int *)(param_1 + 0xb8) * 0x28 +
        *(int *)(param_1 + 0xbc) * 4);
  return;
}


// ==== FUN_00414020 @ 00414020

/* WARNING: Removing unreachable block (ram,0x00418a1b) */
/* WARNING: Removing unreachable block (ram,0x00418a28) */
/* WARNING: Removing unreachable block (ram,0x00418a6b) */
/* WARNING: Removing unreachable block (ram,0x00418a8f) */
/* WARNING: Removing unreachable block (ram,0x00418a35) */
/* WARNING: Removing unreachable block (ram,0x00418a57) */
/* WARNING: Removing unreachable block (ram,0x00418a66) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00414020(void *this,HDC param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_1d4;
  int local_1cc;
  int local_1c4;
  int local_1bc;
  int local_1b4;
  int local_1ac;
  int local_1a4;
  int local_19c;
  int local_194;
  int local_18c;
  int local_184;
  int local_17c;
  int local_174;
  int local_134;
  int local_130;
  int local_12c;
  int local_128 [2];
  int local_120;
  int local_11c;
  int local_118 [6];
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int *local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint local_d0;
  int aiStack_cc [6];
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int aiStack_88 [18];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int aiStack_24 [8];
  
  if (DAT_0043e8bc == 0) {
    return;
  }
  DAT_0048d67c = 0;
  FUN_004064fb(&DAT_004616a8,param_1);
  DAT_0048d67c = 0;
  if (*(int *)((int)this + 0xd0) != 0) {
    DAT_0048d67c = 0;
    return;
  }
  local_134 = DAT_00480ed4;
  local_130 = DAT_00480ed8;
  local_2c = (DAT_00480ed4 - DAT_00480ecc) + _DAT_00480edc;
  local_28 = (DAT_00480ed8 - DAT_00480ed0) + _DAT_00480ee0;
  local_38 = (DAT_00480ed4 - DAT_00480ecc) + _DAT_00480ee4;
  local_34 = (DAT_00480ed8 - DAT_00480ed0) + _DAT_00480ee8;
  local_a0 = 0;
  local_d8 = 0;
LAB_00414121:
  if (7 < local_d8) goto LAB_0041af96;
  local_8c = *(int *)(&DAT_0044268c + local_d8 * 0xd0);
  if (local_8c == 0) goto switchD_0041af66_default;
  local_ec = (int *)(&DAT_00442670 + local_d8 * 0xd0);
  local_94 = *(int *)((int)this + *(int *)(&DAT_00442730 + local_d8 * 0xd0) * 4 + 0x424);
  local_3c = (int)this + local_94 * 100 + 0x44c;
  local_a8 = (int)this + local_94 * 100 + 0x8ac;
  piVar3 = (int *)((int)this + local_94 * 4 + 0x85c);
  piVar4 = (int *)((int)this + local_94 * 4 + 0xcbc);
  piVar5 = (int *)((int)this + local_94 * 4 + 0x834);
  piVar6 = (int *)((int)this + local_94 * 4 + 0xc94);
  iVar7 = FUN_00413a04(&DAT_00442670 + local_d8 * 0xd0,&local_134,&local_2c,&local_38,local_128);
  if (iVar7 == 0) goto LAB_0041a89a;
  _memset(local_118,0,0x18);
  if (local_8c == 1) {
    if (DAT_00480f24 == 2) {
      if ((int)(&DAT_00480f28)[DAT_00480fb4] == local_ec[0x2c]) goto LAB_00414315;
LAB_004184a7:
      if (*(int *)((int)this + 0xd28) == 0) {
        FUN_0040cf73(0xb);
        FUN_0042eac9(&DAT_00480ebc,param_1,0,0,-0x8000,-0x8000);
        _memset(&DAT_004616ac,0,0xfc04);
        _memset(&DAT_004712b4,0,0xfc04);
        if (DAT_00480f24 == 2) {
          iVar7 = _rand();
          (&DAT_00480f28)[DAT_00480fb4] =
               (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        else {
          iVar7 = _rand();
          DAT_00480f28 = (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        _DAT_00480ef4 = -1;
        _DAT_00480ef8 = -1;
        _DAT_00480efc = 0xffffffff;
        _DAT_00480f00 = 0xffffffff;
        _DAT_00480eec = 0xffffffff;
        _DAT_00480ef0 = 0xffffffff;
        _DAT_00480fa4 = 0;
        _DAT_00480fa8 = 0;
        _DAT_00480fac = 0;
        _DAT_00480f20 = 0xffffffff;
        cVar2 = DAT_00480f28;
        if (DAT_00480f24 == 2) {
          cVar2 = (&DAT_00480f28)[DAT_00480fb4];
        }
        local_d4 = (int)cVar2;
        cVar2 = DAT_00480f28;
        if (DAT_00480f24 == 2) {
          cVar2 = (&DAT_00480f28)[DAT_00480fb4 == 0];
        }
        local_dc = (int)cVar2;
        *(undefined4 *)((int)this + 0xd10) = 0;
        *(undefined4 *)((int)this + 0xd0c) = 0;
        FUN_0041e34f(this,local_94,0);
        FUN_0041f2f8(this,param_1);
        DAT_0048d67c = 0;
        local_ec[0x24] = 0;
        FUN_0042e249(local_ec + 9,0,0,-0x8000,-0x8000);
        local_ec[7] = 0;
        local_11c = 0;
        for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
          if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 0) {
            if (local_e0 != local_d8) {
              aiStack_24[local_11c] = local_e0;
              local_11c = local_11c + 1;
            }
          }
          else {
            local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] =
                 local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] + 1;
            if ((*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_d4) ||
               (*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_dc)) {
              local_a0 = 1;
            }
          }
        }
        if (local_11c != 0) {
          iVar7 = FUN_00405e69(local_11c);
          local_e0 = aiStack_24[iVar7];
          *(undefined4 *)(&DAT_0044268c + local_e0 * 0xd0) = 2;
          if (local_a0 == 0) {
            FUN_00413669(&DAT_00442670 + local_e0 * 0xd0,local_dc);
          }
          else {
            FUN_004136c9(&DAT_00442670 + local_e0 * 0xd0,(int)local_118);
          }
          FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
        }
        if (DAT_0048d67c != 0) {
          bVar1 = false;
          if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
            for (local_1b4 = 0; local_1b4 < DAT_0048d67c; local_1b4 = local_1b4 + 1) {
              FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1b4 * 0x10),
                           *(int *)(&DAT_0048d540 + local_1b4 * 0x10),
                           (*(int *)(&DAT_0048d544 + local_1b4 * 0x10) -
                           *(int *)(&DAT_0048d53c + local_1b4 * 0x10)) + 1,
                           (*(int *)(&DAT_0048d548 + local_1b4 * 0x10) -
                           *(int *)(&DAT_0048d540 + local_1b4 * 0x10)) + 1);
            }
            DAT_0048d67c = 0;
          }
          else {
            for (local_1b4 = 0; local_1b4 < DAT_0048d67c; local_1b4 = local_1b4 + 1) {
              if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1b4 * 0x10)) &&
                 (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1b4 * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_1b4 = 0; local_1b4 < DAT_0048d67c; local_1b4 = local_1b4 + 1) {
                FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1b4 * 0x10),
                             *(int *)(&DAT_0048d53c + local_1b4 * 0x10) - DAT_0048d694,
                             *(int *)(&DAT_0048d540 + local_1b4 * 0x10) - DAT_0048d698);
              }
            }
            else {
              for (local_1b4 = 0; local_1b4 < DAT_0048d67c; local_1b4 = local_1b4 + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1b4 * 0x10));
              }
            }
            DAT_0048d67c = 0;
          }
        }
      }
      else if (*(int *)((int)this + 0xd2c) != local_d8) {
        if (local_128[0] == 0) {
          local_e8 = local_134 - (*local_ec + DAT_004830f8);
          local_f8 = local_130 - (local_ec[1] + DAT_004830fc);
        }
        else if (local_128[0] == 1) {
          local_e8 = local_2c - (*local_ec + DAT_004830f8);
          local_f8 = local_28 - (local_ec[1] + DAT_004830fc);
        }
        else if (local_128[0] == 2) {
          local_e8 = local_38 - (*local_ec + DAT_004830f8);
          local_f8 = local_34 - (local_ec[1] + DAT_004830fc);
        }
        if (local_e8 < 0) {
          local_9c = -1;
        }
        else {
          local_9c = 1;
        }
        if (local_f8 < 0) {
          local_a4 = -1;
        }
        else {
          local_a4 = 1;
        }
        if ((DAT_00480fb8 < 0) && (DAT_00480fbc < 0)) {
          if ((local_9c < 1) || (local_a4 < 1)) {
            if ((local_9c < 0) && (0 < local_a4)) {
              if (local_f8 * local_9c - local_e8 * local_a4 < 0) {
                _DAT_00480f20 = 3;
              }
            }
            else if (0 < local_f8 * local_9c - local_e8 * local_a4) {
              _DAT_00480f20 = 2;
            }
          }
          else if (local_f8 * local_9c - local_e8 * local_a4 < 0) {
            _DAT_00480f20 = 2;
          }
          else {
            _DAT_00480f20 = 3;
          }
          *(int *)((int)this + 0xd2c) = local_d8;
        }
        else if ((DAT_00480fb8 < 1) || (-1 < DAT_00480fbc)) {
          if ((DAT_00480fb8 < 1) || (DAT_00480fbc < 1)) {
            if ((-1 < local_9c) || (local_a4 < 1)) {
              local_9c = 1;
              local_a4 = -1;
              if (local_f8 + local_e8 < 0) {
                _DAT_00480f20 = 1;
              }
              else {
                _DAT_00480f20 = 2;
              }
              *(int *)((int)this + 0xd2c) = local_d8;
            }
          }
          else {
            if ((local_9c < 0) && (local_a4 < 0)) {
              _DAT_00480f20 = (uint)(-1 < local_f8 * local_9c - local_e8 * local_a4);
            }
            else if ((local_9c < 1) || (-1 < local_a4)) {
              if (0 < local_f8 * local_9c - local_e8 * local_a4) {
                _DAT_00480f20 = 0;
              }
            }
            else if (local_f8 * local_9c - local_e8 * local_a4 < 0) {
              _DAT_00480f20 = 1;
            }
            *(int *)((int)this + 0xd2c) = local_d8;
          }
        }
        else if ((local_9c < 1) || (-1 < local_a4)) {
          if ((local_9c < 0) && (0 < local_a4)) {
            if (local_f8 * local_9c - local_e8 * local_a4 < 0) {
              _DAT_00480f20 = 3;
            }
            else {
              _DAT_00480f20 = 0;
            }
          }
          else if ((local_9c < 0) && (local_a4 < 0)) {
            if (local_f8 * local_9c - local_e8 * local_a4 < 0) {
              _DAT_00480f20 = 0;
            }
          }
          else if (0 < local_f8 * local_9c - local_e8 * local_a4) {
            _DAT_00480f20 = 3;
          }
          *(int *)((int)this + 0xd2c) = local_d8;
        }
      }
      goto LAB_0041a89a;
    }
    if ((int)DAT_00480f28 != local_ec[0x2c]) goto LAB_004184a7;
LAB_00414315:
    if (((local_94 == 6) &&
        (((local_ec[0x2f] == 1 || (local_ec[0x2f] == 3)) || (local_ec[0x2f] == 5)))) ||
       ((local_94 == 5 && (local_ec[0x2f] == 2)))) goto LAB_004184a7;
    switch(local_94) {
    case 0:
      iVar7 = FUN_00405e69(2);
      FUN_0040cf73(iVar7 + 0x18);
      break;
    case 1:
      iVar7 = local_ec[0x2f];
      if (iVar7 == 0) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      else if (iVar7 == 1) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      else if (iVar7 == 2) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      break;
    case 2:
      if (local_ec[0x2f] == 0) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      else if (local_ec[0x2f] == 1) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      break;
    case 3:
      switch(local_ec[0x2f]) {
      case 0:
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
        break;
      case 1:
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
        break;
      case 2:
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
        break;
      case 3:
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      break;
    case 4:
      if ((local_ec[0x2f] < 0) || (8 < local_ec[0x2f])) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      else {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      break;
    case 5:
      if (local_ec[0x2f] == 0) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      else if (local_ec[0x2f] == 1) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      break;
    case 6:
      iVar7 = local_ec[0x2f];
      if (iVar7 == 0) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      else if (iVar7 == 1) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      else if (iVar7 == 2) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
      else {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x27);
      }
    }
    *(undefined4 *)((int)this + 0xd2c) = 0xffffffff;
    *(int *)((int)this + 0xd0c) = *(int *)((int)this + 0xd0c) + 1;
    local_d4 = local_ec[0x2d];
    FUN_0042eac9(&DAT_00480ebc,param_1,0,0,-0x8000,-0x8000);
    _memset(&DAT_004616ac,0,0xfc04);
    _memset(&DAT_004712b4,0,0xfc04);
    if (DAT_00480f24 == 2) {
      if (local_d4 == -1) {
        iVar7 = _rand();
        (&DAT_00480f28)[DAT_00480fb4] =
             (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
      }
      else {
        (&DAT_00480f28)[DAT_00480fb4] = (char)local_d4;
      }
    }
    else if (local_d4 == -1) {
      iVar7 = _rand();
      DAT_00480f28 = (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
    }
    else {
      DAT_00480f28 = (char)local_d4;
    }
    _DAT_00480ef4 = -1;
    _DAT_00480ef8 = -1;
    _DAT_00480efc = 0xffffffff;
    _DAT_00480f00 = 0xffffffff;
    _DAT_00480eec = 0xffffffff;
    _DAT_00480ef0 = 0xffffffff;
    _DAT_00480fa4 = 0;
    _DAT_00480fa8 = 0;
    _DAT_00480fac = 0;
    _DAT_00480f20 = 0xffffffff;
    cVar2 = DAT_00480f28;
    if (DAT_00480f24 == 2) {
      cVar2 = (&DAT_00480f28)[DAT_00480fb4];
    }
    local_d4 = (int)cVar2;
    cVar2 = DAT_00480f28;
    if (DAT_00480f24 == 2) {
      cVar2 = (&DAT_00480f28)[DAT_00480fb4 == 0];
    }
    local_dc = (int)cVar2;
    DAT_0048d67c = 0;
    if (*(int *)((int)this + 0xd28) != 0) {
      *(int *)((int)this + 0xd28) = *(int *)((int)this + 0xd28) + -1;
      if (*(int *)((int)this + 0xd28) == 0) {
        FUN_004253c9((int)this);
      }
      else {
        FUN_004251e5((int)this);
      }
      if (local_94 == 6) {
        for (local_90 = 0; local_90 < 8; local_90 = local_90 + 1) {
          *(undefined4 *)(&DAT_00442738 + local_90 * 0xd0) = 0;
          *(undefined4 *)(&DAT_0044273c + local_90 * 0xd0) = 0;
          FUN_00412cbc(&DAT_00442670 + local_90 * 0xd0,param_1);
        }
        InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
        UpdateWindow(DAT_0048cc60);
      }
    }
    iVar7 = FUN_00405d47();
    FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
    FUN_00425ece((int)this);
    FUN_0041fc84(this);
    DAT_0043f0b4 = 0;
    if ((4 < *(int *)((int)this + 0xd0c)) ||
       ((0 < *(int *)((int)this + 0xd0c) &&
        (0 < *(int *)((int)this + *(int *)((int)this + 0x1c) * 4 + 0x1c))))) {
      FUN_0040cf73(0x15);
      if (4 < *(int *)((int)this + 0xd0c)) {
        DAT_0043f0b4 = 1;
      }
      *(undefined4 *)((int)this + 0xd0c) = 0;
      FUN_0041fd01(this,param_1);
      local_40 = *(int *)((int)this + *(int *)((int)this + 0x1c) * 4 + 0x1c);
      FUN_0041d404(this,param_1);
      local_d0 = 0;
      while ((*(int *)((int)this + 0x1c) != 0 &&
             (local_d0 = (uint)(*(int *)((int)this + *(int *)((int)this + 0x1c) * 4 + 0x1c) == 6),
             local_d0 != 0))) {
        FUN_0041d404(this,param_1);
      }
LAB_00414bc1:
      switch(local_40) {
      case 0:
        goto switchD_00416135_caseD_0;
      case 1:
        iVar7 = FUN_00405df3();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        if (*(int *)((int)this + 0xd30) < 5) {
          *(int *)((int)this + 0xd30) = *(int *)((int)this + 0xd30) + 1;
          FUN_0041dc95((int)this);
        }
        if (DAT_0048d67c == 0) break;
        bVar1 = false;
        if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
          for (local_174 = 0; local_174 < DAT_0048d67c; local_174 = local_174 + 1) {
            FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_174 * 0x10),
                         *(int *)(&DAT_0048d540 + local_174 * 0x10),
                         (*(int *)(&DAT_0048d544 + local_174 * 0x10) -
                         *(int *)(&DAT_0048d53c + local_174 * 0x10)) + 1,
                         (*(int *)(&DAT_0048d548 + local_174 * 0x10) -
                         *(int *)(&DAT_0048d540 + local_174 * 0x10)) + 1);
          }
          DAT_0048d67c = 0;
          break;
        }
        local_174 = 0;
        goto LAB_00414d27;
      case 2:
        iVar7 = FUN_00405df3();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
          if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 2) {
            local_f0 = *(int *)(&DAT_00442720 + local_e0 * 0xd0);
            *(undefined4 *)(&DAT_00442700 + local_e0 * 0xd0) = 0;
            FUN_0042e249(&DAT_00442694 + local_e0 * 0xd0,0,0,-0x8000,-0x8000);
            *(undefined4 *)(&DAT_0044268c + local_e0 * 0xd0) = 1;
            FUN_00413669(&DAT_00442670 + local_e0 * 0xd0,local_f0);
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
        }
        *(undefined4 *)((int)this + 0xd10) = 0;
        FUN_0041f72a((int)this);
        if (DAT_0048d67c != 0) {
          bVar1 = false;
          if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
            for (local_17c = 0; local_17c < DAT_0048d67c; local_17c = local_17c + 1) {
              FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_17c * 0x10),
                           *(int *)(&DAT_0048d540 + local_17c * 0x10),
                           (*(int *)(&DAT_0048d544 + local_17c * 0x10) -
                           *(int *)(&DAT_0048d53c + local_17c * 0x10)) + 1,
                           (*(int *)(&DAT_0048d548 + local_17c * 0x10) -
                           *(int *)(&DAT_0048d540 + local_17c * 0x10)) + 1);
            }
            DAT_0048d67c = 0;
          }
          else {
            for (local_17c = 0; local_17c < DAT_0048d67c; local_17c = local_17c + 1) {
              if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_17c * 0x10)) &&
                 (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_17c * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_17c = 0; local_17c < DAT_0048d67c; local_17c = local_17c + 1) {
                FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_17c * 0x10),
                             *(int *)(&DAT_0048d53c + local_17c * 0x10) - DAT_0048d694,
                             *(int *)(&DAT_0048d540 + local_17c * 0x10) - DAT_0048d698);
              }
            }
            else {
              for (local_17c = 0; local_17c < DAT_0048d67c; local_17c = local_17c + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_17c * 0x10));
              }
            }
            DAT_0048d67c = 0;
          }
        }
        break;
      case 3:
        iVar7 = FUN_00405df3();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        for (local_e0 = 0; local_e0 < 6; local_e0 = local_e0 + 1) {
          local_118[local_e0] = local_e0;
          aiStack_cc[local_e0] = local_e0;
        }
        for (local_e0 = 0; local_e0 < 0x1e; local_e0 = local_e0 + 1) {
          local_12c = FUN_00405e69(6);
          local_120 = FUN_00405e69(6);
          if (local_120 != local_12c) {
            local_fc = local_118[local_12c];
            local_118[local_12c] = local_118[local_120];
            local_118[local_120] = local_fc;
          }
        }
        for (local_e0 = 0; local_e0 < 0x1e; local_e0 = local_e0 + 1) {
          local_12c = FUN_00405e69(6);
          local_120 = FUN_00405e69(6);
          if (local_120 != local_12c) {
            local_fc = aiStack_cc[local_12c];
            aiStack_cc[local_12c] = aiStack_cc[local_120];
            aiStack_cc[local_120] = local_fc;
          }
        }
        aiStack_88[2] = 0;
        local_12c = 0;
        for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
          if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 2) {
            *(int *)(&DAT_00442720 + local_e0 * 0xd0) = local_118[local_12c];
            *(undefined4 *)(&DAT_00442700 + local_e0 * 0xd0) = 0;
            local_12c = local_12c + 1;
            FUN_0042e249(&DAT_00442694 + local_e0 * 0xd0,0,0,-0x8000,-0x8000);
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
          if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 1) {
            *(int *)(&DAT_00442720 + local_e0 * 0xd0) = local_118[local_12c];
            *(int *)(&DAT_00442724 + local_e0 * 0xd0) = aiStack_cc[local_12c];
            *(undefined4 *)(&DAT_004426fc + local_e0 * 0xd0) = 1;
            if (*(int *)(&DAT_00442700 + local_e0 * 0xd0) != 0) {
              *(undefined4 *)(&DAT_00442704 + local_e0 * 0xd0) =
                   *(undefined4 *)(&DAT_00442700 + local_e0 * 0xd0);
              *(undefined4 *)(&DAT_00442700 + local_e0 * 0xd0) = 0;
            }
            local_12c = local_12c + 1;
            FUN_0042e249(&DAT_00442694 + local_e0 * 0xd0,0,0,-0x8000,-0x8000);
            if (*(int *)(&DAT_004426fc + local_e0 * 0xd0) != 0) {
              *(undefined4 *)(&DAT_00442700 + local_e0 * 0xd0) =
                   *(undefined4 *)(&DAT_00442704 + local_e0 * 0xd0);
              *(undefined4 *)(&DAT_004426fc + local_e0 * 0xd0) = 0;
            }
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
        }
        if (DAT_0048d67c != 0) {
          bVar1 = false;
          if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
            for (local_184 = 0; local_184 < DAT_0048d67c; local_184 = local_184 + 1) {
              FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_184 * 0x10),
                           *(int *)(&DAT_0048d540 + local_184 * 0x10),
                           (*(int *)(&DAT_0048d544 + local_184 * 0x10) -
                           *(int *)(&DAT_0048d53c + local_184 * 0x10)) + 1,
                           (*(int *)(&DAT_0048d548 + local_184 * 0x10) -
                           *(int *)(&DAT_0048d540 + local_184 * 0x10)) + 1);
            }
            DAT_0048d67c = 0;
          }
          else {
            for (local_184 = 0; local_184 < DAT_0048d67c; local_184 = local_184 + 1) {
              if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_184 * 0x10)) &&
                 (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_184 * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_184 = 0; local_184 < DAT_0048d67c; local_184 = local_184 + 1) {
                FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_184 * 0x10),
                             *(int *)(&DAT_0048d53c + local_184 * 0x10) - DAT_0048d694,
                             *(int *)(&DAT_0048d540 + local_184 * 0x10) - DAT_0048d698);
              }
            }
            else {
              for (local_184 = 0; local_184 < DAT_0048d67c; local_184 = local_184 + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_184 * 0x10));
              }
            }
            DAT_0048d67c = 0;
          }
        }
        break;
      case 4:
        goto switchD_00416135_caseD_4;
      case 5:
        iVar7 = FUN_00405e19();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        if (DAT_0048d67c == 0) break;
        bVar1 = false;
        if ((DAT_0048d694 != 0) || (DAT_0048d698 != 0)) {
          local_18c = 0;
          goto LAB_00415a4b;
        }
        for (local_18c = 0; local_18c < DAT_0048d67c; local_18c = local_18c + 1) {
          FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_18c * 0x10),
                       *(int *)(&DAT_0048d540 + local_18c * 0x10),
                       (*(int *)(&DAT_0048d544 + local_18c * 0x10) -
                       *(int *)(&DAT_0048d53c + local_18c * 0x10)) + 1,
                       (*(int *)(&DAT_0048d548 + local_18c * 0x10) -
                       *(int *)(&DAT_0048d540 + local_18c * 0x10)) + 1);
        }
        DAT_0048d67c = 0;
        break;
      case 6:
        iVar7 = FUN_00405e19();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        if (DAT_0048d67c == 0) break;
        bVar1 = false;
        if ((DAT_0048d694 != 0) || (DAT_0048d698 != 0)) {
          local_194 = 0;
          goto LAB_00415cb8;
        }
        for (local_194 = 0; local_194 < DAT_0048d67c; local_194 = local_194 + 1) {
          FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_194 * 0x10),
                       *(int *)(&DAT_0048d540 + local_194 * 0x10),
                       (*(int *)(&DAT_0048d544 + local_194 * 0x10) -
                       *(int *)(&DAT_0048d53c + local_194 * 0x10)) + 1,
                       (*(int *)(&DAT_0048d548 + local_194 * 0x10) -
                       *(int *)(&DAT_0048d540 + local_194 * 0x10)) + 1);
        }
        DAT_0048d67c = 0;
        break;
      case 7:
        iVar7 = FUN_00405df3();
        FUN_0041c2b4(this,iVar7 * DAT_0043d3b0);
        FUN_00425ece((int)this);
        *(undefined4 *)((int)this + 0xd28) = 5;
        if (DAT_0048d67c == 0) goto LAB_0041607a;
        bVar1 = false;
        if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
          for (local_19c = 0; local_19c < DAT_0048d67c; local_19c = local_19c + 1) {
            FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_19c * 0x10),
                         *(int *)(&DAT_0048d540 + local_19c * 0x10),
                         (*(int *)(&DAT_0048d544 + local_19c * 0x10) -
                         *(int *)(&DAT_0048d53c + local_19c * 0x10)) + 1,
                         (*(int *)(&DAT_0048d548 + local_19c * 0x10) -
                         *(int *)(&DAT_0048d540 + local_19c * 0x10)) + 1);
          }
          DAT_0048d67c = 0;
          goto LAB_0041607a;
        }
        local_19c = 0;
        goto LAB_00415f35;
      default:
        break;
      }
      goto switchD_00416135_default;
    }
    goto LAB_00416476;
  }
  if (local_8c == 2) {
    if (DAT_00480f24 == 2) {
      if ((int)(&DAT_00480f28)[DAT_00480fb4] == local_ec[0x2c]) {
LAB_0041919e:
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
        *(undefined4 *)((int)this + 0xd2c) = 0xffffffff;
        local_f0 = local_ec[0x2c];
        FUN_0042eac9(&DAT_00480ebc,param_1,0,0,-0x8000,-0x8000);
        _memset(&DAT_004616ac,0,0xfc04);
        _memset(&DAT_004712b4,0,0xfc04);
        if (DAT_00480f24 == 2) {
          iVar7 = _rand();
          (&DAT_00480f28)[DAT_00480fb4] =
               (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        else {
          iVar7 = _rand();
          DAT_00480f28 = (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        _DAT_00480ef4 = -1;
        _DAT_00480ef8 = -1;
        _DAT_00480efc = 0xffffffff;
        _DAT_00480f00 = 0xffffffff;
        _DAT_00480eec = 0xffffffff;
        _DAT_00480ef0 = 0xffffffff;
        _DAT_00480fa4 = 0;
        _DAT_00480fa8 = 0;
        _DAT_00480fac = 0;
        _DAT_00480f20 = 0xffffffff;
        cVar2 = DAT_00480f28;
        if (DAT_00480f24 == 2) {
          cVar2 = (&DAT_00480f28)[DAT_00480fb4];
        }
        local_d4 = (int)cVar2;
        cVar2 = DAT_00480f28;
        if (DAT_00480f24 == 2) {
          cVar2 = (&DAT_00480f28)[DAT_00480fb4 == 0];
        }
        local_dc = (int)cVar2;
        DAT_0048d67c = 0;
        if (*(int *)((int)this + 0xd28) != 0) {
          *(int *)((int)this + 0xd28) = *(int *)((int)this + 0xd28) + -1;
          if (*(int *)((int)this + 0xd28) == 0) {
            FUN_004253c9((int)this);
          }
          else {
            FUN_004251e5((int)this);
          }
          if (local_94 == 6) {
            for (local_90 = 0; local_90 < 8; local_90 = local_90 + 1) {
              *(undefined4 *)(&DAT_00442738 + local_90 * 0xd0) = 0;
              *(undefined4 *)(&DAT_0044273c + local_90 * 0xd0) = 0;
              FUN_00412cbc(&DAT_00442670 + local_90 * 0xd0,param_1);
            }
            InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
            UpdateWindow(DAT_0048cc60);
          }
        }
        local_ec[0x24] = 0;
        FUN_0042e249(local_ec + 9,0,0,-0x8000,-0x8000);
        local_ec[7] = 0;
        *(int *)((int)this + *(int *)((int)this + 0xd10) * 4 + 0xd14) = local_f0;
        *(int *)((int)this + 0xd10) = *(int *)((int)this + 0xd10) + 1;
        FUN_0041f791((int)this);
        if (*(int *)((int)this + 0xd10) < 5) {
          local_11c = 0;
          for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
            if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 0) {
              if (local_e0 != local_d8) {
                aiStack_24[local_11c] = local_e0;
                local_11c = local_11c + 1;
              }
            }
            else {
              local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] =
                   local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] + 1;
              if ((*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_d4) ||
                 (*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_dc)) {
                local_a0 = 1;
              }
            }
          }
          if (local_11c != 0) {
            iVar7 = FUN_00405e69(local_11c);
            local_e0 = aiStack_24[iVar7];
            *(undefined4 *)(&DAT_0044268c + local_e0 * 0xd0) = 2;
            if (local_a0 == 0) {
              FUN_00413669(&DAT_00442670 + local_e0 * 0xd0,local_dc);
            }
            else {
              FUN_004136c9(&DAT_00442670 + local_e0 * 0xd0,(int)local_118);
            }
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
        }
        else {
          FUN_0040cf73(0x15);
          *(undefined4 *)((int)this + 0xd10) = 0;
          FUN_0041f72a((int)this);
          local_11c = 0;
          for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
            if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 0) {
              if (local_e0 != local_d8) {
                aiStack_24[local_11c] = local_e0;
                local_11c = local_11c + 1;
              }
            }
            else if ((*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 1) &&
                    ((local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] =
                           local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] + 1,
                     *(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_d4 ||
                     (*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_dc)))) {
              local_a0 = 1;
            }
          }
          if (local_11c != 0) {
            iVar7 = FUN_00405e69(local_11c);
            local_e0 = aiStack_24[iVar7];
            *(undefined4 *)(&DAT_0044268c + local_e0 * 0xd0) = 1;
            if (local_a0 == 0) {
              FUN_00413669(&DAT_00442670 + local_e0 * 0xd0,local_dc);
            }
            else {
              FUN_004136c9(&DAT_00442670 + local_e0 * 0xd0,(int)local_118);
            }
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
        }
        if (DAT_0048d67c != 0) {
          bVar1 = false;
          if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
            for (local_1bc = 0; local_1bc < DAT_0048d67c; local_1bc = local_1bc + 1) {
              FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1bc * 0x10),
                           *(int *)(&DAT_0048d540 + local_1bc * 0x10),
                           (*(int *)(&DAT_0048d544 + local_1bc * 0x10) -
                           *(int *)(&DAT_0048d53c + local_1bc * 0x10)) + 1,
                           (*(int *)(&DAT_0048d548 + local_1bc * 0x10) -
                           *(int *)(&DAT_0048d540 + local_1bc * 0x10)) + 1);
            }
            DAT_0048d67c = 0;
          }
          else {
            for (local_1bc = 0; local_1bc < DAT_0048d67c; local_1bc = local_1bc + 1) {
              if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1bc * 0x10)) &&
                 (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1bc * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_1bc = 0; local_1bc < DAT_0048d67c; local_1bc = local_1bc + 1) {
                FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1bc * 0x10),
                             *(int *)(&DAT_0048d53c + local_1bc * 0x10) - DAT_0048d694,
                             *(int *)(&DAT_0048d540 + local_1bc * 0x10) - DAT_0048d698);
              }
            }
            else {
              for (local_1bc = 0; local_1bc < DAT_0048d67c; local_1bc = local_1bc + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1bc * 0x10));
              }
            }
            DAT_0048d67c = 0;
          }
        }
        goto LAB_0041a89a;
      }
    }
    else if ((int)DAT_00480f28 == local_ec[0x2c]) goto LAB_0041919e;
    if (*(int *)((int)this + 0xd28) == 0) {
      FUN_0040cf73(0x1d);
      DAT_0043d3b4 = DAT_0043d3b8;
      if (*(int *)((int)this + 0xd2c) != local_d8) {
        *(undefined4 *)((int)this + 0xd10) = 0;
        *(undefined4 *)((int)this + 0xd0c) = 0;
        FUN_0041e34f(this,local_94,0);
        FUN_0041f2f8(this,param_1);
        for (local_90 = 0; local_90 < 6; local_90 = local_90 + 1) {
          DAT_00480f28 = DAT_00480f28 + '\x01';
          DAT_00480f28 = DAT_00480f28 % '\x06';
          DAT_00480f29 = DAT_00480f29 + '\x01';
          DAT_00480f29 = DAT_00480f29 % '\x06';
          FUN_00408263(&DAT_004616a8,(DAT_00480ed4 - DAT_00480ecc) + _DAT_00480ef4,
                       (DAT_00480ed8 - DAT_00480ed0) + _DAT_00480ef8);
          InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
          UpdateWindow(DAT_0048cc60);
          Sleep(0x32);
        }
        FUN_0041d7fd(this,param_1);
        Sleep(500);
        if (*(int *)((int)this + 0xd30) != 0) {
          *(int *)((int)this + 0xd30) = *(int *)((int)this + 0xd30) + -1;
          FUN_0041dd38(this,param_1);
          *(undefined4 *)((int)this + 0xd2c) = 0xffffffff;
          local_f0 = local_ec[0x2c];
          FUN_0042eac9(&DAT_00480ebc,param_1,0,0,-0x8000,-0x8000);
          _memset(&DAT_004616ac,0,0xfc04);
          _memset(&DAT_004712b4,0,0xfc04);
          if (DAT_00480f24 == 2) {
            iVar7 = _rand();
            (&DAT_00480f28)[DAT_00480fb4] =
                 (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
          }
          else {
            iVar7 = _rand();
            DAT_00480f28 = (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
          }
          _DAT_00480ef4 = -1;
          _DAT_00480ef8 = -1;
          _DAT_00480efc = 0xffffffff;
          _DAT_00480f00 = 0xffffffff;
          _DAT_00480eec = 0xffffffff;
          _DAT_00480ef0 = 0xffffffff;
          _DAT_00480fa4 = 0;
          _DAT_00480fa8 = 0;
          _DAT_00480fac = 0;
          _DAT_00480f20 = 0xffffffff;
          cVar2 = DAT_00480f28;
          if (DAT_00480f24 == 2) {
            cVar2 = (&DAT_00480f28)[DAT_00480fb4];
          }
          local_d4 = (int)cVar2;
          cVar2 = DAT_00480f28;
          if (DAT_00480f24 == 2) {
            cVar2 = (&DAT_00480f28)[DAT_00480fb4 == 0];
          }
          local_dc = (int)cVar2;
          DAT_0048d67c = 0;
          local_ec[0x24] = 0;
          FUN_0042e249(local_ec + 9,0,0,-0x8000,-0x8000);
          local_ec[7] = 0;
          local_11c = 0;
          for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
            if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 0) {
              if (local_e0 != local_d8) {
                aiStack_24[local_11c] = local_e0;
                local_11c = local_11c + 1;
              }
            }
            else {
              local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] =
                   local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] + 1;
              if ((*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_d4) ||
                 (*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_dc)) {
                local_a0 = 1;
              }
            }
          }
          if (local_11c != 0) {
            iVar7 = FUN_00405e69(local_11c);
            local_e0 = aiStack_24[iVar7];
            *(undefined4 *)(&DAT_0044268c + local_e0 * 0xd0) = 2;
            if (local_a0 == 0) {
              FUN_00413669(&DAT_00442670 + local_e0 * 0xd0,local_dc);
            }
            else {
              FUN_004136c9(&DAT_00442670 + local_e0 * 0xd0,(int)local_118);
            }
            FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
          }
          if (DAT_0048d67c != 0) {
            bVar1 = false;
            if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
              for (local_1c4 = 0; local_1c4 < DAT_0048d67c; local_1c4 = local_1c4 + 1) {
                FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1c4 * 0x10),
                             *(int *)(&DAT_0048d540 + local_1c4 * 0x10),
                             (*(int *)(&DAT_0048d544 + local_1c4 * 0x10) -
                             *(int *)(&DAT_0048d53c + local_1c4 * 0x10)) + 1,
                             (*(int *)(&DAT_0048d548 + local_1c4 * 0x10) -
                             *(int *)(&DAT_0048d540 + local_1c4 * 0x10)) + 1);
              }
              DAT_0048d67c = 0;
            }
            else {
              for (local_1c4 = 0; local_1c4 < DAT_0048d67c; local_1c4 = local_1c4 + 1) {
                if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1c4 * 0x10)) &&
                   (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1c4 * 0x10))) {
                  bVar1 = true;
                  break;
                }
              }
              if (bVar1) {
                for (local_1c4 = 0; local_1c4 < DAT_0048d67c; local_1c4 = local_1c4 + 1) {
                  FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1c4 * 0x10),
                               *(int *)(&DAT_0048d53c + local_1c4 * 0x10) - DAT_0048d694,
                               *(int *)(&DAT_0048d540 + local_1c4 * 0x10) - DAT_0048d698);
                }
              }
              else {
                for (local_1c4 = 0; local_1c4 < DAT_0048d67c; local_1c4 = local_1c4 + 1) {
                  FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1c4 * 0x10));
                }
              }
              DAT_0048d67c = 0;
            }
          }
          goto LAB_0041a89a;
        }
        Sleep(1000);
        FUN_0042eac9(&DAT_00480ebc,param_1,0,0,-0x8000,-0x8000);
        _memset(&DAT_004616ac,0,0xfc04);
        _memset(&DAT_004712b4,0,0xfc04);
        if (DAT_00480f24 == 2) {
          iVar7 = _rand();
          (&DAT_00480f28)[DAT_00480fb4] =
               (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        else {
          iVar7 = _rand();
          DAT_00480f28 = (char)((int)(iVar7 * 6 + (iVar7 * 6 >> 0x1f & 0x7fffU)) >> 0xf);
        }
        _DAT_00480ef4 = 0xffffffff;
        _DAT_00480ef8 = 0xffffffff;
        _DAT_00480efc = 0xffffffff;
        _DAT_00480f00 = 0xffffffff;
        _DAT_00480eec = 0xffffffff;
        _DAT_00480ef0 = 0xffffffff;
        _DAT_00480fa4 = 0;
        _DAT_00480fa8 = 0;
        _DAT_00480fac = 0;
        _DAT_00480f20 = 0xffffffff;
        DAT_0048d67c = 0;
        FUN_004254c6();
        *(undefined4 *)((int)this + 0xc4) = 0;
        if (DAT_0048d67c == 0) goto LAB_0041a855;
        bVar1 = false;
        if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
          for (local_1cc = 0; local_1cc < DAT_0048d67c; local_1cc = local_1cc + 1) {
            FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1cc * 0x10),
                         *(int *)(&DAT_0048d540 + local_1cc * 0x10),
                         (*(int *)(&DAT_0048d544 + local_1cc * 0x10) -
                         *(int *)(&DAT_0048d53c + local_1cc * 0x10)) + 1,
                         (*(int *)(&DAT_0048d548 + local_1cc * 0x10) -
                         *(int *)(&DAT_0048d540 + local_1cc * 0x10)) + 1);
          }
          DAT_0048d67c = 0;
          goto LAB_0041a855;
        }
        local_1cc = 0;
        goto LAB_0041a710;
      }
    }
    else if (*(int *)((int)this + 0xd2c) != local_d8) {
      if ((DAT_00480fb8 < 0) && (DAT_00480fbc < 0)) {
        if (local_ec[0x31] == 0) {
          _DAT_00480f20 = 3;
        }
        else {
          _DAT_00480f20 = 2;
        }
      }
      else if ((DAT_00480fb8 < 1) || (-1 < DAT_00480fbc)) {
        if ((DAT_00480fb8 < 1) || (DAT_00480fbc < 1)) {
          if (local_ec[0x31] == 0) {
            _DAT_00480f20 = 1;
          }
          else {
            _DAT_00480f20 = 2;
          }
        }
        else {
          _DAT_00480f20 = (uint)(local_ec[0x31] == 0);
        }
      }
      else if (local_ec[0x31] == 0) {
        _DAT_00480f20 = 3;
      }
      else {
        _DAT_00480f20 = 0;
      }
      *(int *)((int)this + 0xd2c) = local_d8;
    }
  }
  goto LAB_0041a89a;
LAB_00415f35:
  if (DAT_0048d67c <= local_19c) goto LAB_00415f91;
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_19c * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_19c * 0x10))) {
    bVar1 = true;
    goto LAB_00415f91;
  }
  local_19c = local_19c + 1;
  goto LAB_00415f35;
LAB_00415f91:
  if (bVar1) {
    for (local_19c = 0; local_19c < DAT_0048d67c; local_19c = local_19c + 1) {
      FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_19c * 0x10),
                   *(int *)(&DAT_0048d53c + local_19c * 0x10) - DAT_0048d694,
                   *(int *)(&DAT_0048d540 + local_19c * 0x10) - DAT_0048d698);
    }
  }
  else {
    for (local_19c = 0; local_19c < DAT_0048d67c; local_19c = local_19c + 1) {
      FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_19c * 0x10));
    }
  }
  DAT_0048d67c = 0;
LAB_0041607a:
  for (local_90 = 0; local_90 < 8; local_90 = local_90 + 1) {
    *(undefined4 *)(&DAT_00442738 + local_90 * 0xd0) = 0;
    *(undefined4 *)(&DAT_0044273c + local_90 * 0xd0) = 0;
    FUN_00412cbc(&DAT_00442670 + local_90 * 0xd0,param_1);
  }
  InvalidateRect(DAT_0048cc60,(RECT *)0x0,0);
  UpdateWindow(DAT_0048cc60);
switchD_00416135_default:
  if (*(int *)((int)this + 0x1c) == 0) {
    if (*(int *)this != 9) {
      FUN_0040cf73(0x20);
    }
    if ((*piVar5 + -1 <= *piVar3) && (*(int *)((int)this + 0xc4) < 4)) {
      iVar7 = FUN_00405e69(7);
      *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = iVar7 + 1;
      *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
    }
    FUN_0041f071(this,param_1);
    DAT_0048d67c = 0;
    FUN_004254c6();
    if (DAT_0048d67c == 0) goto LAB_0041644b;
    bVar1 = false;
    if ((DAT_0048d694 != 0) || (DAT_0048d698 != 0)) {
      local_1a4 = 0;
      goto LAB_00416306;
    }
    for (local_1a4 = 0; local_1a4 < DAT_0048d67c; local_1a4 = local_1a4 + 1) {
      FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1a4 * 0x10),
                   *(int *)(&DAT_0048d540 + local_1a4 * 0x10),
                   (*(int *)(&DAT_0048d544 + local_1a4 * 0x10) -
                   *(int *)(&DAT_0048d53c + local_1a4 * 0x10)) + 1,
                   (*(int *)(&DAT_0048d548 + local_1a4 * 0x10) -
                   *(int *)(&DAT_0048d540 + local_1a4 * 0x10)) + 1);
    }
    DAT_0048d67c = 0;
LAB_0041644b:
    DAT_0044209c = 0;
    FUN_00405ca2();
    *(undefined4 *)((int)this + 4) = 2;
    return;
  }
LAB_00416476:
  local_100 = 0;
  for (local_e0 = 0; local_e0 < *(int *)((int)this + 0x1c); local_e0 = local_e0 + 1) {
    if (*(int *)((int)this + local_e0 * 4 + 0x20) == 0) {
      aiStack_88[local_100 + 3] = local_e0;
      local_100 = local_100 + 1;
    }
  }
  switch(local_94) {
  case 0:
    local_e4 = local_ec[0x2c];
    if (*piVar3 == 0) {
      FUN_0041e131(this,local_94,local_e4);
      FUN_0041ec27(this,param_1);
      iVar7 = FUN_00405e69(2);
      FUN_0040cf73(iVar7 + 0x18);
    }
    else {
      for (local_e0 = 0; local_e0 < *piVar3; local_e0 = local_e0 + 1) {
        if (*(int *)(local_3c + local_e0 * 4) == local_e4) {
          iVar7 = FUN_00405e69(2);
          FUN_0040cf73(iVar7 + 0x27);
          goto switchD_00417e1c_default;
        }
      }
      FUN_0041e131(this,local_94,local_e4);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    break;
  case 1:
    if (local_ec[0x2f] == 0) {
LAB_0041684f:
      FUN_0041e131(this,local_94,0);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    else if (local_ec[0x2f] == 1) {
      FUN_0041e2a9(this,local_94,1);
      FUN_0041ec27(this,param_1);
      if (*piVar6 <= *piVar4) {
        FUN_0041e68f(this,local_94);
        goto LAB_0041684f;
      }
    }
    break;
  case 2:
    if ((local_ec[0x2f] != 0) && (local_ec[0x2f] == 1)) {
      FUN_0041e131(this,local_94,0);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    break;
  case 3:
    switch(local_ec[0x2f]) {
    case 0:
    case 2:
    case 3:
      break;
    case 1:
      FUN_0041e131(this,local_94,local_ec[0x2e]);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    break;
  case 4:
    if (local_ec[0x2f] != 9) {
      FUN_0041e131(this,local_94,9 - local_ec[0x2f]);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    break;
  case 5:
    if (local_ec[0x2f] == 0) {
LAB_004174ec:
      FUN_0041e131(this,local_94,0);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    else if (local_ec[0x2f] == 1) {
      FUN_0041e2a9(this,local_94,1);
      FUN_0041ec27(this,param_1);
      if (*piVar6 <= *piVar4) {
        FUN_0041e68f(this,local_94);
        goto LAB_004174ec;
      }
    }
    break;
  case 6:
    if (local_ec[0x2f] == 0) {
LAB_00417232:
      FUN_0041e131(this,local_94,0);
      FUN_0041ec27(this,param_1);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
        FUN_0041f676(this,param_1);
      }
    }
    else if (local_ec[0x2f] == 2) {
      FUN_0041e2a9(this,local_94,1);
      FUN_0041ec27(this,param_1);
      if (*piVar6 <= *piVar4) {
        FUN_0041e68f(this,local_94);
        goto LAB_00417232;
      }
    }
    break;
  case 7:
    local_e4 = local_ec[0x2f];
    if (*piVar3 == 0) {
      FUN_0041e131(this,local_94,local_e4);
      FUN_0041ec27(this,param_1);
      iVar7 = FUN_00405e69(2);
      FUN_0040cf73(iVar7 + 0x18);
    }
    else {
      for (local_e0 = 0; local_e0 < *piVar3; local_e0 = local_e0 + 1) {
        if (*(int *)(local_3c + local_e0 * 4) == local_e4) {
          FUN_0041e34f(this,local_94,0);
          FUN_0040cf73(0xb);
          goto LAB_00417a2d;
        }
      }
      FUN_0041e131(this,local_94,local_e4);
      FUN_0041ec27(this,param_1);
      iVar7 = FUN_00405e69(2);
      FUN_0040cf73(iVar7 + 0x18);
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
LAB_00417a2d:
        FUN_0041f676(this,param_1);
      }
    }
    break;
  case 8:
    local_e4 = local_ec[0x2f] * 4 + local_ec[0x2e];
    local_f4 = local_ec[0x2f];
    if (*piVar3 == 0) {
      if (local_f4 == 5) {
        FUN_0041e131(this,local_94,0x14);
        FUN_0041ec27(this,param_1);
      }
      else {
        FUN_0041e131(this,local_94,local_e4);
        FUN_0041ec27(this,param_1);
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
    }
    else {
      if (local_f4 == 5) {
        FUN_0041e131(this,local_94,0x14);
        FUN_0041ec27(this,param_1);
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      else {
        for (local_e0 = 0; local_e0 < *piVar3; local_e0 = local_e0 + 1) {
          iVar7 = *(int *)(local_3c + local_e0 * 4);
          if ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2 == local_f4) {
            FUN_0041e34f(this,local_94,0);
            FUN_0040cf73(0xb);
            goto LAB_00417df0;
          }
        }
        FUN_0041e131(this,local_94,local_e4);
        FUN_0041ec27(this,param_1);
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x18);
      }
      if (*piVar5 <= *piVar3) {
        iVar7 = FUN_00405e69(2);
        FUN_0040cf73(iVar7 + 0x12);
        FUN_00425ece((int)this);
        if (local_100 == 0) {
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          iVar7 = FUN_0041c1fe((int)this);
          if ((4 < iVar7) && (local_b4 == 1)) {
            local_b4 = 5;
          }
          *(int *)((int)this + *(int *)((int)this + 0xc4) * 4 + 0x88) = local_b4;
          *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
        }
        else {
          if (((local_100 < 2) || (*(int *)((int)this + 0x1c) != local_100)) || (DAT_0043f0b4 != 0))
          {
            local_30 = local_100 + -1;
          }
          else {
            local_30 = local_100 + -2;
          }
          local_30 = aiStack_88[local_30 + 3];
          local_b4 = FUN_00405e69(7);
          local_b4 = local_b4 + 1;
          if ((*(int *)((int)this + 0x1c) + -1 == local_30) && (local_b4 == 6)) {
            local_b4 = 4;
          }
          if (local_30 == 0) {
            iVar7 = FUN_0041c1fe((int)this);
            if (iVar7 < 5) {
              iVar7 = FUN_00405e69(2);
              if (iVar7 == 0) {
                local_b4 = 5;
              }
              else {
                local_b4 = 1;
              }
            }
            else {
              local_b4 = 5;
            }
          }
          *(int *)((int)this + local_30 * 4 + 0x20) = local_b4;
          FUN_0041cd97(this,local_30,param_1);
        }
        FUN_0041e34f(this,local_94,1);
LAB_00417df0:
        FUN_0041f676(this,param_1);
      }
    }
  }
switchD_00417e1c_default:
  local_ec[0x24] = 0;
  FUN_0042e249(local_ec + 9,0,0,-0x8000,-0x8000);
  local_ec[7] = 0;
  local_11c = 0;
  for (local_e0 = 0; local_e0 < 8; local_e0 = local_e0 + 1) {
    if (*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 0) {
      if (local_e0 != local_d8) {
        aiStack_24[local_11c] = local_e0;
        local_11c = local_11c + 1;
      }
    }
    else if ((*(int *)(&DAT_0044268c + local_e0 * 0xd0) == 1) &&
            ((local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] =
                   local_118[*(int *)(&DAT_00442720 + local_e0 * 0xd0)] + 1,
             *(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_d4 ||
             (*(int *)(&DAT_00442720 + local_e0 * 0xd0) == local_dc)))) {
      local_a0 = 1;
    }
  }
  if (local_11c != 0) {
    for (local_e0 = 0; local_e0 < local_11c; local_e0 = local_e0 + 1) {
      local_b0 = *(int *)(&DAT_0044267c + aiStack_24[local_e0] * 0xd0) +
                 (*(int *)(&DAT_00442684 + aiStack_24[local_e0] * 0xd0) -
                 *(int *)(&DAT_0044267c + aiStack_24[local_e0] * 0xd0)) / 2;
      local_b0 = local_b0 + DAT_004830f8;
      local_ac = *(int *)(&DAT_00442680 + aiStack_24[local_e0] * 0xd0) +
                 (*(int *)(&DAT_00442688 + aiStack_24[local_e0] * 0xd0) -
                 *(int *)(&DAT_00442680 + aiStack_24[local_e0] * 0xd0)) / 2 + DAT_004830fc;
      iVar7 = FUN_0041b0d0(&local_134,&local_b0);
      aiStack_88[local_e0] = iVar7;
    }
    local_12c = 0;
    local_98 = 0;
    for (local_e0 = 0; local_e0 < local_11c; local_e0 = local_e0 + 1) {
      if (local_12c < aiStack_88[local_e0]) {
        local_98 = aiStack_24[local_e0];
        local_12c = aiStack_88[local_e0];
      }
    }
    local_e0 = local_98;
    *(undefined4 *)(&DAT_0044268c + local_98 * 0xd0) = 1;
    if (local_a0 == 0) {
      FUN_00413669(&DAT_00442670 + local_98 * 0xd0,local_dc);
    }
    else {
      FUN_004136c9(&DAT_00442670 + local_98 * 0xd0,(int)local_118);
    }
    FUN_0040fe33((int *)(&DAT_00442670 + local_e0 * 0xd0));
  }
  if (*(int *)((int)this + 0xd28) == 0) {
    FUN_004253c9((int)this);
  }
  else {
    FUN_004251e5((int)this);
  }
  if (DAT_0048d67c != 0) {
    bVar1 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_1ac = 0; local_1ac < DAT_0048d67c; local_1ac = local_1ac + 1) {
        FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1ac * 0x10),
                     *(int *)(&DAT_0048d540 + local_1ac * 0x10),
                     (*(int *)(&DAT_0048d544 + local_1ac * 0x10) -
                     *(int *)(&DAT_0048d53c + local_1ac * 0x10)) + 1,
                     (*(int *)(&DAT_0048d548 + local_1ac * 0x10) -
                     *(int *)(&DAT_0048d540 + local_1ac * 0x10)) + 1);
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_1ac = 0; local_1ac < DAT_0048d67c; local_1ac = local_1ac + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1ac * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1ac * 0x10))) {
          bVar1 = true;
          break;
        }
      }
      if (bVar1) {
        for (local_1ac = 0; local_1ac < DAT_0048d67c; local_1ac = local_1ac + 1) {
          FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1ac * 0x10),
                       *(int *)(&DAT_0048d53c + local_1ac * 0x10) - DAT_0048d694,
                       *(int *)(&DAT_0048d540 + local_1ac * 0x10) - DAT_0048d698);
        }
      }
      else {
        for (local_1ac = 0; local_1ac < DAT_0048d67c; local_1ac = local_1ac + 1) {
          FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1ac * 0x10));
        }
      }
      DAT_0048d67c = 0;
    }
  }
LAB_0041a89a:
  if ((local_8c == 1) && (local_ec[0x2a] == 0)) {
    if ((local_ec[0x32] != 0) && (local_ec[0x33] = local_ec[0x33] + -1, local_ec[0x33] == 0)) {
      local_ec[0x32] = local_ec[0x32] + -1;
      local_ec[0x33] = 5;
      FUN_00412cbc(local_ec,param_1);
    }
    switch(local_94) {
    case 0:
      break;
    case 1:
    case 7:
    case 8:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
        }
      }
      break;
    case 2:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
        }
      }
      break;
    case 3:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
          if (local_ec[0x2f] == 1) {
            local_ec[0x24] = 1;
          }
        }
        else if ((local_ec[0x2f] == 1) && (iVar7 = FUN_0040dfb7(local_ec + 0xd), iVar7 != 0)) {
          if (iVar7 == 1) {
            if (DAT_0048d67c != 0) {
              bVar1 = false;
              if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
                for (local_1d4 = 0; local_1d4 < DAT_0048d67c; local_1d4 = local_1d4 + 1) {
                  FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_1d4 * 0x10),
                               *(int *)(&DAT_0048d540 + local_1d4 * 0x10),
                               (*(int *)(&DAT_0048d544 + local_1d4 * 0x10) -
                               *(int *)(&DAT_0048d53c + local_1d4 * 0x10)) + 1,
                               (*(int *)(&DAT_0048d548 + local_1d4 * 0x10) -
                               *(int *)(&DAT_0048d540 + local_1d4 * 0x10)) + 1);
                }
                DAT_0048d67c = 0;
              }
              else {
                for (local_1d4 = 0; local_1d4 < DAT_0048d67c; local_1d4 = local_1d4 + 1) {
                  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1d4 * 0x10)) &&
                     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1d4 * 0x10))) {
                    bVar1 = true;
                    break;
                  }
                }
                if (bVar1) {
                  for (local_1d4 = 0; local_1d4 < DAT_0048d67c; local_1d4 = local_1d4 + 1) {
                    FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1d4 * 0x10),
                                 *(int *)(&DAT_0048d53c + local_1d4 * 0x10) - DAT_0048d694,
                                 *(int *)(&DAT_0048d540 + local_1d4 * 0x10) - DAT_0048d698);
                  }
                }
                else {
                  for (local_1d4 = 0; local_1d4 < DAT_0048d67c; local_1d4 = local_1d4 + 1) {
                    FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1d4 * 0x10));
                  }
                }
                DAT_0048d67c = 0;
              }
            }
          }
          else if (iVar7 == 2) {
            FUN_00413b45((int)local_ec);
            FUN_00413fa1((int)local_ec);
            FUN_00412649(local_ec,param_1);
            iVar7 = FUN_00405e69(4);
            FUN_0040cf73(iVar7 + 0x23);
          }
        }
      }
      break;
    case 4:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
        }
      }
      break;
    case 5:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
        }
      }
      break;
    case 6:
      if (local_ec[0x2e] != -1) {
        if (local_ec[8] != -1) {
          local_ec[8] = local_ec[8] + -1;
        }
        if (local_ec[8] == 0) {
          FUN_00413b45((int)local_ec);
          FUN_00413fa1((int)local_ec);
          FUN_00412649(local_ec,param_1);
          if (((local_ec[0x2f] == 1) || (local_ec[0x2f] == 3)) || (local_ec[0x2f] == 5)) {
            local_ec[0x32] = 7;
            local_ec[0x33] = 5;
          }
        }
      }
    }
  }
switchD_0041af66_default:
  local_d8 = local_d8 + 1;
  goto LAB_00414121;
LAB_00415cb8:
  if (DAT_0048d67c <= local_194) goto LAB_00415d14;
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_194 * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_194 * 0x10))) {
    bVar1 = true;
    goto LAB_00415d14;
  }
  local_194 = local_194 + 1;
  goto LAB_00415cb8;
LAB_00415d14:
  if (bVar1) {
    for (local_194 = 0; local_194 < DAT_0048d67c; local_194 = local_194 + 1) {
      FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_194 * 0x10),
                   *(int *)(&DAT_0048d53c + local_194 * 0x10) - DAT_0048d694,
                   *(int *)(&DAT_0048d540 + local_194 * 0x10) - DAT_0048d698);
    }
  }
  else {
    for (local_194 = 0; local_194 < DAT_0048d67c; local_194 = local_194 + 1) {
      FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_194 * 0x10));
    }
  }
  DAT_0048d67c = 0;
  goto switchD_00416135_default;
LAB_00415a4b:
  if (DAT_0048d67c <= local_18c) goto LAB_00415aa7;
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_18c * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_18c * 0x10))) {
    bVar1 = true;
    goto LAB_00415aa7;
  }
  local_18c = local_18c + 1;
  goto LAB_00415a4b;
LAB_00415aa7:
  if (bVar1) {
    for (local_18c = 0; local_18c < DAT_0048d67c; local_18c = local_18c + 1) {
      FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_18c * 0x10),
                   *(int *)(&DAT_0048d53c + local_18c * 0x10) - DAT_0048d694,
                   *(int *)(&DAT_0048d540 + local_18c * 0x10) - DAT_0048d698);
    }
  }
  else {
    for (local_18c = 0; local_18c < DAT_0048d67c; local_18c = local_18c + 1) {
      FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_18c * 0x10));
    }
  }
  DAT_0048d67c = 0;
  goto switchD_00416135_default;
switchD_00416135_caseD_4:
  local_40 = FUN_00405e69(4);
  goto LAB_00414bc1;
LAB_00414d27:
  if (DAT_0048d67c <= local_174) goto LAB_00414d83;
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_174 * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_174 * 0x10))) {
    bVar1 = true;
    goto LAB_00414d83;
  }
  local_174 = local_174 + 1;
  goto LAB_00414d27;
LAB_00414d83:
  if (bVar1) {
    for (local_174 = 0; local_174 < DAT_0048d67c; local_174 = local_174 + 1) {
      FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_174 * 0x10),
                   *(int *)(&DAT_0048d53c + local_174 * 0x10) - DAT_0048d694,
                   *(int *)(&DAT_0048d540 + local_174 * 0x10) - DAT_0048d698);
    }
  }
  else {
    for (local_174 = 0; local_174 < DAT_0048d67c; local_174 = local_174 + 1) {
      FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_174 * 0x10));
    }
  }
  DAT_0048d67c = 0;
  goto switchD_00416135_default;
switchD_00416135_caseD_0:
  FUN_00425ece((int)this);
  goto switchD_00416135_default;
LAB_00416306:
  if (DAT_0048d67c <= local_1a4) goto LAB_00416362;
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1a4 * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1a4 * 0x10))) {
    bVar1 = true;
    goto LAB_00416362;
  }
  local_1a4 = local_1a4 + 1;
  goto LAB_00416306;
LAB_00416362:
  if (bVar1) {
    for (local_1a4 = 0; local_1a4 < DAT_0048d67c; local_1a4 = local_1a4 + 1) {
      FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1a4 * 0x10),
                   *(int *)(&DAT_0048d53c + local_1a4 * 0x10) - DAT_0048d694,
                   *(int *)(&DAT_0048d540 + local_1a4 * 0x10) - DAT_0048d698);
    }
  }
  else {
    for (local_1a4 = 0; local_1a4 < DAT_0048d67c; local_1a4 = local_1a4 + 1) {
      FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1a4 * 0x10));
    }
  }
  DAT_0048d67c = 0;
  goto LAB_0041644b;
LAB_0041a710:
  if (DAT_0048d67c <= local_1cc) {
LAB_0041a76c:
    if (bVar1) {
      for (local_1cc = 0; local_1cc < DAT_0048d67c; local_1cc = local_1cc + 1) {
        FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_1cc * 0x10),
                     *(int *)(&DAT_0048d53c + local_1cc * 0x10) - DAT_0048d694,
                     *(int *)(&DAT_0048d540 + local_1cc * 0x10) - DAT_0048d698);
      }
    }
    else {
      for (local_1cc = 0; local_1cc < DAT_0048d67c; local_1cc = local_1cc + 1) {
        FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_1cc * 0x10));
      }
    }
    DAT_0048d67c = 0;
LAB_0041a855:
    FUN_0040579a(0);
    *(undefined4 *)((int)this + 4) = 1;
    return;
  }
  if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_1cc * 0x10)) &&
     (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_1cc * 0x10))) {
    bVar1 = true;
    goto LAB_0041a76c;
  }
  local_1cc = local_1cc + 1;
  goto LAB_0041a710;
LAB_0041af96:
  bVar1 = false;
  cVar2 = DAT_00480f28;
  if (DAT_00480f24 == 2) {
    cVar2 = (&DAT_00480f28)[DAT_00480fb4];
  }
  local_d4 = (int)cVar2;
  local_dc = 0;
  local_d8 = 0;
  do {
    if (7 < local_d8) {
LAB_0041b083:
      if (bVar1) {
        return;
      }
      DAT_00480f28 = (undefined1)local_dc;
      DAT_00480f29 = (undefined1)local_dc;
      return;
    }
    if ((*(int *)(&DAT_0044268c + local_d8 * 0xd0) != 0) &&
       (local_dc = *(int *)(&DAT_00442720 + local_d8 * 0xd0), local_dc == local_d4)) {
      bVar1 = true;
      goto LAB_0041b083;
    }
    local_d8 = local_d8 + 1;
  } while( true );
}


// ==== FUN_0041b0d0 @ 0041b0d0

int __cdecl FUN_0041b0d0(int *param_1,int *param_2)

{
  return (param_2[1] - param_1[1]) * (param_2[1] - param_1[1]) +
         (*param_2 - *param_1) * (*param_2 - *param_1);
}


// ==== FUN_0041b120 @ 0041b120

void FUN_0041b120(HDC param_1,int param_2,int param_3,int param_4,int param_5)

{
  HDC hdc;
  HGDIOBJ h;
  
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,param_2,param_3,param_4,param_5,hdc,param_2,param_3,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041b1b0 @ 0041b1b0

void FUN_0041b1b0(HDC param_1,int *param_2)

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
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041b280 @ 0041b280

void FUN_0041b280(HDC param_1,int *param_2,int param_3,int param_4)

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
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,param_3,param_4,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,hdc,x1,y1,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041b350 @ 0041b350

int __cdecl FUN_0041b350(int param_1)

{
  return param_1 * -10 + 0x6c;
}


// ==== FUN_0041b36f @ 0041b36f

void FUN_0041b36f(void)

{
  _memset(&DAT_0048c8a8,0,0x370);
  _memset(&DAT_004897d8,0,0x30d0);
  FID_conflict__memcpy(&DAT_004897d8,s_MD_PACK_0043f100,8);
  DAT_0048a884 = 0;
  DAT_0048a885 = 0;
  DAT_0048a886 = 0;
  DAT_004897e2 = 0xc;
  _memset(&DAT_0048a858,0,0x28);
  FID_conflict__memcpy(&DAT_0048a848,s_COLC_0043f208,0xb);
  return;
}


// ==== FUN_0041b408 @ 0041b408

undefined4 FUN_0041b408(void)

{
  HFILE hFile;
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  int local_10;
  
  FUN_0041b36f();
  hFile = _lopen(s_MSPuzzle_dat_0043f108,0);
  if (hFile == -1) {
    uVar1 = 0;
  }
  else {
    UVar2 = _lread(hFile,&DAT_004897d8,0x30d0);
    _lclose(hFile);
    FID_conflict__memcpy(&DAT_0048a848,s_COLC_0043f208,0xb);
    if ((UVar2 == 0x30d0) && (iVar3 = _strncmp(&DAT_004897d8,s_MD_PACK_0043f100,7), iVar3 == 0)) {
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0048c8d0 + local_10 * 0x2c) =
             *(undefined4 *)(&DAT_0048a8bc + local_10 * 0x30);
        FID_conflict__memcpy(&DAT_0048c8a8 + local_10 * 0x2c,&DAT_0048a894 + local_10 * 0x30,0x28);
        if (*(int *)(&DAT_0048c8d0 + local_10 * 0x2c) < 0) {
          *(undefined4 *)(&DAT_0048c8d0 + local_10 * 0x2c) = 0;
        }
      }
      DAT_0043ebe4 = (uint)(DAT_0048a884 == '\0');
      DAT_0043ebe0 = (uint)(DAT_0048a885 == '\0');
      DAT_0043f0d4 = (uint)(DAT_0048a886 == '\0');
      FID_conflict__memcpy(&DAT_0043f0d8,&DAT_0048a858,0x28);
      DAT_0043f0c0 = (uint)DAT_0048a880;
      if ((DAT_0043f0c0 == 0) || (10 < DAT_0043f0c0)) {
        DAT_0043f0c0 = 1;
      }
      DAT_0043f0c4 = (uint)DAT_0048a881;
      if ((DAT_0043f0c4 == 0) || (4 < DAT_0043f0c4)) {
        DAT_0043f0c4 = 1;
      }
      DAT_0043f0c8 = (uint)(DAT_0048a882 == '\0');
      DAT_0043f0cc = (uint)(DAT_0048a883 == '\0');
      uVar1 = 1;
    }
    else {
      FUN_0041b36f();
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_0041b698 @ 0041b698

undefined4 __cdecl FUN_0041b698(int param_1,int *param_2)

{
  int local_14;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  *param_2 = 0x14;
  local_14 = 0x14;
  while ((local_8 < 0x14 && (local_14 == 0x14))) {
    if (*(int *)(&DAT_0048c8d0 + local_8 * 0x2c) < param_1) {
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


// ==== FUN_0041b735 @ 0041b735

int __cdecl FUN_0041b735(int param_1)

{
  int local_1c;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_1c = 0x14;
  while ((local_c < 0x14 && (local_1c == 0x14))) {
    if (*(int *)(&DAT_0048c8d0 + local_c * 0x2c) < param_1) {
      local_1c = local_c;
    }
    local_c = local_c + 1;
  }
  if ((local_1c < 0x14) && (-1 < local_1c)) {
    if (local_1c < 0x13) {
      FID_conflict__memcpy
                (&DAT_0048c8a8 + (local_1c + 1) * 0x2c,&DAT_0048c8a8 + local_1c * 0x2c,
                 (0x13 - local_1c) * 0x2c);
    }
    FID_conflict__memcpy(&DAT_0048c8a8 + local_1c * 0x2c,&DAT_0043f0d8,0x28);
    *(int *)(&DAT_0048c8d0 + local_1c * 0x2c) = param_1;
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


// ==== FUN_0041b879 @ 0041b879

void FUN_0041b879(void)

{
  int local_c;
  HFILE local_8;
  
  _memset(&DAT_0048a894,0,0x3c0);
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    FID_conflict__memcpy(&DAT_0048a894 + local_c * 0x30,&DAT_0048c8a8 + local_c * 0x2c,0x28);
    *(undefined4 *)(&DAT_0048a8bc + local_c * 0x30) =
         *(undefined4 *)(&DAT_0048c8d0 + local_c * 0x2c);
  }
  DAT_0048a884 = DAT_0043ebe4 == 0;
  DAT_0048a885 = DAT_0043ebe0 == 0;
  DAT_0048a886 = DAT_0043f0d4 == 0;
  DAT_0048a880 = (undefined1)DAT_0043f0c0;
  DAT_0048a881 = (undefined1)DAT_0043f0c4;
  DAT_0048a882 = DAT_0043f0c8 == 0;
  DAT_0048a883 = DAT_0043f0cc == 0;
  _memset(&DAT_0048a858,0,0x28);
  FID_conflict__memcpy(&DAT_0048a858,&DAT_0043f0d8,0x28);
  local_8 = _lopen(s_MSPuzzle_dat_0043f108,1);
  if (local_8 == -1) {
    local_8 = _lcreat(s_MSPuzzle_dat_0043f108,0);
  }
  _lwrite(local_8,&DAT_004897d8,0x30d0);
  _lclose(local_8);
  return;
}


// ==== FUN_0041ba50 @ 0041ba50

undefined4 FUN_0041ba50(void)

{
  return 1;
}


// ==== FUN_0041ba68 @ 0041ba68

void FUN_0041ba68(void)

{
  return;
}


// ==== FUN_0041ba80 @ 0041ba80

void __cdecl FUN_0041ba80(HDC param_1)

{
  int x;
  int y;
  int iVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  y = DAT_004830fc;
  x = DAT_004830f8;
  iVar1 = DAT_00483104 - DAT_004830fc;
  iVar2 = DAT_00483100 - DAT_004830f8;
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,x,y,iVar2 + 1,iVar1 + 1,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041bb46 @ 0041bb46

void __cdecl FUN_0041bb46(HDC param_1)

{
  int x;
  int y;
  int iVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  y = DAT_004864cc;
  x = DAT_004864c8;
  iVar1 = DAT_004864d4 - DAT_004864cc;
  iVar2 = DAT_004864d0 - DAT_004864c8;
  hdc = CreateCompatibleDC(param_1);
  h = SelectObject(hdc,DAT_0048d6a0);
  BitBlt(param_1,x,y,iVar2 + 1,iVar1 + 1,hdc,x,y,0xcc0020);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  GdiFlush();
  return;
}


// ==== FUN_0041bc0c @ 0041bc0c

void __cdecl FUN_0041bc0c(uint param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  DVar1 = GetTickCount();
  do {
    DVar2 = GetTickCount();
  } while (DVar2 / 0x37 - DVar1 / 0x37 < param_1);
  return;
}


// ==== FUN_0041bc51 @ 0041bc51

void __fastcall FUN_0041bc51(int param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *(uint *)(param_1 + 0x194) = DVar1 / 0x37;
  return;
}


// ==== FUN_0041bc7f @ 0041bc7f

void __fastcall FUN_0041bc7f(int param_1)

{
  LPVOID pvVar1;
  DWORD DVar2;
  int local_8;
  
  *(undefined4 *)(param_1 + 400) = 0;
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(int *)(local_8 * 0x50 + 0x1c + param_1) = local_8 + 0x61c;
    *(undefined4 *)(local_8 * 0x50 + 0x20 + param_1) = 2;
    *(undefined4 *)(local_8 * 0x50 + 0x24 + param_1) = 0;
    if ((*(int *)(local_8 * 0x50 + 0x20 + param_1) != 0) &&
       (*(int *)(local_8 * 0x50 + param_1) == 0)) {
      if (*(int *)(local_8 * 0x50 + 0x24 + param_1) == 0) {
        if (*(int *)(local_8 * 0x50 + 0x20 + param_1) == 1) {
          pvVar1 = FUN_00426556((LPCSTR)(local_8 * 0x50 + param_1 + 8));
          *(LPVOID *)(local_8 * 0x50 + param_1) = pvVar1;
        }
        else {
          pvVar1 = FUN_00426556(*(LPCSTR *)(local_8 * 0x50 + 0x1c + param_1));
          *(LPVOID *)(local_8 * 0x50 + param_1) = pvVar1;
        }
        if (*(int *)(local_8 * 0x50 + param_1) != 0) {
          *(undefined4 *)(local_8 * 0x50 + 4 + param_1) = 1;
        }
      }
      else if (*(int *)(local_8 * 0x50 + param_1) != 0) {
        *(undefined4 *)(local_8 * 0x50 + 4 + param_1) = 0;
      }
    }
    *(undefined4 *)(local_8 * 0x50 + 0x28 + param_1) = *(undefined4 *)(&DAT_0043f230 + local_8 * 8);
    *(undefined4 *)(local_8 * 0x50 + 0x2c + param_1) = *(undefined4 *)(&DAT_0043f234 + local_8 * 8);
  }
  DVar2 = GetTickCount();
  *(uint *)(param_1 + 0x194) = DVar2 / 0x37;
  return;
}


// ==== FUN_0041becc @ 0041becc

void __fastcall FUN_0041becc(int param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined4 *)(local_8 * 0x50 + param_1) = 0;
    *(undefined1 *)(local_8 * 0x50 + 8 + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x1c + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x20 + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x24 + param_1) = 1;
    if (*(int *)(local_8 * 0x50 + 0x40 + param_1) != 0) {
      FUN_00432b10(*(void **)(local_8 * 0x50 + 0x40 + param_1));
    }
    *(undefined4 *)(local_8 * 0x50 + 0x40 + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x48 + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x4c + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x28 + param_1) = 0;
    *(undefined4 *)(local_8 * 0x50 + 0x2c + param_1) = 0;
  }
  return;
}


// ==== FUN_0041c041 @ 0041c041

void __fastcall FUN_0041c041(int param_1)

{
  undefined4 local_8;
  
  if (*(int *)(param_1 + 400) != 0) {
    for (local_8 = 0; local_8 < *(int *)(param_1 + 400); local_8 = local_8 + 1) {
      FUN_0042e249((void *)(local_8 * 0x50 + 0x40 + param_1),0,0,-0x8000,-0x8000);
    }
  }
  return;
}


// ==== FUN_0041c0ba @ 0041c0ba

void __fastcall FUN_0041c0ba(int param_1)

{
  undefined4 local_8;
  
  if (*(int *)(param_1 + 400) != 0) {
    for (local_8 = 0; local_8 < *(int *)(param_1 + 400); local_8 = local_8 + 1) {
      FUN_004312fe((void *)(local_8 * 0x50 + param_1),1);
    }
  }
  return;
}


// ==== FUN_0041c120 @ 0041c120

void __fastcall FUN_0041c120(int param_1)

{
  if (*(int *)(param_1 + 400) != 0) {
    FUN_00430aea((void *)((*(int *)(param_1 + 400) * 5 + -5) * 0x10 + param_1),1);
  }
  return;
}


// ==== FUN_0041c167 @ 0041c167

undefined4 __fastcall FUN_0041c167(int param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  
  if (*(int *)(param_1 + 400) == 5) {
    uVar1 = 0;
  }
  else {
    DVar2 = GetTickCount();
    *(uint *)(param_1 + 0x198) = DVar2 / 0x37;
    if ((uint)(*(int *)(param_1 + 0x198) - *(int *)(param_1 + 0x194)) < 0x14) {
      uVar1 = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 0x198);
      *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
      FUN_0041c120(param_1);
      uVar1 = 2;
    }
  }
  return uVar1;
}


// ==== FUN_0041c1fe @ 0041c1fe

int __fastcall FUN_0041c1fe(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = *(int *)(param_1 + 0xd30);
  if (*(int *)(param_1 + 0x5c) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x5c); local_c = local_c + 1) {
      if (*(int *)(param_1 + 0x20 + local_c * 4) == 1) {
        local_8 = local_8 + 1;
      }
    }
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0xc4); local_c = local_c + 1) {
      if (*(int *)(param_1 + 0x88 + local_c * 4) == 1) {
        local_8 = local_8 + 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_0041c2b4 @ 0041c2b4

void __thiscall FUN_0041c2b4(void *this,int param_1)

{
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + param_1;
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + param_1;
  return;
}


// ==== FUN_0041c376 @ 0041c376

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0041c376(int param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  for (local_18 = 0; local_18 < *(int *)(param_1 + 0x420); local_18 = local_18 + 1) {
    iVar1 = *(int *)(param_1 + 0x424 + local_18 * 4);
    for (local_8 = 0; local_8 < *(int *)(&DAT_004878a8 + iVar1 * 4); local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_00480fd0 + local_8 * 0x28 + iVar1 * 0x348) = 0;
      (&DAT_00480fd8)[local_8 * 0x28 + iVar1 * 0x348] = 0;
      *(undefined4 *)(&DAT_00480fec + local_8 * 0x28 + iVar1 * 0x348) = 0;
      *(undefined4 *)(&DAT_00480ff0 + local_8 * 0x28 + iVar1 * 0x348) = 0;
      *(undefined4 *)(&DAT_00480ff4 + local_8 * 0x28 + iVar1 * 0x348) = 1;
    }
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + iVar1 * 0x18 + local_c * 4);
            local_14 = local_14 + 1) {
          *(undefined4 *)
           (&DAT_004441d8 + local_14 * 0x28 + local_c * 400 + local_8 * 0x960 + iVar1 * 12000) = 0;
          (&DAT_004441e0)[local_14 * 0x28 + local_c * 400 + local_8 * 0x960 + iVar1 * 12000] = 0;
          *(undefined4 *)
           (&DAT_004441f4 + local_14 * 0x28 + local_c * 400 + local_8 * 0x960 + iVar1 * 12000) = 0;
          *(undefined4 *)
           (&DAT_004441f8 + local_14 * 0x28 + local_c * 400 + local_8 * 0x960 + iVar1 * 12000) = 0;
          *(undefined4 *)
           (&DAT_004441fc + local_14 * 0x28 + local_c * 400 + local_8 * 0x960 + iVar1 * 12000) = 1;
        }
      }
    }
  }
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00483520 + local_8 * 0x28) = 0;
    (&DAT_00483528)[local_8 * 0x28] = 0;
    *(undefined4 *)(&DAT_0048353c + local_8 * 0x28) = 0;
    *(undefined4 *)(&DAT_00483540 + local_8 * 0x28) = 0;
    *(undefined4 *)(&DAT_00483544 + local_8 * 0x28) = 1;
  }
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00483498 + local_8 * 0x28) = 0;
    (&DAT_004834a0)[local_8 * 0x28] = 0;
    *(undefined4 *)(&DAT_004834b4 + local_8 * 0x28) = 0;
    *(undefined4 *)(&DAT_004834b8 + local_8 * 0x28) = 0;
    *(undefined4 *)(&DAT_004834bc + local_8 * 0x28) = 1;
  }
  DAT_00483470 = 0;
  DAT_00483478 = 0;
  _DAT_0048348c = 0;
  _DAT_00483490 = 0;
  _DAT_00483494 = 1;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004878a8 + local_8 * 4) = 0;
    *(undefined4 *)(&DAT_00487af0 + local_8 * 4) = 0;
  }
  return;
}


// ==== FUN_0041c90a @ 0041c90a

void FUN_0041c90a(void)

{
  return;
}


// ==== FUN_0041c920 @ 0041c920

void __thiscall FUN_0041c920(void *this,int param_1)

{
  int iVar1;
  bool bVar2;
  int local_3c;
  int local_34;
  int local_24;
  int local_1c;
  
  iVar1 = param_1 * 0x16;
  if (DAT_00443140 == (short *)0x0) {
LAB_0041c9e8:
    local_34 = 0;
  }
  else {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0041c9e8;
    local_34 = (int)*DAT_00443140;
  }
  if (DAT_00443140 == (short *)0x0) {
LAB_0041ca8e:
    local_3c = 0;
  }
  else {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0041ca8e;
    local_3c = (int)DAT_00443140[1];
  }
  FUN_00427075(&DAT_0048d0f0,4,iVar1 + 0x21,4,iVar1 + 0x21,local_34,local_3c,
               *(int **)((int)this + 8),-1);
  FUN_00427cf0(&DAT_0048d0f0,6,iVar1 + 0x23,
               *(short **)(&DAT_00443000 + *(int *)((int)this + param_1 * 4 + 0x20) * 0x28),0);
  if (*(int *)((int)this + 0x1c) + -1 != param_1) {
    return;
  }
  FUN_00427cf0(&DAT_0048d0f0,4,iVar1 + 0x21,DAT_00443140,0);
  if (*(int *)((int)this + param_1 * 4 + 0x20) != 0) {
    return;
  }
  if (*(int *)((int)this + 0xd0c) < 1) {
    return;
  }
  if (4 < *(int *)((int)this + 0xd0c)) {
    return;
  }
  if (DAT_00443140 == (short *)0x0) {
LAB_0041cc27:
    local_1c = 0;
  }
  else {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0041cc27;
    local_1c = (int)*DAT_00443140;
  }
  if (DAT_00443140 != (short *)0x0) {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      local_24 = (int)DAT_00443140[1];
      goto LAB_0041ccd9;
    }
  }
  local_24 = 0;
LAB_0041ccd9:
  FUN_00427075(&DAT_0048d0f0,4,iVar1 + 0x21,4,iVar1 + 0x21,local_1c,local_24,
               *(int **)((int)this + 8),-1);
  FUN_00427cf0(&DAT_0048d0f0,6,iVar1 + 0x23,
               *(short **)(&DAT_00443648 + (4 - *(int *)((int)this + 0xd0c)) * 0x28),0);
  FUN_00427cf0(&DAT_0048d0f0,4,iVar1 + 0x21,DAT_00443140,0);
  return;
}


// ==== FUN_0041cd97 @ 0041cd97

void __thiscall FUN_0041cd97(void *this,int param_1,HDC param_2)

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
  
  FUN_0041c920(this,param_1);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_2);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_2,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_2);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_2,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_2);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_2,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041d194 @ 0041d194

void __fastcall FUN_0041d194(void *param_1)

{
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < *(int *)((int)param_1 + 0x1c); local_10 = local_10 + 1) {
    FUN_0041c920(param_1,local_10);
  }
  return;
}


// ==== FUN_0041d1d9 @ 0041d1d9

void __fastcall FUN_0041d1d9(int param_1)

{
  int iVar1;
  bool bVar2;
  int local_20;
  int local_18;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return;
  }
  iVar1 = (*(int *)(param_1 + 0x1c) + -1) * 0x16;
  if (DAT_00443140 == (short *)0x0) {
LAB_0041d2b7:
    local_18 = 0;
  }
  else {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (bVar2) goto LAB_0041d2b7;
    local_18 = (int)*DAT_00443140;
  }
  if (DAT_00443140 != (short *)0x0) {
    if (*DAT_00443140 == 0x400) {
      if ((int)DAT_00443140[3] * (int)DAT_00443140[4] - *(int *)(DAT_00443140 + 1) == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      local_20 = (int)DAT_00443140[1];
      goto LAB_0041d369;
    }
  }
  local_20 = 0;
LAB_0041d369:
  FUN_00427075(&DAT_0048d0f0,4,iVar1 + 0x21,4,iVar1 + 0x21,local_18,local_20,*(int **)(param_1 + 8),
               -1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_00427cf0(&DAT_0048d0f0,4,iVar1 + 0xb,DAT_00443140,0);
  }
  return;
}


// ==== FUN_0041d404 @ 0041d404

void __thiscall FUN_0041d404(void *this,HDC param_1)

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
  
  FUN_0041d1d9((int)this);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_1);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041d7fd @ 0041d7fd

void __thiscall FUN_0041d7fd(void *this,HDC param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  HDC pHVar9;
  HGDIOBJ pvVar10;
  int y;
  int x;
  int local_14;
  int local_c;
  
  if (*(int *)((int)this + 0xd30) != 0) {
    iVar8 = *(int *)((int)this + 0xd30) + -1;
    for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
      FUN_00431114(&DAT_00443718 + local_c * 0x50,iVar8 * 0x16 + 0x1bf,5,*(int **)((int)this + 8),0)
      ;
      FUN_00430d0a(&DAT_00443718 + local_c * 0x50,iVar8 * 0x16 + 0x1bf,5,1);
      if (DAT_0048d67c != 0) {
        bVar7 = false;
        if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
          for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
            iVar1 = *(int *)(&DAT_0048d548 + local_14 * 0x10);
            iVar2 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
            iVar3 = *(int *)(&DAT_0048d544 + local_14 * 0x10);
            iVar4 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
            iVar5 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
            iVar6 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
            pHVar9 = CreateCompatibleDC(param_1);
            pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
            BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar9,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar9,pvVar10);
            DeleteDC(pHVar9);
            GdiFlush();
          }
          DAT_0048d67c = 0;
        }
        else {
          for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
            if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_14 * 0x10)) &&
               (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_14 * 0x10))) {
              bVar7 = true;
              break;
            }
          }
          if (bVar7) {
            for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
              y = *(int *)(&DAT_0048d540 + local_14 * 0x10) - DAT_0048d698;
              x = *(int *)(&DAT_0048d53c + local_14 * 0x10) - DAT_0048d694;
              iVar1 = *(int *)(&DAT_0048d548 + local_14 * 0x10);
              iVar2 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
              iVar3 = *(int *)(&DAT_0048d544 + local_14 * 0x10);
              iVar4 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
              iVar5 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
              iVar6 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
              pHVar9 = CreateCompatibleDC(param_1);
              pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
              BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar9,iVar6,iVar5,0xcc0020
                    );
              SelectObject(pHVar9,pvVar10);
              DeleteDC(pHVar9);
              GdiFlush();
            }
          }
          else {
            for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
              iVar1 = *(int *)(&DAT_0048d548 + local_14 * 0x10);
              iVar2 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
              iVar3 = *(int *)(&DAT_0048d544 + local_14 * 0x10);
              iVar4 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
              iVar5 = *(int *)(&DAT_0048d540 + local_14 * 0x10);
              iVar6 = *(int *)(&DAT_0048d53c + local_14 * 0x10);
              pHVar9 = CreateCompatibleDC(param_1);
              pvVar10 = SelectObject(pHVar9,DAT_0048d6a0);
              BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar9,iVar6,iVar5,
                     0xcc0020);
              SelectObject(pHVar9,pvVar10);
              DeleteDC(pHVar9);
              GdiFlush();
            }
          }
          DAT_0048d67c = 0;
        }
      }
      FUN_0041bc0c(1);
    }
  }
  return;
}


// ==== FUN_0041dc95 @ 0041dc95

void __fastcall FUN_0041dc95(int param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    FUN_00431114(&DAT_00443718,local_8 * 0x16 + 0x1bf,5,*(int **)(param_1 + 8),0);
  }
  for (local_8 = 0; local_8 < *(int *)(param_1 + 0xd30); local_8 = local_8 + 1) {
    FUN_00430d0a(&DAT_00443718,local_8 * 0x16 + 0x1bf,5,1);
  }
  return;
}


// ==== FUN_0041dd38 @ 0041dd38

void __thiscall FUN_0041dd38(void *this,HDC param_1)

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
  
  FUN_0041dc95((int)this);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_1);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041e131 @ 0041e131

void __thiscall FUN_0041e131(void *this,int param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 == 4) {
    *(int *)((int)this + 0x86c) = *(int *)((int)this + 0x86c) + param_2;
    if (*(int *)this == 9) {
      *(undefined4 *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0xd8) = 4;
      *(undefined4 *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x308) = 0;
      *(int *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x1f0) = param_2;
      *(int *)((int)this + 0xd4) = *(int *)((int)this + 0xd4) + 1;
    }
    else {
      *(int *)((int)this + 0x5dc) = *(int *)((int)this + 0x86c) / 10;
      *(int *)((int)this + 0x5e0) = *(int *)((int)this + 0x86c) % 10;
    }
  }
  else {
    *(int *)(param_1 * 100 + *(int *)((int)this + param_1 * 4 + 0x85c) * 4 + 0x44c + (int)this) =
         param_2;
    piVar1 = (int *)((int)this + param_1 * 4 + 0x85c);
    *piVar1 = *piVar1 + 1;
    if (*(int *)this == 9) {
      *(int *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0xd8) = param_1;
      *(undefined4 *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x308) = 0;
      *(int *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x1f0) = param_2;
      *(int *)((int)this + 0xd4) = *(int *)((int)this + 0xd4) + 1;
    }
  }
  return;
}


// ==== FUN_0041e2a9 @ 0041e2a9

void __thiscall FUN_0041e2a9(void *this,int param_1,int param_2)

{
  int *piVar1;
  
  *(int *)(param_1 * 100 + *(int *)((int)this + param_1 * 4 + 0xcbc) * 4 + 0x8ac + (int)this) =
       param_2;
  piVar1 = (int *)((int)this + param_1 * 4 + 0xcbc);
  *piVar1 = *piVar1 + 1;
  if (*(int *)this == 9) {
    *(int *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0xd8) = param_1;
    *(undefined4 *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x308) = 1;
    *(int *)((int)this + *(int *)((int)this + 0xd4) * 4 + 0x1f0) = param_2;
    *(int *)((int)this + 0xd4) = *(int *)((int)this + 0xd4) + 1;
  }
  return;
}


// ==== FUN_0041e34f @ 0041e34f

void __thiscall FUN_0041e34f(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_244;
  int local_240;
  int local_23c;
  undefined4 auStack_234 [70];
  undefined4 auStack_11c [70];
  
  if (*(int *)this == 9) {
    if (*(int *)((int)this + 0xd4) != 0) {
      if (param_2 == 0) {
        local_240 = 5;
        if (*(int *)((int)this + 0xd4) < 5) {
          local_240 = *(int *)((int)this + 0xd4);
        }
        for (local_244 = 0; local_244 < local_240; local_244 = local_244 + 1) {
          iVar3 = (*(int *)((int)this + 0xd4) - local_244) + -1;
          iVar2 = *(int *)((int)this + iVar3 * 4 + 0xd8);
          if (*(int *)((int)this + iVar3 * 4 + 0x308) == 0) {
            if (iVar2 == 4) {
              *(int *)((int)this + 0x86c) =
                   *(int *)((int)this + 0x86c) - *(int *)((int)this + iVar3 * 4 + 0x1f0);
            }
            else {
              piVar1 = (int *)((int)this + iVar2 * 4 + 0x85c);
              *piVar1 = *piVar1 + -1;
            }
          }
          else {
            piVar1 = (int *)((int)this + iVar2 * 4 + 0xcbc);
            *piVar1 = *piVar1 + -1;
          }
        }
        *(int *)((int)this + 0xd4) = *(int *)((int)this + 0xd4) - local_240;
      }
      else if (param_2 == 1) {
        *(undefined4 *)((int)this + param_1 * 4 + 0x85c) = 0;
        *(undefined4 *)((int)this + param_1 * 4 + 0xcbc) = 0;
        local_23c = 0;
        for (local_244 = 0; local_244 < *(int *)((int)this + 0xd4); local_244 = local_244 + 1) {
          if (*(int *)((int)this + local_244 * 4 + 0xd8) != param_1) {
            auStack_234[local_23c] = *(undefined4 *)((int)this + local_244 * 4 + 0xd8);
            auStack_11c[local_23c] = *(undefined4 *)((int)this + local_244 * 4 + 0x1f0);
            local_23c = local_23c + 1;
          }
        }
        *(int *)((int)this + 0xd4) = local_23c;
        if (*(int *)((int)this + 0xd4) != 0) {
          for (local_244 = 0; local_244 < *(int *)((int)this + 0xd4); local_244 = local_244 + 1) {
            *(undefined4 *)((int)this + local_244 * 4 + 0xd8) = auStack_234[local_244];
            *(undefined4 *)((int)this + local_244 * 4 + 0x1f0) = auStack_11c[local_244];
          }
        }
      }
    }
  }
  else {
    *(undefined4 *)((int)this + param_1 * 4 + 0x85c) = 0;
    *(undefined4 *)((int)this + param_1 * 4 + 0xcbc) = 0;
  }
  return;
}


// ==== FUN_0041e68f @ 0041e68f

void __thiscall FUN_0041e68f(void *this,int param_1)

{
  int local_23c;
  int local_238;
  undefined4 auStack_234 [70];
  undefined4 auStack_11c [70];
  
  if (((*(int *)((int)this + param_1 * 4 + 0xcbc) != 0) &&
      (*(undefined4 *)((int)this + param_1 * 4 + 0xcbc) = 0, *(int *)this == 9)) &&
     (*(int *)((int)this + 0xd4) != 0)) {
    local_238 = 0;
    for (local_23c = 0; local_23c < *(int *)((int)this + 0xd4); local_23c = local_23c + 1) {
      if ((*(int *)((int)this + local_23c * 4 + 0xd8) != param_1) ||
         ((*(int *)((int)this + local_23c * 4 + 0xd8) == param_1 &&
          (*(int *)((int)this + local_23c * 4 + 0x308) == 0)))) {
        auStack_234[local_238] = *(undefined4 *)((int)this + local_23c * 4 + 0xd8);
        auStack_11c[local_238] = *(undefined4 *)((int)this + local_23c * 4 + 0x1f0);
        local_238 = local_238 + 1;
      }
    }
    *(int *)((int)this + 0xd4) = local_238;
    if (*(int *)((int)this + 0xd4) != 0) {
      for (local_23c = 0; local_23c < *(int *)((int)this + 0xd4); local_23c = local_23c + 1) {
        *(undefined4 *)((int)this + local_23c * 4 + 0xd8) = auStack_234[local_23c];
        *(undefined4 *)((int)this + local_23c * 4 + 0x1f0) = auStack_11c[local_23c];
      }
    }
  }
  return;
}


// ==== FUN_0041e86f @ 0041e86f

void __thiscall FUN_0041e86f(void *this,int param_1,int param_2,int param_3)

{
  if (param_2 < *(int *)(&DAT_004878a8 + param_1 * 4)) {
    FUN_00427cf0(&DAT_0048d0f0,(*(int *)((int)this + param_1 * 4 + 0x884) + param_3) * 0x16 + 0xa4,
                 0x177,*(short **)(&DAT_00480fd0 + param_2 * 0x28 + param_1 * 0x348),0);
  }
  return;
}


// ==== FUN_0041e911 @ 0041e911

void FUN_0041e911(int param_1,int param_2,int param_3)

{
  if (param_2 < *(int *)(&DAT_004878a8 + param_1 * 4)) {
    FUN_00427cf0(&DAT_0048d0f0,param_3 * 0x16 + 0xa4,0x177,
                 *(short **)(&DAT_00480fd0 + param_1 * 0x348 + param_2 * 0x28),0);
  }
  return;
}


// ==== FUN_0041e9a0 @ 0041e9a0

void __thiscall FUN_0041e9a0(void *this,int param_1,int param_2,int param_3)

{
  if (param_2 < *(int *)(&DAT_004878a8 + param_1 * 4)) {
    FUN_00427cf0(&DAT_0048d0f0,(*(int *)((int)this + param_1 * 4 + 0xce4) + param_3) * 0x16 + 0xa4,
                 0x177,*(short **)(&DAT_00480fd0 + param_2 * 0x28 + param_1 * 0x348),0);
  }
  return;
}


// ==== FUN_0041ea42 @ 0041ea42

void __fastcall FUN_0041ea42(int *param_1)

{
  int local_10;
  int local_c;
  int local_8;
  
  FUN_0041f372((int)param_1);
  if (*param_1 == 4) {
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      FUN_0041e86f(param_1,*param_1,param_1[local_8 + *param_1 * 0x19 + 0x113],local_8);
    }
  }
  else if (*param_1 == 9) {
    if (param_1[0x35] != 0) {
      local_10 = 0;
      local_c = param_1[0x35];
      if (0xf < param_1[0x35]) {
        local_10 = param_1[0x35] + -0xf;
        local_c = 0xf;
      }
      for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
        FUN_0041e911(param_1[local_10 + local_8 + 0x36],param_1[local_10 + local_8 + 0x7c],local_8);
      }
    }
  }
  else {
    for (local_8 = 0; local_8 < param_1[*param_1 + 0x217]; local_8 = local_8 + 1) {
      FUN_0041e86f(param_1,*param_1,param_1[local_8 + *param_1 * 0x19 + 0x113],local_8);
    }
    for (local_8 = 0; local_8 < param_1[*param_1 + 0x32f]; local_8 = local_8 + 1) {
      FUN_0041e9a0(param_1,*param_1,param_1[local_8 + *param_1 * 0x19 + 0x22b],local_8);
    }
  }
  return;
}


// ==== FUN_0041ec27 @ 0041ec27

void __thiscall FUN_0041ec27(void *this,HDC param_1)

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
  
  FUN_0041ea42(this);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_1);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041f020 @ 0041f020

void __fastcall FUN_0041f020(int param_1)

{
  FUN_00427075(&DAT_0048d0f0,0x20,0x177,0x20,0x177,0x226,0x16,*(int **)(param_1 + 8),-1);
  return;
}


// ==== FUN_0041f071 @ 0041f071

void __thiscall FUN_0041f071(void *this,HDC param_1)

{
  bool bVar1;
  int local_c;
  
  FUN_00427075(&DAT_0048d0f0,0x20,0x177,0x20,0x177,0x226,0x16,*(int **)((int)this + 8),-1);
  if (DAT_0048d67c != 0) {
    bVar1 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_c * 0x10),
                     *(int *)(&DAT_0048d540 + local_c * 0x10),
                     (*(int *)(&DAT_0048d544 + local_c * 0x10) -
                     *(int *)(&DAT_0048d53c + local_c * 0x10)) + 1,
                     (*(int *)(&DAT_0048d548 + local_c * 0x10) -
                     *(int *)(&DAT_0048d540 + local_c * 0x10)) + 1);
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar1 = true;
          break;
        }
      }
      if (bVar1) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_c * 0x10),
                       *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694,
                       *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698);
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_c * 0x10),
                       *(int *)(&DAT_0048d540 + local_c * 0x10),
                       (*(int *)(&DAT_0048d544 + local_c * 0x10) -
                       *(int *)(&DAT_0048d53c + local_c * 0x10)) + 1,
                       (*(int *)(&DAT_0048d548 + local_c * 0x10) -
                       *(int *)(&DAT_0048d540 + local_c * 0x10)) + 1);
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041f2f8 @ 0041f2f8

void __thiscall FUN_0041f2f8(void *this,HDC param_1)

{
  if (*(int *)this == 9) {
    FUN_0041f020((int)this);
    FUN_0041ec27(this,param_1);
  }
  else {
    FUN_0041f071(this,param_1);
  }
  if ((*(int *)((int)this + 0xd0c) == 0) && (0 < *(int *)((int)this + 0x1c))) {
    FUN_0041cd97(this,*(int *)((int)this + 0x1c) + -1,param_1);
  }
  return;
}


// ==== FUN_0041f372 @ 0041f372

void __fastcall FUN_0041f372(int param_1)

{
  FUN_00427075(&DAT_0048d0f0,0xa4,0x177,0xa4,0x177,0x15a,0x16,*(int **)(param_1 + 8),-1);
  return;
}


// ==== FUN_0041f3d9 @ 0041f3d9

void __thiscall FUN_0041f3d9(void *this,HDC param_1)

{
  bool bVar1;
  int local_18;
  
  FUN_00427075(&DAT_0048d0f0,0xa4,0x177,0xa4,0x177,0x15a,0x16,*(int **)((int)this + 8),-1);
  if (DAT_0048d67c != 0) {
    bVar1 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_18 = 0; local_18 < DAT_0048d67c; local_18 = local_18 + 1) {
        FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_18 * 0x10),
                     *(int *)(&DAT_0048d540 + local_18 * 0x10),
                     (*(int *)(&DAT_0048d544 + local_18 * 0x10) -
                     *(int *)(&DAT_0048d53c + local_18 * 0x10)) + 1,
                     (*(int *)(&DAT_0048d548 + local_18 * 0x10) -
                     *(int *)(&DAT_0048d540 + local_18 * 0x10)) + 1);
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_18 = 0; local_18 < DAT_0048d67c; local_18 = local_18 + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_18 * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_18 * 0x10))) {
          bVar1 = true;
          break;
        }
      }
      if (bVar1) {
        for (local_18 = 0; local_18 < DAT_0048d67c; local_18 = local_18 + 1) {
          FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_18 * 0x10),
                       *(int *)(&DAT_0048d53c + local_18 * 0x10) - DAT_0048d694,
                       *(int *)(&DAT_0048d540 + local_18 * 0x10) - DAT_0048d698);
        }
      }
      else {
        for (local_18 = 0; local_18 < DAT_0048d67c; local_18 = local_18 + 1) {
          FUN_0041b120(param_1,*(int *)(&DAT_0048d53c + local_18 * 0x10),
                       *(int *)(&DAT_0048d540 + local_18 * 0x10),
                       (*(int *)(&DAT_0048d544 + local_18 * 0x10) -
                       *(int *)(&DAT_0048d53c + local_18 * 0x10)) + 1,
                       (*(int *)(&DAT_0048d548 + local_18 * 0x10) -
                       *(int *)(&DAT_0048d540 + local_18 * 0x10)) + 1);
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041f676 @ 0041f676

void __thiscall FUN_0041f676(void *this,HDC param_1)

{
  if (*(int *)this == 9) {
    FUN_0041ec27(this,param_1);
  }
  else {
    FUN_0041f3d9(this,param_1);
  }
  return;
}


// ==== FUN_0041f6b7 @ 0041f6b7

void FUN_0041f6b7(int param_1,int param_2)

{
  if (param_1 < 6) {
    FUN_00427cf0(&DAT_0048d0f0,param_2 * 10 + 0x1fe,0x177,
                 *(short **)(&DAT_00442d58 + param_1 * 0x78),0);
  }
  return;
}


// ==== FUN_0041f72a @ 0041f72a

void __fastcall FUN_0041f72a(int param_1)

{
  FUN_00427075(&DAT_0048d0f0,0x1fe,0x177,0x1fe,0x177,0x32,0x16,*(int **)(param_1 + 8),-1);
  return;
}


// ==== FUN_0041f791 @ 0041f791

void __fastcall FUN_0041f791(int param_1)

{
  undefined4 local_8;
  
  FUN_0041f72a(param_1);
  for (local_8 = 0; local_8 < *(int *)(param_1 + 0xd10); local_8 = local_8 + 1) {
    FUN_0041f6b7(*(int *)(param_1 + 0xd14 + local_8 * 4),local_8);
  }
  return;
}


// ==== FUN_0041f7ef @ 0041f7ef

void __thiscall FUN_0041f7ef(void *this,HDC param_1)

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
  
  FUN_0041f791((int)this);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_1);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_0041fbe8 @ 0041fbe8

void __fastcall FUN_0041fbe8(void *param_1)

{
  if (0 < *(int *)((int)param_1 + 0x1c)) {
    FUN_0041c920(param_1,*(int *)((int)param_1 + 0x1c) + -1);
  }
  return;
}


// ==== FUN_0041fc1d @ 0041fc1d

void __fastcall FUN_0041fc1d(int param_1)

{
  FUN_00427075(&DAT_0048d0f0,0x20,0x177,0x20,0x177,0x6e,0x16,*(int **)(param_1 + 8),-1);
  return;
}


// ==== FUN_0041fc84 @ 0041fc84

void __fastcall FUN_0041fc84(void *param_1)

{
  undefined4 local_8;
  
  FUN_0041fc1d((int)param_1);
  if ((*(int *)((int)param_1 + 0xd0c) == 0) && (0 < *(int *)((int)param_1 + 0x1c))) {
    FUN_0041c920(param_1,*(int *)((int)param_1 + 0x1c) + -1);
  }
  for (local_8 = 0; local_8 < *(int *)((int)param_1 + 0xd0c); local_8 = local_8 + 1) {
    FUN_0041fbe8(param_1);
  }
  return;
}


// ==== FUN_0041fd01 @ 0041fd01

void __thiscall FUN_0041fd01(void *this,HDC param_1)

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
  
  FUN_0041fc84(this);
  if (DAT_0048d67c != 0) {
    bVar7 = false;
    if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
        iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
        iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
        iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
        pHVar8 = CreateCompatibleDC(param_1);
        pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
        BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
               0xcc0020);
        SelectObject(pHVar8,pvVar9);
        DeleteDC(pHVar8);
        GdiFlush();
      }
      DAT_0048d67c = 0;
    }
    else {
      for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
        if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
           (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
          bVar7 = true;
          break;
        }
      }
      if (bVar7) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
          x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_1);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_1,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
      }
      DAT_0048d67c = 0;
    }
  }
  return;
}


// ==== FUN_004200fa @ 004200fa

void __fastcall FUN_004200fa(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  for (local_10 = 0; local_10 < *(int *)(param_1 + 0x420); local_10 = local_10 + 1) {
    iVar1 = *(int *)(param_1 + 0x424 + local_10 * 4);
    *(undefined4 *)(&DAT_00487af0 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e72c + iVar1 * 0x28);
    *(undefined4 *)(&DAT_004878a8 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e730 + iVar1 * 0x28);
    *(undefined4 *)(param_1 + 0x834 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e734 + iVar1 * 0x28);
    *(undefined4 *)(param_1 + 0xc94 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e738 + iVar1 * 0x28);
    *(undefined4 *)(param_1 + 0x884 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e73c + iVar1 * 0x28);
    *(undefined4 *)(param_1 + 0xce4 + iVar1 * 4) = *(undefined4 *)(&DAT_0043e740 + iVar1 * 0x28);
    *(undefined4 *)(param_1 + 0x85c + iVar1 * 4) = 0;
    *(undefined4 *)(param_1 + 0xcbc + iVar1 * 4) = 0;
    for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00486a78 + local_c * 4 + iVar1 * 0x18) =
           *(undefined4 *)(&DAT_0043e744 + iVar1 * 0x28);
    }
  }
  return;
}


// ==== FUN_0042024a @ 0042024a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042024a(int param_1)

{
  int iVar1;
  LPVOID pvVar2;
  int local_14;
  int local_10;
  int local_c;
  
  for (local_14 = 0; local_14 < *(int *)(param_1 + 0x420); local_14 = local_14 + 1) {
    iVar1 = *(int *)(param_1 + 0x424 + local_14 * 4);
    switch(iVar1) {
    case 0:
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x471;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x49e;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        FUN_0040c9a0((int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348));
      }
      break;
    case 1:
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x471;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_0044421c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x480;
          *(undefined4 *)(&DAT_00444220 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_00444224 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_00444244 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x48f;
          *(undefined4 *)(&DAT_00444248 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_0044424c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x4a5;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        FUN_0040c9a0((int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348));
      }
      break;
    case 2:
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x4a7;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_0044421c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x4c5;
          *(undefined4 *)(&DAT_00444220 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_00444224 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x4e3;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        FUN_0040c9a0((int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348));
      }
      break;
    case 3:
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x4e4;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        *(int *)(&DAT_0048353c + local_c * 0x28) = local_c + 0x4f8;
        *(undefined4 *)(&DAT_00483540 + local_c * 0x28) = 2;
        *(undefined4 *)(&DAT_00483544 + local_c * 0x28) = 0;
        FUN_0040c9a0((int *)(&DAT_00483520 + local_c * 0x28));
      }
      for (local_c = 0; local_c < 3; local_c = local_c + 1) {
        *(int *)(&DAT_004834b4 + local_c * 0x28) = local_c + 0x4fd;
        *(undefined4 *)(&DAT_004834b8 + local_c * 0x28) = 2;
        *(undefined4 *)(&DAT_004834bc + local_c * 0x28) = 0;
        FUN_0040c9a0((int *)(&DAT_00483498 + local_c * 0x28));
      }
      _DAT_0048348c = 0x500;
      _DAT_00483490 = 2;
      _DAT_00483494 = 0;
      FUN_0040c9a0(&DAT_00483470);
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x501;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        FUN_0040c9a0((int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348));
      }
      break;
    case 4:
      for (local_c = 0; local_c < *(int *)(&DAT_00486a78 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x505;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          if ((*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0) &&
             (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0)) {
            if (*(int *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0) {
              if (*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 1)
              {
                pvVar2 = FUN_00426556(&DAT_004441e0 +
                                      local_10 * 0x960 + local_c * 0x28 + iVar1 * 12000);
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_004441f4 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0)
              {
                *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     1;
              }
            }
            else if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) !=
                     0) {
              *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0
              ;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x537;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        FUN_0040c9a0((int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348));
      }
      break;
    case 5:
      for (local_c = 0; local_c < *(int *)(&DAT_00486a78 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x551;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          if ((*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0) &&
             (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0)) {
            if (*(int *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0) {
              if (*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 1)
              {
                pvVar2 = FUN_00426556(&DAT_004441e0 +
                                      local_10 * 0x960 + local_c * 0x28 + iVar1 * 12000);
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_004441f4 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0)
              {
                *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     1;
              }
            }
            else if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) !=
                     0) {
              *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0
              ;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x560;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        if ((*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) != 0) &&
           (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) == 0)) {
          if (*(int *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) == 0) {
            if (*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) == 1) {
              pvVar2 = FUN_00426556(&DAT_00480fd8 + iVar1 * 0x348 + local_c * 0x28);
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            else {
              pvVar2 = FUN_00426556(*(LPCSTR *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348));
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
              *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 1;
            }
          }
          else if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
            *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 0;
          }
        }
      }
      break;
    case 6:
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x471;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          if ((*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) &&
             (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0)) {
            if (*(int *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0) {
              if (*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 1) {
                pvVar2 = FUN_00426556(&DAT_004441e0 +
                                      local_10 * 0x960 + local_c * 400 + iVar1 * 12000);
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_004441f4 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) {
                *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     1;
              }
            }
            else if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0
                    ) {
              *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_0044421c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x480;
          *(undefined4 *)(&DAT_00444220 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_00444224 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          if ((*(int *)(&DAT_00444220 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) &&
             (*(int *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0)) {
            if (*(int *)(&DAT_00444224 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0) {
              if (*(int *)(&DAT_00444220 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 1) {
                pvVar2 = FUN_00426556((LPCSTR)(local_10 * 0x960 + local_c * 400 + iVar1 * 12000 +
                                              0x444208));
                *(LPVOID *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_0044421c +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
                *(LPVOID *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              if (*(int *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) {
                *(undefined4 *)(&DAT_00444204 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     1;
              }
            }
            else if (*(int *)(&DAT_00444200 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0
                    ) {
              *(undefined4 *)(&DAT_00444204 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_00444244 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x48f;
          *(undefined4 *)(&DAT_00444248 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_0044424c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          if ((*(int *)(&DAT_00444248 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) &&
             (*(int *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0)) {
            if (*(int *)(&DAT_0044424c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 0) {
              if (*(int *)(&DAT_00444248 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) == 1) {
                pvVar2 = FUN_00426556((LPCSTR)(local_10 * 0x960 + local_c * 400 + iVar1 * 12000 +
                                              0x444230));
                *(LPVOID *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_00444244 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
                *(LPVOID *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     pvVar2;
              }
              if (*(int *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0) {
                *(undefined4 *)(&DAT_0044422c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
                     1;
              }
            }
            else if (*(int *)(&DAT_00444228 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) != 0
                    ) {
              *(undefined4 *)(&DAT_0044422c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00487af0 + iVar1 * 4); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_0044426c + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) =
               local_c * 5 + local_10 + 0x542;
          *(undefined4 *)(&DAT_00444270 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 2;
          *(undefined4 *)(&DAT_00444274 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400) = 0;
          FUN_0040c9a0((int *)(&DAT_00444250 + iVar1 * 12000 + local_10 * 0x960 + local_c * 400));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x4a5;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        if ((*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) != 0) &&
           (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) == 0)) {
          if (*(int *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) == 0) {
            if (*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) == 1) {
              pvVar2 = FUN_00426556(&DAT_00480fd8 + iVar1 * 0x348 + local_c * 0x28);
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            else {
              pvVar2 = FUN_00426556(*(LPCSTR *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348));
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
              *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 1;
            }
          }
          else if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
            *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 0;
          }
        }
      }
      break;
    case 7:
      for (local_c = 0; local_c < *(int *)(&DAT_00486a78 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x562;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          FUN_0040c9a0((int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x576;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        if ((*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) != 0) &&
           (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) == 0)) {
          if (*(int *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) == 0) {
            if (*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) == 1) {
              pvVar2 = FUN_00426556(&DAT_00480fd8 + iVar1 * 0x348 + local_c * 0x28);
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            else {
              pvVar2 = FUN_00426556(*(LPCSTR *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348));
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
              *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 1;
            }
          }
          else if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
            *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 0;
          }
        }
      }
      break;
    case 8:
      for (local_c = 0; local_c < *(int *)(&DAT_00486a78 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004441f4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x57a;
          *(undefined4 *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          if ((*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0) &&
             (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0)) {
            if (*(int *)(&DAT_004441fc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0) {
              if (*(int *)(&DAT_004441f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 1)
              {
                pvVar2 = FUN_00426556(&DAT_004441e0 +
                                      local_10 * 0x960 + local_c * 0x28 + iVar1 * 12000);
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_004441f4 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
                *(LPVOID *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0)
              {
                *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     1;
              }
            }
            else if (*(int *)(&DAT_004441d8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) !=
                     0) {
              *(undefined4 *)(&DAT_004441dc + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0
              ;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00486a7c + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_00444384 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x598;
          *(undefined4 *)(&DAT_00444388 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_0044438c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          if ((*(int *)(&DAT_00444388 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0) &&
             (*(int *)(&DAT_00444368 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0)) {
            if (*(int *)(&DAT_0044438c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0) {
              if (*(int *)(&DAT_00444388 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 1)
              {
                pvVar2 = FUN_00426556((LPCSTR)(local_10 * 0x960 + local_c * 0x28 + iVar1 * 12000 +
                                              0x444370));
                *(LPVOID *)(&DAT_00444368 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_00444384 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
                *(LPVOID *)(&DAT_00444368 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              if (*(int *)(&DAT_00444368 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0)
              {
                *(undefined4 *)(&DAT_0044436c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     1;
              }
            }
            else if (*(int *)(&DAT_00444368 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) !=
                     0) {
              *(undefined4 *)(&DAT_0044436c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0
              ;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00486a80 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_00444514 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x5b6;
          *(undefined4 *)(&DAT_00444518 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_0044451c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          FUN_0040c9a0((int *)(&DAT_004444f8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_00486a84 + iVar1 * 0x18); local_c = local_c + 1) {
        for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
          *(int *)(&DAT_004446a4 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
               local_c * 5 + local_10 + 0x5d4;
          *(undefined4 *)(&DAT_004446a8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 2;
          *(undefined4 *)(&DAT_004446ac + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0;
          if ((*(int *)(&DAT_004446a8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0) &&
             (*(int *)(&DAT_00444688 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0)) {
            if (*(int *)(&DAT_004446ac + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 0) {
              if (*(int *)(&DAT_004446a8 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) == 1)
              {
                pvVar2 = FUN_00426556((LPCSTR)(local_10 * 0x960 + local_c * 0x28 + iVar1 * 12000 +
                                              0x444690));
                *(LPVOID *)(&DAT_00444688 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              else {
                pvVar2 = FUN_00426556(*(LPCSTR *)
                                       (&DAT_004446a4 +
                                       iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28));
                *(LPVOID *)(&DAT_00444688 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     pvVar2;
              }
              if (*(int *)(&DAT_00444688 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) != 0)
              {
                *(undefined4 *)(&DAT_0044468c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) =
                     1;
              }
            }
            else if (*(int *)(&DAT_00444688 + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) !=
                     0) {
              *(undefined4 *)(&DAT_0044468c + iVar1 * 12000 + local_10 * 0x960 + local_c * 0x28) = 0
              ;
            }
          }
        }
      }
      for (local_c = 0; local_c < *(int *)(&DAT_004878a8 + iVar1 * 4); local_c = local_c + 1) {
        *(int *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348) = local_c + 0x5f2;
        *(undefined4 *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) = 2;
        *(undefined4 *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) = 0;
        if ((*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) != 0) &&
           (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) == 0)) {
          if (*(int *)(&DAT_00480ff4 + local_c * 0x28 + iVar1 * 0x348) == 0) {
            if (*(int *)(&DAT_00480ff0 + local_c * 0x28 + iVar1 * 0x348) == 1) {
              pvVar2 = FUN_00426556(&DAT_00480fd8 + iVar1 * 0x348 + local_c * 0x28);
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            else {
              pvVar2 = FUN_00426556(*(LPCSTR *)(&DAT_00480fec + local_c * 0x28 + iVar1 * 0x348));
              *(LPVOID *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) = pvVar2;
            }
            if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
              *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 1;
            }
          }
          else if (*(int *)(&DAT_00480fd0 + local_c * 0x28 + iVar1 * 0x348) != 0) {
            *(undefined4 *)(&DAT_00480fd4 + local_c * 0x28 + iVar1 * 0x348) = 0;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_004240bb @ 004240bb

void __fastcall FUN_004240bb(int param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  for (local_18 = 0; local_18 < *(int *)(param_1 + 0x420); local_18 = local_18 + 1) {
    iVar1 = *(int *)(param_1 + 0x424 + local_18 * 4);
    switch(iVar1) {
    case 0:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            *(undefined4 *)
             (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                 *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
          }
        }
      }
      break;
    case 1:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            *(undefined4 *)
             (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                 *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
          }
        }
      }
      break;
    case 2:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            if (local_14 == 0) {
              *(undefined4 *)(&DAT_004835e8 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
            }
            else {
              *(int *)(&DAT_004835e8 +
                      local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   (*(int *)(&DAT_0043d4f0 + local_c * 4) * 6) / 10;
            }
          }
        }
      }
      break;
    case 3:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            switch(local_14) {
            case 0:
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
              break;
            case 1:
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   0xffffffff;
              break;
            case 2:
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   0x1e;
              break;
            case 3:
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   0xffffffff;
            }
          }
        }
      }
      break;
    case 4:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            if (local_14 == 9) {
              *(undefined4 *)(iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0 + 0x48360c) =
                   0xffffffff;
            }
            else {
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
            }
          }
        }
      }
      break;
    case 5:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            if ((local_14 == 0) || (local_14 == 2)) {
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
            }
            else {
              *(int *)(&DAT_004835e8 +
                      local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   (int)(*(int *)(&DAT_0043d4f0 + local_c * 4) +
                        (*(int *)(&DAT_0043d4f0 + local_c * 4) >> 0x1f & 3U)) >> 2;
            }
          }
        }
      }
      break;
    case 6:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            switch(local_14) {
            case 0:
            case 2:
            case 4:
              *(undefined4 *)
               (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
              break;
            case 1:
            case 3:
            case 5:
              *(int *)(&DAT_004835e8 +
                      local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                   *(int *)(&DAT_0043d4f0 + local_c * 4) / 3;
            }
          }
        }
      }
      break;
    case 7:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            *(undefined4 *)
             (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                 *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
          }
        }
      }
      break;
    case 8:
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        for (local_10 = 0; local_10 < *(int *)(&DAT_00487af0 + iVar1 * 4); local_10 = local_10 + 1)
        {
          for (local_14 = 0; local_14 < *(int *)(&DAT_00486a78 + local_10 * 4 + iVar1 * 0x18);
              local_14 = local_14 + 1) {
            *(undefined4 *)
             (&DAT_004835e8 + local_14 * 4 + iVar1 * 0x4b0 + local_10 * 0x28 + local_c * 0xf0) =
                 *(undefined4 *)(&DAT_0043d4f0 + local_c * 4);
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_00424a09 @ 00424a09

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00424a09(int *param_1)

{
  char cVar1;
  int iVar2;
  int aiStack_28 [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  param_1[0x344] = 0;
  param_1[0x343] = 0;
  param_1[0x35] = 0;
  param_1[5] = 0;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    param_1[local_c + 0x217] = 0;
    param_1[local_c + 0x32f] = 0;
  }
  _memset(&DAT_004616ac,0,0xfc04);
  _memset(&DAT_004712b4,0,0xfc04);
  DAT_00480ecc = 0x7f;
  DAT_00480ed0 = 0x7f;
  _DAT_00480fc0 = 0;
  _DAT_00480edc = 0x96;
  _DAT_00480ee4 = 0x68;
  _DAT_00480ee0 = 0x7f;
  _DAT_00480ee8 = 0x7f;
  _DAT_00480f0c = 0;
  _DAT_00480ef4 = 0xffffffff;
  _DAT_00480ef8 = 0xffffffff;
  _DAT_00480efc = 0xffffffff;
  _DAT_00480f00 = 0xffffffff;
  _DAT_00480eec = 0xffffffff;
  _DAT_00480ef0 = 0xffffffff;
  _DAT_00480fa4 = 0;
  _DAT_00480fa8 = 0;
  _DAT_00480fac = 0;
  _DAT_00480f20 = 0xffffffff;
  FUN_00405e3f();
  FUN_004254c6();
  if (param_1[0x34] == 0) {
    DAT_0043f260 = *param_1;
    FUN_0042559a(param_1,*(LPCSTR *)(&DAT_0043e728 + *param_1 * 0x28));
    param_1[0x17] = *(int *)(&DAT_0043e748 + *param_1 * 0x28);
    FUN_0041c90a();
    FUN_00425ece((int)param_1);
    FUN_0041dc95((int)param_1);
    param_1[7] = param_1[0x17];
    for (local_c = 0; local_c < param_1[0x17]; local_c = local_c + 1) {
      param_1[local_c + 8] = 0;
    }
    if (param_1[0x17] < param_1[0x31]) {
      param_1[0x31] = param_1[0x17];
    }
    if (param_1[0x31] != 0) {
      for (local_c = 0; local_c < param_1[0x31]; local_c = local_c + 1) {
        param_1[local_c + 8] = param_1[local_c + 0x22];
      }
    }
    local_c = 0;
    local_18 = param_1[0x31];
    while ((local_c < 2 && (local_18 < param_1[0x17]))) {
      local_8 = FUN_00405e69(8);
      iVar2 = FUN_00405e69(100);
      if (iVar2 < 0x14) {
        param_1[local_18 + 8] = local_8;
        local_18 = local_18 + 1;
      }
      local_c = local_c + 1;
    }
    FUN_00405e3f();
    for (local_c = 0; local_c < 1000; local_c = local_c + 1) {
      local_14 = FUN_00405e69(param_1[0x17]);
      local_10 = FUN_00405e69(param_1[0x17]);
      if (local_10 != local_14) {
        aiStack_28[3] = param_1[local_14 + 8];
        param_1[local_14 + 8] = param_1[local_10 + 8];
        param_1[local_10 + 8] = aiStack_28[3];
      }
    }
    if (param_1[param_1[0x17] + 7] == 6) {
      param_1[param_1[0x17] + 7] = 4;
    }
    if (((param_1[8] != 0) && (param_1[8] != 1)) && (param_1[8] != 5)) {
      aiStack_28[3] = FUN_00405e69(2);
      if (aiStack_28[3] == 0) {
        param_1[8] = 5;
      }
      else {
        param_1[8] = 1;
      }
    }
    param_1[0x31] = 0;
    FUN_0041d194(param_1);
    FUN_0041c376((int)param_1);
    if (*param_1 == 9) {
      param_1[0x108] = 5;
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        param_1[local_c + 0x109] = *(int *)(&DAT_0043f218 + local_c * 4);
      }
    }
    else {
      param_1[0x108] = 1;
      param_1[0x109] = *param_1;
    }
    FUN_004200fa((int)param_1);
    FUN_0042024a((int)param_1);
    FUN_004240bb((int)param_1);
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      aiStack_28[local_c] = -1;
    }
    local_18 = 0;
LAB_00424f7b:
    do {
      aiStack_28[2] = FUN_00405e69(8);
      for (local_c = 0; local_c < local_18; local_c = local_c + 1) {
        if (aiStack_28[local_c] == aiStack_28[2]) goto LAB_00424f7b;
      }
      aiStack_28[local_18] = aiStack_28[2];
      local_18 = local_18 + 1;
    } while (local_18 < 2);
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0044268c + local_c * 0xd0) = 1;
    }
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0044268c + aiStack_28[local_c] * 0xd0) = 0;
    }
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (*(int *)(&DAT_0044268c + local_c * 0xd0) == 0) {
        iVar2 = FUN_0042d60b((int *)(&DAT_0044267c + local_c * 0xd0));
        DAT_00480ed4 = *(int *)(&DAT_0044267c + local_c * 0xd0) + iVar2 / 2 + DAT_004830f8;
        iVar2 = FUN_0042d61b((int)(&DAT_0044267c + local_c * 0xd0));
        DAT_00480ed8 = *(int *)(&DAT_00442680 + local_c * 0xd0) + iVar2 / 2 + DAT_004830fc;
      }
      else {
        FUN_00413669(&DAT_00442670 + local_c * 0xd0,-1);
        DAT_00480f28 = (&DAT_00442720)[local_c * 0xd0];
      }
    }
  }
  else {
    DAT_00480ed4 = (DAT_00483100 + DAT_004830f8) / 2;
    DAT_00480ed8 = (DAT_004830fc + DAT_00483104) / 2;
    iVar2 = FUN_00405e69(6);
    DAT_00480f28 = (char)iVar2;
    iVar2 = FUN_00405e69(6);
    cVar1 = (char)iVar2;
    DAT_00480f29 = cVar1;
    if ((DAT_00480f28 == cVar1) && (DAT_00480f29 = cVar1 + '\x01', '\x05' < DAT_00480f29)) {
      DAT_00480f29 = cVar1 + -1;
    }
  }
  _DAT_00480f04 = 1;
  return;
}


// ==== FUN_0042516c @ 0042516c

void FUN_0042516c(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    FUN_0040fe33((int *)(&DAT_00442670 + local_8 * 0xd0));
  }
  return;
}


// ==== FUN_004251b9 @ 004251b9

void FUN_004251b9(HDC param_1)

{
  FUN_0042516c();
  FUN_0041ba80(param_1);
  return;
}


// ==== FUN_004251e5 @ 004251e5

void __fastcall FUN_004251e5(int param_1)

{
  int local_8;
  
  local_8 = 0;
  do {
    if (7 < local_8) {
      if (*(int *)(param_1 + 0xcc) == 0) {
        *(undefined4 *)(param_1 + 0xcc) = 1;
      }
      return;
    }
    if (*(int *)(&DAT_0044268c + local_8 * 0xd0) == 1) {
      if (DAT_00480f24 == 2) {
        if ((int)(&DAT_00480f28)[DAT_00480fb4] != *(int *)(&DAT_00442720 + local_8 * 0xd0)) {
LAB_004252b4:
          if (DAT_00480f24 == 2) {
            if ((int)(&DAT_00480f28)[DAT_00480fb4 == 0] != *(int *)(&DAT_00442720 + local_8 * 0xd0))
            {
LAB_0042533a:
              FUN_0041205f((int *)(&DAT_00442670 + local_8 * 0xd0));
              goto LAB_004251fd;
            }
          }
          else if (*(int *)(&DAT_00442720 + local_8 * 0xd0) != (int)DAT_00480f28) goto LAB_0042533a;
        }
      }
      else if (*(int *)(&DAT_00442720 + local_8 * 0xd0) != (int)DAT_00480f28) goto LAB_004252b4;
      FUN_00411a29((int *)(&DAT_00442670 + local_8 * 0xd0));
    }
LAB_004251fd:
    local_8 = local_8 + 1;
  } while( true );
}


// ==== FUN_0042539d @ 0042539d

void __thiscall FUN_0042539d(void *this,HDC param_1)

{
  FUN_004251e5((int)this);
  FUN_0041ba80(param_1);
  return;
}


// ==== FUN_004253c9 @ 004253c9

void __fastcall FUN_004253c9(int param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_0044268c + local_8 * 0xd0) == 1) &&
       (*(int *)(&DAT_00442718 + local_8 * 0xd0) != 0)) {
      FUN_00411a29((int *)(&DAT_00442670 + local_8 * 0xd0));
    }
  }
  if (*(int *)(param_1 + 0xcc) != 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  return;
}


// ==== FUN_0042546e @ 0042546e

void __thiscall FUN_0042546e(void *this,HDC param_1)

{
  FUN_004253c9((int)this);
  FUN_0041ba80(param_1);
  return;
}


// ==== FUN_0042549a @ 0042549a

void FUN_0042549a(HDC param_1)

{
  FUN_0042516c();
  FUN_0041bb46(param_1);
  return;
}


// ==== FUN_004254c6 @ 004254c6

void FUN_004254c6(void)

{
  int local_c;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    if (*(int *)(&DAT_0044268c + local_c * 0xd0) != 0) {
      *(undefined4 *)(&DAT_00442700 + local_c * 0xd0) = 0;
      FUN_0042e249(&DAT_00442694 + local_c * 0xd0,0,0,-0x8000,-0x8000);
      *(undefined4 *)(&DAT_0044268c + local_c * 0xd0) = 0;
    }
  }
  return;
}


// ==== FUN_0042559a @ 0042559a

undefined4 __thiscall FUN_0042559a(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  HGLOBAL pvVar4;
  LPCSTR pCVar5;
  int *piVar6;
  uint uVar7;
  int local_30;
  int local_2c;
  char *local_28;
  int local_1c;
  
  FUN_004254c6();
  if (*(LPCSTR *)((int)this + 0xc) == param_1) {
    piVar6 = *(int **)((int)this + 8);
    iVar1 = FUN_0042d61b(0x4864c8);
    iVar2 = FUN_0042d60b(&DAT_004864c8);
    FUN_00427075(&DAT_0048d0f0,DAT_004864c8,DAT_004864cc,DAT_004864c8,DAT_004864cc,iVar2,iVar1,
                 piVar6,-1);
    uVar3 = 1;
  }
  else {
    if (*(int *)((int)this + 8) != 0) {
      GlobalFree(*(HGLOBAL *)((int)this + 8));
    }
    pvVar4 = FUN_004264ac(param_1);
    *(HGLOBAL *)((int)this + 8) = pvVar4;
    if (-1 < DAT_0043f260) {
      pCVar5 = FUN_00426060((uint *)s_LEVEL_0043f274,DAT_0043f260 + 1,2);
      piVar6 = FUN_004264ac(pCVar5);
      if (piVar6 != (int *)0x0) {
        if (*(int *)(*(int *)((int)this + 8) + 0x10) == 3) {
          local_1c = **(int **)((int)this + 8) + *(int *)((int)this + 8) + 0xc;
        }
        else {
          if ((*(int *)(*(int *)((int)this + 8) + 0x20) == 0) &&
             (*(ushort *)(*(int *)((int)this + 8) + 0xe) < 9)) {
            local_2c = 1 << (*(byte *)(*(int *)((int)this + 8) + 0xe) & 0x1f);
          }
          else {
            local_2c = *(int *)(*(int *)((int)this + 8) + 0x20);
          }
          local_1c = **(int **)((int)this + 8) + *(int *)((int)this + 8) + local_2c * 4;
        }
        uVar7 = ((uint)*(ushort *)(*(int *)((int)this + 8) + 0xe) *
                 *(int *)(*(int *)((int)this + 8) + 4) + 0x1f & 0xffffffe0) >> 3;
        if (piVar6[4] == 3) {
          iVar1 = *piVar6 + 0xc;
        }
        else {
          if ((piVar6[8] == 0) && (*(ushort *)((int)piVar6 + 0xe) < 9)) {
            local_30 = 1 << (*(byte *)((int)piVar6 + 0xe) & 0x1f);
          }
          else {
            local_30 = piVar6[8];
          }
          iVar1 = local_30 * 4 + *piVar6;
        }
        local_28 = (char *)((int)piVar6 + iVar1);
        FUN_0042b930((char *)(local_1c +
                             (*(int *)(*(int *)((int)this + 8) + 8) - (piVar6[2] + 5)) * uVar7 +
                             0x2d),local_28,piVar6[1],piVar6[2],uVar7,
                     ((uint)*(ushort *)((int)piVar6 + 0xe) * piVar6[1] + 0x1f & 0xffffffe0) >> 3,0);
        GlobalFree(piVar6);
      }
    }
    if (*(int *)((int)this + 8) == 0) {
      uVar3 = 0;
    }
    else {
      piVar6 = *(int **)((int)this + 8);
      iVar1 = FUN_0042d61b(0x4864c8);
      iVar2 = FUN_0042d60b(&DAT_004864c8);
      FUN_00427075(&DAT_0048d0f0,DAT_004864c8,DAT_004864cc,DAT_004864c8,DAT_004864cc,iVar2,iVar1,
                   piVar6,-1);
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_004258e3 @ 004258e3

bool __fastcall FUN_004258e3(int param_1)

{
  bool bVar1;
  HGLOBAL pvVar2;
  
  pvVar2 = FUN_004264ac(s_TITLEBMP_0043f27c);
  *(HGLOBAL *)(param_1 + 8) = pvVar2;
  if (*(int *)(param_1 + 8) == 0) {
    bVar1 = false;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0x3f7;
    bVar1 = FUN_0042f070(*(int **)(param_1 + 8));
  }
  return bVar1;
}


// ==== FUN_00425941 @ 00425941

void __thiscall FUN_00425941(void *this,HDC param_1)

{
  bool bVar1;
  int iVar2;
  int local_1c;
  int local_14;
  int local_c;
  
  iVar2 = *(int *)((int)this + 4);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      DAT_0044209c = 0;
      FUN_00405ca2();
      DAT_0043d3a8 = 1;
      DAT_0043f260 = 0xffffffff;
      FUN_0042559a(this,s_GAMEOVERBMP_0043f288);
      FUN_0041bb46(param_1);
      PostMessageA(DAT_00442cf8,0x111,0x137,0);
    }
    else if (iVar2 == 2) {
      *(undefined4 *)((int)this + *(int *)this * 4 + 0x60) = 1;
      *(int *)this = *(int *)this + 1;
      if (*(int *)this < 10) {
        PostMessageA(DAT_00442cf8,0x111,300,0);
      }
      else {
        *(undefined4 *)this = 9;
        if (*(int *)((int)this + 0xc4) != 0) {
          iVar2 = FUN_00405e19();
          FUN_0041c2b4(this,iVar2 * *(int *)((int)this + 0xc4) * DAT_0043f0c4);
          *(undefined4 *)((int)this + 0xc4) = 0;
          FUN_00425ece((int)this);
          if (DAT_0048d67c != 0) {
            bVar1 = false;
            if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
              for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_c * 0x10));
              }
              DAT_0048d67c = 0;
            }
            else {
              for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
                if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
                   (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
                  bVar1 = true;
                  break;
                }
              }
              if (bVar1) {
                for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
                  FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_c * 0x10),
                               *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694,
                               *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698);
                }
              }
              else {
                for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
                  FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_c * 0x10));
                }
              }
              DAT_0048d67c = 0;
            }
          }
        }
        FUN_00425ece((int)this);
        if (DAT_0048d67c != 0) {
          bVar1 = false;
          if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
            for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
              FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_14 * 0x10));
            }
            DAT_0048d67c = 0;
          }
          else {
            for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
              if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_14 * 0x10)) &&
                 (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_14 * 0x10))) {
                bVar1 = true;
                break;
              }
            }
            if (bVar1) {
              for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
                FUN_0041b280(param_1,(int *)(&DAT_0048d53c + local_14 * 0x10),
                             *(int *)(&DAT_0048d53c + local_14 * 0x10) - DAT_0048d694,
                             *(int *)(&DAT_0048d540 + local_14 * 0x10) - DAT_0048d698);
              }
            }
            else {
              for (local_14 = 0; local_14 < DAT_0048d67c; local_14 = local_14 + 1) {
                FUN_0041b1b0(param_1,(int *)(&DAT_0048d53c + local_14 * 0x10));
              }
            }
            DAT_0048d67c = 0;
          }
        }
        DAT_0043f260 = 0xffffffff;
        FUN_0042559a(this,s_GAMEOVERBMP_0043f294);
        FUN_0041bb46(param_1);
        bVar1 = true;
        for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
          if ((bVar1) && (*(int *)((int)this + local_1c * 4 + 0x60) != 0)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        if (bVar1) {
          DAT_0043d3a8 = 1;
          PostMessageA(DAT_00442cf8,0x111,0x137,1);
        }
        else {
          DAT_0043d3a8 = 1;
          PostMessageA(DAT_00442cf8,0x111,0x137,1);
        }
      }
    }
    *(undefined4 *)((int)this + 4) = 0;
  }
  return;
}


// ==== FUN_00425ece @ 00425ece

void __fastcall FUN_00425ece(int param_1)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _sprintf(&DAT_00487a70,&DAT_0043f2a0,*(undefined4 *)(param_1 + 0x10));
  if (DAT_00487b20 != (void *)0x0) {
    FUN_0042e249(&DAT_00487b2c,0,0,-0x8000,-0x8000);
    FUN_004300f3(DAT_00487b20,DAT_00487b24,DAT_00487b28,0x487a70,&local_14);
    FUN_0042df38(&DAT_00487b2c,local_14,local_10,local_c,local_8,0);
    FUN_0042f561(DAT_00487b20,DAT_00487b24,DAT_00487b28,0x487a70,0);
  }
  return;
}


// ==== FUN_00425f8d @ 00425f8d

void __thiscall FUN_00425f8d(void *this,HDC param_1)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _sprintf(&DAT_00487a70,&DAT_0043f2a4,*(undefined4 *)((int)this + 0x10));
  if (DAT_00487b20 != (void *)0x0) {
    FUN_0042e249(&DAT_00487b2c,0,0,-0x8000,-0x8000);
    FUN_004300f3(DAT_00487b20,DAT_00487b24,DAT_00487b28,0x487a70,&local_14);
    FUN_0042df38(&DAT_00487b2c,local_14,local_10,local_c,local_8,0);
    FUN_0042f6fc(DAT_00487b20,DAT_00487b24,DAT_00487b28,0x487a70,param_1,0);
  }
  return;
}


// ==== FUN_00426060 @ 00426060

undefined * __cdecl FUN_00426060(uint *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int local_c;
  int local_8;
  
  FUN_00432d40((uint *)&DAT_0048d070,param_1);
  sVar1 = _strlen(&DAT_0048d070);
  if (param_3 < 1) {
    param_3 = 0;
    local_c = param_2;
    do {
      param_3 = param_3 + 1;
      local_c = local_c / 10;
    } while (0 < local_c);
  }
  for (local_8 = param_3; 0 < local_8; local_8 = local_8 + -1) {
    (&DAT_0048d06f)[local_8 + sVar1] = (char)(param_2 % 10) + '0';
    param_2 = param_2 / 10;
  }
  (&DAT_0048d070)[param_3 + sVar1] = 0;
  return &DAT_0048d070;
}


// ==== FUN_00426129 @ 00426129

void __cdecl FUN_00426129(int param_1)

{
  if (param_1 == 0) {
    DAT_0048cc18 = GetDC(DAT_0048cc60);
  }
  else {
    DAT_0048cc18 = BeginPaint(DAT_0048cc60,(LPPAINTSTRUCT)&DAT_0048cc20);
  }
  return;
}


// ==== FUN_0042616f @ 0042616f

void __cdecl FUN_0042616f(int param_1)

{
  if (param_1 == 0) {
    ReleaseDC(DAT_0048cc60,DAT_0048cc18);
  }
  else {
    EndPaint(DAT_0048cc60,(PAINTSTRUCT *)&DAT_0048cc20);
  }
  return;
}


// ==== FUN_004261b1 @ 004261b1

bool __cdecl FUN_004261b1(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

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


// ==== FUN_004261fa @ 004261fa

bool __cdecl FUN_004261fa(HDC param_1,HANDLE param_2,int param_3,int param_4)

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


// ==== FUN_00426290 @ 00426290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HBITMAP __cdecl FUN_00426290(HDC param_1,LPCSTR param_2)

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
  
  hResData = FUN_0040e208(DAT_00483518,param_2,(LPCSTR)0x2,&local_10);
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
        _DAT_0043f2ac = 0;
        _DAT_0048cc68 = 0x300;
        _DAT_0048cc6a = 0x100;
        for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
          (&DAT_0048cc6c)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 2);
          (&DAT_0048cc6d)[local_28 * 4] =
               *(undefined1 *)((int)&local_c[1].biSize + local_28 * 4 + 1);
          (&DAT_0048cc6e)[local_28 * 4] = (char)(&local_c[1].biSize)[local_28];
          (&DAT_0048cc6f)[local_28 * 4] = 0;
        }
        if (DAT_0043f2a8 == (HPALETTE)0x0) {
          DAT_0043f2a8 = CreatePalette((LOGPALETTE *)&DAT_0048cc68);
        }
      }
      hPal = SelectPalette(param_1,DAT_0048d10c,0);
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


// ==== FUN_004264ac @ 004264ac

HGLOBAL __cdecl FUN_004264ac(LPCSTR param_1)

{
  HGLOBAL hResData;
  HGLOBAL hMem;
  LPVOID _Src;
  SIZE_T local_c;
  LPVOID local_8;
  
  hResData = FUN_0040e208(DAT_00483518,param_1,(LPCSTR)0x2,&local_c);
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


// ==== FUN_00426556 @ 00426556

LPVOID __cdecl FUN_00426556(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_0040e208(DAT_00483518,param_1,s_SPRITE_0043f2b0,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    FUN_0040edd3((int)hResData);
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_004265b4 @ 004265b4

LPVOID __cdecl FUN_004265b4(LPCSTR param_1)

{
  HGLOBAL hResData;
  LPVOID pvVar1;
  DWORD local_8;
  
  hResData = FUN_0040e208(DAT_00483518,param_1,s_SPRFONT_0043f2b8,&local_8);
  if (hResData == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    FUN_0040edd3((int)hResData);
    pvVar1 = LockResource(hResData);
  }
  return pvVar1;
}


// ==== FUN_00426612 @ 00426612

undefined2 * __cdecl FUN_00426612(LPCSTR param_1)

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
  
  hResData = FUN_0040e208(DAT_00483518,param_1,(LPCSTR)0x2,&local_10);
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


// ==== FUN_00426820 @ 00426820

void FUN_00426820(void)

{
  FUN_0042683a();
  FUN_004268db();
  return;
}


// ==== FUN_0042683a @ 0042683a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042683a(void)

{
  DAT_0048d0f0 = 0;
  _DAT_0048d0f4 = 0;
  DAT_0048d0f8 = 0;
  DAT_0048d0fc = 0;
  DAT_0048d100 = 0;
  DAT_0048d10c = 0;
  DAT_0048d108 = 1;
  _DAT_0048d538 = 0;
  DAT_0048d67c = 0;
  DAT_0048d684 = 64000;
  _DAT_0048d680 = 1;
  DAT_0048d694 = 0;
  DAT_0048d698 = 0;
  return;
}


// ==== FUN_004268db @ 004268db

void FUN_004268db(void)

{
  _atexit(FUN_004268f8);
  return;
}


// ==== FUN_004268f8 @ 004268f8

void FUN_004268f8(void)

{
  FUN_00426b87(&DAT_0048d0f0);
  return;
}


// ==== FUN_00426912 @ 00426912

undefined4 __thiscall FUN_00426912(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  HDC pHVar3;
  HBITMAP pHVar4;
  HGDIOBJ pvVar5;
  void *local_8;
  
  if (*(int *)this != 0) {
    FUN_00426c60(this);
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
  FUN_00432120();
  uVar2 = FUN_004321f4((int)this + 0x48,param_1);
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
  DAT_0048d6a0 = *(undefined4 *)((int)this + 4);
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
    FUN_00426d1f(this,0,0,param_1,-1);
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_00426b87 @ 00426b87

void __fastcall FUN_00426b87(int *param_1)

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


// ==== FUN_00426c60 @ 00426c60

void __fastcall FUN_00426c60(int *param_1)

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


// ==== FUN_00426d1f @ 00426d1f

undefined4 __thiscall FUN_00426d1f(void *this,int param_1,int param_2,int *param_3,short param_4)

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
    uVar1 = FUN_0042d358(&local_28,&local_68,&local_48);
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
        FUN_0042b9ec((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0042b930(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_4);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_2c + local_54 + -1;
      local_78 = local_18 + local_10 + -1;
      FUN_0042a633(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_00427075 @ 00427075

undefined4 __thiscall
FUN_00427075(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0042d358(&local_28,&local_68,&local_48);
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
        FUN_0042b9ec((undefined4 *)local_6c,(undefined4 *)local_50,local_2c,local_18,local_34,
                     local_30);
      }
      else {
        FUN_0042b930(local_6c,local_50,local_2c,local_18,local_34,local_30,(byte)param_8);
      }
      local_c = 1;
      local_84 = local_54;
      local_80 = local_10;
      local_7c = local_54 + local_2c + -1;
      local_78 = local_10 + local_18 + -1;
      FUN_0042a633(this,&local_84);
    }
  }
  return local_c;
}


// ==== FUN_004273ff @ 004273ff

void __thiscall
FUN_004273ff(void *this,int param_1,int param_2,int *param_3,int *param_4,short param_5)

{
  FUN_00427075(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00427457 @ 00427457

undefined4 __thiscall
FUN_00427457(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_00427075(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_004275c0 @ 004275c0

void __thiscall
FUN_004275c0(void *this,int param_1,int param_2,int *param_3,int *param_4,HDC param_5,short param_6)

{
  FUN_00427457(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5,param_6);
  return;
}


// ==== FUN_0042761c @ 0042761c

undefined4 __thiscall
FUN_0042761c(void *this,int param_1,int param_2,int *param_3,HDC param_4,short param_5)

{
  int iVar1;
  int y;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00426d1f(this,param_1,param_2,param_3,param_5);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_4,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00427793 @ 00427793

undefined4 __thiscall
FUN_00427793(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6)

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
    uVar1 = FUN_0042d358(&local_38,&local_78,&local_58);
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
      FUN_0042ba36(local_7c,local_60,local_80,local_3c,local_20,local_44,local_40,-local_28);
      local_10 = 1;
      local_9c = local_64;
      local_98 = local_14;
      local_94 = local_3c + local_64 + -1;
      local_90 = local_20 + local_14 + -1;
      FUN_0042a633(this,&local_9c);
    }
  }
  return local_10;
}


// ==== FUN_00427b45 @ 00427b45

undefined4 __thiscall
FUN_00427b45(void *this,int param_1,int param_2,int param_3,int param_4,int *param_5,short *param_6,
            HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_00427793(this,param_1,param_2,param_3,param_4,param_5,param_6);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_00427cf0 @ 00427cf0

undefined4 __thiscall FUN_00427cf0(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0042d358(&local_2c,&local_60,&local_48);
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
          FUN_0042b930(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0042a633(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00427f67 @ 00427f67

undefined4 __thiscall
FUN_00427f67(void *this,int param_1,int param_2,short *param_3,undefined1 param_4)

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
      uVar1 = FUN_0042d358(&local_2c,&local_60,&local_48);
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
        FUN_0042bc66(local_64,local_4c,local_30,local_1c,local_34,local_10,param_4);
        local_8 = 1;
        local_78 = local_50;
        local_74 = local_c;
        local_70 = local_30 + local_50 + -1;
        local_6c = local_1c + local_c + -1;
        FUN_0042a633(this,&local_78);
      }
    }
  }
  return local_8;
}


// ==== FUN_004281cc @ 004281cc

undefined4 __thiscall
FUN_004281cc(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0042d358(&local_2c,&local_60,&local_48);
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
          FUN_0042b930(local_64,local_4c,local_30,local_1c,local_34,local_10,0);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0042a633(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00428477 @ 00428477

void __thiscall
FUN_00428477(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_004281cc(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_004284cf @ 004284cf

undefined4 __thiscall
FUN_004284cf(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_004281cc(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00428636 @ 00428636

void __thiscall
FUN_00428636(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_004284cf(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0042868e @ 0042868e

undefined4 __thiscall
FUN_0042868e(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0042d358(&local_2c,&local_60,&local_48);
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
          FUN_0042b9ec(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0042a633(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00428937 @ 00428937

void __thiscall
FUN_00428937(void *this,int param_1,int param_2,int *param_3,short *param_4,int param_5)

{
  FUN_0042868e(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_0042898f @ 0042898f

undefined4 __thiscall
FUN_0042898f(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  
  iVar1 = FUN_0042868e(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_8);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_8,iVar1,y,iVar2,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ==== FUN_00428af6 @ 00428af6

void __thiscall
FUN_00428af6(void *this,int param_1,int param_2,int *param_3,short *param_4,HDC param_5)

{
  FUN_0042898f(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4,param_5);
  return;
}


// ==== FUN_00428b4e @ 00428b4e

undefined4 __thiscall FUN_00428b4e(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_00427cf0(this,param_1,param_2,param_3,0);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00428cbc @ 00428cbc

undefined4 __thiscall
FUN_00428cbc(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0042d358(&local_3c,&local_70,&local_58);
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
          FUN_0042ba36(local_74,local_5c,local_78,local_40,local_24,local_44,local_18,local_2c);
          local_c = 1;
          local_90 = local_60;
          local_8c = local_10;
          local_88 = local_60 + local_40 + -1;
          local_84 = local_10 + local_24 + -1;
          FUN_0042a633(this,&local_90);
        }
        else {
          local_c = 1;
        }
      }
    }
  }
  return local_c;
}


// ==== FUN_00428ff2 @ 00428ff2

undefined4 __thiscall
FUN_00428ff2(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
            short *param_6,HDC param_7)

{
  int iVar1;
  int y;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  HGDIOBJ h;
  
  iVar1 = FUN_00428cbc(this,param_1,param_2,param_3,param_4,param_5,param_6,0);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_7);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_7,iVar1,y,iVar2 - iVar1,iVar3 - y,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ==== FUN_0042919f @ 0042919f

undefined4 __thiscall FUN_0042919f(void *this,int param_1,int param_2,short *param_3,int param_4)

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
      uVar1 = FUN_0042d358(&local_2c,&local_60,&local_48);
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
          FUN_0042b9ec(local_64,local_4c,local_30,local_1c,local_34,local_10);
          local_8 = 1;
          local_78 = local_50;
          local_74 = local_c;
          local_70 = local_30 + local_50 + -1;
          local_6c = local_1c + local_c + -1;
          FUN_0042a633(this,&local_78);
        }
        else {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}


// ==== FUN_00429414 @ 00429414

undefined4 __thiscall FUN_00429414(void *this,int param_1,int param_2,short *param_3,HDC param_4)

{
  int iVar1;
  undefined4 uVar2;
  int y;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0042919f(this,param_1,param_2,param_3,0);
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
      DAT_0048d67c = 0;
      hdc = CreateCompatibleDC(param_4);
      h = SelectObject(hdc,DAT_0048d6a0);
      BitBlt(param_4,iVar1,y,iVar3,iVar4,hdc,iVar1,y,0xcc0020);
      SelectObject(hdc,h);
      DeleteDC(hdc);
      GdiFlush();
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ==== FUN_00429582 @ 00429582

undefined4 __thiscall
FUN_00429582(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0042d358(&local_6c,&local_58,local_14);
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
        FUN_0042b9ec((undefined4 *)local_5c,(undefined4 *)local_40,local_30,local_2c,local_38,
                     *(int *)((int)this + 0x14));
      }
      else {
        FUN_0042b930(local_5c,local_40,local_30,local_2c,local_38,*(int *)((int)this + 0x14),
                     (byte)param_8);
      }
      local_20 = 1;
    }
  }
  return local_20;
}


// ==== FUN_00429876 @ 00429876

undefined4 __thiscall
FUN_00429876(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_0042d358(&local_68,&local_44,local_24);
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
        FUN_0042b9ec((undefined4 *)local_54,(undefined4 *)local_4c,local_34,local_2c,local_c,
                     local_30);
      }
      else {
        FUN_0042b930(local_54,local_4c,local_34,local_2c,local_c,local_30,(byte)param_8);
      }
      local_10 = 1;
    }
  }
  return local_10;
}


// ==== FUN_00429ad5 @ 00429ad5

undefined4 __thiscall FUN_00429ad5(void *this,int *param_1,undefined1 param_2)

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
      uVar3 = FUN_0042d358(&local_38,&local_18,&local_50);
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
        FUN_0042bc0e(local_58,local_3c,local_28,local_40,param_2);
        local_8 = 1;
        local_70 = local_54;
        local_6c = local_1c;
        local_68 = local_3c + local_54 + -1;
        local_64 = local_28 + local_1c + -1;
        FUN_0042a633(this,&local_70);
      }
    }
  }
  return local_8;
}


// ==== FUN_00429db3 @ 00429db3

void __thiscall
FUN_00429db3(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
  puStack_c = &LAB_0042a044;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (((((*(int *)this == 0) || (*(int *)((int)this + 4) == 0)) || (*(int *)((int)this + 8) == 0))
      || ((*(int *)((int)this + 0xc) == 0 || (*(int *)((int)this + 0x10) == 0)))) ||
     (*(int *)((int)this + 0x1c) == 0)) {
    FUN_0042a04e();
    return;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  if ((param_5 == 0) || (param_6 == 0)) {
    local_8 = 0xffffffff;
    FUN_0042a03b();
    FUN_0042a04e();
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
  uVar1 = FUN_0042d358(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0042a03b();
    FUN_0042a04e();
    return;
  }
  local_50 = param_1;
  local_4c = param_2;
  local_48 = (local_28 - local_30) + param_1;
  local_44 = (local_24 - local_2c) + param_2;
  uVar1 = FUN_0042d358(&local_30,&local_50,&local_40);
  if ((int)uVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_0042a03b();
    FUN_0042a04e();
    return;
  }
  FUN_0042df38(&local_20,local_30,local_2c,local_28,local_24,1);
  if (param_7 == -1) {
    FUN_0042e249(&local_20,1,param_1,param_2,-0x8000);
  }
  else {
    FUN_0042e7f0(&local_20,(int)(char)param_7,1,param_1,param_2,-0x8000);
  }
  local_8 = 0xffffffff;
  FUN_0042a03b();
  FUN_0042a04e();
  return;
}


// ==== FUN_0042a03b @ 0042a03b

void FUN_0042a03b(void)

{
  int unaff_EBP;
  
  FUN_0040bb40((int *)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_0042a04e @ 0042a04e

void FUN_0042a04e(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


// ==== FUN_0042a05f @ 0042a05f

void __thiscall FUN_0042a05f(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_00429db3(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_0042a0b3 @ 0042a0b3

undefined4 __thiscall
FUN_0042a0b3(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar2 = FUN_0042d358(&local_20,&local_54,&local_3c);
    if ((int)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_54 = param_1;
      local_50 = param_2;
      local_4c = (local_18 - local_20) + param_1;
      local_48 = (local_14 - local_1c) + param_2;
      uVar2 = FUN_0042d358(&local_20,&local_54,&local_3c);
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
          FUN_0042b9ec((undefined4 *)local_58,(undefined4 *)local_40,local_24,local_10,local_28,
                       local_28);
        }
        else {
          FUN_0042b930(local_58,local_40,local_24,local_10,local_28,local_28,(byte)param_7);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// ==== FUN_0042a36d @ 0042a36d

void __thiscall FUN_0042a36d(void *this,int param_1,int param_2,int *param_3,short param_4)

{
  FUN_0042a0b3(this,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
               (param_3[3] - param_3[1]) + 1,param_4);
  return;
}


// ==== FUN_0042a3c1 @ 0042a3c1

undefined4 __thiscall FUN_0042a3c1(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00427cf0(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00426d1f(this,param_1,param_2,(int *)(param_3 + 8),0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0042a459 @ 0042a459

undefined4 __thiscall FUN_0042a459(void *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_0042919f(this,param_1,param_2,(short *)(param_3 + 8),0);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_00426d1f(this,param_1,param_2,(int *)(param_3 + 8),-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0042a4f4 @ 0042a4f4

undefined4 __thiscall FUN_0042a4f4(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00428b4e(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0042761c(this,param_1,param_2,(int *)(param_3 + 8),param_4,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0042a592 @ 0042a592

undefined4 __thiscall FUN_0042a592(void *this,int param_1,int param_2,int param_3,HDC param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_3 + 6) == 0) {
    uVar1 = FUN_00429414(this,param_1,param_2,(short *)(param_3 + 8),param_4);
  }
  else if (*(short *)(param_3 + 6) == 2) {
    uVar1 = FUN_0042761c(this,param_1,param_2,(int *)(param_3 + 8),param_4,-1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== FUN_0042a633 @ 0042a633

void __thiscall FUN_0042a633(void *this,int *param_1)

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
        iVar1 = FUN_0042d532(&local_14,
                             (int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
                             (int *)((int)this + local_18 * 0x10 + 0x44c));
        if (iVar1 != 0) {
          *(int *)((int)this + local_18 * 0x10 + 0x44c) = local_14;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x450) = local_10;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x454) = local_c;
          *(undefined4 *)((int)this + local_18 * 0x10 + 0x458) = local_8;
          *(int *)((int)this + 0x58c) = *(int *)((int)this + 0x58c) + -1;
LAB_0042a7e6:
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
              iVar1 = FUN_0042d532(&local_14,(int *)((int)this + local_1c * 0x10 + 0x44c),
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
                goto LAB_0042a7e6;
              }
            }
            local_18 = local_18 + 1;
          } while( true );
        }
      }
    }
    else {
      FUN_0042d4dc(&local_14,(int *)((int)this + (*(int *)((int)this + 0x58c) + -1) * 0x10 + 0x44c),
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


// ==== FUN_0042a8ff @ 0042a8ff

void __thiscall FUN_0042a8ff(void *this,int *param_1,int *param_2,HDC param_3)

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
  
  iVar1 = FUN_0042d443(param_1,param_2);
  if (iVar1 == 0) {
    FUN_0042d60b(param_1);
    FUN_0042d61b((int)param_1);
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
      DAT_0048d67c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0048d6a0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
    FUN_0042d60b(param_2);
    FUN_0042d61b((int)param_2);
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
      DAT_0048d67c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0048d6a0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  else {
    FUN_0042d4dc(&local_18,param_1,param_2);
    FUN_0042d60b(&local_18);
    FUN_0042d61b((int)&local_18);
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
      DAT_0048d67c = 0;
      pHVar3 = CreateCompatibleDC(param_3);
      pvVar4 = SelectObject(pHVar3,DAT_0048d6a0);
      BitBlt(param_3,local_1c,local_24,iVar1,local_8,pHVar3,local_1c,local_24,0xcc0020);
      SelectObject(pHVar3,pvVar4);
      DeleteDC(pHVar3);
      GdiFlush();
    }
  }
  return;
}


// ==== FUN_0042ad0a @ 0042ad0a

undefined4 __thiscall
FUN_0042ad0a(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
      uVar1 = FUN_0042d358(&local_38,&local_70,&local_58);
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
        FUN_0042bd64(local_74,local_5c,local_8,local_c,local_3c,local_28,local_40,local_1c,local_18)
        ;
        local_10 = 1;
      }
    }
  }
  return local_10;
}


// ==== FUN_0042afd2 @ 0042afd2

undefined4 __thiscall FUN_0042afd2(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar2 = FUN_0042d358(&local_24,&local_4c,&local_3c);
    if ((int)uVar2 != 0) {
      local_28 = local_1c - local_24;
      local_14 = local_18 - local_20;
      iVar1 = local_20 + local_14 + -1;
      if (*(int *)((int)this + 0x18) == -1) {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0043260c((byte *)(*(int *)((int)this + 0x14) * local_2c + *(int *)((int)this + 8) +
                               local_24),local_28);
        }
      }
      else {
        for (local_2c = local_20; local_2c <= iVar1; local_2c = local_2c + 1) {
          FUN_0043260c((byte *)(((*(int *)((int)this + 0x10) - local_2c) + -1) *
                                *(int *)((int)this + 0x14) + *(int *)((int)this + 8) + local_24),
                       local_28);
        }
      }
      local_8 = 1;
      local_60 = local_24;
      local_5c = local_20;
      local_58 = local_24 + local_28 + -1;
      local_54 = local_20 + local_14 + -1;
      FUN_0042a633(this,&local_60);
    }
  }
  return local_8;
}


// ==== FUN_0042b205 @ 0042b205

void __fastcall FUN_0042b205(int param_1)

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


// ==== FUN_0042b287 @ 0042b287

undefined4 __thiscall
FUN_0042b287(void *this,int param_1,int param_2,int param_3,int param_4,short *param_5,
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
      uVar1 = FUN_0042d358(&local_30,&local_64,&local_4c);
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
        FUN_0042bec9(local_68,local_50,local_8,local_34,local_20,local_38,local_14,local_6c,param_7,
                     '\0');
        local_c = 1;
        local_88 = local_54;
        local_84 = local_10;
        local_80 = local_34 + local_54 + -1;
        local_7c = local_10 + local_20 + -1;
        FUN_0042a633(this,&local_88);
      }
    }
  }
  return local_c;
}


// ==== FUN_0042b5c1 @ 0042b5c1

undefined4 __thiscall FUN_0042b5c1(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0042d358(&local_28,&local_50,&local_3c);
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
        FUN_0042a633(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_0042b778 @ 0042b778

undefined4 __thiscall FUN_0042b778(void *this,int param_1,int param_2,int param_3,int param_4)

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
    uVar1 = FUN_0042d358(&local_28,&local_50,&local_3c);
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
        FUN_0042a633(this,&local_64);
      }
      else {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


// ==== FUN_0042b930 @ 0042b930

/* WARNING: Removing unreachable block (ram,0x0042b98e) */
/* WARNING: Removing unreachable block (ram,0x0042b9c1) */

void __cdecl
FUN_0042b930(char *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
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
        if (cVar2 != (char)((uint)iVar3 >> 8)) goto LAB_0042b996;
LAB_0042b96e:
        cVar2 = param_2[1];
        if (cVar2 != (char)uVar5) goto LAB_0042b99f;
LAB_0042b975:
        cVar2 = param_2[2];
        if (cVar2 != (char)uVar5) goto LAB_0042b9a9;
        while (iVar3 = CONCAT31(uVar5,param_2[3]), param_2[3] != (char)uVar5) {
          while( true ) {
            param_1[3] = (char)iVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar6 = uVar6 - 1;
            if (uVar6 == 0) goto LAB_0042b9c4;
            cVar2 = *param_2;
            uVar5 = (undefined3)((uint)iVar3 >> 8);
            if (cVar2 == (char)((uint)iVar3 >> 8)) goto LAB_0042b96e;
LAB_0042b996:
            *param_1 = cVar2;
            cVar2 = param_2[1];
            if (cVar2 == (char)uVar5) goto LAB_0042b975;
LAB_0042b99f:
            param_1[1] = cVar2;
            cVar2 = param_2[2];
            if (cVar2 == (char)uVar5) break;
LAB_0042b9a9:
            param_1[2] = cVar2;
            iVar3 = CONCAT31(uVar5,param_2[3]);
            if (param_2[3] == (char)uVar5) goto LAB_0042b983;
          }
        }
LAB_0042b983:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0042b9c4:
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


// ==== FUN_0042b9ec @ 0042b9ec

void __cdecl
FUN_0042b9ec(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,
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


// ==== FUN_0042ba36 @ 0042ba36

void __cdecl
FUN_0042ba36(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_00440242 = param_4;
    do {
      for (uVar4 = DAT_00440242 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *param_2;
        if (*param_3 != '\0') goto LAB_0042bab0;
LAB_0042ba7c:
        uVar3 = param_2[1];
        if (param_3[1] != '\0') goto LAB_0042babc;
LAB_0042ba86:
        uVar3 = param_2[2];
        if (param_3[2] != '\0') goto LAB_0042bac9;
        while (uVar3 = param_2[3], param_3[3] != '\0') {
          while( true ) {
            param_1[3] = uVar3;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0042bae8;
            uVar3 = *param_2;
            if (*param_3 == '\0') goto LAB_0042ba7c;
LAB_0042bab0:
            *param_1 = uVar3;
            uVar3 = param_2[1];
            if (param_3[1] == '\0') goto LAB_0042ba86;
LAB_0042babc:
            param_1[1] = uVar3;
            uVar3 = param_2[2];
            if (param_3[2] == '\0') break;
LAB_0042bac9:
            param_1[2] = uVar3;
            uVar3 = param_2[3];
            if (param_3[3] == '\0') goto LAB_0042ba9a;
          }
        }
LAB_0042ba9a:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0042bae8:
      if ((DAT_00440242 & 3) != 0) {
        iVar5 = (DAT_00440242 & 3) + 1;
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


// ==== FUN_0042bb1d @ 0042bb1d

void __cdecl
FUN_0042bb1d(undefined1 *param_1,undefined1 *param_2,char *param_3,uint param_4,int param_5,
            int param_6,int param_7,int param_8,char param_9)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (param_4 != 0) {
    DAT_00440242 = param_4;
    do {
      for (uVar4 = DAT_00440242 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar1 = *param_2;
        if (*param_3 == param_9) goto LAB_0042bb9d;
LAB_0042bb65:
        uVar1 = param_2[1];
        if (param_3[1] == param_9) goto LAB_0042bbaa;
LAB_0042bb70:
        uVar1 = param_2[2];
        if (param_3[2] == param_9) goto LAB_0042bbb8;
        while (uVar1 = param_2[3], param_3[3] == param_9) {
          while( true ) {
            param_1[3] = uVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar4 = uVar4 - 1;
            if (uVar4 == 0) goto LAB_0042bbd8;
            uVar1 = *param_2;
            if (*param_3 != param_9) goto LAB_0042bb65;
LAB_0042bb9d:
            *param_1 = uVar1;
            uVar1 = param_2[1];
            if (param_3[1] != param_9) goto LAB_0042bb70;
LAB_0042bbaa:
            param_1[1] = uVar1;
            uVar1 = param_2[2];
            if (param_3[2] != param_9) break;
LAB_0042bbb8:
            param_1[2] = uVar1;
            uVar1 = param_2[3];
            if (param_3[3] != param_9) goto LAB_0042bb86;
          }
        }
LAB_0042bb86:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0042bbd8:
      if ((DAT_00440242 & 3) != 0) {
        iVar5 = (DAT_00440242 & 3) + 1;
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


// ==== FUN_0042bc0e @ 0042bc0e

void __cdecl
FUN_0042bc0e(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    DAT_00440242 = param_2 & 3;
    uVar1 = param_2 >> 2;
    do {
      for (; uVar2 = DAT_00440242, uVar1 != 0; uVar1 = uVar1 - 1) {
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


// ==== FUN_0042bc66 @ 0042bc66

/* WARNING: Removing unreachable block (ram,0x0042bcc2) */
/* WARNING: Removing unreachable block (ram,0x0042bcf5) */

void __cdecl
FUN_0042bc66(undefined1 *param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
            undefined1 param_7)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    do {
      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0042bcca;
LAB_0042bca2:
        if (param_2[1] != '\0') goto LAB_0042bcd3;
LAB_0042bca9:
        if (param_2[2] != '\0') goto LAB_0042bcdd;
        while (param_2[3] != '\0') {
          while( true ) {
            param_1[3] = param_7;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            uVar3 = uVar3 - 1;
            if (uVar3 == 0) goto LAB_0042bcf8;
            if (*param_2 == '\0') goto LAB_0042bca2;
LAB_0042bcca:
            *param_1 = param_7;
            if (param_2[1] == '\0') goto LAB_0042bca9;
LAB_0042bcd3:
            param_1[1] = param_7;
            if (param_2[2] == '\0') break;
LAB_0042bcdd:
            param_1[2] = param_7;
            if (param_2[3] == '\0') goto LAB_0042bcb7;
          }
        }
LAB_0042bcb7:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      }
LAB_0042bcf8:
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


// ==== FUN_0042bd20 @ 0042bd20

void FUN_0042bd20(void)

{
  byte in_AH;
  undefined4 unaff_ESI;
  
  if (in_AH < DAT_0044024f) {
    if (DAT_0044024e == '\0') {
      return;
    }
    DAT_0044024a = unaff_ESI;
    DAT_0044024e = 0;
    return;
  }
  if (DAT_0044024e == '\x01') {
    return;
  }
  DAT_00440246 = unaff_ESI;
  DAT_0044024e = 1;
  return;
}


// ==== FUN_0042bd64 @ 0042bd64

/* WARNING: Removing unreachable block (ram,0x0042be6d) */

void __cdecl
FUN_0042bd64(char *param_1,char *param_2,char *param_3,int param_4,uint param_5,int param_6,
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
    DAT_0044024e = 0;
    DAT_00440246 = param_3;
    DAT_0044024a = param_4;
    iVar1 = param_9 - param_5;
    DAT_00440242 = param_5;
    do {
      for (uVar3 = DAT_00440242 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if (*param_2 != '\0') goto LAB_0042be02;
LAB_0042bdca:
        if (param_2[1] != '\0') goto LAB_0042be16;
LAB_0042bdd1:
        if (param_2[2] != '\0') goto LAB_0042be2c;
        while (param_2[3] != '\0') {
          while( true ) {
            FUN_0042bd20();
            if (param_3[3] != '\0') {
              param_1[3] = param_3[3];
            }
            param_1 = param_1 + 4;
            param_3 = param_3 + 4;
            param_2 = param_2 + 4;
            DAT_00440246 = DAT_00440246 + 4;
            DAT_0044024a = DAT_0044024a + 4;
            uVar3 = extraout_ECX_02 - 1;
            param_6 = extraout_EDX_02;
            if (uVar3 == 0) goto LAB_0042be70;
            if (*param_2 == '\0') goto LAB_0042bdca;
LAB_0042be02:
            FUN_0042bd20();
            if (*param_3 != '\0') {
              *param_1 = *param_3;
            }
            uVar3 = extraout_ECX;
            param_6 = extraout_EDX;
            if (param_2[1] == '\0') goto LAB_0042bdd1;
LAB_0042be16:
            FUN_0042bd20();
            if (param_3[1] != '\0') {
              param_1[1] = param_3[1];
            }
            uVar3 = extraout_ECX_00;
            param_6 = extraout_EDX_00;
            if (param_2[2] == '\0') break;
LAB_0042be2c:
            FUN_0042bd20();
            if (param_3[2] != '\0') {
              param_1[2] = param_3[2];
            }
            uVar3 = extraout_ECX_01;
            param_6 = extraout_EDX_01;
            if (param_2[3] == '\0') goto LAB_0042bddf;
          }
        }
LAB_0042bddf:
        param_1 = param_1 + 4;
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        DAT_00440246 = DAT_00440246 + 4;
        DAT_0044024a = DAT_0044024a + 4;
      }
LAB_0042be70:
      if ((DAT_00440242 & 3) != 0) {
        iVar4 = (DAT_00440242 & 3) + 1;
        pcVar5 = param_3;
        pcVar6 = param_1;
        while (param_1 = pcVar6, param_3 = pcVar5, iVar4 = iVar4 + -1, iVar4 != 0) {
          cVar2 = *param_2;
          pcVar5 = param_3 + 1;
          pcVar6 = param_1 + 1;
          param_2 = param_2 + 1;
          DAT_00440246 = DAT_00440246 + 1;
          DAT_0044024a = DAT_0044024a + 1;
          if (cVar2 != '\0') {
            FUN_0042bd20();
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
      DAT_00440246 = DAT_00440246 + iVar1;
      DAT_0044024a = DAT_0044024a + iVar1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}


// ==== FUN_0042bec9 @ 0042bec9

void __cdecl
FUN_0042bec9(char *param_1,char *param_2,byte *param_3,uint param_4,int param_5,int param_6,
            int param_7,int param_8,byte param_9,char param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_4 != 0) {
    DAT_00440242 = param_4;
    do {
      for (uVar2 = DAT_00440242 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        cVar1 = *param_2;
        if ((cVar1 != param_10) && (param_9 <= *param_3)) goto LAB_0042bf60;
LAB_0042bf1c:
        cVar1 = param_2[1];
        if ((cVar1 != param_10) && (param_9 <= param_3[1])) goto LAB_0042bf70;
LAB_0042bf2a:
        cVar1 = param_2[2];
        if ((cVar1 != param_10) && (param_9 <= param_3[2])) goto LAB_0042bf81;
        while ((cVar1 = param_2[3], cVar1 != param_10 && (param_9 <= param_3[3]))) {
          while( true ) {
            param_1[3] = cVar1;
            param_1 = param_1 + 4;
            param_2 = param_2 + 4;
            param_3 = param_3 + 4;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_0042bfa4;
            cVar1 = *param_2;
            if ((cVar1 == param_10) || (*param_3 < param_9)) goto LAB_0042bf1c;
LAB_0042bf60:
            *param_1 = cVar1;
            cVar1 = param_2[1];
            if ((cVar1 == param_10) || (param_3[1] < param_9)) goto LAB_0042bf2a;
LAB_0042bf70:
            param_1[1] = cVar1;
            cVar1 = param_2[2];
            if ((cVar1 == param_10) || (param_3[2] < param_9)) break;
LAB_0042bf81:
            param_1[2] = cVar1;
            cVar1 = param_2[3];
            if ((cVar1 == param_10) || (param_3[3] < param_9)) goto LAB_0042bf46;
          }
        }
LAB_0042bf46:
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        param_3 = param_3 + 4;
      }
LAB_0042bfa4:
      if ((DAT_00440242 & 3) != 0) {
        iVar3 = (DAT_00440242 & 3) + 1;
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


// ==== FUN_0042bfe0 @ 0042bfe0

undefined * FUN_0042bfe0(void)

{
  return &DAT_0043f2c0;
}


// ==== FUN_0042bfe6 @ 0042bfe6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042bfe6(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

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
  
  iVar9 = param_1 + _DAT_0043f2c4;
  iVar6 = param_3 + _DAT_0043f2c4;
  iVar4 = iVar6;
  iVar2 = param_2 + _DAT_0043f2c8;
  iVar3 = param_4 + _DAT_0043f2c8;
  if (iVar6 < iVar9) {
    iVar4 = iVar9;
    iVar9 = iVar6;
    iVar2 = param_4 + _DAT_0043f2c8;
    iVar3 = param_2 + _DAT_0043f2c8;
  }
  if ((DAT_0043f2cc <= iVar4) && (iVar9 <= DAT_0043f2d0)) {
    if (iVar2 < iVar3) {
      if (iVar3 < DAT_0043f2d4) {
        return;
      }
      if (DAT_0043f2d8 < iVar2) {
        return;
      }
      if ((iVar9 < DAT_0043f2cc) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_0043f2cc) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_0043f2cc,
         DAT_0043f2d8 < iVar2)) {
        return;
      }
      if ((DAT_0043f2d0 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0043f2d0 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_0043f2d0,
         iVar3 < DAT_0043f2d4)) {
        return;
      }
      if ((iVar2 < DAT_0043f2d4) &&
         (iVar9 = (int)(((longlong)(iVar3 - DAT_0043f2d4) * (longlong)(iVar9 - iVar4)) /
                       (longlong)-(iVar2 - iVar3)) + iVar4, iVar2 = DAT_0043f2d4,
         DAT_0043f2d0 < iVar9)) {
        return;
      }
      if ((DAT_0043f2d8 < iVar3) &&
         (iVar4 = (int)(((longlong)(DAT_0043f2d8 - iVar2) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar3 - iVar2)) + iVar9, iVar3 = DAT_0043f2d8,
         iVar4 < DAT_0043f2cc)) {
        return;
      }
    }
    else {
      if (DAT_0043f2d8 < iVar3) {
        return;
      }
      if (iVar2 < DAT_0043f2d4) {
        return;
      }
      if ((iVar9 < DAT_0043f2cc) &&
         (iVar2 = (int)(((longlong)(iVar4 - DAT_0043f2cc) * (longlong)(iVar2 - iVar3)) /
                       (longlong)(iVar4 - iVar9)) + iVar3, iVar9 = DAT_0043f2cc,
         iVar2 < DAT_0043f2d4)) {
        return;
      }
      if ((DAT_0043f2d0 < iVar4) &&
         (iVar3 = (int)(((longlong)(DAT_0043f2d0 - iVar9) * (longlong)(iVar3 - iVar2)) /
                       (longlong)(iVar4 - iVar9)) + iVar2, iVar4 = DAT_0043f2d0,
         DAT_0043f2d8 < iVar3)) {
        return;
      }
      if ((iVar3 < DAT_0043f2d4) &&
         (iVar4 = (int)(((longlong)(iVar2 - DAT_0043f2d4) * (longlong)(iVar4 - iVar9)) /
                       (longlong)(iVar2 - iVar3)) + iVar9, iVar3 = DAT_0043f2d4,
         iVar4 < DAT_0043f2cc)) {
        return;
      }
      if ((DAT_0043f2d8 < iVar2) &&
         (iVar9 = (int)(((longlong)(DAT_0043f2d8 - iVar3) * (longlong)(iVar9 - iVar4)) /
                       (longlong)(iVar2 - iVar3)) + iVar4, iVar2 = DAT_0043f2d8,
         DAT_0043f2d0 < iVar9)) {
        return;
      }
    }
    if (iVar9 == iVar4) {
      iVar4 = iVar2;
      if (iVar3 <= iVar2) {
        iVar4 = iVar3;
        iVar3 = iVar2;
      }
      puVar10 = (undefined1 *)(DAT_0043f2dc * iVar4 + iVar9 + _DAT_0043f2c0);
      for (iVar4 = (iVar3 - iVar4) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *puVar10 = param_5;
        puVar10 = puVar10 + DAT_0043f2dc;
      }
    }
    else if (iVar2 == iVar3) {
      uVar7 = (iVar4 - iVar9) + 1;
      puVar11 = (undefined4 *)(DAT_0043f2dc * iVar2 + iVar9 + _DAT_0043f2c0);
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
      DAT_0043f2e0 = DAT_0043f2dc;
      uVar7 = iVar4 - iVar9;
      uVar8 = iVar3 - iVar2;
      if (iVar3 < iVar2) {
        DAT_0043f2e0 = -DAT_0043f2dc;
        uVar8 = -uVar8;
      }
      iVar4 = DAT_0043f2e0;
      if ((short)uVar7 < (short)uVar8) {
        puVar10 = (undefined1 *)(DAT_0043f2dc * iVar2 + iVar9 + _DAT_0043f2c0);
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
        puVar10 = (undefined1 *)(DAT_0043f2dc * iVar2 + iVar9 + _DAT_0043f2c0);
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


// ==== FUN_0042c2ee @ 0042c2ee

void __cdecl FUN_0042c2ee(int param_1,byte *param_2,int param_3)

{
  do {
    *param_2 = *(byte *)(param_1 + (uint)*param_2);
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


// ==== FUN_0042c30f @ 0042c30f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042c30f(void *this,int *param_1,int param_2)

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
  
  DAT_004401ec = 0x7fffffff;
  DAT_004401f0 = 0;
  DAT_004401e4 = 0x7fffffff;
  DAT_004401e8 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      DAT_004401e8 = *piVar10 + _DAT_0043f2c4;
      if (DAT_004401e8 <= DAT_004401e4) {
        DAT_004401e4 = DAT_004401e8;
      }
      piVar10 = piVar10 + 2;
      iVar2 = *piVar1 + _DAT_0043f2c8;
      if (iVar2 <= DAT_004401ec) {
        DAT_004401ec = iVar2;
      }
      if (iVar2 <= DAT_004401f0) {
        DAT_004401f0 = iVar2;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_004401e4 <= DAT_0043f2d0) && (DAT_0043f2cc <= DAT_004401e8)) &&
        (DAT_004401ec <= DAT_0043f2d8)) && (DAT_0043f2d4 <= DAT_004401f0)) {
      if (DAT_004401ec <= DAT_0043f2d4) {
        DAT_004401ec = DAT_0043f2d4;
      }
      if (DAT_0043f2d8 <= DAT_004401f0) {
        DAT_004401f0 = DAT_0043f2d8;
      }
      iVar2 = DAT_0043f2d0 + 1;
      piVar10 = &DAT_0043f2e4;
      for (iVar4 = ((DAT_004401f0 - DAT_004401ec) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar2;
        piVar10 = piVar10 + 1;
      }
      puVar14 = &DAT_0043f2e8;
      for (iVar2 = (DAT_004401f0 - DAT_004401ec) + 1; iVar4 = DAT_004401ec, uVar3 = _DAT_004401fc,
          0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar14 = 0xffffffff;
        puVar14 = puVar14 + 2;
      }
      for (; DAT_004401ec = iVar4, _DAT_004401fc = uVar3, 1 < DAT_004401f4;
          DAT_004401f4 = DAT_004401f4 + -1) {
        iVar5 = param_1[1] + _DAT_0043f2c8;
        iVar7 = param_1[3] + _DAT_0043f2c8;
        iVar2 = *param_1 + _DAT_0043f2c4;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_0043f2c4;
        if (iVar7 < iVar5) {
          iVar2 = param_1[2] + _DAT_0043f2c4;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_0043f2c4;
        }
        if ((iVar11 <= DAT_004401f0) && (iVar4 <= iVar7)) {
          if (iVar11 <= iVar4) {
            iVar2 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar2 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_004401f0 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_004401f0 - iVar11) * (longlong)(iVar8 - iVar2)) /
                         (longlong)(iVar7 - iVar11)) + iVar2;
            iVar7 = DAT_004401f0;
          }
          _DAT_004401f8 = &DAT_0043f2e4 + (iVar7 - iVar4) * 2;
          piVar10 = &DAT_0043f2e4 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar2;
          if (iVar8 < iVar2) {
            _DAT_004401fc = -uVar9;
            if ((int)_DAT_004401fc < iVar4) goto LAB_0042c5b1;
            iVar7 = -(_DAT_004401fc + 1 >> 1);
            uVar3 = _DAT_004401fc + 1;
            iVar11 = iVar2;
LAB_0042c588:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0042c588;
              }
              if (piVar10[1] <= iVar2) {
                piVar10[1] = iVar2;
              }
              if (iVar8 <= *piVar10) {
                *piVar10 = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar2 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_004401fc;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0042c5b1:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar6 = 0x80000000;
            _DAT_004401fc = uVar3;
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
            _DAT_004401fc = uVar9;
LAB_0042c546:
            do {
              iVar8 = iVar11;
              uVar9 = uVar3;
              iVar11 = iVar8 + 1;
              bVar17 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar17 != iVar7 < 0) {
                uVar3 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0042c546;
              }
              if (iVar2 <= *piVar10) {
                *piVar10 = iVar2;
              }
              if (piVar10[1] <= iVar8) {
                piVar10[1] = iVar8;
              }
              piVar10 = piVar10 + 2;
              iVar7 = iVar7 - _DAT_004401fc;
              iVar2 = iVar11;
              uVar3 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_004401ec;
        uVar3 = _DAT_004401fc;
      }
      if (DAT_004401e4 <= DAT_0043f2cc) {
        DAT_004401e4 = DAT_0043f2cc;
      }
      DAT_00440208 = (uint)*(ushort *)this;
      DAT_00440204 = (undefined4 *)((int)this + DAT_00440208 * *(ushort *)((int)this + 2) + 4);
      puVar14 = (undefined4 *)((int)this + 4);
      DAT_0044020c = DAT_0043f2dc * iVar4 + _DAT_0043f2c0;
      piVar10 = &DAT_0043f2e4;
      DAT_00440200 = puVar14;
      if (iVar4 <= DAT_004401f0) {
        do {
          iVar2 = *piVar10;
          if (*piVar10 <= DAT_0043f2cc) {
            iVar2 = DAT_0043f2cc;
          }
          iVar11 = piVar10[1];
          if (piVar10[1] <= DAT_0043f2d0) {
            iVar11 = DAT_0043f2d0;
          }
          if (iVar2 <= iVar11) {
            uVar9 = (iVar11 - iVar2) + 1;
            puVar15 = (undefined4 *)(DAT_0044020c + iVar2);
            iVar2 = CONCAT22((short)((uint)(iVar2 - DAT_004401e4) >> 0x10),
                             (ushort)(iVar2 - DAT_004401e4) % (ushort)(byte)DAT_00440208);
            puVar12 = (undefined4 *)((int)puVar14 + iVar2);
            iVar2 = iVar2 - DAT_00440208;
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
              if ((int)DAT_00440208 < (int)uVar9) {
                do {
                  uVar3 = DAT_00440208;
                  uVar9 = uVar9 - DAT_00440208;
                  if ((short)DAT_00440208 != 0) {
                    uVar6 = DAT_00440208 >> 1;
                    puVar12 = puVar14;
                    puVar13 = puVar15;
                    if ((DAT_00440208 & 1) != 0) {
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
                } while ((int)DAT_00440208 < (int)uVar9);
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
          DAT_0044020c = DAT_0044020c + DAT_0043f2dc;
          piVar10 = piVar10 + 2;
          puVar14 = (undefined4 *)((int)puVar14 + DAT_00440208);
          if (DAT_00440204 <= puVar14) {
            puVar14 = DAT_00440200;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_004401f0);
      }
    }
  }
  return;
}


// ==== FUN_0042c756 @ 0042c756

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042c756(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_004401ec = 0x7fffffff;
  DAT_004401f0 = 0;
  DAT_004401e4 = 0x7fffffff;
  DAT_004401e8 = 0;
  if (param_2 != 0) {
    piVar12 = param_1;
    do {
      piVar1 = piVar12 + 1;
      iVar3 = *piVar12 + _DAT_0043f2c4;
      if (iVar3 <= DAT_004401e4) {
        DAT_004401e4 = iVar3;
      }
      if (DAT_004401e8 <= iVar3) {
        DAT_004401e8 = iVar3;
      }
      piVar12 = piVar12 + 2;
      iVar3 = *piVar1 + _DAT_0043f2c8;
      if (iVar3 <= DAT_004401ec) {
        DAT_004401ec = iVar3;
      }
      if (DAT_004401f0 <= iVar3) {
        DAT_004401f0 = iVar3;
      }
    } while ((int)piVar12 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_004401e4 <= DAT_0043f2d0) && (DAT_0043f2cc <= DAT_004401e8)) &&
        (DAT_004401ec <= DAT_0043f2d8)) && (DAT_0043f2d4 <= DAT_004401f0)) {
      if (DAT_004401ec <= DAT_0043f2d4) {
        DAT_004401ec = DAT_0043f2d4;
      }
      if (DAT_0043f2d8 <= DAT_004401f0) {
        DAT_004401f0 = DAT_0043f2d8;
      }
      iVar3 = DAT_0043f2d0 + 1;
      piVar12 = &DAT_0043f2e4;
      for (iVar4 = ((DAT_004401f0 - DAT_004401ec) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar12 = iVar3;
        piVar12 = piVar12 + 1;
      }
      puVar13 = &DAT_0043f2e8;
      for (iVar3 = (DAT_004401f0 - DAT_004401ec) + 1; DAT_004401f4 = param_2, iVar4 = DAT_004401ec,
          uVar6 = _DAT_004401fc, 0 < iVar3; iVar3 = iVar3 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 2;
      }
      for (; DAT_004401ec = iVar4, _DAT_004401fc = uVar6, 1 < DAT_004401f4;
          DAT_004401f4 = DAT_004401f4 + -1) {
        iVar5 = param_1[1] + _DAT_0043f2c8;
        iVar7 = param_1[3] + _DAT_0043f2c8;
        iVar3 = *param_1 + _DAT_0043f2c4;
        iVar11 = iVar5;
        iVar8 = param_1[2] + _DAT_0043f2c4;
        if (iVar7 < iVar5) {
          iVar3 = param_1[2] + _DAT_0043f2c4;
          iVar11 = iVar7;
          iVar7 = iVar5;
          iVar8 = *param_1 + _DAT_0043f2c4;
        }
        if ((iVar11 <= DAT_004401f0) && (iVar4 <= iVar7)) {
          if (iVar11 < iVar4) {
            iVar3 = (int)(((longlong)(iVar7 - iVar4) * (longlong)(iVar3 - iVar8)) /
                         (longlong)(iVar7 - iVar11)) + iVar8;
            iVar11 = iVar4;
          }
          if (DAT_004401f0 < iVar7) {
            iVar8 = (int)(((longlong)(DAT_004401f0 - iVar11) * (longlong)(iVar8 - iVar3)) /
                         (longlong)(iVar7 - iVar11)) + iVar3;
            iVar7 = DAT_004401f0;
          }
          _DAT_004401f8 = &DAT_0043f2e4 + (iVar7 - iVar4) * 2;
          piVar12 = &DAT_0043f2e4 + (iVar11 - iVar4) * 2;
          iVar4 = (iVar7 - iVar4) - (iVar11 - iVar4);
          uVar9 = iVar8 - iVar3;
          if (iVar8 < iVar3) {
            _DAT_004401fc = -uVar9;
            if ((int)_DAT_004401fc < iVar4) goto LAB_0042c9fd;
            iVar7 = -(_DAT_004401fc + 1 >> 1);
            uVar6 = _DAT_004401fc + 1;
            iVar11 = iVar3;
LAB_0042c9d4:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              iVar11 = iVar8 + -1;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0042c9d4;
              }
              if (piVar12[1] <= iVar3) {
                piVar12[1] = iVar3;
              }
              if (iVar8 <= *piVar12) {
                *piVar12 = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar3 = iVar8 + -1;
              iVar7 = iVar7 - _DAT_004401fc;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
          else if ((int)uVar9 < iVar4) {
LAB_0042c9fd:
            iVar11 = (int)(CONCAT44((int)uVar9 >> 1,(uint)((uVar9 & 1) != 0) << 0x1f) /
                          (longlong)iVar4);
            uVar9 = iVar11 * 2;
            iVar4 = iVar4 + 1;
            uVar10 = 0x80000000;
            _DAT_004401fc = uVar6;
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
            _DAT_004401fc = uVar9;
LAB_0042c992:
            do {
              iVar8 = iVar11;
              uVar9 = uVar6;
              iVar11 = iVar8 + 1;
              bVar15 = SCARRY4(iVar7,iVar4);
              iVar7 = iVar7 + iVar4;
              if (bVar15 != iVar7 < 0) {
                uVar6 = uVar9 - 1;
                if (uVar9 - 1 != 0 && 0 < (int)uVar9) goto LAB_0042c992;
              }
              if (iVar3 <= *piVar12) {
                *piVar12 = iVar3;
              }
              if (piVar12[1] <= iVar8) {
                piVar12[1] = iVar8;
              }
              piVar12 = piVar12 + 2;
              iVar7 = iVar7 - _DAT_004401fc;
              iVar3 = iVar11;
              uVar6 = uVar9 - 1;
            } while (uVar9 - 1 != 0 && 0 < (int)uVar9);
          }
        }
        param_1 = param_1 + 2;
        iVar4 = DAT_004401ec;
        uVar6 = _DAT_004401fc;
      }
      iVar3 = DAT_0043f2dc * iVar4 + _DAT_0043f2c0;
      piVar12 = &DAT_0043f2e4;
      uVar2 = CONCAT11(param_3,param_3);
      uStack_14 = CONCAT22(uVar2,uVar2);
      if (iVar4 <= DAT_004401f0) {
        do {
          iVar11 = *piVar12;
          if (*piVar12 <= DAT_0043f2cc) {
            iVar11 = DAT_0043f2cc;
          }
          iVar7 = piVar12[1];
          if (piVar12[1] <= DAT_0043f2d0) {
            iVar7 = DAT_0043f2d0;
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
          iVar3 = iVar3 + DAT_0043f2dc;
          piVar12 = piVar12 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 <= DAT_004401f0);
      }
    }
  }
  return;
}


// ==== FUN_0042cac8 @ 0042cac8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042cac8(int *param_1,int param_2,undefined1 param_3)

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
  
  DAT_004401ec = 0x7fffffff;
  DAT_004401f0 = 0;
  DAT_004401e4 = 0x7fffffff;
  DAT_004401e8 = 0;
  if (param_2 != 0) {
    piVar10 = param_1;
    do {
      piVar1 = piVar10 + 1;
      iVar3 = *piVar10 + _DAT_0043f2c4;
      if (iVar3 <= DAT_004401e4) {
        DAT_004401e4 = iVar3;
      }
      if (DAT_004401e8 <= iVar3) {
        DAT_004401e8 = iVar3;
      }
      piVar10 = piVar10 + 2;
      iVar3 = *piVar1 + _DAT_0043f2c8;
      if (iVar3 <= DAT_004401ec) {
        DAT_004401ec = iVar3;
      }
      if (DAT_004401f0 <= iVar3) {
        DAT_004401f0 = iVar3;
      }
    } while ((int)piVar10 <= (int)(param_1 + (param_2 + -1) * 2));
    if ((((DAT_004401e4 <= DAT_0043f2d0) && (DAT_0043f2cc <= DAT_004401e8)) &&
        (DAT_004401ec <= DAT_0043f2d8)) && (DAT_0043f2d4 <= DAT_004401f0)) {
      if (DAT_004401ec <= DAT_0043f2d4) {
        DAT_004401ec = DAT_0043f2d4;
      }
      if (DAT_0043f2d8 <= DAT_004401f0) {
        DAT_004401f0 = DAT_0043f2d8;
      }
      iVar3 = DAT_0043f2d0 + 1;
      piVar10 = &DAT_0043f2e4;
      for (iVar4 = ((DAT_004401f0 - DAT_004401ec) + 1) * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar10 = iVar3;
        piVar10 = piVar10 + 1;
      }
      iVar3 = (DAT_004401f0 - DAT_004401ec) + 1;
      puVar12 = &DAT_0043f2e8;
      iVar4 = iVar3;
      while (iVar11 = iVar3, DAT_004401f4 = param_2, iVar3 = DAT_004401ec, uVar2 = _DAT_004401fc,
            0 < iVar4) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 2;
        iVar3 = iVar11 + -1;
        iVar4 = iVar11;
      }
      for (; DAT_004401ec = iVar3, _DAT_004401fc = uVar2, 1 < DAT_004401f4;
          DAT_004401f4 = DAT_004401f4 + -1) {
        iVar5 = param_1[1] + _DAT_0043f2c8;
        iVar6 = param_1[3] + _DAT_0043f2c8;
        iVar4 = *param_1 + _DAT_0043f2c4;
        iVar11 = iVar5;
        iVar7 = param_1[2] + _DAT_0043f2c4;
        if (iVar6 < iVar5) {
          iVar4 = param_1[2] + _DAT_0043f2c4;
          iVar11 = iVar6;
          iVar6 = iVar5;
          iVar7 = *param_1 + _DAT_0043f2c4;
        }
        if ((iVar11 <= DAT_004401f0) && (iVar3 <= iVar6)) {
          if (iVar11 < iVar3) {
            iVar4 = (int)(((longlong)(iVar6 - iVar3) * (longlong)(iVar4 - iVar7)) /
                         (longlong)(iVar6 - iVar11)) + iVar7;
            iVar11 = iVar3;
          }
          if (DAT_004401f0 < iVar6) {
            iVar7 = (int)(((longlong)(DAT_004401f0 - iVar11) * (longlong)(iVar7 - iVar4)) /
                         (longlong)(iVar6 - iVar11)) + iVar4;
            iVar6 = DAT_004401f0;
          }
          _DAT_004401f8 = &DAT_0043f2e4 + (iVar6 - iVar3) * 2;
          piVar10 = &DAT_0043f2e4 + (iVar11 - iVar3) * 2;
          iVar3 = (iVar6 - iVar3) - (iVar11 - iVar3);
          uVar8 = iVar7 - iVar4;
          if (iVar7 < iVar4) {
            _DAT_004401fc = -uVar8;
            if ((int)_DAT_004401fc < iVar3) goto LAB_0042cd6c;
            iVar6 = -(_DAT_004401fc + 1 >> 1);
            uVar2 = _DAT_004401fc + 1;
            iVar11 = iVar4;
LAB_0042cd43:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              iVar11 = iVar7 + -1;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0042cd43;
              }
              if (piVar10[1] <= iVar4) {
                piVar10[1] = iVar4;
              }
              if (iVar7 <= *piVar10) {
                *piVar10 = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar4 = iVar7 + -1;
              iVar6 = iVar6 - _DAT_004401fc;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
          else if ((int)uVar8 < iVar3) {
LAB_0042cd6c:
            iVar11 = (int)(CONCAT44((int)uVar8 >> 1,(uint)((uVar8 & 1) != 0) << 0x1f) /
                          (longlong)iVar3);
            uVar8 = iVar11 * 2;
            iVar3 = iVar3 + 1;
            uVar9 = 0x80000000;
            _DAT_004401fc = uVar2;
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
            _DAT_004401fc = uVar8;
LAB_0042cd01:
            do {
              iVar7 = iVar11;
              uVar8 = uVar2;
              iVar11 = iVar7 + 1;
              bVar14 = SCARRY4(iVar6,iVar3);
              iVar6 = iVar6 + iVar3;
              if (bVar14 != iVar6 < 0) {
                uVar2 = uVar8 - 1;
                if (uVar8 - 1 != 0 && 0 < (int)uVar8) goto LAB_0042cd01;
              }
              if (iVar4 <= *piVar10) {
                *piVar10 = iVar4;
              }
              if (piVar10[1] <= iVar7) {
                piVar10[1] = iVar7;
              }
              piVar10 = piVar10 + 2;
              iVar6 = iVar6 - _DAT_004401fc;
              iVar4 = iVar11;
              uVar2 = uVar8 - 1;
            } while (uVar8 - 1 != 0 && 0 < (int)uVar8);
          }
        }
        param_1 = param_1 + 2;
        iVar3 = DAT_004401ec;
        uVar2 = _DAT_004401fc;
      }
      if (DAT_004401e4 <= DAT_0043f2cc) {
        DAT_004401e4 = DAT_0043f2cc;
      }
      DAT_0044020c = DAT_0043f2dc * iVar3 + _DAT_0043f2c0;
      piVar10 = &DAT_0043f2e4;
      if (iVar3 <= DAT_004401f0) {
        do {
          iVar4 = *piVar10;
          if (*piVar10 <= DAT_0043f2cc) {
            iVar4 = DAT_0043f2cc;
          }
          iVar11 = piVar10[1];
          if (DAT_0043f2d0 <= piVar10[1]) {
            iVar11 = DAT_0043f2d0;
          }
          if (iVar4 <= iVar11) {
            puVar13 = (undefined1 *)(DAT_0044020c + iVar4);
            for (iVar11 = (iVar11 - iVar4) + 1; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar13 = param_3;
              puVar13 = puVar13 + 1;
            }
          }
          DAT_0044020c = DAT_0044020c + DAT_0043f2dc;
          piVar10 = piVar10 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= DAT_004401f0);
      }
    }
  }
  return;
}


// ==== FUN_0042ce3e @ 0042ce3e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042ce3e(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

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
  
  DAT_00440220 = '\0';
  if ((int)param_3 < 0) {
    DAT_00440220 = '\x01';
    param_3 = -param_3;
  }
  else if (param_3 == 0) {
    param_3 = 1;
  }
  DAT_00440221 = '\0';
  if ((int)param_4 < 0) {
    DAT_00440221 = '\x01';
    param_4 = -param_4;
  }
  else if (param_4 == 0) {
    param_4 = 1;
  }
  uVar4 = *param_5 / param_3;
  uVar1 = ((ulonglong)(uint)*param_5 % (ulonglong)param_3 << 0x20) / (ulonglong)param_3;
  uVar5 = (uint)uVar1;
  DAT_0044022e = param_5[1] / param_4;
  uVar2 = ((ulonglong)(uint)param_5[1] % (ulonglong)param_4 << 0x20) / (ulonglong)param_4;
  DAT_0044022a = (uint)uVar2;
  DAT_0044023a = (uint)*param_5;
  iVar6 = param_1 + _DAT_0043f2c4;
  iVar8 = param_3 + iVar6 + -1;
  iVar7 = param_2 + _DAT_0043f2c8;
  DAT_0044021c = param_4 + iVar7 + -1;
  DAT_00440218 = iVar7;
  DAT_00440222 = uVar5;
  DAT_00440226 = uVar4;
  if ((((iVar6 <= DAT_0043f2d0) && (DAT_0043f2cc <= iVar8)) && (iVar7 <= DAT_0043f2d8)) &&
     (DAT_0043f2d4 <= DAT_0044021c)) {
    DAT_00440232 = 0;
    _DAT_00440236 = 0;
    puVar10 = param_5 + 2;
    DAT_00440210 = iVar6;
    if ((iVar6 < DAT_0043f2cc) && (DAT_00440210 = DAT_0043f2cc, DAT_00440220 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar6 - DAT_0043f2cc) * (uVar1 & 0xffffffff);
      DAT_00440232 = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + -(iVar6 - DAT_0043f2cc) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    DAT_00440214 = iVar8;
    if ((DAT_0043f2d0 < iVar8) && (DAT_00440214 = DAT_0043f2d0, DAT_00440220 != '\0')) {
      lVar3 = (ulonglong)(uint)(iVar8 - DAT_0043f2d0) * (uVar1 & 0xffffffff);
      DAT_00440232 = DAT_00440232 + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 + (iVar8 - DAT_0043f2d0) * uVar4 + (int)((ulonglong)lVar3 >> 0x20));
    }
    if ((iVar7 < DAT_0043f2d4) && (DAT_00440218 = DAT_0043f2d4, DAT_00440221 == '\0')) {
      lVar3 = (ulonglong)(uint)-(iVar7 - DAT_0043f2d4) * (uVar2 & 0xffffffff);
      _DAT_00440236 = (uint)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                (-(iVar7 - DAT_0043f2d4) * DAT_0044022e + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0044023a);
    }
    iVar6 = DAT_0044021c;
    if ((DAT_0043f2d8 < DAT_0044021c) && (iVar6 = DAT_0043f2d8, DAT_00440221 == '\0')) {
      lVar3 = (ulonglong)(uint)(DAT_0044021c - DAT_0043f2d8) * (uVar2 & 0xffffffff);
      _DAT_00440236 = _DAT_00440236 + (int)lVar3;
      puVar10 = (ushort *)
                ((int)puVar10 +
                ((DAT_0044021c - DAT_0043f2d8) * DAT_0044022e + (int)((ulonglong)lVar3 >> 0x20)) *
                DAT_0044023a);
    }
    DAT_0044022e = DAT_0044022e * DAT_0044023a;
    DAT_0044021c = iVar6;
    if (DAT_00440220 != '\0') {
      DAT_0044023e = puVar10;
      if (DAT_00440221 == '\0') {
        DAT_0044020c = (char *)(DAT_0043f2dc * DAT_00440218 + DAT_00440214 + _DAT_0043f2c0);
        DAT_00440214 = DAT_00440214 - (DAT_00440210 + -1);
        DAT_0044021c = iVar6 - (DAT_00440218 + -1);
        iVar6 = DAT_00440214;
        uVar9 = DAT_00440232;
        pcVar11 = DAT_0044020c;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_0044021c;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_00440236,DAT_0044022a);
          _DAT_00440236 = _DAT_00440236 + DAT_0044022a;
          if (bVar12) {
            DAT_0044023e = (ushort *)((int)DAT_0044023e + DAT_0044023a);
          }
          puVar10 = (ushort *)((int)DAT_0044023e + DAT_0044022e);
          DAT_0044020c = DAT_0044020c + DAT_0043f2dc;
          DAT_0044021c = DAT_0044021c + -1;
          iVar6 = DAT_00440214;
          uVar9 = DAT_00440232;
          pcVar11 = DAT_0044020c;
          DAT_0044023e = puVar10;
        } while (DAT_0044021c != 0 && 0 < iVar7);
      }
      else {
        DAT_0044020c = (char *)(DAT_0043f2dc * iVar6 + DAT_00440214 + _DAT_0043f2c0);
        DAT_00440214 = DAT_00440214 - (DAT_00440210 + -1);
        DAT_0044021c = iVar6 - (DAT_00440218 + -1);
        iVar6 = DAT_00440214;
        uVar9 = DAT_00440232;
        pcVar11 = DAT_0044020c;
        do {
          do {
            if ((char)*puVar10 != '\0') {
              *pcVar11 = (char)*puVar10;
            }
            iVar7 = DAT_0044021c;
            puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar5) + uVar4);
            iVar6 = iVar6 + -1;
            uVar9 = uVar9 + uVar5;
            pcVar11 = pcVar11 + -1;
          } while (iVar6 != 0);
          bVar12 = CARRY4(_DAT_00440236,DAT_0044022a);
          _DAT_00440236 = _DAT_00440236 + DAT_0044022a;
          if (bVar12) {
            DAT_0044023e = (ushort *)((int)DAT_0044023e + DAT_0044023a);
          }
          puVar10 = (ushort *)((int)DAT_0044023e + DAT_0044022e);
          DAT_0044020c = DAT_0044020c + -DAT_0043f2dc;
          DAT_0044021c = DAT_0044021c + -1;
          iVar6 = DAT_00440214;
          uVar9 = DAT_00440232;
          pcVar11 = DAT_0044020c;
          DAT_0044023e = puVar10;
        } while (DAT_0044021c != 0 && 0 < iVar7);
      }
    }
    uVar5 = DAT_00440226;
    uVar4 = DAT_00440222;
    if (DAT_00440221 != '\0') {
      DAT_0044020c = (char *)(DAT_0043f2dc * DAT_0044021c + DAT_00440210 + _DAT_0043f2c0);
      DAT_00440214 = DAT_00440214 - (DAT_00440210 + -1);
      DAT_0044021c = DAT_0044021c - (DAT_00440218 + -1);
      iVar6 = DAT_00440214;
      uVar9 = DAT_00440232;
      pcVar11 = DAT_0044020c;
      DAT_0044023e = puVar10;
      do {
        do {
          if ((char)*puVar10 != '\0') {
            *pcVar11 = (char)*puVar10;
          }
          iVar7 = DAT_0044021c;
          puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
          iVar6 = iVar6 + -1;
          uVar9 = uVar9 + uVar4;
          pcVar11 = pcVar11 + 1;
        } while (iVar6 != 0);
        bVar12 = CARRY4(_DAT_00440236,DAT_0044022a);
        _DAT_00440236 = _DAT_00440236 + DAT_0044022a;
        if (bVar12) {
          DAT_0044023e = (ushort *)((int)DAT_0044023e + DAT_0044023a);
        }
        puVar10 = (ushort *)((int)DAT_0044023e + DAT_0044022e);
        DAT_0044020c = DAT_0044020c + -DAT_0043f2dc;
        DAT_0044021c = DAT_0044021c + -1;
        iVar6 = DAT_00440214;
        uVar9 = DAT_00440232;
        pcVar11 = DAT_0044020c;
        DAT_0044023e = puVar10;
      } while (DAT_0044021c != 0 && 0 < iVar7);
    }
    uVar5 = DAT_00440226;
    uVar4 = DAT_00440222;
    DAT_0044020c = (char *)(DAT_0043f2dc * DAT_00440218 + DAT_00440210 + _DAT_0043f2c0);
    DAT_00440214 = DAT_00440214 - (DAT_00440210 + -1);
    DAT_0044021c = DAT_0044021c - (DAT_00440218 + -1);
    iVar6 = DAT_00440214;
    uVar9 = DAT_00440232;
    pcVar11 = DAT_0044020c;
    DAT_0044023e = puVar10;
    do {
      do {
        if ((char)*puVar10 != '\0') {
          *pcVar11 = (char)*puVar10;
        }
        iVar7 = DAT_0044021c;
        puVar10 = (ushort *)((int)puVar10 + CARRY4(uVar9,uVar4) + uVar5);
        iVar6 = iVar6 + -1;
        uVar9 = uVar9 + uVar4;
        pcVar11 = pcVar11 + 1;
      } while (iVar6 != 0);
      bVar12 = CARRY4(_DAT_00440236,DAT_0044022a);
      _DAT_00440236 = _DAT_00440236 + DAT_0044022a;
      if (bVar12) {
        DAT_0044023e = (ushort *)((int)DAT_0044023e + DAT_0044023a);
      }
      puVar10 = (ushort *)((int)DAT_0044023e + DAT_0044022e);
      DAT_0044020c = DAT_0044020c + DAT_0043f2dc;
      DAT_0044021c = DAT_0044021c + -1;
      iVar6 = DAT_00440214;
      uVar9 = DAT_00440232;
      pcVar11 = DAT_0044020c;
      DAT_0044023e = puVar10;
    } while (DAT_0044021c != 0 && 0 < iVar7);
  }
  return;
}


// ==== FUN_0042d32b @ 0042d32b

void __cdecl FUN_0042d32b(undefined4 *param_1,undefined4 *param_2,uint param_3)

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


// ==== FUN_0042d358 @ 0042d358

undefined8 __cdecl FUN_0042d358(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_0042d443 @ 0042d443

undefined4 __cdecl FUN_0042d443(int *param_1,int *param_2)

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


// ==== FUN_0042d47f @ 0042d47f

void __cdecl FUN_0042d47f(int *param_1,int *param_2)

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


// ==== FUN_0042d4dc @ 0042d4dc

void __cdecl FUN_0042d4dc(int *param_1,int *param_2,int *param_3)

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


// ==== FUN_0042d532 @ 0042d532

undefined4 __cdecl FUN_0042d532(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_0042d443(param_3,param_2);
  if (iVar1 != 0) {
    FUN_0042d4dc(&DAT_00440250,param_2,param_3);
    DAT_00440260 = ((param_2[2] - *param_2) + 1U & 0xffff) *
                   ((param_2[3] - param_2[1]) + 1U & 0xffff);
    if (((DAT_00440258 - DAT_00440250) + 1U & 0xffff) *
        ((DAT_0044025c - DAT_00440254) + 1U & 0xffff) <=
        ((param_3[2] - *param_3) + 1U & 0xffff) * ((param_3[3] - param_3[1]) + 1U & 0xffff) +
        DAT_00440260) {
      *param_1 = DAT_00440250;
      param_1[1] = DAT_00440254;
      param_1[2] = DAT_00440258;
      param_1[3] = DAT_0044025c;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0042d60b @ 0042d60b

int __cdecl FUN_0042d60b(int *param_1)

{
  return (param_1[2] - *param_1) + 1;
}


// ==== FUN_0042d61b @ 0042d61b

int __cdecl FUN_0042d61b(int param_1)

{
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) + 1;
}


// ==== FUN_0042d62c @ 0042d62c

void __cdecl FUN_0042d62c(char *param_1,uint param_2,char param_3)

{
  uint uVar1;
  char *pcVar2;
  
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    if (*param_1 == param_3) goto LAB_0042d672;
LAB_0042d64e:
    if (param_1[1] == param_3) goto LAB_0042d67b;
LAB_0042d655:
    if (param_1[2] == param_3) goto LAB_0042d685;
    while (param_1[3] == param_3) {
      while( true ) {
        param_1[3] = '\0';
        param_1 = param_1 + 4;
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) goto LAB_0042d69c;
        if (*param_1 != param_3) goto LAB_0042d64e;
LAB_0042d672:
        *param_1 = '\0';
        if (param_1[1] != param_3) goto LAB_0042d655;
LAB_0042d67b:
        param_1[1] = '\0';
        if (param_1[2] != param_3) break;
LAB_0042d685:
        param_1[2] = '\0';
        if (param_1[3] != param_3) goto LAB_0042d663;
      }
    }
LAB_0042d663:
    param_1 = param_1 + 4;
  }
LAB_0042d69c:
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


// ==== FUN_0042d6b8 @ 0042d6b8

bool __cdecl FUN_0042d6b8(char *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  *param_4 = param_2;
  param_4[2] = 0xffffffff;
  param_4[1] = param_3;
  param_4[3] = 0xffffffff;
  uVar2 = 0;
LAB_0042d6e3:
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
          if (param_3 != 0) goto LAB_0042d6e3;
          goto LAB_0042d71c;
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
LAB_0042d71c:
      return *param_4 != param_2;
    }
  } while( true );
}


// ==== FUN_0042d730 @ 0042d730

void FUN_0042d730(void)

{
  FUN_0042bfe0();
  return;
}


// ==== FUN_0042d745 @ 0042d745

undefined4 * __cdecl FUN_0042d745(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0042d730();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0042d730();
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


// ==== FUN_0042d78e @ 0042d78e

undefined4 FUN_0042d78e(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0042d730();
  return *puVar1;
}


// ==== FUN_0042d7a5 @ 0042d7a5

undefined4 FUN_0042d7a5(void)

{
  int iVar1;
  
  iVar1 = FUN_0042d730();
  return *(undefined4 *)(iVar1 + 0x1c);
}


// ==== FUN_0042d7bd @ 0042d7bd

void __cdecl FUN_0042d7bd(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  FUN_0042bfe6(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0042d7e9 @ 0042d7e9

void __cdecl FUN_0042d7e9(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0042c756(param_1,param_2,param_3);
  return;
}


// ==== FUN_0042d80d @ 0042d80d

void __thiscall FUN_0042d80d(void *this,int *param_1,int param_2)

{
  FUN_0042c30f(this,param_1,param_2);
  return;
}


// ==== FUN_0042d831 @ 0042d831

void __cdecl FUN_0042d831(int *param_1,int param_2,undefined1 param_3)

{
  FUN_0042cac8(param_1,param_2,param_3);
  return;
}


// ==== FUN_0042d855 @ 0042d855

void __cdecl FUN_0042d855(int param_1,int param_2,uint param_3,uint param_4,ushort *param_5)

{
  FUN_0042ce3e(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_0042d881 @ 0042d881

void __cdecl FUN_0042d881(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    FUN_0042d47f(param_1,param_1);
  }
  else {
    FUN_0042d47f(param_1,param_2);
  }
  return;
}


// ==== FUN_0042d8c0 @ 0042d8c0

undefined4 __thiscall FUN_0042d8c0(void *this,int param_1,int param_2,int param_3,int param_4)

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
  iVar4 = DAT_0048d104;
  iVar3 = DAT_0048d100;
  iVar2 = DAT_0048d0f8;
  if (DAT_0048d0f8 == 0) {
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
    iVar6 = DAT_0048d0fc + -1;
    if (param_3 <= DAT_0048d0fc + -1) {
      iVar6 = param_3;
    }
    iVar7 = DAT_0048d100 + -1;
    if (param_4 <= DAT_0048d100 + -1) {
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
      if (DAT_0048d108 == -1) {
        FUN_0042b9ec((undefined4 *)(puVar1 + 4),(undefined4 *)(iVar2 + param_2 * iVar4 + param_1),
                     uVar8,iVar9,uVar8,iVar4);
      }
      else {
        FUN_0042b9ec((undefined4 *)(puVar1 + 4),
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


// ==== FUN_0042daed @ 0042daed

undefined4 __thiscall FUN_0042daed(void *this,int param_1,int param_2)

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
      local_2c = DAT_0048d0fc;
      local_38 = DAT_0048d100;
      local_28 = DAT_0048d104;
      iVar2 = DAT_0048d0fc + -1;
      if (local_18 <= DAT_0048d0fc + -1) {
        iVar2 = local_18;
      }
      iVar3 = DAT_0048d100 + -1;
      if (local_24 <= DAT_0048d100 + -1) {
        iVar3 = local_24;
      }
      local_34 = local_34 + 4;
      local_10 = (undefined4 *)DAT_0048d0f8;
      local_8 = (iVar2 - local_14) + 1;
      local_c = (iVar3 - local_20) + 1;
      local_48 = local_14 + local_8 + -1;
      local_44 = local_20 + local_c + -1;
      local_50 = local_14;
      local_4c = local_20;
      local_24 = iVar3;
      local_18 = iVar2;
      FUN_0042a633(&DAT_0048d0f0,&local_50);
      if (DAT_0048d108 == -1) {
        local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
        FUN_0042b9ec(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
      }
      else {
        local_10 = (undefined4 *)
                   ((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
        FUN_0042b9ec(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
      }
      local_40 = *(void **)((int)this + *(short *)((int)this + 0x80) * 4);
      local_3c = local_40;
      FUN_00432b10(local_40);
      *(undefined4 *)((int)this + *(short *)((int)this + 0x80) * 4) = 0;
      *(short *)((int)this + 0x80) = *(short *)((int)this + 0x80) + -1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ==== FUN_0042dd92 @ 0042dd92

undefined4 __thiscall FUN_0042dd92(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_0042de1c @ 0042de1c

undefined4 __thiscall FUN_0042de1c(void *this,int *param_1)

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


// ==== FUN_0042dea9 @ 0042dea9

void __fastcall FUN_0042dea9(int param_1)

{
  while (*(short *)(param_1 + 0x80) != -1) {
    FUN_00432b10(*(void **)(param_1 + *(short *)(param_1 + 0x80) * 4));
    *(undefined4 *)(param_1 + *(short *)(param_1 + 0x80) * 4) = 0;
    *(short *)(param_1 + 0x80) = *(short *)(param_1 + 0x80) + -1;
  }
  return;
}


// ==== FUN_0042df1a @ 0042df1a

void __fastcall FUN_0042df1a(int param_1)

{
  FUN_0042dea9(param_1);
  return;
}


// ==== FUN_0042df38 @ 0042df38

undefined4 __thiscall
FUN_0042df38(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)

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
  iVar4 = DAT_0048d104;
  iVar3 = DAT_0048d100;
  iVar2 = DAT_0048d0f8;
  if (DAT_0048d0f8 == 0) {
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
    iVar10 = DAT_0048d0fc + -1;
    if (param_3 <= DAT_0048d0fc + -1) {
      iVar10 = param_3;
    }
    iVar8 = DAT_0048d100 + -1;
    if (param_4 <= DAT_0048d100 + -1) {
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
          FUN_00432b10(*(void **)this);
          pvVar12 = operator_new(uVar11);
          *(void **)this = pvVar12;
          if (*(int *)this == 0) {
            return 0;
          }
          *(uint *)((int)this + 4) = uVar11;
        }
      }
      else {
        FUN_00432b10(*(void **)this);
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
    if (DAT_0048d108 == -1) {
      FUN_0042b9ec((undefined4 *)(psVar1 + 6),(undefined4 *)(iVar2 + iVar7 * iVar4 + iVar6),uVar9,
                   iVar10,uVar9,iVar4);
    }
    else {
      FUN_0042b9ec((undefined4 *)(psVar1 + 6),
                   (undefined4 *)(iVar2 + ((iVar3 - iVar7) + -1) * iVar4 + iVar6),uVar9,iVar10,uVar9
                   ,-iVar4);
    }
    *(undefined4 *)((int)this + 8) = 1;
    *(undefined4 *)((int)this + 0xc) = 1;
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_0042e249 @ 0042e249

undefined4 __thiscall FUN_0042e249(void *this,int param_1,int param_2,int param_3,int param_4)

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
    local_2c = DAT_0048d0fc;
    local_38 = DAT_0048d100;
    local_28 = DAT_0048d104;
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
      iVar3 = DAT_0048d0fc + -1;
      if (local_18 <= DAT_0048d0fc + -1) {
        iVar3 = local_18;
      }
      iVar2 = DAT_0048d100 + -1;
      local_18 = iVar3;
      if (local_24 <= DAT_0048d100 + -1) {
        iVar2 = local_24;
      }
    }
    local_24 = iVar2;
    local_34 = local_34 + 6;
    local_10 = (undefined4 *)DAT_0048d0f8;
    local_8 = (local_18 - local_14) + 1;
    local_c = (local_24 - local_20) + 1;
    local_48 = local_14;
    local_44 = local_20;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    FUN_0042a633(&DAT_0048d0f0,&local_48);
    if (DAT_0048d108 == -1) {
      local_10 = (undefined4 *)((int)local_10 + local_20 * local_28 + local_14);
      FUN_0042b9ec(local_10,(undefined4 *)local_34,local_8,local_c,local_28,local_30);
    }
    else {
      local_10 = (undefined4 *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0042b9ec(local_10,(undefined4 *)local_34,local_8,local_c,-local_28,local_30);
    }
    if (param_2 != 0) {
      if (*(int *)this != 0) {
        FUN_00432b10(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0042e519 @ 0042e519

undefined4 __thiscall
FUN_0042e519(void *this,short *param_1,int param_2,int param_3,int param_4,int param_5)

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
    local_38 = DAT_0048d0fc;
    local_40 = DAT_0048d100;
    local_34 = DAT_0048d104;
    local_3c = local_3c + 6;
    local_18 = (undefined1 *)DAT_0048d0f8;
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
      FUN_0042a633(&DAT_0048d0f0,&local_58);
      if (DAT_0048d108 == -1) {
        local_18 = (undefined1 *)((int)local_18 + local_2c * local_34 + local_20);
        FUN_0042ba36(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,local_34,local_c,
                     local_10);
      }
      else {
        local_18 = (undefined1 *)
                   ((int)local_18 + ((local_40 - local_2c) + -1) * local_34 + local_20);
        FUN_0042ba36(local_18,(undefined1 *)local_3c,local_48,local_c,local_14,-local_34,local_c,
                     local_10);
      }
      if (param_5 != 0) {
        if (*(int *)this != 0) {
          FUN_00432b10(*(void **)this);
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


// ==== FUN_0042e7f0 @ 0042e7f0

undefined4 __thiscall
FUN_0042e7f0(void *this,int param_1,byte param_2,int param_3,int param_4,int param_5)

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
    local_2c = DAT_0048d0fc;
    local_38 = DAT_0048d100;
    local_28 = DAT_0048d104;
    iVar2 = DAT_0048d0fc + -1;
    if (local_18 <= DAT_0048d0fc + -1) {
      iVar2 = local_18;
    }
    iVar3 = DAT_0048d100 + -1;
    if (local_24 <= DAT_0048d100 + -1) {
      iVar3 = local_24;
    }
    local_34 = local_34 + 6;
    local_10 = (char *)DAT_0048d0f8;
    local_8 = (iVar2 - local_14) + 1;
    local_c = (iVar3 - local_20) + 1;
    local_40 = local_8 + local_14 + -1;
    local_3c = local_c + local_20 + -1;
    local_48 = local_14;
    local_44 = local_20;
    local_24 = iVar3;
    local_18 = iVar2;
    FUN_0042a633(&DAT_0048d0f0,&local_48);
    if (DAT_0048d108 == -1) {
      local_10 = (char *)((int)local_10 + local_28 * local_20 + local_14);
      FUN_0042b930(local_10,(char *)local_34,local_8,local_c,local_28,local_30,param_2);
    }
    else {
      local_10 = (char *)((int)local_10 + ((local_38 - local_20) + -1) * local_28 + local_14);
      FUN_0042b930(local_10,(char *)local_34,local_8,local_c,-local_28,local_30,param_2);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_00432b10(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0042eac9 @ 0042eac9

undefined4 __thiscall
FUN_0042eac9(void *this,HDC param_1,int param_2,int param_3,int param_4,int param_5)

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
    iVar5 = DAT_0048d0fc + -1;
    if (local_18 <= DAT_0048d0fc + -1) {
      iVar5 = local_18;
    }
    iVar4 = DAT_0048d100 + -1;
    if (local_24 <= DAT_0048d100 + -1) {
      iVar4 = local_24;
    }
    cx = (iVar5 - local_14) + 1;
    iVar5 = (iVar4 - local_20) + 1;
    if (DAT_0048d108 == -1) {
      FUN_0042b9ec((undefined4 *)(DAT_0048d0f8 + DAT_0048d104 * local_20 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,DAT_0048d104,iVar3);
    }
    else {
      FUN_0042b9ec((undefined4 *)
                   (DAT_0048d0f8 + ((DAT_0048d100 - local_20) + -1) * DAT_0048d104 + local_14),
                   (undefined4 *)(psVar1 + 6),cx,iVar5,-DAT_0048d104,iVar3);
    }
    if (param_3 != 0) {
      if (*(int *)this != 0) {
        FUN_00432b10(*(void **)this);
      }
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    DAT_0048d67c = 0;
    hdc = CreateCompatibleDC(param_1);
    h = SelectObject(hdc,DAT_0048d6a0);
    BitBlt(param_1,local_14,local_20,cx,iVar5,hdc,local_14,local_20,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
    GdiFlush();
    uVar2 = 1;
  }
  return uVar2;
}


// ==== FUN_0042edf6 @ 0042edf6

bool __thiscall FUN_0042edf6(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

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


// ==== FUN_0042ee69 @ 0042ee69

bool __thiscall FUN_0042ee69(void *this,int *param_1)

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


// ==== FUN_0042eee0 @ 0042eee0

uint __thiscall FUN_0042eee0(void *this,int param_1,int param_2)

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


// ==== FUN_0042ef6a @ 0042ef6a

void __thiscall FUN_0042ef6a(void *this,int param_1,int param_2,undefined1 param_3)

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


// ==== FUN_0042f000 @ 0042f000

void FUN_0042f000(void)

{
  FUN_0042f01a();
  FUN_0042f039();
  return;
}


// ==== FUN_0042f01a @ 0042f01a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f01a(void)

{
  _DAT_0048d6a4 = 0x5452494d;
  return;
}


// ==== FUN_0042f039 @ 0042f039

void FUN_0042f039(void)

{
  _atexit(FUN_0042f056);
  return;
}


// ==== FUN_0042f056 @ 0042f056

void FUN_0042f056(void)

{
  FUN_0042f1e8();
  return;
}


// ==== FUN_0042f070 @ 0042f070

bool __cdecl FUN_0042f070(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00426912(&DAT_0048d0f0,param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_0042d730();
    *puVar2 = DAT_0048d0f8;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = DAT_0048d0fc + -1;
    puVar2[5] = 0;
    puVar2[6] = DAT_0048d100 + -1;
    puVar2[7] = DAT_0048d104;
  }
  return iVar1 != 0;
}


// ==== FUN_0042f12f @ 0042f12f

undefined4 * __cdecl FUN_0042f12f(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar1 = (undefined4 *)FUN_0042d730();
  puVar3 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0042d730();
  *puVar1 = DAT_0048d0f8;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = DAT_0048d0fc + -1;
  puVar1[5] = 0;
  puVar1[6] = DAT_0048d100 + -1;
  puVar1[7] = DAT_0048d104;
  puVar1 = local_24;
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// ==== FUN_0042f1e8 @ 0042f1e8

void FUN_0042f1e8(void)

{
  FUN_00426c60(&DAT_0048d0f0);
  return;
}


// ==== FUN_0042f207 @ 0042f207

void __cdecl FUN_0042f207(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0042f230 @ 0042f230

void __cdecl FUN_0042f230(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  DefWindowProcA(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0042f259 @ 0042f259

uint __cdecl FUN_0042f259(int param_1)

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


// ==== FUN_0042f2d3 @ 0042f2d3

uint __cdecl FUN_0042f2d3(int param_1)

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


// ==== FUN_0042f34e @ 0042f34e

uint __cdecl FUN_0042f34e(int param_1)

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


// ==== FUN_0042f3dd @ 0042f3dd

int __cdecl FUN_0042f3dd(int param_1)

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


// ==== FUN_0042f4b3 @ 0042f4b3

int __cdecl FUN_0042f4b3(int param_1)

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


// ==== FUN_0042f520 @ 0042f520

bool __thiscall FUN_0042f520(void *this,LPCSTR param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = FUN_004265b4(param_1);
  *(LPVOID *)this = pvVar1;
  return *(int *)this != 0;
}


// ==== FUN_0042f561 @ 0042f561

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f561(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int local_30;
  int local_28;
  int local_24;
  int local_20 [4];
  int local_10;
  short *local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    _DAT_0048d680 = 0;
    FUN_004300f3(this,param_1,param_2,param_3,local_20);
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
        FUN_00427cf0(&DAT_0048d0f0,local_28,param_2,local_c,0);
      }
      else {
        FUN_00427f67(&DAT_0048d0f0,local_28,param_2,local_c,*(undefined1 *)((int)this + 0xc));
      }
      local_28 = local_28 + *(int *)((int)this + 4) + local_8;
    }
    _DAT_0048d680 = 1;
    FUN_0042a633(&DAT_0048d0f0,local_20);
  }
  return;
}


// ==== FUN_0042f6fc @ 0042f6fc

void __thiscall FUN_0042f6fc(void *this,int param_1,int param_2,int param_3,HDC param_4,int param_5)

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
    DAT_0048d67c = 0;
    FUN_0042f561(this,param_1,param_2,param_3,param_5);
    if (DAT_0048d67c != 0) {
      bVar7 = false;
      if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_0048d67c = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
             (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
            x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
            iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_0048d67c = 0;
      }
    }
  }
  return;
}


// ==== FUN_0042fb2a @ 0042fb2a

void __thiscall
FUN_0042fb2a(void *this,int param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,
            int param_7)

{
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)this != 0) {
    FUN_004300f3(this,param_1,param_2,param_3,&local_14);
    local_14 = local_14 + param_6;
    local_10 = local_10 + param_7;
    local_c = local_c + param_6;
    local_8 = local_8 + param_7;
    FUN_004273ff(&DAT_0048d0f0,param_1,param_2,&local_14,param_4,-1);
    FUN_0042f561(this,param_1,param_2,param_3,param_5);
  }
  return;
}


// ==== FUN_0042fbbf @ 0042fbbf

void __thiscall
FUN_0042fbbf(void *this,int param_1,int param_2,int param_3,HDC param_4,int *param_5,int param_6,
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
    DAT_0048d67c = 0;
    FUN_0042fb2a(this,param_1,param_2,param_3,param_5,param_6,param_7,param_8);
    if (DAT_0048d67c != 0) {
      bVar7 = false;
      if ((DAT_0048d694 == 0) && (DAT_0048d698 == 0)) {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
          iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
          iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
          iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
          pHVar8 = CreateCompatibleDC(param_4);
          pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
          BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                 0xcc0020);
          SelectObject(pHVar8,pvVar9);
          DeleteDC(pHVar8);
          GdiFlush();
        }
        DAT_0048d67c = 0;
      }
      else {
        for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
          if ((DAT_0048d694 <= *(int *)(&DAT_0048d53c + local_c * 0x10)) &&
             (DAT_0048d698 <= *(int *)(&DAT_0048d540 + local_c * 0x10))) {
            bVar7 = true;
            break;
          }
        }
        if (bVar7) {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            y = *(int *)(&DAT_0048d540 + local_c * 0x10) - DAT_0048d698;
            x = *(int *)(&DAT_0048d53c + local_c * 0x10) - DAT_0048d694;
            iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
            BitBlt(param_4,x,y,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        else {
          for (local_c = 0; local_c < DAT_0048d67c; local_c = local_c + 1) {
            iVar1 = *(int *)(&DAT_0048d548 + local_c * 0x10);
            iVar2 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar3 = *(int *)(&DAT_0048d544 + local_c * 0x10);
            iVar4 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            iVar5 = *(int *)(&DAT_0048d540 + local_c * 0x10);
            iVar6 = *(int *)(&DAT_0048d53c + local_c * 0x10);
            pHVar8 = CreateCompatibleDC(param_4);
            pvVar9 = SelectObject(pHVar8,DAT_0048d6a0);
            BitBlt(param_4,iVar6,iVar5,(iVar3 - iVar4) + 1,(iVar1 - iVar2) + 1,pHVar8,iVar6,iVar5,
                   0xcc0020);
            SelectObject(pHVar8,pvVar9);
            DeleteDC(pHVar8);
            GdiFlush();
          }
        }
        DAT_0048d67c = 0;
      }
    }
  }
  return;
}


// ==== FUN_0042fff9 @ 0042fff9

int __thiscall FUN_0042fff9(void *this,int param_1)

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


// ==== FUN_004300f3 @ 004300f3

undefined4 __thiscall FUN_004300f3(void *this,int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)this == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0042fff9(this,param_3);
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


// ==== FUN_00430195 @ 00430195

int __thiscall FUN_00430195(void *this,char param_1)

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


// ==== FUN_00430250 @ 00430250

void __cdecl FUN_00430250(int param_1,int param_2,short *param_3,short *param_4)

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
      uVar1 = FUN_0042d358(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_3 + local_1c * local_4c + local_20 + 4);
        local_44 = (char *)((int)param_4 + local_10 * local_2c + local_14 + 4);
        FUN_0042b930(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_004303bf @ 004303bf

void __cdecl FUN_004303bf(int param_1,int param_2,short *param_3,short *param_4)

{
  if ((param_3 != (short *)0x0) && (param_4 != (short *)0x0)) {
    FUN_0042b930((char *)((int)param_4 + param_1 + *param_4 * param_2 + 4),(char *)(param_3 + 2),
                 (int)*param_3,(int)param_3[1],(int)*param_4,(int)*param_3,0);
  }
  return;
}


// ==== FUN_0043045a @ 0043045a

void __cdecl FUN_0043045a(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_0042d60b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0042d61b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0042d358(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (char *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (char *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0042b930(local_44,local_50,local_48,local_28,local_2c,local_1c,0);
      }
    }
  }
  return;
}


// ==== FUN_004305e9 @ 004305e9

void __cdecl FUN_004305e9(int param_1,int param_2,int *param_3,short *param_4,short *param_5)

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
      local_38 = FUN_0042d60b(param_3);
      local_38 = param_1 + local_38;
      local_34 = FUN_0042d61b((int)param_3);
      local_34 = param_2 + local_34;
      local_64[0] = 0;
      local_64[1] = 0;
      local_64[2] = local_2c;
      local_58 = local_30;
      uVar1 = FUN_0042d358(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_4c * local_1c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0042b9ec(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_0043076a @ 0043076a

void __cdecl FUN_0043076a(int param_1,int param_2,int param_3,short *param_4,short *param_5)

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
      uVar1 = FUN_0042d358(&local_14,&local_40,local_64);
      if ((int)uVar1 != 0) {
        local_54 = local_14;
        local_18 = local_10;
        local_48 = local_c - local_14;
        local_28 = local_8 - local_10;
        local_20 = local_14 - param_1;
        local_4c = local_10 - param_2;
        local_50 = (undefined4 *)((int)param_4 + local_1c * local_4c + local_20 + 4);
        local_44 = (undefined4 *)((int)param_5 + local_10 * local_2c + local_14 + 4);
        FUN_0042b9ec(local_44,local_50,local_48,local_28,local_2c,local_1c);
      }
    }
  }
  return;
}


// ==== FUN_004308df @ 004308df

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_004308df(void *this,int param_1,int param_2)

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
      _DAT_00440268 = 0;
      DAT_00440268 = 0;
      uVar2 = DAT_00440268;
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


// ==== FUN_00430a76 @ 00430a76

bool __fastcall FUN_00430a76(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_00430ab0 @ 00430ab0

bool __fastcall FUN_00430ab0(int *param_1)

{
  param_1[1] = 0;
  return *param_1 != 0;
}


// ==== FUN_00430aea @ 00430aea

void __thiscall FUN_00430aea(void *this,int param_1)

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
        FUN_0042b778(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_0042919f(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
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
        FUN_0042b5c1(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(int *)this,0);
      }
      else {
        FUN_00427cf0(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                     *(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_00430d0a @ 00430d0a

void __thiscall FUN_00430d0a(void *this,int param_1,int param_2,int param_3)

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
        FUN_0042b778(&DAT_0048d0f0,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_0042919f(&DAT_0048d0f0,param_1,param_2,*(short **)this,0);
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
        FUN_0042b5c1(&DAT_0048d0f0,param_1,param_2,*(int *)this,0);
      }
      else {
        FUN_00427cf0(&DAT_0048d0f0,param_1,param_2,*(short **)this,0);
      }
    }
  }
  return;
}


// ==== FUN_00430ee2 @ 00430ee2

void __thiscall FUN_00430ee2(void *this,int *param_1,int param_2)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_2 != 0) {
    FUN_00427793(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),param_1,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_00430ffe:
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
    if (bVar1) goto LAB_00430ffe;
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
      goto LAB_004310b4;
    }
  }
  local_14 = 0;
LAB_004310b4:
  FUN_00427075(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),local_c,local_14,param_1,-1);
  return;
}


// ==== FUN_00431114 @ 00431114

void __thiscall FUN_00431114(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (param_4 != 0) {
    FUN_00427793(&DAT_0048d0f0,param_1,param_2,param_1,param_2,param_3,*(short **)this);
    return;
  }
  if (*(int *)this == 0) {
LAB_0043120c:
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
    if (bVar1) goto LAB_0043120c;
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
      goto LAB_004312c2;
    }
  }
  local_14 = 0;
LAB_004312c2:
  FUN_00427075(&DAT_0048d0f0,param_1,param_2,param_1,param_2,local_c,local_14,param_3,-1);
  return;
}


// ==== FUN_004312fe @ 004312fe

void __thiscall FUN_004312fe(void *this,int param_1)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_004313b8:
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
    if (bVar1) goto LAB_004313b8;
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
      goto LAB_0043146e;
    }
  }
  local_14 = 0;
LAB_0043146e:
  FUN_0042df38((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               *(int *)((int)this + 0x28) + local_c + -1,*(int *)((int)this + 0x2c) + local_14 + -1,
               0);
  FUN_00430aea(this,param_1);
  return;
}


// ==== FUN_004314bc @ 004314bc

void __thiscall FUN_004314bc(void *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  int local_14;
  int local_c;
  
  if (*(int *)this == 0) {
    return;
  }
  if (*(int *)this == 0) {
LAB_00431576:
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
    if (bVar1) goto LAB_00431576;
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
      goto LAB_0043162c;
    }
  }
  local_14 = 0;
LAB_0043162c:
  FUN_0042df38((void *)((int)this + 0x40),param_1,param_2,param_1 + local_c + -1,
               param_2 + local_14 + -1,0);
  FUN_00430d0a(this,param_1,param_2,param_3);
  return;
}


// ==== FUN_00431671 @ 00431671

void __thiscall FUN_00431671(void *this,int param_1)

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
      FUN_0042868e(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
      return;
    }
    FUN_004281cc(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                 *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                 (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                 (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_00431938:
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
    if (bVar1) goto LAB_00431938;
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
      goto LAB_00431a03;
    }
  }
  local_8 = 0;
LAB_00431a03:
  DAT_0048d6a8 = operator_new(local_8 * local_c + 4);
  if (DAT_0048d6a8 != (short *)0x0) {
    *DAT_0048d6a8 = (short)local_c;
    DAT_0048d6a8[1] = (short)local_8;
    _memset(DAT_0048d6a8 + 2,0,local_8 * local_c);
    if (param_1 == 0) {
      FUN_0042868e(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_0048d6a8,0);
    }
    else {
      FUN_004281cc(&DAT_0048d0f0,*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
                   *(int *)((int)this + 0x30),*(int *)((int)this + 0x34),
                   (*(int *)((int)this + 0x38) - *(int *)((int)this + 0x30)) + 1,
                   (*(int *)((int)this + 0x3c) - *(int *)((int)this + 0x34)) + 1,DAT_0048d6a8,0);
    }
    FUN_00432b10(DAT_0048d6a8);
  }
  DAT_0048d6a8 = (short *)0x0;
  return;
}


// ==== FUN_00431c02 @ 00431c02

void __thiscall FUN_00431c02(void *this,int param_1,int param_2,int *param_3,int param_4)

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
      FUN_0042868e(&DAT_0048d0f0,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,*(short **)this,0);
      return;
    }
    FUN_004281cc(&DAT_0048d0f0,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                 (param_3[3] - param_3[1]) + 1,*(short **)this,0);
    return;
  }
  if (*(int *)this == 0) {
LAB_00431e1b:
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
    if (bVar1) goto LAB_00431e1b;
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
      goto LAB_00431ed1;
    }
  }
  local_8 = 0;
LAB_00431ed1:
  DAT_0048d6a8 = operator_new(local_8 * local_c + 4);
  if (DAT_0048d6a8 != (short *)0x0) {
    *DAT_0048d6a8 = (short)local_c;
    DAT_0048d6a8[1] = (short)local_8;
    _memset(DAT_0048d6a8 + 2,0,local_8 * local_c);
    if (param_4 == 0) {
      FUN_0042868e(&DAT_0048d0f0,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_0048d6a8,0);
    }
    else {
      FUN_004281cc(&DAT_0048d0f0,param_1,param_2,*param_3,param_3[1],(param_3[2] - *param_3) + 1,
                   (param_3[3] - param_3[1]) + 1,DAT_0048d6a8,0);
    }
    FUN_00432b10(DAT_0048d6a8);
  }
  DAT_0048d6a8 = (short *)0x0;
  return;
}


// ==== FUN_0043204c @ 0043204c

void __thiscall FUN_0043204c(void *this,int param_1)

{
  FUN_0042df38((void *)((int)this + 0x40),*(int *)((int)this + 0x28),*(int *)((int)this + 0x2c),
               (*(int *)((int)this + 0x38) + *(int *)((int)this + 0x28)) -
               *(int *)((int)this + 0x30),
               (*(int *)((int)this + 0x3c) + *(int *)((int)this + 0x2c)) -
               *(int *)((int)this + 0x34),0);
  FUN_00431671(this,param_1);
  return;
}


// ==== FUN_004320b1 @ 004320b1

void __thiscall FUN_004320b1(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  FUN_0042df38((void *)((int)this + 0x40),param_1,param_2,(param_3[2] + param_1) - *param_3,
               (param_3[3] + param_2) - param_3[1],0);
  FUN_00431c02(this,param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00432120 @ 00432120

void FUN_00432120(void)

{
  HDC hdc;
  HPALETTE pHVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)DAT_00440272; local_8 = local_8 + 1) {
    (&DAT_00440274)[local_8 * 4] = 0;
    (&DAT_00440275)[local_8 * 4] = 0;
    (&DAT_00440276)[local_8 * 4] = 0;
    (&DAT_00440277)[local_8 * 4] = 4;
  }
  hdc = GetDC((HWND)0x0);
  pHVar1 = CreatePalette((LOGPALETTE *)&DAT_00440270);
  if (pHVar1 != (HPALETTE)0x0) {
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    RealizePalette(hdc);
    pHVar1 = SelectPalette(hdc,pHVar1,0);
    DeleteObject(pHVar1);
  }
  ReleaseDC((HWND)0x0,hdc);
  return;
}


// ==== FUN_004321f4 @ 004321f4

void __cdecl FUN_004321f4(int param_1,int *param_2)

{
  int iVar1;
  HDC hdc;
  int local_8;
  
  hdc = GetDC((HWND)0x0);
  GetSystemPaletteEntries(hdc,0,10,(LPPALETTEENTRY)&DAT_00440274);
  GetSystemPaletteEntries(hdc,0xf6,10,(LPPALETTEENTRY)&DAT_0044064c);
  ReleaseDC((HWND)0x0,hdc);
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_00440274)[local_8 * 4];
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_00440275)[local_8 * 4];
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_00440276)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_00440277)[local_8 * 4] = 0;
    *(undefined *)(param_1 + 0x3da + local_8 * 4) = (&DAT_0044064c)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d9 + local_8 * 4) = (&DAT_0044064d)[local_8 * 4];
    *(undefined *)(param_1 + 0x3d8 + local_8 * 4) = (&DAT_0044064e)[local_8 * 4];
    *(undefined1 *)(param_1 + 0x3db + local_8 * 4) = 0;
    (&DAT_0044064f)[local_8 * 4] = 0;
  }
  iVar1 = *param_2;
  for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
    (&DAT_00440274)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 2);
    *(undefined *)(param_1 + 2 + local_8 * 4) = (&DAT_00440274)[local_8 * 4];
    (&DAT_00440275)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1 + 1);
    *(undefined *)(param_1 + 1 + local_8 * 4) = (&DAT_00440275)[local_8 * 4];
    (&DAT_00440276)[local_8 * 4] = *(undefined1 *)((int)param_2 + local_8 * 4 + iVar1);
    *(undefined *)(param_1 + local_8 * 4) = (&DAT_00440276)[local_8 * 4];
    *(undefined1 *)(param_1 + 3 + local_8 * 4) = 0;
    (&DAT_00440277)[local_8 * 4] = 4;
  }
  CreatePalette((LOGPALETTE *)&DAT_00440270);
  return;
}


// ==== FUN_004323f0 @ 004323f0

void __cdecl FUN_004323f0(char param_1,int param_2)

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
  DAT_0048d6b0 = param_1;
  bVar1 = (&DAT_0048d138)[param_1 * 4];
  bVar2 = (&DAT_0048d139)[param_1 * 4];
  bVar3 = (&DAT_0048d13a)[param_1 * 4];
  for (local_30 = 0; local_30 < 0x100; local_30 = local_30 + 1) {
    uVar5 = ((uint)bVar1 * param_2 + (uint)(byte)(&DAT_0048d138)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar5) {
      uVar5 = 0xff;
    }
    uVar6 = (param_2 * (uint)bVar2 + (uint)(byte)(&DAT_0048d139)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar6) {
      uVar6 = 0xff;
    }
    uVar7 = (param_2 * (uint)bVar3 + (uint)(byte)(&DAT_0048d13a)[local_30 * 4] * iVar4) / 100;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    local_1c = 0;
    local_20 = 0xffffffff;
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      uVar8 = (uVar7 - (byte)(&DAT_0048d13a)[local_34 * 4]) *
              (uVar7 - (byte)(&DAT_0048d13a)[local_34 * 4]) +
              (uVar6 - (byte)(&DAT_0048d139)[local_34 * 4]) *
              (uVar6 - (byte)(&DAT_0048d139)[local_34 * 4]) +
              (uVar5 - (byte)(&DAT_0048d138)[local_34 * 4]) *
              (uVar5 - (byte)(&DAT_0048d138)[local_34 * 4]);
      if (uVar8 < local_20) {
        local_1c = local_34;
        local_20 = uVar8;
      }
    }
    (&DAT_0048d6b8)[local_30] = (undefined1)local_1c;
  }
  return;
}


// ==== FUN_0043260c @ 0043260c

void __cdecl FUN_0043260c(byte *param_1,int param_2)

{
  FUN_0042c2ee(0x48d6b8,param_1,param_2);
  return;
}


// ==== __onexit @ 00432640

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = __msize(DAT_0048ea2c);
  if (sVar1 < (uint)((int)DAT_0048ea28 + (4 - (int)DAT_0048ea2c))) {
    sVar1 = __msize(DAT_0048ea2c);
    pvVar2 = _realloc(DAT_0048ea2c,sVar1 + 0x10);
    if (pvVar2 == (void *)0x0) {
      return (_onexit_t)0x0;
    }
    DAT_0048ea28 = (undefined4 *)
                   (((int)DAT_0048ea28 - (int)DAT_0048ea2c & 0xfffffffcU) + (int)pvVar2);
    DAT_0048ea2c = pvVar2;
  }
  *DAT_0048ea28 = _Func;
  DAT_0048ea28 = DAT_0048ea28 + 1;
  return _Func;
}


// ==== _atexit @ 004326c0

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}


// ==== __global_unwind2 @ 00432718

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x432730,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0043275a

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
  puStack_18 = &LAB_00432738;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_004327ee();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


// ==== __abnormal_termination @ 004327c2

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
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_00432738) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}


// ==== FUN_004327e5 @ 004327e5

void __fastcall FUN_004327e5(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_0044067c = param_1;
  DAT_00440678 = in_EAX;
  DAT_00440680 = unaff_EBP;
  return;
}


// ==== FUN_004327ee @ 004327ee

void FUN_004327ee(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_0044067c = *(undefined4 *)(unaff_EBP + 8);
  DAT_00440678 = in_EAX;
  DAT_00440680 = unaff_EBP;
  return;
}


// ==== _JumpToContinuation @ 00432810

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0043283c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== _CallMemberFunction0 @ 00432850

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00432855. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00432860

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00432865. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 00432870

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00432875. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== _UnwindNestedFrames @ 00432880

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x4328ac,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}


// ==== ___CxxFrameHandler @ 004328e0

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


// ==== _CallCatchBlock2 @ 00432920

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
  local_10 = &LAB_00432990;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== _CallSETranslator @ 004329c0

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
  local_14 = 0x432a57;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  (*DAT_00440730)(*(undefined4 *)param_1,&local_34);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}


// ==== TranslatorGuardHandler @ 00432aa0

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
                    /* WARNING: Could not recover jumptable at 0x00432aff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// ==== FUN_00432b10 @ 00432b10

void __cdecl FUN_00432b10(void *param_1)

{
  _free(param_1);
  return;
}


// ==== `eh_vector_destructor_iterator' @ 00432b20

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
  puStack_c = &DAT_0043c018;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  local_8 = 0xffffffff;
  FUN_00432b90();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00432b90 @ 00432b90

void FUN_00432b90(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== __ArrayUnwind @ 00432bb0

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
  puStack_c = &DAT_0043c028;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== _memset @ 00432c50

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


// ==== `eh_vector_constructor_iterator' @ 00432cb0

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
  puStack_c = &DAT_0043c038;
  puStack_10 = &LAB_0043440c;
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
  FUN_00432d20();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_00432d20 @ 00432d20

void FUN_00432d20(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== FUN_00432d40 @ 00432d40

uint * __cdecl FUN_00432d40(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_00432e28;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00432e28:
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


// ==== FUN_00432d50 @ 00432d50

uint * __cdecl FUN_00432d50(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_00432d6c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_00432d9f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x00432dbb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_00432d6c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x00432dbb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x00432dbb;
    }
  }
LAB_00432d9f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x00432dbb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00432e28:
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
    if (bVar1 == 0) goto LAB_00432e28;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== FID_conflict:_memcpy @ 00432e30

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
switchD_00432ef9_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_00432ef9_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_00432ef9_caseD_3:
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
        goto switchD_00432ef9_caseD_1;
      case 2:
        goto switchD_00432ef9_caseD_2;
      case 3:
        goto switchD_00432ef9_caseD_3;
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
switchD_00432e60_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_00432e60_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_00432e60_caseD_3:
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
      goto switchD_00432e60_caseD_1;
    case 2:
      goto switchD_00432e60_caseD_2;
    case 3:
      goto switchD_00432e60_caseD_3;
    }
  }
  return _Dst;
}


// ==== _strcmp @ 00432f80

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
      if (bVar4 != *_Str2) goto LAB_00432fc4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00432f90;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00432fc4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_00432fc4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00432f90:
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
LAB_00432fc4:
  return (uint)bVar5 * -2 + 1;
}


// ==== FUN_00433010 @ 00433010

void __cdecl FUN_00433010(undefined4 param_1)

{
  DAT_00440690 = param_1;
  return;
}


// ==== _rand @ 00433020

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00440690 = DAT_00440690 * 0x343fd + 0x269ec3;
  return (DAT_00440690 & 0x7fff0000) >> 0x10;
}


// ==== _free @ 00433050

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
    HeapFree(DAT_0048ea24,0,_Memory);
  }
  return;
}


// ==== _malloc @ 004330a0

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00440f68);
  return pvVar1;
}


// ==== __nh_malloc @ 004330c0

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


// ==== __heap_alloc @ 00433110

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00440f64) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_0048ea24,0,dwBytes);
  return pvVar2;
}


// ==== __ftol @ 00433148

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== FUN_00433170 @ 00433170

void FUN_00433170(uint param_1,int param_2)

{
  __ctrandisp1(param_1,param_2);
  return;
}


// ==== FUN_0043317a @ 0043317a

void FUN_0043317a(void)

{
  uint in_stack_00000004;
  int in_stack_00000008;
  
  __ctrandisp1(in_stack_00000004,in_stack_00000008);
  return;
}


// ==== __fpmath @ 004331a0

/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_004331d0();
  DAT_004406ac = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


// ==== FUN_004331d0 @ 004331d0

void FUN_004331d0(void)

{
  PTR_FUN_00440ff4 = &LAB_00435120;
  PTR_FUN_00440ff8 = &LAB_004351a0;
  PTR_FUN_00440ffc = &LAB_004350b0;
  PTR_FUN_00441000 = &LAB_00435180;
  PTR_FUN_00440ff0 = &LAB_00435540;
  PTR_FUN_00441004 = &LAB_00435540;
  return;
}


// ==== operator_new @ 00433210

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}


// ==== _strlen @ 00433220

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
    if (((uint)puVar2 & 3) == 0) goto LAB_00433240;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00433273:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00433240:
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
  goto LAB_00433273;
}


// ==== _strncmp @ 004332a0

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


// ==== _sprintf @ 004332e0

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


// ==== entry @ 00433350

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
  puStack_c = &DAT_0043c048;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_004406ec = DVar2 >> 8 & 0xff;
  DAT_004406e0 = DVar2 >> 0x10;
  _DAT_004406e8 = DVar2 & 0xff;
  _DAT_004406e4 = _DAT_004406e8 * 0x100 + _DAT_004406ec;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_0048ea30 = (byte *)GetCommandLineA();
  DAT_004406c0 = ___crtGetEnvironmentStringsA();
  if ((DAT_004406c0 == (LPVOID)0x0) || (DAT_0048ea30 == (byte *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_0048ea30;
  pbVar5 = DAT_0048ea30;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_0048ea30 + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar5);
        if (iVar3 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_00433455;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_00433455:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  _Code = FUN_0040a6cf(pHVar4);
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== __amsg_exit @ 004334f0

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_004406cc == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_004406c8)(0xff);
  return;
}


// ==== __cinit @ 00433520

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (PTR___fpmath_004406b0 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_004406b0)();
  }
  __initterm((undefined4 *)&DAT_0043d068,(undefined4 *)&DAT_0043d074);
  iVar1 = __initterm((undefined4 *)&DAT_0043d000,(undefined4 *)&DAT_0043d064);
  return iVar1;
}


// ==== _exit @ 00433550

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 00433570

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== doexit @ 00433590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0044071c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00440718 = 1;
  DAT_00440714 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0048ea2c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0048ea28 + -4), DAT_0048ea2c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0048ea2c <= puVar1);
    }
    __initterm((undefined4 *)&DAT_0043d078,(undefined4 *)&DAT_0043d080);
  }
  __initterm((undefined4 *)&DAT_0043d084,(undefined4 *)&DAT_0043d088);
  if (param_3 == 0) {
    DAT_0044071c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


// ==== __initterm @ 00433640

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


// ==== _realloc @ 00433660

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
          local_c = HeapReAlloc(DAT_0048ea24,0,_Memory,_NewSize);
        }
        else {
          if (_NewSize < DAT_00440f64) {
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
          local_c = HeapAlloc(DAT_0048ea24,0,_NewSize);
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
      if ((local_c != (undefined4 *)0x0) || (DAT_00440f68 == 0)) {
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


// ==== __msize @ 00433810

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
  SVar2 = HeapSize(DAT_0048ea24,0,_Memory);
  return SVar2;
}


// ==== ___InternalCxxFrameHandler @ 00433860

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


// ==== FindHandler @ 00433920

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
  pEVar4 = DAT_00440724;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_00440724 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_00440724;
    param_3 = DAT_00440728;
    iVar5 = _ValidateRead(DAT_00440724,1);
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
LAB_00433ad6:
                bVar12 = true;
              }
              else {
                if (*(int *)(pbVar3 + 4) == iVar10) {
LAB_00433aae:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_00433ad6;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00433aa5:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_00433aaa;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00433aa5;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_00433aaa:
                  if (iVar10 == 0) goto LAB_00433aae;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_00433b34;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_00433b34:
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


// ==== FindHandlerForForeignException @ 00433bc0

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
  
  if (((DAT_00440730 == 0) ||
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


// ==== GetRangeOfTrysToCheck @ 00433ca0

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


// ==== ___FrameUnwindToState @ 00433d40

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
  puStack_c = &DAT_0043c058;
  puStack_10 = &LAB_0043440c;
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


// ==== CatchIt @ 00433e30

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


// ==== CallCatchBlock @ 00433ed0

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
  puStack_c = &DAT_0043c068;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &local_14;
  DAT_00440724 = param_1;
  DAT_00440728 = param_3;
  local_8 = 1;
  pvVar1 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00433f95();
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}


// ==== FUN_00433f95 @ 00433f95

void FUN_00433f95(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  **(undefined4 **)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
  DAT_00440724 = *(undefined4 *)(unaff_EBP + -0x28);
  DAT_00440728 = *(undefined4 *)(unaff_EBP + -0x24);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     (*(int *)(unaff_EBP + -0x1c) != 0)) {
    iVar2 = __abnormal_termination();
    DestructExceptionObject(*(EHExceptionRecord **)(unaff_EBP + 8),(uchar)iVar2);
  }
  return;
}


// ==== BuildCatchObject @ 00434010

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
  puStack_c = &DAT_0043c080;
  puStack_10 = &LAB_0043440c;
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
            goto LAB_004341fe;
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
            goto LAB_004341fe;
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
          goto LAB_004341fe;
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
        goto LAB_004341fe;
      }
    }
    _inconsistency();
  }
LAB_004341fe:
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== DestructExceptionObject @ 00434210

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
  puStack_c = &DAT_0043c090;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== AdjustPointer @ 00434290

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


// ==== __CallSettingFrame@12 @ 004342c0

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_004327e5(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_004327e5(param_3);
  return;
}


// ==== terminate @ 00434310

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
  puStack_c = &DAT_0043c0a0;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_00440734 != (code *)0x0) {
    local_8 = 1;
    (*DAT_00440734)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 00434390

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
  puStack_c = &DAT_0043c0b8;
  puStack_10 = &LAB_0043440c;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_terminate_0044073c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_terminate_0044073c)();
  }
  local_8 = 0xffffffff;
  terminate();
  *unaff_FS_OFFSET = local_14;
  return;
}


// ==== FUN_004344c9 @ 004344c9

void FUN_004344c9(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}


// ==== __heap_init @ 004344f0

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_0048ea24 = HeapCreate(1,0x1000,0);
  if (DAT_0048ea24 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0048ea24);
    return 0;
  }
  return 1;
}


// ==== ___sbh_new_region @ 00434530

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
  
  if (DAT_00440f58 == 0) {
    lpMem = &PTR_LOOP_00440748;
  }
  else {
    lpMem = HeapAlloc(DAT_0048ea24,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00440748) {
        if (PTR_LOOP_00440748 == (undefined *)0x0) {
          PTR_LOOP_00440748 = (undefined *)&PTR_LOOP_00440748;
        }
        if (PTR_LOOP_0044074c == (undefined *)0x0) {
          PTR_LOOP_0044074c = (undefined *)&PTR_LOOP_00440748;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00440748;
        lpMem[1] = PTR_LOOP_0044074c;
        PTR_LOOP_0044074c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00440748) {
    HeapFree(DAT_0048ea24,0,lpMem);
  }
  return (undefined **)0x0;
}


// ==== ___sbh_release_region @ 004346a0

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00440f5c == param_1) {
    PTR_LOOP_00440f5c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00440748) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0048ea24,0,param_1);
    return;
  }
  DAT_00440f58 = 0;
  return;
}


// ==== ___sbh_decommit_pages @ 00434700

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
  
  ppuVar4 = (undefined **)PTR_LOOP_0044074c;
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
            DAT_00440f60 = DAT_00440f60 + -1;
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
    if ((ppuVar5 == (undefined **)PTR_LOOP_0044074c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}


// ==== ___sbh_find_block @ 004347e0

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Release */

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00440748;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00440748) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}


// ==== ___sbh_free_block @ 00434840

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
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00440f60 = DAT_00440f60 + 1, DAT_00440f60 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


// ==== ___sbh_alloc_block @ 00434890

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
  
  piVar12 = (int *)PTR_LOOP_00440f5c;
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
              PTR_LOOP_00440f5c = (undefined *)piVar12;
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
              PTR_LOOP_00440f5c = (undefined *)piVar12;
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
  } while ((int *)PTR_LOOP_00440f5c != piVar12);
  ppuVar11 = &PTR_LOOP_00440748;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00440748) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00440f5c = (undefined *)ppuVar11;
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
  PTR_LOOP_00440f5c = (undefined *)ppuVar11;
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


// ==== ___sbh_alloc_block_from_page @ 00434b10

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


// ==== ___sbh_resize_block @ 00434c90

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


// ==== __callnewh @ 00434d60

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_0048d7b8 != (code *)0x0) {
    iVar1 = (*DAT_0048d7b8)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== __cintrindisp2 @ 00434dc0

/* Library Function - Single Match
    __cintrindisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __cintrindisp2(undefined4 param_1,int param_2)

{
  __trandisp2(param_1,param_2);
  DAT_0048d7c8 = 1;
  FUN_00434e75();
  return;
}


// ==== __cintrindisp1 @ 00434dfe

/* Library Function - Single Match
    __cintrindisp1
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __fastcall __cintrindisp1(undefined4 param_1,int param_2)

{
  __trandisp1(param_1,param_2);
  DAT_0048d7c8 = 1;
  FUN_00434e75();
  return;
}


// ==== __ctrandisp2 @ 00434e34

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
  FUN_00434e6e();
  return;
}


// ==== FUN_00434e6e @ 00434e6e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434e6e(void)

{
  char cVar1;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  DAT_0048d7c8 = '\0';
  if (DAT_004406a8 != 0) {
    DAT_0048d7c8 = 0;
    return;
  }
  _DAT_0048d7c0 = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        DAT_0048d7c8 = 0;
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_00434f43;
    }
    if (((ulonglong)_DAT_0048d7c0 & 0x7ff0000000000000) == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_0043c0e8);
      if (ABS(in_ST0) < (float10)_DAT_0043c0d8) {
        in_ST0 = in_ST0 * (float10)_DAT_0043c0f8;
      }
      goto LAB_00434f43;
    }
    if ((DAT_0048d7c6 & 0x7ff0) == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_0043c0e0);
      if ((float10)_DAT_0043c0d0 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_0043c0f0;
      }
      goto LAB_00434f43;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    DAT_0048d7c8 = 0;
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    DAT_0048d7c8 = 0;
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_00434f43:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if (DAT_0048d7c8 == '\0') {
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


// ==== FUN_00434e75 @ 00434e75

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434e75(void)

{
  char cVar1;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  if (DAT_004406a8 != 0) {
    return;
  }
  _DAT_0048d7c0 = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_00434f43;
    }
    if (((ulonglong)_DAT_0048d7c0 & 0x7ff0000000000000) == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_0043c0e8);
      if (ABS(in_ST0) < (float10)_DAT_0043c0d8) {
        in_ST0 = in_ST0 * (float10)_DAT_0043c0f8;
      }
      goto LAB_00434f43;
    }
    if ((DAT_0048d7c6 & 0x7ff0) == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_0043c0e0);
      if ((float10)_DAT_0043c0d0 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_0043c0f0;
      }
      goto LAB_00434f43;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_00434f43:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if (DAT_0048d7c8 == '\0') {
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


// ==== __ctrandisp1 @ 00434fa5

/* Library Function - Single Match
    __ctrandisp1
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2019 */

void __cdecl __ctrandisp1(uint param_1,int param_2)

{
  undefined4 extraout_ECX;
  int extraout_EDX;
  
  __fload(param_1,param_2);
  __trandisp1(extraout_ECX,extraout_EDX);
  FUN_00434e6e();
  return;
}


// ==== __fload @ 00434fd1

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


// ==== __setdefaultprecision @ 00435010

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 00435030

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 00435080

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


// ==== __cftoe @ 004351f0

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
  
  _Digits = DAT_0048d7cc;
  if (DAT_00441008 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (uint)(*_Digits == 0x2d) + (uint)(0 < (int)_SizeInBytes),_SizeInBytes + 1,
              (int)_Digits,unaff_EBP);
  }
  else {
    __shift(_Buf + (*DAT_0048d7cc == 0x2d),(uint)(0 < (int)_SizeInBytes));
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
    *pcVar2 = DAT_00441498;
  }
  bVar4 = DAT_00441008 == '\0';
  *(undefined4 *)(pcVar2 + _SizeInBytes + bVar4) = DAT_0043c148;
  *(undefined2 *)(pcVar2 + _SizeInBytes + bVar4 + 4) = DAT_0043c14c;
  pcVar2 = pcVar2 + (DAT_00441008 == '\0') + _SizeInBytes;
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


// ==== __cftof @ 00435330

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
  
  _Digits = DAT_0048d7cc;
  if (DAT_00441008 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (*_Digits == 0x2d),_Digits[1] + _SizeInBytes,(int)_Digits,unaff_EBP);
  }
  else if (DAT_0044100c == _SizeInBytes) {
    iVar1 = DAT_0044100c + (*DAT_0048d7cc == 0x2d);
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
    *pcVar4 = DAT_00441498;
    iVar1 = _Digits[1];
    if (iVar1 < 0) {
      if (DAT_00441008 == '\0') {
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


// ==== __cftog @ 00435430

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
  
  DAT_0048d7cc = (int *)__fltout();
  DAT_0044100c = DAT_0048d7cc[1] + -1;
  iVar1 = *DAT_0048d7cc;
  __fptostr(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_0048d7cc,unaff_EBP);
  DAT_00441010 = DAT_0044100c < DAT_0048d7cc[1] + -1;
  iVar3 = DAT_0048d7cc[1] + -1;
  if ((-5 < iVar3) && (iVar3 < (int)param_3)) {
    bVar5 = DAT_0044100c < DAT_0048d7cc[1] + -1;
    pcVar2 = param_2 + (iVar1 == 0x2d);
    DAT_0044100c = iVar3;
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
  DAT_0044100c = iVar3;
  __cftoe_g(param_1,param_2,param_3,param_4);
  return;
}


// ==== __cftoe_g @ 004354e0

/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftoe_g(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int unaff_retaddr;
  
  DAT_00441008 = 1;
  __cftoe(param_1,param_2,param_3,param_4,unaff_retaddr);
  DAT_00441008 = 0;
  return;
}


// ==== __cftof_g @ 00435510

/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftof_g(double *param_1,char *param_2,size_t param_3)

{
  int unaff_retaddr;
  
  DAT_00441008 = 1;
  __cftof(param_1,param_2,param_3,unaff_retaddr);
  DAT_00441008 = 0;
  return;
}


// ==== __shift @ 004355b0

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


// ==== __flsbuf @ 004355e0

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
    if ((_File == (FILE *)&DAT_00441700) || (_File == (FILE *)&DAT_00441720)) {
      iVar1 = __isatty(_FileHandle);
      if (iVar1 != 0) goto LAB_00435664;
    }
    __getbuf(_File_00);
  }
LAB_00435664:
  if ((_File_00->_flag & 0x108U) == 0) {
    uVar3 = 1;
    uVar4 = __write(_FileHandle,&_Ch,1);
  }
  else {
    uVar3 = (int)_File_00->_ptr - (int)_File_00->_base;
    _File_00->_ptr = _File_00->_base + 1;
    _File_00->_cnt = _File_00->_bufsiz + -1;
    if ((int)uVar3 < 1) {
      puVar2 = &DAT_004412d0;
      if (_FileHandle != 0xffffffff) {
        puVar2 = (undefined *)
                 (*(int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7) >> 3)) +
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


// ==== __output @ 00435730

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
      uVar4 = *(byte *)((int)&DAT_0043c148 + (int)(char)bVar10) & 0xf;
    }
    local_21c = (int)((char)(&DAT_0043c168)[uVar4 * 8 + local_21c] >> 4);
    switch(local_21c) {
    case 0:
switchD_004357b5_caseD_0:
      local_220 = 0;
      if ((PTR_DAT_004414a0[(uint)bVar10 * 2 + 1] & 0x80) != 0) {
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
          goto switchD_004357b5_caseD_0;
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
        (*(code *)PTR_FUN_00440ff0)(&local_208,&local_200,(int)(char)bVar10,puVar5,local_20c);
        if ((((uint)puVar14 & 0x80) != 0) && (puVar5 == (undefined1 *)0x0)) {
          (*(code *)PTR_FUN_00440ffc)(&local_200);
        }
        if ((bVar10 == 0x67) && (((uint)puVar14 & 0x80) == 0)) {
          (*(code *)PTR_FUN_00440ff4)(&local_200);
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
            local_240 = (wchar_t *)PTR_DAT_00441014;
            pwVar12 = (wchar_t *)PTR_DAT_00441014;
          }
          for (; (puVar11 != (undefined1 *)0x0 && (puVar11 = puVar11 + -1, (char)*pwVar12 != '\0'));
              pwVar12 = (wchar_t *)((int)pwVar12 + 1)) {
          }
          puVar11 = (undefined1 *)((int)pwVar12 - (int)local_240);
          pwVar12 = local_240;
        }
        else {
          if (local_240 == (wchar_t *)0x0) {
            local_240 = (wchar_t *)PTR_DAT_00441018;
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
          local_240 = (wchar_t *)PTR_DAT_00441014;
          pcVar15 = PTR_DAT_00441014;
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
        goto LAB_00435b97;
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
        goto LAB_00435b97;
      case 0x70:
        puVar5 = (undefined1 *)0x8;
      case 0x58:
        local_214 = 7;
        goto LAB_00435b70;
      case 0x75:
        local_218 = 10;
        goto LAB_00435b97;
      case 0x78:
        local_214 = 0x27;
LAB_00435b70:
        local_218 = 0x10;
        puVar13 = puVar5;
        if (((uint)puVar14 & 0x80) != 0) {
          local_246 = '0';
          local_224 = 2;
          local_245 = (char)local_214 + 'Q';
        }
LAB_00435b97:
        if (((uint)puVar14 & 0x8000) == 0) {
          if (((uint)puVar14 & 0x20) == 0) {
            if (((uint)puVar14 & 0x40) == 0) {
              uVar4 = get_int_arg((int *)&param_3);
              goto LAB_00435c36;
            }
            iVar9 = get_int_arg((int *)&param_3);
            local_23c = (ulonglong)iVar9;
          }
          else if (((uint)puVar14 & 0x40) == 0) {
            uVar4 = get_int_arg((int *)&param_3);
            uVar4 = uVar4 & 0xffff;
LAB_00435c36:
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
              if (((uint)puVar14 & 2) == 0) goto LAB_00435ea9;
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
LAB_00435ea9:
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


// ==== write_char @ 004360e0

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


// ==== write_multi_char @ 00436130

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


// ==== write_string @ 00436170

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


// ==== get_int_arg @ 004361b0

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


// ==== get_int64_arg @ 004361c0

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


// ==== get_short_arg @ 004361e0

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


// ==== __ismbblead @ 00436380

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}


// ==== x_ismbbtype @ 004363a0

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_004410b8 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_004414aa + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __setenvp @ 004363e0

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
  cVar1 = *DAT_004406c0;
  pcVar7 = DAT_004406c0;
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
  _DAT_004406fc = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_004406c0;
  pcVar7 = DAT_004406c0;
  do {
    if (cVar1 == '\0') {
      _free(DAT_004406c0);
      DAT_004406c0 = (char *)0x0;
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


// ==== __setargv @ 004364d0

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_0048d7d0,0x104);
  _DAT_0044070c = &DAT_0048d7d0;
  pbVar2 = &DAT_0048d7d0;
  if (*DAT_0048ea30 != 0) {
    pbVar2 = DAT_0048ea30;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_004406f4 = puVar1;
  _DAT_004406f0 = local_8 + -1;
  return local_8 + -1;
}


// ==== parse_cmdline @ 00436570

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
      if (((*(byte *)((int)&DAT_004410b8 + *pbVar6 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_004410b8 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_004365e0;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_004365e0:
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
          if ((*(byte *)((int)&DAT_004410b8 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00436711;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_004410b8 + bVar1 + 1) & 4) != 0) {
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
LAB_00436711:
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


// ==== ___crtGetEnvironmentStringsA @ 00436750

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
  if (DAT_004410b0 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_004410b0 = 2;
    }
    else {
      DAT_004410b0 = 1;
    }
  }
  if (DAT_004410b0 != 1) {
    if (DAT_004410b0 != 2) {
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


// ==== __setmbcp @ 004368e0

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
  if (CodePage == DAT_004411bc) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_004411e0;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_004410b8;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_004411f0 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_004411d8)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_004410b8 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_004411bc = CodePage;
      _DAT_004411c0 = _CPtoLCID(CodePage);
      DAT_004411c8 = *(undefined4 *)(&DAT_004411e4 + local_18 * 0x30);
      DAT_004411cc = *(undefined4 *)(&DAT_004411e8 + local_18 * 0x30);
      DAT_004411d0 = *(undefined4 *)(local_18 * 0x30 + 0x4411ec);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_004412d0);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_004410b8;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_004411c0 = 0;
      DAT_004411bc = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_004410b8 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_004410b8 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_004411bc = CodePage;
      _DAT_004411c0 = _CPtoLCID(CodePage);
    }
    DAT_004411c8 = 0;
    DAT_004411cc = 0;
    DAT_004411d0 = 0;
    return 0;
  }
  if (DAT_004411d4 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}


// ==== getSystemCP @ 00436ac0

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_004411d4 = 1;
                    /* WARNING: Could not recover jumptable at 0x00436add. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_004411d4 = 1;
                    /* WARNING: Could not recover jumptable at 0x00436af2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00441988;
  }
  DAT_004411d4 = (uint)bVar2;
  return param_1;
}


// ==== _CPtoLCID @ 00436b10

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


// ==== setSBCS @ 00436b70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004410b8;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_004411c8 = 0;
  DAT_004411bc = 0;
  _DAT_004411c0 = 0;
  DAT_004411cc = 0;
  DAT_004411d0 = 0;
  return;
}


// ==== ___initmbctable @ 00436ba0

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Release */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}


// ==== __ioinit @ 00436bb0

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
  DAT_0048ea20 = 0x20;
  DAT_0048e920 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_0048e920 + 0x40);
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
    if ((int)DAT_0048ea20 < (int)UVar7) {
      piVar4 = &DAT_0048e924;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_0048ea20;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_0048ea20 = DAT_0048ea20 + 0x20;
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
      } while ((int)DAT_0048ea20 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_0048e920 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
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
    piVar4 = DAT_0048e920 + iVar9 * 2;
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
  UVar7 = SetHandleCount(DAT_0048ea20);
  return UVar7;
}


// ==== __FF_MSGBANNER @ 00436d90

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_004406cc == 1) || ((DAT_004406cc == 0 && (DAT_004406d0 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00441368 != (code *)0x0) {
      (*DAT_00441368)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


// ==== __NMSG_WRITE @ 00436dd0

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
  piVar2 = &DAT_004412d8;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00441368);
  if ((&DAT_004412d8)[iVar4 * 2] == param_1) {
    if ((DAT_004406cc == 1) || ((DAT_004406cc == 0 && (DAT_004406d0 == 1)))) {
      if ((DAT_0048e920 == 0) ||
         (hFile = *(HANDLE *)(DAT_0048e920 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x4412dc);
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
      pcVar8 = *(char **)(iVar4 * 8 + 0x4412dc);
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


// ==== FUN_00437000 @ 00437000

int FUN_00437000(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    terminate();
    return 1;
  }
  if (DAT_0048d8d4 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_0048d8d4);
    if (iVar2 != 0) {
      iVar2 = (*DAT_0048d8d4)(param_1);
      return iVar2;
    }
  }
  return 0;
}


// ==== FUN_00437060 @ 00437060

void FUN_00437060(void)

{
  SetUnhandledExceptionFilter(DAT_0048d8d4);
  return;
}


// ==== _ValidateRead @ 00437070

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 00437090

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


// ==== _ValidateExecute @ 004370b0

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== _abort @ 004370d0

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


// ==== __trandisp1 @ 004370f0

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
                    /* WARNING: Could not recover jumptable at 0x00437155. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)(&DAT_0044138d)[(byte)((bVar2 & 7) << 1 | (char)bVar2 < '\0')] + 0x10
              ))();
  return;
}


// ==== __trandisp2 @ 00437157

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
                    /* WARNING: Could not recover jumptable at 0x004371e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + (char)((&DAT_0044138d)[(byte)(cVar2 << 1 | cVar2 < '\0') & 0xf] |
                               (&DAT_0044138d)[(byte)((bVar3 & 7) << 1 | (char)bVar3 < '\0')] << 2)
              + 0x10))();
  return;
}


// ==== FUN_0043741e @ 0043741e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined5 __fastcall FUN_0043741e(undefined4 param_1,undefined1 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  float10 in_ST0;
  float10 fVar1;
  float10 fVar2;
  undefined4 unaff_retaddr;
  
  fVar1 = ABS(in_ST0);
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)(_DAT_004413be < fVar1) << 8 | (ushort)(NAN(_DAT_004413be) || NAN(fVar1)) << 10 |
       (ushort)(_DAT_004413be == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0x9f) & 0x41) == 0) {
    fVar2 = ROUND(in_ST0);
    fVar1 = (float10)0;
    *(ushort *)(unaff_EBP + -0xa0) =
         (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
         (ushort)(fVar2 == fVar1) << 0xe;
    fVar2 = in_ST0 - fVar2;
    fVar1 = (float10)0;
    *(ushort *)(unaff_EBP + -0xa0) =
         (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
         (ushort)(fVar2 == fVar1) << 0xe;
    f2xm1(ABS(fVar2));
    return CONCAT14(*(undefined1 *)(unaff_EBP + -0x9f),in_EAX);
  }
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)(in_ST0 < fVar1) << 8 | (ushort)(NAN(in_ST0) || NAN(fVar1)) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0x9f) & 1) == 0) {
    return CONCAT14(param_2,unaff_retaddr);
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 4;
  return CONCAT14(param_2,unaff_retaddr);
}


// ==== FUN_00437461 @ 00437461

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00437461(void)

{
  undefined4 uVar1;
  float10 in_ST0;
  
  if (ROUND(in_ST0) == in_ST0) {
    if (ROUND(in_ST0 * (float10)_DAT_004413d2) == in_ST0 * (float10)_DAT_004413d2) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== __87except @ 004374d0

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
  if ((*param_2 != 8) && (DAT_00441bf8 == 0)) {
    iVar2 = FUN_0043a040();
  }
  if (iVar2 == 0) {
    __set_errno(*param_2);
  }
  return;
}


// ==== __control87 @ 004375f0

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


// ==== __controlfp @ 00437640

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== __abstract_cw @ 00437660

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


// ==== __hw_cw @ 00437710

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}


// ==== FUN_004377a0 @ 004377a0

void FUN_004377a0(void)

{
  __amsg_exit(2);
  return;
}


// ==== __isctype @ 004377b0

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
    return (uint)*(ushort *)(PTR_DAT_004414a0 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_004414a0[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
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


// ==== FID_conflict:_tolower @ 00437850

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
  
  if (DAT_00441978 == (_locale_t)0x0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      _C = _C + 0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_00441494 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_004414a0 + _C * 2) & 1;
    }
    else {
      uVar1 = __isctype(_C,1);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_004414a0[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_00441978,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


// ==== __ZeroTail @ 00437940

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


// ==== __IncMan @ 004379b0

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


// ==== __RoundMan @ 00437a20

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


// ==== __CopyMan @ 00437ad0

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


// ==== __FillZeroMan @ 00437af0

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


// ==== __IsZeroMan @ 00437b00

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


// ==== __ShrMan @ 00437b20

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


// ==== __ld12cvt @ 00437bd0

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


// ==== FID_conflict:__ld12tod @ 00437da0

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_004416b0);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 00437dc0

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_004416c8);
  return IVar1;
}


// ==== FID_conflict:__atodbl @ 00437de0

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


// ==== FID_conflict:__atodbl @ 00437e20

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


// ==== __fptostr @ 00437e60

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


// ==== __fltout @ 00437ef0

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
  _DAT_0048d900 = _I10_OUTPUT(local_c,local_8,local_4,0x11,0,&DAT_0048d8d8);
  _DAT_0048d904 = &DAT_0048d8dc;
  _DAT_0048d8f8 = (int)DAT_0048d8da;
  _DAT_0048d8fc = (int)DAT_0048d8d8;
  return &DAT_0048d8f8;
}


// ==== ___dtold @ 00437f60

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


// ==== __write @ 00438020

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
  
  if ((uint)_FileHandle < DAT_0048ea20) {
    local_410 = (int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
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
LAB_00438165:
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
          if (BVar3 == 0) goto LAB_00438165;
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
        _DAT_004406d4 = 0x1c;
        _DAT_004406d8 = 0;
        return -1;
      }
      if (local_418 != 5) {
        __dosmaperr(local_418);
        return -1;
      }
      _DAT_004406d4 = 9;
      _DAT_004406d8 = local_418;
      return -1;
    }
  }
  _DAT_004406d4 = 9;
  _DAT_004406d8 = 0;
  return -1;
}


// ==== __lseek @ 00438250

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
  
  if ((uint)_FileHandle < DAT_0048ea20) {
    piVar1 = (int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
    iVar2 = (_FileHandle & 0x1fU) * 8;
    if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) != 0) {
      hFile = (HANDLE)__get_osfhandle(_FileHandle);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_004406d4 = 9;
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
  _DAT_004406d4 = 9;
  _DAT_004406d8 = 0;
  return -1;
}


// ==== __getbuf @ 00438310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_00441960 = _DAT_00441960 + 1;
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


// ==== __isatty @ 00438360

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Release */

int __cdecl __isatty(int _FileHandle)

{
  if (DAT_0048ea20 <= (uint)_FileHandle) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                  (_FileHandle & 0x1fU) * 8) & 0x40;
}


// ==== _wctomb @ 00438480

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
  if (DAT_00441978 == 0) {
    if (0xff < (ushort)_WCh) {
      _DAT_004406d4 = 0x2a;
      return -1;
    }
    *_MbCh = (char)_WCh;
    return 1;
  }
  local_4 = 0;
  iVar1 = WideCharToMultiByte(DAT_00441988,0x220,&_WCh,1,_MbCh,DAT_00441494,(LPCSTR)0x0,&local_4);
  if ((iVar1 == 0) || (local_4 != 0)) {
    _DAT_004406d4 = 0x2a;
    iVar1 = -1;
  }
  return iVar1;
}


// ==== __aulldiv @ 00438520

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


// ==== __aullrem @ 00438590

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


// ==== ___crtMessageBoxA @ 00438610

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0044198c != (FARPROC)0x0) {
LAB_0043865f:
    if (DAT_00441990 != (FARPROC)0x0) {
      iVar1 = (*DAT_00441990)();
    }
    if ((iVar1 != 0) && (DAT_00441994 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00441994)(iVar1);
    }
    iVar1 = (*DAT_0044198c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0044198c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0044198c != (FARPROC)0x0) {
      DAT_00441990 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00441994 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0043865f;
    }
  }
  return 0;
}


// ==== _strncpy @ 004386b0

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
        goto joined_r0x004386ee;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_0043872b;
        goto LAB_00438799;
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
joined_r0x00438795:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00438799:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_0043872b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00438795;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00438795;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00438795;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x004386ee:
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
LAB_0043872b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _raise @ 004387b0

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
    puVar6 = &DAT_004419a0;
    pcVar7 = DAT_004419a0;
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
    puVar6 = &DAT_004419ac;
    pcVar7 = DAT_004419ac;
    break;
  case 0x15:
    puVar6 = &DAT_004419a4;
    pcVar7 = DAT_004419a4;
    break;
  case 0x16:
    puVar6 = &DAT_004419a8;
    pcVar7 = DAT_004419a8;
  }
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
    __exit(3);
  }
  uVar2 = DAT_004410a8;
  uVar1 = DAT_004410a4;
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_004410a8 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_004410a4 = 0x8c;
      local_4 = uVar1;
      goto LAB_0043887c;
    }
  }
  else {
LAB_0043887c:
    if (_SigNum == 8) {
      if (DAT_00441098 < DAT_0044109c + DAT_00441098) {
        puVar6 = (undefined4 *)(DAT_00441098 * 0xc + 0x441028);
        iVar4 = DAT_0044109c;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_004388bd;
    }
  }
  *puVar6 = 0;
LAB_004388bd:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_004410a4);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_004410a4 = local_4;
  }
  DAT_004410a8 = uVar5;
  return 0;
}


// ==== siglookup @ 00438940

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_00441020;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_00441020 + DAT_004410a0 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


// ==== FUN_00438980 @ 00438980

undefined4 __cdecl
FUN_00438980(int param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  double dVar1;
  int iVar2;
  undefined8 local_8;
  
  dVar1 = ABS((double)CONCAT44(param_2,param_1));
  if ((param_4 == 0x7ff00000) && (param_3 == 0)) {
    if (1.0 < dVar1) {
      param_5[1] = DAT_00441d9c;
      *param_5 = DAT_00441d98;
      return 0;
    }
    if (dVar1 < 1.0) {
      *param_5 = 0;
      param_5[1] = 0;
      return 0;
    }
    param_5[1] = DAT_00441da4;
    *param_5 = DAT_00441da0;
    return 1;
  }
  if ((param_4 == 0xfff00000) && (param_3 == 0)) {
    if (1.0 < dVar1) {
      *param_5 = 0;
      param_5[1] = 0;
      return 0;
    }
    if (dVar1 < 1.0) {
      param_5[1] = DAT_00441d9c;
      *param_5 = DAT_00441d98;
      return 0;
    }
    param_5[1] = DAT_00441da4;
    *param_5 = DAT_00441da0;
    return 1;
  }
  if ((param_2 != 0x7ff00000) || (param_1 != 0)) {
    if ((param_2 == -0x100000) && (param_1 == 0)) {
      iVar2 = FUN_00438bd0(param_3,param_4);
      if (0.0 < (double)CONCAT44(param_4,param_3)) {
        if (iVar2 == 1) {
          local_8 = -(double)CONCAT44(DAT_00441d9c,DAT_00441d98);
        }
        else {
          local_8 = (double)CONCAT44(DAT_00441d9c,DAT_00441d98);
        }
        param_5[1] = local_8._4_4_;
        *param_5 = (undefined4)local_8;
        return 0;
      }
      if ((double)CONCAT44(param_4,param_3) < 0.0) {
        if (iVar2 == 1) {
          local_8._0_4_ = DAT_00441db8;
          local_8._4_4_ = DAT_00441dbc;
        }
        else {
          local_8._0_4_ = 0;
          local_8._4_4_ = 0;
        }
        param_5[1] = local_8._4_4_;
        *param_5 = (undefined4)local_8;
        return 0;
      }
      *param_5 = 0;
      param_5[1] = 0x3ff00000;
    }
    return 0;
  }
  if (0.0 < (double)CONCAT44(param_4,param_3)) {
    param_5[1] = DAT_00441d9c;
    *param_5 = DAT_00441d98;
    return 0;
  }
  *param_5 = 0;
  if ((double)CONCAT44(param_4,param_3) < 0.0) {
    param_5[1] = 0;
    return 0;
  }
  param_5[1] = 0x3ff00000;
  return 0;
}


// ==== FUN_00438bd0 @ 00438bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00438bd0(int param_1,uint param_2)

{
  double dVar1;
  uint uVar2;
  float10 fVar3;
  
  uVar2 = FUN_0043b750(param_1,param_2);
  if ((uVar2 & 0x90) != 0) {
    return 0;
  }
  fVar3 = FUN_0043b730((double)CONCAT44(param_2,param_1));
  if (fVar3 == (float10)(double)CONCAT44(param_2,param_1)) {
    dVar1 = (double)CONCAT44(param_2,param_1) * _DAT_0043c500;
    fVar3 = FUN_0043b730(dVar1);
    if (fVar3 == (float10)dVar1) {
      return 2;
    }
    return 1;
  }
  return 0;
}


// ==== FUN_00438c50 @ 00438c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl
FUN_00438c50(int param_1,uint param_2,ushort param_3,undefined4 param_4,uint param_5,uint param_6)

{
  float10 fVar1;
  uint uVar2;
  float10 fVar3;
  
  fVar1 = (float10)CONCAT28(param_3,CONCAT44(param_2,param_1));
  while (!CARRY4(param_2,param_2)) {
    if (param_1 == 0 && param_2 == 0) {
      return 0;
    }
    if ((param_3 & 0x7fff) != 0) {
      return param_3 & 0x7fff;
    }
    uVar2 = param_6 & 0x7fff;
    if (uVar2 == 0) {
      if (CARRY4(param_5,param_5)) {
        return param_5 * 2;
      }
    }
    else if ((uVar2 == 0x7fff) || (uVar2 = param_5 * 2, !CARRY4(param_5,param_5))) {
      return uVar2;
    }
    fVar3 = fVar1 * (float10)_DAT_004419d8;
    param_1 = SUB104(fVar3,0);
    param_3 = (ushort)((unkuint10)fVar3 >> 0x40);
    param_2 = (uint)((unkuint10)fVar3 >> 0x20);
  }
  uVar2 = param_2 * 2 ^ 0xe000000;
  if ((uVar2 & 0xe000000) != 0) {
    return uVar2;
  }
  uVar2 = (param_2 & 0x7fffffff) >> 0x1b;
  if ((&DAT_004419c0)[uVar2] != '\0') {
    if (((param_3 & 0x7fff) != 0) && ((param_3 & 0x7fff) != 0x7fff)) {
      if ((param_6 & 0x7fff) != 1) {
        return param_6 & 0x7fff;
      }
      return 1;
    }
    return param_3 & 0x7fff;
  }
  return uVar2;
}


// ==== FUN_00439441 @ 00439441

undefined4 FUN_00439441(void)

{
  undefined4 in_EAX;
  unkbyte10 in_ST0;
  unkbyte10 in_ST1;
  undefined2 in_stack_ffffffe6;
  
  FUN_00438c50((int)in_ST1,(uint)((unkuint10)in_ST1 >> 0x20),(ushort)((unkuint10)in_ST1 >> 0x40),
               (int)in_ST0,(uint)((unkuint10)in_ST0 >> 0x20),
               CONCAT22(in_stack_ffffffe6,(short)((unkuint10)in_ST0 >> 0x40)));
  return in_EAX;
}


// ==== __raise_exc @ 004399e0

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


// ==== __handle_exc @ 00439d50

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
            FUN_0043a0d0();
          }
          uVar2 = param_1 & 0x1d;
        }
      }
      else {
        FUN_0043a0d0();
        uVar2 = param_3 & 0xc00;
        if (uVar2 < 0x401) {
          if (uVar2 == 0x400) {
            if (*param_2 <= 0.0) {
              uVar2 = param_1 & 0x1e;
              *param_2 = -(double)CONCAT44(DAT_00441d9c,DAT_00441d98);
            }
            else {
              uVar2 = param_1 & 0x1e;
              *(undefined4 *)((int)param_2 + 4) = DAT_00441dac;
              *(undefined4 *)param_2 = DAT_00441da8;
            }
          }
          else if (uVar2 == 0) {
            if (*param_2 <= 0.0) {
              uVar2 = param_1 & 0x1e;
              *param_2 = -(double)CONCAT44(DAT_00441d9c,DAT_00441d98);
            }
            else {
              uVar2 = param_1 & 0x1e;
              *(undefined4 *)((int)param_2 + 4) = DAT_00441d9c;
              *(undefined4 *)param_2 = DAT_00441d98;
            }
          }
          else {
            uVar2 = param_1 & 0x1e;
          }
        }
        else if (uVar2 == 0x800) {
          if (*param_2 <= 0.0) {
            uVar2 = param_1 & 0x1e;
            *param_2 = -(double)CONCAT44(DAT_00441dac,DAT_00441da8);
          }
          else {
            uVar2 = param_1 & 0x1e;
            *(undefined4 *)((int)param_2 + 4) = DAT_00441d9c;
            *(undefined4 *)param_2 = DAT_00441d98;
          }
        }
        else if (uVar2 == 0xc00) {
          if (*param_2 <= 0.0) {
            uVar2 = param_1 & 0x1e;
            *param_2 = -(double)CONCAT44(DAT_00441dac,DAT_00441da8);
          }
          else {
            uVar2 = param_1 & 0x1e;
            *(undefined4 *)((int)param_2 + 4) = DAT_00441dac;
            *(undefined4 *)param_2 = DAT_00441da8;
          }
        }
        else {
          uVar2 = param_1 & 0x1e;
        }
      }
    }
    else {
      uVar2 = param_1 & 0x1b;
      FUN_0043a0d0();
    }
  }
  else {
    uVar2 = param_1 & 0x17;
    FUN_0043a0d0();
  }
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    uVar2 = uVar2 & 0xffffffef;
    FUN_0043a0d0();
  }
  return uVar2 == 0;
}


// ==== __set_errno @ 0043a010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __set_errno
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __set_errno(int _Value)

{
  if (_Value == 1) {
    _DAT_004406d4 = 0x21;
    return _Value;
  }
  if (1 < _Value) {
    if (3 < _Value) {
      return _Value;
    }
    _DAT_004406d4 = 0x22;
  }
  return _Value;
}


// ==== FUN_0043a040 @ 0043a040

undefined4 FUN_0043a040(void)

{
  return 0;
}


// ==== __statfp @ 0043a050

/* Library Function - Single Match
    __statfp
   
   Library: Visual Studio 1998 Release */

int __statfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __clrfp @ 0043a070

/* Library Function - Single Match
    __clrfp
   
   Library: Visual Studio 1998 Release */

int __clrfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __ctrlfp @ 0043a090

/* Library Function - Single Match
    __ctrlfp
   
   Library: Visual Studio 1998 Release */

int __ctrlfp(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}


// ==== FUN_0043a0d0 @ 0043a0d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043a0d0(void)

{
  return;
}


// ==== ___crtGetStringTypeA @ 0043a130

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
  
  iVar2 = DAT_00441c20;
  if (DAT_00441c20 == 0) {
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
  DAT_00441c20 = iVar2;
  if (iVar2 != 2) {
    if (iVar2 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_00441988;
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
    _Code_page = DAT_00441978;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}


// ==== ___crtLCMapStringA @ 0043a260

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
  
  if (DAT_00441c28 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00441c28 = 1;
    }
    else {
      DAT_00441c28 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_00441c28 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_00441c28 != 1) {
    return DAT_00441c28;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_00441988;
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
                               iVar2), iVar1 == 0)) goto LAB_0043a3db;
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
      if (_LpDestStr == (LPSTR)0x0) goto LAB_0043a472;
      if ((int)_LpDestStr < iVar2) goto LAB_0043a3db;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_0043a472:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_0043a3db:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


// ==== _strncnt @ 0043a490

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
    if (*pcVar2 == '\0') goto LAB_0043a4b5;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_0043a4b5:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


// ==== ___addl @ 0043a4c0

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


// ==== ___add_12 @ 0043a4f0

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


// ==== ___shl_12 @ 0043a560

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


// ==== ___shr_12 @ 0043a5a0

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


// ==== ___mtold12 @ 0043a5e0

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


// ==== ___strgtold12 @ 0043a6d0

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
        if (DAT_00441498 == bVar8) {
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
          if (bVar8 != 0x30) goto switchD_0043a980_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_0043ab84;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_0043ab84;
      }
      if (DAT_00441498 == bVar8) {
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
          goto switchD_0043a980_caseD_2c;
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
        goto LAB_0043ab84;
      }
      if (DAT_00441498 == bVar8) {
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
        if (DAT_00441494 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_004414a0 + (uint)bVar8 * 2) & 4;
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
      if (DAT_00441498 == bVar8) {
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
          goto switchD_0043a980_caseD_2c;
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
        if (DAT_00441494 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_004414a0 + (uint)bVar8 * 2) & 4;
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
        goto switchD_0043a980_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_00441494 < 2) {
        uVar13 = *(ushort *)(PTR_DAT_004414a0 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_0043ab84;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = (byte *)(str + -1);
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_0043ab84;
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
        goto LAB_0043ab84;
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
        goto LAB_0043ab84;
      }
      goto switchD_0043a980_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_00441494 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_004414a0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_0043ab0a;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_0043ab0a:
      while( true ) {
        if (DAT_00441494 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_004414a0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_0043a980_caseD_2c:
      iVar7 = 10;
LAB_0043ab84:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (implicit_E == 0) goto switchD_0043a980_caseD_2c;
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
      goto LAB_0043ac82;
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
        goto LAB_0043ac82;
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
LAB_0043ac82:
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


// ==== $I10_OUTPUT @ 0043ae20

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
      *(undefined4 *)(param_6 + 2) = DAT_0043c5e8;
      param_6[4] = DAT_0043c5ec;
      *(undefined1 *)(param_6 + 5) = DAT_0043c5ee;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0043c5e0;
      param_6[4] = DAT_0043c5e4;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0043c5d8;
      param_6[4] = DAT_0043c5dc;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_0043c5d0;
    param_6[4] = DAT_0043c5d4;
    *(undefined1 *)(param_6 + 5) = DAT_0043c5d6;
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
LAB_0043b199:
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
    if (psVar7 < psVar1) goto LAB_0043b199;
    goto LAB_0043b16b;
  }
  if (psVar7 < psVar1) {
LAB_0043b165:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_0043b165;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_0043b16b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}


// ==== __dosmaperr @ 0043b1c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  int iVar1;
  ulong *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_00441c30;
  _DAT_004406d8 = param_1;
  do {
    if (*puVar2 == param_1) {
      _DAT_004406d4 = *(undefined4 *)(iVar1 * 8 + 0x441c34);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (puVar2 < &DAT_00441d98);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_004406d4 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    _DAT_004406d4 = 8;
    return;
  }
  _DAT_004406d4 = 0x16;
  return;
}


// ==== __free_osfhnd @ 0043b230

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
  
  if ((uint)param_1 < DAT_0048ea20) {
    piVar1 = (int *)((int)&DAT_0048e920 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar2 = (param_1 & 0x1fU) * 8;
    piVar3 = (int *)(*piVar1 + iVar2);
    if (((*(byte *)(piVar3 + 1) & 1) != 0) && (*piVar3 != -1)) {
      if (DAT_004406d0 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0043b296;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0043b296:
      *(undefined4 *)(*piVar1 + iVar2) = 0xffffffff;
      return 0;
    }
  }
  _DAT_004406d4 = 9;
  _DAT_004406d8 = 0;
  return -1;
}


// ==== __get_osfhandle @ 0043b2c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  
  if (((uint)_FileHandle < DAT_0048ea20) &&
     (piVar1 = (intptr_t *)
               (*(int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) +
               (_FileHandle & 0x1fU) * 8), (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  _DAT_004406d4 = 9;
  _DAT_004406d8 = 0;
  return -1;
}


// ==== _calloc @ 0043b310

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
      if (DAT_00440f64 < dwBytes) {
LAB_0043b36d:
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
          goto LAB_0043b36d;
        }
      }
      puVar3 = HeapAlloc(DAT_0048ea24,8,dwBytes);
    }
    if ((puVar3 != (undefined4 *)0x0) || (DAT_00440f68 == 0)) {
      return puVar3;
    }
    iVar1 = __callnewh(dwBytes);
    if (iVar1 == 0) {
      return (void *)0x0;
    }
  } while( true );
}


// ==== __fcloseall @ 0043b3b0

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
  if (3 < DAT_0048e910) {
    iVar2 = 0xc;
    do {
      _File = *(FILE **)(DAT_0048d908 + iVar2);
      if (_File != (FILE *)0x0) {
        if ((_File->_flag & 0x83U) != 0) {
          iVar1 = _fclose(_File);
          if (iVar1 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        if (0x4f < iVar2) {
          _free(*(void **)(DAT_0048d908 + iVar2));
          *(undefined4 *)(DAT_0048d908 + iVar2) = 0;
        }
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0048e910);
  }
  return iVar3;
}


// ==== _fflush @ 0043b430

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


// ==== __flush @ 0043b480

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


// ==== flsall @ 0043b500

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
  if (0 < DAT_0048e910) {
    iVar3 = 0;
    do {
      _File = *(FILE **)(DAT_0048d908 + iVar3);
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
    } while (iVar4 < DAT_0048e910);
  }
  if (param_1 != 1) {
    iVar2 = local_4;
  }
  return iVar2;
}


// ==== __set_exp @ 0043b590

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


// ==== FUN_0043b5d0 @ 0043b5d0

undefined4 __cdecl FUN_0043b5d0(int param_1,uint param_2)

{
  if ((param_2 == 0x7ff00000) && (param_1 == 0)) {
    return 1;
  }
  if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    return 3;
  }
  if (((param_2._2_2_ & 0x7ff8) == 0x7ff0) && (((param_2 & 0x7ffff) != 0 || (param_1 != 0)))) {
    return 4;
  }
  return 0;
}


// ==== __decomp @ 0043b640

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


// ==== FUN_0043b730 @ 0043b730

float10 __cdecl FUN_0043b730(double param_1)

{
  return (float10)ROUND(param_1);
}


// ==== FUN_0043b750 @ 0043b750

int __cdecl FUN_0043b750(int param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2._2_2_ & 0x7ff0) != 0x7ff0) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return (-(uint)((param_2 & 0x80000000) == 0) & 0x20) + 0x20;
    }
    if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
      return (-(uint)((param_2 & 0x80000000) == 0) & 0x70) + 0x10;
    }
    return (-(uint)((param_2 & 0x80000000) == 0) & 0xf8) + 8;
  }
  iVar1 = FUN_0043b5d0(param_1,param_2);
  if (iVar1 == 1) {
    return 0x200;
  }
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      return 1;
    }
    return 2;
  }
  return 4;
}


// ==== ___ld12mul @ 0043b800

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
    if (0 < (short)local_1a) goto LAB_0043b9d3;
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
LAB_0043b9d3:
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


// ==== ___multtenpow12 @ 0043bab0

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
  
  puVar4 = &DAT_00441d60;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar4 = &DAT_00441ec0;
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


// ==== _fclose @ 0043bb30

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


// ==== __commit @ 0043bba0

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
  
  if (((uint)_FileHandle < DAT_0048ea20) &&
     ((*(byte *)(*(int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    DVar2 = 0;
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    iVar3 = 0;
    if (DVar2 != 0) {
      _DAT_004406d4 = 9;
      _DAT_004406d8 = DVar2;
      return -1;
    }
  }
  else {
    _DAT_004406d4 = 9;
    iVar3 = -1;
  }
  return iVar3;
}


// ==== __close @ 0043bc10

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
  
  if (DAT_0048ea20 <= (uint)_FileHandle) {
    _DAT_004406d4 = 9;
    _DAT_004406d8 = 0;
    return -1;
  }
  piVar1 = (int *)((int)&DAT_0048e920 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar2 = (_FileHandle & 0x1fU) * 8;
  if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) == 0) {
    _DAT_004406d4 = 9;
    _DAT_004406d8 = 0;
    return -1;
  }
  if ((_FileHandle == 1) || (_FileHandle == 2)) {
    iVar3 = __get_osfhandle(2);
    iVar4 = __get_osfhandle(1);
    if (iVar3 != iVar4) goto LAB_0043bc6b;
  }
  else {
LAB_0043bc6b:
    hObject = (HANDLE)__get_osfhandle(_FileHandle);
    BVar5 = CloseHandle(hObject);
    if (BVar5 == 0) {
      DVar6 = GetLastError();
      goto LAB_0043bc8b;
    }
  }
  DVar6 = 0;
LAB_0043bc8b:
  __free_osfhnd(_FileHandle);
  if (DVar6 == 0) {
    *(undefined1 *)(*piVar1 + 4 + iVar2) = 0;
    return 0;
  }
  __dosmaperr(DVar6);
  return -1;
}


// ==== __freebuf @ 0043bce0

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


