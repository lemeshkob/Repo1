#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void getPlayerCoordinateForView(float x,float y) { //������� ��� ���������� ��������� ������
	view.setCenter(x + 100, y); //������ �� �������, ��������� ��� ���������� ������. +100 - �������� ������ �� ���� ������. �����������������
}
