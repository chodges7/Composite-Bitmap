#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput(string, int &howMany);
vector <vector <Pixel> > convertImage(Bitmap);
void saveImage(vector <vector <Pixel> >);
vector <vector <Pixel> > applyToCanvas(vector< vector <Pixel> >, vector <vector <Pixel> >);


int main(){

	vector <vector <Pixel> > canvas;
	bool sameSize = true;
	bool done = false;
	int howMany = 0;

	do {
		vector <vector <Pixel> > bmp;
		string name;

		cout << "Enter file name: ";
		cin >> name;

		if (name == "DONE" || name == "done"){
			done = true;
		}
		else if (howMany == 9){
			done = true;
		}
		else{
			//Turns entered name into Matrix of Pixels
			bmp = convertImage(userInput(name, howMany));

			//If it's the first time through, it resizes canvas
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
			cout << "File " << howMany + 1 << " applied to canvas.\n";
			howMany++;
		}
	}
	while (done == false);
	cout << "DONE! Please see canvas.bmp file for output.\n";
	saveImage(canvas);
	return 0;
}

vector <vector <Pixel> > applyToCanvas(vector <vector <Pixel> > canvas, vector <vector <Pixel> > bmp){
	Pixel rgb;
	Pixel crgb;

	if (canvas.size() != bmp.size() && canvas[0].size() != bmp[0].size()){
		cout << "Some of the .bmp files aren't the right sizes\n";	
	}
	else{	
		for (int rodex = 0; rodex < canvas.size(); rodex++){
			int tempRed;
			int tempBlue;
			int tempGreen;
			for (int coldex = 0; coldex < canvas[rodex].size();coldex++){
				rgb = bmp[rodex][coldex];
				crgb = canvas[rodex][coldex];
				tempRed = rgb.red + crgb.red;
				tempBlue = rgb.blue + crgb.blue;
				tempGreen = rgb.green + crgb.green;
				crgb.red = tempRed / 2;
				crgb.blue = tempBlue / 2;
				crgb.green = tempGreen / 2;
				canvas[rodex][coldex] = crgb;
				/*
				   rgb = bmp[rodex][coldex];
				   crgb = canvas[rodex][coldex];
				   crgb.red = rgb.red + crgb.red;
				   crgb.red = crgb.red / 2;
				   crgb.blue = rgb.blue + crgb.blue;
				   crgb.blue = crgb.blue / 2;
				   crgb.green = rgb.green + crgb.green;
				   crgb.green = crgb.green / 2;
				   canvas[rodex][coldex] = crgb;
				 */
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
		cout << "File " << howMany + 1 << " entered.\n";
		return image;
	}
	if (validBmp == false){
		howMany--;
	}
}

vector <vector <Pixel> > convertImage(Bitmap image){
	//Converts Bitmap file format into Pixel Matrix
	vector <vector <Pixel> > bmp;
	bmp = image.toPixelMatrix();
	return bmp;
}

void saveImage(vector <vector <Pixel> > bmp){
	Bitmap image;
	image.fromPixelMatrix(bmp);
	image.save("combinedImage.bmp");
}
