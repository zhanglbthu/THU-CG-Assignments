#ifndef CAMERA_H
#define CAMERA_H

#include "ray.hpp"
#include <vecmath.h>
#include <float.h>
#include <cmath>

class Camera
{
public:
    Camera(const Vector3f &center, const Vector3f &direction, const Vector3f &up, int imgW, int imgH)
    {
        this->center = center;
        this->direction = direction.normalized();
        this->horizontal = Vector3f::cross(this->direction, up).normalized();
        this->up = Vector3f::cross(this->horizontal, this->direction);
        this->width = imgW;
        this->height = imgH;
    }

    // Generate rays for each screen-space coordinate
    virtual Ray generateRay(const Vector2f &point) = 0;
    virtual ~Camera() = default;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    // Extrinsic parameters
    Vector3f center;
    Vector3f direction;
    Vector3f up;
    Vector3f horizontal;
    // Intrinsic parameters
    int width;
    int height;
};

// TODO: Implement Perspective camera
// You can add new functions or variables whenever needed.
class PerspectiveCamera : public Camera
{

public:
    PerspectiveCamera(const Vector3f &center, const Vector3f &direction,
                      const Vector3f &up, int imgW, int imgH, float angle) : Camera(center, direction, up, imgW, imgH)
    {
        // angle is in radian.
        this->angle = angle;
        this->imagePlaneDist = 1 / std::tan(angle / 2);
    }

    Ray generateRay(const Vector2f &point) override
    {
        //
        Vector3f rayDirection = this->imagePlaneDist * this->direction 
                                    + (2 * point.x() / this->width - 1) 
                                    * this->horizontal 
                                    + (2 * point.y() / this->height - 1) * this->up;
        return Ray(this->center, rayDirection.normalized());
    }

protected:
    float angle;
    float imagePlaneDist;
};

#endif // CAMERA_H
