#include<stdlib.h>

#include<stdio.h>

#include<glut.h>

#include<math.h>

static GLdouble viewer[] = {
  1.0,
  0.0,
  0.0
};
float ymove = -2.5, xmove = -.35, zmove = 1.5, batangle = 0, ballback = 0, wicketangle = 0;
int start = 0, hit = 0, front = 0, back = 0, leg = 0, off = 0, selectwicket, delay = 0, no_of_wickets = 0, no_of_balls = 0, no_of_runs = 0, no_of_overs = 0;
float orthoadjust = 2.0, bowlerarmangle = -30;
void ground() {

  glPushMatrix();
  glPushMatrix();
  glColor3f(1, 0, 0);
  glutSolidTorus(.01, 4, 50, 40);
  glColor3f(1.39, .69, 0.19);
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_POLYGON);
  glVertex3f(.5, 1.5, .51);
  glVertex3f(1, -2, .51);
  glVertex3f(-1, -2, .51);
  glVertex3f(-.5, 1.5, .51);
  glEnd();

  glPopMatrix();

}
void ball() {

  glTranslatef(xmove, -ymove, zmove);
  glColor3f(1, 0, 0);
  glColor3f(1, 01, 01);
  glutSolidSphere(.03, 20, 40);

}
void wickets() {
  //batting end

  glColor3f(1, 0, 0);
  glPushMatrix();
  glTranslatef(0, -1.30, -1);
  if (selectwicket = 0)
    glRotatef(wicketangle, 0, 0, 1);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
  glPushMatrix();

  glTranslatef(0.1, -1.30, -1);
  if (selectwicket = 1)
    glRotatef(wicketangle, 0, 0, 1);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.05, -1.30, -1);
  if (selectwicket = 2)
    glRotatef(wicketangle, 0, 0, 1);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
  //bowling end
  glPushMatrix();
  glTranslatef(0, 1.30, -.11);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.1, 1.30, -.11);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.05, 1.30, -.11);
  glScalef(.02, .7, .1);
  glutSolidCube(.5);
  glPopMatrix();
}
void bat()

{
  glTranslatef(-.15, -.25, 0.5);
  glTranslatef(batangle, 0, 0);
  glRotatef(55, 0, 0, 01);
  //glRotatef(batangle,01,01,01);
  glColor3f(0, 0, 1);
  glScalef(.40, 2, .1);
  glutSolidCube(.1);
}
void batsmen() {
  //head
  glTranslatef(-.1, 0, 0);
  glPushMatrix();
  glTranslatef(-00.01, -.7, -.15);
  glColor3f(0, 0, 0);
  glutSolidSphere(.04, 30, 40);
  glColor3f(0, 0, 0);
  glutWireSphere(.07, 30, 40);
  //body
  glColor3f(1, 1, 1);
  glTranslatef(-0.03, -.18, -.15);
  glRotatef(-15, 0, 0, 1);
  glScalef(.8, 1.4, 1);
  glutSolidCube(.12);
  glColor3f(1, 1, 1);
  //glPushMatrix();//abdomen
  glTranslatef(0.05, -.1, -.15);
  glRotatef(49, 0, 0, 1);
  glScalef(.8, 1.5, 1);
  glutSolidCube(.12);
  //glPopMatrix();
  glColor3f(1, 1, 1); //thigh
  //glTranslatef(-0.03,-.1,-1);
  glRotatef(-15, 0, 0, 1);
  glScalef(.8, 1.55, 1);
  //glutSolidCube(.12);
  //legs
  glColor3f(1, 1, 1);
  glTranslatef(-0.025, -.07, -.15);
  glRotatef(-50, 0, 0, 1);
  glScalef(.43, 1, 1);
  glutSolidCube(.12);
  //hands
  glColor3f(1, 01, 01);
  glTranslatef(.1, .2, -1);
  glRotatef(90, 0, 0, 1);
  glScalef(.3, 1.2, 1);
  glutSolidCube(.12);

  glPopMatrix();
}
void bowlerhead() {
  glColor3f(.7, .7, .7);
  glScalef(.1, .1, 1);
  glutSolidSphere(1, 100, 4);
}
void bowlerbody() {
  glTranslatef(0, -.23, 0);
  glScalef(.2, .2, 1);
  glColor3f(1, 0, 0);
  glutSolidCube(1);

}
void bowlerarmleft() {
  glRotatef(bowlerarmangle, 0, 0, 10);
  glTranslatef(-.05, -0.2, -1);
  glScalef(.2, .07, 0.01);
  glColor3f(1, 0, 0);
  glutSolidCube(1);
}
void bowlerarmright() {

  glRotatef(-45, 0, 0, 1);
  glTranslatef(.28, -0.05, 0);
  glScalef(.2, .07, 1);
  glColor3f(1, 0, 0);
  glutSolidCube(1);
}
void bowlerlegright() {

  glPushMatrix();
  glRotatef(-0, 0, 0, 1);
  glTranslatef(.05, -0.5, 0);
  glScalef(.08, .30, 1);
  glColor3f(1, 0, 0);

  glutSolidCube(1);
  glPopMatrix();
}
void bowlerlegleft() {

  glTranslatef(-.05, -0.5, 0);
  glScalef(.08, .30, 1);
  glColor3f(1, 0, 0);
  glutSolidCube(1);
}
void bowler() {
  glScalef(1, 1, .43);
  //glRotatef(45,0,1,0);
  glScalef(.5, .5, .5);
  glTranslatef(-0.15, 3.5, 0);
  glPushMatrix();

  bowlerhead();
  glPopMatrix();
  glPushMatrix();
  bowlerbody();
  glPopMatrix();
  glPushMatrix();

  bowlerarmleft();
  glPopMatrix();
  glPushMatrix();

  bowlerarmright();
  glPopMatrix();
  glPushMatrix();
  bowlerlegright();
  glPopMatrix();
  glPushMatrix();
  bowlerlegleft();
  glPopMatrix();
}
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glClearColor(0, 01, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-orthoadjust, orthoadjust, -orthoadjust, orthoadjust, orthoadjust, -orthoadjust);
  glMatrixMode(GL_MODELVIEW);
  //gluLookAt(1,1,1,0,01,0,0,1,0);
  glPushMatrix();
  glColor3f(1, 0, 0);
  //glutSolidTorus(.02,3.3,40,40);
  glPopMatrix();
  glPushMatrix();
  wickets();
  glPopMatrix();
  glPushMatrix();
  ground();
  glPopMatrix();
  glPushMatrix();
  bowler();
  glPopMatrix();
  glPushMatrix();
  batsmen();
  glPopMatrix();
  //glRotatef(90,0,0,1);
  glTranslatef(.15, -.78, -1);
  glPushMatrix();
  bat();
  glPopMatrix();
  glPushMatrix();
  ball();
  glPopMatrix();
  glutSwapBuffers();
}
void mouse(int btn, int state, int x, int y) {

  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN);
  if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN);
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN);

}
int count = 0, boff, bleg, bgood;
void reset()

{

  start = 0, orthoadjust = 2, bowlerarmangle = -30;
  ymove = -2.5, xmove = -.35, zmove = 0, batangle = 0, hit = 0, count++, wicketangle = 0;
  if (count >= 3) count = 0, boff = bleg = bgood = 0;
  display();
  printf("no of runs=%d", no_of_runs);

}
void delayfunc() {
  for (delay = 0; delay < 300000000; delay++)
  ;
  reset();
}
void bowlingdirection() {

  if (count == 0)
    xmove += 0.00065, zmove -= 0.0001, boff = 1, bleg = 0, bgood = 0; //printf("%d",count);

  if (count == 1)
    xmove += 0.00050, zmove -= 0.0001, boff = 0, bgood = 1, bleg = 0; //,printf("%d",count) ;

  if (count == 2)
    xmove += 0.00030, zmove -= 0.0001, boff = 0, bgood = 0, bleg = 1; //,printf("%d",count);

}

void bowled() {
  wicketangle = 5;
  selectwicket = rand() % 15;

  display();

  no_of_wickets++;
  printf("wickets= %d\n", no_of_wickets);
  delayfunc();

}

void keys(unsigned char key, int x, int y) {
  if (key == 'x') viewer[0] -= 1.0;
  if (key == 'X') viewer[0] += 1.0;
  if (key == 'y') viewer[1] -= 1.0;
  if (key == 'Y') viewer[1] += 1.0;
  if (key == 'z') viewer[2] -= 1.0;
  if (key == 'Z') viewer[2] += 1.0;
  display();
  if (key == 'r') reset();
  if (key == 's') {
    start = 1, no_of_balls++, printf("no of balls=%d\n", no_of_balls);
    if (no_of_balls > 5) no_of_overs++, no_of_balls = 0, printf("overs =%d", no_of_overs);
  }
  if (key == 'w');
  if (key == 27) exit(1);
}

void shot() {

  ymove -= 0.004;
  glutPostRedisplay();
  batangle = -.05;
  while (orthoadjust < 4)
    orthoadjust += .0000003;

}
void battingdirection() {
  if (boff && off) {
    ymove += .002;
    xmove += 0.03;
    zmove += 0.002;
    shot();

  } else if (bgood && front) {
    xmove -= 0.05;

    shot();
    //reset();
  } else if (bgood && back) {
    xmove += 0.00001;
    shot();
    //reset();
  } else if (bleg && leg) {
    xmove -= 0.01;

    shot();
    //reset();
  } else bowled();
  //bleg=boff=bgood=0;
}

void ballmove() {

  if (start) {

    //bowlerarmangle+=0.3;

    //	if(ymove<-1&&hit)hit=0;
    if (ymove > .4 && hit) {
      bowlerarmangle = -30;
      battingdirection();

    }

    //batangle=batangle-.001;
    else {
      bowlingdirection();

      ymove += .005;
      if (ymove < .65)

        glutPostRedisplay();

      else if (ymove > .65)

        bowled();
      //reset();

    }

  }

}
void batmove() {
  if (hit && ymove > 0.4) {
    batangle = batangle - .0001;

  }

}
void myReshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    glFrustum(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, 2.0, 20.0);
  else
    glFrustum(-2.0, 2.0, -2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, 2.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

void special(int key, int x, int y) {
  if (key == GLUT_KEY_UP) hit = 1, front = 1, leg = off = 0;
  if (key == GLUT_KEY_DOWN) hit = 1, back = 1, leg = off = 0;
  if (key == GLUT_KEY_LEFT) hit = 1, leg = 1, back = front = off = 0;
  if (key == GLUT_KEY_RIGHT) hit = 1, off = 1, leg = front = back = 0;
}
int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("color cube");
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keys);
  glutSpecialFunc(special);

  //glutIdleFunc(batmove);
  glutIdleFunc(ballmove);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}
