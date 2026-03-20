#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.2f, 0.5f, 0.8f); 
    
    glBegin(GL_POLYGON);
    GLint circle_points = 100;
    int i;
    float angle;
    float radius = 0.5f;
    
    for (i = 0; i < circle_points; i++) {
        angle = 2 * PI * i / circle_points;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
    
    glFlush();
}

// Fungsi main persis seperti yang diminta
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutMainLoop();
    return 0;
}
