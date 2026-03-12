// Nama : An Al Rivaldi
// NIM : 24060124120030

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

// =====================
// 		TUGAS 1 & 2
// =====================

    // 1. GL_POINTS
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2f(-8.0f, 8.0f);
        glVertex2f(-7.0f, 7.0f);
        glVertex2f(-6.0f, 8.0f);
    glEnd();

    // 2. GL_LINES 
    glColor3f(0.0f, 0.7f, 0.0f); // Hijau
    glBegin(GL_LINES);
        glVertex2f(6.0f, 8.0f);
        glVertex2f(9.0f, 7.0f);
    glEnd();

    // 3. GL_LINE_STRIP 
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glBegin(GL_LINE_STRIP);
        glVertex2f(-9.0f, 2.0f);
        glVertex2f(-8.0f, 4.0f);
        glVertex2f(-7.0f, 2.0f);
        glVertex2f(-6.0f, 5.0f);
    glEnd();

    // 4. GL_LINE_LOOP 
    glColor3f(0.5f, 0.0f, 0.5f); // Ungu
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.0f, 2.0f);
        glVertex2f(9.0f, 2.0f);
        glVertex2f(7.5f, 5.0f);
    glEnd();

    // 5. GL_TRIANGLE_FAN 
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-7.5f, -6.0f); 
        glVertex2f(-9.0f, -5.0f);
        glVertex2f(-8.0f, -8.0f);
		glVertex2f(-7.0f, -8.0f);
        glVertex2f(-6.0f, -5.0f);
    glEnd();

    // 6. GL_TRIANGLE_STRIP 
    glColor3f(0.0f, 0.8f, 0.8f); // Cyan
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(6.0f, -8.0f);
        glVertex2f(7.0f, -5.0f);
        glVertex2f(8.0f, -8.0f);
        glVertex2f(9.0f, -5.0f);
    glEnd();

    // 7. GL_QUAD_STRIP 
    glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-2.0f, 7.0f); 
        glVertex2f(-2.0f, 9.0f); 
        glVertex2f( 0.0f, 6.0f); 
        glVertex2f( 0.0f, 8.0f); 
        glVertex2f( 2.0f, 7.0f); 
        glVertex2f( 2.0f, 9.0f); 
    glEnd();
    
// =================
// 		TUGAS 3
// =================
    
   	// Baris Paling Atas (1 Kubus)
	glColor3f(0.0f, 0.0f, 0.5f); // Biru tua
    glRectf(-0.9f, 2.0f, 0.9f, 4.0f);
    
    // Baris Atas (2 Kubus)
    glRectf(-1.9f, 0.0f, -0.1f, 2.0f); 
    glRectf( 0.1f, 0.0f,  1.9f, 2.0f); 

    // Baris Tengah (3 Kubus)
    glRectf(-2.9f, -2.0f, -1.1f, 0.0f); 
    glRectf(-0.9f, -2.0f,  0.9f, 0.0f); 
    glRectf( 1.1f, -2.0f,  2.9f, 0.0f); 

    // Baris Bawah (2 Kubus)
    glRectf(-1.9f, -4.0f, -0.1f, -2.0f); 
    glRectf( 0.1f, -4.0f,  1.9f, -2.0f);

    // Baris Paling Bawah (1 Kubus)
    glRectf(-0.9f, -6.0f, 0.9f, -4.0f);

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Primitif OpenGL & Kubus Bertingkat");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glutMainLoop();
    return 0;
}
