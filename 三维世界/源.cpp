#include  <iostream>
#include  <cmath>
using  std::cin;
using  std::cout;
using  std::endl;
using  std::istream;

const  float  PI = 3.1415926;
class  Shape {
public:
    virtual  Shape& Input() = 0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};
class  Prism : public  Shape {  //����
    //�벹���������غ���
    virtual Shape& Input() =0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};
class  RTPrism : public  Prism {  //��������
public:
    Shape& Input() {
        //�벹�����뺯��
        cin >> a >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        //�벹���������㺯��
        return sqrt(3) * a * a / 4 + 3 * a * sqrt(a * a / 12 + h * h) / 2;
    }
    float  Volume()  const {
        //�벹��������㺯��
        return sqrt(3) * a * a * h / 12;
    }
private:
    //�벹����Ӧ��Ա����
    float a, h;  //�߳��͸�
};
class  RCone : public  Prism {  //��Բ׶��
    //�벹��RCone��ĳ�Ա�����ͳ�Ա����
    float r, h;  //�뾶�͸�
public:
    Shape& Input() {
        cin >> r >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        return PI * r * r + PI * r * sqrt(r * r + h * h);
    }
    float  Volume()  const {
        return PI * r * r * h / 3;
    }
};
//�벹��������������ش���
class Cuboid :public Shape {
private:
    float a, b, h;  //��,��,��
public:
    Shape& Input() {
        cin >> a >> b>>h;
        return *this;
    }
    float SurfaceAera() const {
        return (a * b + a * h + b * h) * 2;
    }
    float Volume() const {
        return a * b * h;
    }
};
class Cube :public Cuboid {
private:
    float c;
public:
    Shape& Input() {
        cin >> c;
        return *this;
    }
    float SurfaceAera() const {
        return 6 * c * c;
    }
    float Volume() const {
        return c * c * c;
    }
};
class Sphere :public Shape {
private:
    float r;
public:
    Shape& Input() {
        cin >> r;
        return *this;
    }
    float SurfaceAera() const{
        return 4 * PI * r * r;
    }
    float Volume() const{
        return 4 * PI * r * r * r / 3;
    }
};


void  Display(const  Shape& sp) {
    std::cout << "SurfaceAera  =  " << sp.SurfaceAera() << std::endl
        << "Volume  =  " << sp.Volume() << std::endl;
}
void  DisplayCategory() {
    std::cout << "==================================================" <<
        std::endl;
    std::cout << "Please  input  one  of  the  following  choice:" << std::endl;
    std::cout << "\tCUBOID:    1" << std::endl;
    std::cout << "\tCUBE:        2" << std::endl;
    std::cout << "\tRTPRISM:  3" << std::endl;
    std::cout << "\tRCONE:      4" << std::endl;
    std::cout << "\tSPHERE:    5" << std::endl;
}
enum  CATEGORY { CUBOID = 1, CUBE, RTPRISM, RCONE, SPHERE }  category;
istream& operator  >>  (istream& in, CATEGORY& cat) {
    int  n = 0;
    in >> n;
    cat = static_cast<CATEGORY>(n);
    return  in;
}

int  main() {
    Cuboid  cuboid;
    Cube  cube;
    RTPrism  rtprism;
    RCone  rcone;
    Sphere  sphere;
    DisplayCategory();
    cin >> category;
    switch (category) {
    case  CUBOID:
        cout << "Please  input  (a,  b,  c)  in  order:" << endl;
        Display(cuboid.Input());
        break;
    case  CUBE:
        cout << "Please  input  (a):" << endl;
        Display(cube.Input());
        break;
    case  RTPRISM:
        cout << "Please  input  (a,  h)  in  order:" << endl;
        Display(rtprism.Input());
        break;
    case  RCONE:
        cout << "Please  input  (r,  h)  in  order:" << endl;
        Display(rcone.Input());
        break;
    case  SPHERE:
        cout << "Please  input  (r):" << endl;
        Display(sphere.Input());
        break;
    defalut:
        break;
    }
    return  0;
}