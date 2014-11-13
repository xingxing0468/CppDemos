#include <iostream>
#define LENGTH 100000


class BigNum
{
public:
	BigNum(){
		m_num = new char[LENGTH];
	};
	~BigNum()
	{
		delete[] m_num;
		m_num = NULL;		
	};
	char OneByte(int offset) const
	{
		return m_num[offset];
	};
	void SetOneByte(int offset, char value)
	{
		m_num[offset] = value;
	}
	BigNum operator +(const BigNum &b)
	{
		BigNum ret;
		int isOver = 0;
		for(int i = 0; i < LENGTH; i++)
		{
			int temp = int(m_num[i] + b.OneByte(i));
			ret.SetOneByte(i, (temp % 10) + isOver);
			isOver = (temp/10);
		}
		return ret;
	};

private:
	char* m_num;
};


int main()
{
	BigNum a;
	BigNum b;
	BigNum c = a + b;
	c = a + b;
	
}
