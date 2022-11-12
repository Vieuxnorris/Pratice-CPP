#include "Object-Oriented_Design.h"

template<typename Unit>
class Polygon {
public:
	Polygon() {}
	~Polygon() {}
	virtual Unit Area() = 0;
	virtual Unit Perimetre() = 0;
};

template<typename Unit>
class Triangle : public Polygon<Unit> {
public:
	Triangle(Unit a, Unit b, Unit c, Unit h) : a(a), b(b), c(c), h(h) {}
	Unit Area() { return ((this->b * this->h) / 2); }
	Unit Perimetre() { return (this->a + this->b + this->c); }
private:
	Unit a, b, c, h;
};

template<typename Unit>
class Quadrilateral : public Polygon<Unit> {
public:
	Quadrilateral(Unit AC, Unit BE, Unit DF) : AC(AC), BE(BE), DF(DF) {}
	Unit Area() { return ( ((1.0 / 2.0) * this->AC * this->BE) + ((1.0 / 2.0) * this->AC * this->DF) ); }
	Unit Perimetre() { return (this->AC + this->BE + this->DF); }
private:
	Unit AC, BE, DF;
};

template<typename Unit>
class Pentagon : public Polygon<Unit> {
public:
	Pentagon(Unit a, Unit b, Unit c, Unit d, Unit e, Unit h = 0) : a(a), b(b), c(c), d(d), e(e), h(h) {}
	Unit Area() { return ((1.0 / 2.0) * this->Perimetre() * h); }
	Unit Perimetre() { return (a + b + c + d + e); }
private:
	Unit a, b, c, d, e, h;
};

template<typename Unit>
class Hexagon : public Polygon<Unit> {
public:
	Hexagon(Unit a, Unit b, Unit c, Unit d, Unit e, Unit f) : a(a), b(b), c(c), d(d), e(e), f(f) {}
	Unit Area() { return (((3 * sqrt(3)) / 2.0) * this->Perimetre()); }
	Unit Perimetre() { return (a + b + c + d + e + f); }
private:
	Unit a, b, c, d, e, f;
};

template<typename Unit>
class Octagon : public Polygon<Unit> {
public:
	Octagon(Unit a, Unit b, Unit c, Unit d, Unit e, Unit f, Unit g, Unit h, Unit rayon) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), rayon(rayon) {}
	Unit Area() { return ( (this->Perimetre() * rayon) / 2.0 ); }
	Unit Perimetre() { return (a + b + c + d + e + f + g + h); }
private:
	Unit a, b, c, d, e, f, g, h;
	Unit rayon;
};

int PolygonInterface()
{
	Triangle<int> t1(10, 20, 30, 5);
	std::cout << "Area Triangle -> " << t1.Area() << std::endl;
	std::cout << "Perimetre Triangle -> " << t1.Perimetre() << std::endl;

	Quadrilateral<int> q1(10, 20, 30);
	std::cout << "Area Quadrilateral -> " << q1.Area() << std::endl;
	std::cout << "Perimetre Quadrilateral -> " << q1.Perimetre() << std::endl;

	Pentagon<int> p1(2, 3, 4, 5, 6, 10);
	std::cout << "Area Pentagon -> " << p1.Area() << std::endl;
	std::cout << "Perimetre Pentagon -> " << p1.Perimetre() << std::endl;

	Hexagon<int> h1(2, 3, 4, 5, 6, 10);
	std::cout << "Area Hexagon -> " << h1.Area() << std::endl;
	std::cout << "Perimetre Hexagon -> " << h1.Perimetre() << std::endl;

	Octagon<int> o1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << "Area Octagon -> " << o1.Area() << std::endl;
	std::cout << "Perimetre Octagon -> " << o1.Perimetre() << std::endl;

	return EXIT_SUCCESS;
}
