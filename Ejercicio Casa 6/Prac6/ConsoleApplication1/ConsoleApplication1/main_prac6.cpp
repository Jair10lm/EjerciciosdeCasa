//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno:Ramirez Hernandez Jose Angel Jair*****//
//*************	 Visual Studio 2015						******//
//*************  Grupo: 6								******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int lunaTierra = 0;
int marte = 0;
int lunaMarte1 = 0;
int lunaMarte2 = 0;
int jupiter = 0;
int lunaJupiter1 = 0;
int lunaJupiter2 = 0;
int lunaJupiter3 = 0;
int saturno = 0;
int anilloSaturno1 = 0;
int anilloSaturno2 = 0;
int urano = 0;
int lunaUrano1 = 0;
int lunaUrano2 = 0; 
float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glPushMatrix(); //Sistema solar

		

		glPushMatrix();//Dibujar el nucleo
			
			glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
			glutSolidSphere(1.5, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
			
		glPopMatrix();
	
			glPushMatrix();//Anillo rojo
			
				glRotatef(180, 1, 0, 0);   //Rotacion
				//glRotatef(sol, 0, 0, 1);
				glColor3f(1, 0, 0);	//Anillo Cafe
				glutSolidTorus(0.1, 2.8, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);
			
				glPushMatrix();//ATOMO

					glRotatef(jupiter, 0.0, 0.0, 1.0);	//Traslacion 
					glTranslatef(2.8, 0, 0);
					//glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca
					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);


				glPopMatrix();

			glPopMatrix();

			glPushMatrix(); //ANILLO VERDE

				glRotatef(45, 1, 0, 0);   //Rotacion
				//glRotatef(sol, 0, 0, 1);
				glColor3f(0, 1, 0);	//Anillo gris 
				glutSolidTorus(0.1, 3.0, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPushMatrix();//ATOMO

					glRotatef(marte, 0.0, 0.0, 1.0);	//Traslacion 
					glTranslatef(3.0, 0, 0);
					//glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca
					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);


				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//ANILLO AZUL

				glRotatef(90, 1, 0, 0);   //Rotacion
				//glRotatef(sol, 0, 0, 1);
				glColor3f(0, 0, 1);	//Anillo AZUL
				glutSolidTorus(0.1, 3.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

				glPushMatrix();//ATOMO

					glRotatef(tierra, 0.0, 0.0, 1.0);	//Traslacion 
					glTranslatef(3.2, 0, 0);
					//glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca
					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);


				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//ANILLO ROSA

				glRotatef(135, 1, 0, 0);   //Rotacion
				//glRotatef(sol, 0, 0, 1);
				glColor3f(1, 0.0, 0.25);	//Anillo Cafe
				glutSolidTorus(0.1, 3.4, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);


				glPushMatrix();//ATOMO

					glRotatef(venus, 0.0, 0.0, 1.0);	//Traslacion 
					glTranslatef(3.4, 0, 0);
					//glRotatef(venus, 0, 1, 0);   //Rotacion
					glColor3f(1, 1, 1);	//luna blanca
					glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H numero de vertices en plano horizontal ,V numero de vertices en el plano vertical);

					
				glPopMatrix();

			glPopMatrix();

	



	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360; //nunca va a llenarse la variable por lo cual al llegar a 360 se vuelve a inicar haciendo que gire 
		// sol - velocidad de despalzamiento

		mercurio = (mercurio - 1) % 360;

		venus = (venus - 2) % 360;

		tierra = (tierra - 3) % 360;

		marte = (marte - 4) % 360;

		jupiter = (jupiter - 5) % 360;

		saturno = (saturno - 6) % 360;

		urano = (urano - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
  case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
	  angleX += 2.0f;
	  break;
  case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
	  angleX -= 2.0f;
	  break;
  case GLUT_KEY_LEFT:
	  angleY += 2.0f;
	  break;
  case GLUT_KEY_RIGHT:
	  angleY -= 2.0f;
	  break;
  default:
	  break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1000, 1000);	// Tama�o de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion ); //indicamos que el programa se siga ejecutando hasta que sea presionada alguna tecla
  glutMainLoop        ( );          // 

  return 0;
}