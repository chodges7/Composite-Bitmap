#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput();
vector <vector <Pixel> > convertImage(Bitmap);

int main(){
        //Asks user for 10 images
        for (int index = 0; index <= 10; index++){
                vector <vector <Pixel> > bmp;

                bmp = convertImage(userInput());
                cout << "File " << index + 1 << " entered.\n";
        }
}


Bitmap userInput(){
        string name;
        Bitmap image;
           
        //Asks user for file name
        cout << "Enter file name: ";
        cin >> name;

        //Checks to see if file is correct format
        image.open(name);
        bool validBmp = image.isImage();
        
        if (validBmp == true){
                return image;
        }
        if (validBmp == false){
                cout << "Please enter a .bmp format file.\n";
        }
}

vector <vector <Pixel> > convertImage(Bitmap image){
        vector <vector <Pixel> > bmp;
        bmp = image.toPixelMatrix();
        return bmp;
}
