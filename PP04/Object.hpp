class Object
{
public:
	int x;
	int y;

	Object()
	{
		x = 50;
		y = 7;
	}
	~Object()
	{

	}

	void MoveObject()
	{
		x--;
	}
	void MoveFastObject()
	{
		x -= 2;
	}
	void ResetObject()
	{
		x = 50;
	}
};