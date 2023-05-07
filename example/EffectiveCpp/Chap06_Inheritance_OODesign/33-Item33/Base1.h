class Base
{
public:
	virtual void mf1() = 0;
	virtual void mf2() {}
	void mf3();

private:
	int x;
};

class Derived : public Base
{
public:
	virtual void mf1() {}
	void mf4();
};


void Derived::mf4()
{
	mf2();
}