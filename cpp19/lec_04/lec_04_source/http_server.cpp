#include <future>
#include <iostream>
#include <string>
#include <thread>

void Handler(std::string request) {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(100ms);

  std::cout << request << std::endl;
}

void EchoServerStart() {
  while (true) {
    std::string request;

    // ���� �������� ����������.
    std::cin >> request;

    // ��������� ����� �����, ������� ���������� �������� ������.
    std::thread th(Handler, std::move(request));

    // �������� ������ �� ����� ��������� ���������� ����������� ������,
    // ������� �������� detach.
    th.detach();
  }
}

int main() {
  EchoServerStart();
}
