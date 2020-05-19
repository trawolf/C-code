#pragma once
#include"Function.h"


int Snake::Get_x()
{
	return s_x;
}

int Snake::Get_y()
{
	return s_y;
}

Snake* Snake::Get_next()
{
	return next;
}

bool Snake::Bite_self()//����Ƿ�ҧ���Լ�,���Ǽ��ͷ�ڵ��Ƿ������������κ�һ���ڵ�����
{
	//����ֵ��ʾ�Ƿ�ҧ���Լ�״̬
	Snake* self;//���������߼���Ƿ�ҧ���Լ���ָ��

	self = head->Get_next();//����ͷ����һ���ڵ����
	while (self != NULL)//�������н��
	{
		if (self->Get_x() == head->Get_x() && self->Get_y() == head->Get_y())//���self��ָ���x��y����������ͷ��x��y��ȣ�˵��ҧ���Լ���
			return 1;//ҧ���Լ�
		self = self->Get_next();//������
	}
	return 0;//ûҧ��
}

void Snake::Can_not_crowall()//������ǽ��ײ
{
	for (int i = 0; i < 30; i++)
	{
		if (head->s_x == o[i].x && head->s_y == o[i].y)
		{
			end_condition = 4;//ײ���ϰ�������
			Die();
		}
	}
	//ײǽ��ע��ǽ�����ĸ�ͨ��
	if ((head->s_x == 0 && head->s_y != 20) ||
		(head->s_x == 58 && head->s_y != 6) ||
		(head->s_x != 10 && head->s_y == 0) ||
		(head->s_x != 50 && head->s_y == 29))
	{
		end_condition = 1;//ײǽ����
		Die();           //������Ӧ����Ľ�������
	}
}

void Snake::Move()//���ƶ��ĺ���
{
	head->Can_not_crowall();//���ж�ԭ����ͷ���Ƿ�ײǽ
	Snake* next_head = new Snake;//�µ�ͷ��,����ߵ��ƶ�
	//ȷ���ߵ��ƶ����
	//����
	if (condition == UP)
	{
		next_head->s_x = head->s_x;//��ͷ��x����
		next_head->s_y = head->s_y - 1;//��ͷ��y����
		next_head->next = head;//��ͷ�����е�ͷ�ڵ�����
		head = next_head;//headָ��ǰ��
		q = head;//qָ��ָ��head
		//����Ϊֹ,�߱�����������һ�����,���ڷ���������Ƿ�ɾ��������
		//��ͷ����ʳ��
		if (next_head->s_x == food->s_x && next_head->s_y == food->s_y)
		{
			while (q != NULL)
			{
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		//��һ��λ��û��ʳ��
		else
		{
			while (q->next->next != NULL)
			{
				if (q->s_y < 0)//y����ǽʵ��:��(10,0)����(50,29)
				{
					q->s_x += 40;
					q->s_y += 30;//�����(10,-1)��(50,29)
				}
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			Set_location(q->next->s_x, q->next->s_y);//��λ��������
			cout << "  ";
			delete q->next;//ɾ��������
			q->next = NULL;
			Set_location(q->s_x, q->s_y);//��ʱqΪ�����һ���ڵ�
			Green_color();
			cout << "��";
		}
	}

	//����
	if (condition == DOWN)//�� ���
	{
		next_head->s_x = head->s_x;//��ͷ��x����
		next_head->s_y = head->s_y + 1;//��ͷ��y����
		next_head->next = head;//��ͷ�����е�ͷ�ڵ�����
		head = next_head;//headָ��ǰ��
		q = head;//qָ��ָ��head
		 //����Ϊֹ,�߱�����������һ�����,���ڷ���������Ƿ�ɾ��������
		 //��ͷ����ʳ��
		if (next_head->s_x == food->s_x && next_head->s_y == food->s_y)
		{
			while (q != NULL)
			{
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		//��һ��λ��û��ʳ��
		else
		{
			while (q->next->next != NULL)
			{
				if (q->s_y > 29)//y����ǽʵ��:��(50,29)����(10,0)
				{
					q->s_x -= 40;
					q->s_y -= 30;////�����(50,30)��(10,0)
				}
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			Set_location(q->next->s_x, q->next->s_y);//��λ��������
			cout << "  ";
			delete q->next;//ɾ��������
			q->next = NULL;
			Set_location(q->s_x, q->s_y);//��ʱqΪ�����һ���ڵ�
			Green_color();
			cout << "��";
		}
	}

	//����
	if (condition == LEFT)
	{
		next_head->s_x = head->s_x - 2;//��ͷ��x����
		next_head->s_y = head->s_y;//��ͷ��y����
		next_head->next = head;//��ͷ�����е�ͷ�ڵ�����
		head = next_head;//headָ��ǰ��
		q = head;//qָ��ָ��head
				 //����Ϊֹ,�߱�����������һ�����,���ڷ���������Ƿ�ɾ��������
				 //��ͷ����ʳ��
		if (next_head->s_x == food->s_x && next_head->s_y == food->s_y)
		{
			while (q != NULL)
			{
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		//��һ��λ��û��ʳ��
		else
		{
			while (q->next->next != NULL)
			{
				if (q->s_x < 0)//x����ǽʵ��:��(0,20)����(58,6)
				{
					q->s_x += 60;
					q->s_y -= 14;//�����(-2,20)��(58,6)
				}
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			Set_location(q->next->s_x, q->next->s_y);//��λ��������
			cout << "  ";
			delete q->next;//ɾ��������
			q->next = NULL;
			Set_location(q->s_x, q->s_y);//��ʱqΪ�����һ���ڵ�
			Green_color();
			cout << "��";
		}
		q = head;
	}

	//����
	if (condition == RIGHT)
	{
		next_head->s_x = head->s_x + 2;//��ͷ��x����
		next_head->s_y = head->s_y;//��ͷ��y����
		next_head->next = head;//��ͷ�����е�ͷ�ڵ�����
		head = next_head;//headָ��ǰ��
		q = head;//qָ��ָ��head
				 //����Ϊֹ,�߱�����������һ�����,���ڷ���������Ƿ�ɾ��������
				 //��ͷ����ʳ��
		if (next_head->s_x == food->s_x && next_head->s_y == food->s_y)
		{
			while (q != NULL)
			{
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		//��һ��λ��û��ʳ��
		else
		{
			while (q->next->next != NULL)
			{
				if (q->s_x > 58)//x����ǽʵ��:��(58,6)����(0,20)
				{
					q->s_x -= 60;
					q->s_y += 14;//�����(60,6)��(0,20)
				}
				if (q == head)
				{
					Set_location(q->s_x, q->s_y);
					Yellow_color();
					cout << "��";
					q = q->next;
				}
				else
				{
					Set_location(q->s_x, q->s_y);
					Green_color();
					cout << "��";
					q = q->next;
				}
			}
			Set_location(q->next->s_x, q->next->s_y);//��λ��������
			cout << "  ";
			delete q->next;//ɾ��������
			q->next = NULL;
			Set_location(q->s_x, q->s_y);//��ʱqΪ�����һ���ڵ�
			Green_color();
			cout << "��";
		}
	}

	//ÿ���ƶ������Ƿ�ҧ���Լ�
	if (Bite_self())
	{
		end_condition = 2;//���Ҫ���Լ���Ҫ��end_condition������Ӧ���������ֵ
		Die();//ҧ���Լ�����die����
	}

}