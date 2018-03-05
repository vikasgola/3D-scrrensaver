# Screensaver
The application displays a number of balls bouncing on the screen with some options to change properties of balls. 

##  Specifications
- The position, speed and colour of each ball is initially random.  
- The balls collide elastically with the walls,obstacles and also with each other.
- The terrain can be moved by some keys.
- We use a camera that moves in x direction and the focus point to see also moves in the same direction. 
- The speed of some ball can be increased or decreased by the user in the desired direction. The user can also pause or play or  escape from the application.

## System Requirements
ScreenSaver runs on Linux based platforms only. It requires the following packages :
- GNU gcc compiler
- OPENGL utility library
- pthread library

## Usage Instuctions

To run the main program, run:
``
make execute NUM_THREADS = N
``
Inside the GUI window, N number of bouncing balls will be seen on the screen.  Keyboard keys are included for various uses.

-	'Space' KEY : Pressing this button once will pause the movement of all the balls. Pressing it again will resume their movement.
- 'q' KEY:Pressing this button first time will increase the speed of all balls in +x direction(right) without pressing any number key.
     If you press any number key(1 to 9)then the speed of ball will increase in +x direction(right).
- 'a' KEY:Pressing this button first time will increase the speed of all balls in -x direction(left) without pressing any number key.
     If you press any number key(1 to 9)then the speed of ball will increase in -x direction(left).
- 'w' KEY:Pressing this button first time will increase the speed of all balls in +y direction(up) without pressing any number key.
     If you press any number key(1 t o 9)then the speed of ball will increase in +y direction(up).
- 's' KEY:Pressing this button first time will increase the speed of all balls in -y direction(down) without pressing any number key.
     If you press any number key(1 t o 9)then the speed of ball will increase in -y direction(down).
- 'e' KEY:Pressing this button first time will increase the speed of all balls in +z direction(towards the eye) without pressing any number key.
     If you press any number key(1 t o 9)then the speed of ball will increase in +z direction(towards the eye).
- 'd' KEY:Pressing this button first time will increase the speed of all balls in -z direction(away from eye) without pressing any number key.
     If you press any number key(1 t o 9)then the speed of ball will increase in -z direction(away from eye).
- 'Left Arrow' KEY:Pressing the button will move the camera in left direction.
- 'Right Arrow'KEY:Pressing the button will move the camera in right direction.
- 'g' KEY: This button increases gravity upto a certain limit.
- 'h'KEY:This button decreases gravity upto a certain limit 
- 'Escape':Close window
