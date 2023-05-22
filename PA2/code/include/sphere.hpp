#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>
#include <glut.h>

// Finish (PA2): Copy from PA1

class Sphere : public Object3D
{
public:
    Sphere()
    {
        // unit ball at the center
        center = Vector3f(0, 0, 0);
        radius = 1.0f;
    }

    Sphere(const Vector3f &center, float radius, Material *material) : Object3D(material)
    {
        //
        this->center = center;
        this->radius = radius;
    }

    ~Sphere() override = default;

    bool intersect(const Ray &r, Hit &h, float tmin) override
    {
        Vector3f oc = r.getOrigin() - center;
        float a = r.getDirection().squaredLength();
        float b = 2 * Vector3f::dot(oc, r.getDirection());
        float c = oc.squaredLength() - radius * radius;
        float delta = b * b - 4 * a * c;
        if (delta > 0)
        {
            float t1 = (-b - std::sqrt(delta)) / (2 * a);
            float t2 = (-b + std::sqrt(delta)) / (2 * a);
            float t = t1;
            if (t < tmin || t > h.getT())
            {
                t = t2;
            }
            if (t >= tmin && t < h.getT())
            {
                Vector3f p = r.pointAtParameter(t);
                Vector3f n = (p - center).normalized();
                h.set(t, material, n);
                return true;
            }
        }
        return false;
    }

    void drawGL() override
    {
        Object3D::drawGL();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(center.x(), center.y(), center.z());
        glutSolidSphere(radius, 80, 80);
        glPopMatrix();
    }

protected:
    Vector3f center;
    float radius;
};

#endif
