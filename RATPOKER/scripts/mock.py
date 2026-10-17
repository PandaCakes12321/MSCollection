import sys, struct
from PIL import Image
sys.path.insert(0,'.')
L = int(sys.argv[1]); out = sys.argv[2]
B = '../extracted/shared/bitmaps/'
import pefile
pe = pefile.PE('../../original/RATPOKER.EXE'); base = pe.OPTIONAL_HEADER.ImageBase
rd = lambda va,n: pe.get_data(va-base,n)
lv = struct.unpack('<24i', rd(0x414660+L*0x60, 96))
rows = [rd(0x415318+L*200+r*20, 10).decode('latin1') for r in range(10)]
idx = {}
for l in open('../conv/spr/sprites.txt'):
    n,i,x,w,h,hx,hy = l.split(); hy=int(hy); hy = hy-65536 if hy>32767 else hy
    idx[(n,int(i))] = (int(x),int(w),int(h),int(hx),hy)
sheets = {}
def spr(img, n, f, x, y):
    if n not in sheets: sheets[n] = Image.open('../conv/spr/'+n+'.png')
    sx,w,h,hx,hy = idx[(n,f)]
    fr = sheets[n].crop((sx,0,sx+w,h)); img.paste(fr,(x-hx,y-hy),fr)
img = Image.open(B+'BACKGROUND%02d.png'%lv[6]).convert('RGBA')
ls = Image.open(B+'LEVSCORE.png').convert('RGBA'); img.paste(ls,(395,0))
W='WAYS_%d'%lv[7]
fmap = {'-':7,'#':10,'|':9,'J':5,'Y':2,'L':3,'/':0,'<':13,'^':13,'>':13,'V':4,'v':4,'O':12,'X':12}
for r in range(10):
    for c in range(10):
        ch = rows[r][c]; x=c*39+25; y=r*39+25
        if ch=='$': spr(img,W,11,x,y); spr(img,W,10,x,y)
        elif ch=='X': spr(img,W,15,x,y-39); spr(img,W,12,x,y); spr(img,'DOOR_%d'%lv[7],0,x-1,y-3)
        elif ch=='O': spr(img,W,12,x,y); spr(img,'DOOR_%d'%lv[7],0,x,y-3)
        elif ch in fmap: spr(img,W,fmap[ch],x,y)
        if ch=='*': cx,cy=x,y
spr(img,'ROTARY_%d'%lv[9],4,cx,cy); spr(img,'A_CENTER',0,cx,cy)
spr(img,'RAT_R',3,cx+77,cy); spr(img,'BUBBLESPR',0,cx+77,cy)
spr(img,'RAT_G_P',0,2*39+25+14,6*39+25)
for i,d in enumerate([0,0,1,2,5]): spr(img,'DIGITS',d,494+14*i,59)
spr(img,'DIGITS',L//10,517,25); spr(img,'DIGITS',L%10,531,25)
y=56; k=0
for h in [9,8,7,6,5,4,2,1,0]:
    y+=34
    if lv[14+h]: img.paste(Image.open(B+'COMB%02d.png'%k).convert('RGBA'),(400,y))
    k+=1
img.save(out)
