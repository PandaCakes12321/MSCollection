import sys
from PIL import Image
off={0:[(11,28),(24,29),(10,12),(7,16),(32,14),(3,5)],1:[(10,26),(23,28),(13,12),(4,18),(18,16),(14,0)],
2:[(5,25),(24,26),(10,12),(1,15),(20,16),(12,4)],3:[(9,27),(26,24),(9,12),(2,16),(34,16),(9,3)],
4:[(8,31),(22,30),(12,12),(5,16),(31,12),(3,1)],5:[(9,25),(25,31),(10,12),(5,15),(30,12),(0,3)]}
d='D:/Downloads/AIWORKSPACE/PuzzlePort/MIXGEN/work/spr/'
out=Image.new('RGBA',(8*70,6*70),(90,90,90,255))
import random
for s in range(6):
  for v in range(8):
    g=[s]*6 if v==0 else [random.randrange(6) for _ in range(6)]
    c=Image.new('RGBA',(64,64),(0,0,0,0)); mw=mh=0
    for p in range(6):
      im=Image.open(d+'%d.png'%(2100+g[p]*100+p)).convert('RGBA')
      x,y=off[g[p]][p]; c.alpha_composite(im,(x,y)); mw=max(mw,x+im.width); mh=max(mh,y+im.height)
    out.alpha_composite(c,(v*70,s*70))
    if v==0: print(s,mw,mh)
out=out.resize((out.width*2,out.height*2),Image.NEAREST); out.save('D:/Downloads/AIWORKSPACE/PuzzlePort/MIXGEN/work/compose.png')
