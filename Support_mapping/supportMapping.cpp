// SUPPORT MAPPING FUNCTION
//
// Jakub Mikuła

#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

struct vec3 { float x,y,z; };

struct Sphere
{
    vec3 center;
    float radius;
};
// Axis-aligned bounding box. Cube with edges aligned to x,y,z axis.
struct Aabb
{
    vec3 min;
    vec3 max;
};
// Triangular pyramid.
struct Tetrahedron
{
    vec3 points[4];
};
// Cylinder with hemispherical ends.
struct Capsule
{
    vec3 points[2];
    float radius;
};
//function that returns max(point*vector) from given points
vec3 maxPointTimesV(vec3 *points, vec3 v, int size){
    vec3 toReturn = points[0];
    
    for(int i=1; i<size; i++){
        float sumCorners = points[i].x*v.x + points[i].y*v.y + points[i].z*v.z;
        float sumToReturn = toReturn.x*v.x + toReturn.y*v.y + toReturn.z*v.z;
        
        if(sumCorners>sumToReturn){
            toReturn=points[i];
        }
    }
    return toReturn;
}
//support mapping function for Sphere
vec3 supp(vec3 v, Sphere s){
    vec3 toReturn;
    vec3 temp=v;
    float norm = sqrt(pow(v.x, 2)+pow(v.y, 2)+pow(v.z, 2));
    
    temp.x/=norm;
    temp.y/=norm;
    temp.z/=norm;
    
    temp.x*=s.radius;
    temp.y*=s.radius;
    temp.z*=s.radius;
    
    toReturn.x=s.center.x+temp.x;
    toReturn.y=s.center.y+temp.y;
    toReturn.z=s.center.z+temp.z;
    
    return toReturn;
}
//support mapping function for Aabb
vec3 supp(vec3 v, Aabb a){
    vec3 toReturn, corners[8];
        
    for(int i=0; i<8; i++){
        corners[i]=a.min;
        corners[i+1]=a.max;
        
        switch (i) {
            case 0:
                corners[i].x=a.max.x;
                corners[++i].x=a.min.x;
                break;
            case 2:
                corners[i].y=a.max.y;
                corners[++i].y=a.min.y;
                break;
            case 4:
                corners[i].z=a.max.z;
                corners[++i].z=a.min.z;
                break;
            default:
                i++;
                break;
        }
    }
    toReturn = maxPointTimesV(corners, v, 8);
    
    return toReturn;
}
//support mapping function for Tetrahedron
vec3 supp(vec3 v, Tetrahedron t){
    vec3 toReturn = maxPointTimesV(t.points, v, 4);
    
    return toReturn;
}
//support mapping function for Capsule
vec3 supp(vec3 v, Capsule c){
    Sphere s[2];
    vec3 toReturn, points[2];
    
    for(int i=0; i<2; i++){
        s[i].center=c.points[i];
        s[i].radius=c.radius;
        
        points[i]=supp(v, s[i]);
    }
    
    toReturn = maxPointTimesV(points, v, 2);
    
    return toReturn;
}

template <typename Shape>
vec3 support(vec3 v, Shape s){
    
    vec3 temp = supp(v, s);
    
    return temp;
}

void writeCheck(vec3 tW, string shape){
    cout<<shape<<":"<<endl;
    cout<<"x:"<<tW.x<<endl;
    cout<<"y:"<<tW.y<<endl;
    cout<<"z:"<<tW.z<<endl<<endl;
}


int main(int argc,char** argv){
    // SPHERE
    Sphere s;
    vec3 v={-10,-10,-10};
    s.center = v;
    s.radius=11;
    
    vec3 toWrite = support({1,1,1}, s);
    
    writeCheck(toWrite, "Sphere");
    
    // AABB
    Aabb a;
    v={-4,-4,-4};
    a.min=v;
    v={400,2,400};
    a.max=v;
    
    toWrite = support({12,-0.002,1}, a);
    
    writeCheck(toWrite, "Aabb");
    
    // TETRAHEDRON
    Tetrahedron t;
    v={0,17,0};
    t.points[0]=v;
    v={14,0,0};
    t.points[1]=v;
    v={3,0,-4};
    t.points[2]=v;
    v={5,10,-6};
    t.points[3]=v;
    
    toWrite = support({0.003,0,-0.01}, t);
    
    writeCheck(toWrite, "Tetrahedron");

    // CAPSULE
    Capsule c;
    v={0,0,0};
    c.points[0]=v;
    v={10,-20,5};
    c.points[1]=v;
    c.radius=3;
    
    toWrite = support({1,-1,0.01}, c);
    
    writeCheck(toWrite, "Capsule");
    
    return 0;
}
