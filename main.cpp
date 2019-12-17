#include <iostream>
#include <thread>
#include <chrono>

int timesLeft;

int hours;
int minutes;
int seconds;

void clear()
{
  int loop = 0;
  while (loop <= 20)
  {
    std::cout << "\n";
    loop++;
  }
}

void convert_v1()
{
  while (seconds >= 60)
  {
    minutes++;
    seconds -= 60;
  }
  while (minutes >= 60)
  {
    hours++;
    minutes -= 60;
  }
}

void convert_v2()
{
  if (seconds < 0 && minutes > 0)
  {
    seconds = 59;
    minutes--;
  }
  if (minutes < 0 && hours > 0)
  {
    minutes = 59;
    hours--;
  }
  if (seconds < 0 && hours > 0)
  {
    minutes = 59;
    seconds = 59;
    hours--;
  }
}

void wait()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  timesLeft--, seconds--;
  convert_v2();
}

int main() {
  int waitingTime;

  std::cout << "REMINDER\n";
  std::cout << "1 hour = 3600 seconds\n";
  std::cout << "45 minutes = 2700 seconds\n";
  std::cout << "30 minutes = 1800 seconds\n";
  std::cout << "15 minutes = 900 seconds\n";
  std::cout << "1m = 60s\n\n";

  while (true)
  {
    std::cout << "Set timer (seconds) : ";
    std::cin >> waitingTime;

    seconds = waitingTime;
    timesLeft = waitingTime;

    convert_v1();

    std::cout << "\n";
    while (timesLeft >= 0)
    {
      std::cout << hours << "h : " << minutes << "m : " << seconds << "s" << std::endl;
      wait();
    }

    clear();
    std::cout << "\nTIME OVER\n\n";
  }
}