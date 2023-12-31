#include <GL/glut.h>
#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>

static double x=0.0;
static float help1=1;
static bool day= false;
static int grow=0;
static double angle=0;
static float lightIntensity=0;

void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void doInit()
{
	/* Background and foreground color */
 if(day){
	glClearColor(0.9,0.9,0.9,0.0);
	}else{
	glClearColor(0.3,0.3,0.3,0.0);
	}
	glColor3f(.0,1.0,1.0);
    glViewport(0,0,640,480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
}

void help(){
glPushMatrix();
glScaled(0.7,0.7,0.7);
stroke_output(-3,3,"Solar Power Energy Plant");
stroke_output(-3,2,"CGV mini project");
stroke_output(-3,1,"S to change between Day / Night");
stroke_output(-3,0,"H to open Menu");
glPopMatrix();

}

void drawHouse(int x,int y,int z){

glPushMatrix();
glTranslatef(x,y,z);
glScaled(0.5,0.5,0.5);
glColor3f(1,1,1);

	//House
glPushMatrix();
glTranslatef(0,0,-15);
glScaled(1,1,1);
glColor3f(1,1,1);
glutSolidCube(8);
glPopMatrix();

//House Door
glPushMatrix();
glTranslatef(0,-1.5,-8);
glScaled(.5,1.5,0.1);

if(day){
glColor3f(0,0,0);
}else{
	glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();

//House window1
glPushMatrix();
glTranslatef(2,-1.5,-8);
glScaled(.5,0.5,0.1);
if(day){
glColor3f(0,0,0);
}else{
 glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();


//House window2
glPushMatrix();
glTranslatef(-2,-1.5,-8);
glScaled(.5,0.5,0.1);
if(day){
glColor3f(0,0,0);
}else{
	glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();

//House roof
glPushMatrix();
glTranslatef(0,5,-15);
glScaled(1,.2,1);
glColor3f(0,0,1);
glutSolidCube(8);
glPopMatrix();


glPopMatrix();

}

void drawSolarPanel(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);

//Top panel
glPushMatrix();
glTranslatef(5,0,-15);
glRotatef(45,1,0,0);
glScaled(1,2,0.2);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(5,0,-14.5);
glRotatef(45,1,0,0);
glScaled(.5,2,0);
glColor3f(1,1,0);
glutWireCube(1);
glPopMatrix();

//horizontal wire frame on solar
glPushMatrix();
glTranslatef(4.9,0,-14.5);
glRotatef(45,1,0,0);
glScaled(1,1,0);
glColor3f(1,1,0);
glutWireCube(1);
glPopMatrix();

//Stand

glPushMatrix();
glTranslatef(5.5,-1,-16);
glScaled(0.1,2,0.2);
glColor3f(0,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

glPopMatrix();
}


void draw(){

 if(day){
	glClearColor(0.9,0.9,0.9,0.0);
	}else{
	glClearColor(0.3,0.3,0.3,0.0);
	}
 glPushMatrix();
 glRotatef(angle,1,0,0);
 glTranslatef(-10,20,-155);
 glScaled(1,1,0.6);
 if(day){
 glColor3f(1,1,0);
 }else{
 glColor3f(1,1,1);
 }
 glutSolidSphere(5,100,100);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(0,-10,5);
 glScaled(500,10,1000);
  glColor3f(0.8,0.7,0.7);
 glutSolidCube(1);
 glPopMatrix();

drawHouse(-3,0,-55);
drawHouse(-4,0,-35);
drawHouse(-5,0,-15);

drawHouse(-10,0,-15);

//Solar Panels
for(int i=-1;i<3;i++)
{
	for(int j=5;j>-2;j--)
        drawSolarPanel(i*2,1,j);

}

//draw power station.
stroke_output(0.8,1.8,"Power Station");

// transformer
glPushMatrix();
glTranslatef(15,5,-100);
//glScaled(0,2,0.2);
glColor3f(1,0.3,0.3);
glutSolidCube(15);
glPopMatrix();

//Transformer Power levels
if(day){
		if(grow<=15000){
	       grow++;
		   angle+=0.002;
		}
	}
	else{
		if(grow>=0){
	       grow--;
		   angle-=0.002;
		}
	}


	if(grow>1000){

		 		glPushMatrix();
				glTranslatef(14.8,-2,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

	if(grow>2000){

		 		glPushMatrix();
					glTranslatef(14.8,-1,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>3000){

		 		glPushMatrix();
					glTranslatef(14.8,0,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>4000){

		 		glPushMatrix();
					glTranslatef(14.8,1,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>5000){

		 		glPushMatrix();
				glTranslatef(14.8,2,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

	if(grow>6000){

		 		glPushMatrix();
				glTranslatef(14.8,3,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

	if(grow>7000){

		 		glPushMatrix();
				glTranslatef(14.8,4,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}


	if(grow>8000){

		 		glPushMatrix();
				glTranslatef(14.8,5,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

	if(grow>9000){

		 		glPushMatrix();
				glTranslatef(14.8,6,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

	if(grow>10000){

		 		glPushMatrix();
				glTranslatef(14.8,7,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}


if(grow>11000){

		 		glPushMatrix();
				glTranslatef(14.8,8,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}


if(grow>12000){

		 		glPushMatrix();
				glTranslatef(14.8,9,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>13000){

		 		glPushMatrix();
				glTranslatef(14.8,10,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>14000){

		 		glPushMatrix();
				glTranslatef(14.8,11,-99.8);
				glScaled(1,0.05,1);
				glColor3f(1,1,0);
				glutSolidCube(15);
				glPopMatrix();

			}

if(grow>15000){



			}


	}
void doDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);
	if(help1){
		help();
	}
	else
	{
	    draw();
	}
	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={100.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	/*GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f};
	GLfloat light_position[]={2.0f,5.0f,3.0f,1.0f};*/
	//if(day){
	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position2);


	GLfloat light_position3[]={0.0f,5.0f,15.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	/*}else{
	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.5f};
	GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position2);
	GLfloat light_position3[]={0.0f,2.0f,2.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	}*/
	glFlush();
	glutSwapBuffers();
}

void mykey(unsigned char key,int x,int y)
{
	if(key=='q'||key=='Q')
	{
		exit(0);
	}
	if(key=='h'||key=='H')
	{
		help1=!help1;
		glutPostRedisplay();

	}
	if(key=='s' || key=='S'){

		if(day){
		day=false;
		}else{
		day=true;
		}
	glutPostRedisplay();
	glutIdleFunc(doDisplay);
	}
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Solar power");
    glutDisplayFunc(doDisplay);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(mykey);
	doInit();
    glutMainLoop();
	return 0;
}
