class Tree{
public:
	void grow(int year){
		ages+=year;
	}
	int age(){
		return ages;
	}
	Tree(const int &ages){
	this->ages=ages;
	}
private:
	int ages;
};

	