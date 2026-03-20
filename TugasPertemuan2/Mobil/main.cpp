#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void drawCircle(float radius, int segments) {
    glBegin(GL_POLYGON);
    float angle;
    for (int i = 0; i < segments; i++) {
        angle = 2 * PI * i / segments;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
}

void drawWheel() {
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle(0.15f, 40);
    
    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(0.08f, 30);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    for(int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotated(i * 45.0, 0.0, 0.0, 1.0); 
        glBegin(GL_LINES);
        glVertex2f(-0.08f, 0.0f);
        glVertex2f(0.08f, 0.0f);
        glEnd();
        glPopMatrix();
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Jalan Raya
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.4f); glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -1.0f);  glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Posisi Mobil
    glPushMatrix(); 
    glTranslatef(-0.1f, -0.1f, 0.0f); 

    // Bodi bawah
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, -0.1f); glVertex2f(0.6f, -0.1f);
    glVertex2f(0.6f, 0.15f);  glVertex2f(-0.6f, 0.15f);
    glEnd();

    // Bodi atas / Kabin
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f, 0.15f); glVertex2f(0.3f, 0.15f);
    glVertex2f(0.1f, 0.35f);  glVertex2f(-0.2f, 0.35f);
    glEnd();

    // Jendela belakang
    glColor3f(0.5f, 0.8f, 0.9f); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.35f, 0.17f); glVertex2f(-0.05f, 0.17f);
    glVertex2f(-0.05f, 0.32f); glVertex2f(-0.18f, 0.32f);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f); 
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.35f, 0.17f); glVertex2f(-0.05f, 0.17f);
    glVertex2f(-0.05f, 0.32f); glVertex2f(-0.18f, 0.32f);
    glEnd();
    
    // Jendela depan
    glColor3f(0.5f, 0.8f, 0.9f); 
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.17f);  glVertex2f(0.25f, 0.17f);
    glVertex2f(0.08f, 0.32f); glVertex2f(0.0f, 0.32f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 0.17f);  glVertex2f(0.25f, 0.17f);
    glVertex2f(0.08f, 0.32f); glVertex2f(0.0f, 0.32f);
    glEnd();

    // Detail Bodi dan Pintu
    glColor3f(0.0f, 0.0f, 0.0f); 
    glLineWidth(2.0f); 

    // Outline bodi bawah
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6f, -0.1f); glVertex2f(0.6f, -0.1f);
    glVertex2f(0.6f, 0.15f);  glVertex2f(-0.6f, 0.15f);
    glEnd();

    // Outline kabin
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, 0.15f); glVertex2f(0.3f, 0.15f);
    glVertex2f(0.1f, 0.35f);  glVertex2f(-0.2f, 0.35f);
    glEnd();

    // Garis pemisah pintu
    glBegin(GL_LINES);
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, 0.35f);
    glEnd();

    // Gagang Pintu
    glBegin(GL_POLYGON);
    glVertex2f(-0.08f, 0.11f); glVertex2f(-0.04f, 0.11f);
    glVertex2f(-0.04f, 0.13f); glVertex2f(-0.08f, 0.13f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(0.04f, 0.11f); glVertex2f(0.08f, 0.11f);
    glVertex2f(0.08f, 0.13f); glVertex2f(0.04f, 0.13f);
    glEnd();

    // Lampu Depan
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.58f, 0.0f); glVertex2f(0.62f, 0.0f);
    glVertex2f(0.62f, 0.1f); glVertex2f(0.58f, 0.1f);
    glEnd();

    // Roda Belakang
    glPushMatrix();
    glTranslatef(-0.35f, -0.1f, 0.0f);
    drawWheel();
    glPopMatrix();

    // Roda Depan
    glPushMatrix();
    glTranslatef(0.35f, -0.1f, 0.0f);
    drawWheel();
    glPopMatrix();

    glPopMatrix(); 

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mobil 2D"); 
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutMainLoop();
    return 0;
}
