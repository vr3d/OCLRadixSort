/*
		2011 Takahiro Harada
*/

//#define CHECK_ALIGNMENT(a) ADLASSERT((u32(&(a)) & 0xf) == 0);


__inline
float4 make_float4(float x, float y, float z = 0.f, float w = 0.f)
{
	float4 v;
	v.x = x; v.y = y; v.z = z; v.w = w;
	return v;
}

__inline
float4 make_float4(float x)
{
	return make_float4(x,x,x,x);
}

__inline
float4 make_float4(const int4& x)
{
	return make_float4((float)x.s[0], (float)x.s[1], (float)x.s[2], (float)x.s[3]);
}

__inline
int4 make_int4(int x, int y, int z, int w = 0)
{
	int4 v;
	v.s[0] = x; v.s[1] = y; v.s[2] = z; v.s[3] = w;
	return v;
}

__inline
int4 make_int4(float x, float y, float z, float w = 0.f)
{
	int4 v;
	v.s[0] = (int)x; v.s[1] = (int)y; v.s[2] = (int)z; v.s[3] = (int)w;
	return v;
}

__inline
int4 make_int4(int x)
{
	return make_int4(x,x,x,x);
}

__inline
int4 make_int4(const float4& x)
{
	return make_int4((int)x.x, (int)x.y, (int)x.z, (int)x.w);
}

//--
__inline
uint4 make_uint4(u32 x, u32 y, u32 z, u32 w = 0)
{
	uint4 v;
	v.s[0] = x; v.s[1] = y; v.s[2] = z; v.s[3] = w;
	return v;
}

__inline
uint4 make_uint4(float x, float y, float z, float w = 0.f)
{
	uint4 v;
	v.s[0] = (u32)x; v.s[1] = (u32)y; v.s[2] = (u32)z; v.s[3] = (u32)w;
	return v;
}

__inline
uint4 make_uint4(u32 x)
{
	return make_uint4(x,x,x,x);
}

__inline
uint4 make_uint4(const float4& x)
{
	return make_uint4(x.x, x.y, x.z, x.w);
}

//--
__inline
int2 make_int2(int a, int b)
{
	int2 ans; ans.x = a; ans.y = b;
	return ans;
}

__inline
int2 make_int2(int a)
{
	return make_int2( a, a );
}

__inline
uint2 make_uint2(u32 a, u32 b)
{
	uint2 ans; ans.x = a; ans.y = b;
	return ans;
}

__inline
uint2 make_uint2(u32 a)
{
	return make_uint2( a, a );
}

__inline
bool operator ==(const int2& a, const int2& b)
{
	return a.x==b.x && a.y==b.y;
}

__inline
bool operator ==(const int4& a, const int4& b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z && a.w==b.w;
}

__inline
bool operator ==(const float2& a, const float2& b)
{
	return a.x==b.x && a.y==b.y;
}

__inline
bool operator ==(const float4& a, const float4& b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z && a.w==b.w;
}

__inline
float4 operator-(const float4& a)
{
	return make_float4(-a.x, -a.y, -a.z, -a.w);
}

__inline
float4 operator*(const float4& a, const float4& b)
{
//	ADLASSERT((u32(&a) & 0xf) == 0);

	float4 out;
	out.s[0] = a.s[0]*b.s[0];
	out.s[1] = a.s[1]*b.s[1];
	out.s[2] = a.s[2]*b.s[2];
	out.s[3] = a.s[3]*b.s[3];
	return out;
}

__inline
float4 operator*(float a, const float4& b)
{
	return make_float4(a*b.s[0], a*b.s[1], a*b.s[2], a*b.s[3]);
}

__inline
float4 operator*(const float4& b, float a)
{
	return make_float4(a*b.s[0], a*b.s[1], a*b.s[2], a*b.s[3]);
}

__inline
void operator*=(float4& a, const float4& b)
{
	a.s[0]*=b.s[0];
	a.s[1]*=b.s[1];
	a.s[2]*=b.s[2];
	a.s[3]*=b.s[3];
}

__inline
void operator*=(float4& a, float b)
{
	a.s[0]*=b;
	a.s[1]*=b;
	a.s[2]*=b;
	a.s[3]*=b;
}
/*
__inline
bool operator ==(const float4& a, const float4& b)
{


}
*/
//
__inline
float4 operator/(const float4& a, const float4& b)
{
	float4 out;
	out.s[0] = a.s[0]/b.s[0];
	out.s[1] = a.s[1]/b.s[1];
	out.s[2] = a.s[2]/b.s[2];
	out.s[3] = a.s[3]/b.s[3];
	return out;
}

__inline
float4 operator/(const float4& b, float a)
{
	return make_float4(b.s[0]/a, b.s[1]/a, b.s[2]/a, b.s[3]/a);
}

__inline
void operator/=(float4& a, const float4& b)
{
	a.s[0]/=b.s[0];
	a.s[1]/=b.s[1];
	a.s[2]/=b.s[2];
	a.s[3]/=b.s[3];
}

__inline
void operator/=(float4& a, float b)
{
	a.s[0]/=b;
	a.s[1]/=b;
	a.s[2]/=b;
	a.s[3]/=b;
}
//

__inline
float4 operator+(const float4& a, const float4& b)
{
	float4 out;
	out.s[0] = a.s[0]+b.s[0];
	out.s[1] = a.s[1]+b.s[1];
	out.s[2] = a.s[2]+b.s[2];
	out.s[3] = a.s[3]+b.s[3];
	return out;
}

__inline
float4 operator+(const float4& a, float b)
{
	float4 out;
	out.s[0] = a.s[0]+b;
	out.s[1] = a.s[1]+b;
	out.s[2] = a.s[2]+b;
	out.s[3] = a.s[3]+b;
	return out;
}

__inline
float4 operator-(const float4& a, const float4& b)
{
	float4 out;
	out.s[0] = a.s[0]-b.s[0];
	out.s[1] = a.s[1]-b.s[1];
	out.s[2] = a.s[2]-b.s[2];
	out.s[3] = a.s[3]-b.s[3];
	return out;
}

__inline
float4 operator-(const float4& a, float b)
{
	float4 out;
	out.s[0] = a.s[0]-b;
	out.s[1] = a.s[1]-b;
	out.s[2] = a.s[2]-b;
	out.s[3] = a.s[3]-b;
	return out;
}

__inline
void operator+=(float4& a, const float4& b)
{
	a.s[0]+=b.s[0];
	a.s[1]+=b.s[1];
	a.s[2]+=b.s[2];
	a.s[3]+=b.s[3];
}

__inline
void operator+=(float4& a, float b)
{
	a.s[0]+=b;
	a.s[1]+=b;
	a.s[2]+=b;
	a.s[3]+=b;
}

__inline
void operator-=(float4& a, const float4& b)
{
	a.s[0]-=b.s[0];
	a.s[1]-=b.s[1];
	a.s[2]-=b.s[2];
	a.s[3]-=b.s[3];
}

__inline
void operator-=(float4& a, float b)
{
	a.s[0]-=b;
	a.s[1]-=b;
	a.s[2]-=b;
	a.s[3]-=b;
}

__inline
void setZero(float4& ans)
{
	ans = make_float4(0.f);
}




__inline
float4 cross3(const float4& a, const float4& b)
{
	return make_float4(a.s[1]*b.s[2]-a.s[2]*b.s[1], 
		a.s[2]*b.s[0]-a.s[0]*b.s[2], 
		a.s[0]*b.s[1]-a.s[1]*b.s[0], 
		0);
}

__inline
float dot3F4(const float4& a, const float4& b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

__inline
float length3Squared(const float4& a)
{
	return dot3F4(a,a);
}

__inline
float length3(const float4& a)
{
	return sqrtf(length3Squared(a));
}


__inline
float dot4(const float4& a, const float4& b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
}

//	for height
__inline
float dot3w1(const float4& point, const float4& eqn)
{
	return point.x*eqn.x+point.y*eqn.y+point.z*eqn.z+eqn.w;
}

__inline
float4 normalize3(const float4& a)
{
	float length = sqrtf(dot3F4(a, a));
	return 1.f/length * a;
}

__inline
float4 normalize4(const float4& a)
{
	float length = sqrtf(dot4(a, a));
	return 1.f/length * a;
}

__inline
float4 createEquation(const float4& a, const float4& b, const float4& c)
{
	float4 eqn;
	float4 ab = b-a;
	float4 ac = c-a;
	eqn = normalize3( cross3(ab, ac) );
	eqn.w = -dot3F4(eqn,a);
	return eqn;
}

__inline
float intersectPlaneLine( const float4& planeEqn, const float4& vec, const float4& orig )
{
	return (-planeEqn.w - dot3F4(planeEqn, orig))/dot3F4(planeEqn, vec);
}

template<>
__inline
float4 max2(const float4& a, const float4& b)
{
	return make_float4( max2(a.x,b.x), max2(a.y,b.y), max2(a.z,b.z), max2(a.w,b.w) );
}

template<>
__inline
float4 min2(const float4& a, const float4& b)
{
	return make_float4( min2(a.x,b.x), min2(a.y,b.y), min2(a.z,b.z), min2(a.w,b.w) );
}
