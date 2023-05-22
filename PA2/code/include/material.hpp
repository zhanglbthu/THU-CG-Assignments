#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "ray.hpp"
#include "hit.hpp"
#include <iostream>
#include <glut.h>

// Finish (PA2): Copy from PA1.
class Material {
public:

    explicit Material(const Vector3f &d_color, const Vector3f &s_color = Vector3f::ZERO, float s = 0) :
            diffuseColor(d_color), specularColor(s_color), shininess(s) {

    }

    virtual ~Material() = default;

    virtual Vector3f getDiffuseColor() const {
        return diffuseColor;
    }


    Vector3f Shade(const Ray &ray, const Hit &hit,
                   const Vector3f &dirToLight, const Vector3f &lightColor)
    {
        Vector3f shaded = Vector3f::ZERO;
        //
        Vector3f normal = hit.getNormal().normalized();
        float cosTheta = std::max(0.0f, Vector3f::dot(normal, dirToLight.normalized()));
        Vector3f Id = diffuseColor * cosTheta;

        Vector3f rayDirection = ray.getDirection().normalized();
        Vector3f reflectedRay = (2 * Vector3f::dot(normal, dirToLight) * normal - dirToLight).normalized();
        Vector3f viewDirection = -rayDirection;
        float cosAlpha = std::max(0.0f, Vector3f::dot(reflectedRay, viewDirection));
        Vector3f Is = specularColor * pow(cosAlpha, shininess);

        shaded = lightColor * (Is + Id);
        return shaded;
    }

    // For OpenGL, this is fully implemented
    void Use() {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Vector4f(diffuseColor, 1.0f));
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Vector4f(specularColor, 1.0f));
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, Vector2f(shininess * 4.0, 1.0f));
    }

protected:
    Vector3f diffuseColor;
    Vector3f specularColor;
    float shininess;
};


#endif // MATERIAL_H
