#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput(string);
vector <vector <Pixel> > convertImage(Bitmap);
void saveImage(int, vector <vector <Pixel> >);

int main(){
        //Asks user for 10 images
        for (int index = 0; index <= 10; index++){
                vector <vector <Pixel> > bmp;
                string name;

                cout << "Enter file name: ";
                cin >> name;
                if (name == "DONE" || name == "done"){
                        index = 10;
                }
                else{
                        bmp = convertImage(userInput(name));
                        cout << "File " << index + 1 << " entered.\n";

                        saveImage(index, bmp);
                }
        }
}


Bitmap userInput(string name){
        Bitmap image;

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

void saveImage(int index, vector <vector <Pixel> > bmp){
        Bitmap image;
        string name;

        if (index == 0){
                name = "1.bmp";
        }
        else if (index == 1){
                name = "2.bmp";
        }
        else if (index == 2){
                name = "3.bmp";
        }
        else if (index == 3){
                name = "4.bmp";
        }
        else if (index == 4){
                name = "5.bmp";
        }
        else if (index == 5){
                name = "6.bmp";
        }
        else if (index == 6){
                name = "7.bmp";
        }
        else if (index == 7){
                name = "8.bmp";
        }
        else if (index == 8){
                name = "9.bmp";
        }
        else if (index == 9){
                name = "10.bmp";
        }
        image.fromPixelMatrix(bmp);
        image.save(name);
}
