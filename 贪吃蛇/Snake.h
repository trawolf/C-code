#pragma once
class Snake//���࣬�������ߵĻ���Ԫ�غ��ߵ����л�����������������ɵ�
{
public://����û��д���캯����ͬѧ�ǿ��Ը�����Ҫ��д����Ҫע��ָ��ָ��ʱ��������
	
	//��Ԫ�������ò������ԣ�����ͨ��Set���������ͬѧ��˼�����ʵ��
	friend void creat_food();//����ʳ��ĺ���
	friend void Initial(); //��ʼ����������ʼ���ߵ�����ĳ�ʼ���ȣ��Լ�����λ��

	int Get_x();
	int Get_y();
	Snake* Get_next();
	bool Bite_self();//�ж��Ƿ�ҧ���Լ�
	void Can_not_crowall();//���ܴ�ǽ����������ǿ����
	void Move();//�ߵ��ƶ�
private:
	int s_x;//�ߵ�x��y����
	int s_y;
	Snake* next;//ʹ��������ɣ����������򣬴�ź�x��y���ꡣһ��ָ���򣬴�����Ӻ�������ڵ�ĵ�ַ
};

struct Obstacle//�ϰ���ṹ�壬�ڲ���x��y������
{
	int x;//�ϰ���ĺ�������
	int y;
};

