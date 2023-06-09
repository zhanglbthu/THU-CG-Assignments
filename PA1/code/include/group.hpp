#ifndef GROUP_H
#define GROUP_H

#include "object3d.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <iostream>
#include <vector>

// TODO: Implement Group - add data structure to store a list of Object*
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
