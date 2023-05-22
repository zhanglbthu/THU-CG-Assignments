#include "render.hpp"

int baseline(int argc, char *argv[])
{
	// Ray ray(P3(427,1000,447),P3(-1,-2,-1.5).norm());
	// find_intersect_simple(ray);
	int w = atoi(argv[1]), h = atoi(argv[2]), samp = atoi(argv[4]);
	Ray cam(P3(150, 28, 260), P3(-0.45, 0.001, -1).norm());
	P3 cx = P3(w * .33 / h), cy=(cx & P3(cam.d.x, 0, cam.d.z)).norm() * .33, r, *c = new P3[w * h];
	cx *= 1.05;
	ld aperture = .0;
#pragma omp parallel for schedule(dynamic, 1) private(r)
	for (int y = 0; y < h; ++y) {
		fprintf(stderr, "\r%5.2f%%", 100. * y / h);
		for (int x = 0; x < w; ++x) {
			for (int sy = 0; sy < 2; ++sy)
				for (int sx = 0; sx < 2; ++sx)
				{
					unsigned short X[3] = {y + sx, y * x + sy, y * x * y + sx * sy + time(0)};
					r.x = r.y = r.z = 0;
					for (int s = 0; s < samp; ++s) {
						ld r1 = 2 * erand48(X), dx = r1 < 1 ? sqrt(r1): 2-sqrt(2-r1);
						ld r2 = 2 * erand48(X), dy = r2 < 1 ? sqrt(r2): 2-sqrt(2-r2);
						P3 d = cx * ((sx + dx / 2 + x) / w - .5) + cy * ((sy + dy / 2 + y) / h - .5) + cam.d;
						P3 pp = cam.o + d * 150, loc = cam.o + (P3(erand48(X) * 1.05, erand48(X)) - .5) * 2 * aperture;
						r += basic_render(Ray(pp, (pp - loc).norm()), 0, X);
					}
					c[y * w + x] += (r / samp).clip()/4;
				}
		}
	}
	FILE* f = fopen(argv[3],"w");
	fprintf(f, "P6\n%d %d\n%d\n", w, h, 255);
	for (int y = h - 1; y >= 0; --y)
		for (int x = w - 1; x >= 0; --x)
			fprintf(f, "%c%c%c", gamma_trans(c[y*w+x].x), gamma_trans(c[y*w+x].y), gamma_trans(c[y*w+x].z));
	fclose(f);
	char sout[100];
	sprintf(sout,"%s.txt",argv[3]);
	FILE*fout = fopen(sout, "w");
	for (int y = h - 1; y >= 0; --y)
		for (int x = w - 1; x >= 0; --x)
			fprintf(fout, "%.8lf %.8lf %.8lf\n", c[y*w+x].x, c[y*w+x].y, c[y*w+x].z);
	return!puts("");
}

int sppm(int argc, char* argv[])
{
	int w = atoi(argv[1]), h = atoi(argv[2]), iter = atoi(argv[4]);
	ld rad = atof(argv[6]), alpha = atof(argv[7]), samp = atof(argv[5]) * w * h;
	Ray cam(P3(150, 28, 260), P3(-0.45, 0.001, -1).norm());
	int nth = omp_get_num_procs(); --scene_num;
	P3 cx = P3(w * .33 / h), cy=(cx & P3(cam.d.x, 0, cam.d.z)).norm() * .33;
	IMGbuf **c = new IMGbuf*[nth];
	for (int i = 0; i < nth; ++i)
		c[i] = new IMGbuf[h * w];
	IMGbuf* final = new IMGbuf[h * w];
	IMGbuf* now = new IMGbuf[h * w];
	cx *= 1.05;
	ld aperture = .0;
	// for (int _ = 1; _ <= iter; fprintf(stderr, "\niter %d done!\n", _), ++_) {
	// build kdtree
	std::vector<SPPMnode> ball[nth];
	KDTree tree;
	for (int _ = 1; _ <= iter; fprintf(stderr, "\riter %d done!\n", _), ++_) {
		if (_ < 3 || _ % 1 == 0) {
			if (_ > 1) {
				samp /= sqrt(alpha);
				rad *= alpha;
			}
			#pragma omp parallel for num_threads(nth) schedule(dynamic, 1)
			for (int y = 0; y < h; ++y) {
				int num = omp_get_thread_num();
				fprintf(stderr, "\rbuild kdtree %5.2f%% ... ", 100. * y / h);
				for (int x = 0; x < w; ++x)
				for (int sy = 0; sy < 2; ++sy)
				for (int sx = 0; sx < 2; ++sx) {
					unsigned short X[3] = {y + sy, y * x * time(0) + sx, y * x * y + time(0) + sy * 2 + sx};
					ld r1 = 2 * erand48(X), dx = r1 < 1 ? sqrt(r1): 2-sqrt(2-r1);
					ld r2 = 2 * erand48(X), dy = r2 < 1 ? sqrt(r2): 2-sqrt(2-r2);
					P3 d = cx * ((dx / 2 + x + sx) / w - .5) + cy * ((dy / 2 + y + sy) / h - .5) + cam.d;
					P3 pp = cam.o + d * 150, loc = cam.o + (P3(erand48(X) * 1.05, erand48(X)) - .5) * 2 * aperture;
					std::vector<SPPMnode> tmp = sppm_backtrace(Ray(pp, (pp - loc).norm()), 0, y * w + x, X);
					for (int i = 0; i < tmp.size(); ++i)
						if (tmp[i].index >= 0) {
							tmp[i].r = rad;
							ball[num].push_back(tmp[i]);
						}
				}
			}
			std::vector<SPPMnode> totball;
			fprintf(stderr, "\rbuild tree ... ");
			for(int i = 0; i < nth; ++i) {
				totball.insert(totball.end(), ball[i].begin(), ball[i].end());
				// printf("%d: %d\n", i, ball[i].size());
			}
			tree.init(totball);
			fprintf(stderr, "done!\n");
		}
		fprintf(stderr, "rad = %f samp = %.0f\n", rad, samp);
		int per = samp / nth + 1;
		#pragma omp parallel for num_threads(nth) schedule(dynamic, 1)
		for (int t = 0; t < nth; ++t) {
			unsigned short X[3] = {t, t * t, (t & (t * t)) + _ + time(0)};
			int num = omp_get_thread_num();
			// for (int i = 0; i < totball.size(); ++i)
			// 	tree.query(totball[i], c[num]);
			// for (ld y = 0; y <= 81; y += .5)
			// 	for (ld x = 1; x < 200; x += .5)
			// 		for (ld z = 0; z < 150; z += .5)
			// 		tree.query(SPPMnode(P3(x, y, z), P3(1, 1, 1), P3(0,0,0)), c[num]);
			for (int __ = 0; __ < per; __++) {
				if (num == 0 && __ % 1000 == 0)
					fprintf(stderr, "\rsppm tracing %5.2f%%", 100. * __ / per);
				// gen random light
				ld rc = erand48(X) * 18, tht = erand48(X) * 2 * PI;
				P3 o(50 + rc * cos(tht), 81.6 - eps, 81.6 + rc * sin(tht));
				ld r1 = 2 * PI * erand48(X), r2 = erand48(X), r2s = sqrt(r2);
				P3 w = P3(0, -1, 0), u=(P3(1).cross(w)).norm(), v = w.cross(u);
				P3 d = (u * cos(r1) * r2s + v * sin(r1) * r2s + w * sqrt(1 - r2)).norm();
				Ray light = Ray(o, d);
				P3 col = P3(1, 1, 1) + .4;
				tree.query(SPPMnode(o, col, d), c[num]);
				sppm_forward(light, 0, col, X, c[num], &tree);
			}
		}
		// gather result
		memset(now, 0, sizeof now);
		for (int i = 0; i < nth; memset(c[i], 0, sizeof c[i]), ++i)
			for (int j = h * w - 1; j >= 0; --j)
				now[j] += c[i][j];
		// modify rad
		// for (int i = 1; i <= tree.n; ++i) {
		// 	int index = tree.tree[i].sppm.index;
		// 	if (now[index].n > eps) {
		// 		tree.tree[i].sppm.r *= sqrt((final[index].n + alpha * now[index].n) / (final[index].n + now[index].n));
		// 		// if (tree.tree[i].sppm.r < eps)
		// 		// 	fprintf(stderr, "err: %lf %lf\n", sqrt((final[index].n + alpha * now[index].n) / (final[index].n + now[index].n)), tree.tree[i].sppm.r);
		// 	}
		// }
		// tree.modify();
		for (int i = h * w - 1; i >= 0; --i)
			final[i] += now[i] / now[i].n;// * alpha;
		if (_ == 1 || _ % 1 == 0) {
			char sout[100];
			sprintf(sout, "%s%03d.ppm", argv[3], _);
			FILE* f = fopen(sout, "w");
			fprintf(f, "P6\n%d %d\n%d\n", w, h, 255);
			for (int y = h - 1; y >= 0; --y)
				for (int x = w - 1; x >= 0; --x) {
					fprintf(f, "%c%c%c", gamma_trans(final[y*w+x].get().x), gamma_trans(final[y*w+x].get().y), gamma_trans(final[y*w+x].get().z));
				}
			fclose(f);
		}
	}
	return !puts("");
}

int main(int argc, char*argv[])
{
	return baseline(argc, argv);
}
