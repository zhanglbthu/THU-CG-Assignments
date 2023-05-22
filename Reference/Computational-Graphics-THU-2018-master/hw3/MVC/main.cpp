#include <bits/stdc++.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
// basic math operation
struct P{
	double x, y;
#define PP register const P&
	bool operator<(PP a)const {return x<a.x||x==a.x&&y<a.y;}
	P operator+(PP a)const {return (P){x+a.x,y+a.y};}
	P operator-(PP a)const {return (P){x-a.x,y-a.y};}
	P operator*(double p){return (P){x*p,y*p};}
	double operator&(PP a)const {return x*a.y-y*a.x;}
	double operator|(PP a)const {return x*a.x+y*a.y;}
	double len2() const {return x*x+y*y;}
	void noise(double r=1e-2){x+=(rand()&1?1.:-1.)*rand()/2147483647*r;y+=(rand()&1?1.:-1.)*rand()/2147483647*r;}
};
namespace Gauss
{
double a[10][10];
const int n=3;
void pr(){
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n+1;j++)
			printf("%lf ",a[i][j]);
	puts("");
}
void solve(){
	int i,j,k,las;double t;
	for(i=1;i<=n;i++) {
		for(t=0,las=j=i;j<=n;j++)
			if(abs(a[j][i])>t)t=abs(a[j][i]),las=j;
		if(j=las,j!=i)
			for(k=1;k<=n+1;k++)t=a[i][k],a[i][k]=a[j][k],a[j][k]=t;
		for(j=i+1;j<=n;j++)
			for(t=a[j][i]/a[i][i],k=i;k<=n+1;k++)a[j][k]-=a[i][k]*t;
	}
	for(i=n;i>=1;i--)
		for(a[i][n+1]/=a[i][i],j=i-1;j;j--)a[j][n+1]-=a[j][i]*a[i][n+1];
}
}
struct Mat{
	double m[3];
	double transform(P p) {return p.x * m[0] + p.y * m[1] + m[2];}
}fmat[4];
void Calc_Transform_Matrix(Mat&f, P p1, P p2, P p3, double c0, double c1, double c2)
{
	/*
	 *             | x |   
	 * | a b c | * | y | = col
	 *             | 1 |   
	 *
	 * solve a,b,c -> Matrix f.m
	 */
	using namespace Gauss;
	// a,b,c
	a[1][1] = p1.x, a[2][1] = p2.x, a[3][1] = p3.x;
	a[1][2] = p1.y, a[2][2] = p2.y, a[3][2] = p3.y;
	a[1][3] = a[2][3] = a[3][3] = 1;
	a[1][4] = c0, a[2][4] = c1, a[3][4] = c2;
	solve();
	f.m[0] = a[1][4], f.m[1] = a[2][4], f.m[2] = a[3][4];
}
#define check(a, b, c) ((b - a) & (c - a))
bool intri(P p, P a, P b, P c)
{
	double s = std::abs(check(a, b, c));
	double s_ = std::abs(check(a, p, b)) + std::abs(check(b, p, c)) + std::abs(check(c, p, a));
	return std::abs(s - s_) < 1e-8;
}
// POISSION
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char str[100];
#define getidx(i, j, k, w, c) ((i) * (w) * (c) + (j) * (c) + (k))
struct IMG{
	double* img;
	unsigned char* buf;
	std::string filename;
	int w, h, c, w0, w1, h0, h1;
	IMG(): img(NULL), w(0), h(0), c(0) {}
	IMG(int _h, int _w, int _c=1)
	{
		init(_h, _w, _c);
	}
	void init(int _h, int _w, int _c)
	{
		h = _h, w = _w, c = _c;
		img = new double[w * h * c];
		buf = new unsigned char[w * h * c];
		memset(img, 0, sizeof(double) * w * h * c);
		memset(buf, 0, sizeof(unsigned char) * w * h * c);
		w0 = h0 = 1 << 30, w1 = h1 = 1;
	}
	IMG(std::string _): filename(_) {
		if (_ == "") return;
		buf = stbi_load(filename.c_str(), &w, &h, &c, 0);
		img = new double[w * h * c];
		for (int i = 0; i < w * h * c; ++i)
			img[i] = buf[i];
		stat();
	}
	void stat(int lb = 0){
		h0 = w0 = 1 << 30, h1 = w1 = 0;
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w; ++j)
					for (int k = 0; k < c; ++k)
						buf[getidx(i, j, k, w, c)] > lb ? i < h0 ? h0 = i : 1, 
							h1 < i ? h1 = i : 1, j < w0 ? w0 = j : 1, w1 < j ? w1 = j : 1 : 1;
		// printf("h: %d,%d; w: %d,%d\n",h0,h1,w0,w1);
	}
	void write(const char* output_filename){
		unsigned char* buf_ = new unsigned char[w * h * c];
		for (int i = 0; i < w * h * c; ++i)
			buf_[i] = img[i] < 0 ? 0 : img[i] > 255 ? 255 : img[i];
		stbi_write_png(output_filename, w, h, c, buf_, 0);
	}
	void print(char* s)
	{
		puts(s);
		puts("--u");
		for (int i=0;i<w;++i,puts(""))
			for (int j=0;j<h;++j)
				printf("%6d ",1*buf[getidx(i,j,0,w,c)]);
				// printf("%d,%d,%d ",1l*buf[getidx(i,j,0,w,c)],1l*buf[getidx(i,j,1,w,c)],1l*buf[getidx(i,j,2,w,c)]);
		puts("--f");
		for (int i=0;i<w;++i,puts(""))
			for (int j=0;j<h;++j)
				printf("%7.1f",img[getidx(i,j,0,w,c)]);
				// printf("%.1lf,%.1lf,%.1lf ",img[getidx(i,j,0,w,c)],img[getidx(i,j,1,w,c)],img[getidx(i,j,2,w,c)]);
		puts("");
	}
};

#define getpix(f, i, j, k) f.img[getidx(i, j, k, f.w, f.c)]
#define getbuf(f, i, j, k) f.buf[getidx(i, j, k, f.w, f.c)]

struct Solver{
// 4x1-x2-x3=4
// 4 var var const
	int label, id, size;
	double *x, *b, *tmp, err;
	int **a; // a[id][0]: number; a[id][>0]: -id
	void resize(int _size)
	{
		x = new double[size = _size]; memset(x, 0, sizeof(double) * size);
		tmp = new double[size]; memset(tmp, 0, sizeof(double) * size);
		a = new int*[size];
		b = new double[size]; memset(b, 0, sizeof(double) * size);
		for (int i = 0; i < size; ++i)
		{
			a[i] = new int[10];
			a[i][0] = 0;
		}
	}
	void additem(int _id, int _x=0){
		// printf("size=%d id=%d\n",size,_id);
		x[id = _id] = _x;
		b[id] = a[id][0] = 0;
		// x[id]=0;
	}
	void addconst(int _b) {b[id] += _b;}
	void addvar(int id2) {a[id][++a[id][0]] = id2;}
	void print() {
		printf("size=%d\n", size);
		// return;
		for (int i = 0; i < size; ++i)
			if (a[i][0]) {
				printf("4x%d", i);
				for (int j = 1; j <= a[i][0]; ++j)
					printf("-x%d", a[i][j]);
				printf("=%.1lf\n", b[i]);
			}
	}
	void iter() {
		// calc tmp=4x+b-Ax
		err = 0;
// #pragma omp parallel for schedule(dynamic, 10)
		for (int i = 0; i < size; ++i)
			if (a[i][0])
			{
				tmp[i] = b[i];//-4*x[i];
				for (int j = 1; j <= a[i][0]; ++j)
					tmp[i] += x[a[i][j]];
				err += std::abs(tmp[i] - 4 * x[i]);
			}
		for (int i = 0; i < size; ++i)
			if (a[i][0])
				x[i] = tmp[i] / 4;
	}
};

// MVC
const double PI = acos(-1);

// CGAL includes for triangulation
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_conformer_2.h>
#include <CGAL/Triangulation_vertex_base_2.h>
#include <CGAL/Delaunay_mesh_face_base_2.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Polygon_2_algorithms.h>
#include <CGAL/Delaunay_mesher_2.h>
#include <CGAL/Delaunay_mesh_size_criteria_2.h>

// CGAL typedefs and definitions
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_2<K> Vb;
typedef CGAL::Delaunay_mesh_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Constrained_Delaunay_triangulation_2<K, Tds> DelaunayTriangulation;

typedef CGAL::Delaunay_mesh_size_criteria_2<DelaunayTriangulation> Criteria;

typedef DelaunayTriangulation::Finite_vertices_iterator FiniteVerticesIterator;
typedef DelaunayTriangulation::Finite_faces_iterator FiniteFacesIterator;
typedef DelaunayTriangulation::Finite_edges_iterator FiniteEdgesIterator;
typedef DelaunayTriangulation::Face_circulator FacesCirculator;
typedef DelaunayTriangulation::Point_iterator PointIterator;
typedef DelaunayTriangulation::Vertex Vertex;
typedef DelaunayTriangulation::Vertex_handle VertexHandle;
typedef DelaunayTriangulation::Edge Edge;
typedef DelaunayTriangulation::Face Face;
typedef DelaunayTriangulation::Face_handle FaceHandle;
typedef DelaunayTriangulation::Triangle Triangle;

typedef CGAL::Cartesian<double> Metric;
typedef DelaunayTriangulation::Point Point;
typedef CGAL::Polygon_2<Metric> Polygon2D;
typedef CGAL::Bbox_2 BBox2D;

typedef CGAL::Delaunay_mesher_2<DelaunayTriangulation, Criteria> Mesher;
std::map<Point, int> mapping;
std::vector<Point> boundaryVector;
std::vector<Point> orderedPoints;
std::vector<Triangle> triangle_mesh;

bool inside(P p) {
	int cnt = 0;
	P far = (P) {-100, -1000};
	int n = boundaryVector.size();
	for (int i = 0; i < n; ++i) {
		P p0 = (P){boundaryVector[i].x(), boundaryVector[i].y()};
		P p1 = (P){boundaryVector[(i+1)%n].x(), boundaryVector[(i+1)%n].y()};
		if (check(p, p0, p1) * check(far, p0, p1) <= 0 && check(p0, p, far) * check(p1, p, far) <= 0)
			++cnt;
	}
	// printf("inside %d\n",cnt);
	return cnt & 1;
}

void getMesh(const std::vector<Point>& curve) {
	DelaunayTriangulation* adaptiveMesh = new DelaunayTriangulation();
	adaptiveMesh->clear();
	adaptiveMesh->insert(curve.begin(), curve.end());
	for (unsigned int i = 0; i < curve.size(); ++i) {
		Point curr = curve[i];
		Point next = curve[(i+1) % curve.size()];
		adaptiveMesh->insert_constraint(curr, next);
	}
	Mesher mesher(*adaptiveMesh);
	mesher.set_criteria(Criteria(0.125, 0));
	mesher.refine_mesh();
	std::cout << "Done with " << adaptiveMesh->number_of_vertices() << " vertices and " << adaptiveMesh->number_of_faces() << " triangles." << std::endl;
	int index = 0;
	for (FiniteFacesIterator iter = adaptiveMesh->finite_faces_begin() ; iter != adaptiveMesh->finite_faces_end() ; ++iter) {
		Triangle triangle = adaptiveMesh->triangle(iter);
		Point v1 = triangle.vertex(0);
		Point v2 = triangle.vertex(1);
		Point v3 = triangle.vertex(2);
		if (inside((P){(v1.x()+v2.x()+v3.x())/3., (v1.y()+v2.y()+v3.y())/3.}))
			triangle_mesh.push_back(triangle);
		// std::cout << v1.x() << " " << v1.y() << " " << v2.x() << " " << v2.y() << " " << v3.x() << " " << v3.y() << std::endl;
		if (mapping.find(v1) == mapping.end()) {
			mapping[v1] = index++;
			orderedPoints.push_back(v1);
		}
		if (mapping.find(v2) == mapping.end()) {
			mapping[v2] = index++;
			orderedPoints.push_back(v2);
		}
		if (mapping.find(v3) == mapping.end()) {
			mapping[v3] = index++;
			orderedPoints.push_back(v3);
		}
	}
}

double getTanAngle(const Point& a_, const Point& b_, const Point& c_)
{
//tan(.5 * std::abs(angle))
	P b = (P){b_.x() - a_.x(), b_.y() - a_.y()}, c = (P){c_.x() - a_.x(), c_.y() - a_.y()};
	double bdc = (b | c);
	double lbc = sqrt(b.len2() * c.len2());
	return sqrt((lbc - bdc) / (bdc + lbc));
}

double getLength(const Point& a, const Point& b)
{
	return sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
}

int main(int argc, char const *argv[])
{
	int ph = 0, pw = 0, iter = 2000, before = 0, per = 1 << 30, channel = 0, rsm = 0, mvc = 1;
	std::string src_name, mask_name, target_name, output_filename;
	if (argc <= 1)
	{
		puts("Poisson & MVC image editing      -- powered by n+e");
		puts("Usage:");
		puts("    no argument            show this message and exit");
		puts("    -a algorithm           which algorithm (Poisson, MVC) to use, default: MVC");
		puts("    -s SRC                 src filename");
		puts("    -m MASK                mask filename");
		puts("    -t TARGET              target filename");
		puts("    -o OUTPUT              output filename (only support .png)");
		puts("    -h HEIGHT              where to put src into target, specify HEIGHT");
		puts("    -w WIDTH               which to put src into target, specify WIDTH");
		puts("    -i ITERATION           how many ITERATION would you perfer, more is better");
		puts("    -b NUMBER              output less than NUMBER iterate result");
		puts("    -p NUMBER              output result every NUMBER iteration");
		puts("    -r ITER                resume iteration from ITERth png file");
		puts("");
		puts("Example:");
		puts("    ./main -a Poisson -s img/src0.jpg -t img/target0.jpg -m img/mask0.png -o result_poisson.png -p 100 -b 10 -i 5000 -h 350 -w 400");
		puts("    ./main -s img/src0.jpg -t img/target0.jpg -m img/mask0.png -h 318 -w 370 -o result_MVC.png");
		return 0;
	}
	for (int i = 1; i < argc; ++i)
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 's' || argv[i][2] == 's')
				src_name = argv[++i];
			else if (argv[i][1] == 'm' || argv[i][2] == 'm')
				mask_name = argv[++i];
			else if (argv[i][1] == 't' || argv[i][2] == 't')
				target_name = argv[++i];
			else if (argv[i][1] == 'o' || argv[i][2] == 'o')
				output_filename = argv[++i];
			else if (argv[i][1] == 'h' || argv[i][2] == 'h')
				ph = atoi(argv[++i]);
			else if (argv[i][1] == 'w' || argv[i][2] == 'w')
				pw = atoi(argv[++i]);
			else if (argv[i][1] == 'i' || argv[i][2] == 'i')
				iter = atoi(argv[++i]);
			else if (argv[i][1] == 'p' || argv[i][2] == 'p')
				per = atoi(argv[++i]);
			else if (argv[i][1] == 'b' || argv[i][2] == 'b')
				before = atoi(argv[++i]);
			else if (argv[i][1] == 'r' || argv[i][2] == 'r')
				rsm = atoi(argv[++i]);
			else if (argv[i][1] == 'a' || argv[i][2] == 'a')
				mvc = argv[++i][0] == 'M';
		}
	if (rsm)
		sprintf(str, "iter%d.png", rsm);
	if (output_filename == "")
		output_filename = "result.png";
	if (src_name == "")
		return !puts("no src name");
	if (target_name == "")
		return !puts("no target name");
	// read data
	IMG src(src_name), mask(mask_name), target(target_name), resume(str);
	if (mask_name == ""){
		mask.init(src.h, src.w, src.c);
		for (int i = 1; i < src.h - 1; ++i)
			for (int j = 1; j < src.w - 1; ++j)
				for (int k = 0; k < src.c; ++k)
					getpix(mask, i, j, k) = getbuf(mask, i, j, k) = 255;
	}
	assert(mask.w == src.w);
	assert(mask.h = src.h);
	// src.print("src");
	// mask.print("mask");
	// target.print("tar");
	printf("mask %d src %d target %d\n", mask.c, src.c, target.c);
	// assert(src.c==mask.c);
	// assert(src.c==target.c);
	channel = std::min(src.c, target.c);
	printf("src size: %d*%d\n", src.h, src.w);
	mask.stat(200);
	printf("mask size: %d*%d [%d,%d]*[%d,%d]\n", mask.h, mask.w, mask.h0, mask.h1, mask.w0, mask.w1);
	printf("target size: %d*%d\n", target.h, target.w);
	if (mvc) // MVC
	{
		std::map<Point, int> map_boundary;
		std::string cmd = "python edge.py "+ mask_name;
		system(cmd.c_str());
		FILE *fedge = fopen("edge.txt", "r");
		int x, y, cnt = 0;
		while (~fscanf(fedge, "%d%d", &x, &y)) {
			boundaryVector.push_back(Point(x, y));
			map_boundary[Point(x, y)] = cnt++;
		}
		// printf("%d %d\n", src.h, src.w);
		getMesh(boundaryVector);
		// test vertex
		// double tot = 0;
		// for (std::vector<Point>::const_iterator i = boundaryVector.begin(); i != boundaryVector.end(); ++i) {
		// 	int x = int(.5+(*i).x()), y = int(.5+(*i).y());
		// 	getpix(src, x, y, 0) = 
		// 	getpix(src, x, y, 1) = 
		// 	getpix(src, x, y, 2) = tot;
		// 	tot+=.3;
		// }
		// src.write("test.png");
		// calc these vertex's color
		double bcol[cnt + 10][4], weight[cnt + 10], tg[cnt + 10], fcol[orderedPoints.size() + 10][4];
		memset(fcol, 0, sizeof fcol);
		for (int i = 0; i < orderedPoints.size(); ++i)
		if (map_boundary.find(orderedPoints[i]) != map_boundary.end()) { // boundary point
			for (int k = 0; k < channel; ++k) {
				int s_x = int(.5 + orderedPoints[i].x()), s_y = int(.5 + orderedPoints[i].y());
				int t_x = s_x + ph, t_y = s_y + pw;
				fcol[mapping[orderedPoints[i]]][k] = bcol[map_boundary[orderedPoints[i]]][k] = getpix(target, t_x, t_y, k) - getpix(src, s_x, s_y, k);
			}
		}
		for (int i = 0; i < orderedPoints.size(); ++i)
		if (map_boundary.find(orderedPoints[i]) == map_boundary.end()) { // internal point
			int index = mapping[orderedPoints[i]];
			for (int j = 0; j < cnt; ++j)
				tg[j] = getTanAngle(orderedPoints[i], boundaryVector[j], boundaryVector[(j + 1) % cnt]);
			double w_sum = 0;
			for (int j = 0; j < cnt; ++j) {
				weight[j] = (tg[(j+cnt-1)%cnt] + tg[j]) / getLength(orderedPoints[i], boundaryVector[j]);
				w_sum += weight[j];
			}
			for (int j = 0; j < cnt; ++j) {
				double lmd = weight[j] / w_sum;
				for(int k = 0; k < channel; ++k)
					fcol[index][k] += lmd * bcol[j][k];
			}
		}
		// for(int i = 0; i < orderedPoints.size(); ++i)
			// printf("%lf %lf %lf\n", fcol[i][0], fcol[i][1], fcol[i][2]);
		// for each triangular mesh, calc the inside points' color
		for (int i = 0; i < triangle_mesh.size(); ++i)
		{
			Point v1 = triangle_mesh[i].vertex(0);
			Point v2 = triangle_mesh[i].vertex(1);
			Point v3 = triangle_mesh[i].vertex(2);
			P p1 = (P){v1.x(), v1.y()};
			P p2 = (P){v2.x(), v2.y()};
			P p3 = (P){v3.x(), v3.y()};
			double x_min = std::min(std::min(p1.x, p2.x), p3.x);
			double x_max = std::max(std::max(p1.x, p2.x), p3.x);
			double y_min = std::min(std::min(p1.y, p2.y), p3.y);
			double y_max = std::max(std::max(p1.y, p2.y), p3.y);
			// calc transform matrix
			int index1 = mapping[v1];
			int index2 = mapping[v2];
			int index3 = mapping[v3];
			for (int k = 0; k < channel; ++k)
				Calc_Transform_Matrix(fmat[k], p1, p2, p3, fcol[index1][k], fcol[index2][k], fcol[index3][k]);
			for (int x = std::max(0., x_min - 1); x <= x_max + 1 && x < src.h; ++x)
				for (int y = std::max(0., y_min - 1); y <= y_max + 1 && y < src.w; ++y)
					if (intri((P){x, y}, p1, p2, p3))
						for (int k = 0; k < channel; ++k)
						{
							double c = fmat[k].transform((P){x, y}) + getpix(src, x, y, k);
							getpix(target, x + ph, y + pw, k) = c;
						}
		}
		// output
		std::cout << "Output result in " << output_filename << std::endl;
		target.write(output_filename.c_str());
	}
	else // poisson
	{
		// init
		IMG src_grad(mask.h1 - mask.h0 + 1, mask.w1 - mask.w0 + 1, channel);
		// src_grad.print("grad");
		for (int i = mask.h0, h = 0; i <= mask.h1; ++i, ++h)
			for (int j = mask.w0, w = 0; j <= mask.w1; ++j, ++w)
				for (int k = 0; k < channel; ++k)
					if (getpix(mask, i, j, 0)>200)
						getbuf(src_grad, h, w, k) = 255,
						getpix(src_grad, h, w, k) = getpix(src, i, j, k) * 4
												   -getpix(src, i-1, j, k)
												   -getpix(src, i+1, j, k)
												   -getpix(src, i, j-1, k)
												   -getpix(src, i, j+1, k);
		src_grad.stat(200);
		// src_grad.print("grad");
		printf("src_grad h:[%d,%d] w:[%d,%d]\n",src_grad.h0, src_grad.h1, src_grad.w0, src_grad.w1);
		printf("grad done\n");
		// init solver
		Solver*sv = new Solver[channel];
		for (int k = 0; k < channel; ++k)
		{
			sv[k].label = k;
			sv[k].resize((src_grad.h1 - src_grad.h0 + 1) * src_grad.w + src_grad.w1 - src_grad.w0 + 1);
		}
		printf("solver init ... size = %d\n", sv[0].size);
		for (int i = src_grad.h0, h = ph; i <= src_grad.h1; ++i, ++h)
			for (int j = src_grad.w0, w = pw; j <= src_grad.w1; ++j, ++w)
				// (i,j) -> src_grad
				// (h,w) -> target
				for (int k = 0; k < channel; ++k)
					if (getbuf(src_grad, i, j, k) == 255)
					{
						// printf("i=%d j=%d k=%d\n",i,j,k);
						// printf("mapping: %d,%d\n",i-src_grad.h0+mask.h0,j-src_grad.w0+mask.w0,k);
						if (rsm)
							sv[k].additem(i * src_grad.w + j, getpix(resume, h, w, k));
						else
							sv[k].additem(i * src_grad.w + j, getpix(target, h, w, k));
						// sv[k].additem(i*src_grad.w+j,getpix(src,i-src_grad.h0+mask.h0,j-src_grad.w0+mask.w0,k));
						sv[k].addconst(getpix(src_grad, i, j, k));
						if (getbuf(src_grad, i - 1, j, k) == 255)
							sv[k].addvar((i - 1) * src_grad.w + j);
						else
							sv[k].addconst(getpix(target, h - 1, w, k));
						if (getbuf(src_grad, i + 1, j, k) == 255)
							sv[k].addvar((i + 1) * src_grad.w + j);
						else
							sv[k].addconst(getpix(target, h + 1, w, k));
						if (getbuf(src_grad, i, j - 1, k) == 255)
							sv[k].addvar(i * src_grad.w + j - 1);
						else
							sv[k].addconst(getpix(target, h, w - 1, k));
						if (getbuf(src_grad, i, j + 1, k) == 255)
							sv[k].addvar(i * src_grad.w + j + 1);
						else
							sv[k].addconst(getpix(target, h, w + 1, k));
					}
		printf("solver init done\n");
		// sv[0].print();//return 0;
		// iterate solver
		for (int _ = rsm + 1; _ <= iter + 1; _++)
		{
			if (_ % per == 0 || _ <= before || _ == iter + 1)
			{
				for (int i = src_grad.h0, h = ph; i <= src_grad.h1; ++i, ++h)
					for (int j = src_grad.w0, w = pw; j <= src_grad.w1; ++j, ++w)
						for (int k = 0; k < channel; ++k)
							if (getbuf(src_grad, i, j, k) == 255)
								getpix(target, h, w, k) = sv[k].x[i * src_grad.w + j];
				printf("iter %d  err", _);
				for (int i = 0; i < channel; ++i)
					printf(" %lf", sv[i].err);
				puts("");
				if (_ != iter + 1) {
					sprintf(str,"iter%d.png", _);
					target.write(str);
				}
				else target.write(output_filename.c_str());
			}
			for (int k = 0; k < channel; ++k)
				sv[k].iter();
		}
		return 0;
	}
}
