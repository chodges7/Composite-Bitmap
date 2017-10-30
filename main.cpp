#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

//Prototypes for functions:
Bitmap userInput(string, int &howMany);
vector <vector <Pixel> > convertImage(Bitmap);
void saveImage(vector <vector <Pixel> >);
Bitmap combineImages(int);
vector <vector <Pixel> > applyToCavas(vector< vector <Pixel> >, vector <vector <Pixel> >);

int main(){

	vector <vector <Pixel> > canvas;
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
		else if (howMany == 10){
			done = true;
		}
		else{
			bmp = convertImage(userInput(name, howMany));
			
			//If it's the first time through, it resizes canvas
			if (howMany == 0){
				int rows = bmp.size();
				int columns = bmp[0].size();
				canvas.resize(rows);
				for (int index = 0; index < canvas.size(); index++){
					canvas[rows].resize(columns);
				}	
			}

			canvas = applyToCanvas(canvas, bmp);
			howMany++;
		}
	}
	while (done == false);
saveImage(canvas);
return 0;
}

vector <vector <Pixel> > applyToCanvas(vector <vector <Pixel> > canvas, vector <vector <Pixel> > bmp){
	Pixel rgb;
	Pixel crgb;

	for (int rodex = 0; rodex < canvas.size(); rodex++){
		for (int coldex = 0; coldex < canvas[rodex].size();coldex++){
			rgb = bmp[rodex][coldex];
			crgb = canvas[rodex][coldex];
			crgb.red = rgb.red + crgb.red;
			crgb.red = crgb.red / 2;
			crgb.blue = rgb.blue + crgb.blue;
			crgb.blue = crgb.blue / 2;
			crgb.green = rgb.green + crgb.green;
			crgb.green = crgb.green / 2;
			canvas[rodex][coldex] = crgb;
		}
	}
	return canvas;
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
	vector <vector <Pixel> > bmp;
	bmp = image.toPixelMatrix();
	return bmp;
}

void saveImage(vector <vector <Pixel> > bmp){
	Bitmap image;
	image.fromPixelMatrix(bmp);
	image.save("combinedImage.bmp");
}
