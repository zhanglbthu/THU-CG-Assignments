#ifndef __SCENE_H__
#define __SCENE_H__

#include "obj.hpp"
#include "bezier.hpp"

const ld bezier_div_x = 3;
const ld bezier_div_y = 2.5;
ld control_x[] = {20./bezier_div_x,27./bezier_div_x,30./bezier_div_x,30./bezier_div_x,30./bezier_div_x,25./bezier_div_x,20./bezier_div_x,15./bezier_div_x,30./bezier_div_x};
ld control_y[] = {0./bezier_div_y,0./bezier_div_y,10./bezier_div_y,20./bezier_div_y,30./bezier_div_y,40./bezier_div_y,60./bezier_div_y,70./bezier_div_y,80./bezier_div_y};
BezierCurve2D bezier(control_x, control_y, 9, 9, .365);

Object* vase_front[] = {
	new SphereObject(P3(1e5+1,40.8,81.6),   1e5, DIFF, 1.5, P3(.1,.25,.25)),//Left
	new SphereObject(P3(-1e5+99,40.8,81.6), 1e5, DIFF, 1.5, P3(.25,.75,.25)),//Right
	new SphereObject(P3(50,40.8, 1e5),      1e5, DIFF, 1.5, P3(.75,.75,.75)),//Back
	new SphereObject(P3(50,40.8,-1e5+190),  1e5, DIFF, 1.5, P3(.25,.25,.25)),//Front
	new SphereObject(P3(50, 1e5, 81.6),     1e5, DIFF, 1.5, P3(.75,.75,.75), P3(), "star.png"),//Bottom
	new SphereObject(P3(50,-1e5+81.6,81.6), 1e5, DIFF, 1.5, P3(.75,.75,.75)),//Top 
	new SphereObject(P3(40,16.5,47),       16.5, SPEC, 1.5, P3(1,1,1)*.999),//Mirror
	new CubeObject(P3(0,8,84),    P3(34,10,116), DIFF, 1.5, P3(76/255.,34/255.,27/255.)),
	new BezierObject(P3(20, 9.99, 100),  bezier, DIFF, 1.5, P3(1,1,1)*.999, P3(), "vase.png"),
	new SphereObject(P3(73,16.5,78),       16.5, REFR, 1.5, P3(1,1,1)*.999),//Glas 
	// new SphereObject(P3(20,60,100),        16.5, SPEC, 1.5, P3(1,1,1)*.999),//RedBall
	new SphereObject(P3(50,681.6-.27,81.6), 600, DIFF, 1.5, P3(), P3(12,12,12)) //Lite 
};

Object* vase_back[] = {
	new SphereObject(P3(1e5+1,40.8,81.6),   1e5, DIFF, 1.5, P3(.1,.25,.25)),//Left
	new SphereObject(P3(-1e5+99,40.8,81.6), 1e5, DIFF, 1.5, P3(.25,.75,.25)),//Right
	new SphereObject(P3(50,40.8, 1e5),      1e5, DIFF, 1.5, P3(.75,.75,.75)),//Back
	new SphereObject(P3(50,40.8,-1e5+190),  1e5, DIFF, 1.5, P3(.25,.25,.25)),//Front
	new SphereObject(P3(50, 1e5, 81.6),     1e5, DIFF, 1.5, P3(.75,.75,.75), P3(), "star.png"),//Botrom
	new SphereObject(P3(50,-1e5+81.6,81.6), 1e5, DIFF, 1.5, P3(.75,.75,.75)),//Top
	// new SphereObject(P3(27,16.5,47),       16.5, SPEC, 1.5, P3(1,1,1)*.999),//Mirror
	new   CubeObject(P3(0,8,0),    P3(30,10,30), DIFF, 1.5, P3(76/255.,34/255.,27/255.)),
	new BezierObject(P3(15, 9.99, 15),   bezier, DIFF, 1.7, P3(1,1,1)*.999, P3(), "vase.png"),
	new SphereObject(P3(73,16.5,40),       16.5, DIFF, 1.7, P3(1,1,1)*.999, P3(), "rainbow.png"),//Main Ball
	new SphereObject(P3(45,6,45),             6, REFR, 1.7, P3(.5,.5,1)*.999),//SmallBall0
	new SphereObject(P3(44,4,95),             4, REFR, 1.7, P3(1,.5,.5)*.999),//SmallBall1
	new SphereObject(P3(56,4,105),            4, REFR, 1.7, P3(.5,1,.5)*.999),//SmallBall2
	new SphereObject(P3(67,4,112),            4, REFR, 1.7, P3(1,1,.5)*.999),//SmallBall3
	new SphereObject(P3(16,60,100),          12, REFR, 1.5, P3(1,1,1)*.999),//FlyBall
	new SphereObject(P3(50,681.6-.27,81.6), 600, DIFF, 1.5, P3(), P3(12,12,12)) //Lite
};

Object* camera_left[] = {
	new SphereObject(P3(1e5+1,40.8,81.6),   1e5, DIFF, 1.5, P3(.1,.25,.25), P3(), "wallls.com_156455.png"),//Left
	new SphereObject(P3(-1e5+299,40.8,81.6), 1e5, DIFF, 1.5, P3(.25,.75,.25)),//Right
	new SphereObject(P3(50,40.8, 1e5),      1e5, DIFF, 1.5, P3(1,1,1)*.999, P3(), "greenbg.jpg"),//Back
	new SphereObject(P3(50,40.8,-1e5+190),  1e5, DIFF, 1.5, P3(.25,.25,.25)),//Front
	new SphereObject(P3(50, 1e5, 81.6),     1e5, DIFF, 1.5, P3(.75,.75,.75), P3(), "star.png"),//Botrom
	new SphereObject(P3(50,-1e5+81.6,81.6), 1e5, DIFF, 1.5, P3(.75,.75,.75)),//Top
	// new SphereObject(P3(27,16.5,47),       16.5, SPEC, 1.5, P3(1,1,1)*.999),//Mirror
	new   CubeObject(P3(0,8,0),    P3(30,10,30), DIFF, 1.5, P3(76/255.,34/255.,27/255.), P3(), "wood.jpg"),
	new BezierObject(P3(15, 9.99, 15),   bezier, DIFF, 1.7, P3(1,1,1)*.999, P3(), "vase.png"),
	new SphereObject(P3(73,16.5,40),       16.5, DIFF, 1.7, P3(1,1,1)*.999, P3(), "rainbow.png"),//Main Ball
	new SphereObject(P3(45,6,45),             6, REFR, 1.7, P3(.5,.5,1)*.999),//SmallBall0
	new SphereObject(P3(52,3,75),             3, REFR, 1.7, P3(1,.5,.5)*.999),//SmallBall1
	new SphereObject(P3(65.5,3,88),           3, REFR, 1.7, P3(.5,1,.5)*.999),//SmallBall2
	new SphereObject(P3(77,3,92),             3, REFR, 1.7, P3(1,1,.5)*.999),//SmallBall3
	// new SphereObject(P3(16,60,100),          12, REFR, 1.5, P3(1,1,1)*.999),//FlyBall
	new SphereObject(P3(50,681.6-.27,81.6), 600, DIFF, 1.5, P3(), P3(1,1,1)*20) //Lite
};

Object** scene = camera_left;
int scene_num = 14;

std::pair<Refl_t, P3> get_feature(Object* obj, Texture&texture, P3 x, unsigned short *X) {
	std::pair<Refl_t, P3> feature;
	if (texture.filename == "star.png")
		feature = texture.getcol(x.z / 15, x.x / 15);
	else if (texture.filename == "crack.jpg") {
		feature = texture.getcol(x.z / 300, x.x / 300);
	}
	else if (texture.filename == "wood.jpg") {
		feature = texture.getcol(x.x / 30, x.z / 30);
	}
	else if (texture.filename == "greenbg.jpg") {
		feature = texture.getcol(-x.x / 125, -x.y / 80 - 0.05);
		// if (erand48(X) < 0.2 && x.y < 50)
			// feature.first = SPEC;
	}
	else if (texture.filename == "wallls.com_156455.png") {
		feature = texture.getcol(-x.z / 150, -x.y / 100);
		// if (erand48(X) < 0.2 && x.y < 50)
			// feature.first = SPEC;
	}
	else if (texture.filename == "vase.png") {
		P3 tmp = obj->change_for_bezier(x);
		// printf("%f %f\n",tmp.x/2/PI,tmp.y);
		feature = texture.getcol(tmp.x / 2 / PI + .5, tmp.y);
		if (erand48(X) < 0.2)
			feature.first = SPEC;
	}
	else if (texture.filename == "rainbow.png") {
		ld px = (x.x - 73) / 16.5, py = (x.y - 16.5) / 16.5;
		feature = texture.getcol((py * cos(-0.3) + px * sin(-0.3))*.6 - .25, x.z);
		// feature = texture.getcol(x.y / 32 + 0.25, x.z);
	}
	else
		feature = texture.getcol(x.z, x.x);
	return feature;
}

#endif // __SCENE_H__
