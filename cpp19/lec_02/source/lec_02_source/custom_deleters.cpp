#include <functional>
#include <iostream>
#include <memory>


struct Object {};

void CustomDeleter(Object* toDelete) {
  // ��������� ����� ���������������� ��� ��� �������� ������� |toDelete|.
  std::cout << std::hex << toDelete << std::endl;
  delete toDelete;
}

void UniqueCustomDeleterSample() {
  //
  using deleter_type = std::function<void(Object*)>;

  // ������� ��������� � ���������������� �������� ��� ������������ ������.
  // ������ �������� - ��� ��������� �� ��������� ������.
  // ������ - custom deleter.
  std::unique_ptr<Object, deleter_type> ptr(new Object(), CustomDeleter);

  // ��� ������ ����������� |ptr| ��������� ������� CustomDeleter.
}

void SharedCustomDeleterSample() {
  // ������� ��������� � ���������������� �������� ��� ������������ ������.
  // �������, ��� ���������������� ��������� ��� std::shared_ptr �� ��������
  // ������ ����.
  // ������ �������� ��������� �� ��������� ������.
  // ������ - custom deleter.
  std::shared_ptr<Object> ptr(new Object(), CustomDeleter);

  // ��� ������ ����������� |ptr| ��������� ������� CustomDeleter.
}

void UniqueForArray() {
  // ����� ������� unique_ptr ��� �������.
  // ����� � ����������� ����� ������ delete[].
  std::unique_ptr<Object[]> objects(new Object[100]);
}