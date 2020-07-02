// Example 1-3 : Double-Buffered Program: double.c
// http://www.glprogramming.com/red/chapter01.html

// #include <GL/gl.h>
// #include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static GLfloat spin = 0.0;

#define KEY_0               0x30  // [0,48]
#define KEY_9               0x39  // [9,57]
#define KEY_backtick        0x60  // [`,96]
#define KEY_minus           0x2d  // [-,45]
#define KEY_equal           0x3d  // [=,61]
#define KEY_squareR         0x5b  // [[,91]
#define KEY_squareL         0x5d  // [],93]
#define KEY_comma           0x2c  // [,,44]
#define KEY_period          0x2e  // [.,46]
#define KEY_div             0x2f  // [/,47]
#define KEY_slash           0x5c  // [\,92]
#define KEY_ESC             0x1b  // [ESC,27]
#define KEY_A               0x41  // [A,65]
#define KEY_B               0x42  // [B,66]
#define KEY_a               0x61  // [a,97]
#define KEY_b               0x62  // [b,98]
#define KEY_x               0x78  // [x,120]

#define FrameTimer          1
#define AnimationFrame      50

bool requestAnimationFrame = false;

float Width = 50;
float Height= 50;
float Depth = 1;


void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(spin, 0.0, 0.0, 1.0);
   glColor3f(1.0, 1.0, 1.0);
   glRectf(-25.0, -25.0, 25.0, 25.0);
   glPopMatrix();
   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-Width, Width, -Height, Height, -Depth, Depth);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity(); 
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glLoadIdentity();
}

void onFrame(int timerValue)
{
   spinDisplay();
   if(requestAnimationFrame)
   {
      glutTimerFunc(AnimationFrame, onFrame, FrameTimer);
   }
}

void mouse(int button, int state, int x, int y) 
{
   if (state != GLUT_DOWN) return;
   switch (button) {
      case GLUT_LEFT_BUTTON:
         glutIdleFunc(spinDisplay);
         requestAnimationFrame = false;
         break;
      case GLUT_RIGHT_BUTTON:
         glutIdleFunc(NULL);
         requestAnimationFrame = true;
         glutTimerFunc(AnimationFrame, onFrame, FrameTimer);
         break;
      default:
         break;
   }
}

void keyboard(unsigned char key, int x, int y) { 
    printf("#define KEY_%-16c0x%x  // [%c,%d] %f %f\n", key, key, key, key, Width, Depth);
    switch (key) { 
      case KEY_x:
      case KEY_ESC:
         exit(EXIT_SUCCESS); 
         break;
      case KEY_minus:
         Width -= 2;
         break;
      case KEY_equal:
         Width += 2;
         break;
      case KEY_squareL:
         Depth -= 0.2;
         break;
      case KEY_squareR:
         Depth += 0.2;
         break;
   }
}

/* i
 *  Request double buffer display mode.
 *  Register keyboard, mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(&display); 
   glutReshapeFunc(&reshape); 
   glutKeyboardFunc(&keyboard);
   glutMouseFunc(&mouse);
   glutMainLoop();
   return EXIT_SUCCESS;
}