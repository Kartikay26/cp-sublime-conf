struct vec3{
	db x, y, z;
	vec3(db x, db y, db z):x(x),y(y),z(z){}
	db magn(){return sqrt(x*x+y*y+z*z);}
	vec3 operator*(db k){return vec3(k*x, k*y, k*z);}
	vec3 operator/(db k){return (*this)*(1/k);}
	vec3 operator*(vec3 v2){
		return vec3(y*v2.z - z*v2.y, -(x*v2.z - z*v2.x), x*v2.y - y*v2.x);
	}
	vec3 operator+(vec3 v2){
		return vec3(x+v2.x, y+v2.y, z+v2.z);
	}
	vec3 operator-(vec3 v2){
		return vec3(x-v2.x, y-v2.y, z-v2.z);
	}
	vec3 unit(){db m = magn(); return vec3(x/m, y/m, z/m);}
	void show(){cout << x << " " << y << " " << z;}
};

db dot(vec3 v1, vec3 v2){
	return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

#define debugv(x) cout << #x " is "; x.show(); cout << endl;