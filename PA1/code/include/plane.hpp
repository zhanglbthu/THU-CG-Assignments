#ifndef PLANE_H
#define PLANE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// TODO: Implement Plane representing an infinite plane
// function: ax+by+cz=d
// choose your representation , add more fields and fill in the functions

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
        float denom = Vector3f::dot(normal, r.getDirection()); // 计算射线方向与平面法向的点积
        if (std::abs(denom) > 1e-6)                         
        {
            float t = (d - Vector3f::dot(normal, r.getOrigin())) / denom;
            if (t >= tmin && t < h.getT())
            {
                Vector3f normalAtIntersection = normal.normalized();
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

protected:
    Vector3f normal; // 平面法向量
    float d;         // 平面到原点的距离
};

#endif // PLANE_H
