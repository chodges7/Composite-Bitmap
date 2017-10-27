#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput(string, int &index);
vector <vector <Pixel> > convertImage(Bitmap);
void saveImage(int, vector <vector <Pixel> >);

int main(){

        int howMany = 0;
        //Asks user for 10 images
        for (int index = 0; index < 10; index++){
                vector <vector <Pixel> > bmp;
                string name;

                cout << "Enter file name: ";
                cin >> name;
                if (name == "DONE" || name == "done"){
                        index = 10;
                }
                else{
                        bmp = convertImage(userInput(name, index));
                        saveImage(index, bmp);
                        howMany++;
                }
        }
        if (howMany == 0){
                cout << "No files were entered. Please try again.\n";
        }
        /*
        if (howMany > 0){
                for (int index = 0; index < howMany; index++){
                vector <vector <Pixel> > bmp;
                string name;
                bmp = convertImage();
                }
        }
        */
}


Bitmap userInput(string name, int &index){
        Bitmap image;
        //Checks to see if file is correct format
        image.open(name);
        bool validBmp = image.isImage();

        if (validBmp == true){
                cout << "File " << index + 1 << " entered.\n";
                return image;
        }
        if (validBmp == false){
                index--;
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
