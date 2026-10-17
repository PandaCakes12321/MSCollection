from PIL import Image
A='D:/Downloads/AIWORKSPACE/PuzzlePort/LineupAndroid/app/src/main/assets/mixgen/img/'
S='D:/Downloads/AIWORKSPACE/PuzzlePort/MIXGEN/work/spr/'
off={0:[(11,28),(24,29),(10,12),(7,16),(32,14),(3,5)],1:[(10,26),(23,28),(13,12),(4,18),(18,16),(14,0)],
2:[(5,25),(24,26),(10,12),(1,15),(20,16),(12,4)],3:[(9,27),(26,24),(9,12),(2,16),(34,16),(9,3)],
4:[(8,31),(22,30),(12,12),(5,16),(31,12),(3,1)],5:[(9,25),(25,31),(10,12),(5,15),(30,12),(0,3)]}
bg=Image.open(A+'GAMEBOX.png').convert('RGBA')
def put(n,x,y,src=A): bg.alpha_composite(Image.open(src+n+'.png').convert('RGBA'),(x,y))
def animal(g,x,y):
  for p in range(6): put('%d'%(2100+g[p]*100+p),x+off[g[p]][p][0],y+off[g[p]][p][1],S)
put('DOOR00',264,327); put('BOOKOPENBMP',20,331); put('BOOKMARK2',81,340); animal([1]*6,32,340)
put('BDIGITBMP1',106,375); put('BDIGITBMP5',117,375); put('DIGITBMP0',585,348); put('DIGITBMP3',595,348)
for i,dg in enumerate('01234'): put('DIGITBMP'+dg,555+10*i,369)
put('3108',300+11,181+34,S); put('3302',107,341,S)
regs=[(34,-7),(6,112),(332,112),(6,188),(332,188),(6,265),(332,265)]
import random
for c in range(10):
  for r in range(2): animal([random.randrange(6) for _ in range(6)],39+c*55,-2+r*57)
for k in range(1,7):
  for c in range(5): animal([random.randrange(6) for _ in range(6)],regs[k][0]+5+c*55,regs[k][1]+5)
animal([2]*6,285,337)
bg.save('D:/Downloads/AIWORKSPACE/PuzzlePort/MIXGEN/work/mock.png')
