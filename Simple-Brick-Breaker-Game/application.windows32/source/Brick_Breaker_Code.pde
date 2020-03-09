//GLOBAL VARIABLES
int x = 350;
int y = 400;
int pc = 0;

int aax = 25;
int aay = 25;
int aah = 25;
int aaw = 75;

int abx = 125;
int aby = 25;
int abh = 25;
int abw = 75;

int acx = 225; 
int acy = 25;
int ach = 25;
int acw = 75;

int adx = 325;
int ady = 25;
int adh = 25;
int adw = 75;

int aex = 425;
int aey = 25;
int aeh = 25;
int aew = 75;

int afx = 525;
int afy = 25;
int afh = 25;
int afw = 75;

int agx = 625;
int agy = 25;
int agh = 25;
int agw = 75;

int bax = 25;
int bay = 75;
int bah = 25;
int baw = 75;

int bbx = 125;
int bby = 75;
int bbh = 25;
int bbw = 75;

int bcx = 225; 
int bcy = 75;
int bch = 25;
int bcw = 75;

int bdx = 325;
int bdy = 75;
int bdh = 25;
int bdw = 75;

int bex = 425;
int bey = 75;
int beh = 25;
int bew = 75;

int bfx = 525;
int bfy = 75;
int bfh = 25;
int bfw = 75;

int bgx = 625;
int bgy = 75;
int bgh = 25;
int bgw = 75;

int cax = 25;
int cay = 125;
int cah = 25;
int caw = 75;

int cbx = 125;
int cby = 125;
int cbh = 25;
int cbw = 75;

int ccx = 225; 
int ccy = 125;
int cch = 25;
int ccw = 75;

int cdx = 325;
int cdy = 125;
int cdh = 25;
int cdw = 75;

int cex = 425;
int cey = 125;
int ceh = 25;
int cew = 75;

int cfx = 525;
int cfy = 125;
int cfh = 25;
int cfw = 75;

int cgx = 625;
int cgy = 125;
int cgh = 25;
int cgw = 75;

int dax = 25;
int day = 175;
int dah = 25;
int daw = 75;

int dbx = 125;
int dby = 175;
int dbh = 25;
int dbw = 75;

int dcx = 225; 
int dcy = 175;
int dch = 25;
int dcw = 75;

int ddx = 325;
int ddy = 175;
int ddh = 25;
int ddw = 75;

int dex = 425;
int dey = 175;
int deh = 25;
int dew = 75;

int dfx = 525;
int dfy = 175;
int dfh = 25;
int dfw = 75;

int dgx = 625;
int dgy = 175;
int dgh = 25;
int dgw = 75;

int eax = 25;
int eay = 225;
int eah = 25;
int eaw = 75;

int ebx = 125;
int eby = 225;
int ebh = 25;
int ebw = 75;

int ecx = 225; 
int ecy = 225;
int ech = 25;
int ecw = 75;

int edx = 325;
int edy = 225;
int edh = 25;
int edw = 75;

int eex = 425;
int eey = 225;
int eeh = 25;
int eew = 75;

int efx = 525;
int efy = 225;
int efh = 25;
int efw = 75;

int egx = 625;
int egy = 225;
int egh = 25;
int egw = 75;

int fax = 25;
int fay = 275;
int fah = 25;
int faw = 75;

int fbx = 125;
int fby = 275;
int fbh = 25;
int fbw = 75;

int fcx = 225; 
int fcy = 275;
int fch = 25;
int fcw = 75;

int fdx = 325;
int fdy = 275;
int fdh = 25;
int fdw = 75;

int fex = 425;
int fey = 275;
int feh = 25;
int few = 75;

int ffx = 525;
int ffy = 275;
int ffh = 25;
int ffw = 75;

int fgx = 625;
int fgy = 275;
int fgh = 25;
int fgw = 75;

//BALL MOVEMENT
int x_movement = 6;
int y_movement = 4;

//WINDOW SIZE
void setup()
{
  size(725,700);
}

//GAMEPLAY
void draw()
{
//BALL MOVEMENT
  background(0);
  fill(255);
  ellipse(x,y,20,20);
  x += x_movement;
  y += y_movement;
  
  //PADDLE
 fill(255);
  rect(mouseX-75,675,150,25);
  
 //GAME OVER SCREEN
 if (y > height)
  {
    fill(255);
   rect(0,0,width,height);
   fill(255,0,0);
   textSize(100);
   text("GAME OVER",70,500);
  }
  
 //BALL PHYSICS
 if (x > mouseX-80 && x < mouseX-35 && y > 675 && y < 700 && x_movement > 0)
  {
    y_movement *= -1;
    x_movement *= -1;
    y_movement -= 1;
  }
  
   if (x > mouseX-80 && x < mouseX-35 && y > 675 && y < 700 && x_movement < 0)
  {
    y_movement *= -1;
    y_movement -= 1;
  }
  
   if (x > mouseX-35 && x < mouseX && y > 675 && y < 700)
  {
    y_movement *= -1;
    y_movement -= 1;
  }
  
   if (x > mouseX && x < mouseX+35 && y > 675 && y < 700)
  {
    y_movement *= -1;
    y_movement -= 1;
  }
  
  if (x > mouseX+35 && x < mouseX+80 && y > 675 && y < 700 && x_movement > 0)
  {
    y_movement *= -1;
    y_movement -= 1;
  }
  
  if (x > mouseX+35 && x < mouseX+80 && y > 675 && y < 700 && x_movement < 0)
  {
    y_movement *= -1;
    x_movement *= -1;
    y_movement -= 1;
  }
  
  if (y < 0)
  {
  y_movement *= -1;
  }
  
 if(x < 0 || x > width)
 {
   x_movement *= -1;
 }
 
 //BRICKS
 fill(random(225),random(225),random(225));
 rect(aax,aay,aaw,aah);
 if(x>aax && x<(aax+aaw) && y > aay && y < (aay+aah))
 {
  aax = 1000;
  aay = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>aay && y<(aay+aah) && x > aax && x < (aax+aaw))
 {
  aax = 1000;
  aay = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(abx,aby,abw,abh);
 if(x>abx && x<(abx+abw) && y > aby && y < (aby+abh))
 {
  abx = 1000;
  aby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>aby && y<(aby+abh) && x > abx && x < (abx+abw))
 {
  abx = 1000;
  aby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(acx,acy,acw,ach);
 if(x>acx && x<(acx+acw) && y > acy && y < (acy+ach))
 {
  acx = 1000;
  acy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>acy && y<(acy+ach) && x > acx && x < (acx+acw))
 {
  acx = 1000;
  acy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(adx,ady,adw,adh);
 if(x>adx && x<(adx+adw) && y > ady && y < (ady+adh))
 {
  adx = 1000;
  ady = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>ady && y<(ady+adh) && x > adx && x < (adx+adw))
 {
  adx = 1000;
  ady = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(aex,aey,aew,aeh);
 if(x>aex && x<(aex+aew) && y > aey && y < (aey+aeh))
 {
  aex = 1000;
  aey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>aey && y<(aey+aeh) && x > aex && x < (aex+aew))
 {
  aex = 1000;
  aey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(afx,afy,afw,afh);
 if(x>afx && x<(afx+afw) && y > afy && y < (afy+afh))
 {
  afx = 1000;
  afy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>afy && y<(afy+afh) && x > afx && x < (afx+afw))
 {
  afx = 1000;
  afy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(agx,agy,agw,agh);
 if(x>agx && x<(agx+agw) && y > agy && y < (agy+agh))
 {
  agx = 1000;
  agy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>agy && y<(agy+agh) && x > agx && x < (agx+agw))
 {
  agx = 1000;
  agy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(bax,bay,baw,bah);
 if(x>bax && x<(bax+baw) && y > bay && y < (bay+bah))
 {
  bax = 1000;
  bay = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bay && y<(bay+bah) && x > bax && x < (bax+baw))
 {
  bax = 1000;
  bay = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(bbx,bby,bbw,bbh);
 if(x>bbx && x<(bbx+bbw) && y > bby && y < (bby+bbh))
 {
  bbx = 1000;
  bby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bby && y<(bby+bbh) && x > bbx && x < (bbx+bbw))
 {
  bbx = 1000;
  bby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(bcx,bcy,bcw,bch);
 if(x>bcx && x<(bcx+bcw) && y > bcy && y < (bcy+bch))
 {
  bcx = 1000;
  bcy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bcy && y<(bcy+bch) && x > bcx && x < (bcx+bcw))
 {
  bcx = 1000;
  bcy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(bdx,bdy,bdw,bdh);
 if(x>bdx && x<(bdx+bdw) && y > bdy && y < (bdy+bdh))
 {
  bdx = 1000;
  bdy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bdy && y<(bdy+bdh) && x > bdx && x < (bdx+bdw))
 {
  bdx = 1000;
  bdy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(bex,bey,bew,beh);
 if(x>bex && x<(bex+bew) && y > bey && y < (bey+beh))
 {
  bex = 1000;
  bey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bey && y<(bey+beh) && x > bex && x < (bex+bew))
 {
  bex = 1000;
  bey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(bfx,bfy,bfw,bfh);
 if(x>bfx && x<(bfx+bfw) && y > bfy && y < (bfy+bfh))
 {
  bfx = 1000;
  bfy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bfy && y<(bfy+bfh) && x > bfx && x < (bfx+bfw))
 {
  bfx = 1000;
  bfy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(bgx,bgy,bgw,bgh);
 if(x>bgx && x<(bgx+bgw) && y > bgy && y < (bgy+bgh))
 {
  bgx = 1000;
  bgy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>bgy && y<(bgy+bgh) && x > bgx && x < (bgx+bgw))
 {
  bgx = 1000;
  bgy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(cax,cay,caw,cah);
 if(x>cax && x<(cax+caw) && y > cay && y < (cay+cah))
 {
  cax = 1000;
  cay = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cay && y<(cay+cah) && x > cax && x < (cax+caw))
 {
  cax = 1000;
  cay = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(cbx,cby,cbw,cbh);
 if(x>cbx && x<(cbx+cbw) && y > cby && y < (cby+cbh))
 {
  cbx = 1000;
  cby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cby && y<(cby+cbh) && x > cbx && x < (cbx+cbw))
 {
  cbx = 1000;
  cby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(ccx,ccy,ccw,cch);
 if(x>ccx && x<(ccx+ccw) && y > ccy && y < (ccy+cch))
 {
  ccx = 1000;
  ccy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>ccy && y<(ccy+cch) && x > ccx && x < (ccx+ccw))
 {
  ccx = 1000;
  ccy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(cdx,cdy,cdw,cdh);
 if(x>cdx && x<(cdx+cdw) && y > cdy && y < (cdy+cdh))
 {
  cdx = 1000;
  cdy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cdy && y<(cdy+cdh) && x > cdx && x < (cdx+cdw))
 {
  cdx = 1000;
  cdy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(cex,cey,cew,ceh);
 if(x>cex && x<(cex+cew) && y > cey && y < (cey+ceh))
 {
  cex = 1000;
  cey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cey && y<(cey+ceh) && x > cex && x < (cex+cew))
 {
  cex = 1000;
  cey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(cfx,cfy,cfw,cfh);
 if(x>cfx && x<(cfx+cfw) && y > cfy && y < (cfy+cfh))
 {
  cfx = 1000;
  cfy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cfy && y<(cfy+cfh) && x > cfx && x < (cfx+cfw))
 {
  cfx = 1000;
  cfy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(cgx,cgy,cgw,cgh);
 if(x>cgx && x<(cgx+cgw) && y > cgy && y < (cgy+cgh))
 {
  cgx = 1000;
  cgy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>cgy && y<(cgy+cgh) && x > cgx && x < (cgx+cgw))
 {
  cgx = 1000;
  cgy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(dax,day,daw,dah);
 if(x>dax && x<(dax+daw) && y > day && y < (day+dah))
 {
  dax = 1000;
  day = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>day && y<(day+dah) && x > dax && x < (dax+daw))
 {
  dax = 1000;
  day = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(dbx,dby,dbw,dbh);
 if(x>dbx && x<(dbx+dbw) && y > dby && y < (dby+dbh))
 {
  dbx = 1000;
  dby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>dby && y<(dby+dbh) && x > dbx && x < (dbx+dbw))
 {
  dbx = 1000;
  dby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(dcx,dcy,dcw,dch);
 if(x>dcx && x<(dcx+dcw) && y > dcy && y < (dcy+dch))
 {
  dcx = 1000;
  dcy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>dcy && y<(dcy+dch) && x > dcx && x < (dcx+dcw))
 {
  dcx = 1000;
  dcy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(ddx,ddy,ddw,ddh);
 if(x>ddx && x<(ddx+ddw) && y > ddy && y < (ddy+ddh))
 {
  ddx = 1000;
  ddy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>ddy && y<(ddy+ddh) && x > ddx && x < (ddx+ddw))
 {
  ddx = 1000;
  ddy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(dex,dey,dew,deh);
 if(x>dex && x<(dex+dew) && y > dey && y < (dey+deh))
 {
  dex = 1000;
  dey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>dey && y<(dey+deh) && x > dex && x < (dex+dew))
 {
  dex = 1000;
  dey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(dfx,dfy,dfw,dfh);
 if(x>dfx && x<(dfx+dfw) && y > dfy && y < (dfy+dfh))
 {
  dfx = 1000;
  dfy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>dfy && y<(dfy+dfh) && x > dfx && x < (dfx+dfw))
 {
  dfx = 1000;
  dfy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(dgx,dgy,dgw,dgh);
 if(x>dgx && x<(dgx+dgw) && y > dgy && y < (dgy+dgh))
 {
  dgx = 1000;
  dgy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>dgy && y<(dgy+dgh) && x > dgx && x < (dgx+dgw))
 {
  dgx = 1000;
  dgy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
 fill(random(225),random(225),random(225));
  rect(eax,eay,eaw,eah);
 if(x>eax && x<(eax+eaw) && y > eay && y < (eay+eah))
 {
  eax = 1000;
  eay = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>eay && y<(eay+eah) && x > eax && x < (eax+eaw))
 {
  eax = 1000;
  eay = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(ebx,eby,ebw,ebh);
 if(x>ebx && x<(ebx+ebw) && y > eby && y < (eby+ebh))
 {
  ebx = 1000;
  eby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>eby && y<(eby+ebh) && x > ebx && x < (ebx+ebw))
 {
  ebx = 1000;
  eby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(ecx,ecy,ecw,ech);
 if(x>ecx && x<(ecx+ecw) && y > ecy && y < (ecy+ech))
 {
  ecx = 1000;
  ecy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>ecy && y<(ecy+ech) && x > ecx && x < (ecx+ecw))
 {
  ecx = 1000;
  ecy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(edx,edy,edw,edh);
 if(x>edx && x<(edx+edw) && y > edy && y < (edy+edh))
 {
  edx = 1000;
  edy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>edy && y<(edy+edh) && x > edx && x < (edx+edw))
 {
  edx = 1000;
  edy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(eex,eey,eew,eeh);
 if(x>eex && x<(eex+eew) && y > eey && y < (eey+eeh))
 {
  eex = 1000;
  eey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>eey && y<(eey+eeh) && x > eex && x < (eex+eew))
 {
  eex = 1000;
  eey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(efx,efy,efw,efh);
 if(x>efx && x<(efx+efw) && y > efy && y < (efy+efh))
 {
  efx = 1000;
  efy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>efy && y<(efy+efh) && x > efx && x < (efx+efw))
 {
  efx = 1000;
  efy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(egx,egy,egw,egh);
 if(x>egx && x<(egx+egw) && y > egy && y < (egy+egh))
 {
  egx = 1000;
  egy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>egy && y<(egy+egh) && x > egx && x < (egx+egw))
 {
  egx = 1000;
  egy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(fax,fay,faw,fah);
 if(x>fax && x<(fax+faw) && y > fay && y < (fay+fah))
 {
  fax = 1000;
  fay = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fay && y<(fay+fah) && x > fax && x < (fax+faw))
 {
  fax = 1000;
  fay = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
 rect(fbx,fby,fbw,fbh);
 if(x>fbx && x<(fbx+fbw) && y > fby && y < (fby+fbh))
 {
  fbx = 1000;
  fby = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fby && y<(fby+fbh) && x > fbx && x < (fbx+fbw))
 {
  fbx = 1000;
  fby = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(fcx,fcy,fcw,fch);
 if(x>fcx && x<(fcx+fcw) && y > fcy && y < (fcy+fch))
 {
  fcx = 1000;
  fcy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fcy && y<(fcy+fch) && x > fcx && x < (fcx+fcw))
 {
  fcx = 1000;
  fcy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(fdx,fdy,fdw,fdh);
 if(x>fdx && x<(fdx+fdw) && y > fdy && y < (fdy+fdh))
 {
  fdx = 1000;
  fdy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fdy && y<(fdy+fdh) && x > fdx && x < (fdx+fdw))
 {
  fdx = 1000;
  fdy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(fex,fey,few,feh);
 if(x>fex && x<(fex+few) && y > fey && y < (fey+feh))
 {
  fex = 1000;
  fey = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fey && y<(fey+feh) && x > fex && x < (fex+few))
 {
  fex = 1000;
  fey = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
  fill(random(225),random(225),random(225));
  rect(ffx,ffy,ffw,ffh);
 if(x>ffx && x<(ffx+ffw) && y > ffy && y < (ffy+ffh))
 {
  ffx = 1000;
  ffy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>ffy && y<(ffy+ffh) && x > ffx && x < (ffx+ffw))
 {
  ffx = 1000;
  ffy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
   fill(random(225),random(225),random(225));
  rect(fgx,fgy,fgw,fgh);
 if(x>fgx && x<(fgx+fgw) && y > fgy && y < (fgy+fgh))
 {
  fgx = 1000;
  fgy = 1000;
  y_movement *= -1;
  pc = pc+100;
 }
 if(y>fgy && y<(fgy+fgh) && x > fgx && x < (fgx+fgw))
 {
  fgx = 1000;
  fgy = 1000;
  x_movement *= -1;
  pc = pc+100;
 }
 
 fill(255,0,0);
   textSize(20);
   text("Points = " + pc,300,600);
   
   if(pc == 4200)
   {
     fill(255);
   rect(0,0,width,height);
   fill(0,255,0);
   textSize(100);
   text("YOU WIN",140,400);
   }
}