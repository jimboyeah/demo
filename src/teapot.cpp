// #include <GL/gl.h>
// #include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdio>

using namespace std;

#define KEY_x               0x78  // [x,120]
#define KEY_s               0x73  // [s,115]
#define KEY_f               0x66  // [f,102]
#define KEY_ESC             0x1b  // [ESC,27]
#define KEY_1               0x31  // [1,49]
#define KEY_2               0x32  // [2,50]
#define KEY_3               0x33  // [3,51]
#define KEY_4               0x34  // [4,52]
#define KEY_5               0x35  // [5,53]
#define KEY_6               0x36  // [6,54]
#define KEY_7               0x37  // [7,55]
#define KEY_8               0x38  // [8,56]
#define KEY_9               0x39  // [9,57]

// typdef enum {Wired, Solid} Surface;
enum Surface { Wired=1100, Solid };
Surface WiredOrSolid = Wired;

enum Model { Cone, Tetrahedron, Cube, Dodecahedron, Icosahedron, Octahedron, Sphere, Torus, Teapot };
Model Mo = Teapot;

float distance = 0;

static void drawModel()
{
    float size = 0.5;
    float radius = 0.5;
    double base = 1.0;
    double height = 0.5;
    double width = 0.5;
    double innerRadius = 0.3;
    double outerRadius = 0.5;
    int slices = 5;
    int stacks = 4;
    int sides = 6;
    int rings = 5;

    if(WiredOrSolid==Wired)
    {
        switch (Mo)
        {
            case Cone: glutWireCone( base, height, slices, stacks ); break;
            case Cube: glutWireCube( size ); break;
            case Dodecahedron: glutWireDodecahedron( ); break;
            case Icosahedron: glutWireIcosahedron( ); break;
            case Octahedron: glutWireOctahedron( ); break;
            case Sphere: glutWireSphere( radius, slices, stacks ); break;
            case Teapot: glutWireTeapot( size ); break;
            case Tetrahedron: glutWireTetrahedron( ); break;
            case Torus: glutWireTorus( innerRadius, outerRadius, sides, rings ); break;
            default: std::cout << "No model\n";
        }
        return;
    }
    switch(Mo)
    {
        case Cone: glutSolidCone( base, height, slices, stacks ); break;
        case Cube: glutSolidCube( size ); break;
        case Dodecahedron: glutSolidDodecahedron( ); break;
        case Icosahedron: glutSolidIcosahedron( ); break;
        case Octahedron: glutSolidOctahedron( ); break;
        case Sphere: glutSolidSphere( radius, slices, stacks ); break;
        case Teapot: glutSolidTeapot( size ); break;
        case Tetrahedron: glutSolidTetrahedron( ); break;
        case Torus: glutSolidTorus( innerRadius, outerRadius, sides, rings ); break;
        default: std::cout << "No model\n";
    }
}

static void onRender(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawModel();
    glFlush(); // GLUT_SINGLE
    // glutSwapBUffers(); // GLUT_DOUBLE
}

static void SetupLights()
{
    GLfloat ambientLight[]  = {0.2f,  0.2f,  0.2f,  1.0f};//环境光源
    GLfloat diffuseLight[]  = {0.9f,  0.9f,  0.9f,  1.0f};//漫反射光源
    GLfloat specularLight[] = {1.0f,  1.0f,  1.0f,  1.0f};//镜面光源
    GLfloat lightPos[]      = {50.0f, 80.0f, 60.0f, 1.0f};//光源位置
 
    glEnable(GL_LIGHTING);                                //启用光照
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);       //设置环境光源
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);       //设置漫反射光源
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);     //设置镜面光源
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);          //设置灯光位置
    glEnable(GL_LIGHT0);                                  //打开第一个灯光
 
    glEnable(GL_COLOR_MATERIAL);                          //启用材质的颜色跟踪
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);    //指定材料着色的面
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);   //指定材料对镜面光的反应
    glMateriali(GL_FRONT, GL_SHININESS, 100);             //指定反射系数
}

static void init(void)
{
    glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
    SetupLights();
}

static void initMenu()
{
    glutAddMenuEntry("圆锥体", Cone);
    glutAddMenuEntry("四面体", Tetrahedron);
    glutAddMenuEntry("正方体", Cube);
    glutAddMenuEntry("正十二面体", Dodecahedron);
    glutAddMenuEntry("正二十面体", Icosahedron);
    glutAddMenuEntry("正八面体", Octahedron);
    glutAddMenuEntry("球体", Sphere);
    glutAddMenuEntry("圆环体", Torus);
    glutAddMenuEntry("茶壶", Teapot);
    glutAddMenuEntry("--------------", 0);
    glutAddMenuEntry("线框", Wired);
    glutAddMenuEntry("实体", Solid);
 
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

static void onMenu(int value)
{
    switch (value)
    {
        case Wired:
        case Solid:
        WiredOrSolid = (Surface)value;
        break;
        default:
        Mo = (Model)value;
    }
    glutPostRedisplay();
}

static void onKey(unsigned char key, int x, int y)
{
    switch(key)
    {
        case KEY_1: Mo = Cone; break;
        case KEY_2: Mo = Tetrahedron; break;
        case KEY_3: Mo = Cube; break;
        case KEY_4: Mo = Dodecahedron; break;
        case KEY_5: Mo = Icosahedron; break;
        case KEY_6: Mo = Octahedron; break;
        case KEY_7: Mo = Sphere; break;
        case KEY_8: Mo = Torus; break;
        case KEY_9: Mo = Teapot; break;

        case KEY_f:
        WiredOrSolid = Wired;
        break;

        case KEY_s:
        WiredOrSolid = Solid;
        break;

        case KEY_x:
        case KEY_ESC:
        exit(EXIT_SUCCESS);
        break;
    }
    glutPostRedisplay();

    const char *fmt = "#define KEY_%-16c0x%x  // [%c,%d]\n";
    int sz = std::snprintf(nullptr, 0, fmt, key, key, key, key);
    std::vector<char> buf(sz + 1); // note +1 for null terminator
    std::snprintf(&buf[0], buf.size(), fmt, key, key, key, key);
    std::cout << buf << std::endl;

    std::cout << "Model: " << Mo << std::endl;
}

static void onMove(int x, int y)
{
    printf("move to (%d, %d)\t", x, y);
}

static void onWheel( int wheel, int direction, int x, int y )
{
    distance += direction;
    printf("onWheel(%d, %d, %d, %d)\t", wheel, direction, x, y);
}

int main(int argc, char ** argv)
{
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("teapot");
    glutKeyboardFunc(onKey);
    glutDisplayFunc(onRender);
    // glutCreateMenu(onMenu);
    glutMotionFunc(onMove);
    glutMouseWheelFunc(onWheel);
    init();
    glutMainLoop();
    return 0;
}