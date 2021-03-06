#ifndef _quadric_h
#define _quadric_h

typedef struct vec {// Vector structor
	double  x, y, z;// Coefficents of vector directionz

	vec operator + (vec& a) {
		vec tmp;
		tmp.x = this->x + a.x;
		tmp.y = this->y + a.y;
		tmp.z = this->z + a.z;

		return tmp;
	}

	vec operator - (vec& a) {
		vec tmp;
		tmp.x = this->x - a.x;
		tmp.y = this->y - a.y;
		tmp.z = this->z - a.z;

		return tmp;
	}

	vec operator * (double k) {
		vec tmp;
		tmp.x = k*this->x;
		tmp.y = k*this->y;
		tmp.z = k*this->z;

		return tmp;
	}

	double operator * (vec& a) {
		double dot = this->x*a.x + this->y*a.y + this->z*a.z;
		return dot;
	}

	vec operator += (vec& a) {
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		return *this;
	}

} Vec;

typedef struct light {// Point light structure
	Vec    dir;// Direction to light
	double  Int;// Light intensity
} Light;

typedef struct mat {// Material structure
	double  r;// Red component
	double  b;// Blue component
	double  g;// Green component
	double  Ka;// Ambient reflection coefficent
	double  Kd;// Diffuse reflection coefficent
	double  Ks;// Specular reflection coefficent
	double  KS;
	double  KT;
	double  ir;
	int  n;// Specular reflection exponent
	bool isTri = false;

} Mat;

typedef struct quad {// Quadric surface structure
	double  a, b, c, d, e, f, g, h, j, k;// Surface coefficents
	Mat     m;// Surface's material properties
} Quad;

typedef struct ray {// Ray structure
	Vec  org;// Origin of ray
	Vec  dir;// Direction of ray
	int  depth;// Depth (or length) of ray
} Ray;

double  dot(Vec, Vec);
double  intersect(Ray ray, Quad *obj);
Vec     mkvec(double, double, double);
void    normalize(Vec*);
Vec     svmpy(double, Vec);
Vec     vadd(Vec, Vec);
Vec     vsub(Vec, Vec);

#endif
