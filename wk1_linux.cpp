// This is a simple, introductory OpenGL program.
// 
// This is a slightly modified version of the file posed on Oasis
// as "wk1" on the CMT2319 course's page. The only soruce code modification
// is that this file includes different headers - other differences include
// only comments and code style.
//
// Compiling this file on linux is surprisingly easy.
// 
// First, you need to make sure you have the following stuff on your system:
//      - OpenGL header files( glut.h, glu.h - they're usually in /usr/include )
//      - OpenGL libraries( binaries )( usually in /usr/lib )
//      - C++ compiler( g++ )
// 
// If you don't have the headers or lib's, you can get them by installing
// freeglut - type 'sudo apt-get install freeglut-dev' at the command line.
// g++ can be installed by this command: 'sudo apt-get install g++'
//
// Second, we need to tell the compiler where to find the headers and the lib's.
// On Linux, g++ first looks for header files in "/usr/include". The headers we
// need are in the "/usr/include/GL" folder - therefore, #include <GL/glut.h>.
// Libraries are specified by passig command line arguments to the compiler.
// This simple example needs code from glut and glu libraries - we tell this to
// the compiler by specifying '-lglut' and '-lglu' as arguments.
//
// Also, it's recommended to give the executable the compiler generates a
// meaningfull name - such as "hello"( by default, the compiler will name
// executables "a.out" ). We do this by using another command line argument:
// '-o hello'
//
// We end up with the following command:
// g++ -o hello wk1_linux.cpp -lglut -lglu
// ( I'm assuming the file you're trying to complie is called
// "wk1_linux.cpp" and it's in the current directory. )
//
// After executing it, you should have a brand new file named "hello".
// You can run the file by entering "./hello" at the command line.    
//
#include <GL/glut.h>
#include <GL/glu.h>


void display( void )
{
    // clear all pixels
    glClear( GL_COLOR_BUFFER_BIT );

    // set line colour red( r=1, g=0,b=0 ).
    glColor3f( 1.0, 0.0, 0.0 );

    // draw a line from point( 100,150 ) to point( 200, 300 )
    glBegin( GL_LINES );
    glVertex2i( 100,150 );
    glVertex2i( 200,300 );
    glEnd();

    // keep showing( flushing ) line on the screen instead of showing just once.
    glFlush();
    // glutPostRedisplay();
}

void init( void )
{
    // select clearing color
    glClearColor( 0.0, 0.0, 0.0, 0.0 );

    // initialize viewing values
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0,500,0,500 );
}

// Declare initial window size, position, and display mode
//( single buffer and RGBA ).  Open window with "hello"
// in its title bar.  Call initialization routines.
// Register callback function to display graphics.
// Enter main loop and process events.
int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( 500, 500 );
    glutInitWindowPosition( 100, 100 );
    glutCreateWindow( "Hello" );
    init();
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;   // ANSI C requires main to return int.
}
