// Represents airports
class Airport
{
};


class Airplane
{
public:
	virtual void fly(const Airport& destination);
};

void Airplane::fly(const Airport& destination)
{
	// default code for flyaing an airplane to the given destination.
}


class ModelA : public Airplane
{
};

class ModelB : public Airplane
{
};