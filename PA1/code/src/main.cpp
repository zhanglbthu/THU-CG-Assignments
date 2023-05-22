#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

#include "scene_parser.hpp"
#include "image.hpp"
#include "camera.hpp"
#include "group.hpp"
#include "light.hpp"

#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    for (int argNum = 1; argNum < argc; ++argNum)
    {
        std::cout << "Argument " << argNum << " is: " << argv[argNum] << std::endl;
    }

    if (argc != 3)
    {
        cout << "Usage: ./bin/PA1 <input scene file> <output bmp file>" << endl;
        return 1;
    }
    string inputFile = argv[1];
    string outputFile = argv[2]; // only bmp is allowed.

    // TODO: Main RayCasting Logic
    // First, parse the scene using SceneParser.
    // Then loop over each pixel in the image, shooting a ray
    // through that pixel and finding its intersection with
    // the scene.  Write the color at the intersection to that
    // pixel in your output image.
    SceneParser *parser = new SceneParser(inputFile.c_str());
    Camera *camera = parser->getCamera();
    Group *group = parser->getGroup();
    int w = camera->getWidth();
    int h = camera->getHeight();
    Image *image = new Image(w, h);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            // 发射光线
            Ray ray = camera->generateRay(Vector2f(i, j));
            Hit hit;
            // 计算光线与场景的交点
            bool isIntersected = group->intersect(ray, hit, 0);
            if (isIntersected)
            {
                // 根据交点处的材质属性计算该点的颜色
                Vector3f finalColor = Vector3f::ZERO;
                for (int li = 0; li < parser->getNumLights(); li++)
                {
                    Light *light = parser->getLight(li);
                    Vector3f L, lightColor;
                    light->getIllumination(ray.pointAtParameter(hit.getT()), L, lightColor);
                    finalColor += hit.getMaterial()->Shade(ray, hit, L, lightColor);
                }
                image->SetPixel(i, j, finalColor);
            }
            else
            {
                image->SetPixel(i, j, parser->getBackgroundColor());
            }
        }
    }
    image->SaveBMP(outputFile.c_str());
    delete image;
    delete parser;
    cout << "Hello! Computer Graphics!" << endl;
    return 0;
}
