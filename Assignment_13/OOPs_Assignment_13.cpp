#include<iostream>
#include<Windows.h>
#include<GL/glut.h>
#include<string>
#include<sstream>
using namespace std;
int capacity = 10;
 
int array[10] = {};
int data;
	static int Qsize = 0;
 
void display()
{
 	int x=50;
 	glClear(GL_COLOR_BUFFER_BIT);  //clear all pixels
 	//performms the clear operation on one or more buffer at the same time
 	glPointSize(10.0);
 	glColor3f(1.0,0.0,0.0);//gives the colour to the Number
 
 	for(int j = 0; j < Qsize; j++){
 
 	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
 	//drawing premitive commds between glBegin() and glEnd()
 	glBegin(GL_POLYGON);
 	glVertex2f(x,100); //a vertex with 2  point coordinate
 	glVertex2f(x+50,100);
 	glVertex2f(x+50,50);
 	glVertex2f(x,50);
 	glEnd();
 
 	glRasterPos2f(x+10, 70);
 
 	int val = array[j];
 	ostringstream stream;
 	stream<<val;
 	string s = stream.str();
 	for(int i= 0; i<3;i++){
 	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,
s[i]);
 	}
	x+=70;
 	}
 	glutSwapBuffers();
 	glPopMatrix();
 	glEnd();
 	glFlush();  //forces excution before the gathering is completed
}
 //Element is added  from rear end
 void enQueue(){
 if(Qsize<10){
 cout<<"Enter number to be added in queue: ";
 cin>>data;
 array[Qsize] = data; //add elelemt at rear part
 Qsize += 1;
 }
 else{
 cout<<"Queue Overflow"<<endl;
 }
}
//In Dequeue each element is removed from front end
void deQueue(){
if(Qsize > 0){
	for(int i=0;i<=Qsize-1;i++)
 	{
 		array[i]=array[i+1]; //shifting each element 
 	}
 	cout<<"Element deleted successfully!"<<endl;
 	Qsize -= 1;
}
else{
	cout<<"Queue UnderFlow!"<<endl;
}
 }
 
 void keyboard(unsigned char key, int x, int y)
 {
 switch (key)
 {
 case 'e' | 'E': enQueue(); display();
 break;
 
 case 'd' | 'D': deQueue(); display();
 break;
 case 'x' | 'X': exit(0);
 }
}
 void init()
 {
 glClearColor(1,1,1,1);
 }
 //call when the user  changes the size of the window 
 void reshape(int w, int h)
 {
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 //Initilize viewing vaule
 glLoadIdentity();
 gluOrtho2D(0,500,0,500);
 glMatrixMode(GL_MODELVIEW);
 }

 int main(int argc, char*argv[])
 {
 
 int option = 1;
 
 //Queue element;
 while(7>option>0){
 cout<<"\n\n<---------- MENU ---------->"<<endl;
 cout<<"Enter operation to be performed on queues: "<<endl;
 cout<<"1. EnQueue \n2. DeQueue \n3. Size of Queue \n4. Display"<<endl;
 cout<<"Enter option (0 to exit): ";
 cin>>option;
 switch(option){
 case 1: enQueue();
 break;
 case 2: deQueue();
 break;
 case 3: cout<<"Total element/s in queue is/are: "<<Qsize;
 break;
 case 4: glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glColor3f(1.0,1.0,1.0);  //Give white color to back ground
 //decleare intilize window size ,position and display mode.Open Window with Queue Using Opengl in its title bar
 //call intializeing routine.Register callback function to display graphics.Enter the main loop and process events
 glutInitWindowPosition(350,50);
 glutInitWindowSize(800,600);
 glutCreateWindow("Queues Using OpenGL");
 glClearColor(1.0f,0.0f,0.0f,1.0f);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);  //to register the function call and handle keyword
 glutReshapeFunc(reshape);  
 init();
 glutMainLoop();
  glClearColor(1.0f,0.0f,0.0f,1.0f);
 break;
 default: cout<<"Program ended successfully!"<<endl;
 break;
 }
 }
 return 0;
}
