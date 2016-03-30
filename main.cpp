#include <gl/glut.h>

 GLfloat mat_diffuse[4] = { 0.5, 0.5, 0.5, 1.0 };
void init()
{
	//selecteaza culoarea de fond
	/*glClearColor(1,1,1,1);
	glShadeModel(GL_SMOOTH);*/
	/*GLfloat mat_specular[] = {1, 1, 1, 1};
	GLfloat mat_shininess= 50;
	GLfloat light_position[] = {1, 1, 1, 0};

	glClearColor(1, 1, 1, 1);
	glShadeModel(GL_FLAT); //GL_FLAT pentru culoare uniforma
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);*/

   
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH); //implicit
	glClearColor (0.0, 0.0, 0.0, 0.0);
}
/*void triangle()
{
// se va folosi glBegin() cu parametrul corespunzator pentru
//desenarea triunghiului

glBegin(GL_TRIANGLES);
glColor3d(1,0,0);
glVertex3f(20,20,0);
glColor3d(0,1,0);
glVertex3f(5,5,0);
glColor3d(0,0,1);
glVertex3f(20,5,0);
glEnd();


}*/
void sphere()
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1,40,50);
	glutSwapBuffers();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	//triangle();
	sphere();
	glFlush();
}
void reshape (int w, int h)
{
	/*glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
	gluOrtho2D(0, 30, 0, 30*(GLfloat)h/(GLfloat)w);
	else
	gluOrtho2D(0, 30*(GLfloat)w/(GLfloat)h, 0, 30);
	glMatrixMode(GL_MODELVIEW);*/
	/*glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-6); //pentru proiectie perspectiva*/

	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1, 20.0);
	/* if (w <= h)
	glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
	1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
	glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
	1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0); */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-6); //pentru proiectie perspectiva
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{ // schimba rosu
			mat_diffuse[0] += 0.1;
			if (mat_diffuse[0] > 1.0)
				mat_diffuse[0] = 0.0;
			glColor4fv(mat_diffuse);
			glutPostRedisplay();
		}
		break;
		//.....
		case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{ // schimba albastru
			mat_diffuse[2] += 0.1;
			if (mat_diffuse[2] > 1.0)
				mat_diffuse[2] = 0.0;
			glColor4fv(mat_diffuse);
			glutPostRedisplay();
		}
		break;
		case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
		{ // schimba verde
			mat_diffuse[1] += 0.1;
			if (mat_diffuse[1] > 1.0)
				mat_diffuse[1] = 0.0;
			glColor4fv(mat_diffuse);
			glutPostRedisplay();
		}
		break;
		
	}
}
	int main(int argc, char** argv)
	{
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		// Create and position the graphics window

		glutInitWindowSize(500,500);
		glutCreateWindow("Sfera");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutMouseFunc(mouse);
		glutMainLoop();
		return 0;
	} 