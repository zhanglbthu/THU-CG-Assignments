#ifndef PLANE_H
#define PLANE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// Finish (PA2): Copy from PA1

class Plane : public Object3D
{
public:
    Plane()
    {
    }

    Plane(const Vector3f &normal, float d, Material *m) : Object3D(m)
    {
    }

    ~Plane() override = default;

    bool intersect(const Ray &r, Hit &h, float tmin) override
    {
        float denom = Vector3f::dot(norm, r.getDirection()); // 计算射线方向与平面法向的点积
        if (std::abs(denom) > 1e-6)
        {
            float t = (d - Vector3f::dot(norm, r.getOrigin())) / denom;
            if (t >= tmin && t < h.getT())
            {
                Vector3f normalAtIntersection = norm.normalized();
                if (denom > 0)
                {
                    normalAtIntersection = -normalAtIntersection;
                }
                h.set(t, material, normalAtIntersection);
                return true;
            }
        }
        return false;
    }

    void drawGL() override
    {
        Object3D::drawGL();
        Vector3f xAxis = Vector3f::RIGHT;
        Vector3f yAxis = Vector3f::cross(norm, xAxis);
        xAxis = Vector3f::cross(yAxis, norm);
        const float planeSize = 10.0;
        glBegin(GL_TRIANGLES);
        glNormal3fv(norm);
        glVertex3fv(d * norm + planeSize * xAxis + planeSize * yAxis);
        glVertex3fv(d * norm - planeSize * xAxis - planeSize * yAxis);
        glVertex3fv(d * norm + planeSize * xAxis - planeSize * yAxis);
        glNormal3fv(norm);
        glVertex3fv(d * norm + planeSize * xAxis + planeSize * yAxis);
        glVertex3fv(d * norm - planeSize * xAxis + planeSize * yAxis);
        glVertex3fv(d * norm - planeSize * xAxis - planeSize * yAxis);
        glEnd();
    }

protected:
    Vector3f norm;
    float d;
};

#endif // PLANE_H
