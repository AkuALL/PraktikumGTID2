#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, palm = 0;
static int thumb = 0, index_finger = 0, middle_finger = 0, ring_finger = 0, pinky_finger = 0;

static float cam_rot_x = 25.0, cam_rot_y = 45.0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        
        // --- KONTROL KAMERA (POV) ---
        glRotatef(cam_rot_x, 1.0, 0.0, 0.0);
        glRotatef(cam_rot_y, 0.0, 1.0, 0.0);

        // Segment Bahu
        glTranslatef(-2.0, 0.0, 0.0); 
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.5, 0.6); 
            glutWireCube(1.0);      
        glPopMatrix();

        // Segment Siku
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 0.5);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Segment Telapak Tangan
        glTranslatef(1.0, 0.0, 0.0); 
        glRotatef((GLfloat) palm, 0.0, 0.0, 1.0); 
        glPushMatrix(); 
            glTranslatef(0.5, 0.0, 0.0); 
            glScalef(1.0, 0.3, 1.2); 
            glutWireCube(1.0);
        glPopMatrix();

        // --- BAGIAN 5 JARI ---
        // Ibu Jari
        glPushMatrix();
            glTranslatef(0.25, 0.0, 0.65); 
            glRotatef(45.0, 0.0, 1.0, 0.0); 
            glRotatef(60.0, 1.0, 0.0, 0.0); 
            glRotatef((GLfloat) thumb, 0.0, 0.0, 1.0); 
            glTranslatef(0.2, 0.0, 0.0); 
            glPushMatrix();
                glScalef(0.4, 0.15, 0.25); 
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // Jari Telunjuk
        glPushMatrix();
            glTranslatef(1.0, 0.0, 0.22);
            glRotatef((GLfloat) index_finger, 0.0, 0.0, 1.0);
            glTranslatef(0.25, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.5, 0.15, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // Jari Tengah
        glPushMatrix();
            glTranslatef(1.0, 0.0, 0.0);
            glRotatef((GLfloat) middle_finger, 0.0, 0.0, 1.0);
            glTranslatef(0.3, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.6, 0.15, 0.2); 
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // Jari Manis
        glPushMatrix();
            glTranslatef(1.0, 0.0, -0.22);
            glRotatef((GLfloat) ring_finger, 0.0, 0.0, 1.0);
            glTranslatef(0.25, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.5, 0.15, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

        // Jari Kelingking
        glPushMatrix();
            glTranslatef(1.0, 0.0, -0.45);
            glRotatef((GLfloat) pinky_finger, 0.0, 0.0, 1.0);
            glTranslatef(0.2, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.4, 0.15, 0.2);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -8.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; glutPostRedisplay(); break;
        case 'S': shoulder = (shoulder - 5) % 360; glutPostRedisplay(); break;
        case 'e': elbow = (elbow + 5) % 360; glutPostRedisplay(); break;
        case 'E': elbow = (elbow - 5) % 360; glutPostRedisplay(); break;
        case 'p': palm = (palm + 5) % 360; glutPostRedisplay(); break;
        case 'P': palm = (palm - 5) % 360; glutPostRedisplay(); break;
        case 't': thumb = (thumb + 5) % 360; glutPostRedisplay(); break;
        case 'T': thumb = (thumb - 5) % 360; glutPostRedisplay(); break;
        case 'j': index_finger = (index_finger + 5) % 360; glutPostRedisplay(); break;
        case 'J': index_finger = (index_finger - 5) % 360; glutPostRedisplay(); break;
        case 'm': middle_finger = (middle_finger + 5) % 360; glutPostRedisplay(); break;
        case 'M': middle_finger = (middle_finger - 5) % 360; glutPostRedisplay(); break;
        case 'r': ring_finger = (ring_finger + 5) % 360; glutPostRedisplay(); break;
        case 'R': ring_finger = (ring_finger - 5) % 360; glutPostRedisplay(); break;
        case 'k': pinky_finger = (pinky_finger + 5) % 360; glutPostRedisplay(); break;
        case 'K': pinky_finger = (pinky_finger - 5) % 360; glutPostRedisplay(); break;
        case 27: exit(0); break;
        default: break;
    }
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) cam_rot_y += 5;
    else if (key == GLUT_KEY_LEFT) cam_rot_y -= 5;
    else if (key == GLUT_KEY_UP) cam_rot_x += 5;
    else if (key == GLUT_KEY_DOWN) cam_rot_x -= 5;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan 3D");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys); 
    glutMainLoop();
    return 0;
}
