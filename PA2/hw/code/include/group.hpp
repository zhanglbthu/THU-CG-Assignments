#ifndef GROUP_H
#define GROUP_H

#include "object3d.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <iostream>
#include <vector>

// Finish (PA2): Implement Group - copy from PA1
class Group : public Object3D
{

public:
    Group()
    {
    }

    explicit Group(int num_objects) : objects(num_objects)
    {
    }

    ~Group() override
    {
    }

    bool intersect(const Ray &r, Hit &h, float tmin) override
    {
        bool hit = false;
        for (auto object : objects)
        {
            if (object->intersect(r, h, tmin))
            {
                hit = true;
            }
        }
        return hit;
    }

    void drawGL() override
    {
        for (auto *obj : objects)
        {
            obj->drawGL();
        }
    }

    void addObject(int index, Object3D *obj)
    {
        if (index >= 0 && index < objects.size())
        {
            objects[index] = obj;
        }
    }

    int getGroupSize()
    {
        return objects.size();
    }

private:
    std::vector<Object3D *> objects;
};

#endif
