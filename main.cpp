#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
//#include <exception>
#include <iostream>
//#include "Tests.h"
#include "Image.h"
//#include "ImageProcessing.h"
#include "BrightnessandControl.h"
#include "GammaCorrection.h"
#include "Convultion.h"
#include "DrawingModule.h"
//#include "Point.h"
//#include "Size.h"
//#include "Rectangle.h"
using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::ifstream;
using std::invalid_argument;

int Sobel(int x) {
    //scaling function for Sobel kernels
    return x / 16 + 255 / 2;
}

int Identity(int x) {
    return x;
}

int Blur(int x) {
    return x / 9;
}

int GaussianBlur(int x) {
    return x / 16;
}

float ReadNumber()
{
    cout << "\nOption: ";
    string s;
    getline(cin, s);
    return std::stof(s);
}

float ReadNumber( string o)
{
    cout << o;
    string s;
    getline(cin, s);
    return std::stof(s);
}

void ImageOptions(Image& img)
{
    Image tmp;
    string img_commands = "\n1 - Display all commands."
                          "\n2 - Display current image."
                          "\n3 - Load from default input file (TestImage4.txt)."
                          "\n4 - Save to default output file (Poza1.ascii.pgm)."
                          "\n5 - Load from given file."
                          "\n6 - Save to given file."
                          "\n0 - Exit."
                          "\n";
    int option = 1;
    cout << img_commands;
    while (option != 0)
    {
        float option = ReadNumber();
        if (option == 1)
        {
            cout << img_commands;
        }
        if (option == 2)
        {
            cout << img;
        }
        if (option == 3)
        {
            if (tmp.load("Poza2.ascii.pgm"))
            {
                img = tmp;
            }
        }
        if (option == 4)
        {
            img.save("Poza1.ascii.pgm");
        }
        if (option == 5)
        {
            string s;
            getline(cin, s);
            if (tmp.load(s))
            {
                img = tmp;
            }
            else throw invalid_argument("Invalid file!");
        }
        if (option == 6)
        {
            string s;
            getline(cin, s);
            bool b = img.save(s);
            if (!b)throw invalid_argument("Invalid file!");
        }
        if (option == 7) {
            unsigned int x;
            x = int(ReadNumber("X: "));
            unsigned int y =  int(ReadNumber("Y: "));
            unsigned int width =  int(ReadNumber("Width: "));
            unsigned int height = int(ReadNumber("Height: "));
            img.getROI(tmp, x, y, width, height);
            cout << tmp;
        }
        if (option > 7)throw invalid_argument("Invalid option!");
    }
}

void ProcOptions(Image& img)
{
    Image tmp;
    tmp = img;
    BrightnessandControl adj{ 5,5 };
    GammaCorrection corr{ 2 };
    int kernel[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            kernel[i][j] = 1;
    Convultion conv{Identity, kernel};
    string proc_commands = "\n1 - Display commands.\n2 - Display image.\n3 - Adjust image (saves result in Poza2.ascii.pgm).\n4 - Correct image (saves result in Poza2.ascii.pgm).\n5 - Convolute image (saves result in Poza2.ascii.pgm).\n6 - Change adjustment params.\n7 - Change correction params.\n8 - Change convolution params.\n0 - Exit.\n";
    unsigned int option = 1;

    while (option != 0)
    {
        cout << proc_commands;

        option = int(ReadNumber());

        if (option == 1)
        {
            cout << proc_commands;
        }

        if (option == 2)
        {
            cout << tmp;

        }

        if (option == 3)
        {

            adj.process(img, tmp);
            bool b=tmp.save("Poza2.ascii.pgm");
            img = tmp;


        }

        if (option == 4)
        {
            corr.process(img, tmp);
            bool b=tmp.save("Poza2.ascii.pgm");
            //img = tmp;
        }

        if (option == 5)
        {
            conv.process(img, tmp);
            bool b=tmp.save("Poza2.ascii.pgm");
            img = tmp;


        }

        if (option == 6)
        {
            float alfa, beta;
            alfa = ReadNumber("Alfa: ");
            beta = ReadNumber("BEta: ");
            adj = BrightnessandControl(alfa, beta);

        }

        if (option == 7)
        {
            float gamma = ReadNumber("Gamma: ");
            corr = GammaCorrection(gamma);
        }

        if (option == 8)
        {
            cout << "\n0 - Identity conv.\n1 - Blur conv.\n2 - Gaussian blur conv.\n3 - Vertical Sobel conv.\n4 - Horizontal Sobel conv.\n";
            int opt =  int(ReadNumber());
            if (opt > 4)throw invalid_argument("Invalid input!");

            if (opt == 0)
            {
                int k[3][3] = { 0 };
                k[1][1] = 1;
                conv = Convultion{ Identity,k };
            }

            if (opt == 1)
            {
                int k[3][3];
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        k[i][j] = 1;
                    }
                }
                conv = Convultion{ Blur,k };

            }

            if (opt == 2)
            {
                int k[3][3];
                k[0][0] = 1;
                k[2][0] = 1;
                k[2][2] = 1;
                k[0][2] = 1;
                k[1][1] = 4;
                k[0][1] = 2;
                k[1][0] = 2;
                k[1][2] = 2;
                k[2][1] = 2;
                conv = Convultion{ GaussianBlur,k };

            }

            if (opt == 3)
            {
                int k[3][3] = { 0 };
                k[0][0] = 1;
                k[2][0] = 1;
                k[0][2] = -1;
                k[2][2] = -1;
                k[1][0] = 2;
                k[1][2] = -2;
                conv = Convultion{ Sobel,k };

            }

            if (opt == 4)
            {
                int k[3][3] = { 0 };
                k[0][0] = 1;
                k[0][2] = 1;
                k[0][1] = 2;
                k[2][1] = -2;
                k[2][0] = -1;
                k[2][2] = -1;
                conv = Convultion{ Sobel,k };

            } cout<<img<<std::endl;
            cout<<tmp<<std::endl;

        }

        if (option > 8)throw invalid_argument("Invalid input!");
    }
}

void DrawOptions(Image& img)
{
    DrawingModule draw;
    unsigned int opt = 1;
    string commands = "\n1) Display commands."
                           "\n2) Display image."
                           "\n3) Draw a circle. (saves result in Poza2.ascii.pgm)."
                           "\n4)  Draw a line (saves result in Poza2.ascii.pgm)."
                           "\n5) Draw a rectangle (saves result in Poza2.ascii.pgm)."
                           "\n0)- Exit.\n";
    cout << commands;
    Image tmp;

    while (opt != 0) {

        opt =  int(ReadNumber());

        if (opt == 1) {
            cout << commands;
        }

        if (opt == 2) {
            cout << img;
        }

        if (opt == 3) {
            tmp = img;
            int x = int(ReadNumber("X: "));
            int y = int(ReadNumber("Y: "));
            int radius = int(ReadNumber("Radius: "));
           //unsigned int color = int(ReadNumber("Color: "));
            draw.drawCircle(tmp, Point(x, y), radius);
            tmp.save("Poza2.ascii.pgm");
            img = tmp;
        }

        if (opt == 4) {
            tmp = img;
            int x1 = int(ReadNumber("X1: "));
            int y1 = int(ReadNumber("Y1: "));
            int x2 = int(ReadNumber("X2: "));
            int y2 = int(ReadNumber("Y2: "));
           // unsigned int color = int(ReadNumber("Color: "));
            draw.drawLine(tmp, Point(x1, y1), Point(x2,y2));
            tmp.save("Poza2.ascii.pgm");
            img = tmp;
        }

        if (opt == 5) {
            tmp = img;
            int x1 = int(ReadNumber("X1: "));
            int y1 = int(ReadNumber("Y1: "));
            int x2 = int(ReadNumber("X2: "));
            int y2 = int(ReadNumber("Y2: "));
            //unsigned int color = int(ReadNumber("Color: "));
            draw.drawRectangle(tmp, Point(x1, y1), Point(x2, y2));
            tmp.save("Poza2.ascii.pgm");
            img = tmp;
        }
    }
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        Image current{ 15,15 };
        int option = 1;
        string commands = "1 - Image commands."
                          "\n"
                          "2 - Image processing commands\n"
                          "3 - Drawing commands\n"
                          "0 - Exit.\n";

        while (option != 0)
        {
            cout << commands;

            try
            {
                option = int(ReadNumber());

                if (option == 1)
                {
                    ImageOptions(current);
                }

                if (option == 2)
                {
                    ProcOptions(current);
                }
                if(option == 3)
                {
                    DrawOptions(current);
                }

                if (option > 3)throw invalid_argument("Invalid option!");
            }
            catch (...)
            {
                cout << "An error occurred.\n";
            }
        }
    }

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}