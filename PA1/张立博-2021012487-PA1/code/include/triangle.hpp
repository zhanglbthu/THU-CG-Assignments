#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>
#include <iostream>
using namespace std;

// TODO: implement this class and add more fields as necessary,
class Triangle : public Object3D
{

public:
	Triangle() = delete;

	// a b c are three vertex positions of the triangle
	Triangle(const Vector3f &a, const Vector3f &b, const Vector3f &c, Material *m) : Object3D(m), vertices{a, b, c}
	{
		normal = Vector3f::cross(b - a, c - a).normalized();
	}

	bool intersect(const Ray &ray, Hit &hit, float tmin) override
	{
		const float EPSILON = 0.0000001;
		Vector3f edge1 = vertices[1] - vertices[0];
		Vector3f edge2 = vertices[2] - vertices[0];
		Vector3f h = Vector3f::cross(ray.getDirection(), edge2);
		float a = Vector3f::dot(edge1, h);	
		if (a > -EPSILON && a < EPSILON)
		{
			return false;
		}
		float f = 1.0 / a;
		Vector3f s = ray.getOrigin() - vertices[0];
		float u = f * Vector3f::dot(s, h);
		if (u < 0.0 || u > 1.0)
		{
			return false;
		}
		Vector3f q = Vector3f::cross(s, edge1);
		float v = f * Vector3f::dot(ray.getDirection(), q);
		if (v < 0.0 || u + v > 1.0)
		{
			return false;
		}
		float t = f * Vector3f::dot(edge2, q);
		if (t > EPSILON && t < hit.getT())
		{
			hit.set(t, material, normal);
			return true;
		}
		return false;
	}
	Vector3f normal;
	Vector3f vertices[3];

protected:
};

#endif // TRIANGLE_H
