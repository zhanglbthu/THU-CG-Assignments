#pragma once

#include <image.hpp>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>

class Element
{
public:
    virtual void draw(Image &img) = 0;
    virtual ~Element() = default;
};

class Line : public Element
{

public:
    int xA, yA;
    int xB, yB;
    Vector3f color;
    void draw(Image &img) override
    {
        int sx, sy, dx, dy, err;
        dx = abs(xB - xA);
        dy = abs(yB - yA);
        err = dx - dy;
        // sx和sy代表x和y的增量方向
        if (xA < xB)
            sx = 1;
        else
            sx = -1;
        if (yA < yB)
            sy = 1;
        else
            sy = -1;
        while (xA != xB || yA != yB)
        {
            img.SetPixel(xA, yA, color);
            int e2 = 2 * err;
            if (e2 > -dy)
            {
                err -= dy;
                xA += sx;
            }
            if (e2 < dx)
            {
                err += dx;
                yA += sy;
            }
        }
        //画终止点
        img.SetPixel(xB, yB, color);
        printf("Draw a line from (%d, %d) to (%d, %d) using color (%f, %f, %f)\n", xA, yA, xB, yB,
               color.x(), color.y(), color.z());
    }
};

class Circle : public Element
{

public:
    int cx, cy;
    int radius;
    Vector3f color;
    void draw(Image &img) override
    {
        int x = 0, y = radius;
        int d = 1 - radius;
        int deltaE = 3, deltaSE = -2 * radius + 5;
        while (x <= y)
        {
            img.SetPixel(cx + x, cy + y, color);
            img.SetPixel(cx + x, cy - y, color);
            img.SetPixel(cx - x, cy + y, color);
            img.SetPixel(cx - x, cy - y, color);
            img.SetPixel(cx + y, cy + x, color);
            img.SetPixel(cx + y, cy - x, color);
            img.SetPixel(cx - y, cy + x, color);
            img.SetPixel(cx - y, cy - x, color);
            if (d < 0)
            {
                d += deltaE;
                deltaE += 2;
                deltaSE += 2;
            }
            else
            {
                d += deltaSE;
                deltaE += 2;
                deltaSE += 4;
                y--;
            }
            x++;
        }
        printf("Draw a circle with center (%d, %d) and radius %d using color (%f, %f, %f)\n", cx, cy, radius,
               color.x(), color.y(), color.z());
    }
};

class Fill : public Element
{

public:
    int cx, cy;
    Vector3f color;
    void draw(Image &img) override
    {
        std::queue<std::pair<int, int>> q;
        q.push({cx, cy});
        Vector3f oldColor = img.GetPixel(cx, cy);
        int curX;
        int curY;
        while (!q.empty())
        {
            curX = q.front().first;
            curY = q.front().second;
            q.pop();
            if (img.GetPixel(curX, curY) != oldColor)
            {
                continue;
            }
            img.SetPixel(curX, curY, color);
            if (curX + 1 < img.Width() && img.GetPixel(curX + 1, curY) == oldColor)
            {
                q.push({curX + 1, curY});
            }
            if (curX - 1 >= 0 && img.GetPixel(curX - 1, curY) == oldColor)
            {
                q.push({curX - 1, curY});
            }
            if (curY + 1 < img.Height() && img.GetPixel(curX, curY + 1) == oldColor)
            {
                q.push({curX, curY + 1});
            }
            if (curY - 1 >= 0 && img.GetPixel(curX, curY - 1) == oldColor)
            {
                q.push({curX, curY - 1});
            }
        }
        printf("Flood fill source point = (%d, %d) using color (%f, %f, %f)\n", cx, cy,
               color.x(), color.y(), color.z());
    }
};