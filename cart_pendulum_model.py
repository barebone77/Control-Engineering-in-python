import pygame,sys
from pygame.locals import *
pygame.init()
DISPLAYSURF=pygame.display.set_mode((800,500),0,32)
pygame.display.set_caption('CART PENDULUM MODEL')
WHITE=(255,255,255)
BLACK=(0,0,0)
RED=(255,0,0)
BLUE=(0,0,255)
GREEN=(0,255,0)
def draw_cart():
    DISPLAYSURF.fill(WHITE)
    pygame.draw.rect(DISPLAYSURF,BLUE,(200,150,200,110) )
    pygame.draw.circle(DISPLAYSURF,BLACK,(250,260),20,0)
    pygame.draw.circle(DISPLAYSURF,BLACK,(350,260),20,0)
    pygame.draw.line(DISPLAYSURF,GREEN,(300,205),(450,70),2)
    pygame.draw.circle(DISPLAYSURF,RED,(450,70),15,0)
draw_cart()
# DISPLAYSURF.fill(WHITE)
# pygame.draw.rect(DISPLAYSURF,BLUE,(200,150,200,110) )
# pygame.draw.circle(DISPLAYSURF,BLACK,(250,260),20,0)
# pygame.draw.circle(DISPLAYSURF,BLACK,(350,260),20,0)
while True:
    for event in pygame.event.get():
        if event.type==QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.update()        
