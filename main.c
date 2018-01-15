#include <GL/glut.h>
#include<math.h>

// Inicijalna sirina i visina prozora
#define WIDTH 640
#define HEIGHT 480



// Promenljive (globalne)
int u=0,o=-10,p=11,v=-5,b=6;

static GLfloat mov = 3.0f;
static int j,k,l,n;

// Prototipovi funkcija
static void on_init(int w, int h);
static void on_reshape(GLsizei w, GLsizei h);
static void on_display();
static void on_keyboard(unsigned char k, int x, int y);

int main(int argc, char** argv)
{
    
    GLfloat light_ambient[] = { 0.8, 0.0f, 0.0f, 1 };
    GLfloat light_diffuse[] = { 1, 1, 1, 1 };
    GLfloat light_specular[] = { 0.5, 0.5, 0.5, 1 };
    GLfloat model_ambient[] = { 0.1, 0, 0, 1 };
    GLfloat light_position[] = { -2.5f, 0.0f, 0.2f, 0.0f };
    
    glutInit(&argc, argv);

    // Postavljanje prozora
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (WIDTH, HEIGHT);
    glutCreateWindow ("Krvchish");

    // Callbacks        
    on_init(WIDTH, HEIGHT);
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
        
    glutPostRedisplay();
    glClearColor(0.3f, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    
    // Postavlja se osvetljenje
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        
    // Ulaz u glavnu petlju
    glutMainLoop();

    return 0;
}

static void on_init(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    on_reshape(w, h);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
// Upravljanje desavanjima usled promene velicine prozora
static void on_reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Pozicioniranje kamere
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,1000.0f);
    gluLookAt(-50, 0, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

// Funkcija za prikaz (renderovanje)
static void on_display()
{
    GLfloat ambients[] = { 0, 0, 0, 1 };
    GLfloat shininess = 10;
    GLfloat diff_black[] = { 0, 0, 0, 1 };
    GLfloat jedan[] = { 0.52, 0.8, 0.92, 1 };
    GLfloat tri[] = { 0.37, 0.8, 0.16, 1 };
    GLfloat diffuses[] = { 1, 1, 1, 1 };
        

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Postavlja se pozicija kamere
    gluPerspective(45.0f,(GLfloat)WIDTH/(GLfloat)HEIGHT,0.1f,1000.0f);
    gluLookAt(-50, 0, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Crtaju se plavi objekti (ivice)
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jedan);
        glTranslatef(0,18,500);
        glScalef(1,1,220);
        glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jedan);
        glTranslatef(0,-18,500);
        glScalef(1,1,220);
        glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jedan);
        glTranslatef(0,0,1040);
        glScalef(1,6.2,10);
        glutSolidCube(5);
    glPopMatrix();
    
    // Crtaju se zeleni objekti (virusi)
    for(j=25;j<=1000;j+=25){    
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, tri);
            glTranslatef(0,u,j);
            glutSolidIcosahedron();
        glPopMatrix();
    }
    for(k=50;k<=1000;k+=50){    
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, tri);
            glTranslatef(0,o,k);
            glutSolidDodecahedron();
            glTranslatef(0,5.4,0);
            glutSolidDodecahedron();
        glPopMatrix();
    }
    for(l=20;l<=1000;l+=20){    
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, tri);
            glTranslatef(0,p,l);
            glutSolidIcosahedron();
        glPopMatrix();
    }
    for(n=40;n<=1000;n+=40){    
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, tri);
            glTranslatef(0,b,n);
            glutSolidCube(0.7);
        glPopMatrix();
    }
    
    // Crta se Krvchish
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuses);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);
        glutSolidSphere(2,100,100);
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diff_black);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess);
            glRotatef(-45,0,1,0);
            glRotatef(-22,1,0,0);
            glTranslatef(0,0,1.8);
            glutSolidSphere(0.4,10,30);
        glPopMatrix();
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambients);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, jedan);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess);
            glRotatef(-46,0,1,0);
            glRotatef(-23,1,0,0);
            glTranslatef(0,0,1.98);
            glutSolidSphere(0.24,100,100);
        glPopMatrix();
    glPopMatrix();
    
    glutSwapBuffers();
}
// Upravljanje tasterima na tastaturi
static void on_keyboard(unsigned char k, int x, int y)
{
    switch (k) {
        case 27:
            exit(0);
            break;	
	
        case 's':
            mov-=0.5;
            break;
            
        case 'w':
            mov+=0.5;
            break;

            break;
        default:
            return;
    }

    glutPostRedisplay();
}
