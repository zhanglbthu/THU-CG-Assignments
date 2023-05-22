#ifndef CURVE_HPP
#define CURVE_HPP

#include "object3d.hpp"
#include <vecmath.h>
#include <vector>
#include <utility>

#include <algorithm>

// TODO (PA2): Implement Bernstein class to compute spline basis function.计算样条基函数
//       You may refer to the python-script for implementation.

// The CurvePoint object stores information about a point on a curve
// after it has been tesselated: the vertex (V) and the tangent (T)
// It is the responsiblility of functions that create these objects to fill in all the data.
struct CurvePoint
{
    Vector3f V; // Vertex
    Vector3f T; // Tangent  (unit)
};

class Curve : public Object3D
{
protected:
    std::vector<Vector3f> controls;

public:
    explicit Curve(std::vector<Vector3f> points) : controls(std::move(points)) {}

    bool intersect(const Ray &r, Hit &h, float tmin) override
    {
        return false;
    }

    std::vector<Vector3f> &getControls()
    {
        return controls;
    }
    /// @brief
    /// @param resolution 离散化分辨率
    /// @param data
    virtual void discretize(int resolution, std::vector<CurvePoint> &data) = 0;

    void drawGL() override
    {
        Object3D::drawGL();
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glDisable(GL_LIGHTING);
        glColor3f(1, 1, 0);
        glBegin(GL_LINE_STRIP);
        for (auto &control : controls)
        {
            glVertex3fv(control);
        }
        glEnd();
        glPointSize(4);
        glBegin(GL_POINTS);
        for (auto &control : controls)
        {
            glVertex3fv(control);
        }
        glEnd();
        std::vector<CurvePoint> sampledPoints;
        discretize(30, sampledPoints);
        glColor3f(1, 1, 1);
        glBegin(GL_LINE_STRIP);
        for (auto &cp : sampledPoints)
        {
            glVertex3fv(cp.V);
        }
        glEnd();
        glPopAttrib();
    }
};
/// @brief 辅助类，计算Bezier曲线和B样条的基函数
class Bernstein
{
public:
    static float evaluateBasis(int i, int n, float t)
    {
        if (i < 0 || i > n)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        return (1 - t) * evaluateBasis(i, n - 1, t) + t * evaluateBasis(i - 1, n - 1, t);
    }
    static float evaluateBasisDerivative(int i, int n, float t)
    {
        return n * (evaluateBasis(i - 1, n - 1, t) - evaluateBasis(i, n - 1, t));
    }
    static float evaluateBasis(int i, int k, float t, std::vector<float> knots)
    {
        if (k == 0)
        {
            return (t >= knots[i] && t < knots[i + 1]) ? 1.0f : 0.0f;
        }
        else
        {
            return ((t - knots[i]) / (knots[i + k] - knots[i])) * evaluateBasis(i, k - 1, t, knots) + ((knots[i + k + 1] - t) / (knots[i + k + 1] - knots[i + 1])) * evaluateBasis(i + 1, k - 1, t, knots);
        }
    }
    static float evaluateBasisDerivative(int i, int k, float t, std::vector<float> knots)
    {
        float left = evaluateBasis(i, k - 1, t, knots);
        float right = evaluateBasis(i + 1, k - 1, t, knots);
        return k * ((left / (knots[i + k] - knots[i])) - (right / (knots[i + k + 1] - knots[i + 1])));
    }
};

class BezierCurve : public Curve
{
public:
    explicit BezierCurve(const std::vector<Vector3f> &points) : Curve(points)
    {
        if (points.size() < 4 || points.size() % 3 != 1)
        {
            printf("Number of control points of BezierCurve must be 3n+1!\n");
            exit(0);
        }
    }

    void discretize(int resolution, std::vector<CurvePoint> &data) override
    {
        data.clear();
        // TODO (PA2): fill in data vector
        int n = controls.size() - 1;
        for (int i = 0; i < resolution; i++)
        {
            float t = (float)i / (float)(resolution - 1);
            CurvePoint point;
            point.V = Vector3f::ZERO;
            point.T = Vector3f::ZERO;
            for (int j = 0; j <= n; j++)
            {
                float basis = Bernstein::evaluateBasis(j, n, t);
                float basisDerivative = Bernstein::evaluateBasisDerivative(j, n, t);
                point.V += basis * controls[j];
                point.T += basisDerivative * controls[j];
            }
            point.T.normalize();
            data.push_back(point);
        }
    }

protected:
};

class BsplineCurve : public Curve
{
public:
    BsplineCurve(const std::vector<Vector3f> &points) : Curve(points)
    {
        if (points.size() < 4)
        {
            printf("Number of control points of BspineCurve must be more than 4!\n");
            exit(0);
        }
    }

    void discretize(int resolution, std::vector<CurvePoint> &data) override
    {
        data.clear();
        // TODO (PA2): fill in data vector
        int n = controls.size() - 1;
        int k = 3;
        int m = n + k + 1;
        std::vector<float> knotVector(m + 1, 0.0f);
        for (int i = 0; i <= m; i++)
        {
            knotVector[i] = i / (float)(n + k + 1);
        }
        for (int i = 0; i < resolution; i++)
        {
            float t = knotVector[k] + (i / (float)(resolution - 1)) * (knotVector[n + 1] - knotVector[k]);
            CurvePoint point;
            point.V = Vector3f::ZERO;
            point.T = Vector3f::ZERO;
            for (int j = 0; j <= n; j++)
            {
                float basisValue = Bernstein::evaluateBasis(j, k, t, knotVector);
                float basisDerivative = Bernstein::evaluateBasisDerivative(j, k, t, knotVector);
                point.V += basisValue * controls[j];
                point.T += basisDerivative * controls[j];
            }
            point.T.normalize();
            data.push_back(point);
        }
    }

protected:
};
#endif // CURVE_HPP