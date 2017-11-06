/*
    First, the program needs to take input from the user but only 10 times.
    
    Convert images from .bmp files into a matrix of pixels that our program
    can then use to apply to the canvas.

    After that the program needs to apply each of the new images, if they
    are usable to the canvas (a matrix that will be used as the .bmp file
    to apply all the pictues to).
    
    Then there needs to be a function to save the new canvas.bmp file to 
    composite-chodges7.bmp in the directory.
*/

#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
//Take in user input and verify it will work for our program.
Bitmap userInput(string, int &howMany);
//Convert image from a Bitmap to a matrix of Pixels.
vector <vector <Pixel> > convertImage(Bitmap);
//Saves matrix inputed as final composite image.
void saveImage(vector <vector <Pixel> >);
//Take in the canvas and new matrix and avg their values together.
vector <vector <Pixel> > applyToCanvas(vector< vector <Pixel> >, vector <vector <Pixel> >);

const int maxPics = 10;

int main(){

        vector <vector <Pixel> > canvas;
        bool sameSize = true;
        bool done = false;
        int howMany = 0;

        do {
                vector <vector <Pixel> > bmp;
                string name;

                //Limits amt of pictures you can enter
                if (howMany != maxPics){
                        cout << "Enter file name: ";
                        cin >> name;
                }
                //If someone types done or amt of images reaches 10 then the program stops
                if (name == "DONE" || name == "done" || howMany == 10){
                        done = true;
                }
                else{
                        //Turns entered name into Matrix of Pixels
                        bmp = convertImage(userInput(name, howMany));

                        //If it's the first time through, it makes sets up canvas
                        if (howMany == 0){
                                canvas = bmp;
                        }
                        else if (howMany != 0){
                                canvas = applyToCanvas(canvas, bmp);
                        }
                        if (sameSize == false){
                                //If during the applyToCanvas stage, the files were different sizes
                                //then it stops the program.
                                cout << "Please try again\n";				
                                return 0;
                        }
                        //Shows progress of program as images applied to canvas
                        cout << "File " << howMany + 1 << " applied to canvas.\n";
                        howMany++;
                }
        }
        //Once the done bool is ture it exits the do while loop
        while (done == false);

        //Couts that the program is done and saves image
        cout << "DONE! Please see composite-chodges7.bmp file for final output.\n";
        saveImage(canvas);
        return 0;
}

vector <vector <Pixel> > applyToCanvas(vector <vector <Pixel> > canvas, vector <vector <Pixel> > bmp){
        Pixel rgb;
        Pixel crgb;

        //If some of the files aren't the same size then the header file and this cout statement will tell you.
        if (canvas.size() != bmp.size() && canvas[0].size() != bmp[0].size()){
                cout << "\nSome of the .bmp files aren't the right sizes\n\n";	
        }
        else{	
                for (int rodex = 0; rodex < canvas.size(); rodex++){
                        int tempRed;
                        int tempBlue;
                        int tempGreen;
                        for (int coldex = 0; coldex < canvas[rodex].size();coldex++){
                                //This section of code can't be in a sep function because it uses too many
                                // of the variables that are just used in this function.
                                rgb = bmp[rodex][coldex];
                                crgb = canvas[rodex][coldex];
                                tempRed = rgb.red + crgb.red;
                                tempBlue = rgb.blue + crgb.blue;
                                tempGreen = rgb.green + crgb.green;
                                crgb.red = tempRed / 2;
                                crgb.blue = tempBlue / 2;
                                crgb.green = tempGreen / 2;
                                canvas[rodex][coldex] = crgb;
                        }
                }
                return canvas;
        }
}

Bitmap userInput(string name, int &howMany){
        Bitmap image;
        //Checks to see if file is correct format
        image.open(name);
        bool validBmp = image.isImage();

        if (validBmp == true){
                //This cout is mainly to show progress for the program.
                cout << "File " << howMany + 1 << " entered. ";
                return image;
        }
        if (validBmp == false){
                //If file isn't right, then the header file will send an error
                // and the program will ask again at the right index.
                howMany--;
        }
}

vector <vector <Pixel> > convertImage(Bitmap image){
        //Converts Bitmap file format into Pixel Matrix
        vector <vector <Pixel> > bmp;
        bmp = image.toPixelMatrix();
        return bmp;
}

//This function is to save the matrix of pixels at the end of the program
void saveImage(vector <vector <Pixel> > bmp){
        Bitmap image;
        image.fromPixelMatrix(bmp);
        image.save("composite-chodges7.bmp");
}
