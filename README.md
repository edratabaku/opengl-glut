Different examples of code and functions in opengl glut library including mouse and keyboard input functions and different 2d/3d animations.
Written for my Graphics class in 2020.

Steps to run code:
- Download freeglut and glut c header files.
- Download and install Dev C++.
- Open Dev C++ and go to the Tools tab > Compiler options.
- Add the following lines:
        - lglu32
        - lglut32
        - lopengl32
- Add code and run.

1- continousLine.cpp -> Creates a continous broken line for every user mouse click. <br/>
2- mainCircle.cpp -> Creates a red circle with a radius equal to the distance of a user's last two clicks. The center of the circle will be the coordinates of the first click in the last two clicks. <br/>
3- nonContinousLine.cpp -> Creates a new line that connects two points with coordinates of the user's last two clicks. <br/>
4- triangles.cpp -> Creates a yellow triangle from the user's last three clicks. If the user presses the key 'z' as keyboard input, the triangle will be empty (so only outlined). If the user presses the key 'm', the triangle will be filled. If the user presses the escape key (esc), the program will finish execution. <br/>
5- yoyomain.cpp -> Attempt to create a 3D animation of a yoyo with two sides: red and blue. When the yoyo reaches the ground, it will change side. <br/>
