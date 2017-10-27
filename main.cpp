#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput(string, int &index);
vector <vector <Pixel> > convertImage(Bitmap);
void saveImage(string &name, vector <vector <Pixel> >, int);
Bitmap combineImages(int);

string firstimage;
string secondimage;
string thirdimage;
string fourthimage;
string fifthimage;
string sixthimage;
string seventhimage;
string eigthimage;
string ninthimage;
string tenthimage;

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
			saveImage(name, bmp, index);
			howMany++;
		}
	}
	if (howMany == 0){
		cout << "No files were entered. Please try again.\n";
	}	
	if (howMany > 0){
		for (int imageNum = 0; imageNum < howMany; imageNum++){
			combineImages(imageNum);
		}
	}
}

Bitmap combineImages(int imageNum){
	Bitmap image;
	Bitmap secondImage;
	vector <vector <Pixel> > bmp;
	vector <vector <Pixel> > secondbmp;
	Pixel rgb;
	Pixel secondrgb;
	if (imageNum = 0){
		image.open(firstimage);
		secondImage(secondImage)
	}
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

void saveImage(string &name, vector <vector <Pixel> > bmp, int index){
	Bitmap image;

	if (index == 0){
		firstimage = name;
	}
	else if (index == 1){
		secondimage = name;
	}
	else if (index == 2){
		thirdimage = name;
	}
	else if (index == 3){
		fourthimage = name;
	}
	else if (index == 4){
		fifthimage = name;	
	}
	else if (index == 5){
		sixthimage = name;
	}
	else if (index == 6){
		seventhimage = name;
	}
	else if (index == 7){
		eigthimage = name;
	}
	else if (index == 8){
		ninthimage = name;
	}
	else if (index == 9){
		tenthimage = name;
	}

	image.fromPixelMatrix(bmp);
	image.save(name);
}
