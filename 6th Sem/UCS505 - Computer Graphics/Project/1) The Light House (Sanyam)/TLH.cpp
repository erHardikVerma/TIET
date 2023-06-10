
void SetPixel(int x, int y) {
    glVertex2f(x, y);
}

void Land() {
    if (isDayMode) {
        glColor3f(251.0/256,185.0/256,149.0/256);   //Light Brown
    }
    else {
        glColor3f(0.4101, 0.164, 0.164);     //Dark Brown

    }
    glBegin(GL_POLYGON);
    SetPixel(500, 0);
    SetPixel(1024, 0);
    SetPixel(1024, 300);
    SetPixel(500, 300);
    SetPixel(200, 0);
    glEnd();
}
void Lighthouse() {
    if (isDayMode) {
        glColor3f(1.0, 1.0, 1.0);   //White Base
    }
    else {
        glColor3f(0.7f, 0.7f, 0.7f);

    }
    glBegin(GL_POLYGON);
    SetPixel(740, 300);
    SetPixel(750, 350);
    SetPixel(850, 350);
    SetPixel(860, 300);
    glEnd();

    if (isDayMode) {
        glColor3f(1.0, 0.0, 0.0);   //Whole Red Body
    }
    else {
        glColor3f(0.5f, 0.0f, 0.0f);

    }
    glBegin(GL_POLYGON);
    SetPixel(750, 350);
    SetPixel(750, 500);
    SetPixel(850, 500);
    SetPixel(850, 350);
    glEnd();

    if (isDayMode) {
        glColor3f(1.0, 1.0, 1.0);   //White mid
    }
    else {
        glColor3f(0.7f, 0.7f, 0.7f);

    }
    glBegin(GL_POLYGON);
    SetPixel(750, 400);
    SetPixel(750, 450);
    SetPixel(850, 450);
    SetPixel(850, 400);
    glEnd();


    if (isDayMode) {
        glColor3f(1.0, 0.0, 0.0);   //Red Top
    }
    else {
        glColor3f(0.5f, 0.0f, 0.0f);

    }
    glBegin(GL_TRIANGLES);
    SetPixel(765, 540);
    SetPixel(800, 560);
    SetPixel(835, 540);
    glEnd();

    if (isDayMode) {
        glColor3f(1.0, 1.0, 1.0);   //White Portion under Triangle Top
    }
    else {
        glColor3f(0.7f, 0.7f, 0.7f);

    }
    glBegin(GL_POLYGON);
    SetPixel(775, 500);
    SetPixel(775, 540);
    SetPixel(825, 540);
    SetPixel(825, 500);
    glEnd();

    if (isDayMode) {
        glColor3f(0.5, 0.5, 0.5);   //Grey Railing
    }
    else {
        glColor3f(0.3, 0.3, 0.3);
    }
    glBegin(GL_POLYGON);
    SetPixel(750, 500);
    SetPixel(750, 510);
    SetPixel(755, 510);
    SetPixel(755, 500);
    glEnd();
    glBegin(GL_POLYGON);
    SetPixel(845, 500);
    SetPixel(845, 510);
    SetPixel(850, 510);
    SetPixel(850, 500);
    glEnd();
    glBegin(GL_POLYGON);
    SetPixel(795, 500);
    SetPixel(795, 510);
    SetPixel(805, 510);
    SetPixel(805, 500);
    glEnd();
    glBegin(GL_POLYGON);
    SetPixel(750, 510);
    SetPixel(750, 515);
    SetPixel(850, 515);
    SetPixel(850, 510);
    glEnd();
    float r = 7;
    for (int i = r; i > 0; i--)
    {
        float x = 0, y = i, xc = 800, yc = 525;
        //float p = 1 - r;
        float p = 3 - 2 * i;
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(2.0);
        glBegin(GL_POINTS);
        while (x <= y)
        {
            x++;
            if (p < 0)
            {
                //p = p + 2 * (x + 1) + 1;
                p = p + 4 * (x + 1) + 2;
            }
            else
            {
                y--;
                //p = p + 2 * (x + 1) + 1 - 2 * (y - 1);
                p = p + 4 * (x + 1) + 2 - 4 * (y - 1);
            }
            glVertex2i(xc + x, yc + y);
            glVertex2i(xc - x, yc + y);
            glVertex2i(xc + x, yc - y);
            glVertex2i(xc - x, yc - y);
            glVertex2i(xc + y, yc + x);
            glVertex2i(xc - y, yc + x);
            glVertex2i(xc + y, yc - x);
            glVertex2i(xc - y, yc - x);
        }
        glEnd();

    }
}
void SunorMoon() {
    int xc = 100, yc = 700;
    float r = 50;
    for (int i = r; i > 0; i--)
    {
        float x = 0, y = i;
        //float p = 1 - r;
        float p = 3 - 2 * i;
        if (isDayMode) {
            glColor3f(1.0, 1.0, 0.0);
        }
        else {
            glColor3f(0.9, 0.9, 0.9);

        }

        glPointSize(2.0);
        glBegin(GL_POINTS);
        while (x <= y)
        {
            x++;
            if (p < 0)
            {
                //p = p + 2 * (x + 1) + 1;
                p = p + 4 * (x + 1) + 2;
            }
            else
            {
                y--;
                //p = p + 2 * (x + 1) + 1 - 2 * (y - 1);
                p = p + 4 * (x + 1) + 2 - 4 * (y - 1);
            }
            glVertex2i(xc + x, yc + y);
            glVertex2i(xc - x, yc + y);
            glVertex2i(xc + x, yc - y);
            glVertex2i(xc - x, yc - y);
            glVertex2i(xc + y, yc + x);
            glVertex2i(xc - y, yc + x);
            glVertex2i(xc + y, yc - x);
            glVertex2i(xc - y, yc - x);
        }
        glEnd();

    }
}

void light() {

    glColor3f(1.0, 1.0, 0.0);//Yellow
    glBegin(GL_POLYGON);
    SetPixel(xpos, 200);
    SetPixel(xpos + d, 200);
    SetPixel(800, 525);
    glEnd();
}
void star(int x, int y, float col) {
    glColor3f(col, col, col);
    glBegin(GL_POINTS);
    SetPixel(x, y);
    SetPixel(x, y + 1);
    SetPixel(x, y + 2);
    SetPixel(x - 1, y + 1);
    SetPixel(x + 1, y + 1);
    SetPixel(x, y + 3);
    SetPixel(x, y - 1);
    SetPixel(x - 2, y + 1);
    SetPixel(x + 2, y + 1);
    glEnd();
}

void Water()
{
    if (isDayMode) {
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    else {
        glColor3f(0.0f, 0.0f, 0.3f);

    }
    glBegin(GL_POLYGON);
    float x = 500 + sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude;
    float y = waterHeight + sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed + M_PI / 2) * waveAmplitude;
    float x2 = sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed + M_PI / 2) * waveAmplitude;
    float y2 = waterHeight;
    SetPixel(-30, 0);
    SetPixel(500, 0);
    SetPixel(x, y);
    SetPixel( - 30 + x2, y2);
    glEnd();
}
void sky() {
    if (isDayMode) {
        glColor3f(0.529f, 0.808f, 0.922f);
    }
    else {
        glColor3f(0.0f, 0.0f, 0.2f);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    SetPixel(0, 0);
    SetPixel(1024, 0);
    SetPixel(1024, 768);
    SetPixel(0, 768);
    glEnd();
}

void boat() {
    
    glColor3f(0.6f, 0.0f, 0.2f);
    glBegin(GL_POLYGON);
    SetPixel(0 + boatx, 330 + boatx*0.002*sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    SetPixel(35 + boatx, 280 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    SetPixel(115 + boatx, 280 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    SetPixel(150 + boatx, 330 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    glEnd();
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    SetPixel(35 + boatx, 330 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    SetPixel(85 + boatx, 395 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    SetPixel(85 + boatx, 330 + boatx * 0.002 * sin(waveFrequency * glutGet(GLUT_ELAPSED_TIME) * waveSpeed) * waveAmplitude);
    glEnd();
}   
void boatleft() {
    if(boatx>0)
    boatx -= 0.001 * 1024;
}
void boatright() {
    if (boatx < 350)
    boatx += 0.001 * 1024;
}

void display()
{ 
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    sky();
    Lighthouse();
    if (isDayMode == false) {
        light();
        star(010, 750, col[0]);
        star(190, 675, col[1]);
        star(185, 590, col[2]);
        star(305, 700, col[3]);
        star(356, 685, col[4]);
        star(502, 650, col[5]);
        star(550, 725, col[6]);
        star(750, 700, col[7]);
        star(852, 750, col[8]);
        star(900, 640, col[9]);
    }
    boat();
    Water();
    Land();
    SunorMoon();
    glFlush();
}


void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}

void update(int value)
{
    for (int i = 0; i < n; i++) {
        col[i] = rand() / 32767.00;
    }
    if (moving_right) {
        xpos += 10;
        d += -3;
        if (xpos >= 500) {
            delay += 1;
            xpos -= 10;
            d += 3;

            if (delay == 10)
                moving_right = false;
        }
    }
    else {
        xpos -= 10;
        d += 3;
        if (xpos <= -300) {
            delay -= 1;
            xpos += 10;
            d += -3;
            if (delay == 0)
                moving_right = true;
        }
    }
    glutPostRedisplay();    // Request a redraw of the window
    glutTimerFunc(100, update, 0);    // Call update function after 100 milliseconds
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'm': // Switch to day mode
        isDayMode = true;
        break;
    case 'n': // Switch to night mode
        isDayMode = false;
        break;
    case 'a': // Move Boat Left
        boatleft();
        break;
    case 'd': // Move Boat Left
        boatright();
        break;
    }
}

int main(int argc, char** argv)
{   
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CG Project");
    myInit();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);    // Call update function immediately
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    

}
